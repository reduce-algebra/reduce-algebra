% "buildreduce.lsp"                        Copyright (C) Codemist 2016-2017
%
% Build a CSL REDUCE.
%
% Depending on how this file is used it will EITHER create a bootstrap
% version of REDUCE or a full and optimised one.
%
% The behaviour is determined by whether the version of CSL used to
% run it has a full complement of functions in the modules u01.c to u60.c.
%
%
%           bootstrapreduce -z buildreduce.lsp -D@srcdir=<DIR> -D@reduce=<DIR>
%
% Builds a system "bootstrapreduce.img" that does not depend on any
% custom C code. The main use of this slow system is for profiling
% REDUCE and then compiling the hot-spots into C. Once that has been
% done this image is logically unnecessary.
%
%
%           reduce -z buildreduce.lsp -D@srcdir=<DIR> -D@reduce=<dir>
%
% Here the files u01.c to u60.c and u01.lsp to u60.lsp must already
% have been created, and that the reduce executable has them compiled in.
% The REDUCE source files that are compiled *MUST* be the same as those used
% to create this C code.

% Author: Anthony C. Hearn, Stanley L. Kameny and Arthur Norman

% $Id$

(verbos 3)

(window!-heading "basic CSL")

(make!-special '!*savedef)
(make!-special '!*backtrace)

(setq !*savedef (and (not (memq 'embedded lispsystem!*))
                     (zerop (cdr (assoc 'c!-code lispsystem!*)))))

(make!-special '!*noinlines)
(prog (w)
   (setq w (errorset 'noinlines nil nil))
   (setq !*noinlines (and (not (atom w)) (car w)))
   (print (list '!*noinlines 'set 'to !*noinlines)))

% A command-line flag "-g" sets the variable !*backtrace and so can activate
% this. But beware that otherwise !*backtrace may be an unset variable, and
% so I use an errorset to protect myself.

(prog (w)
   (setq w (errorset '!*backtrace nil nil))
   (cond
      ((or (atom w) (null (car w))) (setq !*backtrace nil))
      (t (enable!-errorset 3 3))))

(cond
   (!*backtrace (setq !*echo t)))

(make!-special '!*native_code)
(setq !*native_code nil)

(cond ((and (null !*savedef)
       (null (memq 'jlisp lispsystem!*))
       (null (memq 'embedded lispsystem!*))) (progn

   (de c!:install (name env c!-version !&optional c1)
      (cond
        (c1 (check!-c!-code name env c!-version c1))
        (t (progn
              (put name 'c!-version c!-version)
              (cond (env (prog (v n)
                 (setq v (mkvect (sub1 (length env))))
                 (setq n 0)
            top  (cond
                    ((null env) (progn
                     (put name 'funarg v)
                     (return (symbol!-set!-env name v)))))
                 (putv v n (car env))
                 (setq n (add1 n))
                 (setq env (cdr env))
                 (go top))))
              name))))

   (rdf "$reduce/cslbuild/generated-c/u01.lsp")
   (rdf "$reduce/cslbuild/generated-c/u02.lsp")
   (rdf "$reduce/cslbuild/generated-c/u03.lsp")
   (rdf "$reduce/cslbuild/generated-c/u04.lsp")
   (rdf "$reduce/cslbuild/generated-c/u05.lsp")
   (rdf "$reduce/cslbuild/generated-c/u06.lsp")
   (rdf "$reduce/cslbuild/generated-c/u07.lsp")
   (rdf "$reduce/cslbuild/generated-c/u08.lsp")
   (rdf "$reduce/cslbuild/generated-c/u09.lsp")
   (rdf "$reduce/cslbuild/generated-c/u10.lsp")
   (rdf "$reduce/cslbuild/generated-c/u11.lsp")
   (rdf "$reduce/cslbuild/generated-c/u12.lsp")
   (rdf "$reduce/cslbuild/generated-c/u13.lsp")
   (rdf "$reduce/cslbuild/generated-c/u14.lsp")
   (rdf "$reduce/cslbuild/generated-c/u15.lsp")
   (rdf "$reduce/cslbuild/generated-c/u16.lsp")
   (rdf "$reduce/cslbuild/generated-c/u17.lsp")
   (rdf "$reduce/cslbuild/generated-c/u18.lsp")
   (rdf "$reduce/cslbuild/generated-c/u19.lsp")
   (rdf "$reduce/cslbuild/generated-c/u20.lsp")
   (rdf "$reduce/cslbuild/generated-c/u21.lsp")
   (rdf "$reduce/cslbuild/generated-c/u22.lsp")
   (rdf "$reduce/cslbuild/generated-c/u23.lsp")
   (rdf "$reduce/cslbuild/generated-c/u24.lsp")
   (rdf "$reduce/cslbuild/generated-c/u25.lsp")
   (rdf "$reduce/cslbuild/generated-c/u26.lsp")
   (rdf "$reduce/cslbuild/generated-c/u27.lsp")
   (rdf "$reduce/cslbuild/generated-c/u28.lsp")
   (rdf "$reduce/cslbuild/generated-c/u29.lsp")
   (rdf "$reduce/cslbuild/generated-c/u30.lsp")
   (rdf "$reduce/cslbuild/generated-c/u31.lsp")
   (rdf "$reduce/cslbuild/generated-c/u32.lsp")
   (rdf "$reduce/cslbuild/generated-c/u33.lsp")
   (rdf "$reduce/cslbuild/generated-c/u34.lsp")
   (rdf "$reduce/cslbuild/generated-c/u35.lsp")
   (rdf "$reduce/cslbuild/generated-c/u36.lsp")
   (rdf "$reduce/cslbuild/generated-c/u37.lsp")
   (rdf "$reduce/cslbuild/generated-c/u38.lsp")
   (rdf "$reduce/cslbuild/generated-c/u39.lsp")
   (rdf "$reduce/cslbuild/generated-c/u40.lsp")
   (rdf "$reduce/cslbuild/generated-c/u41.lsp")
   (rdf "$reduce/cslbuild/generated-c/u42.lsp")
   (rdf "$reduce/cslbuild/generated-c/u43.lsp")
   (rdf "$reduce/cslbuild/generated-c/u44.lsp")
   (rdf "$reduce/cslbuild/generated-c/u45.lsp")
   (rdf "$reduce/cslbuild/generated-c/u46.lsp")
   (rdf "$reduce/cslbuild/generated-c/u47.lsp")
   (rdf "$reduce/cslbuild/generated-c/u48.lsp")
   (rdf "$reduce/cslbuild/generated-c/u49.lsp")
   (rdf "$reduce/cslbuild/generated-c/u50.lsp")
   (rdf "$reduce/cslbuild/generated-c/u51.lsp")
   (rdf "$reduce/cslbuild/generated-c/u52.lsp")
   (rdf "$reduce/cslbuild/generated-c/u53.lsp")
   (rdf "$reduce/cslbuild/generated-c/u54.lsp")
   (rdf "$reduce/cslbuild/generated-c/u55.lsp")
   (rdf "$reduce/cslbuild/generated-c/u56.lsp")
   (rdf "$reduce/cslbuild/generated-c/u57.lsp")
   (rdf "$reduce/cslbuild/generated-c/u58.lsp")
   (rdf "$reduce/cslbuild/generated-c/u59.lsp")
   (rdf "$reduce/cslbuild/generated-c/u60.lsp")
    )))

(rdf "$srcdir/fastgets.lsp")
(rdf "$srcdir/compat.lsp")
(rdf "$srcdir/extras.lsp")
(rdf (cond
  ((memq 'jlisp lispsystem!*) "$srcdir/compiler-for-jlisp.lsp")
  (t "$srcdir/compiler.lsp")))

(fluid '(!*nocompile))
(setq !*nocompile nil)

(cond
  ((and (boundp 'interpreted) (eq (compress (explodec interpreted)) 'yes))
   (setq !*nocompile t)))

(progn (terpri)
       (princ "### !*nocompile = ")
       (print !*nocompile)
       nil)

(setq !*comp (null !*nocompile))

% Compile some important things first to improve bootstrapping speed.

(cond
  ((null !*nocompile)
   (compile '(
       s!:improve s!:literal_order s!:comval s!:outopcode0
       s!:plant_basic_block s!:remlose s!:islocal
       s!:is_lose_and_exit s!:comatom s!:destination_label
       s!:record_literal s!:resolve_labels s!:expand_jump
       s!:outopcode1lit stable!-sortip s!:iseasy s!:outjump
       s!:add_pending s!:comcall s!:resolve_literals))
   (compile!-all)))


% Tidy up be deleting any modules that are left over in this image

(dolist (a (library!-members)) (delete!-module a))

% Build fasl files for the compatibility code and the two
% versions of the compiler.

(print (list "*comp =" !*comp))

(faslout 'cslcompat)
(rdf "$srcdir/fastgets.lsp")
(rdf "$srcdir/compat.lsp")
(rdf "$srcdir/extras.lsp")
(faslend)

(faslout 'compiler)
(rdf (cond
  ((memq 'jlisp lispsystem!*) "$srcdir/compiler-for-jlisp.lsp")
  (t "$srcdir/compiler.lsp")))
(faslend)

(setq !*comp (null !*nocompile))

(de concat (u v)
    (compress (cons '!" (append (explode2 u)
                                (nconc (explode2 v) (list '!"))))))

(global '(oldchan!*))

(setq prolog_file 'cslprolo)

(setq rend_file 'cslrend)

(setq !*argnochk t)

(setq !*int nil)                    % Prevents input buffer being saved.

(setq !*msg nil)

(window!-heading "bootstrap RLISP")

% This is dervived fron the Standard LISP BOOT File.
% Author: Anthony C. Hearn.
% Copyright (c) 1991 RAND.  All Rights Reserved.

(fluid '(fname!* !*blockp !*lower !*mode))

(global '(oldchan!*))

(fluid '(!*raise !*lower))

(global '(crchar!* cursym!* nxtsym!* ttype!* !$eol!$))

(put '!; 'switch!* '(nil !*semicol!*))

(put '!( 'switch!* '(nil !*lpar!*))

(put '!) 'switch!* '(nil !*rpar!*))

(put '!, 'switch!* '(nil !*comma!*))

(put '!. 'switch!* '(nil cons))

(put '!= 'switch!* '(nil equal))

(put '!: 'switch!* '(((!= nil setq)) !*colon!*))

(put '!< 'switch!* '(((!= nil leq) (!< nil !*lsqbkt!*)) lessp))

(put '!> 'switch!* '(((!= nil geq) (!> nil !*rsqbkt!*)) greaterp))

% When the full pareser is loaded the function mkprec() will reset all
% these precedences. Until then please parenthesize expressions carefully.

(put '!*comma!* 'infix 1)

(put 'setq 'infix 2)

(put 'cons 'infix 3)

(put 'equal 'infix 4)

(put 'eq 'infix 5)

(flag '(!*comma!*) 'nary)

(flag '(!*colon!* !*semicol!* end then else) 'delim)

(put 'begin 'stat 'blockstat)

(put 'if 'stat 'ifstat)

(put 'symbolic 'stat 'procstat)

(de begin2 nil
   (prog nil
      (setq cursym!* '!*semicol!*)
a     (cond
         ((eq cursym!* 'end) (progn (rds oldchan!*) (return nil)))
         (t (prin2 (errorset '(eval (form (xread nil))) t t)) ))
      (go a)))

(de form (u) u)

(de xread (u) (progn (scan) (xread1 u)))

(de xread1 (u)
   (prog (v w x y z z2)
a     (setq z cursym!*)
a1    (cond
         ((or (null (atom z)) (numberp z)) (setq y nil))
         ((flagp z 'delim) (go end1))
         ((eq z '!*lpar!*) (go lparen))
         ((eq z '!*rpar!*) (go end1))
         ((and w (setq y (get z 'infix))) (go infx))
         ((setq y (get z 'stat)) (go stat)))
a3    (setq w (cons z w))
next  (setq z (scan))
      (go a1)
lparen(setq y nil)
      (cond
         ((eq (scan) '!*rpar!*)
            (and w (setq w (cons (list (car w)) (cdr w)))) )
         ((eqcar (setq z (xread1 'paren)) '!*comma!*)
            (setq w (cons (cons (car w) (cdr z)) (cdr w))))
         (t (go a3)))
      (go next)
infx  (setq z2 (car w))
un1   (setq w (cdr w))
      (cond
         ((null w) (go un2))
         (t (setq z2 (cons (car w) (list z2)))) )
      (go un1)
un2   (setq v (cons z2 v))
preced(cond ((null x) (go pr4)) ((lessp y (car (car x))) (go pr2)))
pr1   (setq x (cons (cons y z) x))
      (go next)
pr2   (setq v
         (cons
            (cond
               ((and (eqcar (car v) (cdar x)) (flagp (cdar x) 'nary))
                  (cons (cdar x) (cons (cadr v) (cdar v))))
               (t (cons (cdar x) (list (cadr v) (car v)))) )
            (cdr (cdr v))))
      (setq x (cdr x))
      (go preced)
stat  (setq w (cons (eval (list y)) w))
      (setq y nil)
      (go a)
end1  (cond
         ((and (and (null v) (null w)) (null x)) (return nil))
         (t (setq y 0)))
      (go infx)
pr4   (cond ((null (equal y 0)) (go pr1)) (t (return (car v)))) ))

(de eqcar (u v) (and (null (atom u)) (eq (car u) v)))

(de mksetq (u v) (list 'setq u v))

(de rread nil
   (prog (x)
      (setq x (token))
      (return
         (cond
            ((and (equal ttype!* 3) (eq x '!()) (rrdls))
            (t x)))) )

(de rrdls nil
   (prog (x r)
a     (setq x (rread))
      (cond
         ((null (equal ttype!* 3)) (go b))
         ((eq x '!)) (return (reverse r)))   % REVERSIP not yet defined.
         ((null (eq x '!.)) (go b)))
      (setq x (rread))
      (token)
      (return (nconc (reverse r) x))
b     (setq r (cons x r))
      (go a)))

(de token nil
   (prog (x y z)
      (setq x crchar!*)
a     (cond
         ((seprp x) (go sepr))
         ((digit x) (go number))
         ((liter x) (go letter))
         ((eq x '!%) (go coment))
         ((eq x '!!) (go escape))
         ((eq x '!') (go quote))
         ((eq x '!") (go string)))
      (setq ttype!* 3)
      (cond ((delcp x) (go d)))
      (setq nxtsym!* x)
a1    (setq crchar!* (readch))
      (go c)
escape(setq y (cons x y))
      (setq z (cons !*raise !*lower))
      (setq !*raise (setq !*lower nil))
      (setq x (readch))
      (setq !*raise (car z))
      (setq !*lower (cdr z))
letter(setq ttype!* 0)
let1  (setq y (cons x y))
      (cond
         ((or (digit (setq x (readch))) (liter x)) (go let1))
         ((eq x '!!) (go escape)))
      (setq nxtsym!* (intern (compress (reverse y))))
b     (setq crchar!* x)
c     (return nxtsym!*)
number(setq ttype!* 2)
num1  (setq y (cons x y))
      (cond ((digit (setq x (readch))) (go num1)))
      (setq nxtsym!* (compress (reverse y)))
      (go b)
quote (setq crchar!* (readch))
      (setq nxtsym!* (list 'quote (rread)))
      (setq ttype!* 4)
      (go c)
string(prog (raise !*lower)
         (setq raise !*raise)
         (setq !*raise nil)
   strinx(setq y (cons x y))
         (cond ((null (eq (setq x (readch)) '!")) (go strinx)))
         (setq y (cons x y))
         (setq nxtsym!* (mkstrng (compress (reverse y))))
         (setq !*raise raise))
      (setq ttype!* 1)
      (go a1)
coment(cond ((null (eq (readch) !$eol!$)) (go coment)))
sepr  (setq x (readch))
      (go a)
d     (setq nxtsym!* x)
      (setq crchar!* '! )
      (go c)))

(setq crchar!* '! )

(de delcp (u) (or (eq u '!;) (eq u '!$)))

(de mkstrng (u) u)

(de seprp (u) (or (eq u blank) (eq u tab) (eq u !$eol!$)))

(de scan nil
   (prog (x y)
      (cond ((null (eq cursym!* '!*semicol!*)) (go b)))
a     (setq nxtsym!* (token))
b     (cond
         ((or (null (atom nxtsym!*)) (numberp nxtsym!*)) (go l))
         ((and (setq x (get nxtsym!* 'newnam)) (setq nxtsym!* x))
            (go b))
         ((eq nxtsym!* 'comment) (go comm))
         ((and
             (eq nxtsym!* '!')
             (setq cursym!* (list 'quote (rread))))
            (go l1))
         ((null (setq x (get nxtsym!* 'switch!*))) (go l))
         ((eq (cadr x) '!*semicol!*)
            (return (setq cursym!* (cadr x)))) )
sw1   (setq nxtsym!* (token))
      (cond
         ((or
             (null (car x))
             (null (setq y (assoc nxtsym!* (car x)))) )
            (return (setq cursym!* (cadr x)))) )
      (setq x (cdr y))
      (go sw1)
comm  (cond ((eq (readch) '!;) (setq crchar!* '! )) (t (go comm)))
      (go a)
l     (setq cursym!*
         (cond
            ((null (eqcar nxtsym!* 'string)) nxtsym!*)
            (t (cons 'quote (cdr nxtsym!*)))) )
l1    (setq nxtsym!* (token))
      (return cursym!*)))

(de ifstat nil
   (prog (condx condit)
a     (setq condx (xread t))
      (setq condit (nconc condit (list (list condx (xread t)))) )
      (cond
         ((null (eq cursym!* 'else)) (go b))
         ((eq (scan) 'if) (go a))
         (t (setq condit
               (nconc condit (list (list t (xread1 t)))) )))
b     (return (cons 'cond condit))))

(de procstat nil
   (prog (x y)
      (cond ((eq cursym!* 'symbolic) (scan)))
      (cond
         ((eq cursym!* '!*semicol!*)
            (return (null (setq !*mode 'symbolic)))) )
      (setq fname!* (scan))
      (cond ((atom (setq x (xread1 nil))) (setq x (list x))))
      (setq y (xread nil))
      (cond ((flagp (car x) 'lose) (return nil)))
      (putd (car x) 'expr (list 'lambda (cdr x) y))
      (setq fname!* nil)
      (return (list 'quote (car x)))) )

(de blockstat nil
   (prog (x hold varlis !*blockp)
a0    (setq !*blockp t)
      (scan)
      (cond
         ((null (or (eq cursym!* 'integer) (eq cursym!* 'scalar)))
            (go a)))
      (setq x (xread nil))
      (setq varlis
         (nconc
            (cond ((eqcar x '!*comma!*) (cdr x)) (t (list x)))
            varlis))
      (go a0)
a     (setq hold (nconc hold (list (xread1 nil))))
      (setq x cursym!*)
      (scan)
      (cond ((not (eq x 'end)) (go a)))
      (return (mkprog varlis hold))))

(de mkprog (u v) (cons 'prog (cons u v)))

(de gostat nil
   (prog (x) (scan) (setq x (scan)) (scan) (return (list 'go x))))

(put 'go 'stat 'gostat)

(de rlis nil
   (prog (x)
      (setq x cursym!*)
      (return (list x (list 'quote (list (xread t)))))))

(de endstat nil (prog (x) (setq x cursym!*) (scan) (return (list x))))

% It is only a rather small number of lines of code to support
% both << >> blocks and WHILE statements here, and doing so makes
% it possible to write the full implementation of RLISP in a much
% more civilised way. What I put in here is a little more than is used
% to start with, but matches the eventual implementation. Eg the 'go
% and 'nodel flags are not relevant until the read parser has been loaded.

(de readprogn nil
   (prog (lst)
   a  (setq lst (cons (xread 'group) lst))
      (cond ((null (eq cursym!* '!*rsqbkt!*)) (go a)))
      (scan)
      (return (cons 'progn (reverse lst))))) 

(put '!*lsqbkt!* 'stat 'readprogn)
(flag '(!*lsqbkt!*) 'go)
(flag '(!*rsqbkt!*) 'delim)
(flag '(!*rsqbkt!*) 'nodel)

(de whilstat ()
   (prog (!*blockp bool bool2)
      (cond
         ((flagp 'do 'delim) (setq bool2 t))
         (t (flag '(do) 'delim)))
      (setq bool (xread t))
      (cond
         (bool2 (remflag '(do) 'delim)))
      (cond
         ((not (eq cursym!* 'do)) (symerr 'while t)))
      (return (list 'while bool (xread t)))))

(dm while (u)
   (prog (body bool lab)
      (setq bool (cadr u))
      (setq body (caddr u))
      (setq lab 'whilelabel) 
      (return (list
         'prog nil
    lab  (list 'cond
            (list (list 'not bool) '(return nil)))
         body
         (list 'go lab)))))

(put 'while 'stat 'whilstat)
(flag '(while) 'nochange)

(de repeatstat ()
   (prog (!*blockp body bool)
      (cond
         ((flagp 'until 'delim) (setq bool t))
         (t (flag '(until) 'delim)))
      (setq body (xread t))
      (cond
         ((null bool) (remflag '(until) 'delim)))
      (cond
         ((not (eq cursym!* 'until)) (symerr 'repeat t)))
      (return (list 'repeat body (xread t)))))

(dm repeat (u)
   (progn (terpri) (print (prog (body bool lab)
      (setq body (cadr u))
      (setq bool (caddr u))
      (setq lab 'repeatlabel) 
      (return (list
      'prog nil
    lab  body
         (list 'cond
            (list (list 'not bool) (list 'go lab))))))))))

(put 'repeat 'stat 'repeatstat)
(flag '(repeat) 'nochange)

% Now we have just enough to be able to start to express ourselves in
% (a subset of) rlisp.

(begin2)

rds(xxx := open("$reduce/packages/support/build.red", 'input));

(close xxx)

(load!-package!-sources prolog_file 'support)

(load!-package!-sources 'revision 'support)

(cond (!*backtrace (setq !*echo t)))

(load!-package!-sources 'rlisp 'rlisp)

(load!-package!-sources 'smacros 'support)

(load!-package!-sources rend_file 'support)

(load!-package!-sources 'poly 'poly)

(load!-package!-sources 'alg 'alg)

(load!-package!-sources 'arith 'arith)  %  Needed by roots, specfn*, (psl).

(load!-package!-sources 'entry 'support)

(load!-package!-sources 'remake 'support)

(setq !*comp nil)

(begin)

symbolic;

!#if (and (not (memq 'embedded lispsystem!*))
          (not !*savedef))

faslout 'user;

%
% The "user" module is only useful when building a full system, since
% in the bootstrap the files u01.lsp to u60.lsp will probably not exist
% and it is CERTAIN that they are not useful.
%

if modulep 'cslcompat then load!-module 'cslcompat;

!#if (not (memq 'jlisp lispsystem!*))
% Note that Jlisp will use a different scheme to get the literal-vectors
% of translated functions installed.

symbolic procedure c!:install(name, env, c!-version, !&optional, c1);
  begin
    scalar v, n;
    if c1 then return check!-c!-code(name, env, c!-version, c1);
    put(name, 'c!-version, c!-version);
    if null env then return name;
    v := mkvect sub1 length env;
    n := 0;
    while env do <<
      putv(v, n, car env);
      n := n + 1;
      env := cdr env >>;
% I only instate the environment if there is nothing useful there at
% present. This is a rather dubious test!
    if symbol!-env name = nil or
       symbol!-env name = name then symbol!-set!-env(name, v);
    put(name, 'funarg, v);
    return name;
  end;

rdf "$reduce/cslbuild/generated-c/u01.lsp"$
rdf "$reduce/cslbuild/generated-c/u02.lsp"$
rdf "$reduce/cslbuild/generated-c/u03.lsp"$
rdf "$reduce/cslbuild/generated-c/u04.lsp"$
rdf "$reduce/cslbuild/generated-c/u05.lsp"$
rdf "$reduce/cslbuild/generated-c/u06.lsp"$
rdf "$reduce/cslbuild/generated-c/u07.lsp"$
rdf "$reduce/cslbuild/generated-c/u08.lsp"$
rdf "$reduce/cslbuild/generated-c/u09.lsp"$
rdf "$reduce/cslbuild/generated-c/u10.lsp"$
rdf "$reduce/cslbuild/generated-c/u11.lsp"$
rdf "$reduce/cslbuild/generated-c/u12.lsp"$
rdf "$reduce/cslbuild/generated-c/u13.lsp"$
rdf "$reduce/cslbuild/generated-c/u14.lsp"$
rdf "$reduce/cslbuild/generated-c/u15.lsp"$
rdf "$reduce/cslbuild/generated-c/u16.lsp"$
rdf "$reduce/cslbuild/generated-c/u17.lsp"$
rdf "$reduce/cslbuild/generated-c/u18.lsp"$
rdf "$reduce/cslbuild/generated-c/u19.lsp"$
rdf "$reduce/cslbuild/generated-c/u20.lsp"$
rdf "$reduce/cslbuild/generated-c/u21.lsp"$
rdf "$reduce/cslbuild/generated-c/u22.lsp"$
rdf "$reduce/cslbuild/generated-c/u23.lsp"$
rdf "$reduce/cslbuild/generated-c/u24.lsp"$
rdf "$reduce/cslbuild/generated-c/u25.lsp"$
rdf "$reduce/cslbuild/generated-c/u26.lsp"$
rdf "$reduce/cslbuild/generated-c/u27.lsp"$
rdf "$reduce/cslbuild/generated-c/u28.lsp"$
rdf "$reduce/cslbuild/generated-c/u29.lsp"$
rdf "$reduce/cslbuild/generated-c/u30.lsp"$
rdf "$reduce/cslbuild/generated-c/u31.lsp"$
rdf "$reduce/cslbuild/generated-c/u32.lsp"$
rdf "$reduce/cslbuild/generated-c/u33.lsp"$
rdf "$reduce/cslbuild/generated-c/u34.lsp"$
rdf "$reduce/cslbuild/generated-c/u35.lsp"$
rdf "$reduce/cslbuild/generated-c/u36.lsp"$
rdf "$reduce/cslbuild/generated-c/u37.lsp"$
rdf "$reduce/cslbuild/generated-c/u38.lsp"$
rdf "$reduce/cslbuild/generated-c/u39.lsp"$
rdf "$reduce/cslbuild/generated-c/u40.lsp"$
rdf "$reduce/cslbuild/generated-c/u41.lsp"$
rdf "$reduce/cslbuild/generated-c/u42.lsp"$
rdf "$reduce/cslbuild/generated-c/u43.lsp"$
rdf "$reduce/cslbuild/generated-c/u44.lsp"$
rdf "$reduce/cslbuild/generated-c/u45.lsp"$
rdf "$reduce/cslbuild/generated-c/u46.lsp"$
rdf "$reduce/cslbuild/generated-c/u47.lsp"$
rdf "$reduce/cslbuild/generated-c/u48.lsp"$
rdf "$reduce/cslbuild/generated-c/u49.lsp"$
rdf "$reduce/cslbuild/generated-c/u50.lsp"$
rdf "$reduce/cslbuild/generated-c/u51.lsp"$
rdf "$reduce/cslbuild/generated-c/u52.lsp"$
rdf "$reduce/cslbuild/generated-c/u53.lsp"$
rdf "$reduce/cslbuild/generated-c/u54.lsp"$
rdf "$reduce/cslbuild/generated-c/u55.lsp"$
rdf "$reduce/cslbuild/generated-c/u56.lsp"$
rdf "$reduce/cslbuild/generated-c/u57.lsp"$
rdf "$reduce/cslbuild/generated-c/u58.lsp"$
rdf "$reduce/cslbuild/generated-c/u59.lsp"$
rdf "$reduce/cslbuild/generated-c/u60.lsp"$

!#endif

if modulep 'smacros then load!-module 'smacros;

faslend;
!#endif

faslout 'remake;

!#if (and (not (memq 'embedded lispsystem!*)) (not !*savedef))

load!-module "user";

!#endif

in "$reduce/packages/support/remake.red"$

global '(reduce_base_modules reduce_extra_modules
         reduce_test_cases reduce_regression_tests
         !*reduce!-packages!*);

symbolic procedure get_configuration_data();
% Read data from a configuration file that lists the modules that must
% be processed.  NOTE that this and the next few funtions will ONLY
% work properly if REDUCE had been started up with the correct
% working directory. This is (just about) acceptable because these are
% system maintainance functions rather than generally flexible things
% for arbitrary use.
  begin
    scalar i, w, e, r, r1;
% Configuration information is held in a file called something like
% "package.map".
    if boundp 'minireduce and symbol!-value 'minireduce then
         i := "package.map"
    else i := "$reduce/packages/package.map";
    i := open(i, 'input);
    i := rds i;
    e := !*echo;
    !*echo := nil;
    w := read();
    !*echo := e;
    i := rds i;
    close i;
    reduce_base_modules :=
      for each x in w conc
         if member('core, cddr x) and
            member('csl, cddr x) then list car x else nil;
    reduce_extra_modules :=
      for each x in w conc
         if not member('core, cddr x) and
            member('csl, cddr x) then list car x else nil;
    reduce_test_cases :=
      for each x in w conc
         if member('test, cddr x) and
            member('csl, cddr x) then list car x else nil;
% Any file with a name *.tst in the regressions directory will be
% considered to be a test case in addition to ones explicitly shown
% in package.map.
    reduce_regression_tests := nil;
    r := list!-directory "$reduce/packages/regressions";
    for each f in r do <<
      r1 := reverse explodec f;
      if eqcar(r1, 't) and
         eqcar(cdr r1, 's) and
         eqcar(cddr r1, 't) and
         eqcar(cdddr r1, '!.) then <<
            r1 := intern list!-to!-string reverse cddddr r1;
            put(r1, 'folder, "regressions");
            reduce_regression_tests :=
               r1 . reduce_regression_tests >> >>;
% I will run the "alg" test twice! This is for the benefit of Java where the
% first time will be seriously slowed down by the need to JIT almost
% everything.
    reduce_test_cases := 'alg . append(reduce_test_cases, reduce_regression_tests);
    for each x in w do
       if member('csl, cddr x) then put(car x, 'folder, cadr x);
%   princ "reduce_base_modules: "; print reduce_base_modules;
%   princ "reduce_extra_modules: "; print reduce_extra_modules;
%   princ "reduce_test_cases: "; print reduce_test_cases;
%   princ "reduce_regression_tests: "; print reduce_regression_tests;
    !*reduce!-packages!* := append(reduce_base_modules, reduce_extra_modules);
    return;
  end;

symbolic procedure build_reduce_modules names;
  begin
    scalar w;
    if boundp 'interpreted and interpreted then !*nocompile := t;
    !*comp := null !*nocompile;

!#if !*savedef
    !*savedef := t;
!#else
    !*savedef := nil;
!#endif
!#if !*noinlines
    !*noinlines := t;
!#else
    !*noinlines := nil;
!#endif
    make!-special '!*native_code;
    !*native_code := nil;
    get_configuration_data();
    if !*backtrace then !*echo := t;  % To help with debugging...
    w := explodec car names;
    if !*savedef then w := append(explodec "[Bootstrap] ", w);
    window!-heading list!-to!-string w;
!#if !*savedef
% When building the bootstrap version I want to record what switches
% get declared...
    if not getd 'original!-switch then <<
       w := getd 'switch;
       putd('original!-switch, car w, cdr w);
       putd('switch, 'expr,
          '(lambda (x)
              (dolist (y x) (princ "+++ Declaring a switch: ") (print y))
              (original!-switch x))) >>;
!#endif
    package!-remake car names;
    if null (names := cdr names) then <<
        printc "Recompilation complete";
        window!-heading  "Recompilation complete" >>;
!#if (or !*savedef (memq 'embedded lispsystem!*))
    if null names then restart!-csl 'begin
    else restart!-csl('(remake build_reduce_modules), names)
!#else
    if null names then restart!-csl '(user begin)
    else restart!-csl('(remake build_reduce_modules), names)
!#endif
  end;

fluid '(cpulimit conslimit testdirectory);

symbolic procedure test_a_package names;
  begin
    scalar packge, logname, logtmp, logfile;
    scalar quitfn, oll, rr, !*redefmsg, !*redeflg!*, walltime, w;
    if not boundp 'cpulimit or
       not fixp (cpulimit := compress explodec cpulimit) or
       cpulimit < 1 then
       cpulimit := if memq('jlisp, lispsystem!*) then 6000 else 360;
    if not boundp 'conslimit or
       not fixp (conslimit := compress explodec conslimit) or
       conslimit < 1 then
       conslimit := 2000;
    princ "TESTING: "; printc car names;
    window!-heading list!-to!-string append(explodec "[Testing] ",
                                            explodec car names);
    !*backtrace := nil;
    !*errcont := t;
    !*extraecho := t;    % Ensure standard environment for the test...
    !*int := nil;        % ... so that results are predictable.
    packge := car names;
    verbos nil;
% Normally logs from testing go in testlogs/name.rlg, however you may
% may sometimes want to put them somewhere else. If you do then launch reduce
% along the lines
%    reduce -D@log="mylogs" ...
% and ensure that <top>/mylogs exists.
    if boundp '!@log and stringp symbol!-value '!@log then
        logname := symbol!-value '!@log
    else logname := "testlogs";
    logname := concat(logname, "/");
    logtmp  := concat(logname, concat(car names, ".tmp"));
    logname := concat(logname, concat(car names,".rlg"));
    logfile := open(logtmp, 'output);
    get_configuration_data();
% Any messages generated while loading the package do NOT appear in the log
    if not memq(packge, reduce_regression_tests) then load!-package packge;
    begin
       scalar !*terminal!-io!*, !*standard!-output!*, !*error!-output!*,
              !*trace!-output!*, !*debug!-io!*, !*query!-io!*, !*errcont,
              outputhandler!*;
       !*terminal!-io!* := !*standard!-output!* := !*error!-output!* := logfile;
       !*trace!-output!* := !*debug!-io!* := !*query!-io!* := logfile;
       oll := linelength 80;
%      princ date(); princ " run on "; printc cdr assoc('name, lispsystem!*);
       if get(packge,'folder) then packge := get(packge,'folder);
       testdirectory := concat("$reduce/packages/", packge);
       packge := concat("$reduce/packages/",
                   concat(packge,
                     concat("/",
                       concat(car names,".tst"))));
       quitfn := getd 'quit;
% At least at one stage at least one test file ends in "quit;" rather than
% "end;" and the normal effect would be that this leads it to cancel
% all execution instantly. To avoid that I will undefine the function
% "quit", but restore it after the test. I reset !*redefmsg to avoid getting
% messages about this. I redefined quit to something (specifically "posn")
% that does not need an argument and that is "harmless".
       remd 'quit;
       putd('quit, 'expr, 'posn);
       !*mode := 'algebraic;
       !*extraecho := t;    % Ensure standard environment for the test...
       !*int := nil;        % ... so that results are predictable.
       !*errcont := t;
% resource!-limit is a special feature in CSL so that potentially wild
% code can be run with it being stopped harshly if it gets stuck.
% The first argument is an expression to evaluate. The next 4 are
%    a time limit, in seconds
%    a "cons" limit, in megaconses
%    a limit on the number of thousands of I/O bytes that can be
%            performed, with both reading and printing counted
%    a limit on the number of Lisp-level errors that can be raised.
%            note that that can be large if errorset is used to trap them.
%
% If a limit is specified as a negative value (typically -1) then that
% resource is not applied.
% The first 3 limits are applied in an APPROXIMATE way, and the first
% is seriously sensitive the the speed of the computer you are running
% on, so should be used with real care. At the end the return value
% is atomic if a limit expired, otherwise ncons of the regular value.
% A global variable *resources* should end up a list of 4 values
% showing the usage in each category.

% The settings here are intended to be fairly conservative...
%  Time:   On an Intel Q6600 CPU the longest test runs in under 20 seconds,
%          so allowing 3 minutes gives almost a factor of 10 slack. If
%          many people are running slow(ish) machines still I can increase
%          the limit.
%  Space:  The amount of space used ought to be pretty independent of
%          the computer used. Measuring on 32 and 64-bit systems will
%          give minor differences. But the limit given here seems to allow
%          all the current tests to run with a factor of 2 headroom
%          in case the test-scripts are updated.
%  IO:     The "crack" package has code in it that checkpoints its state
%          to disc periodically, and tests that activate that use amazingly
%          more IO than the others. The limit at 10 Mbytes suits the
%          relevant current tests. If a broken package leads to a test
%          script looping this then means that the resulting log file is no
%          larger than (about) 10 Mbytes, which is ugly but managable.
%  Errors: Some REDUCE packages make extensive use of errorset and
%          predictable use of "error" (for lack of use of catch and throw,
%          usually). So I do not constrain errors here. But if things were
%          ever such that no errors were expected I could enforce that
%          condition here.
       walltime := timeofday();
       eval '(resettime1);
       rr := resource!-limit(list('in_list1, mkquote packge, t),
                             cpulimit, % CPU time per test
                             conslimit,  % megaconses
                             10000,% allow ten megabytes of I/O
                             -1);  % Do not limit Lisp-level errors at all
       erfg!* := nil;
       terpri();
       princ "Tested on ";
       princ cdr assoc('platform, lispsystem!*);
       princ " CSL";
       eval '(showtime1 nil);
       w := timeofday();
       walltime := (car w - car walltime) . (cdr w - cdr walltime);
       w := cdr walltime;
       walltime := car walltime;
       if w < 0 then << walltime := walltime - 1; w := w + 1000000 >>;
       princ "real	";
       princ (walltime/60);
       princ "m";
       princ remainder(walltime, 60);
       princ ".";
% This illustrates that I need a proper general formatted print mechanism!
       w := (w + 500)/1000;
       if w < 10 then princ "00"
       else if w < 100 then princ "0";
       princ w;
       printc "s";
       erfg!* := nil;
       putd('quit, car quitfn, cdr quitfn);
       if atom rr then printc "+++++ Error: Resource limit exceeded";
       linelength oll
    end;
    close logfile;
    delete!-file logname;
    rename!-file(logtmp, logname);
    names := cdr names;
    if null names then <<
        printc "Testing complete";
        window!-heading "Testing complete";
        restart!-csl t >>
    else restart!-csl('(remake test_a_package), names)
  end;

symbolic procedure profile_compare_fn(p, q);
  begin
    scalar a, b;
    a := (float caddr p/float cadr p);
    b := (float caddr q/float cadr q);
    if a < b then return t
    else if a > b then return nil
    else return ordp(p, q)   % Use alpha ordering on function
                             % if counts match exactly.
  end;

%
% This function runs a test file and sorts out what the top 350
% functions in it. It appends their names to "profile.dat".
%

symbolic procedure profile_a_package names;
  begin
    scalar packge, oll, w, w1, w2, quitfn, !*errcont, rr;
    if not boundp 'cpulimit or
       not fixp (cpulimit := compress explodec cpulimit) or
       cpulimit < 1 then
       cpulimit := if memq('jlisp, lispsystem!*) then 5000 else 180;
    if not boundp 'conslimit or
       not fixp (conslimit := compress explodec conslimit) or
       conslimit < 1 then
       conslimit := 2000;
    princ "PROFILING: "; print car names;
    !*backtrace := nil;
    !*errcont := t;
    !*int := nil;
    packge := car names;
    verbos nil;
    get_configuration_data();
    if not memq(packge, reduce_regression_tests) then <<
       load!-package packge;
       if get(packge,'folder) then packge := get(packge,'folder);
       testdirectory := concat("$reduce/packages/", packge);
       packge := concat("$reduce/packages/",
                   concat(packge,
                     concat("/",
                       concat(car names,".tst"))));
       oll := linelength 80;
       !*mode := 'algebraic;
       window!-heading list!-to!-string append(explodec "[Profile] ",
                                               explodec car names);
       quitfn := getd 'quit;
       remd 'quit;
       putd('quit, 'expr, 'posn);
       mapstore 4;  % reset counts;
       !*errcont := t;
% I try hard to arrange that even if the test fails I can continue and that
% input & output file selection is not messed up for me.
       w := wrs nil;   w1 := rds nil;
       wrs w;          rds w1;
       rr := resource!-limit(list('errorset,
                                  mkquote list('in_list1, mkquote packge, t),
                                  nil, nil),
                             cpulimit,
                             conslimit,
                             10000,% allow ten megabytes of I/O
                             -1);  % Do not limit Lisp-level errors at all
       wrs w;          rds w1;
       erfg!* := nil;
       terpri();
       putd('quit, car quitfn, cdr quitfn);
       w := sort(mapstore 2, function profile_compare_fn);
       begin
          scalar oo;
          oo := wrs open("buildlogs/flaguse.log", 'append);
          bytecounts t;
          close wrs oo;
       end;
       load!-source(); % Need source versions of all code here
       w1 := nil;
       while w do <<
           w2 := get(caar w, '!*savedef);
           if eqcar(w2, 'lambda) then w1 := (caar w . md60 (caar w . cdr w2) .
                                             cadar w . caddar w) . w1;
           w := cdr w >>;
       w := w1;
       % I collect the top 350 functions as used by each test, not because all
       % that many will be wanted but because I might as well record plenty
       % of information here and discard unwanted parts later on.
       for i := 1:349 do if w1 then w1 := cdr w1;
       if w1 then rplacd(w1, nil);
       % princ "MODULE "; prin car names; princ " suggests ";
       % print for each z in w collect car z;
       w1 := open("profile.dat", 'append);
       w1 := wrs w1;
       linelength 80;
       if atom rr then printc "% +++++ Error: Resource limit exceeded";
       princ "% @@@@@ Resources used: "; print !*resources!*;
       princ "("; prin car names; terpri();
       for each n in w do <<
           princ "  ("; prin car n; princ " ";
           if posn() > 30 then << terpri(); ttab 30 >>;
           prin cadr n;
           % I also display the counts just to help me debug & for interest.
           princ " "; prin caddr n; princ " "; princ cdddr n;
           printc ")" >>;
       printc "  )";
       terpri();
       close wrs w1;
       linelength oll >>;
    names := cdr names;
    if null names then <<
        w1 := open("buildlogs/flaguse.log", 'input);
        w1 := rds w1;
        w := nil;
        while (w2 := read()) neq !$eof!$ do
            w := sort(w2, 'orderp) . w;
        close rds w1;
        rr := '((symbol!-make!-fastget 'lose 1)
                (symbol!-make!-fastget 'noncom 0));
        flag('(lose noncom), 'processed);
        oll := 2;
        while w do <<
           w1 := nil;
           for each x in w do <<
               if x and
                  not flagp(cadar x, 'processed) and
                  oll < 63 then <<
                   rr :=
                       list('symbol!-make!-fastget, mkquote cadar x, oll) . rr;
                   flag(list cadar x, 'processed);
                   oll := oll + 1 >>;
               if cdr x then w1 := cdr x . w1 >>;
           w := reverse w1 >>;
        w := open("buildlogs/fastgets.lsp", 'output);
        w := wrs w;
        printc "% fastgets.lsp generated by profiling";
        terpri();
        prettyprint ('progn . reverse rr);
        terpri();
        printc "% end of fastgets.lsp";
        close wrs w;
        printc "Profiling complete";
        window!-heading "Profiling complete";
        restart!-csl t >>
    else restart!-csl('(remake profile_a_package), names)
  end;

symbolic procedure trim_prefix(a, b);
  begin
    while a and b and car a = car b do <<
      a := cdr a;
      b := cdr b >>;
    if null a then return b
    else return nil
  end;

fluid '(time_info);

symbolic procedure read_file f1;
  begin
% I take the view that I can afford to read the whole of a file into
% memory at the start of processing. This makes life easier for me
% and the REDUCE log files are small compared with current main memory sizes.
    scalar r, w, w1, n, x;
    scalar p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13;
% To make comparisons between my CSL logs and some of the "reference
% logs", which are created using a different script, I will discard
% lines that match certain patterns!  Note that if the reference logs change
% the particular tests I perform here could become out of date! Also if any
% legitimate test output happened to match one of the following strings
% I would lose out slightly.
    p1 := explodec "Time: ";
    p2 := explodec "user	";
    p3 := explodec "sys	";
    p4 := explodec "time to formulate conditions:";
    p5 := explodec "CRACK needed :";
    p6 := explodec "time for initializations:";
    p7 := explodec "Tested on ";
    p8 := explodec "Total time taken:";
    p9 := explodec "*** turned off switch";
    p10 := explodec "+++ levelt compiled";
    p11 := explodec "Request to set constant bitsperword";
    p12 := explodec "*** (levelt): base";
    p13 := explodec "max_gc_int :";
    r := nil;
    n := 0;
    while not ((w := readline f1) = !$eof!$) do <<
       w1 := explodec w;
       if trim_prefix(p1, w1)
          or trim_prefix(p2, w1)
          or trim_prefix(p3, w1)
          or trim_prefix(p4, w1)
          or trim_prefix(p5, w1)
          or trim_prefix(p6, w1)
          or trim_prefix(p7, w1)
          or trim_prefix(p8, w1)
          or trim_prefix(p9, w1)
          or trim_prefix(p10, w1)
          or trim_prefix(p11, w1)
          or trim_prefix(p12, w1)
          or trim_prefix(p13, w1)
          then n := n + 1
       else r := ((n := n + 1) . w) . r >>;
    w := r;
% The text scanned for here is expected to match that generated by the
% test script. I locate the last match in a file, extract the numbers
% and eventually write them to testlogs/times.log
    n := explodec "Time (counter 1):";
    while w and null (x := trim_prefix(n, explodec cdar w)) do w := cdr w;
    if null w then <<
       time_info := nil;
       return reversip r >>;
% Remove time info from lines
    w := cdr w;
    if (trim_prefix(explodec "Tested on ", explodec cdar w)) then w := cdr w;
    r := w;
    while eqcar(x, '! ) do x := cdr x;
    w := n := nil;
    while digit car x do << w := car x . w; x := cdr x >>;
    while eqcar(x, '! ) do x := cdr x;
    if x := trim_prefix(explodec "ms  plus GC time:", x) then <<
        while eqcar(x, '! ) do x := cdr x;
        while digit car x do << n := car x . n; x := cdr x >> >>;
    if null w then w := '(!0);
    if null n then n := '(!0);
    time_info := compress reverse w . compress reverse n;
    return reversip r;
  end;

fluid '(!*insist_on_exact_match);

!*insist_on_exact_match := t;

symbolic procedure roughly_equal(a, b);
  begin
% a and b are strings repesenting lines of text. I want to test if they
% match subject to some floating point slop.
    scalar wa, wb, adot, bdot;
    if a = b then return t;
    a := explodec a;
    b := explodec b;
    if !*insist_on_exact_match then return (a = b);
top:
% First deal with end of line matters.
    if null a and null b then return t
    else if null a or null b then return nil;
% next split off any bits of a and b up to a digit
    wa := wb := nil;
    while a and not digit car a do <<
       wa := car a . wa;
       a := cdr a >>;
    while b and not digit car b do <<
       wb := car b . wb;
       b := cdr b >>;
    if not (wa = wb) then return nil;
% now both a and b start with digits. I will seek a chunk of the
% form nnn.mmmE+xxx where E<sign>xxx is optional...
% Note that any leading sign on the float has been checked already!
    wa := wb := nil;
    adot := bdot := nil;
    while a and digit car a do <<
       wa := car a . wa;
       a := cdr a >>;
    if eqcar(a, '!.) then <<
       adot := t;
       wa := car a . wa;
       a := cdr a >>;
    while a and digit car a do <<
       wa := car a . wa;
       a := cdr a >>;
    if eqcar(a, '!e) or eqcar(a, '!E) then <<
       adot := t;
       wa := car a . wa;
       a := cdr a;
       if eqcar(a, '!+) or eqcar(a, '!-) then <<
          wa := car a . wa;
          a := cdr a >>;
       while a and digit car a do <<
          wa := car a . wa;
          a := cdr a >> >>;
% Now all the same to grab a float from b
    while b and digit car b do <<
       wb := car b . wb;
       b := cdr b >>;
    if eqcar(b, '!.) then <<
       bdot := t;
       wb := car b . wb;
       b := cdr b >>;
    while b and digit car b do <<
       wb := car b . wb;
       b := cdr b >>;
    if eqcar(b, '!e) or eqcar(b, '!E) then <<
       bdot := t;
       wb := car b . wb;
       b := cdr b;
       if eqcar(b, '!+) or eqcar(b, '!-) then <<
          wb := car b . wb;
          b := cdr b >>;
       while b and digit car b do <<
          wb := car b . wb;
          b := cdr b >> >>;
% Now one possibility is that I had an integer not a float,
% and in that case I want an exact match
    if not adot or not bdot then <<
       if wa = wb then goto top
       else return nil >>;
    if wa = wb then goto top;   % textual match on floating point values
    wa := compress reversip wa;
    wb := compress reversip wb;
    if fixp wa then wa := float wa;
    if fixp wb then wb := float wb;
    if not (floatp wa and floatp wb) then return nil; % messed up somehow!
    if wa = wb then goto top;
% now the crucial approximate floating point test - note that both numbers
% are positive, but that they may be extreme in range.
% As a cop-out I am going to insist that if values are either very very big
% or very very small that they match as text.
    if wa > 1.0e100 or wb > 1.0e100 then return nil;
    if wa < 1.0e-100 or wb < 1.0e-100 then return nil;
    wa := (wa - wb)/(wa + wb);
    if wa < 0 then wa := -wa;
    if wa > 0.0001 then return nil; % pretty crude!
    goto top
  end;

symbolic procedure in_sync(d1, n1, d2, n2);
  begin
    for i := 1:n1 do if d1 then <<  % skip n1 lines from d1
       d1 := cdr d1 >>;
    for i := 1:n2 do if d2 then <<  % skip n2 lines from d2
       d2 := cdr d2 >>;
% If one is ended but the other is not then we do not have a match. If
% both are ended we do have one.
    if null d1 then return null d2
    else if null d2 then return nil;
% Here I insist on 3 lines that agree before I count a match as
% having been re-established.
    if not roughly_equal(cdar d1, cdar d2) then return nil;
    d1 := cdr d1; d2 := cdr d2;
    if null d1 then return null d2
    else if null d2 then return nil;
    if not roughly_equal(cdar d1, cdar d2) then return nil;
    d1 := cdr d1; d2 := cdr d2;
    if null d1 then return null d2
    else if null d2 then return nil;
    if not roughly_equal(cdar d1, cdar d2) then return nil;
    d1 := cdr d1; d2 := cdr d2;
    if null d1 then return null d2
    else if null d2 then return nil
    else return t
  end;

fluid '(time_data time_ratio gc_time_ratio log_count);

symbolic procedure prinright(x, w);
  begin
    scalar xx, xl;
    xx := explodec x;
    xl := length xx;
    while w > xl do << princ " "; xl := xl + 1 >>;
    princ x;
  end;

fluid '(files_with_differences);

symbolic procedure file_compare(f1, f2, name);
  begin
    scalar i, j, d1, d2, t1, gt1, t2, gt2, time_info, fdiffer;
    d1 := read_file f1;
    if null time_info then t1 := gt1 := 0
    else << t1 := car time_info; gt1 := cdr time_info >>;
    d2 := read_file f2;
    if null time_info then t2 := gt2 := 0
    else << t2 := car time_info; gt2 := cdr time_info >>;
    i := wrs time_data;
    j := set!-print!-precision 3;
    prin name;
    ttab 17;
    if zerop t1 then princ "     ---"
    else << prinright(t1, 8);
% Tag the time with an asterisk if it will not participate in the
% eventual overall timing report.
            if t1<=200 then princ "*";
            ttab 30; prinright(gt1, 8) >>;
    ttab 40;
    if zerop t2 then princ "     ---"
    else << prinright(t2, 9);
            if t2<=200 then princ "*";
            ttab 50; prinright(gt2, 8) >>;
    ttab 60;
    if zerop t1 or zerop t2 then princ "     ***       ***"
    else begin
       scalar r1, gr1, w;
       r1 := float t1 / float t2;
       gr1 := float (t1+gt1)/float (t2+gt2);
% I will only use tests where the time taken was over 200ms in my eventual
% composite summary of timings, since measurement accuracy can leave the
% really short tests pretty meaningless.
       if t1 > 200 and t2 > 200 then <<
% But I will go further than that and give less weight to any test whose time
% is under 1 second, so that the cut-off is gradual rather than abrupt.
          w := min(t1, t2);
% This means that if w (the smaller time) = 200 then then
% the test does not contribute to the average, while if w>=1000
% it contributes fully.
          if w < 1000.0 then w := (w - 200.0)/800.0
          else w := 1.0;
          time_ratio := time_ratio * expt(r1, w);
          gc_time_ratio := gc_time_ratio * expt(gr1, w);
          log_count := log_count + w >>;
       princ r1;
       ttab 70;
       princ gr1;
       end;
    terpri();
    set!-print!-precision j;
    wrs i;
% The next segment of code is a version of "diff" to report ways in which
% reference and recent log files match or diverge.
% I can not see a neat way to get a "structured" control structure
% here easily.  Ah well, drop back to GOTO statements!
top:
    if null d1 then <<      % end of one file
       if d2 then terpri();
       i := 0;
       while d2 and i < 20 do <<
          fdiffer := t;
          princ "REF "; princ caar d2; princ ":"; ttab 10; printc cdar d2;
          d2 := cdr d2;
          i := i + 1 >>;
       if d2 then printc "...";
       if fdiffer then files_with_differences := name . files_with_differences;
       return >>;
    if null d2 then <<      % end of other file
       i := 0;
       while d1 and i < 20 do <<
          fdiffer := t;
          princ "NEW "; princ caar d1; princ ":"; ttab 10; printc cdar d1;
          d1 := cdr d1;
          i := i + 1 >>;
       if d1 then printc "...";
       if fdiffer then files_with_differences := name . files_with_differences;
       return >>;
% The test "roughly_equal" compares allowing some tolerance on floating
% point values. This is because REDUCE uses platform libraries for
% floating point elementary functions and printing, so small differences
% are expected. This is perhaps uncomfortable, but is part of reality, and
% the test here makes comparison output much more useful in that the
% differences shown up are better limited towards "real" ones.
    if roughly_equal(cdar d1, cdar d2) then <<
       d1 := cdr d1;
       d2 := cdr d2;
       go to top >>;
% I will first see if there are just a few blank lines inserted into
% one or other file. This special case is addressed here because it
% appears more common a possibility than I had expected.
    if cdar d1 = "" and cdr d1 and roughly_equal(cdadr d1, cdar d2) then <<
       fdiffer := t;
       princ "NEW "; princ caar d1; princ ":"; ttab 10; printc cdar d1;
       d1 := cdr d1;
       go to top >>
    else if cdar d1 = "" and cdr d1 and cdadr d1 = "" and cddr d1 and
       roughly_equal(cdaddr d1, cdar d2) then <<
       fdiffer := t;
       princ "NEW "; princ caar d1; princ ":"; ttab 10; printc cdar d1;
       d1 := cdr d1;
       princ "NEW "; princ caar d1; princ ":"; ttab 10; printc cdar d1;
       d1 := cdr d1;
       go to top >>
    else if cdar d2 = "" and cdr d2 and
       roughly_equal(cdadr d2, cdar d1) then <<
       fdiffer := t;
       princ "REF "; princ caar d2; princ ":"; ttab 10; printc cdar d2;
       d2 := cdr d2;
       go to top >>
    else if cdar d2 = "" and cdr d2 and cdadr d2 = "" and cddr d2 and
       roughly_equal(cdaddr d2, cdar d1) then <<
       fdiffer := t;
       princ "REF "; princ caar d2; princ ":"; ttab 10; printc cdar d2;
       d2 := cdr d2;
       princ "REF "; princ caar d2; princ ":"; ttab 10; printc cdar d2;
       d2 := cdr d2;
       go to top >>;
    i := 1;
seek_rematch:
    j := 0;
inner:
    if in_sync(d1, i, d2, j) then <<
       terpri();
       for k := 1:i do <<
          if not trim_prefix(explodec "Time (counter 1)", explodec cdar d1) and
             not trim_prefix(explodec "real	", explodec cdar d1) then
             fdiffer := t;
          princ "NEW "; princ caar d1; princ ":"; ttab 10; printc cdar d1;
          d1 := cdr d1 >>;
       for k := 1:j do <<
          if not trim_prefix(explodec "Time (counter 1)", explodec cdar d2) and
             not trim_prefix(explodec "real	", explodec cdar d2) then
             fdiffer := t;
          princ "REF "; princ caar d2; princ ":"; ttab 10; printc cdar d2;
          d2 := cdr d2 >>;
       if null d1 then <<
          if fdiffer then files_with_differences := name . files_with_differences;
          return >>
       else go to top >>;
    j := j + 1;
    i := i - 1;
    if i >= 0 then go to inner;
    i := j;
% I am prepared to seek 80 lines ahead on each side before I give up.
% The number 80 is pretty much arbitrary.
    if i < 80 then goto seek_rematch;
    terpri();
    i := 0;
    while d2 and i < 20 do <<
       fdiffer := t;
       princ "REF "; princ caar d2; princ ":"; ttab 10; printc cdar d2;
       d2 := cdr d2;
       i := i+1 >>;
    if d2 then printc "...";
    i := 0;
    while d1 and i < 20 do <<
       fdiffer := t;
       princ "NEW "; princ caar d1; princ ":"; ttab 10; printc cdar d1;
       d1 := cdr d1;
       i := i+1 >>;
    if d1 then printc "...";
    printc "Comparison failed.";
    if fdiffer then files_with_differences := name . files_with_differences;
  end;

fluid '(which_module);

symbolic procedure check_a_package;
  begin
    scalar oll, names, p1, logname, mylogname, mylog, reflogname, reflog,
           time_data, time_ratio, gc_time_ratio, log_count,
           files_with_differences;
    get_configuration_data();
    if boundp 'which_module and symbol!-value 'which_module and
       not (symbol!-value 'which_module = "") then <<
       names := compress explodec symbol!-value 'which_module;
       if member(names, reduce_test_cases) then names := list names
       else error(0, list("unknown module to check", which_module)) >>
    else names := reduce_test_cases;
% I write a summary of timing information into csllogs/times.log
    time_data := open("testlogs/times.log", 'output);
    p1 := wrs time_data;
    princ "MODULE";
    ttab 21; princ "Local";     ttab 32; princ "(GC)";
    ttab 40; princ "Reference"; ttab 52; princ "(GC)";
    ttab 55; princ "Ratio";     ttab 65; printc "inc GC";
    wrs p1;
    terpri();
    oll := linelength 100;
    printc "=== Comparison results ===";
    time_ratio := gc_time_ratio := 1.0; log_count := 0.0;
    for each packge in names do <<
       terpri();
       princ "CHECKING: "; print packge;
       if boundp '!@log and stringp symbol!-value '!@log then
           logname := symbol!-value '!@log
       else logname := "testlogs";
       mylogname := concat(logname, concat("/", concat(packge, ".rlg")));
       if get(packge,'folder) then p1 := get(packge,'folder)
       else p1 := packge;
       reflogname := concat("$reduce/packages/",
                       concat(p1,
                         concat("/",
                           concat(packge,".rlg"))));
       mylog := errorset(list('open, mkquote mylogname, ''input), nil, nil);
       reflog := errorset(list('open, mkquote reflogname, ''input), nil, nil);
       if errorp mylog then <<
          if not errorp reflog then close car reflog;
          princ "No current log in "; print mylogname >>
       else if errorp reflog then <<
          close car mylog;
          princ "No reference log in "; print reflogname >>
       else <<
          princ "LOGS: "; princ mylogname; princ " "; printc reflogname;
          mylog := car mylog; reflog := car reflog;
          file_compare(mylog, reflog, packge);
          close mylog;
          close reflog >> >>;
     time_data := wrs time_data;
     if not zerop log_count then <<
        time_ratio := expt(time_ratio, 1.0/log_count);
        gc_time_ratio := expt(gc_time_ratio, 1.0/log_count);
        terpri();
        p1 := set!-print!-precision 3;
        princ "Over "; prin log_count; princ " tests the speed ratio was ";
        print time_ratio;
        princ "    (or ";
        prin gc_time_ratio;
        printc " is garbage collection costs are included)";
        set!-print!-precision p1 >>;
     close wrs time_data;
     linelength oll;
     if null files_with_differences then <<
        terpri(); terpri();
        printc "+++++++++++++++++++++++++++";
        printc "+++ All log files match +++";
        printc "+++++++++++++++++++++++++++";
        terpri() >>
     else <<
        terpri(); terpri();
        printc "+++++++++++++++++++++++++++++++";
        printc "+++ The following logs differ:";
        for each x in reverse files_with_differences do <<
           ttab 4; print x >>;
        printc "+++++++++++++++++++++++++++++++";
        terpri() >>;
  end;


faslend;

load!-module 'remake;

<< initreduce();
   date!* := "Bootstrap version";
   preserve('begin, "REDUCE", t) >>;

symbolic;

!#if (and (not (memq 'embedded lispsystem!*)) (not !*savedef))
load!-module 'user;
!#endif

get_configuration_data();

package!-remake2(prolog_file,'support);

package!-remake2('revision,'support);

package!-remake2(rend_file,'support);

package!-remake2('entry,'support);

package!-remake2('smacros,'support);

package!-remake2('remake,'support);


% The next lines have LOTS of hidden depth!  They restart CSL repeatedly
% so that each of the modules that has to be processed gets dealt with in
% a fresh uncluttered environment. The list of modules is fetched from
% a configuration file which must have 3 s-expressions in it. The first
% is a list of basic modules that must be built to get a core version of
% REDUCE. The second list identifies modules that can be built one the core
% is ready for use, while the last list indicates which modules have
% associated test scripts.
%
% when the modules have been rebuild the system does a restart that
% kicks it back into REDUCE by calling begin(). This then continues
% reading from the stream that had been the standard input when this
% job started. Thus this script MUST be invoked as
%           ./csl -obootstrapreduce.img -z buildreduce.lsp
% with the file buildreduce.lsp specified on the command line in the call. It
% will not work if you start csl manually and then do a (rdf ..) [say]
% on buildreduce.lsp.  I told you that it was a little delicate.

!#if !*savedef
% Some switches may be in the utter core and not introduced via the
% "switch" declaration...
for each y in oblist() do
  if flagp(y, 'switch) then <<
     princ "+++ Declaring a switch: ";
     print y >>;
!#endif

get_configuration_data();

build_reduce_modules reduce_base_modules;

% Now I want to do a cold-start so that I can create a sensible
% image for use in the subsequent build steps. This image should not
% contain ANYTHING extraneous.

symbolic restart!-csl nil;

(setq !*savedef (and (null (memq 'embedded lispsystem!*))
                     (zerop (cdr (assoc 'c!-code lispsystem!*)))))
(make!-special '!*noinlines)
(prog (w)
   (setq w (errorset 'noinlines nil nil))
   (setq !*noinlines (and (not (atom w)) (car w)))
   (print (list '!*noinlines 'set 'to !*noinlines)))
(make!-special '!*native_code)
(setq !*native_code nil)

(setq !*backtrace t)

(cond ((and (null !*savedef)
            (null (memq 'embedded lispsystem!*)))
       (load!-module 'user)))

(load!-module 'cslcompat)

(setq !*comp nil)

(load!-module 'module)            % Definition of load_package, etc.

(load!-module 'cslprolo)          % CSL specific code.

(setq loaded!-packages!* '(cslcompat user cslprolo))

(load!-package 'revision)

(load!-package 'rlisp)

(load!-package 'cslrend)

(load!-package 'smacros)

(load!-package 'poly)

(load!-package 'arith)

(load!-package 'alg)

(load!-package 'mathpr)

(cond
   ((modulep 'tmprint) (load!-package 'tmprint)))

(load!-package 'entry)


(setq version!* (compress (cons '!"
  (append
    (explodec "Reduce (Free CSL version, revision ")
    (append (explodec revision!*) (explodec ")"""))))))

(setq date!* (date))

(setq !*backtrace nil)

(initreduce)

(setq no_init_file nil)

% restart-csl re-applied the -D@srcdir=<DIR> -D@reduce=<DIR> command-line
% options and as a consequence the variables !@srcdir and !@reduce will be
% set here. This is perhaps convenient for people who run Reduce with the
% binaries sitting exactly where they where originally built, or at least
% on a computer where the path to the source files used to build Reduce still
% being valid. It would however be a MESS to try to rely on these on (for
% instance) another machine. I had thus considered the line
%          (setq !@csl (setq !@reduce (symbol!-value (gensym))))
% which is intende to unset those variables so leaving things clean. However
% some developers really like to be able to do incremental builds to Reduce
% and so to help them I will leave things as they are and also ensure
% that everything is ready for package!-remake. I am not 100% happy about this
% since I view it as supporting and hence encouraging practises that I count
% as delicate (especially as regards built vs installed Reduce and dependencies
% between modules) so I still HOPE that most people who are developing
% stuff will rebuild Reduce from scratch rather often.

(load!-package 'remake)
(get_configuration_data)

% If the user compiles a new FASL module then I will let it
% generate native code by default. I build the bulk of REDUCE
% without that since I have statically-selected hot-spot compilation
% that gives me what I believe to be a better speed/space tradeoff.

% Oh well, let's change that and disable it by default since at least on
% windows there are problems with windows vs cygwin file-names.

(fluid '(!*native_code))
(setq !*native_code nil)   % The native compilation option that I was
                           % considering at one stage is no longer available.

(preserve 'begin (bldmsg "%w, %w ..." version!* date!*) t)
% Note that (preserve) here arranges to reload the image that it
% creates, and it then runs (begin) the start-up function. This will
% leave us running Reduce in algebraic mode...

%
% See the fairly length comments given a bit earlier about the
% delicacy of the next few lines!
%

symbolic;
no_init_file := t;

load!-module 'remake;

get_configuration_data();

build_reduce_modules reduce_extra_modules;

symbolic;

"**** **** REDUCE FULLY REBUILD **** ****";

% At this stage I have a complete workable REDUCE. If built using a
% basic CSL (I call it "bootstrapreduce" here)  nothing has been compiled into
% C (everything is bytecoded), and it is big because it has retained all
% Lisp source code in the image file. If however I built using a version
% of CSL ("reduce") that did have things compiled into C then these will
% be exploited and the original Lisp source will be omitted from the
% image, leaving a production version.

lisp stop(0);
bye;

