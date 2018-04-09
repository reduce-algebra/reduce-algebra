#! /bin/bash -v

$O/bin/redpsl <<XXX | tee try-real.log
lisp;
standardlisp();
(setq *echo t)
(dskin "mytrace.lsp")
(dskin "try-fasl.lsp")
(exitlisp)

XXX
mv foo.b realfoo.b

