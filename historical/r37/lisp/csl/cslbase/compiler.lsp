
% RLISP to LISP converter. A C Norman 2002


%
% This code may be used and modified, and redistributed in binary
% or source form, subject to the "CCL Public License", which should
% accompany it. This license is a variant on the BSD license, and thus
% permits use of code derived from this in either open and commercial
% projects: but it does require that updates to this code be made
% available back to the originators of the package.
% Before merging other code in with this or linking this code
% with other packages or libraries please check that the license terms
% of the other material are compatible with those of this.
%


(global (quote (s!:opcodelist)))



(setq s!:opcodelist (quote (LOADLOC LOADLOC0 LOADLOC1 LOADLOC2 LOADLOC3 
LOADLOC4 LOADLOC5 LOADLOC6 LOADLOC7 LOADLOC8 LOADLOC9 LOADLOC10 LOADLOC11 
LOC0LOC1 LOC1LOC2 LOC2LOC3 LOC1LOC0 LOC2LOC1 LOC3LOC2 VNIL LOADLIT LOADLIT1 
LOADLIT2 LOADLIT3 LOADLIT4 LOADLIT5 LOADLIT6 LOADLIT7 LOADFREE LOADFREE1 
LOADFREE2 LOADFREE3 LOADFREE4 STORELOC STORELOC0 STORELOC1 STORELOC2 
STORELOC3 STORELOC4 STORELOC5 STORELOC6 STORELOC7 STOREFREE STOREFREE1 
STOREFREE2 STOREFREE3 LOADLEX STORELEX CLOSURE CARLOC0 CARLOC1 CARLOC2 
CARLOC3 CARLOC4 CARLOC5 CARLOC6 CARLOC7 CARLOC8 CARLOC9 CARLOC10 CARLOC11 
CDRLOC0 CDRLOC1 CDRLOC2 CDRLOC3 CDRLOC4 CDRLOC5 CAARLOC0 CAARLOC1 CAARLOC2 
CAARLOC3 CALL0 CALL1 CALL2 CALL2R CALL3 CALLN CALL0_0 CALL0_1 CALL0_2 CALL0_3
CALL1_0 CALL1_1 CALL1_2 CALL1_3 CALL1_4 CALL1_5 CALL2_0 CALL2_1 CALL2_2 
CALL2_3 CALL2_4 BUILTIN0 BUILTIN1 BUILTIN2 BUILTIN2R BUILTIN3 APPLY1 APPLY2 
APPLY3 APPLY4 JCALL JCALLN JUMP JUMP_B JUMP_L JUMP_BL JUMPNIL JUMPNIL_B 
JUMPNIL_L JUMPNIL_BL JUMPT JUMPT_B JUMPT_L JUMPT_BL JUMPATOM JUMPATOM_B 
JUMPATOM_L JUMPATOM_BL JUMPNATOM JUMPNATOM_B JUMPNATOM_L JUMPNATOM_BL JUMPEQ 
JUMPEQ_B JUMPEQ_L JUMPEQ_BL JUMPNE JUMPNE_B JUMPNE_L JUMPNE_BL JUMPEQUAL 
JUMPEQUAL_B JUMPEQUAL_L JUMPEQUAL_BL JUMPNEQUAL JUMPNEQUAL_B JUMPNEQUAL_L 
JUMPNEQUAL_BL JUMPL0NIL JUMPL0T JUMPL1NIL JUMPL1T JUMPL2NIL JUMPL2T JUMPL3NIL
JUMPL3T JUMPL4NIL JUMPL4T JUMPST0NIL JUMPST0T JUMPST1NIL JUMPST1T JUMPST2NIL
JUMPST2T JUMPL0ATOM JUMPL0NATOM JUMPL1ATOM JUMPL1NATOM JUMPL2ATOM 
JUMPL2NATOM JUMPL3ATOM JUMPL3NATOM JUMPFREE1NIL JUMPFREE1T JUMPFREE2NIL 
JUMPFREE2T JUMPFREE3NIL JUMPFREE3T JUMPFREE4NIL JUMPFREE4T JUMPFREENIL 
JUMPFREET JUMPLIT1EQ JUMPLIT1NE JUMPLIT2EQ JUMPLIT2NE JUMPLIT3EQ JUMPLIT3NE 
JUMPLIT4EQ JUMPLIT4NE JUMPLITEQ JUMPLITNE JUMPB1NIL JUMPB1T JUMPB2NIL JUMPB2T
JUMPFLAGP JUMPNFLAGP JUMPEQCAR JUMPNEQCAR CATCH CATCH_B CATCH_L CATCH_BL 
UNCATCH THROW PROTECT UNPROTECT PVBIND PVRESTORE FREEBIND FREERSTR EXIT 
NILEXIT LOC0EXIT LOC1EXIT LOC2EXIT PUSH PUSHNIL PUSHNIL2 PUSHNIL3 PUSHNILS 
POP LOSE LOSE2 LOSE3 LOSES SWOP EQ EQCAR EQUAL NUMBERP CAR CDR CAAR CADR CDAR
CDDR CONS NCONS XCONS ACONS LENGTH LIST2 LIST2STAR LIST3 PLUS2 ADD1 
DIFFERENCE SUB1 TIMES2 GREATERP LESSP FLAGP GET LITGET GETV QGETV QGETVN 
BIGSTACK BIGCALL ICASE FASTGET SPARE1 SPARE2)))

(if (demo!-mode) (progn (setq p s!:opcodelist) (prog (j) (setq j 0) lab1001 (
if (minusp (times 1 (difference 254 j))) (return nil)) (progn (setq n (
random!-number (difference 256 j))) (setq q p) (prog (k) (setq k 1) lab1000 (
if (minusp (times 1 (difference n k))) (return nil)) (setq q (cdr q)) (setq k
(plus k 1)) (go lab1000)) (setq w (car p)) (rplaca p (car q)) (rplaca q w) (
setq p (cdr p))) (setq j (plus j 1)) (go lab1001))))

(prog (n) (setq n 0) (prog (var1003) (setq var1003 s!:opcodelist) lab1002 (if
(null var1003) (return nil)) (prog (v) (setq v (car var1003)) (progn (put v 
(quote s!:opcode) n) (setq n (plus n 1)))) (setq var1003 (cdr var1003)) (go 
lab1002)) (return (list n (quote opcodes) (quote allocated))))

(setq s!:opcodelist nil)

(de s!:vecof (l) (prog (v n) (setq v (mkvect (sub1 (length l)))) (setq n 0) (
prog (var1005) (setq var1005 l) lab1004 (if (null var1005) (return nil)) (
prog (x) (setq x (car var1005)) (progn (putv v n x) (setq n (plus n 1)))) (
setq var1005 (cdr var1005)) (go lab1004)) (return v)))

(progn (put (quote batchp) (quote s!:builtin0) 0) (put (quote date) (quote 
s!:builtin0) 1) (put (quote eject) (quote s!:builtin0) 2) (put (quote error1)
(quote s!:builtin0) 3) (put (quote gctime) (quote s!:builtin0) 4) (put (
quote lposn) (quote s!:builtin0) 6) (put (quote posn) (quote s!:builtin0) 8) 
(put (quote read) (quote s!:builtin0) 9) (put (quote readch) (quote 
s!:builtin0) 10) (put (quote terpri) (quote s!:builtin0) 11) (put (quote time
) (quote s!:builtin0) 12) (put (quote tyi) (quote s!:builtin0) 13) (put (
quote load!-spid) (quote s!:builtin0) 14) (put (quote abs) (quote s!:builtin1
) 0) (put (quote add1) (quote s!:builtin1) 1) (put (quote atan) (quote 
s!:builtin1) 2) (put (quote apply0) (quote s!:builtin1) 3) (put (quote atom) 
(quote s!:builtin1) 4) (put (quote boundp) (quote s!:builtin1) 5) (put (quote
char!-code) (quote s!:builtin1) 6) (put (quote close) (quote s!:builtin1) 7)
(put (quote codep) (quote s!:builtin1) 8) (put (quote compress) (quote 
s!:builtin1) 9) (put (quote constantp) (quote s!:builtin1) 10) (put (quote 
digit) (quote s!:builtin1) 11) (put (quote endp) (quote s!:builtin1) 12) (put
(quote eval) (quote s!:builtin1) 13) (put (quote evenp) (quote s!:builtin1) 
14) (put (quote evlis) (quote s!:builtin1) 15) (put (quote explode) (quote 
s!:builtin1) 16) (put (quote explode2lc) (quote s!:builtin1) 17) (put (quote 
explode2) (quote s!:builtin1) 18) (put (quote explodec) (quote s!:builtin1) 
18) (put (quote fixp) (quote s!:builtin1) 19) (put (quote float) (quote 
s!:builtin1) 20) (put (quote floatp) (quote s!:builtin1) 21) (put (quote 
symbol!-specialp) (quote s!:builtin1) 22) (put (quote gc) (quote s!:builtin1)
23) (put (quote gensym1) (quote s!:builtin1) 24) (put (quote getenv) (quote 
s!:builtin1) 25) (put (quote symbol!-globalp) (quote s!:builtin1) 26) (put (
quote iadd1) (quote s!:builtin1) 27) (put (quote symbolp) (quote s!:builtin1)
28) (put (quote iminus) (quote s!:builtin1) 29) (put (quote iminusp) (quote 
s!:builtin1) 30) (put (quote indirect) (quote s!:builtin1) 31) (put (quote 
integerp) (quote s!:builtin1) 32) (put (quote intern) (quote s!:builtin1) 33)
(put (quote isub1) (quote s!:builtin1) 34) (put (quote length) (quote 
s!:builtin1) 35) (put (quote lengthc) (quote s!:builtin1) 36) (put (quote 
linelength) (quote s!:builtin1) 37) (put (quote liter) (quote s!:builtin1) 38
) (put (quote load!-module) (quote s!:builtin1) 39) (put (quote lognot) (
quote s!:builtin1) 40) (put (quote macroexpand) (quote s!:builtin1) 41) (put 
(quote macroexpand!-1) (quote s!:builtin1) 42) (put (quote macro!-function) (
quote s!:builtin1) 43) (put (quote make!-bps) (quote s!:builtin1) 44) (put (
quote make!-global) (quote s!:builtin1) 45) (put (quote make!-simple!-string)
(quote s!:builtin1) 46) (put (quote make!-special) (quote s!:builtin1) 47) (
put (quote minus) (quote s!:builtin1) 48) (put (quote minusp) (quote 
s!:builtin1) 49) (put (quote mkvect) (quote s!:builtin1) 50) (put (quote 
modular!-minus) (quote s!:builtin1) 51) (put (quote modular!-number) (quote 
s!:builtin1) 52) (put (quote modular!-reciprocal) (quote s!:builtin1) 53) (
put (quote null) (quote s!:builtin1) 54) (put (quote oddp) (quote s!:builtin1
) 55) (put (quote onep) (quote s!:builtin1) 56) (put (quote pagelength) (
quote s!:builtin1) 57) (put (quote pairp) (quote s!:builtin1) 58) (put (quote
plist) (quote s!:builtin1) 59) (put (quote plusp) (quote s!:builtin1) 60) (
put (quote prin) (quote s!:builtin1) 61) (put (quote princ) (quote 
s!:builtin1) 62) (put (quote print) (quote s!:builtin1) 63) (put (quote 
printc) (quote s!:builtin1) 64) (put (quote rational) (quote s!:builtin1) 66)
(put (quote rds) (quote s!:builtin1) 68) (put (quote remd) (quote 
s!:builtin1) 69) (put (quote reverse) (quote s!:builtin1) 70) (put (quote 
reversip) (quote s!:builtin1) 71) (put (quote seprp) (quote s!:builtin1) 72) 
(put (quote set!-small!-modulus) (quote s!:builtin1) 73) (put (quote spaces) 
(quote s!:builtin1) 74) (put (quote xtab) (quote s!:builtin1) 74) (put (quote
special!-char) (quote s!:builtin1) 75) (put (quote special!-form!-p) (quote 
s!:builtin1) 76) (put (quote spool) (quote s!:builtin1) 77) (put (quote stop)
(quote s!:builtin1) 78) (put (quote stringp) (quote s!:builtin1) 79) (put (
quote sub1) (quote s!:builtin1) 80) (put (quote symbol!-env) (quote 
s!:builtin1) 81) (put (quote symbol!-function) (quote s!:builtin1) 82) (put (
quote symbol!-name) (quote s!:builtin1) 83) (put (quote symbol!-value) (quote
s!:builtin1) 84) (put (quote system) (quote s!:builtin1) 85) (put (quote fix
) (quote s!:builtin1) 86) (put (quote ttab) (quote s!:builtin1) 87) (put (
quote tyo) (quote s!:builtin1) 88) (put (quote remob) (quote s!:builtin1) 89)
(put (quote unmake!-global) (quote s!:builtin1) 90) (put (quote 
unmake!-special) (quote s!:builtin1) 91) (put (quote upbv) (quote s!:builtin1
) 92) (put (quote vectorp) (quote s!:builtin1) 93) (put (quote verbos) (quote
s!:builtin1) 94) (put (quote wrs) (quote s!:builtin1) 95) (put (quote zerop)
(quote s!:builtin1) 96) (put (quote car) (quote s!:builtin1) 97) (put (quote
cdr) (quote s!:builtin1) 98) (put (quote caar) (quote s!:builtin1) 99) (put 
(quote cadr) (quote s!:builtin1) 100) (put (quote cdar) (quote s!:builtin1) 
101) (put (quote cddr) (quote s!:builtin1) 102) (put (quote qcar) (quote 
s!:builtin1) 103) (put (quote qcdr) (quote s!:builtin1) 104) (put (quote 
qcaar) (quote s!:builtin1) 105) (put (quote qcadr) (quote s!:builtin1) 106) (
put (quote qcdar) (quote s!:builtin1) 107) (put (quote qcddr) (quote 
s!:builtin1) 108) (put (quote ncons) (quote s!:builtin1) 109) (put (quote 
numberp) (quote s!:builtin1) 110) (put (quote is!-spid) (quote s!:builtin1) 
111) (put (quote spid!-to!-nil) (quote s!:builtin1) 112) (put (quote append) 
(quote s!:builtin2) 0) (put (quote ash) (quote s!:builtin2) 1) (put (quote 
assoc) (quote s!:builtin2) 2) (put (quote assoc!*!*) (quote s!:builtin2) 2) (
put (quote atsoc) (quote s!:builtin2) 3) (put (quote deleq) (quote 
s!:builtin2) 4) (put (quote delete) (quote s!:builtin2) 5) (put (quote divide
) (quote s!:builtin2) 6) (put (quote eqcar) (quote s!:builtin2) 7) (put (
quote eql) (quote s!:builtin2) 8) (put (quote eqn) (quote s!:builtin2) 9) (
put (quote expt) (quote s!:builtin2) 10) (put (quote flag) (quote s!:builtin2
) 11) (put (quote flagpcar) (quote s!:builtin2) 12) (put (quote gcdn) (quote 
s!:builtin2) 13) (put (quote geq) (quote s!:builtin2) 14) (put (quote getv) (
quote s!:builtin2) 15) (put (quote greaterp) (quote s!:builtin2) 16) (put (
quote idifference) (quote s!:builtin2) 17) (put (quote igreaterp) (quote 
s!:builtin2) 18) (put (quote ilessp) (quote s!:builtin2) 19) (put (quote imax
) (quote s!:builtin2) 20) (put (quote imin) (quote s!:builtin2) 21) (put (
quote iplus2) (quote s!:builtin2) 22) (put (quote iquotient) (quote 
s!:builtin2) 23) (put (quote iremainder) (quote s!:builtin2) 24) (put (quote 
irightshift) (quote s!:builtin2) 25) (put (quote itimes2) (quote s!:builtin2)
26) (put (quote leq) (quote s!:builtin2) 28) (put (quote lessp) (quote 
s!:builtin2) 29) (put (quote max2) (quote s!:builtin2) 31) (put (quote member
) (quote s!:builtin2) 32) (put (quote member!*!*) (quote s!:builtin2) 32) (
put (quote memq) (quote s!:builtin2) 33) (put (quote min2) (quote s!:builtin2
) 34) (put (quote mod) (quote s!:builtin2) 35) (put (quote 
modular!-difference) (quote s!:builtin2) 36) (put (quote modular!-expt) (
quote s!:builtin2) 37) (put (quote modular!-plus) (quote s!:builtin2) 38) (
put (quote modular!-quotient) (quote s!:builtin2) 39) (put (quote 
modular!-times) (quote s!:builtin2) 40) (put (quote nconc) (quote s!:builtin2
) 41) (put (quote neq) (quote s!:builtin2) 42) (put (quote orderp) (quote 
s!:builtin2) 43) (put (quote quotient) (quote s!:builtin2) 44) (put (quote 
remainder) (quote s!:builtin2) 45) (put (quote remflag) (quote s!:builtin2) 
46) (put (quote remprop) (quote s!:builtin2) 47) (put (quote rplaca) (quote 
s!:builtin2) 48) (put (quote rplacd) (quote s!:builtin2) 49) (put (quote 
schar) (quote s!:builtin2) 50) (put (quote set) (quote s!:builtin2) 51) (put 
(quote smemq) (quote s!:builtin2) 52) (put (quote subla) (quote s!:builtin2) 
53) (put (quote sublis) (quote s!:builtin2) 54) (put (quote 
symbol!-set!-definition) (quote s!:builtin2) 55) (put (quote symbol!-set!-env
) (quote s!:builtin2) 56) (put (quote times2) (quote s!:builtin2) 57) (put (
quote xcons) (quote s!:builtin2) 58) (put (quote equal) (quote s!:builtin2) 
59) (put (quote eq) (quote s!:builtin2) 60) (put (quote cons) (quote 
s!:builtin2) 61) (put (quote list2) (quote s!:builtin2) 62) (put (quote get) 
(quote s!:builtin2) 63) (put (quote qgetv) (quote s!:builtin2) 64) (put (
quote flagp) (quote s!:builtin2) 65) (put (quote apply1) (quote s!:builtin2) 
66) (put (quote difference) (quote s!:builtin2) 67) (put (quote plus2) (quote
s!:builtin2) 68) (put (quote times2) (quote s!:builtin2) 69) (put (quote 
equalcar) (quote s!:builtin2) 70) (put (quote iequal) (quote s!:builtin2) 71)
(put (quote nreverse) (quote s!:builtin2) 72) (put (quote bps!-putv) (quote 
s!:builtin3) 0) (put (quote errorset) (quote s!:builtin3) 1) (put (quote 
list2!*) (quote s!:builtin3) 2) (put (quote list3) (quote s!:builtin3) 3) (
put (quote putprop) (quote s!:builtin3) 4) (put (quote putv) (quote 
s!:builtin3) 5) (put (quote putv!-char) (quote s!:builtin3) 6) (put (quote 
subst) (quote s!:builtin3) 7) (put (quote apply2) (quote s!:builtin3) 8) (put
(quote acons) (quote s!:builtin3) 9) nil)

(de s!:prinhex1 (n) (princ (schar "0123456789abcdef" (logand n 15))))

(de s!:prinhex2 (n) (progn (s!:prinhex1 (truncate n 16)) (s!:prinhex1 n)))

(de s!:prinhex4 (n) (progn (s!:prinhex2 (truncate n 256)) (s!:prinhex2 n)))

(flag (quote (comp plap pgwd pwrds notailcall ord nocompile carcheckflag 
savedef carefuleq r2i)) (quote switch))

(if (not (boundp (quote !*comp))) (progn (fluid (quote (!*comp))) (setq 
!*comp t)))

(if (not (boundp (quote !*nocompile))) (progn (fluid (quote (!*nocompile))) (
setq !*nocompile nil)))

(if (not (boundp (quote !*plap))) (progn (fluid (quote (!*plap))) (setq 
!*plap nil)))

(if (not (boundp (quote !*pgwd))) (progn (fluid (quote (!*pgwd))) (setq 
!*pgwd nil)))

(if (not (boundp (quote !*pwrds))) (progn (fluid (quote (!*pwrds))) (setq 
!*pwrds t)))

(if (not (boundp (quote !*notailcall))) (progn (fluid (quote (!*notailcall)))
(setq !*notailcall nil)))

(if (not (boundp (quote !*ord))) (progn (fluid (quote (!*ord))) (setq !*ord 
nil)))

(if (not (boundp (quote !*savedef))) (progn (fluid (quote (!*savedef))) (setq
!*savedef nil)))

(if (not (boundp (quote !*carcheckflag))) (progn (fluid (quote (
!*carcheckflag))) (setq !*carcheckflag t)))

(if (not (boundp (quote !*carefuleq))) (progn (fluid (quote (!*carefuleq))) (
setq !*carefuleq (or (and (boundp (quote lispsystem!*)) (not (null (member (
quote jlisp) lispsystem!*)))) (and (boundp (quote !*features!*)) (not (null (
member (quote !:jlisp) !*features!*))))))))

(if (not (boundp (quote !*r2i))) (progn (fluid (quote (!*r2i))) (setq !*r2i t
)))

(fluid (quote (s!:current_function s!:current_label s!:current_block 
s!:current_size s!:current_procedure s!:other_defs s!:lexical_env 
s!:has_closure s!:recent_literals s!:used_lexicals s!:a_reg_values 
s!:current_count)))

(de s!:start_procedure (nargs nopts restarg) (progn (setq 
s!:current_procedure nil) (setq s!:current_label (gensym)) (setq 
s!:a_reg_values nil) (if (or (not (zerop nopts)) restarg) (progn (setq 
s!:current_block (list (list (quote OPTARGS) nopts) nopts (list (quote 
ARGCOUNT) nargs) nargs)) (setq s!:current_size 2)) (if (greaterp nargs 3) (
progn (setq s!:current_block (list (list (quote ARGCOUNT) nargs) nargs)) (
setq s!:current_size 1)) (progn (setq s!:current_block nil) (setq 
s!:current_size 0))))))

(de s!:set_label (x) (progn (if s!:current_label (prog (w) (setq w (cons 
s!:current_size s!:current_block)) (prog (var1007) (setq var1007 
s!:recent_literals) lab1006 (if (null var1007) (return nil)) (prog (x) (setq 
x (car var1007)) (rplaca x w)) (setq var1007 (cdr var1007)) (go lab1006)) (
setq s!:recent_literals nil) (setq s!:current_procedure (cons (cons 
s!:current_label (cons (list (quote JUMP) x) w)) s!:current_procedure)) (setq
s!:current_block nil) (setq s!:current_size 0))) (setq s!:current_label x) (
setq s!:a_reg_values nil)))

(de s!:outjump (op lab) (prog (g w) (if (not (flagp op (quote s!:preserves_a)
)) (setq s!:a_reg_values nil)) (if (null s!:current_label) (return nil)) (if 
(equal op (quote JUMP)) (setq op (list op lab)) (if (equal op (quote ICASE)) 
(setq op (cons op lab)) (setq op (list op lab (setq g (gensym)))))) (setq w (
cons s!:current_size s!:current_block)) (prog (var1009) (setq var1009 
s!:recent_literals) lab1008 (if (null var1009) (return nil)) (prog (x) (setq 
x (car var1009)) (rplaca x w)) (setq var1009 (cdr var1009)) (go lab1008)) (
setq s!:recent_literals nil) (setq s!:current_procedure (cons (cons 
s!:current_label (cons op w)) s!:current_procedure)) (setq s!:current_block 
nil) (setq s!:current_size 0) (setq s!:current_label g) (return op)))

(de s!:outexit nil (prog (w op) (setq op (quote (EXIT))) (if (null 
s!:current_label) (return nil)) (setq w (cons s!:current_size 
s!:current_block)) (prog (var1011) (setq var1011 s!:recent_literals) lab1010 
(if (null var1011) (return nil)) (prog (x) (setq x (car var1011)) (rplaca x w
)) (setq var1011 (cdr var1011)) (go lab1010)) (setq s!:recent_literals nil) (
setq s!:current_procedure (cons (cons s!:current_label (cons op w)) 
s!:current_procedure)) (setq s!:current_block nil) (setq s!:current_size 0) (
setq s!:current_label nil)))

(flag (quote (PUSH PUSHNIL PUSHNIL2 PUSHNIL3 LOSE LOSE2 LOSE3 LOSES STORELOC 
STORELOC0 STORELOC1 STORELOC2 STORELOC3 STORELOC4 STORELOC5 STORELOC6 
STORELOC7 JUMP JUMPT JUMPNIL JUMPEQ JUMPEQUAL JUMPNE JUMPNEQUAL JUMPATOM 
JUMPNATOM)) (quote s!:preserves_a))

(de s!:outopcode0 (op doc) (prog nil (if (not (flagp op (quote s!:preserves_a
))) (setq s!:a_reg_values nil)) (if (null s!:current_label) (return nil)) (
setq s!:current_block (cons op s!:current_block)) (setq s!:current_size (plus
s!:current_size 1)) (if (or !*plap !*pgwd) (setq s!:current_block (cons doc 
s!:current_block)))))

(de s!:outopcode1 (op arg doc) (prog nil (if (not (flagp op (quote 
s!:preserves_a))) (setq s!:a_reg_values nil)) (if (null s!:current_label) (
return nil)) (setq s!:current_block (cons arg (cons op s!:current_block))) (
setq s!:current_size (plus s!:current_size 2)) (if (or !*plap !*pgwd) (setq 
s!:current_block (cons (list op doc) s!:current_block)))))

(deflist (quote ((LOADLIT 1) (LOADFREE 2) (CALL0 2) (CALL1 2) (LITGET 2) (
JUMPLITEQ 2) (JUMPLITNE 2) (JUMPLITEQ!* 2) (JUMPLITNE!* 2) (JUMPFREET 2) (
JUMPFREENIL 2))) (quote s!:short_form_bonus))

