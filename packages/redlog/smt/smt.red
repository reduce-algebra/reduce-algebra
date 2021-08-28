module smt;  % An SMTLIB 2 REPL

revision('smt, "$Id$");

copyright('smt, "(c) 2013-2021 T. Sturm");

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

% trunk/psl/dist/nonkernel/token-decls.sl

create!-package('(smt smtread), nil);

switch smtabout;
switch smtprompt;
% switches are intialized in support/entry.red

global '(nxtsym!*);
global '(!$eof!$);
global '(emsg!*);
global '(!*pretty!-symmetric);

fluid '(!*raise);
fluid '(!*lower);
fluid '(!*backtrace);
fluid '(!*redefmsg);
fluid '(!*rlqeinfcore);
fluid '(!*rlqestdans);
fluid '(!*smtplain);
fluid '(!*smtsilent);
fluid '(smt_assertionl!*);
fluid '(smt_oassertionl!*);
fluid '(smt_model!*);
fluid '(smt_unsatcore!*);
fluid '(smt_options!*);

smt_options!* := '(
   (!:model!-values . "root-of")
   (!:print!-success . true)
   (!:produce!-models . false)
   (!:produce!-unsat!-cores . false));

put('!:model!-values, 'smt_admissible!-values, '("root-of" "approximately" "raw"));
put('!:print!-success, 'smt_admissible!-values, '(true false));
put('!:produce!-models, 'smt_admissible!-values, '(false true));
put('!:produce!-models, 'smt_switch, 'smt_switch!-produce!-models);
put('!:produce!-unsat!-cores, 'smt_admissible!-values, '(false true));
put('!:produce!-unsat!-cores, 'smt_switch, 'smt_switch!-produce!-unsat!-cores);

procedure smt_switch!-produce!-models(truefalse);
   % At the point of calling, :produce-models is not truefalse yet.
   begin scalar !*redefmsg;
      if truefalse eq 'true and not !*rlqeinfcore then <<
         on1 'rlqeinfcore;
         return
      >>;
      if truefalse eq 'false and
         smt_getOption('!:produce!-unsat!-cores) eq 'false and
         !*rlqeinfcore
      then
         off1 'rlqeinfcore
   end;

procedure smt_switch!-produce!-unsat!-cores(truefalse);
   % At the point of calling, :produce-unsat-cores is not truefalse yet.
   begin scalar !*redefmsg;
      if truefalse eq 'true and not !*rlqeinfcore then <<
         on1 'rlqeinfcore;
         return
      >>;
      if truefalse eq 'false and
         smt_getOption('!:produce!-models) eq 'false and
         !*rlqeinfcore
      then
         off1 'rlqeinfcore
   end;

put('smt, 'psopfn, 'smt_smt);

procedure smt_smt(argl);
   begin scalar !*smtplain;
      !*smtplain := t;
      if not argl then <<
         if !*smtabout then
            smt_about();
         return smt_mainloop()
      >>;
      if cdr argl or not stringp car argl then
         rederr "usage: smt() or smt(""file"")";
      return smt_processRead car argl
   end;

operator smt_mainloop;

procedure smt_mainloop();
   begin scalar oc, !*redefmsg, w;
      oc := rl_set '(ofsf);
      w := errorset({'smt_mainloop1}, t, nil);
      if !*rlqeinfcore then
         off1 'rlqeinfcore;
      rl_set oc;
      if errorp w then
         nil
   end;

procedure smt_mainloop1();
   begin scalar raise, !*lower, form, w; integer pno;
      raise := !*raise;
      !*raise := !*lower := nil;
      smt_processReset() where !*smtsilent=t;
      pno := smt_setPrompt 1;
      form := smt_rread();
      while form neq '(exit) and form neq !$eof!$ do <<
         w := errorset({'smt_processForm, mkquote form}, nil, nil);
         if errorp w then
            smt_error emsg!* or "";
         if form = '(reset) then
            pno := 1;
         pno := smt_setPrompt pno;
         form := smt_rread()
      >>;
      !*raise := raise
   end;

procedure smt_setPrompt(pno);
   <<
      if !*smtprompt then
         setpchar lto_sconcat {lto_at2str pno, "% "}
      else
         setpchar "";
      pno + 1
   >>;

procedure smt_processForm(form);
   if eqcar(form, 'assert) then
      smt_processAssert cadr form
   else if eqcar(form, 'check!-sat) then
      smt_processCheckSat()
   else if eqcar(form, 'get!-model) then
      smt_processGetModel()
   else if eqcar(form, 'get!-unsat!-core) then
      smt_processGetUnsatCore()
   else if eqcar(form, 'get!-assertions) then
      smt_processGetAssertions()
   else if eqcar(form, 'reset) then
      smt_processReset()
   else if eqcar(form, 'reset!-assertions) then
      smt_processResetAssertions()
   else if eqcar(form, 'set!-logic) then
      smt_processSetLogic cadr form
   else if eqcar(form, 'read) then
      smt_processRead cadr form
   else if eqcar(form, 'eliminate!-quantifiers) then
      smt_processEliminateQuantifiers()
   else if eqcar(form, 'reduce!-eval) then
      smt_processReduceEval cadr form
   else if eqcar(form, 'reduce!-dump!-assertions) then
      smt_processReduceDumpAssertions cadr form
   else if eqcar(form, 'set!-option) then
      smt_processSetOption(cadr form, caddr form)
   else if eqcar(form, 'get!-option) then
      smt_processGetOption cadr form
   else if eqcar(form, 'quit) then
      quit
   else if eqcar(form, 'help) then
      smt_processHelp()
   else if eqcar(form, 'set!-info) then
      nil
   else if eqcar(form, 'declare!-const) then
      nil
   else if eqcar(form, 'declare!-fun) then
      nil
   else
      smt_error "";

procedure smt_processHelp();
   <<
      ioto_tprin2t "(assert t)                   add assertions";
      ioto_tprin2t "(declare-const f sigma)      ignored";
      ioto_tprin2t "(declare-fun f (sigma_1 ... sigma_n) sigma)";
      ioto_tprin2t "                             ignored";
      ioto_tprin2t "(check-sat)                  return sat, unsat, or unknown";
      ioto_tprin2t "(exit)                       exit the SMT-LIB REPL and return to Reduce";
      ioto_tprin2t "(get-assertions)             print current assertions";
      ioto_tprin2t "(get-model)                  get model after sat";
      ioto_tprin2t "(get-option o)               get current option value";
      ioto_tprin2t "(get-unsat-core)             get minimal unsat core after unsat";
      ioto_tprin2t "(reset)                      reset everything";
      ioto_tprin2t "(reset-assertions)           remove all assertions";
      ioto_tprin2t "(set-logic l)                set current logic to l in {NRA, QF_NRA}";
      terpri();
      ioto_tprin2t "(set-option :model-values <string>)";
      ioto_tprin2t "  ""root-of""                  use root expressions (default)";
      ioto_tprin2t "  ""approximately""            use p digit decimal approximations, default p=12";
      ioto_tprin2t "                             change with (reduce-eval (precision p))";
      ioto_tprin2t "  ""raw""                      show raw Redlog results (not SMT-LIB 2 compliant)";
      ioto_tprin2t "(set-option :produce-assertions <b_value>)";
      ioto_tprin2t "(set-option :produce-models <b_value>)";
      ioto_tprin2t "(set-option :produce-unsat-cores <b_value>)";
      terpri();
      ioto_tprin2t "(help)                       this help";
      ioto_tprin2t "(read <string>)              read an SMT-LIB2 file";
      ioto_tprin2t "(reduce-get-assertions <id>) print existing assertions as a Reduce assignment";
      ioto_tprin2t "(reduce-eval <form>)         evaluate <form> in Reduce Standard Lisp"
   >>;

procedure smt_processAssert(constraint);
   <<
      smt_assertionl!* := nconc(smt_assertionl!*, {smt_toRl constraint});
      smt_oassertionl!* := nconc(smt_oassertionl!*, {constraint});
      smt_model!* := 'unset;
      smt_unsatcore!* := 'unset;
      smt_success 'success
   >>;

%% procedure smt_processCheckSat();
%%    begin scalar w, tval, assl;
%%       assl := for each ass in smt_assertionl!* collect
%%       cl_simpl(ass, nil, -1);
%%       w := smt_processCheckSatAllPosP assl;
%%       if w then <<
%%       on1 'rlsifaco;
%%       w := rl_posqe(rl_ex(rl_smkn('and, assl), nil), nil);
%%       off1 'rlsifaco;
%%       {tval, smt_model!*} := {w, nil}
%%       >> else <<
%%               w := cl_qea(rl_ex(rl_smkn('and, assl), nil), nil);
%%               if null w then <<
%%          smt_prin2t 'unsat;
%%          return
%%               >>;
%%               tval . smt_model!* := car w
%%       >>;
%%       if tval eq 'true then
%%       smt_prin2t 'sat
%%       else if tval eq 'false then
%%       smt_prin2t 'unsat
%%       else
%%       smt_prin2t 'unknown
%%    end;

procedure smt_processEliminateQuantifiers();
   begin scalar w;
      off1 'rlqeinfcore;
      w := errorset({'ofsf_qe, {'rl_smkn, ''and, mkquote smt_assertionl!*}, nil}, t, !*backtrace);
      on1 'rlqeinfcore;
      if errorp w then
         return smt_error "";
      smt_success smt_fromRl car w
   end;

procedure smt_processCheckSat();
   if smt_getOption '!:produce!-unsat!-cores eq 'true then
      smt_processCheckSatPM()
   else if smt_getOption '!:produce!-models eq 'true then
      smt_processCheckSatPM()
   else
      smt_processCheckSat1();

procedure smt_processCheckSat1();
   begin scalar w;
      w := rl_qe(rl_ex(rl_smkn('and, smt_assertionl!*), nil), nil);
      smt_success if w eq 'true then 'sat else if w eq 'false then 'unsat else 'unkown
   end;

procedure smt_processCheckSatPUC();
   % unused
   begin scalar w, tval, model;
      w := cl_qea(rl_ex(rl_smkn('and, smt_assertionl!*), nil), nil);
      if null w then <<
         smt_success 'unsat;
         return
      >>;
      tval . model := car w;
      if tval eq 'true then <<
         if model then <<
            smt_model!* := model;
            smt_success 'sat
         >> else
            smt_success 'unknown
      >> else if tval eq 'false then
         smt_success 'unsat
      else
         smt_success 'unknown
   end;

procedure smt_processCheckSatPM();
   begin scalar w, constants, q, tval, model, !*rlqestdans;
      !*rlqestdans := t;
      w := rl_pnf rl_smkn('and, smt_assertionl!*);
      constants := cl_fvarl1 w;
      w := rl_ex(w, nil);
      q := rl_op w;
      if not rl_quap q then <<  % w is quanitifer-free and variable-free
         w := rl_simpl(w, nil, -1);
         if w eq 'true then
            smt_success 'sat
         else if w eq 'false then
            smt_success 'unsat
         else
            rederr {"error in check-sat, result is", w};
         return
      >>;
      w := cl_qea(w, nil);
      if null w then <<
         smt_model!* := nil;
         smt_success if q eq 'ex then 'unsat else 'sat;
         return
      >>;
      w := car w;
      tval := car w;
      if tval eq 'true then <<
         model := for each pr in cdr w join
            if car pr memq constants then {pr};
         smt_model!* := model;
         smt_success 'sat
      >> else if tval eq 'false then
         smt_success 'unsat
      else
         smt_success 'unknown
   end;

procedure smt_processCheckSatAllPosP(assl);
   begin scalar vl, pvl;
      for each ass in assl do <<
         vl := union(vl, rl_fvarl ass);
         if rl_op ass eq 'greaterp and sfto_varp ofsf_arg2l ass then
            pvl := lto_insertq(mvar ofsf_arg2l ass, pvl)
      >>;
      return length vl = length pvl
   end;

procedure smt_processGetModel();
   if smt_getOption '!:produce!-unsat!-cores eq 'true then
      smt_getModelPM()
   else if smt_getOption '!:produce!-models eq 'true then
      smt_getModelPM()
   else
      smt_error "option :produce-models is false";

procedure smt_getModelPM();
   if smt_model!* eq 'unset then
      smt_error "no model available"
   else
      smt_success!-model for each pr in smt_model!* collect
         smt_getModelPM1(pr, smt_getOption '!:model!-values);

procedure smt_getModelPM1(pr, mvoption);
   begin scalar iv, poly, a, b, c, d, sqrtd, r;
      if mvoption = "raw" then
         return smt_getModelForm(car pr, cdr pr);
      if cadr aex_ctx anu_dp cdr pr then
         return smt_getModelFloat pr;
      iv := anu_iv cdr pr;
      poly := sfto_sqfpartf numr aex_ex anu_dp cdr pr;
      if iv_lb iv = iv_rb iv then
         return smt_getModelForm(car pr,
            smt_fromRlTerm prepsq subf(poly, {car pr . prepsq iv_lb iv}));
      if ldeg poly = 1 then
         return smt_getModelForm(car pr, smt_fromRlTerm prepsq quotsq(
            !*f2q negf red poly, !*f2q lc poly));
      if ldeg poly = 2 then <<
         c := poly;
         a := lc c;
         c := red c;
         if not domainp c then <<
            b := lc c;
            c := red c
         >> else
            b := nil;
         d := addf(exptf(b, 2), negf multf(4, multf(a, c)));
         % we know d >= 0
         sqrtd := fix sqrt d;
         if sqrtd ** 2 = d then <<
            r := quotsq(!*f2q addf(negf b, sqrtd), !*f2q multf(2, a));
            if sfto_lessq(iv_lb iv, r) and sfto_lessq(r, iv_rb iv) then
               return smt_getModelForm(car pr, smt_fromRlTerm prepsq r);
            r := quotsq(!*f2q addf(negf b, negf sqrtd), !*f2q multf(2, a));
            % we know sfto_lessq(iv_lb iv, r) and sfto_lessq(r, iv_rb iv)
            return smt_getModelForm(car pr, smt_fromRlTerm prepsq r)
         >>
      >>;
      if mvoption = "approximately" then
         return smt_getModelFloat pr;
      return smt_getModelForm(car pr,
         {"@root-of", smt_fromRlTerm prepsq subf(poly, {car pr . '!_z}),
            smt_fromRlTerm prepsq iv_lb iv,
            smt_fromRlTerm prepsq iv_rb iv})
   end;

procedure smt_getModelFloat(pr);
   smt_getModelForm(car pr,
      {"@approximately", smt_floatToStr anu_evalfR cdr pr});

procedure smt_getModelForm(const, value);
   {'define!-fun, const, '!(!), '!Real, value};

procedure smt_floatToStr(x);
   if minusf numr simp x then
      {'!-, ioto_smaprin evalf0 {prepsq negsq simp x}}
   else
      ioto_smaprin x;

procedure smt_success!-model(model);
   if !*smtplain then <<
      ioto_tprin2t "(";
      for each form in model do <<
         ioto_tprin2t {"  (", nth(form, 1), " ", nth(form, 2),
            " ", nth(form, 3), " ", nth(form, 4)};
         ioto_tprin2t {"    ", nth(form, 5), ")"}
      >>;
      ioto_tprin2t ")"
   >> else
      smt_success model;

Procedure smt_getModelVerit();
   % unused
   begin scalar varl, model, mal, w;
      model := smt_model!*;
      if model eq 'unset then <<
         smt_error "";
         return
      >>;
%%       varl := cl_fvarl1 rl_smkn('and, smt_assertionl!*);
%%       for each e in model do
%%       varl := lto_delqip(car e, varl);
      for each e in model do <<
         w := smt_anuassoc(cdr e, mal);
         if w then
            cdr w := car e . cdr w
         else
            mal := (cdr e . {car e}) . mal;
      >>;
      w := smt_getOption '!:model!-values;
      smt_success for each pr in mal collect
         {cdr pr,
            if w = "interval" then
               {'interval, smt_rat2smt2 iv_lb anu_iv car pr, smt_rat2smt2 iv_rb anu_iv car pr}
            else if w = "hidden" then
               "()"
            else if w = "anu" then
               car pr
            else
               ioto_smaprin anu_evalfR car pr};
      varl := cl_fvarl1 rl_smkn('and, smt_assertionl!*);
      for each e in model do
         varl := lto_delqip(car e, varl);
      for each v in varl do
         model := {'equal, v, v} . model;
   end;

procedure smt_rat2smt2(q);
   {'!/, rat_numrn q, rat_denr q};

procedure smt_anuassoc(anu, al);
   if null al then
      nil
   else if eqn(anu_compare(anu, caar al), 0) then
      car al
   else
      smt_anuassoc(anu, cdr al);

procedure smt_rl2smtAns(smtform);
   if atom smtform then
      smt_rl2smtSym smtform
   else
      smt_rl2smtSym car smtform . for each arg in cdr smtform collect
         smt_rl2smtSym arg;

procedure smt_rl2smtSym(sym);
   begin scalar tal, w;
      tal := '((quotient . !/));
      w := atsoc(sym, tal);
      return if w then cdr w else sym
   end;

procedure smt_processGetUnsatCore();
   begin scalar core;
      core := smt_unsatcore!*;
      if core eq 'unset then <<
         smt_error "";
         return
      >>;
      smt_success core
   end;

procedure smt_processGetAssertions();
   <<
      smt_checkAlConsistency();
      smt_success!-assertions()
   >>;

procedure smt_checkAlConsistency();
   begin scalar al, oal;
      al := smt_assertionl!*;
      oal := smt_oassertionl!*;
      while al and oal and car al = smt_toRl car oal do <<
         al := cdr al;
         oal := cdr oal
      >>;
      if al or oal then
         smt_error ""
   end;

procedure smt_success!-assertions();
   if !*smtplain then <<
      ioto_tprin2t "(";
      for each a in smt_oassertionl!* do
         ioto_tprin2t {"  ", smt_fixFloats a};
      ioto_tprin2t ")"
   >> else
      smt_success smt_oassertionl!*;

procedure smt_fixFloats(form);
   if atom form then
      form
   else if eqcar(form, '!:dn!:) then
      ioto_smaprin form
   else
      car form . for each d in cdr form collect
         smt_fixFloats d;

procedure smt_processReset();
   <<
      smt_processReset1();
      smt_success 'success
   >>;

procedure smt_processReset1();
   begin scalar pr, o, v, !*smtsilent;
      !*smtsilent := t;
      smt_processResetAssertions();
      for each pr in smt_options!* do <<
         o := car pr;
         v := car get(o, 'smt_admissible!-values);
         smt_processSetOption(o, v)
      >>;
      smt_model!* := 'unset
   end;

procedure smt_processResetAssertions();
   <<
      smt_assertionl!* := smt_oassertionl!* := nil;
      smt_success 'success
   >>;

procedure smt_processReduceEval(form);
   prin2t eval form;

procedure smt_processReduceDumpAssertions(phi);
   <<
      assgnpri(setk(phi, rl_mk!*fof rl_smkn('and, smt_assertionl!*)), {phi}, 'only);
      terpri();
      smt_success 'success
   >>;

procedure smt_processSetOption(option, value);
   begin scalar pr, w;
      pr := atsoc(option, smt_options!*);
      if not pr or
         not (value member get(option, 'smt_admissible!-values))
      then <<
         smt_prin2t 'unsupported;
         return
      >>;
      if cdr pr neq value then <<
         if w := get(option, 'smt_switch) then apply(w, {value});
         cdr pr := value
      >>;
      smt_success 'success
   end;

procedure smt_processGetOption(option);
   begin scalar w;
      w := atsoc(option, smt_options!*);
      if not w then <<
         smt_prin2t 'unsupported;
         return
      >>;
      smt_success cdr w
   end;

procedure smt_processSetLogic(id);
   if id memq '(!N!R!A !Q!F_!N!R!A) then <<
      rl_set '(ofsf);
      smt_success 'success
   >> else if id eq '!Q!F_!N!I!A or id eq '!Q!F_!L!I!A then <<
      rl_set '(pasf);
      smt_success 'success
   >> else
      smt_error "unknown logic";

procedure smt_processRead(file);
   begin scalar ch;
      ch := open(file, 'input);
      rds ch;
      smt_mainloop();
      rds nil;
      close(ch)
   end;

procedure smt_success(response);
   if not !*smtsilent then <<
      if response eq 'success and smt_getOption '!:print!-success eq 'false then
         smt_prin2t ""
      else
         smt_prin2t response
   >>;

procedure smt_error(str);
   smt_print {'error, str};

procedure smt_print(item);
   if !*smtplain then
      (if item neq "" then print if item then item else "()")
   else <<
      lr_result();
      if item neq "" then prin if item then item else "()";
      lr_statcounter();
      prin2 0;
      lr_mode();
      prin2 2
   >>;

procedure smt_prin2t(item);
   if !*smtplain then
      (if item neq "" then prin2t if item then item else "()")
   else <<
      lr_result();
      if item neq "" then prin2 if item then item else "()";
      lr_statcounter();
      prin2 0;
      lr_mode();
      prin2 2
   >>;

procedure smt_getOption(option);
   begin scalar w;
      w := atsoc(option, smt_options!*);
      if not w then
         rederr {"smt_getOption:", option, "unkown"};
      return cdr w
   end;

asserted procedure smt_xpandlet(u: List): List;
   smt_xpandlet1(u, nil);

asserted procedure smt_xpandlet1(u: List, letal: Alist): List;
   begin scalar bl, w, oletal;
      if atom u then
         return if (w := atsoc(u, letal)) then cdr w else u;
      if not pairp u then
         rederr {"smt_xpandlet: something wrong:", u};
      if car u eq 'let then <<
         u := cdr u;
         if not u then
            rederr "smt_xpandlet: syntax error in let";
         oletal := letal;
         bl := pop u;
         for each b in bl do
            letal := (car b . smt_xpandlet1(cadr b, oletal)) . letal;
         if not u then
            rederr "smt_xpandlet: syntax error in let";
         w := smt_xpandlet1(pop u, letal);
         if u then
            rederr "smt_xpandlet: syntax error in let";
         for each b in bl do
            letal := cdr letal;
         return w
      >>;
      if car u eq '!:dn!: then
         return u;
      return car u . for each arg in cdr u collect smt_xpandlet1(arg, letal)
   end;

procedure smt_toRl(form);
   % SMT lib 2 read. Form is the argument of an assert form in the smt2 format.
   % Returns a quantifier-free formula.
   smt_toRl1 smt_xpandlet form;

procedure smt_toRl1(form);
   % SMT lib 2 read. Form is the argument of an assert form in the smt2 format.
   % Returns a quantifier-free formula.
   begin scalar op, w;
      if form memq '(true false) then
         return form;
      op := car form;
      if op eq '!=!> or op eq 'implies then
         op := 'impl;
      if op memq '(not impl) then
         return rl_mkn(op, for each arg in cdr form collect
            smt_toRl1 arg);
      if op memq '(and or) then
         return rl_smkn(op, for each arg in cdr form collect
            smt_toRl1 arg);
      if op eq 'exists then <<
         w := smt_toRl1 caddr form;
         for each l2 in reverse cadr form do
            w := rl_mkq('ex, car l2, w);
         return w
      >>;
      if op eq 'forall then <<
         w := smt_toRl1 caddr form;
         for each l2 in reverse cadr form do
            w := rl_mkq('all, car l2, w);
         return w
      >>;
      return rl_smt2ReadAt form
   end;

procedure smt_fromRl(f);
   begin scalar op;
      op := rl_op f;
      if rl_tvalp op then
         return op;
      if op memq '(not and or) then
         return op . for each subf in rl_argn f collect smt_fromRl subf;
      if op eq 'impl then
         return {'!=!>, smt_fromRl rl_arg2l f, smt_fromRl rl_arg2r f};
      if op eq 'repl then
         return {'!=!>, smt_fromRl rl_arg2r f, smt_fromRl rl_arg2l f};
      if op eq 'equiv then
         return {'and,
            {'!=!>, smt_fromRl rl_arg2l f, smt_fromRl rl_arg2r f},
            {'!=!>, smt_fromRl rl_arg2r f, smt_fromRl rl_arg2l f}};
      return smt_fromrlAt f
   end;

procedure smt_fromRlAt(f);
   begin scalar opal, op, w, lhs;
      op := rl_op f;
      lhs := prepf ofsf_arg2l f;
      if op eq 'neq then
         return {'not, smt_fromRlAt ofsf_0mk2('equal,ofsf_arg2l f)};
      opal := '((lessp . !<) (leq . !<!=) (greaterp . !>) (geq . !>!=) (equal . !=));
      op := if w := atsoc(op, opal) then cdr w else op;
      return {op, smt_fromRlTerm prepf ofsf_arg2l f, 0}
   end;

procedure smt_fromRlTerm(u);
   begin scalar op, argl, opal, w;
      if numberp u or idp u then
         return u;
      op . argl := u;
      if op eq 'expt then
         return smt_fromRlTerm('times . for i:=1:cadr argl collect car argl);
      opal := '((difference . !-) (minus . !-) (plus . !+) (times . !*) (quotient . !/));
      op := if w := atsoc(op, opal) then cdr w else op;
      return op . for each subt in argl collect smt_fromRlTerm subt
   end;

procedure smt_about();
   begin scalar w, l, l2, rev, rev2, date, time, year;
      w := get('smt, 'revision);
      l := lto_stringSplit(w, {'! , !$eol!$, cr!*, ff!*, tab!*});
      rev := compress cdr explode lto_string2id nth(l, 3);
      w := get('smtread, 'revision);
      l2 := lto_stringSplit(w, {'! , !$eol!$, cr!*, ff!*, tab!*});
      rev2 := lto_id2int lto_string2id nth(l2, 3);
      if rev2 > rev then <<
         l := l2;
         rev := rev2
      >>;
      date := nth(l, 4);
      time := nth(l, 5);
      year := car lto_stringSplit(date, '(!-));
      ioto_tprin2t {"Redlog SMT-LIB 2 REPL Revision ",
         rev, " of ", date, ", ", time};
      ioto_tprin2 {"(c) 2013-", year, " T. Sturm"};
      ioto_tprin2t "type (help) for help";
      terpri()
   end;

endmodule;

end;  % of file
