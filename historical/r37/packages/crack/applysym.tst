off echo, dfprint$                      % FJW

% You need crack.red and applysym.red to run this demo.
% To use other contents of the program applysym, not demonstrated
% in this demo you need the program liepde.red.
%
% To run this demo you read in files with
%    in "crack"$
%    in "applysym.red"$
% or, to speed up the calculation you compile them before with
%    faslout "crack"$
%    in "crack"$
%    faslend$
%    faslout "applysym"$
%    in "applysym.red"$
%    faslend$
% and then load them with
%    load crack,applysym$

lisp(depl!*:=nil)$     % clearing of all dependences
setcrackflags()$
lisp(print_:=nil)$

lisp <<
write"-------------------------------------------------------"$terpri()$
write"This file is supposed to provide an automatic test of"$terpri()$
write"the program APPLYSYM. On the other hand the application"$terpri()$
write"of APPLYSYM is an interactive process, therefore the"$terpri()$
write"interested user should inspect the example described"$terpri()$
write"in APPLYSYM.TEX which demonstrates the application"$terpri()$
write"of symmetries to integrate a 2nd order ODE."$terpri()$
write"Here the program QUASILINPDE for integrating first"$terpri()$
write"order quasilinear PDE is demonstrated."$terpri()$terpri()$
write"The following equation comes up in the elimination"$terpri()$
write"of resonant terms in normal forms of singularities"$terpri()$
write"of vector fields (C.Herssens, P.Bonckaert, Limburgs"$terpri()$
write"Universitair Centrum/Belgium, private communication)."$terpri()$
write"-------------------------------------------------------"$terpri()$
>>$

depend w,x,y,z$
QUASILINPDE( df(w,x)*x+df(w,y)*y+2*df(w,z)*z-2*w-x*y,  w,  {x,y,z} )$
nodepend w,x,y,z$


lisp <<terpri()$
write"-------------------------------------------------------"$terpri()$
write"Comment:"$terpri()$
write"The result means that w is defined implicitly through "$terpri()$
terpri()$
write"        x*y    - log(z)*x*y + 2*w      y              "$terpri()$
write"0 = ff(-----,---------------------,---------)         "$terpri()$
write"         z             z            sqrt(z)           "$terpri()$
terpri()$
write"with an arbitrary function ff of 3 arguments. As the PDE"$terpri()$
write"was linear, the arguments of ff are such that we can "$terpri()$
write"solve for w:                                   "$terpri()$
terpri()$
write"                        x*y      y             "$terpri()$
write"w = log(z)*x*y/2 + z*f(-----,---------)        "$terpri()$
write"                         z    sqrt(z)          "$terpri()$
terpri()$
write"with an arbitrary function f of 2 arguments."$terpri()$terpri()$
write"-------------------------------------------------------"$terpri()$
write"The following PDEs are taken from E. Kamke,"$terpri()$
write"Loesungsmethoden und Loesungen von Differential-"$terpri()$
write"gleichungen, Partielle Differentialgleichungen"$terpri()$
write"erster Ordnung, B.G. Teubner, Stuttgart (1979)."$terpri()$
>>$

write"------------------- equation 1.4 ----------------------"$
lisp(depl!*:=nil);
depend z,x,y$
QUASILINPDE( x*df(z,x)-y, z, {x,y})$
write"------------------- equation 2.5 ----------------------"$
lisp(depl!*:=nil);
depend z,x,y$
QUASILINPDE( x**2*df(z,x)+y**2*df(z,y), z, {x,y})$
write"------------------- equation 2.6 ----------------------"$
lisp(depl!*:=nil);
depend z,x,y$
QUASILINPDE( (x**2-y**2)*df(z,x)+2*x*y*df(z,y), z, {x,y})$
write"------------------- equation 2.7 ----------------------"$
lisp(depl!*:=nil);
depend z,x,y$
QUASILINPDE( (a0*x-a1)*df(z,x)+(a0*y-a2)*df(z,y), z, {x,y})$
write"------------------- equation 2.14 ---------------------"$
lisp(depl!*:=nil);
depend z,x,y$
QUASILINPDE( a*df(z,x)+b*df(z,y)-x**2+y**2, z, {x,y})$
write"------------------- equation 2.16 ---------------------"$
lisp(depl!*:=nil);
depend z,x,y$
QUASILINPDE( x*df(z,x)+y*df(z,y)-a*x, z, {x,y})$
write"------------------- equation 2.20 ---------------------"$
lisp(depl!*:=nil);
depend z,x,y$
QUASILINPDE( df(z,x)+df(z,y)-a*z, z, {x,y})$
write"------------------- equation 2.21 ---------------------"$
lisp(depl!*:=nil);
depend z,x,y$
QUASILINPDE( df(z,x)-y*df(z,y)+z, z, {x,y})$
write"------------------- equation 2.22 ---------------------"$
lisp(depl!*:=nil);
depend z,x,y$
QUASILINPDE( 2*df(z,x)-y*df(z,y)+z, z, {x,y})$
write"------------------- equation 2.23 ---------------------"$
lisp(depl!*:=nil);
depend z,x,y$
QUASILINPDE( a*df(z,x)+y*df(z,y)-b*z, z, {x,y})$
write"------------------- equation 2.24 ---------------------"$
lisp(depl!*:=nil);
depend z,x,y$
QUASILINPDE( x*(df(z,x)-df(z,y))-y*df(z,y), z,{x,y})$
write"------------------- equation 2.25 ---------------------"$
lisp(depl!*:=nil);
depend z,x,y$
QUASILINPDE( x*df(z,x)+y*df(z,y)-az, z, {x,y})$
write"------------------- equation 2.26 ---------------------"$
lisp(depl!*:=nil);
depend z,x,y$
QUASILINPDE( x*df(z,x)+y*df(z,y)-z+x**2+y**2-1, z, {x,y})$
write"------------------- equation 2.39 ---------------------"$
lisp(depl!*:=nil);
depend z,x,y$
QUASILINPDE( a*x**2*df(z,x)+b*y**2*df(z,y)-c*z**2, z, {x,y})$
write"------------------- equation 2.40 ---------------------"$
lisp(depl!*:=nil);
depend z,x,y$
QUASILINPDE( x*y**2*df(z,x)+2*y**3*df(z,y)-2*(y*z-x**2)**2, z,
             {x,y})$
write"------------------- equation 3.12 ---------------------"$
lisp(depl!*:=nil);
depend w,x,y,z$
QUASILINPDE( x*df(w,x)+(a*x+b*y)*df(w,y)+(c*x+d*y+f*z)*df(w,z), w,
             {x,y,z})$
write"------------------------ end --------------------------"$

lisp(depl!*:=nil);
end;
