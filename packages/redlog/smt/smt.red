% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% (c) 2013 Thomas Sturm
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

module smtsupp;

% trunk/psl/dist/nonkernel/token-decls.sl

create!-package('(smt smtread), nil);

load!-package 'rltools;

global '(emsg!*);

fluid '(!*raise);
fluid '(!*lower);
fluid '(!*backtrace);
fluid '(smts_assertionl!*);
fluid '(smts_oassertionl!*);
fluid '(smts_model!*);
fluid '(!*smtsplain);

switch smtslog;

operator smt;

procedure smt();
   begin scalar !*smtsplain;
      !*smtsplain := t;
      terpri();
      ioto_tprin2t {"Reduce SMT-LIB 2.0 REPL ..."};
      smts_mainloop()
   end;

operator smts_mainloop;

procedure smts_mainloop();
   begin scalar raise, !*lower, form, w, pchar; integer pno;
      raise := !*raise;
      !*raise := !*lower := nil;
      smts_processReset();
      pno := 1;
      pchar := smts_setPrompt pno;
      smts_prin2t "";
      form := smts_rread();
      while form neq '(exit) do <<
	 w := errorset({'smts_processForm, mkquote form}, t, t);
      	 if errorp w then
	    smts_error();
	 pno := pno + 1;
	 smts_setPrompt pno;
	 form := smts_rread()
      >>;
      setpchar pchar;
      !*raise := raise
   end;

procedure smts_setPrompt(pno);
   setpchar lto_sconcat {lto_at2str pno, "% "};

procedure smts_processForm(form);
   if eqcar(form, 'assert) then
      smts_processAssert cadr form
   else if eqcar(form, 'check!-sat) then
      smts_processCheckSat()
   else if eqcar(form, 'get!-model) then
      smts_processGetModel()
   else if eqcar(form, 'print!-assertions) then
      smts_processPrintAssertions()
   else if eqcar(form, 'reset) then
      smts_processReset()
   else if eqcar(form, 'set!-logic) then
      smts_processSetLogic cadr form
   else if eqcar(form, 'reduce!-eval) then
      prin2t smts_processReduceEval cadr form
   else if eqcar(form, 'quit) then
      quit
   else if eqcar(form, 'help) then
      smts_processHelp()
   else
      smts_error();

procedure smts_processAssert(constraint);
   <<
      smts_assertionl!* := cl_smt2ReadForm constraint . smts_assertionl!*;
      smts_oassertionl!* := constraint . smts_oassertionl!*;
      smts_model!* := 'unset;
      smts_prin2t ""
   >>;

procedure smts_processCheckSat();
   begin scalar w, tval;
      !*rlqeinfcore:=T;
      w := cl_qea(rl_ex(rl_smkn('and, smts_assertionl!*), nil), nil);
      %!*rlqeinfcore:=nil;
      if null w then <<
	 smts_prin2t 'unsat;
	 return
      >>;
      {tval, smts_model!*} := car w;
      if tval eq 'true then
	 smts_prin2t 'sat
      else if tval eq 'false then
	 smts_prin2t 'unsat
      else
	 smts_prin2t 'unknown
   end;

procedure smts_processGetModel();
   begin scalar varl, model, mal, v, val, w;
      model := smts_model!*;
      if model eq 'unset then <<
	 smts_error();
	 return
      >>;
      varl := cl_fvarl1 rl_smkn('and, smts_assertionl!*);
      for each e in model do
	 varl := delqip(cadr e, varl);
      for each v in varl do
	 model := {'equal, v, v} . model;
      for each e in model do <<
	 {v, val} := cdr e;
	 w := assoc(val, mal);
	 if w then
	    cdr w := v . cdr w
	 else
	    mal := (val . {v}) . mal;
      >>;
      smts_prin2t for each pr in mal collect {cdr pr, smts_rl2smtAns car pr}
   end;

procedure smts_rl2smtAns(smtform);
   if atom smtform then
      smts_rl2smtSym smtform
   else
      smts_rl2smtSym car smtform . for each arg in cdr smtform collect
	 smts_rl2smtSym arg;

procedure smts_rl2smtSym(sym);
   begin scalar tal, w;
      tal := '((quotient . !/));
      w := atsoc(sym, tal);
      return if w then cdr w else sym
   end;

procedure smts_processPrintAssertions();
   if !*smtsplain then
      smts_processPrintAssertions1()
   else <<
      lr_result();
      smts_processPrintAssertions1();
      lr_statcounter();
      prin2 0;
      lr_mode();
      prin2 2
   >>;

procedure smts_processPrintAssertions1();
   <<
      smts_checkAlConsistency();
      for each a in smts_oassertionl!* do
      	 prin2t a
   >>;

procedure smts_checkAlConsistency();
   begin scalar al, oal;
      al := smts_assertionl!*;
      oal := smts_oassertionl!*;
      while al and oal and car al = cl_smt2ReadForm car oal do <<
	 al := cdr al;
	 oal := cdr oal
      >>;
      if al or oal then
	 smts_error()
   end;

procedure smts_processReset();
   <<
      smts_assertionl!* := smts_oassertionl!* := nil;
      smts_model!* := 'unset;
      smts_prin2t ""
   >>;

procedure smts_processReduceEval(form);
   eval form;

procedure smts_processSetLogic(id);
   if id eq '!Q!F_!N!R!A then <<
      rl_set '(ofsf);
      smts_prin2t ""
   >> else
      smts_error();

procedure smts_prin2t(item);
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

procedure smts_error();
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

procedure smts_processHelp();
   <<
      ioto_tprin2t "(exit)                 leave the SMT-LIB REPL and return to Reduce";
      ioto_tprin2t "(set-logic <symbol>)   <symbol> must be QF_NRA";
      ioto_tprin2t "(reduce-eval <form>)   evaluate <form> in the Standard Lisp underlying Reduce"
   >>;

endmodule;

end;  % of file
