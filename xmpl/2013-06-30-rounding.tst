%
% CSL is moving to use an underlying maths library called "crlibm",
% for "Correctly Rounded libm". This is supposed to deliver correctly
% rounded double-precision results for the basic elementary functions
% sin, cos, exp and log (and a few others) on any machine that uses IEEE
% floating point. And these days I expect that to be universal. Since the
% results are "correct" they should be identical on all platforms - and that
% is something that has not been the case hithertoo.
%
% If these results are "perfect" then they are ones that the PSL system
% could also aspire too.

% 
% In this test I will just exercise sin(x) for x in the first quadrant.
%

lisp;

!#if (memq 'psl lispsystem!*)

symbolic procedure ttab n;
  spaces (n - posn())$

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
