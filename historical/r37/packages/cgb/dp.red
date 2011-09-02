% ----------------------------------------------------------------------
% $Id: dp.red,v 1.18 1999/04/13 21:44:23 sturm Exp $
% ----------------------------------------------------------------------
% Copyright (c) 1999 Andreas Dolzmann and Thomas Sturm
% ----------------------------------------------------------------------
% $Log: dp.red,v $
% Revision 1.18  1999/04/13 21:44:23  sturm
% Added fluid declaration for !*tdusetorder.
% Added call to ev_init in dip_init.
%
% Revision 1.17  1999/04/13 18:42:03  dolzmann
% Removed fluid declaration for !*gsugar.
% Added procedure dip_comp.
%
% Revision 1.16  1999/04/11 09:47:01  dolzmann
% Changed procedure dip_init: The current polynomial ring is defined by
% parameters and not by global variables.
% Moved module vdp from this file to gb.red.
% Removed procedures td_usetorder and td_unusetorder and replaced them
% by access functions to the global variables used by td and torder
% respectively.
%
% Revision 1.15  1999/04/06 15:04:18  dolzmann
% Moved procedures dip_append, dip_cp, dip_dcont, and dip_dcont1 from
% module dipto into module dip.
% Moved procedures bc_mkat, bc_dcont, and bc_2d from module bcto into the
% bc modules of the dip package.
%
% Revision 1.14  1999/04/06 11:54:26  dolzmann
% Removed module module vdpprint.
%
% Revision 1.13  1999/04/04 17:17:04  sturm
% Turned smacros into regular procedures.
%
% Revision 1.12  1999/04/04 16:46:18  sturm
% Added copyright and CVS fluids.
%
% Revision 1.11  1999/04/04 14:50:38  sturm
% Implemented switch tdusetorder.
%
% Revision 1.10  1999/04/04 14:09:32  sturm
% Moved dip_ilcomb and dip_ilcombr from cgb.red to dp.red.
% Created vdp_ilcomb and vdp_ilcombr for gb.red.
%
% Revision 1.9  1999/04/04 12:20:31  dolzmann
% Added initialization of td_sortmode!*.
%
% Revision 1.8  1999/04/03 13:39:16  sturm
% New td/dip_init/dip_cleanup scheme.
%
% Revision 1.7  1999/03/31 14:09:55  sturm
% Fixed numerous details encountered during CGB reimplementation.
%
% Revision 1.6  1999/03/17 12:33:43  dolzmann
% Added new procedures vdp_monp and dip_monp.
% Added new procedure ev_member.
% Added new procedure ev_init.
% Renamed procedure max!# into ev_max!#.
%
% Revision 1.5  1999/03/12 10:59:08  dolzmann
% Added procedure ev_sdvip.
% Moved procedure vdp_ilcomb1 and vdp_ilcomb1r into package dp and
% renamed the procedures accordingly.
%
% Revision 1.4  1999/03/12 08:54:48  dolzmann
% dded term orders lex and xrevgradlex.
% Changed smacros for bc-layer and ev-layer into procedures.
% Replaced all long integer arithmetic on exponents by machine
% integers arithmetic.
% Added procedure ev_disjointp for ev-layer independent implementation
% of Buchbergers first criterion.
% Procedure dip_condense now uses one call of ev_comp instead of one
% call of ev_compless!? and one equal test.
% Added procedure vdp_nconcmon.
% Replaced the long integer arithmetic on the sugar property by
% machine integer arithmetic.
% Introduec procedures vdp_setnumber for plist independent Groebner
% code.
% Changed assoc in vdp_putprop and vdp_getprop into atsoc.
%
% Revision 1.3  1999/03/08 17:21:31  dolzmann
% Fixed yet another bug in td_torder. Added lex term ordering mode.
%
% Revision 1.2  1999/03/08 16:22:53  dolzmann
% Fixed some bugs in td_torder.
%
% Revision 1.1  1999/03/05 10:28:37  dolzmann
% Newly derived from dipoly.red. Initial check-in.
%
% ----------------------------------------------------------------------
lisp <<
   fluid '(dp_rcsid!* dp_copyright!*);
   dp_rcsid!* := "$Id: dp.red,v 1.18 1999/04/13 21:44:23 sturm Exp $";
   dp_copyright!* := "Copyright (c) 1999 by A. Dolzmann and T. Sturm"
>>;

module dp;

fluid '(kord!*);

