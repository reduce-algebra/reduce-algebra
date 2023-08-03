rlset r;
load_package ranum;
in "ofsftrop.red"$
on rlffi;
on rlgurobi;
on rltropilp;
%on rlverbose;
on rahidepoly;
%%trst ofsf_zeroapprox;
%% tr sfto_fsubq;
%% tr ofsf_zeropLp1int;
%tr sfto_floatsub;
%trst ofsf_zerop3r;
%trst ofsf_zerop1;
%trst ofsf_zerop2;
%tr ofsf_s2aPointPair;
%trst ofsf_zeroapprox;
%% tr ofsf_rdeval;
%% tr ofsf_rdevalat;
%% tr ofsf_evalatp;
%% tr sfto_fsub;
%% tr sfto_fsub1;
%% trst ofsf_posdirp1;

%trst ofsf_tropzeroloop;
trst ofsf_tropzeroinnerloop;

%tr sfto_fsub;

precision 12;

on rlverbose;
on rldebug;

f := -2*x1^6+x1^3*x2-3*x1^3+2*x1*x2^2;

% sol := pzerop(f);

g0 := x1;
g1 := x1+x2-50;
g2 := -x1-x2+50;

ptropzero(f, x1-x2);

end;

ptropzero(f, g0);
ptropzero(f, g1);
ptropzero(f, g2);

end;

on time;
sol := pzerop(f, true, f, {x1=7.67423874,x2=7});

end;

zerosolve(g0, sol);
zeroapprox(g0, sol);

g1 := 2*x1^6+x1^3*x2+3*x1^3+2*x1*x2^2;
sol1 := pzerop g1;

zerosolve(g1, sol1);
zeroapprox(g1, sol1);

sol2 := zerop g1;
zerosolve(g1, sol2);
zeroapprox(g1, sol2);

end;
