module paraset;   % Parameter determining module.

% Author: Stanley L. Kameny.

% Last change date: 23 June 1993.

% Paraset.red determines the parameters !!nfpd, !!nbfpd, and !!maxbflexp
% for floating point numbers.  !!nfpd, !!nbfpd, and !!maxbflexp are
% computed at load, but !!maxbflexp may have to be fixed up at run time
% if !!flexperr is true.

imports errorp, errorset!*, neq, roundconstants;

exports !!mfefix, find!!nbfpd, find!!nfpd, infinityp;

global '(!!nfpd !!nbfpd !!!~xx !!yy !!maxbflexp !!flexperr !!plumax
	 !!epsqrt !!flint !!flbint !!floatbits);

flag('(!!nfpd !!nbfpd !!maxflexp),'share);

symbolic procedure find!!nfpd;
   begin scalar x,y,z;integer i; x:=y:=9.0;
      repeat <<x := 10.0*x+y; i := i+1>> until (z := x+1.0)=x;
      if 10.0*fix(z/10) - 1.0 neq x then i := i - 1;
      return !!nfpd:=i end;

symbolic procedure find!!nbfpd;
   begin scalar x,y,z;integer i; x:=y:=1.0;
      repeat <<x := 2.0*x+y; i := i+1>> until (z := x+1.0)=x;
      if 2.0*fix(z/2) - 1.0 neq x then i := i-1;
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
find!!maxbflexp();

!!epsqrt := 10.0**((-1 - !!nfpd)/2);

!!flint := 10.0**!!nfpd;

!!flbint := 2.0 ** !!nbfpd;

!!floatbits := (10*(!!nfpd + 1))/3;  % Smallest power of 2 that does
	       % not fit in mantissa.  Note that 10/3 > log(10)/log(2).

endmodule;

end;
