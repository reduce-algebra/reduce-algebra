module buchbg;  % Central Groebner base code: Buchberger algorithm.

%   Authors:   H. Melenk, H.M. Moeller,  W. Neun
%   ZIB Berlin 
%   July 1988 

fluid '(!*gcd);

fluid '(                           % switches from the user interface
        !*groebopt !*groebfac !*groebres !*trgroeb !*trgroebs !*groebrm
        !*trgroeb1 !*trgroebr !*groebprereduce groebrestriction!*
        !*groebfullreduction !*groebstat !*groebdivide !*groebprot
        !*groebheufact !*groebweak !*groelterms
 
        vdpvars!*                  % external names of the variables
        !*vdpinteger !*vdpmodular  % indicating type of algorithm
        vdpsortmode!*              % term ordering mode
        secondvalue!* thirdvalue!* % auxiliary: multiple return values
        fourthvalue!*
        groebdomain!*              % domain mode if selected explicitly
        factortime!*               % computing time spent in factoring
        factorlevel!*              % bookkeeping of factor tree
        groefeedback!*             % sideeffect factorization
        groesfactors!*             % data structure for act. fact.
        pairsdone!*                % list of pairs already calculated
        probcount!*                % counting subproblems
        vbccurrentmode!*           % current domain for base coeffs.
        vbcmodule!*                % for modular calculation: 
                                   % current prime
        groetime!*
        !*gsugar                   % enable Traverso's sugar technique
        groecontcount!*            % control of content reduction     
        gmodule!*                  % internal module basis
        groebabort!*               % input abort conditions
       );
 
global '(groebrestriction          % interface:
                                   %  name of restriction function
         groebresmax            % maximum number of internal results
         gvarslast                 % output: variable list 
         groebmonfac               % minimum exponent for reduction of
                                   % monomial factors
         groebprotfile             % reduction protocol
         glterms                   % list for lterms collection
        );
 
flag ('(groebrestriction groebresmax gvarslast groebmonfac
         groebprotfile glterms), 'share);
 
groebrestriction := nil;
groebresmax := 300;
groebmonfac := 1;
groecontcount!* := 10;
!*groebfullreduction := t;
!*gsugar := t;
!*groelterms := t;
 
switch groebopt,groebres,trgroeb,trgroebs,trgroeb1,
       trgroebr,groebfullreduction,groebstat,groebprot;
 
% variables for counting and numbering
fluid '(hcount!* pcount!* mcount!* fcount!* bcount!* b4count!* 
        basecount!* hzerocount!*);
 
%      option ' groebopt'    "optimizes" the given input
%                            polynomial set ( variable
%                            ordering )
%      option ' trgroeb'     prints intermediate
%                            results on the output file
%      option ' trgroeb1'    prints internal representation
%                            of critical pair list d
%      option ' trgroebs '   prints S - polynomials
%                            on the output file
%      option   trgroebr     prints (intermediate) results and
%                            computation statistics
% groebstat  the statistics are printed
% groebres   the H- polynomials are optimised using resultant
%            and factorisation method
%
% groebrm    multiplicities of factors in h-polynomials are reduced
%            to simple factors.
%
% groebdivide
%            the algorithm avoids all divisions (only for modular
%            calculation) , if this switch is set off;
%
% groebprot  Write a protocol to the variable "groebprotfile";
 
!*groebfullreduction := t;
%!*groebPreReduce := T;
!*groebdivide := t;
 

% the code for checkpointing is factored out
% This version: NO CHECKPOINT FACILITY

smacro procedure groebcheckpoint1(); list nil;
smacro procedure groebcheckpoint2(); list nil;
smacro procedure groebcheckpoint2a(); list nil;
smacro procedure groebcheckpoint3(); list nil;
smacro procedure groebcheckpoint4(); list nil;
smacro procedure groebcheckpoint5(); list nil;

 
symbolic procedure buch!-vevdivides!? (vev1,vev2);
    % test: vev1 divides vev2 ? for exponent vectors vev1,vev2
    vevmtest!? (vev2,vev1) and 
     (null gmodule!* or gevcompatible1(vev1,vev2,gmodule!*));
 
