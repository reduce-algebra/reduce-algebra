load!-package 'fide1;   % We need this loaded.

%***********************************************************************
%*****                                                             *****
%*****      D A T A     FOR  DISCRETIZATION (CHANGE IF YOU NEED)   *****
%*****                                                             *****
%***********************************************************************

difmatch all,1,
  0,1$
difmatch all,u,
  u=one,0,
    u(i),
  u=half,0,
    (u(i-1/2)+u(i+1/2))/2$
difmatch all,diff(u,x),
  u=one,2,
    (u(i+1)-u(i-1))/(dip1+dim1),
  u=half,0,
    (u(i+1/2)-u(i-1/2))/di$
difmatch all,diff(u,x,2),
  u=one,0,
    ((u(i+1)-u(i))/dip1-(u(i)-u(i-1))/dim1)/di,
  u=half,2,
    ((u(i+3/2)-u(i+1/2))/dip2-(u(i-1/2)-u(i-3/2))/dim2)/(dip1+dim1)$
difmatch all,u*v,
  u=one,v=one,0,
    u(i)*v(i),
  u=one,v=half,0,
    u(i)*(v(i-1/2)+v(i+1/2))/2,
  u=half,v=one,0,
    (u(i-1/2)+u(i+1/2))/2*v(i),
  u=half,v=half,0,
    (u(i-1/2)*v(i-1/2)+u(i+1/2)*v(i+1/2))/2$
difmatch all,u**n,
  u=one,0,
    u(i)**n,
  u=half,0,
    (u(i-1/2)**n+u(i+1/2)**n)/2$
difmatch all,u*v**n,
  u=one,v=one,0,
    u(i)*v(i)**n,
  u=one,v=half,0,
    u(i)*(v(i-1/2)**n+v(i+1/2)**n)/2,
  u=half,v=one,0,
    (u(i-1/2)+u(i+1/2))/2*v(i)**n,
  u=half,v=half,0,
    (u(i-1/2)*v(i-1/2)**n+u(i+1/2)*v(i+1/2)**n)/2$
difmatch all,u*v*w,
  u=one,v=one,w=one,0,
    u(i)*v(i)*w(i),
  u=one,v=one,w=half,0,
    u(i)*v(i)*(w(i+1/2)+w(i-1/2))/2,
  u=one,v=half,w=one,0,
    u(i)*(v(i-1/2)+v(i+1/2))/2*w(i),
  u=one,v=half,w=half,0,
    u(i)*(v(i-1/2)*w(i-1/2)+v(i+1/2)*w(i+1/2))/2,
  u=half,v=one,w=one,0,
    (u(i-1/2)+u(i+1/2))/2*v(i)*w(i),
  u=half,v=one,w=half,0,
    (u(i-1/2)*w(i-1/2)+u(i+1/2)*w(i+1/2))/2*v(i),
  u=half,v=half,w=one,0,
    (u(i-1/2)*v(i-1/2)+u(i+1/2)*v(i+1/2))/2*w(i),
  u=half,v=half,w=half,0,
    (u(i-1/2)*v(i-1/2)*w(i-1/2)+u(i+1/2)*v(i+1/2)*w(i+1/2))/2$
difmatch all,v*diff(u,x),
  u=one,v=one,2,
    v(i)*(u(i+1)-u(i-1))/(dip1+dim1),
  u=one,v=half,2,
    (v(i+1/2)+v(i-1/2))/2*(u(i+1)-u(i-1))/(dip1+dim1),
  u=half,v=one,0,
    v(i)*(u(i+1/2)-u(i-1/2))/di,
  u=half,v=half,0,
    (v(i+1/2)+v(i-1/2))/2*(u(i+1/2)-u(i-1/2))/di$
difmatch all,v*w*diff(u,x),
  u=one,v=one,w=one,2,
    v(i)*w(i)*(u(i+1)-u(i-1))/(dip1+dim1),
  u=one,v=one,w=half,2,
    v(i)*(w(i-1/2)+w(i+1/2))/2*(u(i+1)-u(i-1))/(dip1+dim1),
  u=one,v=half,w=one,2,
    (v(i+1/2)+v(i-1/2))/2*w(i)*(u(i+1)-u(i-1))/(dip1+dim1),
  u=one,v=half,w=half,2,
    (v(i+1/2)*w(i+1/2)+v(i-1/2)*w(i-1/2))/2*(u(i+1)-u(i-1))/(dip1+dim1),
  u=half,v=one,w=one,0,
    v(i)*w(i)*(u(i+1/2)-u(i-1/2))/di,
  u=half,v=one,w=half,0,
    v(i)*(w(i-1/2)+w(i+1/2))/2*(u(i+1/2)-u(i-1/2))/di,
  u=half,v=half,w=one,0,
    (v(i+1/2)+v(i-1/2))/2*w(i)*(u(i+1/2)-u(i-1/2))/di,
  u=half,v=half,w=half,0,
    (v(i+1/2)*w(i+1/2)+v(i-1/2)*w(i-1/2))/2*(u(i+1/2)-u(i-1/2))/di$
difmatch all,x*u,
  u=one,0,
    x(i)*u(i),
  u=half,1,
    (x(i-1/2)*u(i-1/2)+x(i+1/2)*u(i+1/2))/2$
difmatch all,u/x**n,
  u=one,0,
    u(i)/x(i)**n,
  u=half,0,
    (u(i-1/2)/x(i-1/2)**n+u(i+1/2)/x(i+1/2)**n)/2$
difmatch all,u*v/x**n,
  u=one,v=one,0,
    u(i)*v(i)/x(i)**n,
  u=one,v=half,0,
    u(i)*(v(i-1/2)+v(i+1/2))/2/x(i)**n,
  u=half,v=one,0,
    (u(i-1/2)+u(i+1/2))/2*v(i)/x(i)**n,
  u=half,v=half,0,
    (u(i-1/2)*v(i-1/2)/x(i-1/2)**n+u(i+1/2)*v(i+1/2)/x(i+1/2)**n)/2$
difmatch all,diff(x**n*u,x)/x**n,
  u=one,2,
    (x(i+1)**n*u(i+1)-x(i-1)**n*u(i-1))/x(i)**n/(dim1+dip1),
  u=half,0,
    (x(i+1/2)**n*u(i+1/2)-x(i-1/2)**n*u(i-1/2))/di/x(i)**n$
difmatch all,diff(u*v,x),
  u=one,v=one,4,
    (u(i+1)*v(i+1)-u(i-1)*v(i-1))/(dim1+dip1),
  u=one,v=half,2,
    ((u(i+1)+u(i))/2*v(i+1/2)-(u(i-1)+u(i))/2*v(i-1/2))/di,
  u=half,v=one,2,
    ((v(i+1)+v(i))/2*u(i+1/2)-(v(i-1)+v(i))/2*u(i-1/2))/di,
  u=half,v=half,0,
    (u(i+1/2)*v(i+1/2)-u(i-1/2)*v(i-1/2))/di$
difmatch all,diff(u*v,x)/x**n,
  u=one,v=one,4,
    (u(i+1)*v(i+1)-u(i-1)*v(i-1))/x(i)**n/(dim1+dip1),
  u=one,v=half,2,
    ((u(i+1)+u(i))/2*v(i+1/2)-(u(i-1)+u(i))/2*v(i-1/2))/x(i)**n/di,
  u=half,v=one,2,
    ((v(i+1)+v(i))/2*u(i+1/2)-(v(i-1)+v(i))/2*u(i-1/2))/x(i)**n/di,
  u=half,v=half,0,
    (u(i+1/2)*v(i+1/2)-u(i-1/2)*v(i-1/2))/x(i)**n/di$
difmatch all,diff(u*diff(v,x),x)/x**n,
  u=half,v=one,0,
   (u(i+1/2)*(v(i+1)-v(i))/dip1-u(i-1/2)*(v(i)-v(i-1))/dim1)/di/x(i)**n,
  u=half,v=half,2,
    (u(i+1/2)*(v(i+3/2)-v(i-1/2))/(di+dip2)-u(i-1/2)*(v(i+1/2)-
       v(i-3/2))/(di+dim2))/di/x(i)**n,
  u=one,v=one,2,
    ((u(i+1)+u(i))/2*(v(i+1)-v(i))/dip1-(u(i)+u(i-1))/2*(v(i)-v(i-1))
       /dim1)/di/x(i)**n,
  u=one,v=half,4,
    ((u(i+1)+u(i))/2*(v(i+3/2)-v(i-1/2))/(di+dip2)-
     (u(i)+u(i-1))/2*(v(i+1/2)-v(i-3/2))/(di+dim2))/di/x(i)**n$

%***********************************************************************
%*****      E N D   OF   D A T A     FOR  DISCRETIZATION           *****
%***********************************************************************


%***********************************************************************
%*****                                                             *****
%*****      M O D U L E      A P P R O X                           *****
%*****                                                             *****
%***********************************************************************

