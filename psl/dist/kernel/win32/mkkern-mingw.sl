(load debug)
(off usermode)

(setf *writingasmfile t)
%(reload sys-consts)
(off pcmac)
(off usermode)
(on verboseload)
(load lap-to-asm)
(load win386-asm)
(dskin "foreign.sl")
(setq ExternalDeclarationFormat* " .globl %w%n")
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
(dskin "main-start.sl")  
(dskin "io.sl")
(dskin "intern.sl") 
(dskin "faslin.sl")
(dskin "alloc.sl")
(dskin "support.sl")
(dskin "external.sl")
(dskin "sys-support.sl")
(dskin "../lastkernel.sl")

(print datalabelformat*)
(asmend)
(exitlisp)
