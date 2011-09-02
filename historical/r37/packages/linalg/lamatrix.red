module lmatrix;

%**********************************************************************%
%                                                                      %
% This module forms the ability for matrices to be passed locally.     %
%                                                                      %
% Authors: W. Neun (customised by Matt Rebbeck).                       %
%                                                                      %
%**********************************************************************%

switch mod_was_on;  % Used internally to keep track of the modular 
                    % switch.


symbolic procedure mkmatrix(n,m);
  %
  % Create an nXm matrix.
  %
   'mat . (for i:=1:n collect
           for j:=1:m collect 0);



symbolic procedure setmat(matri,i,j,val);
  %
  % Set matrix element (i,j) to val.
  %
  <<   if !*modular then << off modular; on mod_was_on; >>;
       i := my_reval i;
       j := my_reval j;
       my_letmtr(list(matri,i,j),val,matri);
       if !*mod_was_on then << on modular; off mod_was_on; >>;
       matri>>;



symbolic procedure getmat(matri,i,j);
  %
  % Get matrix element (i,j).
  %
  <<   if !*modular then << off modular; on mod_was_on; >>;
       i := my_reval i;
       j := my_reval j;
       if !*mod_was_on then << on modular; off mod_was_on; >>;
       unchecked_getmatelem list(matri,i,j)>>;



symbolic procedure unchecked_getmatelem u;
  begin scalar x;
         if not eqcar(x :=  car u,'mat)
          then  rerror(matrix,1,list("Matrix",car u,"not set"))
         else return nth(nth(cdr x,cadr u),caddr u);
   end;



symbolic procedure my_letmtr(u,v,y);
  %
  % Substitution for matrix elements with reval only when necessary.
  %
  begin 
    scalar z;
    if not eqcar(y,'mat) then 
     rerror(matrix,10,list("Matrix",car u,"not set"))
      else if not numlis (z := my_revlis cdr u) or length z neq 2
       then return errpri2(u,'hold);
    rplaca(pnth(nth(cdr y,car z),cadr z),v);
  end;


endmodule;  % lmatrix.

end;
