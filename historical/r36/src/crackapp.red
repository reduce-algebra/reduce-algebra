module crackapp;   %  Applications of CRACK.

create!-package('(crackapp decomp firstint lagrange pdesymm),
                '(contrib crack));

symbolic fluid '(print_ logoprint_ nfct_ fname_)$
load_package odesolve$
load_package ezgcd$
load_package factor$

%----------------------------

symbolic operator aread$
symbolic procedure aread(prompt)$
begin scalar val, !*echo;  % Don't re-echo tty input
 rds nil; wrs nil$         % Switch I/O to terminal
 terpri()$
 if null prompt then prompt:= "Input:"; prin2 prompt;
 val := xread(nil)$
 if ifl!* then rds cadr ifl!*$  %  Resets I/O streams
 if ofl!* then wrs cdr ofl!*$
 return val
end$

%----------------------------

algebraic procedure equ_to_expr(a)$
% converts an equation into an expression
begin scalar lde;
 return
 if a=nil then a else
 <<lisp(lde:=reval algebraic a);
  if lisp(atom lde) then a else num
  if lisp(car lde = 'equal) then lhs a - rhs a
              else a
 >>
end$ % of equ_to_expr

%----------------------------

algebraic procedure sub_in_equ(su,a)$
% make the substitution su in a where a may be an equation
begin scalar lde;
 return
 if a=nil then a else
 <<lisp(lde:=reval algebraic a);
  if lisp(atom lde) then sub(su,a) else
  if lisp(car lde = 'equal) then sub(su,lhs a)=sub(su,rhs a)
              else sub(su,a)
 >>
end$ % of sub_in_equ

%----------------------------

algebraic procedure maklist(ex)$
% making a list out of an expression if not already
if lisp(atom algebraic ex) then {ex} else
if lisp(car algebraic ex neq 'list) then ex:={ex}
                                    else ex$

endmodule;


module decomp;  % Routines for decomposition of ODE's.

%  Author: Thomas Wolf
%  Jan 1994

algebraic procedure decomp(problem,runmode);
begin scalar i,j,k,de,m,n,x,y,yy,yyy,new!_d!_yk,as,sol,h1,h2,dep$
  lisp put('d!_y,'simpfn, 'simpiden)$
  lisp put('u!#,'simpfn, 'simpiden)$
  de:=first problem$ problem:=rest problem$
  y :=first problem$ problem:=rest problem$
  x :=first problem$ problem:=0$
  as:=first runmode$ runmode:=rest runmode$
  fl:=first runmode$ runmode:=0$
  symbolic write "Differential factorization of:  "$
  lisp terpri()$
  write de$
  k:=1;    % factorization into a first-order ODE + ...
  clear d1!_;
  de:=equ_to_expr(de)$
  n:=totdeg(de,y)$
  for i:=2:n do <<de:=sub(df(y,x,i)=d!_y(i),de);
                  as:=sub(df(y,x,i)=d!_y(i),as)>>;
  de:=sub(df(y,x)=d!_y(1),de);
  as:=sub(df(y,x)=d!_y(1),as);
  yy:=lisp if atom (yyy:=reval algebraic y) then yyy
                                            else car yyy;
  if (y neq yy) then << let y=yy; de:=de; as:=as; clear y; y:=yy >>;
  depend a!#,x;
  depend b!#,x;
  depend c!#,x;
  depend d!#,y;
  d!_y(k):=
  if as=1 then <<fl:={a!#,d!#};     a!#*d!#            >> else
  if as=2 then <<fl:={a!#,b!#};     a!#*y+b!#          >> else
  if as=3 then <<fl:={a!#,b!#};     a!#*y**d1!_+b!#*y  >> else
  if as=4 then <<fl:={a!#,b!#,c!#}; a!#*y**2+b!#*y+c!# >> else
  as$
  vl:={y,x};
  for i:=1:(k-1) do vl:=.(d!_y(i),vl);
  new!_d!_yk:=d!_y(k)$
  write "The ansatz: ", df(y,x)," = ",d!_y(k);
  if df(yy,x) neq 0 then <<dep:=1;nodepend yy,x>> else dep:=0;
  for m:=k+1:n do
  d!_y(m):=df(d!_y(m-1),x)+df(d!_y(m-1),y)*d!_y(1)+
           for j:=1:k-1 sum df(d!_y(m-1),d!_y(j))*d!_y(j+1);
  de:=de;
  for m:=k:n do clear d!_y(m);

  sol:=crack({de},{},fl,vl);   % first, because {a} is linear
  if sol={} then <<
   write"There exists no such factorization.";
   return {}
  >>        else <<
   sol:=first sol;
   h1:=second sol;
   for each h2 in h1 do
   if symbolic (not atom reval algebraic h2) then
   if symbolic (equal(car reval algebraic h2,'equal)) then
   new!_d!_yk:=sub(h2,new!_d!_yk)$
   if dep=1 then depend yy,x;
   new!_d!_yk:=sub(d!_y(1)=df(y,x),new!_d!_yk);
   for i:=2:n do new!_d!_yk:=sub(d!_y(i)=df(y,x,i),new!_d!_yk);
   h1:=first sol$
   if h1 neq {} then
   <<write "Remaining conditions:";
     while h1 neq {} do <<write"0 = ",first h1;h1:=rest h1>> >>;
   !!arbconst:=0;
   h1:=df(y,x,k)-new!_d!_yk  ;
   h2:=first odesolve(h1,y,x);
   if h1=h2 then write "The solution of ",df(y,x,k)," = ",new!_d!_yk
            else
   <<yyy:=mkid(lisp fname!_,lisp nfct!_);
     h2:=sub(arbconst(1)=yyy,h2);
     lisp(nfct!_:=add1 nfct!_);
     write "The solution ",h2>>;
   if length third sol<(n-k)                         then
   write "is a special solution of the original ODE" else
   if length first sol = 0                             then
   write "is the general solution of the original ODE" else
   write "is a solution of the original ODE";
   h1:=first sol;
   return {h1,new!_d!_yk,third sol} >>
end$

symbolic procedure lesedec;
begin scalar c;
  <<rds nil;wrs nil;
    terpri();write "Input: "$
    c:=xread(nil);
    if ifl!* then rds cadr ifl!*;
    if ofl!* then wrs cdr ofl!* >>;
return c
end$

endmodule;


module firstint;  % Routines for finding first integrals of ODE's.

%  Author: Thomas Wolf
%  Jan 1994

algebraic procedure firint(problem,runmode)$
%de...das DGL-Problem, n...Ordnung der DGL, r...Grad des Ansatzes
begin scalar de,n,x,y,yy,yyy,fl,vl,f!_new,a,sol,h1,h2,co,newfl,fi,dg,
             dep$
  symbolic put('d!_y,'simpfn,'simpiden)$
  de:=first problem$ problem:=rest problem$
  y:=first problem$ problem:=rest problem$
  x:=first problem$ problem:=0$
  fi:=first runmode$ runmode:=rest runmode$
  fl:=first runmode$ runmode:=rest runmode$
  dg:=first runmode$ runmode:=0$
  vl:={x,y}$
  lisp terpri()$
  write "Determination of a first integral for: ";
  write de;
  de:=equ_to_expr(de)$
  n:=totdeg(de,y);
  for i:=2:n do <<de:=sub(df(y,x,i)=d!_y(i),de);
                  fi:=sub(df(y,x,i)=d!_y(i),fi)>>;
  de:=sub(df(y,x)=d!_y(1),de);
  fi:=sub(df(y,x)=d!_y(1),fi);

  yy:=lisp if atom (yyy:=reval algebraic y) then yyy
                                            else car yyy;
  if (y neq yy) then << let y=yy; de:=de; fi:=fi; clear y; y:=yy >>;
  if fi=0 then <<
    fi:=polyans(n-1,dg,x,y,d!_y,h!_);
    fl:=second fi;
    fi:=first fi
  >>;
  symbolic if print_ then
  algebraic write "of the type: ",sub(d!_y(1)=df(y,x),fi) ;
  if df(yy,x) neq 0 then <<dep:=1;nodepend yy,x>> else dep:=0;
  a:=df(fi,x)+df(fi,y)*d!_y(1)+
     for k:=1:n-1 sum
     <<vl:=.(d!_y(k),vl); df(fi,d!_y(k))*d!_y(k+1)>>;

  sol:=crack({num sub(first solve(a,d!_y(n)),de)},{},fl,vl);
  % first, because {a} is linear
  if sol={} then <<
    write"There exists no such first integral.";
    return {} >>
            else <<
    sol:=first sol;
    h1:=second sol;
    for each h2 in h1 do
    % if symbolic (not atom algebraic h2) then
    % if symbolic (equal(car algebraic h2,'equal)) then
    fi:=sub(h2,fi)$
    h1:=third sol;
    newfl:={};
    for each h2 in h1 do
    if (df(h2,y) eq 0) and (df(h2,x) eq 0) and (df(h2,d!_y 1) eq 0) then
    <<on ratarg;
      co:=coeffn(fi,h2,1);
      if my_freeof(co,x) and my_freeof(co,y) and my_freeof(co,d!_y 1)
         and deg(fi-co*h2,h2)=0 then fi:=sub(h2=0,fi)
                           else newfl:=.(h2,newfl)>>;
    h1:=newfl;
    newfl:={};
    for each h2 in h1 do
    if (df(h2,y) eq 0) and (df(h2,x) eq 0) and (df(h2,d!_y 1) eq 0) then
    if df(fi/h2,h2)=0 then fi:=sub(h2=1,fi)
                      else newfl:=.(h2,newfl);
    if my_freeof(fi,x) and my_freeof(fi,y) and my_freeof(fi,d!_y 1)
      then fi:=0;
    printco(first(sol));
    if dep=1 then depend yy,x;
    if fi neq 0 then
    <<co:=df(fi,d!_y 1);
      fi:=sub(d!_y(1)=df(y,x),fi);
      co:=sub(d!_y(1)=df(y,x),co);
      for i:=2:n do
      <<fi:=sub(d!_y(i)=df(y,x,i),fi);
        co:=sub(d!_y(i)=df(y,x,i),co)>>;
      write"A first integral is:  ",fi;
      write"and an integrating factor:  ",co;
      if (third sol neq {}) then
      <<lisp terpri();
        if (first sol neq {})
        then lisp write "functions and constants to be determined: "
        else lisp write "free constants: ";
                        lisp fctprint(cdr reval algebraic newfl)>>
    >>
    else write"There exists no such first integral.";
    return {first sol,fi,newfl}
  >>
%>>
% else
%    <<write "Implicit d.e. ! "$
%    return {{},{},{}}>>
end$

algebraic procedure printco(sol)$
if (sol neq {}) then
<<write "Remaining conditions:";
  while sol neq {} do <<write"0 = ",first sol;sol:=rest sol>> >>$

endmodule;


module lagrange;  % Routines for finding a Lagrangian for a given ODE.

%  Author: Thomas Wolf
%  Jan 1994

symbolic operator deprint$
symbolic operator newfct$
symbolic operator freeoflist$

algebraic procedure hamilton(l,qlist,x)$

Comment:
This is a procedure which for a given first order Lagrangian L in the
unknown functions given in the list q of the variable x
- calculates the velocities in terms of the corresponding generalized
  impulses p_ and the Hamiltonian H(p_,q,x),
- formulates the corresponding Hamilton Jacobi equation for a
  for an action function S_.
After execution the q's in qlist are scalars independent of x! ;

begin
  scalar qcopy,i,j,q,dq,plist,n,dqlist,found,sf,sans,solved,h;
  symbolic put('p_,'simpfn,'simpiden)$      % p_(i) : general. impulses
  symbolic put('dq_,'simpfn,'simpiden)$     % dq(i) : dq/dx

  n:=length qlist; % the number of functions q

  % substitution of df(qi,x) by dq_(i) in the Lagrangian
  qcopy:=qlist;
  for i:=1:n do <<
    q:=first qcopy; qcopy:=rest qcopy;
    l:=sub(df(q,x)=dq_(i),l)>>;

  % expressing dq_(i) by the general. impulses p_(j) and the q's
  plist:={}; dqlist:={};
  for i:=1:n do <<plist:=.(df(l,dq_(i)) - p_(i), plist);
                  dqlist:=.(dq_(i),dqlist)>>;
  dqlist:=solve(plist,dqlist);
  dq:=first dqlist;
  if symbolic(car algebraic(dq))=list then dqlist:=dq;
  if lisp(print_) then write"The velocities: ",dqlist;

  % Test for solubility:
  solved:=t;
  if length dqlist = 0 then solved:=nil
                       else <<
    for i:=1:n do <<
      qcopy:=dqlist;
      found:=nil;
      while (not found) and (qcopy neq {}) do <<
        dq:=first qcopy; qcopy:=rest qcopy;
        if (lhs dq) = dq_(i) then found:=t >> >>;
    if found=nil then solved:=nil>>;

  if solved=nil then <<
    if lisp(print_) then
    write
   " The equations p_ = dL/d(dq/dx) could not be solved for the dq/dx.";
    return nil
  >>            else <<

   % the Hamiltonian as a function of p_, q, x
    h := sub(dqlist, -l + for i:=1:n sum p_(i)*dq_(i));
    if lisp(print_) then <<
      write "The Hamiltonian with P_(i) as the canonical impulses: ";
      on factor,mcd;
      write "H = ",h;
      off factor,mcd
    >>;

    % The Hamiltonian-Jacobi equation
    hj := h;
    sf:=first sepans(0,{},.(x,qlist),s);
    qcopy:=qlist;
    for i:=1:n do <<q:=first qcopy;qcopy:=rest qcopy;
                    hj:=sub(p_(i) = df(sf,q), hj)>>;
    hj := num(df(sf,x) + hj);
    if lisp(print_) then <<
      write "The general Hamilton-Jacobi equation for the action S_:";
      write " 0 = ",hj
    >>;

    % The q's of qlist are becomming independent of x
    qcopy:=qlist;
    while qcopy neq {} do <<
      nodepend first qcopy, x;
      qcopy:=rest qcopy >>;

    return {hj, sf, h, dqlist}
  >>
end$ % of Hamilton

%----------------------------

algebraic procedure solve_hj(l,qlist,x)$

Comment   This Procedure
- makes a separation ansatz for S:
  S(x,qi,Qj) = S1(x,q1,Qj) + S2(x,q2,Qj) +...+ Sn(x,qn,Qj),   or
  S(  qi,Qj) = S1(  q1,Qj) + S2(  q2,Qj) +...+ Sn(  qn,Qj)
  if  dL/dx = 0 or
  S(x,q) = S1(x) + S2(q)   or
  S(x,q) = S1(x)*S2(q) + ...
  if qlist contains only one function q of x.

- calls the package CRACK for solving the resulting conditions
  for the Si,
- finds the general solution for qi(x) from
        dS/dQi = - Pi = constant                                    (*)
  d .. partial derivative,  D .. total derivative
  where the Qi are the (non-trivial and non-additive) constants of
  integration provided by the package CRACK when solving for Si where
  Pi are further constants of integration. The qi have to be solved
  algebraically from (*).

  (*) follows according to the general theory if one regards S(x,qi,Qj)
  as the generating function S(x,qi,Qj) of a canonical transformation
  such that after the transformation the new Hamiltonian is a function
  of Qi only such that DQi/Dt = 0 --> new Qj = constants -->
  new H = constant --> DPj/Dx = 0 -->
  new Pi = constant;

begin
  scalar ham, sans, a, sf, sfans, xcycl, sansatz, undet,
         clist, reslt, el1, el2, k_, fnlsys, xqlist;

  ham := hamilton(l,qlist,x);
  if ham neq nil then <<
    sf := second ham;
              % special simplified treatment if x is a cyclix variable
    if my_freeof(third ham,x) then xcycl:=t
                           else xcycl:=nil;
              % Chosing a suitable ansatz
    if length(qlist)=1 then
    if xcycl then sans:=sepans(8,       qlist ,{},s) % S=K_*x  + S2(q1)
             else sans:=sepans(8,cons(x,qlist),{},s) % S=S1(x) + S2(q1)
                       else
    if xcycl then sans:=sepans(8,qlist, {},s)
                               % S = K_*x + S1(q1) +...+ Sn(qn)
             else sans:=sepans(8,qlist,{x},s);
                               % S = S1(q1,x) + ... + Sn(qn,x)

    if xcycl then begin
     k_:=newfct(c,nil,lisp nfct_);
     lisp(nfct_:=add1 nfct_);
     sansatz := k_*x + first sans;
    end      else begin
     sansatz := first sans;
    end;

              % The Hamilton-Jacobi equation
    a:= sub(sf=sansatz, first ham);
    if lisp(print_) then <<
      write "The ansatz for the action: S_ = ",sansatz;
      if xcycl then
      write "           with ",k_,
            " = constant ( = H because ",x," is cyclic)";
      write "gives for the Hamilton-Jacobi equation:";
      write " 0 = ",a;
      write "which is to be solved.";
    >>;
              % Solving it and dropping additive constants
    sans := second sans;
    xqlist := .(x,qlist);
    if xcycl then sans:=.(k_, sans);
    reslt := drop_const(crack({a}, {}, sans, {}), xqlist, t);
    if reslt neq {} then <<
      % first because only one solution is expected for the linear HJ
      reslt := first reslt;
      undet := third reslt;
      if lisp(print_) then write "result = ",reslt;
      sansatz := sub(second reslt, sansatz);
      if lisp(print_) then write "The action  S_ = ", sansatz;

              % Formulating the final solution by differentiating S
      fnlsys:={};
      clist:={};    % undet muss K_ enthalten
                    % if xcycl then undet:=.(K_, undet);
      for each el1 in undet do
      if freeoflist(el1,xqlist) then clist:=.(el1,clist);

      for each el1 in undet do
      if (not my_freeof(sans,el1)) and
         my_freeof(clist,el1)      and
         (not my_freeof(first reslt,el1)) then
      for each el2 in clist do depend el1,el2;

      for each el1 in clist do <<
        fnlsys:=.(newfct(c,nil,lisp nfct_)-df(sansatz,el1),fnlsys);
        lisp(nfct_:=add1 nfct_);
      >>;

      if lisp(print_) then <<
        write"The solution in implicit form is:";
        for each el1 in fnlsys do write"0 = ",el1$
      >>;
%      fnlsys:=solve(fnlsys,qlist);
%      if lisp(print_) and (fnlsys neq {}) then <<
%        write
%        "The solution in explicit form is (if SOLVE could solve it):";
%        for each el1 in fnlsys do write el1$
%      >>

    >>

  >>
end$  % of solve_HJ

%----------------------------

algebraic procedure lagran(problem,runmode)$
% sol = false : determination of the Lagrangian only
% sol = true  : also transformation to L = y^'2
% returns return of lagfcn
begin scalar de,n,fl,vl,lg,x,y,yy,yyy,loes,k,a,b,ll,h1,h2,dep$
  scalar imp,y!',ham,sf$      % for the Hamiltonian part
  symbolic put('d!_y,'simpfn,'simpiden)$
  de:=first problem$ problem:=rest problem$
  y :=first problem$ problem:=rest problem$
  x :=first problem$ problem:=0$
  lg:=first runmode$ runmode:=rest runmode$
  fl:=first runmode$ runmode:=0$
  vl:={};
  symbolic write "Determination of a Lagrangian L for:";
  lisp terpri()$
  write de$

  de:=equ_to_expr(de)$
  n:=totdeg(de,y);
  for i:=2:n do <<de:=sub(df(y,x,i)=d!_y(i),de);
                  lg:=sub(df(y,x,i)=d!_y(i),lg)>>;
  de:=sub(df(y,x)=d!_y(1),de);
  lg:=sub(df(y,x)=d!_y(1),lg);
  yy:=lisp if atom (yyy:=reval algebraic y) then yyy
                                            else car yyy;
  if (y neq yy) then << let y=yy; de:=de; fi:=fi; clear y; y:=yy >>;
  if lg=0 then
  <<depend u!_,x,y;
    depend v!_,x,y;
    lg:=u!_*d!_y 1**2+v!_;
    fl:=append({u!_,v!_},fl)>>
          else
  if lg=1 then
  <<depend u!_,x,y;
    depend v!_,x,y;
    depend x!_,x,y;
    depend y!_,x,y;
    lg:=u!_*(df(y!_,x)+df(y!_,y)*d!_y 1)**2/(df(x!_,x)+df(x!_,y)*d!_y 1)
        + v!_*(df(x!_,x)+df(x!_,y)*d!_y 1);
    fl:=append({u!_,v!_,x!_,y!_},fl)>>$
  if n>1 then vl:=.(d!_y(n-1),vl)$
  symbolic(if print!_ neq nil then
  algebraic write "The ansatz:  L = ",sub(d!_y(1)=df(y,x),lg) )$
  if df(yy,x) neq 0 then <<dep:=1;nodepend yy,x>> else dep:=0;
  loes:=lagfcn(de,n,x,y,fl,vl,lg);
  lg:=second loes;
  if dep=1 then depend yy,x;
  if (lg eq 0) then write"No Lagrangian of this structure!" else
  <<on factor,mcd;
    lg := sub(d!_y(1)=df(y,x),lg)$
    write "The solution:  L = ",lg$
    off factor; % ,mcd;
    if (first loes neq {})                     then
    <<write "Remaining conditions: "$
      for each s in first loes do symbolic deprint list algebraic s>>
                                               else
if nil then
    solve_hj(lg,{y},x);
  >>;
  return loes
end$   % of lagran

%----------------------------

algebraic procedure lagfcn(de,n,x,y,fl,vl,lg)$
%determines the Lagrangian
%returns {{necessary eq.s},{suff. equ.s},Lagrangian,{free functions}}
begin scalar h1,h2,newfl,co$

  h1:=num sub(d!_y n =
  (-df(lg,d!_y 1,x)-df(lg,d!_y 1,y)*d!_y 1+df(lg,y))/df(lg,d!_y 1,2)
  , de);

  h2:= crack({h1},{},fl,vl)$   % first, because {h1} is linear

  h2:=drop_const(h2, {d!_y,y}, t);       % dropping the divergent term
  h2:=drop_const(h2, {d!_y,y,x}, nil);   % dropping the multip. constant

  if h2={} then h2:={{},{v_=0,u_=0},{}}
           else h2:=first h2;

  h1:=second h2;
  for each h3 in h1 do
  if symbolic (not atom algebraic h3) then
  if symbolic (equal(car algebraic h3,'equal)) then
  lg:=sub(h3,lg)$

  return {first h2,lg,third h2}
end$

endmodule;


module pdesymm; % Finding Symmetries of single or systems of ODEs/PDEs.

%  Author: Thomas Wolf
%  Jan 1994


% The algebraic operator NPRIMITIVE returns the
% numerically-primitive part of any expression.
% It is defined as a simpfn in EZGCD.

symbolic operator ncontent$
symbolic procedure ncontent p$
% Return numeric content of expression p
% based on simpnprimitive in ezgcd.
<< p := simp!* p;
   if polyzerop(numr p) then 0 else
   mk!*sq(numeric!-content numr p ./ numeric!-content denr p)
>>$

symbolic operator totdeg$
symbolic procedure totdeg(p,f)$
%   Ordnung (total) der hoechsten Ableitung von f im Ausdruck p
eval(cons('plus,ldiff1(car ldifftot(reval p,reval f),fctargs reval f)))$

symbolic procedure diffreltot(p,q,v)$
%   liefert komplizierteren Differentialausdruck$
if diffreltotp(p,q,v) then q
                   else p$

symbolic procedure diffreltotp(p,q,v)$
%   liefert t, falls p einfacherer Differentialausdruck, sonst nil
%   p, q Paare (liste.power), v Liste der Variablen
%   liste Liste aus Var. und Ordn. der Ableit. in Diff.ausdr.,
%   power Potenz des Differentialausdrucks
begin scalar n,m$
m:=eval(cons('plus,ldiff1(car p,v)))$
n:=eval(cons('plus,ldiff1(car q,v)))$
return
 if m<n then t
 else if n<m then nil
      else diffrelp(p,q,v)$
end$

symbolic procedure ldifftot(p,f)$
%  leading derivative total degree ordering
%  liefert Liste der Variablen + Ordnungen mit Potenz
%  p Ausdruck in LISP - Notation, f Funktion
ldifftot1(p,f,fctargs f)$

symbolic procedure ldifftot1(p,f,vl)$
%  liefert Liste der Variablen + Ordnungen mit Potenz
%  p Ausdruck in LISP - Notation, f Funktion, lv Variablenliste
begin scalar a$
a:=cons(nil,0)$
if not atom p then
if member(car p,list('expt,'plus,'minus,'times,
          'quotient,'df,'equal)) then
                                        %  erlaubte Funktionen
        <<if (car p='plus) or (car p='times) or (car p='quotient)
             or (car p='equal) then
                <<p:=cdr p$
                while p do
                        <<a:=diffreltot(ldifftot1(car p,f,vl),a,vl)$
                        p:=cdr p>> >>
        else if car p='minus then
                a:=ldifftot1(cadr p,f,vl)
        else if car p='expt then        %  Exponent
                        if numberp caddr p then
                        <<a:=ldifftot1(cadr p,f,vl)$
                        a:=cons(car a,times(caddr p,cdr a))>>
                        else a:=cons(nil,0)
                                        %  Poetenz aus Basis wird mit
                                        %  Potenz multipliziert
        else if car p='df then          %  Ableitung
                if cadr p=f then a:=cons(cddr p,1)
                                        %  f wird differenziert?
                else a:=cons(nil,0)>>   %  sonst Konstante bzgl. f
else if p=f then a:=cons(nil,1)
                                        %  Funktion selbst
        else a:=cons(nil,0)             %  alle uebrigen Fkt. werden
else if p=f then a:=cons(nil,1)$        %  wie Konstante behandelt
return a
end$

%---------------------

% Bei jedem totdiff-Aufruf pruefen, ob evtl. kuerzere dylist reicht
% evtl die combidiff-Kette und combi nicht mit in dylist, sond. erst in
% prolong jedesmal frisch generieren.

symbolic operator desort$

algebraic procedure nextdy(revx,xlist,dy)$
% generates all first order derivatives of lhs dy
% revx = reverse xlist; xlist is the list of variables;
%                       dy the old derivative
begin
  scalar x,n,ldy,rdy,ldyx,sublist;
  x:=first revx; revx:=rest revx;
  sublist:={};
  ldy:=lhs dy;
  rdy:=rhs dy;

  while lisp(not member(prepsq simp!* algebraic x,
             prepsq simp!* algebraic ldy))
        and (revx neq {}) do
  <<x:=first revx; revx:=rest revx>>;

  n:=length xlist;
  if revx neq {} then                % dy is not the function itself
  while first xlist neq x do xlist:=rest xlist;
  xlist:=reverse xlist;

  % New higher derivatives
  while xlist neq {} do
  <<x:=first xlist;
    ldyx:=df(ldy,x);
    sublist:=cons(ldyx=mkid(mkid(rdy,!|),n), sublist);
    n:=n-1;
    xlist:=rest xlist
  >>;
  return sublist
end$


algebraic procedure subdif1(xlist,ylist,ordr)$
% A list of lists of derivatives of one order for all functions
begin
 scalar allsub,revx,i,el,oldsub,newsub;
 revx:=reverse xlist;
 allsub:={};
 oldsub:= for each y in ylist collect y=y;
 for i:=1:ordr do      %  i is the order of next substitutions
 <<oldsub:=for each el in oldsub join nextdy(revx,xlist,el);
   allsub:=cons(oldsub,allsub)
 >>;
 return allsub
end$


algebraic procedure subdif2(xlist,ylist,ordr)$
% A list of for each function one list of lists of derivatives of one
% order
begin
  scalar allsub,revx,i,el,oldsub,newsub;
  revx:=reverse xlist;
  return
  for each y in ylist collect
  <<allsub:={};
    oldsub:={y=y};
    for i:=1:ordr do   %  i is the order of next substitutions
    <<oldsub:=for each el in oldsub join nextdy(revx,xlist,el);
      allsub:=cons(oldsub,allsub)
    >>;
    allsub
  >>
end$

symbolic operator combidif$

symbolic procedure combidif(s)$
% we want to extract the list of derivatives from
begin scalar temp,ans,no,n1;
  s:=reval s; % to guarantee s is in true prefix form
  temp:=reverse explode s;

  while not null temp do
  <<n1:=<<no:=nil;
          while (not null temp) and (not eqcar(temp,'!|)) do
          <<no:=car temp . no;temp:=cdr temp>>;
          compress no
        >>;
    if (not fixp n1) then n1:=intern n1;
    ans:=n1 . ans;
    if eqcar(temp,'!|) then <<temp:=cdr temp; temp:=cdr temp>>;
  >>;
  return ans
end$


symbolic operator combi$

symbolic  procedure combi(ilist)$
% ilist is a list of indexes (of variables of a partial derivative)
% and returns length!/k1!/k2!../ki! where kj! is the multiplicity of j.
begin
  integer n0,n1,n2,n3;
  n1:=1;
  ilist:=cdr ilist;
  while ilist do
  <<n0:=n0+1;n1:=n1*n0;
    if car ilist = n2 then <<n3:=n3+1; n1:=n1/n3>>
                      else <<n2:=car ilist; n3:=1>>;
    ilist:=cdr ilist>>;
  return n1
end$

symbolic operator dif$

symbolic procedure dif(s,n)$
% e.g.:   dif(fnc!|1!|3!|3!|4, 3) --> fnc!|1!|3!|3!|3!|4
begin scalar temp,ans,no,n1,n2,done;
  s:=reval s; % to guarantee s is in true prefix form
  temp:=reverse explode s;
  n2:=reval n;
  n2:=explode n2;

  while (not null temp) and (not done) do
  <<n1:=<<no:=nil;
          while (not null temp) and (not eqcar(temp,'!|)) do
          <<no:=car temp . no;temp:=cdr temp>>;
          compress no
        >>;
    if (not fixp n1) or ((fixp n1) and (n1 leq n)) then
    <<ans:=nconc(n2,ans); ans:='!| . ans; ans:='!! . ans; done:=t>>;
    ans:=nconc(no,ans);
    if eqcar(temp,'!|) then <<ans:='!| . ans; ans:='!! . ans;
                              temp:=cdr temp; temp:=cdr temp>>;
  >>;
  return intern compress nconc(reverse temp,ans);
end$

symbolic operator totdif$

symbolic procedure totdif(s,x,n,dylist)$
% total derivative of s(x,dylist) w.r.t. x which is the n'th variable
begin
  scalar tdf,el1,el2;
  tdf:=simpdf {s,x};
  <<dylist:=cdr dylist;
    while dylist do
    <<el1:=cdar dylist;dylist:=cdr dylist;
      while el1 do
      <<el2:=car el1;el1:=cdr el1;
        tdf:=addsq(tdf ,multsq( simp!* dif(el2,n), simpdf {s,el2}))
      >>
    >>
  >>;
  return prepsq tdf
end$

symbolic operator totdiff$

symbolic procedure totdiff(s,n,dysublist)$
% total derivative of s(x,dylist) w.r.t. the n'th x-variable and
% using only highest derivatives
begin
  scalar tdf,el2;
  tdf:=simp!* 0;
  dysublist:=cdr dysublist;
  while dysublist do
  <<el2:=car dysublist;dysublist:=cdr dysublist;
    tdf:=addsq(tdf ,multsq( simp!* dif(el2,n), simpdf {s,el2}))
  >>;
  return prepsq tdf
end$


algebraic procedure depnd(y,xlist)$
for each xx in xlist do
for each x  in xx    do depend y,x$


algebraic procedure transeq(eqn,xlist,ylist,sb)$
<<for each el1 in sb do eqn:=sub(el1,eqn);
  for each el1 in ylist do
  for each el2 in xlist do nodepend el1,el2;
  eqn>>$

%---------------------

algebraic procedure dirdiv(problem,runmode)$

 Comment
 problem ~ {eqn               % equation
            { y1, y2, ...},   % functions
            { x1, x2, ...} }  % variables
 runmode ~ {ansatz, flist}

 ansatz=nil then
   standard ansatz:
       H_(all variables + all functions + all derivatives < ordr.)
       v_x1, v_x2, ..., v_(n+1) (all variables)
 else
   ansatz={H_=...,v_x1=...,v_x2=...}
   flist ={unknown functions in ansatz}
 ansatz: equ = v_(n+1) + for all i sum v_xi*df(h_,xi);

begin
  scalar sb,el1,el2,dy1list,dy2list,flist,eqlist,h,
         xlist, ylist, ordr, ansatz, cpu, gc;

  cpu:=lisp time()$ gc:=lisp gctime()$

  eqn   := first problem$
  ylist :=second problem$
  xlist := third problem$

  ansatz:= first runmode$
  flist :=second runmode$

  problem:=runmode:=0;

  lisp(<<terpri()$
  write "----------------------------------------------------",
  "----------------------"$ terpri()$terpri()$
  write"This is DIRDIV - a program for writing a PDE as a directional ";
  write"derivative with a vector depending only on the independent ",
       "variables"$
  terpri()>>);
  write "The PDE under investigation is :";
  write"0 = ",eqn;
  write "for the function(s) : ";
  lisp(<<terpri()$fctprint cdr reval algebraic ylist;
         terpri()$terpri()>>);

  ordr:=0;
  for each e1 in ylist do
  <<n:=totdeg(eqn,e1);
    if n>ordr then ordr:=n>>;
      % Generating a substitution list and doing the substitutions
      % and Functions of ylist become variables
  sb:=subdif1(xlist,ylist,ordr)$
  eqn:=transeq(eqn,xlist,ylist,sb);

            % Lists of partial derivatives
  dy1list:=for each el2 in first sb collect rhs el2;
  dy2list:=ylist . for each el1 in rest sb collect
                   for each el2 in el1 collect rhs el2;

            % Generating the equations
  depnd(h!_,xlist . dy2list);
  if ansatz eq nil then flist:={h!_};
  n:=1;
  for each el1 in xlist do
  <<h:=mkid(v!_,el1);
    depnd(h,{xlist});
    if ansatz eq nil then flist:=h . flist;
    eqn:=eqn-h*totdif(h!_,el1,n,dy2list);
    n:=n+1
  >>;
  h:=mkid(v!_,n);
  depnd(h,{xlist});
  if ansatz eq nil then flist:=h . flist;
  eqn:=eqn-h;

  eqlist:=for each el1 in dy1list collect
  <<h:=coeffn(eqn,el1,1);
    eqn:=eqn-h*el1;h>>;
  eqlist:=eqn . eqlist;

            % Test whether eqn is quasi-linear
  if
  (for each el1 in dy1list product
     if not my_freeof(eqlist,el1) then 0 else 1)=0
  then return <<write"The equation is not quasilinear! ";
                for each el1 in ylist do depnd(el1,{xlist});
                {}>>;

  if ansatz neq nil then eqlist:=sub(ansatz,eqlist);

  sb:=l1:=el2:=dy1list:=dy2list:=h:=0;
  eqlist:=crack(eqlist,{},flist,{});
  for each el1 in ylist do depnd(el1,{xlist});

  return eqlist

end$

%---------------------

symbolic operator drop$

symbolic procedure drop(a,vl)$
% liefert summe aller terme aus a, die von elementen von vl abhaengen
begin scalar b$
  if not((pairp a) and (car a='plus)) then b:=a
                                      else
  <<vl:=cdr vl;             % because vl is an algebraic list
    for each c in cdr a do
    if not freeoflist(c,vl) then b:=cons(c,b)$
    if b then b:=cons('plus,reverse b)>>$
  return b$
end$

%---------------------

symbolic operator etamn$

symbolic procedure etamn(u,indxlist,xilist,etalist,revdylist,
                         contact,full)$
% determines etamn recursively
% If length(indxlist)=k then it is assumed that etamn contains at most
% k'th order derivatives, i.e. in revdylist only derivatives up to k'th
% order need to be included. Exception: contact symmetries and k=0 then
% still first oder derivatives are included.
begin
  scalar etam,x,h1,ulist,el,r,cplist,pneta;
  return
    if (length indxlist)<2 then
    <<cplist:=etalist;
      while u neq caddar cplist do cplist:=cdr cplist;
      pneta:=car cplist;                      % = (LIST,eta_yi,yi)
      if null indxlist then cdr pneta
                       else
      <<ulist:=nil;
        cplist:=xilist;
        for h1:=1:(car indxlist)-1 do cplist:=cdr cplist;
        x:=cddar cplist;    % e.g.  x := (v3,3)
        r:=if zerop cadr pneta then simp!* 0
                               else simp!*
           if contact
           then totdif(cadr pneta,car x,cadr x, 'list . revdylist)
           else
           if full
           then totdif(cadr pneta,car x,cadr x, 'list . cdr revdylist)
           else totdiff(cadr pneta,cadr x,cadr revdylist);
        cplist:=xilist;
        while cplist do
        <<el:=cdar cplist;  % e.g.  el=(xi_z,z,3)
          cplist:=cdr cplist;
          h1:=dif(u,caddr el);
          ulist:=h1 . ulist;
          r:=subtrsq(r, multsq(simp!* h1,simp!*
             if contact
             then totdif(car el,car x,cadr x, 'list . revdylist)
             else totdif(car el,car x,cadr x, 'list . cdr revdylist)))
        >>;
        % (if not full then drop(r,'LIST . car revdylist) else r) .
        % (reverse ulist)
        prepsq r . (reverse ulist)
      >>
    >>                   else
    <<etam:=etamn(u, cdr indxlist, xilist, etalist,cdr revdylist,
                  contact,full);
      ulist:=nil;
      cplist:=xilist;
      for h1:=1:(car indxlist)-1 do cplist:=cdr cplist;
      x:=cddar cplist;    % e.g.  x := (v3,3)
      r:=if zerop car etam then simp!* 0
                           else simp!*
         if full then totdif(car etam,car x,cadr x,
                             'list . cdr revdylist)
                 else totdiff(car etam,cadr x,cadr revdylist);
      etam:=cdr etam;
      cplist:=xilist;
      while cplist do
      <<el:=cadar cplist;     % e.g.  el=xi_z
        cplist:=cdr cplist;
        h1:=dif(car etam,cadr indxlist);  % e.g.  h1:=u!|i!|n!
        etam:=cdr etam;
        ulist:=h1 . ulist;
        r:=subtrsq(r, multsq(simp!* h1,simp!*
                      totdif(el,car x,cadr x,'list . cdr revdylist)))
      >>;
      % (if not full then drop(r,'LIST . car revdylist) else r) .
      % (reverse ulist)
      prepsq r . (reverse ulist)
    >>
end$ % of etamn

%---------------------

symbolic operator prolong$

symbolic procedure prolong(uik,xilist,etalist,revdylist,minord,
                           contact)$
begin
  scalar indxlist, u, full, l1, l2, i;
  indxlist:=combidif(uik);
  u:=car indxlist; indxlist:=cdr indxlist;
  revdylist:=cdr revdylist;
  l1:=length(indxlist);
  l2:=length(revdylist)-1;
  for i:=1:(l2-l1) do revdylist:=cdr revdylist;
  % revdylist does not need higher derivatives than of order l1
  if minord=0 then full:=t
              else full:=nil;
  return (car etamn(u,indxlist,cdr xilist,cdr etalist,revdylist,contact,
                    full))
end$ % of prolong

%---------------------

algebraic procedure callcrack(!*time,cpu,gc,lietrace_,truesub,symcon,
                              flist,vl,xilist,etalist)$
begin
  scalar h;
  if lisp(!*time) then
  write "time to formulate conditions: ", lisp time() - cpu,
        " ms    GC time : ", lisp gctime() - gc," ms"$
  if lietrace_ then <<
    write"Symmetry conditions before substitution: ";
    write symcon;
  >>;
  if lietrace_ then <<
    write"The substitutions: ";
    write truesub;
  >>;
  symcon:=sub(truesub,symcon);
  if lietrace_ then <<
    write"Symmetry conditions after substitution, before CRACK: ";
    write symcon;
  >>;
  h:=crack(symcon,{},flist,vl);
  if h neq {} then
  <<h:=first h;
    symcon:=first h;
    xilist :=sub(second h,xilist);
    etalist:=sub(second h,etalist);
    if lietrace_ then <<
      write"symcon nachher: ",symcon;
      write"xilist=",xilist;
      write"etalist=",etalist;
    >>;
    flist:=third h;
    if lisp(print_) then
    <<write"";
      write"Remaining free functions after the last CRACK-run:";
      lisp(fctprint cdr reval algebraic flist);write"">>;
  >>;
  return {symcon,xilist,etalist,flist}
end$ % of callcrack

%---------------------

algebraic procedure liepde(problem,runmode)$

 Comment
 problem ~ {{eq1,eq2, ...},   % equations
            { y1, y2, ...},   % functions
            { x1, x2, ...} }  % variables
 runmode ~ {symord, ansatz, flist}

 if symord=nil then default order of symmetry, i.e.
                    if (one function              ) and
                       (only one equation         ) and
                       (order of equation > 1     ) and
                       ((>1 variable) or (order>2))
                    then symord:=1 (contact s.)
                    else symord:=0 (point s.)
               else symord determines the differential order of xi,
                    eta but must not exceed 0 if more than one
                    dependent variable v

 if ansatz=nil then default ansatz, i.e. xi, eta are functions
                    of xi, yj and derivatives of yj of order upto symord
                    flist={additional parametric functions other than yi
                           which are to be evaluated, such that
                           symmetries exist}
               else if point symm. then ansatz has to have the form
                                     {xi!_x1=...,...,eta!_y3=...} else
                    if contact- or higher order symm. then ansatz has
                    form
                                     {spot!_=...}
                    flist ={unknown functions in ansatz} ;


begin
  scalar eqlist, freelist, occurlist, ylist, xlist, xilist, etalist, sb,
         dylist,n,n1, symcon, flist, deplist, symord, minord, lietrace_,
         ordr, truesub, dycopy, vl, revdylist, ansatz, cpu, gc, contact,
         eqlen, dylen, allsub, n2, n3, e1, e2, subdy, eqn, h,
         eqcopy2;

  cpu:=lisp time()$ gc:=lisp gctime()$
  lietrace_:=nil;

  %--------- extracting input data
  eqlist:= maklist first problem;
  ylist := maklist second problem;
  xlist := maklist third problem;

  symord:= first runmode$
  ansatz:=second runmode$
  flist := third runmode$

  problem:=runmode:=0;

  eqlist:=for each e1 in eqlist collect equ_to_expr(e1);

  if length eqlist > 1 then eqlist:=desort eqlist;

  %--------- initial printout
  lisp(if print_ and logoprint_ then <<terpri()$
    write "-----------------------------------------------",
    "---------------------------"$ terpri()$terpri()$
    write
  "This is LIEPDE - a program for calculating infinitesimal symmetries";
    write "of single ODEs/PDEs and ODE/PDE - systems"; terpri()
  >>                            else terpri());
  write "The ODE/PDE (-system) under investigation is :";
  for each e1 in eqlist do write"0 = ",e1;
  write "for the function(s) : ";
  lisp(<<terpri()$fctprint cdr reval algebraic ylist;
       terpri()$terpri()>>);

  %--------- initializations
  ordr:=0;
  for each e1 in eqlist do
  for each e2 in ylist do
  <<n:=totdeg(e1,e2);
    if n>ordr then ordr:=n>>;

  if symord and (length ylist > 1) and (symord > 0) then
  <<symord:=0;
    write"Only point symmetries are determined if more than one",
         "dependent variable!";
    if ansatz then <<write"Restart with symord=0";halt>>
  >>;
  if symord eq nil then
  if (length ylist = 1              ) and
     ((length xlist > 1) or (ordr>2)) and
     (ordr>1                        ) and
     (length(eqlist)=1              ) then symord:=1
                                      else symord:=0;
  if symord>0 then contact:=t
              else contact:=nil;
  sb:=subdif1(xlist,ylist,ordr)$
  eqlist:=%for each eqn in eqlist collect
          transeq(eqlist,xlist,ylist,sb);

  dylist:=ylist . reverse for each e1 in sb collect
                          for each e2 in e1 collect e3:=rhs e2;
  revdylist:=reverse dylist;  % dylist with decreasing order

  vl:=append(xlist,for each e1 in dylist join e1);

  deplist:=for n:=0:symord collect part(dylist,n+1);
    % list of xi-, eta-variab.

  if not flist then flist:={};
  if not contact then <<
    n:=0;
    xilist :=for each e1 in xlist collect
    <<n:=n+1;
      h:=mkid(xi!_ ,e1);
      depnd(h,xlist . deplist);
      if not ansatz then flist:=h . flist;
      {h,e1,n}>>;
    n:=0;
    etalist:=for each e1 in ylist collect
    <<n:=n+1;
      h:=mkid(eta!_,e1);
      depnd(h,xlist . deplist);
      if not ansatz then flist:=h . flist;
      {h,e1}>>
  >>             else <<
    n1:=spot!_;
    depnd(n1,xlist . deplist);
    if ansatz eq nil then flist:=n1 . flist;
    e2:=-n1;
    n:=0;
    xilist:= for each e1 in xlist collect
    <<n:=n+1;
      h:=dif(first ylist,n);
      e2:=e2+df(n1,h)*h;
      {df(n1,h),e1,n}
    >>;
    etalist:={{e2,first ylist}}
    %;write"xilist=",xilist," etalist=",etalist
  >>;

  if ansatz neq nil then <<xilist:=sub(ansatz,xilist);
                           etalist:=sub(ansatz,etalist)>>;


  % Determining a substitution list for highest derivatives from eqlist
  % Substitutions may not be optimal if starting system is not in
  % standard form

  Comment: Counting in how many equations each highest
  derivative occurs. Those which do not occur allow Stephani-Trick,
  those which do occur once and there linearly are substituted by that
  equation.

  Because one derivative shall be assigned it must be one of
  the highest derivatives from each equation used.
  It could be a lower order derivative
  if substitution is done only finally before solving the
  determining system which would be enough for point symmetries.

  Each equation must be used only once.
  Each derivative must be substituted by only one equation
  At first determining the number of occurences of each highest
  derivative.

  Tricky: If SUB is used for substitution then derivatives could come in
  which are already substituted before. If LET is used, infinite loops
  can occur. ;

  truesub:={};
  occurlist:={};
  freelist:={};

  eqcopy1:=eqlist;
  dycopy:=part(dylist,length dylist);   % the highest derivatives

  eqlen:=length eqcopy1;
  dylen:=length dycopy;

  allsub:={};
  for n1:=1:dylen do
  <<e1:=part(dycopy,n1);
    n2:=0;     % number of equations in which the derivative e1 occurs
    subdy:={};
    for n3:=1:eqlen do
    if not my_freeof(part(eqlist,n3),e1) then
    <<n2:=n2+1;
      eqn:=part(eqcopy1,n3);
      if eqn neq 0 then
      <<e2:=coeff(eqn,e1);
        if hipow!*=1 then
        subdy:={n1,n3,e1 = - first e2/second e2} . subdy
      >>
    >>;
    if n2=0 then freelist:=e1 . freelist else
    <<occurlist:=e1 . occurlist;
      if subdy neq {} then if n2=1 then
      <<h:=first subdy;
        truesub:=(third h) . truesub;
        dycopy:=part(dycopy,n1):=0;
        eqcopy1:=part(eqcopy1,second(h)):=0>>
                                   else allsub:=append(subdy,allsub)
    >>
  >>;

  % Taking the remaining known substitutions
  eqn:=h:=subdy:=0;
  for each subdy in allsub do
  if (part( dycopy, first subdy) neq 0) and
     (part(eqcopy1,second subdy) neq 0) then
  <<truesub:=(third subdy) . truesub;
    dycopy :=part( dycopy, first subdy):=0;
    eqcopy1:=part(eqcopy1,second subdy):=0>>;
  allsub:=0;
  % The remaining unused equations are returned to use them in a
  % further run if they are of lower order.
  eqcopy2:={};
  for each e1 in eqcopy1 do if e1 neq 0 then eqcopy2:=e1 . eqcopy2;

  if length eqcopy2 neq 0 then <<
     %------ Continuing search for substitutions
    eqcopy1:=eqcopy2; eqcopy2:=0;
    dycopy:=append(for each e1 in rest revdylist join e1, xlist);
    % all but the highest derivatives

    eqlen:=length eqcopy1;
    dylen:=length dycopy;

    allsub:={};
    for n1:=1:dylen do
    <<e1:=part(dycopy,n1);
      n2:=0;     % number of equations in which the derivative e1 occurs
      subdy:={};
      for n3:=1:eqlen do
      if not my_freeof(part(eqlist,n3),e1) then
      <<n2:=n2+1;
        eqn:=part(eqcopy1,n3);
        if eqn neq 0 then
        <<e2:=coeff(eqn,e1);
          if hipow!*=1 then
          subdy:={n1,n3,e1 = - first e2/second e2} . subdy
        >>
      >>;
      if (subdy neq {}) and (n2=1) then
      <<h:=first subdy;
        truesub:=(third h) . truesub;
        dycopy:=part(dycopy,n1):=0;
        eqcopy1:=part(eqcopy1,second(h)):=0>>
                                   else allsub:=append(subdy,allsub)
    >>;

    % Taking the remaining known substitutions
    eqn:=h:=subdy:=0;
    for each subdy in allsub do
    if (part( dycopy, first subdy) neq 0) and
       (part(eqcopy1,second subdy) neq 0) then
    <<truesub:=(third subdy) . truesub;
      dycopy :=part( dycopy, first subdy):=0;
      eqcopy1:=part(eqcopy1,second subdy):=0>>;
    allsub:=0;

    % The remaining unused equations are returned to use them in a
    % further run if they are of lower order.
    eqcopy2:={};
    for each e1 in eqcopy1 do if e1 neq 0 then eqcopy2:=e1 . eqcopy2;

    if length(eqcopy2) neq 0 then <<
      write
       "The following substitutions are to be used in the calculation:"$
      for each e1 in truesub do write e1;
      write"The following equations could so far not be used for ",
           " substitution:";
      for each e1 in eqcopy1 do write e1;
      write"Input substitutions of the form {...=..., ...} by using",
           " the above equations."$
      write"ENTER finishes the input."$

      allsub:=aread(nil);
      if allsub neq nil then truesub:=append(allsub,truesub);
      allsub:=0;
    >>;
    eqcopy2:=0;
  >>;

  %------ Determining first short determining equations and solving them
  symcon:={};
  n1:=1;
  if freelist neq {} then
  for each eqn in eqlist do
  <<if lietrace_ then
    write"=============== Preconditions for the ",n1,". equation" ;
    n1:=n1+1;
    eqn:=drop(eqn,first revdylist);
               %dropping all terms without a highest deriv.
    minord:=(length dylist) - 1;
    h:=for each e2 in occurlist sum
    if my_freeof(eqn,e2) then 0
                      else prolong(e2,xilist,etalist,revdylist,minord,
                                   contact) * df(eqn,e2);
    for each e2 in freelist do
    <<e1:=num coeffn(h,e2,1);
      if e1 neq 0 then symcon:=e1 . symcon>>;
    if symcon neq {} then <<
      flist:=callcrack(!*time,cpu,gc,lietrace_,truesub,symcon,flist,vl,
                       xilist,etalist)$
      symcon :=first flist;    xilist:=second flist;
      etalist:=third flist;    flist:=part(flist,4);
      cpu:=lisp time()$ gc:=lisp gctime()$
    >>
  >>;

  %------------ Determining the full symmetry conditions
  minord:=0;
  h:=1;
  n1:=1;
  for each eqn in eqlist do
  if h eq {} then n1:=n1+1 else
  <<if lietrace_ then
    write"=============== Full conditions for the ",n1,". equation" ;
    n1:=n1+1;
    symcon:=num (
            ((for each e1 in xilist sum first e1 * df(eqn,second e1)) +
             for each e1 in dylist sum
             for each e2 in e1     sum if my_freeof(eqn, e2) then 0
                                                          else
             prolong(e2,xilist,etalist,revdylist,minord,contact)
             * df(eqn,e2)
            )   ) . symcon;
    flist:=callcrack(!*time,cpu,gc,lietrace_,truesub,symcon,flist,vl,
                     xilist,etalist)$
    symcon :=first flist;    xilist:=second flist;
    etalist:=third flist;    flist:=part(flist,4);
    cpu:=lisp time()$ gc:=lisp gctime()$
  >>;
  eqn:=sb:=dylist:=e1:=e2:=n:=h:=deplist:=occurlist:=symord:=nil;

  %------- Calculation finished, simplification of the result

  h:=append(for each el in  xilist collect first el,
            for each el in etalist collect first el );

  %------- droping redundant constants or functions
  if symcon={} then sb:=dropredundant(h,flist,vl);
  if sb then <<
   flist:=third sb;
   h:=second sb;
   sb:=first sb;
   e1:=nil
  >>;

  %------- absorbing numerical constants into free constants
  h:=absorbconst(h,flist);
  if h then if sb then sb:=append(sb,h)
                  else sb:=h;

  %------- doing the substitutions
  if sb then <<
   if lisp(print_) then
   write"Free constants and/or functions have been rescaled."$
   xilist :=sub(sb,xilist);
   etalist:=sub(sb,etalist);
   symcon :=sub(sb,symcon)
  >>;

  %------- output
  if flist={} then write"No such symmetry does exist"
              else <<
    if length flist>1 then n:=t
                      else n:=nil;
    write"The symmetr",if n then "ies are:" else "y is:";
    xilist:=for each el in  xilist collect
    <<e1:=mkid( xi!_,second el); e1:= e1 = first el;write e1;e1>>;

    etalist:=for each el in etalist collect
    <<e1:=mkid(eta!_,second el); e1:= e1 = first el;write e1;e1>>;

    lisp(terpri())$
    if flist neq {} then
    lisp<<write"with ";fctprint cdr reval algebraic flist>>;

    if symcon={} then if flist neq {} then
    lisp<<write"which ",if algebraic n then "are" else "is"," free.";
          terpri()>>                  else
                 else
    if lisp(print_) then
    <<write"which still ",if n then "have" else "has"," to satisfy: ";
      lisp(deprint cdr algebraic symcon);
    >>              else
    <<write"which ",if n then "have" else "has",
           " to satisfy conditions. To see them set ";
      write
      "lisp(print_:= max. number of terms of an equation to print);"
    >>
  >>;
  for each e1 in ylist do depnd(e1,{xlist});

  return {symcon,append(xilist,etalist),flist}
end$ % of liepde

endmodule;


end;
