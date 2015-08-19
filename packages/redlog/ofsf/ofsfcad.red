% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 2000-2009 A. Dolzmann, A. Seidl, and T. Sturm
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
   fluid '(ofsf_cad_rcsid!* ofsf_cad_copyright!*);
   ofsf_cad_rcsid!* :=
      "$Id$";
   ofsf_cad_copyright!* := "(c) 2000-2009 A. Dolzmann, A. Seidl, T. Sturm"
>>;

module ofsfcad;

fluid '(ofsf_wd!*);

ofsf_wd!* := "/tmp/";  % will be concatenated - use trailing slash

switch rlqegen1,rlcadans,rlcadtree2dot,rlcadrmwc;

off1 'rlqegen1;
off1 'rlcadans;
off1 'rlcadtree2dot;
on1 'rlcadrmwc;

struct CadData checked by CadDataP;
struct Acell checked by AcellP;
struct Atree checked by AtreeP;

% TODO: Is there a LISP function checking whether its input is a vector?
procedure CadDataP(s);
   atom s and getv(s, 0) eq 'caddata;

procedure AcellP(s);
   pairp s and car s eq 'acell;

procedure AtreeP(s);
   pairp s and car s eq 'atree;

asserted procedure ofsf_cadverbosep(): Boolean;
   % CAD verbose predicate.
   !*rlverbose and !*rlcadverbose;

% rlgcad entry point
asserted procedure ofsf_gcad(phi: Formula, prjordl: List, aaplus: List): DottedPair;
   % Ordered field standard form generic cylindrical algebraic decomposition.
   % [phi] is a formula, [prjordl] is a list of variables (projection order),
   % and [aaplus] is a list of SF. Returns a pair [theta . phip], where [theta]
   % is a list of inequalities and [phip] is a quantifier-free formula. It holds
   % that $\bigwedge\theta$ implies ([phi] equivalent to [phip])$.
   begin scalar !*rlqegen;
      !*rlqegen := t;
      return ofsf_cad(phi, prjordl, aaplus)
   end;

% rlcad entry point
asserted procedure ofsf_cad(phi: Formula, prjordl: List, aaplus: List): Any;
   % Ordered field standard form cylindrical algebraic decomposition. [phi] is a
   % formula, [prjordl] is a list of variables (projection order), and [aaplus]
   % is a list of SF. Returns a pair [theta . phip], where [theta] is a list of
   % inequalities and [phip] is a quantifier-free formula. It holds that
   % $\bigwedge\theta$ implies ([phi] equivalent to [phip])$.
   % Old comment fragment:
   % If [phi] is closed (and rlcadanuex is switched on) a quantifier-free
   % formula equivalent to [phi] is returned, otherwise [phi] is returned in
   % prenex normal form.
   begin scalar cd;
      cd := ofsf_cadpreparation(phi, prjordl, aaplus);
      if !*rlverbose then
	 caddata_print cd;
      if !*rlcadpreponly then <<
	 if !*rlverbose then
	    ioto_tprin2t "+ rlcadpreponly is on: Jump into finish.";
	 return ofsf_cadfinish cd
      >>;
      ofsf_cadprojection cd;
      if !*rlcadprojonly then <<
	 if !*rlverbose then
	    ioto_tprin2t "+ rlcadprojonly is on: Jump into finish.";
	 return ofsf_cadfinish cd
      >>;
      ofsf_cadextension cd;
      if !*rlcadextonly then <<
	 if !*rlverbose then
	    ioto_tprin2t "+ rlcadextonly is on: Jump into finish.";
	 return ofsf_cadfinish cd
      >>;
      ofsf_solutionformula cd;
      return ofsf_cadfinish cd
   end;

% rlcadproj entry point
asserted procedure ofsf_cadproj(phi: Formula, prjordl: List): DottedPair;
   begin scalar cd, theo, ffl;
      cd := ofsf_cadpreparation(phi, prjordl, nil);
      if !*rlverbose then
	 caddata_print cd;
      ofsf_cadprojection cd;
      % if !*rlverbose then
      for each f in caddata_theo cd do
	 mathprint rl_prepfof f;
      ofsf_restorekord cd;
      theo := for each f in caddata_theo cd collect
	 ofsf_reorder f;
      ffl := reversip for j := 1 : caddata_r cd collect
	 for each p in caddata_ffj(cd, j) collect
	    reorder p;
      return theo . ffl
   end;

% rlcadpnum entry point
asserted procedure ofsf_cadpnum(phi: Formula, prjordl: List): List;
   begin scalar cd, dd, resl;
      scalar !*rlcadtrimtree;
      cd := ofsf_cadpreparation(phi, prjordl, nil);
      if !*rlverbose then
	 caddata_print cd;
      ofsf_cadprojection cd;
      ofsf_cadextension cd;
      ofsf_restorekord cd;
      dd := caddata_dd cd;
      resl := for i := 0 : length caddata_varl cd collect
	 length atree_childrenatlevel(dd, i);
      return resl
   end;

