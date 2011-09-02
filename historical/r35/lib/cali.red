% Author H.-G. Graebe | Univ. Leipzig
% graebe@informatik.uni-leipzig.d400.de

module cali;

terpri(); write "CALI 2.1. Last update 22/10/93"; terpri();

COMMENT

              #########################
              ####                 ####
              ####  HEADER MODULE  ####
              ####                 ####
              #########################

This is the header module of the package CALI, a package for
computational commutative algebra.

Author :        H.-G. Graebe
                Univ. Leipzig
                FB Mathematik/Informatik
                Augustusplatz 10 - 11
                D - 04109 Leipzig
                Germany

        email : graebe@informatik.uni-leipzig.d400.de


Version : 2.1, finished at Oct. 22, 1993.

See cali.chg for change's documentation.

Please send all comments, bugs, hints, wishes, criticisms etc. to the
above email address.


Abstract :

This package contains algorithms for computations in commutative
algebra closely related to the Groebner algorithm for ideals and
modules. There are facilities for local computations, using a modern
implementation of Mora's standard basis algorithm, that works for
arbitrary term orders. This reflects the full analogy between modules
over local rings and homogeneous (in fact H-local) modules over
polynomial rings.

CALI extends also the restricted term order facilities of the
groebner package, defining term orders by degree vector lists, and
the rigid implementation of the sugar idea, by a more flexible ecart
vector, in particular useful for local computations.

The package was designed mainly as a symbolic mode programming
environment extending the build-in facilities of REDUCE for the
computational approach to problems arising naturally in commutative
algebra. An algebraic mode interface allows to access (in a more
rigid frame) all important features implemented symbolically.

As main topics CALI contains facilities for

-- defining rings, ideals and modules,

-- computing Groebner bases and local standard bases,

-- computing syzygies, resolutions and (graded) Betti numbers,

-- computing Hilbert series, multiplicities, independent sets,
        dimensions.

-- computing normal forms and representations,

-- computing sums, products, intersections, elimination ideals etc.

-- primality tests, radicals, unmixed parts, primary decompositions
        etc. of ideals and modules,

-- scripts for advanced applications of Groebner bases (blowup,
        associated graded ring, analytic spread,
        symmetric algebra, monomial curves etc.)


Reduce version required :

The program was tested under v. 3.4.1., but should work as well under
v. 3.3.


Relevant publications :

See the bibliography in the manual.


Key words :

Groebner algorithm for ideals and modules, local standard bases,
normal forms, Hilbert series, independent sets, free resolution,
constructive commutative algebra, primality test, radical,
unmixed part, primary decomposition, blowup, associated graded ring,
analytic spread, symmetric algebra, monomial curves, sets of points.

END COMMENT;

comment
create!-package( '(
        cali            % This header module.
        bcsf            % Base coeff. arithmetics.
        ring            % Base ring and monomial arithmetics.
        mo              % Monomial arithmetic.
        dpoly           % Distr. polynomial (and vector) arithmetics.
        bas             % Polynomial lists.
        dpmat           % dpmat's arithmetic.
        red             % Normal form algorithms and related topics.
        groeb           % Groebner algorithm and related topics.
        mora            % Modifications for local computations.
        matop           % Module operations on dpmats.
        quot            % Different quotients.
        moid            % Lead. term ideal algorithms.
        res             % Resolutions.
        intf            % Interface to algebraic mode.
        odim            % Alg. for zerodimensional ideals and
                        % modules.
        prime           % Primality test, radical, and primary
                        % decomposition.
        ),nil);

load!-package 'matrix;

fluid '(
        cali!=rules     % see bcsf
        cali!=basering  % see rings
        cali!=degrees   % see mons in rings
        cali!=trace     % see red, groeb, mora
        cali!=monset    % see groeb
        );

                        % Default :
switch
        hardzerotest,   % (off) see bcsf, try simp for each zerotest.
        red_total,      % (on)  see red, do total reductions.
        binomial,       % (off) see red, do multireductions
                        %                for binomial ideals.
        bcsimp,         % (on)  see red, cancel coefficient's gcd.
        lazy,           % (off) see mora, apply the lazy strategy.
        noetherian,     % (on)  see interf, test term orders and
                        %                choose non local algorithms.
        factorunits,    % (off) see mora, try to remove units from
                        %               polynomials by factorization.
        detectunits;    % (off) see mora, detect generators of the form
                        %               monomial * unit.

% The first initialization : No tracing.

cali!=trace:=0;

% ---- Some useful things, probably implemented also elsewhere
% ---- in the system.

symbolic procedure first x; car x;
symbolic procedure second x; cadr x;
symbolic procedure third x; caddr x;

