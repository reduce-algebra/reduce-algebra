module trigd; 
% Simplification rules and numerical evaluation 
% for degree versions of trig. functions.

% Author: Alan Barnes

% Copyright (c) 2015. A. Barnes All rights reserved.

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

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Support for trig functions with arguments in degrees
% Written by A Barnes, March 2015

% First make code which is commented out in arith/rdelem.red and crelem.red
% available to provide simpfns and numerical evaluation for all degree-based
% trig functions and their inverses. 

% Original author of numerical code not known (Stan Kameny?)

exports rdsind!*, rdcosd!*,  rdasind!*, rdacosd!*, rdtand!*,
        rdcotd!*,  rdatand!*,  rdacotd!*, rdsecd!*, rdcscd!*, 
        rdasecd!*, rdacscd!*,  rdatan2d!*;

imports rad2deg!*, deg2rad!*, convprec, mkround,
        acosd, acos!*, acotd, acscd, asecd,  asin!*, asind, atand,  atan!*, 
        sin!*, sind,  tan!*, tand, atan2d, atan2!*,
        cosd, cos!*, cotd, cscd, secd, 
        difbf, divbf, invbf, pi!/2!*,
        repart, impart, fix, fixp, evenp, ratnump,
        trigquot, knowledge_about;

deflist('((sind rdsind!*) (cosd rdcosd!*) (asind rdasind!*) (acosd
   rdacosd!*) (tand rdtand!*) (cotd rdcotd!*) (atand rdatand!*) (acotd
   rdacotd!*) (secd rdsecd!*) (cscd rdcscd!*) (asecd rdasecd!*) (acscd
   rdacscd!*) (atan2d rdatan2d!*) (argd rdargd!*)),'!:rd!:);

deflist('((sind crsind!*) (cosd crcosd!*) (tand crtand!*)
          (asind crasind!*) (acosd cracosd!*) (atand cratand!*)
          (cotd crcotd!*) (acotd cracotd!*) (secd crsecd!*)
          (cscd crcscd!*) (acscd cracscd!*)
          (asecd crasecd!*) (argd crargd!*)),'!:cr!:);

deflist('((acosd simpiden) (asind simpiden) (atand simpiden)
          (acotd simpiden) (cosd simpiden) (sind simpiden) (tand simpiden)
          (secd simpiden) (cscd simpiden) (cotd simpiden) (acotd simpiden)
          (asecd simpiden) (acscd simpiden) (atan2d simpiden)
   ),'simpfn);

flag ('(acosd asind atand acotd cosd sind tand cscd secd 
        cotd acotd asecd acscd), 'full);

put('atan2d, 'number!-of!-args, 2);

flag('(sind asind tand atand cotd cscd acscd),'odd);
remprop('acotd, 'odd);  % mistakenly set in rdelem.red
flag('(cosd secd),'even);
% NB acotd is not odd (nor of course are  acosd and asecd even)
% Principal value in all three cases lies in [0, 180].

flag('(cotd cscd),'nonzero);

symbolic procedure rdatan2d!*(u,v);
   mkround(if atom x then atan2d(x,y) else rad2deg!: atan2!*(x,y))
   where x=convprec u,y=convprec v;

% not used 

% symbolic procedure atan2d!*(y,x);
%    if mt!: x=0 then if (y := mt!: y)=0 then bfz!* else
%       <<x := timbf(!:180!*,bfhalf!*); if y<0 then minus!: x else x>>
%           else <<(if mt!: x>0 then a
%       else if mt!: y<0 then difbf(a,!:180!*) else plubf(a,!:180!*))
%      where a=rad2deg!: atan!* divbf(y,x)>>;

symbolic procedure rdsind!* u;
   mkround (if atom x then sind x else sin!* deg2rad!: x)
   where x=convprec u;

symbolic procedure rdcosd!* u;
   mkround(if atom x then cosd x else cos!* deg2rad!: x)
  where x=convprec u;

symbolic procedure rdtand!* u;
   mkround(if atom x then tand x else tan!* deg2rad!: x)
  where x=convprec u;

symbolic procedure rdasind!* u;
   mkround(if atom x then asind x else rad2deg!: asin!* x)
   where x=convprec u;

