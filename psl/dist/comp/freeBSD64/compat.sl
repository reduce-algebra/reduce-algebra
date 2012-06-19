% Compat.sl.  Useful definitions for Reduce PSL versions.

% Author: Winfried Neun.

(compiletime
 (progn
 (load defmacro bind-macros strings backquote)
 (defmacro def-pass-1-reform (name args . body)
   (let ((fcn-name (intern (string-concat "PA1R-" (id2string name)))))
     `(progn
       (put (quote ,name) (quote pass-1-reform) (quote ,fcn-name))
       (defmacro ,fcn-name ,args ,@body)
       )))
))

(def-pass-1-reform digit (u)
	 `((lambda ( ($local $$x$$)) (eq (quote 1) (field 
                      (wand (wdifference (quote 8#057) 
			(field ($local $$x$$) ',infstartingbit ',infbitlength))
                            (wdifference
			(field ($local $$x$$) ',infstartingbit ',infbitlength)
					 (quote 8#072)))
                                 '0 '1))) ,u))

(def-pass-1-reform orderp (u v)
	 `(not (wgreaterp (field ,u ',infstartingbit ',infbitlength)
			  (field ,v ',infstartingbit ',infbitlength))))

(def-pass-1-reform flagp** (u v)
          `(flagp ,u ,v))

(def-pass-1-reform terminalp ()
    '(and ($fluid !*int) (null ($fluid ifl!*))))

(def-pass-1-reform liter (u)
  `((lambda (($local &u&) ($local &infu&))
    (eq '0 (wor (wxor 
		  (field ($local &u&) ',tagstartingbit ',infstartingbit) ',id-tag)
               (wshift
                  (wand (wor (wdifference ($local &infu&) '8#141) % a
                             (wdifference '8#172 ($local &infu&))) % z
                        (wor (wdifference ($local &infu&) '8#101) % A
                             (wdifference '8#132 ($local &infu&))) % Z
                   ) '-31)))) ,u (field ,u ',infstartingbit ',infbitlength)))

(def-pass-1-reform   length (u)
   %  length (length (explode x)) -> (flatsize x)

   (when (eqcar  u 'explode) `(flatsize ,(cadr u))))

(def-pass-1-reform   lengthc (u)
	`(flatsize2 ,u))

(compiletime
 (defmacro def-pass-1-macro (name args . body)
   (let ((fcn-name (intern (string-concat "PA1M-" (id2string name)))))
     `(progn
        (put (quote ,name) (quote pass-1-macro) (quote ,fcn-name))
        (defmacro ,fcn-name ,args ,@body)
    ))))

(def-pass-1-macro  flagpcar (u v)
  `((lambda (&&u&&)
    (and (null (atom &&u&&))
         (idp (car  &&u&&))
         (flagp (car &&u&&) ,v) )) ,u ))

(def-pass-1-macro lispapply(w v)
 `((lambda(&&u&&)
   (cond ((not (atom &&u&&)) 
          (rerror 'rlisp '2 (list '"Apply called with non-id arg" &&u&&)))
        (t (apply &&u&& ,v)))) ,w))


(def-pass-1-reform   apply1(u v)
        `(apply ,u (list ,v)))

(def-pass-1-reform   apply2(u v w)
        `(apply ,u (list ,v ,w)))

(def-pass-1-reform   apply3(u v w x) 
        `(apply ,u (list ,v ,w ,x)))

(def-pass-1-reform lispeval (u) `(eval ,u))
