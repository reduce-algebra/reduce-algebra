% Simple correctness tests of f5

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Different ground fields

% Computation in Q[x, y]
f5({x^2*y - 10x + 5, 3y^2 + 4x + 7});

% Computation in Q(a,b,c,d,e)[x, y]
f5({x^2*y - a*x + b, c*y^2 + d*x + e}, {x, y}, lex);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Different term orders

% Without torder:

f5({x + z + y});
% Expected {x + y + z}

f5({x + z + y^2}, {z, y, x}, revgradlex);
% Expected {y^2 + z + x}

% With torder:

torder({z, x, y}, lex);
f5({x + y^2 + z});
% Expected {z + x + y^2}

% Weighted order
torder({x,y,z},weighted,{3, 5, 4});
f5({x + y + z});
% Expected {y + z + x}

% Block order
torder({x, y, z}, lexgradlex, 1);
f5({x + y + z^2});
% Expected {x + z^2 + y}

% Graded order
torder({x, y, z}, graded, {1, 1, 2}, lex);
f5({x + y^4 + z^3});
% Expected {z^3 + y^4 + x}

% and Matrix order;
% Not working currently
% torder({x, y},matrix, mat(
%     (1,0),
%     (0,1)))$
% f5({x + y + z});
% f5({x + y^2 + z^3});

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Different switches combinations: pairwise interactions

% f5interreduce X f5fractionfree
off f5fractionfree;
off f5interreduce;
f5({3x + 5y^2, 2y + 1});
% expected    
%       5   2      1
% {x + ---*y ,y + ---}
%       3          2

f5({a*x + b*y^2, c*y + a^2*d}, {x, y}, lex);
% expected
%                   2
%       b   2      a *d
% {x + ---*y ,y + ------}
%       a           c

on f5interreduce;
f5({3x + 5y^2, 2y + 1});
% expected
%       5        1
% {x + ----,y + ---}
%       12       2

f5({a*x + b*y^2, c*y + a^2*d}, {x, y}, lex);
% expected
%       3    2        2
%      a *b*d        a *d
% {x + ---------,y + ------}
%          2           c
%         c

on f5fractionfree;
f5({3x + 5y^2, 2y + 1});
% expected
% {12*x + 5,2*y + 1}

f5({a*x + b*y^2, c*y + a^2*d}, {x, y}, lex);
% expected
%   2      3    2        2
% {c *x + a *b*d ,c*y + a *d}

off f5interreduce;
f5({3x  + 5y^2, 2y + 1});
% expected
%           2
% {3*x + 5*y ,2*y + 1}

f5({a*x + b*y^2, c*y + a^2*d}, {x, y}, lex);
% expected
%           2        2
% {a*x + b*y ,c*y + a *d}

f5({10*a^5 - 5*a^10*x^2}, {x}, lex);
% expected 
%   5  2
% {a *x  - 2}

f5({a/b*x + c/d}, {x}, lex);
% expected
% {(a*d)*x + b*c}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Parameters & Assumptions

on f5parametric;
on f5fractionfree;
off f5interreduce;

f5({a*x*y^2 - b*x, (b-1)*x^2*y - a^2*x}, {x, y}, lex);

f5dumpAssumptions();
% expected {b - 1 <> 0, b^2 - b <> 0, a <> 0}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Sanity checks

torder({x1}, lex);

f5({3x1});

f5({4x1}, {x1}, lex);

torder({x1, x2}, revgradlex);

f5({x1, x2^2});

f5({x1 + 1, x1});

f5({x2, x1, x1, x1, x2, x2, x1, x2, x1, x2}, {x1, x2}, lex);

f5({x1 + x2, (x1 + x2)^2, (x1 + x2)^3}, {x1, x2}, lex);

f5({x1 + x2, x1*x2 + 1}, {x1, x2}, lex);

f5({x1*x2 + 1, x2*x3 + 1}, {x1, x2, x3}, lex);

f5({x1 + x2 + x3, x1*x2 + x2*x3 + x1*x3, x1*x2*x3 - 1}, {x1, x2, x3}, lex);

f5({10*x1*x2^2 - 11*x1 + 10, 10*x1^2*x2 - 11*x2 + 10}, {x1, x2}, lex);

noon3 := {10*x1*x2^2 + 10*x1*x3^2 - 11*x1 + 10,
          10*x1^2*x2 + 10*x2*x3^2 - 11*x2 + 10,
          10*x1^2*x3 + 10*x2^2*x3 - 11*x3 + 10}$
f5(noon3, {x1, x2, x3}, revgradlex);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% More tests for some combinations of switches

f5({5x1 + x2, x1*x2 + 1}, {x1, x2}, lex);

on f5statistics;
f5({5x1 + x2, x1*x2 + 1}, {x1, x2}, lex);

f5(noon3, {x1, x2, x3}, revgradlex);

f5({x1 + x2, x1*x2 + 100}, {x1, x2}, lex);
f5({4x1 + x2, 1234x1*x2 + 1e5}, {x1, x2}, lex);

off f5statistics;

off f5sugar;
f5({x1 + x2, x1*x2 + 1e10}, {x1, x2}, lex);
f5({x1 + x2, 2347624x1*x2 + 1e100}, {x1, x2}, lex);

