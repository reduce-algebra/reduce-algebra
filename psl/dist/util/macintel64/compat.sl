% Compat.sl.  Useful definitions for Reduce PSL versions.

% Author: Winfried Neun, Herbert Melenk.

(compiletime (load if-system))

(compiletime
 (progn
 (load defmacro bind-macros strings backquote)
 (defmacro def-pass-1-reform (name args . body)
   (let ((fcn-name (intern (string-concat "pa1r-" (id2string name)))))
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

(def-pass-1-reform flagp** (u v)
	  `(flagp ,u ,v))

(def-pass-1-reform terminalp ()
    '(and ($fluid !*int) (eq ($fluid ifl!*) (quote nil))))

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
   %    else check in line for a short list:
   %  most length arguments in REDUCE have 1, 2 or 3 elements.
   (if (eqcar  u 'explode) 
      `(flatsize ,(cadr u))
      `((lambda (($local &u&))
         (cond ((not (pairp ($local &u&))) 
                      (quote 0))
               ((not (pairp (setq ($local &u&) (cdr ($local &u&))))) 
                      (quote 1))
               ((not (pairp (setq ($local &u&) (cdr ($local &u&))))) 
                      (quote 2))
               ((not (pairp (setq ($local &u&) (cdr ($local &u&))))) 
                      (quote 3))
               ((quote t) (wplus2 (quote 3)(length ($local &u&))))))
        ,u)))

(def-pass-1-reform   length (u)
   %  length (length (explode x)) -> (flatsize x)
   %    else check in line for a short list:
   %  most length arguments in REDUCE have 1, 2 or 3 elements.
   (if (eqcar  u 'explode) 
     `(flatsize ,(cadr u))
      (let ((lab1 (gensym))(lab2 (gensym)))
       `(prog (($local &u&)($local &n&))
         (setq ($local &u&) ,u)
         (setq ($local &n&) (quote 0))
     ,lab1
         (cond ((pairp ($local &u&)) (go ,lab2)) 
               ((quote t) (return ($local &n&))))
     ,lab2
         (setq ($local &u&) (cdr ($local &u&)))
         (setq ($local &n&) (wplus2 (quote 1)($local &n&)))
         (go ,lab1)))))
                    

(def-pass-1-reform   lengthc (u)
	`(flatsize2 ,u))

(compiletime
 (defmacro def-pass-1-macro (name args . body)
   (let ((fcn-name (intern (string-concat "pa1m-" (id2string name)))))
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

(def-pass-1-reform   aeval (u)
   %  make (aeval (list ...)) static where possible

   (when (and  (pairp u) 
		(memq (car u) '(cons xcons ncons 
				list1 list2 list3 list4 list5 list)))
	 `(aeval ,(static_aeval_list u))))

(def-pass-1-reform   aeval* (u)
   %  make (aeval (list ...)) static where possible

   (when (and  (pairp u)
		(memq (car u) '(cons xcons ncons
				list1 list2 list3 list4 list5 list)))
	 `(aeval* ,(static_aeval_list u))))

(def-pass-1-reform forall (u)
   %  make (forall  (list ...)) static where possible

   (when (and (pairp u)
		(memq (car u) '(cons xcons ncons
				list1 list2 list3 list4 list5 list)))
	 `(forall ,(static_aeval_list u))))

(def-pass-1-reform !~let (u)
   %  make (!~let  (list ...)) static where possible

   (when (and (pairp u)
		(memq (car u) '(cons xcons ncons
				list1 list2 list3 list4 list5 list)))
	 `(!~let ,(static_aeval_list u))))

(de static_aeval_list (x)
  (prog (l1 l2 l3)
    (setq l3 (setq l1 
	(mapcar (cdr x) 
	     (function (lambda (xx)
		(cond ((and (pairp xx)
				 (memq (car xx)
				  '(cons ncons xcons list1 list2 list3 list4
				   quote list5 list !~let )))
					 (static_aeval_list xx))
				(t xx)))))))
    (while (pairp l1)
	(cond   ((numberp (car l1)) (setq l2 (cons (car l1) l2)))
		((and (pairp (car l1)) (eqcar (car l1) 'Quote))
				(setq l2 (cons (cadar l1) l2)))
		(t  (setq l1 (cons 17 17)))) % break the loop
	(setq l1 (cdr l1)))
    
    (return (if (null l1)
	  (cond ((eqcar x 'cons) (list 'quote (cons (cadr l2) (car l2))))
		((eqcar x 'ncons) (list 'quote (ncons (car l2))))
		((eqcar x 'xcons) (list 'quote (cons  (car l2)  (cadr l2))))
		((eqcar x '!~let) (list '!~let (cons 'quote (reversip l2))))
		((eqcar x 'quote) 
			 (if (numberp (car l2)) (list 'quote (car l2))
				 (list 'quote  (list 'quote (car l2)))))
		(t (list 'quote (reversip l2))))
	  (cons (car x) l3)))))

%%%%%%%%%%%%%%%% replace assoc by calls to the faster assoc* if
% assoc* is available and if we know that the list is a list of pairs.
% HM

(def-pass-1-reform   assoc (item list)
  % Try to turn ASSOC into ATSOC
  % NOTE: This function assumes that a constant list given to ASSOC is
  %       really an association list.
  % Additionally we insert a NULL test in the calling code because
  % the majority of REDUCE's calls to assoc have an empty list.

  (cond ((or (eval-eq-able? item)
	    (and (constant? list)
		 (for (in item (constant-value list))
		      (always (eq-able? (car item)))
		      )))
	`(atsoc ,item ,list))
	((and (getd 'assoc*)
	       % the following are known to be proper a-lists
	      (or (equal list '(car ($fluid alglist*)))
		  (equal list '(cdr ($fluid alglist*)))))
	 (mkassocform `(assoc* ,item ($local !&uhu)) 
		      '($local !&uhu) 
		      list))
	(t (mkassocform `(assoc ,item ($local !&uhu)) 
		      '($local !&uhu) 
		       list))
    ))

(de mkassocform(form name list)
   `((lambda (,name)
       (cond ((eq ,name (quote nil)) (quote nil))
	     ((quote t) ,form))) ,list))

%%%%%%%%%%%%%%%% optimize (NULL (AND ...))  (NULL (OR ...))
%  Note that pa1m-null is applied before pa1r-null. Both have a
%  different job.
%  this code should finally go to $pc/pass-1.sl
%HM

(def-pass-1-macro   null (u)
  % (NULL (and a b ...)) -> (or (null a)(null b) ...)
  % (NULL (or a b ...))  -> (and (null a)(null b) ...)
 (cond ((not (pairp u)) nil)
       ((or (eq (car u) 'and) (eq (car u) 'or))
	 (cons (if (eq (car u) 'and) 'or 'and)
	       (mapcar (cdr u)(function(lambda(w) (list 'null w) )))))
       (t nil)))

%%%%%%%%%%%%%%%% decompose (MEMQ a '(b ....)) into (or (eq a 'b)....) in tests
% this option should go to pass-2-3.sl
% HM

(put 'memq 'opentst '&tstmemq)

(de &tstmemq(form lab)
  (let ((x (cadr form)) (l (caddr form)))
  (if (and (eqcar l 'quote) (pairp (cadr l)) (pairp x) (memq (car x) '($local $fluid $global)))
         % decompose memq with constant list
      (&tstandor (cons 'or 
                     (foreach y in (cadr l)
                           collect (list 'eq x (mkquote y))))
                 lab)
         % compile ordinary call embedded in NEQ.
      (&comtst (list 'neq form ''nil) lab))))

  
% Generate .lap file for a module that is flagged LAP. 
% HM.
% A load command for the lap file is compiled to the current .b fasl file.
% The name of the lap file is built from the module name and an underscore to 
% avoid name conflicts at load time, if the REDUCE module name and
% the LISP fasl name are identical.

% PSL compiler fluids:

(fluid '(dfprint* modulename* *writingfaslfile))

% local fluids:

(fluid '(sl-file* this-module*))

(put 'module 'faslpreeval 'module-fasl)

(de module-fasl(u loadtime)
  (cond((not loadtime)(saveuncompiledexpression u)))
  (cond((and *writingfaslfile 
             (not loadtime)
             (flagp (car(setq u(eval (cadr u)))) 'lap))
   (prog (name !*lower x w)
      (setq this-module* u)
      (setq !*lower t)
           % Create a file name with the prefixes of the faslout name
           % and an extension "lap".
      (setq name (reversip (explode2 modulename!*)))
 a    (cond((and name (not (memq (car name) '(!/ !\))))
            (setq name (cdr name))
            (go a)))
      (setq w (explode2 (car u)))
      (setq w (cond ((lessp (length w) 8) (cons '!_ w))
                    ((setq x(intersection '(!e !a !i !o !u) w))
                     (subst '!_ (car x) w))
	            (t (stderror (bldmsg "cannot create lap file name for %w"
                                       (car u))))))
      (setq this-module* (compress w))
      (setq name (compress 
                 (cons'!" (append(reversip name)
                                 (append w (explode2 '!.lap!"))))))
      (setq sl!-file!* (open name 'output))
      (printf "%n creating LISP load file %w%n" name)
      (setq dfprint!* 'sl!-out)
))))
   
(de sl!-out(x)
  (cond ((equal x '(endmodule))
         (close sl!-file!*) 
         (setq sl!-file!* nil)
         (saveuncompiledexpression (list 'load this-module*))
         (saveuncompiledexpression '(endmodule))
         (setq dfprint!* 'dfprintfasl)
   	 )
        ((atom x) nil)
        ((flagp (car x) 'eval)
         (eval x)
         (channelprint sl!-file!* x))
        (t (channelprint sl!-file!* x)) ))

