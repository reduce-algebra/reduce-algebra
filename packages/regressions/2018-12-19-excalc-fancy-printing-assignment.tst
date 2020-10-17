
Comment Bug report #90.
  https://sourceforge.net/p/reduce-algebra/bugs/90/
$

#if (and (not (member 'tmprint loaded!-packages!*)) (not (getd 'linelength!-orig)))
%#if (not (member 'tmprint loaded!-packages!*))
load_package tmprint$
linelength 5000$
#endif

on fancy;

load_package "excalc"$
coframe e theta = r * d theta, e phi = r * sin(theta) * d phi$
riemannconx om$
write "Display the connection forms";
on fancy;
om(k,-l);

off fancy;
end;
