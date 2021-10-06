module redlog;
% Reduce logic. This is the main package of Redlog. It is autoloaded when
% using rlset() for choosing a context. Further parts of Redlog that are
% technically packages, too, are listed in the 'known!-packages property of
% the identifier 'redlog in the first put() below. None of them requires
% explicit loading by the user.

revision('redlog, "$Id$");

copyright('redlog, "(c) 1995-2021 A. Dolzmann, T. Sturm");

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

create!-package('(redlog rlprint rlami rltypes rlservices rlblackboxes rlcont), nil);

exports quotelog, rl_mkbb, rl_mkserv, rl_op, rl_arg1, rl_arg2l, rl_arg2r, rl_argn, 
   rl_var, rl_mat, rl_mk1, rl_mk2, rl_mkn, rl_smkn, rl_mkq, rl_quap, rl_junctp, rl_basbp, 
   rl_extbp, rl_boolp, rl_tvalp, rl_cxp, rl_mk!*fof, rl_reval, rl_prepfof, rl_cleanup, 
   rl_simp, rl_simpbop, rl_simpq, rl_simp!*fof, rl_lengthlogical, rl_sub!*fof, 
   rl_print!*fof, rl_priq, rl_ppriop, rl_fancy!-ppriop, rl_fancy!-priq, 
   rl_interf1, rl_a2s!-decdeg1, rl_a2s!-varl, rl_a2s!-number, rl_a2s!-id, 
   rl_a2s!-atl, rl_a2s!-posf, rl_s2a!-simpl, rl_s2a!-gqe, rl_s2a!-gqea, rl_s2a!-qea, 
   rl_s2a!-opt, rl_s2a!-atl, rl_s2a!-ml, rl_s2a!-term, rl_s2a!-decdeg1, 
   rl_a2s!-targfn, rl_a2s!-terml, rl_s2a!-terml, rl_a2s!-term, rl_s2a!-varl, 
   rl_s2a!-fbvarl, rl_s2a!-struct, rlmkor, rlmkand, rl_set!$, rl_set, rl_exit, 
   rl_enter, rl_onp, rl_vonoff, rl_updcache, rl_serviadd, rl_bbiadd;

put('redlog, 'known!-packages,
    '(acfsf cl dcfsf dvfsf ibalp mri ofsf pasf qqe qqe_ofsf redlog rlsupport rltools smt talp tplp));

struct Formula;
struct FormulaL asserted by listp;
struct Void;

% The specification of ? (rl_help) implmented in the rlsupport module goes here, 
% because it requires a completely built rlsupport itself.

rl_builtin {
   name = !?, 
   doc = {
      synopsis = {pos = 1, text = "?"}, 
      synopsis = {pos = 1, text = "?builtins"}, 
      synopsis = {pos = 1, text = "?services"}, 
      synopsis = {pos = 1, text = "?types"}, 
      synopsis = {pos = 1, text = "?switches"}, 
      synopsis = {pos = 1, text = "?X"}, 
      description = "help", 
      returns = "Void", 
      arg = {pos = 1, name = "X", text = "a specific service, type, or switch"}
   }
};

% context identifier:
fluid '(rl_cid!*);

% List of fluid variables corresponding to black boxes. Those variables are
% rebound to the domain-specific SM entry points when switching the context with
% rl_set. That is, rl_service(...) will apply('rl_service!*, {...}), where
% rl_service!* is in rl_servl!* and e.g, rl_service!* = 'ofsf_service.
fluid '(rl_servl!*);

% List of fluid variables corresponding to black boxes. Those variables are
% rebound when switching the context with rl_set. They are used via apply within
% genric implementaion in the cl module:
fluid '(rl_bbl!*);

% default language (context), probably obsolete:
fluid '(rl_deflang!*);

fluid '(rl_argl!*);
fluid '(rl_usedcname!*);
fluid '(rl_ocswitches!*);

fluid '(!*utf8);

fluid '(fancy!-line!* fancy!-pos!*);

fluid '(!*strict_argcount);

% Display banner with rlset; initialized in support/entry.red:
switch rlabout;

% Interactive use in algebraic mode:
switch rlbrop, rlsimpl, rlrealtime;
on1  'rlbrop;            % Put parenthesis around conjunctions within discjunctions
off1 'rlsimpl;           % Automatically process algebraic mode input with rl_simpl
off1 'rlrealtime;        % Display wall clock times in the style of "on time"

% Parametric denominators in the input:
switch rladdcond, rlnzden, rlposden;
off1 'rladdcond;         % Explicitly add assumptions made on non-zeroness or positivity
off1 'rlnzden;           % Assume non-zero
off1 'rlposden;          % Assume positive

% Print informative messages during computations:
switch rlverbose;
off1 'rlverbose;

% Break complex kernels:
switch rlbrkcxk;
put('rlbrkcxk, 'simpfg, '((t (rmsubs)) (nil (rmsubs))));
off1 'rlbrkcxk;

% Standard simplifier (rl_simpl):
switch rlsiso, rlsipw, rlsipo, rlsifaco, rlsiplugtheo, rlsid;

on1  'rlsid;         % Smart simplification of derivatives (dcfsf only)
on1  'rlsipo;        % Prefer <, <=, >, >= over =, <>
on1  'rlsiplugtheo;  % Plug in unique values for variables when discovered (dcfsf only)
off1 'rlsipw;        % Prefer <=, >= over <, >
on1  'rlsiso;        % Sort subformulas on each boolean level

switch rlsusi, rlsusiadd, rlsusigs, rlsusimult;
off1 'rlsusi;
off1 'rlsusimult;
off1 'rlsusigs;
on1  'rlsusiadd;

% Groebner simplifier (rl_gsn):
switch rlgsbnf, rlgserf, rlgsprod, rlgsrad, rlgsred, rlgssub, rlgsutord, rlgsvb;
on1  'rlgssub;
on1  'rlgsrad;
on1  'rlgsred;
on1  'rlgserf;
off1 'rlgsprod;
on1  'rlgsvb;
on1  'rlgsbnf;
off1 'rlgsutord;

% Cylindrical algebraic decomposition (rl_cad):
switch rlanuexgcdnormalize, rlanuexsgnopt, rlanuexverbose, rlcaddecdeg,
       rlcaddnfformula, rlcadextonly, rlcadfasteval, rlcadfulldimonly, rlcadpbfvs,
       rlcadpreponly, rlcadprojonly, rlcadrawformula, rlcadte, rlcadtrimtree,
       rlcadverbose;
on1  'rlcaddnfformula;
off1 'rlcadpreponly;
off1 'rlcadprojonly;
off1 'rlcadextonly;
off1 'rlcadverbose;
on1  'rlcadfasteval;
off1 'rlcadfulldimonly;
on1  'rlcadtrimtree;
off1 'rlcadrawformula;
off1 'rlanuexverbose;
on1  'rlanuexgcdnormalize;
off1 'rlanuexsgnopt;
off1 'rlcaddecdeg;
on1  'rlcadte;
on1  'rlcadpbfvs;

% Hermitian quantifier elimination (rl_hqe):
switch rlhqeconnect, rlhqedim0, rlhqegbdimmin, rlhqegbred, rlhqestrconst,
       rlhqetfcfast, rlhqetfcfullsplit, rlhqetfcsplit, rlhqetheory, rlhqevarsel,
       rlhqevarselx, rlhqevb;
on1  'rlhqetfcsplit;     % Split type formula computation up to degree 4.
off1 'rlhqetfcfast;      % Split type formula computation unconditionally
off1 'rlhqetfcfullsplit; % Compute case distinctions only for unknown signs
off1 'rlhqevb;           % More verbose output
on1  'rlhqevarsel;       % Optimize variable selection in the case dim I=n
on1  'rlhqevarselx;      % Advanced optimization with more computational effort
on1  'rlhqetheory;       % Use initial conditions for CGB computation
off1 'rlhqedim0;         % Only zero dimensional branches
off1 'rlhqegbred;        % Use reduced Groebner systems
off1 'rlhqeconnect;      % Connect branches which differ only in the theory
on1  'rlhqestrconst;     % Use combined structure constants
on1  'rlhqegbdimmin;     % Choose maximal independent variable set with minimal cardinality in the case 0<dim<n

% Virtual substitution (rl_qe): See module cl/clqeenv

switch rlxopt, rlxoptpl, rlxoptri, rlxoptric, rlxoptrir, rlxoptsb, rlxoptses;
on1  'rlxopt;
on1  'rlxoptsb;          % Select boundary type
on1  'rlxoptpl;          % Passive list
on1  'rlxoptri;          % Result inheritance
off1 'rlxoptric;         % Result inheritance to container
off1 'rlxoptrir;         % Result inheritance to result
on1  'rlxoptses;         % Structural elimination sets

% Linear optimization via virtual substitution (ofsf_opt):
switch rlopt1s, rlparallel;
off1 'rlopt1s;           % Keep only one solution with optimal value objective function
off1 'rlparallel;        % Use PVM-based parallelization with PSL on a Cray YMP4/T3D (historical)

% Virtual substitution with learning (rl_vsl):
switch rlvsllearn, rlvsllog;
on1  'rlvsllearn;        % Learning for ofsf vs with learning
off1 'rlvsllog;          % Additional verbose output for ofsf vs with learning

% Boolean normal forms (rl_gsc, rl_gsd):
switch rlbnfsac, rlbnfsm;
on1  'rlbnfsac;
off1 'rlbnfsm;

% Resolution of definable functions (rl_resolve):
switch rlresi;
on1 'rlresi;             % Implicit (local) simplification

% Greatest common divisor (sfto_gcdf!*):
switch rldavgcd;
on1 'rldavgcd;           % Heuristically decide between using gcdf or ezgcdf

% Determinant (ofsf_det):
switch rlourdet, rlvmatvb;
off1 'rlourdet;
off1 'rlvmatvb;          % Debugging output within ofsf_det

% Elimination normal form (dcfsf_enf):
switch rlenffac, rlenffacne, rlplsimpl;
off1 'rlenffac;
on1  'rlenffacne;
on1  'rlplsimpl;

% Tree normal form (cl_tnf):
switch rltnft;
on1 'rltnft;             % Return a "tree" instead of a "flat" tree normal form

procedure quotelog(x); 'logical;

put('logical, 'tag, '!*fof);
put('logical, 'evfn, 'rl_reval);
put('logical, 'subfn, 'rl_sub!*fof);
put('logical, 'lengthfn, 'rl_lengthlogical);

rl_builtin {
   name = true, 
   doc = {
      synopsis = {pos = 1, text = "true"}, 
      description = "constant formula true", 
      returns = "Formula", 
      seealso = false
   }
};

put('true, 'rtype, 'logical);

rl_builtin {
   name = false, 
   doc = {
      synopsis = {pos = 1, text = "false"}, 
      description = "constant formula false", 
      returns = "Formula", 
      seealso = true
   }
};

put('false, 'rtype, 'logical);

put('!*fof, 'rtypefn, 'quotelog);
put('!*fof, 'rl_simpfn, 'rl_simp!*fof);

rl_builtin {
   name = and, 
   doc = {
      synopsis = {pos = 1, text = "f_1:Formula and ... and f_n:Formula"}, 
      description = "Boolean conjunction", 
      returns = "Formula", 
      arg = {pos = 1, name = "f_1, ..., f_n", text = "argument formulas"}, 
      seealso = mkand, 
      seealso = or
   }
};

put('and, 'rtypefn, 'quotelog);
put('and, 'rl_simpfn, 'rl_simpbop);
put('and, 'rl_prepfn, 'rl_prepbop);

rl_builtin {
   name = or, 
   doc = {
      synopsis = {pos = 1, text = "f_1:Formula or ... or f_n:Formula"}, 
      description = "Boolean disjunction", 
      returns = "Formula", 
      arg = {pos = 1, name = "f_1, ..., f_n", text = "argument formulas"}, 
      seealso = and, 
      seealso = impl, 
      seealso = mkor
   }
};

put('or, 'rtypefn, 'quotelog);
put('or, 'rl_simpfn, 'rl_simpbop);
put('or, 'rl_prepfn, 'rl_prepbop);

rl_builtin {
   name = not, 
   doc = {
      synopsis = {pos = 1, text = "not f:Formula"}, 
      description = "Boolean negation", 
      returns = "Formula", 
      arg = {pos = 1, name = "f", text = "argument formula"}, 
      seealso = impl
   }
};

put('not, 'rtypefn, 'quotelog);
put('not, 'rl_simpfn, 'rl_simpbop);
put('not, 'rl_prepfn, 'rl_prepbop);

rl_builtin {
   name = impl, 
   doc = {
      synopsis = {pos = 1, text = "f_1:Formula impl f_2:Formula"}, 
      description = "Boolean implication", 
      returns = "Formula", 
      arg = {pos = 1, name = "f_1", text = "argument formula"}, 
      arg = {pos = 2, name = "f_2", text = "argument formula"}, 
      seealso = equiv, 
      seealso = not, 
      seealso = or, 
      seealso = repl
   }
};

algebraic infix impl;
put('impl, 'rtypefn, 'quotelog);
put('impl, 'rl_simpfn, 'rl_simpbop);
put('impl, 'rl_prepfn, 'rl_prepbop);
put('impl, 'number!-of!-args, 2);

rl_builtin {
   name = repl, 
   doc = {
      synopsis = {pos = 1, text = "f_1:Formula repl f_2:Formula"}, 
      description = "Boolean reverse implication (aka replication)", 
      returns = "Formula", 
      arg = {pos = 1, name = "f_1", text = "argument formula"}, 
      arg = {pos = 2, name = "f_2", text = "argument formula"}, 
      seealso = equiv, 
      seealso = impl
   }
};

algebraic infix repl;
put('repl, 'rtypefn, 'quotelog);
put('repl, 'rl_simpfn, 'rl_simpbop);
put('repl, 'rl_prepfn, 'rl_prepbop);
put('repl, 'number!-of!-args, 2);

rl_builtin {
   name = equiv, 
   doc = {
      synopsis = {pos = 1, text = "f_1:Formula equiv f_2:Formula"}, 
      description = "Boolean biimplication (aka equivalence)", 
      returns = "Formula", 
      arg = {pos = 1, name = "f_1", text = "argument formula"}, 
      arg = {pos = 2, name = "f_2", text = "argument formula"}, 
      seealso = impl, 
      seealso = repl
   }
};

algebraic infix equiv;
put('equiv, 'rtypefn, 'quotelog);
put('equiv, 'rl_simpfn, 'rl_simpbop);
put('equiv, 'rl_prepfn, 'rl_prepbop);
put('equiv, 'number!-of!-args, 2);

flag('(impl repl equiv and or), 'spaced);

precedence equiv, when;
precedence repl, equiv;
precedence impl, repl;
flag('(true false), 'reserved);

rl_builtin {
   name = ex, 
   doc = {
      synopsis = {pos = 1, text = "ex(x: Variable, formula: Formula)"}, 
      synopsis = {pos = 2, text = "ex(X: List(Variable), formula: Formula)"}, 
      description = "existential quantifier", 
      returns = "Formula", 
      arg = {pos = 1, name = "x", text = "variable to be existentially quantified"}, 
      arg = {pos = 2, name = "X", text = "list of variables to be existentially quantified"}, 
      arg = {pos = 2, name = "formula", text = "formula to be prefixed with the existential quantifier(s)"}, 
      seealso = all, 
      seealso = rlex
   }
};

put('ex, 'rtypefn, 'quotelog);
put('ex, 'rl_simpfn, 'rl_simpq);
put('ex, 'number!-of!-args, 2);
put('ex, 'rl_prepfn, 'rl_prepq);

rl_builtin {
   name = all, 
   doc = {
      synopsis = {pos = 1, text = "all(x: Variable, formula: Formula)"}, 
      synopsis = {pos = 2, text = "all(X: List(Variable), formula: Formula)"}, 
      description = "universal quantifier", 
      returns = "Formula", 
      arg = {pos = 1, name = "x", text = "variable to be universally quantified"}, 
      arg = {pos = 2, name = "X", text = "list of variables to be universally quantified"}, 
      arg = {pos = 2, name = "formula", text = "formula to be prefixed with the universal quantifier(s)"}, 
      seealso = ex, 
      seealso = rlall
   }
};

put('all, 'rtypefn, 'quotelog);
put('all, 'rl_simpfn, 'rl_simpq);
put('all, 'number!-of!-args, 2);
put('all, 'rl_prepfn, 'rl_prepq);

rl_builtin {
   name = bex, 
   doc = {
      synopsis = {pos = 1, text = "bex(x: Variable, bound: Formula, formula: Formula)"}, 
      description = "bounded existential quantifier (integer domain only)", 
      returns = "Formula", 
      arg = {pos = 1, name = "x", text = "variable to be existentially quantified"}, 
      arg = {pos = 2, name = "bound", text = "quantifier-free formula that constrains x to a finite set"}, 
      arg = {pos = 2, name = "formula", text = "formula to be prefixed with the bounded existential quantifier"}, 
      seealso = ball
   }
};

put('bex, 'rtypefn, 'quotelog);
put('bex, 'rl_simpfn, 'rl_simpbq);
put('bex, 'number!-of!-args, 3);
put('bex, 'rl_prepfn, 'rl_prepbq);

rl_builtin {
   name = ball, 
   doc = {
      synopsis = {pos = 1, text = "ball(x: Variable, bound: Formula, formula: Formula)"}, 
      description = "bounded universal quantifier (integer domain only)", 
      returns = "Formula", 
      arg = {pos = 1, name = "x", text = "variable to be universally quantified"}, 
      arg = {pos = 2, name = "bound", text = "quantifier-free formula that constrains x to a finite set"}, 
      arg = {pos = 2, name = "formula", text = "formula to be prefixed with the bounded universal quantifier"}, 
      seealso = bex
   }
};

put('ball, 'rtypefn, 'quotelog);
put('ball, 'rl_simpfn, 'rl_simpbq);
put('ball, 'number!-of!-args, 3);
put('ball, 'rl_prepfn, 'rl_prepbq);

flag('(rl_simpbop rl_simpq rl_simpbq rl_prepbop rl_prepq rl_prepbq), 'full);

rl_builtin {
   name = rlabout, 
   doc = {
      synopsis = {pos = 1, text = "rlabout()"}, 
      description = "print revision information for REDLOG", 
      returns = "Void"
   }
};

algebraic procedure rlabout();
   lisp rl_about();

asserted procedure rl_about();
   begin scalar rev, date, time, year;
      {rev, date, time} := rl_getversion();
      ioto_tprin2t {"Redlog Revision ", rev, " of ", date, ", ", time};
      year := car lto_stringSplit(date, '(!-));
      ioto_tprin2 {"(c) 1992-", year, " T. Sturm and A. Dolzmann"};
      ioto_prin2t " (www.redlog.eu)";
      ioto_tprin2t "type ?; for help"
   end;

asserted procedure rl_getversion(): List3;
   begin scalar w, res; integer rev, cur;
      for each pack in get('redlog, 'known!-packages) do
         for each mod in get(pack, 'package) do <<
            w := lto_stringSplit(get(mod, 'revision), {'! , !$eol!$, cr!*, ff!*, tab!*});
            if length w = 7 then <<
               rev := lto_id2int lto_string2id nth(w, 3);
               if rev > cur then <<
                  cur := rev;
                  res := {nth(w, 3), nth(w, 4), nth(w, 5)}
               >>
            >> else
               lprim lto_sconcat {"revision missing on ", lto_at2str pack, "/", lto_at2str mod}
         >>;
      return res
   end;

asserted inline procedure rl_op(f: Formula): Id;
   % Reduce logic operator. Returns the top-level operator of [f]. In this
   % sense, truth values are operators.
   if atom f then f else car f;

asserted inline procedure rl_arg1(f: Formula): Formula;
   % Reduce logic argument of formula with unary operator. Returns the single
   % argument formula of f.
   cadr f;

asserted inline procedure rl_arg2l(f: Formula): Formula;
   % Reduce logic left hand side argument of formula with binary operator.
   % Returns the left hand side argument of f.
   cadr f;

asserted inline procedure rl_arg2r(f: Formula): Formula;
   % Reduce logic right hand side argument of formula with binary operator.
   % Returns the right hand side argument of f.
   caddr f;

asserted inline procedure rl_argn(f: Formula): FormulaL;
   % Reduce logic argument list of formula with n-ary operator. Returns the
   % arguments of f as a list.
   cdr f;

asserted inline procedure rl_var(f: Formula): Kernel;
   % Reduce logic variable. f starts with a quantifier. Returns the quantified
   % variable.
   cadr f;

asserted inline procedure rl_mat(f: Formula): Formula;
   % Reduce logic matrix. f starts with a quantifier. Returns the matrix
   % formula.
   caddr f;

asserted inline procedure rl_b(f: Formula): Any;
   % Reduce logic bound. f starts with a bounded quantifier. Returns the
   % bound.
   cadddr f;

asserted inline procedure rl_mk1(uop: Id, arg: Formula): Formula;
   % Reduce logic make formula for unary operator. Returns uop(arg).
   {uop, arg};

asserted inline procedure rl_mk2(bop: Id, larg: Formula, rarg: Formula): Formula;
   % Reduce logic make formula for binary operator. Returns bop(larg, rarg).
   {bop, larg, rarg};

asserted inline procedure rl_mkn(nop: Id, argl: FormulaL): Formula;
   % Reduce logic make formula for n-ary operator. Returns
   % nop(argl[1], ..., argl[n]).
   nop . argl;

asserted inline procedure rl_smkn(nop: Id, argl: FormulaL): Formula;
   % Reduce logic safe make formula for n-ary operator. nop is one
   % of 'and, 'or. If argl = (), return a suitable truth value. If
   % argl = (a1), return a1. Else return nop(argl[1], ..., argl[n]).
   if argl and cdr argl then
      nop . argl
   else if null argl then
      if nop eq 'and then 'true else 'false
   else
      car argl;

asserted inline procedure rl_mkq(q: Id, v: Kernel, m: Formula): Formula;
   % Reduce logic make quantified formula. q is one of 'ex, 'all. Returns
   % q(v, m).
   {q, v, m};

asserted inline procedure rl_mkbq(q: Id, v: Kernel, b: Any, m: Formula): Formula;
   % Reduce logic make bounded-quantified formula. [q] is one of 'bex, 'ball.
   % Returns q(v : b, m).
   {q, v, m, b};

asserted inline procedure rl_quap(x: Any): Boolean;
   % Reduce logic quantifier predicate.
   x eq 'ex or x eq 'all;

asserted inline procedure rl_bquap(x: Any): Boolean;
   % Reduce logic bounded quantifier predicate.
   x eq 'bex or x eq 'ball;

asserted inline procedure rl_junctp(x: Any): Boolean;
   % Reduce logic junctor predicate.
   x eq 'or or x eq 'and;

asserted inline procedure rl_basbp(x: Any): Boolean;
   % Reduce logic basic boolean operator predicate.
   rl_junctp x or x eq 'not;

asserted inline procedure rl_extbp(x: Any): Boolean;
   % Reduce logic extended boolean operator predicate.
   x eq 'impl or x eq 'repl or x eq 'equiv;

asserted inline procedure rl_boolp(x: Any): Boolean;
   % Reduce logic boolean operator predicate.
   rl_basbp x or rl_extbp x;

asserted inline procedure rl_tvalp(x: Any): Boolean;
   % Reduce logic truth value predicate.
   x eq 'true or x eq 'false;

asserted inline procedure rl_cxp(x: Any): Boolean;
   % Reduce logic "complex", in the sense of non-atomic, operator predicate.
   rl_tvalp x or rl_boolp x or rl_quap x or rl_bquap x;

endmodule;

end;
