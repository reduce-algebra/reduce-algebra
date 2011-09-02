module pade;  % Pade' Approximations.

% Author: Lisa Temme

% Date: 15/6/95.

algebraic;

load taylor;

load solve;

%**************
%%Include a boolean function to check for taylor expression
procedure taylorp(x);
   lisp eqcar(x,'taylor);



%% Input my code for the Pade Function

procedure pade(f, x, h, n, d);

% f is function to be approximated
% x is function variable
% h is point at which approximation is evaluated
% n is degree (wanted) of numerator of rational function approximation
% d is degree (wanted) of denominator of rational function approximation

   begin
     scalar y,g,numer,denom, num_var_list, den_var_list, variable_list,
	    tay_expsn,tay_output,poly_taylor,coeff_list,j, k, kk, a, b,
	    new_list,answer,part_answer,count,zero_check_list,p,q,r;
     
%check to see if input is rational
%if so larger degrees of n & d will return input
     if type_ratpoly(f,x) AND deg(num f,x)<=n AND deg(den f,x)<=d
     then return f
     else
     << y := lisp gensym();  	    %declare y as local variable
     	lisp(a:=  gensym());                       %\  declare
        lisp(b:=  gensym());                       % | a and b
        lisp eval list ('operator,mkquote list a); % | as local
        lisp eval list ('operator,mkquote list b); %/  operators
 
        g := sub(x=y+h,f);	    %rewrite f in terms of y at 0
 
        numer :=  for k:=0:n sum a(k)*y^k;
        denom :=  for j:=0:d sum b(j)*y^j;
        num_var_list := for k:=0:n collect a(k);
        den_var_list := for j:=0:d collect b(j);
        variable_list := append(num_var_list,den_var_list);
 
        tay_expsn  := taylor(g, y,0,n+d);
        tay_output := taylortostandard(tay_expsn);
        if NOT(freeof(tay_output,df)) then rederr "not yet implemented"
        %Some Taylor Expansions do not exist at present.

        else
	<< poly_taylor :=
	      denom*(num tay_output) - numer*(den tay_output);
           coeff_list := COEFF(poly_taylor,y);

           if (n+d+1)>length(coeff_list)		
           %Only consider first n+d+1 coefficients at most.

           then new_list := coeff_list
	   else new_list :=
		   for kk:= 1:n+d+1 collect part(coeff_list,kk);
          
           part_answer := solve(new_list,variable_list);
           count :=0;
           zero_check_list := 
               for each r in 
               (for each q in 
                (for p:=n+2:n+d+2 collect part(first part_answer,p))
                                   collect part(q,2))
                                    do <<if r=0 then count:=count+1>>;
                                                            
           %if all the coefficients of the denominator are zero
           if count=d+1 
           then rederr "Pade Approximation of this order does not exist"

           else
           << answer:= sub(part_answer, numer/denom);
              %if Pade would be returned as a Taylor expansion
              if taylorp answer 
              then rederr "no Pade Approximation exists"
%following commented out as not sure it is necessary
%                else 
%                << if length answer=0 
%                   then 
%               rederr "Pade Approximation of this order does not exist"
              else return  sub(y=x,answer) 
%                >>;
           >>;
        >>;
   >>;
   end;

endmodule;

end;
