module trigsimp; % User controlled simplification
                 % of trigonometric expressions.

% Authors: Wolfram Koepf, Andreas Bernig, Herbert Melenk
% Version 1.0 April 1995

!#if (memq 'psl lispsystem!*)
  flag('(trigsmp1),'lap);
!#endif

create!-package('(trigsimp trigsmp1 trigsmp2),'(contrib misc));

load_package compact;

endmodule;


module trigsmp1;

% Collection of rule sets.

algebraic;

clearrules(trig_imag_rules);

trig_normalize!*:=
{

  cos(~a)^2 => 1 - sin(a)^2 when trig_preference=sin,
  sin(~a)^2 => 1 - cos(a)^2 when trig_preference=cos,
  cosh(~a)^2 => 1+sinh(a)^2 when hyp_preference=sinh,
  sinh(~a)^2 => cosh(a)^2-1 when hyp_preference=cosh
};


trig_expand!*:=
{
% additions theorems

  sin((~a + ~b)/~~m)
     => sin(a/m)*cos(b/m) + cos(a/m)*sin(b/m),

  cos((~a + ~b)/~~m)
     => cos(a/m)*cos(b/m) - sin(a/m)*sin(b/m),

  tan((~a+~b)/~~m)
     => (tan(a/m)+tan(b/m))/(1-tan(a/m)*tan(b/m)),

  cot((~a+~b)/~~m)
     =>(cot(a/m)*cot(b/m)-1)/(cot(a/m)+cot(b/m)),

  sec((~a+~b)/~~m)
     =>1/(1/(sec(a/m)*sec(b/m))-1/(csc(a/m)*csc(b/m))),

  csc((~a+~b)/~~m)
     =>1/(1/(sec(b/m)*csc(a/m))+1/(sec(a/m)*csc(b/m))),

  tanh((~a+~b)/~~m)
     => (tanh(a/m)+tanh(b/m))/(1+tanh(a/m)*tanh(b/m)),

  coth((~a+~b)/~~m)
     =>(coth(a/m)*coth(b/m)+1)/(coth(a/m)+coth(b/m)),

  sinh((~a+~b)/~~m)
     => sinh(a/m)*cosh(b/m) + cosh(a/m)*sinh(b/m),

  cosh((~a+~b)/~~m)
     => cosh(a/m)*cosh(b/m) + sinh(a/m)*sinh(b/m),

  sech((~a+~b)/~~m)
     =>1/(1/(sech(a/m)*sech(b/m))+1/(csch(a/m)*csch(b/m))),

  csch((~a+~b)/~~m)
     =>1/(1/(sech(a/m)*csch(b/m))+1/(sech(b/m)*csch(a/m))),

% multiplication theorems

  sin(~n*~a/~~m)
     => sin(a/m)*cos((n-1)*a/m) + cos(a/m)*sin((n-1)*a/m)
          when fixp n and n>1 and n<=15,

  sin(~n*~a/~~m)
     =>2*sin(n/2*a/m)*cos(n/2*a/m)
         when fixp n and mod(n,2)=0 and n>15,

  sin(~n*~a/~~m)
     =>sin((n-1)/2*a/m)*cos((n+1)/2*a/m)+
       sin((n+1)/2*a/m)*cos((n-1)/2*a/m)
         when fixp n and mod(n,2)=1 and n>15,

  cos(~n*~a/~~m)
     => cos(a/m)*cos((n-1)*a/m) - sin(a/m)*sin((n-1)*a/m)
          when fixp n and n>1 and n<=15,

  cos(~n*~a/~~m)
      => 2*cos(n/2*a/m)**2-1
          when fixp n and mod(n,2)=0 and n>15,

  cos(~n*~a/~~m)
     => cos((n-1)/2*a/m)*cos((n+1)/2*a/m)-
        sin((n-1)/2*a/m)*sin((n+1)/2*a/m)
          when fixp n and mod(n,2)=1 and n>15,

  sinh(~n*~a/~~m)
     => sinh(a/m)*cosh((n-1)*a/m)+cosh(a/m)*sinh((n-1)*a/m)
         when fixp n and n<=15 and n>1,

  sinh(~n*~a/~~m)
     => 2*sinh(n/2*a/m)*cosh(n/2*a/m)
         when fixp n and mod(n,2)=0 and n>15,

  sinh(~n*~a/~~m)
     => sinh((n-1)/2*a/m)*cosh((n+1)/2*a/m)+
        sinh((n+1)/2*a/m)*cosh((n-1)/2*a/m)
         when fixp n and mod(n,2)=1 and n>15,

  cosh(~n*~a/~~m)
     => cosh(a/m)*cosh((n-1)*a/m) + sinh(a/m)*sinh((n-1)*a/m)
          when fixp n and n>1 and n<=15,

  cosh(~n*~a/~~m)
      => 2*cosh(n/2*a/m)**2-1
          when fixp n and mod(n,2)=0 and n>15,

  cosh(~n*~a/~~m)
     => cosh((n-1)/2*a/m)*cosh((n+1)/2*a/m)+
        sinh((n-1)/2*a/m)*sinh((n+1)/2*a/m)
          when fixp n and mod(n,2)=1 and n>15,

  tan(~n*~a/~~m)
     => (tan(a/m)+tan((n-1)*a/m))/(1-tan(a/m)*tan((n-1)*a/m))
          when fixp n and n>1 and n<=15,

  tan(~n*~a/~~m)
      => 2*tan(n/2*a/m)/(1-tan(n/2*a/m)**2)
          when fixp n and mod(n,2)=0 and n>15,

  tan(~n*~a/~~m)
     => ( tan((n-1)/2*a/m)+tan((n+1)/2*a/m) )/
        (1-tan((n-1)/2*a/m)*tan((n+1)/2*a/m))
          when fixp n and mod(n,2)=1 and n>15,

  tanh(~n*~a/~~m)
     => (tanh(a/m)+tanh((n-1)*a/m))/(1+tanh(a/m)*tanh((n-1)*a/m))
          when fixp n and n>1 and n<=15,

  tanh(~n*~a/~~m)
      => 2*tanh(n/2*a/m)/(1+tanh(n/2*a/m)**2)
          when fixp n and mod(n,2)=0 and n>15,

  tanh(~n*~a/~~m)
     => ( tanh((n-1)/2*a/m)+tanh((n+1)/2*a/m) )/
        (1+tanh((n-1)/2*a/m)*tanh((n+1)/2*a/m))
          when fixp n and mod(n,2)=1 and n>15,

  cot(~n*~a/~~m)
     => (cot(a/m)*cot((n-1)*a/m)-1)/(cot(a/m)+cot((n-1)*a/m))
          when fixp n and n>1 and n<=15,

  cot(~n*~a/~~m)
      => (cot(n/2*a/m)**2-1)/(2cot(n/2*a/m))
          when fixp n and mod(n,2)=0 and n>15,

  cot(~n*~a/~~m)
     => ( cot((n-1)/2*a/m)*cot((n+1)/2*a/m)-1 ) /
        (cot((n-1)/2*a/m)+cot((n+1)/2*a/m))
          when fixp n and mod(n,2)=1 and n>15,

  coth(~n*~a/~~m)
     => (coth(a/m)*coth((n-1)*a/m)+1)/(coth(a/m)+coth((n-1)*a/m))
          when fixp n and n>1 and n<=15,

  coth(~n*~a/~~m)
      => (coth(n/2*a/m)**2+1)/(2coth(n/2*a/m))
          when fixp n and mod(n,2)=0 and n>15,

  coth(~n*~a/~~m)
     => ( coth((n-1)/2*a/m)*coth((n+1)/2*a/m)+1 ) /
        (coth((n-1)/2*a/m)+coth((n+1)/2*a/m))
          when fixp n and mod(n,2)=1 and n>15,

  sec(~n*~a/~~m)
     => 1/(1/(sec(a/m)*sec((n-1)*a/m))-1/(csc(a/m)*csc((n-1)*a/m)))
          when fixp n and n>1 and n<=15,

  sec(~n*~a/~~m)
     =>1/(1/sec(n/2*a/m)**2-1/csc(n/2*a/m)**2)
          when fixp n and mod(n,2)=0 and n>15,

  sec(~n*~a/~~m)
     =>1/(1/(sec((n-1)/2*a/m)*sec((n+1)/2*a/m))-
       1/(csc((n-1)/2*a/m)*csc((n+1)/2*a/m)))
          when fixp n and mod(n,2)=1 and n>15,

  csc(~n*~a/~~m)
     => 1/(1/(sec(a/m)*csc((n-1)*a/m))+1/(csc(a/m)*sec((n-1)*a/m)))
          when fixp n and n>1 and n<=15,

  csc(~n*~a/~~m)
     =>sec(n/2*a/m)*csc(n/2*a/m)/2
          when fixp n and mod(n,2)=0,

  csc(~n*~a/~~m)
     =>1/(1/(sec((n-1)/2*a/m)*csc((n+1)/2*a/m))+
       1/(csc((n-1)/2*a/m)*sec((n+1)/2*a/m)))
          when fixp n and mod(n,2)=1 and n>15,

  sech(~n*~a/~~m)
     => 1/(1/(sech(a/m)*sech((n-1)*a/m))+1/(csch(a/m)*csch((n-1)*a/m)))
          when fixp n and n>1 and n<=15,

  sech(~n*~a/~~m)
     =>1/(1/sech(n/2*a/m)**2+1/csch(n/2*a/m)**2)
          when fixp n and mod(n,2)=0 and n>15,

  sech(~n*~a/~~m)
     =>1/(1/(sech((n-1)/2*a/m)*sech((n+1)/2*a/m))+
       1/(csch((n-1)/2*a/m)*csch((n+1)/2*a/m)))
          when fixp n and mod(n,2)=1 and n>15,

  csch(~n*~a/~~m)
     => 1/(1/(sech(a/m)*csch((n-1)*a/m))+1/(csch(a/m)*sech((n-1)*a/m)))
          when fixp n and n>1 and n<=15,

  csch(~n*~a/~~m)
     =>sech(n/2*a/m)*csch(n/2*a/m)/2
          when fixp n and mod(n,2)=0 and n>15,

  csch(~n*~a/~~m)
     =>1/(1/(sech((n-1)/2*a/m)*csch((n+1)/2*a/m))+
       1/(csch((n-1)/2*a/m)*sech((n+1)/2*a/m)))
          when fixp n and mod(n,2)=1 and n>15

};

