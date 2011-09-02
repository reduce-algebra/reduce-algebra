module kernel;   % Functions for operations on kernels.

% Author: Anthony C. Hearn.

% Copyright (c) 1990 The RAND Corporation.  All rights reserved.

global '(exlist!* kprops!*);

symbolic procedure fkern u;
   % Finds the unique "p-list" reference to the kernel U.  The choice of
   % the search and merge used here has a strong influence on some
   % timings.  The ordered list used here is also used by prepsq* to
   % order factors in printed output, so cannot be unilaterally changed.
   begin scalar x,y;
	if atom u then return list(u,nil)
	 else if x := get(car u,'fkernfn) then return apply1(x,u);
        y := if atom car u then get(car u,'klist) else exlist!*;
        if not (x := assoc(u,y))
          then <<x := list(u,nil);
                 y := ordad(x,y);
                 if atom car u
                   then <<kprops!* := union(list car u,kprops!*);
                          put(car u,'klist,y)>>
                  else exlist!* := y>>;
        return x
   end;

symbolic procedure kernels u;
   % Returns list of kernels in standard form u.
   kernels1(u,nil);

symbolic procedure kernels1(u,v);
   % We append to end of list to put kernels in the right order, even
   % though a cons on the front of the list would be faster.
   if domainp u then v
    else kernels1(lc u,
                  kernels1(red u,
                           if x memq v then v else append(v,list x)))
         where x=mvar u;

symbolic procedure kernp u;
   % True if U is standard quotient representation for a kernel.
   denr u=1 and not domainp(u := numr u)
        and null red u and lc u=1 and ldeg u=1;     % onep

endmodule;

end;
