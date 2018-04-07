%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU: MATHLIB.SL 
% Description:  Some useful mathematical functions for PSL 
% Author:       Contributions from Galway, Griss, Irish, Morrison, and others 
% Created:      
% Modified:     02-Dec-83 18:07:29 (Nancy Kendzierski) 
% Mode:         Lisp 
% Package:      Utilities 
% Status:        Open Source: BSD License
% Notes:        
% Compiletime:  
% Runtime:      
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
%  Mar 11 1986, Russ Fish
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Most of these routines not very heavily tested.                          
%
% Should these names be changed so that they all begin with an F or some   
% other distinguishing mark?  Are they in conflict with anything?  Or should
% we wait until we have packages?                                          
% Consider using Sasaki's BigFloat package -- it has all this and more, to 
% arbitrary precision.  The only drawback is speed.                        
% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load useful))

%***************** Constants previously declared as NewNam's *****************
(fluid '(number2pi numberpi numberpi!/2 numberpi!/4 number3pi!/4
	 number!-2pi number!-pi number!-pi!/2 number!-pi!/4 number!-3pi!/4
	 numbere numberinversee naturallog2 naturallog10
	 sqrttolerance trigprecisionlimit))

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
(setq numberinversee 0.367879441171442321596)	% 1/e
(setq naturallog2 0.6931471805599453094)
(setq naturallog10 2.302585092994045684)

(setq sqrttolerance 1.00000E-007)
(setq trigprecisionlimit 80)

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
  (times x 0.0174532925199432957694))		% 2*pi/360

(de radianstodegrees (x)
  (times x 57.2957795130823208761))		% 360/(2*pi)

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
  % Accurate to about 6 decimal places, so long as the argument is         
  % of commensurate precision.  This will, of course, NOT be true for      
  % large arguments, since they will be coming in with small precision.    
  (prog (neg)
        (when (minusp x)
          (setq neg t)
          (setq x (minus x)))
        (when (greaterp x trigprecisionlimit)
          (errorprintf "Possible loss of precision in computation of SIN"))
        (when (greaterp x numberpi)
          (setq x 
                (difference x 
                 (times number2pi 
                        (fix (quotient (plus x numberpi) number2pi))))))
        (when (minusp x)
          (setq neg (not neg))
          (setq x (minus x)))
        (when (greaterp x numberpi!/2)
          (setq x (difference numberpi x)))
        (return (if neg
                  (minus (scaledsine x))
                  (scaledsine x)))))

(de scaledsine (x)
  % assumes its argument is scaled to between 0 and pi/2.                  
  (prog (xsqrd)
        (setq xsqrd (times x x))
        (return (times x 
                       (plus 1 
                        (times xsqrd 
                         (plus -0.1666666664 
                          (times xsqrd 
                           (plus 0.0083333315 
                            (times xsqrd 
                             (plus -0.0001984090
                              (times xsqrd 
                               (difference 0.0000027526
                                (times xsqrd 0.0000000239))))))))))))))

(de cos (x)
  % Accurate to about 6 decimal places, so long as the argument is         
  % of commensurate precision.  This will, of course, NOT be true for      
  % large arguments, since they will be coming in with small precision.    
  (progn (when (minusp x)
           (setq x (minus x)))
         (when (greaterp x trigprecisionlimit)
           (errorprintf "Possible loss of precision in computation of COS"))
         (when (greaterp x numberpi)
           (setq x 
                 (difference x 
                  (times number2pi 
                         (fix (quotient (plus x numberpi) number2pi))))))
         (when (minusp x)
           (setq x (minus x)))
         (if (greaterp x numberpi!/2)
           (minus (scaledcosine (difference numberpi x)))
           (scaledcosine x))))

(de scaledcosine (x)
  % Expects its argument to be between 0 and pi/2.                         
  (prog (xsqrd)
        (setq xsqrd (times x x))
        (return (plus 1 
                      (times xsqrd 
                       (plus -0.5 
                        (times xsqrd 
                         (plus 0.041666642
                          (times xsqrd 
                           (plus -0.0013888397
                            (times xsqrd 
                             (difference 0.0000247609
                              (times xsqrd 0.0000002605)))))))))))))

