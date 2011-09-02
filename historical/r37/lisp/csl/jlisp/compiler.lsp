

(global '(s!:opcodelist))


(setq s!:opcodelist
   '(loadloc loadloc0 loadloc1 loadloc2 loadloc3 loadloc4 loadloc5 loadloc6
       loadloc7 loadloc8 loadloc9 loadloc10 loadloc11 loc0loc1 loc1loc2
       loc2loc3 loc1loc0 loc2loc1 loc3loc2 vnil loadlit loadlit1 loadlit2
       loadlit3 loadlit4 loadlit5 loadlit6 loadlit7 loadfree loadfree1
       loadfree2 loadfree3 loadfree4 storeloc storeloc0 storeloc1 storeloc2
       storeloc3 storeloc4 storeloc5 storeloc6 storeloc7 storefree storefree1
       storefree2 storefree3 loadlex storelex closure carloc0 carloc1 carloc2
       carloc3 carloc4 carloc5 carloc6 carloc7 carloc8 carloc9 carloc10
       carloc11 cdrloc0 cdrloc1 cdrloc2 cdrloc3 cdrloc4 cdrloc5 caarloc0
       caarloc1 caarloc2 caarloc3 call0 call1 call2 call2r call3 calln call0_0
       call0_1 call0_2 call0_3 call1_0 call1_1 call1_2 call1_3 call1_4 call1_5
       call2_0 call2_1 call2_2 call2_3 call2_4 builtin0 builtin1 builtin2
       builtin2r builtin3 apply1 apply2 apply3 apply4 jcall jcalln jump jump_b
       jump_l jump_bl jumpnil jumpnil_b jumpnil_l jumpnil_bl jumpt jumpt_b
       jumpt_l jumpt_bl jumpatom jumpatom_b jumpatom_l jumpatom_bl jumpnatom
       jumpnatom_b jumpnatom_l jumpnatom_bl jumpeq jumpeq_b jumpeq_l jumpeq_bl
       jumpne jumpne_b jumpne_l jumpne_bl jumpequal jumpequal_b jumpequal_l
       jumpequal_bl jumpnequal jumpnequal_b jumpnequal_l jumpnequal_bl
       jumpl0nil jumpl0t jumpl1nil jumpl1t jumpl2nil jumpl2t jumpl3nil jumpl3t
       jumpl4nil jumpl4t jumpst0nil jumpst0t jumpst1nil jumpst1t jumpst2nil
       jumpst2t jumpl0atom jumpl0natom jumpl1atom jumpl1natom jumpl2atom
       jumpl2natom jumpl3atom jumpl3natom jumpfree1nil jumpfree1t jumpfree2nil
       jumpfree2t jumpfree3nil jumpfree3t jumpfree4nil jumpfree4t jumpfreenil
       jumpfreet jumplit1eq jumplit1ne jumplit2eq jumplit2ne jumplit3eq
       jumplit3ne jumplit4eq jumplit4ne jumpliteq jumplitne jumpb1nil jumpb1t
       jumpb2nil jumpb2t jumpflagp jumpnflagp jumpeqcar jumpneqcar catch
       catch_b catch_l catch_bl uncatch throw protect unprotect pvbind
       pvrestore freebind freerstr exit nilexit loc0exit loc1exit loc2exit
       push pushnil pushnil2 pushnil3 pushnils pop lose lose2 lose3 loses swop
       eq eqcar equal numberp car cdr caar cadr cdar cddr cons ncons xcons
       acons length list2 list2star list3 plus2 add1 difference sub1 times2
       greaterp lessp flagp get litget getv qgetv qgetvn bigstack bigcall
       icase fastget spare1 spare2))


