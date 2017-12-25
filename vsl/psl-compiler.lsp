% This tries to build a PSL comopiler...


% copyd is invoked (botimes ..) within the for-macro.sl source file,
% but easy-non-sl.sl uses some macros defined in for-macro. To break the
% circularity I define copyd here.

(de stderror (msg)
  (error 99 msg))

(de copyd (new old)
  (prog (olddef)
        (setq olddef (getd old))
        (if (pairp olddef)
          (putd new (car olddef) (cdr olddef))
          (stderror (bldmsg "%r has no definition in CopyD" old)))
        (return new)))

(de codep (u) nil)

(de ncons (u) (cons u nil))

(dm errorprintf (u)
  (list 'errorprintf1 (cadr u) (cons 'list (cddr u))))

(de errorprintf1 (fmt args)
  (terpri)
  (princ "+++ errorprintf ")
  (princ fmt)
  (princ " ")
  (print args)
  nil) 

% This definition is from nonkernel/loop-macros.sl, but that file contains
% a definition of FOR that clashes with the version that I seem to need (which
% is in util/for-macro.sl).

(dm foreach (u)
  %. Macro for MAP functions
  %
  % From RLISP
  %
  % Possible forms are:
  % (foreach x in u do (foo x))	   --> (mapc u (function (lambda (x) (foo x))))

  % (foreach x in u collect (foo x)) --> (mapcar u ...)
  % (foreach x in u conc (foo x))	   --> (mapcan u ...)
  % (foreach x in u join (foo x))	   --> (mapcan u ...)
  % (foreach x on u do (foo x))	   --> (map u ...)
  % (foreach x on u collect (foo u)) --> (maplist u ...)
  % (foreach x on u conc (foo x))	   --> (mapcon u ...)
  % (foreach x on u join (foo x))	   --> (mapcon u ...)
  %
  (prog (action body fn lst mod var)
        (setq var (cadr u))
        (setq u (cddr u))
        (setq mod (car u))
        (setq u (cdr u))
        (setq lst (car u))
        (setq u (cdr u))
        (setq action (car u))
        (setq body (cdr u))
        (setq fn
              (cond ((eq action 'do) (if (eq mod 'in)
                       'mapc
                       'map))
                    ((or (eq action 'conc) (eq action 'join)) (if (eq mod
                                                                   'in)
                       'mapcan
                       'mapcon))
                    ((eq action 'collect) (if (eq mod 'in)
                       'mapcar
                       'maplist))
                    (t (stderror
                        (bldmsg "%r is an illegal action in ForEach"
                         action)))))
        (return (list fn lst
                      (list 'function
                       (cons 'lambda (cons (list var) body)))))))

(dm on (u)
   (terpri)
   (princ "+++ ON ")
   (print (cdr u))
   nil)

(dm off (u)
   (terpri)
   (princ "+++ OFF ")
   (print (cdr u))
   nil)

(dm lap (u)
   (terpri)
   (princ "+++ LAP ")
   (print (cdr u))
   nil)

(dm imports (u)
   (terpri)
   (princ "+++ IMPORTS ")
   (print (cdr u))
   nil)

(de unboundp (u) (not (boundp u)))

(de dskin (u) (rdf u))

(de pp (x) (prettyprint x))

(de string-concat (a b)
  (setq a (explode a))
  (setq b (explode b))
  (compress (append
    (reverse (cdr (reverse a)))
    (cdr b))))

(de gtbps (n) (mkvect n))

(rdf "../psl/dist/util/defmacro1.sl")
(rdf "../psl/dist/util/defmacro2.sl")
(rdf "../psl/dist/util/set1-macros.sl")
(rdf "../psl/dist/util/set2-macros.sl")
(rdf "../psl/dist/util/iter-macros.sl")
(rdf "../psl/dist/util/for-macro.sl")
(rdf "../psl/dist/nonkernel/easy-non-sl.sl")
(rdf "../psl/dist/nonkernel/sets.sl")

% At least for bootstrapping I need to restore MY vertsion of SPACES
(de spaces (n)                 % Print n blanks.
   (cond
      ((zerop n) nil)
      (t (princ " ") (spaces (sub1 n)))))

% The paths used here suppose that the current directory is the VSL
% one. This is a bit unsatisfactory at present.

(rdf "../psl/dist/nonkernel/carcdr.sl")
(rdf "../psl/dist/nonkernel/def-smacro.sl")
(rdf "../psl/dist/nonkernel/defconst.sl")
(rdf "../psl/dist/nonkernel/constants.sl")


(rdf "../psl/dist/comp/anyreg-cmac.sl")

(rdf "../psl/dist/comp/AMD64_ext/sys-consts.sl")
(rdf "../psl/dist/comp/AMD64_ext/sys-dm.sl")
(rdf "../psl/dist/comp/AMD64_ext/AMD64-lap.sl")
(rdf "../psl/dist/comp/AMD64_ext/AMD64-inst.dat")
%                     (rdf "../psl/dist/comp/AMD64_ext/386-inst.dat")
(rdf "../psl/dist/comp/AMD64_ext/AMD64-cmac.sl")
(rdf "../psl/dist/comp/AMD64_ext/AMD64-comp.sl")
(rdf "../psl/dist/comp/AMD64_ext/AMD64-spec.sl")
(rdf "../psl/dist/comp/AMD64_ext/carcdrnil.sl")
(rdf "../psl/dist/comp/AMD64_ext/compat.sl")
(rdf "../psl/dist/comp/AMD64_ext/comp-dec.sl")
(rdf "../psl/dist/comp/AMD64_ext/comp-decls.sl")
(rdf "../psl/dist/comp/AMD64_ext/compiler.sl")
(rdf "../psl/dist/comp/AMD64_ext/doshooks.sl")
%                     (rdf "../psl/dist/comp/AMD64_ext/fixup386.sl")
%                     (rdf "../psl/dist/comp/AMD64_ext/geninstr.sl")
%                     (rdf "../psl/dist/comp/AMD64_ext/lap-to-asm.sl")
(rdf "../psl/dist/comp/AMD64_ext/unixAMD64-lap-to-asm.sl")
(rdf "../psl/dist/comp/AMD64_ext/muls.sl")
(rdf "../psl/dist/comp/AMD64_ext/muls32.sl")
(rdf "../psl/dist/comp/AMD64_ext/nbittab.sl")
(rdf "../psl/dist/comp/AMD64_ext/neweq.sl")
(rdf "../psl/dist/comp/AMD64_ext/tags.sl")
(rdf "../psl/dist/comp/AMD64_ext/asm.sl")

(rdf "../psl/dist/comp/anyreg-cmac.sl")
(rdf "../psl/dist/comp/bare-psl.sym")
(rdf "../psl/dist/comp/big-faslend.sl")
(rdf "../psl/dist/comp/carcdrnil.sl")
(rdf "../psl/dist/comp/cmacros.sl")
(rdf "../psl/dist/comp/comasm.sl")
(rdf "../psl/dist/comp/datamachine.sl")
(rdf "../psl/dist/comp/faslout.sl")
%                     (rdf "../psl/dist/comp/lap-to-asm.sl")
(rdf "../psl/dist/comp/mingw-w64")
(rdf "../psl/dist/comp/p1-decls.sl")
(rdf "../psl/dist/comp/pass-1.sl")
(rdf "../psl/dist/comp/pass-1-lap.sl")
(rdf "../psl/dist/comp/pass-2-3.sl")
(rdf "../psl/dist/comp/p-lambind.sl")
(rdf "../psl/dist/comp/predicates.sl")
(rdf "../psl/dist/comp/pslcomp.sl")
(rdf "../psl/dist/comp/putprint.sl")

% For utterly cross building I may fudge some things...
(de mkitem (tag data) (list 'list ''tagged tag data))

(preserve)
