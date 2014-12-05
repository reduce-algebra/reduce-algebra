% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% (c) 2013 T. Sturm
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

module gurobi;

#if (memq 'csl lispsystem!*)

fluid '(gurobi_libredgurobi!*);
fluid '(gurobi_redgrb!*);
fluid '(gurobi_newmodel!*);
fluid '(gurobi_addconstr!*);
fluid '(gurobi_addconstrFast!*);
fluid '(gurobi_numVars!*);
fluid '(gurobi_delconstr1!*);
fluid '(gurobi_delconstr!*);
fluid '(gurobi_negconstr1!*);
fluid '(gurobi_negconstr!*);
fluid '(gurobi_updatemodel!*);
fluid '(gurobi_write!*);
fluid '(gurobi_newDoubleArray!*);
fluid '(gurobi_setDoubleArray!*);
fluid '(gurobi_freeDoubleArray!*);
fluid '(gurobi_pushToVal!*);
fluid '(gurobi_optimize!*);
fluid '(gurobi_getSol!*);
fluid '(gurobi_freemodel!*);

gurobi_libredgurobi!* := lto_sconcat {rltools_trunk(), "packages/foreign/gurobi/libredgurobi.so"};

if filep gurobi_libredgurobi!* then <<
   gurobi_redgurobi!* := open!-foreign!-library gurobi_libredgurobi!*;

   gurobi_newmodel!* := find!-foreign!-function("gurobi_newmodel", gurobi_redgurobi!*);
   gurobi_addconstr!* := find!-foreign!-function("gurobi_addconstr", gurobi_redgurobi!*);
   gurobi_addconstrFast!* := find!-foreign!-function("gurobi_addconstrFast", gurobi_redgurobi!*);
   gurobi_numVars!* := find!-foreign!-function("gurobi_numVars", gurobi_redgurobi!*);
   gurobi_negconstr1!* := find!-foreign!-function("gurobi_negconstr1", gurobi_redgurobi!*);
   gurobi_negconstr!* := find!-foreign!-function("gurobi_negconstr", gurobi_redgurobi!*);
   gurobi_delconstr1!* := find!-foreign!-function("gurobi_delconstr1", gurobi_redgurobi!*);
   gurobi_delconstr!* := find!-foreign!-function("gurobi_delconstr", gurobi_redgurobi!*);
   gurobi_updatemodel!* := find!-foreign!-function("gurobi_updatemodel", gurobi_redgurobi!*);
   gurobi_write!* := find!-foreign!-function("gurobi_write", gurobi_redgurobi!*);
   gurobi_newDoubleArray!* := find!-foreign!-function("gurobi_newDoubleArray", gurobi_redgurobi!*);
   gurobi_setDoubleArray!* := find!-foreign!-function("gurobi_setDoubleArray", gurobi_redgurobi!*);
   gurobi_freeDoubleArray!* := find!-foreign!-function("gurobi_freeDoubleArray", gurobi_redgurobi!*);
   gurobi_pushToVal!* := find!-foreign!-function("gurobi_pushToVal", gurobi_redgurobi!*);
   gurobi_optimize!* := find!-foreign!-function("gurobi_optimize", gurobi_redgurobi!*);
   gurobi_getSol!* := find!-foreign!-function("gurobi_getSol", gurobi_redgurobi!*);
   gurobi_freemodel!* := find!-foreign!-function("gurobi_freemodel", gurobi_redgurobi!*)
>>;

procedure gurobi_newmodel(n, m);
   % [n] real variables plus [m] integer variables, all unbounded from below.
   call!-foreign!-function(gurobi_newmodel!*, 'int32, n, 'int32, m);

inline procedure gurobi_newDoubleArray(n);
   call!-foreign!-function(gurobi_newDoubleArray!*, 'int32, n, 'int64);

inline procedure gurobi_setDoubleArray(a, i, x);
   call!-foreign!-function(gurobi_setDoubleArray!*, 'int64, a, 'int32, i, 'double, x);

inline procedure gurobi_freeDoubleArray(a);
   call!-foreign!-function(gurobi_freeDoubleArray!*, 'int64, a);

inline procedure gurobi_pushToVal(x);
   call!-foreign!-function(gurobi_pushToVal!*, 'double, x);

inline procedure gurobi_addconstr(relstr, val, c);
   call!-foreign!-function(gurobi_addconstr!*, 'string, relstr, 'int64, val, 'double, c);

inline procedure gurobi_addconstrFast(relstr, c);
   call!-foreign!-function(gurobi_addconstrFast!*, 'string, relstr, 'double, c);

inline procedure gurobi_numVars();
   call!-foreign!-function(gurobi_numVars!*, 'int32);

inline procedure gurobi_negconstr1();
   call!-foreign!-function gurobi_negconstr1!*;

inline procedure gurobi_negconstr(n);
   call!-foreign!-function(gurobi_negconstr!*, 'int32, n);

inline procedure gurobi_delconstr1();
   call!-foreign!-function gurobi_delconstr1!*;

inline procedure gurobi_delconstr(n);
   call!-foreign!-function(gurobi_delconstr!*, 'int32, n);

inline procedure gurobi_updatemodel();
   call!-foreign!-function gurobi_updatemodel!*;

inline procedure gurobi_write(fn);
   call!-foreign!-function(gurobi_write!*, 'string, fn);

inline procedure gurobi_getSol(i);
   call!-foreign!-function(gurobi_getSol!*, 'int32, i, 'double);

inline procedure gurobi_freemodel();
   call!-foreign!-function(gurobi_freemodel!*);

procedure gurobi_optimize();
   begin scalar w, sol;
      w := call!-foreign!-function(gurobi_optimize!*, 'string);
      w := intern compress reversip cdr reverse cdr explode w;
      if w neq 'optimal then
	 return w;
      sol := for i := 1 : gurobi_numVars() collect
	 gurobi_getSol i;
      return sol
   end;

procedure gurobi_addconstraint(rel, cl, c);
   begin scalar val, relstr; integer len;
      len := length cl;
      val := gurobi_newDoubleArray len;
      for i := 0:len-1 do
	 gurobi_setDoubleArray(val, i, pop cl);
      relstr := if rel eq 'equal then
 	 "="
      else if rel eq 'leq then
 	 "<"
      else if rel eq 'geq then
 	 ">"
      else
	 rederr {"illegal relation", rel};
      gurobi_addconstr(relstr, val, c);
      gurobi_freeDoubleArray val
   end;

procedure gurobi_addconstraintFast(rel, cl, c);
   begin scalar relstr; integer len;
      len := length cl;
      for i := 0:len-1 do
	 gurobi_pushToVal pop cl;
      relstr := if rel eq 'equal then
 	 "="
      else if rel eq 'leq then
 	 "<"
      else if rel eq 'geq then
 	 ">"
      else
	 rederr {"illegal relation", rel};
      gurobi_addconstrFast(relstr, c)
   end;

procedure gurobi_dumpmodel();
   <<
      gurobi_write("/tmp/lpdump.lp");
      system("cat /tmp/lpdump.lp");
      system("rm -f /tmp/lpdump.lp")
   >>;

#endif

endmodule;  % gurobi

end;  % of file