(de s!:record_literal (env) (prog (w extra) (setq w (gethash (car 
s!:current_block) (car env))) (if (null w) (setq w (cons 0 nil))) (setq extra
(get (cadr s!:current_block) (quote s!:short_form_bonus))) (if (null extra) 
(setq extra 10) (setq extra (plus extra 10))) (setq s!:recent_literals (cons 
(cons nil s!:current_block) s!:recent_literals)) (puthash (car 
s!:current_block) (car env) (cons (plus (car w) extra) (cons (car 
s!:recent_literals) (cdr w))))))

(de s!:record_literal_for_jump (x env lab) (prog (w extra) (if (null 
s!:current_label) (return nil)) (setq w (gethash (cadr x) (car env))) (if (
null w) (setq w (cons 0 nil))) (setq extra (get (car x) (quote 
s!:short_form_bonus))) (if (null extra) (setq extra 10) (setq extra (plus 
extra 10))) (setq x (s!:outjump x lab)) (puthash (cadar x) (car env) (cons (
plus (car w) extra) (cons (cons nil x) (cdr w))))))

(de s!:outopcode1lit (op arg env) (prog nil (if (not (flagp op (quote 
s!:preserves_a))) (setq s!:a_reg_values nil)) (if (null s!:current_label) (
return nil)) (setq s!:current_block (cons arg (cons op s!:current_block))) (
s!:record_literal env) (setq s!:current_size (plus s!:current_size 2)) (if (
or !*plap !*pgwd) (setq s!:current_block (cons (list op arg) s!:current_block
)))))

(de s!:outopcode2 (op arg1 arg2 doc) (prog nil (if (not (flagp op (quote 
s!:preserves_a))) (setq s!:a_reg_values nil)) (if (null s!:current_label) (
return nil)) (setq s!:current_block (cons arg2 (cons arg1 (cons op 
s!:current_block)))) (setq s!:current_size (plus s!:current_size 3)) (if (or 
!*plap !*pgwd) (setq s!:current_block (cons (cons op doc) s!:current_block)))
))

(de s!:outopcode2lit (op arg1 arg2 doc env) (prog nil (if (not (flagp op (
quote s!:preserves_a))) (setq s!:a_reg_values nil)) (if (null 
s!:current_label) (return nil)) (setq s!:current_block (cons arg1 (cons op 
s!:current_block))) (s!:record_literal env) (setq s!:current_block (cons arg2
s!:current_block)) (setq s!:current_size (plus s!:current_size 3)) (if (or 
!*plap !*pgwd) (setq s!:current_block (cons (cons op doc) s!:current_block)))
))

(de s!:outlexref (op arg1 arg2 arg3 doc) (prog (arg4) (if (null 
s!:current_label) (return nil)) (if (or (greaterp arg1 255) (greaterp arg2 
255) (greaterp arg3 255)) (progn (if (or (greaterp arg1 2047) (greaterp arg2 
31) (greaterp arg3 2047)) (error "stack frame > 2047 or > 31 deep nesting")) 
(setq doc (list op doc)) (setq arg4 (logand arg3 255)) (setq arg3 (plus (
truncate arg3 256) (times 16 (logand arg1 15)))) (if (equal op (quote LOADLEX
)) (setq op (plus 192 arg2)) (setq op (plus 224 arg2))) (setq arg2 (truncate 
arg1 16)) (setq arg1 op) (setq op (quote BIGSTACK))) (setq doc (list doc))) (
setq s!:current_block (cons arg3 (cons arg2 (cons arg1 (cons op 
s!:current_block))))) (setq s!:current_size (plus s!:current_size 4)) (if 
arg4 (progn (setq s!:current_block (cons arg4 s!:current_block)) (setq 
s!:current_size (plus s!:current_size 1)))) (if (or !*plap !*pgwd) (setq 
s!:current_block (cons (cons op doc) s!:current_block)))))

(put (quote LOADLIT) (quote s!:shortform) (cons (quote (1 . 7)) (s!:vecof (
quote (!- LOADLIT1 LOADLIT2 LOADLIT3 LOADLIT4 LOADLIT5 LOADLIT6 LOADLIT7)))))

(put (quote LOADFREE) (quote s!:shortform) (cons (quote (1 . 4)) (s!:vecof (
quote (!- LOADFREE1 LOADFREE2 LOADFREE3 LOADFREE4)))))

(put (quote STOREFREE) (quote s!:shortform) (cons (quote (1 . 3)) (s!:vecof (
quote (!- STOREFREE1 STOREFREE2 STOREFREE3)))))

(put (quote CALL0) (quote s!:shortform) (cons (quote (0 . 3)) (s!:vecof (
quote (CALL0_0 CALL0_1 CALL0_2 CALL0_3)))))

(put (quote CALL1) (quote s!:shortform) (cons (quote (0 . 5)) (s!:vecof (
quote (CALL1_0 CALL1_1 CALL1_2 CALL1_3 CALL1_4 CALL1_5)))))

(put (quote CALL2) (quote s!:shortform) (cons (quote (0 . 4)) (s!:vecof (
quote (CALL2_0 CALL2_1 CALL2_2 CALL2_3 CALL2_4)))))

(put (quote JUMPFREET) (quote s!:shortform) (cons (quote (1 . 4)) (s!:vecof (
quote (!- JUMPFREE1T JUMPFREE2T JUMPFREE3T JUMPFREE4T)))))

(put (quote JUMPFREENIL) (quote s!:shortform) (cons (quote (1 . 4)) (s!:vecof
(quote (!- JUMPFREE1NIL JUMPFREE2NIL JUMPFREE3NIL JUMPFREE4NIL)))))

(put (quote JUMPLITEQ) (quote s!:shortform) (cons (quote (1 . 4)) (s!:vecof (
quote (!- JUMPLIT1EQ JUMPLIT2EQ JUMPLIT3EQ JUMPLIT4EQ)))))

(put (quote JUMPLITNE) (quote s!:shortform) (cons (quote (1 . 4)) (s!:vecof (
quote (!- JUMPLIT1NE JUMPLIT2NE JUMPLIT3NE JUMPLIT4NE)))))

(put (quote JUMPLITEQ!*) (quote s!:shortform) (get (quote JUMPLITEQ) (quote 
s!:shortform)))

(put (quote JUMPLITNE!*) (quote s!:shortform) (get (quote JUMPLITNE) (quote 
s!:shortform)))

(put (quote CALL0) (quote s!:longform) 0)

(put (quote CALL1) (quote s!:longform) 16)

(put (quote CALL2) (quote s!:longform) 32)

(put (quote CALL3) (quote s!:longform) 48)

(put (quote CALLN) (quote s!:longform) 64)

(put (quote CALL2R) (quote s!:longform) 80)

(put (quote LOADFREE) (quote s!:longform) 96)

(put (quote STOREFREE) (quote s!:longform) 112)

(put (quote JCALL0) (quote s!:longform) 128)

(put (quote JCALL1) (quote s!:longform) 144)

(put (quote JCALL2) (quote s!:longform) 160)

(put (quote JCALL3) (quote s!:longform) 176)

(put (quote JCALLN) (quote s!:longform) 192)

(put (quote FREEBIND) (quote s!:longform) 208)

(put (quote LITGET) (quote s!:longform) 224)

(put (quote LOADLIT) (quote s!:longform) 240)

(de s!:literal_order (a b) (if (equal (cadr a) (cadr b)) (orderp (car a) (car
b)) (greaterp (cadr a) (cadr b))))

(de s!:resolve_literals (env) (prog (w op opspec n litbytes) (setq w (
hashcontents (car env))) (setq w (sort w (function s!:literal_order))) (setq 
n (length w)) (setq litbytes (times 4 n)) (if (greaterp n 4096) (setq w (
s!:too_many_literals w n))) (setq n 0) (prog (var1013) (setq var1013 w) 
lab1012 (if (null var1013) (return nil)) (prog (x) (setq x (car var1013)) (
progn (rplaca (cdr x) n) (setq n (plus n 1)))) (setq var1013 (cdr var1013)) (
go lab1012)) (prog (var1017) (setq var1017 w) lab1016 (if (null var1017) (
return nil)) (prog (x) (setq x (car var1017)) (progn (setq n (cadr x)) (prog 
(var1015) (setq var1015 (cddr x)) lab1014 (if (null var1015) (return nil)) (
prog (y) (setq y (car var1015)) (progn (if (null (car y)) (progn (setq op (
caadr y)) (setq opspec (get op (quote s!:shortform))) (if (and opspec (leq (
caar opspec) n) (leq n (cdar opspec))) (rplaca (cdr y) (getv (cdr opspec) n))
(rplaca (cdadr y) n))) (progn (setq op (caddr y)) (if (greaterp n 255) (
progn (rplaca (car y) (plus (caar y) 1)) (setq op (plus (get op (quote 
s!:longform)) (truncate n 256))) (rplaca (cdr y) (ilogand n 255)) (rplaca (
cddr y) (quote BIGCALL)) (rplacd (cdr y) (cons op (cddr y)))) (if (and (setq 
opspec (get op (quote s!:shortform))) (leq (caar opspec) n) (leq n (cdar 
opspec))) (progn (rplaca (car y) (difference (caar y) 1)) (rplaca (cdr y) (
getv (cdr opspec) n)) (rplacd (cdr y) (cdddr y))) (rplaca (cdr y) n))))))) (
setq var1015 (cdr var1015)) (go lab1014)))) (setq var1017 (cdr var1017)) (go 
lab1016)) (prog (var1019) (setq var1019 w) lab1018 (if (null var1019) (return
nil)) (prog (x) (setq x (car var1019)) (rplacd x (cadr x))) (setq var1019 (
cdr var1019)) (go lab1018)) (rplaca env (cons (reversip w) litbytes))))

(de s!:only_loadlit (l) (if (null l) t (if (null (caar l)) nil (if (not (
eqcar (cddar l) (quote LOADLIT))) nil (s!:only_loadlit (cdr l))))))

(de s!:too_many_literals (w n) (prog (k xvecs l r newrefs uses z1) (setq k 0)
(setq n (plus n 1)) (prog nil lab1020 (if (null (and (greaterp n 4096) (not 
(null w)))) (return nil)) (progn (if (and (not (equal (cadar w) 10000000)) (
s!:only_loadlit (cddar w))) (progn (setq l (cons (car w) l)) (setq n (
difference n 1)) (setq k (plus k 1)) (if (equal k 256) (progn (setq xvecs (
cons l xvecs)) (setq l nil) (setq k 0) (setq n (plus n 1))))) (setq r (cons (
car w) r))) (setq w (cdr w))) (go lab1020)) (if (greaterp n 4096) (error 
"function uses too many literals (4096 is limit)")) (setq xvecs (cons l xvecs
)) (prog nil lab1021 (if (null r) (return nil)) (progn (setq w (cons (car r) 
w)) (setq r (cdr r))) (go lab1021)) (prog (var1027) (setq var1027 xvecs) 
lab1026 (if (null var1027) (return nil)) (prog (v) (setq v (car var1027)) (
progn (setq newrefs nil) (setq uses 0) (setq r nil) (setq k 0) (prog (var1025
) (setq var1025 v) lab1024 (if (null var1025) (return nil)) (prog (q) (setq q
(car var1025)) (progn (prog (var1023) (setq var1023 (cddr q)) lab1022 (if (
null var1023) (return nil)) (prog (z) (setq z (car var1023)) (progn (if (car 
z) (rplaca (car z) (plus (caar z) 2))) (setq z1 (cons (quote QGETVN) (cons 
nil (cddr z)))) (rplaca (cdr z) k) (rplacd (cdr z) z1) (rplacd z (cdr z1)) (
setq newrefs (cons z newrefs)) (setq uses (plus uses 11)))) (setq var1023 (
cdr var1023)) (go lab1022)) (setq r (cons (car q) r)) (setq k (plus k 1)))) (
setq var1025 (cdr var1025)) (go lab1024)) (setq newrefs (cons uses newrefs)) 
(setq newrefs (cons (s!:vecof (reversip r)) newrefs)) (setq w (cons newrefs w
)))) (setq var1027 (cdr var1027)) (go lab1026)) (return (sort w (function 
s!:literal_order)))))

(fluid (quote (s!:into_c)))

(de s!:endprocedure (name env) (prog (pc labelvals w vec) (s!:outexit) (if 
s!:into_c (return (cons s!:current_procedure env))) (s!:resolve_literals env)
(setq s!:current_procedure (s!:tidy_flowgraph s!:current_procedure)) (if (
and (not !*notailcall) (not s!:has_closure)) (setq s!:current_procedure (
s!:try_tailcall s!:current_procedure))) (setq s!:current_procedure (
s!:tidy_exits s!:current_procedure)) (setq labelvals (s!:resolve_labels)) (
setq pc (car labelvals)) (setq labelvals (cdr labelvals)) (setq vec (
make!-bps pc)) (setq pc 0) (if (or !*plap !*pgwd) (progn (terpri) (ttab 23) (
princ "+++ ") (prin name) (princ " +++") (terpri))) (prog (var1029) (setq 
var1029 s!:current_procedure) lab1028 (if (null var1029) (return nil)) (prog 
(b) (setq b (car var1029)) (progn (if (and (car b) (flagp (car b) (quote 
used_label)) (or !*plap !*pgwd)) (progn (ttab 20) (prin (car b)) (princ ":") 
(terpri))) (setq pc (s!:plant_basic_block vec pc (reverse (cdddr b)))) (setq 
b (cadr b)) (if (and b (not (equal (car b) (quote ICASE))) (cdr b) (cddr b)) 
(setq b (list (car b) (cadr b)))) (setq pc (s!:plant_exit_code vec pc b 
labelvals)))) (setq var1029 (cdr var1029)) (go lab1028)) (if !*pwrds (progn (
if (neq (posn) 0) (terpri)) (princ "+++ ") (prin name) (princ " compiled, ") 
(princ pc) (princ " + ") (princ (cdar env)) (princ " bytes") (terpri))) (setq
env (caar env)) (if (null env) (setq w nil) (progn (setq w (mkvect (cdar env
))) (prog nil lab1030 (if (null env) (return nil)) (progn (putv w (cdar env) 
(caar env)) (setq env (cdr env))) (go lab1030)))) (return (cons vec w))))

(de s!:add_pending (lab pend blocks) (prog (w) (if (not (atom lab)) (return (
cons (list (gensym) lab 0) pend))) (setq w (atsoc lab pend)) (if w (return (
cons w (deleq w pend))) (return (cons (atsoc lab blocks) pend)))))

(de s!:invent_exit (x blocks) (prog (w) (setq w blocks) scan (if (null w) (go
not_found) (if (and (eqcar (cadar w) x) (equal (caddar w) 0)) (return (cons 
(caar w) blocks)) (setq w (cdr w)))) (go scan) not_found (setq w (gensym)) (
return (cons w (cons (list w (list x) 0) blocks)))))

(de s!:destination_label (lab blocks) (prog (n w x) (setq w (atsoc lab blocks
)) (if (s!:is_lose_and_exit w blocks) (return (quote (EXIT)))) (setq x (cadr 
w)) (setq n (caddr w)) (setq w (cdddr w)) (if (neq n 0) (return lab)) (if (or
(null x) (null (cdr x))) (return x) (if (equal (cadr x) lab) (return lab) (
if (null (cddr x)) (return (s!:destination_label (cadr x) blocks)) (return 
lab))))))

(de s!:remlose (b) (prog (w) (setq w b) (prog nil lab1031 (if (null (and w (
not (atom (car w))))) (return nil)) (setq w (cdr w)) (go lab1031)) (if (null 
w) (return (cons 0 b))) (if (and (numberp (car w)) (eqcar (cdr w) (quote 
LOSES))) (setq w (cons 2 (cddr w))) (if (or (equal (car w) (quote LOSE)) (
equal (car w) (quote LOSE2)) (equal (car w) (quote LOSE3))) (setq w (cons 1 (
cdr w))) (return (cons 0 b)))) (setq b (s!:remlose (cdr w))) (return (cons (
plus (car w) (car b)) (cdr b)))))

(put (quote CALL0_0) (quote s!:shortcall) (quote (0 . 0)))

(put (quote CALL0_1) (quote s!:shortcall) (quote (0 . 1)))

(put (quote CALL0_2) (quote s!:shortcall) (quote (0 . 2)))

(put (quote CALL0_3) (quote s!:shortcall) (quote (0 . 3)))

(put (quote CALL1_0) (quote s!:shortcall) (quote (1 . 0)))

(put (quote CALL1_1) (quote s!:shortcall) (quote (1 . 1)))

(put (quote CALL1_2) (quote s!:shortcall) (quote (1 . 2)))

(put (quote CALL1_3) (quote s!:shortcall) (quote (1 . 3)))

(put (quote CALL1_4) (quote s!:shortcall) (quote (1 . 4)))

(put (quote CALL1_5) (quote s!:shortcall) (quote (1 . 5)))

(put (quote CALL2_0) (quote s!:shortcall) (quote (2 . 0)))

(put (quote CALL2_1) (quote s!:shortcall) (quote (2 . 1)))

(put (quote CALL2_2) (quote s!:shortcall) (quote (2 . 2)))

(put (quote CALL2_3) (quote s!:shortcall) (quote (2 . 3)))

(put (quote CALL2_4) (quote s!:shortcall) (quote (2 . 4)))

(de s!:remcall (b) (prog (w p q r s) (prog nil lab1032 (if (null (and b (not 
(atom (car b))))) (return nil)) (progn (setq p (car b)) (setq b (cdr b))) (go
lab1032)) (if (null b) (return nil) (if (numberp (car b)) (progn (setq r (
car b)) (setq s 2) (setq b (cdr b)) (if (null b) (return nil) (if (numberp (
car b)) (progn (setq q r) (setq r (car b)) (setq s 3) (setq b (cdr b)) (if (
and b (numberp (setq w (car b))) (eqcar (cdr b) (quote BIGCALL)) (equal (
truncate w 16) 4)) (progn (setq r (plus (times 256 (logand w 15)) r)) (setq s
4) (setq b (cdr b))) (if (eqcar b (quote BIGCALL)) (progn (setq w (truncate 
r 16)) (setq r (plus (times 256 (logand r 15)) q)) (setq q w) (if (equal q 5)
(progn (setq q 2) (setq s (difference s 1)) (setq b (cons (quote BIGCALL) (
cons (quote SWOP) (cdr b)))))) (if (greaterp q 4) (return nil))) (if (not (
eqcar b (quote CALLN))) (return nil))))) (if (equal (car b) (quote CALL0)) (
setq q 0) (if (equal (car b) (quote CALL1)) (setq q 1) (if (equal (car b) (
quote CALL2)) (setq q 2) (if (equal (car b) (quote CALL2R)) (progn (setq q 2)
(setq s (difference s 1)) (setq b (cons (quote CALL2) (cons (quote SWOP) (
cdr b))))) (if (equal (car b) (quote CALL3)) (setq q 3) (return nil)))))))) (
setq b (cdr b))) (if (setq q (get (car b) (quote s!:shortcall))) (progn (setq
r (cdr q)) (setq q (car q)) (setq s 1) (setq b (cdr b))) (return nil)))) (
return (cons p (cons q (cons r (cons s b)))))))

(de s!:is_lose_and_exit (b blocks) (prog (lab exit) (setq lab (car b)) (setq 
exit (cadr b)) (setq b (cdddr b)) (if (null exit) (return nil)) (setq b (
s!:remlose b)) (setq b (cdr b)) (prog nil lab1033 (if (null (and b (not (atom
(car b))))) (return nil)) (setq b (cdr b)) (go lab1033)) (if b (return nil) 
(if (equal (car exit) (quote EXIT)) (return t) (if (equal (car exit) (quote 
JUMP)) (progn (if (equal (cadr exit) lab) nil (return (s!:is_lose_and_exit (
atsoc (cadr exit) blocks) blocks)))) (return nil))))))

(de s!:try_tail_1 (b blocks) (prog (exit size body w w0 w1 w2 op) (setq exit 
(cadr b)) (if (null exit) (return b) (if (not (equal (car exit) (quote EXIT))
) (progn (if (equal (car exit) (quote JUMP)) (progn (if (not (
s!:is_lose_and_exit (atsoc (cadr exit) blocks) blocks)) (return b))) (return 
b))))) (setq size (caddr b)) (setq body (cdddr b)) (setq body (s!:remlose 
body)) (setq size (difference size (car body))) (setq body (cdr body)) (setq 
w (s!:remcall body)) (if (null w) (return b)) (setq w0 (cadr w)) (setq w1 (
caddr w)) (setq body (cddddr w)) (if (and (leq w0 7) (leq w1 31)) (progn (
setq body (cons (quote JCALL) body)) (setq body (cons (plus (times 32 w0) w1)
body)) (setq size (difference size 1))) (if (lessp w1 256) (setq body (cons 
w0 (cons w1 (cons (quote JCALLN) body)))) (progn (setq body (cons (quote 
BIGCALL) body)) (setq w2 (logand w1 255)) (setq w1 (truncate w1 256)) (if (
lessp w0 4) (setq body (cons w2 (cons (plus w1 (times 16 w0) 128) body))) (
progn (setq body (cons w0 (cons w2 (cons (plus w1 (plus (times 16 4) 128)) 
body)))) (setq size (plus size 1))))))) (if (car w) (setq body (cons (append 
(car w) (list (quote TAIL))) body))) (rplaca (cdr b) nil) (rplaca (cddr b) (
plus (difference size (cadddr w)) 3)) (rplacd (cddr b) body) (return b)))

(de s!:try_tailcall (b) (prog (var1035 var1036) (setq var1035 b) lab1034 (if 
(null var1035) (return (reversip var1036))) (prog (v) (setq v (car var1035)) 
(setq var1036 (cons (s!:try_tail_1 v b) var1036))) (setq var1035 (cdr var1035
)) (go lab1034)))

(de s!:tidy_exits_1 (b blocks) (prog (exit size body comm w w0 w1 w2 op) (
setq exit (cadr b)) (if (null exit) (return b) (if (not (equal (car exit) (
quote EXIT))) (progn (if (equal (car exit) (quote JUMP)) (progn (if (not (
s!:is_lose_and_exit (atsoc (cadr exit) blocks) blocks)) (return b))) (return 
b))))) (setq size (caddr b)) (setq body (cdddr b)) (setq body (s!:remlose 
body)) (setq size (difference size (car body))) (setq body (cdr body)) (prog 
nil lab1037 (if (null (and body (not (atom (car body))))) (return nil)) (
progn (setq comm (car body)) (setq body (cdr body))) (go lab1037)) (if (eqcar
body (quote VNIL)) (setq w (quote NILEXIT)) (if (eqcar body (quote LOADLOC0)
) (setq w (quote LOC0EXIT)) (if (eqcar body (quote LOADLOC1)) (setq w (quote 
LOC1EXIT)) (if (eqcar body (quote LOADLOC2)) (setq w (quote LOC2EXIT)) (setq 
w nil))))) (if w (progn (rplaca (cdr b) (list w)) (setq body (cdr body)) (
setq size (difference size 1))) (if comm (setq body (cons comm body)))) (
rplaca (cddr b) size) (rplacd (cddr b) body) (return b)))

(de s!:tidy_exits (b) (prog (var1039 var1040) (setq var1039 b) lab1038 (if (
null var1039) (return (reversip var1040))) (prog (v) (setq v (car var1039)) (
setq var1040 (cons (s!:tidy_exits_1 v b) var1040))) (setq var1039 (cdr 
var1039)) (go lab1038)))

(de s!:tidy_flowgraph (b) (prog (r pending) (setq b (reverse b)) (setq 
pending (list (car b))) (prog nil lab1042 (if (null pending) (return nil)) (
prog (c x l1 l2 done1 done2) (setq c (car pending)) (setq pending (cdr 
pending)) (flag (list (car c)) (quote coded)) (setq x (cadr c)) (if (or (null
x) (null (cdr x))) (setq r (cons c r)) (if (equal (car x) (quote ICASE)) (
progn (rplacd x (reversip (cdr x))) (prog (ll) (setq ll (cdr x)) lab1041 (if 
(null ll) (return nil)) (progn (setq l1 (s!:destination_label (car ll) b)) (
if (not (atom l1)) (progn (setq l1 (s!:invent_exit (car l1) b)) (setq b (cdr 
l1)) (setq l1 (cadr l1)))) (rplaca ll l1) (setq done1 (flagp l1 (quote coded)
)) (flag (list l1) (quote used_label)) (if (not done1) (setq pending (
s!:add_pending l1 pending b)))) (setq ll (cdr ll)) (go lab1041)) (rplacd x (
reversip (cdr x))) (setq r (cons c r))) (if (null (cddr x)) (progn (setq l1 (
s!:destination_label (cadr x) b)) (if (not (atom l1)) (setq c (cons (car c) (
cons l1 (cddr c)))) (if (flagp l1 (quote coded)) (progn (flag (list l1) (
quote used_label)) (setq c (cons (car c) (cons (list (car x) l1) (cddr c)))))
(progn (setq c (cons (car c) (cons nil (cddr c)))) (setq pending (
s!:add_pending l1 pending b))))) (setq r (cons c r))) (progn (setq l1 (
s!:destination_label (cadr x) b)) (setq l2 (s!:destination_label (caddr x) b)
) (setq done1 (and (atom l1) (flagp l1 (quote coded)))) (setq done2 (and (
atom l2) (flagp l2 (quote coded)))) (if done1 (progn (if done2 (progn (flag (
list l1) (quote used_label)) (rplaca (cdadr c) l1) (setq pending (cons (list 
(gensym) (list (quote JUMP) l2) 0) pending))) (progn (flag (list l1) (quote 
used_label)) (rplaca (cdadr c) l1) (setq pending (s!:add_pending l2 pending b
))))) (progn (if done2 (progn (flag (list l2) (quote used_label)) (rplaca (
cadr c) (s!:negate_jump (car x))) (rplaca (cdadr c) l2) (setq pending (
s!:add_pending l1 pending b))) (progn (if (not (atom l1)) (progn (setq l1 (
s!:invent_exit (car l1) b)) (setq b (cdr l1)) (setq l1 (car l1)))) (flag (
list l1) (quote used_label)) (rplaca (cdadr c) l1) (if (not (flagp l1 (quote 
coded))) (setq pending (s!:add_pending l1 pending b))) (setq pending (
s!:add_pending l2 pending b)))))) (setq r (cons c r))))))) (go lab1042)) (
return (reverse r))))