(prog (n)
   (setq n 0)
   (prog (v)
      (setq v s!:opcodelist)
lab   (cond ((null v) (return nil)))
      ((lambda (v) (progn (put v 's!:opcode n) (setq n (plus n 1)))) (car v))
      (setq v (cdr v))
      (go lab))
   (return (list n 'opcodes 'allocated)))


(de s!:vecof (l)
   (prog (v n)
      (setq v (mkvect (sub1 (length l))))
      (setq n 0)
      (prog (x)
         (setq x l)
   lab   (cond ((null x) (return nil)))
         ((lambda (x) (progn (putv v n x) (setq n (plus n 1)))) (car x))
         (setq x (cdr x))
         (go lab))
      (return v)))


(progn
   (put 'batchp 's!:builtin0 0)
   (put 'date 's!:builtin0 1)
   (put 'eject 's!:builtin0 2)
   (put 'error1 's!:builtin0 3)
   (put 'gctime 's!:builtin0 4)
   (put 'lposn 's!:builtin0 6)
   (put 'posn 's!:builtin0 8)
   (put 'read 's!:builtin0 9)
   (put 'readch 's!:builtin0 10)
   (put 'terpri 's!:builtin0 11)
   (put 'time 's!:builtin0 12)
   (put 'tyi 's!:builtin0 13)
   (put 'load!-spid 's!:builtin0 14)
   (put 'abs 's!:builtin1 0)
   (put 'add1 's!:builtin1 1)
   (put 'atan 's!:builtin1 2)
   (put 'apply0 's!:builtin1 3)
   (put 'atom 's!:builtin1 4)
   (put 'boundp 's!:builtin1 5)
   (put 'char!-code 's!:builtin1 6)
   (put 'close 's!:builtin1 7)
   (put 'codep 's!:builtin1 8)
   (put 'compress 's!:builtin1 9)
   (put 'constantp 's!:builtin1 10)
   (put 'digit 's!:builtin1 11)
   (put 'endp 's!:builtin1 12)
   (put 'eval 's!:builtin1 13)
   (put 'evenp 's!:builtin1 14)
   (put 'evlis 's!:builtin1 15)
   (put 'explode 's!:builtin1 16)
   (put 'explode2lc 's!:builtin1 17)
   (put 'explode2 's!:builtin1 18)
   (put 'explodec 's!:builtin1 18)
   (put 'fixp 's!:builtin1 19)
   (put 'float 's!:builtin1 20)
   (put 'floatp 's!:builtin1 21)
   (put 'symbol!-specialp 's!:builtin1 22)
   (put 'gc 's!:builtin1 23)
   (put 'gensym1 's!:builtin1 24)
   (put 'getenv 's!:builtin1 25)
   (put 'symbol!-globalp 's!:builtin1 26)
   (put 'iadd1 's!:builtin1 27)
   (put 'symbolp 's!:builtin1 28)
   (put 'iminus 's!:builtin1 29)
   (put 'iminusp 's!:builtin1 30)
   (put 'indirect 's!:builtin1 31)
   (put 'integerp 's!:builtin1 32)
   (put 'intern 's!:builtin1 33)
   (put 'isub1 's!:builtin1 34)
   (put 'length 's!:builtin1 35)
   (put 'lengthc 's!:builtin1 36)
   (put 'linelength 's!:builtin1 37)
   (put 'liter 's!:builtin1 38)
   (put 'load!-module 's!:builtin1 39)
   (put 'lognot 's!:builtin1 40)
   (put 'macroexpand 's!:builtin1 41)
   (put 'macroexpand!-1 's!:builtin1 42)
   (put 'macro!-function 's!:builtin1 43)
   (put 'make!-bps 's!:builtin1 44)
   (put 'make!-global 's!:builtin1 45)
   (put 'make!-simple!-string 's!:builtin1 46)
   (put 'make!-special 's!:builtin1 47)
   (put 'minus 's!:builtin1 48)
   (put 'minusp 's!:builtin1 49)
   (put 'mkvect 's!:builtin1 50)
   (put 'modular!-minus 's!:builtin1 51)
   (put 'modular!-number 's!:builtin1 52)
   (put 'modular!-reciprocal 's!:builtin1 53)
   (put 'null 's!:builtin1 54)
   (put 'oddp 's!:builtin1 55)
   (put 'onep 's!:builtin1 56)
   (put 'pagelength 's!:builtin1 57)
   (put 'pairp 's!:builtin1 58)
   (put 'plist 's!:builtin1 59)
   (put 'plusp 's!:builtin1 60)
   (put 'prin 's!:builtin1 61)
   (put 'princ 's!:builtin1 62)
   (put 'print 's!:builtin1 63)
   (put 'printc 's!:builtin1 64)
   (put 'rational 's!:builtin1 66)
   (put 'rds 's!:builtin1 68)
   (put 'remd 's!:builtin1 69)
   (put 'reverse 's!:builtin1 70)
   (put 'reversip 's!:builtin1 71)
   (put 'seprp 's!:builtin1 72)
   (put 'set!-small!-modulus 's!:builtin1 73)
   (put 'spaces 's!:builtin1 74)
   (put 'xtab 's!:builtin1 74)
   (put 'special!-char 's!:builtin1 75)
   (put 'special!-form!-p 's!:builtin1 76)
   (put 'spool 's!:builtin1 77)
   (put 'stop 's!:builtin1 78)
   (put 'stringp 's!:builtin1 79)
   (put 'sub1 's!:builtin1 80)
   (put 'symbol!-env 's!:builtin1 81)
   (put 'symbol!-function 's!:builtin1 82)
   (put 'symbol!-name 's!:builtin1 83)
   (put 'symbol!-value 's!:builtin1 84)
   (put 'system 's!:builtin1 85)
   (put 'fix 's!:builtin1 86)
   (put 'ttab 's!:builtin1 87)
   (put 'tyo 's!:builtin1 88)
   (put 'remob 's!:builtin1 89)
   (put 'unmake!-global 's!:builtin1 90)
   (put 'unmake!-special 's!:builtin1 91)
   (put 'upbv 's!:builtin1 92)
   (put 'vectorp 's!:builtin1 93)
   (put 'verbos 's!:builtin1 94)
   (put 'wrs 's!:builtin1 95)
   (put 'zerop 's!:builtin1 96)
   (put 'car 's!:builtin1 97)
   (put 'cdr 's!:builtin1 98)
   (put 'caar 's!:builtin1 99)
   (put 'cadr 's!:builtin1 100)
   (put 'cdar 's!:builtin1 101)
   (put 'cddr 's!:builtin1 102)
   (put 'qcar 's!:builtin1 103)
   (put 'qcdr 's!:builtin1 104)
   (put 'qcaar 's!:builtin1 105)
   (put 'qcadr 's!:builtin1 106)
   (put 'qcdar 's!:builtin1 107)
   (put 'qcddr 's!:builtin1 108)
   (put 'ncons 's!:builtin1 109)
   (put 'numberp 's!:builtin1 110)
   (put 'is!-spid 's!:builtin1 111)
   (put 'spid!-to!-nil 's!:builtin1 112)
   (put 'append 's!:builtin2 0)
   (put 'ash 's!:builtin2 1)
   (put 'assoc 's!:builtin2 2)
   (put 'assoc!*!* 's!:builtin2 2)
   (put 'atsoc 's!:builtin2 3)
   (put 'deleq 's!:builtin2 4)
   (put 'delete 's!:builtin2 5)
   (put 'divide 's!:builtin2 6)
   (put 'eqcar 's!:builtin2 7)
   (put 'eql 's!:builtin2 8)
   (put 'eqn 's!:builtin2 9)
   (put 'expt 's!:builtin2 10)
   (put 'flag 's!:builtin2 11)
   (put 'flagpcar 's!:builtin2 12)
   (put 'gcdn 's!:builtin2 13)
   (put 'geq 's!:builtin2 14)
   (put 'getv 's!:builtin2 15)
   (put 'greaterp 's!:builtin2 16)
   (put 'idifference 's!:builtin2 17)
   (put 'igreaterp 's!:builtin2 18)
   (put 'ilessp 's!:builtin2 19)
   (put 'imax 's!:builtin2 20)
   (put 'imin 's!:builtin2 21)
   (put 'iplus2 's!:builtin2 22)
   (put 'iquotient 's!:builtin2 23)
   (put 'iremainder 's!:builtin2 24)
   (put 'irightshift 's!:builtin2 25)
   (put 'itimes2 's!:builtin2 26)
   (put 'leq 's!:builtin2 28)
   (put 'lessp 's!:builtin2 29)
   (put 'max2 's!:builtin2 31)
   (put 'member 's!:builtin2 32)
   (put 'member!*!* 's!:builtin2 32)
   (put 'memq 's!:builtin2 33)
   (put 'min2 's!:builtin2 34)
   (put 'mod 's!:builtin2 35)
   (put 'modular!-difference 's!:builtin2 36)
   (put 'modular!-expt 's!:builtin2 37)
   (put 'modular!-plus 's!:builtin2 38)
   (put 'modular!-quotient 's!:builtin2 39)
   (put 'modular!-times 's!:builtin2 40)
   (put 'nconc 's!:builtin2 41)
   (put 'neq 's!:builtin2 42)
   (put 'orderp 's!:builtin2 43)
   (put 'quotient 's!:builtin2 44)
   (put 'remainder 's!:builtin2 45)
   (put 'remflag 's!:builtin2 46)
   (put 'remprop 's!:builtin2 47)
   (put 'rplaca 's!:builtin2 48)
   (put 'rplacd 's!:builtin2 49)
   (put 'schar 's!:builtin2 50)
   (put 'set 's!:builtin2 51)
   (put 'smemq 's!:builtin2 52)
   (put 'subla 's!:builtin2 53)
   (put 'sublis 's!:builtin2 54)
   (put 'symbol!-set!-definition 's!:builtin2 55)
   (put 'symbol!-set!-env 's!:builtin2 56)
   (put 'times2 's!:builtin2 57)
   (put 'xcons 's!:builtin2 58)
   (put 'equal 's!:builtin2 59)
   (put 'eq 's!:builtin2 60)
   (put 'cons 's!:builtin2 61)
   (put 'list2 's!:builtin2 62)
   (put 'get 's!:builtin2 63)
   (put 'qgetv 's!:builtin2 64)
   (put 'flagp 's!:builtin2 65)
   (put 'apply1 's!:builtin2 66)
   (put 'difference 's!:builtin2 67)
   (put 'plus2 's!:builtin2 68)
   (put 'times2 's!:builtin2 69)
   (put 'bps!-putv 's!:builtin3 0)
   (put 'errorset 's!:builtin3 1)
   (put 'list2!* 's!:builtin3 2)
   (put 'list3 's!:builtin3 3)
   (put 'putprop 's!:builtin3 4)
   (put 'putv 's!:builtin3 5)
   (put 'putv!-char 's!:builtin3 6)
   (put 'subst 's!:builtin3 7)
   (put 'apply2 's!:builtin3 8)
   (put 'acons 's!:builtin3 9)
   nil)


(de s!:prinhex1 (n) (princ (schar "0123456789abcdef" (logand n 15))))


(de s!:prinhex2 (n) (progn (s!:prinhex1 (truncate n 16)) (s!:prinhex1 n)))


(de s!:prinhex4 (n) (progn (s!:prinhex2 (truncate n 256)) (s!:prinhex2 n)))


(flag '(comp plap pgwd pwrds notailcall carcheckflag savedef) 'switch)


(cond ((not (boundp '!*comp)) (progn (fluid '(!*comp)) (setq !*comp t))))


(cond ((not (boundp '!*plap)) (progn (fluid '(!*plap)) (setq !*plap nil))))


(cond ((not (boundp '!*pgwd)) (progn (fluid '(!*pgwd)) (setq !*pgwd nil))))


(cond ((not (boundp '!*pwrds)) (progn (fluid '(!*pwrds)) (setq !*pwrds t))))


(cond
   ((not (boundp '!*notailcall))
      (progn (fluid '(!*notailcall)) (setq !*notailcall nil))))


(cond
   ((not (boundp '!*savedef))
      (progn (fluid '(!*savedef)) (setq !*savedef nil))))


(cond
   ((not (boundp '!*carcheckflag))
      (progn (fluid '(!*carcheckflag)) (setq !*carcheckflag t))))


(fluid
   '(s!:current_function
       s!:current_label
       s!:current_block
       s!:current_size
       s!:current_procedure
       s!:other_defs
       s!:lexical_env
       s!:has_closure
       s!:recent_literals
       s!:used_lexicals
       s!:a_reg_values))


(de s!:start_procedure (nargs nopts restarg)
   (progn
      (setq s!:current_procedure nil)
      (setq s!:current_label (gensym))
      (setq s!:a_reg_values nil)
      (cond
         ((or (not (zerop nopts)) restarg)
            (progn
               (setq s!:current_block
                  (list
                     (list 'optargs nopts)
                     nopts
                     (list 'argcount nargs)
                     nargs))
               (setq s!:current_size 2)))
         ((greaterp nargs 3)
            (progn
               (setq s!:current_block (list (list 'argcount nargs) nargs))
               (setq s!:current_size 1)))
         (t (progn (setq s!:current_block nil) (setq s!:current_size 0)))) ))


(de s!:set_label (x)
   (progn
      (cond
         (s!:current_label
            (prog (w)
               (setq w (cons s!:current_size s!:current_block))
               (prog (x)
                  (setq x s!:recent_literals)
            lab   (cond ((null x) (return nil)))
                  ((lambda (x) (rplaca x w)) (car x))
                  (setq x (cdr x))
                  (go lab))
               (setq s!:recent_literals nil)
               (setq s!:current_procedure
                  (cons
                     (cons s!:current_label (cons (list 'jump x) w))
                     s!:current_procedure))
               (setq s!:current_block nil)
               (setq s!:current_size 0))))
      (setq s!:current_label x)
      (setq s!:a_reg_values nil)))


(de s!:outjump (op lab)
   (prog (g w)
      (cond ((not (flagp op 's!:preserves_a)) (setq s!:a_reg_values nil)))
      (cond ((null s!:current_label) (return nil)))
      (cond
         ((equal op 'jump) (setq op (list op lab)))
         ((equal op 'icase) (setq op (cons op lab)))
         (t (setq op (list op lab (setq g (gensym)))) ))
      (setq w (cons s!:current_size s!:current_block))
      (prog (x)
         (setq x s!:recent_literals)
   lab   (cond ((null x) (return nil)))
         ((lambda (x) (rplaca x w)) (car x))
         (setq x (cdr x))
         (go lab))
      (setq s!:recent_literals nil)
      (setq s!:current_procedure
         (cons (cons s!:current_label (cons op w)) s!:current_procedure))
      (setq s!:current_block nil)
      (setq s!:current_size 0)
      (setq s!:current_label g)
      (return op)))


(de s!:outexit nil
   (prog (w op)
      (setq op '(exit))
      (cond ((null s!:current_label) (return nil)))
      (setq w (cons s!:current_size s!:current_block))
      (prog (x)
         (setq x s!:recent_literals)
   lab   (cond ((null x) (return nil)))
         ((lambda (x) (rplaca x w)) (car x))
         (setq x (cdr x))
         (go lab))
      (setq s!:recent_literals nil)
      (setq s!:current_procedure
         (cons (cons s!:current_label (cons op w)) s!:current_procedure))
      (setq s!:current_block nil)
      (setq s!:current_size 0)
      (setq s!:current_label nil)))


(flag
   '(push pushnil pushnil2 pushnil3 lose lose2 lose3 loses storeloc storeloc0
       storeloc1 storeloc2 storeloc3 storeloc4 storeloc5 storeloc6 storeloc7
       jump jumpt jumpnil jumpeq jumpequal jumpne jumpnequal jumpatom
       jumpnatom)
   's!:preserves_a)


(de s!:outopcode0 (op doc)
   (prog nil
      (cond ((not (flagp op 's!:preserves_a)) (setq s!:a_reg_values nil)))
      (cond ((null s!:current_label) (return nil)))
      (setq s!:current_block (cons op s!:current_block))
      (setq s!:current_size (plus s!:current_size 1))
      (cond
         ((or !*plap !*pgwd)
            (setq s!:current_block (cons doc s!:current_block)))) ))


(de s!:outopcode1 (op arg doc)
   (prog nil
      (cond ((not (flagp op 's!:preserves_a)) (setq s!:a_reg_values nil)))
      (cond ((null s!:current_label) (return nil)))
      (setq s!:current_block (cons arg (cons op s!:current_block)))
      (setq s!:current_size (plus s!:current_size 2))
      (cond
         ((or !*plap !*pgwd)
            (setq s!:current_block (cons (list op doc) s!:current_block)))) ))


(deflist
   '((loadlit 1) (loadfree 2) (call0 2) (call1 2) (litget 2) (jumpliteq 2)
       (jumplitne 2)
       (jumpliteq!* 2)
       (jumplitne!* 2)
       (jumpfreet 2)
       (jumpfreenil 2))
   's!:short_form_bonus)


(de s!:record_literal (env)
   (prog (w extra)
      (setq w (gethash (car s!:current_block) (car env)))
      (cond ((null w) (setq w (cons 0 nil))))
      (setq extra (get (cadr s!:current_block) 's!:short_form_bonus))
      (cond ((null extra) (setq extra 10)) (t (setq extra (plus extra 10))))
      (setq s!:recent_literals
         (cons (cons nil s!:current_block) s!:recent_literals))
      (puthash
         (car s!:current_block)
         (car env)
         (cons
            (plus (car w) extra)
            (cons (car s!:recent_literals) (cdr w)))) ))


(de s!:record_literal_for_jump (x env lab)
   (prog (w extra)
      (cond ((null s!:current_label) (return nil)))
      (setq w (gethash (cadr x) (car env)))
      (cond ((null w) (setq w (cons 0 nil))))
      (setq extra (get (car x) 's!:short_form_bonus))
      (cond ((null extra) (setq extra 10)) (t (setq extra (plus extra 10))))
      (setq x (s!:outjump x lab))
      (puthash
         (cadar x)
         (car env)
         (cons (plus (car w) extra) (cons (cons nil x) (cdr w)))) ))


(de s!:outopcode1lit (op arg env)
   (prog nil
      (cond ((not (flagp op 's!:preserves_a)) (setq s!:a_reg_values nil)))
      (cond ((null s!:current_label) (return nil)))
      (setq s!:current_block (cons arg (cons op s!:current_block)))
      (s!:record_literal env)
      (setq s!:current_size (plus s!:current_size 2))
      (cond
         ((or !*plap !*pgwd)
            (setq s!:current_block (cons (list op arg) s!:current_block)))) ))


(de s!:outopcode2 (op arg1 arg2 doc)
   (prog nil
      (cond ((not (flagp op 's!:preserves_a)) (setq s!:a_reg_values nil)))
      (cond ((null s!:current_label) (return nil)))
      (setq s!:current_block
         (cons arg2 (cons arg1 (cons op s!:current_block))))
      (setq s!:current_size (plus s!:current_size 3))
      (cond
         ((or !*plap !*pgwd)
            (setq s!:current_block (cons (cons op doc) s!:current_block)))) ))


(de s!:outopcode2lit (op arg1 arg2 doc env)
   (prog nil
      (cond ((not (flagp op 's!:preserves_a)) (setq s!:a_reg_values nil)))
      (cond ((null s!:current_label) (return nil)))
      (setq s!:current_block (cons arg1 (cons op s!:current_block)))
      (s!:record_literal env)
      (setq s!:current_block (cons arg2 s!:current_block))
      (setq s!:current_size (plus s!:current_size 3))
      (cond
         ((or !*plap !*pgwd)
            (setq s!:current_block (cons (cons op doc) s!:current_block)))) ))


(de s!:outlexref (op arg1 arg2 arg3 doc)
   (prog (arg4)
      (cond ((null s!:current_label) (return nil)))
      (cond
         ((or (greaterp arg1 255) (greaterp arg2 255) (greaterp arg3 255))
            (progn
               (cond
                  ((or
                      (greaterp arg1 2047)
                      (greaterp arg2 31)
                      (greaterp arg3 2047))
                     (error "stack frame > 2047 or > 31 deep nesting")))
               (setq doc (list op doc))
               (setq arg4 (logand arg3 255))
               (setq arg3
                  (plus (truncate arg3 256) (times 16 (logand arg1 15))))
               (cond
                  ((equal op 'loadlex) (setq op (plus 192 arg2)))
                  (t (setq op (plus 224 arg2))))
               (setq arg2 (truncate arg1 16))
               (setq arg1 op)
               (setq op 'bigstack)))
         (t (setq doc (list doc))))
      (setq s!:current_block
         (cons arg3 (cons arg2 (cons arg1 (cons op s!:current_block)))) )
      (setq s!:current_size (plus s!:current_size 4))
      (cond
         (arg4
            (progn
               (setq s!:current_block (cons arg4 s!:current_block))
               (setq s!:current_size (plus s!:current_size 1)))) )
      (cond
         ((or !*plap !*pgwd)
            (setq s!:current_block (cons (cons op doc) s!:current_block)))) ))


(put
   'loadlit
   's!:shortform
   (cons
      '(1 . 7)
      (s!:vecof
         '(!- loadlit1 loadlit2 loadlit3 loadlit4 loadlit5 loadlit6
             loadlit7))))


(put
   'loadfree
   's!:shortform
   (cons '(1 . 4) (s!:vecof '(!- loadfree1 loadfree2 loadfree3 loadfree4))))


(put
   'storefree
   's!:shortform
   (cons '(1 . 3) (s!:vecof '(!- storefree1 storefree2 storefree3))))


(put
   'call0
   's!:shortform
   (cons '(0 . 3) (s!:vecof '(call0_0 call0_1 call0_2 call0_3))))


(put
   'call1
   's!:shortform
   (cons
      '(0 . 5)
      (s!:vecof '(call1_0 call1_1 call1_2 call1_3 call1_4 call1_5))))


(put
   'call2
   's!:shortform
   (cons '(0 . 4) (s!:vecof '(call2_0 call2_1 call2_2 call2_3 call2_4))))


(put
   'jumpfreet
   's!:shortform
   (cons
      '(1 . 4)
      (s!:vecof '(!- jumpfree1t jumpfree2t jumpfree3t jumpfree4t))))


(put
   'jumpfreenil
   's!:shortform
   (cons
      '(1 . 4)
      (s!:vecof '(!- jumpfree1nil jumpfree2nil jumpfree3nil jumpfree4nil))))


(put
   'jumpliteq
   's!:shortform
   (cons
      '(1 . 4)
      (s!:vecof '(!- jumplit1eq jumplit2eq jumplit3eq jumplit4eq))))


(put
   'jumplitne
   's!:shortform
   (cons
      '(1 . 4)
      (s!:vecof '(!- jumplit1ne jumplit2ne jumplit3ne jumplit4ne))))


(put 'jumpliteq!* 's!:shortform (get 'jumpliteq 's!:shortform))


(put 'jumplitne!* 's!:shortform (get 'jumplitne 's!:shortform))


(put 'call0 's!:longform 0)


(put 'call1 's!:longform 16)


(put 'call2 's!:longform 32)


(put 'call3 's!:longform 48)


(put 'calln 's!:longform 64)


(put 'call2r 's!:longform 80)


(put 'loadfree 's!:longform 96)


(put 'storefree 's!:longform 112)


(put 'jcall0 's!:longform 128)


(put 'jcall1 's!:longform 144)


(put 'jcall2 's!:longform 160)


(put 'jcall3 's!:longform 176)


(put 'jcalln 's!:longform 192)


(put 'freebind 's!:longform 208)


(put 'litget 's!:longform 224)


(put 'loadlit 's!:longform 240)


(de s!:literal_order (a b)
   (cond
      ((equal (cadr a) (cadr b)) (orderp (car a) (car b)))
      (t (greaterp (cadr a) (cadr b)))) )


(de s!:resolve_literals (env)
   (prog (w op opspec n litbytes)
      (setq w (hashcontents (car env)))
      (setq w (sort w (function s!:literal_order)))
      (setq n (length w))
      (setq litbytes (times 4 n))
      (cond ((greaterp n 4096) (setq w (s!:too_many_literals w n))))
      (setq n 0)
      (prog (x)
         (setq x w)
   lab   (cond ((null x) (return nil)))
         ((lambda (x) (progn (rplaca (cdr x) n) (setq n (plus n 1)))) (car x))
         (setq x (cdr x))
         (go lab))
      (prog (x)
         (setq x w)
   lab   (cond ((null x) (return nil)))
         ((lambda (x)
             (progn
                (setq n (cadr x))
                (prog (y)
                   (setq y (cddr x))
             lab   (cond ((null y) (return nil)))
                   ((lambda (y)
                       (progn
                          (cond
                             ((null (car y))
                                (progn
                                   (setq op (caadr y))
                                   (setq opspec (get op 's!:shortform))
                                   (cond
                                      ((and
                                          opspec
                                          (leq (caar opspec) n)
                                          (leq n (cdar opspec)))
                                         (rplaca
                                            (cdr y)
                                            (getv (cdr opspec) n)))
                                      (t (rplaca (cdadr y) n)))) )
                             (t (progn
                                   (setq op (caddr y))
                                   (cond
                                      ((greaterp n 255)
                                         (progn
                                            (rplaca (car y) (plus (caar y) 1))
                                            (setq op
                                               (plus
                                                  (get op 's!:longform)
                                                  (truncate n 256)))
                                            (rplaca (cdr y) (ilogand n 255))
                                            (rplaca (cddr y) 'bigcall)
                                            (rplacd
                                               (cdr y)
                                               (cons op (cddr y)))) )
                                      ((and
                                          (setq opspec (get op 's!:shortform))
                                          (leq (caar opspec) n)
                                          (leq n (cdar opspec)))
                                         (progn
                                            (rplaca
                                               (car y)
                                               (difference (caar y) 1))
                                            (rplaca
                                               (cdr y)
                                               (getv (cdr opspec) n))
                                            (rplacd (cdr y) (cdddr y))))
                                      (t (rplaca (cdr y) n)))) ))) )
                      (car y))
                   (setq y (cdr y))
                   (go lab))))
            (car x))
         (setq x (cdr x))
         (go lab))
      (prog (x)
         (setq x w)
   lab   (cond ((null x) (return nil)))
         ((lambda (x) (rplacd x (cadr x))) (car x))
         (setq x (cdr x))
         (go lab))
      (rplaca env (cons (reversip w) litbytes))))


(de s!:only_loadlit (l)
   (cond
      ((null l) t)
      ((null (caar l)) nil)
      ((not (eqcar (cddar l) 'loadlit)) nil)
      (t (s!:only_loadlit (cdr l)))) )


(de s!:too_many_literals (w n)
   (prog (k xvecs l r newrefs uses z1)
      (setq k 0)
      (setq n (plus n 1))
      (prog nil
   !G5   (cond ((not (and (greaterp n 4096) (not (null w)))) (return nil)))
         (progn
            (cond
               ((and
                   (not (equal (cadar w) 10000000))
                   (s!:only_loadlit (cddar w)))
                  (progn
                     (setq l (cons (car w) l))
                     (setq n (difference n 1))
                     (setq k (plus k 1))
                     (cond
                        ((equal k 256)
                           (progn
                              (setq xvecs (cons l xvecs))
                              (setq l nil)
                              (setq k 0)
                              (setq n (plus n 1)))) )))
               (t (setq r (cons (car w) r))))
            (setq w (cdr w)))
         (go !G5))
      (cond ((greaterp n 4096) (error "function uses too many literals")))
      (setq xvecs (cons l xvecs))
      (prog nil
   !G6   (cond ((not r) (return nil)))
         (progn (setq w (cons (car r) w)) (setq r (cdr r)))
         (go !G6))
      (prog (v)
         (setq v xvecs)
   lab   (cond ((null v) (return nil)))
         ((lambda (v)
             (progn (setq newrefs nil) (setq uses 0) (setq r nil) (setq k 0)
                (prog (q)
                   (setq q v)
             lab   (cond ((null q) (return nil)))
                   ((lambda (q)
                       (progn
                          (prog (z)
                             (setq z (cddr q))
                       lab   (cond ((null z) (return nil)))
                             ((lambda (z)
                                 (progn
                                    (cond
                                       ((car z)
                                          (rplaca (car z) (plus (caar z) 2))))
                                    (setq z1
                                       (cons 'qgetvn (cons nil (cddr z))))
                                    (rplaca (cdr z) k)
                                    (rplacd (cdr z) z1)
                                    (rplacd z (cdr z1))
                                    (setq newrefs (cons z newrefs))
                                    (setq uses (plus uses 11))))
                                (car z))
                             (setq z (cdr z))
                             (go lab))
                          (setq r (cons (car q) r))
                          (setq k (plus k 1))))
                      (car q))
                   (setq q (cdr q))
                   (go lab))
                (setq newrefs (cons uses newrefs))
                (setq newrefs (cons (s!:vecof (reversip r)) newrefs))
                (setq w (cons newrefs w))))
            (car v))
         (setq v (cdr v))
         (go lab))
      (return (sort w (function s!:literal_order)))) )


(fluid '(s!:into_c))


(de s!:endprocedure (name env)
   (prog (pc labelvals w vec)
      (s!:outexit)
      (cond (s!:into_c (return (cons s!:current_procedure env))))
      (s!:resolve_literals env)
      (setq s!:current_procedure (s!:tidy_flowgraph s!:current_procedure))
      (cond
         ((and (not !*notailcall) (not s!:has_closure))
            (setq s!:current_procedure
               (s!:try_tailcall s!:current_procedure))))
      (setq s!:current_procedure (s!:tidy_exits s!:current_procedure))
      (setq labelvals (s!:resolve_labels))
      (setq pc (car labelvals))
      (setq labelvals (cdr labelvals))
      (setq vec (make!-bps pc))
      (setq pc 0)
      (cond
         ((or !*plap !*pgwd)
            (progn (terpri) (ttab 23) (princ "+++ ") (prin name)
               (princ " +++") (terpri))))
      (prog (b)
         (setq b s!:current_procedure)
   lab   (cond ((null b) (return nil)))
         ((lambda (b)
             (progn
                (cond
                   ((and
                       (car b)
                       (flagp (car b) 'used_label)
                       (or !*plap !*pgwd))
                      (progn (ttab 20) (prin (car b)) (princ ":") (terpri))))
                (setq pc (s!:plant_basic_block vec pc (reverse (cdddr b))))
                (setq b (cadr b))
                (cond
                   ((and b (not (equal (car b) 'icase)) (cdr b) (cddr b))
                      (setq b (list (car b) (cadr b)))) )
                (setq pc (s!:plant_exit_code vec pc b labelvals))))
            (car b))
         (setq b (cdr b))
         (go lab))
      (cond
         (!*pwrds
            (progn
               (cond ((neq (posn) 0) (terpri)))
               (princ "+++ ")
               (prin name)
               (princ " compiled, ")
               (princ pc)
               (princ " + ")
               (princ (cdar env))
               (princ " bytes")
               (terpri))))
      (setq env (caar env))
      (cond
         ((null env) (setq w nil))
         (t (progn
               (setq w (mkvect (cdar env)))
               (prog nil
            !G7   (cond ((not env) (return nil)))
                  (progn (putv w (cdar env) (caar env)) (setq env (cdr env)))
                  (go !G7)))) )
      (return (cons vec w))))


(de s!:add_pending (lab pend blocks)
   (prog (w)
      (cond ((not (atom lab)) (return (cons (list (gensym) lab 0) pend))))
      (setq w (atsoc lab pend))
      (cond
         (w (return (cons w (deleq w pend))))
         (t (return (cons (atsoc lab blocks) pend)))) ))


(de s!:invent_exit (x blocks)
   (prog (w)
      (setq w blocks)
scan  (cond
         ((null w) (go not_found))
         ((and (eqcar (cadar w) x) (equal (caddar w) 0))
            (return (cons (caar w) blocks)))
         (t (setq w (cdr w))))
      (go scan)
not_found
      (setq w (gensym))
      (return (cons w (cons (list w (list x) 0) blocks)))) )


(de s!:destination_label (lab blocks)
   (prog (n w x)
      (setq w (atsoc lab blocks))
      (cond ((s!:is_lose_and_exit w blocks) (return '(exit))))
      (setq x (cadr w))
      (setq n (caddr w))
      (setq w (cdddr w))
      (cond ((neq n 0) (return lab)))
      (cond
         ((or (null x) (null (cdr x))) (return x))
         ((equal (cadr x) lab) (return lab))
         ((null (cddr x)) (return (s!:destination_label (cadr x) blocks)))
         (t (return lab)))) )


(de s!:remlose (b)
   (prog (w)
      (setq w b)
      (prog nil
   !G8   (cond ((not (and w (not (atom (car w)))) ) (return nil)))
         (setq w (cdr w))
         (go !G8))
      (cond ((null w) (return (cons 0 b))))
      (cond
         ((and (numberp (car w)) (eqcar (cdr w) 'loses))
            (setq w (cons 2 (cddr w))))
         ((or
             (equal (car w) 'lose)
             (equal (car w) 'lose2)
             (equal (car w) 'lose3))
            (setq w (cons 1 (cdr w))))
         (t (return (cons 0 b))))
      (setq b (s!:remlose (cdr w)))
      (return (cons (plus (car w) (car b)) (cdr b)))) )


(put 'call0_0 's!:shortcall '(0 . 0))


(put 'call0_1 's!:shortcall '(0 . 1))


(put 'call0_2 's!:shortcall '(0 . 2))


(put 'call0_3 's!:shortcall '(0 . 3))


(put 'call1_0 's!:shortcall '(1 . 0))


(put 'call1_1 's!:shortcall '(1 . 1))


(put 'call1_2 's!:shortcall '(1 . 2))


(put 'call1_3 's!:shortcall '(1 . 3))


(put 'call1_4 's!:shortcall '(1 . 4))


(put 'call1_5 's!:shortcall '(1 . 5))


(put 'call2_0 's!:shortcall '(2 . 0))


(put 'call2_1 's!:shortcall '(2 . 1))


(put 'call2_2 's!:shortcall '(2 . 2))


(put 'call2_3 's!:shortcall '(2 . 3))


(put 'call2_4 's!:shortcall '(2 . 4))


(de s!:remcall (b)
   (prog (w p q r s)
      (prog nil
   !G9   (cond ((not (and b (not (atom (car b)))) ) (return nil)))
         (progn (setq p (car b)) (setq b (cdr b)))
         (go !G9))
      (cond
         ((null b) (return nil))
         ((numberp (car b))
            (progn
               (setq r (car b))
               (setq s 2)
               (setq b (cdr b))
               (cond
                  ((null b) (return nil))
                  ((numberp (car b))
                     (progn
                        (setq q r)
                        (setq r (car b))
                        (setq s 3)
                        (setq b (cdr b))
                        (cond
                           ((and
                               b
                               (numberp (setq w (car b)))
                               (eqcar (cdr b) 'bigcall)
                               (equal (truncate w 16) 4))
                              (progn
                                 (setq r (plus (times 256 (logand w 15)) r))
                                 (setq s 4)
                                 (setq b (cdr b))))
                           ((eqcar b 'bigcall)
                              (progn
                                 (setq w (truncate r 16))
                                 (setq r (plus (times 256 (logand r 15)) q))
                                 (setq q w)
                                 (cond ((geq q 4) (return nil)))) )
                           ((not (eqcar b 'calln)) (return nil)))) )
                  ((equal (car b) 'call0) (setq q 0))
                  ((equal (car b) 'call1) (setq q 1))
                  ((equal (car b) 'call2) (setq q 2))
                  ((equal (car b) 'call3) (setq q 3))
                  (t (return nil)))
               (setq b (cdr b))))
         ((setq q (get (car b) 's!:shortcall))
            (progn
               (setq r (cdr q))
               (setq q (car q))
               (setq s 1)
               (setq b (cdr b))))
         (t (return nil)))
      (return (cons p (cons q (cons r (cons s b)))) )))


(de s!:is_lose_and_exit (b blocks)
   (prog (lab exit)
      (setq lab (car b))
      (setq exit (cadr b))
      (setq b (cdddr b))
      (cond ((null exit) (return nil)))
      (setq b (s!:remlose b))
      (setq b (cdr b))
      (prog nil
   !G10  (cond ((not (and b (not (atom (car b)))) ) (return nil)))
         (setq b (cdr b))
         (go !G10))
      (cond
         (b (return nil))
         ((equal (car exit) 'exit) (return t))
         ((equal (car exit) 'jump)
            (progn
               (cond
                  ((equal (cadr exit) lab) nil)
                  (t (return
                        (s!:is_lose_and_exit
                           (atsoc (cadr exit) blocks)
                           blocks)))) ))
         (t (return nil)))) )


(de s!:try_tail_1 (b blocks)
   (prog (exit size body w w0 w1 w2 op)
      (setq exit (cadr b))
      (cond
         ((null exit) (return b))
         ((not (equal (car exit) 'exit))
            (progn
               (cond
                  ((equal (car exit) 'jump)
                     (progn
                        (cond
                           ((not
                               (s!:is_lose_and_exit
                                  (atsoc (cadr exit) blocks)
                                  blocks))
                              (return b)))) )
                  (t (return b)))) ))
      (setq size (caddr b))
      (setq body (cdddr b))
      (setq body (s!:remlose body))
      (setq size (difference size (car body)))
      (setq body (cdr body))
      (setq w (s!:remcall body))
      (cond ((null w) (return b)))
      (setq w0 (cadr w))
      (setq w1 (caddr w))
      (setq body (cddddr w))
      (cond
         ((and (leq w0 7) (leq w1 31))
            (progn
               (setq body (cons 'jcall body))
               (setq body (cons (plus (times 32 w0) w1) body))
               (setq size (difference size 1))))
         ((lessp w1 256) (setq body (cons w0 (cons w1 (cons 'jcalln body)))) )
         (t (progn
               (setq body (cons 'bigcall body))
               (setq w2 (logand w1 255))
               (setq w1 (truncate w1 256))
               (cond
                  ((lessp w0 4)
                     (setq body
                        (cons w2 (cons (plus w1 (times 16 w0) 128) body))))
                  (t (progn
                        (setq body
                           (cons
                              w0
                              (cons
                                 w2
                                 (cons (plus w1 (times 16 4) 128) body))))
                        (setq size (plus size 1)))) ))) )
      (cond ((car w) (setq body (cons (append (car w) (list 'tail)) body))))
      (rplaca (cdr b) nil)
      (rplaca (cddr b) (plus (difference size (cadddr w)) 3))
      (rplacd (cddr b) body)
      (return b)))


(de s!:try_tailcall (b)
   (prog (v !G11 endptr)
      (setq v b)
      (cond ((null v) (return nil)))
      (setq !G11
         (setq endptr (cons ((lambda (v) (s!:try_tail_1 v b)) (car v)) nil)))
looplabel
      (setq v (cdr v))
      (cond ((null v) (return !G11)))
      (rplacd endptr (cons ((lambda (v) (s!:try_tail_1 v b)) (car v)) nil))
      (setq endptr (cdr endptr))
      (go looplabel)))


(de s!:tidy_exits_1 (b blocks)
   (prog (exit size body comm w w0 w1 w2 op)
      (setq exit (cadr b))
      (cond
         ((null exit) (return b))
         ((not (equal (car exit) 'exit))
            (progn
               (cond
                  ((equal (car exit) 'jump)
                     (progn
                        (cond
                           ((not
                               (s!:is_lose_and_exit
                                  (atsoc (cadr exit) blocks)
                                  blocks))
                              (return b)))) )
                  (t (return b)))) ))
      (setq size (caddr b))
      (setq body (cdddr b))
      (setq body (s!:remlose body))
      (setq size (difference size (car body)))
      (setq body (cdr body))
      (prog nil
   !G12  (cond ((not (and body (not (atom (car body)))) ) (return nil)))
         (progn (setq comm (car body)) (setq body (cdr body)))
         (go !G12))
      (cond
         ((eqcar body 'vnil) (setq w 'nilexit))
         ((eqcar body 'loadloc0) (setq w 'loc0exit))
         ((eqcar body 'loadloc1) (setq w 'loc1exit))
         ((eqcar body 'loadloc2) (setq w 'loc2exit))
         (t (setq w nil)))
      (cond
         (w
            (progn
               (rplaca (cdr b) (list w))
               (setq body (cdr body))
               (setq size (difference size 1))))
         (comm (setq body (cons comm body))))
      (rplaca (cddr b) size)
      (rplacd (cddr b) body)
      (return b)))


(de s!:tidy_exits (b)
   (prog (v !G13 endptr)
      (setq v b)
      (cond ((null v) (return nil)))
      (setq !G13
         (setq endptr
            (cons ((lambda (v) (s!:tidy_exits_1 v b)) (car v)) nil)))
looplabel
      (setq v (cdr v))
      (cond ((null v) (return !G13)))
      (rplacd endptr (cons ((lambda (v) (s!:tidy_exits_1 v b)) (car v)) nil))
      (setq endptr (cdr endptr))
      (go looplabel)))


(de s!:tidy_flowgraph (b)
   (prog (r pending)
      (setq b (reverse b))
      (setq pending (list (car b)))
      (prog nil
   !G14  (cond ((not pending) (return nil)))
         (prog (c x l1 l2 done1 done2)
            (setq c (car pending))
            (setq pending (cdr pending))
            (flag (list (car c)) 'coded)
            (setq x (cadr c))
            (cond
               ((or (null x) (null (cdr x))) (setq r (cons c r)))
               ((equal (car x) 'icase)
                  (progn
                     (rplacd x (reversip (cdr x)))
                     (prog (ll)
                        (setq ll (cdr x))
                  lab   (cond ((null ll) (return nil)))
                        (progn
                           (setq l1 (s!:destination_label (car ll) b))
                           (cond
                              ((not (atom l1))
                                 (progn
                                    (setq l1 (s!:invent_exit (car l1) b))
                                    (setq b (cdr l1))
                                    (setq l1 (cadr l1)))) )
                           (rplaca ll l1)
                           (setq done1 (flagp l1 'coded))
                           (flag (list l1) 'used_label)
                           (cond
                              ((not done1)
                                 (setq pending
                                    (s!:add_pending l1 pending b)))) )
                        (setq ll (cdr ll))
                        (go lab))
                     (rplacd x (reversip (cdr x)))
                     (setq r (cons c r))))
               ((null (cddr x))
                  (progn
                     (setq l1 (s!:destination_label (cadr x) b))
                     (cond
                        ((not (atom l1))
                           (setq c (cons (car c) (cons l1 (cddr c)))) )
                        ((flagp l1 'coded)
                           (progn
                              (flag (list l1) 'used_label)
                              (setq c
                                 (cons
                                    (car c)
                                    (cons (list (car x) l1) (cddr c)))) ))
                        (t (progn
                              (setq c (cons (car c) (cons nil (cddr c))))
                              (setq pending (s!:add_pending l1 pending b)))) )
                     (setq r (cons c r))))
               (t (progn
                     (setq l1 (s!:destination_label (cadr x) b))
                     (setq l2 (s!:destination_label (caddr x) b))
                     (setq done1 (and (atom l1) (flagp l1 'coded)))
                     (setq done2 (and (atom l2) (flagp l2 'coded)))
                     (cond
                        (done1
                           (progn
                              (cond
                                 (done2
                                    (progn
                                       (flag (list l1) 'used_label)
                                       (rplaca (cdadr c) l1)
                                       (setq pending
                                          (cons
                                             (list (gensym) (list 'jump l2) 0)
                                             pending))))
                                 (t (progn
                                       (flag (list l1) 'used_label)
                                       (rplaca (cdadr c) l1)
                                       (setq pending
                                          (s!:add_pending l2 pending b)))) )))
                        (t (progn
                              (cond
                                 (done2
                                    (progn
                                       (flag (list l2) 'used_label)
                                       (rplaca
                                          (cadr c)
                                          (s!:negate_jump (car x)))
                                       (rplaca (cdadr c) l2)
                                       (setq pending
                                          (s!:add_pending l1 pending b))))
                                 (t (progn
                                       (cond
                                          ((not (atom l1))
                                             (progn
                                                (setq l1
                                                   (s!:invent_exit
                                                      (car l1)
                                                      b))
                                                (setq b (cdr l1))
                                                (setq l1 (car l1)))) )
                                       (flag (list l1) 'used_label)
                                       (rplaca (cdadr c) l1)
                                       (cond
                                          ((not (flagp l1 'coded))
                                             (setq pending
                                                (s!:add_pending
                                                   l1
                                                   pending
                                                   b))))
                                       (setq pending
                                          (s!:add_pending
                                             l2
                                             pending
                                             b)))) ))) )
                     (setq r (cons c r)))) ))
         (go !G14))
      (return (reverse r))))


(deflist
   '((jumpnil jumpt)
       (jumpt jumpnil)
       (jumpatom jumpnatom)
       (jumpnatom jumpatom)
       (jumpeq jumpne)
       (jumpne jumpeq)
       (jumpequal jumpnequal)
       (jumpnequal jumpequal)
       (jumpl0nil jumpl0t)
       (jumpl0t jumpl0nil)
       (jumpl1nil jumpl1t)
       (jumpl1t jumpl1nil)
       (jumpl2nil jumpl2t)
       (jumpl2t jumpl2nil)
       (jumpl3nil jumpl3t)
       (jumpl3t jumpl3nil)
       (jumpl4nil jumpl4t)
       (jumpl4t jumpl4nil)
       (jumpl0atom jumpl0natom)
       (jumpl0natom jumpl0atom)
       (jumpl1atom jumpl1natom)
       (jumpl1natom jumpl1atom)
       (jumpl2atom jumpl2natom)
       (jumpl2natom jumpl2atom)
       (jumpl3atom jumpl3natom)
       (jumpl3natom jumpl3atom)
       (jumpst0nil jumpst0t)
       (jumpst0t jumpst0nil)
       (jumpst1nil jumpst1t)
       (jumpst1t jumpst1nil)
       (jumpst2nil jumpst2t)
       (jumpst2t jumpst2nil)
       (jumpfree1nil jumpfree1t)
       (jumpfree1t jumpfree1nil)
       (jumpfree2nil jumpfree2t)
       (jumpfree2t jumpfree2nil)
       (jumpfree3nil jumpfree3t)
       (jumpfree3t jumpfree3nil)
       (jumpfree4nil jumpfree4t)
       (jumpfree4t jumpfree4nil)
       (jumpfreenil jumpfreet)
       (jumpfreet jumpfreenil)
       (jumplit1eq jumplit1ne)
       (jumplit1ne jumplit1eq)
       (jumplit2eq jumplit2ne)
       (jumplit2ne jumplit2eq)
       (jumplit3eq jumplit3ne)
       (jumplit3ne jumplit3eq)
       (jumplit4eq jumplit4ne)
       (jumplit4ne jumplit4eq)
       (jumpliteq jumplitne)
       (jumplitne jumpliteq)
       (jumpliteq!* jumplitne!*)
       (jumplitne!* jumpliteq!*)
       (jumpb1nil jumpb1t)
       (jumpb1t jumpb1nil)
       (jumpb2nil jumpb2t)
       (jumpb2t jumpb2nil)
       (jumpflagp jumpnflagp)
       (jumpnflagp jumpflagp)
       (jumpeqcar jumpneqcar)
       (jumpneqcar jumpeqcar))
   'negjump)


(de s!:negate_jump (x)
   (cond ((atom x) (get x 'negjump)) (t (rplaca x (get (car x) 'negjump)))) )


(de s!:resolve_labels nil
   (prog (w labelvals converged pc x)
      (prog nil
   !G15  (progn
            (setq converged t)
            (setq pc 0)
            (prog (b)
               (setq b s!:current_procedure)
         lab   (cond ((null b) (return nil)))
               ((lambda (b)
                   (progn
                      (setq w (assoc!*!* (car b) labelvals))
                      (cond
                         ((null w)
                            (progn
                               (setq converged nil)
                               (setq w (cons (car b) pc))
                               (setq labelvals (cons w labelvals))))
                         ((neq (cdr w) pc)
                            (progn (rplacd w pc) (setq converged nil))))
                      (setq pc (plus pc (caddr b)))
                      (setq x (cadr b))
                      (cond
                         ((null x) nil)
                         ((null (cdr x)) (setq pc (plus pc 1)))
                         ((equal (car x) 'icase)
                            (setq pc (plus pc (times 2 (length x)))) )
                         (t (progn
                               (setq w (assoc!*!* (cadr x) labelvals))
                               (cond
                                  ((null w)
                                     (progn
                                        (setq w 128)
                                        (setq converged nil)))
                                  (t (setq w (difference (cdr w) pc))))
                               (setq w (s!:expand_jump (car x) w))
                               (setq pc (plus pc (length w)))) ))) )
                  (car b))
               (setq b (cdr b))
               (go lab)))
         (cond ((not converged) (go !G15))))
      (return (cons pc labelvals))))


(de s!:plant_basic_block (vec pc b)
   (prog (tagged)
      (prog (i)
         (setq i b)
   lab   (cond ((null i) (return nil)))
         ((lambda (i)
             (progn
                (cond
                   ((atom i)
                      (progn
                         (cond ((symbolp i) (setq i (get i 's!:opcode))))
                         (cond
                            ((and (not tagged) (or !*plap !*pgwd))
                               (progn
                                  (s!:prinhex4 pc)
                                  (princ ":")
                                  (ttab 8)
                                  (setq tagged t))))
                         (cond
                            ((or (not (fixp i)) (lessp i 0) (greaterp i 255))
                               (error "bad byte to put" i)))
                         (bps!-putv vec pc i)
                         (cond
                            ((or !*plap !*pgwd)
                               (progn (s!:prinhex2 i) (princ " "))))
                         (setq pc (plus pc 1))))
                   ((or !*plap !*pgwd)
                      (progn
                         (ttab 23)
                         (princ (car i))
                         (prog (w)
                            (setq w (cdr i))
                      lab   (cond ((null w) (return nil)))
                            ((lambda (w) (progn (princ " ") (prin w)))
                               (car w))
                            (setq w (cdr w))
                            (go lab))
                         (terpri)
                         (setq tagged nil)))) ))
            (car i))
         (setq i (cdr i))
         (go lab))
      (return pc)))


(de s!:plant_bytes (vec pc bytelist doc)
   (prog nil
      (cond
         ((or !*plap !*pgwd) (progn (s!:prinhex4 pc) (princ ":") (ttab 8))))
      (prog (v)
         (setq v bytelist)
   lab   (cond ((null v) (return nil)))
         ((lambda (v)
             (progn
                (cond ((symbolp v) (setq v (get v 's!:opcode))))
                (cond
                   ((or (not (fixp v)) (lessp v 0) (greaterp v 255))
                      (error "bad byte to put" v)))
                (bps!-putv vec pc v)
                (cond
                   ((or !*plap !*pgwd)
                      (progn
                         (cond
                            ((greaterp (posn) 50) (progn (terpri) (ttab 8))))
                         (s!:prinhex2 v)
                         (princ " "))))
                (setq pc (plus pc 1))))
            (car v))
         (setq v (cdr v))
         (go lab))
      (cond
         ((or !*plap !*pgwd)
            (progn
               (cond ((greaterp (posn) 23) (terpri)))
               (ttab 23)
               (princ (car doc))
               (prog (w)
                  (setq w (cdr doc))
            lab   (cond ((null w) (return nil)))
                  ((lambda (w)
                      (progn
                         (cond
                            ((greaterp (posn) 65) (progn (terpri) (ttab 23))))
                         (princ " ")
                         (prin w)))
                     (car w))
                  (setq w (cdr w))
                  (go lab))
               (terpri))))
      (return pc)))


(de s!:plant_exit_code (vec pc b labelvals)
   (prog (w loc low high r)
      (cond
         ((null b) (return pc))
         ((null (cdr b))
            (return
               (s!:plant_bytes vec pc (list (get (car b) 's!:opcode)) b)))
         ((equal (car b) 'icase)
            (progn
               (setq loc (plus pc 3))
               (prog (ll)
                  (setq ll (cdr b))
            lab   (cond ((null ll) (return nil)))
                  ((lambda (ll)
                      (progn
                         (setq w
                            (difference (cdr (assoc!*!* ll labelvals)) loc))
                         (setq loc (plus loc 2))
                         (cond
                            ((lessp w 0)
                               (progn
                                  (setq w (minus w))
                                  (setq low (ilogand w 255))
                                  (setq high
                                     (plus
                                        128
                                        (truncate (difference w low) 256)))) )
                            (t (progn
                                  (setq low (ilogand w 255))
                                  (setq high
                                     (truncate (difference w low) 256)))) )
                         (setq r (cons low (cons high r)))) )
                     (car ll))
                  (setq ll (cdr ll))
                  (go lab))
               (setq r
                  (cons
                     (get 'icase 's!:opcode)
                     (cons (length (cddr b)) (reversip r))))
               (return (s!:plant_bytes vec pc r b)))) )
      (setq w (difference (cdr (assoc!*!* (cadr b) labelvals)) pc))
      (setq w (s!:expand_jump (car b) w))
      (return (s!:plant_bytes vec pc w b))))


(deflist
   '((jumpl0nil ((loadloc0) jumpnil))
       (jumpl0t ((loadloc0) jumpt))
       (jumpl1nil ((loadloc1) jumpnil))
       (jumpl1t ((loadloc1) jumpt))
       (jumpl2nil ((loadloc2) jumpnil))
       (jumpl2t ((loadloc2) jumpt))
       (jumpl3nil ((loadloc3) jumpnil))
       (jumpl3t ((loadloc3) jumpt))
       (jumpl4nil ((loadloc4) jumpnil))
       (jumpl4t ((loadloc4) jumpt))
       (jumpl0atom ((loadloc0) jumpatom))
       (jumpl0natom ((loadloc0) jumpnatom))
       (jumpl1atom ((loadloc1) jumpatom))
       (jumpl1natom ((loadloc1) jumpnatom))
       (jumpl2atom ((loadloc2) jumpatom))
       (jumpl2natom ((loadloc2) jumpnatom))
       (jumpl3atom ((loadloc3) jumpatom))
       (jumpl3natom ((loadloc3) jumpnatom))
       (jumpst0nil ((storeloc0) jumpnil))
       (jumpst0t ((storeloc0) jumpt))
       (jumpst1nil ((storeloc1) jumpnil))
       (jumpst1t ((storeloc1) jumpt))
       (jumpst2nil ((storeloc2) jumpnil))
       (jumpst2t ((storeloc2) jumpt))
       (jumpfree1nil ((loadfree1) jumpnil))
       (jumpfree1t ((loadfree1) jumpt))
       (jumpfree2nil ((loadfree2) jumpnil))
       (jumpfree2t ((loadfree2) jumpt))
       (jumpfree3nil ((loadfree3) jumpnil))
       (jumpfree3t ((loadfree3) jumpt))
       (jumpfree4nil ((loadfree4) jumpnil))
       (jumpfree4t ((loadfree4) jumpt))
       (jumpfreenil ((loadfree !*) jumpnil))
       (jumpfreet ((loadfree !*) jumpt))
       (jumplit1eq ((loadlit1) jumpeq))
       (jumplit1ne ((loadlit1) jumpne))
       (jumplit2eq ((loadlit2) jumpeq))
       (jumplit2ne ((loadlit2) jumpne))
       (jumplit3eq ((loadlit3) jumpeq))
       (jumplit3ne ((loadlit3) jumpne))
       (jumplit4eq ((loadlit4) jumpeq))
       (jumplit4ne ((loadlit4) jumpne))
       (jumpliteq ((loadlit !*) jumpeq))
       (jumplitne ((loadlit !*) jumpne))
       (jumpliteq!* ((loadlit !* swop) jumpeq))
       (jumplitne!* ((loadlit !* swop) jumpne))
       (jumpb1nil ((builtin1 !*) jumpnil))
       (jumpb1t ((builtin1 !*) jumpt))
       (jumpb2nil ((builtin2 !*) jumpnil))
       (jumpb2t ((builtin2 !*) jumpt))
       (jumpflagp ((loadlit !* flagp) jumpt))
       (jumpnflagp ((loadlit !* flagp) jumpnil))
       (jumpeqcar ((loadlit !* eqcar) jumpt))
       (jumpneqcar ((loadlit !* eqcar) jumpnil)))
   's!:expand_jump)


(de s!:expand_jump (op offset)
   (prog (arg low high opcode expanded)
      (cond
         ((not (atom op))
            (progn
               (setq arg (cadr op))
               (setq op (car op))
               (setq offset (difference offset 1)))) )
      (setq expanded (get op 's!:expand_jump))
      (cond
         ((and
             expanded
             (not
                (and
                   (leq 2 offset)
                   (lessp offset (plus 256 2))
                   (or (null arg) (lessp arg 256)))) )
            (progn
               (setq op (cadr expanded))
               (setq expanded (car expanded))
               (cond
                  (arg
                     (progn
                        (cond
                           ((greaterp arg 2047)
                              (error "function uses too many literals"))
                           ((greaterp arg 255)
                              (prog (high low)
                                 (setq low (ilogand expanded 255))
                                 (setq high
                                    (truncate (difference expanded low) 256))
                                 (setq expanded
                                    (plus
                                       (cons
                                          'bigcall
                                          (get (car expanded) 's!:longform))
                                       (cons
                                          high
                                          (cons low (cddr expanded)))) )))
                           (t (setq expanded (subst arg '!* expanded))))
                        (setq offset (plus offset 1)))) )
               (setq offset (difference offset (length expanded)))
               (setq arg nil)))
         (t (setq expanded nil)))
      (setq opcode (get op 's!:opcode))
      (cond ((null opcode) (error 0 (list op offset "invalid block exit"))))
      (cond
         ((and
             (lessp (plus (minus 256) 2) offset)
             (lessp offset (plus 256 2)))
            (setq offset (difference offset 2)))
         (t (progn (setq high t) (setq offset (difference offset 3)))) )
      (cond
         ((lessp offset 0)
            (progn
               (setq opcode (plus opcode 1))
               (setq offset (minus offset)))) )
      (cond
         (high
            (progn
               (setq low (logand offset 255))
               (setq high (truncate (difference offset low) 256))))
         ((greaterp (setq low offset) 255)
            (error 0 "Bad offset in expand_jump")))
      (cond
         (arg (return (list opcode arg low)))
         ((not high) (return (append expanded (list opcode low))))
         (t (return (append expanded (list (plus opcode 2) high low)))) )))


(de s!:comval (x env context)
   (prog (helper)
      (setq x (s!:improve x))
      (cond
         ((atom x) (return (s!:comatom x env context)))
         ((eqcar (car x) 'lambda)
            (return (s!:comlambda (cadar x) (cddar x) (cdr x) env context)))
         ((eq (car x) s!:current_function) (s!:comcall x env context))
         ((and
             (setq helper (get (car x) 's!:compilermacro))
             (setq helper (funcall helper x env context)))
            (return (s!:comval helper env context)))
         ((setq helper (get (car x) 's!:newname))
            (return (s!:comval (cons helper (cdr x)) env context)))
         ((setq helper (get (car x) 's!:compfn))
            (return (funcall helper x env context)))
         ((setq helper (macro!-function (car x)))
            (return (s!:comval (funcall helper x) env context)))
         (t (return (s!:comcall x env context)))) ))


(de s!:comspecform (x env context) (error 0 (list "special form" x)))


(cond
   ((null (get 'and 's!:compfn))
      (progn
         (put 'compiler!-let 's!:compfn (function s!:comspecform))
         (put 'de 's!:compfn (function s!:comspecform))
         (put 'defun 's!:compfn (function s!:comspecform))
         (put 'eval!-when 's!:compfn (function s!:comspecform))
         (put 'flet 's!:compfn (function s!:comspecform))
         (put 'labels 's!:compfn (function s!:comspecform))
         (put 'macrolet 's!:compfn (function s!:comspecform))
         (put 'multiple!-value!-call 's!:compfn (function s!:comspecform))
         (put 'multiple!-value!-prog1 's!:compfn (function s!:comspecform))
         (put 'prog!* 's!:compfn (function s!:comspecform))
         (put 'progv 's!:compfn (function s!:comspecform))
         nil)))


(de s!:improve (u)
   (prog (w)
      (cond
         ((atom u) (return u))
         ((setq w (get (car u) 's!:tidy_fn)) (return (funcall w u)))
         ((setq w (get (car u) 's!:newname))
            (return (s!:improve (cons w (cdr u)))) )
         (t (return u)))) )


(de s!:imp_minus (u)
   (prog (a)
      (setq a (s!:improve (cadr u)))
      (return
         (cond
            ((numberp a) (minus a))
            ((or (eqcar a 'minus) (eqcar a 'iminus)) (cadr a))
            ((eqcar a 'difference)
               (s!:improve (list 'difference (caddr a) (cadr a))))
            ((eqcar a 'idifference)
               (s!:improve (list 'idifference (caddr a) (cadr a))))
            (t (list (car u) a)))) ))


(put 'minus 's!:tidy_fn 's!:imp_minus)


(put 'iminus 's!:tidy_fn 's!:imp_minus)


(de s!:imp_times (u)
   (prog (a b)
      (cond
         ((not (equal (length u) 3))
            (return
               (cons
                  (car u)
                  (prog (v !G16 endptr)
                     (setq v (cdr u))
                     (cond ((null v) (return nil)))
                     (setq !G16
                        (setq endptr
                           (cons ((lambda (v) (s!:improve v)) (car v)) nil)))
               looplabel
                     (setq v (cdr v))
                     (cond ((null v) (return !G16)))
                     (rplacd
                        endptr
                        (cons ((lambda (v) (s!:improve v)) (car v)) nil))
                     (setq endptr (cdr endptr))
                     (go looplabel)))) ))
      (setq a (s!:improve (cadr u)))
      (setq b (s!:improve (caddr u)))
      (return
         (cond
            ((equal a 1) b)
            ((equal b 1) a)
            ((equal a (minus 1)) (s!:imp_minus (list 'minus b)))
            ((equal b (minus 1)) (s!:imp_minus (list 'minus a)))
            (t (list (car u) a b)))) ))


(put 'times 's!:tidy_fn 's!:imp_times)


(de s!:imp_itimes (u)
   (prog (a b)
      (cond
         ((not (equal (length u) 3))
            (return
               (cons
                  (car u)
                  (prog (v !G17 endptr)
                     (setq v (cdr u))
                     (cond ((null v) (return nil)))
                     (setq !G17
                        (setq endptr
                           (cons ((lambda (v) (s!:improve v)) (car v)) nil)))
               looplabel
                     (setq v (cdr v))
                     (cond ((null v) (return !G17)))
                     (rplacd
                        endptr
                        (cons ((lambda (v) (s!:improve v)) (car v)) nil))
                     (setq endptr (cdr endptr))
                     (go looplabel)))) ))
      (setq a (s!:improve (cadr u)))
      (setq b (s!:improve (caddr u)))
      (return
         (cond
            ((equal a 1) b)
            ((equal b 1) a)
            ((equal a (minus 1)) (s!:imp_minus (list 'iminus b)))
            ((equal b (minus 1)) (s!:imp_minus (list 'iminus a)))
            (t (list (car u) a b)))) ))


(put 'itimes 's!:tidy_fn 's!:imp_itimes)


(de s!:imp_difference (u)
   (prog (a b)
      (setq a (s!:improve (cadr u)))
      (setq b (s!:improve (caddr u)))
      (return
         (cond
            ((equal a 0) (s!:imp_minus (list 'minus b)))
            ((equal b 0) a)
            (t (list (car u) a b)))) ))


(put 'difference 's!:tidy_fn 's!:imp_difference)


(de s!:imp_idifference (u)
   (prog (a b)
      (setq a (s!:improve (cadr u)))
      (setq b (s!:improve (caddr u)))
      (return
         (cond
            ((equal a 0) (s!:imp_minus (list 'iminus b)))
            ((equal b 0) a)
            (t (list (car u) a b)))) ))


(put 'idifference 's!:tidy_fn 's!:imp_idifference)


(de s!:alwayseasy (x) t)


(put 'quote 's!:helpeasy (function s!:alwayseasy))


(put 'function 's!:helpeasy (function s!:alwayseasy))


(de s!:easyifarg (x)
   (or (null (cdr x)) (and (null (cddr x)) (s!:iseasy (cadr x)))) )


(put 'ncons 's!:helpeasy (function s!:easyifarg))


(put 'car 's!:helpeasy (function s!:easyifarg))


(put 'cdr 's!:helpeasy (function s!:easyifarg))


(put 'caar 's!:helpeasy (function s!:easyifarg))


(put 'cadr 's!:helpeasy (function s!:easyifarg))


(put 'cdar 's!:helpeasy (function s!:easyifarg))


(put 'cddr 's!:helpeasy (function s!:easyifarg))


(put 'caaar 's!:helpeasy (function s!:easyifarg))


(put 'caadr 's!:helpeasy (function s!:easyifarg))


(put 'cadar 's!:helpeasy (function s!:easyifarg))


(put 'caddr 's!:helpeasy (function s!:easyifarg))


(put 'cdaar 's!:helpeasy (function s!:easyifarg))


(put 'cdadr 's!:helpeasy (function s!:easyifarg))


(put 'cddar 's!:helpeasy (function s!:easyifarg))


(put 'cdddr 's!:helpeasy (function s!:easyifarg))


(put 'caaaar 's!:helpeasy (function s!:easyifarg))


(put 'caaadr 's!:helpeasy (function s!:easyifarg))


(put 'caadar 's!:helpeasy (function s!:easyifarg))


(put 'caaddr 's!:helpeasy (function s!:easyifarg))


(put 'cadaar 's!:helpeasy (function s!:easyifarg))


(put 'cadadr 's!:helpeasy (function s!:easyifarg))


(put 'caddar 's!:helpeasy (function s!:easyifarg))


(put 'cadddr 's!:helpeasy (function s!:easyifarg))


(put 'cdaaar 's!:helpeasy (function s!:easyifarg))


(put 'cdaadr 's!:helpeasy (function s!:easyifarg))


(put 'cdadar 's!:helpeasy (function s!:easyifarg))


(put 'cdaddr 's!:helpeasy (function s!:easyifarg))


(put 'cddaar 's!:helpeasy (function s!:easyifarg))


(put 'cddadr 's!:helpeasy (function s!:easyifarg))


(put 'cdddar 's!:helpeasy (function s!:easyifarg))


(put 'cddddr 's!:helpeasy (function s!:easyifarg))


(de s!:easygetv (x)
   (prog (a2)
      (setq a2 (caddr x))
      (cond
         ((and (null !*carcheckflag) (fixp a2) (geq a2 0) (lessp a2 256))
            (return (s!:iseasy (cadr x))))
         (t (return nil)))) )


(put 'getv 's!:helpeasy (function s!:easygetv))


(de s!:easyqgetv (x)
   (prog (a2)
      (setq a2 (caddr x))
      (cond
         ((and (fixp a2) (geq a2 0) (lessp a2 256))
            (return (s!:iseasy (cadr x))))
         (t (return nil)))) )


(put 'qgetv 's!:helpeasy (function s!:easyqgetv))


(de s!:iseasy (x)
   (prog (h)
      (cond ((atom x) (return t)))
      (cond ((not (atom (car x))) (return nil)))
      (cond
         ((setq h (get (car x) 's!:helpeasy)) (return (funcall h x)))
         (t (return nil)))) )


(de s!:instate_local_decs (v d w)
   (prog (fg)
      (cond ((fluidp v) (return w)))
      (prog (z)
         (setq z d)
   lab   (cond ((null z) (return nil)))
         ((lambda (z)
             (cond ((and (eqcar z 'special) (memq v (cdr z))) (setq fg t))))
            (car z))
         (setq z (cdr z))
         (go lab))
      (cond (fg (progn (make!-special v) (setq w (cons v w)))) )
      (return w)))


(de s!:residual_local_decs (d w)
   (prog nil
      (prog (z)
         (setq z d)
   lab   (cond ((null z) (return nil)))
         ((lambda (z)
             (cond
                ((eqcar z 'special)
                   (prog (v)
                      (setq v (cdr z))
                lab   (cond ((null v) (return nil)))
                      ((lambda (v)
                          (cond
                             ((and (not (fluidp v)) (not (globalp v)))
                                (progn
                                   (make!-special v)
                                   (setq w (cons v w)))) ))
                         (car v))
                      (setq v (cdr v))
                      (go lab)))) )
            (car z))
         (setq z (cdr z))
         (go lab))
      (return w)))


(de s!:cancel_local_decs (w) (unfluid w))


(de s!:find_local_decs (body)
   (prog (w local_decs)
      (prog nil
   !G18  (cond
            ((not
                (and
                   body
                   (or (eqcar (car body) 'declare) (stringp (car body)))) )
               (return nil)))
         (progn
            (cond
               ((stringp (car body)) (setq w (cons (car body) w)))
               (t (setq local_decs (append local_decs (cdar body)))) )
            (setq body (cdr body)))
         (go !G18))
      (prog nil
   !G19  (cond ((not w) (return nil)))
         (progn (setq body (cons (car w) body)) (setq w (cdr w)))
         (go !G19))
      (return (cons local_decs body))))


(de s!:comlambda (bvl body args env context)
   (prog (s nbvl fluids fl1 w local_decs)
      (setq nbvl (setq s (cdr env)))
      (setq body (s!:find_local_decs body))
      (setq local_decs (car body))
      (setq body (cdr body))
      (cond
         ((atom body) (setq body nil))
         ((atom (cdr body)) (setq body (car body)))
         (t (setq body (cons 'progn body))))
      (setq w nil)
      (prog (v)
         (setq v bvl)
   lab   (cond ((null v) (return nil)))
         ((lambda (v) (setq w (s!:instate_local_decs v local_decs w)))
            (car v))
         (setq v (cdr v))
         (go lab))
      (prog (v)
         (setq v bvl)
   lab   (cond ((null v) (return nil)))
         ((lambda (v)
             (progn
                (cond
                   ((or (fluidp v) (globalp v))
                      (prog (g)
                         (setq g (gensym))
                         (setq nbvl (cons g nbvl))
                         (setq fl1 (cons v fl1))
                         (setq fluids (cons (cons v g) fluids))))
                   (t (setq nbvl (cons v nbvl))))
                (cond
                   ((equal (car args) nil) (s!:outstack 1))
                   (t (progn
                         (s!:comval (car args) env 1)
                         (s!:outopcode0 'push '(push)))) )
                (rplacd env (cons 0 (cdr env)))
                (setq args (cdr args))))
            (car v))
         (setq v (cdr v))
         (go lab))
      (rplacd env nbvl)
      (cond
         (fluids
            (progn
               (setq fl1 (s!:vecof fl1))
               (s!:outopcode1lit 'freebind fl1 env)
               (prog (v)
                  (setq v (cons nil fluids))
            lab   (cond ((null v) (return nil)))
                  ((lambda (v) (rplacd env (cons 0 (cdr env)))) (car v))
                  (setq v (cdr v))
                  (go lab))
               (rplacd env (cons (plus 2 (length fluids)) (cdr env)))
               (prog (v)
                  (setq v fluids)
            lab   (cond ((null v) (return nil)))
                  ((lambda (v) (s!:comval (list 'setq (car v) (cdr v)) env 2))
                     (car v))
                  (setq v (cdr v))
                  (go lab)))) )
      (setq w (s!:residual_local_decs local_decs w))
      (s!:comval body env 1)
      (s!:cancel_local_decs w)
      (cond (fluids (s!:outopcode0 'freerstr '(freerstr))))
      (s!:outlose (length bvl))
      (rplacd env s)))


(de s!:loadliteral (x env)
   (cond
      ((member!*!* (list 'quote x) s!:a_reg_values) nil)
      (t (progn
            (cond
               ((equal x nil) (s!:outopcode0 'vnil '(loadlit nil)))
               (t (s!:outopcode1lit 'loadlit x env)))
            (setq s!:a_reg_values (list (list 'quote x)))) )))


(de s!:comquote (x env context)
   (cond ((leq context 1) (s!:loadliteral (cadr x) env))))


(put 'quote 's!:compfn (function s!:comquote))


(fluid '(s!:current_exitlab s!:current_proglabels s!:local_macros))


(de s!:comfunction (x env context)
   (cond
      ((leq context 1)
         (progn
            (setq x (cadr x))
            (cond
               ((eqcar x 'lambda)
                  (prog (g w s!:used_lexicals)
                     (setq s!:has_closure t)
                     (setq g (dated!-name 'lambda))
                     (setq w
                        (s!:compile1
                           g
                           (cadr x)
                           (cddr x)
                           (cons
                              (list
                                 (cdr env)
                                 s!:current_exitlab
                                 s!:current_proglabels
                                 s!:local_macros)
                              s!:lexical_env)))
                     (cond
                        (s!:used_lexicals
                           (setq w
                              (s!:compile1
                                 g
                                 (cons (gensym) (cadr x))
                                 (cddr x)
                                 (cons
                                    (list
                                       (cdr env)
                                       s!:current_exitlab
                                       s!:current_proglabels
                                       s!:local_macros)
                                    s!:lexical_env)))) )
                     (setq s!:other_defs (append w s!:other_defs))
                     (s!:loadliteral g env)
                     (setq w (length (cdr env)))
                     (cond
                        (s!:used_lexicals
                           (progn
                              (setq s!:has_closure t)
                              (cond
                                 ((greaterp w 4095)
                                    (error "stack frame > 4095"))
                                 ((greaterp w 255)
                                    (s!:outopcode2
                                       'bigstack
                                       (plus 128 (truncate w 256))
                                       (logand w 255)
                                       (list 'closure w)))
                                 (t (s!:outopcode1 'closure w x)))) ))) )
               (t (s!:loadliteral x env)))) )))


(put 'function 's!:compfn (function s!:comfunction))


(de s!:should_be_fluid (x)
   (cond
      ((not (or (fluidp x) (globalp x)))
         (progn
            (cond
               (!*pwrds
                  (progn
                     (cond ((neq (posn) 0) (terpri)))
                     (princ "+++ ")
                     (prin x)
                     (princ " declared fluid")
                     (terpri))))
            (fluid (list x))
            nil))))


(de s!:find_lexical (x lex n)
   (prog (p)
      (cond ((null lex) (return nil)))
      (setq p (memq x (caar lex)))
      (cond
         (p
            (progn
               (cond
                  ((not (memq x s!:used_lexicals))
                     (setq s!:used_lexicals (cons x s!:used_lexicals))))
               (return (list n (length p)))) )
         (t (return (s!:find_lexical x (cdr lex) (plus n 1)))) )))


(global '(s!:loadlocs))


(setq s!:loadlocs
   (s!:vecof
      '(loadloc0 loadloc1 loadloc2 loadloc3 loadloc4 loadloc5 loadloc6
          loadloc7 loadloc8 loadloc9 loadloc10 loadloc11)))


(de s!:comatom (x env context)
   (prog (n w)
      (cond
         ((greaterp context 1) (return nil))
         ((or (null x) (not (symbolp x))) (return (s!:loadliteral x env))))
      (setq n 0)
      (setq w (cdr env))
      (prog nil
   !G20  (cond ((not (and w (not (eqcar w x)))) (return nil)))
         (progn (setq n (add1 n)) (setq w (cdr w)))
         (go !G20))
      (cond
         (w
            (progn
               (setq w (cons 'loc w))
               (cond
                  ((member!*!* w s!:a_reg_values) (return nil))
                  (t (progn
                        (cond
                           ((lessp n 12)
                              (s!:outopcode0
                                 (getv s!:loadlocs n)
                                 (list 'loadloc x)))
                           ((greaterp n 4095) (error "stack frame > 4095"))
                           ((greaterp n 255)
                              (s!:outopcode2
                                 'bigstack
                                 (truncate n 256)
                                 (logand n 255)
                                 (list 'loadloc x)))
                           (t (s!:outopcode1 'loadloc n x)))
                        (setq s!:a_reg_values (list w))
                        (return nil)))) )))
      (cond
         ((setq w (s!:find_lexical x s!:lexical_env 0))
            (progn
               (cond
                  ((member!*!* (cons 'lex w) s!:a_reg_values) (return nil)))
               (s!:outlexref 'loadlex (length (cdr env)) (car w) (cadr w) x)
               (setq s!:a_reg_values (list (cons 'lex w)))
               (return nil))))
      (s!:should_be_fluid x)
      (cond ((flagp x 'constant!?) (return (s!:loadliteral (eval x) env))))
      (setq w (cons 'free x))
      (cond ((member!*!* w s!:a_reg_values) (return nil)))
      (s!:outopcode1lit 'loadfree x env)
      (setq s!:a_reg_values (list w))))


(flag '(t !$eol!$ !$eof!$) 'constant!?)


(de s!:islocal (x env)
   (prog (n w)
      (cond ((or (null x) (not (symbolp x)) (eq x t)) (return 99999)))
      (setq n 0)
      (setq w (cdr env))
      (prog nil
   !G21  (cond ((not (and w (not (eqcar w x)))) (return nil)))
         (progn (setq n (add1 n)) (setq w (cdr w)))
         (go !G21))
      (cond (w (return n)) (t (return 99999)))) )


(de s!:load2 (a b env)
   (progn
      (cond
         ((s!:iseasy b)
            (prog (wa wb w)
               (setq wa (s!:islocal a env))
               (setq wb (s!:islocal b env))
               (cond
                  ((and (lessp wa 4) (lessp wb 4))
                     (progn
                        (cond
                           ((and (equal wa 0) (equal wb 1))
                              (setq w 'loc0loc1))
                           ((and (equal wa 1) (equal wb 2))
                              (setq w 'loc1loc2))
                           ((and (equal wa 2) (equal wb 3))
                              (setq w 'loc2loc3))
                           ((and (equal wa 1) (equal wb 0))
                              (setq w 'loc1loc0))
                           ((and (equal wa 2) (equal wb 1))
                              (setq w 'loc2loc1))
                           ((and (equal wa 3) (equal wb 2))
                              (setq w 'loc3loc2)))
                        (cond
                           (w
                              (progn
                                 (s!:outopcode0 w (list 'locloc a b))
                                 (return nil)))) )))
               (s!:comval a env 1)
               (setq s!:a_reg_values nil)
               (s!:comval b env 1)
               (return nil)))
         ((s!:iseasy a)
            (progn
               (s!:comval b env 1)
               (setq s!:a_reg_values nil)
               (s!:comval a env 1)
               t))
         (t (progn
               (s!:comval b env 1)
               (s!:outopcode0 'push '(push))
               (rplacd env (cons 0 (cdr env)))
               (setq s!:a_reg_values nil)
               (s!:comval a env 1)
               (s!:outopcode0 'pop '(pop))
               (rplacd env (cddr env))
               nil)))) )


(global '(s!:carlocs s!:cdrlocs s!:caarlocs))


(setq s!:carlocs
   (s!:vecof
      '(carloc0 carloc1 carloc2 carloc3 carloc4 carloc5 carloc6 carloc7
          carloc8 carloc9 carloc10 carloc11)))


(setq s!:cdrlocs
   (s!:vecof '(cdrloc0 cdrloc1 cdrloc2 cdrloc3 cdrloc4 cdrloc5)))


(setq s!:caarlocs (s!:vecof '(caarloc0 caarloc1 caarloc2 caarloc3)))


(flag '(plus2 times2 eq equal) 's!:symmetric)


(flag
   '(car cdr caar cadr cdar cddr ncons add1 sub1 numberp length)
   's!:onearg)


(flag
   '(cons xcons list2 get flagp plus2 difference times2 greaterp lessp apply1
       eq equal getv qgetv eqcar)
   's!:twoarg)


(flag '(apply2 list2!* list3 acons) 's!:threearg)


(de s!:comcall (x env context)
   (prog (fn args nargs op s w1 w2 w3 sw)
      (setq fn (car x))
      (setq args
         (prog (v !G22 endptr)
            (setq v (cdr x))
            (cond ((null v) (return nil)))
            (setq !G22
               (setq endptr (cons ((lambda (v) (s!:improve v)) (car v)) nil)))
      looplabel
            (setq v (cdr v))
            (cond ((null v) (return !G22)))
            (rplacd endptr (cons ((lambda (v) (s!:improve v)) (car v)) nil))
            (setq endptr (cdr endptr))
            (go looplabel)))
      (setq nargs (length args))
      (cond
         ((and (greaterp nargs 15) !*pwrds)
            (progn
               (cond ((neq (posn) 0) (terpri)))
               (princ "+++ ")
               (prin fn)
               (princ " called with ")
               (prin nargs)
               (princ " from function ")
               (prin s!:current_function)
               (terpri))))
      (setq s (cdr env))
      (cond
         ((equal nargs 0)
            (cond
               ((setq w2 (get fn 's!:builtin0))
                  (s!:outopcode1 'builtin0 w2 fn))
               (t (s!:outopcode1lit 'call0 fn env))))
         ((equal nargs 1)
            (progn
               (cond
                  ((and
                      (equal fn 'car)
                      (lessp (setq w2 (s!:islocal (car args) env)) 12))
                     (s!:outopcode0
                        (getv s!:carlocs w2)
                        (list 'carloc (car args))))
                  ((and
                      (equal fn 'cdr)
                      (lessp (setq w2 (s!:islocal (car args) env)) 6))
                     (s!:outopcode0
                        (getv s!:cdrlocs w2)
                        (list 'cdrloc (car args))))
                  ((and
                      (equal fn 'caar)
                      (lessp (setq w2 (s!:islocal (car args) env)) 4))
                     (s!:outopcode0
                        (getv s!:caarlocs w2)
                        (list 'caarloc (car args))))
                  (t (progn
                        (s!:comval (car args) env 1)
                        (cond
                           ((flagp fn 's!:onearg)
                              (s!:outopcode0 fn (list fn)))
                           ((setq w2 (get fn 's!:builtin1))
                              (s!:outopcode1 'builtin1 w2 fn))
                           (t (s!:outopcode1lit 'call1 fn env)))) ))) )
         ((equal nargs 2)
            (progn
               (setq sw (s!:load2 (car args) (cadr args) env))
               (cond ((flagp fn 's!:symmetric) (setq sw nil)))
               (cond
                  ((flagp fn 's!:twoarg)
                     (progn
                        (cond (sw (s!:outopcode0 'swop '(swop))))
                        (s!:outopcode0 fn (list fn))))
                  (t (progn
                        (setq w3 (get fn 's!:builtin2))
                        (cond
                           (sw
                              (progn
                                 (cond
                                    (w3 (s!:outopcode1 'builtin2r w3 fn))
                                    (t (s!:outopcode1lit 'call2r fn env)))) )
                           (w3 (s!:outopcode1 'builtin2 w3 fn))
                           (t (s!:outopcode1lit 'call2 fn env)))) ))) )
         ((equal nargs 3)
            (progn
               (cond
                  ((equal (car args) nil) (s!:outstack 1))
                  (t (progn
                        (s!:comval (car args) env 1)
                        (s!:outopcode0 'push '(pusha3)))) )
               (rplacd env (cons 0 (cdr env)))
               (setq s!:a_reg_values nil)
               (cond
                  ((s!:load2 (cadr args) (caddr args) env)
                     (s!:outopcode0 'swop '(swop))))
               (cond
                  ((flagp fn 's!:threearg)
                     (s!:outopcode0
                        (cond ((equal fn 'list2!*) 'list2star) (t fn))
                        (list fn)))
                  ((setq w2 (get fn 's!:builtin3))
                     (s!:outopcode1 'builtin3 w2 fn))
                  (t (s!:outopcode1lit 'call3 fn env)))
               (rplacd env (cddr env))))
         (t (prog (largs)
               (setq largs (reverse args))
               (prog (a)
                  (setq a (reverse (cddr largs)))
            lab   (cond ((null a) (return nil)))
                  ((lambda (a)
                      (progn
                         (cond
                            ((null a) (s!:outstack 1))
                            (t (progn
                                  (s!:comval a env 1)
                                  (cond
                                     ((equal nargs 4)
                                        (s!:outopcode0 'push '(pusha4)))
                                     (t (s!:outopcode0 'push '(pusharg)))) )))
                         (rplacd env (cons 0 (cdr env)))
                         (setq s!:a_reg_values nil)))
                     (car a))
                  (setq a (cdr a))
                  (go lab))
               (cond
                  ((s!:load2 (cadr largs) (car largs) env)
                     (s!:outopcode0 'swop '(swop))))
               (cond
                  ((and (equal fn 'apply3) (equal nargs 4))
                     (s!:outopcode0 'apply3 '(apply3)))
                  ((greaterp nargs 255)
                     (error "Over 255 args in a function call"))
                  (t (s!:outopcode2lit 'calln fn nargs (list nargs fn) env)))
               (rplacd env s)))) ))


(de s!:ad_name (l)
   (cond
      ((equal (car l) 'a) (cond ((equal (cadr l) 'a) 'caar) (t 'cadr)))
      ((equal (cadr l) 'a) 'cdar)
      (t 'cddr)))


(de s!:comcarcdr3 (x env context)
   (prog (name outer c1 c2)
      (setq name (cdr (explode2 (car x))))
      (setq x
         (list
            (s!:ad_name name)
            (list (cond ((equal (caddr name) 'a) 'car) (t 'cdr)) (cadr x))))
      (return (s!:comval x env context))))


(put 'caaar 's!:compfn (function s!:comcarcdr3))


(put 'caadr 's!:compfn (function s!:comcarcdr3))


(put 'cadar 's!:compfn (function s!:comcarcdr3))


(put 'caddr 's!:compfn (function s!:comcarcdr3))


(put 'cdaar 's!:compfn (function s!:comcarcdr3))


(put 'cdadr 's!:compfn (function s!:comcarcdr3))


(put 'cddar 's!:compfn (function s!:comcarcdr3))


(put 'cdddr 's!:compfn (function s!:comcarcdr3))


(de s!:comcarcdr4 (x env context)
   (prog (name outer c1 c2)
      (setq name (cdr (explode2 (car x))))
      (setq x
         (list (s!:ad_name name) (list (s!:ad_name (cddr name)) (cadr x))))
      (return (s!:comval x env context))))


(put 'caaaar 's!:compfn (function s!:comcarcdr4))


(put 'caaadr 's!:compfn (function s!:comcarcdr4))


(put 'caadar 's!:compfn (function s!:comcarcdr4))


(put 'caaddr 's!:compfn (function s!:comcarcdr4))


(put 'cadaar 's!:compfn (function s!:comcarcdr4))


(put 'cadadr 's!:compfn (function s!:comcarcdr4))


(put 'caddar 's!:compfn (function s!:comcarcdr4))


(put 'cadddr 's!:compfn (function s!:comcarcdr4))


(put 'cdaaar 's!:compfn (function s!:comcarcdr4))


(put 'cdaadr 's!:compfn (function s!:comcarcdr4))


(put 'cdadar 's!:compfn (function s!:comcarcdr4))


(put 'cdaddr 's!:compfn (function s!:comcarcdr4))


(put 'cddaar 's!:compfn (function s!:comcarcdr4))


(put 'cddadr 's!:compfn (function s!:comcarcdr4))


(put 'cdddar 's!:compfn (function s!:comcarcdr4))


(put 'cddddr 's!:compfn (function s!:comcarcdr4))


(de s!:comgetv (x env context)
   (cond
      (!*carcheckflag (s!:comcall x env context))
      (t (s!:comval (cons 'qgetv (cdr x)) env context))))


(put 'getv 's!:compfn (function s!:comgetv))


(de s!:comqgetv (x env context)
   (cond
      ((and (fixp (caddr x)) (geq (caddr x) 0) (lessp (caddr x) 256))
         (progn
            (s!:comval (cadr x) env 1)
            (s!:outopcode1 'qgetvn (caddr x) (caddr x))))
      (t (s!:comcall x env context))))


(put 'qgetv 's!:compfn (function s!:comqgetv))


(de s!:comget (x env context)
   (prog (a b c w)
      (setq a (cadr x))
      (setq b (caddr x))
      (setq c (cdddr x))
      (cond
         ((eqcar b 'quote)
            (progn
               (setq b (cadr b))
               (setq w (symbol!-make!-fastget b nil))
               (cond
                  (c
                     (progn
                        (cond
                           (w
                              (progn
                                 (cond
                                    ((s!:load2 a b env)
                                       (s!:outopcode0 'swop '(swop))))
                                 (s!:outopcode1 'fastget (logor w 64) b)))
                           (t (s!:comcall x env context)))) )
                  (t (progn
                        (s!:comval a env 1)
                        (cond
                           (w (s!:outopcode1 'fastget w b))
                           (t (s!:outopcode1lit 'litget b env)))) ))) )
         (t (s!:comcall x env context)))) )


(put 'get 's!:compfn (function s!:comget))


(de s!:comflagp (x env context)
   (prog (a b)
      (setq a (cadr x))
      (setq b (caddr x))
      (cond
         ((eqcar b 'quote)
            (progn
               (setq b (cadr b))
               (s!:comval a env 1)
               (setq a (symbol!-make!-fastget b nil))
               (cond
                  (a (s!:outopcode1 'fastget (logor a 128) b))
                  (t (s!:comcall x env context)))) )
         (t (s!:comcall x env context)))) )


(put 'flagp 's!:compfn (function s!:comflagp))


(de s!:complus (x env context)
   (s!:comval (expand (cdr x) 'plus2) env context))


(put 'plus 's!:compfn (function s!:complus))


(de s!:comtimes (x env context)
   (s!:comval (expand (cdr x) 'times2) env context))


(put 'times 's!:compfn (function s!:comtimes))


(de s!:comiplus (x env context)
   (s!:comval (expand (cdr x) 'iplus2) env context))


(put 'iplus 's!:compfn (function s!:comiplus))


(de s!:comitimes (x env context)
   (s!:comval (expand (cdr x) 'itimes2) env context))


(put 'itimes 's!:compfn (function s!:comitimes))


(de s!:complus2 (x env context)
   (prog (a b)
      (setq a (s!:improve (cadr x)))
      (setq b (s!:improve (caddr x)))
      (return
         (cond
            ((and (numberp a) (numberp b)) (s!:comval (plus a b) env context))
            ((equal a 0) (s!:comval b env context))
            ((equal a 1) (s!:comval (list 'add1 b) env context))
            ((equal b 0) (s!:comval a env context))
            ((equal b 1) (s!:comval (list 'add1 a) env context))
            ((equal b (minus 1)) (s!:comval (list 'sub1 a) env context))
            (t (s!:comcall x env context)))) ))


(put 'plus2 's!:compfn (function s!:complus2))


(de s!:comdifference (x env context)
   (prog (a b)
      (setq a (s!:improve (cadr x)))
      (setq b (s!:improve (caddr x)))
      (return
         (cond
            ((and (numberp a) (numberp b))
               (s!:comval (difference a b) env context))
            ((equal a 0) (s!:comval (list 'minus b) env context))
            ((equal b 0) (s!:comval a env context))
            ((equal b 1) (s!:comval (list 'sub1 a) env context))
            ((equal b (minus 1)) (s!:comval (list 'add1 a) env context))
            (t (s!:comcall x env context)))) ))


(put 'difference 's!:compfn (function s!:comdifference))


(de s!:comiplus2 (x env context)
   (prog (a b)
      (setq a (s!:improve (cadr x)))
      (setq b (s!:improve (caddr x)))
      (return
         (cond
            ((and (numberp a) (numberp b)) (s!:comval (plus a b) env context))
            ((equal a 1) (s!:comval (list 'iadd1 b) env context))
            ((equal b 1) (s!:comval (list 'iadd1 a) env context))
            ((equal b (minus 1)) (s!:comval (list 'isub1 a) env context))
            (t (s!:comcall x env context)))) ))


(put 'iplus2 's!:compfn (function s!:comiplus2))


(de s!:comidifference (x env context)
   (prog (a b)
      (setq a (s!:improve (cadr x)))
      (setq b (s!:improve (caddr x)))
      (return
         (cond
            ((and (numberp a) (numberp b))
               (s!:comval (difference a b) env context))
            ((equal b 1) (s!:comval (list 'isub1 a) env context))
            ((equal b (minus 1)) (s!:comval (list 'iadd1 a) env context))
            (t (s!:comcall x env context)))) ))


(put 'idifference 's!:compfn (function s!:comidifference))


(de s!:comtimes2 (x env context)
   (prog (a b)
      (setq a (s!:improve (cadr x)))
      (setq b (s!:improve (caddr x)))
      (return
         (cond
            ((and (numberp a) (numberp b))
               (s!:comval (times a b) env context))
            ((equal a 1) (s!:comval b env context))
            ((equal a (minus 1)) (s!:comval (list 'minus b) env context))
            ((equal b 1) (s!:comval a env context))
            ((equal b (minus 1)) (s!:comval (list 'minus a) env context))
            (t (s!:comcall x env context)))) ))


(put 'times2 's!:compfn (function s!:comtimes2))


(put 'itimes2 's!:compfn (function s!:comtimes2))


(de s!:comminus (x env context)
   (prog (a b)
      (setq a (s!:improve (cadr x)))
      (return
         (cond
            ((numberp a) (s!:comval (minus a) env context))
            ((eqcar a 'minus) (s!:comval (cadr a) env context))
            (t (s!:comcall x env context)))) ))


(put 'minus 's!:compfn (function s!:comminus))


(de s!:comminusp (x env context)
   (prog (a)
      (setq a (s!:improve (cadr x)))
      (cond
         ((eqcar a 'difference)
            (return (s!:comval (cons 'lessp (cdr a)) env context)))
         (t (return (s!:comcall x env context)))) ))


(put 'minusp 's!:compfn (function s!:comminusp))


(de s!:comlessp (x env context)
   (prog (a b)
      (setq a (s!:improve (cadr x)))
      (setq b (s!:improve (caddr x)))
      (cond
         ((equal b 0) (return (s!:comval (list 'minusp a) env context)))
         (t (return (s!:comcall x env context)))) ))


(put 'lessp 's!:compfn (function s!:comlessp))


(de s!:comiminusp (x env context)
   (prog (a)
      (setq a (s!:improve (cadr x)))
      (cond
         ((eqcar a 'difference)
            (return (s!:comval (cons 'ilessp (cdr a)) env context)))
         (t (return (s!:comcall x env context)))) ))


(put 'iminusp 's!:compfn (function s!:comiminusp))


(de s!:comilessp (x env context)
   (prog (a b)
      (setq a (s!:improve (cadr x)))
      (setq b (s!:improve (caddr x)))
      (cond
         ((equal b 0) (return (s!:comval (list 'iminusp a) env context)))
         (t (return (s!:comcall x env context)))) ))


(put 'ilessp 's!:compfn (function s!:comilessp))


(de s!:comprogn (x env context)
   (progn
      (setq x (cdr x))
      (cond
         ((null x) (s!:comval nil env context))
         (t (prog (a)
               (setq a (car x))
               (prog nil
            !G23  (cond ((not (setq x (cdr x))) (return nil)))
                  (progn
                     (s!:comval a env (cond ((geq context 4) context) (t 2)))
                     (setq a (car x)))
                  (go !G23))
               (s!:comval a env context)))) ))


(put 'progn 's!:compfn (function s!:comprogn))


(de s!:comprog1 (x env context)
   (prog nil
      (setq x (cdr x))
      (cond ((null x) (return (s!:comval nil env context))))
      (s!:comval (car x) env context)
      (cond ((null (setq x (cdr x))) (return nil)))
      (s!:outopcode0 'push '(push))
      (rplacd env (cons 0 (cdr env)))
      (prog (a)
         (setq a x)
   lab   (cond ((null a) (return nil)))
         ((lambda (a)
             (s!:comval a env (cond ((geq context 4) context) (t 2))))
            (car a))
         (setq a (cdr a))
         (go lab))
      (s!:outopcode0 'pop '(pop))
      (rplacd env (cddr env))))


(put 'prog1 's!:compfn (function s!:comprog1))


(de s!:comprog2 (x env context)
   (prog (a)
      (setq x (cdr x))
      (cond ((null x) (return (s!:comval nil env context))))
      (setq a (car x))
      (s!:comval a env (cond ((geq context 4) context) (t 2)))
      (s!:comprog1 x env context)))


(put 'prog2 's!:compfn (function s!:comprog2))


(de s!:outstack (n)
   (prog (w a)
      (setq w s!:current_block)
      (prog nil
   !G24  (cond ((not (and w (not (atom (car w)))) ) (return nil)))
         (setq w (cdr w))
         (go !G24))
      (cond
         ((eqcar w 'pushnil) (setq a 1))
         ((eqcar w 'pushnil2) (setq a 2))
         ((eqcar w 'pushnil3) (setq a 3))
         ((and
             w
             (numberp (setq a (car w)))
             (not (equal a 255))
             (eqcar (cdr w) 'pushnils))
            (progn
               (setq w (cdr w))
               (setq s!:current_size (difference s!:current_size 1))))
         (t (setq a nil)))
      (cond
         (a
            (progn
               (setq s!:current_block (cdr w))
               (setq s!:current_size (difference s!:current_size 1))
               (setq n (plus n a)))) )
      (cond
         ((equal n 1) (s!:outopcode0 'pushnil '(pushnil)))
         ((equal n 2) (s!:outopcode0 'pushnil2 '(pushnil2)))
         ((equal n 3) (s!:outopcode0 'pushnil3 '(pushnil3)))
         ((greaterp n 255)
            (progn
               (s!:outopcode1 'pushnils 255 255)
               (s!:outstack (difference n 255))))
         ((greaterp n 3) (s!:outopcode1 'pushnils n n)))) )


(de s!:outlose (n)
   (prog (w a)
      (setq w s!:current_block)
      (prog nil
   !G25  (cond ((not (and w (not (atom (car w)))) ) (return nil)))
         (setq w (cdr w))
         (go !G25))
      (cond
         ((eqcar w 'lose) (setq a 1))
         ((eqcar w 'lose2) (setq a 2))
         ((eqcar w 'lose3) (setq a 3))
         ((and
             w
             (numberp (setq a (car w)))
             (not (equal a 255))
             (eqcar (cdr w) 'loses))
            (progn
               (setq w (cdr w))
               (setq s!:current_size (difference s!:current_size 1))))
         (t (setq a nil)))
      (cond
         (a
            (progn
               (setq s!:current_block (cdr w))
               (setq s!:current_size (difference s!:current_size 1))
               (setq n (plus n a)))) )
      (cond
         ((equal n 1) (s!:outopcode0 'lose '(lose)))
         ((equal n 2) (s!:outopcode0 'lose2 '(lose2)))
         ((equal n 3) (s!:outopcode0 'lose3 '(lose3)))
         ((greaterp n 255)
            (progn
               (s!:outopcode1 'loses 255 255)
               (s!:outlose (difference n 255))))
         ((greaterp n 3) (s!:outopcode1 'loses n n)))) )


(de s!:comprog (x env context)
   (prog (labs s bvl fluids n body local_decs w)
      (setq body (s!:find_local_decs (cddr x)))
      (setq local_decs (car body))
      (setq body (cdr body))
      (setq n 0)
      (prog (v)
         (setq v (cadr x))
   lab   (cond ((null v) (return nil)))
         ((lambda (v) (setq w (s!:instate_local_decs v local_decs w)))
            (car v))
         (setq v (cdr v))
         (go lab))
      (prog (v)
         (setq v (cadr x))
   lab   (cond ((null v) (return nil)))
         ((lambda (v)
             (progn
                (cond
                   ((globalp v)
                      (progn
                         (cond
                            (!*pwrds
                               (progn
                                  (cond ((neq (posn) 0) (terpri)))
                                  (princ "+++++ global ")
                                  (prin v)
                                  (princ " converted to fluid")
                                  (terpri))))
                         (unglobal (list v))
                         (fluid (list v)))) )
                (cond
                   ((fluidp v) (setq fluids (cons v fluids)))
                   (t (progn (setq n (plus n 1)) (setq bvl (cons v bvl)))) )))
            (car v))
         (setq v (cdr v))
         (go lab))
      (setq s (cdr env))
      (setq s!:current_exitlab
         (cons (cons nil (cons (gensym) s)) s!:current_exitlab))
      (s!:outstack n)
      (rplacd env (append bvl (cdr env)))
      (cond
         (fluids
            (prog (fl1)
               (setq fl1 (s!:vecof fluids))
               (s!:outopcode1lit 'freebind fl1 env)
               (prog (v)
                  (setq v (cons nil fluids))
            lab   (cond ((null v) (return nil)))
                  ((lambda (v) (rplacd env (cons 0 (cdr env)))) (car v))
                  (setq v (cdr v))
                  (go lab))
               (rplacd env (cons (plus 2 (length fluids)) (cdr env)))
               (cond ((equal context 0) (setq context 1)))) ))
      (prog (a)
         (setq a (cddr x))
   lab   (cond ((null a) (return nil)))
         ((lambda (a)
             (cond
                ((atom a)
                   (progn
                      (cond
                         ((atsoc a labs)
                            (progn
                               (cond
                                  ((not (null a))
                                     (progn
                                        (cond ((neq (posn) 0) (terpri)))
                                        (princ "+++++ label ")
                                        (prin a)
                                        (princ " multiply defined")
                                        (terpri)))) ))
                         (t (setq labs
                               (cons
                                  (cons
                                     a
                                     (cons (cons (gensym) (cdr env)) nil))
                                  labs)))) ))) )
            (car a))
         (setq a (cdr a))
         (go lab))
      (setq s!:current_proglabels (cons labs s!:current_proglabels))
      (setq w (s!:residual_local_decs local_decs w))
      (prog (a)
         (setq a (cddr x))
   lab   (cond ((null a) (return nil)))
         ((lambda (a)
             (cond
                ((not (atom a)) (s!:comval a env (plus context 4)))
                (t (prog (d)
                      (setq d (atsoc a labs))
                      (cond
                         ((null (cddr d))
                            (progn
                               (rplacd (cdr d) t)
                               (s!:set_label (caadr d)))) ))) ))
            (car a))
         (setq a (cdr a))
         (go lab))
      (s!:cancel_local_decs w)
      (s!:comval nil env context)
      (cond (fluids (s!:outopcode0 'freerstr '(freerstr))))
      (s!:outlose n)
      (rplacd env s)
      (s!:set_label (cadar s!:current_exitlab))
      (setq s!:current_exitlab (cdr s!:current_exitlab))
      (setq s!:current_proglabels (cdr s!:current_proglabels))))


(put 'prog 's!:compfn (function s!:comprog))


(de s!:comtagbody (x env context)
   (prog (labs)
      (prog (a)
         (setq a (cdr x))
   lab   (cond ((null a) (return nil)))
         ((lambda (a)
             (cond
                ((atom a)
                   (progn
                      (cond
                         ((atsoc a labs)
                            (progn
                               (cond
                                  ((not (null a))
                                     (progn
                                        (cond ((neq (posn) 0) (terpri)))
                                        (princ "+++++ label ")
                                        (prin a)
                                        (princ " multiply defined")
                                        (terpri)))) ))
                         (t (setq labs
                               (cons
                                  (cons
                                     a
                                     (cons (cons (gensym) (cdr env)) nil))
                                  labs)))) ))) )
            (car a))
         (setq a (cdr a))
         (go lab))
      (setq s!:current_proglabels (cons labs s!:current_proglabels))
      (prog (a)
         (setq a (cdr x))
   lab   (cond ((null a) (return nil)))
         ((lambda (a)
             (cond
                ((not (atom a)) (s!:comval a env (plus context 4)))
                (t (prog (d)
                      (setq d (atsoc a labs))
                      (cond
                         ((null (cddr d))
                            (progn
                               (rplacd (cdr d) t)
                               (s!:set_label (caadr d)))) ))) ))
            (car a))
         (setq a (cdr a))
         (go lab))
      (s!:comval nil env context)
      (setq s!:current_proglabels (cdr s!:current_proglabels))))


(put 'tagbody 's!:compfn (function s!:comtagbody))


(de s!:comblock (x env context)
   (prog nil
      (setq s!:current_exitlab
         (cons (cons (cadr x) (cons (gensym) (cdr env))) s!:current_exitlab))
      (s!:comval (cons 'progn (cddr x)) env context)
      (s!:set_label (cadar s!:current_exitlab))
      (setq s!:current_exitlab (cdr s!:current_exitlab))))


(put '!~block 's!:compfn (function s!:comblock))


(de s!:comcatch (x env context)
   (prog (g)
      (setq g (gensym))
      (s!:comval (cadr x) env 1)
      (s!:outjump 'catch g)
      (rplacd env (cons '(catch) (cons 0 (cons 0 (cdr env)))) )
      (s!:comval (cons 'progn (cddr x)) env context)
      (s!:outopcode0 'uncatch '(uncatch))
      (rplacd env (cddddr env))
      (s!:set_label g)))


(put 'catch 's!:compfn 's!:comcatch)


(de s!:comthrow (x env context)
   (prog nil
      (s!:comval (cadr x) env 1)
      (s!:outopcode0 'push '(push))
      (rplacd env (cons 0 (cdr env)))
      (s!:comval (caddr x) env 1)
      (s!:outopcode0 'throw '(throw))
      (rplacd env (cddr env))))


(put 'throw 's!:compfn 's!:comthrow)


(de s!:comunwind!-protect (x env context)
   (prog (g)
      (setq g (gensym))
      (s!:comval '(load!-spid) env 1)
      (s!:outjump 'catch g)
      (rplacd
         env
         (cons (list 'unwind!-protect (cddr x)) (cons 0 (cons 0 (cdr env)))) )
      (s!:comval (cadr x) env context)
      (s!:outopcode0 'protect '(protect))
      (s!:set_label g)
      (rplaca (cdr env) 0)
      (s!:comval (cons 'progn (cddr x)) env context)
      (s!:outopcode0 'unprotect '(unprotect))
      (rplacd env (cddddr env))))


(put 'unwind!-protect 's!:compfn 's!:comunwind!-protect)


(de s!:comdeclare (x env context)
   (prog nil
      (cond
         (!*pwrds
            (progn (princ "+++ ") (prin x) (princ " ignored") (terpri)))) ))


(put 'declare 's!:compfn (function s!:comdeclare))


(de s!:expand_let (vl b)
   (prog (vars vals)
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
      (return (list (cons (cons 'lambda (cons vars b)) vals)))) )


(de s!:comlet (x env context)
   (s!:comval (cons 'progn (s!:expand_let (cadr x) (cddr x))) env context))


(put '!~let 's!:compfn (function s!:comlet))


(de s!:expand_let!* (vl local_decs b)
   (prog (r var val)
      (setq r (cons (cons 'declare local_decs) b))
      (prog (x)
         (setq x (reverse vl))
   lab   (cond ((null x) (return nil)))
         ((lambda (x)
             (progn
                (setq val nil)
                (cond
                   ((atom x) (setq var x))
                   ((atom (cdr x)) (setq var (car x)))
                   (t (progn (setq var (car x)) (setq val (cadr x)))) )
                (prog (z)
                   (setq z local_decs)
             lab   (cond ((null z) (return nil)))
                   ((lambda (z)
                       (cond
                          ((eqcar z 'special)
                             (cond
                                ((memq var (cdr z))
                                   (setq r
                                      (cons
                                         (list 'declare (list 'special var))
                                         r)))) )))
                      (car z))
                   (setq z (cdr z))
                   (go lab))
                (setq r
                   (list (list (cons 'lambda (cons (list var) r)) val)))) )
            (car x))
         (setq x (cdr x))
         (go lab))
      (cond
         ((eqcar (car r) 'declare)
            (setq r (list (cons 'lambda (cons nil r)))) )
         (t (setq r (cons 'progn r))))
      (return r)))


(de s!:comlet!* (x env context)
   (prog (b)
      (setq b (s!:find_local_decs (cddr x)))
      (return
         (s!:comval (s!:expand_let!* (cadr x) (car b) (cdr b)) env context))))


(put 'let!* 's!:compfn (function s!:comlet!*))


(de s!:restore_stack (e1 e2)
   (prog (n)
      (setq n 0)
      (prog nil
   !G26  (cond ((not (not (equal e1 e2))) (return nil)))
         (progn
            (cond
               ((null e1)
                  (error 0 "bad block nesting with GO or RETURN-FROM")))
            (cond
               ((and (numberp (car e1)) (greaterp (car e1) 2))
                  (progn
                     (cond ((not (zerop n)) (s!:outlose n)))
                     (setq n (car e1))
                     (s!:outopcode0 'freerstr '(freerstr))
                     (prog (i)
                        (setq i 1)
                  lab   (cond ((minusp (difference n i)) (return nil)))
                        (setq e1 (cdr e1))
                        (setq i (plus2 i 1))
                        (go lab))
                     (setq n 0)))
               ((equal (car e1) '(catch))
                  (progn
                     (cond ((not (zerop n)) (s!:outlose n)))
                     (s!:outopcode0 'uncatch '(uncatch))
                     (setq e1 (cdddr e1))
                     (setq n 0)))
               ((eqcar (car e1) 'unwind!-protect)
                  (progn
                     (cond ((not (zerop n)) (s!:outlose n)))
                     (s!:outopcode0 'protect '(protect))
                     (s!:comval (cons 'progn (cadar e1)) e1 2)
                     (s!:outopcode0 'unprotect '(unprotect))
                     (setq e1 (cdddr e1))
                     (setq n 0)))
               (t (progn (setq e1 (cdr e1)) (setq n (plus n 1)))) ))
         (go !G26))
      (cond ((not (zerop n)) (s!:outlose n)))) )


(de s!:comgo (x env context)
   (prog (pl d)
      (cond
         ((lessp context 4)
            (progn (princ "go not in program context") (terpri))))
      (setq pl s!:current_proglabels)
      (prog nil
   !G27  (cond ((not (and pl (null d))) (return nil)))
         (progn
            (setq d (atsoc (cadr x) (car pl)))
            (cond ((null d) (setq pl (cdr pl)))) )
         (go !G27))
      (cond
         ((null d)
            (progn
               (cond ((neq (posn) 0) (terpri)))
               (princ "+++++ label ")
               (prin (cadr x))
               (princ " not set")
               (terpri)
               (return nil))))
      (setq d (cadr d))
      (s!:restore_stack (cdr env) (cdr d))
      (s!:outjump 'jump (car d))))


(put 'go 's!:compfn (function s!:comgo))


(de s!:comreturn!-from (x env context)
   (prog (tag)
      (cond
         ((lessp context 4)
            (progn
               (princ "+++++ return or return-from not in prog context")
               (terpri))))
      (setq x (cdr x))
      (setq tag (car x))
      (cond ((cdr x) (setq x (cadr x))) (t (setq x nil)))
      (s!:comval x env (difference context 4))
      (setq x (atsoc tag s!:current_exitlab))
      (cond ((null x) (error 0 (list "invalid return-from" tag))))
      (setq x (cdr x))
      (s!:restore_stack (cdr env) (cdr x))
      (s!:outjump 'jump (car x))))


(put 'return!-from 's!:compfn (function s!:comreturn!-from))


(de s!:comreturn (x env context)
   (s!:comreturn!-from (cons 'return!-from (cons nil (cdr x))) env context))


(put 'return 's!:compfn (function s!:comreturn))


(global '(s!:jumplts s!:jumplnils s!:jumpatoms s!:jumpnatoms))


(setq s!:jumplts (s!:vecof '(jumpl0t jumpl1t jumpl2t jumpl3t jumpl4t)))


(setq s!:jumplnils
   (s!:vecof '(jumpl0nil jumpl1nil jumpl2nil jumpl3nil jumpl4nil)))


(setq s!:jumpatoms (s!:vecof '(jumpl0atom jumpl1atom jumpl2atom jumpl3atom)))


(setq s!:jumpnatoms
   (s!:vecof '(jumpl0natom jumpl1natom jumpl2natom jumpl3natom)))


(de s!:jumpif (neg x env lab)
   (prog (w w1 j)
top   (cond
         ((null x)
            (progn (cond ((not neg) (s!:outjump 'jump lab))) (return nil)))
         ((or
             (eq x t)
             (and (eqcar x 'quote) (cadr x))
             (and (atom x) (not (symbolp x))))
            (progn (cond (neg (s!:outjump 'jump lab))) (return nil)))
         ((lessp (setq w (s!:islocal x env)) 5)
            (return
               (s!:outjump
                  (getv (cond (neg s!:jumplts) (t s!:jumplnils)) w)
                  lab)))
         ((and (equal w 99999) (symbolp x))
            (progn
               (s!:should_be_fluid x)
               (setq w (list (cond (neg 'jumpfreet) (t 'jumpfreenil)) x x))
               (return (s!:record_literal_for_jump w env lab)))) )
      (cond
         ((and
             (not (atom x))
             (atom (car x))
             (setq w (get (car x) 's!:testfn)))
            (return (funcall w neg x env lab))))
      (cond
         ((not (atom x))
            (progn
               (setq w (s!:improve x))
               (cond
                  ((or (atom w) (not (eqcar x (car w))))
                     (progn (setq x w) (go top))))
               (cond
                  ((and
                      (setq w1 (get (car w) 's!:compilermacro))
                      (setq w1 (funcall w1 w env 1)))
                     (progn (setq x w1) (go top)))) )))
remacro
      (cond
         ((and (not (atom w)) (setq w1 (macro!-function (car w))))
            (progn
               (setq w (funcall w1 w))
               (cond
                  ((or
                      (atom w)
                      (eqcar w 'quote)
                      (get (car w) 's!:testfn)
                      (get (car w) 's!:compilermacro))
                     (progn (setq x w) (go top))))
               (go remacro))))
      (s!:comval x env 1)
      (setq w s!:current_block)
      (prog nil
   !G28  (cond ((not (and w (not (atom (car w)))) ) (return nil)))
         (setq w (cdr w))
         (go !G28))
      (setq j '(jumpnil . jumpt))
      (cond
         (w
            (progn
               (setq w1 (car w))
               (setq w (cdr w))
               (cond
                  ((equal w1 'storeloc0)
                     (progn
                        (setq s!:current_block w)
                        (setq s!:current_size (difference s!:current_size 1))
                        (setq j '(jumpst0nil . jumpst0t))))
                  ((equal w1 'storeloc1)
                     (progn
                        (setq s!:current_block w)
                        (setq s!:current_size (difference s!:current_size 1))
                        (setq j '(jumpst1nil . jumpst1t))))
                  ((equal w1 'storeloc2)
                     (progn
                        (setq s!:current_block w)
                        (setq s!:current_size (difference s!:current_size 1))
                        (setq j '(jumpst2nil . jumpst2t))))
                  ((eqcar w 'builtin1)
                     (progn
                        (setq s!:current_block (cdr w))
                        (setq s!:current_size (difference s!:current_size 2))
                        (setq j
                           (cons (list 'jumpb1nil w1) (list 'jumpb1t w1)))) )
                  ((eqcar w 'builtin2)
                     (progn
                        (setq s!:current_block (cdr w))
                        (setq s!:current_size (difference s!:current_size 2))
                        (setq j
                           (cons
                              (list 'jumpb2nil w1)
                              (list 'jumpb2t w1)))) ))) ))
      (return (s!:outjump (cond (neg (cdr j)) (t (car j))) lab))))


(de s!:testnot (neg x env lab) (s!:jumpif (not neg) (cadr x) env lab))


(put 'null 's!:testfn (function s!:testnot))


(put 'not 's!:testfn (function s!:testnot))


(de s!:testatom (neg x env lab)
   (prog (w)
      (cond
         ((lessp (setq w (s!:islocal (cadr x) env)) 4)
            (return
               (s!:outjump
                  (getv (cond (neg s!:jumpatoms) (t s!:jumpnatoms)) w)
                  lab))))
      (s!:comval (cadr x) env 1)
      (cond
         (neg (s!:outjump 'jumpatom lab))
         (t (s!:outjump 'jumpnatom lab)))) )


(put 'atom 's!:testfn (function s!:testatom))


(de s!:testconsp (neg x env lab)
   (prog (w)
      (cond
         ((lessp (setq w (s!:islocal (cadr x) env)) 4)
            (return
               (s!:outjump
                  (getv (cond (neg s!:jumpnatoms) (t s!:jumpatoms)) w)
                  lab))))
      (s!:comval (cadr x) env 1)
      (cond
         (neg (s!:outjump 'jumpnatom lab))
         (t (s!:outjump 'jumpatom lab)))) )


(put 'consp 's!:testfn (function s!:testconsp))


(de s!:comcond (x env context)
   (prog (l1 l2 w)
      (setq l1 (gensym))
      (prog nil
   !G29  (cond ((not (setq x (cdr x))) (return nil)))
         (progn
            (setq w (car x))
            (cond
               ((atom (cdr w))
                  (progn
                     (s!:comval (car w) env 1)
                     (s!:outjump 'jumpt l1)
                     (setq l2 nil)))
               (t (progn
                     (cond
                        ((equal (car w) t) (setq l2 nil))
                        (t (progn
                              (setq l2 (gensym))
                              (s!:jumpif nil (car w) env l2))))
                     (setq w (cdr w))
                     (cond
                        ((null (cdr w)) (setq w (car w)))
                        (t (setq w (cons 'progn w))))
                     (s!:comval w env context)
                     (cond
                        (l2 (progn (s!:outjump 'jump l1) (s!:set_label l2)))
                        (t (setq x '(nil)))) ))) )
         (go !G29))
      (cond (l2 (s!:comval nil env context)))
      (s!:set_label l1)))


(put 'cond 's!:compfn (function s!:comcond))


(de s!:comif (x env context)
   (prog (l1 l2)
      (setq l2 (gensym))
      (s!:jumpif nil (cadr x) env l2)
      (setq x (cddr x))
      (s!:comval (car x) env context)
      (setq x (cdr x))
      (cond
         ((or x (and (lessp context 2) (setq x '(nil))))
            (progn
               (setq l1 (gensym))
               (s!:outjump 'jump l1)
               (s!:set_label l2)
               (s!:comval (car x) env context)
               (s!:set_label l1)))
         (t (s!:set_label l2)))) )


(put 'if 's!:compfn (function s!:comif))


(de s!:comwhen (x env context)
   (prog (l2)
      (setq l2 (gensym))
      (cond
         ((lessp context 2)
            (progn (s!:comval (cadr x) env 1) (s!:outjump 'jumpnil l2)))
         (t (s!:jumpif nil (cadr x) env l2)))
      (s!:comval (cons 'progn (cddr x)) env context)
      (s!:set_label l2)))


(put 'when 's!:compfn (function s!:comwhen))


(de s!:comunless (x env context)
   (s!:comwhen (list!* 'when (list 'not (cadr x)) (cddr x)) env context))


(put 'unless 's!:compfn (function s!:comunless))


(de s!:comicase (x env context)
   (prog (l1 labs labassoc w)
      (setq x (cdr x))
      (prog (v)
         (setq v (cdr x))
   lab   (cond ((null v) (return nil)))
         ((lambda (v)
             (progn
                (setq w (assoc!*!* v labassoc))
                (cond
                   (w (setq l1 (cons (cdr w) l1)))
                   (t (progn
                         (setq l1 (gensym))
                         (setq labs (cons l1 labs))
                         (setq labassoc (cons (cons v l1) labassoc)))) )))
            (car v))
         (setq v (cdr v))
         (go lab))
      (s!:comval (car x) env 1)
      (s!:outjump 'icase (reversip labs))
      (setq l1 (gensym))
      (prog (v)
         (setq v labassoc)
   lab   (cond ((null v) (return nil)))
         ((lambda (v)
             (progn
                (s!:set_label (cdr v))
                (s!:comval (car v) env context)
                (s!:outjump 'jump l1)))
            (car v))
         (setq v (cdr v))
         (go lab))
      (s!:set_label l1)))


(put 's!:icase 's!:compfn (function s!:comicase))


(put 'jumpliteq!* 's!:opcode (get 'jumpliteq 's!:opcode))


(put 'jumplitne!* 's!:opcode (get 'jumplitne 's!:opcode))


(de s!:jumpliteql (val lab env)
   (prog (w)
      (cond
         ((or (idp val) (s!:is_fixnum val))
            (progn
               (setq w (list 'jumpliteq!* val val))
               (s!:record_literal_for_jump w env lab)))
         (t (progn
               (s!:outopcode0 'push '(push))
               (s!:loadliteral val env)
               (s!:outopcode1 'builtin2 (get 'eql 's!:builtin2) 'eql)
               (s!:outjump 'jumpt lab)
               (flag (list lab) 's!:jumpliteql)
               (s!:outopcode0 'pop '(pop)))) )))


(de s!:casebranch (sw env dflt)
   (prog (size w w1 r g)
      (setq size (plus 4 (truncate (length sw) 2)))
      (prog nil
   !G30  (cond
            ((not
                (or
                   (equal (remainder size 2) 0)
                   (equal (remainder size 3) 0)
                   (equal (remainder size 5) 0)
                   (equal (remainder size 13) 0)))
               (return nil)))
         (setq size (plus size 1))
         (go !G30))
      (prog (p)
         (setq p sw)
   lab   (cond ((null p) (return nil)))
         ((lambda (p)
             (progn
                (setq w (remainder (eqlhash (car p)) size))
                (setq w1 (assoc!*!* w r))
                (cond
                   (w1 (rplacd (cdr w1) (cons p (cddr w1))))
                   (t (setq r (cons (list w (gensym) p) r)))) ))
            (car p))
         (setq p (cdr p))
         (go lab))
      (s!:outopcode0 'push '(push))
      (rplacd env (cons 0 (cdr env)))
      (s!:outopcode1lit 'call1 'eqlhash env)
      (s!:loadliteral size env)
      (setq g (gensym))
      (s!:outopcode1 'builtin2 (get 'iremainder 's!:builtin2) 'iremainder)
      (s!:outjump
         'icase
         (cons
            g
            (prog (i !G31 endptr)
               (setq i 0)
               (cond
                  ((minusp (difference (difference size 1) i)) (return nil)))
               (setq !G31
                  (setq endptr
                     (cons
                        (progn
                           (setq w (assoc!*!* i r))
                           (cond (w (cadr w)) (t g)))
                        nil)))
         looplabel
               (setq i (plus2 i 1))
               (cond
                  ((minusp (difference (difference size 1) i)) (return !G31)))
               (rplacd
                  endptr
                  (cons
                     (progn
                        (setq w (assoc!*!* i r))
                        (cond (w (cadr w)) (t g)))
                     nil))
               (setq endptr (cdr endptr))
               (go looplabel))))
      (prog (p)
         (setq p r)
   lab   (cond ((null p) (return nil)))
         ((lambda (p)
             (progn
                (s!:set_label (cadr p))
                (s!:outopcode0 'pop '(pop))
                (prog (q)
                   (setq q (cddr p))
             lab   (cond ((null q) (return nil)))
                   ((lambda (q) (s!:jumpliteql (car q) (cdr q) env)) (car q))
                   (setq q (cdr q))
                   (go lab))
                (s!:outjump 'jump dflt)))
            (car p))
         (setq p (cdr p))
         (go lab))
      (s!:set_label g)
      (s!:outopcode0 'pop '(pop))
      (s!:outjump 'jump dflt)
      (rplacd env (cddr env))))


(de s!:comcase (x env context)
   (prog (keyform blocks v w g dflt sw keys nonnum)
      (setq x (cdr x))
      (setq keyform (car x))
      (prog (y)
         (setq y (cdr x))
   lab   (cond ((null y) (return nil)))
         (progn
            (setq w (assoc!*!* (cdar y) blocks))
            (cond
               (w (setq g (cdr w)))
               (t (progn
                     (setq g (gensym))
                     (setq blocks (cons (cons (cdar y) g) blocks)))) )
            (setq w (caar y))
            (cond
               ((and (null (cdr y)) (or (equal w t) (equal w 'otherwise)))
                  (setq dflt g))
               (t (progn
                     (cond ((atom w) (setq w (list w))))
                     (prog (n)
                        (setq n w)
                  lab   (cond ((null n) (return nil)))
                        ((lambda (n)
                            (progn
                               (cond
                                  ((or (idp n) (numberp n))
                                     (progn
                                        (cond
                                           ((not (fixp n)) (setq nonnum t)))
                                        (setq keys (cons n keys))
                                        (setq sw (cons (cons n g) sw))))
                                  (t (error
                                        0
                                        (list "illegal case label" n)))) ))
                           (car n))
                        (setq n (cdr n))
                        (go lab)))) ))
         (setq y (cdr y))
         (go lab))
      (cond
         ((null dflt)
            (progn
               (cond
                  ((setq w (assoc!*!* nil blocks)) (setq dflt (cdr w)))
                  (t (setq blocks
                        (cons (cons nil (setq dflt (gensym))) blocks)))) )))
      (cond
         ((not nonnum)
            (progn
               (setq keys (sort keys (function lessp)))
               (setq nonnum (car keys))
               (setq g (lastcar keys))
               (cond
                  ((lessp (difference g nonnum) (times 2 (length keys)))
                     (progn
                        (cond
                           ((not (equal nonnum 0))
                              (progn
                                 (setq keyform
                                    (list 'xdifference keyform nonnum))
                                 (setq sw
                                    (prog (y !G32 endptr)
                                       (setq y sw)
                                       (cond ((null y) (return nil)))
                                       (setq !G32
                                          (setq endptr
                                             (cons
                                                ((lambda (y)
                                                    (cons
                                                       (difference
       (car y)
                                                          nonnum)
                                                       (cdr y)))
                                                   (car y))
                                                nil)))
                                 looplabel
                                       (setq y (cdr y))
                                       (cond ((null y) (return !G32)))
                                       (rplacd
                                          endptr
                                          (cons
                                             ((lambda (y)
                                                 (cons
                                                    (difference
                                                       (car y)
                                                       nonnum)
                                                    (cdr y)))
                                                (car y))
                                             nil))
                                       (setq endptr (cdr endptr))
                                       (go looplabel)))) ))
                        (s!:comval keyform env 1)
                        (setq w nil)
                        (prog (i)
                           (setq i 0)
                     lab   (cond ((minusp (difference g i)) (return nil)))
                           (cond
                              ((setq v (assoc!*!* i sw))
                                 (setq w (cons (cdr v) w)))
                              (t (setq w (cons dflt w))))
                           (setq i (plus2 i 1))
                           (go lab))
                        (setq w (cons dflt (reversip w)))
                        (s!:outjump 'icase w)
                        (setq nonnum nil)))
                  (t (setq nonnum t)))) ))
      (cond
         (nonnum
            (progn
               (s!:comval keyform env 1)
               (cond
                  ((lessp (length sw) 7)
                     (progn
                        (prog (y)
                           (setq y sw)
                     lab   (cond ((null y) (return nil)))
                           ((lambda (y) (s!:jumpliteql (car y) (cdr y) env))
                              (car y))
                           (setq y (cdr y))
                           (go lab))
                        (s!:outjump 'jump dflt)))
                  (t (s!:casebranch sw env dflt)))) ))
      (setq g (gensym))
      (prog (v)
         (setq v blocks)
   lab   (cond ((null v) (return nil)))
         ((lambda (v)
             (progn
                (s!:set_label (cdr v))
                (cond ((flagp (cdr v) 's!:jumpliteql) (s!:outlose 1)))
                (s!:comval (cons 'progn (car v)) env context)
                (s!:outjump 'jump g)))
            (car v))
         (setq v (cdr v))
         (go lab))
      (s!:set_label g)))


(put 'case 's!:compfn (function s!:comcase))


(fluid '(!*defn dfprint!* s!:dfprintsave s!:faslmod_name))


(de s!:comeval!-when (x env context)
   (prog (y)
      (setq x (cdr x))
      (setq y (car x))
      (setq x (cons 'progn (cdr x)))
      (cond ((memq 'compile y) (eval x)))
      (cond ((memq 'load y) (progn (cond (dfprint!* (apply1 dfprint!* x)))) ))
      (cond
         ((memq 'eval y) (s!:comval x env context))
         (t (s!:comval nil env context)))) )


(put 'eval!-when 's!:compfn (function s!:comeval!-when))


(de s!:comthe (x env context) (s!:comval (caddr x) env context))


(put 'the 's!:compfn (function s!:comthe))


(de s!:comand (x env context)
   (prog (l)
      (setq l (gensym))
      (setq x (cdr x))
      (s!:comval (car x) env 1)
      (prog nil
   !G33  (cond ((not (setq x (cdr x))) (return nil)))
         (progn (s!:outjump 'jumpnil l) (s!:comval (car x) env 1))
         (go !G33))
      (s!:set_label l)))


(put 'and 's!:compfn (function s!:comand))


(de s!:comor (x env context)
   (prog (l)
      (setq l (gensym))
      (setq x (cdr x))
      (s!:comval (car x) env 1)
      (prog nil
   !G34  (cond ((not (setq x (cdr x))) (return nil)))
         (progn (s!:outjump 'jumpt l) (s!:comval (car x) env 1))
         (go !G34))
      (s!:set_label l)))


(put 'or 's!:compfn (function s!:comor))


(de s!:combool (neg x env lab)
   (prog (fn)
      (setq fn (eqcar x 'or))
      (cond
         ((eq fn neg)
            (prog nil
         !G35  (cond ((not (setq x (cdr x))) (return nil)))
               (s!:jumpif fn (car x) env lab)
               (go !G35)))
         (t (progn
               (setq neg (gensym))
               (prog nil
            !G36  (cond ((not (setq x (cdr x))) (return nil)))
                  (s!:jumpif fn (car x) env neg)
                  (go !G36))
               (s!:outjump 'jump lab)
               (s!:set_label neg)))) ))


(put 'and 's!:testfn (function s!:combool))


(put 'or 's!:testfn (function s!:combool))


(de s!:testeq (neg x env lab)
   (prog (a b)
      (setq a (cadr x))
      (setq b (caddr x))
      (cond
         ((null a) (s!:jumpif (not neg) b env lab))
         ((null b) (s!:jumpif (not neg) a env lab))
         ((or (eqcar a 'quote) (and (atom a) (not (symbolp a))))
            (progn
               (s!:comval b env 1)
               (cond ((eqcar a 'quote) (setq a (cadr a))))
               (setq b (list (cond (neg 'jumpliteq) (t 'jumplitne)) a a))
               (s!:record_literal_for_jump b env lab)))
         ((or (eqcar b 'quote) (and (atom b) (not (symbolp b))))
            (progn
               (s!:comval a env 1)
               (cond ((eqcar b 'quote) (setq b (cadr b))))
               (setq a (list (cond (neg 'jumpliteq) (t 'jumplitne)) b b))
               (s!:record_literal_for_jump a env lab)))
         (t (progn
               (s!:load2 a b env)
               (cond
                  (neg (s!:outjump 'jumpeq lab))
                  (t (s!:outjump 'jumpne lab)))) ))) )


(put 'eq 's!:testfn (function s!:testeq))


(de s!:is_fixnum (x)
   (and (fixp x) (geq x (minus 134217728)) (leq x 134217727)))


(de s!:testequal (neg x env lab)
   (prog (a b)
      (setq a (cadr x))
      (setq b (caddr x))
      (cond
         ((null a) (s!:jumpif (not neg) b env lab))
         ((null b) (s!:jumpif (not neg) a env lab))
         ((or
             (and (eqcar a 'quote) (symbolp (cadr a)))
             (and (eqcar b 'quote) (symbolp (cadr b)))
             (s!:is_fixnum a)
             (s!:is_fixnum b))
            (s!:testeq neg x env lab))
         (t (progn
               (s!:load2 a b env)
               (cond
                  (neg (s!:outjump 'jumpequal lab))
                  (t (s!:outjump 'jumpnequal lab)))) ))) )


(put 'equal 's!:testfn (function s!:testequal))


(de s!:testneq (neg x env lab) (s!:testequal (not neg) x env lab))


(put 'neq 's!:testfn (function s!:testneq))


(de s!:testeqcar (neg x env lab)
   (prog (a b sw)
      (setq a (cadr x))
      (setq b (caddr x))
      (cond
         ((eqcar b 'quote)
            (progn
               (s!:comval a env 1)
               (setq b (cadr b))
               (setq a (list (cond (neg 'jumpeqcar) (t 'jumpneqcar)) b b))
               (s!:record_literal_for_jump a env lab)))
         (t (progn
               (setq sw (s!:load2 a b env))
               (cond (sw (s!:outopcode0 'swop '(swop))))
               (s!:outopcode0 'eqcar '(eqcar))
               (s!:outjump (cond (neg 'jumpt) (t 'jumpnil)) lab)))) ))


(put 'eqcar 's!:testfn (function s!:testeqcar))


(de s!:testflagp (neg x env lab)
   (prog (a b sw)
      (setq a (cadr x))
      (setq b (caddr x))
      (cond
         ((eqcar b 'quote)
            (progn
               (s!:comval a env 1)
               (setq b (cadr b))
               (setq sw (symbol!-make!-fastget b nil))
               (cond
                  (sw
                     (progn
                        (s!:outopcode1 'fastget (logor sw 128) b)
                        (s!:outjump (cond (neg 'jumpt) (t 'jumpnil)) lab)))
                  (t (progn
                        (setq a
                           (list (cond (neg 'jumpflagp) (t 'jumpnflagp)) b b))
                        (s!:record_literal_for_jump a env lab)))) ))
         (t (progn
               (setq sw (s!:load2 a b env))
               (cond (sw (s!:outopcode0 'swop '(swop))))
               (s!:outopcode0 'flagp '(flagp))
               (s!:outjump (cond (neg 'jumpt) (t 'jumpnil)) lab)))) ))


(put 'flagp 's!:testfn (function s!:testflagp))


(global '(s!:storelocs))


(setq s!:storelocs
   (s!:vecof
      '(storeloc0 storeloc1 storeloc2 storeloc3 storeloc4 storeloc5 storeloc6
          storeloc7)))


(de s!:comsetq (x env context)
   (prog (n w var)
      (setq x (cdr x))
      (cond ((null x) (return nil)))
      (cond
         ((or (not (symbolp (car x))) (null (cdr x)))
            (return (error 0 (list "bad args for setq" x)))) )
      (s!:comval (cadr x) env 1)
      (setq var (car x))
      (setq n 0)
      (setq w (cdr env))
      (prog nil
   !G37  (cond ((not (and w (not (eqcar w var)))) (return nil)))
         (progn (setq n (add1 n)) (setq w (cdr w)))
         (go !G37))
      (cond
         (w
            (progn
               (cond
                  ((not (member!*!* (cons 'loc w) s!:a_reg_values))
                     (setq s!:a_reg_values
                        (cons (cons 'loc w) s!:a_reg_values))))
               (cond
                  ((lessp n 8)
                     (s!:outopcode0
                        (getv s!:storelocs n)
                        (list 'storeloc var)))
                  ((greaterp n 4095) (error "stack frame > 4095"))
                  ((greaterp n 255)
                     (s!:outopcode2
                        'bigstack
                        (plus 64 (truncate n 256))
                        (logand n 255)
                        (list 'storeloc var)))
                  (t (s!:outopcode1 'storeloc n var)))) )
         ((setq w (s!:find_lexical var s!:lexical_env 0))
            (progn
               (cond
                  ((not (member!*!* (cons 'lex w) s!:a_reg_values))
                     (setq s!:a_reg_values
                        (cons (cons 'lex w) s!:a_reg_values))))
               (s!:outlexref 'storelex (length (cdr env)) (car w) (cadr w)
                  var)))
         (t (progn
               (cond
                  ((or (null var) (eq var t))
                     (error 0 (list "bad variable in setq" var)))
                  (t (s!:should_be_fluid var)))
               (setq w (cons 'free var))
               (cond
                  ((not (member!*!* w s!:a_reg_values))
                     (setq s!:a_reg_values (cons w s!:a_reg_values))))
               (s!:outopcode1lit 'storefree var env))))
      (cond ((cddr x) (return (s!:comsetq (cdr x) env context)))) ))


(put 'setq 's!:compfn (function s!:comsetq))


(put 'noisy!-setq 's!:compfn (function s!:comsetq))


(de s!:comlist (x env context)
   (prog (w)
      (cond ((null (setq x (cdr x))) (return (s!:comval nil env context))))
      (setq s!:a_reg_values nil)
      (cond
         ((null (setq w (cdr x)))
            (s!:comval (list 'ncons (car x)) env context))
         ((null (setq w (cdr w)))
            (s!:comval (list 'list2 (car x) (cadr x)) env context))
         ((null (cdr w))
            (s!:comval (list 'list3 (car x) (cadr x) (car w)) env context))
         (t (s!:comval
               (list 'list2!* (car x) (cadr x) (cons 'list w))
               env
               context)))) )


(put 'list 's!:compfn (function s!:comlist))


(de s!:comlist!* (x env context)
   (prog (w)
      (cond ((null (setq x (cdr x))) (return (s!:comval nil env context))))
      (setq s!:a_reg_values nil)
      (cond
         ((null (setq w (cdr x))) (s!:comval (car x) env context))
         ((null (setq w (cdr w)))
            (s!:comval (list 'cons (car x) (cadr x)) env context))
         ((null (cdr w))
            (s!:comval (list 'list2!* (car x) (cadr x) (car w)) env context))
         (t (s!:comval
               (list 'list2!* (car x) (cadr x) (cons 'list!* w))
               env
               context)))) )


(put 'list!* 's!:compfn (function s!:comlist!*))


(de s!:comcons (x env context)
   (prog (a b)
      (setq a (cadr x))
      (setq b (caddr x))
      (cond
         ((or (equal b nil) (equal b ''nil))
            (s!:comval (list 'ncons a) env context))
         ((eqcar a 'cons)
            (s!:comval (list 'acons (cadr a) (caddr a) b) env context))
         ((eqcar b 'cons)
            (cond
               ((null (caddr b))
                  (s!:comval (list 'list2 a (cadr b)) env context))
               (t (s!:comval
                     (list 'list2!* a (cadr b) (caddr b))
                     env
                     context))))
         ((and (s!:iseasy a) (not (s!:iseasy b)))
            (s!:comval (list 'xcons b a) env context))
         (t (s!:comcall x env context)))) )


(put 'cons 's!:compfn (function s!:comcons))


(de s!:comapply (x env context)
   (prog (a b n)
      (setq a (cadr x))
      (setq b (caddr x))
      (cond
         ((and (null (cdddr x)) (eqcar b 'list))
            (progn
               (cond
                  ((eqcar a 'quote)
                     (return
                        (prog (s!:current_function)
                           (setq s!:current_function (gensym))
                           (return
                              (s!:comval
                                 (cons (cadr a) (cdr b))
                                 env
                                 context)))) ))
               (setq n (length (setq b (cdr b))))
               (return (s!:comval (cons 'funcall (cons a b)) env context))))
         ((and (null b) (null (cdddr x)))
            (return (s!:comval (list 'funcall a) env context)))
         (t (return (s!:comcall x env context)))) ))


(put 'apply 's!:compfn (function s!:comapply))


(de s!:imp_funcall (u)
   (prog (n)
      (setq u (cdr u))
      (cond
         ((eqcar (car u) 'function)
            (return (s!:improve (cons (cadar u) (cdr u)))) ))
      (setq n (length (cdr u)))
      (setq u
         (cond
            ((equal n 0) (cons 'apply0 u))
            ((equal n 1) (cons 'apply1 u))
            ((equal n 2) (cons 'apply2 u))
            ((equal n 3) (cons 'apply3 u))
            (t (cons 'funcall!* u))))
      (return u)))


(put 'funcall 's!:tidy_fn 's!:imp_funcall)


(de s!:certainlyatom (x)
   (or
      (null x)
      (equal x t)
      (s!:is_fixnum x)
      (and
         (eqcar x 'quote)
         (or (symbolp (cadr x)) (s!:is_fixnum (cadr x)))) ))


(de s!:atomlist1 (u)
   (or
      (atom u)
      (and
         (or (symbolp (car u)) (s!:is_fixnum (car u)))
         (s!:atomlist1 (cdr u)))) )


(de s!:atomlist (x)
   (or
      (null x)
      (and (eqcar x 'quote) (s!:atomlist1 (cadr x)))
      (and
         (eqcar x 'list)
         (or
            (null (cdr x))
            (and
               (s!:certainlyatom (cadr x))
               (s!:atomlist (cons 'list (cddr x)))) ))
      (and
         (eqcar x 'cons)
         (s!:certainlyatom (cadr x))
         (s!:atomlist (caddr x)))) )


(de s!:atomcar (x)
   (and
      (or (eqcar x 'cons) (eqcar x 'list))
      (not (null (cdr x)))
      (s!:certainlyatom (cadr x))))


(de s!:atomkeys1 (u)
   (or
      (atom u)
      (and
         (not (atom (car u)))
         (or (symbolp (caar u)) (s!:is_fixnum (caar u)))
         (s!:atomkeys1 (cdr u)))) )


(de s!:atomkeys (x)
   (or
      (null x)
      (and (eqcar x 'quote) (s!:atomkeys1 (cadr x)))
      (and
         (eqcar x 'list)
         (or
            (null (cdr x))
            (and (s!:atomcar (cadr x)) (s!:atomkeys (cons 'list (cddr x)))) ))
      (and (eqcar x 'cons) (s!:atomcar (cadr x)) (s!:atomkeys (caddr x)))) )


(de s!:comsublis (x env context)
   (cond
      ((s!:atomkeys (cadr x)) (s!:comval (cons 'subla (cdr x)) env context))
      (t (s!:comcall x env context))))


(put 'sublis 's!:compfn (function s!:comsublis))


(de s!:comassoc (x env context)
   (cond
      ((and
          (or (s!:certainlyatom (cadr x)) (s!:atomkeys (caddr x)))
          (equal (length x) 3))
         (s!:comval (cons 'atsoc (cdr x)) env context))
      ((equal (length x) 3)
         (s!:comcall (cons 'assoc!*!* (cdr x)) env context))
      (t (s!:comcall x env context))))


(put 'assoc 's!:compfn (function s!:comassoc))


(put 'assoc!*!* 's!:compfn (function s!:comassoc))


(de s!:commember (x env context)
   (cond
      ((and
          (or (s!:certainlyatom (cadr x)) (s!:atomlist (caddr x)))
          (equal (length x) 3))
         (s!:comval (cons 'memq (cdr x)) env context))
      (t (s!:comcall x env context))))


(put 'member 's!:compfn (function s!:commember))


(put 'member!*!* 's!:compfn (function s!:commember))


(de s!:comdelete (x env context)
   (cond
      ((and
          (or (s!:certainlyatom (cadr x)) (s!:atomlist (caddr x)))
          (equal (length x) 3))
         (s!:comval (cons 'deleq (cdr x)) env context))
      (t (s!:comcall x env context))))


(put 'delete 's!:compfn (function s!:comdelete))


(de s!:commap (fnargs env context)
   (prog (carp fn fn1 args var avar moveon l1 r s closed)
      (setq fn (car fnargs))
      (cond
         ((greaterp context 1)
            (progn
               (cond
                  ((equal fn 'mapcar) (setq fn 'mapc))
                  ((equal fn 'maplist) (setq fn 'map)))) ))
      (cond
         ((or (equal fn 'mapc) (equal fn 'mapcar) (equal fn 'mapcan))
            (setq carp t)))
      (setq fnargs (cdr fnargs))
      (cond ((atom fnargs) (error 0 "bad arguments to map function")))
      (setq fn1 (cadr fnargs))
      (prog nil
   !G38  (cond
            ((not
                (or
                   (eqcar fn1 'function)
                   (and (eqcar fn1 'quote) (eqcar (cadr fn1) 'lambda))))
               (return nil)))
         (progn (setq fn1 (cadr fn1)) (setq closed t))
         (go !G38))
      (setq args (car fnargs))
      (setq l1 (gensym))
      (setq r (gensym))
      (setq s (gensym))
      (setq var (gensym))
      (setq avar var)
      (cond (carp (setq avar (list 'car avar))))
      (cond
         (closed (setq fn1 (list fn1 avar)))
         (t (setq fn1 (list 'funcall fn1 avar))))
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
                     (cons 'l2 (gensym))
                     (cons 'var var)
                     (cons 'fn fn1)
                     (cons 'args args)
                     (cons 'moveon moveon)
                     (cons 'r (gensym))
                     (cons 's (gensym)))
                  '(prog (var r s)
                      (setq var args)
                      (setq r (setq s (list nil)))
                l1    (cond ((not var) (return (cdr r))))
                      (rplacd s fn)
                l2    (cond ((not (atom (cdr s))) (setq s (cdr s)) (go l2)))
                moveon(go l1)))) ))
      (s!:comval fn env context)))


(put 'map 's!:compfn (function s!:commap))


(put 'maplist 's!:compfn (function s!:commap))


(put 'mapc 's!:compfn (function s!:commap))


(put 'mapcar 's!:compfn (function s!:commap))


(put 'mapcon 's!:compfn (function s!:commap))


(put 'mapcan 's!:compfn (function s!:commap))


(de s!:nilargs (use)
   (cond
      ((null use) t)
      ((or (equal (car use) 'nil) (equal (car use) ''nil))
         (s!:nilargs (cdr use)))
      (t nil)))


(de s!:subargs (args use)
   (cond
      ((null use) t)
      ((null args) (s!:nilargs use))
      ((not (equal (car args) (car use))) nil)
      (t (s!:subargs (cdr args) (cdr use)))) )


(fluid '(!*where_defined!*))


(de clear_source_database nil
   (progn (setq !*where_defined!* (mkhash 10 2 1.5)) nil))


(de load_source_database (filename)
   (prog (a b)
      (clear_source_database)
      (setq a (open filename 'input))
      (cond ((null a) (return nil)))
      (setq a (rds a))
      (prog nil
   !G39  (cond ((not (setq b (read))) (return nil)))
         (puthash (car b) !*where_defined!* (cdr b))
         (go !G39))
      (close (rds a))
      (return nil)))


(de save_source_database (filename)
   (prog (a)
      (setq a (open filename 'output))
      (cond ((null a) (return nil)))
      (setq a (wrs a))
      (prog (z)
         (setq z (sort (hashcontents !*where_defined!*) (function orderp)))
   lab   (cond ((null z) (return nil)))
         ((lambda (z) (progn (prin z) (terpri))) (car z))
         (setq z (cdr z))
         (go lab))
      (princ nil)
      (terpri)
      (wrs a)
      (setq !*where_defined!* nil)
      (return nil)))


(de display_source_database nil
   (prog (w)
      (cond ((null !*where_defined!*) (return nil)))
      (setq w (hashcontents !*where_defined!*))
      (setq w (sort w (function orderp)))
      (terpri)
      (prog (x)
         (setq x w)
   lab   (cond ((null x) (return nil)))
         ((lambda (x)
             (progn (princ (car x)) (ttab 40) (prin (cdr x)) (terpri)))
            (car x))
         (setq x (cdr x))
         (go lab))))


(de s!:compile1 (name args body s!:lexical_env)
   (prog (w aargs oargs oinit restarg svars nargs nopts env fluids
         s!:current_function
         s!:current_label
         s!:current_block
         s!:current_size
         s!:current_procedure
         s!:current_exitlab
         s!:current_proglabels
         s!:other_defs
         local_decs
         s!:has_closure s!:local_macros s!:recent_literals s!:a_reg_values w1
         w2)
      (setq s!:current_function name)
      (cond
         (!*where_defined!*
            (progn
               (setq w name)
               (puthash w !*where_defined!* (where!-was!-that)))) )
      (setq body (s!:find_local_decs body))
      (setq local_decs (car body))
      (setq body (cdr body))
      (cond
         ((atom body) (setq body nil))
         ((null (cdr body)) (setq body (car body)))
         (t (setq body (cons 'progn body))))
      (setq nargs (setq nopts 0))
      (prog nil
   !G40  (cond
            ((not
                (and
                   args
                   (not (eqcar args '!&optional))
                   (not (eqcar args '!&rest))))
               (return nil)))
         (progn
            (cond
               ((or (equal (car args) '!&key) (equal (car args) '!&aux))
                  (error 0 "&key/&aux")))
            (setq aargs (cons (car args) aargs))
            (setq nargs (plus nargs 1))
            (setq args (cdr args)))
         (go !G40))
      (cond
         ((eqcar args '!&optional)
            (progn
               (setq args (cdr args))
               (prog nil
            !G41  (cond
                     ((not (and args (not (eqcar args '!&rest))))
                        (return nil)))
                  (progn
                     (cond
                        ((or
                            (equal (car args) '!&key)
                            (equal (car args) '!&aux))
                           (error 0 "&key/&aux")))
                     (setq w (car args))
                     (prog nil
                  !G42  (cond
                           ((not
                               (and
                                  (not (atom w))
                                  (or
                                     (atom (cdr w))
                                     (equal (cdr w) '(nil)))) )
                              (return nil)))
                        (setq w (car w))
                        (go !G42))
                     (setq args (cdr args))
                     (setq oargs (cons w oargs))
                     (setq nopts (plus nopts 1))
                     (cond
                        ((atom w) (setq aargs (cons w aargs)))
                        (t (progn
                              (setq oinit t)
                              (setq aargs (cons (car w) aargs))
                              (cond
                                 ((not (atom (cddr w)))
                                    (setq svars
                                       (cons (caddr w) svars)))) ))) )
                  (go !G41)))) )
      (cond
         ((eqcar args '!&rest)
            (progn
               (setq w (cadr args))
               (setq aargs (cons w aargs))
               (setq restarg w)
               (setq args (cddr args))
               (cond (args (error 0 "&rest arg not at end")))) ))
      (setq args (reverse aargs))
      (setq oargs (reverse oargs))
      (prog (v)
         (setq v (append svars args))
   lab   (cond ((null v) (return nil)))
         ((lambda (v)
             (progn
                (cond
                   ((globalp v)
                      (progn
                         (cond
                            (!*pwrds
                               (progn
                                  (cond ((neq (posn) 0) (terpri)))
                                  (princ "+++++ global ")
                                  (prin v)
                                  (princ " converted to fluid")
                                  (terpri))))
                         (unglobal (list v))
                         (fluid (list v)))) )))
            (car v))
         (setq v (cdr v))
         (go lab))
      (cond
         (oinit
            (return
               (s!:compile2 name nargs nopts args oargs restarg body
                  local_decs))))
      (setq w nil)
      (prog (v)
         (setq v args)
   lab   (cond ((null v) (return nil)))
         ((lambda (v) (setq w (s!:instate_local_decs v local_decs w)))
            (car v))
         (setq v (cdr v))
         (go lab))
      (prog (v)
         (setq v args)
   lab   (cond ((null v) (return nil)))
         (progn
            (cond
               ((fluidp (car v))
                  (prog (g)
                     (setq g (gensym))
                     (setq fluids (cons (cons (car v) g) fluids))
                     (rplaca v g)))) )
         (setq v (cdr v))
         (go lab))
      (cond
         (fluids
            (progn
               (setq body (list (list 'return body)))
               (prog (v)
                  (setq v fluids)
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
                        (prog (v !G43 endptr)
                           (setq v fluids)
                           (cond ((null v) (return nil)))
                           (setq !G43
                              (setq endptr
                                 (cons ((lambda (v) (car v)) (car v)) nil)))
                     looplabel
                           (setq v (cdr v))
                           (cond ((null v) (return !G43)))
                           (rplacd
                              endptr
                              (cons ((lambda (v) (car v)) (car v)) nil))
                           (setq endptr (cdr endptr))
                           (go looplabel))
                        body)))) ))
      (setq env
         (cons
            (mkhash 10 (cond (s!:faslmod_name 2) (t 1)) 1.5)
            (reverse args)))
      (puthash name (car env) (cons 10000000 nil))
      (setq w (s!:residual_local_decs local_decs w))
      (s!:start_procedure nargs nopts restarg)
      (setq w1 body)
more  (cond
         ((atom w1) nil)
         ((and (equal (car w1) 'block) (equal (length w1) 3))
            (progn (setq w1 (caddr w1)) (go more)))
         ((and (equal (car w1) 'progn) (equal (length w1) 2))
            (progn (setq w1 (cadr w1)) (go more)))
         ((and (atom (setq w2 (car w1))) (setq w2 (get w2 's!:newname)))
            (progn (setq w1 (cons w2 (cdr w1))) (go more)))
         ((and (atom (setq w2 (car w1))) (setq w2 (macro!-function w2)))
            (progn (setq w1 (funcall w2 w1)) (go more))))
      (cond
         ((not (equal (setq w2 (s!:improve w1)) w1))
            (progn (setq w1 w2) (go more))))
      (cond
         ((and
             (not (atom w1))
             (atom (car w1))
             (not (special!-form!-p (car w1)))
             (s!:subargs args (cdr w1))
             (leq nargs 3)
             (equal nopts 0)
             (not restarg)
             (leq (length (cdr w1)) nargs))
            (progn
               (s!:cancel_local_decs w)
               (cond (restarg (setq nopts (plus nopts 512))))
               (setq nopts (plus nopts (times 1024 (length w1))))
               (setq nargs (plus nargs (times 256 nopts)))
               (cond
                  (!*pwrds
                     (progn
                        (cond ((neq (posn) 0) (terpri)))
                        (princ "+++ ")
                        (prin name)
                        (princ " compiled as link to ")
                        (princ (car w1))
                        (terpri))))
               (return
                  (cons
                     (cons name (cons nargs (cons nil (car w1))))
                     s!:other_defs)))) )
      (s!:comval body env 0)
      (s!:cancel_local_decs w)
      (cond (restarg (setq nopts (plus nopts 512))))
      (setq nargs (plus nargs (times 256 nopts)))
      (return
         (cons
            (cons name (cons nargs (s!:endprocedure name env)))
            s!:other_defs))))


(de s!:compile2 (name nargs nopts args oargs restarg body local_decs)
   (prog (fluids env penv g v init atend w)
      (prog (v)
         (setq v args)
   lab   (cond ((null v) (return nil)))
         ((lambda (v)
             (progn (setq env (cons 0 env)) (setq penv (cons env penv))))
            (car v))
         (setq v (cdr v))
         (go lab))
      (setq env (cons (mkhash 10 (cond (s!:faslmod_name 2) (t 1)) 1.5) env))
      (puthash name (car env) (cons 10000000 nil))
      (setq penv (reversip penv))
      (cond (restarg (setq oargs (append oargs '(0)))) )
      (prog (i)
         (setq i 1)
   lab   (cond ((minusp (difference nargs i)) (return nil)))
         (setq oargs (cons 0 oargs))
         (setq i (plus2 i 1))
         (go lab))
      (s!:start_procedure nargs nopts restarg)
      (prog nil
   !G44  (cond ((not args) (return nil)))
         (progn
            (setq v (car args))
            (setq init (car oargs))
            (cond
               ((equal init 0)
                  (progn
                     (setq w (s!:instate_local_decs v local_decs w))
                     (cond
                        ((fluidp v)
                           (progn
                              (setq g (gensym))
                              (rplaca (car penv) g)
                              (s!:outopcode1lit
                                 'freebind
                                 (s!:vecof (list v))
                                 env)
                              (rplacd
                                 env
                                 (cons 3 (cons 0 (cons 0 (cdr env)))) )
                              (setq atend (cons 'freerstr atend))
                              (s!:comval (list 'setq v g) env 2)))
                        (t (rplaca (car penv) v)))) )
               (t (prog (ival sp l1 l2)
                     (cond
                        ((not (atom init))
                           (progn
                              (setq init (cdr init))
                              (setq ival (car init))
                              (cond
                                 ((not (atom (cdr init)))
                                    (setq sp (cadr init)))) )))
                     (setq l1 (gensym))
                     (setq g (gensym))
                     (rplaca (car penv) g)
                     (cond
                        ((and (null ival) (null sp))
                           (s!:comval
                              (list 'setq g (list 'spid!-to!-nil g))
                              env
                              1))
                        (t (progn
                              (s!:jumpif nil (list 'is!-spid g) env l1)
                              (s!:comval (list 'setq g ival) env 1)
                              (cond
                                 (sp
                                    (progn
                                       (cond
                                          ((fluidp sp)
                                             (progn
                                                (s!:outopcode1lit
                                                   'freebind
                                                   (s!:vecof (list sp))
                                                   env)
                                                (s!:outjump
                                                   'jump
                                                   (setq l2 (gensym)))
                                                (s!:set_label l1)
                                                (s!:outopcode1lit
                                                   'freebind
                                                   (s!:vecof (list sp))
                                                   env)
                                                (rplacd
                                                   env
                                                   (cons
                                                      3
                                                      (cons
                                                         0
       (cons 0 (cdr env)))) )
                                                (s!:comval (list 'setq sp t) env 1)
                                                (s!:set_label l2)
                                                (setq atend
                                                   (cons 'freerstr atend))))
                                          (t (progn
                                                (s!:outopcode0
                                                   'pushnil
                                                   '(pushnil))
                                                (s!:outjump
                                                   'jump
                                                   (setq l2 (gensym)))
                                                (s!:set_label l1)
                                                (s!:loadliteral t env)
                                                (s!:outopcode0 'push '(push))
                                                (s!:set_label l2)
                                                (rplacd
                                                   env
                                                   (cons sp (cdr env)))
                                                (setq atend
                                                   (cons 'lose atend)))) )))
                                 (t (s!:set_label l1)))) ))
                     (setq w (s!:instate_local_decs v local_decs w))
                     (cond
                        ((fluidp v)
                           (progn
                              (s!:outopcode1lit
                                 'freebind
                                 (s!:vecof (list v))
                                 env)
                              (rplacd
                                 env
                                 (cons 3 (cons 0 (cons 0 (cdr env)))) )
                              (s!:comval (list 'setq v g) env 1)
                              (setq atend (cons 'freerstr atend))))
                        (t (rplaca (car penv) v)))) ))
            (setq args (cdr args))
            (setq oargs (cdr oargs))
            (setq penv (cdr penv)))
         (go !G44))
      (setq w (s!:residual_local_decs local_decs w))
      (s!:comval body env 0)
      (prog nil
   !G45  (cond ((not atend) (return nil)))
         (progn
            (s!:outopcode0 (car atend) (list (car atend)))
            (setq atend (cdr atend)))
         (go !G45))
      (s!:cancel_local_decs w)
      (setq nopts (plus nopts 256))
      (cond (restarg (setq nopts (plus nopts 512))))
      (setq nargs (plus nargs (times 256 nopts)))
      (return
         (cons
            (cons name (cons nargs (s!:endprocedure name env)))
            s!:other_defs))))


(de compile!-all nil
   (prog (x)
      (setq x (oblist))
lab   (cond ((null x) (return nil)))
      ((lambda (x)
          (prog (w)
             (setq w (getd x))
             (cond
                ((and
                    (or (eqcar w 'expr) (eqcar w 'macro))
                    (eqcar (cdr w) 'lambda))
                   (progn
                      (princ "Compile: ")
                      (prin x)
                      (terpri)
                      (errorset (list 'compile (mkquote (list x))) t t)))) ))
         (car x))
      (setq x (cdr x))
      (go lab)))


(flag
   '(rds deflist flag fluid global remprop remflag unfluid unglobal dm
       defmacro carcheck faslend c_end)
   'eval)


(flag '(rds) 'ignore)


(fluid '(!*backtrace))


(de s!:fasl_supervisor nil
   (prog (u w !*echo)
top   (setq u (errorset '(read) t !*backtrace))
      (cond ((atom u) (return nil)))
      (setq u (car u))
      (cond ((equal u !$eof!$) (return nil)))
      (cond ((not (atom u)) (setq u (macroexpand u))))
      (cond
         ((atom u) (go top))
         ((eqcar u 'faslend) (return (apply 'faslend nil)))
         ((eqcar u 'rdf)
            (progn
               (setq w (open (setq u (eval (cadr u))) 'input))
               (cond
                  (w
                     (progn (terpri) (princ "Reading file ") (prin u) (terpri)
                        (setq w (rds w))
                        (s!:fasl_supervisor)
                        (princ "End of file ")
                        (prin u)
                        (terpri)
                        (close (rds w))))
                  (t (progn
                        (princ "Failed to open file ")
                        (prin u)
                        (terpri)))) ))
         (t (s!:fslout0 u)))
      (go top)))


(de s!:fslout0 (u) (s!:fslout1 u nil))


(de s!:fslout1 (u loadonly)
   (prog nil
      (cond ((not (atom u)) (setq u (macroexpand u))))
      (cond
         ((atom u) (return nil))
         ((eqcar u 'progn)
            (progn
               (prog (v)
                  (setq v (cdr u))
            lab   (cond ((null v) (return nil)))
                  ((lambda (v) (s!:fslout1 v loadonly)) (car v))
                  (setq v (cdr v))
                  (go lab))
               (return nil)))
         ((eqcar u 'eval!-when)
            (return
               (prog (w)
                  (setq w (cadr u))
                  (setq u (cons 'progn (cddr u)))
                  (cond ((and (memq 'compile w) (not loadonly)) (eval u)))
                  (cond ((memq 'load w) (s!:fslout1 u t)))
                  (return nil))))
         ((or
             (flagp (car u) 'eval)
             (and
                (equal (car u) 'setq)
                (not (atom (caddr u)))
                (flagp (caaddr u) 'eval)))
            (cond ((not loadonly) (errorset u t !*backtrace)))) )
      (cond
         ((eqcar u 'rdf)
            (prog (w)
               (setq w (open (setq u (eval (cadr u))) 'input))
               (cond
                  (w
                     (progn
                        (princ "Reading file ")
                        (prin u)
                        (terpri)
                        (setq w (rds w))
                        (s!:fasl_supervisor)
                        (princ "End of file ")
                        (prin u)
                        (terpri)
                        (close (rds w))))
                  (t (progn
                        (princ "Failed to open file ")
                        (prin u)
                        (terpri)))) ))
         ((or (eqcar u 'de) (eqcar u 'defun))
            (progn
               (setq u (cdr u))
               (prog (p)
                  (setq p (s!:compile1 (car u) (cadr u) (cddr u) nil))
            lab   (cond ((null p) (return nil)))
                  ((lambda (p) (s!:fslout2 p u)) (car p))
                  (setq p (cdr p))
                  (go lab))))
         ((or (eqcar u 'dm) (eqcar u 'defmacro))
            (prog (w g)
               (setq g (dated!-name (cadr u)))
               (setq u (cdr u))
               (setq w (cadr u))
               (cond
                  ((and w (null (cdr w)))
                     (setq w
                        (cons
                           (car w)
                           (cons '!&optional (cons (gensym) nil)))) ))
               (prog (p)
                  (setq p (s!:compile1 g w (cddr u) nil))
            lab   (cond ((null p) (return nil)))
                  ((lambda (p) (s!:fslout2 p u)) (car p))
                  (setq p (cdr p))
                  (go lab))
               (write!-module
                  (list 'dm (car u) '(u !&optional e) (list g 'u 'e)))) )
         ((eqcar u 'putd)
            (prog (a1 a2 a3)
               (setq a1 (cadr u))
               (setq a2 (caddr u))
               (setq a3 (cadddr u))
               (cond
                  ((and
                      (eqcar a1 'quote)
                      (or (equal a2 ''expr) (equal a2 ''macro))
                      (or (eqcar a3 'quote) (eqcar a3 'function))
                      (eqcar (cadr a3) 'lambda))
                     (progn
                        (setq a1 (cadr a1))
                        (setq a2 (cadr a2))
                        (setq a3 (cadr a3))
                        (setq u
                           (cons
                              (cond ((equal a2 'expr) 'de) (t 'dm))
                              (cons a1 (cdr a3))))
                        (s!:fslout1 u loadonly)))
                  (t (write!-module u)))) )
         ((and (not (eqcar u 'faslend)) (not (eqcar u 'carcheck)))
            (write!-module u)))) )


(de s!:fslout2 (p u)
   (prog (name nargs code env w)
      (setq name (car p))
      (setq nargs (cadr p))
      (setq code (caddr p))
      (setq env (cdddr p))
      (cond
         ((and !*savedef (equal name (car u)))
            (progn
               (define!-in!-module (minus 1))
               (write!-module (cons 'lambda (cdr u)))) ))
      (setq w (irightshift nargs 18))
      (setq nargs (logand nargs 262143))
      (cond ((not (equal w 0)) (setq code (difference w 1))))
      (define!-in!-module nargs)
      (write!-module name)
      (write!-module code)
      (write!-module env)))


(de faslend nil
   (prog nil
      (cond ((null s!:faslmod_name) (return nil)))
      (start!-module nil)
      (setq dfprint!* s!:dfprintsave)
      (setq !*defn nil)
      (setq !*comp (cdr s!:faslmod_name))
      (setq s!:faslmod_name nil)
      (return nil)))


(put 'faslend 'stat 'endstat)


(de faslout (u)
   (prog nil
      (terpri)
      (princ "FASLOUT ")
      (prin u)
      (princ ": IN files;  or type in expressions")
      (terpri)
      (princ "When all done, execute FASLEND;")
      (terpri)
      (cond ((not (atom u)) (setq u (car u))))
      (cond
         ((not (start!-module u))
            (progn
               (cond ((neq (posn) 0) (terpri)))
               (princ "+++ Failed to open FASL output file")
               (terpri)
               (return nil))))
      (setq s!:faslmod_name (cons u !*comp))
      (setq s!:dfprintsave dfprint!*)
      (setq dfprint!* 's!:fslout0)
      (setq !*defn t)
      (setq !*comp nil)
      (cond ((getd 'begin) (return nil)))
      (s!:fasl_supervisor)))


(put 'faslout 'stat 'rlis)


(de s!:c_supervisor nil
   (prog (u w !*echo)
top   (setq u (errorset '(read) t !*backtrace))
      (cond ((atom u) (return nil)))
      (setq u (car u))
      (cond ((equal u !$eof!$) (return nil)))
      (cond ((not (atom u)) (setq u (macroexpand u))))
      (cond
         ((atom u) (go top))
         ((eqcar u 'c_end) (return (apply 'c_end nil)))
         ((eqcar u 'rdf)
            (progn
               (setq w (open (setq u (eval (cadr u))) 'input))
               (cond
                  (w
                     (progn (terpri) (princ "Reading file ") (prin u) (terpri)
                        (setq w (rds w))
                        (s!:c_supervisor)
                        (princ "End of file ")
                        (prin u)
                        (terpri)
                        (close (rds w))))
                  (t (progn
                        (princ "Failed to open file ")
                        (prin u)
                        (terpri)))) ))
         (t (s!:cout0 u)))
      (go top)))


(de s!:cout0 (u) (s!:cout1 u nil))


(de s!:cout1 (u loadonly)
   (prog (s!:into_c)
      (setq s!:into_c t)
      (cond ((not (atom u)) (setq u (macroexpand u))))
      (cond
         ((atom u) (return nil))
         ((eqcar u 'progn)
            (progn
               (prog (v)
                  (setq v (cdr u))
            lab   (cond ((null v) (return nil)))
                  ((lambda (v) (s!:cout1 v loadonly)) (car v))
                  (setq v (cdr v))
                  (go lab))
               (return nil)))
         ((eqcar u 'eval!-when)
            (return
               (prog (w)
                  (setq w (cadr u))
                  (setq u (cons 'progn (cddr u)))
                  (cond ((and (memq 'compile w) (not loadonly)) (eval u)))
                  (cond ((memq 'load w) (s!:cout1 u t)))
                  (return nil))))
         ((or
             (flagp (car u) 'eval)
             (and
                (equal (car u) 'setq)
                (not (atom (caddr u)))
                (flagp (caaddr u) 'eval)))
            (cond ((not loadonly) (errorset u t !*backtrace)))) )
      (cond
         ((eqcar u 'rdf)
            (prog (w)
               (setq w (open (setq u (eval (cadr u))) 'input))
               (cond
                  (w
                     (progn
                        (princ "Reading file ")
                        (prin u)
                        (terpri)
                        (setq w (rds w))
                        (s!:c_supervisor)
                        (princ "End of file ")
                        (prin u)
                        (terpri)
                        (close (rds w))))
                  (t (progn
                        (princ "Failed to open file ")
                        (prin u)
                        (terpri)))) ))
         ((or (eqcar u 'de) (eqcar u 'defun))
            (prog (w)
               (setq u (cdr u))
               (setq w (s!:compile1 (car u) (cadr u) (cddr u) nil))
               (prog (p)
                  (setq p w)
            lab   (cond ((null p) (return nil)))
                  ((lambda (p) (s!:cgen (car p) (cadr p) (caddr p) (cdddr p)))
                     (car p))
                  (setq p (cdr p))
                  (go lab))))
         ((or (eqcar u 'dm) (eqcar u 'defmacro))
            (prog (w g)
               (setq g (dated!-name (cadr u)))
               (setq u (cdr u))
               (setq w (cadr u))
               (cond
                  ((and w (null (cdr w)))
                     (setq w
                        (cons
                           (car w)
                           (cons '!&optional (cons (gensym) nil)))) ))
               (setq w (s!:compile1 g w (cddr u) nil))
               (prog (p)
                  (setq p w)
            lab   (cond ((null p) (return nil)))
                  ((lambda (p) (s!:cgen (car p) (cadr p) (caddr p) (cdddr p)))
                     (car p))
                  (setq p (cdr p))
                  (go lab))
               (s!:cinit
                  (list 'dm (car u) '(u !&optional e) (list g 'u 'e)))) )
         ((eqcar u 'putd)
            (prog (a1 a2 a3)
               (setq a1 (cadr u))
               (setq a2 (caddr u))
               (setq a3 (cadddr u))
               (cond
                  ((and
                      (eqcar a1 'quote)
                      (or (equal a2 ''expr) (equal a2 ''macro))
                      (or (eqcar a3 'quote) (eqcar a3 'function))
                      (eqcar (cadr a3) 'lambda))
                     (progn
                        (setq a1 (cadr a1))
                        (setq a2 (cadr a2))
                        (setq a3 (cadr a3))
                        (setq u
                           (cons
                              (cond ((equal a2 'expr) 'de) (t 'dm))
                              (cons a1 (cdr a3))))
                        (s!:cout1 u loadonly)))
                  (t (s!:cinit u)))) )
         ((and (not (eqcar u 'c_end)) (not (eqcar u 'carcheck)))
            (s!:cinit u)))) )


(fluid '(s!:cmod_name))


(de c_end nil
   (prog nil
      (cond ((null s!:cmod_name) (return nil)))
      (s!:cend)
      (setq dfprint!* s!:dfprintsave)
      (setq !*defn nil)
      (setq !*comp (cdr s!:cmod_name))
      (setq s!:cmod_name nil)
      (return nil)))


(put 'c_end 'stat 'endstat)


(de c_out (u)
   (prog nil
      (terpri)
      (princ "C_OUT ")
      (prin u)
      (princ ": IN files;  or type in expressions")
      (terpri)
      (princ "When all done, execute C_END;")
      (terpri)
      (cond ((not (atom u)) (setq u (car u))))
      (cond
         ((null (s!:cstart u))
            (progn
               (cond ((neq (posn) 0) (terpri)))
               (princ "+++ Failed to open C output file")
               (terpri)
               (return nil))))
      (setq s!:cmod_name (cons u !*comp))
      (setq s!:dfprintsave dfprint!*)
      (setq dfprint!* 's!:cout0)
      (setq !*defn t)
      (setq !*comp nil)
      (cond ((getd 'begin) (return nil)))
      (s!:c_supervisor)))


(put 'c_out 'stat 'rlis)


(de s!:compile!-file!* (fromfile !&optional tofile verbose !*pwrds)
   (prog (!*comp w save)
      (cond ((null tofile) (setq tofile fromfile)))
      (cond
         (verbose
            (progn
               (cond ((neq (posn) 0) (terpri)))
               (princ "+++ Compiling file ")
               (prin fromfile)
               (terpri)
               (setq save (verbos nil))
               (verbos (ilogand save 4)))) )
      (cond
         ((not (start!-module tofile))
            (progn
               (cond ((neq (posn) 0) (terpri)))
               (princ "+++ Failed to open FASL output file")
               (terpri)
               (cond (save (verbos save)))
               (return nil))))
      (setq w (open fromfile 'input))
      (cond
         (w (progn (setq w (rds w)) (s!:fasl_supervisor) (close (rds w))))
         (t (progn (princ "Failed to open file ") (prin fromfile) (terpri))))
      (cond (save (verbos save)))
      (start!-module nil)
      (cond
         (verbose
            (progn
               (cond ((neq (posn) 0) (terpri)))
               (princ "+++ Compilation complete")
               (terpri))))
      (return t)))


(de compile!-file!* (fromfile !&optional tofile)
   (s!:compile!-file!* fromfile tofile t t))


(de compd (name type defn)
   (prog (g !*comp)
      (setq !*comp t)
      (cond
         ((eqcar defn 'lambda)
            (progn
               (setq g (dated!-name type))
               (symbol!-set!-definition g defn)
               (compile (list g))
               (setq defn g))))
      (put name type defn)
      (return name)))


(de s!:compile0 (name)
   (prog (w args defn)
      (setq defn (getd name))
      (cond
         ((and (eqcar defn 'macro) (eqcar (cdr defn) 'lambda))
            (prog (!*comp lx vx bx)
               (setq lx (cdr defn))
               (cond
                  ((not
                      (or
                         (and
                            (equal (length lx) 3)
                            (not (atom (setq bx (caddr lx))))
                            (equal (cadr lx) (cdr bx)))
                         (and
                            (equal (length lx) 3)
                            (not (atom (setq bx (caddr lx))))
                            (not (atom (cadr lx)))
                            (eqcar (cdadr lx) '!&optional)
                            (not (atom (setq bx (cdr bx))))
                            (equal (caadr lx) (car bx))
                            (equal (cddadr lx) (cdr bx)))) )
                     (progn
                        (setq w (dated!-name name))
                        (symbol!-set!-definition w (cdr defn))
                        (s!:compile0 w)
                        (cond
                           ((equal 1 (length (cadr lx)))
                              (symbol!-set!-env
                                 name
                                 (list '(u !&optional env) (list w 'u))))
                           (t (symbol!-set!-env
                                 name
                                 (list
                                    '(u !&optional env)
                                    (list w 'u 'env)))) ))) )))
         ((or (not (eqcar defn 'expr)) (not (eqcar (cdr defn) 'lambda)))
            (progn
               (cond
                  (!*pwrds
                     (progn
                        (cond ((neq (posn) 0) (terpri)))
                        (princ "+++ ")
                        (prin name)
                        (princ " not compilable")
                        (terpri)))) ))
         (t (progn
               (setq args (cddr defn))
               (setq defn (cdr args))
               (setq args (car args))
               (cond
                  ((stringp args)
                     (progn
                        (cond
                           (!*pwrds
                              (progn
                                 (cond ((neq (posn) 0) (terpri)))
                                 (princ "+++ ")
                                 (prin name)
                                 (princ " was already compiled")
                                 (terpri)))) ))
                  (t (progn
                        (cond
                           (!*savedef
                              (put
                                 name
                                 '!*savedef
                                 (cons 'lambda (cons args defn)))) )
                        (setq w (s!:compile1 name args defn nil))
                        (prog (p)
                           (setq p w)
                     lab   (cond ((null p) (return nil)))
                           ((lambda (p)
                               (symbol!-set!-definition (car p) (cdr p)))
                              (car p))
                           (setq p (cdr p))
                           (go lab)))) ))) )))


(de compile (l)
   (prog nil
      (cond ((and (atom l) (not (null l))) (setq l (list l))))
      (prog (name)
         (setq name l)
   lab   (cond ((null name) (return nil)))
         ((lambda (name) (errorset (list 's!:compile0 (mkquote name)) t t))
            (car name))
         (setq name (cdr name))
         (go lab))
      (return l)))


