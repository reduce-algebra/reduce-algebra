% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 2000-2009 A. Dolzmann, L. Gilch, A. Seidl, and T. Sturm
% ----------------------------------------------------------------------
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions
% are met:
%
%    * Redistributions of source code must retain the relevant
%      copyright notice, this list of conditions and the following
%      disclaimer.
%    * Redistributions in binary form must reproduce the above
%      copyright notice, this list of conditions and the following
%      disclaimer in the documentation and/or other materials provided
%      with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
% "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
% LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
% A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
% OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
% SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
% LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
% DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
% THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
% (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
% OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
%

lisp <<
   fluid '(ofsf_cadproj_rcsid!* ofsf_cadproj_copyright!*);
   ofsf_cadproj_rcsid!* :=
      "$Id$";
   ofsf_cadproj_copyright!* :=
      "(c) 2000-2009 A. Dolzmann, L. Gilch, A. Seidl, T. Sturm"
>>;

fluid '(ofsf_cadbvl!* !*rlpos);

switch rlcadmc3;
on1 'rlcadmc3;

switch rlpscsgen;
on1 'rlpscsgen;

module ofsfcadproj;
% CAD projection. The following are given:
% a) [pp]: a SFList over kernels contained in [varl]
% b) [varl]: KernelList  (x_1, ..., x_r) [k] is an integer.
% The whole projection code assumes that
% a) the kernel order is (x_r, ..., x_1), i.e., [x_r] is the smallest variable
% b) all elements of [pp] are ordered w.r.t. this kernel oder
% The order of projection is from right to left, i.e., the first projection is
% computed w.r.t. [x_r].

% The level of a polynomial [p] in our context here is not an Integer but either
% a Kernel or [nil]. If [p] contains variables, then the level of [p] is [mvar
% p]. Otherwise it is [nil].

% TODO: What types for functions (code pointers, lambda, things which are used
% by the apply function) are there?
% TODO: Do we need a new data type "tagged standard form"?

struct MtxSF checked by MtxSFP;  % Matrix with Standard Form Entries
struct SFList checked by SFListP;  % List of SF
struct KernelList checked by KernelListP;  % List of Kernel

% TODO: Be more precise here. MtxSF is a List of SFList.
procedure MtxSFP(s);
   listp s;

procedure SFListP(s);
   listp s and (null s or sfpx car s and SFListP cdr s);

procedure KernelListP(s);
   listp s and (null s or assert_kernelp car s and KernelListP cdr s);

%%% --- projection order code --- %%%

