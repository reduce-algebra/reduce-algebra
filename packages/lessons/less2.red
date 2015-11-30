COMMENT

                 REDUCE INTERACTIVE LESSON NUMBER 2

                         David R. Stoutemyer
                        University of Hawaii


COMMENT This is lesson 2 of 7 REDUCE lessons.  Please refrain from
using variables beginning with the letters F through H during the
lesson.

By now you have probably had the experience of generating an
expression, and then having to repeat the calculation because you
forgot to assign it to a variable or because you did not expect to
want to use it later.  REDUCE maintains a history of all inputs and
computation during an interactive session. (Note, this is only for
interactive sessions.) To use an input expression in a new
computation, you can say

        INPUT(n)

where n is the appropriate command number.  The evaluated computations
can be accessed through

        WS(n)    or simply WS

if you wish to refer to the last computation.  WS stands for Work Space.
As with all REDUCE expressions, these can also be used to create new
expressions:

        (INPUT(n)/WS(n2))**2

Special characters can be used to make unique REDUCE variable names
that reduce the chance of accidental interference with any other
variables.  In general, whenever you want to include an otherwise
forbidden character such as * in a name, merely precede it by an
exclamation point, which is called the escape character.  However,
pick a character other than "*", which is used for many internal
REDUCE names.  Otherwise, if most of us use "*" the purpose will be
defeated;

g+!%h;
ws;
pause;

COMMENT You can also name the expression in the workspace by using
the command SAVEAS, for example:;

saveas gplush;
gplush;
pause;

COMMENT You may have noticed that REDUCE imposes its own order on the
indeterminates and functional forms that appear in results, and that
this ordering can strongly affect the intelligibility of the results.
For example:;

g1:= 2*h*g + e + f1 + f + f**2 + f2 + 5 + log(f1) + sin(f1);

COMMENT The ORDER declaration permits us to order indeterminates and
functional forms as we choose. For example, to order F2 before F1,
and to order F1 before all remaining variables:;

order f2, f1;
g1;
pause;

COMMENT Now suppose we partially change our mind and decide to
order LOG(F1) ahead of F1;

order log(f1), f1;
g1;

COMMENT Note that any other indeterminates or functional forms under
the influence of a previous ORDER declaration, such as F2, rank
before those mentioned in the later declaration.  Try to determine
the default ordering algorithm used in your REDUCE implementation, and
try  to achieve some delicate  rearrangements using the ORDER
declaration.;

pause;

COMMENT You may have also noticed that REDUCE factors out any
number, indeterminate, functional form, or the largest integer power
thereof which exactly divides every term of a result or every term of
a parenthesized subexpression of a result. For example:;

on exp, mcd;
g1:= f**2*(g**2 + 2*g) + f*(g**2+h)/(2*f1);

COMMENT This process usually leads to more compact expressions and
reveals important structural information. However, the process can
yield results which are difficult to interpret if the resulting
parentheses are nested more than about two levels, and it is often
desirable to see a fully expanded result to facilitate direct
comparison of all terms. To suppress this monomial factoring, we can
turn off an output control switch named ALLFAC;

off allfac;
g1;
pause;

COMMENT The ALLFAC monomial-factorization process is strongly
dependent upon the ordering.  We can achieve a more selective monomial
factorization by using the FACTOR declaration, which declares a
variable to have FACTOR status.  If any indeterminates or functional
forms occurring in an expression are in FACTOR status when the
expression is printed, terms having the same powers of the
indeterminates or functional forms are collected together, and the
power is factored out.  Terms containing two or more indeterminates or
functional forms under FACTOR status are not included in this monomial
factorization process.  For example:;

off allfac; factor f; g1;
factor g; g1; pause;

COMMENT We can use the REMFAC command to remove items from factor
status;

remfac f;
g1;

COMMENT ALLFAC can still have an effect on the coefficients of the
monomials that have been factored out under the influence of FACTOR:;

on allfac;
g1;
pause;

