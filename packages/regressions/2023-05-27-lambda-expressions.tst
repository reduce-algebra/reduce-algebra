on echo;

% LAMBDA was not "supposed" to be used in algebraic mode, but recent
% changes try to provide upgrades to make it work there.

algebraic;

% (1) Free-standing lambda expressions at top level...

(lambda (); 12345);
(lambda x; x+1);
(lambda (x, y); x + y + 1);

% Lambda expressions applied to arguments at the top-level and
% also hidden within expressions.

(lambda x; x+z) 4;
w := (lambda x; x+z) 4;
y + (lambda x; x+z) 4;

% Using via a name

lam := lambda x; x+y+3;
lam z;

% Now some of the same using new syntax

([x] (x+z)) 4;
y + ([] (x+z))();

% Next some examples in symbolic mode.

symbolic;

fluid '(v);
v := 17;

(lambda x; x+1);

(lambda (); 12345) ();
([x] (v*x + 7)) 3;
(lambda (x, y); x + y + v) (4, 5);

% End of tests
end;
