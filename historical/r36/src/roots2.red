module roots2; % Header module for roots2 package.

% Author: Stanley L. Kameny <stan_kameny@rand.org>.

% Version and Date:  Mod 1.96, 30 March 1995.

% Copyright (c) 1988,1989,1990,1991,1992,1993,1994,1995.
% Stanley L. Kameny.  All Rights Reserved.

Comment
  Revisions:
  30 March 95  Mod 1.96 adds to multroot the capability of solving
                polynomial trees which are determinate but whose
                structure may lack a stairstep pattern of variables,
                or may contain more polynomials than variables.
                Polynomials can now have denominators, which are
                ignored since only the numerators are used.
                  Spurious small real or imaginary parts of complex
                roots, which can arise due to numeric substitution, are
                now detected and eliminated.  However, vital small real
                or imaginary parts are retained (as in the roots
                program.)
                  Error handling is improved.  Each error now returns
                an error message and then multroot(pr,pl) where pr is
                the precision of answers and pl is the equivalent
                polynomial tree whose processing failed. ;

create!-package ('(roots2 realroot nrstroot multroot),
                 '(contrib roots));

symbolic procedure realroots u; nil; % to fool loader.

% Other packages needed.
load_package roots;

endmodule;


module realroot; % Routines for finding real roots of polynomials,
                 % using Sturm series, together with iteration.

% Author: Stanley L. Kameny <stan_kameny@rand.org>.

% Version and Date:  Mod 1.96, 30 March 1995.

% Copyright (c) 1988,1989,1990,1991,1992,1993,1994,1995.
% Stanley L. Kameny.  All Rights Reserved.

Comment   modules bfauxil, bfdoer, bfdoer2, complxp, allroot and rootaux
 needed also;

exports accupr1, bfnewton, isolatep, schinf, schplus, sgn1, sturm,
        sturm0, uniroots;

imports !!mfefix, abs!:, accupr, accuroot, allroots, automod, bdstest,
        bfabs, bfdivide, bfeqp, bfleqp, bfloat, bfloatem, bfmax,
        bfminus, bfminusp, bfplus, bfrlmult, bfsgn, bfsqrt, bfzp,
        ceillog, ckpzro, cpxp, csep, difbf, divbf,
        domainp, dsply, eqcar, equal!:, errach, geq, getprec, gfdiff,
        gffinitr, gfgetmin, gfrl, gfrootfind, gfsqfrf, gfstorval,
        greaterp!:, lastpair, leq, lprim, minbnd1, minprec, mk!*sq,
        multroot,
        neq, nwterr, nwterrfx, outecho, pconstr, plubf, powerchk,
        r2bf, r2flbf, ratdif, ratleqp, ratlessp, ratmax, ratmean,
        ratmin, ratminus, ratplus, realrat, rerror, rl2gf, rlval,
        round!:mt, sch, schnok, setprec, sgn, stuffr, sturm1, timbf,
        trmsg1, trmsg10, trmsg2, trmsg3, trmsg4, trmsg6, trmsg7,
        trmsg8, xclp;


global '(!!nfpd !!flim bfhalf!* max!-acc!-incr bfone!* rlval!#);

fluid '(!*gfp !*xnlist !*intp tht!# !*strm lims!# mltr!# pfactor!#
 prec!# !*rvar acc!# !*xo !1rp accm!# !*xn intv!# sh!# rprec!# rlrt!#
 prm!# pfl!# acfl!# pgcd!#);

fluid '(!*trroot !*bftag !*compxroots !*msg);

flag('(positive negative infinity),'reserved);
global '(limlst!# lm!#);
limlst!# := '(positive negative infinity (minus infinity));

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
      n := (va := sch l+if lr then 1 else 0)-(vb := sch u);
      trmsg4(n);
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
   <<if cpxp (p := gffinitr p) then
        <<p := car csep p; if not atom p then p := bfloatem p>>;
     if not atom p then sturm1(!*gfp := p)>>;

put('sturm,'psopfn,'sturm0);

symbolic procedure sturm0 p;
   <<p := sturm ckprec car p; restorefl();
     'list . for each a in p collect if atom a then a else 'list . a>>;

symbolic procedure sgn1(p,r); if atom p then sgn p else
 % Evaluate sign of one sturm polynomial for rational r=(u . d)
   begin scalar m,c,u,d; u := car r; d := cdr r;
      c := 0; m := 1; p := cdr p;
      repeat <<c := m*car p + u*c; m := m*d>> until null(p := cdr p);
      return sgn c end;

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
          equal!:(bfone!*,round!:mt(divbf(bfloat nx,bfloat x0),13))>>
            then go to lag;
 tht: nx := tighten(i,p,pf,sh); m := 0;
      if !*xnlist then
         <<pf0 := nil;
           movebds(i,xr := ratmean(car i,cdr i),sh); go to lag0>>;
 lg4: trmsg1('lag,nx);
 ret: !*xnlist := nil; if not nx then trmsg10 'lag; go to ret2;
newt: nx := bfnewton(p,p1,gfgetmin(),i,4);
ret2: !*xn := rl2gf nx; return nx end;

global '(tentothetenth!*!*);

tentothetenth!*!* := normbf i2bf!: 10000000000;

symbolic procedure bndtst x;
  greaterp!: (abs!: x, tentothetenth!*!*);

symbolic procedure movebds(i,xr,sh);
   if sgn1(!*intp,xr)=sh then rplacd(i,xr) else rplaca(i,xr);

symbolic procedure tighten(i,p,pf,sh);
   begin scalar j,x0,nx,px,sn,x;
      nx := car i;
tht0: j := 4;
tht1: x0 := nx; nx := ratmean(car i,cdr i);
      if (sn := sgn1(!*intp,nx))=0 then
         <<x := r2flbf nx;trmsg1 ('tht,x); go to ret>>;
      if 0=car ratdif(nx,x0) then
         <<x := r2flbf nx;trmsg3 ('tht,x); go to ret>>;
      if sn=sh then rplacd(i,nx) else rplaca(i,nx);
      if (sn := bdstest i) then <<x := r2flbf sn; go to ret>>;
      if (j := j-1)>0 then go to tht1;
      if bndtst (px := rlval(p,x := r2flbf nx)) then
         <<j := 4; go to tht1>>;
      gfstorval(bfabs px,x);
      trmsg2('tht,x,px);
      if bfzp px then go to ret
         else if pf and bfleqp(pf,bfabs px) then go to tht0
         else return x;
 ret: !*xnlist := nil; return x end;

symbolic procedure rtsreal(p,s);
 % Finds real roots of univariate square-free real polynomial p, using
 % sturm series, isolater and rootfind.
   begin scalar acr,acs,n,q,r,x,y,!*strm,pr,apr,!*bftag,pfl!#,
        acfl!#,xout,x1;
      integer accn,accn1,accm!#,prec!#,prm!#; pr := getprec();
      !*bftag := rlrt!# := t; pgcd!# := not s;
      r := isolatep p; % r is a list of rational number pairs.
      if null r then go to ret;
      if (n := caar lastpair p)>1 then go to gr1;
      y := rootrnd gfrl gfrootfind(p,nil);
      if pfactor!# then
        <<y := accupr1(y,p); y := (rootrnd car y) . cdr y>>;
     % note that rlval!# was set by the last operation of rootrnd.
      xout := {if s then (mkdn rlval!#) . acc!#
                 else if pfactor!# then y
                   else y . acc!# % this can't happen
                };
      if !*trroot then terpri(); go to ret;
 gr1: !*xo := rl2gf 0;
      q := r; acs := acc!#;
 lag: % increase accuracy for this root and the next root if current
      % accuracy is not sufficient for the interroot interval.
      if cdr q then  % no test if this is the last real root.
        <<setprec acs;
          while schnok q do setprec (getprec()+1);
          accn1 := getprec()>>;
      acc!# := max(acs,accn,accn1);
      accn := if accn1>acs then accn1 else 0;
      setprec max(rprec!#,acc!#+2);
      y := rootfind(p,intv!# := car q); apr := t;
      if null y then rerror(roots,8,"Realroots abort");
 acc: y := accuroot(gfrl !*xn,p,!*xo);
     % if acc!# is insufficient for this root, for any reason,
     % increase accuracy and tighten.
      if apr then
        <<if (acr := accupr(p,!1rp,!*xn))>acc!# then acc!# := acr
            else if acr<=acc!# then <<acc!# := acr; apr := nil>>;
          go to acc>>;
      xout := ((x1 := if s then mkdn rlval!# else y) . acc!#) . xout;
     % x is root list. Check for equal roots should fail!
      if x and x1=car x then rooterr x1;
      x := x1 . x;
      dsply y;
      acc!# := acs;
      if (q := cdr q) then <<accn1 := 0; go to lag>>;
 ret: setprec pr; return reverse xout end;

symbolic procedure lval x; if xclp x then cdr x else x;

symbolic procedure lpwr(l,m);
   if eqcar(l,'list) then 'list . lpwr(cdr l,m)
   else if atom l then l else ((car l)**m) . ((cdr l)**m);

symbolic procedure schnok r;
  %true if precision is inadequate to separate two adjacent real roots.
   (l neq h and (sch l neq sch r2flbf2r l or sch h neq sch r2flbf2r h))
   where l=caar r,h=cdar r;

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
 if errorp(y := errorset!*({'a2rat,mkquote y},nil))
    then rerror(roots,5,"Real root function limits must be real")
 else car y;

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

symbolic procedure a2rat x;
   if numberp x then x . 1
   else if atom x then limerr()
   else if eqcar(x,'quotient) then
     ((if numberp n then n
       else if eqcar(n,'minus) then - cadr n
       else rerror(roots,10,"illegal limit")) where n=cadr x) . caddr x
   else if car x eq '!:rn!: then cdr x
   else
    ((if car x memq domainlist!* and y then cdr(apply1(y,x))
       else limerr())
    where y=get(car x,'!:rn!:));

symbolic procedure rlrootno a;
   <<mltr!# := t; lims!# := limchk cdr a; a := ckprec car a;
     a := rlrtno2 if lims!#=t then 0 else a;
     restorefl(); mltr!# := nil; a>>;

put('rlrootno,'psopfn,'rlrootno);

symbolic procedure realroots a;
   <<lims!# := limchk cdr a;
     uniroots(if lims!#=t then 0 else car a,0)>>;

put('realroots,'psopfn,'realroots);

symbolic procedure isolater p;
   <<mltr!# := t; lims!# := limchk cdr p; p := ckprec car p;
     p := isolatep if lims!#=t then 0 else p;
     restorefl(); mltr!# := nil; outril p>>;

put('isolater,'psopfn,'isolater);

symbolic procedure mkratl l; for each a in l collect
   if member(a,limlst!#) then a else
   if eqcar(a,'list) then
      if member(a := cadr a,limlst!#) then a else mkxcl a
      else a;

symbolic procedure exclude x; {'list, x};

symbolic operator exclude;

endmodule;


module nrstroot; % Routines for finding the root of a polynomial which
 % is nearest to a given value (providing the root is sufficiently
 % close.)

% Author: Stanley L. Kameny <stan_kameny@rand.org>.

% Version and Date:  Mod 1.96, 30 March 1995.

% Copyright (c) 1988,1989,1990,1991,1992,1993,1994,1995.
% Stanley L. Kameny.  All Rights Reserved.

Comment   modules bfdoer, bfdoer2, complxp, allroot, and rootaux of
roots.red needed also;

global '(bfz!* cpval!#);

fluid '(!*msg !*multiroot cpxt!# pfactor!# nrst!$ intv!# pfl!# !*bftag
 ss!# accm!# prm!# prec!# !*mb !*gfp !*keepimp !*xo nrst!$ pnn!# pfx!#
 !1rp !*complex !*resimp pgcd!# !*xn !*xobf prec!# !*hardtst acc!# rr!#
 prx!#);

symbolic procedure nearestroot args; % args = (p,rr)
 % finds root nearest to rr, unless accuroot abort occurs.  rr may be
 % real or complex. p can have zero root or multiple roots.  Most useful
 % for refining the value of a known root, by setting rootacc before
 % calling nearestroot.
  nrstroot(p,rr,nil) where p=car args,rr=cadr args;

put('nearestroot,'psopfn,'nearestroot);

symbolic procedure nrstroot(p,rr,trib);
   begin
      scalar x,c,d,dx,xm,r,cp,n,m,s,p1,prx!#,acc,pp,m1,!*msg,
        !*multiroot,cpxt!#,pfactor!#,nrst!$,intv!#,pfl!#,acfl!#,!*bftag;
      integer ss!#,accm!#,prm!#,prec!#;
      !!mfefix();
      p := cdr(c := ckpzro p); c := car c; !*mb := nil;
      if atom p then <<if c then c := 0; go to ret>>;
      if null rr then rr := 0;
      if trib then
        <<acc!# := max(acc!#,rr2acc rr);
          !*gfp := p := automod p; !*bftag := t;
          if atom trib then
        % test branch that calls gfnewton only.
           <<!*keepimp := numberp trib; !*xo := rl2gf 0;
             c := gfnewton(p,a2gf rr,4); go to ret>>
           else % test branch that goes through gfrootfind only
             <<!*keepimp := numberp car trib;
               c := gfrootfind(p,a2gf rr); go to ret>> >>;
      r := a2gf rr; acc := acc!# := max(acc!#,rr2acc rr);
      if c then if gfzerop r then <<c := 0; go to ret>> else
         <<d := bfloat gfrsq r; xm := bfz!*>>;
      m := powerchk p; nrst!$ := t;
      p := gfsqfrf p; automod !1rp; n := pnn!#; p1 := bfloatem !1rp;
      if length p>1 then pfactor!# := prx!# := n;
      if cpxp p then cpxt!# := t;
      if m then
         <<p := gfsqfrf cdr m; m := car m;
           ss!# := s := ceillog m>>;
loop: pp := automod car(x := car p); cp := nil;
      if cpxp pp then
         <<pp := car(cp := csep pp); cp := cdr cp;
           if atom pp then go to cpr else pfactor!# := prx!# := n>>;
 mod: pp := automod pp; r := gf2bf r;
     % powerchk may succeed after sqfrf or csep succeeds.
      if (m1 := powerchk pp) then <<pp := cdr m1; m1 := car m1>>;
      if not m and not m1 then
         <<x := nrstrt0(pp,r,p1); go to col>>;
      x := if m1 then
         nrpass2(m1,nrpass1(pp,r,if m then m1*m else m1),r,p1,acc)
            else nrpass1(pp,r,m);
      if m then x := nrpass2(m,x,r,p1,acc);
     % however we get to the next line, cpval!# has been set.
 col: x := cdr x;
      dx := gfrsq gfdiffer(if bfnump x then (x := x . bfz!*) else x,
         gf2bf r);
      if not d or d and bfleqp(dx,d) then
        <<d := dx; xm := mkdn cpval!#>>;
 cpr: if cp then <<pp := cp; cp := nil; go to mod>>;
      if (p := cdr p) and not domainp caar p then go to loop;
      c := xm;
 ret: return allout if c then {(c . acc!#)} else nil end;

symbolic procedure rr2acc rr;
  (begin scalar !*msg,c;
    c := !*complex; on complex;
    for each n in rr2nl rr do form1(n,nil,'algebraic);
    (simp!* rr) where !*resimp=t;
    if not c then off complex;
    pr := precision pr; return pr end)
    where pr=precision 6;

symbolic procedure rr2nl rr; rr2nl1(rr,nil);

symbolic procedure rr2nl1(rr,nl);
   if numberp rr then {'!:int!:,rr} . nl
     else if atom rr then nl
     else if car rr eq '!:dn!: then {'!:int!:,cadr rr} . nl
     else rr2nl1(car rr,rr2nl1(cdr rr,nl));

symbolic procedure nrstrt0(q,r,p1);
   begin scalar rr,x,b,pr,ps,p2,qf; pmsg pbfprint q; b := !*bftag;
      ps := getprec(); pr := minprec(); pgcd!# := not p1;
      p2 := gfzerop(rr := a2gf r); !*gfp := qf := q;
      if b then go to r2;
      if errorp(q := errorset!*({'cflotem,mkquote qf},nil))
        or errorp(r := errorset!*({'gf2fl,mkquote rr},nil))
         then go to r1 else <<q := car q; r := car r>>;
      if (x := gfrootset(q,r,b)) then
         <<q := qf; !*xn := gf2bf !*xn;
           !*xobf := !*xo := gf2bf !*xo; go to r3>>;
  r1: q := qf; b := !*bftag := t; r := gf2bf rr;
  r2: x := gfrootfind(q,r); !*xobf := !*xo := gf2bf !*xo;
  r3: if not !*hardtst then x := ckacc(q,if p1 then p1 else q,!*xn);
      x := accuroot(
      if bfzp gfim r then (car !*xn) . bfabs cdr !*xn else !*xn,q,!*xo);
      if prec!#<pr+2 then
         <<setflbf b; setprec ps; return acc!# . x>>;
      setprec(pr := prec!#);
      if not !*bftag then b := !*bftag := t;
      if p2 then go to r2 else <<p2 := t; go to r1>> end;

symbolic procedure nrpass1(pp,rr,m);
   nrstrt0(pp,rrpwr(rr,m),nil) where ss!#=ceillog m;

symbolic procedure nrpass2(m,x,rr,p1,acc);
   begin scalar s; s := ceillog m;
      return (nrstrt0(pconstr(m,cdr x),rr,p1)
         where acc!#=max(acc,car x-s),rr!#=1,
            ss!#=0,pfactor!#=(pfactor!# or car x-s>acc)) end;

endmodule;


module multroot;  % Code for solving polynomial sets solvable by
                  % backsubstitution.

% Author: Stanley L. Kameny <stan_kameny@rand.org>.

% Version and Date:  Mod 1.96, 30 March 1995.

% Copyright (c) 1994,1995.  Stanley L. Kameny.  All Rights Reserved.

Comment  modules allroot, bfauxil, bfdoer, bfdoer2, complxp, rootaux and
         realroot needed also;


fluid '(rterr!! mrerr!! rootacc!#!#);

switch fullprecision,compxroots;

put ('multroot,'psopfn,'multroot1);

symbolic procedure multroot1 u;
  if length u neq 2 then rederr
  "2 args required: pr=desired precision, pl=polynomial list"
  else multroot0(car u,cadr u);

symbolic procedure multroot0(pr,pl);
  begin scalar v,ans,pr1,c,r,rterr!!,ra;
    !*protfg := t; pr1 := precision 0; r := !*rounded; c := !*complex;
    ra := rootacc!#!#;
  v := errorset!*({'multroot2,{'multroot01,mkquote pr,mkquote pl}},nil);
    !*protfg := nil; rootacc!#!# := ra;
    return if errorp v then
      <<precision pr1;
        (<<if !*rounded then if not r then off rounded else nil
              else if r then on rounded;
           if !*complex then if not c then off complex else nil
              else if c then on complex>> where !*msg=nil);
           (if rterr!! then lprim
"for some root value(s), a variable depends on an arbitrary variable"
              else if mrerr!! then lprim mrerr!!) where !*msg=t;
        mk!*sq mksq({'multroot,pr,reval pl},1)>>
      else (<<v := car v; on rounded,complex; ans := aeval v;
              if !*rounded then if not r then off rounded else nil
                 else if r then on rounded;
              if !*complex then if not c then off complex else nil
                 else if c then on complex;
              ans>> where !*msg=nil) end;

share npoly!*,pr!*,pl!*;

algebraic procedure multroot01(pr,pl);
Comment
pl is a list of n polynomials in a tree containing branches each one of
which contains one univariate polynomial, one bivariate polynomial, ...
one n-variable polynomial in which each successive polynomial adds one
additional variable.  These branches may branch, so that one variable
gives rise to several branches.  These polynomials are the standard
Groebner output.  All polynomials are real with integer coefficients.
pr is the desired minimum precision of the solution set for real roots.
This program will go through each branch by solving p_1 for the first
variable, then will test each succeeding polynomial for the precision of
each additional variable, returning to the initial solution at higher
precision when necessary, until the last polynomial's solution has been
obtained at precision >= pr.  The solutions are collected in the
variable solns!*.  They are then combined into the final output form by
the function combinesolns();
   begin scalar n,links,path,paths,fl,fl1,var,rts,solns; integer maxv;
     npoly!* := n := length pl - 1;
    % 0..n will be the indices of arrays.
     clear vll!#,vll2!#,varbl!#,poln!#,rtlst!#,derv!#,pra!#,fxer!#;
     array vll!#(n),vll2!#(n);
     pl!* := pl;
     pl := pl!* := reval cleardenr pl!*;
    % vll!# will be an array of {list of variables}
     for j := 0:n do vll!# j := getvars part(pl,j+1);
    % vll!# will be a useful tool for finding and tracing trees.
    % Trees might possibly be totally independent if there are more
    % than one of the vll!#(j) of length 1, or else trees might branch
    % if there is more than one way of extending the variable lists from
    % a given node.  The tree following algorithm must allow for any of
    % these.  It will be easiest to have a tree algorithm which simply
    % enumerates branches as a list of the j values which span the total
    % branch from root to tip.
     links := findlinks n;
     paths := links2paths links;
    % if paths = nil then multroot fails.
     lisp(mrerr!! := nil);
     if not paths then lisp(mrerr!! :=
       "multroot fails because no univariate polynomial was given.");
     lisp(if mrerr!! then rederr "1");
     fl := nil;
     for j := 0:n do
       <<fl1 := nil;
         for each path in paths do if member(j,path) then fl1 := t;
         if not fl1 then fl := t >>;
     if fl = t then lisp(mrerr!! :=
       "multroot failure: at least one polynomial has no single base.");
     lisp(if mrerr!! then rederr "2");
    % In multroot2, we solve for real roots under the condition that
    % the precision of each root >= pr;
     array varbl!#(n),poln!#(n),rtlst!#(n),derv!#(n),pra!#(n),fxer!#(n);
    % these arrays are used in solvepath, but we don't want them to be
    % redefined for different paths.  Maximum index will be <=n, but we
    % will be careful not to go out of bounds.
     vlist!* := rlist!* := solns!* := {};
     pr!* := pr;
     return paths end;

symbolic operator subsetp,algunion,cleardenr;

symbolic procedure cleardenr pl;
   begin scalar plo;
     for each pol in cdr pl do
        plo := (if eqcar(pol,'quotient) then cadr pol else pol) . plo;
     return 'list . reversip plo end;

symbolic procedure algunion(a,b); 'list . union(cdr a,cdr b);

algebraic procedure findlinks n;
   begin scalar links,fl,fl1,var;
     links := {};
    % we have in vll!# an array of lists of variables.  If they can form
    % a strict hierarchy, we have no problem in solving the polynomials.
    % But if they don't, we have to form an artificial hierarchy by
    % augmenting the lists.
     for m := 1:n do
       if m=1 then for j := 0:n do vll2!# j :=
         if length(fl := vll!# j)=1 then
           if not var then var := fl else vll!# j := append(fl,var)
           else fl
         else for k := 1:2 do
           for j := 0:n do
             if length(fl := vll!# j)=m then vll2!# j :=
               if length var<m then if subsetp(var,fl) then var := fl
                     else fl
                 else if fl=var then fl else vll!# j := algunion(fl,var)
               else fl;
     repeat <<fl := nil;
      for j := 0:n do
       <<fl1 := nil;
         for k := 0:n do
           if j neq k
            and length vll2!# j =1 and subset1(vll2!# j,vll2!# k) then
            <<links := append(links,{{j,k}}); fl1 := t>>;
         if fl1=t then
         <<fl := t;
           for k := 0:n do
           <<var := first vll2!# j;
            if j neq k then vll2!# k := delete(var,vll2!# k)>> >> >> >>
      until not fl ;
    return links end;

algebraic procedure multroot2 paths;
  begin scalar path,lfp,fl,soln1,soln2,pr0,nlst;
 lp: path := first paths; paths := rest paths;
     lfp := last path; fl := nil;
     for each path2 in paths do if last path2 = lfp then fl := t;
     if fl then <<lisp(mrerr!! :=
         "multroot failure: This error should not occur!");
       rederr "3">>;
    % this is the place where it is reasonable to eliminate spurious
    % real or imaginary parts of complex roots.
     soln1 := solvepath path;
     if lisp !*compxroots and (nlst := spurival soln1) neq {} then
       <<pr0 := precision 0; pr!* := pr!*+5;
         soln2 := solvepath path; precision pr0; pr!* := pr!*-5;
         soln1 := spurifix(nlst,soln1,soln2)>>;
     if not member(v0!*,vlist!*) then
       % here we save the initial roots or realroots answers so they
       % won't be computed redundantly.
       <<vlist!* := append(vlist!*,{v0!*});
         rlist!* := append(rlist!*,{r0!*})>>;
     if soln1={} then <<fl := t; go to cl>>;
     solns!* := append(solns!*,{soln1});
     if paths neq {} then go to lp;
 cl: clear vll!#,vll2!#,varbl!#,poln!#,rtlst!#,derv!#,pra!#,fxer!#;
     return if fl then {} else combinesolns() end;

algebraic procedure combinesolns();
Comment
 We have all of the separate solutions in solns!* and a list of the
independent variables in vlist!* and the root values of the base
variables in the list rlist!*.  So we can use this information to
combine the separate solutions into an outer product of all solutions.
In doing this, we will first combine all terms with the same base
variable, then combine all of those outer products into one grand
product.  Finally, we sort the variables into standard order and sort
the values into order by the real part of the first variable.$
  begin scalar vlist,rlist,prod,solns,var,rts,grandprod;
     vlist := vlist!*; rlist := rlist!*; grandprod := {};
lp2: var := first vlist; vlist := rest vlist;
     rts := first rlist; rlist := rest rlist;
     prod := {}; solns := solns!*;
     if rts neq {} and solns neq {{}} then
       for each soln1 in solns do
         if isvar(first soln1,var)
           then prod := if prod = {} then soln1
             else outcombine1(rts,prod,soln1);
     grandprod := if grandprod = {} then prod
        else outcombine2(grandprod,prod);
     if vlist neq {} then go to lp2;
     grandsoln!* := grandprod;
     sortvars();
     screensolns1();
     return sortvals();
     end;

symbolic operator screensolns1;

symbolic procedure screensolns1();
   begin scalar inlist,outlist,termout,vr,vr1,vl,vl1,fl;
     inlist := reversip cdr algebraic varsortsolns!*;
     for each rts in inlist do
       <<vr := vr1 := fl := termout := nil;
         for each term in cdr rts do if not fl then
           <<vr1 := cadr term; vl1 := caddr term;
             if not vr or vr neq vr1 then
                 <<vr := vr1; vl := vl1; termout := term . termout>>
               else if vl1 neq vl then fl := t>>;
        if not fl then outlist := ('list.reversip termout).outlist>>;
      return algebraic varsortsolns!* := ('list . outlist) end;

algebraic procedure solvepath path;
   begin scalar
    n,vl,vlll,m,s,rts0,fl,fl1,b,tst,f,ff,pr1,prf,strt,dfx,rtl,rt1,!*msg,
    zz,r,c;
     n := length path;
     if (r := lisp !*rounded) then off rounded;
     if (c := lisp !*complex) then off complex;
    % now we assemble the polynomial tree which represents this path.
     vl := for j := 1:n collect part(pl!*,part(path,j)+1);
    % we now have ordered the polynomials in order of the number of
    % variables.
     vlll := for j := 1:n collect vll!# part(path,j);
    % and have now ordered the variable list in increasing number of
    % variables, so that vlll correctly lists the variables in the
    % reordered list vl;
    % Now we solve for real roots under the condition that the precision
    % of each root >= pr!*;
     n := n-1; % this is done because arrays will have indices 0..n.
     pra!#(0) := pr!*+10; on rounded;
     for j := 1:n do pra!#(j) := pr!*;
    % a starting point: this may have to be increased if necessary.
     v0!* := varbl!#(0) := first first vlll;  strt := t;
str: precision pra!#(0);
     rts0 := if strt and member(v0!*,vlist!*)
       then (r0!* := part(rlist!*,membno(v0!*,vlist!*)))
       else if lisp !*compxroots then roots first vl
         else realroots first vl;
     r0!* := rts0;
     rtlst!#(0) := for each rt in rts0 collect {rt};
     m := 0; strt := nil;
nxt: fl := fl1 := b := 0;
     if (m := m+1) > n then <<m := m-1; go to ret>>;
     poln!#(m) := part(vl,m+1);
     rtl := {};
     for each rt in rtlst!#(m-1) do
       <<zz := sub(rt,poln!#(m));
        % zz is a polynomial, or possibly a constant.  If it is 0
        % then whatever variables it might represent are arbitrary, but
        % if is a nonzero constant, the path stops here.
         rt1 := if mainvar zz=0 then if zz=0 then {rt} else {}
          else combinerts(rt,
           <<lisp(rterr!! := t);
             zz := if lisp !*compxroots then roots zz else realroots zz;
             lisp(rterr!! := nil); zz>>);
         if rt1 neq {} then rtl := append(rtl,rt1)>>;
     rtlst!#(m) := rtl;
     s := length rtlst!#(m);
     varbl!#(m) := elim(part(vlll,m),part(vlll,m+1));
     derv!#(m) :=
       {-(df(poln!#(m),varbl!#(0))+
         if m<2 then 0 else for j := 1:(m-1) sum
           (df(poln!#(m),varbl!#(j))*first derv!#(j)/second derv!#(j)))
        ,df(poln!#(m),varbl!#(m))};
lp1: if (b := b+1) > s then
       <<prf := nil;
         if fl > 0 then
          <<fxer!#(m) := pfx(pr!*,fl); fl := 0;
            dfx := fxer!#(m) - fxer!#(m-1);
            for j := 0:m-1 do
             <<pr1 := pra!#(j) + dfx;
               if pr1>pra!#(j) then
                 <<prf := t; pra!#(j) := pr1>> >> >>;
         if prf then go to str else go to nxt>>
       else
         <<if (tst :=
             abs(10.0^(-pra!#(0))*cabs
                testsub(part(rtlst!#(m),b),derv!#(m),m)) )>10.0^-pr!*
             then fl1 := tst;
           if fl1 > fl then fl := fl1;
           go to lp1>>;
ret: if r then on rounded; if c then on complex;
     if not lisp !*fullprecision then go to rt2;
     precision pra!#(0); return
       if m=0 then rtlst!#(0)
       else for each rtl in rtlst!#(m) collect
         for j := 0:m collect roundroot(part(rtl,j+1),pra!#(j));
rt2: precision pr!*;
     return rtlst!#(m)
     end;

algebraic procedure testsub(lst,quotlst,m);
 % this substitutes the variable value list lst into the derivative
 % quotient quotlst, but avoids 0/0 errors.  For the purposes to which
 % we are putting testsub, infinity is replaced by 1.
  begin scalar nmr,dnr,dnv;
    nmr := first quotlst; dnr := second quotlst;
    ex!! := algebraic nmr/algebraic dnr;
    nmr := num ex!!; dnr := den ex!!;
    while (dnv := sub(lst,dnr))=0 do if sub(lst,nmr)=0 then
      <<nmr := df(nmr,varbl!#(m)); dnr := df(dnr,varbl!#(m));
        if dnr neq 0 then
          <<ex!! := algebraic nmr/algebraic dnr;
            nmr := num ex!!; dnr := den ex!!>>
          else (<<nmr := 1; dnr := 1;
                 lprim "stuffing 1 (dnr prob)">> where !*msg=t) >>
      else (<<nmr := 1; dnr := 1;
              lprim "stuffing 1 (nmr prob)">> where !*msg=t);
    return sub(lst,nmr)/dnv end;

symbolic procedure sortvals1(a,b);
   begin scalar c,d; a := cdr a; b := cdr b;
    % since some variables (and hence their values) may not occur...
 lp: if not a or not b then return nil;
     c := caddar a; d := caddar b;
     algebraic (c := repart c); algebraic (d := repart d);
     algebraic if c < d then return t else if c = d then go to tst;
     return nil;
tst: if (a := cdr a) then <<b := cdr b; go to lp>> end;

algebraic procedure getvars p;
   begin scalar vl,v,v1,lt,c,!*msg;
     c := lisp !*complex; if not c then on complex;
     vl := {};
lp1: if numberp(v := mainvar p) then go to ret
        else if not member(v,vl) then vl := v . vl;
     lt := lcof(p,v); p := reduct(p,v);
lp2: if numberp(v1 := mainvar lt) then goto lp1
        else if not member(v1,vl) then vl := v1 . vl;
     lt := lcof(lt,v1); go to lp2;
ret: if not c then off complex;
     return reverse vl end;

symbolic operator spurival,spurifix;
share val!$,val2!$,eps!$,pr!*;

symbolic procedure spurival vals;
  % produces a list of flattened index of suspicious terms (starting at
  % 1) or {}.  spurifix then checks the indexed items and trims spurious
  % values.
   begin scalar fl,r,c,!*msg; integer m; eps!$ := 10.0^-pr!*;
     r := !*rounded; c := !*complex; on rounded; off complex;
     for each rlst in cdr vals do for each val in cdr rlst do
        <<m := m+1; val!$ := prepsq simp!* caddr val;
          if eqcar(val!$,'plus) and algebraic testval1 val!$
             then fl := m . fl>>;
     if not r then off rounded; if c then on complex;
     return 'list . reversip fl end;

algebraic procedure testval1 val;
  begin scalar rl,im;
    rl := abs repart val; im := abs impart val;
    if rl>0 and im>0 and im<eps!$*rl or rl<eps!$*im then return t end;

symbolic procedure spurifix(ndx,soln1,soln2);
  % soln1 is vals used in spurival, soln2 is vals for higher precision,
  % and ndx is flattened index of those to be tested.  All indexed
  % pairs of roots will be checked and a new soln1 list is made with
  % unmatched small parts of complex roots stripped off.
   if null ndx or length soln1 neq length soln2 then soln1 else
   begin scalar sol0,soln3,lst1,lst2,lst3,val1,val2,eq1,eq2,
           eq3,r,c,!*msg,tri;
         integer m,m0;
      r := !*rounded; c := !*complex; on rounded; off complex;
      soln1 := cdr (sol0 :=soln1); soln2 := cdr soln2; ndx := cdr ndx;
      m0 := car ndx; ndx := cdr ndx;
 lp1: if not soln1 then <<soln3 := 'list . reversip soln3; go to ret>>;
      lst1 := cdar soln1; lst2 := cdar soln2;
      soln1 := cdr soln1; soln2 := cdr soln2;
      if length lst1 neq length lst2 then <<soln3 := sol0; go to ret>>;
 lp2: if not lst1 then
         <<soln3 := ('list . reversip lst3) . soln3;
           lst3 := nil; go to lp1>>;
      eq1 := car lst1; eq2 := car lst2; m := m+1;
      lst1 := cdr lst1; lst2 := cdr lst2;
      if not m0 or m<m0 then <<lst3 := eq1 . lst3; go to lp2>>;
      if not ndx then m0 := nil else
         <<m0 := car ndx; ndx := cdr ndx>>;
      eq1 := eq1;
      val!$ := prepsq simp!* (val1 := caddr eq1);
      val2!$ := prepsq simp!* (val2 := caddr eq2);
      tri := algebraic testval2(val!$,val2!$);
      if tri=aeval 'failed then
        <<((lprim
             "match failed! root stripping aborted: raw roots returned")
             where !*msg=t); soln3 := sol0; go to ret>>;
      eq3 := if tri=0 then eq1
         else {'equal,cadr eq1,
                if freeof(car(val1 := cdr val1),'i)
                  then if tri=1 then cadr val1 else car val1
                  else if tri=1 then car val1 else cadr val1};
      lst3 := eq3 . lst3; go to lp2;
 ret: if not r then off rounded; if c then on complex;
      return soln3 end;

algebraic procedure testval2(a,b);
   begin scalar rl1,rl2,im1,im2;
      rl1 := abs repart a; rl2 := abs repart b; im1 := abs impart a;
      im2 := abs impart b;
      return if rl1=rl2 then if im1=im2 then 0 else 2
                else if im1=im2 then 1 else failed end;

%%end;    %this is the end of the changed or added functions

symbolic procedure isvar(x,var);
  (if eqcar(x,'list) then cadadr x else cadr x)=var;

symbolic operator isvar;

algebraic procedure outcombine1(rts,p1,p2);
 % here p1 is an outerproduct, and p2 is another outerproduct with
 % the same first variable. from the two, we form a single outerproduct
 % by forming all lists with the first variable appearing only once.
 % rts is the root list for the base variable.  A complication is caused
 % by the possibility that one of more root values may be missing from
 % p1, p2, or both.
  begin scalar prod,p1strt,p1end,p2strt,p2end;
     prod := {};
     for each rt in rts do
   <<p1end := second(p1strt := findvals(p1,rt)); p1strt := first p1strt;
     p2end := second(p2strt := findvals(p2,rt)); p2strt := first p2strt;
     if p1strt > 0 and p2strt > 0 then
       for n1 := p1strt:p1end do for n2 := p2strt:p2end do
         prod := append(prod,{append(part(p1,n1),rest part(p2,n2))})>>;
     return prod end;

symbolic procedure findvals(p,rt);
   begin scalar val,pp,pp1; integer n,b,e;
     val := algebraic lisp caddr rt; pp := cdr p;
 lp: pp1 := car pp; pp := cdr pp; n := n+1;
     if algebraic lisp caddr cadr pp1 = val then
       <<if b = 0 then b := n; e := n>>;
     if pp then go to lp;
     return 'list . {b,e} end;

symbolic operator findvals;

algebraic procedure outcombine2(p1,p2);
   begin scalar prod;
      prod := {};
      for each r1 in p1 do for each r2 in p2 do
         prod := append(prod,{append(r1,r2)});
      return prod end;

symbolic procedure sortvars();
   algebraic varsortsolns!* :=
     'list . for each rts in cdr algebraic grandsoln!*
       collect 'list . sort(cdr rts,
         function (lambda(a,b); ordop(cadr a,cadr b)));

symbolic operator sortvars;

symbolic procedure sortvals();
   algebraic sortvals!* := 'list . sort(cdr algebraic varsortsolns!*,
     function sortvals1);

symbolic operator sortvals;

algebraic procedure cabs x;
  if lisp !*compxroots then sqrt((repart x)^2 + (impart x)^2) else x;

algebraic procedure membno(n,l);
   if n=first l then 1
     else if rest l = 0 then 0 else 1 + membno(n,rest l);

algebraic procedure getpaths n;
  % this is used to call links2paths for testing purposes only.
   begin scalar links; links := {};
     for j := 0:n do for k := 0:n do
        if j neq k and subset1(vll!# j,vll!# k) then
        links := append(links,{{j,k}});
     return links2paths links end;

algebraic procedure links2paths links;
  begin scalar paths,paths2,bases,fl,fl2;
     paths := paths2 := {}; bases := root npoly!*;
    % multroot will not work if there are no bases;
     if bases = {} then return nil;
    % extend from bases if possible.
     for each base in bases do
       <<fl := nil;
         for each link in links do if base = first link then
           <<fl := t; paths2 := append(paths2,{link})>>;
         if not fl then paths := append(paths,{{base}})>>;
    % now extend each path in paths2 if possible.  When fully
    % extended, add path to paths.
ext: fl2 := nil;
     for each path in paths2 do
       <<fl := nil;
         for each link in links do if first link = last path then
           <<fl := t; fl2 := t;
             paths2 := append(paths2,{append(path,{second link})})>>;
        if not fl then paths := append(paths,{path});
        paths2 := delete(path,paths2)>>;
     if fl2 then go to ext;
     return paths end;

symbolic operator delete;

algebraic procedure last x; first reverse x;

symbolic procedure subset1(a,b);
   length b-length a=1 and subsetp(a,b);

symbolic operator subset1;

algebraic procedure root n;
   begin scalar trrt; trrt := {};
     for j := 0:n do if length vll!# j=1 then trrt := append(trrt,{j});
     return trrt end;

algebraic procedure pfx(pr,fl);
   begin scalar prf,f,ff;
     prf := fl*10.0^pr; ff := 1.0; f := 0;
     while prf*ff>1.0 do <<ff := ff/10; f := f+1>>;
     return f end;

symbolic procedure roundroot(a,p);
<<p := {'equal,cadr a, if caaddr a = 'minus then
  {'minus, rtrnda(cadr caddr a,p)}
   else rtrnda(caddr a,p)};
  algebraic p>>;

symbolic operator roundroot;

algebraic procedure elim(a,b);
  % compares list b with list a (whose length is shorter by 1) and
  % returns the unmatched member.
   begin scalar x;
     for each el in b do if not member(el,a) then x := el;
     return x end;

algebraic procedure combinerts(r0,r1);
   begin scalar xout; xout := {};
     return if r1 = {} then {} else
       <<for each rt1 in r1 do
           xout := append(xout,{append(r0,{rt1})});
         xout>> end;

endmodule;


end;
