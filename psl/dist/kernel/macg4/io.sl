%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:IO.SL
% Description:  Minimal I/O for the kernel.
% Author:       Brian Beach, Hewlett-Packard CRC
% Created:      16-Feb-84
% Modified:     29-Jun-84 12:26:04 (RAM)
% Mode:         Lisp
% Package:      
% Status:       Experimental (Do Not Distribute)
%
% (c) Copyright 1984, Hewlett-Packard Company, all rights reserved.
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

(on fast-integers)

%(fluid '(onewordbuffer))

(de console-print-string (string)
% (unixputs (strbase (strinf string))))
  (unixputs (strbase  string)))

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
  (let ((f (unixopen (strbase filename) (strbase (kernelstring2string "r")))))
        (if (weq f 0)
            (kernel-fatal-error 
		(kernelstring2string "Couldn't open binary file for input"))
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



