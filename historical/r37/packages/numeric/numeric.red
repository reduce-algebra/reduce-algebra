module numeric;  % Header module for the numeric package and
                 % support of numerical evaluation of symbolic
                 % expressions.

% Author: Herbert Melenk.

% Copyright (c) 1993 ZIB Berlin, RAND.  All rights reserved.

create!-package('(numeric numeval numsolve gauss newton steepstd 
                  bounds numint numfit chebysh rungeku),
		'(contrib numeric));

fluid '(!*noequiv);
fluid '(accuracy!*);
global '(iterations!* !*trnumeric);
switch trnumeric;

% Create .. as infix operator.

newtok '( (!. !.) !*interval!*);

if null get('!*interval!*,'simpfn) then
<<precedence .., or;
  algebraic operator ..;
  put('!*interval!*,'prtch,'! !.!.! );
>>;

% some common utilities

fluid '(minus!-infinity!*);

minus!-infinity!* := '(minus infinity);

% intervals

symbolic procedure adomainp u;
   numberp u or (pairp u and idp car u and get(car u,'dname));

symbolic procedure revalnuminterval(u,num);
 % Evaluate u as interval; numeric bounds required if num=T.
  begin scalar l;
    if not eqcar(u,'!*interval!*) then typerr(u,"interval");
    l:={reval cadr u,reval caddr u};
    if adomainpx(car l,num) and adomainpx(cadr l,num)then return l;
    typerr(u,"numeric interval");
  end;

symbolic procedure adomainpx(u,num);
  % extended algebraic domainp test:
  % num = t: u is a domain element;
  % num = inf: u is a domain element or inf or (minus inf)
  % num = nil: u is arbitrary.
    null num or adomainp u or num='infinity 
                and member(u,'(infinity (minus infinity)));
 
symbolic procedure evalgreaterpx(a,b);
  if a =minus!-infinity!* or b = 'infinity then nil else
  a='infinity or b=minus!-infinity!* or evalgreaterp(a,b);

symbolic procedure mkinterval(u,v);
   list('!*interval!*,u,v);

% Easy coding of numerical procedures with REDUCE:
%
%  In statements or procedure bodies tagged with "dm:" all 
%  arithmetic function calls are replaced by REDUCE domain 
%  arithmetic.

symbolic macro procedure dm!: u;
  subla('((plus2 . !:plus)(times2 . !:times)
          (plus . !:plusn)(times . !:timesn)
          (quotient . !:!:quotient)
          (difference . !:difference)
          (minus . !:minus)
          (minusp . !:minusp)
          (zerop . !:zerop)
          (lessp . (lambda(a b)(!:minusp (!:difference a b))))
          (greaterp . (lambda(a b)(!:minusp (!:difference b a))))
          (leq . (lambda(a b)(not (!:minusp (!:difference b a)))))
          (geq . (lambda(a b)(not (!:minusp (!:difference a b)))))
          (sqrt . num!-sqrtf)
          (abs . absf)
          (min2 . dm!:min)
          (max2 . dm!:max)
          (min . dm!:min)
          (max . dm!:max)
         ) , cadr u);

%wrappers for n-ary plus and times

symbolic macro procedure !:plusn u;
  if null cddr u then cadr u else
   list('!:plus,cadr u,'!:plusn . cddr u);

symbolic macro procedure !:timesn u;
  if null cddr u then cadr u else
   list('!:times,cadr u,'!:timesn . cddr u);

endmodule;

end;
