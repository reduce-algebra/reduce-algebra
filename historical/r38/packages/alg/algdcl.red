module algdcl;  % Various declarations.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

global '(preclis!* ws);

symbolic procedure formopr(u,vars,mode);
   if mode eq 'symbolic
     then list('flag,mkquote cdr u,mkquote 'opfn)
    else list('operator,mkarg(cdr u,vars));

put('operator,'formfn,'formopr);

symbolic procedure operator u; for each j in u do mkop j;

rlistat '(operator);

symbolic procedure remopr u;
   % Remove all operator related properties from id u.
   begin
      remprop(u,'alt);
      remprop(u,'infix);
      remprop(u,'op);
      remprop(u,'prtch);
      remprop(u,'simpfn);
      remprop(u,'unary);
      remflag(list u,'linear);
      remflag(list u,'nary);
      remflag(list u,'opfn);
      remflag(list u,'antisymmetric);
      remflag(list u,'symmetric);
      remflag(list u,'right);
      preclis!* := delete(u,preclis!*)
   end;

flag('(remopr),'eval);

symbolic procedure den u;
   mk!*sq (denr simp!* u ./ 1);

symbolic procedure num u;
   mk!*sq (numr simp!* u ./ 1);

flag('(den num),'opfn);

flag('(den num),'noval);

put('saveas,'formfn,'formsaveas);

symbolic procedure formsaveas(u,vars,mode);
   list('saveas,formclear1(cdr u,vars,mode));

symbolic procedure saveas u;
   let00 list list(if smemq('!~,car u) then 'replaceby else 'equal,
		   car u,
		   if eqcar(ws,'!*sq)
		      and smemql(for each x in frasc!* collect car x,
				 cadr ws)
		     then list('!*sq,cadr ws,nil)
		    else ws);

rlistat '(saveas);

endmodule;

end;
