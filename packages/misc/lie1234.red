module lie1234;
% n-dimensional Lie algebras up to n=4.
% Author: Carsten and Franziska Schoebel.
% e-mail: cschoeb@aix550.informatik.uni-leipzig.de .
% Copyright (c) 1993 The Leipzig University, Computer Science Dept.
% All Rights Reserved.

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%


algebraic;
operator liealg,comtab;

algebraic procedure lieclass(dim);
begin
 if not(dim=1 or dim=2 or dim=3 or dim=4) then
  symbolic rederr "dimension out of range";
 symbolic(if gettype 'liestrin neq 'array then
          rederr "liestrin not array");
 if length liestrin neq {dim+1,dim+1,dim+1} then
  symbolic rederr "dimension of liestrin out of range";
 if dim=1 then <<if symbolic !*tr_lie then
                 write "one-dimensional Lie algebra";
                 lie_class:={liealg(1),comtab(0)}>> else
     if dim=2 then lie2(liestrin(1,2,1),liestrin(1,2,2)) else
      if dim=3 then <<matrix lie3_ff(3,3);
                      for i:=1:3 do <<lie3_ff(1,i):=liestrin(1,2,i);
                                      lie3_ff(2,i):=liestrin(1,3,i);
                                      lie3_ff(3,i):=liestrin(2,3,i)>>;
                      lie3(lie3_ff);clear lie3_ff>> else
      <<array cc(4,4,4);
        for i:=1:4 do for j:=1:4 do for k:=1:4 do
         cc(i,j,k):=liestrin(i,j,k);
        lie4();clear cc>>;return lie_class
end;

algebraic procedure lie2(f,g);
begin
  if g=0 then
   if f=0 then liemat:=mat((1,0),(0,1))
   else liemat:=mat((0,-1/f),(f,0))
  else liemat:=mat((1/g,0),(f,g));
  if (f=0 and g=0) then <<if symbolic !*tr_lie then
   write "The given Lie algebra is commutative";
   lie_class:={liealg(2),comtab(0)}>>
  else <<if symbolic !*tr_lie then
         write "[X,Y]=Y";lie_class:={liealg(2),comtab(1)}>>
end;

algebraic procedure lie3(ff);
begin
  matrix liemat(3,3),l_f(3,3);
  array l_jj(3);
  l_f:=ff;
  for n:=1:3 do
      l_jj(n):=l_f(1,n)*(-l_f(2,1)-l_f(3,2))+
            l_f(2,n)*(l_f(1,1)-l_f(3,3))+
            l_f(3,n)*(l_f(1,2)+l_f(2,3));
  if not(l_jj(1)=0 and l_jj(2)=0 and l_jj(3)=0) then
     <<clear lie3_ff,liemat,l_f,l_jj;
       symbolic rederr "not a Lie algebra">>;
    if l_f=mat((0,0,0),(0,0,0),(0,0,0)) then
    <<if symbolic !*tr_lie then write "Your Lie algebra is commutative";
         lie_class:={liealg(3),comtab(0)};liemat:=liemat**0>> else
      if det(l_f) neq 0 then com3(ff) else
        if independ(1,2,ff)=1 then com2(ff,1,2) else
         if independ(1,3,ff)=1 then com2(ff,1,3) else
          if independ(2,3,ff)=1 then com2(ff,2,3) else
           com1(ff);
   clear l_jj,l_f
end;


algebraic procedure independ(i,j,f0);
begin matrix f1(3,3);
  f1:=f0;
  if (f1(i,1)*f1(j,2)-f1(i,2)*f1(j,1)=0 and
      f1(i,2)*f1(j,3)-f1(i,3)*f1(j,2)=0 and
      f1(i,1)*f1(j,3)-f1(i,3)*f1(j,1)=0) then return 0
  else return 1
end;

algebraic procedure com1(f2);
begin
  scalar alpha,aa,bb;
  integer r,i,j,m,n,z1;
  matrix f3(3,3);
  array l_c(3,3,3);
  f3:=f2;
  for m:=3 step -1 until 1 do
   for n:=3 step -1 until 1 do
   if f3(m,n) neq 0 then i:=m;
  if i=1 then <<i:=1;j:=2>> else
   if i=2 then <<i:=1;j:=3>> else <<i:=2;j:=3>>;
  for k:=1:3 do
   <<l_c(1,2,k):=f3(1,k);l_c(2,1,k):=-f3(1,k);
     l_c(1,3,k):=f3(2,k);l_c(3,1,k):=-f3(2,k);
     l_c(2,3,k):=f3(3,k);l_c(3,2,k):=-f3(3,k)>>;
  z1:=0;
  for u:=3 step -1 until 1 do
   for v:=3 step -1 until 1 do
   if l_c(i,j,1)*l_c(v,1,u)+l_c(i,j,2)*l_c(v,2,u)+
   l_c(i,j,3)*l_c(v,3,u) neq 0
  then <<m:=u;n:=v;z1:=1>>;
  if z1=0 then
    <<a1:=mat((1,0,0),(0,1,0),(l_c(1,2,1),l_c(1,2,2),l_c(1,2,3)));
      a2:=mat((1,0,0),(0,0,1),(l_c(1,3,1),l_c(1,3,2),l_c(1,3,3)));
      a3:=mat((0,1,0),(0,0,1),(l_c(2,3,1),l_c(2,3,2),l_c(2,3,3)));
      if det(a1) neq 0 then liemat:=a1 else
       if det(a2) neq 0 then liemat:=a2 else liemat:=a3;
      if symbolic !*tr_lie then
      write "[X,Y]=Z";lie_class:={liealg(3),comtab(1)}>> else
    <<alpha:=(l_c(i,j,1)*l_c(n,1,m)+l_c(i,j,2)*l_c(n,2,m)+
              l_c(i,j,3)*l_c(n,3,m))/l_c(i,j,m);
      a1:=mat((0,0,0),(0,0,0),(l_c(i,j,1),l_c(i,j,2),l_c(i,j,3)));
      a1(1,n):=1/alpha;a1(2,1):=1;
      if det(a1) neq 0 then r:=1 else
      <<a1(2,1):=0;a1(2,2):=1;
        if det(a1) neq 0 then r:=2 else
        <<a1(2,2):=0;a1(2,3):=1;r:=3>>>>;
      aa:=l_c(n,r,m)/(alpha*l_c(i,j,m));
      bb:=(l_c(i,j,1)*l_c(r,1,m)+l_c(i,j,2)*l_c(r,2,m)+
           l_c(i,j,3)*l_c(r,3,m))/l_c(i,j,m);
      if aa=0 then liemat:=mat((1,0,0),(-bb,1,0),(0,0,1))*a1 else
        liemat:=mat((1,0,0),(bb/aa,-1/aa,1),(0,0,1))*a1;
      if symbolic !*tr_lie then
      write "[X,Z]=Z";lie_class:={liealg(3),comtab(2)}>>;
  clear a1,a2,a3,l_c,f3
end;

algebraic procedure com2(f2,m,n);
begin scalar z1,alpha,alpha1,alpha2,beta,beta1,beta2;
  matrix f3(3,3);
  f3:=f2;
  a1:=mat((f3(m,1),f3(m,2),f3(m,3)),
          (f3(n,1),f3(n,2),f3(n,3)),(0,0,0));
  a1(3,1):=1;z1:=det(a1);
  if z1 neq 0 then
   <<alpha1:=(-f3(n,3)*(f3(m,2)*f3(1,2)+f3(m,3)*f3(2,2))+
               f3(n,2)*(f3(m,2)*f3(1,3)+f3(m,3)*f3(2,3)))/z1;
     alpha2:=(-f3(n,3)*(f3(n,2)*f3(1,2)+f3(n,3)*f3(2,2))+
               f3(n,2)*(f3(n,2)*f3(1,3)+f3(n,3)*f3(2,3)))/z1;
     beta1:=(f3(m,3)*(f3(m,2)*f3(1,2)+f3(m,3)*f3(2,2))-
             f3(m,2)*(f3(m,2)*f3(1,3)+f3(m,3)*f3(2,3)))/z1;
     beta2:=(f3(m,3)*(f3(n,2)*f3(1,2)+f3(n,3)*f3(2,2))-
             f3(m,2)*(f3(n,2)*f3(1,3)+f3(n,3)*f3(2,3)))/z1>>
   else
   <<a1(3,1):=0;a1(3,2):=1;z1:=det(a1);
   if z1 neq 0 then
    <<alpha1:=(-f3(n,3)*(f3(m,1)*f3(1,1)-f3(m,3)*f3(3,1))+
                f3(n,1)*(f3(m,1)*f3(1,3)-f3(m,3)*f3(3,3)))/z1;
      alpha2:=(-f3(n,3)*(f3(n,1)*f3(1,1)-f3(n,3)*f3(3,1))+
                f3(n,1)*(f3(n,1)*f3(1,3)-f3(n,3)*f3(3,3)))/z1;
      beta1:=(f3(m,3)*(f3(m,1)*f3(1,1)-f3(m,3)*f3(3,1))-
              f3(m,1)*(f3(m,1)*f3(1,3)-f3(m,3)*f3(3,3)))/z1;
      beta2:=(f3(m,3)*(f3(n,1)*f3(1,1)-f3(n,3)*f3(3,1))-
              f3(m,1)*(f3(n,1)*f3(1,3)-f3(n,3)*f3(3,3)))/z1>>
   else
   <<a1(3,2):=0;a1(3,3):=1;z1:=det(a1);
      alpha1:=(f3(n,2)*(f3(m,1)*f3(2,1)+f3(m,2)*f3(3,1))-
               f3(n,1)*(f3(m,1)*f3(2,2)+f3(m,2)*f3(3,2)))/z1;
      alpha2:=(f3(n,2)*(f3(n,1)*f3(2,1)+f3(n,2)*f3(3,1))-
               f3(n,1)*(f3(n,1)*f3(2,2)+f3(n,2)*f3(3,2)))/z1;
      beta1:=(-f3(m,2)*(f3(m,1)*f3(2,1)+f3(m,2)*f3(3,1))+
               f3(m,1)*(f3(m,1)*f3(2,2)+f3(m,2)*f3(3,2)))/z1;
      beta2:=(-f3(m,2)*(f3(n,1)*f3(2,1)+f3(n,2)*f3(3,1))+
               f3(m,1)*(f3(n,1)*f3(2,2)+f3(n,2)*f3(3,2)))/z1>>>>;
  if (alpha2=0 and beta1=0 and alpha1=beta2) then
   <<liemat:=mat((1,0,0),(0,1,0),(0,0,1/alpha1))*a1;
     if symbolic !*tr_lie then
     write "[X,Z]=X, [Y,Z]=Y";lie_class:={liealg(3),comtab(3)}>> else
   <<if alpha2 neq 0 then
     <<alpha:=alpha1+beta2;beta:=alpha2*beta1-alpha1*beta2;
       a2:=mat((0,beta1-alpha1*beta2/alpha2,0),
               (1,-alpha1/alpha2,0),(0,0,1))>> else
      if beta1 neq 0 then
       <<alpha:=1+alpha1/beta2;beta:=-alpha1/beta2;
         a2:=mat((-alpha1*beta2/beta1,0,0),
                 (-(beta2**2)/beta1,beta2,0),(0,0,1/beta2))>> else
        <<alpha:=alpha1+beta2;beta:=-alpha1*beta2;
          a2:=mat((1,1,0),(1/alpha1,1/beta2,0),(0,0,1))>>;
     if alpha=0 then
      <<liemat:=mat((1,0,0),(0,sqrt(abs(beta)),0),
               (0,0,1/sqrt(abs(beta))))*a2*a1;
        if symbolic !*tr_lie then
        write "[X,Z]=",beta/abs(beta),"Y, [Y,Z]=X";
        if beta>0 then lie_class:={liealg(3),comtab(4)} else
                       lie_class:={liealg(3),comtab(5)}>>
                 else
      <<liemat:=mat((1,0,0),(0,-alpha,0),(0,0,-1/alpha))*a2*a1;
        if symbolic !*tr_lie then
        write "[X,Z]=-X+",beta/(alpha**2),"Y, [Y,Z]=X";
        lie_class:={liealg(3),comtab(6),beta/(alpha**2)}>>>>;
  clear a1,a2,f3
