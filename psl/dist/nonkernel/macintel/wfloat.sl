%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:WFLOAT.SL
% Description:  Interface to foreign floating point functions.             
% Author:       RAM, HP/FSD                                                
% Created:      27-Feb-84                                                  
% Modified:     29-Oct-84 09:06:40 (Vicki O'Day)
% Mode:         Lisp                                                       
% Package:                                                                 
% Status:       Experimental (Do Not Distribute)                           
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions
%
% 04-Apr-87 (Leigh Stoller)
%  Added support for 68020 IEEE negitive zero test. See $pnk/arithmetic.sl.
% 29-Oct-86 (Leigh Stoller)
%  Removed definition of writefloat. It has been returned to write-float.sl.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(**neg-zero** **neg-one**))

(off echo)

(de *wfloat (x y)
  (uxfloat x y))

(de *fplus2 (x y z)
  (uxplus2 x y z))

(de *fdifference (x y z)
  (uxdifference x y z))

(de *ftimes2 (x y z)
  (uxtimes2 x y z))

(de *fquotient (x y z)
  (uxquotient x y z))

(de *fgreaterp (x y)
  (uxgreaterp x y 't 'nil))

(de *flessp (x y)
  (uxlessp x y 't 'nil))

(de *wfix (x)
  (uxfix x))

(de *fassign (x y)
  (uxassign x y))

(de *doubletofloat (x y)
  (uxdoubletofloat x y))

% These two statements must be at the end of the file because times2, and
% thus *ftimes2, must be defined before it is used.

(loadtime (progn
	    (setq **neg-one** -1.0)
	    (setq **neg-zero** (times2 **neg-one** 0.0))))

% For DCM                                                                  
(de *floattodouble (x y)
  (uxfloattodouble x y))

% For DCM                                                                  
(on echo)


