(setq *echo t)

(mytrace 'internallycallablep)
(mytrace 'fastcallablep)
(mytrace 'saveentry)
(mytrace 'codewritestring)
(mytrace 'depositstring)
(mytrace 'depositbyte)
(mytrace 'depositwordblock)
(mytrace 'depositquadwordexpression)
(mytrace 'depositword)
(mytrace 'word)
(mytrace 'putword)
(mytrace 'wputv)

'(cond
  ((member 'vsl lispsystem*)
   (mytrace 'mkitem)
   (mytrace 'getfcodepointer))
  (t
   (copyd 'gfcp 'getfcodepointer)
   (setq *comp t)
   (de gfcp1 (u)
     (print 'getfcodepointer)
     (print u)
     (setq u (gfcp u))
     (print u)
     u)
   (setq a (getd 'gfcp1))
   (putd 'getfcodepointer 'expr (cdr a))))

(setq *plap t)
(setq *pgwd t)
(setq *testlap t)

(de putentry (a b c)
  (print (list 'putentry a b c))
  nil)

(faslout 'foo)

(de arthur (x) "hello")

(faslend)

