
COMMENT simple tests of hypergeometric operator;

hypergeometric ({},{},z);

hypergeometric ({1/2,1},{3/2},-x^2);

hypergeometric ({1,1},{2},z);

hypergeometric ({1/2,1/2},{3/2},z^2);

hypergeometric ({1/2,1/2},{3/2},-z^2);

hypergeometric ({a,b},{b},z);

hypergeometric ({a,a+1/2},{1/2},z^2);

hypergeometric ({a,a+1/2},{1/2},-tan(z)^2);

hypergeometric ({a,a+1/2},{3/2},z^2);

hypergeometric ({a,a+1/2},{3/2},-tan(z)^2);


hypergeometric ({-a,a},{1/2},-z^2);

hypergeometric ({-a,a},{1/2},sin(z)^2);

hypergeometric ({-a,a},{3/2},-z^2);

hypergeometric ({-a,a},{3/2},sin(z)^2);

hypergeometric ({a,1-a},{3/2},-z^2);

hypergeometric ({a,1-a},{3/2},sin(z)^2);

hypergeometric ({a,a+1/2},{2*a+1},z);

hypergeometric ({a,a+1/2},{2*a},z);

hypergeometric ({a+1,b},{a},z);

hypergeometric ({a,b},{c},1);

hypergeometric ({a,b},{a-b+1},-1);

hypergeometric ({1,a},{a+1},-1);

hypergeometric ({a,b},{(a+b+1)/2},1/2);

hypergeometric ({a,b},{(a+b)/2+1},1/2);

hypergeometric ({a,1-a},{b},1/2);

df(hypergeometric({a,b},{c},z),z);

hypergeometric ({a,b,c},{a-b+1,a+c-1},1);

hypergeometric ({a,b,c},{a-b+1,a+c-1},z);

hypergeometric ({a,b,c},{(a+b+1)/2,2*c},1);

hypergeometric ({a,1-a,c},{d,2*c-d+1},1);

hypergeometric ({a,b},{a-b+1},-1);

hypergeometric ({1,b},{b+1},-1);

hypergeometric ({2,b},{b+1},-1);

hypergeometric ({a,b},{c,b},z);

% Legendre functions
hypergeometric ({a,b},{2*b},z);



COMMENT simple tests of MeijerG operator;

MeijerG({{},1},{{0}},x);  % should be 1/2(sign( - abs(x) + 1) - sign(abs(x) + 1))

MeijerG({{},a},{{b}},x);

MeijerG({{1}},{{},0},x);  % should be 1-1/2(sign( - abs(x) + 1) - sign(abs(x) + 1))

MeijerG({{a}},{{},b},x);

MeijerG({{}},{{0}},-x);   % exp(x)

MeijerG({{}},{{b}},x);

MeijerG({{a}},{{b}},z);

%MeijerG({{a}},{{b},a-1},z);

%MeijerG({{a}},{{b},2*a-b-1},z);

MeijerG({{a}},{{a-1/2},a-1},z);

MeijerG({{a}},{{a},a-1},z);

MeijerG({{a}},{{a},a-1/2},z);

MeijerG({{a},a+1/2},{{a-1/2}},z);

MeijerG({{a},a+1/2},{{a}},z);

MeijerG({{a},a+1},{{a}},z);

MeijerG({{a},a+1/2},{{a},a-1/2},z);

MeijerG({{a},a},{{a-1/2},a-1/2},z);

MeijerG({{a,a+1/2}},{{a}},z);

MeijerG({{a,a}},{{a}},z);

MeijerG({{a}},{{a,a}},z);


% to force simplification of some sqrt expressions
off precise;

MeijerG({{}},{{0},1/2},x^2/4) * sqrt(pi); % cosine

MeijerG({{}},{{1/2},0},x^2/4) * sqrt(pi);  % sine

% hyperbolic cosine and sine
MeijerG({{}},{{0},1/2},-x^2/4) * sqrt(pi);


MeijerG({{}},{{1/2},0},-x^2/4) * sqrt(pi);


% inverse sine
-i/(2*sqrt(pi)) * MeijerG({{1,1}},{{1/2},0},-x^2);

% inverse tangent
1/2 * MeijerG({{1/2,1}},{{1/2},0},x^2);

% inverse cotangent
1/2 * MeijerG({{1/2},1},{{1/2,0}},x^2);

% inverse hyperbolic sine
MeijerG({{1,1}},{{1/2},0},x^2);

MeijerG({{a,a}},{{a-1/2},a-1},x^2);

MeijerG({{1,1}},{{1},0},x);

MeijerG({{}},{{1+1/4},1-1/4},(x^2)/4) * sqrt pi;

MeijerG({{}},{{b,b+1/2}},z);

%% wrong ??
%%MeijerG({{},a,a},{{a-1,a-1}},z);

%MeijerG({{}},{{b,b+1/3,b+2/3}},z);

end;

