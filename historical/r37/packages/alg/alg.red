module alg;  % Header module for alg package.

% Author: Anthony C. Hearn.

create!-package('(alg alg!-form intro general farith numsup genmod
                  random smallmod zfactor sort reval algbool simp
		  exptchk simplog logsort sub order forall eqn rmsubs
		  algdcl opmtch prep extout depend str coeff weight
		  linop elem showrule nestrad maxmin nssimp part map),
                nil);

flag('(alg),'core_package);

put('alglist!*,'initvalue!*,'(cons nil nil));

% Some renamings so that no user operations in algebraic mode need an
% asterisk.

deflist('((eval_mode !*mode)
	  (cardno!* card_no)
	  (fortwidth!* fort_width)
	  (high_pow hipow!*)
	  (low_pow lowpow!*)
	  (root_multiplicities multiplicities!*)),
	'newnam);

endmodule;

end;
