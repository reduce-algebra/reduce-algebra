module orthovec;  % 3-D vector calculus package.

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


create!-package('(orthovec),'(contrib avector));

%          %========================================%
%          %              ORTHOVEC                  %
%          %========================================%
%          %     A 3-D VECTOR CALCULUS PACKAGE      %
%          %     USING ORTHOGONAL CURVILINEAR       %
%          %            COORDINATES                 %
%          %                                        %
%          %   copyright James W Eastwood,          %
%          %             Culham Laboratory,         %
%          %             Abingdon, Oxon.            %
%          %                                        %
%          %             February 1987              %
%          %                                        %
%          %   This new version differs from the    %
%          %   original version published in CPC,   %
%          %   47(1987)139-147 in the following     %
%          %   respects:                            %
%          %                                        %
%          %   *.+.,etc replaced by +,-,*,/         %
%          %   *unary vector +,-,/ introduced       %
%          %   *vector component selector _         %
%          %   *general tidy up                     %
%          %   *L'Hopitals rule in Taylor series    %
%          %   *extended division definition        %
%          %   *algebraic output of lisp vectors    %
%          %   *exponentiation of vectors           %
%          %   *vector extension of depend          %
%          %                                        %
%          %            Version 2                   %
%          %        All rights reserved             %
%          %     copyright James W Eastwood         %
%          %             June 1990                  %
%          %                                        %
%          %   This is a preliminary version of     %
%          %   the NEW VERSION of ORTHOVEC which    %
%          %   will be available from the Computer  %
%          %   Physics Communications Program       %
%          %   Library, Dept. of Applied Maths and  %
%          %   Theoretical Physics, The Queen's     %
%          %   University of Belfast, Belfast       %
%          %   BT7 1NN, Northern Ireland.           %
%          %   See any copy of CPC for further      %
%          %   details of the library services.     %
%          %                                        %
%          %========================================%
%          %       REDUCE 3.4 is assumed            %
%          %========================================%
%
%
%
%-------------------------------------------------------------------
%                       INITIALISATION
%%

algebraic;

%select coordinate system
%========================
procedure vstart0;
begin scalar ctype;
write "Select Coordinate System by number";
write "1] cartesian";
write "2] cylindrical";
write "3] spherical";
write "4] general";
write "5] others";
%remove previous settings
clear u1,u2,u3,h1,h2,h3;
depend h1,u1,u2,u3;
depend h2,u1,u2,u3;
depend h3,u1,u2,u3;
nodepend h1,u1,u2,u3;
nodepend h2,u1,u2,u3;
nodepend h3,u1,u2,u3;
%select coordinate system
ctype := symbolic read();
if ctype=1 then
 << u1:=x;u2:=y;u3:=z;h1:=1;h2:=1;h3:=1 >>
 else if ctype=2 then
  << u1:=r;u2:=th;u3:=z;h1:=1;h2:=r;h3:=1 >>
  else if ctype=3 then
   << u1:=r;u2:=th;u3:=ph;h1:=1;h2:=r;h3:=r*sin(th) >>
   else if ctype=4 then
    << depend h1,u1,u2,u3;depend h2,u1,u2,u3;depend h3,u1,u2,u3 >>
    else << write "To define another coordinate system, give values ";
    write "to components u1,u2,u3 and give functional form or";
    write "DEPEND for scale factors h1,h2 and h3. For example,";
write "to set up paraboloidal coords u,v,w type in:-";
write "u1:=u;u2:=v;u3:=w;h1:=sqrt(u**2+v**2);h2:=h1;h3:=u*v;">>;
write "coordinate type = ",ctype;
write "coordinates = ",u1,",",u2,",",u3;
write "scale factors = ",h1,",",h2,",",h3;
return
end$
let vstart=vstart0()$

%give access to lisp vector procedures
%=======================================
symbolic operator putv,getv,mkvect;
flag('(vectorp), 'direct);
flag('(vectorp), 'boolean);