symbolic procedure strcat l;
% Concatenate the items in the list l to a string.
  begin scalar u;
  u:=for each x in l join explode x;
  while memq('!!,u) do u:=delete('!!,u);
  while memq('!",u) do u:=delete('!",u);
  return compress append(append('(!"),u),'(!"));
  end;

symbolic procedure numberlistp l;
% l is a list of numbers.
  if null l then t
  else fixp car l and numberlistp cdr l;

symbolic procedure merge(l1,l2,fn);
% Returns the (physical) merge of the two sorted lists l1 and l2.
  if null l1 then l2
  else if null l2 then l1
  else if apply2(fn,car l1,car l2) then rplacd(l1,merge(cdr l1,l2,fn))
  else rplacd(l2,merge(l1,cdr l2,fn));

symbolic procedure listexpand(fn,l); eval expand(l,fn);

symbolic procedure listtest(a,b,f);
% Return the first u in a s.th. f(u,b) or nil.
  if null a then nil
  else if apply2(f,car a,b) then
        if car a=nil then t else car a
  else listtest(cdr a,b,f);

symbolic procedure listminimize(a,f);
% Returns a minimal list b such that for all v in a ex. u in b such
% that f(u,v).
  if null a then nil else reverse cali!=min(nil,a,f);

symbolic procedure cali!=min(b,a,f);
  if null a then b
  else if listtest(b,car a,f) or listtest(cdr a,car a,f) then
        cali!=min(b,cdr a,f)
  else cali!=min(car a . b,cdr a,f);

symbolic procedure disjoint(a,b);
  if null a then t else not member(car a,b) and disjoint(cdr a,b);

symbolic procedure print_lf u;
% Line feed after about 70 characters.
  <<if posn()>69 then <<terpri();terpri()>>; prin2 u>>;

symbolic procedure cali_choose(m,k);
% Returns the list of k-subsets of m.
  if (length m < k) then nil
  else if k=1 then for each x in m collect list x
  else nconc(
        for each x in cali_choose(cdr m,k-1) collect (car m . x),
        cali_choose(cdr m,k));

endmodule; % cali - The header module



module bcsf;

COMMENT


            #######################
            #                     #
            #  BASE COEFFICIENTS  #
            #                     #
            #######################


These base coefficients are standard forms.

A list of REPLACEBY rules may be supplied with the setrules command
that will be applied in an additional simplification process.

This rules list is a list of s.f. pairs, where car should replace cdr.

END COMMENT;

% Standard is :

!*hardzerotest:=nil;

symbolic operator setrules;
symbolic procedure setrules m; setrules!* cdr reval m;

symbolic procedure setrules!* m;
  begin scalar r; r:=ring_names cali!=basering;
  m:=for each x in m collect
        if not eqcar(x,'replaceby) then
                typerr(makelist m,"rules list")
        else (numr simp second x . numr simp third x);
  for each x in m do
    if domainp car x or member(mvar car x,r) then
        rederr"no substitution for ring variables allowed";
  cali!=rules:=m;
  return getrules();
  end;

symbolic operator getrules;
symbolic procedure getrules();
  makelist for each x in cali!=rules collect
        list('replaceby,prepf car x,prepf cdr x);

symbolic procedure bc!=simp u;
  if cali!=rules then
  begin scalar r,c; integer i; i:=0;
  r:=cali!=rules;
  while r and (i<1000) do
  << c:=qremf(u,caar r);
     if null car c then r:=cdr r
     else
     << u:=addf(multf(car c,cdar r),cdr c);
        i:=i+1; r:=cali!=rules;
     >>;
  >>;
  if (i<1000) then return u
  else rederr"recursion depth of bc!=simp to high"
  end
  else u;

symbolic procedure  bc_minus!? u; minusf u;

symbolic procedure  bc_zero!? u;
    if (null u or u=0) then t
    else if !*hardzerotest and pairp u then
        null bc!=simp numr simp prepf u
    else nil;

symbolic procedure  bc_fi a; if a=0 then nil else a;

symbolic procedure  bc_one!? u; (u = 1);

symbolic procedure  bc_inv u;
% Test, whether u is invertible. Return the inverse of u or nil.
  if (u=1) or (u=-1) then u
  else begin scalar v; v:=qremf(1,u);
    if cdr v then return nil else return car v;
    end;

symbolic procedure  bc_neg u; negf u;

symbolic procedure  bc_prod (u,v); bc!=simp multf(u,v);

symbolic procedure  bc_quot (u,v);
  (if null cdr w then bc!=simp car w else typerr(v,"denominator"))
  where w=qremf(u,v);

symbolic procedure  bc_sum (u,v); addf(u,v);

symbolic procedure  bc_diff(u,v); addf(u,negf v);

symbolic procedure  bc_power(u,n); bc!=simp exptf(u,n);

symbolic procedure  bc_from_a u; bc!=simp numr simp!* u;

symbolic procedure  bc_2a u; prepf u;

symbolic procedure  bc_prin u;
% Prints a base coefficient in infix form
   ( if domainp u then
         if dmode!*='!:mod!: then prin2 prepf u
         else printsf u
     else << write"("; printsf u; write")" >>) where !*nat=nil;

symbolic procedure bc_divmod(u,v); % Returns quot . rem.
  qremf(u,v);

symbolic procedure bc_gcd(u,v); gcdf!*(u,v);

symbolic procedure bc_lcm(u,v);
    car bc_divmod(bc_prod(u,v),bc_gcd(u,v));

endmodule; % bcsf


module ring;

COMMENT

               ##################
               ##              ##
               ##    RINGS     ##
               ##              ##
               ##################


Informal syntax :

Ring = ('RING (name list) ((degree list list)) deg_type ecart)
        with deg_type = 'lex or 'revlex.

The term order is defined at first comparing successively degrees and
then by the name list lex. or revlex. For details consult the manual.

(name list) contains a phantom name cali!=mk for the module
component, see below in module mons.

The variable cali!=basering contains the actual base ring.

The ecart is a list of positive integers (the ecart vector for the
given ring) and has
        length = length names cali!=basering.
It is used in several places for optimal strategies (groeb) or to
guarantee termination (mora).
All homogenizations are executed with respect to that list.

END COMMENT;

symbolic procedure ring_define(n,to,type,ecart);
    list('ring,'cali!=mk . n, to, type,ecart);

symbolic procedure setring!* c;
  begin
     if !*noetherian and not ring_isnoetherian c then
        rederr"term order is not noetherian";
     cali!=basering:=c;
     setkorder ring_all_names c;
     return c;
  end;

symbolic procedure setecart!* e;
  begin scalar r; r:=cali!=basering;
    if not ring_checkecart(e,ring_names r) then
        typerr(e,"ecart vector")
    else cali!=basering:=
        ring_define(ring_names r,ring_degrees r,ring_tag r,e)
  end;

symbolic procedure ring_2a c;
    makelist {makelist ring_names c,
          makelist for each x in ring_degrees c collect makelist x,
          ring_tag c, makelist ring_ecart c};

symbolic procedure ring_from_a u;
  begin scalar vars,tord,c,r,tag,ecart;
  if not eqcar(u,'list) then typerr(u,"ring") else u:=cdr u;
  vars:=reval car u; tord:=reval cadr u; tag:=reval caddr u;
  if length u=4 then ecart:=reval cadddr u;
  if not(tag memq '(lex revlex)) then typerr(tag,"term order tag");
  if not eqcar(vars,'list) then typerr(vars,"variable list")
  else vars:=cdr vars;
  if tord={'list} then c:=nil
  else if not (c:=ring!=testtord(vars,tord)) then
        typerr(tord,"term order degrees");
  if null ecart then
     if (null tord)or not ring_checkecart(car tord,vars) then
                ecart:=for each x in vars collect 1
     else ecart:=car tord
  else if not ring_checkecart(cdr ecart,vars) then
        typerr(ecart,"ecart list")
  else ecart:=cdr ecart;
  r:=ring_define(vars,c,tag,ecart);
  if !*noetherian and not(ring_isnoetherian r) then
        rederr"Term order is non noetherian";
  return r
  end;

symbolic procedure ring!=testtord(vars,u);
% Test the non empty term order degrees for consistency and return
% the symbolic equivalent of u.
  if (ring!=lengthtest(cdr u,length vars +1)
        and ring!=contenttest cdr u)
            then for each x in cdr u collect cdr x
  else nil;

symbolic procedure ring!=lengthtest(m,v);
% Test, whether m is a list of (algebraic) lists of the length v.
  if null m then t
  else eqcar(car m,'list)
        and (length car m = v)
        and ring!=lengthtest(cdr m,v);

symbolic procedure ring!=contenttest m;
% Test, whether m is a list of (algebraic) number lists.
  if null m then t
  else numberlistp cdar m and ring!=contenttest cdr m;

symbolic procedure ring_names r; % User names only
        cdadr r;

symbolic procedure ring_all_names r; cadr r; % All names

symbolic procedure ring_degrees r; caddr r;

symbolic procedure ring_tag r; cadddr r;

symbolic procedure ring_ecart r; nth(r,5);

% --- Test the term order for the chain condition ------

symbolic procedure ring!=trans d;
% Transpose the degree matrix.
  if (null d)or(null car d) then nil
  else (for each x in d collect car x) .
                ring!=trans(for each x in d collect cdr x);

symbolic procedure ring!=testlex d;
   if null d then t
   else ring!=testlex1(car d) and ring!=testlex(cdr d);

symbolic procedure ring!=testlex1 d;
   if null d then t
   else if car d=0 then ring!=testlex1(cdr d)
   else (car d>0);

symbolic procedure ring!=testrevlex d;
   if null d then t
   else ring!=testrevlex1(car d) and ring!=testrevlex(cdr d);

symbolic procedure ring!=testrevlex1 d;
   if null d then nil
   else if car d=0 then ring!=testrevlex1(cdr d)
   else (car d>0);

symbolic procedure ring_isnoetherian r;
% Test, whether the term order of the ring r satisfies the chain
% condition.
  if ring_tag r ='revlex then
                ring!=testrevlex ring!=trans ring_degrees r
  else ring!=testlex ring!=trans ring_degrees r;

symbolic procedure ring!=degpos d;
  if null d then t
  else (car d>0) and ring!=degpos cdr d;

symbolic procedure ring_checkecart(e,vars);
  (length e=length vars) and ring!=degpos e;

% ---- Test noetherianity switching noetherian on :

put('noetherian,'simpfg,'((t (ring!=test))));

symbolic procedure ring!=test;
  if not ring_isnoetherian cali!=basering then
    << !*noetherian:=nil;
       rederr"Current term order is not noetherian"
    >>;

% ---- Different term orders in algebraic mode -------------

algebraic procedure eliminationorder(v1,v2);
% Elimination order : v1 = all variables
% v2 = variables to eliminate.
  { for each x in v1 collect
        if x member v2 then 1 else 0,
    for each x in v1 collect
        if x member v2 then 0 else 1};

algebraic procedure degreeorder(vars);
  {for each x in vars collect 1};

algebraic procedure localorder(vars);
  {for each x in vars collect -1};

% ---- Different term orders in symbolic mode -------------

symbolic procedure eliminationorder!*(v1,v2);
% Elimination order : v1 = all variables
% v2 = variables to eliminate.
  { for each x in v1 collect
        if x member v2 then 1 else 0,
    for each x in v1 collect
        if x member v2 then 0 else 1};

symbolic procedure degreeorder!*(vars);
  {for each x in vars collect 1};

symbolic procedure localorder!*(vars);
  {for each x in vars collect -1};

symbolic procedure ring_rlp(r,u);
% u is a subset of ring_names r. Returns the block order
% "first degrevlex on u, then the order on r"
  (for each x in ring_names r collect if x member u then 1 else 0)
  . append(for each x in u collect for each y in ring_names r collect
                if x=y then -1 else 0, ring_degrees r);


% ---------- Ring constructors -----------------

symbolic procedure ring_sum(a,b);
% Returns the direct sum of two base rings with degree matrix at
% first b then a and ecart=appended ecart lists.
  begin scalar vars,zeroa,zerob,degs,ecart;
  if not disjoint(ring_names a,ring_names b) then
    rederr"RINGSUM only for disjoint variable sets";
  vars:=append(ring_names a,ring_names b);
  ecart:=append(ring_ecart a,ring_ecart b);
  zeroa:=for each x in ring_names a collect 0;
  zerob:=for each x in ring_names b collect 0;
  degs:=append(
    for each x in ring_degrees b collect append(zeroa,x),
    for each x in ring_degrees a collect append(x,zerob));
  return ring_define(vars, degs, ring_tag a,ecart);
  end;

% --------- First initialization :

setring!* ring_define('(t x y z),'((1 1 1 1)),'revlex,'(1 1 1 1));

!*noetherian:=t;

% -------- End of first initialization ----------------

endmodule;  % ring



module mo;

COMMENT

               ##################
               ##              ##
               ##  MONOMIALS   ##
               ##              ##
               ##################



Monomials are of the form x^a*e_i with a multipower x^a and a module
component e_i. They belong either to the base ring R (i=0) or to a
free module R^c (c >= i > 0).

All computations are performed with respect to a "current module"
over a "current ring" (=cali!=basering).

To each module component e_i of the current module we assign a
"column degree", i.e. a monomial representing a certain multidegree
of the basis vector e_i. See the module dpmat for more details.
The column degrees of the current module are stored in the assoc.
list cali!=degrees.


Informal syntax :

  <monomial> ::= (<exponential part> . <degree part>)
  < .. part> ::= list of integer

Here exponent lists may have varying length since trailing zeroes are
assumed to be omitted. The zero component of <exp. part> contains the
module component. It correspond to the phantom var. name cali!=mk.

END COMMENT;

% ----------- manipulations of the degree part --------------------

symbolic procedure mo!=sprod(a,b);
% Scalar product of integer lists a and b .
    if not a or not b then 0
    else (car a)#*(car b) #+ mo!=sprod(cdr a,cdr b);

symbolic procedure mo!=deglist(a);
% a is an exponent list. Returns the degree list of a.
  if null a then
      for each x in ring_degrees cali!=basering collect 0
  else (mo!=sum(
      for each x in ring_degrees cali!=basering collect
                mo!=sprod(cdr a,x),
      if b then cddr b else nil)
      where b = assoc(car a,cali!=degrees));

symbolic procedure mo_neworder m;
% Deletes trailing zeroes and returns m with new degree part.
    (m1 . mo!=deglist m1) where m1 =mo!=shorten car m;

symbolic procedure mo_degneworder l;
% New degree parts in the degree list l.
  for each x in l collect car x . mo_neworder cdr x;

symbolic procedure mo!=shorten m;
    begin scalar m1;
    m1:=reverse m;
    while m1 and eqn(car m1,0) do m1:=cdr m1;
    return reversip m1;
    end;

% ------------- comparisions of monomials -----------------

symbolic procedure mo_zero;  nil . mo!=deglist nil;
% Returns the unit monomial x^0.

symbolic procedure mo_zero!? u; mo!=zero car u;

symbolic procedure mo!=zero u;
    null u or car u = 0 and mo!=zero cdr u;

symbolic procedure mo_equal!?(m1,m2);
% Test whether m1 = m2.
    equal(mo!=shorten car m1,mo!=shorten car m2);

symbolic procedure mo_divides!?(m1,m2);
% m1,m2:monomial. true :<=> m1 divides m2
    mo!=modiv1(car m1,car m2);

symbolic procedure mo!=modiv1(e1,e2);
    if not e1 then t else if not e2 then nil
    else leq(car e1,car e2) and mo!=modiv1(cdr e1, cdr e2);

symbolic procedure mo_compare(m1,m2);
% compare (m1,m2) . m1 < m2 => -1 | m1 = m2 => 0 | m1 > m2 => +1
   begin scalar a,x;
        x:=mo!=degcomp(cdr m1,cdr m2);
        if x eq 0 then
            x:=if equal(ring_tag cali!=basering,'revlex) then
                       mo!=revlexcomp(car m1, car m2)
               else mo!=lexcomp(car m1,car m2);
        return x;
   end;

symbolic procedure mo_dlexcomp(a,b); mo!=lexcomp(car a,car b)=1;
% Descending lexicographic order, first by mo_comp.

symbolic procedure mo!=degcomp(d1,d2);
    if null d1 then 0
    else if car d1 = car d2 then mo!=degcomp(cdr d1,cdr d2)
    else if car d1 #< car d2 then -1
    else 1;

symbolic procedure mo!=revlexcomp(e1,e2);
    if null e1 then
        if null e2 then 0 else mo!=revlexcomp('(0),e2)
    else if null e2 then mo!=revlexcomp(e1,'(0))
    else if car e1 = car e2 then mo!=revlexcomp(cdr e1,cdr e2)
    else if car e1 #< car e2 then 1
    else -1;


symbolic procedure mo!=lexcomp(e1,e2);
    if null e1 then
        if null e2 then 0 else mo!=lexcomp('(0),e2)
    else if null e2 then mo!=lexcomp(e1,'(0))
    else if car e1 = car e2 then mo!=lexcomp(cdr e1,cdr e2)
    else if car e1 #> car e2 then 1
    else -1;

% ---------- manipulation of the module component --------

symbolic procedure mo_comp v;
% Retuns the module component of v.
    if null car v then 0 else caar v;

symbolic procedure mo_from_ei i;
% Make e_i.
    if i=0 then mo_zero() else (x . mo!=deglist x) where x =list(i);

symbolic procedure mo_vdivides!?(v1,v2);
% Equal module component and v1 divides v2.
   eqn(mo_comp v1,mo_comp v2) and mo_divides!?(v1,v2);

symbolic procedure mo_deletecomp v;
% Delete component part.
   if null car v then v
   else if null cdar v then (nil . mo!=deglist nil)
   else ((x . mo!=deglist x) where x=cons(0,cdar v));

symbolic procedure mo_times_ei(i,m);
% Returns m * e_i or n*e_{i+k}, if m=n*e_k.
   (x . mo!=deglist x)
   where x=if null car m then list(i) else cons(i #+ caar m,cdar m);

symbolic procedure mo_degree m; cdr m;
% Returns the degree part of m.

symbolic procedure mo_getdegree(v,l);
% Compute the (virtual) degree of the monomial v with respect to the
% assoc. list l of column degrees.
  mo_deletecomp(if a then mo_sum(v,cdr a) else v)
  where a =assoc(mo_comp(v),l);

% --------------- monomial arithmetics -----------------------

symbolic procedure mo_lcm (m1,m2);
%  Monomial least common multiple.
    begin scalar x,e1,e2;
        e1:=car m1; e2:=car m2;
        while e1 and e2 do
            <<x := (if car e1 #> car e2 then car e1 else car e2) . x;
              e1 := cdr e1; e2 := cdr e2>>;
        x:=append(reversip x,if e1 then e1 else e2);
        return (mo!=shorten x) . (mo!=deglist x);
    end;

symbolic procedure mo_gcd (m1,m2);
%  Monomial greatest common divisor.
   begin scalar x,e1,e2;
      e1:=car m1; e2:=car m2;
      while e1 and e2 do
         <<x := (if car e1 #< car e2 then car e1 else car e2) . x;
           e1 := cdr e1; e2 := cdr e2>>;
      x:=reversip x; return (mo!=shorten x) . (mo!=deglist x);
   end;

symbolic procedure mo_neg v;
% Return v^-1.
  (for each x in car v collect -x).(for each x in cdr v collect -x);

symbolic procedure mo_sum(m1,m2);
%  Monomial product.
   ((mo!=shorten x) . (mo!=deglist x))
                        where x =mo!=sum(car m1,car m2);

symbolic procedure mo!=sum(e1,e2);
    begin scalar x;
      while e1 and e2 do
        <<x := (car e1 #+ car e2) . x; e1 := cdr e1; e2 := cdr e2>>;
      return append(reversip x,if e1 then e1 else e2);
 end;

symbolic procedure mo_diff (m1,m2); mo_sum(m1,mo_neg m2);

symbolic procedure mo_qrem(m,n);
% m,n monomials. Returns (q . r) with m=n^q*r.
    begin scalar m1,n1,q,q1;
    q:=-1; m1:=cdar m; n1:=cdar n;
    while m1 and n1 and (q neq 0) do
        << if car n1 > 0 then
            << q1:=car m1 / car n1;
               if (q=-1) or (q>q1) then q:=q1;
            >>;
           n1:=cdr n1; m1:=cdr m1;
        >>;
    if n1 or (q=-1) then q:=0;
    return q . mo_diff(m,mo_power(n,q));
    end;

symbolic procedure mo_power(mo,n);
% Monomial power mo^n.
   (for each x in car mo collect n #* x) .
                (for each x in cdr mo collect n #* x);

symbolic procedure mo!=pair(a,b);
  if null a or null b then nil
  else (car a . car b) . mo!=pair(cdr a,cdr b);

symbolic procedure mo_2list m;
% Returns a list (var name . exp) for the monomial m.
  begin scalar k; k:=car m;
  return
    mo!=pair(ring_names cali!=basering, if k then cdr k else nil);
  end;

symbolic procedure mo_varexp(var,m);
% Returns the exponent of var:var. name in the monomial m.
    if not member(var,ring_names cali!=basering) then
                        typerr(var,"variable name")
  else begin scalar c;
    c:=assoc(var,mo_2list m);
    return if c then cdr c else 0
    end;

symbolic procedure mo_inc(m,x,j);
% Return monomial m with power of var. x increased by j.
  begin scalar n,v;
  if not member(x,v:=ring_all_names cali!=basering) then
    typerr(x,"dpoly variable");
  m:=car m;
  while x neq car v do
    << if m then <<n:=car m . n; m:=cdr m>> else n:=0 . n;
       v:=cdr v;
    >>;
  if m then
    << n:=(car m #+ j).n; if m:=cdr m then n:=nconc(reverse m,n) >>
  else n:=j . n;
  while n and (car n = 0) do n:=cdr n;
  n:=reversip n;
  return n . mo!=deglist n
  end;

symbolic procedure mo_linear m;
% Test whether the monomial m is linear.
  (length u=1 and cdar u=1) where u=mo_2list m;

symbolic procedure mo_ecart m;
% Returns the ecart of the monomial m.
    if null car m then 0
    else mo!=sprod(cdar m,ring_ecart cali!=basering);

symbolic procedure mo_radical m;
% Returns the radical of the monomial m.
   (x . mo!=deglist x)
        where x = for each y in car m collect if y=0 then 0 else 1;

symbolic procedure mo_seed(m,s);
% Set var's outside the list s equal to one.
  begin scalar m1,i,x,v;
  if not subsetp(s,v:=ring_all_names cali!=basering) then
    typerr(s,"dpoly name's list");
  m1:=car m;
  while m1 and v do
    << x:=cons(if member(car v,s) then car m1 else 0,x);
       m1:=cdr m1; v:=cdr v
    >>;
  while x and eqn(car x,0) do x:=cdr x;
  x:=reversip x;
  return  x . mo!=deglist x;
  end;

symbolic procedure mo_convert m;
  ( x . mo!=deglist x ) where x =mo!=shorten list(0,mo_ecart m);

% ---------------- monomial interface ---------------

symbolic procedure mo_from_a u;
% Convert a kernel to a monomial.
   if not(u member ring_all_names cali!=basering) then
                typerr(u,"dpoly variable")
   else begin scalar x,y;
          y:=mo!=shorten
              for each x in ring_all_names cali!=basering collect
                            if x equal u then 1 else 0;
          return  y . mo!=deglist y;
        end;

symbolic procedure mo_2a e;
% Convert a monomial to part of algebraic prefix form of a dpoly.
   mo!=expvec2a1(car e,ring_all_names cali!=basering);

symbolic procedure mo!=expvec2a1(u,v);
    if null u then nil
    else if car u = 0 then mo!=expvec2a1(cdr u,cdr v)
    else if car u = 1 then car v . mo!=expvec2a1(cdr u,cdr v)
    else list('expt,car v,car u) . mo!=expvec2a1(cdr u,cdr v);


symbolic procedure mo_prin(e,v);
% Print monomial e in infix form. V is a boolean variable which is
% true if an element in a product has preceded this one
    mo!=dpevlpri1(car e,ring_all_names cali!=basering,v);

symbolic procedure mo!=dpevlpri1(e,u,v);
    if null e then nil
    else if car e = 0 then mo!=dpevlpri1(cdr e,cdr u,v)
    else <<if v then print_lf "*";
           print_lf car u;
           if car e #> 1 then <<print_lf "^"; print_lf car e>>;
           mo!=dpevlpri1(cdr e,cdr u,t)>>;

symbolic procedure mo_support m;
% Returns the support of the monomial m as a list of var. names
% in the correct order.
   begin scalar u;
   for each x in ring_names cali!=basering do
    if mo_divides!?(mo_from_a x,m) then u:=x . u;
   return reversip u;
   end;

endmodule;  % mo


module dpoly;

COMMENT

               ##################
               ##              ##
               ## POLYNOMIALS  ##
               ##              ##
               ##################

Polynomial vectors and polynomials are handled in a unique way using
the module component of monomials to store the vector component. If
the component is 0, we have a polynomial, otherwise a vector. They
are represented in a distributive form (dpoly for short).

Informal syntax of (vector) polynomials :

   <dpoly>   ::= list of <term>s
   <term>    ::= ( <monomial> . <base coefficient> )

END COMMENT;

% ----------- constructors and selectors -------------------

symbolic procedure dp_lc p;
% Leading base coefficient of the dpoly p.
   cdar p;

symbolic procedure dp_lmon p;
% Leading monomial of the dpoly p.
   caar p;

symbolic procedure dp_term (a,e);
%  Constitutes a term from a:base coeff. and e:monomial.
   (e . a);

symbolic procedure dp_from_ei n;
% Returns e_i as dpoly.
  list dp_term(bc_fi 1,mo_from_ei n);

symbolic procedure dp_fi n;
% dpoly from integer
   list dp_term(bc_fi n,mo_zero());

symbolic procedure dp_fbc c;
% Converts the base coefficient c into a dpoly.
   list dp_term(c,mo_zero());

% ------------  dpoly arithmetics ---------------------------

symbolic procedure dp!=comp(i,v);
   if null v then nil
   else if eqn(mo_comp dp_lmon v,i) then car v . dp!=comp(i,cdr v)
   else dp!=comp(i,cdr v);

symbolic procedure dp_comp(i,v);
% Returns the (polynomial) component i of the vector v.
   for each x in dp!=comp(i,v) collect (mo_deletecomp car x) . cdr x;

symbolic procedure dp!=mocompare (t1,t2);
% true <=> term t1 is smaller than term t2 in the current term order.
     eqn(mo_compare (car t1, car t2),1);

symbolic procedure dp_neworder p;
% Returns reordered dpoly p after change of the term order.
   sort(for each x in p collect (mo_neworder car x) . cdr x,
            function dp!=mocompare);

symbolic procedure dp_neg p;
% Returns - p  for the dpoly p.
   for each x in p collect (car x .  bc_neg cdr x);

symbolic procedure dp_times_mo (mo,p);
% Returns p * x^mo for the dpoly p and the monomial mo.
   for each x in p collect (mo_sum(mo,car x) .  cdr x);

symbolic procedure dp_times_bc (bc,p);
% Returns p * bc for the dpoly p and the base coeff. bc.
   for each x in p collect (car x .  bc_prod(bc,cdr x));

symbolic procedure dp_times_bcmo (bc,mo,p);
% Returns p * bc * x^mo for the dpoly p, the monomial mo and the base
% coeff. bc.
   for each x in p collect (mo_sum(mo,car x) .  bc_prod(bc,cdr x));

symbolic procedure dp_times_ei(i,p);
% Returns p * e_i for the dpoly p.
   dp_neworder for each x in p collect (mo_times_ei(i,car x) . cdr x);

symbolic procedure dp_project(p,k);
% Delete all terms x^a*e_i with i>k.
  for each x in p join if mo_comp car x <= k then {x};

symbolic procedure dp_content p;
% Returns the leading coefficient, if invertible, or the content of
% p.
  if null p then bc_fi 0
  else begin scalar w;
        w:=dp_lc p; p:=cdr p;
        while p and not bc_inv w do
         << w:=bc_gcd(w,dp_lc p); p:=cdr p >>;
        return w
        end;

symbolic procedure dp_mondelete(p,s);
% Returns (p.m) with common monomial factor m with support in the
% var. list s deleted.
   if null p or null s then (p . mo_zero()) else
   begin scalar cmf;
     cmf:=dp!=cmf(p,s);
     if mo_zero!? cmf then return (p . cmf)
     else return
       cons(for each x in p collect mo_diff(car x,cmf) . cdr x,cmf)
   end;

symbolic procedure dp!=cmf(p,s);
   begin scalar a;
        a:=mo_seed(dp_lmon p,s); p:=cdr p;
        while p and (not mo_zero!? a) do
                << a:=mo_gcd(a,mo_seed(dp_lmon p,s)); p:=cdr p >>;
        return a
   end;

symbolic procedure dp_unit!? p;
% Tests whether lt p of the dpoly p is a unit.
% This means : p is a unit, if the t.o. is noetherian
%       or   : p is a local unit, if the t.o. is a tangentcone order.
   p and (mo_zero!? dp_lmon p);

symbolic procedure dp_simp pol;
% Returns (pol_new . z) with
%       pol_new having leading coefficient 1 or
%       dp_content pol canceled out
% and pol_old = z * dpoly_new .

  if null pol then pol . bc_fi 1
  else begin scalar z,z1;
    if (z:=bc_inv (z1:=dp_lc pol)) then
        return dp_times_bc(z,pol) . z1;

    % -- now we assume that base coefficients are a gcd domain ----

    z:=dp_content pol;
    if bc_minus!? z1 then z:=bc_neg z;
    pol:=for each x in pol collect
                car x . car bc_divmod(cdr x,z);
    return pol . z;
    end;

symbolic procedure dp_prod(p1,p2);
% Returns p1 * p2 for the dpolys p1 and p2.
    if length p1 <= length p2 then dp!=prod(p1,p2)
                              else dp!=prod(p2,p1);

symbolic procedure dp!=prod(p1,p2);
  if null p1 or null p2 then nil
  else
     begin scalar v;
       for each x in p1 do
                v:=dp_sum( dp_times_bcmo(cdr x,car x, p2 ),v);
       return v;
     end;

symbolic procedure dp_sum(p1,p2);
% Returns p1 + p2 for the dpolys p1 and p2.
    if null p1 then p2
    else if null p2 then p1
    else begin scalar sl,al;
        sl := mo_compare(dp_lmon p1, dp_lmon p2);
        if sl = 1 then return car p1 . dp_sum(cdr p1, p2);
        if sl = -1 then return car p2 . dp_sum(p1, cdr p2);
        al := bc_sum(dp_lc p1, dp_lc p2);
        if bc_zero!? al then return dp_sum(cdr p1, cdr p2)
        else return dp_term(al,dp_lmon p1) . dp_sum(cdr p1, cdr p2)
        end;

symbolic procedure dp_diff(p1,p2);
% Returns p1 - p2 for the dpolys p1 and p2.
    dp_sum(p1, dp_neg p2);

symbolic procedure dp_power(p,n);
% Returns p^n for the dpoly p.
  if (not fixp n) or (n < 0) then typerr(n," exponent")
  else if n=0 then dp_fi 1
  else if n=1 then p
  else if null cdr p then dp!=power1(p,n)
  else dp!=power(p,n);

symbolic procedure dp!=power1(p,n); % For monomials.
  list dp_term(bc_power(dp_lc p,n),mo_power(dp_lmon p,n));

symbolic procedure dp!=power(p,n);
  if n=1 then p
  else if evenp n then dp!=power(dp_prod(p,p),n/2)
  else dp_prod(p,dp!=power(dp_prod(p,p),n/2));

symbolic procedure dp_tcpart p;
% Return the homogeneous degree part of p of highest degree.
  if null p then nil
  else begin scalar d,u; d:=car mo_degree caar p;
  while p and (d=car mo_degree caar p) do
     << u:=car p . u; p:=cdr p >>;
  return reversip u;
  end;

symbolic procedure dp_deletecomp p;
% delete the component part from all terms.
  dp_neworder for each x in p collect mo_deletecomp car x . cdr x;

% ------ Converting prefix forms into dpolys ------------------

symbolic procedure dp_from_a u;
% Converts the algebraic (prefix) form u into a dpoly.
   if atom u then dp!=a2dpatom u
   else if not atom car u or not idp car u
                then typerr(car u,"dpoly operator")
   else (if x='dp!=fnpow then dp!=fnpow(dp_from_a cadr u,caddr u)
      else if x then
            apply(x,list for each y in cdr u collect dp_from_a y)
      else dp!=a2dpatom u)
        where x = get(car u,'dp!=fn);

symbolic procedure dp!=a2dpatom u;
% Converts the atom (or kernel) u into a dpoly.
   if u=0 then nil
   else if numberp u or not member(u, ring_all_names cali!=basering)
                then list dp_term(bc_from_a u,mo_zero())
   else list dp_term(bc_fi 1,mo_from_a u);

symbolic procedure dp!=fnsum u;
% U is a list of dpoly expressions. The result is the dpoly
% representation for the sum. Analogously for the other symbolic
% procedures below.
   (<<for each y in cdr u do x := dp_sum(x,y); x>>) where x = car u;

put('plus,'dp!=fn,'dp!=fnsum);

put('plus2,'dp!=fn,'dp!=fnsum);

symbolic procedure dp!=fnprod u;
   (<<for each y in cdr u do x := dp_prod(x,y); x>>) where x = car u;

put('times,'dp!=fn,'dp!=fnprod);

put('times2,'dp!=fn,'dp!=fnprod);

symbolic procedure dp!=fndif u; dp_diff(car u, cadr u);

put('difference,'dp!=fn,'dp!=fndif);

symbolic procedure dp!=fnpow(u,n); dp_power(u,n);

put('expt,'dp!=fn,'dp!=fnpow);

symbolic procedure dp!=fnneg u;
   ( if null v then v else dp_term(bc_neg dp_lc v,dp_lmon v) . cdr v)
        where v = car u;

put('minus,'dp!=fn,'dp!=fnneg);

symbolic procedure dp!=fnquot u;
   if null cadr u or not null cdadr u
         or not mo_zero!? dp_lmon cadr u
      then typerr(dp_2a cadr u,"distributive polynomial denominator")
    else dp!=fnquot1(car u,dp_lc cadr u);

symbolic procedure dp!=fnquot1(u,v);
   if null u then u
    else dp_term(bc_quot(dp_lc u,v), dp_lmon u) .
            dp!=fnquot1(cdr u,v);

put('quotient,'dp!=fn,'dp!=fnquot);

% -------- Converting dpolys into prefix forms -------------
% ------ Authors: R. Gebauer, A. C. Hearn, H. Kredel -------

symbolic procedure dp_2a u;
% Returns the prefix equivalent of the dpoly u.
   if null u then 0 else dp!=replus dp!=2a u;

symbolic procedure dp!=2a u;
   if null u then nil
    else ((if bc_minus!? x then
                        list('minus,dp!=retimes(bc_2a bc_neg x . y))
           else dp!=retimes(bc_2a x . y))
          where x = dp_lc u, y = mo_2a dp_lmon u)
                 . dp!=2a cdr u;

symbolic procedure dp!=replus u;
   if atom u then u else if null cdr u then car u else 'plus . u;

symbolic procedure dp!=retimes u;
% U is a list of prefix expressions the first of which is a number.
% The result is the prefix representation for their product.
   if car u = 1 then if cdr u then dp!=retimes cdr u else 1
    else if null cdr u then car u
    else 'times . u;

% ----------- Printing routines for dpolys --------------
% ---- Authors: R. Gebauer, A. C. Hearn, H. Kredel ------

symbolic procedure dp_print u;
% Prints a distributive polynomial in infix form.
   << terpri();  dp_print1(u,nil); terpri(); terpri() >>;

symbolic procedure dp_print1(u,v);
% Prints a dpoly in infix form.
% U is a distributive form. V is a flag which is true if a term
% has preceded current form.
   if null u then if null v then print_lf 0 else nil
    else begin scalar bool,w;
       w := dp_lc u;
       if bc_minus!? w then <<bool := t; w := bc_neg w>>;
       if bool then print_lf " - " else if v then print_lf " + ";
       ( if not bc_one!? w or mo_zero!? x then
            << bc_prin w; mo_prin(x,t)>>
         else mo_prin(x,nil))
           where x = dp_lmon u;
       dp_print1(cdr u,t)
     end;

% -------------- Auxiliary dpoly operations -------------------

symbolic procedure dp_ecart p;
% Returns the ecart of the dpoly p.
   if null p then 0 else (dp!=ecart p) - (mo_ecart dp_lmon p);

symbolic procedure dp!=ecart p;
   if null p then 0
   else max2(mo_ecart dp_lmon p,dp!=ecart cdr p);

symbolic procedure dp_df(pol,var);
% Returns the derivative of the dpoly pol by the variable var.
  dp!=df(pol,var,mo_from_a var);

symbolic procedure dp!=df(f,var,mo);
  if null f then nil
  else begin scalar x;
     x:=mo_varexp(var,dp_lmon f);
     if x > 0 then return
        dp_sum(list dp_term(bc_prod(dp_lc f,bc_fi x),
                            mo_diff(dp_lmon f,mo)),
               dp!=df(cdr f,var,mo))
     else return dp!=df(cdr f,var,mo)
     end;

symbolic procedure dp_jac(f,l);
% Make the jacobian vector (df/dx_i) with respect to the variable
% list l.
   begin integer i; scalar w; i:=0;
   while l do
     << i:=i+1; w:=dp_sum(w,dp_times_ei(i,dp_df(f,car l)));
        l:=cdr l
     >>;
   return w;
   end;

symbolic procedure dp_homogenize(p,x);
% Homogenize (according to mo_ecart) the dpoly p using the variable x.
  if null p then p
  else begin integer maxdeg;
    maxdeg:=0;
    for each y in p do maxdeg:=max2(maxdeg,mo_ecart car y);
    return dp_compact dp_neworder for each y in p collect
                mo_inc(car y,x,maxdeg-mo_ecart car y) . cdr y;
    end;

symbolic procedure dp_seed(p,s);
% Returns the dpoly p with all vars outside the list s set equal to 1.
  if null p then p
  else dp_compact dp_neworder
                for each x in p collect mo_seed(car x,s).cdr x;

symbolic procedure dp_compact p;
% Collect equal terms in the sorted dpoly p.
  if null p then p else dp_sum(list car p,dp_compact cdr p);

symbolic procedure dp_convert pol;
% Create univariate polynomial.
 if null pol then nil
 else dp_sum(list dp_term(dp_lc pol,mo_convert dp_lmon pol),
        dp_convert cdr pol);

% -- dpoly operations based on computation with ideal bases.

symbolic procedure dp_pseudodivmod(g,f);
% Returns a dpoly list {q,r,z} such that z * g = q * f + r and
% z is a dpoly unit. Computes redpol({[f.e_1]},[g.0]).
% g, f and r must belong to the same free module.
   begin scalar u;
   f:=list bas_make1(1,f,dp_from_ei 1);
   g:=bas_make(0,g);
   u:=if !*noetherian then red_redpol(f,g) else mora_redpol(f,g);
   return {dp_neg dp_deletecomp bas_rep car u,bas_dpoly car u,cdr u};
   end;

symbolic procedure dpgcd!*(u,v);
% Compute the gcd of two polynomials by the syzygies' method :
% 0 = u*u1 + v*v1 => gcd = u/v1 = -v/u1 .
  if dp_unit!? u or dp_unit!? v then dp_fi 1
  else begin scalar g,w;
    w:=bas_dpoly first dpmat_list
        syzygies!* dpmat_make(2,0,{bas_make(1,u),bas_make(2,v)},nil);
    return car dp_pseudodivmod(u,dp_comp(2,w));
    end;

symbolic operator dpgcd;
symbolic procedure dpgcd(u,v);
  if !*mode='symbolic then rederr"only for algebraic mode"
  else dp_2a dpgcd!*(dp_from_a u,dp_from_a v);

endmodule; % dpoly


module bas;

COMMENT

              #######################
              ####               ####
              ####  IDEAL BASES  ####
              ####               ####
              #######################


Ideal bases are lists of vector polynomials (with additional
information), constituting the rows of a dpmat (see below).  In a
rep. part there can be stored vectors representing each base element
according to a fixed basis. Usually rep=nil.

Informal syntax :

 <bas>          ::= list of base elements
 <base element> ::= list(nr dpoly length ecart rep)

END COMMENT;


% -------- Reference operators for the base element b ---------

symbolic procedure bas_dpoly b; cadr b;
symbolic procedure bas_dplen b; caddr b;
symbolic procedure bas_nr b; car b;
symbolic procedure bas_dpecart b; cadddr b;
symbolic procedure bas_rep b; nth(b,5);

% ----- Elementary constructors for the base element be --------

symbolic procedure bas_newnumber(nr,be);
% Returns be with new number part.
   nr . cdr be;

symbolic procedure bas_make(nr,pol);
% Make base element with rep=nil.
   list(nr,pol, length pol,dp_ecart pol,nil);

symbolic procedure bas_make1(nr,pol,rep);
% Make base element with prescribed rep.
   list(nr,pol, length pol,dp_ecart pol,rep);

symbolic procedure bas_getelement(i,bas);
% Returns the base element with number i from bas (or nil).
  if null bas then list(i,nil,0,0,nil)
  else if eqn(i,bas_nr car bas) then car bas
  else bas_getelement(i,cdr bas);

% ---------- Operations on base lists ---------------

symbolic procedure bas_sort b;
% Sort the base list b.
  sort(b,function red_better);

symbolic procedure bas_print u;
% Prints a list of distributive polynomials using dp_print.
  begin terpri();
     if null u then print 'empty
     else for each v in u do
            << write bas_nr v, " -->  ";
               dp_print1(bas_dpoly v,nil); terpri();terpri() >>;
  end;

symbolic procedure bas_renumber u;
% Renumber base list u.
  if null u then nil
  else begin scalar i; i:=0;
      return for each x in u collect <<i:=i+1; bas_newnumber(i,x) >>
  end;

symbolic procedure bas_setrelations u;
% Set in the base list u the relation part rep of base element nr. i
% to e_i (provided i>0).
  for each x in u do
        if bas_nr x > 0 then rplaca(cddddr x, dp_from_ei bas_nr x);

symbolic procedure bas_removerelations u;
% Remove relation parts.
  for each x in u do rplaca(cddddr x, nil);

symbolic procedure bas_getrelations u;
% Returns the relations of the base list u as a separate base list.
  begin scalar w;
  for each x in u do w:=bas_make(bas_nr x,bas_rep x) . w;
  return reversip w;
  end;

symbolic procedure bas_from_a u;
% Converts the algebraic (prefix) form u to a base list clearing
% denominators. Only for lists.
   bas_renumber for each v in cdr u collect
        bas_make(0,dp_from_a prepf numr simp v);

symbolic procedure bas_2a u;
% Converts the base list u to its algebraic prefix form.
    append('(list),for each x in u collect dp_2a bas_dpoly x);

symbolic procedure bas_neworder u;
% Returns reordered base list u (e.g. after change of term order).
    for each x in u collect
        bas_make1(bas_nr x,dp_neworder bas_dpoly x,
                                dp_neworder bas_rep x);

symbolic procedure bas_zerodelete u;
% Returns base list u with zero elements deleted but not renumbered.
    if null u then nil
    else if null bas_dpoly car u then bas_zerodelete cdr u
    else car u.bas_zerodelete cdr u;

symbolic procedure bas_simpelement b;
% Returns (b_new . z) with
%       bas_dpoly b_new having leading coefficient 1 or
%       gcd(dp_content bas_poly,dp_content bas_rep) canceled out
% and dpoly_old = z * dpoly_new , rep_old= z * rep_new.

  if null bas_dpoly b then b . bc_fi 1
  else begin scalar z,z1,pol,rep;
    if (z:=bc_inv (z1:=dp_lc bas_dpoly b)) then
        return bas_make1(bas_nr b,
                dp_times_bc(z,bas_dpoly b),
                dp_times_bc(z,bas_rep b))
                        . z1;

    % -- now we assume that base coefficients are a gcd domain ----

    z:=bc_gcd(dp_content bas_dpoly b,dp_content bas_rep b);
    if bc_minus!? z1 then z:=bc_neg z;
    pol:=for each x in bas_dpoly b collect
                car x . car bc_divmod(cdr x,z);
    rep:=for each x in bas_rep b collect
                car x . car bc_divmod(cdr x,z);
    return bas_make1(bas_nr b,pol,rep) . z;
    end;

symbolic procedure bas_simp u;
% Applies bas_simpelement to each dpoly in the base list u.
   for each x in u collect car bas_simpelement x;

symbolic procedure bas_zero!? b;
% Test whether all base elements are zero.
   null b or (null bas_dpoly car b and bas_zero!? cdr b);

symbolic procedure bas_sieve(bas,vars);
% Sieve out all base elements from the base list bas with leading
% term containing a variable from the list of var. names vars and
% renumber the result.
   begin scalar u,m;  m:=mo_zero();
   for each x in vars do
       if member(x,ring_names cali!=basering) then
            m:=mo_sum(m,mo_from_a x)
       else typerr(x,"variable name");
   return bas_renumber for each x in bas_zerodelete bas join
        if mo_zero!? mo_gcd(m,dp_lmon bas_dpoly x) then {x};
   end;

symbolic procedure bas_homogenize(b,var);
% Homogenize the base list b using the var. name var.
  for each x in b collect
      bas_make1(bas_nr x,dp_homogenize(bas_dpoly x,var),
                dp_homogenize(bas_rep x,var));

symbolic procedure bas_dehomogenize(b,var);
% Set the var. name var in the base list b equal to one.
  begin scalar u,v;
  if not member(var,v:=ring_all_names cali!=basering) then
    typerr(var,"dpoly variable");
  u:=setdiff(v,list var);
  return for each x in b collect
                bas_make1(bas_nr x,dp_seed(bas_dpoly x,u),
                            dp_seed(bas_rep x,u));
  end;

endmodule;  % bas

module dpmat;

COMMENT

                 #####################
                 ###               ###
                 ###    MATRICES   ###
                 ###               ###
                 #####################

This module introduces special dpoly matrices with its own matrix
syntax.

Informal syntax :

 <matrix> ::= list('DPMAT,#rows,#cols,baslist,column_degrees)

Dpmat's are the central data structure exploited in the modules of
this package. Each such matrix describes a map

                   f : R^rows --> R^cols,

that gives rise for the definition of two modules,

                im f = the submodule of R^cols generated by the rows
                       of the matrix

        and  coker f = R^cols/im f.

Conceptually dpmat's are identified with im f.

END COMMENT;

% ------------- Reference operators ----------------

symbolic procedure dpmat_rows m; cadr m;
symbolic procedure dpmat_cols m; caddr m;
symbolic procedure dpmat_list m; cadddr m;
symbolic procedure dpmat_coldegs m; nth(m,5);

% ------------- Elementary operations --------------

symbolic procedure dpmat_rowdegrees m;
% Returns the row degrees of the dpmat m as an assoc. list.
  (for each x in dpmat_list m join
        if bas_nr x > 0 then
                {(bas_nr x).(mo_getdegree(dp_lmon bas_dpoly x,l))})
  where l=dpmat_coldegs m;

symbolic procedure dpmat_make(r,c,bas,degs);
  list('dpmat,r,c,bas,degs);

symbolic procedure dpmat_element(r,c,mmat);
% Returns mmat[r,c].
   dp_neworder
        dp_comp(c, bas_dpoly bas_getelement(r,dpmat_list mmat));

symbolic procedure dpmat_print m; mathprint dpmat_2a m;

symbolic procedure getleadterms!* m;
% Returns the dpmat with the leading terms of m.
  (begin scalar b;
  b:=for each x in dpmat_list m collect
    bas_make(bas_nr x,list(car bas_dpoly x));
  return dpmat_make(dpmat_rows m,dpmat_cols m,b,cali!=degrees);
  end) where cali!=degrees:=dpmat_coldegs m;

% -------- Symbolic mode file transfer --------------

symbolic procedure savemat!*(m,name);
% Save the dpmat m under the name <name>.
  begin scalar nat,c;
  if not (stringp name or idp name) then typerr(name,"file name");
  if not eqcar(m,'dpmat) then typerr(m,"dpmat");
  nat:=!*nat; !*nat:=nil;
  write"Saving as ",name;
  out name$
  write"algebraic(setring "$

  % mathprint prints lists without terminator, but matrices with
  % terminator.

  mathprint ring_2a cali!=basering$ write")$"$
  write"algebraic(<<basis :="$ dpmat_print m$
  if dpmat_cols m=0 then write"$"$ write">>)$"$
  if (c:=dpmat_coldegs m) then
    << write"algebraic(degrees:="$
    mathprint moid_2a for each x in c collect cdr x$ write")$"$
    >>;
  write"end$"$ terpri()$
  shut name; terpri(); !*nat:=nat;
  end;

symbolic procedure initmat!* name;
% Initialize a dpmat from <name>.
  if not (stringp name or idp name) then typerr(name,"file name")
  else begin scalar m,c,d; integer i;
     write"Initializing ",name; terpri();
     in name$ m:=reval 'basis; cali!=degrees:=nil;
     if eqcar(m,'list) then
        << m:=bas_from_a m; m:=dpmat_make(length m,0,m,nil)>>
     else if eqcar(m,'mat) then
        << c:=moid_from_a reval 'degrees; i:=0;
           cali!=degrees:=for each x in c collect <<i:=i+1; i . x >>;
           m:=dpmat_from_a m;
        >>
     else typerr(m,"basis or matrix");
     dpmat_print m;
     return m;
     end;

% ---- Algebraic mode file transfer ---------

symbolic operator savemat;
symbolic procedure savemat(m,name);
  if !*mode='symbolic then rederr"only for algebraic mode"
  else savemat!*(dpmat_from_a m,name);

symbolic operator initmat;
symbolic procedure initmat name;
  if !*mode='symbolic then rederr"only for algebraic mode"
  else dpmat_2a initmat!* name;

% --------------- Arithmetics for dpmat's ----------------------

symbolic procedure dpmat!=dpsubst(a,b);
% Substitute in the dpoly a each e_i by b_i from the base list b.
   begin scalar v;
   for each x in b do
        v:=dp_sum(v,dp_prod(dp_comp(bas_nr x,a),bas_dpoly x));
   return v;
   end;

symbolic procedure dpmat_mult(a,b);
% Returns a * b.
  if not eqn(dpmat_cols a,dpmat_rows b) then
        rerror('dpmat,1," matrices don't match for MATMULT")
  else dpmat_make( dpmat_rows a, dpmat_cols b,
        for each x in dpmat_list a collect
                bas_make(bas_nr x,
                        dpmat!=dpsubst(bas_dpoly x,dpmat_list b)),
        cali!=degrees)
        where cali!=degrees:=dpmat_coldegs b;

symbolic procedure dpmat_times_dpoly(f,m);
% Returns f * m for the dpoly f and the dpmat m.
   dpmat_make(dpmat_rows m,dpmat_cols m,
        for each x in dpmat_list m collect
            bas_make1(bas_nr x, dp_prod(f,bas_dpoly x),
                        dp_prod(f,bas_rep x)),
        cali!=degrees) where cali!=degrees:=dpmat_coldegs m;

symbolic procedure dpmat_neg a;
% Returns - a.
   dpmat_make(
        dpmat_rows a,
        dpmat_cols a,
        for each x in dpmat_list a collect
            bas_make1(bas_nr x,dp_neg bas_dpoly x, dp_neg bas_rep x),
        cali!=degrees) where cali!=degrees:=dpmat_coldegs a;

symbolic procedure dpmat_diff(a,b);
% Returns a - b.
  dpmat_sum(a,dpmat_neg b);

symbolic procedure dpmat_sum(a,b);
% Returns a + b.
  if not (eqn(dpmat_rows a,dpmat_rows b)
                and eqn(dpmat_cols a, dpmat_cols b)
                and equal(dpmat_coldegs a,dpmat_coldegs b)) then
        rerror('dpmat,2,"matrices don't match for MATSUM")
  else (begin scalar u,v,w;
        u:=dpmat_list a; v:=dpmat_list b;
        w:=for i:=1:dpmat_rows a collect
            (bas_make1(i,dp_sum(bas_dpoly x,bas_dpoly y),
                            dp_sum(bas_rep x,bas_rep y))
                        where y= bas_getelement(i,v),
                              x= bas_getelement(i,u));
        return dpmat_make(dpmat_rows a,dpmat_cols a,w,cali!=degrees);
        end) where cali!=degrees:=dpmat_coldegs a;

symbolic procedure dpmat_from_dpoly p;
    dpmat_make(1,0,list bas_make(1,p),nil);

symbolic procedure dpmat_unit(n,degs);
% Returns the unit dpmat of size n.
  dpmat_make(n,n, for i:=1:n collect bas_make(i,dp_from_ei i),degs);

symbolic procedure dpmat_transpose m;
% Returns transposed m with consistent column degrees.
  if (dpmat_cols m = 0) then dpmat!=transpose ideal2mat!* m
  else dpmat!=transpose m;

symbolic procedure dpmat!=transpose m;
  (begin scalar b,p,q;
     cali!=degrees:=
        for each x in dpmat_rowdegrees m collect
                (car x).(mo_neg cdr x);
     for i:=1:dpmat_cols m do
       << p:=nil;
          for j:=1:dpmat_rows m do
            << q:=dpmat_element(j,i,m);
               if q then p:=dp_sum(p,dp_times_ei(j,q))
            >>;
          if p then b:=bas_make(i,p) . b;
       >>;
   return dpmat_make(dpmat_cols m,dpmat_rows m,reverse b,
                    cali!=degrees);
   end) where cali!=degrees:=cali!=degrees;

symbolic procedure ideal2mat!* u;
% Returns u as column vector if dpmat_cols u = 0.
  if dpmat_cols u neq 0 then
            rerror('dpmat,4,"IDEAL2MAT only for ideal bases")
  else dpmat_make(dpmat_rows u,1,
                 for each x in dpmat_list u collect
                   bas_make(bas_nr x,dp_times_ei(1,bas_dpoly x)),
                nil) where cali!=degrees:=nil;

symbolic procedure dpmat_renumber old;
% Renumber dpmat_list old.
% Returns (new . change) with new = change * old.
  if null dpmat_list old then (old . dpmat_unit(dpmat_rows old,nil))
  else (begin scalar i,u,v,w;
      cali!=degrees:=dpmat_rowdegrees old;
      i:=0; u:=dpmat_list old;
      while u do
        <<i:=i+1; v:=bas_newnumber(i,car u) . v;
        w:=bas_make(i,dp_from_ei bas_nr car u) . w  ; u:=cdr u>>;
      return dpmat_make(i,dpmat_cols old,
                        reverse v,dpmat_coldegs old) .
             dpmat_make(i,dpmat_rows old,reverse w,cali!=degrees);
      end) where cali!=degrees:=cali!=degrees;

symbolic procedure mathomogenize!*(m,var);
% Returns m with homogenized rows using the var. name var.
  dpmat_make(dpmat_rows m, dpmat_cols m,
        bas_homogenize(dpmat_list m,var), cali!=degrees)
  where cali!=degrees:=dpmat_coldegs m;

symbolic operator mathomogenize;
symbolic procedure mathomogenize(m,v);
% Returns the homogenized matrix of m with respect to the variable v.
  if !*mode='symbolic then rederr"only for algebraic mode"
  else dpmat_2a mathomogenize!*(dpmat_from_a reval m,v);

symbolic procedure matdehomogenize!*(m,var);
% Returns m with var. name var set equal to one.
  dpmat_make(dpmat_rows m, dpmat_cols m,
        bas_dehomogenize(dpmat_list m,var), cali!=degrees)
  where cali!=degrees:=dpmat_coldegs m;

symbolic procedure dpmat_sieve(m,vars);
% Apply bas_sieve to dpmat_list m.
  dpmat_make(length x,dpmat_cols m,x,cali!=degrees)
        where x=bas_sieve(dpmat_list m,vars)
  where cali!=degrees:=dpmat_coldegs m;

symbolic procedure dpmat_neworder m;
% Apply bas_neworder to dpmat_list m with current cali!=degrees.
   dpmat_make(dpmat_rows m,dpmat_cols m,
        bas_neworder dpmat_list m,cali!=degrees);

symbolic procedure dpmat_zero!? m;
% Test whether m is a zero dpmat.
   bas_zero!? dpmat_list m;

procedure dpmat_project(m,k);
% Project the dpmat m onto its first k components.
  dpmat_make(dpmat_rows m,k,
        for each x in dpmat_list m collect
                bas_make(bas_nr x,dp_project(bas_dpoly x,k)),
        dpmat_coldegs m);

% ---------- Interface to algebraic mode

symbolic procedure dpmat_2a m;
% Convert the dpmat m to a matrix (c>0) or a polynomial list (c=0) in
% algebraic (pseudo)prefix form.
  if dpmat_cols m=0 then bas_2a dpmat_list m
  else   'mat .
        if dpmat_rows m=0 then list for j:=1:dpmat_cols m collect 0
        else  for i:=1:dpmat_rows m collect
                for j:=1:dpmat_cols m collect
                    dp_2a dpmat_element(i,j,m);

symbolic procedure dpmat_from_a m;
% Convert an algebraic polynomial list or matrix expression into a
% dpmat with respect to the current setting of cali!=degrees.
  if eqcar(m,'mat) then
    begin integer i; scalar u,p; m:=cdr m;
    for each x in m do
      << i:=1; p:=nil;
         for each y in x do
           << p:=dp_sum(p,dp_times_ei(i,dp_from_a reval y)); i:=i+1 >>;
         u:=bas_make(0,p).u
      >>;
    return dpmat_make(length m,length car m,
                bas_renumber reversip u, cali!=degrees);
    end
  else if eqcar(m,'list) then
    ((begin scalar x;  x:=bas_from_a reval m;
    return dpmat_make(length x,0,x,nil)
    end) where cali!=degrees:=nil)
  else typerr(m,"polynomial list or matrix");

% ---- Substitution in dpmats --------------

symbolic procedure dpmat_sub(a,m);
% a=list of (var . alg. prefix form) to be substituted into the dpmat
% m.
   dpmat_from_a subeval1(a,dpmat_2a m)
  where cali!=degrees:=dpmat_coldegs m;

% ------------- Determinant ------------------------

symbolic procedure dpmat_det m;
% Returns the determinant of the dpmat m.
  if dpmat_rows m neq dpmat_cols m then rederr "non-square matrix"
  else dp_from_a prepf numr detq matsm dpmat_2a m;

endmodule; % dpmat

module red;

COMMENT

                    #################
                    ##             ##
                    ## NORMAL FORM ##
                    ## ALGORITHMS  ##
                    ##             ##
                    #################

This module contains normal form algorithms for base elements. All
reductions executed on the dpoly part, are repeated on the rep part,
hence tracing them up for further use. In several places they are
managed as
        <model>::=(dpoly part).(rep part).

The output trace intensity can be managed with the global parameter
cali!=trace that has the following meaning :

       cali!=trace >=   0      no trace
                       10      '.' for each substitution
                       70      trace interreduce!*
                       80      trace redpol
                       90      show substituents

The reduction strategy is first matching in the simplifier (base)
list. It can be changed overloading red_better, the relation
according to what base lists are sorted. Standard is minimal ecart,
breaking ties with minimal length (since such a strategy is good for
both the classical and the local case).

The module "mora" contains additional and special procedures for the
local case. The local case can be activated by "off noetherian".

Switches :

          red_total :   t      compute total normal forms
                        nil    reduce only until lt is standard
          bcsimp    :   t      apply bas_simp

          binomial  :   t      Allow multireduction. Only for
                                binomial ideals without
                                representation part.

END COMMENT;

% Standard is :

!*red_total:=t;
!*bcsimp:=t;
!*binomial:=nil;

symbolic procedure red_better(a,b);
% Base list sort criterion. Simplifier lists are sorted such that the
% best substituent comes first.
  if bas_dpecart a < bas_dpecart b then t
  else if bas_dpecart a > bas_dpecart b then nil
  else bas_dplen a < bas_dplen b;

symbolic procedure red_subst(model,basel);
%  model and basel = base elements
%  Returns (model1 . z) with model1 a base element
%                       and  base coeff. z
%  such that
%
%  pol_new := z * pol_old - z1 * mo * f_a
%  rep_new := z * rep_old - z1 * mo * rep_a
%
% with appropriate base coeff. z and z1 and monomial mo.

   if !*binomial then red!=subst2(model,basel)
   else red!=subst1(model,basel);

symbolic procedure red!=subst1(model,basel);
    begin scalar polold,polnew,repold,repnew,gcd,mo,fa,z,z1;
        polold:=bas_dpoly model; z1:=dp_lc polold;
        repold:=bas_rep model;
        fa:=bas_dpoly basel; z:= dp_lc fa;
        if !*bcsimp then      % modify z and z1
          if (gcd:=bc_inv z) then
            << z1:=bc_prod(z1,gcd); z:=bc_fi 1 >>
          else
            << gcd:=bc_gcd(z,z1);
               z:=car bc_divmod(z,gcd);
               z1:=car bc_divmod(z1,gcd)
            >>;
        mo:=mo_diff(dp_lmon polold,dp_lmon fa);
        polnew:=dp_diff(dp_times_bc(z,polold),
                                dp_times_bcmo(z1,mo,fa));
        repnew:=dp_diff(dp_times_bc(z,repold),
                                dp_times_bcmo(z1,mo,bas_rep basel));
        if cali!=trace > 79 then
                << prin2 "---> "; dp_print polnew >>
        else if cali!=trace > 0 then prin2 ".";
        if cali!=trace > 89 then
                << prin2 " uses "; dp_print fa >>;
        return bas_make1(bas_nr model,polnew,repnew) . z;
    end;

symbolic procedure red!=subst2(model,basel);
% Only for binomials without representation parts.
    begin scalar m,b,u,r;
    if cali!=trace>0 then prin2 ".";
    m:=bas_dpoly model; b:=bas_dpoly basel;
    if (length b neq 2) or bas_rep model then
            rederr"switch off binomial";
    u:=mo_qrem(dp_lmon m,dp_lmon b);
    r:=list dp_term(dp_lc m,
                mo_sum(mo_power(dp_lmon cdr b,car u),cdr u));
    return bas_make(bas_nr model,dp_sum(r,cdr m)) . bc_fi 1;
    end;

symbolic procedure red_redpol(bas,model);
% Takes model = a base element and bas = a base list.
% Returns (model1 . z) with model1 a base element (nr,pol1,rep1) and
%       pol1 = z * pol + \sum c_a f_a
%       rep1 = z * rep + \sum c_a rep_a.
% No extra simplification is done since otherwise z should be
% divided. z is a polynomial unit, i.e. of degree 0.

  if (null bas_dpoly model) or (null bas) then model . dp_fi 1
  else begin
     scalar z,v,pol1,rep1,pol,rep,z1,q;
     z:=bc_fi 1;
     if cali!=trace>79 then
       << write" reduce "; dp_print bas_dpoly model >>;
     while (q:=bas_dpoly model) and (v:=red_divtest(bas,dp_lmon q)) do
       << v:=red_subst(model,v); model:=car v;
          z:=bc_prod(z,cdr v)
       >>;
                % Now we've got a model with standard leading term.
     if !*red_total and bas_dpoly model
            and (v:=cdr bas_dpoly model) then

    %        If pol = q + rem                    and
    %    (z*q+)rem1 = z*(q+)rem + \sum e_a*f_a   then
    %       rep1    = z*rep + \sum e_a*rep_a
    % is the correct representation of z*q+rem1.

       << pol:=bas_dpoly model;         % Uses only lt:=lt(pol) below
          v:=bas_make1(bas_nr model,v,bas_rep model);
                                        % v = cdr pol
          v:=red_redpol(bas,v);         % is now (model1 . z1)
          z1:=cdr v; z:=bc_prod(z,dp_lc z1);
          pol1:=bas_dpoly car v; rep:=bas_rep car v;
          pol:=dp_term(bc_prod(dp_lc z1,dp_lc pol), dp_lmon pol)
                          . pol1;  % pol := z1 * lt + pol1
          model:=bas_make1(bas_nr model,pol,rep);
       >>;
     return model . dp_fbc z;
     end;

% ----- Interface to symbolic mode computations with dpmat's --

symbolic procedure red!=sort(a,b);
% This term order must refine the division order.
  eqn(mo_compare(dp_lmon bas_dpoly a,dp_lmon bas_dpoly b),1);

symbolic procedure red_straight bas;
% Autoreduce straightening formulae of the base list bas. Applicable
% only to noetherian term orders.
  begin scalar u;
  u:=red!=redstraight1 sort(bas,function red!=sort);
  if !*bcsimp then u:=bas_simp u;
  return sort(u,function red_better);
  end;

symbolic procedure red!=redstraight1 bas;
  if null bas then nil
  else (car red_redpol(cdr bas,car bas)) . red!=redstraight1 cdr bas;

symbolic procedure red_divtest(a,b);
% Returns the first f in the base list a, such that lt(f) | b else nil.
% b is a monomial.
  if null a then nil
  else if mo_vdivides!?(dp_lmon bas_dpoly car a,b) then car a
  else red_divtest(cdr a,b);

symbolic procedure red_collect bas;
% Returns ( bas1 . bas2 ), where bas2 may be reduced with bas1.
    begin scalar bas1,bas2;
    bas1:=listminimize(bas,function (lambda(x,y);
         mo_vdivides!?(dp_lmon bas_dpoly x,dp_lmon bas_dpoly y)));
    bas2:=setdiff(bas,bas1);
    return bas1 . bas2;
    end;

symbolic procedure red_interreduce m;
% Reduce rows of the base list m until it has pairwise incomparable
% leading terms. If red_total is on then do also autoreduction.
% Compute correct representation parts.

    begin scalar c,w,bas1,pol,rep;
    m:=bas_sort bas_zerodelete m;
    if !*bcsimp then m:=bas_simp m;
    while cdr (c:=red_collect m) do
      << if cali!=trace>69 then
                <<write" interreduce ";terpri();bas_print m>>;
         m:=nil; w:=cdr c; bas1:=car c;
         while w do
           << c:=car red_redpol(bas1,car w);
              if bas_dpoly c then m:=c . m;
              w:=cdr w
            >>;
         if !*bcsimp then m:=bas_simp m;
         m:=merge(bas1,bas_sort m,function red_better);
      >>;
    if !*red_total then m:=red_straight m;
    return m;
    end;

endmodule;  % red


module groeb;

COMMENT

              ##############################
              ##                          ##
              ##      GROEBNER PACKAGE    ##
              ##                          ##
              ##############################


The trace intensity can be managed with cali!=trace by the following
rules :

      cali!=trace >=    0      no trace
                        2      show actual step
                       10      show input and output
                       20      show new base elements
                       30      show pairs
                       40      show actual pairlist
                       50      show S-polynomials

Pair lists have the following informal syntax :

      <spairlist>::= list of spairs
      < spair >  ::= (komp  groeb!=weight  lcm  p_i  p_j)
               with lcm = lcm(lt(bas_dpoly p_i),lt(bas_dpoly p_j)).


The pair selection strategy is by first matching in the pair list.
It can be changed overloading groeb!=better, the relation according to
what pair lists are sorted. Standard is the sugar strategy.

cali!=monset :

One can manage a list of variables, that are allowed to be canceled
out, if they appear as common factors in a dpoly. This is possible if
these variables are non zero divisors (e.g. for prime ideals) and
affects "pure" Groebner basis computation only.


END COMMENT;

% ---------- Global variables ------------------------------

%  Standard :

symbolic procedure groeb_stbasis(bas,comp_mgb,comp_ch,comp_syz);
% Returns { mgb , change , syz } with
%       dpmat mgb = (if comp_mgb=true the minimal)
%               Groebner basis of the dpmat bas.
%       dpmat change defined by   mgb = change * bas
%               if comp_ch = true.
%       dpmat syz = (not interreduced) syzygy matrix of the dpmat bas
%               if comp_syz = true.

   if dpmat_zero!? bas then
       {bas,dpmat_unit(dpmat_rows bas,nil),
            dpmat_unit(dpmat_rows bas,nil)}
   else (begin scalar u,syz,change,syz1,mon_set;
   if comp_ch or comp_syz then mon_set:=nil else mon_set:=cali!=monset;
   if comp_syz then % syzygies for zero base elements.
   << u:=setdiff(for i:=1:dpmat_rows bas collect i,
                for each x in dpmat_list bas collect bas_nr x);
      syz1:=for each x in u collect bas_make(0,dp_from_ei x);
   >>;
   u:=groeb_innerstbasis(bas,comp_ch,comp_syz,mon_set); syz:=cadr u;
   if comp_mgb then
        << u:=groeb_mingb car u;
           if !*red_total then
                u:=dpmat_make(dpmat_rows u,dpmat_cols u,
                            red_straight dpmat_list u,
                            cali!=degrees);
        >>
   else u:=car u;
   cali!=degrees:=dpmat_rowdegrees bas;
   if comp_ch then
       change:=dpmat_make(dpmat_rows u,dpmat_rows bas,
                bas_neworder bas_getrelations dpmat_list u,
                cali!=degrees);
   bas_removerelations dpmat_list u;
   if comp_syz then
   << syz:=nconc(syz,syz1);
      syz:= dpmat_make(length syz,dpmat_rows bas,
                bas_neworder bas_renumber syz,cali!=degrees);
   >>;
   cali!=degrees:=dpmat_coldegs u;
   return {u,change,syz}
   end) where cali!=degrees:=dpmat_coldegs bas;

symbolic procedure groeb_innerstbasis(bas,comp_ch,comp_syz,mon_set1);
% Returns ( gb . syz . trace ) with change on the relations part of
% gb, where
%       dpmat gb is the Groebner basis
%       base list syz is the dpmat_list of the syzygy matrix of bas
%       spairlist trace is the Groebner trace.
  begin integer i;
    scalar u,q,gb,syz,p,pl,pol,rep,trace,nr, return_by_unit, Ccrit;

    % -------- Initialization

    gb:=bas_sort dpmat_list bas;
    if comp_ch or comp_syz then bas_setrelations gb;
    Ccrit:=(not comp_syz) and (dpmat_cols bas<2);
                                    % -- don't reduce main syzygies
    nr:=dpmat_rows bas; % the number of the last base element inserted
    if cali!=trace > 0 then
        <<terpri(); write" Computing Groebner basis  ";terpri()>>;
    if cali!=trace > 5 then
        << terpri(); write" Compute Groebner basis of"; bas_print gb >>;
    pl:=groeb_makepairlist(gb,Ccrit);
    if cali!=trace > 30 then groeb_printpairlist pl;
    if cali!=trace > 5 then
        <<terpri(); write" New base elements :";terpri() >>;

    % -------- working out pair list

    while pl and not return_by_unit do
      << % ------- Choose a pair

         p:=car pl; pl:=cdr pl;

         % ------ compute S-polynomial (which is a modelement)

         if cali!=trace > 10 then groeb_printpair(p,pl);
         pol:=groeb_spol p;
         if cali!=trace > 70 then
           << terpri(); write" S.-pol : ";
              dp_print1(bas_dpoly pol,nil)
           >>;

         pol:=car red_redpol(gb,pol);

         if cali!=trace > 70 then
           << terpri(); write" Reduced S.-pol. : ";
              dp_print1(bas_dpoly pol,nil)
           >>;

         if !*bcsimp then pol:=car bas_simpelement pol;

         if bas_dpoly pol then

              % --- the S-polynomial doesn't reduce to zero

           << nr:=nr+1;
              pol:=bas_newnumber(nr,pol);
              if mon_set1 then
                    pol:=bas_make(nr,
                        car dp_mondelete(bas_dpoly pol,mon_set1));

                   % --- update the tracelist

              q:=bas_dpoly pol;
              trace:=list(groeb!=i p,groeb!=j p,nr,dp_lmon q) . trace;

              if cali!=trace > 20 then
                << terpri(); write nr,". ---> ";
                   dp_print1(q,nil); terpri()
                >>;
              if Ccrit and (dp_unit!? q) then return_by_unit:=t;

                   % ----- updating pairlist
              if not return_by_unit then
                << pl:=groeb_updatePL(pl,gb,pol,Ccrit);
                   if cali!=trace > 30 then
                     << terpri(); groeb_printpairlist pl >>;
                >>;
              gb:=merge(list pol,gb,function red_better);
                                                % --- updating gb
           >>

         else % ------ S-polynomial reduces to zero
            if comp_syz then
                syz:=car bas_simpelement(bas_make(0,bas_rep pol)) . syz
      >>;

    % --------  updating the result

    if return_by_unit then return
        % --- no syzygies are to be computed
        dpmat_make(1,dpmat_cols bas,list(bas_newnumber(nr,pol)),
                cali!=degrees) . nil . reversip trace;
    gb:=dpmat_make(length gb,dpmat_cols bas,gb,cali!=degrees);
    return gb . syz . reversip trace
    end;

% ---------- Critical pair criteria -----------------------

symbolic procedure groeb!=critA(p);
    if null p then nil
    else reversip groeb!=critA1(nil,p);

symbolic procedure groeb!=critA1(b,a);
  if null a then b
  else if groeb!=testA1(b,car a) or groeb!=testA2(cdr a,car a) then
            groeb!=critA1(b,cdr a)
  else groeb!=critA1(car a . b,cdr a);

symbolic procedure groeb!=testA1(u,b);
% Test, whether komp(a)=komp(b) and lcm(a) | lcm(b) for some a in u.
  if null u then nil
  else ((caar u=car b) and mo_divides!?(nth(car u,3),nth(b,3)))
  or groeb!=testA1(cdr u,b);

symbolic procedure groeb!=testA2(u,b);
% Test, whether komp(b)=komp(a) and lcm(a) |<> lcm(b) for some a in u.
  if null u then nil
  else ((caar u=car b) and mo_divides!?(nth(car u,3),nth(b,3))
            and not mo_equal!?(nth(car u,3),nth(b,3)))
  or groeb!=testA2(cdr u,b);

symbolic procedure groeb!=critB(e,p);
% Delete pairs from p, for which testB is false.
  for each x in p join if not groeb!=testB(e,x) then {x};

symbolic procedure groeb!=testB(e,a);
% e=lt(f_k). Test, whether for a=pair (i j)
% komp(a)=komp(e) and Syz(i,j,k)=[ 1 * * ].
    (mo_comp e=car a)
    and mo_divides!?(e,nth(a,3))
    and (not mo_equal!?(mo_lcm(dp_lmon bas_dpoly nth(a,5),e),
                        nth(a,3)))
    and (not mo_equal!?(mo_lcm(dp_lmon bas_dpoly nth(a,4),e),
                        nth(a,3)));

symbolic procedure groeb!=critC(p);
% Delete main syzygies.
  for each x in p join if not groeb!=testC1 x then {x};

symbolic procedure groeb!=testC1 el;
    mo_equal!?(
        mo_sum(dp_lmon bas_dpoly nth(el,5),
               dp_lmon bas_dpoly nth(el,4)),
        nth(el,3));

symbolic procedure groeb_updatePL(p,gb,be,Ccrit);
% Update the pairlist p with the new base element be and the old ones
% in the base list gb. Discard pairs where both base elements have
% number part 0.
    begin scalar p1,k,a,n; n:=(bas_nr be neq 0);
    a:=dp_lmon bas_dpoly be; k:=mo_comp a;
    for each b in gb do
        if (k=mo_comp dp_lmon bas_dpoly b)
                and(n or (bas_nr b neq 0)) then
                        p1:=groeb!=newpair(k,b,be).p1;
    p1:=groeb!=critA(sort(p1,function groeb!=better));
    if Ccrit then p1:=groeb!=critC p1;
    return
        merge(p1,
              groeb!=critB(a,p), function groeb!=better);
    end;

symbolic procedure groeb_makepairlist(gb,Ccrit);
    begin scalar newgb,p;
    while gb do
        << p:=groeb_updatePL(p,newgb,car gb,Ccrit);
           newgb:=car gb . newgb;
           gb:=cdr gb
        >>;
    return p;
    end;

% -------------- S-pair list constructions --------------------

symbolic procedure groeb!=i p; bas_nr nth(p,4);

symbolic procedure groeb!=j p; bas_nr nth(p,5);

symbolic procedure groeb!=better(a,b);
% True if the Spair a is better than the Spair b.
    if (cadr a < cadr b) then t
    else if (cadr a = cadr b) then mo_compare(nth(a,3),nth(b,3))<=0
    else nil;

symbolic procedure groeb!=weight(lcm,p1,p2);
    mo_ecart(lcm) + min2(bas_dpecart p1,bas_dpecart p2);

symbolic procedure groeb!=newpair(k,p1,p2);
% Make an spair from base elements with common component number k.
    list(k,groeb!=weight(lcm,p1,p2),lcm, p1,p2)
        where lcm =mo_lcm(dp_lmon bas_dpoly p1,dp_lmon bas_dpoly p2);

symbolic procedure groeb_printpairlist p;
    begin
    for each x in p do
        << write groeb!=i x,".",groeb!=j x; print_lf  " | " >>;
    terpri();
    end;

symbolic procedure groeb_printpair(pp,p);
    begin terpri();
    write"Investigate (",groeb!=i pp,".",groeb!=j pp,")  ",
        "Pair list has length ",length p; terpri()
    end;

% ------------- S-polynomial constructions -----------------

symbolic procedure groeb_spol pp;
% Make an S-polynomial from the spair pp, i.e. return
% a base element with
%   dpoly = ( zi*mi*(red) pi - zj*mj*(red) pj )
%    rep  = (zi*mi*rep_i - zj*mj*rep_j),
%
%       where mi=lcm/lm(pi), mj=lcm/lm(pj)
%       and  zi and zj are appropriate scalars.
%
    begin scalar pi,pj,ri,rj,zi,zj,lcm,mi,mj,a,b;
      a:=nth(pp,4); b:=nth(pp,5); lcm:=nth(pp,3);
      pi:=bas_dpoly a; pj:=bas_dpoly b; ri:=bas_rep a; rj:=bas_rep b;
      mi:=mo_diff(lcm,dp_lmon pi); mj:=mo_diff(lcm,dp_lmon pj);
      zi:=dp_lc pj; zj:=bc_neg dp_lc pi;
      a:=dp_sum(dp_times_bcmo(zi,mi, cdr pi),
                dp_times_bcmo(zj,mj, cdr pj));
      b:=dp_sum(dp_times_bcmo(zi,mi, ri),
                dp_times_bcmo(zj,mj, rj));
      a:=bas_make1(0,a,b);
      return if !*bcsimp then car bas_simpelement a else a;
    end;

symbolic procedure groeb_mingb gb;
% Returns the min. Groebner basis dpmat mgb of the dpmat gb
% discarding base elements with bas_nr<=0.
   begin scalar u;
    u:=for each x in car red_collect dpmat_list gb join
                if bas_nr x>0 then {x};
        % Choosing base elements with minimal leading terms only.
    return dpmat_make(length u,dpmat_cols gb,bas_renumber u,
                    dpmat_coldegs gb);
    end;

% ------- Minimizing a basis using its syszgies ---------

symbolic procedure groeb!=delete(l,bas);
% Delete base elements from the base list bas with number in the
% integer list l.
    begin scalar b;
    while bas do
      << if not memq(bas_nr car bas,l) then b:=car bas . b;
         bas:= cdr bas
      >>;
    return reverse b
    end;

symbolic procedure groeb_minimize(bas,syz);
% Minimize the dpmat pair bas,syz deleting superfluous base elements
% from bas using syzygies from syz containing unit entries.
   (begin scalar drows, dcols, s,s1,i,j,p,q,y;
   cali!=degrees:=dpmat_coldegs syz;
   s1:=dpmat_list syz; j:=0;
   while j < dpmat_rows syz do
     << j:=j+1;
        if (q:=bas_dpoly bas_getelement(j,s1)) then
          << i:=0;
             while leq(i,dpmat_cols syz) and
                 (memq(i,dcols) or not dp_unit!?(p:=dp_comp(i,q)))
                        do i:=i+1;
             if leq(i,dpmat_cols syz) then
               << drows:=j . drows;
                  dcols:=i . dcols;
                  s1:=for each x in s1 collect
                     if memq(bas_nr x,drows) then x
                     else (bas_make(bas_nr x,
                        dp_diff(dp_prod(y,p),dp_prod(q,dp_comp(i,y))))
                           where y:=bas_dpoly x);
               >>
          >>
     >>;

   % --- s1 becomes the new syzygy part, s the new base part.

   s1:=bas_renumber bas_simp groeb!=delete(drows,s1);
   s1:=dpmat_make(length s1,dpmat_cols syz,s1,cali!=degrees);
                        % The new syzygy matrix of the old basis.
   s:=dpmat_renumber
          dpmat_make(dpmat_rows bas,dpmat_cols bas,
                groeb!=delete(dcols,dpmat_list bas),
                dpmat_coldegs bas);
   s1:=dpmat_mult(s1,dpmat_transpose cdr s);
        % The new syzygy matrix of the new basis, but not yet in the
        % right form since cali!=degrees is empty.
   s:=car s;            % The new basis.
   cali!=degrees:=dpmat_rowdegrees s;
   s1:=interreduce!* dpmat_make(dpmat_rows s1,dpmat_cols s1,
                bas_neworder dpmat_list s1,cali!=degrees);
   return s.s1;
   end) where cali!=degrees:=cali!=degrees;

% ---- Groebner algorithm with factorization and constraint lists.

symbolic procedure groeb!=problemsort(a,b); nth(a,4)<=nth(b,4);
% Sorted by ascending easydim to force depth first search.

symbolic operator groebfactor;
symbolic procedure groebfactor m;
  if !*mode='symbolic then rederr"only for algebraic mode"
  else makelist
      for each x in groebfactor!*(dpmat_from_a m,dp_fi 1) collect
        dpmat_2a x;

symbolic procedure groebfactor!*(bas,poly);
% Returns a list l of mgb's such that
% V(bas) \intersect D(poly) =
%           \union { V(b) : b \in l } \intersect D(poly)
% Data structure : problem = (dpmat,constraint list,pair list,easydim)
%                  result = dpmat . constraint list

   if dpmat_cols bas > 0 then
        rederr "GROEBFACTORIZE only for ideal bases"
   else if null !*noetherian then
        rederr "GROEBFACTORIZE only for noetherian term orders"
   else if dpmat_zero!? bas then list(bas)
   else begin integer nr; scalar gbs,pl,u,res;

    % -------- Initialization

   if cali!=trace > 5 then
   << write"Compute Groebner basis of"; dpmat_print bas;
      write" Preprocessing basis ... ";terpri()
   >>;
   poly:=if dp_unit!? poly then nil else {poly};
   gbs:=for each x in groeb!=preprocess(nil,bas,poly) collect
            list(car x,cdr x,
                groeb_makepairlist(dpmat_list car x,t),
                easydim!* car x);
   gbs:=sort(gbs,function groeb!=problemsort);
   while gbs do
   << if cali!=trace>10 then
                print for each x in gbs collect nth(x,4);
      u:=groeb!=slave car gbs; gbs:=cdr gbs;
       if u then
         if second u then % a result
         << u:=car second u;
           if cali!=trace > 5 then
           << write"partial result :"; terpri();
              dpmat_print car u ;
               prin2"constraints : ";
               for each x in cdr u do dp_print x;
           >>;
           if not groeb!=redtest(res,car u) then
                res:=u . groeb!=sieve(res,car u);
         >>
         else % a new problem list
         << u:=first u;
            for each x in u do
              if not groeb!=redtest(res,car x) then
                        gbs:=groeb!=update(gbs,x);
            if cali!=trace>20 then
            << terpri(); write length gbs," remaining branches. ",
               length res," partial results"; terpri()
            >>;
         >>
      else % branch discarded
        if cali!=trace>20 then print"Branch discarded";
   >>;
   return for each x in res collect car x;
   end;

symbolic procedure groeb!=redtest(a,c);
% Ex. u \in a : car u \submodule c
  listtest(a,c,function(lambda(x,y); submodulep!*(car x,y)));

symbolic procedure groeb!=sieve(a,c);
% Remove u \in a with c \submodule car u.
  for each x in a join if not submodulep!*(c,car x) then {x};

symbolic procedure groeb!=update(gbs,P);
% Update problem list gbs with a new problem P=(p,c_p,pl_p,dim_p) .
  begin scalar u,con;
  if (u:=groeb!=redtest(gbs,car p)) then
        cdr u:=intersection(second u,second p) . cddr u
  else
  << con:=second p;
     gbs:=for each x in gbs join
        if submodulep!*(car p,car x) then
                << con:=intersection(con,second x); >>
        else {x};
      gbs:=merge(gbs,{{ first p, con, third p, nth(p,4) }},
                function groeb!=problemsort);
  >>;
  return gbs;
  end;

symbolic procedure groeb!=test(con,m);
  if null con then t
  else begin scalar p; p:=car con;
    for each x in cdr con do p:=dp_prod(p,x);
    return bas_dpoly car red_redpol(m,bas_make(0,p));
    end;

symbolic procedure groeb!=preprocess(a1,b,con);
% Returns a list of (dpmat . constraint) factoring elements of the
% dpmat b. a1 is a list of essential results (dpmat . constraint)
% already computed.
% Data structure : problem = dpmat . constraint list

  begin scalar a,c,d,back,u,v,p;
    b:=list(b.con);
    if cali!=trace>20 then prin2"preprocessing started";
    while b do
    << if cali!=trace>20 then
       << terpri(); write length a," ready. ";
          write length b," left."; terpri()
       >>;
       c:=car b; b:=cdr b;
       if not (null groeb!=test(con:=cdr c,dpmat_list car c)
            or groeb!=redtest(a1,car c)
            or groeb!=redtest(a,car c)) then
       << d:=dpmat_list car c; back:=nil;
          while d and not back do
          << u:=((fctrf numr simp dp_2a bas_dpoly car d)
                        where !*factor=t);
             if (length u>2) or (cdadr u>1) then
             << back:=t; v:=nil;
                for each y in cdr u do
                << p:=dp_from_a prepf car y; v:=(p.con).v;
                   if not member(p,con) then con:=p . con;
                >>;
                b:=append(for each y in v collect
                      matsum!* {car c,
                        dpmat_make(1,0, list bas_make(1,car y),nil)}
                            . cdr y,
                      b);
             >>
             else d:=cdr d
          >>;
          if not back then
          << if cali!=trace>20 then
             << terpri(); write"Subproblem :"; dpmat_print car c >>;
             a:=c . groeb!=sieve(a,car c)
          >>
       >>
    >>;
    if cali!=trace>20 then prin2"preprocessing finished...";
    return a;
    end;

symbolic procedure groeb!=slave c;
  begin integer i; scalar be,back,p,u,v,a,b,gb,pl,nr,pol,con;

  back:=nil;
  gb:=dpmat_list first c; con:=second c; pl:=third c; nr:=length gb;
  while pl and not back do
  << p:=car pl; pl:=cdr pl;
     if cali!=trace > 10 then groeb_printpair(p,pl);

     pol:=groeb_spol p;
     if cali!=trace > 70 then
     << terpri(); write"S.-pol : "; dp_print1(bas_dpoly pol,nil) >>;
     pol:=bas_dpoly car red_redpol(gb,pol);
     if cali!=trace > 70 then
     << terpri(); write"Reduced S.-pol. : "; dp_print1(pol,nil) >>;

     if pol then
     << if !*bcsimp then pol:=car dp_simp pol;
        if dp_unit!? pol then
        << if cali!=trace>20 then print "unit ideal";
           back:=t
        >>
        else
        << % -- factorize pol
           u:=((fctrf numr simp dp_2a pol) where !*factor=t);
           nr:=nr+1;
           if length cdr u=1 then % only one factor
           << pol:=dp_from_a prepf caadr u;
              be:=bas_make(nr,pol);
              u:=be.gb;
              if null groeb!=test(con,u) then
              << back:=t;
                 if cali!=trace>20 then print" zero constraint";
              >>
              else
              << if cali!=trace>20 then
                 << terpri(); write nr,". "; dp_print1( pol,nil) >>;
                 pl:=groeb_updatePL(pl,gb,be,t);
                 if cali!=trace > 30 then
                 << terpri(); groeb_printpairlist pl >>;
                 gb:=merge(list be,gb,function red_better);
              >>
           >>
           else % more than one factor
           << for each x in cdr u do
              << pol:=dp_from_a prepf car x;
                 be:=bas_make(nr,pol);
                 a:=be.gb;
                 if groeb!=test(con,a) then
                 << if cali!=trace>20 then
                    << terpri(); write nr; write". ";
                       dp_print1( pol,nil)
                    >>;
                    p:=groeb_updatePL(append(pl,nil),gb,be,t);
                    if cali!=trace > 30 then
                    << terpri(); groeb_printpairlist p >>;
                    b:=merge(list be,append(gb,nil),
                        function red_better);
                    b:=dpmat_make(length b,0,b,nil);
                    v:={b,con,p}.v;
                 >>
                 else if cali!=trace>20 then print" zero constraint";
                 if not member(pol,con) then con:=pol . con;
              >>;
              if null v then
                << if cali!=trace>20 then print "Branch canceled";
                   back:=t
                >>
              else if length v=1 then
              << c:=car v; gb:=dpmat_list first c; con:=second c;
                 pl:=third c; v:=nil;
              >>
              else
              << back:=t;
                 if cali!=trace>20 then
                 << write" Branching into ",length v," parts ";
                    terpri();
                 >>;
              >>;
           >>;
        >>;
     >>;
  >>;
  if not back then % pl exhausted => new partial result.
  << u:=groeb_mingb dpmat_make(length gb,0,gb,nil);
     if !*red_total then
        % interreduce and try factorization once more.
     << u:=groeb!=preprocess(nil,
                dpmat_make(dpmat_rows u,0,
                   red_straight dpmat_list u,nil),con);
        if length u>1 then
        << v:=for each x in u collect
                {car x,cdr x,groeb_makepairlist(dpmat_list car x,t)};
           back:=t
        >>
        else u:=car u;
     >>
  >>;
  if back then return
        {for each x in v collect
                {first x,second x,third x,easydim!* first x},
        nil}
  else if u then return {nil,list u}
  else return nil;
  end;

endmodule; % groeb

module mora;

COMMENT

               ######################
               ##                  ##
               ##  STANDARD BASIS  ##
               ##    ALGORITHMS    ##
               ##                  ##
               ######################

This module contains the modifications to the modules red and groeb
necessary for non noetherian term orders. Consult the comments given
there for the meaning of several parameters, switches etc.

We make use of encoupled ecart vectors, hence all algorithms work for
arbitrary term orders (even for pure rev.-lex.).

"on lazy" turns on the lazy strategy of the tangent cone algorithm
(the default).  Otherwise we use Lazard's approach with
homogenization.

The following options effect the  computation only if no
representation part has to be computed :

"on factorunits" tries to remove unit factors (i.e. with deg lt(f)=0)
from polynomials by factorization.

"on detectunits" deletes unit factors only from polynomials of the
form monomial * unit.

END COMMENT;

% The default :

!*lazy:=t;

% ---------------- Special tools for local algebra -----------

symbolic procedure mora!=factorunits p;
  if null p then nil
    else mora!=delprod
        for each y in cdr (fctrf numr simp dp_2a p where !*factor=t)
            collect (dp_from_a prepf car y . cdr y);

symbolic procedure mora!=delprod u;
  begin scalar p; p:=dp_fi 1;
     for each x in u do
        if not dp_unit!? car x then p:=dp_prod(p,dp_power(car x,cdr x));
     return p
  end;

symbolic procedure mora!=detectunits p;
  if null p then nil
  else if listtest(cdr p,dp_lmon p,
        function(lambda(x,y);not mo_vdivides!?(y,car x))) then p
  else list dp_term(bc_fi 1,dp_lmon p);

symbolic procedure mora_factorunits b;
  bas_make(bas_nr b,mora!=factorunits bas_dpoly b);

symbolic procedure mora_detectunits b;
  bas_make(bas_nr b,mora!=detectunits bas_dpoly b);

symbolic procedure mora!=postprocess(pol,r0,monset);
% r0 <=> pol has dprows = 0.
  begin
  if !*bcsimp then pol:=car bas_simpelement pol;
  if !*factorunits and r0 then pol:=mora_factorunits pol
  else if !*detectunits then pol:=mora_detectunits pol;
  if monset then
        pol:=bas_make(bas_nr pol,
                      car dp_mondelete(bas_dpoly pol,monset));
  return pol
  end;

symbolic procedure mora_remo(b,m1,m2);
  for each x in b collect mora!=remo(x,m1,m2);

symbolic procedure mora!=remo(b,m1,m2);
% Remove monomials in the base element b (without bas_rep) belonging
% to the moideal m1 or less than m2 (highest corner), if m2<>nil.
% The latter works only for ideals.
  if m1 or m2 then
        bas_make(bas_nr b,mora!=remo1(bas_dpoly b,m1,m2))
  else b;

symbolic procedure mora!=remo1(p,m1,m2);
  for each x in p join
        if mora!=remotest(car x,m1,m2) then nil else list x;

symbolic procedure mora!=remotest(m,m1,m2);
   (if m2 then (mo_compare(m,m2)=-1) else nil) or moid_member(m,m1);

% ---------- Reduction specials -------------------

symbolic procedure mora!=better(a,b); bas_dplen a<bas_dplen b;
% A hook for its own reduction strategy.

symbolic procedure mora!=test(a,b);
% Test for updating the simplifier list.
  mora!=better(a,b) and
        mo_vdivides!?(dp_lmon bas_dpoly a,dp_lmon bas_dpoly b);

symbolic procedure mora!=update(simp,b);
% Update the simplifier list simp with the base element b.
    begin if cali!=trace>79 then
      << terpri();
         write(bas_dpecart b," +++> "); dp_print1(bas_dpoly b,nil);
      >>;
    return merge(list b,
                for each x in simp join
                        if mora!=test(b,x) then nil else {x},
                function mora!=better);
    end;

symbolic procedure mora!=divtest(u,m);
% Returns the first f in the base list u, such that lt(f) | lt(m)
% and ec(f) <= ec(m) else nil. m is a base element.
  listtest(u,m,function(lambda(x,y);
        (bas_dpecart x leq bas_dpecart y) and
           mo_vdivides!?(dp_lmon bas_dpoly x,dp_lmon bas_dpoly y)));

symbolic procedure mora!=divtest1(u,m);
  red_divtest(u,dp_lmon bas_dpoly m);

symbolic procedure mora_redpol(bas,model);
% Analogous to redpol in the module red, but the unit z may be a true
% polynomial (with degree 0 leading term):
% Returns (model1 . z) with model1 = (pol1 , rep1) and
%       pol1 = z * pol + \sum c_a f_a
%       rep1 = z * rep + \sum c_a rep_a
% No extra simplification are allowed since otherwise z should be
% divided !!
% The rep-component 0 is used for managing the polynomial unit z.
  if (null bas_dpoly model) or (null bas) then model . dp_fi 1
  else begin
     scalar ec,z,v1,v2;
        % Prepare rep for collecting the unit.
     model:=bas_make1(bas_nr model,bas_dpoly model,
                dp_sum(bas_rep model,dp_fi 1));
     if cali!=trace>79 then
       << write" reduce "; dp_print1(bas_dpoly model,nil); terpri() >>;
     while (bas_dpoly model) and
                ((v1:=mora!=divtest(bas,model)) or
                 (v2:=mora!=divtest1(bas,model))) do
       if v1 then model:=car red_subst(model,v1)
       else
         << v2:=red_subst(model,v2); bas:=mora!=update(bas,model);
            model:=car v2;
         >>;
     % ---- lt(pol) now irreducible ----
     z:=dp_comp(0,bas_rep model);
     return bas_make1(bas_nr model, bas_dpoly model,
                dp_diff(bas_rep model,z)) . z;
     end;

symbolic procedure mora!=splitup m;
% Split up the base list m into two lists : m1 is a moideal, m2 the
% remainder, totally reduced with respect to m1. Returns m1 . m2.
% Applies only without rep. part.
  begin scalar m1,m2,u;
  for each x in m do
        if length bas_dpoly x=1 then m1:=dp_lmon bas_dpoly x.m1
        else m2:=x.m2;
  if m1 then
    << u:=mora!=splitup for each x in m2 collect
                mora!=remo(x,m1,nil); % recursively
       m2:=cdr u; m1:=moid_sum(car u,m1);
    >>;
  return m1 . sort(bas_zerodelete m2,function mora!=better);
  end;

symbolic procedure mora_interreduce m;
% Reduce rows of the base list m until it has pairwise incomparable
% leading terms. Compute correct representation parts. !*factorunit
% should be nil for vector lists.
    begin scalar c,m1,m1a,u,v,w,bas1,pol,rep,norep;
    m:=sort(bas_zerodelete m, function mora!=better);
    if null m then return m
    else norep:=null bas_rep first m;
    if !*bcsimp then m:=bas_simp m;
    if norep then
        << if !*factorunits then
              m:=for each x in m collect mora_factorunits x
           else if !*detectunits then
              m:=for each x in m collect mora_detectunits x;
           u:=mora!=splitup m; m1:=car u; m:=cdr u
        >>;
    while cdr (c:=red_collect m) do
      << if cali!=trace>69 then
                <<write" interreduce ";terpri();bas_print m>>;
         w:=cdr c; bas1:=car c; m:=nil;
         while w do
           << c:=mora!=remo(car mora_redpol(bas1, car w),m1,nil);
              if bas_dpoly c then m:=c . m; w:=cdr w
            >>;
         if !*bcsimp then m:=bas_simp m;
         if norep then
           << if !*factorunits then
                        m:=for each x in m collect mora_factorunits x
              else if !*detectunits then
                        m:=for each x in m collect mora_detectunits x;
              u:=mora!=splitup m;
              if (m1a:=car u) then % remo bas1 with respect to m1a.
                << v:=mora!=splitup mora_remo(bas1,m1a,nil);
                   m1:=moid_sum(m1,moid_sum(m1a,car v));
                   bas1:=cdr v; m:=cdr u
                >>;
          >>;
         m:=merge(bas1,sort(m,function mora!=better),
                        function mora!=better);
      >>;
    if m1 then
        << m1:=for each x in m1 collect
                        bas_make(0,list dp_term(bc_fi 1,x));
           m:=merge(sort(m1,function mora!=better),m,
                        function mora!=better)
        >>;
    return m;
    end;

% ---------- Standard basis algorithms ---------------

symbolic procedure mora_stbasis(bas,comp_mgb,comp_ch,comp_syz);
% Returns {mgb,change,syz} with
%       dpmat mgb = if comp_mgb=true the minimal standard basis of
%                the dpmat bas else its simplifier list.
%       dpmat change defined by   mgb = change * bas
%               if comp_ch = true,
%       dpmat syz  = (non interreduced) syzygy matrix of bas
%               if comp_syz = true.

   if dpmat_zero!? bas then
     {bas,dpmat_unit(dpmat_rows bas,nil),dpmat_unit(dpmat_rows bas,nil)}
   else begin scalar u,syz,change,syz1,mon_set;
   cali!=degrees:=dpmat_coldegs bas;
   if comp_ch or comp_syz then mon_set:=nil else mon_set:=cali!=monset;
   if comp_syz then % syzygies for zero base elements.
   << u:=setdiff(for i:=1:dpmat_rows bas collect i,
      for each x in dpmat_list bas collect bas_nr x);
      syz1:=for each x in u collect bas_make(0,dp_from_ei x);
   >>;
   u:=if !*lazy then mora!=lazystbasis(bas,comp_ch,comp_syz,mon_set)
      else mora!=homstbasis(bas,comp_ch,comp_syz,mon_set);
   syz:=cadr u;
   if comp_mgb then u:=groeb_mingb car u else u:=car u;
      cali!=degrees:=dpmat_rowdegrees bas;
   if comp_ch then
      change:=dpmat_make(dpmat_rows u,dpmat_rows bas,
        bas_neworder bas_getrelations dpmat_list u, cali!=degrees);
   bas_removerelations dpmat_list u;
   if comp_syz then
   << syz:=nconc(syz,syz1);
      syz:=dpmat_make(length syz,dpmat_rows bas,
                bas_neworder bas_renumber syz,cali!=degrees);
   >>;
   cali!=degrees:=dpmat_coldegs u;
   return {u,change,syz}
   end;

% --------- StBasis with global simplifier list. The relict. ---------

symbolic procedure mora!=simpstbasis(bas,comp_ch,comp_syz,mon_set1);
% Returns bas . syz . trace with change matrix on rep-part of bas.
  if dpmat_rows bas=0 then bas . dpmat_unit(0,nil) . nil
  else begin integer i,nr,ec;
    scalar syz,m1,simp,u,v1,v2,q,gb,p,pl,pol,rep,trace,Ccrit,
                return_by_unit,norep;

    % -------- Initialization

    gb:=append(dpmat_list bas,nil); % make a copy of bas
    if comp_ch or comp_syz then bas_setrelations gb
    else norep:=t;
    if norep then
      << u:=mora!=splitup gb; m1:=car u; simp:=cdr u >>
    else simp:=append(gb,nil);
    simp:=sort(listminimize(simp,function mora!=test),
                function mora!=better);
    Ccrit:=(not comp_syz) and (dpmat_cols bas=0);
                            % -- don't reduce main syzygies
    nr:=dpmat_rows bas;
    if cali!=trace > 0 then
      << terpri(); write" Computing SimpStBasis  ";terpri() >>;
    if cali!=trace > 5 then
      << terpri(); write" Compute SimpStBasis of"; bas_print gb >>;
    pl:=groeb_makepairlist(gb,Ccrit);
    if cali!=trace > 30 then groeb_printpairlist pl;
    if cali!=trace > 5 then
      << terpri(); write" New base elements :";terpri() >>;

    % -------- working out pair list

    while pl and not return_by_unit do
      << p:=car pl; pl:=cdr pl;

         % ------ compute S-polynomial (which is a modelement)

         if cali!=trace > 10 then groeb_printpair(p,pl);
         pol:=groeb_spol p;
         if cali!=trace > 70 then
           << terpri(); write" S.-pol : ";
              dp_print1(bas_dpoly pol,nil)
           >>;

              % ---- reduce S-Polynomial ----------------

         if norep and m1 then pol:=mora!=remo(pol,m1,nil);
         while bas_dpoly pol and
                ((v1:=mora!=divtest(simp,pol)) or
                 (v2:=mora!=divtest1(simp,pol))) do
           << if v1 then u:=car red_subst(pol,v1)
              else
               << u:=car red_subst(pol,v2);
                  simp:=mora!=update(simp,pol)
               >>;
              if norep and m1 then pol:=mora!=remo(u,m1,nil)
              else pol:=u;
           >>;
         if cali!=trace > 70 then
           << terpri(); write" Reduced S.-pol. : ";
              dp_print1(bas_dpoly pol,nil)
           >>;

         if bas_dpoly pol then

              % --- the S-polynomial doesn't reduce to zero

           << if norep then pol:=mora!=postprocess(pol,ccrit,mon_set1);
              nr:=nr+1;
              pol:=bas_newnumber(nr,pol);

                % --- update the tracelist

              trace:=
                  list(groeb!=i p,groeb!=j p,nr,dp_lmon bas_dpoly pol) .
                            trace;

              if norep and (length bas_dpoly pol=1) then
                << p:=dp_lmon bas_dpoly pol;
                   u:=mora!=splitup mora_remo(simp,list p,nil);
                   m1:=moid_sum(m1,p . car u);
                   simp:=sort(listminimize(cdr u,function mora!=test),
                                function mora!=better)
                >>
              else simp:=mora!=update(simp,pol);

              if cali!=trace > 20 then
                << terpri(); write nr,". ---> ";
                        dp_print1(bas_dpoly pol,nil); terpri()
                >>;
              if Ccrit and (dp_unit!? bas_dpoly pol) then
                            return_by_unit:=t;
              if not return_by_unit then
                << % ----- updating pairlist
                   pl:=groeb_updatePL(pl,gb,pol,Ccrit);
                   if cali!=trace > 30 then
                     << terpri(); groeb_printpairlist pl >>;
                >>;
              gb:=pol.gb;
            >>

          else % ------ S-polynomial reduces to zero
             if comp_syz then
                syz:=bas_simpelement bas_make(0,bas_rep pol).syz;

      >>;

    % --------  updating the result

    if m1 then simp:=bas_renumber
        append(simp, for each x in m1 collect
                bas_make(0,list dp_term(bc_fi 1,x)));
    if cali!=trace>0 then
        write " Simplifier list has length ",length simp;
    if return_by_unit then return
        dpmat_make(1,dpmat_cols bas,list(bas_newnumber(1,pol)),
                cali!=degrees) . nil . reversip trace
    else return
        dpmat_make(length simp,dpmat_cols bas,simp,cali!=degrees)
                . syz . reversip trace;
    end;

% ------- StBasis with the lazy strategy. The default. -----------

symbolic procedure mora!=queuesort(a,b);
% Sort criterion for the queue.
  mo_compare(dp_lmon bas_dpoly a,dp_lmon bas_dpoly b)=1;

symbolic procedure mora!=nextspol(pl,queue);
% True <=> take first pl next.
  if null queue then t
  else if null pl then nil
  else mo_compare(nth(car pl,3),dp_lmon bas_dpoly car queue)=1;

symbolic procedure mora!=lazystbasis(bas,comp_ch,comp_syz,mon_set1);
% Returns ( gb . syz . nil) as above but using the local standard
% base algorithm with lazy strategy. (nil, since tracing doesn't make
% sense.
  if dpmat_rows bas=0 then bas . dpmat_unit(0,nil) . nil
  else begin integer i,nr,ec;
    scalar syz,Ccrit,m1,queue,simp,u,v1,v2,q,gb,p,pl,pol,rep,
        return_by_unit,norep;

    % -------- Initialization

    gb:=append(dpmat_list bas,nil); % make a copy of bas
    if comp_ch or comp_syz then bas_setrelations gb
    else norep:=t;
    if norep then
      << u:=mora!=splitup gb; m1:=car u; simp:=cdr u >>
    else simp:=append(gb,nil);
    simp:=sort(listminimize(simp,function mora!=test),
                function mora!=better);
    Ccrit:=(not comp_syz) and (dpmat_cols bas=0);
                        % -- don't reduce main syzygies
    nr:=dpmat_rows bas;
    if cali!=trace > 0 then
    <<terpri(); write" Computing LazyStBasis  ";terpri()>>;
    if cali!=trace > 5 then
        << terpri(); write" Compute LazyStBasis of"; bas_print gb >>;
    pl:=groeb_makepairlist(gb,Ccrit);
    if cali!=trace > 30 then groeb_printpairlist pl;
    if cali!=trace > 5 then
        <<terpri(); write" New base elements :";terpri() >>;

    % -------- working out pair list

    while (pl or queue) and not return_by_unit do
      if mora!=nextspol(pl,queue) then
        << p:=car pl; pl:=cdr pl;
           if cali!=trace > 10 then groeb_printpair(p,pl);
           pol:=groeb_spol p;
           if bas_dpoly pol then % back into the queue
             << if norep then
                    pol:=mora!=postprocess(pol,ccrit,mon_set1);
                if Ccrit and dp_unit!? bas_dpoly pol then
                    return_by_unit:=t
                else queue:=merge(list pol, queue,
                                    function mora!=queuesort)
             >>
           else % pol reduced to zero.
           if comp_syz then
                syz:=bas_simpelement bas_make(0,bas_rep pol).syz;
           if cali!=trace > 70 then
             << terpri(); write" S.-pol : ";
                dp_print1(bas_dpoly pol,nil)
             >>;
        >>
      else
        << pol:=car queue; queue:=cdr queue;
           if norep and m1 then pol:=mora!=remo(pol,m1,nil);
           if bas_dpoly pol then % try a reduction step
             if ((v1:=mora!=divtest(simp,pol)) or
                 (v2:=mora!=divtest1(simp,pol))) then
               << if v1 then u:=car red_subst(pol,v1)
                  else
                    << u:=car red_subst(pol,v2);
                       simp:=mora!=update(simp,pol)
                    >>;
                  if norep and m1 then pol:=mora!=remo(u,m1,nil)
                  else pol:=u;
                  if bas_dpoly pol then % back into the queue
                    << if norep then
                        pol:=mora!=postprocess(pol,ccrit,mon_set1);
                       if Ccrit and dp_unit!? bas_dpoly pol then
                           return_by_unit:=t
                       else queue:=merge(list pol, queue,
                           function mora!=queuesort)
                   >>
                 else % pol reduced to zero.
                 if comp_syz then
                   syz:=bas_simpelement bas_make(0,bas_rep pol).syz;
              >>
            else % no reduction possible
              << nr:=nr+1; pol:=bas_newnumber(nr,pol);
                 if cali!=trace > 20 then
                   << terpri(); write nr,". --> ";
                        dp_print1(bas_dpoly pol,nil)
                   >>;
                 pl:=groeb_updatePL(pl,gb,pol,Ccrit);
                 if norep and (length bas_dpoly pol=1) then
                   << p:=dp_lmon bas_dpoly pol;
                      u:=mora!=splitup mora_remo(simp,list p,nil);
                      m1:=moid_sum(m1,p . car u);
                      simp:=sort(listminimize(cdr u,
                                        function mora!=test),
                                function mora!=better)
                   >>
                 else simp:=mora!=update(simp,pol);
                 gb:=pol.gb;
              >>
          else  % ------ S-polynomial reduces to zero
            << if cali!=trace>20 then write " QL = ",length queue;
               if comp_syz then
                 syz:=bas_simpelement bas_make(0,bas_rep pol).syz;
            >>
     >>;

     % --------  updating the result

    if m1 then simp:=bas_renumber
        append(simp, for each x in m1 collect
                    bas_make(0,list dp_term(bc_fi 1,x)));
    if cali!=trace>0 then
        write " Simplifier list has length ",length simp;
    if return_by_unit then return
        dpmat_make(1,dpmat_cols bas,list(bas_newnumber(1,pol)),
                cali!=degrees). nil . nil
    else return dpmat_make(length simp,dpmat_cols bas,simp,
                cali!=degrees) . syz . nil;
    end;

% ------ Lazard's approach. Use "off lazy" to activate it. --------

symbolic procedure mora!=homstbasis(m,comp_ch,comp_syz,mon_set);
  (begin scalar v,c,e,n,to,u;
  c:=cali!=basering; v:=list gensym();
  if not(comp_ch or comp_syz) then mon_set:=append(v,mon_set);
  setring!* ring_sum(c,ring_define(v,nil,'lex,'(1)));
  cali!=degrees:=mo_degneworder dpmat_coldegs m;
  if cali!=trace>0 then print" Homogenize input ";
  u:=groeb_innerstbasis(mathomogenize!*(m,car v),
                comp_ch, comp_syz, mon_set);
  if cali!=trace>0 then print" Dehomogenize output ";
  u:=matdehomogenize!*(car u,car v) . bas_dehomogenize(cadr u,car v);
  setring!* c; cali!=degrees:=dpmat_coldegs m;
  return {dpmat_neworder car u,bas_neworder cdr u};
  end) where cali!=basering:=cali!=basering,
                        cali!=degrees:=cali!=degrees;


endmodule;  % mora


module matop;

COMMENT

              #############################
              ####                     ####
              ####  MATRIX OPERATIONS  ####
              ####                     ####
              #############################


This module contains operations on dpmats, that correspond to module
operations on the corresponding images resp. cokernels.

END COMMENT;

procedure matop!=testdpmatlist l;
% Test l to be a list of dpmats embedded into a common free module.
  if null l then rederr"Empty DPMAT list"
  else begin scalar c,d;
    for each x in l do
        if not eqcar(x,'dpmat) then typerr(x,"DPMAT");
    c:=dpmat_cols car l; d:=dpmat_coldegs car l;
    for each x in cdr l do
      if not (eqn(c,dpmat_cols x) and equal(d,dpmat_coldegs x)) then
                rederr"Matrices don't match in the DPMAT list";
  end;

procedure matappend!* l;
% Appends rows of the dpmats in the dpmat list l.
  (begin scalar u,r;
      matop!=testdpmatlist l;
      cali!=degrees:=dpmat_coldegs car l;
      u:=dpmat_list car l; r:=dpmat_rows car l;
      for each y in cdr l do
        << u:=append(u, for each x in dpmat_list y collect
                        bas_newnumber(bas_nr x + r,x));
           r:=r + dpmat_rows y;
        >>;
      return dpmat_make(r,dpmat_cols car l,u,cali!=degrees)
   end) where cali!=degrees:=cali!=degrees;

put('matappend,'psopfn,'matop!=matappend);
symbolic procedure matop!=matappend l;
% Append the dpmats in the list l.
  dpmat_2a matappend!* for each x in l collect dpmat_from_a reval x;

procedure flatten!* m;
% Returns the ideal of all elements of m.
  if dpmat_cols m = 0 then m
  else (begin scalar x;
    x:=bas_renumber bas_zerodelete
        for i:=1:dpmat_rows m join
        for j:=1:dpmat_cols m collect
                bas_make(0,dpmat_element(i,j,m));
    return dpmat_make(length x,0,x,nil)
    end) where cali!=degrees:=nil;

procedure matsum!* l;
% Returns the module sum of the dpmat list l.
  interreduce!* matappend!* l;

put('matsum,'psopfn,'matop!=matsum);
put('idealsum,'psopfn,'matop!=matsum);
symbolic procedure matop!=matsum l;
% Returns the sum of the ideals/modules in the list l.
  dpmat_2a matsum!* for each x in l collect dpmat_from_a reval x;

procedure matop!=idealprod2(a,b);
  if (dpmat_cols a > 0) or (dpmat_cols b > 0 ) then
                rederr"IDEALPROD only for ideals"
  else (begin scalar x;
    x:=bas_renumber
        for each a1 in dpmat_list a join
        for each b1 in dpmat_list b collect
            bas_make(0,dp_prod(bas_dpoly a1,bas_dpoly b1));
    return interreduce!* dpmat_make(length x,0,x,nil)
    end) where cali!=degrees:=nil;

procedure idealprod!* l;
% Returns the product of the ideals in the dpmat list l.
 if null l then rederr"empty list in IDEALPROD"
 else if length l=1 then car l
 else begin scalar u;
    u:=car l;
    for each x in cdr l do u:=matop!=idealprod2(u,x);
    return u;
    end;

put('idealprod,'psopfn,'matop!=idealprod);
symbolic procedure matop!=idealprod l;
% Returns the product of the ideals in the list l.
  dpmat_2a idealprod!* for each x in l collect dpmat_from_a reval x;

procedure idealpower!*(a,n);
  if (dpmat_cols a > 0) or (not fixp n) or (n < 0) then
        rederr" Syntax : idealpower(ideal,integer)"
  else if (n=0) then dpmat_from_dpoly dp_fi 1
  else begin scalar w; w:=a;
  for i:=2:n do w:=matop!=idealprod2(w,a);
  return w;
  end;

symbolic operator idealpower;
symbolic procedure idealpower(m,l);
  if !*mode='symbolic then rederr"only for algebraic mode"
  else   dpmat_2a idealpower!*(dpmat_from_a reval m,l);

procedure matop!=shiftdegs(d,n);
% Shift column degrees d n places.
   for each x in d collect ((car x + n) . cdr x);

procedure directsum!* l;
% Returns the direct sum of the modules in the dpmat list l.
  if null l then rederr"Empty DPMAT list"
  else (begin scalar r,c,u;
    for each x in l do
        if not eqcar(x,'dpmat) then typerr(x,"DPMAT")
        else if dpmat_cols x=0 then
                rederr"DIRECTSUM only for modules";
    c:=r:=0; % Actual column resp. row index.
    cali!=degrees:=nil;
    for each x in l do
       << cali!=degrees:=append(cali!=degrees,
                        matop!=shiftdegs(dpmat_coldegs x,c));
          u:=append(u, for each y in dpmat_list x collect
                bas_make(bas_nr y + r,dp_times_ei(c,bas_dpoly y)));
          r:=r + dpmat_rows x;
          c:=c + dpmat_cols x;
        >>;
    return dpmat_make(r,c,u,cali!=degrees)
    end) where cali!=degrees:=cali!=degrees;

put('directsum,'psopfn,'matop!=directsum);
symbolic procedure matop!=directsum l;
% Returns the direct sum of the modules in the list l.
  dpmat_2a directsum!* for each x in l collect dpmat_from_a reval x;

symbolic operator deleteunits;
symbolic procedure deleteunits m;
  if !*mode='symbolic then rederr"only for algebraic mode"
  else if !*noetherian then m
  else dpmat_2a deleteunits!* dpmat_from_a m;

symbolic procedure deleteunits!* m;
% Delete units from the base elements of the ideal m.
  if !*noetherian or (dpmat_cols m>0) then m
  else dpmat_make(dpmat_rows m,0,
        for each x in dpmat_list m collect mora_factorunits x,nil);

symbolic procedure interreduce!* m;
  (begin scalar u,c;  c:=dpmat_cols m; m:=dpmat_list m;
  u:=if !*noetherian then red_interreduce m else mora_interreduce m;
  return dpmat_make(length u,c, bas_renumber u,cali!=degrees)
  end)  where cali!=degrees:=dpmat_coldegs m;

symbolic operator interreduce;
symbolic procedure interreduce m;
% Interreduce m.
  if !*mode='symbolic then rederr"only for algebraic mode"
  else   dpmat_2a interreduce!* dpmat_from_a reval m;

symbolic procedure gbasis!* m;
% Produce a minimal Groebner or standard basis of the dpmat m.
   if !*noetherian then car groeb_stbasis(m,t,nil,nil)
   else car mora_stbasis(m,t,nil,nil);

put('tangentcone,'psopfn,'matop!=tangentcone);
symbolic procedure matop!=tangentcone m;
  begin scalar c;
  intf_test m; m:=car m; intf_get m;
  if not (c:=get(m,'gbasis)) then rederr"Compute Gbasis first";
  c:=tangentcone!* c;
  return dpmat_2a c;
  end;

symbolic procedure tangentcone!* m;
% Returns the tangent cone of m, provided the term order has degrees.
% m must be a gbasis.
  if null ring_degrees cali!=basering then
        rederr"tangent cone only for degree orders defined"
  else (begin scalar b;
  b:=for each x in dpmat_list m collect
    bas_make(bas_nr x,dp_tcpart bas_dpoly x);
  return dpmat_make(dpmat_rows m,dpmat_cols m,b,cali!=degrees);
  end)  where cali!=degrees:=dpmat_coldegs m;


symbolic procedure syzygies1!* bas;
% Returns the (not yet interreduced first) syzygy module of the dpmat
% bas.
  begin
  if cali!=trace > 0 then
    << terpri(); write" Compute syzygies"; terpri() >>;
  if !*noetherian then return third groeb_stbasis(bas,nil,nil,t)
  else return third mora_stbasis(bas,nil,nil,t);
  end;

symbolic procedure syzygies!* bas;
% Returns the interreduced syzygy basis.
  interreduce!* syzygies1!* bas;

symbolic procedure normalform!*(a,b);
% Returns {a1,r,z} with a1=z*a-r*b where the rows of the dpmat a1 are
% the normalforms of the rows of the dpmat a with respect to the
% dpmat b.
   if not(eqn(dpmat_cols a,dpmat_cols b) and
        equal(dpmat_coldegs a,dpmat_coldegs b)) then
                rederr"dpmats don't match for NORMALFORM"
   else (begin scalar a1,z,u,r;
      bas_setrelations dpmat_list b;
      a1:=for each x in dpmat_list a collect
        << u:=if !*noetherian then
                red_redpol(dpmat_list b,x)
              else
                mora_redpol(dpmat_list b,x);
           z:=bas_make(bas_nr x,dp_times_ei(bas_nr x,cdr u)).z;
           car u
        >>;
      r:=bas_getrelations a1; bas_removerelations a1;
      bas_removerelations dpmat_list b; z:=reversip z;
      a1:=dpmat_make(dpmat_rows a,dpmat_cols a,a1,cali!=degrees);
      cali!=degrees:=dpmat_rowdegrees b;
      r:=dpmat_make(dpmat_rows a,dpmat_rows b,bas_neworder r,
                            cali!=degrees);
      cali!=degrees:=nil;
      z:=dpmat_make(dpmat_rows a,dpmat_rows a,bas_neworder z,nil);
      return  {a1,r,z};
      end)  where cali!=degrees:=dpmat_coldegs b;

symbolic procedure matop_pseudomod(a,b); car mod!*(a,b);

symbolic procedure mod!*(a,b);
% Returns the normal form of the dpoly a modulo the dpmat b and the
% corresponding unit produced during pseudo division.
  (begin scalar a1,z,u,r;
      a:=dp_neworder a; % to be on the safe side.
      u:=if !*noetherian then
                red_redpol(dpmat_list b,bas_make(0,a))
              else
                mora_redpol(dpmat_list b,bas_make(0,a));
      return (bas_dpoly car u) . cdr u;
  end)  where cali!=degrees:=dpmat_coldegs b;

symbolic operator mod;
symbolic procedure mod(a,b);
% True normal form as s.q. also for matrices.
  if !*mode='symbolic then rederr"only for algebraic mode"
  else begin scalar u;
    b:=dpmat_from_a reval b; a:=reval a;
    if eqcar(a,'list) then
        if dpmat_cols b>0 then rederr"entries don't match for MOD"
        else a:=makelist for each x in cdr a collect
           << u:=mod!*(dp_from_a x, b);
              {'quotient,dp_2a car u,dp_2a cdr u}
           >>
    else if eqcar(a,'mat) then
        begin a:=dpmat_from_a a;
        if dpmat_cols a neq dpmat_cols b then
                rederr"entries don't match for MOD";
        a:=for each x in dpmat_list a collect mod!*(bas_dpoly x,b);
        a:='mat.
            for each x in a collect
              << u:=dp_2a cdr x;
                 for i:=1:dpmat_cols b collect
                    {'quotient,dp_2a dp_comp(i,car x),u}
              >>
        end
    else if dpmat_cols b>0 then rederr"entries don't match for MOD"
    else << u:=mod!*(dp_from_a a, b);
            a:={'quotient,dp_2a car u,dp_2a cdr u}
          >>;
    return a;
    end;

infix mod;

symbolic operator normalform;
symbolic procedure normalform(a,b);
% Compute a normal form of the rows of a with respect to b :
%   first result = third result * a + second result * b.
  if !*mode='symbolic then rederr"only for algebraic mode"
  else begin scalar m;
  m:= normalform!*(dpmat_from_a reval a,dpmat_from_a reval b);
  return {'list,dpmat_2a car m, dpmat_2a cadr m, dpmat_2a caddr m}
  end;

symbolic procedure eliminate!*(m,vars);
% Returns a (dpmat) basis of the elimination module of the dpmat m
% eliminating variables contained in the var. list vars.
% It sets temporary the standard elimination term order, but doesn't
% affect the ecart, and computes a Groebner basis of m.
   (begin scalar c,e,bas,v;
   c:=cali!=basering; e:=ring_ecart c;
   v:=ring_names cali!=basering;
   setring!* ring_define(v,eliminationorder!*(v,vars),'revlex,e);
   cali!=degrees:=nil; % No degrees for proper result !!
   bas:=(bas_sieve(dpmat_list
            car groeb_stbasis(dpmat_neworder m,t,nil,nil), vars)
            where !*noetherian=t);
   setring!* c; cali!=degrees:=dpmat_coldegs m;
   return dpmat_make(length bas,dpmat_cols m,bas_neworder bas,
                            cali!=degrees);
   end)
   where cali!=degrees:=cali!=degrees,
                cali!=basering:=cali!=basering;

symbolic operator eliminate;
symbolic procedure eliminate(m,l);
% Returns the elimination ideal/module of m with respect to the
% variables in the list l to be eliminated.
  if !*mode='symbolic then rederr"only for algebraic mode"
  else begin l:=reval l;
    if not eqcar(l,'list) then typerr(l,"variable list");
    m:=dpmat_from_a m; l:=cdr l;
    return dpmat_2a eliminate!*(m,l);
    end;

symbolic procedure matintersect!* l;
  if null l then rederr"MATINTERSECT with empty list"
  else if length l=1 then car l
  else (begin scalar c,u,v,p,size;
    matop!=testdpmatlist l;
    size:=dpmat_cols car l;
    v:=for each x in l collect gensym();
    c:=cali!=basering;
    setring!* ring_sum(c,
        ring_define(v,degreeorder!* v,'lex,for each x in v collect 1));
    cali!=degrees:=mo_degneworder dpmat_coldegs car l;
    u:=for each x in pair(v,l) collect
        dpmat_times_dpoly(dp_from_a car x,dpmat_neworder cdr x);
    p:=dp_fi 1; for each x in v do p:=dp_diff(p,dp_from_a x);
    if size=0 then p:=dpmat_make(1,0,list bas_make(1,p),cali!=degrees)
    else p:=dpmat_times_dpoly(p,dpmat_unit(size,cali!=degrees));
    p:=gbasis!* matsum!* (p . u);
    p:=dpmat_sieve(p,v);
    setring!* c;
    cali!=degrees:=dpmat_coldegs car l;
    return dpmat_neworder p;
   end)
   where cali!=degrees:=cali!=degrees,
                cali!=basering:=cali!=basering;

put('matintersect,'psopfn,'matop!=matintersect);
symbolic procedure matop!=matintersect l;
% Returns the intersection of the submodules of a fixed free module
% in the list l.
  dpmat_2a matintersect!* for each x in l collect dpmat_from_a reval x;

put('idealintersect,'psopfn,'matop!=idealintersect);
symbolic procedure matop!=idealintersect l;
  rederr "use MATINTERSECT instead";

% ------- Submodule property and equality test --------------

put('modequalp,'psopfn,'matop!=equalp);
% Test, whether a and b are module equal.
symbolic procedure matop!=equalp u;
  if length u neq 2 then rederr"Syntax : MODEQUALP(dpmat,dpmat) "
  else begin scalar a,b;
    intf_get first u; intf_get second u;
    if null(a:=get(first u,'gbasis)) or
        null(b:=get(second u,'gbasis)) then
            rederr"Compute gbases first";
    if modequalp!*(a,b) then return 'yes else return 'no
    end;

symbolic procedure modequalp!*(a,b);
  submodulep!*(a,b) and submodulep!*(b,a);

put('submodulep,'psopfn,'matop!=submodulep);
% Test, whether a is a submodule of b.
symbolic procedure matop!=submodulep u;
  if length u neq 2 then rederr"Syntax : SUBMODULEP(dpmat,dpmat)"
  else begin scalar a,b;
    intf_get second u;
    if null(b:=get(second u,'gbasis)) then
            rederr"Compute second gbasis first";
    a:=dpmat_from_a reval first u;
    if submodulep!*(a,b) then return 'yes else return 'no
    end;

symbolic procedure submodulep!*(a,b);
  if not(dpmat_cols a=dpmat_cols b
     and equal(dpmat_coldegs a,dpmat_coldegs b)) then
    rederr"incompatible modules in SUBMODULEP"
  else (begin
    a:=for each x in dpmat_list a collect bas_dpoly x;
    return not listtest(a,b,function matop_pseudomod)
    end) where cali!=degrees:=dpmat_coldegs a;

endmodule; % matop

module quot;

COMMENT

                #################
                #               #
                #   QUOTIENTS   #
                #               #
                #################


This module contains algorithms for different kinds of quotients of
ideals and modules.

END COMMENT;

% -------- Quotient of a module by a polynomial -----------
% Returns m : (f) for a polynomial f.

symbolic operator matquot;
symbolic procedure matquot(m,f);
  if !*mode='symbolic then rederr"only for algebraic mode"
  else dpmat_2a matquot!*(dpmat_from_a reval m,dp_from_a reval f);

symbolic procedure matquot!*(m,f);
  if dp_unit!? f then m
  else if dpmat_cols m=0 then flatten!* quot!=quot(ideal2mat!* m,f)
  else quot!=quot(m,f);

symbolic procedure quot!=quot(m,f);
  begin scalar a,b;
  a:=matintersect!* {m,
    dpmat_times_dpoly(f,dpmat_unit(dpmat_cols m,dpmat_coldegs m))};
  b:=for each x in dpmat_list a collect
    bas_make(bas_nr x,car dp_pseudodivmod(bas_dpoly x,f));
  return dpmat_make(dpmat_rows a,dpmat_cols a,b,dpmat_coldegs m);
  end;

% -------- Quotient of a module by an ideal -----------
% Returns m:n as a module.

symbolic operator idealquotient;
symbolic procedure idealquotient(m,n);
  if !*mode='symbolic then rederr"only for algebraic mode"
  else dpmat_2a idealquotient2!*(dpmat_from_a reval m,
                            dpmat_from_a reval n);

% -------- Quotient of a module by another module  -----------
% Returns m:n as an ideal in S. m and n must be submodules of a common
% free module.

symbolic operator modulequotient;
symbolic procedure modulequotient(m,n);
  if !*mode='symbolic then rederr"only for algebraic mode"
  else dpmat_2a modulequotient2!*(dpmat_from_a reval m,
                            dpmat_from_a reval n);

% ---- The annihilator of a module, i.e. Ann coker M := M : F ---

symbolic operator annihilator;
symbolic procedure annihilator m;
  if !*mode='symbolic then rederr"only for algebraic mode"
  else dpmat_2a annihilator2!* dpmat_from_a reval m;

% ---- Quotients as M:N = \intersect { M:f | f \in N } ------

symbolic procedure idealquotient2!*(m,n);
  if dpmat_cols n>0 then rederr"Syntax : idealquotient(dpmat,ideal)"
  else if dpmat_cols m=0 then modulequotient2!*(m,n)
  else matintersect!* for each x in dpmat_list n collect
        quot!=quot(m,bas_dpoly x);

symbolic procedure modulequotient2!*(m,n);
  (begin scalar c;
  if not((c:=dpmat_cols m)=dpmat_cols n) then rederr
    "MODULEQUOTIENT only for submodules of a common free module";
  if not equal(dpmat_coldegs m,dpmat_coldegs n) then
          rederr"matrices don't match for MODULEQUOTIENT";
  if (c=0) then << m:=ideal2mat!* m; n:=ideal2mat!* n >>;
  cali!=degrees:=dpmat_coldegs m;
  n:=for each x in dpmat_list n collect matop_pseudomod(bas_dpoly x,m);
  n:=for each x in n join if x then {x};
  return if null n then dpmat_from_dpoly dp_fi 1
  else matintersect!* for each x in n collect quot!=mquot(m,x);
  end) where cali!=degrees:=cali!=degrees;

symbolic procedure quot!=mquot(m,f);
  begin scalar a,b;
  a:=matintersect!*
    {m,dpmat_make(1,dpmat_cols m,list bas_make(1,f),dpmat_coldegs m)};
  b:=for each x in dpmat_list a collect
    bas_make(bas_nr x,car dp_pseudodivmod(bas_dpoly x,f));
  return dpmat_make(dpmat_rows a,0,b,nil);
  end;

symbolic procedure annihilator2!* m;
  if dpmat_cols m=0 then m
  else modulequotient2!*(m,dpmat_unit(dpmat_cols m,dpmat_coldegs m));

% -------- Quotients by the general element method --------

symbolic procedure idealquotient1!*(m,n);
  if dpmat_cols n>0 then rederr "second parameter must be an ideal"
  else if dpmat_cols m=0 then modulequotient1!*(m,n)
  else (begin scalar u1,u2,f,v,r,m1;
  v:=list gensym(); r:=cali!=basering;
  setring!* ring_sum(r,ring_define(v,degreeorder!* v,'revlex,'(1)));
  cali!=degrees:=mo_degneworder dpmat_coldegs m;
  n:=for each x in dpmat_list n collect dp_neworder x;
  u1:=u2:=dp_from_a car v; f:=car n;
  for each x in n do
        << f:=dp_sum(f,dp_prod(u1,x)); u1:=dp_prod(u1,u2) >>;
  m1:=dpmat_sieve(gbasis!* quot!=quot(dpmat_neworder m,f),v);
  setring!* r; cali!=degrees:=dpmat_coldegs m;
  return dpmat_neworder m1;
   end)
   where cali!=degrees:=cali!=degrees,
                cali!=basering:=cali!=basering;

symbolic procedure modulequotient1!*(m,n);
  (begin scalar c,u1,u2,f,v,r,m1;
  if not((c:=dpmat_cols m)=dpmat_cols n) then rederr
    "MODULEQUOTIENT only for submodules of a common free module";
  if not equal(dpmat_coldegs m,dpmat_coldegs n) then
          rederr"matrices don't match for MODULEQUOTIENT";
  if (c=0) then << m:=ideal2mat!* m; n:=ideal2mat!* n >>;
  cali!=degrees:=dpmat_coldegs m;
  n:=for each x in dpmat_list n collect matop_pseudomod(bas_dpoly x,m);
  n:=for each x in n join if x then {x};
  if null n then return dpmat_from_dpoly dp_fi 1;
  v:=list gensym(); r:=cali!=basering;
  setring!* ring_sum(r,ring_define(v,degreeorder!* v,'revlex,'(1)));
  cali!=degrees:=mo_degneworder cali!=degrees;
  u1:=u2:=dp_from_a car v; f:=dp_neworder car n;
  for each x in n do
     << f:=dp_sum(f,dp_prod(u1,dp_neworder x));
        u1:=dp_prod(u1,u2)
     >>;
  m1:=dpmat_sieve(gbasis!* quot!=mquot(dpmat_neworder m,f),v);
  setring!* r; cali!=degrees:=dpmat_coldegs m;
  return dpmat_neworder m1;
   end)
   where cali!=degrees:=cali!=degrees,
                cali!=basering:=cali!=basering;

symbolic procedure annihilator1!* m;
  if dpmat_cols m=0 then m
  else modulequotient1!*(m,dpmat_unit(dpmat_cols m,dpmat_coldegs m));

% --------------- Stable quotients ------------------------

symbolic operator matqquot;
symbolic procedure matqquot(m,f);
% Stable quotient of dpmat m with respect to a polynomial f, i.e.
% m : <f> = { v \in F | \exists n : f^n*v \in m }
  if !*mode='symbolic then rederr"only for algebraic mode"
  else dpmat_2a matqquot!*(dpmat_from_a reval m,dp_from_a reval f);

symbolic procedure matqquot!*(m,f);
  if dp_unit!? f then m
  else if dpmat_cols m=0 then
        flatten!* quot!=stabquot(ideal2mat!* m,{f})
  else quot!=stabquot(m,{f});

symbolic operator matstabquot;
symbolic procedure matstabquot(m,f);
% Stable quotient of dpmat m with respect to an ideal f.
  if !*mode='symbolic then rederr"only for algebraic mode"
  else dpmat_2a
        matstabquot!*(dpmat_from_a reval m,dpmat_from_a reval f);

symbolic procedure matstabquot!*(m,f);
  if dpmat_cols f > 0 then rederr "stable quotient only by ideals"
  else begin scalar c;
    if (c:=dpmat_cols m)=0 then
        << f:=for each x in dpmat_list f collect
                    matop_pseudomod(bas_dpoly x,m);
           f:=for each x in f join if x then {x}
        >>
    else f:=for each x in dpmat_list f collect bas_dpoly x;
    if null f then return
        if c=0 then dpmat_from_dpoly dp_fi 1
        else dpmat_unit(c,dpmat_coldegs m);
    if dp_unit!? car f then return m;
    if c=0 then return flatten!* quot!=stabquot(ideal2mat!* m,f)
    else return quot!=stabquot(m,f);
    end;

symbolic procedure quot!=stabquot(m,f);
% m must be a module.
  if dpmat_cols m=0 then rederr"quot_stabquot only for cols>0"
  else (begin scalar m1,p,p1,p2,v,v1,v2,c;
    v1:=gensym(); v2:=gensym(); v:={v1,v2};
    setring!* ring_sum(c:=cali!=basering,
        ring_define(v,degreeorder!* v,'lex,'(1 1)));
    cali!=degrees:=mo_degneworder dpmat_coldegs m;
    p1:=p2:=dp_from_a v1;
    f:=for each x in f collect dp_neworder x;
    p:=car f;
    for each x in cdr f do
    << p:=dp_sum(dp_prod(p1,x),p); p1:=dp_prod(p1,p2) >>;
    p:=dp_diff(dp_fi 1,dp_prod(dp_from_a v2,p));
        % p = 1 - v2 * \sum{f_i * v1^i}
    m1:=matsum!* {dpmat_neworder m, dpmat_times_dpoly(p,
        dpmat_unit(dpmat_cols m,cali!=degrees))};
    m1:=dpmat_sieve(gbasis!* m1,v);
    setring!* c; cali!=degrees:=dpmat_coldegs m;
    return dpmat_neworder m1;
   end)
   where cali!=degrees:=cali!=degrees,
                cali!=basering:=cali!=basering;

endmodule; % quot

module moid;

COMMENT

               ##################################
               ##                              ##
               ##     MONOMIAL IDEALS AND      ##
               ##  HILBERT SERIES COMPUTATION  ##
               ##                              ##
               ##################################

This module supports computations with leading term ideals. Moideal
monomials are assumed to be without module component, but there is a
Hilbert series calculation also for modules. Hilbert series are
calculated with respect to the ecart vector. To change this overload
mo_convert

This module contains :

        - A moideal prime decomposition along Bayer, Stillman (1992).

        - An algorithm to find all strongly independent sets using
                moideal primes (also for modules),

        - An algorithm to compute the dimension (dim M := dim in(M))
                based on strongly independent sets.

        - Two algorithms computing Hilbert series of ideals and
                modules.

Lit.: Bayer, Stllman : J. Symb. Comp. 14 (1992), 31 - 50.

      Bigatti, Conti, Robbiano, Traverso . to appear


Monomial ideals have the following informal syntax :

        <moideal> ::= list of monomials

They may be vmoideals as well, i.e. with module components.
Moideals are kept ordered with respect to the descending lexicographic
order, see [BS].

END COMMENT;

% ------------- monomial ideal constructors --------------

symbolic procedure moid_from_bas bas;
% Returns the list of leading monomials of the base list bas
% not removing module components.
   for each x in bas_zerodelete bas collect dp_lmon bas_dpoly x;

symbolic procedure moid_from_dpmat m;
% Returns the assoc. list of moideals of the columns of the dpmat m.
  (if dpmat_cols m = 0 then list (0 . u)
  else for i:=1:dpmat_cols m collect
     i . for each x in u join if mo_comp(x)=i then {mo_deletecomp x})
  where u=moid_from_bas dpmat_list m;

symbolic procedure moid_2a m;
% Convert the moideal m to algebraic mode.
  'list . for each x in m collect dp_2a list dp_term(bc_fi 1,x);

symbolic procedure moid_from_a m;
% Convert a moideal from algebraic mode.
  if not eqcar(m,'list) then typerr(m,"moideal")
  else for each x in cdr m collect dp_lmon dp_from_a x;

symbolic procedure moid_print m; mathprint moid_2a m;

% ------- moideal arithmetics ------------------------

symbolic procedure moid_sum(a,b);
% (Reduced) sum of two (v)moideals.
  moid_red append(a,b);

symbolic procedure moid_intersect(a,b);
% Intersection of two (pure !) moideals.
  begin scalar c;
  while b do
    << c:=nconc(for each x in a collect mo_lcm(x,car b),c);
       b:=cdr b
    >>;
  return moid_red c
  end;

symbolic procedure moid_sort m;
% Sorting by descending (pure) lexicographic order, first by mo_comp.
   sort(m,function mo_dlexcomp);

symbolic procedure moid_red m;
% Returns a minimal generating set of the (v)moideal m.
  moid!=red moid_sort m;

symbolic procedure moid!=red m;
  begin scalar v;
  while m do
    << if not moid_member(car m,cdr m) then v:=car m . v;
       m:=cdr m;
    >>;
  return reversip v;
  end;

symbolic procedure moid_member(mo,m);
% true <=> c \in m vdivides mo.
  if null m then nil
  else mo_vdivides!?(car m,mo) or moid_member(mo,cdr m);

symbolic procedure moid_radical u;
% Returns the radical of the (pure) moideal u.
  moid_red for each x in u collect mo_radical x;

symbolic procedure moid_quot(m,x);
% The quotient of the moideal m by the monomial x.
  moid_red for each u in m collect mo_diff(u,mo_gcd(u,x));

% --------------- moideal prime decomposition --------------
% Returns the minimal primes of the moideal m as a list of variable
% lists.

symbolic procedure moid_primes m;
  begin scalar c,m1,m2;
    m:=listminimize(for each x in m collect mo_support x,
                function subsetp);
    for each x in m do
        if length x=1 then m1:=car x . m1
        else m2:=x . m2;
    return for each x in moid!=primes(m2,ring_names cali!=basering)
        collect append(m1,x);
  end;

symbolic procedure moid!=primes(m,vars);
  if null m then list nil
  else begin scalar b,c,vars1; b:=t;
    for each x in m do b:=b and intersection(x,vars);
    if not b then return nil;
    return listminimize(
        for each x in intersection(car m,vars) join
        for each y in moid!=primes(moid!=sps(x,cdr m),
              vars:=delete(x,vars)) collect x . y,
        function subsetp);
  end;

symbolic procedure moid!=sps(x,m);
  for each y in m join if not memq(x,y) then {y};


% ------------ (Strongly) independent sets -----------------

symbolic procedure moid_max l;
  if null l then nil
  else car sort(l,function (lambda(x,y);length x >= length y));

symbolic procedure indepvarsets!* m;
% Returns the sets of (strongly) independent variables for the
% dpmat m. m must be a Groebner basis.
  begin scalar u,n;
    u:=listminimize(
        for each x in moid_from_dpmat m join moid_primes cdr x,
        function subsetp);
    n:=ring_names cali!=basering;
    return for each x in u collect setdiff(n,x);
  end;

% ---------- Dimension and codimension ------------

symbolic procedure dim!* m;
% The dpmat m must be a Groebner basis. Computes the dimension of
% Coker m as the greatest size of a strongly independent set.
  if not eqcar(m,'dpmat) then typerr(m,"DPMAT")
  else length moid_max indepvarsets!* m;

symbolic procedure codim!* m;
  length ring_names cali!=basering - dim!* m;

% ---- An easy independent set procedure -------------

symbolic operator easyindepset;
symbolic procedure easyindepset m;
  if !*mode='symbolic then rederr"only for algebraic mode"
  else makelist easyindepset!* dpmat_from_a reval m;

symbolic procedure easyindepset!* m;
% Returns a maximal with respect to inclusion independent set for the
% moideal m.
  begin scalar b,c,d;
    m:=for each x in m collect mo_support x;
    b:=c:=ring_names cali!=basering;
    for each x in b do if moid!=ept(d:=delete(x,c),m) then c:=d;
    return setdiff(ring_names cali!=basering,c);
  end;

symbolic procedure moid!=ept(l,m);
  if null m then t
  else intersection(l,car m) and moid!=ept(l,cdr m);

symbolic operator easydim;
symbolic procedure easydim m;
  if !*mode='symbolic then rederr"only for algebraic mode"
  else easydim!* dpmat_from_a reval m;

symbolic procedure easydim!* m;
% Returns a lower bound for the dimension. The bound is true for
% unmixed ideals (e.g. primes). m must be a gbasis.
  if not eqcar(m,'dpmat) then typerr(m,"DPMAT")
  else listexpand(function max2,
        for each x in moid_from_dpmat m collect
            length easyindepset!* cdr x);

% ---------- The Hilbert series -------------------

% --- first variant : [BS]

symbolic procedure moid!=hilb1 m;
% Compute the univariate Hilbert series of the moideal m by the rule
% H(m + (M)) = H((M)) - t^ec(m) * H((M):m)
   if null m then dp_fi 1
   else begin scalar m1,m2;
    for each x in m do
        if mo_linear x then m1:=x . m1 else m2:=x . m2;
    if null m2 then return moid!=hilbmon m1
    else if null cdr m2 then return moid!=hilbmon(car m2 . m1)
    else if moid!=powers m2 then return moid!=hilbmon(append(m1,m2))
    else return dp_prod(moid!=hilbmon m1,
            dp_diff(moid!=hilb1 cdr m2,
                    dp_times_mo(mo_convert car m2,
                        moid!=hilb1 moid_quot(cdr m2,car m2))));
    end;

symbolic procedure moid!=hilbmon m;
% Returns the product of the converted dpolys 1 - mo for the
% monomials mo in m.
   if null m then dp_fi 1
   else begin scalar p;
    m:=for each x in m collect
        dp_sum(dp_fi 1,list dp_term(bc_fi(-1),mo_convert x));
    p:=car m;
    for each x in cdr m do p:=dp_prod(p,x);
    return p;
    end;

symbolic procedure moid!=powers m;
% m contains only powers of variables.
  if null m then t
  else (length mo_support car m<2) and moid!=powers cdr m;


% --- Second variant : by induction on the number of variables.

symbolic procedure moid!=hilb2 m;
  if null m then dp_fi 1
   else begin scalar m1,m2,x,p;
    for each x in m do
        if mo_linear x then m1:=x . m1 else m2:=x . m2;
    if null m2 then return moid!=hilbmon m1
    else if null cdr m2 then return moid!=hilbmon(car m2 . m1)
    else if moid!=powers m2 then return moid!=hilbmon(append(m1,m2))
    else begin scalar x;
        x:=mo_from_a car mo_support car m2;
        p:=dp_prod(moid!=hilbmon m1,
            dp_sum(moid!=hilb2 moid_red(x . m2),
            dp_times_mo(mo_convert x,
                moid!=hilb2 moid_quot(m2,x))))
        end;
    return p;
    end;

% -------- Hilbert series from a free resolution --------------

symbolic procedure hilb3 u;
% Hilbert series numerator from the resolution u.
  begin scalar sgn,p; sgn:=t;
  for each x in u do
    << if sgn then p:=dp_sum(p,moid!=hilb3 x)
       else p:=dp_diff(p,moid!=hilb3 x);
       sgn:=not sgn;
    >>;
  return p;
  end;

symbolic procedure moid!=hilb3 u;
% Convert column degrees of the dpmat u to a generating polynomial.
  (if length c = dpmat_cols u then
        dp_compact for each x in c collect
                dp_term(bc_fi 1,mo_convert cdr x)
   else dp_fi max(1,dpmat_cols u))
  where c:=dpmat_coldegs u;

% ------- The common interface ----------------

symbolic procedure hilb(m,fn);
% Returns the (univariate) Hilbert series numerator of the dpmat m as
% a dpoly using the internal Hilbert series computation fn for
% moideals. m must be a Groebner basis.
  if dpmat_cols m = 0 then apply1(fn,moid_from_bas dpmat_list m)
  else (begin scalar w,lt,p,p1; integer i;
    lt:=moid_from_dpmat m;
    for i:=1:dpmat_cols m do
      << p1:=atsoc(i,lt);
         if null p1 then rederr"HILB with wrong leading term list"
         else p1:=apply1(fn,cdr p1);
         w:=atsoc(i,cali!=degrees);
         if w then p1:=dp_times_mo(mo_convert cdr w,p1);
         p:=dp_sum(p,p1);
       >>;
    return p;
    end) where cali!=degrees:=dpmat_coldegs m;


symbolic procedure hilb1 m; hilb(m,function moid!=hilb1);

symbolic procedure hilb2 m; hilb(m,function moid!=hilb2);

symbolic procedure moid!=hilb2hs h;
% Converts the Hilbert series numerator h into a rational expression
% with denom = prod ( 1-x^k | k in ecart vector )
% and cancels common factors. Returns a s.q.
  begin scalar g,x,den,num;
  x:=car ring_names cali!=basering;
  num:=numr simp dp_2a h;       % This is the numerator as a s.f.
  den:=1;
  for each n in ring_ecart cali!=basering do
        den:=multf(den,(((x.n).-1).1));
                                % This is the denominator as a s.f.
  g:=gcdf!*(num,den);
  return quotf(num,g) ./ quotf(den,g);
  end;

symbolic procedure hilbseries1 m; moid!=hilb2hs hilb1 m;
% m must be a Gbasis.

symbolic procedure hilbseries2 m; moid!=hilb2hs hilb2 m;
% m must be a Gbasis.

symbolic procedure hilbseries3 u; moid!=hilb2hs hilb3 u;
% u must be a resolution.

% ------------- Multiplicity ---------------------

symbolic procedure moid_hf2mult n;
% Get the sum of the coefficients of the s.f. (car n).
% This is the multiplicity, if n is a HF.
  (prepf absf if numberp f then f
   else car subf(f,list (mvar f . 1))) where f=car n;

symbolic procedure moid_hf2dim f;
% Returns the dimension as the pole order at 1 of the HF f.
  if domainp denr f then 0
  else begin scalar g,x,d; integer n;
    f:=denr f; x:=mvar f; n:=0; d:=(((x.1).-1).1);
    while null cdr (g:=qremf(f,d)) do
        << n:=n+1; f:=car g >>;
    return n;
    end;

symbolic procedure degree!* m; moid_hf2mult hilbseries1 m;

endmodule; % moid


module res;


COMMENT

          ######################
          ###                ###
          ###   RESOLUTIONS  ###
          ###                ###
          ######################

This module contains algorithms on complexes, i.e. chains of modules
(submodules of free modules represented as im f of certain dpmat's).

A chain (in particular a resolution) is a list of dpmat's with the
usual annihilation property of subsequent dpmat's.

This module contains

        - An algorithm to compute a minimal resolution of a dpmat,

        - the same for a local dpmat, using either the Simp or the
                Lazy strategy,

        - the extraction of the (graded) Betti numbers from a
                resolution.

This module is just under development.

END COMMENT;

% ------------- Minimal resolutions --------------

symbolic procedure Resolve!*(m,d);
% Compute a minimal resolution of the dpmat m, i.e. a list of dpmat's
% (s0 s1 s2 ...), where sk is the k-th syzygy module of m, upto the
% d'th part.
  (begin scalar a,u;
  if dpmat_cols m=0 then
    << cali!=degrees:=nil; m:=ideal2mat!* m>>
  else cali!=degrees:=dpmat_coldegs m;
  a:=list(m); u:=syzygies!* m;
  while (not dpmat_zero!? u)and(d>1) do
    << m:=u; u:=syzygies!* m; d:=d-1;
       u:=groeb_minimize(m,u); m:=car u; u:=cdr u; a:=m . a;
    >>;
  return reversip (u.a);
  end) where cali!=degrees:=cali!=degrees;

% ----------------- The Betti numbers -------------

symbolic procedure bettiNumbers!* c;
% Returns the list of Betti numbers of the chain c.
   for each x in c collect dpmat_cols x;

symbolic procedure gradedBettiNumbers!* c;
% Returns the list of degree lists (according to the ecart) of the
% generators of the chain c.
  for each x in c collect
     begin scalar i,d; d:=dpmat_coldegs x;
        return
    if d then sort(for each y in d collect mo_ecart cdr y,'leq)
        else for i:=1:dpmat_cols x collect 0;
     end;

endmodule; % res


module intf;

COMMENT

            #####################################
            ###                               ###
            ###  INTERFACE TO ALGEBRAIC MODE  ###
            ###                               ###
            #####################################


  There are two types of procedures :

  The first type takes polynomial lists or polynomial matrices as
  input, converts them into dpmats, computes the result and
  reconverts it to algebraic mode.

  The second type is property driven, i.e. Basis, Gbasis, Syzygies
  etc. are attached via properties to an identifier.
  For them, the 'ring property watches, that cali!=basering hasn't
  changed (including the term order). Otherwise the results must be
  reevaluated using setideal(name,name) or setmodule(name,name) since
  otherwise results may become wrong.

   The switch "noetherian" controls whether the term order satisfies
   the chain condition (default is "on") and chooses either the
   groebner algorithm or the local standard basis algorithm.

END COMMENT;

% ----- The properties managed upto now ---------

fluid '(intf!=properties);

intf!=properties:='(basis ring gbasis syzygies resolution
                hilbertseries independentsets);

% --- Some useful common symbolic procedures --------------

symbolic procedure intf!=clean u;
% Removes all properties.
  for each x in intf!=properties do remprop(u,x);

symbolic procedure intf_test m;
  if (length m neq 1)or(not idp car m) then typerr(m,"identifier");

symbolic procedure intf_get m;
% Get the 'basis.
  begin scalar c;
  if not (c:=get(m,'basis)) then typerr(m,"dpmat variable");
  if not equal(get(m,'ring),cali!=basering) then
                rederr"invalid base ring";
  cali!=degrees:=dpmat_coldegs c;
  return c;
  end;

symbolic procedure intf!=set(m,v);
% Attach the dpmat value v to the variable m.
  << put(m,'ring,cali!=basering);
     put(m,'basis,v);
     if dpmat_cols v = 0 then
       << put(m,'rtype,'list); put(m,'avalue,'list.{dpmat_2a v})>>
     else
       <<put(m,'rtype,'matrix); put(m,'avalue,'matrix.{dpmat_2a v})>>;
  >>;

% ------ setideal -------------------

put('setideal,'psopfn,'intf!=setideal);
symbolic procedure intf!=setideal u;
% setideal(name,base list)
  begin scalar l;
  if length u neq 2 then rederr "Syntax : setideal(identifier,ideal)";
  if not idp car u then typerr(car u,"ideal name");
  l:=reval cadr u;
  if not eqcar(l,'list) then typerr(l,"ideal basis");
  intf!=clean(car u);
  put(car u,'ring,cali!=basering);
  put(car u,'basis,l:=dpmat_from_a l);
  put(car u,'avalue,'list.{l:=dpmat_2a l});
  put(car u,'rtype,'list);
  return l;
  end;

% --------------- setmodule -----------------------

put('setmodule,'psopfn,'intf!=setmodule);
symbolic procedure intf!=setmodule u;
% setmodule(name,matrix)
  begin scalar l;
  if length u neq 2 then
        rederr "Syntax : setmodule(identifier,module basis)";
  if not idp car u then typerr(car u,"module name");
  l:=reval cadr u;
  if not eqcar(l,'mat) then typerr(l,"module basis");
  intf!=clean(car u);
  put(car u,'ring,cali!=basering);
  put(car u,'basis,dpmat_from_a l);
  put(car u,'avalue,'matrix.{l});
  put(car u,'rtype,'matrix);
  return l;
  end;

% ------------ setring ------------------------

put('setring,'psopfn,'intf!=setring);
% Setring(vars,term order degrees,tag <,ecart>) sets the internal
% variable cali!=basering. The term order is at first by the degrees
% and then by the tag. The tag must be LEX or REVLEX.
% If ecart is not supplied the ecart is set to the default, i.e. the
% first degree vector (noetherian degree order) or to (1 1 .. 1).
% The ring may also be supplied as a list of its arguments as e.g.
% output by "getring".
symbolic procedure intf!=setring u;
  begin
  if length u = 1 then u:=cdr reval car u;
  if not memq(length u,'(3 4)) then
    rederr "Syntax : setring(vars,term order,tag[,ecart])";
  setring!* ring_from_a ('list . u);
  return ring_2a cali!=basering;
  end;

% ----------- getring --------------------

put('getring,'psopfn,'intf!=getring);
% Get the base ring of an object as the algebraic list
% {vars,tord,tag,ecart}.

symbolic procedure intf!=getring u;
  if null u then ring_2a cali!=basering
  else begin scalar c; c:=get(car u,'ring);
    if null c then typerr(car u,"dpmat variable");
    return ring_2a c;
    end;


% ------- The algebraic interface -------------

symbolic operator ideal2mat;
symbolic procedure ideal2mat m;
% Convert the list of polynomials m into a matrix column.
  if !*mode='symbolic then rederr"only for algebraic mode"
  else if not eqcar(m,'list) then typerr(m,'list)
  else 'mat . for each x in cdr m collect {x};

put('flatten,'psopfn,'cali!-flatten);

symbolic procedure cali!-flatten m;
% Flatten the matrix in car(m).
  (if !*mode='symbolic then rederr"only for algebraic mode"
    else if not eqcar(m,'mat) then typerr(m,'matrix)
    else 'list . for each x in cdr m join for each y in x collect y)
  where m = reval car m;

put('setgbasis,'psopfn,'intf!=setgbasis);
symbolic procedure intf!=setgbasis m;
% Say that the basis is already a Gbasis.
  begin scalar c;
  intf_test m; m:=car m; c:=intf_get m;
  put(m,'gbasis,c);
  return reval m;
  end;

symbolic operator setdegrees;
symbolic procedure setdegrees m;
% Set a term list as actual column degrees. Execute this before
% setmodule to supply a module with prescribed column degrees.
  if !*mode='symbolic then rederr"only for algebraic mode"
  else begin scalar i,b;
  b:=moid_from_a reval m; i:=0;
  cali!=degrees:= for each x in b collect <<i:=i+1; i . x>>;
  return moid_2a for each x in cali!=degrees collect cdr x;
  end;

put('getdegrees,'psopfn,'intf!=getdegrees);
symbolic procedure intf!=getdegrees m;
  begin
  if m then <<intf_test m; intf_get car m>>;
  return moid_2a for each x in cali!=degrees collect cdr x
  end;

symbolic operator getecart;
symbolic procedure getecart;
  if !*mode='symbolic then rederr"only for algebraic mode"
  else makelist ring_ecart cali!=basering;

put('gbasis,'psopfn,'intf!=gbasis);
symbolic procedure intf!=gbasis m;
  begin scalar c,c1;
  intf_test m; m:=car m; c1:=intf_get m;
  if (c:=get(m,'gbasis)) then return dpmat_2a c;
  c:=gbasis!* c1;
  put(m,'gbasis,c);
  return dpmat_2a c;
  end;

symbolic operator setmonset;
symbolic procedure setmonset m;
  if !*mode='symbolic then rederr"only for algebraic mode"
  else makelist setmonset!* cdr reval m;

symbolic procedure setmonset!* m;
  if subsetp(m,ring_names cali!=basering) then cali!=monset:=m
  else typerr(m,"monset list");

symbolic operator getmonset;
symbolic procedure getmonset(); makelist cali!=monset;

put('resolve,'psopfn,'intf!=resolve);
symbolic procedure intf!=resolve m;
  begin scalar c,c1,d;
  intf_test m; if length m=2 then d:=reval cadr m else d:=100;
  m:=car m; c1:=intf_get m;
  if ((c:=get(m,'resolution)) and (car c >= d)) then
        return makelist for each x in cdr c collect dpmat_2a x;
  c:=Resolve!*(c1,d);
  put(m,'resolution,d.c);
  if not get(m,'syzygies) then put(m,'syzygies,cadr c);
  return makelist for each x in c collect dpmat_2a x;
  end;

put('syzygies,'psopfn,'intf!=syzygies);
symbolic procedure intf!=syzygies m;
  begin scalar c,c1;
  intf_test m; m:=car m; c1:=intf_get m;
  if (c:=get(m,'syzygies)) then return dpmat_2a c;
  c:=syzygies!* c1;
  put(m,'syzygies,c);
  return dpmat_2a c;
  end;

put('indepvarsets,'psopfn,'intf!=indepvarsets);
symbolic procedure intf!=indepvarsets m;
  begin scalar c;
  intf_test m; m:=car m; intf_get m;
  if (c:=get(m,'independentsets)) then
    return makelist for each x in c collect makelist x;
  if not (c:=get(m,'gbasis)) then rederr"Compute Gbasis first";
  c:=indepvarsets!* c;
  put(m,'independentsets,c);
  return makelist for each x in c collect makelist x;
  end;

put('getleadterms,'psopfn,'intf_getleadterms);
symbolic procedure intf_getleadterms m;
  begin scalar c;
  intf_test m; m:=car m; intf_get m;
  if not (c:=get(m,'gbasis)) then rederr"Compute Gbasis first";
  c:=getleadterms!* c;
  return dpmat_2a c;
  end;

put('hilbseries,'psopfn,'intf!=hilbseries);
symbolic procedure intf!=hilbseries m;
% Returns the Hilbert series of m.
  begin scalar c;
  intf_test m; m:=car m; intf_get m;
  if (c:=get(m,'hilbertseries)) then return mk!*sq c;
  if not(c:=get(m,'gbasis)) then rederr"Compute Gbasis first"
  else c:=hilbseries1 c;
  put(m,'hilbertseries,c);
  return mk!*sq c;
  end;

put('degree,'psopfn,'intf_getmult);
symbolic procedure intf_getmult m;
% Returns the multiplicity of m.
  begin scalar c;
  intf_test m; m:=car m; intf_get m;
  if (c:=get(m,'hilbertseries)) then return moid_hf2mult c;
  if not(c:=get(m,'gbasis)) then rederr"Compute Gbasis first"
  else c:=hilbseries1 c;
  put(m,'hilbertseries,c);
  return moid_hf2mult c;
  end;

put('dim,'psopfn,'intf!=dim);
put('codim,'psopfn,'intf!=codim);
symbolic procedure intf!=dim m;
% Returns the dimension of coker m.
  begin scalar c;
  intf_test m; m:=car m; intf_get m;
  if (c:=get(m,'hilbertseries)) then return moid_hf2dim c;
  if (c:=get(m,'independentsets)) then return length moid_max c;
  if not(c:=get(m,'gbasis)) then rederr"Compute Gbasis first"
  else << c:=indepvarsets!* c; put(m,'independentsets,c);
        c:=length moid_max c;
       >>;
  return c;
  end;

symbolic procedure intf!=codim m;
% Returns the codimension of coker m.
  length ring_names cali!=basering - intf!=dim m;

put('BettiNumbers,'psopfn,'intf!=BettiNumbers);
symbolic procedure intf!=BettiNumbers m;
  begin scalar c;
  intf_test m; m:=car m; intf_get m;
  if (c:=get(m,'resolution)) then return makelist BettiNumbers!* cdr c
  else rederr"Compute a resolution first";
  end;

put('GradedBettiNumbers,'psopfn,'intf!=GradedBettiNumbers);
symbolic procedure intf!=GradedBettiNumbers m;
  begin scalar c;
  intf_test m; m:=car m; intf_get m;
  if (c:=get(m,'resolution)) then return
    makelist for each x in GradedBettiNumbers!* cdr c collect makelist x
  else rederr"Compute a resolution first";
  end;

put('degsfromresolution,'psopfn,'intf!=degsfromresolution);
symbolic procedure intf!=degsfromresolution m;
  begin scalar c;
  intf_test m; m:=car m;
  if not equal(get(m,'ring),cali!=basering) then
        rederr"invalid base ring";
  if not (c:=get(m,'resolution)) then
        rederr"compute a resolution first";
  return makelist for each x in cdr c collect
            moid_2a for each y in dpmat_coldegs x collect cdr y;
  end;

symbolic operator sieve;
symbolic procedure sieve(m,vars);
% Sieve out all base elements from m containing one of the variables
% in vars in their leading term.
  if !*mode='symbolic then rederr"only for algebraic mode"
  else dpmat_2a dpmat_sieve(dpmat_from_a reval m,cdr vars);

endmodule; % intf

module odim;

COMMENT

Applications to zerodimensional ideals and modules.

END COMMENT;

% -------------- Test for zero dimension -----------------
% For a true answer m must be a gbasis.

put('dimzerop,'psopfn,'odim!=zerop);
symbolic procedure odim!=zerop m;
  begin scalar c;
  intf_test m; intf_get(m:=car m);
  if not (c:=get(m,'gbasis)) then rederr"Compute Gbasis first";
  if dimzerop!* c then return 'yes else return 'no;
  end;

symbolic procedure dimzerop!* m; null odim_parameter m;

symbolic procedure odim_parameter m;
% Return a parameter of the dpmat m or nil, if it is zerodimensional
% or (1).
  odim!=parameter moid_from_dpmat m;

symbolic procedure odim!=parameter m;
  if null m then nil
  else odim!=parameter1 cdar m or odim!=parameter cdr m;

symbolic procedure odim!=parameter1 m;
  if null m then car reverse ring_names cali!=basering
  else if mo_zero!? car m then nil
  else begin scalar b,u;
  u:=for each x in m join if length(b:=mo_support x)=1 then b;
  b:=reverse ring_names cali!=basering;
  while b and member(car b,u) do b:=cdr b;
  return if b then car b else nil;
  end;

% --- Get a k-base of F/M as a list of monomials ----
% m must be a gbasis for the correct result.

put('getkbase,'psopfn,'odim!=evkbase);
symbolic procedure odim!=evkbase m;
  begin scalar c;
  intf_test m; intf_get(m:=car m);
  if not (c:=get(m,'gbasis)) then rederr"Compute Gbasis first";
  return moid_2a getkbase!* c;
  end;

symbolic procedure getkbase!* m;
  if not dimzerop!* m then rederr"dpmat not zerodimensional"
  else for each u in moid_from_dpmat m join
        odim!=kbase(mo_from_ei car u,ring_names cali!=basering,cdr u);

symbolic procedure odim!=kbase(mo,n,m);
  if moid_member(mo,m) then nil
  else mo . for each x on n join
                odim!=kbase(mo_inc(mo,car x,1),append(x,nil),m);

% --- Produce an univariate polynomial inside the ideal m ---

symbolic procedure odim_up(a,m);
% Returns a univariate polynomial (of smallest possible degree if m
% is a gbasis) in the variable a inside the zerodimensional ideal m.
% Uses Buchberger's approach.
  if dpmat_cols m>0 or not dimzerop!* m then
      rederr"univariate polynomials only for zerodimensional ideals"
  else if not member(a,ring_names cali!=basering) then
    typerr(a,"variable name")
  else if null matop_pseudomod(dp_fi 1,m) then dp_fi 1
  else begin scalar b,v,p,l,q,r;
    % l is a list of ( p(a) . NF p(a) ), sorted by lt NF p(a)
    p:=(dp_fi 1 . dp_fi 1); b:=dpmat_list m;  v:=mo_from_a a;
    while cdr p do
      << l:=merge(list p,l,function odim!=greater);
         q:=dp_times_mo(v,car p);
         r:=red_redpol(b,bas_make(0,dp_times_mo(v,cdr p)));
         p:=odim!=reduce(dp_prod(cdr r,q) . bas_dpoly car r,l);
      >>;
    return
    if !*bcsimp then car dp_simp car p
    else car p;
    end;

symbolic procedure odim!=greater(a,b);
    mo_compare(dp_lmon cdr a,dp_lmon cdr b)=1;

symbolic procedure odim!=reduce(a,l);
  if null cdr a or null l or odim!=greater(a, car l) then a
  else if mo_equal!?(dp_lmon cdr a,dp_lmon cdar l) then
    begin scalar z,z1,z2,b;
    b:=car l; z1:=bc_neg dp_lc cdr a; z2:=dp_lc cdr b;
    if !*bcsimp then
      << if (z:=bc_inv z1) then <<z1:=bc_fi 1; z2:=bc_prod(z2,z)>>
         else
           << z:=bc_gcd(z1,z2);
              z1:=car bc_divmod(z1,z);
              z2:=car bc_divmod(z2,z);
           >>;
      >>;
    a:=dp_sum(dp_times_bc(z2,car a),dp_times_bc(z1,car b)) .
           dp_sum(dp_times_bc(z2,cdr a),dp_times_bc(z1,cdr b));
    return odim!=reduce(a,cdr l)
    end
  else odim!=reduce(a,cdr l);

endmodule; % odim

module prime;

COMMENT

        ####################################
        #                                  #
        #  PRIME DECOMPOSITION, RADICALS,  #
        #        AND RELATED PROBLEMS      #
        #                                  #
        ####################################


This module contains algorithms

    - for zerodimensional ideals :
            - to test whether it is radical
            - to compute its radical
            - for a primality test

    - for zerodimensional ideals and modules :
            - to compute its primes
            - to compute its primary decomposition

    - for arbitrary ideals :
            - for a primality test
            - to compute its radical
            - to test whether it is radical

    - for arbitrary ideals and modules :
        - to compute its isolated primes
        - to compute its primary decomposition and
            the associated primes
        - a shortcut for the primary decomposition
            computation for unmixed modules

The algorithms follow

        Seidenberg : Trans. AMS 197 (1974), 273 - 313.

        Kredel : in Proc. EUROCAL'87, Lecture Notes in Comp. Sci. 378
                (1986), 270 - 281.

        Gianni, Trager, Zacharias :
                J. Symb. Comp. 6 (1988), 149 - 167.

with essential modifications for modules as e.g. presented in

        Rutman : J. Symb. Comp. 14 (1992), 483 - 503


END COMMENT;

% ------ The radical of a zerodimensional ideal -----------

symbolic procedure prime!=mksqrfree(pol,x);
% Make the univariate dpoly p(x) squarefree.
  begin scalar p,q;
    p:=numr simp dp_2a pol;
    q:=numr simp dp_2a dp_df(pol,x);
    return dp_from_a prepf car qremf(p,gcdf!*(p,q))
    end;

put('zeroradical,'psopfn,'prime!=evzero);
symbolic procedure prime!=evzero m;
  begin scalar c;
  intf_test m; intf_get(m:=car m);
  if not (c:=get(m,'gbasis)) then rederr"Compute Gbasis first";
  return dpmat_2a zeroradical!* c;
  end;

symbolic procedure zeroradical!* m;
% Returns the radical of the zerodim. ideal m. m must be a gbasis.
  if dpmat_cols m>0 or not dimzerop!* m then
        rederr"ZERORADICAL only for zerodimensional ideals"
  else if null matop_pseudomod(dp_fi 1,m) then m
  else begin scalar u;
    u:=for each x in ring_names cali!=basering collect
        bas_make(0,prime!=mksqrfree(odim_up(x,m),x));
    u:=dpmat_make(length u,0,bas_renumber u,nil);
    return gbasis!* matsum!* {m,u};
    end;

put('iszeroradical,'psopfn,'prime!=eviszero);
symbolic procedure prime!=eviszero m;
  begin scalar c;
  intf_test m; intf_get(m:=car m);
  if not (c:=get(m,'gbasis)) then rederr"Compute Gbasis first";
  return if iszeroradical!* c then 'yes else 'no;
  end;

symbolic procedure iszeroradical!* m;
% Test whether the zerodim. ideal m is radical. m must be a gbasis.
  if dpmat_cols m>0 or not dimzerop!* m then
        rederr"ISZERORADICAL only for zerodimensional ideals"
  else if null matop_pseudomod(dp_fi 1,m) then t
  else begin scalar u,isradical;
    isradical:=t;
    for each x in ring_names cali!=basering do
        isradical:=isradical and
            null matop_pseudomod(prime!=mksqrfree(odim_up(x,m),x),m);
    return isradical;
    end;

% ---- The primes of a zerodimensional ideal or module ------

symbolic operator zeroprimes;
symbolic procedure zeroprimes m;
  if !*mode='symbolic then rederr"only for algebraic mode"
  else makelist for each x in
        zeroprimes!* dpmat_from_a reval m collect dpmat_2a x;

symbolic procedure zeroprimes!* m;
% The primes of the zerodimensional ideal Ann F/M.
% The unit ideal has no primes.
  listminimize(
        for each x in prime!=zeroprimes1 gbasis!* annihilator2!* m
                join prime!=zeroprimes2 x,
        function submodulep!*)  ;

symbolic procedure prime_iszeroprime m;
% Test a zerodimensiomal ideal to be prime. m must be a gbasis.
  if dpmat_cols m>0 or not dimzerop!* m then
    rederr "iszeroprime only for zerodimensional ideals"
  else if null matop_pseudomod(dp_fi 1,m) then
    rederr"the ideal is the unit ideal"
  else prime!=iszeroprime1 m and prime!=iszeroprime2 m;

symbolic procedure prime!=zeroprimes1 m;
% A first approximation to the isolated primes in dim=0.
  if dpmat_cols m>0 then rederr"only for ideals"
  else if null matop_pseudomod(dp_fi 1,m) then nil
  else if not dimzerop!* m then
        rederr"ZEROPRIMES only for zerodimensional ideals or modules"
  else prime!=zeroprimes1a(ring_names cali!=basering,list m);

symbolic procedure prime!=zeroprimes1a(vars,l);
% vars=var. names, l=list of dpmats. Find recursively the factors
% of the univariate polynomial in x=car vars for each u in l and
% split up with them the elements of l, removing unit ideals.
  if null vars then l
  else begin scalar x,u;
    x:=car vars;
    u:=for each m in prime!=zeroprimes1a(cdr vars,l) join
        for each y in
          cdr ((fctrf numr simp dp_2a odim_up(x,m)) where !*factor=t)
            collect matsum!* {m,
                    dpmat_make(1,0,
                        list bas_make(1,dp_from_a prepf car y),
                    nil)};
    u:=for each x in u collect gbasis!* x;
    return for each x in u join if matop_pseudomod(dp_fi 1,x) then {x};
    end;

symbolic procedure prime!=iszeroprime1 m;
% A first non primality test.
  if dpmat_cols m>0 or not dimzerop!* m then
        rederr"iszeroprime only for zerodimensional ideals"
  else prime!=iszeroprime1a(ring_names cali!=basering,m);

symbolic procedure prime!=iszeroprime1a(vars,m);
% vars=var. names, l=list of dpmats. Recursively try to factor the
% univariate polynomial in x=car vars for m
  if null vars then t
  else begin scalar u;
    if (length(u:=cdr ((fctrf numr simp dp_2a odim_up(car vars,m))
                                where !*factor=t))>1)
        or (cdar u>1) then return nil
    else return prime!=iszeroprime1a(cdr vars,m);
    end;

symbolic procedure prime_gpchange(vars,v,m);
% Change to general position with respect to v. Only for pure lex.
% term order and radical ideal m.
  if null vars then m
  else if null matop_pseudomod(dp_fi 1,m) then m
  else begin scalar s,x,a;
    s:=0; x:=mo_from_a car vars;
    a:=list (v.prepf addf(!*k2f v,!*k2f car vars));
            % the substitution rule v -> v + x .
    while not member(x,moid_from_bas dpmat_list m)
                % i.e. m has a leading term equal to x
        and ((s:=s+1) < 10)
                % to avoid too much loops.
        do m:=gbasis!* dpmat_sub(a,m);
    if s=10 then rederr" change to general position failed";
    return prime_gpchange(cdr vars,v,m);
    end;

symbolic procedure prime!=zeroprimes2 m;
% Decompose the radical zerodimensional dmpat ideal m using a general
% position argument.
  (begin scalar c,v,vars,u,d,r,vars1;
    c:=cali!=basering; vars:=ring_names c; v:=gensym();
    u:=moid_from_bas dpmat_list m;
    vars1:=for each x in vars join
                if not member(mo_from_a x,u) then {x};
    if (length vars1)=1 then return prime!=zeroprimes3(m,first vars1);
    if ring_tag c='revlex then % for proper ring_sum redefine it.
        r:=ring_define(vars,ring_degrees c,'lex,ring_ecart c)
    else r:=c;
    setring!* ring_sum(r,ring_define(list v,nil,'lex,'(1)));
    cali!=degrees:=nil;
    m:=gbasis!* matsum!* {dpmat_neworder m,
        dpmat_make(1,0,list bas_make(1,dp_from_a v),nil)};
    if matop_pseudomod(dp_fi 1,m) then
      << m:=prime_gpchange(vars1,v,m);
         u:=for each x in prime!=zeroprimes3(m,v) join
             if matop_pseudomod(dp_fi 1,x) and
                matop_pseudomod(dp_fi 1,d:=eliminate!*(x,{v})) then {d}
                    % To recognize (1) even if x is not a gbasis.
      >>;
    setring!* c;
    return for each x in u collect interreduce!* dpmat_neworder x;
   end)
   where cali!=degrees:=cali!=degrees,
                cali!=basering:=cali!=basering;

symbolic procedure prime!=zeroprimes3(m,v);
% m is in general position with univariate polynomial in v.
  begin scalar u,p;
  u:=dpmat_list m;
  while u and not equal(mo_support dp_lmon (p:=bas_dpoly car u),
                        list v) do u:=cdr u;
  if null u then rederr"univariate polynomial not found";
  p:=for each x in cdr ((fctrf numr simp dp_2a p) where !*factor=t)
        collect dpmat_make(1,0,
                    list bas_make(1,dp_from_a prepf car x),nil);
  return for each x in p collect matsum!* {m,x};
  end;

symbolic procedure prime!=iszeroprime2 m;
% Test the radical zerodimensional dmpat ideal m to be prime using a
% general position argument.
  (begin scalar c,v,vars,u,r;
    c:=cali!=basering; vars:=ring_names c; v:=gensym();
    if ring_tag c='revlex then % for proper ring_sum redefine it.
        r:=ring_define(vars,ring_degrees c,'lex,ring_ecart c)
    else r:=c;
    setring!* ring_sum(r,ring_define(list v,nil,'lex,'(1)));
    cali!=degrees:=nil;
    m:=matsum!* {dpmat_neworder m,
        dpmat_make(1,0,list bas_make(1,dp_from_a v),nil)};
    m:=prime_gpchange(vars,v,gbasis!* m);
    u:=prime!=iszeroprime3(m,v);
    setring!* c; return u;
   end)
   where cali!=degrees:=cali!=degrees,
                cali!=basering:=cali!=basering;

symbolic procedure prime!=iszeroprime3(m,v);
  begin scalar u,p;
  u:=dpmat_list m;
  while u and not equal(mo_support dp_lmon (p:=bas_dpoly car u),
                        list v) do u:=cdr u;
  if null u then rederr"univariate polynomial not found";
  if (length(u:=cdr ((fctrf numr simp dp_2a p) where !*factor=t))>1)
        or (cdar u>1) then return nil
  else return t
  end;

% - The primary decomposition of a zerodimensional ideal or module -

symbolic procedure prime_polynomial l;
% l is a list of (gbases of) prime ideals.
% Returns a list of (p . f) with p \in l and dpoly f \in all q \in l
% except p.
  for each x in l collect (x . prime!=polynomial(x,delete(x,l)));

symbolic procedure prime!=polynomial(x,l);
% Returns a dpoly f inside all q \in l and outside x.
  if null l then dp_fi 1
  else begin scalar u,p,q;
    p:=prime!=polynomial(x,cdr l);
    if null matop_pseudomod(p,car l) then return p;
    u:=dpmat_list car l;
    while u and null matop_pseudomod(q:=bas_dpoly car u,x) do u:=cdr u;
    if null u then
        rederr"prime ideal separation failed"
    else return dp_prod(p,q);
  end;

symbolic operator zeroprimarydecomposition;
symbolic procedure zeroprimarydecomposition m;
% Returns a list of {Q,p} with p a prime ideal and Q a p-primary
% component of m. For m=S^c the list is empty.
  if !*mode='symbolic then rederr"only for algebraic mode"
  else makelist
  for each x in zeroprimarydecomposition!* dpmat_from_a reval m
        collect makelist {dpmat_2a first x,dpmat_2a second x};

symbolic procedure zeroprimarydecomposition!* m;
% The symbolic counterpart, returns a list of {Q,p}. m is not
% assumed to be a gbasis.
    if not dimzerop!* m then rederr
 "zeroprimarydecomposition only for zerodimensional ideals or modules"
    else for each f in prime_polynomial
            (for each y in zeroprimes!* m collect gbasis!* y)
        collect {matqquot!*(m,cdr f),car f};

% --------- Primality test for an arbitrary ideal. ---------

put('isprime,'psopfn,'prime!=isprime);
symbolic procedure prime!=isprime m;
  begin scalar c;
    intf_test m; intf_get(m:=car m);
    if not (c:=get(m,'gbasis)) then rederr"Compute Gbasis first";
    return if isprime!* c then 'yes else 'no;
  end;

symbolic procedure isprime!* m;
% Test an dpmat ideal m to be prime. m must be a gbasis.
  if dpmat_cols m>0 then rederr"prime test only for ideals"
  else (begin scalar vars,u,v,c1,c2,m1,m2,lc;
    v:=moid_max indepvarsets!* m; cali!=degrees:=nil;
    if null v then return prime_iszeroprime m;
    vars:=ring_names(c1:=cali!=basering);
        % Change to dimension zero.
    u:=setdiff(ring_names c1,v);
    setring!*
        ring_define(vars,ring_rlp(c1,u),ring_tag c1,ring_ecart c1);
    m1:=dpmat_2a gbasis!* dpmat_neworder m;
    setring!*(c2:= ring_define(u,degreeorder!* u,'revlex,
                        for each x in u collect 1));
    m1:=groeb_mingb dpmat_from_a m1;
    if null matop_pseudomod(dp_fi 1,m1) then
      << setring!* c1; rederr"Input must be a gbasis" >>;
    lc:=bc_2a prime!=quot m1; setring!* c1;
        % Test recontraction of m1 to be equal to m.
    m2:=matqquot!*(m,dp_from_a lc);
    if not submodulep!*(m2,m) then return nil;
        % Test the zerodimensional ideal m1 to be prime
    setring!* c2; u:=prime_iszeroprime m1; setring!* c1;
    return u;
   end)
   where cali!=degrees:=cali!=degrees,
                cali!=basering:=cali!=basering;

symbolic operator isolatedprimes;
symbolic procedure isolatedprimes m;
  if !*mode='symbolic then rederr"only for algebraic mode"
  else makelist
    for each x in isolatedprimes!* dpmat_from_a reval m collect
        dpmat_2a x;

symbolic procedure isolatedprimes!* m;
% Returns the isolated primes of the dpmat m as a dpmat list.
  prime!=isoprimes gbasis!* annihilator2!* m;

symbolic procedure prime!=isoprimes m;
% m is a gbasis and an ideal.
  (begin scalar u,c,v,vars,m1,m2,l,p;
    if null(v:=odim_parameter m) then return
        for each x in prime!=zeroprimes1 m join prime!=zeroprimes2 x;
    vars:=ring_names(c:=cali!=basering); cali!=degrees:=nil;
    u:=delete(v,vars);
    setring!* ring_define(vars,ring_rlp(c,u),ring_tag c,ring_ecart c);
    m1:=dpmat_2a gbasis!* dpmat_neworder m;
    setring!* ring_define(u,degreeorder!* u,
                        'revlex,for each x in u collect 1);
    p:=bc_2a prime!=quot(m1:=groeb_mingb dpmat_from_a m1);
    l:=for each x in prime!=isoprimes m1 collect
            (dpmat_2a x . bc_2a prime!=quot x);
    setring!* c;
    l:=for each x in l collect
                matqquot!*(dpmat_from_a car x,dp_from_a cdr x);
    if dp_unit!?(p:=dp_from_a p) or
        submodulep!*(matqquot!*(m,p),m) or
        null matop_pseudomod(dp_fi 1,
            m2:=gbasis!* matsum!* {m,dpmat_from_dpoly p})
                then return l
    else return
        listminimize(append(l,prime!=isoprimes  m2),
                        function submodulep!*);
   end)
   where cali!=degrees:=cali!=degrees,
                cali!=basering:=cali!=basering;

symbolic procedure prime!=quot m;
% The lcm of the leading coefficients of m.
  begin scalar p,u;
    u:=for each x in dpmat_list m collect dp_lc bas_dpoly x;
    if null u then return bc_fi 1;
    p:=car u; for each x in cdr u do p:=bc_lcm(p,x);
    return p
  end;

% ----------- The radical -------------
% Returns the radical of the dpmat ideal m.

symbolic operator radical;
symbolic procedure radical m;
  if !*mode='symbolic then rederr"only for algebraic mode"
  else dpmat_2a radical!* gbasis!* dpmat_from_a reval m;

symbolic procedure radical!* m;
% m must be a gbasis.
  if dpmat_cols m>0 then rederr"RADICAL only for ideals"
  else (begin scalar u,c,v,vars,m1,l,p,p1;
    if null(v:=odim_parameter m) then return zeroradical!* m;
    vars:=ring_names (c:=cali!=basering);
    cali!=degrees:=nil; u:=delete(v,vars);
    setring!* ring_define(vars,ring_rlp(c,u),ring_tag c,ring_ecart c);
    m1:=dpmat_2a gbasis!* dpmat_neworder m;
    setring!* ring_define(u,degreeorder!* u,
                        'revlex,for each x in u collect 1);
    p:=bc_2a prime!=quot(m1:=groeb_mingb dpmat_from_a m1);
    l:=radical!* m1; p1:=bc_2a prime!=quot l;
    l:=dpmat_2a l; setring!* c;
    l:=matqquot!*(dpmat_from_a l,dp_from_a p1);
    if dp_unit!?(p:=dp_from_a p) or
    submodulep!*(matqquot!*(m,p),m) then return l
    else << m1:=radical!* gbasis!* matsum!* {m,dpmat_from_dpoly p};
            if submodulep!*(m1,l) then l:=m1
            else if not submodulep!*(l,m1) then
                    l:= matintersect!* {l,m1};
         >>;
    return l;
   end)
   where cali!=degrees:=cali!=degrees,
                cali!=basering:=cali!=basering;

% -- Primary decomposition for modules without embedded components ---

symbolic operator easyprimarydecomposition;
symbolic procedure easyprimarydecomposition m;
  if !*mode='symbolic then rederr"only for algebraic mode"
  else makelist
    for each x in easyprimarydecomposition!* dpmat_from_a reval m
        collect makelist {dpmat_2a first x,dpmat_2a second x};

symbolic procedure easyprimarydecomposition!* m;
% Primary decomposition for a module without embedded components.
   begin scalar u; u:=isolatedprimes!* m;
      return if null u then nil
        else if length u=1 then {m,car u}
        else for each f in
        prime_polynomial(for each y in u collect gbasis!* y)
                    collect {matqquot!*(m,cdr f),car f};
  end;

% ---- General primary decomposition ----------

symbolic operator primarydecomposition;
symbolic procedure primarydecomposition m;
  if !*mode='symbolic then rederr"only for algebraic mode"
  else makelist
    for each x in primarydecomposition!* gbasis!* dpmat_from_a reval m
        collect makelist {dpmat_2a first x,dpmat_2a second x};

symbolic procedure primarydecomposition!* m;
% Returns the primary decomposition of the dpmat (ideal or module) m
% as a list {Q,p} with a prime ideal p and a p-primary component Q.
% m must be a gbasis.
  if dpmat_cols m=0 then
    for each x in prime!=decompose1 ideal2mat!* m collect
        {flatten!* first x,second x}
  else prime!=decompose1 m;

symbolic procedure prime!=decompose1 m;
  (begin scalar u,c,v,vars,m1,l,p,q;
    if null(v:=odim_parameter m) then
            return zeroprimarydecomposition!* m;
    vars:=ring_names (c:=cali!=basering);
    cali!=degrees:=nil; u:=delete(v,vars);
    setring!* ring_define(vars,ring_rlp(c,u),ring_tag c,ring_ecart c);
    m1:=dpmat_2a gbasis!* dpmat_neworder m;
    setring!* ring_define(u,degreeorder!* u,
                                'revlex,for each x in u collect 1);
    p:=bc_2a prime!=quot(m1:=groeb_mingb dpmat_from_a m1);
    l:=for each x in prime!=decompose1 m1 collect
          {(dpmat_2a first x . bc_2a prime!=quot first x),
           (dpmat_2a second x . bc_2a prime!=quot second x)};
    setring!* c;
    l:=for each x in l collect
    << cali!=degrees:=dpmat_coldegs m;
       {gbasis!* matqquot!*(dpmat_from_a car first x,
                            dp_from_a cdr first x),
        matqquot!*(dpmat_from_a car second x,dp_from_a cdr second x)}
    >>;
    if dp_unit!?(p:=dp_from_a p) or
        submodulep!*(m1:=matqquot!*(m,p),m) then return l
    else
      << q:=p;
         while not submodulep!*(m1:=dpmat_times_dpoly(p,m1),m) do
               q:=dp_prod(p,q);
         l:=listminimize(
                append(l,prime!=decompose1
                    gbasis!* matsum!* {m, dpmat_times_dpoly(q,
                    dpmat_unit(dpmat_cols m,dpmat_coldegs m))}),
                function(lambda(x,y);
                    submodulep!*(car x,car y)));
      >>;
    return l;
   end)
   where cali!=degrees:=cali!=degrees,
                cali!=basering:=cali!=basering;

symbolic operator unmixedradical;
symbolic procedure unmixedradical m;
% Returns the radical of the dpmat ideal m.
  if !*mode='symbolic then rederr"only for algebraic mode"
  else dpmat_2a unmixedradical!* gbasis!* dpmat_from_a reval m;

symbolic procedure unmixedradical!* m;
% m must be a gbasis.
  if dpmat_cols m>0 then rederr"UNMIXEDRADICAL only for ideals"
  else (begin scalar u,c,d,v,vars,m1,l,p,p1;
    if null(v:=moid_max indepvarsets!* m) then
                return zeroradical!* m;
    vars:=ring_names (c:=cali!=basering);
    d:=length v; u:=setdiff(vars,v);
    setring!* ring_define(vars,ring_rlp(c,u),ring_tag c,ring_ecart c);
    m1:=dpmat_2a gbasis!* dpmat_neworder m;
    setring!* ring_define(u,degreeorder!* u,'revlex,
                for each x in u collect 1);
    p:=bc_2a prime!=quot(m1:=groeb_mingb dpmat_from_a m1);
    l:=zeroradical!* m1; p1:=bc_2a prime!=quot l;
    l:=dpmat_2a l; setring!* c;
    l:=matqquot!*(dpmat_from_a l,dp_from_a p1);
    if dp_unit!?(p:=dp_from_a p) then return l
    else << m1:=gbasis!* matsum!* {m,dpmat_from_dpoly p};
            if dim!* m1=d then
                l:= matintersect!* {l,unmixedradical!* m1};
         >>;
    return l;
   end)
   where cali!=degrees:=cali!=degrees,
                cali!=basering:=cali!=basering;

symbolic operator eqhull;
symbolic procedure eqhull m;
% Returns the radical of the dpmat ideal m.
  if !*mode='symbolic then rederr"only for algebraic mode"
  else dpmat_2a eqhull!* gbasis!* dpmat_from_a reval m;

symbolic procedure eqhull!* m;
% m must be a gbasis.
  begin scalar d;
  if (d:=dim!* m)=0 then return m
  else return prime!=eqhull(m,d)
  end;

symbolic procedure prime!=eqhull(m,d);
% d(>0) is the dimension of the dpmat m.
  (begin scalar u,c,v,vars,m1,l,p;
  v:=moid_max indepvarsets!* m;
  if length v neq d then
        rederr "EQHULL found a component of wrong dimension";
  vars:=ring_names(c:=cali!=basering);
  cali!=degrees:=nil; u:=setdiff(ring_names c,v);
  setring!* ring_define(vars,ring_rlp(c,u),ring_tag c,ring_ecart c);
  m1:=dpmat_2a gbasis!* dpmat_neworder m;
  setring!* ring_define(u,degreeorder!* u,'revlex,
                                for each x in u collect 1);
  p:=bc_2a prime!=quot(m1:=groeb_mingb dpmat_from_a m1);
  setring!* c; cali!=degrees:=dpmat_coldegs m;
  if submodulep!*(l:=matqquot!*(m,dp_from_a p),m) then return m;
  m1:=gbasis!* matstabquot!*(m,annihilator2!* l);
  if dim!* m1=d then return matintersect!* {l,prime!=eqhull(m1,d)}
  else return l;
   end)
   where cali!=degrees:=cali!=degrees,
                cali!=basering:=cali!=basering;

endmodule; % prime

module scripts;

COMMENT

               ######################
               ##                  ##
               ##     ADVANCED     ##
               ##   APPLICATIONS   ##
               ##                  ##
               ######################

This module contains several additional advanced applications of
standard basis computations, inspired partly by the scripts
distributed with the commutative algebra package MACAULAY
(Bayer/Stillman/Eisenbud).

The following topics are currently covered :
        - computing the jacobian matrix
        - generating random linear forms
        - generating ideals of minors
        - [BGK]'s heuristic variable optimization
        - certain stuff on maps (preimage, ratpreimage)
        - ideals of points (in affine and proj. spaces)
        - ideals of (affine and proj.) monomial curves
        - General Rees rings, associated graded rings, and related
                topics (analytic spread, symmetric algebra)
        - several short scripts (minimal generators, symbolic powers
                of primes, singular locus)


END COMMENT;

% ------ The Jacobian matrix -------------

symbolic operator matjac;
symbolic procedure matjac(m,l);
% Returns the Jacobian matrix from the ideal m
% (given as an algebraic mode list) with respect to the var. list l.
   if not eqcar(m,'list) then typerr(m,"ideal basis")
   else if not eqcar(l,'list) then typerr(l,"variable list")
   else 'mat . for each x in cdr l collect
        for each y in cdr m collect prepsq difff(numr simp reval y,x);

% ---------- Random linear forms -------------

symbolic operator random_linear_form;
symbolic procedure random_linear_form(vars,bound);
% Returns a random linear form in algebraic prefix form.
  if not eqcar(vars,'list) then typerr(vars,"variable list")
  else 'plus . for each x in cdr vars collect
        {'times,random(2*bound)-bound,x};


% ---------- Minors ---------

symbolic procedure minors!*(m,k);
% Returns the interreduced ideal of the k-minors of the dpmat m.
  if dpmat_cols m=0 then rederr"MINORS only for matrices"
  else if (dpmat_rows m<k) or (dpmat_cols m<k) then
        dpmat_make(0,0,nil,nil)
  else begin scalar r,c,u;
    r:=cali_choose(for i:=1:dpmat_rows m collect i,k);
    c:=cali_choose(for i:=1:dpmat_cols m collect i,k);
    u:=bas_renumber for each x in r join
        for each y in c collect bas_make(0,scripts!=subdet(m,x,y));
    return interreduce!* dpmat_make(length u,0,u,nil)
    end;

symbolic procedure scripts!=subdet(m,x,y);
% Returns the minor of the dpmat m with x as list of row indices and
% y as list of column indices.
   dp_from_a prepf numr detq matsm ('mat .
        for each a in x collect for each b in y collect
        dp_2a dpmat_element(a,b,m));

symbolic operator minors;
symbolic procedure minors(m,b);
  if !*mode='symbolic then rederr"only for algebraic mode"
  else dpmat_2a minors!*(dpmat_from_a reval m,reval b);

%------- --- [BGK]'s heuristic variable optimization ----------

symbolic operator varopt;
symbolic procedure varopt m;
  if !*mode='symbolic then rederr"only for algebraic mode"
  else makelist varopt!* dpmat_from_a m;

symbolic procedure varopt!* m;
% Find a heuristically optimal variable order.
  begin scalar c; c:=mo_zero();
  for each x in dpmat_list m do
    for each y in bas_dpoly x do c:=mo_lcm(c,car y);
  return
    for each x in
        sort(mo_2list c,function(lambda(x,y); cdr x>cdr y)) collect
        car x;
  end;

% ----- Certain stuff on maps -------------

% A ring map is represented as a list
%   {preimage_ring, image_ring, subst_list},
% where subst_list is a substitution list {v1=ex1,v2=ex2,...} in
% algebraic prefix form, i.e. looks like (list (equal var image) ...)

symbolic operator preimage;
symbolic procedure preimage(m,map);
% Compute the preimage of an ideal m under a (polynomial) ring map.
  if !*mode='symbolic then rederr"only for algebraic mode"
  else begin map:=cdr reval map;
     return preimage!*(reval m,
        {ring_from_a first map, ring_from_a second map, third map});
  end;

symbolic procedure preimage!*(m,map);
% m and the result are given and returned in algebraic prefix form.
  if not !*noetherian then
        rederr"PREIMAGE only for noetherian term orders"
  else begin scalar u,oldring,newring,oldnames;
  if not eqcar(m,'list) then rederr"PREIMAGE only for ideals";
  oldring:=first map; newring:=second map;
  oldnames:=ring_names oldring;
  setring!* ring_sum(newring,oldring);
  u:=bas_renumber for each x in cdr third map collect
  << if not member(second x,oldnames) then
            typerr(second x,"var. name");
     bas_make(0,dp_diff(dp_from_a second x,dp_from_a third x))
  >>;
  m:=matsum!* {dpmat_from_a m,dpmat_make(length u,0,u,nil)};
  m:=dpmat_2a eliminate!*(m,ring_names newring);
  setring!* oldring;
  return m;
  end;

symbolic operator ratpreimage;
symbolic procedure ratpreimage(m,map);
% Compute the preimage of an ideal m under a rational ring map.
  if !*mode='symbolic then rederr"only for algebraic mode"
  else   begin map:=cdr reval map;
  return ratpreimage!*(reval m,
        {ring_from_a first map, ring_from_a second map, third map});
  end;

symbolic procedure ratpreimage!*(m,map);
% m and the result are given and returned in algebraic prefix form.
  if not !*noetherian then
        rederr"RATPREIMAGE only for noetherian term orders"
  else begin scalar u,oldring,newnames,oldnames,f,g,v,g0;
  if not eqcar(m,'list) then rederr"RATPREIMAGE only for ideals";
  oldring:=first map; v:=gensym();
  newnames:=v . ring_names second map;
  oldnames:=ring_names oldring; u:=append(oldnames,newnames);
  setring!* ring_define(u,nil,'lex,for each x in u collect 1);
  g0:=dp_fi 1;
  u:=bas_renumber for each x in cdr third map collect
  << if not member(second x,oldnames) then
            typerr(second x,"var. name");
     f:=simp third x; g:=dp_from_a prepf denr f;
     f:=dp_from_a prepf numr f; g0:=dp_prod(g,g0);
     bas_make(0,dp_diff(dp_prod(g,dp_from_a second x),f))
  >>;
  u:=bas_make(0,dp_diff(dp_prod(g0,dp_from_a v),dp_fi 1)) . u;
  m:=matsum!* {dpmat_from_a m,dpmat_make(length u,0,u,nil)};
  m:=dpmat_2a eliminate!*(m,newnames);
  setring!* oldring;
  return m;
  end;

% ---- The ideals of affine resp. proj. points --------

symbolic operator affine_points;
symbolic procedure affine_points m;
% m is an algebraic matrix, which rows are the coordinates of points
% in the affine space with Spec = the current ring.
  if !*mode='symbolic then rederr"only for algebraic mode"
  else   dpmat_2a affine_points!* reval m;

symbolic procedure affine_points!* m;
  begin scalar names;
  if length(names:=ring_names cali!=basering) neq length cadr m then
        typerr(m,"coordinate matrix");
  m:=for each x in cdr m collect
         'list . for each y in pair(names,x) collect
                {'plus,car y,{'minus,reval cdr y}};
  m:=for each x in m collect dpmat_from_a x;
  m:=matintersect!* m;
  return m;
  end;

symbolic operator proj_points;
symbolic procedure proj_points m;
% m is an algebraic matrix, which rows are the coordinates of _points
% in the projective space with Proj = the current ring.
  if !*mode='symbolic then rederr"only for algebraic mode"
  else   dpmat_2a proj_points!* reval m;

symbolic procedure proj_points!* m;
  begin scalar names,x0,u;
  if length(names:=ring_names cali!=basering) neq length cadr m then
        typerr(m,"coordinate matrix");
  x0:=car names; names:=cdr names;
  m:=for each x in cdr m collect
         'list .
         << u:=reval car x;
            for each y in pair(names,cdr x) collect
                {'plus,{'times,car y,u},
                       {'minus,{'times,reval cdr y,x0}}}
         >>;
  m:=for each x in m collect dpmat_from_a x;
  m:=matintersect!* m;
  return m;
  end;

% ----- Affine and proj. monomial curves ------------

symbolic operator affine_monomial_curve;
symbolic procedure affine_monomial_curve(l,R);
% l is a list of integers, R contains length l ring var. names.
% Returns the generators of the monomial curve (t^i : i\in l) in R.
  if !*mode='symbolic then rederr"only for algebraic mode"
  else dpmat_2a affine_monomial_curve!*(cdr reval l,cdr reval R);

symbolic procedure affine_monomial_curve!*(l,R);
  if not numberlistp l then typerr(l,"number list")
  else if length l neq length R then
        rederr"number of variables doesn't match"
  else begin scalar u,t0,v;
    v:=list gensym();
    r:=ring_define(r,{l},'revlex,l);
    setring!* ring_sum(r,ring_define(v,degreeorder!* v,'lex,'(1)));
    t0:=dp_from_a car v;
    u:=bas_renumber for each x in pair(l,ring_names r) collect
        bas_make(0,dp_diff(dp_from_a cdr x,dp_power(t0,car x)));
    u:=dpmat_make(length u,0,u,nil);
    u:=(eliminate!*(u,v) where cali!=monset=ring_names cali!=basering);
    setring!* r;
    return dpmat_neworder u;
    end;

symbolic operator proj_monomial_curve;
symbolic procedure proj_monomial_curve(l,R);
% l is a list of integers, R contains length l ring var. names.
% Returns the generators of the monomial curve
% (s^(d-i)*t^i : i\in l) in R where d = max { x : x \in l}
  if !*mode='symbolic then rederr"only for algebraic mode"
  else dpmat_2a proj_monomial_curve!*(cdr reval l,cdr reval R);

symbolic procedure proj_monomial_curve!*(l,R);
  if not numberlistp l then typerr(l,"number list")
  else if length l neq length R then
        rederr"number of variables doesn't match"
  else begin scalar u,t0,t1,v,d;
    t0:=gensym(); t1:=gensym(); v:={t0,t1};
    d:=listexpand(function max2,l);
    r:=ring_define(r,degreeorder!* r,'revlex,for each x in r collect 1);
    setring!* ring_sum(r,ring_define(v,degreeorder!* v,'lex,'(1 1)));
    t0:=dp_from_a t0; t1:=dp_from_a t1;
    u:=bas_renumber for each x in pair(l,ring_names r) collect
        bas_make(0,dp_diff(dp_from_a cdr x,
                dp_prod(dp_power(t0,car x),dp_power(t1,d-car x))));
    u:=dpmat_make(length u,0,u,nil);
    u:=(eliminate!*(u,v) where cali!=monset=ring_names cali!=basering);
    setring!* r;
    return dpmat_neworder u;
    end;

% -- General Rees rings, associated graded rings, and related topics --

symbolic operator blowup;
symbolic procedure blowup(m,n,vars);
% vars is a list of var. names for the ring R
%       of the same length as dpmat_list n.
% Returns an ideal J such that (S+R)/J == S/M [ N.t ]
%       ( with S = the current ring )
% is the blow up ring of the ideal N over S/M.
% (S+R) is the new current ring.
  if !*mode='symbolic then rederr"only for algebraic mode"
  else   dpmat_2a blowup!*(dpmat_from_a reval m,dpmat_from_a reval n,
                cdr reval vars);

symbolic procedure blowup!*(M,N,vars);
  if (dpmat_cols m > 0)or(dpmat_cols n > 0) then
        rederr"BLOWUP defined only for ideals"
  else if not !*noetherian then
        rederr"BLOWUP only for noetherian term orders"
  else begin scalar u,s,t0,v,r1;
    if length vars neq dpmat_rows n then
        rederr {"ring must have",dpmat_rows n,"variables"};
    u:=for each x in dpmat_rowdegrees n collect mo_ecart cdr x;
    r1:=ring_define(vars,list u,'revlex,u);
    s:=ring_sum(cali!=basering,r1); v:=list(gensym());
    setring!* ring_sum(s,ring_define(v,degreeorder!* v,'lex,'(1)));
    t0:=dp_from_a car v;
    n:=for each x in
            pair(vars,for each y in dpmat_list n collect bas_dpoly y)
            collect dp_diff(dp_from_a car x,
                            dp_prod(dp_neworder cdr x,t0));
    m:=bas_renumber append(bas_neworder dpmat_list m,
            for each x in n collect bas_make(0,x));
    m:=(eliminate!*(interreduce!* dpmat_make(length m,0,m,nil),v)
        where cali!=monset=nil);
    setring!* s;
    return dpmat_neworder m;
    end;

symbolic operator assgrad;
symbolic procedure assgrad(m,n,vars);
% vars is a list of var. names for the ring T
%       of the same length as dpmat_list n.
% Returns an ideal J such that (S+T)/J == (R/N + N/N^2 + ... )
%       ( with R=S/M and S the current ring )
% is the associated graded ring of the ideal N over R.
% (S+T) is the new current ring.
  if !*mode='symbolic then rederr"only for algebraic mode"
  else   dpmat_2a assgrad!*(dpmat_from_a reval m,dpmat_from_a reval n,
                cdr reval vars);

symbolic procedure assgrad!*(M,N,vars);
  if (dpmat_cols m > 0)or(dpmat_cols n > 0) then
        rederr"ASSGRAD defined only for ideals"
  else begin scalar u;
    u:=blowup!*(m,n,vars);
    return matsum!* {u,dpmat_neworder n};
    end;

symbolic operator analytic_spread;
symbolic procedure analytic_spread m;
% Returns the analytic spread of the ideal m.
  if !*mode='symbolic then rederr"only for algebraic mode"
  else analytic_spread!* dpmat_from_a reval m;

symbolic procedure analytic_spread!* m;
   if (dpmat_cols m>0) then rederr"ANALYTIC SPREAD only for ideals"
   else (begin scalar r,m1,vars;
   r:=ring_names cali!=basering;
   vars:=for each x in dpmat_list m collect gensym();
   m1:=blowup!*(dpmat_from_dpoly nil,m,vars);
   return dim!* gbasis!* matsum!*{m1,dpmat_from_a('list . r)};
   end) where cali!=basering=cali!=basering;

symbolic operator sym;
symbolic procedure sym(M,vars);
% vars is a list of var. names for the ring R
%       of the same length as dpmat_list M.
% Returns an ideal J such that (S+R)/J == Sym(M)
%       ( with S = the current ring )
% is the symmetric algebra of M over S.
% (S+R) is the new current ring.
  if !*mode='symbolic then rederr"only for algebraic mode"
  else dpmat_2a sym!*(dpmat_from_a M,cdr reval vars);

symbolic procedure sym!*(m,vars);
% The symmetric algebra of the dpmat m.
   if not !*noetherian then
        rederr"SYM only for noetherian term orders"
   else begin scalar n,u,s,r1;
    if length vars neq dpmat_rows m then
        rederr {"ring must have",dpmat_rows m,"variables"};
    cali!=degrees:=dpmat_coldegs m;
    u:=for each x in dpmat_rowdegrees m collect mo_ecart cdr x;
    r1:=ring_define(vars,list u,'revlex,u); n:=syzygies!* m;
    setring!* ring_sum(cali!=basering,r1);
    return flatten!* interreduce!*
                dpmat_mult(dpmat_neworder n,
                        ideal2mat!* dpmat_from_a('list . vars));
    end;

% ----- Several short scripts ----------

% ------ Minimal generators of an ideal or module.
symbolic operator minimal_generators;
symbolic procedure minimal_generators m;
  if !*mode='symbolic then rederr"only for algebraic mode"
  else dpmat_2a minimal_generators!* dpmat_from_a reval m;

symbolic procedure minimal_generators!* m;
  car groeb_minimize(m,syzygies!* m);

% ------- Symbolic powers of prime (or unmixed) ideals
symbolic operator symbolic_power;
symbolic procedure symbolic_power(m,d);
  if !*mode='symbolic then rederr"only for algebraic mode"
  else dpmat_2a symbolic_power!*(dpmat_from_a m,reval d);

symbolic procedure symbolic_power!*(m,d);
  eqhull!* idealpower!*(m,d);

% ----- Singular locus -----------

algebraic procedure singular_locus(m,c);
  matsum(m, minors(matjac(m,first getring()),c));

endmodule; % scripts


end;

