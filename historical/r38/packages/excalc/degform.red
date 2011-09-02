module degform;

% Author: Eberhard Schruefer;

fluid '(frlis!*);

global '(dimex!*);

symbolic procedure deg!*farg u;
   %Calculates the sum of degrees of the elements of the list u;
   if null cdr u then deg!*form car u else
    begin scalar z;
      for each j in u do z := addf(deg!*form j,z);
      return z
    end;

symbolic procedure deg!*form u;
%U is a prefix expression. Result is the degree of u;
   if atom u then get!*fdeg u
    else (if flagp(x,'indexvar) then get!*ifdeg u
           else if x eq 'wedge then deg!*farg cdr u
           else if x eq 'd then addd(1,deg!*form cadr u)
           else if x eq 'hodge then addf(dimex!*,negf deg!*form cadr u)
           else if x eq 'partdf then if cddr u then nil else -1
           else if x eq 'liedf then deg!*form caddr u
           else if x eq 'innerprod then addd(-1,deg!*form caddr u)
           else if x memq '(plus minus difference quotient) then
                     deg!*form cadr u
           else if x eq 'times then deg!*farg cdr u
           else nil) where x = car u;

symbolic procedure simpexdegree u;
   !*f2q deg!*form prepsq simp!* car u;

put('exdegree,'simpfn,'simpexdegree);

symbolic procedure exformp u;
   %test for exterior forms and vectors in prefix expressions;
   if null u or numberp u then nil
    else if atom u and u memq frlis!* then t
    else if atom u then get(u,'fdegree)
    else if flagp(car u,'indexvar)
            then assoc(length cdr u,get(car u,'ifdegree))
    else if car u eq '!*sq then exformp prepsq cadr u
    else if car u memq '(wedge d partdf hodge innerprod liedf) then t
    else if get(car u,'dname) then nil
    else lexformp cdr u or exformp car u;

symbolic procedure lexformp u;
   u and (exformp car u or lexformp cdr u);


endmodule;

end;
