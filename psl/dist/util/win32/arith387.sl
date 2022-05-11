%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:arith387.sl  for Intel 386 /387
% Description:  Generic arithmetic: 387 supplementum
% Author:        
% Created:      14-May 1990 
% Modified:     
% Mode:         Lisp 
% Package:      Utilities 
% Status:       Open Source: BSD License
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
% 05-03-1992 (HM)
% version with using round-to-nearest mode for arithmetic operations
%
% 27-nov-1991 (HM)
% moved to masked coprocessor mode: exceptions are tested by investigating
% the result exponent (IEEE convention).
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  $Id$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% the functions are mapped to the corresponding Cmacros,
% which then are expanded to coprocessor instructions
%
% This module can be loaded to a PSL arithmetic which is
% compiled avoiding the coprocessor instructions.

(compiletime (flag '(ftestresult) 'internalfunction))

(fluid '(fcontrolword** fcontrolwordadr** fcontrolwordn** fcontrolwordadrn**))

(setq fcontrolword** 16#0f7f)  % 387 mask: truncate, all exceptions masked
(setq fcontrolwordadr**        % address of mask
	(plus2 symval (times2 4 (id2int 'fcontrolword**))))

(setq fcontrolwordn** 16#037f)  % 387 mask: round nearest, all exceptions masked
(setq fcontrolwordadrn**        % address of mask
	(plus2 symval (times2 4 (id2int 'fcontrolwordn**))))


(compiletime (progn
   (put 'clear387 'opencode 
	     '((*move ($fluid fcontrolwordadr**) (reg 5))
	       (fldcw (displacement (reg 5) 0))
	       ))
   (put 'clear387n 'opencode 
	     '((*move ($fluid fcontrolwordadrn**) (reg 5))
	       (fldcw (displacement (reg 5) 0))
	       ))

   (define-constant IEEEbias 1023)
   (define-constant IEEEmask 2047)
   (ds floathighword (x) (floathighorder (wdifference  x 4)))
   (ds floatlowword (x) (floatloworder (wdifference  x 4)))
   (ds IEEEexpt(u) (wdifference (wand IEEEmask 
				     (wshift (floatHighword u) -20))
						 IEEEbias))
   (ds *testNan(x y)
	(when (weq IEEEmask (wand IEEEmask 
				  (wshift (getmem (wplus2 4 x)) -20)))   
	      (ftsignal y)))
   (define-constant ZEROexp (minus IEEEbias))
   
))

%  (fluid '(*arith387*))
%  (setq *arith387* t)
%  (*freset)

(de ftsignal(u) 
   (stderror (bldmsg "Floating point exception in %w" u)))

(off r2i)
 
(de *wfloat (x y) 
	(clear387n)
	(*wfloat x y)
	(*testNan x "int-float-conversion"))

(de *fplus2 (x y z) 
	(clear387n)
	(*fplus2 x y z)
	(*testNan x "float-plus"))

(de *fdifference (x y z)
	(clear387n)
	(*fdifference x y z)
	(*testNan x "float-difference"))

(de *ftimes2 (x y z)
	(clear387n)  
	(*ftimes2 x y z)
	(*testnan x "float-times"))
 
(de *fquotient (x y z)  
	(clear387n)
	(*fquotient x y z)
	(*testNan x "float-quotient"))
 
% as the Cmacro is intelligent enough, we omit the T and NIL parameters
 
(de *fgreaterp (x y) 
	(clear387n)
	(*fgreaterp x y ))
 
(de *flessp (x y)
	(clear387n) 
	(*flessp x y ))
 
(de *wfix (f)
	(clear387) 
	(*wfix f))

% (re)set for the 387 coprocessor status:
%  clear exception flag
%  set rounding mode to "towards zero"
%  set interrupt mask to zerodiv + overflow + invalid

(on r2i)

(lap '((*entry uxsin expr 1)
       (*move ($fluid fcontrolwordadr**) (reg 5))
       (fldcw (displacement (reg 5) 0))
       (*move (displacement (reg 1) 0) (reg 3))
       (*move (displacement (reg 2) 0) (reg 3))
       (fld (displacement (reg 2) 0))
       (fsin)
       (fstp (displacement (reg 1) 0))
       (*linke 0 ftestresult expr 1)))


(lap '((*entry uxcos expr 1)
       (*move ($fluid fcontrolwordadr**) (reg 5))
       (fldcw (displacement (reg 5) 0))
       (*move (displacement (reg 1) 0) (reg 3))
       (*move (displacement (reg 2) 0) (reg 3))
       (fld (displacement (reg 2) 0))
       (fcos)
       (fstp (displacement (reg 1) 0))
       (*linke 0 ftestresult expr 1)))


(lap '((*entry uxtan expr 1)
       (*move ($fluid fcontrolwordadr**) (reg 5))
       (fldcw (displacement (reg 5) 0))
       (*move (displacement (reg 1) 0) (reg 3))
       (*move (displacement (reg 2) 0) (reg 3))
       (fld (displacement (reg 2) 0))
       (fptan)
       (fstp (displacement (reg 1) 0))   
       (fstp (displacement (reg 1) 0))
       (*linke 0 ftestresult expr 1)))


(compiletime (flag '(uxxatan) 'internalentry))

(de uxatan(u v) (uxxatan u v (floatbase(fltinf 1.0))))  % for unix compatibility

(lap '((*entry uxxatan expr 1)
       (*move ($fluid fcontrolwordadr**) (reg 5))
       (fldcw (displacement (reg 5) 0))
       (fld (displacement (reg 2) 0))  % the atan argument
       (fld (displacement (reg 3) 0))  % should be a one
       (fpatan)
       (fstp (displacement (reg 1) 0))
       (*linke 0 ftestresult expr 1)))


(lap '((*entry uuxexp expr 1)
       (*move ($fluid fcontrolwordadr**) (reg 5))
       (fldcw (displacement (reg 5) 0))
       (*move (displacement (reg 1) 0) (reg 3))
       (*move (displacement (reg 2) 0) (reg 3))
       (fld (displacement (reg 2) 0))
       (fldl2e)
       (fmulp)
       (f2xm1)
       (fld1)
       (faddp)
       (fstp (displacement (reg 1) 0))
       (*linke 0 ftestresult expr 1)))

(lap '((*entry uxlog expr 1)
       (*move ($fluid fcontrolwordadr**) (reg 5))
       (fldcw (displacement (reg 5) 0))
       (*move (displacement (reg 1) 0) (reg 3))
       (*move (displacement (reg 2) 0) (reg 3))
       (Fldln2)
       (fld (displacement (reg 2) 0))
       (fyl2x)
       (fstp (displacement (reg 1) 0))
       (*linke 0 ftestresult expr 1)))

(lap '((*entry uxsqrt expr 1)
       (*move ($fluid fcontrolwordadr**) (reg 5))
       (fldcw (displacement (reg 5) 0))
       (*move (displacement (reg 1) 0) (reg 3))
       (*move (displacement (reg 2) 0) (reg 3))
       (fld (displacement (reg 2) 0))
       (fsqrt)
       (fstp (displacement (reg 1) 0))
       (*linke 0 ftestresult expr 1)))

(de ftestresult(x) (*testNan x "elem. function"))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         $pu/fast-math.sl 
% Description:  Some useful mathematical functions for PSL 
% Author:       Contributions from Galway, Griss, Irish, Morrison, and others 
% Created:      
% Modified:     Wed Jan  7 08:16:45 1987 (Russ Fish)
% Mode:         Lisp 
% Package:      Utilities 
% Status:       Open Source: BSD License
% Notes:        
% Compiletime:  
% Runtime:      
%
% (c) Copyright 1987, University of Utah, all rights reserved.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% Tue Oct 20 18:23:35 1987 (Jim Cobb)
%  Added mathlib-style argument range checking.
% Wed Jan  7 08:17:05 1987 (Russ Fish)
%  Converted mathlib.sl to fast-math.sl, using C math external functions.
%  Also added if_system for VAX to copyd external- routines to the names
%  actually used in the functions.
% Mar 11 1986, Russ Fish
%    More precise definitions of floating point constants now work.
% 9 Jan 1985 1716-PST (Cris Perdue)
%  Installed new definition of MOD with compiletime load of
%  useful to support it.  Old definition was buggy.
% 02-Dec-83 18:07:29 (Nancy Kendzierski)
%   Translated from Rlisp to Lisp.
% 02-Dec-83 15:54:03  Nancy Kendzierski
%   Changed 'newnam stuff to setq's of fluids, since 'newnam is an rlisp-only
%   hack.
% 01-Dec-83 19:21:50  Nancy Kendzierski
%   Changed numbers to correct round-off problem w/un-rlisp.  Since this was
%   done by hand, the process was prone to error.  I don't know if I got them
%   all correct.
% 1 July 1983, Martin Griss                                               
%   LPRIM replaced by ERRORPRINTF so works from BARE-PSL                  
% MATHLIB.RED, 16-Dec-82 21:56:52, Edit by GALWAY                         
%   Various fixes and enhancements too numerous for me to remember.        
%   Includes fixes in SQRT function, modifications of RANDOM and other     
%   functions to bring them more in line with Common Lisp, addition of MOD 
%   and FLOOR.                                                             
% <PSL.UTIL>MATHLIB.RED.13, 13-Sep-82 08:49:52, Edit by BENSON            
%   Bug in EXP, changed 2**N to 2.0**N                                      
% <PSL.UTIL>MATHLIB.RED.12,  2-Sep-82 09:22:19, Edit by BENSON            
%   Changed all calls in REDERR to calls on STDERROR                        
% <PSL.UTIL>MATHLIB.RED.2, 17-Jan-82 15:48:21, Edit by GRISS              
%   changed for PSL                                                         
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Most of these routines not very heavily tested.                          
%
% Should these names be changed so that they all begin with an F or some   
% other distinguishing mark?  Are they in conflict with anything?  Or should
% we wait until we have packages?                                          
% Consider using Sasaki's BigFloat package -- it has all this and more, to 
% arbitrary precision.  The only drawback is speed.                        
% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load useful if-system))

%***************** Constants previously declared as NewNam's *****************
(fluid '(number2pi numberpi numberpi!/2 numberpi!/4 number3pi!/4
	 number!-2pi number!-pi number!-pi!/2 number!-pi!/4 number!-3pi!/4
	 numbere numberinversee naturallog2 naturallog10))

