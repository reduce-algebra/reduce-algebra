module rlservices;

revision('rlservices, "$Id$");

copyright('rlservices, "(c) 2016-2017 T. Sturm");

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

rl_service {
   name = !1equation,
   doc = "equivalent DNF with one relevant equation in each branch (DCFSF)",
   arg = {pos = 1, name = conjunction, type = Formula, doc = "conjunction of atoms"},
   arg = {pos = 2, name = variable, type = Variable, doc = "variable to be considered"},
   arg = {pos = 3, name = assume, type = List(Atom), default = {}, doc = "atomic input assumptions"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = all,
   doc = "universal closure",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   arg = {pos = 2, name = except, type = List(Variable), default = {}, doc = "variables not to be quantified"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = apnf,
   doc = "anti-prenex normal form, aka miniscoping",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = atl,
   doc = "set of contained atomic formulas",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = List(Atom)},
   mode = both};

rl_service {
   name = atml,
   doc = "list of contained atomic formulas with numbers of occurrences",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = MList(Atom)},
   mode = both};

rl_service {
   name = atnum,
   doc = "number of contained atomic formulas counting multiplicities",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = Integer},
   mode = both};

rl_service {
   name = bvarl,
   doc = "list of variables with bound occurrences",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = List(Variable)},
   mode = both};

rl_service {
   name = cad,
   doc = "cylindrical algebraic decomposition",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   arg = {pos = 2, name = porder, type = List(Variable), default = {}, doc = "projection order"},
   arg = {pos = 3, name = xpolys, type = List(Term), default = {}, doc = "extra polynomials for projection"},
   arg = {pos = 4, name = verbose, type = Switch, doc = "print information on progress of computation"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = cadporder,
   doc = "cylindrical algebraic decomposition projection order",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = List(Variable)},
   mode = both};

rl_service {
   name = cadproj,
   doc = "cylindrical algebraic decomposition projection",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   arg = {pos = 2, name = porder, type = List(Variable), default = {}, doc = "projection order"},
   returns = {type = List(Term)},
   mode = both};

rl_service {
   name = cnf,
   doc = "conjunctive normal form",
   arg = {pos = 1, name = formula, type = Formula, doc = "quantifier-free input formula"},
   arg = {pos = 2, name = bnfsm, type = Switch, doc = "smart"},
   arg = {pos = 3, name = bnfsac, type = Switch, doc = "subsumption and cut"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = decdeg,
   doc = "decrease degree",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = Formula},
   mode = both};

rl_service {  % There was the option variables = 'fvarl.
   name = decdeg1,
   doc = "low-level decrease degree information",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   arg = {pos = 2, name = variables, type = List(Variable), doc = "variables to consider"},
   returns = {type = Pair(Formula, List(Pair(Variable, Integer)))},
   mode = both};

rl_service {
   name = depth,
   doc = "depth of the tree representation of a formula",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = Integer},
   mode = both};

