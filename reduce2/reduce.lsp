
(setq system!* 'tenex)

(setq date!* "25-MAR-73")

(de newform (u) (deflist u 'newform))

(de newnam (u) (deflist u 'newnam))

(de deflist (l v)
  (cond
    ((null l) nil)
    (t (cons
        (prog2 (putprop (caar l) (cadar l) v) (caar l))
        (deflist (cdr l) v)))) )

%(newnam
%  '((digit numberp)
%    (error err)
%    (explode explodec)
%    (flagp get)
%    (getel eval)
%    (gts eval)
%    (ncons nconsx)
%    (remove removex)
%    (stringp atom)
%    (!*apply apply)
%    (!*eval eval)
%    (!*!*dollar '!$)
%    (!*!*eof '!$eof!$)
%    (!*!*esc '!#)
%    (!*!*fmark '!&)
%    (!*!*qmark '!')
%    (!*!*xmark '!!)))

%(newform
%  '((equal
%      (lambda (u v)
%        (cond
%          ((and (numberp v) (lessp (abs v) 1000)) (list 'eq u v))
%          (t (list 'equal u v)))) )
%     (errorset (lambda (u v) (list 'errset (list 'eval u) v)))
%     (map (lambda (u v) (list 'map v u)))
%     (maplist (lambda (u v) (list 'maplist v u)))
%     (mapcar (lambda (u v) (list 'mapcar v u)))
%     (pts (lambda (u v) (list 'set u v)))
%     (put (lambda (u v w) (list 'putprop u w v)))) )

(de lose (u)
  (prog nil
a   (cond ((null u) (return nil)))
    (put (car u) 'lose t)
    (setq u (cdr u))
    (go a)))

%(de putd (name varlis body type) (put name type (list 'lambda varlis body)))

(special !*s!* !*s1!*)

(special !*pi!*)

%(de compress (u) (cond ((numberp (car u)) (maknam u)) (t (readlist u))))

%(de flag (u v)
%  (prog nil
%a   (cond ((null u) (return nil)))
%    (put (car u) v t)
%    (setq u (cdr u))
%    (go a)))
%
%(de remflag (u v)
%  (prog nil
%a   (cond ((null u) (return nil)))
%    (remprop (car u) v)
%    (setq u (cdr u))
%    (go a)))
%
%(de getd (u)
%  (prog (x)
%    (setq x (getl u '(expr fexpr subr fsubr lsubr macro)))
%    (return (cond ((and x (null (get u '!*!*array))) (cadr x)) (t nil)))) )
%
%(de global (u)
%  (prog nil
%a   (cond ((null u) (return nil)))
%    (put (car u) 'special t)
%    (set (car u) nil)
%    (setq u (cdr u))
%    (go a)))
%
%(de fixp (n)
%  (or (and (numberp n) (eq n (plus 0 n))) (null (eq (cadr n) 'flonum))))
%
%(de quotient (n) (quotient 1 n))

%(de !*array (u)
%  (prog nil
%a   (cond ((null u) (return nil)))
%    (eval (cons 'array (cons (caar u) (cons t (cdar u)))) )
%    (setq u (cdr u))
%    (go a)))
%
%(de setel (u v) (eval (list 'store u (list 'quote v))))
%
%(lose '(arlist mkarray !*array eval getel1 setel))

(de open (u v)
  (prog nil
    (eval (cons v (cons (mkat u) u)))
    (cond
      ((eq v 'input) (setq ipl!* (cons u ipl!*)))
      (t (setq opl!* (cons u opl!*))))
    (return u)))

(de rds (u)
  (cond
    ((null u) (inc nil nil))
    ((member u ipl!*) (inc (mkat u) nil))
    (t (rederr (cons "RDS GIVEN CLOSED FILE" u)))) )

(de wrs (u)
  (cond
    ((null u) (outc nil nil))
    ((member u opl!*) (outc (mkat u) nil))
    (t (rederr (cons "WRS GIVEN CLOSED FILE" u)))) )

(de close (u)
  (cond
    ((null u) nil)
    ((member u ipl!*)
      (inc (cond ((null (equal u ifl!*)) (inc (mkat u) nil)) (t nil)) t))
    ((member u opl!*)
      (outc (cond ((null (equal u ofl!*)) (outc (mkat u) nil)) (t nil)) t))
    (t (rederr (cons "CLOSE GIVEN CLOSED FILE" u)))) )

(de mkat (u)
  (prog (z)
    (setq u (flatten u))
a   (cond ((null u) (return (compress z))))
    (setq z (nconc (delete '!: (explode (car u))) z))
    (setq u (cdr u))
    (go a)))

%(de token nil
%  (prog (x)
%    (scanset)
%    (setq ttype!* (setq x (scan)))
%    (scanreset)
%    (return
%      (cond
%        ((equal x 0) (intern scnval))
%        ((equal x 1) (list 'string scnval))
%        ((equal x 2) scnval)
%        ((equal scnval 39) (list 'quote (rread)))
%        (t (intern (ascii scnval)))) )))

(de delcp (u) (member u '(!; !$)))

%(de liter (x)
%  (and
%    (null (numberp x))
%    (greaterp
%      (setq x (lsh (maknum (caar (get x 'pname)) 'fixnum) (minus 11)))
%      64)
%    (greaterp 91 x)))

(de mkvar (u v) u)

%(lose '(token))

%(newnam '((scan scan!*)))

(de outdef (name varlis body type)
  (prog nil
    (terpri)
    (princ "(DEFPROP ")
    (princ name)
    (princ " ")
    (terpri)
    (sprint (list 'lambda varlis body) 2 0)
    (princ " ")
    (terpri)
    (sprint type 1 1)
    (princ ")")
    (terpri)))

(de dfprint (u)
  (prog nil
    (sprint u 2 0)
    (terpri)
    (terpri)))

(put 'defn 'simpfg '((t (ed t))))

(de inout (u v)
  (prog (dev fl !*s!* !*s1!*)
    (setq dev 'dsk!:)
    (setq echol!* !*echo)
a   (cond ((null u) (go d)) ((null (devp (car u))) (go b)))
    (setq dev (car u))
    (setq u (cdr u))
    (go a)
b   (cond ((eq v 'output) (go c)))
    (setq fl (list dev (mkfil (car u))))
    (cond ((member fl ipl!*) (go b1)))
    (open fl v)
b1  (rds (setq ifl!* fl))
    (cond
      ((and (null (atom (cadr fl))) (member (cdadr fl) '(lsp lap sl))) (go l)))
    (setq !*echo iecho!*)
    (begin1)
b2  (setq u (cdr u))
    (go a)
c   (cond
      ((or (eq (car u) 'l) (eq dev 'lpt!:)) (setq fl '(lpt!:)))
      ((eq (car u) 't) (go e))
      (t (setq fl (list dev (mkfil (car u)))) ))
    (cond ((member fl opl!*) (go c1)))
    (open fl v)
c1  (wrs (setq ofl!* fl))
    (linelength 68)
d   (cond ((eq v 'input) (refg)))
    (return nil)
e   (setq ofl!* nil)
    (wrs nil)
    (return nil)
l   (cond ((eq (cdadr fl) 'lap) (setq ibase 8)))
l1  (cond ((eq (cdadr fl) 'sl) (go sl)))
    (setq !*s!* (errset (read) t))
    (cond ((or (atom !*s!*) (cdr !*s!*)) (go l2)))
    (setq !*s!* (car !*s!*))
l11 (cond (!*defn (go l3)))
    (setq !*s!* (errset (eval !*s!*) t))
    (cond ((or (atom !*s!*) (cdr !*s!*)) (go l2)))
    (print (car !*s!*))
    (terpri)
    (go l1)
l2  (setq ibase 10)
    (endifl fl)
    (cond ((eq !*s!* !*!*eof) (go b2)) (t (rederr "ERROR TERMINATION")))
l3  (dfprint !*s!*)
    (go l1)
sl  (setq !*s!* (errset (read) t))
    (cond ((or (atom !*s!*) (cdr !*s!*)) (go l2)))
    (setq !*s1!* (errset (read) t))
    (cond ((or (atom !*s1!*) (cdr !*s1!*)) (go l2)))
    (cond
      ((eq (car !*s!*) 'define)
        (setq !*s!*
          (list 'define!* (mkquote (mapcar (caar !*s1!*) (function reform)))) ))
      (t (setq !*s!*
          (reform
            (cons
              (car !*s!*)
              (mapcar
                (car !*s1!*)
                (function (lambda (j) (mkquote (reform j)))) ))) )))
    (go l11)))

(de reform (u)
  (cond
    ((atom u)
      (cond
        ((numberp u) u)
        (t ((lambda (x) (cond (x (reform x)) (t u))) (get u 'newnam)))) )
    ((eq (car u) 'quote) u)
    ((eq (car u) 'cond)
      (cons
        'cond
        (mapcar
          (cdr u)
          (function (lambda (j) (list (reform (car j)) (reform (cadr j)))) ))) )
    ((eq (car u) 'prog)
      (prog2 (rplacd (cdr u) (mapcar (cddr u) (function reform))) u))
    ((eq (car u) 'lambda) (prog2 (rplaca (cddr u) (reform (caddr u))) u))
    (t (mkform (car u) (mapcar (cdr u) (function reform)))) ))

(de shut (u)
  (prog (x)
a   (cond
      ((null u) (return nil))
      ((devp (car u)) (go d))
      ((eq (car u) 'l) (setq x '(lpt!:)))
      (t (setq x (list 'dsk!: (mkfil (car u)))) ))
a1  (cond
      ((member x opl!*) (go b))
      ((null (member x ipl!*)) (rederr (list x "NOT OPEN"))))
    (endifl x)
    (go c)
b   (close x)
    (setq opl!* (delete x opl!*))
    (cond ((null (equal x ofl!*)) (go c)))
    (setq ofl!* nil)
    (wrs nil)
c   (setq u (cdr u))
    (go a)
d   (cond ((or (null (cdr u)) (cddr u)) (go err)))
    (setq x (list (car u) (cadr u)))
    (setq u (cdr u))
    (go a1)
err (rederr (list "CLOSE FORMAT" u))))

(de devp (u)
  (cond
    ((atom u) (eq (car (reverse (explode u))) '!:))
    (t (null (eq (car u) 'cons)))) )

(de mkfil (u)
  (cond
    ((atom u) u)
    ((numberp (car u)) u)
    ((eq (car u) 'cons) (cons (cadr u) (caddr u)))
    (t (rederr "FILE FORMAT"))))

(setq opl!* nil)

(lose '(inout shut))

(de pause nil
  (prog nil
    (cond
      ((null ifl!*) (return nil))
      ((or (null erfg!*) (null cloc!*)) (go c))
      ((yesp 'edit!?) (go a))
      ((null flg!*) (go c)))
    (setq flg!* (setq sos!* nil))
    (!*apply 'shut (list ifl!*))
    (return nil)
a   (setq contl!* nil)
    (cond ((null ofl!*) (go b)))
    (lprim (list ofl!* "SHUT"))
    (!*apply 'shut (list ofl!*))
b   (return (edit1 cloc!* nil))
c   (cond ((yesp 'cont!?) (return nil)))
    (refg)
    (setq contl!* (cons ifl!* contl!*))
    (setq ifl!* nil)
    (setq ipl!* (cdr ipl!*))
    (rds nil)
    (cond (erfg!* (return 'no)))) )

(de yesp (u)
  (prog (x y count)
    (cond (ifl!* (rds nil)))
    (cond (ofl!* (wrs nil)))
    (cond ((atom u) (princ u)) (t (lpri u)))
    (terpri)
    (setq count 0)
a   (setq x (read))
    (setq count (plus count 1))
    (terpri)
    (cond
      ((or (greaterp count 10) (eq x !$eof!$)) (stop 99)))
    (cond ((or (and (eq x 'y) (setq y t)) (eq x 'n)) (go b)))
    (princ "TYPE Y OR N")
    (go a)
b   (cond (ofl!* (wrs ofl!*)))
    (cond (ifl!* (rds ifl!*)))
    (setq cursym!* '!*semicol!*)
    (return y)))

(de cont nil
  (prog nil
    (cond ((null contl!*) (rederr "NO FILE OPEN")))
    (refg)
    (setq ifl!* (car contl!*))
    (setq contl!* (cdr contl!*))
    (setq ipl!* (cons ifl!* ipl!*))
    (rds ifl!*)
    (begin1)))

(flag '(cont) 'ignore)

(de printty (u)
  (prog nil
    (cond ((and (null !*fort) !*nat) (print u)))
    (cond ((null ofl!*) (return nil)))
    (outc nil nil)
    (print u)
    (outc (mkat ofl!*) t)))

(de redmsg1 (u v) (yesp (list 'declare u v "? (Y/N)")))

(deflist '((pause endstat) (cont endstat)) 'stat)

(setq echol!* nil)

(de stime (u)
  (prog (x)
    (setq x (gts u))
    (pts u (!*eval '(time nil)))
    (terpri)
    (princ (!*dif (gts u) x))
    (princ " ")
    (princ 'ms)
    (terpri)))

(de timstat nil (prog2 (scan!*) '(stime 'time2!*)))

(deflist '((time timstat)) 'stat)

(flag '(stime) 'direct)

(setq switch!*
  '((!$ nil !*semicol!* nil)
     (125 nil !*semicol!* nil)
     (!; nil !*semicol!* nil)
     (!+ nil plus nil ! !+! )
     (!- nil difference nil ! !-! )
     (!* !* times expt)
     (!/ nil quotient nil)
     (!= nil equal nil)
     (!, nil !*comma!* nil)
     (!( nil !*lpar!* nil)
     (!) nil !*rpar!* nil)
     (!: != !*colon!* setq nil ! !:!=! )
     (!. nil cons nil)
     (!< != lessp leq)
     (!> != greaterp geq)))

(newnam '((!^ expt) (!Right!Arrow setq)))

(prog (x)
  (setq x switch!*)
a (cond
    ((null x) (return nil))
    ((numberp (caar x)) (rplaca (car x) (intern (ascii (caar x)))) ))
  (setq x (cdr x))
  (go a))

(lose '(abs assoc simpgts))

(de begin nil
  (prog nil
    (setq time1!* (setq time2!* (!*eval '(time nil))))
    (setq !*int t)
    (setq !*echo nil)
    (setq contl!* (setq ifl!* (setq ipl!* (setq ofl!* (setq opl!* nil)))) )
    (cond ((eq date!* nil) (go a)))
    (princ "REDUCE 2 (")
    (princ date!*)
    (princ ") ...")
    (terpri)
    (setq date!* nil)
    (cond ((neq system!* 'tenex) (go a)))
    (princ "FOR HELP, TYPE HELP<ALTMODE>")
    (terpri)
a   (setq !*mode (progn (setq alglist!* (cons nil nil)) imode!*))
    (setq crchar!* '! )
    (begin1)
    (princ "ENTERING LISP...")
    (terpri)))

(deflist
  '((initl
      (lambda nil
        (prog (x)
          (getsym subr scaninit letter ignore scan scanset scanreset)
          (scaninit 37 13 34 34 33)
          (mapcar (function ignore) iglist!*)
          (setq klist nil)
          (setq base (setq ibase 10))
          (setq llength!* 67)
          (setq !*nopoint t)
          (ddtin nil)
          (nouuo nil)
          (bakgag nil)
          (setq iecho!* t)
          (setq imode!* 'algebraic)
          (remprop 'df 'fexpr)
          (outc nil t)
          (remprop 'initl 'expr)
          (cond ((getd 'apninit) (apninit)))
          (cond ((getd 'modinit) (modinit)))
          (cond ((getd 'initfn) (initfn 'begin)))
          (excise)))) )
  'expr)

(setq iglist!* '(9 10 12 13 31 32))

(deflist '((retry endstat)) 'stat)

%(setq scnval nil)

%(putsym (scnval (get 'scnval 'value)))

(put '!*!*null 'newnam (ascii 0))

%(lap orderp subr)
%(!*!*null 104960 1 2)
%(!*!*null 112640 1 (c 0))
%(movei 1 't)
%(popj p)

(null (setq !*mode 'symbolic))

(setq blockp!* nil)

(setq defl!* '((!*!*array . array)))

(setq erfg!* nil)

(setq initl!* '(blockp!* erfg!* outl!* vars!*))

(setq letl!* nil)

(setq matp!* nil)

(setq outl!* nil)

(setq preclis!*
  '(or and not member equal neq eq geq greaterp leq lessp plus difference times
     quotient expt cons))

(setq ttype!* nil)

(setq type!* nil)

(setq vars!* nil)

(setq !*defn nil)

(setq !*echo t)  % Changed by ACN for debugging.

(setq !*msg nil)

(setq !*nat nil)

(de gostat nil
  (prog (var)
    (setq var (cond ((eq (scan) 'to) (scan)) (t cursym!*)))
    (scan)
    (return (list 'go var))))

(put 'go 'stat 'gostat)

(newnam '((goto go)))

(deflist
  '((not not) (plus plus) (difference minus) (minus minus) (times times)
     (quotient recip) (recip recip))
  'unary)

(flag '(and or plus times equal !*comma!*) 'nary)

(flag '(cons setq) 'right)

(deflist '((minus plus) (recip times)) 'alt)

(de mkprec nil
  (prog (x y z)
    (setq x (cons '!*comma!* (cons 'setq preclis!*)))
    (setq y 1)
a   (cond ((null x) (return nil)))
    (put (car x) 'infix y)
    (cond ((setq z (get (car x) 'unary)) (put z 'infix y)))
    (setq x (cdr x))
    (setq y (plus y 1))
    (go a)))

(prog (w x y z)
  (mkprec)
  (setq x switch!*)
a (cond ((null x) (return nil)))
  (setq w (cdar x))
  (put (caar x) 'switch!* w)
  (setq y (list (caar x) (caar x)))
  (put (cadr w) 'prtch y)
  (cond ((setq z (get (cadr w) 'unary)) (put z 'prtch y)))
  (cond ((null (car (setq y (cddr w)))) (go b)))
  (setq z (compress (list (caar x) (car w))))
  (put (car y) 'prtch (list z z))
b (cond
    ((null (cdr y)) (go c))
    ((cadr y) (rplaca (get (cadr w) 'prtch) (cadr y))))
  (cond ((cddr y) (rplaca (get (car y) 'prtch) (caddr y))))
c (setq x (cdr x))
  (go a))

(de terprix nil
  (prog nil
    (cond ((or !*defn (null (or (and !*echo !*nat) erfg!*))) (go a)))
    (mapcar (reverse outl!*) (function princ))
    (terpri)
a   (setq outl!* nil)))

(de delete (u v)
  (cond
    ((null v) nil)
    ((equal u (car v)) (cdr v))
    (t (cons (car v) (delete u (cdr v)))) ))

(de flagp!*!* (u v) (and (atom u) (null (numberp u)) (flagp u v)))

(de begin1 nil
  (prog (result)
    (setq cursym!* '!*semicol!*)
a   (cond
      ((or (and !*echo !*nat) (and !*int (null ifl!*) (null ofl!*))) (terpri)))
    (cond (!*test (stime 'time2!*)))
    (cond
      ((and
         tmode!*
         (setq !*mode (progn (setq alglist!* (cons nil nil)) tmode!*)))
        (setq tmode!* nil)))
    (mapcar initl!* (function sinitl))
    (cond ((eq cursym!* 'end) (go nd0)))
    (setq program!* (errorset '(command) t t))
    (cond ((or (atom program!*) (cdr program!*)) (go err1)))
    (setq program!* (car program!*))
    (cond ((eqcar program!* '!*comma!*) (go er)) ((eq cursym!* 'end) (go nd0)))
    (setq program!*
      (cond ((eqcar program!* 'retry) programl!*) (t (mkex program!*))))
    (cond (!*defn (go d)))
b   (terprix)
    (setq result (errorset (gts 'program!*) t t))
    (cond ((or (atom result) (cdr result) erfg!*) (go err2)) (!*defn (go a)))
    (setq result (car result))
    (cond
      ((eq semic!* '!;)
        (cond
          ((eq !*mode 'symbolic) (prog2 (print result) (terpri)))
          (result (prog2 (terpri!* t) (varpri result (assgnl program!*) t)))
          (t nil))))
    (cond ((and (neq !*mode 'symbolic) result) (setq !*ans result)))
    (go a)
d   (cond ((or (flagp!*!* key!* 'ignore) (eqcar program!* 'quote)) (go b)))
    (dfprint program!*)
    (cond ((flagp!*!* key!* 'eval) (go b)))
    (go a)
nd0 (comm1 'end)
    (terprix)
nd1 (return (endifl ifl!*))
err1(cond
      ((and (eq program!* !*!*esc) (list (token))) (go a))
      ((null (eq program!* !*!*eof)) (go err3)))
    (go nd1)
er  (lprie
      (cond
        ((null (atom (cadr program!*))) (list (caadr program!*) "UNDEFINED"))
        (t "SYNTAX ERROR")))
    (go err3)
err2(setq programl!* program!*)
err3(comm1 t)
    (cond
      ((or (null erfg!*) (eq erfg!* 'hold)) (lprie "ERROR TERMINATION *****")))
    (setq erfg!* t)
    (cond ((and !*int (eq (!*eval (list 'pause)) 'no)) (return nil)))
    (go a)))

(de endifl (u)
  (prog nil
    (cond (u (go a)))
    (mapcar (append ipl!* opl!*) (function close))
    (setq ipl!* (setq opl!* (setq ofl!* nil)))
    (return nil)
a   (close u)
    (setq ipl!* (delete u ipl!*))
    (cond (ifl!* (rds (setq ifl!* (cond (ipl!* (car ipl!*)) (t nil)))) ))) )

(de assgnl (u)
  (cond
    ((or (atom u) (null (member (car u) '(pts setk setq)))) nil)
    ((atom (cadr u)) (cons (mkquote (cadr u)) (assgnl (caddr u))))
    (t (cons (cadr u) (assgnl (caddr u)))) ))

(de sinitl (u) (pts u (get u 'initl)))

(flag '(in out on off shut) 'ignore)

(de princx (u) (setq outl!* (cons u outl!*)))

% Edited by ACN to give up after several end of file marks

(fluid '(eofcount))
(setq eofcount 0)

(de token nil
  (prog (x y z)
    (setq x crchar!*)
a   (cond
      ((seprp x) (go sepr))
      ((digit x) (go number))
      ((liter x) (go letter))
      ((eq x !*!*xmark) (go escape))
      ((eq x !*!*qmark) (go quote))
      ((eq x !*!*smark) (go string))
      ((eq x !$eof!$)
        (cond
          ((greaterp (setq eofcount (plus eofcount 1)) 5) (stop 0)))))
    (setq ttype!* 3)
    (cond ((delcp x) (go d)))
    (setq nxtsym!* x)
a1  (setq crchar!* (readch))
    (go c)
escape
    (setq x (readch))
letter
    (setq ttype!* 0)
let1(setq y (cons x y))
    (cond
      ((or (digit (setq x (readch))) (liter x)) (go let1))
      ((eq x !*!*xmark) (go escape)))
b   (setq nxtsym!* (compress (reverse y)))
    (setq crchar!* x)
c   (return nxtsym!*)
number
    (setq ttype!* 2)
num1(setq y (cons x y))
    (setq z x)
    (cond
      ((or (digit (setq x (readch))) (eq x '!.) (eq x 'e) (eq z 'e)) (go num1))
      (t (go b)))
quote
    (setq crchar!* (readch))
    (setq nxtsym!* (mkquote (rread)))
    (setq ttype!* 4)
    (go c)
string
    (cond ((eq (setq x (readch)) !*!*smark) (go s1)))
    (setq y (cons x y))
    (go string)
s1  (setq nxtsym!* (list!-to!-string (reverse y)))
    (setq ttype!* 1)
    (go a1)
sepr(setq x (readch))
    (go a)
d   (setq nxtsym!* x)
    (setq crchar!* '! )
    (go c)))

(de mkquote (u) (list 'quote u))

(de ptoken nil
  (prog (x)
    (setq x (token))
    (princx x)
    (cond ((or (null (eq x '!()) (null (eq x '!)))) (princx " ")))
    (return x)))

(de rread1 nil
  (prog (x y)
    (setq x (ptoken))
    (cond
      ((null (equal ttype!* 3)) (return x))
      ((eq x '!() (return (rrdls)))
      ((null (or (eq x '!+) (eq x '!-))) (return x)))
    (setq y (ptoken))
    (cond
      ((null (numberp y))
        (prog2 (setq nxtsym!* " ") (symerr "SYNTAX ERROR" nil)))
      ((eq x '!-) (setq y (!*apply 'minus (list y)))) )
    (return y)))

(de rrdls nil
  (prog (x y)
    (setq x (rread1))
    (cond
      ((null (equal ttype!* 3)) (go a))
      ((eq x '!)) (return nil))
      ((null (eq x '!.)) (go a)))
    (setq x (rread1))
    (setq y (ptoken))
    (cond
      ((or (null (equal ttype!* 3)) (null (eq y '!))))
        (prog2 (setq nxtsym!* " ") (symerr "DOT CONTEXT ERROR" nil)))
      (t (return x)))
a   (return (cons x (rrdls)))) )

(de rread nil (prog2 (princx " '") (rread1)))

(de scan nil
  (prog (x)
    (cond ((null (eq cursym!* '!*semicol!*)) (go b)))
a   (terprix)
    (setq nxtsym!* (token))
b   (cond ((null (atom nxtsym!*)) (go q1)) ((eq nxtsym!* 'else) (terprix)))
    (princx nxtsym!*)
c   (cond
      ((numberp nxtsym!*) (go l))
      ((and (setq x (get nxtsym!* 'newnam)) (setq nxtsym!* x)) (go c))
      ((eq nxtsym!* 'comment) (go comm))
      ((eq nxtsym!* !*!*esc) (error !*!*esc))
      ((null (equal ttype!* 3)) (go l))
      ((eq nxtsym!* !*!*qmark) (go quote))
      ((null (setq x (get nxtsym!* 'switch!*))) (go l))
      ((eq (cadr x) '!*semicol!*) (go delim)))
    (setq nxtsym!* (token))
    (cond
      ((and (car x) (eq nxtsym!* (car x))) (go sw1))
      (t (setq cursym!* (cadr x))))
    (cond ((eq cursym!* '!*rpar!*) (go l2)) (t (return cursym!*)))
sw1 (princx nxtsym!*)
    (setq cursym!* (caddr x))
    (setq nxtsym!* (token))
    (return cursym!*)
comm(princx crchar!*)
    (cond ((delcp crchar!*) (go com1)))
    (setq crchar!* (readch))
    (go comm)
com1(setq crchar!* '! )
    (terprix)
    (go a)
delim
    (setq semic!* nxtsym!*)
    (return (setq cursym!* '!*semicol!*))
quote
    (setq nxtsym!* (mkquote (rread)))
    (go l)
q1  (cond ((null (eq (car nxtsym!*) 'string)) (go l)))
    (princx " ")
    (princx (cadr (setq nxtsym!* (cons 'quote (cdr nxtsym!*)))) )
l   (setq cursym!* nxtsym!*)
l1  (setq nxtsym!* (token))
l2  (cond
      ((or
         (numberp nxtsym!*)
         (and (atom nxtsym!*) (null (get nxtsym!* 'switch!*))))
        (princx " ")))
    (return cursym!*)))

(flag '(end !*colon!* !*semicol!*) 'delim)

(de eqcar (u v) (and (null (atom u)) (eq (car u) v)))

(de mkex (u) (cond ((eq !*mode 'symbolic) u) (t (aproc u))))

(de mkform (u v)
  (prog (x)
    (return
      (cond
        ((and (atom u) (setq x (get u 'newform))) (!*apply x v))
        (t (cons u v)))) ))

(de remcomma (u) (cond ((eqcar u '!*comma!*) (cdr u)) (t (list u))))

(de xread1 (u)
  (prog (v w x y z z1 z2)
a   (setq z cursym!*)
a1  (cond
      ((or (null (atom z)) (numberp z)) (setq y nil))
      ((flagp z 'delim) (go delimit))
      ((eq z '!*lpar!*) (go lparen))
      ((eq z '!*rpar!*) (go rparen))
      ((setq y (get z 'infix)) (go infx))
      ((setq y (get z 'stat)) (go stat)))
a2  (setq w (cons z w))
next(setq z (scan))
    (go a1)
n1  (setq y nil)
    (setq w (cons z w))
n2  (setq z z1)
    (go a1)
lparen
    (setq y nil)
    (cond ((eq (scan) '!*rpar!*) (go lp1)))
    (setq z (xread1 (cond ((eqcar w 'mat) (setq matp!* 'mat)) (t 'paren))))
    (cond ((eq u 'mat) (setq z (remcomma z))) ((eqcar z '!*comma!*) (go lp2)))
    (go a2)
lp1 (cond (w (setq w (cons (mkform (car w) nil) (cdr w)))) )
    (go next)
lp2 (cond
      ((null w) (go lp3))
      (t (setq w (cons (mkform (car w) (cdr z)) (cdr w)))) )
    (go next)
lp3 (cond ((eq u 'lambda) (go a2)) (t (go err1)))
rparen
    (cond ((null u) (go err2)) (t (go end1)))
infx(cond
      ((or (eq z '!*comma!*) (null (atom (setq z1 (scan)))) (numberp z1))
        (go in1))
      ((or (eq z1 '!*rpar!*) (eq z1 '!*comma!*) (flagp z1 'delim)) (go n1))
      ((and
         (eq z1 '!*lpar!*)
         (eqcar (setq z1 (xread 'paren)) '!*comma!*)
         (setq z (cons z (cdr z1))))
        (go a1)))
in1 (cond (w (go unwind)) ((null (setq z (get z 'unary))) (go err4)))
    (setq v (cons '!*!*un!*!* v))
    (go pr1)
unwind
    (setq z2 (mkvar (car w) z))
un1 (setq w (cdr w))
    (cond
      ((null w) (go un2))
      ((or
         (numberp (car w))
         (and (null (atom (car w))) (null (eq !*mode 'symbolic))))
        (go err5)))
    (setq z2 (mkform (car w) (list z2)))
    (go un1)
un2 (setq v (cons z2 v))
preced
    (cond
      ((null x) (go pr4))
      ((or
         (lessp y (caar x))
         (and
           (equal y (caar x))
           (or
             (and
               (eq z (cdar x))
               (null (flagp z 'nary))
               (null (flagp z 'right)))
             (get (cdar x) 'alt))))
        (go pr2)))
pr1 (setq x (cons (cons y z) x))
    (cond
      ((null (eq z '!*comma!*)) (go n2))
      ((or (cdr x) (null u) (member u '(lambda mat paren))) (go next))
      (t (go end2)))
pr2 (cond
      ((eq (cdar x) 'setq) (go assign))
      ((eq (cadr v) '!*!*un!*!*) (go unary)))
pr21(setq z2
      (mkform
        (cdar x)
        (cond
          ((and (eqcar (car v) (cdar x)) (flagp (cdar x) 'nary))
            (cons (cadr v) (cdar v)))
          (t (list (cadr v) (car v)))) ))
pr3 (setq x (cdr x))
    (setq v (cons z2 (cddr v)))
    (go preced)
unary
    (cond
      ((eq (car v) '!*!*un!*!*) (go pr1))
      (t (setq z2 (mkform (cdar x) (list (car v)))) ))
    (go pr3)
stat(cond
      ((or
         (flagp z 'go)
         (and
           (null (eq u 'proc))
           (or
             (flagp y 'endstat)
             (and (null (delcp nxtsym!*)) (null (eq nxtsym!* '!,)))) ))
        (go s1)))
    (setq y nil)
    (go a2)
s1  (setq w (cons (!*apply y nil) w))
    (setq y nil)
    (go a)
assign
    (setq v (cons (mkex (car v)) (cdr v)))
    (cond
      ((or (numberp (cadr v)) (null (cadr v))) (go err1))
      ((null (atom (cadr v))) (go as3))
      ((eq u 'for) (go as2))
      ((or (eq !*mode 'symbolic) (progvr (cadr v))) (go pr21)))
as1 (setq z2 (mkform 'setk (list (mkarg (cadr v)) (car v))))
    (go pr3)
as2 (setq z2 (list 'setq (cadr v) (car v)))
    (go pr3)
as3 (cond
      ((null (atom (caadr v))) (go err1))
      ((null (eq !*mode 'symbolic)) (go as1))
      ((get (caadr v) '!*!*array)
        (setq z2 (mkform 'setel (list (mkarg (cadr v)) (car v)))) )
      (type!* (go as2))
      (t (setq z2 (procstat1 (cadr v) (car v) 'expr))))
    (go pr3)
delimit
    (cond
      ((and (null u) (flagp z 'nodel)) (go err1))
      ((member u '(mat paren)) (go err3)))
end1(cond (y (go err1)) ((and (null v) (null w) (null x)) (return nil)))
    (setq y 0)
    (go unwind)
pr4 (cond ((null (equal y 0)) (go pr1)))
end2(cond ((null (cdr v)) (return (car v))))
err1(symerr "SYNTAX ERROR" nil)
err2(symerr "TOO MANY RIGHT PARENTHESES" nil)
err3(symerr "TOO FEW RIGHT PARENTHESES" nil)
err4(symerr "REDUNDANT OPERATOR" nil)
err5(symerr "MISSING OPERATOR" nil)))

(flag '(endstat modestat retstat timstat) 'endstat)

(flag '(else while) 'nodel)

(flag '(begin) 'go)

(de xread (u) (prog2 (scan) (xread1 u)))

(de command nil
  (prog nil
    (scan)
    (setq key!* cursym!*)
    (return (xread1 nil))))

(de remnam (u)
  (prog nil
a   (cond ((null u) (return nil)))
    (remprop (car u) 'newnam)
    (remprop (car u) 'newform)
    (setq u (cdr u))
    (go a)))

(de lpri (u)
  (prog nil
a   (cond ((null u) (return nil)))
    (princ (car u))
    (princ " ")
    (setq u (cdr u))
    (go a)))

(de lpriw (u v)
  (prog (x)
    (terprix)
    (setq u (cons u (cond ((and v (or (atom v) (stringp v))) (list v)) (t v))))
    (cond ((and ofl!* (or !*fort (not !*nat))) (go c)))
a   (lpri u)
    (terpri)
    (cond ((null x) (go b)))
    (wrs x)
    (return nil)
b   (cond ((null ofl!*) (return nil)))
c   (setq x ofl!*)
    (wrs nil)
    (go a)))

(de lprim (u) (lpriw "***" u))

(de lprie (u)
  (prog nil
    (setq erfg!* t)
    (terpri)
    (lpriw "*****" u)))

(de rederr (u)
  (prog nil
    (lprie u)
    (terpri)
    (error nil)))

(de symerr (u v)
  (prog (x)
    (setq erfg!* t)
    (cond
      ((or (numberp cursym!*) (not (setq x (get cursym!* 'prtch))))
        (setq x cursym!*))
      (t (setq x (car x))))
    (terpri)
    (setq outl!* (cons (car outl!*) (cons '!$!$!$ (cdr outl!*))))
    (comm1 t)
    (cond
      ((null v) (lprie u))
      (t (lprie
          (cons
            x
            (cons 'invalid (cond (u (list 'in u 'statement)) (t nil)))) )))
    (error nil)))

(de progvr (var)
  (cond
    ((not (atom var)) nil)
    ((or (numberp var) (flagp var 'share)) t)
    (t (prog (x)
        (cond ((setq x (get var 'datatype)) (return (car x)))) ))) )

(de mkarg (u)
  (cond
    ((null u) nil)
    ((atom u) (cond ((progvr u) u) (t (mkquote u))))
    ((and (flagp!*!* (car u) 'nochange) (not (flagp key1!* 'quote))) u)
    ((eq (car u) 'quote) (mkquote u))
    ((eq (car u) 'gts) u)
    (t (cons 'list (mapcar u (function mkarg)))) ))

(de rlis1 (u)
  (prog (x y)
    (cond ((not (setq x (get cursym!* 'statfn))) (setq x cursym!*)))
    (cond ((flagp!*!* (scan) 'delim) (return (list x))))
    (setq y (remcomma (xread1 nil)))
    (cond (u (setq y (list y))))
    (setq key1!* x)
    (setq x
      (cond
        ((not (eq u 'flagop)) (cons x (mapcar y (function mkarg))))
        (t (mkprog
            nil
            (cons (list 'flag (cons 'quote y) (mkquote x)) (get x 'simpfg)))) ))
    (setq key1!* nil)
    (return x)))

(de rlis nil (rlis1 t))

(de norlis nil (rlis1 nil))

(de rlisf nil (rlis1 'flagop))

(de flagop (u)
  (prog nil
a   (cond ((null u) (return nil)))
    (put (car u) 'stat 'rlisf)
    (setq u (cdr u))
    (go a)))

(put 'flagop 'stat 'rlis)

(flag '(cond prog pts quote setq) 'nochange)

(de comm1 (u)
  (prog nil
    (cond ((eq u 'end) (go b)))
a   (cond
      ((or
         (eq cursym!* '!*semicol!*)
         (and (eq u 'end) (member cursym!* '(end else until !*rpar!*))))
        (return nil)))
b   (scan)
    (go a)))

(de aconc (u v) (nconc u (list v)))

(de ifstat nil
  (prog (condx condit)
    (flag letl!* 'delim)
a   (setq condx (xread t))
    (remflag letl!* 'delim)
    (cond ((not (eq cursym!* 'then)) (go c)))
    (setq condit (aconc condit (list (mkex condx) (mkex (xread t)))) )
    (cond
      ((not (eq cursym!* 'else)) (setq condit (aconc condit '('t 'nil))))
      ((eq (scan) 'if) (go a))
      (t (setq condit (aconc condit (list t (mkex (xread1 t)))) )))
b   (return (cons 'cond condit))
c   (cond ((not (member cursym!* letl!*)) (symerr 'if t)))
    (return (iflet condx))))

(put 'if 'stat 'ifstat)

(flag '(then else) 'delim)

(de flagtype (u v)
  (prog (x y z)
    (setq vars!* (append u vars!*))
a   (cond ((null u) (return (reverse z))))
    (setq x (car u))
    (cond ((or (numberp x) (not (atom x))) (symerr "SYNTAX ERROR" nil)))
    (setq y (get x 'datatype))
    (put x 'datatype (cons v y))
    (setq z (cons x z))
    (setq u (cdr u))
    (go a)))

(de decl (u)
  (prog (v w varlis)
a   (cond ((eq cursym!* '!*semicol!*) (go b)))
    (cond ((not (flagp!*!* cursym!* 'type)) (return varlis)))
    (setq w cursym!*)
    (cond ((eq (scan) 'procedure) (return (procstat))))
    (setq v (flagtype (remcomma (xread1 nil)) w))
    (setq varlis (append v varlis))
    (and (not (eq cursym!* '!*semicol!*)) (symerr nil t))
    (cond ((null u) (go c)))
b   (scan)
    (go a)
c   (flag varlis 'share)
    (global varlis)
    (setq u (list (mkform 'flag (list (mkquote varlis) (mkquote 'share)))) )
d   (cond ((null varlis) (return (mkprog nil u))))
    (setq u (cons (mkform 'pts (list (mkquote (car varlis)) nil)) u))
    (setq varlis (cdr varlis))
    (go d)))

(flag '(real integer scalar) 'type)

% The code here assumed that the interpreter (at least) used shallow binding
% so that if user-code expanded to something with (prog (...)...) in it then
% the variables would be bound in such a way that EVAL could later on access
% them. In particular that applied in the case of a look like "for i:=1:10.."
% and the code in VARPRI could use EVAL, leading to moans about undefined
% variables on some Lisps.
(de mkprog (u v)
  (progn (fluid u)
    (cons 'prog (cons u v))))

(de setdiff (u v) (cond ((null v) u) (t (setdiff (delete (car v) u) (cdr v)))) )

(de remtype (varlis)
  (prog (x y)
    (setq vars!* (setdiff vars!* varlis))
a   (cond ((null varlis) (return nil)))
    (setq x (car varlis))
    (setq y (cdr (get x 'datatype)))
    (cond (y (put x 'datatype y)) (t (remprop x 'datatype)))
    (setq varlis (cdr varlis))
    (go a)))

(de blockstat nil
  (prog (x hold varlis)
    (setq blockp!* (cons nil blockp!*))
    (scan)
    (cond ((member cursym!* '(nil !*rpar!*)) (error !*!*esc)))
    (setq varlis (decl t))
a   (cond ((eq cursym!* 'end) (go b)))
    (setq x (xread1 nil))
    (cond
      ((eqcar x 'end) (go c))
      ((not (eq cursym!* '!*colon!*)) (setq x (mkex x))))
    (and (not (eq cursym!* 'end)) (scan))
    (cond (x (setq hold (aconc hold x))))
    (go a)
b   (comm1 'end)
c   (remtype varlis)
    (setq blockp!* (cdr blockp!*))
    (return (mkprog varlis hold))))

(de decstat nil (decl nil))

(deflist '((integer decstat) (real decstat) (scalar decstat)) 'stat)

(put 'begin 'stat 'blockstat)

(de retstat nil
  (cond
    ((not blockp!*) (symerr nil t))
    (t (list
        'return
        (cond ((flagp!*!* (scan) 'delim) nil) (t (mkex (xread1 t)))) ))) )

(put 'return 'stat 'retstat)

(de modestat nil
  (prog (x)
    (setq x (cond ((eq cursym!* 'lisp) 'symbolic) (t cursym!*)))
    (cond
      ((flagp!*!* (scan) 'delim)
        (return
          (not (setq !*mode (progn (setq alglist!* (cons nil nil)) x)))) ))
    (setq tmode!* !*mode)
    (setq !*mode (progn (setq alglist!* (cons nil nil)) x))
    (return (xread1 nil))))

(de procstat1 (u body type)
  (prog (name varlis)
    (setq name (car u))
    (cond
      ((or (null name) (not (atom name)) (numberp name))
        (rederr (list name "INVALID PROCEDURE NAME")))
      ((flagp name 'lose) (return nil))
      ((not (getd name)) (flag (list name) 'fnc)))
    (cond ((eqcar body 'prog) (setq varlis (cadr body))))
    (cond (varlis (rplaca (cdr body) (setdiff varlis (cdr u)))) )
    (setq varlis (cdr u))
    (cond ((flagp name 'fnc) (go a)))
    (lprim (list name 'redefined))
a   (cond
      (!*defn (outdef name varlis body type))
      (t (putd name type (list 'lambda varlis body))))
    (remflag (list name) 'fnc)
    (return
      (cond
        ((eq !*mode 'symbolic) (mkquote name))
        (t (mkform 'flag (list (mkquote (list name)) (mkquote 'opfn)))) ))) )

(de procstat nil
  (prog (x y z)
    (setq type!* (cond ((eq cursym!* 'procedure) 'expr) (t cursym!*)))
    (setq x
      (cond
        ((not (or (eq cursym!* 'procedure) (eq (scan) 'procedure)))
          (prog2 (setq fname!* cursym!*) (xread1 nil)))
        (t (prog2 (setq fname!* (scan)) (xread1 'proc)))) )
    (cond ((atom x) (setq x (list x))) ((eq (car x) 'setq) (go b)))
    (setq y (flagtype (cdr x) 'scalar))
    (setq z (mkex (xread t)))
    (remtype y)
a   (setq z (procstat1 x z type!*))
    (setq type!* nil)
    (return z)
b   (cond
      ((not (eq !*mode 'symbolic))
        (prog2 (setq type!* nil) (symerr "SYNTAX ERROR" nil))))
    (setq z (caddr x))
    (setq x (cadr x))
    (go a)))

(deflist '((procedure procstat) (fexpr procstat) (macro procstat)) 'stat)

(deflist '((algebraic modestat) (lisp modestat) (symbolic modestat)) 'stat)

(de endstat nil
  (prog (x)
    (setq x cursym!*)
    (comm1 'end)
    (return (list x))))

(put 'end 'stat 'endstat)

(de expt (m n)
  (prog (p q)
    (setq p 0)
    (cond
      ((minusp n) (return (quotient 1.0 (expt m (minus n)))) )
      ((or (equal n 0) (equal m 1)) (return 1)))
    (setq p 1)
a   (setq q (divide n 2))
    (cond ((equal (cdr q) 0) (go b)))
    (setq p (times m p))
    (cond ((equal (car q) 0) (return p)))
b   (setq n (car q))
    (setq m (times m m))
    (go a)))

(de geq (u v) (or (equal u v) (greaterp u v)))

(de leq (u v) (or (equal u v) (lessp u v)))

(de neq (u v) (not (equal u v)))

(deflist '((greateq geq) (lesseq leq) (uneq neq)) 'newnam)

(de infstat nil
  (prog (x)
    (setq x (remcomma (xread nil)))
    (cond ((eq !*mode 'algebraic) (mapcar x (function mkop))))
    (setq preclis!* (append (reverse x) preclis!*))
    (mkprec)))

(de precstat nil
  (prog (x)
    (setq x (remcomma (xread nil)))
    (return (precset (car x) (cadr x)))) )

(de precset (x y)
  (prog (w z)
    (setq preclis!* (delete x preclis!*))
    (setq w preclis!*)
a   (cond ((null w) (rederr (list y "NOT FOUND"))) ((eq y (car w)) (go b)))
    (setq z (cons (car w) z))
    (setq w (cdr w))
    (go a)
b   (setq preclis!* (nconc (reverse z) (cons (car w) (cons x (cdr w)))) )
    (mkprec)))

(put 'infix 'stat 'infstat)

(put 'precedence 'stat 'precstat)

(de flatten (u)
  (cond
    ((null u) nil)
    ((atom u) (list u))
    ((atom (car u)) (cons (car u) (flatten (cdr u))))
    (t (nconc (flatten (car u)) (flatten (cdr u)))) ))

(de progchk (u)
  (prog (x)
    (cond ((or (not (eqcar u 'prog)) (cadr u)) (return nil)))
    (setq u (cdr u))
a   (setq u (cdr u))
    (cond
      ((null u) (return (reverse x)))
      ((atom (car u)) (go b))
      ((eqcar (car u) 'return) (go ret))
      ((eqcar (car u) 'prog) (go b))
      ((member 'return (flatten (car u))) (return nil)))
b   (setq x (cons (car u) x))
    (go a)
ret (cond
      ((cdr u) (return nil))
      ((not (atom (cadar u))) (setq x (cons (cadar u) x))))
    (go a)))

(de adform (u v w)
  (cond
    ((null w) nil)
    ((equal v (car w))
      (prog (x)
        (setq x (progchk u))
        (return (cond ((null x) (cons u (cdr w))) (t (append x (cdr w)))) )))
    (t (cons (car w) (adform u v (cdr w)))) ))

(de forloop nil
  (prog (curs exp incr indx condlist body flg fnc lab1 lab2)
    (setq fnc (gensym1 'g))
    (setq exp (xread1 'for))
    (cond
      ((and (eq (car exp) '!*comma!*) (eqcar (cadr exp) 'setq))
        (setq exp
          (list
            nil
            (cadadr exp)
            (cons '!*comma!* (nconc (cddadr exp) (cddr exp)))) ))
      ((not (member (car exp) '(setq equal))) (go err)))
    (setq exp (cdr exp))
    (cond ((or (not (atom (setq indx (car exp)))) (numberp indx)) (go err)))
    (setq indx (car (flagtype (list indx) 'integer)))
    (setq exp (remcomma (cadr exp)))
a1  (cond
      ((null exp) (go b2))
      ((cdr exp) (setq flg t))
      ((eq cursym!* 'step) (go b1))
      ((eq cursym!* '!*colon!*) (go bb)))
    (setq condlist
      (nconc condlist (list (list 'setq indx (car exp)) (list fnc))))
b0  (setq exp (cdr exp))
    (go a1)
b1  (setq incr (mkex (xread nil)))
    (cond ((not (member (setq curs cursym!*) '(until while))) (go err)))
aa  (setq lab1 (gensym1 'g))
    (setq lab2 (gensym1 'g))
    (setq condlist (aconc condlist (list 'setq indx (car exp))))
    (setq exp (remcomma (xread t)))
    (setq body (mkex (car exp)))
    (setq condlist
      (nconc
        condlist
        (list
          lab1
          (list
            'cond
            (list
              (cond
                ((eq curs 'until)
                  (cond
                    ((numberp incr)
                      (list
                        (cond ((minusp incr) 'lessp) (t 'greaterp))
                        indx
                        body))
                    (t (list
                        'minusp
                        (list 'times (list 'difference body indx) incr)))) )
                (t (list 'not body)))
              (list 'go lab2)))
          (list fnc)
          (list 'setq indx (list 'plus indx incr))
          (list 'go lab1)
          lab2)))
    (and (cdr exp) (setq flg t))
    (go b0)
bb  (setq incr 1)
    (setq curs 'until)
    (go aa)
b2  (cond
      ((null condlist) (go err))
      ((setq curs (get cursym!* 'bin)) (go c))
      ((not (eq cursym!* 'do)) (go err)))
    (setq body (mkex (xread nil)))
b   (cond
      (flg (putd fnc 'expr (list 'lambda nil body)))
      (t (setq condlist (adform body (list fnc) condlist))))
    (remtype (list indx))
    (return (mkprog (cons indx exp) condlist))
c   (setq exp (gensym1 'g))
    (setq body
      (list 'setq exp (list (car curs) (list 'simp (mkex (xread t))) exp)))
    (setq condlist
      (cons
        (list 'setq exp (mkquote (cdr curs)))
        (aconc condlist (list 'return (list 'mk!*sq exp)))) )
    (setq exp (list exp))
    (go b)
err (symerr 'for t)))

(de forstat nil (cond ((eq (scan) 'all) (forallfn)) (t (forloop))))

(put 'for 'stat 'forstat)

(flag '(step do until while) 'delim)

(de defp (u v)
  (prog (w)
    (cond ((or (not (atom u)) (numberp u)) (errpri2 u 'hold)))
    (setq w defl!*)
a   (cond ((null w) (return nil)) ((get u (caar w)) (go b)))
    (setq w (cdr w))
    (go a)
b   (setq w (cdar w))
    (cond ((null v) (go c)))
    (setq u (list u "ALREADY DEFINED AS" w))
    (cond ((eq v w) (lprim u)) (t (lprie u)))
c   (return w)))

(de numlis (u) (or (null u) (and (numberp (car u)) (numlis (cdr u)))) )

(de arrayfn (u)
  (prog (x y)
a   (cond ((null u) (return nil)))
    (setq x (car u))
    (cond ((atom x) (errpri2 x t)) ((defp (car x) 'array) (go b)))
    (setq y (cond ((eq !*mode 'symbolic) (cdr x)) (t (revlis (cdr x)))) )
    (cond
      ((not (numlis y))
        (lprie (list "INCORRECT ARRAY ARGUMENTS FOR" (car x)))) )
    (put (car x) '!*!*array y)
    (!*array (list (cons (car x) (add1lis y))))
b   (setq u (cdr u))
    (go a)))

(de add1lis (u)
  (cond ((null u) nil) (t (cons (plus (car u) 1) (add1lis (cdr u)))) ))

(put 'array 'stat 'rlis)

(put 'array 'statfn 'arrayfn)

(de arlist (u n)
  (cond ((equal n 0) nil) (t (cons (mkarray u) (arlist u (difference n 1)))) ))

(de mkarray (u) (cond ((null u) nil) (t (arlist (cdr u) (car u)))) )

(de !*array (u)
  (prog nil
a   (cond ((null u) (return nil)))
    (put (caar u) 'array (mkarray (cdar u)))
    (setq u (cdr u))
    (go a)))

(de getel1 (u v)
  (cond ((null v) u) (t (getel1 (nth u (plus (car v) 1)) (cdr v)))) )

(de getel (u) (getel1 (get (car u) 'array) (cdr u)))

(de setel (u v)
  (prog (x n)
    (setq x (reverse (cdr u)))
    (setq n (car x))
    (setq x (getel1 (get (car u) 'array) (reverse (cdr x))))
a   (cond ((equal n 0) (return (rplaca x v))))
    (setq n (difference n 1))
    (setq x (cdr x))
    (go a)))

(de assoc (u v)
  (cond ((null v) nil) ((eq u (caar v)) (car v)) (t (assoc u (cdr v)))) )

(de on1 (u)
  (prog (x y z)
    (setq x (remcomma (xread nil)))
a   (cond
      ((null x) (return (mkprog nil z)))
      ((or (not (atom (car x))) (numberp (car x))) (go c)))
    (setq z
      (cons
        (mkform
          'setq
          (list
            (compress (append (explode "*") (explode (car x))))
            (mkvar u nil)))
        z))
    (cond
      ((setq y (assoc u (get (car x) 'simpfg)))
        (setq z (append (mapcar (cdr y) (function mkforml)) z))))
b   (setq x (cdr x))
    (go a)
c   (lprie (list (car x) "INVALID ARGUMENT"))
    (go b)))

(de mkforml (u) (mkform (car u) (cdr u)))

(de onstat nil (on1 t))

(de offstat nil (on1 nil))

(put 'on 'stat 'onstat)

(put 'off 'stat 'offstat)

(lose '(assoc))

(de defstat nil
  (prog (x y)
a   (setq x (scan))
b   (cond
      ((flagp!*!* x 'delim) (return nil))
      ((eq x '!*comma!*) (go a))
      ((or (not (atom x)) (numberp x)) (go er)))
    (setq y (scan))
    (cond ((not (eq y 'equal)) (go er)))
    (put x 'newnam (xread t))
    (setq x cursym!*)
    (go b)
er  (symerr 'define t)))

(put 'define 'stat 'defstat)

(de writstat nil
  (prog (mode x y z)
    (setq mode (eq !*mode 'symbolic))
    (setq x (remcomma (xread 'lambda)))
a   (cond
      ((null x)
        (return
          (mkprog
            nil
            (cons
              (cond (mode (mkform 'terpri nil)) (t (mkform 'terpri!* (list t))))
              y))))
      ((not mode) (go c)))
    (setq z (mkform 'princ (list (car x))))
    (cond ((null (cdr x)) (setq z (list 'return z))))
b   (setq y (aconc y z))
    (setq x (cdr x))
    (go a)
c   (setq z (mkex (car x)))
    (setq z (mkform 'varpri (list z (mkquote (assgnl z)) (not (cdr x)))) )
    (go b)))

(put 'write 'stat 'writstat)

(de lamstat nil
  (prog (x y)
    (cond ((not (eq !*mode 'symbolic)) (symerr "ALGEBRAIC" t)))
    (setq x (xread 'lambda))
    (flagtype (setq x (cond ((null x) nil) (t (remcomma x)))) 'scalar)
    (setq y (list 'lambda x (xread t)))
    (remtype x)
    (return y)))

(put 'lambda 'stat 'lamstat)

(de refg nil
  (prog (x)
    (setq x echol!*)
    (setq echol!* !*echo)
    (setq !*echo x)))

(de inout (u v)
  (prog (fl)
    (setq echol!* !*echo)
    (setq intl!* !*int)
a   (cond ((null u) (go d)))
    (setq fl (car u))
    (cond
      ((eq v 'output) (go c))
      ((eq fl 't) (go l))
      ((member fl ipl!*) (go b1)))
    (open fl v)
    (cond ((null (member fl ipl!*)) (setq ipl!* (cons fl ipl!*))))
b1  (rds (setq ifl!* fl))
    (setq !*echo iecho!*)
    (setq !*int nil)
    (begin1)
    (setq u (cdr u))
    (go a)
c   (cond ((eq fl 't) (go m)) ((member fl opl!*) (go c1)))
    (open fl v)
    (cond ((null (member fl opl!*)) (setq opl!* (cons fl opl!*))))
c1  (wrs (setq ofl!* fl))
d   (cond ((eq v 'input) (refg)))
    (return nil)
l   (rds (setq ifl!* nil))
    (go d)
m   (setq ofl!* nil)
    (wrs nil)))

(de shut (u)
  (prog (x)
a   (cond
      ((null u) (return nil))
      ((member x opl!*) (go b))
      ((not (member x ipl!*)) (rederr (list x "NOT OPEN"))))
    (endifl x)
    (go c)
b   (close x)
    (setq opl!* (delete x opl!*))
    (cond ((not (equal x ofl!*)) (go c)))
    (setq ofl!* nil)
    (wrs nil)
c   (setq u (cdr u))
    (go a)))

(de in (u) (inout u 'input))

(de out (u) (inout u 'output))

(deflist '((in rlis) (out rlis) (shut rlis)) 'stat)

(setq arbl!* nil)

(setq defl!* '((simpfn . operator) (matrix . matrix) (!*!*array . array)))

(setq depl!* nil)

(setq dnl!* nil)

(setq dsubl!* nil)

(setq exlist!* '((!*)))

(setq exptl!* nil)

(setq factors!* nil)

(setq frasc!* nil)

(setq frlis!* nil)

(setq initl!* (append '(subfg!* sstack!* sub2!* tstack!*) initl!*))

(setq letl!* '(let match clear saveas))

(setq sstack!* 0)

(setq slimit!* 30)

(setq typl!* nil)

(setq matp!* nil)

(setq mchfg!* nil)

(setq mcond!* nil)

(setq mod!* nil)

(setq mul!* nil)

(setq ncmp!* nil)

(setq ofl!* nil)

(setq ordn!* 0)

(setq prin!* nil)

(setq rplis!* nil)

(setq subfg!* t)

(setq subl!* nil)

(setq sub2!* nil)

(setq upl!* nil)

(setq wtl!* nil)

(setq !*allfac t)

(setq !*ans 0)

(setq !*div nil)

(setq !*exp t)

(setq !*float nil)

(setq !*gcd nil)

(setq !*hipow nil)

(setq !*match nil)

(setq !*mcd t)

(setq !*mode (progn (setq alglist!* (cons nil nil)) 'symbolic))

(setq !*msg t)

(setq !*nero nil)

(setq !*outp nil)

(setq !*small nil)

(setq !*pri (not !*small))

(setq !*rat nil)

(setq !*resubs t)

(setq !*sqvar!* '(t))

(setq !*super nil)

(setq !*xdn t)

(put 'tstack!* 'initl 0)

(put 'sstack!* 'initl 0)

(put 'subfg!* 'initl t)

(de aproc (u)
  (cond
    ((null u) nil)
    ((atom u)
      (cond ((and (numberp u) (fixp u)) u) (t (list 'aeval (mkarg u)))) )
    ((or (flagp (car u) 'nochange) (get (car u) 'stat)) u)
    ((flagp (car u) 'direct) (cons (car u) (mapcar (cdr u) (function aproc))))
    ((and
       (not (and (atom key!*) (get!* key!* 'stat)))
       (null vars!*)
       (not !*defn)
       (not blockp!*))
      (mkquote (aeval u)))
    (t (list 'aeval (mkarg u)))) )

(flag '(setk setel arrayfn varpri) 'nochange)

(flag
  '(or and not member equal neq eq geq greaterp leq remainder lessp numberp ordp
     flag)
  'direct)

(deflist '((sum (addsq nil . 1)) (product (multsq 1 . 1))) 'bin)

(flag '(sum product) 'delim)

(flag '(sum product) 'nodel)

(deflist
  '((exp ((nil (rmsubs1)) (t (rmsubs))))
     (mcd ((nil (rmsubs)) (t (rmsubs))))
     (fort
       ((nil (setq !*nat nat!*!*)) (t (setq nat!*!* !*nat) (setq !*nat nil))))
     (gcd ((t (rmsubs))))
     (float ((t (rmsubs)))) )
  'simpfg)

(newnam
  '((add cons) (lc cdar) (ldeg cdaar) (lt car) (mult cons) (mvar caaar)
     (lpow caar) (numr car) (denr cdr) (tc cdr)))

(newform
  '((red (lambda (u) (list 'cdr u))) (div (lambda (u v) (list 'cons u v)))) )

% The conversion to Lisp left the next as (infix '(cons cons div)) which
% was a MESS. Really "infix" was to have been a statement parsed by
% INFSTAT, but my automated conversion left it as a raw function call.
% Also the renaming of MULT and ADD was unhelpful!
 
%(setq preclis!* (append (reverse '(mult add div)) preclis!*))
%(mkprec)

(de abs (n) (cond ((minusp n) (minus n)) (t n)))

(de assoc (u v)
  (cond ((null v) nil) ((eq u (caar v)) (car v)) (t (assoc u (cdr v)))) )

(de assoc!* (u v)
  (cond ((null v) nil) ((equal u (caar v)) (car v)) (t (assoc!* u (cdr v)))) )

(de atomlis (u) (or (null u) (and (atom (car u)) (atomlis (cdr u)))) )

(de carx (u)
  (cond
    ((null (cdr u)) (car u))
    (t (rederr (list "MISMATCH OF ARGUMENTS" u)))) )

(de delasc (u v)
  (cond
    ((null v) nil)
    ((or (atom (car v)) (neq u (caar v))) (cons (car v) (delasc u (cdr v))))
    (t (cdr v))))

(de get!* (u v) (cond ((numberp u) nil) (t (get u v))))

(de apply1 (fn arg) (apply fn (list arg)))

(de apply2 (fn a1 a2) (apply fn (list a1 a2)))

(de mapcon (x !*pi!*)
  (cond ((null x) nil)
        (t (nconc (apply1 !*pi!* x) (mapcon (cdr x) !*pi!*)))) )

(de mapcons (u !*s!*) (mapcar u
   (function (lambda (j) (cons !*s!* j)))) )

(de mappend (u !*s!*) (mapcar u
   (function (lambda (j) (append !*s!* j)))) )

(de ncons (u v) (cond ((null u) v) (t (cons u v))))

(de nlist (u n)
  (cond ((equal n 0) nil) (t (cons u (nlist u (difference n 1)))) ))

(de nth (u n) (car (pnth u n)))

(de pnth (u n)
  (cond
    ((null u) (rederr "ELEMENT OUT OF BOUNDS"))
    ((equal n 1) u)
    (t (pnth (cdr u) (difference n 1)))) )

(de pair (x y)
  (cond
    ((and (null x) (null y)) nil)
    ((or (null x) (null y)) (rederr (list "MISMATCH OF ARGUMENTS" x y)))
    (t (cons (cons (car x) (car y)) (pair (cdr x) (cdr y)))) ))

(de permp (u v)
  (cond
    ((null u) t)
    ((eq (car u) (car v)) (permp (cdr u) (cdr v)))
    (t (not (permp (cdr u) (subst (car v) (car u) (cdr v)))) )))

(de posn (u v) (cond ((eq u (car v)) 1) (t (plus (posn u (cdr v)) 1))))

(de revpr (u) (cons (cdr u) (car u)))

(de rplacw (u v)
  (cond
    ((or (atom u) (atom v)) (errach (list 'rplacw u v)))
    (t (rplacd (rplaca u (car v)) (cdr v)))) )

(de repeats (x)
  (cond
    ((null x) nil)
    ((member (car x) (cdr x)) (cons (car x) (repeats (cdr x))))
    (t (repeats (cdr x)))) )

(de spaces (n)
  (cond ((equal n 0) nil) (t (prog2 (princ " ") (spaces (difference n 1)))) ))

(de subla (u v)
  (cond
    ((or (null u) (null v)) v)
    ((atom v) ((lambda (x) (cond (x (cdr x)) (t v))) (assoc v u)))
    (t (cons (subla u (car v)) (subla u (cdr v)))) ))

(de sublis (u v)
  (prog (x)
    (cond ((null u) (return v)))
    (setq x u)
a   (cond
      ((null x)
        (return
          (cond
            ((or
               (atom v)
               (equal (setq x (cons (sublis u (car v)) (sublis u (cdr v)))) v))
              v)
            (t x))))
      ((equal v (caar x)) (return (cdar x))))
    (setq x (cdr x))
    (go a)))

(de union (x y)
  (cond
    ((null x) y)
    (t (union (cdr x) (cond ((member (car x) y) y) (t (cons (car x) y)))) )))

(de xn (u v)
  (cond
    ((null u) nil)
    ((member (car u) v) (cons (car u) (xn (cdr u) (delete (car u) v))))
    (t (xn (cdr u) v))))

(de mespri (u v w x y)
  (prog (nat1 z)
    (cond ((and (null y) (null !*msg)) (return nil)))
    (setq nat1 !*nat)
    (setq !*nat nil)
    (cond ((and ofl!* (or !*fort (not nat1))) (go c)))
a   (lpri
      (cons
        (cond ((null y) "***") (t "*****"))
        (cond ((and u (atom u)) (list u)) (t u))))
    (maprin v)
    (princ " ")
    (lpri (cond ((and w (atom w)) (list w)) (t w)))
    (maprin x)
    (terpri)
    (cond ((null z) (go b)))
    (wrs z)
    (go d)
b   (cond ((null ofl!*) (go d)))
c   (wrs nil)
    (setq z ofl!*)
    (go a)
d   (setq !*nat nat1)
    (cond (y (cond ((eq y 'hold) (setq erfg!* y)) (t (error nil)))) )))

(de errach (u)
  (prog nil
    (terpri!* t)
    (lprie "CATASTROPHIC ERROR *****")
    (printty u)
    (lpriw " " nil)
    (rederr "PLEASE SEND OUTPUT AND INPUT LISTING TO A C HEARN ")))

(de errpri1 (u) (mespri "SUBSTITUTION FOR" u "NOT ALLOWED" nil 'hold))

(de errpri2 (u v) (mespri "SYNTAX" u "INCORRECT" nil v))

(de redmsg (u v)
  (prog nil
    (cond
      ((null !*msg) nil)
      ((and (null ifl!*) !*int) (cond ((redmsg1 u v) nil) (t (error nil))))
      (t (lprim (list u 'declared v))))
    (cond ((not (eq v 'operator)) (return nil)))
    (mespri "PLEASE DO NOT DECLARE OPERATORS BY DEFAULT" nil nil nil nil)
    (mespri "IF YOU DO, YOUR PROGRAM MAY NOT RUN CORRECTLY" nil nil nil nil)
    (mespri "IN FUTURE RELEASES OF REDUCE" nil nil nil nil)))

(de reval (u) (reval1 u t))

(de aeval (u) (reval1 u nil))

(de reval1 (u v)
  (prog (x y)
    (cond
      ((and (numberp u) (fixp u)) (return u))
      ((atom u) nil)
      ((eq (car u) '!*comma!*) (errpri2 u t))
      ((and (eq (car u) '!*sq) (caddr u)) (go b)))
    (mapcar rplis!* (function (lambda (j) (rplacw (cdr j) (car j)))) )
    (setq rplis!* nil)
    (setq x (list u))
    (setq y typl!*)
a   (cond
      ((null y) (go b))
      ((!*apply (car y) x) (return (!*apply (get (car y) 'evfn) x))))
    (setq y (cdr y))
    (go a)
b   (setq u (simp!* u))
    (cond ((null v) (return (mk!*sq u))))
    (setq u (prepsq u))
    (return
      (cond
        ((and (eqcar u 'minus) (numberp (cadr u))) (minus (cadr u)))
        (t u)))) )

(de revlis (u) (mapcar u (function reval)))

(de revop (u v)
  ((lambda (x)
     (cond
       ((or (null v) (numlis (cdr x))) x)
       (t (rederr (list "NON-NUMERICAL ARGUMENT IN" (car u)))) ))
    (cons (car u) (revlis (cdr u)))) )

(de mk!*sq (u)
  (cond
    ((null (car u)) 0)
    ((and (atom (car u)) (equal (cdr u) 1)) (car u))
    (t (cons '!*sq (cons u !*sqvar!*)))) )

(de simp!* (u)
  (prog (x)
    (cond ((and (eqcar u '!*sq!*) (caddr u)) (return (cadr u))))
    (setq x mul!*)
    (setq mul!* nil)
    (setq u (simp u))
a   (cond ((null mul!*) (go b)))
    (setq u (!*apply (car mul!*) (list u)))
    (setq mul!* (cdr mul!*))
    (go a)
b   (setq mul!* x)
    (return (subs2 u))))

(de subs2 (u)
  (prog nil
    (cond (sub2!* (setq u (resimp u))))
    (cond
      ((or (null !*match) (null subfg!*)) (go a))
      (!*small (rederr "LARGER SYSTEM NEEDED")))
    (setq u (subs3q u))
a   (return u)))

(de simp (u)
  (prog (x)
a   (cond
      ((atom u) (return (simpatom u)))
      ((or (not (atom (car u))) (numberp (car u))) (go e))
      ((flagp (car u) 'opfn)
        (setq u (!*eval (cons (car u) (mapcar (cdr u) (function mkquote)))) ))
      ((setq x (get (car u) 'simpfn))
        (return
          (cond
            ((eq x 'iden) (simpiden u))
            (t (!*eval (cons x (list (mkquote (cdr u)))) ))) ))
      ((setq x (opmtch u)) (return (simp x)))
      ((get (car u) '!*!*array) (go d))
      ((setq x (get (car u) 'matrix)) (go m))
      ((get (car u) 'infix) (go e))
      ((member (car u) '(cond prog)) (setq u (!*eval u)))
      (t (prog2 (redmsg (car u) 'operator) (mkop (car u)))) )
    (go a)
d   (setq u (revop u t))
    (setq u (getel u))
    (go a)
m   (cond
      ((not (eqcar x 'mat)) (rederr (list 'matrix (car u) "NOT SET")))
      ((or (not (numlis (setq u (revlis (cdr u)))) ) (neq (length u) 2))
        (go e)))
    (setq u (nth (nth (cdr x) (car u)) (cadr u)))
    (go a)
e   (errpri2 u t)))

(de simpatom (u)
  (prog (z)
    (cond
      ((null u) (go a))
      ((not (numberp u)) (go c))
      ((equal u 0) (go a))
      ((not (fixp u)) (go b))
      ((or (null mod!*) (neq (setq u (cmod u)) 0)) (return (cons u 1))))
a   (return (cons nil 1))
b   (cond (!*float (return (cons u 1))))
    (setq z (fix (times 1000000 u)))
    (setq z
      ((lambda (n) (cons (quotient z n) (quotient 1000000 n)))
        (gcdn 1000000 z)))
    (mespri nil u "REPRESENTED BY" (list 'quotient (car z) (cdr z)) nil)
    (return z)
c   (cond ((flagp u 'share) (return (simp (!*eval u)))) )
    (setq z typl!*)
d   (cond
      ((null z) (return (mksq u 1)))
      ((!*apply (car z) (list u))
        (rederr (list (get (car z) 'name) u "USED AS SCALAR"))))
    (setq z (cdr z))
    (go d)))

(de mkop (u)
  (cond
    ((or (numberp u) (not (atom u))) (rederr (list u "CANNOT BE AN OPERATOR")))
    ((null u) (rederr "LOCAL VARIABLE USED AS OPERATOR"))
    ((defp u 'operator) nil)
    ((member u frlis!*) (rederr (list "OPERATOR" u "CANNOT BE ARBITRARY")))
    (t (put u 'simpfn 'iden))))

(de simpcar (u) (simp (car u)))

(de simpexpt (u)
  (prog (flg m n x)
    (setq n (simp (carx (cdr u))))
    (setq u (car u))
a   (setq m (car n))
a1  (cond
      ((equal u 1) (return (cons 1 1)))
      ((or (not (atom m)) (neq (cdr n) 1)) (go nonumexp)))
    (cond
      ((null m)
        (return (cond ((equal u 0) (rederr " 0/0 FORMED")) (t (cons 1 1)))) )
      ((not (atom u)) (go nonatom))
      ((numberp u)
        (return
          (cond
            ((equal u 0)
              (cond
                ((minusp m) (rederr "ZERO DENOMINATOR"))
                ((null m) (rederr " 0/0 FORMED"))
                (t (cons nil 1))))
            ((minusp m)
              (cond
                (!*mcd (cons 1 (expt u (minus m))))
                ((equal u (minus 1)) (cons (expt u (minus m)) 1))
                (t (cons (cons 1 (expt u (minus m))) 1))))
            (t (cons (expt u m) 1)))) )
      ((flagp u 'share) (go nonatom))
      ((or (not (minusp m)) (not !*mcd)) (return (mksq u m)))
      ((null (cdr (setq x (mksp u (minus m)))) ) (return (invsq (car x))))
      (t (return (list 1 (cons x 1)))) )
nonatom
    (cond ((not (fixp m)) (go nonumexp)))
    (setq x (simp u))
    (cond
      ((not (minusp m)) (return (exptsq x m)))
      (!*mcd (return (invsq (exptsq x (minus m)))) )
      ((null (car x)) (rederr "ZERO DENOMINATOR")))
nonumexp
    (cond
      ((atom u) (go b))
      ((eq (car u) 'times) (go tims))
      ((eq (car u) 'quotient) (go quot))
      ((eq (car u) 'expt) (go exp))
      ((and (eq (car u) 'minus) (numberp m) (equal (cdr n) 1))
        (return
          (multsq (simpexpt (list (minus 1) m)) (simpexpt (list (cadr u) m)))) )
      (flg (go b)))
    (setq flg t)
    (setq u (prepsq (cond ((null x) (simp u)) (t x))))
    (go a1)
b   (cond ((equal u 0) (return (cons nil 1))))
    (cond ((not (numberp m)) (setq m (prepf m))))
    (cond ((member m frlis!*) (return (cons (list (cons (cons u m) 1)) 1))))
    (setq n (prepf (cdr n)))
    (cond
      ((or !*mcd (neq (cdr x) 1) (not (numberp m)) (neq n 1)) (go c))
      ((eq (car u) 'plus) (return (mksq u m))))
c   (cond (!*small (rederr "LARGER SYSTEM NEEDED")) (t (return (simpx1 u m n))))
exp (setq n (multsq (simp (caddr u)) n))
    (setq u (cadr u))
    (go a)
quot(setq n (prepsq n))
    (return
      (multsq
        (simpexpt (list (cadr u) n))
        (simpexpt (list (caddr u) (list 'minus n)))) )
tims(setq n (prepsq n))
    (setq x (simpexpt (list (cadr u) n)))
    (setq u (cddr u))
t1  (cond ((null u) (return x)))
    (setq x (multsq (simpexpt (list (car u) n)) x))
    (setq u (cdr u))
    (go t1)))

(put 'expt 'simpfn 'simpexpt)

(de simpx1 (u m n)
  (prog (flg z)
a   (cond
      ((and (numberp m) (fixp m)) (go e))
      ((atom m) (go b))
      ((eq (car m) 'minus) (go mns))
      ((eq (car m) 'plus) (go pls))
      ((and (eq (car m) 'times) (numberp (cadr m)) (fixp (cadr m))) (go tms)))
b   (setq z 1)
c   (setq u (list 'expt u (cond ((equal n 1) m) (t (list 'quotient m n)))) )
    (cond ((not (member u exptl!*)) (setq exptl!* (cons u exptl!*))))
d   (return (mksq u (cond (flg (minus z)) (t z))))
e   (setq z m)
    (cond ((equal n 1) (go d)))
    (setq m 1)
    (go c)
mns (setq m (cadr m))
    (cond (!*mcd (return (invsq (simpx1 u m n)))) )
    (setq flg (not flg))
    (go a)
pls (setq z (cons 1 1))
pl1 (setq m (cdr m))
    (cond ((null m) (return z)))
    (setq z
      (multsq (simpx1 u (cond (flg (list 'minus (car m))) (t (car m))) n) z))
    (go pl1)
tms (setq z (gcdn n (cadr m)))
    (setq n (quotient n z))
    (setq z (quotient (cadr m) z))
    (setq m (retimes (cddr m)))
    (go c)))

(de invsq (u)
  (cond ((null u) (rederr "ZERO DENOMINATOR")) (t (normsq (revpr u)))) )

(de simpiden (u)
  (prog (y z)
    (setq u (revop u nil))
    (cond
      ((null subfg!*) (go c))
      ((and (flagp (car u) 'linear) (neq (setq z (formlnr u)) u))
        (return (simp z)))
      ((setq z (opmtch u)) (return (simp z)))
      ((flagp (car u) 'symmetric) (setq u (cons (car u) (ordn (cdr u)))) )
      ((flagp (car u) 'antisymmetric) (go d)))
c   (setq u (mksq u 1))
    (return (cond (y (negsq u)) (t u)))
d   (cond
      ((repeats (cdr u)) (return (cons nil 1)))
      ((not (permp (setq z (ordn (cdr u))) (cdr u))) (setq y t)))
    (setq u (cons (car u) z))
    (go c)))

(de simpdiff (u) (addsq (simpcar u) (simpminus (cdr u))))

(put 'difference 'simpfn 'simpdiff)

(de simpminus (u) (negsq (simp (carx u))))

(put 'minus 'simpfn 'simpminus)

(de simpplus (u)
  (prog (z)
    (setq z (cons nil 1))
a   (cond ((null u) (return z)))
    (setq z (addsq (simpcar u) z))
    (setq u (cdr u))
    (go a)))

(put 'plus 'simpfn 'simpplus)

(de simpquot (u) (multsq (simpcar u) (simprecip (cdr u))))

(put 'quotient 'simpfn 'simpquot)

(de simprecip (u)
  (cond
    ((null !*mcd) (simpexpt (list (carx u) (minus 1))))
    (t (invsq (simp (carx u)))) ))

(put 'recip 'simpfn 'simprecip)

(de simptimes (u)
  (prog (x y)
    (cond ((or (neq tstack!* 0) (null mul!*)) (go a0)))
    (setq y mul!*)
    (setq mul!* nil)
a0  (setq tstack!* (plus tstack!* 1))
    (setq x (simpcar u))
a   (setq u (cdr u))
    (cond ((null (car x)) (return (cons nil 1))) ((null u) (go b)))
    (setq x (multsq x (simpcar u)))
    (go a)
b   (cond ((or (null mul!*) (greaterp tstack!* 1)) (go c)))
    (setq x (!*apply (car mul!*) (list x)))
    (setq mul!* (cdr mul!*))
    (go b)
c   (setq tstack!* (difference tstack!* 1))
    (cond ((equal tstack!* 0) (setq mul!* y)))
    (return x)))

(put 'times 'simpfn 'simptimes)

(de simpgts (u) (simp (!*eval (cons 'gts u))))

(put 'gts 'simpfn 'simpgts)

(de simp!*sq (u) (cond ((null (cadr u)) (resimp (car u))) (t (car u))))

(put '!*sq 'simpfn 'simp!*sq)

(de simpsub (u)
  (prog (x z z1)
a   (cond ((null (cdr u)) (go d)) ((not (eqexpr (car u))) (errpri2 (car u) t)))
    (setq x (cadar u))
    (setq z1 typl!*)
b   (cond ((null z1) (go b1)) ((!*apply (car z1) (list x)) (go c)))
    (setq z1 (cdr z1))
    (go b)
b1  (setq x (simp0 x))
    (cond ((not (kernp x)) (error (errpri1 (cadar u)))) )
    (setq x (caaaar x))
c   (setq z (cons (cons x (caddar u)) z))
    (setq u (cdr u))
    (go a)
d   (setq u (simp!* (car u)))
    (return (multsq (subf (car u) z) (subf (cdr u) z)))) )

(de subf (u l)
  (cond
    ((or (null u) (numb u)) (cons u 1))
    (t (prog (m n exp kern w x y y1 z)
        (setq m 0)
        (setq n 0)
        (setq kern (car (caar u)))
        (cond
          ((and (not (atom kern)) (not (atom (car kern))))
            (setq kern (list '!*sq (cons kern 1) nil))))
        (setq z (cons nil 1))
  a     (cond ((or (null u) (equal (deg u kern) 0)) (go b)))
        (setq y (cons (car u) y))
        (setq u (cdr u))
        (go a)
  b     (cond
          ((and l (equal (setq exp (sublis l kern)) kern)) (go f))
          ((null l) (setq exp (cond ((eq kern 'k!*) 1) (t kern)))) )
  c     (setq w (cons 1 1))
        (setq n 0)
        (cond ((lessp (cdaar y) 0) (go h)))
        (setq x (simp exp))
        (cond
          ((and (null l) (kernp x) (eq (car (caar (car x))) kern)) (go f))
          ((null (car x)) (go e)))
  d     (setq m (cdaar y))
        (setq w (multsq (exptsq x (difference m n)) w))
        (setq n m)
        (setq z (addsq (multsq w (subf (cdar y) l)) z))
        (setq y (cdr y))
        (cond (y (go d)))
  e     (return (addsq z (subf u l)))
  f     (setq z (addsq (multpq (caar y) (subf (cdar y) l)) z))
        (setq y (cdr y))
        (cond (y (go f)) (t (go e)))
  h     (setq x (simprecip (list exp)))
  j     (setq y1 (cons (car y) y1))
        (setq y (cdr y))
        (cond ((and y (lessp (cdaar y) 0)) (go j)))
  k     (setq m (minus (cdaar y1)))
        (setq w (multsq (exptsq x (difference m n)) w))
        (setq n m)
        (setq z (addsq (multsq w (subf (cdar y1) l)) z))
        (setq y1 (cdr y1))
        (cond (y1 (go k)) (y (go c)) (t (go e)))) )))

(de resimp (u) (multsq (subf (car u) nil) (invsq (subf (cdr u) nil))))

(put 'sub 'simpfn 'simpsub)

(de eqexpr (u) (and (eqcar u 'equal) (cddr u) (null (cdddr u))))

(de kernp (u)
  (and
    (equal (cdr u) 1)
    (not (atom (car u)))
    (not (atom (caar u)))
    (null (cdar u))
    (equal (cdaar u) 1)
    (equal (cdaaar u) 1)))

(de addsq (u v)
  (cond
    ((null (car u)) v)
    ((null (car v)) u)
    ((and (equal (cdr u) 1) (equal (cdr v) 1)) (cons (addf (car u) (car v)) 1))
    (t (prog (w x y z)
        (setq x (gcdf (cdr u) (cdr v)))
        (setq w (cons (divf (cdr u) x) (divf (cdr v) x)))
        (setq y (addf (multf (car u) (cdr w)) (multf (car v) (car w))))
        (cond ((null y) (return (cons nil 1))))
        (setq z (multf (cdr u) (cdr w)))
        (cond ((equal x 1) (return (cons y z))))
        (setq x (gcdf y x))
        (return
          (cond
            ((equal x 1) (cons y z))
            (t (cons (divf y x) (divf z x)))) ))) ))

(de multsq (u v)
  (cond
    ((or (null (car u)) (null (car v))) (cons nil 1))
    ((and (equal (cdr u) 1) (equal (cdr v) 1)) (cons (multf (car u) (car v)) 1))
    (t (prog (x y)
        (setq x (gcdf (cdr v) (car u)))
        (setq y (gcdf (cdr u) (car v)))
        (return
          (cons
            (multf (divf (car u) x) (divf (car v) y))
            (multf (divf (cdr u) y) (divf (cdr v) x)))) ))) )

(de negsq (u) (cons (negf (car u)) (cdr u)))

(de multpq (u v) (multsq (cons (list (cons u 1)) 1) v))

(de addf (u v)
  (cond
    ((null u) v)
    ((null v) u)
    ((atom u) (addn u v))
    ((atom (car u)) (addr u v))
    ((atom v) (addn v u))
    ((atom (car v)) (addr v u))
    ((equal (caar u) (caar v))
      ((lambda (x y) (cond ((null x) y) (t (cons (cons (caar u) x) y))))
        (addf (cdar u) (cdar v))
        (addf (cdr u) (cdr v))))
    (((lambda (j k)
        (cond
          ((eq (car j) (car k)) (greaterp (cdr j) (cdr k)))
          (ncmp!* (ncmordp (car j) (car k)))
          (t (orderp (car j) (car k)))) )
       (caar u)
       (caar v))
      (cons (car u) (addf (cdr u) v)))
    (t (cons (car v) (addf u (cdr v)))) ))

(de addn (n v)
  (cond
    ((null v) n)
    ((atom v)
      ((lambda (m) (cond ((equal m 0) nil) (t m)))
        (cond ((null mod!*) (plus n v)) (t (cplus (cmod n) (cmod v)))) ))
    ((atom (car v)) (mkfr (plus (times n (cdr v)) (car v)) (cdr v)))
    (t (cons (car v) (addn n (cdr v)))) ))

(de mkfr (u v)
  (cond
    ((equal u 0) nil)
    (!*float (quotient (times 1.0 u) v))
    ((minusp v) (mkfr (minus u) (minus v)))
    (t ((lambda (m)
         ((lambda (n1 n2) (cond ((equal n2 1) n1) (t (cons n1 n2))))
           (quotient u m)
           (quotient v m)))
        (gcdn u v)))) )

(de addr (u v)
  (cond
    ((null v) u)
    ((atom v) (mkfr (plus (times (cdr u) v) (car u)) (cdr u)))
    ((atom (car v))
      (mkfr
        (plus (times (car u) (cdr v)) (times (cdr u) (car v)))
        (times (cdr u) (cdr v))))
    (t (cons (car v) (addr u (cdr v)))) ))

(de multf (u v)
  (prog (x y z)
a0  (cond
      ((or (null u) (null v)) (return nil))
      ((atom u) (return (multn u v)))
      ((atom (car u)) (return (multr u v)))
      ((atom v) (return (multn v u)))
      ((atom (car v)) (return (multr v u)))
      ((or !*exp ncmp!* x) (go a)))
    (setq u (mksfpf u 1))
    (setq v (mksfpf v 1))
    (setq x t)
    (go a0)
a   (setq x (caaar u))
    (setq y (caaar v))
    (cond
      ((not ncmp!*) (go a1))
      ((and (not (atom x)) (flagp!*!* (car x) 'noncom)) (go b))
      ((and (not (atom y)) (flagp!*!* (car y) 'noncom)) (go a2)))
a1  (cond ((eq x y) (go c)) ((orderp x y) (go b)))
a2  (setq x (multf u (cdar v)))
    (setq y (multf u (cdr v)))
    (return (cond ((null x) y) (t (cons (cons (caar v) x) y))))
b   (setq x (multf (cdar u) v))
    (setq y (multf (cdr u) v))
    (return (cond ((null x) y) (t (cons (cons (caar u) x) y))))
c   (setq x
      (cond
        ((equal (setq z (plus (cdaar u) (cdaar v))) 0) (list (cons 1 1)))
        (t (mksp x z))))
    (setq y (addf (multf (list (car u)) (cdr v)) (multf (cdr u) v)))
    (return
      (cond
        ((null (cdr x))
          (cond
            ((null (caar x)) y)
            (t (addf
                (multf
                  (caar x)
                  (multf
                    (cdar u)
                    (cond
                      ((equal (cdar x) 1) (cdar v))
                      (t (multf (mksqf (cons 1 (cdar x))) (cdar v)))) ))
                y))))
        ((null (setq u (multf (cdar u) (cdar v)))) y)
        ((null !*mcd) (addf (list (cons x u)) y))
        (t (cons (cons x u) y)))) ))

(de multf2 (u v) (multf (list (cons u 1)) v))

(de multn (n v)
  (cond
    ((null v) nil)
    ((equal n 1) v)
    ((atom v)
      (cond
        ((null mod!*) (times n v))
        (t ((lambda (m) (cond ((equal m 0) nil) (t m)))
            (ctimes (cmod n) (cmod v)))) ))
    ((atom (car v)) (mkfr (times n (car v)) (cdr v)))
    (t (cons (cons (caar v) (multn n (cdar v))) (multn n (cdr v)))) ))

(de multr (u v)
  (cond
    ((null v) nil)
    ((atom v) (mkfr (times (car u) v) (cdr u)))
    ((atom (car v)) (mkfr (times (car u) (car v)) (times (cdr u) (cdr v))))
    (t (cons (cons (caar v) (multr u (cdar v))) (multr u (cdr v)))) ))

(de negf (u) (multn (minus 1) u))

(de divf (p q)
  (cond
    ((null p) nil)
    ((equal p q) 1)
    ((equal q 1) p)
    ((atom q)
      (cond
        (mod!* (multn (crecip q) p))
        (!*float (multn (quotient 1.0 q) p))
        ((atom p)
          ((lambda (z)
             (cond
               ((equal (cdr z) 0) (car z))
               ((not !*mcd) (mkfr p q))
               (t nil)))
            (divide p q)))
        ((atom (car p)) (mkfr (car p) (times (cdr p) q)))
        (t (divk (caar p) p q))))
    ((atom (car q)) (multr (revpr q) p))
    ((numb p) nil)
    (t ((lambda (x y)
         (cond
           ((eq (car x) (car y))
             ((lambda (n)
                (cond
                  ((or (not (minusp n)) (not !*mcd))
                    ((lambda (w)
                       (cond
                         (w
                           ((lambda (v y)
                              (cond
                                ((null y) v)
                                (t ((lambda (z) (cond (z (append v z)) (t nil)))
                                    (divf y q)))) )
                             (cond
                               ((equal n 0) w)
                               (t (list (cons (mksp (car x) n) w))))
                             (addf
                               p
                               (multf
                                 (cond
                                   ((equal n 0) q)
                                   (t (multf2 (mksp (car x) n) q)))
                                 (negf w)))) )
                         (t nil)))
                      (divf (cdar p) (cdar q))))
                  (t nil)))
               (difference (cdr x) (cdr y))))
           ((orderp (car x) (car y)) (divk x p q))
           (t nil)))
        (caar p)
        (caar q)))) )

(de divk (x p q)
  ((lambda (w)
     (cond
       (w
         (cond
           ((null (cdr p)) (list (cons x w)))
           (t ((lambda (y) (cond (y (cons (cons x w) y)) (t nil)))
               (divf (cdr p) q)))) )
       (t nil)))
    (divf (cdar p) q)))

(de gcdn (p q) (cond ((equal q 0) (abs p)) (t (gcdn q (remainder p q)))) )

(de comfac (p)
  (prog (x y)
    (cond ((null (cdr p)) (return (car p))))
    (setq y (caaar p))
a   (cond
      ((equal (deg p y) 0) (return (cons nil (gcd2 x p))))
      ((null (cdr p)) (return (cons (caar p) (gcd2 x (cdar p)))) )
      ((equal x 1) (go b))
      (t (setq x (gcd2 x (cdar p)))) )
b   (setq p (cdr p))
    (go a)))

(de deg (u var) (cond ((or (numb u) (not (eq (caaar u) var))) 0) (t (cdaar u))))

(de numb (u) (or (atom u) (atom (car u))))

(de gcdf (u v)
  (cond ((or (equal u 1) (equal v 1) !*float) 1) (t (absf (gcd2 u v)))) )

(de gcd2 (u v)
  (cond
    ((null u) v)
    ((null v) u)
    ((or (equal u 1) (equal v 1)) 1)
    ((equal u v) u)
    ((atom u)
      (cond
        ((atom v) (gcdn u v))
        ((atom (car v)) 1)
        (t (gcd2 (cdr v) (gcd2 u (cdar v)))) ))
    ((atom (car u)) 1)
    ((atom v) (gcd2 (cdr u) (gcd2 v (cdar u))))
    ((atom (car v)) 1)
    (t ((lambda (x y)
         (cond
           ((eq x y)
             ((lambda (j k)
                ((lambda (l)
                   (cond
                     ((or (null (car j)) (null (car k))) l)
                     (t (multop
                         (cond
                           ((greaterp (cdar j) (cdar k)) (car k))
                           (t (car j)))
                         l))))
                  (multf
                    (cond
                      ((null !*gcd) 1)
                      (t (gcdk (divf u (gcdl j)) (divf v (gcdl k)))) )
                    (gcd2 (cdr j) (cdr k)))) )
               (comfac u)
               (comfac v)))
           ((ordop x y) (gcd2 (cdr (comfac u)) v))
           (t (gcd2 (cdr (comfac v)) u))))
        (caaar u)
        (caaar v)))) )

(de gcdl (u) (cond ((null (car u)) (cdr u)) (t (list u))))

(de minusf (u)
  (cond
    ((null u) nil)
    ((atom u) (minusp u))
    ((atom (car u)) (minusp (car u)))
    (t (minusf (cdar u)))) )

(de absf (u) (cond ((minusf u) (negf u)) (t u)))

(de normsq (u)
  (cond ((minusf (cdr u)) (cons (negf (car u)) (negf (cdr u)))) (t u)))

(de ordad (a u)
  (cond
    ((null u) (list a))
    ((ordp a (car u)) (cons a u))
    (t (cons (car u) (ordad a (cdr u)))) ))

(de ordn (u)
  (cond
    ((null u) nil)
    ((null (cdr u)) u)
    ((null (cddr u)) (ord2 (car u) (cadr u)))
    (t (ordad (car u) (ordn (cdr u)))) ))

(de ord2 (u v) (cond ((ordp u v) (list u v)) (t (list v u))))

(de ordp (u v)
  (cond
    ((null u) (null v))
    ((null v) t)
    ((atom u)
      (cond
        ((atom v)
          (cond
            ((numberp u) (and (numberp v) (not (lessp u v))))
            ((numberp v) t)
            (t (orderp u v))))
        (t t)))
    ((atom v) nil)
    ((equal (car u) (car v)) (ordp (cdr u) (cdr v)))
    (t (ordp (car u) (car v)))) )

(de exptsq (u n)
  (prog (m x)
    (cond
      ((or (equal n 1) (null (car u))) (return u))
      ((lessp n 0) (return (simpexpt (list (mk!*sq u) n))))
      ((null !*exp) (return (cons (mksfpf (car u) n) (mksfpf (cdr u) n)))) )
    (setq x (cons 1 1))
a   (setq m (quotient n 2))
    (cond ((equal n (times 2 m)) (go b)))
    (setq x (multsq u x))
    (cond ((equal m 0) (return x)))
b   (setq n m)
    (setq u (multsq u u))
    (go a)))

(de exptf (u n) (cond ((or !*exp (kernlp u)) (exptf1 u n)) (t (mksfpf u n))))

(de exptf1 (u n)
  (cond ((equal n 0) 1) (t (multf u (exptf1 u (difference n 1)))) ))

(de mksp (u p)
  (prog (v x y)
    (setq u (fkern u))
    (setq v (cddr u))
a   (cond
      ((null v) (go b))
      ((null subfg!*) (setq sub2!* t))
      ((setq x (assoc 'asymp v)) (go l1))
      ((setq x (assoc 'rep v)) (go l2)))
b   (return (getpower u p))
l1  (cond ((not (lessp p (cdr x))) (return (list (cons nil 1)))) )
    (setq v (delasc (car x) v))
    (go a)
l2  (setq v (cdddr x))
    (setq y (caddr x))
    (cond ((and (neq y 1) (lessp p y)) (go b)) ((car v) (go l3)))
    (setq subl!* (cons v subl!*))
    (setq y (simpcar (cdr x)))
l21 (rplaca v (mk!*sq y))
    (go l31)
l3  (setq y (simpcar v))
    (cond ((and (eqcar (car v) '!*sq) (null (caddar v))) (go l21)))
l31 (setq v y)
    (setq x (caddr x))
    (cond ((equal x 1) (return (list (exptsq v p)))) )
    (setq y (divide p x))
    (setq v (exptsq v (car y)))
    (cond ((not (equal (cdr y) 0)) (setq v (multpq (getpower u (cdr y)) v))))
    (return (list v))))

(de mksp!* (u p) (getpower (fkern u) p))

(de fkern (u)
  (prog (v)
    (cond ((not (atom u)) (go a0)) ((setq v (get u 'aprop)) (return v)))
    (setq v (list u nil))
    (put u 'aprop v)
    (return v)
a0  (cond
      ((not (atom (car u))) (setq v exlist!*))
      ((not (setq v (get (car u) 'klist))) (go b)))
a   (cond
      ((equal u (caar v)) (return (car v)))
      ((ordp u (caar v))
        (return (car (rplacw v (cons (list u nil) (cons (car v) (cdr v)))) )))
      ((null (cdr v)) (return (cadr (rplacd v (list (list u nil)))) )))
    (setq v (cdr v))
    (go a)
b   (setq v (list (list u nil)))
    (put (car u) 'klist v)
    (go a)))

(de getpower (u n)
  (prog (v)
    (cond
      ((and subfg!* (not (assoc 'used!* (cdr u)))) (aconc u (list 'used!*))))
    (setq v (cadr u))
    (cond ((null v) (return (caar (rplaca (cdr u) (list (cons (car u) n)))) )))
a   (cond
      ((equal n (cdar v)) (return (car v)))
      ((lessp n (cdar v))
        (return
          (car (rplacw v (cons (cons (caar v) n) (cons (car v) (cdr v)))) )))
      ((null (cdr v)) (return (cadr (rplacd v (list (cons (caar v) n)))) )))
    (setq v (cdr v))
    (go a)))

(de mksf (u n)
  ((lambda (x)
     (cond
       ((null (cdr x))
         (cond
           ((equal (cdar x) 1) (caar x))
           (t (multf (mksqf (cons 1 (cdar x))) (caar x)))) )
       (t (list (cons x 1)))) )
    (mksp u n)))

(de mksfpf (u n)
  (cond
    ((and (not (minusp n)) (kernlp u)) (exptf1 u n))
    ((atom u) (cons 1 (expt u (minus n))))
    ((atom (car u)) (cons (expt (cdr u) (minus n)) (expt (car u) (minus n))))
    (t (mksf u n))))

(de mksqf (u)
  (prog nil
    (cond
      ((null (car u)) (return nil))
      ((equal (cdr u) 1) (return (car u)))
      ((null !*mcd)
        (return
          (multf
            (car u)
            (mksqf (simpexpt (list (mk!*sq (cons (cdr u) 1)) (minus 1)))) ))) )
    (setq sub2!* t)
    (return
      (cond
        (!*exp (multf (car u) (mksf (mk!*sq (cons 1 (mksfpf (cdr u) 1))) 1)))
        (t (mksf (mk!*sq (cons (car u) (mksfpf (cdr u) 1))) 1)))) ))

(de mksq (u n)
  (prog (x y)
    (cond
      ((or (null subfg!*) (not (setq y (assoc!* u wtl!*)))) (go a))
      ((null (car (setq y (mksq 'k!* (times n (cdr y)))) )) (return y)))
a   (setq x (mksp u n))
    (cond
      ((null (cdr x)) (setq x (car x)))
      (t (setq x (cons (list (cons x 1)) 1))))
    (return (cond (y (multsq y x)) (t x)))) )

(de emtch (u)
  (cond ((atom u) u) (t ((lambda (x) (cond (x x) (t u))) (opmtch u)))) )

(de opmtch (u)
  (prog (x y)
    (setq x (get (car u) 'opmtch))
    (cond (subfg!* (go a)) (x (setq sub2!* t)))
    (return nil)
a   (cond ((null x) (return nil)))
    (setq y (mcharg (cdr u) (caar x) (car u)))
b   (cond
      ((null y) (go c))
      ((!*eval (subla (car y) (cdadar x)))
        (return (subla (car y) (caddar x)))) )
    (setq y (cdr y))
    (go b)
c   (setq x (cdr x))
    (go a)))

(de mcharg (u v w)
  (cond
    ((and (null u) (null v)) (list nil))
    ((flagp w 'symmetric) (mchsarg u v w))
    ((flagp w 'antisymmetric) (mchasarg u v w))
    (t (prog (m n)
        (setq m 0)
        (setq n 0)
        (setq m (length u))
        (setq n (length v))
  a     (cond
          ((not (mtp v)) (go c))
          ((equal m n) (go b))
          ((or (neq n 2) (not (flagp w 'nary)) (lessp m 2)) (return nil))
          (t (setq u (cdr (mkbin w u)))) )
  b     (return (list (pair v (mapcar u (function emtch)))) )
  c     (return (cond ((neq m n) nil) (t (mcharg2 u v (list nil)))) ))) ))

(de mcharg2 (u v w)
  (prog (y z)
    (cond ((null u) (return w)))
    (setq y (mchk (car u) (car v)))
    (setq u (cdr u))
    (setq v (cdr v))
a   (cond ((null y) (return z)))
    (setq z (nconc (mcharg2 u (subla (car y) v) (mappend w (car y))) z))
    (setq y (cdr y))
    (go a)))

(de mchk (u v)
  (cond
    ((equal u v) (list nil))
    ((atom v) (cond ((member v frlis!*) (list (list (cons v u)))) (t nil)))
    ((atom u) nil)
    ((eq (car u) (car v)) (mcharg (cdr u) (cdr v) (car u)))
    (t nil)))

(de mkbin (u v)
  (cond ((null (cddr v)) (cons u v)) (t (list u (car v) (mkbin u (cdr v)))) ))

(de mtp (v)
  (or
    (null v)
    (and
      (member (car v) frlis!*)
      (not (member (car v) (cdr v)))
      (mtp (cdr v)))) )

(de prepsq (u) (cond ((null (car u)) 0) (t (sqform u (function prepf)))) )

(de sqform (u !*pi!*)
  ((lambda (x y) (cond ((equal y 1) x) (t (list 'quotient x y))))
    (apply1 !*pi!* (car u))
    (apply1 !*pi!* (cdr u))))

(de prepf (u) (replus (prepf1 u nil)))

(de prepf1 (u v)
  (cond
    ((null u) nil)
    ((atom u)
      (list
        (retimes
          (cons
            (cond ((minusp u) (list 'minus (minus u))) (t u))
            (exchk v nil)))) )
    ((atom (car u))
      (list
        (retimes
          (cons
            (cond
              ((minusp (car u))
                (list 'minus (list 'quotient (minus (car u)) (cdr u))))
              (t (list 'quotient (car u) (cdr u))))
            (exchk v nil)))) )
    (t (nconc
        (prepf1 (cdar u) (cond ((eq (caaar u) 'k!*) v) (t (cons (caar u) v))))
        (prepf1 (cdr u) v)))) )

(de exchk (u v)
  (cond
    ((null u) v)
    ((equal (cdar u) 1) (exchk (cdr u) (cons (sqchk (caar u)) v)))
    (t (exchk (cdr u) (cons (list 'expt (sqchk (caar u)) (cdar u)) v)))) )

(de replus (u) (cond ((atom u) u) ((null (cdr u)) (car u)) (t (cons 'plus u))))

(de retimes (u)
  (prog (x y)
a   (cond
      ((null u) (go d))
      ((equal (car u) 1) (go c))
      ((not (eqcar (car u) 'minus)) (go b)))
    (setq x (not x))
    (cond ((equal (cadar u) 1) (go c)) (t (setq u (cons (cadar u) (cdr u)))) )
b   (setq y (cons (car u) y))
c   (setq u (cdr u))
    (go a)
d   (setq y (cond ((null y) 1) ((cdr y) (cons 'times (reverse y))) (t (car y))))
    (return (cond (x (list 'minus y)) (t y)))) )

(de sqchk (u)
  (cond
    ((atom u) ((lambda (x) (cond (x x) (t u))) (get u 'newnam)))
    ((eq (car u) '!*sq) (prepsq (cadr u)))
    ((and (eq (car u) 'expt) (equal (caddr u) 1)) (cadr u))
    ((atom (car u)) u)
    (t (prepf u))))

(deflist '((!*sq sqprint)) 'specprn)

(de sqprint (u)
  (prog (z)
    (setq z orig!*)
    (cond ((and !*nat (lessp posn!* 20)) (setq orig!* posn!*)))
    (cond
      (!*pri (go c))
      ((neq (cdar u) 1) (go b))
      (t (xprinf (caar u) nil nil)))
a   (return (setq orig!* z))
b   (princ!* "(")
    (xprinf (caar u) nil nil)
    (princ!* ") / (")
    (xprinf (cdar u) nil nil)
    (princ!* ")")
    (go a)
c   (maprin (setq !*outp (prepsq!* (car u))))
    (go a)))

(de varpri (u v w)
  (prog (x y)
    (cond ((and !*nero (equal u 0) v) (return nil)))
    (cond (!*fort (go fort)))
    (setq x typl!*)
a   (cond
      ((null x) (go b))
      ((and (!*apply (car x) (list u)) (setq y (get (car x) 'prifn)))
        (return (!*apply y (list u v w)))) )
    (setq x (cdr x))
    (go a)
b   (cond ((null v) (go c)))
    (inprint 'setq (get 'setq 'infix) (mapcar v (function !*eval)))
    (oprin 'setq)
c   (maprin u)
    (cond
      ((null w) (return nil))
      ((and (not !*nat) (not !*fort)) (princ!* !*!*dollar)))
    (terpri!* (not !*nat))
    (return nil)
fort(setq count!* 1)
    (cond ((and (atom u) (not (numberp u))) (go c)))
    (setq fortvar!*
      (cond ((or (null v) (not (atom (setq v (!*eval (car v)))) )) 'ans) (t v)))
    (cond ((greaterp posn!* 5) (go c)))
    (spaces 6)
    (princ fortvar!*)
    (oprin 'equal)
    (setq posn!* (plus (length (explode fortvar!*)) 7))
    (go c)))

(de xprinf (u v w)
  (prog nil
a   (cond
      ((null u) (return nil))
      ((not (numb u)) (go b))
      ((minusf u) (go a1))
      (v (oprin 'plus)))
a0  (cond
      ((or (not w) (neq u 1))
        (cond
          ((atom u) (princ!* u))
          (t (maprin (list 'quotient (car u) (cdr u)))) )))
    (return nil)
a1  (oprin 'minus)
    (setq u (cond ((atom u) (minus u)) (t (cons (minus (car u)) (cdr u)))) )
    (go a0)
b   (xprint (car u) v)
    (setq u (cdr u))
    (setq v t)
    (go a)))

(de xprint (u v)
  (prog (flg)
    (setq flg (and (not (atom (cdr u))) (cddr u)))
    (cond ((not flg) (go a)) (v (oprin 'plus)))
    (princ!* "(")
a   (xprinf (cdr u) (cond (flg nil) (t v)) (not flg))
    (cond (flg (princ!* ")")))
    (cond
      ((or (not (atom (cdr u))) (not (equal (abs (cdr u)) 1))) (oprin 'times)))
    (setq u (car u))
    (cond
      ((atom (car u)) (princ!* (car u)))
      ((or (not (atom (caar u))) (eq (caar u) '!*sq)) (go c))
      ((eq (caar u) 'plus) (maprint (car u) 100))
      (t (maprin (car u))))
b   (cond ((equal (cdr u) 1) (return nil)))
    (oprin 'expt)
    (princ!* (cdr u))
    (cond ((not !*nat) (return nil)))
    (setq ycoord!* (difference ycoord!* 1))
    (cond ((greaterp ymin!* ycoord!*) (setq ymin!* ycoord!*)))
    (return nil)
c   (princ!* "(")
    (cond
      ((not (atom (caar u))) (xprinf (car u) nil nil))
      (t (sqprint (cdar u))))
    (princ!* ")")
    (go b)))

(setq !*echo t)

(setq count!* 1)

(setq llength!* 67)

(setq obrkp!* t)

(setq orig!* 0)

(setq pline!* nil)

(setq !*cardno 20)

(setq !*fort nil)

(setq !*list nil)

(setq !*nat t)

(setq fortvar!* 'ans)

(setq posn!* 0)

(setq ycoord!* 0)

(setq ymax!* 0)

(setq ymin!* 0)

(flag '(!*cardno) 'share)

(de mathprint (l)
  (prog nil
    (terpri!* t)
    (maprin l)
    (terpri!* t)))

(de maprin (u) (maprint u 0))

(de maprint (l p)
  (prog (x y)
    (cond
      ((null l) (return nil))
      ((atom l) (go b))
      ((stringp l) (return (princ!* l)))
      ((not (atom (car l))) (maprint (car l) p))
      ((setq x (get (car l) 'infix)) (go a))
      ((setq x (get (car l) 'specprn)) (return (!*apply x (list (cdr l)))) )
      (t (princ!* (car l))))
    (princ!* "(")
    (setq obrkp!* nil)
    (inprint '!*comma!* 0 (cdr l))
    (setq obrkp!* t)
e   (return (princ!* ")"))
b   (cond
      ((numberp l) (go d))
      ((setq x (get l 'oldnam)) (return (maprint x p))))
c   (return (princ!* l))
d   (cond ((not (minusp l)) (go c)))
    (princ!* "(")
    (princ!* l)
    (go e)
a   (setq p (not (greaterp x p)))
    (cond ((not p) (go g)))
    (setq y orig!*)
    (princ!* "(")
    (cond ((lessp posn!* 15) (setq orig!* posn!*)))
g   (inprint (car l) x (cdr l))
    (cond ((not p) (return nil)))
    (princ!* ")")
    (setq orig!* y)))

(de inprint (op p l)
  (prog nil
    (cond ((get op 'alt) (go a)))
    (maprint (car l) p)
a0  (setq l (cdr l))
a   (cond
      ((null l) (return nil))
      ((and (not (atom (car l))) (eq op (get!* (caar l) 'alt))) (go b)))
    (oprin op)
b   (maprint (car l) p)
    (cond ((or (not !*nat) (not (eq op 'expt))) (go a0)))
    (setq ycoord!* (difference ycoord!* 1))
    (cond ((greaterp ymin!* ycoord!*) (setq ymin!* ycoord!*)))
    (go a0)))

(de oprin (op)
  ((lambda (x)
     (cond
       ((null x) (princ!* op))
       (!*fort (princ!* (cadr x)))
       ((and !*list obrkp!* (member op '(plus minus)))
         (prog nil
           (terpri!* t)
           (princ!* (car x))))
       ((and !*nat (eq op 'expt))
         (prog nil
           (setq ycoord!* (plus ycoord!* 1))
           (cond ((greaterp ycoord!* ymax!*) (setq ymax!* ycoord!*)))) )
       (t (princ!* (car x)))) )
    (get op 'prtch)))

(de princ!* (u)
  (prog (m n v)
    (setq m 0)
    (setq n 0)
    (setq v (explode u))
    (setq n (length v))
    (cond ((greaterp n llength!*) (go d)))
a   (setq m (plus posn!* n))
    (cond
      (!*fort (go f1))
      ((greaterp m llength!*) (go c))
      ((not !*nat) (princ u))
      (t (setq pline!*
          (cons (cons (cons (cons posn!* m) ycoord!*) u) pline!*))))
b   (return (setq posn!* m))
c   (terpri!* t)
    (go a)
d   (cond
      (!*fort (rederr (list u "TOO LONG FOR FORTRAN")))
      ((not !*nat) (go d4)))
d1  (setq m posn!*)
d2  (cond ((equal m llength!*) (go d3)))
    (princ!* (car v))
    (setq m (plus m 1))
    (setq v (cdr v))
    (cond ((null v) (go b)))
    (go d2)
d3  (terpri!* t)
    (go d1)
d4  (princ u)
    (setq m (remainder n llength!*))
    (go b)
f1  (cond
      ((and (equal count!* !*cardno) (or (eq u '!+) (eq u '!-))) (go f4))
      ((lessp m llength!*) (go f2)))
    (terpri)
    (spaces 5)
    (princ 'x)
    (setq posn!* (plus n 6))
    (setq count!* (plus count!* 1))
    (go f3)
f2  (setq posn!* m)
f3  (return (princ u))
f4  (terpri)
    (spaces 6)
    (princ fortvar!*)
    (oprin 'equal)
    (princ fortvar!*)
    (setq posn!* 20)
    (go f3)))

(de terpri!* (u)
  (prog (n)
    (setq n 0)
    (cond (!*fort (go d)) ((or (not pline!*) (not !*nat)) (go b)))
    (setq n ymax!*)
    (setq pline!* (reverse pline!*))
a   (scprint pline!* n)
    (terpri)
    (cond ((equal n ymin!*) (go b)))
    (setq n (difference n 1))
    (go a)
b   (cond (u (terpri)))
c   (setq pline!* nil)
    (setq posn!* orig!*)
    (setq ycoord!* (setq ymax!* (setq ymin!* 0)))
    (return nil)
d   (cond ((equal posn!* orig!*) (go c)))
    (setq count!* 1)
    (go b)))

(de scprint (u n)
  (prog (m)
    (setq posn!* 0)
a   (cond
      ((null u) (return nil))
      ((not (equal (cdaar u) n)) (go b))
      ((not (minusp (setq m (difference (caaaar u) posn!*)))) (spaces m)))
    (princ (cdar u))
    (setq posn!* (cdaaar u))
b   (setq u (cdr u))
    (go a)))

(de forallfn nil
  (prog nil
    (flag letl!* 'delim)
    (setq arbl!* (remcomma (xread nil)))
    (remflag letl!* 'delim)
    (return (iflet1))))

(de iflet (u)
  (prog nil
    (setq mcond!* (mkex u))
    (return (iflet1))))

(de iflet1 nil
  (prog (x y z)
    (setq z arbl!*)
    (cond ((setq x (xn z vars!*)) (rederr (cons "TYPE CONFLICT FOR" x))))
    (setq x (mapcar z (function newvar)))
    (setq y (pair z x))
    (setq vars!* (append x vars!*))
    (setq mcond!* (subla y mcond!*))
    (setq frlis!* (union x frlis!*))
    (setq z (list (xread1 nil)))
    (cond
      (mcond!*
        (setq z (cons (mkform 'setq (list 'mcond!* (mkquote mcond!*))) z))))
    (cond
      (y
        (setq z
          (cons
            (mkform 'setq (list 'frasc!* (mkquote y)))
            (cons (mkform 'setq (list 'frlis!* (mkquote frlis!*))) z)))) )
    (setq mcond!* nil)
    (setq vars!* (setdiff vars!* x))
    (setq arbl!* nil)
    (return (mkprog nil z))))

(de arb (u) (car (setq arbl!* (cons u arbl!*))))

(newform '((arb (lambda (u) (arb u)))) )

(de newvar (u) (compress (cons !*!*fmark (explode u))))

(put 'forall 'stat 'forallfn)

(de let (u) (let0 u nil))

(de let0 (u v)
  (prog nil
a   (cond
      ((null u) (return (setq mcond!* (setq frasc!* nil))))
      ((not (eqexpr (car u))) (errpri2 (car u) 'hold))
      (t (let2 (cadar u) (car (cddar u)) v t)))
    (setq u (cdr u))
    (go a)))

(de let1 (u v) (let2 u v nil t))

(de let2 (u v w b)
  (prog (flg x y z)
    (cond
      ((or
         (atom u)
         (null frasc!*)
         (not (setq flg (xn (mapcar frasc!* (function car)) (flatten u)))) )
        (go a)))
    (setq u (subla frasc!* u))
    (cond ((eqcar v '!*sq) (setq v (list (car v) (cadr v) nil))))
    (setq v (subla frasc!* v))
a   (setq x u)
    (cond ((numberp x) (go ler1)))
    (setq y typl!*)
b   (cond
      ((null y) (go c))
      ((or (setq z (!*apply (car y) (list x))) (!*apply (car y) (list v)))
        (return
          (!*apply (get (car y) 'letfn) (list x v (get (car y) 'name) b z)))) )
    (setq y (cdr y))
    (go b)
c   (cond
      ((not (atom x)) (go nonatom))
      ((and (setq y (get x 'oldnam)) (not (member y (flatten v))))
        (let2 y v w b)))
    (cond (b (go d)))
    (remprop x 'newnam)
    (remprop x 'oldnam)
    (remprop x 'opmtch)
    (remprop x 'aprop)
    (remprop x 'klist)
    (remprop x 'matrix)
    (cond ((not (setq y (get x '!*!*array))) (go c1)))
    (!*array (list (cons x (add1lis y))))
c1  (rmsubs)
    (return nil)
d   (setq x (simp0 x))
    (cond
      ((not (equal (cdr x) 1)) (go ler1))
      ((or w flg (numb (car x)) (cdar x) (neq (cdaar x) 1)) (go prodct)))
nonpdt
    (setq x (caaar x))
    (setq z (fkern (car x)))
    (cond
      ((null b) (return (rplacd (cdr z) nil)))
      ((assoc 'used!* (cdr z)) (rmsubs2)))
    (xadd
      (cond
        ((and (equal v 0) (not (equal (cdr x) 1))) (cons 'asymp (cdr x)))
        (t (list 'rep v (cdr x) nil)))
      (cdr z)
      (sqchk (car z))
      t)
    (rplacw z (delasc 'dfn z))
    (return nil)
nonatom
    (cond
      ((or (not (atom (car x))) (numberp (car x))) (go ler2))
      ((get (car x) '!*!*array) (go arr))
      ((eq (car x) 'df) (go diff))
      ((setq y (get (car x) 'matrix)) (return (letmtr u v y)))
      ((not (get (car x) 'simpfn)) (go ler3))
      (t (go d)))
prodct
    (cond ((not (setq y (kernlp (car x)))) (go n)) ((neq y 1) (go ler1)))
    (rmsubs)
    (setq x (klistt (car x)))
    (setq y (list (cons w (cond (mcond!* mcond!*) (t t))) v nil))
    (cond
      ((or w (cdr x) (neq (cdar x) 1))
        (return (setq !*match (xadd (cons x y) !*match u b)))) )
    (setq x (caar x))
    (cond ((atom x) (go ler1)))
    (return
      (put (car x) 'opmtch (xadd (cons (cdr x) y) (get (car x) 'opmtch) u b)))
diff(cond ((null (letdf u v w x b)) (go d)) (t (return nil)))
arr (cond
      ((and (setq z (assoc!* x (get (car x) 'klist))) (assoc 'used!* (cdr z)))
        (rmsubs2)))
    (setel (revop x t) v)
    (return nil)
n   (cond ((and !*super (setq x (cons (mksfpf (car x) 1) 1))) (go nonpdt)))
ler1(return (errpri1 u))
ler2(return (errpri2 u 'hold))
ler3(redmsg (car x) 'operator)
    (mkop (car x))
    (go a)))

(de simp0 (u)
  (prog (x)
    (setq x (cons subfg!* sub2!*))
    (setq subfg!* nil)
    (setq u (simp u))
    (setq subfg!* (car x))
    (setq sub2!* (cdr x))
    (return u)))

(de match (u) (let0 u t))

(de clear (u)
  (prog nil
    (rmsubs)
a   (cond ((null u) (return (setq mcond!* (setq frasc!* nil)))) )
    (let2 (car u) nil nil nil)
    (setq u (cdr u))
    (go a)))

(de setk (u v) (prog2 (let1 (cond ((atom u) u) (t (revop u nil))) v) v))

(de klistt (u)
  (cond ((atom u) nil) (t (cons (caar u) (klistt (cdr (carx u)))) )))

(de kernlp (u) (cond ((numb u) u) ((null (cdr u)) (kernlp (cdar u))) (t nil)))

(de rmsubs nil (prog2 (rmsubs1) (rmsubs2)))

(de rmsubs2 nil (prog2 (rplaca !*sqvar!* nil) (setq !*sqvar!* (list t))))

(de rmsubs1 nil
  (prog nil
    (!~map (append dsubl!* subl!*) (function (lambda (j) (rplaca (car j) nil))))
    (setq dsubl!* (setq subl!* nil))))

(de xadd (u v w b)
  (prog (x)
    (setq x (assoc!* (car u) v))
    (cond ((null x) (go c)) ((null b) (go b1)))
    (rmsubs1)
    (rplacd x (cdr u))
a   (return v)
b1  (setq v (delete x v))
    (go a)
c   (cond
      ((null b) (mespri nil w "NOT FOUND" nil nil))
      (t (setq v (aconc v u))))
    (go a)))

(put 'clear 'stat 'rlis)

(put 'let 'stat 'rlis)

(put 'match 'stat 'rlis)

(flag '(let match) 'quote)

(de opstat nil
  (prog (x y)
    (setq x cursym!*)
    (setq y (remcomma (xread nil)))
    (return
      (cond
        ((eq !*mode 'symbolic)
          (mkprog
            nil
            (list (mkform 'flag (list (mkquote y) (mkquote 'opfn)))) ))
        ((neq x 'operator)
          (cond
            ((eqcar (car y) 'prog) (car y))
            (t (cons x (mapcar (list y) (function mkarg)))) ))
        ((and (neq key!* 'operator) (get key!* 'fn))
          ((lambda (!*s!*)
             (mkprog
               nil
               (mapcar
                 y
                 (function
                   (lambda (j)
                     (mkform 'put (list (mkquote j) !*s!* !*s!*)))) )))
            (mkquote (get key!* 'fn))))
        (t (mkprog
            nil
            (list (mkform 'mapcar (list (mkquote y) '(function mkop)))) ))) )))

(put 'operator 'stat 'opstat)

(de den (u) (mk!*sq (cons (cdr (simp!* u)) 1)))

(de num (u) (mk!*sq (cons (car (simp!* u)) 1)))

(flag '(den num) 'opfn)

(de saveas (u)
  (prog nil
    (let1 u !*ans)))

(put 'saveas 'stat 'norlis)

(de terms (u) (terms1 (car (simp!* u))))

(flag '(terms) 'opfn)

(de terms1 (u)
  (prog (n)
    (setq n 0)
    (setq n 0)
a   (cond ((null u) (return n)) ((atom u) (return (plus n 1))))
    (setq n (plus n (terms1 (cdar u))))
    (setq u (cdr u))
    (go a)))

(de denom (u) (let1 u (mk!*sq (cons (cdr (simp !*ans)) 1))))

(de numer (u) (let1 u (mk!*sq (cons (car (simp !*ans)) 1))))

(de nd (u v) (prog2 (numer u) (denom v)))

(put 'denom 'stat 'norlis)

(put 'numer 'stat 'norlis)

(put 'nd 'stat 'norlis)

(deflist '((cos iden) (sin iden) (log iden)) 'simpfn)

(let1 '(expt i 2) (minus 1))

(let1 '(log e) 1)

(let1 '(log 1) 0)

(let1 '(cos 0) 1)

(let1 '(sin 0) 0)

(deflist
  '((expt
      (((x y) times y (expt x (plus y (minus 1))))
        ((x y) times (log x) (expt x y))))
     (log (((x) quotient 1 x)))
     (cos (((x) minus (sin x))))
     (sin (((x) cos x))))
  'dfn)

(deflist
  '((cos ((((minus !*!*!*x)) (nil . t) (cos !*!*!*x) nil)))
     (sin ((((minus !*!*!*x)) (nil . t) (minus (sin !*!*!*x)) nil))))
  'opmtch)

(setq frlis!* '(!*!*!*x))

(flagop (list 'share))

(flag '(!*ans !*mode) 'share)

(de simpdf (u)
  (prog (v x y)
    (cond ((null subfg!*) (return (mksq (cons 'df u) 1))))
    (setq v (cdr u))
    (setq u (simpcar u))
a   (cond ((or (null v) (null (car u))) (return u)))
    (setq x (cond ((or (null y) (equal y 0)) (simpcar v)) (t y)))
    (cond ((null (kernp x)) (go e)))
    (setq x (caaaar x))
    (setq v (cdr v))
    (cond ((null v) (go c)))
    (setq y (simpcar v))
    (cond
      ((null (car y)) (go d))
      ((or (not (equal (cdr y) 1)) (not (numberp (car y)))) (go c)))
    (setq y (car y))
    (setq v (cdr v))
b   (cond ((equal y 0) (go a)))
    (setq u (diffsq u x))
    (setq y (difference y 1))
    (go b)
c   (setq u (diffsq u x))
    (go a)
d   (setq y nil)
    (setq v (cdr v))
    (go a)
e   (mespri "DIFFERENTIATION WRT" (prepsq x) "NOT ALLOWED" nil t)))

(put 'df 'simpfn 'simpdf)

(de diffsq (u v)
  (multsq
    (addsq (difff (car u) v) (negsq (multsq u (difff (cdr u) v))))
    (cons 1 (cdr u))))

(de difff (u v)
  (cond
    ((numb u) (cons nil 1))
    (t (addsq
        (addsq
          (multpq (caar u) (difff (cdar u) v))
          (multsq (cons (cdar u) 1) (diffp (caar u) v)))
        (difff (cdr u) v)))) )

(de diffp (u v)
  (prog (w x x1 y z)
    (setq y (fkern (car u)))
    (cond
      ((and (eq (car u) v) (setq w (cons 1 1))) (go e))
      ((or (atom (car u)) (and (atom (caar u)) (get (caar u) '!*!*array)))
        (go f))
      ((and
         (setq x (assoc 'dfn (cddr y)))
         (setq x (assoc v (cadr x)))
         (setq w (cdr x)))
        (go e))
      ((or
         (and (not (atom (caar u))) (setq w (difff (car u) v)))
         (and (eq (caar u) '!*sq) (setq w (diffsq (cadar u) v))))
        (go c))
      ((setq x (get!* (caar u) 'dfn)) nil)
      ((and (eq (caar u) 'plus) (setq w (diffsq (simpcar u) v))) (go c)))
    (setq x1 x)
    (setq z (cdar u))
a   (setq w (cons (diffsq (simp (car z)) v) w))
    (cond ((and (caar w) (null (car x1))) (go h)))
    (setq x1 (cdr x1))
    (setq z (cdr z))
    (cond ((and z x1) (go a)) ((or z x1) (go h)))
    (setq x1 (reverse w))
    (setq z (cdar u))
    (setq w (cons nil 1))
b   (cond
      ((caar x1)
        (setq w
          (addsq
            (multsq (car x1) (simp (subla (pair (caar x) z) (cdar x))))
            w))))
    (setq x (cdr x))
    (setq x1 (cdr x1))
    (cond (x1 (go b)))
c   (cond
      ((setq x (assoc 'dfn (cddr y))) (go d))
      (t (aconc y (setq x (list 'dfn nil)))) )
    (setq dsubl!* (cons (cdr x) dsubl!*))
d   (rplaca (cdr x) (xadd (cons v w) (cadr x) nil t))
    (cond ((null (car x)) (go f)))
e   (cond
      ((setq x (assoc (car u) wtl!*))
        (setq w (multpq (mksp 'k!* (minus (cdr x))) w))))
    (return
      (cond
        ((equal (cdr u) 1) w)
        (t (multsq
            (cons (multf2 (getpower y (difference (cdr u) 1)) (cdr u)) 1)
            w))))
f   (cond ((not (assoc 'rep (cddr y))) (return (cons nil 1))))
    (setq w (mksq (list 'df (car u) v) 1))
    (go e)
h   (setq w
      (cond
        ((eq (caar u) 'df) (cons 'df (cons (cadar u) (derad v (cddar u)))) )
        (t (list 'df (car u) v))))
    (setq w (cond ((setq x (opmtch w)) (simp x)) (t (mksq w 1))))
    (go e)))

(de derad (u v)
  (cond
    ((null v) (list u))
    ((numberp (car v)) (cons (car v) (derad u (cdr v))))
    ((equal u (car v))
      (cond
        ((and (cdr v) (numberp (cadr v)))
          (cons u (cons (plus (cadr v) 1) (cddr v))))
        (t (cons u (cons 2 (cdr v)))) ))
    ((ordp u (car v)) (cons u v))
    (t (cons (car v) (derad u (cdr v)))) ))

(de letdf (u v w x b)
  (prog (z)
    (cond
      ((or (and (not (atomlis (cadr x))) (cdddr x)) (numberp (caadr x)))
        (return (list (errpri1 u))))
      ((not (defp (caadr x) nil)) (go ler3)))
a   (cond
      ((or
         (not (frlp (cdadr x)))
         (not (frlp (cddr x)))
         (not (member (caddr x) (cdadr x))))
        (return nil)))
    (setq z (posn (caddr x) (cdadr x)))
    (cond
      ((not (get (caadr x) 'dfn))
        (put (caadr x) 'dfn (nlist nil (length (cdadr x)))) ))
    (setq w (get (caadr x) 'dfn))
b   (cond
      ((or (null w) (equal z 0)) (return (errpri1 u)))
      ((neq z 1) (go c))
      ((car w) (mespri "ASSIGNMENT FOR" x "REDEFINED" nil nil)))
    (return (rplaca w (cons (cdadr x) v)))
c   (setq w (cdr w))
    (setq z (difference z 1))
    (go b)
ler3(redmsg (caadr x) 'operator)
    (mkop (caadr x))
    (go a)))

(de frlp (u) (or (null u) (and (member (car u) frlis!*) (frlp (cdr u)))) )

(de subs3q (u)
  (prog (x)
    (setq x mchfg!*)
    (setq mchfg!* nil)
    (setq u (multsq (subs3f (car u)) (invsq (subs3f (cdr u)))) )
    (setq mchfg!* x)
    (return u)))

(de subs3f (u) (subs3f1 u !*match t))

(de subs3f1 (u l bool)
  (prog (x z)
    (setq z (cons nil 1))
a   (cond ((null u) (return z)) ((numb u) (return (addsq z (cons u 1)))) )
    (setq x (subs3t (car u) l))
    (cond ((or (not bool) (not mchfg!*)) (go b)))
    (setq mchfg!* nil)
    (cond (!*resubs (setq x (subs3q x))))
b   (setq z (addsq z x))
    (setq u (cdr u))
    (go a)))

(de subs3t (u v)
  (prog (x y z)
    (setq x (mtchk (car u) (cond ((numb (cdr u)) (sizchk v 1)) (t v))))
    (cond ((null x) (go a)) ((null (caar x)) (go b)))
    (setq y (subs3f1 (cdr u) x nil))
    (cond (mchfg!* (return (multsq (cons (list (cons (car u) 1)) 1) y))))
a   (return (cons (list u) 1))
b   (setq x (cddar x))
    (setq z (caadr x))
    (setq mchfg!* nil)
    (setq y (subs3f1 (cdr u) !*match nil))
    (setq mchfg!* t)
    (cond
      ((neq (car z) (caar u)) (errach 'subs3t u x))
      ((neq z (car u))
        (setq y (multpq (mksp!* (caar u) (difference (cdar u) (cdr z))) y))))
    (setq y (multsq (simpcar x) y))
    (setq x (cdadr x))
    (cond ((null x) (return y)))
    (setq z 1)
c   (setq u !*mcd)
    (cond ((null x) (go d)))
    (setq z
      (list
        (cons (mksp!* (caar x) (cond (u (cdar x)) (t (minus (cdar x)))) ) z)))
    (setq x (cdr x))
    (go c)
d   (return
      (cond
        (u (cons (car y) (multf z (cdr y))))
        (t (cons (multf z (car y)) (cdr y)))) )))

(de sizchk (u n)
  (cond
    ((null u) nil)
    ((greaterp (length (caar u)) n) (sizchk (cdr u) n))
    (t (cons (car u) (sizchk (cdr u) n)))) )

(de mtchk (u v1)
  (prog (flg v w x y z)
    (setq flg (and (not (atom (car u))) (flagp!*!* (caar u) 'noncom)))
a0  (cond ((null v1) (return z)))
    (setq v (car v1))
    (setq w (car v))
a   (cond
      ((null w) (go d))
      ((equal u (car w)) (go b1))
      ((or
         (and
           (not (member (cdar w) frlis!*))
           (or
             (and (caadr v) (not (equal (cdr u) (cdar w))))
             (cond
               (!*mcd (lessp (cdr u) (cdar w)))
               (t (or
                   (minusp (times (cdr u) (cdar w)))
                   (lessp (abs (cdr u)) (abs (cdar w)))) ))) )
         (not (setq y (mchk (car u) (caar w)))) )
        (go c))
      ((member (cdar w) frlis!*) (setq y (mapcons y (cons (cdar w) (cdr u)))) ))
b   (cond
      ((null y) (go c))
      ((car
         (setq x
           (cons
             (subla (car y) (delete (car w) (car v)))
             (list
               (subla (car y) (cadr v))
               (subla (car y) (caddr v))
               (cons (subla (car y) (car w)) (cadddr v)))) ))
        (setq z (cons x z)))
      ((!*eval (subla (car y) (cdadr v))) (return (list x))))
    (setq y (cdr y))
    (go b)
b1  (setq y (list nil))
    (go b)
c   (cond (flg (go c1)))
    (setq w (cdr w))
    (go a)
c1  (cond ((and (cadddr v) (not (nocp (cadddr v)))) (go e)))
d   (setq z (append z (list v)))
e   (setq v1 (cdr v1))
    (go a0)))

(de nocp (u)
  (or
    (null u)
    (atom (caar u))
    (and (not (flagp!*!* (caaar u) 'noncom)) (nocp (cdr u)))) )

(de mchsarg (!*s!* v w)
  (prog (y z m n)
    (setq m 0)
    (setq n 0)
    (setq m (length !*s!*))
    (setq n (length v))
    (cond
      ((not (mtp v)) (go b))
      ((or (neq n 2) (not (flagp w 'nary)) (lessp m n)) (return nil))
      (t (setq !*s!* (cdr (mkbin w !*s!*)))) )
    (return
      (maplist (permutations v) (function (lambda (j) (pair (car j) !*s!*)))) )
b   (cond ((neq m n) (return nil)))
    (setq y (permutations !*s!*))
c   (cond ((null y) (return z)))
    (setq z (nconc (mcharg2 (car y) v (list nil)) z))
    (setq y (cdr y))
    (go c)))

(de mchasarg (u v w) (rederr "NOT YET IMPLEMENTED"))

(de permutations (!*s!*)
  (cond
    ((null !*s!*) (list !*s!*))
    (t (mapcon
        !*s!*
        (function
          (lambda (j)
            (mapcons (permutations (delete (car j) !*s!*)) (car j)))) ))) )

(flagop (list 'antisymmetric 'symmetric))

(flag '(plus times cons) 'symmetric)

(de factor (u) (factor1 u t 'factors!*))

(de factor1 (u v w)
  (prog (x y)
    (setq y (gts w))
a   (cond
      ((null u) (go b))
      ((or
         (kernp (setq x (simpcar u)))
         (and !*super (kernp (setq x (mksfpf x 1)))) )
        (go c))
      (t (errpri2 (car u) 'hold)))
    (go d)
c   (setq x (caaaar x))
    (cond
      (v (setq y (cons x y)))
      ((not (member x y)) (mespri nil (car u) "NOT FOUND" nil nil))
      (t (setq y (delete x y))))
d   (setq u (cdr u))
    (go a)
b   (pts w y)))

(de remfac (u) (factor1 u nil 'factors!*))

(put 'factor 'stat 'rlis)

(put 'remfac 'stat 'rlis)

(de order (u)
  (prog nil
a   (cond
      ((null u) (return nil))
      ((or (not (atom (car u))) (numberp (car u))) (go b)))
    (put (car u) 'order ordn!*)
    (setq ordn!* (plus ordn!* 1))
b   (setq u (cdr u))
    (go a)))

(put 'order 'stat 'rlis)

(de up (u) (factor1 u t 'upl!*))

(de down (u) (factor1 u t 'dnl!*))

(deflist '((up rlis) (down rlis)) 'stat)

(de formop (u)
  (cond
    ((numb u) u)
    (t (addof (multop (caar u) (formop (cdar u))) (formop (cdr u)))) ))

(de addof (u v)
  (cond
    ((null u) v)
    ((null v) u)
    ((numb u) (cons (car v) (addof u (cdr v))))
    ((numb v) (addof v u))
    ((equal (caar u) (caar v))
      (cons (cons (caar u) (addof (cdar u) (cdar v))) (addof (cdr u) (cdr v))))
    ((ordop (caar u) (caar v)) (cons (car u) (addof (cdr u) v)))
    (t (cons (car v) (addof u (cdr v)))) ))

(de multop (u v)
  (cond ((null prin!*) (multf2 u v)) ((eq (car u) 'k!*) v) (t (multop1 u v))))

(de multop1 (u v)
  (cond
    ((null v) nil)
    ((or (numb v) (ordop u (caar v))) (list (cons u v)))
    (t (cons (cons (caar v) (multop1 u (cdar v))) (multop1 u (cdr v)))) ))

(de ordop (u v)
  (cond
    ((null u) (null v))
    ((null v) t)
    ((null prin!*) (orderp u v))
    ((and (member u factors!*) (not (member v factors!*))) t)
    ((and (member v factors!*) (not (member u factors!*))) nil)
    ((atom u)
      (cond
        ((atom v)
          (cond
            ((numberp u) (and (numberp v) (not (lessp u v))))
            ((numberp v) t)
            ((equal ordn!* 0) (orderp u v))
            (t ((lambda (x y)
                 (cond ((and x y) (lessp x y)) (x t) (y nil) (t (orderp u v))))
                (get u 'order)
                (get v 'order)))) )
        ((member u factors!*) t)
        (t (not (member (car v) factors!*)))) )
    ((atom v) (member (car u) factors!*))
    ((equal (car u) (car v)) (ordop (cdr u) (cdr v)))
    (t (ordop (car u) (car v)))) )

(de divof (p q)
  (cond
    ((null p) nil)
    ((equal p q) 1)
    ((equal q 1) p)
    ((atom q)
      (cond
        ((atom p) (mkfr p q))
        ((atom (car p)) (mkfr (car p) (times q (cdr p))))
        (t (cons (cons (caar p) (divof (cdar p) q)) (divof (cdr p) q)))) )
    ((atom (car q))
      (cond
        ((atom p) (mkfr (times p (cdr q)) (car q)))
        ((atom (car p)) (mkfr (times (car p) (cdr q)) (times (cdr p) (car q))))
        (t (cons (cons (caar p) (divof (cdar p) q)) (divof (cdr p) q)))) )
    ((numb p)
      (list
        (cons (cons (caaar q) (minus (cdaar q))) (divof p (cdr (carx q)))) ))
    (t ((lambda (x y)
         (cond
           ((eq (car x) (car y))
             ((lambda (n w z)
                (cond
                  ((equal n 0) (addof w z))
                  (t (cons (cons (cons (car y) n) w) z))))
               (difference (cdr x) (cdr y))
               (divof (cdar p) (cdr (carx q)))
               (divof (cdr p) q)))
           ((ordop (car x) (car y))
             (cons (cons x (divof (cdar p) q)) (divof (cdr p) q)))
           (t (list
               (cons
                 (cons (car y) (minus (cdr y)))
                 (divof p (cdr (carx q)))) ))) )
        (caar p)
        (caar q)))) )

(de ckrn (u)
  (prog (x)
    (cond ((numb u) (return u)))
a   (setq x (gck2 (ckrn (cdar u)) x))
    (cond
      ((null (cdr u)) (return (list (cons (caar u) x))))
      ((or (numb (cdr u)) (not (eq (caaar u) (caaadr u))))
        (return (gck2 (ckrn (cdr u)) x))))
    (setq u (cdr u))
    (go a)))

(de gck2 (u v)
  (cond
    ((null v) u)
    ((equal u v) u)
    ((numb u)
      (cond
        ((numb v)
          (cond ((and (atom u) (atom v) (not !*float)) (gcdn u v)) (t 1)))
        (t (gck2 u (cdarx v)))) )
    ((numb v) (gck2 (cdarx u) v))
    (t ((lambda (x y)
         (cond
           ((eq (car x) (car y))
             (list
               (cons
                 (cond ((greaterp (cdr x) (cdr y)) y) (t x))
                 (gck2 (cdarx u) (cdarx v)))) )
           ((ordop (car x) (car y)) (gck2 (cdarx u) v))
           (t (gck2 u (cdarx v)))) )
        (caar u)
        (caar v)))) )

(de cdarx (u) (cdr (carx u)))

(de prepsq!* (u)
  (prog nil
    (cond ((null (car u)) (return 0)))
    (setq prin!* (or factors!* (neq ordn!* 0) wtl!*))
    (cond (prin!* (setq u (cons (formop (car u)) (formop (cdr u)))) ))
    (setq u
      (cond
        ((or !*rat (and (not !*float) !*div) upl!* dnl!*)
          (replus (prepsq!*1 (car u) nil (cdr u))))
        (t (sqform u (function (lambda (j) (replus (prepsq!*1 j nil 1)))) ))) )
    (setq prin!* nil)
    (return u)))

(de prepsq!*1 (u v w)
  (prog (x y z)
    (cond
      ((null u) (return nil))
      ((and
         (not (numb u))
         (or
           (member (caaar u) factors!*)
           (and (not (atom (caaar u))) (member (caaaar u) factors!*))))
        (return
          (nconc
            (prepsq!*1 (cdar u) (cons (caar u) v) w)
            (prepsq!*1 (cdr u) v w))))
      ((null (kernlp u)) (go a)))
    (setq u (mkkl v u))
    (setq v nil)
a   (setq x (cond ((null !*allfac) 1) (t (ckrn u))))
    (cond ((null dnl!*) (go a1)))
    (setq z (ckrn!* x dnl!*))
    (setq x (divof x z))
    (setq u (divof u z))
    (setq w (divof w z))
a1  (setq y (ckrn w))
    (cond ((null upl!*) (go a2)))
    (setq z (ckrn!* y upl!*))
    (setq y (divof y z))
    (setq u (divof u z))
    (setq w (divof w z))
a2  (cond ((and (null !*div) (null !*float)) (setq y (gcd2 x y))))
    (setq u (normsq (cons (divof u y) (divof w y))))
    (cond ((and !*gcd (null !*div) (null prin!*)) (setq u (cancel u))))
    (setq x (divof x y))
    (cond
      ((and !*allfac (null !*div) (neq x (car u))) (go b))
      ((null v) (go d)))
    (setq v (exchk v nil))
    (go c)
d   (setq u (prepsq u))
    (return (cond ((eqcar u 'plus) (cdr u)) (t (list u))))
b   (cond ((and (equal x 1) (null v)) (go d)))
    (setq u (cons (divof (car u) x) (cdr u)))
    (setq v (prepf (mkkl v x)))
    (cond
      ((equal u (cons 1 1)) (return v))
      ((eqcar v 'times) (setq v (cdr v)))
      (t (setq v (list v))))
c   (return (list (retimes (aconc v (prepsq u)))) )))

(de cancel (u) (multsq (cons (car u) 1) (cons 1 (cdr u))))

(de mkkl (u v) (cond ((null u) v) (t (mkkl (cdr u) (list (cons (car u) v)))) ))

(de ckrn!* (u v)
  (cond
    ((null u) (errach 'ckrn!*))
    ((numb u) 1)
    ((member (caaar u) v) (list (cons (caar u) (ckrn!* (cdr (carx u)) v))))
    (t (ckrn!* (cdr (carx u)) v))))

(de gcdk (u v)
  (prog (beta f1 f2 psi psi1 tau tau1 tau2 var w d1 d2 d3 m n)
    (setq d1 0)
    (setq d2 0)
    (setq d3 0)
    (setq m 0)
    (setq n 0)
    (cond ((equal u v) (return u)))
a0  (cond ((or (numb u) (equal (deg v (setq var (caaar u))) 0)) (return 1)))
    (setq tau1 1)
    (cond
      ((greaterp (setq d2 (difference (cdaar u) (cdaar v))) 0) (go b))
      ((lessp d2 0) (go a)))
    (setq v (caddr (remk u v)))
    (cond ((null v) (return u)) ((atom v) (return 1)))
    (setq v (divf v (gcdl (comfac v))))
    (go a0)
a   (setq d2 (minus d2))
    (setq w u)
    (setq u v)
    (setq v w)
b   (setq w (remk u v))
    (setq d1 (car w))
    (setq m (plus d2 (difference 1 (cadr w))))
    (setq w (caddr w))
    (cond
      ((null w) (return (divf v (gcdl (comfac v)))) )
      ((equal (deg w var) 0) (return 1)))
    (setq f1 (cdar v))
    (setq n (difference (times d2 (difference d1 1)) (times m d1)))
    (setq tau (cond ((greaterp n 0) (exptf f1 n)) (t 1)))
    (cond ((null beta) (go c)))
    (setq psi
      (divf (exptf (negf (multf tau2 f2)) d3) (exptf psi1 (difference d3 1))))
    (setq beta
      (negf
        (divf (multf tau (multf f2 (exptf psi d2))) (exptf tau1 (plus d2 1)))) )
    (go d)
c   (setq beta (multf (expt (minus 1) (plus d2 1)) tau))
    (setq psi (minus 1))
d   (setq u v)
    (setq v (divf w beta))
    (cond ((null v) (errach "GCDK DIVISION FAILED")))
    (setq d3 d2)
    (setq d2 d1)
    (setq f2 f1)
    (setq psi1 psi)
    (setq tau2 tau1)
    (setq tau1 (multf tau (exptf f1 m)))
    (go b)))

(de remk (u v)
  (prog (f1 var x k l n)
    (setq k 0)
    (setq l 0)
    (setq n 0)
    (setq f1 (cdar v))
    (setq var (caaar v))
    (setq n (cdaar v))
    (setq l 0)
a   (setq k (difference (deg u var) n))
    (cond ((lessp k 0) (return (list (minus k) l u))))
    (setq x (negf (multf (cdar u) (cdr v))))
    (cond ((greaterp k 0) (setq x (multf2 (mksp var k) x))))
    (setq u (addf (multf f1 (cdr u)) x))
    (setq l (plus l 1))
    (go a)))

(de coeff (u v w)
  (prog (x y z)
    (cond ((not (atom v)) (setq v (reval v))))
    (setq x factors!*)
    (setq factors!* (list v))
    (setq u (simp!* u))
    (setq prin!* t)
    (setq y (cons (formop (car u)) (formop (cdr u))))
    (setq prin!* nil)
    (cond
      ((not (atom (cdr y)))
        (mespri "COEFF GIVEN EXPRESSION" "WITH DENOMINATOR" nil (prepf (cdr y))
          nil)))
    (setq u (cdr y))
    (setq y (car y))
    (cond ((null y) (go b0)))
a   (cond ((or (numb y) (not (equal (caaar y) v))) (go b)))
    (setq z (cons (cons (cdaar y) (prepsq!* (cancel (cons (cdar y) u)))) z))
    (setq y (cdr y))
    (go a)
b   (cond ((null y) (go b1)))
b0  (setq z (cons (cons 0 (prepsq!* (cancel (cons y u)))) z))
b1  (cond
      ((or
         (and (not (atom w)) (atom (car w)) (setq y (get!* (car w) '!*!*array)))
         (and (atom w) (setq y (get!* w '!*!*array)) (null (cdr y))))
        (go g)))
    (setq y (explode w))
    (setq w nil)
c   (setq w
      (cons (list 'equal (compress (append y (explode (caar z)))) (cdar z)) w))
    (cond ((null (cdr z)) (go d)))
    (setq z (cdr z))
    (go c)
d   (setk '!*hipow (caar z))
    (let0 w nil)
    (cond (!*msg (lprim (aconc (maplist w (function cadar)) "ARE NON ZERO"))))
e   (setq factors!* x)
    (return (reval '!*hipow))
g   (setq z (reverse z))
    (cond ((atom w) (setq w (list w 'times))))
    (setk '!*hipow (caar z))
    (setq y (pair (cdr w) y))
g0  (cond ((member 'times (flatten (caar y))) (go g1)))
    (setq y (cdr y))
    (go g0)
g1  (setq y (difference (cdar y) (reval (subst 0 'times (caar y)))) )
    (cond ((greaterp (caar z) y) (rederr "ARRAY TOO SMALL")))
    (setq w (revop (subst y 'times w)))
h   (cond
      ((or (null z) (not (equal y (caar z)))) (setel w 0))
      (t (prog2 (setel w (cdar z)) (setq z (cdr z)))) )
    (cond ((equal y 0) (go e)))
    (setq y (difference y 1))
    (go h)))

(flag '(coeff) 'opfn)

(de mkcoeff (u v)
  (prog nil
    (coeff !*ans u v)))

(put 'mkcoeff 'stat 'norlis)

(de weight (u)
  (prog (y z)
    (rmsubs)
a   (cond ((null u) (return nil)) ((not (eqexpr (car u))) (go er)))
    (setq y (simp0 (cadar u)))
    (setq z (reval (caddar u)))
    (cond
      ((or (not (kernp y)) (not (and (numberp z) (fixp z) (not (minusp z)))) )
        (go er)))
    (setq y (caaaar y))
    (setq wtl!* (cons (cons y z) wtl!*))
b   (setq u (cdr u))
    (go a)
er  (errpri2 (car u) 'hold)
    (go b)))

(de wtlevel (n)
  (prog (x)
    (setq n (reval n))
    (cond ((not (and (numberp n) (fixp n) (not (minusp n)))) (errpri2 n)))
    (setq n (plus n 1))
    (setq x (assoc 'asymp (cddr (fkern 'k!*))))
    (cond ((equal n (cdr x)) (return nil)) ((leq n (cdr x)) (rmsubs2)))
    (rmsubs1)
    (rplacd x n)))

(deflist '((weight rlis) (wtlevel norlis)) 'stat)

(let1 '(expt k!* 2) 0)

(de nssimp (u v)
  (prog (w x y z)
    (setq u (dsimp u v))
a   (cond ((null u) (return z)))
    (setq w (car u))
c   (cond
      ((null w) (go d))
      ((or
         (numberp (car w))
         (not (or (eqcar (car w) '!*div) (!*apply v (list (car w)))) ))
        (setq x (aconc x (car w))))
      (t (setq y (aconc y (car w)))) )
    (setq w (cdr w))
    (go c)
d   (cond ((null y) (go er)))
e   (setq z (addns (cons (cond ((null x) (cons 1 1)) (t (simptimes x))) y) z))
    (setq u (cdr u))
    (setq x (setq y nil))
    (go a)
er  (setq y (get v 'name))
    (cond
      ((and (atom (car x)) (not (numberp (car x))))
        (cond
          ((not (flagp (car x) (get y 'fn))) (redmsg (car x) y))
          (t (rederr (list y x "NOT SET")))) )
      (t (rederr (list "MISSING" y x))))
    (put (car x) y y)
    (setq y (list (car x)))
    (setq x (cdr x))
    (go e)))

(de dsimp (u !*s!*)
  (cond
    ((numberp u) (list (list u)))
    ((atom u)
      ((lambda (w)
         ((lambda (x)
            (cond
              ((and x (not (eq x w)) subfg!*) (dsimp x !*s!*))
              ((flagp u 'share) (dsimp (!*eval u) !*s!*))
              (t (prog2 (flag (list u) 'used!*) (list (list u)))) ))
           (get u w)))
        (get !*s!* 'name)))
    ((eq (car u) 'plus)
      (mapcon (cdr u) (function (lambda (j) (dsimp (car j) !*s!*)))) )
    ((eq (car u) 'difference)
      (nconc (dsimp (cadr u) !*s!*) (dsimp (cons 'minus (cddr u)) !*s!*)))
    ((eq (car u) 'minus) (dsimptimes (list (minus 1) (carx (cdr u))) !*s!*))
    ((eq (car u) 'times) (dsimptimes (cdr u) !*s!*))
    ((eq (car u) 'quotient)
      (dsimptimes (list (cadr u) (list 'recip (carx (cddr u)))) !*s!*))
    ((not (!*apply !*s!* (list u))) (list (list u)))
    ((eq (car u) 'recip) (list (list (list '!*div (carx (cdr u)))) ))
    ((eq (car u) 'expt)
      ((lambda (z)
         (cond
           ((or (not (numberp z)) (not (fixp z))) (errpri2 u t))
           ((minusp z)
             (list
               (list (list '!*div (cons 'times (nlist (cadr u) (minus z)))) )))
           (t (dsimptimes (nlist (cadr u) z) !*s!*))))
        (reval (caddr u))))
    ((eq (car u) 'mat) (list (list u)))
    ((get (car u) '!*!*array) (dsimp (getel (revop u t)) !*s!*))
    (t ((lambda (x)
         (cond
           (x (dsimp x !*s!*))
           (t ((lambda (y) (cond (y (dsimp y !*s!*)) (t (list (list u)))) )
               (opmtch (revop u nil)))) ))
        (opmtch u)))) )

(de dsimptimes (u v)
  (cond
    ((null u) (errach 'dsimptimes))
    ((null (cdr u)) (dsimp (car u) v))
    (t ((lambda (!*s!*)
         (mapcon
           (dsimptimes (cdr u) v)
           (function (lambda (j) (mappend !*s!* (car j)))) ))
        (dsimp (car u) v)))) )

(de addns (u v)
  (cond
    ((null v) (list u))
    ((equal (cdr u) (cdar v))
      ((lambda (x)
         (cond ((null (car x)) (cdr v)) (t (cons (cons x (cdr u)) (cdr v)))) )
        (addsq (car u) (caar v))))
    ((ordp (cdr u) (cdar v)) (cons u v))
    (t (cons (car v) (addns u (cdr v)))) ))

(de nslet (u v w b flg)
  (prog nil
    (cond (flg (go a)) ((not (atom u)) (rederr (list "TYPE CONFLICT FOR" u))))
    (redmsg u w)
    (put u w w)
a   (cond ((null b) (go c)) ((atom u) (flagp u 'used!*)))
    (rmsubs2)
c   (cond
      ((not (atom u))
        (cond
          ((get (car u) '!*!*array) (setel (revop u t) (cond (b v) (t nil))))
          (t (put
              (car u)
              'opmtch
              (xadd
                (cons
                  (cdr u)
                  (list (cons nil (cond (mcond!* mcond!*) (t t))) v nil))
                (get (car u) 'opmtch)
                u
                b)))) )
      ((null b) (remprop u w))
      (t (put u w v)))) )

(de nsp (u v)
  (cond
    ((numberp u) nil)
    ((atom u) (or (get u v) (and (flagp u 'share) (nsp (!*eval u) v))))
    ((member (car u) '(times quotient)) (nsor (cdr u) v))
    ((member (car u) '(plus difference minus expt recip)) (nsp (cadr u) v))
    (t (flagp (car u) (get v 'fn)))) )

(de nsor (u v) (and u (or (nsp (car u) v) (nsor (cdr u) v))))

(setq typl!* (union '(matp) typl!*))

(de matrix (u)
  (prog (v w n)
    (setq n 0)
    (setq matp!* t)
a   (cond
      ((null u) (return nil))
      ((and (atom (car u)) (not (defp (car u) 'matrix)))
        (put (car u) 'matrix 'matrix))
      ((or
         (not (atom (caar u)))
         (numberp (caar u))
         (neq (length (setq v (revlis (cdar u)))) 2)
         (not (numlis v)))
        (go er))
      ((not (defp (caar u) 'matrix)) (go c)))
b   (setq u (cdr u))
    (go a)
c   (setq n (car v))
d   (cond ((equal n 0) (go e)))
    (setq w (cons (nzero (cadr v)) w))
    (setq n (difference n 1))
    (go d)
e   (put (caar u) 'matrix (cons 'mat w))
    (setq w nil)
    (go b)
er  (errpri2 (car u) 'hold)
    (go b)))

(put 'matrix 'stat 'opstat)

(de nzero (n) (cond ((equal n 0) nil) (t (cons 0 (nzero (difference n 1)))) ))

(de matp (u) (nsp u 'matrix))

(put 'mat 'matfn 'matfn)
% The Code assumes that after the call to put above the call
%   (flagp 'mat 'matfn)        
%  returns non-nil which is not the case in PSL. PSL which keeps flags
%  separate from properties.  
(flag '(mat) 'matfn)

(put 'tp 'matfn 'tp)

(put 'matp 'letfn 'nslet)

(put 'matp 'name 'matrix)

(put 'matrix 'fn 'matfn)

(put 'matp 'evfn 'matsm)

(put 'matp 'prifn 'matpri!*)

(de mapc2 (u !*pi!*)
  (mapcar
    u
    (function (lambda (j) (mapcar j
      (function (lambda (k) (apply1 !*pi!* k)))) ))) )

(de matsm (u)
  (prog nil
    (setq u (matsm1 u))
    (return
      (cond
        ((and (null (cdr u)) (null (cdar u))) (mk!*sq2 (caar u)))
        (t (cons 'mat (mapc2 u (function mk!*sq2)))) ))) )

(de mk!*sq2 (u) (mk!*sq (subs2 u)))

(de matsm1 (u)
  (prog (x y)
    (setq u (nssimp u 'matp))
a   (cond ((null u) (return x)))
    (setq y (multsm (caar u) (mtimes (cdar u))))
    (setq x (cond ((null x) y) (t (addm x y))))
    (setq u (cdr u))
    (go a)))

(de mtimes (u)
  (prog (x y z n)
    (setq n 0)
a   (cond
      ((null u) (return z))
      ((eqcar (car u) '!*div) (go d))
      ((atom (car u)) (go er))
      ((eq (caar u) 'mat) (setq x (mapc2 (cdar u) (function simp))))
      ((and (setq x (get (caar u) 'matfn)) (neq x 'matfn))
        (setq x (!*apply x (list (matsm1 (carx (cdar u)))) )))
      (t (go er)))
    (setq z
      (cond
        ((null z) x)
        ((and (null (cdr z)) (null (cdar z))) (multsm (caar z) x))
        (t (multm x z))))
c   (setq u (cdr u))
    (go a)
d   (setq y (matsm1 (cadar u)))
    (cond
      ((or
         (neq (setq n (length (car y))) (length y))
         (and z (neq n (length z))))
        (rederr "MATRIX MISMATCH"))
      ((and (null (cdr y)) (null (cdar y))) (go e)))
    (setq x subfg!*)
    (setq subfg!* nil)
    (setq z
      (rhside
        (backsub
          (bareiss (augment y (cond ((null z) (generateident n)) (t z))))
          n)
        n))
    (setq subfg!* x)
    (go c)
e   (cond ((null (caaar y)) (rederr "ZERO DENOMINATOR")))
    (setq y (revpr (caar y)))
    (setq z (cond ((null z) (list (list y))) (t (multsm y z))))
    (go c)
er  (rederr (list 'matrix (car u) "NOT SET"))))

(de addm (u v)
  (mapcar
    (addm1 u v (function cons))
    (function (lambda (j) (addm1 (car j) (cdr j) (function addsq)))) ))

(de addm1 (u v !*pi!*)
  (cond
    ((and (null u) (null v)) nil)
    ((or (null u) (null v)) (rederr "MATRIX MISMATCH"))
    (t (cons (apply2 !*pi!* (car u) (car v))
             (addm1 (cdr u) (cdr v) !*pi!*)))) )

(de tp (u)
  (prog (v w x y z)
    (setq v (setq w (list nil)))
a   (cond ((null (car u)) (return (cdr v))))
    (setq x u)
    (setq y (setq z (list nil)))
b   (cond ((null x) (go c)))
    (setq z (cdr (rplacd z (list (caar x)))) )
    (setq x (cdr (rplaca x (cdar x))))
    (go b)
c   (setq w (cdr (rplacd w (list (cdr y)))) )
    (go a)))

(de scalprod (u v)
  (cond
    ((and (null u) (null v)) (cons nil 1))
    ((or (null u) (null v)) (rederr "MATRIX MISMATCH"))
    (t (addsq (multsq (car u) (car v)) (scalprod (cdr u) (cdr v)))) ))

(de multm (u v)
  ((lambda (!*s!*)
     (mapcar
       u
       (function
         (lambda (!*s1!*)
           (mapcar !*s!* (function (lambda (k) (scalprod !*s1!* k)))) ))) )
    (tp v)))

(de multsm (!*s!* u)
  (cond
    ((equal !*s!* (cons 1 1)) u)
    (t (mapc2 u (function (lambda (j) (multsq !*s!* j)))) )))

(de letmtr (u v y)
  (prog (z)
    (cond
      ((not (eqcar y 'mat)) (rederr (list 'matrix (car u) "NOT SET")))
      ((or (not (numlis (setq z (revlis (cdr u)))) ) (neq (length z) 2))
        (return (errpri2 u 'hold))))
    (rplaca (pnth (nth (cdr y) (car z)) (cadr z)) v)))

(de matpri!* (u v w) (matpri (cdr u) (cond (v (!*eval (car v))) (t nil))))

(de matpri (u x)
  (prog (v m n)
    (setq m 1)
    (cond ((null x) (setq x 'mat)))
a   (cond ((null u) (return nil)))
    (setq n 1)
    (setq v (car u))
b   (cond ((null v) (go c)) ((and (equal (car v) 0) !*nero) (go b1)))
    (maprin (list x m n))
    (oprin 'setq)
    (setq orig!* posn!*)
    (maprin (car v))
    (cond ((and (null !*nat) (null !*fort)) (princ !*!*dollar)))
    (setq orig!* 0)
    (terpri!* t)
b1  (setq v (cdr v))
    (setq n (plus n 1))
    (go b)
c   (setq u (cdr u))
    (setq m (plus m 1))
    (go a)))

(de augment (u v)
  (cond
    ((null u) nil)
    (t (cons (append (car u) (car v)) (augment (cdr u) (cdr v)))) ))

(de generateident (n)
  (prog (i j u v)
    (setq i 0)
    (setq j 0)
    (setq i 1)
a   (cond ((greaterp i n) (return v)))
    (setq u nil)
    (setq j 1)
b   (cond
      ((greaterp j n) (go c))
      (t (setq u (cons (cons (cond ((equal i j) 1) (t nil)) 1) u))))
    (setq j (plus j 1))
    (go b)
c   (setq i (plus i 1))
    (setq v (cons u v))
    (go a)))

(de rhside (u m)
  (cond
    ((null u) nil)
    (t (cons (pnth (car u) (plus m 1)) (rhside (cdr u) m)))) )

(de bareiss (u)
  (prog (aa c0 ci1 ci2 ik1 ij kk1 kj k1j k1k1 ui u1 x k k1)
    (setq k 0)
    (setq k1 0)
    (setq aa (cons 1 1))
    (setq k 2)
    (setq k1 1)
    (setq u1 u)
    (go pivot)
agn (setq u1 (cdr u1))
    (cond ((or (null (cdr u1)) (null (cddr u1))) (return u)))
    (setq aa (nth (car u1) k))
    (setq k (plus k 2))
    (setq k1 (difference k 1))
    (setq u1 (cdr u1))
pivot
    (setq k1j (setq k1k1 (pnth (car u1) k1)))
    (cond ((neq (car k1k1) (cons nil 1)) (go l2)))
    (setq ui (cdr u1))
l   (cond
      ((null ui) (return nil))
      ((equal (car (setq ij (pnth (car ui) k1))) (cons nil 1)) (go l1)))
l0  (cond ((null ij) (go l2)))
    (setq x (car ij))
    (rplaca ij (negsq (car k1j)))
    (rplaca k1j x)
    (setq ij (cdr ij))
    (setq k1j (cdr k1j))
    (go l0)
l1  (setq ui (cdr ui))
    (go l)
l2  (setq ui (cdr u1))
l21 (cond ((null ui) (return nil)))
    (setq ij (pnth (car ui) k1))
    (setq c0
      (addsq1
        (multsq1 (car k1k1) (cadr ij))
        (negsq (multsq1 (cadr k1k1) (car ij)))) )
    (cond ((neq c0 (cons nil 1)) (go l3)))
    (setq ui (cdr ui))
    (go l21)
l3  (setq c0 (divsq c0 aa))
    (setq kk1 (setq kj (pnth (cadr u1) k1)))
    (cond
      ((and (cdr u1) (null (cddr u1))) (go ev0))
      ((eq ui (cdr u1)) (go comp)))
l31 (cond ((null ij) (go comp)))
    (setq x (car ij))
    (rplaca ij (negsq (car kj)))
    (rplaca kj x)
    (setq ij (cdr ij))
    (setq kj (cdr kj))
    (go l31)
comp(cond ((null (cdr u1)) (go ev)))
    (setq ui (cddr u1))
comp1
    (cond ((null ui) (go ev)))
    (setq ik1 (pnth (car ui) k1))
    (setq ci1
      (divsq
        (addsq1
          (multsq1 (cadr k1k1) (car ik1))
          (negsq (multsq1 (car k1k1) (cadr ik1))))
        aa))
    (setq ci2
      (divsq
        (addsq1
          (multsq1 (car kk1) (cadr ik1))
          (negsq (multsq1 (cadr kk1) (car ik1))))
        aa))
    (cond ((null (cddr k1k1)) (go comp3)))
    (setq ij (cddr ik1))
    (setq kj (cddr kk1))
    (setq k1j (cddr k1k1))
comp2
    (cond ((null ij) (go comp3)))
    (rplaca
      ij
      (divsq
        (addsq1
          (multsq1 (car ij) c0)
          (addsq1 (multsq1 (car kj) ci1) (multsq1 (car k1j) ci2)))
        aa))
    (setq ij (cdr ij))
    (setq kj (cdr kj))
    (setq k1j (cdr k1j))
    (go comp2)
comp3
    (setq ci1 (setq ci2 nil))
    (setq ui (cdr ui))
    (go comp1)
ev0 (cond ((equal c0 (cons nil 1)) (return nil)))
ev  (setq kj (cdr kk1))
    (setq x (cddr k1k1))
    (rplaca kj c0)
ev1 (setq kj (cdr kj))
    (cond ((null kj) (go agn)))
    (rplaca
      kj
      (divsq
        (addsq1
          (multsq1 (car k1k1) (car kj))
          (negsq (multsq1 (car kk1) (car x))))
        aa))
    (setq x (cdr x))
    (go ev1)))

(de backsub (u m)
  (prog (idet ij ijj ri summ uj ur i jj)
    (setq i 0)
    (setq jj 0)
    (cond ((null u) (rederr "SINGULAR MATRIX")))
    (setq ur (reverse u))
    (setq i m)
    (setq ri (car ur))
    (setq ij (pnth ri m))
    (setq idet (revpr (car ij)))
    (cond ((null (cdr idet)) (rederr "SINGULAR MATRIX")))
rowm(setq ij (cdr ij))
    (cond ((null ij) (go rows)))
    (rplaca ij (multsq1 (car ij) idet))
    (go rowm)
rows(setq i (difference i 1))
    (setq ur (cdr ur))
    (cond ((null ur) (return u)))
    (setq ri (car ur))
    (setq jj (plus m 1))
    (setq ijj (pnth ri jj))
r2  (cond ((null ijj) (go rows)))
    (setq ij (pnth ri i))
    (setq idet (car ij))
    (setq uj (pnth u i))
    (setq summ (cons nil 1))
r3  (setq uj (cdr uj))
    (cond ((null uj) (go r4)))
    (setq ij (cdr ij))
    (setq summ (addsq1 summ (multsq1 (car ij) (nth (car uj) jj))))
    (go r3)
r4  (rplaca ijj (divsq (addsq1 (car ijj) (negsq summ)) idet))
    (setq jj (plus jj 1))
    (setq ijj (cdr ijj))
    (go r2)))

(de divf!* (u v)
  (cond
    ((null u) nil)
    (t ((lambda (x) (cond ((null x) (errach "DIVISION FAILED")) (t x)))
        (divf u v)))) )

(de divsq (u v)
  (cond
    (!*gcd (multsq u (revpr v)))
    (t (cons (divf!* (car u) (car v)) (divf!* (cdr u) (cdr v)))) ))

(de multsq1 (u v)
  (cond
    (!*gcd (multsq u v))
    (t (cons (multf (car u) (car v)) (multf (cdr u) (cdr v)))) ))

(de addsq1 (u v)
  (cond
    (!*gcd (addsq u v))
    ((equal (cdr u) (cdr v)) (cons (addf (car u) (car v)) (cdr u)))
    (t (prog (x)
        (setq x (gcdf (cdr u) (cdr v)))
        (setq x (cons (divf (cdr u) x) (divf (cdr v) x)))
        (return
          (cons
            (addf (multf (cdr x) (car u)) (multf (car x) (car v)))
            (multf (cdr x) (cdr u)))) ))) )

(de simpdet (u) (detq (matsm1 (carx u))))

(de detq (u)
  (prog (x n)
    (setq n 0)
    (setq n (length u))
    (cond ((neq n (length (car u))) (rederr "NON SQUARE MATRIX")))
    (setq x subfg!*)
    (setq subfg!* nil)
    (setq u (bareiss u))
    (setq subfg!* x)
    (return (cond ((null u) (cons nil 1)) (t (nth (nth u n) n)))) ))

(put 'det 'simpfn 'simpdet)

(de simptrace (u)
  (prog (n z)
    (setq n 0)
    (setq u (matsm1 (carx u)))
    (cond ((neq (length u) (length (car u))) (rederr "NON SQUARE MATRIX")))
    (setq z (cons nil 1))
    (setq n 1)
a   (cond ((null u) (return z)))
    (setq z (addsq (nth (car u) n) z))
    (setq u (cdr u))
    (setq n (plus n 1))
    (go a)))

(put 'trace 'simpfn 'simptrace)

(setq typl!* (union '(vectorp) typl!*))

(setq gamiden!* nil)

(setq indices!* nil)

(deflist '((cons simpdot)) 'simpfn)

(de vector (u) (vector1 u))

(de vector1 (u)
  (!~map u (function (lambda (j) (put (car j) 'vector 'vector)))) )

(de vectorp (u) (nsp u 'vector))

(put 'vector 'stat 'opstat)

(put 'vector 'fn 'vecfn)

(put 'vectorp 'letfn 'nslet)

(put 'vectorp 'name 'vector)

(put 'vectorp 'evfn 'veval)

(de index (u)
  (prog nil
    (vector1 u)
    (rmsubs)
    (setq indices!* (union indices!* u))))

(de remind (u)
  (prog nil
    (setq indices!* (setdiff indices!* u))))

(de mass (u)
  (prog nil
a   (cond ((null u) (return nil)))
    (put (cadar u) 'mass (caddar u))
    (put (cadar u) 'vector 'vector)
    (setq u (cdr u))
    (go a)))

(de mshell (u)
  (prog (x z)
a   (cond ((null u) (return (let0 z nil))))
    (setq x (getmas (car u)))
    (setq z
      (cons (list 'equal (list 'cons (car u) (car u)) (list 'expt x 2)) z))
    (setq u (cdr u))
    (go a)))

(deflist '((mshell rlis) (mass rlis) (index rlis) (remind rlis)) 'stat)

(de veval (u)
  (prog (z)
    (setq u (nssimp u 'vectorp))
a   (cond
      ((null u) (return (replus z)))
      ((null (cdar u)) (rederr "MISSING VECTOR"))
      ((cddar u) (rederr (list "REDUNDANT VECTOR" (cdar u)))) )
    (setq z (aconc z (retimes (cons (prepsq (caar u)) (cdar u)))) )
    (setq u (cdr u))
    (go a)))

(de isimpq (u) (multsq (cons (isimp (car u)) 1) (cons 1 (cdr u))))

(de isimp (u) (isimp1 u indices!* nil nil nil))

(de isimp1 (u i v w x)
  (cond
    ((null u) nil)
    ((numb u)
      (cond
        (x (multf u (spur0 (car x) i v w (cdr x))))
        (v (rederr (append "UNMATCHED INDEX ERROR" i)))
        (w (multf (emult w) (isimp1 u i v nil x)))
        (t u)))
    (t (addf (isimp2 (car u) i v w x) (isimp1 (cdr u) i v w x)))) )

(de isimp2 (u i v w x)
  (prog (z)
    (cond
      ((atom (setq z (caar u))) (go a))
      ((and (eq (car z) 'cons) (xn (cdr z) i)) (return (dotsum u i v w x)))
      ((eq (car z) 'g) (go b))
      ((eq (car z) 'eps) (return (esum u i v w x))))
a   (return (multf2 (car u) (isimp1 (cdr u) i v w x)))
b   (setq z (gadd (appn (cddr z) (cdar u)) x (cadr z)))
    (return (isimp1 (multn (nb (car z)) (cdr u)) i v w (cdr z)))) )

(de nb (u) (cond (u 1) (t (minus 1))))

(de dotsum (u i v w x)
  (prog (i1 n u1 u2 v1 y z)
    (setq n (cdar u))
    (cond ((not (member (car (setq u1 (cdaar u))) i)) (setq u1 (reverse u1))))
    (setq u2 (cadr u1))
    (setq u1 (car u1))
    (setq v1 (cdr u))
    (cond ((equal n 2) (go h)) ((neq n 1) (rederr u)))
a   (cond
      ((not (member u1 i))
        (return (multf (mkdot u1 u2) (isimp1 v1 i1 v w x)))) )
a1  (setq i1 (delete u1 i))
    (cond
      ((eq u1 u2) (return (multn 4 (isimp1 v1 i1 v w x))))
      ((not (setq z (assoc u1 v))) (go c))
      ((member u2 i) (go d)))
    (setq u1 (cdr z))
    (go e)
c   (cond
      ((setq z (memlis u1 x))
        (return (isimp1 v1 i1 v w (cons (subst u2 u1 z) (delete z x)))) )
      ((setq z (memlis u1 w))
        (return
          (esum (cons (cons (cons 'eps (subst u2 u1 z)) 1) v1) i1 v (delete z w)
            x)))
      ((and (member u2 i) (null y)) (go g)))
    (return (isimp1 v1 i (cons (cons u1 u2) v) w x))
d   (setq u1 u2)
    (setq u2 (cdr z))
e   (setq i i1)
    (setq v (delete z v))
    (go a)
g   (setq y t)
    (setq z u1)
    (setq u1 u2)
    (setq u2 z)
    (go a1)
h   (cond ((eq u1 u2) (rederr u)))
    (setq i (setq i1 (delete u1 i)))
    (setq u1 u2)
    (go a)))

(de vmult (u)
  (prog (z)
    (setq z (list (list '(1 . 1))))
a   (cond ((null u) (return z)))
    (setq z (vmult1 (nssimp (car u) 'vectorp) z))
    (cond ((null z) (return nil)))
    (setq u (cdr u))
    (go a)))

(de vmult1 (!*s!* v)
  (prog (z)
    (cond ((null v) (return nil)))
a   (cond
      ((null !*s!*) (return z))
      ((cddar !*s!*) (rederr (cons "REDUNDANT VECTOR" (cdar !*s!*)))) )
    (setq z
      (nconc
        z
        (mapcar
          v
          (function
            (lambda (j)
              (cons
                (multsq (car j) (caar !*s!*))
                (append (cdr j) (cdar !*s!*)))) ))) )
    (setq !*s!* (cdr !*s!*))
    (go a)))

(de simpdot (u) (mkvarg u (function dotord)))

(de dotord (u)
  (prog2
    (cond
      ((and (xn u indices!*) (not (member 'isimpq mul!*)))
        (setq mul!* (aconc mul!* 'isimpq)))
      (t nil))
    (cond
      ((member 'a u) (rederr "A REPRESENTS ONLY GAMMA5 IN VECTOR EXPRESSIONS"))
      (t (mksq (cons 'cons (ord2 (car u) (carx (cdr u)))) 1)))) )

(de mkvarg (u !*pi!*)
  (prog (z)
    (setq u (vmult u))
    (setq z (cons nil 1))
a   (cond ((null u) (return z)))
    (setq z (addsq (multsq (apply1 !*pi!* (cdar u)) (caar u)) z))
    (setq u (cdr u))
    (go a)))

(de mkdot (u v) (mksf (cons 'cons (ord2 u v)) 1))

(de getmas (u)
  ((lambda (x) (cond (x x) (t (rederr (list u "HAS NO MASS")))) )
    (get!* u 'mass)))

(put 'g 'simpfn 'simpgamma)

(flagop (list 'noncom 'nospur))

(flag '(g) 'noncom)

(de ncmordp (u v)
  (cond
    ((and (not (atom u)) (atom (car u)) (flagp (car u) 'noncom))
      (cond
        ((and (not (atom v)) (flagp!*!* (car v) 'noncom)) (orderp u v))
        (t t)))
    ((and (not (atom v)) (atom (car v)) (flagp (car v) 'noncom)) nil)
    (t (orderp u v))))

(de spur (u)
  (prog2
    (rmsubs)
    (!~map
      u
      (function
        (lambda (j)
          (prog2
            (remflag (list (car j)) 'nospur)
            (remflag (list (car j)) 'reduce)))) )))

(put 'spur 'stat 'rlis)

(de simpgamma (!*s!*)
  (cond
    ((or (null !*s!*) (null (cdr !*s!*)))
      (rederr "MISSING ARGUMENTS FOR G OPERATOR"))
    (t (prog nil
        (setq gamiden!* (union (list (car !*s!*)) gamiden!*))
        (cond ((not (member 'isimpq mul!*)) (setq mul!* (aconc mul!* 'isimpq))))
        (setq ncmp!* t)
        (return
          (mkvarg
            (cdr !*s!*)
            (function (lambda (j) (cons (mkgf j (car !*s!*)) 1)))) ))) ))

(de gadd (u v l)
  (prog (w x n)
    (setq n 0)
    (setq n 0)
    (cond ((not (setq x (assoc l v))) (go a)))
    (setq v (delete x v))
    (setq w (cddr x))
    (setq x (cadr x))
a   (cond
      ((null u)
        (return (cons (equal (remainder n 2) 0) (cons (cons l (cons x w)) v))))
      ((eq (car u) 'a) (go c))
      (t (setq w (cons (car u) w))))
b   (setq u (cdr u))
    (go a)
c   (setq x (not x))
    (setq n (plus (length w) n))
    (go b)))

(de mkg (u l) (list (cons (cons (cons 'g (cons l u)) 1) 1)))

(de mka (l) (mkg (list 'a) l))

(de mkgf (u l) (mksf (cons 'g (cons l u)) 1))

(de mkg1 (u l) (cond ((not (flagp l 'nospur)) (mkg u l)) (t (mkgf u l))))

(de spur0 (u i v1 v2 v3)
  (prog (l w i1 kahp z n)
    (setq n 0)
    (setq l (car u))
    (setq n 1)
    (setq z (cadr u))
    (setq u (reverse (cddr u)))
    (cond (z (setq u (cons 'a u))))
    (cond
      ((get l 'nospur) (go a))
      ((null u) (go end1))
      ((or
         (and (eq (car u) 'a) (or (lessp (length u) 5) (!*evenp u)))
         (and (not (eq (car u) 'a)) (not (!*evenp u))))
        (return nil))
      ((null i) (go end0)))
a   (cond ((null u) (go end1)) ((member (car u) i) (go b)))
a1  (setq w (cons (car u) w))
    (setq u (cdr u))
    (go a)
b   (cond
      ((member (car u) (cdr u)) (go kah1))
      ((member (car u) i1) (go a1))
      ((setq z (bassoc (car u) v1)) (go e))
      ((setq z (memlis (car u) v2))
        (return
          (cond
            ((and (flagp l 'nospur) (null v1) (null v3) (null (cdr v2)))
              (multf (mkgf (append (reverse w) u) l) (multn n (mkeps1 z))))
            (t (multn
                n
                (isimp1
                  (spur0
                    (cons l (cons nil (append (reverse u) w)))
                    nil
                    v1
                    (delete z v2)
                    v3)
                  i
                  nil
                  (list z)
                  nil)))) ))
      ((setq z (memlis (car u) v3)) (go c))
      (t (rederr (list "UNMATCHED INDEX" (car u)))) )
c   (setq v3 (delete z v3))
    (setq kahp nil)
    (cond
      ((and (flagp l 'nospur) (flagp (car z) 'nospur))
        (rederr "NOT YET IMPLEMENTED"))
      ((flagp (car z) 'nospur) (setq kahp (car z))))
    (setq z (cdr z))
    (setq i1 (car z))
    (setq z (reverse (cdr z)))
    (cond (i1 (setq z (cons 'a z))))
    (setq i1 nil)
c1  (cond ((eq (car u) (car z)) (go d)))
    (setq i1 (cons (car z) i1))
    (setq z (cdr z))
    (go c1)
d   (setq z (cdr z))
    (setq i (delete (car u) i))
    (setq u (cdr u))
    (cond ((not (flagp l 'nospur)) (go d0)))
    (setq w (cons w (cons u (cons i1 z))))
    (setq i1 (car w))
    (setq z (cadr w))
    (setq u (caddr w))
    (setq w (cdddr w))
d0  (setq w (reverse w))
    (cond
      ((and (or (null u) (not (eqcar w 'a))) (setq u (append u w))) (go d1))
      ((not (!*evenp u)) (setq n (minus n))))
    (setq u (cons 'a (append u (cdr w))))
d1  (cond (kahp (setq l kahp)))
    (setq z
      (multf (mkg (reverse i1) l) (multf (brace u l i) (multn n (mkg1 z l)))) )
    (setq z (isimp1 z i v1 v2 v3))
    (cond
      ((or (null z) (setq z (divf z 2))) (return z))
      (t (errach (list 'spur0 n i v1 v2 v3))))
e   (setq v1 (delete z v1))
    (setq i (delete (car w) i))
    (setq u (cons (other (car u) z) (cdr u)))
    (go a)
kah1(cond ((eq (car u) (cadr u)) (go k2)))
    (setq kahp t)
    (setq i1 (cons (car u) i1))
    (go a1)
k2  (setq i (delete (car u) i))
    (setq u (cddr u))
    (setq n (times 4 n))
    (go a)
end0(setq w (reverse u))
end1(cond
      (kahp (go end2))
      ((null (setq z (spurr w l nil 1))) (return nil))
      (t (return
          (cond
            ((and (get 'eps 'klist) (not (flagp l 'nospur)))
              (isimp1 (multn n z) i v1 v2 v3))
            (t (multf z (isimp1 n i v1 v2 v3)))) )))
end2(setq z (multf (kahane (reverse w) i1 l) n))
    (return (isimp1 z (setdiff i i1) v1 v2 v3))))

(de appn (u n) (cond ((equal n 1) u) (t (append u (appn u (difference n 1)))) ))

(de other (u v) (cond ((eq u (car v)) (cdr v)) (t (car v))))

(de kahane (u i l)
  (prog (k m p r v w x y z)
    (setq k 0)
mark(cond ((eqcar u 'a) (go a1)))
a   (setq p (not p))
    (cond ((null u) (go d)) ((member (car u) i) (go c)))
a1  (setq w (aconc w (car u)))
b   (setq u (cdr u))
    (go a)
c   (setq y (cons (car u) p))
    (setq z (cons (cons x (cons y w)) z))
    (setq x y)
    (setq w nil)
    (setq k (plus k 1))
    (go b)
d   (setq z (cons (cons nil (cons x w)) z))
pass2
    (setq m 1)
l1  (cond ((null z) (go l9)))
    (setq u (caar z))
    (setq x (cadar z))
    (setq w (cddar z))
    (setq z (cdr z))
    (setq m (plus m 1))
    (cond
      ((null u) (go l2))
      ((and (eq (car u) (car x)) (exc x (cdr u))) (go l7)))
    (setq w (reverse w))
    (setq r t)
l2  (setq p (not (exc x r)))
    (setq x (car x))
    (setq y nil)
l3  (cond
      ((null z) (errach "UNMATCHED INDEX IN KAHANE"))
      ((and (eq x (car (setq i (cadar z)))) (not (exc i p))) (go l5))
      ((and (eq x (car (setq i (caar z)))) (exc i p)) (go l4)))
    (setq y (cons (car z) y))
    (setq z (cdr z))
    (go l3)
l4  (setq x (cadar z))
    (setq w (appr (cddar z) w))
    (setq r t)
    (go l6)
l5  (setq x (caar z))
    (setq w (append (cddar z) w))
    (setq r nil)
l6  (setq z (appr y (cdr z)))
    (cond ((null x) (go l8)) ((not (eqcar u (car x))) (go l2)))
l7  (cond ((and w (cdr u)) (setq w (aconc (cdr w) (car w)))) )
    (setq v (multf (brace w l nil) v))
    (go l1)
l8  (setq v (mkg w l))
    (setq z (reverse z))
    (setq k (quotient k 2))
    (go l1)
l9  (setq u (expt 2 k))
    (cond ((not (equal (remainder (difference k m) 2) 0)) (setq u (minus u))))
    (return (multn u v))))

(de appr (u v) (cond ((null u) v) (t (appr (cdr u) (cons (car u) v)))) )

(de exc (u v) (cond ((null (cdr u)) v) (t (not v))))

(de brace (u l i)
  (cond
    ((null u) 2)
    ((or (xn i u) (flagp l 'nospur)) (addf (mkg1 u l) (mkg1 (reverse u) l)))
    ((eq (car u) 'a)
      (cond
        ((!*evenp u)
          (addf
            (mkg u l)
            (multn (minus 1) (mkg (cons 'a (reverse (cdr u))) l))))
        (t (multf (mka l) (spr2 (cdr u) l 2 nil)))) )
    ((!*evenp u) (spr2 u l 2 nil))
    (t (spr1 u l 2 nil))))

(de spr1 (u l n b)
  (cond
    ((null u) nil)
    ((null (cdr u)) (multn n (mkg1 u l)))
    (t (prog (m x z)
        (setq x u)
        (setq m 0)
  a     (cond ((null x) (return z)))
        (setq z
          (addf
            (multf
              (mkg1 (list (car x)) l)
              (cond
                ((null b) (spurr (remove u m) l nil n))
                (t (spr1 (remove u m) l n nil))))
            z))
        (setq x (cdr x))
        (setq n (minus n))
        (setq m (plus m 1))
        (go a)))) )

(de remove (x n)
  (cond
    ((null x) nil)
    ((equal n 0) (cdr x))
    (t (cons (car x) (remove (cdr x) (difference n 1)))) ))

(de spr2 (u l n b)
  (cond
    ((and (null (cddr u)) (null b)) (multn n (mkdot (car u) (cadr u))))
    (t ((lambda (x) (cond (b (addf (spr1 u l n b) x)) (t x)))
        (addf
          (spurr u l nil n)
          (multf (mka l) (spurr (append u (list 'a)) l nil n)))) )))

(de !*evenp (u) (or (null u) (not (!*evenp (cdr u)))) )

(de bassoc (u v)
  (cond
    ((null v) nil)
    ((or (eq u (caar v)) (eq u (cdar v))) (car v))
    (t (bassoc u (cdr v)))) )

(de memlis (u v)
  (cond ((null v) nil) ((member u (car v)) (car v)) (t (memlis u (cdr v)))) )

(de spurr (u l v n)
  (prog (m w x y z)
a   (cond ((null u) (go b)) ((member (car u) (cdr u)) (go g)))
    (setq v (cons (car u) v))
    (setq u (cdr u))
    (go a)
b   (return
      (cond
        ((null v) n)
        ((flagp l 'nospur) (multn n (mkgf v l)))
        (t (sprgen v n))))
g   (setq x (car u))
    (setq y (cdr u))
    (setq w y)
    (setq m 0)
h   (cond
      ((eq x (car w))
        (return (addf (multf (mkdot x x) (spurr (delete x y) l v n)) z))))
    (setq z
      (addf (multf (mkdot x (car w)) (spurr (remove y m) l v (times 2 n))) z))
    (setq w (cdr w))
    (setq n (minus n))
    (setq m (plus m 1))
    (go h)))

(de sprgen (v n)
  (prog (x z)
    (cond
      ((not (eq (car v) 'a)) (return (sprgen1 v n)))
      ((null (setq x (comb (setq v (cdr v)) 4))) (return nil))
      ((null (cdr x)) (go e)))
c   (cond ((null x) (return (multf2 (mksp 'i 1) z))))
    (setq z
      (addf
        (multn
          (asign (car x) v n)
          (multf (mkeps1 (car x)) (sprgen1 (setdiff v (car x)) 1)))
        z))
d   (setq x (cdr x))
    (go c)
e   (setq z (multn n (mkeps1 (car x))))
    (go d)))

(de asign (u v n)
  (cond
    ((null u) n)
    (t (asign (cdr u) v (times (asign1 (car u) v (minus 1)) n)))) )

(de asign1 (u v n) (cond ((eq u (car v)) n) (t (asign1 u (cdr v) (minus n)))) )

(de sprgen1 (u n)
  (cond
    ((null u) nil)
    ((null (cddr u)) (multn n (mkdot (car u) (cadr u))))
    (t (prog (w x y z)
        (setq x (car u))
        (setq u (cdr u))
        (setq y u)
  a     (cond ((null u) (return z)) ((null (setq w (mkdot x (car u)))) (go b)))
        (setq z (addf (multf w (sprgen1 (delete (car u) y) n)) z))
  b     (setq n (minus n))
        (setq u (cdr u))
        (go a)))) )

(put 'eps 'simpfn 'simpeps)

(de comb (u n)
  (prog (v m)
    (setq m 0)
    (cond
      ((equal n 0) (return (list nil)))
      ((lessp (setq m (difference (length u) n)) 0) (return nil)))
a   (cond ((equal m 0) (return (cons u v))))
    (setq v (nconc v (mapcons (comb (cdr u) (difference n 1)) (car u))))
    (setq u (cdr u))
    (setq m (difference m 1))
    (go a)))

(de simpeps (u)
  (mkvarg
    u
    (function (lambda (j) (cons (cond ((repeats j) nil) (t (mkeps1 j))) 1)))) )

(de mkeps1 (u)
  (prog2
    (cond
      ((and (xn u indices!*) (not (member 'isimpq mul!*)))
        (setq mul!* (aconc mul!* 'isimpq)))
      (t nil))
    ((lambda (x) (multn (nb (permp x u)) (mksf (cons 'eps x) 1))) (ordn u))))

(de esum (u i v w x)
  (prog (y z z1)
    (setq z (car u))
    (setq u (cdr u))
    (cond
      ((neq (cdr z) 1)
        (setq u (multf (exptf (mkeps1 (cdar z)) (difference (cdr z) 1)) u))))
    (setq z (cdar z))
a   (cond ((repeats z) (return nil)))
b   (cond
      ((null z) (return (isimp1 u i v (cons (reverse y) w) x)))
      ((not (member (car z) i)) (go d))
      ((not (setq z1 (bassoc (car z) v))) (go c)))
    (setq v (delete z1 v))
    (setq i (delete (car z) i))
    (setq z (append (reverse y) (cons (other (car z) z1) (cdr z))))
    (setq y nil)
    (go a)
c   (cond
      ((setq z1 (memlis (car z) w)) (go c1))
      (t (return (isimp1 u i v (cons (append (reverse y) z) w) x))))
c1  (setq z (append (reverse y) z))
    (setq y (xn i (xn z z1)))
    (return (isimp1 (multf (emult1 z1 z y) u) (setdiff i y) v (delete z1 w) x))
d   (setq y (cons (car z) y))
    (setq z (cdr z))
    (go b)))

(de emult (u)
  (cond
    ((null (cdr u)) (mkeps1 (car u) 1))
    ((null (cddr u)) (emult1 (car u) (cadr u) nil))
    (t (multf (emult1 (car u) (cadr u) nil) (emult (cddr u)))) ))

(de emult1 (u v i)
  ((lambda (x !*s!*)
     ((lambda (m n)
        (cond
          ((equal m 4) (times 24 n))
          ((equal m 3) (multn (times 6 n) (mkdot (car x) (car !*s!*))))
          (t (multn
              (times n (cond ((equal m 0) 1) (t m)))
              (car
                (detq
                  (maplist
                    x
                    (function
                      (lambda (!*s1!*)
                        (maplist
                          !*s!*
                          (function
                            (lambda (j)
                              (cons
                                (mkdot (car !*s1!*) (car j))
                                1)))) ))) ))) )))
       (length i)
       ((lambda (j) (nb (cond ((permp u (append i x)) (not j)) (t j))))
         (permp v (append i !*s!*)))) )
    (setdiff u i)
    (setdiff v i)))

(de depend1 (u v)
  (prog (x y z)
    (cond ((or (not (atom (car u))) (numberp (car u))) (errpri2 (car u) t)))
    (setq x (list (car u) (reval (cadr u))))
    (setq y (assoc (car x) depl!*))
    (cond
      (y
        (cond
          (v (rplacd y (union (cdr x) (cdr y))))
          ((setq z (setdiff (cdr y) (cdr x))) (rplacd y z))
          (t (setq depl!* (delete y depl!*)))) )
      ((null v) nil)
      (t (setq depl!* (cons x depl!*)))) ))

(de depend (u) (depend1 u t))

(de nodepend (u) (depend1 u nil))

(put 'depend 'stat 'rlis)

(put 'nodepend 'stat 'rlis)

(de depdl2 (x v)
  (cond
    ((null x) nil)
    ((member v (assoc (car x) depl!*)) t)
    (t (depdl2 (cdr x) v))))

(de depdl1 (x v)
  (cond ((null v) nil) ((depdl2 x (car v)) t) (t (depdl1 x (cdr v)))) )

(de flvar (u)
  (prog (x)
a   (cond ((null u) (return x)) ((atom u) (return (union (list u) x))))
    (setq x (union (flvar (car u)) x))
    (setq u (cdr u))
    (go a)))

(de dependl (u v)
  ((lambda (x) (or (xn x v) (and depl!* (depdl1 x v)))) (flvar u)))

(flagop (list 'linear))

(put 'linear 'simpfg '((rmsubs)))

(de formlntms (u v w x)
  (prog (y z)
a   (cond
      ((null v)
        (return
          (cond
            ((null z) x)
            (t (cons
                'times
                (aconc
                  (reverse z)
                  (cond
                    ((null (cdr y)) (formlnr (cons u (cons (car y) w))))
                    (t (cons u (cons (cons 'times (reverse y)) w)))) ))) )))
      ((dependl (car v) w) (setq y (cons (car v) y)))
      (t (setq z (cons (car v) z))))
    (setq v (cdr v))
    (go a)))

(de formlnr (u)
  ((lambda (!*s!* y !*s1!*)
     (cond
       ((equal y 1) u)
       ((not (dependl y !*s1!*)) (list 'times y (cons !*s!* (cons 1 !*s1!*))))
       ((atom y) u)
       ((eq (car y) 'plus)
         (cons
           'plus
           (mapcar
             (cdr y)
             (function (lambda (j) (formlnr (cons !*s!* (cons j !*s1!*)))) ))) )
       ((eq (car y) 'minus)
         (list 'minus (formlnr (cons !*s!* (cons (cadr y) !*s1!*)))) )
       ((eq (car y) 'difference)
         (list
           'difference
           (formlnr (cons !*s!* (cons (cadr y) !*s1!*)))
           (formlnr (cons !*s!* (cons (caddr y) !*s1!*)))) )
       ((eq (car y) 'times) (formlntms !*s!* (cdr y) !*s1!* u))
       ((and (eq (car y) 'quotient) (not (dependl (caddr y) !*s1!*)))
         (list
           'quotient
           (formlnr (cons !*s!* (cons (cadr y) !*s1!*)))
           (caddr y)))
       ((and (eq (car y) 'recip) (not (dependl (cadr y) !*s1!*)))
         (list 'quotient (cons !*s!* (cons 1 !*s1!*)) (cadr y)))
       (t u)))
    (car u)
    (cadr u)
    (cddr u)))

(setq iecho!* t)

(setq imode!* 'algebraic)

(setq date!* "AUG-10-73")
