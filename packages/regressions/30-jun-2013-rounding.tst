%
% This is possibly not quite a regression test in that answers are not
% yet "correct" to start with. But it is something that can be run
% using CSL and PSL on native Windows, Cygwin, Linux, MacOSX and other
% platforms to collect information about how Lisp-level floating point
% arithmetic and elementary function libraries behave. In an IDEAL world
% I think that the same results would be generated regardless of platform.
%

lisp;

!#if (memq 'psl lispsystem!*)

symbolic procedure ttab n;
  spaces (n - posn());

!#endif

symbolic procedure show(m, v);
 << prin2 m;
    ttab 20;
    prin2 hexfloat1 v;
    ttab 50;
    print v >>;

<<
terpri();

show("pi",      mypi := 4.0*atan 1.0);
show("sin(pi)", sin mypi);
show("sqrt(2)", sqrt 2.0);
show("2**0.5",  expt(2.0, 0.5));

for i := 1:156 do <<
  x := float i / 100.0;
  m := bldmsg("sin(%w/100)", i);
  show(m, sin x) >>;

>>;

end;