on f5sugar;
f5({x1 + x2, x1*x2 + 1e10}, {x1, x2}, lex);
f5({x1 + x2, 2347624x1*x2 + 1e100}, {x1, x2}, lex);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Test from groebner Reduce package

vars := {q1,q2,q3,q4,q5,q6}$
system := {q1,
          q2**2 + q3**2 + q4**2,
          q4*q3*q2,
          q3**2*q2**2 + q4**2*q2**2 + q4**2*q3**2,
          q6**2 + 1/3*q5**2,
          q6**3 - q5**2*q6,
          2*q2**2*q6 - q3**2*q6 - q4**2*q6 + q3**2*q5 - q4**2*q5,
          2*q2**2*q6**2 - q3**2*q6**2 - q4**2*q6**2 - 2*q3**2*q5*q6
          + 2*q4**2*q5*q6 - 2/3*q2**2*q5**2 + 1/3*q3**2*q5**2
          + 1/3*q4**2*q5**2,
          - q3**2*q2**2*q6 - q4**2*q2**2*q6 + 2*q4**2*q3**2*q6 -
          q3**2*q2**2*q5 + q4**2*q2**2*q5,
          - q3**2*q2**2*q6**2 - q4**2*q2**2*q6**2 + 2*q4**2*q3**2*q6**2
          + 2*q3**2*q2**2*q5*q6 - 2*q4**2*q2**2*q5*q6 + 1/3*q3**2*q2**2
          *q5**2 + 1/3*q4**2*q2**2*q5**2 - 2/3*q4**2*q3**2*q5**2,
          - 3*q3**2*q2**4*q5*q6**2 + 3*q4**2*q2**4*q5*q6**2
          + 3*q3**4*q2**2*q5*q6**2 - 3*q4**4*q2**2*q5*q6**2
          - 3*q4**2*q3**4*q5*q6**2 + 3*q4**4*q3**2*q5*q6**2
          + 1/3*q3**2*q2**4*q5**3 - 1/3*q4**2*q2**4*q5**3
          - 1/3*q3**4*q2**2*q5**3 + 1/3*q4**4*q2**2*q5**3 + 1/3*q4**2
            *q3**4*q5**3 - 1/3*q4**4*q3**2*q5**3}$

f5(system, vars, lex);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Tests from Groebner.jl Julia package
%   https://github.com/sumiya11/Groebner.jl

% Root-5
system := {
  x1 + x2 + x3 + x4 + x5,
  x1*x2 + x1*x3 + x1*x4 + x1*x5 + x2*x3 + x2*x4 + x2*x5 + x3*x4 + x3*x5 + x4*x5,
  x1*x2*x3 + x1*x2*x4 + x1*x2*x5 + x1*x3*x4 + x1*x3*x5 + x1*x4*x5 + x2*x3*x4 + x2*x3*x5 + x2*x4*x5 + x3*x4*x5,
  x1*x2*x3*x4 + x1*x2*x3*x5 + x1*x2*x4*x5 + x1*x3*x4*x5 + x2*x3*x4*x5,
  x1*x2*x3*x4*x5 - 1
}$
vars := {x1, x2, x3, x4, x5}$
f5(system, vars, lex);

% Sparse-5
system := {
  x1^2*x2^2*x3^2*x4^2*x5^2 + 3*x1^2 + x1*x2*x3*x4*x5 + x2^2 + x3^2 + x4^2 + x5^2 + 5,
  x1^2*x2^2*x3^2*x4^2*x5^2 + x1^2 + x1*x2*x3*x4*x5 + 3*x2^2 + x3^2 + x4^2 + x5^2 + 5,
  x1^2*x2^2*x3^2*x4^2*x5^2 + x1^2 + x1*x2*x3*x4*x5 + x2^2 + 3*x3^2 + x4^2 + x5^2 + 5,
  x1^2*x2^2*x3^2*x4^2*x5^2 + x1^2 + x1*x2*x3*x4*x5 + x2^2 + x3^2 + 3*x4^2 + x5^2 + 5,
  x1^2*x2^2*x3^2*x4^2*x5^2 + x1^2 + x1*x2*x3*x4*x5 + x2^2 + x3^2 + x4^2 + 3*x5^2 + 5
}$
vars := {x1, x2, x3, x4, x5}$
f5(system, vars, revgradlex);

% Katsura-5
system := {
  x0^2 - x0 + 2*x1^2 + 2*x2^2 + 2*x3^2 + 2*x4^2 + 2*x5^2,
  2*x0*x1 + 2*x1*x2 - x1 + 2*x2*x3 + 2*x3*x4 + 2*x4*x5,
  2*x0*x2 + x1^2 + 2*x1*x3 + 2*x2*x4 - x2 + 2*x3*x5,
  2*x0*x3 + 2*x1*x2 + 2*x1*x4 + 2*x2*x5 - x3,
  2*x0*x4 + 2*x1*x3 + 2*x1*x5 + x2^2 - x4,
  x0 + 2*x1 + 2*x2 + 2*x3 + 2*x4 + 2*x5 - 1
}$
vars := {x0,x1,x2,x3,x4,x5}$
f5(system, vars, revgradlex);

end;  % of file
