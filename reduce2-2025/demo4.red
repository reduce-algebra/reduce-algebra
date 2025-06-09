(begin)

COMMENT Show conversion from Reduce syntax to raw Lisp. I would tend to
view Reduce as the successful version of "Lisp 2" and its language as
the version of McCarthy's m-notation that has lasted in practical
application! Observe how compact and readable the Reduce code is;

lisp (!*defn := t);

symbolic procedure factorial n;
  for i := 1:n product i^2;

end;