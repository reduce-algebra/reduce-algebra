module rank;

% Author: Eberhard Schruefer.

% Module for calculating the rank of a matrix or a system of linear
% equations.
% Format: rank <matrix> : rank <list of equations>.

symbolic procedure rank!-eval u;
   begin scalar n;
      if cdr u then rerror(matrix,17,"Wrong number of arguments")
       else if getrtype (u := car u) eq 'matrix
	 then return rank!-matrix matsm u
       else if null eqcar(u := aeval u,'list) then typerr(u,"matrix")
       else return rank!-matrix
	 for each row in cdr u collect
	   if not eqcar(row,'list)
	       then rerror(matrix,15,"list not in matrix shape")
	    else <<row := cdr row;
		   if null n then n := length row
		    else if n neq length row
		     then rerror(matrix,151,"list not in matrix shape");
		   for each j in row collect simp j>>
   end;


put('rank,'psopfn,'rank!-eval);

symbolic procedure rank!-matrix u;
   begin scalar x,y,z; integer m,n;
     z := 1;
     for each v in u do
          <<y := 1;
	    for each w in v do y := lcm(y,denr w);
	    m := 1;
	    x := nil;
	    for each j in v do
	      <<if numr j then
		x := list m .* multf(numr j,quotf(y,denr j)) .+ x;
		m := m + 1>>;
	    if y := c!:extmult(x,z)
	       then <<z := y; n := n + 1>>>>;
     return n
    end;

endmodule;

end;
