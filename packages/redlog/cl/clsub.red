module clsub;
% Substitution and replacement

revision('clsub, "$Id$");

copyright('clsub, "(c) 2021 A. Dolzmann, T. Sturm");

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

rl_provideService rl_subfof = cl_subfof using rl_varsubstat, rl_subalchk, rl_eqnrhskernels, rl_subat;

asserted procedure cl_subfof(al: Alist, f: Formula): Formula;
   % Common logic substitute into first-order formula. The elements of al are
   % v_i . p_i, where v_i are variables and p_i are Lisp prefix forms. In the
   % output, all occurrences of the $v_i$ are replaced by the p_i. the
   % p_imust not contain parametric denominators. Otherwise an error is
   % raised.
   begin scalar asgal, w, allvl;
      rl_subalchk al;
      for each x in al do <<
         w := rl_eqnrhskernels x;
         asgal := lto_alunion {{car x . w}, asgal};
         allvl := car x . append(w, allvl)
      >>;
      w := cl_varl1 f;
      allvl := lto_nconcn {allvl, car w, cdr w};
      return cl_subfof1(al, f, asgal, allvl)
   end;

 asserted procedure cl_subfof1(al: Alist, f: Formula, asgal: Alist, allvl: List): Formula;
   begin scalar op, v, newv, m, b;
      op := rl_op f;
      if rl_tvalp op then
         return f;
      if rl_quap op then <<
         v := rl_var f;
         m := rl_mat f;
         al := for each x in al join if not eqcar(x, v) then {x};
         asgal := for each x in asgal join if not eqcar(x, v) then {x};
         newv := cl_newv(v, m, asgal, allvl);
         if newv neq v then <<
            allvl := newv . allvl;
            m := cl_subvarsubstat(newv, v, m)
         >>;
         return rl_mkq(op, newv, cl_subfof1(al, m, asgal, allvl))
      >>;
      if rl_bquap op then
         return rl_BQsubfof1(al, f, asgal, allvl);
      if rl_boolp op then
         return rl_mkn(op, for each x in rl_argn f collect cl_subfof1(al, x, asgal, allvl));
      ASSERT( cl_atfp f );
      return rl_subat(al, f)
   end;

asserted procedure cl_newv(v: Id, m: Formula, asgal: Alist, allvl: List): Id;
   % Common logic new variable. Rename v if necessary.
   begin scalar a, fvl, w, newv; integer n;
      newv := v;
      fvl := cl_subfvarl m;
      while fvl do <<
         a := car fvl;
         fvl := cdr fvl;
         if (w := atsoc(a, asgal)) and v memq w then <<
            % There is a substitution of [v] for a free variable.
            repeat <<
               newv := mkid(v, n);
               n := n + 1
            >> until not (newv memq allvl or get(v, 'avalue));
            fvl := nil
         >>
      >>;
      return newv
   end;

asserted procedure cl_subvarsubstat(newv: Id, oldv: Id, f: Formula): Formula;
   begin scalar op;
      if rl_tvalp f then
         return f;
      op := rl_op f;
      if rl_quap op then
         if rl_var f eq oldv then
            return rl_mkq(op, newv, cl_subvarsubstat(newv, oldv, rl_mat f))
         else
            return rl_mkq(op, rl_var f, cl_subvarsubstat(newv, oldv, rl_mat f));
      if rl_boolp op then
         return rl_mkn(op, for each x in rl_argn f collect cl_subvarsubstat(newv, oldv, x));
      return rl_varsubstat(f, newv, oldv)
   end;

asserted procedure cl_subfvarl(m: Formula);
   cl_subfvarl1(m, nil);

asserted procedure cl_subfvarl1(f: Formula, cbvl: List);
   begin scalar op;
      op := rl_op f;
      if rl_quap op then
         return cl_subfvarl1(rl_mat f, rl_var f . cbvl);
      if rl_boolp op then
         return for each x in rl_argn f join cl_subfvarl1(x, cbvl);
      if rl_tvalp op then
         return nil;
      return for each x in rl_varlat f join if not (x memq cbvl) then {x}
   end;

% Replacement. Not a service, and apparently not used anywhere.

asserted procedure cl_replace(f: Formula, sal: Alist): Formula;
   % Replace all occurrences of subformulas in f according to sal.
   if sal then cl_replace1(f, sal) else f;

asserted procedure cl_replace1(f: Formula, sal: Alist): Formula;
   begin scalar w, op;
      if (w := assoc(f, sal)) then
         return cdr w;
      op := rl_op f;
      if rl_quap op then
         return rl_mkq(op, rl_var f, cl_replace(rl_mat f, sal));
      if rl_bquap op then
         return rl_BQreplace1(f, sal);
      if rl_boolp op then
         return rl_mkn(op, for each subf in rl_argn f collect cl_replace(subf, sal));
      ASSERT( rl_tvalp op or cl_atfp f );
      return f
   end;

% vsub provides virtual substitution in the algebraic mode. It is currently
% not a service and probably should be integrated more cleanly.

put('vsub, 'psopfn, 'cl_vsubeval);

asserted procedure cl_vsubeval(u: LispPrefixForm): LispPrefixForm;
   begin scalar al, f;
      if null u then
         rederr "no arguments in vsub";
      u := reverse u;
      f := rl_simp pop u;
      if null u then
         return rl_mk!*fof f;
      u := reversip u;
      if null cdr u and eqcar(car u, 'list) then
         u := cdr car u;
      al := for each eqn in u collect <<
         if not eqcar(eqn, 'equal) then
            rederr {eqn, "invalid as equation in vsub"};
         cadr eqn . caddr eqn
      >>;
      rl_vsubalchk al;
      return rl_mk!*fof cl_vsubfof(al, f)
   end;

asserted procedure cl_vsubfof(subl: Alist, f: Formula): Formula;
   <<
      for each pr in subl do
         f := cl_vsubfof1(car pr, cdr pr, f);
      f
   >>;

asserted procedure cl_vsubfof1(v: Kernel, u: List, f: Formula): Formula;
   begin scalar op;
      op := rl_op f;
      if rl_tvalp op then
         return f;
      if rl_quap op then
         return if rl_var f eq v then
            f
         else
            rl_mkq(op, rl_var f, cl_vsubfof1(v, u, rl_mat f));
      if rl_bquap op then
         rederr "cl_vsubfof1: bounded quantifiers are not supported";
      if rl_boolp op then
         return rl_mkn(op, for each x in rl_argn f collect cl_vsubfof1(v, u, x));
      % [f] is atomic.
      return rl_vsubat(v, u, f)
   end;

endmodule;

end;
