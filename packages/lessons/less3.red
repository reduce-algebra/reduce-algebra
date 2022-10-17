COMMENT

                  REDUCE INTERACTIVE LESSON NUMBER 3

                         David R. Stoutemyer
                         University of Hawaii

                        Update for REDUCE 3.4
                            Herbert Melenk
                      Konrad-Zuse-Zentrum Berlin

;% $Id$

COMMENT This is lesson 3 of 7 REDUCE lessons.  Please refrain from
using variables beginning with the letters F through H during the
lesson.

Mathematics is replete with many named elementary and not-so-
elementary functions besides the set built into REDUCE such as SIN,
COS, and LOG, and it is often convenient to utilize expressions
containing a functional form such as F(X) to denote an unknown
function or a class of functions.  Functions are called operators in
REDUCE, and by merely declaring their names as such, we are free to
use them for functional forms.  For example:;

operator f;
g1 := f(f(cot(f)), f());

COMMENT Note that

   1.  We can use the same name for both a variable and an operator.
       (However, this practice often leads to confusion.)
   2.  We can use the same operator for any number of arguments --
       including zero arguments such as for F().
   3.  We can assign values to specific instances of functional
       forms.;

pause;

COMMENT COT is one of the functions already defined in REDUCE together
with a few of its properties.  However, you can augment or even
override these definitions depending on the needs of a given problem.
For example, if you wished to write COT(F) in terms of TAN, you could
say:;

cot(f) := 1/tan(f);
g1 := g1 + cot(h+1);

pause;

COMMENT Naturally, our assignment for COT(F) did not affect COT(H+1)
in our example above.  However, we can use a LET rule to make all
cotangents automatically be replaced by the reciprocal of the
corresponding tangents:;

let cot(~f) => 1/tan(f);
g1;

COMMENT Any variable preceded by a tilde is a dummy variable which is
distinct from any other previously or subsequently introduced
indeterminate, variable, or dummy variable having the same name
outside the rule.  The leftmost occurrence of a dummy variable in a
rule must be marked with a tilde.

The arguments to LET are either single rules or lists (explicitly
enclosed in {..} or as variables with list values).  All elements of a
list have to be rules (i.e., expressions written in terms of the
operator "=>") or names of other rule lists.  So we could have written
the above command either as

      LET COT(~F) => 1/TAN(F)

or as the command sequence

      RS := {COT(~F) => 1/TAN(F)}
      LET RS

The CLEARRULES command clears one or more rules.  They have to be
entered in the same form as for LET -- otherwise REDUCE is unable to
identify them.;

clearrules cot(~f) => 1/tan(f);
cot(g+5);

COMMENT Alternative forms would have been

     CLEARRULES {COT(~F) => 1/TAN(F)}

   or with the above value of RS

     CLEARRULES RS

Note that CLEAR RS would not remove the rule(s) from the system -- it
would only remove the list value from the variable RS.;

pause;

COMMENT The arguments of a functional form on the left-hand side of a
rule can be more complicated than mere indeterminates.  For example,
we may wish to inform REDUCE how to differentiate expressions
involving a symbolic function P, whose derivative is expressed in
terms of another function Q.;

operator p, q;
let df(p(~x), x) => q(x)^2;

df(3*p(f*g), g);

COMMENT Also, REDUCE obviously knows the chain rule.;

pause;

COMMENT As another example, suppose that we wish to employ the
angle-sum identities for SIN and COS:;

let {sin(~x+~y) => sin(x)*cos(y) + sin(y)*cos(x),
     cos(~x+~y) => cos(x)*cos(y) - sin(x)*sin(y)};
cos(5 + f - g);

COMMENT Note that:

   1.  LET can have any number of replacement rules written as a list.
   2.  There was no need for rules with 3 or more addends, because the
       above rules were automatically employed recursively, with two
       of the three addends 5, F, and -G grouped together as one of
       the dummy variables the first time through.
   3.  Despite the sub-expression F-G in our example, there was no
       need to make rules for the difference of two angles, because
       sub-expressions of the form X-Y are treated as X+(-Y).
   4.  Built-in rules were employed to convert expressions of the form
       SIN(-X) or COS(-X) to -SIN(X) or COS(X) respectively.

As an exercise, try to implement rules which transform the logarithms
of products and quotients respectively to sums and differences of
logarithms, while converting the logarithm of a power of a quantity to
the power times the logarithm of the quantity.;

pause;

COMMENT Actually, the left-hand side of a rule also can be somewhat
more general than a functional form.  The left-hand side can be a
power of an indeterminate or of a functional form, or a product of
such powers and/or indeterminates or functional forms.  For example,
we can have the rule

       SIN(~X)^2 => 1 - COS(~X)^2

or we can have the rule:;

let cos(~x)^2 => 1 - sin(~x)^2;
g1 := cos(f)^3 + cos(g);
pause;

