off rlabout;

% Positive qe:
% Examples from
% Boulier et al. 2007
% http://dx.doi.org/10.1007/978-3-540-73433-8_6
% for n=9 they prove that a Hopf bifurcation exists

rlset r;

ab2007_hopf_n_9 := ex(vv2,ex(vv1,ex(vv3,(( - vv1 < 0 and - vv3 < 0) and
- vv2 < 0) and (((((( gamma0*theta - theta*vv1*vv3**9 - theta*vv1 = 0
and gamma0*mu + lambda1*vv1 - vv2 = 0) and 9*alpha*gamma0 -
9*alpha*vv1*vv3**9 - 9*alpha*vv1 + delta*vv2 - delta*vv3 = 0) and -
9*delta*lambda1*theta*vv1*vv3**8 - delta*theta*vv3**9 - delta*theta < 0
and 6561*alpha**2*vv1**2*vv3**16 + 81*alpha*delta*theta*vv1*vv3 **17 +
81*alpha*delta*theta*vv1*vv3**8 + 162*alpha*delta*vv1*vv3**8 +
162*alpha* theta*vv1*vv3**17 + 162*alpha*theta*vv1*vv3**8 +
81*alpha*vv1*vv3**8 + delta**2* theta*vv3**9 + delta**2*theta + delta**2
- 9*delta*lambda1*theta*vv1*vv3**8 + delta*theta**2*vv3**18 +
2*delta*theta**2*vv3**9 + delta*theta**2 + 2*delta* theta*vv3**9 +
2*delta*theta + delta + theta**2*vv3**18 + 2*theta**2*vv3**9 + theta**2
+ theta*vv3**9 + theta = 0) and - theta < 0) and - gamma0 < 0) and - mu
< 0) and - delta < 0 and - alpha < 0)))$

rlposqe rlex ab2007_hopf_n_9;

end;