%-------------------------------------------------------------------
%                      INPUT-OUTPUT
%
%set a new vector
%===================
procedure svec(c1,c2,c3);
begin scalar a;a:=mkvect(2);
putv(a,0,c1);putv(a,1,c2);putv(a,2,c3);
return a
end$

%output a vector
%===============
procedure vout(v);
begin;
if vectorp(v) then
  for j:=0:2 do write "[",j+1,"] ",getv(v,j)
  else write v;
return v
end$

%-------------------------------------------------------------------
%               REDEFINITION OF SOME STANDARD PROCEDURES
%
% Vector extension of standard definitions of depend and nodepend.

remflag('(depend nodepend),'lose);   % We must use these definitions.

symbolic procedure depend u;
begin scalar v,w; v:= !*a2k car u;
for each x in cdr u do
if vectorp(v) then
 for ic:=0:upbv(v) do
 <<if atom(w:=getv(v,ic)) and not numberp(w) then depend1(w,x,t)>>
 else depend1(car u,x,t)
end$

symbolic procedure nodepend u;
begin scalar v,w;
rmsubs();
v:= !*a2k car u;
for each x in cdr u do
if vectorp(v) then
 for ic:=0:upbv(v) do
 <<if atom(w:=getv(v,ic)) and not numberp(w) then depend1(w,x,nil)>>
 else depend1(car u,x,nil)
end $

%
%-------------------------------------------------------------------
%                      ALGEBRAIC OPERATIONS
%
%define symbols for vector algebra
%=====================================
newtok '(( !+ ) vectoradd);
newtok '(( !- ) vectordifference);
newtok '((!> !< ) vectorcross);
newtok '(( !* ) vectortimes);
newtok '(( !/ ) vectorquotient);
newtok '(( !_ ) vectorcomponent);
newtok '(( !^ ) vectorexpt);
%
%define operators
%================
operator vectorminus,vectorplus,vectorrecip;
infix vectoradd,vectordifference,vectorcross,vectorexpt,
      vectorcomponent,vectortimes,vectorquotient,dotgrad;
precedence vectoradd,<;
precedence vectordifference,vectoradd;
precedence dotgrad,vectordifference;
precedence vectortimes,dotgrad;
precedence vectorcross,vectortimes;
precedence vectorquotient,vectorcross;
precedence vectorexpt,vectorquotient;
precedence vectorcomponent,vectorexpt;

deflist( '(
   (vectordifference vectorminus)
   (vectoradd vectorplus)
   (vectorquotient vectorrecip)
   (vectorrecip vectorrecip)
 ), 'unary)$