(de tan (x)
  % Accurate to about 6 decimal places, so long as the argument is         
  % of commensurate precision.  This will, of course, NOT be true for      
  % large arguments, since they will be coming in with small precision.    
  (prog (neg)
        (when (minusp x)
          (setq neg t)
          (setq x (minus x)))
        (when (greaterp x trigprecisionlimit)
          (errorprintf "Possible loss of precision in computation of TAN"))
        (when (greaterp x numberpi!/2)
          (setq x 
                (difference x 
                 (times numberpi 
                        (fix (quotient (plus x numberpi!/2) numberpi))))))
        (when (minusp x)
          (setq neg (not neg))
          (setq x (minus x)))
        (if (lessp x numberpi!/4)
          (setq x (scaledtangent x))
          (setq x (scaledcotangent (minus (difference x numberpi!/2)))))
        (return (if neg
                  (minus x)
                  x))))

(de cot (x)
  % Accurate to about 6 decimal places, so long as the argument is         
  % of commensurate precision.  This will, of course, NOT be true for      
  % large arguments, since they will be coming in with small precision.    
  (prog (neg)
        (when (minusp x)
          (setq neg t)
          (setq x (minus x)))
        (when (greaterp x numberpi!/2)
          (setq x 
                (difference x 
                 (times numberpi 
                        (fix (quotient (plus x numberpi!/2) numberpi))))))
        (when (greaterp x trigprecisionlimit)
          (errorprintf "Possible loss of precision in computation of COT"))
        (when (minusp x)
          (setq neg (not neg))
          (setq x (minus x)))
        (if (lessp x numberpi!/4)
          (setq x (scaledcotangent x))
          (setq x (scaledtangent (minus (difference x numberpi!/2)))))
        (return (if neg
                  (minus x)
                  x))))

(de scaledtangent (x)
  % Expects its argument to be between 0 and pi/4.                         
  (prog (xsqrd)
        (setq xsqrd (times x x))
        (return (times x 
                       (plus 1.0 
                        (times xsqrd 
                         (plus 0.3333314
                          (times xsqrd 
                           (plus 0.1333924 
                            (times xsqrd 
                             (plus 0.05337406 
                              (times xsqrd 
                               (plus 0.024565089 
                                (times xsqrd 
                                 (plus 0.002900525
				  (times xsqrd 0.0095168091))))))))))))))))

(de scaledcotangent (x)
  % Expects its argument to be between 0 and pi/4.                         
  (prog (xsqrd)
        (setq xsqrd (times x x))
        (return (quotient 
                 (difference 1.0 
                  (times xsqrd 
                         (plus 0.33333334
                          (times xsqrd 
                           (plus 0.022222029
                            (times xsqrd 
                             (plus 0.0021177168
                              (times xsqrd 
                               (plus 0.0002078504
				(times xsqrd 0.0000262619))))))))))
                 x))))

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

(de asin (x)
  (prog (neg)
        (when (minusp x)
          (setq neg t)
          (setq x (minus x)))
        (when (greaterp x 1.0)
          (stderror (list "Argument to ASIN too large:" x)))
        (return (if neg
                  (difference (checkedarccosine x) numberpi!/2)
                  (difference numberpi!/2 (checkedarccosine x))))))

(de acos (x)
  (prog (neg)
        (when (minusp x)
          (setq neg t)
          (setq x (minus x)))
        (when (greaterp x 1.0)
          (stderror (list "Argument to ACOS too large:" x)))
        (return (if neg
                  (difference numberpi (checkedarccosine x))
                  (checkedarccosine x)))))

(de checkedarccosine (x)
  % Return cosine of a "checked number", assumes its argument is in the range
                                                                           
  % 0 <= x <= 1.                                                           
  (times (sqrt (difference 1.0 x)) 
   (plus 1.5707963
         (times x 
                (plus -0.2145988
                      (times x 
                       (plus 0.088978987
                        (times x 
                         (plus -0.050174305
                          (times x 
                           (plus 0.030891881
                            (times x 
                             (plus -0.017088126
                              (times x 
                               (difference 0.0066700901
				(times x 0.0012624911))))))))))))))))

