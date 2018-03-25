#! /bin/bash -v

$O/bin/redpsl <<XXX | tee try-real.log
lisp;
standardlisp();
(setq *echo t)
(load compiler)
(dskin "mytrace.lsp")
(dskin "try-fasl.lsp")
(exitlisp)

XXX
