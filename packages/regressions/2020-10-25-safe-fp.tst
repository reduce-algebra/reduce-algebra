% test safe!-fp!-plus and friends by comparing the version that Reduce
% provides with a reference implementation here.

% The idea is that safe!-fp!-times(u, v) will multiply u by v and return nil
% either if the result would be an infinity or a NaN or if the result would
% be small enought to be de-normmilised and hence less precise than one
% might naiveley hope. For safe!-fp!-plus there is also a nil result for
% some cases where non-equal values are subtracted such as to lose precision.


off echo;
lisp;

on comp;
% I need to arrange that the compiler does not print messages that would
% be platform-specific. Hence the next 2 lines.
load compiler;
off pwrds;

% I create a list of large and small values to do a first set of tests
% with.

on rounded; % Needed to get !!plumin etc defined.

maxx := 1.797e+308;
ll := v := nil;
for i := 0:20 do <<
   w := expt(1.12345, i);
   v := w . (1.0/w) . v;
   v := (!!plumin*w) . (!!plumin/w) . v;
   if w < maxx/!!plumax then
     v := (!!plumax*w) . (!!plumax/w) . v;
   v := (!!timmin*w) . (!!timmax/w) . v
   >>;

v;

% If a value x is in the list of test values include -x too.

for each x in v do
  ll := x . (-x) . ll;

% ll is now a list of test values

length ll;

fluid '(errs);
errs := 0;

symbolic procedure badcase();
  errs := errs + 1;

global '(!!!!two460 !!!!two512 !!!!two564 !!!!two1023 !!!!minnorm !!!!minnegnorm);

remprop('!!!!two460, 'constant!?);
remprop('!!!!two512, 'constant!?);
remprop('!!!!two564, 'constant!?);
remprop ('!!!!two1023, 'constant!?);

!!!!two460 := 2.0^460;
!!!!two512 := 2.0^512;
!!!!two564 := 2.0^564;
!!!!two1023 := 2.0^1023;
!!!!minnorm := 2.0^(-1022);
!!!!minnegnorm := -!!!!minnorm;

put('!!!!two460, 'constant!?, !!!!two460);
put('!!!!two512, 'constant!?, !!!!two512);
put('!!!!two564, 'constant!?, !!!!two564);
put('!!!!two1023, 'constant!?, !!!!two1023);
put('!!!!minnorm, 'constant!?, !!!!minnorm);
put('!!!!minnegnorm, 'constant!?, !!!!minnegnorm);


% The functions portable!-fp!-xxx are intended to be such that when they
% run they never generated overflows from finite inputs. I will compare
% whatever Reduce does with their output.

symbolic procedure portable!-fp!-plus(u, v);
% I can only get overflow if u and v have the same sign. If u and
% v are normalised to start with I can only end up with a sub-normal
% number if their signs differ. Note that both +0.0 and -0.0 count as >= 0.0
% and so when you add them there will not be a check for underflow.
  if u < 0.0 then
    if v < 0.0 then <<
% I want to see if u+v > would overflow. If u and v are large then I can
% compute u/2 and v/2 with no loss of anything (if say u/2 was sub-normal
% it might lose accuracy here). In this case both operands are negative
% so comparing against half the most negative possible value does the
% checking that I need. It I pass this test it will be safe to perform
% a simple addition.
      if 0.5*u + 0.5*v <= -!!!!two1023 then nil
      else u + v >>
    else begin
% u and v have different signs, so adding them can not lead to overflow
% but might result in underflow. So do the arithmetic directly and check.
      scalar r;
      r := u + v;
      if r = 0.0 then <<
        if !*nonegzerotimes then return 0.0
        else return r >>;
      if r < !!!!minnorm and r > !!!!minnegnorm then return nil
% I dislike and would like to remove this next line.
% This premature underflow to 0.0 just loses accuracy in a way I find
% really disturbing, but I am leaving the behaviour here as it is for
% compatibility with older versions of the code.
      else if u - r*0.001953125 = u then return 0.0
      else return r
    end
  else if v < 0.0 then begin
