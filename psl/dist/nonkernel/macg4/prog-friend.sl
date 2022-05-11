%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:PROG-FRIEND.SL
% Title:        PROG, GO, and RETURN 
% Author:       Eric Benson 
% Created:      20 August 1981 
% Modified:     22-Mar-84 11:51:38 (Brian Beach) 
% Status:       Open Source: BSD License 
% Mode:         Lisp 
% Package:      Kernel 
% Compiletime:  
% Runtime:      
%
% (c) Copyright 1983, Hewlett-Packard Company, all rights reserved.
% (c) Copyright 1981, University of Utah
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
% 26 Jan 1984 1001-PST (Brian Beach)
%  Corrected file name in header.
% 01-Dec-83 14:58:48 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  $Id$
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

