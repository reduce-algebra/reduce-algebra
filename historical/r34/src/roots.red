module roots;  % Header module for roots package.

% Author: Stanley L. Kameny <valley!stan@rand.org>.

% Revisions:
%
%   10 Oct 90.  Mod 1.92 uses exact arithmetic in bigfloat polynomial
%                evaluation and all polynomial deflations.  Extremely
%                small real or complex parts of roots can be handled.
%                Polynomials with non-unit initial coefficients and
%                almost degenerate polynomials which require high
%                precision calculations cause no trouble.  REDUCE 3.4
%                required.
%
%   16 May 90.  Mod 1.91 adds capability for handling enormous or
%                infinitesimal coefficients, and uses powergcd logic to
%                speed up root finding when powers are all multiples of
%                a power.  Root separation is improved in difficult
%                cases in which close roots occur on different square-
%                free factors and on real and complex factors.  Better
%                starting points for iteration are found in cases where
%                one or more derivatives vanish at usual initial points.
%
%   11 Feb 90.  Mod 1.90 avoids floating point overflows under extreme
%                conditions.  Files are reorganized to be compatible
%                with REDUCE 3.3 and also be operable under the ROUNDED
%                domain logic being developed for REDUCE 3.4.
%
%    8 Oct 89.  Mod 1.89 avoids floating point under- and overflows
%                which could occur in SLISP.
%
%   21 Aug 89.  Mod 1.88 contains improved precision and accuracy
%                logic and a RATROOT switch for obtaining root output
%                in rational format.  Roots are individually output to
%                the accuracy required to separate them.
%
%   19 Jun 89.  Corrected sign change count error in procedures SCH and
%                SCHINF in isoroots module.

create!-package('(roots bfdoer bfdoer2 complxp allroot realroot),
                '(contrib roots));

symbolic procedure roots u; nil;   % To fool loader.

endmodule;


module bfdoer; % routines for doing bfloat arithmetic, mixed float
               % and bf arithmetic, gf and gbf arithmetic, rational
               % arithmetic and fast polynomial manipulations and form
               % conversion.

% Author: Stanley L. Kameny <valley!stan@rand.org>.

% Version and Date:  Mod 1.92, 10 Oct 90.

% Copyright (c) 1988,1989,1990. Stanley L. Kameny. All Rights Reserved.

Comment  support for allroot and realroot modules;

symbolic;

fluid '(!*bftag !*pcmp !*rvar !*strm lims!# mltr!# emsg!# !*xo !*po
 dmode!* polrem!$ !*powergcd !:prec!: !*msg);

fluid '(cpxt!# acc!# sprec!# pfactor!# rr!# ss!# !*xn !*zp);

global '(bfz!* bfone!* bfhalf!* bftwo!* !!eps !!nfpd limlst!#
 logten domainlist!* bfee!* ee);

bfz!* := '!:bf!: . (0 . 0); bfone!* := '!:bf!: . (1 . 0);
bftwo!* := '!:bf!: . (2 . 0); bfhalf!* := '!:bf!: . (5 . -1);
bfee!* := bfloat ee;

smacro procedure mt!: u; cadr u;

smacro procedure ep!: u; cddr u;

symbolic smacro procedure rndpwr x; normbf round!:mt(x,!:prec!:);

symbolic procedure bfrlmult(r,u);
   if atom u then r*u else timbf(bfloat r,u);

symbolic procedure bfabs u; if atom u then abs u else abs!: u;

symbolic procedure bfleqp(a,b); if atom a then a<=b else not grpbf(a,b);

symbolic procedure bfeqp(a,b); if atom a then a=b else
   ((zerop ma and zerop mb or ep!: a=ep!: b and ma=mb)
    where ma=mt!: a,mb=mt!: b);

symbolic procedure bfsgn u;
   if atom u then sgn u
      else if mt!: u=0 then 0 else if minusp!: u then -1 else 1;

symbolic procedure bfmin(u,v);
   if atom u then min(u,v) else min!:(u,v);

symbolic procedure bfsiz p; length explode abs mt!: bfloat p;

symbolic procedure gfconj u; (car u) . (bfminus cdr u);

symbolic procedure rl2gf u;
   if !*bftag then (bfloat u) . bfz!* else (cflot u) . 0.0;

symbolic procedure im2gf u;
   if !*bftag then bfz!* . (bfloat u) else 0.0 . (cflot u);

symbolic procedure gfrlmult(r,u); % multiplies real*gf or real*gbf.
   if atom car u then gffmult(r,u) else gbfmult(bfloat r,u);

symbolic procedure gfeqp(u,v); gfzerop gfdiffer(u,v);

symbolic procedure ncoeffs p;
    begin scalar n,q; integer d;
          for each i in p do
             <<n := car i;
               while d<n  do <<q:= nil . q; d := d+1>>;
               d := d+1; q := (cdr i) . q>>;
          return n . q end;

symbolic procedure rlval(p,r);
 % evaluate real polynomial for floating or bigfloat value.
   if atom p or atom car p then p
      else if bfzp r then (if caar p=0 then cdar p else r2flbf 0) else
   begin scalar c,bf; bf := bfp!: r;
         c := car (p := cdr ncoeffs p);
         for each i in cdr p do
            <<c := if bf then times!:(r,c) else r*c;
              if i then
                 c := (if bf then plus!:(i,c) else c + i)>>;
         return if bf then rndpwr c else c end;

symbolic procedure deflate2 (p,u);
 % deflate real bf polynomial by one pair of gbf roots.
 % no rounding is done.
    begin scalar q,n,b,c,f,g,h,j;
       b := times!:(bftwo!*,gfrl u);
       c := minus!: plus!:(sqr!: gfrl u,sqr!: gfim u);
       g := h := bfz!*; n := car(p := ncoeffs p)-1; p := cdr p;
       while n>0 do
          <<n := n-1;
            f := plus!:(times!:(b,g),times!:(c,h));
            if (j := car p) then f := plus!:(j,f);
            if mt!: f neq 0 then q := (n . f) . q;
            h := g; g := f; p := cdr p>>;
       return q end;

symbolic procedure sqr!: a; times!:(a,a);

symbolic procedure primp p; if atom p then sgn p else
   begin integer d;
         for each y in p do d := gcdn(d,cdr y);
         return for each y in p collect (car y).(cdr y/d) end;

symbolic procedure primpn p;
   begin scalar n,g; n := car p; p := cdr p; g := 0;
         while p and car p=0 do <<p := cdr p; n := n-1>>;
         if n<0 then return 0 else if n=0 then return sgn car p;
         for each y in p do g := gcdn(y,g);
         return n . for each y in p collect y/g end;

symbolic procedure r2flbf u; if !*bftag then r2bf u else r2fl u;
 % translate any real number object to float or bigfloat.

symbolic procedure intdiff p;
   <<if caar p=0 then p := cdr p;
     for each y in p collect (car y-1) . (car y*cdr y)>>;

