%
% Test for error in trigsimp
%  https://sourceforge.net/p/reduce-algebra/bugs/51/
%

1-(sin(pi*x/2))*2;

trigsimp(ws);

trigsimp(ws,cos);

%
% some more failures
%

trigsimp sin(1/2);

trigsimp  sin(x*y/2) ;

trigsimp sin(x^2/2);

trigsimp  sin(1/(2*x));

sin(1/(2*x)) + sin(x/2);

trigsimp ws;

trigsimp (  sin(x/(2*y)) + sin(y/(3*x)));

end;
