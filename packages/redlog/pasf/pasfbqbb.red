module pasfbqbb;
% Black boxes processing bounded quantifiers for cl services.

revision('pasfbqbb, "$Id$");

copyright('pasfbqbb, "(c) 2021 A. Dolzmann, T. Sturm");

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

asserted procedure pasf_BQapply2ats1(f: Formula, client: Applicable, xargs: List): Formula;
   % Apply also to atoms in bound.
   rl_mkbq(rl_op f, rl_var f, cl_apply2ats1(rl_b f, client, xargs), cl_apply2ats1(rl_mat f, client, xargs));

asserted procedure pasf_BQatnum(f: Formula): Integer;
   % Count atoms also in bound.
   cl_atnum(rl_mat f) + cl_atnum(rl_b f);

asserted procedure pasf_BQqnum(f: Formula): Integer;
   % Do not count bounded quantifiers.
   cl_qnum rl_mat f;

asserted procedure pasf_BQdepth(f: Formula): Integer;
   % Do not consider the bound.
   1 + cl_depth rl_mat f;

asserted procedure pasf_BQf2ml(f: Formula, client: Applicable): List;
   % Consider both bound and matrix.
   lto_almerge({cl_f2ml(rl_mat f, client), cl_f2ml(rl_b f, client)}, 'plus2);

asserted procedure pasf_BQsubfof1(al: Alist, f: Formula, asgal: Alist, allvl: List): Formula;
   begin scalar op, v, m, b, al, asgal, newv, allvl, m;
      op := rl_op f;
      v := rl_var f;
      m := rl_mat f;
      b := rl_b f;
      al := for each x in al join if not eqcar(x, v) then {x};
      asgal := for each x in asgal join if not eqcar(x, v) then {x};
      newv := cl_newv(v, m, asgal, allvl);
      if newv neq v then <<
         allvl := newv . allvl;
         m := cl_subvarsubstat(newv, v, m)
      >>;
      return rl_mkbq(op, newv, cl_subfof1(al, b, asgal, allvl), cl_subfof1(al, m, asgal, allvl))
   end;

asserted procedure pasf_BQreplace1(f: Formula, sal: Alist): Formula;
   rl_mkbq(rl_op f, rl_var f, cl_replace(rl_b f, sal), cl_replace(rl_mat f, sal));

asserted procedure pasf_BQnnf1(f: Formula, flag: Boolean): Formula;
   % Do not flip within bound.
   rl_mkbq(cl_cflip(rl_op f, flag), rl_var f, cl_nnf1(rl_b f, t), cl_nnf1(rl_mat f, flag));

asserted procedure pasf_BQrename!-vars1(f: Formula, vl: DottedPair): DottedPair;
   begin scalar rnf, w, nvar, rnb;
      rnf . vl := cl_rename!-vars1(rl_mat f, vl);
      w := assoc(rl_var f, cdr vl);
      if w then <<
         if eqn(cdr w, 0) then <<
            cdr w := 1;
            return rl_mkbq(rl_op f, rl_var f, rl_b f, rnf) . vl
         >>;
         repeat <<
            nvar := mkid(car w, cdr w);
            cdr w := cdr w + 1
         >> until not (nvar memq car vl or get(nvar, 'avalue));
         push(nvar, car vl);
         rnb := cl_apply2ats1(rl_b f, 'rl_varsubstat, {nvar, car w});
         rnf := cl_apply2ats1(rnf, 'rl_varsubstat, {nvar, car w});
         return rl_mkbq(rl_op f, nvar, rnb, rnf) . vl
      >>;
      return rl_mkbq(rl_op f, rl_var f, rl_b f, rnf) . vl
   end;

asserted procedure pasf_BQvarl2(f: Formula, fvl: KernelL, cbvl: KernelL, bvl: KernelL): DottedPair;
   <<
      cbvl := lto_insertq(rl_var f, cbvl);
      fvl . bvl := cl_varl2(rl_b f, fvl, cbvl, bvl);
      cl_varl2(rl_mat f, fvl, lto_insertq(rl_var f, cbvl), bvl)
   >>;

asserted procedure pasf_BQqvarl1(f: Formula): KernelL;
   lto_insertq(rl_var f, cl_qvarl1 rl_mat f);

asserted procedure pasf_BQordp(f1: Formula, f2: Formula): ExtraBoolean;
   if rl_var f1 neq rl_var f2 then
      not(ordp(rl_var f1, rl_var f2) and rl_var f1 neq rl_var f2)
   else if rl_b f1 neq rl_b f2 then
      cl_ordp(rl_b f1, rl_b f2)
   else
      cl_ordp(rl_mat f1, rl_mat f2);

endmodule;

end;
