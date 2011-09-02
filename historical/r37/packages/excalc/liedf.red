module liedf;

% Author: Eberhard Schruefer;

global '(commutator!-of!-framevectors);

newtok '((!| !_ ) liedf);

infix liedf;

%flag('(liedf),'nary); %Not done for now, but should be considered.

flag('(liedf),'spaced);

precedence liedf,innerprod;

put('liedf,'simpfn,'simpliedf);

put('liedf,'rtypefn,'getrtypeor);

symbolic procedure simpliedf u;
   !*pf2sq partitliedf u;

put('liedf,'partitfn,'partitliedf);

symbolic procedure partitliedf u;
   liedfpf(partitop car u,partitop cadr u);

symbolic procedure mkliedf(u,v);
   begin scalar x,y;
     return if x := opmtch(y := list('liedf,u,v))
               then partitop x
             else mkupf y
   end;


symbolic procedure liedfpf(u,v);
   if null tvectorp u then
      rerror(excalc,9,
	     "First argument of lie derivative must be a vector")
    else if null tvectorp v then
             addpf(exdfpf innerprodpf(u,v),
                   innerprodpf(u,exdfpf v))
    else begin scalar x;
           for each k on u do
             for each l on v do
               x := addpf(liedftt(lt k,lt l),x);
           return x
         end;

symbolic procedure liedftt(u,v);
   begin scalar x;
     return addpf(multpfsq(liedfk(car u,car v),multsq(tc u,tc v)),
                  addpf(if x := innerprodpf(!*k2pf car u,exdf0 tc v)
                           then car v .*
                                multsq(!*pf2sq x,tc u) .+ nil
                         else nil,
                        if x := innerprodpf(!*k2pf car v,exdf0 tc u)
                           then car u .*
                                negsq multsq(!*pf2sq x,tc v) .+ nil
                   else nil))
   end;

symbolic procedure liedfk(u,v);
   if u eq v then nil
    else if eqcar(u,'partdf) and eqcar(v,'partdf) then nil
    else if basisvectorp u and basisvectorp v
            then if null ordop(u,v)
                    then negpf liedfk(v,u)
                  else if commutator!-of!-framevectors
                          then get!-structure!-const(u,v)
                  else mkliedf(u,v)
    else if eqcar(v,'liedf)
            then if ordop(u,cadr v) then mkliedf(u,v)
                  else addpf(liedfpf(liedfk(u,cadr v),!*k2pf caddr v),
                             liedfpf(!*k2pf cadr v,
                                     liedfpf(!*k2pf u,!*k2pf caddr v)))
    else if worderp(u,v) then mkliedf(u,v)
          else negpf mkliedf(v,u);

symbolic procedure get!-structure!-const(u,v);
   %We currently assume that only the basis has structure consts.
   begin scalar x;
     return if x := assoc(list(cadadr u,cadadr v),
                          commutator!-of!-framevectors)
               then !*pfsq2pf cdr x
             else nil
   end;


endmodule;

end;
