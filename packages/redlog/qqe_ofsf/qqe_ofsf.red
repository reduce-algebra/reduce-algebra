module qqe_ofsf;

revision('qqe_ofsf, "$Id$");

copyright('qqe_ofsf, "(c) 2005-2021 A. Dolzmann, T. Sturm");

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

create!-package('(qqe_ofsf),nil);

load!-package 'ofsf;

flag('(qqe_ofsf),'rl_package);

%% put('qqe_ofsf,'rl_prepat,'qqe_ofsf_prepat);
%% put('qqe_ofsf,'rl_resimpat,'qqe_ofsf_resimpat); %!!!
%% put('qqe_ofsf,'rl_lengthat,'qqe_ofsf_lengthat);

% Parameters
put('qqe_ofsf,'rl_params,'(
   (rl_prepat!* . qqe_ofsf_prepat)
   (rl_simpat!* . qqe_ofsf_simpat)
   (rl_subat!* . qqe_ofsf_subat) %% to do
   (rl_subalchk!* . qqe_ofsf_subalchk) %% to do
   (rl_eqnrhskernels!* . qqe_ofsf_eqnrhskernels) %% to do
   (rl_ordatp!* . qqe_ofsf_ordatp) %% to do
   (rl_qemkans!* . ofsf_qemkans) %% belongs to qe -should this be wrapped?
   (rl_simplat1!* . qqe_ofsf_simplat1)
   (rl_smupdknowl!* . qqe_ofsf_smupdknowl)
   (rl_smrmknowl!* . cl_smrmknowl)
   (rl_smcpknowl!* . cl_smcpknowl)
   (rl_smmkatl!* . cl_smmkatl)
   (rl_negateat!* . qqe_ofsf_negateat)
   (rl_varlat!* . qqe_ofsf_varlat)
   (rl_varsubstat!* . qqe_ofsf_varsubstat)
   (rl_translat!* . ofsf_translat) % belongs to qe - !?
   (rl_elimset!*. ofsf_elimset)
   (rl_trygauss!* . cl_trygauss)
   (rl_varsel!* . ofsf_varsel) % belongs to qe - !?
   (rl_betterp!* . cl_betterp)
   (rl_subsumption!* . ofsf_subsumption) % bnf function maybe ok
   (rl_bnfsimpl!* . cl_bnfsimpl)
   (rl_sacat!* . cl_sacat)   % was before ofsf_sacat : to be modified still
   (rl_sacatlp!* . ofsf_sacatlp)
   (rl_qstrycons!* . ofsf_qstrycons)
   (rl_qscsaat!* . cl_qscsaat)
   (rl_qssubat!* . ofsf_qssubat)
   (rl_qsconsens!* . cl_qsnconsens)
   (rl_qsimpltestccl!* . cl_qsimpltestccl)
   (rl_qssubsumep!* . cl_qssusubyit)
   (rl_qssubsumep!* . cl_qssusubytab)
   (rl_qstautp!* . cl_qstautp)
   (rl_qssusuat!* . ofsf_qssusuat)
   (rl_qssimpl!* . cl_qssimpl)
   (rl_qssiadd!* . ofsf_qssiadd)
   (rl_fctrat!* . qqe_ofsf_fctrat) % to do
   (rl_tordp!* . ordp)
   (rl_transform!* . ofsf_transform) % belongs to qe
   (rl_updatr!* . ofsf_updatr) % belongs to qe
   (rl_a2cdl!* . ofsf_a2cdl) %% not possible for example for qequal
   (rl_t2cdl!* . ofsf_t2cdl)
   (rl_getineq!* . ofsf_getineq)
   (rl_qefsolset!* . ofsf_qefsolset)
   (rl_bettergaussp!* . ofsf_bettergaussp)
   (rl_bestgaussp!* . ofsf_bestgaussp)
   (rl_esetunion!* . ofsf_esetunion)
   (rl_structat!* . qqe_ofsf_structat) %% to do
   (rl_ifstructat!* . ofsf_ifstructat) %% to do
   (rl_termmlat!* . ofsf_termmlat) %% to do
   (rl_multsurep!* . ofsf_multsurep) % !?
   (rl_specelim!* . ofsf_specelim)
   (rl_fbqe!* . ofsf_fbqe)));

% Services
put('qqe_ofsf,'rl_services,'(
   (rl_subfof!* . cl_subfof)
   (rl_identifyonoff!* . cl_identifyonoff)
   (rl_simpl!* . cl_simplbasic)
   (rl_simplbasic!* . cl_simplbasic)
   (rl_thsimpl!* . ofsf_thsimpl) %% belongs to qe
   (rl_nnf!* . cl_nnf)
   (rl_nnfnot!* . cl_nnfnot)
   (rl_pnf!* . cl_pnf)
   (rl_cnf!* . cl_cnf)   % was before ofsf_cnf : but ofsf_sacat has to be
                         % modified first
   (rl_dnf!* . cl_dnf)   % same here
   (rl_all!* . cl_all)
   (rl_ex!* . cl_ex)
   (rl_atnum!* . cl_atnum)
   (rl_qnum!* . cl_qnum)
   (rl_tab!* . cl_tab)
   (rl_atab!* . cl_atab)
   (rl_itab!* . cl_itab)
%%   (rl_gsc!* . ofsf_gsc) %% groebner simplifier !?
%%   (rl_gsd!* . ofsf_gsd)
%%   (rl_gsn!* . ofsf_gsn)
   (rl_qe!* . qqe_ofsf_qe) %% to do
   (rl_qea!* . ofsf_qea) %% what is this function doing?
   (rl_gqe!* . cl_gqe)
   (rl_gqea!* . cl_gqea)
   (rl_qeipo!* . cl_qeipo)
   (rl_qews!* . cl_qews)
%%   (rl_opt!* . ofsf_opt) % standard form optimization !?
   (rl_ifacl!* . cl_ifacl)
   (rl_ifacml!* . cl_ifacml)
   (rl_matrix!* . cl_matrix)
   (rl_miniscope!* . cl_miniscope)
   (rl_atml!* . cl_atml)
   (rl_tnf!* . cl_tnf)
   (rl_atl!* . cl_atl)
   (rl_struct!* . cl_struct)
   (rl_ifstruct!* . cl_ifstruct)
   (rl_termml!* . cl_termml)
   (rl_terml!* . cl_terml)
   (rl_varl!* . cl_varl)
   (rl_fvarl!* . cl_fvarl)
   (rl_bvarl!* . cl_bvarl)
   (rl_gentheo!* . cl_gentheo)
   (rl_decdeg!* . ofsf_decdeg) %belongs to qe
   (rl_decdeg1!* . ofsf_decdeg1)
   (rl_surep!* . cl_surep)
   (rl_siaddatl!* . cl_siaddatl)
%%   (rl_cad!* . ofsf_cad) % later
%%   (rl_gcad!* . ofsf_gcad) % later
%%   (rl_cadswitches!* . ofsf_cadswitches)
   (rl_lqe!* . cl_lqe)
   (rl_xqe!* . ofsf_xopt!-qe)
   (rl_xqea!* . ofsf_xopt!-qea)
   (rl_lthsimpl!* . ofsf_lthsimpl) %% belongs to qe
   (rl_lthsimpl!* . ofsf_lthsimpl)
   (rl_quine!* . cl_quine)
%%   (rl_cadporder!* . ofsf_cadporder)
%%   (rl_gcadporder!* . ofsf_gcadporder)
%%   (rl_cadproj!* . ofsf_cadproj)
   (rl_hqe!* . ofsf_hqe)
   (rl_ghqe!* . ofsf_ghqe)));

%algebraic infix equal;
put('equal,'rl_prepfn,'ofsf_prepat);
put('equal,'rl_simpfn,'qqe_ofsf_chsimpat);
%put('equal,'number!-of!-args,2);
put('equal,'rtypefn,'quotelog);
remprop('equal,'psopfn); % temporary - to make arg check, also important
                         % in rlsimp1!!!

%algebraic infix neq;
put('neq,'rl_prepfn,'ofsf_prepat);
put('neq, 'rl_simpfn, 'qqe_ofsf_chsimpat);
%put('neq,'number!-of!-args,2);
put('neq,'rtypefn,'quotelog);
newtok '((!< !>) neq) where !*msg=nil;

%algebraic infix leq;
put('leq,'rl_prepfn,'ofsf_prepat);
put('leq,'rl_simpfn,'qqe_ofsf_chsimpat);
%put('leq,'number!-of!-args,2);
put('leq,'rtypefn,'quotelog);

%algebraic infix geq;
put('geq,'rl_prepfn,'ofsf_prepat);
put('geq,'rl_simpfn,'qqe_ofsf_chsimpat);
%put('geq,'number!-of!-args,2);
put('geq,'rtypefn,'quotelog);

%algebraic infix lessp;
put('lessp,'rl_prepfn,'ofsf_prepat);
put('lessp,'rl_simpfn,'qqe_ofsf_chsimpat);
%put('lessp,'number!-of!-args,2);
put('lessp,'rtypefn,'quotelog);

%algebraic infix greaterp;
put('greaterp,'rl_prepfn,'ofsf_prepat);
put('greaterp,'rl_simpfn,'qqe_ofsf_chsimpat);
%put('greaterp,'number!-of!-args,2);
put('greaterp,'rtypefn,'quotelog);

put('qequal,'infix,31);
put('qneq,'infix,32);

flag('(qqe_ofsf_chsimpat),'full);

%% TODO: other infixes from ofsf

procedure qqe_ofsf_prepat(f);
   if qqe_rqopp qqe_op f then qqe_prepat f
   else ofsf_prepat f;

procedure qqe_ofsf_resimpat(f);
   if qqe_rqopp qqe_op f then f
   else qqe_mk2(qqe_op f,
      numr resimp !*f2q qqe_arg2l f,numr resimp !*f2q qqe_arg2r f);

procedure qqe_ofsf_chsimpat(u);
   rl_smkn('and,for each x in ofsf_chsimpat1 u collect qqe_ofsf_simpat x);

procedure qqe_ofsf_chsimpat1(u);
   begin scalar leftl,rightl,lhs,rhs;
      lhs := cadr u;
      if pairp lhs and ofsf_opp car lhs then <<
         leftl := ofsf_chsimpat1 lhs;
         lhs := caddr lastcar leftl
      >>;
      rhs := caddr u;
      if pairp rhs and ofsf_opp car rhs then <<
         rightl := ofsf_chsimpat1 rhs;
         rhs := cadr car rightl
      >>;
      return nconc(leftl,{car u,lhs,rhs} . rightl)
   end;

procedure qqe_ofsf_simpat(u);
   begin
      qqe_ofsf_chsimpterm qqe_arg2l u;
      qqe_ofsf_chsimpterm qqe_arg2r u;
      qqe_arg!-check u;
      if qqe_op u memq '(qequal qneq) then return qqe_simpat u
      else return ofsf_simpat(u)
   end;

procedure qqe_ofsf_chsimpterm(term);
   begin scalar x;
      if atom term then return term
      else <<
         x := cdr term;
         while x do <<
            if pairp car x and qqe_op car x eq 'expt and
               pairp qqe_arg2l car x
               and qqe_op qqe_arg2l car x memq '(ltail rtail) then
                  car x := qqe_chsimpterm car x
            else if pairp car x then qqe_ofsf_chsimpterm car x;
            x := cdr x;
         >>;
      >>;
   end;

asserted procedure qqe_ofsf_smupdknowl(op: Id, atl: List, knowl: Alist, n: Integer): Alist;
   % Smart simplifier update knowledge. [op] is one of the operators [and],
   % [or]; [atl] is a list of atomic formulas; [knowl] is knowledge base; [n] is
   % an integer. Returns a knowledge base. If [op] is [and], then all knowledge
   % in [atl] is added to the [knowl] with the tag [n]. If [op] is [or], then
   % the negation of all knowledge in [atl] is added to [knowl].
   begin scalar at;
      while atl do <<
         at := pop atl;
         knowl := qqe_ofsf_smupdknowl1(op, at, knowl, n);
         if knowl eq 'false then <<
            atl := nil;
            at := 'break
         >>
      >>;
      if at eq 'break then
         return 'false
      else
         return knowl
   end;

asserted procedure qqe_ofsf_smupdknowl1(op: Id, at: Atom, knowl: Alist, n: Integer): Alist;
   begin scalar ent, contra;
      if op eq 'or then <<
         ent := rl_negateat at;
         contra := at
      >> else <<
         ent := at;
         contra := rl_negateat at
      >>;
      if assoc(ent, knowl) then
         return knowl;
      return knowl := (ent . n) . knowl
   end;

procedure qqe_ofsf_simplat1(f,sop);
   << if (x memq '(true false)) or (qqe_rqopp qqe_op f) then x
   else ofsf_simplat1(x, sop) >>
      where x=qqe_simplat1(f, sop);

procedure qqe_ofsf_simplqequal(f);
   qqe_mk2('qequal,ofsf_arg2l f,ofsf_arg2r f );

procedure qqe_ofsf_simplqneq(f);
   qqe_mk2('qneq,ofsf_arg2l f, ofsf_arg2r f);

%CS Ab hier, besser richtige Wrapper schreiben

procedure qqe_ofsf_canegrel(r,flg);
   % QQE Ordered field standard form conditionally algberaically negate
   % relation. [r] is a relation. Returns a relation $R$. If [flg] is
   % non-[nil], then $[R]=[r]$. If [flg] is [nil], then [R] is a
   % relation, such that $R(-t,0)$ is equivalent to $[r](t,0)$ for
   % every term $t$.
   if flg then r else qqe_anegrel r;

procedure qqe_ofsf_anegrel(r);
   % QQE Ordered field standard form algebraically negate relation. [r] is
   % a relation. Returns a relation $R$ such that $R(-t,0)$ is
   % equivalent to $[r](t,0)$ for a term $t$.
   cdr atsoc(r,'((qequal . qequal) (qneq . qneq))) or ofsf_anegrl r;

procedure qqe_ofsf_clnegrel(r,flg);
   % QQE Ordered field standard form conditionally logically negate
   % relation. [r] is a relation; [flg] is bool. Return a relation
   % $R$. If [flg] is non-[nil] [r] is returned. Othewise a relation
   % $R$ is returned such that for terms $t_1$, $t_2$ we have
   % $R(t_1,t_2)$ equivalent to $\lnot [r](t_1,t_2)$.
   if flg then r else qqe_ofsf_lnegrel r;

procedure qqe_ofsf_lnegrel(r);
   % QQE Ordered field standard form logically negate relation. [r] is a
   % relation. Returns a relation $R$ such that for terms $t_1$, $t_2$
   % we have $R(t_1,t_2)$ equivalent to $\lnot [r](t_1,t_2)$.
   if r eq 'qequal then
      'qneq
   else if r eq 'qneq then
      'qequal
   else
      ofsf_lnegrel r;

procedure qqe_ofsf_negateat(f);
   % QQE Ordered field standard form negate atomic formula. [f] is an
   % atomic formula. Returns an atomic formula equivalent to $\lnot
   % [f]$.
   ofsf_mkn(qqe_ofsf_lnegrel qqe_op f,ofsf_argn f);

procedure qqe_ofsf_varsubstat(atf,new,old);
   % QQE ordered field standard form substitute variable for variable
   % in atomic formula. [atf] is an atomic formula; [new] and [old]
   % are variables. Returns an atomic formula equivalent to [atf]
   % where [old] is substituted with [new].
   if qqe_rqopp qqe_op atf then qqe_varsubstat(atf, new,old)
   else ofsf_varsubstat(atf,new,old);

procedure qqe_ofsf_varlterm(term, list);
   % QQE ordered field standard form variable list term.
   % kernels {numr simp qqe_arg2l atform, numr simp qqe_arg2r atform};
   % should be done with dfs...i think here is no better wrapping
   % possible.
   begin scalar list;

      if (atom term) and idp term and not(term eq 'qepsilon)
      then list := lto_insertq(term, list)

      else if not atom term then
         for each x in cdr term do list := qqe_ofsf_varlterm(x, list);

      return list;
   end;


procedure qqe_ofsf_ordatp(a1,a2);
   % Ordered field standard form atomic formula predicate. [a1] and
   % [a2] are atomic formulas. Returns [t] iff [a1] is less than [a2].
   begin scalar lhs1,lhs2;
      lhs1 := ofsf_arg2l a1;
      lhs2 := ofsf_arg2l a2;
      if lhs1 neq lhs2 then return not ordp(lhs1,lhs2);
      return qqe_ofsf_ordrelp(ofsf_op a1,ofsf_op a2)
   end;

procedure qqe_ofsf_ordrelp(r1,r2);
   % Ordered field standard form relation order predicate.
   % [r1] and [r2] are ofsf-relations. Returns a [T] iff $[r1] < [r2]$.
   r2 memq cdr (r1 memq '(equal neq leq lessp geq greaterp qequal qneq));

procedure qqe_ofsf_varlat(atform);
   % later
   % begin scalar lhs, rhs;
   union(qqe_ofsf_varlterm(qqe_arg2l at,nil),
      qqe_ofsf_varlterm(qqe_arg2r at, nil))
         where at=qqe_ofsf_prepat atform;

%ENDCS Ab hier, besser richtige Wrapper schreiben

procedure qqe_ofsf_mk2(op,lhs,rhs);
   % later
   qqe_mk2(op,lhs,rhs);

procedure qqe_ofsf_qe(f,theo);
   % QQE ordered field standard form quantifier elimination.
   begin
      return qqe_qe(f);
      % ofsf_qe(f);  %<--- should be decided by some switch
   end;

procedure qqe_qe!-basic(f);
   ofsf_qe(f,nil);

endmodule;  % qqe_ofsf

end;  % of file
