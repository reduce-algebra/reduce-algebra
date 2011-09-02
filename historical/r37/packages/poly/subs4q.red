module subs4q; % Routines for matching quotients.

% Author: Anthony C. Hearn.
%         modification to more general quotient matching: Herbert Melenk

% Copyright (c) 1992 RAND.  All rights reserved.

symbolic procedure subs4q u;
   % U is a standard quotient,
   % Value is a standard quotient with all quotient substitutions made.
   begin scalar x,w,q,d;
      if null(x:=get('slash,'opmtch)) then return u;
      w := prepsq u;
      remprop('slash,'opmtch); % to prevent endless recursion.
      put('slash!*,'opmtch,x);
      while w and eqcar(q:=w,'quotient) do
          <<w:=opmtch ('slash!* . cdr w) or
               smemq('minus,caddr w) and
		  opmtch{'slash!*,reval{'minus,cadr w},
				  reval{'minus,caddr w}};
            d:=d or w>>;
      u:= if d then simp!* q else u;
      put('slash,'opmtch,x);
      return u;
   end;

endmodule;

end;
