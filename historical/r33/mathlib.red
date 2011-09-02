MODULE MATHLIB;  % Some useful mathematical functions.

% Authors: W. Galway, M. L. Griss, A. C. Hearn. D. Irish, A. C. Norman,
%          D. Morrison.

% ***** Constants declared as NewNam's *****

% We can't use these long numbers in some Lisps because the reader can't
% handle them (and it would truncate instead of round, anyway).  These
% are here for reference for implementation on other machines.

% put('NumberPi,'NewNam,3.14159265358979324);
% put('NumberPi!/2,'NewNam,1.57079632679489662);
% put('NumberPi!/4,'NewNam,0.785398163397448310);

deflist('((Number2Pi 6.2831853)
          (NumberPi 3.1415927)
          (NumberPi!/2 1.5707963)
          (NumberPi!/4 0.78539816)
          (Number3Pi!/4 2.3561945)
          (Number!-2Pi -6.2831853)
          (Number!-Pi -3.1415927)
          (Number!-Pi!/2 -1.5707963)
          (Number!-Pi!/4 -0.78539816)
          (SqrtTolerance 0.0000001)
          (NumberE 2.718281828)
          (NumberInverseE 0.36787944)
          (NaturalLog2 0.69314718)
          (NaturalLog10 2.3025851)
          (TrigPrecisionLimit 80)),
'newnam);

% ***** Basic Functions *****

symbolic procedure mod(M,N);
   % Returns M modulo N.  Unlike remainder function, it returns
   % positive result in range 0..N-1, even if M is negative.
   % Needs more work for case of negative N.)
   (if result >= 0 then result else result + N)
      where result = remainder(M,N);

symbolic procedure Floor x;
   % Returns the largest integer less than or equal to x
   % (i.e. the "greatest integer" function.)
   % Note the trickiness to compensate for fact that (unlike APL's
   % "FLOOR" function) FIX truncates towards zero.
   if fixp x then x
    else (if x = float n then n else if x >= 0 then n else n-1)
       where n = fix x;

symbolic procedure Ceiling X;
   % Returns the smallest integer greater than or equal to X.
   % Note the trickiness to compensate for fact that (unlike APL's
   % "FLOOR" function) FIX truncates towards zero.
   if fixp X then X
    else (if x = float n then n else if x >= 0 then n+1 else n)
       where n = fix x;

symbolic procedure Round X;
   % Rounds to the closest integer.
   % Kind of sloppy -- it's biased when the digit causing rounding is a
   % five. It's a bit weird with negative arguments, round(-2.5)= -2.
   if fixp X then X else floor(X+0.5);

% ***** Trigonometric Functions *****

% Trig functions are all in radians.  The following few functions may
% be used to convert to/from degrees, or degrees/minutes/seconds.

symbolic procedure DegreesToRadians x;
   x*0.017453292; % 2*pi/360

symbolic procedure RadiansToDegrees x;
   x*57.29578;    % 360/(2*pi)

symbolic procedure RadiansToDMS x;
    % Converts radians to a list of degrees, minutes, and seconds
    % (rounded, not truncated, to the nearest integer).
    begin scalar Degs,Mins;
       x := RadiansToDegrees x;
       Degs := fix x;
       x := 60*(x-Degs);
       Mins := fix x;
       return list(Degs,Mins, Round(60*(x-Mins)))
    end;

symbolic procedure DMStoRadians(Degs,Mins,Sex);
   % Converts degrees, minutes, seconds to radians.
   % DegreesToRadians(Degs+Mins/60.0+Sex/3600.0)
   DegreesToRadians(Degs+Mins*0.016666667+Sex*0.00027777778);

symbolic procedure sin x;
   % Accurate to about 6 decimal places, so long as the argument is
   % of commensurate precision.  This will, of course, NOT be true for
   % large arguments, since they will be coming in with small precision.
   begin scalar neg;
      if minusp x then <<neg := T; x := -x>>;
      if x>TrigPrecisionLimit
        then ErrorPrintF
                "Possible loss of precision in computation of SIN";
      if x>NumberPi then x := x-Number2Pi*fix((x+NumberPi)/Number2Pi);
      if minusp x then <<neg := not neg; x := -x>>;
      if x > NumberPi!/2 then x := NumberPi-x;
      return if neg then -ScaledSine x else ScaledSine x
   end;

