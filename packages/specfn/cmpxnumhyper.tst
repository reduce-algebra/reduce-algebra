load_package specfn2;
clear z;
off complex,rounded;
% polynomial cases
p1 := hypergeometric({-6, 3, 2}, {-7, 1, 5}, z);
p2 := hypergeometric({-6, 3}, {7, 1}, z);
p3 :=  hypergeometric({-6, -7, 2}, {-6, 1, 3}, z);
on rounded,complex;
hypergeometric({-6, 3,2}, {-7, 1,5},5+i);
p1 where z=>5+i;

hypergeometric({-6, 3}, {7, 1},-3+2i);
p2 where z=> -3+2i;

hypergeometric({-6, -7, 2}, {-6, 1, 3}, 1.1i);
p3 where z => 1.1i;

% elementary functions
(hypergeometric({0.5,0.5},{1.5},z^2)-asin z/z) where z=>0.6i;

(hypergeometric({0.5,1},{1.5},-z^2) -atan z/z) where z=>0.5+0.5i;

(hypergeometric({1,1},{2},z) +log(1-z)/z )where z=> -0.3i;

% Miscellaneous examples compared with Maple results.
% 2F1
hypergeometric({0.5, 0.7},{1.5},1.3);   % value on upper edge of the cut
hypergeometric({0.5, 0.7},{1.5},1.3+0.0000001i);
hypergeometric({0.5, 0.7},{1.5},1.3-0.0000001i);
hypergeometric({0.5, 0.7},{1.5},2.8);  % value on upper edge of the cut
hypergeometric({0.5, 0.7},{1.5},2.8+0.0000001i);
hypergeometric({0.5, 0.7},{1.5},2.8-0.0000001i);
hypergeometric({0.5, 0.7},{1.5},4);  % value on upper edge of the cut 
hypergeometric({0.5, 0.7},{1.5},4+0.0000001i);
hypergeometric({0.5, 0.7},{1.5},4-0.0000001i);
hypergeometric({0.5, 0.7},{1.5},-2i);
hypergeometric({0.5, 0.7},{1.5},1+i);
hypergeometric({0.5, 0.7},{1.2}, 3i);
hypergeometric({0.5i, 1+0.7i},{1.1},1.3); % value on upper edge of the cut
hypergeometric({0.5i, 1+0.7i},{1.1},1.3+0.0000001i); 
hypergeometric({0.5i, 1+0.7i},{1.1},1.3-0.0000001i);
hypergeometric({0.5i, 1+0.7i},{1.1},4); % value on upper edge of the cut
hypergeometric({0.5i, 1+0.7i},{1.1},4+0.0000001i); 
hypergeometric({0.5i, 1+0.7i},{1.1},4-0.0000001i);
hypergeometric({0.5, 0.7},{1.3},-3i);
hypergeometric({0.5i, 0.7i},{1.3},-3i);
hypergeometric({0.5, 0.7},{2},0.6+0.3i);  
hypergeometric({0.5i, 0.7i},{2},0.6+0.3i);
hypergeometric({0.5, 0.7i},{1},1.5i);
% the next 2 succeed if precision is increased to 24
% and agree with Maple
precision 24;
hypergeometric({0.5, 0.7},{2},0.6+0.8i);  % severe rounding at precision 12
hypergeometric({0.5i, 0.7i},{2},0.6+0.8i);  % fails at precision 12
% hypergeometric({0.5, 0.7},{1.5},exp(i*pi/3)); % still fails
% hypergeometric({0.5+i, 0.7-i},{1.9},exp(i*pi/3)); % still fails
precision 12;
hypergeometric({0.5, 0.7},{5.5},exp(i*pi/3));   % OK
hypergeometric({0.5+i, 0.7-i},{5.9},exp(i*pi/3));   % OK

% Other F's
hypergeometric({0.5+i, 1+0.7i, 0.9i},{1.9, 1.5},(1+i)/2);
hypergeometric({0.5, 0.7},{1.1, 1.2},1.5);
hypergeometric({0.5, 0.7},{1.1, 1.2},1.5i); 
hypergeometric({0.5, 0.7},{0.1, 0.2, 0.3},3-4i);
hypergeometric({0.5i, 0.7, 0.9i},{1.9, 1.5i, 1, 2}, 1+2i);
hypergeometric({0.5i, 0.7},{1.1, 1.2i, 1.3},i);
hypergeometric({0.5, 0.7},{0.1, 0.2, 0.3},1);
hypergeometric({0.5+i, 0.7-i, 0.9},{1.9, 1.5, 1}, exp(i*pi/3));
hypergeometric({0.5+i, 0.7-i, 0.9i},{1.9, 1.5, 1}, exp(i*pi/3));

;end;

