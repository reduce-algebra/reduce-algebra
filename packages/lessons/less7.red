COMMENT

                  REDUCE INTERACTIVE LESSON NUMBER 7

                         David R. Stoutemyer
                         University of Hawaii

;% $Id$

COMMENT This is lesson 7 of 7 REDUCE lessons.  Sometimes it is desired
to have a certain facility available to algebraic mode, no such
facility is described in the REDUCE User's Manual, and there is no
easy way to implement the facility directly in algebraic mode.  The
possibilities are:

   1.  The facility exists for algebraic mode, but is undocumented.
   2.  The facility exists, but is available only in symbolic mode.
   3.  The facility is not built-in for either mode.

Perusal of the REDUCE source code (see
https://sourceforge.net/p/reduce-algebra/code/HEAD/tree/trunk/packages/
-- alg contains the core algebra facilities), together with
experimentation can reveal which of these alternatives is true.  (Even
in case 3, an inquiry via the REDUCE Project Forum or Mailing List --
see https://sourceforge.net/projects/reduce-algebra/support -- may
reveal that someone else has already implemented the supplementary
facility and can provide the code.);

pause;

COMMENT A type of statement is available to both modes if its leading
keyword appears in either of the equivalent statements

      PUT (..., 'STAT, ...)
or
      DEFLIST('(...), 'STAT).

A symbolic-mode global variable is available to algebraic mode and
vice-versa if the name of the variable appears in either of the
equivalent statements

      SHARE ...,
or
      FLAG('(...), 'SHARE).

A function defined in symbolic mode is directly available to algebraic
mode if the function name appears in one of the statements

      SYMBOLIC OPERATOR ...,
      PUT(..., 'SIMPFN, ...),
      DEFLIST('(...), 'SIMPFN),
      FLAG('(...), 'OPFN).

In addition, if you want a function to be used as a predicate in IF or
WHILE statements, it should be flagged BOOLEAN, as in

      FLAG('(...), 'BOOLEAN);

pause;

COMMENT Other functions which are used but not defined in RLISP are
the built-in LISP functions.  See a description of the underlying LISP
system (normally either PSL or CSL) for documentation on these
functions.  All Standard Lisp functions should be available.

Particularly notable built-in features available only to symbolic mode
include

   1.  A function named SPACES, which outputs the number of blanks
       indicated by its integer argument.
   2.  A function named REDERR, which provokes an error interrupt
       after outputting its arguments.
   3.  A predicate named KERNP, which returns NIL if its argument
       is not an indeterminate or a functional form.
   4.  A function named MATHPRINT, which outputs its argument in
       natural mathematical notation, beginning on a new line.
   5.  A function named MAPRIN, which is like MATHPRINT, but does not
       automatically start or end a new line.
   6.  A function named TERPRI!*, which ends the current output-line.

Thus, for example, all that we have to do to make the predicate KERNP
and the function SPACES available to algebraic mode is to type

      FLAG('(KERNP), 'BOOLEAN),
      SYMBOLIC OPERATOR SPACES.

When such simple remedies are unavailable, we can introduce our own
statements or write our own SYMBOLIC-mode variables and procedures,
then use these techniques to make them available to algebraic mode.
In order to do so, it is usually necessary to understand how REDUCE
represents and simplifies algebraic expressions.;

pause;

COMMENT One of the REDUCE representations is called Cambridge Prefix.
An expression is either an atom or a list consisting of a literal
atom, denoting a function or operator name, followed by arguments
which are Cambridge Prefix expressions.  The most common unary
operator names are MINUS, LOG, SIN, and COS.  The most common binary
operator names are DIFFERENCE, QUOTIENT, and EXPT.  The most common
nary operator names are PLUS and TIMES.  Thus, for example, the
expression

      3*x^2*y + x^(1/2) + e^(-x)

could be represented as

'(PLUS (TIMES 3 (EXPT X 2) Y) (EXPT X (QUOTIENT 1 2)) (EXPT E (MINUS X))

The parser produces an unsimplified Cambridge Prefix version of
algebraic-mode expressions typed by the user, then the simplifier
returns a simplified prefix version.  When a symbolic procedure that
has been declared a symbolic operator is invoked from algebraic mode,
the procedure is given simplified Cambridge Prefix versions of the
arguments.  To illustrate these ideas, here is an infix function named
ISFREEOF, which determines whether its left argument is free of the
indeterminate, function name, or literal sub-expression which is the
right argument.  ISFREEOF is similar to the REDUCE FREEOF function but
less general.;

pause;

flag('(isfreeof), 'boolean);
infix isfreeof;
symbolic procedure campre1 isfreeof campre2;
   if campre1=campre2 then nil
   else if atom campre1 then t
   else (car campre1 isfreeof campre2)
      and (cdr campre1 isfreeof campre2);

algebraic if log(5+x+cos(y)) isfreeof sin(z-7)
   then write "WORKS ONE WAY";
algebraic if not(log(5+x+cos(y)) isfreeof cos(y))
   then write "WORKS OTHER WAY TOO";

COMMENT Conceivably we might wish to distinguish when CAMPRE2 is a
literal atom occurring as a function name from the case when CAMPRE2
is a literal atom and occurs as an indeterminate.  Accordingly, see if
you can write two such more specialized infix predicates named
ISFREEOFINDET and ISFREEOFFUNCTION.;

pause;

COMMENT When writing a symbolic-mode function, it is often desired to
invoke the algebraic simplifier from within the function.  This can be
done by using the function named REVAL, which returns a simplified
Cambridge Prefix version of its prefix argument.

Usually, REDUCE uses and produces a different representation, which I
call REDUCE prefix.  The symbolic function AEVAL returns a simplified
REDUCE-prefix version of its prefix argument.  Both REVAL and AEVAL
can take either type of prefix argument.

A REDUCE-prefix expression is an integer, a floating-point number, an
indeterminate, or an expression of the form

      ('!*SQ standardquotient . !*SQVAR!*).

!*SQVAR!* is a global variable which is set to T when the REDUCE-
prefix expression is originally formed.  The value of !*SQVAR!* is
reset to NIL if subsequent LET, MATCH, or computational ON statements
could change the environment is such a way that the expression might
require resimplification next time it is used.;

pause;

COMMENT Standard quotients are neither Cambridge nor REDUCE prefix, so
the purpose of the atom '!*SQ is to make the value of all algebraic-
mode variables always be some type of prefix form at the top level.

A standard quotient is a unit-normal dotted pair of 2 standard forms,
and a standard form is the REDUCE representation for a polynomial.
Unit-normal means that the leading coefficient of the denominator is
positive.

REDUCE has a built-in symbolic function SIMP!*, which returns the
simplified standard quotient representation of its argument, which can
be either Cambridge or REDUCE prefix.  REDUCE also has symbolic
functions named NEGSQ, INVSQ, ADDSQ, MULTSQ, DIVSQ, DIFFSQ, and
CANONSQ which respectively negate, reciprocate, add, multiply, divide,
differentiate, and unit-normalize standard quotients.  There is also a
function named ABSQ, which negates a standard quotient if the leading
coefficient of its numerator is negative, and there is a function
named EXPTSQ which raises a standard quotient to an integer power.
Finally, there is a function named MK!*SQ, which returns a REDUCE
prefix version of its standard-quotient argument, and there is also a
function named PREPSQ which returns a Cambridge prefix version of its
standard-quotient argument.

If there is a sequence of operations, rather than converting from
prefix to standard quotient and back at each step, it is usually more
efficient to do the operations on standard quotients, then use MK!*SQ
to make the final result be REDUCE prefix.  Also it is often more
efficient to work with polynomials rather than rational functions
during the intermediate steps.;

pause;

COMMENT The coefficient domain of polynomials is floating-point
numbers, integers, integers modulo an arbitrary integer modulus, or
rational numbers.  However, zero is represented as NIL.

The polynomial variables are called kernels, which can be
indeterminates or uniquely-stored fully simplified Cambridge-prefix
functional forms.  The latter alternative permits the representation
of expressions which could not otherwise be represented as the ratio
of two expanded polynomials, such as

   1.  sub-expressions of the form LOG(...) or SIN(...),
   2.  sub-expressions of the form indeterminate^noninteger,
   3.  unexpanded polynomials, each polynomial factor being
       represented as a functional form,
   4.  rational expressions not placed over a common denominator,
       each quotient sub-expression being represented as a functional
       form.

A polynomial is represented as a list of its nonzero terms in
decreasing order of the degree of the leading "variable".  Each term
is represented as a standard power dotted with its coefficient, which
is a standard form in the remaining variables.  A standard power is
represented as a variable dotted with a positive integer degree.;

pause;

COMMENT Letting ::= denote "is defined as" and letting | denote "or",
we can summarize the REDUCE data representations as follows:

   reduceprefix ::= ('!*SQ standardquotient . !*SQVAR!*)
   standardquotient ::= NUMR(standardquotient) ./
                               DENR(standardquotient)
   NUMR(standardquotient) ::= standardform
   DENR(standardquotient) ::= unitnormalstandardform
   domainelement ::= NIL | nonzerointeger | nonzerofloat |
                     nonzerointeger . positiveinteger
   standardform ::= domainelement |
                    LT(standardform) .+ RED(standardform)
   RED(standardform) ::= standardform
   LT(standardform) := LPOW(standardform) .* LC(standardform)
   LPOW(standardform) := MVAR(standardform) .^ LDEG(standardform)
   LC(standardform) ::= standardform
   MVAR(standardform) ::= kernel
   kernel ::= indeterminate | functionalform
   functionalform ::= (functionname Cambridgeprefix1 Cambridgeprefix2
                       ...)
   Cambridgeprefix ::= integer | float | indeterminate |
                          functionalform
   LC(unitnormalstandardform) ::= positivedomainelement |
                                 unitnormalstandardform

I have taken this opportunity to also introduce the major REDUCE
selector macros named NUMR, DENR, LT, RED, LPOW, LC, MVAR, and LDEG,
together with the major constructor macros named ./, .+, .*, and .^ .
The latter are just mnemonic aliases for ".".  A comparison of my
verbal and more formal definitions also reveals that the selectors are
respectively just aliases for CAR, CDR, CAR, CDR, CAAR, CDAR, CAAAR,
and CDAAR.  Since these selectors and constructors are macros rather
than functions, they afford a more readable and modifiable programming
style at no cost in ultimate efficiency.  Thus you are encouraged to
use them and to invent your own when convenient.  As an example of how
this can be done, here is the macro definition for extracting the main
variable of a standard term:;

%   symbolic smacro procedure tvar trm; caar trm;

pause;

COMMENT It turns out that there are already built-in selectors named
TC, TPOW, and TDEG, which respectively extract the coefficient,
leading power, and leading degree of a standard term.  There are also
built-in constructors named !*P2F, !*K2F, !*K2Q, and !*T2Q, which
respectively make a power into a standard form, a kernel into a
standard form, a kernel into a standard quotient, and a term into a
standard quotient.  See the REDUCE User's Manual for a complete list.

The unary functions NEGF and ABSF respectively negate, and unit-
normalize their standard-form arguments.  The binary functions ADDF,
MULTF, QUOTF, SUBF, EXPTF, and GCDF respectively add, multiply, divide,
substitute into, raise to a positive integer power, and determine the
greatest common divisor of standard forms.  See if you can use them to
define a macro which subtracts standard forms.;

pause;

COMMENT The best way to become adept at working with standard forms
and standard quotients is to study the corresponding portions of the
REDUCE source listing.  The listing of ADDF and its subordinates is
particularly instructive.  As an exercise, see if you can write a
function named ISFREEOFKERN which determines whether or not its left
argument is free of the kernel which is the right argument, using
REDUCE prefix rather than Cambridge prefix for the left argument.;

pause;

COMMENT As a final example of the interaction between modes, here is a
function which produces simple character-based plots.  Note that, to
keep the implementation as simple as possible, values of the
indeterminate ("x") increase downwards and values of the expression
plotted ("y") increase to the right.  This is the conventional
orientation rotated clockwise through 90 degrees!;

share ncols;
ncols := 66;
symbolic operator plot;
symbolic procedure plot(ex, xinit, dx, ndx, yinit, dy);
   begin COMMENT This procedure produces a character-plot of univariate
      expression EX where,
         XINIT is the initial value of the indeterminate,
         DX is the increment per line of the indeterminate,
         NDX is the number of lines plotted,
         YINIT is the value represented at the left edge,
         DY is incremental value per column.
      The shared variable NCOLS, initially 66, is the number of columns
      used.  Points are plotted using "*", except "<" and ">" are used
      at the left and right edges to indicate out of bounds points.;

   scalar x, f, y;  integer col, ncolsminus1;
   ncolsminus1 := ncols - 1;
   write "Starting the plot of ",ex;
   x := listofvars ex;          % find indeterminates;
   if length x > 1 then rederr
     "ERROR: PLOT expression can have at most 1 indeterminate";
   if null x then <<
      write "ERROR: no indeterminates in ", ex;
      rederr "" >>
   else x := car x;
   write " in variable ", x;  terpri();
   COMMENT Convert args from algebraic to symbolic values;
   xinit := revalx xinit;
   dx := revalx dx;
   yinit := revalx yinit;
   dy := revalx dy;

   for j:= 0:ndx do <<

      % generate expression with current value substituted for x
      f := subst(xinit + j*dx, x, ex);
      y := eval(f);                      % eval expression
      col := rnd((y - yinit)/dy);        % scale and round for cols

      if col<0 then write "<"
      else if col > ncolsminus1 then << spaces(ncolsminus1);
         prin2 ">";
         terpri() >>
      else << spaces(col);
         prin2 "*";
         terpri() >>
      >> ;
   if null y then rederr
     "ERROR: UNABLE TO PERFORM FLOATING-POINT EVALUATION OF 1ST ARG"
   end;

pause;

symbolic procedure listofvars campre;
   if null campre or numberp campre then nil
   else if atom campre then list campre
   else varsinargs cdr campre;

symbolic procedure varsinargs listofcampre;
   if null listofcampre then nil
   else union(listofvars car listofcampre, varsinargs cdr listofcampre);

symbolic procedure rnd x;
   begin scalar ans;
   ans := revalx x;
   if not numberp x then redderr "RND GIVEN NON-NUMERIC ARGUMENT";
   if ans >=0 then ans := fix(ans+00.5)
   else ans:= fix(ans-0.5);
   return ans
   end;

symbolic procedure revalx u;
   % MAKE SURE WE GET TRUE FLOATS IN SYMBOLIC MODE.
   if eqcar(u,'!:rd!:) then rdprepx u else u;

symbolic procedure rdprepx u;
   if floatp cdr u then cdr u else bf2flr u;

pause;

on rounded;

plot(y^2,     0, 0.25, 10, 0, 0.25);
pause;

plot((a+1)^2, 0, 0.25, 10, 0, 0.25);
pause;

b := a*2;

plot(a*b,     0, 0.25, 10, 0, 0.25);
pause;

COMMENT We leave it as an exercise to write a more elaborate plot
procedure which offers amenities such as automatic scaling, numbered
ordinates, etc.

Good luck with these exercises, with REDUCE, with computer algebra and
with all of your endeavors.

;end;
