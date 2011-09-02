module dipoly;   % Header module for dipoly package.

%/*Authors: R. Gebauer, A. C. Hearn, H. Kredel*/
%
% Significant modifications: H. Melenk.
%
%% Modifications:
%
% 14-Dec-1994 (HM):  Term order GRADED added.
%
% 17-Sep-1994 (HM):  The ideal variables are now declared in the TORDER
%                    statement.  The calling conventions can be still
%                    used, but are removed from the documents.
%
% 12-Sep-1994 (HM):  Make the base coefficient arithmatic call subs2 if
%                    the switch *bcsub2 is on.  This is turned on if
%                    there are roots in the coefficient domain.  Without
%                    subs2 the zero detection would be incomplete in
%                    such cases.
%                    Term order MATRIX added.
%
%  5-Jun-1994 (HM):  Introduced zero divisor list for the base
%                    coefficients.  These are polynomial variants of let
%                    rules which Groebner has found for the parameters.

% For the time being, this contains the smacros that used to be in
% consel, and repeats those in bcoeff.

%----------------------------------------------------------------

% For compatibility with REDUCE 3.5:

macro procedure dipoly!-compat(u);
if version!*="REDUCE 3.5" then
<<fluid '(!*arbvars !*varopt);
 {'progn,'(setq !*arbvars t), '(setq !*varopt t),
  if 'psl memq lispsystem!* then
  << newtok'((!# !=) eq);
     put('iequal,'quotenewnam,'eq);
     nil
  >>
  else
  << newtok'((!# !=) eqn);
     put('eqn,'op,get('eq,'op));
     put('eqn,'infix,get('eq,'infix));
     put('iequal,'quotenewnam,'eqn);
     nil
  >>
 }
>>;

dipoly!-compat();

%----------------------------------------------------------------

%/*Constructors and selectors for a distributed polynomial form*/

%/*A distributive polynomial has the following informal syntax:
%
%   <dipoly> ::= dipzero
%                | <exponent vector> . <base coefficient> . <dipoly>*/

% Vdp2dip modules included.  They could be in a separate package.

create!-package('(dipoly a2dip bcoeff dip2a dipoly1 dipvars
		  expvec torder vdp2dip vdpcom condense dipprint),
		'(contrib dipoly));

put('dipoly,'version,4.0);

%define dipzero = 'nil;

fluid '(dipzero);
     %/*Until we understand how to define something to nil*/


smacro procedure dipzero!? u; null u;

smacro procedure diplbc p;
%  /* Distributive polynomial leading base coefficient.
%    p is a distributive polynomial. diplbc(p)  returns
%    the leading base coefficient of p. */
   cadr p;

smacro procedure dipmoncomp (a,e,p);
%  /* Distributive polynomial monomial composition. a is a base
%    coefficient, e is an exponent vector and p is a
%    distributive polynomial. dipmoncomp(a,e,p) returns a dis-
%    tributive polynomial with p as monomial reductum, e as
%    exponent vector of the leading monomial and a as leading
%    base coefficient. */
   e . a . p;

smacro procedure dipevlmon p;
%  /* Distributive polynomial exponent vector leading monomial.
%    p is a distributive polynomial. dipevlmon(p) returns the
%    exponent vector of the leading monomial of p. */
   car p;

smacro procedure dipfmon (a,e);
%  /* Distributive polynomial from monomial. a is a base coefficient
%    and e is an exponent vector. dipfmon(a,e) returns a
%    distributive polynomial with e as exponent vector and
%    a as base coefficient. */
   e . a . dipzero;

smacro procedure dipnov p;
%  /* Distributive polynomial number of variables. p is a distributive
%    polynomial. dipnov(p) returns a digit, the number of variables
%    of the distributive polynomial p. */
   length car p;

smacro procedure dipmred p;
%  /* Distributive polynomial reductum. p is a distributive polynomial
%    dipmred(p) returns the reductum of the distributive polynomial p,
%    a distributive polynomial. */
   cddr p;

endmodule;

end;
