% dbuild2.sl --- Lisp-version independent code for "in core" build.

% Author:  Anthony C. Hearn.

(setq !*argnochk t)

(setq !*int nil)                    % Prevents input buffer being saved.

(setq !*msg nil)

(setq !*comp t)               % It's faster if we compile the boot file.

(rdf "$reduce/psl/boot.sl")

(begin2)

rds(xxx := open("$reduce/packages/support/build.red",'input));

(close xxx)

(load!-package!-sources prolog_file 'support)

(load!-package!-sources 'rlisp 'rlisp)

(load!-package!-sources rend_file 'support)

(load!-package!-sources 'poly 'poly)

(load!-package!-sources 'alg 'alg)

(load!-package!-sources 'arith 'arith)  %  Needed by roots, specfn*, (psl).

(load!-package!-sources 'entry 'support)

(load!-package!-sources 'remake 'support)

(setq !*comp nil)

(rds oldchan2!*)
