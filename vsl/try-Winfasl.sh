#! /bin/bash -v

./vsl -i Winfasl.img <<XXX | tee try-Winfasl.log

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
(mytrace 'internallycallablep)
(mytrace 'fastcallablep)

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

XXX