trig_combine!*:=
{
  sin(~a)*sin(~b) => 1/2*(cos(a-b) - cos(a+b)),
  cos(~a)*cos(~b) => 1/2*(cos(a-b) + cos(a+b)),
  sin(~a)*cos(~b) => 1/2*(sin(a-b) + sin(a+b)),
  sin(~a)^2          => 1/2*(1-cos(2*a)),
  cos(~a)^2          => 1/2*(1+cos(2*a)),

  sinh(~a)*sinh(~b) => 1/2*(cosh(a+b) - cosh(a-b)),
  cosh(~a)*cosh(~b) => 1/2*(cosh(a-b) + cosh(a+b)),
  sinh(~a)*cosh(~b) => 1/2*(sinh(a-b) + sinh(a+b)),
  sinh(~a)^2          => 1/2*(cosh(2*a)-1),
  cosh(~a)^2          => 1/2*(1+cosh(2*a))
};

trig_standardize!*:=
{
  tan(~a) => sin(a)/cos(a),
  cot(~a) => cos(a)/sin(a),
  tanh(~a) => sinh(a)/cosh(a),
  coth(~a) => cosh(a)/sinh(a),
  sec(~a) => 1/cos(a),
  csc(~a) => 1/sin(a),
  sech(~a) => 1/cosh(a),
  csch(~a) => 1/sinh(a)
} ;

