lisp;

% load!-package 'assert;
on1 'assert;
on1 'assertbreak;

rl_set '(r);

assert_install_all;

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
% Example from slides by K. Korovin.

% oo := setkorder '(x);

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
stl := {{'x2, simp 7, 'dummy}};
state := vslstate_mk(vinput, stl, nil, nil)$

procedure test_eterm(state, x);
   begin scalar eterm, resl;
      repeat <<
   	 eterm := vsl_eterm(state, x);
	 push(eterm, resl)
      >> until vsl_eoesetp eterm;
      pop resl;
      return {length resl, resl}
   end;

test_eterm(state, 'x1);

end;  % of file
