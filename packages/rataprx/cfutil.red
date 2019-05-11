module cfutil;
% Various utilities for continued fractions
% A. Barnes, February 2019

% The following code for printing borrows heavily from the code
% previously in contfrac.red

symbolic procedure fix!-negative(n);
 if numberp n then if n < 0 then (-n) . t else list n
 else if eqcar(n, 'minus) then (cadr n) . t
 else list n;
 
symbolic procedure print!-contfract(x);
% printing continued fractions
  if null !*nat or atom x or length x < 4
      or not eqcar(cadddr x,'list) then 'failed
  else << maprin reform!-contfract(x); t>>;

put('contfrac, 'prifn, 'print!-contfract);

symbolic procedure reform!-contfract(x);
% prepare a continued fraction for pretty-printing
begin scalar xx, xxx, origex, conv, coeflist, n;
   origex := cadr x;
   conv := caddr x;
   if conv = origex then conv := "exact";
   coeflist := cadddr x;
    xx := reverse cddr coeflist;
    if length xx > 12 then
       return list('list, origex, conv, cadddr x);

    if xx then <<
       n := fix!-negative(cadr car xx);
       xxx := list('quotient, car n, caddr car xx);
       for each tt in rest xx do <<
          xxx := list('plus, caddr tt,
	               if cdr n then list('minus, xxx) else xxx);
	  n := fix!-negative(cadr tt);
          xxx := list('quotient, car n, xxx)
       >>;
       if cadr coeflist = 0 then
          return list('list, origex, conv,
	               if cdr n then list('minus, xxx) else xxx)
       else 
          return list('list, origex, conv,
	               list('plus, cadr coeflist,
		            if cdr n then list('minus, xxx) else xxx));
    >>
    else
       return list('list, origex, conv, cadr coeflist);
end;

put('contfrac, 'fancy!-reform, 'reform!-contfract);

% Access procedures for various parts of a continued fraction

% Given a continued fraction expansion, returns the originating expression.
symbolic procedure cf!:expr(u);
 << u:=reval car u;
    if eqcar(u, 'contfrac) then cadr u
    else typerr(u, "continued fraction: cf_expression")
 >>;
    
put('cf_expression,'psopfn,'cf!:expr);

% Returns the last convergent of a continued fraction expansion.
symbolic procedure cf!:conv(u);
 << u:=reval car u;
    if eqcar(u,'contfrac) then aeval caddr u
    else typerr(u, "continued fraction: cf_convergent")
 >>;
    
put('cf_convergent,'psopfn,'cf!:conv);


% Returns a list of the continuentsts of a continued fraction
symbolic procedure cf!:coef!-list(u);
 << u:=reval car u;
    if eqcar(u, 'contfrac) then cadddr u
    else typerr(u, "continued fraction: cf_continuents")
 >>;
    
put('cf_continuents,'psopfn,'cf!:coef!-list);

% Returns a list of the convergents of a continued fraction
symbolic procedure cf!:conv!-list(u);
    << u := reval car u;
       if eqcar(u, 'contfrac) then 
          cons('list, reversip cf!:convlist1(cdr cadddr u))
       else
          typerr(u, "continued fraction: cf_convergents")
    >>;

symbolic procedure cf!:convlist1(coeflist);
begin scalar a, l, g, gg, ggg, h, hh, hhh, x, y, !*gcd, !*ezgcd;
    !*gcd := t; !*ezgcd := t;
    a := simp!* car coeflist;
    l := list prepsq a;
    coeflist :=  cdr coeflist;
    if null coeflist then return l;
    gg:= a;  hh := 1 . 1; g := 1 . 1; h := nil . 1;
  
    foreach coef in coeflist do <<
       x := simp!* cadr coef;
       y := simp!* caddr coef;
       ggg := addsq(multsq(y, gg), multsq(x, g));
       hhh := addsq(multsq(y,hh), multsq(x, h));
       g := gg; gg := ggg; h := hh; hh := hhh;
       l := prepsq(quotsq(gg, hh)) . l;
    >>;
    return l;
end;
    
put('cf_convergents,'psopfn, 'cf!:conv!-list);

put ('cf_transform, 'psopfn, 'cf!:transform);

symbolic procedure cf!:transform(u);
  % produce an equivalent continued fraction using a specified list of
  % coefficients {ci} to multiply the ith partial  denominator by ci
  % and modify the partial numerators accordingly.
  % If necessary, the list {ci} is extended to the required length with 1's.
begin scalar l, coeflist, newlist, c, d, a, b, !*gcd, !*ezgcd;
   if length u neq 2 then
      rederr "cf_transform: exactly two arguments are required.";
   l := cadr u;
   u := reval car u;
   if not eqcar(u, 'contfrac) then 
      typerr(u, "continued fraction: cf_transform");
   if not eqcar(l, 'list) then
      rederr "cf_transform: second argument must be a list.";
      
   l := cdr  l;
   coeflist := cdr  cadddr u;
   newlist :=  list car coeflist;
   coeflist := cdr coeflist;
   
   !*gcd := t; !*ezgcd := t;
   d := 1 . 1;
   foreach pr in cdr coeflist do <<
      if l then
         c:= simp!* car l
      else
         c := (1 . 1);
      a := multsq(simp!* cadr pr, multsq(d, c));
      b := multsq(simp!* caddr pr, c);
      newlist := list('list, prepsq a, prepsq b) . newlist;
      if l then l := cdr l;
      d := c;
   >>;
   newlist := 'list . reversip newlist;
   return list('contfrac, cadr u, caddr u, newlist);
end;

symbolic procedure cf!:unit!-num(u);
  % produce an equivalent continued fraction with all partial numerators = 1
begin scalar coeflist, newlist, c, a, b, !*gcd, !*ezgcd;
   u := reval car u;
   if not eqcar(u, 'contfrac) then 
      typerr(u, "continued fraction: cf_unit_num");
   coeflist := cdr cadddr u;
   newlist := list car coeflist;

   !*gcd := t; !*ezgcd := t;
   c := 1 . 1;
   foreach pr in cdr coeflist do <<
      a := simp!* cadr pr;
      c := invsq multsq(c, a);
      b := multsq(simp!* caddr pr, c);
      newlist := list('list, 1, prepsq b) . newlist;
   >>;
   newlist := 'list . reversip newlist;
   return list('contfrac, cadr u, caddr u, newlist);     
end;   

symbolic procedure cf!:unit!-den(u);
  % produce an equivalent continued fraction with all partial denominators = 1
begin scalar coeflist, newlist, d, c, a, b, !*gcd, !*ezgcd;
   u := reval car u;
   if not eqcar(u, 'contfrac) then 
      typerr(u, "continued fraction: cf_unit_den");
   coeflist := cdr cadddr u;
   newlist := list car coeflist;

   !*gcd := t; !*ezgcd := t;
   d := 1 . 1;
   foreach pr in cdr coeflist do <<
      b := simp!* caddr pr;
      c := multsq(d, b);
      a := quotsq(simp!* cadr pr, c);
      newlist := list('list, prepsq a, 1) . newlist;
      d := b;
   >>;
   newlist := 'list . reversip newlist;
   return list('contfrac, cadr u, caddr u, newlist);     
end;   

put('cf_unit_numerators, 'psopfn, 'cf!:unit!-num);
put('cf_unit_denominators, 'psopfn, 'cf!:unit!-den);

symbolic procedure cf!:remove!-fracs(u);
  % produce an equivalent continued fraction with all
  % partial numerators & denominators integer.
begin scalar coeflist, newlist, numprs, a, b, c;
   u := reval car u;
   if not eqcar(u, 'contfrac) then 
      typerr(u, "continued fraction: cf_remove_fractions");
      
   coeflist := cdr cadddr u;
   newlist := list car coeflist;
   coeflist := cdr coeflist;
   numprs := length coeflist;

   c := 1 . 1;
   for n := 1 : numprs do <<
      a := simp!* cadar coeflist;
      b := simp!* caddar coeflist;
      
      a := multsq(c, a);
			
      c := quotsq(multf(cdr a, cdr b) . 1, gcdf(cdr a, cdr b) . 1);
      a := multsq(a, c); b := multsq(b, c);
      
      newlist := list('list, prepsq a, prepsq b) . newlist;
      coeflist := cdr coeflist;
   >>;

   newlist := 'list . reversip newlist;
   return list('contfrac, cadr u, caddr u, newlist);
end;   

put('cf_remove_fractions, 'psopfn, 'cf!:remove!-fracs);
put('cf_remove_constant, 'psopfn, 'cf!:remove!-const);

symbolic procedure cf!:remove!-const(u);
  % produce an equivalent continued fraction with all
  % partial numerators & denominators integer.
begin scalar coeflist, newlist, a, b, c, d, cc, aa, a0;
   u := reval car u;
   if not eqcar(u, 'contfrac) then 
      typerr(u, "continued fraction: cf_remove_constant");
      
   coeflist := cdr cadddr u;
   a0 := car coeflist;
   if a0 = 0 then return u;
 
   a0 := simp!* a0;
   newlist := list 0;
   coeflist := cdr coeflist;

   if null coeflist then <<
      newlist := list('list, prepsq a0, 1) . newlist;
      return list('contfrac, cadr u, caddr u,'list . reversip newlist);
   >>;
      
   a := simp!* cadar coeflist;
   b := simp!* caddar coeflist;
   cc := addsq(multsq(a0, b), a);  
   newlist := list('list, prepsq cc, prepsq b) . newlist;
   coeflist := cdr coeflist;

   if null coeflist then
      return list('contfrac, cadr u, caddr u,'list . reversip newlist);
   aa := a;   
   a := simp!* cadar coeflist;
   b := simp!* caddar coeflist;
   c := multsq(a, aa);
   d := addsq(multsq(a0, a), multsq(cc, b));
   newlist := list('list, prepsq c, prepsq d) . newlist;
   coeflist := cdr coeflist;
   
   if null coeflist then
      return list('contfrac, cadr u, caddr u,'list . reversip newlist);
   a := simp!* cadar coeflist;
   b := caddar coeflist;
   c := multsq(cc, a);
   newlist := list('list, prepsq c, b) . newlist;

   newlist := append('list . reversip newlist, cdr coeflist);
   return list('contfrac, cadr u, caddr u, newlist);
end;   

symbolic procedure cf!:even!-odd(u);
  % produce the odd and even parts of a continued fraction.
begin scalar coeflist, oddlist, evenlist, numterms, conv,
             m, a, aa, aaa, b, bb, bbb, c, d, cc, c1, c2;
   u := reval car u;
   if not eqcar(u, 'contfrac) then 
      typerr(u, "continued fraction: cf_even_odd");
      
   coeflist := cdr cadddr u;
   numterms := length coeflist;
   m := numterms;

   evenlist := list car coeflist;
   oddlist := list car coeflist;
   
   coeflist := cdr coeflist;
   m := m-1;
   if m = 0 then goto done;
    
   aa := simp!* cadar coeflist;
   bb := simp!* caddar coeflist;
   cc := quotsq(multf(cdr aa, cdr bb) . 1, gcdf(cdr aa, cdr bb) . 1);
   c := multsq(cc, aa); d:= multsq(cc, bb);
   c1 := cc;
   oddlist := list('list, prepsq c, prepsq d) . oddlist;
   
   coeflist := cdr coeflist;
   m := m - 1;
   if m = 0 then goto done;

   a := simp!* cadar coeflist;
   b := simp!* caddar coeflist;
   c := multsq(aa, b);
   d := addsq(multsq(b, bb), a);
   cc := quotsq(multf(cdr c, cdr d) . 1, gcdf(cdr c, cdr d) . 1);
   c := multsq(cc, c); d:= multsq(cc, d);
   c2 := cc;   
   evenlist := list('list, prepsq c, prepsq d) . evenlist;

   coeflist := cdr coeflist;
   m := m - 1;
   if m = 0 then goto done;

   aa := a; bb := b;
   a := simp!* cadar coeflist;
   b := simp!* caddar coeflist;
   c := multsq(c1, multsq(aa, b));
   d := addsq(multsq(b, bb), a);
   cc := quotsq(multf(cdr c, cdr d) . 1, gcdf(cdr c, cdr d) . 1);
   c := multsq(cc, c); d:= multsq(cc, d);
   c1 := cc;
   oddlist := list('list, prepsq c, prepsq d) . oddlist;
   m := m - 1;

   cc := c2;
   for n := 1  : m do <<
      coeflist := cdr coeflist;
      aaa := aa; aa := a; bbb := bb; bb := b;
      a := simp!* cadar coeflist;
      b := simp!* caddar coeflist;
      
      c := negsq multsq(cc, quotsq(multsq(b, multsq(aa, aaa)), bbb));

      d := quotsq(addsq(multsq(b, multsq(bb, bbb)),
                        addsq(multsq(a, bbb), multsq(aa, b))), bbb);
			
      cc := quotsq(multf(cdr c, cdr d) . 1, gcdf(cdr c, cdr d) . 1);
      c := multsq(cc, c); d:= multsq(cc, d);
      
      if evenp n then <<
          c1 := cc;
          oddlist := list('list, prepsq c, prepsq d) . oddlist;
	  cc := c2;
      >>
      else <<
          c2 := cc;
          evenlist := list('list, prepsq c, prepsq d) . evenlist;
	  cc := c1;
      >>;
   >>;
done:
   oddlist := 'list . reversip oddlist;
   evenlist := 'list . reversip evenlist;
   if evenp numterms then <<
      conv := car cf!:convlist1 cdr evenlist;
      evenlist := list('contfrac, cadr u, conv, evenlist);
      oddlist := list('contfrac, cadr u, caddr u, oddlist);
   >>
   else <<
      conv := car cf!:convlist1 cdr oddlist;
      oddlist := list('contfrac, cadr u, conv, oddlist);
      evenlist := list('contfrac, cadr u, caddr u, evenlist)
   >>;
   oddlist := cf!:remove!-const list oddlist;
   return list('list, evenlist, oddlist);     
end;   

put('cf_even_odd, 'psopfn, 'cf!:even!-odd);

put('cf_euler, 'psopfn, 'cf!:euler);

symbolic procedure cf!:euler(u);
  %  generate a continued fraction using Euler's formula.
begin scalar v, x, n;
  if length u < 2 then
     rederr "cf_euler: 2 or 3 args needed -- expression, variable, [integer]";
  x := cadr u;
  if not idp x or flagp(x, 'constant) then
     rederr  "cf_euler: second arg must be a variable";
  if cddr u then <<
     n := ieval caddr u;
     if n leq 0 then
        rederr "cf!:euler: third argument must be a positive integer";
     >>
  else
     n := 6;
    
  v := cf!:euler1(car u, x, n);
  
  return 'contfrac . list(car u, car cf!:convlist1 v, 'list . v);
end;

symbolic procedure cf!:euler1(u, x, n);
begin scalar coeflist, ps, nextterm, lastterm, a, b, c, d, j, k;
  ps := car simpps1(u, x, 0);  
  j := ps!:find!-order(ps);
  coeflist := list 0;
  
  nextterm := ps!:get!-term(ps, j);
  
  if j >= 0 then <<
     if j > 0 then
        nextterm := multsq(!*p2q(x to j), nextterm);
     a := nextterm;
     d := 1 . 1;
  >>
  else << 
     d := !*p2q(x to -j);
     a := nextterm;
     nextterm := multsq(invsq d, nextterm);
  >>;
  b := d;

  coeflist := list('list, prepsq a, prepsq b) . coeflist;
  
  c := d;
  for i := 2 : n do <<
     lastterm := nextterm;
     k := 0;
     repeat <<
        j := j + 1;
	k := k + 1;
        nextterm := ps!:evaluate(ps, j);
     >>	
     until nextterm neq (nil . 1)  or k = ps!:order!-limit;

     if nextterm = nil . 1 then  <<
        print "ps_euler: power series is very sparse  -- terminating early";
        goto done;
     >>
     else if j >= 0 then <<
        d := 1 . 1;
	if j >0 then
           nextterm := multsq(!*p2q(x to j), nextterm);
     >>
     else <<
        d := !*p2q(x to -j);
        nextterm := multsq(invsq d, nextterm);
     >>;
     a := quotsq(nextterm, lastterm);

     if j >= 0 then
        b := addsq(1 . 1, a)
     else << 
        a := multsq(a, d);
	b := addsq(d, a);
     >>;     
     coeflist :=
         list('list, prepsq negsq multsq(c, a), prepsq b) . coeflist;
     c := d;
   >>;
done:
     return reversip coeflist;

end;

endmodule;

end;