trig2exp!*:=
{
  cos(~a) => (e^(i*a) + e^(-i*a))/2,
  sin(~a) => -i*(e^(i*a) - e^(-i*a))/2,
  cosh(~a) => (e^(a) + e^(-a))/2,
  sinh(~a) => (e^(a) - e^(-a))/2
};

exp2trig1!*:=
{
  e**(~x)=>cos(x/i)+i*sin(x/i)
};

exp2trig2!*:=
{
  e**(~x)=>1/(cos(x/i)-i*sin(x/i))
};

trig2hyp!*:=
{
  sin(~a)=> -i * sinh(i*a),
  cos(~a)=> cosh(i*a),
  tan(~a)=> -i*tanh(i*a),
  cot(~a)=> i*coth(i*a),
  sec(~a)=> sech(i*a),
  csc(~a)=> i*csch(i*a),
  asin(~a)=> asinh(i*a)/i,
  acos(~a)=> acosh(a)/i
};

hyp2trig!*:=
{
  sinh(~a)=> -i*sin(i*~a),
  cosh(~a)=> cos(i*~a),
  acosh(~a)=> i*acos(a),
  asinh(~a)=> asin(-i*a)*i
};

subtan!*:=
{
  sin(~x)=>cos(x)*tan(x) when trig_preference=cos,
  cos(~x)=>sin(x)/tan(x) when trig_preference=sin,
  sinh(~x)=>cosh(x)*tanh(x) when hyp_preference=cosh,
  cosh(x)=>sinh(x)/tanh(x) when hyp_preference=sinh
};

