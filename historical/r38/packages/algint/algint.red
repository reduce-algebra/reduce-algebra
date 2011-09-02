module algint; % Header for REDUCE algebraic integration package.

% Authors: J. Davenport and A. C. Hearn.

create!-package('(algint afactor algfn antisubs coates coatesid findmagc
		  findres finitise fixsubf fracdi genus intbasis jhddiff
		  jhdriver linrel log2atan maninp modify modlineq nagell
                  nbasis places precoats removecm sqfrnorm substns
		  inttaylr torsionb wstrass zmodule),
		  % algnums hidden phantoms primes
		'(int alg));

% Other packages needed.

load!-package 'int;

% Various functions used in the algebraic integrator.

symbolic smacro procedure divsf(u,v); sqrt2top(u ./ v);

symbolic smacro procedure maninp(u,v,w);
   interr "MANINP called -- not implemented in this version";

symbolic smacro procedure readclock; time();

symbolic procedure superprint u; prettyprint u;


% Various selectors written as macros.

symbolic smacro procedure argof u;
   % Argument of a unary function.
   cadr u;

symbolic smacro procedure lsubs u; car u;

symbolic smacro procedure rsubs u; cdr u;

symbolic smacro procedure lfirstsubs u; caar u;

symbolic smacro procedure rfirstsubs u; cdar u;


% Selectors for the Taylor series structure.

% Format is:
%function.((first.last computed so far) . assoc list of computed terms).

% ***store-hack-1***:
% remove this macro if more store is available.

symbolic smacro procedure tayshorten u; nil;

symbolic smacro procedure taylordefn u; car u;

symbolic smacro procedure taylorfunction u; caar u;

symbolic smacro procedure taylornumbers u; cadr u;

symbolic smacro procedure taylorfirst u; caadr u;

symbolic smacro procedure taylorlast u; cdadr u;

symbolic smacro procedure taylorlist u; cddr u;

symbolic smacro procedure taylormake(fn,nums,alist);
   fn . (nums . alist);

endmodule;

end;
