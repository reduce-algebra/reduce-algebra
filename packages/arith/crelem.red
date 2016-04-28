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
% 
% Except for acot, they agree with the cuts recommended by Kahan.
% This exception is necessary as in Reduce acot(-z) = pi - acot z
%
% Beware of 'simplifications' such as log(a/b)=log(a)-log(b) as these
% in general change the cut structure.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% a utility procedure used to calculate the arguments for acos and acosh 
% used in the four procedures for acos, asin, acosh and asinh. 
symbolic procedure invfnargs(x, y);
begin scalar ssq, hyp, n, s;
  ssq := rd!:plus(rd!:times(x, x), rd!:times(y, y));
  % n = 2(x^2-y^2)-1
  n := rd!:difference(rd!:times(rd!:difference (x, y),
                                rd!:times(i2rd!* 2, rd!:plus(x, y))),
                      i2rd!* 1 );
                                   
  hyp := rdhypot!*(rd!:difference(ssq, i2rd!* 1),
                   rd!:times(i2rd!* 2, y));
  s := rd!:plus(ssq, hyp);
  % NB n/s = ssq-hyp, but this method reduces rounding errors somewhat
  % at the expense of a few extra arithmetic operations.
  return s . rd!:quotient(n, s);
end;

symbolic procedure crasin!* z;
% This version uses the formula for the real and imag parts u & v of asin z
%   u = acos(sqrt((x^2+y^2-1)^2+4x^2)-x^2-y^2)/2
%                                                where z = x+i*y
%   v = acosh(x^2+y^2+sqrt((x^2+y^2-1)^2+4y^2))/2
% involving only calls to versions of acos, acosh and sqrt from rdelem.red.
% It is faster than the  method using complex logarithm and sqrt
% by a factor of around 4 for the default precision
% and a factor of about 1.25 for bigfloats
begin scalar rp, ip, args, u, v;
  rp := tagrl z; ip := tagim z;
  args := invfnargs(rp, ip);
  v := rd!:quotient(rdacosh!* car args, i2rd!* 2);
  % the test for zero real part of z avoids problems than occur when
  % the argument of rdacos!* is greater than the exact result 1 due to rounding
  u := if rd!:zerop rp then i2rd!* 0 
       else rd!:quotient(rdacos!* rd!:minus cdr args, i2rd!* 2);

  return mkcr(if rd!:minusp rp then rd!:minus u else u,
              if rd!:minusp ip or (rd!:zerop ip and not rd!:minusp rp)
              then rd!:minus v else v);
end;

% symbolic procedure crasin!* u; 
% Branch-cut is {r | r real & (r>=1 or r<=-1)}
% cr!:minus timesi!* crasinh!* timesi!* u;

symbolic procedure cracos!* z;
% This version uses the formula for the real and imag parts u & v of acos z
%   u = acos(x^2+y^2-sqrt((x^2+y^2-1)^2+4y^2))/2
%                                                   where z = x+i*y
%   v = acosh(x^2+y^2+sqrt((x^2+y^2-1)^2+4y^2))/2
% involving only calls to versions of acos, acosh and sqrt from rdelem.red.
% It is faster than the  method using complex logarithm and sqrt
% by a factor of around 4 for the default precision
% and a factor of about 1.25 for bigfloats
begin scalar rp, ip, args,  u, v;
  rp := tagrl z; ip := tagim z;
  args := invfnargs(rp, ip);
  % the test for zero real part of z avoids problems than occur when
  % the argument of rdacos!* is less than the exact result -1 due to rounding
  u := rd!:quotient(if rd!:zerop rp then rdpi!*() 
                    else rdacos!* cdr args,
                    i2rd!* 2);
  v := rd!:quotient(rdacosh!* car args, i2rd!* 2);
  return mkcr(if rd!:minusp rp then  rd!:difference(rdpi!*(), u) else u,
              if rd!:minusp ip or (rd!:zerop ip and not rd!:minusp rp)
              then v else rd!:minus v);
end;
  
% symbolic procedure cracos!* u;
%   cr!:plus(cr!:times(crhalf!*(),crpi!*()),
%      timesi!* crasinh!* timesi!* u);

symbolic procedure cratan!* u;
% Branch points at +i and -i are singular
% The branch cut is taken to be {r*i | r real and (r>1 or r <-1)}
% Adds pi if u lies on upper branch-cut (r>1)
% This maintains the condition atan(-u)= -atan(u) on the branch-cut
% The upper-cut lies in the first quadrant and the lower-cut in the third.
%
% Produces the same result as Kahan's formula below, but is faster.
  (if rd!:zerop tagrl u and  bflessp(rdone!*(), round!* tagim u) then
     cr!:plus(val, crpi!*()) else val)
  where val =  cr!:times(cri!/2(),crlog!* cr!:quotient(
                      cr!:plus(cri!*(),u),cr!:differ(cri!*(),u)));

