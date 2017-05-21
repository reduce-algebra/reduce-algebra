module rlblackboxes;

revision('rlblackboxes, "$Id$");

copyright('rlblackboxes, "(c) 2017 T. Sturm");

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

rl_blackbox {
   doc = "atomic formula multiplicity list to case distinction list",
   name = a2cdl,
   argnum = 1};

rl_blackbox {
   doc = "bound to atomic formula list",
   name = b2atl,
   argnum = 2};

rl_blackbox {
   doc = "bound satisfiable predicate",
   name = bsatp,
   argnum = 2};

rl_blackbox {
   doc = "bound to term list",
   name = b2terml,
   argnum = 2};

rl_blackbox {
   doc = "best Gauss solution predicate",
   name = bestgaussp,
   argnum = 1};

rl_blackbox {
   doc = "better Gauss solution predicate",
   name = bettergaussp,
   argnum = 2};

rl_blackbox {
   doc = "Boolean normal form construction simplification step",
   name = bnfsimpl,
   argnum = 2};

rl_blackbox {
   doc = "DFG format print atomic formula",
   name = dfgPrintAt,
   argnum = 1};

rl_blackbox {
   doc = "DFG format print variable",
   name = dfgPrintV,
   argnum = 1};
   
rl_blackbox {
   doc = "list of kernels of rational function in LP form",
   name = eqnrhskernels,
   argnum = 1};

rl_blackbox {
   doc = "elimination set union",
   name = esetunion,
   argnum = 2};

rl_blackbox {
   doc = "fallback quantifier elimination",
   name = fbqe,
   argnum = 2};

rl_blackbox {
   doc = "factorize terms of atomic formula",
   name = fctrat,
   argnum = 1};

rl_blackbox {
   doc = "make equation",
   name = mkequation,
   argnum = 2};

rl_blackbox {
   doc = "quantifier elimination finite solution set",
   name = qefsolset,
   argnum = 5};

rl_blackbox {
   doc = "list of contained inequalities not containing certain variables",
   name = getineq,
   argnum = 2};

rl_blackbox {
   doc = "implicit logical negation of atomic formula",
   name = negateat,
   argnum = 1};

rl_blackbox {
   doc = "resolve extension function tranformation function",
   name = rxffn,
   argnum = 1};

rl_blackbox {
   doc = "list of variables contained in atomic formula",
   name = varlat,
   argnum = 1};

rl_blackbox {
   doc = "multiplicative sure predicate",
   name = multsurep,
   argnum = 2};

rl_blackbox {
   doc = "quine simplification compute satisfying assignment",
   name = qscsaat,
   argnum = 1};

rl_blackbox {
   doc = "quine simplification compute consensus",
   name = qsconsens,
   argnum = 3};

rl_blackbox {
   doc = "quine simplification implication test clause against clause list",
   name = qsimpltestccl,
   argnum = 3};

rl_blackbox {
   doc = "quine simplification simplify additively",
   name = qssiadd,
   argnum = 4};

rl_blackbox {
   doc = "quine simplification simplify",
   name = qssimpl,
   argnum = 3};

rl_blackbox {
   doc = "",
   name = qssubat,
   argnum = 2};

rl_blackbox {
   doc = "subsumption predicate",
   name = qssubsumep,
   argnum = 3};

rl_blackbox {
   doc = "",
   name = qssusuat,
   argnum = 3};
   
rl_blackbox {
   doc = "tautology predicate",
   name = qstautp,
   argnum = 1};

rl_blackbox {
   doc = "quine simplification try consensus",
   name = qstrycons,
   argnum = 4};

rl_blackbox {
   doc = "SMTLIB-2 format print atomic formula",
   name = smt2PrintAt,
   argnum = 1};

rl_blackbox {
   doc = "SMTLIB-2 format print logic",
   name = smt2PrintLogic,
   argnum = 0};

rl_blackbox {
   doc = "SMTLIB-2 format read atomic formula",
   name = smt2ReadAt,
   argnum = 1};

rl_blackbox {
   doc = "simplify atomic formula",
   name = simplat1,
   argnum = 2};

rl_blackbox {
   doc = "simplify bound",
   name = simplb,
   argnum = 2};

rl_blackbox {
   doc = "smart simplification update knowledge",
   name = smupdknowl,
   argnum = 4};

rl_blackbox {
   doc = "smart simplification remove knowledge",
   name = smrmknowl,
   argnum = 2};

rl_blackbox {
   doc = "smart simplification copyknowledge",
   name = smcpknowl,
   argnum = 1};

rl_blackbox {
   doc = "smart simplification make list of atomic formulas",
   name = smmkatl,
   argnum = 4};

rl_blackbox {
   doc = "smart-simplify implication",
   name = smsimpl!-impl,
   argnum = 5};

rl_blackbox {
   doc = "smart-simplify equivalence",
   name = smsimpl!-equiv1,
   argnum = 5};

rl_blackbox {
   doc = "special elimination",
   name = specelim,
   argnum = 5};

rl_blackbox {
   doc = "structural formula analysis atomic case",
   name = structat,
   argnum = 2};

rl_blackbox {
   doc = "susi post simplification",
   name = susipost,
   argnum = 2};

rl_blackbox {
   doc = "susi transform",
   name = susitf,
   argnum = 2};

rl_blackbox {
   doc = "susi binary smart simplification",
   name = susibin,
   argnum = 2};

rl_blackbox {
   doc = "irreducible factors structural formula analysis atomic case",
   name = ifstructat,
   argnum = 2};

rl_blackbox {
   doc = "subsumption and cut atomic formula",
   name = sacat,
   argnum = 3};

rl_blackbox {
   doc = "subsumption and cut atomic formula list predciate",
   name = sacatlp,
   argnum = 2};

rl_blackbox {
   doc = "subsumption relation w.r.t. generic or",
   name = subsumption,
   argnum = 3};

rl_blackbox {
   doc = "term to case distinction list",
   name = t2cdl,
   argnum = 1};

rl_blackbox {
   doc = "term multiplicity list on atomic formula",
   name = termmlat,
   argnum = 1};

rl_blackbox {
   doc = "equivalently transform formula before QE step",
   name = transform,
   argnum = 7};

rl_blackbox {
   doc = "substitute variable with another variable in atomic formula",
   name = varsubstat,
   argnum = 3};

rl_blackbox {
   doc = "translate atomic formula into a list of bounds modulo a theory",
   name = translat,
   argnum = 5};

rl_blackbox {
   doc = "elimination set computation",
   name = elimset,
   argnum = 2};

rl_blackbox {
   doc = "try Gauss elimination",
   name = trygauss,
   argnum = 5};

rl_blackbox {
   doc = "select variable to be eliminated",
   name = varsel,
   argnum = 3};

rl_blackbox {
   doc = "compare quality of two different elimination set substitution results",
   name = betterp,
   argnum = 2};

rl_blackbox {
   doc = "make answer from result container",
   name = qemkans,
   argnum = 2};

rl_blackbox {
   doc = "total order on atomic formulas",
   name = ordatp,
   argnum = 2};

rl_blackbox {
   doc = "replace varable-free terms in atomic formula with their signs",
   name = signat,
   argnum = 1};

rl_blackbox {
   doc = "substitute alist check",
   name = subalchk,
   argnum = 1};

rl_blackbox {
   doc = "substitute into atomic formula",
   name = subat,
   argnum = 2};

rl_blackbox {
   doc = "total order on terms",
   name = tordp,
   argnum = 2};

% The following are technically not blackboxes. They would become blackboxes
% when moving rl_prepfof and rl_simp to cl and calling them via the scheduler
% (instead of a the context tag). With the current design, they should not be
% called directly. Instead rl_prepfof and rl_simp should be used.

rl_blackbox {
   doc = "Lisp prefix from atomic formula",
   name = prepat,
   argnum = 1};

rl_blackbox {
   doc = "atomic formula from Lisp prefix",
   name = simpat,
   argnum = 1};

% The following are similar to rl_prepat and rl_simpat above. However, vsub is
% living in clmisc, without a service interface.

rl_blackbox {
   doc = "virtual substitution Alist check",
   name = vsubalchk,
   argnum = 1};

rl_blackbox {
   doc = "virtual substitution into atomic formula",
   name = vsubat,
   argnum = 3};

endmodule;

end;
