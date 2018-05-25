COMMENT

                  REDUCE INTERACTIVE LESSON NUMBER 5

                         David R. Stoutemyer
                         University of Hawaii


COMMENT This is lesson 5 of 7 REDUCE lessons.

There are at least two good reasons for wanting to save REDUCE
expression assignments to a file:

   1.  So that one can logout, then resume computation at a later
       time.
   2.  So that needed main memory space can be cleared without
       irrecoverably losing the values of variables which are not
       needed in the next expression but will be needed later.

Using trivial small expressions, the following statement sequence
illustrates how this could be done:

   OFF NAT,
   OUT TEMP,
   F1 := (F + G)^2,
   G1 := G*F1,
   OUT T,
   CLEAR F1,
   H1 := H*G1,
   OUT TEMP,
   CLEAR G1,
   H2 := F*H1,
   CLEAR H1,
   SHUT TEMP,
   IN TEMP,
   F1,
   ON NAT,
   F1.

ON NAT yields the natural output style with raised exponents, which is
unsuitable for subsequent input.

The OUT-statement causes subsequent output to be directed to the file
named in the statement, until overridden by a different OUT-statement
or until the file is closed by a SHUT-statement.  File T is the
terminal, and any other name designates a normal file.  Such names
must comply with the local file-naming conventions as well as with the
REDUCE syntax.  If the output is not of lasting importance, I find
that including something like "TEMPORARY" or "SCRATCH" in the name
helps remind me to delete it later.

Successive OUT-statements to the same file will append rather than
overwrite output if and only if there is no intervening SHUT-
statement for that file.  The SHUT-statement also has the effect of an
implied OUT T.

Note:

   1.  The generated output is the simplified expression rather than
       the raw form entered at the terminal.
   2.  Each output assignment automatically has a dollar-sign appended
       so that it is legal input and so that (perhaps lengthy) output
       will not unavoidably be generated at the terminal when the file
       is read in later.
   3.  Output cannot be sent simultaneously to 2 or more files.
   4.  Statements entered at the terminal which do not generate output
       -- such as declarations, LET rules, and procedure definitions
       -- do not appear in the output file.
   5.  One could get declarations, procedure definitions, rules, etc.
       written to a file from the terminal by typing statements such
       as

          WRITE "
          ALGEBRAIC PROCEDURE ...
             ... ".

       This could serve as a means of generating permanent copies of
       LET rules, procedures, etc., but it is quite awkward compared
       with the usual way, which is to generate a file containing the
       REDUCE program by using a text editor, then input the program
       by using the IN-statement.  If you have refrained from learning
       to use a basic text editor (such as Windows Notepad), hesitate
       no longer.  I suggest that your first text-editing exercise be
       to create an IN file for (re)defining the function
       FACTORIAL(n).
   6.  The reason I didn't actually execute the above statement
       sequence is that when the input to REDUCE comes from a file,
       both the input and output are sent to the output file (which is
       convenient for producing a file containing both the input and
       output of a demonstration.)  Consequently, you would have seen
       none of the statements between the "OUT TEMP" and "OUT T" as
       well as between the second "OUT TEMP" and the "SHUT TEMP",
       until the IN-statement was executed.  The example is confusing
       enough without having things scrambled from the order you would
       type them.  To clarify all of this, I encourage you to actually
       execute the above statement sequence with an appropriately
       chosen file name and using semicolons instead of the commas and
       final period.  Afterwards, to return to the lesson, type CONT.
   7.  It is often more natural to use a string (e.g. "less5.red")
       rather than an identifier (e.g. less5!.red) for a filename.
       REDUCE accepts both.;

pause;

COMMENT Suppose you and your colleagues developed or obtained a set of
REDUCE files containing supplementary packages such as trigonometric
simplification, Laplace transforms, etc.  It would be a waste of time
(and distracting) to have these files displayed every time they were
input, so this output can be suppressed by inserting the statement
"OFF ECHO" at the beginning of the file.  (But don't forget to include
the statement "ON ECHO" at the end of the file.)

The lessons have amply demonstrated the PAUSE-statement, which is
useful for insertion in input files at the top-level or within
functions when input from the user is necessary or desired.

It often happens that after generating an expression, one decides that
it would be convenient to use it as the body of a function definition,
with one or more of the indeterminates therein as parameters, which
can be done as follows.  (If you input code like this directly rather
than from a file, you will need to agree to let REDUCE declare F to be
an operator.);

