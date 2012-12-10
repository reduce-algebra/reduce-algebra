lisp;

load!-package 'assert;
on1 'assert;
on1 'assertbreak;

load!-package 'redlog;
rl_set '(r);

procedure anu_approx(anu);
   begin scalar iv;
      iv := anu_iv anu;
      return {float(numr car iv or 0)/float denr car iv,
	 float(numr cdr iv or 0)/float denr cdr iv}
   end;

% TEST 1

setkorder '(x);

f1 := numr simp xread t;
(x**5 - 3)*(x**2 -2)*(x**3 - 42)*(x + 7);

f2 := numr simp xread t;
(x + 100)*(x^19 - 1000);

f2 := multf(f1, f2);

g := numr simp xread t;
x^2 - 3;

trl := trail_push(declit_mk ofsf_0mk2('equal, f1), nil);
trl := trail_push(declit_mk ofsf_0mk2('equal, f2), trl);
trl := trail_push(declit_mk ofsf_0mk2('greaterp, g), trl);

res := ofsf_feasible trl;
assert(length res = 2);

fres := for each anu in res collect anu_approx anu;
i1 := car fres;
i2 := cadr fres;

s1 := -7.0;
s2 := 42^(1.0 / 3.0);

assert(car i1 < s1 and s1 < cadr i1);
assert(car i2 < s2 and s2 < cadr i2);

% TEST 2
% f1 = x^4 - 5 < 0
% f2 = (y^5 - x^3)*(y - x)*(y^3 - 7) = 0
% g = y^3 - 2 > 0
% Trail: f1, x = sqrt 2, f2, g
% f2(sqrt 2) has three roots.
% Their approximations are {y = 1.23114,y = 1.41421,y = 1.91293}.
% Only the last two satisfy g > 0.

setkorder '(y x);

hugo := aex_fromrp ratpoly_fromsf numr simp xread t;
x**2 - 2;

sqrt2 := anu_mk(hugo, iv_mk(rat_fromnum 1, rat_fromnum 2));

f1 := rl_simp xread t;
x^4 - 5 < 0;

f2 := rl_simp xread t;
(y^5 - x^3)*(y - x)*(y^3 - 7) = 0;

g := rl_simp xread t;
y^3 - 2 > 0;

trl := nil;
trl := trail_push(declit_mk f1, trl);
trl := trail_push(varass_mk('x, sqrt2), trl);
trl := trail_push(declit_mk f2, trl);
trl := trail_push(declit_mk g, trl);

res := ofsf_feasible trl;

fres := for each anu in res collect anu_approx anu;

assert(length fres = 2);

i1 := car fres;
i2 := cadr fres;

s1 := 1.41;
s2 := 1.91;

assert(car i1 < s1 and s1 < cadr i1);
assert(car i2 < s2 and s2 < cadr i2);

end;