% symbolic procedure cratan1!* u;
% % Branch points and branch cuts are as above
%   cr!:minus timesi!* cratanh!* timesi!* u;

symbolic procedure cracot!* u;
% Branch points and branch-cut is as for atan
% definition uses acot u =pi/2-atan u
% NB acot is NOT odd unlike acoth so identities relating 
% acot(i*z)  with acoth(z) need care!
   cr!:differ(cr!:times(crhalf!*(),crpi!*()), cratan!*  u);

symbolic procedure crasec!* u; cracos!* cr!:quotient(i2cr!* 1,u);

symbolic procedure cracsc!* u; crasin!* cr!:quotient(i2cr!* 1,u);

symbolic procedure crasinh!* z;
% This version uses the formula for the real and imag parts u & v of asinh z
%   u = acosh(x^2+y^2+sqrt((x^2+y^2-1)^2+4x^2))/2 
%                                                   where z = x+i*y
%   v = acos(sqrt((x^2+y^2-1)^2+4x^2)-x^2-y^2)/2
% involving only calls to versions of acos, acosh and sqrt from rdelem.red.
% It is faster than the  method using complex logarithm and sqrt
% by a factor of around 4 for the default precision
% and a factor of about 1.25 for bigfloats
begin scalar rp, ip, args, u, v;
  rp := tagrl z; ip := tagim z;
  args := invfnargs(ip, rp);
  u := rd!:quotient(rdacosh!* car args, i2rd!* 2);
  % the test for zero imaginary part of z avoids problems than occur when
  % the argument of rdacos!* is greater than the exact result 1 due to rounding
  v := if rd!:zerop ip then i2rd!* 0 
       else rd!:quotient(rdacos!* rd!:minus cdr args, i2rd!* 2);

  return mkcr(if rd!:minusp rp or (rd!:zerop rp and rd!:minusp ip)
              then rd!:minus u else u,
              if rd!:minusp ip then rd!:minus v else v);
end;

