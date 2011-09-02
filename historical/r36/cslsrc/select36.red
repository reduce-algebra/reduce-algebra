%
% Run using smallr35 to select code to compile into C.
% I run "reduce.tst" as the main test to tune against, but also
% use data collected (elsewhere) to ensure that the most heavily
% used functions in various other tests are catered for.
%

%
% I recompile the patches module in case it has changed since the main
% image file that I am using was created.
%

on comp, backtrace;
in "../src/patches.red"$

% It is a misery that the REDUCE test files do not tidy up after themselves,
% so if I want to run several in the same job I have to put well-judged
% CLEAR statements between.  If I miss out some of these almost any
% curious behaviour might arise.

on echo;
lisp verbos 3;

% Here I set up a list that documents what appear to be the most
% heavily used few functions in each of a number of the test files.
% I will force these to be compiled into C regardless of what is in the
% benchmark files that I process as well

lisp (force_these := '(
% Reduce.tst
    getel1 simpcar noncomp ordop delcp multd addf terminalp
    multf prin2!* !*ssave getrtypeor getrtype timesip getrtype2
    exchk simp ordad getel readch1 spur0 kahane spurr sprgen1
% Int.tst
    ordop reorder multd addf powers0 multf maxdeg
    noncomp rmultpf quotf1 quotf negf addd raddf degr
    !*n2f !*d2q minusf ordpp
% Factor.tst
    !*n2f adjoin!-term multiply!-by!-constant!-mod!-p plus!-mod!-p
    remainder!-in!-vector mksp getpower addf multd times!-term!-mod!-p
    multf listsum to noncomp times!-mod!-p fkern clear!-column addd
    minus!-mod!-p multdm
% Decompos.tst
    freeof freeofl !*n2f smember addf ordop multd multf
    to adjoin!-term noncomp addd multdm adddm mkspm sub2chk
    multiply!-by!-constant!-mod!-p plus!-mod!-p ordpp exchk
% Limits.tst
    ps!:getv ps!:last!-term ps!:order ps!:get!-term ps!:evaluate exchk
    multsq retimes1 prepf1 quotf addsq prepf ps!:times!-erule replus
    retimes ps!:putv !*d2q exchk1 prepsq prepd
% Matrix.tst
    addf multd !*n2f multf addd to c!:ordxp c!:ordexp noncomp
    adddm negf c!:extadd ordop quotf1 c!:extmult mkspm sub2chk
    c!:ordexn scprint multdm
% Groebner.tst
    evcompless!? evcomp evlexcomp evinvlexcomp evgradlexcomp
    evrevgradlexcomp evtdeg evgradgradcomp evgradgradcomp1
    evpartdeg evpartdeg1 evgradrevgradcomp evgradrevgradcomp1
    evlexgradlexcomp evlexgradlexcomp1 evlexrevgradlexcomp
    evlexrevgradlexcomp1 evweightedcomp evweightedcomp1 evgradedinit
    evgradedcomp ev!-gamma vevzero!?1 vevmtest!? bcint2op
    bcprod vevcan0 evsum quotf evzero!? diplength groebsearchinlist
    listsum exchk multd reorder retimes1 vevmaptozero1 ordop
    evrevgradlexcomp evtdeg bccheckz buch!-vevdivides!? bcsum
    dipilcomb1
% Roots.tst
    CSL_normbf CSL_timbf round!:mt round!:last plus!: divide!:
    conv!:mt ncoeffs gftimesn difference!: plubf terminalp
    lastpair abs!: gfplusn gfrsq cut!:mt gfdot readch1 gbfdot
% Solve.tst
    ordop freeof freeofl smember addf multd multf !*n2f noncomp
    negf to exchk ordpp vevmtest!? addd multdm retimes1 reorder
    adddm mkspm
% Compact.tst
    termsf addf !*n2f addd multd multf noncomp to
    adddm negf mkspm sub2chk multdm kernels1 red!-weight1
    !:minus nonzero!-length ordop mv!-pow!-!+ ordpp
% Gcd.tst
    !*n2f adjoin!-term multiply!-by!-constant!-mod!-p
    plus!-mod!-p mksp addf getpower multd addd
    times!-term!-mod!-p times!-mod!-p ordop multf
    fkern noncomp powers2 to adddm raddf reorder
% Excalc.tst
    ordop reorder delall maxdeg powers0 rmultpf raddf
    quotf to quotf1 lastpair reordop addf multf quotfm
    exchk ordpp noncomp negf multd
% Tps.tst
    ps!:getv ps!:last!-term ps!:order quotf exchk
    ps!:get!-term retimes1 prepf1 prepf minusf multsq
    ps!:evaluate replus revpr retimes gcdf lnc quotf1
    terminalp scprint
% Taylor.tst
    gcdfd1 quotf multd lastpair addf
    gcdf minusf quotf1 multf multsq gcdf1 gcdfd
    lnc terminalp ordop
% Sum.tst
    addf noncomp multf multd to !*n2f addd ordop reorder
    adddm multdm mkspm sub2chk lastpair raddf ordpp exchk
    negf rmultpf quotf1
% Algint.tst
    addf multd ordop reorder multf noncomp delall
    powers0 to !*n2f addd quotf1 maxdeg rmultpf
    negf adddm subs2f1 depends ldepends raddf
% Scope.tst
    lastpair terminalp initbrsea testred initwght
    token prin2x readch1 numberofocc downwght1 pnthxzz
    lispeval smember inshisto delcp pprin2
    downwght toknump init
% Gentran.tst
    lastpair terminalp pprin2 readch1 token prin2x
    listp exchk prepf1 retimes1 delcp ordop nconc!*
    toknump mkvar lispeval exchk1 noncomp reversip!*
% Arnum.tst
    !*n2f multd addf adjoin!-term remainder!-in!-vector
    multf to addd rnzerop!: multdm noncomp rnequiv adddm
    rnonep!: int!-equiv!-chk times!-in!-vector mkrn
    plus!-mod!-p multiply!-by!-constant!-mod!-p mksp
% Elem.tst
    delcp terminalp readch1 exchk sinitl striptag
    CSL_normbf convprec!* prin2x token
    replus convchk prepf retimes1 errorset!* errorp round!:mt
% Complex.tst
    !*n2f CSL_normbf terminalp multd remainder!-in!-vector
    adjoin!-term round!:mt addf readch1 round!:last
    multiply!-by!-constant!-mod!-p scprint prin2!*
    gizerop!: mkgi times!-in!-vector addd striptag
% Rounded.tst
    terminalp smemql CSL_normbf readch1
    !:round!:mt round!:last prin2!* !*ssave token
    prin2x exchk scprint convprec divide!: sinitl getrtype
    round!*
% Math.tst
    terminalp readch1 prin2x token delcp reversip!* mkvar
    token1 toknump convertmode scan formc arrayp
    eolcheck xread1 getrmacro macrochk form1
% Spde.tst
    ordop ldepends depends exchk prepf1 ordpp
    retimes1 multsq ordad addf difff nconc!* exchk1
    addsq !*d2q multd simpcar multf sqchk
% Avector.tst
    prin2!* negnumberchk update!-pline ordop maprint
    putpline noncomp multf layout!-formula scprint
    prepf1 addf quotf1 oprin exchk negf retimes1
    nconc!* to exptpri
% Orthovec.tst
    exchk prepf1 retimes1 nconc!* exchk1 prepf retimes
    getrtype getrtypeor reval replus simpcar prepd
    getrtype2 sqchk reval2 simp prepsqxx !*ssave
% Specfn.tst
    CSL_normbf round!:mt subs3f round!:last exchk
    revpr quotsq convprec!* !*ssave striptag subs3q
    divide!: simpcar subs3f1 getrtype2 getrtype multsq
    addsq convchk
% Misc
    modzerop!: modonep!: !*modular2f general!-modular!-plus
    general!-modular!-times modplus!: modtimes!: dcombine
      ))$

