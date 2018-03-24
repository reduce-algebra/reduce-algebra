#! /bin/bash -v

./vsl -i Macfasl.img <<XXX | tee try-Macfasl.log

(setq *echo t *plap t *pgen t *testlap t)


% This seems to be called at cross-compile time with NIL as the
% second argument. That seems a bit weird to me.

(de mkitem (tag x)
  (cond
    ((null (fixp tag)) (mkitem 0 x))
    ((null (fixp x)) (mkitem tag 0))
    (t (land 16#ffffffffffffffff (lor
         (lsh tag 56)
         (land x 16#00ffffffffffffff))))))

(de put_a_halfword (a b)
  (puthalfword (plus2 codebase* currentoffset*) 0 b))

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
(mytrace 'findidnumber)
(mytrace 'depositwordidnumber)
(mytrace 'put_a_halfword)

(setq *plap t)
(setq *pgwd t)
(setq *testlap t)

(faslout 'foo)
(lap '((*entry sample expr 0)
       (*alloc 0)
       (*linke 0 arthur expr 0)
       (mov (reg 1) (reg 2))))
(faslend)

XXX

