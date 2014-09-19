(compiletime% (reload sys-consts)
(off immediatequote)
(reload fasl-decls)
(on plap pcmac)
)

(faslout "cross")
(de codefiletrailer ()
  (prog (s)
        (systemfaslfixup)
        (binarywrite codeout* (idifference (isub1 nextidnumber*) 
					   first-local-id-number))
        % Number of local IDs
        (foreach x in (car orderedidlist*) do
                 (progn (remprop x fasl-idnumber-property*)
                        (setq x (strinf (faslid2string x)))
                        (setq s (strlen x))
			(binarywrite codeout* s)
                        (binarywriteblock codeout* (strbase x)
					  (strpack s))))
        (binarywrite codeout* % S is size in words
                     (setq s
                      (iquotient
                       (iplus2 currentoffset*
                        (isub1 8))
		       8)))
        (binarywrite codeout* initoffset*)
        (binarywriteblock codeout* codebase* (times2  2 s))
        (binarywrite codeout*
                     (setq s
                      (iquotient
                       (iplus2 bittableoffset*
                        (isub1 bittable-entries-per-word))
                       bittable-entries-per-word)))
        (binarywriteblock codeout* bittablebase* (times2 2 s))
	(deallocatefaslspaces)))
(faslend)