symbolic procedure ScaledSine x;
   % assumes its argument is scaled to between 0 and pi/2.
   begin scalar xsqrd;
      xsqrd := x*x;
      return x*(1+xsqrd*(-0.16666667+xsqrd*(0.0083333315
                   +xsqrd*(-0.0001984090
                      +xsqrd*(0.0000027526-xsqrd*0.0000000239)))))
   end;

symbolic procedure cos x;
   % Accurate to about 6 decimal places, so long as the argument is
   % of commensurate precision.  This will, of course, NOT be true for
   % large arguments, since they will be coming in with small precision.
   <<if minusp x then x := - x;
     if x>TrigPrecisionLimit
       then ErrorPrintf
               "Possible loss of precision in computation of COS";
     if x>NumberPi then x := x-Number2Pi*fix((x+NumberPi)/Number2Pi);
     if minusp x then x := -x;
     if x>NumberPi!/2 then -ScaledCosine(NumberPi-x)
      else ScaledCosine x>>;

symbolic procedure ScaledCosine x;
   % Expects its argument to be between 0 and pi/2.
   begin scalar xsqrd;
      xsqrd := x*x;
      return 1+xsqrd*(-0.5+xsqrd*(0.041666642+xsqrd*(-0.0013888397+
                  xsqrd*(0.0000247609-xsqrd*0.0000002605))))
   end;

symbolic procedure tan x;
   % Accurate to about 6 decimal places, so long as the argument is
   % of commensurate precision.  This will, of course, NOT be true for
   % large arguments, since they will be coming in with small precision.
   begin scalar neg;
      if minusp x then <<neg := T; x := -x>>;
      if x>TrigPrecisionLimit
        then ErrorPrintF
                "Possible loss of precision in computation of TAN";
      if x>NumberPi!/2
        then x := x-NumberPi*fix((x+NumberPi!/2)/NumberPi);
      if minusp x then <<neg := not neg; x := -x>>;
      if x<NumberPi!/4 then x := ScaledTangent x
       else x := ScaledCotangent(-(x-numberpi!/2));
      return if neg then -x else x
   end;

symbolic procedure cot x;
   % Accurate to about 6 decimal places, so long as the argument is
   % of commensurate precision.  This will, of course, NOT be true for
   % large arguments, since they will be coming in with small precision.
   begin scalar neg;
     if minusp x then <<neg := T; x := -x>>;
     if x>NumberPi!/2
       then x := x-NumberPi*fix((x+NumberPi!/2)/NumberPi);
     if x>TrigPrecisionLimit
       then ErrorPrintF
               "Possible loss of precision in computation of COT";
     if minusp x then <<neg := not neg; x := -x>>;
     if x<NumberPi!/4 then x := ScaledCotangent x
      else x := ScaledTangent(-(x-numberpi!/2));
     return if neg then -x else x
   end;

symbolic procedure ScaledTangent x;
   % Expects its argument to be between 0 and pi/4.
   (x*(1.0+xsqrd*(0.3333314+xsqrd*(0.1333924
                   +xsqrd*(0.05337406 + xsqrd*(0.024565089
                       +xsqrd*(0.002900525+xsqrd*0.0095168091)))))))
      where xsqrd = x*x;

symbolic procedure ScaledCotangent x;
   % Expects its argument to be between 0 and pi/4.
   ((1.0-xsqrd*(0.33333334+xsqrd*(0.022222029+xsqrd*(0.0021177168 +
              xsqrd*(0.0002078504+xsqrd*0.0000262619)))))/x)
      where xsqrd = x*x;

symbolic procedure sec x; 1.0/cos x;

symbolic procedure csc x; 1.0/sin x;

symbolic procedure sinD x; sin DegreesToRadians x;

symbolic procedure cosD x; cos DegreesToRadians x;

symbolic procedure tanD x; tan DegreesToRadians x;

symbolic procedure cotD x; cot DegreesToRadians x;

symbolic procedure secD x; sec DegreesToRadians x;

symbolic procedure cscD x; csc DegreesToRadians x;

symbolic procedure asin x;
   begin scalar neg;
      if minusp x then <<neg := T; x := -x>>;
      if x>1.0 then stderror list("Argument to ASIN too large:",x);
      return if neg then CheckedArcCosine x - NumberPi!/2
              else NumberPi!/2 - CheckedArcCosine x
   end;

