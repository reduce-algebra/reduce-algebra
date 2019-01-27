%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU: MATHLIB.SL 
% Description:  Some useful mathematical functions for PSL 
% Author:       Contributions from Galway, Griss, Irish, Morrison, and others 
% Created:      
% Modified:     02-Dec-83 18:07:29 (Nancy Kendzierski) 
% Mode:         Lisp 
% Package:      Utilities 
% Status:       Open Source: BSD License
% Notes:        
% Compiletime:  
% Runtime:      
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
%  June 23 1991, Herbert Melenk
%    inserted calls for fp operations reusing boxes
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
        (setq x (plus x 0.0)) % now x is float and a fresh box
        (setq xsqrd (floattimes2 x x))
        (return (==iptimes2 x 
                       (==ipplus2r 1.0 
                        (==iptimes2r xsqrd 
                         (==ipplus2r -0.1666666664 
                          (==iptimes2r xsqrd 
                           (==ipplus2r 0.0083333315 
                            (==iptimes2r xsqrd 
                             (==ipplus2r -0.0001984090
                              (==iptimes2r xsqrd 
                               (==ipdifferencer 0.0000027526
                                (floattimes2 xsqrd 0.0000000239))))))))))))))

(de cos (x)
  % Accurate to about 6 decimal places, so long as the argument is         
  % of commensurate precision.  This will, of course, NOT be true for      
  % large arguments, since they will be coming in with small precision.    
  (progn (when (minusp x)
           (setq x (minus x)))
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
        (setq x (plus x 0.0)) % now x is float and a fresh box
        (setq xsqrd (times x x))
        (return (==ipplus2r 1.0  
                      ( ==iptimes2r xsqrd 
                       (==ipplus2r -0.5 
                        (==iptimes2r xsqrd 
                         (==ipplus2r 0.041666642
                          (==iptimes2r xsqrd 
                           (==ipplus2r -0.0013888397
                            (==iptimes2r xsqrd 
                             (==ipdifferencer 0.0000247609
                              (times xsqrd 0.0000002605)))))))))))))

(de tan (x)
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
        (setq x (plus x 0.0)) % now x is float and a fresh box
        (setq xsqrd (floattimes2 x x))
        (return (==iptimes2 x 
                       (==ipplus2r 1.0 
                        (==iptimes2r xsqrd 
                         (==ipplus2r 0.3333314
                          (==iptimes2r xsqrd 
                           (==ipplus2r 0.1333924 
                            (==iptimes2r xsqrd 
                             (==ipplus2r 0.05337406 
                              (==iptimes2r xsqrd 
                               (==ipplus2r 0.024565089 
                                (==iptimes2r xsqrd 
                                 (==ipplus2r 0.002900525
				  (floattimes2 xsqrd 0.0095168091))))))))))))))))

