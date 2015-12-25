
% Test that using the defint package doesn't modify global switches

operator f;

lisp {!*factor,!*exp,!*complex,!*rounded,!*combinelogs};

load_package defint;

lisp {!*factor,!*exp,!*complex,!*rounded,!*combinelogs};

int(f(x),x,a+b,c+d);

lisp {!*factor,!*exp,!*complex,!*rounded,!*combinelogs};

end;
