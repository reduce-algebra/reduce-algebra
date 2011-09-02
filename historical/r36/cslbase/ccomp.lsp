(global '(!*fastvector !*unsafecar))


(flag '(fastvector unsafecar) 'switch)


(fluid '(c_file l_file o_file l_contents file_name))


(dm c!:printf (u) (list 'c!:printf1 (cadr u) (cons 'list (cddr u))))


(de c!:printf1 (fmt args)
   (prog (a c)
      (setq fmt (explode2 fmt))
      (prog nil
   !G50  (cond ((not fmt) (return nil)))
         (progn
            (setq c (car fmt))
            (setq fmt (cdr fmt))
            (cond
               ((and
                   (equal c '!\)
                   (or (equal (car fmt) 'n) (equal (car fmt) '!N)))
                  (progn (terpri) (setq fmt (cdr fmt))))
               ((and
                   (equal c '!\)
                   (or (equal (car fmt) 'q) (equal (car fmt) '!Q)))
                  (progn (princ '!") (setq fmt (cdr fmt))))
               ((equal c '!%)
                  (progn
                     (setq c (car fmt))
                     (cond
                        ((null args) (setq a 'missing_arg))
                        (t (setq a (car args))))
                     (cond
                        ((or (equal c 'v) (equal c '!V))
                           (cond
                              ((flagp a 'c!:live_across_call)
                                 (progn
                                    (princ "stack[")
                                    (princ (minus (get a 'c!:location)))
                                    (princ "]")))
                              (t (princ a))))
                        ((or (equal c 'a) (equal c '!A)) (prin a))
                        ((or (equal c 't) (equal c '!T)) (ttab a))
                        (t (princ a)))
                     (cond (args (setq args (cdr args))))
                     (setq fmt (cdr fmt))))
               (t (princ c))))
         (go !G50))))


(de c!:cspecform (x env) (error 0 (list "special form" x)))


(progn
   (put 'and 'c!:code (function c!:cspecform))
   (put 'catch 'c!:code (function c!:cspecform))
   (put 'compiler!-let 'c!:code (function c!:cspecform))
   (put 'cond 'c!:code (function c!:cspecform))
   (put 'declare 'c!:code (function c!:cspecform))
   (put 'de 'c!:code (function c!:cspecform))
   (put 'eval!-when 'c!:code (function c!:cspecform))
   (put 'flet 'c!:code (function c!:cspecform))
   (put 'function 'c!:code (function c!:cspecform))
   (put 'go 'c!:code (function c!:cspecform))
   (put 'if 'c!:code (function c!:cspecform))
   (put 'labels 'c!:code (function c!:cspecform))
   (put '!~let 'c!:code (function c!:cspecform))
   (put 'let!* 'c!:code (function c!:cspecform))
   (put 'list 'c!:code (function c!:cspecform))
   (put 'list!* 'c!:code (function c!:cspecform))
   (put 'macrolet 'c!:code (function c!:cspecform))
   (put 'multiple!-value!-call 'c!:code (function c!:cspecform))
   (put 'multiple!-value!-prog1 'c!:code (function c!:cspecform))
   (put 'or 'c!:code (function c!:cspecform))
   (put 'prog 'c!:code (function c!:cspecform))
   (put 'prog!* 'c!:code (function c!:cspecform))
   (put 'prog1 'c!:code (function c!:cspecform))
   (put 'prog2 'c!:code (function c!:cspecform))
   (put 'progn 'c!:code (function c!:cspecform))
   (put 'progv 'c!:code (function c!:cspecform))
   (put 'quote 'c!:code (function c!:cspecform))
   (put 'return 'c!:code (function c!:cspecform))
   (put 'return!-from 'c!:code (function c!:cspecform))
   (put 'setq 'c!:code (function c!:cspecform))
   (put 'tagbody 'c!:code (function c!:cspecform))
   (put 'the 'c!:code (function c!:cspecform))
   (put 'throw 'c!:code (function c!:cspecform))
   (put 'unless 'c!:code (function c!:cspecform))
   (put 'unwind!-protect 'c!:code (function c!:cspecform))
   (put 'when 'c!:code (function c!:cspecform)))


(fluid
   '(current_procedure current_args current_block current_contents all_blocks
       registers stacklocs))


(fluid '(available used))


(setq available (setq used nil))


(de c!:reset_gensyms nil
   (progn
      (remflag used 'c!:live_across_call)
      (remflag used 'c!:visited)
      (prog nil
   !G51  (cond ((not used) (return nil)))
         (progn
            (remprop (car used) 'c!:contents)
            (remprop (car used) 'c!:why)
            (remprop (car used) 'c!:where_to)
            (remprop (car used) 'c!:count)
            (remprop (car used) 'c!:live)
            (remprop (car used) 'c!:clash)
            (remprop (car used) 'c!:chosen)
            (remprop (car used) 'c!:location)
            (cond
               ((plist (car used))
                  (prog (o)
                     (setq o (wrs nil))
                     (princ "+++++ ")
                     (prin (car used))
                     (princ " ")
                     (prin (plist (car used)))
                     (terpri)
                     (wrs o))))
            (setq available (cons (car used) available))
            (setq used (cdr used)))
         (go !G51))))


(de c!:my_gensym nil
   (prog (w)
      (cond
         (available
            (progn (setq w (car available)) (setq available (cdr available))))
         (t (setq w (gensym1 "v"))))
      (setq used (cons w used))
      (cond
         ((plist w)
            (progn (princ "????? ") (prin w) (princ " => ") (prin (plist w))
               (terpri))))
      (return w)))


(de c!:newreg nil
   (prog (r)
      (setq r (c!:my_gensym))
      (setq registers (cons r registers))
      (return r)))


(de c!:startblock (s)
   (progn (setq current_block s) (setq current_contents nil)))


(de c!:outop (a b c d)
   (cond
      (current_block
         (setq current_contents (cons (list a b c d) current_contents)))) )


(de c!:endblock (why where_to)
   (cond
      (current_block
         (progn
            (put current_block 'c!:contents current_contents)
            (put current_block 'c!:why why)
            (put current_block 'c!:where_to where_to)
            (setq all_blocks (cons current_block all_blocks))
            (setq current_contents nil)
            (setq current_block nil)))) )


(de c!:cval_inner (x env)
   (prog (helper)
      (setq x (s!:improve x))
      (cond
         ((atom x) (return (c!:catom x env)))
         ((eqcar (car x) 'lambda)
            (return
               (c!:clambda (cadar x) (cons 'progn (cddar x)) (cdr x) env)))
         ((setq helper (get (car x) 'c!:code))
            (return (funcall helper x env)))
         ((and
             (setq helper (get (car x) 'c!:compile_macro))
             (setq helper (funcall helper x)))
            (return (c!:cval helper env)))
         ((and (idp (car x)) (setq helper (macro!-function (car x))))
            (return (c!:cval (funcall helper x) env)))
         (t (return (c!:ccall (car x) (cdr x) env)))) ))


(de c!:cval (x env)
   (prog (r)
      (setq r (c!:cval_inner x env))
      (cond
         ((and r (not (member!*!* r registers)))
            (error 0 (list r "not a register" x))))
      (return r)))


(de c!:clambda (bvl body args env)
   (prog (w fluids env1)
      (setq env1 (car env))
      (setq w
         (prog (a !G52 endptr)
            (setq a args)
            (cond ((null a) (return nil)))
            (setq !G52
               (setq endptr
                  (cons ((lambda (a) (c!:cval a env)) (car a)) nil)))
      looplabel
            (setq a (cdr a))
            (cond ((null a) (return !G52)))
            (rplacd endptr (cons ((lambda (a) (c!:cval a env)) (car a)) nil))
            (setq endptr (cdr endptr))
            (go looplabel)))
      (prog (v)
         (setq v bvl)
   lab   (cond ((null v) (return nil)))
         ((lambda (v)
             (progn
                (cond
                   ((globalp v)
                      (prog (oo)
                         (setq oo (wrs nil))
                         (princ "+++++ ")
                         (prin v)
                         (princ " converted from GLOBAL to FLUID")
                         (terpri)
                         (wrs oo)
                         (unglobal (list v))
                         (fluid (list v)))) )
                (cond
                   ((fluidp v)
                      (progn
                         (setq fluids (cons (cons v (c!:newreg)) fluids))
                         (flag (list (cdar fluids)) 'c!:live_across_call)
                         (setq env1
                            (cons (cons 'c!:dummy!:name (cdar fluids)) env1))
                         (c!:outop
                            'ldrglob
                            (cdar fluids)
                            v
                            (c!:find_literal v))
                         (c!:outop 'strglob (car w) v (c!:find_literal v))))
                   (t (progn
                         (setq env1 (cons (cons v (c!:newreg)) env1))
                         (c!:outop 'movr (cdar env1) nil (car w)))) )
                (setq w (cdr w))))
            (car v))
         (setq v (cdr v))
         (go lab))
      (cond (fluids (c!:outop 'fluidbind nil nil fluids)))
      (setq env (cons env1 (append fluids (cdr env))))
      (setq w (c!:cval body env))
      (prog (v)
         (setq v fluids)
   lab   (cond ((null v) (return nil)))
         ((lambda (v)
             (c!:outop 'strglob (cdr v) (car v) (c!:find_literal (car v))))
            (car v))
         (setq v (cdr v))
         (go lab))
      (return w)))


(de c!:locally_bound (x env) (atsoc x (car env)))


(flag '(nil t) 'c!:constant)


(fluid '(literal_vector))


(de c!:find_literal (x)
   (prog (n w)
      (setq w literal_vector)
      (setq n 0)
      (prog nil
   !G53  (cond ((not (and w (not (equal (car w) x)))) (return nil)))
         (progn (setq n (plus n 1)) (setq w (cdr w)))
         (go !G53))
      (cond
         ((null w) (setq literal_vector (append literal_vector (list x)))) )
      (return n)))


(de c!:catom (x env)
   (prog (v w)
      (setq v (c!:newreg))
      (cond
         ((and (idp x) (setq w (c!:locally_bound x env)))
            (c!:outop 'movr v nil (cdr w)))
         ((or (null x) (equal x 't) (c!:small_number x))
            (c!:outop 'movk1 v nil x))
         ((or (not (idp x)) (flagp x 'c!:constant))
            (c!:outop 'movk v x (c!:find_literal x)))
         (t (c!:outop 'ldrglob v x (c!:find_literal x))))
      (return v)))


(de c!:cjumpif (x env d1 d2)
   (prog (helper r)
      (setq x (s!:improve x))
      (cond
         ((and
             (atom x)
             (or
                (not (idp x))
                (and (flagp x 'c!:constant) (not (c!:locally_bound x env)))) )
            (c!:endblock 'goto (list (cond (x d1) (t d2)))) )
         ((and (not (atom x)) (setq helper (get (car x) 'c!:ctest)))
            (return (funcall helper x env d1 d2)))
         (t (progn
               (setq r (c!:cval x env))
               (c!:endblock (list 'ifnull r) (list d2 d1)))) )))


(fluid '(current))


(de c!:ccall (fn args env) (c!:ccall1 fn args env))


(fluid '(visited))


(de c!:has_calls (a b)
   (prog (visited)
      (return (c!:has_calls_1 a b))))


(de c!:has_calls_1 (a b)
   (cond
      ((or (equal a b) (not (atom a)) (memq a visited)) nil)
      (t (prog (has_call)
            (setq visited (cons a visited))
            (prog (z)
               (setq z (get a 'c!:contents))
         lab   (cond ((null z) (return nil)))
               ((lambda (z) (cond ((eqcar z 'call) (setq has_call t))))
                  (car z))
               (setq z (cdr z))
               (go lab))
            (cond
               (has_call
                  (return
                     (prog (visited)
                        (return (c!:can_reach a b)))) ))
            (prog (d)
               (setq d (get a 'c!:where_to))
         lab   (cond ((null d) (return nil)))
               ((lambda (d) (cond ((c!:has_calls_1 d b) (setq has_call t))))
                  (car d))
               (setq d (cdr d))
               (go lab))
            (return has_call)))) )


(de c!:can_reach (a b)
   (cond
      ((equal a b) t)
      ((or (not (atom a)) (memq a visited)) nil)
      (t (progn
            (setq visited (cons a visited))
            (c!:any_can_reach (get a 'c!:where_to) b)))) )


(de c!:any_can_reach (l b)
   (cond
      ((null l) nil)
      ((c!:can_reach (car l) b) t)
      (t (c!:any_can_reach (cdr l) b))))


(de c!:pareval (args env)
   (prog (tasks tasks1 merge split r)
      (setq tasks
         (prog (a !G54 endptr)
            (setq a args)
            (cond ((null a) (return nil)))
            (setq !G54
               (setq endptr
                  (cons
                     ((lambda (a) (cons (c!:my_gensym) (c!:my_gensym)))
                        (car a))
                     nil)))
      looplabel
            (setq a (cdr a))
            (cond ((null a) (return !G54)))
            (rplacd
               endptr
               (cons
                  ((lambda (a) (cons (c!:my_gensym) (c!:my_gensym))) (car a))
                  nil))
            (setq endptr (cdr endptr))
            (go looplabel)))
      (setq split (c!:my_gensym))
      (c!:endblock 'goto (list split))
      (prog (a)
         (setq a args)
   lab   (cond ((null a) (return nil)))
         ((lambda (a)
             (prog (s)
                (setq s (car tasks))
                (setq tasks (cdr tasks))
                (c!:startblock (car s))
                (setq r (cons (c!:cval a env) r))
                (c!:endblock 'goto (list (cdr s)))
                (cond
                   ((c!:has_calls (car s) (cdr s))
                      (setq tasks1 (cons s tasks1)))
                   (t (setq merge (cons s merge)))) ))
            (car a))
         (setq a (cdr a))
         (go lab))
      (prog (z)
         (setq z tasks1)
   lab   (cond ((null z) (return nil)))
         ((lambda (z) (setq merge (cons z merge))) (car z))
         (setq z (cdr z))
         (go lab))
      (prog (v)
         (setq v merge)
   lab   (cond ((null v) (return nil)))
         ((lambda (v)
             (progn
                (c!:startblock split)
                (c!:endblock 'goto (list (car v)))
                (setq split (cdr v))))
            (car v))
         (setq v (cdr v))
         (go lab))
      (c!:startblock split)
      (return (reversip r))))


(de c!:ccall1 (fn args env)
   (prog (tasks merge r val)
      (setq fn (list fn (cdr env)))
      (setq val (c!:newreg))
      (cond
         ((null args) (c!:outop 'call val nil fn))
         ((null (cdr args))
            (c!:outop 'call val (list (c!:cval (car args) env)) fn))
         (t (progn (setq r (c!:pareval args env)) (c!:outop 'call val r fn))))
      (c!:outop 'reloadenv 'env nil nil)
      (return val)))


(fluid '(restart_label reloadenv does_call current_c_name))


(fluid '(proglabs blockstack))


(de c!:cfndef (current_procedure current_c_name argsbody)
   (prog (env n w current_args current_block restart_label current_contents
         all_blocks entrypoint exitpoint args1 registers stacklocs
         literal_vector reloadenv does_call blockstack proglabs checksum args
         body)
      (setq checksum (md60 argsbody))
      (setq args (car argsbody))
      (setq body (cdr argsbody))
      (cond
         ((atom body) (setq body nil))
         ((atom (cdr body)) (setq body (car body)))
         (t (setq body (cons 'progn body))))
      (c!:reset_gensyms)
      (wrs c_file)
      (linelength 200)
      (c!:printf1 "\n\n/* Code for %a */\n\n" (list current_procedure))
      (c!:find_literal current_procedure)
      (setq current_args args)
      (prog (v)
         (setq v args)
   lab   (cond ((null v) (return nil)))
         ((lambda (v)
             (cond
                ((or (equal v '!&optional) (equal v '!&rest))
                   (error
                      0
                "&optional and &rest not supported by this compiler (yet)"))
                ((globalp v)
                   (prog (oo)
                      (setq oo (wrs nil))
                      (princ "+++++ ")
                      (prin v)
                      (princ " converted from GLOBAL to FLUID")
                      (terpri)
                      (wrs oo)
                      (unglobal (list v))
                      (fluid (list v))
                      (setq n (cons (cons v (c!:my_gensym)) n))))
                ((fluidp v) (setq n (cons (cons v (c!:my_gensym)) n)))) )
            (car v))
         (setq v (cdr v))
         (go lab))
      (setq restart_label (c!:my_gensym))
      (setq body (list 'c!:private_tagbody restart_label body))
      (cond
         (n
            (progn
               (setq body (list (list 'return body)))
               (setq args (subla n args))
               (prog (v)
                  (setq v n)
            lab   (cond ((null v) (return nil)))
                  ((lambda (v)
                      (setq body (cons (list 'setq (car v) (cdr v)) body)))
                     (car v))
                  (setq v (cdr v))
                  (go lab))
               (setq body
                  (cons
                     'prog
                     (cons
                        (prog (v !G55 endptr)
                           (setq v (reverse n))
                           (cond ((null v) (return nil)))
                           (setq !G55
                              (setq endptr
                                 (cons ((lambda (v) (car v)) (car v)) nil)))
                     looplabel
                           (setq v (cdr v))
                           (cond ((null v) (return !G55)))
                           (rplacd
                              endptr
                              (cons ((lambda (v) (car v)) (car v)) nil))
                           (setq endptr (cdr endptr))
                           (go looplabel))
                        body)))) ))
      (c!:printf1 "static Lisp_Object " (list))
      (cond
         ((or (null args) (geq (length args) 3))
            (c!:printf1 "MS_CDECL " (list))))
      (c!:printf1 "%s(Lisp_Object env" (list current_c_name))
      (cond
         ((or (null args) (geq (length args) 3))
            (c!:printf1 ", int nargs" (list))))
      (setq n t)
      (setq env nil)
      (prog (x)
         (setq x args)
   lab   (cond ((null x) (return nil)))
         ((lambda (x)
             (prog (aa)
                (c!:printf1 "," (list))
                (cond
                   (n
                      (progn
                         (c!:printf1 "\n                        " (list))
                         (setq n nil)))
                   (t (setq n t)))
                (setq aa (c!:my_gensym))
                (setq env (cons (cons x aa) env))
                (setq registers (cons aa registers))
                (setq args1 (cons aa args1))
                (c!:printf1 " Lisp_Object %s" (list aa))))
            (car x))
         (setq x (cdr x))
         (go lab))
      (cond
         ((or (null args) (geq (length args) 3)) (c!:printf1 ", ..." (list))))
      (c!:printf1 ")\n{\n" (list))
      (c!:startblock (setq entrypoint (c!:my_gensym)))
      (setq exitpoint current_block)
      (c!:endblock 'goto (list (list (c!:cval body (cons env nil)))) )
      (c!:optimise_flowgraph
         entrypoint
         all_blocks
         env
         (cons (length args) current_procedure)
         args1)
      (c!:printf1 "}\n\n" (list))
      (wrs o_file)
      (setq l_contents
         (cons
            (cons current_procedure (cons literal_vector checksum))
            l_contents))
      (return nil)))


(flag
   '(rds deflist flag fluid global remprop remflag unfluid unglobal dm
       carcheck c!-end)
   'eval)


(flag '(rds) 'ignore)


(fluid '(!*backtrace))


(de c!:ccompilesupervisor nil
   (prog (u w)
top   (setq u (errorset '(read) t !*backtrace))
      (cond ((atom u) (return nil)))
      (setq u (car u))
      (cond ((equal u !$eof!$) (return nil)))
      (cond
         ((atom u) (go top))
         ((eqcar u 'c!-end) (return (apply 'c!-end nil)))
         ((eqcar u 'rdf)
            (progn
               (setq w (open (setq u (eval (cadr u))) 'input))
               (cond
                  (w
                     (progn
                        (terpri)
                        (princ "Reading file ")
                        (print u)
                        (setq w (rds w))
                        (c!:ccompilesupervisor)
                        (princ "End of file ")
                        (print u)
                        (close (rds w))))
                  (t (progn (princ "Failed to open file ") (print u)))) ))
         (t (c!:ccmpout1 u)))
      (go top)))


(global '(c!:char_mappings))


(setq c!:char_mappings
   '((!  . !A) (!! . !B) (!# . !C) (!$ . !D) (!% . !E) (!^ . !F) (!& . !G)
       (!* . !H) (!( . !I) (!) . !J) (!- . !K) (!+ . !L) (!= . !M) (!\ . !N)
       (!| . !O) (!, . !P) (!. . !Q) (!< . !R) (!> . !S) (!: . !T) (!; . !U)
       (!/ . !V) (!? . !W) (!~ . !X) (!` . !Y)))


(de c!:inv_name (n)
   (prog (r w)
      (setq r '(!_ !C !C !"))
      (prog (c)
         (setq c (explode2 n))
   lab   (cond ((null c) (return nil)))
         ((lambda (c)
             (progn
                (cond
                   ((equal c '!_) (setq r (cons '!_ r)))
                   ((or (liter c) (digit c)) (setq r (cons c r)))
                   ((setq w (atsoc c c!:char_mappings))
                      (setq r (cons (cdr w) r)))
                   (t (setq r (cons '!Z r)))) ))
            (car c))
         (setq c (cdr c))
         (go lab))
      (setq r (cons '!" r))
      (return (compress (reverse r)))) )


(fluid '(defnames pending_functions))


(de c!:ccmpout1 (u)
   (prog (pending_functions)
      (setq pending_functions (list u))
      (prog nil
   !G56  (cond ((not pending_functions) (return nil)))
         (progn
            (setq u (car pending_functions))
            (setq pending_functions (cdr pending_functions))
            (c!:ccmpout1a u))
         (go !G56))))


(de c!:ccmpout1a (u)
   (prog (w)
      (cond
         ((atom u) (return nil))
         ((eqcar u 'progn)
            (progn
               (prog (v)
                  (setq v (cdr u))
            lab   (cond ((null v) (return nil)))
                  ((lambda (v) (c!:ccmpout1a v)) (car v))
                  (setq v (cdr v))
                  (go lab))
               (return nil)))
         ((eqcar u 'c!-end) nil)
         ((or
             (flagp (car u) 'eval)
             (and
                (equal (car u) 'setq)
                (not (atom (caddr u)))
                (flagp (caaddr u) 'eval)))
            (errorset u t !*backtrace)))
      (cond
         ((eqcar u 'rdf)
            (prog nil
               (setq w (open (setq u (eval (cadr u))) 'input))
               (cond
                  (w
                     (progn
                        (princ "Reading file ")
                        (print u)
                        (setq w (rds w))
                        (c!:ccompilesupervisor)
                        (princ "End of file ")
                        (print u)
                        (close (rds w))))
                  (t (progn (princ "Failed to open file ") (print u)))) ))
         ((eqcar u 'de)
            (progn
               (setq u (cdr u))
               (setq defnames
                  (cons
                     (list (car u) (c!:inv_name (car u)) (length (cadr u)))
                     defnames))
               (cond ((neq (posn) 0) (terpri)))
               (princ "Compiling ")
               (prin (caar defnames))
               (princ " ... ")
               (c!:cfndef (caar defnames) (cadar defnames) (cdr u))
               (terpri)))) ))


(fluid '(!*defn dfprint!* dfprintsave))


(de c!:concat (a b)
   (compress (cons '!" (append (explode2 a) (append (explode2 b) '(!")))) ))


(de c!:ccompilestart (name !&optional dir)
   (prog (o d w)
      (setq file_name name)
      (cond (dir (setq name (c!:concat dir (c!:concat "/" name)))) )
      (setq c_file (open (c!:concat name ".c") 'output))
      (setq l_file (c!:concat name ".lsp"))
      (setq l_contents nil)
      (setq o (reverse (explode (date))))
      (prog (i)
         (setq i 1)
   lab   (cond ((minusp (difference 5 i)) (return nil)))
         (progn (setq d (cons (car o) d)) (setq o (cdr o)))
         (setq i (plus2 i 1))
         (go lab))
      (setq d (cons '!- d))
      (setq o (cdddr (cdddr (cddddr o))))
      (setq w o)
      (setq o (cdddr o))
      (setq d (cons (caddr o) (cons (cadr o) (cons (car o) d))))
      (setq d
         (compress (cons '!" (cons (cadr w) (cons (car w) (cons '!- d)))) ))
      (setq o_file (wrs c_file))
      (setq defnames nil)
      (c!:printf1 "\n/* %s.c%tMachine generated C code */\n\n" (list name 25))
      (c!:printf1 "/* Signature: 00000000 %s */\n\n" (list d))
      (c!:printf1 "#include <stdarg.h>\n" (list))
      (c!:printf1 "#include <string.h>\n" (list))
      (c!:printf1 "#include <ctype.h>\n\n" (list))
      (c!:printf1 "#include \qmachine.h\q\n" (list))
      (c!:printf1 "#include \qtags.h\q\n" (list))
      (c!:printf1 "#include \qcslerror.h\q\n" (list))
      (c!:printf1 "#include \qexterns.h\q\n" (list))
      (c!:printf1 "#include \qarith.h\q\n" (list))
      (c!:printf1 "#include \qentries.h\q\n\n\n" (list))
      (wrs o_file)
      (return nil)))


(de c!-end nil
   (prog (checksum c1 c2 c3)
      (wrs c_file)
      (c!:printf1 "\n\nsetup_type const %s_setup[] =\n{\n" (list file_name))
      (setq defnames (reverse defnames))
      (prog nil
   !G57  (cond ((not defnames) (return nil)))
         (prog (name nargs f1 f2 cast fn)
            (setq name (caar defnames))
            (setq f1 (cadar defnames))
            (setq nargs (caddar defnames))
            (setq cast "(n_args *)")
            (cond
               ((equal nargs 1)
                  (progn
                     (setq f2 'too_many_1)
                     (setq cast "")
                     (setq fn 'wrong_no_1)))
               ((equal nargs 2)
                  (progn
                     (setq f2 f1)
                     (setq f1 'too_few_2)
                     (setq cast "")
                     (setq fn 'wrong_no_2)))
               (t (progn
                     (setq fn f1)
                     (setq f1 'wrong_no_na)
                     (setq f2 'wrong_no_nb))))
            (c!:printf1
               "    {\q%s\q,%t%s,%t%s,%t%s%s},\n"
               (list name 32 f1 48 f2 63 cast fn))
            (setq defnames (cdr defnames)))
         (go !G57))
      (setq c3 (setq checksum (md60 l_contents)))
      (setq c1 (remainder c3 10000000))
      (setq c3 (quotient c3 10000000))
      (setq c2 (remainder c3 10000000))
      (setq c3 (quotient c3 10000000))
      (setq checksum
         (list!-to!-string
            (append
               (explodec c3)
               (cons '!  (append (explodec c2) (cons '!  (explodec c1)))) )))
      (c!:printf1
         "    {NULL, (one_args *)%a, (two_args *)%a, 0}\n};\n\n"
         (list (list!-to!-string (explodec file_name)) checksum))
      (c!:printf1 "/* end of generated code */\n" (list))
      (close c_file)
      (setq l_file (open l_file 'output))
      (wrs l_file)
      (linelength 72)
      (terpri)
      (princ "% ")
      (princ file_name)
      (princ ".lsp")
      (ttab 20)
      (princ "Machine generated Lisp")
      (terpri)
      (terpri)
      (princ "(c!:install ")
      (princ '!")
      (princ file_name)
      (princ '!")
      (princ " ")
      (princ checksum)
      (printc ")")
      (terpri)
      (prog (x)
         (setq x (reverse l_contents))
   lab   (cond ((null x) (return nil)))
         ((lambda (x)
             (progn
                (princ "(c!:install '")
                (prin (car x))
                (princ " '")
                (prin (cadr x))
                (princ " ")
                (prin (cddr x))
                (princ ")")
                (terpri)
                (terpri)))
            (car x))
         (setq x (cdr x))
         (go lab))
      (terpri)
      (princ "% End of generated Lisp code")
      (terpri)
      (terpri)
      (setq l_contents nil)
      (wrs o_file)
      (close l_file)
      (setq !*defn nil)
      (setq dfprint!* dfprintsave)))


(put 'c!-end 'stat 'endstat)


(de c!-compile (u)
   (prog nil
      (terpri)
      (princ "C!-COMPILE ")
      (prin u)
      (princ ": IN files;  or type in expressions")
      (terpri)
      (princ "When all done, execute C!-END;")
      (terpri)
      (verbos nil)
      (c!:ccompilestart (car u))
      (setq dfprintsave dfprint!*)
      (setq dfprint!* 'c!:ccmpout1)
      (setq !*defn t)
      (cond ((getd 'begin) (return nil)))
      (c!:ccompilesupervisor)))


(put 'c!-compile 'stat 'rlis)


(de c!:print_opcode (s depth)
   (prog (op r1 r2 r3 helper)
      (setq op (car s))
      (setq r1 (cadr s))
      (setq r2 (caddr s))
      (setq r3 (cadddr s))
      (setq helper (get op 'c!:opcode_printer))
      (cond
         (helper (funcall helper op r1 r2 r3 depth))
         (t (progn (prin s) (terpri)))) ))


(de c!:print_exit_condition (why where_to depth)
   (prog (helper lab1 drop1 lab2 drop2 negate)
      (cond
         ((equal why 'goto)
            (progn
               (setq where_to (car where_to))
               (cond
                  ((atom where_to)
                     (progn
                        (c!:printf1 "    goto %s;\n" (list where_to))
                        (c!:display_flowgraph where_to depth t)))
                  (t (progn
                        (c!:printf1 "    " (list))
                        (c!:pgoto where_to depth))))
               (return nil)))
         ((eqcar (car why) 'call)
            (return
               (prog (args locs g w)
                  (cond
                     ((setq w (get (cadar why) 'c!:direct_entrypoint))
                        (progn
                           (prog (a)
                              (setq a (cdr why))
                        lab   (cond ((null a) (return nil)))
                              ((lambda (a)
                                  (cond
                                     ((flagp a 'c!:live_across_call)
                                        (progn
                                           (cond
                                              ((null g)
                                                 (c!:printf1
                                                    "    {\n"
                                                    (list))))
                                           (setq g (c!:my_gensym))
                                           (c!:printf1
                                              "        Lisp_Object %s = %v;\n"
                                              (list g a))
                                           (setq args (cons g args))))
                                     (t (setq args (cons a args)))) )
                                 (car a))
                              (setq a (cdr a))
                              (go lab))
                           (cond
                              ((neq depth 0)
                                 (progn
                                    (cond (g (c!:printf1 "    " (list))))
                                    (c!:printf1
                                       "    popv(%s);\n"
                                       (list depth)))) )
                           (cond (g (c!:printf1 "    " (list))))
                           (c!:printf1 "    return %s(" (list (cdr w)))
                           (setq args (reversip args))
                           (cond
                              (args
                                 (progn
                                    (c!:printf1 "%v" (list (car args)))
                                    (prog (a)
                                       (setq a (cdr args))
                                 lab   (cond ((null a) (return nil)))
                                       ((lambda (a)
                                           (c!:printf1 ", %v" (list a)))
                                          (car a))
                                       (setq a (cdr a))
                                       (go lab)))) )
                           (c!:printf1 ");\n" (list))
                           (cond (g (c!:printf1 "    }\n" (list)))) ))
                     ((setq w (get (cadar why) 'c!:c_entrypoint))
                        (progn
                           (prog (a)
                              (setq a (cdr why))
                        lab   (cond ((null a) (return nil)))
                              ((lambda (a)
                                  (cond
                                     ((flagp a 'c!:live_across_call)
                                        (progn
                                           (cond
                                              ((null g)
                                                 (c!:printf1
                                                    "    {\n"
                                                    (list))))
                                           (setq g (c!:my_gensym))
                                           (c!:printf1
                                              "        Lisp_Object %s = %v;\n"
                                              (list g a))
                                           (setq args (cons g args))))
                                     (t (setq args (cons a args)))) )
                                 (car a))
                              (setq a (cdr a))
                              (go lab))
                           (cond
                              ((neq depth 0)
                                 (c!:printf1
                                    "        popv(%s);\n"
                                    (list depth))))
                           (c!:printf1 "        return %s(nil" (list w))
                           (cond
                              ((or (null args) (geq (length args) 3))
                                 (c!:printf1 ", %s" (list (length args)))) )
                           (prog (a)
                              (setq a (reversip args))
                        lab   (cond ((null a) (return nil)))
                              ((lambda (a) (c!:printf1 ", %v" (list a)))
                                 (car a))
                              (setq a (cdr a))
                              (go lab))
                           (c!:printf1 ");\n" (list))
                           (cond (g (c!:printf1 "    }\n" (list)))) ))
                     (t (prog (nargs)
                           (setq nargs (length (cdr why)))
                           (c!:printf1 "    {\n" (list))
                           (prog (a)
                              (setq a (cdr why))
                        lab   (cond ((null a) (return nil)))
                              ((lambda (a)
                                  (cond
                                     ((flagp a 'c!:live_across_call)
                                        (progn
                                           (setq g (c!:my_gensym))
                                           (c!:printf1
                                              "        Lisp_Object %s = %v;\n"
                                              (list g a))
                                           (setq args (cons g args))))
                                     (t (setq args (cons a args)))) )
                                 (car a))
                              (setq a (cdr a))
                              (go lab))
                           (cond
                              ((neq depth 0)
                                 (c!:printf1
                                    "        popv(%s);\n"
                                    (list depth))))
                           (c!:printf1
                              "        fn = elt(env, %s); /* %a */\n"
                              (list
                                 (c!:find_literal (cadar why))
                                 (cadar why)))
                           (cond
                              ((equal nargs 1)
                                 (c!:printf1
                                    "        return (*qfn1(fn))(qenv(fn)"
                                    (list)))
                              ((equal nargs 2)
                                 (c!:printf1
                                    "        return (*qfn2(fn))(qenv(fn)"
                                    (list)))
                              (t (c!:printf1
                                    "        return (*qfnn(fn))(qenv(fn), %s"
                                    (list nargs))))
                           (prog (a)
                              (setq a (reversip args))
                        lab   (cond ((null a) (return nil)))
                              ((lambda (a) (c!:printf1 ", %s" (list a)))
                                 (car a))
                              (setq a (cdr a))
                              (go lab))
                           (c!:printf1 ");\n    }\n" (list)))) )
                  (return nil)))) )
      (setq lab1 (car where_to))
      (setq drop1 (and (atom lab1) (not (flagp lab1 'c!:visited))))
      (setq lab2 (cadr where_to))
      (setq drop2 (and (atom lab2) (not (flagp drop2 'c!:visited))))
      (cond
         ((and drop2 (equal (get lab2 'c!:count) 1))
            (progn (setq where_to (list lab2 lab1)) (setq drop1 t)))
         (drop1 (setq negate t)))
      (setq helper (get (car why) 'c!:exit_helper))
      (cond ((null helper) (error 0 (list "Bad exit condition" why))))
      (c!:printf1 "    if (" (list))
      (cond
         (negate
            (progn
               (c!:printf1 "!(" (list))
               (funcall helper (cdr why) depth)
               (c!:printf1 ")" (list))))
         (t (funcall helper (cdr why) depth)))
      (c!:printf1 ") " (list))
      (cond
         ((not drop1)
            (progn
               (c!:pgoto (car where_to) depth)
               (c!:printf1 "    else " (list)))) )
      (c!:pgoto (cadr where_to) depth)
      (cond
         ((atom (car where_to))
            (c!:display_flowgraph (car where_to) depth drop1)))
      (cond
         ((atom (cadr where_to))
            (c!:display_flowgraph (cadr where_to) depth nil)))) )


(de c!:pmovr (op r1 r2 r3 depth) (c!:printf1 "    %v = %v;\n" (list r1 r3)))


(put 'movr 'c!:opcode_printer (function c!:pmovr))


(de c!:pmovk (op r1 r2 r3 depth)
   (c!:printf1 "    %v = elt(env, %s); /* %a */\n" (list r1 r3 r2)))


(put 'movk 'c!:opcode_printer (function c!:pmovk))


(de c!:pmovk1 (op r1 r2 r3 depth)
   (cond
      ((null r3) (c!:printf1 "    %v = nil;\n" (list r1)))
      ((equal r3 't) (c!:printf1 "    %v = lisp_true;\n" (list r1)))
      (t (c!:printf1
            "    %v = (Lisp_Object)%s; /* %a */\n"
            (list r1 (plus (times 16 r3) 1) r3)))) )


(put 'movk1 'c!:opcode_printer (function c!:pmovk1))


(de c!:preloadenv (op r1 r2 r3 depth)
   (c!:printf1 "    env = stack[%s];\n" (list (minus reloadenv))))


(put 'reloadenv 'c!:opcode_printer (function c!:preloadenv))


(de c!:pldrglob (op r1 r2 r3 depth)
   (c!:printf1 "    %v = qvalue(elt(env, %s)); /* %a */\n" (list r1 r3 r2)))


(put 'ldrglob 'c!:opcode_printer (function c!:pldrglob))


(de c!:pstrglob (op r1 r2 r3 depth)
   (c!:printf1 "    qvalue(elt(env, %s)) = %v; /* %a */\n" (list r3 r1 r2)))


(put 'strglob 'c!:opcode_printer (function c!:pstrglob))


(de c!:pnilglob (op r1 r2 r3 depth)
   (c!:printf1 "    qvalue(elt(env, %s)) = nil; /* %a */\n" (list r3 r2)))


(put 'nilglob 'c!:opcode_printer (function c!:pnilglob))


(de c!:pnull (op r1 r2 r3 depth)
   (c!:printf1 "    %v = (%v == nil ? lisp_true : nil);\n" (list r1 r3)))


(put 'null 'c!:opcode_printer (function c!:pnull))


(put 'not 'c!:opcode_printer (function c!:pnull))


(flag '(null not) 'c!:uses_nil)


(de c!:pfastget (op r1 r2 r3 depth)
   (progn
      (c!:printf1 "    if (!symbolp(%v)) %v = nil;\n" (list r2 r1))
      (c!:printf1 "    else { %v = qfastgets(%v);\n" (list r1 r2))
      (c!:printf1
         "           if (%v != nil) { %v = elt(%v, %s); /* %s */\n"
         (list r1 r1 r1 (car r3) (cdr r3)))
      (c!:printf1 "#ifdef RECORD_GET\n" (list))
      (c!:printf1 "             if (%v != SPID_NOPROP)\n" (list r1))
      (c!:printf1
         "                record_get(elt(fastget_names, %s), 1);\n"
         (list (car r3)))
      (c!:printf1
         "             else record_get(elt(fastget_names, %s), 0),\n"
         (list (car r3)))
      (c!:printf1 "                %v = nil; }\n" (list r1))
      (c!:printf1
         "           else record_get(elt(fastget_names, %s), 0); }\n"
         (list (car r3)))
      (c!:printf1 "#else\n" (list))
      (c!:printf1
         "             if (%v == SPID_NOPROP) %v = nil; }}\n"
         (list r1 r1))
      (c!:printf1 "#endif\n" (list))
      nil))


(put 'fastget 'c!:opcode_printer (function c!:pfastget))


(flag '(fastget) 'c!:uses_nil)


(de c!:pfastflag (op r1 r2 r3 depth)
   (progn
      (c!:printf1 "    if (!symbolp(%v)) %v = nil;\n" (list r2 r1))
      (c!:printf1 "    else { %v = qfastgets(%v);\n" (list r1 r2))
      (c!:printf1
         "           if (%v != nil) { %v = elt(%v, %s); /* %s */\n"
         (list r1 r1 r1 (car r3) (cdr r3)))
      (c!:printf1 "#ifdef RECORD_GET\n" (list))
      (c!:printf1 "             if (%v == SPID_NOPROP)\n" (list r1))
      (c!:printf1
         "                record_get(elt(fastget_names, %s), 0),\n"
         (list (car r3)))
      (c!:printf1 "                %v = nil;\n" (list r1))
      (c!:printf1
         "             else record_get(elt(fastget_names, %s), 1),\n"
         (list (car r3)))
      (c!:printf1 "                %v = lisp_true; }\n" (list r1))
      (c!:printf1
         "           else record_get(elt(fastget_names, %s), 0); }\n"
         (list (car r3)))
      (c!:printf1 "#else\n" (list))
      (c!:printf1
   "             if (%v == SPID_NOPROP) %v = nil; else %v = lisp_true; }}\n"
         (list r1 r1 r1))
      (c!:printf1 "#endif\n" (list))
      nil))


(put 'fastflag 'c!:opcode_printer (function c!:pfastflag))


(flag '(fastflag) 'c!:uses_nil)


(de c!:pcar (op r1 r2 r3 depth)
   (prog nil
      (cond
         ((not !*unsafecar)
            (progn
               (c!:printf1 "    if (!car_legal(%v)) " (list r3))
               (c!:pgoto
                  (c!:find_error_label (list 'car r3) r2 depth)
                  depth))))
      (c!:printf1 "    %v = qcar(%v);\n" (list r1 r3))))


(put 'car 'c!:opcode_printer (function c!:pcar))


(de c!:pcdr (op r1 r2 r3 depth)
   (prog nil
      (cond
         ((not !*unsafecar)
            (progn
               (c!:printf1 "    if (!car_legal(%v)) " (list r3))
               (c!:pgoto
                  (c!:find_error_label (list 'cdr r3) r2 depth)
                  depth))))
      (c!:printf1 "    %v = qcdr(%v);\n" (list r1 r3))))


(put 'cdr 'c!:opcode_printer (function c!:pcdr))


(de c!:pqcar (op r1 r2 r3 depth)
   (c!:printf1 "    %v = qcar(%v);\n" (list r1 r3)))


(put 'qcar 'c!:opcode_printer (function c!:pqcar))


(de c!:pqcdr (op r1 r2 r3 depth)
   (c!:printf1 "    %v = qcdr(%v);\n" (list r1 r3)))


(put 'qcdr 'c!:opcode_printer (function c!:pqcdr))


(de c!:patom (op r1 r2 r3 depth)
   (c!:printf1 "    %v = (!consp(%v) ? lisp_true : nil);\n" (list r1 r3)))


(put 'atom 'c!:opcode_printer (function c!:patom))


(de c!:pnumberp (op r1 r2 r3 depth)
   (c!:printf1 "    %v = (is_number(%v) ? lisp_true : nil);\n" (list r1 r3)))


(put 'numberp 'c!:opcode_printer (function c!:pnumberp))


(de c!:pfixp (op r1 r2 r3 depth)
   (c!:printf1 "    %v = integerp(%v);\n" (list r1 r3)))


(put 'fixp 'c!:opcode_printer (function c!:pfixp))


(de c!:piminusp (op r1 r2 r3 depth)
   (c!:printf1
      "    %v = ((int32)(%v) < 0 ? lisp_true : nil);\n"
      (list r1 r3)))


(put 'iminusp 'c!:opcode_printer (function c!:piminusp))


(de c!:pilessp (op r1 r2 r3 depth)
   (c!:printf1
      "    %v = ((int32)%v < (int32)%v) ? lisp_true : nil;\n"
      (list r1 r2 r3)))


(put 'ilessp 'c!:opcode_printer (function c!:pilessp))


(de c!:pigreaterp (op r1 r2 r3 depth)
   (c!:printf1
      "    %v = ((int32)%v > (int32)%v) ? lisp_true : nil;\n"
      (list r1 r2 r3)))


(put 'igreaterp 'c!:opcode_printer (function c!:pigreaterp))


(de c!:piminus (op r1 r2 r3 depth)
   (c!:printf1 "    %v = (Lisp_Object)(2-((int32)(%v)));\n" (list r1 r3)))


(put 'iminus 'c!:opcode_printer (function c!:piminus))


(de c!:piadd1 (op r1 r2 r3 depth)
   (c!:printf1 "    %v = (Lisp_Object)((int32)(%v) + 0x10);\n" (list r1 r3)))


(put 'iadd1 'c!:opcode_printer (function c!:piadd1))


(de c!:pisub1 (op r1 r2 r3 depth)
   (c!:printf1 "    %v = (Lisp_Object)((int32)(%v) - 0x10);\n" (list r1 r3)))


(put 'isub1 'c!:opcode_printer (function c!:pisub1))


(de c!:piplus2 (op r1 r2 r3 depth)
   (c!:printf1
      "    %v = (Lisp_Object)((int32)%v + (int32)%v - TAG_FIXNUM);\n"
      (list r1 r2 r3)))


(put 'iplus2 'c!:opcode_printer (function c!:piplus2))


(de c!:pidifference (op r1 r2 r3 depth)
   (c!:printf1
      "    %v = (Lisp_Object)((int32)%v - (int32)%v + TAG_FIXNUM);\n"
      (list r1 r2 r3)))


(put 'idifference 'c!:opcode_printer (function c!:pidifference))


(de c!:pitimes2 (op r1 r2 r3 depth)
   (c!:printf1
      "    %v = fixnum_of_int(int_of_fixnum(%v) * int_of_fixnum(%v));\n"
      (list r1 r2 r3)))


(put 'itimes2 'c!:opcode_printer (function c!:pitimes2))


(de c!:pmodular_plus (op r1 r2 r3 depth)
   (progn
      (c!:printf1
         "    {   int32 w = int_of_fixnum(%v) + int_of_fixnum(%v);\n"
         (list r2 r3))
      (c!:printf1
         "        if (w >= current_modulus) w -= current_modulus;\n"
         (list))
      (c!:printf1 "        %v = fixnum_of_int(w);\n" (list r1))
      (c!:printf1 "    }\n" (list))))


(put 'modular!-plus 'c!:opcode_printer (function c!:pmodular_plus))


(de c!:pmodular_difference (op r1 r2 r3 depth)
   (progn
      (c!:printf1
         "    {   int32 w = int_of_fixnum(%v) - int_of_fixnum(%v);\n"
         (list r2 r3))
      (c!:printf1 "        if (w < 0) w += current_modulus;\n" (list))
      (c!:printf1 "        %v = fixnum_of_int(w);\n" (list r1))
      (c!:printf1 "    }\n" (list))))


(put
   'modular!-difference
   'c!:opcode_printer
   (function c!:pmodular_difference))


(de c!:pmodular_minus (op r1 r2 r3 depth)
   (progn
      (c!:printf1 "    {   int32 w = int_of_fixnum(%v);\n" (list r3))
      (c!:printf1 "        if (w != 0) w = current_modulus - w;\n" (list))
      (c!:printf1 "        %v = fixnum_of_int(w);\n" (list r1))
      (c!:printf1 "    }\n" (list))))


(put 'modular!-minus 'c!:opcode_printer (function c!:pmodular_minus))


(de c!:passoc (op r1 r2 r3 depth)
   (c!:printf1 "    %v = Lassoc(nil, %v, %v);\n" (list r1 r2 r3)))


(put 'assoc 'c!:opcode_printer (function c!:passoc))


(flag '(assoc) 'c!:uses_nil)


(de c!:patsoc (op r1 r2 r3 depth)
   (c!:printf1 "    %v = Latsoc(nil, %v, %v);\n" (list r1 r2 r3)))


(put 'atsoc 'c!:opcode_printer (function c!:patsoc))


(flag '(atsoc) 'c!:uses_nil)


(de c!:pmember (op r1 r2 r3 depth)
   (c!:printf1 "    %v = Lmember(nil, %v, %v);\n" (list r1 r2 r3)))


(put 'member 'c!:opcode_printer (function c!:pmember))


(flag '(member) 'c!:uses_nil)


(de c!:pmemq (op r1 r2 r3 depth)
   (c!:printf1 "    %v = Lmemq(nil, %v, %v);\n" (list r1 r2 r3)))


(put 'memq 'c!:opcode_printer (function c!:pmemq))


(flag '(memq) 'c!:uses_nil)


(de c!:pget (op r1 r2 r3 depth)
   (c!:printf1 "    %v = get(%v, %v);\n" (list r1 r2 r3)))


(put 'get 'c!:opcode_printer (function c!:pget))


(de c!:pqgetv (op r1 r2 r3 depth)
   (progn
      (c!:printf1
         "    %v = *(Lisp_Object *)((char *)%v + (4L-TAG_VECTOR) +"
         (list r1 r2))
      (c!:printf1 " ((int32)%v>>2));\n" (list r3))))


(put 'qgetv 'c!:opcode_printer (function c!:pqgetv))


(de c!:pqputv (op r1 r2 r3 depth)
   (progn
      (c!:printf1
         "    *(Lisp_Object *)((char *)%v + (4L-TAG_VECTOR) +"
         (list r2))
      (c!:printf1 " ((int32)%v>>2)) = %v;\n" (list r3 r1))))


(put 'qputv 'c!:opcode_printer (function c!:pqputv))


(de c!:peq (op r1 r2 r3 depth)
   (c!:printf1 "    %v = (%v == %v ? lisp_true : nil);\n" (list r1 r2 r3)))


(put 'eq 'c!:opcode_printer (function c!:peq))


(flag '(eq) 'c!:uses_nil)


(de c!:pequal (op r1 r2 r3 depth)
   (c!:printf1
      "    %v = (equal(%v, %v) ? lisp_true : nil);\n"
      (list r1 r2 r3 r2 r3)))


(put 'equal 'c!:opcode_printer (function c!:pequal))


(flag '(equal) 'c!:uses_nil)


(de c!:pfluidbind (op r1 r2 r3 depth) nil)


(put 'fluidbind 'c!:opcode_printer (function c!:pfluidbind))


(de c!:pcall (op r1 r2 r3 depth)
   (prog (w boolfn)
      (cond
         ((setq w (get (car r3) 'c!:direct_entrypoint))
            (progn
               (c!:printf1 "    %v = %s(" (list r1 (cdr w)))
               (cond
                  (r2
                     (progn
                        (c!:printf1 "%v" (list (car r2)))
                        (prog (a)
                           (setq a (cdr r2))
                     lab   (cond ((null a) (return nil)))
                           ((lambda (a) (c!:printf1 ", %v" (list a))) (car a))
                           (setq a (cdr a))
                           (go lab)))) )
               (c!:printf1 ");\n" (list))))
         ((setq w (get (car r3) 'c!:direct_predicate))
            (progn
               (setq boolfn t)
               (c!:printf1 "    %v = (Lisp_Object)%s(" (list r1 (cdr w)))
               (cond
                  (r2
                     (progn
                        (c!:printf1 "%v" (list (car r2)))
                        (prog (a)
                           (setq a (cdr r2))
                     lab   (cond ((null a) (return nil)))
                           ((lambda (a) (c!:printf1 ", %v" (list a))) (car a))
                           (setq a (cdr a))
                           (go lab)))) )
               (c!:printf1 ");\n" (list))))
         ((equal (car r3) current_procedure)
            (progn
               (c!:printf1 "    %v = %s(env" (list r1 current_c_name))
               (cond
                  ((or (null r2) (geq (length r2) 3))
                     (c!:printf1 ", %s" (list (length r2)))) )
               (prog (a)
                  (setq a r2)
            lab   (cond ((null a) (return nil)))
                  ((lambda (a) (c!:printf1 ", %v" (list a))) (car a))
                  (setq a (cdr a))
                  (go lab))
               (c!:printf1 ");\n" (list))))
         ((setq w (get (car r3) 'c!:c_entrypoint))
            (progn
               (c!:printf1 "    %v = %s(nil" (list r1 w))
               (cond
                  ((or (null r2) (geq (length r2) 3))
                     (c!:printf1 ", %s" (list (length r2)))) )
               (prog (a)
                  (setq a r2)
            lab   (cond ((null a) (return nil)))
                  ((lambda (a) (c!:printf1 ", %v" (list a))) (car a))
                  (setq a (cdr a))
                  (go lab))
               (c!:printf1 ");\n" (list))))
         (t (prog (nargs)
               (setq nargs (length r2))
               (c!:printf1
                  "    fn = elt(env, %s); /* %a */\n"
                  (list (c!:find_literal (car r3)) (car r3)))
               (cond
                  ((equal nargs 1)
                     (c!:printf1 "    %v = (*qfn1(fn))(qenv(fn)" (list r1)))
                  ((equal nargs 2)
                     (c!:printf1 "    %v = (*qfn2(fn))(qenv(fn)" (list r1)))
                  (t (c!:printf1
                        "    %v = (*qfnn(fn))(qenv(fn), %s"
                        (list r1 nargs))))
               (prog (a)
                  (setq a r2)
            lab   (cond ((null a) (return nil)))
                  ((lambda (a) (c!:printf1 ", %v" (list a))) (car a))
                  (setq a (cdr a))
                  (go lab))
               (c!:printf1 ");\n" (list)))) )
      (cond
         ((not (flagp (car r3) 'c!:no_errors))
            (progn
               (cond
                  ((and (null (cadr r3)) (equal depth 0))
                     (c!:printf1 "    errexit();\n" (list)))
                  (t (progn
                        (c!:printf1 "    nil = C_nil;\n" (list))
                        (c!:printf1 "    if (exception_pending()) " (list))
                        (c!:pgoto
                           (c!:find_error_label nil (cadr r3) depth)
                           depth)))) )))
      (cond
         (boolfn
            (c!:printf1 "    %v = %v ? lisp_true : nil;\n" (list r1 r1)))) ))


(put 'call 'c!:opcode_printer (function c!:pcall))


(de c!:pgoto (lab depth)
   (prog nil
      (cond ((atom lab) (return (c!:printf1 "goto %s;\n" (list lab)))) )
      (setq lab (get (car lab) 'c!:chosen))
      (cond
         ((zerop depth) (c!:printf1 "return onevalue(%v);\n" (list lab)))
         ((flagp lab 'c!:live_across_call)
            (c!:printf1
               "{ Lisp_Object res = %v; popv(%s); return onevalue(res); }\n"
               (list lab depth)))
         (t (c!:printf1
               "{ popv(%s); return onevalue(%v); }\n"
               (list depth lab)))) ))


(de c!:pifnull (s depth) (c!:printf1 "%v == nil" (list (car s))))


(put 'ifnull 'c!:exit_helper (function c!:pifnull))


(de c!:pifatom (s depth) (c!:printf1 "!consp(%v)" (list (car s))))


(put 'ifatom 'c!:exit_helper (function c!:pifatom))


(de c!:pifsymbol (s depth) (c!:printf1 "symbolp(%v)" (list (car s))))


(put 'ifsymbol 'c!:exit_helper (function c!:pifsymbol))


(de c!:pifnumber (s depth) (c!:printf1 "is_number(%v)" (list (car s))))


(put 'ifnumber 'c!:exit_helper (function c!:pifnumber))


(de c!:pifizerop (s depth) (c!:printf1 "(%v) == 1" (list (car s))))


(put 'ifizerop 'c!:exit_helper (function c!:pifizerop))


(de c!:pifeq (s depth) (c!:printf1 "%v == %v" (list (car s) (cadr s))))


(put 'ifeq 'c!:exit_helper (function c!:pifeq))


(de c!:pifequal (s depth)
   (c!:printf1 "equal(%v, %v)" (list (car s) (cadr s) (car s) (cadr s))))


(put 'ifequal 'c!:exit_helper (function c!:pifequal))


(de c!:pifilessp (s depth)
   (c!:printf1 "((int32)(%v)) < ((int32)(%v))" (list (car s) (cadr s))))


(put 'ifilessp 'c!:exit_helper (function c!:pifilessp))


(de c!:pifigreaterp (s depth)
   (c!:printf1 "((int32)(%v)) > ((int32)(%v))" (list (car s) (cadr s))))


(put 'ifigreaterp 'c!:exit_helper (function c!:pifigreaterp))


(de c!:display_flowgraph (s depth dropping_through)
   (cond
      ((not (atom s)) (progn (c!:printf1 "    " (list)) (c!:pgoto s depth)))
      ((not (flagp s 'c!:visited))
         (prog (why where_to)
            (flag (list s) 'c!:visited)
            (cond
               ((or (not dropping_through) (not (equal (get s 'c!:count) 1)))
                  (c!:printf1 "\n%s:\n" (list s))))
            (prog (k)
               (setq k (reverse (get s 'c!:contents)))
         lab   (cond ((null k) (return nil)))
               ((lambda (k) (c!:print_opcode k depth)) (car k))
               (setq k (cdr k))
               (go lab))
            (setq why (get s 'c!:why))
            (setq where_to (get s 'c!:where_to))
            (cond
               ((and
                   (equal why 'goto)
                   (or
                      (not (atom (car where_to)))
                      (and
                         (not (flagp (car where_to) 'c!:visited))
                         (equal (get (car where_to) 'c!:count) 1))))
                  (c!:display_flowgraph (car where_to) depth t))
               (t (c!:print_exit_condition why where_to depth)))) )))


(fluid '(startpoint))


(de c!:branch_chain (s count)
   (prog (contents why where_to n)
      (cond
         ((not (atom s)) (return s))
         ((flagp s 'c!:visited)
            (progn
               (setq n (get s 'c!:count))
               (cond ((null n) (setq n 1)) (t (setq n (plus n 1))))
               (put s 'c!:count n)
               (return s))))
      (flag (list s) 'c!:visited)
      (setq contents (get s 'c!:contents))
      (setq why (get s 'c!:why))
      (setq where_to
         (prog (z !G58 endptr)
            (setq z (get s 'c!:where_to))
            (cond ((null z) (return nil)))
            (setq !G58
               (setq endptr
                  (cons
                     ((lambda (z) (c!:branch_chain z count)) (car z))
                     nil)))
      looplabel
            (setq z (cdr z))
            (cond ((null z) (return !G58)))
            (rplacd
               endptr
               (cons ((lambda (z) (c!:branch_chain z count)) (car z)) nil))
            (setq endptr (cdr endptr))
            (go looplabel)))
      (prog nil
   !G59  (cond
            ((not
                (and
                   contents
                   (eqcar (car contents) 'movr)
                   (equal why 'goto)
                   (not (atom (car where_to)))
                   (equal (caar where_to) (cadr (car contents)))) )
               (return nil)))
         (progn
            (setq where_to (list (list (cadddr (car contents)))) )
            (setq contents (cdr contents)))
         (go !G59))
      (put s 'c!:contents contents)
      (put s 'c!:where_to where_to)
      (cond
         ((and (null contents) (equal why 'goto))
            (progn (remflag (list s) 'c!:visited) (return (car where_to)))) )
      (cond
         (count
            (progn
               (setq n (get s 'c!:count))
               (cond ((null n) (setq n 1)) (t (setq n (plus n 1))))
               (put s 'c!:count n))))
      (return s)))


(de c!:one_operand (op)
   (progn
      (flag (list op) 'c!:set_r1)
      (flag (list op) 'c!:read_r3)
      (put op 'c!:code (function c!:builtin_one))))


(de c!:two_operands (op)
   (progn
      (flag (list op) 'c!:set_r1)
      (flag (list op) 'c!:read_r2)
      (flag (list op) 'c!:read_r3)
      (put op 'c!:code (function c!:builtin_two))))


(prog (n)
   (setq n
      '(car cdr qcar qcdr null not atom numberp fixp iminusp iminus iadd1
          isub1 modular!-minus))
lab(cond ((null n) (return nil)))
   ((lambda (n) (c!:one_operand n)) (car n))
   (setq n (cdr n))
   (go lab))


(prog (n)
   (setq n
      '(eq equal atsoc memq iplus2 idifference assoc member itimes2 ilessp
          igreaterp qgetv get modular!-plus modular!-difference))
lab(cond ((null n) (return nil)))
   ((lambda (n) (c!:two_operands n)) (car n))
   (setq n (cdr n))
   (go lab))


(flag '(movr movk movk1 ldrglob call reloadenv fastget fastflag) 'c!:set_r1)


(flag '(strglob qputv) 'c!:read_r1)


(flag '(qputv fastget fastflag) 'c!:read_r2)


(flag '(movr qputv) 'c!:read_r3)


(flag '(ldrglob strglob nilglob movk call) 'c!:read_env)


(fluid '(fn_used nil_used nilbase_used))


(de c!:live_variable_analysis (all_blocks)
   (prog (changed z)
      (prog nil
   !G60  (progn
            (setq changed nil)
            (prog (b)
               (setq b all_blocks)
         lab   (cond ((null b) (return nil)))
               ((lambda (b)
                   (prog (w live)
                      (prog (x)
                         (setq x (get b 'c!:where_to))
                   lab   (cond ((null x) (return nil)))
                         ((lambda (x)
                             (cond
                                ((atom x)
                                   (setq live (union live (get x 'c!:live))))
                                (t (setq live (union live x)))) )
                            (car x))
                         (setq x (cdr x))
                         (go lab))
                      (setq w (get b 'c!:why))
                      (cond
                         ((not (atom w))
                            (progn
                               (cond
                                  ((or (eqcar w 'ifnull) (eqcar w 'ifequal))
                                     (setq nil_used t)))
                               (setq live (union live (cdr w)))
                               (cond
                                  ((and
                                      (eqcar (car w) 'call)
                                      (or
                                         (flagp
                                            (cadar w)
                                            'c!:direct_predicate)
                                         (and
                                            (flagp (cadar w) 'c!:c_entrypoint)
                                            (not
                                               (flagp
                                                  (cadar w)
                                                  'c!:direct_entrypoint)))) )
                                     (setq nil_used t)))
                               (cond
                                  ((and
                                      (eqcar (car w) 'call)
                                      (not
                                         (equal (cadar w) current_procedure))
                                      (not
                                         (get
                                            (cadar w)
                                            'c!:direct_entrypoint))
                                      (not (get (cadar w) 'c!:c_entrypoint)))
                                     (progn
                                        (setq fn_used t)
                                        (setq live
                                           (union '(env) live)))) ))) )
                      (prog (s)
                         (setq s (get b 'c!:contents))
                   lab   (cond ((null s) (return nil)))
                         ((lambda (s)
                             (prog (op r1 r2 r3)
                                (setq op (car s))
                                (setq r1 (cadr s))
                                (setq r2 (caddr s))
                                (setq r3 (cadddr s))
                                (cond
                                   ((equal op 'movk1)
                                      (progn
                                         (cond
                                            ((equal r3 nil) (setq nil_used t))
                                            ((equal r3 't)
                                               (setq nilbase_used t)))) )
                                   ((and (atom op) (flagp op 'c!:uses_nil))
                                      (setq nil_used t)))
                                (cond
                                   ((flagp op 'c!:set_r1)
                                      (cond
                                         ((memq r1 live)
                                            (setq live (delete r1 live)))
                                         ((equal op 'call) nil)
                                         (t (setq op 'nop)))) )
                                (cond
                                   ((flagp op 'c!:read_r1)
                                      (setq live (union live (list r1)))) )
                                (cond
                                   ((flagp op 'c!:read_r2)
                                      (setq live (union live (list r2)))) )
                                (cond
                                   ((flagp op 'c!:read_r3)
                                      (setq live (union live (list r3)))) )
                                (cond
                                   ((equal op 'call)
                                      (progn
                                         (cond
                                            ((or
                                                (not
                                                   (flagp
                                                      (car r3)
                                                      'c!:no_errors))
                                                (flagp
                                                   (car r3)
                                                   'c!:c_entrypoint)
                                                (get
                                                   (car r3)
                                                   'c!:direct_predicate))
                                               (setq nil_used t)))
                                         (setq does_call t)
                                         (cond
                                            ((and
                                                (not
                                                   (eqcar
                                                      r3
                                                      current_procedure))
                                                (not
                                                   (get
                                                      (car r3)
                                                      'c!:direct_entrypoint))
                                                (not
                                                   (get
                                                      (car r3)
                                                      'c!:c_entrypoint)))
                                               (setq fn_used t)))
                                         (cond
                                            ((not
                                                (flagp
                                                   (car r3)
                                                   'c!:no_errors))
                                               (flag
                                                  live
                                                  'c!:live_across_call)))
                                         (setq live (union live r2)))) )
                                (cond
                                   ((flagp op 'c!:read_env)
                                      (setq live (union live '(env)))) )))
                            (car s))
                         (setq s (cdr s))
                         (go lab))
                      (setq live (sort live (function orderp)))
                      (cond
                         ((not (equal live (get b 'c!:live)))
                            (progn
                               (put b 'c!:live live)
                               (setq changed t)))) ))
                  (car b))
               (setq b (cdr b))
               (go lab)))
         (cond ((not (not changed)) (go !G60))))
      (setq z registers)
      (setq registers (setq stacklocs nil))
      (prog (r)
         (setq r z)
   lab   (cond ((null r) (return nil)))
         ((lambda (r)
             (cond
                ((flagp r 'c!:live_across_call)
                   (setq stacklocs (cons r stacklocs)))
                (t (setq registers (cons r registers)))) )
            (car r))
         (setq r (cdr r))
         (go lab))))


(de c!:insert1 (a b) (cond ((memq a b) b) (t (cons a b))))


(de c!:clash (a b)
   (cond
      ((equal (flagp a 'c!:live_across_call) (flagp b 'c!:live_across_call))
         (progn
            (put a 'c!:clash (c!:insert1 b (get a 'c!:clash)))
            (put b 'c!:clash (c!:insert1 a (get b 'c!:clash)))) )))


(de c!:build_clash_matrix (all_blocks)
   (prog nil
      (prog (b)
         (setq b all_blocks)
   lab   (cond ((null b) (return nil)))
         ((lambda (b)
             (prog (live w)
                (prog (x)
                   (setq x (get b 'c!:where_to))
             lab   (cond ((null x) (return nil)))
                   ((lambda (x)
                       (cond
                          ((atom x) (setq live (union live (get x 'c!:live))))
                          (t (setq live (union live x)))) )
                      (car x))
                   (setq x (cdr x))
                   (go lab))
                (setq w (get b 'c!:why))
                (cond
                   ((not (atom w))
                      (progn
                         (setq live (union live (cdr w)))
                         (cond
                            ((and
                                (eqcar (car w) 'call)
                                (not (get (cadar w) 'c!:direct_entrypoint))
                                (not (get (cadar w) 'c!:c_entrypoint)))
                               (setq live (union '(env) live)))) )))
                (prog (s)
                   (setq s (get b 'c!:contents))
             lab   (cond ((null s) (return nil)))
                   ((lambda (s)
                       (prog (op r1 r2 r3)
                          (setq op (car s))
                          (setq r1 (cadr s))
                          (setq r2 (caddr s))
                          (setq r3 (cadddr s))
                          (cond
                             ((flagp op 'c!:set_r1)
                                (cond
                                   ((memq r1 live)
                                      (progn
                                         (setq live (delete r1 live))
                                         (cond
                                            ((equal op 'reloadenv)
                                               (setq reloadenv t)))
                                         (prog (v)
                                            (setq v live)
                                      lab   (cond ((null v) (return nil)))
                                            ((lambda (v) (c!:clash r1 v))
                                               (car v))
                                            (setq v (cdr v))
                                            (go lab))))
                                   ((equal op 'call) nil)
                                   (t (progn
                                         (setq op 'nop)
                                         (rplacd s (cons (car s) (cdr s)))
                                         (rplaca s op)))) ))
                          (cond
                             ((flagp op 'c!:read_r1)
                                (setq live (union live (list r1)))) )
                          (cond
                             ((flagp op 'c!:read_r2)
                                (setq live (union live (list r2)))) )
                          (cond
                             ((flagp op 'c!:read_r3)
                                (setq live (union live (list r3)))) )
                          (cond
                             ((equal op 'call) (setq live (union live r2))))
                          (cond
                             ((flagp op 'c!:read_env)
                                (setq live (union live '(env)))) )))
                      (car s))
                   (setq s (cdr s))
                   (go lab))))
            (car b))
         (setq b (cdr b))
         (go lab))
      (return nil)))


(de c!:allocate_registers (rl)
   (prog (schedule neighbours allocation)
      (setq neighbours 0)
      (prog nil
   !G61  (cond ((not rl) (return nil)))
         (prog (w x)
            (setq w rl)
            (prog nil
         !G62  (cond
                  ((not
                      (and
                         w
                         (greaterp
                            (length (setq x (get (car w) 'c!:clash)))
                            neighbours)))
                     (return nil)))
               (setq w (cdr w))
               (go !G62))
            (cond
               (w
                  (progn
                     (setq schedule (cons (car w) schedule))
                     (setq rl (deleq (car w) rl))
                     (prog (r)
                        (setq r x)
                  lab   (cond ((null r) (return nil)))
                        ((lambda (r)
                            (put
                               r
                               'c!:clash
                               (deleq (car w) (get r 'c!:clash))))
                           (car r))
                        (setq r (cdr r))
                        (go lab))))
               (t (setq neighbours (plus neighbours 1)))) )
         (go !G61))
      (prog (r)
         (setq r schedule)
   lab   (cond ((null r) (return nil)))
         ((lambda (r)
             (prog (poss)
                (setq poss allocation)
                (prog (x)
                   (setq x (get r 'c!:clash))
             lab   (cond ((null x) (return nil)))
                   ((lambda (x) (setq poss (deleq (get x 'c!:chosen) poss)))
                      (car x))
                   (setq x (cdr x))
                   (go lab))
                (cond
                   ((null poss)
                      (progn
                         (setq poss (c!:my_gensym))
                         (setq allocation (append allocation (list poss)))) )
                   (t (setq poss (car poss))))
                (put r 'c!:chosen poss)))
            (car r))
         (setq r (cdr r))
         (go lab))
      (return allocation)))


(de c!:remove_nops (all_blocks)
   (prog (b)
      (setq b all_blocks)
lab   (cond ((null b) (return nil)))
      ((lambda (b)
          (prog (r)
             (prog (s)
                (setq s (get b 'c!:contents))
          lab   (cond ((null s) (return nil)))
                ((lambda (s)
                    (cond
                       ((not (eqcar s 'nop))
                          (prog (op r1 r2 r3)
                             (setq op (car s))
                             (setq r1 (cadr s))
                             (setq r2 (caddr s))
                             (setq r3 (cadddr s))
                             (cond
                                ((or
                                    (flagp op 'c!:set_r1)
                                    (flagp op 'c!:read_r1))
                                   (setq r1 (get r1 'c!:chosen))))
                             (cond
                                ((flagp op 'c!:read_r2)
                                   (setq r2 (get r2 'c!:chosen))))
                             (cond
                                ((flagp op 'c!:read_r3)
                                   (setq r3 (get r3 'c!:chosen))))
                             (cond
                                ((equal op 'call)
                                   (setq r2
                                      (prog (v !G63 endptr)
                                         (setq v r2)
                                         (cond ((null v) (return nil)))
                                         (setq !G63
                                            (setq endptr
                                               (cons
                                                  ((lambda (v)
                                                      (get v 'c!:chosen))
                                                     (car v))
                                                  nil)))
                                   looplabel
                                         (setq v (cdr v))
                                         (cond ((null v) (return !G63)))
                                         (rplacd
                                            endptr
                                            (cons
                                               ((lambda (v)
                                                   (get v 'c!:chosen))
                                                  (car v))
                                               nil))
                                         (setq endptr (cdr endptr))
                                         (go looplabel)))) )
                             (cond
                                ((not (and (equal op 'movr) (equal r1 r3)))
                                   (setq r
                                      (cons (list op r1 r2 r3) r)))) ))) )
                   (car s))
                (setq s (cdr s))
                (go lab))
             (put b 'c!:contents (reversip r))
             (setq r (get b 'c!:why))
             (cond
                ((not (atom r))
                   (put
                      b
                      'c!:why
                      (cons
                         (car r)
                         (prog (v !G64 endptr)
                            (setq v (cdr r))
                            (cond ((null v) (return nil)))
                            (setq !G64
                               (setq endptr
                                  (cons
                                     ((lambda (v) (get v 'c!:chosen)) (car v))
                                     nil)))
                      looplabel
                            (setq v (cdr v))
                            (cond ((null v) (return !G64)))
                            (rplacd
                               endptr
                               (cons
                                  ((lambda (v) (get v 'c!:chosen)) (car v))
                                  nil))
                            (setq endptr (cdr endptr))
                            (go looplabel)))) ))) )
         (car b))
      (setq b (cdr b))
      (go lab)))


(fluid '(error_labels))


(de c!:find_error_label (why env depth)
   (prog (w z)
      (setq z (list why env depth))
      (setq w (assoc!*!* z error_labels))
      (cond
         ((null w)
            (progn
               (setq w (cons z (c!:my_gensym)))
               (setq error_labels (cons w error_labels)))) )
      (return (cdr w))))


(de c!:assign (u v c)
   (cond
      ((flagp u 'fluid) (cons (list 'strglob v u (c!:find_literal u)) c))
      (t (cons (list 'movr u nil v) c))))


(de c!:insert_tailcall (b)
   (prog (why dest contents fcall res w)
      (setq why (get b 'c!:why))
      (setq dest (get b 'c!:where_to))
      (setq contents (get b 'c!:contents))
      (prog nil
   !G65  (cond
            ((not (and contents (not (eqcar (car contents) 'call))))
               (return nil)))
         (progn
            (setq w (cons (car contents) w))
            (setq contents (cdr contents)))
         (go !G65))
      (cond ((null contents) (return nil)))
      (setq fcall (car contents))
      (setq contents (cdr contents))
      (setq res (cadr fcall))
      (prog nil
   !G66  (cond ((not w) (return nil)))
         (progn
            (cond
               ((eqcar (car w) 'reloadenv) (setq w (cdr w)))
               ((and (eqcar (car w) 'movr) (equal (cadddr (car w)) res))
                  (progn (setq res (cadr (car w))) (setq w (cdr w))))
               (t (setq res (setq w nil)))) )
         (go !G66))
      (cond ((null res) (return nil)))
      (cond
         ((c!:does_return res why dest)
            (cond
               ((equal (car (cadddr fcall)) current_procedure)
                  (progn
                     (prog (p)
                        (setq p (pair current_args (caddr fcall)))
                  lab   (cond ((null p) (return nil)))
                        ((lambda (p)
                            (setq contents
                               (c!:assign (car p) (cdr p) contents)))
                           (car p))
                        (setq p (cdr p))
                        (go lab))
                     (put b 'c!:contents contents)
                     (put b 'c!:why 'goto)
                     (put b 'c!:where_to (list restart_label))))
               (t (progn
                     (setq nil_used t)
                     (put b 'c!:contents contents)
                     (put
                        b
                        'c!:why
                        (cons
                           (list 'call (car (cadddr fcall)))
                           (caddr fcall)))
                     (put b 'c!:where_to nil)))) ))) )


(de c!:does_return (res why where_to)
   (cond
      ((not (equal why 'goto)) nil)
      ((not (atom (car where_to))) (equal res (caar where_to)))
      (t (prog (contents)
            (setq where_to (car where_to))
            (setq contents (reverse (get where_to 'c!:contents)))
            (setq why (get where_to 'c!:why))
            (setq where_to (get where_to 'c!:where_to))
            (prog nil
         !G67  (cond ((not contents) (return nil)))
               (cond
                  ((eqcar (car contents) 'reloadenv)
                     (setq contents (cdr contents)))
                  ((and
                      (eqcar (car contents) 'movr)
                      (equal (cadddr (car contents)) res))
                     (progn
                        (setq res (cadr (car contents)))
                        (setq contents (cdr contents))))
                  (t (setq res (setq contents nil))))
               (go !G67))
            (cond
               ((null res) (return nil))
               (t (return (c!:does_return res why where_to)))) ))) )


(de c!:pushpop (op v)
   (prog (n w)
      (cond ((null v) (return nil)))
      (setq n (length v))
      (cond
         ((equal n 1)
            (return (c!:printf1 "        %s(%s);\n" (list op (car v)))) ))
      (prog nil
   !G68  (cond ((not (greaterp n 0)) (return nil)))
         (progn
            (setq w n)
            (cond ((greaterp w 6) (setq w 6)))
            (setq n (difference n w))
            (c!:printf1 "        %s%d(%s" (list op w (car v)))
            (setq v (cdr v))
            (prog (i)
               (setq i 2)
         lab   (cond ((minusp (difference w i)) (return nil)))
               (progn (c!:printf1 ",%s" (list (car v))) (setq v (cdr v)))
               (setq i (plus2 i 1))
               (go lab))
            (c!:printf1 ");\n" (list)))
         (go !G68))))


(de c!:optimise_flowgraph (startpoint all_blocks env argch args)
   (prog (w n locs stacks error_labels fn_used nil_used nilbase_used)
      (prog (b)
         (setq b all_blocks)
   lab   (cond ((null b) (return nil)))
         ((lambda (b) (c!:insert_tailcall b)) (car b))
         (setq b (cdr b))
         (go lab))
      (setq startpoint (c!:branch_chain startpoint nil))
      (remflag all_blocks 'c!:visited)
      (c!:live_variable_analysis all_blocks)
      (c!:build_clash_matrix all_blocks)
      (cond ((and error_labels env) (setq reloadenv t)))
      (prog (u)
         (setq u env)
   lab   (cond ((null u) (return nil)))
         ((lambda (u)
             (prog (v)
                (setq v env)
          lab   (cond ((null v) (return nil)))
                ((lambda (v) (c!:clash (cdr u) (cdr v))) (car v))
                (setq v (cdr v))
                (go lab)))
            (car u))
         (setq u (cdr u))
         (go lab))
      (setq locs (c!:allocate_registers registers))
      (setq stacks (c!:allocate_registers stacklocs))
      (flag stacks 'c!:live_across_call)
      (c!:remove_nops all_blocks)
      (setq startpoint (c!:branch_chain startpoint nil))
      (remflag all_blocks 'c!:visited)
      (setq startpoint (c!:branch_chain startpoint t))
      (remflag all_blocks 'c!:visited)
      (cond (does_call (setq nil_used t)))
      (cond
         (nil_used (c!:printf1 "    Lisp_Object nil = C_nil;\n" (list)))
         (nilbase_used (c!:printf1 "    nil_as_base\n" (list))))
      (cond
         (locs
            (progn
               (c!:printf1 "    Lisp_Object %s" (list (car locs)))
               (prog (v)
                  (setq v (cdr locs))
            lab   (cond ((null v) (return nil)))
                  ((lambda (v) (c!:printf1 ", %s" (list v))) (car v))
                  (setq v (cdr v))
                  (go lab))
               (c!:printf1 ";\n" (list)))) )
      (cond (fn_used (c!:printf1 "    Lisp_Object fn;\n" (list))))
      (cond
         ((or (equal (car argch) 0) (geq (car argch) 3))
            (c!:printf1
               "    argcheck(nargs, %s, \q%s\q);\n"
               (list (car argch) (cdr argch)))) )
      (cond
         (does_call
            (progn
               (c!:printf1 "    if (stack >= stacklimit)\n" (list))
               (c!:printf1 "    {\n" (list))
               (c!:pushpop 'push args)
               (c!:printf1
                  "        env = reclaim(env, \qstack\q, GC_STACK, 0);\n"
                  (list))
               (c!:pushpop 'pop (reverse args))
               (c!:printf1 "        nil = C_nil;\n" (list))
               (c!:printf1
                  "        if (exception_pending()) return nil;\n"
                  (list))
               (c!:printf1 "    }\n" (list)))) )
      (cond
         (reloadenv (c!:printf1 "    push(env);\n" (list)))
         (t (c!:printf1 "    CSL_IGNORE(env);\n" (list))))
      (setq n 0)
      (cond
         (stacks
            (progn
               (c!:printf1
                  "/* space for vars preserved across procedure calls */\n"
                  (list))
               (prog (v)
                  (setq v stacks)
            lab   (cond ((null v) (return nil)))
                  ((lambda (v)
                      (progn (put v 'c!:location n) (setq n (plus n 1))))
                     (car v))
                  (setq v (cdr v))
                  (go lab))
               (setq w n)
               (prog nil
            !G69  (cond ((not (geq w 5)) (return nil)))
                  (progn
                     (c!:printf1
                        "    push5(nil, nil, nil, nil, nil);\n"
                        (list))
                     (setq w (difference w 5)))
                  (go !G69))
               (cond
                  ((neq w 0)
                     (progn
                        (cond
                           ((equal w 1)
                              (c!:printf1 "    push(nil);\n" (list)))
                           (t (progn
                                 (c!:printf1 "    push%s(nil" (list w))
                                 (prog (i)
                                    (setq i 2)
                              lab   (cond
                                       ((minusp (difference w i))
                                          (return nil)))
                                    (c!:printf1 ", nil" (list))
                                    (setq i (plus2 i 1))
                                    (go lab))
                                 (c!:printf1 ");\n" (list)))) ))) ))) )
      (cond (reloadenv (progn (setq reloadenv n) (setq n (plus n 1)))) )
      (cond
         (env
            (c!:printf1
               "/* copy arguments values to proper place */\n"
               (list))))
      (prog (v)
         (setq v env)
   lab   (cond ((null v) (return nil)))
         ((lambda (v)
             (cond
                ((flagp (cdr v) 'c!:live_across_call)
                   (c!:printf1
                      "    stack[%s] = %s;\n"
                      (list
                         (minus (get (get (cdr v) 'c!:chosen) 'c!:location))
                         (cdr v))))
                (t (c!:printf1
                      "    %s = %s;\n"
                      (list (get (cdr v) 'c!:chosen) (cdr v)))) ))
            (car v))
         (setq v (cdr v))
         (go lab))
      (c!:printf1 "/* end of prologue */\n" (list))
      (c!:display_flowgraph startpoint n t)
      (cond
         (error_labels
            (progn
               (c!:printf1 "/* error exit handlers */\n" (list))
               (prog (x)
                  (setq x error_labels)
            lab   (cond ((null x) (return nil)))
                  ((lambda (x)
                      (progn
                         (c!:printf1 "%s:\n" (list (cdr x)))
                         (c!:print_error_return
                            (caar x)
                            (cadar x)
                            (caddar x))))
                     (car x))
                  (setq x (cdr x))
                  (go lab)))) )
      (remflag all_blocks 'c!:visited)))


(de c!:print_error_return (why env depth)
   (prog nil
      (cond
         ((and reloadenv env)
            (c!:printf1 "    env = stack[%s];\n" (list (minus reloadenv)))) )
      (cond
         ((null why)
            (progn
               (prog (v)
                  (setq v env)
            lab   (cond ((null v) (return nil)))
                  ((lambda (v)
                      (c!:printf1
                         "    qvalue(elt(env, %s)) = %v; /* %a */\n"
                         (list
                            (c!:find_literal (car v))
                            (get (cdr v) 'c!:chosen)
                            (car v))))
                     (car v))
                  (setq v (cdr v))
                  (go lab))
               (cond
                  ((neq depth 0) (c!:printf1 "    popv(%s);\n" (list depth))))
               (c!:printf1 "    return nil;\n" (list))))
         ((flagp (cadr why) 'c!:live_across_call)
            (progn
               (c!:printf1
                  "    {   Lisp_Object res = %v;\n"
                  (list (cadr why)))
               (prog (v)
                  (setq v env)
            lab   (cond ((null v) (return nil)))
                  ((lambda (v)
                      (c!:printf1
                         "        qvalue(elt(env, %s)) = %v;\n"
                         (list
                            (c!:find_literal (car v))
                            (get (cdr v) 'c!:chosen))))
                     (car v))
                  (setq v (cdr v))
                  (go lab))
               (cond
                  ((neq depth 0)
                     (c!:printf1 "        popv(%s);\n" (list depth))))
               (c!:printf1
                  "        return error(1, %s, res); }\n"
                  (list
                     (cond
                        ((eqcar why 'car) "err_bad_car")
                        ((eqcar why 'cdr) "err_bad_cdr")
                        (t (error 0 (list why "unknown_error")))) ))) )
         (t (progn
               (prog (v)
                  (setq v env)
            lab   (cond ((null v) (return nil)))
                  ((lambda (v)
                      (c!:printf1
                         "    qvalue(elt(env, %s)) = %v;\n"
                         (list
                            (c!:find_literal (car v))
                            (get (cdr v) 'c!:chosen))))
                     (car v))
                  (setq v (cdr v))
                  (go lab))
               (cond
                  ((neq depth 0) (c!:printf1 "    popv(%s);\n" (list depth))))
               (c!:printf1
                  "    return error(1, %s, %v);\n"
                  (list
                     (cond
                        ((eqcar why 'car) "err_bad_car")
                        ((eqcar why 'cdr) "err_bad_cdr")
                        (t (error 0 (list why "unknown_error"))))
                     (cadr why)))) ))) )


(de c!:cand (u env)
   (prog (w r)
      (setq w (reverse (cdr u)))
      (cond ((null w) (return (c!:cval nil env))))
      (setq r (list (list 't (car w))))
      (setq w (cdr w))
      (prog (z)
         (setq z w)
   lab   (cond ((null z) (return nil)))
         ((lambda (z) (setq r (cons (list (list 'null z) nil) r))) (car z))
         (setq z (cdr z))
         (go lab))
      (setq r (cons 'cond r))
      (return (c!:cval r env))))


(put 'and 'c!:code (function c!:cand))


(de c!:ccatch (u env) (error 0 "catch"))


(put 'catch 'c!:code (function c!:ccatch))


(de c!:ccompile_let (u env) (error 0 "compiler-let"))


(put 'compiler!-let 'c!:code (function c!:ccompiler_let))


(de c!:ccond (u env)
   (prog (v conc)
      (setq v (c!:newreg))
      (setq conc (c!:my_gensym))
      (prog (c)
         (setq c (cdr u))
   lab   (cond ((null c) (return nil)))
         ((lambda (c)
             (prog (l1 l2)
                (setq l1 (c!:my_gensym))
                (setq l2 (c!:my_gensym))
                (cond
                   ((atom (cdr c))
                      (progn
                         (c!:outop 'movr v nil (c!:cval (car c) env))
                         (c!:endblock (list 'ifnull v) (list l2 conc))))
                   (t (progn
                         (c!:cjumpif (car c) env l1 l2)
                         (c!:startblock l1)
                         (c!:outop
                            'movr
                            v
                            nil
                            (c!:cval (cons 'progn (cdr c)) env))
                         (c!:endblock 'goto (list conc)))) )
                (c!:startblock l2)))
            (car c))
         (setq c (cdr c))
         (go lab))
      (c!:outop 'movk1 v nil nil)
      (c!:endblock 'goto (list conc))
      (c!:startblock conc)
      (return v)))


(put 'cond 'c!:code (function c!:ccond))


(de c!:cdeclare (u env) (error 0 "declare"))


(put 'declare 'c!:code (function c!:cdeclare))


(de c!:cde (u env) (error 0 "de"))


(put 'de 'c!:code (function c!:cde))


(de c!:cdefun (u env) (error 0 "defun"))


(put '!~defun 'c!:code (function c!:cdefun))


(de c!:ceval_when (u env) (error 0 "eval-when"))


(put 'eval!-when 'c!:code (function c!:ceval_when))


(de c!:cflet (u env) (error 0 "flet"))


(put 'flet 'c!:code (function c!:cflet))


(de c!:cfunction (u env)
   (prog (v)
      (setq u (cadr u))
      (cond
         ((not (atom u))
            (progn
               (cond
                  ((not (eqcar u 'lambda))
                     (error 0 (list "lambda expression needed" u))))
               (setq v (dated!-name 'lambda))
               (setq pending_functions
                  (cons (cons 'de (cons v (cdr u))) pending_functions))
               (setq u v))))
      (setq v (c!:newreg))
      (c!:outop 'movk v u (c!:find_literal u))
      (return v)))


(put 'function 'c!:code (function c!:cfunction))


(de c!:cgo (u env)
   (prog (w w1)
      (setq w1 proglabs)
      (prog nil
   !G70  (cond ((not (and (null w) w1)) (return nil)))
         (progn (setq w (assoc!*!* (cadr u) (car w1))) (setq w1 (cdr w1)))
         (go !G70))
      (cond ((null w) (error 0 (list u "label not set"))))
      (c!:endblock 'goto (list (cadr w)))
      (return nil)))


(put 'go 'c!:code (function c!:cgo))


(de c!:cif (u env)
   (prog (v conc l1 l2)
      (setq v (c!:newreg))
      (setq conc (c!:my_gensym))
      (setq l1 (c!:my_gensym))
      (setq l2 (c!:my_gensym))
      (c!:cjumpif (cadr u) env l1 l2)
      (c!:startblock l1)
      (c!:outop 'movr v nil (c!:cval (car (setq u (cddr u))) env))
      (c!:endblock 'goto (list conc))
      (c!:startblock l2)
      (c!:outop 'movr v nil (c!:cval (cadr u) env))
      (c!:endblock 'goto (list conc))
      (c!:startblock conc)
      (return v)))


(put 'if 'c!:code (function c!:cif))


(de c!:clabels (u env) (error 0 "labels"))


(put 'labels 'c!:code (function c!:clabels))


(de c!:expand!-let (vl b)
   (cond
      ((null vl) (cons 'progn b))
      ((null (cdr vl)) (c!:expand!-let!* vl b))
      (t (prog (vars vals)
            (prog (v)
               (setq v vl)
         lab   (cond ((null v) (return nil)))
               ((lambda (v)
                   (cond
                      ((atom v)
                         (progn
                            (setq vars (cons v vars))
                            (setq vals (cons nil vals))))
                      ((atom (cdr v))
                         (progn
                            (setq vars (cons (car v) vars))
                            (setq vals (cons nil vals))))
                      (t (progn
                            (setq vars (cons (car v) vars))
                            (setq vals (cons (cadr v) vals)))) ))
                  (car v))
               (setq v (cdr v))
               (go lab))
            (return (cons (cons 'lambda (cons vars b)) vals)))) ))


(de c!:clet (x env) (c!:cval (c!:expand!-let (cadr x) (cddr x)) env))


(put '!~let 'c!:code (function c!:clet))


(de c!:expand!-let!* (vl b)
   (cond
      ((null vl) (cons 'progn b))
      (t (prog (var val)
            (setq var (car vl))
            (cond
               ((not (atom var))
                  (progn
                     (setq val (cdr var))
                     (setq var (car var))
                     (cond ((not (atom val)) (setq val (car val)))) )))
            (setq b (list (list 'return (c!:expand!-let!* (cdr vl) b))))
            (cond (val (setq b (cons (list 'setq var val) b))))
            (return (cons 'prog (cons (list var) b)))) )))


(de c!:clet!* (x env) (c!:cval (c!:expand!-let!* (cadr x) (cddr x)) env))


(put 'let!* 'c!:code (function c!:clet!*))


(de c!:clist (u env)
   (cond
      ((null (cdr u)) (c!:cval nil env))
      ((null (cddr u)) (c!:cval (cons 'ncons (cdr u)) env))
      ((eqcar (cadr u) 'cons)
         (c!:cval
            (list
               'acons
               (cadr (cadr u))
               (caddr (cadr u))
               (cons 'list (cddr u)))
            env))
      ((null (cdddr u)) (c!:cval (cons 'list2 (cdr u)) env))
      (t (c!:cval
            (list 'list2!* (cadr u) (caddr u) (cons 'list (cdddr u)))
            env))))


(put 'list 'c!:code (function c!:clist))


(de c!:clist!* (u env)
   (prog (v)
      (setq u (reverse (cdr u)))
      (setq v (car u))
      (prog (a)
         (setq a (cdr u))
   lab   (cond ((null a) (return nil)))
         ((lambda (a) (setq v (list 'cons a v))) (car a))
         (setq a (cdr a))
         (go lab))
      (return (c!:cval v env))))


(put 'list!* 'c!:code (function c!:clist!*))


(de c!:ccons (u env)
   (prog (a1 a2)
      (setq a1 (s!:improve (cadr u)))
      (setq a2 (s!:improve (caddr u)))
      (cond
         ((or (equal a2 nil) (equal a2 ''nil) (equal a2 '(list)))
            (return (c!:cval (list 'ncons a1) env))))
      (cond
         ((eqcar a1 'cons)
            (return (c!:cval (list 'acons (cadr a1) (caddr a1) a2) env))))
      (cond
         ((eqcar a2 'cons)
            (return (c!:cval (list 'list2!* a1 (cadr a2) (caddr a2)) env))))
      (cond
         ((eqcar a2 'list)
            (return
               (c!:cval
                  (list
                     'cons
                     a1
                     (list 'cons (cadr a2) (cons 'list (cddr a2))))
                  env))))
      (return (c!:ccall (car u) (cdr u) env))))


(put 'cons 'c!:code (function c!:ccons))


(de c!:cget (u env)
   (prog (a1 a2 w r r1)
      (setq a1 (s!:improve (cadr u)))
      (setq a2 (s!:improve (caddr u)))
      (cond
         ((and
             (eqcar a2 'quote)
             (idp (setq w (cadr a2)))
             (setq w (symbol!-make!-fastget w nil)))
            (progn
               (setq r (c!:newreg))
               (c!:outop 'fastget r (c!:cval a1 env) (cons w (cadr a2)))
               (return r)))
         (t (return (c!:ccall (car u) (cdr u) env)))) ))


(put 'get 'c!:code (function c!:cget))


(de c!:cflag (u env)
   (prog (a1 a2 w r r1)
      (setq a1 (s!:improve (cadr u)))
      (setq a2 (s!:improve (caddr u)))
      (cond
         ((and
             (eqcar a2 'quote)
             (idp (setq w (cadr a2)))
             (setq w (symbol!-make!-fastget w nil)))
            (progn
               (setq r (c!:newreg))
               (c!:outop 'fastflag r (c!:cval a1 env) (cons w (cadr a2)))
               (return r)))
         (t (return (c!:ccall (car u) (cdr u) env)))) ))


(put 'flagp 'c!:code (function c!:cflag))


(de c!:cgetv (u env)
   (cond
      ((not !*fastvector) (c!:ccall (car u) (cdr u) env))
      (t (c!:cval (cons 'qgetv (cdr u)) env))))


(put 'getv 'c!:code (function c!:cgetv))


(de c!:cputv (u env)
   (cond
      ((not !*fastvector) (c!:ccall (car u) (cdr u) env))
      (t (c!:cval (cons 'qputv (cdr u)) env))))


(put 'putv 'c!:code (function c!:cputv))


(de c!:cqputv (x env)
   (prog (rr)
      (setq rr (c!:pareval (cdr x) env))
      (c!:outop 'qputv (caddr rr) (car rr) (cadr rr))
      (return (caddr rr))))


(put 'qputv 'c!:code (function c!:cqputv))


(de c!:cmacrolet (u env) (error 0 "macrolet"))


(put 'macrolet 'c!:code (function c!:cmacrolet))


(de c!:cmultiple_value_call (u env) (error 0 "multiple_value_call"))


(put 'multiple!-value!-call 'c!:code (function c!:cmultiple_value_call))


(de c!:cmultiple_value_prog1 (u env) (error 0 "multiple_value_prog1"))


(put 'multiple!-value!-prog1 'c!:code (function c!:cmultiple_value_prog1))


(de c!:cor (u env)
   (prog (next done v r)
      (setq v (c!:newreg))
      (setq done (c!:my_gensym))
      (setq u (cdr u))
      (prog nil
   !G71  (cond ((not (cdr u)) (return nil)))
         (progn
            (setq next (c!:my_gensym))
            (c!:outop 'movr v nil (c!:cval (car u) env))
            (setq u (cdr u))
            (c!:endblock (list 'ifnull v) (list next done))
            (c!:startblock next))
         (go !G71))
      (c!:outop 'movr v nil (c!:cval (car u) env))
      (c!:endblock 'goto (list done))
      (c!:startblock done)
      (return v)))


(put 'or 'c!:code (function c!:cor))


(de c!:cprog (u env)
   (prog (w w1 bvl local_proglabs progret progexit fluids env1)
      (setq env1 (car env))
      (setq bvl (cadr u))
      (prog (v)
         (setq v bvl)
   lab   (cond ((null v) (return nil)))
         ((lambda (v)
             (cond
                ((globalp v) (error 0 (list v "attempt to bind a global")))
                ((fluidp v)
                   (progn
                      (setq fluids (cons (cons v (c!:newreg)) fluids))
                      (flag (list (cdar fluids)) 'c!:live_across_call)
                      (setq env1
                         (cons (cons 'c!:dummy!:name (cdar fluids)) env1))
                      (c!:outop 'ldrglob (cdar fluids) v (c!:find_literal v))
                      (c!:outop 'nilglob nil v (c!:find_literal v))))
                (t (progn
                      (setq env1 (cons (cons v (c!:newreg)) env1))
                      (c!:outop 'movk1 (cdar env1) nil nil)))) )
            (car v))
         (setq v (cdr v))
         (go lab))
      (cond (fluids (c!:outop 'fluidbind nil nil fluids)))
      (setq env (cons env1 (append fluids (cdr env))))
      (setq u (cddr u))
      (setq progret (c!:newreg))
      (setq progexit (c!:my_gensym))
      (setq blockstack (cons (cons nil (cons progret progexit)) blockstack))
      (prog (a)
         (setq a u)
   lab   (cond ((null a) (return nil)))
         ((lambda (a)
             (cond
                ((atom a)
                   (cond
                      ((atsoc a local_proglabs)
                         (progn
                            (cond
                               ((not (null a))
                                  (progn
                                     (setq w (wrs nil))
                                     (princ "+++++ multiply defined label: ")
                                     (prin a)
                                     (terpri)
                                     (wrs w)))) ))
                      (t (setq local_proglabs
                            (cons
                               (list a (c!:my_gensym))
                               local_proglabs)))) )))
            (car a))
         (setq a (cdr a))
         (go lab))
      (setq proglabs (cons local_proglabs proglabs))
      (prog (a)
         (setq a u)
   lab   (cond ((null a) (return nil)))
         ((lambda (a)
             (cond
                ((atom a)
                   (progn
                      (setq w (cdr (assoc!*!* a local_proglabs)))
                      (cond
                         ((null (cdr w))
                            (progn
                               (rplacd w t)
                               (c!:endblock 'goto (list (car w)))
                               (c!:startblock (car w)))) )))
                (t (c!:cval a env))))
            (car a))
         (setq a (cdr a))
         (go lab))
      (c!:outop 'movk1 progret nil nil)
      (c!:endblock 'goto (list progexit))
      (c!:startblock progexit)
      (prog (v)
         (setq v fluids)
   lab   (cond ((null v) (return nil)))
         ((lambda (v)
             (c!:outop 'strglob (cdr v) (car v) (c!:find_literal (car v))))
            (car v))
         (setq v (cdr v))
         (go lab))
      (setq blockstack (cdr blockstack))
      (setq proglabs (cdr proglabs))
      (return progret)))


(put 'prog 'c!:code (function c!:cprog))


(de c!:cprog!* (u env) (error 0 "prog*"))


(put 'prog!* 'c!:code (function c!:cprog!*))


(de c!:cprog1 (u env)
   (prog (g)
      (setq g (c!:my_gensym))
      (setq g
         (list 'prog (list g) (list 'setq g (cadr u)) (cons 'progn (cddr u))
            (list 'return g)))
      (return (c!:cval g env))))


(put 'prog1 'c!:code (function c!:cprog1))


(de c!:cprog2 (u env)
   (prog (g)
      (setq u (cdr u))
      (setq g (c!:my_gensym))
      (setq g
         (list 'prog (list g) (list 'setq g (cadr u)) (cons 'progn (cddr u))
            (list 'return g)))
      (setq g (list 'progn (car u) g))
      (return (c!:cval g env))))


(put 'prog2 'c!:code (function c!:cprog2))


(de c!:cprogn (u env)
   (prog (r)
      (setq u (cdr u))
      (cond ((equal u nil) (setq u '(nil))))
      (prog (s)
         (setq s u)
   lab   (cond ((null s) (return nil)))
         ((lambda (s) (setq r (c!:cval s env))) (car s))
         (setq s (cdr s))
         (go lab))
      (return r)))


(put 'progn 'c!:code (function c!:cprogn))


(de c!:cprogv (u env) (error 0 "progv"))


(put 'progv 'c!:code (function c!:cprogv))


(de c!:cquote (u env)
   (prog (v)
      (setq u (cadr u))
      (setq v (c!:newreg))
      (cond
         ((or (null u) (equal u 't) (c!:small_number u))
            (c!:outop 'movk1 v nil u))
         (t (c!:outop 'movk v u (c!:find_literal u))))
      (return v)))


(put 'quote 'c!:code (function c!:cquote))


(de c!:creturn (u env)
   (prog (w)
      (setq w (assoc!*!* nil blockstack))
      (cond ((null w) (error "RETURN out of context")))
      (c!:outop 'movr (cadr w) nil (c!:cval (cadr u) env))
      (c!:endblock 'goto (list (cddr w)))
      (return nil)))


(put 'return 'c!:code (function c!:creturn))


(put 'return!-from 'c!:code (function c!:creturn_from))


(de c!:csetq (u env)
   (prog (v w)
      (setq v (c!:cval (caddr u) env))
      (setq u (cadr u))
      (cond
         ((not (idp u)) (error 0 (list u "bad variable in setq")))
         ((setq w (c!:locally_bound u env)) (c!:outop 'movr (cdr w) nil v))
         ((flagp u 'c!:constant)
            (error 0 (list u "attempt to use setq on a constant")))
         (t (c!:outop 'strglob v u (c!:find_literal u))))
      (return v)))


(put 'setq 'c!:code (function c!:csetq))


(put 'noisy!-setq 'c!:code (function c!:csetq))


(de c!:cprivate_tagbody (u env)
   (prog nil
      (setq u (cdr u))
      (c!:endblock 'goto (list (car u)))
      (c!:startblock (car u))
      (setq current_args
         (prog (v !G72 endptr)
            (setq v current_args)
            (cond ((null v) (return nil)))
            (setq !G72
               (setq endptr
                  (cons
                     ((lambda (v)
                         (prog (z)
                            (setq z (assoc!*!* v (car env)))
                            (return (cond (z (cdr z)) (t v)))) )
                        (car v))
                     nil)))
      looplabel
            (setq v (cdr v))
            (cond ((null v) (return !G72)))
            (rplacd
               endptr
               (cons
                  ((lambda (v)
                      (prog (z)
                         (setq z (assoc!*!* v (car env)))
                         (return (cond (z (cdr z)) (t v)))) )
                     (car v))
                  nil))
            (setq endptr (cdr endptr))
            (go looplabel)))
      (return (c!:cval (cadr u) env))))


(put 'c!:private_tagbody 'c!:code (function c!:cprivate_tagbody))


(de c!:cthe (u env) (c!:cval (caddr u) env))


(put 'the 'c!:code (function c!:cthe))


(de c!:cthrow (u env) (error 0 "throw"))


(put 'throw 'c!:code (function c!:cthrow))


(de c!:cunless (u env)
   (prog (v conc l1 l2)
      (setq v (c!:newreg))
      (setq conc (c!:my_gensym))
      (setq l1 (c!:my_gensym))
      (setq l2 (c!:my_gensym))
      (c!:cjumpif (cadr u) env l2 l1)
      (c!:startblock l1)
      (c!:outop 'movr v nil (c!:cval (cons 'progn (cddr u)) env))
      (c!:endblock 'goto (list conc))
      (c!:startblock l2)
      (c!:outop 'movk1 v nil nil)
      (c!:endblock 'goto (list conc))
      (c!:startblock conc)
      (return v)))


(put 'unless 'c!:code (function c!:cunless))


(de c!:cunwind_protect (u env) (error 0 "unwind_protect"))


(put 'unwind!-protect 'c!:code (function c!:cunwind_protect))


(de c!:cwhen (u env)
   (prog (v conc l1 l2)
      (setq v (c!:newreg))
      (setq conc (c!:my_gensym))
      (setq l1 (c!:my_gensym))
      (setq l2 (c!:my_gensym))
      (c!:cjumpif (cadr u) env l1 l2)
      (c!:startblock l1)
      (c!:outop 'movr v nil (c!:cval (cons 'progn (cddr u)) env))
      (c!:endblock 'goto (list conc))
      (c!:startblock l2)
      (c!:outop 'movk1 v nil nil)
      (c!:endblock 'goto (list conc))
      (c!:startblock conc)
      (return v)))


(put 'when 'c!:code (function c!:cwhen))


(de c!:expand_map (fnargs)
   (prog (carp fn fn1 args var avar moveon l1 r s closed)
      (setq fn (car fnargs))
      (cond
         ((or (equal fn 'mapc) (equal fn 'mapcar) (equal fn 'mapcan))
            (setq carp t)))
      (setq fnargs (cdr fnargs))
      (cond ((atom fnargs) (error 0 "bad arguments to map function")))
      (setq fn1 (cadr fnargs))
      (prog nil
   !G73  (cond
            ((not
                (or
                   (eqcar fn1 'function)
                   (and (eqcar fn1 'quote) (eqcar (cadr fn1) 'lambda))))
               (return nil)))
         (progn (setq fn1 (cadr fn1)) (setq closed t))
         (go !G73))
      (setq args (car fnargs))
      (setq l1 (c!:my_gensym))
      (setq r (c!:my_gensym))
      (setq s (c!:my_gensym))
      (setq var (c!:my_gensym))
      (setq avar var)
      (cond (carp (setq avar (list 'car avar))))
      (cond
         (closed (setq fn1 (list fn1 avar)))
         (t (setq fn1 (list 'apply1 fn1 avar))))
      (setq moveon (list 'setq var (list 'cdr var)))
      (cond
         ((or (equal fn 'map) (equal fn 'mapc))
            (setq fn
               (sublis
                  (list
                     (cons 'l1 l1)
                     (cons 'var var)
                     (cons 'fn fn1)
                     (cons 'args args)
                     (cons 'moveon moveon))
                  '(prog (var)
                      (setq var args)
                l1    (cond ((not var) (return nil)))
                fn
                moveon(go l1)))) )
         ((or (equal fn 'maplist) (equal fn 'mapcar))
            (setq fn
               (sublis
                  (list
                     (cons 'l1 l1)
                     (cons 'var var)
                     (cons 'fn fn1)
                     (cons 'args args)
                     (cons 'moveon moveon)
                     (cons 'r r))
                  '(prog (var r)
                      (setq var args)
                l1    (cond ((not var) (return (reversip r))))
                      (setq r (cons fn r))
                moveon(go l1)))) )
         (t (setq fn
               (sublis
                  (list
                     (cons 'l1 l1)
                     (cons 'l2 (c!:my_gensym))
                     (cons 'var var)
                     (cons 'fn fn1)
                     (cons 'args args)
                     (cons 'moveon moveon)
                     (cons 'r (c!:my_gensym))
                     (cons 's (c!:my_gensym)))
                  '(prog (var r s)
                      (setq var args)
                      (setq r (setq s (list nil)))
                l1    (cond ((not var) (return (cdr r))))
                      (rplacd s fn)
                l2    (cond ((not (atom (cdr s))) (setq s (cdr s)) (go l2)))
                moveon(go l1)))) ))
      (return fn)))


(put 'map 'c!:compile_macro (function c!:expand_map))


(put 'maplist 'c!:compile_macro (function c!:expand_map))


(put 'mapc 'c!:compile_macro (function c!:expand_map))


(put 'mapcar 'c!:compile_macro (function c!:expand_map))


(put 'mapcon 'c!:compile_macro (function c!:expand_map))


(put 'mapcan 'c!:compile_macro (function c!:expand_map))


(de c!:expand_carcdr (x)
   (prog (name)
      (setq name (cdr (reverse (cdr (explode2 (car x)))) ))
      (setq x (cadr x))
      (prog (v)
         (setq v name)
   lab   (cond ((null v) (return nil)))
         ((lambda (v) (setq x (list (cond ((equal v 'a) 'car) (t 'cdr)) x)))
            (car v))
         (setq v (cdr v))
         (go lab))
      (return x)))


(progn
   (put 'caar 'c!:compile_macro (function c!:expand_carcdr))
   (put 'cadr 'c!:compile_macro (function c!:expand_carcdr))
   (put 'cdar 'c!:compile_macro (function c!:expand_carcdr))
   (put 'cddr 'c!:compile_macro (function c!:expand_carcdr))
   (put 'caaar 'c!:compile_macro (function c!:expand_carcdr))
   (put 'caadr 'c!:compile_macro (function c!:expand_carcdr))
   (put 'cadar 'c!:compile_macro (function c!:expand_carcdr))
   (put 'caddr 'c!:compile_macro (function c!:expand_carcdr))
   (put 'cdaar 'c!:compile_macro (function c!:expand_carcdr))
   (put 'cdadr 'c!:compile_macro (function c!:expand_carcdr))
   (put 'cddar 'c!:compile_macro (function c!:expand_carcdr))
   (put 'cdddr 'c!:compile_macro (function c!:expand_carcdr))
   (put 'caaaar 'c!:compile_macro (function c!:expand_carcdr))
   (put 'caaadr 'c!:compile_macro (function c!:expand_carcdr))
   (put 'caadar 'c!:compile_macro (function c!:expand_carcdr))
   (put 'caaddr 'c!:compile_macro (function c!:expand_carcdr))
   (put 'cadaar 'c!:compile_macro (function c!:expand_carcdr))
   (put 'cadadr 'c!:compile_macro (function c!:expand_carcdr))
   (put 'caddar 'c!:compile_macro (function c!:expand_carcdr))
   (put 'cadddr 'c!:compile_macro (function c!:expand_carcdr))
   (put 'cdaaar 'c!:compile_macro (function c!:expand_carcdr))
   (put 'cdaadr 'c!:compile_macro (function c!:expand_carcdr))
   (put 'cdadar 'c!:compile_macro (function c!:expand_carcdr))
   (put 'cdaddr 'c!:compile_macro (function c!:expand_carcdr))
   (put 'cddaar 'c!:compile_macro (function c!:expand_carcdr))
   (put 'cddadr 'c!:compile_macro (function c!:expand_carcdr))
   (put 'cdddar 'c!:compile_macro (function c!:expand_carcdr))
   (put 'cddddr 'c!:compile_macro (function c!:expand_carcdr)))


(de c!:builtin_one (x env)
   (prog (r1 r2)
      (setq r1 (c!:cval (cadr x) env))
      (c!:outop (car x) (setq r2 (c!:newreg)) (cdr env) r1)
      (return r2)))


(de c!:builtin_two (x env)
   (prog (a1 a2 r rr)
      (setq a1 (cadr x))
      (setq a2 (caddr x))
      (setq rr (c!:pareval (list a1 a2) env))
      (c!:outop (car x) (setq r (c!:newreg)) (car rr) (cadr rr))
      (return r)))


(de c!:narg (x env)
   (c!:cval (expand (cdr x) (get (car x) 'c!:binary_version)) env))


(prog (n)
   (setq n '((plus plus2) (times times2) (iplus iplus2) (itimes itimes2)))
lab(cond ((null n) (return nil)))
   ((lambda (n)
       (progn
          (put (car n) 'c!:binary_version (cadr n))
          (put (car n) 'c!:code (function c!:narg))))
      (car n))
   (setq n (cdr n))
   (go lab))


(de c!:cplus2 (u env)
   (prog (a b)
      (setq a (s!:improve (cadr u)))
      (setq b (s!:improve (caddr u)))
      (return
         (cond
            ((and (numberp a) (numberp b)) (c!:cval (plus a b) env))
            ((equal a 0) (c!:cval b env))
            ((equal a 1) (c!:cval (list 'add1 b) env))
            ((equal b 0) (c!:cval a env))
            ((equal b 1) (c!:cval (list 'add1 a) env))
            ((equal b (minus 1)) (c!:cval (list 'sub1 a) env))
            (t (c!:ccall (car u) (cdr u) env)))) ))


(put 'plus2 'c!:code (function c!:cplus2))


(de c!:ciplus2 (u env)
   (prog (a b)
      (setq a (s!:improve (cadr u)))
      (setq b (s!:improve (caddr u)))
      (return
         (cond
            ((and (numberp a) (numberp b)) (c!:cval (plus a b) env))
            ((equal a 0) (c!:cval b env))
            ((equal a 1) (c!:cval (list 'iadd1 b) env))
            ((equal b 0) (c!:cval a env))
            ((equal b 1) (c!:cval (list 'iadd1 a) env))
            ((equal b (minus 1)) (c!:cval (list 'isub1 a) env))
            (t (c!:builtin_two u env)))) ))


(put 'iplus2 'c!:code (function c!:ciplus2))


(de c!:cdifference (u env)
   (prog (a b)
      (setq a (s!:improve (cadr u)))
      (setq b (s!:improve (caddr u)))
      (return
         (cond
            ((and (numberp a) (numberp b)) (c!:cval (difference a b) env))
            ((equal a 0) (c!:cval (list 'minus b) env))
            ((equal b 0) (c!:cval a env))
            ((equal b 1) (c!:cval (list 'sub1 a) env))
            ((equal b (minus 1)) (c!:cval (list 'add1 a) env))
            (t (c!:ccall (car u) (cdr u) env)))) ))


(put 'difference 'c!:code (function c!:cdifference))


(de c!:cidifference (u env)
   (prog (a b)
      (setq a (s!:improve (cadr u)))
      (setq b (s!:improve (caddr u)))
      (return
         (cond
            ((and (numberp a) (numberp b)) (c!:cval (difference a b) env))
            ((equal a 0) (c!:cval (list 'iminus b) env))
            ((equal b 0) (c!:cval a env))
            ((equal b 1) (c!:cval (list 'isub1 a) env))
            ((equal b (minus 1)) (c!:cval (list 'iadd1 a) env))
            (t (c!:builtin_two u env)))) ))


(put 'idifference 'c!:code (function c!:cidifference))


(de c!:ctimes2 (u env)
   (prog (a b)
      (setq a (s!:improve (cadr u)))
      (setq b (s!:improve (caddr u)))
      (return
         (cond
            ((and (numberp a) (numberp b)) (c!:cval (times a b) env))
            ((or (equal a 0) (equal b 0)) (c!:cval 0 env))
            ((equal a 1) (c!:cval b env))
            ((equal b 1) (c!:cval a env))
            ((equal a (minus 1)) (c!:cval (list 'minus b) env))
            ((equal b (minus 1)) (c!:cval (list 'minus a) env))
            (t (c!:ccall (car u) (cdr u) env)))) ))


(put 'times2 'c!:code (function c!:ctimes2))


(de c!:citimes2 (u env)
   (prog (a b)
      (setq a (s!:improve (cadr u)))
      (setq b (s!:improve (caddr u)))
      (return
         (cond
            ((and (numberp a) (numberp b)) (c!:cval (times a b) env))
            ((or (equal a 0) (equal b 0)) (c!:cval 0 env))
            ((equal a 1) (c!:cval b env))
            ((equal b 1) (c!:cval a env))
            ((equal a (minus 1)) (c!:cval (list 'iminus b) env))
            ((equal b (minus 1)) (c!:cval (list 'iminus a) env))
            (t (c!:builtin_two u env)))) ))


(put 'itimes2 'c!:code (function c!:citimes2))


(de c!:cminus (u env)
   (prog (a b)
      (setq a (s!:improve (cadr u)))
      (return
         (cond
            ((numberp a) (c!:cval (minus a) env))
            ((eqcar a 'minus) (c!:cval (cadr a) env))
            (t (c!:ccall (car u) (cdr u) env)))) ))


(put 'minus 'c!:code (function c!:cminus))


(de c!:ceq (x env)
   (prog (a1 a2 r rr)
      (setq a1 (s!:improve (cadr x)))
      (setq a2 (s!:improve (caddr x)))
      (cond
         ((equal a1 nil) (return (c!:cval (list 'null a2) env)))
         ((equal a2 nil) (return (c!:cval (list 'null a1) env))))
      (setq rr (c!:pareval (list a1 a2) env))
      (c!:outop 'eq (setq r (c!:newreg)) (car rr) (cadr rr))
      (return r)))


(put 'eq 'c!:code (function c!:ceq))


(de c!:cequal (x env)
   (prog (a1 a2 r rr)
      (setq a1 (s!:improve (cadr x)))
      (setq a2 (s!:improve (caddr x)))
      (cond
         ((equal a1 nil) (return (c!:cval (list 'null a2) env)))
         ((equal a2 nil) (return (c!:cval (list 'null a1) env))))
      (setq rr (c!:pareval (list a1 a2) env))
      (c!:outop
         (cond ((or (c!:eqvalid a1) (c!:eqvalid a2)) 'eq) (t 'equal))
         (setq r (c!:newreg))
         (car rr)
         (cadr rr))
      (return r)))


(put 'equal 'c!:code (function c!:cequal))


(de c!:is_fixnum (x)
   (and (fixp x) (geq x (minus 134217728)) (leq x 134217727)))


(de c!:certainlyatom (x)
   (or
      (null x)
      (equal x t)
      (c!:is_fixnum x)
      (and
         (eqcar x 'quote)
         (or (symbolp (cadr x)) (c!:is_fixnum (cadr x)))) ))


(de c!:atomlist1 (u)
   (or
      (atom u)
      (and
         (or (symbolp (car u)) (c!:is_fixnum (car u)))
         (c!:atomlist1 (cdr u)))) )


(de c!:atomlist (x)
   (or
      (null x)
      (and (eqcar x 'quote) (c!:atomlist1 (cadr x)))
      (and
         (eqcar x 'list)
         (or
            (null (cdr x))
            (and
               (c!:certainlyatom (cadr x))
               (c!:atomlist (cons 'list (cddr x)))) ))
      (and
         (eqcar x 'cons)
         (c!:certainlyatom (cadr x))
         (c!:atomlist (caddr x)))) )


(de c!:atomcar (x)
   (and
      (or (eqcar x 'cons) (eqcar x 'list))
      (not (null (cdr x)))
      (c!:certainlyatom (cadr x))))


(de c!:atomkeys1 (u)
   (or
      (atom u)
      (and
         (not (atom (car u)))
         (or (symbolp (caar u)) (c!:is_fixnum (caar u)))
         (c!:atomlist1 (cdr u)))) )


(de c!:atomkeys (x)
   (or
      (null x)
      (and (eqcar x 'quote) (c!:atomkeys1 (cadr x)))
      (and
         (eqcar x 'list)
         (or
            (null (cdr x))
            (and (c!:atomcar (cadr x)) (c!:atomkeys (cons 'list (cddr x)))) ))
      (and (eqcar x 'cons) (c!:atomcar (cadr x)) (c!:atomkeys (caddr x)))) )


(de c!:comsublis (x)
   (cond ((c!:atomkeys (cadr x)) (cons 'subla (cdr x))) (t nil)))


(put 'sublis 'c!:compile_macro (function c!:comsublis))


(de c!:comassoc (x)
   (cond
      ((or (c!:certainlyatom (cadr x)) (c!:atomkeys (caddr x)))
         (cons 'atsoc (cdr x)))
      (t nil)))


(put 'assoc 'c!:compile_macro (function c!:comassoc))


(put 'assoc!*!* 'c!:compile_macro (function c!:comassoc))


(de c!:commember (x)
   (cond
      ((or (c!:certainlyatom (cadr x)) (c!:atomlist (caddr x)))
         (cons 'memq (cdr x)))
      (t nil)))


(put 'member 'c!:compile_macro (function c!:commember))


(de c!:comdelete (x)
   (cond
      ((or (c!:certainlyatom (cadr x)) (c!:atomlist (caddr x)))
         (cons 'deleq (cdr x)))
      (t nil)))


(put 'delete 'c!:compile_macro (function c!:comdelete))


(de c!:ctestif (x env d1 d2)
   (prog (l1 l2)
      (setq l1 (c!:my_gensym))
      (setq l2 (c!:my_gensym))
      (c!:jumpif (cadr x) l1 l2)
      (setq x (cddr x))
      (c!:startblock l1)
      (c!:jumpif (car x) d1 d2)
      (c!:startblock l2)
      (c!:jumpif (cadr x) d1 d2)))


(put 'if 'c!:ctest (function c!:ctestif))


(de c!:ctestnull (x env d1 d2) (c!:cjumpif (cadr x) env d2 d1))


(put 'null 'c!:ctest (function c!:ctestnull))


(put 'not 'c!:ctest (function c!:ctestnull))


(de c!:ctestatom (x env d1 d2)
   (prog nil
      (setq x (c!:cval (cadr x) env))
      (c!:endblock (list 'ifatom x) (list d1 d2))))


(put 'atom 'c!:ctest (function c!:ctestatom))


(de c!:ctestconsp (x env d1 d2)
   (prog nil
      (setq x (c!:cval (cadr x) env))
      (c!:endblock (list 'ifatom x) (list d2 d1))))


(put 'consp 'c!:ctest (function c!:ctestconsp))


(de c!:ctestsymbol (x env d1 d2)
   (prog nil
      (setq x (c!:cval (cadr x) env))
      (c!:endblock (list 'ifsymbol x) (list d1 d2))))


(put 'idp 'c!:ctest (function c!:ctestsymbol))


(de c!:ctestnumberp (x env d1 d2)
   (prog nil
      (setq x (c!:cval (cadr x) env))
      (c!:endblock (list 'ifnumber x) (list d1 d2))))


(put 'numberp 'c!:ctest (function c!:ctestnumberp))


(de c!:ctestizerop (x env d1 d2)
   (prog nil
      (setq x (c!:cval (cadr x) env))
      (c!:endblock (list 'ifizerop x) (list d1 d2))))


(put 'izerop 'c!:ctest (function c!:ctestizerop))


(de c!:ctesteq (x env d1 d2)
   (prog (a1 a2 r)
      (setq a1 (cadr x))
      (setq a2 (caddr x))
      (cond
         ((equal a1 nil) (return (c!:cjumpif a2 env d2 d1)))
         ((equal a2 nil) (return (c!:cjumpif a1 env d2 d1))))
      (setq r (c!:pareval (list a1 a2) env))
      (c!:endblock (cons 'ifeq r) (list d1 d2))))


(put 'eq 'c!:ctest (function c!:ctesteq))


(de c!:ctesteqcar (x env d1 d2)
   (prog (a1 a2 r d3)
      (setq a1 (cadr x))
      (setq a2 (caddr x))
      (setq d3 (c!:my_gensym))
      (setq r (c!:pareval (list a1 a2) env))
      (c!:endblock (list 'ifatom (car r)) (list d2 d3))
      (c!:startblock d3)
      (c!:outop 'qcar (car r) nil (car r))
      (c!:endblock (cons 'ifeq r) (list d1 d2))))


(put 'eqcar 'c!:ctest (function c!:ctesteqcar))


(global '(least_fixnum greatest_fixnum))


(setq least_fixnum (minus (expt 2 27)))


(setq greatest_fixnum (difference (expt 2 27) 1))


(de c!:small_number (x)
   (and (fixp x) (geq x least_fixnum) (leq x greatest_fixnum)))


(de c!:eqvalid (x)
   (cond
      ((atom x) (c!:small_number x))
      ((flagp (car x) 'c!:fixnum_fn) t)
      (t (and
            (equal (car x) 'quote)
            (or (idp (cadr x)) (c!:small_number (cadr x)))) )))


(flag '(iplus iplus2 idifference iminus itimes itimes2) 'c!:fixnum_fn)


(de c!:ctestequal (x env d1 d2)
   (prog (a1 a2 r)
      (setq a1 (s!:improve (cadr x)))
      (setq a2 (s!:improve (caddr x)))
      (cond
         ((equal a1 nil) (return (c!:cjumpif a2 env d2 d1)))
         ((equal a2 nil) (return (c!:cjumpif a1 env d2 d1))))
      (setq r (c!:pareval (list a1 a2) env))
      (c!:endblock
         (cons
            (cond ((or (c!:eqvalid a1) (c!:eqvalid a2)) 'ifeq) (t 'ifequal))
            r)
         (list d1 d2))))


(put 'equal 'c!:ctest (function c!:ctestequal))


(de c!:ctestilessp (x env d1 d2)
   (prog (r)
      (setq r (c!:pareval (list (cadr x) (caddr x)) env))
      (c!:endblock (cons 'ifilessp r) (list d1 d2))))


(put 'ilessp 'c!:ctest (function c!:ctestilessp))


(de c!:ctestigreaterp (x env d1 d2)
   (prog (r)
      (setq r (c!:pareval (list (cadr x) (caddr x)) env))
      (c!:endblock (cons 'ifigreaterp r) (list d1 d2))))


(put 'igreaterp 'c!:ctest (function c!:ctestigreaterp))


(de c!:ctestand (x env d1 d2)
   (prog (next)
      (prog (a)
         (setq a (cdr x))
   lab   (cond ((null a) (return nil)))
         ((lambda (a)
             (progn
                (setq next (c!:my_gensym))
                (c!:cjumpif a env next d2)
                (c!:startblock next)))
            (car a))
         (setq a (cdr a))
         (go lab))
      (c!:endblock 'goto (list d1))))


(put 'and 'c!:ctest (function c!:ctestand))


(de c!:ctestor (x env d1 d2)
   (prog (next)
      (prog (a)
         (setq a (cdr x))
   lab   (cond ((null a) (return nil)))
         ((lambda (a)
             (progn
                (setq next (c!:my_gensym))
                (c!:cjumpif a env d1 next)
                (c!:startblock next)))
            (car a))
         (setq a (cdr a))
         (go lab))
      (c!:endblock 'goto (list d2))))


(put 'or 'c!:ctest (function c!:ctestor))


(progn
   (put 'abs 'c!:c_entrypoint "Labsval")
   (put 'append 'c!:c_entrypoint "Lappend")
   (put 'apply0 'c!:c_entrypoint "Lapply0")
   (put 'apply1 'c!:c_entrypoint "Lapply1")
   (put 'apply2 'c!:c_entrypoint "Lapply2")
   (put 'apply3 'c!:c_entrypoint "Lapply3")
   (put 'ash1 'c!:c_entrypoint "Lash1")
   (put 'assoc 'c!:c_entrypoint "Lassoc")
   (put 'atan 'c!:c_entrypoint "Latan")
   (put 'atom 'c!:c_entrypoint "Latom")
   (put 'atsoc 'c!:c_entrypoint "Latsoc")
   (put 'batchp 'c!:c_entrypoint "Lbatchp")
   (put 'boundp 'c!:c_entrypoint "Lboundp")
   (put 'bps!-putv 'c!:c_entrypoint "Lbpsputv")
   (put 'caaaar 'c!:c_entrypoint "Lcaaaar")
   (put 'caaadr 'c!:c_entrypoint "Lcaaadr")
   (put 'caaar 'c!:c_entrypoint "Lcaaar")
   (put 'caadar 'c!:c_entrypoint "Lcaadar")
   (put 'caaddr 'c!:c_entrypoint "Lcaaddr")
   (put 'caadr 'c!:c_entrypoint "Lcaadr")
   (put 'caar 'c!:c_entrypoint "Lcaar")
   (put 'cadaar 'c!:c_entrypoint "Lcadaar")
   (put 'cadadr 'c!:c_entrypoint "Lcadadr")
   (put 'cadar 'c!:c_entrypoint "Lcadar")
   (put 'caddar 'c!:c_entrypoint "Lcaddar")
   (put 'cadddr 'c!:c_entrypoint "Lcadddr")
   (put 'caddr 'c!:c_entrypoint "Lcaddr")
   (put 'cadr 'c!:c_entrypoint "Lcadr")
   (put 'car 'c!:c_entrypoint "Lcar")
   (put 'cdaaar 'c!:c_entrypoint "Lcdaaar")
   (put 'cdaadr 'c!:c_entrypoint "Lcdaadr")
   (put 'cdaar 'c!:c_entrypoint "Lcdaar")
   (put 'cdadar 'c!:c_entrypoint "Lcdadar")
   (put 'cdaddr 'c!:c_entrypoint "Lcdaddr")
   (put 'cdadr 'c!:c_entrypoint "Lcdadr")
   (put 'cdar 'c!:c_entrypoint "Lcdar")
   (put 'cddaar 'c!:c_entrypoint "Lcddaar")
   (put 'cddadr 'c!:c_entrypoint "Lcddadr")
   (put 'cddar 'c!:c_entrypoint "Lcddar")
   (put 'cdddar 'c!:c_entrypoint "Lcdddar")
   (put 'cddddr 'c!:c_entrypoint "Lcddddr")
   (put 'cdddr 'c!:c_entrypoint "Lcdddr")
   (put 'cddr 'c!:c_entrypoint "Lcddr")
   (put 'cdr 'c!:c_entrypoint "Lcdr")
   (put 'char!-code 'c!:c_entrypoint "Lchar_code")
   (put 'close 'c!:c_entrypoint "Lclose")
   (put 'code!-char 'c!:c_entrypoint "Lcode_char")
   (put 'codep 'c!:c_entrypoint "Lcodep")
   (put 'compress 'c!:c_entrypoint "Lcompress")
   (put 'constantp 'c!:c_entrypoint "Lconstantp")
   (put 'date 'c!:c_entrypoint "Ldate")
   (put 'deleq 'c!:c_entrypoint "Ldeleq")
   (put 'delete 'c!:c_entrypoint "Ldelete")
   (put 'digit 'c!:c_entrypoint "Ldigitp")
   (put 'divide 'c!:c_entrypoint "Ldivide")
   (put 'eject 'c!:c_entrypoint "Leject")
   (put 'endp 'c!:c_entrypoint "Lendp")
   (put 'eq 'c!:c_entrypoint "Leq")
   (put 'eqcar 'c!:c_entrypoint "Leqcar")
   (put 'eql 'c!:c_entrypoint "Leql")
   (put 'eqn 'c!:c_entrypoint "Leqn")
   (put 'equal 'c!:c_entrypoint "Lequal")
   (put 'error 'c!:c_entrypoint "Lerror")
   (put 'error1 'c!:c_entrypoint "Lerror1")
   (put 'evenp 'c!:c_entrypoint "Levenp")
   (put 'evlis 'c!:c_entrypoint "Levlis")
   (put 'explode 'c!:c_entrypoint "Lexplode")
   (put 'explode2 'c!:c_entrypoint "Lexplodec")
   (put 'explodec 'c!:c_entrypoint "Lexplodec")
   (put 'expt 'c!:c_entrypoint "Lexpt")
   (put 'fasldef 'c!:c_entrypoint "Lfasldef")
   (put 'faslstart 'c!:c_entrypoint "Lfaslstart")
   (put 'faslwrite 'c!:c_entrypoint "Lfaslwrite")
   (put 'fix 'c!:c_entrypoint "Ltruncate")
   (put 'fixp 'c!:c_entrypoint "Lfixp")
   (put 'flag 'c!:c_entrypoint "Lflag")
   (put 'flagp!*!* 'c!:c_entrypoint "Lflagp")
   (put 'flagp 'c!:c_entrypoint "Lflagp")
   (put 'flagpcar 'c!:c_entrypoint "Lflagpcar")
   (put 'float 'c!:c_entrypoint "Lfloat")
   (put 'floatp 'c!:c_entrypoint "Lfloatp")
   (put 'fluidp 'c!:c_entrypoint "Lsymbol_specialp")
   (put 'gcdn 'c!:c_entrypoint "Lgcd")
   (put 'gctime 'c!:c_entrypoint "Lgctime")
   (put 'gensym 'c!:c_entrypoint "Lgensym")
   (put 'gensym1 'c!:c_entrypoint "Lgensym1")
   (put 'geq 'c!:c_entrypoint "Lgeq")
   (put 'get!* 'c!:c_entrypoint "Lget")
   (put 'getenv 'c!:c_entrypoint "Lgetenv")
   (put 'getv 'c!:c_entrypoint "Lgetv")
   (put 'globalp 'c!:c_entrypoint "Lsymbol_globalp")
   (put 'greaterp 'c!:c_entrypoint "Lgreaterp")
   (put 'iadd1 'c!:c_entrypoint "Liadd1")
   (put 'idifference 'c!:c_entrypoint "Lidifference")
   (put 'idp 'c!:c_entrypoint "Lsymbolp")
   (put 'igreaterp 'c!:c_entrypoint "Ligreaterp")
   (put 'ilessp 'c!:c_entrypoint "Lilessp")
   (put 'iminus 'c!:c_entrypoint "Liminus")
   (put 'iminusp 'c!:c_entrypoint "Liminusp")
   (put 'indirect 'c!:c_entrypoint "Lindirect")
   (put 'integerp 'c!:c_entrypoint "Lintegerp")
   (put 'intern 'c!:c_entrypoint "Lintern")
   (put 'iplus2 'c!:c_entrypoint "Liplus2")
   (put 'iquotient 'c!:c_entrypoint "Liquotient")
   (put 'iremainder 'c!:c_entrypoint "Liremainder")
   (put 'irightshift 'c!:c_entrypoint "Lirightshift")
   (put 'isub1 'c!:c_entrypoint "Lisub1")
   (put 'itimes2 'c!:c_entrypoint "Litimes2")
   (put 'length 'c!:c_entrypoint "Llength")
   (put 'lengthc 'c!:c_entrypoint "Llengthc")
   (put 'leq 'c!:c_entrypoint "Lleq")
   (put 'lessp 'c!:c_entrypoint "Llessp")
   (put 'linelength 'c!:c_entrypoint "Llinelength")
   (put 'liter 'c!:c_entrypoint "Lalpha_char_p")
   (put 'load!-module 'c!:c_entrypoint "Lload_module")
   (put 'lposn 'c!:c_entrypoint "Llposn")
   (put 'macro!-function 'c!:c_entrypoint "Lmacro_function")
   (put 'macroexpand!-1 'c!:c_entrypoint "Lmacroexpand_1")
   (put 'macroexpand 'c!:c_entrypoint "Lmacroexpand")
   (put 'make!-bps 'c!:c_entrypoint "Lget_bps")
   (put 'make!-global 'c!:c_entrypoint "Lmake_global")
   (put 'make!-simple!-string 'c!:c_entrypoint "Lsmkvect")
   (put 'make!-special 'c!:c_entrypoint "Lmake_special")
   (put 'mapstore 'c!:c_entrypoint "Lmapstore")
   (put 'max2 'c!:c_entrypoint "Lmax2")
   (put 'member 'c!:c_entrypoint "Lmember")
   (put 'memq 'c!:c_entrypoint "Lmemq")
   (put 'min2 'c!:c_entrypoint "Lmin2")
   (put 'minus 'c!:c_entrypoint "Lminus")
   (put 'minusp 'c!:c_entrypoint "Lminusp")
   (put 'mkquote 'c!:c_entrypoint "Lmkquote")
   (put 'mkvect 'c!:c_entrypoint "Lmkvect")
   (put 'mod 'c!:c_entrypoint "Lmod")
   (put 'modular!-difference 'c!:c_entrypoint "Lmodular_difference")
   (put 'modular!-expt 'c!:c_entrypoint "Lmodular_expt")
   (put 'modular!-minus 'c!:c_entrypoint "Lmodular_minus")
   (put 'modular!-number 'c!:c_entrypoint "Lmodular_number")
   (put 'modular!-plus 'c!:c_entrypoint "Lmodular_plus")
   (put 'modular!-quotient 'c!:c_entrypoint "Lmodular_quotient")
   (put 'modular!-reciprocal 'c!:c_entrypoint "Lmodular_reciprocal")
   (put 'modular!-times 'c!:c_entrypoint "Lmodular_times")
   (put 'nconc 'c!:c_entrypoint "Lnconc")
   (put 'neq 'c!:c_entrypoint "Lneq")
   (put 'not 'c!:c_entrypoint "Lnull")
   (put 'null 'c!:c_entrypoint "Lnull")
   (put 'numberp 'c!:c_entrypoint "Lnumberp")
   (put 'oddp 'c!:c_entrypoint "Loddp")
   (put 'onep 'c!:c_entrypoint "Lonep")
   (put 'orderp 'c!:c_entrypoint "Lorderp")
   (put 'pagelength 'c!:c_entrypoint "Lpagelength")
   (put 'pairp 'c!:c_entrypoint "Lconsp")
   (put 'plist 'c!:c_entrypoint "Lplist")
   (put 'plusp 'c!:c_entrypoint "Lplusp")
   (put 'posn 'c!:c_entrypoint "Lposn")
   (put 'prin 'c!:c_entrypoint "Lprin")
   (put 'prin1 'c!:c_entrypoint "Lprin")
   (put 'prin2 'c!:c_entrypoint "Lprinc")
   (put 'princ 'c!:c_entrypoint "Lprinc")
   (put 'print 'c!:c_entrypoint "Lprint")
   (put 'printc 'c!:c_entrypoint "Lprintc")
   (put 'put 'c!:c_entrypoint "Lputprop")
   (put 'putv!-char 'c!:c_entrypoint "Lsputv")
   (put 'putv 'c!:c_entrypoint "Lputv")
   (put 'qcaar 'c!:c_entrypoint "Lcaar")
   (put 'qcadr 'c!:c_entrypoint "Lcadr")
   (put 'qcar 'c!:c_entrypoint "Lcar")
   (put 'qcdar 'c!:c_entrypoint "Lcdar")
   (put 'qcddr 'c!:c_entrypoint "Lcddr")
   (put 'qcdr 'c!:c_entrypoint "Lcdr")
   (put 'qgetv 'c!:c_entrypoint "Lgetv")
   (put 'rdf 'c!:c_entrypoint "Lrdf")
   (put 'rds 'c!:c_entrypoint "Lrds")
   (put 'read 'c!:c_entrypoint "Lread")
   (put 'readch 'c!:c_entrypoint "Lreadch")
   (put 'reclaim 'c!:c_entrypoint "Lgc")
   (put 'remd 'c!:c_entrypoint "Lremd")
   (put 'remflag 'c!:c_entrypoint "Lremflag")
   (put 'remob 'c!:c_entrypoint "Lunintern")
   (put 'remprop 'c!:c_entrypoint "Lremprop")
   (put 'representation 'c!:c_entrypoint "Lrepresentation")
   (put 'reverse 'c!:c_entrypoint "Lreverse")
   (put 'reversip 'c!:c_entrypoint "Lnreverse")
   (put 'rplaca 'c!:c_entrypoint "Lrplaca")
   (put 'rplacd 'c!:c_entrypoint "Lrplacd")
   (put 'schar 'c!:c_entrypoint "Lsgetv")
   (put 'seprp 'c!:c_entrypoint "Lwhitespace_char_p")
   (put 'set!-small!-modulus 'c!:c_entrypoint "Lset_small_modulus")
   (put 'set 'c!:c_entrypoint "Lset")
   (put 'smemq 'c!:c_entrypoint "Lsmemq")
   (put 'spaces 'c!:c_entrypoint "Lxtab")
   (put 'special!-char 'c!:c_entrypoint "Lspecial_char")
   (put 'special!-form!-p 'c!:c_entrypoint "Lspecial_form_p")
   (put 'spool 'c!:c_entrypoint "Lspool")
   (put 'stop 'c!:c_entrypoint "Lstop")
   (put 'stringp 'c!:c_entrypoint "Lstringp")
   (put 'subla 'c!:c_entrypoint "Lsubla")
   (put 'sublis 'c!:c_entrypoint "Lsublis")
   (put 'subst 'c!:c_entrypoint "Lsubst")
   (put 'symbol!-env 'c!:c_entrypoint "Lsymbol_env")
   (put 'symbol!-function 'c!:c_entrypoint "Lsymbol_function")
   (put 'symbol!-name 'c!:c_entrypoint "Lsymbol_name")
   (put 'symbol!-set!-definition 'c!:c_entrypoint "Lsymbol_set_definition")
   (put 'symbol!-set!-env 'c!:c_entrypoint "Lsymbol_set_env")
   (put 'symbol!-value 'c!:c_entrypoint "Lsymbol_value")
   (put 'system 'c!:c_entrypoint "Lsystem")
   (put 'terpri 'c!:c_entrypoint "Lterpri")
   (put 'threevectorp 'c!:c_entrypoint "Lthreevectorp")
   (put 'time 'c!:c_entrypoint "Ltime")
   (put 'ttab 'c!:c_entrypoint "Lttab")
   (put 'tyo 'c!:c_entrypoint "Ltyo")
   (put 'unmake!-global 'c!:c_entrypoint "Lunmake_global")
   (put 'unmake!-special 'c!:c_entrypoint "Lunmake_special")
   (put 'upbv 'c!:c_entrypoint "Lupbv")
   (put 'vectorp 'c!:c_entrypoint "Lsimple_vectorp")
   (put 'verbos 'c!:c_entrypoint "Lverbos")
   (put 'wrs 'c!:c_entrypoint "Lwrs")
   (put 'xcons 'c!:c_entrypoint "Lxcons")
   (put 'xtab 'c!:c_entrypoint "Lxtab")
   (put 'zerop 'c!:c_entrypoint "Lzerop")
   (put 'cons 'c!:direct_entrypoint (cons 2 "cons"))
   (put 'ncons 'c!:direct_entrypoint (cons 1 "ncons"))
   (put 'list2 'c!:direct_entrypoint (cons 2 "list2"))
   (put 'list2!* 'c!:direct_entrypoint (cons 3 "list2star"))
   (put 'acons 'c!:direct_entrypoint (cons 3 "acons"))
   (put 'list3 'c!:direct_entrypoint (cons 3 "list3"))
   (put 'plus2 'c!:direct_entrypoint (cons 2 "plus2"))
   (put 'difference 'c!:direct_entrypoint (cons 2 "difference2"))
   (put 'add1 'c!:direct_entrypoint (cons 1 "add1"))
   (put 'sub1 'c!:direct_entrypoint (cons 1 "sub1"))
   (put 'get 'c!:direct_entrypoint (cons 2 "get"))
   (put 'lognot 'c!:direct_entrypoint (cons 1 "lognot"))
   (put 'ash 'c!:direct_entrypoint (cons 2 "ash"))
   (put 'quotient 'c!:direct_entrypoint (cons 2 "quot2"))
   (put 'remainder 'c!:direct_entrypoint (cons 2 "Cremainder"))
   (put 'times2 'c!:direct_entrypoint (cons 2 "times2"))
   (put 'minus 'c!:direct_entrypoint (cons 1 "negate"))
   (put 'rational 'c!:direct_entrypoint (cons 1 "rational"))
   (put 'lessp 'c!:direct_predicate (cons 2 "lessp2"))
   (put 'leq 'c!:direct_predicate (cons 2 "lesseq2"))
   (put 'greaterp 'c!:direct_predicate (cons 2 "greaterp2"))
   (put 'geq 'c!:direct_predicate (cons 2 "geq2"))
   (put 'zerop 'c!:direct_predicate (cons 1 "zerop"))
   "C entrypoints established")


(flag
   '(atom atsoc codep constantp deleq digit endp eq eqcar evenp eql fixp flagp
       flagpcar floatp get globalp iadd1 idifference idp igreaterp ilessp
       iminus iminusp indirect integerp iplus2 irightshift isub1 itimes2 liter
       memq minusp modular!-difference modular!-expt modular!-minus
       modular!-number modular!-plus modular!-times not null numberp onep
       pairp plusp qcaar qcadr qcar qcdar qcddr qcdr remflag remprop reversip
       seprp special!-form!-p stringp symbol!-env symbol!-name symbol!-value
       threevectorp vectorp zerop)
   'c!:no_errors)