% A second case where signs differ. When writing this I felt that the
% duplicated code here was ugly but that adjusting the tree of tests to
% have just one copy of this led to worse mess.
    scalar r;
    r := u + v;
    if r = 0.0 then <<
      if !*nonegzerotimes then return 0.0
      else return r >>;
    if r < !!!!minnorm and r > !!!!minnegnorm then return nil
    else if u - r*0.001953125 = u then return 0.0
    else return r
  end
  else <<
% Adding two positive values.
    if 0.5*u + 0.5*v >= !!!!two1023 then nil
    else u + v >>;

symbolic procedure portable!-fp!-times(u, v);
  begin
% I will have essentially four cases, based on the magnitude of the numbers.
% (a) zero values.
% (b) numbers are big and I may risk overflow.
% (c) numbers are small and I may risk underflow.
% (d) numbers are such that I have no great risk.
    scalar u1, v1;
    if u = 0.0 or v = 0.0 then <<
      if !*nonegzerotimes then return 0.0
      else return u*v >>;
% Now the inputs are non-zero. 
    if u < 0.0 then u1 := -u else u1 := u;
    if v < 0.0 then v1 := -v else v1 := v;
% I now have the absolute values of the operands. I will check for all
% potential bad cases.
    if u1 < !!!!two512 then
      if v1 < !!!!two512 then <<
% Here both numbers are fairly small, so I can afford to multiply them
% directly. Since I have filtered out multiplication by zero I can then
% detect (gradual) underflow with a simple comparison.
        if u1*v1 < !!!!minnorm then return nil >>
      else <<
% Here u is small but v is big. If I divide v by 2^512 it ends up in the
% range [1, 2^512), and in particular multiplying by u will not overflow.
% Furthermore it can not underflow either because (v/2^512) is at least 1.0.
        if u1*(v1/!!!!two512) >= !!!!two512 then return nil >>
    else if v1 < !!!!two512 then <<
% Here u is large but v is not... so similar arguments apply.
      if (u1/!!!!two512)*v1 >= !!!!two512 then return nil >>
% The remaining case is u1>=2^212 and v1>=2^512 so overflowe is certain.
    else return nil;
    return u*v
  end;

symbolic procedure portable!-fp!-quot(u, v);
% The logic for division uses the same ideas as those for multiplication.
% However v can be as small as 2^(-(1022+52)) [ie 2^-1074] so division by
% it could lead to overflow sooner than multiplication by a huge but finite
% floating value.
  begin
    scalar u1, v1;
    if v = 0.0 then return nil;    % Result is infinity or NaN
    if u = 0.0 then <<
      if !*nonegzerotimes then return 0.0
      else return u/v >>;
    if u < 0.0 then u1 := -u else u1 := u;
    if v < 0.0 then v1 := -v else v1 := v;
% I now have the absolute values of the operands. I want to detect the
% easier and (probably) more common cases first.
    if u1 < !!!!two512 then
      if v1 > 1.0/!!!!two512 then <<
% Divide a not huge number by a not-so-tiny one, so quotient will not
% overflow. The only issue is whether it will underflow.
        if u1/v1 < !!!!minnorm then return nil >>
      else <<
% Here u is reasonable but v is tiny.
        if u1/(v1*!!!!two564) >= !!!!two460 then return nil >>
    else if v1 > 1.0/!!!!two512 then <<
% Here u is large but v is not too tiny...
      if (u1/!!!!two512)/v1 >= !!!!two512 then return nil >>
    else <<
% Finally u is big and v is tiny...
      if (u1/!!!!two512)/(v1*!!!!two564) >= 2.0^(-52) then return nil >>;
    return u/v;
  end;
    
% Now the code that runs tests.

symbolic procedure tab_to n;
  while posn() < n do prin2 " ";

