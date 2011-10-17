
%
%           r36 -Z -Ifullimage -Ismallr36.img -O- mkred36.lsp
%
% Build final version of REDUCE 3.6 using pre-generated fasl files
%


(load!-module 'compat)

(mapc '(compiler    ccomp
        algint      applysym    arnum       assist      avector
        boolean     cali        camal       cedit       changevr
        compact     crack       crackapp    cvit        defint
        desir       dfpart      dipoly      dummy       excalc
        ezgcd       factor      fide        fide1       fps
        gentran     gnuplot     groebner    groebnr2    hephys
        ideals      ineq        int         invbase     laplace
        lie         linalg      matrix      misc        modsr
        ncpoly      noncom2     normform    numeric     odesolve
        orthovec    physop      pm          pmrules     randpoly
        rcref       reacteqn    reset       residue     rlfi
        rlisp88     roots       roots2      rprint      rsolve
        scope       sets        solve       spde        specbess
        specfaux    specfn      specfn2     symaux      symmetry
        taylor      tps         tri         trigsimp    wu
        xcolor      xideal      zeilberg    ztrans
  ) 'copy!-module)

(setq !*comp nil)

(de rederr (x) (princ "+++ rederr: ") (print x) (error 'rederr))

(de c!:install (name env !&optional checksum !&rest r)
   (progn
      (cond (r nil)
            (t (progn
      (flag (list name) 'lose)
      (cond (env (prog (v n)
         (setq v (mkvect (sub1 (length env))))
         (setq n 0)
    top  (cond
            ((null env) (return (symbol!-set!-env name v))))
         (putv v n (car env))
         (setq n (add1 n))
         (setq env (cdr env))
         (go top)))))))
      name))

(load!-module 'user)                % activate the generated C code
(load!-module 'module)              % Definition of module etc.
(load!-module 'cslprolo)            % CSL-specific code
(global '(patchdate!*))
(setq patchdate!* (modulep 'patches))
(load!-module 'patches)             % Possible patches
(write!-help!-module "../cslsrc/r36.inf" nil)
(load!-module 'makehelp)            % Install the HELP database
(setq loaded!-packages!*
   '(compat user module cslprolo patches))

% It is essential that patches be loaded before rlisp, since patches sets up
% information about the date-stamp of the last patches and rlisp migrates this
% into the variable date!* that is used to create the initial REDUCE banner.

(load!-package 'rlisp)              % RLISP
(load!-package 'cslrend)            % CSL dependent code
(load!-package 'poly)
(load!-package 'alg)                % basic algebra
(load!-package 'arith)
(load!-package 'mathpr)

(load!-package 'fmprint)            % Fancy printing option...
(fmp!-switch nil)                   % ...switched OFF by default

(setq !*comp nil)
(load!-package 'entry)              % entry points for other packages

(initreduce)

(preserve 'begin (bldmsg "%w, %w ..." version!* date!*))


