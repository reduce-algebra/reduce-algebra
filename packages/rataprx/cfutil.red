module cfutil;
% Various utilities for continued fractions
% A. Barnes, February 2019

% New wrapper for contfract1 to facilitate pretty-printing &
% the impementation of various access functions.

symbolic procedure con!-frac u;
begin scalar cfr, v;
   v := contfract1(car u, if cdr u then ieval cadr u);
   cfr := list(car u, list('quotient, caar v, cdar v), 'list . cdr v);
   return cons('confrac1, cfr);
end;

symbolic procedure simpcf u;
begin scalar arg2;
  arg2 := aeval cadr u;
  u:= list('confrac1, car u, arg2, caddr u);
  return !*k2q u;
end;

put('confrac1, 'simpfn, 'simpcf);

put('cf,'psopfn,'con!-frac);

% The following code for printing borrows heavily from the code in contfrac.red

symbolic procedure print!-confrac(x);
% print a continued fraction
  begin scalar xx, xxx, coeflist;
    if null !*nat or atom x or length x < 4
        or not eqcar(cadddr x,'list)
        then return 'failed;
    coeflist := cadddr x;
    xx := reverse cddr coeflist;
    if length xx > 12 then <<
      maprin list('list, cadr x, caddr x, cadddr x);
      return t>>;
    if xx then <<
        xxx := list('quotient, 1, car xx);
        for each tt in rest xx do
           xxx := list('quotient, 1, list('plus, tt, xxx));
        if cadr coeflist = 0 then
          maprin list('list, cadr x, caddr x, xxx)
        else
          maprin list('list, cadr x, caddr x, list ('plus, cadr coeflist, xxx));
     >>
     else
       maprin list('list, cadr x, caddr x, cadr coeflist);
    return t;
   end;

put('confrac1, 'prifn, 'print!-confrac);

symbolic procedure reform!-confrac(x);
% prepare a continued fraction for pretty-printing
begin scalar xx, xxx, coeflist;
    coeflist := cadddr x;
    xx := reverse cddr coeflist;
    if length xx > 12 then
       return list('list, cadr x, caddr x, cadddr x);
    if xx then <<
       xxx := list('quotient, 1, car xx);
       for each tt in rest xx do
          xxx := list('quotient, 1, list('plus, tt, xxx));
       if cadr coeflist = 0 then
          return list('list, cadr x, caddr x, xxx)
       else
          return list('list, cadr x, caddr x, list ('plus, cadr coeflist, xxx));
     >>
     else
        return list('list, cadr x, caddr x, cadr coeflist);
end;

put('confrac1,'fancy!-reform, 'reform!-confrac);

symbolic procedure print!-contfract(x);
% printing continued fractions
  begin scalar xx, xxx, coeflist;
    coeflist := caddr x;
    if null !*nat or atom x or length x < 3
        or not eqcar(caddr x,'list)
        then return 'failed;
    xx := reverse cddr coeflist;
    if length xx > 12 then <<
         maprin list('list, cadr x, caddr x); 
         return t>>;
    if xx then <<
        xxx := list('quotient, cadr car xx, caddr car xx);
        for each tt in rest xx do
          xxx := list('quotient, cadr tt, list('plus, caddr tt, xxx));
        if cadr coeflist = 0 then
	  maprin list('list, cadr x, xxx)
	else
          maprin list('list, cadr x, list ('plus, cadr coeflist, xxx));
     >>
     else
       maprin list('list, cadr x, cadr coeflist);
     return t;
   end;

put('contfrac, 'prifn, 'print!-contfract);

% symbolic procedure print!-contfract-old(x);
% % printing continued fractions
%   begin scalar xx,xxx;
%     if null !*nat or atom x or length x < 3
%         or not eqcar(caddr x,'list)
%         then return 'failed;
%     xx := reverse cddr caddr x;
%     if length xx > 12 then  return 'failed;
%     if xx then
%      <<xxx := list('quotient ,cadr first xx,caddr first xx);
%        for each tt in rest xx do
%          xxx := list('quotient ,cadr tt,list('plus,caddr tt,xxx));
%        if cadr caddr x = 0 then maprin list('list,cadr x,xxx) else
%         maprin list('list,cadr x,list ('plus,cadr caddr x ,xxx));
%      >> else maprin list('list,cadr x,cadr caddr x);
%     return t;
%    end;
% 
% put('contfrac,'prifn,'print!-contfract-old);
% 

symbolic procedure reform!-contfract(x);
% prepare a continued fraction for pretty-printing
begin scalar xx, xxx, coeflist;
    coeflist := caddr x;
    xx := reverse cddr coeflist;
    if length xx > 12 then
       return list('list, cadr x, caddr x);
    if xx then <<
       xxx := list('quotient, cadr car xx, caddr car xx);
       for each tt in rest xx do
          xxx := list('quotient, cadr tt, list('plus, caddr tt, xxx));
       if cadr coeflist = 0 then
          return list('list, cadr x, xxx)
       else
          return list('list, cadr x, list('plus, cadr coeflist, xxx));
     >>
     else
        return list('list, cadr x, cadr coeflist);
end;

put('contfrac, 'fancy!-reform, 'reform!-contfract);

% Access procedures for various parts of a continued fraction

symbolic procedure cf!:listp u;
begin scalar v, b;
  if eqcar(u, 'list) and length u = 3 then <<
     v := caddr u;
     if eqcar(v, 'list) then <<
        b := t; v := cdr v;
        while b and v do <<
	  if not fixp(car v) then b := nil;
	  v := cdr v>>;
	return b;
     >>;
  >>;
  return nil;
end;

% Given a continued fraction expansion, returns the originating expression.
symbolic procedure cf!:expr(u);
 << u:=reval car u;
    if eqcar(u, 'confrac1) then cadr u
    else if eqcar(u, 'contfrac) or cf!:listp u then
      rederr("Operation not supported for this type of continued fraction")
    else typerr(u, "continued fraction: cf_expression")
 >>;
    
put('cf_expression,'psopfn,'cf!:expr);

% Returns the last convergent of a continued fraction expansion.
symbolic procedure cf!:conv(u);
 << u:=reval car u;
    if eqcar(u,'confrac1) then caddr u
    else if eqcar(u, 'contfrac) or cf!:listp u then cadr u
    else typerr(u, "continued fraction: cf_expression")
 >>;
    
put('cf_convergent,'psopfn,'cf!:conv);


% Returns a list of the coefficients of a continued fraction
symbolic procedure cf!:coef!-list(u);
 << u:=reval car u;
    if eqcar(u, 'confrac1) then cadddr u
    else if eqcar(u, 'contfrac) or cf!:listp u then caddr u
    else typerr(u, "continued fraction: cf_coeflist")
 >>;
    
put('cf_coeflist,'psopfn,'cf!:coef!-list);

symbolic procedure cfrac!:listp u;
begin scalar v, b;
  if eqcar(u, 'contfrac) and length u = 3 then <<
     v := caddr u;
     if eqcar(v, 'list) then <<
        b := t; v := cdr v;
	if not fixp(car v) then return nil
	else <<
	   v := cdr v;
           while b and v do <<
	      if not eqcar(car v, 'list) or length car v neq 3
	         or not fixp(cadar v) or not fixp(caddar v) then b := nil;
	      v := cdr v;
	   >>;
	   return b;
        >>;
     >>;
  >>;
  return nil;
end;

% Returns a list of the convergents of a continued fraction
symbolic procedure cf!:conv!-list(u);
begin scalar coeflist, a, l, g, gg, ggg, h, hh, hhh, x, y;
    u:=reval car u;
    if eqcar(u, 'confrac1) then coeflist := cdr cadddr u
    else if eqcar(u, 'contfrac) then 
      (if not cfrac!:listp u then
         rederr("Operation not supported for non-constant continued fractions")
       else
         coeflist := cdaddr u)
    else if cf!:listp u then coeflist := cdaddr u
    else typerr(u, "continued fraction: cf_convlist");

    a:= car coeflist; l := list a;
    coeflist :=  cdr coeflist;
    if null coeflist then return l;
    gg:=a;  hh:=1; g:=1; h:=0;
  
    if  fixp car coeflist then
       foreach coef in coeflist do <<
           ggg := coef*gg + g; hhh := coef*hh + h;
           g := gg; gg:=ggg; h:=hh; hh:=hhh;
	   l := list('quotient, gg, hh) . l;
       >>
    else
       foreach coef in coeflist do <<
           x := cadr coef; y := caddr coef;
           ggg := y*gg + x*g; hhh := y*hh + x*h;
           g := gg; gg:=ggg; h:=hh; hh:=hhh;
	   l := list('quotient, gg, hh) . l;
       >>;
       return 'list . reversip l;

end;
    
put('cf_convlist,'psopfn,'cf!:conv!-list);

endmodule;

end;

