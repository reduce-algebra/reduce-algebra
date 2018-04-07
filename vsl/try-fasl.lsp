(setq *echo t)

%(mytrace 'internallycallablep)
%(mytrace 'fastcallablep)

(setq *plap t)
(setq *pgwd t)
(setq *testlap t)

(cond
  ((member 'vsl lispsystem*)
   (de putentry (a b c)
     (print (list 'putentry a b c))
     nil)))

(faslout 'foo)

(de arthur (x) "hello")

(faslend)

