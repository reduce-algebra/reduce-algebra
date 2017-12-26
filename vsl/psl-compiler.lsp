% This tries to build a PSL comopiler...

% For VSL the treatment of file-names written as "$xxx/..." is that a Lisp
% variable called "@xxx" is inspected to find the actual path required.

(setq @psl  "../psl/dist")

(setq @psys "../psl/dist/bin/AMD64_ext")

(setq @pl   "../psl/dist/lap/AMD64_ext")

(setq @pk   "../psl/dist/kernel")
(setq @pxk  "../psl/dist/kernel/AMD64_ext")

(setq @pnk  "../psl/dist/nonkernel")
(setq @pxnk "../psl/dist/nonkernel/AMD64_ext")
(setq @pnkl "../psl/dist/nonkernel/AMD64_ext/lap")

(setq @pc   "../psl/dist/comp")
(setq @pxc  "../psl/dist/comp/AMD64_ext")

(setq @pu   "../psl/dist/util")
(setq @pxu  "../psl/dist/util/AMD64_ext")

(setq @pdist   "../psl/dist/distrib")
(setq @pxdist  "../psl/dist/distrib/AMD64_ext")


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

(dm defun (u) (cons 'de (cdr u)))

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

(de remob (u)
  (terpri)
  (princ "+++ REMOB not performed on ")
  (print u)
  u)

% This definition of totalcopy is probably insufficient...
(de totalcopy (x)
  (copy x))

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


% I will also want IFOR, but the other things defined in util/inum.sl would
% potentially clobber VSL versions of iplus etc.. so I lift the definition
% out to here.

(dm ifor (u)
  % U is of the form: (IFOR (FROM var start end step) (DO body))

  (let ((step (nth (second u) 5)))
    (if (fixp step)
      (constant-increment-ifor u)
      (variable-increment-ifor u)
      )))

(de variable-increment-ifor (u)
  (let* ((var       (second (second u)))
       (start     (third  (second u)))
       (finish    (fourth (second u)))
       (step      (nth    (second u) 5))
       (action    (first (third u)))
       (body      (cons 'progn (cdr (third u))))
       (result    (list (list 'setq var start)))
       (x         (list 'IDIFFERENCE finish var))
       (label1    (gensym))
       (label2    (gensym)))
    (unless (onep step)
      (setf x (list 'ITIMES2 step x))
      )
    (unless (eq action 'DO)
      (stderror "Only do expected in SysLisp FOR")
      )
    `(PROG (,var)
       (SETQ ,var ,start)
       ,label1
       (COND ((ILESSP ,x 0) (GO ,label2)))
       ,body
       (SETQ ,var (IPLUS2 ,var ,step))
       (GO ,label1)
       ,label2
       )))

(de constant-increment-ifor (u)
  (let* ((var       (second (second u)))
       (start     (third  (second u)))
       (finish    (fourth (second u)))
       (step      (nth    (second u) 5))
       (action    (first (third u)))
       (body      (cons 'progn (cdr (third u))))
       (result    (list (list 'setq var start)))
       (comparison(if (minusp step) 'ILESSP 'IGREATERP))
       (label1    (gensym)))
    (unless (eq action 'DO)
      (stderror "Only do expected in SysLisp FOR")
      )
    `(PROG (,var)
       (SETQ ,var ,start)
       ,label1
       (COND ((,comparison ,var ,finish) (RETURN 0)))
       ,body
       (SETQ ,var (IPLUS2 ,var ,step))
       (GO ,label1)
       )))


 

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

(de fboundp (u) (not (null (getd u))))

(de funboundp (u) (null (getd u)))

(de dskin (u) (rdf u))

(de pp (x) (prettyprint x))

(de string-concat (a b)
  (setq a (explode a))
  (setq b (explode b))
  (compress (append
    (reverse (cdr (reverse a)))
    (cdr b))))

(de gtbps (n) (mkvect n))

(rdf "$pu/defmacro1.sl")
(rdf "$pu/defmacro2.sl")
(rdf "$pu/set1-macros.sl")
(rdf "$pu/set2-macros.sl")
(rdf "$pu/iter-macros.sl")
(rdf "$pu/for-macro.sl")

(rdf "$pnk/easy-non-sl.sl")
(rdf "$pnk/sets.sl")

% $pu/if.sl defines an IF macro that uses symbols as keywords THEN, ELIF
% and ELSE. It is coded using the NEXT macro from $pnk/loop-macros.sl, but
% if I load that file then it gives a version of FOR that conflicts with
% $pu/for-macro.sl. So I will provide BEXT manually here - not that I think
% that use of it was a good idea!

(dm next (u)  % Continue Loop
  '(go $loop$))

(rdf "$pu/if.sl")

(rdf "$pu/if-system.sl")

% At least for bootstrapping I need to restore MY version of SPACES
(de spaces (n)                 % Print n blanks.
   (cond
      ((zerop n) nil)
      (t (princ " ") (spaces (sub1 n)))))

% The paths used here suppose that the current directory is the VSL
% one. This is a bit unsatisfactory at present.

(rdf "$pnk/carcdr.sl")
(rdf "$pnk/def-smacro.sl")
(rdf "$pnk/defconst.sl")
(rdf "$pnk/constants.sl")


(rdf "$pc/anyreg-cmac.sl")
(rdf "$pc/cmacros.sl")
(rdf "$pc/datamachine.sl")
(rdf "$pc/bare-psl.sym")
(rdf "$pc/big-faslend.sl")
%                     (rdf "$pc/carcdrnil.sl")
(rdf "$pc/comasm.sl")
(rdf "$pc/faslout.sl")
(rdf "$pc/p1-decls.sl")
(rdf "$pc/pass-1.sl")
(rdf "$pc/pass-2-3.sl")
(rdf "$pc/p-lambind.sl")
(rdf "$pc/predicates.sl")
(rdf "$pc/pslcomp.sl")
(rdf "$pc/putprint.sl")
(rdf "$pc/pass-1-lap.sl")
%                     (rdf "$pc/lap-to-asm.sl")


(rdf "$pxc/compat.sl")
(rdf "$pxc/sys-consts.sl")
(rdf "$pxc/sys-dm.sl")
(rdf "$pxc/tags.sl")
(rdf "$pxc/AMD64-cmac.sl")
(rdf "$pxc/AMD64-lap.sl")
%                     (rdf "$pxc/AMD64-inst.dat")
%                     (rdf "$pxc/386-inst.dat")
(rdf "$pxc/AMD64-comp.sl")
(rdf "$pxc/AMD64-spec.sl")
(rdf "$pxc/carcdrnil.sl")
(rdf "$pxc/comp-decls.sl")
(rdf "$pxc/compiler.sl")
%                     (rdf "$pxc/doshooks.sl")
%                     (rdf "$pxc/fixup386.sl")
%                     (rdf "$pxc/geninstr.sl")
%                     (rdf "$pxc/lap-to-asm.sl")
(rdf "$pxc/muls.sl")
(rdf "$pxc/muls32.sl")
(rdf "$pxc/nbittab.sl")
(rdf "$pxc/neweq.sl")
(rdf "$pxc/unixAMD64-asm.sl")
(rdf "$pxc/unixAMD64-lap-to-asm.sl")

% For utterly cross building I may fudge some things...
(de mkitem (tag data) (list 'list ''tagged tag data))

(preserve)