symbolic procedure cf(p, q);
   (float caddr p/float cadr p) > (float caddr q/float cadr q);

symbolic mapstore 4;  % reset counts;

in "../xmpl/reduce.tst";

symbolic (w_reduce := sort(mapstore 2, function cf))$

clear a, xx, yy, zz, k1, ki, kf, p1, pf,
      eei, ef, ki, kf, p1, pf, gp, ix, iy, iz,
      p2, p3, p4, qi, q2, ga, gb, w;


% The lines commented out thus "%---" are a prototype of how to
% include one or more further test files in this benchmark/tuning
% suite.

%--- symbolic mapstore 4;
%---
%--- in "../xmpl/int.tst";
%---
%--- symbolic (w_int := sort(mapstore 2, function cf))$
%---
%--- clear f1s, a, z, u, v;

symbolic;

fluid '(w);

w := w_reduce$

symbolic procedure top_twenty x;
  begin
    scalar y;
    for i := 1:20 do
       if x then << y := car x . y; x := cdr x >>;
    return y
  end;

symbolic procedure addin r;
  begin
    scalar v;
    v := assoc(car r, w);
    if not v then w := r . w
    else w := list(car r, cadr r + cadr v, caddr r + caddr v) . delete(v, w);
    return nil
  end;

%--- w_int      := top_twenty w_int$

for i := 1:20 do <<
%---    if w_int      then << addin car w_int;      w_int      := cdr w_int >>;
   nil >>;

z := w$ w := nil;
for each v in z do begin
   scalar name, name1;
   name := car v;
   name1 := symbol!-env name;
   if not atom name1 then <<
      name1 := cdr name1;
      if vectorp name1 then name := getv(name1, 0) >>;
   addin list(name, cadr v, caddr v) end;

w := sort(w, function cf)$

for each fn in force_these do begin
    scalar name1;
    name1 := symbol!-env fn;
    if not atom name1 and vectorp cdr name1 then fn := getv(cdr name1, 0);
    addin list(fn, 0, 0);
    force_these := cdr force_these end;

total_bytes_executed := 0;
for each v in w do total_bytes_executed := total_bytes_executed + caddr v;

