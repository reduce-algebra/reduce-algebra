load_package redlog;
rlset r;

load_package assert;
on assert;
on assertbreak;
assert_install_all;

lisp;

% TEST 1

oo := setkorder '(x);

ex1_f1 := numr simp xread t;
(x**5 - 3)*(x**2 -2)*(x**3 - 42)*(x + 7);
ex1_f2 := numr simp xread t;
(x**5 - 3)*(x**2 -2)*(x**3 - 42)*(x + 7)*(x + 100)*(x^19 - 1000);
ex1_f3 := numr simp xread t;
x^2 - 3;

ex1_trl := nil;
ex1_trl := trail_push({'rl_declit, nil, ofsf_0mk2('equal, ex1_f1)}, ex1_trl);
ex1_trl := trail_push({'rl_declit, nil, ofsf_0mk2('equal, ex1_f2)}, ex1_trl);
ex1_trl := trail_push({'rl_declit, nil, ofsf_0mk2('greaterp, ex1_f3)}, ex1_trl);


ex1_res := ofsf_feasible ex1_trl;
for each p in ex1_res do assert anuiv_ptp p;

ex1_fres := ofsf_ivlapprox ex1_res;
assert(length ex1_fres = 2);

ex1_i1 := cadr car ex1_fres;
ex1_i2 := cadr cadr ex1_fres;

ex1_s1 := -7.0;
ex1_s2 := 42^(1.0 / 3.0);

assert anu_approxEqualEnough(ex1_i1, ex1_s1);
assert anu_approxEqualEnough(ex1_i2, ex1_s2);

ofsf_ivlprint ex1_fres;

setkorder oo;

% TEST 2
% f1 = x^4 - 5
% f2 = (y^5 - x^3)*(y - x)*(y^3 - 7)
% f3 = y^3 - 2
% Trail: f1 < 0, x := sqrt 2, f2 = 0, f3 > 0
% f2(sqrt 2) has three roots.
% Their approximations are {y = 1.23114, y = 1.41421, y = 1.91293}.
% Only the last two satisfy f3 > 0.

oo := setkorder '(y x);

ex2_hugo := aex_fromrp simp xread t;
x**2 - 2;
ex2_sqrt2 := anu_mk(ex2_hugo, iv_mk(rat_fromnum 1, rat_fromnum 2));

ex2_f1 := numr simp xread t;
x^4 - 5;
ex2_f2 := numr simp xread t;
(y^5 - x^3)*(y - x)*(y^3 - 7);
ex2_f3 := numr simp xread t;
y^3 - 2;

ex2_trl := nil;
ex2_trl := trail_push({'rl_declit, nil, ofsf_0mk2('lessp, ex2_f1)}, ex2_trl);
ex2_trl := trail_push(varass_mk('x, ex2_sqrt2), ex2_trl);
ex2_trl := trail_push({'rl_declit, nil, ofsf_0mk2('equal, ex2_f2)}, ex2_trl);
ex2_trl := trail_push({'rl_declit, nil, ofsf_0mk2('greaterp, ex2_f3)}, ex2_trl);

ex2_res := ofsf_feasible ex2_trl;

for each p in ex2_res do assert anuiv_ptp p;

ex2_fres := ofsf_ivlapprox ex2_res;
assert(length ex2_fres = 2);

ex2_i1 := cadr car ex2_fres;
ex2_i2 := cadr cadr ex2_fres;

ex2_s1 := 1.41;
ex2_s2 := 1.91;

assert anu_approxEqualEnough(ex2_i1, ex2_s1);
assert anu_approxEqualEnough(ex2_i2, ex2_s2);

ofsf_ivlprint ex2_fres;

setkorder oo;

% TEST 3

oo := setkorder '(x);

ex3_f1 := numr simp xread t;
(x-1)^2*(x-2)^2*(x-3)^2*(x-4)*(x-5)*(x-6)^2;
ex3_f2 := numr simp xread t;
-(2*x - 3)*(2*x - 9);

for each op in '(equal neq leq geq lessp greaterp) do <<
   ex3_trl := nil;
   ex3_trl := trail_push({'rl_declit, nil, ofsf_0mk2(op, ex3_f1)}, ex3_trl);
   ex3_trl := trail_push({'rl_declit, nil, ofsf_0mk2('geq, ex3_f2)}, ex3_trl);
   prin2t op;
   ofsf_ivlprint ofsf_ivlapprox ofsf_feasible ex3_trl;
   terpri()
>>;

setkorder oo;

end;
