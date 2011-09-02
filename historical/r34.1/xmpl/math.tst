% Test of Math Package.

% Author: Stanley L. Kameny <stan%valley.uucp@rand.org>.

% Copyright (c) 1987, 1988, 1989, 1991 Stanley L. Kameny.
% All Rights Reserved.

%*********************************************************************
%**
%**  This math package will compute the floating point values of  **
%**  the usual elementary functions, namely:                      **
%**     sin     asin     sind    asind     sinh    asinh          **
%**     cos     acos     cosd    acosd     cosh    acosh          **
%**     tan     atan     tand    atand     tanh    atanh          **
%**     cot     acot     cotd    acotd     coth    acoth          **
%**     sec     asec     secd    asecd     sech    asech          **
%**     csc     acsc     cscd    acscd     csch    acsch          **
%**             atan2            atan2d                           **
%**     exp     ln       sqrt                                     **
%**     expt    log      cbrt                                     **
%**     logb    hypot                                             **
%**     log10   floor                                             **
%**             ceiling                                           **
%**             round                                             **
%**                                                               **
%**  All functions are computed to the accuracy of the floating-  **
%**  point precision of the system set up at the time.            **
%**                                                               **
%*********************************************************************
%**  File #1===Trig Function Tests===
%**  Trig functions are tested in both degrees and radians modes.
%*********************************************************************

symbolic;

math!!label;

symbolic procedure terpr(i,j); if remainder(i,j)=0 then terpri()$

% #1: sind**2+cosd**2 test: ideal answers 1.0 for all args.

  for i:=0:45 do <<write "  ",i,"->",sind float i**2+cosd float i**2;
                       terpr(i,4)>>;

% #2: quadrant test of sind, cosd: proper answers + +,+ -,- -,- +.

begin scalar a;
    a:= sind 45.0;
    for i:= 0.0:3.0 do
       <<write " ",sind(i*90+45)/a," ", cosd (i*90+45)/a;terpri()>>
  end$

% #3: scaling test: all values should be 1 exactly.

begin scalar a; a:= cosd 60.0;
%  for i:= -10.0:10.0 do write fix(cosd(60+i*360)/a)," "
   for i:= -10.0:10.0 do write round(cosd(60+i*360)/a)," "
 end$

% #4: test of radians -> degrees evaluation: ideal values 1.0.

array a(6)$

begin
   for i:=1:6 do  a(i):=sind(15.0*i);
   for i:=1:6 do <<write sin(pii2*i/6.0)/a(i),"  "; terpr(i,3)>>
 end$

% #5: test of tand*cotd: ideal values 1.0.

begin
   for i:=5 step 5 until 85 do
      <<write tand float i*cotd float i,"  "; terpr(i,25)>>;
   terpri()
 end$

% #6: test of secd**2-tand**2: ideal values 1.0.

begin
   for i:=5 step 5 until 85 do
      <<write secd float i**2-tand float i**2,"  "; terpr(i,25)>>
 end$

% #7: test of cscd**2-cotd**2: ideal values 1.0.

begin
   for i:=5 step 5 until 85 do
      <<write cscd float i**2-cotd float i**2,"  "; terpr(i,25)>>
 end$

% #8: test of asind+acosd: ideal values 1.0.

begin write "sind and cosd"; terpri();
   for i:=-10:10 do
      <<write (asind(0.1*i)+acosd(0.1*i))/90,"  "; terpr(i,5)>>;
   write "sin and cos";terpri();
   for i:=-10:10 do
      <<write (acos(0.1*i)+asin(0.1*i))/pii2,"  "; terpr(i,5)>>
 end$

% #9: test of atand+acotd: ideal values 1.0.

begin scalar x; write "tand, atand and acotd"; terpri();
   for i:=-80 step 10 until 80 do
   <<x:=tand float i; write (atand x+acotd x)/90,"  "; terpr(i,50)>>;
     terpri();
   write "tan, atan and acot";terpri();
   for i:=-80 step 10 until 80 do
      <<x:= tan (pii2*i/90.0); write (atan x+acot x)/pii2,"  ";
     terpr(i,50)>>
 end$

% #10: test of atand tand: ideal values i for i:=-9:89.

begin
   for i:=-9:89 do
      <<write " ",i,"->",if i=0 then 1.0 else atand tand float i;
        terpr(i,4)>>
 end$

% #11: test of acot cotd: ideal values 10*i for i:=1:17.

