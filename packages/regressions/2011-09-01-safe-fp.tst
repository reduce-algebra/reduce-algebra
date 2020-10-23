on rounded;

% In 2011 this tested safe!-fp!-plus etc.

% As of 2020 things have changed and the new model is that safe!-fp!-op
% performs X op Y and if the result is an infinity or a NaN it returns nil
% without generating an exception. So my newer "reference" implementation
% here tried to model that, and is probably exactly the code used with PSL!



lisp;

on echo,comp;
% The procedures here will be compiled, but I switch off all
% compiler messages because those messages are platform dependent
% and so would show up as gratuitous differences between the log files
% on differing machines.

load compiler;
off pwrds;

errs := 0;

maxx := 1.797e+308;

list(!!plumin,
     !!plumax,
     !!timmin,
     !!timmax);

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

for each x in v do
  ll := x . (-x) . ll;

% ll is now a list of critical values

length ll;

fluid '(errs);

symbolic procedure badcase();
  errs := errs + 1;


global '(!!maxfloatq2 !!two511 !!two513);

remprop('!!maxfloatq2, 'constant!?);
remprop('!!two511, 'constant!?);
remprop ('!!two513, 'constant!?);

begin
  scalar r, w;
% I know the numeric value I want expressed in powers of 2, so I compute
% it here building on initial values that are small enough that I can
% be confident that they read in exactly.
  r := 8388608.0;
  w := r*r*r;
  r := r*w*w;
  r := r*r*r;
  r := 8.0*r*r;
% The value I produce here is 2^53-1 times a huge power of 2 and is the
% largest finite IEEE double precision value.
  !!maxfloatq2 := r*(134217728.0*134217728.0-2.0);
  r := 2.0;
  for i := 1:9 do r := r*r;
  !!two511 := r/2.0;
  !!two513 := 2.0*r
end;

put('!!maxfloatq2, 'constant!?, !!maxfloatq2);
put('!!two511, 'constant!?, !!two511);
put('!!two513, 'constant!?, !!two513);

symbolic procedure portable!-fp!-plus(u, v);
% I can only get overflow if u and v have the same sign. If u and
% v are normalised to start with I can only end up with a sub-normal
% number if their signs differ. Note that both +0.0 and -0.0 count as >= 0.0
% and so do not go through the code that checks for underflow.
  if u < 0.0 then
    if v < 0.0 then <<
% I want to see if u+v > would overflow. If u and v are large then I can
% compute u/2 and v/2 with no loss of anything (if say u/2 was sub-normal
% it might lose accuracy here). In this case both operands are negative
% so comparing against half the most negative possible value does the
% checking that I need. It I pass this test it will be safe to perform
% a simple addition.
      if 0.5*u + 0.5*v < -!!maxfloatq2 then nil
      else u + v >>
    else begin
% u and v have different signs, so adding them can not lead to overflow
% but might result in underflow. So do the arithmetic directly and check.
      scalar r;
      r := u + v;
      if r = 0.0 then return r
       else if r < !!minnorm and r > !!minnegnorm then return nil
% As in the CSL case I dislike and would like to remove this next line.
% Note that in the CSL case I only make this extra test if u and v have
% different signs. The calculation performed can never cause an overflow!
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
    if r = 0.0 then return r
     else if r < !!minnorm and r > !!minnegnorm then return nil
    else if u - r*0.001953125 = u then return 0.0
    else return r
  end
  else <<
% Adding two positive values.
    if 0.5*u + 0.5*v > !!maxfloatq2 then nil
    else u + v >>;

symbolic procedure portable!-fp!-times(u, v);
  begin
% Now the real business. I will have essentially three cases, based on
% the magnitude of the numbers.
% (a) numbers are big and I may risk overflow.
% (b) numbers are small and I may risk underflow.
% (c) numbers are such that I have no great risk.
    scalar u1, v1;
    if !*nonegzerotimes and (u = 0.0 or v = 0.0) then return 0.0;
    if u < 0.0 then u1 := -u else u1 := u;
    if v < 0.0 then v1 := -v else v1 := v;
% I now have the absolute values of the operands. I will check for all
% potential bad cases.
    if u1 < !!two511 then
      if v1 < !!two511 then <<
% Here both numbers are fairly small, so I can afford to multiply them
% directly. Since I have filtered out multiplication by zero I can then
% detect (gradual) underflow with a simple comparison.
        if u1*v1 < !!minnorm and u neq 0.0 and v neq 0.0 then return nil >>
      else <<
% Here u is small but v is big. If I divide v by 2^511 it ends up in the
% range 1 to 2^513, and in particular multiplying by u will not overflow.
% Furthermore it can not underflow either because (v/2^511) is at least 1.0.
        if u1*(v1/!!two511) >= !!two513 then return nil >>
    else if v1 < !!two511 then <<
% Here u is large but v is not... so similar arguments apply.
      if (u1/!!two511)*v1 >= !!two513 then return nil >>
    else <<
% Finally both u and v are greater than or equal to 2^511 so overflow is possible.
      if (u1/!!two511)*(v1/!!two511) >= 4.0 then return nil >>;
    return u*v
  end;

symbolic procedure portable!-fp!-quot(u, v);
% The logic for division is essentially the same as that for multiplication.
  if v = 0.0 then nil
  else begin
    scalar u1, v1;
    if !*nonegzerotimes and u = 0.0 then return 0.0;
    if u < 0.0 then u1 := -u else u1 := u;
    if v < 0.0 then v1 := -v else v1 := v;
% I now have the absolute values of the operands.
    if u1 < !!two511 then
      if v1 > 1.0/!!two511 then <<
% Divide a not huge number by a not tiny one, so quotient will not
% overflow, but could underflow.
        if u1/v1 < !!minnorm and u neq 0.0 then return nil >>
      else <<
% Here u is reasonable but v is tiny.
        if u1/(v1*!!two511) >= !!two513 then return nil >>
    else if v1 > 1.0/!!two511 then <<
% Here u is large but v is not too tiny...
      if (u1/!!two511)/v1 >= !!two513 then return nil >>
    else <<
% Finally u is big and v is tiny...
      if (u1/!!two511)/(v1*!!two511) >= 4.0 then return nil >>;
    return u/v;
  end;
    



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


end;
