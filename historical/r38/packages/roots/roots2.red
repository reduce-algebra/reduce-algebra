module roots2; % Header module for roots2 package.

% Author: Stanley L. Kameny <stan_kameny@rand.org>.

% Version and Date:  Mod 1.96, 30 March 1995.

% Copyright (c) 1988,1989,1990,1991,1992,1993,1994,1995.
% Stanley L. Kameny.  All Rights Reserved.

Comment
  Revisions:
  30 March 95  Mod 1.96 adds to multroot the capability of solving
		polynomial trees which are determinate but whose
		structure may lack a stairstep pattern of variables,
		or may contain more polynomials than variables.
		Polynomials can now have denominators, which are
		ignored since only the numerators are used.
		  Spurious small real or imaginary parts of complex
		roots, which can arise due to numeric substitution, are
		now detected and eliminated.  However, vital small real
		or imaginary parts are retained (as in the roots
		program.)
		  Error handling is improved.  Each error now returns
		an error message and then multroot(pr,pl) where pr is
		the precision of answers and pl is the equivalent
		polynomial tree whose processing failed. ;

create!-package ('(roots2 realroot nrstroot multroot),
                 '(contrib roots));

symbolic procedure realroots u; nil; % to fool loader.

% Other packages needed.
load_package roots;

endmodule;

end;
