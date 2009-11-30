(off usermode)

(setf *writingasmfile t)
%(reload sys-consts)
(off pcmac)
(off usermode)
(on verboseload)
(load lap-to-asm)
(load winnt-asm)
(dskin "foreign.sl")
(dskin "bittable.sl")

(de fastcallablep(x) nil)

(put 'symval 'symbol '!s!y!m!v!a!l_)
(put 'putw   'symbol '__!p!u!t!w)
(put 'getw   'symbol '__!g!e!t!w)    

(setq *mainfound t)
       
(load hash-decls f-strings fasl-decls)

(de continuableerror(a b c)
   (print (list "ERROR:" a b c))
   (quit))

(asmout "main")
(dskin "../firstkernel.sl")
(dskin "main-sta.sl")  
(dskin "io.sl")
(dskin "intern.sl") 
(dskin "faslin.sl")
(dskin "alloc.sl")
(dskin "support.sl")
(dskin "external.sl")
(dskin "sys-supp.sl")
(dskin "../lastkernel.sl")

(asmend)
(exitlisp)