end;

algebraic procedure com3(f2);
begin matrix l_k(3,3),f3(3,3);
  f3:=f2;
  l_k(1,1):=f3(1,2)**2+2*f3(1,3)*f3(2,2)+f3(2,3)**2;
  l_k(1,2):=-f3(1,1)*f3(1,2)+f3(1,3)*f3(3,2)-
           f3(2,1)*f3(1,3)+f3(2,3)*f3(3,3);
  l_k(1,3):=-f3(1,1)*f3(2,2)-f3(1,2)*f3(3,2)-
           f3(2,1)*f3(2,3)-f3(2,2)*f3(3,3);
  l_k(2,1):=l_k(1,2);
  l_k(2,2):=f3(1,1)**2-2*f3(1,3)*f3(3,1)+f3(3,3)**2;
  l_k(2,3):=f3(1,1)*f3(2,1)+f3(1,2)*f3(3,1)-
          f3(3,1)*f3(2,3)-f3(3,2)*f3(3,3);
  l_k(3,1):=l_k(1,3);
  l_k(3,2):=l_k(2,3);
  l_k(3,3):=f3(2,1)**2+2*f3(2,2)*f3(3,1)+f3(3,2)**2;
  if not(numberp(l_k(1,1)) and
   numberp(l_k(1,1)*l_k(2,2)-l_k(1,2)*l_k(2,1)) and
         numberp(det(l_k))) then
  <<write "Is ",-l_k(1,1),">0 and ",
     l_k(1,1)*l_k(2,2)-l_k(1,2)*l_k(2,1),">0 and ",
      -det(l_k),">0 ? (y/n) and press <RETURN>";
    he:=symbolic read();
    if he=y then so3(f2) else so21(f2)>> else
  if (-l_k(1,1)>0 and l_k(1,1)*l_k(2,2)-l_k(1,2)*l_k(2,1)>0 and
      -det(l_k)>0) then so3(f2) else so21(f2);
  clear l_k,f3
end;

algebraic procedure so3(f4);
begin scalar s,tt,q,r,alpha;
      matrix f5(3,3);
  f5:=f4;
  s:=f5(2,2)/abs(f5(2,2));
  tt:=abs(f5(1,2)**2+f5(1,3)*f5(2,2));
  r:=f5(1,1)-f5(1,2)*f5(2,1)/f5(2,2);
  alpha:=tt*(-r*r-((f5(2,1)/f5(2,2))**2+f5(3,1)/f5(2,2))*tt);
  q:=1/sqrt(alpha);
  liemat(1,1):=1/(s*sqrt(tt));
  liemat(1,2):=0;
  liemat(1,3):=0;
  liemat(2,1):=q*r;
  liemat(2,2):=0;
  liemat(2,3):=-q*tt/f5(2,2);
  liemat(3,1):=-q*s*sqrt(tt)*f5(2,1)/f5(2,2);
  liemat(3,2):=-q*s*sqrt(tt);
  liemat(3,3):=q*s*sqrt(tt)*f5(1,2)/f5(2,2);
  if symbolic !*tr_lie then
  write "[X,Y]=Z, [X,Z]=-Y, [Y,Z]=X";lie_class:={liealg(3),comtab(7)};
  clear f5;
end;

algebraic procedure so21(f4);
begin scalar gam,eps,s,tt,q,r,alpha;
      matrix l_g(3,3),f5(3,3);
  f5:=f4;
  liemat:=mat((1,0,0),(0,1,0),(0,0,1));
  if f5(2,2)=0 then
   if f5(1,3) neq 0 then <<liemat:=mat((1,0,0),(0,0,1),(0,1,0));
    l_g(1,1):=f5(2,1);l_g(1,2):=f5(2,3);l_g(1,3):=f5(2,2);
    l_g(2,1):=f5(1,1);l_g(2,2):=f5(1,3);l_g(2,3):=f5(1,2);
    l_g(3,1):=-f5(3,1);l_g(3,2):=-f5(3,3);l_g(3,3):=-f5(3,2);
    f5:=l_g>> else
    if f5(3,1) neq 0 then <<liemat:=mat((0,1,0),(1,0,0),(0,0,1));
     l_g(1,1):=-f5(1,2);l_g(1,2):=-f5(1,1);l_g(1,3):=-f5(1,3);
     l_g(2,1):=f5(3,2);l_g(2,2):=f5(3,1);l_g(2,3):=f5(3,3);
     l_g(3,1):=f5(2,2);l_g(3,2):=f5(2,1);l_g(3,3):=f5(2,3);
     f5:=l_g>> else
      <<liemat:=mat((1,0,1),(1,0,0),(0,1,0));
        l_g(1,1):=-f5(2,3);l_g(1,2):=f5(2,3)-f5(2,1);l_g(1,3):=0;
        l_g(2,1):=-f5(3,3);l_g(2,2):=2*f5(1,1);
        l_g(2,3):=f5(1,2)-f5(3,2);
        l_g(3,1):=0;l_g(3,2):=f5(1,1);l_g(3,3):=f5(1,2);
        f5:=l_g>>;
  if f5(1,2)**2+f5(1,3)*f5(2,2)=0 then
   <<gam:=-f5(1,2)/f5(2,2);eps:=f5(1,1)-f5(1,2)*f5(2,1)/f5(2,2);
     if 1/4*(f5(3,2)**2+f5(3,1)*f5(2,2))-eps*f5(2,2)/2=0 then
      <<liemat:=mat((0,0,1),(0,2/eps,2*gam/eps),(1,0,0))*liemat;
        l_g(1,1):=2*gam*f5(3,2)/eps-f5(3,3);
        l_g(1,2):=-f5(3,2);l_g(1,3):=-2*f5(3,1)/eps;
        l_g(2,1):=0;l_g(2,2):=-eps*f5(2,2)/2;l_g(2,3):=-f5(2,1);
        l_g(3,1):=0;l_g(3,2):=0;l_g(3,3):=-2;f5:=l_g>> else
      <<liemat:=mat((1/2,0,1/2),(0,1/eps,gam/eps),(-1/2,0,1/2))*liemat;
        l_g(1,1):=-f5(3,1)/(2*eps);l_g(1,2):=-f5(3,2)/2;
        l_g(1,3):=f5(3,1)/(2*eps)-1;
        l_g(2,1):=f5(2,1)/2;l_g(2,2):=f5(2,2)*eps/2;
        l_g(2,3):=-f5(2,1)/2;l_g(3,1):=f5(3,1)/(2*eps)+1;
        l_g(3,2):=f5(3,2)/2;l_g(3,3):=-f5(3,1)/(2*eps);f5:=l_g>>>>;
  if not(numberp(f5(1,2)**2+f5(1,3)*f5(2,2))) then
 <<write "Is ",f5(1,2)**2+f5(1,3)*f5(2,2),
         "<0 ? (y/n) and press <RETURN>";
    he:=symbolic read();
    if he=y then
    <<s:=f5(2,2)/abs(f5(2,2));
     tt:=abs(f5(1,2)**2+f5(1,3)*f5(2,2));
     r:=f5(1,1)-f5(1,2)*f5(2,1)/f5(2,2);
     alpha:=tt*(-r*r-((f5(2,1)/f5(2,2))**2+f5(3,1)/f5(2,2))*tt);
     q:=1/sqrt(abs(alpha));
     l_g(1,1):=-q*s*sqrt(tt)*f5(2,1)/f5(2,2);
     l_g(1,2):=-q*s*sqrt(tt);
     l_g(1,3):=q*s*sqrt(tt)*f5(1,2)/f5(2,2);
     l_g(2,1):=1/(s*sqrt(tt));
     l_g(2,2):=0;
     l_g(2,3):=0;
     l_g(3,1):=q*r;
     l_g(3,2):=0;
     l_g(3,3):=-q*tt/f5(2,2);
     liemat:=l_g*liemat>> else
   <<s:=f5(2,2)/abs(f5(2,2));
     tt:=f5(1,2)**2+f5(1,3)*f5(2,2);
     r:=f5(1,1)-f5(1,2)*f5(2,1)/f5(2,2);
     alpha:=tt*(r*r-((f5(2,1)/f5(2,2))**2+f5(3,1)/f5(2,2))*tt);
     q:=1/sqrt(abs(alpha));
     if not(numberp(alpha)) then
     <<write "Is ",alpha,">0 ? (y/n) and press <RETURN>";
       he:=symbolic read();
       if he=y then
       <<l_g(1,1):=1/(s*sqrt(tt));
         l_g(1,2):=0;
         l_g(1,3):=0;
         l_g(2,1):=q*r;
         l_g(2,2):=0;
         l_g(2,3):=q*tt/f5(2,2);
         l_g(3,1):=q*s*sqrt(tt)*f5(2,1)/f5(2,2);
         l_g(3,2):=q*s*sqrt(tt);
         l_g(3,3):=-q*s*sqrt(tt)*f5(1,2)/f5(2,2);
         liemat:=l_g*liemat>> else
       <<l_g(1,1):=1/(s*sqrt(tt));
         l_g(1,2):=0;
         l_g(1,3):=0;
         l_g(2,1):=q*s*sqrt(tt)*f5(2,1)/f5(2,2);
         l_g(2,2):=q*s*sqrt(tt);
         l_g(2,3):=-q*s*sqrt(tt)*f5(1,2)/f5(2,2);
         l_g(3,1):=q*r;
         l_g(3,2):=0;
         l_g(3,3):=q*tt/f5(2,2);
         liemat:=l_g*liemat>>>> else
     if alpha>0 then
      <<l_g(1,1):=1/(s*sqrt(tt));
        l_g(1,2):=0;
        l_g(1,3):=0;
        l_g(2,1):=q*r;
        l_g(2,2):=0;
        l_g(2,3):=q*tt/f5(2,2);
        l_g(3,1):=q*s*sqrt(tt)*f5(2,1)/f5(2,2);
        l_g(3,2):=q*s*sqrt(tt);
        l_g(3,3):=-q*s*sqrt(tt)*f5(1,2)/f5(2,2);
        liemat:=l_g*liemat>> else
      <<l_g(1,1):=1/(s*sqrt(tt));
        l_g(1,2):=0;
        l_g(1,3):=0;
        l_g(2,1):=q*s*sqrt(tt)*f5(2,1)/f5(2,2);
        l_g(2,2):=q*s*sqrt(tt);
        l_g(2,3):=-q*s*sqrt(tt)*f5(1,2)/f5(2,2);
        l_g(3,1):=q*r;
        l_g(3,2):=0;
        l_g(3,3):=q*tt/f5(2,2);
        liemat:=l_g*liemat>>>>>> else
  if f5(1,2)**2+f5(1,3)*f5(2,2)<0 then
   <<s:=f5(2,2)/abs(f5(2,2));
     tt:=abs(f5(1,2)**2+f5(1,3)*f5(2,2));
     r:=f5(1,1)-f5(1,2)*f5(2,1)/f5(2,2);
     alpha:=tt*(-r*r-((f5(2,1)/f5(2,2))**2+f5(3,1)/f5(2,2))*tt);
     q:=1/sqrt(abs(alpha));
     l_g(1,1):=-q*s*sqrt(tt)*f5(2,1)/f5(2,2);
     l_g(1,2):=-q*s*sqrt(tt);
     l_g(1,3):=q*s*sqrt(tt)*f5(1,2)/f5(2,2);
     l_g(2,1):=1/(s*sqrt(tt));
     l_g(2,2):=0;
     l_g(2,3):=0;
     l_g(3,1):=q*r;
     l_g(3,2):=0;
     l_g(3,3):=-q*tt/f5(2,2);
     liemat:=l_g*liemat>> else
   <<s:=f5(2,2)/abs(f5(2,2));
     tt:=f5(1,2)**2+f5(1,3)*f5(2,2);
     r:=f5(1,1)-f5(1,2)*f5(2,1)/f5(2,2);
     alpha:=tt*(r*r-((f5(2,1)/f5(2,2))**2+f5(3,1)/f5(2,2))*tt);
     q:=1/sqrt(abs(alpha));
     if not(numberp(alpha)) then
     <<write "Is ",alpha,">0 ? (y/n) and press <RETURN>";
       he:=symbolic read();
       if he=y then
       <<l_g(1,1):=1/(s*sqrt(tt));
         l_g(1,2):=0;
         l_g(1,3):=0;
         l_g(2,1):=q*r;
         l_g(2,2):=0;
         l_g(2,3):=q*tt/f5(2,2);
         l_g(3,1):=q*s*sqrt(tt)*f5(2,1)/f5(2,2);
         l_g(3,2):=q*s*sqrt(tt);
         l_g(3,3):=-q*s*sqrt(tt)*f5(1,2)/f5(2,2);
         liemat:=l_g*liemat>> else
       <<l_g(1,1):=1/(s*sqrt(tt));
         l_g(1,2):=0;
         l_g(1,3):=0;
         l_g(2,1):=q*s*sqrt(tt)*f5(2,1)/f5(2,2);
         l_g(2,2):=q*s*sqrt(tt);
         l_g(2,3):=-q*s*sqrt(tt)*f5(1,2)/f5(2,2);
         l_g(3,1):=q*r;
         l_g(3,2):=0;
         l_g(3,3):=q*tt/f5(2,2);
         liemat:=l_g*liemat>>>> else
     if alpha>0 then
      <<l_g(1,1):=1/(s*sqrt(tt));
        l_g(1,2):=0;
        l_g(1,3):=0;
        l_g(2,1):=q*r;
        l_g(2,2):=0;
        l_g(2,3):=q*tt/f5(2,2);
        l_g(3,1):=q*s*sqrt(tt)*f5(2,1)/f5(2,2);
        l_g(3,2):=q*s*sqrt(tt);
        l_g(3,3):=-q*s*sqrt(tt)*f5(1,2)/f5(2,2);
        liemat:=l_g*liemat>> else
      <<l_g(1,1):=1/(s*sqrt(tt));
        l_g(1,2):=0;
        l_g(1,3):=0;
        l_g(2,1):=q*s*sqrt(tt)*f5(2,1)/f5(2,2);
        l_g(2,2):=q*s*sqrt(tt);
        l_g(2,3):=-q*s*sqrt(tt)*f5(1,2)/f5(2,2);
        l_g(3,1):=q*r;
        l_g(3,2):=0;
        l_g(3,3):=q*tt/f5(2,2);
        liemat:=l_g*liemat>>>>;
  if symbolic !*tr_lie then
  write "[X,Y]=Z, [X,Z]=Y, [Y,Z]=X";lie_class:={liealg(3),comtab(8)};
  clear l_g,f5