symbolic procedure rdacosd!* u;
   mkround(if atom x then acosd x else rad2deg!: acos!* x)
   where x=convprec u;

symbolic procedure rdatand!* u;
   mkround(if atom x then atand x else rad2deg!: atan!* x)
  where x=convprec u;

symbolic procedure rdsecd!* u;
   mkround(if atom x then secd x else invbf cos!* deg2rad!: x)
   where x=convprec u;

symbolic procedure rdcscd!* u;
   mkround(if atom x then cscd x else invbf sin!* deg2rad!: x)
  where x=convprec u;

symbolic procedure rdcotd!* u;
  mkround(if atom x then cotd x else tan!* difbf(pi!/2!*(),
          deg2rad!: x))
   where x=convprec u;

symbolic procedure rdacotd!* u;
  mkround(if atom x then acotd x
      else rad2deg!: difbf(pi!/2!*(),atan!* x))
   where x=convprec u;

symbolic procedure rdasecd!* u;  % not yet
   mkround(if atom x then asecd x else
      rad2deg!: difbf(pi!/2!*(),asin!* invbf x))
   where x=convprec u;

symbolic procedure rdacscd!* u;
  mkround(if atom x then acscd x else rad2deg!: asin!* invbf x)
  where x=convprec u;

symbolic procedure rdargd!* u;
   if rd!:minusp u then i2rd!*(180) else rdzero!*();

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% now for the  complex ones

symbolic procedure crsind!* u;
   mkcr(rd!:times(rdsind!* rl,rdcosh!* deg2rad!* im),
        rd!:times(rdcos!* rl,rdsinh!* deg2rad!* im))
    where rl=tagrl u,im=tagim u;

symbolic procedure crcosd!* u;
   mkcr(rd!:times(rdcosd!* rl,rdcosh!* deg2rad!* im),
        rd!:minus rd!:times(rdsind!* rl,rdsinh!* deg2rad!* im))
    where rl=tagrl u,im=tagim u;

symbolic procedure crtand!* u;
   cr!:times(cri!*(),cr!:quotient(cr!:differ(y,x),cr!:plus(y,x)))
   where x=crexp!*(cr!:times(cr2i!*(),crd2r!* u)),y=i2cr!* 1;

symbolic procedure crcotd!* u;
   cr!:times(cri!*(),cr!:quotient(cr!:plus(x,y),cr!:differ(x,y)))
   where x=crexp!*(cr!:times(cr2i!*(),crd2r!* u)),y=i2cr!* 1;

symbolic procedure crasind!* u;
   crr2d!* cr!:minus timesi!* crasinh!* timesi!* u;

symbolic procedure cracosd!* u;
   crr2d!* cr!:plus(cr!:times(crhalf!*(),crpi!*()),
      timesi!* crasinh!* timesi!* u);

symbolic procedure cratand!* u;
   crr2d!* cr!:times(cri!/2(),crlog!* cr!:quotient(
      cr!:plus(cri!*(),u),cr!:differ(cri!*(),u)));

symbolic procedure cracot!* u;
  cr!:differ(!*rd2cr pi!/2!*(), cratan!* u);

symbolic procedure cracotd!* u;
  cr!:differ(i2cr!* 90, cratand!* u);

symbolic procedure crsecd!* u;
   cr!:quotient(i2cr!* 1,crcos!* crd2r!* u);

symbolic procedure crcscd!* u;
  cr!:quotient(i2cr!* 1,crsin!* crd2r!* u);

symbolic procedure crasecd!* u;
   crr2d!* cracos!* cr!:quotient(i2cr!* 1,u);

symbolic procedure cracscd!* u;
  crr2d!* crasin!* cr!:quotient(i2cr!* 1,u);

% no procedure cratan2d!*  -- of course!

symbolic procedure crargd!* u; rdatan2d!*(tagim u,tagrl u);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% There is some duplication of the above in compopr, crelem and rdelem
% Tidy up later along with similar duplication for basic trig and
% hyperbolic functions?  Or is this duplication there for bootstrapping?

algebraic;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ******* basic simplification rules *******

% Rules follow the same pattern as for the basic trig functions except
% there are no rules to convert cases with purely imaginary arguments to
% hyperbolic functions.

let cosd(0) => 1;

