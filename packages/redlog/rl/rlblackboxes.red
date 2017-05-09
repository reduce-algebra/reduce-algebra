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
   doc = "list of contained inequalities not containing certain variables",
   name = getineq,
   argnum = 2};

rl_blackbox {
   doc = "implicit logical negation of atomic formula",
   name = negateat,
   argnum = 1};

rl_blackbox {
   doc = "list of variables contained in atomic formula",
   name = varlat,
   argnum = 1};

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
   doc = "simplify atomic formula",
   name = simplat1,
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
   doc = "structural formula analysis atomic case",
   name = structat,
   argnum = 2};

rl_blackbox {
   doc = "irreducible factors structural formula analysis atomic case",
   name = ifstructat,
   argnum = 2};

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

endmodule;

end;
