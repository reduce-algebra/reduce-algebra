module where;  % Support for a where construct.

% Author: Anthony C. Hearn.

% Copyright (c) 1987 The RAND Corporation.  All rights reserved.

% global '(fixedpreclis!*);

symbolic procedure formwhere(u,vars,mode);
   begin scalar expn,equivs,y,z;
     expn := cadr u;
     equivs := remcomma caddr u;
     if not(mode eq 'symbolic)
       then return formc(list('whereexp,'list . equivs,expn),vars,mode);
     for each j in equivs do
	if not atom j and car j memq '(equal setq)
	  then <<y := caddr j . y; z := cadr j . z>>
	 else rerror(rlisp,17,list(j,"invalid in WHERE statement"));
     return formc(list('lambda,reversip z,expn) . reversip y,vars,mode)
   end;

put('where,'formfn,'formwhere);

% fixedpreclis!* := 'where . fixedpreclis!*;  % Where has special place.

% mkprec();

endmodule;

end;