(de scaledcotangent (x)
  % Expects its argument to be between 0 and pi/4.                         
  (prog (xsqrd)
        (setq x (plus x 0.0)) % now x is float and a fresh box
        (setq xsqrd (floattimes2 x x))
        (return (==ipquotient 
                 (==ipdifferencer 1.0 
                  (==iptimes2r xsqrd 
                         (==ipplus2r 0.33333334
                          (==iptimes2r xsqrd 
                           (==ipplus2r 0.022222029
                            (==iptimes2r xsqrd 
                             (==ipplus2r 0.0021177168
                              (==iptimes2r xsqrd 
                               (==ipplus2r 0.0002078504
				(floattimes2 xsqrd 0.0000262619))))))))))
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
                                                                           
  (setq x (float x))
  % 0 <= x <= 1.                                                           
  (==iptimes2 (sqrt (difference 1.0 x)) 
   (==ipplus2r 1.5707963
         (==iptimes2r x 
                (==ipplus2r -0.2145988
                      (==iptimes2r x 
                       (==ipplus2r 0.088978987
                        (==iptimes2r x 
                         (==ipplus2r -0.050174305
                          (==iptimes2r x 
                           (==ipplus2r 0.030891881
                            (==iptimes2r x 
                             (==ipplus2r -0.017088126
                              (==iptimes2r x 
                               (==ipdifferencer 0.0066700901
				(floattimes2 x 0.0012624911))))))))))))))))

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
        (setq x (plus x 0.0))
        (setq xsqrd (times x x))
        (return 
         (==iptimes2r x 
          (==ipplus2r 1.0 
           (==iptimes2r xsqrd 
            (==ipplus2r -0.33333145
                  (==iptimes2r xsqrd 
                         (==ipplus2r 0.19993551
                          (==iptimes2r xsqrd 
                           (==ipplus2r -0.14208899 
                            (==iptimes2r xsqrd 
                             (==ipplus2r 0.10656264
                              (==iptimes2r xsqrd 
                               (==ipplus2r -0.07528964 
                                (==iptimes2r xsqrd 
                                 (==ipplus2r 0.042909614
                                  (==iptimes2r xsqrd 
                                   (==ipplus2r -0.016165737
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
                                                                           
%    Fast SQRT using access to IEEE exponent
%    for initial guess and (partially) unboxed
%    arithmetic for the Newton iterations.

(compiletime
   (define-constant IEEEbias 1023)
)

(compiletime (flag1 'initialsqrt 'internalfunction))
(compiletime (load inum))

(de initialsqrt(x)
   % initial approximation for sqrt: divide exponent by 2
   % sqrt(m*2**e)-> m*2**(e/2)
  (prog(e m ho)
   (setq x (floatplus2 x 0.0))  % new box with same number
      % pick out exponent and divide by 2
   (setq ho (floatHighorder (inf x)))
   (setq e  (wdifference (wand 2#11111111111 (wshift ho -20))
                        IEEEbias))
   (setq e (wplus2 IEEEbias (wshift e -1)))
      % eliminate old exponent
   (setq m (wminus (wshift 2#11111111111 20)))
   (setq ho (wand m ho))
      % insert new exponent
   (setq ho (wor (wshift e 20)))
   (setf (floatHighorder (inf x)) ho)
   (return x) ))

(de sqrt(x)
   % Newton iteration for fixpoint of y**2-x;
   % start with a good initial approximation and
   % then do 4 steps without further reasoning.
   (prog(a)
    (setq x (float x))
    (cond((floatlessp x 0.0) (stderror "sqrt called with negative argument"))
         ((zerop x)(return 0.0)))
    (setq a (initialsqrt x))
    (ifor (from i 1 4 1)
          (do
        % a := a - (a^2 - x)/2a
     (setq a
      (==ipdifference
          a
          (==ipquotient
              (==ipdifference
                 (floattimes2 a a)
                 x)
              (floatplus2 a a) )))) )
    (return a) ))

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
          (==ipplus2r 1.0 
                (==iptimes2r x 
                       (==ipplus2r -0.9999999995
                        (==iptimes2r x 
                         (==ipplus2r 0.4999999206
                          (==iptimes2r x 
                           (==ipplus2r -0.1666653019
                            (==iptimes2r x 
                             (==ipplus2r 0.0416573475 
                              (==iptimes2r x 
                               (==ipplus2r -0.0083013598 
                                (==iptimes2r x 
                                 (==ipplus2r 0.0013298820
				 (floattimes2 x -0.0001413161))))))))))))))))))

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
         (==iptimes2r x 
          (==ipplus2r 0.99999642
                (==iptimes2r x 
                       (==ipplus2r -0.49987412 
                        (==iptimes2r x 
                         (==ipplus2r 0.33179903
                          (==iptimes2r x 
                           (==ipplus2r -0.24073381
                            (==iptimes2r x 
                             (==ipplus2r 0.16765407
                              (==iptimes2r x 
                               (==ipplus2r -0.09532939 
                                (==iptimes2r x 
                                 (==ipdifferencer 0.036088494
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