symbolic procedure bf!!eps;
   begin scalar x; integer n; !!eps := 1.0;
         if !*bftag then <<x := bfone!*;
            repeat <<n := n-1; !!eps := 0.1*!!eps>>
               until equal!:(x,plubf(x,'!:bf!: . (1 . n)))>>
         else <<x := 1.0;
            repeat !!eps := 0.1*!!eps until x + !!eps = x>>;
         return !!eps := 10*!!eps end;

symbolic procedure ratminus r; (-car r) . (cdr r);

symbolic procedure ratdif(r,s); ratplusm(r,ratminus s,nil);

symbolic procedure ratplus(r,s); ratplusm(r,s,nil);

symbolic procedure ratmean(r,s); ratplusm(r,s,t);

symbolic procedure ratplusm(r,s,m);
 % computes sum or mean of two realrats.
   begin scalar ra,rd,sa,sd,a,d,g;
         ra := car r; rd := cdr r; sa := car s; sd := cdr s;
         if rd=sd then <<a := ra+sa; d := rd>> else
         <<g := gcdn(rd,sd); a := sd/g*ra+rd/g*sa; d := rd/g*sd>>;
         if m then d := d+d;
%   ret:
         if a=0 then return (0 . 1);
         g := gcdn(a,d); return (a/g) . (d/g) end;

symbolic procedure ratmin(a,b); if ratlessp(a,b) then a else b;

symbolic procedure ratmax(a,b); if ratlessp(a,b) then b else a;

symbolic procedure ratlessp(a,b); car ratdif(a,b)<0;

symbolic procedure ratleqp(a,b); car ratdif(a,b)<=0;

symbolic procedure listecho(l,n); if n<2 then l else
   begin scalar c; for each x in l do
         <<for i := 1:n do c := append(c, list x)>>; return c end;

symbolic procedure ncpxp p; bfnump p or bfnump cdar p;

symbolic procedure cpxp p; not ncpxp p;

symbolic procedure bfloatem p; if p then
   (<<for each c in p collect (car c) .
       if cp then (bfloat cadr c) . bfloat cddr c else bfloat cdr c>>
   where cp=cpxp p);

symbolic procedure cflotem p;
   <<for each c in p collect (car c) .
      if cp then (cflot cadr c) . cflot cddr c else cflot cdr c>>
   where cp=cpxp p;

symbolic procedure gfdiff p;
 % differentiates the gfform of real or complex polynomial.
   <<if caar p=0 then p:= cdr p;
  if ncpxp p then
     for each a in p collect (car a-1) . bfrlmult(car a,cdr a) else
     for each a in p collect (car a-1) . gftimes(rl2gf car a,cdr a)>>;

symbolic procedure gfval(p,x);
   <<p := if cpxp p then gfcval(p,x) else gfrval(p,x);
     if atom car p and (infinityp car p or infinityp cdr p)
        then error(0,"gfval -> infinity") else p>>;

symbolic procedure gfrval(p,x);
 % evaluate real polynomial for gf or gbf value x.
   if gfzerop x then rl2gf(if caar p=0 then cdar p else 0)
   else if bfzp gfim x then rl2gf rlval(p,gfrl x) else
   begin scalar c;
         c := rl2gf car (p := cdr ncoeffs p);
         for each i in cdr p do
            <<c := gftimesn(x,c);
              if i then c := ((bfplusn(i,car c)) . cdr c)>>;
         return rndpwrxc(x,c) end;

symbolic procedure rndpwrxc(x,c);
   if atom car x then c else (rndpwr car c) . rndpwr cdr c;

symbolic procedure gfcval(p,x);
 % evaluate complex polynomial for gf or gbf value x.
   if gfzerop x then (if caar p=0 then cdar p else rl2gf 0) else
   begin scalar c;
         c := car (p := cdr ncoeffs p);
         for each i in cdr p do
            <<c := gftimesn(x,c); if i then c := gfplusn(i,c)>>;
         return rndpwrxc(x,c) end;

symbolic procedure bfplusn(u,v); if atom u then u+v else plus!:(u,v);

symbolic procedure gfplusn(u,v);
   if atom car u then gffplus(u,v) else
     (plus!:(car u,car v)) . plus!:(cdr u,cdr v);

symbolic procedure gftimesn(u,v);
   if atom car u then gfftimes(u,v) else
     begin scalar ru,iu,rv,iv;
        ru := car u; iu := cdr u; rv := car v; iv := cdr v;
        return (difference!:(times!:(ru,rv),times!:(iu,iv))) .
           plus!:(times!:(ru,iv),times!:(iu,rv)) end;

symbolic procedure minbound (p,o);
 % estimate min root distance from origin o for polynomial p.
   <<p := if atom (p := automod p) then nil else minbnd1(p,o);
     !*bftag := bf; outmode p>> where bf=!*bftag,acc!#=6;

symbolic operator maxbound,minbound;

symbolic procedure maxbound p; outmode maxbnd1 p;

symbolic procedure maxbnd1 p;
 % maxbound of roots of real or complex float polynomial,
 % in floating point avoiding under/ and over/ flows.
   begin scalar nc,bf,m,pr;
      bf := !*bftag; pr := !:prec!:;
      if atom (p:= gffinit p) then return nil;
      !:prec!: := 8; p := bfloatrd p;
      nc := ncpxp p; p := reverse p;
      !*bftag := bf;
      m := bfrlmult(2,maxbdbf(p,nc));
      !:prec!: := pr;
      return m end;

symbolic procedure minbnd1(p,org);
   begin scalar b,c; b := !*bftag;
         setflbf bfp!: if not bfnump(c := cdar p) then car c else c;
         org := a2gf org;
         if ncpxp p then if bfzp gfim org then org := gfrl org else
            p := for each r in p collect (car r) . rl2gf cdr r;
         p := bfinverse maxbnd1 invpoly orgshift(p,org);
         setflbf b; return p end;

symbolic procedure maxbdbf(p,nc);
   begin scalar an,al,m,mm,n;
   % selection of critical term uses bfloat arithmetic; final
   % computation uses float.
      n := car (an := car p);
      an := if nc then bfabs cdr an else bfsqrt gfrsq cdr an;
      while (p := cdr p) do
       <<al := if nc then bfabs cdar p else bfsqrt gfrsq cdar p;
         mm := not zerop mt!: al and logrtn(divbf(al,an),n-caar p);
         if not m or mm and mm>m then m := mm>>;
      m := fl2bfexp m;
      return m end;

symbolic procedure bfloatrd p;
   <<for each c in p collect (car c) .
      if cp then (rndpwr bfloat cadr c) . rndpwr bfloat cddr c
         else rndpwr bfloat cdr c>>
   where cp=cpxp p;

symbolic procedure logrtn(x,n);
  % floating log of x**(1/n) using bfloat logic as boost.
  (y/n) where y=log(m/10.0**p)+(p+ep!: x)*logten
        where p=length explode m-1 where m=mt!: x;

symbolic procedure fl2bfexp m; if !*bftag then expfl2bf m else exp m;

symbolic procedure expfl2bf m; if m<0 then invbf expfl2bf(-m) else
   exptbf(bfee!*,mi,bfloat exp mf) where mf=m-mi where mi=fix2 m;

symbolic procedure ungfform p;
   begin scalar r; integer n;
      if caar p=0 then
         <<if bfnzp cdar p then r := cdar p; p := cdr p>>;
      for each i in p do
        if bfnzp cdr i then r := (((!*rvar or 'x) . car i) . cdr i) . r;
      return r end;

symbolic procedure gtag c;
   if fixp c then '!:gi!: else if floatp c then '!:gf!: else '!:gbf!:;

symbolic procedure gzero c;
   if fixp c then 0 else if floatp c then 0.0 else bfz!*;

symbolic procedure simpgi u; ('!:gi!: . u) ./ 1;

put('!:gi!:,'simpfn,'simpgi);

symbolic procedure simpgf u;
   ('!:gf!: . (('!:ft!: . car u) . ('!:ft!: . cdr u))) ./ 1;

put('!:gf!:,'simpfn,'simpgf);

symbolic procedure simpgbf u; ('!:gbf!: . u) ./ 1;

put('!:gbf!:,'simpfn,'simpgbf);

symbolic procedure !*i2gf u;
   '!:gf!: . (cflot u .  0.0);

symbolic procedure rlrtno p;
   <<sturm1 p; p := schinf(-1)-schinf 1; !*strm := nil; p>>;

symbolic procedure roots p; <<lims!# := nil; uniroots(p,1)>>;

symbolic operator roots;

symbolic procedure rlrootno a;
   <<mltr!# := t; lims!# := limchk cdr a; ckprec car a;
     a := rlrtno2 if lims!#=t then 0 else car a;
     restorefl(); mltr!# := nil; a>>;

put('rlrootno,'psopfn,'rlrootno);

symbolic procedure realroots a;
   <<lims!# := limchk cdr a;
     uniroots(if lims!#=t then 0 else car a,0)>>;

put('realroots,'psopfn,'realroots);

symbolic procedure isolater p;
   <<mltr!# := t; lims!# := limchk cdr p; ckprec car p;
     p := isolatep if lims!#=t then 0 else car p;
     restorefl(); mltr!# := nil; outril p>>;

put('isolater,'psopfn,'isolater);

symbolic procedure outril p;
   'list . for each i in p collect
         'list . list(mk!*sq car i,mk!*sq cdr i);

symbolic procedure gfrootset(p,r,b);
 if errorp(r := errorset!*(list('gfrootfind,mkquote p,mkquote r),nil))
    then gfsetmsg(r,b,'gfrootfind) else car r;

symbolic procedure gfsetmsg(r,b,n);
   if (r := emsg!#) then <<emsg!# := nil; rerror(roots,1,r)>>
   else if b
    then rerror(roots,2,list(n,": error in bfloat computation"))
   else nil;

symbolic procedure sch z;
   begin scalar v,v1; integer r;
         v := sgn1(car !*strm,z);
         if v=0 and mltr!# then return schplus z;
         for each q in cdr !*strm do
            <<if v*(v1:= sgn1(q,z))<0 then r := r+1;
              if v1 neq 0 then v := v1>>;
         return r end;

symbolic procedure mkratl l; for each a in l collect
   if member(a,limlst!#) then a else
   if eqcar(a,'list) then
      if member(a := cadr a,limlst!#) then a else mkxcl realrat a
      else realrat a;

symbolic procedure mkxcl a; if xclp a then a else 'list . a;

symbolic procedure xclp a; eqcar(a,'list);

symbolic procedure exclude x; list('list,x);

symbolic operator exclude;

symbolic procedure gfnewtset(n,p,y,xo,b);
   begin scalar y1,b; if (b := !*bftag) then go to ret;
      if not atom car y then go to mbf;
      if not errorp (y1 := errorset!*(
           list('gfns1,n,mkquote p,mkquote y,mkquote xo),nil))
         then return car y1;
 mbf: gfsetmsg(y1,b,'gfnewton);
      p := makebfp(p,xo); xo := !*xo; y := gf2bf y;
 ret: y := gfns1(n,p,y,xo); !*bftag := b; return y end;

symbolic procedure gfns1(n,p,y,xo);
  <<!*xo := xo; trmsg13(n,xnshift y,gfval(p,y)); gfnewton(p,y,4)>>;

symbolic procedure nearestroot(p,rr);
 % finds root nearest to r, unless accuroot abort occurs.  r may be
 % real or complex. p can have zero root or multiple roots.
  nrstroot(p,rr,nil);

symbolic procedure gfnewt(p,r,cpx);
   nrstroot(gffinit p,r,if cpx then 0 else t);
   % direct call to gfnewton. If cpx then retain imaginary part, no
   % matter how small.

symbolic procedure gfroot(p,r,cpx);
   nrstroot(gffinit p,r,list if cpx then 0 else t);

symbolic procedure firstroot p; nearestroot(p,0);

symbolic operator firstroot,nearestroot,gfnewt,gfroot;

symbolic procedure multivar y;
   if atom y or car y memq domainlist!*
      or not atom car y and numberp caar y then nil else
   begin scalar x,v,g,w;
   strt: x := numr simp!* y;
   loop: if domainp x then return;
         g := car x;
    lp2: if domainp g then <<x := cdr x; go to loop>>;
         if (w := leadatom g) eq 'i then
            <<(<<if m then off msg; on complex; !*msg := m>>
               where m=!*msg); v := nil; go to strt>>;
         if not v then v := w else if v neq w then return t;
         g := cdr g; go to lp2 end;

symbolic procedure ckacc(q,p,r);
   if not(r and caar lastpair p>1 and (rr!#>1 or pfactor!#)) then r
   else if caar lastpair q=1 then
      <<acc!# := cdr(r := accupr1(r,q)); car r>> else
   begin scalar ac,rl,s,nx; rl := bfzp gfim r;
      r := <<accuroot(r,q,!*xo); !*xn>>;
loop: ac := accupr(q,p,r);
      if ac>acc!# then <<acc!# := ac; go to gfr>>;
      if s or ss!#=0 then return r;
      s := t; acc!# := acc!# + ss!#:
 gfr: nx := r; r := <<accuroot(r,q,!*xo); !*xn>>;
      if gfeqp(gf2bf nx,gf2bf r)
         or s and not(rl and not(rl := bfzp gfim r))
         then return r else go to loop end;

symbolic procedure gfadjust x; if !*pcmp or not !*bftag
   or not lessp!:(abs!: gfrl x,sprec!#) then x else im2gf gfim x;

symbolic procedure xnshift x;
   if gfzerop !*xo then x else gfadjust gfdiffer(x,!*xo);

symbolic procedure unshift x;
   if gfzerop !*xo then x else gfadjust gfplus(x,!*xo);

symbolic procedure gfexit(pf,nx,x0,m);
 if bfzp pf then <<trmsg1 (m,nx); t>>
   else if gfeqp(unshift nx,unshift x0) then <<trmsg3 (m,nx); nx>> else
   begin scalar rl,r1,r0,im,i1,i0;
      r1 := bfloat(rl := gfrl(nx := unshift nx));
      i1 := bfloat(im := gfim nx);
      r0 := bfloat gfrl(x0 := unshift x0); i0 := bfloat gfim x0;
     return
       if eqprts(r1,r0) then
          if mt!: i1*mt!: i0<0 then rl2gf rl
          else if cvt2(i1,i0) then zptst rl2gf rl else nil
       else if eqprts(i1,i0) then
          if mt!: r1*mt!: r0<0 then im2gf im
          else if cvt2(r1,r0) then zptst im2gf im else nil
       else <<!*zp := 0; nil>>  end;

symbolic procedure zptst x;
   if !*zp>4 then x else <<!*zp := !*zp+1; nil>>;

symbolic procedure eqprts(a,b); bfnzp a and (equal!:(a,b) or cvt5(a,b));

symbolic procedure powerchk p;
  % reduce degree of polynomial if powergcd > 1.
   <<if !*powergcd and length p>2 then
        for each x in cdr p do g := gcdn(g,car x);
     if g>1 then g . for each x in p collect (car x/g) . cdr x>>
   where g=0; % returns (powergcd . <reduced polynomial>) or nil.

%unfluid '(!*pcmp !*rvar !*strm lims!# mltr!# emsg!# !*xo !*po);

%unfluid '(cpxt!# acc!# sprec!# pfactor!# rr!# ss!# !*xn !*zp);

endmodule;


module bfdoer2; % routines for doing bfloat arithmetic, mixed float
                % and bf arithmetic, gf and gbf arithmetic, rational
                % arithmetic and fast polynomial manipulations and form
                % conversion, part 2.

% Author: Stanley L. Kameny <valley!stan@rand.org>.

% Version and Date:  Mod 1.92, 10 Oct 1990.

% Copyright (c) 1988,1989,1990. Stanley L. Kameny. All Rights Reserved.

Comment  support for allroot and realroot modules;

symbolic;

fluid '(!*trroot !*rootmsg !*multiroot !*bigfloat !*roundbf !:prec!:
  !*msg !*bftag !*automode !*sqfree !*ratroot !*nosqfr rootacc!#);
!*automode := t;
switch trroot,rootmsg,multiroot,ratroot;
global '(!!eps !!nfpd !!flim !!flint bfz!*);
global '(!!shbinfl rootsreal rootscomplex auton!* den!*);
flag('(rootsreal rootscomplex),'share);
fluid '(!*pfsav pr!# ra!# acc!# prec!# bfl!# emsg!# eps!#);
fluid '(!*xmax !*xmax2 !*rvar nwmax!# lgmax!# nozro!# !1rp);
fluid '(!*xo !*po !*cmplex !*pcmp !*multrt lgmax!# nwmax!#);
fluid '(!*keepimp sqf!# exp!# sprec!# rprec!# !*bfsh vars!# incmsg!$
 cpx!# pfactor!# rr!# pnn!# nn!# prx!# rlrt!#);

smacro procedure ep!: u; cddr u;
smacro procedure mt!: u; cadr u;
smacro procedure preci!: u; length explode abs mt!: u;

symbolic procedure pmsg a;
   if !*rootmsg and !*trroot then <<write a; terpri()>>;

symbolic procedure gf2flt a;
  % force into float format, except if !shbinfl or float error.
   if !*roundbf or !!shbinfl then a else
      <<(if errorp gx then a else car gx)
         where gx=errorset!*(list('gf2fl,mkquote a),nil)>>;

symbolic procedure gfbfxn nx;
 gf2bf if !*bfsh then
      if bfnump nx then bfplus(nx,gfrl !*xo) else gfrl unshift nx
   else if bfnump nx then nx else unshift nx;

symbolic procedure trmsg1 (a,nx);
   if !*trroot then <<write a,",px=0 => ",gfbfxn nx; terpri()>>;

symbolic procedure trmsg2 (a,xn,px);
   if !*trroot then <<write a,"-> xn=",gfbfxn xn; trmsg5(xn,px)>>;

symbolic procedure trmsg3 (a,xn);
   if !*trroot then <<write a,",xn=x0 => ",gfbfxn xn; terpri()>>;

symbolic procedure trmsg4 req; if !*trroot then
   <<write "number of "; if nozro!# then write "nonzero ";
     write "real roots = ",req; terpri()>>;

symbolic procedure trmsg5(nx,px);
   <<terpri(); write "      "," px=",px; terpri()>>;

symbolic procedure trmsg6(k,xn,px);
   if !*trroot then
      <<write "mean of ",k," xn->",gfbfxn xn; trmsg5(xn,px)>>;

symbolic procedure trmsg7 xn;
   if !*trroot then <<write "best value =",gfbfxn xn; terpri()>>;

symbolic procedure trmsg8;
   if !*trroot then
      <<if !*bftag then write ":prec: = ",!:prec!:
           else write "!nfpd = ",!!nfpd; terpri()>>;

symbolic procedure trmsg9 a;
   lprim list("Roots precision increase to ",a);

symbolic procedure trmsg10 a;
   if !*trroot or !*rootmsg then lprim list(a," abort -> ");

symbolic procedure trmsg11 (xn,n);
   if !*trroot then <<write "n=",n," -> ",gfbfxn xn; terpri()>>;

symbolic procedure trmsg12 z;
   if !*trroot then <<write "acc(",acc!#,") ->",outtrim z; terpri()>>;

symbolic procedure trmsg13(n,xn,px);
   if !*trroot then <<write "n=",n,",xn=",gfbfxn xn; trmsg5(xn,px)>>;

symbolic procedure trmsg17 y;
   lprim list("Roots ",y," equal to acc ",acc!#);

symbolic procedure nwterr m;
 if m>nwmax!# then
    <<restorefl(); emsg!# := list("max NWT limit",nwmax!#,"exceeded");
      error(0,emsg!#)>>;

symbolic procedure lagerr m;
 if m>lgmax!# then
    <<restorefl(); emsg!# := list("max LAG limit",lgmax!#,"exceeded");
      error(0,emsg!#)>>;

symbolic procedure seteps;
 eps!# := '!:bf!: . 1 .-(if !*bftag then !:prec!: else !!nfpd);

symbolic procedure pconstr(m,r);
 % set !*bftag and return equivalent of x^m-r in corresponding form.
   prxflot(if prx!# then max(prx!#,ac) else ac,
      list(0 . if rl then bfminus r else gfminus r,
         m . if rl then 1.0 else rl2gf 1.0))
   where rl=bfnump r,ac=acc!#+2+ceillog m;

symbolic procedure ceillog m; ceiling log10 float m;

symbolic procedure prxflot(pr,p);
   if setflbf(rlrt!# or pr>!!nfpd)
      then <<!:prec!: := pr; bfrndem bfloatem p>>
      else <<!:prec!: := !!nfpd; cflotem p>>;

symbolic procedure smpart y;
   (if mt!: a>0 and mt!: b>0 then
      (if lessp!:(b,times!:(a,c)) then t
       else if lessp!:(a,times!:(b,c)) then 0))
    where a=abs!: round!:mt(gfrl y,5),b=abs!: round!:mt(gfim y,5),
       c := '!:bf!: . 1 . -!:prec!:;

symbolic procedure stuffr(n,v,ar);
 <<pmsg v; while n>0 do <<pt := cdr pt; n := n-1>>; rplaca(pt,v); ar>>
   where pt=ar;

symbolic procedure n2gf p; if atom p then p else
   begin scalar f,n; n := car p;
       for each y in cdr p do
          <<if y and y neq 0 then f := (n . y) . f; n := n-1>>;
       return f end;

symbolic procedure pbfprint x;
   begin scalar n,d,c;
     if not (atom(d := cdar x) or bfp!: d) then
        <<c := 'complex; d := car d>>;
     if floatp d then n := 'float else if fixp d then n := 'fix;
     x := for each p in x collect (car p) . gf2bf cdr p;
     if n then x := n . x; if c then x := c . x; return x end;

symbolic procedure pflupd pf;
   <<!*pfsav := append(lastpair !*pfsav,list pf);
     bfmin(pf,car !*pfsav)>>;

symbolic procedure lbfzro; if !*bftag then bfz!* else 0;

symbolic procedure rootacc x;
   if (x := if numberp x then max(6,abs fix x)) then
     <<precmsg x; rootacc!# := x>>;

symbolic procedure rootprec n;
   rprec!# := if numberp n and abs fix n>!!nfpd then n;

symbolic procedure csize p;
   begin integer n;
     for each c in gffinitr p do n := max(n,xnsiz cdr c); return n end;

symbolic operator rootacc, rootprec, csize;

symbolic procedure ckpzro p;
 % solve for zero roots and reduce p.
   begin scalar c,n; ckprec p;
         if numberp (p := gffinit p) then p := nil
            else if atom p then <<c := '(((0) . 1)); p := nil>>
            else if atom car p then p := nil
            else if (n:= caar p)>0 then go to zrt;
         go to ret;
    zrt: c := list(list 0 . n); % eliminate and solve for zero roots.
       % if there are no other roots, we're done.
         if not p or null cdr p then <<p := nil; go to ret>>;
       % otherwise, reduce polynomial degree.
         p := for each j in p collect (car j-n) . cdr j;
    ret: nozro!# := t; return c . p end;

symbolic procedure ckprec p;
   <<find!!nfpd(); find!!flim(); bf!!eps();
     !*rvar := nil;
     rootsreal := rootscomplex := nil; cpx!# := !*complex;
     if multivar p
       then rerror(roots,3,"Univariate polynomial required");
     bfl!# := !*bftag;
     if not rootacc!# then rootacc 6; acc!# := ra!# := rootacc!#;
     pr!# := !:prec!: := max(!:prec!:,acc!#+2,!!nfpd+2);
     sqf!# := !*sqfree; exp!# := !*exp; !*sqfree := !*exp := t>>;

symbolic procedure restorefl;
   <<!:prec!: := max(pr!#,acc!#+2); precmsg acc!#;
     rootacc!# := ra!#; !*sqfree := sqf!#; !*exp := exp!#;
     if !*complex and not cpx!# then
        (<<if m then off msg; off complex; !*msg := m>> where m=!*msg);
     nozro!# := pr!# := ra!# := sqf!# := exp!# := cpx!# := nil>>;

symbolic procedure mkequal l;
  'list . (for each y in l collect list('equal,!*rvar or 'x,outmode y));

symbolic procedure outmode j;
   if null j then j
   else if bfnump j and bfzp j then 0 else if fixp j then j
   else mk!*sq if !*ratroot then mkgirat j else !*f2q
      if floatp j then '!:rd!: . j
      else if eqcar(j, '!:bf!:) then '!:rd!: . cdr j
      else '!:cr!: . if atom car j then j else (cdar j) . cddr j;

symbolic procedure allout c;
   begin scalar rl,cmp; integer a;
      c := for each j in c collect gf2bf j;
      for each x in c do a := max(a,xnsiz x); acc!# := a;
      restorefl();
      for each x in c do
         if atom x or eqcar(x,'!:bf!:) then rl := x . rl
            else cmp := x . cmp;
      rootscomplex := mkequal reversip cmp;
      rootsreal := mkequal reversip rl; return mkequal c end;

symbolic procedure outecho r;
   allout for each c in r join
      listecho(car c,if !*multiroot then cdr c else 1);

symbolic procedure find!!flim;
   <<!!flim := 0; repeat <<n := n/10; !!flim := !!flim+1>>
       until explode(1.0+n)=explode 1.0; !!flim>> where n=1.0;

symbolic procedure xnsiz x;
   if bfnump x then bfsiz x
   else if bfzp gfim x then bfsiz gfrl x
   else if bfzp gfrl x then bfsiz gfim x else
   <<x := gf2bf x;
     ((max(preci!: car x+e1,preci!: cdr x+e2)-min(e1,e2))
      where e1=ep!: car x,e2=ep!: cdr x)>>;

symbolic procedure outtrim j;
   if !*roundbf or acc!#>!!flim or (not !*automode and bfl!#)
      then gf2bf j else
     ((if errorp d then gf2bf j else car d)
       where d=errorset!*(list('gf2fl,mkquote j),nil));

symbolic procedure minprec; if !*bftag then !:prec!: else !!nfpd;

symbolic procedure bfmax p;
  <<!*xmax := maxbnd1 p;
    ((!*xmax2 := bftimes(m,m))
     where m=if !*bftag then bfloat !*xmax else cflot !*xmax); !*xmax>>;

symbolic procedure nbfout x; normbf bfloat ftout x;

symbolic procedure bfixup x; if !*bftag then gf2bf x else gf2fl x;

symbolic procedure ftout x;
   if atom x then cflot x
   else if eqcar(x,'!:ft!:) or eqcar(x,'!:rd!:) then cdr x else x;

find!!nfpd(); find!!flim();

symbolic procedure cexpand cc;
   begin scalar c;
      for each r in cc do
         <<if (not !*pcmp) and not bfnump car r then
              c := ((gfconj car r) . cdr r) . c; c := r . c>>;
      return c end;

symbolic procedure rootrnd y; rtrnda(y,acc!#);

symbolic procedure rtrnda(y,a);
   if bfzp y then y
   else normbf round!:mt(y,max(a,(acc!#+1)/2,(rootacc!#+1)/2));

symbolic procedure gfrtrnd y;
   (begin scalar b; y := cdr y;
      if bfzp a or bfzp y then go to ret;
      if (b := ep!: a+bfsiz a-ep!: y-bfsiz y)>0
         then return(rtrnda(a,acc!#)).rtrnda(y,acc!#-b)
      else if b<0 then return(rtrnda(a,acc!#+b)).rtrnda(y,acc!#);
 ret: return (rootrnd a).rootrnd y end)
    where a=car y;

symbolic procedure makebfp(p,xo); <<!*xo := gf2bf xo; mkbfgfp p>>;

symbolic procedure mkbfgfp p; <<setflbf t; bfloatem p>>;

symbolic procedure makebf(p,p0,xo);
   <<!*po := bfloatem p0; makebfp(p,xo)>>;

symbolic procedure setflbf b; !*bftag := b;

symbolic procedure gfsqfrf p;
   begin scalar m,cp,q,dmd;
      if caar lastpair p=1 or !*nosqfr then go to nof;
      cp := cpxp(q := mkinteg p);
      dmd := dmode!*; if !*complex then dmd := get(dmd,'realtype);
      m := !*msg; off msg;
      if dmd then eval list('off,mkquote list(dmd := get(dmd,'dname)));
      q := sqfrf if cp then ungffc q else ungfform q;
      if dmd then eval list('on,mkquote list dmd); if m then on msg;
      if cdr q then pfactor!# := t else if cdar q=1 then go to nof;
      !1rp := p1rmult q; return q;
 nof: q := list(p . 1); !1rp := p; return q end;

symbolic procedure automod p;
  % choose float or bigfloat gfform representation of p.
  % round precision if automode is off and rootprec specified.
    if bfnump (p := remode p) then p else
       ((if !*automode or not !*bftag then p else
           <<if rprec!# then !:prec!: := rprec!#;
             for each j in p collect (car j) .
              if cp then (rndpr cadr j).rndpr cddr j else rndpr cdr j>>)
       where cp=cpxp p);

symbolic procedure remode p;
   if bfnump (p := gffinit p) then p else
   begin integer n,s,s2; scalar a,d,m,nl,pr,nc,dd; rr!# := 0;
      if not !*automode or null cdr p then
         <<n := !:prec!:; go to sel>>;
    % determine precision of calculation and set mode.
    % first find minimum precision for normalizing p.
      m := car(d := car lastpair(p := bfloatem p)); d := cdr d;
      for each c in cdr reverse p do n := max(n,xnsiz cdr c);
      pr := !:prec!:;
      !:prec!: := if (nc := bfnump d) and abs mt!: d=1
         or not nc and
            ((a := mt!: car d)=0 and abs(dd := mt!: cdr d)=1 or
              dd=0 and abs a=1) then n else 2+max(n,xnsiz d);
      n := 0;
    % now calculate necessary precision for gfrootfind.
  nl := for each c in cdr reverse p collect xnsiz cdr c;
      for each c in nl do
         <<rr!# := rr!#+1; s := s+c; s2 := s2+c*c; n := max(n,c)>>;
      n := calcprec(m,nn!# := n,rr!#,float s/rr!#,
         if n>1 then float s2/(2*n*(n-1)) else 0);
      if rprec!# then n := max(n,rprec!#);
      pnn!# := n;
      if n>!!nfpd or !*roundbf then go to bfl;
      setflbf nil; !:prec!: := pr;
 cfl: if errorp(d := errorset!*(list('cflotem,mkquote p),nil))
         then go to bfl else return car d;
 sel: if not !*bftag then go to cfl;
 bfl: setflbf t; !:prec!: := n; return bfloatem p end;

symbolic procedure bfnump p; numberp p or bfp!: p;

symbolic procedure gffinit p;
   if not domainp p and numberp caar p then p
   else if numberp p
      or not atom p and member(car p,domainlist!*) then 0
   else reformup if domainp p then
     begin scalar !*msg,cp;
       cp := !*complex; on complex; p := gfform numr simp!* p;
       if not cp then off complex; return p end
     else gfform p;

symbolic procedure clrdenom p; % convert p to integer polynomial.
   <<dmconv0 if !*complex then '!:crn!: else '!:rn!:;
     den!* := conv2gid(p := dmconv1 p,1); conv2gi2 p>>;

symbolic procedure gfform p;
   if domainp p then 0 else if atom caar p then p else
   begin scalar q; !*rvar := mvar p; p := clrdenom p;
loop: if cdar p then q := ((cdaar p) . gfsimp cdar p). q;
      if null (p := cdr p) then return q
      else if domainp p then <<q := (0 . gfsimp p) . q; return q>>
      else go to loop end;

symbolic procedure gfsimp u;
 % strip domain tags and strip zero im part but restore :bf: if needed.
   if bfnump u then u else if eqcar(u,'!:rd!:) then retag cdr u
   else if eqcar(u,'!:ft!:) then cdr u
      else if eqcar(u,'!:rn!:) then divbf(bfloat cadr u,bfloat cddr u)
   else
      <<if eqcar(u,'!:crn!:) then u := !*crn2cr u;
        u := if car u memq '(!:cr!: !:gf!:)
             then (retag cadr u) . retag cddr u
          else if eqcar(u,'!:gi!:)
             then (normbf bfloat cadr u) . normbf bfloat cddr u
          else cdr u;
        if bfzp cdr u then car u else u>>;

symbolic procedure reformup q; if domainp q then q else
   begin scalar c,fg,d; integer n;
      for each v in q do  % check for complex, float, bfloat.
         <<v := cdr v; n := max(n,xnsiz v);
           if floatp v or bfp!: v then c := gzero v
           else if not atom v then
              <<fg := t;
                if not fixp (v := car v) then c := gzero v >> >>;
       % make coefficients homogeneous in type and assure
       % adequate precision if automode is on;
       % convert coefficients to all real or all complex.
      if fg then
         <<q := for each v in q collect (car v) .
            <<d := cdr v; if bfnump d then d . 0 else d>>;
           d := q;
           repeat if bfnzp cadar d then fg := nil
                 until not fg or null(d := cdr d);
           if fg then
              q := for each v in q collect (car v) . cddr v>>;
      if bfp!: c or (n>!!nfpd and !*automode) then
         <<q := bfloatem q; setflbf t>>
         else if floatp c then <<q := cflotem q; setflbf nil>>;
      if !*automode and n+2>!:prec!: then !:prec!: := n+2;
      return q end;

%unfluid '(!*pfsav ra!# acc!# rat!# prec!# bfl!#);
%unfluid '(!*xmax !*xmax2 !*rvar nwmax!# lgmax!# nozro!# sprec!#);
%unfluid '(!*xo rprec!# !*cmplex !*pcmp !*multrt emsg!# incmsg!$);
%unfluid '(!*keepimp !*po pr!# !1rp sqf!# exp!# !*bfsh vars!# rlrt!#);
%unfluid '(cpx!# pfactor!# rr!# pnn!# norfrmp!# nn!# eps!# prx!#);

endmodule;


module complxp; % Support for complex polynomial solution.

% Author: Stanley L. Kameny <valley!stan@rand.org>.

% Version and Date:  Mod 1.92, 10 Oct 1990.

% Copyright (c) 1989,1990.  Stanley L. Kameny.  All Rights Reserved.

Comment   support for modules allroot and realroot;

symbolic;

symbolic procedure rxgfrl(p,x);
   <<x := gfabs x;
     for each i in cdr p do
        <<c := gftimes(c,x);
          if i then c := gfplus(c,rl2gf bfabs i)>>;
     bfsqrt gfrsq c>>
    where c=rl2gf bfabs car(p := cdr ncoeffs p);

symbolic procedure rxgfc(p,x);
   <<x := gfabs x;
     for each i in cdr p do
        <<c := gfabstim(x,c); if i then c := gfplus(c,gfabs i)>>;
     bfsqrt gfrsq c>>
   where c=gfabs car(p := cdr ncoeffs p);

symbolic procedure gfabs x; (bfabs car x) . bfabs cdr x;

symbolic procedure gfabstim(b,c);
 <<(plubf(timbf(ba,ca),timbf(bd,cd))).plubf(timbf(ba,cd),timbf(bd,ca))>>
 where ba=car b,bd=cdr b,ca=car c,cd=cdr c;

symbolic procedure rxrl(p,r);
   <<r := bfabs r;
     for each i in cdr p do
        <<c := timbf(r,c); if i then c := plubf(c,bfabs i)>>;
     c>>
   where c=bfabs car(p := cdr ncoeffs p);

symbolic procedure csep p;
   %separate gfform p into real p and im whose roots are all complex.
   <<p := primpc mkinteg p;
     (<<if not atom g then <<p := gfcpquo(p,g); pfactor!# := t>>;
        (n2gf g) . p>>
 where g=gfgcd(primcoef fillz for each s in p collect (car s) . cadr s,
          primcoef fillz for each s in p collect (car s) . cddr s))>>;

symbolic procedure fillz p; if atom p then p else
   for each c in ncoeffs p collect if null c then 0 else c;

symbolic procedure primcoef p; if atom p then p else
   %trim leading and trailing zero coeffs, and make prim.
   begin integer d;
      p := reverse cdr p;
      while p and car p=0 do p := cdr p; if null p then return 0;
      p := reverse p; while p and car p=0 do p := cdr p;
      if null cdr p then return 1;
      for each c in p do d := gcdn(d,c);
      return
       (((length p-1) . for each c in p collect s*c/d)
        where s=sgn car p) end;

symbolic procedure gfgcd(p,q); if atom p or atom q then 1 else
   if car q>car p then gfgcdr(q,p) else gfgcdr(p,q);

symbolic procedure gfgcdr(p1,p2);
   <<if r=0 then p2 else if atom r then 1 else gfgcdr(p2,r)>>
   where r=pqrem(p1,p2);

symbolic procedure pqrem(p1,p2);
    %primitive pseudoremainder of p1,p2 in intcoeff form.
    begin scalar a,g,n,n2,m,m1,m2;
       n := car p1-(n2 := car p2); p1 := cdr p1;
       p2 := cdr p2; m2 := car p2;
   lp: g := gcdn(m1 := car p1,m2);
       m1 := m2/g;
       a := p1 := for each y in p1 collect y*m1; m := car a/m2;
       for each y in p2 do
          <<rplaca(a,car a-y*m); a := cdr a>>;
       p1 := cdr p1; if (n := n-1)>=0 then go to lp;
       return primcoef ((length p1-1) . p1) end;

symbolic procedure negprem(p1,p2);
   %computes the negative pseudoremainder of p1,p2 in fillz form.
   begin scalar a,g,n,n2,m,m1,m2;
      n := car p1-(n2 := car p2); p1 := cdr p1;
      p2 := cdr p2; m2 := car p2;
  lp: g := gcdn(m1 := car p1,m2); m1 := abs(m2/g);
      p1 := for each y in p1 collect y*m1; a := p1; m := car a/m2;
      for each y in p2 do <<rplaca(a,car a-y*m); a := cdr a>>;
      p1 := cdr p1; if (n := n-1)>=0 then go to lp;
      return primpn((n2-1) . for each y in p1 collect -y) end;

symbolic procedure gfcpquo(p,q);
 %quotient of gi poly p and integer poly q, a factor in fillz form.
   begin scalar n,c,a,d,f,z,pp; z := 0 . 0;
      n := car(p := ncoeffs p)-car q;
      pp := for each r in cdr p collect if r then r else z;
      c := car(q := cdr q);
loop: a := (caar pp)/c; d := (cdar pp)/c;
      if a neq 0 or d neq 0 then f := (n.(a . d)) . f;
      if (n := n-1)<0 then return f;
      p := pp;
      for each r in q do
         <<rplaca(p,(caar p-a*r).(cdar p-d*r)); p := cdr p>>;
      pp := cdr pp; go to loop end;

symbolic procedure deflate1(p,r);
 %fast rem . quotient function for real polynomial with real r.
 %all arithmetic is bf with no rounding.
   begin scalar q,n,c;
      n := car(p := ncoeffs p); p := cdr p; c := car p;
      for each i in cdr p do
         <<n := n-1; if mt!: c neq 0 then q := (n . c) . q;
           c := times!:(r,c); if i then c := plus!:(i,c)>>;
      return c . q end;

symbolic procedure deflate1c(p,r);
 %rem . quotient function for complex polynomial, with complex r.
 %all arithmetic is bf with no rounding.
   begin scalar q,n,c;
      n := car(p := ncoeffs p); p := cdr p; c := car p;
      for each j in cdr p do
         <<n := n-1; if not gfzerop c then q := (n . c) . q;
           c := gftimesn(r,c); if j then c := gfplusn(c,j)>>;
      return c . q end;

fluid '(acc!# !*intp !*multrt !*strm !*pcmp !*cmplex sprec!# !*xo);
fluid '(!*bftag !*rootmsg lims!# pfactor!# pr1rp!# !*xnlist accm!#);
global '(!!bfepsq !!shbinfl !!epsqrt limlst!# bfone!*);
fluid '(!:prec!:);

smacro procedure ep!: u; cddr u;
smacro procedure mt!: u; cadr u;
smacro procedure preci!: u; length explode abs mt!: u;

symbolic procedure accupr(p,q,r); if caar lastpair q<2 then 1 else
   begin scalar cq,cp,rl,!*bftag,ac,s; !*bftag := t; ac := 1;
      q := bfloatem q; r := gf2bf r; cq := cpxp q; cp := cpxp p;
      rl := bfnump r or bfzp gfim r and (r := car r);
      q := % deflate root r or complex pair but do not round.
       if rl then cdr if cq then deflate1c(q,rl2gf r) else deflate1(q,r)
       else if not cq then deflate2(q,r)
       else cdr
         if cp then deflate1c(q,r)
         else deflate1c(cdr deflate1c(q,r),(car r) . minus!: cdr r);
      if caar q>0 then return 0;
      if rl then r := rl2gfc r;
      p := bfsqrt bfloat gfrsq r; p := 1+preci!: p+ep!: p;
loop: s := if caar lastpair q>1 then bfloat minbnd1(q,r) else
         bfsqrt gfrsq gfplus(r,
           <<s := cdar bfprim q; if not cq then rl2gf s else s>>);
      accm!# := max(accm!#,
         ac := max(ac,p-preci!: s-ep!: s));
      if not rl and not cp then  % repeat minbnd1 test for conj r.
         <<r := (car r) . minus!: cdr r; rl := t; go to loop>>;
      return ac end;

symbolic procedure orgshift(p,org);
   %shifts origin of real or complex polynomial to origin org,
   %with p and org of the same form.
   begin scalar s,fl,cp; integer n;
      if gfzerop(if (cp := cpxp p) then org else rl2gf org)
         then return p;
      org := gf2bf org;
      if (fl := numberp leadatom cdar p) then p := bfloatem p;
      if cp then while p do
         <<p := deflate1c(p,org);
           if not gfzerop car p then s := (n.car p).s;
           n := n+1; p := cdr p>>
         else while p do
            <<p := deflate1(p,org);
              if bfnzp car p then s := (n.car p).s;
              n := n+1; p := cdr p>>;
       return reversip if fl then cflotem s else bfrndem s end;

symbolic procedure bfrndem s;
   (for each c in s collect (car c) .
      if cp then (rndpwr cadr c) . rndpwr cddr c else rndpwr cdr c)
   where cp=cpxp s;

symbolic procedure schnok r; %true if precision is inadequate.
   begin scalar l,h,p;
loop: if (l := caar r) neq (h := cdar r) and
         (p and p neq l and sch l neq sch r2flbf2r l
             or sch h neq sch r2flbf2r h) then return t;
      p := h; if (r := cdr r) then go to loop end;

symbolic procedure r2flbf2r x; realrat r2flbf x;

symbolic procedure bfprim p;
   <<if ncpxp p
      then for each y in p collect (car y) . bfdivide(cdr y,d)
      else for each y in p collect (car y) . gfquotient(cdr y,d)>>
   where d=cdar lastpair p;

symbolic procedure primpc p;
   %make complex p primitive.
   begin integer d;
      for each y in p do d := gcdn(cadr y,gcdn(d,cddr y));
      return for each y in p collect
         (car y) . ((cadr y/d) . (cddr y/d)) end;

symbolic procedure ungffc p;
   begin scalar r,c;
      c := gtag cadar p;
      if caar p=0 then
         <<if not gfzerop cdar p then r := c.cdar p; p := cdr p>>;
      for each i in p do
         if not gfzerop cdr i then r := ((!*rvar.car i).(c.cdr i)).r;
      return r end;

symbolic smacro procedure ep!: x; cddr x;

symbolic procedure mkinteg p;
  %converts a polynomial in gfform to the smallest exactly equivalent
  %polynomial with integral coefficients.
   (begin integer m;
       p := bfloatem p; %convert to bfloat.
      % then work with powers of 10 to convert to integer.
       for each y in p do m := if nc then max(m,-ep!: cdr y) else
          max(m,-ep!: cadr y,-ep!: cddr y);
       p := for each y in p collect (car y) .
          if nc then iscale(m,cdr y) else
             (iscale(m,cadr y)) . iscale(m,cddr y);
       return if nc then primp p else primpc p end)
    where nc=ncpxp p;

symbolic procedure mkgirat j;
   %convert a gf complex into the equivalent gi rational form.
   begin scalar ra,rd,ia,id,ro,io;
      if bfnump(j := gf2bf j) then return realrat rootrnd bfloat j;
      j := gfrtrnd gf2bf j;
      ra := car(rd := realrat car j); rd := cdr rd;
      ia := car(id := realrat cdr j); id := cdr id;
      j := lcm(id,rd); ro := j/rd; io := j/id;
      return ('!:gi!: . ((ra*ro) . (ia*io))) . j end;

symbolic procedure mkpoly rtl; num mkpoly1 cdr rtl;

symbolic procedure mkpoly1 r;
   if null cdr r then mkdiffer car r
      else 'times . list(mkdiffer car r,mkpoly1 cdr r);

symbolic procedure getroot(n,r);
   if (n := fix n)<1 or n>length(r := cdr r) then
      rerror(roots,4,"n out of range") else
      <<while (n := n-1)>0 do r := cdr r; caddar r>>;

symbolic procedure mkdiffer r; 'difference . cdr r;

symbolic operator mkpoly,getroot;

symbolic procedure a2gf x;
   %convert any interpretable input value to gf form.
   bfixup if bfnump x then rl2gf x
      else if not atom x and bfnump car x
         then (r2flbf car x) .  r2flbf cdr x else
      <<(if errorp y or null(y := car y)
         then error(0,list(x,"is illegal as root parameter")) else y)
      where y=errorset!*(list('a2gf1,mkquote x),nil)>>;

symbolic procedure a2gf1 x;
   <<x := numr d; d := denr d;
      if domainp x then
        if eqcar(x,'!:gi!:) then
           if atom d then gfquotbf(cadr x,cddr x,d)
           else if eqcar(d,'!:gi!:) then
              gfquotient(gi2gf x,gi2gf d) else nil
           else if bfnump(x := gfsimp x)
              then rl2gf bfdivide(r2flbf x,r2flbf gfsimp d) else x
      else if equal(caar x,'(i . 1)) then gfquotbf(cdr x,cdar x,d)>>
    where d = simp!* x;

symbolic procedure gi2gf x; (bfloat cadr x) . bfloat cddr x;

symbolic procedure gfquotbf(rl,im,d);
   (if rl then quotbf(rl,d) else bfz!*) . quotbf(im,d);

symbolic procedure quotbf(n,d);
   <<if eqcar(n,'!:rn!:) then <<d := cddr n; n := cadr n>>
     else n := ftout n;  divbf(bfloat n,bfloat d)>>;

symbolic procedure sturm1 p;
   %produces the sturm sequence as a list of ncoeff's
   begin scalar b,c,s;
      b := fillz primp intdiff (p := mkinteg p);
      s := list(b,p := !*intp := fillz p);
      if not atom b then repeat
         <<c := negprem(p,b); s := c . s;
           p := b; b := c>> until atom c;
      !*multrt := c=0;
      return !*strm := reverse s end;

symbolic procedure gfshift p;
   begin scalar pr,n,org; sprec!# := '!:bf!: . (3 . (1-!:prec!:));
      !*xo := rl2gf 0; if null p then return !*xo;
      n := car (pr := ncoeffs bfprim p); if n>1 then pr := caddr pr;
      if pr then if cpxp p
         then !*xo := org := gfquotient(pr,rl2gf(-n))
         else !*xo := rl2gf(org :=bfdivide(pr,r2flbf(-n)));
      if null pr then return p;
      return orgshift(p,org) end;

symbolic procedure p1rmult p; automod numr simp!* p1rmult1 p;

symbolic procedure p1rmult1 p;
   if atom p then nil
   else if atom cdr p then reval mk!*sq !*f2q caar p
   else list('times,p1rmult1 list car p,p1rmult1 cdr p);

symbolic procedure xoshift(p,nx);
   begin scalar n,org,pr,cp,orgc,a,b;
     % shift if abs p(mean) < p(origin).
      n := car (pr := ncoeffs bfprim p); if n>1 then pr := caddr pr;
      if null pr then return nil;
      org := if (cp := cpxp p) then gfquotient(pr,rl2gf(-n))
         else bfdivide(pr,r2flbf(-n));
      orgc := if cp then org else rl2gf org;
      if errorp(b := errorset!*(
            list('gfrsq,list('gfval,mkquote p,mkquote orgc)),nil))
         then return bflessp(gfrsq gf2bf orgc,bfone!*)
        else b := car b;
      a := gfrsq gfval(p,rl2gf 0);
      pmsg list("a=",a," b=",b);
      return not bflessp(a,b) end;

symbolic procedure gffinitr p;
   %do gffinit p but restore *bftag.
   begin scalar bf;
      bf := !*bftag; p := gffinit p; !*bftag := bf; return p end;

symbolic procedure invpoly p;
   %remove zero roots of p and reverse coefficients of p.
   <<p := ncoeffs for each r in p collect (car r-caar p) . cdr r;
     n2gf((car p) . reversip cdr p)>>;

symbolic procedure bdstest i;
   begin scalar y;
      if equal!:(rootrnd r2bf car i,y := rootrnd r2bf cdr i)
         then return y end;

symbolic procedure limchk x;
   <<!!mfefix();
     if null (x := for each y in x collect
        if member(y,limlst!#) then y
        else if eqcar(y := reval y,'list)
         then 'list . list limchk1 cadr y
        else limchk1 y) then nil
     else if x and not cdr x then
        if car x eq 'positive then list 1
        else if car x eq 'negative then list (-1) else limerr()
     else <<x := mkratl x; limchk2(car x,cadr x)>>>>;

symbolic procedure limchk1 y;
 if errorp(y := errorset!*(list('a2gf,mkquote y),nil))
    then limerr()
 else if bfzp gfim car y then caar y
 else rerror(roots,5,"Real root function limits must be real");

symbolic procedure limchk2(a,b);
 <<if member(a,l) and member(b,l) then if a neq b then nil else limerr()
   else if member(a,limlst!#) then
      if member(b,limlst!#) then limerr() else limchk2(b,a)
   else if member(b,limlst!#) then
      if b eq 'negative then list('minfty,mkxcl a)
      else if b eq 'positive then list(mkxcl a,'infty)
      else if b eq 'infinity then list(a,'infty) else list('minfty,a)
   else if ratv b=ratv a and (xclp a or xclp b) then t
   else if ratlessp(ratv b,ratv a) then list(b,a) else list(a,b)>>
   where l = cddr limlst!#;

symbolic procedure limerr;
   rerror(roots,6,"Illegal region specification");

symbolic procedure ratv a; if xclp a then cdr a else a;

symbolic procedure rlrtno2 p;
  if null sturm p then 0
  else if null lims!# then schinf(-1)-schinf 1 else
  begin scalar a,b; a := car lims!#;
    if null cdr lims!# then
       return if a<0 then schinf(-1)-schinf 0-adjst realrat 0
          else schinf 0-schinf 1;
    return if (b := cadr lims!#)='infty then schxa a-schinf 1
       else if a='minfty then schinf(-1)-schxb b
       else schxa a-schxb b end;

symbolic procedure schxa a; if xclp a then sch cdr a else sch a+adjst a;

symbolic procedure schxb b;
   if xclp b then sch cdr b+adjst cdr b else sch b;

symbolic procedure adjst l; if sgn1(car !*strm,l)=0 then 1 else 0;

!!bfepsq := bfloat(!!epsqrt := 10.0**((-1-!!nfpd)/2));

symbolic procedure flhypot q;
   begin scalar p,r; p := car q; q := cdr q;
      if atom p then return hypot(p,q);
      p := abs!: p; q := abs!: q;
      if mt!: p=0 then return cflot q
      else if mt!: q=0 then return cflot p
      else if lessp!:(p,q) then <<r := p; p := q; q := r>>;
      return if lessp!:(r := divbf(q,p),!!bfepsq) then cflot p
         else <<r := cflot r; cflot p * sqrt(1+r*r)>> end;

symbolic procedure flroot(q,p,n);
   <<n := 1.0/n; if !!shbinfl then q**n/p**n else (q/p)**n>>;

symbolic procedure gfstorval(pf,xn); !*xnlist := (pf . xn) . !*xnlist;

symbolic procedure gfgetmin;
   begin scalar y,nx,l; l := !*xnlist; nx := car (y := car l);
      for each x in cdr l do
         if bflessp(car x,nx) then nx := car (y := x);
      return cdr y end;

symbolic procedure calcprec(m,n,r,av,s2);
   <<pmsg list("m=",m," n=",n," a=",acc!#," r=",r," av=",av,
      " s2=",s2,"->",p);p>>
   where p=if m<2 then 1+max(acc!#,n)
      else max(acc!#+1,n+1+ceillog m+ if r=1 then 0 else
         max(if s2>2.2 or s2<1.0 then 0 else if s2>1.7 then 2 else 3,
             if m>3 and 1.5*av>n+1 then
                 fix(0.7*max(acc!#,7)*log float m+0.5) else 0));

symbolic procedure rrpwr(r,m);
   <<while (m := m-1)>0 do rr := gftimes(rr,r); rr>>
   where rr=(r := a2gf r);

symbolic procedure cvt2(a,b); mt!: a neq 0 and mt!: b neq 0 and
   <<a := divide!:(round!:mt(a,5),round!:mt(b,5),3);
     lessp!:(a,bfone!*) and greaterp!:(a,'!:bf!: . 1 . -1)>>;

symbolic procedure dsply nx; if !*rootmsg then
   << <<write nx; terpri(); wrs n>> where n=wrs nil>>;

symbolic procedure leadatom x; if atom x then x else leadatom car x;

symbolic procedure cvt5(a,b); equal!:(round!:mt(a,5),round!:mt(b,5));

%unfluid '(acc!# !*intp !*multrt !*strm !*pcmp !*cmplex sprec!# !*xo);
%unfluid '(!*bftag incracc!# lims!# pfactpr!# pr1rp!# !*xnlist accm!#);

endmodule;


module allroot; % Routines for solving real polynomials by iteration.

% Author: Stanley L. Kameny <valley!stan@rand.org>.

% Version and Date:  Mod 1.92, 10 Oct 1990.

% Copyright (c) 1988,1989,1990. Stanley L. Kameny. All Rights Reserved.

Comment   modules bfauxil, bfdoer, bfdoer2, complxp and realroot
 needed also;

symbolic;

global '(roots!-mod); roots!-mod := "Mod 1.92, 10 Oct 1990.";
global '(!!eps !!nfpd); fluid '(!:prec!:);
fluid '(!*trroot !*bftag !*rootmsg !*multiroot !*powergcd rootacc!#
  !*hardtst);
flag('(rootacc!#),'share);
switch trroot,rootmsg,multiroot;
fluid '(!*xnlist !*pfsav !*rvar !*hx !*lx !*xmax !*xmax2);
fluid '(!*pcmp prec!# acc!# sprec!# !*xn eps!# accm!#);
fluid '(nwmax!# lgmax!# !*xo !*po !*keepimp !1rp !*zx1 !*mb tht!#
 !*bfsh !*strm mltr!# emsg!# lims!# incmsg!$ polrem!$ cpxt!# sh!#
 pfactor!# rprec!# rr!# ss!# prx!# nrst!$ !*xd !*zp intv!# pnn!#);
global '(bfone!* bfhalf!* bfz!* polnix!$);
nwmax!# := 60; lgmax!# := 60; !:prec!: := 8;
!*multiroot := !*powergcd := t;

symbolic smacro procedure ep!: x; cddr x;

symbolic procedure gfrootfind(p,nx);
% p is expected to be in the form returned by gfform, and
% nx should be in the form (rl . im).  returns nx in form (rl . im).
   begin scalar p1,p2,px,x1,x2,x3,x0,xd,nx,n,n1,gfqt,xz,rsc,njp,
     pf,xn2,t1,t2,!*pfsav,pf0,pf1,pfn,lp,xlim,fg,fg2,ip,ip0;
      integer r;
      !*xnlist := emsg!# := !*xd := nil; trmsg8(); !*pcmp := cpxp p;
      if caar p>0 then
    <<restorefl();
      rerror(roots,7,"Roots error: zero root out of sequence!")>>;
      if (n := caar lastpair p)=1 then
         <<p := cdar bfprim p;
           nx := gfminus if !*pcmp then p else rl2gf p;
           gfshift nil; trmsg11(nx,1); go to ret1>>;
      if nx and bfp!: car nx and not !*bftag then p := mkbfgfp p;
      !*xo := rl2gf 0; seteps();
      if not (n>2 and not !*hardtst and xoshift(p,nx)) then gfshift nil
         else <<p := gfshift p; pmsg('xo . !*xo)>>;
      nx := if not nx then rl2gf 0 else xnshift nx;
      p1 := gfdiff p;
      if gfzerop nx then xz := t;
      px := gfval(p,nx); bfmax p; !*zp := 0;
strt: pf := gfrsq px; trmsg13(n,nx,px);
      if bfzp pf then <<trmsg1 ('lag,nx); go to ret0>>;
      x1 := gfval(p1,nx);
    % avoid bad starting point using minbnd1 for offset.
      if (!*zx1 := not !*mb and bfnzp gfrsq x1) then go to st2;
      !*mb := x2 := nil; x1 := bfrlmult(2.0,minbnd1(p,nx));
      if !*keepimp then
         <<if !*pcmp or bfnzp gfim nx then x2 := gfdiffer(nx,im2gf x1);
           px := gfval(p,nx := gfplus(nx,im2gf x1));
           if not x2 then go to st1>>
       else
         <<x2 := gfdiffer(nx,rl2gf x1);
           px := gfval(p,nx := gfplus(nx,rl2gf x1))>>;
      if bflessp(gfrsq(p2 := gfval(p,x2)),gfrsq px) then
         <<nx := x2; px := p2>>;
 st1: xz := nil; go to strt;
 st2: n1 := n-1; p2 := gfdiff p1; xlim := bfrlmult(100.0,!*xmax2);
      ip := bfnzp gfim nx;
 lag: x3 := gfval(p2,nx);
      if not fg or bfzp gfrsq x1 then <<pmsg 0; go to lag0>>;
      gfqt := gfquotient(px,x1);
    % if newton is good enough, do it: it's cheaper.
      xn2 := gftimes(gftimes(gfqt,gfqt),
          gfrlmult(0.5,gfquotient(x3,x1)));
      t1 := bfabs gfdot(nx,xn2);
      t2 := bfabs bfrlmult(0.002,gfdot(nx,gfqt));
      pmsg if bfnzp t2 then gf2flt bfdivide(t1,t2) else "nwt_del->0";
      if bflessp(t1,t2) then go to ret;
lag0: x2 := gfrlmult(n1,
         gfdiffer(gfrlmult(n1,gftimes(x1,x1)),
           gfrlmult(n,gftimes(px,x3))));
      x2 := gfsqrt x2;
      x0 := nx; xd := gfplus(x1,x2); x2 := gfdiffer(x1,x2);
    % determine correct sign of x2 for Laguerre iteration.
      if bflessp(gfrsq xd,gfrsq x2) then xd := x2;
      if bfzp(x2 := gfrsq xd) then
         <<trmsg10 'lag; return(!*xnlist := nil)>>;
      if bflessp(bftimes(xlim,x2),bfrlmult(n*n,gfrsq px))
         then <<lp := t; xn2 := gfrsq nx; go to lag1>>;
      xd := gfrlmult(-n,gfquotient(px,xd)); nx := gfplus(x0,xd);
    % constrain iteration to circle of radius !*xmax=maxbound p,
    % by scaling root to radius !*xmax/2.
      if bflessp(xn2 := gfrsq nx,!*xmax2) then go to lag2;
lag1: if rsc then go to lag2;
      pf1 := pf0 := fg2 := !*pfsav := !*xnlist := nil;
      if lp then
         <<if !*trroot then <<write "root scaled"; terpri()>>;
           nx := if xz then rl2gf bfrlmult(0.5,!*xmax) else
              <<xn2 := bfrlmult(0.5,
                   if atom xn2 then sqrt(!*xmax2/xn2)
              else bfsqrt divbf(!*xmax2,xn2));
                 gfrlmult(xn2,nx)>>; rsc := t>>
      else if bflessp(xlim,xn2) then lp := t;
      pf := gfrsq(px := gfval(p,nx)); go to lag3;
lag2: if !*xnlist then
         for each y in !*xnlist do if nx=cdr y then njp := t;
      pf := gfrsq(px := gfval(p,nx));
    % test for minimum in envelope of pf, but not on first iter.
      if not fg then fg := t else <<pf1 := pf0; pf0 := pfn>>;
    % if root has just turned complex, allow to settle.
      ip0 := ip; ip := bfnzp gfim nx;
      if ip and not ip0 then
         <<pf1 := pf0 := fg2 := !*pfsav := nil>>;
      pfn := pflupd pf;
      if pf1 then
         <<if not fg2 then <<if bflessp(pfn,pf0) then fg2 := t>> else
            <<if bflessp(pf0,pfn) or bfeqp(pf0,pf1) and bfeqp(pf0,pfn)
                then go to newt>> >>;
      if xz then xz := nil else gfstorval(pf,nx);
      pmsg mapcar(!*pfsav,function gf2flt);
lag3: trmsg2('lag,nx,px); r := r+1;
      if (xd := gfexit(pf,nx,x0,'lag))=t then go to ret0
         else if xd then
            <<if gfeqp(nx,xd) then go to ret0
              else if r>2 then <<!*xd := nx := xd; go to ret2>> >>
         else if njp then go to newt;
      lagerr r;
      x1 := gfval(p1,nx); go to lag;
ret1: nx := unshift nx; go to ret2;
newt: nx := gfgetmin();
 ret: return gfnewt2(p,p1,nx,4);
ret0: nx := unshift nx;
ret2: !*xnlist := nil; dsply nx; return !*xn := nx end;

symbolic procedure pshift p;
   orgshift(p,if cpxp p then !*xo else gfrl !*xo);

symbolic procedure gfnewton(p,nx,k);
   <<p := pshift p; gfnewt2(p,gfdiff p,xnshift nx,k)>>;

symbolic procedure gfnewt2(p,p1,nx,kmax);
   begin scalar pf0,pf,k,xk,loop,x0,x1,xd,px,rl; integer m,tht!#;
      !*xnlist := emsg!# := !*xd := nil;
      if (rl := bfzp gfim nx) and ncpxp p then
         <<!*bfsh := t;
   nx := rl2gf bfnewton(p,p1,gfrl nx,intv!#,kmax);
           !*bfsh := nil; go to ret1>>;
      seteps(); !*zp := 0;
      if gfzerop(px := gfval(p,nx)) then
         <<trmsg1('nwt,nx); go to ret1>>;
      gfstorval(gfrsq px,nx);
 ne0: x0 := nx;
      if gfzerop(x1 := gfval(p1,nx)) then
         <<trmsg10 'nwt; go to ret1>>;
      nx := gfdiffer(nx,gfquotient(px,x1)); pf0 := pf;
      for each y in !*xnlist do if nx=cdr y then loop := t;
      gfstorval(pf := gfrsq(px := gfval(p,nx)),nx);
      pmsg list gf2flt pf;
    % test for loop, but not on first iteration.
      if pf0 and bfleqp(pf0,pf) then
         <<loop := t;
           if kmax<2 then <<trmsg2('loop,nx,px); go to ret>> >>;
      trmsg2(if loop then 'loop else 'nwt,nx,px);
      if (xd := gfexit(pf,nx,x0,'nwt)) then
            <<if xd=t or gfeqp(nx,xd) then go to ret1
              else if m>0 then <<!*xd := nx := xd; go to ret2>> >>;
      if not loop then go to nlp;
    % next section updates loop variables.
      if k then <<xk := gfplus(xk,nx); k := k+1>>
         else <<k := 1; xk := nx>>;
      if k>=kmax then
         <<nx:=gfrlmult(1.0/k,xk);
           gfstorval(gfrsq(px := gfval(p,nx)),nx);
           trmsg6(k,nx,px); goto ret>>;
 nlp: nwterr(m := m+1); go to ne0;
 ret: trmsg7 (nx := gfgetmin());
ret1: nx := unshift nx;
ret2: !*xnlist := nil; dsply nx; return !*xn := nx end;

symbolic procedure accuroot (y,p,xo);
   begin scalar rprec,b,c,n,rl,x,x1,pr0,p1,ps,rx,y0;
      ps := !:prec!:;  rl := bfnump y; !*xo := xo; b := !*bftag;
      y0 := y := gf2bf y; p := makebfp(p,xo);
      if (n := caar lastpair p)<2 then
         <<!:prec!: := max(ps,acc!#+2);
           if prx!# then !:prec!: := max(!:prec!:,prx!#);
           y := gfrootfind(p,nil); go to ret>>;
      x := if rl then gfrl xnshift (y := rl2gf y) else xnshift y;
      pr0 := if b then ps else !!nfpd;
      p1 := gfdiff pshift p;
      if rl and ncpxp p then
         <<x1 := bfabs rlval(p1,x); rx := rxrl(p1,x)>>
      else
         <<rx := if cpxp p then rxgfc(p1,x) else rxgfrl(p1,x);
           x1 := bfsqrt gfrsq gfval(p1,x)>>;
      if bfzp x1 then <<setflbf b; return nil>>;
      !:prec!: := 8;
      c := divbf(timbf(rx,'!:bf!: . (1 . (acc!#+2))),x1);
      rprec := 1+ep!: round!:mt(c,1);
      if rprec<=pr0 then
         <<!:prec!: := pr0; if !*xd then go to bfp else go to ret>>;
      !:prec!: := rprec;
 bfp: y := if !*xd or not rl and (bfzp gfim y or bfzp gfrl y)
         then gfrootfind(p,y) else
            <<trmsg8(); gfnewton(p,y,if rl then 2 else 0)>>;
      if !*xd then <<!:prec!: := !:prec!:+!:prec!:/2; go to bfp>>;
 ret: prec!# := !:prec!:;
      if rl or n<2 or not (c := smpart y) then go to r2;
      !:prec!: := !:prec!:+1; x := gfnewton(p,y := gf2bf !*xn,0);
      y := !*xn :=
         if c=t then if cvt5(gfrl y,gfrl x) and not cvt5(gfim y,gfim x)
             then rl2gf gfrl y else y
         else if cvt5(gfim y,gfim x) and not cvt5(gfrl y,gfrl x)
             then im2gf gfim y else y;
  r2: !:prec!: := ps;
      if not rl and
         (bfzp gfrl y and bfnzp gfrl y0
            or bfzp gfim y and bfnzp gfim y0)
         then acc!# := max(acc!#,accupr(p,!1rp,y));
      trmsg12(y := if rl then rootrnd gfrl y else gfrtrnd y);
      setflbf b; return y end;

symbolic procedure allroots(p,p0);
  % do the actual work of finding roots of p in appropriate environment.
   begin scalar q,n,n0,c,cc,cprq,rln,cpn,ac,y,er,rl,z,mb,inc,prec,xo,
        sprec,b,red,sw,sw2; integer req,npi,accm!#,prec!#;
      prec := !:prec!:; polrem!$ := polnix!$ := nil; ac := acc!#;
      n0 := caar lastpair p; red := not p0;
      sprec := if (b := !*bftag) then !:prec!: else !!nfpd;
      if not(!*pcmp := cpxp p) then req := if n0=1 then 1 else rlrtno p;
      if req>0 then trmsg4 req; % req = <no of real roots to determine>.
strt: n := n0; q := p; c := cc := !*mb := sw2 := nil; cprq := n-req;
      if not !*pcmp then cprq := cprq/2; rln := cpn := 0;
root: pmsg pbfprint q; acc!# := ac; !*keepimp := req-rln=0;
  r1: y := gfrootset(q,nil,b);
      if n=n0 then <<xo := !*xo; p0 := q>>;
      if not y then <<er := t; go to fl>>;
            if not (y := ckacc(q,if red then p0 else !1rp,!*xn)) then
         <<trmsg10 "ckacc"; go to inc0>>;
      if princreq(n,bfzp gfim y,sprec) then
         <<sw2 := sw := prec!#+2; go to fl>>;
 r15: sw2 := nil;
      if n0>2 and n0>n then
         <<if !*trroot then <<write "q(",n,") -> ",gf2bf y; terpri()>>;
           y := gfnewtset(caar lastpair p0,p0,!*xn,xo,b);
           if not y then <<trmsg10 "gfnewtset"; go to inc0>> >>;
      if !*trroot then <<write "p(",n,") -> ",gf2bf y; terpri()>>;
      if gfzerop y then <<incmsg!$ := "illegal zero root"; go to incr>>;
      if not (y := accuroot(!*xn,p0,xo)) then
            <<trmsg10 "accuroot"; go to inc0>>;
      rl := bfzp gfim y;
      if princreq(n,rl,sprec) then <<sw := prec!#+2; go to fl>>;
  r2: if rl then
         <<y := gfrl y; if rln+1>req then
            <<incmsg!$ := "excess real root"; go to incr>> >>
         else if cpn+1>cprq then
            <<incmsg!$ := "excess complex root"; go to incr>>;
      z := gf2bf(if rl then gfrl !*xn else !*xn); % set by lag or nwt.
      if not rl and not !*pcmp then
         <<y := (car y) . bfabs cdr y; z := (car z) . bfabs cdr z>>;
      if c and member(y,c) then
            <<incmsg!$ := "equal roots found"; go to incr>>;
      if rl then rln := rln+1 else cpn := cpn+1;
      c := y . c; mb := nil;
      cc := ((if red then z else y) . acc!#) . cc;
     % c is rounded roots list used in testing for equal roots.  Output
     % list is cc, a list of (root . acc) where root may be y or z.
      if !*trroot then terpri();
    % new logic does all deflation in bfloat for greater accuracy.
      z := gf2bf z; q := bfloatem q;
      if (rl or !*pcmp) and (n := n-1)>0 and
         (q := cdr(if rl then deflate1(q,z) else deflate1c(q,z)))
         or (n := n-2)>0 and (q := deflate2(q,z)) then
            <<q := if not b then cflotem q else bfrndem q; go to root>>;
 ret: !:prec!: := max(prec,(acc!# := ac)+2);
      setflbf b; return cexpand cc;
incr: lprim incmsg!$; polnix!$ := q;
      if mb then go to inc1
      else if !*zx1 then
         <<lprim "offset iteration attempted";
           !*mb := mb := t; go to r1>>;
inc0: if (npi := npi+1)>3 then
         <<lprim list("root finding aborted. Deflate degree = ",n);
           lprim list("poly = ",q); terpri();
           if n0>n then polrem!$ := q; go to ret>>;
inc1: inc := max(n0,sprec/2);
      !:prec!: := sprec := max(sprec+inc,2+2*acc!#); trmsg9 sprec;
      if b then go to strt;
  fl: p := makebf(p,p0,xo); p0 := !*po; xo := !*xo;
      b := t; !1rp := bfloatem !1rp;
      if er then <<er := nil; q := bfloatem q; go to r1>>;
      if sw then
     % precision has increased: backup point depends on n.
         <<!:prec!: := sprec := sw; sw := nil; q := p;
           if n=n0 then
              <<y := gf2bf y;
                if sw2 then go to r15 else go to r2>> >>;
      go to strt end;

symbolic procedure princreq(n,rl,sprec);
   (n>2 or (rl or !*pcmp) and n>1) and min(prec!#,2*(accm!#+1))>sprec;

symbolic procedure nrstroot(p,rr,trib);
   begin
  scalar x,c,d,dx,xm,r,cp,n,m,s,p1,prx!#,acc,pp,m1,
     !*multiroot,cpxt!#,pfactor!#,nrst!$,intv!#;
      integer ss!#,accm!#;
      !!mfefix();
      p := cdr(c := ckpzro p); c := car c; !*mb := nil;
      if atom p then <<if c then c := list 0; go to ret>>;
      if null rr then rr := 0;
      r := a2gf rr; acc := acc!# := max(acc!#,1+xnsiz r);
      if trib then if atom trib then
        % test branch that calls gfnewton only.
         <<!*keepimp := numberp trib; p := automod p; !*xo := rl2gf 0;
           c := list gfnewton(p,a2gf rr,4); go to ret>>
         else % test branch that goes through gfrootfind only
         <<!*keepimp := numberp car trib; p := automod p;
           c := list gfrootfind(p,a2gf rr); go to ret>>;
      if c then if gfzerop r then <<c := list 0; go to ret>> else
        <<d := bfloat gfrsq r; xm := bfz!*>>;
      m := powerchk p; nrst!$ := t;
      p := gfsqfrf1 p; n := pnn!#; p1 := !1rp;
      if length p>1 then pfactor!# := prx!# := n;
      if cpxp p then cpxt!# := t;
      if m then
         <<p := gfsqfrf cdr m; m := car m;
           ss!# := s := ceillog m>>;
      acc := acc!#;
loop: pp := automod car(x := car p); cp := nil;
      if cpxp pp then
         <<pp := car(cp := csep pp); cp := cdr cp;
           if atom pp then go to cpr else pfactor!# := prx!# := n>>;
 mod: pp := automod pp; r := a2gf rr;
     % powerchk may succeed after sqfrf or csep succeeds.
      if (m1 := powerchk pp) then <<pp := cdr m1; m1 := car m1>>;
      if not m and not m1 then
         <<x := nrstrt0(pp,r,p1); go to col>>;
      x := if m1 then
         nrpass2(m1,nrpass1(pp,r,if m then m1*m else m1),r,p1,acc)
            else nrpass1(pp,r,m);
      if m then x := nrpass2(m,x,r,p1,acc);
 col: x := cdr x;
      dx := gfrsq gfdiffer(if bfnump x then (x := x . bfz!*) else x,
         gf2bf r);
      if not d or d and bfleqp(dx,d) then <<d := dx; xm := x>>;
 cpr: if cp then <<pp := cp; cp := nil; go to mod>>;
      if (p := cdr p) and not domainp caar p then go to loop else
         <<c := list if bfzp gfim xm then gfrl xm else xm;
           go to ret>>;
% abrt:
      c := nil;
      if !*trroot then <<write 'nearestroot," abort"; terpri()>>;
 ret: return allout c end;

symbolic procedure nrstrt0(q,rr,p1);
   begin scalar r,x,b,pr,ps,p2; pmsg pbfprint q; b := !*bftag;
      ps := !:prec!:; pr := if b then ps else !!nfpd;
      p2 := gfzerop a2gf rr;
  r1: if (x := gfrootset(q,r := a2gf rr,!*bftag)) then go to r2;
      q := bfloatem q; setflbf t; go to r1;
  r2: if not !*hardtst then x := ckacc(q,if p1 then p1 else q,!*xn);
      x := accuroot(
      if bfzp gfim r then (car !*xn) . bfabs cdr !*xn else !*xn,q,!*xo);
      if prec!#<pr+2 then
         <<setflbf b; !:prec!: := ps; return acc!# . x>>;
      pr := !:prec!: := prec!#;
      if not !*bftag then <<q := makebf(q,p1,!*xo); p1 := !*po>>;
      if p2 then go to r2 else <<p2 := t; go to r1>> end;

symbolic procedure nrpass1(pp,rr,m);
   nrstrt0(pp,rrpwr(rr,m),nil) where ss!#=ceillog m;

symbolic procedure nrpass2(m,x,rr,p1,acc);
   begin scalar s; s := ceillog m;
      return (nrstrt0(pconstr(m,cdr x),rr,p1)
         where acc!#=max(acc,car x-s),rr!#=1,
            ss!#=0,pfactor!#=(pfactor!# or car x-s>acc)) end;

%unfluid '(!*xnlist !*pfsav !*rvar !*hx !*lx !*xmax2 !*mb cpxt!# !*xd
% !*cmplex !*pcmp prec!# acc!# sprec!# !*xn eps!# sh!# nwmax!# pnn!#
% lgmax!# !*xo !*po !*keepimp !1rp emsg!# !*zp accm!# lims!# !*bfsh
% !*strm mltr!# !*bftag incmsg!$ !*zx1 !*xmax pfactor!# rprec!# rr!#
% ss!# prx!# nrst!$ intv!# tht!#);

endmodule;


module realroot; % Routines for finding real roots of polynomials,
                 % using Sturm series, together with iteration.

% Author: Stanley L. Kameny <valley!stan@rand.org>.

% Version and Date:  Mod 1.92, 10 Oct 1990.

% Copyright (c) 1988,1989,1990. Stanley L. Kameny. All Rights Reserved.

Comment   modules bfauxil, bfdoer, bfdoer2, complxp and allroot
 needed also;

symbolic;

global '(!!nfpd !!flim bfhalf!* max!-acc!-incr bfone!*);
max!-acc!-incr := 8;
fluid '(!*gfp !*xnlist !*intp tht!# !*strm lims!# mltr!# pfactor!#
 prec!# !*rvar acc!# !*cmplex !*xr !*xo !1rp cpxt!# pnn!# ss!# accm!#
 !*xn pr1rp!# prx!# nrst!$ intv!# sh!# !:prec!: rprec!# rlrt!#);
fluid '(!*trroot !*bftag !*multiroot rootacc!#);
switch trroot,multiroot;
flag('(positive negative infinity),'reserved);
global '(limlst!#);
limlst!# := '(positive negative infinity (minus infinity));

smacro procedure mt!: u; cadr u;

smacro procedure ep!: u; cddr u;

symbolic procedure isolatep p;
   begin scalar n,q,zr,a,b,c,ril,va,vb,vc,v0,w,elem,l,u,i,j,lr,ur,
         xcli,xclj,ol,ou;
      if null sturm p or schinf(-1)-schinf 1=0 then go to ret;
    % limits +/-1.0001*maxbound p to give working room for rootfind.
      n := car(q := car !*strm);
      l := ratminus(u := realrat bfrlmult(1.0001,bfmax p));
      if (zr := l=u) and (lr := l) and not lims!# then go to zrt;
      if lims!# then
         <<i := car lims!#; if cdr lims!# then
            <<j := cadr lims!#;  % both limits given.
              if i eq 'minfty then xcli := t else
                 <<if xclp i then <<xcli := t; i := cdr i>>;
                   l := ratmax(l,i)>>;
              if j eq 'infty then xclj := t else
                 <<if xclp j then <<xclj := t; j := cdr j>>;
                   u := ratmin(u,j)>>;
              if zr then if ratlessp(u,l) then go to ret
                 else go to zrt;
              if sgn1(q,l)=0 then       % root at l.
                 <<ol := offsetr(n,l);
                   if xcli then l := ratplus(l,ol) else lr := l>>;
              if l neq u and sgn1(q,u)=0 then  % root at u.
                 <<ou := offsetr(n,u);
                   if xclj then u := ratdif(u,ou) else ur := u>> >>
           else if zr then go to ret else
              <<if sgn1(q,ol := realrat 0)=0 then ol := offsetr(n,ol);
                if i<0 then u := ratminus ol  % negative roots.
                   else l := ol>> >>;  % positive roots.;
      trmsg4(n := (va := sch l+if lr then 1 else 0)-(vb := sch u));
      if n=0 then go to ret;
      if n=1 then ril := list list(l,u)
         else for j:=1:n do ril := nil . ril;
      v0 := vb+n-1;
      if lr then
         <<stuffrt(l,u,lr,ol,v0,va,vb,nil,ril);
           l := ratplus(lr,ol); va := va-1>>;
      if ur then
         <<stuffrt(l,u,ur,ou,v0,va,vb,nil,ril);
           u := ratdif(ur,ou); vb := vb+1>>;
      w := list list(l,u,va,vb);
      if n>1 then while w do
        <<elem := car w; w := cdr w; a := car elem; b := cadr elem;
          va := caddr elem; vb := cadddr elem; c := ratmean(a,b);
          if sgn1(q,c)=0 then % c is a root.
             w := stuffrt(a,b,c,offsetr(n,c),v0,va,vb,w,ril) else
          % root not found; stuff isolating interval and update work.
             <<vc := sch c;
               if va = vc+1 then <<stuffr(v0-vc,list(a,c),ril)>>;
               if va > vc+1 then w := list(a,c,va,vc) . w;
               if vb = vc-1 then <<stuffr(v0-vb,list(c,b),ril)>>;
               if vb < vc-1 then w := list(c,b,vc,vb) . w>> >>;
      ril := for each i in ril collect (car i) . cadr i;
 ret: return ril;
 zrt: return list (lr . lr) end;

symbolic procedure stuffrt(a,b,c,m,v0,va,vb,w,ril);
   begin scalar vcm,vcp;  % stuff root and update work.
      vcm := 1+(vcp := sch ratplus(c,m));
      stuffr(v0-vcp,list(c,c),ril);
      if va = vcm+1 then stuffr(v0-vcm,list(a,ratdif(c,m)),ril);
      if va > vcm+1 then w := list(a,ratdif(c,m),va,vcm) . w;
      if vb = vcp-1 then stuffr(v0-vb,list(ratplus(c,m),b),ril);
      if vb < vcp-1 then w := list(ratplus(c,m),b,vcp,vb) . w;
      return w end;

symbolic procedure offsetr(n,r);
   realrat if n=1 then 1 else minbnd1(!*gfp,mk!*sq r);

symbolic procedure sturm p;
   <<if cpxp (p := gffinitr p) then p := car csep p;
     if not atom p then <<!*gfp := bfloatem p; sturm1 p>> >>;

symbolic procedure schinf z;
   begin scalar v,v1; integer r;
      v := schinf1(car !*strm,z := sgn z);
      if v=0 then return schplus realrat z;
      for each p in cdr !*strm do
         <<v1:= if atom p then p else schinf1(p,z);
           if v*v1<0 then r := r+1; if v1 neq 0 then v := v1>>;
      return r end;

symbolic procedure schplus z; sch ratplus(z,offsetr(caar !*strm,z));

symbolic procedure schinf1(p,z);
   if z=0 then car lastpair p else (z**car p)*sgn cadr p;

symbolic procedure sgn1(p,r); if atom p then sgn p else
 % Evaluate sign of one sturm polynomial for rational r=(u . d)
   begin scalar m,c,u,d; u := car r; d := cdr r;
      c := 0; m := 1; p := cdr p;
      repeat <<c := m*car p + u*c; m := m*d>> until null(p := cdr p);
      return sgn c end;

symbolic procedure iscale(d,y); mt!: y*10**(d+ep!: y);

symbolic procedure r2flimbf x;
   if acc!#<=!!flim then r2flbf x else r2bf x;

symbolic procedure rootfind(p,i);
  % finds real roots in either float or bigfloat modes.
  % p is in gfform. i is a pointer to a rational interval pair;
   begin scalar p1,p2,px,x1,x2,x3,x0,nx,xr,fg,n,s,sh;
      scalar xd,xe,qt,xnlist,pf,pf0; integer m,tht!#;
      n := caar lastpair p; !*xnlist := nil;
      if car i=cdr i then
         <<nx := r2flbf cdr i; go to lg4>>;
      xr := ratmean(car i,cdr i);
      if !*trroot then
         <<write "real root ",list(r2flimbf car i,r2flimbf cdr i);
           terpri()>>; trmsg8();
      if ratlessp(cdr i,car i) then
         errach "lx > hx ***error in roots package";
      movebds(i,xr,sh!# := sh := sgn1(!*intp,cdr i));
      p2 := gfdiff(p1 := gfdiff p);
lag0: if bndtst (px := rlval(p,nx := r2flbf xr)) then go to tht
         else if bfzp px then go to lg4;
 lag: % check for proper slope at nx.
      if bndtst (x1 := rlval(p1,nx))
         or (s := bfsgn x1) neq sh then go to tht;
     % if lag not converging, go to newt.
      pf := bfabs px; if pf0 and bfleqp(pf0,pf) then go to newt;
      gfstorval(pf,nx); x1 := bfabs x1;
      if bndtst (x3 := rlval(p2,nx)) then go to tht;
   % bigfloat computations: is newton cheaper?
      if fg and
         <<qt := divbf(px,x1);
           xe := timbf(qt,timbf(qt,(divbf(x3,x1))));
           equal!:(nx,plubf(nx,timbf(bfhalf!*,xe)))>>
              then go to newt;
    % check whether laguerre iteration will work.
      x2 := difbf(bfrlmult(n-1.0,timbf(x1,x1)),
           bfrlmult(n,timbf(px,x3)));
      if bfminusp x2 then go to tht;
   % nx has met all tests, so continue.
      x0 := nx;
      xd := divbf(bfrlmult(-n*s,px),
         plubf(x1,bfsqrt(bfrlmult(n-1,x2))));
      nx := plubf(x0,xd);
 lg3: fg := t;
      if ratlessp(xr := realrat nx,car i) or ratlessp(cdr i,xr)
         then go to tht;
      if bndtst (px := rlval(p,nx)) then go to tht;
      movebds(i,xr,sh); trmsg2 ('lag,nx,px);
      if bdstest i then go to ret;
      if bfzp px then go to lg4;
      if bfeqp(nx,x0) then <<trmsg3('lag,nx); go to ret>>;
      if xnlist and member(nx,xnlist) then go to newt;
      xnlist := nx . xnlist; pf0 := pf;
      if(m := m+1)<10 or
        <<m := 0;
          equal!:(bfone!*,round!:mt(divbf(bfloat nx,bfloat x0),3))>>
            then go to lag;
 tht: nx := tighten(i,p,pf,sh); m := 0;
      if !*xnlist then
         <<pf0 := nil;
           movebds(i,xr := ratmean(car i,cdr i),sh); go to lag0>>;
 lg4: trmsg1('lag,nx);
 ret: !*xnlist := nil; if not nx then trmsg10 'lag; go to ret2;
newt: nx := bfnewton(p,p1,gfgetmin(),i,4);
ret2: !*xn := rl2gf nx; return nx end;

symbolic procedure bndtst x; greaterp!:(abs!: x,'(!:bf!: 1 . 10));

symbolic procedure movebds(i,xr,sh);
   if sgn1(!*intp,xr)=sh then rplacd(i,xr) else rplaca(i,xr);

symbolic procedure tighten(i,p,pf,sh);
   begin scalar j,x0,nx,px,sn,x;
      nx := car i;
tht0: j := 4;
tht1: x0 := nx; nx := ratmean(car i,cdr i);
      if (sn := sgn1(!*intp,nx))=0 then
         <<trmsg1 ('tht,x := r2flbf nx); go to ret>>;
      if 0=car ratdif(nx,x0) then
         <<trmsg3 ('tht,x := r2flbf nx); go to ret>>;
      if sn=sh then rplacd(i,nx) else rplaca(i,nx);
      if (sn := bdstest i) then <<x := r2flbf sn; go to ret>>;
      if (j := j-1)>0 then go to tht1;
      if bndtst (px := rlval(p,x := r2flbf nx)) then
         <<j := 4; go to tht1>>;
      gfstorval(bfabs px,x);
      if (tht!# := tht!#+1)>40 then
         <<trmsg10 'tht; x := nil; go to ret>>;
      trmsg2('tht,x,px);
      if bfzp px then go to ret
         else if pf and bfleqp(pf,bfabs px) then go to tht0
         else return x;
 ret: !*xnlist := nil; return x end;

symbolic procedure bfnewton (p,p1,nx,ri,kmax);
   begin scalar ri,px,pf,pf0,x0,xe,k,xk,xr,lp; integer m;
      !*xnlist := nil;
      gfstorval(pf0 := bfabs(px := rlval(p,nx)),nx);
      if bfzp pf0 then <<trmsg1('nwt,nx); go to ret>>;
newt: x0 := nx; if bfzp(xe := rlval(p1,nx)) then go to ret1;
      nx := bfplus(nx,xe := bfminus bfdivide(px,xe));
      px := rlval(p,nx);
     % if realroot case, check range of nx.
      if not ri then go to tst2;
      if ratleqp(car ri,xr := realrat nx) and ratleqp(xr,cdr ri)
         then go to tst;
     % fall through if nx out of range.
      nx := tighten(ri,p,bfabs px,sh!#);
      if null !*xnlist then go to ret2;
      movebds(ri,xr := ratmean(car ri,cdr ri),sh!#);
      px := rlval(p,nx := r2flbf xr);
      lp := k := xk := pf := nil; go to newt;
 tst: movebds(ri,xr,sh!#);
      if bdstest ri then go to ret;
     % test for start of loop unless already in loop.
tst2: pf0 := pf; pf := bfabs px;
      if (not lp) and pf0 and bfleqp(pf0,pf) then
          <<if kmax<2 then go to ret3 else lp := t>>;
      trmsg2 (if lp then 'loop else 'nwt,nx,px);
      if bfzp pf then <<trmsg1 ('nwt,nx); go to ret>>;
      if bfeqp(nx,x0) then <<trmsg3 ('nwt,nx);go to ret>>;
      gfstorval(pf,nx);
     % next line initializes or updates loop variables.
      if k then <<xk := bfplus(xk,nx); k := k+1>>
         else if lp then <<k := 1; xk := nx>>;
      if k=kmax then
         <<nx := bfrlmult(1.0/k,xk);
           gfstorval(bfabs (px := rlval(p,nx)),nx);
           trmsg6(k,nx,px); go to ret3>>;
      nwterr(m := m+1); go to newt;
ret3: trmsg7(nx := gfgetmin()); goto ret;
ret2: if nx then go to ret;
ret1: trmsg10 'nwt;
 ret: !*xnlist := nil; return nx end;

symbolic procedure rtsreal p;
 % Finds real roots of univariate square-free real polynomial p, using
 % sturm series, isolater and rootfind.
   begin scalar acr,acs,n,q,r,x,y,!*strm,pr,apr,!*bftag;
      integer accm!#; pr := !:prec!:;
      !*bftag := rlrt!# := t;
      r := isolatep p; % r is a list of rational number pairs.
      if null r then go to ret;
      if (n := caar lastpair p)>1 then go to gr1;
      x := (y := gfrl gfrootfind(p,nil)) . acc!#;
      if pfactor!# then x := accupr1(y,p);
      x := list x; if !*trroot then terpri(); go to ret;
 gr1: % if acc!# is not sufficient for intervals r, increase it.
      !:prec!: := acc!#;
      while schnok r do !:prec!: := !:prec!:+1;
      if !:prec!:>acc!# then acc!# := !:prec!:;
      !*xo := rl2gf 0;
      q := r; acs := acc!#; !:prec!: := rprec!#;
 lag: y := rootfind(p,intv!# := car q); apr := t;
      if null y then rerror(roots,8,"Realroots abort");
 acc: y := accuroot(gfrl !*xn,p,!*xo);
     % if acc!# is insufficient for this root, for any reason,
     % increase accuracy and tighten.
       if apr then
          <<if (acr := accupr(p,!1rp,!*xn))>acc!# then
               <<acc!# := acr; go to acc>>
            else if acr<acc!# then
               <<apr := nil; acc!# := max(acr,acs); go to acc>> >>;
     % x is root list. Check for equal roots should fail!
      if x and y=caar x then rooterr y;
      x := (y . acc!#) . x; dsply y; if !*trroot then terpri();
      acc!# := acs;
      if (q := cdr q) then go to lag;
 ret: !:prec!: := pr; return reverse x end;

symbolic procedure accupr1(y,p);
 % if acc!# is insufficient to separate this root from roots of
 % other factors of !1rp, increase accuracy.
   <<!*xn := y;
     while (acr := accupr(p,!1rp,!*xn))>acc!# do
          <<acc!# := acr; y := accuroot(y,p,rl2gf 0)>>;
     y . (acc!#+ss!#)>> where acc!#=acc!#,acr=acc!#;

symbolic procedure uniroots(p,rrts);
   <<!:prec!: := 2+precision 0; !!mfefix();
     if rrts=0 then
        (<<rprec!# := max(!!nfpd, if rprec!# then rprec!# else 7);
           uniroot0(p,0)>>
         where !*bftag=t,!*roundbf=t,rprec!#=rprec!#)
     else uniroot0(p,rrts)>>;

symbolic procedure uniroot0(p,rrts);
   begin
    scalar c,lim,n,p1,pp,q,r,r1,rr,x,cp,m,cpxt!#,pfactor!#,acc,s,
       prx!#,m1,nrst!$,intv!#,rlrt!#;
    integer ss!#;
      p := cdr(c := ckpzro p); c := car c;
     % lims!# code is applicable only when realroots is called.
      if lims!# then if not cdr lims!# or
         <<r := car lims!#; r1 := cadr lims!#;
           r neq 'minfty and
              (if xclp r then cadr r>=0 else car r>0)
           or r1 neq 'infty and
              (if xclp r1 then cadr r1<=0 else car r1<0)>>
            then c := nil;
      if atom p then <<r := c; go to ret>>;
      if cpxp p then cpxt!# := t;
      m := powerchk p; % top level powergcd factoring.
      p := gfsqfrf1 p; n := pnn!#;
      p1 := !1rp; % save original one-factor polynomial.
      if length p>1 then pfactor!# := prx!# := n;
      if m then
         <<p := gfsqfrf cdr m; m := car m;
           ss!# := s := ceillog m>>;
      lim := acc!#+max!-acc!-incr;
% strt:
      q := p; r1 := nil; r := c; acc := acc!#;
loop: pp := automod car(x := car q); cp := nil;
      if cpxp pp then
         <<pp := car(cp := csep pp); cp := cdr cp;
           if atom pp then go to cpr else pfactor!# := prx!# := n>>;
     % first find the real roots and complex pairs, if any.
 mod: pp := automod pp;
     % powerchk may succeed after sqfrf or csep succeeds.
      if (m1 := powerchk pp) then <<pp := cdr m1; m1 := car m1>>;
      if not m and not m1 then
         <<rr := doroots(pp,rrts,t); go to col>>;
      rr := if m1 then
         rtpass2(m1,rtpass1(pp,m1,rrts,if m then m1*m else m1),
           rrts,p1,acc,m)
            else rtpass1(pp,m,rrts,m);
      if m then rr := rtpass2(m,rr,rrts,p1,acc,nil);
 col: rr := for each y in rr collect car y;
     % the following test should never succeed!
      for each y in rr do if member(y,r1) then rooterr y;
      r1 := append(r1,rr);
      r := append(r,list(rr . cdr x));
 cpr: if cp and rrts>0 then
     % now find roots of cp, which has only complex roots.
         <<pp := cp; cp := nil; go to mod>>;
      if (q := cdr q) and not domainp caar q then go to loop;
 ret: return outecho r end;

symbolic procedure rtpass1(pp,m,rrts,m2);
   doroots(pp,rrts,nil) where lims!#=limadj m2,ss!#=ceillog m;

symbolic procedure rtpass2(m,rr,rrts,p1,acc,m2);
   begin scalar pp,s; s := ceillog m;
      return for each y in rr join
         (<<pp := pconstr(m,car y); doroots(pp,rrts,not m2)>>
           where !1rp=p1,acc!#=max(acc,cdr y-s),rr!#=1,
             ss!#=0,pfactor!#=(pfactor!# or cdr y-s>acc),
             lims!#=limadj m2) end;

symbolic procedure doroots(pp,r,s);
   if r=0 then rtsreal pp else allroots(pp,s);

symbolic procedure limadj m;
   if not m then lims!#
   else if length lims!#<2 then
      if remainder(m,2)=0 then list 1 else nil else
   ((if ratlessp(lval b,lval a) then list(b,a) else list(a,b))
    where a=lpwr(car lims!#,m),b=lpwr(cadr lims!#,m));

symbolic procedure lval x; if xclp x then cdr x else x;

symbolic procedure lpwr(l,m);
   if eqcar(l,'list) then 'list . lpwr(cdr l,m)
   else if atom l then l else ((car l)**m) . ((cdr l)**m);

symbolic procedure gfsqfrf1 p;
  % top level gfsqfrf, saving precision of !1rp in pr1rp!#
   <<p := gfsqfrf p; automod !1rp;
     pr1rp!# := if !*bftag then !:prec!: else !!nfpd+2; p>>;

symbolic procedure rooterr y;
   lprim list(y,"is false repeated root.  Send input to S. L. Kameny");

%unfluid '(!*gfp !*xnlist !*intp tht!# !*strm lims!# mltr!# ss!#);
%unfluid '(prec!# !*rvar acc!# !*cmplex !*xo !1rp cpxt!# pnn!# rlrt!#);
%unfluid '(pfactor!# !*xn pr1rp!# prx!# nrst!$ intv!# sh!# rprec!#);

endmodule;


end;
