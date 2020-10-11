% Bug report
% https://sourceforge.net/p/reduce-algebra/bugs/127/

load_package sum;

on backtrace;

% 1. This should return factorial(k)
prod(n, n, 1, k);

% 2. The following two should signal "Zero divisor" or some such
prod(1/(n-1), n, 1, k);

prod(m/(n-1), n, 1, k);

% but only the following input shows the error

prod(n/(n-1), n, 1, k);

% 3. The following input used to return
%
% (2**k*prod(n/(2*n - 1),n,1,k))/prod(2*n - 1,n,1,k) 
% 
% which is wrong

prod(2*n/(2*n-1), n, 1, k);

% The nect input should give a closed form (and signal "Zero divisor")

prod(n/(n-1)^2, n, 1, k);

% The following returns prod(n,n,1,k)/(prod(n - 1,n,1,k)*prod(n + 1,n,1,k)) -- smells funny,
prod(n/(n^2-1), n, 1, k);

prod(m*n/(n^2-1), n, 1, k);

prod(n^2/(n^2-1), n, 1, k);

end;
