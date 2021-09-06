% https://doi.org/10.1007/978-3-030-85165-1_18
% 4.1 Triangle Network

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

symbolic operator qesimpl;

symbolic procedure qesimpl(phi, theo);
   begin scalar res, !*rlverbose;
      phi := rl_simp phi;
      theo := for each a in cdr theo collect rl_simp a;
      res := rl_simpl(cl_apply2ats1(phi, function qesimpl1, {theo}), theo, -1);
      return rl_mk!*fof res
   end;

symbolic procedure qesimpl1(at, theo);
   begin scalar w;
      w := rl_qe(rl_all(rl_mk2('impl, rl_smkn('and, theo), at), nil), nil);
      if w eq 'true then
         return 'true;
      w := rl_qe(rl_ex(rl_mkn('and, at . theo), nil), nil);
      if w eq 'false then
         return 'false;
      return at
   end;

off allfac;
on rlnzden;
on rlqeaprecise;
off rlqedfs;
off rlqefbmma;
off rlqefbqepcad;
off rlqefbslfq;
on rlsiexpl;
on rlsiexpla;
on rlqegsd;

kl := {k12, k13, k21, k23, K31, K32}$
xl := {x1, x2}$
fl := {(-2*k12-k13)*x1^2+(2*k21+k23)*x2^2+(k31-k32)*x1*x2}$

pos := for each k in kl collect k > 0$

% Non-emptyness of V_k^*:
phi1 := varietyStarIsNotEmpty(xl, fl, pos);
w := rlqea(phi1, pos);
phi1_ := qesimpl(for each case in w mkor first case, pos);

% Shifted completeness under inverses:
phi2 := varietyStarIsCosetInv(xl, fl, pos);
w := rlqe(phi2, pos);
phi2_ := qesimpl(w, pos);

% Shifted completeness under multiplication:
phi3 := varietyStarIsCosetMult(xl, fl, pos);
w := rlqe(phi3, pos);
phi3_ := qesimpl(w, pos);

coset := rlgsn(phi1_ and phi2_ and phi3_, form=dnf);

phi4 := rlsimpl(sub(for each x in xl collect x=1, zero fl), pos);

group := rlgsn(coset and phi4, form=dnf);

end;
