off echo, dfprint$                      % FJW

%*******************************************************************%
%                                                                   %
%  CONLAW.TST  contains test examples for the programs CONLAW1.RED  %
%  CONLAW2.RED, CONLAW3.RED                                         %
%                                                                   %
%  Author: Thomas Wolf                                              %
%  Date:   1. Jan 1998                                              %
%                                                                   %
%  Details about the syntax of CONLAWi are given in CONLAW.TEX.     %
%  To run this file read in or load CRACK, CONLAW0.RED before.      %
%                                                                   %
%*******************************************************************%

lisp(depl!*:=nil)$     % clearing of all dependencies
setcrackflags()$       % standart flags
lisp(print_:=nil)$     % no output of the calculation

lisp <<terpri()$write
"If you want to see more details of the following calculation then"$
terpri()$write"change in the file `conlaw.tst' the line"$
terpri()$write"        lisp(print_:=nil)$ "$
terpri()$write"into"$
terpri()$write"        lisp(print_:=10)$ "$
terpri()>>$

lisp <<terpri()$write
"**************************************************************************"$
terpri()$terpri()$write
"The following example calculates all conservation laws of the KdV-"$
terpri()$write
"equation with a characteristic function of order not higher than two"$
terpri()>>$

nodepnd {u}$   % deletes all dependencies of u
depend u,x,t$  % declares u to be a function of x,t
conlaw3({{df(u,t) = u*df(u,x)+df(u,x,3)}, {u}, {t,x}},
        {0, 2, t, {}, {}}                             )$

lisp <<terpri()$write
"**************************************************************************"$
terpri()$terpri()$write
"The next example demonstrates that one can specify an ansatz"$
terpri()$write
"for the characteristic function of one or more equations of the"$
terpri()$write
"PDE-system. In this example all conservation laws of the wave"$
terpri()$write
"equation which is written as a first order system are calculated"$
terpri()$write
"such that the characteristic functions of the first of both"$
terpri()$write
"equations is proportional to df(u,x,2). (This will include zero"$
terpri()$write
"as it is a multiple of df(u,x,2) too.)"$
terpri()>>$

comment 
 In the following input the equations are solved for the t-derivatives,
 so the t-derivatives will be substituted in the conservation-law-
 conditions, so the ansatz for q_1 should have no t-derivatives of u
 included. Therefore the function r in q_1 below is specified as
 depending on t,x,u,v,df(u,x),df(v,x). 
 In the call of conlaw2 the list of variables is {t,x} and x is
 the second of the variables (could equally well be in reverse order).
 Therefore df(u,x) takes the form u!`2 when the dependencies of r
 are specified (see CONLAW.TEX). $

nodepnd {u,v,r}$
depend u,x,t$
depend v,x,t$
depend r,t,x,u,v,u!`2,v!`2$
q_1:=r*df(u,x,2)$
conlaw2({{df(u,t)=df(v,x),
          df(v,t)=df(u,x) }, {u,v}, {t,x}},
        {2, 2, t, {r}, {}})$
clear q_1$
nodepnd {q_1}$

lisp<<terpri()$write
"**************************************************************************"$
terpri()$terpri()$write
"For the Burgers equation the following example finds all conservation"$
terpri()$write
"laws of zero'th order in the characteristic function up to the solution"$
terpri()$write
"of the linear heat equation. This is an example for what happens when not"$
terpri()$write
"all conditions could be solved, but it is also an example which shows"$
terpri()$write
"that not only characteristic functions of polynomial or rational form"$
terpri()$write
"can be found."$
terpri()>>$

nodepnd {u}$
depend u,x,t$
conlaw1({{df(u,t)=df(u,x,2)+df(u,x)**2/2}, {u}, {t,x}}, 
        {0, 0, t, {}, {}}                              )$      

lisp <<terpri()$write
"**************************************************************************"$
terpri()$terpri()$write
"In this example all conservation laws of the Ito system are calculated"$
terpri()$write
"that have a conserved density of order not higher than one."$
terpri()$write
"This is a further example of non-polynomial conservation laws."$
terpri()>>$

nodepnd {u,v}$
depend u,x,t$
depend v,x,t$
conlaw1({{df(u,t)=df(u,x,3)+6*u*df(u,x)+2*v*df(v,x),
          df(v,t)=2*df(u,x)*v+2*u*df(v,x)           }, {u,v}, {t,x}},
        {0, 1, t, {}, {}})$

lisp <<terpri()$write
"**************************************************************************"$
terpri()$terpri()$write
"In the next example the 5th order Korteweg - de Vries equation is"$
terpri()$write
"investigated concerning conservation laws of order 0 and 1 in the"$
terpri()$write
"conserved density P_t. Parameters a,b,c in the PDE are determined"$
terpri()$write
"such that conservation laws exist. This complicates the problem by"$
terpri()$write
"making it non-linear with a number of cases to be considered."$
terpri()$write
"Some of the subcases below can be combined to reduce their number"$
terpri()$write
"which currently is not done automatically."$
terpri()>>$

nodepnd {u}$
depend u,x,t$
conlaw1({{df(u,t)=-df(u,x,5)-a*u**2*df(u,x)
                  -b*df(u,x)*df(u,x,2)-c*u*df(u,x,3)}, 
         {u}, {t,x}},
        {0, 1, t, {a,b,c}, {}})$

lisp <<terpri()$write
"**************************************************************************"$
terpri()$terpri()$write
"CONLAWi can also be used to determine first integrals of ODEs."$
terpri()$write
"The generality of the ansatz is not just specified by the order."$
terpri()$write
"For example, the Lorentz system below is a first order system"$
terpri()$write
"therefore any first integrals are zero order expressions."$
terpri()$write
"The ansatz to be investigated below looks for first integrals of"$
terpri()$write
"the form a1(x,1)+a2(y,t)+a3(x,t)=const. and determines parameters"$
terpri()$write
"s,b,r such that first integrals exist."$
terpri()>>$

nodepnd {x,y,z,a1,a2,a3,b,s,r}$
depend x,t$
depend y,t$
depend z,t$
depend a1,x,t$
depend a2,y,t$
depend a3,z,t$

p_t:=a1+a2+a3$
conlaw1({{df(x,t) = - s*x + s*y,
          df(y,t) = x*z + r*x - y,
          df(z,t) = x*y - b*z},
         {x,y,z},{t}
	},
	{0,0,t,{a1,a2,a3,s,r,b},{}})$

clear p_t$
nodepnd {u,v,r,p_t,x,y,z,a1,a2,a3,b,s,r}$

end$
