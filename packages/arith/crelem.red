module crelem; % Complex elementary functions for complex rounded.

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

imports !*rd2cr, bflessp, bfminusp, cr!:differ, cr!:minus, cr!:plus,
        cr!:quotient, cr!:times, cr!:zerop, cr2i!*, crhalf!*, cri!*,
        cri!/2, crprcd, crrl, deg2rad!*, gf2cr!:, gfsqrt, i2cr!*,
        i2rd!*, mkcr, rad2deg!*, rd!:minus, rd!:quotient, rd!:times,
        rdatan2!*, rdatan2d!*, rdcos!*, rdcosd!*, rdcosh!*, rde!*,
        rdexp!*, rdhalf!*, rdhypot!*, rdlog!*, rdone!*, rdpi!*,
        rdsin!*, rdsind!*, rdsinh!*, rdtwo!*, rdzero!*, retag,
        round!*, tagim, tagrl, bfminus, bflessp;

fluid '(!*!*roundbf);

global '(!!flprec !!rdprec bfz!* bftwo!* bfone!* bfhalf!*);

deflist('((expt crexpt!*) (sin crsin!*) (cos crcos!*) (tan crtan!*)
          (asin crasin!*) (acos cracos!*) (atan cratan!*)
          (cot crcot!*) (acot cracot!*) (sec crsec!*) (asec crasec!*)
          (csc crcsc!*) (acsc cracsc!*) (sinh crsinh!*) (cosh crcosh!*)
          (asinh crasinh!*) (acosh cracosh!*) (tanh crtanh!*)
          (coth crcoth!*) (atanh cratanh!*) (acoth cracoth!*)
          (sech crsech!*) (csch crcsch!*) (asech crasech!*)
          (acsch cracsch!*) (atan2 cratan2!*) (arg crarg!*)
          (sqrt crsqrt!*) (norm crnorm!*) (arg crarg!*) (log crlog!*) 
          (log10 crlog10!*) (exp crexp!*) (logb crlogb!*) 
          (e cre!*) (pi crpi!*)),'!:cr!:);

symbolic procedure cre!*; mkcr(rde!*(),rdzero!*());

symbolic procedure crpi!*; mkcr(rdpi!*(),rdzero!*());

symbolic procedure crexpt!*(u,v);
   if cr!:zerop(cr!:differ(v,crhalf!*())) then crsqrt!* u
   else crexp!* cr!:times(v,crlog!* u);

symbolic procedure crnorm!* u; rdhypot!*(tagrl u,tagim u);

symbolic procedure crarg!* u; rdatan2!*(tagim u,tagrl u);

symbolic procedure crsqrt!* u; gf2cr!: gfsqrt crprcd u;

symbolic procedure crr2d!* u; mkcr(rad2deg!* tagrl u,rad2deg!* tagim u);

symbolic procedure crd2r!* u; mkcr(deg2rad!* tagrl u,deg2rad!* tagim u);

symbolic procedure crsin!* u;
   mkcr(rd!:times(rdsin!* rl,rdcosh!* im),
        rd!:times(rdcos!* rl,rdsinh!* im))
    where rl=tagrl u,im=tagim u;

symbolic procedure crcos!* u;
   mkcr(rd!:times(rdcos!* rl,rdcosh!* im),
        rd!:minus rd!:times(rdsin!* rl,rdsinh!* im))
    where rl=tagrl u,im=tagim u;

symbolic procedure crtan!* u;
   cr!:times(cri!*(),cr!:quotient(cr!:differ(y,x),cr!:plus(y,x)))
   where x=crexp!*(cr!:times(cr2i!*(),u)),y=i2cr!* 1;

symbolic procedure crcot!* u;
   cr!:times(cri!*(),cr!:quotient(cr!:plus(x,y),cr!:differ(x,y)))
   where x=crexp!*(cr!:times(cr2i!*(),u)),y=i2cr!* 1;

