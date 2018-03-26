(setq *echo t)

(mytrace 'internallycallablep)
(mytrace 'fastcallablep)

(cond ((member 'vsl lispsystem*) (mytrace 'mkitem)))

(setq *plap t)
(setq *pgwd t)
(setq *testlap t)

(faslout 'foo)

(de arthur (x) "hello")

(faslend)

