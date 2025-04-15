% This illustrated the scheme for setting up byte-coded functions by
% giving the sequence of bytes directly. When you use this to define
% a function (eek and foo here) it automatically creates jit!-eek and
% jit!-foo for you to test.

lisp;
on echo;

bytecoded eek a;
   (eek here is some stuff)
   (loadlit2 !:exitlabel exit);

eek 22;
op!-bytes 'jit!-eek;
jit!-eek 22;
op!-bytes 'jit!-eek;
jit!-eek 22;

bytecoded foo(a, b);
   (foo here is some stuff)
   (loadlit 2 !:exitlabel exit);

symbol!-fn!-cell 'foo;
symbol!-env 'foo;

foo(22, 33);

jit!-foo(22, 33);
jit!-foo(22, 33);
jit!-foo(22, 33);

end;
