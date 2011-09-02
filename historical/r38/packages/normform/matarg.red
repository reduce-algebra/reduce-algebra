module matarg;
               % This module forms the ability for matrices to be passed
               % between functions.
               %
               % This module can be used independently from algebraic 
               % mode.
               %
               % It was written by W. Neun.
               %

symbolic procedure mkmatrix(n,m);
   'mat . (for i:=1:n collect
           for j:=1:m collect 0);

symbolic procedure setmat(matri,i,j,val);
    <<   if !*modular then << off modular; on mod_was_on; >>;
         i := reval i;
         j := reval j;
         val := mk!*sq simp reval val;
         letmtr(list(matri,i,j),val,matri);
         if !*mod_was_on then << on modular; off mod_was_on; >>;
         matri>>;

symbolic procedure letmtr(u,v,y);
   %substitution for matrix elements;
   begin scalar z;
	if not eqcar(y,'mat)
	  then rerror(matrix,10,list("Matrix",car u,"not set"))
         else if not numlis (z := revlis cdr u) or length z neq 2
          then return errpri2(u,'hold);
        rplaca(pnth(nth(cdr y,car z),cadr z),v);
   end;

symbolic procedure getmat(matri,i,j);
    <<   i := off_mod_reval i;
         j := off_mod_reval j;
         unchecked_getmatelem list(matri,i,j)>>;

symbolic procedure unchecked_getmatelem u;
  begin scalar x;
         if not eqcar(x :=  car u,'mat)
          then  rerror(matrix,1,list("Matrix",car u,"not set"))
         else return nth(nth(cdr x,cadr u),caddr u);
   end;

flag('(setmat,getmat,mkmatrix,letmtr),'opfn);  %  So they can be used
                                               %  independently from 
                                               %  algebraic mode.
                                              
endmodule;

end;

