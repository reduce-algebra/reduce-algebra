(setq *echo t)

% First I wish to ensure that all relevant code is loaded!
(faslout "foo") (faslend)

%(mytrace 'depositquadwordexpression)
(mytrace 'codefiletrailer)

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

(remflag '(codefiletrailer) 'lose)

(fluid '(first-local-id-number))
(setq first-local-id-number 2048)


% (de codewritestring (x)
%   (setq x (strinf x))
%   (setq s (strlen x))
%   (binarywrite codeout* s)
%   (binarywriteblock codeout* (strbase x) (strpack s)))

(setq *comp t)

(de codewritestring (x)
  (prog (len w)
    (setq x (explode2 x))
    (setq len (sub1 (length x)))
    (setq w (times 8 (strpack len))) % 8 bytes per word
    (binarywrite codeout* len)
(print (list 'in_codefiletrailer x len w))
    (foreach b in x do (binarywritebyte codeout* (char-code b)))
    (while (lessp (setq len (add1 len)) w)
      (binarywritebyte codeout* 0))))

(cond
  ((null (member 'vsl lispsystem*))
   (de binarywritebyte (str b) (fputc b str))))

(de codefiletrailer ()
  (prog (s len)
        (systemfaslfixup)
        (binarywrite codeout* (idifference (isub1 nextidnumber*)
                                           first-local-id-number))
        % Number of local IDs
        (foreach x in (car orderedidlist*) do
                 (progn (remprop x fasl-idnumber-property*)
                        (codewritestring (faslid2string x))))
        (binarywrite codeout* % S is size in words
                     (setq s
                      (quotient
                       (plus2 currentoffset*
                        (sub1 addressingunitsperitem))
                       addressingunitsperitem)))
        (binarywrite codeout* initoffset*)
        (binarywriteblock codeout* codebase* s)
        (if *compact-bittable
         (let((b (compact-bittable bittablebase* bittableoffset*))
              (bpw (quotient bitsperword 8)))
           (binarywrite codeout*
            (setq s (quotient
                       (plus2 (car b)
                        (sub1 bpw))
                       bpw)))
           (setq b (explode2 (cdr b)))
           (setq len (length b))
           (setq s (times 8 s))
           (foreach b1 in b do
              (binarywritebyte codeout* (char-code b1)))
           (while (lessp (setq len (add1 len)) s)
              (binarywritebyte codeout* 0))

%          (binarywriteblock codeout* (strbase(strinf (cdr b))) s)
         )
         (progn
          (binarywrite codeout*
                     (setq s
                      (quotient
                       (plus2 bittableoffset*
                        (sub1 bittable-entries-per-word))
                       bittable-entries-per-word)))
          (binarywriteblock codeout* bittablebase* s)
        ))
        (deallocatefaslspaces)))




(faslout "foo")

(dskin "../psl/dist/comp/pass-2-3.sl")

(faslend)

