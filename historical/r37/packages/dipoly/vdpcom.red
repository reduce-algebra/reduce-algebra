module vdpcom;
 
% common routines to all vdp mappings
 

fluid '(intvdpvars!* vdpvars!* secondvalue!* vdpsortmode!* !*groebrm
	!*vdpinteger !*trgroeb !*groebdivide pcount!* !*gsugar
         vdpsortextension!* );


global '(vdpprintmax);
flag('(vdpprintmax),'share);
vdpprintmax := 5;
 
% Repeat of smacros defined in vdp2dip.

smacro procedure vdpPoly u; cadr cddr u;

smacro procedure vdpzero!? u;
    null u or null vdpPoly u;

smacro procedure vdpevlmon u; cadr u;

 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  manipulating of exponent vectors
%
 
symbolic procedure vevnth (a,n);
 % extract nth element from a
   if null a then 0 else if n=1 then car a else vevnth(cdr a,n #- 1);
 
% unrolled code for zero test (very often called)
smacro procedure vevzero!? u;
        null u or (car u = 0 and vevzero!?1 cdr u);
 
symbolic procedure vevzero!?1 u;
        null u or (car u = 0 and vevzero!? cdr u);
 
symbolic procedure veveq(vev1,vev2);
  if null vev1 then vevzero!? vev2
  else if null vev2 then vevzero!? vev1
  else (car vev1 = car vev2 and vevequal(cdr vev1,vev2));
   
symbolic procedure vevmaptozero e;
 %  generate an exponent vector with same length as e and zeros only
        vevmaptozero1(e,nil);
 
symbolic procedure vevmaptozero1(e,vev);
     if null e then vev else vevmaptozero1(cdr e, 0 . vev);
 
symbolic procedure vevmtest!? (e1,e2);
%  /* Exponent vector multiple test. e1 and e2 are compatible exponent
%    vectors. vevmtest?(e1,e2) returns a boolean expression.
%    True if exponent vector e1 is a multiple of exponent
%    vector e2, else false. */
    if null e2 then t
    else if null e1 then if vevzero!? e2 then t else nil
    else not(car e1 #<car e2)and vevmtest!?(cdr e1,cdr e2);
 
 
symbolic procedure vevlcm (e1,e2);
%  /* Exponent vector least common multiple. e1 and e2 are
%    exponent vectors. vevlcm(e1,e2) computes the least common
%    multiple of the exponent vectors e1 and e2, and returns
%    an exponent vector. */
   begin scalar x;
      while e1 and e2 do
         <<x := (if car e1 #> car e2 then car e1 else car e2) . x;
           e1 := cdr e1; e2 := cdr e2>>;
      x := reversip x;
      if e1 then x := nconc(x,e1)
      else if e2 then x := nconc(x,e2);
      return x;
   end;
 
symbolic procedure vevmin (e1,e2);
%   Exponent vector minima
   begin scalar x;
      while e1 and e2 do
         <<x := (if car e1 #< car e2 then car e1 else car e2) . x;
           e1 := cdr e1; e2 := cdr e2>>;
      while x and 0=car x do x := cdr x;  % cut trailing zeros
      return reversip x;
   end;
 
symbolic procedure vevsum (e1,e2);
%  /* Exponent vector sum. e1 and e2 are exponent vectors.
%    vevsum(e1,e2) calculates the sum of the exponent vectors.
%    e1 and e2 componentwise and returns an exponent vector. */
   begin scalar x;
      while e1 and e2 do
         <<x := (car e1 #+ car e2) . x;e1 := cdr e1; e2 := cdr e2>>;
      x := reversip x;
      if e1 then x := nconc(x,e1)
      else if e2 then x := nconc(x,e2);
      return x;
   end;
 
 
symbolic procedure vevtdeg u;
% calculate the total degree of u
   if null u then 0 else car u #+ vevtdeg cdr u;
 
symbolic procedure vdptdeg u;
   if vdpzero!? u then 0 else
   max(vevtdeg vdpevlmon u,vdptdeg vdpred u);
 
symbolic procedure vevdif (ee1,ee2);
%    Exponent vector difference. e1 and e2 are exponent
%    vectors. vevdif(e1,e2) calculates the difference of the
%    exponent vectors e1 and e2 componentwise and returns an
%    exponent vector.
   begin scalar x,y,break,e1,e2;
      e1 := ee1; e2 := ee2;
      while e1 and e2 and not break do
         <<y := (car e1 #- car e2); x := y . x;
           break := y #< 0;
           e1 := cdr e1; e2 := cdr e2>>;
      if break or (e2 and not vevzero!? e2) then
        <<print ee1; print ee2; 
          if getd 'backtrace then backtrace();
	 return rerror(dipoly,5,"Vevdif, difference would be < 0")>>;
      return nconc(reversip x,e1);
   end;
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% numbering of polynomials
%
 
  symbolic procedure vdpEnumerate f;
  % f is a temporary result. Prepare it for medium range storage
  % and ssign a number
  if vdpzero!? f then f else
  << f := vdpsave f;
     if not vdpGetProp(f,'NUMBER) then
        f := vdpPutProp(f,'NUMBER,(pcount!* := pcount!* #+ 1));
     f>>;

%smacro procedure vdpNumber f;
%     vdpGetProp(f,'NUMBER) ;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% SUGAR of polynomials
%

symbolic procedure gsugar p;
   if !*gsugar then
    ((s or 
        << print list("*** missing sugar",p);  
           backtrace();
          s:=vdptdeg p; 
          gsetsugar(p,s);
          s>>
      ) where s= if vdpzero!? p then 0 else vdpgetprop(p,'SUGAR));

symbolic procedure gsetsugar(p,s);
   !*gsugar and vdpputprop(p,'SUGAR,s or vdptdeg p) or p;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  operations on sets of polynomials
%
 
symbolic procedure vdpMember(p1,l);
% test membership of a polynomial in a list of polys
      if null l then nil
         else
      if vdpEqual(p1,car l) then l
         else
               vdpMember(p1,cdr l);
 
 
symbolic procedure vdpUnion (s1,s2);
 % s1 and s2 are two sets of polynomials.
 % union of the sets using vdpMember as crit
   if null s1 then s2
      else
   if vdpmember(car s1,s2) then vdpUnion(cdr s1,s2)
      else car s1 . vdpUnion(cdr s1,s2);
  
symbolic procedure vdpIntersection (s1,s2);
 % s1 and s2 are two sets of polynomials.
 % intersection of the sets using vdpMember as crit
   if null s1 then NIL
      else
   if vdpmember(car s1,s2) then car s1 . vdpUnion(cdr s1,s2)
      else vdpUnion(cdr s1,s2);
 
symbolic procedure vdpSetEqual!?(s1,s2);
 % tests if s1 and s2 have the same polynomials as members
     if not (length s1 = length s2) then nil
         else vdpSetEqual!?1(s1,append(s2,nil));
 
symbolic procedure vdpSetEqual!?1(s1,s2);
  % destroys its second parameter (is therefor copied when called)
     if null s1 and null s2 then t
         else
     if null s1 or null s2 then nil
         else
     (if hugo then vdpSetEqual!?1(cdr s1,groedeletip(car hugo,s2))
        else nil) where hugo = vdpMember(car s1,s2);
 
 

symbolic procedure vdpSortedSetEqual!?(s1,s2);
 % tests if s1 and s2 have the same polynomials as members
 % here assuming, that both sets are sorted by the same
 % principles
     if null s1 and null s2 then t
         else
     if null s1 or null s2 then nil
         else
     if vdpequal(car s1,car s2) then
       vdpSortedSetEqual!?(cdr s1,cdr s2)
          else NIL;


symbolic procedure vdpDisjoint!? (s1,s2);
 % s1 and s2 are two sets of polynomials.
 % test that there are no common members
   if null s1 then T
      else
   if vdpmember(car s1,s2) then NIL
      else vdpDisjoint!?(cdr s1,s2);

symbolic procedure vdpSubset!? (s1,s2);
    not(length s1 > length s2) and vdpSubset!?1(s1,s2);


symbolic procedure vdpSubset!?1 (s1,s2);
 % s1 and s2 are two sets of polynomials.
 % test if s1 is subset of s2
    if null s1 then T
      else
   if vdpmember(car s1,s2) then vdpSubset!?1 (cdr s1,s2)
      else NIL;

symbolic procedure vdpDeleteMember(p,l);
   % delete polynomial p from list l
    if null l then nil
        else
    if vdpequal(p,car l) then vdpdeletemember(p,cdr l)
        else car l . vdpdeletemember(p,cdr l);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  sorting of polynomials
%
 
symbolic procedure   vdplsort pl;
%  /* Distributive polynomial list sort. pl is a list of
%    distributive polynomials. vdplsort(pl) returns the
%    sorted distributive polynomial list of pl.
   sort(pl, function vdpvevlcomp);
 
symbolic procedure  vdplsortin (po,pl);
%    po is a polynomial, pl is a list of polynomials.
%    po is inserted into pl at its place determined by vevlcompless?.
%    the result is the updated pl;
   if null pl then list po
   else if vevcompless!? (vdpevlmon po, vdpevlmon car pl)
       then  car pl . vdplsortin (po, cdr pl)
     else po . pl;
 
symbolic procedure  vdplsortinreplacing (po,pl);
%    po is a polynomial, pl is a list of polynomials.
%    po is inserted into pl at its place determined by vevlcompless?.
%    if there is a multiple of the exponent of pl, this is deleted
%    the result is the updated pl;
   if null pl then list po
   else if vevdivides!? (vdpevlmon po, vdpevlmon car pl) 
       then vdplsortinreplacing (po, cdr pl)
   else if vevcompless!? (vdpevlmon po, vdpevlmon car pl)
       then  car pl . vdplsortinreplacing (po, cdr pl)
     else po . pl;





%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% property lists for polynomials
%

symbolic procedure vdpPutProp (poly,prop,val);
   begin scalar c,p;
      if not pairp poly or not pairp (c := cdr poly)
                        or not pairp (c := cdr c)
                        or not pairp (c := cdr c)
                        or not pairp (c := cdr c  ) 
	    then rerror(dipoly,6,
                  list("vdpPutProp given a non-vdp as 1st parameter",
			poly,prop,val));
      p := assoc(prop,car c);
      if p then rplacd(p,val)
           else rplaca(c,(prop . val) . car c);
      return poly;
   end;

symbolic procedure vdpGetProp (poly,prop);
     if null poly then nil  % nil is a legal variant of vdp=0
       else
     if not eqcar(poly,'vdp)
	    then rerror(dipoly,7,
                  list("vdpGetProp given a non-vdp as 1st parameter",
			poly,prop))
       else
      (if p then cdr p else nil)
          where p=assoc(prop,cadr cdddr poly);
 
symbolic procedure vdpRemAllProps u; 
     begin scalar c;
      if not pairp u or not pairp (c := cdr u)
		     or not pairp (c := cdr c)
		     or not pairp (c := cdr c)
		     or not pairp (c := cdr c)
            then return u;
      rplaca(c,NIL); return u;
     end;
         
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Groebner interface to power substitution
 
fluid '(!*sub2);

symbolic procedure groebsubs2 q;
     (subs2 q) where !*sub2=t;

% and a special print
symbolic procedure vdpprintshort u;
    begin scalar m;
       m := vdpprintmax;
       vdpprintmax:= 2;
       vdpprint u;
       vdpprintmax:=m;
    end;

endmodule;
 
end;
