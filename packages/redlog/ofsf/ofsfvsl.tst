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
state := vsls_mk(vinput, nil, nil, nil)$

procedure test_eterm(state, x);
   begin scalar eterm, resl;
      vsls_esetput(state, x, vsl_eset(state, x));
      repeat <<
   	 eterm := vsl_eterm(state, x);
	 push(eterm, resl)
      >> until vsl_eoesetp eterm;
      pop resl;
      return {length resl, resl}
   end;

test_eterm(state, 'x1);

% TEST 3
% Test access functions.

vsls_il state;
vsls_setil(state, cdr vsls_il state)$
vsls_il state;

algebraic;

% TEST 4
% Test vsl_vsl.

rlvsl {x1 - 2*x2 >= 0, -x1 + 3*x2 = 0, 5*x1 - x2 <= 0};

on errcont;

rlvsl {x1 <> 0};

off errcont;

% TEST 5
% Algebraic mode test.

f01 :=
- 2*x1 - 3*x2 + x3 - 3*x4 + 2*x5 + 3 >= 0;
f02 :=
- 2*x1 - 2*x3 + x4 + 2*x5 + 2 >= 0;
f03 :=
x1 + 3*x2 - x5 + 2 >= 0;
f04 :=
- 3*x1 + 2*x3 - 3*x5 - 2 >= 0;
f05 :=
3*x1 - 2*x2 - 2*x4 + x5 - 2 >= 0;
f06 :=
2*x1 - x2 - 3*x3 + 2*x4 - 2*x5 + 3 >= 0;
f07 :=
2*x1 + 3*x2 + 2*x3 - 2*x4 + 3*x5 + 1 >= 0;
f08 :=
2*x1 + x5 + 2 >= 0;
f09 :=
- x1 - 3*x2 - x3 + 2*x4 + 3 >= 0;
f10 :=
x1 + 3*x2 + x3 - 2*x4 - 3 >= 0;

rlvsl {f01, f02, f03, f04, f05, f06, f07, f08, f09, f10};

% TEST 6
% Parameter-Free Linear Optimization -
% Example sc50a taken from the ZIB netlib-lp
% ftp://ftp.zib.de/pub/mp-testdata/lp/netlib-lp/

sc50a_c := {
vCOL00001 >= 0,vCOL00002 >= 0,vCOL00003 >= 0,vCOL00004 >= 0,vCOL00005 >= 0,
vCOL00006 >= 0,vCOL00007 >= 0,vCOL00008 >= 0,vCOL00009 >= 0,vCOL00010 >= 0,
vCOL00011 >= 0,vCOL00012 >= 0,vCOL00013 >= 0,vCOL00014 >= 0,vCOL00015 >= 0,
vCOL00016 >= 0,vCOL00017 >= 0,vCOL00018 >= 0,vCOL00019 >= 0,vCOL00020 >= 0,
vCOL00021 >= 0,vCOL00022 >= 0,vCOL00023 >= 0,vCOL00024 >= 0,vCOL00025 >= 0,
vCOL00026 >= 0,vCOL00027 >= 0,vCOL00028 >= 0,vCOL00029 >= 0,vCOL00030 >= 0,
vCOL00031 >= 0,vCOL00032 >= 0,vCOL00033 >= 0,vCOL00034 >= 0,vCOL00035 >= 0,
vCOL00036 >= 0,vCOL00037 >= 0,vCOL00038 >= 0,vCOL00039 >= 0,vCOL00040 >= 0,
vCOL00041 >= 0,vCOL00042 >= 0,vCOL00043 >= 0,vCOL00044 >= 0,vCOL00045 >= 0,
vCOL00046 >= 0,vCOL00047 >= 0,vCOL00048 >= 0,
2*vCOL00001+(1*vCOL00002)+(1.5*vCOL00003) <= 170,
1*vCOL00001+(2*vCOL00002)+(1.5*vCOL00003) <= 130,
1*vCOL00004+(-1*vCOL00005) = 0,
-1*vCOL00001+(1*vCOL00006) = 0,
-1*vCOL00002+(1*vCOL00007) = 0,
-1*vCOL00003+(1*vCOL00008) = 0,
-1*vCOL00006+(1*vCOL00009) <= 0,
-1*vCOL00007+(1*vCOL00010) <= 0,
-1*vCOL00008+(1*vCOL00011) <= 0,
-1*vCOL00009+(2*vCOL00012)+(1*vCOL00013)+(1.5*vCOL00014) <= 170,
-1*vCOL00010+(1*vCOL00012)+(2*vCOL00013)+(1.5*vCOL00014) <= 130,
1*vCOL00005+(-1*vCOL00011) <= 0,
1.1*vCOL00004+(-1*vCOL00015) = 0,
1*vCOL00005+(1*vCOL00015)+(-1*vCOL00016) = 0,
-1*vCOL00006+(-1*vCOL00012)+(1*vCOL00017) = 0,
-1*vCOL00007+(-1*vCOL00013)+(1*vCOL00018) = 0,
-1*vCOL00008+(-1*vCOL00014)+(1*vCOL00019) = 0,
-1*vCOL00017+(1*vCOL00020) <= 0,
-1*vCOL00018+(1*vCOL00021) <= 0,
-1*vCOL00019+(1*vCOL00022) <= 0,
-1*vCOL00020+(2*vCOL00023)+(1*vCOL00024)+(1.5*vCOL00025) <= 170,
-1*vCOL00021+(1*vCOL00023)+(2*vCOL00024)+(1.5*vCOL00025) <= 130,
1*vCOL00016+(-1*vCOL00022) <= 0,
1.1*vCOL00015+(-1*vCOL00026) = 0,
1*vCOL00016+(1*vCOL00026)+(-1*vCOL00027) = 0,
-1*vCOL00017+(-1*vCOL00023)+(1*vCOL00028) = 0,
-1*vCOL00018+(-1*vCOL00024)+(1*vCOL00029) = 0,
-1*vCOL00019+(-1*vCOL00025)+(1*vCOL00030) = 0,
-1*vCOL00028+(1*vCOL00031) <= 0,
-1*vCOL00029+(1*vCOL00032) <= 0,
-1*vCOL00030+(1*vCOL00033) <= 0,
-1*vCOL00031+(2*vCOL00034)+(1*vCOL00035)+(1.5*vCOL00036) <= 170,
-1*vCOL00032+(1*vCOL00034)+(2*vCOL00035)+(1.5*vCOL00036) <= 130,
1*vCOL00027+(-1*vCOL00033) <= 0,
1.1*vCOL00026+(-1*vCOL00037) = 0,
1*vCOL00027+(1*vCOL00037)+(-1*vCOL00038) = 0,
-1*vCOL00028+(-1*vCOL00034)+(1*vCOL00039) = 0,
-1*vCOL00029+(-1*vCOL00035)+(1*vCOL00040) = 0,
-1*vCOL00030+(-1*vCOL00036)+(1*vCOL00041) = 0,
-1*vCOL00039+(1*vCOL00042) <= 0,
-1*vCOL00040+(1*vCOL00043) <= 0,
-1*vCOL00041+(1*vCOL00044) <= 0,
-1*vCOL00042+(2*vCOL00045)+(1*vCOL00046)+(1.5*vCOL00047) <= 170,
-1*vCOL00043+(1*vCOL00045)+(2*vCOL00046)+(1.5*vCOL00047) <= 130,
1*vCOL00038+(-1*vCOL00044) <= 0,
1.1*vCOL00037+(-1*vCOL00048) = 0,
-0.8*vCOL00045+(0.1*vCOL00046)+(0.15*vCOL00047) <= 0,
0.1*vCOL00045+(-0.8*vCOL00046)+(0.15*vCOL00047) <= 0,
-1*vCOL00047+(1*vCOL00048) <= 0}$

on rlverbose;

rlvsl sc50a_c;

end;  % of file