(setq number2pi 6.2831853071795864770)
(setq numberpi 3.1415926535897932385)
(setq numberpi!/2 1.57079632679489661925)
(setq numberpi!/4 0.785398163397448309625)
(setq number3pi!/4 2.356194490192344928875)

% It's probably a mistake to have two definitions, with and without dashes...
(setq number!-2pi 6.2831853071795864770)
(setq number!-pi 3.1415926535897932385)
(setq number!-pi!/2 1.57079632679489661925)
(setq number!-pi!/4 0.785398163397448309625)
(setq number!-3pi!/4 2.356194490192344928875)

(setq numbere 2.71828182845904523536)
(setq numberinversee 0.367879441171442321596)   % 1/e
(setq naturallog2 0.6931471805599453094)
(setq naturallog10 2.302585092994045684)

%% Do this becuase the Vax external functions have "external-" tacked
%%  on the front.
		    
%********************* Basic functions ***************************************
									   
% Mathematically, mod(x,m) should be x-m*floor(x/m)
(de mod (x m)
  (let* ((pair (divide x m))
	 (q (car pair))
	 (r (cdr pair)))
    % Quotient in PSL division is always truncated toward 0.  We
    % adjust Q to be the "floor" of the true quotient.
    (if (and (lessp q 0) (not (equal r 0)))
      (setq q (sub1 q)))
    (difference x (times m q))))

