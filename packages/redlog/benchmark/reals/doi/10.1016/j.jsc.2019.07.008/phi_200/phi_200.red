off rlabout;

rlset r;

load_package assist;

on ofsfvs;
off rlqefb;

precision(6);

s1 := {
   k1 = 0.02,
   k3 = 0.01,
   k4 = 0.032,
   k7 = 0.045,
   k9 = 0.092,
   k11 = 0.01,
   k12 = 0.01,
   k15 = 0.086,
   k16 = 0.0011}$

s2 := {
   k2 = 1,
   k5 = 1,
   k6 = 15,
   k8 = 1,
   k10 = 1,
   k13 = 1,
   k14 = 0.5}$

sigma := append(s1, s2)$

tau200 := {
   k17 = 100,
   k18 = 50,
   k19 = 200}$

psi :=
   k2*x6 + k15*x11 - k1*x1*x4 - k16*x1*x5 = 0 and
   k3*x6 + k5*x7 + k10*x9 + k13*x10 - x2*x5*(k11 + k12) - k4*x2*x4 = 0 and
   k6*x7 + k8*x8 - k7*x3*x5 = 0 and
   x6*(k2 + k3) + x7*(k5 + k6) - k1*x1*x4 - k4*x2*x4 = 0 and
   k8*x8 + k10*x9 + k13*x10 + k15*x11 - x2*x5*(k11 + k12) - k7*x3*x5 - k16*x1*x5 = 0 and
   k1*x1*x4 - x6*(k2 + k3) = 0 and
   k4*x2*x4 - x7*(k5 + k6) = 0 and
   k7*x3*x5 - x8*(k8 + k9) = 0 and
   k9*x8 - k10*x9 + k11*x2*x5 = 0 and
   k12*x2*x5 - x10*(k13 + k14) = 0 and
   k14*x10 - k15*x11 + k16*x1*x5 = 0 and
   x5 - k17 + x8 + x9 + x10 + x11 = 0 and
   x4 - k18 + x6 + x7 = 0 and
   x1 - k19 + x2 + x3 + x6 + x7 + x8 + x9 + x10 + x11 = 0$

psi200 := sub(append(sigma, tau200), psi);

xl := {{x1, {x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11}},
       {x2, {x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11}},
       {x3, {x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11}},
       {x4, {x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11}},
       {x5, {x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11}},
       {x6, {x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11}},
       {x7, {x2, x11, x10, x9, x8, x7, x6, x5, x4, x3, x1}},
       {x8, {x2, x11, x10, x9, x8, x7, x6, x5, x4, x3, x1}},
       {x9, {x4, x3, x2, x1, x9, x11, x10, x5, x8, x7, x6}},
       {x10, {x5, x9, x8, x7, x2, x6, x11, x10, x4, x3, x1}},
       {x11, {x8, x7, x1, x2, x11, x4, x3, x6, x10, x5, x9}}}$

nu := for i := 1:11 mkand mkid(x, i) > 0;

phi200 := psi200 and nu;

qe_results := for each pr in xl collect
   rlqepcad(rlqe ex(delete(first pr, second pr), phi200), N=256, L=200);

on rlcadextonly;
on rlcadtree2gml;
off rlcadtree2gmlxml;

symbolic emb procedure atree_2gml(tt, filename);
   atree_2gml(tt, "/dev/stdout");

symbolic operator banner;
symbolic procedure banner(vl);
   <<
      terpri();
      ioto_tprin2t {"------------------------------------------------------------------------"};
      ioto_tprin2t {"CAD tree for ", cdr vl};
      ioto_tprin2t {"------------------------------------------------------------------------"};
      nil
   >>;

for each formula in qe_results do <<
   banner rlfvarl formula;
   rlcad formula;
   nil
>>;

column := for each formula in qe_results collect <<
   system := {};
   constraints := true;

   for each at in rlatl formula do
      if part(at, 0) = equal then
         system := cons(part(at, 1), system)
      else
         constraints := constraints and at;

      roots := realroots system;

      valid_roots := {};
      for each root in roots do
         if rlsimpl(sub(root, constraints)) = true then
            valid_roots := cons(root, valid_roots);

      valid_roots
>>$

evalf column;

% Note: Valid roots cannot safely be identified numerically. For the article we used
% external Python tools for extracting them as real algebraic numbers form the CAD trees.

end;
