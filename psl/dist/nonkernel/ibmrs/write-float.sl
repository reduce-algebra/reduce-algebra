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
% (c) Copyright 1986,  University of Utah, all rights reserved.
% 
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
  (uxwritefloat buffer (mkstr floatptr) (strbase floatformat*)))



