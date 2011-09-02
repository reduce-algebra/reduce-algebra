module coeff;  % Routines for finding coefficients of forms.

% Author: Anthony C. Hearn.

% Modifications by: F. Kako (including introduction of COEFFN).

% Copyright (c) 1991 RAND.  All rights reserved.

fluid '(!*ratarg);

global '(hipow!* lowpow!*);

switch ratarg;

flag ('(hipow!* lowpow!*),'share);

symbolic procedure coeffeval u;
   begin integer n;
      n := length u;
      if n<2 or n>3
	then rerror(alg,28,
		    "COEFF called with wrong number of arguments")
       else return coeff1(car u,cadr u,
                         if null cddr u then nil else caddr u)
      end;

put('coeff,'psopfn,'coeffeval);

symbolic procedure coeff1(u,v,w);
   % Finds the coefficients of V in U and returns results in W.
   % We turn EXP on and FACTOR off to make sure powers of V separate.
   (begin scalar !*factor,bool,x,y,z;
	if eqcar(u,'!*sq) and null !*exp
	  then <<!*exp := t; u := resimp cadr u>>
	 else <<!*exp := t; u := simp!* u>>;
        v := !*a2kwoweight v;
        bool := !*ratarg or freeof(prepf denr u,v);
        if null bool then u := !*q2f u;
	x := updkorder v;
	if null bool then <<y := reorder u; u := 1>>
         else <<y := reorder numr u; u := denr u>>;
        setkorder x;
        if null y then go to a;
        while not domainp y and mvar y=v
           do <<z := (ldeg y . !*ff2a(lc y,u)) . z; y := red y>>;
        if null y then go to b;
    a:  z := (0 . !*ff2a(y,u)) . z;
    b:  lowpow!* := caar z;
        z := reverse z;
        hipow!* := caar z;
        z := multiple!-result(z,w);
        return if null w then z else hipow!*
   end) where !*exp = !*exp;

symbolic procedure coeffn(u,v,n);
   % Returns n-th coefficient of U.
   % We turn EXP on and FACTOR off to make sure powers of V separate.
   begin scalar !*exp,!*factor,bool,x,y;
      !*exp := t;
      n := reval n;
      if not fixp n or minusp n then typerr(n,"COEFFN index");
      v := !*a2kwoweight v;
      u := simp!* u;
      bool := !*ratarg or freeof(prepf denr u,v);
      if null bool then u := !*q2f u;
      x := updkorder v;
      if null bool then <<y := reorder u; u := 1>>
       else <<y := reorder numr u; u := denr u>>;
      setkorder x;
      if null y then return 0; % changed by JHD for consistency
   b: if domainp y or mvar y neq v
        then return if n=0 then !*ff2a(y,u) else 0
       else if n=ldeg y then return !*ff2a(lc y,u)
       else if n>ldeg y then return 0
       else <<y := red y; go to b>>
   end;

flag('(coeffn),'opfn);

flag('(coeffn),'noval);

endmodule;

end;
