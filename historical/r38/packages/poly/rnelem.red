module rnelem;

fluid '(!*rounded);

% This module adds 10 integer functions to mode rational.

deflist('((fix rnfix!*) (round rnround!*)
  (ceiling rnceiling!*) (floor rnfloor!*) % (isqrt rnisqrt!*)
% (icbrt rnicbrt!*) (irootn rnirootn!*) (ilog2 rnilog2!*) (sgn rnsgn!*)
  (factorial rnfactorial!*) (perm rnperm!*) (choose rnchoose!*))
  ,'!:rn!:);

for each c in '(fix round ceiling floor % isqrt icbrt irootn ilog2 sgn
 factorial perm choose) do put(c,'simpfn,'simpiden);

flag('(fix floor ceiling round isqrt icbrt irootn ilog2 factorial % sgn
 perm choose) ,'integer);

deflist('((perm 2) (choose 2)),'number!-of!-args);

symbolic procedure rnfix!* x; quotient(cadr x,cddr x);

symbolic procedure rnfixchk x;
   (if cdr y=0 then car y
    else error(0,list(prepf x,"is not an integer equivalent")))
   where y=divide(cadr x,cddr x);

% symbolic procedure rnsgn!* x; sgn cadr x;

symbolic procedure rnfloor!* x;
   if cdr(x := divide(cadr x,cddr x))<0 then car x-1 else car x;

symbolic procedure rnceiling!* x;
   if cdr(x := divide(cadr x,cddr x))>0 then car x+1 else car x;

symbolic procedure rnround!* x;
   (if cadr rndifference!:(x,!*i2rn y)=0 then y
    else if rnminusp!: x then -rnround!*('!:rn!: . ((-cadr x) . cddr x))
    else rnfloor!*(rnplus!:(x,'!:rn!: . (1 . 2)))) where y=rnfix!* x;

% symbolic procedure rnisqrt!* x; isqrt rnfix!* x;

symbolic procedure rnilog2!* x; ilog2 rnfix!* x;

symbolic procedure rnfactorial!* x;
   (if fixp y and not(y<0) then nfactorial y
    else !*p2f mksp(list('factorial,y),1))
    where y=rnfixchk x;

symbolic procedure rnperm!*(x,n); perm(rnfixchk x,rnfixchk n);

symbolic procedure perm(x,n);
   if not fixp x or not fixp n or x<0 or x>n
      then terrlst(list(x,n),'perm) else for j := n-x+1:n product j;

symbolic procedure rnchoose!*(x,n); choose(rnfixchk x,rnfixchk n);

symbolic procedure choose(x,n); perm(x,n)/factorial x;

symbolic procedure simprn x;
   begin scalar !*rounded,dmode!*;
      dmode!* := '!:rn!:;
      return for each a in simplist x collect
	 if atom a then !*i2rn a else a
   end;

% symbolic procedure rnicbrt!* x; icbrt rnfix!* x;

symbolic procedure rnirootn!*(x,n); irootn(rnfix!* x,rnfixchk n);


endmodule;

end;
