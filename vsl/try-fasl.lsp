(setq *echo t)

%(mytrace 'depositquadwordexpression)
%(mytrace 'depositword)
%(mytrace 'depositwordidnumber)

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

(de arthur1 (x) nil)

(de arthur2 (x) x)

(de arthur3 (x) (cadr x))

(de arthur4 (x) (list x x x))

(de arthur5 (x)
   (if (zerop x) 1 (times x (arthur5 (sub1 x)))))

(faslend)

