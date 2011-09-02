% Build checkpointed version of REDUCE.

% (setq !*backtrace t)              % In case anything goes wrong.

(setq prolog_file 'cslprolo)

(setq rend_file 'cslrend)           % CSL specific code.

(load!-module 'compat)

(setq !*comp nil)

(load!-module 'module)              % Definition of load_package, etc.

% (load!-module 'patches)

(load!-module prolog_file)          % CSL specific code.

(setq loaded!-packages!* (list 'compat 'user prolog_file))

(rdf "$reduce/packages/support/mkred2.sl")

(cond ((equal (getenv "MACHINE") "win32")
   (setq plotdir!* (concat (getenv "reduce") "\wutil\win32"))))

(checkpoint 'begin (bldmsg "%w, %w ..." version!* date!*))
