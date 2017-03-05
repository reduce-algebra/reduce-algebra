module smt;  % An SMTLIB 2.0 REPL

revision('smt, "$Id$");

copyright('smt, "(c) 2013-2017 T. Sturm");

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

global '(nxtsym!*);
global '(!$eof!$);
global '(emsg!*);

fluid '(!*raise);
fluid '(!*lower);
fluid '(!*backtrace);
fluid '(smt_assertionl!*);
fluid '(smt_oassertionl!*);
fluid '(smt_model!*);
fluid '(!*smtsplain);

switch smtslog;
switch smtsilent;

operator smt;

procedure smt();
   begin scalar !*smtsplain;
      !*smtsplain := t;
      if not !*smtsilent then <<
      	 terpri();
      	 ioto_tprin2t {"Reduce SMT-LIB 2.0 REPL ..."}
      >>;
      smt_mainloop()
   end;

operator smt_mainloop;

procedure smt_mainloop();
   begin scalar oc;
      oc := rl_set '(ofsf);
      on1 'rlqeinfcore;
      errorset({'smt_mainloop1}, t, !*backtrace);
      off1 'rlqeinfcore;
      rl_set oc
   end;

procedure smt_mainloop1();
   begin scalar raise, !*lower, form, w, pchar; integer pno;
      raise := !*raise;
      !*raise := !*lower := nil;
      smt_processReset();
      pno := 1;
      pchar := smt_setPrompt pno;
      smt_prin2t "";
      form := smt_rread();
      while form neq '(exit) and form neq !$eof!$ do <<
	 w := errorset({'smt_processForm, mkquote form}, t, t);
      	 if errorp w then
	    smt_error();
	 pno := pno + 1;
	 smt_setPrompt pno;
	 form := smt_rread()
      >>;
      setpchar pchar;
      !*raise := raise
   end;

procedure smt_setPrompt(pno);
   if !*smtsilent then
      setpchar ""
   else
      setpchar lto_sconcat {lto_at2str pno, "% "};

procedure smt_processForm(form);
   if eqcar(form, 'assert) then
      smt_processAssert cadr form
   else if eqcar(form, 'check!-sat) then
      smt_processCheckSat()
   else if eqcar(form, 'get!-model) then
      smt_processGetModel()
   else if eqcar(form, 'print!-assertions) then
      smt_processPrintAssertions()
   else if eqcar(form, 'reset) then
      smt_processReset()
   else if eqcar(form, 'set!-logic) then
      smt_processSetLogic cadr form
   else if eqcar(form, 'read) then
      smt_processRead cadr form
   else if eqcar(form, 'reduce!-eval) then
      smt_processReduceEval cadr form
   else if eqcar(form, 'reduce!-dump!-assertions) then
      smt_processReduceDumpAssertions cadr form
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
      smt_error();

procedure smt_processAssert(constraint);
   <<
      smt_assertionl!* := cl_smt2ReadForm constraint . smt_assertionl!*;
      smt_oassertionl!* := constraint . smt_oassertionl!*;
      smt_model!* := 'unset;
      smt_prin2t ""
   >>;

%% procedure smt_processCheckSat();
%%    begin scalar w, tval, assl;
%%       assl := for each ass in smt_assertionl!* collect
%% 	 cl_simpl(ass, nil, -1);
%%       w := smt_processCheckSatAllPosP assl;
%%       if w then <<
%% 	 on1 'rlsifaco;
%% 	 w := rl_posqe(rl_ex(rl_smkn('and, assl), nil), nil);
%% 	 off1 'rlsifaco;
%% 	 {tval, smt_model!*} := {w, nil}
%%       >> else <<
%%       	 w := cl_qea(rl_ex(rl_smkn('and, assl), nil), nil);
%%       	 if null w then <<
%% 	    smt_prin2t 'unsat;
%% 	    return
%%       	 >>;
%%       	 tval . smt_model!* := car w
%%       >>;
%%       if tval eq 'true then
%% 	 smt_prin2t 'sat
%%       else if tval eq 'false then
%% 	 smt_prin2t 'unsat
%%       else
%% 	 smt_prin2t 'unknown
%%    end;

procedure smt_processCheckSat();
   begin scalar w, tval;
      w := cl_qea(rl_ex(rl_smkn('and, smt_assertionl!*), nil), nil);
      if null w then <<
	 smt_prin2t 'unsat;
	 return
      >>;
      tval . smt_model!* := car w;
      if tval eq 'true then
	 smt_prin2t 'sat
      else if tval eq 'false then
	 smt_prin2t 'unsat
      else
	 smt_prin2t 'unknown
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
   begin scalar varl, model, mal, w;
      model := smt_model!*;
      if model eq 'unset then <<
	 smt_error();
	 return
      >>;
      varl := cl_fvarl1 rl_smkn('and, smt_assertionl!*);
      for each e in model do
	 varl := delqip(car e, varl);
      for each v in varl do
	 model := {'equal, v, v} . model;
      for each e in model do <<
	 w := assoc(cdr e, mal);
	 if w then
	    cdr w := car e . cdr w
	 else
	    mal := (cdr e . {car e}) . mal;
      >>;
      smt_prin2t for each pr in mal collect {cdr pr, smt_rl2smtAns car pr}
   end;

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

procedure smt_processPrintAssertions();
   if !*smtsplain then
      smt_processPrintAssertions1()
   else <<
      lr_result();
      smt_processPrintAssertions1();
      lr_statcounter();
      prin2 0;
      lr_mode();
      prin2 2
   >>;

procedure smt_processPrintAssertions1();
   <<
      smt_checkAlConsistency();
      for each a in smt_oassertionl!* do
      	 prin2t a
   >>;

procedure smt_checkAlConsistency();
   begin scalar al, oal;
      al := smt_assertionl!*;
      oal := smt_oassertionl!*;
      while al and oal and car al = cl_smt2ReadForm car oal do <<
	 al := cdr al;
	 oal := cdr oal
      >>;
      if al or oal then
	 smt_error()
   end;

procedure smt_processReset();
   <<
      smt_assertionl!* := smt_oassertionl!* := nil;
      smt_model!* := 'unset;
      smt_prin2t ""
   >>;

procedure smt_processReduceEval(form);
   prin2t eval form;

procedure smt_processReduceDumpAssertions(phi);
   <<
      assgnpri(setk(phi, rl_mk!*fof rl_smkn('and, smt_assertionl!*)), {phi}, 'only);
      terpri();
      smt_prin2t ""
   >>;

procedure smt_processSetLogic(id);
   if id eq '!Q!F_!N!R!A then <<
      rl_set '(ofsf);
      smt_prin2t ""
   >> else if id eq '!Q!F_!N!I!A or id eq '!Q!F_!L!I!A then <<
      rl_set '(pasf);
      smt_prin2t ""
   >> else
      smt_error();

procedure smt_prin2t(item);
   if !*smtsplain then
      (if item neq "" then prin2t if item then item else "()")
   else <<
      lr_result();
      if item neq "" then prin2 if item then item else "()";
      lr_statcounter();
      prin2 0;
      lr_mode();
      prin2 2
   >>;

procedure smt_processRead(file);
   begin scalar ch;
      ch := open(file, 'input);
      rds ch;
      smt_mainloop();
      rds nil;
      close(ch)
   end;

procedure smt_error();
   if !*smtsplain then
      prin2t "error - there is help avilable via ""(help)"""
   else <<
      lr_result();
      prin2 "error";
      lr_statcounter();
      prin2(-1);
      lr_mode();
      prin2 2
   >>;

procedure smt_processHelp();
   <<
      ioto_tprin2t "(exit)                 leave the SMT-LIB REPL and return to Reduce";
      ioto_tprin2t "(set-logic <symbol>)   <symbol> must be QF_NRA";
      ioto_tprin2t "(reduce-eval <form>)   evaluate <form> in the Standard Lisp underlying Reduce"
   >>;

endmodule;

end;  % of file