(1-(v/c)^2)^(1/2);
for all v saveas f(v);
f(5);

COMMENT Here the indeterminate V became a parameter of F.
Alternatively, we can save the previous expression to a variable.;

saveas fof5;
fof5;

COMMENT I find this technique more convenient than referring to the
special variable WS.;

pause;

COMMENT The FOR-loop provides a convenient way to form finite sums or
products with specific integer index limits.  However, this need is so
ubiquitous that REDUCE provides even more convenient syntax of the
forms

  FOR index := initial STEP increment UNTIL final SUM expression,

  FOR index := initial STEP increment UNTIL final PRODUCT expression.

As before, ":" is an acceptable abbreviation for "STEP 1 UNTIL".  As
an example of their use, here is a very concise definition of a
function which computes Taylor-series expansions of symbolic
expressions:;

algebraic procedure taylor(ex, x, pt, n);
   COMMENT This function returns the degree-N Taylor-series
      expansion of expression EX with respect to indeterminate X,
      expanded about expression PT.  For a series-like appearance,
      display the answer under the influence of FACTOR X, ON RAT,
      and perhaps also ON DIV;
   sub(x=pt, ex) + for k:=1:n sum(sub(x=pt, df(ex,x,k))*(x-pt)^k
                 / for j:=1:k product j);

clear a, x;  factor x;  on rat, div;
g1 := taylor(e^x, x, 0, 4);
g2 := taylor(e^cos(x)*cos(sin(x)), x, 0, 3);
% This illustrates the zero denominator limitation; continue anyway:
taylor(log(x), x, 0, 4);

COMMENT It would, of course, be more efficient to compute each
derivative and factorial from the preceding one.  (Similarly for
(X-PT)^K if and only if PT NEQ 0).

The Fourier series expansion of our example E^COS(X)*COS(SIN(X))
is  1 + cos(x) + cos(2*x)/2 + cos(3*x)/(3*2) + ... .
Use the above SUM and PRODUCT features to generate the partial sum of
this series through terms of order COS(6*X);

pause;

COMMENT Closed-form solutions are often unobtainable for nontrivial
problems, even using computer algebra.  When this is the case,
truncated symbolic series solutions are often worth trying before
resorting to approximate numerical solutions.

When we combine truncated series it is pointless (and worse yet,
misleading) to retain terms of higher order than is justified by the
constituents.  For example, if we wish to multiply together the
truncated series G1 and G2 generated above, there is no point in
retaining terms higher than third degree in X.  We can avoid even
generating such terms as follows:;

let x^4 = 0;
g3 := g1*g2;

COMMENT Replacing X^4 with 0 has the effect of also replacing all
higher powers of X with 0.  We could, of course, use our TAYLOR
function to compute G3 directly, but differentiation is time consuming
compared to truncated polynomial algebra.  Moreover, our TAYLOR
function requires a closed-form expression to begin with, whereas
iterative techniques often permit us to construct symbolic series
solutions even when we have no such closed form.

Now consider the truncated series:;

clear y;  factor y;
h1 := taylor(cos y, y, 0, 6);

COMMENT Suppose we regard terms of order X^N in G1 as being comparable
to terms of order Y^(2*N) in H1, and we want to form (G1*H1)^2.  This
can be done as follows:;

let y^7 = 0;
f1 := (g1*h1)^2;

COMMENT Note however that any terms of the form C*X^M*Y^N with
2*M+N > 6 are inconsistent with the accuracy of the constituent
series, and we have generated several such misleading terms by
independently truncating powers of X and Y.  To avoid generating such
junk, we can specify that a term be replaced by 0 whenever a weighted
sum of exponents of specified indeterminates and functional forms
exceeds a specified weight level.  In our example this is done as
follows:;

weight x=2, y=1;
wtlevel 6;
f1 := f1;

COMMENT Variables not mentioned in a WEIGHT declaration have a weight
of 0, and the default weight-level is 2.;

pause;

COMMENT Here is an example of how one might compute numerical
approximations to the cosine function.  (But note that REDUCE can
already do this automatically!)  One way is to provide a supplementary
LET rule for numerical arguments.  For example, since our TAYLOR
function would reveal that the Taylor series for cos x is
1 - x^2/2! + x^4/4! - ...;

