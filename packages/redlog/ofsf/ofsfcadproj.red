module ofsfcadproj;  % CAD projection

revision('ofsfcadproj, "$Id$");

copyright('ofsfcadproj, "(c) 2000-2009 A. Dolzmann, L. Gilch, A. Seidl, T. Sturm, 2016 T. Sturm");

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

fluid '(ofsf_cadbvl!* !*rlpos);

switch rlcadmc3;
on1 'rlcadmc3;

switch rlpscsgen;
on1 'rlpscsgen;

% The following are given:
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

%%% --- projection order optimization code --- %%%

switch dolzmann;

asserted procedure ofsf_cadporder!-betterp(rating: Integer, optrating: Integer, theo: List, theoopt: List): Boolean;
   if not !*dolzmann then
      not optrating or rating < optrating or
      (!*rlqegen and rating = optrating and length theo < length theoopt)
   else
      not optrating or rating > optrating or
      (!*rlqegen and rating = optrating and length theo < length theoopt);

asserted procedure ofsf_cadporder!-rate(pset: SFList): Integer;
   % length pset;
   for each f in pset sum sf_stdeg f;

asserted procedure ofsf_caddecdeg(phi: Formula): Formula;
   begin scalar w;
      if !*rlverbose then
	 ioto_prin2 "- decrease degrees: ";
      w := ofsf_decdeg0 phi;
      phi := car w;
      if !*rlverbose then
	 for each x in cdr w do
	    ioto_prin2 {"(", car x, "^", cdr x, ")"};
      return phi
   end;

asserted procedure ofsf_cadvbl(phi: Formula): List;
   % CAD variable block list. [phi] is a prenex formula. Returns a List of Lists
   % of variables. The last element of this list is the list of unquantified
   % variables, i.e., is [nil] when [phi] is a sentence. Each list represents a
   % block of variables, i.e., ordering can be arbitrarily changed only within
   % these blocks.
   begin scalar varl, qal, cq, cl, cll, v, q;
      varl . qal := ofsf_mkvarl phi;  % ((xr, ..., x_1) . ((x_r.Q_r), ..., (x_k+1.Q_k+1)))
      if qal then <<
      	 cq := cdar qal;  % current quantifier
      	 while qal do <<
	    v . q := pop qal;
	    pop varl;
	    if q neq cq then <<
	       push(cl, cll);
	       cq := q;
	       cl := nil
	    >>;
	    push(v, cl)
	 >>;
	 push(reversip cl, cll)
      >>;
      push(varl, cll);
      return reversip cll
   end;

asserted procedure ofsf_gcadporder(phi: Formula): KernelList;
   % Generic CAD projection order. The result is a List of all variables in a
   % PNF of [phi] encoding an order suitable for generic CAD projection. We
   % assume that [ofsf_gcad] uses [cl_pnf] for PNF computation.
   begin scalar !*rlqegen;
      !*rlqegen := t;
      return ofsf_cadporder phi
   end;

asserted procedure ofsf_cadporder(phi: Formula): KernelList;
   % CAD projection order. The result is a List of all variables in a PNF of
   % [phi] encoding an order suitable for CAD projection. We assume that
   % [ofsf_cad] uses [cl_pnf] for PNF computation.
   begin scalar cll, !*rlcadverbose;
      if !*rlverbose then
	 ioto_prin2t "+++ Optimizing projection order.";
      if !*rlcaddecdeg then
	 phi := ofsf_caddecdeg phi;
      phi := cl_pnf phi;
      cll := ofsf_cadvbl phi;
      if !*rlverbose then <<
      	 ioto_tprin2 {"+ input order by blocks:"};
	 for each cl in cll do
	    ioto_prin2 {" -> ", cl}
      >>;
      cll := ofsf_cadporder1(ofsf_transfac cl_terml phi, cll);
      if !*rlverbose then <<
      	 ioto_tprin2 {"+ optimized order:"};
	 for each cl in cll do
	    ioto_prin2 {" -> ", cl}
      >>;
      return for each cl in cll join cl
   end;

asserted procedure ofsf_cadporder1(fl: SFList, cll: List): List;
   % CAD projection order subroutine. [fl] is a List of irreducible SF; [cll] is
   % a List of Lists of variables. Returns a List of Lists of variables. The
   % variable order is optimized for projection within each List in [cll].
   begin scalar cl, lastp, ncl, ncll, theo;
      integer j;
      j := for each cl in cll sum
	 length cl;
      while cll do <<
	 cl := pop cll;
	 if cl then <<
	    lastp := null cll or null car cll;
	    {fl, ncl, theo} := ofsf_cadporder2(fl, cl, j, lastp, theo);
	    push(ncl, ncll);
	    j := j - length cl
	 >> else
	    push(nil, ncll)
      >>;
      return reversip ncll
   end;

asserted procedure ofsf_cadporder2(fl: SFList, cl: KernelList, j: Integer, lastp: Boolean, theo: List): List;
   % CAD projection order subroutine. [fl] is a List of irreducible SF; [cl] is
   % a block of variables; [j] is the level of the first variable in [cl]; If
   % [lastp] is [t], then [cl] is the last projection block. Returns a List
   % [{nfl, ncl, ntheo}], where [ncl] contains the variables from [cl] in an
   % order optimized for projection, and [nfl] is the projection set after
   % projecting in this order [ncl].
   begin scalar x, ncl;
      if !*rlverbose then
	 ioto_tprin2t {"+ current input block: ", cl};
      while cl and (not lastp or cdr cl) do <<
      	 {fl, x, theo} := ofsf_cadporder3(fl, cl, j, theo);
	 push(x, ncl);
	 cl := delete(x, cl);
	 j := j - 1
      >>;
      if lastp then
	 push(car cl, ncl);
      ncl := reversip ncl;
      if !*rlverbose then
	 ioto_tprin2t {"+ reordered block: ", ncl};
      return {fl, ncl, theo}
   end;

asserted procedure ofsf_cadporder3(fl: SFList, cl: KernelList, j: Integer, theo: List): List;
   % CAD projection order subroutine. [fl] is a List of irreducible SF; [cl] is
   % a block of variables; [j] is the level of the first variable in [cl].
   % Returns a List [{nfl, v, ntheo}], where [v] is the best variable in [cl]
   % for the next projection step and [nfl] is the result of this projection
   % step.
   begin scalar pp1, pp2, r, pset, xopt, psetopt, ropt, theoopt;
      for each x in cl do <<
	 if !*rlverbose then
	    ioto_prin2 {"[", x, ":"};
	 pp1 . pp2 := ofsf_cadporder!-project(fl, x, j, theo);
	 r := ofsf_cadporder!-rate pp1;
	 pset := union(pp1, pp2);
	 if !*rlverbose then <<
	    ioto_prin2 r;
	    if !*rlqegen then
	       ioto_prin2 {"/", length theo};
	    ioto_prin2 "] "
	 >>;
	 if ofsf_cadporder!-betterp(r, ropt, theo, theoopt) then <<
	    xopt := x;
	    psetopt := pset;
	    ropt := r;
	    if !*rlqegen then
	       theoopt := theo
	 >>
      >>;
      if !*rlverbose then
	 ioto_prin2t {"choose ", xopt};
      if !*rlqegen then
	 theo := theoopt;
      return {psetopt, xopt, theo}
   end;

asserted procedure ofsf_cadporder!-project(fl: SFList, x: Kernel, j: Integer, theo: List): DottedPair;
   begin scalar oldorder, ffj, ffi, pset, w;
      oldorder := setkorder {x};
      fl := for each f in fl collect
	 reorder f;
      for each f in fl do
	 if mvar f eq x then
	    push(f, ffj)
	 else
	    push(f, ffi);
      if !*rlqegen then <<
	 theo := for each at in theo collect
	    ofsf_0mk2(ofsf_op at, reorder ofsf_arg2l at);
	 w := ofsf_projopcohogen(ffj, x, j, theo);
	 pset := ofsf_transfac car w
      >> else
	 pset := ofsf_transfac ofsf_projopcoho(ffj, x, j);
      setkorder oldorder;
      return pset . ffi
   end;

%%% --- projection code --- %%%

% What the projection phase expects from caddata: aa, aaplus, varl, r, k.
% What is filled in: ff, hh.

asserted procedure ofsf_cadprojection1(cd: CadData): Any;
   % CAD projection phase.
   begin scalar varl, aa, ff, hh, hhtags, pp, theo, w, tag, tagl;
      integer k, r, l;
      varl := caddata_varl cd;  % {x1, ..., xr}
      k := caddata_k cd;  % the number of free variables
      r := length varl;  % the number of all variables
      aa := append(caddata_aa cd, caddata_aaplus cd);  % polynomials occuring in the input formula
      ff := mkvect r;  % here go the projection factors
      hh := mkvect r;  % here go the tagged projection factors
      hhtags := mkvect r;  % here go the tags of the projection polynomials
      if !*rlqegen then <<  % hack: generic CAD: new projection
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
	    tag := ofsf_mkhhtag(j, l);
	    push(tag . f, w);
	    push(tag, tagl)
	 >>;
         putv(hh, j, reversip w);  % the same order as in [ff]
	 putv(hhtags, j, reversip tagl)
      >>;
      caddata_puthh(cd, hh);
      caddata_puthhtags(cd, hhtags);
      if !*rlverbose then <<
	 ioto_tprin2t {"+ number of all projection factors: ", length pp};
	 if !*rlqegen then
	    ioto_prin2t {"+ number of theory elements: ", length theo}
      >>
   end;

asserted procedure ofsf_distribute(fl: SFList, ff: Atom, varl: KernelList): Any;
   % [ff] is changed in place.
   begin integer l;
      for each f in fl do <<
      	 l := sf_level(f, varl);
	 if l > 0 and not (f member getv(ff, l)) then
	    putv(ff, l, f . getv(ff, l))
      >>
   end;

asserted procedure ofsf_mkhhtag(j: Integer, l: Integer): Kernel;
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

asserted procedure sf_lc(f: SF, x: Kernel): SF;
   % Leading coefficient. [f] is a SF, [x] is a ID. Returns a SF. [f] has to be
   % ordered in a way compatible to a list containing [x].
   if not domainp f and mvar f eq x then lc f else f;

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
      ll := ofsf_projlcsll({aa}, x);
      dd := for each a in aa join
	 if sfto_vardeg(a, x) >= 2 then
	    {sf_discriminant(a, x)};
      rr := for each a1 on aa join
	 for each a2 in cdr aa collect
	    sfto_resf(car a1, a2, x);
      resl := list2set lto_remove('domainp, union(union(ll, dd), rr));
      if ofsf_cadverbosep() then
	 ioto_prin2 {"(projco2v ", length resl, ")"};
      return resl
   end;

asserted procedure ofsf_projmc(aa: SFList, x: Kernel): SFList;
   % McCallum's projection operator.
   begin scalar ll, dd, rr, resl;
      ll := ofsf_projmccoeffs(aa, x);
      dd := for each a in aa collect
	 sf_discriminant(a, x);
      rr := for each a1 on aa join
	 for each a2 in cdr aa collect
	    sfto_resf(car a1, a2, x);
      resl := list2set lto_remove('domainp, union(union(ll, dd), rr));
      if ofsf_cadverbosep() then
	 ioto_prin2 {"(projmc ", length resl, ")"};
      return resl
   end;

asserted procedure ofsf_projmcgen(aa: SFList, x: Kernel, theo: List): List;
   % McCallum's projection operator; generic version.
   begin scalar ll, dd, rr, resl;
      ll . theo := ofsf_projmccoeffsgen(aa, x, theo);
      dd := for each a in aa collect
	 sf_discriminant(a, x);
      rr := for each a1 on aa join
	 for each a2 in cdr aa collect
	    sfto_resf(car a1, a2, x);
      resl := list2set lto_remove('domainp, union(union(ll, dd), rr));
      if ofsf_cadverbosep() then
	 ioto_prin2 {"(projmcgen ", length resl, ")"};
      return resl . theo
   end;

asserted procedure ofsf_projcoho(aa: SFList, x: Kernel): SFList;
   % Collin's projection operator with Hong's improvement to S2.
   begin scalar bll, ll, ss1, ss2, resl;
      if ofsf_cadverbosep() then
	 ioto_prin2 "(projcoho ";
      bll := ofsf_projcored(aa, x);
      % TODO: Understand when is a call to list2set really needed. Originally it
      % was used only for [ss2] here and in ofsf_projcohogen, as well.
      ll := list2set ofsf_projlcsll(bll, x);
      ss1 := list2set ofsf_projcoss1(bll, x);
      ss2 := list2set ofsf_projhoss2(bll, x);
      resl := union(union(ll, ss1), ss2);
      if ofsf_cadverbosep() then
	 ioto_prin2 {" ", length resl, ")"};
      return resl
   end;

asserted procedure ofsf_projcohogen(aa: SFList, x: Kernel, theo: List): DottedPair;
   % Collin's projection operator with Hong's improvement to S2; generic
   % version.
   begin scalar bll, ll, ss1, ss2, resl;
      if ofsf_cadverbosep() then
	 ioto_prin2 "(projcohogen ";
      bll . theo := ofsf_projcoredgen(aa, x, theo);
      ll := list2set ofsf_projlcsll(bll, x);
      ss1 . theo := ofsf_projcoss1gen(bll, x, theo);
      ss1 := list2set ss1;
      ss2 . theo := ofsf_projhoss2gen(bll, x, theo);
      ss2 := list2set ss2;
      resl := union(union(ll, ss1), ss2);
      if ofsf_cadverbosep() then
	 ioto_prin2 {" ", length resl, ")"};
      return resl . theo
   end;

asserted procedure ofsf_projcored(aa: SFList, x: Kernel): List;
   % Collins' projection set of redukta for a list of polynomials. Returns a
   % list of lists of SF.
   begin scalar w, resll; integer c;
      for each f in aa do <<
   	 w := ofsf_projcored1(f, x);
	 w := ofsf_defpdel(w, nil);
	 if w then
	    push(w, resll)
      >>;
      resll := reversip resll;
      if ofsf_cadverbosep() then <<
	 c := for each l in resll sum
	    length l;
   	 ioto_prin2 {"(red ", c, ")"}
      >>;
      return resll
   end;

asserted procedure ofsf_projcored1(f: SF, x: Kernel): SFList;
   % Collins' projection set of redukta for a single polynomial. This procedure
   % computes the smallest possible set by using local equational theory as
   % follows: If a coefficient is found to be zero w.r.t. to [ltheo], the
   % reductum is not needed and we continue. If a coefficient is found to be
   % non-zero w.r.t. [ltheo], it is the last reductum we add to [resl].
   % Otherwise, we add the reductum to [resl] and [lcq = 0] to [ltheo].
   begin scalar lcf, finished, resl, ltheo;
      assert(sfto_mvartest(f, x));
      repeat <<
	 if sfto_mvartest(f, x) then <<
	    lcf := lc f;
	    if ofsf_surep(ofsf_0mk2('neq, lcf), ltheo) then <<
	       finished := t;
	       push(f, resl)
	    >> else if not ofsf_surep(ofsf_0mk2('equal, lcf), ltheo) then <<
	       push(f, resl);
	       push(ofsf_0mk2('equal, lcf), ltheo)
	    >>;
	    f := red f
      	 >> else <<
	    finished := t;
	    if not ofsf_surep(ofsf_0mk2('equal, f), ltheo) then
	       push(f, resl)
	 >>
      >> until finished;
      return reversip resl  % natural order of redukta
   end;

asserted procedure ofsf_projcoredgen(aa: SFList, x: Kernel, theo: List): DottedPair;
   % Collins' projection set of redukta for a list of polynomials; generic
   % version. Returns a DottedPair of the form List of List of SF . theory.
   begin scalar w, resll; integer c;
      for each f in aa do <<
	 w . theo := ofsf_projcoredgen1(f, x, theo);
	 w := ofsf_defpdel(w, theo);
	 if w then
	    push(w, resll)
      >>;
      resll := reversip resll;
      if ofsf_cadverbosep() then <<
	 c := for each l in resll sum
	    length l;
	 ioto_prin2 {"(redgen ", c, ")"}
      >>;
      return resll . theo
   end;

asserted procedure ofsf_projcoredgen1(f: SF, x: Kernel, theo: List): DottedPair;
   % Collins' projection set of redukta for a single polynomial; generic
   % version. Returns a dotted pair of the form SFList . theory.
   begin scalar ctheo, ltheo, lcf, finished, resl;
      assert(sfto_mvartest(f, x));
      repeat <<
	 ctheo := append(theo, ltheo);
	 if sfto_mvartest(f, x) then <<
	    lcf := lc f;
	    if ofsf_surep(ofsf_0mk2('neq, lcf), ctheo) then <<
	       finished := t;
	       push(f, resl)
	    >> else if not ofsf_surep(ofsf_0mk2('equal, lcf), ctheo) then <<
	       if ofsf_cadvalassp(ofsf_cadbvl!*, lcf) then <<
	       	  finished := t;
	       	  push(ofsf_0mk2('neq, lcf), theo)
	       >> else
		  push(ofsf_0mk2('equal, lcf), ltheo);
	       push(f, resl)
	    >>;
	    f := red f
	 >> else <<
	    finished := t;
	    if not ofsf_surep(ofsf_0mk2('equal, f), ctheo) then
	       push(f, resl)
	 >>
      >> until finished;
      return reversip resl . theo  % natural order of redukta
   end;

asserted procedure ofsf_projcoss1(bll: List, x: Kernel): SFList;
   % Collins' projection set S1(bll). [bll] is a List of List of SF.
   begin scalar w, resl;
      for each bl in bll do <<
	 w := for each f in bl join
	    sf_pscs(f, sf_diff(f, x), x);
	 w := ofsf_defpdel(w, nil);
	 resl := append(resl, w)
      >>;
      if ofsf_cadverbosep() then
	 ioto_prin2 {"(S1 ", length resl, ")"};
      return resl
   end;

asserted procedure ofsf_projcoss1gen(bll: List, x: Kernel, theo: List): DottedPair;
   % Collins' projection set S1(bll); generic version. [bll] is a List of List of SF.
   begin scalar w, pscs, resl;
      if ofsf_cadverbosep() then
	 ioto_prin2 "(S1gen ";
      for each bl in bll do <<
	 w := for each f in bl join <<
	    pscs . theo := sf_pscsgen(f, sf_diff(f, x), x, theo);
	    pscs
	 >>;
	 w := ofsf_defpdel(w, theo);
	 resl := append(resl, w)
      >>;
      if ofsf_cadverbosep() then
	 ioto_prin2 {length resl, ")"};
      return resl . theo
   end;

asserted procedure ofsf_projhoss2(bll: List, x: Kernel): SFList;
   % Hong's projection set S2(bll). [bll] is a List of List of SF.
   begin scalar bl, w, resl, redll;
      while bll do <<
	 bl := pop bll;
	 w := for each f in bl join
	    for each tmp in bll join
	       sf_pscs(f, car tmp, x);
	 w := ofsf_defpdel(w, nil);
	 resl := append(resl, w)
      >>;
      if ofsf_cadverbosep() then
	 ioto_prin2 {"(S2 ", length resl, ")"};
      return resl
   end;

asserted procedure ofsf_projhoss2gen(bll: List, x: Kernel, theo: List): DottedPair;
   % Hong's projection set S2(bll); generic version. [bll] is a List of List of
   % SF.
   begin scalar bl, w, pscs, resl;
      if ofsf_cadverbosep() then
	 ioto_prin2 "(S2gen ";
      while bll do <<
	 bl := pop bll;
	 w := for each f in bl join
	    for each tmp in bll join <<
	       pscs . theo := sf_pscsgen(f, car tmp, x, theo);
	       pscs
	    >>;
	 w := ofsf_defpdel(w, theo);
	 resl := append(resl, w)
      >>;
      if ofsf_cadverbosep() then
	 ioto_prin2 {length resl, ")"};
      return resl . theo
   end;

asserted procedure ofsf_projlcsll(bll: List, x: Kernel): SFList;
   % Leading coefficients of [bll]. [bll] is a list of lists of SF.
   begin scalar w, resl;
      for each bl in bll do <<
	 w := for each f in bl collect
	    sf_lc(f, x);
	 w := ofsf_defpdel(w, nil);
	 resl := append(resl, w)
      >>;
      if ofsf_cadverbosep() then
	 ioto_prin2 {"(lcs ", length resl, ")"};
      return resl
   end;

asserted procedure ofsf_projmccoeffs(aa: SFList, x: Kernel): SFList;
   % McCallum's projection set of coefficients for a list of polynomials.
   begin scalar resl;
      resl := for each f in aa join
	 ofsf_projmccoeffs1(f, x);
      resl := ofsf_defpdel(resl, nil);
      if ofsf_cadverbosep() then
	 ioto_prin2 {"(coeffs ", length resl, ")"};
      return resl
   end;

asserted procedure ofsf_projmccoeffs1(f: SF, x: Kernel): SFList;
   % McCallum's projection set of coefficients for a single polynomial.
   begin scalar lcf, finished, resl, ltheo;
      assert(sfto_mvartest(f, x));
      repeat <<
	 if sfto_mvartest(f, x) then <<
	    lcf := lc f;
	    if ofsf_surep(ofsf_0mk2('neq, lcf), ltheo) then
	       finished := t
	    else if not ofsf_surep(ofsf_0mk2('equal, lcf), ltheo) then <<
	       push(lcf, resl);
	       push(ofsf_0mk2('equal, lcf), ltheo)
	    >>;
	    f := red f;
	 >> else <<
	    finished := t;
	    if not ofsf_surep(ofsf_0mk2('equal, f), ltheo) then
	       push(f, resl)
	 >>
      >> until finished;
      return reversip resl  % natural order of coefficients
   end;

asserted procedure ofsf_projmccoeffsgen(aa: SFList, x: Kernel, theo: List): DottedPair;
   % McCallum's projection set of coefficients for a list of polynomials;
   % generic version.
   begin scalar resl, w;
      resl := for each f in aa join <<
	 w . theo := ofsf_projmccoeffsgen1(f, x, theo);
      	 w
      >>;
      resl := ofsf_defpdel(resl, theo);
      if ofsf_cadverbosep() then
	 ioto_prin2 {"(coeffsgen ", length resl, ")"};
      return resl . theo
   end;

asserted procedure ofsf_projmccoeffsgen1(f: SF, x: Kernel, theo: List): SFList;
   % McCallum's projection set of coefficients for a single polynomial; generic
   % version.
   begin scalar ctheo, ltheo, lcf, finished, resl;
      assert(sfto_mvartest(f, x));
      repeat <<
	 ctheo := append(theo, ltheo);
	 if sfto_mvartest(f, x) then <<
	    lcf := lc f;
	    if ofsf_surep(ofsf_0mk2('neq, lcf), ctheo) then
	       finished := t
	    else if not ofsf_surep(ofsf_0mk2('equal, lcf), ctheo) then
	       if ofsf_cadvalassp(ofsf_cadbvl!*, lcf) then <<
		  finished := t;
	       	  push(ofsf_0mk2('neq, lcf), theo)
	       >> else <<
		  push(lcf, resl);
	       	  push(ofsf_0mk2('equal, lcf), ltheo)
	       >>;
	    f := red f
	 >> else <<
	    finished := t;
	    if not ofsf_surep(ofsf_0mk2('equal, f), ltheo) then
	       push(f, resl)
	 >>
      >> until finished;
      return reversip resl . theo  % natural order of coefficients
   end;

asserted procedure ofsf_defpdel(l: SFList, theo: List): SFList;
   % Definite predicate deletion. Delete all elements from [l], which can be
   % proved to be non-zero w.r.t. [theo] by ofsf_surep.
   for each f in l join
      if not ofsf_surep(ofsf_0mk2('neq, f), theo) then
	 {f}
      else <<
	 if ofsf_cadverbosep() then
	    ioto_prin2 "*";
	 nil
      >>;

asserted procedure ofsf_cadvalassp(bvl: KernelList, f: SF): Boolean;
   % Ordered field standard form valid assumption. Returns [T] if an assumption
   % containing [sf] is valid. Depends on switch [!*rlqegenct].
   (!*rlqegenct or sfto_monfp f) and null intersection(bvl, kernels f);

endmodule;  % ofsfcadprojection

end;  % of file
