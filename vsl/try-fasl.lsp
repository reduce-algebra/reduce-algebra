(setq *echo t)

%(mytrace 'depositquadwordexpression)

(setq *plap t)
(setq *pgwd t)
(setq *testlap t)

(load nbittab)
(getd 'codefiletrailer)

(cond
  ((member 'vsl lispsystem*)
   (de putentry (a b c)
     (print (list 'putentry a b c))
     nil)))

(faslout "foo")

(dskin "../psl/dist/comp/pass-2-3.sl")

(faslend)