rl_service {
   name = dfgprint,
   doc = "dump a formula as DFG input",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order formula"},
   arg = {pos = 2, name = file, type = String, default = "", doc = "file name to dump into, where """" uses stdout"},
   returns = {type = Any},
   mode = both};

rl_service {
   name = dnf,
   doc = "disjunctive normal form",
   arg = {pos = 1, name = formula, type = Formula, doc = "quantifier-free input formula"},
   arg = {pos = 2, name = bnfsm, type = Switch, doc = "smart"},
   arg = {pos = 3, name = bnfsac, type = Switch, doc = "subsumption and cut"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = dpep,
   doc = "deciding polynomial exponential problems",
   arg = {pos = 1, name = formula, type = Formula, doc = "quantifier-free input formula"},
   arg = {pos = 2, name = accuracy, type = Integer, default = 20, doc = "length of taylor expanson of exp"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = enf,
   doc = "elimination normal form (DCFSF)",
   arg = {pos = 1, name = formula, type = Formula, doc = "quantifier-free input formula"},
   arg = {pos = 2, name = variable, type = Variable, doc = "variable to be eliminated next"},
   arg = {pos = 3, name = assume, type = List(Atom), default = {}, doc = "atiomic input assumptions"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = ex,
   doc = "existential closure",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   arg = {pos = 2, name = except, type = List(Variable), default = {}, doc = "variables not to be quantified"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = ex2,
   doc = "'exists at least two' closure",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   arg = {pos = 2, name = except, type = List(Variable), default = {}, doc = "variables not to be quantified"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = explats,
   doc = "explode (factor) atoms of the form z ~ 1 or z /~ 1 with z in Z (PADICS only)",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   arg = {pos = 2, name = siexpl, type = Switch, doc = "explode if boolean operator matches"},
   arg = {pos = 3, name = siexpla, type = Switch, doc = "explode always"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = fvarl,
   doc = "list of variables with free occurrences",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = List(Variable)},
   mode = both};

rl_service {
   name = gcad,
   doc = "generic cylindrical algebraic decomposition",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   arg = {pos = 2, name = porder, type = List(Variable), default = {}, doc = "projection order"},
   arg = {pos = 3, name = xpolys, type = List(Term), default = {}, doc = "extra polynomials for projection"},
   arg = {pos = 4, name = verbose, type = Switch, doc = "print information on progress of computation"},
   returns = {type = Pair(List(Atom), Formula)},
   mode = both};

rl_service {
   name = gcadporder,
   doc = "generic cylindrical algebraic decomposition projection order",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = List(Variable)},
   mode = both};

rl_service {
   name = gentheo,
   doc = "heuristically add assumptions to theory to make formula true",
   arg = {pos = 1, name = theory, type = List(Atom), doc = "input theory"},
   arg = {pos = 2, name = formula, type = Formula, doc = "input formula"},
   arg = {pos = 3, name = exclude, type = List(Variable), default = {}, doc = "variables not to make assumptions on"},
   returns = {type = Pair(List(Atom), Formula)},
   mode = both};

rl_service {
   name = ghqe,
   doc = "generic Hermitian quantifier elimination",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = Pair(List(Atom), Formula)},
   mode = both};

rl_service {
   name = gqe,
   doc = "generic quantifier elimination",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   arg = {pos = 2, name = assume, type = List(Atom), default = {}, doc = "atomic input assumptions on the parameters"},
   arg = {pos = 3, name = except, type = List(Variable), default = {}, doc = "parameters to exclude from assumptions"},
   returns = {type = Pair(List(Atom), Formula)},
   mode = both};

rl_service {
   name = gqea,
   doc = "generic quantifier elimination with answer",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   arg = {pos = 2, name = assume, type = List(Atom), default = {}, doc = "atomic input assumptions"},
   arg = {pos = 3, name = except, type = List(Variable), default = {}, doc = "parameters to exclude from assumptions"},
   returns = {type = Pair(List(Atom),List(Pair(Formula, List(Assignment(Any)))))},
   mode = both};

rl_service {
   name = gsn,
   doc = "Groebner simplifier",
   arg = {pos = 1, name = formula, type = Formula, doc = "quantifier-free input formula"},
   arg = {pos = 2, name = assume, type = List(Atom), default = {}, doc = "atomic input assumptions"},
   arg = {pos = 3, name = form, type = Enum(auto, cnf, dnf), default = auto, doc = "Boolean normal form to use"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = hqe,
   doc = "Hermitian quantifier elimination",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = ifacl,
   doc = "list of irreducible factors",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = List(Term)},
   mode = both};

rl_service {
   name = ifacml,
   doc = "list of irreducible factors with numbers of occurrences",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = MList(Term)},
   mode = both};

rl_service {
   name = ifacdegl,
   doc = "maximal degrees of variables in irreducible factors",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = Pair(List(Pair(Variable, Integer)), List(Pair(Variable, Integer)))},
   mode = both};

rl_service {
   name = kapur,
   doc = "GB-based satisfiability",
   arg = {pos = 1, name = formula, type = Formula, doc = "quantifier-free input formula"},
   returns = {type = TruthValue},
   mode = both};

rl_service {
   name = lqe,
   doc = "local quantifier elimination",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   arg = {pos = 2, name = assume, type = List(Atom), default = {}, doc = "atomic input assumptions on the parameters"},
   arg = {pos = 3, name = point, type = List(Assignment(Rational)), default = {}, doc = "point where generated theory will be consistent"},
   returns = {type = Pair(List(Atom), Formula)},
   mode = both};

rl_service {
   name = matrix,
   doc = "matrix, i.e., argument formula of leading quantifier",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = mkcanonic,
   doc = "a canonical form for variable-free formulas (PADICS only)",
   arg = {pos = 1, name = formula, type = Formula, doc = "variable-free input formula"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = nnf,
   doc = "negation normal form",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = opt,
   doc = "optimize linear objective function subject to linear constraints",
   arg = {pos = 1, name = constraints, type = List(Atom), doc = "linear constraints"},
   arg = {pos = 2, name = objective, type = LPolyQ, doc = "linear objective function"},
   % The weakly parametric case systematically throws bug messages in
   % ofsf_getvalue. I think this never worked but was implemented to study the
   % (non-)working of active/passive lists with weak parameters.  -- TS
   arg = {pos = 3, name = unused, type = List(Variable), default = {}, doc = "do not use"},
   arg = {pos = 4, name = processors, type = Integer, default = 8, doc = "number of processor with experimental PVM-based parallelization"},
   arg = {pos = 5, name = parallel, type = Switch, doc = "experimental PVM-based parallelization"},
   % [Any] in the return type is Rational or +-infty.
   returns = {type = Pair(Any, List(List(Assignment(Any))))},
   mode = both};

rl_service {
   doc = "prenex normal form",
   name = pnf,
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = posgqe,
   doc = "positive generic quantifier elimination",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   arg = {pos = 2, name = assume, type = List(Atom), default = {}, doc = "atomic input assumptions on the parameters"},
   arg = {pos = 3, name = except, type = List(Variable), default = {}, doc = "parameters to exclude from assumptions"},
   returns = {type = Pair(List(Atom), Formula)},
   mode = both};

rl_service {
   name = posgqea,
   doc = "generic quantifier elimination with answer",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   arg = {pos = 2, name = assume, type = List(Atom), default = {}, doc = "atomic input assumptions"},
   arg = {pos = 3, name = except, type = List(Variable), default = {}, doc = "parameters to exclude from assumptions"},
   returns = {type = Pair(List(Atom),List(Pair(Formula, List(Assignment(Any)))))},
   mode = both};

rl_service {
   name = posqea,
   doc = "positive quantifier elimination with answer",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   arg = {pos = 2, name = assume, type = List(Atom), default = {}, doc = "atomic input assumptions"},
   returns = {type = List(Pair(Formula, List(Assignment(Any))))},
   mode = both};

rl_service {
   name = pqea,
   doc = "probabilistic quantifier elimination with answer (domain Z only)",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   arg = {pos = 2, name = probability, type = Rational, default = 1, doc = "probability in [0,1]"},
   arg = {pos = 3, name = assume, type = List(Atom), default = {}, doc = "atomic input assumptions"},
   returns = {type = List(Pair(Formula, List(Assignment(Any))))},
   mode = both};

rl_service {
   name = posqe,
   doc = "positive quantifier elimination (all variables are positive)",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   arg = {pos = 2, name = assume, type = List(Atom), default = {}, doc = "atomic input assumptions"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = posresolve,
   doc = "resolve non-standard symbols (min, max, abs) in formulas assuming all variables are positive",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula with additional functions/relations"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = pqe,
   doc = "probabilistic quantifier elimination (domain Z only)",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   arg = {pos = 2, name = probability, type = Rational, default = 1, doc = "p in [0,1]"},
   arg = {pos = 3, name = assume, type = List(Atom), default = {}, doc = "atomic input assumptions"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = preqe,
   doc = "pre-quantifier elimination (domain R only)",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = psat2pol,
   doc = "encode satisfiability into polynomial assuming all variables are positive",
   arg = {pos = 1, name = formula, type = Formula, doc = "quantifier-free input formula"},
   returns = {type = Term},
   mode = both};

rl_service {
   name = qe,
   doc = "quantifier elimination",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   arg = {pos = 2, name = assume, type = List(Atom), default = {}, doc = "atomic input assumptions"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = qea,
   doc = "quantifier elimination with answer",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   arg = {pos = 2, name = assume, type = List(Atom), default = {}, doc = "atomic input assumptions"},
   returns = {type = List(Pair(Formula, List(Assignment(Any))))},
   mode = both};

rl_service {
   name = qeg,
   doc = "regular quantifier elimination via multiple genric quantifier elimination",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = qeipo,
   doc = "quantifier elimination in position",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   arg = {pos = 2, name = assume, type = List(Atom), default = {}, doc = "atomic input assumptions"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = qews,
   doc = "quantifier elimination with selection",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   arg = {pos = 2, name = assume, type = List(Atom), default = {}, doc = "atomic input assumptions"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = qnum,
   doc = "number of occurring quantifier symbols ('ex', 'all')",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = Integer},
   mode = both};

rl_service {
   name = qsat,
   doc = "parametric quantified SAT",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula (QBF)"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = qsatdimacs,
   doc = "apply parametric quantified SAT to DIMACS file",
   arg = {pos = 1, name = file, type = String, doc = "file in DIMACS format"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = quine,
   doc = "Boolean normal form simplification following Quine",
   arg = {pos = 1, name = formula, type = Formula, doc = "input formula in CNF or DNF"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = qvarl,
   doc = "list of variables that are arguments of quantifier symbols",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = List(Variable)},
   mode = both};

rl_service {
   name = readdimacs,
   doc = "read DIMACS file into a first-order formula",
   arg = {pos = 1, name = file, type = String, doc = "file in DIMACS format"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = resolve,
   doc = "resolve non-standard symbols (min, max, abs) in formulas",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula with additional functions/relations"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = rnf,
   doc = "refined normal form (domain TERMS only)",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = sat2pol,
   doc = "encode satisfiability into polynomial",
   arg = {pos = 1, name = formula, type = Formula, doc = "quantifier-free input formula"},
   returns = {type = Term},
   mode = both};

rl_service {
   name = sign,
   doc = "replace all left hand sides of atoms with their sign",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula, typically variable-free"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = simpl,
   doc = "standard simplifier",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   arg = {pos = 2, name = assume, type = List(Atom), default = {}, doc = "atomic input assumptions"},
   arg = {pos = 3, name = depth, type = Integer, default = -1, doc = "maximal recursion depth"},
   arg = {pos = 4, name = sipo, type = Switch, doc = "prefer <, <=, >, >= over =, <>"},
   arg = {pos = 5, name = sipw, type = Switch, doc = "prefer <=, >= over <, >"},
   arg = {pos = 6, name = sifac, type = Switch, doc = "factorize left hand sides of non-order relations"},
   arg = {pos = 7, name = sifaco, type = Switch, doc = "factorize left hand sides of order relations"},
   arg = {pos = 8, name = siexpl, type = Switch, doc = "split f*g=0 and f*g<>0 in disjunctions and conjunctions, respectively"},
   arg = {pos = 9, name = siexpla, type = Switch, doc = "always split atoms f*g=0 and f*g<>0"},
   arg = {pos = 10, name = siplugtheo, type = Switch, doc = "plug in values obtained from implicit theory"},
   arg = {pos = 11, name = sipd, type = Switch, doc = "degree parity decompositon"},
   arg = {pos = 12, name = sisocx, type = Switch, doc = "sort non-atomic subformulas"},
   arg = {pos = 13, name = sid, type = Switch, doc = "smart simplification of derivatives (domain 'padic' only)"},
   arg = {pos = 14, name = sichk, type = Switch, doc = "check for equal nonatomic sibling formulas"},
   % xargs are ignored - PSL has a limit of 14 parameters
   xarg = {pos = 15, name = siatadv, type = Switch},
   xarg = {pos = 16, name = sitsqspl, type = Switch},
   xarg = {pos = 17, name = siidem, type = Switch},
   xarg = {pos = 18, name = siso, type = Switch},
   xarg = {pos = 19, name = sism, type = Switch},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = smt2Print,
   doc = "dump a formula as SMTLIB 2 input",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order formula"},
   arg = {pos = 2, name = file, type = String, default = "", doc = "file name to dump into, where """" uses stdout"},
   arg = {pos = 3, name = header, type = List(String), default = {}, doc = "typically a comment"},
   returns = {type = Any},
   mode = both};

