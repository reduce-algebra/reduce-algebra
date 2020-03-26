%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:HASHTABLES.SL
% Description:  Simple implementation of hash tables on top of vectors.
% Author:       Rainer Schöpf
% Created:      December 29, 2019
% Mode:         Lisp
% Package:      
% Status:       Open Source: BSD License
%
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% Implementation of hash tables at the Lisp level
%
% A hashtable is a vector with 2^n+1 elements (1<=n<=16).
% The 0-th element contains information about the hashtable itself, it is a list of the form
%    (!#hashtable!# comp mask)
% where:
%    !#hashtable!#  - a fixed id
%    comp           - the comparator function (eq or equal)
%    len            - the length of vector minus 1 (=n)
%    mask           - the number 2^n-1
% The rest of the vector elements are the buckets for the hashtable, each of which
% is an association list of (key . value) elements.
%
% The bucket number for a key is computed in a two step process:
% 1. The function sxhash computes a PSL posint (i.e. an integer that fits in a machine word
%     and has zero tag bits). This integer is an invariant over the life of the lisp image.
% 2. The bucket number is computed by multiplying this integer by a constant fix(2^32*golden_ratio)
%     and taking the highest n bits of the result (a 32 bit number).
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load if f-vectors f-evectors vfvect))

(fluid '(*sxhash-max-depth*))

(setq *sxhash-max-depth* 5)

(define-constant *sxhash-cons-default-value* 261835505)

% This is the golden ration times 2^32
%(define-constant !#hash-multiplier!# (wconst 16#9E3779B9))

% For reference: golden ration times 2^64 is 16#9e3779b97f4a7c15

%(flag '(sxhash-internal sxhash-string big-sxhash ht-check-twopower ht-compute-size is-hashtable)
%       'internalfunction)

(de sxhash (o)
    (sxhash-internal o *sxhash-max-depth*))

(de sxhash-internal (o depth)
  (case (tag o)
        ((posint-tag) o)
        ((negint-tag) (inf o))
        ((fixnum-tag) (inf (fixval (fixinf o))))
        ((bignum-tag) (big-sxhash o))
        ((floatnum-tag) (wxor (floathiword o) (floatloword o)))
        ((string-tag bytes-tag) (sxhash-string o))
        ((halfwords-tag)
         (let ((n (halfwordlen o))
               (s (halfworditm o 0)))
           (for (from i 1 n 1)                                                                                                                                                                           (do (setq s (wxor (wshift s 4) (halfworditm o i)))))
           (inf s)))
        ((words-tag)
         (let ((n (wrdlen o))
               (s (inf (wrditm o 0))))
           (for (from i 1 n 1)                                                                                                                                                                           (do (setq s (wxor (wshift s 6) (inf (wrditm o i))))))
           (inf s)))
        ((vector-tag)
         (let ((n (upbv o))
               (s 0))
           (for (from i 0 n 1)
		%% do a left shift of 5 bits before using the intermediate value
		%% otherwise all vectors with the same elements but different order would hash to the same value
                (do (setq s (wxor (wshift s 5) (sxhash-internal (getv o i) depth)))))
           (inf s)))
        ((pair-tag)
	 (progn
	   (if (not (greaterp depth 0))
	       *sxhash-cons-default-value*
	     (let ((s 0)
		   (o1 o))
	       (while (and (pairp o1) (greaterp depth 1))
		 %% do a left shift of 3 bits before using the intermediate value
		 %% otherwise all lists with the same elements but different order would hash to the same value
		 %% use a different shift than for vectors in order to hash a list to another value than a vector with the same elements
		 (setq depth (sub1 depth))
		 (setq s (wxor (wshift s 3) (sxhash-internal (car o1) depth)))
		 (setq o1 (cdr o1)))
	       %% At this point we are either at the end of the list (o1 is not a pair) or depth is 1
	       %% In both cases we recurse on o1
	       (setq depth (sub1 depth))
	       (setq s (wxor (wshift s 3) (sxhash-internal o1 depth)))
	       (inf s)))))
        ((evector-tag)
         (let ((n (eupbv o))
               (s 0))
           (for (from i 0 n 1)
		%% see comments on vectors and pairs above
                (do (setq s (wxor (wshift s 7) (sxhash-internal (egetv o i) depth)))))
           (inf s)))
        ((id-tag) (id2int o))
        % More or less random value for other lisp objects
        ((hvect-tag hwords-tag hhalfwords-tag hbytes-tag) 4711)
        ((unbound-tag btr-tag forward-tag bvector-tag context-tag funarg-tag sgd-tag bstruct-tag) 1147)
        % Unknown tag bits
        (nil 0)))

(de sxhash-string (s)
    (let* ((inf (strinf s))
           (n (strlen inf))
           (result 0))
      (when (wgreaterp n (wdifference bitsperword 8))
        (setq n (wdifference bitsperword 8)))  
      (for (from i 0 n)
           (do
            (setq result (wxor result (wshift (strbyt inf i)
                                              (wdifference (wdifference bitsperword 16) i))))
            ))
      (inf result)))

(de big-sxhash (b)
    (let ((l (veclen (vecinf b)))
	  (result 0))
      (vfor (from i 1 l 1) (do (setq result (wxor (igetv b i) result))))
      (if (eq (igetv b 0) 'bigneg) (setq result (wnot result)))
      (inf result)))

(de ht-check-twopower (n)
  (let ((len 0))
    (while (eq 0 (wand n 1))
      (setq n (wshift n -1))
      (setq len (wplus2 len 1))
      )
    (if (eq n 1) len)))

(de mkhash1 (size flavor)
    (let ((len
	   (and (fixp size)
		(greaterp size 1)
		(lessp size 65537)
		(ht-check-twopower size))))
      (cond ((null len)
	     (stderror (bldmsg "Argument size to mkhash must be an integer of the form 2^n, 1<=n<=16, not %w" size)))
	    ((not (or (eq flavor 0) (eq flavor 'eq) (eq flavor 3) (eq flavor 'equal)))
	     (stderror (bldmsg "Argument %w to mkhash invalid as flavor" flavor)))
	    (t
	     (let ((comp (if (or (eq flavor 0) (eq flavor 'eq)) 'eq 'equal))
		   (v (mkvect size)))
	       (putv v 0 (list '!#hashtable!# comp len (isub1 size)))
               v)))))

%%
%% external entrypoint:
%%  allow any value for size (automatically increased to next power of 2) and ignore growth
%%

(de mkhash (size flavor growth)
    (mkhash1 (ht-compute-size size) flavor))

(de ht-compute-size (size)
    (cond ((or (not (fixp size)) (lessp size 2) (greaterp size 65536))
	   (stderror (bldmsg "Argument size to mkhash must be an integer of the form 2^n, 1<=n<=16, not %w" size)))
	  (t
	   (let ((power 1))
	     (while (wlessp power size)
	       (setq power (wshift power 1)))
	     power))))
    
(ds is-hashtable (table)
    (and (vectorp table)
	 (let ((first (getv table 0)))
	   (and (pairp first) (eq (car first) '!#hashtable!#)))))

(ds valid-hashtable (table fnc)
    (if (not (is-hashtable table))
        (stderror (bldmsg "Argument %w to %w is not a hashtable" table fnc))
      t))

(ds hash-to-key (key shftamount mask)
    (wplus2 1 (wand (wshift (wtimes2 (sxhash key) (wconst 16#9E3779B9)) shftamount) mask)))

(de puthash (key table value)
    (if (valid-hashtable table 'puthash)
        (let* ((x (getv table 0))
               (comp (cadr x))
	       (len (caddr x))
               (mask (cadddr x))
	       (shftamount (wdifference len 32))
               (hkey (hash-to-key key shftamount mask))
               (v (getv table hkey))
               (found (if (eq comp 'eq) (atsoc key v)
                        (assoc key v))))
          (if (not found) (putv table hkey (cons (cons key value) v))
            (let ((oldvalue (cdr found)))
              (cond ((and (eq comp 'equal) (not (equal value oldvalue)))
                     (rplacd found value))
                    ((and (eq comp 'eq) (not (eq value oldvalue)))
                     (rplacd found value))
                    ))))))


(de gethash (key table)
    (if (valid-hashtable table 'gethash)
        (let* ((x (getv table 0))
               (comp (cadr x))
	       (len (caddr x))
               (mask (cadddr x))
	       (shftamount (wdifference len 32))
               (hkey (hash-to-key key shftamount mask))
               (v (getv table hkey))
               (found (if (eq comp 'eq) (atsoc key v)
                        (assoc key v))))
          (if found (cdr found)))))
    
(de remhash (key table value)
    (if (valid-hashtable table 'remhash)
        (let* ((x (getv table 0))
               (comp (cadr x))
	       (len (caddr x))
               (mask (cadddr x))
	       (shftamount (wdifference len 32))
               (hkey (hash-to-key key shftamount mask))
               (v (getv table hkey))
               (found (if (eq comp 'eq) (atsoc key v)
                        (assoc key v))))
          (if found (putv table hkey (del comp found v))))))