fluid '(dip_evlist!* dip_vars!* dip_sortmode!* dip_sortevcomp!*
   dip_sortextension!* vdpsortmode!* vdpsortextension!* global!-dipvars!*);

fluid '(td_vars!* td_sortmode!* td_sortextension!* !*tdusetorder);
td_vars!* := '(list);

td_sortmode!* := 'revgradlex;
   
put('td,'psopfn,'td_torder);

flag('(xrevgradlex revgradlex lex),'dipsortmode);
put('revgradlex,'ev_comp,'ev_revgradlexcomp);
put('lex,'ev_comp,'ev_lexcomp);
put('xrevgradlex,'ev_comp,'ev_xrevgradlexcomp);

switch tdusetorder;

on1 'tdusetorder;

endmodule;  % dp

module bcsq;

procedure bc_zero();
   nil ./ 1;

procedure bc_zero!?(u);
   null numr u;

procedure bc_abs(u);
   absf numr u ./ denr u;

procedure bc_one!?(u);
   numr u = 1 and denr u = 1;

procedure bc_2sq(u);
   u;

procedure bc_a2bc(u);
   % Converts the algebraic (kernel) u into a base coefficient.
   simp!* u;

procedure bc_fd a;
   % Base coefficient from domain element.
   a ./ 1;

procedure bc_neg(u);
   % Base coefficient negative. u is a base coefficient. bc_neg(u)
   % returns the negative of the base coefficient u, a base
   % coefficient.
   negsq u;

procedure bc_prod(a,b);
   if denr a = 1 and numberp numr a and denr b = 1 and numberp numr b then
      if numr a = 1 then
	 b
      else if numr b = 1 then
	 a
      else if (a := times2(numr a,numr b)) = 0 then
	 nil ./ 1
      else
	 a ./ 1
   else
      multsq(a,b);

procedure bc_quot(a,b);
   if denr a = 1 and numberp numr a and denr b = 1 and numberp numr b then
      if numr b = 1 then
	 a
      else if (a := quotientx(numr a,numr b)) = 0 then
	 nil ./ 1
      else
	 a ./ 1
   else
      quotsq(a,b);

procedure bc_sum(a,b);
   % Base coefficient sum. u and v are base coefficients. bcsum(u,v)
   % calculates u+v and returns a base coefficient.
   if denr a = 1 and numberp numr a and denr b = 1 and numberp numr b then
      if (a := plus2(numr a,numr b)) = 0 then
	 nil ./ 1
      else
	 a ./ 1
   else
      addsq(a,b);

procedure bc_pmon(var,dg);
   % Parameter monomial.
   var .** dg .* 1 .+ nil ./ 1;


procedure bc_minus!?(u);
   % Boolean function. Returns true if u is a negative base coeff.
   if fixp numr u then
      numr u < 0
   else
      minusf numr u;

procedure bc_2a(u);
   % Returns the prefix equivalent of the base coefficient u.
   prepsq u;

procedure bc_gcd(u,v);
   if denr u = 1 and denr v = 1 then
      if fixp numr u and fixp numr v then
 	 gcdn(numr u,numr v) ./ 1
      else
      	 gcdf!*(numr u,numr v) ./ 1
   else
      1 ./ 1;

procedure bc_mkat(op,bc);
   {op,numr bc,nil};

procedure bc_dcont(bc);
   sfto_dcontentf numr bc;

procedure bc_2d(bc);
   numr bc or 0;

endmodule;  % bcsq

module ev;

procedure ev_max!#(a,b);
   if a #> b then a else b;

procedure ev_init();
   ;

procedure ev_member(ev,evl);
   ev member evl;

procedure ev_divides!?(ev1,ev2);
   ev_mtest!?(ev2,ev1);

procedure ev_sdivp(ev1,ev2);
   ev1 neq ev2 and ev_divides!?(ev1,ev2);

procedure ev_xrevgradlexcomp(e1,e2);
   % Exponent vector reverse graduated lex compare. The exponent
   % vectors e1 and e2 are in reverse graduated lex ordering.
   % evRevGradLexcomp(e1,e2) returns the digit 0 if exponent vector e1
   % is equal exponent vector e2, the digit 1 if e1 is greater than
   % e2, else the digit -1.
   begin scalar te1,te2;
      if null e1 then
      	 return 0;
      if car e1 #= car e2 then
      	 return ev_xrevgradlexcomp(cdr e1,cdr e2);
      te1 := ev_tdeg e1;
      te2 := ev_tdeg e2;
      if te1 #= te2 then
	 return if car e1 #< car e2 then 1 else -1;
      return if te1 #> te2 then 1 else -1
   end;

procedure ev_lexcomp(e1,e2);
   % Exponent vector lexicographical compare. The exponent vectors e1
   % and e2 are in lexicographical ordering. evLexComp(e1,e2) returns
   % the digit 0 if exponent vector e1 is equal exponent vector e2,
   % the digit 1 if e1 is greater than e2, else the digit -1. */
   if null e1 then
      0
   else if car e1 #= car e2 then
      ev_lexcomp(cdr e1,cdr e2)
   else if car e1 #> car e2 then
      1
   else
      -1;

procedure ev_revgradlexcomp(e1,e2);
   % Exponent vector reverse graduated lex compare. The exponent
   % vectors e1 and e2 are in reverse graduated lex ordering.
   % evRevGradLexcomp(e1,e2) returns the digit 0 if exponent vector e1
   % is equal exponent vector e2, the digit 1 if e1 is greater than
   % e2, else the digit -1.
   begin scalar te1,te2;
      if null e1 then
      	 return 0;
      if car e1 #= car e2 then
	 return ev_revgradlexcomp(cdr e1, cdr e2);
      te1 := ev_tdeg e1;
      te2 := ev_tdeg e2;
      if te1 #= te2 then
 	 return ev_invlexcomp(e1,e2);
      if te1 #> te2 then
 	 return 1;
      return -1
   end;

procedure ev_invlexcomp(e1,e2);
   % Exponent vector inverse lexicographical compare. No term order!
   begin scalar n;
      if null e1 then
	 return 0;
      if car e1 #= car e2 then
 	 return ev_invlexcomp(cdr e1,cdr e2);  % sic!
      n := ev_invlexcomp(cdr e1,cdr e2);
      if not (n #= 0) then
 	 return n;
      if car e2 #= car e1 then
 	 return 0;
      if car e2 #> car e1 then
 	 return 1;
      return -1
   end;

procedure ev_mtest!?(e1,e2);
   % Exponent vector multiple test. e1 and e2 are compatible exponent
   % vectors. vevmtest?(e1,e2) returns a boolean expression. True if
   % exponent vector e1 is a multiple of exponent vector e2, else
   % false.
   begin scalar r;
      r := t;
      while e1 and r do <<
	 if car e1 #< car e2 then
	    e1 := r := nil
	 else <<
	    e1 := cdr e1;
	    e2 := cdr e2
	 >>
      >>;
      return r
   end;
      
procedure ev_2a(e);
   % Returns list of prefix equivalents of exponent vector e.
   ev_2a1(e,dip_vars!*);

procedure ev_2a1(u,v);
   if null u then
      nil
   else if car u #= 0 then
      ev_2a1(cdr u,cdr v)
   else if car u #= 1 then
      car v . ev_2a1(cdr u,cdr v)
   else
      {'expt,car v,car u} . ev_2a1(cdr u,cdr v);

procedure ev_2f(ev,vars);
   if null ev then
      1
   else if car ev #= 0 then
      ev_2f(cdr ev,cdr vars)
   else
      multf(car vars .** car ev .* 1 .+ nil,ev_2f(cdr ev,cdr vars));

procedure ev_lcm(e1,e2);
   % Exponent vector least common multiple. e1 and e2 are exponent
   % vectors. ev_lcm(e1,e2) computes the least common multiple of the
   % exponent vectors e1 and e2, and returns an exponent vector.
   begin scalar x;
      while e1 do <<
	 x := (if car e1 #> car e2 then car e1 else car e2) . x;
	 e1 := cdr e1;
 	 e2 := cdr e2
      >>;
      return reversip x
   end;

procedure ev_zero();
   for each x in dip_vars!* collect 0;

procedure ev_zero!?(ev);
   null ev or eqcar(ev,0) and ev_zero!? cdr ev;

procedure ev_compless!?(e1,e2);
   ev_comp(e2,e1) #= 1;

procedure ev_comp(e1,e2);
   % Exponent vector compare. e1, e2 are exponent vectors in some
   % order. Evcomp(e1,e2) returns the digit 0 if exponent vector e1 is
   % equal exponent vector e2, the digit 1 if e1 is greater than e2,
   % else the digit -1. This function is assigned a value by the
   % ordering mechanism, so is dummy for now. IDapply would be better
   % here, but is not within standard LISP!
   apply(dip_sortevcomp!*,{e1,e2});

procedure ev_insert(ev,v,dg,vars);
   % f to dip conversion: Insert the "dg" into the ev in the place of
   % variable v.
   if null ev or null vars then
      nil
   else if car vars eq v then
      dg . cdr ev
   else
      car ev . ev_insert(cdr ev,v,dg,cdr vars);

procedure ev_tdeg(u);
   % calculate the total degree of u.
   begin integer x;
      while u do <<
	 x := car u #+ x;
 	 u := cdr u
      >>;
      return x
   end;

procedure ev_dif(e1,e2);
   begin scalar s;
      while e1 do <<
	 s := (car e1 #- car e2) . s;
	 e1 := cdr e1;
	 e2 := cdr e2
      >>;
      return reversip s
   end;

procedure ev_sum(e1,e2);
   begin scalar s;
      while e1 do <<
	 s := (car e1 #+ car e2) . s;
	 e1 := cdr e1;
	 e2 := cdr e2
      >>;
      return reversip s
   end;

procedure ev_disjointp(e1,e2);
   % nonconstructive test of lcm(e1,e2) = e1 + e2 equivalent: no
   % matches of nonzero elements.
   if null e1 then
      t
   else if (car e1 neq 0) and (car e2 neq 0) then
      nil
   else
      ev_disjointp(cdr e1,cdr e2);

procedure ev_identify(oev,nev);
   nev;

endmodule;  % ev

module dip;

procedure dip_fmon(a,e);
   % Distributive polynomial from monomial. a is a base coefficient
   % and e is an exponent vector. dip_fmon(a,e) returns a distributive
   % polynomial with e as exponent vector and a as base coefficient.
   e . a . nil;

procedure dip_moncomp(a,e,p);
   % Distributive polynomial monomial composition. a is a base
   % coefficient, e is an exponent vector and p is a distributive
   % polynomial. dipmoncomp(a,e,p) returns a distributive polynomial
   % with p as monomial reductum, e as exponent vector of the leading
   % monomial and a as leading base coefficient.
   e . a . p;

procedure dip_mred(p);
   % Distributive polynomial reductum. p is a distributive polynomial
   % dipmred(p) returns the reductum of the distributive polynomial p,
   % a distributive polynomial.
   cddr p;

procedure dip_lbc(p);
   % Distributive polynomial leading base coefficient. p is a
   % distributive polynomial. dip_lbc(p) returns the leading base
   % coefficient of p.
   cadr p;

procedure dip_evlmon(p);
   % Distributive polynomial exponent vector leading monomial. p is a
   % distributive polynomial. dipevlmon(p) returns the exponent vector
   % of the leading monomial of p.
   car p;

procedure dip_init(newvars,newsortmode,newsortextension);
   % Initializing dip polynomial package.
   begin scalar vars,sortmode,sortextension,sortevcomp,evlist,newsortevcomp,z;
      if not idp newsortmode or not flagp(newsortmode,'dipsortmode) then
 	 return typerr(newsortmode,"term ordering mode");
      % following saves thousands of calls to GET:
      newsortevcomp := get(newsortmode,'ev_comp);
      if not getd newsortevcomp then
	 rederr "dip_init: no comparison routine found";
      if (z := get(newsortmode,'evcompinit)) then
 	 apply(z,nil);
      if (z := get(newsortmode,'evlength)) and z neq length newvars then
 	 rederr "dip_init: wrong variable number for fixed length term order";
      vars := dip_vars!*;
      sortmode := dip_sortmode!*;
      sortextension := dip_sortextension!*;
      sortevcomp := dip_sortevcomp!*;
      evlist := dip_evlist!*;
      dip_vars!* := newvars;
      dip_sortmode!* := newsortmode;
      dip_sortextension!* := newsortextension;
      dip_sortevcomp!* := newsortevcomp;
      dip_evlist!* := {nil};
      ev_init();
      return {vars,sortmode,sortextension,sortevcomp,evlist}
   end;

procedure dip_cleanup(l);
   % l = (vars sortmode sortextension sortevcomp evlist).
   <<
      dip_vars!* := car l;
      l := cdr l;
      dip_sortmode!* := car l;
      l := cdr l;
      dip_sortextension!* := car l;
      l := cdr l;
      dip_sortevcomp!* := car l;
      l := cdr l;
      dip_evlist!* := car l
   >>;

procedure dip_monp(u);
   u and not cddr u;

procedure dip_2f(u);
   numr dip_2sq u;

procedure dip_2sq(u);
   % convert a dip into a standard quotient.
   if null u then
      nil ./ 1
   else
      addsq(dip_lmon2sq(dip_lbc u,dip_evlmon u),dip_2sq dip_mred u);

procedure dip_lmon2sq(bc,ev);
   % convert a monomial into a standard quotient.
   multsq(bc_2sq bc,ev_2f(ev,dip_vars!*) ./ 1);

procedure dip_f2dip(u);
   dip_f2dip1(u,ev_zero(),bc_fd 1);

procedure dip_f2dip1(u,ev,bc);
   % f to dip conversion: scan the standard form. ev and bc are the
   % exponent and coefficient parts collected so far from higher parts.
   if null u then
      nil
   else if domainp u then
      dip_fmon(bc_prod(bc,bc_fd u),ev)
   else
      dip_sum(dip_f2dip2(mvar u,ldeg u,lc u,ev,bc),dip_f2dip1(red u,ev,bc));

procedure dip_f2dip2(var,dg,c,ev,bc);
   % f to dip conversion: multiply leading power either into exponent
   % vector or into the base coefficient.
   if memq(var,dip_vars!*) then
      dip_f2dip1(c,ev_insert(ev,var,dg,dip_vars!*),bc)
   else
      dip_f2dip1(c,ev,bc_prod(bc,bc_pmon(var,dg)));

procedure dip_prod(p1,p2);
   % Distributive polynomial product. p1 and p2 are distributive
   % polynomials. dipprod(p1,p2) calculates the product of the two
   % distributive polynomials p1 and p2, a distributive polynomial*/
   if dip_length p1 <= dip_length p2 then
      dip_prodin(p1,p2)
   else
      dip_prodin(p2,p1);

procedure dip_prodin(p1,p2);
   % Distributive polynomial product internal. p1 and p2 are distrib
   % polynomials. dipprod(p1,p2) calculates the product of the two
   % distributive polynomials p1 and p2, a distributive polynomial.
   begin scalar bp1,ep1;
      if null p1 or null p2 then
      	 return nil;
      bp1 := dip_lbc p1;
      ep1 := dip_evlmon p1;
      return dip_moncomp(bc_prod(bp1,dip_lbc p2),ev_sum(ep1,dip_evlmon p2),
      	 dip_sum(dip_prodin(dip_fmon(bp1,ep1),dip_mred p2),
	    dip_prodin(dip_mred p1,p2)))
   end;

procedure dip_sum(p1,p2);
   % Distributive polynomial sum. p1 and p2 are distributive
   % polynomials. dipsum(p1,p2) calculates the sum of the two
   % distributive polynomials p1 and p2. Iterative version, better
   % suited for very long polynomials. Warning: this routine uses
   % "dipmred" == "cdr cdr" for a destructive concatenation.
   begin scalar w,rw,sl,ep1,ep2,nt,al,done;
      while not done do <<
	 if null p1 then <<
	    nt := p2;
 	    done := t
	 >> else if null p2 then <<
	    nt := p1;
 	    done := t
	 >> else <<
	    ep1 := dip_evlmon p1;
	    ep2 := dip_evlmon p2;
	    sl := ev_comp(ep1,ep2);
	    % Compute the next term.
	    if sl #= 1 then <<
	       nt := dip_moncomp(dip_lbc p1,ep1,nil);
	       p1 := dip_mred p1
	    >> else if sl #= -1 then <<
	       nt := dip_moncomp(dip_lbc p2,ep2,nil);
	       p2 := dip_mred p2
	    >> else <<
	       al := bc_sum(dip_lbc p1,dip_lbc p2);
	       nt := if not null al then
 		  dip_moncomp(al,ep1,nil);
	       p1 := dip_mred p1;
 	       p2 := dip_mred p2
	    >>
	 >>;
       	 % Append the term to the sum polynomial.
     	 if nt then
            if null w then
 	       w := rw := nt
            else <<
	       cdr cdr rw := nt;
 	       rw := nt
	    >>
      >>;
      return w
   end;

procedure dip_2a(u);
   % Returns prefix equivalent of distributive polynomial u.
   if null u then 0 else dip_replus dip_2a1 u;

procedure dip_2a1(u);
   begin scalar x,y;
      if null u then
      	 return nil;
      x := dip_lbc u;
      y := ev_2a dip_evlmon u;
      if bc_minus!? x then
 	 return {'minus,dip_retimes(bc_2a bc_neg x . y)} . dip_2a1 dip_mred u;
      return dip_retimes(bc_2a x . y) . dip_2a1 dip_mred u
   end;

procedure dip_replus(u);
   if atom u then u else if null cdr u then car u else 'plus . u;

procedure dip_retimes(u);
   % U is a list of prefix expressions the first of which is a number.
   % Result is prefix representation for their product.
   if car u = 1 then
      if cdr u then dip_retimes cdr u else 1
   else if null cdr u then
      car u
   else
      'times . u;

procedure dip_simpcont(p);
   % Calculate the contents of p and divide all coefficients by it.
   begin scalar c;
      c := dip_contenti p;
      if bc_minus!? dip_lbc p then
 	 c := bc_neg c;
      if bc_one!? c then
 	 return p;
      return dip_reduceconti(p,c)
   end;

procedure dip_contenti(p);
   dip_contenti1(p,bc_zero());

procedure dip_contenti1(p,c);
   <<
      while p do <<
	 c := bc_gcd(dip_lbc p,c);
	 p := dip_mred p
      >>;
      bc_abs c
   >>;

procedure dip_reduceconti(p,c);
   % Divide all coefficients of p by cont.
   if p then
      dip_moncomp(bc_quot(dip_lbc p,c),dip_evlmon p,
	 dip_reduceconti(dip_mred p,c));

procedure dip_condense(f);
   begin scalar dl,ev,w;
      dl := dip_evlist!*;
      while f do <<
	 ev := dip_evlmon f;
    	 while cdr dl and (w := ev_comp(ev,cadr dl)) #= -1 do
 	    dl := cdr dl;
    	 if cdr dl and w #= 0 then
	    car f := ev_identify(car f,cadr dl)
      	 else
 	    cdr dl := ev . cdr dl;
    	 f := dip_mred f
      >>;
   end;

procedure dip_evlcomp(p1,p2);
   % Distributive polynomial exponent vector leading monomial compare.
   % p1 and p2 are distributive polynomials. dip_evlcomp(p1,p2)
   % returns a boolean expression true if the distributive polynomial
   % p1 is smaller or equal the distributive polynomial p2 else false.
   not ev_compless!?(dip_evlmon p1,dip_evlmon p2);

procedure dip_length(p);
   % Distributive polynomial length. p is a distributive polynomial.
   % dip_length(p) returns the number of terms of the distributive
   % polynomial p, a digit.
   if null p then 0 else 1 + dip_length dip_mred p;

procedure dip_cancelmev(f,ev);
   % cancels all monomials in f which are multiples of ev.
   if null f then
      nil
   else if ev_mtest!?(dip_evlmon f,ev) then
      dip_cancelmev(dip_mred f,ev)
   else
      dip_evlmon f . dip_lbc f . dip_cancelmev(dip_mred f,ev);

procedure dip_bcquot(p,c);
   if bc_one!? c then
      p
   else
      dip_bcquot1(p,c);

procedure dip_bcquot1(p,c);
   if null p then
      nil
   else
      dip_evlmon p . bc_quot(dip_lbc p,c) . dip_bcquot1(dip_mred p,c);

procedure dip_appendmon(dip,bc,ev);
   append(dip,dip_fmon(bc,ev));

procedure dip_nconcmon(dip,bc,ev);
   nconc(dip,dip_fmon(bc,ev));

procedure dip_bcprod(p,c);
   if bc_zero!? c then
      nil
   else if bc_one!? c then
      p
   else
      dip_bcprod1(p,c);

procedure dip_bcprod1(p,c);
   if null p then
      nil
   else
      dip_evlmon p . bc_prod(dip_lbc p,c) . dip_bcprod1(dip_mred p,c);

procedure dip_tdeg(p);
   if null p then
      0
   else
      max(ev_tdeg dip_evlmon p,dip_tdeg dip_mred p);

procedure dip_append(p1,p2);
   append(p1,p2);

procedure dip_cp(p);
   for each x in p collect x;

procedure dip_dcont(dp);
   dip_dcont1(dp,bc_zero());

procedure dip_dcont1(dp,c);
   <<
      c := bc_2d c;
      while dp do <<
	 c := gcdn(c,bc_dcont dip_lbc dp);
	 dp := dip_mred dp
      >>;
     bc_fd c
   >>;

procedure dip_ilcomb(p1,c1,t1,p2,c2,t2);
   if null p1 then
      dip_prod(p2,dip_fmon(c2,t2))
   else if null p2 then
      dip_prod(p1,dip_fmon(c1,t1))
   else
      dip_ilcomb1(p1,c1,t1,p2,c2,t2);

procedure dip_ilcombr(p1,c1,p2,c2,t2);
   if null p1 then
      dip_prod(p2,dip_fmon(c2,t2))
   else if null p2 then
      dip_bcprod(p1,c1)
   else
      dip_ilcomb1r(p1,c1,p2,c2,t2);

procedure dip_ilcomb1(p1,c1,t1,p2,c2,t2);
   % Compute p1*c1^t1+p2*c2^t2.
   begin scalar hc1,ht1,hc2,ht2,cmp,resl,w;
      ht1 := ev_sum(car p1,t1);
      p1 := cdr p1;
      hc1 := bc_prod(car p1,c1);
      p1 := cdr p1;
      ht2 := ev_sum(car p2,t2);
      p2 := cdr p2;
      hc2 := bc_prod(car p2,c2);
      p2 := cdr p2;
      while p1 and p2 do <<
	 cmp := ev_comp(ht1,ht2);  % 1 = ">", -1 = "<", 0 = "="
	 if cmp #= 1 then <<
	    resl := hc1 . ht1 . resl;
	    ht1 := ev_sum(car p1,t1);
	    p1 := cdr p1;
	    hc1 := bc_prod(car p1,c1);
	    p1 := cdr p1
	 >> else if cmp #= -1 then <<
	    resl := hc2 . ht2 . resl;
	    ht2 := ev_sum(car p2,t2);
	    p2 := cdr p2;
	    hc2 := bc_prod(car p2,c2);
	    p2 := cdr p2
	 >> else <<  % cmp = 0, actually add monomials
	    w := bc_sum(hc1,hc2);
	    if not bc_zero!? w then
	       resl := w . ht1 . resl;
	    ht1 := ev_sum(car p1,t1);
	    p1 := cdr p1;
	    hc1 := bc_prod(car p1,c1);
	    p1 := cdr p1;
	    ht2 := ev_sum(car p2,t2);
	    p2 := cdr p2;
	    hc2 := bc_prod(car p2,c2);
	    p2 := cdr p2
	 >>
      >>;
      return if p1 then
	 dip_ilcomb2(resl,hc2,ht2,hc1,ht1,p1,c1,t1)
      else
	 dip_ilcomb2(resl,hc1,ht1,hc2,ht2,p2,c2,t2)
   end;

procedure dip_ilcomb2(resl,hc1,ht1,hc2,ht2,p2,c2,t2);
   begin scalar cmp,w;
      while p2 and (cmp := ev_comp(ht1,ht2)) #= -1 do <<
	 resl := hc2 . ht2 . resl;
	 ht2 := ev_sum(car p2,t2);
	 p2 := cdr p2;
	 hc2 := bc_prod(car p2,c2);
	 p2 := cdr p2
      >>;
      if p2 then <<
	 if cmp #= 1 then
	    resl := hc2 . ht2 . hc1 . ht1 . resl
	 else <<  % cmp = 0
	    w := bc_sum(hc1,hc2);
	    if not bc_zero!? w then
	       resl := w . ht1 . resl
	 >>;
	 while p2 do <<
	    resl := ev_sum(car p2,t2) . resl;
	    p2 := cdr p2;
	    resl := bc_prod(car p2,c2) . resl;
	    p2 := cdr p2
	 >>;
	 return reversip resl
      >>;
      cmp := ev_comp(ht1,ht2);
      if cmp #= -1 then
	 resl := hc1 . ht1 . hc2 . ht2 . resl
      else if cmp #= 1 then
	 resl := hc2 . ht2 . hc1 . ht1 . resl
      else <<  % cmp = 0
	 w := bc_sum(hc1,hc2);
	 if not bc_zero!? w then
	    resl := w . ht1 . resl
      >>;
      return reversip resl
   end;

procedure dip_ilcomb1r(p1,c1,p2,c2,t2);
   % Compute p1*c1+p2*c2^t2.
   begin scalar hc1,ht1,hc2,ht2,cmp,resl,w;
      ht1 := car p1;
      p1 := cdr p1;
      hc1 := bc_prod(car p1,c1);
      p1 := cdr p1;
      ht2 := ev_sum(car p2,t2);
      p2 := cdr p2;
      hc2 := bc_prod(car p2,c2);
      p2 := cdr p2;
      while p1 and p2 do <<
	 cmp := ev_comp(ht1,ht2);  % 1 = ">", -1 = "<", 0 = "="
	 if cmp #= 1 then <<
	    resl := hc1 . ht1 . resl;
	    ht1 := car p1;
	    p1 := cdr p1;
	    hc1 := bc_prod(car p1,c1);
	    p1 := cdr p1
	 >> else if cmp #= -1 then <<
	    resl := hc2 . ht2 . resl;
	    ht2 := ev_sum(car p2,t2);
	    p2 := cdr p2;
	    hc2 := bc_prod(car p2,c2);
	    p2 := cdr p2
	 >> else <<  % cmp = 0, actually add monomials
	    w := bc_sum(hc1,hc2);
	    if not bc_zero!? w then
	       resl := w . ht1 . resl;
	    ht1 := car p1;
	    p1 := cdr p1;
	    hc1 := bc_prod(car p1,c1);
	    p1 := cdr p1;
	    ht2 := ev_sum(car p2,t2);
	    p2 := cdr p2;
	    hc2 := bc_prod(car p2,c2);
	    p2 := cdr p2
	 >>
      >>;
      return if p1 then
	 dip_ilcomb2r(resl,hc2,ht2,hc1,ht1,p1,c1)
      else
	 dip_ilcomb2(resl,hc1,ht1,hc2,ht2,p2,c2,t2)
   end;


procedure dip_ilcomb2r(resl,hc1,ht1,hc2,ht2,p2,c2);
   begin scalar cmp,w;
      while p2 and (cmp := ev_comp(ht1,ht2)) #= -1 do <<
	 resl := hc2 . ht2 . resl;
	 ht2 := car p2;
	 p2 := cdr p2;
	 hc2 := bc_prod(car p2,c2);
	 p2 := cdr p2
      >>;
      if p2 then <<
	 if cmp #= 1 then
	    resl := hc2 . ht2 . hc1 . ht1 . resl
	 else <<  % cmp = 0
	    w := bc_sum(hc1,hc2);
	    if not bc_zero!? w then
	       resl := w . ht1 . resl
	 >>;
	 while p2 do <<
	    resl := car p2 . resl;
	    p2 := cdr p2;
	    resl := bc_prod(car p2,c2) . resl;
	    p2 := cdr p2
	 >>;
	 return reversip resl
      >>;
      cmp := ev_comp(ht1,ht2);
      if cmp #= -1 then
	 resl := hc1 . ht1 . hc2 . ht2 . resl
      else if cmp #= 1 then
	 resl := hc2 . ht2 . hc1 . ht1 . resl
      else <<  % cmp = 0
	 w := bc_sum(hc1,hc2);
	 if not bc_zero!? w then
	    resl := w . ht1 . resl
      >>;
      return reversip resl
   end;

procedure dip_comp(p1,p2);
   % distributive polynomial compare. [p1] and [p2] are DIP's. Returns
   % bool. Returns [T] if [p1] is greater than [p2] wrt. the
   % quasi-order induced by the current term order.
   begin scalar w;
      if null p1 then
      	 return nil;
      if null p2 then
	 return T;
      w := dip_comp1(p1,p2);
      if w #= -1 then
	 return nil;
      if w #= 1 then
	 return T;
      return dip_comp(dip_mred p1,dip_mred p2)
   end;
      
procedure dip_comp1(p1,p2);
   ev_comp(dip_evlmon p1,dip_evlmon p2);

endmodule;  % dip

module td;

procedure td_vars();
   if !*tdusetorder then
      cdr global!-dipvars!*
   else
      cdr td_vars!*;

procedure td_sortmode();
   if !*tdusetorder then
      vdpsortmode!*
   else
      td_sortmode!*;

procedure td_sortextension();
   if !*tdusetorder then
      vdpsortextension!*
   else
      td_sortextension!*;

procedure td_torder(u);
  begin scalar oldmode,oldex,oldvars,w;
     oldmode := td_sortmode!*;
     oldex := td_sortextension!*;
     oldvars := td_vars!*;
     td_vars!* := '(list);
     w := reval car u;
     if null cdr u and eqcar(w,'list) then
	u := cdr w
     else
	u := w . for each a in cdr u collect reval a;
     w := car u;
     u := cdr u;
     if eqcar(w,'list) then <<
	td_vars!* := w;
 	w := car u;
 	u := cdr u
     >>;
     td_sortmode!* := w;
     td_sortextension!* := for each x in u join
     	if eqcar(x,'list) then cdr x else {x};
     if flagp(td_sortmode!*,'dipsortextension) and null td_sortextension!*
     then
 	rederr "td_torder: term order needs additional parameter(s)";
     return 'list . oldvars . oldmode . oldex
  end;

endmodule;  % td

end;  % of file
