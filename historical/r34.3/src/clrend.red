module rend; % CL REDUCE "back-end".

% Copyright (c) 1991 RAND.  All Rights Reserved.

symbolic procedure delcp u;
   % Returns true if U is a semicolon, dollar sign, or other delimiter.
   % This definition replaces one in the BOOT file.
   u eq '!; or u eq '!$;

symbolic procedure seprp u;
   % Returns true if U is a blank or other separator (eg, tab or ff).
   % This definition replaces one in the BOOT file.
     u eq '!  or u eq '!         or u eq !$eol!$;

% Common LISP specific definitions.

flag('(load),'opfn);

% The next one is added since it is a familiar name for this
% operation.

symbolic procedure prop u; symbol!-plist u;
  

% tr and untr are defined in clend.lisp.

deflist('((tr rlis) (untr rlis)),'stat);


% The FACTOR module also requires a definition for GCTIME. Since this
% is currently undefined in CL, we provide the following definition.

symbolic procedure gctime; 0;

% yesp1 is more or less equivalent to y-or-n-p.

remflag('(yesp1),'lose);

symbolic procedure yesp1; y!-or!-n!-p();

flag('(yesp1),'lose);

% The Common Lisp TOKEN function returns tokens rather than characters,
% so CEDIT must be modified.

remflag('(cedit),'lose);

symbolic procedure cedit n;
   begin scalar x,ochan;
      if null terminalp() then rederr "Edit must be from a terminal";
      ochan := wrs nil;
      if n eq 'fn then x := reversip crbuf!*
       else if null n
        then if null crbuflis!*
               then <<statcounter := statcounter-1;
                      rederr "No previous entry">>
              else x := cdar crbuflis!*
       else if (x := assoc(car n,crbuflis!*))
        then x := cedit0(cdr x,car n)
       else <<statcounter := statcounter-1;
              rederr list("Entry",car n,"not found")>>;
      crbuf!* := nil;
      % Following line changed for CL version.
      x := foreach y in x conc explodec y;
      terpri();
      editp x;
      terpri();
      x := cedit1 x;
      wrs ochan;
      if x eq 'failed then nil
      % Following changed for CL version.
      else 
        crbuf1!* := compress(append('(!") ,
                                       append(x, '(!" ))));
   end;

flag('(cedit),'lose);

% FLOOR is already defined.

flag('(floor),'lose);

% CL doesn't like '(function ...) in defautoload (module entry).

remflag('(mkfunction),'lose);

smacro procedure mkfunction u; mkquote u;

flag('(mkfunction),'lose);

remflag('(not_imag_num),'lose);

fluid '(!*keepsqrts !*msg !*numval dmode!*);

symbolic procedure not_imag_num a;
 % Tests true if a is a number that is not a pure imaginary number.
   begin scalar v,!*keepsqrts,!*msg,!*numval,dmode, sqrtfn;
      dmode := dmode!*;
      !*numval := t;
      sqrtfn := get('sqrt, 'simpfn);
      put('sqrt, 'simpfn, 'simpsqrt);
      on rounded,complex;
      a := resimp simp a;
      a := numberp cdr a and domainp car a and car repartsq a;
      off rounded,complex;
      if dmode then onoff(get(dmode,'dname),t);
      put('sqrt, 'simpfn, sqrtfn);
      return a
   end;


flag('(not_imag_num),'lose);

% The following redefines a function in the roots package.

remflag('(nrstrt0),'lose);

fluid '(!*bftag !*gfp !*hardtst !*xn !*xobf !*xo acc!# prec!# !:prec!:);

global '(!!nfpd);

symbolic procedure nrstrt0(q,r,p1);
   begin scalar rr,x,b,pr,ps,p2,qf; pmsg pbfprint q; b := !*bftag;
      ps := !:prec!:; pr := if b then ps else !!nfpd;
      p2 := gfzerop(rr := a2gf r); !*gfp := qf := q;
      if b then go to r2;
      if errorp(q := errorset!*(list('cflotem,mkquote qf),nil))
        or errorp(r := errorset!*(list('gf2fl,mkquote rr),nil))
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
         <<setflbf b; !:prec!: := ps; return acc!# . x>>;
      pr := !:prec!: := prec!#;
      if not !*bftag then b := !*bftag := t;
      if p2 then go to r2 else <<p2 := t; go to r1>> end;

flag('(nrstrt0),'lose);

% Needed by library packages.

symbolic procedure ncons u; u . nil;

remflag('(boundssincos),'lose);

symbolic procedure boundssincos u;
   % Reason if one of the turn points (n*pi) is in the
   % range. If yes, include the corresponding value 1 or -1.
   % Otherwise compute the range spanned by the end points.
  begin scalar n,lo,hi,alo,ahi,!1pi,!2pi,!3pi,l,m;
        integer s;
     n := errorset(list('boundseval2,mkquote cadr u),nil,nil);
     if atom n then goto trivial;
     n := car n;
     lo := car n; hi := cdr n; 
     !1pi := simp 'pi;
     if not domainp car !1pi then goto trivial;
     !2pi := addsq(!1pi,!1pi); !3pi := addsq(!1pi,!2pi);
       % convert sin to cos
     if car u = 'sin then <<m :=multsq(!1pi, (-1) . 2);
         lo := addsq(lo,m); hi := addsq(hi,m)>>; 
     m := negsq multsq(!2pi,fixsq quotsq(lo,!2pi));
       % move interval to main interval
     lo:=addsq(lo,m); hi:=addsq(hi,m);
     if minusf car lo then
     <<lo := addsq(lo,!2pi); hi := addsq(hi,!2pi)>>;
     if null car lo or sqgreaterp(hi,!2pi) then l:= (1 . 1) . l;
     if (sqgreaterp(!1pi,lo) and  sqgreaterp(hi,!1pi))
      or(sqgreaterp(!3pi,lo) and  sqgreaterp(hi,!3pi))
       then l := ((-1) . 1) . l;
     if l and cdr l then goto trivial;
     l := num!-cossq lo . num!-cossq hi . l;
     return minsq l . maxsq l;
 trivial:
     return ((-1) . 1) . (1 . 1);
  end;

flag('(boundssincos),'lose);

endmodule;

end;
