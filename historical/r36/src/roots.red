module roots;  % Header module for roots package.

% Author: Stanley L. Kameny <stan_kameny@rand.org>.

% Version and Date:  Mod 1.96, 30 March 1995.

% Copyright (c) 1988,1989,1990,1991,1992,1993,1994,1995.
% Stanley L. Kameny.  All Rights Reserved.

Comment
  Revisions:
  30 March 95   Mod 1.96 adds the additional capability of solving
                 polynomials by automatically reversing the powers and
                 finding inverse roots first when direct root finding
                 fails to converge.  Examples that caused aborts in the
                 previous versions are now solved.

   2 March 94.  Mod 1.95 adds multroot, a program to solve a nest of
                 polynomials composed of one or more unary polynomials
                 solved by roots or realroots, with others solved by
                 back-substitution.  Multroot can be called directly, or
                 it is called automatically if roots or realroots is
                 given as argument a list of polynomials.

    15 Nov 93.  Error in reporting real roots in the variable rootsreal
                 corrected (in function ALLOUT).

    28 May 93.  Mod 1.94 is adapted to use the binary bigfloats of
                 Reduce 3.5 and later versions.  It will not work with
                 previous versions.  Handling of rational limits in real
                 roots functions corrected.  Allroots is strengthened to
                 handle polynomials with extremely close large roots.
                 Rounding of extremely close roots by realroots made
                 more precise.  Polynomials directly input are evaluated
                 exactly whenever possible, and with rounded evaluation
                 done only when necessary.  Some minor bugs in handling
                 polynomial inputs and limit inputs into real roots
                 functions corrected.  Rounding of complex roots changed
                 to round real and imaginary parts independently.  Root
                 reordering standardizes root order output from
                 allroots.

    9 July 92.  Mod 1.93 improves polynomial handling by using big
                 float for polynomials which the system floating point
                 representation cannot handle.  Also, it derives
                 floating point polynomials from bigfloat versions,
                 never the reverse order (which could induce errors).
                 Improved ability to handle almost degenerate complex
                 polynomials and to find difficult roots more rapidly.
                 Firstroot function now uses allroots.  Dynamic
                 adjustment of maximum iteration limits added to avoid
                 aborts on difficult examples.

    10 Oct 90.  Mod 1.92 uses exact arithmetic in bigfloat polynomial
                 evaluation and all polynomial deflations.  Extremely
                 small real or complex parts of roots can be handled.
                 Polynomials with non-unit initial coefficients and
                 almost degenerate polynomials which require high
                 precision calculations cause no trouble.  REDUCE 3.4
                 required.

    16 May 90.  Mod 1.91 adds capability for handling enormous or
                 infinitesimal coefficients, and uses powergcd logic to
                 speed up root finding when powers are all multiples of
                 a power.  Root separation is improved in difficult
                 cases in which close roots occur on different square-
                 free factors and on real and complex factors.  Better
                 starting points for iteration are found in cases where
                 one or more derivatives vanish at usual initial points.

    11 Feb 90.  Mod 1.90 avoids floating point overflows under extreme
                 conditions.  Files are reorganized to be compatible
                 with REDUCE 3.3 and also be operable under the ROUNDED
                 domain logic being developed for REDUCE 3.4.

     8 Oct 89.  Mod 1.89 avoids floating point under- and overflows
                 which could occur in SLISP.

    21 Aug 89.  Mod 1.88 contains improved precision and accuracy
                 logic and a RATROOT switch for obtaining root output
                 in rational format.  Roots are individually output to
                 the accuracy required to separate them.

    19 Jun 89.  Corrected sign change count error in procedures SCH and
                 SCHINF in isoroots module.
;

