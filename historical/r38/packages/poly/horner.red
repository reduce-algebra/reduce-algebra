module horner; % Convert an expression into a nested Horner product.

% Author: Herbert Melenk.

fluid '(!*exp !*div);

symbolic procedure hornersq u;
  if !*div and null dmode!* and numberp denr u and denr u neq 1 then
   <<setdmode('rational,t); 
     u:=hornerf quotf(numr u, denr u);
     setdmode('rational,nil);
     u ./ 1>>
   else hornerf numr u . hornerf denr u;

symbolic procedure hornerf u;
  <<u:=expnd u where !*exp=t; hornerf1 u where !*exp=nil>>;

symbolic procedure hornerf1 u;
  begin scalar x,a,b,c; integer n,m;
   if domainp u then return u;
   if domainp red u then goto q; 

      % Identify the pattern
      %      x^n*a + x^m*b + c with n>m 
      % and transform it into
      %      x^m(x^(n-m)*a + b) + c
      % calling hornerf1 again for folding x^m with powers of
      % x in c. Also a and b are folded recursively.
      % The term x^n*a may have the form (x^k*f+g)*x^n*h
      % by recursion; in that case a is (x^k*f+g)*h.

   if (x:=mvar u) = mvar red u then
   << n:=ldeg u; a:=hornerf1 lc u; u:=red u; m:=ldeg u;
      b:=hornerf1 lc u; c:=red u >>
   else if sfp mvar u and not domainp lc u and (x:=mvar lc u)=mvar red u 
     and (n:=ldeg lc u)>(m:=ldeg red u) then
   << a:=multf(mvar u,lc lc u); u:=red u; b:=hornerf1 lc u; c:=red u >>
   else goto q;
   return hornerf1
       addf(multf(exptf(!*k2f x,m),
                  addf(multf(exptf(!*k2f x,n-m),a),
                       b)), c);
q: return addf(multf(!*p2f lpow u,hornerf1 lc u),hornerf1 red u);
   end;

put('horner,'polyfn,'hornerf);

endmodule;

end;