for each x in ll do
  for each y in ll do <<
     if errs < 20 then <<
        a1 := safe!-fp!-plus(x, y);
        a2 := portable!-fp!-plus(x, y);
        if not eqn(a1, a2) then <<
            terpri();
            prin2t "safe-fp-plus incorrect";
            prin2 "x: "; prin2 x; tab_to 40; prin2t hexfloat1 x;
            prin2 "y: "; prin2 y; tab_to 40; prin2t hexfloat1 y;
            prin2 "new: "; prin2 a1; tab_to 40; prin2t hexfloat1 a1;
            prin2 "ref: "; prin2 a2; tab_to 40; prin2t hexfloat1 a2;
            terpri();
            badcase() >>;
        a1 := safe!-fp!-times(x, y);
        a2 := portable!-fp!-times(x, y);
        if not eqn(a1, a2) then <<
            terpri();
            prin2t "safe-fp-times incorrect";
            prin2 "x: "; prin2 x; tab_to 40; prin2t hexfloat1 x;
            prin2 "y: "; prin2 y; tab_to 40; prin2t hexfloat1 y;
            prin2 "new: "; prin2 a1; tab_to 40; prin2t hexfloat1 a1;
            prin2 "ref: "; prin2 a2; tab_to 40; prin2t hexfloat1 a2;
            terpri();
            badcase() >>;
        a1 := safe!-fp!-quot(x, y);
        a2 := portable!-fp!-quot(x, y);
        if not eqn(a1, a2) then <<
            terpri();
            prin2t "safe-fp-quot incorrect";
            prin2 "x: "; prin2 x; tab_to 40; prin2t hexfloat1 x;
            prin2 "y: "; prin2 y; tab_to 40; prin2t hexfloat1 y;
            prin2 "new: "; prin2 a1; tab_to 40; prin2t hexfloat1 a1;
            prin2 "ref: "; prin2 a2; tab_to 40; prin2t hexfloat1 a2;
            terpri();
            badcase() >> >> >>;



% Now some randomised testing...


% The commented out code here sets a random seed based on the date and
% time of day. For stand-alone testing you should give use_real_random
% a value. That can be done using CSL by putting -Duse_real_random on the
% command line or otherwise by launching Reduce, setting the variable and
% then reading this test file.

if boundp 'use_real_random then
  begin
    scalar seed := 0;
    for each c in explode data!-and!-time() do
      seed := remainder(11213*seed + id2int c, 10000000);
    random_new_seed seed;
  end;

% The following can generate any legal finite floating point value, but
% never a NaN and never and infinity. I can generate denormalised values.
% Its distribution is uniform on exponent values.

symbolic procedure IEEErandom();
  begin
    scalar s, x, m;
    s := zerop remainder(next!-random!-number(), 2);
    x := random 2047;   % Will not generate a NaN or an infinity
    m := random (2^52);
    return (s . x . m);
  end;

% Set the number of test cases. For a regression test that is part of
% the main Reduce test suite this needs to be kept smallish to avoid
% taking too long. But if use_real_random is defined a much larger
% count is set up.

global '(count);

if boundp 'use_real_random then count := 1000000
else count := 10000;


% I have a number of schemes for generating random floating point
% values in various ranges... I generate each as a triple (sign, exponent,
% mantissa).

% This generates random floats in the range about 2^(-500) to 2^500, and
% simple arithmetic on such values can never overflow or fall into the
% range of denormalised values or underflow.

symbolic procedure IEEErandom1();
  begin
    scalar s, x, m;
    s := zerop remainder(next!-random!-number(), 2);
    x := 1023 - 500 + random 1001;
    m := random (2^52);
    return (s . x . m);
  end;

% Values < 1

symbolic procedure IEEErandom2();
  begin
    scalar s, x, m;
    s := zerop remainder(next!-random!-number(), 2);
    x := random 1024;
    m := random (2^52);
    return (s . x . m);
  end;

% Now values that are small and that have only around 28 bits. The purpose
% here is to exercise the round-to-even code by having a noticable (although
% still small) number of products where the exact answer has a value that is
% has a fractional part that is 0.5ULP.

