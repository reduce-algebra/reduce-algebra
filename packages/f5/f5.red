module f5;
% f5. Main module. The F5 Algorithm for computing Groebner bases.
% Contains the AM and SM entry points.

revision('f5, "$Id$");

copyright('f5, "(c) 2022 A. Demin, T. Sturm, MPI Informatics, Germany");

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

% The f5 module provides the implementation of the Faugère's F5 algorithm
%     https://www-polsys.lip6.fr/~jcf/Papers/F02a.pdf
%
% The interface contains the operator `f5` with the following signature
%     `f5(polynomials: List, vars: List, order: Id)`
% Where
%   . `polynomials` is a list of expressions, the Ideal generators,
%   . `vars` is a list of Reduce identifiers with respect to which the basis is computed;
%      All identifiers occurring in `polynomials` but not in `vars` are considered
%      to belong to the coefficients.
%   . `order` is the identifier of the term order to compute the basis in,
%      possible options are `lex`, `revgradlex`;
%
% For example, one can use F5 to compute the Groebner basis of
% x*y + 1, y*z + 1 in lex term order with x > y > z in the following way:
%
%  > load_package f5;
%  > f5({x*y + 1, y*z + 1}, {x, y, z}, lex);
%
%  or, using the `torder` command to set the term order:
%
%  > load_package f5;
%  > torder({x, y, z}, lex);
%  > f5({x*y + 1, y*z + 1});
%
% For different combinations of torder and input arguments F5 works
% much the same way as the GROEBNER package:
% If torder has been called before, then
%     f5(system) uses the term order set by torder;
%     f5(system, vars, ord) temporarily shadows torder
%     and uses input arguments to set the term order.
% If torder has not been called before, then
%     f5(system) extracts variables as identifiers present in input system,
%                 and uses default sort mode from torder (currently, the default is lex);
%     f5(system, vars, ord) uses input arguments.

% The f5core file is the heart of the package, it contains
% the implementation of the F5 algorithm with the Rewritten Criterion.
% The f5poly implements `Polynomial` interface, which is used by the
% f5lp to implement a `LabeledPolynomial`. f5core operates mainly
% on `LabeledPolynomial` objects.
% The f5param file allows tracking parameter assumtions during
% Groebner computation. The f5stat allows recording and printing
% useful statistics about F5 algorithm steps execution for each f5 call.
%
% Other files in the directory implement experimental algorithms and are not documented
create!-package('(f5 f5core f5lp f5poly f5param f5stat), nil);

fluid '(!*backtrace);

% Needed for compatibility with torder.
% global!-dipvars!* is a list of kernels, 
% which currently serve as variables in polynomial ring.
% vdpsortmode!* is a "sort mode" identifier (e.g., lex, revgradlex)  
fluid '(global!-dipvars!*);
fluid '(vdpsortmode!*);

% Currently, there are several switches available, these are described below
% . f5fractionfree (default is OFF)
% . f5interreduce  (default is OFF)
% . f5statistics (default is OFF)
% . f5sugar (default is ON)
% . f5usef5c (default is OFF)
% . f5parametric (default is OFF)
% . f5parametricNormalize (default is OFF)

% f5fractionfree - If this is ON, then coefficients of polynomials
%              in the output basis do not contain fractions.
%              Otherwise, each polynomial in the output is monic.
%              Is OFF by default.
% For example,
%  > off f5fractionfree;
%  > f5({5x + y, 2x + 1}, {x, y}, lex);
%          1       5
%    {x + ---,y - ---}
%          2       2
%
%  > on f5fractionfree;
%  > f5({5x + y, 2x + 1}, {x, y}, lex);
%
%    {2*x + 1,2*y - 5}
%
switch f5fractionfree=off;

% f5interreduce - If the output basis should be fully interreduced.
%                If this is ON, each generator in the output basis is
%                in the normal form with respect to other generators.
%                Otherwise, only head terms of polynomials in the basis
%                are reduced (and the size of the basis is minimal).
%                Is OFF by default.
%                Generally, f5 with f5interreduce ON is considerably slower.
%  For example,
%  > off f5interreduce;
%  > f5({x^2 + x + y, x*y + y, x^3 + x}, {x, y}, lex);
%
%    {x + y,y}
%
%  > on f5interreduce;
%  > f5({x^2 + x + y, x*y + y, x^3 + x}, {x, y}, lex);
%
%    {x,y}
%
switch f5interreduce=off;

% f5statistics - If this is ON, collects and prints the following statistics
%                with each call to f5:
%                 the number of polynomials reduced,
%                 the number of polynomials reduced to zero,
%                 the number of calls to normal form,
%                 the range of produced critical pairs degrees.
%                All statistics above are differentiated by the signature index.
%                By default, this is OFF, the information
%                is neither collected nor printed.
switch f5statistics=off;

% f5sugar - If ON, sugar selection strategy is used;
%           otherwise, uses normal selection strategy.
%              https://doi.org/10.1145/120694.120701
%           Is ON by default.
switch f5sugar=on;

% f5usef5c - If OFF, the F5C algorithm is used in f5:
%              https://doi.org/10.1016%2Fj.jsc.2010.06.019
%            Otherwise, does not interreduce intermediate bases.
%            Default option is OFF.
switch f5usef5c=off;

% f5parametric - If set on, parametric coefficients are 
%                not considered as rational functions but
%                as parametric expressions. Necessary assumptions
%                on the non-vanishing of such parametric expressions
%                are made during computation.
%                Default option if OFF.
switch f5parametric=off;

% f5parametricNormalize - This switch is considered only with f5paramettic ON. 
%                         Its default is OFF. "Normalize" refers to the conversion
%                         to primitive/monic polynomials with f5fractionfree ON/OFF.
%                         If set OFF, normalization factors are computed over the integers.
%                         If set ON, normalization factors are computed over the polynomial
%                         ring in the parameters, and necessary assumptions on their
%                         non-vanishing are made.
switch f5parametricNormalize=off;

% Assertions should be OFF in production.
load!-package 'assert;
off1 'assert;
off1 'assert_procedures;
off1 'assert_inline_procedures;
off1 'assertinstall;
off1 'evalassert;

% For string manipulations in table printing;
% For `sfto_kernelp`;
load!-package 'rltools;

% Two functions in the interface: f5 and f5dumpAssumptions
put('f5, 'psopfn, 'f5_groebner);

operator f5dumpAssumptions; 
asserted procedure f5dumpAssumptions();
   'list . param_dumpAssumptions();

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%% STRUCTS DEFINITIONS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% interface implemented in f5poly.red
procedure f5_isPolynomial(x); eqcar(x, 'p);
procedure f5_isCoeff(x); sqp(x) or integerp(x);
struct Polynomial checked by f5_isPolynomial;
struct Terms checked by listp;
struct Term checked by listp;
struct Coeffs checked by listp;
% Coeff can be either an Integer or a Standard Quotient.
struct Coeff checked by f5_isCoeff;

% interface implemented in f5lp.red
procedure f5_isLabeledPolynomial(x); eqcar(x, 'lp);
procedure f5_isSignature(x); eqcar(x, 'sgn);
struct LabeledPolynomial checked by f5_isLabeledPolynomial;
struct Signature checked by f5_isSignature;

% interface implemented in f5primes.red (not used currently)
procedure f5_isPrimetracker(x); eqcar(x, 'pt);
struct Primetracker checked by f5_isPrimetracker;

% interface implemented in f5core.red
procedure f5_isBasistracker(x); eqcar(x, 'bt);
procedure f5_isCriticalPair(x); (null x) or eqcar(x, 'cp);
procedure f5_isRewriteRule(x); eqcar(x, 'rr);
struct Basistracker checked by f5_isBasistracker;
struct CriticalPair checked by f5_isCriticalPair;
struct RewriteRule checked by f5_isRewriteRule;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% A note on the relations of functions in this file:
% - algebraic interface function `f5` is the same as `f5_groebner`; 
% - there are 4 symbolic interface functions for computing GB:
%     `f5_groebnerp`, `f5_groebnerf`, `f5_groebnerq`;
% - all of the above functions use `f5_groebnerpoly`, 
%   which operates on internal `Polynomial` type, as a backend;
% - `f5_groebner` calls to `f5_groebnerp` and, hence, also ends up in `f5_groebnerpoly`.

% The main function that parses input arguments and calls the f5 routine
%
% First, if the format of the input is correct (see the format in the header of this file),
% the term order is set and the input basis is passes to the `f5_groebnerp` function. 
%   `f5_groebnerp` convert input expressions to polynomials, and passes them on to 
% the `f5_groebnerpoly`. There, input polynomials are cleaned a bit, and simple basis cases are handled.
% Polynomials are then passes to `core_constructModule`, which converts each of
% them to a `LabeledPolynomial` object, and outputs the list of LabeledPolynomials.
%   These LabeledPolynomials are then passed to `core_groebner1`. Both of those functions
% return a list that contains a Groebner basis, and each generator in the basis
% is represented as a `LabeledPolynomial`. Finally, each item in the Groebner basis list
% is converted to a Lisp Prefix, and the resulting list is returned.
asserted procedure f5_groebner(u: List): List;
   begin scalar inputBasis, f, vars, ord, fsq,
                varsNum, varsDen, saveTorder, w;
      % handle errors in the input
      if null u or not (listp u) then
         f5_argumentError();
      inputBasis := reval pop u;
      if not (listp inputBasis) or not (pop inputBasis eq 'list) or null inputBasis then
         f5_argumentError();
      % set the term order
      saveTorder := if not null u then <<
         % variables and sort mode are specified in f5 call
         vars := reval pop u;
         if not (listp vars) or not (pop vars eq 'list) then
            f5_argumentError();
         for each var in vars do
            if not sfto_kernelp(var) then
               f5_argumentError();
         ord := pop u;
         poly_initRing({vars, ord})
      >> else if not null cdr global!-dipvars!* then <<
         % both variables and sort mode have been specified using torder
         poly_initRing(nil)
      >> else <<
         % sort mode has been specified using torder,
         % variables are taken from the inputBasis
         for each f in inputBasis do <<
            fsq := simp f;
            varsNum := union(varsNum, kernels numr fsq);
            varsDen := union(varsDen, kernels denr fsq)
         >>;
         if varsDen then
            lprim {varsDen, "implicitly declared as parameters"};
         vars := lto_setminus(varsNum, varsDen);
         vars := sort(vars, 'ordp);
         poly_initRing({vars})
      >>;
      w := errorset({'f5_groebnerp, mkquote inputBasis}, t, !*backtrace);
      torder cdr saveTorder;
      if errorp w then
         return nil;
      return 'list . car w
   end;

% Lisp Prefix --> Lisp Prefix
% Given a list of lisp prefix forms, converts them to polynomials,
% computes the Groebner basis of the corresponding ideal,
% and returns the basis elements as a list of lisp standard prefix.
% Important invariant: 
%    the term order is preserved during the out conversion.   
asserted procedure f5_groebnerp(inputBasisLp: List): List;
   begin scalar basis;
      basis := f5_groebnerpoly(for each f in inputBasisLp collect
                                 poly_sq2poly simp f);
      return (for each f in basis collect poly_poly2lp f)
   end;

% Standard Form --> Standard Form
% Given a list of standard forms, converts them to SQ, then uses `f5_groebnerq`
% to compute the Groebner basis of the corresponding ideal,
% and returns the basis elements as a list of standard forms.
asserted procedure f5_groebnerf(inputBasisSf: List): List;
   begin scalar basis;
      basis := f5_groebnerq(for each f in inputBasisSf collect (f ./ 1));
      return (for each f in basis collect numr f)
   end;

% Standard Quotient --> Standard Quotient
% Given a list of standard quotients, converts them to polynmomials,
% computes the Groebner basis of the corresponding ideal,
% and returns the basis elements as a list of standard quotients.
asserted procedure f5_groebnerq(inputBasisSq: List): List;
   begin scalar basis;
      basis := f5_groebnerpoly(for each f in inputBasisSq collect 
                                 poly_sq2poly f);
      return (for each f in basis collect poly_poly2sq f)
   end;

% Polynomial --> Polynomial
% Computes a Groebner basis of the ideal generated 
% by the given polynomials.
asserted procedure f5_groebnerpoly(inputBasis: List): List;
   begin scalar inputModule, outputModule, properIdeal, w, p;
      w := inputBasis; inputBasis := nil;
      properIdeal := t; while properIdeal and w do <<
         p := pop w;
         % get rid of zeros in input 
         if not poly_iszero!?(p) then <<
            push(p, inputBasis); 
            % if constant present in the input,
            % the ideal is improper
            if poly_isConst!?(p) then
               properIdeal := nil
         >>
      >>;
      if not properIdeal then
         return {poly_one()};
      if null inputBasis then
         % This is a bit unclear mathematically, 
         % but we go with the design decisions of the GROEBNER package
         return {poly_zero()};
      if !*f5parametric then <<
         param_clearAssumptions()
      >>;
      inputModule := core_constructModule(inputBasis);
      % disallow parameters in coefficients when f5modular is ON 
      % if !*f5modular then
      %    % if params in coefficients
      %    for each p in inputModule do 
      %       for each cf in poly_getCoeffs(lp_eval(p)) do
      %          if kernels cf then
      %             rederr {"Parameters in coefficients with f5modular ON are not supported, sorry:", kernels cf};
      outputModule := core_groebner1(inputModule);
      return (for each p in outputModule collect lp_eval p)
   end;

% f5 argument error
asserted procedure f5_argumentError();
   rederr "usage: f5(polynomials: List, vars: List, order: Any). For example,

          > f5({x*y + 1, y*z + 1}, {x, y, z}, lex);

          Or, using torder:

          > torder({x, y, z}, lex);
          > f5({x*y + 1, y*z + 1});
          ";

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

endmodule;  % end of module f5

end;  % of file
