(setq *echo t)

%(mytrace 'internallycallablep)
%(mytrace 'fastcallablep)
%(mytrace 'saveentry)
%(mytrace 'depositstring)
%(mytrace 'depositbyte)
(mytrace 'depositwordblock)
(mytrace 'depositquadwordexpression)
(mytrace 'depositword)
(mytrace 'putword)
%(mytrace 'compact-bittable)

%(mytrace 'binarywrite)
%(mytrace 'binarywriteblock)


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

