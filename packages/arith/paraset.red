module paraset;   % Parameter determining module.

% Author: Stanley L. Kameny.

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


% Last change date: 23 June 1993.

% Paraset.red determines the parameters !!nfpd, !!nbfpd, and !!maxbflexp
% for floating point numbers.  !!nfpd, !!nbfpd, and !!maxbflexp are
% computed at load, but !!maxbflexp may have to be fixed up at run time
% if !!flexperr is true.
% [March 2015] also compute !!minnorm the smallest normalised floating
% point number. This will mostly be relevant for IEEE arithmetic and will
% end up as just the smallest non-zero number if subnorms are not in use.
% Provide (more or less) portable definitions of tests for infinity, NaN and
% subnorms... with the one for infinity being cheaper than the use of
% explode.

imports errorp, errorset!*, neq, roundconstants;

exports !!mfefix, find!!nbfpd, find!!nfpd, infinityp;

global '(!!nfpd !!nbfpd !!!~xx !!yy !!maxbflexp !!flexperr !!plumax
         !!epsqrt !!flint !!flbint !!floatbits);

flag('(!!nfpd !!nbfpd !!maxflexp),'share);

symbolic procedure find!!nfpd;
   begin scalar x,y,z;integer i; x:=y:=9.0;
      repeat <<x := 10.0*x+y; i := i+1>> until (z := x+1.0)=x;
% The following line and the corresponding one in find!!nbfpd can call
% FIX on a a value that is around 10^16 (if floats are IEEE 64-bit values) and
% that might lead to unreliable conseqences. If arithmetic is IEEE (as maybe
% it mostly will be these days) then the test would fail anyway, so
% in that case commenting it out can not have adverse effects!
%     if 10.0*fix(z/10) - 1.0 neq x then i := i - 1;
      return !!nfpd:=i end;

symbolic procedure find!!nbfpd;
   begin scalar x,y,z;integer i; x:=y:=1.0;
      repeat <<x := 2.0*x+y; i := i+1>> until (z := x+1.0)=x;
%     if 2.0*fix(z/2) - 1.0 neq x then i := i-1;
      return !!nbfpd:=i end;

symbolic procedure find!!maxbflexp;
   begin scalar z; integer n;
      !!!~xx := 1.0;
      while not errorp
       (z := errorset!*(
          '(progn (setq !!yy (plus 1.0 (times !!!~xx 2.0)))
                  (and (not (infinityp !!yy))
                       (greaterp !!yy !!!~xx))),nil))
         and car z do
            <<n := n+1; !!!~xx := !!yy>>;
      !!flexperr := not errorp z and not car z;
      return !!maxbflexp := n end;

symbolic procedure find!!minnorm();
   begin scalar a, b, c;
     a := 1.0;
     b := 0.0;
     repeat <<
       c := b;
       b := a;
       a := 2.0*a + 1.0 >> until a/2.0 = b;
% Now c should be a numbers whose mantissa has all possible bits set.
     repeat <<
       b := c;
       c := c/2.0 >> until 2.0*c neq b;
% If my computer does not provide denormalised numbers this loop
% will end on an underflow with c zero.
     if c = 0.0 then !!minnorm := b
     else !!minnorm := c;
   end;

% I believe I might now retire this in favour of fp!-infinite but BEWARE
% that this code will also reply "true" on NaNs as well as infinities.

symbolic procedure infinityp u;
   % Check for a representation of an IEEE floating point infinity.
   not(x eq '!- or digit x) where x=car explode u;

symbolic procedure !!mfefix;
  <<if !!flexperr then
      begin integer n;
        !!flexperr := !!plumax := nil;
        while errorp errorset!*('(explode !!!~xx),nil) do
          <<!!!~xx := !!!~xx/2.0; n := n+1>>;
        !!maxbflexp := !!maxbflexp - n;
      end;
    if not !!plumax then roundconstants()>>;

find!!nfpd(); find!!nbfpd();
find!!maxbflexp(); find!!minnorm();

!!epsqrt := 10.0**((-1 - !!nfpd)/2);

!!flint := 10.0**!!nfpd;

!!flbint := 2.0 ** !!nbfpd;

!!floatbits := (10*(!!nfpd + 1))/3;  % Smallest power of 2 that does
               % not fit in mantissa.  Note that 10/3 > log(10)/log(2).


% The following should only ever be used on floating point values. Note
% that it may be important to use EQN not EQUAL here in case EQUAL treats
% things that are EQ as being equal, while NaN must not be treated as
% equal even to itself.

% I pre-check for zero so that I do not attempt to compute 1.0/0.0. This
% is because on systems that do not actually have infinities that attempt at
% division could raise an exception. Well even without that situation I can
% worry because if x is a sub-normalised number (eg 1.0e-311) its reciprocal
% could be an IEEE infinity. So my first attempt here was not good enough to
% be safe for PSL. Hence the fact that I only do the division if the absolute
% value of x is at least 1.0e300. So almost all non-infinities will be
% detected by the range check and only the extreme ones fall to the
% reciprocal test.

symbolic inline procedure fp!-infinite x;
  (x > 1.0e300 or x < -1.0e300) and eqn(1.0/x, 0.0);

symbolic inline procedure fp!-nan x;
  not eqn(x, x);

symbolic inline procedure fp!-finite x;
  eqn(x-x, 0.0);

symbolic inline procedure fp!-subnorm x;
  abs x < !!minnorm;


endmodule;

end;
