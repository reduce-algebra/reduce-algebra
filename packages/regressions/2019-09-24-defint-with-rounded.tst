%
% https://sourceforge.net/p/reduce-algebra/discussion/899364/thread/56e6086714/
%
% Definite integration with rounded on does not evaluate properly (pi not replaced by value)
%

on rounded;

% Indefinite integration

int(x*pi,x);

% Definite integration

int(x*pi,x,0,2);

int(int(1, r, 2, 4*sin(3*theta)), theta, pi/18, 5*pi/18);

end;
