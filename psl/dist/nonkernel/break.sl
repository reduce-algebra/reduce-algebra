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
% 03-Nov-94 (Herbert Melenk)
%   Enable break loop control in lower case mode.
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
  (deflist '((!Q breakquit) (!q breakquit)
	     (? helpbreak)
	     (!A reset) (!a reset) % Abort to top level
             (!M breakerrmsg) (!m breakerrmsg)
	     (!E breakedit)  (!e breakedit)
	     (!C breakcontinue)(!c breakcontinue)
             (!R breakretry) (!r breakretry)
	     (!I interpbacktrace) (!i interpbacktrace)
	     (!V verbosebacktrace) (!v verbosebacktrace)
             (!T backtrace) (!t backtrace))
           'breakfunction))

