
#if (member 'psl lispsystem!*)
linelength 5000$
load_package tmprint$
#endif

on fancy;

operator f;
share y1,y2,y3,y4;

x1 := (a+b+c)/2;
x2 := binomial(a+b/2,n);
x3 := int(f(x),x,a+b,c+d);
x4 := sum(f(x),x,a+b,c+d);
x5 := df(f(x+a),x);
x6 := BesselJ(a+b,x);
x7 := texsym(stackrel,f(a+b),texsym(longrightarrow));
x8 := hypergeometric({},{1,2},-z);
x9 := MeijerG({{}},{{b,b+1/3,b+2/3}},z);

% Expressions that simplify and must therefore be built by hand

lisp <<
  y1 := '(!*sq (((((limit (f x) x (plus a b)) . 1) . 1)) . 1) t);
  y2 := '(!*sq (((((hypergeometric (list 1 -22) (list) (minus z)) . 1) . 1)) . 1) t);
  y3 := '(!*sq (((((meijerg (list (list)) (list (list b (plus b 1) (plus b 2))) z) . 1) . 1)) . 1) t);
  y4 := '(!*sq (((((meijerg (list (list b (plus b 1) (plus b 2))) (list (list)) z) . 1) . 1)) . 1) t);
>>$
y1;
y2;
y3;
y4;

on list;

x1;
x2;
x3;
x4;
x5;
x6;
x7;
x8;
x9;
y1;
y2;
y3;
y4;

off fancy;

end;
