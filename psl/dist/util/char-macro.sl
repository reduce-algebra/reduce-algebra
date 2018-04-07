%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:CHAR-MACRO.SL 
% Description:  Character constant macro 
% Author:       Eric Benson 
% Created:      10 August 1981 
% Modified:     6 May 1984 1656-PDT (Nancy Kendzierski) 
% Package:      
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
% 6 May 1984 1607-PDT (Nancy Kendzierski)
%  Changed file name, since moved out of kernel.  Added compiletime loads
%  to allow separate compilation in useful package.  Changed #\!0 to 48,
%  since #\ not yet available.
% 27 Jan 1984 0914-PST (Brian Beach)
%  Corrected file name in header.
% 20 Dec 1983 1706-PST (Nancy Kendzierski)
%  Added header.
% 1 Feb 1983 1355-PST  (Cris Perdue)
%  pk:char.red merged with the version in USEFUL.  Some symbolic names
%  for characters removed (not needed, I hope).
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load backquote read1macros))

(dm Char (U)		%. Character constant macro
  (DoChar (cadr U)))

% Table driven char macro expander
(de DoChar (u)
  (cond
    ((idp u) (or
	       (get u 'CharConst)
	       ((lambda (n) (cond ((lessp n 128) n))) (id2int u))
	       (CharError u)))
    ((pairp u) % Here's the real change -- let users add "functions"
      ((lambda (fn)
	 (cond
	   (fn (apply fn (list (dochar (cadr u)))))
	   (t (CharError u))))
       (cond ((idp (car u)) (get (car u) 'char-prefix-function)))))
    ((and (fixp u) (geq u 0) (leq u 9)) (plus u 48))  % 48 = (char 0)
    (t (CharError u))))

(deflist
  `((lower ,(function (lambda(x) (lor x 2#100000))))
    (quote ,(function (lambda(x) x)))
    (control ,(function (lambda(x) (land x 2#11111))))
    (cntrl ,(function (lambda(x) (land x 2#11111))))
    (meta ,(function (lambda(x) (lor x 2#10000000)))))
  'char-prefix-function)

(de CharError (u)
  (ErrorPrintF "*** Unknown character constant: %r" u)
  0)

(DefList '((NULL 0)
	   (BELL 7)
	   (BACKSPACE 8)
	   (TAB 8#11)
	   (LF 8#12)
	   % (RETURN 8#12)	% RETURN is LF: it's end-of-line.  Out! /csp
	   (EOL 8#12)
	   (FF 8#14)
	   (CR 8#15)
	   (ESC 27)
	   (ESCAPE 27)
	   (BLANK 32)
	   (SPACE 32)
	   (RUB 8#177)
	   (RUBOUT 8#177)
	   (DEL 8#177)
	   (DELETE 8#177)
	   ) 'CharConst)

% End of file.
