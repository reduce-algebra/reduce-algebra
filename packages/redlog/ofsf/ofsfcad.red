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

switch rlqegen1,rlcadmcproj,rlpscsgen,rlcadans,rlcadtv,rlcadtree2dot,rlcadrmwc;
fluid '(rlcadguessnoc!*);

off1 'rlqegen1;
off1 'rlcadmcproj;
on1 'rlpscsgen;
off1 'rlcadans;
on1 'rlcadtv;
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

% rlcadpnum entry point
asserted procedure ofsf_cadpnum(phi: Formula, prjordl: List): Integer;
   begin scalar !*rlcadtrimtree, cd;
      cd := ofsf_cadpreparation(phi, prjordl, nil);
      if !*rlverbose then
	 caddata_print cd;
      ofsf_cadprojection cd;
      ofsf_cadextension cd;
      ofsf_restorekord cd;
      return length atree_yield caddata_dd cd
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

asserted procedure ofsf_cadpreparation(phi: Formula, prjordl: List, aaplus: List): CadData;
   % CAD preparation. [phi] is an ofsf formula. [prjordl] is a list of variables
   % encoding a desired variable projection order; [prjordl] contains all
   % variables of [phi] and bound variables are in front of free variables.
   % [aaplus] is a list of SF; additional polynomials to be added to projection
   % polynomials.
   begin scalar w, ophi, varl, qal, oldorder, psi, ffr, ff, cd;
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
      ffr := for each f in cl_terml phi collect f;
      ff := mkvect r;
      putv(ff, r, ffr);
      l := (if bvb then k + length car bvb else 0)
      	 where bvb := cdr reverse ofsf_cadvbl1 phi;
      if !*rlverbose and aaplus then
	 ioto_prin2t {"+++ Adding ", length aaplus, " projection polynomials."};
      aaplus := for each f in aaplus collect reorder f;
      cd := caddata_mkblank();
      caddata_putphi(cd, phi);
      caddata_putk(cd, k);
      caddata_putr(cd, r);
      caddata_putvarl(cd, varl);
      caddata_putqal(cd, qal);
      caddata_putpsi(cd, psi);
      caddata_putff(cd, ff);
      caddata_putaa(cd, union(ffr, aaplus));
      caddata_putaaplus(cd, aaplus);
      caddata_putdd(cd, 'undefined);
      caddata_putphiprime(cd, 'undefined);
      caddata_putoldorder(cd, oldorder);
      caddata_putophi(cd, ophi);
      caddata_putjj(cd, 'undefined);
      caddata_puttheo(cd, nil);
      caddata_puthh(cd, nil);
      caddata_putl(cd, l);
      return cd
   end;

asserted procedure ofsf_cadprojection(cd: CadData): Any;
   begin scalar r, ff;
      r := caddata_r cd;
      if !*rlverbose then
	 ioto_tprin2t {"+++ Projection Phase"};
      ofsf_cadprojection1 cd;  % [caddata_ff] and [caddata_jj] are computed here.
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
	    ioto_tprin2 "+ number of projection factors of level r,...,1: ";
      	    for i := 0 : r - 2 do
	       ioto_prin2 {length getv(ff, r-i), ","};
	    ioto_prin2t length getv(ff, 1)
      	 >>;
      return nil
   end;

asserted procedure ofsf_cadextension(cd: CadData): Any;
   begin scalar dd; integer r;
      if !*rlverbose then
	 ioto_tprin2t {"+++ Extension Phase"};
      dd := ofsf_tree cd;
      if !*rlverbose then <<
	 r := caddata_r cd;
	 ioto_tprin2t {"+ (#D0,...,#Dr)=",
	    for i := 0 : r collect length atree_levellabels(dd, i)}
      >>;
      if !*rlcadtree2dot then <<
	 atree_2dot dd;
	 atree_2gml(dd, "cadtree.gml")
      >>;
      caddata_putdd(cd, dd);
      return nil
   end;

asserted procedure ofsf_cadfinish(cd: CadData): DottedPair;
   % Returns a pair [(theo . phip)], where [phip] is [caddata_phiprime cd] if a
   % quantifier-free formula equivalent to [phi] was computed. If such a formula
   % was not computed, the input formula [phi] is returned.
   begin scalar w, oldorder, theo, phiprime;
      if !*rlverbose then
	 ioto_tprin2t {"+++ Finish Phase"};
      if !*rlqegen1 then <<
	 % for j := 1 : min2(1, caddata_k cd) do
         %    caddata_puttheo(cd, append(for each f in caddata_ffj(cd, j) collect
	 %       ofsf_0mk2('neq, f), caddata_theo cd))
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
% indices, cells representing intervals even indices.

asserted procedure acell_mk(idx: Integer, sp: AnuList, tv: Id, desc: QfFormula, tl: List): Acell;
   % Acell make. [idx] is an IDX, [sp] is a SP, [tv] is ['true] or ['false],
   % [desc] is a DESC and [tl] is a tag list.
   % {'acell, identifier, sample point, truth value, description, tag list}
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

asserted procedure acell_sri(c: Acell): Id;
   % Symbolic root information.
   atsoc('root, tl) or atsoc('between, tl) or atsoc('below, tl) or
      atsoc('beyond, tl) or atsoc('arbitrary, tl) where tl=acell_gettl c;

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

asserted procedure acell_addtagip(c: Acell, tg: Id): Any;
   % Add tag in place.
   nth(c, 6) := tg . nth(c, 6);

asserted procedure acell_tvasstring(c: Acell): String;
   begin scalar tv;
      tv := acell_gettv c;
      if tv eq 'true then
      	 return "T";
      if tv 'false then
	 return "F";
      return "?"
   end;

asserted procedure acell_med(c: Acell): Rational;
   % Middle point of the interval of the sample point's last coordinate.
   iv_med anu_iv car acell_getsp c;

asserted procedure acell_sortfn(c1: Acell, c2: Acell): Boolean;
   rat_leq(acell_med c1, acell_med c2);

% module cadtree;

asserted procedure ofsf_tree(cd: CadData): Atree;
   ofsf_treeovercell(basecell, cl_nnf caddata_psi cd, cd)
      where basecell=acell_mk(0, nil, nil, 'true, nil);  % the only cell of R^0

asserted procedure ofsf_treeovercell(basecell: Acell, psi: QfFormula, cd: CadData): Atree;
   % CAD tree over cell. [basecell] is a cell in R^{j-1}. Returns a tree over
   % [basecell]. Intuition: Recursively find for a cell C in R^j a partial CAD
   % tree that has C as a root. If j > k, then C has a truth value.
   begin
      scalar sp, varl, xj, hhhj, cell, tree, treel, qj, neutral, nrdata, ncbuffer, res, tv, tvl;
      integer j, r, k;
      sp := acell_getsp basecell;
      j := length sp + 1;
      r := caddata_r cd;
      if ofsf_cadverbosep() then
	 ioto_prin2 {"(", j - 1};
      varl := caddata_varl cd;
      % (1) Base Case: j - 1 = r. [basecell] is a leaf.
      if eqn(j - 1, r) then <<
	 if !*rlcadtv then
	    acell_puttv(basecell, ofsf_evalqff(psi, sp, varl));
	 if ofsf_cadverbosep() then
	    ioto_prin2 ")";
      	 return atree_new basecell
      >>;
      % trial evaluation
      if !*rlcadtv and !*rlcadte then <<
	 psi := ofsf_trialeval(psi, sp);
      	 if psi memq '(true false) then <<
	    acell_puttv(basecell, psi);
	    if ofsf_cadverbosep() then
	       ioto_prin2 "TE)";
	    return atree_new basecell
      	 >>
      >>;
      if ofsf_cadverbosep() then
      	 ioto_prin2 {":", 1}; % ioto_prin2 {":", 2*n+1};
      k := caddata_k cd;
      xj := nth(varl, j);
      hhhj := ofsf_tocprepare(caddata_hhj(cd, j), xj, sp, varl);
      nrdata := tiri_init(hhhj, xj);
      ncbuffer := ncb_init();
      % (2) Recursion Case: j <= r
      % (2a) 1 <= j <= k or no truth values
      assert(1 <= j and j <= r);
      if (1 <= j and j <= k) or (not !*rlcadtv) then
	 while cell := ofsf_nextcell(ncbuffer, sp, nrdata, xj, j, k) do <<
	    if not ofsf_iswhitecell(cell, cd) then
	       push(ofsf_treeovercell(cell, psi, cd), treel)
	 >>
      else <<  % (2b) k < j <= r
	 if not !*rlcadpartial then  % Compute tree over all cells.
	    while cell := ofsf_nextcell(ncbuffer, sp, nrdata, xj, j, k) do
	       push(ofsf_treeovercell(cell, psi, cd), treel)
	 else <<
      	    qj := cdr nth(caddata_qal cd, j - k);
      	    neutral := if qj eq 'all then 'true else 'false;
	    tv := neutral;
      	    while (tv eq neutral) and
	       (cell := ofsf_nextcell(ncbuffer, sp, nrdata, xj, j, k)) do <<
		  tree := ofsf_treeovercell(cell, psi, cd);
	       	  push(tree, treel);
		  tv := acell_gettv atree_rootlabel tree
	       >>;
	    acell_puttv(basecell, tv)
	 >>
      >>;
      if !*rlcadisoallroots then
	 while cell := ofsf_nextcell(ncbuffer, sp, nrdata, xj, j, k) do
	    push(atree_new cell, treel);
      treel := sort(treel, function atree_sortfn);
      if !*rlcadans then
	 ofsf_addanswers(basecell, treel, j, cd);
      if ofsf_cadverbosep() then
	 ioto_prin2 {"_", 1 - length treel, ")"}; % ioto_prin2 {"_", (2*n+1) - length treel, ")"};
      % Most likely the following will never happen.
      if null treel then
	 rederr "GCAD: stack full of white cells occured.";
      % construct result tree
      if !*rlcadtrimtree and j > k then
	 res := atree_new basecell
      else
	 res := atree_addchildlistip(atree_new basecell, treel);
      % propagation below free variable space
      if not (!*rlcadtv and !*rlcadpbfvs) then
	 return res;
      tvl := list2set for each b in treel collect
	 acell_gettv atree_rootlabel b;
      if eqn(length tvl, 1) then
	 acell_puttv(atree_rootlabel res, car tvl);
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
      if theta eq 'false then <<
	 if ofsf_cadverbosep() then
	    ioto_prin2 {"(", length sp, ":W)"};
	 return t
      >>;
      return nil
   end;

asserted procedure ofsf_trialeval(psi: QfFormula, sp: AnuList): QfFormula;
   cl_simpl(cl_apply2ats1(psi,
      function(lambda(atf, sp); ofsf_0mk2(ofsf_op atf,
	 ofsf_trialevalsgnf(ofsf_arg2l atf, sp))), {sp}),
      nil, -1);

asserted procedure ofsf_addanswers(basecell: Acell, treel: List, j: Integer, cd: CadData): Any;
   % Add root info and answers to cells. [treel] is a non-empty list of Atrees.
   begin integer k, l;
      k := caddata_k cd;
      l := caddata_l cd;
      % 1. add root information
      if !*rlcadisoallroots and k+1 <= j and j <= l then <<
      	 ofsf_addrootinfo(treel, getv(caddata_ffid cd, j));
      	 % if ofsf_cadverbosep() then ioto_tprin2t {for each tt in treel collect
	 %    acell_sri atree_rootlabel tt};
      	 % 2. tag answers in case treel contains cells of level l
      	 if j = l then for each tt in treel do
	    if acell_gettv atree_rootlabel tt eq 'true then
	       acell_addtagip(atree_rootlabel tt, 'answers . {nil});
      	 acell_addtagip(basecell, 'answers . for each tt in treel join
	    if acell_gettv atree_rootlabel tt eq 'true then
	       for each a in cdr atsoc('answers, acell_gettl atree_rootlabel tt)
	       	  collect acell_sri atree_rootlabel tt . a);
      >>
   end;

asserted procedure ofsf_addrootinfo(treel: List, ffids: List): Any;
   % Add root information. [treel] is a non-empty list of ATREEs of ACELLs. The
   % argument is changed in-place. We add the "symbolic root information" to the
   % root labels of these trees. We assume that cells, which have a 0-dim last
   % component, have inherited their tags from the appropriate projection
   % factors.
   begin scalar rnl, rtg, ltg;
      % [treel] will always consist of an odd number of trees.
      % If there is only one cell, then 'sri . 'arbitrary is there already.
      if null cdr treel then
	 return nil;
      % We have at least 3 cells.
      % rnl (root number list) is an alist id . num.
      rnl := for each id in ffids collect
	 id . 0;
      % The leftmost cell is special.
      % tag the second cell from the left.
      rtg := ofsf_addrootinfo0dim(atree_rootlabel cadr treel, rnl, ffids);
      % tag the leftmost cell.
      acell_addtagip(atree_rootlabel car treel, 'below . rtg);
      % 'below . atsoc('root, acell_gettl atree_rootlabel cadr treel));
      treel := cddr treel;
      ltg := rtg;
      % there are at least 3 cells
      while cdr treel do <<
         rtg := ofsf_addrootinfo0dim(atree_rootlabel cadr treel, rnl, ffids);
	 acell_addtagip(atree_rootlabel car treel, 'between . ltg . rtg);
	 treel := cddr treel;
         ltg := rtg;
      >>;
      acell_addtagip(atree_rootlabel car treel, 'beyond . ltg)
   end;

asserted procedure ofsf_addrootinfo0dim(cell: Acell, rnl: List, ffids: List): Id;
   % Add root info to cell with 0-dim last component in-place. Returns the added
   % tag. This return value is used.
   begin scalar tl, ri;
      tl := acell_gettl cell;
      ofsf_rnlinc(rnl, tl);
      ri := 'root . for each tg in intersection(ffids, tl) collect
	 tg . cdr atsoc(tg, rnl);
      acell_addtagip(cell, ri);
      return ri
   end;

asserted procedure ofsf_rnlinc(rnl: List, tl: List): Any;
   % Increment rnl.
   if rnl then <<
      ofsf_rnlinc(cdr rnl, tl);
      if memq(caar rnl, tl) then
	 cdar rnl := cdar rnl + 1
   >>;

% MK: This is a service.
algebraic procedure doc(pl,ql);
   % Degree of correspondence. [pl] and [ql] are LIST(NUM).
   begin scalar np,qp,caa,cbb,ccc,p_i,pj,qi,qj,sd;
      caa := cbb := ccc := 0;
      np := length pl;
      ng := length ql;
      if np neq ng then rederr "doc: parameter lists have different lengths";
      for i := 1 : np-1 do
	 for j := i+1 : ng do
	 <<
	    p_i := mynth(pl,i); pj := mynth(pl,j);
	    qi := mynth(ql,i); qj := mynth(ql,j);
	    if p_i neq -1 and pj neq -1 and qi neq -1 and qj neq -1 then
	    <<
	       caa := caa+1;
	       sd := abs(sign(p_i-pj)-sign(qi-qj));
	       if sd=0 then cbb := cbb+1
	       else if sd=1 then ccc := ccc+1
	    >>
	 >>;
      return (cbb+1/2*ccc)/caa
   end;

% MK: This is a service.
algebraic procedure degreeofcorrespondence(pl,gl);
   begin scalar np,ng;
      np := length pl;
      ng := length gl;
      n := for i := 1 : np-1 sum
	 for j := i+1 : ng sum
	    quality1(mynth(pl,i),mynth(pl,j),mynth(gl,i),mynth(gl,j));
      d := for i := 1 : np-1 sum for j := i+1 : ng sum
	 if mynth(pl,i) neq mynth(pl,j) then 1;
      write d;
      if d=0 then return 1;
      return n/d
   end;

% MK: This is a service.
algebraic procedure quality1(p1,p2,g1,g2);
   if p1=p2 then 0
   else if p1<p2 then
      (if g1>g2 then 0 else if g1=g2 then 1/2 else 1)
   else % p1>p2
      quality1(p2,p1,g2,g1);

% MK: This is a service.
algebraic procedure rlcadnumauto(phi);
%   rlcadnum(rlcadproj(phi,pord),pord)
%      where pord=>for each vb in rlcadvbl phi join vb;
   begin scalar plist,pord;
      pord := for each vb in rlcadvbl rlpnf phi join vb;
      plist := rlcadproj(phi,pord);
      return rlcadnum(plist,pord)
   end;

% MK: This is a service.
algebraic procedure rlcadnumepo(phi);
   % Number of projection polynomials for full CAD with efficient
   % projection order.
   begin scalar plist,pord;
      pord := rlcadporder phi;
      plist := rlcadproj(phi,pord);
      return rlcadnum(plist,pord)
   end;

% MK: This is a service.
algebraic procedure rlcaddefaultorder(phi);
   for each vb in rlcadvbl rlpnf phi join vb;

% MK: This is a service.
algebraic procedure rlcadnum(pl,pord);
   first rlcadnum1(pl,pord);

% MK: This is a service.
algebraic procedure rlcadguessauto(phi);
   begin scalar plist,pord;
      pord := for each vb in rlcadvbl rlpnf phi join vb;
      plist := rlcadproj(phi,pord);
      return rlcadguess(plist,pord)
   end;

% MK: This is a service.
algebraic procedure rlcadguessepo(phi);
   begin scalar plist,pord;
      pord := rlcadporder phi;
      plist := rlcadproj(phi,pord);
      return rlcadguess(plist,pord)
   end;

% MK: This is a service.
algebraic procedure rlcadguess(pl, pord);
   for each n in rlcadguess1(pl, pord) product n;

symbolic operator rlcadnum1;
procedure rlcadnum1(pl, pord);
   % . [pl] is a list (Fr,...,F1) of projection factors, [pord] is a list
   % (xr,...,x1) of variables. Returns a list (#Dr,...,#D1) of numbers.
   begin scalar oldorder,w,ff,varl;
      oldorder := setkorder pord;
      w := for each ffj in cdr pl collect
 	 for each f in cdr ffj collect reorder numr simp f;
      ff := reverse w;
      varl := reverse cdr pord;
      w := reversip ofsf_cadnum1(ff,varl,nil); % (#Dr,...,#D1)
      setkorder oldorder;
      return 'list . w;
   end;

symbolic operator rlcadpnum;
procedure rlcadpnum(phi, pord);
   ofsf_cadpnum(rl_simp phi, cdr pord);

symbolic operator rlcadguess1;
procedure rlcadguess1(pl,pord);
   % . [pl] is a list (Fr,...,F1) of projection factors, [pord] is a
   % list (xr,...,x1) of variables. Returns a list (#Dr,...,#D1) of numbers.
   begin scalar oldorder,w,ff,varl,!*rlacdguessnoc;
      oldorder := setkorder pord;
      w := for each ffj in cdr pl collect
 	 for each f in cdr ffj collect reorder numr simp f;
      ff := reverse w;
      varl := reverse cdr pord;
      %on1 !*rlcadguessnoc;
      w := ofsf_cadnum1(ff,varl,t);
      %off1 !*rlcadguessnoc;
      w := reversip w; % (#Dr,...,#D1)
      setkorder oldorder;
      return 'list . w;
   end;

procedure ofsf_cadnum1(ff,varl,probe);
   % Cad num subroutine. [ff] is a list (F1,...,Fr) of lists of
   % polynomials. Returns a list of natural numbers of length r+1.
   begin scalar w;
      w := ofsf_fulltree(
	 list2vector(nil . for each ffj in ff collect
	    for each f in ffj collect tag_(f,{'dummytag})),
	 varl,probe);
%	 list2vector(nil . ff),varl,probe);
      return for i := 0 : length varl collect length atree_levellabels(w,i)
   end;

asserted procedure ofsf_fulltree(ff: Atom, varl: List, probe: Boolean): Atree;
   % [ff] is a vector [nil, F_1, ..., F_r], where the elements are
   % LIST(TAG(SF)).
   begin scalar basecell;
      % This is the only cell of D0:
      basecell := acell_mk(0, nil, nil, 'true, nil);
      return ofsf_fulltreeovercell(basecell, ff, varl, 'unknown, 'unknown, probe)
   end;

asserted procedure ofsf_fulltreeovercell(basecell: Acell, ff: Atom, varl: List, qal: List, psi: Formula, probe: Boolean): Atree;
   % Cad full tree over cell. [basecell] is a cell in D_{j-1}, [ff] is a vector
   % [nil, F_1,...,F_r], where the elements are LIST(TAG(SF)), [varl] is (x_1,
   % ..., x_r), [qal] and [psi] are not needed. Returns a tree over the
   % basecell. Intuition: Finds for a cell C in D_j a full cad tree that has C
   % as a root. Each cell has a sample point, but no truth value.
   begin scalar r,k,j,fffj,xj,sp,cell,treel,nrdata,ncbuffer;
      integer n;
      if ofsf_cadverbosep() then
	 ioto_prin2 {"(", length acell_getsp basecell};
      % ioto_tprin2t {"tree over: ", basecell};
      r := length varl;
      k := r;  % not needed, nextcell would need it for fulldimonly and gen1
      j := length acell_getsp basecell + 1;
      sp := acell_getsp basecell;
      % 1. BASE CASE: j=r, evaluation case. The base cell is a leaf.
      if j > r then <<
	 if ofsf_cadverbosep() then
	    ioto_prin2 ")";
      	 return atree_new basecell
      >>;
      % Prepare Polynomials
      xj := nth(varl, j);
      fffj := ofsf_tocprepare(list2vector getv(ff, j), xj, sp, varl);
      % ffj := for each te in ffj collect tag_object te;
      % ffj := ofsf_tocprepare(ff,xj,sp,varl);
      nrdata := tiri_init(fffj, xj);
      % Old code:
      % nrdata := rip_init(fffj,xj); % initialize next root data
      % rip_putpscl(nrdata,for each psc in rip_pscl nrdata join
      % 	 if (d := aex_stchsgnch(cdr psc,xj,'minfty) -
      % 	    aex_stchsgnch(cdr psc,xj,'infty)) neq 0 then <<n := n+d;{psc}>>);
      if ofsf_cadverbosep() then
	 ioto_prin2 {":", 2*n+1};
      ncbuffer := ofsf_ncinit();
      % 2. RECURSION CASE: j<=r
      if 0 <= j and j <= r then  % full dec., no truth values
	 if probe then <<
	    cell := ofsf_nextcell(ncbuffer, sp, nrdata, xj, j, k);
	    treel := ofsf_fulltreeovercell(cell, ff, varl, qal, psi, probe) . treel;
	    for i := 1 : (2*n+1)-1 do
	       treel := atree_new basecell . treel;
	 >> else
	    while cell := ofsf_nextcell(ncbuffer,sp,nrdata,xj,j,k) do
	       treel := ofsf_fulltreeovercell(cell, ff, varl, qal, psi, probe) . treel;
      % construct result tree
      return atree_addchildlistip(atree_new basecell, treel);
   end;

asserted procedure ofsf_tocprepare(hhj: Atom, xj: Kernel, sp: AnuList, varl: List): List;
   % Tree over cell prepare polynomials. [hhj] is a Vector of tagged SF, [xj] is
   % a variable. Returns a List of tagged Aex.
   begin scalar w;
      w := vector2list hhj;
      if null sp then <<
	 if ofsf_cadverbosep() then
	    ioto_prin2 "(base case)";
	 return for each te in w collect
	    tag_(aex_fromsf tag_object te, tag_taglist te)
      >>;
      % Convert SF to Aex and substitute the sample point [sp].
      w := for each tsf in w collect
	 tag_(ofsf_subsp(aex_fromsf tag_object tsf, sp, varl), tag_taglist tsf);
      % Make elements of [hhj] smaller and throw away [null] and constant
      % polynomials.
      w := for each tae in w collect
	 tag_(aex_mklcnt aex_reduce tag_object tae, tag_taglist tae);
      w := for each tae in w join
	 if not aex_simplenumberp tag_object tae then
	    {tag_(aex_reduce aex_sqfree(tag_object tae, xj), tag_taglist tae)};
      w := tglist2set w;
      % if !*rlcaddebug then
      %    for each f in hhj do
      %       if aex_sgn aex_lc(f, xj) eq 0 then
      %      	  prin2t "ofsf_tocprepare: smaller but lc trivial";
      % if !*rlcaddebug then
      %    for each f in hhj do
      %       if aex_simplenumberp f then
      %       	  prin2t "ofsf_tocprepare: smaller but number";
      % Make the elements of [hhj] pairwise prime.
      w := aex_tgpairwiseprime(w, xj);
      % if !*rlcaddebug then
      %    for each f in hhj do
      %       if aex_sgn aex_lc(f,xj) eq 0 then
      %       	  prin2t "ofsf_tocprepare: pairwiseprime but lc trivial";
      % if !*rlcaddebug then
      %    for each f in hhj do
      %       if aex_simplenumberp f then
      %       	  prin2t "ofsf_tocprepare: pairwiseprime but number";
      return w
   end;

% The following two procedures work with tagged Aex. They were moved here from
% the ofsfanuex module. TODO: Understand the tags.

%asserted procedure aex_tgpairwiseprime(ael: AexList, x: Kernel): AexList;
procedure aex_tgpairwiseprime(ael, x);
   % Pairwise prime. [ael] is a list of Aex with non-trivial lcs. Returns a list
   % of Aex with non-trivial lcs.
   begin scalar pprestlist, tmp;
      if null ael or null cdr ael then
	 return ael;
      pprestlist := aex_tgpairwiseprime(cdr ael, x);
      tmp := aex_tgpairwiseprime1(car ael . pprestlist, x);
      if aex_simplenumberp tag_object car tmp then
	 return cdr tmp;
      return tmp
   end;

%asserted procedure aex_tgpairwiseprime1(ael: AexList, x: Kernel): AexList;
procedure aex_tgpairwiseprime1(ael, x);
   % Pairwise prime. Makes [car ael] pairwise prime with all elements of [cdr
   % ael].
   begin scalar ae1, ae2, aelnew, g; integer deg;
      ae1 := pop ael;
      while ael and not aex_simplenumberp tag_object ae1 do <<
	 ae2 := pop ael;
	 g := aex_gcd(tag_object ae1, tag_object ae2, x);
	 deg := aex_deg(g, x);
      	 ae1 := tag_(aex_quot(tag_object ae1, g, x), tag_taglist ae1);
	 if deg > 0 then
	    ae2 := tag_(tag_object ae2, union(tag_taglist ae1, tag_taglist ae2));
 	 aelnew := ae2 . aelnew
      >>;
      return ae1 . aelnew
   end;

% Tagged root isolation. The following four functions use the incremental root
% isolation submodule in ofsfanuex. The reason for their existence is the fact
% that the polynomials here are tagged whereas the polynomials in ofsfanuex do
% not have any tags.

procedure tiri_init(tael, x);
   begin scalar ael, tal;
      ael := for each tae in tael collect
	 tag_object tae;
      tal := for each tae in tael collect
	 tag_object tae . tag_taglist tae;
      return tal . iri_init(ael, x)
   end;

procedure tiri_nextroot(tri);
   begin scalar w, tag;
      w := iri_nextroot cdr tri;
      if null w then
	 return nil;
      tag := atsoc(car w, car tri);
      return tag_(cdr w, cdr tag)
   end;

procedure tiri_rootl(tri);
   iri_rootl cdr tri;

procedure tiri_rootlnotags(tri);
   iri_rootl cdr tri;

% CadData

asserted procedure caddata_mkblank(): CadData;
   % Blank caddata. Undefined entries have the value ['undefined].
   begin scalar cd;
      cd := mkvect(18);
      putv(cd,0, 'caddata);
      putv(cd,1, 'undefined); % [phi] is a prenex ofsf formula for which a CAD is to be constructed.
      putv(cd,2, 'undefined); % [k] is an integer; the number of free variables in [phi].
      putv(cd,3, 'undefined); % [r] is an integer; the number of all variables in [phi].
      putv(cd,4, 'undefined); % [varl] is a list kernels; all variables in [phi].
      putv(cd,5, 'undefined); % [qal] is a list of dotted pairs [(x . Q)], where [x] is a variable and [Q] is a quantifier; quantifier prefix of [phi].
      putv(cd,6, 'undefined); % [psi] is a quantifier-free ofsf formula; matrix of [phi].
      putv(cd,7, 'undefined); % [ff] is a vector of lists of SF; projection polynomials.
      putv(cd,8, 'undefined); % [dd] is an Atree.
      putv(cd,9, 'undefined); % [phiprime] is a quantifier-free ofsf formula; the result equivalent to [phi].
      putv(cd,10,'undefined); % [oldorder] is a list of kernels; the old kernel ordering.
      putv(cd,11,'undefined); % [ophi] is an ofsf formula; the original input formula using [oldorder].
      putv(cd,12,'undefined); % [J] is unused.
      putv(cd,13,'undefined); % [theo] is a list of negated atoms.
      putv(cd,14,'undefined); % [hh] is a vector of vectors of tagged SF.
      putv(cd,15,'undefined); % [l] is an integer; the number of free variables plus the number of variables in the outermost quantifier block of [phi]; if there is no quantifier, [l] is zero
      % putv(cd,16,ffid);     % [Fid] is a vector of lists of ids.
      putv(cd,16,'undefined);
      putv(cd,17,'undefined); % [A] is list of SF.
      putv(cd,18,'undefined); % [A+] is list of SF.
      return cd
   end;

% access functions

procedure caddata_phi(cd);      getv(cd,1);
procedure caddata_k(cd);        getv(cd,2);
procedure caddata_r(cd);        getv(cd,3);
procedure caddata_varl(cd);     getv(cd,4);
 procedure caddata_xj(cd,j);     nth(getv(cd,4),j);
procedure caddata_qal(cd);      getv(cd,5);
procedure caddata_psi(cd);      getv(cd,6);
procedure caddata_ff(cd);       getv(cd,7);
procedure caddata_ffl(cd);      cdr vector2list getv(cd,7);  % [caddata_ff cd] as list.
procedure caddata_ffj(cd,j);    getv(getv(cd,7),j);
procedure caddata_dd(cd);       getv(cd,8);
procedure caddata_phiprime(cd); getv(cd,9);
procedure caddata_oldorder(cd); getv(cd,10);
procedure caddata_ophi(cd);     getv(cd,11);
 procedure caddata_jj(cd);       getv(cd,12);
procedure caddata_theo(cd);     getv(cd,13);
procedure caddata_hh(cd);       getv(cd,14);
procedure caddata_hhj(cd,j);      getv(getv(cd,14),j);
procedure caddata_l(cd);        getv(cd,15);
procedure caddata_ffid(cd);     getv(cd,16);
 procedure caddata_aa(cd);	getv(cd,17);
 procedure caddata_aaplus(cd);	getv(cd,18);

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
procedure caddata_putjj(cd,jj);             putv(cd,12,jj);
procedure caddata_puttheo(cd,theo);         putv(cd,13,theo);
procedure caddata_puthh(cd,hh);             putv(cd,14,hh);
procedure caddata_putl(cd,l);               putv(cd,15,l);
procedure caddata_putffid(cd,ffid);         putv(cd,16,ffid);
procedure caddata_putaa(cd,a);	            putv(cd,17,a);
procedure caddata_putaaplus(cd,a);	    putv(cd,18,a);

asserted procedure caddata_print(cd: CadData): Any;
   begin
      ioto_prin2t "+ begin caddata";
      if !*rlcadverbose then
	 caddata_printall cd
      else
	 caddata_printsome cd;
      ioto_prin2t "+ end caddata"
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
      % if caddata_jj cd neq 'undefined then
	 ioto_prin2t{"jj := ", caddata_jj cd};
      % if caddata_theo cd neq 'undefined then
	 ioto_prin2t{"theo := ", caddata_theo cd};
      % if caddata_hh cd neq 'undefined then
	 ioto_prin2t{"hh := ", caddata_hh cd};
      % if caddata_l cd neq 'undefined then
	 ioto_prin2t{"l := ", caddata_l cd};
      % if caddata_ffid cd neq 'undefined then
	 ioto_prin2t{"ffid := ", caddata_ffid cd};
      % if caddata_aa cd neq 'undefined then
	 ioto_prin2t{"aa := ", caddata_aa cd};
      % if caddata_aaplus cd neq 'undefined then
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
      ofsf_cadswitchprint !*rlcadaproj; ioto_prin2 "rlcadaproj;";
      ofsf_cadswitchprint !*rlcadaprojalways; ioto_prin2 "rlcadaprojalways;";
      ofsf_cadswitchprint !*rlcadhongproj; ioto_prin2 "rlcadhongproj;";
      ofsf_cadswitchprint !*rlcadfac; ioto_prin2 "rlcadfac;";
      % ioto_tprin2 "+ extension phase switches";
      ofsf_cadswitchprint !*rlcadpartial; ioto_prin2 "rlcadpartial;";
      ofsf_cadswitchprint !*rlcadte; ioto_prin2 "rlcadte;";
      ofsf_cadswitchprint !*rlcadpbfvs; ioto_prin2 "rlcadpbfvs;";
      ofsf_cadswitchprint !*rlcadisoallroots; ioto_prin2 "rlcadisoallroots;";
      ofsf_cadswitchprint !*rlcadtrimtree; ioto_prin2 "rlcadtrimtree;";
      ofsf_cadswitchprint !*rlcadfasteval; ioto_prin2 "rlcadfasteval;";
      ofsf_cadswitchprint !*rlcadfulldimonly; ioto_prin2 "rlcadfulldimonly;";
      ofsf_cadswitchprint !*rlcadrmwc; ioto_prin2 "rlcadrmwc;";
      % ioto_tprin2 "+ solution formula construction phase switches:";
      ofsf_cadswitchprint !*rlcadrawformula; ioto_prin2 "rlcadrawformula;";
      ofsf_cadswitchprint !*rlcaddnfformula; ioto_prin2 "rlcaddnfformula;";
      % ioto_tprin2 "+ general switches:";
      ofsf_cadswitchprint !*rlcadpreponly; ioto_prin2 "rlcadpreponly;";
      ofsf_cadswitchprint !*rlcadprojonly; ioto_prin2 "rlcadprojonly;";
      ofsf_cadswitchprint !*rlcadbaseonly; ioto_prin2 "rlcadbaseonly;";
      ofsf_cadswitchprint !*rlcadextonly;  ioto_prin2 "rlcadextonly;";
      ioto_tprin2 "+ end CAD relevant switches"
   >>;

asserted procedure ofsf_cadswitchprint(b: Boolean): Any;
   % Print a single switch.
   if b then ioto_tprin2 "on " else ioto_tprin2 "off ";

% root isolation

% TODO: (?) Define a data structure for nrdata (next root data).

% This is kept only because of the ofsf_fulltreeovercell procedure.
asserted procedure ofsf_ncinit(): List;
   {nil};

% New Cell Buffer

asserted procedure ncb_init(): List;
   % New cell buffer init. NcBuffer holds exactly one element. The lement is
   % either [nil] or an Acell.
   {nil};

asserted procedure ncb_get(ncb: List): List;
   % New cell buffer get. Return the single element and reset it to [nil].
   begin scalar w;
      w := car ncb;
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

asserted procedure ofsf_nextcell(ncbuffer: List, sp: AnuList, nrdata: Any, xj: Kernel, j: Integer, k: Integer): ExtraBoolean;
   % Returns a cell. Caveat: [j eq length sp + 1], i.e., [j] is the level of the
   % newly generated cells.
   begin scalar cell, tgroot, root, w;
      integer cind;
      cell := ncb_get ncbuffer;
      if cell eq 'finished then
	 return nil;
      if cell then <<
	 if not ((!*rlcadfulldimonly and j > k) or (!*rlqegen1 and j <= min2(1, k))) then
	    return cell;
      	 if !*rlverbose then <<
	    if !*rlqegen1 and j <= min2(1, k) then
	       ioto_prin2 {"(", j, "!gen)"};
	    if !*rlcadfulldimonly and j > k then
	       ioto_prin2 {"(", j, "!fdo)"}
	 >>
      >>;
      % There is no cell left, we need to get a root to get the next two cells.
      tgroot := tiri_nextroot nrdata;
      cind := 2*(length tiri_rootl nrdata);
      if tgroot then <<
	 root := tag_object tgroot;
	 ncb_put(acell_mk(cind - 1, root . sp, nil, nil, tag_taglist tgroot), ncbuffer);  % Store the 0-dim cell into the [ncbuffer].
	 w := iv_lb anu_iv root;
	 return acell_mk(cind - 2, anu_fromrat(xj, w) . sp, nil, nil, nil)  % Return the full-dim cell with a rational sample point.
      >>;
      % There is no cell and no root left.
      ncb_put('finished, ncbuffer);
      if null tiri_rootl nrdata then  % If there was no root, make a cell with 0 as the sample point.
	 return acell_mk(0, anu_fromrat(xj, rat_0()) . sp, nil, nil, {{'arbitrary}});
      % Search rootlist for the maximum of all right bounds and make a cell.
      w := rat_mapmax for each r in tiri_rootl nrdata collect iv_rb anu_iv r;
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

% Atree

% TODO: Is childlist a list of Atrees?

%DS
% <ATREE> ::= 'atree . <rootlabel> . <childlist>

asserted procedure atree_new(a: Acell): Atree;
   % New tree. The new tree is rooted at Acell [a].
   'atree . a . nil;

asserted procedure atree_rootlabel(tt: Atree): Any;
   cadr tt;

asserted procedure atree_sortfn(t1: Atree, t2: Atree): Any;
   % Sort function. [t1], [t2] are trees of Acells.
   acell_sortfn(atree_rootlabel t1, atree_rootlabel t2);

% asserted procedure atree_addchildip(tt: Atree, c: Atree): Atree;
%    <<
%       cddr tt := c . cddr tt;
%       tt
%    >>;

asserted procedure atree_addchildlistip(tt: Atree, cl: List): Atree;
   <<
      cddr tt := nconc(cl, cddr tt);
      tt
   >>;

asserted procedure atree_childlist(tt: Atree): List;
   cddr tt;

asserted procedure atree_firstchild(tt: Atree): Any;
   if atree_childlist tt then car atree_childlist tt;

asserted procedure atree_levellabels(tt: Atree, n: Integer): List;
   if eqn(n, 0) then
      {atree_rootlabel tt}
   else
      for each child in atree_childlist tt join
      	 atree_levellabels(child, n-1);

asserted procedure atree_yield(tt: Atree): List;
   % Truth value yield labels. [tt] is a tree. Returns a list of ACELL.
   if null atree_childlist tt then
      {atree_rootlabel tt}
   else
      for each child in atree_childlist tt join
	 atree_yield child;

asserted procedure atree_tvyield(tt: Atree): List;
   % Truth value yield labels. [tt] is a tree. Returns a list of ACELL.
   if acell_gettv atree_rootlabel tt neq nil then  % undef. tv: nil
      {atree_rootlabel tt}
   else
      for each child in atree_childlist tt join
	 atree_tvyield child;

asserted procedure atree_print(tt: Atree): Any;
   for each e in atree_print1(tt, 0) do
      ioto_tprin2t e;

asserted procedure atree_print1(tt: Atree, d: Integer): List;
   % atree_print(dd);
   % l2sfn is a function which converts a label to a string. returns a
   % list of strings. returns a list of list of strings.
   begin scalar childl, rootlabel, w;
      childl := atree_childlist tt;
      rootlabel := atree_rootlabel tt;
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
      childl := atree_childlist tt;
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
   if null atree_childlist tt then
      ioto_prin2 {"(", d, ")"}
   else <<
      ioto_prin2 {"(", d};
      for each c in atree_childlist tt do
	 atree_printlin(c, d+1);
      ioto_prin2 ")"
   >>;

% Atree to DOT

asserted procedure atree_2dot(tt: Atree): Any;
   % Output tree in dot format.
   begin
      out("cadtree.dot");
      ioto_prin2t("digraph cadtree {");
      atree_2dot1(tt,nil);
      ioto_prin2t("}");
      shut("cadtree.dot")
   end;

asserted procedure atree_2dot1(tt: Atree, idx: Any): Any;
   begin scalar childlist, idxl, w; integer i, n;
      % Print basecell:
      atree_2dotprinnode idx;
      atree_2dotnodetail atree_rootlabel tt;
      i := 1;
      childlist := atree_childlist tt;
      n := length childlist;
      while i <= n do <<
	 idxl := append(idx, {i});
	 atree_2dotprinnode idx;
	 prin2 "->";
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
      prin2 "C";
      for each e in idxl do
	 prin2 e
   >>;

asserted procedure atree_2dotnodetail(c: Acell): Any;
   % Print node detail.
   if acell_gettv c eq 'true then
      ioto_prin2t(" [label=T shape=circle style=filled color=green]")
   else if acell_gettv c eq 'false then
      ioto_prin2t(" [label=F shape=circle style=filled color=red]")
   else
      ioto_prin2t(" [label=""-"" shape=circle style=filled color=grey]");

% Atree to TGF (Trivial Graph Format)

asserted procedure atree_2tgf(tt: Atree, filename: String): Any;
   % Atree to tgf. Outputs the atree [tt] to file [filename] in tgf (Trivial
   % Graph Format) syntax.
   begin
      out(filename);
      atree_2tgf_nodes(tt, 1);
      ioto_prin2t("#");
      atree_2tgf_edges(tt, 1);
      shut(filename)
   end;

asserted procedure atree_2tgf_nodes(tt: Atree, number: Integer): Integer;
   begin scalar childlist;
      prin2 number;
      acell_prin atree_rootlabel tt;
      childlist := atree_childlist tt;
      for each child in childlist do
	 number := atree_2tgf_nodes(child, number + 1);
      return number
   end;

asserted procedure atree_2tgf_edges(tt: Atree, number: Integer): Integer;
   begin scalar childlist, mynumber;
      mynumber := number;
      childlist := atree_childlist tt;
      for each child in childlist do <<
	 prin2 mynumber;
	 prin2 " ";
	 prin2 (number + 1);
	 terpri();
	 number := atree_2tgf_edges(child, number + 1)
      >>;
      return number
   end;

asserted procedure acell_prin(c: Acell): Any;
   begin scalar tv, temp;
      prin2 " """;
      prin2 "idx: ";
      prin2 acell_getidx c;
      prin2 ", tv: ";
      tv := acell_gettv c;
      temp := if tv eq 'true then "T" else if tv eq 'false then "F" else "?";
      prin2 temp;
      prin2 ", desc: ";
      prin2 acell_getdesc c;
      prin2 ", tl: ";
      prin2 acell_gettl c;
      prin2 """";
      terpri()
   end;

% Atree to GML (Graph Modelling Language)

asserted procedure atree_2gml(tt: Atree, filename: String): Any;
   % Atree to gml. Outputs the Atree [tt] to file [filename] in gml (Graph
   % Modelling Language) syntax.
   begin
      out(filename);
      ioto_prin2t("Creator ""REDLOG""");
      ioto_prin2t("graph [");
      ioto_prin2t("label ""Graph generated by REDLOG.""");
      ioto_prin2t("directed 1");
      atree_2gml_nodes(tt, 1);
      atree_2gml_edges(tt, 1);
      ioto_prin2t("]");
      shut(filename)
   end;

asserted procedure atree_2gml_nodes(tt: Atree, number: Integer): Integer;
   begin scalar childlist;
      atree_2gml_node(tt, number);
      childlist := atree_childlist tt;
      for each child in childlist do
	 number := atree_2gml_nodes(child, number + 1);
      return number
   end;

asserted procedure atree_2gml_node(tt: Atree, number: Integer): Any;
   begin scalar c, tv, anul, n, color;
      ioto_prin2t "node [";
      ioto_prin2t {"id ", number};
      c := atree_rootlabel tt;
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
      ioto_prin2t "graphics [";
      ioto_prin2t {"fill """, color, """"};
      ioto_prin2t "]";
      ioto_prin2t "]"
   end;

asserted procedure atree_2gml_edges(tt: Atree, number: Integer): Integer;
   begin scalar childlist, mynumber;
      mynumber := number;
      childlist := atree_childlist tt;
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

% CAD extension

% Andreas' CAD extension phase. Includes additional explicit base phase code,
% which is used for efficiency (factorization is possible). Extension code is
% also correct for the special case of the base phase.

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
	 caddata_putphiprime(cd, acell_gettv atree_rootlabel dd);
	 return nil
      >>;
      ddk := atree_levellabels(dd, k);
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

asserted procedure ofsf_solutionformula(cd: CadData): Any;
   % Solution formula construction. The argument is changed in place.
   begin scalar ffl, dd, k, yy, yyi, ffk, phiprime, cellstogo;
      if !*rlverbose then
	 ioto_tprin2t "+++ Solution Formula Construction Phase";
      ffl := caddata_ffl cd;
      dd := caddata_dd cd;
      k := caddata_k cd;
      if memq(acell_gettv atree_rootlabel dd, {'true, 'false}) then <<
	 if ofsf_cadverbosep() and !*rlcadans then
	    ioto_prin2t {"ANSWERS for decision problem: ",
	       cdr atsoc('answers,acell_gettl atree_rootlabel dd)};
	 caddata_putphiprime(cd, acell_gettv atree_rootlabel dd);
	 return nil
      >>;
      % dk := atree_levellabels(dd, k);
      yy := atree_tvyield dd;
      % some verbose output for qe with answers
      if ofsf_cadverbosep() and !*rlcadans then <<
         ioto_prin2t "+++ ANSWERS: ";
	 ioto_prin2t {"yy: ", yy};
	 % for each cell in yy do
	 %    if acell_gettv cell eq 'true then
	 %       ioto_prin2t {"ANSWERS: ", atsoc('answers, acell_gettl cell)};
     	 for each c in list2set (for each cell in yy join
	    if acell_gettv cell eq 'true then
	       {atsoc('answers,acell_gettl cell)}) do
		  ioto_prin2t {"ANSWERS: ", c}
      >>;
      % ffk: projection polynomials
      yyi := list2set for each cell in yy collect
	 length acell_getsp cell;
      if !*rlverbose then
	 ioto_prin2t {"+ Levels to be considered: ", yyi};
      ffk := for each i in yyi join append(nth(ffl, i), nil);
      phiprime := ofsf_solutionformula1(dd, ffl, ffk, yy, yyi, k);
      if phiprime eq 'ssfcfailed then <<
	 if !*rlverbose then
	    ioto_tprin2t "++ SSFC failed, trying all possible projection factors.";
	 yyi := for i := 1 : k collect i;
	 if !*rlverbose then
	    ioto_prin2t {"+ Levels to be considered: ", yyi};
	 ffk := for each i in yyi join
	    append(nth(ffl, i), nil);
	 phiprime := ofsf_solutionformula1(dd, ffl, ffk, yy, yyi, k)
      >>;
      if phiprime eq 'ssfcfailed then <<
	 if !*rlverbose then
	    ioto_tprin2t "++ Simple solution formula construction failed.";
	 return nil
      >> else <<
	 if !*rlverbose then
	    ioto_tprin2t "++ Simple solution formula construction successful.";
	 if !*rlcadrawformula then
	    caddata_putphiprime(cd, phiprime)
	 else
	    caddata_putphiprime(cd, rl_dnf phiprime)
      >>;
      return nil
   end;

asserted procedure ofsf_solutionformula1(dd, ff, ffk, yy, yyi, k): Any;
   begin scalar cellstogo;
      if !*rlverbose then
	 ioto_tprin2t {"+ generating signatures for ", length ffk,
	    " polynomials in ", length yy,
	    " cells; (Dk: ", length atree_levellabels(dd,k), " cells)"};
      cellstogo := length yy;  % for verbose output
      for each cell in yy do <<
	 acell_putdesc(cell, ofsf_signature4(ffk, acell_getsp cell));
	 if ofsf_cadverbosep() then
	    ioto_prin2 {"[",cellstogo,
	       %"idx",acell_getidx cell," ",%
	       "sig",acell_getdesc cell, " ",
	       (if acell_gettv cell eq 'true then " tt" else " ff"),
	       % acell_getdesc cell,
	       "] "};
	 cellstogo := cellstogo - 1
      >>;
      return ofsf_ssfc2(ffk, yy)
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

asserted procedure ofsf_ssfc2(ffk, yy): Any;
   % Solution formula construction by Hong90. Signatures are already calculated.
   begin scalar wwt,wwf,wwc;
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
   % Compatible signatrues subroutine. [w1], [w2] are signatures of the same
   % length; both should be not empty except for recursive calls. Remark: This
   % is a fold, the first element of the disjunction is neutral wrt "or" for the
   % base case.
   (null w1 or null w2) or
      ((car w1 eq car w2 or car w1 equal "?" or car w2 equal "?") and
 	 ofsf_compsig1(cdr w1, cdr w2));

asserted procedure ofsf_sigbasedfo(ffk: List, sigl: List): Formula;
   % Signature based formula. [ffk] is a list of SF, [sig] is a signature
   % (can include "?"). returns a qf. FOF.
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
   % Signature. [fk] is a list of standard forms (in, say, variables x1,...,xk),
   % [sp] is sample point (a list (ak,...,a1) of algebraic numbers. Returns a
   % list (sigma1,...,sigmak) of elements of {-1,0,1}.
   for each f in fk collect
      aex_sgn ofsf_subsp!*(aex_fromsf f, sp);

asserted procedure ofsf_signature4(fk: List, sp: AnuList): List;
   % signature. [fk] is a list of standard forms (in, say, variables x1,...,xk),
   % [sp] is sample point (a list (al,...,a1) of algebraic numbers with l <= k).
   % Returns a list (sigma1,...,sigmak) of elements of {-1,0,1}.
   for each f in fk collect
      ofsf_sgnf4(f, sp);

asserted procedure ofsf_signaturesbytv(ddk: List, tv): List;
   % Signatures by truth value. [ddk] is a list of cells.
   for each c in ddk join
      if acell_gettv c eq tv then {acell_getdesc c};

endmodule;   % ofsfcad

end;  % of file