(de atan (x)
  (cond ((minusp x) (if (lessp x -1.0)
           (plus number!-pi!/2 (checkedarctangent (quotient -1.0 x)))
           (minus (checkedarctangent (minus x)))))
        ((greaterp x 1.0) 
         (difference numberpi!/2 (checkedarctangent (quotient 1.0 x))))
        (t (checkedarctangent x))))

(de acot (x)
  (cond ((minusp x) (if (lessp x -1.0)
           (minus (checkedarctangent (quotient -1.0 x)))
           (plus number!-pi!/2 (checkedarctangent (minus x)))))
        ((greaterp x 1.0) (checkedarctangent (quotient 1.0 x)))
        (t (difference numberpi!/2 (checkedarctangent x)))))

(de checkedarctangent (x)
  (prog (xsqrd)
        (setq xsqrd (times x x))
        (return 
         (times x 
          (plus 1 
           (times xsqrd 
            (plus -0.33333145
                  (times xsqrd 
                         (plus 0.19993551
                          (times xsqrd 
                           (plus -0.14208899 
                            (times xsqrd 
                             (plus 0.10656264
                              (times xsqrd 
                               (plus -0.07528964 
                                (times xsqrd 
                                 (plus 0.042909614
                                  (times xsqrd 
                                   (plus -0.016165737
				    (times xsqrd 0.0028662257))))))))))))))))))))

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
                                                                           
(de sqrt (n)
  % Simple Newton-Raphson floating point square root calculator.           
  % Not waranted against truncation errors, etc.                           
  (prog (answer scale)
        (setq n (float n))
        (when (lessp n 0.00000E+000)
          (stderror (list "SQRT given negative argument:" n)))
        (when (zerop n)
          (return n))
        % Scale argument to within 1e-10 to 1E+10;                         
        (setq scale 0)
        (while (greaterp n 1.00000E+010)
          (setq scale (plus scale 1))
          (setq n (times n 1.00000E-010)))
        (while (lessp n 1.00000E-010)
          (setq scale (difference scale 1))
          (setq n (times n 1.00000E+010)))
        (setq answer 
              (cond ((greaterp n 2.0) (quotient (plus n 1) 2))
                    ((lessp n 0.5) (quotient 2 (plus n 1)))
                    (t n)))
        % Here's the heart of the algorithm.                               
        (while (greaterp (abs 
                          (difference (quotient (expt answer 2) n) 1.0))
                         sqrttolerance)
          (setq answer (times 0.5 (plus answer (quotient n answer)))))
        (return (times answer (expt 10.0 (times 5 scale))))))

%******************** Logs and Exponentials **********************************
                                                                           
(de exp (x)
  % Returns the exponential (ie, e**x) of its floatnum argument as         
  % a flonum. The argument is scaled to                                    
  % the interval -ln  2 to  0, and a  Taylor series  expansion             
  % used (formula 4.2.45 on page 71 of Abramowitz and  Stegun,             
  % "Handbook of Mathematical  Functions").                                
  (prog (n)
        (setq n (ceiling (quotient x naturallog2)))
        (setq x (difference (times n naturallog2) x))
        (return 
         (times (expt 2.0 n) 
          (plus 1.0 
                (times x 
                       (plus -0.9999999995
                        (times x 
                         (plus 0.4999999206
                          (times x 
                           (plus -0.1666653019
                            (times x 
                             (plus 0.0416573475 
                              (times x 
                               (plus -0.0083013598 
                                (times x (plus 0.0013298820
				 (times x -0.0001413161))))))))))))))))))

