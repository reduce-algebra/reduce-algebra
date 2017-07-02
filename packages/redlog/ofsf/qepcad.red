module qepcad;

revision('qepcad, "$Id$");

copyright('qepcad, "(c) 1995-2009 A. Dolzmann and T. Sturm, 2010-2017 T. Sturm");

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

% This does not work under Windows. This is not too critical, because Qepcad B
% will hardly compile under window. However, runtime test should be added to
% detrmine early whether there is an executable qepcad in the path. Furthermore
% it would be nice not to overwrite possibly exisiting user file, although
% filenames are quite special, and everything takes places in /tmp.

fluid '(!*rlverbose);
fluid '(!*echo);
fluid '(!*time);
fluid '(!*backtrace);
fluid '(!*nat);
fluid '(!*fancy);
fluid '(!*outputhandler);

global '(qepcad_qepcad!*);
global '(qepcad_slfq!*);
global '(qepcad_tmpdir!*);
global '(qepcad_awk!*);

qepcad_qepcad!* := "qepcad";
qepcad_slfq!* := "slfq";
qepcad_tmpdir!* := "/tmp/";
qepcad_awk!* := lto_sconcat {systo_get!-resource!-directory(), "/", "qepcad.awk"};

switch rlqefbqepcad;
switch rlqefbslfq;
switch rlslfqvb;

on1 'rlqefbslfq;

rl_provideService rl_qepcad = qepcad_qepcad;

asserted procedure qepcad_qepcad(f: Formula, N: Integer, L: Integer): Formula;
   qepcad_generic(f, {N, L}, "qepcad", 'qepcad_printer, 'qepcad_run);

rl_provideService rl_slfq = qepcad_slfq;

asserted procedure qepcad_slfq(f: Formula, N: Integer, L: Integer): Formula;
   qepcad_generic(f, {N, L}, "slfq", function(lambda x; mathprint rl_prepfof x), 'qepcad_runSlfq);

asserted procedure qepcad_generic(f: Formula, argl: List, stem: String, printer: Applicable, runner: Applicable);
   begin scalar fn1, fn2, result;
      fn1 . fn2 := qepcad_fn stem;
      qepcad_dump(f, fn1, printer);
      apply(runner, append(argl, {fn1, fn2}));
      result := qepcad_readResult fn2;
      system lto_sconcat {"rm -f ", fn1, " ", fn2};
      if null result then
	 lprim "external computation failed";
      return rl_simp result or f
   end;

asserted procedure qepcad_fn(stem: String): String;
   begin scalar bname;
      bname := lto_sconcat {qepcad_tmpdir!*, "rl", stem,
      	 "-", getenv "USER" or "unknown", "-", lto_at2str getpid()};
      return lto_sconcat {bname, ".", stem} . lto_sconcat {bname, ".red"}
   end;

asserted procedure qepcad_dump(f: Formula, fn: String, printer: Applicable);
   begin scalar w;
      if fn = "" then <<
	 apply(printer, {f});
	 return
      >>;
      if !*rlverbose then ioto_tprin2 {"+++ creating ", fn, " ... "};
      out fn;
      w := errorset({printer, mkquote f}, t, !*backtrace);
      shut fn;
      if errorp w then
 	 rederr {"qepcad_dump: problem dumping", f, "using", printer};
      if !*rlverbose then ioto_prin2t "done"
   end;

asserted procedure qepcad_printer(f: Formula);
   begin scalar ff, fl, bl, l;
      ff := f := cl_pnf f;
      % Apparently, Qepcad wants the bound variables in the order as they appear
      % in the prenex block. I am not certain about quanified variables that do
      % not occur in the sense of of logic.
      while rl_quap rl_op ff do <<
	 push(rl_var ff, bl);
	 ff := rl_mat ff
      >>;
      bl := reversip bl;
      fl := cl_fvarl1 f;
      l := append(fl, bl);
      prin2t "[Qepcad B input, automatically generated in Reduce/Redlog";
      prin2t lto_sconcat {" by ", getenv("USER") or "unknown", " on ", date()};
      prin2t " http://reduce-algebra.sourceforge.net/";
      prin2t " http://www.redlog.eu/]";
      prin2 "(";
      prin2 car l;
      for each x in cdr l do << prin2 ","; prin2 x >>;
      prin2t ")";
      prin2t length fl;
      qepcad_print f;
      prin2t ".";
      prin2t "finish"
   end;

asserted procedure qepcad_print(f: Formula);
   begin scalar w, svfancy, svpprifn, svprtch;
      % Save relevant global values.
      svfancy := !*fancy;
      svpprifn := get('times, 'pprifn);
      svprtch := get('expt, 'prtch);
      % Adapt to Qepcad-style printing.
      if svfancy then off1 'fancy;
      put('times, 'pprifn, 'qepcad_ppricadtimes);
      put('expt, 'prtch, '!^);
      % Print formula.
      w := errorset({'qepcad_cadprint1, mkquote f}, t, !*backtrace);
      % Restore global values.
      if svfancy then on1 'fancy;
      put('times, 'pprifn, svpprifn);
      put('expt, 'prtch, svprtch);
      if errorp w then rederr {"qepcad_print: could not print", f};
      return car w
   end;

asserted procedure qepcad_cadprint1(f: Formula);
   begin scalar !*nat;
      terpri!* nil;
      while rl_op f memq '(ex all) do <<
	 prin2!* "(";
	 prin2!* if rl_op f eq 'ex then "E" else "A";
	 prin2!* rl_var f;
	 prin2!* ") ";
	 f := rl_mat f
      >>;
      prin2!* "[";
      qepcad_cadprint2 f;
      prin2!* "]";
      terpri!* nil
   end;

asserted procedure qepcad_cadprint2(f: Formula);
   begin scalar op, argl, outputhandler!*;
      op := rl_op f;
      if rl_cxp op then <<
	 if rl_tvalp op then <<
	    qepcad_cadprinttval f;
	    return nil
	 >>;
	 prin2!* "[";
	 argl := rl_argn f;
	 qepcad_cadprint2(car argl);
	 for each x in cdr argl do <<
	    qepcad_cadPrintRel op;
	    qepcad_cadprint2 x
	 >>;
	 prin2!* "]";
	 return nil
      >>;
      maprin prepf ofsf_arg2l f;
      qepcad_cadPrintRel op;
      prin2!* "0"
   end;

asserted procedure qepcad_cadprinttval(tv: Id);
   if tv eq 'true then <<
      prin2!* "0";
      qepcad_cadPrintRel 'equal;
      prin2!* "0"
   >> else <<
      assert(tv eq 'false);
      prin2!* "0";
      qepcad_cadPrintRel 'neq;
      prin2!* "0"
   >>;

asserted procedure qepcad_cadPrintRel(op: Id);
   <<
      prin2!* " ";
      prin2!* if op eq 'equal then
	 "="
      else if op eq 'neq then
	 "/="
      else if op eq 'lessp then
	 "<"
      else if op eq 'greaterp then
	 ">"
      else if op eq 'leq then
	 "<="
      else if op eq 'geq then
	 ">="
      else if op eq 'or then
	 "\/"
      else if op eq 'and then
	 "/\"
      else if op eq 'impl then
	 "==>"
      else if op eq 'equiv then
	 "<==>";
      prin2!* " "
   >>;

asserted procedure qepcad_ppricadtimes(f: Id, n: Integer);
   begin scalar w, outputhandler!*;
      w := (get(car f,'infix) < n);
      if w then prin2!* "(";
      maprin cadr f;
      for each x in cddr f do << prin2!* " "; maprin x >>;
      if w then prin2!* ")"
   end;

asserted procedure qepcad_run(N: Integer, L: Integer, fn1: String, fn2: String);
   begin scalar narg, larg, call, vb, tm;
      narg := lto_sconcat {"+N",lto_at2str(N * 10^6)," "};
      larg := lto_sconcat {"+L",lto_at2str(L * 10^3)," "};
      vb := lto_at2str !*rlverbose;
      tm := lto_at2str !*time;
      call := lto_sconcat {
	 qepcad_qepcad!*, " ", narg, larg, "< ", fn1,
	 " | awk -v rf=", fn2,
	 " -v verb=", vb,
	 " -v time=", tm,
	 " -v slfqvb=nil -v name=QEPCAD -f ", qepcad_awk!*};
      if !*rlverbose then
	 ioto_tprin2t lto_sconcat {"+++ calling ",call};
      system call
   end;

asserted procedure qepcad_runSlfq(N: Integer, L: Integer, fn1: String, fn2: String);
   begin scalar narg, larg, call, vb, tm, svb;
      % In contrast to Qepcad, slfq multiplies N by 10^6 itself.
      narg := lto_sconcat {"-N ",lto_at2str(N), " "};
      larg := lto_sconcat {"-P ",lto_at2str(L * 10^3), " "};
      vb := lto_at2str !*rlverbose;
      tm := lto_at2str !*time;
      svb := lto_at2str !*rlslfqvb;
      call := lto_sconcat {
	 qepcad_slfq!*, " ", narg, larg, "< ", fn1,
	 " 2> /dev/null | awk -v rf=", fn2,
	 " -v verb=", vb, " -v time=", tm, " -v slfqvb=", svb,
	 " -v name=SLFQ -f ", qepcad_awk!*};
      if !*rlverbose then
	 ioto_tprin2t lto_sconcat {"+++ calling ",call};
      system call
   end;

asserted procedure qepcad_readResult(fn: String): Formula;
   begin scalar svecho, svsemic, fh, w;
      svsemic := semic!*;  % not quite clear about this
      svecho := !*echo;
      !*echo := nil;
      fh := rds open(fn,'input);
      w := errorset({'xread, t}, nil, !*backtrace);
      close rds fh;
      semic!* := svsemic;
      !*echo := svecho;
      if errorp w then rederr {"qepcad_readResult: bad formula in file", fn};
      return car w
   end;

endmodule;

end;
