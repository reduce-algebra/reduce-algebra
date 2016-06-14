module rltypes;

revision('rltypes, "$Id$");

copyright('rltypes, "(c) 2016 T. Sturm");

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

% To start with, we want to be able to pass forms between AM and SM without any
% conversion. One example is extended QE over the reals, where the domain takes
% care of the AM conversion of the answers, and we do want to formally specify
% within our type system what the answer terms are.

rl_type {
   name = Any,
   a2s = rl_identity1,
   s2a = rl_identity1,
   doc = {
      syntax = "An object that is not formally specified but explained with the service using it"}};

asserted procedure rl_identity1(x: Any): Any;
   % Unary identity function.
   x;

% Atomic types:

% Formulas

rl_type {
   name = Formula,
   a2s = rl_simp,
   s2a = rl_mk!*fof,
   equational,
   doc = {
      syntax = "A first-order formula in the current domain.",
      example = "all(x, ex(y, x = y))"}};

% Truth Values

rl_type {
   name = TruthValue,
   inherits = Formula,
   doc = {
      syntax = "{true, false}, a finite subset of first-order formulas.",
      example = "true"}};

% Atomic formulas

rl_type {
   name = Atom,
   inherits = Formula,
   a2s = rl_a2sAtom,
   equational,
   doc = {
      syntax = "An atomic formula in the current domain",
      example = "x^4*y^2 + y^2*x^4 - 3*x^2*y^2 + 1 >= 0"}};

asserted procedure rl_a2sAtom(x);
   begin scalar w;
      w := rl_simp x;
      if rl_cxp rl_op w then
      	 typerr(x, "atomic formula");
      return w
   end;

% Terms: All domains set properties rl_simpterm and rl_prepterm on the context
% identifier. redlog/rlcont.red provides corresponding wrappers which apply
% those. All this happens outside the Redlog schedulers.

rl_type {
   name = Term,
   a2s = rl_simpterm,
   s2a = rl_prepterm};

% Variables do not inherit Term. There is a difference between a kernel and the
% corresponding standard form.

rl_type {
   name = Variable,
   a2s = rl_a2sVariable,
   s2a = rl_identity1};

asserted procedure rl_a2sVariable(x: Any): List;
   if sfto_kernelp x then x else typerr(x, "Variable");


% Flag/Switch. Switches have a special treatment: their default is the setting
% of the corresponding Redlog switch.

rl_type {
   name = Flag,
   a2s = rl_a2sFlag,
   doc = {syntax = "An element from the finite set {on, yes, true, off, no, false}."}};

rl_type {
   name = Switch,
   a2s = rl_a2sFlag,
   doc = {
      syntax = "An element from the finite set {on, yes, true, off, no, false}.",
      semantics = "Used for temporarily rebinding Redlog switches."}};

asserted procedure rl_a2sFlag(u: Any): Boolean;
   % We expect certain keywords, which are not evaluated. In particular, the
   % only way to bind the Switch to the corresponding global switch is currently
   % not to specify anything and use the default value. This is something to
   % think about at some point.
   <<
      if fluidp u then
	 u := eval u;
      if u memq '(on yes true t) then
      	 t
      else if u memq '(off no false nil) then
      	 nil
      else
      	 rederr {"bad value", u, "for Switch; use one of on/yes/true or off/no/false"}
   >>;

% Integers

rl_type {
   name = Integer,
   a2s = rl_a2sInteger,
   s2a = rl_identity1,
   doc = {
      syntax = "An integer number of arbitrary size."}};

asserted procedure rl_a2sInteger(n: Any): Integer;
   % Algebraic to symbolic number.
   begin
      n := reval n;
      if not fixp n then typerr(n, "Integer");
      return n
   end;

% Keyword BNF

rl_type {
   name = KwBnf,
   a2s = rl_a2sKwBnf,
   doc = {
      syntax = "The finite set {auto, cnf, dnf}",
      semantics = "A keyword to be passed as an option. Keywords arguments are not evaluated.",
      example = "cnf"}};

asserted procedure rl_a2sKwBnf(bnf: Id): Id;
   <<
      if not memq(bnf, '(cnf dnf auto)) then
      	 typerr(bnf, "Bnf");
      bnf
   >>;

% Point

rl_type {
   name = Point,
   doc = {
      syntax = "A list of equations assigning values to some parameters.",
      example = "{a=3.14, b=22/7, c=0}"},
   a2s = rl_a2sPoint};

asserted procedure rl_a2sPoint(u: List): Alist;
   for each x in cdr reval u collect
      cadr x . caddr x;


% Parametric Point

rl_type {
   name = ParametricPoint,
   doc = {
      syntax = "A list of equations assigning to some variables parametric terms in an extended language."}};

% QeAnswer

rl_type {
   name = QeAnswer,
   s2a = rl_s2aQeAnswer,
   doc = {
      syntax = "A list of pairs {formula, sampleSolution}, where sampleSolution is a ?ParametricPoint in the vartiables of formula."}};

asserted procedure rl_s2aQeAnswer(res): List;
   'list . for each x in res collect
      {'list, rl_mk!*fof car x, 'list . cadr x};

% Rational

rl_type {
   name = Rational,
   s2a = rl_a2sRational,
   doc = {
      syntax = "An element from the set Q of rational numbers.",
      example = "1, -1/2, 0.1"}};

asserted procedure rl_a2sRational(x): SF;
   simp x;



% Compound types:

% Lists

rl_type {
   name = List,
   a2s = rl_a2sList,
   s2a = rl_s2aList};

asserted procedure rl_a2sList(l: List, a2sElement: Any): List;
   begin scalar w, !*rlsimpl;
      l := reval l;
      if not eqcar(l, 'list) then
 	 typerr(l, "List");
      return for each x in cdr l collect apply(a2sElement, {x})
   end;

asserted procedure rl_s2aList(l: List, s2aElement: Any): List;
   'list . for each x in l collect apply(s2aElement, {x});

% Pairs

rl_type {
   name = Pair,
   a2s = rl_a2sPair,
   s2a = rl_s2aPair};

asserted procedure rl_a2sPair(x: Any, a2sElem1: Any, a2sElem2: Any): List;
   begin scalar w, !*rlsimpl;
      x := reval x;
      if not eqcar(x, 'list) then
 	 typerr(x, "Pair");
      x := cdr x;
      if not eqn(length x, 2) then
 	 typerr(x, "Pair");
      return {apply(a2sElem1, {car x}), apply(a2sElem2, {cadr x})}
   end;

asserted procedure rl_s2aPair(x: Any, a2sElem1: Any, a2sElem2: Any): List;
   'list . {apply(a2sElem1, {car x}), apply(a2sElem2, {cdr x})};

% Multiplicity lists

rl_type {name = MList,
   s2a = rl_s2aMList,
   doc = {
      syntax = "A List of Pairs associating its elements with numbers, e.g., occurrences.",
      example = "{{a+b = 0, 4}, {a = c-d, 1}}"}};

asserted procedure rl_s2aMList(l: List, a2sElement: Any): List;
   'list . for each pr in l collect {'list, apply(a2sElement, {car pr}), cdr pr};

% Assignments

rl_type {
   name = Assignment,
   a2s = rl_a2sAssignment,
   s2a = rl_s2aAssignment,
   equational,
   doc = {
      syntax = "An equation, where the left hand side is a Variable",
      example = "v_1 = x^4*y^2 + y^2*x^4 - 3*x^2*y^2 + 1 >= 0"}};

asserted procedure rl_a2sAssignment(x: Any, a2sLhs: Any): List;
   begin scalar w;
      w := reval x;
      if not (listp w and eqn(length w, 3) and eqcar(w, 'equal)) and kernelp cadr w then
	 typerr(x, "Assignment");
      return cadr w .  apply(a2sLhs, {caddr w})
   end;

asserted procedure rl_s2aAssignment(x: List, s2aLhs: Any): List;
   {'equal, car x, apply(s2aLhs, {cdr x})};

% Temporary, used with the old scheduler:

procedure rl_a2s!-atl(x);
   rl_a2sList(x, 'rl_a2sAtom);

procedure rl_a2s!-sflist(x);
   rl_a2sList(x, 'rl_simpterm);

procedure rl_a2s!-idlist(x);
   rl_a2sList(x, rl_a2sVariable);

copyd('rl_a2s!-number, 'rl_a2sInteger);

procedure rl_s2a!-fl(x);
   rl_s2aList(x, 'rl_mk!*fof);

procedure rl_s2a!-idlist(x);
   rl_a2sList(x, 'rl_identity1);

copyd('rl_s2a!-atl, 'rl_s2a!-fl);
copyd('rl_s2a!-qea, 'rl_s2aQeAnswer);

endmodule;

end;
