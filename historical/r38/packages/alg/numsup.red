module numsup;   % Numerical support for basic algebra package.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 The RAND Corporation.  All rights reserved.

%  Numerical greatest common divisor.

symbolic procedure gcdn(u,v);
%  U and v are integers. Value is absolute value of gcd of u and v.
   if v = 0 then abs u else gcdn(v,remainder(u,v));


% Interface to rounded code.

% Only needed if package ARITH is autoloaded.

% switch rounded;

% put('rounded,'package!-name,'arith);

% put('rounded,'simpfg,
%             '((t (load!-package 'arith) (setdmode 'rounded t))));
    % Enough for now.

endmodule;

end;
