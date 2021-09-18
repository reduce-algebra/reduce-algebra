% https://doi.org/10.1007/978-3-030-85165-1_18
% 4.4 n-site Phosphorylation

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

algebraic procedure rename(vl, fl);
   begin
      integer j;
      scalar sb, xj, xl;
      j := 0;
      xl := sb := {};
      for each v in vl do <<
         j := j + 1;
         xj := mkid(x, j);
         xl := cons(xj, xl);
         sb := cons(v = xj, sb)
      >>;
      return {reverse xl, sub(sb, fl), reverse sb}
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

procedure npho_vectorfield(n);
   begin scalar res, w;
      res := {-k_on0 * s0 * e + k_off0 * c0 + l_cat0 * d1};
      w := for i := 1:n-1 collect <<
         - mkid(k_on, i) * mkid(s, i) * e
         + mkid(k_off, i) * mkid(c, i)
         + mkid(k_cat, i-1) * mkid(c, i-1)
         - mkid(l_on, i-1) * mkid(s, i) * f
         + mkid(l_off, i-1) * mkid(d, i)
         + mkid(l_cat, i) * mkid(d, i+1)
      >>;
      res := append(res, w);
      w := for i := 0:n-1 collect <<
         mkid(k_on, i) * mkid(s, i) * e
         - (mkid(k_off, i) + mkid(k_cat, i)) * mkid(c, i)
      >>;
      res := append(res, w);
      w := for i := 1:n collect <<
         mkid(l_on, i-1) * mkid(s, i) * f
         - (mkid(l_off, i-1) + mkid(l_cat, i-1)) * mkid(d, i)
      >>;
      res := append(res, w);
      return res
   end;

procedure npho_parameters(n);
   begin scalar res, w;
      res := for i := 0:n-1 collect
         mkid(k_on, i);
      w := for i := 0:n-1 collect
         mkid(k_off, i);
      res := append(res, w);
      w := for i := 0:n-1 collect
         mkid(k_cat, i);
      res := append(res, w);
      w := for i := 0:n-1 collect
         mkid(l_on, i);
      res := append(res, w);
      w := for i := 0:n-1 collect
         mkid(l_off, i);
      res := append(res, w);
      w := for i := 0:n-1 collect
         mkid(l_cat, i);
      res := append(res, w);
      return res
   end;

procedure npho_variables(n);
   begin scalar res, w;
      res := for i := 0:n collect
         mkid(s, i);
      w := for i := 0:n-1 collect
         mkid(c, i);
      res := append(res, w);
      w := for i := 1:n collect
         mkid(d, i);
      res := append(res, w);
      res := append(res, {e, f});
      return res
   end;

n := 1;

kl := npho_parameters n;
vl := npho_variables n;
ofl := npho_vectorfield n;

w := rename(vl, ofl)$
xl := first w;
fl := second w;
third w;

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
