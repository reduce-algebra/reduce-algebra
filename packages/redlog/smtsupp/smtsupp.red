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

global '(!*raise);
fluid '(!*lower);
fluid '(smts_assertionl!*);
fluid '(smts_oassertionl!*);
fluid '(smts_model!*);

switch smtsplain;
switch smtslog;

operator smts_mainloop;

procedure smts_mainloop();
   begin scalar form, raise, !*lower;
      raise := !*raise;
      !*raise := !*lower := nil;  % should use errorset here
      smts_processReset();
      smts_prin2t nil;
      form := read();
      while form neq '(exit) do <<
	 smts_processForm form;
	 form := read()
      >>;
      !*raise := raise
   end;

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
   else if eqcar (form, 'set!-logic) then
      smts_processSetLogic cadr form
   else
      smts_error();

procedure smts_processAssert(constraint);
   <<
      smts_assertionl!* := cl_smt2ReadForm constraint . smts_assertionl!*;
      smts_oassertionl!* := constraint . smts_oassertionl!*;
      smts_model!* := nil;
      smts_prin2t nil
   >>;

procedure smts_processCheckSat();
   begin scalar tval;
      {tval, smts_model!*} := car rl_qea(rl_ex(rl_smkn('and, smts_assertionl!*), nil), nil);
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
      if null model then
	 smts_error();
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
      smts_prin2t for each pr in mal collect {cdr pr, car pr}
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
      smts_assertionl!* := smts_oassertionl!* := smts_model!* := nil;
      smts_prin2t nil
   >>;

procedure smts_processSetLogic(id);
   if id eq '!Q!F_!N!R!A then <<
      rl_set '(ofsf);
      smts_prin2t nil
   >> else
      smts_error();

procedure smts_prin2t(item);
   if !*smtsplain then
      (if item then prin2t item)
   else <<
      lr_result();
      if item then prin2 item;
      lr_statcounter();
      prin2 0;
      lr_mode();
      prin2 2
   >>;

procedure smts_error();
   if !*smtsplain then
      prin2t "error"
   else <<
      lr_result();
      prin2 "error";
      lr_statcounter();
      prin2(-1);
      lr_mode();
      prin2 2
   >>;

endmodule;

end;  % of file
