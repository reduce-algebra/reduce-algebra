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
%    comp           - the comparator functin (eq or equal)
%    mask           - the number 2^n-1
% The rest of the vector elements are the buckets for the hashtable, each of which
% is an association list of (key . value) elements.
%
% The bucket number for a key is computed in a two step process:
% 1. The function sxhash computes a PSL posint (i.e. an integer that fits in a machine word
%     and has zero tag bits). This integer is an invariant over the life of the lisp image.
% 2. The bucket number is computed by multiplying this integer by a constant fix(2^32*golden_ratio)
%     and taking the lowest n bits of the result.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load if f-vectors f-evectors))

% This is the golden ration times 2^32
%(define-constant !#hash-multiplier!# (wconst 16#9E3779B9))

% For reference: golden ration times 2^64 is 16#9e3779b97f4a7c15


(de sxhash (o)
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
           (for (from i 1 n 1)                                                                                                                                                                           (do (setq s (wxor s (halfworditm o i)))))
           s))
        ((words-tag)
         (let ((n (wrdlen o))
               (s (inf (wrditm o 0))))
           (for (from i 1 n 1)                                                                                                                                                                           (do (setq s (wxor s (inf (wrditm o i))))))
           s))
        ((vector-tag)
         (let ((n (upbv o))
               (s (sxhash (getv o 0))))
           (for (from i 1 n 1)
                (do (setq s (wxor s (sxhash (getv o i))))))
           s))
        ((pair-tag) (wxor (sxhash (car o)) (sxhash (cdr o))))
        ((evector-tag)
         (let ((n (eupbv o))
               (s (sxhash (egetv o 0))))
           (for (from i 1 n 1)
                (do (setq s (wxor s (sxhash (egetv o i))))))
           s))
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

(de ht-check-twopower (n)
    (while (eq 0 (wand n 1))
      (setq n (wshift n -1))
      )
    (eq n 1))

(de mkhash (size flavor)
    (cond ((or (not (fixp size))
               (lessp size 2)
               (greaterp size 65536)
               (not (ht-check-twopower size)))
           (stderror (bldmsg "Argument size to mkhash must be an integer of the form 2^n, 1<=n<=16, not %w" size)))
	  ((not (or (eq flavor 0) (eq flavor 'eq) (eq flavor 3) (eq flavor 'equal)))
	   (stderror (bldmsg "Argument %w to mkhash invalid as flavor" flavor)))
	  (t
	   (let ((comp (if (or (eq flavor 0) (eq flavor 'eq)) 'eq 'equal))
		 (v (mkvect size)))
	     (putv v 0 (list '!#hashtable!# comp (isub1 size)))
               v))))

(ds is-hashtable (table)
    (and (vectorp table)
         (eq (car (getv table 0)) '!#hashtable!#)))

(ds valid-hashtable (table fnc)
    (if (not (is-hashtable table))
        (stderror (bldmsg "Argument %w to %w is not a hashtable" table fnc))
      t))

(ds hash-to-key (key mask)
    (wand (wtimes2 (sxhash key) (wconst 16#9E3779B9)) mask))

(de puthash (key table value)
    (if (valid-hashtable table 'puthash)
        (let* ((x (getv table 0))
               (comp (cadr x))
               (mask (caddr x))
               (hkey (hash-to-key key mask))
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
               (mask (caddr x))
               (hkey (hash-to-key key mask))
               (v (getv table hkey))
               (found (if (eq comp 'eq) (atsoc key v)
                        (assoc key v))))
          (if found (cdr found)))))
    
(de remhash (key table value)
    (if (valid-hashtable table 'remhash)
        (let* ((x (getv table 0))
               (comp (cadr x))
               (mask (caddr x))
               (hkey (hash-to-key key mask))
               (v (getv table hkey))
               (found (if (eq comp 'eq) (atsoc key v)
                        (assoc key v))))
          (if found (putv table hkey (del comp found v))))))