(deflist (quote ((JUMPNIL JUMPT) (JUMPT JUMPNIL) (JUMPATOM JUMPNATOM) (
JUMPNATOM JUMPATOM) (JUMPEQ JUMPNE) (JUMPNE JUMPEQ) (JUMPEQUAL JUMPNEQUAL) (
JUMPNEQUAL JUMPEQUAL) (JUMPL0NIL JUMPL0T) (JUMPL0T JUMPL0NIL) (JUMPL1NIL 
JUMPL1T) (JUMPL1T JUMPL1NIL) (JUMPL2NIL JUMPL2T) (JUMPL2T JUMPL2NIL) (
JUMPL3NIL JUMPL3T) (JUMPL3T JUMPL3NIL) (JUMPL4NIL JUMPL4T) (JUMPL4T JUMPL4NIL
) (JUMPL0ATOM JUMPL0NATOM) (JUMPL0NATOM JUMPL0ATOM) (JUMPL1ATOM JUMPL1NATOM) 
(JUMPL1NATOM JUMPL1ATOM) (JUMPL2ATOM JUMPL2NATOM) (JUMPL2NATOM JUMPL2ATOM) (
JUMPL3ATOM JUMPL3NATOM) (JUMPL3NATOM JUMPL3ATOM) (JUMPST0NIL JUMPST0T) (
JUMPST0T JUMPST0NIL) (JUMPST1NIL JUMPST1T) (JUMPST1T JUMPST1NIL) (JUMPST2NIL 
JUMPST2T) (JUMPST2T JUMPST2NIL) (JUMPFREE1NIL JUMPFREE1T) (JUMPFREE1T 
JUMPFREE1NIL) (JUMPFREE2NIL JUMPFREE2T) (JUMPFREE2T JUMPFREE2NIL) (
JUMPFREE3NIL JUMPFREE3T) (JUMPFREE3T JUMPFREE3NIL) (JUMPFREE4NIL JUMPFREE4T) 
(JUMPFREE4T JUMPFREE4NIL) (JUMPFREENIL JUMPFREET) (JUMPFREET JUMPFREENIL) (
JUMPLIT1EQ JUMPLIT1NE) (JUMPLIT1NE JUMPLIT1EQ) (JUMPLIT2EQ JUMPLIT2NE) (
JUMPLIT2NE JUMPLIT2EQ) (JUMPLIT3EQ JUMPLIT3NE) (JUMPLIT3NE JUMPLIT3EQ) (
JUMPLIT4EQ JUMPLIT4NE) (JUMPLIT4NE JUMPLIT4EQ) (JUMPLITEQ JUMPLITNE) (
JUMPLITNE JUMPLITEQ) (JUMPLITEQ!* JUMPLITNE!*) (JUMPLITNE!* JUMPLITEQ!*) (
JUMPB1NIL JUMPB1T) (JUMPB1T JUMPB1NIL) (JUMPB2NIL JUMPB2T) (JUMPB2T JUMPB2NIL
) (JUMPFLAGP JUMPNFLAGP) (JUMPNFLAGP JUMPFLAGP) (JUMPEQCAR JUMPNEQCAR) (
JUMPNEQCAR JUMPEQCAR))) (quote negjump))

(de s!:negate_jump (x) (if (atom x) (get x (quote negjump)) (rplaca x (get (
car x) (quote negjump)))))

(de s!:resolve_labels nil (prog (w labelvals converged pc x) (prog nil 
lab1045 (progn (setq converged t) (setq pc 0) (prog (var1044) (setq var1044 
s!:current_procedure) lab1043 (if (null var1044) (return nil)) (prog (b) (
setq b (car var1044)) (progn (setq w (assoc!*!* (car b) labelvals)) (if (null
w) (progn (setq converged nil) (setq w (cons (car b) pc)) (setq labelvals (
cons w labelvals))) (if (neq (cdr w) pc) (progn (rplacd w pc) (setq converged
nil)))) (setq pc (plus pc (caddr b))) (setq x (cadr b)) (if (null x) nil (if
(null (cdr x)) (setq pc (plus pc 1)) (if (equal (car x) (quote ICASE)) (setq
pc (plus pc (times 2 (length x)))) (progn (setq w (assoc!*!* (cadr x) 
labelvals)) (if (null w) (progn (setq w 128) (setq converged nil)) (setq w (
difference (cdr w) pc))) (setq w (s!:expand_jump (car x) w)) (setq pc (plus 
pc (length w))))))))) (setq var1044 (cdr var1044)) (go lab1043))) (if (null 
converged) (go lab1045))) (return (cons pc labelvals))))

(de s!:plant_basic_block (vec pc b) (prog (tagged) (prog (var1049) (setq 
var1049 b) lab1048 (if (null var1049) (return nil)) (prog (i) (setq i (car 
var1049)) (progn (if (atom i) (progn (if (symbolp i) (setq i (get i (quote 
s!:opcode)))) (if (and (not tagged) (or !*plap !*pgwd)) (progn (s!:prinhex4 
pc) (princ ":") (ttab 8) (setq tagged t))) (if (or (not (fixp i)) (lessp i 0)
(greaterp i 255)) (error "bad byte to put" i)) (bps!-putv vec pc i) (if (or 
!*plap !*pgwd) (progn (s!:prinhex2 i) (princ " "))) (setq pc (plus pc 1))) (
if (or !*plap !*pgwd) (progn (ttab 23) (princ (car i)) (prog (var1047) (setq 
var1047 (cdr i)) lab1046 (if (null var1047) (return nil)) (prog (w) (setq w (
car var1047)) (progn (princ " ") (prin w))) (setq var1047 (cdr var1047)) (go 
lab1046)) (terpri) (setq tagged nil)))))) (setq var1049 (cdr var1049)) (go 
lab1048)) (return pc)))

(de s!:plant_bytes (vec pc bytelist doc) (prog nil (if (or !*plap !*pgwd) (
progn (s!:prinhex4 pc) (princ ":") (ttab 8))) (prog (var1051) (setq var1051 
bytelist) lab1050 (if (null var1051) (return nil)) (prog (v) (setq v (car 
var1051)) (progn (if (symbolp v) (setq v (get v (quote s!:opcode)))) (if (or 
(not (fixp v)) (lessp v 0) (greaterp v 255)) (error "bad byte to put" v)) (
bps!-putv vec pc v) (if (or !*plap !*pgwd) (progn (if (greaterp (posn) 50) (
progn (terpri) (ttab 8))) (s!:prinhex2 v) (princ " "))) (setq pc (plus pc 1))
)) (setq var1051 (cdr var1051)) (go lab1050)) (if (or !*plap !*pgwd) (progn (
if (greaterp (posn) 23) (terpri)) (ttab 23) (princ (car doc)) (prog (var1053)
(setq var1053 (cdr doc)) lab1052 (if (null var1053) (return nil)) (prog (w) 
(setq w (car var1053)) (progn (if (greaterp (posn) 65) (progn (terpri) (ttab 
23))) (princ " ") (prin w))) (setq var1053 (cdr var1053)) (go lab1052)) (
terpri))) (return pc)))

(de s!:plant_exit_code (vec pc b labelvals) (prog (w loc low high r) (if (
null b) (return pc) (if (null (cdr b)) (return (s!:plant_bytes vec pc (list (
get (car b) (quote s!:opcode))) b)) (if (equal (car b) (quote ICASE)) (progn 
(setq loc (plus pc 3)) (prog (var1055) (setq var1055 (cdr b)) lab1054 (if (
null var1055) (return nil)) (prog (ll) (setq ll (car var1055)) (progn (setq w
(difference (cdr (assoc!*!* ll labelvals)) loc)) (setq loc (plus loc 2)) (if
(lessp w 0) (progn (setq w (minus w)) (setq low (ilogand w 255)) (setq high 
(plus 128 (truncate (difference w low) 256)))) (progn (setq low (ilogand w 
255)) (setq high (truncate (difference w low) 256)))) (setq r (cons low (cons
high r))))) (setq var1055 (cdr var1055)) (go lab1054)) (setq r (cons (get (
quote ICASE) (quote s!:opcode)) (cons (length (cddr b)) (reversip r)))) (
return (s!:plant_bytes vec pc r b)))))) (setq w (difference (cdr (assoc!*!* (
cadr b) labelvals)) pc)) (setq w (s!:expand_jump (car b) w)) (return (
s!:plant_bytes vec pc w b))))

(deflist (quote ((JUMPL0NIL ((LOADLOC0) JUMPNIL)) (JUMPL0T ((LOADLOC0) JUMPT)
) (JUMPL1NIL ((LOADLOC1) JUMPNIL)) (JUMPL1T ((LOADLOC1) JUMPT)) (JUMPL2NIL ((
LOADLOC2) JUMPNIL)) (JUMPL2T ((LOADLOC2) JUMPT)) (JUMPL3NIL ((LOADLOC3) 
JUMPNIL)) (JUMPL3T ((LOADLOC3) JUMPT)) (JUMPL4NIL ((LOADLOC4) JUMPNIL)) (
JUMPL4T ((LOADLOC4) JUMPT)) (JUMPL0ATOM ((LOADLOC0) JUMPATOM)) (JUMPL0NATOM (
(LOADLOC0) JUMPNATOM)) (JUMPL1ATOM ((LOADLOC1) JUMPATOM)) (JUMPL1NATOM ((
LOADLOC1) JUMPNATOM)) (JUMPL2ATOM ((LOADLOC2) JUMPATOM)) (JUMPL2NATOM ((
LOADLOC2) JUMPNATOM)) (JUMPL3ATOM ((LOADLOC3) JUMPATOM)) (JUMPL3NATOM ((
LOADLOC3) JUMPNATOM)) (JUMPST0NIL ((STORELOC0) JUMPNIL)) (JUMPST0T ((
STORELOC0) JUMPT)) (JUMPST1NIL ((STORELOC1) JUMPNIL)) (JUMPST1T ((STORELOC1) 
JUMPT)) (JUMPST2NIL ((STORELOC2) JUMPNIL)) (JUMPST2T ((STORELOC2) JUMPT)) (
JUMPFREE1NIL ((LOADFREE1) JUMPNIL)) (JUMPFREE1T ((LOADFREE1) JUMPT)) (
JUMPFREE2NIL ((LOADFREE2) JUMPNIL)) (JUMPFREE2T ((LOADFREE2) JUMPT)) (
JUMPFREE3NIL ((LOADFREE3) JUMPNIL)) (JUMPFREE3T ((LOADFREE3) JUMPT)) (
JUMPFREE4NIL ((LOADFREE4) JUMPNIL)) (JUMPFREE4T ((LOADFREE4) JUMPT)) (
JUMPFREENIL ((LOADFREE !*) JUMPNIL)) (JUMPFREET ((LOADFREE !*) JUMPT)) (
JUMPLIT1EQ ((LOADLIT1) JUMPEQ)) (JUMPLIT1NE ((LOADLIT1) JUMPNE)) (JUMPLIT2EQ 
((LOADLIT2) JUMPEQ)) (JUMPLIT2NE ((LOADLIT2) JUMPNE)) (JUMPLIT3EQ ((LOADLIT3)
JUMPEQ)) (JUMPLIT3NE ((LOADLIT3) JUMPNE)) (JUMPLIT4EQ ((LOADLIT4) JUMPEQ)) (
JUMPLIT4NE ((LOADLIT4) JUMPNE)) (JUMPLITEQ ((LOADLIT !*) JUMPEQ)) (JUMPLITNE 
((LOADLIT !*) JUMPNE)) (JUMPLITEQ!* ((LOADLIT !* SWOP) JUMPEQ)) (JUMPLITNE!* 
((LOADLIT !* SWOP) JUMPNE)) (JUMPB1NIL ((BUILTIN1 !*) JUMPNIL)) (JUMPB1T ((
BUILTIN1 !*) JUMPT)) (JUMPB2NIL ((BUILTIN2 !*) JUMPNIL)) (JUMPB2T ((BUILTIN2 
!*) JUMPT)) (JUMPFLAGP ((LOADLIT !* FLAGP) JUMPT)) (JUMPNFLAGP ((LOADLIT !* 
FLAGP) JUMPNIL)) (JUMPEQCAR ((LOADLIT !* EQCAR) JUMPT)) (JUMPNEQCAR ((LOADLIT
!* EQCAR) JUMPNIL)))) (quote s!:expand_jump))

(fluid (quote (s!:backwards_jump s!:longer_jump)))

(progn (setq s!:backwards_jump (make!-simple!-string 256)) (setq 
s!:longer_jump (make!-simple!-string 256)) nil)

(prog (var1057) (setq var1057 (quote ((JUMP JUMP_B JUMP_L JUMP_BL) (JUMPNIL 
JUMPNIL_B JUMPNIL_L JUMPNIL_BL) (JUMPT JUMPT_B JUMPT_L JUMPT_BL) (JUMPATOM 
JUMPATOM_B JUMPATOM_L JUMPATOM_BL) (JUMPNATOM JUMPNATOM_B JUMPNATOM_L 
JUMPNATOM_BL) (JUMPEQ JUMPEQ_B JUMPEQ_L JUMPEQ_BL) (JUMPNE JUMPNE_B JUMPNE_L 
JUMPNE_BL) (JUMPEQUAL JUMPEQUAL_B JUMPEQUAL_L JUMPEQUAL_BL) (JUMPNEQUAL 
JUMPNEQUAL_B JUMPNEQUAL_L JUMPNEQUAL_BL) (CATCH CATCH_B CATCH_L CATCH_BL)))) 
lab1056 (if (null var1057) (return nil)) (prog (op) (setq op (car var1057)) (
progn (putv!-char s!:backwards_jump (get (car op) (quote s!:opcode)) (get (
cadr op) (quote s!:opcode))) (putv!-char s!:backwards_jump (get (caddr op) (
quote s!:opcode)) (get (cadddr op) (quote s!:opcode))) (putv!-char 
s!:longer_jump (get (car op) (quote s!:opcode)) (get (caddr op) (quote 
s!:opcode))) (putv!-char s!:longer_jump (get (cadr op) (quote s!:opcode)) (
get (cadddr op) (quote s!:opcode))))) (setq var1057 (cdr var1057)) (go 
lab1056))

(de s!:expand_jump (op offset) (prog (arg low high opcode expanded) (if (not 
(atom op)) (progn (setq arg (cadr op)) (setq op (car op)) (setq offset (
difference offset 1)))) (setq expanded (get op (quote s!:expand_jump))) (if (
and expanded (not (and (leq 2 offset) (lessp offset (plus 256 2)) (or (null 
arg) (lessp arg 256))))) (progn (setq op (cadr expanded)) (setq expanded (car
expanded)) (if arg (progn (if (greaterp arg 2047) (error 
"function uses too many literals (2048 limit)") (if (greaterp arg 255) (prog 
(high low) (setq low (ilogand expanded 255)) (setq high (truncate (difference
expanded low) 256)) (setq expanded (plus (cons (quote BIGCALL) (get (car 
expanded) (quote s!:longform))) (cons high (cons low (cddr expanded)))))) (
setq expanded (subst arg (quote !*) expanded)))) (setq offset (plus offset 1)
))) (setq offset (difference offset (length expanded))) (setq arg nil)) (setq
expanded nil)) (setq opcode (get op (quote s!:opcode))) (if (null opcode) (
error 0 (list op offset "invalid block exit"))) (if (and (lessp (plus (minus 
256) 2) offset) (lessp offset (plus 256 2))) (setq offset (difference offset 
2)) (progn (setq high t) (setq offset (difference offset 3)))) (if (lessp 
offset 0) (progn (setq opcode (byte!-getv s!:backwards_jump opcode)) (setq 
offset (minus offset)))) (if high (progn (setq low (logand offset 255)) (setq
high (truncate (difference offset low) 256))) (if (greaterp (setq low offset
) 255) (error 0 "Bad offset in expand_jump"))) (if arg (return (list opcode 
arg low)) (if (not high) (return (append expanded (list opcode low))) (return
(append expanded (list (byte!-getv s!:longer_jump opcode) high low)))))))

(de s!:comval (x env context) (prog (helper) (setq x (s!:improve x)) (if (
atom x) (return (s!:comatom x env context)) (if (eqcar (car x) (quote lambda)
) (return (s!:comlambda (cadar x) (cddar x) (cdr x) env context)) (if (eq (
car x) s!:current_function) (s!:comcall x env context) (if (and (setq helper 
(get (car x) (quote s!:compilermacro))) (setq helper (funcall helper x env 
context))) (return (s!:comval helper env context)) (if (setq helper (get (car
x) (quote s!:newname))) (return (s!:comval (cons helper (cdr x)) env context
)) (if (setq helper (get (car x) (quote s!:compfn))) (return (funcall helper 
x env context)) (if (setq helper (macro!-function (car x))) (return (
s!:comval (funcall helper x) env context)) (return (s!:comcall x env context)
))))))))))

(de s!:comspecform (x env context) (error 0 (list "special form" x)))

(if (null (get (quote and) (quote s!:compfn))) (progn (put (quote 
compiler!-let) (quote s!:compfn) (function s!:comspecform)) (put (quote de) (
quote s!:compfn) (function s!:comspecform)) (put (quote defun) (quote 
s!:compfn) (function s!:comspecform)) (put (quote eval!-when) (quote 
s!:compfn) (function s!:comspecform)) (put (quote flet) (quote s!:compfn) (
function s!:comspecform)) (put (quote labels) (quote s!:compfn) (function 
s!:comspecform)) (put (quote macrolet) (quote s!:compfn) (function 
s!:comspecform)) (put (quote multiple!-value!-call) (quote s!:compfn) (
function s!:comspecform)) (put (quote multiple!-value!-prog1) (quote 
s!:compfn) (function s!:comspecform)) (put (quote prog!*) (quote s!:compfn) (
function s!:comspecform)) (put (quote progv) (quote s!:compfn) (function 
s!:comspecform)) nil))

(de s!:improve (u) (prog (w) (if (atom u) (return u) (if (setq w (get (car u)
(quote s!:tidy_fn))) (return (funcall w u)) (if (setq w (get (car u) (quote 
s!:newname))) (return (s!:improve (cons w (cdr u)))) (return u))))))

(de s!:imp_minus (u) (prog (a) (setq a (s!:improve (cadr u))) (return (if (
numberp a) (minus a) (if (or (eqcar a (quote minus)) (eqcar a (quote iminus))
) (cadr a) (if (eqcar a (quote difference)) (s!:improve (list (quote 
difference) (caddr a) (cadr a))) (if (eqcar a (quote idifference)) (
s!:improve (list (quote idifference) (caddr a) (cadr a))) (list (car u) a))))
))))

(put (quote minus) (quote s!:tidy_fn) (quote s!:imp_minus))

(put (quote iminus) (quote s!:tidy_fn) (quote s!:imp_minus))

(de s!:imp_times (u) (prog (a b) (if (not (equal (length u) 3)) (return (cons
(car u) (prog (var1059 var1060) (setq var1059 (cdr u)) lab1058 (if (null 
var1059) (return (reversip var1060))) (prog (v) (setq v (car var1059)) (setq 
var1060 (cons (s!:improve v) var1060))) (setq var1059 (cdr var1059)) (go 
lab1058))))) (setq a (s!:improve (cadr u))) (setq b (s!:improve (caddr u))) (
return (if (equal a 1) b (if (equal b 1) a (if (equal a (minus 1)) (
s!:imp_minus (list (quote minus) b)) (if (equal b (minus 1)) (s!:imp_minus (
list (quote minus) a)) (list (car u) a b))))))))

(put (quote times) (quote s!:tidy_fn) (quote s!:imp_times))

(de s!:imp_itimes (u) (prog (a b) (if (not (equal (length u) 3)) (return (
cons (car u) (prog (var1062 var1063) (setq var1062 (cdr u)) lab1061 (if (null
var1062) (return (reversip var1063))) (prog (v) (setq v (car var1062)) (setq
var1063 (cons (s!:improve v) var1063))) (setq var1062 (cdr var1062)) (go 
lab1061))))) (setq a (s!:improve (cadr u))) (setq b (s!:improve (caddr u))) (
return (if (equal a 1) b (if (equal b 1) a (if (equal a (minus 1)) (
s!:imp_minus (list (quote iminus) b)) (if (equal b (minus 1)) (s!:imp_minus (
list (quote iminus) a)) (list (car u) a b))))))))

(put (quote itimes) (quote s!:tidy_fn) (quote s!:imp_itimes))

(de s!:imp_difference (u) (prog (a b) (setq a (s!:improve (cadr u))) (setq b 
(s!:improve (caddr u))) (return (if (equal a 0) (s!:imp_minus (list (quote 
minus) b)) (if (equal b 0) a (list (car u) a b))))))

(put (quote difference) (quote s!:tidy_fn) (quote s!:imp_difference))

(de s!:imp_idifference (u) (prog (a b) (setq a (s!:improve (cadr u))) (setq b
(s!:improve (caddr u))) (return (if (equal a 0) (s!:imp_minus (list (quote 
iminus) b)) (if (equal b 0) a (list (car u) a b))))))

(put (quote idifference) (quote s!:tidy_fn) (quote s!:imp_idifference))

(de s!:alwayseasy (x) t)

(put (quote quote) (quote s!:helpeasy) (function s!:alwayseasy))

(put (quote function) (quote s!:helpeasy) (function s!:alwayseasy))

(de s!:easyifarg (x) (or (null (cdr x)) (and (null (cddr x)) (s!:iseasy (cadr
x)))))

(put (quote ncons) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote car) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote cdr) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote caar) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote cadr) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote cdar) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote cddr) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote caaar) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote caadr) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote cadar) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote caddr) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote cdaar) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote cdadr) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote cddar) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote cdddr) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote caaaar) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote caaadr) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote caadar) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote caaddr) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote cadaar) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote cadadr) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote caddar) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote cadddr) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote cdaaar) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote cdaadr) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote cdadar) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote cdaddr) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote cddaar) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote cddadr) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote cdddar) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote cddddr) (quote s!:helpeasy) (function s!:easyifarg))

(de s!:easygetv (x) (prog (a2) (setq a2 (caddr x)) (if (and (null 
!*carcheckflag) (fixp a2) (geq a2 0) (lessp a2 256)) (return (s!:iseasy (cadr
x))) (return nil))))

(put (quote getv) (quote s!:helpeasy) (function s!:easygetv))

(de s!:easyqgetv (x) (prog (a2) (setq a2 (caddr x)) (if (and (fixp a2) (geq 
a2 0) (lessp a2 256)) (return (s!:iseasy (cadr x))) (return nil))))

(put (quote qgetv) (quote s!:helpeasy) (function s!:easyqgetv))

(de s!:iseasy (x) (prog (h) (if (atom x) (return t)) (if (not (atom (car x)))
(return nil)) (if (setq h (get (car x) (quote s!:helpeasy))) (return (
funcall h x)) (return nil))))

(de s!:instate_local_decs (v d w) (prog (fg) (if (fluidp v) (return w)) (prog
(var1065) (setq var1065 d) lab1064 (if (null var1065) (return nil)) (prog (z
) (setq z (car var1065)) (if (and (eqcar z (quote special)) (memq v (cdr z)))
(setq fg t))) (setq var1065 (cdr var1065)) (go lab1064)) (if fg (progn (
make!-special v) (setq w (cons v w)))) (return w)))

(de s!:residual_local_decs (d w) (prog nil (prog (var1069) (setq var1069 d) 
lab1068 (if (null var1069) (return nil)) (prog (z) (setq z (car var1069)) (if
(eqcar z (quote special)) (prog (var1067) (setq var1067 (cdr z)) lab1066 (if
(null var1067) (return nil)) (prog (v) (setq v (car var1067)) (if (and (not 
(fluidp v)) (not (globalp v))) (progn (make!-special v) (setq w (cons v w))))
) (setq var1067 (cdr var1067)) (go lab1066)))) (setq var1069 (cdr var1069)) (
go lab1068)) (return w)))

(de s!:cancel_local_decs (w) (unfluid w))

(de s!:find_local_decs (body) (prog (w local_decs) (prog nil lab1070 (if (
null (and body (or (eqcar (car body) (quote declare)) (stringp (car body)))))
(return nil)) (progn (if (stringp (car body)) (setq w (cons (car body) w)) (
setq local_decs (append local_decs (cdar body)))) (setq body (cdr body))) (go
lab1070)) (prog nil lab1071 (if (null w) (return nil)) (progn (setq body (
cons (car w) body)) (setq w (cdr w))) (go lab1071)) (return (cons local_decs 
body))))