COMMENT Note that a replacement takes place wherever the left-hand
side of a rule divides a term.  With a rule replacing SIN(X)^2 and a
rule replacing COS(X)^2 simultaneously in effect, an expression which
uses either one will lead to an infinite recursion that eventually
exhausts the available storage.  (Try it if you wish -- after the
lesson).  We are also permitted to employ a more symmetric rule using
a top level "+" provided that no free variables appear in the rule.
However, a rule such as "SIN(~X)^2 + COS(X)^2 => 1" is not permitted.
We can get around the restriction against a top-level "+" on the
left-hand side though, at the minor nuisance of having to employ an
operator whenever we want the rule applied to an expression:;

clearrules cos(~x)^2 => 1 - sin(~x)^2;
operator mytrigsimp;
mytrigsimp_rules := {
   mytrigsimp(~a*sin(~x)^2 + a*cos(x)^2 + ~c) => a + mytrigsimp(c),
   mytrigsimp(~a*sin(~x)^2 + a*cos(x)^2) => a,
   mytrigsimp(sin(~x)^2 + cos(x)^2 + ~c) => 1 + mytrigsimp(c),
   mytrigsimp(sin(~x)^2 + cos(x)^2) => 1,
   mytrigsimp(~x) => x }$
g1 := f*cos(g)^2 + f*sin(g)^2 + g*sin(g)^2 + g*cos(g)^2 + 5;
g1 := mytrigsimp(g1) where mytrigsimp_rules;
pause;

COMMENT Here we use another syntactical paradigm: the rule list is
assigned to a name (here MYTRIGSIMP_RULES) and it is activated only
locally for one evaluation, using the WHERE clause.

Why doesn't our rule MYTRIGSIMP(~X) => X defeat the other more
specific ones?  The reason is that rules inside a list are applied in
the order they are written, with the whole process immediately
restarted whenever any rule succeeds.  Thus the rule MYTRIGSIMP(X) =
X, intended to make the operator MYTRIGSIMP eventually evaporate, is
tried only after all of the genuine simplification rules have done all
they can.  For such reasons we usually write rules for an operator in
an order which proceeds from the most specific to the most general
cases.  Experimentation will reveal that MYTRIGSIMP will not simplify
higher powers of sine and cosine, such as COS(X)^4 +
2*COS(X)^2*SIN(X)^2 + SIN(X)^4, and that MYTRIGSIMP will not
necessarily work when there are more than 6 terms.  This latter
restriction is not fundamental but is a practical one imposed to keep
the combinatorial searching associated with the current algorithm
under reasonable control.  As an exercise, see if you can generalize
the rules sufficiently so that 5*COS(H)^2 + 6*SIN(H)^2 simplifies to 5
+ SIN(H)^2 or to 6 - COS(H)^2.

Note that REDUCE already provides an operator TRIGSIMP for simplifying
trigonometric or hyperbolic expressions -- see the REDUCE manual entry
for the user-contributed package "TRIGSIMP: Simplification and
factorization of trigonometric and hyperbolic functions".;

pause;

COMMENT Rules do not need to have free variables.  For example, we
could introduce the simplification rule to replace all subsequent
instances of M*C^2 by ENERGY:;

clear m, c, energy;
g1 := (3*m^2*c^2 + m*c^3 + c^2 + m + m*c + m1*c1^2)
        where m*c^2 => energy;
pause;

COMMENT Suppose that instead we wish to replace M by ENERGY/C^2:;

g1 where m => energy/c^2;

COMMENT You may wonder how a rule of the trivial form
"indeterminate => ..." differs from the corresponding assignment
"indeterminate := ...".  The difference is this:

   1.  The LET rule does not replace any contained bound
       variables with their values until the rule is actually used for
       a replacement.
   2.  The LET rule performs the evaluation of any contained bound
       variables every time the rule is used.

Thus, the rule "X => X + 1" would cause infinite recursion at the
first subsequent occurrence of X, as would the pair of rules "{X => Y,
Y => X}".  (Try it! -- After the lesson.)  To illustrate point 1
above, compare the following command sequence with the analogous
earlier one in lesson 2, which used assignments throughout:;

clear e1, f;
e2 := f;
let f1 => e1 + e2;
f1;
e2 := g;
f1;
pause;

COMMENT For a subsequent example, we need to replace E^(I*X) by
COS(X)^2 + I*SIN(X)^2 for all X.  See if you can successfully
introduce this rule.  (Without it, the following code will not work
correctly!);

pause;
e^i;

COMMENT REDUCE does not match I as an instance of the pattern I*X with
X = 1, so if you neglected to include a rule for this degenerate case,
do so now.;

pause;
clear x, n, nminusone;
zero := e^(n*i*x) - e^(nminusone*i*x)*e^(i*x);
realzero := sub(i=0, zero);
imagzero := sub(i=0, -i*zero);

