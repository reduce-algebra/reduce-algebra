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

(compiletime
  (flag '(backtrace1 backtracerange) 'internalfunction))

(fluid '(ignoredinbacktrace* options* interpreterfunctions*))
(fluid '(in* out*))

(setq ignoredinbacktrace*
      (list 'eval 'apply 'fastapply 'codeapply 'codeevalapply 'catch
            'errorset 'evprogn 'toploop 'breakeval 'bindeval 'break 'main
            'stackcheck))

(setq interpreterfunctions* (list 'cond 'prog 'and 'or 'progn 'setq))

(global '(heapupperbound stacklowerbound))

%%  on-altstack* indicates that we are on an alternate signal stack
%%  and that stack-pointer* is the real stack pointer 
(fluid '(stack-pointer* on-altstack*))

(de interpbacktrace ()
  (prog (here)
        (setq here (if on-altstack* stack-pointer* (loc here)))
        (printf "Backtrace, including interpreter functions, from top of stack:%n")
        (return (backtracerange here (wshift stacklowerbound 5) 1))))

(de backtrace ()
  (prog (here x)
        (setq here (if on-altstack* stack-pointer* (loc here)))
        (printf "Backtrace from top of stack:%n")
        (return (backtracerange here (wshift stacklowerbound 5) 0))))

(de backtracerange (starting ending interpflag)
  (prog (x)
    (for (from i starting ending
	       (wminus
		(wtimes2 addressingunitsperitem
			 stackdirection)))
	 (do (cond ((and (weq (tag (getmem i)) btr-tag)
                         (wlessp (inf (getmem i)) maxsymbols))
		    (backtrace1 (mkid (inf (getmem i))) interpflag))
		   ((setq x (returnaddressp (getmem i)))
		    (backtrace1 x interpflag)))))
    (return (terpri))))

(de verbosebacktrace ()
  (prog (here x)
    (unless (member 'addr2id options*)
      (load addr2id))
    (setq here (loc here))
    (for % start a little before here
     (from i here (wshift stacklowerbound 5)
	   (wminus
	    (wtimes2 addressingunitsperitem
		     stackdirection)))
     (do (cond ((and (codep (getmem i))
		     (wgreaterp (inf (getmem i)) heapupperbound))
		(writechar (char tab))
		(channelwriteunknownitem out* (getmem i))
		(terpri))
	       ((weq (tag (getmem i)) btr-tag)
		(printf "	%r%n" (mkid (inf (getmem i)))))
	       ((setq x (returnaddressp (getmem i)))
		(printf "%p -> %p:%n"
			(code-address-to-symbol (inf (getmem i))) x))
	       (t (printf "	%p%n" (getmem i))))))
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
