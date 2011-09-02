module newton;  % root finding with generalized Newton methods.

% Author: H. Melenk, ZIB, Berlin

% Copyright (c): ZIB Berlin 1992, all rights resrved
% Version 2: termination and damping criterion modified to affine
%            invariance.
% Nov. 94:   Avoid symbolic inversion of Jacobian.

fluid '(!*noequiv accuracy!* !*invjacobi);
global '(iterations!* !*trnumeric erfg!*);


symbolic procedure rdnewton0(e,vars,p,n);
    %preparations for Newton iteration.
 (begin scalar jac,x,oldmode,!*noequiv;
    integer prec;
    if not memq(dmode!*,'(!:rd!: !:cr!:))then
       <<oldmode:=t; setdmode('rounded,t)>>;
    prec:=precision 0;
    p := for each x in p collect
         force!-to!-dm numr simp x;
    if !*trnumeric then lprim "computing symbolic Jacobian";
    eval list('matrix,mkquote list list('jacobian,n,n));
    for i:=1:n do for j:=1:n do
        setmatelem(list('jacobian,i,j),
         reval list('df,nth(e,i),nth(vars,j)));
    if !*trnumeric and !*invjacobi
      then lprim "inverting symbolic Jacobian";
    jac := cdr reval 
      if !*invjacobi then '(quotient 1 jacobian) else 'jacobian;
    jac := for each r in jac collect
       for each c in r collect reval c;
    !*noequiv:=t;
    x := rdnewton1(e,jac,vars,p,'root);
    if oldmode then setdmode('rounded,nil);
    precision prec;
    if null x then rederr "no solution found";
    return 'list.
       for each p in pair(vars,x) collect
          list('equal,car p,cdr p);
  end) where !*roundbf=!*roundbf;

symbolic procedure rdnewton1(f,jac,vars,x,mode);
  begin scalar r,acc;
     if !*trnumeric then lprim "starting Newton iteration";
     acc := !:!:quotient(1,expt(10,accuracy!*));
     r:= rdnewton2(f,jac,vars,acc,x,mode,nil,nil);
     r:= for each x in r collect prepf x;
     return r;
 end;

symbolic procedure rdnewton2(f,jac,vars,acc,x,mode,low,high);
  % Algorithm for finding the root function system f
  % with technique of adaptively damped Newton.
  % f:     function to minimize (list of algebraic exprs);
  % jac:   Jacobian, symbolically inverted if *invjacobi is t;                    
  % vars:  variables (list of id's);
  % acc:   requested accuracy (e.g. 0.0000001)
  % x:     starting point (list of domain elements).
 dm!:
  begin scalar n0,n1,e0,e1,dx,dx2,x1,g,dmp,delta,h;
        scalar dxold,dx2old,dmpold;
    integer count;
    mode := nil;
    e0 := list!-evaluate(f,vars,x);
  loop:
    count:=add1 count;
    if count>iterations!* then
    <<lprim "requested accuracy not reached within iteration limit";
      goto ready>>;

      % evaluate Jacobian.
    g := matrix!-evaluate(jac,vars,x);
      % the newton step.
    dx := if !*invjacobi then mat!*list(g,e0) else rdsolvelin(g,e0);  
    if null dx then goto jacerr;  
    n0 := normlist dx;
    dmp:= 1;

  step:
      % evaluate function at new point.
    x1 := list!-list(x, scal!*list(dmp,dx));
    e1 := errorset({'list!-evaluate,mkquote f,
              mkquote vars,mkquote x1},nil,nil)
                       where !*msg=nil,!*protfg=t;;
    if errorp e1 then goto contract else e1 := car e1;

        % anticipated next (simplified) Newton step.
    dx2:=if !*invjacobi then mat!*list(g,e1) else rdsolvelin(g,e1);
    if null dx2 then goto contract; 
    n1 := normlist(dx2);
    if n1=0 or n1<n0 then goto accept;
    if null dmpold then goto contract;

       % predict optimal damping factor
    h:= dmpold *(normlist list!-list(dx2old,dx) * normlist(dx))
        / (normlist(dxold) * normlist(dx2old));
    if h>1 then
    << dmp:=if h<10 then 1/h else 1/10;
       dmpold := nil; goto step>>;

  contract:
    dmp:=dmp/2;
    if dmp<acc then rederr "Newton method does not converge";
    goto step;

  accept:
    delta:=dmp*n0;
    x := x1; e0:=e1; n0:=n1;
    if low and high and (low>car x or high<car x) then return nil;
    dmpold := dmp; dxold := dx; dx2old := dx2;
    rdnewtonprintpoint(count,x,delta,e0);
    if n1>acc or dmp<1 then<<update!-precision(delta.e0); goto loop>>;

  ready:
    x := list!-list(x,dx2);
    return x;

  jacerr: rederr "singular Jacobian";  
  end;

symbolic procedure rdnewtonprintpoint(count,x,dx,e0);
  if !*trnumeric then
   begin 
    writepri(count,'first);
    writepri(". residue=",nil);
    printsflist e0;
    writepri(", step length=",nil);
    writepri(mkquote prepf dx,'last);
    writepri(" at ",nil);
    printsflist x;
    writepri(" ",'last);
   end;

endmodule;

end;
