#! /bin/bash -v

$O/bin/redpsl <<XXX | tee try-real.log
lisp;
standardlisp();
(setq *echo t *plap t *pgen t *testlap t)
(load compiler)
(rdf "mytrace.lsp")

(mytrace 'jmp!.!L!T!H)
(mytrace 'jmp!.!I!N!S!T!R)
(mytrace 'mov!.!L!T!H)
(mytrace 'mov!.!I!N!S!T!R)
(mytrace 'op-jump-effa)

(mytrace '*linke)
(mytrace '*jcall)
%(mytrace 'cmacropatternexpand)
%(mytrace 'cmacrosubstitute)
%(mytrace 'anyregpatternmatch)
(mytrace 'regp)
(mytrace 'upperreg64p)
(mytrace 'depositbyte)
(mytrace 'op-reg-effa)
(mytrace 'findidnumber)
(mytrace 'shortlabelp)
(mytrace 'indirectadrp)
(mytrace 'adrp)
(mytrace 'reg-5-prefix)
(mytrace 'modr/m)
(mytrace 'indexed-reg-5-p)
(mytrace 'reg2int)

(setq *plap t)
(setq *pgwd t)
(setq *testlap t)

(faslout 'foo)

%(lap '((*entry sample expr 0)
%       (*alloc 0)
%       (*linke 0 arthur expr 0)
%       (mov (reg 1) (reg 2))))

(de arthur (x) "hello")

(faslend)
(exitlisp)

XXX