let sind(15) => sqrt(2)/4*(sqrt 3-1),
    sind(75) => sqrt(2)/4*(sqrt 3+1),
    sind(30) => 1/2,
    sind(45) => sqrt 2/2,
    sind(60) => sqrt(3)/2;

for all x let cosd acosd x = x, sind asind x = x, tand atand x = x,
    cotd acotd x = x, secd asecd x = x, cscd acscd x = x;

% Rules below take principal value to lie in [0, 180]
let acosd(-~x) => 180-acosd(x),
    asecd(-~x) => 180-asecd(x),
    acotd(-~x) => 180-acotd(x);  % conflicts with oddness of acotd

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Fold the elementary trigonometric functions down to the origin.
let
 sind((~~w + ~~k)/~~d)
     => (if evenp fix repart(k/(d*180)) then 1 else -1)
          * sind(w/d + k/d-fix repart(k/(d*180))*180)
     when ((ratnump(rp) and abs(rp) >= 180) where rp => repart(k/d)),

 cosd((~~w + ~~k)/~~d)
     => (if evenp fix repart(k/(d*180)) then 1 else -1)
          * cosd(w/d + k/d-fix repart(k/(d*180))*180)
     when ((ratnump(rp) and abs(rp) >= 180) where rp => repart(k/d)),

 tand((~~w + ~~k)/~~d)
     => tand(w/d + k/d-fix repart(k/(d*180))*180)
     when ((ratnump(rp) and abs(rp) >= 180) where rp => repart(k/d)),        

 cotd((~~w + ~~k)/~~d)
     => cotd(w/d + k/d-fix repart(k/(d*180))*180)
     when ((ratnump(rp) and abs(rp) >= 180) where rp => repart(k/d)),

% the following 2 rules would not be inherited

 cscd((~~w + ~~k)/~~d)
     => (if evenp fix repart(k/(d*180)) then 1 else -1)
          * cscd(w/d + k/d-fix repart(k/(d*180))*180)
     when ((ratnump(rp) and abs(rp) >= 180) where rp => repart(k/d)),

 secd((~~w + ~~k)/~~d)
     => (if evenp fix repart(k/(d*180)) then 1 else -1)
          * secd(w/d + k/d-fix repart(k/(d*180))*180)
     when ((ratnump(rp) and abs(rp) >= 180) where rp => repart(k/d));

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Rules to shift by 180 into the interval (-90,  +90)
 
let
 sind((~~w + ~~k)/~~d)
     => -sind(w/d + k/d-sign(repart(k/d))*180)
     when ((ratnump(rp) and abs(rp) > 90) where rp => repart(k/d)),

 cosd((~~w + ~~k)/~~d)
     => -cosd(w/d + k/d-sign(repart(k/d))*180)
     when ((ratnump(rp) and abs(rp) > 90) where rp => repart(k/d)),

 tand((~~w + ~~k)/~~d)
     => tand(w/d + k/d-sign(repart(k/d))*180)
     when ((ratnump(rp) and abs(rp) > 90) where rp => repart(k/d)),

 cotd((~~w + ~~k)/~~d)
     => cotd(w/d + k/d-sign(repart(k/d))*180)
     when ((ratnump(rp) and abs(rp) > 90) where rp => repart(k/d)),

% the following 2 rules would not be inherited
 secd((~~w + ~~k)/~~d)
     => -secd(w/d + k/d-sign(repart(k/d))*180)
     when ((ratnump(rp) and abs(rp) > 90) where rp => repart(k/d)),

 cscd((~~w + ~~k)/~~d)
     => -cscd(w/d + k/d-sign(repart(k/d))*180)
     when ((ratnump(rp) and abs(rp) > 90) where rp => repart(k/d));

% The following rules follow the pattern
%   sin(~x + 90)=> cos(x)
% however allowing x to be a quotient and a negative 90 shift.
% We need to handle only 90 shifts here because
% the bigger shifts are already covered by the rules above.

let 
    sind((~~x + ~~k)/~~d) => sign repart(k/d)*cosd(x/d+i*impart(k/d))
         when  abs repart(k/d) = 90,

    cosd((~~x + ~~k)/~~d) => -sign repart(k/d)*sind(x/d+i*impart(k/d))
         when  abs repart(k/d) = 90,