symbolic procedure listsize(x, n);
   if null x then n
   else if atom x then n+1
   else listsize(cdr x, listsize(car x, n+1));

fnames := '("u01" "u02" "u03" "u04" "u05"
            "u06" "u07" "u08" "u09" "u10"
            "u11" "u12");

size_per_file := 5000;

symbolic procedure get!-saved m;
  << loaded!-packages!* := nil;
     load!-package m;
     for each x in oblist() do
        if not atsoc(x, w) then remprop(x, '!*savedef)
  >>;

% With !*savedef = '!*savedef when I load a module I do not load the
% executable code in it - just the saved function definitions on
% property lists (also I execute any code in the file that is not
% just defining a function).  Since some modules define functions
% that they then call, I need to define suitable placeholders here.

symbolic procedure set!-teeny!-primes(); nil;
symbolic procedure initio(); nil;
symbolic procedure find!!flim(); nil;
algebraic procedure get!-eulers!-constant; 0;
symbolic procedure root_of_eval u; '!*xxx!*;

% The taylor module defines and uses a macro (taylor!:) in a way that
% seems to make it hard for me to handle using the general mechanism
% I use below.

get!-saved 'taylor;

!*savedef := '!*savedef;

<<
% I load the files here with the largest module first. This is intended
% to ease memory pressure.  But I put the core system last so that
% definitions in it take precedense over those in optional modules.

get!-saved 'algint;
%     get!-saved 'int;
get!-saved 'scope;
%     get!-saved 'gentran;
get!-saved 'factor;
%     get!-saved 'ezgcd;
get!-saved 'roots2;
%     get!-saved 'roots;
get!-saved 'excalc;
get!-saved 'groebnr2;
%     get!-saved 'groebner;
%     get!-saved 'dipoly;
get!-saved 'solve;
%     get!-saved 'matrix;
get!-saved 'specfn2;
%     get!-saved 'specfn;
%     get!-saved 'specfaux;
get!-saved 'specbess;
get!-saved 'numeric;
% get!-saved 'spde;      Not loaded because of function clashes
get!-saved 'misc;
%     get!-saved 'tps;
get!-saved 'rlisp88;
get!-saved 'arnum;
get!-saved 'odesolve;
% get!-saved 'rcref;     Not loaded because I will not worry about speed here
% get!-saved 'avector;   Not loaded because of function clashes
get!-saved 'hephys;
% get!-saved 'orthovec;  Not loaded because of function clashes
get!-saved 'compact;
% get!-saved 'rprint;    Not loaded because I will not worry about speed here
% get!-saved 'cedit;     Not loaded because I will not worry about speed here
% get!-saved 'pretty;    Not loaded because I will not worry about speed here
get!-saved 'module;

% Now do some tidying up - to try to free up some memory

for each x in oblist() do
   for each y in '(simpfn dfn opmtch klist kvalue avalue) do
      remprop(x, y);

% I reload the most basic bits of REDUCE once again to ensure that the
% definitions that I will compile into C come from these modules even
% if some other package redefines something critical.

get!-saved 'rlisp;
get!-saved 'cslrend;
get!-saved 'poly;
get!-saved 'alg;
get!-saved 'arith;
get!-saved 'mathpr;

off echo;
in "../src/patches.red"$
on echo;

!*savedef := nil;

set!-print!-precision 4;
benefit := 0;

symbolic verbos nil;
global '(rprifn!*);

load_package ccomp;

on fastfor, fastvector, unsafecar;

while fnames do begin
   scalar bulk;
   princ "About to create "; printc car fnames;
   c!:ccompilestart car fnames;
   bulk := 0;
   while bulk < size_per_file and w do begin
      scalar name, defn, value;
      name := caar w;
      value := float caddar w/((1.0+sqrt float cadar w)*1000.0);
      defn := get(name, '!*savedef);
      remprop('name, '!*savedef);  % Save a little space.
      if null defn then <<
         princ "+++ "; prin name; printc ": no saved definition found";
         w := cdr w >>
      else <<
         bulk := listsize(defn, bulk);
         if bulk < size_per_file then <<
            benefit := benefit + caddar w;
            prin name; ttab 30; prin value;
            ttab 45; print (100.0*float benefit/float total_bytes_executed);
            c!:ccmpout1 ('de . name . cdr defn);
            w := cdr w >> >> end;
   eval '(c!-end);
   fnames := cdr fnames
   end;

terpri();
printc "*** End of compilation from REDUCE into C ***";
terpri();

bulk := 0;
% I list the next 50 functions that WOULD get selected - just for interest.
while bulk < 50 and w do
  begin
     name := caar w;
     value := float caddar w/((1.0+sqrt float cadar w)*1000.0);
     defn := get(name, '!*savedef);
     if null defn then <<
        princ "+++ "; prin name; printc ": no saved definition found";
        w := cdr w >>
     else <<
        bulk := bulk+1;
        benefit := benefit + caddar w;
        prin name; ttab 30; prin value;
        ttab 45; print (100.0*float benefit/float total_bytes_executed);
        w := cdr w >> end;

nil >>;

quit;

