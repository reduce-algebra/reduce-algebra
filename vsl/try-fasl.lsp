(setq *echo t)

(mytrace 'jmp!.!L!T!H)
(mytrace 'jmp!.!I!N!S!T!R)
(mytrace 'mov!.!L!T!H)
(mytrace 'mov!.!I!N!S!T!R)
(mytrace 'op-jump-effa)

(mytrace '*linke)
(mytrace '*jcall)
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
%(mytrace 'mkitem)

(setq *plap t)
(setq *pgwd t)
(setq *testlap t)

(faslout 'foo)

(de arthur (x) "hello")

(faslend)

