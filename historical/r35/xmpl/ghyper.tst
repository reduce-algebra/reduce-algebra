% Test cases for hypergeometric functions

% from Wolfram Koepf: Power Series in Computer Algebra
%                       J. Symbolic Computation 13, (1992)

load_package specfn2;

hypergeometric({-alpha},{},x);

hypergeometric({},{},x);

x * hypergeometric({1,1},{2},x);

x * hypergeometric({},{3/2},-x^2/4);

hypergeometric({},{1/2},-x^2/4);     

x * hypergeometric({},{3/2},x^2/4);     

hypergeometric({},{1/2},x^2/4);     

x * hypergeometric({1/2,1/2},{3/2},x^2);     

x * hypergeometric({1/2,1},{3/2},-x^2);     

x * hypergeometric({1/2,1/2},{3/2},-x^2);     

x * hypergeometric({1/2,1},{3/2},x^2);     

% another example which shows the polynomial case:

hypergeometric({12,12/34},{3},x);

% Some more (nontrivial) examples from
% Graham, Knuth, Ptashnik: Concrete Mathematics
% Addison-Wesley Publishing Company, 1989

HYPERGEOMETRIC({a,b,-n},{c,a+b-c-n+1},1);

% is known for integers though

hypergeometric({a,b,-4},{c,a+b-c-4+1},z);

hypergeometric({1-c-2n,-2n},{c},1);

hypergeometric({a,b},{1+b-a},-1); % Kummer's formula (z=1)

hypergeometric({a,b},{c},1);

end;