symbolic procedure cratan2!*(y,x);
    begin scalar q,p;
       q := crsqrt!* cr!:plus(cr!:times(y,y),cr!:times(x,x));
      if cr!:zerop q then error(0,list("invalid arguments to ",'atan2));
       y := cr!:quotient(y,q); x := cr!:quotient(x,q); p := rdpi!*();
       if cr!:zerop x then
          <<q := rd!:quotient(p,i2rd!* 2);
            return if bfminusp retag crrl y then rd!:minus q else q>>;
       q := cratan!* cr!:quotient(y,x);
       if bfminusp retag crrl x then
          <<p := !*rd2cr p;
            q := if bfminusp retag crrl y
               then cr!:differ(q,p) else cr!:plus(q,p)>>;
          %  bfzp x is probably impossible?
       return q end;

symbolic procedure crlog!* u;
   mkcr(rdlog!* crnorm!* u,crarg!* u);

symbolic procedure crlog10!* u; cr!:quotient(crlog!* u,crlog!* i2cr!* 10);

symbolic procedure crlogb!*(u,b); cr!:quotient(crlog!* u,crlog!* b);

symbolic procedure timesi!* u; cr!:times(cri!*(),u);

symbolic procedure crsec!* u; cr!:quotient(i2cr!* 1,crcos!* u);

symbolic procedure crcsc!* u; cr!:quotient(i2cr!* 1,crsin!* u);

symbolic procedure crsinh!* u;
   cr!:times(crhalf!*(),cr!:differ(y,cr!:quotient(i2cr!* 1,y)))
   where y=crexp!* u;

symbolic procedure crcosh!* u;
   cr!:times(crhalf!*(),cr!:plus(y,cr!:quotient(i2cr!* 1,y)))
   where y=crexp!* u;

symbolic procedure crtanh!* u;
   cr!:quotient(cr!:differ(x,y),cr!:plus(x,y))
   where x=crexp!*(cr!:times(i2cr!* 2,u)),y=i2cr!* 1;

symbolic procedure crcoth!* u;
   cr!:quotient(cr!:plus(x,y),cr!:differ(x,y))
   where x=crexp!*(cr!:times(i2cr!* 2,u)),y=i2cr!* 1;

symbolic procedure crsech!* u;
   cr!:quotient(i2cr!* 2,cr!:plus(y,cr!:quotient(i2cr!* 1,y)))
   where y=crexp!* u;

symbolic procedure crcsch!* u;
   cr!:quotient(i2cr!* 2,cr!:differ(y,cr!:quotient(i2cr!* 1,y)))
   where y=crexp!* u;

symbolic procedure crexp!* u;
   <<u := tagim u; mkcr(rd!:times(r,rdcos!* u),rd!:times(r,rdsin!* u))>>
   where r=rdexp!* tagrl u;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Inverse trig and hyperbolic functions
% The principal values necessarily have discontinuities (on the branch-cuts)
% owing to the periodicty of the trig and hyperbolic functions 
% and the multi-valued nature of their inverses.
% The choice of cuts is to a large extent arbitrary. Below they are chosen
% always to lie on the real or imaginary axes and to maintain conditions
% such as oddness on the cut and continuity along the cut.
% Beware of 'simplifications' such as log(a/b)=log(a)-log(b) as these
% in general change the cut structure.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure crasin!* u; 
% Branch-cut is {r | r real & (r>=1 or r<=-1)}
cr!:minus timesi!* crasinh!* timesi!* u;

symbolic procedure cracos!* u;
   cr!:plus(cr!:times(crhalf!*(),crpi!*()),
      timesi!* crasinh!* timesi!* u);

symbolic procedure cratan!* u;
% Branch points at +i and -i are singular
% The branch cut is taken to be {r*i | r real and (r>1 or r <-1)}
% Adds pi if u lies on upper branch-cut (r>1)
% This maintains the condition atan(-u)= -atan(u) on the branch-cut
% The upper-cut lies in the first quadrant and the lower-cut in the third.
  (if rd!:zerop tagrl u and  bflessp(rdone!*(), round!* tagim u) then
     cr!:plus(val, crpi!*()) else val)
  where val =  cr!:times(cri!/2(),crlog!* cr!:quotient(
                      cr!:plus(cri!*(),u),cr!:differ(cri!*(),u)));

symbolic procedure cracot!* u;
% Branch points and branch-cut is as for atan
% definition uses acot u =pi/2-atan u
% NB acot is NOT odd unlike acoth so identities relating 
% acot(i*z)  with acoth(z) need care!
   cr!:differ(cr!:times(crhalf!*(),crpi!*()), cratan!*  u);

symbolic procedure crasec!* u; cracos!* cr!:quotient(i2cr!* 1,u);

symbolic procedure cracsc!* u; crasin!* cr!:quotient(i2cr!* 1,u);

symbolic procedure crasinh!* u;
% Branch-cut is taken to be {r*i |r real & (r>=1 or r<= -1)}
% The upper-half belongs to the second quadrant and the lower-half to the fourth
% The condition asinh(-z) =-asinh z is maintained on the cut by
% ensuring the correct branch is taken of the sqrt in log(i*(r-sqrt(r^2-1)))
% on the two halves of the cut.
% returns essentially the same result as
%   crlog!* cr!:plus(u,crsqrt!* cr!:plus(cr!:times(u,u),i2cr!* 1));
% but optimises the sqrt calculation for large z
begin scalar rl, im, one, imbf, s;
  rl:=tagrl u; im:=tagim u; imbf := round!* im; one:=rdone!*(); s:=1;
  if rd!:zerop rl and 
     (bflessp(one, imbf) or bflessp(imbf, bfminus one)) then
        << if rd!:minusp im then <<im :=rd!:minus im; s:=-1>>;
           return (if s=1 then val else cr!:minus val)
              where val = mkcr(rd!:minus rdacosh!* im, pi!/2!*())>>;

  s := cr!:times(u,u);
  return
     if bflessp(round!* crnorm!* u,rdtwo!*()) then
        crlog!* cr!:plus(u, crsqrt!* cr!:plus(i2cr!* 1,s))
     else (if rd!:minusp rl then
             crlog!* cr!:differ(u, cr!:times(u, sroot))
           else
             crlog!* cr!:plus(u, cr!:times(u, sroot)))
           where sroot =
               crsqrt!* cr!:plus(i2cr!* 1,cr!:quotient(i2cr!* 1,s));
end;

symbolic procedure cracosh!* u;
% Branch cut is {r | r real and (r>=1 or r <= -1)}
% Right-hand half is in 1st quadrant and left-hand half in the third quadrant.
% Chosen in preference to that below as acosh(z)+acosh(-z)=pi*i everywhere.
  cr!:differ(timesi!* cr!:times(crhalf!*(), crpi!*()), crasinh!* timesi!* u);

% symbolic procedure cracosh!* u;
% % The original version used the formula
% %     acosh z = log(z+sqrt(z^2-1))
% % The branch cuts were fubar: portions of both real and imaginary axes.
% %
% % The improved version uses the formula
% %     acosh z = log(z+sqrt(z-1)*sqrt(z+1))
% % the branch-cut is {r | r real and r< 1} 
% % For r>0 cut is in 1st quadrant and when r<0  in the 2nd quadrant.
% % Beware of 'simplifications' such as combining sqrts; these alter the cuts
%  crlog!* cr!:plus(u,cr!:times(crsqrt!* cr!:differ(u, i2cr!* 1),
%                               crsqrt!* cr!:plus(u, i2cr!* 1)));

symbolic procedure cratanh!* u;
% The branch-points at u=+1 and u=-1  are singularities
% Branch cut is taken to be {r | r real and (r>1 or r<-1)}
% Subtracts i*pi if u lies on right-hand branch-cut {r | r real & r>1}
% This maintains the condition atanh(-u)= -atanh(u) on the branch-cut
% The rh-cut lies in the fourth quadrant and the lh-cut in the second.
  (if rd!:zerop tagim u and  bflessp(rdone!*(), round!* tagrl u) then
     cr!:differ(val, cr!:times(cri!*(), crpi!*())) else val)
 where  val=cr!:times(crhalf!*(),crlog!* cr!:quotient(cr!:plus(i2cr!* 1,u),
      cr!:differ(i2cr!* 1,u)));

symbolic procedure cracoth!* u;
% The branch-points at u=+1 and u=-1  are singularities
% Branch cut is taken to be the interval of the real axis (-1, +1)
% Subtracts i*pi if u lies on left half of branch-cut {r | r real & -1<r<0}
% This maintains the condition acoth(-u)= -acoth(u) on the branch-cut
% The rh half-cut lies in the first quadrant and the lh half-cut in the third.
% There is a discontinuity as r --> 0  along the lh half-cut
  (if rd!:zerop tagim u and rd!:minusp tagrl u  and 
              bflessp(bfminus rdone!*(), round!* tagrl u)
   then cr!:differ(val, cr!:times(cri!*(), crpi!*())) else val)
  where val = cr!:times(crhalf!*(),crlog!* 
                 cr!:quotient(cr!:plus(i2cr!* 1,u), cr!:differ(u,i2cr!* 1)));

symbolic procedure crasech!* u; cracosh!* cr!:quotient(i2cr!* 1,u);

symbolic procedure cracsch!* u; crasinh!* cr!:quotient(i2cr!* 1,u);

endmodule;
end;
