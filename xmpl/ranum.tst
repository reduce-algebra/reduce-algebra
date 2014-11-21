on ranum;

f := (x**2-2)*x*(x-5);

rl := isolate f;

for each r in rl collect sub(x=r, f);

r1 := refine(part(rl, 1), 10);

on rarat;

r1;

refine(r1, 100);

off rarat;

x1 := ra(f, 1, 2);

off nat;

x1;

on nat;

x2 := ra(f, 4, 10);

isolate f;

x1-3;

x1+1/7;

x1/5;

-x1;

x1 + x2;

1/x1;

x1 - x2;

x1 * x2;

x1^4;

x1**10 - (x1*x1*x1*x1*x1*x1*x1*x1*x1*x1);

wilk := 8388608*x**20 + 1761607681*x**19 + 172931153920*x**18 +
10543221964800*x**17 + 447347234439168*x**16 +
14028108264898560*x**15 + 336985244869591040*x**14 +
6342720331186176000*x**13 + 94877480085669019648*x**12 +
1137370949952460554240 *x**11 + 10968398649699241820160*x**10 +
85079777790228273561600*x**9 + 528740774622641958944768 *x**8 +
2611655889692786813829120*x**7 + 10122095419974470210682880*x**6 +
30198816984091441338777600*x**5 + 67426052557934862488567808*x**4 +
107969196810523545855590400*x**3 + 115794329499468438700032000 *x**2 +
73425049924762651852800000*x + 20408661249006627717120000$

sub(x=x1, wilk);

sub(x=x2, wilk);

isolatingivl wilk;

on rahidepoly;

wrl := isolate wilk;

for each x in wrl collect refine(x, 10);

off rahidepoly;

on errcont;

symbolic ra_wrappertest(6, 42);

symbolic ra_wrappertest(7, 42);

off msg;

ra(f, 1, 10);

ra(f, 1/2, 1);

ra(f, 1, 5);

ra(f, 5, 10);

on msg;

off errcont;

end;