create!-package('(roots bfdoer bfdoer2 complxp allroot rootaux),
                '(contrib roots));

exports bfabs, bfnump, bfrlmult, bfsiz, ceillog, cpxp, getprec, im2gf,
        minprec, mkxcl, ncpxp, pmsg, rl2gf, roots, setflbf, setprec,
        trmsg1, trmsg10, trmsg11, trmsg12, trmsg13, trmsg2,
        trmsg3, trmsg4, trmsg6, trmsg7, trmsg8, xclp;

imports abs!:, bfloat, bfp!:, ceiling, cflot, eqcar, log10, preci!:,
        precision, precision1, timbf, trmsg10a, trmsg11a, trmsg12a,
        trmsg13a, trmsg1a, trmsg2a, trmsg3a, trmsg4a, trmsg6a,
        trmsg7a, trmsg8a;

% load!-package 'arith;   % For bootstrapping purposes.

global '(roots!-mod); roots!-mod := "Mod 1.96, 30 March 1995.";

fluid '(!*bftag !:prec!: !*rootmsg !*trroot);

global '(!!nfpd bfz!*);

symbolic procedure roots u; nil;   % To fool loader.

symbolic procedure minprec; if !*bftag then !:prec!: else !!nfpd;

symbolic smacro procedure getprec(); 2+precision 0;
symbolic smacro procedure setprec p; precision1(p-2,t);

symbolic smacro procedure bfsiz p; preci!: bfloat p;

symbolic smacro procedure bfnump p; numberp p or bfp!: p;

symbolic smacro procedure bfrlmult(r,u);
   if atom u then r*u else timbf(bfloat r,u);

symbolic smacro procedure bfabs u; if atom u then abs u else abs!: u;

symbolic smacro procedure rl2gf u;
   if !*bftag then (bfloat u) . bfz!* else (cflot u) . 0.0;

symbolic smacro procedure im2gf u;
   if !*bftag then bfz!* . (bfloat u) else 0.0 . (cflot u);

symbolic smacro procedure xclp a; eqcar(a,'list);

symbolic smacro procedure mkxcl a; if xclp a then a else 'list . a;

symbolic smacro procedure ncpxp p; bfnump p or bfnump cdar p;

symbolic smacro procedure cpxp p; not ncpxp p;

symbolic smacro procedure pmsg a;
   if !*rootmsg and !*trroot then <<write a; terpri()>>;

symbolic smacro procedure ceillog m; ceiling log10 float m;

symbolic smacro procedure setflbf b; !*bftag := b;

symbolic smacro procedure trmsg1 (a, nx);
  if !*trroot then trmsg1a (a, nx);

symbolic smacro procedure trmsg2 (a, xn, px);
  if !*trroot then trmsg2a (a, xn, px);

symbolic smacro procedure trmsg3 (a, xn);
  if !*trroot then trmsg3a (a, xn);

symbolic smacro procedure trmsg4 req;
  if !*trroot then trmsg4a req;

symbolic smacro procedure trmsg6 (k, xn, px);
  if !*trroot then trmsg6a (k, xn, px);

symbolic smacro procedure trmsg7 xn;
  if !*trroot then trmsg7a xn;

symbolic smacro procedure trmsg8;
  if !*trroot then trmsg8a();

symbolic smacro procedure trmsg10 a;
  if !*trroot or !*rootmsg then trmsg10a a;

symbolic smacro procedure trmsg11 (xn, n);
  if !*trroot then trmsg11a (xn, n);

symbolic smacro procedure trmsg12 z;
  if !*trroot then trmsg12a z;

symbolic smacro procedure trmsg13(n,xn,px);
   if !*trroot then trmsg13a(n,xn,px);

endmodule;


module bfdoer; % routines for doing bfloat arithmetic, mixed float
               % and bf arithmetic, gf and gbf arithmetic, rational
               % arithmetic and fast polynomial manipulations and form
               % conversion.

% Author: Stanley L. Kameny <stan_kameny@rand.org>.

% Version and Date:  Mod 1.96, 30 March 1995.

% Copyright (c) 1988,1989,1990,1991,1992,1993,1994,1995.
% Stanley L. Kameny.  All Rights Reserved.

Comment  support for allroot and realroot modules;

exports bfeqp, bfleqp, bfloatem, bfmin, bfsgn, cflotem,
        ckacc, deflate2, firstroot, gfconj, gfdiff, gfeqp, gfexit,
        gfnewt, gfnewtset, gfplusn, gfrlmult, gfroot, gfrootset,
        gftimesn, gfval, gtag, gzero, intdiff, isolater, listecho,
        maxbnd1, maxbound, minbnd1, minbound, mkratl, ncoeffs,
        nearestroot, powerchk, primp, primpn, r2flbf, ratdif,
        ratleqp, ratlessp, ratmax, ratmean, ratmin, ratminus, ratplus,
        realroots, rlrootno, rlrtno, rlval, root_val, rtreorder, sch,
        simpgi, univar, ungfform, unshift, xnshift;

imports a2gf, abs!:, accupr, accupr1, accuroot, automod, bf2flr, bfabs,
        bfinverse, bfloat, bfminus, bfnump, bfnzp, bfp!:, bfrlmult,
        bfsqrt, bfzp, cflot, ckprec, cpxp, cvt2, cvt5, difference!:,
        divbf, domainp, ep!:, eqcar, equal!:, errorp, errorset!*, exp,
        exptbf, gbfmult, gcdn, getprec, gf2bf, gfdiffer, gffinit,
        gffmult, gffplus, gfftimes, gfim, gfnewton, gfplus, gfrl,
        gfrsq, gfrtrnd, gftimes, gfzerop, grpbf, im2gf, infinityp,
        invbf, invpoly, isolatep, lastpair, leadatom, leq, lessp!:,
        limchk, log, make!:ibf, min!:, minus!:, minusp!:, mk!*sq,
        mkquote, mkxcl, msd!:, mt!:, ncpxp, neq, nrstroot, numr, off,
        on, orgshift, outmode, over, plubf, plus!:, preci!:, precision,
        r2bf, r2fl, realrat, rerror, restorefl, rl2gf, rlrtno2, rndpwr,
        rootrnd, roots, schinf, schplus, setflbf, setprec, sgn, sgn1,
        simp!*, sturm1, timbf, times!:, trmsg1, trmsg12, trmsg13,
        trmsg3, uniroots, univariatep;


fluid '(!*bftag !*pcmp !*rvar !*strm lims!# mltr!# emsg!# !*xo !*gfp
        !*powergcd pfl!# acfl!# accm!# froot!# !*backtrace);

fluid '(acc!# sprec!# pfactor!# rr!# ss!# !*xn !*zp !*xobf !*noeqns
        !*msg rootacc!# rootacc!#!#);

fluid '(iniprec!#);

global '(bfz!* bfone!* bfhalf!* bftwo!* prd!% log2 bfee!* !!ee);

bfee!* := bfloat !!ee;

symbolic smacro procedure dnp x; eqcar(x,'!:dn!:);

symbolic procedure bfleqp(a,b); if atom a then a<=b else not grpbf(a,b);

symbolic procedure bfeqp(a,b); if atom a then a=b else
   ((zerop ma and zerop mb or ep!: a=ep!: b and ma=mb)
    where ma=mt!: a,mb=mt!: b);

symbolic procedure bfsgn u;
   if atom u then sgn u else sgn mt!: u;

symbolic procedure bfmin(u,v);
   if atom u then min(u,v) else min!:(u,v);

symbolic procedure gfconj u; (car u) . (bfminus cdr u);

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

symbolic smacro procedure sqr!: a; times!:(a,a);

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
         if a=0 then return (0 . 1);
         g := gcdn(a,d); return (a/g) . (d/g) end;

symbolic procedure ratmin(a,b); if ratlessp(a,b) then a else b;

symbolic procedure ratmax(a,b); if ratlessp(a,b) then b else a;

symbolic procedure ratlessp(a,b); car ratdif(a,b)<0;

symbolic procedure ratleqp(a,b); car ratdif(a,b)<=0;

symbolic procedure listecho(l,n); if n<2 then l else
   begin scalar c; for each x in l do
         <<for i := 1:n do c := append(c, list x)>>; return c end;

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
     if atom gfrl p and (infinityp gfrl p or infinityp gfim p)
        then error(0,"gfval -> infinity") else p>>;

symbolic smacro procedure rndpwrxc(x,c);
   if atom gfrl x then c else (rndpwr gfrl c) . rndpwr gfim c;

symbolic procedure gfrval(p,x);
 % evaluate real polynomial for gf or gbf value x.
   if gfzerop x then rl2gf(if caar p=0 then cdar p else 0)
   else if bfzp gfim x then rl2gf rlval(p,gfrl x) else
   begin scalar c;
         c := rl2gf car (p := cdr ncoeffs p);
         for each i in cdr p do
            <<c := gftimesn(x,c);
              if i then c := ((bfplusn(i,gfrl c)) . gfim c)>>;
         return rndpwrxc(x,c) end;

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
   if atom gfrl u then gffplus(u,v) else
     (plus!:(gfrl u,gfrl v)) . plus!:(gfim u,gfim v);

symbolic procedure gftimesn(u,v);
   if atom gfrl u then gfftimes(u,v) else
     begin scalar ru,iu,rv,iv;
        ru := gfrl u; iu := gfim u; rv := gfrl v; iv := gfim v;
        return (difference!:(times!:(ru,rv),times!:(iu,iv))) .
           plus!:(times!:(ru,iv),times!:(iu,rv)) end;

symbolic procedure minbound (p,o);
 % estimate min root distance from origin o for polynomial p.
   <<p := if atom (p := automod ckprec p) then nil else minbnd1(p,o);
     !*bftag := bf; restorefl(); outmode p>> where bf=!*bftag,acc!#=6;

symbolic operator maxbound,minbound;

symbolic procedure maxbound p;
  <<p := maxbnd1 ckprec p; restorefl(); outmode p>>;

symbolic procedure maxbnd1 p;
 % maxbound of roots of real or complex float polynomial,
 % in floating point avoiding under/ and over/ flows.
   begin scalar nc,bf,m,pr;
      bf := !*bftag; pr := getprec();
      if atom (p:= gffinit p) then return nil;
      setprec 8; p := bfloatrd p;
      nc := ncpxp p; p := reverse p;
      !*bftag := bf;
      m := bfrlmult(2,maxbdbf(p,nc));
      setprec pr;
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
  (y/n) where y=log(m/2.0**p)+(p+ep!: x)*log2
        where p=msd!: m-1 where m=mt!: x;

symbolic procedure fl2bfexp m; if !*bftag then expfl2bf m else exp m;

symbolic procedure expfl2bf m; if m<0 then invbf expfl2bf(-m) else
   exptbf(bfee!*,mi,bfloat exp mf) where mf=m-mi where mi=fix m;

symbolic procedure ungfform p;
   begin scalar r; integer n;
      if caar p=0 then
         <<if bfnzp cdar p then r := cdar p; p := cdr p>>;
      for each i in p do
        if bfnzp cdr i then r := (((!*rvar or 'x) . car i) . cdr i) . r;
      return r end;

symbolic procedure gtag c;
   if fixp c then '!:gi!: else '!:cr!:;

symbolic procedure gzero c;
   if fixp c then 0 else if floatp c then 0.0 else bfz!*;

symbolic procedure simpgi u; ('!:gi!: . u) ./ 1;

put('!:gi!:,'simpfn,'simpgi);

symbolic procedure rlrtno p;
   <<sturm1 p; p := schinf(-1)-schinf 1; !*strm := nil; p>>;

symbolic procedure roots p;
   <<lims!# := nil; uniroots(car p,1)>> where froot!#=nil;

symbolic procedure firstroot p;
   <<lims!# := nil; uniroots(car p,1)>> where froot!#=t;

symbolic procedure root_val x;
  % produces list of root values at system precision (or greater if
  % required to separate roots.)
  roots_at_prec x where !*noeqns=t;

symbolic procedure roots_at_prec x;
  % produces list of root equations at system precision (or greater if
  % required to separate roots.)
   roots x
     where rootacc!#!#=p,iniprec!#=p where !*msg=nil,p=precision 0;

symbolic(for each n in '(roots firstroot root_val roots_at_prec) do
  put(n,'psopfn,n));

symbolic procedure outril p;
   'list . for each i in p collect
         'list . list(mk!*sq car i,mk!*sq cdr i);

symbolic procedure gfrootset(p,r,b);
 if errorp
   (r := errorset!*({'gfrootfind,mkquote p,mkquote r},!*backtrace))
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

symbolic procedure gfnewtset(n,p,y,xo,b);
   begin scalar y1,b;
      if (b := !*bftag) then go to ret;
      if not atom car y then go to mbf;
      if not errorp (y1 := errorset!*
        ({'gfns1,n,mkquote p,mkquote y,mkquote xo},!*backtrace))
         then return car y1;
 mbf: gfsetmsg(y1,b,'gfnewton);
      p := !*gfp; !*xo := xo := gf2bf xo; y := gf2bf y; !*bftag := t;
 ret: y := gfns1(n,p,y,xo); !*bftag := b; return y end;

symbolic procedure gfns1(n,p,y,xo);
  <<!*xo := xo; trmsg13(n,xnshift y,gfval(p,y)); gfnewton(p,y,4)>>;

symbolic procedure gfnewt args;
   nrstroot(gffinit p,r,if cpx then 0 else t)
    where rootacc!#!#=pr,rprec!#=pr
    where p=car args,r=cadr args,cpx=caddr args,pr=precision 0;
   % direct call to gfnewton. If cpx then retain imaginary part, no
   % matter how small (but either p or r must be complex).

symbolic procedure gfroot args;
   nrstroot(gffinit p,r,list if cpx then 0 else t)
    where rootacc!#!#=pr,rprec!#=pr
    where p=car args,r=cadr args,cpx=caddr args,pr=precision 0;
   % direct call to gfrootfind. If cpx then retain imaginary part, no
   % matter how small (but precision will have to be high enough).

symbolic(for each n in '(gfnewt gfroot) do put(n,'psopfn,n));

symbolic procedure univar y;
   (if domainp (y := numr p) then 0 else
    if univariatep y or
       <<on complex; univariatep (y := numr resimp p)>> or
       <<on rounded; univariatep (y := numr resimp p)>> then y)
    where p=simp!* y,!*msg=nil;

symbolic procedure ckacc(q,p,r);   % p,q,r,!*xo,!*xn all bfloat
   if not(r and caar lastpair p>1 and (rr!#>1 or pfactor!#)) then r
   else if caar lastpair q=1 then
      <<acc!# := cdr(r := accupr1(r,q)); car r>> else
   begin scalar ac,rl,s,nx; rl := bfzp gfim r;
      r := <<if not pfl!# then accuroot(r,q,!*xobf); !*xn>>;
loop: ac := accupr(q,p,r);
      if pfl!# then
         <<if (s := acc!# - (ac := ac + ss!#))>0 then
              <<acfl!# := t; accm!# := accm!#-s>>;
           acc!# := ac;
           r := if rl then rootrnd gfrl r else gfrtrnd r;
           trmsg12 r;
           return r>>
      else if ac>acc!# then <<acc!# := ac; go to gfr>>;
      if s or ss!#=0 then return r;
      s := t; acc!# := acc!# + ss!#:
 gfr: nx := r; r := <<accuroot(r,q,!*xobf); !*xn>>;
      if gfeqp(nx,r)
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

symbolic procedure rtreorder cc; if cc then
   if dnp caar cc or not bfnump caar cc and dnp caaar cc then
    (<<for each j in cc do p := max(p,rrsiz car j);
     prd!% := 2*p; sort(cc,function dnafterp)>> where p=0)
   else sort(cc,function bfnafterp);

symbolic procedure bfnafterp(a,b);
  (if bfnump ca then
     if bfnump cb then rd!:minusp rd!:difference(cb,ca)
     else ((if rd!:zerop d then rd!:minusp cdr cb else rd!:minusp d)
           where d=rd!:difference(car cb,ca))
   else if bfnump cb then
     ((if rd!:zerop d then not rd!:minusp cdr ca else rd!:minusp d)
      where d=rd!:difference(cb,car ca))
   else
   ((if rd!:zerop d then rd!:minusp rd!:difference(cdr cb,cdr ca)
     else rd!:minusp d) where d=rd!:difference(car cb,car ca)))
  where ca=car a,cb=car b;

symbolic procedure dnafterp(a,b);
  (if dnp ca then
     if dnp cb then dnafterp1(ca,cb)
     else if dnequal(ca,car cb) then mt!: cdr cb<0
       else dnafterp1(ca,car cb)
   else if dnp cb then
     if dnequal(car ca,cb) then mt!: cdr ca>0 else dnafterp1(car ca,cb)
   else
   ((if dnequal(cca,ccb) then dnafterp1(cdr ca,cdr cb)
     else dnafterp1(cca,ccb))
    where cca=car ca,ccb=car cb))
  where ca=car a,cb=car b;

symbolic procedure dnequal(a,b);
   mt!: a=0 and mt!: b=0 or ep!: a=ep!: b and mt!: a=mt!: b;

symbolic procedure dnafterp1(a,b);
   if ep!: a=ep!: b then mt!: a>mt!: b else
     ((if d=0 then ma>mb else
         if d>prd!% then ma>0
         else if d<-prd!% then mb<0
         else if d>0 then ma*10**d>mb
         else ma>mb*10**-d)
       where d=ep!: a - ep!: b, ma=mt!: a, mb=mt!: b);

endmodule;


module bfdoer2; % routines for doing bfloat arithmetic, mixed float
                % and bf arithmetic, gf and gbf arithmetic, rational
                % arithmetic and fast polynomial manipulations and form
                % conversion, part 2.

% Author: Stanley L. Kameny <stan_kameny@rand.org>.

% Version and Date:  Mod 1.96, 30 March 1995.

% Copyright (c) 1988,1989,1990,1991,1992,1993,1994,1995.
% Stanley L. Kameny.  All Rights Reserved.

Comment  support for allroot and realroot modules;

exports allout, automod, bfixup, bfmax, cexpand, ckprec, ckpzro, csize,
        ftout, gf2flt, gffinit, gfrtrnd, gfsimp, gfsqfrf, mkdn,
        n2gf, nbfout, nwterr, nwterrfx, outecho, outmode, pbfprint,
        pconstr, pflupd, restorefl, rootprec, rootrnd, seteps, smpart,
        stuffr, trmsg10a, trmsg11a, trmsg12a, trmsg13a, trmsg1a,
        trmsg2a, trmsg3a, trmsg4a, trmsg6a, trmsg7a, trmsg8a, trmsg9,
        trmsg17, xnsiz;

imports !*crn2cr, !*f2q, abs!:, bfloat, bfloatem, bfmin, bfminus,
        bfnump, bfnzp, bfp!:, bfplus, bfprin0, bfrndem, bfsiz, bftimes,
        bfzp, calcprec, ceiling, ceillog, cflot, conv2gi2, conv2gid,
        cpxp, crp, divbf, dmconv0, dmconv1, domainp, ep!:, eqcar,
        errorp, errorset!*, find!!nfpd, floor, getprec, gf2bf, gf2fl,
        gfconj, gffinitr, gfim, gfminus, gfrl, gzero, i2bf!:, lastpair,
        lessp!:, lispeval, listecho, log10, lprim, make!:ibf, make!:rd,
        maxbnd1, minprec, mk!*sq, mkgirat, mkinteg, mkquote, mt!:,
        mvar, neq, normbf, numr, off, on, p1rmult, pmsg, preci!:,
        precision, precmsg, r2bf, rdp, rerror, reversip, rl2gf,
        round!:mt, rtreorder, setflbf, setprec, simp!*, sizatom, sqfrf,
        sqrt, tagim, tagrl, times!:, ungffc, ungfform, univar, unshift;

fluid '(!*trroot !*rootmsg !*multiroot !*roundbf !:bprec!: !*complex
  !*msg !*bftag !*sqfree !*ratroot !*nosqfr rootacc!# iniprec!#);
switch trroot,rootmsg,multiroot,ratroot;
global '(!!nfpd !!nbfpd !!flim bfz!* log2of10 rlval!# cpval!#);
global '(!!shbinfl rootsreal rootscomplex den!* lm!# !!flprec);
flag('(rootsreal rootscomplex),'share);
fluid '(!*pfsav pr!# acc!# bfl!# emsg!# eps!# rootacc!#!#);
fluid '(!*xmax !*xmax2 !*rvar nwmax!# lgmax!# nozro!# !1rp);
fluid '(!*xo !*exp !*pcmp !*multrt lgmax!# nwmax!# rnd!# rndl!#);
fluid '(!*keepimp sqf!# exp!# sprec!# rprec!# !*bfsh incmsg!$
  cpx!# pfactor!# rr!# pnn!# nn!# prx!# rlrt!# !*noeqns);

global '(!*rootorder); symbolic (!*rootorder := t);

symbolic procedure gf2flt a;
  % force into float format, except if !shbinfl or float error.
   if !*roundbf or !!shbinfl then a else
      <<(if errorp gx then a else car gx)
         where gx=errorset!*(list('gf2fl,mkquote a),nil)>>;

symbolic procedure gfbfxn nx;
 gf2bf if !*bfsh then
      if bfnump nx then bfplus(nx,gfrl !*xo) else gfrl unshift nx
   else if bfnump nx then nx else unshift nx;

symbolic procedure print_the_number xn;
  if atom xn then write xn
   else if numberp car xn then <<write car xn;
                              if cdr xn >=0 then write "+";
                              write cdr xn;
                              write "*I" >>
   else if rdp xn then bfprin0a xn
    else <<bfprin0a car xn;
           if mt!: cdr xn >= 0 then write "+";
           bfprin0a cdr xn;
           write "*I" >>;

symbolic procedure bfprin0a u;
  bfprin0 u where !*nat = nil;

symbolic procedure trmsg1a (a,nx);
   if !*trroot then <<
     write a,",px=0 => ";
     print_the_number gfbfxn nx;
     terpri()
   >>;

symbolic procedure trmsg2a (a,xn,px);
   if !*trroot then <<
     write a," -> xn=";
     print_the_number gfbfxn xn;
     trmsg5(xn,px)
   >>;

symbolic procedure trmsg3a (a,xn);
   if !*trroot then <<
     write a,",xn=x0 => ";
     print_the_number gfbfxn xn;
     terpri()
   >>;

symbolic procedure trmsg4a req; if !*trroot then
   <<write "number of "; if nozro!# then write "nonzero ";
     write "real roots = ",req; terpri()>>;

symbolic procedure trmsg5(nx,px);
   <<terpri(); write "      "," px="; print_the_number px; terpri()>>;

symbolic procedure trmsg6a(k,xn,px);
   if !*trroot then
      <<write "mean of ",k," xn->"; print_the_number gfbfxn xn;
        trmsg5(xn,px)>>;

symbolic procedure trmsg7a xn;
   if !*trroot
    then <<write "best value ="; print_the_number gfbfxn xn; terpri()>>;

symbolic procedure trmsg8a;
   if !*trroot then
      <<if !*bftag then write "Precision is ",getprec()
           else write "!nfpd = ",!!nfpd; terpri()>>;

symbolic procedure trmsg9 a;
   lprim{"Roots precision increase to ",a};

symbolic procedure trmsg10a a;
   <<lprim{"restart at higher precision called by function ",a};
     terpri()>>;

symbolic procedure trmsg11a (xn,n);
   if !*trroot
     then <<write "n=",n," -> "; print_the_number gfbfxn xn; terpri()>>;

symbolic procedure trmsg12a z;
   if !*trroot then <<write "acc(",acc!#,") ->";
                      print_the_number outtrim z; terpri()>>;

symbolic procedure trmsg13a(n,xn,px);
   if !*trroot
     then <<write "n=",n,",xn="; print_the_number gfbfxn xn;
            trmsg5(xn,px)>>;

symbolic procedure trmsg17 y;
   lprim list("Roots ",y," equal to acc ",acc!#);

symbolic procedure nwterr m;
 if m>nwmax!#+lm!# then
    <<restorefl();
      emsg!# := list("max NWT limit",nwmax!#+lm!#,"exceeded");
      error(0,emsg!#)>>;

symbolic procedure nwterrfx(n,cp);
  if n<3 then 0 else
   fix((n-2)*sqrt max(0,0-15+minprec())*if cp then 4 else 1);

symbolic procedure seteps;
 eps!# := make!:ibf(1,-(if !*bftag then !:bprec!: else !!nbfpd));

symbolic procedure pconstr(m,r);
 % set !*bftag and return equivalent of x^m-r in bfloat form.
  bfloatem prxflot(if prx!# then max(prx!#,ac) else ac,
   {0 . if rl then bfminus if bfnump r then r else car r else gfminus r,
         m . if rl then 1.0 else rl2gf 1.0})
   where rl=(bfnump r or bfzp cdr r),ac=acc!#+2+ceillog m;

symbolic procedure prxflot(pr,p);
   <<setprec(if setflbf(rlrt!# or pr>!!nfpd) then pr else !!nfpd);
     bfrndem bfloatem p>>;

symbolic procedure smpart y;
   (if mt!: a>0 and mt!: b>0 then
      (if lessp!:(b,times!:(a,c)) then t
       else if lessp!:(a,times!:(b,c)) then 0))
    where a=abs!: round!:mt(gfrl y,20),b=abs!: round!:mt(gfim y,20),
       c := make!:ibf (1, -!:bprec!:);

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

symbolic procedure rootacc n;
  if null n or numberp n and (n := abs fix n)>=6 then
     rootacc!#!# := n else
    rerror(roots,1,{"nil or numeric input >= 6 required."});

symbolic procedure rootprec n;
  if null n or numberp n and (n := abs fix n)>=!!flprec+4 then
     rprec!# := n else
    rerror(roots,2,{"nil or numeric input >=",!!flprec+4,"required."});

symbolic procedure csize p;
   begin integer n;
     for each c in gffinitr p do n := max(n,xnsiz cdr c); return n end;

symbolic operator rootacc, rootprec, csize;

symbolic procedure ckpzro p;
 % solve for zero roots and reduce p.
   begin scalar c,n; p := ckprec p;
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
   <<find!!flim();
     !*rvar := nil;
     rootsreal := rootscomplex := nil; cpx!# := !*complex;
     bfl!# := !*bftag;
     acc!# := rootacc!# := rootacc!#!# or 6;
    % the following line is corrected so :prec: restores properly.
     pr!# := getprec();
    % prevent floating of polynomial with decimal or fractional
    % coefficients when rounded is on initially.
     <<if (rnd!# := !*rounded) then off rounded;
       if (rndl!# := !*roundall) then off roundall>> where !*msg=nil;
     sqf!# := !*sqfree; exp!# := !*exp; !*sqfree := !*exp := t;
    % simp!* is called on p in univar only.  Result is not dependent on
    % system precision unless p must be evaluated with rounded on.
     if null(p := univar p) then
       <<restorefl();
         rerror(roots,3,"Univariate polynomial required")>>;
     if !*rounded then msgpri(nil,
      "Polynomial simplified in ROUNDED mode at precision",precision 0,
      ":       root locations depend on system precision.",nil)
       where !*msg=t;
    % next line corrected so internal precision is correct at start.
     setprec max(rprec!# or (!!nfpd+2),acc!#+2); p>>;

symbolic procedure restorefl;
   <<setprec pr!#;
     !*sqfree := sqf!#; !*exp := exp!#;
    % restore input dmode.
     <<if !*complex and not cpx!# then off complex;
       if rnd!# then on rounded else if !*rounded then off rounded;
       if rndl!# then on roundall>>
      where !*msg=nil;
     nozro!# := pr!# := sqf!# := exp!# := cpx!# := rnd!# :=
       rndl!# :=  nil>>;

symbolic procedure mkequal l;
  'list . (for each y in l collect {'equal,!*rvar or 'x,outmode y});

symbolic procedure outmode j;
   if null j then j
   else if bfnump j and bfzp j then 0 else if fixp j then j
   else mk!*sq if !*ratroot then mkgirat j else !*f2q
      if floatp j then make!:rd j
       else if eqcar(j,'!:dn!:) then decimal2internal(cadr j,cddr j)
       else if domainp j then j
       else if eqcar(car j,'!:dn!:) then
         '!:cr!: . (cdr decimal2internal(cadar j,cddar j)) .
                   cdr decimal2internal(caddr j,cdddr j)
       else '!:cr!: . if bfp!: car j then (cdar j) . cddr j else j;

symbolic procedure allout c;
   begin scalar rl,cmp; integer a;
      c := for each j in c collect car j;
      if c and not !*ratroot and
       ((pairp r and (not bfnump r and car r eq '!:dn!:
           or not bfnump car r and caar r eq '!:dn!:)) where r=car c)
        then for each j in c do a := max(a,rrsiz j);
      restorefl(); % precision has been restored to initial value.
      for each x in c do
         if atom x or eqcar(x,'!:dn!:) then rl := x . rl
            else cmp := x . cmp;
      !*msg := t;
   % Increase system precision if too low to print out all roots.
      precmsg a;
   % If system precision is already high, warn about inputting values.
      if a<precision 0 and a>max(rootacc!#!# or 6,!!flprec)
       then msgpri(nil,
        "input of these values may require precision >= ",a,nil,nil);
       !*msg := nil;
      % the following change improves roots, solve interface.
      c := if !*noeqns then
         <<rootscomplex := rootsreal := nil;
           'list . for each j in c collect outmode j>>
         else
           <<rootscomplex := mkequal reversip cmp;
             rootsreal := mkequal reversip rl; mkequal c>>;
      return c end;

symbolic procedure rrsiz u;
  % determine precision needed for printing results.
   if numberp u then length explode abs u
   else if u eq 'i then 0
   else if atom u then rrsiz sizatom u
   else if eqcar(u,'minus) then rrsiz cadr u else
     ((if not atom y then
         if eqcar(y,'!:dn!:) then max(rrsiz car u,rrsiz cdr u)
         else rerror(roots,7,"unknown structure")
       else if y memq '(plus difference) then
         begin integer r;
           for each n in cdr u do r := max(r,rrsiz n);
           return r end
       else if y memq '(times quotient) then
         for each n in cdr u sum rrsiz n
       else if y eq '!:dn!: then length explode abs car normdec cdr u
       else rerror(roots,7,"unknown structure")) where y=car u);

symbolic procedure outecho r;
   allout for each c in r join
      listecho(car c,if !*multiroot then cdr c else 1);

symbolic procedure find!!flim;
   <<!!flim := 0; repeat <<n := n/10; !!flim := !!flim+1>>
       until explode(1.0+n)=explode 1.0; !!flim>> where n=1.0;

symbolic procedure xnsiz x;
  ceiling (xnsiz1 x / log2of10);

symbolic procedure xnsiz1 x;
   if bfnump x then bfsiz x
   else if bfzp gfim x then bfsiz gfrl x
   else if bfzp gfrl x then bfsiz gfim x else
   <<x := gf2bf x;
     ((max(preci!: gfrl x+e1,preci!: gfim x+e2)-min(e1,e2))
      where e1=ep!: gfrl x,e2=ep!: gfim x)>>;

symbolic procedure outtrim j;
   if !*roundbf or acc!#>!!flim then gf2bf j else
     ((if errorp d then gf2bf j else car d)
       where d=errorset!*({'gf2fl,mkquote j},nil));

symbolic procedure bfmax p;
  <<!*xmax := maxbnd1 p;
    ((!*xmax2 := bftimes(m,m))
     where m=if !*bftag then bfloat !*xmax else cflot !*xmax); !*xmax>>;

symbolic procedure nbfout x; bfloat ftout x;

symbolic procedure bfixup x; if !*bftag then gf2bf x else gf2fl x;

symbolic procedure ftout x;
   if atom x then cflot x
   else if rdp x then cdr x else x;

find!!flim();

symbolic procedure cexpand cc;
   begin scalar c;
      if !*rootorder then cc := rtreorder cc;
      for each r in cc do
         <<if (not !*pcmp) then
             if not bfnump car r and bfnump caar r
               then c := ((gfconj car r) . cdr r) . c
             else if not eqcar(car r,'!:dn!:) and eqcar(caar r,'!:dn!:)
               then c := ((cdnconj car r) . cdr r) . c;
           c := r . c>>;
      return c end;

symbolic procedure cdnconj u;
  (car u) . (cadr u . ((minus caddr u) . cdddr u));

symbolic procedure mkdn u;
 if atom car u then '!:dn!: . normdec u else (mkdn car u) . mkdn cdr u;

symbolic procedure normdec x;
   begin scalar mt,s;integer ep;
      if (mt := car x)=0 then go to ret;
      if mt<0 then <<mt := -mt; s := t>>;
      ep := cdr x;
      mt := reversip explode mt;
      while car mt eq '!0 do <<mt := cdr mt; ep := ep+1>>;
      mt := compress reversip mt;
      if s then mt := -mt;
 ret: return mt . ep end;

symbolic procedure rootrnd y; rtrnda(y,acc!#);

symbolic procedure rtrnda(r,a);
  if bfzp r then <<rlval!# := 0 . 0; r>> else
  ((decimal2internal(car (rlval!# := u),cdr u))
   where u=round!:dec1(r,a));

symbolic procedure gfrtrnd y;
   (begin scalar rl,rld,im; y := cdr y;
      rl := rtrnda(a,acc!#); rld := rlval!#;
      im := rtrnda(y,acc!#);
      cpval!# := if car rlval!# = 0 then rld else rld . rlval!#;
      return rl . im end)
    where a=car y;

symbolic procedure gfsqfrf p;
   begin scalar m,cp,q,dmd;
      if caar lastpair p=1 or !*nosqfr then go to nof;
      cp := cpxp(q := mkinteg p);
      dmd := dmode!*; if !*complex then dmd := get(dmd,'realtype);
      m := !*msg; off msg;
      if dmd then lispeval {'off,mkquote list(dmd := get(dmd,'dname))};
      q := sqfrf if cp then ungffc q else ungfform q;
      if dmd then lispeval {'on,mkquote list dmd}; if m then on msg;
      if cdr q then pfactor!# := t else if cdar q=1 then go to nof;
      !1rp := p1rmult q; return q;
 nof: q := list(p . 1); !1rp := p; return q end;

symbolic procedure automod p; % p is always returned in bfloat form.
   if bfnump (p := gffinit p) then p else
   begin integer n,s,s2; scalar a,d,m,nl,pr,nc,dd; rr!# := 0;
      if null cdr p then <<n := getprec(); go to sel>>;
    % determine precision of calculation and set mode.
    % first find minimum precision for normalizing p.
      m := car(d := car lastpair(p := bfloatem p)); d := cdr d;
      for each c in cdr reverse p do n := max(n,xnsiz cdr c);
      pr := getprec();
      setprec(if (nc := bfnump d) and abs mt!: d=1
         or not nc and
            ((a := mt!: car d)=0 and abs(dd := mt!: cdr d)=1 or
              dd=0 and abs a=1) then n else 2+max(n,xnsiz d));
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
      setflbf nil; setprec pr;
 cfl: if errorp errorset!*({'cflotem,mkquote p},nil)
         then go to bfl else return p;
 sel: if not !*bftag then go to cfl;
 bfl: setflbf t; setprec n; return p end;

symbolic procedure gffinit p;
   if not domainp p and numberp caar p then p
   else if numberp p
      or not atom p and member(car p,domainlist!*) then 0
   else
     begin scalar !*msg,cp;
       cp := !*complex; on complex;
       p := gfform p;
       if not cp then off complex; return reformup p end;

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
   if bfnump u or rdp u then u
    else if eqcar(u,'!:rn!:) then r2bf cdr u
    else
      <<if eqcar(u,'!:crn!:) then u := !*crn2cr u;
        u := if crp u
             then (tagrl u) . tagim u
          else if eqcar(u,'!:gi!:)
             then (normbf i2bf!: cadr u) . normbf i2bf!: cddr u
          else cdr u;
        if bfzp cdr u then car u else u>>;

symbolic procedure reformup q; if domainp q then q else
  % returned q will be bfloat.
   begin scalar c,fg,d; integer n;
      for each v in q do  % check for complex, float, bfloat.
         <<v := cdr v; n := max(n,xnsiz v);
           if floatp v or bfp!: v then c := gzero v
           else if not atom v then
              <<fg := t;
                if not fixp (v := car v) then c := gzero v >> >>;
       % make coefficients homogeneous in type and assure
       % adequate precision;
       % convert coefficients to all real or all complex.
      if fg then
         <<q := for each v in q collect (car v) .
            <<d := cdr v; if bfnump d then d . 0 else d>>;
           d := q;
           repeat if bfnzp cadar d then fg := nil
                 until not fg or null(d := cdr d);
           if fg then
              q := for each v in q collect (car v) . cddr v>>;
      if bfp!: c or n>!!nfpd then <<q := bfloatem q; setflbf t>>
         else if floatp c then <<q := bfloatem q; setflbf nil>>;
      if n+2>getprec() then setprec(n+2);
      return q end;

endmodule;


module complxp; % Support for complex polynomial solution.

% Author: Stanley L. Kameny <stan_kameny@rand.org>.

% Version and Date:  Mod 1.96, 30 March 1995.

% Copyright (c) 1988,1989,1990,1991,1992,1993,1994,1995.
% Stanley L. Kameny.  All Rights Reserved.

Comment   support for modules allroot and realroot;

exports a2gf, a2rat, accupr, bdstest, bfprim, bfrndem, calcprec, csep,
        cvt2, cvt5, deflate1, deflate1c, dsply, getroot, gffinitr,
        gfgetmin, gfshift, gfstorval, invpoly, leadatom, limchk,
        mkgirat, mkinteg, mkpoly, orgshift, p1rmult, rlrtno2, rrpwr,
        rxgfc, rxgfrl, rxrl, schnok, sturm1, ungffc, xoshift;

imports !!mfefix, !*f2q, abs!:, ashift, automod, bfabs, bfdivide,
        bfixup, bflessp, bfloat, bfloatem, bfnump, bfnzp, bfsqrt,
        bfzp, ceiling, ceillog, cflot, cflotem, cpxp,
        decimal2internal, deflate2, denr, divbf, divide!:, domainp,
        ep!:, eqcar, equal!:, errorp, errorset!*, floor, ftout, gcdn,
        geq, gf2bf, gffinit, gfim, gfplus, gfplusn, gfquotient, gfrsq,
        gfrtrnd, gfsimp, gftimes, gftimesn, gfval, gfzerop,
        greaterp!:, gtag, hypot, intdiff, lastpair, lcm, lessp!:, log,
        make!:ibf, minbnd1, minus!:, mk!*sq, mkquote, mkratl, mkxcl,
        mt!:, n2gf, ncoeffs, ncpxp, neq, num, numr, plubf, plus!:,
        pmsg, preci!:, prepsq, primp, primpn, r2bf, r2flbf, ratlessp,
        realrat, rerror, reval, reversip, rl2gf, rndpwr,
        rootrnd, round!:mt, sch, schinf, sgn, sgn1, simp!*, sqrt,
        sturm, timbf, times!:, typerr, xclp;


fluid '(acc!# !*intp !*multrt !*strm sprec!# !*xo !*rvar rootacc!#!#);
fluid '(!*bftag !*rootmsg lims!# pfactor!# !*xnlist accm!# pflt!#);
global '(limlst!# bfone!*);

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

symbolic smacro procedure rl2gfc x;
   x . if atom x then 0.0 else bfz!*;

symbolic procedure accupr(p,q,r);
   begin scalar cq,cp,rl,!*bftag,s; integer ac;
      if caar lastpair q<2 then return 1; !*bftag := t;
      r := gf2bf r; cq := cpxp (q := bfloatem q); cp := cpxp p;
      rl := bfnump r or bfzp gfim r and (r := car r);
      q := % deflate root r or complex pair but do not round.
       if rl then cdr if cq then deflate1c(q,rl2gf r) else deflate1(q,r)
       else if not cq then deflate2(q,r)
       else cdr
         if cp then deflate1c(q,r)
         else deflate1c(cdr deflate1c(q,r),(car r) . minus!: cdr r);
      if caar q>0 then <<ac := acc!#; go to ret>>;
      if rl then r := rl2gfc r;
      p := bfsqrt bfloat gfrsq r;
     % decimal computation proved to be more precise in critical cases.
      p := round!:dec1(p,acc!#+2);
      p := 1 + cdr p + length explode abs car p;
loop: s := if caar lastpair q>1 then bfloat minbnd1(q,r) else
         bfsqrt gfrsq gfplus(r,
           <<s := cdar bfprim q; if not cq then rl2gf s else s>>);
     % decimal computation used here also for precision.
      s := round!:dec1(s,acc!#+2);
      ac := max(ac,rootacc!#,p-cdr s-length explode abs car s);
     % repeat minbnd1 test for conj r only if r is a complex pair and
     % q is complex.
      if cq and not rl and not cp then
         <<r := (car r) . minus!: cdr r; rl := t; go to loop>>;
 ret: if rootacc!#!# then ac := max(ac,rootacc!#!#);
      accm!# := max(ac,accm!#); return ac end;

symbolic procedure orgshift(p,org);
   %shifts origin of real or complex polynomial to origin org,
   %with p and org of the same form.
   begin scalar s,cp; integer n;
      if gfzerop(if (cp := cpxp p) then org else rl2gf org)
         then return p;
      org := gf2bf org;
      if numberp leadatom cdar p then p := bfloatem p;
      if cp then while p do
         <<p := deflate1c(p,org);
           if not gfzerop car p then s := (n.car p).s;
           n := n+1; p := cdr p>>
         else while p do
            <<p := deflate1(p,org);
              if bfnzp car p then s := (n.car p).s;
              n := n+1; p := cdr p>>;
       return reversip if pflt!# then cflotem s else bfrndem s end;

symbolic procedure bfrndem s;
   (for each c in s collect (car c) .
      if cp then (rndpwr cadr c) . rndpwr cddr c else rndpwr cdr c)
   where cp=cpxp s;

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

%symbolic procedure iscale(d,y); mt!: y*2**(d+ep!: y);
symbolic procedure iscale(d,y); ashift(mt!: y,d+ep!: y);

symbolic procedure mkinteg p;
  %converts a polynomial in gfform to the smallest exactly equivalent
  %polynomial with integral coefficients.
   (begin integer m;
       p := bfloatem p; %convert to bfloat.
      % then work with powers of 2 to convert to integer.
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
      if eqcar(j,'!:dn!:) then
        <<ra := cadr j; ro := cddr j; rd := 1;
          if ro<0 then rd := 10^(-ro) else if ro>0 then ra := 10^ro;
          return mkrn(ra,rd) ./ 1>>
      else if pairp j and eqcar(car j,'!:dn!:) then
        <<ra := cadar j; ro := cddar j; rd := 1;
          if ro<0 then rd := 10^(-ro) else if ro>0 then ra := 10^ro;
          ia := caddr j; io := cdddr j; id := 1;
          if io<0 then id := 10^(-io) else if io>0 then ia := 10^io;
          ra := car(rd := cdr mkrn(ra,rd)); rd := cdr rd;
          ia := car(id := cdr mkrn(ia,id)); id := cdr id;
          go to lcm>>;
      if bfnump(j := gf2bf j) then return cdr !*rd2rn rootrnd bfloat j;
      j := gfrtrnd gf2bf j;
      ra := car(rd := cdr !*rd2rn car j); rd := cdr rd;
      ia := car(id := cdr !*rd2rn cdr j); id := cdr id;
 lcm: j := id/gcdn(id,rd)*rd; ro := j/rd; io := j/id;
      return ('!:gi!: . ((ra*ro) . (ia*io))) . j end;

symbolic procedure mkpoly rtl;
  if eqcar (rtl, 'list) then num mkpoly1 cdr rtl
   else typerr(if eqcar(rtl,'!*sq) then prepsq cadr rtl else rtl,
               "list");

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
   begin scalar pr,n,org; sprec!# := make!:ibf (3,1-!:bprec!:);
      !*xo := rl2gf 0; if null p then return !*xo;
      n := car (pr := ncoeffs bfprim p); if n>1 then pr := caddr pr;
      if pr then if cpxp p
         then !*xo := org := gfquotient(pr,rl2gf(-n))
         else !*xo := rl2gf(org :=bfdivide(pr,r2flbf(-n)));
      if null pr then return p;
      return orgshift(p,org) where pflt!#=null !*bftag end;

symbolic procedure p1rmult p; automod numr simp!* p1rmult1 p;

symbolic procedure p1rmult1 p;
   if atom p then nil
   else if atom cdr p then reval mk!*sq !*f2q caar p
   else {'times,p1rmult1 list car p,p1rmult1 cdr p};

symbolic procedure xoshift(p,nx);
   begin scalar n,org,pr,cp,orgc,a,b;
     % shift if abs p(mean) < p(origin).
      n := car (pr := ncoeffs bfprim p); if n>1 then pr := caddr pr;
      if null pr then return nil;
      org := if (cp := cpxp p) then gfquotient(pr,rl2gf(-n))
         else bfdivide(pr,r2flbf(-n));
      orgc := if cp then org else rl2gf org;
      if errorp(b := errorset!*(
            {'gfrsq,{'gfval,mkquote p,mkquote orgc}},nil))
         then return bflessp(gfrsq gf2bf orgc,bfone!*)
        else b := car b;
      a := gfrsq gfval(p,rl2gf 0);
      pmsg list("a=",a," b=",b);
      return not bflessp(a,b) end;

symbolic procedure gffinitr p;
   %do gffinit p but restore *bftag.
   (gffinit p) where !*bftag = !*bftag;

symbolic procedure invpoly p;
   %remove zero roots of p and reverse coefficients of p.
   <<p := ncoeffs for each r in p collect (car r-caar p) . cdr r;
     n2gf((car p) . reversip cdr p)>>;

symbolic procedure bdstest i;
   begin scalar y;
      if equal!:(rootrnd r2bf car i,y := rootrnd r2bf cdr i)
         then return y end;

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

symbolic procedure limadj m;
   if not m then lims!#
   else if length lims!#<2 then
      if remainder(m,2)=0 then list 1 else nil else
   ((if ratlessp(lval b,lval a) then list(b,a) else list(a,b))
    where a=lpwr(car lims!#,m),b=lpwr(cadr lims!#,m));

symbolic procedure gfstorval(pf,xn); !*xnlist := (pf . xn) . !*xnlist;

symbolic procedure gfgetmin;
   begin scalar y,nx,l; l := !*xnlist; nx := car (y := car l);
      for each x in cdr l do
         if bflessp(car x,nx) then nx := car (y := x);
      return cdr y end;

symbolic procedure calcprec(m,n,r,av,s2);
   begin integer p;
     p := if m<2 then 1+max(acc!#,n)
       else max(acc!#+1,n+1+ceillog m +
         if r=1 then 0 else
           max(if s2>2.2 or s2<1.0 then 0 else if s2>1.7 then 2 else 3,
             if m>3 and 1.5*av>n+1 then
                 fix(0.7*max(acc!#,7)*log float m+0.5) else 0));
    pmsg list("m=",m," n=",n," a=",acc!#," r=",r," av=",av,
      " s2=",s2,"->",p);
    return p end;

symbolic procedure rrpwr(r,m);
   <<while (m := m-1)>0 do rr := gftimes(rr,r); rr>>
   where rr=(r := a2gf r);

symbolic procedure cvt2(a,b); mt!: a neq 0 and mt!: b neq 0 and
   <<a := divide!:(round!:mt(a,20),round!:mt(b,20),16);
     lessp!:(a,bfone!*) and greaterp!:(a,decimal2internal(1, -1))>>;

symbolic procedure dsply nx; if !*rootmsg then
   << << write "  prec is ",2+precision 0; terpri();
   print_the_number nx; terpri(); wrs n>> where n=wrs nil>>;

symbolic procedure leadatom x; if atom x then x else leadatom car x;

symbolic procedure cvt5(a,b); equal!:(round!:mt(a,20),round!:mt(b,20));

endmodule;


module allroot; % Routines for solving real polynomials by iteration.

% Author: Stanley L. Kameny <stan_kameny@rand.org>.

% Version and Date:  Mod 1.96, 30 March 1995.

% Copyright (c) 1988,1989,1990,1991,1992,1993,1994,1995.
% Stanley L. Kameny.  All Rights Reserved.

Comment   modules bfauxil, bfdoer, bfdoer2, complxp, rootaux, realroot,
 nrstroot and multroot needed also;

exports accuroot, allroots, gfnewton, gfrootfind, sizatom;

imports !!mfefix, a2gf, accupr, allout, automod, bfabs, bfdivide,
        bfeqp, bfleqp, bflessp, bfloat, bfloatem, bfmax, bfnewton,
        bfnump, bfnzp, bfp!:, bfprim, bfrlmult, bfrndem, bfsqrt,
        bftimes, bfzp, ceillog, cexpand, ckacc, ckpzro, cpxp, csep,
        cvt5, decimal2internal, deflate1, deflate1c, deflate2, divbf,
        domainp, dsply, ep!:, errorp, errorset!*, geq, getprec, gf2bf,
        gf2flt, gfdiff, gfdiffer, gfdot, gfeqp, gfexit, gfgetmin,
        gfim, gfminus, gfnewtset, gfplus, gfquotient, gfrl, gfrlmult,
        gfrootset, gfrsq, gfrtrnd, gfshift, gfsqfrf, gfsqfrf1, gfsqrt,
        gfstorval, gftimes, gfval, gfzerop, im2gf, lastpair,
        leq, lprim, minbnd1, minprec, mkquote, ncpxp, nwterr,
        nwterrfx, orgshift, pbfprint, pconstr, pflupd, pmsg, powerchk,
        rerror, restorefl, rl2gf, rlrtno, rlval, rootrnd, round!:mt,
        rrpwr, rxgfc, rxgfrl, rxrl, seteps, setflbf, setprec, smpart,
        sqrt, timbf, trmsg1, trmsg10, trmsg11, trmsg12, trmsg13,
        trmsg2, trmsg4, trmsg6, trmsg7, trmsg8, trmsg9, unshift,
        xnshift, xnsiz, xoshift;

fluid '(!*trroot !*bftag !*rootmsg !*multiroot !*powergcd !*hardtst
 !*nosturm !2loop !*noinvert);
switch trroot,rootmsg,multiroot,nosturm;
fluid '(!*xnlist !*pfsav !*xmax !*xmax2 !*gfp pgcd!# allrl!#);
fluid '(!*pcmp prec!# acc!# sprec!# !*xn eps!# accm!# !*xobf froot!#);
fluid '(nwmax!# lgmax!# !*xo !*keepimp !1rp !*zx1 !*mb tht!# prm!#
 !*bfsh !*strm mltr!# emsg!# lims!# incmsg!$ cpxt!# sh!# pfl!# acfl!#
 pfactor!# rprec!# rr!# ss!# prx!# nrst!$ !*xd !*zp intv!# pnn!#);
global '(bfone!* bfhalf!* bfz!* cpval!# polnix!$ polrem!$ lm!#);
nwmax!# := 200; lgmax!# := 100;
!*multiroot := !*powergcd := t;

symbolic procedure gfrootfind(p,nx);
% p is expected to be in the form returned by gfform, and
% nx should be in the form (rl . im).  returns nx in form (rl . im).
   begin scalar p1,p2,px,x1,x2,x3,x0,xd,nx,n1,gfqt,xz,rsc,njp,lgerr,
     pf,xn2,t1,t2,!*pfsav,pf0,pf1,pfn,lp,xlim,fg,fg2,ip,ip0,nxl2;
      integer n,r,m,ni; lm!# := 0;
      !*xnlist := emsg!# := !*xd := nil; pmsg pbfprint p; trmsg8();
      !*pcmp := cpxp p;
      if caar p>0 then
    <<restorefl();
      rerror(roots,7,"Roots error: zero root out of sequence!")>>;
      if (n := caar lastpair p)=1 then
         <<p := cdar bfprim p;
           nx := gfminus if !*pcmp then p else rl2gf p;
           gfshift nil; trmsg11(nx,1); go to ret1>>;
      if nx and bfp!: car nx and not !*bftag then
         <<p := !*gfp; !*bftag := t>>;
      !*xo := rl2gf 0; seteps();
      lm!# := 2*nwterrfx(n,nil);
      if n<3 or !*hardtst or not xoshift(p,nx) then gfshift nil
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
      ip := bfnzp gfim nx; nxl2 := {nx};
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
         <<pf1 := pf0 := fg2 := !*pfsav := nil; ni := 1>>;
      pfn := pflupd pf;
      if pf1 then
         <<if not fg2 then <<if bflessp(pfn,pf0) then fg2 := t>> else
            <<if bflessp(pf0,pfn) or bfeqp(pf0,pf1) and bfeqp(pf0,pfn)
                then go to newt>> >>;
      if xz then xz := nil else gfstorval(pf,nx);
      pmsg mapcar(!*pfsav,function gf2flt);
lag3: trmsg2('lag,nx,px); r := r+1; ni := ni+1;
      if (xd := gfexit(pf,nx,x0,'lag))=t then go to ret0
        % m logic delays this exit to allow settling.
         else if xd and (m := m+1) > 5
         then
            <<if gfeqp(nx,xd) then go to ret0
              else if r>2 then <<!*xd := nx := xd; go to ret2>> >>
         else if njp then go to newt;
      if not xd then m := 0;
     % this logic looks for loops of length 2 or lag limit exceeded.
      if ni>5 and gfeqp(car nxl2,nx) or (lgerr := (r>lgmax!#+lm!#)) then
        <<lprim(if lgerr then {"max LAG limit",lgmax!#+lm!#,"exceeded"}
             else "lag loop of length 2 found.");
          !2loop := t; return(!*xnlist := nil)>> else
        if length(nxl2 := nconc(nxl2,{nx})) > 2 then nxl2 := cdr nxl2;
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
      !*xnlist := emsg!# := !*xd := nil; pmsg pbfprint p; trmsg8();
      if (rl := bfzp gfim nx) and ncpxp p then
         <<!*bfsh := t;
           nx := rl2gf bfnewton(p,p1,gfrl nx,intv!#,kmax);
           !*bfsh := nil; go to ret1>>;
      seteps(); !*zp := lm!# := 0;
      lm!# := nwterrfx(caar lastpair p,t);
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
 ret: nx := gfgetmin();trmsg7 nx;
ret1: nx := unshift nx;
ret2: !*xnlist := nil; dsply nx; return !*xn := nx end;

symbolic procedure accuroot(y,p,xo);  % p,xo,!*xn all bfloat
   begin scalar rprec,b,c,n,rl,x,pr0,ps,y0;
      ps := getprec(); rl := bfnump (y0 := y := gf2bf y); b := !*bftag;
      pr0 := minprec();
      !*xo := xo; !*bftag := t;
      if (n := caar lastpair p)<2 then
         <<setprec max(ps,acc!#+2);
           if prx!# then setprec max(getprec(),prx!#);
           y := gfrootfind(p,nil); go to ret>>;
      x := if rl then gfrl xnshift (y := rl2gf y) else xnshift y;
      if not(rprec := prreq(p,x,rl)) then <<setflbf b; return nil>>;
      if not (allrl!# or rl) and (bfzp gfim y or bfzp gfrl y)
         then !*xd := 1;
      if rprec<=pr0 then
         <<setprec pr0; if !*xd then go to bfp else go to ret>>;
      setprec rprec;
 bfp: y := if not rl and
            (rprec>=2*pr0 or bfzp gfim y or bfzp gfrl y)
         or !*xd then gfrootfind(p,y) else
            <<trmsg8(); gfnewton(p,y,if rl then 2 else 0)>>;
      if !*xd then <<setprec((3*getprec())/2);
        go to bfp>>;
 ret: if acfl!# then
         <<setprec(prec!# := prm!# := max(rprec,prm!#)); go to r3>>;
      prec!# := getprec();
      if rl or n<2 or not (c := smpart y) then go to r2;
      setprec(prec!# + 1);
      x := gfnewton(p,y := gf2bf !*xn,0);
      y := !*xn :=
         if c=t then
           if not !*pcmp and cvt5(gfrl y,gfrl x)
              and not cvt5(gfim y,gfim x)
             then rl2gf gfrl y else y
         else if cvt5(gfim y,gfim x) and not cvt5(gfrl y,gfrl x)
              then im2gf gfim y else y;
  r2: setprec ps;
      if not rl and
         (bfzp gfrl y and bfnzp gfrl y0
            or bfzp gfim y and bfnzp gfim y0)
        then acc!# := max(acc!#,accupr(p,if pgcd!# then p else !1rp,y));
  r3: y := if rl then rootrnd gfrl y else gfrtrnd y;
      trmsg12 y;
      setflbf b; !*xn := gf2bf !*xn;
      return y end;

symbolic procedure prreq(p,x,rl);
  % find required precision to find root at x in polynomial p.
   begin scalar p1,x1,rx;
      p1 := gfdiff pshift p;
      if rl and ncpxp p then
         <<x1 := bfabs rlval(p1,x); rx := rxrl(p1,x)>>
      else
         <<rx := if cpxp p then rxgfc(p1,x) else rxgfrl(p1,x);
           x1 := bfsqrt gfrsq gfval(p1,x)>>;
      return if bfzp x1 then nil else
        <<x := getprec(); setprec 8;
          rl := ep!: round!:mt(
              divbf(timbf(rx,decimal2internal (1, (acc!#+2))),x1),1);
          setprec x; 1 + ceiling (rl / log2of10)>> end;

symbolic procedure sizatom u;
   begin scalar c,x; c := !*complex; on complex;
     x := prepsq simp!* u;
     if not c then off complex;
     if x neq u then return x
       else rerror(roots,8,"non-numeric value") end;

symbolic procedure dsplyrtno m;
   (<< write "rootno. ",m; wrs n>> where n=wrs nil);

symbolic procedure allroots(p,p0); % p is always bfloated at this call.
Comment   With modifications for nosturm and offset iteration and root
    inversion.$
  % do the actual work of finding roots of p in appropriate environment.
   begin scalar q,n,n0,c,cc,cprq,rln,cpn,qf,ac,y,er,rl,z,mb,inc,prec,xo,
        pf,xof,qbf,sprec,b,red,sw,pfl!#,acfl,acfl!#,!*msg,prq,allrl!#,
        invp,invtd!*,pinv,!1rpinv,!1rp0,nmfg,p00,zi;
        integer req,npi,accm!#,prec!#,r15n,prm!#,k,rtn,invpb;
      prec := getprec(); polrem!$ := polnix!$ := nil; !*msg := t;
      ac := acc!#; n0 := caar lastpair p; pgcd!# := red := not p0;
      b := !*bftag; sprec := minprec(); invpb := n0/2;
      !*pcmp := cpxp p;
      if !*nosturm then req := nil else
         <<if not !*pcmp then req := if n0=1 then 1 else rlrtno p;
           if req>0 then trmsg4 req>>;
     % req = <no of real roots to determine unless nosturm is on>.
     % rtn is the number of separate root computations - 1 = max number
     % of restarts required.
      rtn := (if !*pcmp or !*nosturm then n0 else (n0+req)/2) - 1;
     % save original values of p and !1rp.
      p00 := p; !1rp0 := !1rp;
     %don't bother with inv mechanism if n0<11 unless !*noinvert="test".
      if !*noinvert="test" or n0>10 and not !*noinvert then
         <<pinv := invpoly p; !1rpinv := invpoly !1rp;
           if !*noinvert="test" or
                 not bfleqp(maxbnd1 pinv,maxbnd1 p) then  %% not perfect
              <<if !*trroot or !*rootmsg then
                   lprim "inverting initially!";
                   nmfg := t; go to inv>> >>;
      go to st0;
 tlp: if invtd!* then go to abrt else % prevents looping through tlp.
         <<if !*trroot or !*rootmsg then lprim
              "inverted polynomial tried";
           invtd!* := t>>;
 inv: k := 0;
      if not pinv then
         <<pinv := invpoly p00 ; !1rpinv := invpoly !1rp0>>;
     % toggle {p,!1rp,invp} from {p00,!1rp0,nil} to {pinv,!1rpinv,t}.
     % the first time only that invp is turned on, increase sprec.
      if (invp := not invp) then
         <<p := pinv; !1rp := !1rpinv>>
         else <<p := p00; !1rp := !1rp0>>;
     % increase precision the first time thru inv: when nmfb is off.
      if not nmfg and invpb neq 0 then
         <<prec := prec+invpb; setprec(prec-2); sprec := minprec();
           invpb := 0 ;if !*bftag then b := t>>;
strt: if prq and (k := k+1)>rtn then go to abrt; mb := nil;
      if (!*rootmsg or !*rootmsg) and not nmfg then
     (<<write "allroots restart at prec ",getprec(); terpri(); wrs ch>>
       where ch=wrs nil);
 st0: n := n0; !*gfp := qbf := p; c := cc := pf := prq := nil;
      if not !*nosturm then
         <<cprq := n-req; if not !*pcmp then cprq := cprq/2>>;
      rln := cpn := prm!# := 0;
root: qf := mb := !*mb := nmfg := nil;
      if not !*nosturm then allrl!# := cpn = cprq;
      if b then <<q := qbf; go to r0>>;
      q := if errorp(q := errorset!*({'cflotem,mkquote qbf},nil))
         then <<b := !*bftag := t; qbf>> else (qf := car q);
  r0: acc!# := ac; if not !*nosturm then !*keepimp := req-rln=0;
  r1: if !*rootmsg then dsplyrtno(1+n0-n);
      y := gfrootset(q,nil,b);
      if !2loop then <<!2loop := nil; go to tlp>>;
      r15n := 0;
      acfl := acfl!# := pfl!# := nil;
      if n=n0 then
         <<xo := !*xobf := gf2bf !*xo; p0 := qbf;
           if not b then <<xof := !*xo; pf := q>> >>;
      if not y then <<er := t; go to fl>>;
      if not (y := ckacc(qbf,if red then p0 else !1rp,gf2bf !*xn))
         then <<trmsg10 "ckacc"; go to inc0>>;
      if princreq(n,bfzp gfim y,sprec) then
        <<prq := t; sw := prec!#;
          if n>2 then sw := sw+n0; go to fl>>;
 r15: if(r15n := r15n+1)>3 then go to abrt;
      if invp or n0>2 and n0>n then
         <<if !*trroot
             then <<write "q(",n,") -> ";
                    print_the_number gf2bf y; terpri()>>;
           y := if not pf or bfp!: car !*xn
             then gfnewtset(n0,p0,!*xn,xo,b)
             else gfnewtset(n0,pf,!*xn,xof,b);
           if not y then <<trmsg10 "gfnewtset"; go to inc0>> >>;
      if acfl then
         <<pfl!# := t;
           y := ckacc(qbf,if red then p0 else !1rp,gf2bf !*xn)>>;
      if !*trroot
       then <<write "p(",n,") -> ";print_the_number gf2bf y; terpri()>>;
      if gfzerop y then <<incmsg!$ := "illegal zero root"; go to incr>>;
      if not (y := accuroot(!*xn,p0,xo)) then
            <<trmsg10 "accuroot"; go to inc0>>;
      rl := bfzp gfim y;
      if princreq(n,rl,sprec) then
        <<prq := t; sw := prec!#; if n>3 then sw := sw+2; go to fl>>;
  r2: if not !*nosturm then
         (if rl then
            <<y := gfrl y; if rln+1>req then
               <<incmsg!$ := "excess real root"; go to incr>> >>
            else if cpn+1>cprq then
               <<incmsg!$ := "excess complex root"; go to incr>>);
      z := gf2bf(if rl then gfrl !*xn else !*xn); % set by lag or nwt.
      if not rl and not !*pcmp then
       <<y := (car y) . bfabs cdr y; z := (car z) . bfabs cdr z>>;
      if c and member(y,c) then
         <<incmsg!$ := "equal roots found"; go to incr>>;
      if rl then rln := rln+1 else cpn := cpn+1;
      c := y . c; %mb := nil;
  Comment  If we are using the inverse polynomial, then we need to
    find roots at increased accuracy and precision, to allow for loss of
    accuracy in taking the inverse.  Gfrootfind always provides that
    additional accuracy in the unrounded root z (which is used for
    deflation), so it is a simple matter to invert the root before
    rounding.  When the rounding is done, using gfrtrnd, the binary
    bigfloat result is the output of gfrtrnd, and the decimal equivalent
is
    returned as the value of the global variable cpval!#. $
      if invp then
         <<zi := gf2bf z;
              if red then zi := if rl then bfquotient(bfone!*,zi)
                 else gfquotient(bfone!* . bfz!*,zi)
              else
                gfrtrnd gfquotient(bfone!* . bfz!*,
                  if rl then (zi . bfz!*) else zi)>>;
      if not (rl or red or !*pcmp) then
         cpval!# := (car cpval!#) . (abs cadr cpval!#) . cddr cpval!#;
      cc := ((if red then if invp then zi else z else mkdn cpval!#)
                  . acc!#) . cc;
     % the output list cc will be either z or :dn: objects, so
     % output functions will have to be clever!
     % c is rounded roots list used in testing for equal roots.
      if !*trroot then terpri();
     % firstroot computes first root found only. It could be wrong.
      if froot!# then goto ret;
    % new logic does all deflation in bfloat for greater accuracy.
      z := gf2bf z; q := bfloatem q;
      if (rl or !*pcmp) and (n := n-1)>0 and
         (q := cdr(if rl then deflate1(q,z) else deflate1c(q,z)))
         or (n := n-2)>0 and (q := deflate2(q,z)) then
            <<qbf := bfrndem q; go to root>>;
 ret: setprec max(prec,(acc!# := ac)+2);
      setflbf b; return cexpand cc;
incr: lprim incmsg!$; polnix!$ := q;
      if mb then go to tlp
         else if !*zx1 then
            <<lprim "offset iteration attempted";
              !*mb := mb := t; go to r1>>;
inc0: if (npi := npi+1)<=3 then go to inc1;
abrt: lprim list("root finding aborted. Deflate degree = ",n);
      lprim list("poly = ",q); terpri();
      if n0>n then polrem!$ := q; go to ret;
inc1: inc := max(n0,sprec/2);
      setprec(sprec := max(sprec+inc,2+2*acc!#)); trmsg9 sprec;
      if b then go to strt;
  fl: p := p0; xo := !*xo := gf2bf xo;
      b := !*bftag := t; !1rp := bfloatem !1rp;
      if er then <<er := nil; q := qbf; go to r1>>;
      acfl := t;
      if sw then
     % precision has increased: backup point depends on n.
         <<setprec (sprec := sw); sw := nil; q := p;
           if n=n0 then <<y := gf2bf y; go to r15>> >>;
      go to strt end;

symbolic procedure princreq(n,rl,sprec);
   (n>2 or (rl or !*pcmp) and n>1) and min(prec!#,2*(accm!#+1))>sprec;

endmodule;


module rootaux; % Support for allroot, previously in realroot.

% Author: Stanley L. Kameny <stan_kameny@rand.org>.

% Version and Date:  Mod 1.96, 30 March 1995.

% Copyright (c) 1988,1989,1990,1991,1992,1993,1994,1995.
% Stanley L. Kameny.  All Rights Reserved.

global '(!!nfpd max!-acc!-incr lm!#);

max!-acc!-incr := 8;

fluid '(!*xn !1rp acc!# ss!# rootacc!#!# rprec!# cpxt!# pfactor!# prx!#
  nrst!$ intv!# rlrt!# lims!# pnn!# rr!# !*strm !*xnlist sh!#
  !*nosturm);

fluid '(!*compxroots !*bftag !*roundbf !*msg);

symbolic procedure accupr1(y,p);
 % if acc!# is insufficient to separate this root from roots of
 % other factors of !1rp, increase accuracy.
   <<!*xn := y;
     while (acr := accupr(p,bfloatem !1rp,!*xn))>acc!# do
          <<acc!# := acr; y := accuroot(y,p,rl2gf 0)>>;
     y . (acc!#+ss!#)>> where acr=acc!#;

symbolic procedure uniroots(p,rrts);
   <<!!mfefix();
     if eqcar(aeval p,'list) then
        (algebraic multroot(pr,p)
         where pr=if rootacc!#!# then rootacc!#!# else precision 0,
               !*compxroots=if rrts=0 then nil else t)
     else if rrts=0 then
        (<<rprec!# := max(!!nfpd,rprec!# or 7);
           uniroot0(p,0)>>
         where !*bftag=t,!*roundbf=t,rprec!#=rprec!#)
     else uniroot0(p,rrts)>> where !*msg=nil;

symbolic procedure uniroot0(p,rrts);
   begin
    scalar c,lim,n,p1,pp,q,r,r1,rr,x,cp,m,cpxt!#,pfactor!#,acc,s,
       prx!#,m1,nrst!$,intv!#,rlrt!#,rrc;
    integer ss!#;
      p := cdr(c := ckpzro p);
      if (c := car c) then c := {({(caaar c) . 6}. cdar c)};
     % lims!# code is applicable only when realroots is called.
      if lims!# then if not cdr lims!# or
         <<r := car lims!#; r1 := cadr lims!#;
           r neq 'minfty and
              (if xclp r then cadr r>=0 else car r>0)
           or r1 neq 'infty and
              (if xclp r1 then cadr r1<=0 else car r1<0)>>
            then c := nil;
      if atom p then
        <<r := if c then c else {(nil . 1)}; go to ret>>;
      if cpxp p then cpxt!# := t;
      m := powerchk p; % top level powergcd factoring.
      p := if !*nosturm and rrts neq 0 then {(!1rp := p) . 1}
         else gfsqfrf p;
      automod !1rp; n := pnn!#;
      p1 := !1rp; % save original one-factor polynomial.
      if length p>1 then pfactor!# := prx!# := n;
      if m then
         <<p := if !*nosturm and rrts neq 0 then {(!1rp := cdr m) . 1}
              else gfsqfrf cdr m;
           m := car m; ss!# := s := ceillog m>>;
      lim := acc!#+max!-acc!-incr;
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
 col: rrc := for each y in rr collect car y;
     % the following test should never succeed!
      for each y in rrc do if member(y,r1) then rooterr y;
      r1 := append(r1,rrc);
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
   if r=0 then rtsreal(pp,s) else allroots(pp,s);

symbolic procedure rooterr y;
   lprim list(y,"is false repeated root.  Send input to S. L. Kameny")
    where !*msg=t;

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

symbolic procedure bfnewton (p,p1,nx,ri,kmax);
   begin scalar ri,px,pf,pf0,x0,xe,k,xk,xr,lp; integer m;
      !*xnlist := nil; lm!# := 0;
      lm!# := nwterrfx(caar lastpair p,nil);
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
ret3: nx := gfgetmin(); trmsg7(nx);goto ret;
ret2: if nx then go to ret;
ret1: trmsg10 'nwt;
 ret: !*xnlist := nil; return nx end;

endmodule;


end;