begin
   for i:=10 step 10 until 170 do
   <<write " ",i,"->",acotd cotd i; terpr(i,40)>>; terpri();terpri() end$

% #12: test of asind sind: ideal values 10*i for i:=-9:9.

begin
   for i:=-90 step 10 until 90 do
      <<write " ",i,"->",asind sind float i; terpr(i,40)>>
 end$

% #13: test of acosd cosd: ideal values 10*i for i:=1:18.

begin
   for i:=10 step 10 until 180 do
      <<write " ",i,"->",acosd cosd float i; terpr(i,40)>>
 end$

% #14: test of acscd cscd: ideal values 10*i for i:=-9:9, except
%       error for i=0.

begin
   for i:=-90 step 10 until 90 do
      <<write " ",i,"->",if i=0 then "error" else acscd cscd float i;
        terpr(i,40)>>
 end$

% #15: test of asecd secd: ideal values 10*i for i :=0:18. except
%       error for i=9.

begin
   for i:=0 step 10 until 180 do
      <<write" ",i,"->",if i=90 then "error" else asecd secd float i;
        terpr(i,40)>>
 end$

%*********************************************************************
%**  ===Exp,Log,Sqrt,Cbrt, and Expt  Function tests===
%*********************************************************************

% #16: test of properties of exp function: ideal results 1.0.

array b(5)$

begin scalar x; x:=0;
   write "multiplicative property";terpri();
   for i:=0:5 do b(i):=1+i/6.0; for i:=0:5 do for j:=i:5 do
      <<write "  ",exp (b(i)+b(j))/exp(b(i))/exp(b(j));
        terpr(x:=x+1,5)>>
 end$

% #17: various properties of exp: ideal results 1.0.

begin write "inverse property"$ terpri()$
   for i:=1:5 do write "  ",exp(b(i))*exp(-b(i));terpri();
   write "squares"; terpri();
      for i:=-10:10 do
         <<write "  ",sqrt(exp(0.2*i))/exp(0.1*i); terpr(i,5)>>;
   write "cubes"; terpri();
      for i:=-10:10 do
         <<write "  ",cbrt(exp(0.3*i))/exp(0.1*i); terpr(i,5)>>
 end$

% #18: test of log exp: ideal results 1.0.

begin for i:=-5:5 do
   <<write if i=0 then "0/0" else (log exp float i)/i,"  "; terpr(i,5)>>
 end$

% #19: test of log10 expt(10,i): ideal results 1.0.

begin scalar i; write "small values i:=-5:5"; terpri();
   for j:=-5:5 do
      <<write if j neq 0 then log10 float expt(10,j)/j else "zero","  ";
        terpr(j,5)>>;
   write "large i=2**j where j:=0:6"; terpri();
   for j:=0:5 do
      <<write (log10 float expt(10,2**j))/2**j,"  "; terpr(j,5)>>;
        terpri();
        write "noninteger values of i=j/10.0 where j:=1:20";terpri();
        for j:=1:20 do
            <<i:=j/10.0; write (log10 float expt(10,i))/i,"  ";
              terpr(j,5)>>
 end$

% #20: test of properties of expt(x,i)*(expt(x,-i). ideal result 1.0.

begin integer j;
   for x:=2:6 do for i:=2:6 do
      <<write expt(x,i)*expt(x,-i),"  "; terpr(j:=j+1,5)>>
 end$

% #21: test of expt(-x,i)/expt(x,i) for fractional i.

begin integer j,k; write "odd numerator. ideal result -1.0"; terpri();
   for i:=1:10 do
      <<k:=(2*i-1.0)/(8*i+1); write expt(-8,k)/expt(8,k),"  ";
        terpr(j:=j+1,5)>>;
   write "even numerator. ideal result 1.0"; terpri();
   for i:=1:10 do
      <<k:=(2.0*i)/(8*i+1); write expt(-8,k)/expt(8,k),"  ";
        terpr(j:=j+1,5)>>
 end$

% #22: test of properties of ln or log or logb:
%      inverse argument: ideal result -1.0.

begin integer x;
   for i:=2:5 do for j:= 2:10 do
      <<x:=x+1; write logb(float i,float j)/logb(float i,1.0/j),"  ";
        terpr(x,5)>>
 end$

% #23: test of log(a*b) = log a+log b: ideal result 1.0.

begin integer x;
   for i:=1:5 do for j:=i:5 do
      <<write log (i*j*0.01)/(log (i*0.1)+log(j*0.1)),"  ";
        terpr(x:=x+1,5)>>
 end$

