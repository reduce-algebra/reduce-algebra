% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 2013 T. Sturm
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

module ofsflp;

switch lpkeepfiles;

switch rlffi;

fluid '(!*rlgurobi);
fluid '(!*rlffi);

fluid '(lp_model!*);
fluid '(lp_modelcache!*);
fluid '(lp_varl!*);
fluid '(lp_dim!*);
fluid '(lp_rdim!*);
fluid '(lp_zdim!*);

global '(!*lp_cslp);
!*lp_cslp := memq('csl, lispsystem!*);

procedure lp_newmodel(n, m);
   if !*rlgurobi and !*rlffi and !*lp_cslp then
      gurobi_newmodel(n, m)
   else <<
      lp_model!* := lp_modelcache!* := nil;
      lp_varl!* := for i := 0:n+m-1 collect mkid('c, i);
      lp_dim!* := n+m;
      lp_rdim!* := n;
      lp_zdim!* := m
   >>;

procedure lp_addconstraint(rel, l, r);
   begin scalar lhs, vl;
      if !*rlgurobi and !*rlffi and !*lp_cslp then <<
      	 gurobi_addconstraintFast(rel, l, r);
      	 return
      >>;
      vl := lp_varl!*;
      lhs := 'plus . for each c in l collect {'times, c, pop vl};
      lp_modelcache!* :=  {rel, lhs, r} . lp_modelcache!*;
   end;

procedure lp_updatemodel();
   if !*rlgurobi and !*rlffi and !*lp_cslp then
      gurobi_updatemodel()
   else <<
      lp_model!* := nconc(lp_model!*, reversip lp_modelcache!*);
      lp_modelcache!* := nil
   >>;

procedure lp_negconstr1();
   if !*rlgurobi and !*rlffi and !*lp_cslp then
      gurobi_negconstr1()
   else if lp_model!* then
      lp_model!* := lp_negconstr car lp_model!* . cdr lp_model!*
   else if lp_modelcache!* then <<
      lp_modelcache!* := reversip lp_modelcache!*;
      lp_negconstr car lp_modelcache!* . cdr lp_modelcache!*;
      lp_modelcache!* := reversip lp_modelcache!*
   >>;

procedure lp_negconstr(c);
   {car c, 'plus . for each s in cdr cadr c collect {'times, -cadr s, caddr s}, caddr c};

procedure lp_delconstr1();
   if !*rlgurobi and !*rlffi and !*lp_cslp then
      gurobi_delconstr1()
   else if lp_model!* then
      lp_model!* := cdr lp_model!*
   else if lp_modelcache!* then
      lp_modelcache!* := reversip cdr reversip lp_modelcache!*;

procedure lp_freemodel();
   if !*rlgurobi and !*rlffi and !*lp_cslp then
      gurobi_freemodel()
   else
      lp_model!* := lp_modelcache!* := lp_varl!* := nil;

procedure lp_optimize();
   if !*rlgurobi and !*rlffi and !*lp_cslp then
      gurobi_optimize()
   else if !*rlgurobi and not (!*rlffi and !*lp_cslp) then
      lp_rungurobi()
   else
      lp_runlinalg();

procedure lp_optaction();
   if !*rlgurobi and !*rlffi and !*lp_cslp then
      "using Gurobi via FFI"
   else if !*rlgurobi and not (!*rlffi and !*lp_cslp) then
      "using Gurobi via file interface"
   else
      "using Reduce simplex";

procedure lp_rungurobi();
   <<
      lp_updatemodel();
      lp_rungurobi1(lp_model!*, lp_varl!*, lp_dim!*, lp_rdim!*)
   >>;

