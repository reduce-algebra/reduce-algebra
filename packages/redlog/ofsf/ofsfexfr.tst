lisp;

load!-package 'assert;
on1 'assert;
on1 'assertbreak;

load!-package 'redlog;
rl_set '(r);

procedure anu_ivapprox(anu);
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
for each p in res do assert anuiv_ptp p;

fres := for each p in res collect anu_ivapprox cadr p;
assert(length fres = 2);

i1 := car fres;
i2 := cadr fres;

s1 := -7.0;
s2 := 42^(1.0 / 3.0);

assert(car i1 < s1 and s1 < cadr i1);
assert(car i2 < s2 and s2 < cadr i2);

ofsf_ivlprint ofsf_ivlapprox res;

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
for each p in res do assert anuiv_ptp p;

fres := for each p in res collect anu_ivapprox cadr p;
assert(length fres = 2);

i1 := car fres;
i2 := cadr fres;

s1 := 1.41;
s2 := 1.91;

assert(car i1 < s1 and s1 < cadr i1);
assert(car i2 < s2 and s2 < cadr i2);

ofsf_ivlprint ofsf_ivlapprox res;

% TEST 3

setkorder '(x);

g := numr simp xread t;
(x-1)^2*(x-2)^2*(x-3)^2*(x-4)*(x-5)*(x-6)^2;

h := numr simp xread t;
-(2*x - 3)*(2*x - 9);

% al := '(
%    (neq .
%       (((open minf) (open 1.0)) ((open 1.0) (open 2.0)) ((open 2.0) (open 3.0))
%        ((open 3.0) (open 4.0)) ((open 4.0) (open 5.0)) ((open 5.0) (open 6.0))
%        ((open 6.0) (open pinf))))
%    (leq . (((closed 4.0) (closed 5.0))))
%    (geq . (((open minf) (closed 4.0)) ((closed 5.0) (open pinf))))
%    (lessp . (((open 4.0) (open 5.0))))
%    (greaterp .
%       (((open minf) (open 1.0)) ((open 1.0) (open 2.0)) ((open 2.0) (open 3.0))
%        ((open 3.0) (open 4.0)) ((open 5.0) (open 6.0))
%        ((open 6.0) (open pinf)))));

% for each r in '(neq leq geq lessp greaterp) do <<
%    res := ofsf_lit2ivl(r, g, 'x);
%    terpri();
%    ioto_tprin2t r;
%    res := for each iv in res collect
%       ofsf_ivapprox iv;
%    assert(res = cdr atsoc(r, al));
%    for each iv in res do
%       ofsf_ivprint iv
% >>;

tr ofsf_ivcutl;

for each r in '(equal neq leq geq lessp greaterp) do <<
   trl := nil;
   trl := trail_push(declit_mk ofsf_0mk2(r, g), trl);
   trl := trail_push(declit_mk ofsf_0mk2('geq, h), trl);
   prin2t r;
   ofsf_ivlprint ofsf_ivlapprox ofsf_feasible trl;
   terpri()
>>;

end;

% TEST 4

on backtrace;
% tr aex_minus, aex_sgn;
% trst ctx_union;
% trst anu_cmp1;
% trst aex_inv;

setkorder '(y x);

g1 := 'x;
g2 := 'y;

hugo := aex_fromrp ratpoly_fromsf numr simp xread t;
x**2 - 2;

sqrt2 := anu_mk(hugo, iv_mk(rat_fromnum 1, rat_fromnum 2));

hugo := aex_fromrp ratpoly_fromsf numr simp xread t;
y**2 - 3;

sqrt3 := anu_mk(hugo, iv_mk(rat_fromnum 1, rat_fromnum 2));

anu1 := sqrt2;
anu2 := sqrt3;

aex1 := aex_bind(aex_fromrp simp g1, g1, anu1);
aex2 := aex_bind(aex_fromrp simp g2, g2, anu2);
res := aex_minus(aex1, aex2);
res2 := aex_sgn res;
res3 := aex_minus(aex2, aex1);
res4 := aex_sgn res3;

hugo := aex_findroots(g, 'x);
anu_compare(nth(hugo,2), nth(hugo,4));
anu_compare(nth(hugo,4), nth(hugo,2));
anu_compare(nth(hugo,4), nth(hugo,4));


end;
