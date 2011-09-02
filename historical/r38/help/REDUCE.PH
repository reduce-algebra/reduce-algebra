"false";
"no";
"small";
"yes"
(<argument>)
(<coeffs>,<var>=(<lo> .. <hi>)
(<exp>,
(<expr>,<k>[,<lolim> [,<uplim> ]])
(<expr>,<var>,<limpoint>) or
(<expression
(<expression>)
(<expression>) or
(<expression>,<expression>
(<expression>,<expression>) or <expression>
(<expression>,<integer>)
(<expression>,<kernel>
(<integer>)
(<integer>,<expression>)
(<integer>,<expression>,<expression>
(<integer>,<integer>
(<list of j1,m1>,<list of j2,m2>, <list of j3,m3>)
(<list of parameters>,<list of parameters>,  <argument>)
(<list>) or
(<matrix>)
(<matrix>,<column
(<matrix>,<r>,<c>
(<order>,<argument>)
(<parameter>,<parameter>,<argument>)
(A say). It returns
(If you are feeling lazy then the braces can be omitted.)
(LIST
(a + b*i)*(c + d*i); 
(default
(e.g.
(i,j)'th
(or other variable declaration such as
(see
(which
(x + y)**3; 
(x+1)/x + x**2/sin y;       
). A numeric value is not returned by
); 
***** A invalid as integer
***** Matrix
***** X invalid as KERNEL
,  
, and
, its arguments are reordered to conform to the internal ordering of the system.
, or
, that is a variable preceded by the tilde symbol: the expression  is evaluated for each element of <object> where the element is  substituted for the free variable,
, the
, the printing behavior is as if
, there are no algebraic rules associated with it; it will only evaluate when
, where
, which would be right associative.
, without a semicolon between
,3*X  + 7*X + 3,2*COS(2*X)}
,3x**2+7x+3,df(sin(2*x),x)
- -------
-------
---------
-----------
-------------
----------------
---------------------------------
.  
. Default is
. For non-numeric arguments, the value is an expression in the original operator.
. If
. In addition, if an operator has more than one argument, no such distribution occurs, so
. The
. This is done by the commands
. You may wish to add a check to see that its argument is properly restricted.
...
..........
0  
0.......0
0.00000000000000012
0.70710678118
1  
1  2      3
10*(Y  + 12*Y  + 54*Y  + 108*Y + 81),
2     
2         
2            
2                    2            2
2    2
2  2
2.2798561599
3      
3      2
4       3       2
4      3          3    4
4      3        2  2        3    4
4    3    2
5*(Y  + 12*Y  + 54*Y  + 108*Y + 81),
:- if on then
;  
<<a := 23;b := 2*a;c := 4**2;m
<action>
<column
<condition>
<equation>
<exp>
<expr
<expr>
<expr> :- a scalar expression.
<expr> :- an algebraic expression.
<expression
<expression>
<expression> can be any
<expression> can be any REDUCE scalar expression.
<expression> can be any valid REDUCE
<expression> can be any valid REDUCE expression that evaluates to a number.
<expression> can be any valid scalar REDUCE expression
<expression> is any valid scalar REDUCE expression
<expression> is expected to be a polynomial expression, not a rational expression. Rational expressions are accepted when the switch
<expression> is ordinarily a polynomial. If
<expression> m
<expression> may be any scalar REDUCE expression, not an array, matrix or vector expression. <simple
<expression> may be any scalar REDUCE expression.
<expression> may be any valid REDUCE expression.
<expression> must evaluate to a
<expression> must evaluate to a number, e.g., integer, rational or floating point number.
<filename>
<function>
<identifier>
<identifier> can be any valid REDUCE identifier.
<identifier> may be any valid REDUCE identifier
<identifier> must
<integer>
<item>
<kernel>
<kernel> must be a
<line-id>
<list>
<logical expression>
<matrix
<matrix>
<matrix> :- a
<matrix> :- a matrix.
<matrix> :- a square
<matrix>.
<name>
<number>
<object>
<operator>
<r>,<c> :- positive integers such that <matrix>(<r>,  <c>) neq 0.
<r>,<c> :- positive integers.
<restricted
<simple
<simple_expression> 
<square
<statement>
<string>
<substitution>
<var>
<var>[=<val>]
<variable
<vector-var>
= <string>
A :=
A := 10 
A numeric value is not returned by
A variable preceded by a
A(1,1) :=
A(2,1) :=
A(2,2) :=
A*C + A*D*I + B*C*I - B*D 
A*D - B*C
AGM_function
ALIST :=
ARBCOMPLEX
ASIN(
ATAN
After
Airy_Ai
Airy_Bi
Algebra
Alternatively
An explicit numeric value is not given unless the switch
Any variables used inside
Arithmetic
Array
Assign
At the present time, it is possible to have both switches on at once, which could lead to infinite recursion. However, an expression is switched from one form to the other in this case. Users should not rely on this behavior, since it may change in the n
Author:
Author: Eberhard Schruefer
Author: Francis J. Wright
Author: Herbert Melenk
Authors:
BERNOULLI
BESSEL
BLIST :=
Basic Groebner operators
Be careful
Bernoulli
BernoulliP
Bessel
Binomial
Buchberger
By default, calculations are performed in the rational numbers. To extend this field the
CE concept of idempotent evaluation. As an alternative, REDUCE provides two switches
COS(A - B) + COS(A + B)
COS(Y)*DF(Y,X
Chebyshev
Clebsch_Gordan
Combinatorial Operators
Comparison operators can only be used as conditions in conditional commands such as
Computation
Computing with distributive polynomials
Cont? (Y or N)
Declaration
Declare
Default
ELLIPTIC
Elliptic
Error
Euler
Evaluates
Expressions
Extensions
FACTOR
Factorizing Groebner bases
Field Extensions:
For
Fortran
Fortran-compatible
Fresnel
Function
Functions
GNUPLOT
GROEBNER
Gamma and Related Functions
Gegenbauer
Groebner
Groebner Bases for Modules
Groebner_walk
HUGO := 1 + X + -*X  + O(X )
Hankel
Heaviside
Herbert
HermiteP
However,
Hypergeometric
IDENT
If 
If the
If you
In many cases it is desirable to expand product arguments of logarithms, or collect a sum of logarithms into a single logarithm. Since these are inverse operations, it is not possible to provide rules for doing both at the same time and preserve the REDU
Integral
Integrals
It has dimension n where n is the number of expressions.
It returns
JACOBI
Jacobi
Jacobi's Elliptic Functions and Elliptic Integrals
JacobiAmplitude
Jacobian
Jacobic
Jacobid
Jacobin
Jacobis
Kredel-Weispfenning
LaguerreP
Legendre
Linear Algebra package
Lisp
Logical operators can only be used in conditional expressions
Logical operators can only be used in conditional statements such as
Logical operators can only be used inside conditional
MULTIPLICITIES
Matrices
Matrix
Meijer
Melenk
Miscellaneous
Modular Arithmetic:
Modular operations are
No simplification is done for this function.
Note
Note that
Numeric Package
Numerical
ORDER
Operations
Operator
Otherwise
PACKAGE
PROCEDURE
Package
Pochhammer
Polygamma
Polynomial
Procedure
REDUCE
REDUCE's
REDUCE,
REDUCE.
RES := 0.785398163397 
ROOT
ROUND
Related functions:
Result
Roots Package
SIN(X)
SIN(Y
SQRT(
SQRT(24*Y  + 60*Y + 25)
SQRT(3)
STIRLING
Scalar
Since
SixjSymbol
SolidHarmonicY
Special Function Package
SphericalHarmonicY
Stirling
TAYLOR
TERM
Taylor
The
The binary comparison operators can only be used for comparisons between numbers or variables that evaluate to numbers. The truth values returned by such a comparison can only be used inside programming constructs, such as
The command
The declaration
The exponentiation operator is left associative, so that
The first
The following
The functions
The integer value of the global variable
The minimal accuracy of the result values is controlled by
The numeric values for the operator
The operator
The s
The te
The variable
Then
There
These
This
ThreejSymbol
Time:
Time: 1
Time: 80 ms 
To change the
Under normal circumstances
When
When an operator is declared
When the
When the operator
When the switch
WhittakerW
With
X  
X  +
X  - 2*X *Y + 2*X*Y  - Y
X  - X  + X  - X  + X 
X=2*ARBINT(1)*PI + ASIN(1) + PI - 3}
You
You can write a procedure to attach integrals or other functions to
You may attach functionality by defining
You may attach further functionality by defining
Zeta
[    
[       
[        
[         
[             
[                  
[                      
[                                   
[                  ]
[                 ]
[                ]
[             ]
[            ]
[          ]
[       2                              2                  ]
[       ]
[      2      ]
[    - 1          - 1          - 1    ]
[    ]
[   25*y  - 2*y + 1             2*(25*y  - 2*y + 1)       ]
[  1      i      0  ]
[,accuracy=<a>][,iterations=<i>])
[-----------  -----------  -----------]
[----------------------  ---------------------------------]
[0 
[0  
[0  0  0 
[0  0  0  0  0]
[0  1 
[1   
[1  2  3]
[4  5  6]
[7  8  9]
[i + 1  i + 2  i + 3]
a :=
a := 10; 
a := 15; 
a := [   
about
above
above.
absolute
access
according
accuracy
acosh
acsc
action
activate
actual
add_columns
add_rows
add_to_columns
add_to_rows
added
addition
additional
affect
after
again
algebra
algebraic
algint
algorithm
algorithms
alist :=
all
allbranch
allowed
allows
alphabetical
already
also
alternative
always
ambiguity
and
and some simple transformations are known to the system.
and stands for an arbitrary part
and the
and the first variable declaration.
and the number zero are
another
answer
antisymmetric
any
anywhere
appear
appear on the left-hand side, all but the first term of the expression is moved to the right-hand side.
appearing
appears on the left-hand side, any constant terms are moved to the right-hand side, but the symbolic factors remain.
append
application
applied
applies
apply
appropriate
approximate
approximation
arbcomplex
arbitrary
arbvars
arccosecant
are
are computed via the power series representation, which limits the argument range.
are global, and any change made to them inside the block affects their global value. A
arglength
argument
argument,
argument.
arguments
arguments,
arguments.
arithmetic
around
array
array,
asech
asinh
assign
assigned
assignment
associated
associative
assume
assumption
asymptotic
attach
attached
attempt
augment_columns
automatically
auxiliary
available
avoid
axes names
b :=
balanced_mod
band_matrix
based
bases
basic
basis
because
become
been
before
begin
begin scalar
begin scalar b; b := a + 10; WRITE A end; 
beginning
begins
behavior
being
between
binary
blist :=
block
block. When the block is finished, the variables are removed. You may use the words
block_matrix
blocks that were not declared
boolean
boolean value
both
bounds
bounds(sin x,x=(1 .. 2));
braces
bracket
branch
built
but
calculated
calculates
calculation
calculations
calculations.
call
called
calling
calls
can
can also be calculated in a modular base. To do this first type on modular;. Then setmod p; (where p is a prime) will set the modular base of calculation to p. By further typing on balanced_mod the answer will appear using a symmetric modular representat
can also be used
can be
can be turned on.
can be used
cannot
canonical
careful
case
case,
case.
cases
cases,
causes
certain
change
changed
changes
char_matrix
char_poly
character
characteristic
characters
chebyshev_
check
cholesky
class
clear
cleared
clearrules
closed
coeff
coeff_matrix
coefficient
coefficients
coeffn
cofactor
collect
collected
collection
column
column_dim
columns,
combination
combine
command
command changes REDUCE's mode of operation to symbolic. When
command ends the REDUCE session, returning control to the program (e.g., the operating system) that called REDUCE. When you are at the top level, the
command,
command, group or block      each iteration of the loop,
command.
commands
comment
common
commutat
companion
comparison
compiled
complete
complex
complicated
component
computation
compute
computed
computes
computes the
computes the Jordan normal form J of a
computing
concept
condition
conditional
conditions
conjugate
connect
cons
considered
consist
constant
constraint
construc
construction
constructs
contain
containing
contains
contents
continue
continued_fraction
continues
contour
contraction
control
controlled
controls
convert
converted
coordinate
copy_into
correct
corresponding
cos(a)*cos(b); 
cos(~x)*sin(~y) => (sin(x+y)-sin(x-y))/2,
cos(~x)^2       => (1+cos(2*x))/2,
coshval(1); 
could
count
cramer
create
cross-referenc
current
currently
curve
decimal
declaration
declaration must be made immediately after a
declare
declared
declared inside a block is always global.
declaring
decompose
decomposition
default
define
defined
defines
defining
definite
definition
defint(
defpoly
degree
degrees,
delimiter
denominator
denote
depend
dependencies
dependency
dependent
depending
derivative
describe
desired
detail
determin
determinant
df(sin(7*x + y),x); 
diagonal
difference
different
differential
differentiat
differentiation
dilog
dimension
dimensions
direction
directly
directory
display
distribution
divided
division
divisor
documentation
does
does not indicate typechecking by the current REDUCE; it is only for your own information. Declaration statements must immediately follow the
doing
dollar
domain
done
double
during
e.g.
each
echo
editing
editor
effect
effect.
effects.
efficient
eigenvector
either
element
elements
eliminat
else
else for i := 0:n-1 product i+1;
empty
enclosed
end
end;
entered
entries
entry
equal
equation
equations
equations.
equivalent
error
escape
establish
evallhseqp
evaluate
evaluated
evaluates
evaluation
even
evenp
eventual
every
exactly
example
example,
example.
examples:
except
exclamation
execute
executed
executing
execution
existing
expand_cases
expanded
expanding
expandlogs
expansion
expect
expensive
explicit
explicitly
exponential
exponentiation
exponents
expresse
expression
expression,
expression.
expression>
expression> is a single identifier or begins with a prefix operator name.
expression> must
expression> must be a single identifier or begin with a prefix operator name.
expression> must be a single identifier or begin with a prefix operator.
expressions
expressions.
expt
extend
extended
extract
facilitate
facilities
factor
factored
factorial
factoring
factorization
factorize
factorize(4*x**2 + 28*x + 48); 
factorize(a**2 + b**2); 
factorize(x^15 - 1); 
factors
false
faster
feeling
field
file
file,
file.
files
find
find_companion
finding
finds
finite
first
first lu * second lu; 
floating
floating-point
followed
following
for
for all
for an example.
for each
forall
form
form,
form.
formal
format
forms
formula
found
four-vectors
fraction
free
free variable
freeof
frobenius
from
full
fullroots
function
function.
functionality
functions
functions,
functions.
functions:
further
g := (exp(a) + exp(-a))/2;
g(line1,a1,b1)*g(line2,b1,c1); 
gamma
garbage
general
generally
generat
generate
generated
get_columns
get_rows
given
given,
given.
global
globally
gltbasis
graded
gradlex term order
gradlexgradlex term order
gradlexrevgradlex term order
gram_schmidt
graph
greater
greatest
groebfullreduction
groebmonfac
groebner
groebner_walk
groebnerf
groebnert
groebopt
groebprereduce
groebprot
groebrestriction
groebstat
group
gvarslast
handle
has
has a limited numeric evaluation of large values of its argument.
has been
has no effect.
have
hermitian
hessian
high-energy
higher
highest
hilbert
homogeneous
hugo := taylor(exp(x),x,0,2); 
hyperbolic
hypergeometric
ideal
ideal parameters
idealquotient
identical
identifier
identifier,
identifier, then <restricted
identifier.
identifiers
identity
if 
if fixp(a) then write "ok" else write "not";
if not (fixp(n) and n>=0)
if not numberp(a) then write "
if numberp a and a < 15 then write a**2 else write "no";
if numberp x and x<20 then y := sqrt(x) else write "illegal";
if you wish. Numerical values of expressions involving
ifactor
ignored
imaginary
immediately
impart
implementation
implements
implicit
important
in applications different from classical linear algebra.
in the place of
include
included
includes
including
increase
indefinite
independent
indeterminate
index
indicate
indicating
indices
individual
inequalities
infinite
infinity
infix
information
inhibit
initial
initialize
initially
input
inside
instead
int
integer
integer,
integer.
integers
integers.
integra
integral
integration
interactive
intermediate
internal
interpolation
interpret
interval
into
introduction
invalid
inverse
inversion
invertible
involving
is 
is a
is a list of expressions or equations.
is a synonym for
is also called Bessel function of the third kind. There is currently no numeric evaluation of Hankel functions.
is also declared non zero by the declaration
is equivalent to
is evaluated for each element of <object> where  the element is substituted for
is known to the system. Numerical values may also be found by turning on the switch
is member of the options for a 3d
is off
is off, regardless of the setting of
is off.
is on
is on and its argument evaluates to a number.
is on and the argument has an absolute numeric value less than or equal to 1.
is on,
is on, a
is on, a rational expression may also be used, otherwise an error results. <kernel> must be a
is on, expressions in the differentiation operator
is on.
is printed. If the user replies
is replaced by zero unless
is reserved for use as the
is set
is simplified towards
is still attached to it. When <identifier> is subsequently used as an operator, the message
iteration
iterative
its
jacobian
jordan_block
jordansymbolic
kernel
kernel,
kernel.
kernels
key is your delimiter for the input string.
knowledge
known
korder
lambda
large
last
leading
least
left
left-hand
length
less
let
level
level,
lex term order
like
limit
limited
limitedfactors
limits
line
line,
line.
linear
linelength
lines
liss
list
list,
list.
list>
list> :- a positive integer or a list of positive  integers.
list> :- either a positive integer or a list of positive  integers.
list> :- either a single
list> :- either a single variable or a list of  variables.
list> :- list of algebraic expressions.
list>)
list>.
listarg
lists
load_package
loaded
local
logarithm
logical
logical operator returns
long
lower
lu_decom
m := mat((a,b),(c,d)); 
made
main
make
make_identity
manipulation
many
mass
mat
mat((
mat((i+1,i+2,i+3),(4,5,2),(1,i,0));
match
mateigen
mathematical
matrices
matrices.
matrix
matrix,
matrix.
matrix_augment
matrix_stack
matrixp
may
may also be found by turning on the switch
may also be raised to positive and negative powers with the exponentiation operator (negative powers require the matrix to be invertible). Scalar expressions and
may be
may be  optionally preceded by a tilde.
means
member
message
message.
messages
method
minimal
minimum
minor
minus
missing
mode
mode,
mode, if <expression> is a real number, the operator
mode, if <list> is a list of three real numbers, the operator
mode.
modular
module
modulus
monomial
more
most
mshell
mult_columns
mult_rows
multiple
multiplication
multiplicities
multiplicity
multiplied
multiply
multivariate
must
n-ary
name
name.
names
natural
necessary
need
needed
negative
nested
new
next
nextprime
nil
nodepend
non-negative
non-numeric
nonneg.
nonzero
normal
normally
not
notation
nprimitive
nullspace
num_odesolve
num_solve
number
number,
number.
numbered
numberp
numberp(
numbers
numbers,
numbers.
numerator
numeric
numeric accuracy
numerical
objects
occur
occurs
of 
off
off exp; 
off rounded; 
off,
off.
often
omitted
omitted.)
on complex; 
on fort; 
on modular;
on rounded;
on rounded; 
on,
on.
once
one
only
operation
operations
operator
operator f; 
operator is
operator is a binary infix or prefix logical operator. It returns
operator is included in the package specfn2.
operator is left associative:
operator is right associative
operator is used
operator returns
operator returns the
operator which implements the
operator,
operator.
operators
operators,
operators.
option:
option: Assign a name to to the
optional
optional free variable
options
or 
or a
or an algebraic expression with exactly one
order
order.
ordered
ordering
ordinarily
ordinary
original
orthogonal
other
otherwise
otherwise.
out
output
outside
over
package
package can be used. The package must first be loaded by load_package arnum;. The field can now be extended by using the defpoly command. For example, defpoly sqrt2**2-2; will extend the field to include the square root of 2 (now defined by sqrt2). See
parameter
parameters
parentheses
part
partial
particular
parts
pattern
pause
performed
performs the equivalent task on the rows of <matrix>.
performs the same task
performs the same task on the rows of <matrix>.
pf(2/((x+1)^2*(x+2)),x);
physics
picture
pivot
place
placed
places
plot
plot_xmesh
plot_ymesh
plus
point
point.
pointer
points
polynomial
polynomial.
polynomials
polynomials.
position
positive
possible
power
powers
preceded
precedence
precise
precision
predicate
preduce
prefix
previous
previously
prime
print
print_precision
printed
printed,
printed.
printing
problem
procedure
procedure coshval(a);
procedure fac(n);
procedure.
procedures
process
produce
produced
produces
producing
product
production
products
program
programming
programs
prompt
properties
property
provide
provides
pseudo_inverse
put
quotient
radians
raised
random
random_matrix
range
range.
ratarg
rather
rational
ratjordan
read
real
realroots
recurrence
recursive
redefine
rederr
redimension
reduce
reduct
reference
related
relation
remain
remainder
remains
remove
remove_columns
remove_rows
removed
removes
repart
repeat
replace
replacement
replaces
represent
representation
represented
representing
represents
require
required
requirements
reserved
respect
respectively.
rest
restricted
restriction
resubstitution
result
resultant
resulting
results
results.
return
returned
returned.
returning
returns
returns a numeric value only
returns an error message.
reverse
revgradlex term order
right
right-hand
root
root_multiplicities
root_of
roots
round
rounded
rounded;
rows
rows_pivot
rule
rules
s may be raised to fractional and floating-point powers.
same
saveas
savestructr
scalar
scientific
scientific_notation
screen
second
see
see:
select
semicolon
separate
sequence
series
session
session,
session.
set
setmod
sets
setting
several
share
should
shown
showrules
side
sides
sign
significan
similar
simple
simplif
simplification
simplified
simultaneous
sin(x)
sin(~x)*sin(~y) => (cos(x-y)-cos(x+y))/2,
sin(~x)^2       => (1-cos(2*x))/2}
since
single
singular
size>
size> :- a positive integer.
smithex_int
solution
solve
solve(
solve(log(sin(x+3)),x); 
solvesingular
solving
some
sometimes
space
special
specific
specifically
specified
specifies
sqrt(
sqrt2**2-2;
square
stack_rows
standard
starting
statement
statement,
statement.
statement>
statements
statements and procedures to add further functionality to
statements,
statements.
steps
sticks the matrices in <matrix
still
stored
string
structr
structure
sub_matrix
subexpressions
subscript
subsequent
substitute
substitution
subtraction
such
such that
sufficient
sum
supplie
support
suppressed
surface
swap_columns
swap_entries
swap_rows
switch
switch is
switch only has effect when the
switches
symbol
symbolic
symbols
symmetr
symmetric
syntax
syntax:
system
system.
systems
take
taken
takes
tangent
taylor
taylor(e^(x^2+y^2),x,0,4,y,0,4); 
taylor(exp(x),x,0,2);
taylorautoexpand
taylorcombine
taylorcombine(hugo + x); 
taylorkeeporiginal
taylororiginal
taylorprint
taylorrevert
taylorseriesp
taylortemplate
taylortostandard
techniques
term
term order
terminal
terminat
terminate
terms
than
that
the
their
them
them.
themselves
then
then rederr "Choose nonneg. integer only"
there
therefore
these
they
third
this
those
though
three
tilde
time
time,
times
to be the inverse of
to carry out these operations.
toeplitz
together
top-level
torder
torder_compile
total
trace
trallfac
transform
transformations
trgroeb
trigonometric
true
true.
truncat
truth
turn
turned
turning
two
type
unary
unchanged.
under
unique
univariate
unless
unless the switch
until
upper
use
used
used,
used.
useful
user
uses
using
usual
usually
valid
value
value,
value.
values
values,
values.
vandermonde
variable
variable.
variables
variables,
variables.
various
vector
vector aa,bb,cc; 
vectors
want
warning
was
weight
weighted
weighted term order
weights
well
when
where
where <
where <bas> is a
where <p> is a polynomial or a list of polynomials.
where <p> is a univariate polynomial
where <p> is an expression,
where <var> is a variable (a <kernel> without subscript)  and <rep> is an expression which contains <var>.  Here
whether
which
which is equivalent to 
while
will
wish
with
within
without
words
workspace
would
write
written
ws; 
wtlevel
x + x*y**3 + x**2*cos(z); 
x**5 + x**2 + 18 + sqrt(y); 
you
your
zero
zero.
zeros
{,<expression>}
{,<identifier>}
{,<kernel>
{,<vector-
{1,2,
{2.27985615996629, 2.27985615996629,
{2x + y,4x + 2y}
{7x + 15y - z,x - y - z}
{<exp>, ...
{<exp>,...}
{<exp>,<exp>,...
{A,B,C,D}
{AA,BB,CC}
{Return}
{X  + X  + X  + X + 1,1}
{X -
{X= -
{X=2*ARBINT(1)*PI - ASIN(1) - 3,
{a,b,c,d}
{aa,bb,cc}
{cos(~x)*cos(~y) => (cos(x+y)+cos(x-y))/2,
{exp1, exp2, ... , expm}
{x,y,z}
{x,y}
{x=sqrt(3),x= - sqrt(3)}
