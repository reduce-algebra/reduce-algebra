load_package crackapp;  % Needed for these tests.

% Initial load up list
off echo$

lisp(depl!*:=nil)$     % clearing of all dependences
setcrackflags()$
lisp write
"...................................................................",
"......."$
write "An example of the determination of point symmetries for ODEs"$
depend y,x$
de := {df(y,x,2) = (df(y,x)*(2*x*y+x**3) - 4*y**2)/x**4, 
       y, x}$
mo := {0,nil,nil}$      
LIEPDE(de,mo)$
nodepend y,x$
lisp write
"...................................................................",
"......."$
write "An example of the determination of point symmetries for PDEs"$
depend u,x,y$
de := {df(u,x,x)-df(u,y),u,{x,y}}$
mo := {0,nil,nil}$
LIEPDE(de,mo)$
nodepend u,x,y$
lisp write
"...................................................................",
"......."$
write "An example of the determination of first integrals of ODEs"$
depend y,x$
de := {df(y,x,2)=x*df(y,x)**2-2*df(y,x)/x-y**2/x, y, x}$
mo := {0,{},2}$
FIRINT(de,mo)$
nodepend y,x$
lisp write
"...................................................................",
"......."$
write "An example of the determination of a Lagrangian for an ODE  "$
depend f,x$
depend y,x$
de := {df(y,x,2) = 6*y**2 + x, y, x}$
mo := {0,{}}$
LAGRAN(de,mo)$
nodepend f,x$
nodepend y,x$
lisp write
"...................................................................",
"......."$
write "An example of the factorization of an ODE  " $
depend f,x$
depend y,x$
depend q,x$
de := {df(y,x,2) = df(y,x)**2/y - f*df(y,x) - y*q, y, x}$
mo := {2,{}}$
DECOMP(de,mo)$
nodepend f,x$
nodepend y,x$
nodepend q,x$

end$
