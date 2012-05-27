%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%   MAKE.SL
%
%   PSL based UNIX style make utility for MS-DOS
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load chars))
 
(fluid '(lastchar igno lpar rpar))
(setq igno 13 lpar '!( rpar '!) )

(fluid '(variables objects done actual commands))

(de make(obj)
  (prog(fi ci fo co *raise)
   (setq lastchar nil)
   (when (not (filep "Makefile"))
	 (prin2t "***** make: Makefile not found")
	 (exitlisp) )
   (setq fi (open "Makefile" 'input))
   (setq ci (rds fi))
   (make!-read)
   (rds ci)
   (close fi)
   (setq *raise t)
   (when (or (not(stringp obj)) (equal obj "")) 
	 (setq obj "all"))
   (make!-it (explode2 obj))
   (setq fo (open "dofile.bat" 'output))
   (setq co (wrs fo))
   (make!-write)
   (wrs co)
   (close fo)
   ))
 
(de read!-lin()
   (prog (u v)
   next
     (setq v (read!-item))
     (cond ((eq (inf (caar v)) (char eol))
	    (return u))
	   ((eofp (caar v)) (return v)))
     (when (or (null u) (not (eq (inf (caar v)) (char tab))))
	   (setq u (append u v)))
     (go next) ))

(de read!-item()
   (prog (u c prevchar)
  pre
     (setq c (or lastchar (readch)))
     (setq lastchar nil)
     (when (eofp c) (return (list (list c))))
     (cond
       ((eq (inf c) igno) (go pre))
       ((and (eq c '! ) (null u))(go pre))
       ((eq c '!\) 
	(setq c (readch))
	(cond ((eq (inf c) igno) (readch) t)                % skip 2 chars
	      ((eq (inf c) (char eol)) t)                   % skip 1 char
	      (t (setq u (cons '!\ u)) (setq lastchar c)))  % skip 0 char
	(go pre))
       ((or (digit c)
	    (liter c)
	    (memq c '(!/ !. !( !) !$ !- !_) ))
	  (setq u (cons c u))
	  (setq prevchar c)
	  (go pre) )
       ((and (or (eq prevchar 'c) (eq prevchar '!c))
	     (eq c '!:))                                    % case c:
	  (setq u (cons c u))
	  (setq prevchar nil)
	  (go pre) )
	    % offenbar Trenner
       (u (setq lastchar c))
       (t (setq u (list c))) )
     (return (reform (reversip u))) ))
  
(de read-skip()
   (cond ((eq (inf (readch)) (char eol)) t)
	 (t (read-skip)) ))

(de reform(u)
   (prog (r v s)
 lp   (cond((null u)(return (list (reversip r)))))
      (cond ((and (eq (car u) '!$)
		  (cdr u)
		  (eq (cadr u) lpar ) )
	     (go var) ))
      (setq r (cons (car u) r))
      (setq u (cdr u))
      (go lp)
 var
      (setq v nil u (cddr u))
 lpv  (cond ((eq (car u) rpar) (go var1)))
      (setq v (cons (car u) v))
      (setq u (cdr u))
      (go lpv)
 var1 (setq v (reversip v))
      (setq s (assoc v variables))
      (when (null s)
	 (setq s (getenv (compress (reversip (cons '!" (reverse (cons '!" v)))))))
	 (when s (setq s (list v (explode2 s)))
		 (setq variables (cons s variables)) )
      )
      (cond ((null s)
	     %%%%%% (make!-error (list "variable fehlt" v))
	     (setq s '(nil (! ) ))
	    ))
      (setq u (cdr u))
      (setq r (append (reversip r) (append (cadr s) u)))
      (return (append (reform r) (cddr s)))  ))

(de make-read()
   (prog (u)
  line
     (setq u (read!-lin))
     (cond ((null u) (go line))
	   ((eofp (caar u)) (return nil))
	   ((eq (caar u) '!#) (go line))
	   ((eq (caadr u) '=) (make!-setq (car u)(cddr u)))
	   ((eq (inf (caar u)) (char tab))
		   (make!-error (list "tab illegal in " u)))
	   ((eq (caadr u) '!:) (make!-rule (car u) (cddr u)))
	   (t (make!-error (list "unverstaendlich:" u))))
     (go line)))
 
(de eofp (c)
    (setq c (inf c))
    (or (eq c (char eof)) (eq c 16#1a)))

(de make-setq(var val)
   (setq variables 
      (cons (cons var val) variables)))
 
(de make-rule (obj prem)
   (prog (act)
     (setq act (read-lin))
     (when (null act) (setq act (list (list " "))))
     (cond ((not (eq (inf (caar act)) (char tab)))
	 %   (make!-error (list "tab erwartet vor Aktion zu" obj))
	    (setq act (cons nil act))
      ))
     (setq objects (cons (list obj prem (cdr act)) objects))))

(fluid '(recurs))

(de make!-it(obj)
   (when (member obj recurs)
	 (make!-error (list "recursive call for " obj)))
   (let(o d (recurs (cons obj recurs)))
     (setq o (assoc obj objects))
     (cond ((null o) (make!-error (list "dont know how to make " obj))))
     (setq d (file-date obj))
     (if (make-it-cond (cadr o) d nil)
	 (progn (report obj "make") (push obj done) (attach (caddr o)))
	 (progn (report obj "----") (push obj actual) nil))
      ))

(de report(o m)
   (prin2 m) (prin2 ":") (tab 8)
   (foreach c in o do (prin2 c))
   (terpri))

(de make!-it-cond1(obj dat)
 (cond((member obj done) t)
      ((member obj actual) nil)
      (t
   (prog(o d d0 tue)
     (setq o (assoc obj objects))
     (when o (setq d0 (make-it obj)))
     (setq d (file-date obj))
     (cond ((and (null d)(null o))
	      (make!-error (list "dont know how to make " obj))))
     (when (null d)
       (prin2 "===== warning: no file ")
       (mapc obj (function prin2))
       (terpri))
     (setq tue (and (not (member obj done))
		    (or d0 (null dat) (greaterp d dat))))
     (return tue) ))) )

(de make-it-cond(ol d v)
   (cond((null ol) v)
	(t (make-it-cond 
	      (cdr ol)
	      d
	      (or (make-it-cond1 (car ol) d)
		  v)))))

(de file-date (f)
    (let ((s (filestatus (compress (cons '!" (append f '(!"))) nil))))
       (when s (cddr (assoc 'writetime s)))))
       
(de attach(c)
   (setq commands (cons c commands)))    

 
(de make-write()
   (mapc (reversip commands) (function write-lin))
   (prin2t ":ende"))

(de write-lin(l)
   (if (not (eq (caar l) lpar))
       (write-lin1 l)
    (let (c itm)
       (setq l (cons (cdar l)(cdr l)))
       (while l
	   (setq itm (pop l))
	   (when (and (not (eq (car itm) rpar)) (memq rpar itm))
		 (push (list rpar) l)
		 (setq itm (delete rpar itm))  )
	   (if (or (eq (car itm) '!;) (eq (car itm) rpar))
	       (progn (write-lin1 (reverse c)) (setq c nil))
	       (push itm c)  )))))

(de write-lin1(l)
   (setq l (subst '!\ '!/ l))
   (prin2 "@")
   (when (and (not (equal (car l) '(!c !d)))
	      (not (equal (car l) '(!e !c !h !o)))  )
	 (prin2 "call "))
   (foreach x in l do
      (progn
	(foreach y in x do (prin2 y))
       (prin2 " ")))
   (terpri)
   (prin2t "@if errorlevel 1 goto ende")
   )
 
(de make!-error(l)
   (wrs nil)
   (prin2 "***** make error ")
   (prin2l l)
   (exitlisp) )

(fluid '(object))

(loadtime
  (progn
      (setq object nil)
      (errorset '(setq object (getenv "object")) nil nil)
      (errorset '(make object) t t)
      (exitlisp)
))