% next two rules could be omitted and use inheritance
  cscd((~~x + ~~k)/~~d) => sign repart(k/d)*secd(x/d+i*impart(k/d))
       when  abs repart(k/d) = 90,

   secd((~~x + ~~k)/~~d) => -sign repart(k/d)*cscd(x/d+i*impart(k/d))
       when  abs repart(k/d) = 90,

    tand((~~x + ~~k)/~~d) => -cotd(x/d+i*impart(k/d))
         when  abs repart(k/d) = 90,

    cotd((~~x + ~~k)/~~d) => -tand(x/d+i*impart(k/d))
         when  abs repart(k/d) = 90;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% cosd, tand, cotd, secd, cscd inherit from sind.

let 
     cosd(~x) => sind(90-x)
         when x neq 0 and knowledge_about(sind, 90-x, cosd),
%  Test for x /= 0 necessary to avoid circularity in pattern matcher 
%  with the rule for 90 deg shifts for sin 
% note third argument of knowledge_about prevents rule triggering for args
% x+/-pi/2
    tand(~x) => trigquot(sind(x),cosd(x)) 
             when knowledge_about(sind,x,cosd),
    cotd(~x) => trigquot(cosd(x),sind(x))
               when  knowledge_about(sind,x,cosd),
    secd(~x) => 1/cosd(x) when knowledge_about(cosd,x,sind),
    cscd(~x) => 1/sind(x) when knowledge_about(sind,x,cosd);
  
% area functions

let asind(~x) => 90 - acosd(x) when knowledge_about(acosd,x,asind),
    acotd(~x) => 90 - atand(x) when knowledge_about(atand,x,acotd),
    acscd(~x) => asind(1/x) when knowledge_about(asind,1/x,acscd),
    asecd(~x) => acosd(1/x) when knowledge_about(acosd,1/x,asecd);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Transfer inverse function values from cosd to acosd and tand to atand.
% Negative values not needed.
% Ensure rules also work when RATIONAL is ON

