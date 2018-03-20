#! /bin/bash -v

$O/bin/redpsl <<XXX | tee try-real.log
lisp;
standardlisp();
(setq *echo t *plap t *pgen t *testlap t)
(load compiler)
(rdf "mytrace.lsp")

(mytrace 'jmp!.!L!T!H 2)
(mytrace 'jmp!.!I!N!S!T!R 2)
(mytrace 'op-jump-effa 2)

(faslout 'fee)
(de bar (x) "hello")
(faslend)
(exitlisp)
XXX
