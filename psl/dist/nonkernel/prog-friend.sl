%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:PROG-FRIEND.SL
% Title:        PROG, GO, and RETURN 
% Author:       Eric Benson 
% Created:      20 August 1981 
% Modified:     22-Mar-84 11:51:38 (Brian Beach) 
% Status:       Experimental 
% Mode:         Lisp 
% Package:      Kernel 
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
% 24 Nov 1994 (Herbert Melenk)
%  modified progjumptable* assoc structure to memq (saving conses).
%  Enabled GO to prog body on higher level.
% 26 Jan 1984 1001-PST (Brian Beach)
%  Corrected file name in header.
% 01-Dec-83 14:58:48 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(
         progjumptable* % A-List of labels and expressions
	 progbody*      % Tail of the current PROG       
))

(global '(
         progform*      % Currently processed statement of a PROG
))

(df prog (progbody)
  %. Program feature function
  (prog (n x result)

        (unless (pairp progbody) (return nil))
        (setq n 0)

        (foreach x in (car progbody) do
                 (progn (pbind1 x) (setq n (plus n 1))))
        (setq progbody (cdr progbody))

        (setq x progbody)
        (while (and (pairp x)(pairp (car x))) (setq x (cdr x)))

        (let ((progjumptable* x) 
              (progbody*      progbody))


         (while progbody*

            (if (pairp (setq progform* (car progbody*)))
                (setq result (*catch '$prog$ (eval progform*)))
                (setq throwsignal* nil))
   
            (unless throwsignal*
                  (setq result nil)
                  (setq progbody* (cdr progbody*)))
        ))
        (unbindn n)
             % Now we have unwound the complete PROG structure.
             % A pending go is evaluated towards the next higher level
             % where it may be satisfied or lead to an error.
        (when (eq result '$pending-go$) (eval progform*)) 
        (return result)))

(df go (u)
  %. Goto label within PROG
  (let*((lbl (car u))
        (x (memq lbl progjumptable*)))
   (cond
      ((null progbody*) (stderror (bldmsg "GO: Label >%w< not found" lbl)))
      (x (setq progbody* (cdr x)) (*throw '$prog$ nil))
      (t (setq progbody* nil) 
         (when (not (eq (car progform*) 'go)) (setq progform* (cons 'go u)))
         (*throw '$prog$ '$pending-go$)) )))
              

(de return (u)
  %. Return value from PROG
  (if progbody*
    (progn (setq progbody* nil) (*throw '$prog$ u))
    (stderror "RETURN attempted outside the scope of a PROG")))