asserted procedure lp_rungurobi1(cl: List, vl: List, d: Integer, rd: Integer): List;
   begin scalar bfn, lp, sol, log, cl, call, res;
      bfn := lto_sconcat {"/tmp/reduce-lp-", lto_at2str getpid(), "-", getenv "USER", "-", lto_at2str random(2^16)};
      lp := lto_sconcat {bfn, ".lp"};
      sol := lto_sconcat {bfn, ".sol"};
      log := lto_sconcat {bfn, ".log"};
      lp_writeLp(lp, {'times, 0, car vl}, cl, vl, rd);
      call := lto_sconcat {"gurobi_cl ResultFile=", sol, " ", lp, " > ", log};
      system call;
      res := lp_readSol(sol, vl, d);
      if not !*lpkeepfiles then
	 for each fn in {lp, sol, log} do
	    system lto_sconcat {"rm -f ", fn};
      return res
   end;

asserted procedure lp_writeLp(fn: String, obj: List, cl: List, vl: List, rd: Integer);
   begin scalar oldprtch, w, oldsemic, oldecho, oldutf8, oldfancy;
      oldprtch := get('times, 'prtch);
      put('times, 'prtch, '! );
      oldsemic := semic!*;
      oldecho := !*echo;
      oldutf8 := !*utf8;
      oldfancy := !*fancy;
      !*echo := nil;
      !*utf8 := nil;
      !*fancy := nil;
      if fn then
      	 out fn;
      w := errorset({'lp_writeLp1, mkquote obj, mkquote cl, mkquote vl, mkquote rd}, nil, !*backtrace);
      if fn then
      	 shut fn;
      !*fancy := oldfancy;
      !*utf8 := oldutf8;
      !*echo := oldecho;
      semic!* := oldsemic;
      put('times, 'prtch, oldprtch);
      if errorp w then
	 rederr emsg!*
   end;

asserted procedure lp_writeLp1(obj: List, cl: List, vl: List, rd: Integer);
   <<
      prin2!* "Minimize";
      terpri!* nil;
      maprin obj;
      terpri!* nil;
      prin2!* "Subject To";
      terpri!* nil;
      for each c in cl do <<
	 maprin {car c, reval cadr c, caddr c};
	 terpri!* nil
      >>;
      prin2!* "Bounds";
      terpri!* nil;
      for each v in vl do <<
	 maprin {'geq, v, '!-Inf};
      	 terpri!* nil
      >>;
      for i := 1:rd do pop vl;
      if vl then <<
	 prin2!* "Integers";
      	 terpri!* nil;
	 for each rvl on vl do <<
	    prin2!* car rvl;
	    if cdr rvl then prin2!* " "
	 >>;
	 terpri!* nil
      >>;
      prin2!* "End";
      terpri!* nil
   >>;

asserted procedure lp_readSol(fn: String, vl: List, d: Integer);
   begin scalar ch, tok, res;
      ch := open(fn, 'input);
      rds ch;
      tok := read();
      if tok neq '!# then <<
	 rds nil;
	 close ch;
	 return 'infeasible
      >>;
      repeat tok := read() until tok = 0;
      res := for i := 1:d collect
	 read() . read();
      rds nil;
      close ch;
      res := for each v in vl collect
	 cdr atsoc(v, res);
      return res
   end;

procedure lp_runlinalg();
   lp_runlinalg1(lp_model!*, lp_varl!*, lp_dim!*);

asserted procedure lp_runlinalg1(cl: List, vl: List, d: Integer): List;
   begin scalar w, bounds;
      bounds := for each v in vl collect v . '((minus infinity) infinity);
      w := fs_simplex2('min, sc_simp 0, cl, bounds);
      if w eq 'infeasible then
	 return 'infeasible;
      return for each e in cdr w collect caddr e
   end;

procedure lp_dumpmodel();
   <<
      lp_updatemodel();
      if !*rlgurobi and !*rlffi and !*lp_cslp then
      	 gurobi_dumpmodel()
      else
	 lp_writeLp(nil, nil, lp_model!*, lp_varl!*, lp_rdim!*)
   >>;

endmodule;

end;  % of file
