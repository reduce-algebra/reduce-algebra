% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 2010-2013 T. Sturm
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
module pident;

switch pidentmore;

load!-package 'redlog;
load!-package 'ofsf;

rl_set '(dcfsf);

operator pident;

procedure pident(sys,ivl,ovl,pvl);
   % Parameter identifiability.
   begin scalar res; integer i;
      sys := rl_simp sys;
      ivl := cdr ivl;
      ovl := cdr ovl;
      pvl := cdr pvl;
      res := pident_pident(sys,ivl,ovl,pvl);
      res := if !*pidentmore then
      	 'list . for each case in res collect <<
	    i := i + 1;
	    {'list, lto_id2string mkid('case, i),
	       'list . for each eqn in car case collect rl_mk!*fof eqn,
	       'list . for each ne in cadr case collect rl_mk!*fof ne,
	       'list . for each pinfo in caddr case collect 'list . pinfo,
	       'list . for each c in cadddr case collect mk!*sq !*f2q c}
      	 >>
      else
      	 'list . for each case in res collect <<
	    i := i + 1;
	    {'list, lto_id2string mkid('case, i),
	       'list . for each eqn in car case collect rl_mk!*fof eqn,
	       'list . for each ne in cadr case collect rl_mk!*fof ne,
	       'list . for each pinfo in caddr case collect 'list . pinfo}
      	 >>;
      return res
   end;

procedure pident_maxorderl(fl,vl);
   % Maximal order. [fl] is a list of standard forms; [v] is variable.
   % Returns a number. The result is the maximum of the orders wrt. [v]
   % of the differential polynomials in [fl].
   begin scalar w; integer m;
      for each v in vl do
      	 for each f in fl do <<
	    w := dcfsf_orddegf(f,v);
	    if car w > m then
	       m := car w
      	 >>;
      return m
   end;

procedure pident_pident(sys,ivl,ovl,pvl);
   % [sys] is a list of DCFSF equations; [ivl], [ovl], and [pvl] are lists of
   % variables, the internal functions, the input and output functions, and the
   % real parameters, resp.
   begin scalar context,theo,sol,dsol,casel,vl,res;
      pident_checkVars(sys,ivl,ovl,pvl);
      theo := for each p in pvl collect dcfsf_0mk2('equal,numr simp {'d,p,1});
      for each x in ivl do
	 sys := rl_mkq('ex,x,sys);
      sol := rl_qe(sys,theo);
      dsol := rl_dnf sol;
      casel := if rl_op dsol eq 'or then rl_argn dsol else {dsol};
      vl := append(ivl,ovl);
      res := for each case in casel collect
	 pident_doit1(case,vl,pvl);
      return res
   end;

procedure pident_checkVars(sys,ivl,ovl,pvl);
   for each v in rl_fvarl sys do
      if not (member(v,ivl) or member(v,ovl) or member(v,pvl)) then
	 rederr {"unspecified variable", v};

procedure pident_doit1(sol,vl,pvl);
   begin scalar psi, cl, eql, neql, cvl, subl, psip, hu, huhu, sol, res;
      eql . neql :=
	 lto_partition(rl_atl sol, function(lambda at; rl_op at eq 'equal));
      % [cl] is the list of $c_i(p)$.
      cl := pident_cl(eql, vl);
      rl_set '(r);
      % [cvl] is the list of $p_j$ actually occurring in the $c_i(p)$.
      for each c in cl do
	 for each v in kernels c do
	    cvl := lto_insertq(v,cvl);
      subl := for each v in cvl collect
 	 v . mkid(v,'!_star);
      % [psi] is the antecedens of the implications in the real elimination
      % step. Immediately exploit transitivity. The [v_i] in the paper do not
      % exist.
      psi := rl_smkn('and,for each c in cl collect
 	 ofsf_0mk2('equal,addf(c,negf numr subf(c,subl))));
      % Add to [psi] all inequlitities that contain only variables [p_j],
      % [p_j^*].
      for each at in neql do
	 if pident_subset(cl_fvarl1 at,pvl) then
	    psi := rl_mkn('and,{psi,at});
      res := for each p in pvl collect <<
	 % [p] is one variable $p_j$. [psip] is the succedens of the
	 % implications in the real elimination step.
	 psip := ofsf_0mk2('equal,numr simp {'difference,p,mkid(p,'!_star)});
      	 hu := rl_all(rl_mk2('impl,psi,psip),nil);
      	 huhu := rl_qe(hu,nil);
	 % [huhu] is one of [true], [false] depending on whether [p] is
	 % identifiable.
	 {p,huhu}
      >>;
      rl_set '(dcfsf);
      return {eql,neql,res,cl}
   end;

procedure pident_cl(eql,vl);
   % Coefficient list. [f] is a DCFSF formula; [vl] is a list of variables.
   % Returns a list of SF. [vl] contains all variables except the real
   % parameters. The result is the list of polynomial coefficients in the real
   % parameters of the left hand sides of equations in [f] considered a
   % distributive differential polynomials in [vl].
   begin scalar res,lhs,kl;
      for each at in eql do <<
	 lhs := dcfsf_arg2l at;
	 kl := pident_vl2kl(vl,pident_maxorderl({lhs},vl));
	 for each c in sfto_allcoeffs(lhs,kl) do
	    if not domainp c then
	       res := lto_insert(sfto_dprpartf c,res);
      >>;
      return res
   end;

procedure pident_vl2kl(vl,n);
   % Variable list to kernel list. Returns a list containing the kernels in [vl]
   % and their first [n] derivatives.
   for each v in vl join dcfsf_mkkl(v,n);

procedure pident_subset(m1,m2);
   not m1 or member(car m1,m2) and pident_subset(cdr m1,m2);

procedure lto_partition(l, p);
   begin scalar l1, l2;
      for each x in l do
	 if apply(p,{x}) then
	    l1 := x . l1
	 else
	    l2 := x . l2;
      return reversip l1 . reversip l2
   end;

procedure lto_id2string(id);
   compress('!" . reversip('!" . reversip explode id));

endmodule;

end;