endmodule;


module trigsmp2;

% Executable code.

algebraic;

procedure behandle(ex);
  begin scalar p,q,p2,q2;
    p := num ex;
    q := den ex;
    let exp2trig1!*;
    p2 := p;
    clearrules exp2trig1!*;
    let exp2trig2!*;
    q2 := q;
    clearrules exp2trig2!*;
    return p2/q2;
  end;

procedure trigsimp1(f,l);
  begin
    scalar u,p,trigpreferencelist,hyppreferencelist,
    directionlist,modelist,keepalltriglist,err,onlytan;

    err:=0;
    if freeof(f,sin) and freeof(f,cos) and freeof(f,cosh) and
    freeof(f,sinh) and freeof(f,csc) and
    freeof(f,sec) and freeof(f,csch) and freeof(f,sech) then
       onlytan:=1 else onlytan:=0;
    trigpreferencelist:={};
    hyppreferencelist:={};
    directionlist:={};
    modelist:={};
    keepalltriglist:={};
    while length(l) neq 0 do begin
      u:=first(l);
      l:=rest(l);
      if u=sin or u=cos then trigpreferencelist:=u.trigpreferencelist
      else if (u=sinh) or (u=cosh) then hyppreferencelist:=
         u.hyppreferencelist
      else if (u=expand) or (u=combine) or (u=compact) then
         directionlist:=u.directionlist
      else if u=hyp or u=trig or u=expon then modelist:=u.modelist
      else if (u=keepalltrig) then keepalltriglist:=u.keepalltriglist
      else <<write u," not possible. Use sin,cos,cosh,sinh,
      expand,combine,compact,hyp,trig,expon,keepalltrig!";err:=1;>>;
    end;

%Defaults
    if trigpreferencelist={} then trigpreferencelist:={sin};
    if hyppreferencelist={} then hyppreferencelist:={sinh};
    if directionlist={} then directionlist:={expand};

%contradictions?
    if length(trigpreferencelist)>1 then <<write trigpreferencelist,
    " not possible. Use either sin or cos.";err:=1;>>;
    if length(hyppreferencelist)>1 then <<write hyppreferencelist,
    " not possible. Use either sinh or cosh.";err:=1;>>;
    if length(directionlist)>1 then <<write directionlist,
    " not possible. Use either expand or combine or compact.";err:=1;>>;
    if length(modelist)>1 then <<write modelist," not possible.
       Use either hyp or expon.";err:=1;>>;

    if err=0 then begin
%application

      if first(trigpreferencelist)=sin then trig_preference:=sin;
      if first(trigpreferencelist)=cos then trig_preference:=cos;
      if first(hyppreferencelist)=sinh then hyp_preference:=sinh;
      if first(hyppreferencelist)=cosh then hyp_preference:=cosh;

      let trig_normalize!*;
      p:=f;

      if keepalltriglist={} or directionlist={combine} or
         directionlist={compact}
      then <<let trig_standardize!*;
      p:=p+0;clearrules(trig_standardize!*);>>;

      if modelist neq {} then begin
        if first(modelist)=trig then <<let hyp2trig!*;
           p:=p+0;clearrules(hyp2trig!*);p:=behandle(p);>>;
        if first(modelist)=hyp then
        <<p:=behandle(p);let trig2hyp!*;p:=p+0;clearrules(trig2hyp!*)>>;
        if first(modelist)=expon then
          <<let trig2exp!*;p:=p+0;clearrules(trig2exp!*);>>;
      end;

      if first(directionlist)=expand then
      <<let trig_expand!*;p:=p+0;clearrules(trig_expand!*);>>;
      if first(directionlist)=combine then
      <<let trig_combine!*;p:=p+0;clearrules(trig_combine!*);
      if onlytan=1 and
      (keepalltriglist={keepalltrig}) then
      <<let subtan!*;p:=p+0;clearrules(subtan!*)>>;>>;
      clearrules(trig_normalize!*);
      if first(directionlist)=compact then begin
      % load compact;  % Loaded at beginning.
        let trig_expand!*;p:=p+0;clearrules(trig_expand!*);
        p:=compact(f,{sin(x)**2+cos(x)**2=1});
      end;
    end;
    return p;
  end;