(de s!:comlambda (bvl body args env context) (prog (s nbvl fluids fl1 w 
local_decs) (setq nbvl (setq s (cdr env))) (setq body (s!:find_local_decs 
body)) (setq local_decs (car body)) (setq body (cdr body)) (if (atom body) (
setq body nil) (if (atom (cdr body)) (setq body (car body)) (setq body (cons 
(quote progn) body)))) (setq w nil) (prog (var1073) (setq var1073 bvl) 
lab1072 (if (null var1073) (return nil)) (prog (v) (setq v (car var1073)) (
setq w (s!:instate_local_decs v local_decs w))) (setq var1073 (cdr var1073)) 
(go lab1072)) (prog (var1075) (setq var1075 bvl) lab1074 (if (null var1075) (
return nil)) (prog (v) (setq v (car var1075)) (progn (if (or (fluidp v) (
globalp v)) (prog (g) (setq g (gensym)) (setq nbvl (cons g nbvl)) (setq fl1 (
cons v fl1)) (setq fluids (cons (cons v g) fluids))) (setq nbvl (cons v nbvl)
)) (if (equal (car args) nil) (s!:outstack 1) (progn (s!:comval (car args) 
env 1) (s!:outopcode0 (quote PUSH) (quote (PUSH))))) (rplacd env (cons 0 (cdr
env))) (setq args (cdr args)))) (setq var1075 (cdr var1075)) (go lab1074)) (
rplacd env nbvl) (if fluids (progn (setq fl1 (s!:vecof fl1)) (
s!:outopcode1lit (quote FREEBIND) fl1 env) (prog (var1077) (setq var1077 (
cons nil fluids)) lab1076 (if (null var1077) (return nil)) (prog (v) (setq v 
(car var1077)) (rplacd env (cons 0 (cdr env)))) (setq var1077 (cdr var1077)) 
(go lab1076)) (rplacd env (cons (plus 2 (length fluids)) (cdr env))) (prog (
var1079) (setq var1079 fluids) lab1078 (if (null var1079) (return nil)) (prog
(v) (setq v (car var1079)) (s!:comval (list (quote setq) (car v) (cdr v)) 
env 2)) (setq var1079 (cdr var1079)) (go lab1078)))) (setq w (
s!:residual_local_decs local_decs w)) (s!:comval body env 1) (
s!:cancel_local_decs w) (if fluids (s!:outopcode0 (quote FREERSTR) (quote (
FREERSTR)))) (s!:outlose (length bvl)) (rplacd env s)))

(de s!:loadliteral (x env) (if (member!*!* (list (quote quote) x) 
s!:a_reg_values) nil (progn (if (equal x nil) (s!:outopcode0 (quote VNIL) (
quote (loadlit nil))) (s!:outopcode1lit (quote LOADLIT) x env)) (setq 
s!:a_reg_values (list (list (quote quote) x))))))

(de s!:comquote (x env context) (if (leq context 1) (s!:loadliteral (cadr x) 
env)))

(put (quote quote) (quote s!:compfn) (function s!:comquote))

(fluid (quote (s!:current_exitlab s!:current_proglabels s!:local_macros)))

(de s!:comfunction (x env context) (if (leq context 1) (progn (setq x (cadr x
)) (if (eqcar x (quote lambda)) (prog (g w s!:used_lexicals) (setq 
s!:has_closure t) (setq g (hashtagged!-name (quote lambda) (cdr x))) (setq w 
(s!:compile1 g (cadr x) (cddr x) (cons (list (cdr env) s!:current_exitlab 
s!:current_proglabels s!:local_macros) s!:lexical_env))) (if s!:used_lexicals
(setq w (s!:compile1 g (cons (gensym) (cadr x)) (cddr x) (cons (list (cdr 
env) s!:current_exitlab s!:current_proglabels s!:local_macros) s!:lexical_env
)))) (setq s!:other_defs (append w s!:other_defs)) (s!:loadliteral g env) (
setq w (length (cdr env))) (if s!:used_lexicals (progn (setq s!:has_closure t
) (if (greaterp w 4095) (error "stack frame > 4095") (if (greaterp w 255) (
s!:outopcode2 (quote BIGSTACK) (plus 128 (truncate w 256)) (logand w 255) (
list (quote CLOSURE) w)) (s!:outopcode1 (quote CLOSURE) w x)))))) (
s!:loadliteral x env)))))

(put (quote function) (quote s!:compfn) (function s!:comfunction))

(de s!:should_be_fluid (x) (if (not (or (fluidp x) (globalp x))) (progn (if 
!*pwrds (progn (if (neq (posn) 0) (terpri)) (princ "+++ ") (prin x) (princ 
" declared fluid") (terpri))) (fluid (list x)) nil)))

(de s!:find_lexical (x lex n) (prog (p) (if (null lex) (return nil)) (setq p 
(memq x (caar lex))) (if p (progn (if (not (memq x s!:used_lexicals)) (setq 
s!:used_lexicals (cons x s!:used_lexicals))) (return (list n (length p)))) (
return (s!:find_lexical x (cdr lex) (plus n 1))))))

(global (quote (s!:loadlocs)))

(setq s!:loadlocs (s!:vecof (quote (LOADLOC0 LOADLOC1 LOADLOC2 LOADLOC3 
LOADLOC4 LOADLOC5 LOADLOC6 LOADLOC7 LOADLOC8 LOADLOC9 LOADLOC10 LOADLOC11))))

(de s!:comatom (x env context) (prog (n w) (if (greaterp context 1) (return 
nil) (if (or (null x) (not (symbolp x))) (return (s!:loadliteral x env)))) (
setq n 0) (setq w (cdr env)) (prog nil lab1080 (if (null (and w (not (eqcar w
x)))) (return nil)) (progn (setq n (add1 n)) (setq w (cdr w))) (go lab1080))
(if w (progn (setq w (cons (quote loc) w)) (if (member!*!* w s!:a_reg_values
) (return nil) (progn (if (lessp n 12) (s!:outopcode0 (getv s!:loadlocs n) (
list (quote LOADLOC) x)) (if (greaterp n 4095) (error "stack frame > 4095") (
if (greaterp n 255) (s!:outopcode2 (quote BIGSTACK) (truncate n 256) (logand 
n 255) (list (quote LOADLOC) x)) (s!:outopcode1 (quote LOADLOC) n x)))) (setq
s!:a_reg_values (list w)) (return nil))))) (if (setq w (s!:find_lexical x 
s!:lexical_env 0)) (progn (if (member!*!* (cons (quote lex) w) 
s!:a_reg_values) (return nil)) (s!:outlexref (quote LOADLEX) (length (cdr env
)) (car w) (cadr w) x) (setq s!:a_reg_values (list (cons (quote lex) w))) (
return nil))) (s!:should_be_fluid x) (if (flagp x (quote constant!?)) (return
(s!:loadliteral (eval x) env))) (setq w (cons (quote free) x)) (if (
member!*!* w s!:a_reg_values) (return nil)) (s!:outopcode1lit (quote LOADFREE
) x env) (setq s!:a_reg_values (list w))))

(flag (quote (t !$EOL!$ !$EOF!$)) (quote constant!?))

(de s!:islocal (x env) (prog (n w) (if (or (null x) (not (symbolp x)) (eq x t
)) (return 99999)) (setq n 0) (setq w (cdr env)) (prog nil lab1081 (if (null 
(and w (not (eqcar w x)))) (return nil)) (progn (setq n (add1 n)) (setq w (
cdr w))) (go lab1081)) (if w (return n) (return 99999))))

(de s!:load2 (a b env) (progn (if (s!:iseasy b) (prog (wa wb w) (setq wa (
s!:islocal a env)) (setq wb (s!:islocal b env)) (if (and (lessp wa 4) (lessp 
wb 4)) (progn (if (and (equal wa 0) (equal wb 1)) (setq w (quote LOC0LOC1)) (
if (and (equal wa 1) (equal wb 2)) (setq w (quote LOC1LOC2)) (if (and (equal 
wa 2) (equal wb 3)) (setq w (quote LOC2LOC3)) (if (and (equal wa 1) (equal wb
0)) (setq w (quote LOC1LOC0)) (if (and (equal wa 2) (equal wb 1)) (setq w (
quote LOC2LOC1)) (if (and (equal wa 3) (equal wb 2)) (setq w (quote LOC3LOC2)
))))))) (if w (progn (s!:outopcode0 w (list (quote LOCLOC) a b)) (return nil)
)))) (s!:comval a env 1) (setq s!:a_reg_values nil) (s!:comval b env 1) (
return nil)) (if !*ord (progn (s!:comval a env 1) (s!:outopcode0 (quote PUSH)
(quote (PUSH))) (rplacd env (cons 0 (cdr env))) (setq s!:a_reg_values nil) (
s!:comval b env 1) (s!:outopcode0 (quote POP) (quote (POP))) (rplacd env (
cddr env)) t) (if (s!:iseasy a) (progn (s!:comval b env 1) (setq 
s!:a_reg_values nil) (s!:comval a env 1) t) (progn (s!:comval b env 1) (
s!:outopcode0 (quote PUSH) (quote (PUSH))) (rplacd env (cons 0 (cdr env))) (
setq s!:a_reg_values nil) (s!:comval a env 1) (s!:outopcode0 (quote POP) (
quote (POP))) (rplacd env (cddr env)) nil))))))

(global (quote (s!:carlocs s!:cdrlocs s!:caarlocs)))

(setq s!:carlocs (s!:vecof (quote (CARLOC0 CARLOC1 CARLOC2 CARLOC3 CARLOC4 
CARLOC5 CARLOC6 CARLOC7 CARLOC8 CARLOC9 CARLOC10 CARLOC11))))

(setq s!:cdrlocs (s!:vecof (quote (CDRLOC0 CDRLOC1 CDRLOC2 CDRLOC3 CDRLOC4 
CDRLOC5))))

(setq s!:caarlocs (s!:vecof (quote (CAARLOC0 CAARLOC1 CAARLOC2 CAARLOC3))))

(flag (quote (plus2 times2 eq equal)) (quote s!:symmetric))

(flag (quote (car cdr caar cadr cdar cddr ncons add1 sub1 numberp length)) (
quote s!:onearg))

(flag (quote (cons xcons list2 get flagp plus2 difference times2 greaterp 
lessp apply1 eq equal getv qgetv eqcar)) (quote s!:twoarg))

(flag (quote (apply2 list2!* list3 acons)) (quote s!:threearg))

(de s!:comcall (x env context) (prog (fn args nargs op s w1 w2 w3 sw) (setq 
fn (car x)) (setq args (prog (var1083 var1084) (setq var1083 (cdr x)) lab1082
(if (null var1083) (return (reversip var1084))) (prog (v) (setq v (car 
var1083)) (setq var1084 (cons (s!:improve v) var1084))) (setq var1083 (cdr 
var1083)) (go lab1082))) (setq nargs (length args)) (if (and (greaterp nargs 
15) !*pwrds) (progn (if (neq (posn) 0) (terpri)) (princ "+++ ") (prin fn) (
princ " called with ") (prin nargs) (princ " from function ") (prin 
s!:current_function) (terpri))) (setq s (cdr env)) (if (equal nargs 0) (if (
setq w2 (get fn (quote s!:builtin0))) (s!:outopcode1 (quote BUILTIN0) w2 fn) 
(s!:outopcode1lit (quote CALL0) fn env)) (if (equal nargs 1) (progn (if (and 
(equal fn (quote car)) (lessp (setq w2 (s!:islocal (car args) env)) 12)) (
s!:outopcode0 (getv s!:carlocs w2) (list (quote carloc) (car args))) (if (and
(equal fn (quote cdr)) (lessp (setq w2 (s!:islocal (car args) env)) 6)) (
s!:outopcode0 (getv s!:cdrlocs w2) (list (quote cdrloc) (car args))) (if (and
(equal fn (quote caar)) (lessp (setq w2 (s!:islocal (car args) env)) 4)) (
s!:outopcode0 (getv s!:caarlocs w2) (list (quote caarloc) (car args))) (progn
(s!:comval (car args) env 1) (if (flagp fn (quote s!:onearg)) (s!:outopcode0
fn (list fn)) (if (setq w2 (get fn (quote s!:builtin1))) (s!:outopcode1 (
quote BUILTIN1) w2 fn) (s!:outopcode1lit (quote CALL1) fn env)))))))) (if (
equal nargs 2) (progn (setq sw (s!:load2 (car args) (cadr args) env)) (if (
flagp fn (quote s!:symmetric)) (setq sw nil)) (if (flagp fn (quote s!:twoarg)
) (progn (if sw (s!:outopcode0 (quote SWOP) (quote (SWOP)))) (s!:outopcode0 
fn (list fn))) (progn (setq w3 (get fn (quote s!:builtin2))) (if sw (progn (
if w3 (s!:outopcode1 (quote BUILTIN2R) w3 fn) (s!:outopcode1lit (quote CALL2R
) fn env))) (if w3 (s!:outopcode1 (quote BUILTIN2) w3 fn) (s!:outopcode1lit (
quote CALL2) fn env)))))) (if (equal nargs 3) (progn (if (equal (car args) 
nil) (s!:outstack 1) (progn (s!:comval (car args) env 1) (s!:outopcode0 (
quote PUSH) (quote (PUSHA3))))) (rplacd env (cons 0 (cdr env))) (setq 
s!:a_reg_values nil) (if (s!:load2 (cadr args) (caddr args) env) (
s!:outopcode0 (quote SWOP) (quote (SWOP)))) (if (flagp fn (quote s!:threearg)
) (s!:outopcode0 (if (equal fn (quote list2!*)) (quote list2star) fn) (list 
fn)) (if (setq w2 (get fn (quote s!:builtin3))) (s!:outopcode1 (quote 
BUILTIN3) w2 fn) (s!:outopcode1lit (quote CALL3) fn env))) (rplacd env (cddr 
env))) (prog (largs) (setq largs (reverse args)) (prog (var1086) (setq 
var1086 (reverse (cddr largs))) lab1085 (if (null var1086) (return nil)) (
prog (a) (setq a (car var1086)) (progn (if (null a) (s!:outstack 1) (progn (
s!:comval a env 1) (if (equal nargs 4) (s!:outopcode0 (quote PUSH) (quote (
PUSHA4))) (s!:outopcode0 (quote PUSH) (quote (PUSHARG)))))) (rplacd env (cons
0 (cdr env))) (setq s!:a_reg_values nil))) (setq var1086 (cdr var1086)) (go 
lab1085)) (if (s!:load2 (cadr largs) (car largs) env) (s!:outopcode0 (quote 
SWOP) (quote (SWOP)))) (if (and (equal fn (quote apply3)) (equal nargs 4)) (
s!:outopcode0 (quote APPLY3) (quote (APPLY3))) (if (greaterp nargs 255) (
error "Over 255 args in a function call") (s!:outopcode2lit (quote CALLN) fn 
nargs (list nargs fn) env))) (rplacd env s))))))))

(de s!:ad_name (l) (if (equal (car l) (quote a)) (if (equal (cadr l) (quote a
)) (quote caar) (quote cadr)) (if (equal (cadr l) (quote a)) (quote cdar) (
quote cddr))))

(de s!:comcarcdr3 (x env context) (prog (name outer c1 c2) (setq name (cdr (
explode2 (car x)))) (setq x (list (s!:ad_name name) (list (if (equal (caddr 
name) (quote a)) (quote car) (quote cdr)) (cadr x)))) (return (s!:comval x 
env context))))

(put (quote caaar) (quote s!:compfn) (function s!:comcarcdr3))

(put (quote caadr) (quote s!:compfn) (function s!:comcarcdr3))

(put (quote cadar) (quote s!:compfn) (function s!:comcarcdr3))

(put (quote caddr) (quote s!:compfn) (function s!:comcarcdr3))

(put (quote cdaar) (quote s!:compfn) (function s!:comcarcdr3))

(put (quote cdadr) (quote s!:compfn) (function s!:comcarcdr3))

(put (quote cddar) (quote s!:compfn) (function s!:comcarcdr3))

(put (quote cdddr) (quote s!:compfn) (function s!:comcarcdr3))

(de s!:comcarcdr4 (x env context) (prog (name outer c1 c2) (setq name (cdr (
explode2 (car x)))) (setq x (list (s!:ad_name name) (list (s!:ad_name (cddr 
name)) (cadr x)))) (return (s!:comval x env context))))

(put (quote caaaar) (quote s!:compfn) (function s!:comcarcdr4))

(put (quote caaadr) (quote s!:compfn) (function s!:comcarcdr4))

(put (quote caadar) (quote s!:compfn) (function s!:comcarcdr4))

(put (quote caaddr) (quote s!:compfn) (function s!:comcarcdr4))

(put (quote cadaar) (quote s!:compfn) (function s!:comcarcdr4))

(put (quote cadadr) (quote s!:compfn) (function s!:comcarcdr4))

(put (quote caddar) (quote s!:compfn) (function s!:comcarcdr4))

(put (quote cadddr) (quote s!:compfn) (function s!:comcarcdr4))

(put (quote cdaaar) (quote s!:compfn) (function s!:comcarcdr4))

(put (quote cdaadr) (quote s!:compfn) (function s!:comcarcdr4))

(put (quote cdadar) (quote s!:compfn) (function s!:comcarcdr4))

(put (quote cdaddr) (quote s!:compfn) (function s!:comcarcdr4))

(put (quote cddaar) (quote s!:compfn) (function s!:comcarcdr4))

(put (quote cddadr) (quote s!:compfn) (function s!:comcarcdr4))

(put (quote cdddar) (quote s!:compfn) (function s!:comcarcdr4))

(put (quote cddddr) (quote s!:compfn) (function s!:comcarcdr4))

(de s!:comgetv (x env context) (if !*carcheckflag (s!:comcall x env context) 
(s!:comval (cons (quote qgetv) (cdr x)) env context)))

(put (quote getv) (quote s!:compfn) (function s!:comgetv))

(de s!:comqgetv (x env context) (if (and (fixp (caddr x)) (geq (caddr x) 0) (
lessp (caddr x) 256)) (progn (s!:comval (cadr x) env 1) (s!:outopcode1 (quote
QGETVN) (caddr x) (caddr x))) (s!:comcall x env context)))

(put (quote qgetv) (quote s!:compfn) (function s!:comqgetv))

(de s!:comget (x env context) (prog (a b c w) (setq a (cadr x)) (setq b (
caddr x)) (setq c (cdddr x)) (if (eqcar b (quote quote)) (progn (setq b (cadr
b)) (setq w (symbol!-make!-fastget b nil)) (if c (progn (if w (progn (if (
s!:load2 a b env) (s!:outopcode0 (quote SWOP) (quote (SWOP)))) (s!:outopcode1
(quote FASTGET) (logor w 64) b)) (s!:comcall x env context))) (progn (
s!:comval a env 1) (if w (s!:outopcode1 (quote FASTGET) w b) (
s!:outopcode1lit (quote LITGET) b env))))) (s!:comcall x env context))))

(put (quote get) (quote s!:compfn) (function s!:comget))

(de s!:comflagp (x env context) (prog (a b) (setq a (cadr x)) (setq b (caddr 
x)) (if (eqcar b (quote quote)) (progn (setq b (cadr b)) (s!:comval a env 1) 
(setq a (symbol!-make!-fastget b nil)) (if a (s!:outopcode1 (quote FASTGET) (
logor a 128) b) (s!:comcall x env context))) (s!:comcall x env context))))

(put (quote flagp) (quote s!:compfn) (function s!:comflagp))

(de s!:complus (x env context) (s!:comval (expand (cdr x) (quote plus2)) env 
context))

(put (quote plus) (quote s!:compfn) (function s!:complus))

(de s!:comtimes (x env context) (s!:comval (expand (cdr x) (quote times2)) 
env context))

(put (quote times) (quote s!:compfn) (function s!:comtimes))

(de s!:comiplus (x env context) (s!:comval (expand (cdr x) (quote iplus2)) 
env context))

(put (quote iplus) (quote s!:compfn) (function s!:comiplus))

(de s!:comitimes (x env context) (s!:comval (expand (cdr x) (quote itimes2)) 
env context))

(put (quote itimes) (quote s!:compfn) (function s!:comitimes))

(de s!:complus2 (x env context) (prog (a b) (setq a (s!:improve (cadr x))) (
setq b (s!:improve (caddr x))) (return (if (and (numberp a) (numberp b)) (
s!:comval (plus a b) env context) (if (equal a 0) (s!:comval b env context) (
if (equal a 1) (s!:comval (list (quote add1) b) env context) (if (equal b 0) 
(s!:comval a env context) (if (equal b 1) (s!:comval (list (quote add1) a) 
env context) (if (equal b (minus 1)) (s!:comval (list (quote sub1) a) env 
context) (s!:comcall x env context))))))))))

(put (quote plus2) (quote s!:compfn) (function s!:complus2))

(de s!:comdifference (x env context) (prog (a b) (setq a (s!:improve (cadr x)
)) (setq b (s!:improve (caddr x))) (return (if (and (numberp a) (numberp b)) 
(s!:comval (difference a b) env context) (if (equal a 0) (s!:comval (list (
quote minus) b) env context) (if (equal b 0) (s!:comval a env context) (if (
equal b 1) (s!:comval (list (quote sub1) a) env context) (if (equal b (minus 
1)) (s!:comval (list (quote add1) a) env context) (s!:comcall x env context))
)))))))

(put (quote difference) (quote s!:compfn) (function s!:comdifference))

(de s!:comiplus2 (x env context) (prog (a b) (setq a (s!:improve (cadr x))) (
setq b (s!:improve (caddr x))) (return (if (and (numberp a) (numberp b)) (
s!:comval (plus a b) env context) (if (equal a 1) (s!:comval (list (quote 
iadd1) b) env context) (if (equal b 1) (s!:comval (list (quote iadd1) a) env 
context) (if (equal b (minus 1)) (s!:comval (list (quote isub1) a) env 
context) (s!:comcall x env context))))))))

(put (quote iplus2) (quote s!:compfn) (function s!:comiplus2))

(de s!:comidifference (x env context) (prog (a b) (setq a (s!:improve (cadr x
))) (setq b (s!:improve (caddr x))) (return (if (and (numberp a) (numberp b))
(s!:comval (difference a b) env context) (if (equal b 1) (s!:comval (list (
quote isub1) a) env context) (if (equal b (minus 1)) (s!:comval (list (quote 
iadd1) a) env context) (s!:comcall x env context)))))))

(put (quote idifference) (quote s!:compfn) (function s!:comidifference))

(de s!:comtimes2 (x env context) (prog (a b) (setq a (s!:improve (cadr x))) (
setq b (s!:improve (caddr x))) (return (if (and (numberp a) (numberp b)) (
s!:comval (times a b) env context) (if (equal a 1) (s!:comval b env context) 
(if (equal a (minus 1)) (s!:comval (list (quote minus) b) env context) (if (
equal b 1) (s!:comval a env context) (if (equal b (minus 1)) (s!:comval (list
(quote minus) a) env context) (s!:comcall x env context)))))))))

(put (quote times2) (quote s!:compfn) (function s!:comtimes2))

(put (quote itimes2) (quote s!:compfn) (function s!:comtimes2))

(de s!:comminus (x env context) (prog (a b) (setq a (s!:improve (cadr x))) (
return (if (numberp a) (s!:comval (minus a) env context) (if (eqcar a (quote 
minus)) (s!:comval (cadr a) env context) (s!:comcall x env context))))))

(put (quote minus) (quote s!:compfn) (function s!:comminus))

(de s!:comminusp (x env context) (prog (a) (setq a (s!:improve (cadr x))) (if
(eqcar a (quote difference)) (return (s!:comval (cons (quote lessp) (cdr a))
env context)) (return (s!:comcall x env context)))))

(put (quote minusp) (quote s!:compfn) (function s!:comminusp))

(de s!:comlessp (x env context) (prog (a b) (setq a (s!:improve (cadr x))) (
setq b (s!:improve (caddr x))) (if (equal b 0) (return (s!:comval (list (
quote minusp) a) env context)) (return (s!:comcall x env context)))))

(put (quote lessp) (quote s!:compfn) (function s!:comlessp))

(de s!:comiminusp (x env context) (prog (a) (setq a (s!:improve (cadr x))) (
if (eqcar a (quote difference)) (return (s!:comval (cons (quote ilessp) (cdr 
a)) env context)) (return (s!:comcall x env context)))))

(put (quote iminusp) (quote s!:compfn) (function s!:comiminusp))

(de s!:comilessp (x env context) (prog (a b) (setq a (s!:improve (cadr x))) (
setq b (s!:improve (caddr x))) (if (equal b 0) (return (s!:comval (list (
quote iminusp) a) env context)) (return (s!:comcall x env context)))))

(put (quote ilessp) (quote s!:compfn) (function s!:comilessp))

(de s!:comprogn (x env context) (progn (setq x (cdr x)) (if (null x) (
s!:comval nil env context) (prog (a) (setq a (car x)) (prog nil lab1087 (if (
null (setq x (cdr x))) (return nil)) (progn (s!:comval a env (if (geq context
4) context 2)) (setq a (car x))) (go lab1087)) (s!:comval a env context)))))

(put (quote progn) (quote s!:compfn) (function s!:comprogn))

(de s!:comprog1 (x env context) (prog nil (setq x (cdr x)) (if (null x) (
return (s!:comval nil env context))) (s!:comval (car x) env context) (if (
null (setq x (cdr x))) (return nil)) (s!:outopcode0 (quote PUSH) (quote (PUSH
))) (rplacd env (cons 0 (cdr env))) (prog (var1089) (setq var1089 x) lab1088 
(if (null var1089) (return nil)) (prog (a) (setq a (car var1089)) (s!:comval 
a env (if (geq context 4) context 2))) (setq var1089 (cdr var1089)) (go 
lab1088)) (s!:outopcode0 (quote POP) (quote (POP))) (rplacd env (cddr env))))

(put (quote prog1) (quote s!:compfn) (function s!:comprog1))

(de s!:comprog2 (x env context) (prog (a) (setq x (cdr x)) (if (null x) (
return (s!:comval nil env context))) (setq a (car x)) (s!:comval a env (if (
geq context 4) context 2)) (s!:comprog1 x env context)))

(put (quote prog2) (quote s!:compfn) (function s!:comprog2))