symbolic procedure acos x;
   begin scalar neg;
     if minusp x then <<neg := T; x := -x>>;
     if x>1.0 then stderror list("Argument to ACOS too large:",x);
     return if neg then NumberPi - CheckedArcCosine x
             else CheckedArcCosine x
   end;

symbolic procedure CheckedArcCosine x;
   % Return cosine of a "checked number", assumes its argument is in
   % the range 0 <= x <= 1.
   sqrt(1.0-x)*(1.5707963+x*(-0.2145988+x*(0.088978987+x*(-0.050174305+
           x*(0.030891881+x*(-0.017088126+x*(0.0066700901
                                              -x*(0.0012624911))))))));

symbolic procedure atan x;
   if minusp x
     then if x < -1.0 then Number!-Pi!/2 + CheckedArcTangent(-1.0/x)
           else -CheckedArcTangent(-x)
    else if x>1.0 then NumberPi!/2 - CheckedArcTangent(1.0/x)
    else CheckedArcTangent x;

symbolic procedure acot x;
   if minusp x
     then if x<-1.0 then -CheckedArcTangent(-1.0/x)
           else Number!-Pi!/2 + CheckedArcTangent(-x)
    else if x>1.0 then CheckedArcTangent(1.0/x)
    else NumberPi!/2 - CheckedArcTangent x;

symbolic procedure CheckedArcTangent x;
   (x*(1+xsqrd*(-0.33333145+xsqrd*(0.19993551+xsqrd*(-0.14208899+
           xsqrd*(0.10656264+xsqrd*(-0.07528964+xsqrd*(0.042909614+
             xsqrd*(-0.016165737+xsqrd*0.0028662257)))))))))
      where xsqrd = x*x;

symbolic procedure asec x; acos(1.0/x);

symbolic procedure acsc x; asin(1.0/x);

symbolic procedure asinD x; RadiansToDegrees asin x;

symbolic procedure acosD x; RadiansToDegrees acos x;

symbolic procedure atanD x; RadiansToDegrees atan x;

symbolic procedure acotD x; RadiansToDegrees acot x;

symbolic procedure asecD x; RadiansToDegrees asec x;

symbolic procedure acscD x; RadiansToDegrees acsc x;


% ***** Hyperbolic Functions *****

symbolic procedure sinh x; (exp x - exp(-x))/2.0;

symbolic procedure cosh x; (exp x + exp(-x))/2.0;

symbolic procedure tanh x; sinh x/cosh x;

symbolic procedure csch x; 1/sinh x;

symbolic procedure sech x; 1/cosh x;

symbolic procedure coth x; 1/tanh x;

symbolic procedure asinh x; log(x + sqrt(x**2+1.0));

symbolic procedure acosh x;
   <<if x<0 then x := -x;
     if x<1 then stderror list("Argument to ACOSH too small:",x);
     log(x + sqrt(x**2-1.0))>>;

symbolic procedure atanh x;
   begin scalar neg;
      if x<0 then <<neg := t; x := -x>>;
      if x>=1 then stderror list("Argument to ATANH too large:",x);
      x := log((1.0+x)/(1-x));
      return if neg then -x else x
   end;

symbolic procedure acsch x;
   if x=0 then stderror "0 invalid argument to ACSCH"
    else log(y + sqrt(y**2+1)) where y = 1.0/x;

symbolic procedure asech x;
   <<if x<0 then x := -x;
     if x>1 then stderror list("Argument to ASECH too large:",x);
     log(y + sqrt(y**2-1)) where y = 1.0/x>>;

symbolic procedure acoth x;
   begin scalar neg;
      if x=0 then stderror "0 invalid argument to ACOTH"
       else if x<0 then <<neg := t; x := -x>>;
      if x<=1 then stderror list("Argument to ACOTH too small:",x);
      x := log((x+1.0)/(x-1));
      return if neg then -x else x
   end;


% ***** Roots and Such *****

symbolic procedure sqrt N;
   % Simple Newton-Raphson floating point square root calculator.
   % Not warranted against truncation errors, etc.
   begin integer scale; scalar answer;
      N:=FLOAT N;
      if N<0.0 then stderror list("SQRT given negative argument:",N);
      if zerop N then return N;
      % Scale argument to within 1e-10 to 1e+10;
      scale := 0;
      while N > 1.0E10 do <<scale := scale + 1; N := N * 1.0E-10>>;
      while N < 1.0E-10 do <<scale := scale - 1; N := N * 1.0E10>>;
      answer := if N>2.0 then (N+1)/2
                 else if N<0.5 then 2/(N+1)
                 else N;
      % Here's the heart of the algorithm.
      while abs(answer**2/N - 1.0) > SqrtTolerance do
         answer := 0.5*(answer+N/answer);
      return answer * 10.0**(5*scale)
   end;

