
(setq addressingunitsperitem 4)

(de binarywrite (channel n)
  (putw n channel))
 
(de binarywriteblock (channel blockbase blocksize)
  (fwrite blockbase 4 blocksize channel))

(compiletime
(load fasl-decls fast-vector)
)

(ds MyStrPack (upperbound) 
  % Returns the number of items required to store a string, including
  % the one-item header.  Note that indexing starts at zero, and all
  % strings have a trailing zero byte.  Thus, a string with an upper
  % bound of 3 will require 5 bytes of storage past the header.
  (wquotient (wplus2 upperbound
                     (wplus2 4 1)
                     )
             4
             ))

(fluid '(*writingfaslfile
         *lower
         *quiet_faslout
         dfprint*
         uncompiledexpressions*
         modulename*
         codeout*
         initoffset*
         currentoffset*
         faslblockend*
         maxfasloffset*
         bittableoffset*
         faslfilenameformat*
         fasl-idnumber-property*
         ))

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
                                          (mystrpack s))))
        (binarywrite codeout* % S is size in words
                     (setq s
                      (iquotient
                       (iplus2 currentoffset*
                        (isub1 4))
                       4)))
        (printf "code size is %d/%x%n" s s)
        (printf "initoffset is %d/%x%n" initoffset* initoffset*)
        (binarywrite codeout* initoffset*)
        (binarywriteblock codeout* codebase* s)
        (binarywrite codeout*
                     (setq s
                      (iquotient
                       (iplus2 bittableoffset*
                        (isub1 bittable-entries-per-word))
                       bittable-entries-per-word)))
        (printf "bittable size is %d/%x%n" s s)
        (binarywriteblock codeout* bittablebase* s)
        (deallocatefaslspaces)))

