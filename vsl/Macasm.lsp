% This builds a PSL compiler that creates textual assembly code files ...

% For VSL the treatment of file-names written as "$xxx/..." is that a Lisp
% variable called "@xxx" is inspected to find the actual path required.

(setq @psl  "../psl/dist")

(setq @psys "../psl/dist/bin/macintel64")

(setq @pl   "../psl/dist/lap/macintel64")

(setq @pk   "../psl/dist/kernel")
(setq @pxk  "../psl/dist/kernel/macintel64")

(setq @pnk  "../psl/dist/nonkernel")
(setq @pxnk "../psl/dist/nonkernel/macintel64")
(setq @pnkl "../psl/dist/nonkernel/macintel64/lap")

(setq @pc   "../psl/dist/comp")
(setq @pxc  "../psl/dist/comp/macintel64")

(setq @pu   "../psl/dist/util")
(setq @pxu  "../psl/dist/util/macintel64")

(setq @pdist   "../psl/dist/distrib")
(setq @pxdist  "../psl/dist/distrib/macintel64")

(rdf "psl-support-1.lsp")

(rdf "$pnk/lisp-macros.sl")

(rdf "$pu/defmacro1.sl")
(rdf "$pu/defmacro2.sl")
(rdf "$pu/set1-macros.sl")
(rdf "$pu/set2-macros.sl")
(rdf "$pu/iter-macros.sl")
(rdf "$pu/for-macro.sl")
(rdf "$pu/cond-macros.sl")
(rdf "$pu/numeric-ops.sl")

(rdf "$pnk/easy-non-sl.sl")
(rdf "$pnk/sets.sl")
%(rdf "$pnk/type-error.sl")

% $pu/if.sl defines an IF macro that uses symbols as keywords THEN, ELIF
% and ELSE. It is coded using the NEXT macro from $pnk/loop-macros.sl, but
% if I load that file then it gives a version of FOR that conflicts with
% $pu/for-macro.sl. So I will provide NEXT manually here - not that I think
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

(de intp (x) (and (fixp x) (not (bignump x))))
(flag '(intp) 'lose)

(de flag1 (x y) (flag (list x) y))

(de remflag1 (x y) (remflag (list x) y))

(dm control (x)
  (list 'logand (list 'char-code (list 'quote (cadr x))) 31))
(dm cntrl (x)
  (list 'logand (list 'char-code (list 'quote (cadr x))) 31))

(de continuableerror (errnum message errorform*)
  (progn (errorprintf "***** %l" message)))

(de main ())

% The paths used here suppose that the current directory is the VSL
% one. This is a bit unsatisfactory at present.

(rdf "$pnk/carcdr.sl")
(rdf "$pnk/def-smacro.sl")
(rdf "$pnk/defconst.sl")
(rdf "$pnk/constants.sl")

(rdf "$pnk/eval-when.sl")

(dm bothtimes (x) (cons 'progn (cdr x)))
(dm compiletime (x) (cons 'progn (cdr x)))
(dm loadtime (x) (cons 'progn (cdr x)))

(rdf "$pc/datamachine.sl")
(rdf "$pc/pass-1.sl")
(rdf "$pc/pass-2-3.sl")
(rdf "$pc/pass-1-lap.sl")


(rdf "$pc/anyreg-cmac.sl")
(rdf "$pc/cmacros.sl")
(rdf "$pc/bare-psl.sym")
(rdf "$pc/big-faslend.sl")
(rdf "$pc/comasm.sl")
(rdf "$pc/p1-decls.sl")
(rdf "$pc/p-lambind.sl")
(rdf "$pc/predicates.sl")
(rdf "$pc/pslcomp.sl")
(rdf "$pc/putprint.sl")


(rdf "$pxc/compat.sl")
(rdf "$pxc/sys-consts.sl")
(rdf "$pxc/sys-dm.sl")
(rdf "$pxc/tags.sl")
(rdf "$pxc/AMD64-lap.sl")
(rdf "$pxc/AMD64-cmac.sl")
(rdf "$pxc/AMD64-comp.sl")
(rdf "$pc/faslout.sl")
(rdf "$pxc/AMD64-spec.sl")
%         (rdf "$pxc/carcdrnil.sl")
(rdf "$pxc/comp-decls.sl")
(rdf "$pxc/compiler.sl")
(rdf "$pxc/nbittab.sl")
(rdf "$pxc/neweq.sl")

% redefine as macros since VSL doesn't support functions with
% a variable number of arguments.
(dm codeprintf (x) (cons 'fprintf (cons 'codeout* (cdr x))))
(dm dataprintf (x) (cons 'fprintf (cons 'dataout* (cdr x))))

(rdf "$pxc/unixAMD64-lap-to-asm.sl")
(rdf "$pxc/unixAMD64-asm.sl")

(rdf "psl-support-2.lsp")

(preserve)