end;

algebraic procedure lie4();
begin
     scalar lam,jac1,jac2,jac3,jac4;
     integer p1,m1,m2,m3,diml1;
     matrix l_f(6,4);
     array ordv(12);
 ordv(1):=ordv(3):=ordv(7):=1;ordv(2):=ordv(5):=ordv(9):=2;
 ordv(4):=ordv(6):=ordv(11):=3;ordv(8):=ordv(10):=ordv(12):=4;
 for i:=1:4 do
  <<l_f(1,i):=cc(1,2,i);l_f(2,i):=cc(1,3,i);l_f(3,i):=cc(2,3,i);
    l_f(4,i):=cc(1,4,i);l_f(5,i):=cc(2,4,i);l_f(6,i):=cc(3,4,i);
    cc(1,1,i):=cc(2,2,i):=cc(3,3,i):=cc(4,4,i):=0;
    cc(2,1,i):=-l_f(1,i);cc(3,1,i):=-l_f(2,i);cc(3,2,i):=-l_f(3,i);
    cc(4,1,i):=-l_f(4,i);cc(4,2,i):=-l_f(5,i);cc(4,3,i):=-l_f(6,i)>>;
 for s:=1:4 do
 <<jac1:=for r:=1:4 sum
    cc(1,2,r)*cc(r,3,s)+cc(2,3,r)*cc(r,1,s)+cc(3,1,r)*cc(r,2,s);
   jac2:=for r:=1:4 sum
    cc(1,2,r)*cc(r,4,s)+cc(2,4,r)*cc(r,1,s)+cc(4,1,r)*cc(r,2,s);
   jac3:=for r:=1:4 sum
    cc(1,3,r)*cc(r,4,s)+cc(3,4,r)*cc(r,1,s)+cc(4,1,r)*cc(r,3,s);
   jac4:=for r:=1:4 sum
    cc(2,3,r)*cc(r,4,s)+cc(3,4,r)*cc(r,2,s)+cc(4,2,r)*cc(r,3,s);
   if (jac1 neq 0 OR jac2 neq 0 OR jac3 neq 0 OR jac4 neq 0 ) then
    s:=4>>;
 if (jac1 neq 0 OR jac2 neq 0 OR jac3 neq 0 OR jac4 neq 0 )then
  <<clear l_f,ordv,cc;symbolic rederr "not a Lie algebra">>;
 m1:=0;
 for s:=1:6 do
  for tt:=1:4 do
   if l_f(s,tt) neq 0 then <<m1:=s;p1:=tt;s:=6;tt:=4>>;
 if m1=0 then diml1:=0 else
  if m1=6 then diml1:=1 else
  <<m2:=0;
    for s:=m1+1:6 do
     <<lam:=l_f(s,p1)/l_f(m1,p1);
       for tt:=1:4 do
       if l_f(s,tt) neq lam*l_f(m1,tt) then <<m2:=s;s:=6;tt:=4>>>>;
       if m2=0 then diml1:=1 else
     if m2=6 then diml1:=2 else
     <<m3:=0;
       for s:=m2+1:6 do
       if not(det(mat((l_f(m1,2),l_f(m1,3),l_f(m1,4)),
                      (l_f(m2,2),l_f(m2,3),l_f(m2,4)),
                      (l_f(s,2),l_f(s,3),l_f(s,4))))=0 and
              det(mat((l_f(m1,1),l_f(m1,3),l_f(m1,4)),
                      (l_f(m2,1),l_f(m2,3),l_f(m2,4)),
                      (l_f(s,1),l_f(s,3),l_f(s,4))))=0 and
              det(mat((l_f(m1,1),l_f(m1,2),l_f(m1,4)),
                      (l_f(m2,1),l_f(m2,2),l_f(m2,4)),
                      (l_f(s,1),l_f(s,2),l_f(s,4))))=0 and
              det(mat((l_f(m1,1),l_f(m1,2),l_f(m1,3)),
                      (l_f(m2,1),l_f(m2,2),l_f(m2,3)),
                      (l_f(s,1),l_f(s,2),l_f(s,3))))=0)
        then <<m3:=s;s:=6>>;
       if m3=0 then diml1:=2 else diml1:=3>>>>;
   if diml1=0 then
    <<if symbolic !*tr_lie then write "Your Lie algebra is commutative";
      lie_class:={liealg(4),comtab(0)};
      liemat:=mat((1,0,0,0),(0,1,0,0),(0,0,1,0),(0,0,0,1))>> else
    if diml1=3 then
    com43(ordv(2*m1-1),ordv(2*m1),ordv(2*m2-1),ordv(2*m2),
            ordv(2*m3-1),ordv(2*m3)) else
      if diml1=1 then
       com41(ordv(2*m1-1),ordv(2*m1),p1) else
        com42(ordv(2*m1-1),ordv(2*m1),ordv(2*m2-1),ordv(2*m2));
 clear ordv,l_f
end;

algebraic procedure com41(i1,j1,p1);
begin scalar y1,y2,y3,beta1,beta2,beta3,beta4,beta5,beta6;
      matrix liemat(4,4);
 for i:=1:4 do liemat(1,i):=cc(i1,j1,i);
 if p1=1 then <<y1:=2;y2:=3;y3:=4>> else
  if p1=2 then <<y1:=1;y2:=3;y3:=4>> else
   if p1=3 then <<y1:=1;y2:=2;y3:=4>> else
    <<y1:=1;y2:=2;y3:=3>>;
 liemat(2,y1):=liemat(3,y2):=liemat(4,y3):=1;
 beta1:=(for l:=1:4 sum cc(i1,j1,l)*cc(l,y1,p1))/cc(i1,j1,p1);
 beta2:=(for l:=1:4 sum cc(i1,j1,l)*cc(l,y2,p1))/cc(i1,j1,p1);
 beta3:=cc(y1,y2,p1)/cc(i1,j1,p1);
 beta4:=(for l:=1:4 sum cc(i1,j1,l)*cc(l,y3,p1))/cc(i1,j1,p1);
 beta5:=cc(y1,y3,p1)/cc(i1,j1,p1);
 beta6:=cc(y2,y3,p1)/cc(i1,j1,p1);
 if (beta1=0 and beta2=0 and beta3=0 and beta4=0 and beta5=0) then
  <<liemat:=mat((1,0,0,0),(0,0,0,1),(0,0,1,0),(0,1,0,0))*liemat;
    beta3:=-beta6;beta6:=0>> else
  if (beta1=0 and beta2=0 and beta3=0) then
   <<liemat:=mat((1,0,0,0),(0,1,0,0),(0,0,0,1),(0,0,1,0))*liemat;
     beta2:=beta4;beta3:=beta5;beta4:=beta5:=0;beta6:=-beta6>>;
 if (beta1=0 and beta2=0) then
  <<liemat:=mat((beta3,0,0,0),(0,1,0,0),(0,0,1,0),(0,0,0,1))*liemat;
    y1:=beta4;y2:=beta5/beta3;y3:=beta6/beta3>> else
  if beta1=0 then
   <<liemat:=mat((1,0,0,0),(-beta3/beta2,1,0,0),(0,0,1/beta2,0),
             (0,0,0,1))*liemat;y1:=beta4;
     y2:=beta5-beta3*beta4/beta2;y3:=beta6/beta2>> else
    <<liemat:=mat((1,0,0,0),(beta3/beta1,-beta2/beta1,1,0),
              (0,1/beta1,0,0),(0,0,0,1))*liemat;
      y1:=beta4;y2:=(beta3*beta4-beta2*beta5)/beta1;
      y3:=beta5/beta1>>;
 if (beta1=0 and beta2=0) then
  <<liemat:=mat((1,0,0,0),(0,1,0,0),(0,y3,-y2,1),(0,0,1,0))*liemat;
    if symbolic !*tr_lie then
    write "[X,Z]=W";lie_class:={liealg(4),comtab(2)}>> else
  <<if y1=0 then
    liemat:=mat((1,0,0,0),(0,1,0,0),(-y3,0,0,-1),(0,0,1,1))*liemat else
    liemat:=mat((1,0,0,0),(0,1,0,0),(-y3/y1,0,1,-1/y1),(0,0,0,1/y1))*
    liemat;
    if symbolic !*tr_lie then
    write "[W,Z]=W";lie_class:={liealg(4),comtab(1)}>>