% rlcadfnum entry point
asserted procedure ofsf_cadfnum(pl: List, prjordl: List): List;
   % [pl] is a list (Fr, ..., F1) of lists of projection factors, [prjordl] is a
   % list (xr, ..., x1) of variables. Returns a list (#D0, ..., #Dr) of positive
   % integers: The number of cells on each level of the CAD tree for (Fr, ...,
   % F1).
   begin scalar oldorder, w, ff, varl, resl;
      oldorder := setkorder prjordl;
      w := for each ffj in pl collect
 	 for each f in ffj collect
	    reorder numr simp f;
      ff := reverse w;
      varl := reverse prjordl;
      resl := ofsf_cadfnum1(ff, varl);
      setkorder oldorder;
      return resl
   end;

symbolic operator rlcadpnum;
procedure rlcadpnum(phi, prjordl);
   % Number of nodes in a partial CAD tree.
   'list . ofsf_cadpnum(rl_simp phi, cdr prjordl);

symbolic operator rlcadfnum;
procedure rlcadfnum(pl, prjordl);
   % Number of nodes in the full CAD tree.
   begin
      pl := for each ffj in cdr pl collect
	 cdr ffj;
      return 'list . ofsf_cadfnum(pl, cdr prjordl)
   end;

% TODO: We need a clear concept when is a field [nil] and when ['undefined]. An
% example is caddata_theo. This has something to do with switches !*rlqegen and
% !*rlqegen1. Understand the switches.

asserted procedure ofsf_cadpreparation(phi: Formula, prjordl: List, aaplus: List): CadData;
   % CAD preparation. [phi] is an ofsf formula. [prjordl] is a list of variables
   % encoding a desired variable projection order; [prjordl] contains all
   % variables of [phi] and bound variables are in front of free variables.
   % [aaplus] is a list of SF; additional polynomials to be added to projection
   % polynomials.
   begin scalar w, ophi, varl, qal, oldorder, psi, aa, rvbl, cd;
      integer r, k, l;
      if !*rlverbose then
	 ioto_tprin2t "+++ Preparation Phase";
      if !*rlcaddecdeg then <<
      	 w := ofsf_decdeg0 phi;
      	 phi := car w;
      	 if !*rlverbose then <<
	    ioto_prin2 "+ decrease degrees: ";
	    ioto_prin2t for each x in cdr w join {"(", car x, "^", cdr x, ")"}
	 >>
      >>;
      ophi := phi := cl_pnf phi;
      % [ophi] with old kernel order
      varl . qal := ofsf_mkvarl phi;
      % [varl] is (x_r, ..., x_1).
      % [qal] is ((x_r . Q_r), ..., (x_k+1 . Q_k+1)).
      if prjordl then <<
	 varl := prjordl;
	 qal := for each x in qal collect <<
	    w := pop prjordl;
	    w . cdr x
	 >>
      >>;
      r := length varl;
      k := r - length qal;
      % reordering w.r.t. varl
      oldorder := setkorder varl;
      if !*rlverbose then
	 ioto_prin2t {"+ Kernel order set to ", varl};
      varl := reverse varl;  % reversip would affect kernel order
      % [varl] is now (x_1, ..., x_r).
      qal := reversip qal;
      % [qal] is now ((x_k+1 . Q_k+1), ..., (x_r . Q_r)).
      phi := ofsf_reorder phi;
      psi := cl_matrix phi;
      % phi = Q_k+1 x_k+1 ... Q_r x_r psi.
      aa := for each f in cl_terml phi collect f;
      if aaplus then <<
	 if !*rlverbose then
	    ioto_prin2t {"+++ Adding ", length aaplus, " projection polynomials."};
      	 aaplus := for each f in aaplus collect reorder f
      >>;
      rvbl := reversip ofsf_cadvbl phi;
      l := (if cdr rvbl then k + length car cdr rvbl else 0);
      cd := caddata_mkblank();
      caddata_putphi(cd, phi);
      caddata_putk(cd, k);
      caddata_putr(cd, r);
      caddata_putvarl(cd, varl);
      caddata_putqal(cd, qal);
      caddata_putpsi(cd, psi);
      caddata_putoldorder(cd, oldorder);
      caddata_putophi(cd, ophi);
      caddata_puttheo(cd, nil);
      caddata_putl(cd, l);
      caddata_putaa(cd, aa);
      caddata_putaaplus(cd, aaplus);
      return cd
   end;

asserted procedure ofsf_cadprojection(cd: CadData): Any;
   begin scalar r, ff;
      r := caddata_r cd;
      if !*rlverbose then <<
	 ioto_tprin2t {"+++ Projection Phase"};
	 ioto_prin2t {"+ projection order: ", reverse caddata_varl cd}
      >>;
      ofsf_cadprojection1 cd;  % [caddata_ff] and [caddata_hh] are computed here.
      ff := caddata_ff cd;
      if !*rlverbose then
	 if !*rlcadprojonly then
	    for i := 1 : r do <<
	       ioto_tprin2t {"+ projection factors of level ", r-i+1, ":"};
	       mathprint('list . for each f in getv(ff, r-i+1) collect prepf f)
      	    >>
	 else <<
	    % ioto_tprin2t {"+ (#F1,...,#Fr)=",
	    %    for each ffi in ffl collect length ffi};
	    ioto_tprin2 "+ Number of projection factors of level r,...,1: ";
      	    for i := 0 : r - 2 do
	       ioto_prin2 {length getv(ff, r-i), ","};
	    ioto_prin2t length getv(ff, 1)
      	 >>;
      return nil
   end;

asserted procedure ofsf_cadextension(cd: CadData): Any;
   begin scalar dd; integer r;
      if !*rlverbose then <<
	 ioto_tprin2t "+++ Extension Phase";
	 ioto_tprin2t "+ Building partial CAD tree..."
      >>;
      dd := ofsf_partialtree cd;
      if !*rlverbose then <<
	 r := caddata_r cd;
	 ioto_tprin2 "+ Number of partial CAD tree nodes of level 0,...,r: ";
	 for i := 0 : r - 1 do
	    ioto_prin2 {length atree_childrenatlevel(dd, i), ","};
	 ioto_prin2t length atree_childrenatlevel(dd, r)
      >>;
      if !*rlcadtree2dot then <<
	 atree_2dot(dd, lto_sconcat{ofsf_wd!*, "cadtree.dot"});
	 atree_2tgf(dd, lto_sconcat{ofsf_wd!*, "cadtree.tgf"});
	 atree_2gml(dd, lto_sconcat{ofsf_wd!*, "cadtree.gml"})
      >>;
      caddata_putdd(cd, dd);
      % if !*rlverbose then <<
      % 	 ioto_tprin2t {"+ CAD tree:"};
      % 	 atree_print dd
      % >>;
      return nil
   end;

asserted procedure ofsf_cadfinish(cd: CadData): DottedPair;
   % Returns a pair [(theo . phip)], where [phip] is [caddata_phiprime cd] if a
   % quantifier-free formula equivalent to [phi] was computed. If such a formula
   % was not computed, the input formula [phi] is returned.
   begin scalar w, theo, phiprime;
      if !*rlverbose then
	 ioto_tprin2t {"+++ Finish Phase"};
      if !*rlqegen1 then <<
	 w := for j := 1 : min2(1, caddata_k cd) join
            for each f in caddata_ffj(cd, j) collect
	       ofsf_0mk2('neq, f);
	 caddata_puttheo(cd, append(w, caddata_theo cd))
      >>;
      ofsf_restorekord cd;
      theo := for each f in caddata_theo cd collect ofsf_reorder f;
      if !*rlqegen then
	 theo := ofsf_thsimpl theo;
      phiprime := caddata_phiprime cd;
      if phiprime neq 'undefined then
	 return theo . cl_simpl(ofsf_reorder phiprime, theo, -1);
      return theo . caddata_ophi cd
   end;

asserted procedure ofsf_mkvarl(f: Formula): DottedPair;
   % Make variable list. [f] is a prenex formula. Returns a dotted pair [(vl .
   % qal)], where [vl] is a list of all variables in [f] and [qal] is a list of
   % dotted pairs [x . Q], where [x] is a kernel and [Q] the corresponding
   % quantifier. The first pair in [qal] corresponds to the innermost variable
   % with its quantifier.
   begin scalar vl, qal;
      vl := cl_fvarl1 f;  % list of free variables
      while rl_quap rl_op f do <<
	 qal := (rl_var f . rl_op f) . qal;
	 vl := rl_var f . vl;
	 f := rl_mat f
      >>;
      return vl . qal
   end;

asserted procedure ofsf_restorekord(cd: CadData): Any;
   % Restore the current kernel order to the old kernel order stored in [cd].
   begin scalar oldorder;
      oldorder := caddata_oldorder cd;
      if oldorder neq 'undefined then
	 setkorder oldorder;
      if !*rlverbose then
	 ioto_tprin2 {"+ Kernel order was restored."};
      return nil
   end;

asserted procedure ofsf_reorder(f: Formula): Formula;
   % Reorder formula. Reorders all polynomials occurring in [f] w.r.t. the
   % current kernel order.
   cl_apply2ats(f,
      function(lambda(atf); ofsf_0mk2(ofsf_op atf, reorder ofsf_arg2l atf)));

% Andreas' cell.

% Constructors and access functions for data type Acell plus the code for
% decomposing the cylinder over a given Acell.

%DS
% <CAD> ::= (..., <CDEC>, ...)
% <CDEC> ::= (..., <ACELL>, ...)
% <ACELL> ::= (<IDX> . (<SP> . <TV> . <DESC> . <TL> . nil)) (an alist)
% <IDX> ::= List of natural numbers
% <SP> ::= List of ANU's
% <DESC> ::= "quantifier-free formula"
% <TL> ::= "tag list"

% IDX is an integer, the index of the cell. Cells representing points have odd
% indices, cells representing intervals have even indices.

asserted procedure acell_mk(idx: Integer, sp: AnuList, tv: Id, desc: QfFormula, tl: List): Acell;
   % Acell make. [tv] is ['true], ['false], or [nil]; [tl] is a tag list.
   % {'acell, index, sample point, truth value, description, tag list}
   {'acell, idx, sp, tv, desc, tl};

asserted procedure acell_getidx(c: Acell): Any;
   % Get index.
   nth(c, 2);

asserted procedure acell_getsp(c: Acell): AnuList;
   % Get sample point.
   nth(c, 3);

asserted procedure acell_gettv(c: Acell): Id;
   % Get truth value.
   nth(c, 4);

asserted procedure acell_getdesc(c: Acell): QfFormula;
   % Get description.
   nth(c, 5);

asserted procedure acell_gettl(c: Acell): List;
   % Get tag list.
   nth(c, 6);

asserted procedure acell_sri(c: Acell): Any;
   % Symbolic root information.
   atsoc('root, tl) or atsoc('between, tl) or atsoc('below, tl) or
      atsoc('above, tl) or atsoc('arbitrary, tl) where tl=acell_gettl c;

asserted procedure acell_putsp(c: Acell, sp: AnuList): Any;
   % Put sample point.
   nth(c, 3) := sp;

asserted procedure acell_puttv(c: Acell, tv: Id): Any;
   % Put truth value.
   nth(c, 4) := tv;

asserted procedure acell_putdesc(c: Acell, desc: QfFormula): Any;
   % Put description.
   nth(c, 5) := desc;

asserted procedure acell_puttl(c: Acell, tl: List): Any;
   % Put tag list.
   nth(c, 6) := tl;

asserted procedure acell_addtagip(c: Acell, tg: Any): Any;
   % Add tag in place.
   nth(c, 6) := tg . nth(c, 6);

asserted procedure acell_tvasstring(c: Acell): String;
   begin scalar tv;
      tv := acell_gettv c;
      if tv eq 'true then
      	 return "T";
      if tv eq 'false then
	 return "F";
      return "?"
   end;

asserted procedure acell_med(c: Acell): Rational;
   % Middle point of the interval of the sample point's last coordinate.
   iv_med anu_iv car acell_getsp c;

asserted procedure acell_sortfn(c1: Acell, c2: Acell): Boolean;
   rat_leq(acell_med c1, acell_med c2);

% module cadtree;

asserted procedure ofsf_cadfnum1(ff: List, varl: List): List;
   % Full CAD num subroutine. [ff] is a list (F1, ..., Fr) of lists of
   % polynomials. Returns a list of positive integers of length r+1.
   begin scalar hh, w;
      hh := for each ffj in ff collect
	 for each f in ffj collect
	    'dummytag . f;
      w := ofsf_fulltree(list2vector(nil . hh), varl);
      return for i := 0 : length varl collect
	 length atree_childrenatlevel(w, i)
   end;

asserted procedure ofsf_fulltree(hh: Atom, varl: List): Atree;
   % [hh] is a vector [nil, F_1, ..., F_r], where the elements are Alists of
   % tag . SF.
   begin scalar basecell;
      basecell := acell_mk(0, nil, nil, nil, nil);  % the only cell of R^0
      return ofsf_ftoc(basecell, hh, varl)
   end;

asserted procedure ofsf_ftoc(basecell: Acell, hh: Atom, varl: List): Atree;
   % Full CAD tree over cell. [basecell] is a cell in R^{j-1}, [hh] is a vector
   % [nil, F_1, ..., F_r], where the elements are Alists of tag . SF, [varl] is
   % (x_1, ..., x_r). Returns an Atree over the basecell. Intuition: Recursively
   % find for a cell C in R^j and recursively build a full CAD tree that has C
   % as its root. Each cell has a sample point, but no truth value.
   begin scalar sp, xj, cell, treel, iri, ncbuffer, res;
      integer r, k, j;
      sp := acell_getsp basecell;
      j := length sp + 1;
      if ofsf_cadverbosep() then
	 ioto_prin2 {"(", j - 1};
      r := length varl;
      k := r;  % This is not needed. ofsf_nextcell would need it only for fulldimonly and gen1.
      % (1) Non-recursion Case: j = r + 1. [basecell] is a leaf.
      if eqn(j - 1, r) then <<
	 if ofsf_cadverbosep() then
	    ioto_prin2 ")";
      	 return atree_mk basecell
      >>;
      xj := nth(varl, j);
      iri := ofsf_iriprepare(getv(hh, j), xj, sp, varl);
      ncbuffer := ncb_init();
      % (2) Recursion Case: 1 <= j <= r
      assert(1 <= j and j <= r);
      while cell := ofsf_nextcell(ncbuffer, sp, iri, xj, j, k) do
	 push(ofsf_ftoc(cell, hh, varl), treel);
      if ofsf_cadverbosep() then
	 ioto_prin2 ")";
      res := atree_mk basecell;
      atree_setchildl(res, treel);
      return res
   end;

asserted procedure ofsf_partialtree(cd: CadData): Atree;
   begin scalar basecell;
      % basecell := acell_mk(0, nil, nil, 'true, nil);  % the only cell of R^0
      basecell := acell_mk(0, nil, nil, nil, nil);  % the only cell of R^0
      return ofsf_ptoc(basecell, cl_nnf caddata_psi cd, cd)
   end;

asserted procedure ofsf_ptoc(basecell: Acell, psi: QfFormula, cd: CadData): Atree;
   % Partial CAD tree over cell. [basecell] is a cell in R^{j-1}. Returns a
   % partial tree over [basecell]. Intuition: Recursively find for a cell C in
   % R^j a partial CAD tree that has C as its root. If j > k, then C has a truth
   % value.
   begin
      scalar sp, varl, xj, cell, tree, treel, qj, neutral, iri, ncbuffer, res, tv;
      integer j, r, k;
      sp := acell_getsp basecell;
      j := length sp + 1;
      if ofsf_cadverbosep() then
	 ioto_prin2 {"(", j - 1};
      r := caddata_r cd;
      varl := caddata_varl cd;
      % (1) Non-recursion Case: j = r + 1. [basecell] is a leaf.
      if eqn(j - 1, r) then <<
	 acell_puttv(basecell, ofsf_evalqff(psi, sp, varl));
	 if ofsf_cadverbosep() then
	    ioto_prin2 ")";
      	 return atree_mk basecell
      >>;
      % (2) Recursion Case: 1 <= j <= r
      assert(1 <= j and j <= r);
      if !*rlcadte then <<  % trial evaluation
	 psi := ofsf_trialeval(psi, sp);
      	 if psi memq '(true false) then <<
	    acell_puttv(basecell, psi);
	    if ofsf_cadverbosep() then
	       ioto_prin2 ":T)";
	    return atree_mk basecell
      	 >>
      >>;
      k := caddata_k cd;
      xj := nth(varl, j);
      iri := ofsf_iriprepare(caddata_hhj(cd, j), xj, sp, varl);
      ncbuffer := ncb_init();
      if (1 <= j and j <= k) then <<  % (2a) Subcase: 1 <= j <= k
	 while cell := ofsf_nextcell(ncbuffer, sp, iri, xj, j, k) do
	    if ofsf_iswhitecell(cell, cd) then <<
	       if ofsf_cadverbosep() then
	    	  ioto_prin2 {"(", j, ":W)"}
	    >> else
	       push(ofsf_ptoc(cell, psi, cd), treel);
      	 if null treel then  % TODO: Understand why this is an error!
	    rederr "GCAD: stack full of white cells occured.";
	 % This sort should not be needed from correctness point of view.
   	 % TODO: Verify this to be 100% sure!
	 treel := sort(treel, function atree_sortfn);
      	 res := atree_mk basecell;
	 atree_setchildl(res, treel);
	 if ofsf_cadverbosep() then
	    ioto_prin2 ")";
      	 return ofsf_pbfvs(res, treel)
      >>;
      % (2b) Subcase: k < j <= r
      qj := cdr nth(caddata_qal cd, j - k);
      neutral := if qj eq 'all then 'true else 'false;
      tv := neutral;
      while (tv eq neutral) and
	 (cell := ofsf_nextcell(ncbuffer, sp, iri, xj, j, k)) do <<
	    tree := ofsf_ptoc(cell, psi, cd);
	    push(tree, treel);
	    tv := acell_gettv atree_rootcell tree
	 >>;
      acell_puttv(basecell, tv);
      res := atree_mk basecell;
      if !*rlcadans then <<
	 % To add answers we need to isolate all remaining roots:
	 while (cell := ofsf_nextcell(ncbuffer, sp, iri, xj, j, k)) do
	    push(atree_mk cell, treel);
      	 treel := sort(treel, function atree_sortfn);
	 ofsf_addanswers(basecell, treel, j, cd);
      	 if ofsf_cadverbosep() then
	    ioto_prin2 ")";
	 atree_setchildl(res, treel);
	 return res
      >>;
      if not !*rlcadtrimtree then <<
      	 treel := sort(treel, function atree_sortfn);
	 atree_setchildl(res, treel)
      >>;
      if ofsf_cadverbosep() then
	 ioto_prin2 ")";
      return res
   end;

asserted procedure ofsf_iswhitecell(cell: Acell, cd: CadData): Boolean;
   % Is white cell.
   begin scalar theta, sp;
      if (caddata_theo cd eq 'undefined) or (not !*rlcadrmwc) then
	 return nil;
      theta := rl_smkn('and, caddata_theo cd);
      sp := acell_getsp cell;
      theta := ofsf_trialeval(theta, sp);
      if theta eq 'false then
	 return t;
      return nil
   end;

asserted procedure ofsf_trialeval(psi: QfFormula, sp: AnuList): QfFormula;
   cl_simpl(cl_apply2ats1(psi,
      function(lambda(atf, sp); ofsf_0mk2(ofsf_op atf,
	 ofsf_trialevalsgnf(ofsf_arg2l atf, sp))), {sp}),
      nil, -1);

asserted procedure ofsf_pbfvs(btr: Atree, treel: List): Atree;
   % Propagate truth value below free variable space.
   begin scalar tv, c, w;
      if not !*rlcadpbfvs then
      	 return btr;
      assert(not null treel);
      w := pop treel;
      tv := acell_gettv atree_rootcell w;
      if tv neq 'true and tv neq 'false then
	 return btr;
      c := t; while c and treel do <<
      	 w := pop treel;
	 if tv neq acell_gettv atree_rootcell w then
	    c := nil
      >>;
      if c then <<
	 acell_puttv(atree_rootcell btr, tv);
      	 if !*rlcadtrimtree then
	    atree_setchildl(btr, nil)
      >>;
      return btr
   end;

asserted procedure ofsf_addanswers(basecell: Acell, treel: List, j: Integer, cd: CadData): Any;
   % Add root info and answers to cells. [treel] is a non-empty list of Atrees.
   begin integer k, l;
      k := caddata_k cd;
      l := caddata_l cd;
      if k+1 <= j and j <= l then <<
      	 ofsf_addrootinfo(treel, getv(caddata_hhtags cd, j));
	 % The following is a propagation of an answer to lower levels.
	 % TODO: Rewrite this in a proper way.
      	 % 	 if j = l then
      	 % 	    for each tt in treel do
      	 % 	       if acell_gettv atree_rootcell tt eq 'true then
      	 % 	       	  acell_addtagip(atree_rootcell tt, 'answers . {nil});
      	 % 	 acell_addtagip(basecell,
      	 % 	    'answers . for each tt in treel join
      	 % 	       if acell_gettv atree_rootcell tt eq 'true then
      	 % 	       	  for each a in cdr atsoc('answers, acell_gettl atree_rootcell tt) collect
      	 % 	 	     acell_sri atree_rootcell tt . a)
      >>
   end;

asserted procedure ofsf_addrootinfo(treel: List, hhtags: List): Any;
   % Add root information. [treel] is a non-empty list of Atrees. The argument
   % is changed in-place. We add the "symbolic root information" to the root
   % labels of these trees. We assume that cells, which have a 0-dim last
   % component, have inherited their tags from the appropriate projection
   % factors.
   begin scalar rnl, rtg, ltg;
      % [treel] has to consist of an odd number of elements.
      assert(not evenp length treel);
      % If there is only one cell, then it is already tagged with 'arbitrary.
      if null cdr treel then
	 return nil;
      % There are at least 3 cells.
      % [rnl] (root number list) is an Alist of dotted pairs [tag . num].
      rnl := for each tag in hhtags collect
	 tag . 0;
      % Add info to the second cell from the left.
      rtg := ofsf_addrootinfo0dim(atree_rootcell cadr treel, rnl, hhtags);
      % Add info to the leftmost cell.
      acell_puttl(atree_rootcell car treel, {'below, rtg});
      treel := cddr treel;
      ltg := rtg;
      while cdr treel do <<  % There are at least 3 cells.
         rtg := ofsf_addrootinfo0dim(atree_rootcell cadr treel, rnl, hhtags);
	 acell_puttl(atree_rootcell car treel, {'between, ltg, rtg});
	 treel := cddr treel;
         ltg := rtg
      >>;
      acell_puttl(atree_rootcell car treel, {'above, ltg})
   end;

asserted procedure ofsf_addrootinfo0dim(cell: Acell, rnl: Alist, hhtags: List): Any;
   % Add root info to a cell with 0-dim last component in-place. Returns the
   % added info.
   begin scalar tl, ri;
      tl := acell_gettl cell;
      ofsf_rnlinc(rnl, tl);
      ri := 'root . for each tag in intersection(hhtags, tl) collect
	 tag . cdr atsoc(tag, rnl);
      % acell_addtagip(cell, ri);
      acell_puttl(cell, ri);
      return ri
   end;

asserted procedure ofsf_rnlinc(rnl: Alist, tl: List): Any;
   % Increment those elements in [rnl] whose car is in [tl]. This is done
   % in-place.
   for each rn in rnl do
      if memq(car rn, tl) then
	 cdr rn := cdr rn + 1;

asserted procedure ofsf_iriprepare(hhj: Alist, xj: Kernel, sp: AnuList, varl: List): Iri;
   % Prepare polynomials for incremental root isolation. [hhj] is an Alist of
   % tag . SF, [xj] is a variable, [sp] is a sample point. Returns an Iri data
   % structure, which can be used to incrementally isolate the roots of [hhj].
   begin scalar w;
      w := for each pr in hhj collect
	 aex_fromsf cdr pr . {car pr};
      w := for each tae in w collect
	 ofsf_subsp(car tae, sp, varl) . cdr tae;
      w := for each tae in w collect
	 aex_mklcnt aex_reduce car tae . cdr tae;
      w := for each tae in w join
	 if not aex_simplenumberp car tae then
	    {aex_reduce aex_sqfree(car tae, xj) . cdr tae};
      % w := tglist2set w;
      % Make the elements of [w] pairwise prime.
      w := aex_tgpairwiseprime(w, xj);
      return iri_init(w, xj)
   end;

asserted procedure aex_tgpairwiseprime(tael: TgAexList, x: Kernel): TgAexList;
   % Pairwise prime with tags. [tael] is transformed to another TgAexList, which
   % has the same real roots, but no two polynomials have a common root. This is
   % achieved by systematically dividing the gcd of all pairs of polynomials in
   % [tael], and adding the gcd as a "new" polynomial, which inherits tags from
   % the polynomials it divides.
   begin scalar pprestlist;
      if null tael or null cdr tael then
	 return tael;
      pprestlist := aex_tgpairwiseprime(cdr tael, x);
      return aex_tgpairwiseprime1(car tael . pprestlist, x)
   end;

asserted procedure aex_tgpairwiseprime1(tael: TgAexList, x: Kernel): TgAexList;
   begin scalar tae1, tae2, taelnew, g, tg;
      integer d1, deg;
      tae1 := pop tael;
      d1 := aex_deg(car tae1, x);
      while tael and not eqn(d1, 0) do <<
	 tae2 := pop tael;
	 g := aex_gcd(tag_o tae1, tag_o tae2, x);
	 deg := aex_deg(g, x);
	 if deg > 0 then <<
      	    tae1 := tag_mktag(aex_quot(tag_o tae1, g, x), tag_t tae1);
	    tae2 := tag_mktag(aex_quot(tag_o tae2, g, x), tag_t tae2);
	    tg := tag_mktag(g, union(tag_t tae1, tag_t tae2));
	    d1 := d1 - deg;
	    push(tg, taelnew)
	 >>;
	 if aex_deg(tag_o tae2, x) > 0 then
 	    push(tae2, taelnew)
      >>;
      taelnew := reversip taelnew;
      if not eqn(d1, 0) then
      	 push(tae1, taelnew);
      return append(taelnew, tael)
   end;

% CadData

asserted procedure caddata_mkblank(): CadData;
   % Blank caddata. Undefined entries have the value ['undefined].
   begin scalar cd;
      cd := mkvect(18);
      putv(cd,0, 'caddata);
      putv(cd,1, 'undefined);
      % [phi] is a ofsf formula in prenex normal form; the input formula for
      % which a CAD is to be constructed.
      putv(cd,2, 'undefined);
      % [k] is an integer; the number of free variables in [phi].
      putv(cd,3, 'undefined);
      % [r] is an integer; the number of all variables in [phi].
      putv(cd,4, 'undefined);
      % [varl] is a list of kernels; all variables in [phi]. This list also
      % determines the projection order: The last variable is projected first,
      % the first variable is projected last.
      putv(cd,5, 'undefined);
      % [qal] is a list of dotted pairs [(x . Q)], where [x] is a variable and
      % [Q] is a quantifier; quantifier prefix of [phi].
      putv(cd,6, 'undefined);
      % [psi] is a quantifier-free ofsf formula; matrix of [phi].
      putv(cd,7, 'undefined);
      % [ff] is a vector of lists of SF; projection polynomials.
      putv(cd,8, 'undefined);
      % [dd] is an Atree.
      putv(cd,9, 'undefined);
      % [phiprime] is a quantifier-free ofsf formula; the result equivalent to
      % [phi].
      putv(cd,10,'undefined);
      % [oldorder] is a list of kernels; the old kernel ordering.
      putv(cd,11,'undefined);
      % [ophi] is an ofsf formula; the original input formula using [oldorder].
      % [jj] was here
      putv(cd,13,'undefined);
      % [theo] is a list of negated atoms.
      putv(cd,14,'undefined);
      % [hh] is a vector of alists; tagged projection polynomials; An element of
      % some alist here is a pair id . SF. The first compoment is a tag uniquely
      % identifying the given projection polynomial.
      putv(cd,15,'undefined);
      % [l] is an integer; the number of free variables plus the number of
      % variables in the outermost quantifier block of [phi]; if there is no
      % quantifier, [l] is zero
      putv(cd,16,'undefined);
      % [hhtags] is a vector of lists of ids; tags of all projection polynomials
      putv(cd,17,'undefined);
      % [aa] is list of SF; all polynomials occurring in [phi].
      putv(cd,18,'undefined);
      % [aaplus] is list of SF; polynomials to be added to the projection set
      % before computing the projection.
      return cd
   end;

% access functions

procedure caddata_phi(cd);      getv(cd,1);
procedure caddata_k(cd);        getv(cd,2);
procedure caddata_r(cd);        getv(cd,3);
procedure caddata_varl(cd);     getv(cd,4);
procedure caddata_qal(cd);      getv(cd,5);
procedure caddata_psi(cd);      getv(cd,6);
procedure caddata_ff(cd);       getv(cd,7);
procedure caddata_ffl(cd);      cdr vector2list getv(cd,7);  % [caddata_ff cd] as list.
procedure caddata_ffj(cd,j);    getv(getv(cd,7),j);
procedure caddata_dd(cd);       getv(cd,8);
procedure caddata_phiprime(cd); getv(cd,9);
procedure caddata_oldorder(cd); getv(cd,10);
procedure caddata_ophi(cd);     getv(cd,11);
% [jj] was here
procedure caddata_theo(cd);     getv(cd,13);
procedure caddata_hh(cd);       getv(cd,14);
procedure caddata_hhj(cd,j);      getv(getv(cd,14),j);
procedure caddata_l(cd);        getv(cd,15);
procedure caddata_hhtags(cd);     getv(cd,16);
procedure caddata_aa(cd);       getv(cd,17);
procedure caddata_aaplus(cd);   getv(cd,18);

procedure caddata_bvl(cd);
   % bound variable list
   for i := caddata_k cd + 1 : caddata_r cd collect
      nth(caddata_varl cd, i);

procedure caddata_fvl(cd);
   % free variable list
   for i := 1 : caddata_k cd collect
      nth(caddata_varl cd, i);

procedure caddata_putphi(cd,phi);           putv(cd,1,phi);
procedure caddata_putk(cd,k);               putv(cd,2,k);
procedure caddata_putr(cd,r);               putv(cd,3,r);
procedure caddata_putvarl(cd,varl);         putv(cd,4,varl);
procedure caddata_putqal(cd,qal);           putv(cd,5,qal);
procedure caddata_putpsi(cd,psi);           putv(cd,6,psi);
procedure caddata_putff(cd,ff);             putv(cd,7,ff);
procedure caddata_putdd(cd,dd);             putv(cd,8,dd);
procedure caddata_putphiprime(cd,phiprime); putv(cd,9,phiprime);
procedure caddata_putoldorder(cd,oldorder); putv(cd,10,oldorder);
procedure caddata_putophi(cd,phi);          putv(cd,11,phi);
% [jj] was here
procedure caddata_puttheo(cd,theo);         putv(cd,13,theo);
procedure caddata_puthh(cd,hh);             putv(cd,14,hh);
procedure caddata_putl(cd,l);               putv(cd,15,l);
procedure caddata_puthhtags(cd,hhtags);         putv(cd,16,hhtags);
procedure caddata_putaa(cd,aa);             putv(cd,17,aa);
procedure caddata_putaaplus(cd,aaplus);     putv(cd,18,aaplus);

asserted procedure caddata_print(cd: CadData): Any;
   begin
      ioto_prin2t "+ BEGIN caddata_print";
      if !*rlcadverbose then
	 caddata_printall cd
      else
	 caddata_printsome cd;
      ioto_prin2t "+ END caddata_print"
   end;

asserted procedure caddata_printall(cd: CadData): Any;
   begin
      % if caddata_phi cd neq 'undefined then
	 ioto_prin2t{"phi := ", caddata_phi cd};
      % if caddata_k cd neq 'undefined then
	 ioto_prin2t{"k := ", caddata_k cd};
      % if caddata_r cd neq 'undefined then
	 ioto_prin2t{"r := ", caddata_r cd};
      % if caddata_varl cd neq 'undefined then
	 ioto_prin2t{"varl := ", caddata_varl cd};
      % if caddata_qal cd neq 'undefined then
	 ioto_prin2t{"qal := ", caddata_qal cd};
      % if caddata_psi cd neq 'undefined then
	 ioto_prin2t{"psi := ", caddata_psi cd};
      % if caddata_ff cd neq 'undefined then
	 ioto_prin2t{"ff := ", caddata_ff cd};
      % if caddata_dd cd neq 'undefined then
	 ioto_prin2t{"dd := ", caddata_dd cd};
      % if caddata_phiprime cd neq 'undefined then
	 ioto_prin2t{"phiprime := ", caddata_phiprime cd};
      % if caddata_oldorder cd neq 'undefined then
	 ioto_prin2t{"oldorder := ", caddata_oldorder cd};
      % if caddata_ophi cd neq 'undefined then
	 ioto_prin2t{"ophi := ", caddata_ophi cd};
      % if caddata_theo cd neq 'undefined then
	 ioto_prin2t{"theo := ", caddata_theo cd};
      % if caddata_hh cd neq 'undefined then
	 ioto_prin2t{"hh := ", caddata_hh cd};
      % if caddata_l cd neq 'undefined then
	 ioto_prin2t{"l := ", caddata_l cd};
      % if caddata_hhtags cd neq 'undefined then
	 ioto_prin2t{"hhtags := ", caddata_hhtags cd};
      % if caddata_aa cd neq 'undefined then
	 ioto_prin2t{"aa := ", caddata_aa cd};
      % if caddata_aaplu cd neq 'undefined then
	 ioto_prin2t{"aaplus := ", caddata_aaplus cd}
   end;

asserted procedure caddata_printsome(cd: CadData): Any;
   begin
      if caddata_k cd neq 'undefined then
	 ioto_prin2t{"k := ", caddata_k cd};
      if caddata_r cd neq 'undefined then
	 ioto_prin2t{"r := ", caddata_r cd};
      if caddata_varl cd neq 'undefined then
	 ioto_prin2t{"varl := ", caddata_varl cd};
      if caddata_qal cd neq 'undefined then
	 ioto_prin2t{"qal := ", caddata_qal cd};
      if caddata_oldorder cd neq 'undefined then
	 ioto_prin2t{"oldorder := ", caddata_oldorder cd}
   end;

% TODO: Switches !*rlcadhongproj and !*rlcadfac are not used. Remove them.

asserted procedure ofsf_printcadswitches(): Any;
   % Prints the status of all switches relevant to CAD.
   <<
      ioto_tprin2 "+ begin CAD relevant switches";
      % ioto_tprin2 "+ verbose switches:";
      ofsf_cadswitchprint !*rlverbose; ioto_prin2 "rlverbose;";
      ofsf_cadswitchprint !*rlcadverbose; ioto_prin2 "rlcadverbose;";
      ofsf_cadswitchprint !*rlanuexverbose; ioto_prin2 "rlanuexverbose;";
      % ioto_tprin2 "+ preparation phase switches:";
      ofsf_cadswitchprint !*rlcaddecdeg; ioto_prin2 "rlcaddecdeg;";
      % ioto_tprin2 "+ projection phase switches:";
      ofsf_cadswitchprint !*rlcadhongproj; ioto_prin2 "rlcadhongproj;";
      ofsf_cadswitchprint !*rlcadfac; ioto_prin2 "rlcadfac;";
      % ioto_tprin2 "+ extension phase switches";
      ofsf_cadswitchprint !*rlcadte; ioto_prin2 "rlcadte;";
      ofsf_cadswitchprint !*rlcadpbfvs; ioto_prin2 "rlcadpbfvs;";
      ofsf_cadswitchprint !*rlcadtrimtree; ioto_prin2 "rlcadtrimtree;";
      ofsf_cadswitchprint !*rlcadfasteval; ioto_prin2 "rlcadfasteval;";
      ofsf_cadswitchprint !*rlcadfulldimonly; ioto_prin2 "rlcadfulldimonly;";
      ofsf_cadswitchprint !*rlcadans; ioto_prin2 "rlcadans;";
      ofsf_cadswitchprint !*rlcadtree2dot; ioto_prin2 "rlcadtree2dot;";
      ofsf_cadswitchprint !*rlcadrmwc; ioto_prin2 "rlcadrmwc;";
      % ioto_tprin2 "+ solution formula construction phase switches:";
      ofsf_cadswitchprint !*rlcadrawformula; ioto_prin2 "rlcadrawformula;";
      % ioto_tprin2 "+ general switches:";
      ofsf_cadswitchprint !*rlcadpreponly; ioto_prin2 "rlcadpreponly;";
      ofsf_cadswitchprint !*rlcadprojonly; ioto_prin2 "rlcadprojonly;";
      ofsf_cadswitchprint !*rlcadextonly;  ioto_prin2 "rlcadextonly;";
      ioto_tprin2 "+ end CAD relevant switches"
   >>;

asserted procedure ofsf_cadswitchprint(b: Boolean): Any;
   % Print a single switch.
   if b then ioto_tprin2 "on " else ioto_tprin2 "off ";

% root isolation

% New Cell Buffer

asserted procedure ncb_init(): List;
   % New cell buffer init. NcBuffer holds exactly one element. The lement is
   % either [nil], ['finished], or an Acell.
   {nil};

asserted procedure ncb_get(ncb: List): ExtraBoolean;
   % New cell buffer get. Return the single element and reset it to [nil].
   begin scalar w;
      w := car ncb;
      % car ncb := if w eq 'finished then 'finished else nil;
      car ncb := nil;
      return w
   end;

asserted procedure ncb_put(w: Any, ncb: List): List;
   % New cell buffer put.
   <<
      assert(null car ncb);
      car ncb := w;
      ncb
   >>;

asserted procedure ofsf_nextcell(ncbuffer: List, sp: AnuList, iri: Iri, xj: Kernel, j: Integer, k: Integer): ExtraBoolean;
   % Returns either a new Acell or nil. Caveat: [j = length sp + 1], i.e., [j]
   % is the level of the newly generated cell.
   begin scalar cell, tgroot, root, w;
      integer cind;
      cell := ncb_get ncbuffer;
      if cell eq 'finished then <<
	 ncb_put('finished, ncbuffer);
	 return nil
      >>;
      if cell then <<
	 if not ((!*rlcadfulldimonly and j > k) or (!*rlqegen1 and j <= min2(1, k))) then
	    return cell;
      	 if ofsf_cadverbosep() then <<
	    if !*rlcadfulldimonly and j > k then
	       ioto_prin2 {"(", j, ":F)"};
	    if !*rlqegen1 and j <= min2(1, k) then
	       ioto_prin2 {"(", j, ":G)"}
	 >>
      >>;
      % There is no cell left, we need to get a root to get the next two cells.
      tgroot := iri_nextroot iri;
      cind := 2*(length iri_rootl iri);
      if tgroot then <<
	 root := tag_o tgroot;
	 % Store the 0-dim cell into the [ncbuffer]:
	 ncb_put(acell_mk(cind - 1, root . sp, nil, nil, tag_t tgroot), ncbuffer);
	 w := iv_lb anu_iv root;
	 % Return the full-dim cell with a rational sample point:
	 return acell_mk(cind - 2, anu_fromrat(xj, w) . sp, nil, nil, nil)
      >>;
      % There is no cell and no root left.
      ncb_put('finished, ncbuffer);
      if null iri_rootl iri then  % If there was no root, make a cell with 0 as the sample point.
	 return acell_mk(0, anu_fromrat(xj, rat_0()) . sp, nil, nil, 'arbitrary);
      % Search rootlist for the maximum of all right bounds and make a cell.
      w := rat_mapmax for each tanu in iri_rootl iri collect iv_rb anu_iv tag_o tanu;
      return acell_mk(cind, anu_fromrat(xj, w) . sp, nil, nil, nil)
   end;

asserted procedure ofsf_subsp(ae: Aex, sp: AnuList, varl: List): Aex;
   % Substitute sample point. [sp] is a sample point of length j-1, [varl] is
   % [x_1, ..., x_{j-1}] or a longer list. Returns a univariate Aex.
   begin scalar x, anu;
      sp := reverse sp;
      while sp do <<
	 x := pop varl;
	 anu := pop sp;
      	 ae := aex_bind(ae, x, anu)
      >>;
      return ae
   end;

asserted procedure ofsf_subsp!*(ae: Aex, sp: AnuList): Aex;
   % In Aex, each Anu is bound to the main variable of its defining polynomial.
   % Hence, no variable list is required.
   begin scalar anu;
      sp := reverse sp;
      while sp do <<
	 anu := pop sp;
      	 ae := aex_bind(ae, aex_mvar anu_dp anu, anu)
      >>;
      return ae
   end;

% Tag

% This module implements the datatype Tag(Alpha). An element of this datatype is
% a pair of an object (of type Alpha) and a set of tags.

asserted procedure tag_mktag(a: Any, tag: Any): DottedPair;
   % Tag [a] with [tag].
   a . tag;

asserted procedure tag_o(ti: DottedPair): Any;
   % Object of a tagged item.
   car ti;

asserted procedure tag_t(ti: DottedPair): List;
   % Tag of a tagged item.
   cdr ti;

% asserted procedure tag_add(te: DottedPair, a: Any): DottedPair;
%    % Add a tag to a tagged object.
%    if member(a, tag_t te) then
%       te
%    else
%       tag_o te . (a . tag_t te);

% asserted procedure tglist2set(lte: List): List;
%    % List to set for tagged elements. [lte] is List of tagged elements. Returns
%    % a list of tagged elements such that no element occurs twice.
%    tgunion(lte, {});

% asserted procedure tgunion(st1: List, st2: List): List;
%    % Union of tagged elements. [st1] and [st2] are sets of tagged elements.
%    % Returns a set of tagged elements.
%    <<
%       if st1 then
% 	 for each t1 in st1 do
% 	    st2 := tgunion1(t1, st2);
%       st2
%    >>;

% asserted procedure tgunion1(te: DottedPair, ste: List): List;
%    % Union of tagged elements subroutine. [te] is a tagged element, [ste] is a
%    % set of tagged elements.
%    if null ste then
%       {te}
%    else if tag_o te = tag_o car ste then
%       tag_(tag_o te, union(tag_t te, tag_t car ste)) . cdr ste
%    else
%       car ste . tgunion1(te, cdr ste);

% Atree

%DS
% <ATREE> ::= {'atree, <rootcell>, <childlist>}
% <rootcell> is an Acell
% <childl> is a list of Atrees

asserted procedure atree_mk(c: Acell): Atree;
   % New tree. The new tree is rooted at Acell [c].
   {'atree, c, nil};

asserted procedure atree_rootcell(tt: Atree): Any;
   nth(tt, 2);

asserted procedure atree_childl(tt: Atree): List;
   nth(tt, 3);

asserted procedure atree_childrenatlevel(tt: Atree, n: Integer): List;
   % Returns the list of Acells with distance exactly [n] from the root of [tt].
   if eqn(n, 0) then
      {atree_rootcell tt}
   else
      for each child in atree_childl tt join
      	 atree_childrenatlevel(child, n-1);

asserted procedure atree_setchildl(tt: Atree, cl: List): Any;
   nth(tt, 3) := cl;

% asserted procedure atree_addtochildlip(tt: Atree, cl: List): Any;
%    nth(tt, 3) := nconc(cl, nth(tt, 3));

asserted procedure atree_sortfn(t1: Atree, t2: Atree): Any;
   % Sort function. [t1], [t2] are trees of Acells.
   acell_sortfn(atree_rootcell t1, atree_rootcell t2);

asserted procedure atree_celll(tt: Atree): List;
   % Returns the list of all Acells in [tt].
   if null atree_childl tt then
      {atree_rootcell tt}
   else
      for each child in atree_childl tt join
	 atree_celll child;

asserted procedure atree_celltvl(tt: Atree): List;
   % Truth value cells. Returns a list of Acells, which have assigned a truth
   % value to them.
   if acell_gettv atree_rootcell tt neq nil then
      {atree_rootcell tt}
   else
      for each child in atree_childl tt join
	 atree_celltvl child;

% Atree print procedures

asserted procedure atree_print(tt: Atree): Any;
   for each e in atree_print1(tt, 0) do
      ioto_tprin2t e;

asserted procedure atree_print1(tt: Atree, d: Integer): List;
   begin scalar childl, rootlabel, w;
      childl := atree_childl tt;
      rootlabel := atree_rootcell tt;
      if null childl then
	 return {{acell_tvasstring rootlabel}};
      w := for each s in childl join
	 for each l in atree_print1(s, d+1) collect
	    (" " . "   " . l);
      caar w := acell_tvasstring rootlabel;
      cadar w := "---";
      return w
   end;

asserted procedure atree_print1raw(tt: Atree, d: Integer): List;
   % Returns a list of strings.
   begin scalar childl, w;
      childl := atree_childl tt;
      if null childl then
	 return {{d}};
      w := for each s in childl join
	 for each l in atree_print1raw(s, d+1)
	    collect (" " . l);
      caar w := d;
      return w
   end;

asserted procedure atree_printlin(tt: Atree, d: Integer): Any;
   % Print linear.
   if null atree_childl tt then
      ioto_prin2 {"(", d, ")"}
   else <<
      ioto_prin2 {"(", d};
      for each c in atree_childl tt do
	 atree_printlin(c, d+1);
      ioto_prin2 ")"
   >>;

% Atree to DOT

asserted procedure atree_2dot(tt: Atree, filename: String): Any;
   % Output tree in dot format.
   begin
      out filename;
      ioto_prin2t("digraph cadtree {");
      atree_2dot1(tt,nil);
      ioto_prin2t("}");
      shut filename
   end;

asserted procedure atree_2dot1(tt: Atree, idx: Any): Any;
   begin scalar childlist, idxl, w; integer i, n;
      % Print basecell:
      atree_2dotprinnode idx;
      atree_2dotnodetail atree_rootcell tt;
      i := 1;
      childlist := atree_childl tt;
      n := length childlist;
      while i <= n do <<
	 idxl := append(idx, {i});
	 atree_2dotprinnode idx;
	 ioto_prin2 "->";
	 atree_2dotprinnode idxl;
	 ioto_prin2t "";
	 w := pop childlist;
      	 atree_2dot1(w, idxl);
	 i := i+1
      >>
   end;

asserted procedure atree_2dotprinnode(idxl: List): Any;
   % Print node. [idxl] is a list of integers.
   <<
      ioto_prin2 "C";
      for each e in idxl do
	 ioto_prin2 e
   >>;

asserted procedure atree_2dotnodetail(c: Acell): Any;
   % Print node detail.
   begin scalar tv;
      tv := acell_gettv c;
      if tv eq 'true then
      	 ioto_prin2t(" [label=T shape=circle style=filled color=green]")
      else if tv eq 'false then
      	 ioto_prin2t(" [label=F shape=circle style=filled color=red]")
      else
      	 ioto_prin2t(" [label=""-"" shape=circle style=filled color=grey]")
   end;

% Atree to TGF (Trivial Graph Format)

asserted procedure atree_2tgf(tt: Atree, filename: String): Any;
   % Atree to tgf. Outputs the atree [tt] to file [filename] in tgf (Trivial
   % Graph Format) syntax.
   begin
      out filename;
      atree_2tgf_nodes(tt, 1);
      ioto_prin2t "#";
      atree_2tgf_edges(tt, 1);
      shut filename
   end;

asserted procedure atree_2tgf_nodes(tt: Atree, number: Integer): Integer;
   begin scalar childlist;
      ioto_prin2 number;
      acell_prin atree_rootcell tt;
      childlist := atree_childl tt;
      for each child in childlist do
	 number := atree_2tgf_nodes(child, number + 1);
      return number
   end;

asserted procedure atree_2tgf_edges(tt: Atree, number: Integer): Integer;
   begin scalar childlist, mynumber;
      mynumber := number;
      childlist := atree_childl tt;
      for each child in childlist do <<
	 ioto_prin2t {mynumber, " ", number + 1};
	 number := atree_2tgf_edges(child, number + 1)
      >>;
      return number
   end;

asserted procedure acell_prin(c: Acell): Any;
   begin scalar tmp, tv;
      ioto_prin2 " """;
      ioto_prin2 {"idx: ", acell_getidx c};
      tmp := acell_gettv c;
      tv := if tmp eq 'true then "T" else if tmp eq 'false then "F" else "?";
      ioto_prin2 {", tv: ", tv};
      ioto_prin2 {", desc: ", acell_getdesc c, ", tl: ", acell_gettl c};
      ioto_prin2t """"
   end;

% Atree to GML (Graph Modelling Language)

asserted procedure atree_2gml(tt: Atree, filename: String): Any;
   % Atree to gml. Outputs the Atree [tt] to file [filename] in gml (Graph
   % Modelling Language) syntax.
   begin
      out filename;
      ioto_prin2t("Creator ""REDLOG""");
      ioto_prin2t("graph [");
      ioto_prin2t("label ""Graph generated by REDLOG.""");
      ioto_prin2t("directed 1");
      atree_2gml_nodes(tt, 1);
      atree_2gml_edges(tt, 1);
      ioto_prin2t("]");
      shut filename
   end;

asserted procedure atree_2gml_nodes(tt: Atree, number: Integer): Integer;
   begin scalar childlist;
      atree_2gml_node(tt, number);
      childlist := atree_childl tt;
      for each child in childlist do
	 number := atree_2gml_nodes(child, number + 1);
      return number
   end;

asserted procedure atree_2gml_node(tt: Atree, number: Integer): Any;
   begin scalar c, tv, anul, n, color;
      ioto_prin2t "node [";
      ioto_prin2t {"id ", number};
      c := atree_rootcell tt;
      ioto_prin2t "label """;
      ioto_prin2t {"idx: ", acell_getidx c};
      ioto_prin2 "tp: (";
      anul := reverse acell_getsp c;
      n := length anul;
      for i := 1 : (n - 1) do
      	 ioto_prin2 {anu_evalf nth(anul, i), ", "};
      if n > 0 then ioto_prin2 anu_evalf nth(anul, n);
      ioto_prin2t ")";
      ioto_prin2t {"desc: ", acell_getdesc c};
      ioto_prin2t {"tl: ", acell_gettl c};
      ioto_prin2t """";
      % color
      tv := acell_gettv c;
      color := if tv eq 'true then "#00FF00"
      else if tv eq 'false then "#FF0000" else "#C0C0C0";
      ioto_prin2t {"graphics [", "fill """, color, """]"};
      ioto_prin2t "]"
   end;

asserted procedure atree_2gml_edges(tt: Atree, number: Integer): Integer;
   begin scalar childlist, mynumber;
      mynumber := number;
      childlist := atree_childl tt;
      for each child in childlist do <<
	 atree_2gml_edge(mynumber, number + 1);
	 number := atree_2gml_edges(child, number + 1)
      >>;
      return number
   end;

asserted procedure atree_2gml_edge(efrom: Integer, eto: Integer): Any;
   begin
      ioto_prin2t "edge [";
      ioto_prin2t {"source ", efrom};
      ioto_prin2t {"target ", eto};
      ioto_prin2t "]"
   end;

% CAD solution formula

% Andreas' solution formula construction for the decision case. That is, the
% solution formula is either [true] or [false].

asserted procedure ofsf_solutionformula_old(cd: CadData): Any;
   % old version which looks only at cells of level ddk
   begin scalar ffl, dd, k, ddk, ffk, phiprime, cellstogo;
      if !*rlverbose then
	 ioto_tprin2t "+++ Solution Formula Construction Phase";
      ffl := caddata_ffl cd;
      dd := caddata_dd cd;
      k := caddata_k cd;
      if k eq 0 then <<
	 caddata_putphiprime(cd, acell_gettv atree_rootcell dd);
	 return nil
      >>;
      ddk := atree_childrenatlevel(dd, k);
      % ffk := nth(ffl, k);
      ffk := for i := 1 : k join
	 nth(ffl, i);
      % acdecl = (D_k,...,D_0). ffl = (F_1,...,Fr)
      if !*rlverbose then
	 ioto_tprin2t {"+ generating signatures for ", length ffk,
	    " polynomials in ", length ddk, " cells"};
      cellstogo := length ddk; % for verbose output
      for each cell in ddk do <<
	 acell_putdesc(cell, ofsf_signature(ffk, acell_getsp cell));
	 if ofsf_cadverbosep() then
	    ioto_prin2 {"[", cellstogo,  % "idx",acell_getidx cell," ",
	       (if acell_gettv cell eq 'true then
	       	  " tt" else " ff"),  % acell_getdesc cell,
	       "] "};
	 cellstogo := cellstogo-1
      >>;
      phiprime := ofsf_sfchong(ffk, ddk);
      if phiprime eq 'ssfcfailed then <<
	 if !*rlverbose then
	    ioto_tprin2t "+ Solution formula construction ssfc failed. ";
	 return nil
      >> else <<
	 if !*rlverbose then
	    ioto_tprin2t "+ Solution formula construction ssfc successful.";
	 if !*rlcadrawformula then
	    caddata_putphiprime(cd,phiprime)
	 else
	    caddata_putphiprime(cd,rl_dnf phiprime)
      >>;
      return nil
   end;

asserted procedure ofsf_sfchong(ffk, ddk): Any;
   % Solution formula construction by Hong90. Signatures are already calculated.
   begin scalar wwt, wwf, wwc;
      wwt := ofsf_signaturesbytv(ddk, 'true);
      wwf := ofsf_signaturesbytv(ddk, 'false);
      wwc := intersection(wwt, wwf);
      if null wwc then
	 return rl_smkn('or,
	    for each sig in wwt collect
	       ofsf_sigbasedfo(ffk, sig));
      return 'ssfcfailed
   end;

asserted procedure ofsf_solutionformula(cd: CadData): Any;
   % Solution formula construction. [cd] is changed in place.
   begin scalar dd, yy, w, yyi, ffl, k, fflk, phiprime;
      if !*rlverbose then
	 ioto_tprin2t "+++ Simple Solution Formula Construction Phase";
      dd := caddata_dd cd;
      if memq(acell_gettv atree_rootcell dd, '(true false)) then <<
	 if !*rlverbose and !*rlcadans then
	    ioto_prin2t {"+ ANSWERS (for decision problem): ",
	       cdr atsoc('answers, acell_gettl atree_rootcell dd)};
	 caddata_putphiprime(cd, acell_gettv atree_rootcell dd);
	 return nil
      >>;
      yy := atree_celltvl dd;
      if !*rlverbose and !*rlcadans then <<  % verbose output for QE with answers
         % ioto_prin2t "+ Cells with defined truth value:";
	 % for each cell in yy do
	 %    ioto_prin2t {cell};
	 w := for each cell in yy join
	    if acell_gettv cell eq 'true then
	       {atsoc('answers, acell_gettl cell)};
	 for each c in list2set w do
	    ioto_prin2t {"+ ANSWERS: ", c}
      >>;
      yyi := list2set for each cell in yy collect
      	 length acell_getsp cell;
      if !*rlverbose then
	 ioto_prin2t {"+ Levels to be considered: ", yyi};
      ffl := caddata_ffl cd;
      fflk := for each i in yyi join
	 append(nth(ffl, i), nil);
      k := caddata_k cd;
      phiprime := ofsf_solutionformula1(dd, fflk, yy, k);
      if phiprime eq 'ssfcfailed then <<
	 if !*rlverbose then
	    ioto_tprin2t "+ SSFC failed, trying all possible projection factors.";
	 yyi := for i := 1 : k collect i;
	 if !*rlverbose then
	    ioto_prin2t {"+ Levels to be considered: ", yyi};
	 fflk := for each i in yyi join
	    append(nth(ffl, i), nil);
	 phiprime := ofsf_solutionformula1(dd, fflk, yy, k)
      >>;
      if phiprime eq 'ssfcfailed then <<
	 if !*rlverbose then
	    ioto_tprin2t "+ SSFC failed.";
	 return nil
      >>;
      if !*rlverbose then
	 ioto_tprin2t "+ SSFC succeded.";
      if !*rlcadrawformula then
	 caddata_putphiprime(cd, phiprime)
      else
	 caddata_putphiprime(cd, rl_dnf phiprime);
      return nil
   end;

asserted procedure ofsf_solutionformula1(dd: Atree, ffk: List, yy: List, k: Integer): Any;
   begin integer cellstogo;
      if !*rlverbose then <<
	 ioto_tprin2t {"+ Generating signatures for ", length ffk,
	    " polynomials and ", length yy, " cells."};
	 ioto_tprin2t {"+ Number of cells on level ", k, " is ",
	    length atree_childrenatlevel(dd, k), "."};
	 cellstogo := length yy;  % for verbose output
      >>;
      for each cell in yy do <<
	 acell_putdesc(cell, ofsf_signature4(ffk, acell_getsp cell));
	 if !*rlverbose then <<
	    ioto_prin2 {"[", cellstogo, " ",
	       "sig", acell_getdesc cell, " ",
	       (if acell_gettv cell eq 'true then "true" else "false"), "] "};
	    cellstogo := cellstogo - 1
	 >>
      >>;
      return ofsf_ssfc2(ffk, yy)
   end;

asserted procedure ofsf_ssfc2(ffk: List, yy: List): Any;
   % Solution formula construction by Hong90. Signatures are already calculated.
   begin scalar wwt, wwf, wwc;
      wwt := ofsf_signaturesbytv(yy, 'true);
      wwf := ofsf_signaturesbytv(yy, 'false);
      wwc := ofsf_compsig(wwt, wwf);
      if null wwc then
	 return rl_smkn('or,
	    for each sig in wwt collect
	       ofsf_sigbasedfo(ffk,sig));
      if ofsf_cadverbosep() then
	 ioto_prin2t {"+ SSFC failed because of these compatible signatures: ", wwc};
      return 'ssfcfailed
   end;

asserted procedure ofsf_compsig(ww1: List, ww2: List): ExtraBoolean;
   % Compatible signatures. [ww1] and [ww2] are lists of signatures. All
   % signatures have same length. Returns [nil], if there are no compatible
   % signatures and (w1, w2), if [w1] from [ww1] is compatible with [w2] from [ww2].
   begin scalar ww2copy, retvalue, w1, w2;
      if null ww1 then
	 return nil;
      while ww1 and not retvalue do <<
	 w1 := pop ww1;
	 ww2copy := ww2;
	 while ww2copy and not retvalue do <<
	    w2 := pop ww2copy;
	    if ofsf_compsig1(w1, w2) then
 	       retvalue := {w1, w2}
	 >>
      >>;
      return retvalue
   end;

asserted procedure ofsf_compsig1(w1: List, w2: List): Boolean;
   % Compatible signatures subroutine. [w1], [w2] are signature lists of the
   % same length.
   begin scalar c, s1, s2;
      if null w1 then
   	 return t;
      c := t; while w1 and c do <<
   	 s1 := pop w1;
   	 s2 := pop w2;
   	 if s1 neq s2 and not (s1 equal "?") and not (s2 equal "?") then
   	    c := nil
      >>;
      return c
   end;

asserted procedure ofsf_sigbasedfo(ffk: List, sigl: List): QfFormula;
   % Signature based formula. [ffk] is a list of SF, [sig] is a signature
   % (can include "?").
   begin scalar sig, fo;
      for each f in ffk do <<
	 sig := pop sigl;
	 if not (sig equal "?") then
	    push(ofsf_signofpolyfo(f, sig), fo)
      >>;
      return rl_smkn('and, fo)
   end;

asserted procedure ofsf_signofpolyfo(f: SF, s: Integer): QfFormula;
   % [s] is in {-1, 0, 1}.
   if eqn(s, -1) then
      ofsf_0mk2('lessp, f)
   else if eqn(s, 0) then
      ofsf_0mk2('equal, f)
   else if eqn(s, 1) then
      ofsf_0mk2('greaterp, f);

asserted procedure ofsf_evalqff(f: QfFormula, sp: AnuList, idl: List): Id;
   % Evaluate quantifier-free formula at sample point. Returns ['true] or
   % ['false], i.e., the truth value of f(x_1,...,x_r) at point [sp].
   if !*rlcadfasteval then
      ofsf_evalqff!-fast(f, sp, idl)
   else
      cl_simpl(cl_apply2ats1(f, function ofsf_subsignat, {sp, idl}), nil, -1);

asserted procedure ofsf_evalsignf(f: SF, sp: AnuList, idl: List): SF;
   % Algebraic number evaluate sign of standard form at sample point.
   numr simp aex_sgn ofsf_subsp(aex_fromsf f, sp, idl);

asserted procedure ofsf_trialevalsgnf(f: SF, sp: AnuList): SF;
   % Trial evaluation of sign of a SF at a sample point. The sample point needs
   % not to provide a number for each variable.
   <<
      f := ofsf_subsp!*(aex_fromsf f, sp);
      if aex_simplenumberp f then
	 numr simp aex_sgn f
      else
	 numr aex_ex f
   >>;

asserted procedure ofsf_sgnf4(f: SF, sp: AnuList): Any;
   <<
      f := ofsf_subsp!*(aex_fromsf f, sp);
      if aex_simplenumberp f then
	 aex_sgn f
      else
	 "?"
   >>;

asserted procedure ofsf_subsignat(at: QfFormula, sp: AnuList, idl: List): QfFormula;
   % Substitute sign in atomic formula. Returns an OFSF atomic formula. Returns
   % [at] with the left-hand side $f$ replaced by the sign of $f([sp])$, or a
   % simpler version of f under the context of sp.
   ofsf_0mk2(ofsf_op at, ofsf_evalsignf(ofsf_arg2l at, sp, idl));

asserted procedure ofsf_evalqff!-fast(f: QfFormula, sp: AnuList, idl: List): Id;
   % Evaluate quantifier-free formula at sample point fast. [f] is a
   % quantifier-free OFSF formula in NNF; Returns ['true] or ['false]. Returns
   % the truth value of $f(x_1,\ldots,x_r)$ at point [sp].
   if cl_atfp f then
      ofsf_simplat1(ofsf_subsignat(f, sp, idl), nil)
   else
      ofsf_evalqff!-fast1(f, sp, idl);

asserted procedure ofsf_evalqff!-fast1(f: QfFormula, sp: AnuList, idl: List): Id;
   % Evaluate quantifier-free formula at sample point fastly subroutine. [f] is
   % a quantifier-free OFSF formula in NNF; [sp] is a sample point; [idl] is a
   % LIST of identifiers. Returns ['true] or ['false]. Returns the truth value
   % of $f(x_1,\ldots,x_r)$ at point [sp].
   if rl_tvalp f then
      f
   else
      ofsf_evalqff!-gand(rl_op f, rl_argn f, sp, idl);

asserted procedure ofsf_evalqff!-gand(gand, argl, sp: AnuList, idl: List): Id;
   % Evaluate quantifier-free formula at sample point generic and. [gand] is one
   % of [and], [or]; [argl] is a list of formulas; [sp] is a sample point; [idl]
   % is a LIST of identifiers. Returns ['true] or ['false]. Returns the truth
   % value of $([gand] . [argl])(x_1,\ldots,x_r)$ at point [sp].
   begin scalar gfalse,arg,cargl,c;
      gfalse := cl_cflip('false,gand eq 'and);
      c := t; while argl and c do <<
	 arg := car argl;
	 argl := cdr argl;
	 if cl_atfp arg then
	    (if ofsf_simplat1(ofsf_subsignat(arg,sp,idl),nil) eq gfalse then
	       c := nil)
	 else
	    cargl := arg . cargl
      >>;
      if not c then
	 return gfalse;
      c := t; while cargl and c do <<
	 arg := car cargl;
	 cargl := cdr cargl;
	 if ofsf_evalqff!-fast1(arg,sp,idl) eq gfalse then
	    c := nil
      >>;
      if not c then
	 return gfalse;
      return cl_flip gfalse
   end;

asserted procedure ofsf_signature(fk: List, sp: AnuList): List;
   % Signature. [fk] is a list of standard forms in variables x_1, ..., x_k).
   % [sp] is a sample point, i.e., a list (a_1, ..., a_l) of algebraic numbers
   % with l <= k). Returns a list (sgn_1, ..., sgn_k) of elements from {-1, 0,
   % 1}.
   for each f in fk collect
      aex_sgn ofsf_subsp!*(aex_fromsf f, sp);

asserted procedure ofsf_signature4(fk: List, sp: AnuList): List;
   % Signature. [fk] is a list of standard forms in variables x_1, ..., x_k).
   % [sp] is a sample point, i.e., a list (a_1, ..., a_l) of algebraic numbers
   % with l <= k). Returns a list (sgn_1, ..., sgn_k) of elements from {-1, 0,
   % 1}.
   for each f in fk collect
      ofsf_sgnf4(f, sp);

asserted procedure ofsf_signaturesbytv(ddk: List, tv: Id): List;
   % Signatures by truth value. [ddk] is a list of Acells.
   for each c in ddk join
      if acell_gettv c eq tv then {acell_getdesc c};

endmodule;  % ofsfcad

end;  % of file