for all x such that numberp x let abs(x) = x, abs(-x) = x;
epsrecip := 1024$
on rounded;
while 1.0 + 1.0/epsrecip neq 1.0 do
   epsrecip := epsrecip + epsrecip;

for all x such that numberp num x and numberp den x let cos x =
   begin COMMENT X is integer, real, or a rational number.  This rule
      returns the Taylor-series approximation to COS X, truncated when
      the last included term is less than (1/EPSRECIP) of the returned
      answer.  EPSRECIP is a global variable initialized to a value
      that is appropriate to the local floating-point precision.
      Arbitrarily larger values are justifiable when X is exact and
      ROUNDED is off.  No angle reduction is performed, so this
      function is not recommended for ABS(X) >= about PI/2;
   integer k;  scalar mxsq, term, ans;
   k := 1;
   mxsq := -x*x;
   term := mxsq/2;
   ans := term + 1;
   while abs(num term)*epsrecip*den(ans) - abs(num ans)*den(term) > 0 do
      << term := term*mxsq/k/(k+1);
         ans := term + ans;
         k := k+2 >>;
   return ans
   end;

cos(f) + cos(1/2);
off rounded;
cos(1/2);

COMMENT As an exercise, write a similar rule for the SIN or LOG, or
replace the COS rule with an improved one which uses angle reduction
so that angles outside a modest range are represented as equivalent
angles within the range, before computing the Taylor series.;

pause;

COMMENT There is a REDUCE compiler, and you may wish to learn how to
use it.  However, even if rules such as the above ones are compiled,
they will be slow compared to the implementation-dependent hand-coded
ones used by most FORTRAN-like systems, so REDUCE provides a way to
generate FORTRAN programs which can then be compiled and executed in a
subsequent job step.  This is useful when there is a lot of
floating-point computation or when we wish to exploit an existing
FORTRAN program.  Suppose, for example, that we wish to utilize an
existing FORTRAN subroutine which uses the Newton-Raphson iteration

   Xnew := Xold - SUB(X=Xold, F(X)/DF(F(X),X))

to attempt an approximate solution to the equation F(X)=0.  Most such
subroutines require the user to provide a FORTRAN function or
subroutine which, given Xold, returns F(X)/DF(F(X),X) evaluated at
X=Xold.  If F(X) is complicated, manual symbolic derivation of
DF(F(X),X) is a tedious and error-prone process.  We can get REDUCE to
relieve us of this responsibility as is illustrated below for the
trivial example F(X) = X*E^X - 1:

   ON FORT, ROUNDED,
   OUT FONDFFILE,
   WRITE "      REAL FUNCTION FONDF(XOLD)",
   WRITE "      REAL XOLD, F",
                F := XOLD*E^XOLD - 1.0,
                FONDF := F/DF(F,XOLD),
   WRITE "      RETURN",
   WRITE "      END",
   SHUT FONDFFILE.

COMMENT Under the influence of ON FORT, the output generated by
assignments is printed as valid FORTRAN assignment statements, using
as many continuation lines as necessary up to the number specified by
the global variable !*CARDNO, which is initially set to 20.  The
output generated by an expression which is not an assignment is a
corresponding assignment to a variable named ANS.  In either case,
expressions which would otherwise exceed !*CARDNO continuation lines
are evaluated piecewise, using ANS as an intermediate variable.

Try executing the above statement sequence, using an appropriate
filename and using semicolons instead of the commas and period at the
end of the lines (only), then view the file after the lesson to see
how it worked.;

pause;
off fort, rounded;

COMMENT To make this technique usable by non-REDUCE programmers, we
could write a more general REDUCE program which given merely the
expression F by the user, outputs not only the function FONDF, but
also any necessary job-control commands and an appropriate main
program for calling the Newton-Raphson subroutine and printing the
results.

Sometimes it is desirable to modify or supplement the syntax of
REDUCE.  For example:

   1.  Electrical engineers may prefer to input J as the
       representation of (-1)^(1/2).
   2.  A user might prefer to input LOGE to denote natural
       logarithms.  (Note that LN is already defined as a synonym for
       LOG.)
   3.  A user might prefer to use DERIV instead of DF to request
       differentiation.

Such lexical macros can be established by the DEFINE declaration:;

clear x, j;
define j=i, loge=log, deriv=df;

COMMENT Now watch!;

g1 := sub(x=loge(j^3*x), deriv(x^2,x));