COMMENT It is often desirable to distribute denominators over all
factored subexpressions generated under the influence of a FACTOR
declaration, such as when we wish to view a result as a polynomial or
as a power series in the factored indeterminates or functional forms,
with  coefficients which are rational  functions of any other
indeterminates or functional forms.  (A mnemonic aid is: think RAT
for RATional-function coefficients.) For example:;

on rat;
g1;
pause;

COMMENT RAT has no effect on expressions which have no
indeterminates or functional forms under the influence of FACTOR.
The related but different DIV switch permits us to distribute numerical
and monomial factors of the denominator over every term of the
numerator, expressing these distributed portions as rational-number
coefficients and negative power factors respectively. (A mnemonic
aid: DIV DIVides by monomials.) The overall effect can also depend
strongly on whether the RAT switch is on or off.  Series and
polynomials are often most attractive with RAT and DIV both on;

on div, rat;
g1;
off rat;
g1;
pause;

remfac g;
g1;
pause;

COMMENT With a very complicated result, detailed study of the result
is often facilitated by having each new term begin on a new line,
which can be accomplished using the LIST switch:;

on list;
g1;
pause;

COMMENT  In various combinations, ORDER, FACTOR, the computational
switches EXP, MCD, GCD, and ROUNDED, together with the output control
switches ALLFAC, RAT, DIV, and LIST provide a variety of output
alternatives. With experience, it is usually possible to use these
tools to produce a result in the desired form, or at least in a form
which is far more acceptable than the one produced by the default
settings.  I encourage you to experiment with various combinations
while this information is fresh in your mind;

pause;
off list, rat, div, gcd, rounded;
on allfac, mcd, exp;

COMMENT You may have wondered whether or not an assignment to a
variable, say F1, automatically updates the value of a bound
variable, say G1, which was previously assigned an expression
containing F1. The answer is:

   1.  If F1 was a bound variable in the expression when it was set
       to G1, then subsequent changes to the value of F1 have no
       effect on G1 because all traces of F1 in G1 disappeared after
       F1 contributed its value to the formation of G1.
   2.  If F1 was an indeterminate in an expression previously
       assigned to G1, then for each subsequent use of G1, F1
       contributes its current value at the time of that use.

These phenomena are illustrated by the following sequence:;

pause;
f2 := f;
g1 := f1 + f2;
f2 := g;
g1;
f1 := g;
f1 := h;
g1;
f1 := g;
g1;

COMMENT  Experience indicates that it is well worth studying this
sequence and experimenting with others until these phenomena are
thoroughly understood. You might, for example, mimic the above
example, but with another level of evaluation included by inserting a
statement analogous to "Q9:=G1" after "F2:=G", and inserting an
expression analogous to "Q9" at the end, to compare with G1. ;

pause;
COMMENT Note also, that if an indeterminate is used directly, or
indirectly through another expression, in evaluating itself, this will
lead to an infinite recursion.  For example, the following expression
results in infinite recursion at the first evaluation of H1.  On some
machines (Vax/Unix, IBM) this will cause REDUCE to terminate abnormally.

        H1 := H1 + 1

You may experiment with this problem, later at your own risk.

It is often desirable to make an assignment to an indeterminate in a
previously established expression have a permanent effect, as if the
assignment were done before forming the expression.  This can be done by
using the substitute function, SUB.

G1 := F1 + F2;

h1 := sub(f1=h, g1);
f1 := g;
h1;

COMMENT Note the use of "=" rather than ":=" in SUB. This function
is also valuable for achieving the effect of a local assignment
within a subexpression, without binding the involved indeterminate or
functional form in the rest of the expression or wherever else it
occurs. More generally the SUB function can have any number of
equations of  the form  "indeterminate or  functional form  =
expression", separated by commas, before the expression which is its
last argument. Try devising a set of examples which reveals whether
such multiple substitutions are done left to right, right to left, in
parallel, or unpredictably.

This is the end of lesson 2. To execute lesson 3, start a fresh
REDUCE job.

;end;
