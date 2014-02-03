lisp;

on1 'assert;
on1 'assertbreak;

rl_set '(r);

%assert_install_all;
%assert_uninstall vsl_substackat;

% TEST 1
% Stack substitution test.

t1 := simp xread t;
x2 + 1;
t2 := simp xread t;
x3 - 4;
term := numr simp xread t;
42*x1 - 4711*x2 + x3 + 654;

formula := ofsf_0mk2('geq, term);
st := {{'x2, t2, 'dummy}, {'x1, t1, 'dummy}};

f := vsl_substack(formula, st);

% TEST 2
% Test vsl_eterm function.

f01 := numr simp xread t$
- 2*x1 - 3*x2 + x3 - 3*x4 + 2*x5 + 3$
f02 := numr simp xread t$
- 2*x1 - 2*x3 + x4 + 2*x5 + 2$
f03 := numr simp xread t$
x1 + 3*x2 - x5 + 2$
f04 := numr simp xread t$
- 3*x1 + 2*x3 - 3*x5 - 2$
f05 := numr simp xread t$
3*x1 - 2*x2 - 2*x4 + x5 - 2$
f06 := numr simp xread t$
2*x1 - x2 - 3*x3 + 2*x4 - 2*x5 + 3$
f07 := numr simp xread t$
2*x1 + 3*x2 + 2*x3 - 2*x4 + 3*x5 + 1$
f08 := numr simp xread t$
2*x1 + x5 + 2$
f09 := numr simp xread t$
- x1 - 3*x2 - x3 + 2*x4 + 3$
f10 := numr simp xread t$
x1 + 3*x2 + x3 - 2*x4 - 3$

infl := {f01, f02, f03, f04, f05, f06, f07, f08, f09, f10}$
vinput := for each f in infl collect
   ofsf_0mk2('geq, f)$
state := vsls_mk(vinput, nil, nil, nil)$

procedure test_eterm(state, x);
   begin scalar eterm, resl;
      vsls_esetput(state, x, vsl_eset(state, x));
      repeat <<
   	 eterm := vsl_eterm(state, x);
	 push(eterm, resl)
      >> until vslse_eoesetp eterm;
      pop resl;
      return {length resl, resl}
   end;

test_eterm(state, 'x1);

% TEST 3
% Test vsl_analyze function.

c1 := numr simp xread t;
(x1-x2+7);
c2 := numr simp xread t;
(x2-5);
c3 := numr simp xread t;
(x1+x2-20);

vsl_analyze({ofsf_0mk2('geq, c1), ofsf_0mk2('geq, c2)}, ofsf_0mk2('geq, c3));

% TEST 4
% Test learning.

algebraic;

on rlverbose$

il := {
   -5*x1 + x2 - 5 >= 0,
   -x1 - 2*x2 >= 0,
   x1 + 3*x2 >= 0,
   5*x1 + x2 >= 0};

on rlvsllearn;
rlvsl il;
off rlvsllearn;
rlvsl il;

on rlvsllearn$
off rlverbose$

% TEST 5
% Test infinity substitutions.

on rlverbose;

hu := {
   x1 + x2 >= 0,
   -x2 + x3 >= 0,
   x3 - 10 >= 0,
   -x3 >= 0};

rlvsl hu;

end;  % of file