% symbolic procedure crasinh!* u;
% Branch-cut is taken to be {r*i |r real & (r>=1 or r<= -1)}
% The upper-half belongs to the first quadrant and the lower-half to the third
% The condition asinh(-z) =-asinh z is maintained on the cut.
%
% This (Kahan's) simple formula is faster than the 'optimised' versions below
%  and seems to produce equally accurate results.
%    crlog!* cr!:plus(u, crsqrt!* cr!:plus(i2cr!* 1,cr!:times(u,u)));

% symbolic procedure crasinh!* u;
%    crlog!* cr!:plus(u,
%      if bflessp(round!* crnorm!* u,rdtwo!*())
%          then crsqrt!* cr!:plus(i2cr!* 1,s)
%          else cr!:times(u,
%             crsqrt!* cr!:plus(i2cr!* 1,cr!:quotient(i2cr!* 1,s))))
%   where s=cr!:times(u,u);

% symbolic procedure crasinh1!* u;
% % Returns essentially the same result as
%%   crlog!* cr!:plus(u,crsqrt!* cr!:plus(cr!:times(u,u),i2cr!* 1));
% % but optimises the sqrt calculation for large z without altering the cut.
% %
% % The original optimisation above had the effect of altering the branch cut
% % to {r*i | r real & 1<= |r| <= 2} union {z | real z <0 & |z| =2}
% % and destroying the oddness condition for most of the region |z| > 2.
% % Beware of such rearrangements; these may alter the cuts.
% 
% (if bflessp(round!* crnorm!* u,rdtwo!*()) then
%         crlog!* cr!:plus(u, crsqrt!* cr!:plus(i2cr!* 1,s))
%    else (if rd!:minusp rl  or (rd!:zerop  rl and rd!:minusp tagim u) then
%             crlog!* cr!:differ(u, cr!:times(u, sroot))
%          else
%              crlog!* cr!:plus(u, cr!:times(u, sroot)))
%          where sroot = crsqrt!* cr!:plus(i2cr!* 1,cr!:quotient(i2cr!* 1,s)),
%                rl = tagrl u)
%      where s = cr!:times(u,u);

symbolic procedure cracosh!* z;
% This version uses the formula for the real and imag parts u & v of acosh z
%   u = acosh(x^2+y^2+sqrt((x^2+y^2-1)^2+4y^2))/2
%                                                    where z = x+i*y
%   v = acos(x^2+y^2-sqrt((x^2+y^2-1)^2+4y^2))/2
% involving only calls to versions of acos, acosh and sqrt from rdelem.red.
% It is faster than the  method using complex logarithm and sqrt
% by a factor of around 4 for the default precision
% and a factor of about 1.25 for bigfloats
begin scalar rp, ip, args, u, v;
  rp := tagrl z; ip := tagim z;
  args := invfnargs(rp, ip);
  u := rd!:quotient(rdacosh!* car args, i2rd!* 2);
  % the test for zero real part of z avoids problems than occur when
  % the argument of rdacos!* is less than the exact result -1 due to rounding
  v := rd!:quotient(if rd!:zerop rp then rdpi!*() 
                    else rdacos!* cdr args, 
                    i2rd!* 2);
  return mkcr(u, if rd!:minusp ip then rd!:minus v1 else v1)
          where v1 = if rd!:minusp rp then rd!:difference(rdpi!*(), v) else v;
end;

% symbolic procedure cracosh!* u;
%    crlog!* cr!:plus(u,crsqrt!* cr!:differ(cr!:times(u,u),i2cr!* 1));

% symbolic procedure cracosh!* u;
% The original version above used the formula
%     acosh z = log(z+sqrt(z^2-1))
% The branch cuts were the portions of the real axis |r| >=1  
% and the whole of the imaginary axis.
%
% The improved version uses the formula
%     acosh z = log(z+sqrt(z-1)*sqrt(z+1))
% the branch-cut is {r | r real and r< 1} 
% For r>0 cut is in 1st quadrant and when r<0  in the 2nd quadrant.
% Beware of 'simplifications' such as combining sqrts; these may alter the cuts
%
% Produces same result as Kahan's formula below, but is faster.
%   crlog!* cr!:plus(u,cr!:times(crsqrt!* cr!:differ(u, i2cr!* 1),
%                                crsqrt!* cr!:plus(u, i2cr!* 1)));

% symbolic procedure cracosh1!* u;
% % This improved version uses Kahan's formula
% %     acosh z = 2log(sqrt((z-1)/2) +sqrt((z+1)/2))
% % the branch-cut should be the same as above
%    cr!:times(two, crlog!*
%               cr!:plus(crsqrt!* cr!:quotient(cr!:differ(u, i2cr!* 1), two),
%                       crsqrt!* cr!:quotient(cr!:plus(u, i2cr!* 1), two)))
%      where two = i2cr!* 2;

symbolic procedure cratanh!* u;
% The branch-points at u=+1 and u=-1  are singularities
% Branch cut is taken to be {r | r real and (r>1 or r<-1)}
% Subtracts i*pi if u lies on right-hand branch-cut {r | r real & r>1}
% This maintains the condition atanh(-u)= -atanh(u) on the branch-cut
% The rh-cut lies in the fourth quadrant and the lh-cut in the second.
%
% Produces same result as Kahan's formula below, but is faster.
  (if rd!:zerop tagim u and  bflessp(rdone!*(), round!* tagrl u) then
     cr!:differ(val, cr!:times(cri!*(), crpi!*())) else val)
 where  val=cr!:times(crhalf!*(),crlog!* cr!:quotient(cr!:plus(i2cr!* 1,u),
      cr!:differ(i2cr!* 1,u)));

% symbolic procedure cratanh1!* u;
% %  Uses Kahan's formula 1/2(log(1+z)-log(1-z))
% % The branch cuts are as as above  
%  cr!:times(crhalf!*(),cr!:differ(crlog!* cr!:plus(i2cr!* 1,u),
%                                 crlog!* cr!:differ(i2cr!* 1,u)));

symbolic procedure cracoth!* u;
% The branch-points at u=+1 and u=-1  are singularities
% Branch cut is taken to be the interval of the real axis (-1, +1)
% Subtracts i*pi if u lies on right half of branch-cut {r | r real & 0<r<1}
% This maintains the condition acoth(-u)= -acoth(u) on the branch-cut
% The rh half-cut lies in the fourth quadrant and the lh half-cut in the second.
% There is a discontinuity as r --> 0  along the rh half-cut
%
% Produces the same result as atanh(1/u) except at u=0 when i*pi/2 is returned.
  (if rd!:zerop tagim u and (bflessp(rdzero!*(), rp)  and 
              bflessp(rp, rdone!*())) where rp = round!* tagrl u
   then cr!:differ(val, cr!:times(cri!*(), crpi!*())) else val)
  where val = cr!:times(crhalf!*(),crlog!* 
                 cr!:quotient(cr!:plus(i2cr!* 1,u), cr!:differ(u,i2cr!* 1)));

symbolic procedure crasech!* u; cracosh!* cr!:quotient(i2cr!* 1,u);

symbolic procedure cracsch!* u; crasinh!* cr!:quotient(i2cr!* 1,u);

endmodule;
end;
