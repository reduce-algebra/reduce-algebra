% Tests of the rataprx package.

% Authors: Lisa Temme, Wolfram Koepf (koepf@zib.de)

% periodic decimal representations
rational2periodic(1/3);
periodic2rational(ws);
rational2periodic(1/7);
periodic2rational(ws);
% previously lost the minus sign
rational2periodic(-1/700);
periodic2rational(ws);
% periodic part has length 34
rational2periodic(1/103);
periodic2rational(ws);
periodic2rational({0},{},{1,2,3,4,5,6,7,8,9});

% hexadecimals
rational2periodic(1/7, 16);
periodic2rational(ws);
rational2periodic(1/13, 16);
periodic2rational(ws);
periodic2rational({0},{},{1,2,3,4,5,6,7,8,9}, 16);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% continued fractions
% of numbers
cf(6/11);        % exact continued fraction result
!*a := cf pi;    % terminates at system precision
cf(pi, 1000);    % sets a bound of 1000 on denominator
cf(pi, 0, 8);    % produces 8 terms in expansion  -- same as cfrac(pi, 8)

% twelve terms of some well known periodic  expansions
cf(sqrt(2), 0, 12);
cfrac(sqrt(3), 12);
cfrac((1+sqrt(5))/2, 12);  % golden ratio

cf(e, 100000);      % denominator bound = 100 000
cf(e, 100000, 8);   % denominator bound = 100 000 or at most 8 terms
cf(e, 1000, 12);    % denominator bound = 1000 or at most 12 terms



% of rational functions
!*b := cfrac((x^5+2)^2/(x^3-5), x);
cfrac((x^5+2)^2/(x^3-5), x, 10);
cfrac((x^5+2)^2/(x^3-5), x, 3);


% of analytic functions
cfrac(e^x, x, 8);
% default order is 5
!*c := cfrac(e^x, x);
!*d := cfrac(x^2/(x-1)*e^x, x);

% not implemented
cfrac(log(x),x,4);
cfrac(asech(x),x,5);
cfrac(sin sqrt x,x,4);

% New operators cf etc. added by A. Barnes
cf_continuents(!*a);
cf_expression(!*a);
cf_convergent(!*a);
cf_convergents(!*a);

% also works with cfrac output
cf_convergent(!*b);
cf_continuents(!*b);
cf_convergents(!*b);

cf_expression !*c;
ps(cf_convergent !*c, x, 0);

cf_expression !*d;
ps(cf_expression !*d, x, 0);
ps(cf_convergent !*d, x, 0);

% more new operators
cf_remove_fractions(cf_euler(e^x, x, 4));
!*a := cf_remove_fractions(cf_euler(4*atan x, x, 4));
!*b := (!*a where x => 1);
!*c := cf(pi, 0, 6);
cf_remove_constant !*c;
!*c:= cf(pi, 0, 8)$
!*d := cf_even_odd !*c;
cf_convergents !*c;
cf_convergents first !*d;
cf_convergents second !*d;

% Pade representations
pade(sin(x),x,0,3,3);
pade(tanh(x),x,0,5,5);
pade(atan(x),x,0,5,5);
pade(1/(x*sin(x)),x,0,3,2);
pade(sin(x)/x^2,x,0,10,1);
pade(sin(x)/x^2,x,0,10,2);
pade(sin(x)/x^2,x,0,10,3);
pade(exp(x),x,0,10,10);
pade(sin(x),x,0,20,20);
% no Pade Approximation exists 
pade(exp(1/x),x,0,5,5);
% wrong order
pade(sin(x)/x^2,x,0,10,0);
% not implemented
pade(factorial(x),x,1,3,3);
% extended Pade representations
pade(asech(x),x,0,3,3);
taylor(ws-asech(x),x,0,10);
pade(sin(sqrt(x)),x,0,3,3);
taylor(ws-sin(sqrt(x)),x,0,10);

end;