(de floor (x)
  % Returns the largest integer less than or equal to X.  (I.e. the "greatest
  % integer" function.)                                                    
  (if (fixp x)
    x
    (prog (n)
	  (setq n (fix x))
	  % Note the trickiness to compensate for fact that (unlike APL's
	  % "FLOOR" function) FIX truncates towards zero.
	  (return (cond ((equal x (float n)) n)
			((geq x 0) n)
			(t (difference n 1)))))))

(de ceiling (x)
  % Returns the smallest integer greater than or equal to X.               
  (if (fixp x)
    x
    (prog (n)
	  (setq n (fix x))
	  % Note the trickiness to compensate for fact that (unlike APL's
	  % "FLOOR" function) FIX truncates towards zero.
	  (return (cond ((equal x (float n)) n)
			((greaterp x 0) (plus n 1))
			(t n))))))

(de round (x)
  % Rounds to the closest integer.                                         
  % Kind of sloppy -- it's biased when the digit causing rounding is a five,
									   
  % it's a bit weird with negative arguments, round(-2.5)= -2.             
  (if (fixp x)
    x
    (floor (plus x 0.5))))

%***************** Trigonometric Functions ***********************************
									   
% Trig functions are all in radians.  The following few functions may be used
									   
% to convert to/from degrees, or degrees/minutes/seconds.                  
(de degreestoradians (x)
  (times x 0.0174532925199432957694))           % 2*pi/360

(de radianstodegrees (x)
  (times x 57.2957795130823208761))             % 360/(2*pi)

% 360/(2*pi)                                                               
(de radianstodms (x)
  % Converts radians to a list of degrees, minutes, and seconds (rounded, not
									   
  % truncated, to the nearest integer).                                    
  (prog (degs mins)
	(setq x (radianstodegrees x))
	(setq degs (fix x))
	(setq x (times 60 (difference x degs)))
	(setq mins (fix x))
	(return (list degs mins (round (times 60 (difference x mins)))))))

(de dmstoradians (degs mins sex)
  % Converts degrees, minutes, seconds to radians.                         
  (degreestoradians
   (plus degs (quotient mins 60.0) (quotient sex 3600.0))))

(de sin (x)
  (setq x (float x))
  (prog (result)
	(setq result (gtfltn))
	(uxsin (floatbase result) (floatbase (fltinf x)))
	(return (mkfltn result))))

(de cos (x)
  (setq x (float x))
  (prog (result)
	(setq result (gtfltn))
	(uxcos (floatbase result) (floatbase (fltinf x)))
	(return (mkfltn result))))

(de tan (x)
  (quotient (sin x) (cos x)))

(de cot (x)
  (quotient (cos x) (sin x)))

(de sec (x)
  (quotient 1.0 (cos x)))

(de csc (x)
  (quotient 1.0 (sin x)))

(de sind (x)
  (sin (degreestoradians x)))

(de cosd (x)
  (cos (degreestoradians x)))

(de tand (x)
  (tan (degreestoradians x)))

(de cotd (x)
  (cot (degreestoradians x)))

(de secd (x)
  (sec (degreestoradians x)))

(de cscd (x)
  (csc (degreestoradians x)))

(de atan (x)
  (setq x (float x))
  (prog (result)
	(setq result (gtfltn))
     %  (uxatan (floatbase result) (floatbase (fltinf x)) (floatbase(fltinf 1.0)))
	(uxatan (floatbase result) (floatbase (fltinf x)))
	(return (mkfltn result))))

(de acot (x)
  (cond ((minusp x) (if (lessp x -1.0)
	   (minus (atan (quotient -1.0 x)))
	   (plus number!-pi!/2 (atan (minus x)))))
	((greaterp x 1.0) (atan (quotient 1.0 x)))
	(t (difference numberpi!/2 (atan x)))))

(de asec (x)
  (acos (quotient 1.0 x)))

(de acsc (x)
  (asin (quotient 1.0 x)))

(de asind (x)
  (radianstodegrees (asin x)))

(de acosd (x)
  (radianstodegrees (acos x)))

(de atand (x)
  (radianstodegrees (atan x)))

(de acotd (x)
  (radianstodegrees (acot x)))

(de asecd (x)
  (radianstodegrees (asec x)))

(de acscd (x)
  (radianstodegrees (acsc x)))

%****************** Roots and such *******************************************
									   
(de sqrt (x)
  (prog (result)
	(when (lessp x 0.00000E+000)
	  (stderror (list "SQRT given negative argument:" x)))
	(setq result (gtfltn))
	(uxsqrt (floatbase result) (floatbase (fltinf (float x))))
	(return (mkfltn result))))

%******************** Logs and Exponentials **********************************
									   
(de exp (x)
  % Returns the exponential (ie, e**x) of its floatnum argument as
  % a flonum. The argument is scaled to the interval -ln  2 to  0
  (prog (n result)
	(setq n (ceiling (quotient x naturallog2)))
	(setq x (difference x (times n naturallog2)))
	(setq result (gtfltn))
	(uuxexp (floatbase result) (floatbase (fltinf (float x))))
	(return
	 (times2 (expt 2.0 n) (mkfltn result)))))

(de log (x)
  (prog (result)
	(when (leq x 0.00000E+000)
	  (stderror (list "LOG given non-positive argument:" x)))
	(setq result (gtfltn))
	(uxlog (floatbase result) (floatbase (fltinf (float x))))
	(return (mkfltn result))))

(de log2 (x)
  (quotient (log x) naturallog2))

(de log10 (x)
  (quotient (log x) naturallog10))

(de transfersign (s val)
  % Transfers the sign of S to Val by returning abs(Val) if S >= 0,        
  % otherwise -abs(Val).                                                   
  (if (geq s 0)
    (abs val)
    (minus (abs val))))

(de dmstodegrees (degs mins sex)
  % Converts degrees, minutes, seconds to degrees                          
  (plus degs (quotient mins 60.0) (quotient sex 3600.0)))

(de degreestodms (x)
  % Converts degrees to a list of degrees, minutes, and seconds (all integers,
  % rounded, not truncated).                                               
  (prog (degs mins)
	(setq degs (fix x))
	(setq x (times 60 (difference x degs)))
	(setq mins (fix x))
	(return (list degs mins (round (times 60 (difference x mins)))))))

