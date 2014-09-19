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
% (c) Copyright 1983, Hewlett-Packard Company, all rights reserved.
% (c) Copyright 1981, University of Utah
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 26 Jan 1984 1001-PST (Brian Beach)
%  Corrected file name in header.
% 01-Dec-83 14:58:48 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(progjumptable* % A-List of labels and expressions
	 progbody*))

% Tail of the current PROG
(compiletime (on pcmac))
(df prog (progbody*)
  %. Program feature function
  (prog (progjumptable* n result)
        (unless (pairp progbody*)
          (return nil))
        (setq n 0)
        (foreach x in (car progbody*) do
                 (progn (pbind1 x)
                        (setq n (plus n 1))))
        (setq progbody* (cdr progbody*))
        (foreach x on progbody* do (when (idp (car x))
                   (setq progjumptable* (cons x progjumptable*))))
        (while (progn (while (and (pairp progbody*) (idp (car progbody*)))
                        (setq progbody* (cdr progbody*)))
                      % skip over labels
                      (pairp progbody*))
          % eval the expression
          (progn (setq result (*catch '$prog$ (eval (car progbody*))))
                 (unless throwsignal*
                   (setq result nil)
                   (setq progbody* (cdr progbody*)))))
  (console-print-string " nun unbinden wir ") (unixputn n) (console-newline)
        (unbindn n)
        (return result)))

(compiletime (off pcmac))
(df go (u)
  %. Goto label within PROG
  (let (newprogbody)
       (if progbody*
         (progn (setq newprogbody (atsoc (car u) progjumptable*))
                (if (null newprogbody)
                  (continuableerror 3001
                   (bldmsg "%r is not a label within the current scope"
                    (car u))
                   (cons 'go u))
                  (progn (setq progbody* newprogbody)
                         (*throw '$prog$ nil))))
         (continuableerror 3101 "GO attempted outside the scope of a PROG"
          (cons 'go u)))))

(de return (u)
  %. Return value from PROG
  (if progbody*
    (progn (setq progbody* nil)
           (*throw '$prog$ u))
    (conterror 3102 "RETURN attempted outside the scope of a PROG"
               (return u))))

