%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:BACKTRACE.SL 
% Title:        Functions for displaying the return stack. 
% Author:       ??? 
% Created:      ??? 
% Modified:     22-Mar-84 09:23:19 (Brian Beach) 
% Package:      Kernel 
% Status:       Open Source: BSD License
%
% (c) Copyright 1987, University of Utah, all rights reserved.
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 27-May-87 (Harold Carr & Leigh Stoller)
%  Added fluid declaration of in* and out*.
% 22-Mar-84 09:13:24 (Brian Beach)
%  Fixed constants.  Removed WFORS.
% 01-Dec-83 14:12:23 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  $Id$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(on fast-integers)

(compiletime (put 'memo 'opencode '((l (reg 1) (displacement (reg 1) 0)))))

(compiletime
  (flag '(backtrace1 backtracerange) 'internalfunction))

(fluid '(ignoredinbacktrace* options* interpreterfunctions*))
(fluid '(in* out*))

(setq ignoredinbacktrace*
      (list 'eval 'apply 'fastapply 'codeapply 'codeevalapply 'catch
            'errorset 'evprogn 'toploop 'breakeval 'bindeval 'break 'main
            'standardlisp 'TOP-LOOP-EVAL-AND-PRINT 'ORIGINAL-MAIN))

(setq interpreterfunctions* (list 'cond 'prog 'and 'or 'progn 'setq))

(global '(heapupperbound stacklowerbound))

(lap '((*entry get-stack-pointer expr 0)
       (*alloc 0)
       (*move (reg st) (reg 1))
       (*exit 0)))

(de interpbacktrace ()
  (prog (here)
        (setq here (get-stack-pointer))
        (printf "Backtrace, including interpreter functions, from top of stack:%n")
        (return (backtracerange here stacklowerbound 1))))

(de backtrace ()
  (prog (here x)
        (setq here (get-stack-pointer))
        (printf "Backtrace from top of stack:%n")
        (return (backtracerange here stacklowerbound 0))))

(de backtracerange (starting ending interpflag)
  (prog (x i)
    (setq ending  (wshift ending 5))
    (for (from ii starting ending
               (wminus (wtimes2 addressingunitsperitem stackdirection)))
         (do (setq i ii)
             (cond ((weq (tag (memo i)) btr-tag)
                    (backtrace1 (mkid (inf (memo i))) interpflag))
                   ((setq x (returnaddressp (memo i)))
                    (backtrace1 x interpflag)))))
    (return (terpri))))

(de verbosebacktrace ()
  (prog (here x i stkl)
    (setq here (get-stack-pointer))
    (setq stkl (wshift stacklowerbound 5))
    (for % start a little before here
     (from ii here stkl
           (wminus (wtimes2 addressingunitsperitem stackdirection)))
     (do (setq i ii)
         (cond ((and (eq (tag (memo i)) 29)
                     (wgreaterp (inf (memo i)) heapupperbound))
                (writechar (char tab))
                (channelwriteunknownitem out* (memo i))
                (terpri))
               ((weq (tag (memo i)) btr-tag)
                (printf "       %r%n" (mkid (inf (memo i)))))
               ((setq x (returnaddressp (memo i)))
                (printf "%p -> %p:%n"
                        (code-address-to-symbol (memo i) ) x))
               (t (printf "     %p%n" (memo i))))))
    (return (terpri))))

    

(de backtrace1 (item code)
  %
  % Code is 1 if Interpreter functions should be printed, 0 if not.
  %
  (unless (memq item ignoredinbacktrace*)
    (unless (and (equal code 0) (memq item interpreterfunctions*))
      (prin1 item)
      (writechar (char blank)))))

(off fast-integers)