end;


algebraic procedure com42(i1,j1,i2,j2);
begin scalar d,d1,d2,d3,d4,a1,a2,a3,a4,a5,b1,b2,b3,b4,b5;
      matrix liemat(4,4);
      array sol(1,4);
 for i:=1:4 do <<liemat(1,i):=cc(i1,j1,i);liemat(2,i):=cc(i2,j2,i)>>;
 liemat(3,1):=liemat(4,2):=1;if (d:=det(liemat)) neq 0 then
  <<d1:=1;d2:=2;d3:=3;d4:=4>> else
  <<liemat(4,2):=0;liemat(4,3):=1;if (d:=det(liemat)) neq 0 then
   <<d1:=1;d2:=3;d3:=2;d4:=4;d:=-d>> else
   <<liemat(3,1):=0;liemat(3,2):=1;if (d:=det(liemat)) neq 0 then
    <<d1:=2;d2:=3;d3:=1;d4:=4>> else
    <<liemat(3,2):=liemat(4,3):=0;liemat(3,1):=liemat(4,4):=1;
      if (d:=det(liemat)) neq 0 then
     <<d1:=1;d2:=4;d3:=2;d4:=3>> else
     <<liemat(3,1):=0;liemat(3,2):=1;if (d:=det(liemat)) neq 0 then
      <<d1:=2;d2:=4;d3:=1;d4:=3;d:=-d>> else
      <<liemat(3,2):=0;liemat(3,3):=1;d:=det(liemat);
        d1:=3;d2:=4;d3:=1;d4:=2>>
  >>>>>>>>;
 a1:=for r:=1:4 sum ( cc(i1,j1,r)*cc(r,d1,d3)*cc(i2,j2,d4)-
                      cc(i1,j1,r)*cc(r,d1,d4)*cc(i2,j2,d3))/d;
 b1:=for r:=1:4 sum (-cc(i1,j1,r)*cc(r,d1,d3)*cc(i1,j1,d4)+
                      cc(i1,j1,r)*cc(r,d1,d4)*cc(i1,j1,d3))/d;
 a2:=for r:=1:4 sum ( cc(i2,j2,r)*cc(r,d1,d3)*cc(i2,j2,d4)-
                      cc(i2,j2,r)*cc(r,d1,d4)*cc(i2,j2,d3))/d;
 b2:=for r:=1:4 sum (-cc(i2,j2,r)*cc(r,d1,d3)*cc(i1,j1,d4)+
                      cc(i2,j2,r)*cc(r,d1,d4)*cc(i1,j1,d3))/d;
 a3:=for r:=1:4 sum ( cc(i1,j1,r)*cc(r,d2,d3)*cc(i2,j2,d4)-
                      cc(i1,j1,r)*cc(r,d2,d4)*cc(i2,j2,d3))/d;
 b3:=for r:=1:4 sum (-cc(i1,j1,r)*cc(r,d2,d3)*cc(i1,j1,d4)+
                      cc(i1,j1,r)*cc(r,d2,d4)*cc(i1,j1,d3))/d;
 a4:=for r:=1:4 sum ( cc(i2,j2,r)*cc(r,d2,d3)*cc(i2,j2,d4)-
                      cc(i2,j2,r)*cc(r,d2,d4)*cc(i2,j2,d3))/d;
 b4:=for r:=1:4 sum (-cc(i2,j2,r)*cc(r,d2,d3)*cc(i1,j1,d4)+
                      cc(i2,j2,r)*cc(r,d2,d4)*cc(i1,j1,d3))/d;
 a5:=( cc(d1,d2,d3)*cc(i2,j2,d4)-cc(d1,d2,d4)*cc(i2,j2,d3))/d;
 b5:=(-cc(d1,d2,d3)*cc(i1,j1,d4)+cc(d1,d2,d4)*cc(i1,j1,d3))/d;
 findcentre(a1,a2,a3,a4,a5,b1,b2,b3,b4,b5);
   if nottriv=0 then trivcent(a1,a2,a3,a4,a5,b1,b2,b3,b4,b5)
  else
  if (sol(1,3)=0 and sol(1,4)=0) then
   if sol(1,1)=0 then
   <<liemat:=mat((0,1,0,0),(1,0,0,0),(0,0,1,0),(0,0,0,1))*liemat;
   centincom(b1,b3,b5,a1,a3,a5)>> else
   <<liemat:=mat((1,sol(1,2)/sol(1,1),0,0),(0,1,0,0),(0,0,1,0),
            (0,0,0,1))*liemat;centincom(a2,a4,a5,
     b2-sol(1,2)/sol(1,1)*a2,b4-sol(1,2)/sol(1,1)*a4,
     b5-sol(1,2)/sol(1,1)*a5)>> else
  if det(mat((1,0,0,0),(0,1,0,0),
        (sol(1,1),sol(1,2),sol(1,3),sol(1,4)),(0,0,0,1)))=0 then
  <<liemat:=mat((1,0,0,0),(0,1,0,0),
        (sol(1,1),sol(1,2),sol(1,3),sol(1,4)),(0,0,1,0))*liemat;
  centoutcom(a1,a2,b1,b2)>> else
  <<liemat:=mat((1,0,0,0),(0,1,0,0),
        (sol(1,1),sol(1,2),sol(1,3),sol(1,4)),(0,0,0,1))*liemat;
  centoutcom(a3,a4,b3,b4)>>;
 clear sol,nottriv
end;

algebraic procedure findcentre(a1,a2,a3,a4,a5,b1,b2,b3,b4,b5);
begin integer flag;
      scalar help;
 nottriv:=0;flag:=0;
 cent:=mat((a1,a2,0,-a5),(a3,a4,a5,0),(b1,b2,0,-b5),
           (b3,b4,b5,0),(0,0,a1,a3),(0,0,a2,a4),
           (0,0,b1,b3),(0,0,b2,b4));
 for i:=1:4 do
  if (cent(i,1) neq 0 and flag=0) then
  <<flag:=1;for j:=1:4 do
   <<help:=cent(1,j);cent(1,j):=cent(i,j);cent(i,j):=help>>>>;
 if flag=0 then <<nottriv:=1;sol(1,1):=1>> else
 <<for i:=2:4 do <<help:=cent(i,1)/cent(1,1);
   for j:=1:4 do cent(i,j):=cent(i,j)-help*cent(1,j)>>;
   flag:=0;
   for i:=2:4 do
    if (cent(i,2) neq 0 and flag=0) then
    <<flag:=1;for j:=2:4 do
     <<help:=cent(2,j);cent(2,j):=cent(i,j);cent(i,j):=help>>>>;
   if flag=0 then <<nottriv:=1;sol(1,1):=-cent(1,2);
                    sol(1,2):=cent(1,1)>> else
   <<for i:=3:4 do <<help:=cent(i,2)/cent(2,2);
     for j:=2:4 do cent(i,j):=cent(i,j)-help*cent(2,j)>>;
     flag:=0;
     for i:=3:8 do
      if (cent(i,3) neq 0 and flag=0) then
      <<flag:=1;for j:=3:4 do
       <<help:=cent(3,j);cent(3,j):=cent(i,j);cent(i,j):=help>>>>;
     if flag=0 then <<nottriv:=1;
      sol(1,1):=(cent(1,2)*cent(2,3)/cent(2,2)-cent(1,3))/cent(1,1);
      sol(1,2):=-cent(2,3)/cent(2,2);sol(1,3):=1>> else
     <<for i:=4:8 do <<help:=cent(i,3)/cent(3,3);
       for j:=3:4 do cent(i,j):=cent(i,j)-help*cent(3,j)>>;
       flag:=0;
       for i:=4:8 do
        if (cent(i,4) neq 0 and flag=0) then
        <<flag:=1;cent(4,4):=cent(i,4)>>;
       if flag=0 then <<nottriv:=1;
        sol(1,1):=(-(cent(2,3)*cent(3,4)/cent(3,3)-cent(2,4))*
                  cent(1,2)/cent(2,2)+cent(3,4)*cent(1,3)/
                  cent(3,3)-cent(1,4))/cent(1,1);
        sol(1,2):=(cent(2,3)*cent(3,4)/cent(3,3)-cent(2,4))/
                  cent(2,2);
        sol(1,3):=-cent(3,4)/cent(3,3);sol(1,4):=1>>
  >>>>>>;
 clear cent
end;

algebraic procedure centincom(a,c,e,b,d,f);
begin scalar v1,w1,v2,w2;
 if c=0 then if d=0 then
   <<liemat:=mat((1,0,0,0),(0,1,0,0),(0,0,0,1),(0,0,1,0))*liemat;
     v1:=a;v2:=-e;w1:=b;w2:=-f>> else
     <<liemat:=mat((1,0,0,0),(0,1,0,0),(0,0,1,-b/d),(0,0,0,1))*liemat;
       v1:=c;v2:=e;w1:=d;w2:=f>> else
  <<liemat:=mat((1,0,0,0),(0,1,0,0),(0,0,1,-a/c),(0,0,0,1))*liemat;
    v1:=c;v2:=e;w1:=d;w2:=f>>;
 if w1=0 then
  <<liemat:=mat((1,0,0,0),(0,1,0,0),(0,-v2/w2,v1/w2,0),(0,0,0,1/v1))*
  liemat;
    if symbolic !*tr_lie then
    write "[X,Z]=w, [Y,Z]=X";lie_class:={liealg(4),comtab(6)}>> else
  <<liemat:=mat((1,0,0,0),(0,1,0,0),(0,-w2/(w1*v2-w2*v1),
             w1*w1/(w1*v2-w2*v1),0),(0,0,0,1/w1))*
        mat((1,0,0,0),(v1,w1,0,0),(0,0,1,0),(0,0,0,1))*liemat;
    if symbolic !*tr_lie then
    write "[X,Z]=X, [Y,Z]=w";lie_class:={liealg(4),comtab(7)}>>
end;

algebraic procedure centoutcom(a,c,b,d);
begin integer flag;
      scalar alpha,beta;
 flag:=0;
 if c neq 0 then
 <<liemat:=mat((0,b-a*d/c,0,0),(1,-a/c,0,0),(0,0,1,0),(0,0,0,1))*liemat;
    alpha:=a+d;beta:=b*c-a*d>> else
  if b neq 0 then
   <<liemat:=mat((-a*d/b,0,0,0),(-d*d/b,d,0,0),(0,0,1,0),(0,0,0,1/d))*
   liemat;
     alpha:=1+a/d;beta:=-a/d>> else
   if a neq d then
    <<liemat:=mat((1,1,0,0),(1/a,1/d,0,0),(0,0,1,0),(0,0,0,1))*liemat;
      alpha:=a+d;beta:=-a*d>> else
      <<liemat:=mat((1,0,0,0),(0,1,0,0),(0,0,1,0),(0,0,0,1/a))*liemat;
        flag:=1>>;
 if flag=1 then
  <<if symbolic !*tr_lie then
    write "[W,Z]=W, [X,Z]=X";lie_class:={liealg(4),comtab(10)}>> else
  if alpha=0 then
   <<liemat:=mat((1,0,0,0),(0,sqrt(abs(beta)),0,0),(0,0,1,0),
             (0,0,0,1/sqrt(abs(beta))))*liemat;
     if symbolic !*tr_lie then
     write "[W,Z]=",beta/abs(beta),"X, [X,Z]=W";
     if beta>0 then lie_class:={liealg(4),comtab(11)} else
                    lie_class:={liealg(4),comtab(8)}>> else
    <<liemat:=mat((1,0,0,0),(0,-alpha,0,0),(0,0,1,0),
              (0,0,0,-1/alpha))*liemat;
      if symbolic !*tr_lie then
      write "[W,Z]=-W+",beta/(alpha**2),"X, [X,Z]=W";
      lie_class:={liealg(4),comtab(9),beta/(alpha**2)}>>