symbolic procedure gevcompatible1(v1,v2,g);
  % test whether v1 and v2 belong to the same vector column.
   if null g then t 
   else if null v1 then (null v2 or gevcompatible1('(0),v2,g))
   else if null v2 then gevcompatible1(v1,'(0),g) else
    (car g = 0 or car v1 = car v2) and
         gevcompatible1(cdr v1,cdr v2,cdr g);
      
symbolic procedure gcompatible(f,h);
   null gmodule!* or 
     gevcompatible1(vdpevlmon f,vdpevlmon h,gmodule!*);

symbolic procedure groebmakepair(f,h);
     % construct a pair from polynomials f and h
   begin scalar ttt,sf,sh;
      ttt:=tt(f,h);
      return if !*gsugar then
      <<sf:=gsugar(f) #+ vevtdeg vevdif(ttt,vdpevlmon f);
        sh:=gsugar(h) #+ vevtdeg vevdif(ttt,vdpevlmon h);
        list(ttt,f,h,max(sf,sh))>>
       else list(ttt,f,h);
   end;

% the 1-polynomial will be constructed at run time
% because the length of the vev is not known in advance
fluid '(vdpone!*);
 
symbolic procedure vdponepol;
    % construct the polynomial=1
    vdpone!* := vdpfmon(a2vbc 1,vevzero());
 
symbolic procedure groebner2(p,r);
  % setup all global variables for the Buchberger algorithm
  % printing of statistics
 begin scalar groetime!*,tim1,spac,spac1,p1,factortime!*,
              pairsdone!*,factorlevel!*,groesfactors!*,!*gcd;
       factortime!* := 0;
       groetime!*   := time();
       vdponepol(); % we construct dynamically
       hcount!* := 0; mcount!* := 0; fcount!* := 0;
       bcount!* := 0; b4count!* := 0; hzerocount!* := 0;
       basecount!* := 0; !*gcd := t; glterms := list('list);
       groecontcount!* := 10;
       if !*trgroeb then
       << prin2 "Groebner Calculation starting ";
          terprit 2;
          prin2 " groebopt: "; print !*groebopt;
       >>;
       spac := gctime();
 
       p1:= if !*groebfac or null !*gsugar
          then groebbasein (p,!*groebfac,!*groebres,r) 
                 where !*gsugar=nil
            else gtraverso(p,nil,nil,nil);
 
       if !*trgroeb or !*trgroebr or !*groebstat then
       <<
          spac1 := gctime() - spac;
          terpri();
          prin2t "statistics for GROEBNER calculation";
          prin2t "===================================";
          prin2 " total computing time (including gc): ";
          prin2((tim1 := time()) - groetime!*);
          prin2t "          milliseconds  ";
       if factortime!* neq 0 then
        <<prin2 " (time spent in FACTOR (excl. gc):    ";
          prin2 factortime!*;
          prin2t "          milliseconds)";
        >>;
          prin2 " (time spent for garbage collection:  ";
          prin2 spac1;
          prin2t "          milliseconds)";
          terprit 1;
          prin2  "H-polynomials total: "; prin2t hcount!*;
          prin2  "H-polynomials zero : "; prin2t hzerocount!*;
          prin2  "Crit M hits: "; prin2t mcount!*;
          prin2  "Crit F hits: "; prin2t fcount!*;
          prin2  "Crit B hits: "; prin2t bcount!*;
          prin2  "Crit B4 hits: "; prin2t b4count!*;
       >>;
       return p1;
 end;
 
 
smacro procedure testabort h;
     vdpmember (h,abort1) or
      'cancel = (abort2 := groebtestabort(h,abort2));
 
symbolic procedure groebenumerate f;
  % f is a temporary result. Prepare it for medium range storage
  % and ssign a number
  if vdpzero!? f then f else
   << vdpcondense f;
      if not vdpgetprop(f,'number) then
      <<f := vdpputprop(f,'number,(pcount!* := pcount!* #+ 1));
        if !*groebprot then 
          << groebprotsetq(mkid('poly,pcount!*),'candidate);
             vdpputprop(f,'groebprot,mkid('poly,pcount!*));
          >>;
      >>;
     f>>;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Buchberger's Algorithm
%
% INPUT :   G0 = { f1, ... , fr}  set of nonzero polynomials
% OUTPUT:   groebner basis (list of nonzero polynomials)
%
% internal variables:
%
%    problems  list of problems to be processed. problems is non nil,
%              if the inital problem was split by a successful factoring
%    results   collection of results from problems
%    G         basis under construction
%    G1        local pointer to G
%    D         list of critical pairs during algorithm
%    D1,D2     local lists of pairs during update of D
%    f,fj      polynomials
%    p,p1,p2   pairs
%    s,h       polynomials in the central part of the algorithm
%              (the "s-poly" and the "h-poly" selon Buchberger
%    G99       set of polynomials used for reduction. Held as
%              a search tree
%    abort1    list of polynomials in factorization context.
%              a calculation branch can be cancelled if one of
%              these polys is detected
%    abort2    list of sets of polynomials. If a new h polynomial
%              is calculated, it should be removed from the sets.
%              if one set becomes null, the set restriction is
%              fulfilled and the branch can be cancelled
 
symbolic procedure groebbasein (g0,fact,groebres,abort1);
   begin scalar problems, results, abort2,x,
                g,g1,d,d1,d2,p,p1,s,h,g99,hlist,lv,lasth;
         integer gvbc, probcount!*;
         groebabort!* := abort1; 
         lv := length vdpvars!*;
         groebcheckpoint1();
         for each p in g0 do 
            if vdpzero!? p then g0 := delete(p,g0);
          if !*groebprereduce then g0 := groebprereduce g0;
          x := for each fj in g0 collect
          <<groebsavelterm fj;
            gsetsugar(vdpenumerate vdpsimpcont fj,nil)>>;
          if !*groebprot then
           for each f in x do
           << groebprotsetq(mkid('poly,h:= vdpnumber f), vdp2a f);
              vdpputprop(f,'groebprot,mkid('poly,h))>>;
          g0 := x;
                                       % establish the initial problem
        problems := list (list (nil,nil,nil,g0,abort1,nil,nil,
                          vbccurrentmode!*, nil,nil) );
        !*trgroeb and groebmess1(g,d);
        goto macroloop;
        groebcheckpoint2();
macroloop:
  while problems and gvbc < groebresmax do
  begin
     groebcheckpoint2a();
                                       % pick up next problem
     x := car problems;
     groebcheckpoint3();
     d := car x;
     g := cadr x;
     g99 := groebstreereconstruct caddr x;
     g0 := cadddr x; 
     abort1 := nth(x,5);
     abort2 := nth(x,6);
     pairsdone!* := nth(x,7);
     h := nth(x,8);                     % vbcCurrentMode!*
     factorlevel!* := nth(x,9);
     groesfactors!* := nth(x,10);
     groebcheckpoint4();
     problems := cdr problems;
     g0 := % sort G0, but keep factor in first position
       if factorlevel!* and  g0 and cdr g0 then car g0 . vdplsort cdr g0
        else vdplsort g0;
     x := nil;
     lasth := nil;
                !*trgroeb and groebmess23 (g0,abort1,abort2);
      while d or g0 do
       begin
          if groebfasttest(g0,g,d,g99) then goto stop;
                 !*trgroeb and groebmess50(g);
          if g0 then
          <<    h := car g0;
               g0 := cdr g0;
               gsetsugar(h,nil);
               groebsavelterm h;
               p := list(nil,h,h); >>
             else
          <<   p := car d;
               d := delete (p,d);
               s := groebspolynom (cadr p, caddr p);
               if fact then
                    pairsdone!* := (vdpnumber cadr p
                                      . vdpnumber caddr p)
                              . pairsdone!*;
                           !*trgroeb and groebmess3 (p,s);
               h:=groebnormalform(s,g99,'tree);
               groebsavelterm h;
               h:=groebsimpcontnormalform h;
                 if vdpzero!? h then !*trgroeb and groebmess4(p,d);
                                      % test for possible chains
               if not vdpzero!? h then  % only for real h's
                   << s := groebchain (h,cadr p,g99);
                      if s = h then
                        h := groebchain (h,caddr p,g99);
                        if secondvalue!* then
                            g := delete(secondvalue!*,g)>>; >>;
          if vdpzero!? h then goto bott;
          if vevzero!? vdpevlmon h then % base 1 found
                  <<   !*trgroeb and groebmess5(p,h); goto stop>>;
          if testabort(h) then
                  <<   !*trgroeb and groebmess19(h,abort1,abort2);
                   goto stop>>;
          s:= nil;
                    % look for implicit or explicit factorization
          hlist := nil;
          if groebrestriction!* then
                    hlist := groebtestrestriction(h,abort1);
          if not hlist and fact then 
                    hlist := groebfactorize(h,abort1,g,g99);
          if hlist = 'zero then goto bott;
          if groefeedback!* then g0 := append(groefeedback!*,g0);
          groefeedback!* := nil;
                   % factorisation found but only one factor survived
          if hlist and length hlist = 2 then
                   <<h := car cadr hlist; hlist := nil>>;
          if not hlist and groebres then
             <<hlist := groebtestresultant(lasth,h,lv);
               if hlist then groebres := nil>>;
          if hlist then
                <<if hlist neq 'cancel then
                   problems:=
                    groebencapsulate(hlist,d,g0,g,g99,
                           abort1,abort2,problems,fact);
                  go stop>>;
                  % h polynomial is accepted now
               h := groebenumerate h; !*trgroeb and groebmess5(p,h);
                              % construct new critical pairs
               d1 := nil;
                   !*trgroeb and groebmess50(g);
              for each f in g do
                  if(car p or % that means "not an input polynomial"
                     not member (vdpnumber h . vdpnumber f, pairsdone!*)
                    ) and gcompatible(f,h) then
                    <<d1 := groebcplistsortin(groebmakepair(f,h),d1);
                      if tt(f,h) = vdpevlmon(f) then 
                              <<g := delete (f,g);
                                !*trgroeb and groebmess2 f>> >>;
                  !*trgroeb and groebmess51(d1);
               d2 := nil;
               while d1 do
                  <<d1 := groebinvokecritf d1;         
                    p1 := car d1; d1 := cdr d1;
                    d2 := groebinvokecritbuch4 (p1,d2);
                    d1 := groebinvokecritm (p1,d1) >>;
                 d := groebinvokecritb (h,d);  
                 d := groebcplistmerge(d,d2);   
                         % monomials and binomials
                 if vdplength h < 3 and car p then 
                   <<g := groebsecondaryreduction (h,g,g99,d,nil,t);
                     if g = 'abort then goto stop;
                     g99 := secondvalue!*;
                     d := thirdvalue!*>>;
                 g := h . g;
                 lasth := h;
                 g99 := groebstreeadd(h, g99);
                            !*trgroeb and groebmess8(g,d);
                 goto bott;
    stop:        d := g := g0 := nil;
    bott: groebcheckpoint5();
   end;
   g := vdplsort g;       % such that T descending
   x := groebbasein2(g,g99,problems,abort1,abort2,fact);
   g1 := car x; problems := cdr x;
   if g1 then <<results := g1 . results; gvbc := gvbc+1>>;
   !*trgroeb and groebmess13(g1,problems);
  end;
  if gvbc  >= groebresmax then
      lpriw("########","warning: GROEBRESMAX limit reached");
  return groebbasein3 results;
end;
 
symbolic procedure groebfasttest(g0,g,d,g99); 
      <<g := g0 := d := g99 := nil; nil>>;
           % a hook for special techniques

symbolic procedure groebbasein2(g,g99,problems,abort1,abort2,fact);
  % final reduction for a base G: reduce each polynomial with the
  % other members; here again support of factorization
  begin scalar !*groebfullreduction,!*groebheufact;     % saving value
   scalar g1,f,h,hlist,x,!*gsugar; integer cnt;
   !*groebfullreduction := t;
   g1 := nil;
   while g do
      <<h := car g;
        g := cdr g;
        if !*groebprot then
          groebprotsetq('candidate,mkid('poly,vdpnumber h));
        h := groebnormalform (h,g,'sort);
        f := groebsimpcontnormalform h;
                           !*trgroeb and groebmess26(h,f);
        if !*groebprot then 
          groebprotsetq({'gb,cnt:=cnt+1},'candidate);
        if vdpone!? f then <<g1 := g := nil>>;  % base {1} found
                                                % very late now
        if fact and not vdpzero!? f then
            << hlist := groebfactorize (f,abort1,nil,nil);
               if not null hlist then
                 <<          % lift structure
                  hlist := for each x in cdr hlist collect car x;
                             % discard superfluous factors
                  for each h in hlist do
                       if vdpmember(h,abort1) then
                           <<hlist := delete(h,hlist);
                               !*trgroeb and 
                               groebmess19(h,abort1,abort2)>>;
                                       % generate new subproblems
                  x := 0;
                  for each h in hlist do
                    <<hlist := delete(h,hlist);
                      h := groebenumerate h;
                      problems:=
                         list(nil,                 % null D
                              append(g1,g),        % base
                              g99,                 % G99
                              list h,              % G0
                              append(hlist,abort1),
                              abort2,
                              pairsdone!*,
                              vbccurrentmode!*,
                              (x := x+1) . factorlevel!*,
                              groesfactors!*
                             ) . problems;
                    >>;
                  g := g1 := nil;     % cancel actual final reduction
                  f := nil;
                >>  
              >>;
        if f and vdpevlmon h neq vdpevlmon f then
        <<g:= vdplsort append(g,f . g1); g1 := nil>> else
        if f and not vdpzero!? f then g1 := append (g1 ,list f);
        >>;
     return g1.problems;
   end;

symbolic procedure groebbasein3 results;
 % final postprocessing : remove multiple bases from the result
 begin scalar x,g,f,p1,p2;
  x := nil; g := results; p1 := p2 := 0;
  while results do
      <<if vdpone!? car car results      % exclude multiple {1}
              then p1 := p1 + 1              % count ones
          else
      <<f := for each p in car results     % delete props for member 
                     collect vdpremallprops p;
        if  member (f,x)                     % each base only once
              then p2 := p2 + 1              % count multiples
        else if not groeb!-abort!-id(f,groebabort!*) 
           then x := f . x;
         results := cdr results>> >>;
  results := if null x then list list vdpone!* else x;
  return results;
end;

fluid '( !*vbccompress);
 
 
symbolic procedure groebchain(h,f,g99);
    % test if a chain from h-plynomials can be computed from the h
   begin scalar h1,h2,h3,count,found;
         secondvalue!* := nil;
       return h; % erst einmal
         if not buch!-vevdivides!? (vdpevlmon h, vdpevlmon f) 
              then return h;
         h2 := h;
         h1 := f;
         found := t;
         count := 0;
         while found do
                  <<h3 := groebspolynom(h1,h2);
                    h3 := groebnormalform(h3,g99,'tree);
                    h3 := vdpsimpcont h3;
                    if vdpzero!? h3 then
                           <<found := nil;
                            prin2t "chain---------------------------";
                             vdpprint h1;
                             vdpprint h2;
                             vdpprint h3;
                             secondvalue!* := f;
                             count := 9999>>
                      else
                   if vdpone!? h3 then
                           <<found := nil;
                            prin2t "chain---------------------------";
                             vdpprint h1;
                             vdpprint h2;
                             vdpprint h3;
                             h2 := h3;
                             count := 9999>>
 
                      else
                    if buch!-vevdivides!?(vdpevlmon h3, vdpevlmon h2) 
		      then <<found := t;
                             prin2t "chain---------------------------";
                             vdpprint h1;
                             vdpprint h2;
                             vdpprint h3;
                             h1 := h2;
                             h2 := h3;
                             count := count+1>>
                      else
                           found := nil;
                  >>;
       return if count > 0 then
             << prin2 "CHAIN :"; prin2t count; h2>>
            else h;
    end;
 
 
symbolic procedure groebencapsulate(hlist,d,g0,g,g99,
                   abort1,abort2,problems,fact);
% hlist is a factorized h poly. This procedure has the job to
% form new problems from hlist and to add them to problems.
% Result is problems.
% Standard procedure: only creation of subproblems
    begin scalar factl,      % list of factorizations under way
                 u,y,z;
          integer fc;
      if length vdpvars!*>10 or car hlist neq 'factor then
          return groebencapsulatehardcase(hlist,d,g0,g,g99,
                   abort1,abort2,problems,fact);
                            % encapsulate for each factor
      factl := groebrecfactl list hlist;;
                   !*trgroeb and groebmess22 (factl,abort1,abort2);
      for each x in reverse factl do
           <<y := append (car x, g0);
             z := vdpunion (cadr x,abort1);
             u := append(caddr x,abort2);
                  problems :=  list(
                            d,
                            g,
                            g,                       % future G99
                            y,                       % as new problem
                            z,                       % abort1
                            u,                       % abort2
                            pairsdone!*,             % pairsdone!*
                            vbccurrentmode!*,
                            (fc:= fc+1) . factorlevel!*,
                            groesfactors!*
                           ) . problems;
            >>;
        return problems;
end;
 
 
 
 
symbolic procedure groebencapsulatehardcase(hlist,d,g0,g,g99,
                   abort1,abort2,problems,fact);
% hlist is a factorized h poly. This procedure has the job to
% form new problems from hlist and to add them to problems.
% Result is problems.
% First the procedure tries to compute new h-polynomials from the
% remaining pairs which are not affected by the factors in hlist.
% purpose is to find further factorizations and to do calculations
% in common for all factors in order to shorten the separate later
% branches;
    begin scalar factl,      % list of factorizations under way
                 factr,      % variables under factorization
                 u,h,d1,d2,p1,y,z,p,s,f,gc,pd,break,fl1;
          integer fc;
      factl := list hlist;
      factr := vdpspace car cadr hlist;
      for each x in cdr hlist do
         for each p in x do
             factr := vevunion(factr,vdpspace p);
 
% ITER:
                                 % now process additional pairs
      while d or g0 do
        begin
          break := nil;
          if g0 then
          <<               % next poly from input
               s := car g0; g0 := cdr g0; p := list(nil,s,s);
          >>
             else
          <<               % next poly fropm pairs
               p := car d; d := delete (p,d);
               if not vdporthspacep(car p,factr) then
                 s:= nil else
               <<s := groebspolynom (cadr p, caddr p);
                        !*trgroeb and groebmess3 (p,s);>>;
          >>;
 
          if null s or not vdporthspacep(vdpevlmon s,factr) then
              <<                     % throw away s polynomial
                 f := cadr p;
                 if not vdpmember3(f,g0,g,gc)
                      then gc := f . gc;
                 f := caddr p;
                 if car p and not vdpmember3 (f,g0,g,gc)
                      then gc := f . gc;
                  goto bott>>;
 
          h := groebnormalform(s,g99,'tree);
                  if vdpzero!? h and car p then
                               !*trgroeb and groebmess4(p,d);
 
          if not vdporthspacep(vdpevlmon h,factr) then
              <<                     % throw away h polynomial
                 f := cadr p;
                 if not vdpmember3(f,g0,g,gc)
                      then gc := f . gc;
                 f := caddr p;
                 if car p and not vdpmember3 (f,g0,g,gc)
                      then gc := f . gc;
                 goto bott>>;
 
 %%%         if car p then
 %%%               pairsdone!* := (vdpnumber cadr p . vdpnumber caddr p)
 %%%                             . pairsdone!*;
 
          if vdpzero!? h then goto bott;
 
          if vevzero!? vdpevlmon h then     % base 1 found
                   goto stop;
 
          h := groebsimpcontnormalform h;   %  coefficients normalized
 
          if testabort h then
                 <<!*trgroeb and groebmess19(h,abort1,abort2);
                   goto stop>>;
 
          s:= nil;
 
          hlist := nil;
          if groebrestriction!* then
                    hlist := groebtestrestriction(h,abort1);
          if hlist = 'cancel then goto stop;
 
          if not hlist and fact then
                  hlist := groebfactorize(h,abort1,g,g99);
          if groefeedback!* then g0 := append(groefeedback!*,g0);
          groefeedback!* := nil;
          if hlist and length hlist = 2 then
                   <<h := car cadr hlist; hlist := nil>>;
          if hlist then
                << for each x in cdr hlist do
                      for each h in x do
                           factr := vevunion(factr,vdpspace h);
                  factl := hlist . factl; % add to factors
                  goto bott>>;
 
          h := groebenumerate h;             % ready now
 
                        !*trgroeb and groebmess5(p,h);
 
                              % construct new critical pairs
          d1 := nil;
 
 
          for each f in g do
             if tt(f,h) = vdpevlmon(f) and gcompatible(f,h) then
              <<g := delete (f,g);
                d1 := groebcplistsortin( groebmakepair(f,h) , d1);
                             !*trgroeb and   groebmess2 f;
              >>;
                     !*trgroeb and groebmess51(d1);
          d2 := nil;
          while d1 do
                  <<d1 := groebinvokecritf d1;         
                    p1 := car d1; d1 := cdr d1;
                    d2 := groebinvokecritbuch4 (p1,d2); 
                    d1 := groebinvokecritm (p1,d1);  
                  >>;
 
          d := groebinvokecritb (h,d);            
          d := groebcplistmerge(d,d2);
 
          if vdplength h < 3 then
                    <<g := groebsecondaryreduction (h,g,g99,d,gc,t);
                      if g = 'abort then goto stop;
                      g99 := secondvalue!*;
                      d := thirdvalue!*;
                      gc := fourthvalue!*>>;
          g := h . g;
          g99 := groebstreeadd(h, g99);
 
                            !*trgroeb and groebmess8(g,d);
          goto bott;
 
  stop:
         d := g := g0 := gc := factl := nil;
  bott:
         end;     %ITER
 
                            % now collect all relvevant polys
        g0 := vdpunion(g0,vdpunion(g,gc));
 
                            % encapsulate for each factor
        if factl then
           << factl := groebrecfactl factl;
              !*trgroeb and groebmess22 (factl,abort1,abort2);
           >>;
        for each x in reverse factl do
           <<fl1 := (fc := fc+1) . factorlevel!*;
             break:= nil;
             y := append (car x, g0);
             z := vdpunion (cadr x,abort1);
             u := append(caddr x,abort2);
             if vdpmember(vdpone!*,y) then break:=vdpone!*;
 
                        % inspect the unreduced list first 
             if not break then for each p in z do 
                  if vdpmember(p,y) then break := p; 
 
                        % now prepare the reduced list
            if not break then
            <<y := append (car x,groebreducefromfactors(g0,car x));
              pd := secondvalue!*;
              if vdpmember(vdpone!*,y) then break := vdpone!* else
                 for each p in z do if vdpmember(p,y) then break := p;
              pd := subla(pd,pairsdone!*);
            >>;
 
            if not break then
                  problems :=  list(
                            nil,                     % new D
                            nil,                     % new G
                            nil,                     % future G99
                            y,                       % as new problem
                            z,                       % abort1
                            u,                       % abort2
                            nil,                     % pairsdone!*
                            vbccurrentmode!*,
                            fl1,                     % factorlevel!*,
                            groesfactors!*           % factor db
                           ) . problems
                else !*trgroeb and groebmess19a(break,fl1);
            >>;
        return problems;
end;
 
symbolic procedure groebrecfactl (factl);
% factl is a list of factorizations:a list of lists of vdps
% generate calculation pathes from them
   begin scalar rf,res,type;
     if null factl then return list list(nil,nil,nil);
     rf := groebrecfactl (cdr factl);
     factl := car factl;
     type := car factl;   % FACTOR or RESTRICT
     factl := cdr factl;
     while factl do
        <<for each y in rf do
           if vdpdisjoint!?(car factl,cadr y) then
             res := list( vdpunion(car factl,car y),
                     (if type = 'factor then
                         append (for each x in cdr factl collect car x,
                                                                cadr y)
                        else
                      if type = 'resultant then
                         append (for each x in cdr factl collect cadr x,
                                                                cadr y)
                        else cadr y),
                     (if type neq 'factor and type neq 'resultant then
                         append(cdr factl,caddr y)
                        else caddr y)
                    ) . res;
          factl := cdr factl>>;
     return res;
   end;
 
 
symbolic procedure groebtestabort (h,abort2);
   % tests if h is member of one of the sets in abort2.
   % if yes, it is deleted. If one wet becomes null, the message
   % "CANCEL is returned, otherwise the updated abort2.
    begin scalar x,break,res;
              % car test the occurence
       x := abort2;
       while x and not break do
        << if vdpmember(h,car x) then break := t;
           x := cdr x>>;
       if not break then return abort2;  % not relvevant
       break := nil;
       while abort2 and not break do
        <<x := vdpdeletemember(h,car abort2);
          if null x then break := t;
          res := x . res;
          abort2 := cdr abort2;
        >>;
       !*trgroeb and groebmess25(h,res);
       if break then return 'cancel;
       return res;
    end;
 
 
 
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%    Reduction of polynomials
%
 
symbolic procedure groebnormalform(f,g,type);
     % general procedure for reduction of one polynomial from a set
     %  f is a polynomial, G is a Set of polynomials either in
     %     a search tree or in a sorted list
     % type describes the ordering of the set G:
     %    'TREE     G is a search tree
     %    'SORT     G is a sorted list
     %    'LIST     G is a list, but not sorted
     %  f has to be reduced modulo G
  begin scalar f0,f1,c,vev,divisor,break,done,fold,a;
        integer n,s1,s2;
      if !*groebweak and !*vdpinteger 
            and groebweakzerotest(f,g,type) then return f2vdp nil;
      fold := f; f1 := vdpzero(); a:= vbcfi 1;
      gsetsugar(f1,gsugar f);
      while not vdpzero!? f do
          begin
            vev:=vdpevlmon f; c:=vdplbc f;
 
            if not !*groebfullreduction and not vdpzero!? f1 then
                    g := nil;                 % cut off

            if type = 'sort then
                 while g and vevcompless!?(vev,vdpevlmon car g)
                            do g := cdr g;
            if null g then
                  <<f1:=vdpsum (f1,f); f:=vdpzero();
                    break := t; divisor := nil; goto ready>>;
 
            divisor :=
               if type = 'tree then groebsearchinstree(vev,g)
                               else groebsearchinlist (vev,g);
 
            if divisor then done := t;    % true action indicator
 
            if divisor and !*trgroebs then
                       << prin2 "//-";
                          prin2 vdpnumber divisor;
                          >>;
            if divisor then
                      if vdplength divisor = 1 then
                            f := vdpcancelmvev(f,vdpevlmon divisor)
                          else
                      if !*vdpinteger or not !*groebdivide then
                       << f:=groebreduceonestepint(f,f1,c,vev,divisor);
                          f1 := secondvalue!*; n := n+1;
                          if  not vdpzero!? f and 
                              n #> groecontcount!* then
                          <<f0 := f;
                            f:=groebsimpcont2(f,f1);
                            groecontentcontrol(f neq f0);
                            f1 := secondvalue!*; n := 0 >>;
                       >>
                       else
                        f := groebreduceonesteprat(f,nil,c,vev,divisor)
               else
                  <<!*gsugar and <<s1:=gsugar(f);s2:=gsugar(f1)>>;
                    f1 := vdpappendmon (f1,vdplbc f,vdpevlmon f);
                    f := vdpred f;
                    !*gsugar and <<gsetsugar(f,s1); 
                                   gsetsugar(f1,max(s2,s1))>>; 
                    >>;
            ready:
          end;
      if !*groebprot then groebreductionprotocolborder();
      if not done then f1 := fold;
      return f1;
   end;
 
symbolic procedure groecontentcontrol u;
   % u indicates, that a substantial content reduction was done;
   % update content reduction limit from u.
  groecontcount!*:= if not numberp groecontcount!* then 10 else
                    if u then max(0,groecontcount!*-1)
                         else min(10,groecontcount!*+1);

symbolic procedure groebvbcbig!? a;
    % test if a is a "big" coefficient
     (if numberp x then (x > 1000000000000 or x < -1000000000000)
                   else t) 
             where x=vbcnumber a;

symbolic procedure groebsimpcontnormalform h;
  % simpCont version preserving the property SUGAR 
     if vdpzero!? h then h else
     begin scalar sugar,c;
         sugar :=gsugar h; c:=vdplbc h; 
         h := vdpsimpcont h;
         gsetsugar(h,sugar);
         if !*groebprot and not(c=vdplbc h)then
          groebreductionprotocol2 
             reval list('quotient,vbc2a vdplbc h,vbc2a c);
         return h;
     end;

symbolic procedure groebsimpcont2(f,f1);
  % simplify two polynomials with the gcd of their contents;
    begin scalar c,s1,s2;
         s1:=gsugar f; s2:=gsugar f1;
         c := vdpcontent f;
         if vbcone!? vbcabs c then goto ready;
         if not vdpzero!? f1 then 
         << c := vdpcontent1(f1,c);
            if vbcone!? vbcabs c then goto ready;
            f1 :=  vdpdivmon(f1,c,nil)>>;
         f := vdpdivmon(f,c,nil);
                 !*trgroeb and groebmess28 c;
         groebsaveltermbc c;
         gsetsugar(f,s1); gsetsugar(f1,s2);
      ready:
         secondvalue!* := f1; return f;
    end;

% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
%
%  special case reductions
%
 
symbolic procedure groebprereduce g;
% reduce the polynomials in g with themselves.
% the reduction is continued until headterms are stable
% is possible;
  begin scalar res,work,oldvev,f,oldf,!*groebweak,!*groebfullreduction;
        integer count;
     if !*trgroebs then
     <<  g := for each p in g collect vdpenumerate p;
         for each p in g do vdpprint p>>;
     res := nil; % delete zero polynomials from G
     for each f in g do if not vdpzero!? f then res := f . res;
     work := g := res := reversip res;
     while work do
      << g := vdplsort res;   % sort prvevious result
         if !*trgroebs then prin2t "Starting cycle in prereduction.";
         res := nil;
         count := count + 1;
         work := nil;
         while g do
         << oldf := f:= car g; g := cdr g;
            oldvev := vdpevlmon f;
            f := vdpsimpcont groebnormalform (f,g,'sort);
            if (!*trgroebs or !*groebprot) and not vdpequal(f,oldf) then
            <<f := vdpenumerate f;
              if !*groebprot then
                if not vdpzero!? f then
                 groebprotsetq(mkid('poly,vdpnumber f), vdp2a f)
                 else groebprotval 0;
              if !*trgroebs then
                 <<prin2t "reducing"; vdpprint oldf; prin2t "to";
                                                    vdpprint f>>;
            >>;
            if not vdpzero!? f then
            <<if oldvev neq vdpevlmon f then work := t;
              res := f . res>>;
         >>;
      >>;
     return for each f in res collect vdpsimpcont f;
     end;
 
symbolic procedure groebreducefromfactors (g,facts);
% reduce the polynomials in G from those in facts.
   begin scalar new,gnew,f,nold,nnew,numbers;
     if !*trgroebs then <<
                  prin2t "replacing from factors:";
                  for each x in facts do vdpprin2t x
                        >>;
     while g do
          <<f := car g;
            g := cdr g;
            nold := vdpnumber(f);
            new :=  groebnormalform(f,facts,'list);
            if vdpzero!? new then
               << if !*trgroebs then <<prin2 "vanishes ";
                                       prin2 vdpnumber f
                                     >>;
               >>
            else
            if vevzero!? vdpevlmon new then
               << if !*trgroebs then <<prin2 "ONEPOL ";
                                       prin2 vdpnumber f
                                     >>;
                 g := nil;
                 gnew := list vdpone!*;
               >>
            else
            <<
              if new neq f then
               <<new := vdpenumerate vdpsimpcont new;
                 nnew := vdpnumber new;
                 numbers := (nold . nnew) . numbers;
                 if !*trgroebs then <<prin2 "replacing ";
                                      prin2 vdpnumber f;
                                      prin2 " by ";
                                      prin2t vdpnumber new
                                      >>;
               >>;
              gnew := new . gnew;
            >>;
          >>;
    secondvalue!* := numbers;
    return gnew;
    end;
 
 % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
%
%  support for Reduction by "simple" polynomials
 
symbolic procedure groebnormalform1(f,p);
    % short version; reduce f by p
    % special case: p is a nomomial
     if vdplength p = 1 then vdpcancelmvev(f,vdpevlmon p)
            else groebnormalform(f,list p,nil);
 
symbolic procedure groebprofitsfromvev(p,vev);
    % tests, if at least one monomial from p would be reduced by vev
    if vdpzero!? p then nil
        else
    if buch!-vevdivides!?(vev, vdpevlmon p) then t
        else
            groebprofitsfromvev(vdpred p,vev);
 
 
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
%
%  special reduction procedures
 
 
 
symbolic procedure groebreduceonestepint(f,f1,c,vev,g1);
      % reduction step for integer case:
      % calculate f= a*f - b*g a,b such that leading term vanishes
      %                        (vev of lvbc g divides vev of lvbc f)
      %
      % and  calculate f1 = a*f1
      % return value=f, secondvalue=f1
 begin scalar vevlcm,a,b,cg,x,rg1;
            % trivial case: g1 single monomial
      if vdpzero!? (rg1:= vdpred g1)
          then return <<f := vdpred f; secondvalue!* := f1; f>>;
      vevlcm := vevdif(vev,vdpevlmon g1);
      cg := vdplbc g1;
            % calculate coefficient factors
      x := if not !*groebdivide then vbcfi 1 else vbcgcd(c,cg);
      a := vbcquot(cg,x);
      b := vbcquot(c,x);
            % multiply relvevant parts from f and f1 by a (vbc)
      if f1 and not vdpzero!? f1 then f1 := vdpvbcprod(f1,a);
      if !*groebprot then groebreductionprotocol(a,vbcneg b,vevlcm,g1);
      f:= vdpilcomb1 (vdpred f, a, vevzero(),
                     rg1,vbcneg b, vevlcm);
            % return with f and f1
      secondvalue!*:= f1;
      thirdvalue!* := a;
      return f;
 end;
 
 
symbolic procedure groebreduceonesteprat(f,dummy,c,vev,g1);
      % reduction step for rational case:
      % calculate f= f - g/vdpLbc(f)
      %
 begin scalar x,rg1,vevlcm;
            % trivial case: g1 single monomial
      dummy := nil;
      if vdpzero!? (rg1 := vdpred g1) then return vdpred f ;
            % calculate coefficient factors
      x := vbcneg vbcquot(c,vdplbc g1);
      vevlcm := vevdif(vev,vdpevlmon g1);
      if !*groebprot then 
         groebreductionprotocol(a2vbc 1,x,vevlcm,g1);
      return vdpilcomb1(vdpred f,a2vbc 1,vevzero(),
                            rg1,x,vevlcm);
 end;
 
 
symbolic procedure groebreductionprotocol(a,b,vevlcm,g1);
    if !*groebprot then
        groebprotfile :=
        if not vbcone!? a then
         append(groebprotfile,
                list(
                   list('equal,
                        'candidate,
                         list('times,'candidate,vbc2a a)),
                   list('equal,
                        'candidate,
                        list('plus,
                             'candidate,
                             list('times,
                                  vdp2a vdpfmon(b,vevlcm),
                                  mkid('poly,vdpnumber g1) )))
               )    )
        else
        append(groebprotfile,
                list(
                   list('equal,
                        'candidate,
                        list('plus,
                             'candidate,
                             list('times,
                                  vdp2a vdpfmon(b,vevlcm),
                                  mkid('poly,vdpnumber g1) )))
 
               )    ) ;
 
symbolic procedure groebreductionprotocol2 a;
      if !*groebprot then
        groebprotfile :=
	if not(a=1) then
         append(groebprotfile,
                list(
                   list('equal,
                        'candidate,
                         list('times,'candidate,a))));

symbolic procedure groebreductionprotocolborder();
        append(groebprotfile,'!+!+!+!+!+!+!+!+!+!+!+!+!+!+!+!+ . nil);
 
 
 
symbolic procedure groebprotsetq(a,b);
    groebprotfile :=
      append (groebprotfile,
              list (list ('equal,a,b)));
 
symbolic procedure groebprotval a;
    groebprotfile :=
      append (groebprotfile,
              list (list ('equal,'intermediateresult,a)));
 
 

symbolic procedure subset!?(s1,s2);
    % tests if s1 is a subset of s2
       if null s1 then t
          else
       if member(car s1,s2) then subset!?(cdr s1,s2)
          else
            nil;

symbolic procedure vevsplit (vev);
      % split vev such that each exponent vector has only one 1
      begin scalar n,vp,e;
        n := 0;
        for each x in vev do
            <<n := n+1;
              if x neq 0 then
                <<e := append (vdpevlmon vdpone!*,nil);
                  rplaca(pnth(e,n),1);
                  vp := e . vp;
                >>;
            >>;
        return vp;
     end;
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%   calculation of an S-polynomial
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
%general strategy:
%
%  groebSpolynom4 calculates the traditional s-Polynomial from p1,p2
%    (linear combination such that the highest term vanishes).
%  groebSpolynom2 subtracts multiples of p2 from the s-polynomial such
%    that head terms are eliminated early.
 
symbolic procedure groebspolynom (p1,p2);
     groebspolynom2(p1,p2);
 
 
symbolic procedure groebspolynom2 (p1,p2);
     if vdpzero!? p1 then p2 else if vdpzero!? p2 then p1 else
   begin scalar s,tp1,tp2,ts,cand;
     s := groebspolynom3(p1,p2);
     if vdpzero!? s or vdpone!? s or !*groebprot then return s;
     tp1 := vdpevlmon p1; tp2 := vdpevlmon p2;
     while not vdpzero!? s
       and ((buch!-vevdivides!?(tp2,(ts := vdpevlmon s))
		and (cand := p2))
	   or
	   (buch!-vevdivides!?(tp1,(ts := vdpevlmon s))
		and (cand := p1)))
	do << if !*vdpinteger then
                    s := % vdpsimpcont 
                          groebreduceonestepint(s,nil,vdplbc s,ts,cand)
                       else
                          % rational, float and modular case
                        s := groebreduceonesteprat
                                  (s,nil,vdplbc s,ts,cand);
           >>;
     return s;
   end;
 
symbolic procedure groebspolynom3(p,q);
   begin scalar r;
     r:=groebspolynom4(p,q);
     groebsavelterm r;
     return r;
   end;

symbolic procedure groebspolynom4 (p1,p2);
  begin scalar ep1,ep2,ep,rp1,rp2,db1,db2,x,r;
    ep1 := vdpevlmon p1; ep2 := vdpevlmon p2;
    ep := vevlcm(ep1, ep2);
    rp1 := vdpred p1; rp2 := vdpred p2;
    gsetsugar(rp1,gsugar p1); gsetsugar(rp2,gsugar p2);
    r:=     ( if vdpzero!? rp1 and vdpzero!? rp2 then rp1
              else ( if vdpzero!? rp1 then
                      <<db2:=a2vbc 0;
                        vdpprod(rp2,
                                vdpfmon(db1:=a2vbc 1,
                                       vevdif(ep, ep2) ) )
                      >>
                     else if vdpzero!? rp2 then
                      <<db1:=a2vbc 0;
                        vdpprod(rp1,
                                vdpfmon(db2:=a2vbc 1,
                                        vevdif(ep, ep1) ) )
                      >>
                          else
                             <<db1 := vdplbc p1;
                               db2 := vdplbc p2;
                               if !*vdpinteger then
                                  << x:= vbcgcd (db1,db2);
                                     if not vbcone!? x then
                                     << db1 := vbcquot (db1,x);
                                        db2 := vbcquot (db2,x);
                                  >> >>;
                                vdpilcomb1 (rp2,db1,vevdif(ep,ep2),
                                          rp1,vbcneg db2,vevdif(ep,ep1))
                             >>
                   )
            );
     if !*groebprot then
        groebprotsetq('candidate, 
         {'difference,
           {'times,vdp2a vdpfmon(db2,vevdif(ep,ep2)), 
                   mkid('poly,vdpnumber p1)},
           {'times,vdp2a vdpfmon(db1,vevdif(ep,ep1)),
                      mkid('poly,vdpnumber p2)}} );
        
     return r;
end;
 
symbolic procedure groebsavelterm r;
     if !*groelterms and not vdpzero!? r then
        groebsaveltermbc vdplbc r;

symbolic procedure groebsaveltermbc r;
     <<r:=vbc2a r;
       if not numberp r and not constant_exprp r then
         for each p in cdr fctrf numr simp r do
         <<p:=prepf car p;
           if not member(p,glterms) then nconc(glterms,list p);
      >> >>;

symbolic procedure sfcont f;
   % Calculate the integer content of standard form f.
      if domainp f then f else
      gcdf(sfcont lc f, sfcont red f);

symbolic procedure vdplmon u; vdpfmon (vdplbc u,vdplbc u);
 
symbolic procedure vdpmember3(p,g1,g2,g3);
     % test membership of p in one of then lists g1,g2,g3
       vdpmember(p,g1) or vdpmember(p,g2) or vdpmember(p,g3);

symbolic procedure groeb!-abort!-id(base,abort1);
   % Test whether one of the elements in abort1 is
   % member of the ideal described by base. Definite
   % test here.
  if null abort1 then nil else 
   vdpzero!?(groebnormalform(car abort1,base,'list))
     or groeb!-abort!-id(base,cdr abort1);

endmodule;

end;

