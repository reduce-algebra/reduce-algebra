%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PU:QUALIFIED-COUNTING.SL
% Description:    counting function execution with callers ref.
% Author:         Herbert Melenk and Winfried Neun, ZIB Berlin
% Created:        5 September 1986
% Status:         Experimental (Do Not Distribute), CRAY version only
% Mode:           Lisp
% Package:        Utilities
%
% Copyright (c) 1987, Konrad Zuse Zentrum Berlin, all rights reserved
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
(cond ((not (getd 'priv-equal)) (copyd 'priv-equal 'equal)))
(cond ((not (getd 'priv-get))   (copyd 'priv-get 'get)))
(cond ((not (getd 'priv-put))   (copyd 'priv-put 'put)))

(de priv-assoc (u v)
  %. Return first (U . xxx) in V, or NIL
  (cond ((not (pairp v)) nil)
        ((and (pairp (car v)) (priv-equal u (caar v))) (car v))
        (t (priv-assoc u (cdr v)))))
 
(imports '(compiler addr2id))
 
(on comp)
 
(dm qualcount (u)
  (mapc (cdr u) (function qualcount1)))

(de qualcount1 (u)
  (let ((name (intern (gensym)))(name2 (intern (gensym))))
   (if (null (getd u)) (printf "*** Function not defined : %w %n" u)
    (eval
     `(progn
       (copyd ',name ',u)
       (de ,name2 (x1 x2 x3 x4 x5 x6 x7 x8 x9 x10 x11 x12 x13 x14 x15)
          (prog (retadr countpos)
           (setq retadr (inf (quallap)))
           (setq countpos (priv-assoc retadr (priv-get ',u 'qualcount)))
           (cond (countpos
                    (rplacd countpos (wplus2 1 (cdr countpos))))
                 (t (priv-put ',u 'qualcount
                         (cons (cons retadr 1)
                            (priv-get ',u 'qualcount)))))
           (return (,name x1 x2 x3 x4 x5 x6 x7 x8 x9 x10 x11 x12 x13
                       x14 x15))
        )  )
        (compile (list ',name2))
        (copyd ',u ',name2)
) ))))
 
(put 'quallap 'opencode '((*move (reg returnaddr) (reg 1))))
 
(fluid '(*bordervalue*))
 
(setq *bordervalue* 20)
 
(dm print-qualcount (u) (mapobl (function print-qualcount1)))

(de print-qualcount1 (r)

    (unless (priv-get r 'qualcount) (return nil))
    (prog (x)
      (prin2 "************* calls for function ")
      (prin2  r)
      (prin2t " ************* ")
      (setq x (priv-get r 'qualcount))
   aa
      (when ( null x) (return (terpri)))
      (when (wgreaterp (cdar x) *bordervalue*)
        (terpri)
        (prin2 "number of calls : ") (prin2 (cdar x))
        (prin2 " from ")
        (prin2t (code-address-to-symbol (inf (caar x)))))
      (setq x (cdr x))
      (go aa)
)   )
 
(de reset-qualcount() (mapobl (function (lambda (x)
					(remprop x 'qualcount)))))
 
(prin2t "use (qualcount function function ...), (print-qualcount)")
(prin2t "and (reset-qualcount)")
(prin2t "use *bordervalue* as level for printing")