symbolic procedure IEEErandom3();
  begin
    scalar s, x, m;
    s := zerop remainder(next!-random!-number(), 2);
    x := random 1024;
    m := land(random (2^52), 0xffffffe000000);
    return (s . x . m);
  end;

% Values > 1

symbolic procedure IEEErandom4();
  begin
    scalar s, x, m;
    s := zerop remainder(next!-random!-number(), 2);
    x := 1023+random 1024;
    m := random (2^52);
    return (s . x . m);
  end;

% Values all of which are huge.

symbolic procedure IEEErandom4a();
  begin
    scalar s, x, m;
    s := zerop remainder(next!-random!-number(), 2);
    x := 1023+(1024-100) + random 100;
    m := random (2^52);
    return (s . x . m);
  end;

% Convert from a triple to a genuine floating point value.

symbolic procedure IEEE2float v;
  begin
    scalar s:=car v, x:=cadr v, m:=cddr v, r;
% Deal with infinities and NaNs. Not used here but present for completeness.
    if x = 2047 then <<
      if m = 0 then <<
        if s then return 'minus_infinity
        else return 'infinity >>
      else return 'NaN >>;
% Insert the hidden bit.
    if x = 0 then x := 1   % Magic to make denorms behave!
    else m := m + (2^52);
    r := float m;
% As before I could speed this up dramatically by exploiting the binary
% representation of x and having a table of floating point values of
% powers of 2. Or if I has LDEXP.
    while x > 1023+52 do << r := r*2.0; x := x-1 >>;
    while x < 1023+52 do << r := r/2.0; x := x+1 >>;
    if s then r := -r;
    return r;
  end;

% Test multiplication of big values.

