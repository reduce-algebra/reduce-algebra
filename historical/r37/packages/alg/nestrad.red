module nestrad; % Simplify nested square roots.

% Author: H. Melenk.

% Modifications by: A. C. Hearn:

% The case sqrt(x+8-6*sqrt(x-1)) gave the wrong sign for say x=5.
% However, adding an abs call messed up int(1/(x**4+4*x**2+1),x).
% So for the time being, we only use this code when the argument can
% be shown to be a non-negative number.

fluid '(!*intflag!*);

symbolic procedure unnest!-sqrt!-sqrt!*(a0,b0,r0);
  % look for a simplified equivalent to sqrt(a + b*sqrt(c));
  % See: Borodin et al, JSC (1985) 1,p 169ff.
  begin scalar d,a,b,r,s,w;
   if numberp r and r<0 then return nil;
   a:=simp a0; b:=simp b0; r:=simp r0;
     % discriminant: d:=sqrt(a^2-b^2*r).
   d:=subtrsq(multsq(a,a),multsq(multsq(b,b),r));
   if denr d neq 1 or (not domainp(d:=numr d) and not evenp ldeg d)
      or cdr(d:=radf(d,2)) then return nil;
   d := car d ./ 1;
    % s := 2(a+d).
   s:=addsq(a,d); s:=addsq(s,s); s:=prepsq s;
    % w:=(s+2 b sqrt r)/2 sqrt s.
   w:={'quotient,{'times,{'sqrt,s},{'plus,s,{'times,2,b0,{'sqrt,r0}}}},
                 {'times,2,s}};
   return w;
 end;

symbolic procedure unnest!-sqrt!-sqrt(a,b,r);
  begin scalar w;
     return if (w:=unnest!-sqrt!-sqrt!*(a,b,r)) then chkabs w
	     else if (w:=unnest!-sqrt!-sqrt!*({'times,b,r},a,r))
	      then chkabs {'quotient,w,{'expt,r,{'quotient,1,4}}}
	     else nil
  end;

symbolic procedure chkabs u;
   if !*intflag!* then u      % The integrator doesn't care about sign.
%   else (if null x then {'abs,u}
    else (if null x then u
	   else if not minusp!: x then u
	   else {'minus,u})
	 where x = not_imag_num u;

symbolic operator unnest!-sqrt!-sqrt;

algebraic;

sqrtsqrt_rules := { 
(~a + ~b * ~c^(1/2)) ^(1/2) => !*!*w 
   when (!*!*w:=unnest!-sqrt!-sqrt(a,b,c)),
(~a + ~c^(1/2)) ^(1/2) => !*!*w
   when (!*!*w:=unnest!-sqrt!-sqrt(a,1,c))}$

let sqrtsqrt_rules;

endmodule;

end;
