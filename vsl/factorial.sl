% This is a file with a test function in to see if I can compile it.

(de factorial (n)
  (if (zerop n)
      1
      (times n (factorial (sub1 n)))))

