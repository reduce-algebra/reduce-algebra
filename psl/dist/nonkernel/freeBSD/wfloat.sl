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
  (uxfloat (mkitem fixnum-tag x) y))

(de *fplus2 (x y z)
  (when (eq (uxplus2 (mkitem fixnum-tag x) (mkitem fixnum-tag y)
		     (mkitem fixnum-tag z)) 0)
	(stderror "Floating point error in fplus2")))

(de *fdifference (x y z)
  (when (eq (uxdifference (mkitem fixnum-tag x) (mkitem fixnum-tag y)
			  (mkitem fixnum-tag z)) 0)
	(stderror "Floating point error in fdifference")))

(de *ftimes2 (x y z)
  (when (eq (uxtimes2 (mkitem fixnum-tag x) (mkitem fixnum-tag y)
		      (mkitem fixnum-tag z)) 0)
	(stderror "Floating point error in ftimes")))

(de *fquotient (x y z)
  (when (eq (uxquotient (mkitem fixnum-tag x) (mkitem fixnum-tag y)
			(mkitem fixnum-tag z)) 0)
	(stderror "Floating point error in fquotient")))

(de *fgreaterp (x y)
  (uxgreaterp (mkitem fixnum-tag x) (mkitem fixnum-tag y) 't 'nil))

(de *flessp (x y)
  (uxlessp (mkitem fixnum-tag x) (mkitem fixnum-tag y) 't 'nil))

(de *wfix (x)
  (uxfix (mkitem fixnum-tag x)))

(de *fassign (x y)
  (uxassign (mkitem fixnum-tag x) (mkitem fixnum-tag y)))

(de *doubletofloat (x y)
  (uxdoubletofloat (mkitem fixnum-tag x) (mkitem fixnum-tag y)))

% These two statements must be at the end of the file because times2, and
% thus *ftimes2, must be defined before it is used.

(loadtime (progn
	    (setq **neg-one** -1.0)
	    (setq **neg-zero** (times2 **neg-one** 0.0))))

(de *floattodouble (x y)
  (uxfloattodouble (mkitem fixnum-tag x) (mkitem fixnum-tag y)))

(de uxsin (r x)
  (when (eq (uuxsin (mkitem fixnum-tag r) (mkitem fixnum-tag x)) 0)
	(stderror "Floating point error in sin")))

(de uxcos (r x)
  (when (eq (uuxcos (mkitem fixnum-tag r) (mkitem fixnum-tag x)) 0)
	(stderror "Floating point error in cos")))

(de uxtan (r x)
  (when (eq(uuxtan (mkitem fixnum-tag r) (mkitem fixnum-tag x)) 0)
	(stderror "Floating point error in tan")))

(de uxasin (r x)
  (when (eq(uuxasin (mkitem fixnum-tag r) (mkitem fixnum-tag x)) 0)
	(stderror "Floating point error in asin")))

(de uxacos (r x)
  (when (eq(uuxacos (mkitem fixnum-tag r) (mkitem fixnum-tag x)) 0)
	(stderror "Floating point error in acos")))

(de uxatan (r x)
  (when (eq(uuxatan (mkitem fixnum-tag r) (mkitem fixnum-tag x)) 0)
	(stderror "Floating point error in atan")))

(de uxsqrt (r x)
  (when (eq(uuxsqrt (mkitem fixnum-tag r) (mkitem fixnum-tag x)) 0)
	(stderror "Floating point error in sqrt")))

(de uxexp (r x)
  (when (eq(uuxexp (mkitem fixnum-tag r) (mkitem fixnum-tag x)) 0)
	(stderror "Floating point error in exp")))

(de uxlog (r x)
  (when (eq(uuxlog (mkitem fixnum-tag r) (mkitem fixnum-tag x)) 0)
	(stderror "Floating point error in log")))

(de uxatan2 (r y x)
  (when (eq(uuxatan2 (mkitem fixnum-tag r) (mkitem fixnum-tag y)(mkitem fixnum-tag x)) 0)
	(stderror "Floating point error in atan2")))


