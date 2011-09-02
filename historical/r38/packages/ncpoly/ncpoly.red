module ncpoly; % Computing in non-commutative polynomial rings and
	       % ideals.

% Author: H. Melenk, ZIB-Berlin, J. Apel, University of Leipzig.

% Copyright: Konrad-Zuse-Zentrum Berlin, 1994

create!-package ('(ncpoly ncenv ncdip ncgroeb ncfactor ncout),
		 '(contrib ncpoly));

fluid '(
 basecount!*
 bcount!*
 b4count!*
 dipvars!*
 factortime!*
 fcount!*
 glterms!*
 groecontcount!*
 groetime!*
 hcount!*
 hzerocount!*
 mcount!*
 nccof!*             % cofactors after a reduction step
 ncdipbase!*         % vector:
                     % the i-th entry is a list (j1,j2...)
                     % where j1,j2 ... < i
                     %    and x_i * x_j neq x_j*x_i
 ncdipcircular!*     % t if one variable appears in more than one
                     % commutator
 ncdiptable!*        % 2-dim array:
                     % then entry (i,j) keeps the powers of the
                     % commutator [x_i,x_j] where j<i
 ncdipvars!*         % variable set
 ncpi!-brackets!*
 ncpi!-comm!-rules!*
 ncpi!-names!*
 ncpi!-name!-rules!*
 nc_factor_time
 nc_factor_time!*
 vdpsortmode!*
 pcount!*
 !*evallhseqp
 !*gsugar
 !*ncg!-right
 !*nc!-traverso!-sloppy
 !*trgroeb
 !*trgroebs
 !*trgroebfull       % print a full trace
 !*trnc
 !*varoptt
 !*vdpinteger
);

global '(glterms);

share ncpi!-brackets!*,ncpi!-comm!-rules!*,ncpi!-name!-rules!*;

load_package dipoly;
load_package groebner;

exports nc_cleanup,nc_compact,left_factor,left_factors,nc_divide,
nc_factorize,nc_factorize_all,nc_groebner,nc_preduce,nc_setup,right_factor,
right_factors;

(if not numberp v or v<2.8
   then rederr "Groebner package version too old")
     where v=get('groebner,'version);

endmodule;;end;