procedure degree(p,x);
  begin
  scalar h;
  if p=0 then h:=inf else h:=deg(num(p),x)-deg(den(p),x);
  return h;
  end;

procedure balanced(p,x);
  if deg(num(p),x)=2*deg(den(p),x) then 1 else 0;

procedure coordinated(p,x);
  begin
    scalar k,pneu,e,o,j;
    k:={};
    e:=0;
    o:=0;
    pneu:=num(p);
    for j:=0:deg(pneu,x) do
      <<if coeffn(pneu,x,j) neq 0 then k:=j.k>>;
    for j:=1:length(k) do
      <<if fixp(part(k,j)/2) then e:=1 else o:=1>>;
     if o=e then return 0 else return 1;
  end;

procedure trig2ord(p,x,y);
  begin
    if balanced(p,x) neq 1 or balanced(p,y) neq 1 then write
    "error using trig2ord:
      polynomial not balanced.";
    if coordinated(p,x) neq 1 or coordinated(p,y) neq 1 then write
    "error using trig2ord:
      polynomial not coordinated";
    return sub(x=sqrt(x),y=sqrt(y),x**degree(p,x)*y**degree(p,y)*p);
  end;

procedure ord2trig(p,x,y);
  x**(-degree(p,x))*y**(-degree(p,y))*sub(x=x**2,y=y**2,p);

procedure factor_trig_poly(p,x,y);
  begin
    scalar j,p1,flist1,flist,d;
    p1:=trig2ord(p,x,y);
    d:=den(p1);
    flist1:=factorize(num(p1));
    flist:={};
    for j:=1:length(flist1) do
        flist:=ord2trig(part(flist1,j),x,y).flist;
    if d neq 1 then flist:=(1/d).flist;
    return flist;
  end;

procedure subpoly2trig(p,x);
  begin
    scalar r,d;
    d:=degree(den(p),x);
    r:=p*x**d;
    r:=sub(x=cos(x)+i*sin(x),r);
    r:=r*(cos(x)-i*sin(x))**d;
    return r;
  end;

procedure subpoly2hyp(p,x);
  begin
    scalar r,d;
    d:=degree(den(p),x);
    r:=p*x**d;
    r:=sub(x=cosh(x)+sinh(x),r);
    r:=r*(cosh(x)-sinh(x))**d;
    return r;
  end;

procedure varget(p);
  begin
    scalar q,l,h;
    q:=factorize(p);
    h:=0;
    for each l in q do
      <<if not(numberp(l)) then
        begin
          if (h=0) and length(l)=1  then h:=l else
          h:=1;
        end;
      >>;
    if h=0 then h:=1;
    return h;
  end;

procedure numberget(p);
  begin
    scalar q,d,l,h;
    q:=factorize(p);
    d:=1;
    h:=0;
    for each l in q do if numberp(l) then d:=d*l;
    return d;
  end;

procedure argumenttriglist(term1, list1);
begin
scalar head1,j,l;
l:=arglength(term1);
if l<1 then return list1;
head1:=part(term1,0);
if head1 = sinh or
   head1 = cosh or
   head1 = sin or
   head1 = cos then
   list1:=append(list1,{part(term1,1)})
else for j:=1:l do
  list1:=argumenttriglist(part(term1,j),list1);
return list1;
end;

