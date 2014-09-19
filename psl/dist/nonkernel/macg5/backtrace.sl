%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:BACKTRACE.SL 
% Title:        Functions for displaying the return stack. 
% Author:       ??? 
% Created:      ??? 
% Modified:     22-Mar-84 09:23:19 (Brian Beach) 
% Package:      Kernel 
%
% (c) Copyright 1987, University of Utah, all rights reserved.
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

(on fast-integers)

(compiletime (put 'memo 'opencode '((lwz (reg 1) (displacement (reg 1) 0)))))

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
             (cond ((weq (tag (getmem i)) btr-tag)
                    (backtrace1 (mkid (inf (getmem i))) interpflag))
                   ((setq x (returnaddressp (getmem i)))
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
         (cond ((and (eq (tag (getmem i)) 253)
                     (wgreaterp (inf (getmem i)) heapupperbound))
                (writechar (char tab))
                (channelwriteunknownitem out* (getmem i))
                (terpri))
               ((weq (tag (getmem i)) btr-tag)
                (printf "       %r%n" (mkid (inf (getmem i)))))
               ((setq x (returnaddressp (getmem i)))
                (printf "%p -> %p:%n"
                        (code-address-to-symbol (getmem i) ) x))
               (t (printf "     %p%n" (getmem i))))))
    (return (terpri))))

    

(de backtrace1 (item code)
  %
  % Code is 1 if Interpreter functions should be printed, 0 if not.
  %
 (unless (greaterp (inf item) maxsymbols)
  (unless (memq item ignoredinbacktrace*)
    (unless (and (equal code 0) (memq item interpreterfunctions*))
    (when (stringp (symnam item)) (prin1 item))
      (writechar (char blank))))))

(off fast-integers)