(de log (x)
  % See Abramowitz and Stegun, page 69.                                    
  (cond ((leq x 0.00000E+000) 
         (stderror (list "LOG given non-positive argument:" x)))
        ((lessp x 1.0) (minus (log (quotient 1.0 x))))
        (t % Find natural log of x > 1;                                     
           (prog (nextx ipart)
                 % ipart is the "integer part" of the                      
                 % logarithm.                                              
                 (setq ipart 0)
                 % Keep multiplying by 1/e until x is small enough, may want
                 % to be more "efficient" if we ever use really big numbers.
                 (while (greaterp (setq nextx (times numberinversee x)) 
                         1.0)
                   (setq x nextx)
                   (setq ipart (plus ipart 1))
                   nil)
                 (return (plus ipart (if (lessp x 2.0)
                            (checkedlogarithm x)
                            (times 2.0 (checkedlogarithm (sqrt x))))))))))

(de checkedlogarithm (x)
  % Should have 1 <= x <= 2.  (i.e. x = 1+y  0 <= y <= 1)                  
  (progn (setq x (difference x 1.0))
         (times x 
          (plus 0.99999642
                (times x 
                       (plus -0.49987412 
                        (times x 
                         (plus 0.33179903
                          (times x 
                           (plus -0.24073381
                            (times x 
                             (plus 0.16765407
                              (times x 
                               (plus -0.09532939 
                                (times x 
                                 (difference 0.036088494
				  (times x 0.0064535442)))))))))))))))))

(de log2 (x)
  (quotient (log x) naturallog2))

(de log10 (x)
  (quotient (log x) naturallog10))

%********************* Random Number Generator *******************************
                                                                           
% The declarations below  constitute a linear,  congruential               
% random number generator (see  Knuth, "The Art of  Computer               
% Programming: Volume 2: Seminumerical Algorithms", pp9-24).               
% With the given  constants it  has a period  of 392931  and               
% potency  6.    To   have  deterministic   behaviour,   set               
% RANDOMSEED.                                                              
%                                                                          
% Constants are:        6   2                                              
%    modulus: 392931 = 3 * 7 * 11                                          
%    multiplier: 232 = 3 * 7 * 11 + 1                                      
%    increment: 65537 is prime                                             
%                                                                          
% Would benefit from being recoded in SysLisp, when full word integers should
% be used with "automatic" modular arithmetic (see Knuth).  Perhaps we should
% have a longer period version?                                            
% By E. Benson, W. Galway and M. Griss                                     
(fluid '(randomseed randommodulus))

(setq randommodulus 392931)

(setq randomseed (remainder (time) randommodulus))

(de next!-random!-number ()
  % Returns a pseudo-random number between 0 and RandomModulus-1 (inclusive).
                                                                           
  (setq randomseed 
        (remainder (plus (times 232 randomseed) 65537) randommodulus)))

(de random (n)
  % Return a pseudo-random number uniformly selected from the range 0..N-1.
  % NOTE that this used to be called RandomMod(N).  Needs to be made more  
  % compatible with Common LISP's random?                                  
  (fix (quotient (times (float n) (next!-random!-number)) randommodulus)))

(de factorial (n)
  % Simple factorial                                                       
  (prog (m)
        (setq m 1)
        (for (from i 1 n 1) (do (setq m (times m i))))
        (return m)))

% Some functions from ALPHA_1 users                                        
(de atan2d (y x)
  (radianstodegrees (atan2 y x)))

(de atan2 (y x)
  (setq x (float x))
  (setq y (float y))
  (cond ((equal x 0.00000E+000) % Y axis.
	 (if (geq y 0.00000E+000)
           numberpi!/2
           (plus numberpi numberpi!/2)))
        ((and (geq x 0.00000E+000) (geq y 0.00000E+000)) % First quadrant.  
         (atan (quotient y x)))
        ((and (lessp x 0.00000E+000) (geq y 0.00000E+000)) % Second quadrant.
         (difference numberpi (atan (quotient y (minus x)))))
        ((and (lessp x 0.00000E+000) (lessp y 0.00000E+000)) % Third quadrant.
         (plus numberpi (atan (quotient y x))))
        (t % Fourth quadrant.                                               
           (difference number2pi (atan (quotient (minus y) x))))))

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