% #24:test of sqrt x*sqrt x/x for x:=5i*(5i/3)**i where i:=1:20
%     (test values strictly arbitrary): ideal results 1.0.

begin scalar x,s;
   for i:=1:20 do
      <<x:= 5.0*i;s:=sqrt(x:=x*(expt(x/3,i))); write s*s/x,"  ";
        terpr(i,5)>>
 end$

% #25: test of cbrt x**3/x for x:=5i*(5i/3)**i where i:=-9:10
%      (test values strictly arbitrary):ideal results 1.0.

begin scalar x,s;
   for i:=-9:10 do
      <<x:= 5.0*i; if i neq 0 then s:= cbrt(x:=x*(expt(x/3,i)));
        write if i=0 then 1 else s*s*s/x,"  "; terpr(i,5)>>
 end$

%*********************************************************************
%**  ===Hyperbolic Function Tests===
%*********************************************************************

% #26: test of sinh x+ cosh x= exp x: ideal results 1.0.

begin scalar x;
   for i:=1:10 do
      <<x:=ln float i$ write (sinh x+cosh x)/exp x,"  "$ terpr(i,5)>>
 end$

% #27: test of cosh x-sinh x= exp(-x): ideal results 1.0.

begin scalar x;
   for i:=1:10 do
      <<x:=ln float i$ write(cosh x-sinh x)*exp x,"  "$ terpr(i,5)>>
 end$

% #28: test of (cosh x)**2-(sinh x)**2: ideal results 1.0.

begin scalar x$
   for i:=1:10 do
      <<x:=ln float i$write(cosh x)**2-(sinh x)**2,"  "; terpr(i,5)>>
 end$

% #29: test of tanh*cosh/sinh: ideal results 1.0.

begin scalar x;
   for i:=1:20 do
      <<x:=ln(i*0.1);
        write if i=10 then 1 else tanh x*cosh x/sinh x,"  ";
        terpr(i,5)>>
 end$

% #30: test of tanh*coth: ideal results 1.0.

begin scalar x;
   for i:=1:20 do
      <<x:=ln(i*0.1); write if i=10 then 1 else tanh x*coth x,"  ";
        terpr(i,5)>>
 end$

% #31: test of sech*cosh: ideal results 1.0.

begin scalar x;
   for i:=1:20 do
      <<x:=ln(i*0.1); write sech x*cosh x,"  "; terpr(i,5)>>
 end$

% #32: test of csch*sinh: ideal results 1.0.

begin scalar x;
   for i:=1:20 do
      <<x:=ln(i*0.1);  write if i=10 then 1 else csch x*sinh x,"  ";
        terpr(i,5)>>
 end$

% #33: test of asinh sinh: ideal results 1.0.

begin scalar x; for i:=1:20 do
   <<x:=ln(i*0.1); write if i=10 then 1 else asinh sinh x/x,"  ";
     terpr(i,5)>>
 end$

% #34: test of acosh cosh: ideal results 1.0.  However, acosh x
%      loses accuracy as x -> 1 since d/dx cosh x -> 0.

begin scalar x;
   for i:=1:20 do
      <<x:=ln(1+i*0.05); write acosh cosh x/x,"  "; terpr(i,5)>>
 end$

% #35: test of cosh acosh:ideal results 1.0.

begin scalar x;
   for i:=1:50 do
      <<x:=1+i/25.0; write (cosh acosh x)/x,"  "; terpr(i,5)>>
 end$

% #36: test of atanh tanh: ideal results 1.0.

begin scalar x;
   for i:=1:20 do
      <<x:=ln(i*0.1); write if i=10 then 1 else (atanh tanh x)/x,"  ";
        terpr(i,5)>>
 end$

% #37: test of acoth coth: ideal results 1.0.

begin scalar x;
   for i:=1:20 do
      <<x:=ln(i*0.1); write if i=10 then 1 else (acoth coth x)/x,"  ";
        terpr(i,5)>>
 end$

% #38: test of asech sech: ideal results 1.0.  However, asech x
%      loses accuracy as x -> 1 since d/dx sech x -> 0.

begin scalar x;
   for i:=1:20 do
      <<x:=ln(1+i*0.05); write (asech sech x)/x,"  "; terpr(i,5)>>
 end$

% #39: test of acsch csch: ideal results 1.0.

begin scalar x;
   for i:=1:20 do
      <<x:=ln(i*0.1); write if i=10 then 1 else (acsch csch x)/x,"  ";
        terpr(i,5)>>
 end$

% End of Test.

end;
