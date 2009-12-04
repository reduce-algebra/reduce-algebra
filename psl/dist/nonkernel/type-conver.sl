%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:TYPE-CONVERSIONS.SL 
% Title:        Functions for converting between various data types 
% Author:       Eric Benson 
% Created:      28 August 1981 
% Modified:     04-Apr-84 14:45:33 (Brian Beach) 
% Status:       Experimental 
% Mode:         Lisp 
% Package:      Kernel 
% Compiletime:  
% Runtime:      
%
% (c) Copyright 1982, University of Utah
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
% Revisions:
%
% 11-Oct-87 (Robert Kessler)
%  Bug fix suggested by ZIB - make sys2fixn save argument value before calling 
%  gtfixn which could cause a gc and thus the argument could be incorrectly
%  traced.
% 26 Jan 1984 1001-PST (Brian Beach)
%  Corrected file name in header.
% 01-Dec-83 15:04:02 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(on fast-integers)

(compiletime
  (flag '(sys2fixn) 'internalfunction))

(de id2int (u)
  % Return ID index as Lisp number
  (if (idp u)
    (mkint (idinf u))
    (noniderror u 'id2int)))

(de int2id (u)
  % Return ID corresponding to index
  (let (stripu)
       (if (intp u)
         (progn (setq stripu (intinf u))
                (if (wgeq stripu 0)
                  (mkid stripu)
                  (typeerror u 'int2id '"positive integer")))
         (nonintegererror u 'int2id))))

(de int2sys (n)
  % Convert Lisp integer to untagged
  (cond ((intp n) (intinf n))
        ((fixnp n) (fixval (fixinf n)))
        (t (nonintegererror n 'int2sys))))

(de lisp2char (u)
  % Convert Lisp item to syslsp char
  (prog (c)
        % integers, IDs and strings are legal
        (return (cond ((and (intp u) (wgeq (setq c (intinf u)) 0)
                        (wleq c 255))
                       c)
                      ((idp u) % take first char of ID print name

                       (strbyt (strinf (symnam (idinf u))) 0))
                      ((stringp u) (strbyt (strinf u) 0))
                      (t % take first character of Lisp string

                         (noncharactererror u 'lisp2char))))))

(de int2code (n)
  % Convert Lisp integer to code pointer
  (mkcode n))

(de sys2int (n)
  % Convert word to Lisp number
  (if (weq (signedfield n
			(wdifference infstartingbit 1)
                        (wplus2 infbitlength 1))
           n)
    n
    (sys2fixn n)))

(fluid '(savefixn-tag savefixn-inf))

(de sys2fixn (n)
  (prog (fx)
        (setf savefixn-tag (tag n))
        (setf savefixn-inf (inf n))
        (setf n 0)
        (setq fx (gtfixn))
        (setf (fixval fx) (mkitem savefixn-tag savefixn-inf))
        (return (mkfixn fx))))

(de id2string (u)
  % Return print name of U (not copy)
  (if (idp u)
    (symnam (idinf u))
    (noniderror u 'id2string)))

% The functions for converting strings to IDs are Intern and NewID.  Intern
% returns an interned ID, NewID returns an uninterned ID. They are both found

% in OBLIST.RED
(de string2vector (u)
  % Make vector of ASCII values in U
  (if (stringp u)
    (prog (stripu v n)
      (setq n (strlen (strinf u)))
      (setq v (gtvect n))
      (setq stripu (strinf u))
      (for % in case GC occurred

       (from i 0 n 1)
       (do (setf (vecitm v i) (mkint (strbyt stripu i)))))
      (return (mkvec v)))
    (nonstringerror u 'string2vector)))

(de vector2string (v)
  % Make string with ASCII values in V
  (if (vectorp v)
    (prog (stripv s n ch)
      (setq n (veclen (vecinf v)))
      (setq s (gtstr n))
      (setq stripv (vecinf v))
      (for % in case GC occurred

       (from i 0 n 1)
       (do (setf (strbyt s i) (lisp2char (vecitm stripv i)))))
      (return (mkstr s)))
    (nonvectorerror v 'vector2string)))

(de list2string (p)
  % Make string with ASCII values in P
  (cond ((null p) '"")
        ((pairp p)
         (prog (s n)
	   (setq n (wdifference (intinf (length p)) 1))
	   (setq s (gtstr n))
	   (for (from i 0 n 1)
		(do (progn (setf (strbyt s i) (lisp2char (car p)))
			   (setq p (cdr p)))))
	   (return (mkstr s))))
        (t (nonpairerror p 'list2string))))

(de string2list (s)
  % Make list with ASCII values in S
  (if (stringp s)
    (prog (l n)
      (setq l nil)
      (setq n (strlen (strinf s)))
      (for (from i n 0 -1)
	   (do (setq l (cons (mkint (strbyt (strinf s) i)) l))))
      % strip S each time in case GC
      (return l))
    (nonstringerror s 'string2list)))

(de list2vector (l)
  % convert list to vector
  (if (or (pairp l) (null l))
    (prog (v n)
      % this function is used by READ
      (setq n (wdifference (intinf (length l)) 1))
      (setq v (gtvect n))
      (for (from i 0 n 1)
	   (do (progn (setf (vecitm v i) (car l))
		      (setq l (cdr l)))))
      (return (mkvec v)))
    (nonpairerror l 'list2vector)))

(de vector2list (v)
  % Convert vector to list
  (if (vectorp v)
    (prog (l n)
      (setq l nil)
      (setq n (veclen (vecinf v)))
      (for (from i n 0 -1)
	   (do (setq l (cons (vecitm (vecinf v) i) l))))
      % strip V each time in case GC
      (return l))
    (nonvectorerror v 'vector2list)))


(off fast-integers)
