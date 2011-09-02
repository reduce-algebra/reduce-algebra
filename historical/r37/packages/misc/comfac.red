module comfac;   % Multivariate common factor/content routines.

% Author: Anthony C. Hearn.

% Copyright (c) 1989 The RAND Corporation.  All Rights Reserved.

symbolic smacro procedure domain!-gcd(u,v); gcdn(u,v);

symbolic smacro procedure domain!-onep u; onep u;

symbolic procedure mv!-pow!-zerop u;
   null u or zerop car u and mv!-pow!-zerop cdr u;

symbolic procedure mv!-pow!-gcd(u,v);
   if null u then nil
    else min(car u,car v) . mv!-pow!-gcd(cdr u,cdr v);

symbolic procedure mv!-content u;
   % Finds the term that is the content of u.
      if null u then nil
       else begin scalar x,y;
	 x := mv!-lc u;
	 y := mv!-lpow u;
      a: u := mv!-red u;
	 if null u or domain!-onep x and mv!-pow!-zerop y
	   then return mv!-!.!*(y,x);
	 x := domain!-gcd(x,mv!-lc u);
	 y := mv!-pow!-gcd(y,mv!-lpow u);
	 go to a
       end;

endmodule;

end;
