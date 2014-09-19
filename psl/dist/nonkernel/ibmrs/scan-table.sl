%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PVNK:SCAN-TABLE.SL
% Title:          Lisp character table for UNIX (Vax and HPUX200)
% Author:         Eric Benson
% Created:        27 November 1981
% Modified:       27-Feb-84 16:47:38 (RAM)
% Status:         Experimental
% Mode:           Lisp
% Package:        Kernel
%
% (c) Copyright 1983,  Hewlett-Packard Company, all rights reserved.
% Copyright (c) 1981 Eric Benson
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 17-Jul-84 8:00 (Brian Beach)
%  EOF character no longer set at startuptime, set at load time.
% 27-Feb-84 16:47:08 (RAM)
%  Changed File and Title entries in header.
% 2-Dec-83  16:00:00 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(lispscantable* currentscantable*))

(setq lispscantable*
      '[17 10 10 10 11 10 10 10 10 17 17 10 17 17 10 10 10 10 10 10 10 10
        10 10 10 10 10 10 10 10 10 10 17 14 15 10 10 12 10 11 11 11 10 19
        10 18 20 10 0 1 2 3 4 5 6 7 8 9 10 10 10 10 10 10 10 10 10 10 10
        10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10
        11 16 11 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10
        10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 lispdiphthong])

(setq currentscantable* lispscantable*)

(put 'eof 'charconst (char (cntrl d)))

