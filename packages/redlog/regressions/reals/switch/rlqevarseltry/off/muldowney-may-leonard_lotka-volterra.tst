% Muldowney_May_Leonard_LOTKA_VOLTERRA_1_1
% Received from H. Errami/A. Weber, 2010

off rlabout$

rlset r$

informula := ex(vv3,ex(vv2,ex(vv1,vv3 > 0 and vv2 > 0 and vv1 > 0 and b3 > 0 and b2 > 0 and b1 > 0
and a3 > 0 and a2 > 0 and a1 > 0 and max(abs(a2*vv2 - vv2) + abs(b2*vv2 + vv2) + a1*vv2 + a3*vv1 -
b1*vv3 - b3*vv2 - 3*vv1 - 2*vv2 - 3*vv3 + 2,abs(a3*vv3 - vv3) + abs(b3*vv3 + vv3) + a1*vv2 +
a2*vv3 - b1*vv3 - b2*vv1 - 3*vv1 - 3*vv2 - 2*vv3 + 2,abs(a1*vv1 - vv1) + abs(b1*vv1 + vv1) +
a2*vv3 + a3*vv1 - b2*vv1 - b3*vv2 - 2*vv1 - 3*vv2 - 3*vv3 + 2) >= 0))) and ex(vv3,ex(vv2,ex
(vv1,vv3 > 0 and vv2 > 0 and vv1 > 0 and b3 > 0 and b2 > 0 and b1 > 0 and a3 > 0 and a2 > 0 and
a1 > 0 and max(abs(a2*vv2 - vv2) + abs(b2*vv2 + vv2) - a1*vv2 - a3*vv1 + b1*vv3 + b3*vv2 + 3*vv1 +
2*vv2 + 3*vv3 - 2,abs(a3*vv3 - vv3) + abs(b3*vv3 + vv3) - a1*vv2 - a2*vv3 + b1*vv3 + b2*vv1 +
3*vv1 + 3*vv2 + 2*vv3 - 2,abs(a1*vv1 - vv1) + abs(b1*vv1 + vv1) - a2*vv3 - a3*vv1 + b2*vv1 +
b3*vv2 + 2*vv1 + 3*vv2 + 3*vv3 - 2) >= 0))) and ex(vv3,ex(vv2,ex(vv1,vv3 > 0 and vv2 > 0 and vv1 >
0 and b3 > 0 and b2 > 0 and b1 > 0 and a3 > 0 and a2 > 0 and a1 > 0 and max(abs(a1*vv1 - vv1) + abs
(b3*vv3 + vv3) + a1*vv2 + a3*vv1 - b1*vv3 - b3*vv2 - 3*vv1 - 2*vv2 - 3*vv3 + 2,abs(a2*vv2 - vv2) +
abs(b1*vv1 + vv1) + a1*vv2 + a2*vv3 - b1*vv3 - b2*vv1 - 3*vv1 - 3*vv2 - 2*vv3 + 2,abs
(a3*vv3 - vv3) + abs(b2*vv2 + vv2) + a2*vv3 + a3*vv1 - b2*vv1 - b3*vv2 - 2*vv1 - 3*vv2 - 3*vv3 +
2) >= 0))) and ex(vv3,ex(vv2,ex(vv1,vv3 > 0 and vv2 > 0 and vv1 > 0 and b3 > 0 and b2 > 0 and b1 >
0 and a3 > 0 and a2 > 0 and a1 > 0 and max(abs(a1*vv1 - vv1) + abs(b3*vv3 + vv3) - a1*vv2 -
a3*vv1 + b1*vv3 + b3*vv2 + 3*vv1 + 2*vv2 + 3*vv3 - 2,abs(a2*vv2 - vv2) + abs(b1*vv1 + vv1) -
a1*vv2 - a2*vv3 + b1*vv3 + b2*vv1 + 3*vv1 + 3*vv2 + 2*vv3 - 2,abs(a3*vv3 - vv3) + abs
(b2*vv2 + vv2) - a2*vv3 - a3*vv1 + b2*vv1 + b3*vv2 + 2*vv1 + 3*vv2 + 3*vv3 - 2) >= 0)))$

on rlqegsd;
off rlqevarseltry;

informula:= rlposresolve(informula);

rlposqe rlex(informula);

end;
