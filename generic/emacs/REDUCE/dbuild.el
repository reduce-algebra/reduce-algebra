;; Build ESL REDUCE dynamically in main memory without the use of fasl
;; files.  Beware that this file is a mix of Emacs Lisp and REDUCE
;; syntax.  It is based on the REDUCE 3.3 file `dbuild.sl'.

(require 'boot)

;; Load enough modules to run "alg.tst":
(setq MODULES* '(rlisp rend arith mathlib alg1 alg2 ; entry
		  matr hephys)) ; util int solve ezgcd factor rcref
		  ; rsltnt bfloat))

(setq *INT nil)					   ; prevents input buffer being saved

(setq *MSG nil)

(setq *COMP t)

(setq *ARGNOCHK t)

(BEGIN2)
h := open("rlisp.red",'input); rds h;
(BEGIN2)
close h; h := open("eslrend.red",'input); rds h;
(BEGIN2)
close h; for each x in cddr modules!* do infile concat(id2string x,".red");
end;

(makunbound 'H)

;; (load init!-file)

(setq *COMP nil)

(INITREDUCE)