for j:=1:2 do <<
  acosd_rules :=
    symbolic(
    'list . for j:=0:12 join
      (if eqcar(q,'acosd) and cadr q=w then {{'replaceby,q,u}})
       where q=reval{'acosd,w}
        where w=reval{'cosd,u}
         where u =15*j)$

  atand_rules :=
    symbolic(
    'list . for j:=0:5 join
      (if eqcar(q,'atand) and cadr q=w then {{'replaceby,q,u}})
       where q= reval{'atand,w}
        where w= reval{'tand,u}
         where u= 15*j)$

   let acosd_rules;
   clear acosd_rules;
   let atand_rules;
   clear atand_rules;
   if j=1 then on rational else off rational;
>>;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ***** Differentiation rules *****.

let df(cosd(~x),x) => -pi/180*sind(x),
    df(sind(~x),x) => pi/180*cosd(x),
    df(tand(~x),x) => pi/180*(1 + tand x**2),
    df(cotd(~x),x) => -pi/180*(1+cotd x**2),
    df(secd(~x),x) => pi/180*secd(x)*tand(x),
    df(cscd(~x),x) => -pi/180*cscd(x)*cotd(x),
    df(acosd(~x),x) => -180/pi*sqrt(1-x**2)/(1-x**2),
    df(asind(~x),x) => 180/pi*sqrt(1-x**2)/(1-x**2),
    df(atand(~x),x) => 180/(pi*(1+x**2)),
    df(acotd(~x),x) => -180/(pi*(1+x**2)),
    df(acscd(~x),x) =>  -180/(pi*x*sqrt(x**2 - 1)),
    df(asecd(~x),x) => 180/(pi*x^2*sqrt(1-1/x^2)),
    df(atan2d(~y,~x),~z) => 180/pi*(x*df(y, z)-y*df(x, z))/(x^2+y^2);

% More trigonometrical rules.

let 
   atan2d(~y, 0) => sign(y)*90
      when y neq 0 and  fixp sign(y),
   atan2d(0, ~x) => (if sign(x)=1 then 0 else 180)
      when x neq 0 and fixp sign(x),
   atan2d(~y, ~x) => (if sign(x)=1 then 0 
                     else if sign(y)=1 then 180
                     else -180) + atand(y/x)
      when fixp sign(x) and fixp sign(y);

let
  sind(atand ~u)   => u/sqrt(1+u^2),
  cosd(atand ~u)   => 1/sqrt(1+u^2),
  sind(2*atand ~u) => 2*u/(1+u^2),
  cosd(2*atand ~u) => (1-u^2)/(1+u^2),
  sind(~n*atand ~u) => sind((n-2)*atand u) * (1-u^2)/(1+u^2) +
                     cosd((n-2)*atand u) * 2*u/(1+u^2)
                     when fixp n and n>2,
  cosd(~n*atand ~u) => cosd((n-2)*atand u) * (1-u^2)/(1+u^2) -
                     sind((n-2)*atand u) * 2*u/(1+u^2)
                     when fixp n and n>2,
  sind(acosd ~u) => sqrt(1-u^2),
  cosd(asind ~u) => sqrt(1-u^2),
  sind(2*acosd ~u) => 2 * u * sqrt(1-u^2),
  cosd(2*acosd ~u) => 2*u^2 - 1,
  sind(2*asind ~u) => 2 * u * sqrt(1-u^2),
  cosd(2*asind ~u) => 1 - 2*u^2,
  sind(~n*acosd ~u) => sind((n-2)*acosd u) * (2*u^2 - 1) +
                     cosd((n-2)*acosd u) * 2 * u * sqrt(1-u^2)
                     when fixp n and n>2,
  cosd(~n*acosd ~u) => cosd((n-2)*acosd u) * (2*u^2 - 1) -
                     sind((n-2)*acosd u) * 2 * u * sqrt(1-u^2)
                     when fixp n and n>2,
  sind(~n*asind ~u) => sind((n-2)*asind u) * (1 - 2*u^2) +
                     cosd((n-2)*asind u) * 2 * u * sqrt(1-u^2)
                     when fixp n and n>2,
  cosd(~n*asind ~u) => cosd((n-2)*asind u) * (1 - 2*u^2) -
                     sind((n-2)*asind u) * 2 * u * sqrt(1-u^2)
                     when fixp n and n>2;

% no rules yet for complex args

%trigd_imag_rules := {
%    sind(i * ~~x)   => i * sinh(pi*x/180) when impart(y)=0,
%    cosd(i * ~~x / ~~y)   => cosh(pi*x/(180*y)) when impart(y)=0,
%    tand(i * ~~x / ~~y)   => i * tanh(pi*x/(180*y)) when impart(y)=0,
%    cotd(i * ~~x / ~~y)   => -coth(pi*x/(180*y)) when impart(y)=0,
%    cscd(i * ~~x / ~~y)   => -i * csch(pi*x/(180*y)) when impart(y)=0,
%    secd(i * ~~x / ~~y)   => sech(pi*x/(180*y)) when impart(y)=0,
%    asind(i * ~~x / ~~y)  => 180i/pi * asinh(x/y) when impart(y)=0,
%    atand(i * ~~x / ~~y)  => 180i/pi * atanh(x/y) when impart(y)=0
%                                and not(x=1 and y=1)
%}$

% let trigd_imag_rules;


% Generalized periodicity rules for trigonometric functions

let 
 cosd(~n*arbint(~k) + ~~x) => cosd(x+(n-fix(n/360)*360)*arbint(k))
    when fixp(n) and abs n >= 360,

 sind(~n*arbint(~k) + ~~x) => sind(x+(n-fix(n/360)*360)*arbint(k))
     when fixp(n) and abs n >= 360,

 secd(~n*arbint(~k) + ~~x) => secd(x+(n-fix(n/360)*360)*arbint(k))
     when fixp(n) and abs n >= 360,

 cscd(~n*arbint(~k) + ~~x) => cscd(x+(n-fix(n/360)*360)*arbint(k))
     when fixp(n) and abs n >= 360,

 tand(~n*arbint(~k) + ~~x) => tand(x+(n-fix(n/180)*180)*arbint(k))
     when fixp(n) and abs n >= 180,

 cotd(~n*arbint(~k) + ~~x) => cotd(x+(n-fix(n/180)*180)*arbint(k))
     when fixp(n) and abs n >= 180;


endmodule;

end;