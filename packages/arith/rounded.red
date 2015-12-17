module rounded; % *** Support for Arbitrary Rounded Arithmetic.

% Authors: Anthony C. Hearn and Stanley L. Kameny.

% Last updated: 23 June 1993.

% Copyright (c) 2000, Anthony C. Hearn.  All rights reserved.

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


COMMENT this module defines a rounded object as a list with two fields:

      (<tag>.<structure>).

The <structure> depends on the precision.  It is either a floating point
number or the stripped bfloat (mt . ep);

exports chkint!*, chkrn!*, convprec, convprec!*, deg2rad!*,
        i2rd!*, logfp, mkround, rd!:difference, rd!:minus, rd!:minusp,
        rd!:onep, rd!:plus, rd!:prep, rd!:prin, rd!:quotient,
        rd!:simp, rd!:times, rd!:zerop, rdprep1, rdqoterr, rdzchk,
        rndbfon, round!*, roundbfoff, roundbfon, roundconstants,
        safe!-fp!-plus, safe!-fp!-times, safe!-fp!-quot;

imports !*d2q, !:difference, !:minus, !:minusp, !:zerop, abs!:, aeval,
        apply1, bf2flr, bfdiffer, bfexplode0, bfinverse, bflessp,
        bfloat, bfminus, bfminusp, bfprin!:, bftrim!:, bfzerop!:,
        bfzp, ceiling, copyd, deg2rad!*, difbf, divbf, dmoderr,
        ep!:, eqcar, equal!:, errorp, errorset!*, fl2int,
        fl2rd, float!-bfp, floor, ft2rn1, geq, greaterp!:, grpbf,
        i2bf!:, initdmode, invbf, leq, lessp!:, log, lprim, lshift,
        make!:ibf, make!:rd, minus!:, minusp!:, mkquote, msgpri, mt!:,
        neq, normbf, off1, on1, over, plubf, preci!:, r2bf, rd2fl,
        rd!:forcebf, realrat, rerror, retag, rmsubs, round!:mt, setk,
        sqrt, timbf, times!:, union;

fluid '(!:prec!: !:bprec!: !:print!-prec!: minprec!# rootacc!#!#);

fluid '(dmode!* !*bfspace !*numval !*roundbf !*!*roundbf !*norndbf);

fluid '(!*noconvert);

global '(bfone!* epsqrt!* !!log2of10 !!log2);

global '(domainlist!* !!nfpd !!nbfpd !!flprec !!rdprec mxflbf!!
         mnflbf!!);

global '(!!plumax !!plumin !!timmax !!timmin !!maxflbf !!minflbf
         !!fleps1 !!fleps2 !!flint !!maxbflexp !!maxarg);

global '(rd!-tolerance!* cr!-tolerance!* yy!! bfz!* !!smlsin);

switch rounded;

%Set value for !!flprec. It never changes.
!!flprec := !!nfpd - 3;

!!smlsin := 10.0^-(2+!!flprec);

symbolic procedure logfp x;
  % floating log of x**(1/n) using bfloat logic as boost.
  (log(m/float lshift(1,p))+(p+ep!: x)*!!log2)
    where p=(preci!: x - 1) where m=mt!: x;

symbolic procedure roundconstants;
   <<!!plumax := 2.0**(!!maxbflexp -1);
     !!minflbf := invbf(!!maxflbf := make!:ibf (1,!!maxbflexp));
    % plumin must be large enough to avoid underflow from difference.
     !!plumin := 10.0**!!flprec/!!plumax;
     !!timmin := 1/(!!timmax := sqrt(!!plumax));
     !!maxarg := logfp !!maxflbf>>;

switch bfspace,numval,roundbf; % norndbf.

!*bfspace := nil;
!*numval := t;