deflist('((vectorminus vectorplus) (vectorrecip vectortimes)),
                 'alt)$

%extract component of a vector
%=============================
procedure vectorcomponent(v,ic);
if vectorp(v) then
  if ic=1 or ic=2 or ic=3 then getv(v,ic-1)
    else rerror(orthovec,1,"Incorrect component number")
  else rerror(orthovec,2,"Not a vector")$

%
%add vector or scalar pair v1 and v2
%===================================
procedure vectoradd(v1,v2);
begin scalar v3;
if vectorp(v1) and vectorp(v2) then
  <<v3:=mkvect(2);
  for ic:=0:2 do putv(v3,ic,plus(getv(v1,ic),getv(v2,ic)))>>
  else
  if not(vectorp(v1)) and not(vectorp(v2)) then v3:=plus(v1, v2)
     else rerror(orthovec,3,"Incorrect args to vector add");
return v3
end$

%unary plus
%==========
procedure vectorplus(v);v$
%
%negate vector or scalar v
%=========================
procedure vectorminus(v);
begin scalar v3;
if vectorp(v) then
  <<v3:=mkvect(2);
  for ic:=0:2 do putv(v3,ic,minus(getv(v,ic)))>>
  else v3:=minus(v);
return v3
end$

%scalar or vector subtraction
%============================
procedure vectordifference(v1,v2);(v1 + vectorminus(v2))$

%dot product or scalar times
%===========================
procedure vectortimes(v1,v2);
begin scalar v3;
if vectorp(v1) and vectorp(v2) then
  v3:= for ic:=0:2 sum times(getv(v1,ic),getv(v2,ic))
  else
  if not(vectorp(v1)) and not(vectorp(v2)) then
    v3:=times(v1 , v2 )
    else if vectorp(v1) and not(vectorp(v2)) then
      <<v3:=mkvect(2);
      for ic:=0:2 do putv(v3,ic,times(getv(v1,ic),v2)) >>
      else
      <<v3:=mkvect(2);
      for ic:=0:2 do putv(v3,ic,times(getv(v2,ic),v1)) >>;
return v3
end$

%vector cross product
%====================
procedure vectorcross(v1,v2);
begin scalar v3;
if vectorp(v1) and vectorp(v2) then
  <<v3:=mkvect(2);
  putv(v3,0,getv(v1,1)*getv(v2,2)-getv(v1,2)*getv(v2,1));
  putv(v3,1,getv(v1,2)*getv(v2,0)-getv(v1,0)*getv(v2,2));
  putv(v3,2,getv(v1,0)*getv(v2,1)-getv(v1,1)*getv(v2,0))>>
  else rerror(orthovec,4,"Incorrect args to vector cross product");
return v3
end$

%vector division
%===============
procedure vectorquotient(v1,v2);
if vectorp(v1) then
 if vectorp(v2) then
  quotient (v1*v2,v2*v2)
  else v1*recip(v2)
 else if vectorp(v2) then
  v1*v2*recip(v2*v2)
  else quotient(v1,v2)$

procedure vectorrecip(v);
if vectorp(v) then
 v*recip(v*v)
 else recip(v)$

%length of vector
%================
procedure vmod(v);sqrt(v * v)$

%vector exponentiation
%=====================
procedure vectorexpt(v,n);
if vectorp(v) then expt(vmod(v),n) else expt(v,n)$

%-------------------------------------------------------------------
%                      DIFFERENTIAL OPERATIONS
%

%div
%===
procedure div(v);
if vectorp(v) then
  (df(h2*h3*getv(v,0),u1)+df(h3*h1*getv(v,1),u2)
    +df(h1*h2*getv(v,2),u3))/h1/h2/h3
  else rerror(orthovec,5,"Incorrect arguments to div")$

%grad
%====
procedure grad(s);
begin scalar v;
v:=mkvect(2);
if vectorp(s) then
  rerror(orthovec,6,"Incorrect argument to grad")
  else << putv(v,0,df(s,u1)/h1);
          putv(v,1,df(s,u2)/h2);
          putv(v,2,df(s,u3)/h3) >>;
return v
end$

%curl
%====
procedure curl(v);
begin scalar v1;
v1:=mkvect(2);
if vectorp(v) then
  << putv(v1,0,(df(h3*getv(v,2),u2)-df(h2*getv(v,1),u3))/h2/h3);
     putv(v1,1,(df(h1*getv(v,0),u3)-df(h3*getv(v,2),u1))/h3/h1);
     putv(v1,2,(df(h2*getv(v,1),u1)-df(h1*getv(v,0),u2))/h1/h2) >>
  else rerror(orthovec,7,"Incorrect argument to curl");
return v1
end$

%laplacian
%=========
procedure delsq(v);
if vectorp(v) then (grad(div(v)) - curl(curl(v))) else div(grad(v))$

%differentiation
%===============
procedure vdf(v,x);
begin scalar v1;
if vectorp(x) then
  rerror(orthovec,8,"Second argument to VDF must be scalar")
  else if vectorp(v) then
    <<v1:=mkvect(2);for ic:=0:2 do putv(v1,ic,vdf(getv(v,ic),x)) >>
    else v1:=df(v,x);
return v1
end$

%v1.grad(v2)
%===========
procedure dotgrad(v1,v2);
if vectorp(v1) then
  if vectorp(v2) then
    (1/2)*(grad(v1 * v2) + v1 * div(v2)  - div(v1) * v2
          - (curl(v1 >< v2) + v1 >< curl(v2) - curl(v1) >< v2 ))
    else v1 * grad(v2)
  else rerror(orthovec,9,"Incorrect arguments to dotgrad")$

%3-D Vector Taylor Expansion about vector point
%==============================================
procedure vtaylor(vex,vx,vpt,vorder);
%note: expression vex, variable vx, point vpt and order vorder
%      are any legal mixture of vectors and scalars
begin scalar vseries;
if vectorp(vex) then
  <<vseries:=mkvect(2);
  for ic:=0:2 do putv(vseries,ic,vptaylor(getv(vex,ic),vx,vpt,vorder))>>
  else vseries:=vptaylor(vex,vx,vpt,vorder);
return vseries
end$

%Scalar Taylor expansion about vector point
%==========================================
procedure vptaylor(sex,vx,vpt,vorder);
%vector variable
if vectorp(vx) then
  if vectorp(vpt) then
%vector order
    if vectorp(vorder) then
      taylor( taylor( taylor( sex,
      getv(vx,0), getv(vpt,0), getv(vorder,0) ),
      getv(vx,1), getv(vpt,1), getv(vorder,1) ),
      getv(vx,2), getv(vpt,2), getv(vorder,2) )
      else
      taylor( taylor( taylor( sex,
      getv(vx,0), getv(vpt,0), vorder),
      getv(vx,1), getv(vpt,1), vorder),
      getv(vx,2), getv(vpt,2), vorder)
    else rerror(orthovec,10,"VTAYLOR: vector VX mismatches scalar VPT")
%scalar variable
  else if vectorp(vpt) then
    rerror(orthovec,11,"VTAYLOR: scalar VX mismatches vector VPT")
    else if vectorp(vorder) then
      rerror(orthovec,12,"VTAYLOR: scalar VX mismatches vector VORDER")
      else taylor(sex,vx,vpt,vorder)$

%Scalar Taylor expansion of ex wrt x about point pt to order n
%=============================================================
procedure taylor(ex,x,pt,n);
begin scalar term,series,dx,mfac;
if numberp n then <<
  mfac:=1;dx:=x-pt;term:=ex;
  series:= limit(ex,x,pt) +
  for k:=1:n sum limit((term:=df(term,x)),x,pt)*(mfac:=mfac*dx/k) >>
  else rerror(orthovec,13,
              "Truncation orders of Taylor series must be integers");
return series
end$
%
%limiting value of exression ex as x tends to pt
%===============================================
procedure limit(ex,x,pt);
begin scalar lim,denex,numex;
%polynomial
lim:=if (denex:=den(ex))=1 then sub(x=pt,ex)
 else
%zero denom rational
 if sub(x=pt,denex)=0 then
%l'hopital's rule
  << if sub(x=pt,(numex:=num(ex)))=0 then
   limit(df(numex,x)/df(denex,x),x,pt)
%singular
   else rerror(orthovec,14,"Singular coefficient found by LIMIT")>>
%nonzero denom rational
  else sub(x=pt,ex);
return lim
end$
%
%-------------------------------------------------------------------
%                      INTEGRAL OPERATIONS
%
% Vector Integral
%================
procedure vint(v,x);
begin scalar v1;
if vectorp(x) then
  rerror(orthovec,15,"Second argument to VINT must be scalar")
  else if vectorp(v) then
    <<v1:=mkvect(2);for ic:=0:2 do putv(v1,ic,int(getv(v,ic),x)) >>
    else v1:=int(v,x);
return v1
end$

%Definite Vector Integral
%========================
procedure dvint(v,x,xlb,xub);
begin scalar integr,intval;
if vectorp(xlb) or vectorp(xub)
  then rerror(orthovec,16,"Limits to DVINT must be scalar")
  else if vectorp(v) then
    <<intval:=mkvect(2);
    for ic:=0:2 do <<integr:=int(getv(v,ic),x);
    putv(intval,ic,sub(x=xub,integr)-sub(x=xlb,integr)) >> >>
    else
    <<integr:=int(v,x);intval:=sub(x=xub,integr)-sub(x=xlb,integr)>>;
return intval
end$

%Volume Integral
%===============
procedure volint(v);
begin scalar v1;
if vectorp(v) then
  <<v1:=mkvect(2);for ic:=0:2 do putv(v1,ic,volint(getv(v,ic))) >>
  else v1:= int( int( int(v*h1*h2*h3,u1),u2),u3);
return v1
end$

%Definite Volume Integral
%========================
procedure dvolint(v,vlb,vub,n);
begin scalar v1,intgrnd;
if vectorp(vlb) and vectorp(vub) then
  <<intgrnd:= (h1*h2*h3) * v;
  v1:= if n=1 then
    dvint(dvint(dvint(intgrnd,
    u1,getv(vlb,0),getv(vub,0)),
    u2,getv(vlb,1),getv(vub,1)),
    u3,getv(vlb,2),getv(vub,2) )
      else if n=2 then
      dvint(dvint(dvint(intgrnd,
      u3,getv(vlb,2),getv(vub,2)),
      u1,getv(vlb,0),getv(vub,0)),
      u2,getv(vlb,1),getv(vub,1) )
        else if n=3 then
        dvint(dvint(dvint(intgrnd,
        u2,getv(vlb,1),getv(vub,1)),
        u3,getv(vlb,2),getv(vub,2)),
        u1,getv(vlb,0),getv(vub,0) )
          else if n=4 then
          dvint(dvint(dvint(intgrnd,
          u1,getv(vlb,0),getv(vub,0)),
          u3,getv(vlb,2),getv(vub,2)),
          u2,getv(vlb,1),getv(vub,1) )
            else if n=5 then
            dvint(dvint(dvint(intgrnd,
            u2,getv(vlb,1),getv(vub,1)),
            u1,getv(vlb,0),getv(vub,0)),
            u3,getv(vlb,2),getv(vub,2) )
              else
              dvint(dvint(dvint(intgrnd,
              u3,getv(vlb,2),getv(vub,2)),
              u2,getv(vlb,1),getv(vub,1)),
              u1,getv(vlb,0),getv(vub,0)) >>
  else rerror(orthovec,17,"Bounds to DVOLINT must be vectors");
return v1
end$

%Scalar Line Integral
%====================
procedure lineint(v,vline,tt);
if vectorp(v) and vectorp(vline) and not vectorp(tt) then
 int(sub( u1=getv(vline,0), u2=getv(vline,1), u3=getv(vline,2),
  getv(v,0) * df(getv(vline,0),tt) *  h1 +
  getv(v,1) * df(getv(vline,1),tt) *  h2 +
  getv(v,2) * df(getv(vline,2),tt) *  h3 ) , tt)
 else rerror(orthovec,18,"Incorrect arguments to LINEINT")$

%Definite Scalar Line Integral
%=============================
procedure dlineint(v,vline,tt,tlb,tub);
begin scalar integr,intval;
if vectorp(tlb) or vectorp(tub)
  then rerror(orthovec,19,"Limits to DLINEINT must be scalar")
  else <<integr:=lineint(v,vline,tt);
  intval:=sub(tt=tub,integr)-sub(tt=tlb,integr)>>;
return intval
end$

%
%-------------------------------------------------------------------
%        SET DEFAULT COORDINATES TO CARTESIAN
%
% write "Cartesian coordinates selected by default";
% write "If you wish to change this then type VSTART";
% write "and follow the instructions given.";
% write "u1,u2,u3 are reserved for coordinate names";
% write "h1,h2,h3 are reserved for scale factor names";
ctype:=1$u1:=x$u2:=y$u3:=z$h1:=1$h2:=1$h3:=1$
% write "coordinate type = ",ctype;
% write "coordinates = ",u1,",",u2,",",u3;
% write "scale factors = ",h1,",",h2,",",h3;

%-------------------------------------------------------------------

endmodule;

end;