procedure triggcd(p,q,x);
  begin
    scalar p1,q1,g1,g,u,d,nu,h,complex!*,err,l;
    on complex;
    nu:=numberget(x);
    err:=0;
    if varget(x)=1 then err:=1 else begin
      l:=argumenttriglist(p,{});
      for d:=1:length(l) do if not(fixp(df(part(l,d),varget(x))/nu))
      and not(freeof(part(l,d),varget(x))) then err:=1;
      l:=argumenttriglist(q,{});
      for d:=1:length(l) do if not(fixp(df(part(l,d),varget(x))/nu))
      and not(freeof(part(l,d),varget(x))) then err:=1;
    end;
    if err=0 then begin
      p1:=trigsimp1(p,{});
      p1:=sub(sin(varget(x))=sin(varget(x)/nu),
      cos(varget(x))=cos(varget(x)/nu),sinh(varget(x))
                    =sinh(varget(x)/nu),
      cosh(varget(x))=cosh(varget(x)/nu),p1);
      p1:=trigsimp1(p1,{});
      q1:=trigsimp1(q,{});
      q1:=sub(sin(varget(x))=sin(varget(x)/nu),
      cos(varget(x))=cos(varget(x)/nu),sinh(varget(x))
                    =sinh(varget(x)/nu),
      cosh(varget(x))=cosh(varget(x)/nu),q1);
      q1:=trigsimp1(q1,{});
      p1:=sub(sin(varget(x))=(xx_x-1/xx_x)/(2i),
      cos(varget(x)) =>xx_x/2+1/(2xx_x),
      sinh(varget(x))=(yy_y-1/yy_y)/2,
      cosh(varget(x))=yy_y/2+1/(2yy_y),p1);
      q1:=sub(sin(varget(x))=(xx_x-1/xx_x)/(2i),
      cos(varget(x)) =>xx_x/2+1/(2xx_x),
      sinh(varget(x))=(yy_y-1/yy_y)/2,
      cosh(varget(x))=yy_y/2+1/(2yy_y),q1);
      if balanced(p1,xx_x)+balanced(q1,xx_x)+coordinated(p1,xx_x)+
      coordinated(q2,xx_x)+balanced(p1,yy_y)+balanced(q1,yy_y)+
      coordinated(p1,yy_y)+coordinated(q2,yy_y) neq 8
      then d:=1
      else begin
        p1:=trig2ord(p1,xx_x,yy_y);
        q1:=trig2ord(q1,xx_x,yy_y);
        g1:=gcd(num(p1),num(q1));
        g:=ord2trig(g1,xx_x,yy_y)/lcm(den(p1),den(p2));
        h:=subpoly2trig(g,xx_x);
        h:=subpoly2hyp(h,yy_y);
        h:=sub(xx_x=varget(x)*nu,yy_y=varget(x)*nu,h);
        h:=trigsimp1(h,{});
        h:=factorize(num(h));
        d:=1;
        for each r in h do if not(numberp(r)) then d:=d*r;
      end;
    end else d:="error using triggcd, basis not possible.";
    return d;
  end;

procedure trigfactorize(p,x);
  begin
    scalar l,q,f,r,d,h,s,u,err,complex!*;
    on complex;
    nu:=numberget(x);
    err:=0;
    if varget(x)=1 then err:=1 else begin
      l:=argumenttriglist(p,{});
      for d:=1:length(l) do if not(fixp(df(part(l,d),varget(x))/nu))
      and not(freeof(part(l,d),varget(x))) then err:=1;
    end;
    if err=1
      then rederr("error using trigfactorize, basis not possible")
    else begin
      q:=trigsimp1(p,{});
      q:=sub(sin(varget(x))=sin(varget(x)/nu),
      cos(varget(x))=cos(varget(x)/nu),sinh(varget(x))
                    =sinh(varget(x)/nu),
      cosh(varget(x))=cosh(varget(x)/nu),q);
      q:=trigsimp1(q,{});
      q:=sub(sin(varget(x))=(xx_x-1/xx_x)/(2i),
      cos(varget(x)) =xx_x/2+1/(2xx_x),
      sinh(varget(x))=(yy_y-1/yy_y)/2,cosh(varget(x))
                     =yy_y/2+1/(2yy_y),q);
      if balanced(q,xx_x)+coordinated(q,xx_x)+
      balanced(q,yy_y)+coordinated(q,yy_y)<4 then f:={p}
      else begin
        q:=factor_trig_poly(q,xx_x,yy_y);
        f:={};
        d:=1;
        for each r in q do
        <<h:=subpoly2trig(r,xx_x);
          h:=subpoly2hyp(h,yy_y);
          h:=sub(xx_x=varget(x)*nu,yy_y=varget(x)*nu,h);
          h:=trigsimp1(h,{});
          if freeof(h,varget(x)) then d:=d*h else begin
            for each u in factorize(h) do
            <<if freeof(u,varget(x)) then begin
              d:=d*u;
              h:=h/u;
            end;
          >>;
          f:=reverse(h.reverse(f));
          end;
        >>;
        if d neq 1 then f:=d.f;
      end;
    end;
    return f;
  end;

symbolic procedure trigsimp!*(f);
trigsimp1(reval car f,'list.for each w in cdr f collect reval w);

symbolic put('trigsimp,'psopfn, 'trigsimp!*);

endmodule;


end;
