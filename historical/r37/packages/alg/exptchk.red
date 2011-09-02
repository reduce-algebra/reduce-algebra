module exptchk;   % Check expt products for further simplification.

% Author: Anthony C. Hearn.

fluid '(!*combineexpt !*keepexptseparate);

switch combineexpt;

put('combineexpt,'simpfg,'((t (rmsubs)) (nil (rmsubs))));

symbolic procedure exptunwind(u,v);
   % U is a standard form, v a list of powers.
   % result is a standard form of product(v) * u.
   % This function is the key to a better treatment of surds.
   % Note that combineexpt on gives most compact results. However,
   % in some cases, we can do the reduction even when combineexpt
   % is off. However, some tests are considerably slower (or even 
   % give less compact results) in such cases.  The internal switch
   % keepexptseparate accordingly inhibits this use.
   begin scalar x,x1,x2,y,z,z2;
  a:  if null v then return u;
      x := caar v;    % kernel in EXPT
      x1 := cadr x;   % expression
      x2 := caddr x;  % exponent
      y := cdar v;    % power
      v := cdr v;
      % This section looks for expt expressions in which bases match.
      while (z := assocp1(x1,v)) and
         (z2 := simp {'plus,{'times,x2,y},{'times,caddar z,cdr z}})
         and (!*combineexpt or (fixp numr z2 and fixp denr z2))
	do <<if fixp numr z2 and fixp denr z2
               then <<x2 := divide(numr z2,denr z2);
                      if car x2>0
			then <<if fixp x1 then u := multf(x1**car x2,u)
				else u := multpf(mksp(x1,car x2),u);
                               z2 := cdr x2 ./ denr z2>>;
                      y := numr z2>>
	     else if domainp numr z2 then y := 1
              else <<y := lnc cdr comfac numr z2;
                     if not fixp y then y := 1>>;
             x2 := prepsq(quotf(numr z2,y) ./ denr z2);
             v := delete(z,v)>>;
      % This section looks for expressions in which exponents match.
      % We need to see if we can refine use of *combineexpt here.
      if !*combineexpt and y=1 and fixp x1 then   % Is y=1 necessary?
         <<while (z := assocp2(x2,v)) and cdr z=1 and fixp cadar z do
              <<x1 := cadar z * x1; v := delete(z,v)>>;
           if eqcar(x2,'quotient) and fixp cadr x2 and fixp caddr x2
      % We need next line for the case on combineexpt,rational;
      %    1/sqrt(2)*(rt^(2/3)*m^(1/3)*3^(2/3))/2^(5/6);
		and cadr x2<caddr x2
             then <<z := nrootn(x1**cadr x2,caddr x2);
                    if cdr z = 1 then u := multd(car z,u)
                     else if car z = 1
                      then u := multf(formsf(x1,x2,1),u)
                     else <<u := multd(car z,u);   % Iterate again.
                            v := (list('expt,cdr z,x2) . 1) . v>>>>
            else u := multf(formsf(x1,x2,y),u)>>
       else u := multf(formsf(x1,x2,y),u);
      go to a
   end;

symbolic procedure assocp1(u,v);
   % Looks for equality of u to a in list of terms of form
   % ((expt a b) . n).
   if null v then nil
    else if u = cadr caar v then car v
    else assocp1(u,cdr v);

symbolic procedure assocp2(u,v);
   % Looks for equality of u to b in list of terms of form
   % ((expt a b) . n).
   if null v then nil
    else if u = caddr caar v then car v
    else assocp2(u,cdr v);

symbolic procedure formsf(u,v,n);
   % u is either an integer, or a kernel.
   % Creates (u^v)^n as a standard form.
   if fixp u and fixp v then (u^v)^n
    else if v=1 then !*p2f mksp(u,n)
    else !*p2f mksp(list('expt,u,v),n);

symbolic procedure exptchksq u;
   % U is a standard quotient. Result is u with possible expt
   % simplifications.
   if !*keepexptseparate then u else
   (if u=v or denr v=1 then v
     % else reduce to lowest terms.
     else multsq(numr v ./1,1 ./denr v))
    where v = (exptchk numr u ./ exptchk denr u);

symbolic procedure exptchk u;
   % u is a standard form. Result is u with possible expt
   % simplifications.
   if domainp u then u else exptchk1(u,nil);

symbolic procedure exptchk1(u,v);
   % This is the key procedure for exponent reduction. At the moment,
   % only constant arguments are considered.
   if null u then nil
    else if not exptexpfp u then exptunwind(u,v)
    else if eqcar(mvar u,'expt) % and fixp cadr mvar u
     then addf(exptchk1(lc u,lpow u . v),exptchk1(red u,v))
    else addf(multpf(lpow u,exptchk1(lc u,v)),exptchk1(red u,v));

symbolic procedure exptexpfp u;
   % True if u contains an expt kernel.
   not domainp u
      and ((eqcar(x,'expt) or exptexpfp lc u or exptexpfp red u)
	   where x = mvar u);

endmodule;

end;