rl_service {
   name = smt2Read,
   doc = "read SMTLIB 2 input file into formula",
   arg = {pos = 1, name = file, type = String, doc = "SMTLIB 2 input file"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = smtqe,
   doc = "quantifier elimination as SMT theory solver",
   arg = {pos = 1, name = assertions, type = List(Formula), doc = "assertions to be satisfied simultaneously"},
   returns = {type = Triplet(Enum(sat, unsat, unknown), List(Any), List(Integer))},
   mode = both};

rl_service {
   name = stex,
   doc = "stochastic experiment (domain Z only)",
   arg = {pos = 1, name = formula, type = Formula, doc = "input formula"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = struct,
   doc = "structural formula analysis",
   arg = {pos = 1, name = formula, type = Formula, doc = "input formula"},
   arg = {pos = 2, name = fac, type = Flag, default = yes, doc = "factorize terms"},
   arg = {pos = 3, name = basename, type = Variable, default = v, doc = "basename of newly introduced variables "},
   returns = {type = Pair(Formula, List(Assignment(Term)))},
   mode = both};

rl_service {
   name = symbolify,
   doc = "replace integer factors with symbolic names",
   arg = {pos = 1, name = formula, type = Formula, doc = "input formula"},
   returns = {type = Pair(Formula, List(Assignment(Integer)))},
   mode = both};

rl_service {
   name = tab,
   doc = "tableau simplification",
   arg = {pos = 1, name = formula, type = Formula, doc = "input formula"},
   arg = {pos = 2, name = cases, type = List(Formula), default = {}, doc = "a finite case distinction, typically complete"},
   arg = {pos = 3, name = iterate, type = Flag, default = yes, doc = "iterate tableau simplification as long as result gets smaller"},
   arg = {pos = 4, name = iterateb, type = Flag, default = yes, doc = "iterate on the single branches instead of the whole formula"},
   returns = {type = Formula},
   mode = both};

algebraic procedure rlatab(formula);
   <<
      lisp lprim "rlatab(formula) is depricated - use rltab(formula, iterate=no) instead.";
      rltab(formula, iterate=no)
   >>;

algebraic procedure rlitab(formula);
   <<
      lisp lprim "rlitab(formula) is depricated - use rltab(formula) instead.";
      rltab formula
   >>;

rl_service {
   name = tan2,
   doc = "tangent of half angle substitution",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = Formula},
   mode = both};

   rl_service {
   name = terml,
   doc = "set of contained terms",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = List(Term)},
   mode = both};