COMMENT Regarding the last two assignments as equations, we can solve
them to get recurrence relations defining SIN(N*X) and COS(N*X) in
terms of angles having lower multiplicity.

Can you figure out why I didn't use N-1 rather than NMINUSONE above?

Can you devise a similar technique to derive the angle-sum identities
that we previously implemented?;

pause;

COMMENT To implement a set of trigonometric multiple-angle expansion
rules, we need to match the patterns SIN(N*X) and COS(N*X) only when N
is an integer exceeding 1.  We can implement one of the necessary
rules as follows:;

cos(~n*~x) => cos(x)*cos((n-1)*x) - sin(x)*sin((n-1)*x)
        when fixp n and n>1;

COMMENT Note:

   1.  In a conditional rule, any dummy variables should appear in the
       left-hand side of the replacement with a tilde.
   2.  FIXP, standing for FIX Predicate, is a built-in function which
       yields true if and only if its argument is an integer.  Other
       useful predicates are NUMBERP, which is true if its argument
       represents a numeric value, that is an integer, a rational
       number or a rounded (floating point) number, and EVENP, which
       is true if its argument is an integer multiple of 2.
   3.  Arbitrarily-complicated true-false conditions can be composed
       using the relational operators =, NEQ, <, >, <=, >=, together
       with the logical operators "AND", "OR", "NOT".
   4.  The operators < , >, <=, and >= work only when both sides are
       numbers.
   5.  The relational operators have higher precedence than "NOT",
       which has higher precedence than "AND", which has higher
       precedence than "OR".
   6.  In a sequence of expressions joined by "AND" operators, testing
       is done left to right, and testing is discontinued after the
       first item which is false.
   7.  In a sequence of expressions joined by "OR" operators, testing
       is done left to right, and testing is discontinued after the
       first item which is true.
   8.  We didn't actually need the "AND N>1" part in the above rule.
       Can you guess why?

Your mission is to complete the set of multiple-angle rules and to
test them on the example COS(4*X) + COS(X/3) + COS(F*X).;

pause;

COMMENT Now suppose that we wish to write a set of rules for doing
symbolic integration, such that expressions of the form
INTEGRATE(X^P, X) are replaced by X^(P+1)/(P+1) for arbitrary X and P,
provided P is independent of X.  This will of course be less complete
that the analytic integration package available with REDUCE, but for
specific classes of integrals it is often a reasonable way to do such
integration.  Noting that DF(P,X) is 0 if P is independent of X, we
can accomplish this as follows:;

operator integrate;
let integrate(~x^~p, x) => x^(p+1)/(p+1) when df(p, x) = 0;
integrate(f^5, f);
integrate(g^g, g);
integrate(f^g, f);
pause;

g1 := integrate(g*f^5, f) + integrate(f^5+f^g, f);

COMMENT The last example indicates that we must incorporate rules
which distribute integrals over sums and extract factors which are
independent of the second argument of INTEGRATE.  Can you think of
rules which accomplish this?  It is a good exercise, but this
particular pair of properties of INTEGRATE is so prevalent in
mathematics that operators with these properties are called linear,
and a corresponding declaration is built into REDUCE:;

linear integrate;
g1;
g1 := integrate(f+1, f) + integrate(1/f^5, f);
pause;

COMMENT We overcame one difficulty and uncovered 3 others.  Clearly
REDUCE does not consider F to match the pattern F^P as F^1, or 1 to
match the pattern as F^0, or 1/F^5 to match the pattern as F^(-1), but
we can add additional rules for such cases:;

let {
   integrate(1/~x^~p, x) => x^(1-p)/(1-p) when df(p, x) = 0,
   integrate(~x, x) => x^2/2,
   integrate(1, ~x) => x }$
g1;

COMMENT A remaining problem is that INTEGRATE(X^-1, X) will lead to
X^0/(-1+1), which simplifies to 1/0, which will cause a zero-divide
error message.  Consequently, we should also include the correct rule
for this special case:;

let integrate(~x^-1, x) => log(x);
integrate(1/x, x);
pause;

COMMENT We now collect the integration rules so far into one list
according to the law that within a rule set a more specific rule
should precede the more general one:;

integrate_rules := {
  integrate(1, ~x) => x,
  integrate(~x, x) => x^2/2,
  integrate(~x^-1, x) => log(x),
  integrate(1/~x^~p, x) => x^(1-p)/(1-p) when df(p, x) = 0,
  integrate(~x^~p, x) => x^(p+1)/(p+1) when df(p, x) = 0 }$

COMMENT Note that there are more elegant ways to match special cases
in which variables have the values 0 or 1 by using "double tilde
variables" -- see "Advanced use of rule lists" in section 11.3 of the
REDUCE User's Manual.

This is the end of lesson 3.  We leave it as an intriguing exercise to
extend this integrator.

;end;
