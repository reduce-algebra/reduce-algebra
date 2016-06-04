% Natural Numbers as Elements of a Term Algebra

rlset(talp, {o, 0}, {s, 1});

nn1 := all(x, ex(y, y=s(x)));

rlqe nn1;

% The successor of each natural number is unique:

nn2 := all(x, y=s(x) and z=s(x) impl y=z);

rlqe nn2;

rlqe rlall ws;

% Disprove that every natural number is a successor:

nn3 := all(x, ex(y, x=s(y)));

rlqe nn3;

rlqea nn3;

% Binary Trees as Term Algebras.

rlset(talp, {o, 0}, {l, 1}, {r, 1});

bt1 := all(x, ex({y, z}, y=l(x) and z=r(x)));

rlqe bt1;

bt2 := all(x, u=l(x) and v=l(x) and y=r(x) and z=r(x) impl u=v and y=z);

rlqe bt2;

bt3 := all(x, ex({y, z}, x=l(y) or x=r(z)));

rlqe bt3;

rlqea bt3;

% Hoffelner's Artificial Parametric Problems

rlset(talp, {a, 0}, {f, 1}, {g, 2});

pp1 := ex({x, y}, g(x, f(y))=g(u, x));

rlqe pp1;

rlqea pp1;

pp2 := rlsimpl pp1;

rlset(talp, {a, 0}, {f, 1});

rlqe pp2;

rlset(talp, {a, 0}, {f, 1}, {g, 2});

pp3 := ex({x, y, z}, x=u and y=a and z<>x);

rlqe pp3;

rlqea pp3;

end;
