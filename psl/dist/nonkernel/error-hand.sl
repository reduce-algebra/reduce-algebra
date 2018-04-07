%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:ERROR-HANDLERS.SL 
% Title:        Low level error handlers 
% Author:       Eric Benson 
% Created:      18 August 1981 
% Modified:     23-Mar-84 09:01:35 (Brian Beach) 
% Status:       Open Source: BSD License
% Mode:         Lisp 
% Package:      Kernel 
% Compiletime:  PL:IF-SYSTEM.B 
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
%  Thu Mar  1 21:54:21 1984, Edit by Fish
%    Changed YesP EOF behavior for scripts such as "build".  Normal Unix
%    behavior will now be to exit PSL, returning a non-zero status code
%    to "build", "make", etc.  Logic is included to force a break loop
%    if BreakIn!* = Unix!-TTY!*, just as if a B had been typed to YesP.
% 22-Mar-84 11:23:45 (Brian Beach)
%  Added compiletime load of if-system.
% 26 Jan 1984 0959-PST (Brian Beach)
%  Corrected file name in header.
% 01-Dec-83 14:42:20 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load if-system))

(fluid '(*continuableerror % if true, inside continuable error
         errorform* breaklevel* % nesting level of break loops
         maxbreaklevel* % maximum permitted ...
         *emsgp
	 unix-tty*
	 cursym*
	 ))

% value of 2nd arg to previous errorset
(global '(emsg*))

% gets message from most recent error
(de fatalerror (s)
  (errorprintf "***** Fatal error: %s" s)
  (while t
    (quit))
  nil)

(de rangeerror (object index fn)
  (stderror (bldmsg "Index %r out of range for %p in %p" index object fn)))

(de stderror (message)
  %. Error without number
  (error 99 message))

(de yesp (u)
  (prog (bool x y oldout oldin promptstring*)
        (setq oldin (rds nil))
        (setq oldout (wrs errout*))
        %	TERPRI();
        %	PRIN2L U;
        %	TERPRI();
        %	TERPRI();
        (if_system tops20 % ? in col 1, so batch jobs get killed

                   (setq promptstring* (bldmsg "?%l (Y or N) " u))
                   (setq promptstring* (bldmsg "%l (Y or N) " u)))
   a
        (setq x (read))
        (when (or (setq y (memq x '(y yes))) (memq x '(n no)))
          (go b))

 	% Override exit-on-eof for scripts if BreakIn!* is Unix!-TTY!*.
 	(if_system unix
 	    (when (and (eq x !$eof!$) (eq BreakIn!* Unix!-TTY!*))
		  (setq x 'b )))

        (when (equal x 'b)
          (errorset '(break) nil nil))

        (if_system unix % If read EOF, croak so shell scripts terminate
                   (when (eq x $eof$)
			 (exit-with-status 1)))
        (setq bool t)
        (go a)
   b
        (wrs oldout)
        (rds oldin)
        (setq cursym* '*semicol*)
        (return y)))

(de continuableerror (errnum message errorform*)
  %. maybe fix
  (prog (*continuableerror)
        (setq *continuableerror t)
        (setq emsg* message)
        (return (if (and *break *emsgp (lessp breaklevel* maxbreaklevel*))
                  (progn (errorprintf "***** %l" message)
                         % Don't print number
                         (cond ((null errorform*)
                                (errorprintf "***** Continuable error."))
                               ((lessp (flatsize errorform*) 40)
                                (errorprintf
                                 "***** Continuable error: retry form is %r"
                                 errorform*))
                               (t
                                (errorprintf
                                 "***** Continuable error, retry form is:")
                                (errorprintf "%p" errorform*)))
                         (break))
                  (error errnum message)))))