asserted procedure ofsf_cadvbl1(phi: Formula): List;
   % Variable-block-list. [phi] is a prenex fof. Returns a list of lists
   % [[xr..][..xk]..[xk..x1]] of Kernels.
   begin scalar tmp, fvarl, ql, cq, cll, cl, a;
      tmp := ofsf_mkvarl phi;  % ((xr,...,x_1).((x_r.Q_r),...,(x_k+1.Q_k+1)))
      fvarl := car tmp;  % ((xr,...,x_1)
      ql := cdr tmp;
      if ql then <<
      	 cq := cdar ql;  % current quantifier
      	 while ql do <<
	    a := car ql;
	    ql := cdr ql;
	    fvarl := cdr fvarl;
	    if cdr a neq cq then <<
	       cll := cl . cll;
	       cq := cdr a;
	       cl := nil
	    >>;
	    cl := car a . cl;
	 >>;
	 cll := reversip cl . cll
      >>;
      cll := fvarl . cll;
      cll := reversip cll;
      return cll
end;

asserted procedure ofsf_gcadporder(phi: Formula): List;
   % Generic CAD projection order. Returns a list of identifiers. The result is
   % a list of all variables in a PNF of [phi] encoding an order suitable for
   % generic CAD projection. We assume that [ofsf_gcad] uses [cl_pnf] for PNF
   % computation.
   begin scalar !*rlqegen;
      !*rlqegen := t;
      return ofsf_cadporder phi
   end;

asserted procedure ofsf_cadporder(phi: Formula): List;
   ofsf_cadporder0(phi, 'ofsf_cadporder!-rate, 'ofsf_cadporder!-betterp);

switch dolzmann;

asserted procedure ofsf_cadporder!-betterp(rating, optrating, theo, theoopt): Boolean;
   if not !*dolzmann then
      not optrating or rating < optrating or
      (!*rlqegen and rating = optrating and length theo < length theoopt)
   else
      not optrating or rating > optrating or
      (!*rlqegen and rating = optrating and length theo < length theoopt);

asserted procedure ofsf_cadporder!-rate(pset: List): Integer;
   % length pset;
   for each f in pset sum sf_stdeg f;

asserted procedure ofsf_cadporder0(phi: Formula, rate, betterp): List;
   % CAD projection order. [phi] is an OFSF FORMULA. Returns a list of
   % identifiers. The result is a list of all variables in a PNF of [phi]
   % encoding an order suitable for CAD projection. We assume that [ofsf_cad]
   % uses [cl_pnf] for PNF computation.
   begin scalar cll, varl, !*rlcadverbose;
      if !*rlverbose then
	 ioto_prin2t "+++ Optimizing projection order.";
      if !*rlcaddecdeg then
	 phi := ofsf_caddecdeg phi;
      phi := cl_pnf phi;
      cll := ofsf_cadsplt phi;
      if !*rlverbose then <<
      	 ioto_tprin2 {"++ input order: ->"};
	 for each x in cll do
	    ioto_prin2 {" ", x, " ->"}
      >>;
      cll := ofsf_cadporder1(ofsf_transfac cl_terml phi, cll, rate, betterp);
      if !*rlverbose then <<
      	 ioto_tprin2 {"++ optimized order: ->"};
	 for each x in cll do
	    ioto_prin2 {" ", x, " ->"}
      >>;
      varl := for each cl in cll join cl;
      return varl
   end;

asserted procedure ofsf_caddecdeg(phi: Formula): Formula;
   begin scalar w;
      if !*rlverbose then ioto_prin2 "- decrease degrees: ";
      w := ofsf_decdeg0 phi;
      phi := car w;
      if !*rlverbose then
	 for each x in cdr w do
	    ioto_prin2 {"(", car x, "^", cdr x, ")"};
      return phi
   end;

asserted procedure ofsf_cadsplt(phi: Formula): List;
   begin scalar fvarl, ql, cq, cll, cl, a, tmp;
      tmp := ofsf_mkvarl phi;
      fvarl := car tmp;
      ql := cdr tmp;
      if ql then <<
      	 cq := cdar ql;
      	 while ql do <<
	    a := car ql;
	    ql := cdr ql;
	    fvarl := cdr fvarl;
	    if cdr a neq cq then <<
	       cll := cl . cll;
	       cq := cdr a;
	       cl := nil
	    >>;
	    cl := car a . cl;
	 >>;
	 cll := reversip cl . cll
      >>;
      cll := fvarl . cll;
      cll := reversip cll;
      return cll
   end;

asserted procedure ofsf_cadporder1(tl,cll,rate,betterp: Boolean): List;
   % CAD projection order subroutine. [tl] is a list of (irreducible) SF's;
   % [cll] is a LIST of lists of identifiers. Returns a LIST of lists of
   % identifers. The variable order is optimized for projection within each list
   % in [cll].
   begin scalar w, varl, ncll, cl, theo;
      varl := for each cl in cll join append(cl,nil);
      while cll do <<
	 cl := car cll;
	 cll := cdr cll;
	 if cl then <<
	    w := ofsf_cadporder2(tl,cl,varl,null cll or null car cll,theo,
	       rate,betterp);
	    tl := car w;
	    ncll := cadr w . ncll;
	    theo := caddr w
	 >> else
	    ncll := nil . ncll
      >>;
      return reversip ncll
   end;

procedure ofsf_cadporder2(tl,cl,varl,lastp,theo,rate,betterp);
   % CAD projection order subroutine. [tl] is a list of (irreducible) SF's; [cl]
   % is a LIST of identifiers; [varl] is a LIST of IDENTIFIERS; [lastp] is
   % BOOLEAN. Returns a pair $(T . V)$, where $T$ is a LIST of SF's and $V$ is a
   % LIST of IDENTIFIER's. [varl] is the list of all variables in the original
   % input formula in the given input order, i.e., [cl] is a subsegment of
   % [varl]. If [lastp] is non-[nil], then we are in the last projection block.
   % $V$ contains the variables from [cl] in an order optimized for projection,
   % and $T$ is the projection set after projecting in this order $V$.
   begin scalar w,ncl,lvarl;
      if !*rlverbose then
	 ioto_tprin2t {"+ Current input block: -> ",cl," ->"};
      lvarl := member(car cl,varl);
      while cl and (not lastp or cdr cl) do <<
      	 w := ofsf_cadporder3(tl,cl,lvarl,theo,rate,betterp);
	 tl := car w;
	 ncl := cadr w . ncl;
	 theo := caddr w;
	 cl := delete(cadr w,cl);
	 lvarl := delete(cadr w,lvarl)
      >>;
      if lastp then
	 ncl := car cl . ncl;
      ncl := reversip ncl;
      if !*rlverbose then
	 ioto_tprin2t {"+ Reordered block: ",ncl};
      return {tl,ncl,theo}
   end;

procedure ofsf_cadporder3(tl,cl,lvarl,theo,rate,betterp);
   % CAD projection order subroutine. [tl] is a list of (irreducible) SF's; [cl]
   % is a LIST of identifiers; [lvarl] is a LIST of identifiers. Returns a pair
   % $(T . v)$, where $T$ is a LIST of SF's and $v$ is an IDENTIFIER. [lvarl] is
   % the tail of the list of all variables in the original input formula in the
   % given input order starting with [cl]. $v$ is the best variables in [cl] for
   % the next projection step and $T$ is the result of this projection step.
   begin scalar pset,xopt,psetopt,optrating,theoopt,rating,j,psetpr;
      j := length lvarl;
      for each x in cl do <<
	 if !*rlverbose then
	    ioto_prin2 {"[",x,":"};
	 lvarl := x . delete(x,lvarl);
	 psetpr := ofsf_cadporder!-project(tl,x,lvarl,j,theo);
	 pset := car psetpr;
	 rating := apply(rate,{pset});
	 pset := union(car psetpr,cdr psetpr);
	 if !*rlverbose then <<
	    ioto_prin2 rating;
	    if !*rlqegen then
	       ioto_prin2 {"/",length theo};
	    ioto_prin2 "] "
	 >>;
	 if apply(betterp,{rating,optrating,theo,theoopt}) then <<
	    xopt := x;
	    psetopt := pset;
	    optrating := rating;
	    if !*rlqegen then theoopt := theo
	 >>;
      >>;
      if !*rlqegen then theo := theoopt;
      if !*rlverbose then ioto_prin2t {"choose ",xopt};
      return {psetopt,xopt,theo}
   end;

procedure ofsf_cadporder!-project(tl,x,lvarl,j,theo);
   begin scalar pset,oldorder;
      oldorder := setkorder {x};
      tl := for each f in tl collect
	 reorder f;
      if !*rlqegen then
	 theo := for each at in theo collect
	    ofsf_0mk2(ofsf_op at,reorder ofsf_arg2l at);
      pset := ofsf_cadporder!-project1(tl,x,lvarl,j,theo);
      setkorder oldorder;
      return pset
   end;

procedure ofsf_cadporder!-project1(tl,x,lvarl,j,theo);
   begin scalar ffj,ffi,pset,w;
      ffj := ffi := nil;
      for each f in tl do
	 if mvar f eq x then
	    ffj := f . ffj
	 else
	    ffi := f . ffi;
      pset :=  if !*rlqegen then <<
	 w := ofsf_projopcohogen(ffj, nth(reverse lvarl, j), j, theo);
	 theo := cdr w;
	 ofsf_transfac car w
      >> else
	 ofsf_transfac ofsf_projopcoho(ffj, nth(reverse lvarl, j), j);
      return (pset . ffi)
   end;

%%% --- projection code --- %%%

% What the projection phase expects from caddata: aa, aaplus, varl, r, k.
% What is filled in: ff, hh.

asserted procedure ofsf_cadprojection1(cd: CadData): Any;
   % CAD projection phase.
   begin scalar varl, aa, ff, hh, ffid, pp, theo, w, tag, tagl;
      integer k, r, l;
      varl := caddata_varl cd;  % {x1, ..., xr}
      k := caddata_k cd;  % the number of free variables
      r := length varl;  % the number of all variables
      aa := append(caddata_aa cd, caddata_aaplus cd);  % polynomials occuring in the input formula
      ff := mkvect r;  % here go the projection factors
      hh := mkvect r;  % here go the tagged projection factors
      ffid := mkvect r;  % here go the id's of the projection polynomials
      % hack: generic cad: new projection
      if !*rlqegen then <<
	 ofsf_cadbvl!* := lto_drop(varl, k);  % better: caddata_bvl
	 pp . theo := ofsf_projsetcohogen(aa, varl, nil);
	 caddata_puttheo(cd, theo)
      >> else
      	 pp := ofsf_projsetcoho(aa, varl);
      ofsf_distribute(pp, ff, varl);
      caddata_putff(cd, ff);
      for j := 1 : r do <<
	 l := 0;
	 tagl := nil;
	 w := nil;
	 for each f in getv(ff, j) do <<
	    l := l + 1;
	    tag := ofsf_ffji(j, l);
	    push(tag_(f, {tag}), w);
	    push(tag, tagl)
	 >>;
         putv(hh, j, list2vector reversip w);  % the same order as in [ff]
	 putv(ffid, j, tagl)
      >>;
      caddata_puthh(cd, hh);
      caddata_putffid(cd, ffid);
      if !*rlverbose then <<
	 ioto_tprin2t {"+ number of all projection factors: ", length pp};
	 if !*rlqegen then
	    ioto_prin2t {"+ number of theory elements: ", length theo}
      >>
   end;

asserted procedure ofsf_distribute(fl: SfList, ff: Atom, varl: KernelList): Any;
   % [ff] is changed in place.
   begin integer l;
      for each f in fl do <<
      	 l := sf_level(f, varl);
	 if l > 0 and not (f member getv(ff, l)) then  % memq?
	    putv(ff, l, f . getv(ff, l))
      >>
   end;

asserted procedure ofsf_ffji(j: Integer, l: Integer): Kernel;
   % Make an identifier of the form [ffj_l].
   intern compress lto_nconcn {explode 'ff, explode j, explode '!_, explode l};

% begin sfto procedures

asserted procedure sf_level(f: SF, varl: KernelList): Integer;
   % Level of a polynomial w.r.t. the variable list. Returns 0, if [f] is a
   % constant, otherwise the position of [mvar f] in [varl].
   if null varl then
      rederr "***** sf_level: invalid kernel"
   else if domainp f then
      0
   else if mvar f eq car varl then
      1
   else
      1 + sf_level(f, cdr varl);

asserted procedure sf_stdeg(f: SF): Integer;
   % Sum of total degrees of a polynomial.
   if null f or eqn(f, 0) then
      -1
   else
      sf_stdeg1 f;

asserted procedure sf_stdeg1(f: SF): Integer;
   if domainp f then
      0
   else
      sf_stdeg1 lc f + ldeg f + sf_stdeg1 red f;

asserted procedure sf_tdeg(f: SF, xl: KernelList): Integer;
   % Total degree.
   if null f or eqn(f, 0) then
      -1
   else if null xl then
      0
   else
      sf_tdeg1(f, xl);

asserted procedure sf_tdeg1(f: SF, xl: KernelList): Integer;
   % Total degree subroutine.
   if null f or eqn(f, 0) then
      0
   else if null xl then
      0
   else
      max(sf_tdeg1(sf_lc(f, car xl), cdr xl) + sfto_vardeg(f, car xl),
	 sf_tdeg1(sf_red(f, car xl), xl));

asserted procedure sf_lc(f: SF, x: Kernel): SF;
   % Leading coefficient. [f] is a SF, [x] is a ID. Returns a SF. [f] has to be
   % ordered in a way compatible to a list containing [x].
   if not domainp f and mvar f eq x then lc f else f;

asserted procedure sf_red(f: SF, x: Kernel): SF;
   % Univariate reductum of a standard form.
   if not domainp f and mvar f eq x then red f else nil;

asserted procedure sf_discriminant(f: SF, x: Kernel): SF;
   % Caveat: deg(f, x) > 0 is required.
   quotf(sfto_resf(f, numr difff(f, x), x), lc f);

asserted procedure sf_coeffs(f: SF, x: Kernel): SFList;
   % List of all coefficients, even those that are zero.
   if domainp f or mvar f neq x then {f} else coeffs f;

asserted procedure sf_psc(f: SF, g: SF, x: Kernel, j: Integer): SF;
   % The [j]-th principal subresultant coefficient of [f] and [g].
   mtx_det mtx_mmji(f, g, x, j, j);

asserted procedure sf_factorize(f: SF): DottedPair;
   % Factorize. Returns a pair [Integer . List of Pairs (SF . Integer)]: content
   % and factors with multiplicities.
   fctrf f;

asserted procedure sf_factors(f: SF): SFList;
   for each a in cdr sf_factorize f collect car a;

asserted procedure sf_cdl(f: SF, x: Kernel): List;
   % Coefficient and degree list. Retuns a List of pairs [SF . Integer].
   if sfto_mvartest(f, x) then
      (lc f . ldeg f) . sf_cdl(red f, x)
   else
      {(f . 0)};

asserted procedure sf_pscs(f: SF, g: SF, x: Kernel): SFList;
   % All principal subresultant coefficients of [f] and [g].
   for k := 0 : min(sfto_vardeg(f, x), sfto_vardeg(g, x))-1 collect
      sf_psc(f, g, x, k);

asserted procedure sf_pscsgen(a: SF, b: SF, x: Kernel, theo: List): DottedPair;
   % All principal subresultant coefficients of [f] and [g], generic version.
   % Returns a dotted Pair (SFList . theory).
   begin scalar k, pscl, finished;
      if not !*rlpscsgen then
	 return sf_pscs(a, b, x) . theo;
      k := 0;
      if k > min(sfto_vardeg(a, x), sfto_vardeg(b, x))-1 then
	 return nil . theo;
      repeat <<
	 pscl := sf_psc(a,b,x,k) . pscl;
	 k := k+1;
	 if k > min(sfto_vardeg(a, x), sfto_vardeg(b, x))-1 then <<
	    if ofsf_cadverbosep() then
	       ioto_prin2 "(end)"
	 >> else if ofsf_surep(ofsf_0mk2('neq, car pscl), theo) then <<
	    if ofsf_cadverbosep() then
	       if domainp car pscl then
	       	  ioto_prin2 "(dom)"
	       else
		  ioto_prin2 "(=>)";
	    finished := t
	 >> else if ofsf_cadvalassp(ofsf_cadbvl!*,car pscl) then <<
	    if ofsf_cadverbosep() then
	       ioto_prin2 "(>th)";
	    theo := ofsf_0mk2('neq,car pscl) . theo;
	    finished := t
	 >>;
      >> until finished or k > min(sfto_vardeg(a, x), sfto_vardeg(b, x))-1;
      % if ofsf_cadverbosep() then
      % 	 ioto_prin2 {" (- ", min(sfto_vardeg(a, x), sfto_vardeg(b, x))-k, ") "};
      return pscl . theo;
   end;

asserted procedure sf_diff(f: SF, x: Kernel): SF;
   numr difff(f, x);

% end sfto procedures

% begin lto procedures

asserted procedure lto_select(fn: Any, l: List): List;
   % Select elements from a list. [fn] is a function of type ALPHA->BOOL, [l] is
   % a list of ALPHA. Returns a list of ALPHA.
   lto_select1(fn, l, nil);

asserted procedure lto_select1(fn: Any, l: List, xarl: List): List;
   % Select elements from a list. [fn] is a function with length([xarl])+1
   % arguments, [l] and [xarl] are LIST.
   for each a in l join
      if apply(fn, a . xarl) then
	 {a};

asserted procedure lto_remove(fn: Any, l: List): List;
   % Remove elements from a list. [fn] is a function of type ALPHA->BOOL, [l] is
   % a list of ALPHA. Returns a list of ALPHA.
   lto_remove1(fn, l, nil);

asserted procedure lto_remove1(fn: Any, l: List, xarl: List): List;
   % Remove elements from a list. [fn] is a function with length([xarl])+1
   % arguments , [l] and [xarl] are LIST.
   for each a in l join
      if not apply(fn, a . xarl) then
	 {a};

asserted procedure lto_rmpos(lst: List, posl: List): List;
   % Remove positions. [lst] is a List. [posl] is a List of Integers.
   begin scalar pos;
      pos := 0;
      return for each a in lst join <<
	 pos := pos + 1;
	 if not memq(pos, posl) then {a}
      >>
   end;

asserted procedure lto_drop(l: List, n: Integer): List;
   % Drop the first n elements of l.
   if l and n > 0 then lto_drop(cdr l, n-1) else l;

asserted procedure lto_init(l: List): List;
   % Initial part of a non-empty list, with the last element removed.
   <<
      assert(not null l);
      if cdr l then car l . lto_init cdr l
   >>;

% end lto procedures

%%% --- Datatype MTX (matrices) --- %%%
% a matrix is represented as a list of lines.

asserted procedure mtx_0(m: Integer, n: Integer): MtxSF;
   % Zero matrix. Returns an m times n zero matrix.
   for l := 1 : m collect
      for c := 1 : n collect nil;

asserted procedure mtx_put(mtx: MtxSF, l: Integer, c: Integer, a: SF): Any;
   % Put entry.
   nth(nth(mtx, l), c) := a;

asserted procedure mtx_rmlscs(mtx: MtxSF, lines: List, columns: List): MtxSF;
   % Matrix remove lines and columns. [lines] and [columns] are Lists of
   % Integers.
   for each l in lto_rmpos(mtx, lines) collect
      lto_rmpos(l, columns);

asserted procedure mtx_sylvester(f: SF, g: SF, x: Kernel): MtxSF;
   % Sylvester matrix. [f] and [g] are non-zero polynomials in [x]. Returns a a
   % square matrix of dimension [m+n], where if [m] is the degree of [f] in [x],
   % and [n] is the degree of [g] in [x].
   begin scalar res, cfl, cgl;
      integer m, n, mpn;
      m := sfto_vardeg(f, x);
      n := sfto_vardeg(g, x);
      mpn := m + n;
      if eqn(mpn, 0) then
	 return mtx_0(0, 0);
      res := mtx_0(mpn, mpn);
      cfl := sf_coeffs(f, x);
      cgl := sf_coeffs(g, x);
      for j := 1 : n do
	 for k := j : j + m do
  	    mtx_put(res, j, k, nth(cfl, 1+(k-j)));
      for j := n+1 : mpn do
	 for k := j-n : j do
  	    mtx_put(res, j, k, nth(cgl, 1+(k-(j-n))));
      return res
   end;

asserted procedure mtx_det(mtx: MtxSF): SF;
   ofsf_det mtx;

asserted procedure mtx_mmji(f: SF, g: SF, x: Kernel, j: Integer, i: Integer): MtxSF;
   % Modified Sylvester matrix Mji.
   begin scalar ltd1, ltd2, ctd1, ctd2;
      integer m, n, mpn;
      % ltd: lines to delete; ctd: columns to delete
      m := sfto_vardeg(f, x);
      n := sfto_vardeg(g, x);
      mpn := m + n;
      ltd1 := for k := mpn-j+1 : mpn collect k;
      ltd2 := for k := n-j+1 : n collect k;
      ctd1 := for k := (mpn-i-j)+1 : mpn collect k;
      ctd2 := for k := mpn-(2*j+1)+1 : (mpn-i-j)-1 collect k;
      return mtx_rmlscs(mtx_sylvester(f, g, x), union(ltd1, ltd2), union(ctd1, ctd2))
   end;

%%% --- module tag --- %%%

% This module implements the datatype Tag(Alpha). An element of this datatype is
% a pair of an object (of type Alpha) and a set of tags.

asserted procedure tag_(a: Any, l: List): DottedPair;
   % Tag item for the first time.
   a . list2set l;

asserted procedure tag_object(te: DottedPair): Any;
   % Object of a tagged item.
   car te;

asserted procedure tag_taglist(te: DottedPair): List;
   % Tag list of a tagged item.
   cdr te;

asserted procedure tag_add(te: DottedPair, a: Any): DottedPair;
   % Add a tag to a tagged object.
   if member(a, tag_taglist te) then
      te
   else
      tag_object te . (a . tag_taglist te);

asserted procedure tglist2set(lte: List): List;
   % List to set for tagged elements. [lte] is List of tagged elements. Returns
   % a list of tagged elements such that no element occurs twice.
   tgunion(lte, {});

asserted procedure tgunion(st1: List, st2: List): List;
   % Union of tagged elements. [st1] and [st2] are sets of tagged elements.
   % Returns a set of tagged elements.
   <<
      if st1 then
	 for each t1 in st1 do
	    st2 := tgunion1(t1, st2);
      st2
   >>;

asserted procedure tgunion1(te: DottedPair, ste: List): List;
   % Union of tagged elements subroutine. [te] is a tagged element, [ste] is a
   % set of tagged elements.
   if null ste then
      {te}
   else if tag_object te = tag_object car ste then
      tag_(tag_object te, union(tag_taglist te, tag_taglist car ste)) . cdr ste
   else
      car ste . tgunion1(te, cdr ste);

asserted procedure notdomainp(f: Any): Boolean;
   not domainp f;

%%% --- Projection subsets --- %%%
% PAIR(LIST(SF),ID)->LIST(SF)

asserted procedure ofsf_projsetcoho(aa: SFList, varl: KernelList): SFList;
   ofsf_projset('ofsf_transfac, 'ofsf_projopcoho, aa, varl);

asserted procedure ofsf_projsetcohogen(aa: SFList, varl: KernelList, theo: List): DottedPair;
   ofsf_projsetgen('ofsf_transfac, 'ofsf_projopcohogen, aa, varl, theo);

procedure ofsf_projset(transfn, projopfn, aa, varl);
   % Projection set. [transfn] is a transformation on the projection set.
   % [projopfn] is a combined projection operator, [aa] is the list of input
   % polynomials and [varl] the list of variables. Returns a List of SF.
   ofsf_projset1(transfn, projopfn, aa, varl, 'ofsf_polyoflevel, 'union);

procedure ofsf_projset1(transfn, projopfn, aa, varl, polyoflevelfn, unionfn);
   begin scalar r, pp, cvar, w, ppj;
      r := length varl;
      pp := apply(transfn, {aa});
      for j := r step -1 until 2 do <<
	 cvar := nth(varl, j);
	 if ofsf_cadverbosep() then <<
	    ioto_tprin2 {"+ projection F", j, " -> F", j-1};
	    ioto_tprin2t {"+ variable: ", cvar}
	 >>;
	 ppj := apply(polyoflevelfn, {pp, cvar});
	 w := apply(transfn, {apply(projopfn, {ppj, cvar, j})});
	 pp := apply(unionfn, {pp, w})
      >>;
      return pp
   end;

procedure ofsf_projsetgen(transfn, projopfn, aa, varl, theo);
   begin scalar r, pp, cvar, ppj, pp_theo;
      r := length varl;
      pp := apply(transfn, {aa});
      for j := r step -1 until 2 do <<
	 cvar := nth(varl, j);
	 if ofsf_cadverbosep() then <<
	    ioto_tprin2 {"+ genprojection F", j, " -> F", j-1};
	    ioto_prin2t {", variable: ", nth(varl, j)}
	 >>;
	 ppj := ofsf_polyoflevel(pp, cvar);
	 pp_theo := apply(projopfn, {ppj, cvar, j, theo});
	 pp := union(apply(transfn, {car pp_theo}), pp);
	 theo := union(cdr pp_theo, theo)
      >>;
      return pp . theo
   end;

asserted procedure ofsf_polyoflevel(aa: SFList, x: Kernel): SFList;
   for each f in aa join
      if sfto_mvartest(f, x) then
	 {f};

asserted procedure ofsf_transfac(pp: SFList): SFList;
   % Factorization transformation.
   list2set for each p in pp join sf_factors p;

%%% --- Combined projection operators --- %%%

asserted procedure ofsf_projopcoho(aa: SFList, var: Kernel, j: Integer): SFList;
   % Combined Collins' projection operator with Hong's improvement.
   if eqn(j, 2) then
      ofsf_projco2v(aa, var)
   else if eqn(j, 3) and !*rlcadmc3 then
      ofsf_projmc(aa, var)
   else
      ofsf_projcoho(aa, var);

asserted procedure ofsf_projopcohogen(aa: SFList, var: Kernel, j: Integer, theo: List): DottedPair;
   % Combined Collins' projection operator with Hong's improvement; generic
   % version.
   if eqn(j, 2) then
      ofsf_projco2v(aa, var) . theo
   else if eqn(j, 3) and !*rlcadmc3 then
      ofsf_projmcgen(aa, var, theo)
   else
      ofsf_projcohogen(aa, var, theo);

asserted procedure ofsf_projco2v(aa: SFList, x: Kernel): SFList;
   % Collins' projection operator for two variable case.
   begin scalar ll, dd, rr, resl;
      if ofsf_cadverbosep() then
	 ioto_prin2 "(projco2v ";
      ll := ofsf_projlcs(aa, x);
      dd := for each a in aa join
	 if sfto_vardeg(a, x) >= 2 then
	    {sf_discriminant(a, x)};
      rr := for each a1 on aa join
	 for each a2 in cdr aa collect
	    sfto_resf(car a1, a2, x);
      resl := list2set lto_remove('domainp, union(union(ll, dd), rr));
      if ofsf_cadverbosep() then
	 ioto_prin2 {" ", length resl, ")"};
      return resl
   end;

asserted procedure ofsf_projmc(aa: SFList, x: Kernel): SFList;
   % McCallum's projection operator.
   begin scalar ll, dd, rr, resl;
      if ofsf_cadverbosep() then
	 ioto_prin2 "(projmc ";
      ll := ofsf_projmccoeffs(aa, x);
      dd := for each a in aa collect
	 sf_discriminant(a, x);
      rr := for each a1 on aa join
	 for each a2 in cdr aa collect
	    sfto_resf(car a1, a2, x);
      resl := list2set lto_remove('domainp, union(union(ll, dd), rr));
      if ofsf_cadverbosep() then
	 ioto_prin2 {" ", length resl, ")"};
      return resl
   end;

asserted procedure ofsf_projmcgen(aa: SFList, x: Kernel, theo: List): List;
   % McCallum's projection operator; generic version.
   begin scalar bb_theo, ll, dd, rr;
      % ll := ofsf_projmccoeffs(aa, x);
      bb_theo := ofsf_projcoredgen(aa, x, theo);
      ll := ofsf_projlcs(car bb_theo, x);
      dd := for each a in aa collect
	 sf_discriminant(a, x);
      rr := for each a1 on aa join for each a2 in cdr aa collect
	 sfto_resf(car a1, a2, x);
      return list2set lto_remove('domainp, union(union(ll,dd),rr)) . cdr bb_theo
   end;

asserted procedure ofsf_projcoho(aa: SFList, x: Kernel): SFList;
   % Collin's projection operator with Hong's improvement to S2.
   begin scalar bb, ll, ss1, ss2, resl;
      if ofsf_cadverbosep() then
	 ioto_prin2 "(projcoho ";
      bb := ofsf_projcored(aa, x);
      bb := ofsf_defpdel bb;
      % ll := ofsf_projmccoeffs(aa, x);
      ll := ofsf_projlcs(bb, x);
      ll := ofsf_defpdel ll;
      ss1 := ofsf_projcoss1(bb, x);
      ss1 := ofsf_defpdel ss1;
      ss2 := list2set ofsf_projhoss2(bb, x);
      ss2 := ofsf_defpdel ss2;
      resl := lto_select('notdomainp, union(union(ll, ss1), ss2));
      if ofsf_cadverbosep() then
	 ioto_prin2 {" ", length resl, ")"};
      return resl
   end;

asserted procedure ofsf_projcohogen(aa: SFList, x: Kernel, theo: List): DottedPair;
   % Collin's projection operator with Hong's improvement to S2; generic
   % version.
   begin scalar bb_theo, bb, ll, ss1_theo, ss1, ss2_theo, ss2;
      % redukta
      bb_theo := ofsf_projcoredgen(aa, x, theo);
      bb := car bb_theo;
      theo := cdr bb_theo;
      % leading coefficients
      ll := ofsf_projlcs(bb, x);
      % S1
      ss1_theo := ofsf_projcoss1gen(bb, x, theo);
      ss1 := car ss1_theo;
      theo := cdr ss1_theo;
      % S2
      ss2_theo := ofsf_projhoss2gen(bb, x, theo);
      ss2 := list2set car ss2_theo;
      theo := cdr ss2_theo;
      return lto_select('notdomainp, union(union(ll, ss1), ss2)) . theo
   end;

asserted procedure ofsf_projcored(aa: SFList, x: Kernel): SFList;
   % Collins' projection set of redukta for a list of polynomials.
   begin scalar resl;
      resl := for each f in aa join
   	 ofsf_projcored1(f, x);
      if ofsf_cadverbosep() then
   	 ioto_prin2 {"(red ", length resl, ")"};
      return resl
   end;

asserted procedure ofsf_projcored1(f: SF, x: Kernel): SFList;
   % Collins' projection set of redukta for a single polynomial. This procedure
   % computes the smallest possible set by using local equational theory as
   % follows: If a coefficient is found to be zero w.r.t. to [eqtheo], the
   % reductum is not needed and we continue. If a coefficient is found to be
   % non-zero w.r.t. [eqtheo], it is the last reductum we add to [resl].
   % Otherwise, we add the reductum to [resl] and [lcq = 0] to [eqtheo].
   begin scalar lcf, finished, resl, eqtheo;
      assert(sfto_mvartest(f, x));
      repeat <<
	 if sfto_mvartest(f, x) then <<
	    lcf := lc f;
	    if ofsf_surep(ofsf_0mk2('neq, lcf), eqtheo) then <<
	       push(f, resl);
	       finished := t
	    >> else if not ofsf_surep(ofsf_0mk2('equal, lcf), eqtheo) then <<
	       push(f, resl);
	       push(ofsf_0mk2('equal, lcf), eqtheo)
	    >>;
	    f := red f
      	 >> else <<
	    finished := t;
	    if not ofsf_surep(ofsf_0mk2('equal, f), eqtheo) then
	       push(f, resl)
	 >>
      >> until finished;
      return reversip resl  % natural order of redukta
   end;

asserted procedure ofsf_projcoredgen(aa: SFList, x: Kernel, theo: List): DottedPair;
   % Collins' projection set of redukta for a list of polynomials; generic
   % version. Returns a DottedPair of the form SFList . theory.
   begin scalar bb, bb_theo;
      if ofsf_cadverbosep() then
	 ioto_prin2 "(redgen: ";
      bb := for each f in aa join <<
	 bb_theo := ofsf_projcoredgen1(f, x, theo);
	 theo := cdr bb_theo;
	 car bb_theo
      >>;
      if ofsf_cadverbosep() then
	 ioto_prin2 {length bb, ")"};
      return bb . theo;
   end;

asserted procedure ofsf_projcoredgen1(f: SF, x: Kernel, theo: List): DottedPair;
   % Collins' projection set of redukta for a single polynomial; generic
   % version. Returns a dotted pair of the form SFList . theory.
   begin scalar redl, finished;
      if domainp f then
	 return nil;
      repeat <<
	 redl := f . redl;
	 f := sf_red(f, x);
	 if domainp f then << % f can be nil here
	    if ofsf_cadverbosep() then
	       ioto_prin2 "(end)";
	    finished := t
	 >> else if ofsf_surep(ofsf_0mk2('neq, sf_lc(car redl, x)), theo) then <<
	    if ofsf_cadverbosep() then
	       if domainp sf_lc(car redl, x) then
   	       	  ioto_prin2 "(dom)"
	       else
		  ioto_prin2 "(=>)";
	    finished := t
	 >> else if ofsf_cadvalassp(ofsf_cadbvl!*, sf_lc(car redl, x)) then <<
	    if ofsf_cadverbosep() then
	       ioto_prin2 "(>th)";
	    theo := ofsf_0mk2('neq, sf_lc(car redl, x)) . theo;
	    finished := t
	 >>;
      >> until finished;
      return reversip redl . theo
   end;

asserted procedure ofsf_projlcs(bb: SFList, x: Kernel): SFList;
   % Set of leading coefficients of [bb].
   begin scalar resl;
      resl := for each f in bb collect
	 sf_lc(f, x);
      if ofsf_cadverbosep() then
	 ioto_prin2 {"(lcs ", length resl, ")"};
      return resl
   end;

asserted procedure ofsf_projmccoeffs(aa: SFList, x: Kernel): SFList;
   % McCallum's projection set of coefficients for a list of polynomials.
   begin scalar resl;
      resl := for each f in aa join
	 ofsf_projmccoeffs1(f, x);
      if ofsf_cadverbosep() then
	 ioto_prin2 {"(coeffs ", length resl, ")"};
      return resl
   end;

asserted procedure ofsf_projmccoeffs1(f: SF, x: Kernel): SFList;
   % McCallum's projection set of coefficients for a single polynomial.
   begin scalar lcf, finished, resl;
      assert(sfto_mvartest(f, x));
      repeat <<
	 if sfto_mvartest(f, x) then <<
	    lcf := lc f;
	    f := red f
	 >> else <<
	    lcf := f;
	    finished := t
	 >>;
	 % if ofsf_surep(ofsf_0mk2('neq, lcf), nil) then
	 if domainp lcf then
	    finished := t
	 else
	    push(lcf, resl)
      >> until finished;
      return resl
   end;

asserted procedure ofsf_defpdel(l: SFList): SFList;
   % Definite predicate deletion. Delete all elements from [l] for which
   % ofsf_surep can verify definiteness.
   for each f in l join
      if not ofsf_surep(ofsf_0mk2('neq, f), nil) then
	 {f}
      else if !*rlverbose then <<
	 ioto_prin2 "*";
	 nil
      >>;

asserted procedure ofsf_cadvalassp(bvl: KernelList, f: SF): Boolean;
   % Ordered field standard form valid assumption. Returns [T] if an assumption
   % containing [sf] is valid. Depends on switch [!*rlqegenct].
   (!*rlqegenct or sfto_monfp f) and null intersection(bvl, kernels f);

asserted procedure ofsf_projcoss1(bb: SFList, x: Kernel): SFList;
   % Collins' projection set S1(bb).
   begin scalar ss1;
      ss1 := for each b in bb join
	 sf_pscs(b, sf_diff(b, x), x);
      if ofsf_cadverbosep() then
	 ioto_prin2 {"(S1 ", length ss1, ")"};
      return ss1
   end;

asserted procedure ofsf_projcoss1gen(bb: SFList, x: Kernel, theo: List): DottedPair;
   % Collins' projection set S1(bb) generic version.
   begin scalar ss, pscs_theo;
      if ofsf_cadverbosep() then
	 ioto_prin2 "(S1gen: ";
      ss := for each b in bb join <<
	 pscs_theo := sf_pscsgen(b, sf_diff(b, x), x, theo);
	 theo := cdr pscs_theo;
	 car pscs_theo
      >>;
      if ofsf_cadverbosep() then
	 ioto_prin2 {length ss, ")"};
      return ss . theo
   end;

asserted procedure ofsf_splitredl(bb: SFList, x: Kernel): List;
   % Split redukta list into list of lists of redukta.
   begin scalar redl,redll;
      % break up [bb] into sets containing an input poly and its reducta
      while bb do <<
      	 redl := {car bb};
	 bb := cdr bb;
      	 while bb and sf_red(car redl, x) = car bb do <<  % eq is possible here
	    redl := car bb . redl;
	    bb := cdr bb
      	 >>;
      	 redll := reversip redl . redll
      >>;
      % function(lambda(x, y); length x > length y)
      redll := sort(redll, function ofsf_splitredlordp);
      return redll
   end;

asserted procedure ofsf_splitredlordp(l1: SFList, l2: SFList): Boolean;
   % We assume that [l1] and [l2] are non-empty and their cars contain the
   % current variable as mvar.
   begin scalar le1, le2, x, hit, res, d1, d2;
      le1 := length l1;
      le2 := length l2;
      if le1 > le2 then
	 return t;
      if le1 < le2 then
	 return nil;
      x := mvar car l1;
      while l1 and not hit do <<
	 d1 := sfto_vardeg(car l1, x);
	 d2 := sfto_vardeg(car l2, x);
	 l1 := cdr l1;
	 l2 := cdr l2;
      	 if d1 > d2 then
	    res := hit := t;
	 if d1 < d2 then <<
	    res := nil;
	    hit := t
	 >>
      >>;
      return res
   end;

asserted procedure ofsf_projhoss2(bb: SFList, x: Kernel): SFList;
   % Hong's projection set S2 version 3. Note that for this to work properly,
   % the list bb of reducta has to look like
   % {f,red(f),red(red(f)),...,g,red(g),red(red(g)),...}
   begin scalar ss2, redll;
      if ofsf_cadverbosep() then
	 ioto_prin2 "(S2 ";
      % 1. break up [bb] into sets containing an input poly and its reducta
      redll := ofsf_splitredl(bb, x);
      % 2.
      % if ofsf_cadverbosep() then
      % 	 ioto_prin2 {"[", length redll, "]"};
      ss2 := for each ll on redll join for each l in cdr ll join
	 % car ll and l are lists of SF
	 for each b2 in l join
	    sf_pscs(caar ll, b2, x);
      if ofsf_cadverbosep() then
	 ioto_prin2 {length ss2, ")"};
      return ss2
   end;

asserted procedure ofsf_projhoss2gen(bb: SFList, x: Kernel, theo: List): DottedPair;
   % Hong's projection set S1 version 3 generic. Note that for this to work
   % properly, the list bb of reducta has to look like
   % {f,red(f),red(red(f)),...,g,red(g),red(red(g)),...}
   begin scalar ss2, redll, pscs_theo;
      % 1. break bb up into sets containing an imput poly and its reducta
      redll := ofsf_splitredl(bb, x);
      % 2.
      if ofsf_cadverbosep() then
	 ioto_prin2 "(hoS2gen ";
      ss2 := for each ll on redll join
	 for each l in cdr ll join
	    % car ll and l are lists of SF
	    for each b2 in l join <<
	       pscs_theo := sf_pscsgen(caar ll,b2,x,theo);
	       theo := cdr pscs_theo ;
	       car pscs_theo
	    >>;
      if ofsf_cadverbosep() then
	 ioto_prin2 {length ss2, ")"};
      return ss2 . theo
   end;

endmodule;  % ofsfcadprojection

end;  % of file
