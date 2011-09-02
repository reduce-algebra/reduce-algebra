module infix; % Functions for introducing new infix operators.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

fluid '(!*mode);

global '(preclis!*);

symbolic procedure forminfix(u,vars,mode);
   begin scalar x;
      if null(mode eq 'symbolic)
       then x := for each j in cdr u collect list('mkop,mkarg(j,vars));
      u := list(car u,mkarg(cdr u,vars));
      return if x then 'progn . aconc(x,u) else u
   end;

put('infix,'formfn,'forminfix);

symbolic procedure infix x;
   <<for each j in x do
	if not(j member preclis!*) then preclis!* := j . preclis!*;
     mkprec()>>;

symbolic procedure precedence u;
   begin scalar x,y,z;
      preclis!* := delete(car u,preclis!*);
      y := cadr u;
      x := preclis!*;
   a: if null x then rerror(rlisp,16,list (y,"not found"))
       else if y eq car x
        then <<preclis!* :=
                  nconc!*(reversip!* z,car x . (car u . cdr x));
               mkprec();
               return nil>>;
      z := car x . z;
      x := cdr x;
      go to a
   end;

deflist('((infix rlis) (precedence rlis)),'stat);

flag('(infix precedence),'eval);

endmodule;

end;
