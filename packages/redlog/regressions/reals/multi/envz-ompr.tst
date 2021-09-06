% https://doi.org/10.1007/978-3-030-85165-1_18
% 4.2 Escherichia Coli Osmoregulation System

off rlabout;

rlset r;

algebraic procedure varietyStarIsNotEmpty(xl, sfl, theo);
   rlsimpl(ex(xl, notzero xl and zero sfl), theo);

algebraic procedure varietyStarIsCosetInv(xl, sfl, theo);
   % all({g, x}, g<>0 and x<>0 and y<>0 and F(g)=0 and F(g*x)=0 impl F(g/x)=0);
   begin
      scalar il, gl, gxl, u1in;
      scalar x_in_variety, g_in_variety, gx_in_variety, g_over_x_in_variety;
      x_in_variety := zero sfl;
      il := for each x in xl collect getIndex(x, 'x);
      gl := for each i in il collect mkid(g, i);
      gxl := append(gl, xl);
      g_in_variety := sub(
         for each i in il collect mkid(x, i) = mkid(g, i),
         x_in_variety);
      gx_in_variety := sub(
         for each i in il collect mkid(x, i) = mkid(g, i) * mkid(x, i),
         x_in_variety);
      g_over_x_in_variety := sub(
         for each i in il collect mkid(x, i) = mkid(g, i) / mkid(x, i),
         x_in_variety);
      % Inverse:
      u1in := all(gxl, notzero gxl and g_in_variety and gx_in_variety
         impl g_over_x_in_variety);
      return u1in
   end;

algebraic procedure varietyStarIsCosetMult(xl, sfl, theo);
   % all({g, x, y}, g<>0 and x<>0 and y<>0 and F(g)=0 and F(g*x)=0 and F(g*y)=0 impl F(g*x*y)=0);
   begin
      scalar il, yl, gl, gxl, gxyl, u1, u2, g_in_variety, u1in, u2in;
      scalar x_in_variety, gx_in_variety, gy_in_variety, gxy_in_variety, g_over_x_in_variety;
      x_in_variety := zero sfl;
      il := for each x in xl collect getIndex(x, 'x);
      gl := for each i in il collect mkid(g, i);
      yl := for each i in il collect mkid(y, i);
      gxl := append(gl, xl);
      gxyl := append(gxl, yl);
      g_in_variety := sub(
         for each i in il collect mkid(x, i) = mkid(g, i),
         x_in_variety);
      gx_in_variety := sub(
         for each i in il collect mkid(x, i) = mkid(g, i) * mkid(x, i),
         x_in_variety);
      gy_in_variety := sub(
         for each i in il collect mkid(x, i) = mkid(g, i) * mkid(y, i),
         x_in_variety);
      gxy_in_variety := sub(
         for each i in il collect
            mkid(x, i) = mkid(g, i) * mkid(x, i) * mkid(y, i),
         x_in_variety);
      u2in := all(gxyl, notzero gxyl and g_in_variety and gx_in_variety and
         gy_in_variety impl gxy_in_variety);
      return u2in
   end;

symbolic operator getIndex;

symbolic procedure getIndex(v, base);
   begin scalar w;
      w := explode v;
      for i := 1:length explode base do
         w := cdr w;
      return compress w
   end;

algebraic procedure notzero(vl);
   rlsimpl for each v in vl  mkand v <> 0;

algebraic procedure zero(vl);
   rlsimpl for each v in vl  mkand v = 0;

off allfac;
on rlnzden;
on rlqeaprecise;
off rlqedfs;
off rlqefbmma;
off rlqefbqepcad;
off rlqefbslfq;
on rlsiexpl;
on rlsiexpla;

kl := {k12, k21, k23, k32, k34, k56, k65, k67, k89, k98, k910, k1112, k1211, k1213}$
xl := {x1, x2, x3, x4, x5, x6, x7, x8, x9}$
fl := {
   -k12*x1 + k21*x2 - k1112*x1*x7 + (k1211+k1213)*x9,
   k12*x1 + (-k21-k23)*x2 + k32*x3 + k67*x6,
   k23*x2 + (-k32-k34)*x3 - k89*x3*x7 + (k98+k910)*x8,
   k34*x3 - k56*x4*x5 + k65*x6,
   -k56*x4*x5 + k65*x6 + k910*x8 + k1213*x9,
   k56*x4*x5 + (-k65-k67)*x6,
   k67*x6 - k89*x3*x7 + k98*x8 - k1112*x1*x7 + k1211*x9,
   k89*x3*x7 + (-k98-k910)*x8,
   k1112*x1*x7 + (-k1211-k1213)*x9}$
 
pos := for each k in kl collect k > 0$

% Non-emptyness of V_k^*:
phi1 := varietyStarIsNotEmpty(xl, fl, pos);
w := rlqea(phi1, pos);
phi1_ := rlsimpl(for each case in w mkor first case, pos);
  
% Shifted completeness under inverses:
phi2 := varietyStarIsCosetInv(xl, fl, pos);
phi2_ := rlqe(phi2, pos);

% Shifted completeness under multiplication:
phi3 := varietyStarIsCosetMult(xl, fl, pos);
phi3_ := rlqe(phi3, pos);

coset := rlgsn(phi1_ and phi2_ and phi3_, form=dnf);

phi4 := rlsimpl(sub(for each x in xl collect x=1, zero fl), pos);

group := rlgsn(coset and phi4, form=dnf);

end;