end;

algebraic procedure trivcent(a1,a2,a3,a4,a5,b1,b2,b3,b4,b5);
begin integer flag;
      scalar he,help,alpha,beta,c1,c2,c3,c4,c5,
             d1,d2,d3,d4,d5,P,e1,e2,e3,e4,e5,e6;
 if (a1*b2-a2*b1)=0 then
  if (a3*b4-a4*b3)=0 then
   <<liemat:=mat((1,0,0,0),(0,1,0,0),(0,0,1,1),(0,0,0,1))*liemat;
     a1:=a1+a3;b1:=b1+b3;a2:=a2+a4;b2:=b2+b4>> else
   <<liemat:=mat((1,0,0,0),(0,1,0,0),(0,0,0,1),(0,0,1,0))*liemat;
     help:=a1;a1:=a3;a3:=help;help:=a2;a2:=a4;a4:=help;
     help:=b1;b1:=b3;b3:=help;help:=b2;b2:=b4;b4:=help;
     a5:=-a5;b5:=-b5>>;
 if a2 neq 0 then <<alpha:=a1+b2;beta:=a2*b1-a1*b2;
  if alpha=0 then
   <<c1:=0;c2:=b1-a1*b2/a2;c3:=sqrt(abs(beta));c4:=-c3*a1/a2;
     c5:=1/c3;d1:=a1/(a2*c2);d2:=c5;d3:=1/c2;d4:=0;d5:=c3;
     if not(numberp(beta)) then
     <<write "Is ",beta,">0 ? (y/n) and press <RETURN>";
       he:=symbolic read();
       if he=y then flag:=2 else flag:=3>> else
     if beta>0 then flag:=2 else flag:=3>> else
   <<c1:=0;c2:=b1-a1*b2/a2;c3:=-alpha;c4:=alpha*a1/a2;
     c5:=1/c3;d1:=a1/(a2*c2);d2:=c5;d3:=1/c2;d4:=0;d5:=c3;
     flag:=4;P:=beta/(alpha*alpha)>>>> else
  if b1 neq 0 then <<alpha:=1+a1/b2;beta:=-a1/b2;
   if alpha=0 then
    <<c1:=-a1*b2/b1;c2:=0;c3:=-sqrt(abs(beta))*b2/b1;c4:=-c3*b1;
      c5:=1/c4;d1:=1/c1;d2:=0;d3:=-1/(a1*b2);d4:=c5;d5:=c4;
      if not(numberp(beta)) then
     <<write "Is ",beta,">0 ? (y/n) and press <RETURN>";
       he:=symbolic read();
       if he=y then flag:=2 else flag:=3>> else
      if beta>0 then flag:=2 else flag:=3>> else
    <<c1:=-a1*b2/b1;c2:=0;c3:=alpha*b2/b1;c4:=-alpha*b2;
      c5:=1/c4;d1:=1/c1;d2:=0;d3:=-1/(a1*b2);d4:=c5;d5:=c4;
      flag:=4;P:=beta/(alpha*alpha)>>>> else
   if a1 neq b2 then <<alpha:=a1+b2;beta:=-a1*b2;
    if alpha=0 then
     <<c1:=1;c2:=1;c3:=sqrt(abs(beta))/a1;c4:=sqrt(abs(beta))/b2;
       c5:=1/sqrt(abs(beta));help:=1/b2-1/a1;d1:=1/(b2*help);
       d2:=-c5/help;d3:=-1/(a1*help);d4:=-d2;d5:=1/c5;
       if not(numberp(beta)) then
     <<write "Is ",beta,">0 ? (y/n) and press <RETURN>";
       he:=symbolic read();
       if he=y then flag:=2 else flag:=3>> else
       if beta>0 then flag:=2 else flag:=3>> else
     <<c1:=1;c2:=1;c3:=-alpha/a1;c4:=-alpha/b2;c5:=-1/alpha;
       help:=1/b2-1/a1;d1:=1/(b2*help);d2:=1/(alpha*help);
       d3:=-1/(a1*help);d4:=-d2;d5:=-alpha;
       flag:=4;P:=beta/(alpha*alpha)>>>> else
     <<c1:=1;c2:=0;c3:=0;c4:=1;c5:=1/a1;
       d1:=1;d2:=0;d3:=0;d4:=1;d5:=a1;flag:=1>>;
 liemat:=mat((c1,c2,0,0),(c3,c4,0,0),(0,0,c5,0),(0,0,0,1))*liemat;
 e1:=d1*(c1*a3+c2*a4)+d3*(c1*b3+c2*b4);
 e2:=d2*(c1*a3+c2*a4)+d4*(c1*b3+c2*b4);
 e3:=d1*(c3*a3+c4*a4)+d3*(c3*b3+c4*b4);
 e4:=d2*(c3*a3+c4*a4)+d4*(c3*b3+c4*b4);
 e5:=c5*a5*d1+c5*b5*d3;
 e6:=c5*a5*d2+c5*b5*d4;
 if flag=4 then
  <<liemat:=mat((1,0,0,0),(0,1,0,0),(0,0,e1+e4,1),(0,0,1,0))*liemat;
    a1:=-e4;a2:=e1+e3+e4;a3:=-1;a4:=1;a5:=-e5;
    b1:=P*(e1+e4)+e2;b2:=e4;b3:=P;b4:=0;b5:=-e6>> else
  if flag=1 then
   if (e1+e4=0) then
    <<liemat:=mat((1,0,0,0),(0,1,0,0),(0,0,0,1),(0,0,1,0))*liemat;
      a1:=e1;a2:=e3;a3:=1;a4:=0;a5:=-e5;
      b1:=e2;b2:=e4;b3:=0;b4:=1;b5:=-e6>> else
    <<liemat:=mat((1,0,0,0),(0,1,0,0),(0,0,e1+e4,-2),(0,0,0,1))*liemat;
      a1:=e4-e1;a2:=-2*e3;a3:=e1;a4:=e3;a5:=e5*(e1+e4);
      b1:=-2*e2;b2:=e1-e4;b3:=e2;b4:=e4;b5:=e6*(e1+e4)>>;
 if (flag=1 OR flag=4) then
  if a1*b2-a2*b1=0 then
   if b1=0 then
    <<liemat:=mat((a2,0,0,0),(0,1,0,0),(0,0,1,0),(0,0,0,1))*liemat;
      flag:=5;e1:=a3;e2:=b3*a2;e3:=a4/a2;e4:=b4;e5:=a5/a2;
      e6:=b5>> else
    <<liemat:=mat((a1,b1,0,0),(1,0,0,0),(0,0,1,0),(0,0,0,1))*liemat;
      flag:=5;e1:=(a1*b3+b1*b4)/b1;
      e2:=a1*a3+b1*a4-a1*(a1*b3+b1*b4)/b1;e3:=b3/b1;
      e4:=a3-a1*b3/b1;e5:=b5/b1;e6:=a5-b5*a1/b1>> else
   <<if a2 neq 0 then
      <<beta:=a2*b1-a1*b2;c1:=0;c2:=b1-a1*b2/a2;
        c3:=sqrt(abs(beta));c4:=-c3*a1/a2;c5:=1/c3;
        d1:=a1/(a2*c2);d2:=c5;d3:=1/c2;d4:=0;d5:=c3>> else
       if b1 neq 0 then
        <<beta:=-a1/b2;c1:=-a1*b2/b1;c2:=0;
          c3:=-sqrt(abs(beta))*b2/b1;c4:=-c3*b1;c5:=1/c4;
          d1:=1/c1;d2:=0;d3:=-1/(a1*b2);d4:=c5;d5:=c4>> else
        <<beta:=-a1*b2;c1:=1;c2:=1;c3:=sqrt(abs(beta))/a1;
          c4:=sqrt(abs(beta))/b2;c5:=1/sqrt(abs(beta));
          help:=1/b2-1/a1;d1:=1/(b2*help);d2:=-c5/help;
          d3:=-1/(a1*help);d4:=-d2;d5:=1/c5>>;
     if not(numberp(beta)) then
     <<write "Is ",beta,">0 ? (y/n) and press <RETURN>";
       he:=symbolic read();
       if he=y then flag:=2 else flag:=3>> else
     if beta>0 then flag:=2 else flag:=3;
     liemat:=mat((c1,c2,0,0),(c3,c4,0,0),(0,0,c5,0),(0,0,0,1))*liemat;
     e1:=d1*(c1*a3+c2*a4)+d3*(c1*b3+c2*b4);
     e2:=d2*(c1*a3+c2*a4)+d4*(c1*b3+c2*b4);
     e3:=d1*(c3*a3+c4*a4)+d3*(c3*b3+c4*b4);
     e4:=d2*(c3*a3+c4*a4)+d4*(c3*b3+c4*b4);
     e5:=c5*a5*d1+c5*b5*d3;
     e6:=c5*a5*d2+c5*b5*d4>>;
 if flag=2 then
  <<liemat:=mat((1,0,0,0),(0,1,0,0),(-e5/e1,-e6/e1,1,0),
            (0,0,-e2/e1,1/e1))*liemat;
    liemat:=mat((1/2,1/2,0,0),(1/2,-1/2,0,0),(0,0,1/2,1/2),
            (0,0,-1/2,1/2))*liemat;
    if symbolic !*tr_lie then
    write "[W,Y]=W, [X,Z]=X";lie_class:={liealg(4),comtab(3)}>> else
  if flag=3 then
   <<liemat:=mat((1,0,0,0),(0,1,0,0),(-e5/e1,-e6/e1,1,0),
             (0,0,e2/e1,1/e1))*liemat;
     if symbolic !*tr_lie then
     write "-[W,Y]=[X,Z]=X, [X,Y]=[W,Z]=W";
     lie_class:={liealg(4),comtab(4)}>> else
  <<liemat:=mat((1,0,0,0),(0,1,0,0),(-e5/e1,-e6/e1,1,0),
            (0,0,-e3/e1,1/e1))*liemat;
    if symbolic !*tr_lie then
    write "[X,Y]=[W,Z]=W, [X,Z]=X";lie_class:={liealg(4),comtab(5)}>>;
end;