put('roundbf,'simpfg,'((t (roundbfon)) (nil (roundbfoff))));

symbolic procedure roundbfon; !*!*roundbf := t;

symbolic procedure roundbfoff; !*!*roundbf := !!rdprec > !!flprec;

%  put('rounded,'package!-name,'arith);  % Use if ARITH autoloaded.

domainlist!* := union('(!:rd!:),domainlist!*);

put('rounded,'tag,'!:rd!:);
put('!:rd!:,'dname,'rounded);
flag('(!:rd!:),'field);
put('!:rd!:,'i2d,'i2rd!*);
put('!:rd!:,'minusp,'rd!:minusp);
put('!:rd!:,'plus,'rd!:plus);
put('!:rd!:,'times,'rd!:times);
put('!:rd!:,'difference,'rd!:difference);
put('!:rd!:,'quotient,'rd!:quotient);
put('!:rd!:,'zerop,'rd!:zerop);
put('!:rd!:,'onep,'rd!:onep);
put('!:rd!:,'prepfn,'rd!:prep);
put('!:rd!:,'prifn,'rd!:prin);
put('!:rd!:,'minus,'rd!:minus);
put('!:rd!:,'rootfn,'rd!:root);
put('!:rd!:,'!:rn!:,'!*rd2rn);
put('!:rn!:,'!:rd!:,'!*rn2rd);

symbolic procedure round!* x;
   % Returns actual number representation, as either float or bfloat.
%   retag cdr x;
   if float!-bfp x then rd2fl x else x;

symbolic procedure mkround u;
   % inverse operation to round!*, i.e. tags a naked float
   if atom u then make!:rd u else u;

%symbolic procedure roundbfp; !*roundbf or !!rdprec > !!flprec;

symbolic procedure print!-precision n;
   % Set the system printing precision !:print!-prec!:.
   % Returns previous value.
   begin scalar oldprec;
      if n=0 then return !:print!-prec!:;
      if n<0 then
         << oldprec := !:print!-prec!:;
            !:print!-prec!: := nil;
            return oldprec >>;
      if n > !:prec!: then
         << msgpri(nil,"attempt to set print!-precision greater than",
                       "precision ignored",nil,nil);
            return nil >>;
      oldprec := !:print!-prec!:;
      !:print!-prec!: := n;
      return oldprec
   end;

symbolic procedure print_precision n;
   % Alternative name.
   print!-precision n;

symbolic procedure precision0 n;
  % called from algebraic call of precision.
   if n member '((nil) () (reset))
      then <<rootacc!#!# := nil; precision !!flprec>>
   else if cdr n
     or not numberp(n := prepsq simp!* aeval {'fix,prepsq simp!* car n})
     or n<0 then
       rerror(arith,5,"positive numeric value or `RESET' required")
   else <<if n>0 then rootacc!#!# := max(n,6); precision n>>;

put('precision,'psopfn,'precision0);

symbolic procedure precision n;
   % Set the system precision !!rdprec, bfloat precision !:prec!:,
   % and rd!:onep tolerance. Returns previous value.
   <<if not numberp n or n<0
       then rerror(arith,6,"positive number required");
     precision1(n,t)>>;

!!log2of10 := log 10 / log 2;

symbolic procedure decprec2internal p;
   ceiling(p * !!log2of10) + 3;

% symbolic procedure internal2decprec p;
%    floor ((p - 3) / !!log2of10);

symbolic procedure precision1(n,bool);
   begin scalar oldprec;
      if n=0 then return !!rdprec;
      if bool then rmsubs();  % So that old results are resimplified.
      oldprec := !!rdprec;
      !:prec!: :=
        (!!rdprec := if !*roundbf then n else max(n,minprec!#))+2;
      if !:print!-prec!: and n < !:print!-prec!:+2
         then !:print!-prec!: := nil; %unset
      !:bprec!: := decprec2internal !:prec!:;
      epsqrt!* := make!:ibf(1, -!:bprec!:/2);
      rd!-tolerance!* := make!:ibf(1, 6-!:bprec!:);
      cr!-tolerance!* := make!:ibf(1, 2*(6-!:bprec!:));
%     if !!rdprec <= !!flprec then
%        <<!!fleps1 := 1.0/float(2.0**(!:bprec!: - 2));
%          !!fleps2 := !!fleps1**2>>;
      !*!*roundbf := !!rdprec > !!flprec or !*roundbf;
      return oldprec end;

flag('(print!-precision),'opfn); % Symbolic operator print!-precision.
flag('(print_precision),'opfn);  % Symbolic operator print_precision.

symbolic procedure !*rd2rn x;
 % Converts a rounded number N into a rational to the system precision.
 % Elegant form: uses both rd2rn1 and realrat... and choses the best,
 %  but uses a heuristic to avoid the extra work when not needed.
   begin scalar n,p,r,r1,r2,d1,d2,ov;
     if rd!:zerop x then return '!:rn!: . (0 . 1);
     p := precision 0;
     r := rd2rn1 x;
     r1 := '!:rn!: . r;
     if abs car r<10 or cdr r<10
       or 2*max(length explode cdr r,length explode abs car r)<p+1
         then go to ret;
     r2 := '!:rn!: . realrat bftrim!: rd!:forcebf x;
     precision(2+p);
     d1 := !:difference(x,r1); if !:minusp d1 then d1 := !:minus d1;
     d2 := !:difference(x,r2); if !:minusp d2 then d2 := !:minus d2;
     if !:zerop d2 or !:minusp !:difference(d2,d1) then ov := t;
     precision p;
ret: return if ov then r2 else r1 end;

symbolic procedure rd2rn1 n;
   if float!-bfp n then ft2rn1 rd2fl n else bf2rn1 n;

symbolic procedure bf2rn1 n;
  % Here, the nonzero input n is always a binary bigfloat
   begin scalar negp,a,p0,p1,q0,q1,w,flagg,nn,r0,r1;
      if mt!: n<0 then <<negp := t; n := minus!: n>>;
      nn := n;
 top: a := ((if d=0 then m else lshift(m,d))
              where m=mt!: n,d=ep!: n);
      n := difbf(n,normbf i2bf!: a);
      if not flagg
        then <<flagg := t; p0 := 1; p1 := a; q0 := 0; q1 := 1>>
       else <<w := p0 + a*p1; p0 := p1; p1 := w; r0 := r1;
              w := q0 + a*q1; q0 := q1; q1 := w>>;
      r1 := abs!: difbf(nn,divbf(i2bf!: p1,i2bf!: q1));
     % temporary write statement here
    % if !*trrd2rn1 then << write p1 . q1," -> ",r1; terpri()>>;
      if bfzerop!: n or bfzerop!: r1
          then return if negp then (-p1) . q1 else p1 . q1
       else if r0 and not greaterp!:(r0,r1)
          then return if negp then (-p0) . q0 else p0 . q0;
      n := invbf n;
      go to top
  end;

symbolic procedure !*rn2rd u;
   % Converts the (tagged) rational u/v into a (tagged) rounded
   % number to the system precision, after testing to number
   mkround chkrn!* r2bf cdr u;

minprec!# := min(6,!!flprec-2);

precision1(!!flprec,nil);        % Initial value = effective float prec.

%  !!fleps1 seems to be a fixed value 2^(-44) always...

%!!fleps1 := 1.0/float(2.0**(!:bprec!: - 6));
!!fleps1 := 2.0**(6 - !:bprec!:);
!!fleps2 := !!fleps1**2;

symbolic procedure precmsg pr;
   if pr>!!rdprec then
      <<msgpri(nil,"precision increased to",pr,nil,nil);
        precision1(pr,t)>>;

symbolic procedure rd!:simp u;
   if null atom u and car u=0 then nil ./ 1
    else if null dmode!* or dmode!* eq '!:gi!:
     then (if eqcar(x,'!:rn!:) then cdr x else x ./ 1)
           where x = !*rd2rn make!:rd u
    else if dmode!* memq '(!:rd!: !:cr!:)
     then (mkround convprec!* u) ./ 1 % Must call convprec!*, since
                                      % precision may have changed.
    else (if y then !*d2q apply1(y,make!:rd u)
           else dmoderr('!:rd!:,dmode!*))
          where y = get('!:rd!:,dmode!*);

put('!:rd!:,'simpfn,'rd!:simp);

symbolic procedure rndbfon; if not !*norndbf then
   <<!*!*roundbf := t;
     if !:prec!:<!!flprec+3 then
         <<!*roundbf := t;
           lprim "ROUNDBF turned on to increase accuracy">>>>;

symbolic procedure i2rd!* u;
% Converts integer U to tagged rounded form.
 mkround chkint!* u;

symbolic procedure chkint!* u;
    if !*!*roundbf then bfloat u else
     ((if floatp u then u   % Added by ACN to make i2rd!* work with floats.
       else if msd!: x <= !!maxbflexp then float u
       else <<rndbfon(); bfloat u>>) where x=abs u);

mnflbf!! := invbf(mxflbf!! := make!:ibf (1, 800));

symbolic procedure chkrn!* u;
   if !*!*roundbf then u else bf2flck u;

symbolic procedure bf2flck u;
   if !*!*roundbf then u
   else if mt!: u=0 then 0.0 else
    ((if not grpbf(!!minflbf,r) and not grpbf(r,!!maxflbf)
         then bf2flr u
      else <<rndbfon(); u>>) where r := abs!: u);

symbolic procedure convchk x;
   if !*!*roundbf then if atom x then bfloat x else x
   else if atom x then x else bf2flck x;

symbolic procedure convprec!* u;
   convchk retag u;

symbolic procedure convprec u; convchk round!* u;

symbolic procedure rd!:minusp u;
  % bfminusp round!* u;
   if float!-bfp u then minusp rd2fl u else minusp!: u;

symbolic procedure convprc2(u,v);
   <<u := convprec u; yy!! := convprec v;
     if !*roundbf then <<yy!! := bfloat yy!!; bfloat u>> else u>>;

symbolic procedure rdzchk(u,x,y);
 if atom u then
    if u=0.0 or x>0.0 and y>0.0 or x<0.0 and y<0.0 then u
    else if abs u<(abs x)*!!fleps1 then 0.0 else u
 else
    if mt!: u=0 or mt!: x>0 and mt!: y>0 or mt!: x<0 and mt!: y<0 then u
    else if lessp!:(abs!: u,times!:(abs!: x,rd!-tolerance!*)) then bfz!*
    else u;

symbolic procedure rd!:plus(u,v);
  (if not !*!*roundbf and atom cdr u and atom cdr v
      and (z := safe!-fp!-plus(cdr u,cdr v)) then make!:rd z else
   begin scalar x,y;
      x := convprc2(u,v); y := yy!!;
      u := if not atom x then plubf(x,y) else
#if (member 'csl lispsystem!*)
% Pretty-well ever since IEEE arithmetic has been in use CSL has probably
% just overflowed to give an IEEE infinity, and has not raised an exception.
         <<z := x + y;
           if fp!-infinite z
             then <<rndbfon(); plubf(x := bfloat x,y := bfloat y)>>
             else z>>;
#else
         <<z := errorset!*(list('plus2,mkquote x,mkquote y),nil);
           if errorp z
             then <<rndbfon(); plubf(x := bfloat x,y := bfloat y)>>
             else car z>>;
#endif
      return mkround rdzchk(u,x,y) end) where z=nil;

symbolic procedure rd!:difference(u,v);
  (if not !*!*roundbf and atom cdr u and atom cdr v
      and (z := safe!-fp!-plus(cdr u, safe!-fp!-minus cdr v)) then
       make!:rd z else
   begin scalar x,y;
      x := convprc2(u,v); y := yy!!;
      u := if not atom x then difbf(x,y) else
#if (member 'csl lispsystem!*)
         <<z := x - y;
           if fp!-infinite z
             then <<rndbfon(); difbf(x := bfloat x,y := bfloat y)>>
             else z>>;
#else
         <<z := errorset!*(list('difference,mkquote x,mkquote y),nil);
           if errorp z
             then <<rndbfon(); difbf(x := bfloat x,y := bfloat y)>>
             else car z>>;
#endif
      return mkround rdzchk(u,x,if atom y then -y else minus!: y) end)
   where z=nil;

symbolic procedure rd!:times(u,v);
  (if not !*!*roundbf and atom cdr u and atom cdr v
      and (z := safe!-fp!-times(cdr u,cdr v)) then make!:rd z else
   begin scalar x,y;
      x := convprc2(u,v); y := yy!!;
      return mkround if not atom x then timbf(x,y) else
#if (member 'csl lispsystem!*)
         <<z := x*y;
           if fp!-infinite z then <<rndbfon(); timbf(bfloat x,bfloat y)>>
              else z>> end) where z=nil;
#else
         <<z := errorset!*(list('times2,mkquote x,mkquote y),nil);
           if errorp z then <<rndbfon(); timbf(bfloat x,bfloat y)>>
              else car z>> end) where z=nil;
#endif

symbolic procedure rd!:quotient(u,v);
  if !:zerop v then rerror(arith,7,"division by zero") else
  (if not !*!*roundbf and atom cdr u and atom cdr v
      and (z := safe!-fp!-quot(cdr u,cdr v)) then make!:rd z else
   begin scalar x,y;
      x := convprc2(u,v); y := yy!!;
      if atom x and zerop y then rdqoterr();
      return mkround if not atom x then
         if mt!: y=0 then rdqoterr() else divbf(x,y)
         else
#if (member 'csl lispsystem!*)
           <<z := x/y;
% Here  use the test "not fp!-finite" which would notice a NaN as well
% as infinities. That is because 0.0/0.0 might generate a NaN (although
% at present it raises an exception whhich would then not be caught here).
% This is a bit hypothetical because the case of dividion by 0.0 is trapped
% a few libes above here!
             if not fp!-finite z then <<rndbfon(); divbf(bfloat x,bfloat y)>>
                else z>> end) where z=nil;
#else
           <<z := errorset!*(list('quotient,mkquote x,mkquote y),nil);
             if errorp z then <<rndbfon(); divbf(bfloat x,bfloat y)>>
                else car z>> end) where z=nil;
#endif

symbolic procedure rdqoterr; error(0,"zero divisor in quotient");

% There are three functions here - safe-!fp!-plus, times and quot. They
% must be given floating point arguments and they return the sum, product
% or quotient of the arguments. If the result would either overflow to
% yield an IEEE infinity or underflow to yield a sub-normalised number
% then they return nil. I observe that sometimes even if a result is
% too small to be normalised it can be 100% accurate. I will neverthless
% reject all cases where the result is a non-zero sub-normalised value.
%
% Earlier versions of these procedures where to various extents built in to
% PSL and CSL, and were more conservative, returning nil for some calculations
% that fall well short of underflow or overflow. The versions here now
% insist that 64-bit IEEE arithmetic is used, and build in definite ideas
% related to the exact range of numbers supported there. A consequence is
% that earlier (eg) VAX and IBM360 floating point models are no longer
% supported. Also any Lisp that used 32-bit rather than 64-bit IEEE floats
% would be out of luck.
%
% A real issue for the code here is that at the time that thie is being
% written PSL treats overflow as and error (rather than generating an
% IEEE infinity). I wish to avoid any such errors. So in the PSL case
% I test the values of the operands. For addition there could only be
% overflow if signs match (so I have two sign tests as overhead). For
% multiplication and division I compare against 2^511, which is a value
% whose square is still within range. The overall effect is a messy split
% on cases, but each path through it has only 3 or 4 extra arithmetic
% operations.

% The value "-0.0" can cause trouble as regards branch cuts for complex
% functions, or at least its handling calls for care there. So FOR NOW I
% will set !*nonegzero to true and these primitives will then not
% create that value, and they will cause it to turn into a +0.0 on any
% arithmetic. That should preserve old behaviour. But I hope that people
% will experiment with switching this flag off and when eveything works well
% without it then it can be removed.
%

global '(!*nonegzerominus !*nonegzerotimes);
!*nonegzerominus := nil;
!*nonegzerotimes := t;

symbolic procedure safe!-fp!-minus u;
  if !*nonegzerominus and u = 0.0 then 0.0
  else -u;

#if (memq 'csl lispsystem!*)

symbolic procedure safe!-fp!-plus(u, v);
  begin
    scalar r;
% CSL (and Jlisp, which uses this code too) add two huge numbers an IEEE
% infinity is generated rather than an exception.
    r := u + v;
% If the result was exactly 0.0 all is well. Well there is hidden delicacy
% here in that -0.0 + -0.0 will return -0.0 (but 0.0 + -0.0 and -0.0 + 0.0
% both return 0.0). I do not have a !*nonegzeroplus because the only way that
% safe!-fp!-add could possibly give a -0.0 input would be if both inputs
% had been -0.0.
    if r = 0.0 then return r
% If the result is sub-normalised I reject it.
    else if r < !!minnorm and r > !!minnegnorm then return nil
% The next test is required if behaviour is to be close to that which
% applied prior to this version of the code, but I view it as badly
% arbitrary and rather unsatisfactory and would like to get rid of it! The
% scheme checks if two values had just been subtracted in such a way that
% about 44 leading bits cancel out. In the original code this had been
% implemented as abs r < !!fleps1*abs u where !!fleps1 has the value
% 2.0^(-44), but the test here that sees if adding a small fraction of
% r to u makes no difference avoids the absolute value conversions.
% The largest possible value for the LHS arises if u is the biggest possible
% number and v the most negative possible balue. This is still in range
% (ie it does not overflow to give an infinity). That is a plausible reason
% for the test having a "-" not a "+" in it.
% I *REALLY think that returning 0.0 here rather than the value that would
% naturally be computed is WRONG.
    else if u - r*0.001953125 = u then return 0.0
% I want to test if the result is infinite. To do this I subtract it
% fr4om itself. Any finite number will lead to 0.0, but (infinity-infinity)
% yields a NaN which is not equal to 0.0.
    else if r-r = 0.0 then return r
% ... the result overflowed and r was an IEEE infinity.
    else return nil;
  end;

symbolic procedure safe!-fp!-times(u, v);
  begin
    scalar r;
    r := u * v;
% If the result is sub-normalised or zero I reject it, unless either u or
% v was zero in which case the zero result is proper.
    if r < !!minnorm and r > !!minnegnorm and
       u neq 0.0 and v neq 0.0 then return nil
    else if !*nonegzerotimes and r = 0.0 then return 0.0
% If r is infinite than r-r evaluates to a NaN which will not be equal to
% 0.0.
    else if r-r = 0.0 then return r
    else return nil;
  end;

symbolic procedure safe!-fp!-quot(u, v);
  begin
    scalar r;
    if v = 0.0 then return nil
    else if !*nonegzerotimes and u = 0.0 then return 0.0;
    r := u / v;
    if r < !!minnorm and r > !!minnegnorm and u neq 0.0 then return nil
    else if r-r = 0.0 then return r
    else return nil;
  end;

#else

global '(!!maxfloatq2 !!two511 !!two513);

remprop('!!maxfloatq2, 'constant!?);
remprop('!!two511, 'constant!?);
remprop ('!!two513, 'constant!?);

begin
  scalar r, w;
% I know the numeric value I want expressed in powers of 2, so I compute
% it here building on initial values that are small enough that I can
% be confident that they read in exactly.
  r := 8388608.0;
  w := r*r*r;
  r := r*w*w;
  r := r*r*r;
  r := 8.0*r*r;
% The value I produce here is 2^53-1 times a huge power of 2 and is the
% largest finite IEEE double precision value.
  !!maxfloatq2 := r*(134217728.0*134217728.0-2.0);
  r := 2.0;
  for i := 1:9 do r := r*r;
  !!two511 := r/2.0;
  !!two513 := 2.0*r
end;

put('!!maxfloatq2, 'constant!?, !!maxfloatq2);
put('!!two511, 'constant!?, !!two511);
put('!!two513, 'constant!?, !!two513);

symbolic procedure safe!-fp!-plus(u, v);
% I can only get overflow if u and v have the same sign. If u and
% v are normalised to start with I can only end up with a sub-normal
% number if their signs differ. Note that both +0.0 and -0.0 count as >= 0.0
% and so do not go through the code that checks for underflow.
  if u < 0.0 then
    if v < 0.0 then <<
% I want to see if u+v > would overflow. If u and v are large then I can
% compute u/2 and v/2 with no loss of anything (if say u/2 was sub-normal
% it might lose accuracy here). In this case both operands are negative
% so comparing against half the most negative possible value does the
% checking that I need. It I pass this test it will be safe to perform
% a simple addition.
      if 0.5*u + 0.5*v < -!!maxfloatq2 then nil
      else u + v >>
    else begin
% u and v have different signs, so adding them can not lead to overflow
% but might result in underflow. So do the arithmetic directly and check.
      scalar r;
      r := u + v;
      if r = 0.0 then return r
       else if r < !!minnorm and r > !!minnegnorm then return nil
% As in the CSL case I dislike and would like to remove this next line.
% Note that in the CSL case I only make this extra test if u and v have
% different signs. The calculation performed can never cause an overflow!
% This premature underflow to 0.0 just loses accuracy in a way I find
% really disturbing, but I am leaving the behaviour here as it is for
% compatibility with older versions of the code.
      else if u - r*0.001953125 = u then return 0.0
      else return r
    end
  else if v < 0.0 then begin
% A second case where signs differ. When writing this I felt that the
% duplicated code here was ugly but that adjusting the tree of tests to
% have just one copy of this led to worse mess.
    scalar r;
    r := u + v;
    if r = 0.0 then return r
     else if r < !!minnorm and r > !!minnegnorm then return nil
    else if u - r*0.001953125 = u then return 0.0
    else return r
  end
  else <<
% Adding two positive values.
    if 0.5*u + 0.5*v > !!maxfloatq2 then nil
    else u + v >>;
    
symbolic procedure safe!-fp!-times(u, v);
  begin
% Now the real business. I will have essentially three cases, based on
% the magnitude of the numbers.
% (a) numbers are big and I may risk overflow.
% (b) numbers are small and I may risk underflow.
% (c) numbers are such that I have no great risk.
    scalar u1, v1;
    if !*nonegzerotimes and (u = 0.0 or v = 0.0) then return 0.0;
    if u < 0.0 then u1 := -u else u1 := u;
    if v < 0.0 then v1 := -v else v1 := v;
% I now have the absolute values of the operands. I will check for all
% potential bad cases.
    if u1 < !!two511 then
      if v1 < !!two511 then <<
% Here both numbers are fairly small, so I can afford to multiply them
% directly. Since I have filtered out multiplication by zero I can then
% detect (gradual) underflow with a simple comparison.
        if u1*v1 < !!minnorm and u neq 0.0 and v neq 0.0 then return nil >>
      else <<
% Here u is small but v is big. If I divide v by 2^511 it ends up in the
% range 1 to 2^513, and in particular multiplying by u will not overflow.
% Furthermore it can not underflow either because (v/2^511) is at least 1.0.
        if u1*(v1/!!two511) >= !!two513 then return nil >>
    else if v1 < !!two511 then <<
% Here u is large but v is not... so similar arguments apply.
      if (u1/!!two511)*v1 >= !!two513 then return nil >>
    else <<
% Finally both u and v are less than 2^511 so overflow is not possible,
% but underflow is a risk
      if u1*v1 < !!minnorm and u neq 0.0 and v neq 0.0 then return nil >>;
    return u*v
  end;
    
symbolic procedure safe!-fp!-quot(u, v);
% The logic for division is essentially the same as that for multiplication.
  if v = 0.0 then nil
  else begin
    scalar u1, v1;
    if !*nonegzerotimes and u = 0.0 then return 0.0;
    if u < 0.0 then u1 := -u else u1 := u;
    if v < 0.0 then v1 := -v else v1 := u;
% I now have the absolute values of the operands.
    if u1 < !!two511 then
      if v1 > 1.0/!!two511 then <<
% Divide a not huge number by a not tiny one, so quotient will not
% overflow, but could underflow.
        if u1/v1 < !!minnorm and u neq 0.0 then return nil >>
      else <<
% Here v is reasonable but v is tiny.
        if u1/(v1*!!two511) >= !!two513 then return nil >>
    else if v1 > 1.0/!!two511 then <<
% Here u is large but v is not too tiny...
      if (u1/!!two511)/v1 >= !!two513 then return nil >>
    else <<
% Finally u is big and v is tiny...
      if u1/v1 < !!minnorm and u neq 0.0 then return nil >>;
    return u/v;
  end;
    
#endif % PSL

symbolic procedure rd!:zerop u;
  % bfzp round!* u;
   if float!-bfp u then zerop rd2fl u else mt!: u = 0;

symbolic procedure rd!:minus u;
  % mkround bfminus round!* u;
   if float!-bfp u then fl2rd (safe!-fp!-minus rd2fl u) else minus!: u;

symbolic procedure rd!:onep u;
   % We need the tolerance test since some LISPs (e.g. PSL) can print
   % a number as 1.0, but it doesn't equal 1.0!
   if float!-bfp u then abs(1.0 - rd2fl u)<!!fleps1
    else equal!:(bfone!*,bftrim!: u);

symbolic procedure rd!:root(u,n);
   if float!-bfp u then fl2rd expt(rd2fl u,recip float n)
    else texpt!:any(u,quotient!:(bfone!*,i2bf!: n));

% Since decimal input -> :rd: in all dmodes, dmode!* must be used to
% determine whether to round to current precision,  but input never gets
% truncated, since precision is always increased at input time.
% to avoid inaccuracies in floating point representation, rd!:prep
% returns values in bfloat format.

symbolic procedure rd!:prep u;
   if !*noconvert then rdprep1 u
    else if rd!:onep u then 1
   else if rd!:onep rd!:minus u then -1 else rdprep1 u;

%symbolic procedure rdprep1 u;
%   if float!-bfp u then
%     if not dmode!* memq '(!:rd!: !:cr!:) or !*!*roundbf
%       then round!:mt(bfloat rd2fl u,min(!:bprec!:,!!nbfpd))
%      else if !:bprec!:>!!nbfpd then u
%      else fl2rd bf2flr round!:mt(bfloat rd2fl u,!:bprec!:)
%    else round!:mt(u,!:bprec!:);

symbolic procedure rdprep1 u;
   % Using cdr u to get actual float leads to various glitches.
   if float!-bfp u then u else round!:mt(u,!:bprec!:);

symbolic procedure rd!:prin u;
   if float!-bfp u and not fp!-finite rd2fl u then prin2!* rd2fl u
   else 
  % Printed output is rounded to 2 fewer places than internal value.
   bfprin!: bftrim!: rd!:forcebf u;

symbolic procedure rd!:explode u;
   bfexplode0 bftrim!: rd!:forcebf u;

initdmode 'rounded;

put('evalf,'psopfn,'evalf0);

procedure evalf0(u);
   % Return first argument as a float wrt. the current precision even
   % with off rounded. Optional second argument overrides the current
   % precision.
   begin scalar sp,w;
      if cdr u then
	 sp := precision0 cdr u;
      if !*rounded then
      	 w := aeval car u
      else <<
      	 on1 'rounded;
      	 w := aeval car u;
      	 off1 'rounded;
      >>;
      if cdr u then <<
	 if cadr u > sp then <<
	    prin2 "*** required accuracy exceeds current precision (";
	    prin2 sp;
	    prin2t ")";
 	    prin2t "*** printing with required accuracy ...";
	    mathprint w;
	    prin2t "*** finished printing"
	 >>;
	 precision0 {sp}
      >>;
      return w
   end;

put('evalnum,'psopfn,'evalnum0);

procedure evalnum0(u);
   % Return the exact algebraic representation of the first argument
   % rounded to the current precision. Optional second argument
   % overrides the current precision.
   begin scalar sp,w;
      if cdr u then
	 sp := precision0 cdr u;
      if !*rounded then
      	 w := aeval car u
      else <<
      	 on1 'rounded;
      	 w := aeval car u;
      	 off1 'rounded;
      	 w := aeval w
      >>;
      if cdr u then
      	 precision0 {sp};
      return w
   end;


symbolic procedure hexfloat1 w1;
% hexfloat may be useful from symbolic mode
  if floatp w1 then
    begin
      scalar w, s, x, m1, m2, m3, m4, n;
      if not numberp w1 then return w1
      else if w1 = 0.0 then return "0.0";
% The test that follows appears to behave OK on at least CSL and PSL on
% some Linux systems...
      if not eqn(w1, w1) then return "NaN"
      else if w1 = 0.5*w1 then <<
         if w1 > 0.0 then return "inf"
         else if w1 < 0.0 then return "-inf"
         else return "NaN" >>;
      if w1 < 0.0 then << s := t; w1 := -w1 >>;
      x := 0;
      n := 0;
      while w1 < 0.5 and n < 5000 do << w1 := 2.0*w1; x := x-1; n := n + 1 >>;
      while w1 >= 1.0 and n < 5000 do << w1 := w1/2.0; x := x+1; n := n + 1 >>;
      if n >= 5000 then return "hexfloat failed";
      w1 := w1 * 32.0;
      m1 := fix w1;
      w1 := w1 - float m1;
      w1 := w1 * 65536.0;
      m2 := fix w1;
      w1 := w1 - float m2;
      w1 := w1 * 65536.0;
      m3 := fix w1;
      w1 := w1 - float m3;
      w1 := w1 * 65536.0;
      m4 := fix w1;
      w1 := w1 - float m4;
      if not zerop w1 then error(1, "Floating point oddity in hexfloat");
% I should now have 5+16+16+16=53 bits of mantissa;
      m1 := explodehex m1;
      m2 := cdr explodehex (m2 + 65536);
      m3 := cdr explodehex (m3 + 65536);
      m4 := cdr explodehex (m4 + 65536);
      w := '!B . explode x;
      w := append(m4, '!_ . w);
      w := append(m3, '!_ . w);
      w := append(m2, '!_ . w);
      w := append(m1, '!_ . w);
      if s then w := '!- . w;
      return list2string w
    end
  else if atom w1 then w1
  else hexfloat1 car w1 . hexfloat1 cdr w1;

symbolic procedure hexfloat u;
% hexfloat tries to be a little generous about its args since it will
% be used in debugging context - but it is inteded to be given a rounded
% valoue and it returns a string...
  begin
    scalar w, w1;
    if numberp u then return hexfloat1 u
    else if atom u then return u
    else <<
      w := aeval car u;
      w1 := prepsq simp w >>;
    if eqcar(w1, '!:rd!:) and floatp cdr w1 then return hexfloat1 cdr w1
    else return w;
  end;

put('hexfloat, 'psopfn, 'hexfloat);

endmodule;

end;
