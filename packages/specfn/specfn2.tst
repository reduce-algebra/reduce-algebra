
comment simple tests of hypergeometric operator;

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

% Legendre functions
hypergeometric ({a,b},{2*b},z);


comment simple tests of MeijerG operator;

MeijerG({{},1},{{0}},x);

MeijerG({{}},{{1+1/4},1-1/4},(x^2)/4) * sqrt pi;

end;



