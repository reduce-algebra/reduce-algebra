module ncpoly; % Computing in non-commutative polynomial rings and
	       % ideals.

% Author: H. Melenk, ZIB-Berlin, J. Apel, University of Leipzig.

% Copyright: Konrad-Zuse-Zentrum Berlin, 1994

create!-package ('(ncpoly ncenv ncdip ncgroeb ncfactor ncout),
		 '(contrib ncpoly));

fluid '(ncpi!-brackets!* ncpi!-comm!-rules!* ncpi!-name!-rules!*
	ncpi!-names!*);

share ncpi!-brackets!*,ncpi!-comm!-rules!*,ncpi!-name!-rules!*;

load_package dipoly;
load_package groebner;

(if not numberp v or v<2.8
   then rederr "Groebner package version too old")
     where v=get('groebner,'version);

endmodule;

end;