begin
  printc "multiplication in range 1 to 2^1024";
  for i := 1:count do
    begin
      scalar a:=IEEErandom4(), b:=IEEErandom4(), c, d, e, f;
      c := IEEE2float a;
      d := IEEE2float b;
      e := portable!-fp!-times(c, d);
      f := safe!-fp!-times(c, d);
      if e neq f then <<
        terpri();
        prin list('failure, a, b, c, d, e, f);
        stop 1 >>;
    end;
  return "Test was passed"
end;

% Test multiplication of reasonably values things.

begin
  printc "multiplication in range 2^-512 to 2^512";
  for i := 1:count do
    begin
      scalar a:=IEEErandom1(), b:=IEEErandom1(), c, d, e, f;
      c := IEEE2float a;
      d := IEEE2float b;
      e := portable!-fp!-times(c, d);
      f := safe!-fp!-times(c, d);
      if e neq f then <<
        terpri();
        prin list('failure, a, b, c, d, e, f);
        stop 1 >>;
    end;
  return "Test was passed"
end;

% Test multiplication where denorms and underflow are possible.

begin
  printc "multiplication in range 2^-1024 to 2^0";
  for i := 1:count do
    begin
      scalar a:=IEEErandom2(), b:=IEEErandom2(), c, d, e, f;
      c := IEEE2float a;
      d := IEEE2float b;
      e := portable!-fp!-times(c, d);
      f := safe!-fp!-times(c, d);
      if e neq f then <<
        terpri();
        prin list('failure, a, b, c, d, e, f);
        stop 1 >>;
    end;
  return "Test was passed"
end;


% Cases where the round-to-even situation might be exercised.

begin
  printc "multiplication with limited number of bits in inputs";
  for i := 1:count do
    begin
      scalar a:=IEEErandom3(), b:=IEEErandom3(), c, d, e, f;
      c := IEEE2float a;
      d := IEEE2float b;
      e := portable!-fp!-times(c, d);
      f := safe!-fp!-times(c, d);
      if e neq f then <<
        terpri();
        prin list('failure, a, b, c, d, e, f);
        stop 1 >>;
    end;
  return "Test was passed"
end;

% Test division such that the result will often be huge

begin
  printc "division with many oveflows";
  for i := 1:count do
    begin
      scalar a:=IEEErandom4(), b:=IEEErandom2(), c, d, e, f;
      c := IEEE2float a;
      d := IEEE2float b;
      e := portable!-fp!-quot(c, d);
      f := safe!-fp!-quot(c, d);
      if e neq f then <<
        terpri();
        prin list('failure, a, b, c, d, e, f);
        stop 1 >>;
    end;
  return "Test was passed"
end;

% Test division of reasonably values things.

begin
  printc "division easy cases";
  for i := 1:count do
    begin
      scalar a:=IEEErandom1(), b:=IEEErandom1(), c, d, e, f;
      c := IEEE2float a;
      d := IEEE2float b;
      e := portable!-fp!-quot(c, d);
      f := safe!-fp!-quot(c, d);
      if e neq f then <<
        terpri();
        prin list('failure, a, b, c, d, e, f);
        stop 1 >>;
    end;
  return "Test was passed"
end;

% Test division where denorms and underflow are possible.

begin
  printc "division when underflow plausible";
  for i := 1:count do
    begin
      scalar a:=IEEErandom2(), b:=IEEErandom4(), c, d, e, f;
      c := IEEE2float a;
      d := IEEE2float b;
      e := portable!-fp!-quot(c, d);
      f := safe!-fp!-quot(c, d);
      if e neq f then <<
        terpri();
        prin list('failure, a, b, c, d, e, f);
        stop 1 >>;
    end;
  return "Test was passed"
end;


% Cases where the round-to-even situation might be exercised.

begin
  printc "division with limited bits in inputs";
  for i := 1:count do
    begin
      scalar a:=IEEErandom3(), b:=IEEErandom3(), c, d, e, f;
      c := IEEE2float a;
      d := IEEE2float b;
      e := portable!-fp!-quot(c, d);
      f := safe!-fp!-quot(c, d);
      if e neq f then <<
        terpri();
        prin list('failure, a, b, c, d, e, f);
        stop 1 >>;
    end;
  return "Test was passed"
end;

% Test addition of big values.

begin
  printc "addition in easy cases";
  for i := 1:count do
    begin
      scalar a:=IEEErandom4a(), b:=IEEErandom4a(), c, d, e, f;
      c := IEEE2float a;
      d := IEEE2float b;
      e := portable!-fp!-plus(c, d);
      f := safe!-fp!-plus(c, d);
      if e neq f then <<
        terpri();
        prin list('failure, a, b, c, d, e, f);
        stop 1 >>;
    end;
  return "Test was passed"
end;

% Test addition of reasonably values things.

begin
  printc "addition in easy cases";
  for i := 1:count do
    begin
      scalar a:=IEEErandom1(), b:=IEEErandom1(), c, d, e, f;
      c := IEEE2float a;
      d := IEEE2float b;
      e := portable!-fp!-plus(c, d);
      f := safe!-fp!-plus(c, d);
      if e neq f then <<
        terpri();
        prin list('failure, a, b, c, d, e, f);
        stop 1 >>;
    end;
  return "Test was passed"
end;

% Test addition where denorms and underflow are possible. Well it will
% not be at all common here!

begin
  printc "addition with underflow possible";
  for i := 1:count do
    begin
      scalar a:=IEEErandom2(), b:=IEEErandom2(), c, d, e, f;
      c := IEEE2float a;
      d := IEEE2float b;
      e := portable!-fp!-plus(c, d);
      f := safe!-fp!-plus(c, d);
      if e neq f then <<
        terpri();
        prin list('failure, a, b, c, d, e, f);
        stop 1 >>;
    end;
  return "Test was passed"
end;


% Cases where the two inputs each have a limited number of set bits.

begin
  printc "addition few bits in each input";
  for i := 1:count do
    begin
      scalar a:=IEEErandom3(), b:=IEEErandom3(), c, d, e, f;
      c := IEEE2float a;
      d := IEEE2float b;
      e := portable!-fp!-plus(c, d);
      f := safe!-fp!-plus(c, d);
      if e neq f then <<
        terpri();
        prin list('failure, a, b, c, d, e, f);
        stop 1 >>;
    end;
  return "Test was passed"
end;


end;
