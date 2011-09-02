module fac;  % Support "factor" as an operator.

% Author: Anthony C. Hearn.

global '(!*micro!-version);

symbolic procedure factor u;
   if !*micro!-version then factor0 u else factor1(u,t,'factors!*);

symbolic procedure factor0 u;
   begin scalar oldexp,v,w;
      if cdr u or kernp (v := simp!* car u)
        then <<lprim "Please use FAC instead"; 
               return factor1(u,t,'factors!*)>>;
      oldexp := !*exp;
      !*exp := t;
      if null oldexp then v := resimp v;
      w := !*fcfm2f fctrf numr v ./ !*fcfm2f fctrf denr v;
      if null oldexp then !*exp := oldexp;
%      if w = u or w = v then return u
%       else if null oldexp then return mk!*sq w
%       else return list('!*sq,w,nil)
      return mk!*sq w
    end;

flag('(factor),'intfn);

symbolic procedure !*fcfm2f u;
   % converts factored form u to standard form.
   multf(car u,!*fcfm2f1 cdr u);

symbolic procedure !*fcfm2f1 u;
   if null u then 1 else multpf(mksp(caar u,cdar u),!*fcfm2f1 cdr u);

symbolic procedure expandd u; reval u where !*exp = t;

flag('(expandd),'opfn);

flag('(expandd),'noval);

endmodule;

end;
