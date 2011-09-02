off echo, dfprint$                      % FJW

% To run this demo you need liepde.red and crack.red.
% Either read in the files with
%    in "crack"$
%    in "liepde.red"$
% or, to speed up the computation compile them before
%    faslout "crack"$
%    in "crack"$
%    faslend$
%    faslout "liepde"$
%    in "liepde.red"$
%    faslend$
% and then load them with
%    load crack,liepde$
%
lisp(depl!*:=nil)$     % clearing of all dependences
setcrackflags()$
lisp(print_:=nil)$

lisp <<
write"-------------------------------------------------------"$terpri()$
write"The following runs demonstrate the program LIEPDE for the"$terpri()$
write"computation of infinitesimal symmetries. Times given"$terpri()$
write"below refer to a 8 MB session under LINUX on a 133 MHz"$terpri()$
write"Pentium PC with the CRACK version of April 1998."$terpri()$
>>$

lisp(prelim_:=nil)$      % not necessary as this is the default value
lisp(individual_:=nil)$  % not necessary as this is the default value

lisp <<
write"-------------------------------------------------------"$terpri()$
write"The first example is a single ODE with a parametric"$terpri()$
write"function f=f(x) for which point symmetries are to be"$terpri()$
write"determined."$terpri()$
write"(Time ~ 6 sec.)"$terpri()$
write"-------------------------------------------------------"$terpri()$
>>$

lisp(freeint_:=nil)$ % This enables the solution of differential equ.s in
                     % which unevaluated integrals remain. This becomes
                     % necessary in this example through the parametric
                     % function f=f(x)
depend y,x$
depend f,x$
liepde({df(y,x,2)=-(y+3*f)*df(y,x)+y**3-f*y**2-(2*f**2+df(f,x))*y, 
        {y}, {x}},
       {"point"},{})$
nodepnd {y,f}$
lisp(freeint_:=t)$   % Because the simplification of differential
                     % expressions which involve unevaluated integrals
                     % may provide difficulties such solutions involving
                     % unevaluated integrals are disabled.

lisp <<
write"-------------------------------------------------------"$terpri()$
write"The following example demonstrates a number of things."$terpri()$
write"The Burgers equation is investigated concerning third"$terpri()$
write"order symmetries. The equation is used to substitute"$terpri()$
write"df(u,t) and all derivatives of df(u,t). This computation"$terpri()$
write"also shows that any equations that remain unsolved are"$terpri()$
write"returned, like in this case the heat quation."$terpri()$
write"(Time ~ 15 sec.)"$terpri()$
write"-------------------------------------------------------"$terpri()$
>>$

nodepnd {u}$
depend u,t,x$
liepde({df(u,t)=df(u,x,2)+df(u,x)**2,{u},{t,x}},{"general",3},{})$

lisp <<
write"-------------------------------------------------------"$terpri()$
write"Now the same equation is investigated, this time only"$terpri()$
write"df(u,x,2) and its derivatives are substituted. As a"$terpri()$
write"consequence less jet-variables (u-derivatives of lower"$terpri()$
write"order) are generated in the process of formulating the"$terpri()$
write"symmetry conditions. Less jet-variables in which the"$terpri()$
write"conditions have to be fulfilled identically means less"$terpri()$
write"overdetermined conditions and more solutions which to"$terpri()$
write"compute takes longer than before."$terpri()$
write"(Time ~ 85 sec.)"$terpri()$
write"-------------------------------------------------------"$terpri()$
>>$

liepde({df(u,x,2)=df(u,t)-df(u,x)**2,{u},{t,x}},{"general",3},{})$
nodepnd {u}$

lisp <<
write"-------------------------------------------------------"$terpri()$
write"The following example includes the Karpman equations"$terpri()$
write"for three unknown functions in 4 variables. "$terpri()$
terpri()$
write"If point symmetries are to be computed for a single"$terpri()$
write"equation or a system of equations of higher than first"$terpri()$
write"order then there is the option to formulate at first"$terpri()$
write"preliminary conditions for each equation, have CRACK"$terpri()$
write"solving these conditions before the full set of conditions"$terpri()$
write"is formulated and solved. This strategy is adopted if a"$terpri()$
write"lisp flag prelim_ has the value t. The default value"$terpri()$
write"is nil. "$terpri()$
terpri()$
write"Similarly, if a system of equations is to be investigated"$terpri()$
write"and a flag individual_ has the value t then symmetry"$terpri()$
write"conditions are formulated and investigated for each"$terpri()$
write"individual equation successively. The default value is nil."$terpri()$
terpri()$
write"It is advantageous to split a large set of conditions"$terpri()$
write"into smaller sets to be investigated successively if"$terpri()$
write"each set is sufficiently overdetermined to be solvable"$terpri()$
write"quickly. Then any substitutions are done in the smaller"$terpri()$
write"set and the next set of conditions is shorter. For"$terpri()$
write"example, for the Karpman equations below the speedup for"$terpri()$
write"prelim_:=t; individual_:=t; is a factor of 10."$terpri()$
write"(Time ~ 1 min.)"$terpri()$
write"-------------------------------------------------------"$terpri()$
>>$

