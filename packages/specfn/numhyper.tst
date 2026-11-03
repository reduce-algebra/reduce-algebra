load_package specfn2;
clear z;
% polynomial cases
p1 := hypergeometric({-6, 3, 2}, {-7, 1, 5}, z);
p2 := hypergeometric({-6, 3}, {7, 1}, z);
p3 :=  hypergeometric({-6, -7, 2}, {-6, 1, 3}, z);
on rounded;
hypergeometric({-6, 3,2}, {-7, 1,5},5);
p1 where z=>5;

hypergeometric({-6, 3}, {7, 1},-3);
p2 where z=> -3;

hypergeometric({-6, -7, 2}, {-6, 1, 3}, 1.1);
p3 where z => 1.1;

% elementary functions
foreach z in {1/3.0, 2/3.0, -2/3.0, 0.9}
   collect (hypergeometric({1,1},{2},z) +log(1-z)/z);

foreach z in {1/3.0, 2/3.0, -2/3.0, 0.9}
   collect (hypergeometric({0.5,0.5},{1.5},z^2)-asin z/z);

foreach z in {1/3.0, 2/3.0, -2/3.0, 0.9}
   collect (hypergeometric({0.5,1},{1.5},-z^2) -atan z/z);

a:= 3$
b:= 2$
foreach z in {1/3.0, 2/3.0, -2/3.0, 0.9}
   collect (hypergeometric({a,b},{a},z) -1/(1-z)^b);

foreach z in {1/3.0, 2/3.0, -2/3.0, 0.9}
   collect (hypergeometric({a,b},{b},z) -1/(1-z)^a);
      
a:= 3$
b:= 6$
foreach z in {1/3.0, 2/3.0, -2/3.0, 0.9}
   collect (hypergeometric({a,b},{a},z) -1/(1-z)^b);

foreach z in {1/3.0, 2/3.0, -2/3.0, 0.9}
   collect (hypergeometric({a,b},{b},z) -1/(1-z)^a);

% complete elliptic integrals
hypergeometric({0.5,0.5},{1}, 0.64) -2*ellipticK(0.8)/pi;
hypergeometric({-0.5,0.5},{1}, 0.81) -2*ellipticE(0.9)/pi;
hypergeometric({0.5,1.5},{2}, 0.64) -4*ellipticD(0.8)/pi;

% Miscellaneous examples compared with Maple results.
% 2F1
hypergeometric({0.5, 0.7},{1.5},0.3);
hypergeometric({0.5, 0.7},{1.5},-0.7);
hypergeometric({0.5, 0.7},{1.5},-2);
hypergeometric({0.5, 0.7},{1.5},1);
hypergeometric({0.5, 0.7},{1.1},-1);
hypergeometric({0.5, 0.7, 0.9},{1.9, 1.5},-1);

hypergeometric({0.5, 0.7},{1.1, 1.2},-1);
hypergeometric({0.5, 0.7},{1.2},-1);
hypergeometric({0.5, 0.7},{0.1, 0.2, 0.3},-1);

hypergeometric({0.5, 0.7, 0.9},{1.9, 1.5, 1, 2}, 1);
hypergeometric({0.5, 0.7},{1.1, 1.2, 1.3},1);
hypergeometric({0.5, 0.7},{0.1, 0.2, 0.3},1);

hypergeometric({0.5, 0.7, 0.9},{1.9, 1.5, 1, 2}, 2);
hypergeometric({0.5, 0.7},{1.1, 1.2, 1.3},-3);
hypergeometric({0.5, 0.7},{0.1, 0.2, 0.3},1);
hypergeometric({0.5, 0.7},{0.1, 0.2, 0.3},2);

;end;