rl_service {
   name = termml,
   doc = " list of contained terms with numbers of occurrences",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = MList(Term)},
   mode = both};

rl_service {
   name = thsimpl,
   doc = "theory simplifer",
   arg = {pos = 1, name = theory, type = List(Atom), doc = "a list of atoms"},
   returns = {type = List(Atom)},
   mode = both};

rl_service {
   name = tnf,
   doc = "term normal form",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   arg = {pos = 2, name = terms, type = List(Term), doc = "terms for case distinction"},
   arg = {pos = 3, name = tnft, type = Switch, doc = "tree TNF in contrast to flat TNF"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = varl,
   doc = "lists of variables sperarated wrt. free and bound occurrences",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = Pair(List(Variable), List(Variable))},
   mode = both};

rl_service {
   name = vsl,
   doc = "virtual substitution with learning",
   arg = {pos = 1, name = constraints, type = List(Atom), doc = "a list of atomic constraints"},
   returns = {type = TruthValue},
   mode = both};

rl_service {
   name = wqe,
   doc = "weak quantifier elimination (domain Z only)",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   arg = {pos = 2, name = assume, type = List(Atom), default = {}, doc = "atomic input assumptions"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = wqea,
   doc = "weak quantifier elimination with answer",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   arg = {pos = 2, name = assume, type = List(Atom), default = {}, doc = "atomic input assumptions"},
   returns = {type = List(Triplet(Formula, List(Formula), List(Assignment(Any))))},
   mode = both};

rl_service {
   name = xqe,
   doc = "weakly parametric liner quantifier elimination",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = xqea,
   doc = "weakly parametric liner quantifier elimination with answer",
   arg = {pos = 1, name = formula, type = Formula, doc = "first-order input formula"},
   returns = {type = List(Pair(Formula, List(Assignment(Any))))},
   mode = both};

% SM-only services:

rl_service {
   name = identifyonoff,
   doc = "for rlidentify - should become obsolete at some point",
   argnum = 1,
   mode = sm
};

rl_service {
   name = lthsimpl,
   doc = "local qe theory simplification",
   argnum = 1,
   mode = sm
};

rl_service {
   name = nnfnot,
   doc = "logical negation as a positive formula",
   argnum = 1,
   mode = sm
};

rl_service {
   name = siaddatl,
   doc = "simplifier add to list of atomic formulas",
   argnum = 2,
   mode = sm
};

rl_service {
   name = subfof,
   doc = "substitution",
   argnum = 2,
   mode = sm
};

rl_service {
   name = surep,
   doc = "fast incomplete heuristic test for a formula to be valid",
   argnum = 2,
   mode = sm
};

endmodule;

end;
