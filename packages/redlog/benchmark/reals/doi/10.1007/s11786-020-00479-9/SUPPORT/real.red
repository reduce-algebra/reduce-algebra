% (c) 2019 by T. Sturm (http://science.thomas-sturm.de/)
%
% This software is distributed under CC BY-NC-ND 4.0
% https://creativecommons.org/licenses/by-nc-nd/4.0/legalcode
%
% You are free to: SHARE — copy and redistribute the material in any medium or
% format. The licensor cannot revoke these freedoms as long as you follow the
% following license terms: ATTRIBUTION — You must give appropriate credit,
% provide a link to the license, and indicate if changes were made. You may do
% so in any reasonable manner, but not in any way that suggests the licensor
% endorses you or your use. NON-COMMERCIAL — You may not use the material for
% commercial purposes. NO-DERIVATIVES — If you remix, transform, or build upon
% the material, you may not distribute the modified material.
%
rlset r;
on rlnzden;
off rlqefbmma;
off rlqefbqepcad;
off rlqefbslfq;
off ofsfvs;

off allfac;

switch varietyStarIsCosetEAA;

algebraic procedure classifyComponents(components);
   begin
      scalar WITNESS_VARIETY_STAR, VARIABLES, PROJ_VARIABLES, COSET;
      scalar w, x_in_variety, xl, proj_x_in_variety, proj_xl;
      WITNESS_VARIETY_STAR := {};
      VARIABLES := {};
      PROJ_VARIABLES := {};
      COSET := {};
      for each component in components do <<
          x_in_variety := for each p in component mkand p = 0;
          xl := rlfvarl x_in_variety;
    VARIABLES := cons(xl, VARIABLES);
    w := projectComponent(xl, x_in_variety);
    if first w = {} then <<  % regular case
       w := varietyStarIsCoset(xl, x_in_variety);
       WITNESS_VARIETY_STAR := cons(first w, WITNESS_VARIETY_STAR);
       PROJ_VARIABLES := cons(xl, PROJ_VARIABLES);
       COSET := cons(second w, COSET)
    >> else <<  % projection case
       proj_x_in_variety := second w;
       proj_xl := rlfvarl proj_x_in_variety;
       PROJ_VARIABLES := cons(proj_xl, PROJ_VARIABLES);
       w := varietyStarIsCoset(proj_xl, proj_x_in_variety);
       WITNESS_VARIETY_STAR := cons(first w, WITNESS_VARIETY_STAR);
       COSET := cons(strDowncase second w, COSET)
    >>
      >>;
      COSET := reverse COSET;
      return {
    reverse VARIABLES,
    reverse PROJ_VARIABLES,
    reverse WITNESS_VARIETY_STAR,
    COSET,
    summary COSET}
   end;

procedure summary(l);
   begin scalar gamma, summary, pls; integer c;
      summary := "";
      pls := "";
      for each gamma in {"G", "g", "C", "c", "O", "o", "X", "x"} do <<
          c := for each xx in l sum if strEqual(xx, gamma) then 1 else 0;
          if c neq 0 then <<
            summary := cat {
          summary,
          pls,
          if c neq 1 then symbolic lto_at2str c else "",
          gamma};
            pls := " + "
    >>
      >>;
      return summary
   end;

algebraic procedure projectComponent(xl, x_in_variety);
   begin scalar subs;
      subs := for each x in xl join
    if rlqe all(xl, x_in_variety impl x=0) = true then {x=0} else {};
      return {subs, sub(subs, x_in_variety)}
   end;

algebraic procedure varietyStarIsCoset(xl, x_in_variety);
   begin scalar ne, w;
      ne := varietyStarIsNotEmpty(xl, x_in_variety);
      if first ne = false then
    return {{1=0}, "O"};
      return cons(second ne, varietyStarIsCoset1(xl, x_in_variety))
   end;

algebraic procedure varietyStarIsNotEmpty(xl, x_in_variety);
   if xl = {} then
      {false, {1=0}}
   else
      wrapQea ex(xl, notzero xl and x_in_variety);

algebraic procedure varietyStarIsCoset1(xl, x_in_variety);
   if symbolic !*varietyStarIsCosetEAA then
      varietyStarIsCosetEAA(xl, x_in_variety)
   else
      varietyStarIsCosetAAA(xl, x_in_variety);

algebraic procedure varietyStarIsCosetAAA(xl, x_in_variety);
   % all({g, x, y}, g<>0 and x<>0 and y<>0 and
   %                F(g)=0 and F(g*x)=0 and F(g*y)=0
   %                    impl F(g*x*y)=0 and F(g/x)=0);
   %
   % where all equations and inequalities are component-wise!
   begin
      scalar il, yl, gl, gxl, gxyl, u1, u2, g_in_variety;
      scalar gx_in_variety, gy_in_variety, gxy_in_variety, g_over_x_in_variety;
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
      g_over_x_in_variety := sub(
    for each i in il collect mkid(x, i) = mkid(g, i) / mkid(x, i),
    x_in_variety);
      u1 := rlqe all(gxl,
    notzero gxl and g_in_variety and gx_in_variety
       impl g_over_x_in_variety);
      if u1 = false then
    return {"X"};
      u2 := rlqe all(gxyl,
    notzero gxyl and g_in_variety and gx_in_variety and gy_in_variety
       impl gxy_in_variety);
      if u2 = false then
    return {"X"};
      return {cosetIsGroup(xl, x_in_variety)}
   end;

algebraic procedure varietyStarIsCosetEAA(xl, x_in_variety);
   % ex(g, g<>0 and
   %        all({x, y}, x<>0 and y<>0 and F(g*x)=0 and F(g*y)=0 impl
   %                    F(g*x*y)=0 and F(g/x)=0));
   % where all equations and inequalities are component-wise!
   % Returns false, or {-1, g} where g is the factor of a coset.
   begin
      scalar w, yl, gl, il, u1, u2, is_shifted_toric;
      scalar gx_in_variety, gxy_in_variety, g_over_x_in_variety;
      il := for each x in xl collect getIndex(x, 'x);
      yl := for each i in il collect mkid(y, i);
      xlyl := append(xl, yl);
      gl := for each i in il collect mkid(g, i);
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
      g_over_x_in_variety := sub(
    for each i in il collect mkid(x, i) = mkid(g, i) / mkid(x, i),
    x_in_variety);
      u1 := rlqe all(xl,
    notzero xl and gx_in_variety impl g_over_x_in_variety);
      if u1 = false then
    return {"X", {1=0}};
      u2 := rlqe all(xlyl,
    notzero xlyl and gx_in_variety and gy_in_variety impl
       gxy_in_variety);
      if u2 = false then
    return {"X", {1=0}};
      is_shifted_toric := wrapQea ex(gl, notzero gl and u1 and u2);
      if first is_shifted_toric = false then
    return {"X", second is_shifted_toric};
      if first is_shifted_toric = true then
    return {cosetIsGroup(xl, x_in_variety), second is_shifted_toric};
      sqlExitC("varietyStarIsProperCoset", first is_shifted_toric)
   end;

algebraic procedure cosetIsGroup(xl, x_in_variety);
   % Both coset conditions were true. We have a coset, which is a group iff it
   % contains 1.
   begin scalar is_group;
      is_group := rlsimpl sub(for each x in xl collect x=1, x_in_variety);
      if is_group = true then
    return "G";
      if is_group = false then
    return "C"
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
   for each v in vl  mkand v <> 0;

algebraic procedure positive(vl);
   for each v in vl  mkand v > 0;

algebraic procedure wrapQea(phi);
   begin scalar w;
      on rlqeaprecise;
      w := rlqea phi;
      off rlqeaprecise;
      if w = {} then w := {{false, {}}};
      if first first w = false then <<
    if length w neq 1 then sqlExitC("wrapQea 1", w);
    return {false, {1=0}}
      >>;
      if first first w = true then <<
    if length w neq 1 then sqlExitC("wrapQea 1", w);
    return first w
      >>;
      % Virtual substitution for the outer existential quantifiers did not
      % succeed. Extended QE prevented fallback into CAD. We do this manually
      % now, and will not get a witness. I am assuming here that phi has only
      % existential quantifiers.
      w := rlsimpl for each x in w mkor rlcad first x;
      used_cad_ := 1;
      if w = false then
    return {false, {1=0}};
      if w = true then
          return {true, "failed"};
      sqlExitC("wrapQea 2", w)
   end;

end;