algebraic procedure com43(i1,j1,i2,j2,i3,j3);
begin integer ll;
      matrix liemat(4,4),bb(4,4),ff(3,3);
      array l_z(4,4,3);
 for i:=1:4 do
  <<cc(2,1,i):=-cc(1,2,i);cc(3,1,i):=-cc(1,3,i);
    cc(3,2,i):=-cc(2,3,i);cc(4,1,i):=-cc(1,4,i);
    cc(4,2,i):=-cc(2,4,i);cc(4,3,i):=-cc(3,4,i);
    cc(1,1,i):=cc(2,2,i):=cc(3,3,i):=cc(4,4,i):=0;
    liemat(1,i):=cc(i1,j1,i);liemat(2,i):=cc(i2,j2,i);
    liemat(3,i):=cc(i3,j3,i)>>;
 liemat(4,1):=1;if det(liemat) neq 0 then ll:=1 else
  for j:=2:4 do <<liemat(4,j-1):=0;liemat(4,j):=1;
  if det(liemat) neq 0 then <<ll:=j;j:=4>>>>;
 bb:=1/liemat;
 for i:=1:3 do
  <<l_z(1,2,i):=for r:=1:4 sum for s:=1:4 sum for tt:=1:4 sum
              liemat(1,r)*liemat(2,s)*cc(r,s,tt)*bb(tt,i);
    l_z(1,3,i):=for r:=1:4 sum for s:=1:4 sum for tt:=1:4 sum
              liemat(1,r)*liemat(3,s)*cc(r,s,tt)*bb(tt,i);
    l_z(2,3,i):=for r:=1:4 sum for s:=1:4 sum for tt:=1:4 sum
              liemat(2,r)*liemat(3,s)*cc(r,s,tt)*bb(tt,i);
    l_z(1,4,i):=for r:=1:4 sum for tt:=1:4 sum
              liemat(1,r)*cc(r,ll,tt)*bb(tt,i);
    l_z(2,4,i):=for r:=1:4 sum for tt:=1:4 sum
              liemat(2,r)*cc(r,ll,tt)*bb(tt,i);
    l_z(3,4,i):=for r:=1:4 sum for tt:=1:4 sum
              liemat(3,r)*cc(r,ll,tt)*bb(tt,i)>>;
 for i:=1:3 do
  <<ff(1,i):=l_z(1,2,i);ff(2,i):=l_z(1,3,i);ff(3,i):=l_z(2,3,i)>>;
 ll:=0;
 for i:=1:3 do for j:=1:3 do
  if ff(i,j) neq 0 then <<ll:=1;i:=3;j:=3>>;
 if ll=0 then comcom0() else
  if det(ff)=0 then comcom1() else comcom3();
 clear bb,ff,l_z
end;

algebraic procedure comcom0();
begin scalar he,a1,b1,c1,a2,b2,c2,a3,b3,c3,aa1,bb1,cc1,
             aa2,bb2,cc2,al1,be1,ga1,al2,be2,ga2,r,s,P,q;
 a1:=l_z(1,4,1);b1:=l_z(1,4,2);c1:=l_z(1,4,3);
 a2:=l_z(2,4,1);b2:=l_z(2,4,2);c2:=l_z(2,4,3);
 a3:=l_z(3,4,1);b3:=l_z(3,4,2);c3:=l_z(3,4,3);
 if (a3=0 and b3=0) then
  <<liemat:=mat((1,0,0,0),(0,1,0,0),(0,0,1,0),(0,0,0,1/c3))*liemat;
    al1:=a1/c3;be1:=b1/c3;ga1:=c1/c3;
    al2:=a2/c3;be2:=b2/c3;ga2:=c2/c3>> else
  <<if (a3=0 and b3 neq 0) then
   <<liemat:=mat((0,b3,c3,0),(1,0,0,0),(0,0,1,0),(0,0,0,1))*liemat;
     aa1:=b2+c3;bb1:=b3*a2;cc1:=b3*c2-b2*c3;
     aa2:=b1/b3;bb2:=a1;cc2:=c1-b1*c3/b3>> else
   <<liemat:=mat((a3,b3,c3,0),(0,1,0,0),(0,0,1,0),(0,0,0,1))*liemat;
     aa1:=a1+b3*a2/a3+c3;bb1:=a3*b1-a1*b3-b3*b3*a2/a3+b3*b2;
     cc1:=a3*c1-a1*c3-b3*a2*c3/a3+b3*c2;
     aa2:=a2/a3;bb2:=b2-a2*b3/a3;cc2:=c2-a2*c3/a3>>;
  <<liemat:=mat((1,0,0,0),(0,1,-aa2,0),(0,0,1,0),(0,0,0,1))*liemat;
    cc1:=cc1+bb1*aa2;cc2:=cc2+bb2*aa2;aa2:=0>>;
  if (bb1=0 and aa1=bb2 and cc2 neq 0) then
   <<liemat:=mat((0,0,1,0),(0,1,0,0),(1,-cc1/cc2,0,0),(0,0,0,1/aa1))*
   liemat;
     al1:=0;be1:=cc1/(aa1*cc2);ga1:=1/aa1;
     al2:=cc2/aa1;be2:=1;ga2:=0>> else
    if (bb1=0 and aa1 neq bb2 and cc2 neq 0) then
     <<a1:=1/(bb2-aa1);b1:=(bb2*aa1-bb2*bb2+cc1)/(cc2*(aa1-bb2));
     liemat:=mat((1,0,0,0),(0,1,0,0),(a1,b1,1,0),(0,0,0,1/bb2))*liemat;
       al1:=(aa1-cc1*a1)/bb2;be1:=-b1*cc1/bb2;ga1:=cc1/bb2;
       al2:=-cc2*a1/bb2;be2:=1-b1*cc2/bb2;ga2:=cc2/bb2>>else
     if(bb1=0 and cc2=0) then
      <<liemat:=mat((1,0,0,0),(0,0,1,0),(0,1,0,0),(0,0,0,1/bb2))*liemat;
        al1:=aa1/bb2;be1:=cc1/bb2;al2:=1/bb2;ga1:=be2:=ga2:=0>>
     else
      <<r:=-aa1-bb2;s:=aa1*bb2-cc1;P:=s-r*r/3;
        q:=2*r*r*r/27-s*r/3+bb2*cc1-bb1*cc2;
        c1:=(-q/2+sqrt(q*q/4+P*P*P/27))**(1/3)+
            (-q/2-sqrt(q*q/4+P*P*P/27))**(1/3)-r/3;
        a1:=(c1-bb2)/bb1;b1:=(c1-bb2)*(c1-aa1)/bb1;
      liemat:=mat((1,0,0,0),(0,0,1,0),(a1,1,b1,0),(0,0,0,1/c1))*liemat;
        al1:=(aa1-a1*bb1)/c1;be1:=(cc1-b1*bb1)/c1;
        ga1:=bb1/c1;al2:=1/c1;be2:=ga2:=0>>>>;
 if ga2 neq 0 then
 <<liemat:=mat((1,-ga1/ga2,0,0),(0,1,0,0),(0,0,1,0),(0,0,0,1))*liemat;
   aa1:=al1-ga1*al2/ga2;bb1:=be1+al1*ga1/ga2-al2*ga1*ga1/
   (ga2*ga2)-ga1*be2/ga2;aa2:=al2;bb2:=be2+al2*ga1/ga2;cc2:=ga2>>
  else <<liemat:=mat((0,1,0,0),(1,0,0,0),(0,0,1,0),(0,0,0,1))*liemat;
         aa1:=be2;bb1:=al2;aa2:=be1;bb2:=al1;cc2:=ga1>>;
 if (aa2=0 and aa1-bb1-bb2=0 and -aa1-bb1+bb2=0 and cc2=0)
  then c0111(aa1,aa1) else
  <<if aa2=0 then
     if (aa1-bb1-bb2) neq 0 then
     <<liemat:=mat((1,0,0,0),(1,1,0,0),(0,0,1,0),(0,0,0,1))*liemat;
       aa2:=aa1-bb1-bb2;bb2:=bb1+bb2;aa1:=aa1-bb1>> else
      if (-aa1-bb1+bb2) neq 0 then
       <<liemat:=mat((1,0,0,0),(-1,1,0,0),(0,0,1,0),(0,0,0,1))*liemat;
         aa2:=-aa1-bb1+bb2;bb2:=bb2-bb1;aa1:=aa1+bb1>> else
      <<liemat:=mat((0,0,1,0),(0,1,0,0),(1,0,0,0),(0,0,0,1/aa1))*liemat;
          aa2:=cc2/aa1;bb2:=1;cc2:=0;aa1:=1/aa1>>;
    liemat:=mat((1,-aa1/aa2,aa1*cc2/aa2,0),(0,1,0,0),(0,0,1,0),
            (0,0,0,1))*liemat;
    be1:=bb1-aa1*bb2/aa2;
    al2:=aa2;be2:=aa1+bb2;ga2:=cc2-aa1*cc2;
    liemat:=mat((1,0,0,0),(-be2,be1,0,0),(0,0,1,0),(0,0,0,1))*liemat;
    aa1:=be2; aa2:=al2*be1;cc2:=ga2*be1;
    if (cc2 neq 0 and aa2=(1-aa1)) then
     <<liemat:=mat((1,0,0,0),(1,1,0,0),(0,0,cc2,0),(0,0,0,1))*liemat;
       al1:=aa1-1;
       if al1=1 then
        <<if symbolic !*tr_lie then
          write "[W,Z]=W+X, [X,Z]=X+Y, [Y,Z]=Y";
          lie_class:={liealg(4),comtab(12)}>>
        else <<liemat:=mat((0,0,1,0),(0,1,0,0),(1,1/(al1-1),
               1/((al1-1)*(al1-1)),0),(0,0,0,1/al1))*liemat;
        liemat:=mat((0,1,0,0),(1/al1,0,0,0),(0,0,1,0),(0,0,0,1))*liemat;
        if symbolic !*tr_lie then
        write "[W,Z]=",1/al1,"W+X, [X,Z]=",1/al1,"X, [Y,Z]=Y";
        lie_class:={liealg(4),comtab(15),1/al1}>>>> else
     <<if cc2 neq 0 then
       liemat:=mat((1,0,-cc2/(1-aa2-aa1),0),(0,1,(-1+aa1)*
               cc2/(1-aa2-aa1),0),(0,0,cc2/(1-aa2-aa1),0),
               (0,0,0,1))*liemat;
       liemat:=mat((1,0,0,0),(aa1/2,1,0,0),(0,0,1,0),(0,0,0,1))*liemat;
       r:=(aa1*aa1/4+aa2);
       if r=0 then
       <<if symbolic !*tr_lie then
         write "[W,Z]=",aa1/2,"W+X, [X,Z]=",aa1/2,"X, [Y,Z]=Y";
         lie_class:={liealg(4),comtab(15),aa1/2}>> else
        <<liemat:=mat((sqrt(abs(r)),0,0,0),(0,1,0,0),(0,0,1,0),
                  (0,0,0,1))*liemat;
          if not(numberp(r)) then
          <<write "Is ",r,"<0 ? (y/n) and press <RETURN>";
            he:=symbolic read();
            if he=y then
            <<liemat:=mat((1,0,0,0),(0,1,0,0),(0,0,1,0),
                     (0,0,0,sqrt(abs(1/r))))*liemat;
             s:=aa1/(2*sqrt(abs(r)));
             if symbolic !*tr_lie then
             write "[W,Z]=",s,"W+X, [X,Z]=-W+",s,"X, [Y,Z]=",
                   sqrt(abs(1/r)),"Y";
                   lie_class:={liealg(4),comtab(14),s,sqrt(abs(1/r))}>>
            else
          <<liemat:=mat((1,0,0,0),(1,1,0,0),(0,0,1,0),(0,0,0,1))*liemat;
              liemat:=mat((-2*sqrt(abs(r)),sqrt(abs(r)),0,0),
                      (0,sqrt(abs(r)),0,0),(0,0,1,0),(0,0,0,1))*liemat;
              <<c0111(aa1/2-sqrt(abs(r)),aa1/2+sqrt(abs(r)))>>>>>> else
          if r<0 then
           <<liemat:=mat((1,0,0,0),(0,1,0,0),(0,0,1,0),
                     (0,0,0,sqrt(abs(1/r))))*liemat;
             s:=aa1/(2*sqrt(abs(r)));
             if symbolic !*tr_lie then
             write "[W,Z]=",s,"W+X, [X,Z]=-W+",s,"X, [Y,Z]=",
                   sqrt(abs(1/r)),"Y";
                   lie_class:={liealg(4),comtab(14),s,sqrt(abs(1/r))}>>
            else
          <<liemat:=mat((1,0,0,0),(1,1,0,0),(0,0,1,0),(0,0,0,1))*liemat;
              liemat:=mat((-2*sqrt(abs(r)),sqrt(abs(r)),0,0),
                      (0,sqrt(abs(r)),0,0),(0,0,1,0),(0,0,0,1))*liemat;
              c0111(aa1/2-sqrt(abs(r)),aa1/2+sqrt(abs(r)))>>>>
     >>>>
 end;