(de s!:outstack (n) (prog (w a) (setq w s!:current_block) (prog nil lab1090 (
if (null (and w (not (atom (car w))))) (return nil)) (setq w (cdr w)) (go 
lab1090)) (if (eqcar w (quote PUSHNIL)) (setq a 1) (if (eqcar w (quote 
PUSHNIL2)) (setq a 2) (if (eqcar w (quote PUSHNIL3)) (setq a 3) (if (and w (
numberp (setq a (car w))) (not (equal a 255)) (eqcar (cdr w) (quote PUSHNILS)
)) (progn (setq w (cdr w)) (setq s!:current_size (difference s!:current_size 
1))) (setq a nil))))) (if a (progn (setq s!:current_block (cdr w)) (setq 
s!:current_size (difference s!:current_size 1)) (setq n (plus n a)))) (if (
equal n 1) (s!:outopcode0 (quote PUSHNIL) (quote (PUSHNIL))) (if (equal n 2) 
(s!:outopcode0 (quote PUSHNIL2) (quote (PUSHNIL2))) (if (equal n 3) (
s!:outopcode0 (quote PUSHNIL3) (quote (PUSHNIL3))) (if (greaterp n 255) (
progn (s!:outopcode1 (quote PUSHNILS) 255 255) (s!:outstack (difference n 255
))) (if (greaterp n 3) (s!:outopcode1 (quote PUSHNILS) n n))))))))

(de s!:outlose (n) (prog (w a) (setq w s!:current_block) (prog nil lab1091 (
if (null (and w (not (atom (car w))))) (return nil)) (setq w (cdr w)) (go 
lab1091)) (if (eqcar w (quote LOSE)) (setq a 1) (if (eqcar w (quote LOSE2)) (
setq a 2) (if (eqcar w (quote LOSE3)) (setq a 3) (if (and w (numberp (setq a 
(car w))) (not (equal a 255)) (eqcar (cdr w) (quote LOSES))) (progn (setq w (
cdr w)) (setq s!:current_size (difference s!:current_size 1))) (setq a nil)))
)) (if a (progn (setq s!:current_block (cdr w)) (setq s!:current_size (
difference s!:current_size 1)) (setq n (plus n a)))) (if (equal n 1) (
s!:outopcode0 (quote LOSE) (quote (LOSE))) (if (equal n 2) (s!:outopcode0 (
quote LOSE2) (quote (LOSE2))) (if (equal n 3) (s!:outopcode0 (quote LOSE3) (
quote (LOSE3))) (if (greaterp n 255) (progn (s!:outopcode1 (quote LOSES) 255 
255) (s!:outlose (difference n 255))) (if (greaterp n 3) (s!:outopcode1 (
quote LOSES) n n))))))))

(de s!:comprog (x env context) (prog (labs s bvl fluids n body local_decs w) 
(setq body (s!:find_local_decs (cddr x))) (setq local_decs (car body)) (setq 
body (cdr body)) (setq n 0) (prog (var1093) (setq var1093 (cadr x)) lab1092 (
if (null var1093) (return nil)) (prog (v) (setq v (car var1093)) (setq w (
s!:instate_local_decs v local_decs w))) (setq var1093 (cdr var1093)) (go 
lab1092)) (prog (var1095) (setq var1095 (cadr x)) lab1094 (if (null var1095) 
(return nil)) (prog (v) (setq v (car var1095)) (progn (if (globalp v) (progn 
(if !*pwrds (progn (if (neq (posn) 0) (terpri)) (princ "+++++ global ") (prin
v) (princ " converted to fluid") (terpri))) (unglobal (list v)) (fluid (list
v)))) (if (fluidp v) (setq fluids (cons v fluids)) (progn (setq n (plus n 1)
) (setq bvl (cons v bvl)))))) (setq var1095 (cdr var1095)) (go lab1094)) (
setq s (cdr env)) (setq s!:current_exitlab (cons (cons nil (cons (gensym) s))
s!:current_exitlab)) (s!:outstack n) (rplacd env (append bvl (cdr env))) (if
fluids (prog (fl1) (setq fl1 (s!:vecof fluids)) (s!:outopcode1lit (quote 
FREEBIND) fl1 env) (prog (var1097) (setq var1097 (cons nil fluids)) lab1096 (
if (null var1097) (return nil)) (prog (v) (setq v (car var1097)) (rplacd env 
(cons 0 (cdr env)))) (setq var1097 (cdr var1097)) (go lab1096)) (rplacd env (
cons (plus 2 (length fluids)) (cdr env))) (if (equal context 0) (setq context
1)))) (prog (var1099) (setq var1099 (cddr x)) lab1098 (if (null var1099) (
return nil)) (prog (a) (setq a (car var1099)) (if (atom a) (progn (if (atsoc 
a labs) (progn (if (not (null a)) (progn (if (neq (posn) 0) (terpri)) (princ 
"+++++ label ") (prin a) (princ " multiply defined") (terpri)))) (setq labs (
cons (cons a (cons (cons (gensym) (cdr env)) nil)) labs)))))) (setq var1099 (
cdr var1099)) (go lab1098)) (setq s!:current_proglabels (cons labs 
s!:current_proglabels)) (setq w (s!:residual_local_decs local_decs w)) (prog 
(var1101) (setq var1101 (cddr x)) lab1100 (if (null var1101) (return nil)) (
prog (a) (setq a (car var1101)) (if (not (atom a)) (s!:comval a env (plus 
context 4)) (prog (d) (setq d (atsoc a labs)) (if (null (cddr d)) (progn (
rplacd (cdr d) t) (s!:set_label (caadr d))))))) (setq var1101 (cdr var1101)) 
(go lab1100)) (s!:cancel_local_decs w) (s!:comval nil env context) (if fluids
(s!:outopcode0 (quote FREERSTR) (quote (FREERSTR)))) (s!:outlose n) (rplacd 
env s) (s!:set_label (cadar s!:current_exitlab)) (setq s!:current_exitlab (
cdr s!:current_exitlab)) (setq s!:current_proglabels (cdr 
s!:current_proglabels))))

(put (quote prog) (quote s!:compfn) (function s!:comprog))

(de s!:comtagbody (x env context) (prog (labs) (prog (var1103) (setq var1103 
(cdr x)) lab1102 (if (null var1103) (return nil)) (prog (a) (setq a (car 
var1103)) (if (atom a) (progn (if (atsoc a labs) (progn (if (not (null a)) (
progn (if (neq (posn) 0) (terpri)) (princ "+++++ label ") (prin a) (princ 
" multiply defined") (terpri)))) (setq labs (cons (cons a (cons (cons (gensym
) (cdr env)) nil)) labs)))))) (setq var1103 (cdr var1103)) (go lab1102)) (
setq s!:current_proglabels (cons labs s!:current_proglabels)) (prog (var1105)
(setq var1105 (cdr x)) lab1104 (if (null var1105) (return nil)) (prog (a) (
setq a (car var1105)) (if (not (atom a)) (s!:comval a env (plus context 4)) (
prog (d) (setq d (atsoc a labs)) (if (null (cddr d)) (progn (rplacd (cdr d) t
) (s!:set_label (caadr d))))))) (setq var1105 (cdr var1105)) (go lab1104)) (
s!:comval nil env context) (setq s!:current_proglabels (cdr 
s!:current_proglabels))))

(put (quote tagbody) (quote s!:compfn) (function s!:comtagbody))

(de s!:comblock (x env context) (prog nil (setq s!:current_exitlab (cons (
cons (cadr x) (cons (gensym) (cdr env))) s!:current_exitlab)) (s!:comval (
cons (quote progn) (cddr x)) env context) (s!:set_label (cadar 
s!:current_exitlab)) (setq s!:current_exitlab (cdr s!:current_exitlab))))

(put (quote !~block) (quote s!:compfn) (function s!:comblock))

(de s!:comcatch (x env context) (prog (g) (setq g (gensym)) (s!:comval (cadr 
x) env 1) (s!:outjump (quote CATCH) g) (rplacd env (cons (quote (catch)) (
cons 0 (cons 0 (cdr env))))) (s!:comval (cons (quote progn) (cddr x)) env 
context) (s!:outopcode0 (quote UNCATCH) (quote (UNCATCH))) (rplacd env (
cddddr env)) (s!:set_label g)))

(put (quote catch) (quote s!:compfn) (quote s!:comcatch))

(de s!:comthrow (x env context) (prog nil (s!:comval (cadr x) env 1) (
s!:outopcode0 (quote PUSH) (quote (PUSH))) (rplacd env (cons 0 (cdr env))) (
s!:comval (caddr x) env 1) (s!:outopcode0 (quote THROW) (quote (THROW))) (
rplacd env (cddr env))))

(put (quote throw) (quote s!:compfn) (quote s!:comthrow))

(de s!:comunwind!-protect (x env context) (prog (g) (setq g (gensym)) (
s!:comval (quote (load!-spid)) env 1) (s!:outjump (quote CATCH) g) (rplacd 
env (cons (list (quote unwind!-protect) (cddr x)) (cons 0 (cons 0 (cdr env)))
)) (s!:comval (cadr x) env context) (s!:outopcode0 (quote PROTECT) (quote (
PROTECT))) (s!:set_label g) (rplaca (cdr env) 0) (s!:comval (cons (quote 
progn) (cddr x)) env context) (s!:outopcode0 (quote UNPROTECT) (quote (
UNPROTECT))) (rplacd env (cddddr env))))

(put (quote unwind!-protect) (quote s!:compfn) (quote s!:comunwind!-protect))

(de s!:comdeclare (x env context) (prog nil (if !*pwrds (progn (princ "+++ ")
(prin x) (princ " ignored") (terpri)))))

(put (quote declare) (quote s!:compfn) (function s!:comdeclare))

(de s!:expand_let (vl b) (prog (vars vals) (prog (var1107) (setq var1107 vl) 
lab1106 (if (null var1107) (return nil)) (prog (v) (setq v (car var1107)) (if
(atom v) (progn (setq vars (cons v vars)) (setq vals (cons nil vals))) (if (
atom (cdr v)) (progn (setq vars (cons (car v) vars)) (setq vals (cons nil 
vals))) (progn (setq vars (cons (car v) vars)) (setq vals (cons (cadr v) vals
)))))) (setq var1107 (cdr var1107)) (go lab1106)) (return (list (cons (cons (
quote lambda) (cons vars b)) vals)))))

(de s!:comlet (x env context) (s!:comval (cons (quote progn) (s!:expand_let (
cadr x) (cddr x))) env context))

(put (quote !~let) (quote s!:compfn) (function s!:comlet))

(de s!:expand_let!* (vl local_decs b) (prog (r var val) (setq r (cons (cons (
quote declare) local_decs) b)) (prog (var1111) (setq var1111 (reverse vl)) 
lab1110 (if (null var1111) (return nil)) (prog (x) (setq x (car var1111)) (
progn (setq val nil) (if (atom x) (setq var x) (if (atom (cdr x)) (setq var (
car x)) (progn (setq var (car x)) (setq val (cadr x))))) (prog (var1109) (
setq var1109 local_decs) lab1108 (if (null var1109) (return nil)) (prog (z) (
setq z (car var1109)) (if (eqcar z (quote special)) (if (memq var (cdr z)) (
setq r (cons (list (quote declare) (list (quote special) var)) r))))) (setq 
var1109 (cdr var1109)) (go lab1108)) (setq r (list (list (cons (quote lambda)
(cons (list var) r)) val))))) (setq var1111 (cdr var1111)) (go lab1110)) (if
(eqcar (car r) (quote declare)) (setq r (list (cons (quote lambda) (cons nil
r)))) (setq r (cons (quote progn) r))) (return r)))

(de s!:comlet!* (x env context) (prog (b) (setq b (s!:find_local_decs (cddr x
))) (return (s!:comval (s!:expand_let!* (cadr x) (car b) (cdr b)) env context
))))

(put (quote let!*) (quote s!:compfn) (function s!:comlet!*))

(de s!:restore_stack (e1 e2) (prog (n) (setq n 0) (prog nil lab1113 (if (null
(not (equal e1 e2))) (return nil)) (progn (if (null e1) (error 0 
"bad block nesting with GO or RETURN-FROM")) (if (and (numberp (car e1)) (
greaterp (car e1) 2)) (progn (if (not (zerop n)) (s!:outlose n)) (setq n (car
e1)) (s!:outopcode0 (quote FREERSTR) (quote (FREERSTR))) (prog (i) (setq i 1
) lab1112 (if (minusp (times 1 (difference n i))) (return nil)) (setq e1 (cdr
e1)) (setq i (plus i 1)) (go lab1112)) (setq n 0)) (if (equal (car e1) (
quote (catch))) (progn (if (not (zerop n)) (s!:outlose n)) (s!:outopcode0 (
quote UNCATCH) (quote (UNCATCH))) (setq e1 (cdddr e1)) (setq n 0)) (if (eqcar
(car e1) (quote unwind!-protect)) (progn (if (not (zerop n)) (s!:outlose n))
(s!:outopcode0 (quote PROTECT) (quote (PROTECT))) (s!:comval (cons (quote 
progn) (cadar e1)) e1 2) (s!:outopcode0 (quote UNPROTECT) (quote (UNPROTECT))
) (setq e1 (cdddr e1)) (setq n 0)) (progn (setq e1 (cdr e1)) (setq n (plus n 
1))))))) (go lab1113)) (if (not (zerop n)) (s!:outlose n))))

(de s!:comgo (x env context) (prog (pl d) (if (lessp context 4) (progn (princ
"go not in program context") (terpri))) (setq pl s!:current_proglabels) (
prog nil lab1114 (if (null (and pl (null d))) (return nil)) (progn (setq d (
atsoc (cadr x) (car pl))) (if (null d) (setq pl (cdr pl)))) (go lab1114)) (if
(null d) (progn (if (neq (posn) 0) (terpri)) (princ "+++++ label ") (prin (
cadr x)) (princ " not set") (terpri) (return nil))) (setq d (cadr d)) (
s!:restore_stack (cdr env) (cdr d)) (s!:outjump (quote JUMP) (car d))))

(put (quote go) (quote s!:compfn) (function s!:comgo))

(de s!:comreturn!-from (x env context) (prog (tag) (if (lessp context 4) (
progn (princ "+++++ return or return-from not in prog context") (terpri))) (
setq x (cdr x)) (setq tag (car x)) (if (cdr x) (setq x (cadr x)) (setq x nil)
) (s!:comval x env (difference context 4)) (setq x (atsoc tag 
s!:current_exitlab)) (if (null x) (error 0 (list "invalid return-from" tag)))
(setq x (cdr x)) (s!:restore_stack (cdr env) (cdr x)) (s!:outjump (quote 
JUMP) (car x))))

(put (quote return!-from) (quote s!:compfn) (function s!:comreturn!-from))

(de s!:comreturn (x env context) (s!:comreturn!-from (cons (quote 
return!-from) (cons nil (cdr x))) env context))

(put (quote return) (quote s!:compfn) (function s!:comreturn))

(global (quote (s!:jumplts s!:jumplnils s!:jumpatoms s!:jumpnatoms)))

(setq s!:jumplts (s!:vecof (quote (JUMPL0T JUMPL1T JUMPL2T JUMPL3T JUMPL4T)))
)

(setq s!:jumplnils (s!:vecof (quote (JUMPL0NIL JUMPL1NIL JUMPL2NIL JUMPL3NIL 
JUMPL4NIL))))

(setq s!:jumpatoms (s!:vecof (quote (JUMPL0ATOM JUMPL1ATOM JUMPL2ATOM 
JUMPL3ATOM))))

(setq s!:jumpnatoms (s!:vecof (quote (JUMPL0NATOM JUMPL1NATOM JUMPL2NATOM 
JUMPL3NATOM))))

(de s!:jumpif (neg x env lab) (prog (w w1 j) top (if (null x) (progn (if (not
neg) (s!:outjump (quote JUMP) lab)) (return nil)) (if (or (eq x t) (and (
eqcar x (quote quote)) (cadr x)) (and (atom x) (not (symbolp x)))) (progn (if
neg (s!:outjump (quote JUMP) lab)) (return nil)) (if (lessp (setq w (
s!:islocal x env)) 5) (return (s!:outjump (getv (if neg s!:jumplts 
s!:jumplnils) w) lab)) (if (and (equal w 99999) (symbolp x)) (progn (
s!:should_be_fluid x) (setq w (list (if neg (quote JUMPFREET) (quote 
JUMPFREENIL)) x x)) (return (s!:record_literal_for_jump w env lab))))))) (if 
(and (not (atom x)) (atom (car x)) (setq w (get (car x) (quote s!:testfn)))) 
(return (funcall w neg x env lab))) (if (not (atom x)) (progn (setq w (
s!:improve x)) (if (or (atom w) (not (eqcar x (car w)))) (progn (setq x w) (
go top))) (if (and (setq w1 (get (car w) (quote s!:compilermacro))) (setq w1 
(funcall w1 w env 1))) (progn (setq x w1) (go top))))) remacro (if (and (not 
(atom w)) (setq w1 (macro!-function (car w)))) (progn (setq w (funcall w1 w))
(if (or (atom w) (eqcar w (quote quote)) (get (car w) (quote s!:testfn)) (
get (car w) (quote s!:compilermacro))) (progn (setq x w) (go top))) (go 
remacro))) (s!:comval x env 1) (setq w s!:current_block) (prog nil lab1115 (
if (null (and w (not (atom (car w))))) (return nil)) (setq w (cdr w)) (go 
lab1115)) (setq j (quote (JUMPNIL . JUMPT))) (if w (progn (setq w1 (car w)) (
setq w (cdr w)) (if (equal w1 (quote STORELOC0)) (progn (setq 
s!:current_block w) (setq s!:current_size (difference s!:current_size 1)) (
setq j (quote (JUMPST0NIL . JUMPST0T)))) (if (equal w1 (quote STORELOC1)) (
progn (setq s!:current_block w) (setq s!:current_size (difference 
s!:current_size 1)) (setq j (quote (JUMPST1NIL . JUMPST1T)))) (if (equal w1 (
quote STORELOC2)) (progn (setq s!:current_block w) (setq s!:current_size (
difference s!:current_size 1)) (setq j (quote (JUMPST2NIL . JUMPST2T)))) (if 
(eqcar w (quote BUILTIN1)) (progn (setq s!:current_block (cdr w)) (setq 
s!:current_size (difference s!:current_size 2)) (setq j (cons (list (quote 
JUMPB1NIL) w1) (list (quote JUMPB1T) w1)))) (if (eqcar w (quote BUILTIN2)) (
progn (setq s!:current_block (cdr w)) (setq s!:current_size (difference 
s!:current_size 2)) (setq j (cons (list (quote JUMPB2NIL) w1) (list (quote 
JUMPB2T) w1))))))))))) (return (s!:outjump (if neg (cdr j) (car j)) lab))))

(de s!:testnot (neg x env lab) (s!:jumpif (not neg) (cadr x) env lab))

(put (quote null) (quote s!:testfn) (function s!:testnot))

(put (quote not) (quote s!:testfn) (function s!:testnot))

(de s!:testatom (neg x env lab) (prog (w) (if (lessp (setq w (s!:islocal (
cadr x) env)) 4) (return (s!:outjump (getv (if neg s!:jumpatoms s!:jumpnatoms
) w) lab))) (s!:comval (cadr x) env 1) (if neg (s!:outjump (quote JUMPATOM) 
lab) (s!:outjump (quote JUMPNATOM) lab))))

(put (quote atom) (quote s!:testfn) (function s!:testatom))

(de s!:testconsp (neg x env lab) (prog (w) (if (lessp (setq w (s!:islocal (
cadr x) env)) 4) (return (s!:outjump (getv (if neg s!:jumpnatoms s!:jumpatoms
) w) lab))) (s!:comval (cadr x) env 1) (if neg (s!:outjump (quote JUMPNATOM) 
lab) (s!:outjump (quote JUMPATOM) lab))))

(put (quote consp) (quote s!:testfn) (function s!:testconsp))

(de s!:comcond (x env context) (prog (l1 l2 w) (setq l1 (gensym)) (prog nil 
lab1116 (if (null (setq x (cdr x))) (return nil)) (progn (setq w (car x)) (if
(atom (cdr w)) (progn (s!:comval (car w) env 1) (s!:outjump (quote JUMPT) l1
) (setq l2 nil)) (progn (if (equal (car w) t) (setq l2 nil) (progn (setq l2 (
gensym)) (s!:jumpif nil (car w) env l2))) (setq w (cdr w)) (if (null (cdr w))
(setq w (car w)) (setq w (cons (quote progn) w))) (s!:comval w env context) 
(if l2 (progn (s!:outjump (quote JUMP) l1) (s!:set_label l2)) (setq x (quote 
(nil))))))) (go lab1116)) (if l2 (s!:comval nil env context)) (s!:set_label 
l1)))

(put (quote cond) (quote s!:compfn) (function s!:comcond))

(de s!:comif (x env context) (prog (l1 l2) (setq l2 (gensym)) (s!:jumpif nil 
(cadr x) env l2) (setq x (cddr x)) (s!:comval (car x) env context) (setq x (
cdr x)) (if (or x (and (lessp context 2) (setq x (quote (nil))))) (progn (
setq l1 (gensym)) (s!:outjump (quote JUMP) l1) (s!:set_label l2) (s!:comval (
car x) env context) (s!:set_label l1)) (s!:set_label l2))))

(put (quote if) (quote s!:compfn) (function s!:comif))

(de s!:comwhen (x env context) (prog (l2) (setq l2 (gensym)) (if (lessp 
context 2) (progn (s!:comval (cadr x) env 1) (s!:outjump (quote JUMPNIL) l2))
(s!:jumpif nil (cadr x) env l2)) (s!:comval (cons (quote progn) (cddr x)) 
env context) (s!:set_label l2)))

(put (quote when) (quote s!:compfn) (function s!:comwhen))

(de s!:comunless (x env context) (s!:comwhen (list!* (quote when) (list (
quote not) (cadr x)) (cddr x)) env context))

(put (quote unless) (quote s!:compfn) (function s!:comunless))

(de s!:comicase (x env context) (prog (l1 labs labassoc w) (setq x (cdr x)) (
prog (var1118) (setq var1118 (cdr x)) lab1117 (if (null var1118) (return nil)
) (prog (v) (setq v (car var1118)) (progn (setq w (assoc!*!* v labassoc)) (if
w (setq l1 (cons (cdr w) l1)) (progn (setq l1 (gensym)) (setq labs (cons l1 
labs)) (setq labassoc (cons (cons v l1) labassoc)))))) (setq var1118 (cdr 
var1118)) (go lab1117)) (s!:comval (car x) env 1) (s!:outjump (quote ICASE) (
reversip labs)) (setq l1 (gensym)) (prog (var1120) (setq var1120 labassoc) 
lab1119 (if (null var1120) (return nil)) (prog (v) (setq v (car var1120)) (
progn (s!:set_label (cdr v)) (s!:comval (car v) env context) (s!:outjump (
quote JUMP) l1))) (setq var1120 (cdr var1120)) (go lab1119)) (s!:set_label l1
)))

(put (quote s!:icase) (quote s!:compfn) (function s!:comicase))

(put (quote JUMPLITEQ!*) (quote s!:opcode) (get (quote JUMPLITEQ) (quote 
s!:opcode)))

(put (quote JUMPLITNE!*) (quote s!:opcode) (get (quote JUMPLITNE) (quote 
s!:opcode)))

(de s!:jumpliteql (val lab env) (prog (w) (if (or (idp val) (eq!-safe val)) (
progn (setq w (list (quote JUMPLITEQ!*) val val)) (s!:record_literal_for_jump
w env lab)) (progn (s!:outopcode0 (quote PUSH) (quote (PUSH))) (
s!:loadliteral val env) (s!:outopcode1 (quote BUILTIN2) (get (quote eql) (
quote s!:builtin2)) (quote eql)) (s!:outjump (quote JUMPT) lab) (flag (list 
lab) (quote s!:jumpliteql)) (s!:outopcode0 (quote POP) (quote (POP)))))))

(de s!:casebranch (sw env dflt) (prog (size w w1 r g) (setq size (plus 4 (
truncate (length sw) 2))) (prog nil lab1121 (if (null (or (equal (remainder 
size 2) 0) (equal (remainder size 3) 0) (equal (remainder size 5) 0) (equal (
remainder size 13) 0))) (return nil)) (setq size (plus size 1)) (go lab1121))
(prog (var1123) (setq var1123 sw) lab1122 (if (null var1123) (return nil)) (
prog (p) (setq p (car var1123)) (progn (setq w (remainder (eqlhash (car p)) 
size)) (setq w1 (assoc!*!* w r)) (if w1 (rplacd (cdr w1) (cons p (cddr w1))) 
(setq r (cons (list w (gensym) p) r))))) (setq var1123 (cdr var1123)) (go 
lab1122)) (s!:outopcode0 (quote PUSH) (quote (PUSH))) (rplacd env (cons 0 (
cdr env))) (s!:outopcode1lit (quote CALL1) (quote eqlhash) env) (
s!:loadliteral size env) (setq g (gensym)) (s!:outopcode1 (quote BUILTIN2) (
get (quote iremainder) (quote s!:builtin2)) (quote iremainder)) (s!:outjump (
quote ICASE) (cons g (prog (i var1125) (setq i 0) lab1124 (if (minusp (times 
1 (difference (difference size 1) i))) (return (reversip var1125))) (setq 
var1125 (cons (progn (setq w (assoc!*!* i r)) (if w (cadr w) g)) var1125)) (
setq i (plus i 1)) (go lab1124)))) (prog (var1129) (setq var1129 r) lab1128 (
if (null var1129) (return nil)) (prog (p) (setq p (car var1129)) (progn (
s!:set_label (cadr p)) (s!:outopcode0 (quote POP) (quote (POP))) (prog (
var1127) (setq var1127 (cddr p)) lab1126 (if (null var1127) (return nil)) (
prog (q) (setq q (car var1127)) (s!:jumpliteql (car q) (cdr q) env)) (setq 
var1127 (cdr var1127)) (go lab1126)) (s!:outjump (quote JUMP) dflt))) (setq 
var1129 (cdr var1129)) (go lab1128)) (s!:set_label g) (s!:outopcode0 (quote 
POP) (quote (POP))) (s!:outjump (quote JUMP) dflt) (rplacd env (cddr env))))

