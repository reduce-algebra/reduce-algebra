module ofsfic;  % Computation of infeasible cores

revision('ofsfic, "$Id$");

copyright('ofsfic, "(c) 2015 M. Jaroschek, 2017 M. Kosta, T. Sturm");

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

% WARNING: To compute infeasible cores one should go [on rlqeinfcore;]
% and carry out EXCLUSIVELY infeasible core computations. When the
% switch [rlqeinfcore] is turned on, then other parts of Redlog will
% exhibit strange behavior, errors, and/or compute incorrect results!

% REASON: This module uses a workaround mechanism of overwriting
% existing Redlog procedures when the switch [rlqeinfcore] is turned
% on/off. This behavior is a relic, which came into existence by
% modifying existing Redlog procedures directly, and identifying the
% needed functionality afterwards. Here we isolated the modified
% procedures, so we have a delicate co-existence of this module and
% the existing Redlog without modifying Redlog sources directly.

% When the switch [rlqeinfcore] is turned on, then procedures in this
% module (listed in [!*rlqeinfcore!-owal]) are used. When the switch
% is turned off, then existing Redlog procedures are used.

% TODO: For the above-described mechanism to work 100% smoothly we
% have to store and restore switches when manipulating with the
% rlqeinfcore switch!

switch rlqeinfcore;
% put('rlqeinfcore, 'simpfg, '((t . ((rlqeinfcore_on))) (nil . ((rlqeinfcore_off)))));
put('rlqeinfcore, 'simpfg, '((t . ((rlqeinfcore_switch))) (nil . ((rlqeinfcore_switch)))));


fluid '(!*rlqeinfcore!-owal);
fluid '(!*rlqeinfcore!-defal);

% existing Redlog procedures that have to be overwritten for this
% module to work:
!*rlqeinfcore!-owal :=
   '((ce_mk . ofsfic!*ce_mk)
     (co_push2 . ofsfic!*co_push2)
     (cl_mk1EQR . ofsfic!*cl_mk1EQR)
     (cl_qea . ofsfic!*cl_qea)
     (cl_qe1 . ofsfic!*cl_qe1)
     (cl_qeblock4 . ofsfic!*cl_qeblock4)
     (cl_qevar . ofsfic!*cl_qevar)
     (cl_process!-candvl . ofsfic!*cl_process!-candvl)
     (cl_esetsubst . ofsfic!*cl_esetsubst)
     (cl_qeatal1 . ofsfic!*cl_qeatal1)
     (cl_simpl . ofsfic!*cl_simpl)
     (ofsf_exploitKnowl . ofsfic!*ofsf_exploitKnowl)
     (ofsf_qemkans . ofsfic!*ofsf_qemkans)
     (ofsf_qebacksub . ofsfic!*ofsf_qebacksub)
     (ofsf_qenobacksub . ofsfic!*ofsf_qenobacksub)
    )$

procedure rlqeinfcore_storedefs();
   % Store current procedure definitions into [!*rlqeinfcore!-defal].
   for each pr in !*rlqeinfcore!-owal do <<
      push(car pr . getd car pr, !*rlqeinfcore!-defal);
      push(cdr pr . getd cdr pr, !*rlqeinfcore!-defal)
   >>;

% procedure rlqeinfcore_on();
%    % Overwrite procedures when [on rlqeinfcore;] is executed, i.e.,
%    % procedures of this module (with name prefix ofsfic!*) are used.
%    begin scalar tmp;
%       if null !*rlqeinfcore!-defal then
% 	 rlqeinfcore_storedefs();
%       for each pr in !*rlqeinfcore!-owal do <<
% 	 tmp := atsoc(cdr pr, !*rlqeinfcore!-defal);
% 	 if null tmp then
% 	    rederr {"Missing procedure definition ", cdr pr};
% 	 tmp := cdr tmp;
% 	 putd(car pr, car tmp, cdr tmp)
%       >>
%    end;

% procedure rlqeinfcore_off();
%    % Overwrite procedures when [off rlqeinfcore;] is executed, i.e.,
%    % original Redlog procedures are used.
%    begin scalar tmp;
%       if null !*rlqeinfcore!-defal then
% 	 rlqeinfcore_storedefs();
%       for each pr in !*rlqeinfcore!-owal do <<
% 	 tmp := atsoc(car pr, !*rlqeinfcore!-defal);
% 	 if null tmp then
% 	    rederr {"Missing procedure definition ", car pr};
% 	 tmp := cdr tmp;
% 	 putd(car pr, car tmp, cdr tmp)
%       >>
%    end;

procedure rlqeinfcore_switch();
   begin scalar s, tmp;
      if null !*rlqeinfcore!-defal then
	 rlqeinfcore_storedefs();
      for each pr in !*rlqeinfcore!-owal do <<
	 s := if !*rlqeinfcore then  % on -> off: Use original Redlog procedures.
	    car pr
	 else  % off -> on: Use procedures of this module (with name prefix ofsfic!*)
	    cdr pr;
	 tmp := atsoc(s, !*rlqeinfcore!-defal);
	 if null tmp then
	    rederr {"Missing procedure definition ", s};
	 tmp := cdr tmp;
	 putd(car pr, car tmp, cdr tmp)
      >>
   end;

% variables this module stores information into:
fluid '(!*rlqeicsimpl !*icinitsimpl);
fluid '(rlqeicdata!*);

% ContainerElement ::= ('ce, VarList, QfFormula, Kernel, SubstTriplet, Answer, Vector)

%%%%%%%MAX
%DS
% InfCoreData ::= [InfCore, FalseVect, EvTPList, MaxFalse, Coverage, CurrentFVect, GuardList, Knowl, EssentialVect, VarList, CADCellList]
% InfCore ::= (QFFormula, ...)
% FalseVect ::= [Integer, ...]
% EvTPList ::= (EvTP, ...)
% EvTP ::= [t | nil, ...]
% MaxFalse ::= Integer . Integer
% Coverage ::= Integer
% CurrentFVect ::= [QFFormula, ...]
% GuardList ::= (QFFormula, ...)
% Knowl ::= (IR, ...)
% EssentialVect ::= [t | nil, ...]
% VarList ::= KernelL
% CADCellList ::= (ACell, ...)

struct InfCoreData checked by vectorp;

asserted procedure ic_init(f: Formula): InfCoreData;
   % Infeasible Core Initialize. Create, initialize and return
   % infeasible core data from a fully existentially quantified
   % formula [f].
   begin scalar icdata, flist, k;
      icdata := mkvect 14;
      flist := ofsfic_ftol f;
      k := length flist - 1;
      putv(icdata, 1, lto_list2vector for i := 0 : k collect 0);
      putv(icdata, 4, 0);
      putv(icdata, 5, lto_list2vector flist);
      % putv(icdata, 6, mkvect k);
      putv(icdata, 8, mkvect k);
      putv(icdata, 12, lto_list2vector flist);
      return icdata
   end;

asserted procedure ic_infcore(icdata: InfCoreData): List;
   % Infeasible Core Data Infeasible Core. Contains a subset of the
   % elements in the formula vector which, at the end of the
   % computation, will be unsatisfiable.
   getv(icdata, 0);

asserted procedure ic_falsevect(icdata: InfCoreData): Vector;
   % Infeasible Core Data False Vector. The Vector contains the number
   % of test points that evaluate to false for each formula in the
   % formula vector.
   getv(icdata, 1);

asserted procedure ic_evtplist(icdata: InfCoreData): List;
   % Infeasible Core Evaluated Test Point List. Each test point
   % consists of a vector of truth values. The ith truth value is T if
   % the ith formula in the formula vector gives true when evaluated
   % at the test point represented by this list.
   getv(icdata, 2);

asserted procedure ic_maxfalseel(icdata: InfCoreData): Integer;
   % Infeasible Maximal False Element. Index of the formula in the
   % formula vector that gives false for the most test points that are
   % not yet covered by the current infeasible core.
   getv(icdata, 3);

asserted procedure ic_coverage(icdata: InfCoreData): Integer;
   % Infeasible Core Coverage. The number of test points that have yet
   % to be covered by the infeasible core.
   getv(icdata, 4);

asserted procedure ic_currentfvect(icdata: InfCoreData): Vector;
   % Infeasible Core Current Formula Vector. Each entry represents one
   % of the input constraints at the current virtual substitution step.
   getv(icdata, 5);

asserted procedure ic_guardList(icdata: InfCoreData): List;
   % Infeasible Core Guard List. An AList which associates guards with
   % the formulas from which they emerged.
   getv(icdata, 6);

asserted procedure ic_knowl(icdata: InfCoreData): List;
   % Infeasible Core Knowledge. Contains currently known bounds for
   % the simplification process.
   getv(icdata, 7);

asserted procedure ic_essentialvect(icdata: InfCoreData): Vector;
   % Infeasible Core Essential List. Contains indices of formulas in
   % the formula vector that are known to be a necessary part of the
   % infeasible core.
   getv(icdata, 8);

asserted procedure ic_varlist(icdata: InfCoreData): List;
   % Infeasible Core Variable List.
   getv(icdata, 9);

asserted procedure ic_cadcellList(icdata: InfCoreData): List;
   % Infeasible Core CAD Cell List. Contains all the leaves of the CAD
   % tree after a CAD call.
   getv(icdata, 10);

asserted procedure ic_taglist(icdata: InfCoreData): List;
   getv(icdata, 11);

asserted procedure ic_originalfvect(icdata: InfCoreData): List;
   getv(icdata, 12);

asserted procedure ic_offsetlist(icdata: InfCoreData): List;
   getv(icdata, 13);

asserted procedure ic_setinfcore(icdata: InfCoreData, l: List): List;
   % Infeasible Core Data Infeasible Core. Contains a subset of the
   % elements in the formula vector which, at the end of the
   % computation, will be unsatisfiable.
   putv(icdata, 0, l);

asserted procedure ic_appendinfcore(icdata: InfCoreData, k: Integer);
   putv(icdata, 0, k . getv(icdata, 0));

asserted procedure ic_appendevtplist(icdata: InfcoreData, vec: Vector): Any;
   putv(icdata, 2, vec . getv(icdata, 2));

asserted procedure ic_addcoverage(icdata: InfCoreData, k: Integer): Any;
   putv(icdata, 4, getv(icdata, 4) + k);

asserted procedure ic_setcurrentfvect(icdata: InfCoreData, v: Vector): Any;
   putv(icdata, 5, v);

asserted procedure ic_clearguardList(icdata: InfCoreData): List;
   % Infeasible Core Guard List. An AList which associates guards with
   % the formulas from which they emerged.
   putv(icdata, 6, nil);

asserted procedure ic_appendguardlist(icdata: InfcoreData, el: Any): Any;
   putv(icdata, 6, el . getv(icdata, 6));

asserted procedure ic_setknowl(icdata: InfCoreData, knowl: Any): List;
   putv(icdata, 7, knowl);

asserted procedure ic_setvarlist(icdata: InfCoreData, l: List): List;
   putv(icdata, 9, l);

asserted procedure ic_insertvarlist(icdata: InfCoreData, v: DottedPair): List;
   putv(icdata, 9, ofsfic_insertqcar(v, getv(icdata, 9)));

asserted procedure ic_resetcadcellList(icdata: InfCoreData): Any;
   putv(icdata, 10, nil);

asserted procedure ic_appendcadcellList(icdata: InfCoreData, cell: Any): List;
   % Infeasible Core CAD Cell List. Contains all the leafs of the CAD
   % tree after a CAD call.
   putv(icdata, 10, cell . getv(icdata, 10));

asserted procedure ic_settaglist(icdata: InfCoreData, l: List): List;
   putv(icdata, 11, l);

asserted procedure ic_appendtaglist(icdata: InfCoreData, p: Any): List;
   putv(icdata, 11, p . getv(icdata, 11));

asserted procedure ic_setoffsetlist(icdata: InfCoreData, l: List): Any;
   putv(icdata, 13, l);

asserted procedure ic_addtofalsevect(icdata: InfCoreData, k: Integer, j: Integer): Vector;
   putv(ic_falseVect icdata, k, getv(ic_falsevect icdata, k) + j);

asserted procedure ic_taglistremfalse(icdata: InfCoreData): List;
   begin scalar l;
      l := getv(icdata, 11);
      if caar l eq 'false then <<
      	 putv(icdata, 11, cdr l);
      	 return cdar l
      >>;
      return nil
   end;

%%%%%%%MAX
asserted procedure ic_computeinfcore(icdata: InfCoreData): Any;
   begin scalar essential, l;
      integer k, chosen;
      essential := ic_essentialvect icdata;
      for i := 0 : upbv essential do
	 if getv(essential, i) then <<
	    chosen := getv(ic_falsevect icdata, i);
	    ic_addcoverage(icdata, -chosen);
	    ic_appendinfcore(icdata, i);
 	    ic_updateevtplist(icdata, i);
	    ic_updatefalsevect icdata
	 >>;
      while ic_coverage icdata > 0 do <<
	 {chosen, k} := ic_maxfalse icdata;
	 ic_addcoverage(icdata, -chosen);
	 ic_appendinfcore(icdata, k);
	 ic_updateevtplist(icdata, k);
	 ic_updatefalsevect icdata
      >>;
      l := nil;
      if ic_offsetlist icdata then <<
      	 for each e in ic_infcore icdata do
      	    for each n in cadr assoc(e, ic_offsetlist icdata) do
 	       l := lto_insertq(n, l);
      	 ic_setinfcore(icdata, l)
      >>
   end;

asserted procedure ic_updateevtplist(icdata: InfCoreData, k: Integer): Any;
   begin scalar evtplist;
      for each tp in ic_evtplist rlqeicdata!* do
	 if not (getv(tp, k) eq 'false) then
	    evtplist := tp . evtplist;
      putv(icdata, 2, evtplist)
    end;

asserted procedure ic_updatefalsevect(icdata: InfCoreData): Any;
   begin
      putv(icdata, 1, lto_list2vector for i := 0 : upbv ic_falsevect icdata collect 0);
      for each tp in ic_evtplist icdata do
	 for i := 0 : upbv tp do
	    if getv(tp, i) eq 'false then
	       ic_addtofalsevect(icdata, i, 1)
   end;

asserted procedure ic_maxfalse(icdata: InfCoreData): List;
   begin scalar falsevect;
      integer chosen, k, current;
      falsevect := ic_falsevect icdata;
      for i := 0 : upbv falsevect do <<
	 current := getv(falsevect, i);
	 if current > chosen then <<
	    chosen := current;
	    k := i
	 >>
      >>;
      return {chosen, k}
   end;


%%%%%%%MAX
declare ofsfic!*ce_mk: (VarList, QfFormula, Kernel, List, Answer, List) -> ContainerElement;
inline procedure ofsfic!*ce_mk(vl, f, v, eterm, an, fvect);
   % Container element make.
   {'ce, vl, f, v, eterm, an, fvect};

%%%%%%%MAX
declare ce_fvect: (ContainerElement) -> Vector;
inline procedure ce_fvect(x);
   % Container element formula vector. Only used for infeasible core computation.
   nth(cdr x, 6);

%%%%%%%MAX
declare ofsfic!*co_push2: (Container, ContainerElement) -> Container;
inline procedure ofsfic!*co_push2(co, ce);
   %TODO: REENABLE %%%%%%%MAX
   % Insert 1 element into container.
   % if co_member(ce,co) then <<
   %    if !*rlverbose and !*rlqevb and !*rlqevbold then
   % 	 ioto_prin2 "@";
   %    co
   % >> else
   ce . co;

%%%%%%%MAX
declare ofsfic!*cl_mk1EQR: (Formula,EquationL) -> ExtendedQeResult;
inline procedure ofsfic!*cl_mk1EQR(f, eql);
   % Make singleton extended QE result.
   {{f, eql}};

asserted procedure ofsfic!*cl_qea(f: Formula, theo: Theory): ExtendedQeResult;
   % Quantifier elimination with answer. Returns a list of pairs $(..., (c_i,
   % A_i), ...)$. The $c_i$ are quantifier-free formulas, and the $A_i$ are
   % lists of equations. We have $[theo] \models \bigvee_i c_i
   % \longleftrightarrow [f]$. Whenever some $c_i$ holds for an interpretation
   % of the parameters, [f] holds, and $A_i$ describes a satisfying sample
   % point. Accesses the switch [rlqepnf]; if [rlqepnf] is on, then [f] has to
   % be prenex.
   begin scalar er,!*rlsipw,!*rlsipo,!*rlqeans,ic;
      !*rlsipw := !*rlsipo := !*rlqeans := t;
      % Initialize an infeasible core data structure.
      if !*rlqeinfcore then << %%%%%%%MAX
	 % ENTRY POINT
	 % TODO: Store previous switch settings and restore them
	 % afterwards.
	 !*rlqesr := t;
	 !*rlataltheo := nil;
	 !*rlqestdans := t;
	 !*rlcadtrimtree := nil;
	 !*rlqedyn := nil;
	 !*rlcadans := nil;
	 rlqeicdata!* := ic_init f
      >>;
      er := ofsfic!*cl_qe1(f,theo,nil);
      if rl_exceptionp er then
	 return er;
      % Infeasible core computation
      if !*rlqeinfcore then %%%%%%%MAX
	 if er = {nil} or caadr er eq 'false then <<
	    ic_computeinfcore rlqeicdata!*;
	    ic := ic_infcore rlqeicdata!*;
	    ioto_tprin2t {"infcore: ", ic_infcore rlqeicdata!*};
	    ioto_tprin2t {"infcore length: ", length ic_infcore rlqeicdata!*};
	    rlqeicdata!* := ic_init f;
	    ioto_tprin2t {"input length: ", upbv ic_currentfvect rlqeicdata!* + 1};
	    er := nil . '((false))
	    %
      	    % newF := nil;
	    % for each n in ic do
	    %    newF := getv(ic_currentfvect rlqeicdata!*, n) . newF;
	    % newF := rl_ex(rl_smkn('and, newF), nil);
	    % !*rlqeinfcore := nil;
	    % ioto_tprin2t {"test: ", ofsfic!*cl_qea(newF, nil)}
      	 >> else
	    ioto_tprin2t {"model: ",
	       for each pr in cdar cl_erEQR er collect {'equal, car pr, cdr pr}};
      return cl_erEQR er
   end;

asserted procedure ofsfic!*cl_qe1(f: Formula, theo: Theory, xbvl: KernelL): EliminationResult;
   % Quantifier elimination. [f] must be prenex if the switch [rlqepnf] is off;
   % [theo] serves as background theory.
   begin scalar q,ql,varll,bvl,svf,result,w,ww,k,rvl,jl,f2,offset,offset2;
      integer n;
      if !*rlqepnf then
	 f := rl_pnf f;
      f2:=f;
      if !*rlqeinfcore then << %%%%%%%MAX
	 !*rlqeicsimpl := t;
	 !*icinitsimpl := t;
	 f := {f};
	 f2 := {{}};
	 while not (car f2 = car f or car f eq 'false) do <<
	    f2 := f;
	    f := ofsfic!*cl_simpl(car f2, theo, -1);
	    if offset then <<
	       if not (car f2 = car f) and not (car f = 'false) then <<
		  if not (car f2 = car f or car f eq 'false) then <<
		     offset2 := ic_offsetlist rlqeicdata!*;
		     for each i in offset2 do <<
			w := cadr i;
			ww := nil;
			for each j in w do
			   for each k in cadr assoc(j, offset) do
 			      ww := k . ww;
			cadr i := ww
		     >>
		  >>;
		  offset := offset2
	       >>
	    >> else
	       offset := ic_offsetlist rlqeicdata!*;
	    ic_setoffsetlist(rlqeicdata!*, nil)
	 >>;
	 !*rlqeicsimpl := nil;
	 !*icinitsimpl := nil;
	 if car f eq 'false and cdr f then <<
	    rlqeicdata!* := ic_init car f2;
	    ofsfic_filterlocalcore(lto_list2vector ofsfic_ftol car f2, cadr f);
	    ic_setoffsetlist(rlqeicdata!*, offset);
	    f := car f
	 >> else <<
	    rlqeicdata!* := ic_init car f;
	    ic_setoffsetlist(rlqeicdata!*, offset);
	    f := car f;
	    if f eq 'false then
 	       putv(ic_essentialvect rlqeicdata!*, 0, t)
	 >>
      >> else
	 f:=rl_simpl(f,theo,-1);
      if f eq 'inctheo then
	 return rl_exception 'inctheo;
      if not rl_quap rl_op f then
	 return cl_mkER(theo,ofsfic!*cl_mk1EQR(f,nil));
      {ql,varll,f,bvl} := cl_split f;
      % Remove from the theory atomic formulas containing quantified variables:
      theo := for each atf in theo join
	 if null intersection(rl_varlat atf,bvl) then {atf};
      bvl := union(bvl,xbvl);
      {ql,varll,q,rvl,jl,theo,svf} := cl_qe1!-iterate(ql,varll,f,theo,bvl);
      jl := cl_qe1!-requantify(ql,varll,q,rvl,jl);
      if !*rlqeans and null ql then <<
	 if !*rlverbose then <<
	    ioto_tprin2 "+++ Postprocessing answer:";
	    n := length jl
	 >>;
	 result := for each j in jl join <<
	    if !*rlverbose then ioto_prin2 {" [",n:=n-1};
	    w := {cl_jF j . rl_qemkans(cl_jA j, svf)};
	    if !*rlverbose then ioto_prin2 {"]"};
	    w
	 >>;
      >> else <<
	 f := cl_jF car jl;
	 if !*rlverbose then
	    ioto_tprin2 {"+++ Final simplification ... ",cl_atnum f," -> "};
	 f := rl_simpl(f,theo,-1);
	 if !*rlverbose then
	    ioto_prin2t cl_atnum f;
	 if !*rlqefb and rvl then <<
	    if not rl_quap rl_op f then <<
	       if !*rlverbose then
		  ioto_tprin2t "++++ No more quantifiers after simplification";
	       result := f
	    >> else <<
	       if !*rlverbose then
		  ioto_tprin2 {"++++ Entering fallback QE: "};
	       theo . result := rl_fbqe(f, theo)
	    >>
	 >> else
	    result := f;
	 result := ofsfic!*cl_mk1EQR(result,nil);
      >>;
      return cl_mkER(theo,result)
   end;

asserted procedure ofsfic!*cl_qeblock4(f: QfFormula, varl: KernelL, theo: Theory, ans: Boolean, bvl: KernelL, dpth: Integer, vlv: Integer): List3;
   % Quantifier elimination for one block soubroutine. Arguments are as in
   % [cl_qeblock], where [q] has been dropped. Return value as well.
   begin scalar w,co,remvl,newj,cvl,coe,ww;
      integer c,count,delc,oldcol,comax,comaxn;
      if !*rlqegsd then
	 f := rl_gsd(f,theo);
      cvl := varl;
      co := co_new();
      if rl_op f eq 'or then
	 for each x in rl_argn f do
	    co := co_save(co,{ofsfic!*ce_mk(cvl,x,nil,nil,nil,ic_currentfvect rlqeicdata!*)})
      else if !*rlqeinfcore then %%%%%%%MAX
	 % If we compute an infeasible core, the list of input
	 % constraints is added to the container.
	 co := co_save(co, {ofsfic!*ce_mk(cvl, f, nil, nil, nil, ic_currentfvect rlqeicdata!*)})
      else
	 co := co_save(co, {ofsfic!*ce_mk(cvl, f, nil, nil, nil, nil)});
      while co_data co do <<
	 if !*rlverbose and !*rlqedfs and not !*rlqevbold then <<
	    ww := car co_stat co;
	    if comax = 0 or car ww < comax or
	       (car ww = comax and cdr ww < comaxn)
	    then <<
	       comax := car ww;
	       comaxn := cdr ww;
	       ioto_prin2 {"[",comax,":",comaxn,"] "}
	    >>
	 >>;
	 if !*rlqeidentify then on1 'rlidentify;
	 coe . co := co_get co;
	 % If we compute an infeasible core, then get the current
	 % formula vector from the container element.
	 if !*rlqeinfcore then %%%%%%%MAX
	    ic_setcurrentfvect(rlqeicdata!*, ce_fvect coe);
	 cvl := ce_vl coe;
	 count := count + 1;
	 if !*rlverbose then
	    if !*rlqedfs then
	       (if !*rlqevbold then <<
		  if vlv = length cvl then
		     ioto_tprin2t {"-- crossing: ",dpth - vlv};
		  ioto_prin2 {"[",dpth - length cvl}
	       >>)
	    else <<
	       if c=0 then <<
		  ioto_tprin2t {"-- left: ",length cvl};
		  c := co_length(co) + 1
	       >>;
	       ioto_nterpri(length explode c + 4);
	       ioto_prin2 {"[",c};
	       c := c - 1
	    >>;
	 w . theo := ofsfic!*cl_qevar(ce_f coe,ce_vl coe,ce_ans coe,theo,ans,bvl);
	 if car w then <<  % We have found a suitable variable.
	    w := cdr w;
	    if w then
	       if ce_vl car w eq 'break then <<
		  co := co_new();
		  newj := {cl_co2J car w}
	       >> else if cdr cvl then <<
		  if !*rlverbose then oldcol := co_length co;
		  co := co_save(co,w);
		  if !*rlverbose then
		     delc := delc + oldcol + length w - co_length(co)
	       >> else
		  for each x in w do newj := lto_insert(cl_co2J x,newj)
	 >> else <<
	    % There is no eliminable variable. Invalidate this entry, and save
	    % its variables for later requantification.
	    if !*rlqeinfcore then << %%%%%%%MAX
	       if ofsfic_process!-coe coe then <<  % [coe] is equivalent to ['true]
		  co := co_new();
		  newj := {'true . nil}
	       >>
	    >> else <<
	       if !*rlverbose then ioto_prin2 append("[Failed:" . cdr w,{"] "});
	       remvl := union(cvl,remvl);
	       newj := lto_insert(cl_co2J coe,newj);
	       if !*rlverbose and (not !*rlqedfs or !*rlqevbold) then <<
		  ioto_prin2 "] ";
		  if !*rlqedfs and null cvl then ioto_prin2 ". "
	       >>
	    >>
	 >>
      >>;
      if !*rlverbose then ioto_prin2{"[DEL:",delc,"/",count,"]"};
      if ans then return {remvl, newj, theo};
      % I am building the formula here rather than later because one might want
      % to do some incremental simplification at some point.
      return {remvl,
	 {cl_mkJ(rl_smkn('or,for each x in newj collect car x),nil)}, theo}
   end;

asserted procedure ofsfic_process!-coe(coe: ContainerElement): Boolean;
   % Returns [t] or [nil] depending on whether [coe] is equivalent to
   % ['true] or ['false].
   begin scalar fvect, cadinput, cd, cadres, rfvect, falseFound, celleval, sf, vl, vlsp, tmpres;
      fvect := ce_fvect coe;
      cadinput := rl_ex(rl_smkn('and, vector2list fvect), nil);
      cd := ofsf_cadpreparation(cadinput, ofsf_cadporder cadinput, nil);
      ofsf_cadprojection cd;
      ofsf_cadextension cd;
      % From now on we work in a (possibly) modified kord!*.
      cadres := acell_gettv atree_rootcell caddata_dd cd;
      assert(cadres memq '(true false));
      if cadres eq 'true then <<
	 ofsf_cadfinish cd;
	 return t
      >>;
      % [cadres] is ['false]
      % We make a reorder copy of [fvect].
      rfvect := mkvect upbv fvect;
      for i := 0 : upbv fvect do
	 putv(rfvect, i, ofsf_reorder getv(fvect, i));
      for each cell in atree_getleaves caddata_dd cd do <<
	 falseFound := nil;
	 celleval := mkvect upbv rfvect;
	 for i := 0 : upbv rfvect do <<
	    sf := getv(rfvect, i);
	    vl := cl_fvarl sf;
	    vlsp := for each anu in acell_getsp cell collect
	       aex_mvar anu_dp anu;
	    tmpres := 'true;
	    if lto_subsetq(vl, vlsp) then <<
	       for each v in lto_setminus(vlsp, vl) do
		  sf := rl_smkn('and, {sf, ofsf_0mk2('geq, addf(!*k2f v, 1))});
	       tmpres := ofsf_trialeval(sf, acell_getsp cell)
	    >>;
	    assert(tmpres memq '(true false));
	    putv(celleval, i, tmpres);
	    if tmpres eq 'false then <<
	       falseFound := t;
	       ic_addtofalsevect(rlqeicdata!*, i, 1)
	    >>
	 >>;
	 if falseFound then <<
	    ic_addcoverage(rlqeicdata!*, 1);
	    ic_appendevtplist(rlqeicdata!*, celleval)
	 >> else <<
	    !*rlqeicsimpl := t;
	    ofsfic_filterlocalcore(rfvect, cadr
	       rl_simpl(rl_smkn('and, vector2list celleval), nil, -1));
	    !*rlqeicsimpl := nil
	 >>
      >>;
      ofsf_cadfinish cd;
      return nil
   end;

asserted procedure ofsfic!*cl_qevar(f: QfFormula, vl: KernelL, an: Answer, theo: Theory, ans: Boolean, bvl: KernelL): DottedPair;
   % Quantifier eliminate one variable. [f] is a quantifier-free formula; [vl]
   % is a non-empty list of variables; [an] is an answer; [theo] is a list of
   % atomic formulas; [ans] is Boolean. Returns a pair $a . p$. Either $a=[T]$
   % and $p$ is a pair of a list of container elements and a theory or $a=[nil]$
   % and $p$ is an error message. If there is a container element with ['break]
   % as varlist, this is the only one.
   begin scalar w,candvl,status; integer len;
      % Infeasible core computation is not yet implemented for the methods. %%%%%%%MAX
      if not !*rlqeinfcore and (w := cl_transform(f,vl,an,theo,ans,bvl)) then
	 {f,vl,an,theo,ans,bvl} := w;
      if not !*rlqeinfcore and (w := cl_gauss(f,vl,an,theo,ans,bvl)) then
	 return w;
      if not !*rlqeinfcore and (w := rl_specelim(f,vl,theo,ans,bvl)) neq 'failed then
	 return w;
      % Elimination set method
      candvl := cl_varsel(f,vl,theo);
      if !*rlverbose and !*rlqevb and (not !*rlqedfs or !*rlqevbold)
	 and (len := length candvl) > 1
      then
	 ioto_prin2 {"{",len,":"};
      status . w := ofsfic!*cl_process!-candvl(f,vl,an,theo,ans,bvl,candvl);
      if !*rlverbose and !*rlqevb and (not !*rlqedfs or !*rlqevbold)
	 and len>1
      then
	 ioto_prin2 {"}"};
      if status eq 'nonocc then
	 return (t . w) . theo;
      if status eq 'failed then
	 return (nil . w) . theo;
      if status eq 'local then
	 return (t . car w) . cl_theo!*;
      if status eq 'elim then
	 return (t . car w) . cdr w;
      rederr {"cl_qevar: bad status",status}
   end;

asserted procedure ofsfic!*cl_process!-candvl(f: QfFormula, vl: KernelL, an: Answer, theo: Theory, ans: Boolean, bvl: KernelL, candvl: KernelL): TaggedContainerElementL;
   begin scalar w,ww,v,alp,ww,status,newForm,ww2,elimset,tpl;
      while candvl do <<
	 v := pop candvl;
	 alp := cl_qeatal(f,v,theo,ans);
	 if alp = '(nil . nil) then <<  % [v] does not occur in [f].
	    if !*rlverbose and (not !*rlqedfs or !*rlqevbold) then
	       ioto_prin2 "*";
	    if !*rlqeinfcore then %%%%%%%MAX
	       w := {ofsfic!*ce_mk(lto_delq(v, vl), f, nil, nil, ans and cl_updans(v, 'arbitrary, nil, nil, an, ans), ic_currentfvect rlqeicdata!*)}
	    else
	       w := {ofsfic!*ce_mk(lto_delq(v,vl),f,nil,nil,ans and cl_updans(v,'arbitrary,nil,nil,an,ans),nil)};
	    status := 'nonocc;
	    candvl := nil
	 >> else if car alp = 'failed then
	    (if null w then <<
	       w := cdr alp;
	       status := 'failed
	    >>)
	 else <<
	    if !*rlqeinfcore then << %%%%%%%MAX
	       elimset := rl_elimset(v, alp);
	       while alp do
		  if caar alp eq 'equal1 then <<
		     if not ('(ofsf_qesubi (pinf)) member elimset) then
			elimset := '(ofsf_qesubi (pinf)) . elimset;
		     if not ('(ofsf_qesubi (minf)) member elimset) then
			elimset := '(ofsf_qesubi (minf)) . elimset;
		     alp := nil
		  >> else
		     alp := cdr alp;
	       ww := cl_esetvectsubst(f, ic_currentfvect rlqeicdata!*, v, elimset, lto_delq(v, vl), an, ans, bvl);
	       ic_clearguardList rlqeicdata!*;
	       if car ww then <<
		  if cadaar ww eq 'true then <<
		     candvl := nil;
		     ww := {{ofsfic!*ce_mk('break, 'true, nil, nil, car cddaar ww, nil)}}
		  >> else <<
		     vl := cadr ww;
		     ww := car ww;
		     for each triple in ww do <<
			tpl := car triple;
			newForm := cadr triple;
			an := caddr triple;
			ic_setcurrentfvect(rlqeicdata!*, tpl);
			if rl_op newForm eq 'or then
			   for each subf in rl_argn newForm do
			      ww2 := ofsfic!*ce_mk(vl, subf, nil, nil, an, tpl) . ww2
			else if newForm neq 'false then
			   ww2 := ofsfic!*ce_mk(vl, newForm, nil, nil, an, tpl) . ww2
		     >>;
		     ww := {ww2}
		  >>
	       >> else
		  ww := {nil}
	    >> else <<
	       if !*rlverbose and (not !*rlqedfs or !*rlqevbold) then
		  ioto_prin2 "e";
	       ww := ofsfic!*cl_esetsubst(f,v,rl_elimset(v,alp),lto_delq(v,vl),an,
		  theo,ans,bvl)
	    >>;
	    if !*rlqelocal then <<
	       candvl := nil;
	       w := ww;
	       status := 'local
	    >> else if rl_betterp(ww,w) then <<
	       w := ww;
	       status := 'elim
	    >>
	 >>
      >>;
      return status . w
   end;

%%%%%%%MAX
asserted procedure cl_esetvectsubst(form, fvect: Vector, v: Kernel, eset: List, vl: KernelL, an: List, ans: Boolean, bvl: KernelL): DottedPair;
   % Elimination Set Vector Substitution. For infeasible core
   % computation only. [fvect] is a vector of quantifier-free formula;
   % [v] is a kernel; [eset] is an elimination set; [an] is an answer;
   % [ans] is Boolean. Returns a pair $l . nvl$, where $nvl$ is the
   % new variable list and $l$ is a list of Vectors, each representing
   % an elimination term. A vector contains the elimination results
   % for the specific elimination term when substituted into the
   % formulas of the formula vector. Guards are only added to the
   % formulas from which the elimination term emerged.
   begin scalar a, d, u, elimres, junct, w, f, u2, sf, resvect,res,falseFound;
      while eset do <<
	 a . d := pop eset;
	 while d do <<
	    u := pop d;
	    if cdr u then <<
	       f := assoc(u, ic_guardList rlqeicdata!*);
	       if f then
		  f := cadr f;
	       u2 := 'true . cdr u
	    >> else
 	       u2 := u;
	    falseFound := nil;
	    resvect := mkvect upbv fvect;
	    for i := 0 : upbv fvect do <<
	       sf := getv(fvect, i);
	       if f and ofsfic_subformulap(sf, f) then <<
		  w := apply(a, bvl . nil . sf . v . u);
		  f := nil
	       >> else
		  w := apply(a, bvl . nil . sf . v . u2);
	       elimres := rl_simpl(cdr w, nil, -1);
	       if !*rlqegsd then
		  elimres := rl_gsd(elimres, nil);
	       if elimres eq 'false then <<
		  if not falseFound then <<
		     ic_addcoverage(rlqeicdata!*, 1);
		     falseFound := t
		  >>;
		  ic_addtofalsevect(rlqeicdata!*, i, 1)
	       >>;
	       putv(resvect, i, elimres)
	    >>;
	    if falseFound then
 	       ic_appendevtplist(rlqeicdata!*, resvect);
	    !*rlqeicsimpl := t;
	    res := ofsfic!*cl_simpl(rl_smkn('and, vector2list resvect), nil, -1);
	    !*rlqeicsimpl := nil;
	    if car res eq 'false then <<
	       if not falseFound then
 		  ofsfic_filterlocalcore(resvect, cadr res);
	    >> else <<
	       res := car res;
	       if res eq 'true then <<
		  eset := d := nil;
		  an := cl_updans(v, a, u, form, an, ans);
		  for each vv in vl do
		     an := cl_updans(vv, 'arbitrary, nil, nil, an, ans);
		  junct := {{resvect, 'true, an}};
	       >> else
		  junct := {resvect,res,cl_updans(v,a,u,form,an,ans)} . junct
	    >>
	 >>
      >>;
      return junct . {vl}
   end;

asserted procedure ofsfic!*cl_esetsubst(f: QfFormula, v: Kernel, eset: List, vl: KernelL, an: List, theo: Theory, ans: Boolean, bvl: KernelL): DottedPair;
   % Elimination set substitution. [f] is a quantifier-free formula; [v] is a
   % kernel; [eset] is an elimination set; [an] is an answer; [theo] is the
   % current theory; [ans] is Boolean. Returns a pair $l . \Theta$, where
   % $\Theta$ is the new theory and $l$ is a list of container elements. If
   % there is a container element with ['break] as varlist, this is the only
   % one.
   begin scalar a,d,u,elimres,junct,bvl,w;
      while eset do <<
	 a . d := pop eset;
	 while d do <<
	    u := pop d;
	    w := apply(a,bvl . theo . f . v . u);
	    theo := union(theo,car w);
	    elimres := rl_simpl(cdr w,theo,-1);
	    if !*rlqegsd then
	       elimres := rl_gsd(elimres,theo);
	    if elimres eq 'true then <<
	       an := cl_updans(v,a,u,f,an,ans);
	       for each vv in vl do
		  an := cl_updans(vv,'arbitrary,nil,nil,an,ans);
	       junct := {ofsfic!*ce_mk('break,elimres,nil,nil,an,nil)};
	       eset := d := nil
	    >> else if elimres neq 'false then
	       if rl_op elimres eq 'or then
		  for each subf in rl_argn elimres do
		     junct := ofsfic!*ce_mk(vl,subf,nil,nil,cl_updans(v,a,u,f,an,ans),nil) . junct
	       else
		  junct :=
		     ofsfic!*ce_mk(vl,elimres,nil,nil,cl_updans(v,a,u,f,an,ans),nil)
			. junct;
	 >>
      >>;
      return junct . theo
   end;

procedure ofsfic!*cl_qeatal1(f,v,theo,flg,ans);
   % Quantifier elimination atomic formula list. [f] is aformula; [v] is a
   % variable; [theo] is the current theory, [flg] and [ans] are Boolean.
   % Returns an ALP. If [flg] is non-[nil] [f] has to be considered negated.
   begin scalar op,w,ww;
      op := rl_op f;
      w := if rl_tvalp op then
	 {nil . nil}
      else if op eq 'not then
	 {ofsfic!*cl_qeatal1(rl_arg1 f,v,theo,not flg,ans)}
      else if op eq 'and then <<
	 if !*rlataltheo then
	    for each subf in rl_argn f do
	       if cl_atfp subf and not memq(v, rl_varlat subf) then
		  theo := lto_insert(subf, theo);
	 for each subf in rl_argn f collect
	    ofsfic!*cl_qeatal1(subf,v,theo,flg,ans)
      >> else if op eq 'or then <<
	 if !*rlataltheo then
	    for each subf in rl_argn f do
	       if cl_atfp subf and not memq(v, rl_varlat subf) then
		  theo := lto_insert(rl_negateat subf, theo);
	 for each subf in rl_argn f collect
	    ofsfic!*cl_qeatal1(subf,v,theo,flg,ans)
      >> else if op eq 'impl then
	 {ofsfic!*cl_qeatal1(rl_arg2l f,v,theo,not flg,ans),
	    ofsfic!*cl_qeatal1(rl_arg2r f,v,theo,flg,ans)}
      else if op eq 'repl then
	 {ofsfic!*cl_qeatal1(rl_arg2l f,v,theo,flg,ans),
	    ofsfic!*cl_qeatal1(rl_arg2r f,v,theo,not flg,ans)}
      else if op eq 'equiv then
	 {ofsfic!*cl_qeatal1(rl_arg2l f,v,theo,not flg,ans),
	    ofsfic!*cl_qeatal1(rl_arg2r f,v,theo,flg,ans),
	    ofsfic!*cl_qeatal1(rl_arg2l f,v,theo,flg,ans),
	    ofsfic!*cl_qeatal1(rl_arg2r f,v,theo,not flg,ans)}
      else if rl_quap op then
	 rederr "argument formula not prenex"
      else  % [f] is an atomic formula.
	 if !*rlqeinfcore then << %%%%%%%MAX
	    ww := rl_translat(f, v, theo, flg, ans);
	    if car ww neq 'failed then <<
	       for each a in car ww do
		  for each g in cdr a do
		     ic_appendguardList(rlqeicdata!*, g . {f});
	    >>;
	    {ww}
	 >> else
	    {rl_translat(f,v,theo,flg,ans)};
      if (ww := atsoc('failed,w)) then return ww;
      return cl_alpunion w
   end;

procedure ofsfic!*cl_simpl(f,atl,n);
   % Common logic simplify. [f] is a formula; [atl] is a list of
   % atomic formulas, which are considered to describe a theory; [n]
   % is an integer. Depends on switches [!*rlsism], [!*rlsichk],
   % [!*rlsiso], [!*rlsiidem]. Returns the identifier [inctheo] or a
   % formula. [inctheo] means that [atl] is inconsistent. Else the
   % result is [f], simplified (wrt. [atl]). For non-negative [n],
   % simplification stops at level [n].
   begin scalar w;
      if null !*rlsism then
	 return cl_simpl1(f,nil,n,nil);
      atl := cl_sitheo atl;
      if atl eq 'inctheo then
	 return 'inctheo;
      w := rl_smupdknowl('and,atl,nil,n+1);
      if w eq 'false then return 'inctheo;
      if !*rlqeicsimpl then << %%%%%%%MAX
	 w := cl_simpl1!-tagged(f, w, n, nil);
	 ic_settaglist(rlqeicdata!*, nil)
      >> else w:=cl_simpl1(f,w,n,nil);
      return w;
   end;

%%%%%%%MAX
procedure cl_simpl1!-tagged(f,knowl,n,sop);
   % Common logic simplify. [f] is a formula; [knowl] is an IRL; [n]
   % is an integer; [sop] is a CL operator. Depends on switches
   % [!*rlsism], [!*rlsichk], [!*rlsiso], [!*rlsiidem]. Returns a
   % formula. Simplifies [f] recursively using [knowl].
   begin scalar op,result,w,newknowl;
      if eqn(n, 0) then
 	 return {f, nil};
      op := rl_op f;
      if rl_tvalp op then <<
	 if eqn(n, -1) then
 	    return {f, 0 . nil};
      	 return {f, nil}
      >>;
      if rl_junctp op then <<
	 w := cl_smsimpl!-junct!-tagged(op, rl_argn f, knowl, n);
	 return {rl_smkn(op, car w), cadr w}
      >>;
      if op eq 'not then <<
	 % CHANGED TO n FROM n-1
	 result := cl_simpl1!-tagged(rl_arg1 f, knowl, n, 'not);
	 if rl_tvalp car result then
 	    return {cl_flip car result, cadr result};
	 if cl_atfp car result then
	    return {rl_negateat car result, cadr result};
	 return {cl_negate!-invol car result, cadr result}
      >>;
      if rl_quap op then <<
	 if !*rlsism then knowl := rl_smrmknowl(knowl, rl_var f);
	 % CHANGED TO n FROM n-1
	 result := cl_simpl1!-tagged(rl_mat f, knowl, n, op);
	 if rl_tvalp car result then return result;
	 if not (rl_var f memq cl_fvarl car result) then
	    return result;
	 return {rl_mkq(op,rl_var f,car result), cadr result}
      >>;
      if rl_bquap op then <<
	 if !*rlsism then
 	    knowl := rl_smrmknowl(knowl, rl_var f);
	 return cl_simplbq(f, knowl, n)
      >>;
      if (w := rl_external(op, 'cl_simpl)) then
	 return apply(w, {f});
      w := cl_simplat(f, sop);
      if !*rlsism then <<
	 op := rl_op w;
	 if rl_junctp op then <<
	    w := cl_smsimpl!-junct!-tagged(op, rl_argn w, knowl, n);
	    return {rl_smkn(op, car w), cadr w}
	 >>;
	 if rl_tvalp op then <<
	    if eqn(n, -1) then
 	       return {w, {0}};
	    return {w, {{0}, 'arb, n}};
	 >>;
	 % [w] is atomic.
	 newknowl := ofsf_smupdknowl!-tagged('and, w, {-1}, rl_smcpknowl knowl, n);
	 if newknowl eq 'false then <<
	    if eqn(n, -1) then
 	       return {{'false}, ofsfic_extracttags ofsfic_prunetag ic_taglistremfalse rlqeicdata!*};
	    return {{'false}, ic_taglistremfalse rlqeicdata!*}
	 >>;
	 w := ofsf_smmkatl!-tagged('and, knowl, newknowl, n);
	 return if car w eq 'false then w else {rl_smkn('and, car w), cadr w}
      >>;
      if w then
	 return w;
      rederr {"cl_simpl1(): unknown operator",op}
   end;

%%%%%%%MAX
procedure cl_smsimpl!-junct!-tagged(op,junct,knowl,n);
   % Common logic smart simplify. [op] is one of [and], [or]; [junct]
   % is a list of formulas; [knowl] is an IRL; [n] is an integer.
   % Returns a list of formulas. Accesses the switch [!*rlsism]. With
   % [!*rlsism] on sophisticated simplifications are applied to
   % [junct].
   begin scalar break,w,atl,col,newknowl,k,atflist,l,l2,l3,rel,at;
      %if not !*rlsism then return cl_gand!-col(junct,n,op,nil);
      newknowl := rl_smcpknowl knowl;
      break := cl_cflip('false, op eq 'and);
      k := 0;
      for each subf in junct do <<
	 w := if cl_atfp subf then
	    cl_simplat(subf, op)
	 else
	    subf;
	 if cl_atfp w then <<
	    atflist := w . atflist;
	    newknowl := ofsf_smupdknowl!-tagged(op, w, {k}, newknowl, n);
	 >> else
	    col := {w, {{{k}, {'arb}, n}}} . col;
	 k := k+1
      >>;
      if newknowl eq 'false then <<
	 if eqn(n, -1) then
 	    return {{break}, ofsfic_extracttags ofsfic_prunetag ic_taglistremfalse rlqeicdata!*};
	 return {{break}, ic_taglistremfalse rlqeicdata!*}
      >>;
      w:= cl_smsimpl!-junct1!-tagged(op, atl, reversip col, knowl, newknowl, n, break);
      if caar w neq 'false and !*icinitsimpl and eqn(n, -1) then <<
	 l2 := nil;
	 k := 0;
	 for each subf in car w do <<
	    rel := nil;
	    if cl_atfp subf then <<
	       at := ofsf_at2ir(subf, n);
	       l := ofsfic_inittps(cdr assoc(car at, ic_taglist rlqeicdata!*), cdadr at);
	       if (cadadr at eq 'leq) or (cadadr at eq 'lessp) then <<
		  if caadr car l eq 'leq then
		     rel := nth(l, 4);
		  if rel then <<
		     l3 := ofsfic_tagnumbers caaar rel;
		     for each i in ofsfic_tagnumbers car l do
 			l3 := i . l3;
		     l := l3
		  >> else
 		     l := ofsfic_tagnumbers car l
	       >> else if cadadr at eq 'equal then <<
		  rel := caddr l;
		  if null rel then <<
		     l3 := ofsfic_tagnumbers car rel;
		     for each i in ofsfic_tagnumbers cadr l do
			l3 := i . l3;
		     l := l3
		  >> else
 		     l := ofsfic_tagnumbers caddr l
	       >> else if (cadadr at eq 'geq) or (cadadr at eq 'greaterp) then <<
		  if caadr cadr l eq 'geq then
 		     rel := nth(l, 4);
		  if rel then <<
		     l3 := ofsfic_tagnumbers caar rel;
		     for each i in ofsfic_tagnumbers cadr l do
 			l3 := i . l3;
		     l := l3
		  >> else
		     l := ofsfic_tagnumbers cadr l
	       >> else <<
		  l := for each i in nth(l, 4) collect car i;
		  l := for each i in l join ofsfic_tagnumbers l
	       >>
	    >> else
 	       l := ofsfic_tagnumbers(cadr assoc(subf, ic_taglist rlqeicdata!*));
	    l2 := {k, l} . l2;
	    k := k + 1
	 >>;
	 ic_setoffsetlist(rlqeicdata!*, l2)
      >>;
      if eqn(n, -1) then
 	 return {car w, ofsfic_extracttags ofsfic_prunetag cadr w};
      return w
   end;

%%%%%%%MAX
procedure cl_smsimpl!-junct1!-tagged(op,atl,col,knowl,newknowl,n,break);
   % Common logic smart simplify. [op] is one of [and], [or]; [atl] is
   % a list of atomic formulas; [col] is a list of complex formulas;
   % [knowl] and [newknowl] are IRL's; [n] is an integer; [break] is
   % one of [true], [false] corresponding to [op]. Returns a list of
   % formulas.
   begin scalar a,w,wop,argl,sicol,natl,tag,w2,tagl,ttagl,tagcopy;
      while col do <<
	 a := pop col;
	 tag := cadr a;
	 a := car a;
	 tagcopy := copy ic_taglist rlqeicdata!*;
	 w2 := cl_simpl1!-tagged(a, newknowl, n-1, op);
	 w := car w2;
	 ic_settaglist(rlqeicdata!*, tagcopy);
	 tagl := ofsfic_tagrepl(cadr w2, tag, n-1);
	 tagl := ofsfic_prunetag tagl;
	 wop := rl_op w;
	 if wop eq break then <<
	    a := break;
	    col := nil
	 >> else
	    if wop eq op then <<
	       argl := rl_argn w;
	       while argl and cl_atfp car argl do <<
		  natl := {car argl, tagl} . natl;
		  argl := cdr argl
	       >>;
	       if !*rlsiidem and natl then <<
		  col := nconc(reversip sicol, col);
		  sicol := nil
	       >>;
	       if argl then
		  sicol := nconc(sicol, for each x in reverse argl collect {x, tagl});
	    >> else if rl_cxp wop then <<
	       if wop neq cl_flip break then
 		  sicol := {w,tagl} . sicol
 	       else
 		  ttagl := append(tagl, ttagl)
	    >> else <<  % [w] is atomic.
	       if !*rlsiidem then <<
		  col := nconc(reversip sicol,col);
		  sicol := nil
	       >>;
	       natl := {{w, tagl}}
	    >>;
	 if natl then <<
	    for each sf in natl do
	       newknowl := ofsf_smupdknowl!-tagged(op, car sf, cadr sf, newknowl, n);
	    if newknowl eq 'false then <<
	       tagl := ic_taglistremfalse rlqeicdata!*;
	       a := break;
	       col := nil
	    >>;
	    natl := nil
	 >>
      >>;
      if a eq break then
 	 return {{break}, tagl};
      return cl_smsimpl!-junct2!-tagged(op,sicol,knowl,newknowl,n,break,append(ttagl,tagl))
   end;

%%%%%%%MAX
procedure cl_smsimpl!-junct2!-tagged(op,sicol,knowl,newknowl,n,break,tagl);
   % Common logic smart simplify. [op] is one of [and], [or]; [sicol] is a list
   % of complex formulas; [knowl] and [newknowl] are IRL's; [n] is an integer;
   % [break] is one of [true], [false] corresponding to [op]. Returns a list of
   % formulas.
   begin scalar atl,w;
      atl := ofsf_smmkatl!-tagged(op, knowl, newknowl, n);
      tagl := append(cadr atl, tagl);
      atl := car atl;
      if atl eq break then
	 return {{break}, tagl};
      if !*rlsichk then <<
	 w := sicol;
	 sicol := nil;
	 for each x in w do
 	    sicol := ofsfic_carinsert(x, sicol)
      >> else
	 sicol := reversip sicol;
      if !*rlsiso then <<
	 atl := sort(atl, 'rl_ordatp);
	 if !*rlsisocx then
	    sicol := sort(sicol, function(lambda(x, y); cl_sordp(car x, car y)))
      >>;
      w := nconc(atl, for each i in sicol collect car i);
      for each i in sicol do <<
	 if !*icinitsimpl and eqn(n, -1) then
 	    ic_appendtaglist(rlqeicdata!*, car i . {cadr i});
	 tagl:=append(cadr i, tagl)
      >>;
      if w then return
 	 {w, tagl};
      return {{cl_flip break}, tagl}
   end;

%%%%%%%MAX
asserted procedure ofsfic_ftol(f: Formula): FormulaL;
   begin scalar flist;
      flist := caddr cl_split f;
      if rl_op flist eq 'and then
      	 return rl_argn flist;
      return {flist}
   end;

%%%%%%%MAX
procedure ofsfic_carinsert(x, l);
   if assoc(car x, l) then l else x . l;

%%%%%%%MAX
procedure ofsfic_insertqcar(x, l);
   if null l then
      x . nil
   else if car x = caar l then
      l
   else
      car l . ofsfic_insertqcar(x, cdr l);

%%%%%%%MAX
procedure ofsfic_tagflat(tag);
   if listp caar tag then
      {for each j in car tag join
 	 if listp car j then
 	    copy car j
 	 else
 	    {copy car j}, cadr tag, caddr tag}
   else
      tag;

%%%%%%%MAX
procedure ofsfic_threepointsearch(v);
   begin scalar u, l, e, n, lb, ub, eb, eberror, nb, val;
      for each i in v do <<
       	 val := if cadadr i then
 	    {if cdr cdadr i < 0 then cadadr i else - cadadr i,
 	       if cdr cdadr i < 0 then -cdr cdadr i else cdr cdadr i}
 	 else
 	    {0, 1};
       	 if caadr i eq 'leq then <<
	    if null ub then
 	       ub := val;
	    if not u or (cadr val * car ub > cadr ub * car val) then <<
	       u := i;
	       ub := val
	    >>
       	 >>;
       	 if caadr i eq 'lessp then <<
	    if null ub then
 	       ub := val;
	    if cadr val * car ub >= cadr ub * car val then <<
	       u := i;
	       ub := val
	    >>
       	 >>;
       	 if caadr i eq 'geq then <<
	    if null lb then
 	       lb := val;
	    if null l or (cadr val * car lb < cadr lb * car val) then <<
	       lb := val;
	       l := i
	    >>
       	 >>;
       	 if caadr i eq 'greaterp then <<
	    if null lb then
 	       lb := val;
	    if (cadr val * car lb <= cadr lb * car val) then <<
	       lb := val;
	       l := i
	    >>
       	 >>;
       	 if caadr i eq 'neq then
 	    n := {i, val} . n;
       	 if caadr i eq 'equal then <<
	    if eb and not (cadr val * car eb = cadr eb * car val) then
	       eberror := {ofsfic_tagflat e, ofsfic_tagflat i};
	    e := i;
	    eb := val
       	 >>
      >>;
      if eberror then
 	 return eberror;
      if ub and lb then <<
       	 if cadr lb * car ub < cadr ub * car lb then
 	    return {ofsfic_tagflat l, ofsfic_tagflat u};
       	 if (cadr lb * car ub = cadr ub * car lb) and (caadr l eq 'greaterp or caadr u eq 'lessp) then
 	    return {ofsfic_tagflat l, ofsfic_tagflat u}
      >>;
      if eb then <<
       	 if ub and (cadr ub * car eb > cadr eb * car ub) then
 	    return {ofsfic_tagflat e, ofsfic_tagflat u};
       	 if ub and (cadr ub * car eb = cadr eb * car ub) and caadr u eq 'lessp then
 	    return {ofsfic_tagflat e, ofsfic_tagflat u};
       	 if lb and (cadr lb * car eb = cadr eb * car lb) and caadr l eq 'greaterp then
 	    return {ofsfic_tagflat e, ofsfic_tagflat l};
       	 if lb and (cadr lb * car eb < cadr eb * car lb) then
	    return {ofsfic_tagflat e, ofsfic_tagflat l}
      >>;
      if n then <<
       	 for each p in n do <<
	    nb := cadr p;
	    if lb and ub and (cadr lb * car ub = cadr ub * car lb) and (cadr ub * car nb = cadr nb * car ub) then
	       eberror := {ofsfic_tagflat l, ofsfic_tagflat car p, ofsfic_tagflat u};
	    if eb and (cadr eb * car nb = cadr nb * car eb) then
 	       eberror := {ofsfic_tagflat car p, ofsfic_tagflat e}
       	 >>;
       	 return eberror
      >>;
      ioto_tprin2t{" "};
      ioto_tprin2t{"v: ", v};
      ioto_tprin2t{"u: ", u};
      ioto_tprin2t{"ub: ", ub};
      ioto_tprin2t{"l: ", l};
      ioto_tprin2t{"lb: ", lb};
      ioto_tprin2t{"e: ", e};
      ioto_tprin2t{"n: ", n};
      rederr "Error in ofsfic_threepointsearch"
   end;

%%%%%%%MAX
procedure ofsfic_inittps(v, value);
   begin scalar u, l, e, n, lb, ub, eb, eberror, val;
      for each i in v do <<
       	 val := if cadadr i then
 	    {if cdr cdadr i < 0 then cadadr i else - cadadr i,
	     if cdr cdadr i < 0 then -cdr cdadr i else cdr cdadr i}
 	 else
 	    {0, 1};
       	 if caadr i eq 'leq then <<
	    if null ub then
 	       ub := val;
	    if not u or (cadr val * car ub > cadr ub * car val) then <<
	       u := i;
	       ub := val
	    >>
       	 >>;
       	 if caadr i eq 'lessp then <<
	    if null ub then
 	       ub := val;
	    if cadr val * car ub >= cadr ub * car val then <<
	       u := i;
	       ub := val
	    >>
       	 >>;
       	 if caadr i eq 'geq then <<
	    if null lb then
 	       lb := val;
	    if null l or (cadr val * car lb < cadr lb * car val) then <<
	       lb := val;
	       l := i
	    >>
       	 >>;
       	 if caadr i eq 'greaterp then <<
	    if null lb then
 	       lb := val;
	    if cadr val * car lb <= cadr lb * car val then <<
	       lb := val;
	       l := i
	    >>
       	 >>;
       	 if caadr i eq 'neq then
 	    n := {i, val} . n;
       	 if caadr i eq 'equal then <<
	    if eb and not (cadr val * car eb = cadr eb * car val) then
	       eberror := {ofsfic_tagflat e, ofsfic_tagflat i};
	    if not (e and cadr e = value) then <<
	       e := i;
	       eb := val
	    >>
       	 >>
      >>;
      return {u, l, e, n}
   end;

%%%%%%%MAX
procedure ofsfic_tagnumbers(tag);
   begin
      if listp tag then <<
	 if cdr tag and not atom cadr tag then <<
	    if caadr tag eq 'arb or caadr tag eq 'neq or caadr tag eq 'leq or
	       caadr tag eq 'lessp or caadr tag eq 'geq or caadr tag eq 'greaterp or
	       caadr tag eq 'equal then
		  return ofsfic_tagnumbers car tag;
	    return for each i in tag join ofsfic_tagnumbers i
	 >>;
	 return for each i in tag join ofsfic_tagnumbers i
      >>;
      return {tag}
   end;

%%%%%%%MAX
% Replace each entry in tagl with depth <= n with the entries in tags.
% If there is no entry with depth <= n, then just add tags to tagl.
procedure ofsfic_tagrepl(tagl, tags, n);
   begin scalar tagl2, found;
      for each i in tagl do
       	 if caddr i <= n then <<
	    if null found then <<
	       found := t;
	       for each j in tags do
 		  tagl2 := j . tagl2
	    >>
       	 >> else
 	    tagl2 := i . tagl2;
      if null found then
 	 for each j in tags do
 	    tagl2 := j . tagl2;
      return tagl2
   end;

%%%%%%%MAX
% Probably exists already. Checks if an entry e is in a list l with =.
procedure ofsfic_containsp(l, e);
   begin scalar found;
      while l do
       	 if e = car l then <<
	    found := t;
	    l := nil
       	 >> else
 	    l := cdr l;
      return found
   end;

%%%%%%%MAX
% Extract only the tags in the taglist.
procedure ofsfic_extracttags(tagl);
   begin scalar l;
      for each i in tagl do
       	 for each j in car i do
	    if not ofsfic_containsp(l, j) then
 	       l := j . l;
      return l
   end;

%%%%%%%MAX
% Remove duplicates from the taglist.
procedure ofsfic_prunetag(tagl);
   begin scalar found, tagl2;
      for each i in tagl do <<
       	 found := nil;
       	 for each j in tagl2 do
 	    if j = i then
 	       found := t;
       	 if not found then
 	    tagl2 := i . tagl2
      >>;
      return tagl2
   end;

%%%%%%%MAX
procedure ofsfic_subformulap(sf, f);
   begin scalar w;
      if sf neq 'true then <<
	 if (car sf eq 'or) or (car sf eq 'and) then <<
	    for each ssf in rl_argn sf do
	       if not w then
		  w := ofsfic_subformulap(ssf, f);
	    return w
	 >>;
	 w := car ofsf_at2ir(sf, -1);
	 return (f = sf)
      >>;
      return nil
   end;

%%%%%%%MAX (Fixed by MK.)
% Reduce local core by repeated simplification. Unoptimized.
asserted procedure ofsfic_filterlocalcore(fvect: Vector, core: List): Any;
   % No meaningful return value.
   begin scalar w, evect;
      integer l;
      evect := ic_essentialvect rlqeicdata!*;
      w := for i := 0 : upbv evect collect
	 if getv(evect, i) then
	    getv(fvect, i)
	 else
	    'true;
      w := ofsfic!*cl_simpl(rl_smkn('and, w), nil, -1);
      if w eq 'false then
	 return;
      l := length core + 1;
      while length core < l do <<
	 w := for i := 0 : upbv fvect collect
	    if i memq core then
	       getv(fvect, i)
	    else
	       'true;
	 !*rlqeicsimpl := t;
	 w := ofsfic!*cl_simpl(rl_smkn('and, w), nil, -1);
	 !*rlqeicsimpl := nil;
	 l := length core;
	 core := for each i in cadr w join
	    if i memq core then  % The new core is a subset of the old core.
	       {i}
      >>;
      for each i in core do
	 putv(evect, i, t)
   end;

%%%%%%%MAX
procedure ofsf_smupdknowl!-tagged(op,a,tag,knowl,n);
   % Ordered field standard form update knowledge. [op] is one of
   % [and], [or]; [atl] is a list of (simplified) atomic formulas;
   % [knowl] is a conjunctive IRL; [n] is the current level. Returns
   % an IRL. Destructively updates [knowl] wrt. the [atl] information.
   begin scalar w,w2,ir,taglist;
      if knowl eq 'false then
 	 return knowl;
      a := if op eq 'and then a else ofsf_negateat a;
      ir := ofsf_at2ir(a, n);
      if w := assoc(car ir, knowl) then <<
	 w2 := for each j in w collect j;
	 cdr w := ofsf_sminsert(cadr ir, cdr w);
	 if not (cdr w = cdr w2 and n = caadr w) then <<
	    taglist := ic_taglist rlqeicdata!*;
	    w2 := assoc(car w, taglist);
	    cdr w2 := {tag, cdadr ir, n} . cdr w2
	 >>;
	 if cdr w eq 'false then <<
	    knowl := 'false;
	    ic_appendtaglist(rlqeicdata!*, ('false . ofsfic_threepointsearch cdr w2))
	 >>  % else [ofsf_sminsert] has updated [cdr w] destructively.
      >> else <<
	 ic_appendtaglist(rlqeicdata!*, car ir . {tag,cdadr ir,n} . nil);
	 knowl := ir . knowl
      >>;
      return knowl
   end;

%%%%%%%MAX
procedure ofsf_smmkatl!-tagged(op, oldknowl, newknowl, n);
   if !*rlsippatl then
      ofsf_sippatl!-tagged(op, ofsf_smmkatl1!-tagged(op, oldknowl, newknowl, n), newknowl, n)
   else
      ofsf_smmkatl1!-tagged(op, oldknowl, newknowl, n);

%%%%%%%MAX
procedure ofsf_sippatl!-tagged(op, atl, newknowl, n);
   begin scalar gtrue, gfalse, gequal, subal, zvl, posvl, negvl, geqvl, leqvl,
	 neqvl, at, natl, atl2, at2, ir, vl, m, tagl, w, loctag, asc, newt, found, tmp;
      gtrue := cl_cflip('true, op eq 'and);
      gfalse := cl_cflip('false, op eq 'and);
      gequal := ofsf_clnegrel('equal, op eq 'and);
      {subal, zvl, posvl, negvl, geqvl, leqvl, neqvl} := ofsfic!*ofsf_exploitKnowl newknowl;
      while atl do <<
	 loctag := nil;
	 atl2 := pop atl;
	 if caddr caadr atl2 eq n then
 	    for each i in cadr atl2 do
	       if listp caar i then
 		  for each j in car i do <<
	       	     loctag := lto_insertq(j, loctag);
	       	     tagl := j . tagl
	       	  >>
	       else <<
		  loctag := lto_insertq(i, loctag);
		  tagl := i . tagl
	       >>;
	 for each at in car atl2 do <<
	    if not null at then <<
	       at2 := copy at;
	       if !*rlsippsubst and not ofsf_vareqnp(gequal, at) then <<
		  vl := rl_varlat at;
		  for each v in (for each i in subal collect car i) do <<
		     if ofsfic_containsp(vl, v) then <<
			m := assoc(v, ic_varList rlqeicdata!*);
			w := cdr assoc(cadr m, ic_taglist rlqeicdata!*);
			for each i in w do
			   if listp caar i then
 			      for each j in car i do <<
			      	 loctag := lto_insertq(j, loctag);
			      	 tagl := j . tagl
			      >>
			   else <<
			      loctag := lto_insertq(i, loctag);
			      tagl := i. tagl
			   >>
		     >>
		  >>;
		  at := ofsf_sippsubst(at, subal);
		  at := ofsf_simplat1(at, op) where !*rlsiatadv = nil;
	       >>;
	       if not rl_tvalp at then
		  if !*rlsippsignchk and not sfto_varIsNumP ofsf_arg2l at then
		     at := ofsf_sippsignchk(at, zvl, posvl, negvl, geqvl, leqvl, neqvl);
	       if not ((at eq gfalse) or (at = at2)) then <<
		  vl := rl_varlat at2;
		  for each v in vl do <<
		     m := assoc(v, ic_varList rlqeicdata!*);
		     if m then <<
			w := cdr assoc(cadr m, ic_taglist rlqeicdata!*);
			for each i in w do
			   if listp caar i then
 			      for each j in car i do <<
			      	 loctag := lto_insertq(j, loctag);
			      	 tagl := j . tagl;
			      >>
 			   else <<
			      loctag := lto_insertq(i, loctag);
			      tagl := i . tagl
			   >>
		     >>
		  >>
	       >>;
	       if eqn(n, -1) and not (at eq gtrue or at eq gfalse) then <<
		     ir := ofsf_at2ir(at, n);
		     asc := assoc(car ir, ic_taglist rlqeicdata!*);
		     newt := {for each i in loctag join ofsfic_tagnumbers i, cdadr ir, -1};
		     if asc then <<
		      	found := nil;
		      	tmp := asc;
		      	while tmp and not found do <<
			   if car tmp = newt then
 			      found := t;
			   tmp := cdr tmp
		      	>>;
		      	if not found then
 			   cdr asc := newt . cdr asc;
		     >> else
		      	ic_appendtaglist(rlqeicdata!*, car ir . {{for each i in loctag join ofsfic_tagnumbers i, cdadr ir, -1}})
	       >>;
	       if at eq gfalse then <<
		  tagl := nil;
		  if caddr caadr atl2 eq n then
 		     for each i in cadr atl2 do
		     	if listp caar i then
 			   for each j in car i do
 			      tagl := j . tagl
 			else
			   tagl := i . tagl;
		  vl := rl_varlat at2;
		  for each v in vl do <<
		     m := assoc(v, ic_varList rlqeicdata!*);
		     if m then <<
			w := cdr assoc(cadr m, ic_taglist rlqeicdata!*);
			for each i in w do
			   if listp caar i then
 			      for each j in car i do
				 tagl := j . tagl
 			   else
			      tagl := i . tagl
		     >>
		  >>;
		  natl := gfalse;
		  atl := nil
	       >> else if at neq gtrue then
		  natl := lto_insert(at, natl)
	    >>
	 >>
      >>;
      ic_setvarlist(rlqeicdata!*, nil);
      return {natl, tagl}
   end;

%%%%%%%MAX
procedure ofsf_smmkatl1!-tagged(op, oldknowl, newknowl, n);
   % Ordered field standard form make atomic formula list. [op] is one
   % of [and], [or]; [oldknowl] and [newknowl] are IRL's; [n] is an
   % integer. Returns a list of atomic formulas. Depends on switch
   % [rlsipw].
   if op eq 'and then
      ofsf_smmkatl!-and!-tagged(oldknowl, newknowl, n)
   else  % [op eq 'or]
      ofsf_smmkatl!-or!-tagged(oldknowl, newknowl, n);

%%%%%%%MAX
procedure ofsf_smmkatl!-and!-tagged(oldknowl, newknowl, n);
   begin scalar w, tag;
      if not !*rlsipw and !*rlsipo then
	 return for each i in newknowl collect
 	    {ofsf_ir2atl('and, i, n), cdr assoc(car i, ic_taglist rlqeicdata!*)};
      return for each ir in newknowl collect <<
	 w := atsoc(car ir, oldknowl);
	 tag := cdr assoc(car ir, ic_taglist rlqeicdata!*);
	 if null w then
 	    {ofsf_ir2atl('and, ir, n), tag}
 	 else
 	    {ofsf_smmkatl!-and1(w, ir, n), tag}
      >>
   end;

%%%%%%%MAX
procedure ofsf_smmkatl!-or!-tagged(oldknowl, newknowl, n);
   begin scalar w, tag;
      return for each ir in newknowl collect <<
	 w := atsoc(car ir, oldknowl);
	 tag := cdr assoc(car ir, ic_taglist rlqeicdata!*);
	 if null w then
 	    {ofsf_ir2atl('or, ir, n), tag}
 	 else
 	    {ofsf_smmkatl!-or1(w, ir, n), tag}
      >>
   end;

%%%%%%%MAX
procedure ofsfic!*ofsf_exploitKnowl(knowl);
   begin
      scalar subal, zvl, posvl, negvl, geqvl, leqvl, neqvl, v, rel, a;
      integer n;
      for each ir in knowl do
	 if (v := sfto_varp car ir) then
	    for each le in cdr ir do <<
	       rel . a := cdr le;
	       a := negsq a;
	       n := numr a or 0;
	       if rel eq 'equal then <<
		  if !*rlsippsubst then <<
		     subal := (v . a) . subal;
		     if !*rlqeicsimpl then
			ic_insertvarlist(rlqeicdata!*, v . ir);
		  >> else
		     (if n > 0 then
			posvl := lto_insertq(v, posvl)
		     else if n < 0 then
			negvl := lto_insertq(v, negvl)
		     else if eqn(n,0) then
			zvl := lto_insertq(v, zvl))
	       >> else if rel eq 'greaterp then <<
		  if n >= 0 then <<
		     if !*rlqeicsimpl then
			ic_insertvarlist(rlqeicdata!*, v . ir);
		     posvl := lto_insertq(v, posvl)
		  >>
	       >> else if rel eq 'geq then <<
		  if n > 0 then <<
		     if !*rlqeicsimpl then
			ic_insertvarlist(rlqeicdata!*, v . ir);
		     posvl := lto_insertq(v, posvl)
		  >> else if eqn(n, 0) then <<
		     if !*rlqeicsimpl then
			ic_insertvarlist(rlqeicdata!*, v . ir);
		     geqvl := lto_insertq(v, geqvl)
		  >>
	       >> else if rel eq 'lessp then <<
		  if n <= 0 then <<
		     if !*rlqeicsimpl then
			ic_insertvarlist(rlqeicdata!*, v . ir);
		     negvl := lto_insertq(v, negvl)
		  >>
	       >> else if rel eq 'leq then <<
		  if n < 0 then <<
		     if !*rlqeicsimpl then
			ic_insertvarlist(rlqeicdata!*, v . ir);
		     negvl := lto_insertq(v, negvl)
		  >> else if eqn(n, 0) then <<
		     if !*rlqeicsimpl then
			ic_insertvarlist(rlqeicdata!*, v . ir);
		     leqvl := lto_insertq(v, leqvl)
		  >>
	       >> else if rel eq 'neq then <<
		  if eqn(n, 0) then <<
		     if !*rlqeicsimpl then
			ic_insertvarlist(rlqeicdata!*, v . ir);
		     neqvl := lto_insertq(v, neqvl)
		  >>
	       >>
	    >>;
      return {subal, zvl, posvl, negvl, geqvl, leqvl, neqvl}
   end;

procedure ofsfic!*ofsf_qemkans(an,svf);
   begin scalar res; integer time, gctime;
      if !*rlverbose then <<
	 time := time();
	 gctime := gctime()
      >>;
      if !*rlqestdans and not !*rlqegen then
	 an := ofsf_qemkstdans(an, svf);
      res := ofsf_qemkans1 an;
      res := if !*rlqebacksub then
	 ofsfic!*ofsf_qebacksub res
      else
	 ofsfic!*ofsf_qenobacksub res;
      if !*rlqebacksub then res := sort(res, function ordpcar);
      if !*rlverbose then <<
	 ioto_tprin2 {"++++ Time for answer processing: ", time() - time, " ms"};
	 gctime := gctime() - gctime;
	 if gctime > 0 then
	    ioto_prin2t {" plus GC time: ", gctime, " ms"}
      >>;
      return res
   end;

procedure ofsfic!*ofsf_qebacksub(eql);
   % Quantifier elimination back substitution. [eql] is a list $((v . w), ...)$,
   % where $v$ is a variable and $w$ is an SQ. Returns a list of equations.
   begin scalar subl, e;
      return for each w in eql join <<
	 e := car w . prepsq subsq(cdr w, subl);
	 subl := (car w . cdr e) . subl;
	 if !*rlqefullans or not flagp(car w, 'rl_qeansvar) then {e}
      >>
   end;

procedure ofsfic!*ofsf_qenobacksub(eql);
   % Quantifier elimination back substitution. [eql] is a list $(((v .
   % w) . a), ...)$, where $v$ is a variable, $w$ is an SQ, and $a$ is
   % an answer translation. Returns a list $((e,a),...)$, where $e$ is
   % an equation and $a$ is an answer translation.
   for each w in eql join
      if !*rlqefullans or not flagp(car w, 'rl_qeansvar) then
	 {car w . prepsq cdr w};

endmodule;  % [ofsfic]

end;  % of file
