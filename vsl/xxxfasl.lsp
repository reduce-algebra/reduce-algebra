% This builds a PSL compiler that creates binary FASL files ...

% For VSL the treatment of file-names written as "$xxx/..." is that a Lisp
% variable called "@xxx" is inspected to find the actual path required.

(rdf "psl-support-1.lsp")

(setq @psl  "../psl/dist")

(setq @psys (bldmsg "../psl/dist/bin/%w" machine))

(setq @pl   (bldmsg "../psl/dist/lap/%w" machine))

(setq @pk   "../psl/dist/kernel")
(setq @pxk  (bldmsg "../psl/dist/kernel/%w" machine))

(setq @pnk  "../psl/dist/nonkernel")
(setq @pxnk (bldmsg "../psl/dist/nonkernel/%w" machine))
(setq @pnkl (bldmsg "../psl/dist/nonkernel/%w/lap" machine))

(setq @pc   "../psl/dist/comp")
(setq @pxc  (bldmsg "../psl/dist/comp/%w" machine))

(setq @pu   "../psl/dist/util")
(setq @pxu  (bldmsg "../psl/dist/util/%w" machine))

(setq @pdist   "../psl/dist/distrib")
(setq @pxdist  (bldmsg "../psl/dist/distrib/%w" machine))

(setq totalbytes 800000)

(global '(memory))
(upbv (setq memory (mkvect (quotient totalbytes 8))))
(dotimes (i (add1 (quotient totalbytes 8))) (putv memory i 0))

(global '(heapupperbound heaplowerbound heaplast heaptrapbound heaplast
          heaptrapped nextbps lastbps))

% I set up the simulated memory so half is for BPS and half is for heap.

(setq lastbps (quotient totalbytes 2))
(setq nextbps 0)
(setq heapupperbound (setq highpointer totalbytes))
(setq lowpointer lastbps)

(setq heaplast lowpointer)
(setq heaptrapbound (sub1 highpointer))



(rdf "$pnk/lisp-macros.sl")

(rdf "$pu/defmacro1.sl")
(rdf "$pu/defmacro2.sl")
(rdf "$pu/set1-macros.sl")
(rdf "$pu/set2-macros.sl")
(rdf "$pu/iter-macros.sl")
(rdf "$pu/for-macro.sl")
(rdf "$pu/cond-macros.sl")
(rdf "$pu/numeric-ops.sl")

(rdf "$pnk/def-smacro.sl")
(rdf "$pnk/easy-non-sl.sl")
(rdf "$pnk/compsupport.sl")

(rdf "$pu/sys-macros.sl")

(rdf "$pnk/sets.sl")

%(rdf "$pnk/type-error.sl")

(rdf "$pu/if.sl")

(rdf "$pu/if-system.sl")


(rdf "$pnk/carcdr.sl")
(rdf "$pnk/defconst.sl")
(rdf "$pnk/constants.sl")

(rdf "$pnk/eval-when.sl")

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

(cond
  ((equal machine "AMD64_ext") (setq machine1 "AMD64"))
  (t (setq machine1 machine)))

(rdf "$pxc/compat.sl")
(rdf "$pxc/sys-consts.sl")
(rdf "$pxc/sys-dm.sl")
(rdf "$pxc/tags.sl")
(rdf (bldmsg "$pxc/%w-lap.sl" machine1))
(rdf (bldmsg "$pxc/%w-cmac.sl" machine1))
(rdf (bldmsg "$pxc/%w-comp.sl" machine1))
(rdf "$pc/faslout.sl")
(rdf (bldmsg "$pxc/%w-spec.sl" machine1))

%         (rdf "$pxc/carcdrnil.sl")

(rdf "$pxc/comp-decls.sl")
(rdf "$pxc/compiler.sl")
(rdf "$pxc/nbittab.sl")
%(rdf "$pxc/neweq.sl")    % THIS ONE IS NOT WANTED, AND BREAKS THINGS
(rdf "$pxc/fixup386.sl")  % The name here is worrying.

(rdf "$pxnk/sys-faslin.sl")
% (rdf "$pxu/compat.sl")    % HMMM worry re assoc expansion here
(rdf "compat.sl")           % .. so use my private version

(global '(totalbytes))

(preserve)