(de s!:comcase (x env context) (prog (keyform blocks v w g dflt sw keys 
nonnum) (setq x (cdr x)) (setq keyform (car x)) (prog (y) (setq y (cdr x)) 
lab1132 (if (null y) (return nil)) (progn (setq w (assoc!*!* (cdar y) blocks)
) (if w (setq g (cdr w)) (progn (setq g (gensym)) (setq blocks (cons (cons (
cdar y) g) blocks)))) (setq w (caar y)) (if (and (null (cdr y)) (or (equal w 
t) (equal w (quote otherwise)))) (setq dflt g) (progn (if (atom w) (setq w (
list w))) (prog (var1131) (setq var1131 w) lab1130 (if (null var1131) (return
nil)) (prog (n) (setq n (car var1131)) (progn (if (or (idp n) (numberp n)) (
progn (if (not (fixp n)) (setq nonnum t)) (setq keys (cons n keys)) (setq sw 
(cons (cons n g) sw))) (error 0 (list "illegal case label" n))))) (setq 
var1131 (cdr var1131)) (go lab1130))))) (setq y (cdr y)) (go lab1132)) (if (
null dflt) (progn (if (setq w (assoc!*!* nil blocks)) (setq dflt (cdr w)) (
setq blocks (cons (cons nil (setq dflt (gensym))) blocks))))) (if (not nonnum
) (progn (setq keys (sort keys (function lessp))) (setq nonnum (car keys)) (
setq g (lastcar keys)) (if (lessp (difference g nonnum) (times 2 (length keys
))) (progn (if (not (equal nonnum 0)) (progn (setq keyform (list (quote 
xdifference) keyform nonnum)) (setq sw (prog (var1134 var1135) (setq var1134 
sw) lab1133 (if (null var1134) (return (reversip var1135))) (prog (y) (setq y
(car var1134)) (setq var1135 (cons (cons (difference (car y) nonnum) (cdr y)
) var1135))) (setq var1134 (cdr var1134)) (go lab1133))))) (s!:comval keyform
env 1) (setq w nil) (prog (i) (setq i 0) lab1136 (if (minusp (times 1 (
difference g i))) (return nil)) (if (setq v (assoc!*!* i sw)) (setq w (cons (
cdr v) w)) (setq w (cons dflt w))) (setq i (plus i 1)) (go lab1136)) (setq w 
(cons dflt (reversip w))) (s!:outjump (quote ICASE) w) (setq nonnum nil)) (
setq nonnum t)))) (if nonnum (progn (s!:comval keyform env 1) (if (lessp (
length sw) 7) (progn (prog (var1138) (setq var1138 sw) lab1137 (if (null 
var1138) (return nil)) (prog (y) (setq y (car var1138)) (s!:jumpliteql (car y
) (cdr y) env)) (setq var1138 (cdr var1138)) (go lab1137)) (s!:outjump (quote
JUMP) dflt)) (s!:casebranch sw env dflt)))) (setq g (gensym)) (prog (var1140
) (setq var1140 blocks) lab1139 (if (null var1140) (return nil)) (prog (v) (
setq v (car var1140)) (progn (s!:set_label (cdr v)) (if (flagp (cdr v) (quote
s!:jumpliteql)) (s!:outlose 1)) (s!:comval (cons (quote progn) (car v)) env 
context) (s!:outjump (quote JUMP) g))) (setq var1140 (cdr var1140)) (go 
lab1139)) (s!:set_label g)))

(put (quote case) (quote s!:compfn) (function s!:comcase))

(fluid (quote (!*defn dfprint!* s!:dfprintsave s!:faslmod_name)))

(de s!:comeval!-when (x env context) (prog (y) (setq x (cdr x)) (setq y (car 
x)) (setq x (cons (quote progn) (cdr x))) (if (memq (quote compile) y) (eval 
x)) (if (memq (quote load) y) (progn (if dfprint!* (apply1 dfprint!* x)))) (
if (memq (quote eval) y) (s!:comval x env context) (s!:comval nil env context
))))

(put (quote eval!-when) (quote s!:compfn) (function s!:comeval!-when))

(de s!:comthe (x env context) (s!:comval (caddr x) env context))

(put (quote the) (quote s!:compfn) (function s!:comthe))

(de s!:comand (x env context) (prog (l) (setq l (gensym)) (setq x (cdr x)) (
s!:comval (car x) env 1) (prog nil lab1141 (if (null (setq x (cdr x))) (
return nil)) (progn (s!:outjump (quote JUMPNIL) l) (s!:comval (car x) env 1))
(go lab1141)) (s!:set_label l)))

(put (quote and) (quote s!:compfn) (function s!:comand))

(de s!:comor (x env context) (prog (l) (setq l (gensym)) (setq x (cdr x)) (
s!:comval (car x) env 1) (prog nil lab1142 (if (null (setq x (cdr x))) (
return nil)) (progn (s!:outjump (quote JUMPT) l) (s!:comval (car x) env 1)) (
go lab1142)) (s!:set_label l)))

(put (quote or) (quote s!:compfn) (function s!:comor))

(de s!:combool (neg x env lab) (prog (fn) (setq fn (eqcar x (quote or))) (if 
(eq fn neg) (prog nil lab1143 (if (null (setq x (cdr x))) (return nil)) (
s!:jumpif fn (car x) env lab) (go lab1143)) (progn (setq neg (gensym)) (prog 
nil lab1144 (if (null (setq x (cdr x))) (return nil)) (s!:jumpif fn (car x) 
env neg) (go lab1144)) (s!:outjump (quote JUMP) lab) (s!:set_label neg)))))

(put (quote and) (quote s!:testfn) (function s!:combool))

(put (quote or) (quote s!:testfn) (function s!:combool))

(de s!:testeq (neg x env lab) (prog (a b) (setq a (s!:improve (cadr x))) (
setq b (s!:improve (caddr x))) (if (or (s!:eval_to_eq_unsafe a) (
s!:eval_to_eq_unsafe b)) (progn (if (neq (posn) 0) (terpri)) (princ 
"++++ EQ on number upgraded to EQUAL in ") (prin s!:current_function) (princ 
" : ") (prin a) (princ " ") (print b) (return (s!:testequal neg (cons (quote 
equal) (cdr x)) env lab)))) (if !*carefuleq (progn (s!:comval x env 1) (
s!:outjump (if neg (quote JUMPT) (quote JUMPNIL)) lab) (return nil))) (if (
null a) (s!:jumpif (not neg) b env lab) (if (null b) (s!:jumpif (not neg) a 
env lab) (if (or (eqcar a (quote quote)) (and (atom a) (not (symbolp a)))) (
progn (s!:comval b env 1) (if (eqcar a (quote quote)) (setq a (cadr a))) (
setq b (list (if neg (quote JUMPLITEQ) (quote JUMPLITNE)) a a)) (
s!:record_literal_for_jump b env lab)) (if (or (eqcar b (quote quote)) (and (
atom b) (not (symbolp b)))) (progn (s!:comval a env 1) (if (eqcar b (quote 
quote)) (setq b (cadr b))) (setq a (list (if neg (quote JUMPLITEQ) (quote 
JUMPLITNE)) b b)) (s!:record_literal_for_jump a env lab)) (progn (s!:load2 a 
b env) (if neg (s!:outjump (quote JUMPEQ) lab) (s!:outjump (quote JUMPNE) lab
)))))))))

(de s!:testeq1 (neg x env lab) (prog (a b) (if !*carefuleq (progn (s!:comval 
x env 1) (s!:outjump (if neg (quote JUMPT) (quote JUMPNIL)) lab) (return nil)
)) (setq a (s!:improve (cadr x))) (setq b (s!:improve (caddr x))) (if (null a
) (s!:jumpif (not neg) b env lab) (if (null b) (s!:jumpif (not neg) a env lab
) (if (or (eqcar a (quote quote)) (and (atom a) (not (symbolp a)))) (progn (
s!:comval b env 1) (if (eqcar a (quote quote)) (setq a (cadr a))) (setq b (
list (if neg (quote JUMPLITEQ) (quote JUMPLITNE)) a a)) (
s!:record_literal_for_jump b env lab)) (if (or (eqcar b (quote quote)) (and (
atom b) (not (symbolp b)))) (progn (s!:comval a env 1) (if (eqcar b (quote 
quote)) (setq b (cadr b))) (setq a (list (if neg (quote JUMPLITEQ) (quote 
JUMPLITNE)) b b)) (s!:record_literal_for_jump a env lab)) (progn (s!:load2 a 
b env) (if neg (s!:outjump (quote JUMPEQ) lab) (s!:outjump (quote JUMPNE) lab
)))))))))

(put (quote eq) (quote s!:testfn) (function s!:testeq))

(if (eq!-safe 0) (put (quote iequal) (quote s!:testfn) (function s!:testeq1))
(put (quote iequal) (quote s!:testfn) (function s!:testequal)))

(de s!:testequal (neg x env lab) (prog (a b) (setq a (cadr x)) (setq b (caddr
x)) (if (null a) (s!:jumpif (not neg) b env lab) (if (null b) (s!:jumpif (
not neg) a env lab) (if (or (and (eqcar a (quote quote)) (or (symbolp (cadr a
)) (eq!-safe (cadr a)))) (and (eqcar b (quote quote)) (or (symbolp (cadr b)) 
(eq!-safe (cadr b)))) (eq!-safe a) (eq!-safe b)) (s!:testeq1 neg (cons (quote
eq) (cdr x)) env lab) (progn (s!:load2 a b env) (if neg (s!:outjump (quote 
JUMPEQUAL) lab) (s!:outjump (quote JUMPNEQUAL) lab))))))))

(put (quote equal) (quote s!:testfn) (function s!:testequal))

(de s!:testneq (neg x env lab) (s!:testequal (not neg) (cons (quote equal) (
cdr x)) env lab))

(put (quote neq) (quote s!:testfn) (function s!:testneq))

(de s!:testeqcar (neg x env lab) (prog (a b sw promote) (setq a (cadr x)) (
setq b (s!:improve (caddr x))) (if (s!:eval_to_eq_unsafe b) (progn (if (neq (
posn) 0) (terpri)) (princ "++++ EQCAR on number upgraded to EQUALCAR in ") (
prin s!:current_function) (princ " : ") (print b) (setq promote t)) (if 
!*carefuleq (progn (s!:comval x env 1) (s!:outjump (if neg (quote JUMPT) (
quote JUMPNIL)) lab) (return nil)))) (if (and (not promote) (eqcar b (quote 
quote))) (progn (s!:comval a env 1) (setq b (cadr b)) (setq a (list (if neg (
quote JUMPEQCAR) (quote JUMPNEQCAR)) b b)) (s!:record_literal_for_jump a env 
lab)) (progn (setq sw (s!:load2 a b env)) (if sw (s!:outopcode0 (quote SWOP) 
(quote (SWOP)))) (if promote (s!:outopcode1 (quote BUILTIN2) (get (quote 
equalcar) (quote s!:builtin2)) (quote equalcar)) (s!:outopcode0 (quote EQCAR)
(quote (EQCAR)))) (s!:outjump (if neg (quote JUMPT) (quote JUMPNIL)) lab))))
)

(put (quote eqcar) (quote s!:testfn) (function s!:testeqcar))

(de s!:testflagp (neg x env lab) (prog (a b sw) (setq a (cadr x)) (setq b (
caddr x)) (if (eqcar b (quote quote)) (progn (s!:comval a env 1) (setq b (
cadr b)) (setq sw (symbol!-make!-fastget b nil)) (if sw (progn (s!:outopcode1
(quote FASTGET) (logor sw 128) b) (s!:outjump (if neg (quote JUMPT) (quote 
JUMPNIL)) lab)) (progn (setq a (list (if neg (quote JUMPFLAGP) (quote 
JUMPNFLAGP)) b b)) (s!:record_literal_for_jump a env lab)))) (progn (setq sw 
(s!:load2 a b env)) (if sw (s!:outopcode0 (quote SWOP) (quote (SWOP)))) (
s!:outopcode0 (quote FLAGP) (quote (FLAGP))) (s!:outjump (if neg (quote JUMPT
) (quote JUMPNIL)) lab)))))

(put (quote flagp) (quote s!:testfn) (function s!:testflagp))

(global (quote (s!:storelocs)))

(setq s!:storelocs (s!:vecof (quote (STORELOC0 STORELOC1 STORELOC2 STORELOC3 
STORELOC4 STORELOC5 STORELOC6 STORELOC7))))

(de s!:comsetq (x env context) (prog (n w var) (setq x (cdr x)) (if (null x) 
(return nil)) (if (or (not (symbolp (car x))) (null (cdr x))) (return (error 
0 (list "bad args for setq" x)))) (s!:comval (cadr x) env 1) (setq var (car x
)) (setq n 0) (setq w (cdr env)) (prog nil lab1145 (if (null (and w (not (
eqcar w var)))) (return nil)) (progn (setq n (add1 n)) (setq w (cdr w))) (go 
lab1145)) (if w (progn (if (not (member!*!* (cons (quote loc) w) 
s!:a_reg_values)) (setq s!:a_reg_values (cons (cons (quote loc) w) 
s!:a_reg_values))) (if (lessp n 8) (s!:outopcode0 (getv s!:storelocs n) (list
(quote storeloc) var)) (if (greaterp n 4095) (error "stack frame > 4095") (
if (greaterp n 255) (s!:outopcode2 (quote BIGSTACK) (plus 64 (truncate n 256)
) (logand n 255) (list (quote STORELOC) var)) (s!:outopcode1 (quote STORELOC)
n var))))) (if (setq w (s!:find_lexical var s!:lexical_env 0)) (progn (if (
not (member!*!* (cons (quote lex) w) s!:a_reg_values)) (setq s!:a_reg_values 
(cons (cons (quote lex) w) s!:a_reg_values))) (s!:outlexref (quote STORELEX) 
(length (cdr env)) (car w) (cadr w) var)) (progn (if (or (null var) (eq var t
)) (error 0 (list "bad variable in setq" var)) (s!:should_be_fluid var)) (
setq w (cons (quote free) var)) (if (not (member!*!* w s!:a_reg_values)) (
setq s!:a_reg_values (cons w s!:a_reg_values))) (s!:outopcode1lit (quote 
STOREFREE) var env)))) (if (cddr x) (return (s!:comsetq (cdr x) env context))
)))

(put (quote setq) (quote s!:compfn) (function s!:comsetq))

(put (quote noisy!-setq) (quote s!:compfn) (function s!:comsetq))

(de s!:comlist (x env context) (prog (w) (if (null (setq x (cdr x))) (return 
(s!:comval nil env context))) (setq s!:a_reg_values nil) (if (null (setq w (
cdr x))) (s!:comval (list (quote ncons) (car x)) env context) (if (null (setq
w (cdr w))) (s!:comval (list (quote list2) (car x) (cadr x)) env context) (
if (null (cdr w)) (s!:comval (list (quote list3) (car x) (cadr x) (car w)) 
env context) (s!:comval (list (quote list2!*) (car x) (cadr x) (cons (quote 
list) w)) env context))))))

(put (quote list) (quote s!:compfn) (function s!:comlist))

(de s!:comlist!* (x env context) (prog (w) (if (null (setq x (cdr x))) (
return (s!:comval nil env context))) (setq s!:a_reg_values nil) (if (null (
setq w (cdr x))) (s!:comval (car x) env context) (if (null (setq w (cdr w))) 
(s!:comval (list (quote cons) (car x) (cadr x)) env context) (if (null (cdr w
)) (s!:comval (list (quote list2!*) (car x) (cadr x) (car w)) env context) (
s!:comval (list (quote list2!*) (car x) (cadr x) (cons (quote list!*) w)) env
context))))))

(put (quote list!*) (quote s!:compfn) (function s!:comlist!*))

(de s!:comcons (x env context) (prog (a b) (setq a (cadr x)) (setq b (caddr x
)) (if (or (equal b nil) (equal b (quote (quote nil)))) (s!:comval (list (
quote ncons) a) env context) (if (eqcar a (quote cons)) (s!:comval (list (
quote acons) (cadr a) (caddr a) b) env context) (if (eqcar b (quote cons)) (
if (null (caddr b)) (s!:comval (list (quote list2) a (cadr b)) env context) (
s!:comval (list (quote list2!*) a (cadr b) (caddr b)) env context)) (if (and 
(not !*ord) (s!:iseasy a) (not (s!:iseasy b))) (s!:comval (list (quote xcons)
b a) env context) (s!:comcall x env context)))))))

(put (quote cons) (quote s!:compfn) (function s!:comcons))

(de s!:comapply (x env context) (prog (a b n) (setq a (cadr x)) (setq b (
caddr x)) (if (and (null (cdddr x)) (eqcar b (quote list))) (progn (if (eqcar
a (quote quote)) (return (progn (setq n s!:current_function) (prog (
s!:current_function) (setq s!:current_function (compress (append (explode n) 
(cons (quote !!) (cons (quote !.) (explodec (setq s!:current_count (plus 
s!:current_count 1)))))))) (return (s!:comval (cons (cadr a) (cdr b)) env 
context)))))) (setq n (length (setq b (cdr b)))) (return (s!:comval (cons (
quote funcall) (cons a b)) env context))) (if (and (null b) (null (cdddr x)))
(return (s!:comval (list (quote funcall) a) env context)) (return (
s!:comcall x env context))))))

(put (quote apply) (quote s!:compfn) (function s!:comapply))

(de s!:imp_funcall (u) (prog (n) (setq u (cdr u)) (if (eqcar (car u) (quote 
function)) (return (s!:improve (cons (cadar u) (cdr u))))) (setq n (length (
cdr u))) (setq u (if (equal n 0) (cons (quote apply0) u) (if (equal n 1) (
cons (quote apply1) u) (if (equal n 2) (cons (quote apply2) u) (if (equal n 3
) (cons (quote apply3) u) (cons (quote funcall!*) u)))))) (return u)))

(put (quote funcall) (quote s!:tidy_fn) (quote s!:imp_funcall))

(de s!:eval_to_eq_safe (x) (or (null x) (equal x t) (and (not (symbolp x)) (
eq!-safe x)) (and (not (atom x)) (flagp (car x) (quote eq!-safe))) (and (
eqcar x (quote quote)) (or (symbolp (cadr x)) (eq!-safe (cadr x))))))

(de s!:eval_to_eq_unsafe (x) (or (and (atom x) (not (symbolp x)) (not (
eq!-safe x))) (and (not (atom x)) (flagp (car x) (quote eq!-unsafe))) (and (
eqcar x (quote quote)) (or (not (atom (cadr x))) (and (not (symbolp (cadr x))
) (not (eq!-safe (cadr x))))))))

(de s!:list_all_eq_safe (u) (or (atom u) (and (or (symbolp (car u)) (eq!-safe
(car u))) (s!:list_all_eq_safe (cdr u)))))

(de s!:eval_to_list_all_eq_safe (x) (or (null x) (and (eqcar x (quote quote))
(s!:list_all_eq_safe (cadr x))) (and (eqcar x (quote list)) (or (null (cdr x
)) (and (s!:eval_to_eq_safe (cadr x)) (s!:eval_to_list_all_eq_safe (cons (
quote list) (cddr x)))))) (and (eqcar x (quote cons)) (s!:eval_to_eq_safe (
cadr x)) (s!:eval_to_list_all_eq_safe (caddr x)))))

(de s!:eval_to_eq_unsafe (x) (or (and (numberp x) (not (eq!-safe x))) (
stringp x) (and (eqcar x (quote quote)) (or (not (atom (cadr x))) (and (
numberp (cadr x)) (not (eq!-safe (cadr x)))) (stringp (cadr x))))))

(de s!:list_some_eq_unsafe (u) (and (not (atom u)) (or (s!:eval_to_eq_unsafe 
(car u)) (s!:list_some_eq_unsafe (cdr u)))))

(de s!:eval_to_list_some_eq_unsafe (x) (if (atom x) nil (if (eqcar x (quote 
quote)) (s!:list_some_eq_unsafe (cadr x)) (if (and (eqcar x (quote list)) (
cdr x)) (or (s!:eval_to_eq_unsafe (cadr x)) (s!:eval_to_list_some_eq_unsafe (
cons (quote list) (cddr x)))) (if (eqcar x (quote cons)) (or (
s!:eval_to_eq_unsafe (cadr x)) (s!:eval_to_list_some_eq_unsafe (caddr x))) 
nil)))))

(de s!:eval_to_car_eq_safe (x) (and (or (eqcar x (quote cons)) (eqcar x (
quote list))) (not (null (cdr x))) (s!:eval_to_eq_safe (cadr x))))

(de s!:eval_to_car_eq_unsafe (x) (and (or (eqcar x (quote cons)) (eqcar x (
quote list))) (not (null (cdr x))) (s!:eval_to_eq_unsafe (cadr x))))

(de s!:alist_eq_safe (u) (or (atom u) (and (not (atom (car u))) (or (symbolp 
(caar u)) (eq!-safe (caar u))) (s!:alist_eq_safe (cdr u)))))

(de s!:eval_to_alist_eq_safe (x) (or (null x) (and (eqcar x (quote quote)) (
s!:alist_eq_safe (cadr x))) (and (eqcar x (quote list)) (or (null (cdr x)) (
and (s!:eval_to_car_eq_safe (cadr x)) (s!:eval_to_alist_eq_safe (cons (quote 
list) (cddr x)))))) (and (eqcar x (quote cons)) (s!:eval_to_car_eq_safe (cadr
x)) (s!:eval_to_alist_eq_safe (caddr x)))))

(de s!:alist_eq_unsafe (u) (and (not (atom u)) (not (atom (car u))) (or (not 
(atom (caar u))) (and (not (symbolp (caar u))) (not (eq!-safe (caar u)))) (
s!:alist_eq_unsafe (cdr u)))))

(de s!:eval_to_alist_eq_unsafe (x) (if (null x) nil (if (eqcar x (quote quote
)) (s!:alist_eq_unsafe (cadr x)) (if (eqcar x (quote list)) (and (cdr x) (or 
(s!:eval_to_car_eq_unsafe (cadr x)) (s!:eval_to_alist_eq_unsafe (cons (quote 
list) (cddr x))))) (if (eqcar x (quote cons)) (or (s!:eval_to_car_eq_unsafe (
cadr x)) (s!:eval_to_alist_eq_safe (caddr x))) nil)))))

(flag (quote (eq eqcar null not greaterp lessp geq leq minusp atom numberp 
consp)) (quote eq!-safe))

(if (not (eq!-safe 1)) (flag (quote (length plus minus difference times 
quotient plus2 times2 expt fix float)) (quote eq!-unsafe)))

(de s!:comequal (x env context) (if (or (s!:eval_to_eq_safe (cadr x)) (
s!:eval_to_eq_safe (caddr x))) (s!:comcall (cons (quote eq) (cdr x)) env 
context) (s!:comcall x env context)))

(put (quote equal) (quote s!:compfn) (function s!:comequal))

(de s!:comeq (x env context) (if (or (s!:eval_to_eq_unsafe (cadr x)) (
s!:eval_to_eq_unsafe (caddr x))) (progn (if (neq (posn) 0) (terpri)) (princ 
"++++ EQ on number upgraded to EQUAL in ") (prin s!:current_function) (princ 
" : ") (prin (cadr x)) (princ " ") (print (caddr x)) (s!:comcall (cons (quote
equal) (cdr x)) env context)) (s!:comcall x env context)))

(put (quote eq) (quote s!:compfn) (function s!:comeq))

(de s!:comeqcar (x env context) (if (s!:eval_to_eq_unsafe (caddr x)) (progn (
if (neq (posn) 0) (terpri)) (princ 
"++++ EQCAR on number upgraded to EQUALCAR in ") (prin s!:current_function) (
princ " : ") (prin (caddr x)) (s!:comcall (cons (quote equalcar) (cdr x)) env
context)) (s!:comcall x env context)))

(put (quote eqcar) (quote s!:compfn) (function s!:comeqcar))

(de s!:comsublis (x env context) (if (s!:eval_to_alist_eq_safe (cadr x)) (
s!:comval (cons (quote subla) (cdr x)) env context) (s!:comcall x env context
)))

(put (quote sublis) (quote s!:compfn) (function s!:comsublis))

(de s!:comsubla (x env context) (if (s!:eval_to_alist_eq_unsafe (cadr x)) (
progn (if (neq (posn) 0) (terpri)) (princ 
"++++ SUBLA on number upgraded to SUBLIS in ") (prin s!:current_function) (
princ " : ") (print (cadr x)) (s!:comval (cons (quote sublis) (cdr x)) env 
context)) (s!:comcall x env context)))

(put (quote subla) (quote s!:compfn) (function s!:comsubla))

(de s!:comassoc (x env context) (if (and (or (s!:eval_to_eq_safe (cadr x)) (
s!:eval_to_alist_eq_safe (caddr x))) (equal (length x) 3)) (s!:comval (cons (
quote atsoc) (cdr x)) env context) (if (equal (length x) 3) (s!:comcall (cons
(quote assoc!*!*) (cdr x)) env context) (s!:comcall x env context))))

(put (quote assoc) (quote s!:compfn) (function s!:comassoc))

(put (quote assoc!*!*) (quote s!:compfn) (function s!:comassoc))

