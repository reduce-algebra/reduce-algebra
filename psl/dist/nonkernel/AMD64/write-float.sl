%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PXNK:WRITE-FLOAT.SL
% Title:          Format a floating point number into a string.
% Author:         Leigh Stoller
% Created:        25-Oct-86
% Modified:       
% Status:         Experimental
% Mode:           Lisp
% Package:        Kernel
%
 (c) Copyright 1982, University of Utah
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
% 25-Oct-86 (Leigh Stoller)
%  This is a new version that uses sprintf correctly. The old version was so
%  bad it was not worth keeping around.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(floatformat* floatprecision*))

(de setprintprecision (digits-to-print)
  (if (not (fixp digits-to-print))
      (nonintegererror digits-to-print 'setprintprecision))

  (setq floatprecision* digits-to-print)
  (setq floatformat* (bldmsg "%%.%pg" floatprecision*))
  )

(loadtime (setprintprecision 6))    % Initialize to 6 on startup.

(de getprintprecision ()
  floatprecision*)
    

(de writefloat (buffer floatptr)
  (if (eq (wand (current-stack-pointer) 15) 0)
  (uxwritefloat8 (inf buffer) (inf floatptr)
		(strbase (strinf floatformat*)) 4711)
  (uxwritefloat (inf buffer) (inf floatptr)
		(strbase (strinf floatformat*)))))