algebraic procedure c0111(my,ny);
begin
 liemat:=mat((0,0,1,0),(1,0,0,0),(0,1,0,0),(0,0,0,1))*liemat;
 if symbolic !*tr_lie then
 write "[W,Z]=W, [X,Z]=",my,"X, [Y,Z]=",ny,"Y";
 lie_class:={liealg(4),comtab(13),my,ny}
end;

algebraic procedure comcom1();
begin integer ii;
      scalar he,a1,a2,a3,b2,b3,c2,c3,help;
      matrix a11(4,4),a22(4,4),a33(4,4),ccc(3,3);
 help:=0;
 for m:=1:3 do for n:=1:3 do
  if ff(m,n) neq 0 then <<ii:=m;m:=3;n:=3>>;
  a11:=mat((1,0,0,0),(0,1,0,0),(ff(ii,1),ff(ii,2),ff(ii,3),0),
           (0,0,0,1));
  a22:=mat((1,0,0,0),(0,0,1,0),(ff(ii,1),ff(ii,2),ff(ii,3),0),
           (0,0,0,1));
  a33:=mat((0,1,0,0),(0,0,1,0),(ff(ii,1),ff(ii,2),ff(ii,3),0),
           (0,0,0,1));
 if det(a11) neq 0 then liemat:=a11*liemat else
  if det(a22) neq 0 then liemat:=a22*liemat else liemat:=a33*liemat;
 liemat:=mat((0,0,1,0),(1,0,0,0),(0,1,0,0),(0,0,0,1))*liemat;
 a11:=1/liemat;
 for m:=1:3 do for n:=1:3 do
 ccc(m,n):=for i:=1:4 sum for j:=1:4 sum for k:=1:4 sum
  liemat(m,i)*liemat(4,j)*cc(i,j,k)*a11(k,n);
 a1:=ccc(1,1);a2:=ccc(2,1);a3:=ccc(3,1);b2:=ccc(2,2);
 b3:=ccc(3,2);c2:=ccc(2,3);c3:=ccc(3,3);
 if a1=0 then
  <<if c2=0 then
     if b3=0 then
      <<liemat:=mat((1,0,0,0),(0,1,1,0),(0,0,1,0),(0,0,0,1))*liemat;
        a2:=a2+a3;c2:=-2*b2>> else
      <<liemat:=mat((1,0,0,0),(0,1,b2/b3,0),(0,0,1,0),(0,0,0,1))*liemat;
        a2:=a2+a3*b2/b3;c2:=-3*b2*b2/b3;b2:=2*b2>>;
    help:=b2*b2+c2*b3;c3:=sqrt(abs(help));
    liemat:=mat((c2/c3,0,0,0),(0,1,0,0),(0,b2/c3,c2/c3,0),
            (0,a3*c3/help,-a2*c3/help,c3/help))*liemat;
    if symbolic !*tr_lie then
    write "[X,Y]=W, [X,Z]=",help/abs(help),"Y, [Y,Z]=X";
    if help>0 then lie_class:={liealg(4),comtab(19)} else
                   lie_class:={liealg(4),comtab(20)}>> else
  <<liemat:=mat((1,0,0,0),(0,1,0,0),(0,0,1,0),
            (0,2*a3/a1,-2*a2/a1,2/a1))*liemat;
    b2:=2*b2/a1;c2:=2*c2/a1;b3:=2*b3/a1;c3:=2*c3/a1;
    if b3 neq 0 then
  <<liemat:=mat((1,0,0,0),(0,1,(1-b2)/b3,0),(0,0,1,0),(0,0,0,1))*liemat;
      c2:=c2+(1-b2)*(c3-1)/b3;b2:=c3:=1;
      if c2=0 then
       <<liemat:=mat((-1,0,0,0),(0,0,1,0),(0,1,0,0),(0,0,0,1))*liemat;
         c2:=b3>> else
       <<a1:=b3/abs(b3);a2:=c2/abs(c2);a3:=sqrt(abs(b3*c2));
         liemat:=mat((1,0,0,0),(0,(abs(b3/c2))**(1/4),0,0),
                 (0,0,(abs(c2/b3))**(1/4),0),(0,0,0,1))*liemat;
         if a1=a2 then
          <<if not(numberp(a1)) then
            <<write "Is ",a1,"<0 ? (y/n) and press <RETURN>";
              he:=symbolic read();
              if he=y then a3:=-a3>> else
            if a1<0 then a3:=-a3;
            liemat:=mat((1,0,0,0),(0,1,0,0),(0,1,1,0),(0,0,0,1))*liemat;
            b2:=1-a3;c2:=a3;c3:=a3+1>> else
          <<help:=1;
            if not(numberp(a1)) then
            <<write "Is ",a1,"<0 ? (y/n) and press <RETURN>";
              he:=symbolic read();
              if he=y then
              liemat:=mat((-1,0,0,0),(0,0,1,0),(0,1,0,0),(0,0,0,1))*
              liemat>> else
            if a1<0 then
            liemat:=mat((-1,0,0,0),(0,0,1,0),(0,1,0,0),(0,0,0,1))
                       *liemat;
            if symbolic !*tr_lie then
            write "[W,Z]=2W, [X,Y]=W, [X,Z]=X-",a3,"Y, ",
           "[Y,Z]=",a3,"X+Y";lie_class:={liealg(4),comtab(17),a3}>>>>>>;
    if (help neq 1) then
     if (c2=0 OR b2 neq c3) then
     <<if (b2 neq c3) then
      liemat:=mat((1,0,0,0),(0,1,c2/(b2-c3),0),(0,0,1,0),(0,0,0,1))*
      liemat;
      if not(numberp(b2)) then
            <<write "Is ",b2,"<1 ? (y/n) and press <RETURN>";
              he:=symbolic read();
              if he=y then
          liemat:=mat((-1,0,0,0),(0,0,1,0),(0,1,0,0),(0,0,0,1))*liemat;
              help:=b2;b2:=c3;c3:=help>> else
      if b2<1 then
        <<liemat:=mat((-1,0,0,0),(0,0,1,0),(0,1,0,0),(0,0,0,1))*liemat;
          help:=b2;b2:=c3;c3:=help>>;
        if symbolic !*tr_lie then
        write "[W,Z]=2W, [X,Y]=W, [X,Z]=",b2,"X, [Y,Z]=",c3,"Y";
        lie_class:={liealg(4),comtab(16),b2-1}>> else
      <<liemat:=mat((1,0,0,0),(0,1/sqrt(abs(c2)),0,0),
                (0,0,sqrt(abs(c2)),0),(0,0,0,1))*liemat;
        if not(numberp(c2)) then
            <<write "Is ",c2,"<0 ? (y/n) and press <RETURN>";
              he:=symbolic read();
              if he=y then
              liemat:=mat((-1,0,0,0),(0,1,0,0),(0,0,-1,0),(0,0,0,1))*
              liemat>> else
        if c2<0 then
         liemat:=mat((-1,0,0,0),(0,1,0,0),(0,0,-1,0),(0,0,0,1))*liemat;
        if symbolic !*tr_lie then
        write "[W,Z]=2W, [X,Y]=W, [X,Z]=X+Y, [Y,Z]=Y";
        lie_class:={liealg(4),comtab(18)}>>>>;
 clear a11,a22,a33,ccc
end;

algebraic procedure comcom3();
begin integer help;
      scalar he,al,be,ga;
      matrix l_k(3,3),l_a(3,3);
 help:=0;
 l_k(1,1):=ff(1,2)**2+2*ff(1,3)*ff(2,2)+ff(2,3)**2;
 l_k(1,2):=-ff(1,1)*ff(1,2)+ff(1,3)*ff(3,2)-
          ff(2,1)*ff(1,3)+ff(2,3)*ff(3,3);
 l_k(1,3):=-ff(1,1)*ff(2,2)-ff(1,2)*ff(3,2)-
          ff(2,1)*ff(2,3)-ff(2,2)*ff(3,3);
 l_k(2,1):=l_k(1,2);
 l_k(2,2):=ff(1,1)**2-2*ff(1,3)*ff(3,1)+ff(3,3)**2;
 l_k(2,3):=ff(1,1)*ff(2,1)+ff(1,2)*ff(3,1)-
         ff(3,1)*ff(2,3)-ff(3,2)*ff(3,3);
 l_k(3,1):=l_k(1,3);l_k(3,2):=l_k(2,3);
 l_k(3,3):=ff(2,1)**2+2*ff(2,2)*ff(3,1)+ff(3,2)**2;
 if not(numberp(l_k(1,1)) and
  numberp(l_k(1,1)*l_k(2,2)-l_k(1,2)*l_k(2,1)) and
        numberp(det(l_k))) then
 <<write "Is ",-l_k(1,1),">0 and ",
      l_k(1,1)*l_k(2,2)-l_k(1,2)*l_k(2,1),">0 and ",
     -det(l_k),">0 ? (y/n) and press <RETURN>";
   he:=symbolic read();
   if he=y then <<help:=1;lie4so3()>> else lie4so21()>> else
 if (-l_k(1,1)>0 and l_k(1,1)*l_k(2,2)-l_k(1,2)*l_k(2,1)>0 and
     -det(l_k)>0) then
  <<help:=1;lie4so3()>> else lie4so21();
 liemat:=mat((l_a(1,1),l_a(1,2),l_a(1,3),0),(l_a(2,1),l_a(2,2),
          l_a(2,3),0), (l_a(3,1),l_a(3,2),l_a(3,3),0),(0,0,0,1))*liemat;
 bb:=1/liemat;
 al:=for j:=1:4 sum for k:=1:4 sum for l:=1:4 sum
         liemat(1,j)*liemat(4,k)*cc(j,k,l)*bb(l,2);
 be:=for j:=1:4 sum for k:=1:4 sum for l:=1:4 sum
         liemat(1,j)*liemat(4,k)*cc(j,k,l)*bb(l,3);
 ga:=for j:=1:4 sum for k:=1:4 sum for l:=1:4 sum
         liemat(2,j)*liemat(4,k)*cc(j,k,l)*bb(l,3);
 if help=1 then
  liemat:=mat((1,0,0,0),(0,1,0,0),(0,0,1,0),(ga,-be,al,1))*liemat else
  liemat:=mat((1,0,0,0),(0,1,0,0),(0,0,1,0),(ga,-be,-al,1))*liemat;
 if help=1 then
  <<if symbolic !*tr_lie then
    write "[W,X]=Y, [W,Y]=-X, [X,Y]=W";
    lie_class:={liealg(4),comtab(21)}>> else
  <<if symbolic !*tr_lie then
    write "[W,X]=Y, [W,Y]=X, [X,Y]=W";
    lie_class:={liealg(4),comtab(22)}>>;
 clear l_k,l_a
end;

