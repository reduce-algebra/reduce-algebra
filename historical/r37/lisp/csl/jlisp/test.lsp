
(plus 1 2 3)

(defun reverse (a) (rev1 a nil))

'yyy

(defun rev1 (a b)
   (cond
      ((eq a nil) b)
      (t (rev1 (cdr a) (cons (car a) b)))))

'xxx

(reverse '(a b c))

(plus2 101 999)

(defun fact (n)
   (if (equal n 0) 1
        (times n (fact (sub1 n)))))

(fact 100)

(list 1 2 'a 'x)


