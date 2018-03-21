#! /bin/bash -v

./vsl -i AMDfasl.img <<XXX | tee try-AMDfasl.log

(setq *echo t)

% This seems to be called at cross-compile time with NIL as the
% second argument. That seems a bit weird to me.

(de mkitem (tag x)
  (cond
    ((null (fixp tag)) (mkitem 0 x))
    ((null (fixp x)) (mkitem tag 0))
    (t (land 16#ffffffffffffffff (lor
         (lsh tag 56)
         (land x 16#00ffffffffffffff))))))

(rdf "mytrace.lsp")

(mytrace 'jmp!.!L!T!H)
(mytrace 'jmp!.!I!N!S!T!R)
(mytrace 'op-jump-effa)

(mytrace '*linke)
(mytrace '*jcall)
(mytrace 'cmacropatternexpand)
(mytrace 'cmacrosubstitute)
(mytrace 'anyregpatternmatch)
(mytrace 'regp)
(mytrace 'upperreg64p)
(mytrace 'depositbyte)
(mytrace 'op-reg-effa)

(setq *plap t)
(setq *pgwd t)
(setq *testlap t)

(faslout 'foo)

(lap '((*entry sample expr 0)
       (*alloc 0)
       (*linke 0 arthur expr 0)
       (mov (reg 1) (reg 2)))


%(faslend)

XXX

