% tests from: 
%
% Adamchik, V.S. and Marichev, O.I:
% The algorithm for calculating integrals of hypergeometric type
% functions and its realization in REDUCE system,
% presented at ISSAC 1990, Tokyo

load_package specfn2;

MeijerG({{},1},{{0}},x);

MeijerG({{},alpha},{{0}},x);

MeijerG({{alpha}},{{0}},x);

MeijerG({{alpha +1}},{{0}},x);

MeijerG({{0},1/2},{{0},1/2},x) * pi;

MeijerG({{}},{{0}},x);

MeijerG({{1,1}},{{1},0},x);

MeijerG({{1/2,1}},{{1/2},0},x^2) * 1/2;

MeijerG({{1}},{{1/2},0},x^2) * sqrt(pi);

MeijerG({{}},{{1+1/4},1-1/4},(x^2)/4) * sqrt pi;

MeijerG({{}},{{1-1/4},1+1/4},(x^2)/4) * sqrt pi;

MeijerG({{}},{{2/4},0/4},(x^2)/4) * sqrt pi;

MeijerG({{}},{{0/4},2/4},(x^2)/4) * sqrt pi;

MeijerG({{}},{{nu/2},-nu/2},x^2/4);

MeijerG({{}},{{nu/2,-nu/2}},x^2/4) /2;

MeijerG({{0,1/2}},{{(mu+nu)/2,(mu-nu)/2},(nu-mu)/2,-(mu+nu)/2},x^2)*
                sqrt(pi)/2;

MeijerG({{},(1-n)/2,1+n/2},{{0,1/2}},x^2);

MeijerG({{1-a,1-b}},{{0},1-c},x);

end;

