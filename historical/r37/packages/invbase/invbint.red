module invbint; % Algebraic mode interface to invbase.

symbolic procedure invtorder u;
  begin scalar w,o;
    w := reval car u;
    o := assoc(w,'((gradlex . glex) (revgradlex .grev) (lex . lex)));
    if null o then typerr(w,"involutive term ordering");
    ordering := cdr o;
    invsysvars!* := 
     if cdr u then 
      for each y in cdr listeval (cadr u,nil) collect reval y
       else nil;
  end;

put('invtorder,'stat,'rlis);

symbolic procedure invbase u;
  begin scalar sys,vars,r;
    u := reval car u;
    if not eqcar(u,'list) then rederr "Argument to invbase not a list";
    sys := for each p in cdr u collect 
     <<p := reval p;
       if eqcar(p,'equal) then p:=reval{'difference,cadr p,caddr p};
       p>>;
   % find the variables.
   vars := invsysvars!* or gvarlis sys;
   readsys('list.sys,'list.vars);
   invbase!*();
   r:= for each p in gg collect 
     'plus . for each m in getv(gv,car p) collect
        prepsq !*di2q(list m,vars); 
  return 'list . r;
 end;

put('invbase,'psopfn,'invbase);

symbolic procedure invlex u;
  begin scalar sys,vars,r;
    u := reval car u;
    if not eqcar(u,'list) then rederr "Argument to invlex not a list";
    sys := for each p in cdr u collect 
     <<p := reval p;
       if eqcar(p,'equal) then p:=reval{'difference,cadr p,caddr p};
       p>>;
   % find the variables.
   vars := invsysvars!* or gvarlis sys;
   readsys('list.sys,'list.vars);
   invlex!*();
   (r:= for each p in gg collect 
     'plus . for each m in getv(gv,car p) collect
        prepsq !*di2q(list m,vars)) where ordering='lex; 
  return 'list . r;
 end;

put('invlex,'psopfn,'invlex);

symbolic procedure invtest u;
  begin scalar sys,vars,r;
    u := reval car u;
    if not eqcar(u, 'list) then rederr "Argument to invtest not a list";
    sys := for each p in cdr u collect 
     <<p := reval p;
       if eqcar(p,'equal) then p:=reval{'difference,cadr p,caddr p};
       p>>;
   % find the variables.
   vars := invsysvars!* or gvarlis sys;
   readsys('list.sys,'list.vars);
   return invtest!*();
 end;

put('invtest,'psopfn,'invtest);

% the following procedure are borrowed from the groebner package:

symbolic procedure gvarlis u;
   % Finds variables (kernels) in the list of expressions u.
   sort(gvarlis1(u,nil),function ordop);

symbolic procedure gvarlis1(u,v);
   if null u then v
    else union(gvar1(car u,v),gvarlis1(cdr u,v));

symbolic procedure gvar1(u,v);
   if null u or numberp u or (u eq 'i and !*complex) then v
    else if atom u then if u member v then v else u . v
    else if get(car u,'dname) then v
    else if car u memq '(plus times expt difference minus)
     then gvarlis1(cdr u,v)
    else if car u eq 'quotient then gvar1(cadr u,v)
    else if u member v then v
    else u . v;

endmodule;

end;
