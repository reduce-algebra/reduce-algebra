%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:IF.SL 
% Description:  if-then-else macro 
% Author:       Cris Perdue, Hewlett-Packard CRC 
% Created:      19 Aug 82 
% Modified:     19 Jan 1984 1442-PST (Brian Beach) 
% Status:        Open Source: BSD License
% Mode:         Lisp 
% Package:      Utilities 
% Compiletime:  
% Runtime:      
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
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
% 19 Jan 1984 1442-PST (Brian Beach)
%   Added standard header.
% 31 Aug 1983 1437-PDT, Cris Perdue
%   Converted calls on error to be calls on stderror.
%   Extended IF to allow "else if" as an alternative to "elseif".
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(setq *usermode nil)

% Syntax of new IF is:
% (if <expr> [then <expr> ... ] [<elseif-part> ... ] [else <expr> ... ])
% <elseif-part> = elseif <expr> [then <expr> ... ]
% <elseif-part> = else if <expr> [then <expr> ... ]
% This syntax allows construction of arbitrary CONDs.
(defun construct-new-if (form)
  (let ((clause)
	(next-clause)
	(stmt (list 'cond))
	(e form))
    (while e
      (cond
       ((or (sym= (first e) 'if)
	    (sym= (first e) 'elseif))
	(cond ((or (null (rest e))
		   (not (or (null (rest (rest e)))
			    (sym= (third e) 'then)
			    (sym= (third e) 'else)
			    (sym= (third e) 'elseif))))
	       (stderror "Can't expand IF.")))
	(setq next-clause (next-if-clause e))
	(setq clause
	  (cond ((and (rest (rest e))
		      (sym= (third e) 'then))
		 (cons (second e)
		       (ldiff (pnth e 4) next-clause)))
		(t (list (second e)))))
	(nconc stmt (list clause))
	(setq e next-clause)
	(next))
       ((sym= (first e) 'else)
	(cond ((null (rest e))
	       (stderror "Can't expand IF.")))
	(cond ((sym= (second e) 'if)
	       (setq e (rest e))
	       (next)))
	(cond ((next-if-clause e)
	       (stderror "Can't expand IF.")))
	(nconc stmt (list (cons t (rest e))))
	(exit))))
    stmt))

(defun next-if-clause (tail)
  (for (on x (rest tail))
       (do (cond ((or (sym= (first x) 'else)
		      (sym= (first x) 'elseif))
		  (return x))))
       (returns nil)))

(defun sym= (a b) (eq a b))

(defun ldiff (x y)
  (cond ((null x) nil)
	((eq x y) nil)
	(t (cons (first x) (ldiff (rest x) y)))))

% Checks for (IF <expr> <KEYWORD> . . .  ) form.  If keyword form,
% does fancy expansion, otherwise expands compatibly with MacLISP
% IF expression.  <KEYWORD> ::= THEN | ELSE | ELSEIF
(dm if (form)
  (let ((b (rest (rest form)))
	(test (second form)))
       (cond
	((or (sym= (first b) 'then)
	     (sym= (first b) 'else)
	     (sym= (first b) 'elseif))
	 (construct-new-if form))
	((eq (length b) 1) `(cond (,test ,(nth b 1))))
	(t `(cond (,test ,(nth b 1)) (t ,@(pnth b 2)))))))
