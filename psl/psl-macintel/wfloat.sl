(faslin "wfloat2.b")

(de *fplus2 (x y z)
  (when (eq -1  (uxplus2 x y z)) 
            (stderror "Floating Point Error in fplus2")))

(de *fdifference (x y z)
  (when (eq -1 (uxdifference x y z))
            (stderror "Floating Point Error in fdifference")))


