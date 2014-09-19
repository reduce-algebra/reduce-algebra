%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:BREAK.SL 
% Title:        Break using new top loop 
% Author:       Eric Benson 
% Created:      23 October 1981 
% Modified:     04-Apr-84 15:08:49 (Brian Beach) 
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
% 01-Dec-83 14:19:21 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(*break *quitbreak breakeval* breakname* breakvalue* errorform*
                breaklevel* maxbreaklevel* toploopname* toploopeval*
                toploopread* toploopprint* *defn % break binds !*DEFN to NIL

                breakin* breakout*))

(loadtime
  (progn (setq breaklevel* 0)
         (setq maxbreaklevel* 5)
         ))

(de break ()
  %. Enter top loop within evaluation
%%%%%  (kernel-fatal-error "Break entered.")  %%% TEMPORARY
  ((lambda (breaklevel*)
           (prog (oldin oldout *quitbreak breakvalue* *defn)
                 (setq oldin (rds breakin*))
                 (setq oldout (wrs breakout*))
                 (setq *quitbreak t)
                 (if toploopname*
                   (progn (when (neq toploopeval* 'breakeval)
                            (setq breakeval* toploopeval*)
                            (setq breakname*
                             (concat toploopname* " break")))
                          (catch '$break$
                           (toploop toploopread* toploopprint* 'breakeval
                            breakname* "Break loop")))
                   (progn (setq breakeval* 'eval)
                          (setq breakname* "lisp break")
                          (catch '$break$
                           (toploop 'read 'print 'breakeval breakname*
                            "Break loop"))))
                 (rds oldin)
                 (wrs oldout)
                 (return (if *quitbreak
                           (let (*break
                                 *emsgp)
                                (stderror "Exit to ErrorSet"))
                           (eval errorform*)))))
   (plus breaklevel* 1)))

(de breakeval (u)
  (let (f)
       (if (and (idp u) (setq f (get u 'breakfunction)))
         (apply f nil)
         (setq breakvalue* (apply breakeval* (list u))))))

(de breakquit ()
  (setq *quitbreak t)
  (throw '$break$ nil))

(de breakcontinue ()
  (setq errorform* (mkquote breakvalue*))
  (breakretry))

(de breakretry ()
  (if *continuableerror
    (progn (setq *quitbreak nil)
           (throw '$break$ nil))
    (progn (prin2t "Can only continue from a continuable error; use Q (BreakQuit) to quit")
           (terpri))))

(de helpbreak ()
  (evload '(help))
  (displayhelpfile 'break))

(de breakerrmsg ()
  (printf "ErrorForm!* : %r %n" errorform*))

(de breakedit ()
  (if (getd 'edit)
    (setq errorform* (edit errorform*))
    (errorprintf "*** Editor not loaded")))

(loadtime
  (deflist '((q breakquit)
	     (? helpbreak)
	     (a reset) % Abort to top level
             (m breakerrmsg)
	     (e breakedit)
	     (c breakcontinue)
             (r breakretry)
	     (i interpbacktrace)
	     (v verbosebacktrace)
)%             (t backtrace))
           'breakfunction))