module approx$
% Author: R. Liska$
% Program APPROX, Version REDUCE 3.4     05/1991$

symbolic$

symbolic fluid '(!*prapprox)$

switch prapprox$
!*prapprox:=nil$

global '(cursym!* coords!* icoords!* functions!* hipow!* lowpow!*)$
%  Implicitely given indices
icoords!*:='(i j k l m n i1 j1 k1 l1 m1 n1)$

if null getd 'coordfn then
procedure coordfn$
begin
  scalar cor,icor$
  flag('(into),'delim)$
  cor:=remcomma xread nil$
  remflag('(into),'delim)$
  if cursym!* eq 'into then
      icor:=remcomma xread nil
    else if cursym!* eq '!*semicol!* then
      icor:=icoords!*
    else return symerr('coordfn,t)$
  return list('putcor,
               mkquote cor,
               mkquote icor)
end$

put('coordinates,'stat,'coordfn)$
flag('(putcor),'nochange)$

if null getd'putcor then
procedure putcor(u,v)$
begin
  scalar j$
  j:=1$
  coords!*:=u$
  while u do
    <<if not idp car u then        msgpri
          (" Coordinate ",car u," must be identifier",nil,'hold)$
      if not idp car v then        msgpri
          (" Index ",car v," must be identifier",nil,'hold)$
      put(car u,'index,list car v)$
      put(car v,'coord,list car u)$
      put(car u,'ngrid,j)$
      j:=j+1$
      put(car u,'simpfn,'simpiden)$
      u:=cdr u$
      v:=cdr v >>
end$

if null getd'tcar then
procedure tcar u$
if pairp u then car u
  else u$

algebraic$

procedure fact(n)$
if n=0 then 1
  else n*fact(n-1)$

procedure taylor(fce,var,step,ord)$
if step=0 or ord=0 then fce
  else fce+for j:=1:ord sum step**j/fact(j)*df(fce,var,j)$

symbolic$

procedure maxorder u$
begin
  scalar movar,var$
a:movar:=car u$
  if not eqexpr movar then return errpri2(movar,'hold)$
  movar:=cdr movar$
  var:=car movar$
  movar:=reval cadr movar$
  if not atom var or not var memq coords!* then return msgpri(
        " Parameter ",var," must be coordinate",nil,'hold)
    else if not fixp movar then return msgpri(
        " Parameter ", movar," must be integer",nil,'hold)
    else put(var,'maxorder,movar)$
  u:=cdr u$
  if u then go to a$
  return nil
end$

put('maxorder,'stat,'rlis)$

procedure center u$
begin
  scalar movar,var$
a:movar:=car u$
  if not eqexpr movar then return errpri2(movar,'hold)$
  movar:=cdr movar$
  var:=car movar$
  movar:=reval cadr movar$
  if not atom var or not var memq coords!* then return msgpri(
        " Parameter ",var," must be coordinate",nil,'hold)
    else if not(fixp movar or (eqcar(movar,'quotient) and
           (fixp cadr movar or
            (eqcar(cadr movar,'minus) and fixp cadadr movar))
                        and fixp caddr movar)) then return msgpri(
        " Parameter ", movar," must be integer or rational number",nil,
        'hold)
    else put(var,'center,movar)$
  u:=cdr u$
  if u then go to a$
  return nil
end$

put('center,'stat,'rlis)$

procedure functions u$
<<functions!* := u$
  for each a in u do put(a,'simpfn,'simpiden) >>$

put('functions,'stat,'rlis)$

procedure simptaylor u$
begin
  scalar ind,var,movar,step,fce,ifce$
  fce:=car u$
  if null cdr u then return simp fce$
  ifce:=cadr u$
  if cddr u then fce:= fce . cddr u$
  ind:=mvar numr simp ifce$
  var:=tcar get(ind,'coord)$
  step:=reval list('difference,
                   ifce,
                   list('plus,
                        if (movar:=get(var,'center)) then movar
                          else 0,
                        ind))$
  step:=list('times,
             step,
             get(var,'gridstep))$
  movar:=if (movar:=get(var,'maxorder)) then movar
           else 3$
  return simp list('taylor,
                   fce,
                   var,
                   step,
                   movar)
end$

algebraic$

procedure approx difsch$
begin
  scalar ldifsch,rdifsch,nrcoor,coors,rest,ldifeq,rdifeq$
  symbolic
    <<for each a in functions!* do
          <<put(a,'simpfn,'simptaylor)$
            eval list('depend,mkquote (a . coords!*)) >>$
      flag(functions!*,'full)$
      for each a in coords!* do put(a,'gridstep, intern compress append
                           (explode 'h,explode a))$
      nrcoor:=length coords!* - 1$
      eval list('array,
                mkquote list('steps . add1lis list(nrcoor)))$
      coors:=coords!*$
      for j:=0:nrcoor do
        <<setel(list('steps,j),aeval get(car coors,'gridstep))$
          coors:=cdr coors >>  >>$
  ldifsch:=lhs difsch$
  rdifsch:=rhs difsch$
  ldifeq:=ldifsch$
  rdifeq:=rdifsch$
  ldifeq:=substeps(ldifeq)$
  rdifeq:=substeps(rdifeq)$
  rest:=ldifsch-ldifeq-rdifsch+rdifeq$
  for j:=0:nrcoor do
    steps(j):=steps(j)**minorder(rest,steps(j))$
  write " Difference scheme approximates differential equation ",
     ldifeq=rdifeq$
  write " with orders of approximation:"$
  on div$
  for j:=0:nrcoor do write steps(j)$
  off div$
  symbolic if !*prapprox
     then algebraic write " Rest of approximation : ",rest$
  symbolic
    <<for each a in functions!* do
        <<put(a,'simpfn,'simpiden)$
          eval list('nodepend,mkquote (a . coords!*)) >>$
      remflag(functions!*,'full)>>$
  clear steps
end$

procedure substeps u$
begin
  scalar step,nu,du$
  nu:=num u$
  du:=den u$
  symbolic for each a in coords!* do
    <<step:=get(a,'gridstep)$
      flag(list step,'used!*)$
      put(step,'avalue,'(scalar 0)) >>$
  symbolic rmsubs()$
  nu:=nu$
  du:=du$
  symbolic for each a in coords!* do
    <<step:=get(a,'gridstep)$
      remflag(list step,'used!*)$
      remprop(step,'avalue) >>$
  if du=0 then <<write
    " Reformulate difference scheme, grid steps remain in denominators"$
                 u:=0 >>
    else u:=nu/du$
  return u
end$

procedure minorder(pol,var)$
begin
  scalar lcofs,mord$
  coeff(den pol,var)$
  mord:=-hipow!*$
  lcofs := rest coeff(num pol,var)$
  if not mord=0 then return (mord+lowpow!*)$
  mord:=1$
a:if lcofs={} then return 0
    else if first lcofs=0 then lcofs:=rest lcofs
    else return mord$
  mord:=mord+1$
  go to a
end$

algebraic$

endmodule$

%***********************************************************************
%*****                                                             *****
%*****      M O D U L E      C H A R P O L                         *****
%*****                                                             *****
%***********************************************************************

module charpol$
% Author: R. Liska
% Program CHARPOL Version REDUCE 3.4     05/1991

symbolic$

fluid '(!*exp !*gcd !*prfourmat)$

switch prfourmat$
!*prfourmat:=t$

procedure coefc1 uu$
begin
  scalar lco,l,u,v,a$
  u:=car uu$
  v:=cadr uu$
  a:=caddr uu$
  lco:=aeval list('coeff,u,v)$
  lco:=cdr lco$
  l:=length lco - 1$
  for i:=0:l do
    <<setel(list(a,i),car lco)$
      lco:=cdr lco >>$
  return (l . 1)
end$

deflist('((coefc1 coefc1)),'simpfn)$

global '(cursym!* coords!* icoords!* unvars!*)$

icoords!*:='(i j k l m n i1 j1 k1 l1 m1 n1)$

if null getd'coordfn then
procedure coordfn$
begin
  scalar cor,icor$
  flag('(into),'delim)$
  cor:=remcomma xread nil$
  remflag('(into),'delim)$
  if cursym!* eq 'into then
      icor:=remcomma xread nil
    else if cursym!* eq '!*semicol!* then
      icor:=icoords!*
    else return symerr('coordfn,t)$
  return list('putcor,
              mkquote cor,
              mkquote icor)
end$

put('coordinates,'stat,'coordfn)$
flag('(putcor),'nochange)$

if null getd'putcor then
procedure putcor(u,v)$
begin
  scalar j$
  j:=1$
  coords!*:=u$
  while u do
    <<if not idp car u then        msgpri
          (" Coordinate ",car u," must be identifier",nil,'hold)$
      if not idp car v then        msgpri
          (" Index ",car v," must be identifier",nil,'hold)$
      put(car u,'index,list car v)$
      put(car v,'coord,list car u)$
      put(car u,'ngrid,j)$
      j:=j+1$
      put(car u,'simpfn,'simpiden)$
      u:=cdr u$
      v:=cdr v >>
end$

if null getd'tcar then
procedure tcar u$
if pairp u then car u
  else u$

if null getd 'grid then
procedure grid u$
eval list(get(car u,'grid),
          mkquote cdr u)$

put('grid,'stat,'rlis)$
put('uniform,'grid,'gridunif)$

if null getd'gridunif then
procedure gridunif u$
flag(u,'uniform)$

flag('(tcon unit charmat ampmat denotemat),'matflg)$

put('unit,'rtypefn,'getrtypecar)$
put('charmat,'rtypefn,'getrtypecar)$
put('ampmat,'rtypefn,'getrtypecar)$
put('denotemat,'rtypefn,'getrtypecar)$

procedure unit u$
generateident length matsm u$

procedure charmat u$
matsm list('difference,list('times,'lam,list('unit,u)),u)$

procedure charpol u$
simp list('det,list('charmat,carx(u,'charpol)))$

put('charpol,'simpfn,'charpol)$

algebraic$
korder lam$

procedure re(x)$
sub(i=0,x)$

procedure im(x)$
(x-re(x))/i$

procedure con(x)$
sub(i=-i,x)$

procedure complexpol x$
begin
  scalar y$
  y:=troot1 x$
  return if im y=0 then y
           else y*con y
end$

procedure troot1 x$
begin
  scalar y$
  y:=x$
  while not(sub(lam=0,y)=y) and sub(lam=1,y)=0 do y:=y/(lam-1)$
  x:=sub(lam=1,y)$
  if not(numberp y or (numberp num y and numberp den y)) then
      write " If  ",re x,"  =  0  and  ",im x,
            "  =  0  , a root of the polynomial is equal to 1."$
  return y
end$

procedure hurw(x)$
% X is a polynomial in LAM, all its roots are |LAMI|<1 <=> for all roots
% of the polynomial HURW(X) holds RE(LAMI)<0.
(lam-1)**deglam(num x)*sub(lam=(lam+1)/(lam-1),x)$

symbolic$

procedure deglam x$
begin
  scalar y,z,exp$
  exp:=!*exp$
  !*exp:=t$
  y:=simp car x$
  if not numberp cdr y then go to e$
  y:=car y$
  if mvar y='lam then z:=ldeg y
    else go to e$
  !*exp:=exp$
  return (z . 1)$
e:typerr(x, "polynomial in LAM")
end$

put('deglam,'simpfn,'deglam)$

procedure unfunc u$
<<unvars!*:=u$
  for each a in u do put(a,'simpfn,'simpiden) >>$

put('unfunc,'stat,'rlis)$

global '(denotation!* denotid!*)$
denotation!*:=nil$
denotid!*:='a$

procedure denotid u$
<<denotid!*:=car u$nil>>$

put('denotid,'stat,'rlis)$

procedure cleardenot$
denotation!*:=nil$

put('cleardenot,'stat,'endstat)$
flag('(cleardenot),'eval)$

algebraic$
array cofpol!*(20)$

procedure denotepol u$
begin
  scalar nco,dco$
  dco:=den u$
  u:=num u$
  nco:=coefc1 (u,lam,cofpol!*)$
  for j:=0:nco do cofpol!*(j):=cofpol!*(j)/dco$
  denotear nco$
  u:=for j:=0:nco sum lam**j*cofpol!*(j)$
  return u
end$

symbolic$

put('denotear,'simpfn,'denotear)$

procedure denotear u$
begin
  scalar nco,x$
  nco:=car u$
  for i:=0:nco do
    <<x:=list('cofpol!*,i)$
      setel(x,mk!*sq denote(getel x,0,i)) >>$
  return (nil .1)
end$

procedure denotemat u$
begin
  scalar i,j,x$
  i:=0$
  x:=for each a in  matsm u collect
       <<i:=i+1$
         j:=0$
         for each b in a collect
           <<j:=j+1$
             denote(mk!*sq b,i,j) >> >>$
  return x
end$

procedure denote(u,i,j)$
% U is prefix form, I,J are integers
begin
  scalar reu,imu,ireu,iimu,eij,fgcd$
  if atom u then return simp u$
  fgcd:=!*gcd$
  !*gcd:=t$
  reu:=simp!* list('re,u)$
  imu:=simp!* list('im,u)$
  !*gcd:=fgcd$
  eij:=append(explode i,explode j)$
  ireu:=intern compress append(append(explode denotid!* ,'(r)),eij)$
  iimu:=intern compress append(append(explode denotid!* ,'(i)),eij)$
  if car reu then insdenot(ireu,reu)$
  if car imu then insdenot(iimu,imu)$
  return simp list('plus,
                   if car reu then ireu
                     else 0,
                   list('times,
                        'i,
                        if car imu then iimu
                          else 0))
end$

procedure insdenot(iden,u)$
denotation!*:=(u . iden) . denotation!*$

procedure prdenot$
for each a in reverse denotation!* do
  varpri(list('!*sq,car a,t),list('setq,cdr a,nil),'only)$

put('prdenot,'stat,'endstat)$
flag('(prdenot),'eval)$

procedure ampmat u$
begin
  scalar x,i,h1,h0,un,rh1,rh0,ru,ph1,ph0,exp$
  exp:=!*exp$
  !*exp:=t$
  fouriersubs()$
  u:=car matsm u$
  x:=for each a in coords!* collect if a='t then 0
                                      else list('times,
                                                tcar get(a,'index),
                                                get(a,'wave),
                                                get(a,'step))$
  x:=list('expp,'plus . x)$
  x:=simp x$
  u:=for each a in u collect resimp quotsq(a,x)$
  gonsubs()$
  u:=for each a in u collect resimp a$
  remfourier()$
a:if null u then go to d$
  ru:=caar u$
  un:=unvars!*$
  i:=1$
b:if un then go to c$
  rh1:=reverse rh1$
  rh0:=reverse rh0$
  h1:=rh1 . h1$
  h0:=rh0 . h0$
  rh0:=rh1:=nil$
  u:=cdr u$
  go to a$
c:rh1:=coefck(ru,list('u1!*,i)) . rh1$
  rh0:=negsq coefck(ru,list('u0!*,i)) . rh0$
  un:=cdr un$
  i:=i+1$
  go to b$
d:h1:=reverse h1$
  h0:=reverse h0$
  if !*prfourmat then
      <<ph1:=for each a in h1 collect
               for each b in a collect prepsq!* b$
        setmatpri('h1,nil . ph1)$
        ph1:=nil$
        ph0:=for each a in h0 collect
               for each b in a collect prepsq!* b$
        setmatpri('h0,nil . ph0)$
        ph0:=nil >>$
  x:=if length h1=1 then list list quotsq(caar h0,caar h1)
       else lnrsolve(h1,h0)$
  x:=for each a in x collect for each b in a collect
         simp list('isimp,list('!*sq,b,nil))$
  !*exp:=exp$
  return x
end$

algebraic procedure isimp x$
begin
  scalar n,d,y$
  n:=num x$
  d:=den x$
  y:=sub(i=-i,d)$
  n:=n*y$
  d:=d*y$
  on gcd$
  y:=n/d$
  off gcd$
  return y
end$

procedure coefck(x,y)$
% X is standard form, Y is prefix form, returns coefficient of Y
% appearing in X, i.e. X contains COEFCK(X,Y)*Y
begin
  scalar ky,xs$
  ky:=!*a2k y$
  xs:=car subf(x,list(ky . 0))$
  xs:=addf(x,negf xs)$
  if null xs then return(nil . 1)$
  xs:=quotf1(xs,!*k2f ky)$
  return if null xs then <<msgpri
    ("COEFCK failed on ",list('sq!*,x . 1,nil)," with ",y,'hold)$
                           xread nil$
                           !*f2q xs>>
           else !*f2q xs
end$

procedure simpfour u$
begin
  scalar nrunv,x,ex,arg,mv,cor,incr,lcor$
  nrunv:=get(car u,'nrunvar)$
a:u:=cdr u$
  if null u then go to r$
  arg:=simp car u$
  mv:=mvar car arg$
  if not atom mv or not numberp cdr arg then return msgpri
      ("Bad index ",car u,nil,nil,'hold)$
  cor:=tcar get(mv,'coord)$
  if not cor member coords!* then return msgpri
      ("Term ",car u," contains non-coordinate ",mv,'hold)$
  if cor member lcor then return msgpri
      ("Term ",car u," means second appearance of coordinate ",cor,
       'hold)$
  if not cor='t and cdr arg>get(cor,'maxden)
    then put(cor,'maxden,cdr arg)$
  lcor:=cor . lcor$
  incr:=addsq(arg,negsq !*k2q mv)$
  if not flagp(cor,'uniform) then return lprie
      ("Non-uniform grids not yet supported")$
  if cor='t then go to ti$
  ex:=list('times,car u,get(cor,'step),get(cor,'wave)) . ex$
  go to a$
ti:if null car incr then x:=list('u0!*,nrunv)
    else if incr= 1 . 1 then x:=list('u1!*,nrunv)
    else return lprie "Scheme is not twostep in time"$
  go to a$
r:for each a in setdiff(coords!*,lcor) do
    if a='t then x:=list('u0!*,nrunv)
      else ex:=list('times,tcar get(a,'index),get(a,'step),get(a,'wave))
                  . ex$
  return simp list('times,x,list('expp,'plus . ex))
end$

procedure fouriersubs$
begin
  scalar x,i$
  for each a in '(expp u1!* u0!*) do put(a,'simpfn,'simpiden)$
  x:=unvars!*$
  i:=1$
a:if null x then go to b$
  put(car x,'nrunvar,i)$
  i:=i+1$
  x:=cdr x$
  go to a$
b:flag(unvars!*,'full)$
  for each a in unvars!* do put(a,'simpfn,'simpfour)$
  for each a in coords!* do
    if not a='t then
    <<x:=intern compress append(explode 'h,explode a)$
      put(a,'step,x)$
      if not flagp(a,'uniform) then put(x,'simpfn,'simpiden)$
      x:=intern compress append(explode 'k,explode a)$
      put(a,'wave,x)$
      x:=intern compress append(explode 'a,explode a)$
      put(a,'angle,x)$
      put(a,'maxden,1) >>$
  algebraic for all z,y,v let
    expp((z+y)/v)=expp(z/v)*expp(y/v),
    expp(z+y)=expp z*expp y
end$

procedure gonsubs$
begin
  scalar xx$
  algebraic for all z,y,v clear expp((z+y)/v),expp(z+y)$
  for each a in coords!* do
    if not a='t then
      <<xx:=list('quotient,
                 list('times,
                      get(a,'maxden),
                      get(a,'angle)),
                 get(a,'step))$
        setk(get(a,'wave),aeval xx)$
        xx:=list('times,
                 get(a,'wave),
                 get(a,'step))$
        mathprint list('setq,
                       get(a,'angle),
                       if get(a,'maxden)=1 then xx
                         else list('quotient,
                                   xx,
                                   get(a,'maxden))) >>$
  algebraic for all x let expp x=cos x+i*sin x$
  algebraic for all x,n such that numberp n and n>1 let
    sin(n*x)=sin x*cos((n-1)*x)+cos x*sin((n-1)*x),
    cos(n*x)=cos x*cos((n-1)*x)-sin x*sin((n-1)*x)$
  for each a in unvars!* do
    <<put(a,'simpfn,'simpiden)$
      remprop(a,'nrunvar) >>
end$

procedure remfourier$
<<algebraic for all x clear expp x$
  algebraic for all x,n such that numberp n and n>1 clear
    sin(n*x),cos(n*x)$
  for each a in coords!* do
    if not a='t then
    <<remprop(a,'step)$
      remprop(remprop(a,'wave),'avalue)$
      remprop(a,'maxden) >> >>$

operator numberp$

algebraic$

endmodule$

%***********************************************************************
%*****                                                             *****
%*****      M O D U L E      H U R W P                             *****
%*****                                                             *****
%***********************************************************************

module hurwp$

% Author: R. Liska
% Program HURWP Version REDUCE 3.4     05/1991

symbolic$

global '(ofl!* mlist!*)$
fluid '(!*exp !*gcd)$

symbolic if not getd 're then algebraic procedure re(x)$
sub(i=0,x)$

symbolic if not getd 'im then algebraic procedure im(x)$
(x-re(x))/i$

symbolic if not getd'con then algebraic procedure con(x)$
sub(i=-i,x)$

flag('(tcon),'matflg)$
put('tcon,'msimpfn,'tcon)$
put('tcon,'rtypefn,'getrtypecar)$

procedure tcon u$
% Calculates complex conjugate and transpose matrix
begin
  scalar v,b$
  v:=matsm list('tp,u)$
  for each a in v do
    <<b:=a$
      while b do
        <<rplaca(b,quotsq(subf(numr car b, '((i minus i))),
                          !*f2q denr car b))$
          b:=cdr b >> >>$
  return v
end$

algebraic$
korder lam$

symbolic if not getd 'hurw then algebraic procedure hurw(x)$
(lam-1)**deglam(x)*sub(lam=(lam+1)/(lam-1),x)$

symbolic$

if not getd 'deglam then procedure deglam x$
begin
  scalar y,z,exp$
  exp:=!*exp$
  !*exp:=t$
  y:=simp car x$
  if not numberp cdr y then go to e$
  y:=car y$
  if mvar y='lam then z:=ldeg y
    else go to e$
  !*exp:=exp$
  return (z . 1)$
e:typerr(x,"Polynomial in LAM")
end$

put('deglam,'simpfn,'deglam)$
global '(positive!* userpos!* userneg!* !*pfactor)$
!*pfactor:=nil$

procedure positivep u$
% U is prefix form. Procedure tests if U>0, eventually writes this
% condition and puts U into POSITIVE!*. If U<=0 then returns NIL,
% if U>0 then T, in other cases 'COND.
% If it does not know if U>0 and program is running in interactive
% mode it asks user if U>0 and return value is based on user reply.
if numberp u then
    if u>0 then t
      else nil
  else if eqcar(u,'!*sq) and fixp caadr u and fixp cdadr u then
           if caadr u*cdadr u>0 then t
             else nil
  else
    begin
      scalar x,exp$
      exp:=!*exp$
      if !*pfactor and
             member('factor,mlist!*) then
           <<!*exp:=nil$
             u:=aeval list('ppfactor,u) >>$
      u:=prepsq!* simp u$
      !*exp:=exp$
      x:=if terminalp() and null ofl!* then
             begin
               scalar y,z$
               prin2!* "Is it true, that  "$
               maprin u$
               prin2!* "  >  0    ?"$
             a:prin2!* "  Reply (Y/N/?)"$
               terpri!* t$
               y:=read()$
               if y eq 'y then <<z:=t$ userpos!*:=u . userpos!* >>
                 else if y eq 'n
                  then <<z:=nil$ userneg!*:=u . userneg!*>>
                 else if y eq '? then z:='cond
                 else go to a$
               return z
             end
           else 'cond$
      if x eq 'cond then
          if null positive!* then positive!*:= list (1 . u)
            else positive!* := ((caar positive!* + 1) . u) . positive!*$
      return x
    end$

global'(hconds!*)$

algebraic$
array cof(20),fcof(20)$
share hconds!*$

procedure ppfactor x$
begin
  scalar d,n,de$
  d:=factorize(num x)$
  n:=for each a in d product a$
  if den x=1 then return n$
  d:=factorize(den x)$
  de:=for each a in d product a$
  return (n/de)
end$

procedure hurwitzp u$
% U is a polynomial in LAM. Procedure tests if it is Hurwitz polynomial
% i.e. for all its rools LAMI holds RE(LAMI)<0.
% Returned values: YES  - definitely yes
%                  NO   - definitely no
%                  COND - if conditions holds (all members of POSITIVE!*
%                         are >0)
if im u=0 then rehurwp u
  else cohurwp u$

symbolic$

procedure coef1(u,v,a)$
begin
  scalar lco,l$
  lco:=aeval list('coeff,u,v)$
  lco:=cdr lco$
  l:=length lco - 1$
  for i:=0:l do
    <<setel(list(a,i),car lco)$
      lco:=cdr lco >>$
  return l
end$

procedure rehurwp u$
begin
  scalar deg,hurp,gcd$
  gcd:=!*gcd$
  !*gcd:=t$
  deg:=coef1(car u,'lam,'cof)$
  if deg=0 then return typerr(u,"Polynomial in LAM")$
  positive!* := userpos!* := userneg!* := nil$
  if deg <= 2 then
      <<for i:=0:deg do setel(list('cof,i),
                              aeval list('quotient,
                                         getel list('cof,i),
                                         getel list('cof,deg)))$
        if deg=1 then hurp:=positivep getel list('cof,0)
          else if deg=2 then hurp:=
                   if positivep getel list('cof,0) and
                      positivep getel list('cof,1) then
                        if positive!* then 'cond
                          else t
                      else if positive!* then 'cond    % added 08/08/91
                      else nil$
        printcond(nil) >>
    else hurp:=rehurwp1 deg$
  !*gcd:=gcd$
  return rethurp hurp
end$

procedure rethurp hurp$
<<hconds!*:= 'list . if positive!* then mapcar(positive!*,function cdr)
                       else nil$
  !*k2q(if null hurp then 'no
          else if null positive!* then 'yes
          else 'cond) >>$

put('rehurwp,'simpfn,'rehurwp)$

procedure cohurwp u$
begin
  scalar deg$
  u:=reval list('sub,'(equal lam (times i lam)),car u)$
  deg:=coef1(u,'lam,'cof)$
  if deg=0 then return typerr(u,"Polynomial in LAM")$
  positive!* := userpos!* := userneg!* :=nil$
  if aeval list('im,getel list('cof,deg))=0 then
        for j:= 0:deg do setel(list('cof,j),
                              aeval list('times,'i,getel list('cof,j)))$
  return rethurp cohurwp1 (deg)
end$

put('cohurwp,'simpfn,'cohurwp)$

procedure rehurwp1 deg$
begin
  scalar i,bai,bdi,x,lich,sud,bsud,matr,hmat,csud,clich,dsud,dlich$
a:i:=deg$
  csud:=clich:=nil$
  bsud:=t$
b:x:=positivep getel list('cof,i)$
  if null x then go to c
    else if x eq t then bai:=t
    else if x eq 'cond then
      if i=deg or i=0 then <<csud:=caar positive!* . csud$
                             clich:=caar positive!* . clich >>
        else if bsud then csud:=caar positive!* . csud
        else clich:=caar positive!* . clich$
  i:=i-1$
  bsud:=not bsud$
  if i>=0 then go to b$
  go to d$
  % Change of sign AI = - AI
c:if bai or bdi then go to n
    else bai:=t$
  for i:=0:deg do setel(list('cof,i),
                        aeval list('minus,getel list('cof,i)))$
  go to a$
  % Checking DI > 0 - Hurwitz determinants
  % Splitting to odd and even coeffs. AI, A0 is coeff. by LAM**DEG
d:bsud:=t$
  for i:=deg step -1 until 0 do
    <<x:=simp getel list('cof,i)$
      if bsud then sud:=x . sud
        else lich:=x . lich$
      bsud:=not bsud >>$
  sud:=reverse sud$
  lich:=reverse lich$
  % Filling of SUD and LICH on the length DEG by zeroes from right
  sud:=filzero(sud,deg)$
  lich:=filzero(lich,deg)$
  dsud:=dlich:=nil$
  matr:=nil$
  i:=1$
  bsud:=nil$
d1:matr:=nconc(matr,list lich)$
  lich:=(nil . 1) . lich$
d2:hmat:=cutmat(matr,i)$
  x:=mk!*sq detq hmat$
  x:=positivep x$  % Necessary to add storing of odd and even DIs
  if null x then
      if bsud then go to n
        else go to c
    else if x eq t and not bsud then bdi:=t
    else if x eq 'cond then
      if bsud then dsud:=caar positive!* . dsud
        else dlich:=caar positive!* . dlich$
  i:=i+1$
  bsud:=not bsud$
  if i>deg then go to k$
  if not bsud then go to d1$
  matr:=nconc(matr,list sud)$
  sud:=(nil . 1) . sud$
  go to d2$
n:return nil$
k:if null positive!* or ((null csud or null clich) and
                         (null dsud or null dlich))
      then return <<printuser()$ t>>$
  prin2t "If we denote:"$
  printcond(t)$
  printdef('c1,clich:=reverse clich)$
  printdef('c2,csud:=reverse csud)$
  printdef('d1,dlich:=reverse dlich)$
  printdef('d2,dsud:=reverse dsud)$
  prin2t "Necessary and sufficient conditions are:"$
  prin2t if null csud or null clich then         "  (D1)  OR  (D2)"
           else if null dsud or null dlich then  "  (C1)  OR  (C2)"
           else "  (  (C1)  OR  (C2)  )  AND  (  (D1)  OR  (D2)  )"$
  printuser()$
  return 'cond
end$

procedure printcond(x)$
<<if not x then
      prin2t "Necessary and sufficient conditions are:"$
  positive!*:=reverse positive!*$
  for each a in positive!* do
    <<if x then <<prin2!* " ("$
                  prin2!* car a$
                  prin2!* ")  " >>$
      maprin cdr a$
      prin2!* "  >  0"$
      terpri!* t >>$
  if not x then printuser() >>$

procedure printuser()$
if userpos!* or userneg!* then
    <<prin2t"You have explicitly stated:"$
      for each a in userpos!* do <<maprin a$
                                   prin2!* "  >  0"$
                                   terpri!* t >>$
      for each a in userneg!* do <<maprin a$
                                   prin2!* "  <=  0"$
                                   terpri!* t >> >>$

procedure printdef(x,y)$
if y then
    <<prin2!* " ("$
      prin2!* x$
      prin2!* ")   ("$
      prin2!* car y$
      prin2!* ")"$
      if cdr y then for each a in cdr y do
          <<prin2!* " AND ("$
            prin2!* a$
            prin2!* ")" >>$
      terpri!* t >>$

procedure filzero(x,n)$
% Adds zeros (in S.Q. form) to the list X from right on the length N
begin
  scalar y,i$
  y:=x$
  i:=1$
  if null x then return typerr(x,"Empty list")$
  while cdr y do
    <<y:=cdr y$
      i:=i+1>>$
  while i<n do
    <<rplacd(y,list(nil . 1))$
      y:=cdr y$
      i:=i+1 >>$
  return x
end$

procedure cutmat(x,n)$
% From each member of list X, i.e. row of a matrix, remains
% the first N elements
for each a in x collect cutrow(a,n)$

procedure cutrow(y,n)$
begin
  scalar i,z,zz$
  i:=1$
  z:=list car y$
  zz:=z$
  y:=cdr y$
  while i<n do
    <<rplacd(zz,list car y)$
      y:=cdr y$
      zz:=cdr zz$
      i:=i+1 >>$
  return z
end$

procedure cohurwp1 (deg)$
begin
  scalar k,x,y,ak,bk,akk,bkk,matr,hmat$
  % Splitting on RE and IM part
  for j:=0:deg do
    <<x:=getel list('cof,j)$
      y:=simp list('re,x)$
      x:=resimp simp list('quotient,list('difference,x,mk!*sq y),'i)$
      ak:=x . ak$
      bk:=y . bk >>$
  % Construction of coeffs. AI, BI
  positive!*:=userpos!*:=userneg!*:=nil$
  akk:=filzero(ak,2*deg)$
  bkk:=filzero(bk,2*deg)$
  k:=2$
d1:matr:=nconc(matr,list akk)$
  matr:=nconc(matr,list bkk)$
  akk:=(nil . 1) . akk$
  bkk:=(nil . 1) . bkk$
  hmat:=cutmat(matr,k)$
  x:=mk!*sq detq hmat$
  x:=positivep x$
  if null x then go to n$
  if k=2*deg then go to ko$
  k:=k+2$
  go to d1$
n:return nil$
ko:printcond(nil)$
  return t
end$

algebraic$

endmodule$

%***********************************************************************
%*****                                                            ******
%*****      M O D U L E      L I N B A N D                        ******
%*****                                                            ******
%***********************************************************************

module linband$

% Author: R. Liska
% Program LINBAND Version REDUCE 3.4     05/1991

% GENTRAN package has to be loaded prior to this module

symbolic$

global'(fortcurrind!* genstmtnum!* genstmtincr!*)$
fluid'(!*period)$            % declaration for 3.4
%global'(!*period)$          % declaration for 3.3

fluid'(!*imsl !*nag !*essl)$

switch imsl,nag,essl$
!*imsl:=nil$
!*nag:=nil$
!*essl:=nil$

procedure ison x$
if eval x then 1
  else 0$

operator ison$

if null getd 'gentempst then
procedure gentempst$
list('gentemp,xread t)$

global'(temp!*)$
temp!*:=nil$

procedure gentemp u$
<<temp!* := ((!*period . fortcurrind!*) . u) . temp!*$ nil>>$

put('gentemp,'stat,'gentempst)$
put('gentemp,'formfn,'formgentran)$
load!-package 'gentran;

procedure outtemp$
begin
  scalar period,fortind$
  period:=!*period$
  fortind:=fortcurrind!*$
  for each a in reverse temp!* do
    <<!*period:=caar a$
      fortcurrind!*:=cdar a$
      eval list('gentran,mkquote cdr a,nil)>>$
  temp!* := nil$
  !*period:=period$
  fortcurrind!*:=fortind$
  return nil
end$

put('outtemp,'stat,'endstat)$
flag('(outtemp),'eval)$

algebraic$

procedure genlinbandsol(nlc,nuc,system)$
% Generates FORTRAN program for solving of linear algebraic system
% of equations with band matrix with NLC lower codiagonals and NUC
% upper codiagonals.
begin
  scalar pvars,svars,vareq,fveq$
  %  PVARS  - list of variables before actual variable
  %  SVARS  - list of variables after actual variable
  %  VAREQ  - actual v-equation (list {variable equation})
  symbolic
    <<put('list,'evfno,get('list,'evfn))$
      put('list,'evfn,'listnoeval)$
      put('equal,'psopfno,get('equal,'psopfn))$
      put('equal,'psopfn,'equalaeval)>>$
  system:=expanddo(nlc,nuc,system)$
  vareq:=first system$
  pvars:={}$
  svars:=findsvars(nuc,vareq,system)$
  off period$
  gentran n:=1$
  gentemp n:=1$
  on period$
  ncol!*:=nlc+nuc+1$
  for i:=1:nlc do
    <<genvareq(pvars,svars,vareq,nlc,nlc-i+1,pfix!*)$
      pvars:=append(pvars,first vareq . {})$
      system:=nextvareqsys(vareq,system)$
      vareq:=first system$
      system:=rest system$
      gennp1()$
      svars:=findsvars(nuc,vareq,system) >>$
  while length svars=nuc do
    <<genvareq(pvars,svars,vareq,nlc,0,0)$
      pvars:=append(rest pvars,first vareq . {})$
      fveq:=first system$
      system:=nextvareqsys(vareq,system)$
      vareq:=first system$
      system:=rest system$
  % Get in and get out of loop
      if (ffst system=do) and (first vareq=first frrfst system and
          rest vareq=rest frrfst system) then
          pvars:=findpvars(nlc,first system)
        else if first fveq=do and not(ffst system=do) then
          pvars:=lastvars(nlc,fveq)$
      gennp1()$
      svars:=findsvars(nuc,vareq,system) >>$
  for i:=1:nuc do
    <<genvareq(pvars,svars,vareq,nlc,i,sfix!*)$
      pvars:=append(rest pvars,first vareq . {})$
      system:=nextvareqsys(vareq,system)$
      vareq:=first system$
      system:=rest system$
      if not(svars={}) then
          <<svars:=rest svars$
            gennp1() >> >>$
  off period$
  if ison !*imsl = 1 then pvars:=gencall!-imsl(nlc,nuc)
    else if ison !*nag = 1 then pvars:=gencall!-nag(nlc,nuc)
    else if ison !*essl= 1 then pvars:=gencall!-essl(nlc,nuc)
    else pvars:=gencall!-linpack(nlc,nuc)$
  on period$
  outtemp$
  symbolic <<put('list,'evfn,remprop('list,'evfno))$
             put('equal,'psopfn,remprop('equal,'psopfno))>>
end$

procedure gencall!-imsl (nlc,nuc)$
gentran
  <<literal tab!*,"CALL LEQT1B(ACOF,N,",eval nlc,",",eval nuc,
              ",IACOF,ARHS,1,IARHS,0,XL,IER)",cr!*$
    literal "C  IACOF IS ACTUAL 1-ST DIMENSION OF THE ACOF ARRAY",cr!*$
    literal "C  IARHS IS ACTUAL 1-ST DIMENSION OF THE ARHS ARRAY",cr!*$
    literal "C  XL IS WORKING ARRAY WITH SIZE N*(NLC+1)",cr!*$
    literal
       "C  WHERE N IS NUMBER OF EQUATIONS NLC NUMBER OF LOWER",cr!*$
    literal "C  CODIAGONALS",cr!*$
    literal
       "C  IF IER=129( .NE.0) MATRIX ACOF IS ALGORITHMICALLY SINGULAR",
        cr!*$
    literal tab!*,"IF(IER.NE.0) CALL ERROUT",cr!*>>$

procedure gencall!-linpack(nlc,nuc)$
if ncol!*=3 and nlc=1 then gencall!-linpack!-trid(nlc,nuc)
  else gentran
  <<literal tab!*,"CALL DGBFA(ACOF,IACOF,N,",eval nlc,",",eval nuc,
            ",IPVT,IER)",cr!*$
    literal "C  N IS NUMBER OF EQUATIONS",cr!*$
    literal "C  ACOF IS ARRAY OF DIMENSION (IACOF,P), P >= N",cr!*$
    literal "C     IACOF >= ",eval(nlc+ncol!*),cr!*$
    literal "C  IPVT IS ARRAY OF DIMENSION AT LEAST (N)",cr!*$
    literal "C  IF (IER.NE.0) MATRIX ACOF IS ALGORITHMICALLY SINGULAR",
              cr!*$
    literal tab!*,"IF(IER.NE.0) CALL ERROUT",cr!*$
    literal tab!*,"CALL DGBSL(ACOF,IACOF,N,",eval nlc,",",eval nuc,
            ",IPVT,ARHS,0)",cr!*>>$

procedure gencall!-linpack!-trid(nlc,nuc)$
gentran
  <<literal tab!*,"CALL DGTSL(N,ALCD,AD,AUCD,ARHS,IER)",cr!*$
    literal "C  N IS NUMBER OF EQUATIONS",cr!*$
    literal
      "C  ALCD,AD,AUCD,ARHS ARE ARRAYS OF DIMENSION AT LEAST (N)",cr!*$
    literal "C  IF (IER.NE.0) MATRIX ACOF IS ALGORITHMICALLY SINGULAR",
              cr!*$
    literal tab!*,"IF(IER.NE.0) CALL ERROUT",cr!* >>$

procedure gencall!-essl(nlc,nuc)$
if ncol!*=3 and nlc=1 then gencall!-essl!-trid(nlc,nuc)
  else gentran
  <<literal tab!*,"CALL DGBF(ACOF,IACOF,N,",eval nlc,",",eval nuc,
            ",IPVT)",cr!*$
    literal "C  N IS NUMBER OF EQUATIONS",cr!*$
    literal "C  ACOF AND ARHS ARE DOUBLE PRECISION TYPE",cr!*$
    literal "C  FOR SINGLE PRECISION CHANGE DGBF TO SGBF AND ",
            "DGBS TO SGBS",cr!*$
    literal "C  ACOF IS ARRAY OF DIMENSION (IACOF,P), P >= N",cr!*$
    literal "C     IACOF >= ",eval(nlc+ncol!*+15),cr!*$
    literal "C  ARHS IS ARRAY OF DIMENSION AT LEAST (N)",cr!*$
    literal "C  IPVT IS INTEGER ARRAY OF DIMENSION AT LEAST (N)",cr!*$
    literal tab!*,"CALL DGBS(ACOF,IACOF,N,",eval nlc,",",eval nuc,
            ",IPVT,ARHS)",cr!*>>$

procedure gencall!-essl!-trid(nlc,nuc)$
gentran
  <<literal tab!*,"CALL DGTF(N,ALCD,AD,AUCD,AF,IPVT)",cr!*$
    literal "C  N IS NUMBER OF EQUATIONS",cr!*$
    literal
    "C  ALCD,AD,AUCD,AF,ARHS ARE ARRAYS OF DIMENSION AT LEAST (N)",cr!*$
    literal "C  THESE ARRAYS ARE DOUBLE PRECISION TYPE",cr!*$
    literal "C  FOR SINGLE PRECISION CHANGE DGTF TO SGTF AND ",
            "DGTS TO SGTS",cr!*$
    literal
    "C  IPVT IS INTEGER ARRAY OF DIMENSION AT LEAST (N+3)/8",cr!*$
    literal tab!*,"CALL DGTS(N,ALCD,AD,AUCD,AF,IPVT,ARHS)",cr!* >>$

procedure gencall!-nag(nlc,nuc)$
if ncol!*=3 and nlc=1 then gencall!-nag!-trid(nlc,nuc)
  else gentran
  <<ier:=0$
    literal tab!*,"CALL F01LBF(N,",eval nlc,",",eval nuc,
         ",ACOF,IACOF,AL,IAL,IN,IV,IER)",cr!*$
    literal "C  N IS NUMBER OF EQUATIONS",cr!*$
    literal "C  ACOF IS ARRAY OF DIMENSION (IACOF,P), P >= N",cr!*$
    literal "C      IACOF >= MIN(N,",eval ncol!*,")",cr!*$
    literal "C  AL IS ARRAY OF DIMENSION (IAL,P), P >= N",cr!*$
    literal "C      IAL >= MAX(1,",eval nlc,")",cr!*$
    literal "C  IN IS INTEGER ARRAY OF DIMENSION AT LEAST (N)",cr!*$
    literal tab!*,"IF(IER.NE.0) CALL ERROUT",cr!*$
    literal tab!*,"CALL F04LDF(N,",eval nlc,",",eval nuc,
            ",1,ACOF,IACOF,AL,IAL,IN,ARHS,IARHS,IER)",cr!*$
    literal "C  ARHS IS ARRAY OF DIMENSION (IARHS), IARHS >= N",cr!*$
    literal tab!*,"IF(IER.NE.0) CALL ERROUT",cr!* >>$

procedure gencall!-nag!-trid(nlc,nuc)$
gentran
  <<ier:=0$
    literal tab!*,
          "CALL F01LEF(N,AD,0.,AUCD,ALCD,1.E-10,AU2CD,IN,IER)",cr!*$
    literal "C  N IS NUMBER OF EQUATIONS",cr!*$
    literal
"C  ALCD,AD,AUCD,AU2CD,ARHS ARE ARRAYS OF DIMENSION AT LEAST (N)",cr!*$
    literal "C  IN IS INTEGER ARRAY OF DIMENSION AT LEAST (N)",cr!*$
    literal tab!*,"IF(IER.NE.0 .OR. IN(N).NE.0) CALL ERROUT",cr!*$
    literal tab!*,
         "CALL F04LEF(1,N,AD,AUCD,ALCD,AU2CD,IN,ARHS,0.,IER)",cr!*$
    literal tab!*,"IF(IER.NE.0) CALL ERROUT",cr!* >>$

procedure gennp1$
<<off period$
  gentran n:=n+1$
  gentemp n:=n+1$
  on period >>$

% Definition of operator SUBE

symbolic$

symbolic procedure simpsube u$
begin
  scalar x$
a:if null cdr u then go to d
    else if null eqexpr car u then errpri2(car u,t)$
  x:=list('equal,reval cadar u,caddar u) . x$
  u:=cdr u$
  go to a$
d:x:=reverse(car u . x)$
  x:=subeval x$
  return x
end$

symbolic put('sube,'psopfn,'simpsube)$

algebraic$

% Procedures FFRRST etc.

procedure ffst u$
first first u$
procedure frst u$
first rest u$
procedure rfst u$
rest first u$
procedure rrst u$
rest rest u$

procedure fffst u$
first ffst u$
procedure ffrst u$
first frst u$
procedure frfst u$
first rfst u$
procedure frrst u$
first rrst u$
procedure rffst u$
rest ffst u$
procedure rfrst u$
rest frst u$
procedure rrfst u$
rest rfst u$
procedure rrrst u$
rest rrst u$

procedure ffffst u$
ffst ffst u$
procedure fffrst u$
ffst frst u$
procedure ffrfst u$
ffst rfst u$
procedure ffrrst u$
ffst rrst u$
procedure frffst u$
frst ffst u$
procedure frfrst u$
frst frst u$
procedure frrfst u$
frst rfst u$
procedure frrrst u$
frst rrst u$
procedure rfffst u$
rfst ffst u$
procedure rffrst u$
rfst frst u$
procedure rfrfst u$
rfst rfst u$
procedure rfrrst u$
rfst rrst u$
procedure rrffst u$
rrst ffst u$
procedure rrfrst u$
rrst frst u$
procedure rrrfst u$
rrst rfst u$
procedure rrrrst u$
rrst rrst u$

procedure findsvars(nuc,vareq,system)$
% Looks for NUC next variables in SYSTEM
% VAREQ is actual v-equation
if ffst system=do then findsvarsdo(nuc,vareq,first system)
  else findsvars1(nuc,rest system)$

procedure findsvars1(nuc,system)$
% Substitutes values for loop variable
if nuc=0 or system={} then {}
  else if ffst system=do then fsvars1do(nuc,first system)
  else ffst system . findsvars1(nuc-1,rest system)$

procedure fsvars1do(nuc,cykl)$
% Substitutes into the loop CYKL
begin
  scalar id,from,step,syst,x,y$
  cykl:=rest cykl$
  syst:=first cykl$
  id:=first syst$
  from:=frst syst$
  step:=frrrst syst$
  syst:=rest cykl$
  x:={}$
a:y:=sube(id=from,ffst syst)$
  x:=y . x$
  nuc:=nuc-1$
  if nuc=0 then go to r$
  syst:=rest syst$
  if not(syst={}) then go to a$
  syst:=rest cykl$
  from:=from+step$
  go to a$
r:x:=reverse x$
  return x
end$

procedure findsvarsdo(nuc,vareq,cykl)$
% Does not substitute for loop variable, only increases it
% by STEP if it is necessary
begin
  scalar id,add1,step,syst,x,y$
  cykl:=rest cykl$
  syst:=first cykl$
  id:=first syst$
  step:=frrrst syst$
  syst:=rest cykl$
  while not(first vareq=ffst syst and rest vareq=rfst syst)
     do syst:=rest syst$
  syst:=rest syst$
  add1:=0$
  x:={}$
a:if syst={} then go to b$
  y:=sube(id=id+add1,ffst syst)$
  x:=y . x$
  nuc:=nuc-1$
  if nuc=0 then go to r$
  syst:=rest syst$
  go to a$
b:syst:=rest cykl$
  add1:=add1+step$
  go to a$
r:x:=reverse x$
  return x
end$

procedure expanddo(nlc,nuc,system)$
% Every loop in SYSTEM is expanded so that more than or equal to
% NLC first elements and more than or equal NUC last elements are
% excluded from the loop, and changes the parameters of loop so
% that its meaning remains the same
begin
  scalar x$
  x:={}$
a:if system={} then go to r$
  if ffst system=do then x:=append(expddo(nlc,nuc,first system),x)
    else x:=first system . x$
  system:=rest system$
  go to a$
r:x:=reverse x$
  return x
end$

procedure expddo(nlc,nuc,cykl)$
% Performs the expansion of the loop CYKL - returns reverse list
begin
  scalar id,from,to1,step,syst,lsyst,ns,x,y,bn$
  cykl:=rest cykl$
  syst:=first cykl$
  id:=first syst$
  from:=frst syst$
  to1:=frrst syst$
  step:=frrrst syst$
  syst:=rest cykl$
  lsyst:=length syst$
  ns:=quotient1(nlc,lsyst)$
  if nlc>ns*lsyst then ns:=ns+1$
  bn:=0$
  x:={}$
a:y:=sube(id=from,ffst syst) . sube(id=from,frfst syst) . {}$
  x:=y . x$
  syst:=rest syst$
  if not(syst={}) then go to a$
  ns:=ns-1$
  from:=from+step$
  if ns=0 then go to b$
  syst:=rest cykl$
  go to a$
b:if bn=1 then go to r$
  syst:=rest cykl$
  ns:=quotient1(nuc,lsyst)$
  if nuc>ns*lsyst then ns:=ns+1$
  to1:=to1-ns*step$
  y:=do . (id . from . to1 . step . {}) . syst$
  x:=y . x$
  from:=to1+step$
  bn:=1$
  go to a$
r:return x
end$

symbolic procedure quotient1(u,v)$
quotient(u,v)$

symbolic operator quotient1$
operator acof,arhs$

procedure genvareq(pvars,svars,vareq,nlc,nzero,mode)$
if ison !*imsl = 1 then
       genvareq!-imsl(pvars,svars,vareq,nlc,nzero,mode)
  else if ison !*nag = 1 then
       genvareq!-nag(pvars,svars,vareq,nlc,nzero,mode)
  else genvareq!-linpack(pvars,svars,vareq,nlc,nzero,mode)$

procedure genvareq!-imsl(pvars,svars,vareq,nlc,nzero,mode)$
% Generates N-th row of coeff. matrix ACOF and right hand side ARHS
% according to the v-equation VAREQ.
% NZERO is number of zeroes before or after (according to MODE).
% Matrix ACOF is transformed to IMSL band matrix storage.
begin
  integer j$
  scalar var,rhside,lhside,x,y$
  if not(length pvars + length svars+1+nzero=ncol!*) then return
      write" Unconsistent PVARS:",pvars," SVARS:",svars," NZERO:",nzero$
  var:=first vareq$
  vareq:=frst vareq$
  rhside:=rhs vareq$
  lhside:=lhs vareq$
  j:=1$
  x:=0$
  if mode=pfix!* then while j<=nzero do
      <<gentran acof(n,eval j):=0$
        j:=j+1 >>$
  for each a in pvars do
    <<y:=lincof(lhside,a)$
      x:=x+a*y$
      gentran acof(n,eval j):=:y$
      j:=j+1>>$
  y:=lincof(lhside,var)$
  x:=x+var*y$
  gentran acof(n,eval j):=:y$
  j:=j+1$
  for each a in svars do
    <<y:=lincof(lhside,a)$
      x:=x+a*y$
      gentran acof(n,eval j):=:y$
      j:=j+1>>$
  if mode=sfix!* then while j<=ncol!* do
      <<gentran acof(n,eval j):=0$
        j:=j+1 >>$
  gentran arhs(n):=:rhside$
  gentemp eval(var):=arhs(n)$
  if not(x-lhside=0) then write " For equation ",vareq," given only ",
      "variables ",pvars,svars,var$
  return
end$

procedure genvareq!-linpack(pvars,svars,vareq,nlc,nzero,mode)$
% Generates N-th row of coeff. matrix ACOF and right hand side ARHS
% according to the v-equation VAREQ.
% NZERO is number of zeroes before or after (according to MODE).
% Matrix ACOF is transformed to LINPACK band matrix storage.
% NCOL!* is the band width.
begin
  integer j,jj,nn$
  scalar var,rhside,lhside,x,y$
  if not(length pvars + length svars+1+nzero=ncol!*) then return
      write" Unconsistent PVARS:",pvars," SVARS:",svars," NZERO:",nzero$
  if nlc=1 and ncol!*=3 then return
         genvareq!-linpack!-trid(pvars,svars,vareq,nlc,nzero,mode)$
  var:=first vareq$
  vareq:=frst vareq$
  rhside:=rhs vareq$
  lhside:=lhs vareq$
  j:=n-nlc$
  jj:=1$
  nn:=ncol!*+nlc$
  x:=0$
  if mode=pfix!* then while jj<=nzero do
      <<nn:=nn-1$
        jj:=jj+1$
        j:=j+1 >>$
  for each a in pvars do
    <<y:=lincof(lhside,a)$
      x:=x+a*y$
      gentran acof(nn,j)::=:y$
      nn:=nn-1$
      j:=j+1>>$
  y:=lincof(lhside,var)$
  x:=x+var*y$
  gentran acof(nn,j)::=:y$
  nn:=nn-1$
  j:=j+1$
  for each a in svars do
    <<y:=lincof(lhside,a)$
      x:=x+a*y$
      gentran acof(nn,j)::=:y$
      nn:=nn-1$
      j:=j+1>>$
  gentran arhs(n):=:rhside$
  gentemp eval(var):=arhs(n)$
  if not(x-lhside=0) then write " For equation ",vareq," given only ",
      "variables ",pvars,svars,var$
  return
end$

procedure genvareq!-linpack!-trid(pvars,svars,vareq,nlc,nzero,mode)$
begin
  scalar var,rhside,lhside,x,y$
  var:=first vareq$
  vareq:=frst vareq$
  rhside:=rhs vareq$
  lhside:=lhs vareq$
  x:=0$
  for each a in pvars do
    <<y:=lincof(lhside,a)$
      x:=x+a*y$
      gentran alcd(n):=:y >>$
  y:=lincof(lhside,var)$
  x:=x+var*y$
  gentran ad(n):=:y$
  for each a in svars do
    <<y:=lincof(lhside,a)$
      x:=x+a*y$
      gentran aucd(n):=:y >>$
  gentran arhs(n):=:rhside$
  gentemp eval(var):=arhs(n)$
  if not(x-lhside=0) then write " For equation ",vareq," given only ",
      "variables ",pvars,svars,var$
  return
end$

procedure genvareq!-nag(pvars,svars,vareq,nlc,nzero,mode)$
% Generates N-th row of coeff. matrix ACOF and right hand side ARHS
% according to the v-equation VAREQ.
% NZERO is number of zeroes before or after (according to MODE).
% Matrix ACOF is transformed to NAG band matrix storage.
% NCOL!* is the band width.
begin
  integer j$
  scalar var,rhside,lhside,x,y$
  if not(length pvars + length svars+1+nzero=ncol!*) then return
      write" Unconsistent PVARS:",pvars," SVARS:",svars," NZERO:",nzero$
  if nlc=1 and ncol!*=3 then return
         genvareq!-nag!-trid(pvars,svars,vareq,nlc,nzero,mode)$
  var:=first vareq$
  vareq:=frst vareq$
  rhside:=rhs vareq$
  lhside:=lhs vareq$
  j:=1$
  x:=0$
  for each a in pvars do
    <<y:=lincof(lhside,a)$
      x:=x+a*y$
      gentran acof(eval j,n):=:y$
      j:=j+1>>$
  y:=lincof(lhside,var)$
  x:=x+var*y$
  gentran acof(eval j,n):=:y$
  j:=j+1$
  for each a in svars do
    <<y:=lincof(lhside,a)$
      x:=x+a*y$
      gentran acof(eval j,n):=:y$
      j:=j+1>>$
  gentran arhs(n):=:rhside$
  gentemp eval(var):=arhs(n)$
  if not(x-lhside=0) then write " For equation ",vareq," given only ",
      "variables ",pvars,svars,var$
  return
end$

procedure genvareq!-nag!-trid(pvars,svars,vareq,nlc,nzero,mode)$
begin
  scalar var,rhside,lhside,x,y$
  var:=first vareq$
  vareq:=frst vareq$
  rhside:=rhs vareq$
  lhside:=lhs vareq$
  x:=0$
  for each a in pvars do
    <<y:=lincof(lhside,a)$
      x:=x+a*y$
      gentran alcd(n):=:y >>$
  y:=lincof(lhside,var)$
  x:=x+var*y$
  gentran ad(n):=:y$
  for each a in svars do
    <<y:=lincof(lhside,a)$
      x:=x+a*y$
      gentran aucd(n+1):=:y >>$
  gentran arhs(n):=:rhside$
  gentemp eval(var):=arhs(n)$
  if not(x-lhside=0) then write " For equation ",vareq," given only ",
      "variables ",pvars,svars,var$
  return
end$

procedure lincof(expre,ker)$
% Expression EXPRE is linear in kernel KER.
% Returns coeff. of KER in EXPRE.
(expre-sube(ker=0,expre))/ker$

stackdolabel!*:={}$

procedure nextvareqsys(vareq,system)$
% Looks for the next v-equation. Returns the new v-equation . SYSTEM.
% During get into the loop generates the beginning of the loop,
% during get out of the loop generates end of the loop.
if rest system={} then {} . {}
  else if ffst system=do then nextvesdo(vareq,system)
  else if ffrst system=do then nextvesdofst(rest system)
  else frst system . rest system$

procedure nextvesdofst(system)$
% Get into the loop
begin
  scalar id,from,to1,step$
  id:=frfst system$
  from:=frst id$
  to1:=frrst id$
  step:=frrrst id$
  id:=first id$
  genstmtnum!*:=genstmtnum!*+genstmtincr!*$
  gentran literal tab!*,"DO ",eval(genstmtnum!*)," ",eval(id),"=",
          eval(from),",",eval(to1),",",eval(step),cr!*$
  stackdolabel!*:=genstmtnum!* . stackdolabel!*$
  genstmtnum!*:=genstmtnum!*+genstmtincr!*$
  gentemp <<literal tab!*,"DO ",eval(genstmtnum!*)," ",
            eval(id),"=",eval(from),
          ",",eval(to1),",",eval(step),cr!*>>$
  fortcurrind!*:=fortcurrind!* + 4$
  stackdolabel!*:=genstmtnum!* . stackdolabel!*$
  id:=frrfst system . system$
  return id
end$

procedure nextvesdo(vareq,system)$
% SYSTEM begins with a loop - test on the end of loop.
% Suppose that after the loop cannot be another loop, which
% follows from EXPANDDO.
begin
  scalar vareqs$
  vareqs:=rrfst system$
  while not(first vareq=ffst vareqs and rest vareq=rfst vareqs) and
        not(rest vareqs={}) do vareqs:=rest vareqs$
  vareqs:=rest vareqs$
  if vareqs={} then
    % End of loop
      <<fortcurrind!* := fortcurrind!* - 4$
        gentemp<<literal eval first stackdolabel!*,tab!*,"CONTINUE",
                 cr!*>>$
        stackdolabel!*:=rest stackdolabel!*$
        gentran literal eval first stackdolabel!*,tab!*,"CONTINUE",cr!*$
        stackdolabel!*:=rest stackdolabel!*$
        vareqs:=frst system . rest system >>
    else vareqs:=first vareqs . system$
  return vareqs
end$

procedure findpvars(nlc,cykl)$
% Looks for NLC previous variables during geting into the loop
begin
  scalar id,step$
  id:=frst cykl$
  step:=frrrst id$
  id:=first id$
  cykl:=reverse rrst cykl$
  id:=reverse fsvars1do(nlc,
                       do . (id . (id-step) . 0 . (-step) . {}) . cykl)$
  return id
end$

procedure lastvars(nlc,cykl)$
% Looks for the NLC last variables of the loop CYKL
begin
  scalar id,step,to1$
  id:=frst cykl$
  to1:=frrst id$
  step:=frrrst id$
  id:=first id$
  cykl:=reverse rrst cykl$
  id:=reverse fsvars1do(nlc,do . (id . to1 . 0 . (-step) . {}) . cykl)$
  return id
end$

symbolic$
flag('(ffst frst rfst rrst fffst ffrst frfst frrst rffst rfrst rrfst
     rrrst ffffst fffrst ffrfst ffrrst frffst frfrst frrfst frrrst
     rfffst rffrst rfrfst rfrrst rrffst rrfrst rrrfst rrrrst
     findsvars findsvars1 fsvars1do findsvarsdo expanddo expddo
     genvareq nextvareqsys nextvesdofst nextvesdo findpvars lastvars),
     'noval)$

procedure equalaeval u$
'equal . aevlis u$

procedure aevlis u$
for each a in u collect aeval a$

procedure listnoeval(u,v)$
if atom u then listnoeval(cadr get(u,'avalue),v)
  else u$

endmodule$

algebraic$

end$