COMMENT Each "equation" in a DEFINE declaration must be of the form
"name = item", where each item is an expression, an operator, or a
REDUCE-reserved word such as "FOR".  Such replacements take place
during the lexical scanning, before any evaluation, LET rules, or
built-in simplification.  Think of a good application for this
facility, then try it.;

pause;

COMMENT When REDUCE is being run non-interactively, with input from a
file rather than a terminal, it is preferable to have REDUCE make
reasonable decisions and proceed when it encounters apparently
undeclared operators, divisions by zero, etc.  In interactive mode, it
is preferable to pause and query the user.  ON INT specifies the
latter style, and OFF INT specifies the former.  Under the influence
of OFF INT, we can also have most error messages suppressed by
specifying OFF MSG.  This is sometimes useful when we expect abnormal
conditions and do not want our output marred by the associated
messages.  INT is automatically turned off during input from a file in
response to an IN-command from a terminal.;

pause;

COMMENT REDUCE provides a trace command for debugging, which employs
the syntax

   TR functionname1, functionname2, ..., functionnameN.

An analogous command named UNTR removes function names from trace
status;

pause;

COMMENT REDUCE also provides an assignment-tracing command for
debugging, which employs the syntax

   TRST functionname1, functionname2, ..., functionnameN.

An analogous command named UNTRST removes functionnames from this
status.  All assignments in the designated functions are reported,
except for assignments to array elements.  Such functions must be
uncompiled and must have a top-level BEGIN-block.  To apply both TRST
and TR to a function simultaneously, it is crucial to request them in
that order, and it is necessary to relinquish the two kinds of tracing
in the opposite order.;

pause;

COMMENT The REDUCE algebraic algorithms are written in a subset of
REDUCE called RLISP.  In turn, the more sophisticated features of
RLISP are written in a small subset of RLISP, which is itself written
in a simple dialect of LISP called Standard LISP.

RLISP is ideal for implementing algebraic algorithms, but the RLISP
environment is not most suitable for the routine use of these
algorithms in the natural mathematical style of the preceding lessons.
Accordingly, REDUCE is initially in a mode called ALGEBRAIC, which
provides the user with the environment illustrated in the preceding
lessons, while insulating him from accidental interaction with the
numerous functions, global variables, etc. necessary for implementing
the built-in algebra.  In contrast, the underlying RLISP system
together with all of the algebraic simplification algorithms written
therein is called SYMBOLIC mode.

As we have seen, algebraic-mode rules and procedures can be used to
extend the built-in algebraic capabilities.  However, some extensions
can be accomplished most easily or efficiently by descending to
SYMBOLIC mode.

To make REDUCE operate in symbolic mode, we merely execute the top-
level mode-declaration statement consisting of the word SYMBOLIC.  We
can subsequently switch back by executing the statement consisting of
the word ALGEBRAIC.

RLISP has the semantics of LISP with the syntax of our by-now-familiar
algebraic-mode REDUCE, so RLISP provides a natural tool for many
applications besides computer algebra, such as games, theorem-proving,
natural-language translation, computer-aided instruction, and
artificial intelligence in general.  For this reason, it is possible
to run RLISP without any of the symbolic-mode algebraic algorithms
that are written in RLISP, and it is advisable to thus save space when
the application does not involve computer algebra.  (An RLISP system
is a step in the process of building a complete REDUCE system, but is
not distributed as an independent application, although one can be
built from the source code available.)

We have now discussed virtually every feature that is available in
algebraic mode, so lesson 6 will deal solely with RLISP, and lesson 7
will deal with communication between ALGEBRAIC and SYMBOLIC mode for
mathematical purposes.  However, I suggest that you proceed to those
lessons only if and when:

   1.  You have consolidated and fully absorbed the information in
       lessons 1 through 5 by considerable practice beyond the
       exercises therein.  (The exercises were intended to also
       suggest good related project ideas.)
   2.  You feel the need for a facility which you believe is
       impossible or quite awkward to implement solely in ALGEBRAIC
       mode.
   3.  You have read the pamphlet "Introduction to LISP", by D. Lurie,
       or an equivalent.
   4.  You are familiar with the definition of Standard LISP, as
       described in the "Standard LISP Report" which was published in
       the October 1979 SIGPLAN Notices.  [This is available from the
       REDUCE web site.]

Don't forget to view or print your newly generated FORTRAN file and to
delete any temporary files created by this lesson.;

;end;
