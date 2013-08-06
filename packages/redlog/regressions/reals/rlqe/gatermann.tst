% Gatermann Mass Action Kinetics
% Highly non-linear.

rlset reals;

gatermann := ex(vv3,ex(vv2,ex(vv1,vv3 > 0 and vv2 > 0 and vv1 > 0 and
(((k21*vv1**2*vv2 - k34*vv1 + k43*vv3 + k46 - k64*vv1 = 0 and -
k21*vv1**2*vv2 + k56 - k65*vv2 = 0) and k34*vv1 - k43*vv3 = 0) and -
k21*k43*k64*vv1**2 + 2*k21*k43*k65*vv1*vv2 - k43*k64*k65 < 0 and
k21**2*k34*vv1**4 - 2*k21**2*k34*vv1**3*vv2 + k21**2*k43*vv1**4 -
4*k21**2*k43*vv1**3*vv2 + 4*k21**2*k43*vv1**2*vv2**2 + k21**2*k64*vv1**4
- 2*k21**2*k64*vv1**3*vv2 - 2*k21**2*k65*vv1**3*vv2 +
4*k21**2*k65*vv1**2*vv2**2 + k21*k34**2*vv1**2 + 2*k21*k34*k43*vv1**2 -
2*k21*k34*k43*vv1*vv2 + 2*k21*k34*k64*vv1**2 + 2*k21*k34*k65*vv1**2 -
4*k21*k34*k65*vv1*vv2 + k21*k43**2*vv1**2 - 2*k21*k43**2*vv1*vv2 +
2*k21*k43*k64*vv1**2 - 4*k21*k43*k64*vv1*vv2 + 2*k21*k43*k65*vv1**2 -
4*k21*k43*k65*vv1*vv2 + k21*k64**2*vv1**2 + 2*k21*k64*k65*vv1**2 -
4*k21*k64*k65*vv1*vv2 - 2*k21*k65**2*vv1*vv2 + k34**2*k65 + k34*k43*k64
+ 2*k34*k43*k65 + 2*k34*k64*k65 + k34*k65**2 + k43**2*k64 + k43**2*k65 +
k43*k64**2 + 2*k43*k64*k65 + k43*k65**2 + k64**2*k65 + k64*k65**2 = 0)
and ((((( - k21 < 0 and - k46 < 0) and - k64 < 0) and - k34 < 0) and -
k43 < 0) and - k56 < 0) and - k65 < 0)))$

rlqe rlex gatermann;

end;
