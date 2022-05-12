%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:IO.SL
% Description:  Minimal I/O for the kernel.
% Author:       Brian Beach, Hewlett-Packard CRC
% Created:      16-Feb-84
% Modified:     29-Jun-84 12:26:04 (RAM)
% Mode:         Lisp
% Package:      
% Status:       Open Source: BSD License
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
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
% 29-Jun-84 12:22:21 (RAM)
%  Changed console-print-string to make one call to unixputs rather than
%  multiple calls to unixputc.
%  Removed definition of unixputn (it was only there for debugging).
%  Changed binaryopenread to call unixopen rather than fopen.  Unixopen
%  can be extended to expand $names properly, etc, eliminating the need
%  for the HPUX-PATH stuff.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% $Id$

(on fast-integers)

%(fluid '(onewordbuffer))

(de console-print-string (string)
  (unixputs (strbase (mkitem fixnum-tag string))))

%  (let ((upper-bound (strlen (strinf string))))
%  ` (for (from i 0 upper-bound)
%         (do (unixputc (strbyt (strinf string) i)))
%         )))

(de console-print-number (num)
  (unixputn num))

(de console-newline ()
  (unixputc (char lf))
  )

(de binaryopenread (filename)
  (let ((f (unixopen (strbase (mkitem fixnum-tag filename))
		 (strbase (mkitem fixnum-tag "r")))))
        (if (weq f 0)
            (kernel-fatal-error "Couldn't open binary file for input")
            f)))

(de binaryread (filepointer)            % Read one word, 32 bits.
  (getw filepointer)
  )

(de binaryreadblock (filepointer blockbase blocksize) 
  (fread blockbase 4 blocksize filepointer)
  )

(de binaryclose (filepointer) 
  (fclose filepointer)
  )

(off fast-integers)