algebraic procedure lie4so3();
begin scalar s,tt,q,r,alpha;
 s:=ff(2,2)/abs(ff(2,2));
 tt:=abs(ff(1,2)**2+ff(1,3)*ff(2,2));
 r:=ff(1,1)-ff(1,2)*ff(2,1)/ff(2,2);
 alpha:=tt*(-r*r-((ff(2,1)/ff(2,2))**2+ff(3,1)/ff(2,2))*tt);
 q:=1/sqrt(alpha);
 l_a(1,1):=1/(s*sqrt(tt));l_a(1,2):=l_a(1,3):=l_a(2,2):=0;l_a(2,1):=q*r;
 l_a(2,3):=-q*tt/ff(2,2);l_a(3,1):=-q*s*sqrt(tt)*ff(2,1)/ff(2,2);
 l_a(3,2):=-q*s*sqrt(tt);l_a(3,3):=q*s*sqrt(tt)*ff(1,2)/ff(2,2)
end;

algebraic procedure lie4so21();
begin scalar gam,eps,s,tt,q,r,alpha;
      matrix l_g(3,3);
 l_a:=mat((1,0,0),(0,1,0),(0,0,1));
 if ff(2,2)=0 then
  if ff(1,3) neq 0 then <<l_a:=mat((1,0,0),(0,0,1),(0,1,0));
   l_g(1,1):=ff(2,1);l_g(1,2):=ff(2,3);l_g(1,3):=ff(2,2);
   l_g(2,1):=ff(1,1);l_g(2,2):=ff(1,3);l_g(2,3):=ff(1,2);
   l_g(3,1):=-ff(3,1);l_g(3,2):=-ff(3,3);l_g(3,3):=-ff(3,2);ff:=l_g>>
    else
   if ff(3,1) neq 0 then <<l_a:=mat((0,1,0),(1,0,0),(0,0,1));
    l_g(1,1):=-ff(1,2);l_g(1,2):=-ff(1,1);l_g(1,3):=-ff(1,3);
    l_g(2,1):=ff(3,2);l_g(2,2):=ff(3,1);l_g(2,3):=ff(3,3);
    l_g(3,1):=ff(2,2);l_g(3,2):=ff(2,1);l_g(3,3):=ff(2,3);ff:=l_g>> else
                         <<l_a:=mat((1,0,1),(1,0,0),(0,1,0));
    l_g(1,1):=-ff(2,3);l_g(1,2):=ff(2,3)-ff(2,1);l_g(1,3):=0;
    l_g(2,1):=-ff(3,3);l_g(2,2):=2*ff(1,1);l_g(2,3):=ff(1,2)-ff(3,2);
    l_g(3,1):=0;l_g(3,2):=ff(1,1);l_g(3,3):=ff(1,2);ff:=l_g>>;
 if ff(1,2)**2+ff(1,3)*ff(2,2)=0 then
  <<gam:=-ff(1,2)/ff(2,2);eps:=ff(1,1)-ff(1,2)*ff(2,1)/ff(2,2);
  if 1/4*(ff(3,2)**2+ff(3,1)*ff(2,2))-eps*ff(2,2)/2=0 then
   <<l_a:=mat((0,0,1),(0,2/eps,2*gam/eps),(1,0,0))*l_a;
   l_g(1,1):=2*gam*ff(3,2)/eps-ff(3,3);
   l_g(1,2):=-ff(3,2);l_g(1,3):=-2*ff(3,1)/eps;
   l_g(2,1):=0;l_g(2,2):=-eps*ff(2,2)/2;l_g(2,3):=-ff(2,1);
   l_g(3,1):=l_g(3,2):=0;l_g(3,3):=-2;ff:=l_g>> else
   <<l_a:=mat((1/2,0,1/2),(0,1/eps,gam/eps),(-1/2,0,1/2))*l_a;
   l_g(1,1):=-ff(3,1)/(2*eps);l_g(1,2):=-ff(3,2)/2;
   l_g(1,3):=ff(3,1)/(2*eps)-1;
   l_g(2,1):=ff(2,1)/2;l_g(2,2):=ff(2,2)*eps/2;
   l_g(2,3):=-ff(2,1)/2;l_g(3,1):=ff(3,1)/(2*eps)+1;
   l_g(3,2):=ff(3,2)/2;l_g(3,3):=-ff(3,1)/(2*eps);ff:=l_g>>>>;
 if not(numberp(ff(1,2)**2+ff(1,3)*ff(2,2))) then
 <<write "Is ",ff(1,2)**2+ff(1,3)*ff(2,2),
         "<0 ? (y/n) and press <RETURN>";
   he:=symbolic read();
   if he=y then
   <<s:=ff(2,2)/abs(ff(2,2));
  tt:=abs(ff(1,2)**2+ff(1,3)*ff(2,2));
  r:=ff(1,1)-ff(1,2)*ff(2,1)/ff(2,2);
  alpha:=tt*(-r*r-((ff(2,1)/ff(2,2))**2+ff(3,1)/ff(2,2))*tt);
  q:=1/sqrt(abs(alpha));
  l_g(1,1):=-q*s*sqrt(tt)*ff(2,1)/ff(2,2);
  l_g(1,2):=-q*s*sqrt(tt);l_g(1,3):=q*s*sqrt(tt)*ff(1,2)/ff(2,2);
  l_g(2,1):=1/(s*sqrt(tt));l_g(2,2):=l_g(2,3):=0;
  l_g(3,1):=q*r;l_g(3,2):=0;l_g(3,3):=-q*tt/ff(2,2);l_a:=l_g*l_a>> else
  <<s:=ff(2,2)/abs(ff(2,2));
  tt:=ff(1,2)**2+ff(1,3)*ff(2,2);
  r:=ff(1,1)-ff(1,2)*ff(2,1)/ff(2,2);
  alpha:=tt*(r*r-((ff(2,1)/ff(2,2))**2+ff(3,1)/ff(2,2))*tt);
  q:=1/sqrt(abs(alpha));
  if not(numberp(alpha)) then
  <<write "Is ",alpha,">0 ? (y/n) and press <RETURN>";
    he:=symbolic read();
    if he =y then
    <<l_g(1,1):=1/(s*sqrt(tt));l_g(1,2):=l_g(1,3):=0;
   l_g(2,1):=q*r;l_g(2,2):=0;l_g(2,3):=q*tt/ff(2,2);
   l_g(3,1):=q*s*sqrt(tt)*ff(2,1)/ff(2,2);l_g(3,2):=q*s*sqrt(tt);
   l_g(3,3):=-q*s*sqrt(tt)*ff(1,2)/ff(2,2);l_a:=l_g*l_a>> else
   <<l_g(1,1):=1/(s*sqrt(tt));l_g(1,2):=l_g(1,3):=0;
   l_g(2,1):=q*s*sqrt(tt)*ff(2,1)/ff(2,2);l_g(2,2):=q*s*sqrt(tt);
   l_g(2,3):=-q*s*sqrt(tt)*ff(1,2)/ff(2,2);
   l_g(3,1):=q*r;l_g(3,2):=0;l_g(3,3):=q*tt/ff(2,2);
   l_a:=l_g*l_a>>>> else
  if alpha>0 then
   <<l_g(1,1):=1/(s*sqrt(tt));l_g(1,2):=l_g(1,3):=0;
   l_g(2,1):=q*r;l_g(2,2):=0;l_g(2,3):=q*tt/ff(2,2);
   l_g(3,1):=q*s*sqrt(tt)*ff(2,1)/ff(2,2);l_g(3,2):=q*s*sqrt(tt);
   l_g(3,3):=-q*s*sqrt(tt)*ff(1,2)/ff(2,2);l_a:=l_g*l_a>> else
   <<l_g(1,1):=1/(s*sqrt(tt));l_g(1,2):=l_g(1,3):=0;
   l_g(2,1):=q*s*sqrt(tt)*ff(2,1)/ff(2,2);l_g(2,2):=q*s*sqrt(tt);
   l_g(2,3):=-q*s*sqrt(tt)*ff(1,2)/ff(2,2);
   l_g(3,1):=q*r;l_g(3,2):=0;l_g(3,3):=q*tt/ff(2,2);l_a:=l_g*l_a>>
>>>> else
 if ff(1,2)**2+ff(1,3)*ff(2,2)<0 then
  <<s:=ff(2,2)/abs(ff(2,2));
  tt:=abs(ff(1,2)**2+ff(1,3)*ff(2,2));
  r:=ff(1,1)-ff(1,2)*ff(2,1)/ff(2,2);
  alpha:=tt*(-r*r-((ff(2,1)/ff(2,2))**2+ff(3,1)/ff(2,2))*tt);
  q:=1/sqrt(abs(alpha));
  l_g(1,1):=-q*s*sqrt(tt)*ff(2,1)/ff(2,2);
  l_g(1,2):=-q*s*sqrt(tt);l_g(1,3):=q*s*sqrt(tt)*ff(1,2)/ff(2,2);
  l_g(2,1):=1/(s*sqrt(tt));l_g(2,2):=l_g(2,3):=0;
  l_g(3,1):=q*r;l_g(3,2):=0;l_g(3,3):=-q*tt/ff(2,2);
  l_a:=l_g*l_a>> else
  <<s:=ff(2,2)/abs(ff(2,2));
  tt:=ff(1,2)**2+ff(1,3)*ff(2,2);
  r:=ff(1,1)-ff(1,2)*ff(2,1)/ff(2,2);
  alpha:=tt*(r*r-((ff(2,1)/ff(2,2))**2+ff(3,1)/ff(2,2))*tt);
  q:=1/sqrt(abs(alpha));
  if not(numberp(alpha)) then
  <<write "Is ",alpha,">0 ? (y/n) and press <RETURN>";
    he:=symbolic read();
    if he =y then
    <<l_g(1,1):=1/(s*sqrt(tt));l_g(1,2):=l_g(1,3):=0;
   l_g(2,1):=q*r;l_g(2,2):=0;l_g(2,3):=q*tt/ff(2,2);
   l_g(3,1):=q*s*sqrt(tt)*ff(2,1)/ff(2,2);l_g(3,2):=q*s*sqrt(tt);
   l_g(3,3):=-q*s*sqrt(tt)*ff(1,2)/ff(2,2);l_a:=l_g*l_a>> else
   <<l_g(1,1):=1/(s*sqrt(tt));l_g(1,2):=l_g(1,3):=0;
   l_g(2,1):=q*s*sqrt(tt)*ff(2,1)/ff(2,2);l_g(2,2):=q*s*sqrt(tt);
   l_g(2,3):=-q*s*sqrt(tt)*ff(1,2)/ff(2,2);
   l_g(3,1):=q*r;l_g(3,2):=0;l_g(3,3):=q*tt/ff(2,2);
   l_a:=l_g*l_a>>>> else
  if alpha>0 then
   <<l_g(1,1):=1/(s*sqrt(tt));l_g(1,2):=l_g(1,3):=0;
   l_g(2,1):=q*r;l_g(2,2):=0;l_g(2,3):=q*tt/ff(2,2);
   l_g(3,1):=q*s*sqrt(tt)*ff(2,1)/ff(2,2);l_g(3,2):=q*s*sqrt(tt);
   l_g(3,3):=-q*s*sqrt(tt)*ff(1,2)/ff(2,2);l_a:=l_g*l_a>> else
   <<l_g(1,1):=1/(s*sqrt(tt));l_g(1,2):=l_g(1,3):=0;
   l_g(2,1):=q*s*sqrt(tt)*ff(2,1)/ff(2,2);l_g(2,2):=q*s*sqrt(tt);
   l_g(2,3):=-q*s*sqrt(tt)*ff(1,2)/ff(2,2);
   l_g(3,1):=q*r;l_g(3,2):=0;l_g(3,3):=q*tt/ff(2,2);l_a:=l_g*l_a>>>>;
 clear l_g
end;

endmodule;

end;

