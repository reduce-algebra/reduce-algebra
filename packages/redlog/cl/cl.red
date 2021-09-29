module cl;
% Common logic. Generic functions on first order formulas.

revision('cl, "$Id$");

copyright('cl, "(c) 1995-2021 A. Dolzmann, T. Sturm");

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

create!-package('(cl clsub clsimpl clsimplbasic clsusi clbnf clnf clqe cltab clmisc clresolv
                  cldfgformat clsmt2format clqenode clqecont clqeenv clqestate clqenew), nil);

compiletime load!-package 'redlog;

exports cl_atfp, cl_cxfp, cl_atflp, cl_ncflp, cl_dnfp, cl_cnfp, cl_bnfp,
   cl_simpl, cl_simplbasic, cl_simplifyTheory, cl_ordp, cl_smcpknowl,
   cl_smrmknowl, cl_smupdknowl, cl_smmkatl, cl_siaddatl, cl_susimkatl,
   cl_susicpknowl, cl_susiupdknowl, cl_dnf, cl_cnf, cl_bnf!-cartprod,
   cl_bnfsimpl, cl_sacatlp, cl_sacat, cl_expand!-extbool, cl_nnf, cl_nnfnot,
   cl_pnf, cl_rename!-vars, cl_fvarl, cl_fvarl1, cl_bvarl, cl_bvarl1, cl_varl,
   cl_varl1, cl_apnf, cl_freevp, cl_tnf, cl_gqe, cl_gqea, cl_qe, cl_qea,
   cl_qeipo, cl_qews, cl_trygauss, cl_specelim, cl_tab, cl_atab, cl_itab,
   cl_gentheo, cl_apply2ats, cl_apply2ats1, cl_apply2ats2, cl_atnum, cl_f2ml,
   cl_atml, cl_atml1, cl_atl, cl_atl1, cl_identifyonoff, cl_ifacml, cl_ifacml1,
   cl_ifacl, cl_ifacl1, cl_ifacdegl, cl_matrix, cl_closure, cl_all, cl_ex,
   cl_flip, cl_cflip, cl_subfof, cl_termml, cl_termml1, cl_terml, cl_terml1,
   cl_struct, cl_ifstruct, cl_surep, cl_splt;

fluid '(cl_identify!-atl!* cl_pal!* cl_lps!* cl_theo!* !*rlidentify !*rlsiexpla !*rlbnfsm
        !*rlverbose !*rlsiso !*rlbnfsac !*rltnft !*rlsipw !*rlsipo !*rlspgs !*rlqefb !*rlresi
        !*slat);

fluid '(!*rlqepnf !*rlqedfs !*rlqeans !*rlqegsd !*rlqeheu !*rlqegen !*rlqevarsel !*rlqelocal
        !*rlqeprecise !*rlqeaprecise !*rlqestdans !*rlqedyn !*rlqevb !*rlqevbold !*rlqeidentify);

switch clqenew;

off1 'clqenew;

struct QfFormula;
struct QfFormulaL asserted by listp;
struct Theory asserted by listp;
struct TheoryFormulaPair asserted by pairp;
struct KernelL asserted by listp;
struct Quantifier asserted by idp;
struct AtFormula asserted by cl_atfp;

procedure cl_atfp(x);
   % Common logic atomic formula predicate. [x] is a formula. Returns
   % non-[nil] iff [x] is an atomic formula.
   not rl_cxp rl_op x;

procedure cl_cxfp(x);
   % Common logic complex formula predicate. [x] is a formula. Returns
   % non-[nil] iff [x] is a complex, i.e. non-atomic, formula.
   rl_cxp rl_op x;

procedure cl_atflp(fl);
   % Common logic atomic formula list predicate. [fl] is a list of
   % formulas. Returns [T] or [nil]. [T] is returned if and only if
   % [fl] is a list of atomic formulas.
   null fl or (cl_atfp car fl and cl_atflp cdr fl);

procedure cl_ncflp(fl);
   % Common logic non-complex formula list predicate. [fl] is a list
   % of formulas. Returns [T] or [nil]. [T] is returned if and only if
   % [fl] is a list of atomic formulas and truth values.
   null fl or ((cl_atfp car fl or rl_tvalp car fl) and cl_ncflp cdr fl);

procedure cl_dnfp(f);
   % Common logic disjunctive normal form predicate. [f] is a formula.
   % Returns [T] or [nil]. [T] is returned iff [f] is in disjunctive
   % normal form.
   (rl_tvalp f) or (cl_atfp f) or (rl_op f eq 'and and cl_ncflp rl_argn f)
      or ((rl_op f eq 'or) and cl_dnfp1 rl_argn f);

procedure cl_dnfp1(fl);
   % Common logic disjunctive normal form predicate subroutine. [f] is
   % a formula. Returns [T] or [nil].
   (null fl) or ((rl_tvalp car fl) or (cl_atfp car fl) or
      ((rl_op car fl eq 'and) and (cl_ncflp rl_argn car fl))) and
         (cl_dnfp1 cdr fl);

procedure cl_cnfp(f);
   % Common logic conjunctive normal form predicate. [f] is a formula.
   % Returns [T] or [nil]. [T] is returned iff [f] is in conjunctive
   % normal form.
   (rl_tvalp f) or (cl_atfp f) or (rl_op f eq 'or and cl_ncflp rl_argn f)
      or ((rl_op f eq 'and) and cl_cnfp1 rl_argn f);

procedure cl_cnfp1(fl);
   % Common logic conjunctive normal form predicate subroutine . [f]
   % is a formula. Returns [T] or [nil]. [T] is returned iff [f] is in
   % conjunctive normal form.
   (null fl) or ((rl_tvalp car fl) or (cl_atfp car fl) or
      ((rl_op car fl eq 'or) and (cl_ncflp rl_argn car fl))) and
         (cl_cnfp1 cdr fl);

procedure cl_bnfp(f);
   % Common logic boolean normal form predicate. [f] is a formula.
   % Returns [T] or [nil]. [T] is returned iff [f] is in disjunctive
   % or conjunctive normal form.
   (rl_tvalp f) or (cl_atfp f) or (cl_ncflp rl_argn f)
      or ((rl_op f eq 'and) and cl_cnfp1 rl_argn f) or
         ((rl_op f eq 'or) and cl_dnfp1 rl_argn f);

endmodule;  % [cl]

end;  % of file
