%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:PRINTF.SL 
% Description:  Formatted print routine 
% Author:       Eric Benson 
% Created:      27 August 1981 
% Modified:     29-Aug-84 10:06:30 (Brian Beach) 
% Package:      Nonkernel 
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
% 20-Jul-84 9:00 (Brian Beach)
%  Added compile time load of TOKEN-DECLS.
%  Removed WARRAYS, WSTRINGS for micro-kernel.
%  Cleaned up PRINTF2.
% 01-Dec-83 14:58:18 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load io-decls token-decls))

(compiletime
  (flag '(printf1 printf2) 'internalfunction))

(fluid '(in* out*))

(fluid '(formatforprintf* lineposition tokenbuffer))

% First, lambda-bind FormatForPrintF!*
(de printf (formatforprintf* a1 a2 a3 a4 a5 a6 a7 a8 a9 a10 a11 a12 a13)
  (printf1 formatforprintf* a1 a2 a3 a4 a5 a6 a7 a8 a9 a10 a11 a12 a13))

% Then, push all the registers on the stack and set up a pointer to them
(lap '((*entry printf1 expr 15)
       (*alloc 0)
       (*Move (reg 2) (indirect (reg sp)))
%       (*push (reg 2))
       (*push (reg 3))
       (*push (reg 4))
       (*push (reg 5))
       (*push (reg 6))
       (*push (reg 7))
       (*push (reg 8))
       (*push (reg 9))
       (*push (reg 10))
       (*push (reg 11))
       (*push (reg 12))
       (*push (reg 13))
       (*push (reg 14))
%       (*push (reg 15))
       (*loc (reg 1) (frame 13))	% load address of frame containing (reg 2), ie 1st arg
       (*call printf2)
       (*exit 13)))


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%                          Formatted print
%
% Format is a string, either in the heap or not, whose characters will be
% written on the currently selected output channel.  The exception to this is
% that when a % is encountered, the following character is interpreted as a
% format character, to decide how to print one of the other arguments.  The
% following format characters are currently supported:
%	%b - blanks; take the next argument as integer and print that many
%		blanks
%	%c - print the next argument as a single character
%	%d - print the next argument as a decimal integer
%       %e - EVALs the next argument for side-effect -- most useful if the
%            thing EVALed does some printing
%	%f - fresh-line, print end-of-line char if not at beginning of line
%	%l - same as %w, except lists are printed without top level parens
%	%n - print end-of-line character
%	%o - print the next argument as an octal integer
%	%p - print the next argument as a Lisp item, using Prin1
%       %r - print the next argument as a Lisp item, using ErrPrin (`FOO')
%	%s - print the next argument as a string
%	%t - tab; take the next argument as an integer and
%		print spaces to that column
%	%w - print the next argument as a Lisp item, using Prin2
%	%x - print the next argument as a hexidecimal integer
%	%% - print a %
%
% If the character is not one of these (either upper or lower case), then an
% error occurs.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime
 (defmacro next-arg ()
   '(prog1 (getmem printfargs)
	   (setf printfargs (loc (wgetv printfargs stackdirection)))
	   )))

% Actual printf, with 1 argument: pointer to array of parameters
(de printf2 (printfargs)
  (prog (uplim i ch upch)
    (setq uplim (strlen (strinf formatforprintf*)))
    (setq i 0)
    (while (wleq i uplim)
      (setq ch (strbyt (strinf formatforprintf*) i))
      (if (wneq ch (char !%))
	(writechar ch)
	(progn
	 (setq i (wplus2 i 1))
	 (setq ch (strbyt (strinf formatforprintf*) i))
	 (setq upch (if (lowercasechar ch)
		      (raisechar ch)
		      ch))
	 (case upch
	   (((char !B))  (spaces (next-arg)))
	   (((char !C))  (writechar (next-arg)))
	   (((char !D))  (writesysinteger (next-arg) 10))
	   (((char !E))  (eval (next-arg)))
	   (((char !F))  (when (wgreaterp (posn) 0)
			  (writechar (char eol))))
	   (((char !L))  (prin2l (next-arg)))
	   (((char !N))  (writechar (char eol)))
	   (((char !O))  (writesysinteger (next-arg) 8))
	   (((char !X))  (writesysinteger (next-arg) 16))
	   (((char !P))  (prin1 (next-arg)))
	   (((char !R))  (errprin (next-arg)))
	   (((char !S))  (writestring (next-arg)))
	   (((char !T))  (tab (next-arg)))
	   (((char !W))  (prin2 (next-arg)))
	   (((char !%)) (writechar (char !%)))
	   (nil
	    (stderror (bldmsg "Unknown character code for PrintF: %r" (mkid ch)))))))
      (setq i (wplus2 i 1)))))

(de errorprintf (format a1 a2 a3 a4)
  % also A5..A14
  (let ((savechannel (wrs errout*)))
    (when (wgreaterp (wgetv lineposition (intinf errout*)) 0)
      (terpri))
    (printf format a1 a2 a3 a4)
    (when (wgreaterp (wgetv lineposition (intinf errout*)) 0)
      (terpri))
    (wrs savechannel)))

(de tostringwritechar (channel ch)
  % shares TokenBuffer                                                     
  (progn (if (wgeq (wgetv tokenbuffer 0) (wdifference maxtokensize 1))
           (progn (setf (wgetv tokenbuffer 0) 80)
                  % truncate to 80 chars                                   
                  (setf (strbyt tokenbuffer 80) (char null))
                  (stderror 
                   (list '"Buffer overflow while constructing error message:"
                         formatforprintf* '"The truncated result was:" 
                         (copystring (mkstr tokenbuffer)))))
           (progn (setf (wgetv tokenbuffer 0) 
                        (wplus2 (wgetv tokenbuffer 0) 1))
                  (setf (strbyt tokenbuffer (wgetv tokenbuffer 0)) ch)))
))

%. Print to string                                                         
(de bldmsg 
  (format arg1 arg2 arg3 arg4 arg5 arg6 arg7 arg8 arg9 arg10 arg11 arg12)
             % arg13)  jpa
  (prog (tempchannel out*)
        (setf (wgetv lineposition 2) 0)
        (setf (wgetv tokenbuffer 0) -1)
        (setq tempchannel out*)
        (setf out* '2)
        (printf format arg1 arg2 arg3 arg4 arg5 arg6 arg7 arg8 arg9 arg10 
                arg11 arg12) % jpa arg13)
        (setf (strbyt tokenbuffer (wplus2 (wgetv tokenbuffer 0) 1)) 
              (char null))
        (setf out* tempchannel)
        (return (copystring tokenbuffer))))

(de errprin (u)
  %. `Prin1 with quotes'
  (progn (writechar (char !`))
         (prin1 u)
         (writechar (char !'))))

(de prin2l (itm)
  %. Prin2 without top-level parens
  (cond ((null itm) nil)
        % NIL is (), print nothing
        ((not (pairp itm)) (prin2 itm))
        (t (progn (while (progn (prin2 (car itm))
                                (setq itm (cdr itm))
                                (pairp itm))
                    (channelwriteblankoreol out*))
                  (when itm
                    (channelwriteblankoreol out*)
                    (prin2 itm))))))

(de channelprintf (out* format a1 a2 a3 a4 a5 a6 a7 a8 a9 a10 a11 a12)
  (printf format a1 a2 a3 a4 a5 a6 a7 a8 a9 a10 a11 a12))