(de s!:comatsoc (x env context) (if (or (s!:eval_to_eq_unsafe (cadr x)) (
s!:eval_to_alist_eq_unsafe (caddr x))) (progn (if (neq (posn) 0) (terpri)) (
princ "++++ ATSOC on number upgraded to ASSOC in ") (prin s!:current_function
) (princ " : ") (prin (cadr x)) (princ " ") (print (caddr x)) (s!:comval (
cons (quote assoc) (cdr x)) env context)) (s!:comcall x env context)))

(put (quote atsoc) (quote s!:compfn) (function s!:comatsoc))

(de s!:commember (x env context) (if (and (or (s!:eval_to_eq_safe (cadr x)) (
s!:eval_to_list_all_eq_safe (caddr x))) (equal (length x) 3)) (s!:comval (
cons (quote memq) (cdr x)) env context) (s!:comcall x env context)))

(put (quote member) (quote s!:compfn) (function s!:commember))

(put (quote member!*!*) (quote s!:compfn) (function s!:commember))

(de s!:commemq (x env context) (if (or (s!:eval_to_eq_unsafe (cadr x)) (
s!:eval_to_list_some_eq_unsafe (caddr x))) (progn (if (neq (posn) 0) (terpri)
) (princ "++++ MEMQ on number upgraded to MEMBER in ") (prin 
s!:current_function) (princ " : ") (prin (cadr x)) (princ " ") (print (caddr 
x)) (s!:comval (cons (quote member) (cdr x)) env context)) (s!:comcall x env 
context)))

(put (quote memq) (quote s!:compfn) (function s!:commemq))

(de s!:comdelete (x env context) (if (and (or (s!:eval_to_eq_safe (cadr x)) (
s!:eval_to_list_all_eq_safe (caddr x))) (equal (length x) 3)) (s!:comval (
cons (quote deleq) (cdr x)) env context) (s!:comcall x env context)))

(put (quote delete) (quote s!:compfn) (function s!:comdelete))

(de s!:comdeleq (x env context) (if (or (s!:eval_to_eq_unsafe (cadr x)) (
s!:eval_to_list_some_eq_unsafe (caddr x))) (progn (if (neq (posn) 0) (terpri)
) (princ "++++ DELEQ on number upgraded to DELETE in ") (prin 
s!:current_function) (princ " : ") (prin (cadr x)) (princ " ") (print (caddr 
x)) (s!:comval (cons (quote delete) (cdr x)) env context)) (s!:comcall x env 
context)))

(put (quote deleq) (quote s!:compfn) (function s!:comdeleq))

(de s!:commap (fnargs env context) (prog (carp fn fn1 args var avar moveon l1
r s closed) (setq fn (car fnargs)) (if (greaterp context 1) (progn (if (
equal fn (quote mapcar)) (setq fn (quote mapc)) (if (equal fn (quote maplist)
) (setq fn (quote map)))))) (if (or (equal fn (quote mapc)) (equal fn (quote 
mapcar)) (equal fn (quote mapcan))) (setq carp t)) (setq fnargs (cdr fnargs))
(if (atom fnargs) (error 0 "bad arguments to map function")) (setq fn1 (cadr
fnargs)) (prog nil lab1146 (if (null (or (eqcar fn1 (quote function)) (and (
eqcar fn1 (quote quote)) (eqcar (cadr fn1) (quote lambda))))) (return nil)) (
progn (setq fn1 (cadr fn1)) (setq closed t)) (go lab1146)) (setq args (car 
fnargs)) (setq l1 (gensym)) (setq r (gensym)) (setq s (gensym)) (setq var (
gensym)) (setq avar var) (if carp (setq avar (list (quote car) avar))) (if 
closed (setq fn1 (list fn1 avar)) (setq fn1 (list (quote funcall) fn1 avar)))
(setq moveon (list (quote setq) var (list (quote cdr) var))) (if (or (equal 
fn (quote map)) (equal fn (quote mapc))) (setq fn (sublis (list (cons (quote 
l1) l1) (cons (quote var) var) (cons (quote fn) fn1) (cons (quote args) args)
(cons (quote moveon) moveon)) (quote (prog (var) (setq var args) l1 (cond ((
not var) (return nil))) fn moveon (go l1))))) (if (or (equal fn (quote 
maplist)) (equal fn (quote mapcar))) (setq fn (sublis (list (cons (quote l1) 
l1) (cons (quote var) var) (cons (quote fn) fn1) (cons (quote args) args) (
cons (quote moveon) moveon) (cons (quote r) r)) (quote (prog (var r) (setq 
var args) l1 (cond ((not var) (return (reversip r)))) (setq r (cons fn r)) 
moveon (go l1))))) (setq fn (sublis (list (cons (quote l1) l1) (cons (quote 
l2) (gensym)) (cons (quote var) var) (cons (quote fn) fn1) (cons (quote args)
args) (cons (quote moveon) moveon) (cons (quote r) (gensym)) (cons (quote s)
(gensym))) (quote (prog (var r s) (setq var args) (setq r (setq s (list nil)
)) l1 (cond ((not var) (return (cdr r)))) (rplacd s fn) l2 (cond ((not (atom 
(cdr s))) (setq s (cdr s)) (go l2))) moveon (go l1))))))) (s!:comval fn env 
context)))

(put (quote map) (quote s!:compfn) (function s!:commap))

(put (quote maplist) (quote s!:compfn) (function s!:commap))

(put (quote mapc) (quote s!:compfn) (function s!:commap))

(put (quote mapcar) (quote s!:compfn) (function s!:commap))

(put (quote mapcon) (quote s!:compfn) (function s!:commap))

(put (quote mapcan) (quote s!:compfn) (function s!:commap))

(de s!:nilargs (use) (if (null use) t (if (or (equal (car use) (quote nil)) (
equal (car use) (quote (quote nil)))) (s!:nilargs (cdr use)) nil)))

(de s!:subargs (args use) (if (null use) t (if (null args) (s!:nilargs use) (
if (not (equal (car args) (car use))) nil (s!:subargs (cdr args) (cdr use))))
))

(fluid (quote (!*where_defined!*)))

(de clear_source_database nil (progn (setq !*where_defined!* (mkhash 10 2 1.5
)) nil))

(de load_source_database (filename) (prog (a b) (clear_source_database) (setq
a (open filename (quote input))) (if (null a) (return nil)) (setq a (rds a))
(prog nil lab1147 (if (null (setq b (read))) (return nil)) (puthash (car b) 
!*where_defined!* (cdr b)) (go lab1147)) (close (rds a)) (return nil)))

(de save_source_database (filename) (prog (a) (setq a (open filename (quote 
output))) (if (null a) (return nil)) (setq a (wrs a)) (prog (var1149) (setq 
var1149 (sort (hashcontents !*where_defined!*) (function orderp))) lab1148 (
if (null var1149) (return nil)) (prog (z) (setq z (car var1149)) (progn (prin
z) (terpri))) (setq var1149 (cdr var1149)) (go lab1148)) (princ nil) (terpri
) (wrs a) (setq !*where_defined!* nil) (return nil)))

(de display_source_database nil (prog (w) (if (null !*where_defined!*) (
return nil)) (setq w (hashcontents !*where_defined!*)) (setq w (sort w (
function orderp))) (terpri) (prog (var1151) (setq var1151 w) lab1150 (if (
null var1151) (return nil)) (prog (x) (setq x (car var1151)) (progn (princ (
car x)) (ttab 40) (prin (cdr x)) (terpri))) (setq var1151 (cdr var1151)) (go 
lab1150))))

(fluid (quote (s!:r2i_simple_recurse s!:r2i_cons_recurse)))

(de s!:r2i (name args body) (prog (lab v b1 s!:r2i_simple_recurse 
s!:r2i_cons_recurse) (setq lab (gensym)) (setq v (list (gensym))) (setq b1 (
s!:r2i1 name args body lab v)) (if s!:r2i_cons_recurse (progn (setq b1 (list 
(quote prog) v lab b1)) (return b1)) (if s!:r2i_simple_recurse (progn (setq v
(list (gensym))) (setq b1 (s!:r2i2 name args body lab v)) (setq b1 (list (
quote prog) (cdr v) lab b1)) (return b1)) (return (s!:r2i3 name args body lab
v))))))

(de s!:r2i1 (name args body lab v) (if (or (null body) (equal body (quote (
progn)))) (list (quote return) (list (quote nreverse) (car v))) (if (and (
eqcar body name) (equal (length (cdr body)) (length args))) (progn (setq 
s!:r2i_simple_recurse t) (cons (quote progn) (append (s!:r2isteps args (cdr 
body) v) (list (list (quote go) lab))))) (if (eqcar body (quote cond)) (cons 
(quote cond) (s!:r2icond name args (cdr body) lab v)) (if (eqcar body (quote 
if)) (cons (quote if) (s!:r2iif name args (cdr body) lab v)) (if (eqcar body 
(quote when)) (cons (quote when) (s!:r2iwhen name args (cdr body) lab v)) (if
(eqcar body (quote cons)) (s!:r2icons name args (cadr body) (caddr body) lab
v) (if (or (eqcar body (quote progn)) (eqcar body (quote prog2))) (cons (
quote progn) (s!:r2iprogn name args (cdr body) lab v)) (if (eqcar body (quote
and)) (s!:r2i1 name args (s!:r2iand (cdr body)) lab v) (if (eqcar body (
quote or)) (s!:r2i1 name args (s!:r2ior (cdr body)) lab v) (list (quote 
return) (list (quote nreverse) (car v) body))))))))))))

(de s!:r2iand (l) (if (null l) t (if (null (cdr l)) (car l) (list (quote cond
) (list (car l) (s!:r2iand (cdr l)))))))

(de s!:r2ior (l) (if (null l) nil (cons (quote cond) (prog (var1153 var1154) 
(setq var1153 l) lab1152 (if (null var1153) (return (reversip var1154))) (
prog (x) (setq x (car var1153)) (setq var1154 (cons (list x) var1154))) (setq
var1153 (cdr var1153)) (go lab1152)))))

(de s!:r2icond (name args b lab v) (if (null b) (list (list t (list (quote 
return) (list (quote nreverse) (car v))))) (if (null (cdar b)) (progn (if (
null (cdr v)) (rplacd v (list (gensym)))) (cons (list (list (quote setq) (
cadr v) (caar b)) (list (quote return) (list (quote nreverse) (car v) (cadr v
)))) (s!:r2icond name args (cdr b) lab v))) (if (eqcar (car b) t) (list (cons
t (s!:r2iprogn name args (cdar b) lab v))) (cons (cons (caar b) (s!:r2iprogn
name args (cdar b) lab v)) (s!:r2icond name args (cdr b) lab v))))))

(de s!:r2iif (name args b lab v) (if (null (cddr b)) (list (car b) (s!:r2i1 
name args (cadr b) lab v)) (list (car b) (s!:r2i1 name args (cadr b) lab v) (
s!:r2i1 name args (caddr b) lab v))))

(de s!:r2iwhen (name args b lab v) (cons (car b) (s!:r2iprogn name args (cdr 
b) lab v)))

(de s!:r2iprogn (name args b lab v) (if (null (cdr b)) (list (s!:r2i1 name 
args (car b) lab v)) (cons (car b) (s!:r2iprogn name args (cdr b) lab v))))

(de s!:r2icons (name args a d lab v) (if (eqcar d (quote cons)) (s!:r2icons2 
name args a (cadr d) (caddr d) lab v) (if (and (eqcar d name) (equal (length 
(cdr d)) (length args))) (progn (setq s!:r2i_cons_recurse t) (cons (quote 
progn) (cons (list (quote setq) (car v) (list (quote cons) a (car v))) (
append (s!:r2isteps args (cdr d) v) (list (list (quote go) lab)))))) (list (
quote return) (list (quote nreverse) (car v) (list (quote cons) a d))))))

(de s!:r2icons2 (name args a ad dd lab v) (if (and (eqcar dd name) (equal (
length (cdr dd)) (length args))) (progn (setq s!:r2i_cons_recurse t) (cons (
quote progn) (cons (list (quote setq) (car v) (list (quote cons) a (car v))) 
(cons (list (quote setq) (car v) (list (quote cons) ad (car v))) (append (
s!:r2isteps args (cdr dd) v) (list (list (quote go) lab))))))) (list (quote 
return) (list (quote nreverse) (car v) (list (quote cons) a (list (quote cons
) ad dd))))))

(de s!:r2isteps (vars vals v) (if (null vars) (if (null vals) nil (error 0 
"too many args in recursive call to self")) (if (null vals) (error 0 
"not enough args in recursive call to self") (if (equal (car vars) (car vals)
) (s!:r2isteps (cdr vars) (cdr vals) v) (if (s!:r2i_safestep (car vars) (cdr 
vars) (cdr vals)) (cons (list (quote setq) (car vars) (car vals)) (
s!:r2isteps (cdr vars) (cdr vals) v)) (prog (w) (if (null (cdr v)) (rplacd v 
(list (gensym)))) (setq v (cdr v)) (setq w (s!:r2isteps (cdr vars) (cdr vals)
v)) (return (cons (list (quote setq) (car v) (car vals)) (append w (list (
list (quote setq) (car vars) (car v))))))))))))

(de s!:r2i_safestep (x vars vals) (if (and (null vars) (null vals)) t (if (
s!:r2i_dependson (car vals) x) nil (s!:r2i_safestep x (cdr vars) (cdr vals)))
))

(de s!:r2i_dependson (e x) (if (equal e x) t (if (or (atom e) (eqcar e (quote
quote))) nil (if (not (atom (car e))) t (if (flagp (car e) (quote 
s!:r2i_safe)) (s!:r2i_list_dependson (cdr e) x) (if (or (fluidp x) (globalp x
)) t (if (or (flagp (car e) (quote s!:r2i_unsafe)) (macro!-function (car e)))
t (s!:r2i_list_dependson (cdr e) x))))))))

(flag (quote (car cdr caar cadr cdar cddr caaar caadr cadar caddr cdaar cdadr
cddar cdddr cons ncons rcons acons list list2 list3 list!* add1 sub1 plus 
plus2 times times2 difference minus quotient append reverse nreverse null not
assoc atsoc member memq subst sublis subla pair prog1 prog2 progn)) (quote 
s!:r2i_safe))

(flag (quote (cond if when case de defun dm defmacro prog let let!* flet and 
or)) (quote s!:r2i_unsafe))

(de s!:r2i_list_dependson (l x) (if (null l) nil (if (s!:r2i_dependson (car l
) x) t (s!:r2i_list_dependson (cdr l) x))))

(de s!:r2i2 (name args body lab v) (if (or (null body) (equal body (quote (
progn)))) (list (quote return) nil) (if (and (eqcar body name) (equal (length
(cdr body)) (length args))) (progn (cons (quote progn) (append (s!:r2isteps 
args (cdr body) v) (list (list (quote go) lab))))) (if (eqcar body (quote 
cond)) (cons (quote cond) (s!:r2i2cond name args (cdr body) lab v)) (if (
eqcar body (quote if)) (cons (quote if) (s!:r2i2if name args (cdr body) lab v
)) (if (eqcar body (quote when)) (cons (quote when) (s!:r2i2when name args (
cdr body) lab v)) (if (or (eqcar body (quote progn)) (eqcar body (quote prog2
))) (cons (quote progn) (s!:r2i2progn name args (cdr body) lab v)) (if (eqcar
body (quote and)) (s!:r2i2 name args (s!:r2iand (cdr body)) lab v) (if (
eqcar body (quote or)) (s!:r2i2 name args (s!:r2ior (cdr body)) lab v) (list 
(quote return) body))))))))))

(de s!:r2i2cond (name args b lab v) (if (null b) (list (list t (list (quote 
return) nil))) (if (null (cdar b)) (progn (if (null (cdr v)) (rplacd v (list 
(gensym)))) (cons (list (list (quote setq) (cadr v) (caar b)) (list (quote 
return) (cadr v))) (s!:r2i2cond name args (cdr b) lab v))) (if (eqcar (car b)
t) (list (cons t (s!:r2i2progn name args (cdar b) lab v))) (cons (cons (caar
b) (s!:r2i2progn name args (cdar b) lab v)) (s!:r2i2cond name args (cdr b) 
lab v))))))

(de s!:r2i2if (name args b lab v) (if (null (cddr b)) (list (car b) (s!:r2i2 
name args (cadr b) lab v)) (list (car b) (s!:r2i2 name args (cadr b) lab v) (
s!:r2i2 name args (caddr b) lab v))))

(de s!:r2i2when (name args b lab v) (cons (car b) (s!:r2i2progn name args (
cdr b) lab v)))

(de s!:r2i2progn (name args b lab v) (if (null (cdr b)) (list (s!:r2i2 name 
args (car b) lab v)) (cons (car b) (s!:r2i2progn name args (cdr b) lab v))))

(de s!:r2i3 (name args body lab v) (prog (v v1 v2 lab1 lab2 lab3 w P Q g R) (
if (s!:any_fluid args) (return body)) (if (eqcar body (quote cond)) (progn (
if (not (setq w (cdr body))) (return body)) (setq P (car w)) (setq w (cdr w))
(if (null P) (return body)) (setq Q (cdr P)) (setq P (car P)) (if (or (null 
Q) (cdr Q)) (return body)) (setq Q (car Q)) (if (or (null w) (cdr w)) (return
body)) (setq w (car w)) (if (not (eqcar w t)) (return body)) (setq w (cdr w)
) (if (or (not w) (cdr w)) (return body)) (setq w (car w))) (if (eqcar body (
quote if)) (progn (setq w (cdr body)) (setq P (car w)) (setq w (cdr w)) (setq
Q (car w)) (setq w (cdr w)) (if (null w) (return body)) (setq w (car w))) (
return body))) (if (or (atom w) (atom (cdr w)) (atom (cddr w)) (cdddr w)) (
return body)) (setq g (car w)) (setq R (cadr w)) (setq w (caddr w)) (if (not 
(atom g)) (return body)) (if (member g (quote (and or progn prog1 prog2 cond 
if when))) (return body)) (if (not (eqcar w name)) (return body)) (setq w (
cdr w)) (if (not (equal (length w) (length args))) (return body)) (setq v1 (
gensym)) (setq v2 (gensym)) (setq v (list v2)) (setq lab1 (gensym)) (setq 
lab2 (gensym)) (setq lab3 (gensym)) (setq w (s!:r2isteps args w v)) (setq w (
list (quote prog) (cons v1 v) lab1 (list (quote cond) (list P (list (quote go
) lab2))) (list (quote setq) v1 (list (quote cons) R v1)) (cons (quote progn)
w) (list (quote go) lab1) lab2 (list (quote setq) v2 Q) lab3 (list (quote 
cond) (list (list (quote null) v1) (list (quote return) v2))) (list (quote 
setq) v2 (list g (list (quote car) v1) v2)) (list (quote setq) v1 (list (
quote cdr) v1)) (list (quote go) lab3))) (return w)))

(de s!:any_fluid (l) (if (null l) nil (if (fluidp (car l)) t (s!:any_fluid (
cdr l)))))

(de s!:compile1 (name args body s!:lexical_env) (prog (w aargs oargs oinit 
restarg svars nargs nopts env fluids s!:current_function s!:current_label 
s!:current_block s!:current_size s!:current_procedure s!:current_exitlab 
s!:current_proglabels s!:other_defs local_decs s!:has_closure s!:local_macros
s!:recent_literals s!:a_reg_values w1 w2 s!:current_count) (setq 
s!:current_function name) (setq s!:current_count 0) (if !*where_defined!* (
progn (setq w name) (puthash w !*where_defined!* (where!-was!-that)))) (setq 
body (s!:find_local_decs body)) (setq local_decs (car body)) (setq body (cdr 
body)) (if (atom body) (setq body nil) (if (null (cdr body)) (setq body (car 
body)) (setq body (cons (quote progn) body)))) (setq nargs (setq nopts 0)) (
prog nil lab1155 (if (null (and args (not (eqcar args (quote !&optional))) (
not (eqcar args (quote !&rest))))) (return nil)) (progn (if (or (equal (car 
args) (quote !&key)) (equal (car args) (quote !&aux))) (error 0 "&key/&aux"))
(setq aargs (cons (car args) aargs)) (setq nargs (plus nargs 1)) (setq args 
(cdr args))) (go lab1155)) (if (eqcar args (quote !&optional)) (progn (setq 
args (cdr args)) (prog nil lab1157 (if (null (and args (not (eqcar args (
quote !&rest))))) (return nil)) (progn (if (or (equal (car args) (quote !&key
)) (equal (car args) (quote !&aux))) (error 0 "&key/&aux")) (setq w (car args
)) (prog nil lab1156 (if (null (and (not (atom w)) (or (atom (cdr w)) (equal 
(cdr w) (quote (nil)))))) (return nil)) (setq w (car w)) (go lab1156)) (setq 
args (cdr args)) (setq oargs (cons w oargs)) (setq nopts (plus nopts 1)) (if 
(atom w) (setq aargs (cons w aargs)) (progn (setq oinit t) (setq aargs (cons 
(car w) aargs)) (if (not (atom (cddr w))) (setq svars (cons (caddr w) svars))
)))) (go lab1157)))) (if (eqcar args (quote !&rest)) (progn (setq w (cadr 
args)) (setq aargs (cons w aargs)) (setq restarg w) (setq args (cddr args)) (
if args (error 0 "&rest arg not at end")))) (setq args (reverse aargs)) (setq
oargs (reverse oargs)) (prog (var1159) (setq var1159 (append svars args)) 
lab1158 (if (null var1159) (return nil)) (prog (v) (setq v (car var1159)) (
progn (if (globalp v) (progn (if !*pwrds (progn (if (neq (posn) 0) (terpri)) 
(princ "+++++ global ") (prin v) (princ " converted to fluid") (terpri))) (
unglobal (list v)) (fluid (list v)))))) (setq var1159 (cdr var1159)) (go 
lab1158)) (if oinit (return (s!:compile2 name nargs nopts args oargs restarg 
body local_decs))) (setq w nil) (prog (var1161) (setq var1161 args) lab1160 (
if (null var1161) (return nil)) (prog (v) (setq v (car var1161)) (setq w (
s!:instate_local_decs v local_decs w))) (setq var1161 (cdr var1161)) (go 
lab1160)) (if (and !*r2i (null oargs) (null restarg)) (setq body (s!:r2i name
args body))) (prog (v) (setq v args) lab1162 (if (null v) (return nil)) (
progn (if (fluidp (car v)) (prog (g) (setq g (gensym)) (setq fluids (cons (
cons (car v) g) fluids)) (rplaca v g)))) (setq v (cdr v)) (go lab1162)) (if 
fluids (progn (setq body (list (list (quote return) body))) (prog (var1164) (
setq var1164 fluids) lab1163 (if (null var1164) (return nil)) (prog (v) (setq
v (car var1164)) (setq body (cons (list (quote setq) (car v) (cdr v)) body))
) (setq var1164 (cdr var1164)) (go lab1163)) (setq body (cons (quote prog) (
cons (prog (var1166 var1167) (setq var1166 fluids) lab1165 (if (null var1166)
(return (reversip var1167))) (prog (v) (setq v (car var1166)) (setq var1167 
(cons (car v) var1167))) (setq var1166 (cdr var1166)) (go lab1165)) body)))))
(setq env (cons (mkhash 10 (if s!:faslmod_name 2 1) 1.5) (reverse args))) (
puthash name (car env) (cons 10000000 nil)) (setq w (s!:residual_local_decs 
local_decs w)) (s!:start_procedure nargs nopts restarg) (setq w1 body) more (
if (atom w1) nil (if (and (equal (car w1) (quote block)) (equal (length w1) 3
)) (progn (setq w1 (caddr w1)) (go more)) (if (and (equal (car w1) (quote 
progn)) (equal (length w1) 2)) (progn (setq w1 (cadr w1)) (go more)) (if (and
(atom (setq w2 (car w1))) (setq w2 (get w2 (quote s!:newname)))) (progn (
setq w1 (cons w2 (cdr w1))) (go more)) (if (and (atom (setq w2 (car w1))) (
setq w2 (macro!-function w2))) (progn (setq w1 (funcall w2 w1)) (go more)))))
)) (if (not (equal (setq w2 (s!:improve w1)) w1)) (progn (setq w1 w2) (go 
more))) (if (and (not (atom w1)) (atom (car w1)) (not (special!-form!-p (car 
w1))) (s!:subargs args (cdr w1)) (leq nargs 3) (equal nopts 0) (not restarg) 
(leq (length (cdr w1)) nargs)) (progn (s!:cancel_local_decs w) (if restarg (
setq nopts (plus nopts 512))) (setq nopts (plus nopts (times 1024 (length w1)
))) (setq nargs (plus nargs (times 256 nopts))) (if !*pwrds (progn (if (neq (
posn) 0) (terpri)) (princ "+++ ") (prin name) (princ " compiled as link to ")
(princ (car w1)) (terpri))) (return (cons (cons name (cons nargs (cons nil (
car w1)))) s!:other_defs)))) (s!:comval body env 0) (s!:cancel_local_decs w) 
(if restarg (setq nopts (plus nopts 512))) (setq nargs (plus nargs (times 256
nopts))) (return (cons (cons name (cons nargs (s!:endprocedure name env))) 
s!:other_defs))))