% ***** Logs and Exponentials *****

symbolic procedure exp x;
   % Returns the exponential (ie, e**x) of its floatnum argument as
   % a flonum. The argument is scaled to
   % the interval -ln  2 to  0, and a  Taylor series  expansion
   % used (formula 4.2.45 on page 71 of Abramowitz and  Stegun,
   % "Handbook of Mathematical  Functions"). Note that little effort
   % has been expended to minimize truncation errors.
   % On many systems it will be appropriate to define a system-
   % specific EXP routine that does bother about rounding and that
   % understands the precision of the host floating point arithmetic;
   begin scalar N;
     N := ceiling(x / NaturalLog2);
     x := N * NaturalLog2 - x;
     return 2.0**N * (1.0+x*(-0.9999999995+x*(0.4999999206
               +x*(-0.1666653019+x*(0.0416573475+x*(-0.0083013598
                   +x*(0.0013298820+x*(-0.0001413161))))))))
   end;

symbolic procedure log x;
   % See Abramowitz and Stegun, page 69.
   if x<=0.0 then stderror list("LOG given non-positive argument:",x)
    else if x < 1.0 then -log(1.0/x)
    else
    % Find natural log of x > 1;
    begin scalar nextx, ipart;      % ipart is the "integer part" of
                                    % the logarithm.
      ipart := 0;

      % Keep multiplying by 1/e until x is small enough, may want to
      % be more "efficient" if we ever use really big numbers.
      while (nextx := NumberInverseE * x) > 1.0 do
        <<x := nextx; ipart := ipart + 1>>;
      return ipart + if x < 2.0 then CheckedLogarithm x
                      else 2.0 * CheckedLogarithm(sqrt(x))
    end;
 
symbolic procedure CheckedLogarithm x;
% Should have 1 <= x <= 2.  (i.e. x = 1+y  0 <= y <= 1)
   <<x := x-1.0;
     x*(0.99999642+x*(-0.49987412+x*(0.33179903+x*(-0.24073381
        +x*(0.16765407+x*(-0.09532939
            +x*(0.036088494-x*0.0064535442)))))))>>;

symbolic procedure log2 x; log x / NaturalLog2;

symbolic procedure log10 x; log x / NaturalLog10;

symbolic procedure factorial n;   % simple factorial
   if n<0 or not fixp n
     then error(50,list(n,"invalid factorial argument"))
    else begin scalar m;
       m:=1;
       for i:=1:n do m:=m*i;
       return m;
     end;


% Some functions from ALPHA_1 users

symbolic procedure atan2d( y, x );
   radianstodegrees atan2( y, x );

symbolic procedure atan2( y, x );
  <<x := float x;
    y := float y;
    if x = 0.0
      then if y>=0.0 then numberpi!/2 else numberpi+numberpi!/2
     else if x>=0.0 and y>=0.0 then atan(y/x)  % first quadrant.
     else if x<0.0 and y>=0.0 then numberpi - atan(y/-x)
        % second quadrant.
     else if x<0.0 and y<0.0 then numberpi + atan(y/x)
        % third quadrant.
     else number2pi - atan(-y/x)   % fourth quadrant.
   >>;

symbolic procedure transfersign( s, val );
   % transfers the sign of s to val by returning abs(val) if s >= 0,
   % otherwise -abs(val).
   if s >= 0 then abs(val) else -abs(val);

symbolic procedure dmstodegrees(degs,mins,sex);
   % converts degrees, minutes, seconds to degrees
   % degs+mins/60.0+sex/3600.0
   degs+mins*0.016666667+sex*0.00027777778;

symbolic procedure degreestodms x;
   % converts degrees to a list of degrees, minutes, and seconds
   % (all integers, rounded, not truncated).
   begin scalar degs,mins;
      degs := fix x;
      x := 60*(x-degs);
      mins := fix x;
      return list(degs,mins, round(60*(x-mins)))
   end;

endmodule;

end;
