module ztrans; % Calculation of Z transformation and inverse.

% Authors: Wolfram Koepf, Lisa Temme.
% Version 1.0, April 1995.

% ZTRANS: Z transformation, see
% Bronstein, Semendjajew: Taschenbuch der Mathematik, 4.4.4

create!-package('(ztrans ztrrules),'(contrib misc));

flag('(ztrrules),'lap);

fluid '(!*precise);

!*precise := nil;   % Needed for this module at the moment.

% auxiliary functions


symbolic procedure newrederr(u);
   <<terpri!* t;
     prin2!* "***** ";
     if eqcar(u,'list) then foreach xx in cdr u do newrederr1(xx)
       else  newrederr1 u;
     terpri!* nil; erfg!* := t; error1()>>;

symbolic procedure newrederr1(u);
     if not atom u and atom car u and cdr u and atom cadr u
        and null cddr u
       then <<prin2!* car u; prin2!* " "; prin2!* cadr u>>
      else maprin u;

flag('(newrederr),'opfn);


%********************************************************************

%Ztrans procedure

algebraic operator ztrans_aux;
algebraic operator !~f,!~g,!~summ,binomial;

algebraic procedure ztrans(f,n,z);
 begin
 scalar tmp,!*factor,!*exp;
   off factor;
   tmp := ztrans_aux(f,n,z);
   if part(tmp,0)=ztrans_aux then
     << on factor;
        tmp := ztrans_aux(f,n,z);
        off factor;
     >>;
   if part(tmp,0)=ztrans_aux then 
       return lisp mk!*sq((list((car fkern list('ztrans,f,n,z) . 1)
                                                   . 1)) . 1)
     else return tmp;
 end$

endmodule;

end;
