;; Lisp code to build a REDUCE image for bootstrapping on Common Lisp
;; FJW, April 2022

(load "sl-on-cl")

;; (unless (sl:getenv "reduce")
;;   ;; No easy way to support setenv in ABCL, so $reduce must be set explicitly!
;;   (cond #-ABCL ((probe-file "./packages") (sl:setenv "reduce" "."))
;;         #-ABCL ((probe-file "../packages") (sl:setenv "reduce" ".."))
;;         (t (format t "~%Error: cannot find packages directory.  Please set $reduce.~2%")
;;            (sl:exit 1))))

#-DEBUG (declaim (optimize speed))
#+DEBUG (declaim (optimize debug safety))
#+SBCL (declaim (sb-ext:muffle-conditions sb-ext:compiler-note style-warning))
#+CLISP (setq custom:*suppress-check-redefinition* t
              custom:*compile-warnings* nil)
#+ABCL (progn
         (require :abcl-contrib)
         (require :asdf-jar) ;; seems to imply (require "asdf")
         ;; Process .asd files in the current directory only.
         (asdf:initialize-source-registry
          `(:source-registry (:directory ,*default-pathname-defaults*)
                             :ignore-inherited-configuration)))

#+CCL
;; (progn
  ;; (require :asdf)
  (setq ccl:*warn-if-redefine* nil
        ccl::*suppress-compiler-warnings* t)
  ;; )

(standard-lisp)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% STANDARD LISP SYNTAX FROM NOW ON! %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(setq !*verboseload t)
(setq !*redefmsg nil)           % Just duplicates CL warnings!

(cl:defparameter !*init!-time!* (time))

(cl:defvar !*argnochk t)
(cl:defvar !*int nil)  % Prevents input buffer being saved.
(cl:defvar !*msg nil)

% Do not use fasl version of "boot.sl": the CL compiler may optimize
% away (i.e. discard) uses of fluid variables that are needed later in
% the build process!

(cond ((filep "boot.sl") (load "boot.sl"))
      ((filep "../psl/boot.sl") (load "../psl/boot.sl"))
      (t (error 0 "Cannot find boot file.") (exit 1)))

(setq !*comp t)  % It's faster in some lisps if we compile.

%%%%%%%%%%%%%%%%%%%%%%%
%% Start of build.sl %%
%%%%%%%%%%%%%%%%%%%%%%%

% The following code is essentially a Standard Lisp version
% of "packages/support/build.red".  It primarily defines the function
% load!-package!-sources, which is required for bootstrapping.

(global '(loaded!-packages!*))

% Since some of the early modules may have tabs in them, we must redefine
% seprp. Note that there is a TAB in this definition and that may not be
% readily visible when merely editing the file.

(de seprp (u) (or (eq u '! ) (eq u '!	) (eq u !$eol!$)))

(de mkfil (u)
   (cond
      ((stringp u) u)
      ((not (idp u)) (typerr u "file name"))
      (t (string!-downcase u))))

% Convert the module u in package directory v, or the current
% directory if v is nil, to a (lower-case) file name relative to the
% directory containing packages.  Also defined in remake.red!

(de module2!-to!-file (u v)
   (progn
      (setq u (concat2 (mkfil u) ".red"))
      (cond
         (v
            (concat2
               "$reduce/packages/"
               (concat2 (mkfil v) (concat2 "/" u))))
         (t u))))

(de inmodule (u v)
   (prog (file)
      (terpri)
      (terpri)
      (prin2 "+++ Reading file: ")
      (prin2 (setq file (module2!-to!-file u v)))
      (terpri)
      (setq u (open file 'input))
      (setq v (rds u))
      (setq cursym!* '!*semicol!*)
      (prog nil
   whilelabel
         (cond ((not (not (eq cursym!* 'end))) (return nil)))
         (progn (prin2 (eval (form (xread nil)))) (prin2 " "))
         (go whilelabel))
      (rds v)
      (close u)))

(de load!-package!-sources (u v)
   (prog (!*int !*echo w)
      (inmodule u v)
      (cond ((setq w (get u 'package)) (setq w (cdr w))))
      (prog nil
   whilelabel
         (cond ((not w) (return nil)))
         (progn (inmodule (car w) v) (setq w (cdr w)))
         (go whilelabel))
      (setq loaded!-packages!* (cons u loaded!-packages!*))))

%%%%%%%%%%%%%%%%%%%%%
%% End of build.sl %%
%%%%%%%%%%%%%%%%%%%%%

(load!-package!-sources 'clprolo nil)
(load!-package!-sources 'revision 'support)
(load!-package!-sources 'rlisp 'rlisp)
(load!-package!-sources 'smacros 'support)
(load!-package!-sources 'clrend nil)
(load!-package!-sources 'poly 'poly)
(load!-package!-sources 'alg 'alg)
(load!-package!-sources 'rtools 'rtools)  % https://sourceforge.net/p/reduce-algebra/code/5845/
(load!-package!-sources 'arith 'arith)
(load!-package!-sources 'entry 'support)
(load!-package!-sources 'remake nil)

(setq !*comp nil)

% (load "compiler")

(prog nil
   (terpri)
   (prin2 "Time to build bootstrap REDUCE: ")
   (prin2 (quotient (difference (time) !*init!-time!*) 1000.0))
   (prin2t " secs")
   (prin2 "Heap left: ")
   (prin2 (gtheap))
   (prin2t " bytes")
)

(initreduce)
(setq date!* (date))
(setq version!* "Bootstrap REDUCE")
(save!-reduce!-image "bootstrap")
