% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% (c) 2013 M. Kosta, T. Sturm
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

module z3;

!#if (memq 'csl lispsystem!*)

compiletime load!-package 'rltools;

macro procedure z3_interface(u);
   begin scalar myname, foreign, argtypel, rettype, lib, myargl, myname!-star, argn, a, foreign!-argl, p;
      u := cdr u;
      myname := eval pop u;
      foreign := eval pop u;
      argtypel := eval pop u;
      rettype := eval pop u;
      lib := eval pop u;
      myname!-star := lto_idconcat {myname, '!*};
      argn := length argtypel;
      for i := 1 : argn do <<
	 a := mkid('a, i);
	 myargl := a . myargl;
	 foreign!-argl := a . mkquote pop argtypel . foreign!-argl
      >>;
      if rettype then
	 foreign!-argl := mkquote rettype . foreign!-argl;
      myargl := reversip myargl;
      foreign!-argl := reversip foreign!-argl;
      p := {'fluid, mkquote {myname!-star}} . p;
      p := {'setq, myname!-star, {'z3_find!-foreign!-function, foreign, lib}} . p;
      p := {'put, mkquote myname, ''number!-of!-args, argn} . p;
      p := {'de, myname, myargl, 'call!-foreign!-function . myname!-star . foreign!-argl} . p;
      return 'progn . reversip p
   end;

procedure z3_find!-foreign!-function(name, lib);
   if lib then
      find!-foreign!-function(name, lib);

global '(int64_min!*);
global '(int64_max!*);

int64_min!* := -0x7fffffffffffffff - 1;
int64_max!* := 0x7fffffffffffffff;

fluid '(z3_libredz3!*);
fluid '(z3_redz3!*);

z3_libredz3!* := lto_sconcat {rltools_trunk(), "packages/foreign/z3/libredz3.so"};

errorset('(setq z3_redz3!* (open!-foreign!-library z3_libredz3!*)), nil, nil);

% Format: (reduce function name as identifier, C function name as string,
% argument type list, return value type, library path)
z3_interface('z3_cleanup_args, "redz3_cleanupArgs", nil, nil, 'z3_redz3!*);
z3_interface('z3_context_to_string, "Z3_context_to_string", '(int64), 'string, 'z3_redz3!*);
z3_interface('z3_del_config, "Z3_del_config", '(int64), nil, 'z3_redz3!*);
z3_interface('z3_del_context, "Z3_del_context", '(int64), nil, 'z3_redz3!*);
z3_interface('z3_init_args, "redz3_initArgs", '(int32), nil, 'z3_redz3!*);
z3_interface('z3_mk_app, "redz3_mkAppWithArgs", '(int64 string), 'int64, 'z3_redz3!*);
z3_interface('z3_mk_config, "Z3_mk_config", nil, 'int64, 'z3_redz3!*);
z3_interface('z3_mk_const, "Z3_mk_const", nil, 'int64, 'z3_redz3!*);
z3_interface('z3_mk_context, "Z3_mk_context", '(int64), 'int64, 'z3_redz3!*);
z3_interface('z3_mk_int, "redz3_mkInt", '(int64 int64), 'int64, 'z3_redz3!*);
z3_interface('z3_mk_int_var, "redz3_mkIntVar", '(int64 string), 'int64, 'z3_redz3!*);
z3_interface('z3_mk_simple_solver, "Z3_mk_simple_solver", '(int64), 'int64, 'z3_redz3!*);
z3_interface('z3_mk_solver, "Z3_mk_solver", '(int64), 'int64, 'z3_redz3!*);
z3_interface('z3_parse_smtlib2_string, "redz3_parse_smtlib2_string", '(int64 string), 'int64, 'z3_redz3!*);
z3_interface('z3_prin2_ast, "redz3_prin2Ast", '(int64 int64), nil, 'z3_redz3!*);
z3_interface('z3_push_to_args, "redz3_pushToArgs", '(int64), nil, 'z3_redz3!*);
z3_interface('z3_solver_assert, "Z3_solver_assert", '(int64 int64 int64), 'int64, 'z3_redz3!*);
z3_interface('z3_solver_check, "Z3_solver_check", '(int64 int64), 'int32, 'z3_redz3!*);
z3_interface('z3_solver_reset, "Z3_solver_reset", '(int64 int64), nil, 'z3_redz3!*);

procedure z3_check!-sat(ctx, slv);
   begin scalar res;
      res := z3_solver_check(ctx, slv);
      if res = 1 then
	 return 'sat;
      if res = -1 then
	 return 'unsat;
      return 'unknown
   end;

procedure z3_form2ast(ctx, form);
   % Only for integers now. We need a clear concept for various logics.
   begin scalar op, argl, w;
      if fixp form then <<
	 if form < int64_min!* or form > int64_max!* then
	    rederr {"integer", form, "out of range"};
      	 return z3_mk_int(ctx, form)
      >>;
      if form member '(true "true") then
	 return z3_mk_app(ctx, "true");
      if form member '(false "false") then
	 return z3_mk_app(ctx, "false");
      if idp form then
	 % TODO: Check if symbol!-name returns a string of length at most 256.
	 return z3_mk_int_var(ctx, symbol!-name form);
      if stringp form then
	 % TODO: Check if form is of length at most 256.
	 return z3_mk_int_var(ctx, form);
      if listp form then <<
	 argl := for each arg in cdr form collect
 	    z3_form2ast(ctx, arg);
	 % TODO: Test whether length argl is int32 or int64.
	 z3_init_args length argl;
	 for each arg in argl do
	    z3_push_to_args arg;
      	 op := car form;
	 % Arithmetic operators:
      	 if op member '(plus !+ "plus" "+") then <<
	    w := z3_mk_app(ctx, "plus");
	    z3_cleanup_args();
	    return w
	 >>;
	 if op member '(minus difference !- "minus" "difference") then <<
	    w := z3_mk_app(ctx, "minus");
	    z3_cleanup_args();
	    return w
	 >>;
	 if op member '(times !* "times" "*") then <<
	    w := z3_mk_app(ctx, "times");
	    z3_cleanup_args();
	    return w
	 >>;
	 if op member '(modc "modc") then <<
	    w := z3_mk_app(ctx, "mod");
	    z3_cleanup_args();
	    return w
	 >>;
	 if op member '(divc "divc") then <<
	    w := z3_mk_app(ctx, "div");
	    z3_cleanup_args();
	    return w
	 >>;
	 % Relations:
	 if op member '(neq "neq" "<>") then <<
	    w := z3_mk_app(ctx, "neq");
	    z3_cleanup_args();
	    return w
	 >>;
	 if op member '(equal != "equal" "=") then <<
	    w := z3_mk_app(ctx, "equal");
	    z3_cleanup_args();
	    return w
	 >>;
	 if op member '(geq "geq" ">=") then <<
	    w := z3_mk_app(ctx, "geq");
	    z3_cleanup_args();
	    return w
	 >>;
	 if op member '(leq "leq" "<=") then <<
	    w := z3_mk_app(ctx, "leq");
	    z3_cleanup_args();
	    return w
	 >>;
	 if op member '(greaterp "greaterp" ">") then <<
	    w := z3_mk_app(ctx, "greaterp");
	    z3_cleanup_args();
	    return w
	 >>;
	 if op member '(lessp "lessp" "<") then <<
	    w := z3_mk_app(ctx, "lessp");
	    z3_cleanup_args();
	    return w
	 >>;
	 if op member '(cong "cong") then <<
	    w := z3_mk_app(ctx, "cong");
	    z3_cleanup_args();
	    return w
	 >>;
	 if op member '(ncong "ncong") then <<
	    w := z3_mk_app(ctx, "ncong");
	    z3_cleanup_args();
	    return w
	 >>;
	 % Logical connectives:
	 if op member '(not "not") then <<
	    w := z3_mk_app(ctx, "not");
	    z3_cleanup_args();
	    return w
	 >>;
	 if op member '(and "and") then <<
	    w := z3_mk_app(ctx, "and");
	    z3_cleanup_args();
	    return w
	 >>;
	 if op member '(or "or") then <<
	    w := z3_mk_app(ctx, "or");
	    z3_cleanup_args();
	    return w
	 >>;
	 if op member '(impl "impl") then <<
	    w := z3_mk_app(ctx, "impl");
	    z3_cleanup_args();
	    return w
	 >>;
	 if op member '(equiv "equiv") then <<
	    w := z3_mk_app(ctx, "equiv");
	    z3_cleanup_args();
	    return w
	 >>
      >>;
      rederr {"syntax error in form", form}
   end;

!#endif

endmodule;  % z3

end;  % of file