(de s!:compile2 (name nargs nopts args oargs restarg body local_decs) (prog (
fluids env penv g v init atend w) (prog (var1169) (setq var1169 args) lab1168
(if (null var1169) (return nil)) (prog (v) (setq v (car var1169)) (progn (
setq env (cons 0 env)) (setq penv (cons env penv)))) (setq var1169 (cdr 
var1169)) (go lab1168)) (setq env (cons (mkhash 10 (if s!:faslmod_name 2 1) 
1.5) env)) (puthash name (car env) (cons 10000000 nil)) (setq penv (reversip 
penv)) (if restarg (setq oargs (append oargs (quote (0))))) (prog (i) (setq i
1) lab1170 (if (minusp (times 1 (difference nargs i))) (return nil)) (setq 
oargs (cons 0 oargs)) (setq i (plus i 1)) (go lab1170)) (s!:start_procedure 
nargs nopts restarg) (prog nil lab1171 (if (null args) (return nil)) (progn (
setq v (car args)) (setq init (car oargs)) (if (equal init 0) (progn (setq w 
(s!:instate_local_decs v local_decs w)) (if (fluidp v) (progn (setq g (gensym
)) (rplaca (car penv) g) (s!:outopcode1lit (quote FREEBIND) (s!:vecof (list v
)) env) (rplacd env (cons 3 (cons 0 (cons 0 (cdr env))))) (setq atend (cons (
quote FREERSTR) atend)) (s!:comval (list (quote setq) v g) env 2)) (rplaca (
car penv) v))) (prog (ival sp l1 l2) (if (not (atom init)) (progn (setq init 
(cdr init)) (setq ival (car init)) (if (not (atom (cdr init))) (setq sp (cadr
init))))) (setq l1 (gensym)) (setq g (gensym)) (rplaca (car penv) g) (if (
and (null ival) (null sp)) (s!:comval (list (quote setq) g (list (quote 
spid!-to!-nil) g)) env 1) (progn (s!:jumpif nil (list (quote is!-spid) g) env
l1) (s!:comval (list (quote setq) g ival) env 1) (if sp (progn (if (fluidp 
sp) (progn (s!:outopcode1lit (quote FREEBIND) (s!:vecof (list sp)) env) (
s!:outjump (quote JUMP) (setq l2 (gensym))) (s!:set_label l1) (
s!:outopcode1lit (quote FREEBIND) (s!:vecof (list sp)) env) (rplacd env (cons
3 (cons 0 (cons 0 (cdr env))))) (s!:comval (list (quote setq) sp t) env 1) (
s!:set_label l2) (setq atend (cons (quote FREERSTR) atend))) (progn (
s!:outopcode0 (quote PUSHNIL) (quote (PUSHNIL))) (s!:outjump (quote JUMP) (
setq l2 (gensym))) (s!:set_label l1) (s!:loadliteral t env) (s!:outopcode0 (
quote PUSH) (quote (PUSH))) (s!:set_label l2) (rplacd env (cons sp (cdr env))
) (setq atend (cons (quote LOSE) atend))))) (s!:set_label l1)))) (setq w (
s!:instate_local_decs v local_decs w)) (if (fluidp v) (progn (
s!:outopcode1lit (quote FREEBIND) (s!:vecof (list v)) env) (rplacd env (cons 
3 (cons 0 (cons 0 (cdr env))))) (s!:comval (list (quote setq) v g) env 1) (
setq atend (cons (quote FREERSTR) atend))) (rplaca (car penv) v)))) (setq 
args (cdr args)) (setq oargs (cdr oargs)) (setq penv (cdr penv))) (go lab1171
)) (setq w (s!:residual_local_decs local_decs w)) (s!:comval body env 0) (
prog nil lab1172 (if (null atend) (return nil)) (progn (s!:outopcode0 (car 
atend) (list (car atend))) (setq atend (cdr atend))) (go lab1172)) (
s!:cancel_local_decs w) (setq nopts (plus nopts 256)) (if restarg (setq nopts
(plus nopts 512))) (setq nargs (plus nargs (times 256 nopts))) (return (cons
(cons name (cons nargs (s!:endprocedure name env))) s!:other_defs))))

(de compile!-all nil (prog (var1174) (setq var1174 (oblist)) lab1173 (if (
null var1174) (return nil)) (prog (x) (setq x (car var1174)) (prog (w) (setq 
w (getd x)) (if (and (or (eqcar w (quote expr)) (eqcar w (quote macro))) (
eqcar (cdr w) (quote lambda))) (progn (princ "Compile: ") (prin x) (terpri) (
errorset (list (quote compile) (mkquote (list x))) t t))))) (setq var1174 (
cdr var1174)) (go lab1173)))

(flag (quote (rds deflist flag fluid global remprop remflag unfluid unglobal 
dm defmacro carcheck faslend c_end)) (quote eval))

(flag (quote (rds)) (quote ignore))

(fluid (quote (!*backtrace)))

(de s!:fasl_supervisor nil (prog (u w !*echo) top (setq u (errorset (quote (
read)) t !*backtrace)) (if (atom u) (return nil)) (setq u (car u)) (if (equal
u !$eof!$) (return nil)) (if (not (atom u)) (setq u (macroexpand u))) (if (
atom u) (go top) (if (eqcar u (quote faslend)) (return (apply (quote faslend)
nil)) (if (eqcar u (quote rdf)) (progn (setq w (open (setq u (eval (cadr u))
) (quote input))) (if w (progn (terpri) (princ "Reading file ") (prin u) (
terpri) (setq w (rds w)) (s!:fasl_supervisor) (princ "End of file ") (prin u)
(terpri) (close (rds w))) (progn (princ "Failed to open file ") (prin u) (
terpri)))) (s!:fslout0 u)))) (go top)))

(de s!:fslout0 (u) (s!:fslout1 u nil))

(de s!:fslout1 (u loadonly) (prog (w) (if (not (atom u)) (setq u (macroexpand
u))) (if (atom u) (return nil) (if (eqcar u (quote progn)) (progn (prog (
var1176) (setq var1176 (cdr u)) lab1175 (if (null var1176) (return nil)) (
prog (v) (setq v (car var1176)) (s!:fslout1 v loadonly)) (setq var1176 (cdr 
var1176)) (go lab1175)) (return nil)) (if (eqcar u (quote eval!-when)) (
return (prog nil (setq w (cadr u)) (setq u (cons (quote progn) (cddr u))) (if
(and (memq (quote compile) w) (not loadonly)) (eval u)) (if (memq (quote 
load) w) (s!:fslout1 u t)) (return nil))) (if (or (flagp (car u) (quote eval)
) (and (equal (car u) (quote setq)) (not (atom (caddr u))) (flagp (caaddr u) 
(quote eval)))) (if (not loadonly) (errorset u t !*backtrace)))))) (if (eqcar
u (quote rdf)) (prog nil (setq w (open (setq u (eval (cadr u))) (quote input
))) (if w (progn (princ "Reading file ") (prin u) (terpri) (setq w (rds w)) (
s!:fasl_supervisor) (princ "End of file ") (prin u) (terpri) (close (rds w)))
(progn (princ "Failed to open file ") (prin u) (terpri)))) (if !*nocompile (
progn (if (and (not (eqcar u (quote faslend))) (not (eqcar u (quote carcheck)
))) (write!-module u))) (if (or (eqcar u (quote de)) (eqcar u (quote defun)))
(progn (setq u (cdr u)) (if (and (setq w (get (car u) (quote c!-version))) (
equal w (md60 (cons (cadr u) (s!:fully_macroexpand_list (cddr u)))))) (progn 
(princ "+++ ") (prin (car u)) (printc " not compiled (C version available)") 
(write!-module (list (quote restore!-c!-code) (mkquote (car u))))) (if (flagp
(car u) (quote lose)) (progn (princ "+++ ") (prin (car u)) (printc 
" not compiled (LOSE flag)")) (prog (var1178) (setq var1178 (s!:compile1 (car
u) (cadr u) (cddr u) nil)) lab1177 (if (null var1178) (return nil)) (prog (p
) (setq p (car var1178)) (s!:fslout2 p u)) (setq var1178 (cdr var1178)) (go 
lab1177))))) (if (or (eqcar u (quote dm)) (eqcar u (quote defmacro))) (prog (
g) (setq g (hashtagged!-name (cadr u) (cddr u))) (setq u (cdr u)) (if (flagp 
(car u) (quote lose)) (progn (princ "+++ ") (prin (car u)) (printc 
" not compiled (LOSE flag)") (return nil))) (setq w (cadr u)) (if (and w (
null (cdr w))) (setq w (cons (car w) (cons (quote !&optional) (cons (gensym) 
nil))))) (prog (var1180) (setq var1180 (s!:compile1 g w (cddr u) nil)) 
lab1179 (if (null var1180) (return nil)) (prog (p) (setq p (car var1180)) (
s!:fslout2 p u)) (setq var1180 (cdr var1180)) (go lab1179)) (write!-module (
list (quote dm) (car u) (quote (u !&optional e)) (list g (quote u) (quote e))
))) (if (eqcar u (quote putd)) (prog (a1 a2 a3) (setq a1 (cadr u)) (setq a2 (
caddr u)) (setq a3 (cadddr u)) (if (and (eqcar a1 (quote quote)) (or (equal 
a2 (quote (quote expr))) (equal a2 (quote (quote macro)))) (or (eqcar a3 (
quote quote)) (eqcar a3 (quote function))) (eqcar (cadr a3) (quote lambda))) 
(progn (setq a1 (cadr a1)) (setq a2 (cadr a2)) (setq a3 (cadr a3)) (setq u (
cons (if (equal a2 (quote expr)) (quote de) (quote dm)) (cons a1 (cdr a3)))) 
(s!:fslout1 u loadonly)) (write!-module u))) (if (and (not (eqcar u (quote 
faslend))) (not (eqcar u (quote carcheck)))) (write!-module u)))))))))

(de s!:fslout2 (p u) (prog (name nargs code env w) (setq name (car p)) (setq 
nargs (cadr p)) (setq code (caddr p)) (setq env (cdddr p)) (if (and !*savedef
(equal name (car u))) (progn (define!-in!-module (minus 1)) (write!-module (
cons (quote lambda) (cons (cadr u) (s!:fully_macroexpand_list (cddr u))))))) 
(setq w (irightshift nargs 18)) (setq nargs (logand nargs 262143)) (if (not (
equal w 0)) (setq code (difference w 1))) (define!-in!-module nargs) (
write!-module name) (write!-module code) (write!-module env)))

(de faslend nil (prog nil (if (null s!:faslmod_name) (return nil)) (
start!-module nil) (setq dfprint!* s!:dfprintsave) (setq !*defn nil) (setq 
!*comp (cdr s!:faslmod_name)) (setq s!:faslmod_name nil) (return nil)))

(put (quote faslend) (quote stat) (quote endstat))

(de faslout (u) (prog nil (terpri) (princ "FASLOUT ") (prin u) (princ 
": IN files;  or type in expressions") (terpri) (princ 
"When all done, execute FASLEND;") (terpri) (if (not (atom u)) (setq u (car u
))) (if (not (start!-module u)) (progn (if (neq (posn) 0) (terpri)) (princ 
"+++ Failed to open FASL output file") (terpri) (return nil))) (setq 
s!:faslmod_name (cons u !*comp)) (setq s!:dfprintsave dfprint!*) (setq 
dfprint!* (quote s!:fslout0)) (setq !*defn t) (setq !*comp nil) (if (getd (
quote begin)) (return nil)) (s!:fasl_supervisor)))

(put (quote faslout) (quote stat) (quote rlis))

(de s!:c_supervisor nil (prog (u w !*echo) top (setq u (errorset (quote (read
)) t !*backtrace)) (if (atom u) (return nil)) (setq u (car u)) (if (equal u 
!$eof!$) (return nil)) (if (not (atom u)) (setq u (macroexpand u))) (if (atom
u) (go top) (if (eqcar u (quote c_end)) (return (apply (quote c_end) nil)) (
if (eqcar u (quote rdf)) (progn (setq w (open (setq u (eval (cadr u))) (quote
input))) (if w (progn (terpri) (princ "Reading file ") (prin u) (terpri) (
setq w (rds w)) (s!:c_supervisor) (princ "End of file ") (prin u) (terpri) (
close (rds w))) (progn (princ "Failed to open file ") (prin u) (terpri)))) (
s!:cout0 u)))) (go top)))

(de s!:cout0 (u) (s!:cout1 u nil))

(de s!:cout1 (u loadonly) (prog (s!:into_c) (setq s!:into_c t) (if (not (atom
u)) (setq u (macroexpand u))) (if (atom u) (return nil) (if (eqcar u (quote 
progn)) (progn (prog (var1182) (setq var1182 (cdr u)) lab1181 (if (null 
var1182) (return nil)) (prog (v) (setq v (car var1182)) (s!:cout1 v loadonly)
) (setq var1182 (cdr var1182)) (go lab1181)) (return nil)) (if (eqcar u (
quote eval!-when)) (return (prog (w) (setq w (cadr u)) (setq u (cons (quote 
progn) (cddr u))) (if (and (memq (quote compile) w) (not loadonly)) (eval u))
(if (memq (quote load) w) (s!:cout1 u t)) (return nil))) (if (or (flagp (car
u) (quote eval)) (and (equal (car u) (quote setq)) (not (atom (caddr u))) (
flagp (caaddr u) (quote eval)))) (if (not loadonly) (errorset u t !*backtrace
)))))) (if (eqcar u (quote rdf)) (prog (w) (setq w (open (setq u (eval (cadr 
u))) (quote input))) (if w (progn (princ "Reading file ") (prin u) (terpri) (
setq w (rds w)) (s!:c_supervisor) (princ "End of file ") (prin u) (terpri) (
close (rds w))) (progn (princ "Failed to open file ") (prin u) (terpri)))) (
if (or (eqcar u (quote de)) (eqcar u (quote defun))) (prog (w) (setq u (cdr u
)) (setq w (s!:compile1 (car u) (cadr u) (cddr u) nil)) (prog (var1184) (setq
var1184 w) lab1183 (if (null var1184) (return nil)) (prog (p) (setq p (car 
var1184)) (s!:cgen (car p) (cadr p) (caddr p) (cdddr p))) (setq var1184 (cdr 
var1184)) (go lab1183))) (if (or (eqcar u (quote dm)) (eqcar u (quote 
defmacro))) (prog (w g) (setq g (hashtagged!-name (cadr u) (cddr u))) (setq u
(cdr u)) (setq w (cadr u)) (if (and w (null (cdr w))) (setq w (cons (car w) 
(cons (quote !&optional) (cons (gensym) nil))))) (setq w (s!:compile1 g w (
cddr u) nil)) (prog (var1186) (setq var1186 w) lab1185 (if (null var1186) (
return nil)) (prog (p) (setq p (car var1186)) (s!:cgen (car p) (cadr p) (
caddr p) (cdddr p))) (setq var1186 (cdr var1186)) (go lab1185)) (s!:cinit (
list (quote dm) (car u) (quote (u !&optional e)) (list g (quote u) (quote e))
))) (if (eqcar u (quote putd)) (prog (a1 a2 a3) (setq a1 (cadr u)) (setq a2 (
caddr u)) (setq a3 (cadddr u)) (if (and (eqcar a1 (quote quote)) (or (equal 
a2 (quote (quote expr))) (equal a2 (quote (quote macro)))) (or (eqcar a3 (
quote quote)) (eqcar a3 (quote function))) (eqcar (cadr a3) (quote lambda))) 
(progn (setq a1 (cadr a1)) (setq a2 (cadr a2)) (setq a3 (cadr a3)) (setq u (
cons (if (equal a2 (quote expr)) (quote de) (quote dm)) (cons a1 (cdr a3)))) 
(s!:cout1 u loadonly)) (s!:cinit u))) (if (and (not (eqcar u (quote c_end))) 
(not (eqcar u (quote carcheck)))) (s!:cinit u))))))))

(fluid (quote (s!:cmod_name)))

(de c_end nil (prog nil (if (null s!:cmod_name) (return nil)) (s!:cend) (setq
dfprint!* s!:dfprintsave) (setq !*defn nil) (setq !*comp (cdr s!:cmod_name))
(setq s!:cmod_name nil) (return nil)))

(put (quote c_end) (quote stat) (quote endstat))

(de c_out (u) (prog nil (terpri) (princ "C_OUT ") (prin u) (princ 
": IN files;  or type in expressions") (terpri) (princ 
"When all done, execute C_END;") (terpri) (if (not (atom u)) (setq u (car u))
) (if (null (s!:cstart u)) (progn (if (neq (posn) 0) (terpri)) (princ 
"+++ Failed to open C output file") (terpri) (return nil))) (setq 
s!:cmod_name (cons u !*comp)) (setq s!:dfprintsave dfprint!*) (setq dfprint!*
(quote s!:cout0)) (setq !*defn t) (setq !*comp nil) (if (getd (quote begin))
(return nil)) (s!:c_supervisor)))

(put (quote c_out) (quote stat) (quote rlis))

(de s!:compile!-file!* (fromfile !&optional tofile verbose !*pwrds) (prog (
!*comp w save) (if (null tofile) (setq tofile fromfile)) (if verbose (progn (
if (neq (posn) 0) (terpri)) (princ "+++ Compiling file ") (prin fromfile) (
terpri) (setq save (verbos nil)) (verbos (ilogand save 4)))) (if (not (
start!-module tofile)) (progn (if (neq (posn) 0) (terpri)) (princ 
"+++ Failed to open FASL output file") (terpri) (if save (verbos save)) (
return nil))) (setq w (open fromfile (quote input))) (if w (progn (setq w (
rds w)) (s!:fasl_supervisor) (close (rds w))) (progn (princ 
"Failed to open file ") (prin fromfile) (terpri))) (if save (verbos save)) (
start!-module nil) (if verbose (progn (if (neq (posn) 0) (terpri)) (princ 
"+++ Compilation complete") (terpri))) (return t)))

(de compile!-file!* (fromfile !&optional tofile) (s!:compile!-file!* fromfile
tofile t t))

(de compd (name type defn) (prog (g !*comp) (setq !*comp t) (if (eqcar defn (
quote lambda)) (progn (setq g (dated!-name type)) (symbol!-set!-definition g 
defn) (compile (list g)) (setq defn g))) (put name type defn) (return name)))

(de s!:compile0 (name) (prog (w args defn) (setq defn (getd name)) (if (and (
eqcar defn (quote macro)) (eqcar (cdr defn) (quote lambda))) (prog (!*comp lx
vx bx) (setq lx (cdr defn)) (if (not (or (and (equal (length lx) 3) (not (
atom (setq bx (caddr lx)))) (equal (cadr lx) (cdr bx))) (and (equal (length 
lx) 3) (not (atom (setq bx (caddr lx)))) (not (atom (cadr lx))) (eqcar (cdadr
lx) (quote !&optional)) (not (atom (setq bx (cdr bx)))) (equal (caadr lx) (
car bx)) (equal (cddadr lx) (cdr bx))))) (progn (setq w (hashtagged!-name 
name defn)) (symbol!-set!-definition w (cdr defn)) (s!:compile0 w) (if (equal
1 (length (cadr lx))) (symbol!-set!-env name (list (quote (u !&optional env)
) (list w (quote u)))) (symbol!-set!-env name (list (quote (u !&optional env)
) (list w (quote u) (quote env)))))))) (if (or (not (eqcar defn (quote expr))
) (not (eqcar (cdr defn) (quote lambda)))) (progn (if !*pwrds (progn (if (neq
(posn) 0) (terpri)) (princ "+++ ") (prin name) (princ " not compilable") (
terpri)))) (progn (setq args (cddr defn)) (setq defn (cdr args)) (setq args (
car args)) (if (stringp args) (progn (if !*pwrds (progn (if (neq (posn) 0) (
terpri)) (princ "+++ ") (prin name) (princ " was already compiled") (terpri))
)) (progn (if !*savedef (put name (quote !*savedef) (cons (quote lambda) (
cons args (s!:fully_macroexpand_list defn))))) (setq w (s!:compile1 name args
defn nil)) (prog (var1188) (setq var1188 w) lab1187 (if (null var1188) (
return nil)) (prog (p) (setq p (car var1188)) (symbol!-set!-definition (car p
) (cdr p))) (setq var1188 (cdr var1188)) (go lab1187)))))))))

(de s!:fully_macroexpand_list (l) (if (atom l) l (prog (var1190 var1191) (
setq var1190 l) lab1189 (if (null var1190) (return (reversip var1191))) (prog
(u) (setq u (car var1190)) (setq var1191 (cons (s!:fully_macroexpand u) 
var1191))) (setq var1190 (cdr var1190)) (go lab1189))))

(de s!:fully_macroexpand (x) (prog (helper) (if (or (atom x) (eqcar x (quote 
quote))) (return x) (if (eqcar (car x) (quote lambda)) (return (cons (cons (
quote lambda) (cons (cadar x) (s!:fully_macroexpand_list (cddar x)))) (
s!:fully_macroexpand_list (cdr x)))) (if (setq helper (get (car x) (quote 
s!:newname))) (return (s!:fully_macroexpand (cons helper (cdr x)))) (if (setq
helper (get (car x) (quote s!:expandfn))) (return (funcall helper x)) (if (
setq helper (macro!-function (car x))) (return (s!:fully_macroexpand (funcall
helper x))) (return (cons (car x) (s!:fully_macroexpand_list (cdr x)))))))))
))

(de s!:expandfunction (u) u)

(de s!:expandflet (u) (cons (car u) (cons (prog (var1193 var1194) (setq 
var1193 (cadr u)) lab1192 (if (null var1193) (return (reversip var1194))) (
prog (b) (setq b (car var1193)) (setq var1194 (cons (s!:expandfletvars b) 
var1194))) (setq var1193 (cdr var1193)) (go lab1192)) (
s!:fully_macroexpand_list (cddr u)))))

(de s!:expandfletvars (b) (cons (car b) (cons (cadr b) (
s!:fully_macroexpand_list (cddr b)))))

(de s!:expandlabels (u) (s!:expandflet u))

(de s!:expandmacrolet (u) (s!:expandflet u))

(de s!:expandprog (u) (cons (car u) (cons (cadr u) (s!:fully_macroexpand_list
(cddr u)))))

(de s!:expandtagbody (u) (s!:fully_macroexpand_list u))

(de s!:expandprogv (u) (cons (car u) (cons (cadr u) (cons (caddr u) (
s!:fully_macroexpand_list (cadddr u))))))

(de s!:expandblock (u) (cons (car u) (cons (cadr u) (
s!:fully_macroexpand_list (cddr u)))))

(de s!:expanddeclare (u) u)

(de s!:expandlet (u) (cons (car u) (cons (prog (var1196 var1197) (setq 
var1196 (cadr u)) lab1195 (if (null var1196) (return (reversip var1197))) (
prog (x) (setq x (car var1196)) (setq var1197 (cons (
s!:fully_macroexpand_list x) var1197))) (setq var1196 (cdr var1196)) (go 
lab1195)) (s!:fully_macroexpand_list (cddr u)))))

(de s!:expandlet!* (u) (s!:expandlet u))

(de s!:expandgo (u) u)

(de s!:expandreturn!-from (u) (cons (car u) (cons (cadr u) (
s!:fully_macroexpand_list (cddr u)))))

(de s!:expandcond (u) (cons (car u) (prog (var1199 var1200) (setq var1199 (
cdr u)) lab1198 (if (null var1199) (return (reversip var1200))) (prog (x) (
setq x (car var1199)) (setq var1200 (cons (s!:fully_macroexpand_list x) 
var1200))) (setq var1199 (cdr var1199)) (go lab1198))))

(de s!:expandcase (u) (cons (car u) (cons (s!:fully_macroexpand (cadr u)) (
prog (var1202 var1203) (setq var1202 (cddr u)) lab1201 (if (null var1202) (
return (reversip var1203))) (prog (x) (setq x (car var1202)) (setq var1203 (
cons (cons (car x) (s!:fully_macroexpand_list (cdr x))) var1203))) (setq 
var1202 (cdr var1202)) (go lab1201)))))

(de s!:expandeval!-when (u) (cons (car u) (cons (cadr u) (
s!:fully_macroexpand_list (cddr u)))))

(de s!:expandthe (u) (cons (car u) (cons (cadr u) (s!:fully_macroexpand_list 
(cddr u)))))

(de s!:expandmv!-call (u) (cons (car u) (cons (cadr u) (
s!:fully_macroexpand_list (cddr u)))))

(put (quote function) (quote s!:expandfn) (function s!:expandfunction))

(put (quote flet) (quote s!:expandfn) (function s!:expandflet))

(put (quote labels) (quote s!:expandfn) (function s!:expandlabels))

(put (quote macrolet) (quote s!:expandfn) (function s!:expandmacrolet))

(put (quote prog) (quote s!:expandfn) (function s!:expandprog))

(put (quote tagbody) (quote s!:expandfn) (function s!:expandtagbody))

(put (quote progv) (quote s!:expandfn) (function s!:expandprogv))

(put (quote !~block) (quote s!:expandfn) (function s!:expandblock))

(put (quote declare) (quote s!:expandfn) (function s!:expanddeclare))

(put (quote !~let) (quote s!:expandfn) (function s!:expandlet))

(put (quote let!*) (quote s!:expandfn) (function s!:expandlet!*))

(put (quote go) (quote s!:expandfn) (function s!:expandgo))

(put (quote return!-from) (quote s!:expandfn) (function s!:expandreturn!-from
))

(put (quote cond) (quote s!:expandfn) (function s!:expandcond))

(put (quote case) (quote s!:expandfn) (function s!:expandcase))

(put (quote eval!-when) (quote s!:expandfn) (function s!:expandeval!-when))

(put (quote the) (quote s!:expandfn) (function s!:expandthe))

(put (quote multiple!-value!-call) (quote s!:expandfn) (function 
s!:expandmv!-call))

(de compile (l) (prog nil (if (and (atom l) (not (null l))) (setq l (list l))
) (prog (var1205) (setq var1205 l) lab1204 (if (null var1205) (return nil)) (
prog (name) (setq name (car var1205)) (errorset (list (quote s!:compile0) (
mkquote name)) t t)) (setq var1205 (cdr var1205)) (go lab1204)) (return l)))


% end of file
