module mma;  % Support for using Mathematica's QE as an external program

revision('mma, "$Id$");

copyright('mma, "(c) 2008-2017 T. Sturm");

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

fluid '(!*redefmsg);
fluid '(!*rlverbose);
fluid '(!*echo);
fluid '(!*time);
fluid '(!*backtrace);
fluid '(!*fancy);
fluid '(!*outputhandler);

global '(mma_call!*);
global '(mma_awk!*);

% This module automatically checks for executable
% /Applications/Mathematica.app/Contents/MacOS/MathKernel or
% /usr/local/bin/math, which are the common names for text-based Mathematica on
% OSX and Linux, repectively. This can be overridden with an environment
% variable MATHEMATICA. Note that at least on OSX, MathKernel must be called
% with its absolute path. Windows is not supported.

mma_awk!* := lto_sconcat {systo_get!-resource!-directory(), "/mma.awk"};

switch rlqefbmma;

rl_provideService rl_mathematica = mma_mathematica;

asserted procedure mma_mathematica(f: Formula): Formula;
   qepcad_generic(f, nil, "mma", 'mma_printer, 'mma_run);

asserted procedure mma_printer(f: Formula);
   mma_cadprint rl_pnf f;

asserted procedure mma_print(f: Formula);
   begin scalar w, svfancy, svpprifn, svprtch; integer ll;
      % Save relevant global values.
      svfancy := !*fancy;
      svpprifn := get('times, 'pprifn);
      svprtch := get('expt, 'prtch);
      ll := linelength(2^(32-5)-1);
      % Adapt to Mathematica-style printing.
      if svfancy then off1 'fancy;
      put('times, 'pprifn, 'qepcad_ppricadtimes);
      put('expt, 'prtch, '!^);
      mma_myscprint t;
      % Print formula.
      w := errorset({'mma_cadprint, mkquote f}, t, !*backtrace);
      % Restore global values.
      if svfancy then on1 'fancy;
      put('times, 'pprifn, svpprifn);
      put('expt, 'prtch, svprtch);
      mma_myscprint nil;
      linelength ll;
      if errorp w then rederr {"mma_print: could not print", f};
      return car w
   end;

asserted procedure mma_cadprint(f: Formula);
   begin scalar w, !*nat, outputhandler!*;
      terpri!* nil;
      prin2!* "InputForm[Resolve[";
      mma_cadprint1 f;
      prin2!* ",";
      w := cl_varl f;
      maprin('list . nconc(car w,cdr w));
      prin2!* ",";
      prin2!* "Reals]]";
      terpri!* t;
      prin2!* "TimeUsed[]";
      terpri!* nil
   end;

asserted procedure mma_cadprint1(f: Formula);
   begin scalar op,!*nat;
      op := rl_op f;
      if op eq 'ex then <<
	 prin2!* "Exists[";
	 prin2!* rl_var f;
	 prin2!* ",";
	 mma_cadprint1 rl_mat f;
	 prin2!* "]";
	 return nil
      >>;
      if op eq 'all then <<
	 prin2!* "ForAll[";
	 prin2!* rl_var f;
	 prin2!* ",";
	 mma_cadprint1 rl_mat f;
	 prin2!* "]";
	 return nil
      >>;
      mma_cadprint2 f
   end;

asserted procedure mma_cadprint2(f: Formula);
   begin scalar op, argl, outputhandler!*;
      op := rl_op f;
      if rl_cxp op then <<
	 if rl_tvalp op then <<
	    mma_cadprinttval f;
	    return nil
	 >>;
	 prin2!* "(";
	 argl := rl_argn f;
	 mma_cadprint2(car argl);
	 for each x in cdr argl do <<
	    mma_cadprintop op;
	    mma_cadprint2 x
	 >>;
	 prin2!* ")";
	 return nil
      >>;
      maprin prepf ofsf_arg2l f;
      mma_cadprintop op;
      prin2!* "0"
   end;

asserted procedure mma_cadprinttval(tv: Id);
   if tv eq 'true then
      prin2!* "True"
   else <<
      assert(tv eq 'false);
      prin2!* "False"
   >>;

asserted procedure mma_cadprintop(op: Id);
   <<
      prin2!* " ";
      prin2!*(cdr atsoc(op,'((equal . "==") (neq . "!=") (lessp . "<")
      	 (greaterp . ">") (geq . ">=") (leq . "<=") (or . "||") (and . "&&")
      	    (impl . nil) (equiv . nil))) or
 	 rederr {"cannot translate",op,"to mma"});
      prin2!* " "
   >>;

% This should be done with an outputhandler
copyd('mma_scprint!-orig, 'scprint);

asserted procedure mma_scprint(u: List, n: Integer);
   <<
      mma_scprint!-orig(u, n);
      prin2 "\"
   >>;

asserted procedure mma_myscprint(flg: Boolean);
   copyd('scprint, if flg then 'mma_scprint else 'mma_scprint!-orig)
      where !*redefmsg=nil;

asserted procedure mma_run(fn1: String, fn2: String);
   begin scalar vb, tm, call, mma;
      mma := getenv("MATHEMATICA");
      if not mma then
	 if system "test -x /Applications/Mathematica.app/Contents/MacOS/MathKernel" = 0 then
	    mma := "/Applications/Mathematica.app/Contents/MacOS/MathKernel"  % Mac OSX
	 else if system "test -x /usr/local/bin/math" = 0 then
	    mma := "/usr/local/bin/math"  % Linux
	 else
	    rederr "no executable Mathematica found";
      vb := lto_at2str !*rlverbose;
      tm := lto_at2str !*time;
      call := lto_sconcat {mma, " < ",fn1,
	 " | awk -v rf=", fn2, " -v verb=", vb, " -v time=", tm,
	 " -f ",mma_awk!*};
      if !*rlverbose then
	 ioto_tprin2t lto_sconcat {"+++ calling ",call};
      system call
   end;

endmodule;

end;