lisp(prelim_:=t)$
lisp(individual_:=t)$

depend r,x,y,z,t;
depend f,x,y,z,t;
depend v,x,y,z,t;

on time$
liepde({

first 
solve(
        {df(r,t) + w1*df(r,z)
         + s1*(df(r,x)*df(f,x)+df(r,y)*df(f,y)+r*df(f,x,2)/2+r*df(f,y,2)/2) 
         + s2*(df(r,z)*df(f,z)+r*df(f,z,2)/2),
 
         df(f,t) + w1*df(f,z) 
         - (s1*(df(r,x,2)/r+df(r,y,2)/r-df(f,x)**2-df(f,y)**2) +
            s2*(df(r,z,2)/r-df(f,z)**2))/2 + a1*v,
       
         df(v,t,2) - w2**2*(df(v,x,2)+df(v,y,2)+df(v,z,2))
         - 2*a2*r*(df(r,x,2)+df(r,y,2)+df(r,z,2))
         - 2*a2*(df(r,x)**2+df(r,y)**2+df(r,z)**2)},
         
        {df(v,x,2), df(r,x,2), df(f,x,2)}         

     )         
         , {r,f,v}, {x,y,z,t}},

       {"point"}, 
       
       {})$

off time$
nodepnd {r,f,v}$

lisp <<
write"-------------------------------------------------------"$terpri()$
write"In the following example a system of two equations (by"$terpri()$
write"V.Sokolov) is investigated concerning a special ansatz for"$terpri()$
write"4th order symmetries. The ansatz for the symmetries includes"$terpri()$
write"two unknown functions f,g. Because x is the second variable"$terpri()$
write"in the list of variables {t,x}, the name u!`2 stands for"$terpri()$
write"df(u,x)."$terpri()$
write"Because higher order symmetries are investigated we have"$terpri()$
write"to set prelim_:=nil. The symmetries to be calculated are"$terpri()$
write"lengthy and therefore conditions are not very overdetermined."$terpri()$
write"In that case CRACK can take long to solve a single "$terpri()$
write"subset of conditions. The complete set of conditions would"$terpri()$
write"have been more overdetermined and easier to solve. Therefore"$terpri()$
write"the advantage of first formulating all conditions and then"$terpri()$
write"solving them together with one CRACK call is that having"$terpri()$
write"more equations, the chance of finding short integrable"$terpri()$
write"equations among then is higher, i.e. CRACK has more freedom"$terpri()$
write"in optimizing the computation. Therefore individual_:=nil"$terpri()$
write"is more appropriate in this example."$terpri()$
terpri()$
write"Because 4th order conditions are to be computed the"$terpri()$
write"`binding stack size' is increased."$terpri()$
write"(Time ~ 5 min.)"$terpri()$
write"-------------------------------------------------------"$terpri()$
>>$

lisp(prelim_:=nil)$
lisp(individual_:=nil)$
lisp(if getd 'set_bndstk_size then      % FJW -- PSL only!
   set_bndstk_size(7000))$ % 

nodepnd {u,v}$
depend  u,x,t;
depend  v,x,t;

des:={df(u,t)=+df(u,x,2) + (u + v)*df(u,x) + u*df(v,x),
      df(v,t)=-df(v,x,2) + (u + v)*df(v,x) + v*df(u,x)
     }$

nodepnd {f,g}$
depend f,t,x,u,v,u!`2,v!`2,u!`2!`2,v!`2!`2,u!`2!`2!`2,v!`2!`2!`2$
depend g,t,x,u,v,u!`2,v!`2,u!`2!`2,v!`2!`2,u!`2!`2!`2,v!`2!`2!`2$
liepde({des,{u,v},{t,x}},
       {xi_t=0,
        xi_x=0,
        eta_u=+df(u,x,4)+f,
        eta_v=-df(v,x,4)+g
       },
       {f,g}
      )$
nodepnd {f,g}$

end$
