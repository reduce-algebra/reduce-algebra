
COMMENT Problem with num_min reported by ACN:
        An invalid accuracy parameter (i.e. not a positivie integer)
        triggered an internal lisp error. Now it is detected and reported correctly;

on backtrace;

num_min(cos x^2 + cos y^2, {x=1, y=2}, accuracy=1.0e-36, iterations=100);

num_min(cos x^2 + cos y^2, {x=1, y=2}, accuracy=36, iterations=100);

end;
