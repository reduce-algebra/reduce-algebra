%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:BACKQUOTE.SL 
% Description:  tool for building partially quoted lists 
% Author:       Don Morrison, Hewlett-Packard CRC 
% Created:      Wednesday, 12 May 1982 
% Modified:     19 Jan 1984 1429-PST (Brian Beach) 
% Status:       Open Source: BSD License
% Mode:         Lisp 
% Package:      Utilities 
% Compiletime:  
% Runtime:      
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
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
% 19 Jan 1984 1429-PST (Brian Beach)
%   Added standard header.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Backquote is  similar  to MACLISP's  `  (that's backwards!)   mechanism.   In
% essence the  body  of  the  backquote is  quoted,  except  for  those  things
% surrounded by unquote, which are evaluated at macro expansion time.  UNQUOTEL
% splices in a  list, and  unquoted splices  in a  list destructively.   Mostly
% useful for defining macro's.

(dm backquote (u) (backquote-form (cadr u)))

(de backquote-form (u)
  (cond
    ((vectorp u) (backquote-vector u))
    ((atom u)
      (cond
	((and (idp u) (not (memq u '(t nil)))) (mkquote u))
	(t u)))
    ((eq (car u) 'unquote) (cadr u))
    ((eq (car u) 'backquote) (backquote-form (backquote-form (cadr u))))
    ((memq (car u) '(unquotel unquoted))
      (ContinuableError 99 (BldMsg "%r can't be spliced in here." u)) u)
    ((eqcar (car u) 'unquotel)
      (cond
	((cdr u) (list 'append (cadar u) (backquote-form (cdr u))))
	(t (cadar u))))
    ((eqcar (car u) 'unquoted)
      (cond
	((cdr u) (list 'nconc (cadar u) (backquote-form (cdr u))))
	(t (cadar u))))    
    (t (backquote-list u))))

(de backquote-vector (u)
  ((lambda (n rslt all-quoted)  % can't use LET 'cause it ain't defined yet
     ((lambda (i)
	(while (not (minusp i)) % can't use FOR or DO for the same reason
	  ((lambda (x)
	     (setq all-quoted (and all-quoted (backquote-constantp x)))
	     (setq rslt (cons x rslt)))
	    (backquote-form (getv u i)))
	  (setq i (sub1 i))))
       n)
     (cond
       (all-quoted
	 ((lambda (i vec)
	    (while (not (greaterp i n))
	      (putv vec i (backquote-constant-value (car rslt)))
	      (setq rslt (cdr rslt))
	      (setq i (add1 i)))
	    vec)
	   0
	   (mkvect n)))
       (t (cons 'vector rslt))))
    (upbv u)
    nil
    t))

(de backquote-list (u)
  ((lambda (car-u cdr-u)  % can't use LET 'cause it ain't defined yet
     (cond
       ((null cdr-u)
	 (cond
	   ((backquote-constantp car-u)
	     (list 'quoted-list (backquote-constant-value car-u)))
	   (t (list 'list car-u))))
       ((constantp cdr-u)
	 (cond
	   ((backquote-constantp car-u)
	     (list 'quoted-list* (backquote-constant-value car-u) cdr-u))
	   (t (list 'list* car-u cdr-u))))
       ((and (pairp cdr-u) (memq (car cdr-u) '(list list*)))
	 (cons (car cdr-u) (cons car-u (cdr cdr-u))))
       ((and
	  (pairp cdr-u)
	  (memq (car cdr-u) '(quoted-list quoted-list*)))
	 (cond
	   ((backquote-constantp car-u)
	     (cons
	       (car cdr-u)
	       (cons (backquote-constant-value car-u) (cdr cdr-u))))
	   (t (list
		'list*
		car-u
		(mkquote (backquote-constant-value cdr-u))))))
       ((eqcar cdr-u 'quote)
	 (cond
	   ((backquote-constantp car-u)
	      (list
	       'quoted-list*
	       (backquote-constant-value car-u)
	       (cadr cdr-u)))
	   (t (list 'list* car-u cdr-u))))
       (t (list 'list* car-u cdr-u))))
    (backquote-form (car u))
    (backquote-form (cdr u))))

(de backquote-constantp (u)
  (cond
    ((pairp u) (memq (car u) '(quote quoted-list quoted-list*)))
    (t (not (idp u)))))

(de backquote-constant-value (x)
  (cond
    ((eqcar x 'quote) (cadr x))
    ((eqcar x 'quoted-list) (cdr x))
    ((eqcar x 'quoted-list*)
      (cadr (apply 'quoted-list* (list x))))
    (t x)))

% The following, while possibly useful in themselves, are mostly included
% for use by backquote and friends.

(dm quoted-list (u) (mkquote (cdr u)))
  
(dm list* (u) (expand (cdr u) 'cons))

(dm quoted-list* (u)
  (cond
    ((pairp (cdr u))
      (setq u (reverse (cdr u)))
      ((lambda (a)
	 (foreach elem in (cdr u) do
	   (setq a (cons elem a)))
	 (mkquote a))
	(car u)))))
%     (t (error ... ?     

% Since unquote and friends should be completely stripped out by backquote,
% make it an error to try and evaluate them.  These could be much better...

(dm unquote (u) (ContinuableError
		  99
		  (BldMsg "%r is not within backquote." u)
		  u))

(copyd 'unquotel 'unquote)

(copyd 'unquoted 'unquote)
