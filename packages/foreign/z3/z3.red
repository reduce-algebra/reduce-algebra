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

fluid '(z3_libredz3!*);
fluid '(z3_redz3!*);
fluid '(z3_mk_config!*);
fluid '(z3_mk_context!*);
fluid '(z3_mk_simple_solver!*);
fluid '(z3_parse_smtlib2_string!*);
fluid '(z3_solver_assert!*);
fluid '(z3_solver_check!*);
fluid '(z3_solver_reset!*);
fluid '(z3_context_to_string!*);
fluid '(z3_del_config!*);
fluid '(z3_del_context!*);

z3_libredz3!* := lto_sconcat {rltools_trunk(), "packages/foreign/z3/libredz3.so"};

if filep z3_libredz3!* then <<
   z3_redz3!* := open!-foreign!-library z3_libredz3!*;

   z3_mk_config!* := find!-foreign!-function("Z3_mk_config", z3_redz3!*);
   z3_mk_context!* := find!-foreign!-function("Z3_mk_context", z3_redz3!*);
   z3_mk_simple_solver!* := find!-foreign!-function("Z3_mk_simple_solver", z3_redz3!*);
   z3_parse_smtlib2_string!* := find!-foreign!-function("redz3_parse_smtlib2_string", z3_redz3!*);
   z3_solver_assert!* := find!-foreign!-function("Z3_solver_assert", z3_redz3!*);
   z3_solver_check!* := find!-foreign!-function("Z3_solver_check", z3_redz3!*);
   z3_solver_reset!* := find!-foreign!-function("Z3_solver_reset", z3_redz3!*);
   z3_context_to_string!* := find!-foreign!-function("Z3_context_to_string", z3_redz3!*);
   z3_del_config!* := find!-foreign!-function("Z3_del_config", z3_redz3!*);
   z3_del_context!* := find!-foreign!-function("Z3_del_context", z3_redz3!*)
>>;

inline procedure z3_mk_config();
   call!-foreign!-function(z3_mk_config!*, 'int64);

inline procedure z3_mk_context(cfg);
   call!-foreign!-function(z3_mk_context!*, 'int64, cfg, 'int64);

inline procedure z3_mk_simple_solver(ctx);
   call!-foreign!-function(z3_mk_simple_solver!*, 'int64, ctx, 'int64);

inline procedure z3_parse_smtlib2_string(ctx, str);
   call!-foreign!-function(z3_parse_smtlib2_string!*, 'int64, ctx, 'string, str, 'int64);

inline procedure z3_solver_assert(ctx, slv, ast);
   call!-foreign!-function(z3_solver_assert!*, 'int64, ctx, 'int64, slv, 'int64, ast, 'int64);

procedure z3_solver_check(ctx, slv);
   begin scalar res;
      res := call!-foreign!-function(z3_solver_check!*, 'int64, ctx, 'int64, slv, 'int32);
      if res = 1 then
	 return 'sat;
      if res = -1 then
	 return 'unsat;
      return 'unknown
   end;

inline procedure z3_solver_reset(ctx, slv);
   call!-foreign!-function(z3_solver_reset!*, 'int64, ctx, 'int64, slv);

inline procedure z3_context_to_string(ctx);
   call!-foreign!-function(z3_context_to_string!*, 'int64, ctx, 'string);

inline procedure z3_del_config(cfg);
   call!-foreign!-function(z3_del_config!*, 'int64, cfg);

inline procedure z3_del_context(ctx);
   call!-foreign!-function(z3_del_context!*, 'int64, ctx);

!#endif

endmodule;  % z3

end;  % of file
