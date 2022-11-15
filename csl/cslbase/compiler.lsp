
% RLISP to LISP converter. A C Norman 2022


%%
%% Copyright (C) 2022, following the master REDUCE source files.          *
%%                                                                        *
%% Redistribution and use in source and binary forms, with or without     *
%% modification, are permitted provided that the following conditions are *
%% met:                                                                   *
%%                                                                        *
%%     * Redistributions of source code must retain the relevant          *
%%       copyright notice, this list of conditions and the following      *
%%       disclaimer.                                                      *
%%     * Redistributions in binary form must reproduce the above          *
%%       copyright notice, this list of conditions and the following      *
%%       disclaimer in the documentation and/or other materials provided  *
%%       with the distribution.                                           *
%%                                                                        *
%% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
%% "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
%% LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
%% FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
%% COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
%% INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
%% BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
%% OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
%% ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
%% TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
%% THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
%% DAMAGE.                                                                *
%%


% $Id$

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
CAARLOC3 CALL0 CALL1 CALL2 CALL2R CALL3 CALL4 CALL0_0 CALL0_1 CALL0_2 CALL0_3
CALL1_0 CALL1_1 CALL1_2 CALL1_3 CALL1_4 CALL1_5 CALL2_0 CALL2_1 CALL2_2 
CALL2_3 CALL2_4 BUILTIN0 BUILTIN1 BUILTIN2 BUILTIN2R BUILTIN3 APPLY1 APPLY2 
APPLY3 APPLY4 JCALL spare66 JUMP JUMP_B JUMP_L JUMP_BL JUMPNIL JUMPNIL_B 
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
BIGSTACK BIGCALL ICASE FASTGET ONEVALUE SPARE)))

(prog (n) (setq n 0) (prog (var1001) (setq var1001 s!:opcodelist) lab1000 (
cond ((null var1001) (return nil))) (prog (v) (setq v (car var1001)) (progn (
put v (quote s!:opcode) n) (setq n (plus n 1)))) (setq var1001 (cdr var1001))
(go lab1000)) (return (list n (quote opcodes) (quote allocated))))

(setq s!:opcodelist nil)

(fluid (quote (s!:env_alist)))

(de s!:vecof (l) (prog (w) (setq w (assoc l s!:env_alist)) (cond (w (return (
cdr w)))) (setq w (s!:vecof1 l)) (setq s!:env_alist (cons (cons l w) 
s!:env_alist)) (return w)))

(de s!:vecof1 (l) (prog (v n) (setq v (mkvect (sub1 (length l)))) (setq n 0) 
(prog (var1003) (setq var1003 l) lab1002 (cond ((null var1003) (return nil)))
(prog (x) (setq x (car var1003)) (progn (putv v n x) (setq n (plus n 1)))) (
setq var1003 (cdr var1003)) (go lab1002)) (return v)))

(progn (put (quote batchp) (quote s!:builtin0) 0) (put (quote date) (quote 
s!:builtin0) 1) (put (quote eject) (quote s!:builtin0) 2) (put (quote error1)
(quote s!:builtin0) 3) (put (quote gctime) (quote s!:builtin0) 4) (put (
quote lposn) (quote s!:builtin0) 6) (put (quote posn) (quote s!:builtin0) 8) 
(put (quote read) (quote s!:builtin0) 9) (put (quote readch) (quote 
s!:builtin0) 10) (put (quote terpri) (quote s!:builtin0) 11) (put (quote time
) (quote s!:builtin0) 12) (put (quote tyi) (quote s!:builtin0) 13) (put (
quote load!-spid) (quote s!:builtin0) 14) (put (quote abs) (quote s!:builtin1
) 0) (put (quote add1) (quote s!:builtin1) 1) (put (quote !1!+) (quote 
s!:builtin1) 1) (put (quote atan) (quote s!:builtin1) 2) (put (quote apply0) 
(quote s!:builtin1) 3) (put (quote atom) (quote s!:builtin1) 4) (put (quote 
boundp) (quote s!:builtin1) 5) (put (quote char!-code) (quote s!:builtin1) 6)
(put (quote close) (quote s!:builtin1) 7) (put (quote codep) (quote 
s!:builtin1) 8) (put (quote compress) (quote s!:builtin1) 9) (put (quote 
constantp) (quote s!:builtin1) 10) (put (quote digit) (quote s!:builtin1) 11)
(put (quote endp) (quote s!:builtin1) 12) (put (quote eval) (quote 
s!:builtin1) 13) (put (quote evenp) (quote s!:builtin1) 14) (put (quote evlis
) (quote s!:builtin1) 15) (put (quote explode) (quote s!:builtin1) 16) (put (
quote explode2lc) (quote s!:builtin1) 17) (put (quote explode2) (quote 
s!:builtin1) 18) (put (quote explodec) (quote s!:builtin1) 18) (put (quote 
fixp) (quote s!:builtin1) 19) (put (quote float) (quote s!:builtin1) 20) (put
(quote floatp) (quote s!:builtin1) 21) (put (quote symbol!-specialp) (quote 
s!:builtin1) 22) (put (quote gc) (quote s!:builtin1) 23) (put (quote gensym1)
(quote s!:builtin1) 24) (put (quote getenv) (quote s!:builtin1) 25) (put (
quote symbol!-globalp) (quote s!:builtin1) 26) (put (quote iadd1) (quote 
s!:builtin1) 27) (put (quote symbolp) (quote s!:builtin1) 28) (put (quote 
iminus) (quote s!:builtin1) 29) (put (quote iminusp) (quote s!:builtin1) 30) 
(put (quote indirect) (quote s!:builtin1) 31) (put (quote integerp) (quote 
s!:builtin1) 32) (put (quote intern) (quote s!:builtin1) 33) (put (quote 
isub1) (quote s!:builtin1) 34) (put (quote length) (quote s!:builtin1) 35) (
put (quote lengthc) (quote s!:builtin1) 36) (put (quote linelength) (quote 
s!:builtin1) 37) (put (quote liter) (quote s!:builtin1) 38) (put (quote 
load!-module) (quote s!:builtin1) 39) (put (quote lognot) (quote s!:builtin1)
40) (put (quote macroexpand) (quote s!:builtin1) 41) (put (quote 
macroexpand!-1) (quote s!:builtin1) 42) (put (quote macro!-function) (quote 
s!:builtin1) 43) (put (quote make!-bps) (quote s!:builtin1) 44) (put (quote 
make!-global) (quote s!:builtin1) 45) (put (quote make!-simple!-string) (
quote s!:builtin1) 46) (put (quote make!-special) (quote s!:builtin1) 47) (
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
printc) (quote s!:builtin1) 64) (put (quote rds) (quote s!:builtin1) 68) (put
(quote remd) (quote s!:builtin1) 69) (put (quote reverse) (quote s!:builtin1
) 70) (put (quote reversip) (quote s!:builtin1) 71) (put (quote seprp) (quote
s!:builtin1) 72) (put (quote set!-small!-modulus) (quote s!:builtin1) 73) (
put (quote spaces) (quote s!:builtin1) 74) (put (quote xtab) (quote 
s!:builtin1) 74) (put (quote special!-char) (quote s!:builtin1) 75) (put (
quote special!-form!-p) (quote s!:builtin1) 76) (put (quote spool) (quote 
s!:builtin1) 77) (put (quote stop) (quote s!:builtin1) 78) (put (quote 
stringp) (quote s!:builtin1) 79) (put (quote sub1) (quote s!:builtin1) 80) (
put (quote !1!-) (quote s!:builtin1) 80) (put (quote symbol!-env) (quote 
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
101) (put (quote cddr) (quote s!:builtin1) 102) (put (quote c!Ar) (quote 
s!:builtin1) 103) (put (quote c!Dr) (quote s!:builtin1) 104) (put (quote 
c!Aar) (quote s!:builtin1) 99) (put (quote c!Adr) (quote s!:builtin1) 100) (
put (quote c!Dar) (quote s!:builtin1) 101) (put (quote c!Ddr) (quote 
s!:builtin1) 102) (put (quote ca!Ar) (quote s!:builtin1) 99) (put (quote 
ca!Dr) (quote s!:builtin1) 100) (put (quote cd!Ar) (quote s!:builtin1) 101) (
put (quote cd!Dr) (quote s!:builtin1) 102) (put (quote c!A!Ar) (quote 
s!:builtin1) 105) (put (quote c!A!Dr) (quote s!:builtin1) 106) (put (quote 
c!D!Ar) (quote s!:builtin1) 107) (put (quote c!D!Dr) (quote s!:builtin1) 108)
(put (quote qcar) (quote s!:builtin1) 103) (put (quote qcdr) (quote 
s!:builtin1) 104) (put (quote qcaar) (quote s!:builtin1) 105) (put (quote 
qcadr) (quote s!:builtin1) 106) (put (quote qcdar) (quote s!:builtin1) 107) (
put (quote qcddr) (quote s!:builtin1) 108) (put (quote ncons) (quote 
s!:builtin1) 109) (put (quote numberp) (quote s!:builtin1) 110) (put (quote 
is!-spid) (quote s!:builtin1) 111) (put (quote spid!-to!-nil) (quote 
s!:builtin1) 112) (put (quote mv!-list!*) (quote s!:builtin1) 113) (put (
quote append) (quote s!:builtin2) 0) (put (quote ash) (quote s!:builtin2) 1) 
(put (quote assoc) (quote s!:builtin2) 2) (put (quote assoc!*!*) (quote 
s!:builtin2) 2) (put (quote atsoc) (quote s!:builtin2) 3) (put (quote deleq) 
(quote s!:builtin2) 4) (put (quote delete) (quote s!:builtin2) 5) (put (quote
divide) (quote s!:builtin2) 6) (put (quote eqcar) (quote s!:builtin2) 7) (
put (quote eql) (quote s!:builtin2) 8) (put (quote eqn) (quote s!:builtin2) 9
) (put (quote expt) (quote s!:builtin2) 10) (put (quote flag) (quote 
s!:builtin2) 11) (put (quote flagpcar) (quote s!:builtin2) 12) (put (quote 
gcdn) (quote s!:builtin2) 13) (put (quote geq) (quote s!:builtin2) 14) (put (
quote getv) (quote s!:builtin2) 15) (put (quote greaterp) (quote s!:builtin2)
16) (put (quote idifference) (quote s!:builtin2) 17) (put (quote igreaterp) 
(quote s!:builtin2) 18) (put (quote ilessp) (quote s!:builtin2) 19) (put (
quote imax) (quote s!:builtin2) 20) (put (quote imin) (quote s!:builtin2) 21)
(put (quote iplus2) (quote s!:builtin2) 22) (put (quote iquotient) (quote 
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
savedef r2i)) (quote switch))

(cond ((not (boundp (quote !*comp))) (progn (fluid (quote (!*comp))) (setq 
!*comp t))))

(cond ((not (boundp (quote !*nocompile))) (progn (fluid (quote (!*nocompile))
) (setq !*nocompile nil))))

(cond ((not (boundp (quote !*plap))) (progn (fluid (quote (!*plap))) (setq 
!*plap nil))))

(cond ((not (boundp (quote !*pgwd))) (progn (fluid (quote (!*pgwd))) (setq 
!*pgwd nil))))

(cond ((not (boundp (quote !*pwrds))) (progn (fluid (quote (!*pwrds))) (setq 
!*pwrds t))))

(cond ((not (boundp (quote !*notailcall))) (progn (fluid (quote (!*notailcall
))) (setq !*notailcall nil))))

(cond ((not (boundp (quote !*ord))) (progn (fluid (quote (!*ord))) (setq 
!*ord t))))

(cond ((not (boundp (quote !*savedef))) (progn (fluid (quote (!*savedef))) (
setq !*savedef nil))))

(cond ((not (boundp (quote !*carcheckflag))) (progn (fluid (quote (
!*carcheckflag))) (setq !*carcheckflag t))))

(cond ((not (boundp (quote !*r2i))) (progn (fluid (quote (!*r2i))) (setq 
!*r2i t))))

(fluid (quote (s!:current_function s!:current_label s!:current_block 
s!:current_size s!:current_procedure s!:other_defs s!:lexical_env 
s!:has_closure s!:recent_literals s!:used_lexicals s!:a_reg_values 
s!:current_count s!:maybe_values)))

(de s!:start_procedure (nargs nopts restarg) (progn (setq 
s!:current_procedure nil) (setq s!:current_label (gensym)) (setq 
s!:a_reg_values nil) (cond ((or (not (zerop nopts)) restarg) (progn (setq 
s!:current_block (list (list (quote OPTARGS) nopts) nopts (list (quote 
ARGCOUNT) nargs) nargs)) (setq s!:current_size 2))) (t (cond ((greaterp nargs
3) (progn (setq s!:current_block (list (list (quote ARGCOUNT) nargs) nargs))
(setq s!:current_size 1))) (t (progn (setq s!:current_block nil) (setq 
s!:current_size 0))))))))

(de s!:set_label (x) (progn (cond (s!:current_label (prog (w) (setq w (cons 
s!:current_size s!:current_block)) (prog (var1005) (setq var1005 
s!:recent_literals) lab1004 (cond ((null var1005) (return nil))) (prog (x) (
setq x (car var1005)) (rplaca x w)) (setq var1005 (cdr var1005)) (go lab1004)
) (setq s!:recent_literals nil) (setq s!:current_procedure (cons (cons 
s!:current_label (cons (list (quote JUMP) x) w)) s!:current_procedure)) (setq
s!:current_block nil) (setq s!:current_size 0)))) (setq s!:current_label x) 
(setq s!:a_reg_values nil)))

(de s!:outjump (op lab) (prog (g w) (cond ((not (flagp op (quote 
s!:preserves_a))) (setq s!:a_reg_values nil))) (cond ((null s!:current_label)
(return nil))) (cond ((equal op (quote JUMP)) (setq op (list op lab))) (t (
cond ((equal op (quote ICASE)) (setq op (cons op lab))) (t (setq op (list op 
lab (setq g (gensym)))))))) (setq w (cons s!:current_size s!:current_block)) 
(prog (var1007) (setq var1007 s!:recent_literals) lab1006 (cond ((null 
var1007) (return nil))) (prog (x) (setq x (car var1007)) (rplaca x w)) (setq 
var1007 (cdr var1007)) (go lab1006)) (setq s!:recent_literals nil) (setq 
s!:current_procedure (cons (cons s!:current_label (cons op w)) 
s!:current_procedure)) (setq s!:current_block nil) (setq s!:current_size 0) (
setq s!:current_label g) (return op)))

(de s!:outexit nil (prog (w op) (setq op (quote (EXIT))) (cond ((null 
s!:current_label) (return nil))) (setq w (cons s!:current_size 
s!:current_block)) (prog (var1009) (setq var1009 s!:recent_literals) lab1008 
(cond ((null var1009) (return nil))) (prog (x) (setq x (car var1009)) (rplaca
x w)) (setq var1009 (cdr var1009)) (go lab1008)) (setq s!:recent_literals 
nil) (setq s!:current_procedure (cons (cons s!:current_label (cons op w)) 
s!:current_procedure)) (setq s!:current_block nil) (setq s!:current_size 0) (
setq s!:current_label nil)))

(flag (quote (PUSH PUSHNIL PUSHNIL2 PUSHNIL3 LOSE LOSE2 LOSE3 LOSES STORELOC 
STORELOC0 STORELOC1 STORELOC2 STORELOC3 STORELOC4 STORELOC5 STORELOC6 
STORELOC7 JUMP JUMPT JUMPNIL JUMPEQ JUMPEQUAL JUMPNE JUMPNEQUAL JUMPATOM 
JUMPNATOM)) (quote s!:preserves_a))

(de s!:outopcode0 (op doc) (prog nil (cond ((not (flagp op (quote 
s!:preserves_a))) (setq s!:a_reg_values nil))) (cond ((null s!:current_label)
(return nil))) (setq s!:current_block (cons op s!:current_block)) (setq 
s!:current_size (plus s!:current_size 1)) (cond ((or !*plap !*pgwd) (setq 
s!:current_block (cons doc s!:current_block))))))

(de s!:outopcode1 (op arg doc) (prog nil (cond ((not (flagp op (quote 
s!:preserves_a))) (setq s!:a_reg_values nil))) (cond ((null s!:current_label)
(return nil))) (setq s!:current_block (cons arg (cons op s!:current_block)))
(setq s!:current_size (plus s!:current_size 2)) (cond ((or !*plap !*pgwd) (
setq s!:current_block (cons (list op doc) s!:current_block))))))

(deflist (quote ((LOADLIT 1) (LOADFREE 2) (CALL0 2) (CALL1 2) (LITGET 2) (
JUMPLITEQ 2) (JUMPLITNE 2) (JUMPLITEQ!* 2) (JUMPLITNE!* 2) (JUMPFREET 2) (
JUMPFREENIL 2))) (quote s!:short_form_bonus))

(de s!:record_literal (env) (prog (w extra) (setq w (gethash (car 
s!:current_block) (car env))) (cond ((null w) (setq w (cons 0 nil)))) (setq 
extra (get (cadr s!:current_block) (quote s!:short_form_bonus))) (cond ((null
extra) (setq extra 10)) (t (setq extra (plus extra 10)))) (setq 
s!:recent_literals (cons (cons nil s!:current_block) s!:recent_literals)) (
puthash (car s!:current_block) (car env) (cons (plus (car w) extra) (cons (
car s!:recent_literals) (cdr w))))))

(de s!:record_literal_for_jump (x env lab) (prog (w extra) (cond ((null 
s!:current_label) (return nil))) (setq w (gethash (cadr x) (car env))) (cond 
((null w) (setq w (cons 0 nil)))) (setq extra (get (car x) (quote 
s!:short_form_bonus))) (cond ((null extra) (setq extra 10)) (t (setq extra (
plus extra 10)))) (setq x (s!:outjump x lab)) (puthash (cadar x) (car env) (
cons (plus (car w) extra) (cons (cons nil x) (cdr w))))))

(de s!:outopcode1lit (op arg env) (prog nil (cond ((not (flagp op (quote 
s!:preserves_a))) (setq s!:a_reg_values nil))) (cond ((null s!:current_label)
(return nil))) (setq s!:current_block (cons arg (cons op s!:current_block)))
(s!:record_literal env) (setq s!:current_size (plus s!:current_size 2)) (
cond ((or !*plap !*pgwd) (setq s!:current_block (cons (list op arg) 
s!:current_block))))))

(de s!:outopcode2 (op arg1 arg2 doc) (prog nil (cond ((not (flagp op (quote 
s!:preserves_a))) (setq s!:a_reg_values nil))) (cond ((null s!:current_label)
(return nil))) (setq s!:current_block (cons arg2 (cons arg1 (cons op 
s!:current_block)))) (setq s!:current_size (plus s!:current_size 3)) (cond ((
or !*plap !*pgwd) (setq s!:current_block (cons (cons op doc) s!:current_block
))))))

(de s!:outlexref (op arg1 arg2 arg3 doc) (prog (arg4) (cond ((null 
s!:current_label) (return nil))) (cond ((or (greaterp arg1 255) (greaterp 
arg2 255) (greaterp arg3 255)) (progn (cond ((or (greaterp arg1 2047) (
greaterp arg2 31) (greaterp arg3 2047)) (error 0 
"stack frame > 2047 or > 31 deep nesting"))) (setq doc (list op doc)) (setq 
arg4 (logand arg3 255)) (setq arg3 (plus (truncate arg3 256) (times 16 (
logand arg1 15)))) (cond ((equal op (quote LOADLEX)) (setq op (plus 192 arg2)
)) (t (setq op (plus 224 arg2)))) (setq arg2 (truncate arg1 16)) (setq arg1 
op) (setq op (quote BIGSTACK)))) (t (setq doc (list doc)))) (setq 
s!:current_block (cons arg3 (cons arg2 (cons arg1 (cons op s!:current_block))
))) (setq s!:current_size (plus s!:current_size 4)) (cond (arg4 (progn (setq 
s!:current_block (cons arg4 s!:current_block)) (setq s!:current_size (plus 
s!:current_size 1))))) (cond ((or !*plap !*pgwd) (setq s!:current_block (cons
(cons op doc) s!:current_block))))))

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

(put (quote CALL4) (quote s!:longform) 64)

(put (quote CALL2R) (quote s!:longform) 80)

(put (quote LOADFREE) (quote s!:longform) 96)

(put (quote STOREFREE) (quote s!:longform) 112)

(put (quote JCALL0) (quote s!:longform) 128)

(put (quote JCALL1) (quote s!:longform) 144)

(put (quote JCALL2) (quote s!:longform) 160)

(put (quote JCALL3) (quote s!:longform) 176)

(put (quote JCALL4) (quote s!:longform) 192)

(put (quote FREEBIND) (quote s!:longform) 208)

(put (quote LITGET) (quote s!:longform) 224)

(put (quote LOADLIT) (quote s!:longform) 240)

(de s!:literal_order (a b) (cond ((equal (cadr a) (cadr b)) (orderp (car a) (
car b))) (t (greaterp (cadr a) (cadr b)))))

(de s!:resolve_literals (env checksum) (prog (w op opspec n litbytes) (setq w
(hashcontents (car env))) (setq w (sort w (function s!:literal_order))) (
setq w (append w (list (list checksum 0)))) (setq n (length w)) (setq 
litbytes (times 4 n)) (cond ((greaterp n 4096) (setq w (s!:too_many_literals 
w n)))) (setq n 0) (prog (var1011) (setq var1011 w) lab1010 (cond ((null 
var1011) (return nil))) (prog (x) (setq x (car var1011)) (progn (rplaca (cdr 
x) n) (setq n (plus n 1)))) (setq var1011 (cdr var1011)) (go lab1010)) (prog 
(var1015) (setq var1015 w) lab1014 (cond ((null var1015) (return nil))) (prog
 (x) (setq x (car var1015)) (progn (setq n (cadr x)) (prog (var1013) (setq 
var1013 (cddr x)) lab1012 (cond ((null var1013) (return nil))) (prog (y) (
setq y (car var1013)) (progn (cond ((null (car y)) (progn (setq op (caadr y))
(setq opspec (get op (quote s!:shortform))) (cond ((and opspec (leq (caar 
opspec) n) (leq n (cdar opspec))) (rplaca (cdr y) (getv (cdr opspec) n))) (t 
(rplaca (cdadr y) n))))) (t (progn (setq op (caddr y)) (cond ((greaterp n 255
) (progn (rplaca (car y) (plus (caar y) 1)) (setq op (plus (get op (quote 
s!:longform)) (truncate n 256))) (rplaca (cdr y) (ilogand n 255)) (rplaca (
cddr y) (quote BIGCALL)) (rplacd (cdr y) (cons op (cddr y))))) (t (cond ((and
(setq opspec (get op (quote s!:shortform))) (leq (caar opspec) n) (leq n (
cdar opspec))) (progn (rplaca (car y) (difference (caar y) 1)) (rplaca (cdr y
) (getv (cdr opspec) n)) (rplacd (cdr y) (cdddr y)))) (t (rplaca (cdr y) n)))
))))))) (setq var1013 (cdr var1013)) (go lab1012)))) (setq var1015 (cdr 
var1015)) (go lab1014)) (prog (var1017) (setq var1017 w) lab1016 (cond ((null
var1017) (return nil))) (prog (x) (setq x (car var1017)) (rplacd x (cadr x))
) (setq var1017 (cdr var1017)) (go lab1016)) (rplaca env (cons (reversip w) 
litbytes))))

(de s!:only_loadlit (l) (cond ((null l) t) (t (cond ((null (caar l)) nil) (t 
(cond ((not (eqcar (cddar l) (quote LOADLIT))) nil) (t (s!:only_loadlit (cdr 
l)))))))))

(de s!:too_many_literals (w n) (prog (k xvecs l r newrefs uses z1) (setq k 0)
(setq n (plus n 1)) (prog nil lab1018 (cond ((null (and (greaterp n 4096) (
not (null w)))) (return nil))) (progn (cond ((and (not (equal (cadar w) 
10000000)) (s!:only_loadlit (cddar w))) (progn (setq l (cons (car w) l)) (
setq n (difference n 1)) (setq k (plus k 1)) (cond ((equal k 256) (progn (
setq xvecs (cons l xvecs)) (setq l nil) (setq k 0) (setq n (plus n 1))))))) (
t (setq r (cons (car w) r)))) (setq w (cdr w))) (go lab1018)) (cond ((
greaterp n 4096) (error 0 "function uses too many literals (4096 is limit)"))
) (setq xvecs (cons l xvecs)) (prog nil lab1019 (cond ((null r) (return nil))
) (progn (setq w (cons (car r) w)) (setq r (cdr r))) (go lab1019)) (prog (
var1025) (setq var1025 xvecs) lab1024 (cond ((null var1025) (return nil))) (
prog (v) (setq v (car var1025)) (progn (setq newrefs nil) (setq uses 0) (setq
r nil) (setq k 0) (prog (var1023) (setq var1023 v) lab1022 (cond ((null 
var1023) (return nil))) (prog (q) (setq q (car var1023)) (progn (prog (
var1021) (setq var1021 (cddr q)) lab1020 (cond ((null var1021) (return nil)))
(prog (z) (setq z (car var1021)) (progn (cond ((car z) (rplaca (car z) (plus
(caar z) 2)))) (setq z1 (cons (quote QGETVN) (cons nil (cddr z)))) (rplaca (
cdr z) k) (rplacd (cdr z) z1) (rplacd z (cdr z1)) (setq newrefs (cons z 
newrefs)) (setq uses (plus uses 11)))) (setq var1021 (cdr var1021)) (go 
lab1020)) (setq r (cons (car q) r)) (setq k (plus k 1)))) (setq var1023 (cdr 
var1023)) (go lab1022)) (setq newrefs (cons uses newrefs)) (setq newrefs (
cons (s!:vecof (reversip r)) newrefs)) (setq w (cons newrefs w)))) (setq 
var1025 (cdr var1025)) (go lab1024)) (return (sort w (function 
s!:literal_order)))))

(fluid (quote (s!:into_c)))

(de s!:endprocedure (name env checksum) (prog (pc labelvals w vec) (
s!:outexit) (cond (s!:into_c (return (cons s!:current_procedure env)))) (
s!:resolve_literals env checksum) (setq s!:current_procedure (
s!:tidy_flowgraph s!:current_procedure)) (cond ((and (not !*notailcall) (not 
s!:has_closure)) (setq s!:current_procedure (s!:try_tailcall 
s!:current_procedure)))) (setq s!:current_procedure (s!:tidy_exits 
s!:current_procedure)) (setq labelvals (s!:resolve_labels)) (setq pc (car 
labelvals)) (setq labelvals (cdr labelvals)) (setq vec (make!-bps pc)) (setq 
pc 0) (cond ((or !*plap !*pgwd) (progn (terpri) (ttab 23) (princ "+++ ") (
prin name) (princ " +++") (terpri)))) (prog (var1027) (setq var1027 
s!:current_procedure) lab1026 (cond ((null var1027) (return nil))) (prog (b) 
(setq b (car var1027)) (progn (cond ((and (car b) (flagp (car b) (quote 
used_label)) (or !*plap !*pgwd)) (progn (ttab 20) (prin (car b)) (princ ":") 
(terpri)))) (setq pc (s!:plant_basic_block vec pc (reverse (cdddr b)))) (setq
b (cadr b)) (cond ((and b (neq (car b) (quote ICASE)) (cdr b) (cddr b)) (
setq b (list (car b) (cadr b))))) (setq pc (s!:plant_exit_code vec pc b 
labelvals)))) (setq var1027 (cdr var1027)) (go lab1026)) (cond (!*pwrds (
progn (cond ((neq (posn) 0) (terpri))) (princ "+++ ") (prin name) (princ 
" compiled, ") (princ pc) (princ " + ") (princ (cdar env)) (printc " bytes"))
)) (setq env (caar env)) (cond ((null env) (setq w nil)) (t (progn (setq w (
mkvect (cdar env))) (prog nil lab1028 (cond ((null env) (return nil))) (progn
(putv w (cdar env) (caar env)) (setq env (cdr env))) (go lab1028))))) (
return (cons vec w))))

(de s!:add_pending (lab pend blocks) (prog (w) (cond ((not (atom lab)) (
return (cons (list (gensym) lab 0) pend)))) (setq w (atsoc lab pend)) (cond (
w (return (cons w (deleq w pend)))) (t (return (cons (atsoc lab blocks) pend)
)))))

(de s!:invent_exit (x blocks) (prog (w) (setq w blocks) scan (cond ((null w) 
(go not_found)) (t (cond ((and (eqcar (cadar w) x) (equal (caddar w) 0)) (
return (cons (caar w) blocks))) (t (setq w (cdr w)))))) (go scan) not_found (
setq w (gensym)) (return (cons w (cons (list w (list x) 0) blocks)))))

(de s!:destination_label (lab blocks) (prog (n w x) (setq w (atsoc lab blocks
)) (cond ((s!:is_lose_and_exit w blocks) (return (quote (EXIT))))) (setq x (
cadr w)) (setq n (caddr w)) (setq w (cdddr w)) (cond ((neq n 0) (return lab))
) (cond ((or (null x) (null (cdr x))) (return x)) (t (cond ((equal (cadr x) 
lab) (return lab)) (t (cond ((null (cddr x)) (return (s!:destination_label (
cadr x) blocks))) (t (return lab)))))))))

(de s!:remlose (b) (prog (w) (setq w b) (prog nil lab1029 (cond ((null (and w
(not (atom (car w))))) (return nil))) (setq w (cdr w)) (go lab1029)) (cond (
(null w) (return (cons 0 b)))) (cond ((and (numberp (car w)) (eqcar (cdr w) (
quote LOSES))) (setq w (cons 2 (cddr w)))) (t (cond ((or (equal (car w) (
quote LOSE)) (equal (car w) (quote LOSE2)) (equal (car w) (quote LOSE3))) (
setq w (cons 1 (cdr w)))) (t (return (cons 0 b)))))) (setq b (s!:remlose (cdr
w))) (return (cons (plus (car w) (car b)) (cdr b)))))

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

(de s!:remcall (b) (prog (w cmnt nargs lvoff callsize) (prog nil lab1030 (
cond ((null (and b (not (atom (car b))))) (return nil))) (progn (setq cmnt (
car b)) (setq b (cdr b))) (go lab1030)) (cond ((null b) (return nil)) (t (
cond ((numberp (car b)) (progn (setq lvoff (car b)) (setq callsize 2) (setq b
(cdr b)) (cond ((null b) (return nil)) (t (cond ((numberp (car b)) (progn (
setq nargs lvoff) (setq lvoff (car b)) (setq callsize 3) (setq b (cdr b)) (
cond ((eqcar b (quote BIGCALL)) (progn (setq w (truncate lvoff 16)) (setq 
lvoff (plus (times 256 (logand lvoff 15)) nargs)) (setq nargs w) (cond ((
equal nargs 5) (progn (setq nargs 2) (setq callsize (difference callsize 1)) 
(setq b (cons (quote BIGCALL) (cons (quote SWOP) (cdr b))))))) (cond ((
greaterp nargs 4) (return nil))))) (t (return nil))))) (t (cond ((equal (car 
b) (quote CALL0)) (setq nargs 0)) (t (cond ((equal (car b) (quote CALL1)) (
setq nargs 1)) (t (cond ((equal (car b) (quote CALL2)) (setq nargs 2)) (t (
cond ((equal (car b) (quote CALL2R)) (progn (setq nargs 2) (setq callsize (
difference callsize 1)) (setq b (cons (quote CALL2) (cons (quote SWOP) (cdr b
)))))) (t (cond ((equal (car b) (quote CALL3)) (setq nargs 3)) (t (cond ((
equal (car b) (quote CALL4)) (setq nargs 4)) (t (return nil))))))))))))))))) 
(setq b (cdr b)))) (t (cond ((setq nargs (get (car b) (quote s!:shortcall))) 
(progn (setq lvoff (cdr nargs)) (setq nargs (car nargs)) (setq callsize 1) (
setq b (cdr b)))) (t (return nil))))))) (return (cons cmnt (cons nargs (cons 
lvoff (cons callsize b)))))))

(de s!:is_lose_and_exit (b blocks) (prog (lab exit) (setq lab (car b)) (setq 
exit (cadr b)) (setq b (cdddr b)) (cond ((null exit) (return nil))) (setq b (
s!:remlose b)) (setq b (cdr b)) (prog nil lab1031 (cond ((null (and b (not (
atom (car b))))) (return nil))) (setq b (cdr b)) (go lab1031)) (cond (b (
return nil)) (t (cond ((equal (car exit) (quote EXIT)) (return t)) (t (cond (
(equal (car exit) (quote JUMP)) (progn (cond ((equal (cadr exit) lab) nil) (t
(return (s!:is_lose_and_exit (atsoc (cadr exit) blocks) blocks)))))) (t (
return nil)))))))))

(de s!:try_tail_1 (b blocks) (prog (exit size body w nargs litoff w2 op) (
setq exit (cadr b)) (cond ((null exit) (return b)) (t (cond ((not (equal (car
exit) (quote EXIT))) (progn (cond ((equal (car exit) (quote JUMP)) (progn (
cond ((not (s!:is_lose_and_exit (atsoc (cadr exit) blocks) blocks)) (return b
))))) (t (return b)))))))) (setq size (caddr b)) (setq body (cdddr b)) (setq 
body (s!:remlose body)) (setq size (difference size (car body))) (setq body (
cdr body)) (setq w (s!:remcall body)) (cond ((null w) (return b))) (setq 
nargs (cadr w)) (setq litoff (caddr w)) (setq body (cddddr w)) (cond ((and (
leq nargs 4) (leq litoff 31)) (progn (setq body (cons (quote JCALL) body)) (
setq body (cons (plus (times 32 nargs) litoff) body)) (setq size (difference 
size 1)))) (t (progn (setq body (cons (quote BIGCALL) body)) (setq w2 (logand
litoff 255)) (setq litoff (truncate litoff 256)) (setq body (cons w2 (cons (
plus litoff (times 16 nargs) 128) body)))))) (cond ((car w) (setq body (cons 
(append (car w) (list (quote TAIL))) body)))) (rplaca (cdr b) nil) (rplaca (
cddr b) (plus (difference size (cadddr w)) 3)) (rplacd (cddr b) body) (return
b)))

(de s!:try_tailcall (b) (prog (var1033 var1034) (setq var1033 b) lab1032 (
cond ((null var1033) (return (reversip var1034)))) (prog (v) (setq v (car 
var1033)) (setq var1034 (cons (s!:try_tail_1 v b) var1034))) (setq var1033 (
cdr var1033)) (go lab1032)))

(de s!:tidy_exits_1 (b blocks) (prog (exit size body comm w op) (setq exit (
cadr b)) (cond ((null exit) (return b)) (t (cond ((not (equal (car exit) (
quote EXIT))) (progn (cond ((equal (car exit) (quote JUMP)) (progn (cond ((
not (s!:is_lose_and_exit (atsoc (cadr exit) blocks) blocks)) (return b))))) (
t (return b)))))))) (setq size (caddr b)) (setq body (cdddr b)) (setq body (
s!:remlose body)) (setq size (difference size (car body))) (setq body (cdr 
body)) (prog nil lab1035 (cond ((null (and body (not (atom (car body))))) (
return nil))) (progn (setq comm (car body)) (setq body (cdr body))) (go 
lab1035)) (cond ((eqcar body (quote VNIL)) (setq w (quote NILEXIT))) (t (cond
((eqcar body (quote LOADLOC0)) (setq w (quote LOC0EXIT))) (t (cond ((eqcar 
body (quote LOADLOC1)) (setq w (quote LOC1EXIT))) (t (cond ((eqcar body (
quote LOADLOC2)) (setq w (quote LOC2EXIT))) (t (setq w nil))))))))) (cond (w 
(progn (rplaca (cdr b) (list w)) (setq body (cdr body)) (setq size (
difference size 1)))) (t (cond (comm (setq body (cons comm body)))))) (rplaca
(cddr b) size) (rplacd (cddr b) body) (return b)))

(de s!:tidy_exits (b) (prog (var1037 var1038) (setq var1037 b) lab1036 (cond 
((null var1037) (return (reversip var1038)))) (prog (v) (setq v (car var1037)
) (setq var1038 (cons (s!:tidy_exits_1 v b) var1038))) (setq var1037 (cdr 
var1037)) (go lab1036)))

(de s!:tidy_flowgraph (b) (prog (r pending) (setq b (reverse b)) (setq 
pending (list (car b))) (prog nil lab1040 (cond ((null pending) (return nil))
) (prog (c x l1 l2 done1 done2) (setq c (car pending)) (setq pending (cdr 
pending)) (flag (list (car c)) (quote coded)) (setq x (cadr c)) (cond ((or (
null x) (null (cdr x))) (setq r (cons c r))) (t (cond ((equal (car x) (quote 
ICASE)) (progn (rplacd x (reversip (cdr x))) (prog (ll) (setq ll (cdr x)) 
lab1039 (cond ((null ll) (return nil))) (progn (setq l1 (s!:destination_label
(car ll) b)) (cond ((not (atom l1)) (progn (setq l1 (s!:invent_exit (car l1)
b)) (setq b (cdr l1)) (setq l1 (cadr l1))))) (rplaca ll l1) (setq done1 (
flagp l1 (quote coded))) (flag (list l1) (quote used_label)) (cond ((not 
done1) (setq pending (s!:add_pending l1 pending b))))) (setq ll (cdr ll)) (go
lab1039)) (rplacd x (reversip (cdr x))) (setq r (cons c r)))) (t (cond ((
null (cddr x)) (progn (setq l1 (s!:destination_label (cadr x) b)) (cond ((not
(atom l1)) (setq c (cons (car c) (cons l1 (cddr c))))) (t (cond ((flagp l1 (
quote coded)) (progn (flag (list l1) (quote used_label)) (setq c (cons (car c
) (cons (list (car x) l1) (cddr c)))))) (t (progn (setq c (cons (car c) (cons
nil (cddr c)))) (setq pending (s!:add_pending l1 pending b))))))) (setq r (
cons c r)))) (t (progn (setq l1 (s!:destination_label (cadr x) b)) (setq l2 (
s!:destination_label (caddr x) b)) (setq done1 (and (atom l1) (flagp l1 (
quote coded)))) (setq done2 (and (atom l2) (flagp l2 (quote coded)))) (cond (
done1 (progn (cond (done2 (progn (flag (list l1) (quote used_label)) (rplaca 
(cdadr c) l1) (setq pending (cons (list (gensym) (list (quote JUMP) l2) 0) 
pending)))) (t (progn (flag (list l1) (quote used_label)) (rplaca (cdadr c) 
l1) (setq pending (s!:add_pending l2 pending b))))))) (t (progn (cond (done2 
(progn (flag (list l2) (quote used_label)) (rplaca (cadr c) (s!:negate_jump (
car x))) (rplaca (cdadr c) l2) (setq pending (s!:add_pending l1 pending b))))
(t (progn (cond ((not (atom l1)) (progn (setq l1 (s!:invent_exit (car l1) b)
) (setq b (cdr l1)) (setq l1 (car l1))))) (flag (list l1) (quote used_label))
(rplaca (cdadr c) l1) (cond ((not (flagp l1 (quote coded))) (setq pending (
s!:add_pending l1 pending b)))) (setq pending (s!:add_pending l2 pending b)))
))))) (setq r (cons c r)))))))))) (go lab1040)) (return (reverse r))))

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

(de s!:negate_jump (x) (cond ((atom x) (get x (quote negjump))) (t (rplaca x 
(get (car x) (quote negjump))))))

(de s!:resolve_labels nil (prog (w labelvals converged pc x) (prog nil 
lab1043 (progn (setq converged t) (setq pc 0) (prog (var1042) (setq var1042 
s!:current_procedure) lab1041 (cond ((null var1042) (return nil))) (prog (b) 
(setq b (car var1042)) (progn (setq w (assoc!*!* (car b) labelvals)) (cond ((
null w) (progn (setq converged nil) (setq w (cons (car b) pc)) (setq 
labelvals (cons w labelvals)))) (t (cond ((neq (cdr w) pc) (progn (rplacd w 
pc) (setq converged nil)))))) (setq pc (plus pc (caddr b))) (setq x (cadr b))
(cond ((null x) nil) (t (cond ((null (cdr x)) (setq pc (plus pc 1))) (t (
cond ((equal (car x) (quote ICASE)) (setq pc (plus pc (times 2 (length x)))))
(t (progn (setq w (assoc!*!* (cadr x) labelvals)) (cond ((null w) (progn (
setq w 128) (setq converged nil))) (t (setq w (difference (cdr w) pc)))) (
setq w (s!:expand_jump (car x) w)) (setq pc (plus pc (length w)))))))))))) (
setq var1042 (cdr var1042)) (go lab1041))) (cond ((null converged) (go 
lab1043)))) (return (cons pc labelvals))))

(de s!:plant_basic_block (vec pc b) (prog (tagged) (prog (var1047) (setq 
var1047 b) lab1046 (cond ((null var1047) (return nil))) (prog (i) (setq i (
car var1047)) (progn (cond ((atom i) (progn (cond ((symbolp i) (setq i (get i
(quote s!:opcode))))) (cond ((and (not tagged) (or !*plap !*pgwd)) (progn (
s!:prinhex4 pc) (princ ":") (ttab 8) (setq tagged t)))) (cond ((or (not (fixp
i)) (lessp i 0) (greaterp i 255)) (error 0 (list "bad byte to put" i)))) (
bps!-putv vec pc i) (cond ((or !*plap !*pgwd) (progn (s!:prinhex2 i) (princ 
" ")))) (setq pc (plus pc 1)))) (t (cond ((or !*plap !*pgwd) (progn (ttab 23)
(princ (car i)) (prog (var1045) (setq var1045 (cdr i)) lab1044 (cond ((null 
var1045) (return nil))) (prog (w) (setq w (car var1045)) (progn (princ " ") (
prin w))) (setq var1045 (cdr var1045)) (go lab1044)) (terpri) (setq tagged 
nil)))))))) (setq var1047 (cdr var1047)) (go lab1046)) (return pc)))

(de s!:plant_bytes (vec pc bytelist doc) (prog nil (cond ((or !*plap !*pgwd) 
(progn (s!:prinhex4 pc) (princ ":") (ttab 8)))) (prog (var1049) (setq var1049
bytelist) lab1048 (cond ((null var1049) (return nil))) (prog (v) (setq v (
car var1049)) (progn (cond ((symbolp v) (setq v (get v (quote s!:opcode))))) 
(cond ((or (not (fixp v)) (lessp v 0) (greaterp v 255)) (error 0 (list 
"bad byte to put" v)))) (bps!-putv vec pc v) (cond ((or !*plap !*pgwd) (progn
(cond ((greaterp (posn) 50) (progn (terpri) (ttab 8)))) (s!:prinhex2 v) (
princ " ")))) (setq pc (plus pc 1)))) (setq var1049 (cdr var1049)) (go 
lab1048)) (cond ((or !*plap !*pgwd) (progn (cond ((greaterp (posn) 23) (
terpri))) (ttab 23) (princ (car doc)) (prog (var1051) (setq var1051 (cdr doc)
) lab1050 (cond ((null var1051) (return nil))) (prog (w) (setq w (car var1051
)) (progn (cond ((greaterp (posn) 65) (progn (terpri) (ttab 23)))) (princ " "
) (prin w))) (setq var1051 (cdr var1051)) (go lab1050)) (terpri)))) (return 
pc)))

(de s!:plant_exit_code (vec pc b labelvals) (prog (w loc low high r) (cond ((
null b) (return pc)) (t (cond ((null (cdr b)) (return (s!:plant_bytes vec pc 
(list (get (car b) (quote s!:opcode))) b))) (t (cond ((equal (car b) (quote 
ICASE)) (progn (setq loc (plus pc 3)) (prog (var1053) (setq var1053 (cdr b)) 
lab1052 (cond ((null var1053) (return nil))) (prog (ll) (setq ll (car var1053
)) (progn (setq w (difference (cdr (assoc!*!* ll labelvals)) loc)) (setq loc 
(plus loc 2)) (cond ((lessp w 0) (progn (setq w (minus w)) (setq low (ilogand
w 255)) (setq high (plus 128 (truncate (difference w low) 256))))) (t (progn
(setq low (ilogand w 255)) (setq high (truncate (difference w low) 256))))) 
(setq r (cons low (cons high r))))) (setq var1053 (cdr var1053)) (go lab1052)
) (setq r (cons (get (quote ICASE) (quote s!:opcode)) (cons (length (cddr b))
(reversip r)))) (return (s!:plant_bytes vec pc r b))))))))) (setq w (
difference (cdr (assoc!*!* (cadr b) labelvals)) pc)) (setq w (s!:expand_jump 
(car b) w)) (return (s!:plant_bytes vec pc w b))))

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

(prog (var1055) (setq var1055 (quote ((JUMP JUMP_B JUMP_L JUMP_BL) (JUMPNIL 
JUMPNIL_B JUMPNIL_L JUMPNIL_BL) (JUMPT JUMPT_B JUMPT_L JUMPT_BL) (JUMPATOM 
JUMPATOM_B JUMPATOM_L JUMPATOM_BL) (JUMPNATOM JUMPNATOM_B JUMPNATOM_L 
JUMPNATOM_BL) (JUMPEQ JUMPEQ_B JUMPEQ_L JUMPEQ_BL) (JUMPNE JUMPNE_B JUMPNE_L 
JUMPNE_BL) (JUMPEQUAL JUMPEQUAL_B JUMPEQUAL_L JUMPEQUAL_BL) (JUMPNEQUAL 
JUMPNEQUAL_B JUMPNEQUAL_L JUMPNEQUAL_BL) (CATCH CATCH_B CATCH_L CATCH_BL)))) 
lab1054 (cond ((null var1055) (return nil))) (prog (op) (setq op (car var1055
)) (progn (putv!-char s!:backwards_jump (get (car op) (quote s!:opcode)) (get
(cadr op) (quote s!:opcode))) (putv!-char s!:backwards_jump (get (caddr op) 
(quote s!:opcode)) (get (cadddr op) (quote s!:opcode))) (putv!-char 
s!:longer_jump (get (car op) (quote s!:opcode)) (get (caddr op) (quote 
s!:opcode))) (putv!-char s!:longer_jump (get (cadr op) (quote s!:opcode)) (
get (cadddr op) (quote s!:opcode))))) (setq var1055 (cdr var1055)) (go 
lab1054))

(de s!:expand_jump (op offset) (prog (arg low high opcode expanded) (cond ((
not (atom op)) (progn (setq arg (cadr op)) (setq op (car op)) (setq offset (
difference offset 1))))) (setq expanded (get op (quote s!:expand_jump))) (
cond ((and expanded (not (and (leq 2 offset) (lessp offset (plus 256 2)) (or 
(null arg) (lessp arg 256))))) (progn (setq op (cadr expanded)) (setq 
expanded (car expanded)) (cond (arg (progn (cond ((greaterp arg 2047) (error 
0 "function uses too many literals (2048 limit)")) (t (cond ((greaterp arg 
255) (prog (high low) (setq low (ilogand arg 255)) (setq high (truncate (
difference arg low) 256)) (setq expanded (cons (quote BIGCALL) (cons (plus (
get (car expanded) (quote s!:longform)) high) (cons low (cddr expanded)))))))
(t (setq expanded (subst arg (quote !*) expanded)))))) (setq offset (plus 
offset 1))))) (setq offset (difference offset (length expanded))) (setq arg 
nil))) (t (setq expanded nil))) (setq opcode (get op (quote s!:opcode))) (
cond ((null opcode) (error 0 (list op offset "invalid block exit")))) (cond (
(and (lessp (plus (minus 256) 2) offset) (lessp offset (plus 256 2))) (setq 
offset (difference offset 2))) (t (progn (setq high t) (setq offset (
difference offset 3))))) (cond ((lessp offset 0) (progn (setq opcode (
byte!-getv s!:backwards_jump opcode)) (setq offset (minus offset))))) (cond (
high (progn (setq low (logand offset 255)) (setq high (truncate (difference 
offset low) 256)))) (t (cond ((greaterp (setq low offset) 255) (error 0 
"Bad offset in expand_jump"))))) (cond (arg (return (list opcode arg low))) (
t (cond ((not high) (return (append expanded (list opcode low)))) (t (return 
(append expanded (list (byte!-getv s!:longer_jump opcode) high low)))))))))

(de s!:comval (x env context) (prog (helper) (setq x (s!:improve x)) (cond ((
atom x) (return (s!:comatom x env context))) (t (cond ((eqcar (car x) (quote 
lambda)) (return (s!:comlambda (cadar x) (cddar x) (cdr x) env context))) (t 
(cond ((eq (car x) s!:current_function) (s!:comcall x env context)) (t (cond 
((setq helper (s!:local_macro (car x))) (progn (cond ((atom (cdr helper)) (
s!:comval (cons (quote funcall) (cons (cdr helper) (cdr x))) env context)) (t
(s!:comval (funcall (cons (quote lambda) (cdr helper)) x) env context))))) (
t (cond ((and (setq helper (get (car x) (quote s!:compilermacro))) (setq 
helper (funcall helper x env context))) (return (s!:comval helper env context
))) (t (cond ((setq helper (get (car x) (quote s!:newname))) (return (
s!:comval (cons helper (cdr x)) env context))) (t (cond ((setq helper (get (
car x) (quote s!:compfn))) (return (funcall helper x env context))) (t (cond 
((setq helper (macro!-function (car x))) (return (s!:comval (funcall helper x
) env context))) (t (return (s!:comcall x env context))))))))))))))))))))

(de s!:comspecform (x env context) (error 0 (list "special form" x)))

(cond ((null (get (quote and) (quote s!:compfn))) (progn (put (quote 
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
s!:comspecform)) nil)))

(de s!:improve (u) (prog (w) (cond ((atom u) (return u)) (t (cond ((setq w (
get (car u) (quote s!:tidy_fn))) (return (funcall w u))) (t (cond ((setq w (
get (car u) (quote s!:newname))) (return (s!:improve (cons w (cdr u))))) (t (
return u)))))))))

(de s!:imp_cond_predicate (u) (cond ((and (eqcar u (quote memq)) (atom (cadr 
u)) (eqcar (caddr u) (quote quote))) (cons (quote or) (prog (var1057 var1058)
(setq var1057 (cadr (caddr u))) lab1056 (cond ((null var1057) (return (
reversip var1058)))) (prog (v) (setq v (car var1057)) (setq var1058 (cons (
list (quote eq) (cadr u) (mkquote v)) var1058))) (setq var1057 (cdr var1057))
(go lab1056)))) (t u)))

(de s!:imp_cond (u) (cons (quote cond) (prog (var1060 var1061) (setq var1060 
(cdr u)) lab1059 (cond ((null var1060) (return (reversip var1061)))) (prog (s
) (setq s (car var1060)) (setq var1061 (cons (cons (s!:imp_cond_predicate (
car s)) (cdr s)) var1061))) (setq var1060 (cdr var1060)) (go lab1059))))

(put (quote cond) (quote s!:tidy_fn) (quote s!:imp_cond))

(de s!:imp_minus (u) (prog (a) (setq a (s!:improve (cadr u))) (return (cond (
(numberp a) (minus a)) (t (cond ((or (eqcar a (quote minus)) (eqcar a (quote 
iminus))) (cadr a)) (t (cond ((eqcar a (quote difference)) (s!:improve (list 
(quote difference) (caddr a) (cadr a)))) (t (cond ((eqcar a (quote 
idifference)) (s!:improve (list (quote idifference) (caddr a) (cadr a)))) (t 
(list (car u) a))))))))))))

(put (quote minus) (quote s!:tidy_fn) (quote s!:imp_minus))

(put (quote iminus) (quote s!:tidy_fn) (quote s!:imp_minus))

(de s!:imp_1!+ (u) (s!:improve (cons (quote add1) (cdr u))))

(put (quote !1!+) (quote s!:tidy_fn) (quote s!:imp_1!+))

(de s!:imp_1!- (u) (s!:improve (cons (quote sub1) (cdr u))))

(put (quote !1!-) (quote s!:tidy_fn) (quote s!:imp_1!-))

(de s!:imp_times (u) (prog (a b) (cond ((not (equal (length u) 3)) (return (
cons (car u) (prog (var1063 var1064) (setq var1063 (cdr u)) lab1062 (cond ((
null var1063) (return (reversip var1064)))) (prog (v) (setq v (car var1063)) 
(setq var1064 (cons (s!:improve v) var1064))) (setq var1063 (cdr var1063)) (
go lab1062)))))) (setq a (s!:improve (cadr u))) (setq b (s!:improve (caddr u)
)) (return (cond ((equal a 1) b) (t (cond ((equal b 1) a) (t (cond ((equal a 
(minus 1)) (s!:imp_minus (list (quote minus) b))) (t (cond ((equal b (minus 1
)) (s!:imp_minus (list (quote minus) a))) (t (list (car u) a b))))))))))))

(put (quote times) (quote s!:tidy_fn) (quote s!:imp_times))

(de s!:imp_itimes (u) (prog (a b) (cond ((not (equal (length u) 3)) (return (
cons (car u) (prog (var1066 var1067) (setq var1066 (cdr u)) lab1065 (cond ((
null var1066) (return (reversip var1067)))) (prog (v) (setq v (car var1066)) 
(setq var1067 (cons (s!:improve v) var1067))) (setq var1066 (cdr var1066)) (
go lab1065)))))) (setq a (s!:improve (cadr u))) (setq b (s!:improve (caddr u)
)) (return (cond ((equal a 1) b) (t (cond ((equal b 1) a) (t (cond ((equal a 
(minus 1)) (s!:imp_minus (list (quote iminus) b))) (t (cond ((equal b (minus 
1)) (s!:imp_minus (list (quote iminus) a))) (t (list (car u) a b))))))))))))

(put (quote itimes) (quote s!:tidy_fn) (quote s!:imp_itimes))

(de s!:imp_difference (u) (prog (a b) (setq a (s!:improve (cadr u))) (setq b 
(s!:improve (caddr u))) (return (cond ((equal a 0) (s!:imp_minus (list (quote
minus) b))) (t (cond ((equal b 0) a) (t (list (car u) a b))))))))

(put (quote difference) (quote s!:tidy_fn) (quote s!:imp_difference))

(de s!:imp_idifference (u) (prog (a b) (setq a (s!:improve (cadr u))) (setq b
(s!:improve (caddr u))) (return (cond ((equal a 0) (s!:imp_minus (list (
quote iminus) b))) (t (cond ((equal b 0) a) (t (list (car u) a b))))))))

(put (quote idifference) (quote s!:tidy_fn) (quote s!:imp_idifference))

(de s!:imp_car (u) (prog (a) (setq a (s!:improve (cadr u))) (cond ((eqcar a (
quote car)) (return (list (quote caar) (cadr a)))) (t (cond ((eqcar a (quote 
cdr)) (return (list (quote cadr) (cadr a)))) (t (return (list (quote car) a))
))))))

(put (quote car) (quote s!:tidy_fn) (quote s!:imp_car))

(de s!:imp_cdr (u) (prog (a) (setq a (s!:improve (cadr u))) (cond ((eqcar a (
quote car)) (return (list (quote cdar) (cadr a)))) (t (cond ((eqcar a (quote 
cdr)) (return (list (quote cddr) (cadr a)))) (t (return (list (quote cdr) a))
))))))

(put (quote cdr) (quote s!:tidy_fn) (quote s!:imp_cdr))

(de s!:boolean_jumpable (u) (or (null u) (equal u t) (and (not (atom u)) (
atom (car u)) (or (flagp (car u) (quote s!:bool_opcode)) (and (or (equal (car
u) (quote and)) (equal (car u) (quote or))) (s!:boolean_jumpable_list (cdr u
)))))))

(de s!:boolean_jumpable_list (u) (or (atom u) (and (s!:boolean_jumpable (car 
u)) (s!:boolean_jumpable_list (cdr u)))))

(flag (quote (null not eq equal neq eqcar atom flagp)) (quote s!:bool_opcode)
)

(de s!:imp_or (u) (prog (w x) (setq w (cdr u)) (cond ((atom w) (return nil)))
(setq x (car w)) (cond ((atom (cdr w)) (return (s!:improve x))) (t (cond ((
s!:boolean_jumpable x) (return (list (quote cond) (list x t) (list t (
s!:imp_or (cons (quote or) (cdr w))))))) (t (return (list (quote or) (
s!:improve x) (s!:imp_or (cons (quote or) (cdr w)))))))))))

(put (quote or) (quote s!:tidy_fn) (quote s!:imp_or))

(de s!:imp_and (u) (prog (w x) (setq w (cdr u)) (cond ((atom w) (return t))) 
(setq x (car w)) (cond ((atom (cdr w)) (return x)) (t (cond ((
s!:boolean_jumpable x) (return (list (quote cond) (list x (s!:imp_and (cons (
quote and) (cdr w)))) (list t nil)))) (t (return (list (quote and) (
s!:improve x) (s!:imp_and (cons (quote and) (cdr w)))))))))))

(put (quote and) (quote s!:tidy_fn) (quote s!:imp_and))

(de s!:alwayseasy (x) t)

(put (quote quote) (quote s!:helpeasy) (function s!:alwayseasy))

(put (quote function) (quote s!:helpeasy) (function s!:alwayseasy))

(de s!:easyifarg (x) (or (null (cdr x)) (and (null (cddr x)) (s!:iseasy (cadr
x)))))

(put (quote ncons) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote car) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote cdr) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote qcar) (quote s!:helpeasy) (function s!:easyifarg))

(put (quote qcdr) (quote s!:helpeasy) (function s!:easyifarg))

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

(de s!:easygetv (x) (prog (a2) (setq a2 (caddr x)) (cond ((and (null 
!*carcheckflag) (fixp a2) (geq a2 0) (lessp a2 256)) (return (s!:iseasy (cadr
x)))) (t (return nil)))))

(put (quote getv) (quote s!:helpeasy) (function s!:easygetv))

(put (quote svref) (quote s!:heapeasy) (function s!:easygetv))

(de s!:easyqgetv (x) (prog (a2) (setq a2 (caddr x)) (cond ((and (fixp a2) (
geq a2 0) (lessp a2 256)) (return (s!:iseasy (cadr x)))) (t (return nil)))))

(put (quote qgetv) (quote s!:helpeasy) (function s!:easyqgetv))

(put (quote qsvref) (quote s!:heapeasy) (function s!:easyqgetv))

(de s!:iseasy (x) (prog (h) (cond ((atom x) (return t))) (cond ((not (atom (
car x))) (return nil))) (cond ((setq h (get (car x) (quote s!:helpeasy))) (
return (funcall h x))) (t (return nil)))))

(de s!:instate_local_decs (v d w) (prog (fg) (cond ((fluidp v) (return w))) (
prog (var1069) (setq var1069 d) lab1068 (cond ((null var1069) (return nil))) 
(prog (z) (setq z (car var1069)) (cond ((and (eqcar z (quote special)) (memq 
v (cdr z))) (setq fg t)))) (setq var1069 (cdr var1069)) (go lab1068)) (cond (
fg (progn (make!-special v) (setq w (cons v w))))) (return w)))

(de s!:residual_local_decs (d w) (prog nil (prog (var1073) (setq var1073 d) 
lab1072 (cond ((null var1073) (return nil))) (prog (z) (setq z (car var1073))
(cond ((eqcar z (quote special)) (prog (var1071) (setq var1071 (cdr z)) 
lab1070 (cond ((null var1071) (return nil))) (prog (v) (setq v (car var1071))
(cond ((and (not (fluidp v)) (not (globalp v)) (not (keywordp v))) (progn (
make!-special v) (setq w (cons v w)))))) (setq var1071 (cdr var1071)) (go 
lab1070))))) (setq var1073 (cdr var1073)) (go lab1072)) (return w)))

(de s!:cancel_local_decs (w) (unfluid w))

(de s!:find_local_decs (body isprog) (prog (w local_decs) (cond ((and (not 
isprog) body (null (cdr body)) (eqcar (car body) (quote progn))) (setq body (
cdar body)))) (prog nil lab1074 (cond ((null (and body (or (eqcar (car body) 
(quote declare)) (stringp (car body))))) (return nil))) (progn (cond ((
stringp (car body)) (setq w (cons (car body) w))) (t (setq local_decs (append
local_decs (cdar body))))) (setq body (cdr body))) (go lab1074)) (prog nil 
lab1075 (cond ((null w) (return nil))) (progn (setq body (cons (car w) body))
(setq w (cdr w))) (go lab1075)) (return (cons local_decs body))))

(de s!:comlambda (bvl body args env context) (prog (s nbvl fluids fl1 w 
local_decs) (cond ((and (equal context 0) s!:maybe_values) (s!:outopcode0 (
quote ONEVALUE) (quote (onevalue))))) (setq nbvl (setq s (cdr env))) (setq 
body (s!:find_local_decs body nil)) (setq local_decs (car body)) (setq body (
cdr body)) (cond ((atom body) (setq body nil)) (t (cond ((atom (cdr body)) (
setq body (car body))) (t (setq body (cons (quote progn) body)))))) (setq w 
nil) (prog (var1077) (setq var1077 bvl) lab1076 (cond ((null var1077) (return
nil))) (prog (v) (setq v (car var1077)) (setq w (s!:instate_local_decs v 
local_decs w))) (setq var1077 (cdr var1077)) (go lab1076)) (prog (var1079) (
setq var1079 bvl) lab1078 (cond ((null var1079) (return nil))) (prog (v) (
setq v (car var1079)) (progn (cond ((or (globalp v) (keywordp v)) (error 0 (
list "attempt to bind global" v)))) (cond ((fluidp v) (prog (g) (setq g (
gensym)) (setq nbvl (cons g nbvl)) (setq fl1 (cons v fl1)) (setq fluids (cons
(cons v g) fluids)))) (t (setq nbvl (cons v nbvl)))) (cond ((equal (car args
) nil) (s!:outstack 1)) (t (progn (s!:comval (car args) env 1) (s!:outopcode0
(quote PUSH) (quote (PUSH)))))) (rplacd env (cons 0 (cdr env))) (setq args (
cdr args)))) (setq var1079 (cdr var1079)) (go lab1078)) (rplacd env nbvl) (
cond (fluids (progn (setq fl1 (s!:vecof fl1)) (s!:outopcode1lit (quote 
FREEBIND) fl1 env) (prog (var1081) (setq var1081 (cons nil fluids)) lab1080 (
cond ((null var1081) (return nil))) (prog (v) (setq v (car var1081)) (rplacd 
env (cons 0 (cdr env)))) (setq var1081 (cdr var1081)) (go lab1080)) (rplacd 
env (cons (plus 2 (length fluids)) (cdr env))) (prog (var1083) (setq var1083 
fluids) lab1082 (cond ((null var1083) (return nil))) (prog (v) (setq v (car 
var1083)) (s!:comval (list (quote setq) (car v) (cdr v)) env 2)) (setq 
var1083 (cdr var1083)) (go lab1082))))) (setq w (s!:residual_local_decs 
local_decs w)) (s!:comval body env 1) (s!:cancel_local_decs w) (cond (fluids 
(s!:outopcode0 (quote FREERSTR) (quote (FREERSTR))))) (s!:outlose (length bvl
)) (rplacd env s)))

(de s!:loadliteral (x env) (cond ((member!*!* (list (quote quote) x) 
s!:a_reg_values) nil) (t (progn (cond ((equal x nil) (s!:outopcode0 (quote 
VNIL) (quote (loadlit nil)))) (t (s!:outopcode1lit (quote LOADLIT) x env))) (
setq s!:a_reg_values (list (list (quote quote) x)))))))

(de s!:comquote (x env context) (progn (cond ((and (equal context 0) 
s!:maybe_values) (s!:outopcode0 (quote ONEVALUE) (quote (onevalue))))) (cond 
((leq context 1) (s!:loadliteral (cadr x) env)))))

(put (quote quote) (quote s!:compfn) (function s!:comquote))

(fluid (quote (s!:current_exitlab s!:current_proglabels s!:local_macros)))

(de s!:comval_m (x env context s!:local_macros) (s!:comval x env context))

(de s!:comflet (x env context) (prog (w r g save) (setq save (cdr env)) (prog
 (var1085) (setq var1085 (cadr x)) lab1084 (cond ((null var1085) (return nil)
)) (prog (d) (setq d (car var1085)) (progn (setq g (gensym)) (s!:comval (list
(quote function) (cons (quote lambda) (cdr d))) env context) (s!:outopcode0 
(quote PUSH) (quote (PUSH))) (rplacd env (cons g (cdr env))) (setq r (cons (
cons (car d) g) r)))) (setq var1085 (cdr var1085)) (go lab1084)) (s!:comval_m
(cons (quote progn) (cddr x)) env context (append r s!:local_macros)) (
s!:outlose (length (cadr x))) (rplacd env save)))

(put (quote flet) (quote s!:compfn) (function s!:comflet))

(de s!:comlabels (x env context) (prog (w w1 r g) (prog (var1087) (setq 
var1087 (cadr x)) lab1086 (cond ((null var1087) (return nil))) (prog (d) (
setq d (car var1087)) (progn (setq g (gensym)) (setq w (cons (list (quote 
setq) g (list (quote function) (cons (quote lambda) (cdr d)))) w)) (setq w1 (
cons (list g) w1)) (setq r (cons (cons (car d) g) r)))) (setq var1087 (cdr 
var1087)) (go lab1086)) (setq x (cons (quote let) (cons (reverse w1) (append 
w (cddr x))))) (return (s!:comval_m x env context (append r s!:local_macros))
)))

(put (quote labels) (quote s!:compfn) (function s!:comlabels))

(de s!:commacrolet (x env context) (s!:comval_m (cons (quote progn) (cddr x))
env context (append (cadr x) s!:local_macros)))

(put (quote macrolet) (quote s!:compfn) (function s!:commacrolet))

(de s!:local_macro (fn) (prog (w y) (setq w (cons (list nil nil nil 
s!:local_macros) s!:lexical_env)) (prog nil lab1088 (cond ((null w) (return 
nil))) (progn (setq y (atsoc fn (cadddr (car w)))) (cond (y (setq w nil)) (t 
(setq w (cdr w))))) (go lab1088)) (return y)))

(de s!:comfunction (x env context) (progn (cond ((and (equal context 0) 
s!:maybe_values) (s!:outopcode0 (quote ONEVALUE) (quote (onevalue))))) (cond 
((leq context 1) (progn (setq x (cadr x)) (cond ((eqcar x (quote lambda)) (
prog (g w s!:used_lexicals) (setq s!:has_closure t) (setq g (hashtagged!-name
(quote lambda) (cdr x))) (cond (s!:used_lexicals (s!:compile1 g (cons (
gensym) (cadr x)) (cddr x) (cons (list (cdr env) s!:current_exitlab 
s!:current_proglabels s!:local_macros) s!:lexical_env))) (t (s!:compile1 g (
cadr x) (cddr x) (cons (list (cdr env) s!:current_exitlab 
s!:current_proglabels s!:local_macros) s!:lexical_env)))) (s!:loadliteral g 
env) (setq w (length (cdr env))) (cond (s!:used_lexicals (progn (setq 
s!:has_closure t) (cond ((greaterp w 4095) (error 0 "stack frame > 4095")) (t
(cond ((greaterp w 255) (s!:outopcode2 (quote BIGSTACK) (plus 128 (truncate 
w 256)) (logand w 255) (list (quote CLOSURE) w))) (t (s!:outopcode1 (quote 
CLOSURE) w x)))))))))) (t (cond ((setq context (s!:local_macro x)) (progn (
cond ((atom (cdr context)) (s!:comatom (cdr context) env 1)) (t (error 0 
"(function <local macro>) is illegal"))))) (t (s!:loadliteral x env))))))))))

(put (quote function) (quote s!:compfn) (function s!:comfunction))

(de s!:should_be_fluid (x) (cond ((not (or (fluidp x) (globalp x) (keywordp x
))) (progn (cond (!*pwrds (progn (cond ((neq (posn) 0) (terpri))) (princ 
"+++ ") (prin x) (princ " declared fluid") (terpri)))) (fluid (list x)) nil))
))

(de s!:find_lexical (x lex n) (prog (p) (cond ((null lex) (return nil))) (
setq p (memq x (caar lex))) (cond (p (progn (cond ((not (memq x 
s!:used_lexicals)) (setq s!:used_lexicals (cons x s!:used_lexicals)))) (
return (list n (length p))))) (t (return (s!:find_lexical x (cdr lex) (plus n
1)))))))

(global (quote (s!:loadlocs)))

(setq s!:loadlocs (s!:vecof (quote (LOADLOC0 LOADLOC1 LOADLOC2 LOADLOC3 
LOADLOC4 LOADLOC5 LOADLOC6 LOADLOC7 LOADLOC8 LOADLOC9 LOADLOC10 LOADLOC11))))

(de s!:comatom (x env context) (prog (n w) (cond ((and (equal context 0) 
s!:maybe_values) (s!:outopcode0 (quote ONEVALUE) (quote (onevalue))))) (cond 
((greaterp context 1) (return nil)) (t (cond ((or (null x) (not (symbolp x)))
(return (s!:loadliteral x env)))))) (setq n 0) (setq w (cdr env)) (prog nil 
lab1089 (cond ((null (and w (not (eqcar w x)))) (return nil))) (progn (setq n
(add1 n)) (setq w (cdr w))) (go lab1089)) (cond (w (progn (setq w (cons (
quote loc) w)) (cond ((member!*!* w s!:a_reg_values) (return nil)) (t (progn 
(cond ((lessp n 12) (s!:outopcode0 (getv s!:loadlocs n) (list (quote LOADLOC)
x))) (t (cond ((greaterp n 4095) (error 0 "stack frame > 4095")) (t (cond ((
greaterp n 255) (s!:outopcode2 (quote BIGSTACK) (truncate n 256) (logand n 
255) (list (quote LOADLOC) x))) (t (s!:outopcode1 (quote LOADLOC) n x))))))) 
(setq s!:a_reg_values (list w)) (return nil))))))) (cond ((setq w (
s!:find_lexical x s!:lexical_env 0)) (progn (cond ((member!*!* (cons (quote 
lex) w) s!:a_reg_values) (return nil))) (s!:outlexref (quote LOADLEX) (length
(cdr env)) (car w) (cadr w) x) (setq s!:a_reg_values (list (cons (quote lex)
w))) (return nil)))) (s!:should_be_fluid x) (cond ((flagp x (quote 
constant!?)) (return (s!:loadliteral (eval x) env)))) (setq w (cons (quote 
free) x)) (cond ((member!*!* w s!:a_reg_values) (return nil))) (
s!:outopcode1lit (quote LOADFREE) x env) (setq s!:a_reg_values (list w))))

(flag (quote (t !$EOL!$ !$EOF!$)) (quote constant!?))

(de s!:islocal (x env) (prog (n w) (cond ((or (null x) (not (symbolp x)) (eq 
x t)) (return 99999))) (setq n 0) (setq w (cdr env)) (prog nil lab1090 (cond 
((null (and w (not (eqcar w x)))) (return nil))) (progn (setq n (add1 n)) (
setq w (cdr w))) (go lab1090)) (cond (w (return n)) (t (return 99999)))))

(de s!:load2 (a b env) (progn (cond ((s!:iseasy b) (prog (wa wb w) (setq wa (
s!:islocal a env)) (setq wb (s!:islocal b env)) (cond ((and (lessp wa 4) (
lessp wb 4)) (progn (cond ((and (equal wa 0) (equal wb 1)) (setq w (quote 
LOC0LOC1))) (t (cond ((and (equal wa 1) (equal wb 2)) (setq w (quote LOC1LOC2
))) (t (cond ((and (equal wa 2) (equal wb 3)) (setq w (quote LOC2LOC3))) (t (
cond ((and (equal wa 1) (equal wb 0)) (setq w (quote LOC1LOC0))) (t (cond ((
and (equal wa 2) (equal wb 1)) (setq w (quote LOC2LOC1))) (t (cond ((and (
equal wa 3) (equal wb 2)) (setq w (quote LOC3LOC2)))))))))))))) (cond (w (
progn (s!:outopcode0 w (list (quote LOCLOC) a b)) (return nil))))))) (
s!:comval a env 1) (setq s!:a_reg_values nil) (s!:comval b env 1) (return nil
))) (t (cond (!*ord (progn (s!:comval a env 1) (s!:outopcode0 (quote PUSH) (
quote (PUSH))) (rplacd env (cons 0 (cdr env))) (setq s!:a_reg_values nil) (
s!:comval b env 1) (s!:outopcode0 (quote POP) (quote (POP))) (rplacd env (
cddr env)) t)) (t (cond ((s!:iseasy a) (progn (s!:comval b env 1) (setq 
s!:a_reg_values nil) (s!:comval a env 1) t)) (t (progn (s!:comval b env 1) (
s!:outopcode0 (quote PUSH) (quote (PUSH))) (rplacd env (cons 0 (cdr env))) (
setq s!:a_reg_values nil) (s!:comval a env 1) (s!:outopcode0 (quote POP) (
quote (POP))) (rplacd env (cddr env)) nil)))))))))

(global (quote (s!:carlocs s!:cdrlocs s!:caarlocs)))

(setq s!:carlocs (s!:vecof (quote (CARLOC0 CARLOC1 CARLOC2 CARLOC3 CARLOC4 
CARLOC5 CARLOC6 CARLOC7 CARLOC8 CARLOC9 CARLOC10 CARLOC11))))

(setq s!:cdrlocs (s!:vecof (quote (CDRLOC0 CDRLOC1 CDRLOC2 CDRLOC3 CDRLOC4 
CDRLOC5))))

(setq s!:caarlocs (s!:vecof (quote (CAARLOC0 CAARLOC1 CAARLOC2 CAARLOC3))))

(flag (quote (plus2 times2 eq equal)) (quote s!:symmetric))

(flag (quote (qcar qcdr car cdr caar cadr cdar cddr ncons add1 sub1 numberp 
length)) (quote s!:onearg))

(flag (quote (cons xcons list2 get flagp plus2 difference times2 greaterp 
lessp apply1 eq equal getv qgetv eqcar)) (quote s!:twoarg))

(flag (quote (apply2 list2!* list3 acons)) (quote s!:threearg))

(de s!:comcall (x env context) (prog (fn args nargs op s w1 w2 w3 sw) (setq 
fn (car x)) (cond ((not (symbolp fn)) (error 0 
"non-symbol used in function position"))) (setq args (prog (var1092 var1093) 
(setq var1092 (cdr x)) lab1091 (cond ((null var1092) (return (reversip 
var1093)))) (prog (v) (setq v (car var1092)) (setq var1093 (cons (s!:improve 
v) var1093))) (setq var1092 (cdr var1092)) (go lab1091))) (setq nargs (length
args)) (setq s (cdr env)) (cond ((and (equal context 0) s!:maybe_values) (
s!:outopcode0 (quote ONEVALUE) (quote (onevalue))))) (cond ((equal nargs 0) (
cond ((setq w2 (get fn (quote s!:builtin0))) (s!:outopcode1 (quote BUILTIN0) 
w2 fn)) (t (progn (s!:outopcode1lit (quote CALL0) fn env) (cond ((neq fn 
s!:current_function) (setq s!:maybe_values t))))))) (t (cond ((equal nargs 1)
(progn (cond ((and (or (equal fn (quote car)) (equal fn (quote qcar))) (
lessp (setq w2 (s!:islocal (car args) env)) 12)) (s!:outopcode0 (getv 
s!:carlocs w2) (list (quote carloc) (car args)))) (t (cond ((and (or (equal 
fn (quote cdr)) (equal fn (quote qcdr))) (lessp (setq w2 (s!:islocal (car 
args) env)) 6)) (s!:outopcode0 (getv s!:cdrlocs w2) (list (quote cdrloc) (car
args)))) (t (cond ((and (equal fn (quote caar)) (lessp (setq w2 (s!:islocal 
(car args) env)) 4)) (s!:outopcode0 (getv s!:caarlocs w2) (list (quote 
caarloc) (car args)))) (t (progn (s!:comval (car args) env 1) (cond ((flagp 
fn (quote s!:onearg)) (s!:outopcode0 fn (list fn))) (t (cond ((setq w2 (get 
fn (quote s!:builtin1))) (s!:outopcode1 (quote BUILTIN1) w2 fn)) (t (progn (
cond ((and (equal context 0) s!:maybe_values) (s!:outopcode0 (quote ONEVALUE)
(quote (onevalue))))) (s!:outopcode1lit (quote CALL1) fn env) (cond ((neq fn
s!:current_function) (setq s!:maybe_values t))))))))))))))))) (t (cond ((
equal nargs 2) (progn (setq sw (s!:load2 (car args) (cadr args) env)) (cond (
(flagp fn (quote s!:symmetric)) (setq sw nil))) (cond ((flagp fn (quote 
s!:twoarg)) (progn (cond (sw (s!:outopcode0 (quote SWOP) (quote (SWOP))))) (
s!:outopcode0 fn (list fn)))) (t (progn (setq w3 (get fn (quote s!:builtin2))
) (cond (sw (progn (cond (w3 (s!:outopcode1 (quote BUILTIN2R) w3 fn)) (t (
s!:outopcode1lit (quote CALL2R) fn env))))) (t (cond (w3 (s!:outopcode1 (
quote BUILTIN2) w3 fn)) (t (progn (cond ((and (equal context 0) 
s!:maybe_values) (s!:outopcode0 (quote ONEVALUE) (quote (onevalue))))) (
s!:outopcode1lit (quote CALL2) fn env) (cond ((neq fn s!:current_function) (
setq s!:maybe_values t))))))))))))) (t (cond ((equal nargs 3) (progn (cond ((
equal (car args) nil) (s!:outstack 1)) (t (progn (s!:comval (car args) env 1)
(s!:outopcode0 (quote PUSH) (quote (PUSHA3)))))) (rplacd env (cons 0 (cdr 
env))) (setq s!:a_reg_values nil) (cond ((s!:load2 (cadr args) (caddr args) 
env) (s!:outopcode0 (quote SWOP) (quote (SWOP))))) (cond ((flagp fn (quote 
s!:threearg)) (s!:outopcode0 (cond ((equal fn (quote list2!*)) (quote 
list2star)) (t fn)) (list fn))) (t (cond ((setq w2 (get fn (quote s!:builtin3
))) (s!:outopcode1 (quote BUILTIN3) w2 fn)) (t (progn (cond ((and (equal 
context 0) s!:maybe_values) (s!:outopcode0 (quote ONEVALUE) (quote (onevalue)
)))) (s!:outopcode1lit (quote CALL3) fn env) (cond ((neq fn 
s!:current_function) (setq s!:maybe_values t)))))))) (rplacd env (cddr env)))
) (t (prog (largs) (cond ((and (not (and (equal fn (quote apply3)) (equal 
nargs 4))) (not (and (equal fn (quote apply4)) (equal nargs 5)))) (progn (
setq w1 (car args)) (setq args (cdr args)) (setq w2 (car args)) (setq args (
cdr args)) (setq w3 (car args)) (setq args (cdr args)) (setq args (list w1 w2
w3 (cons (quote list) args))) (setq nargs 4)))) (setq largs (reverse args)) 
(prog (var1095) (setq var1095 (reverse (cddr largs))) lab1094 (cond ((null 
var1095) (return nil))) (prog (a) (setq a (car var1095)) (progn (cond ((null 
a) (s!:outstack 1)) (t (progn (s!:comval a env 1) (cond ((equal nargs 4) (
s!:outopcode0 (quote PUSH) (quote (PUSHA4)))) (t (s!:outopcode0 (quote PUSH) 
(quote (PUSHARG)))))))) (rplacd env (cons 0 (cdr env))) (setq s!:a_reg_values
nil))) (setq var1095 (cdr var1095)) (go lab1094)) (cond ((s!:load2 (cadr 
largs) (car largs) env) (s!:outopcode0 (quote SWOP) (quote (SWOP))))) (cond (
(and (equal fn (quote apply3)) (equal nargs 4)) (s!:outopcode0 (quote APPLY3)
(quote (APPLY3)))) (t (cond ((and (equal fn (quote apply4)) (equal nargs 5))
(s!:outopcode0 (quote APPLY4) (quote (APPLY4)))) (t (progn (cond ((and (
equal context 0) s!:maybe_values) (s!:outopcode0 (quote ONEVALUE) (quote (
onevalue))))) (s!:outopcode1lit (quote CALL4) fn env) (cond ((neq fn 
s!:current_function) (setq s!:maybe_values t)))))))) (rplacd env s)))))))))))
)

(de s!:ad_name (l) (cond ((equal (car l) (quote a)) (cond ((equal (cadr l) (
quote a)) (quote caar)) (t (quote cadr)))) (t (cond ((equal (cadr l) (quote a
)) (quote cdar)) (t (quote cddr))))))

(de s!:comcarcdr3 (x env context) (prog (name outer c1 c2) (setq name (cdr (
explode2 (car x)))) (setq x (list (s!:ad_name name) (list (cond ((equal (
caddr name) (quote a)) (quote car)) (t (quote cdr))) (cadr x)))) (return (
s!:comval x env context))))

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

(de s!:comgetv (x env context) (cond (!*carcheckflag (s!:comcall x env 
context)) (t (s!:comval (cons (quote qgetv) (cdr x)) env context))))

(put (quote getv) (quote s!:compfn) (function s!:comgetv))

(de s!:comqgetv (x env context) (cond ((and (fixp (caddr x)) (geq (caddr x) 0
) (lessp (caddr x) 256)) (progn (s!:comval (cadr x) env 1) (s!:outopcode1 (
quote QGETVN) (caddr x) (caddr x)))) (t (s!:comcall x env context))))

(put (quote qgetv) (quote s!:compfn) (function s!:comqgetv))

(de s!:comget (x env context) (prog (a b c w) (setq a (cadr x)) (setq b (
caddr x)) (setq c (cdddr x)) (cond ((eqcar b (quote quote)) (progn (setq b (
cadr b)) (setq w (symbol!-make!-fastget b nil)) (cond (c (progn (cond (w (
progn (cond ((s!:load2 a b env) (s!:outopcode0 (quote SWOP) (quote (SWOP)))))
(s!:outopcode1 (quote FASTGET) (logor w 64) b))) (t (s!:comcall x env 
context))))) (t (progn (s!:comval a env 1) (cond (w (s!:outopcode1 (quote 
FASTGET) w b)) (t (s!:outopcode1lit (quote LITGET) b env)))))))) (t (
s!:comcall x env context)))))

(put (quote get) (quote s!:compfn) (function s!:comget))

(de s!:comflagp (x env context) (prog (a b) (setq a (cadr x)) (setq b (caddr 
x)) (cond ((eqcar b (quote quote)) (progn (setq b (cadr b)) (s!:comval a env 
1) (setq a (symbol!-make!-fastget b nil)) (cond (a (s!:outopcode1 (quote 
FASTGET) (logor a 128) b)) (t (s!:comcall x env context))))) (t (s!:comcall x
env context)))))

(put (quote flagp) (quote s!:compfn) (function s!:comflagp))

(de s!:complus (x env context) (s!:comval (expand (cdr x) (quote plus2)) env 
context))

(put (quote plus) (quote s!:compfn) (function s!:complus))

(put (quote !+) (quote s!:compfn) (function s!:complus))

(de s!:comtimes (x env context) (s!:comval (expand (cdr x) (quote times2)) 
env context))

(put (quote times) (quote s!:compfn) (function s!:comtimes))

(put (quote !*) (quote s!:compfn) (function s!:comtimes))

(de s!:comiplus (x env context) (s!:comval (expand (cdr x) (quote iplus2)) 
env context))

(put (quote iplus) (quote s!:compfn) (function s!:comiplus))

(de s!:comitimes (x env context) (s!:comval (expand (cdr x) (quote itimes2)) 
env context))

(put (quote itimes) (quote s!:compfn) (function s!:comitimes))

(de s!:complus2 (x env context) (prog (a b) (setq a (s!:improve (cadr x))) (
setq b (s!:improve (caddr x))) (return (cond ((and (numberp a) (numberp b)) (
s!:comval (plus a b) env context)) (t (cond ((equal a 0) (s!:comval b env 
context)) (t (cond ((equal a 1) (s!:comval (list (quote add1) b) env context)
) (t (cond ((equal b 0) (s!:comval a env context)) (t (cond ((equal b 1) (
s!:comval (list (quote add1) a) env context)) (t (cond ((equal b (minus 1)) (
s!:comval (list (quote sub1) a) env context)) (t (s!:comcall x env context)))
)))))))))))))

(put (quote plus2) (quote s!:compfn) (function s!:complus2))

(de s!:comdifference (x env context) (prog (a b) (setq a (s!:improve (cadr x)
)) (setq b (s!:improve (caddr x))) (return (cond ((and (numberp a) (numberp b
)) (s!:comval (difference a b) env context)) (t (cond ((equal a 0) (s!:comval
(list (quote minus) b) env context)) (t (cond ((equal b 0) (s!:comval a env 
context)) (t (cond ((equal b 1) (s!:comval (list (quote sub1) a) env context)
) (t (cond ((equal b (minus 1)) (s!:comval (list (quote add1) a) env context)
) (t (s!:comcall x env context))))))))))))))

(put (quote difference) (quote s!:compfn) (function s!:comdifference))

(de s!:comiplus2 (x env context) (prog (a b) (setq a (s!:improve (cadr x))) (
setq b (s!:improve (caddr x))) (return (cond ((and (numberp a) (numberp b)) (
s!:comval (plus a b) env context)) (t (cond ((equal a 1) (s!:comval (list (
quote iadd1) b) env context)) (t (cond ((equal b 1) (s!:comval (list (quote 
iadd1) a) env context)) (t (cond ((equal b (minus 1)) (s!:comval (list (quote
isub1) a) env context)) (t (s!:comcall x env context))))))))))))

(put (quote iplus2) (quote s!:compfn) (function s!:comiplus2))

(de s!:comidifference (x env context) (prog (a b) (setq a (s!:improve (cadr x
))) (setq b (s!:improve (caddr x))) (return (cond ((and (numberp a) (numberp 
b)) (s!:comval (difference a b) env context)) (t (cond ((equal b 1) (
s!:comval (list (quote isub1) a) env context)) (t (cond ((equal b (minus 1)) 
(s!:comval (list (quote iadd1) a) env context)) (t (s!:comcall x env context)
)))))))))

(put (quote idifference) (quote s!:compfn) (function s!:comidifference))

(de s!:comtimes2 (x env context) (prog (a b) (setq a (s!:improve (cadr x))) (
setq b (s!:improve (caddr x))) (return (cond ((and (numberp a) (numberp b)) (
s!:comval (times a b) env context)) (t (cond ((equal a 1) (s!:comval b env 
context)) (t (cond ((equal a (minus 1)) (s!:comval (list (quote minus) b) env
context)) (t (cond ((equal b 1) (s!:comval a env context)) (t (cond ((equal 
b (minus 1)) (s!:comval (list (quote minus) a) env context)) (t (s!:comcall x
env context))))))))))))))

(put (quote times2) (quote s!:compfn) (function s!:comtimes2))

(put (quote itimes2) (quote s!:compfn) (function s!:comtimes2))

(de s!:comminus (x env context) (prog (a b) (setq a (s!:improve (cadr x))) (
return (cond ((numberp a) (s!:comval (minus a) env context)) (t (cond ((eqcar
a (quote minus)) (s!:comval (cadr a) env context)) (t (s!:comcall x env 
context))))))))

(put (quote minus) (quote s!:compfn) (function s!:comminus))

(de s!:comminusp (x env context) (prog (a) (setq a (s!:improve (cadr x))) (
cond ((eqcar a (quote difference)) (return (s!:comval (cons (quote lessp) (
cdr a)) env context))) (t (return (s!:comcall x env context))))))

(put (quote minusp) (quote s!:compfn) (function s!:comminusp))

(de s!:comlessp (x env context) (prog (a b) (setq a (s!:improve (cadr x))) (
setq b (s!:improve (caddr x))) (cond ((equal b 0) (return (s!:comval (list (
quote minusp) a) env context))) (t (return (s!:comcall x env context))))))

(put (quote lessp) (quote s!:compfn) (function s!:comlessp))

(de s!:comiminusp (x env context) (prog (a) (setq a (s!:improve (cadr x))) (
cond ((eqcar a (quote difference)) (return (s!:comval (cons (quote ilessp) (
cdr a)) env context))) (t (return (s!:comcall x env context))))))

(put (quote iminusp) (quote s!:compfn) (function s!:comiminusp))

(de s!:comilessp (x env context) (prog (a b) (setq a (s!:improve (cadr x))) (
setq b (s!:improve (caddr x))) (cond ((equal b 0) (return (s!:comval (list (
quote iminusp) a) env context))) (t (return (s!:comcall x env context))))))

(put (quote ilessp) (quote s!:compfn) (function s!:comilessp))

(de s!:comprogn (x env context) (progn (setq x (cdr x)) (cond ((null x) (
s!:comval nil env context)) (t (prog (a) (setq a (car x)) (prog nil lab1096 (
cond ((null (setq x (cdr x))) (return nil))) (progn (s!:comval a env (cond ((
geq context 4) context) (t 2))) (setq a (car x))) (go lab1096)) (s!:comval a 
env context))))))

(put (quote progn) (quote s!:compfn) (function s!:comprogn))

(de s!:comprog1 (x env context) (prog nil (setq x (cdr x)) (cond ((null x) (
return (s!:comval nil env context)))) (s!:comval (car x) env context) (cond (
(null (setq x (cdr x))) (return nil))) (s!:outopcode0 (quote PUSH) (quote (
PUSH))) (rplacd env (cons 0 (cdr env))) (prog (var1098) (setq var1098 x) 
lab1097 (cond ((null var1098) (return nil))) (prog (a) (setq a (car var1098))
(s!:comval a env (cond ((geq context 4) context) (t 2)))) (setq var1098 (cdr
var1098)) (go lab1097)) (s!:outopcode0 (quote POP) (quote (POP))) (rplacd 
env (cddr env))))

(put (quote prog1) (quote s!:compfn) (function s!:comprog1))

(de s!:comprog2 (x env context) (prog (a) (setq x (cdr x)) (cond ((null x) (
return (s!:comval nil env context)))) (setq a (car x)) (s!:comval a env (cond
((geq context 4) context) (t 2))) (s!:comprog1 x env context)))

(put (quote prog2) (quote s!:compfn) (function s!:comprog2))

(de s!:outstack (n) (prog (w a) (setq w s!:current_block) (prog nil lab1099 (
cond ((null (and w (not (atom (car w))))) (return nil))) (setq w (cdr w)) (go
lab1099)) (cond ((eqcar w (quote PUSHNIL)) (setq a 1)) (t (cond ((eqcar w (
quote PUSHNIL2)) (setq a 2)) (t (cond ((eqcar w (quote PUSHNIL3)) (setq a 3))
(t (cond ((and w (numberp (setq a (car w))) (not (equal a 255)) (eqcar (cdr 
w) (quote PUSHNILS))) (progn (setq w (cdr w)) (setq s!:current_size (
difference s!:current_size 1)))) (t (setq a nil))))))))) (cond (a (progn (
setq s!:current_block (cdr w)) (setq s!:current_size (difference 
s!:current_size 1)) (setq n (plus n a))))) (cond ((equal n 1) (s!:outopcode0 
(quote PUSHNIL) (quote (PUSHNIL)))) (t (cond ((equal n 2) (s!:outopcode0 (
quote PUSHNIL2) (quote (PUSHNIL2)))) (t (cond ((equal n 3) (s!:outopcode0 (
quote PUSHNIL3) (quote (PUSHNIL3)))) (t (cond ((greaterp n 255) (progn (
s!:outopcode1 (quote PUSHNILS) 255 255) (s!:outstack (difference n 255)))) (t
(cond ((greaterp n 3) (s!:outopcode1 (quote PUSHNILS) n n)))))))))))))

(de s!:outlose (n) (prog (w a) (setq w s!:current_block) (prog nil lab1100 (
cond ((null (and w (not (atom (car w))))) (return nil))) (setq w (cdr w)) (go
lab1100)) (cond ((eqcar w (quote LOSE)) (setq a 1)) (t (cond ((eqcar w (
quote LOSE2)) (setq a 2)) (t (cond ((eqcar w (quote LOSE3)) (setq a 3)) (t (
cond ((and w (numberp (setq a (car w))) (not (equal a 255)) (eqcar (cdr w) (
quote LOSES))) (progn (setq w (cdr w)) (setq s!:current_size (difference 
s!:current_size 1)))) (t (setq a nil))))))))) (cond (a (progn (setq 
s!:current_block (cdr w)) (setq s!:current_size (difference s!:current_size 1
)) (setq n (plus n a))))) (cond ((equal n 1) (s!:outopcode0 (quote LOSE) (
quote (LOSE)))) (t (cond ((equal n 2) (s!:outopcode0 (quote LOSE2) (quote (
LOSE2)))) (t (cond ((equal n 3) (s!:outopcode0 (quote LOSE3) (quote (LOSE3)))
) (t (cond ((greaterp n 255) (progn (s!:outopcode1 (quote LOSES) 255 255) (
s!:outlose (difference n 255)))) (t (cond ((greaterp n 3) (s!:outopcode1 (
quote LOSES) n n)))))))))))))

(de s!:comprog (x env context) (prog (labs s bvl fluids n body local_decs w) 
(setq body (s!:find_local_decs (cddr x) t)) (setq local_decs (car body)) (
setq body (cdr body)) (setq n 0) (prog (var1102) (setq var1102 (cadr x)) 
lab1101 (cond ((null var1102) (return nil))) (prog (v) (setq v (car var1102))
(setq w (s!:instate_local_decs v local_decs w))) (setq var1102 (cdr var1102)
) (go lab1101)) (prog (var1104) (setq var1104 (cadr x)) lab1103 (cond ((null 
var1104) (return nil))) (prog (v) (setq v (car var1104)) (progn (cond ((or (
globalp v) (keywordp v)) (error 0 (list "attempt to bind global or keyword" v
)))) (cond ((fluidp v) (setq fluids (cons v fluids))) (t (progn (setq n (plus
n 1)) (setq bvl (cons v bvl))))))) (setq var1104 (cdr var1104)) (go lab1103)
) (setq s (cdr env)) (setq s!:current_exitlab (cons (cons nil (cons (gensym) 
s)) s!:current_exitlab)) (s!:outstack n) (rplacd env (append bvl (cdr env))) 
(cond (fluids (prog (fl1) (setq fl1 (s!:vecof fluids)) (s!:outopcode1lit (
quote FREEBIND) fl1 env) (prog (var1106) (setq var1106 (cons nil fluids)) 
lab1105 (cond ((null var1106) (return nil))) (prog (v) (setq v (car var1106))
(rplacd env (cons 0 (cdr env)))) (setq var1106 (cdr var1106)) (go lab1105)) 
(rplacd env (cons (plus 2 (length fluids)) (cdr env))) (cond ((equal context 
0) (setq context 1)))))) (prog (var1108) (setq var1108 body) lab1107 (cond ((
null var1108) (return nil))) (prog (a) (setq a (car var1108)) (cond ((atom a)
(progn (cond ((atsoc a labs) (progn (cond ((not (null a)) (progn (cond ((neq
(posn) 0) (terpri))) (princ "+++++ label ") (prin a) (princ 
" multiply defined") (terpri)))))) (t (setq labs (cons (cons a (cons (cons (
gensym) (cdr env)) nil)) labs)))))))) (setq var1108 (cdr var1108)) (go 
lab1107)) (setq s!:current_proglabels (cons labs s!:current_proglabels)) (
setq w (s!:residual_local_decs local_decs w)) (prog (var1110) (setq var1110 
body) lab1109 (cond ((null var1110) (return nil))) (prog (a) (setq a (car 
var1110)) (cond ((not (atom a)) (progn (cond ((not (eqcar a (quote quote))) (
s!:comval a env (plus context 4)))))) (t (prog (d) (setq d (atsoc a labs)) (
cond ((null (cddr d)) (progn (rplacd (cdr d) t) (s!:set_label (caadr d)))))))
)) (setq var1110 (cdr var1110)) (go lab1109)) (s!:cancel_local_decs w) (
s!:comval nil env context) (cond (fluids (s!:outopcode0 (quote FREERSTR) (
quote (FREERSTR))))) (s!:outlose n) (rplacd env s) (s!:set_label (cadar 
s!:current_exitlab)) (setq s!:current_exitlab (cdr s!:current_exitlab)) (setq
s!:current_proglabels (cdr s!:current_proglabels))))

(put (quote prog) (quote s!:compfn) (function s!:comprog))

(de s!:comtagbody (x env context) (prog (labs) (prog (var1112) (setq var1112 
(cdr x)) lab1111 (cond ((null var1112) (return nil))) (prog (a) (setq a (car 
var1112)) (cond ((atom a) (progn (cond ((atsoc a labs) (progn (cond ((not (
null a)) (progn (cond ((neq (posn) 0) (terpri))) (princ "+++++ label ") (prin
a) (princ " multiply defined") (terpri)))))) (t (setq labs (cons (cons a (
cons (cons (gensym) (cdr env)) nil)) labs)))))))) (setq var1112 (cdr var1112)
) (go lab1111)) (setq s!:current_proglabels (cons labs s!:current_proglabels)
) (prog (var1114) (setq var1114 (cdr x)) lab1113 (cond ((null var1114) (
return nil))) (prog (a) (setq a (car var1114)) (cond ((not (atom a)) (progn (
cond ((not (eqcar a (quote quote))) (s!:comval a env (plus context 4)))))) (t
(prog (d) (setq d (atsoc a labs)) (cond ((null (cddr d)) (progn (rplacd (cdr
d) t) (s!:set_label (caadr d))))))))) (setq var1114 (cdr var1114)) (go 
lab1113)) (s!:comval nil env context) (setq s!:current_proglabels (cdr 
s!:current_proglabels))))

(put (quote tagbody) (quote s!:compfn) (function s!:comtagbody))

(de s!:comprogv (x env context) (prog nil (setq x (cdr x)) (cond ((s!:load2 (
car x) (cadr x) env) (s!:outopcode0 (quote SWOP) (quote (SWOP))))) (
s!:outopcode0 (quote PVBIND) (quote (PVBIND))) (rplacd env (cons (quote (
pvbind)) (cons 0 (cdr env)))) (s!:comval (cons (quote progn) (cddr x)) env 1)
(s!:outopcode0 (quote PVRESTORE) (quote (PVRESTORE))) (rplacd env (cdddr env
))))

(put (quote progv) (quote s!:compfn) (function s!:comprogv))

(de s!:comprog!* (x env context) (prog (local_decs) (setq local_decs (
s!:find_local_decs (cddr x) t)) (setq x (list (quote !~block) nil (list (
quote let!*) (cadr x) (cons (quote declare) (car local_decs)) (cons (quote 
tagbody) (cdr local_decs))))) (return (s!:comval x env context))))

(put (quote prog!*) (quote s!:compfn) (function s!:comprog!*))

(de s!:comprog (x env context) (prog (local_decs) (setq local_decs (
s!:find_local_decs (cddr x) t)) (setq x (list (quote !~block) nil (list (
quote !~let) (cadr x) (cons (quote declare) (car local_decs)) (cons (quote 
tagbody) (cdr local_decs))))) (return (s!:comval x env context))))

(put (quote prog) (quote s!:compfn) (function s!:comprog))

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

(de s!:comthrow (x env context) (prog nil (cond ((null (cdr x)) (error 0 
"throw needs to provide a tag"))) (s!:comval (cadr x) env 1) (s!:outopcode0 (
quote PUSH) (quote (PUSH))) (rplacd env (cons 0 (cdr env))) (s!:comval (cond 
((cddr x) (caddr x)) (t nil)) env 1) (s!:outopcode0 (quote THROW) (quote (
THROW))) (rplacd env (cddr env))))

(put (quote throw) (quote s!:compfn) (quote s!:comthrow))

(de s!:comunwind!-protect (x env context) (prog (g) (setq g (gensym)) (
s!:comval (quote (load!-spid)) env 1) (s!:outjump (quote CATCH) g) (rplacd 
env (cons (list (quote unwind!-protect) (cddr x)) (cons 0 (cons 0 (cdr env)))
)) (s!:comval (cadr x) env context) (s!:outopcode0 (quote PROTECT) (quote (
PROTECT))) (s!:set_label g) (rplaca (cdr env) 0) (s!:comval (cons (quote 
progn) (cddr x)) env context) (s!:outopcode0 (quote UNPROTECT) (quote (
UNPROTECT))) (rplacd env (cddddr env))))

(put (quote unwind!-protect) (quote s!:compfn) (quote s!:comunwind!-protect))

(de s!:comdeclare (x env context) (prog nil (cond (!*pwrds (progn (princ 
"+++ ") (prin x) (princ " ignored") (terpri))))))

(put (quote declare) (quote s!:compfn) (function s!:comdeclare))

(de s!:expand_let (vl b) (prog (vars vals) (prog (var1116) (setq var1116 vl) 
lab1115 (cond ((null var1116) (return nil))) (prog (v) (setq v (car var1116))
(cond ((atom v) (progn (setq vars (cons v vars)) (setq vals (cons nil vals))
)) (t (cond ((atom (cdr v)) (progn (setq vars (cons (car v) vars)) (setq vals
(cons nil vals)))) (t (progn (setq vars (cons (car v) vars)) (setq vals (
cons (cadr v) vals)))))))) (setq var1116 (cdr var1116)) (go lab1115)) (return
(list (cons (cons (quote lambda) (cons vars b)) vals)))))

(de s!:comlet (x env context) (s!:comval (cons (quote progn) (s!:expand_let (
cadr x) (cddr x))) env context))

(put (quote !~let) (quote s!:compfn) (function s!:comlet))

(de s!:expand_let!* (vl local_decs b) (prog (r var val) (setq r (cons (cons (
quote declare) local_decs) b)) (prog (var1120) (setq var1120 (reverse vl)) 
lab1119 (cond ((null var1120) (return nil))) (prog (x) (setq x (car var1120))
(progn (setq val nil) (cond ((atom x) (setq var x)) (t (cond ((atom (cdr x))
(setq var (car x))) (t (progn (setq var (car x)) (setq val (cadr x))))))) (
prog (var1118) (setq var1118 local_decs) lab1117 (cond ((null var1118) (
return nil))) (prog (z) (setq z (car var1118)) (cond ((eqcar z (quote special
)) (cond ((memq var (cdr z)) (setq r (cons (list (quote declare) (list (quote
special) var)) r))))))) (setq var1118 (cdr var1118)) (go lab1117)) (setq r (
list (list (cons (quote lambda) (cons (list var) r)) val))))) (setq var1120 (
cdr var1120)) (go lab1119)) (cond ((eqcar (car r) (quote declare)) (setq r (
list (cons (quote lambda) (cons nil r))))) (t (setq r (cons (quote progn) r))
)) (return r)))

(de s!:comlet!* (x env context) (prog (b) (setq b (s!:find_local_decs (cddr x
) nil)) (return (s!:comval (s!:expand_let!* (cadr x) (car b) (cdr b)) env 
context))))

(put (quote let!*) (quote s!:compfn) (function s!:comlet!*))

(de s!:restore_stack (e1 e2) (prog (n) (setq n 0) (prog nil lab1122 (cond ((
null (not (equal e1 e2))) (return nil))) (progn (cond ((null e1) (error 0 
"bad block nesting with GO or RETURN-FROM"))) (cond ((and (numberp (car e1)) 
(greaterp (car e1) 2)) (progn (cond ((not (zerop n)) (s!:outlose n))) (setq n
(car e1)) (s!:outopcode0 (quote FREERSTR) (quote (FREERSTR))) (prog (i) (
setq i 1) lab1121 (cond ((minusp (times 1 (difference n i))) (return nil))) (
setq e1 (cdr e1)) (setq i (plus i 1)) (go lab1121)) (setq n 0))) (t (cond ((
equal (car e1) (quote (catch))) (progn (cond ((not (zerop n)) (s!:outlose n))
) (s!:outopcode0 (quote UNCATCH) (quote (UNCATCH))) (setq e1 (cdddr e1)) (
setq n 0))) (t (cond ((eqcar (car e1) (quote unwind!-protect)) (progn (cond (
(not (zerop n)) (s!:outlose n))) (s!:outopcode0 (quote PROTECT) (quote (
PROTECT))) (s!:comval (cons (quote progn) (cadar e1)) e1 2) (s!:outopcode0 (
quote UNPROTECT) (quote (UNPROTECT))) (setq e1 (cdddr e1)) (setq n 0))) (t (
cond ((equal (car e1) (quote (pvbind))) (progn (cond ((not (zerop n)) (
s!:outlose n))) (s!:outopcode0 (quote PVRESTORE) (quote (PVRESTORE))) (setq 
e1 (cddr e1)) (setq n 0))) (t (progn (setq e1 (cdr e1)) (setq n (plus n 1))))
)))))))) (go lab1122)) (cond ((not (zerop n)) (s!:outlose n)))))

(de s!:comgo (x env context) (prog (pl d) (cond ((lessp context 4) (progn (
princ "go not in program context") (terpri)))) (setq pl s!:current_proglabels
) (prog nil lab1123 (cond ((null (and pl (null d))) (return nil))) (progn (
setq d (atsoc (cadr x) (car pl))) (cond ((null d) (setq pl (cdr pl))))) (go 
lab1123)) (cond ((null d) (progn (cond ((neq (posn) 0) (terpri))) (princ 
"+++++ label ") (prin (cadr x)) (princ " not set") (terpri) (return nil)))) (
setq d (cadr d)) (s!:restore_stack (cdr env) (cdr d)) (s!:outjump (quote JUMP
) (car d))))

(put (quote go) (quote s!:compfn) (function s!:comgo))

(de s!:comreturn!-from (x env context) (prog (tag) (cond ((lessp context 4) (
progn (princ "+++++ return or return-from not in prog context") (terpri)))) (
setq x (cdr x)) (setq tag (car x)) (cond ((cdr x) (setq x (cadr x))) (t (setq
x nil))) (s!:comval x env (difference context 4)) (setq x (atsoc tag 
s!:current_exitlab)) (cond ((null x) (error 0 (list "invalid return-from" tag
)))) (setq x (cdr x)) (s!:restore_stack (cdr env) (cdr x)) (s!:outjump (quote
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

(de s!:jumpif (neg x env lab) (prog (w w1 j) top (cond ((null x) (progn (cond
((not neg) (s!:outjump (quote JUMP) lab))) (return nil))) (t (cond ((or (eq 
x t) (and (eqcar x (quote quote)) (cadr x)) (and (atom x) (not (symbolp x))))
(progn (cond (neg (s!:outjump (quote JUMP) lab))) (return nil))) (t (cond ((
lessp (setq w (s!:islocal x env)) 5) (return (s!:outjump (getv (cond (neg 
s!:jumplts) (t s!:jumplnils)) w) lab))) (t (cond ((and (equal w 99999) (
symbolp x)) (progn (s!:should_be_fluid x) (setq w (list (cond (neg (quote 
JUMPFREET)) (t (quote JUMPFREENIL))) x x)) (return (
s!:record_literal_for_jump w env lab))))))))))) (cond ((and (not (atom x)) (
atom (car x)) (setq w (get (car x) (quote s!:testfn)))) (return (funcall w 
neg x env lab)))) (cond ((not (atom x)) (progn (setq w (s!:improve x)) (cond 
((or (atom w) (not (eqcar x (car w)))) (progn (setq x w) (go top)))) (cond ((
setq w1 (s!:local_macro (car w))) (progn (cond ((atom (cdr w1)) (setq x (cons
(quote funcall) (cons (cdr w1) (cdr w))))) (t (setq x (funcall (cons (quote 
lambda) (cdr w1)) w)))) (go top)))) (cond ((and (setq w1 (get (car w) (quote 
s!:compilermacro))) (setq w1 (funcall w1 w env 1))) (progn (setq x w1) (go 
top))))))) remacro (cond ((and (not (atom w)) (setq w1 (macro!-function (car 
w)))) (progn (setq w (funcall w1 w)) (cond ((or (atom w) (eqcar w (quote 
quote)) (get (car w) (quote s!:testfn)) (get (car w) (quote s!:compilermacro)
)) (progn (setq x w) (go top)))) (go remacro)))) (s!:comval x env 1) (setq w 
s!:current_block) (prog nil lab1124 (cond ((null (and w (not (atom (car w))))
) (return nil))) (setq w (cdr w)) (go lab1124)) (setq j (quote (JUMPNIL . 
JUMPT))) (cond (w (progn (setq w1 (car w)) (setq w (cdr w)) (cond ((equal w1 
(quote STORELOC0)) (progn (setq s!:current_block w) (setq s!:current_size (
difference s!:current_size 1)) (setq j (quote (JUMPST0NIL . JUMPST0T))))) (t 
(cond ((equal w1 (quote STORELOC1)) (progn (setq s!:current_block w) (setq 
s!:current_size (difference s!:current_size 1)) (setq j (quote (JUMPST1NIL . 
JUMPST1T))))) (t (cond ((equal w1 (quote STORELOC2)) (progn (setq 
s!:current_block w) (setq s!:current_size (difference s!:current_size 1)) (
setq j (quote (JUMPST2NIL . JUMPST2T))))) (t (cond ((eqcar w (quote BUILTIN1)
) (progn (setq s!:current_block (cdr w)) (setq s!:current_size (difference 
s!:current_size 2)) (setq j (cons (list (quote JUMPB1NIL) w1) (list (quote 
JUMPB1T) w1))))) (t (cond ((eqcar w (quote BUILTIN2)) (progn (setq 
s!:current_block (cdr w)) (setq s!:current_size (difference s!:current_size 2
)) (setq j (cons (list (quote JUMPB2NIL) w1) (list (quote JUMPB2T) w1))))))))
))))))))) (return (s!:outjump (cond (neg (cdr j)) (t (car j))) lab))))

(de s!:testnot (neg x env lab) (s!:jumpif (not neg) (cadr x) env lab))

(put (quote null) (quote s!:testfn) (function s!:testnot))

(put (quote not) (quote s!:testfn) (function s!:testnot))

(de s!:testatom (neg x env lab) (prog (w) (cond ((lessp (setq w (s!:islocal (
cadr x) env)) 4) (return (s!:outjump (getv (cond (neg s!:jumpatoms) (t 
s!:jumpnatoms)) w) lab)))) (s!:comval (cadr x) env 1) (cond (neg (s!:outjump 
(quote JUMPATOM) lab)) (t (s!:outjump (quote JUMPNATOM) lab)))))

(put (quote atom) (quote s!:testfn) (function s!:testatom))

(de s!:testconsp (neg x env lab) (prog (w) (cond ((lessp (setq w (s!:islocal 
(cadr x) env)) 4) (return (s!:outjump (getv (cond (neg s!:jumpnatoms) (t 
s!:jumpatoms)) w) lab)))) (s!:comval (cadr x) env 1) (cond (neg (s!:outjump (
quote JUMPNATOM) lab)) (t (s!:outjump (quote JUMPATOM) lab)))))

(put (quote consp) (quote s!:testfn) (function s!:testconsp))

(de s!:comcond (x env context) (prog (l1 l2 w) (setq l1 (gensym)) (prog nil 
lab1125 (cond ((null (setq x (cdr x))) (return nil))) (progn (setq w (car x))
(cond ((atom (cdr w)) (progn (s!:comval (car w) env 1) (s!:outjump (quote 
JUMPT) l1) (setq l2 nil))) (t (progn (cond ((equal (car w) t) (setq l2 nil)) 
(t (progn (setq l2 (gensym)) (s!:jumpif nil (car w) env l2)))) (setq w (cdr w
)) (cond ((null (cdr w)) (setq w (car w))) (t (setq w (cons (quote progn) w))
)) (s!:comval w env context) (cond (l2 (progn (s!:outjump (quote JUMP) l1) (
s!:set_label l2))) (t (setq x (quote (nil))))))))) (go lab1125)) (cond (l2 (
s!:comval nil env context))) (s!:set_label l1)))

(put (quote cond) (quote s!:compfn) (function s!:comcond))

(de s!:comif (x env context) (prog (l1 l2) (setq l2 (gensym)) (s!:jumpif nil 
(cadr x) env l2) (setq x (cddr x)) (s!:comval (car x) env context) (setq x (
cdr x)) (cond ((or x (and (lessp context 2) (setq x (quote (nil))))) (progn (
setq l1 (gensym)) (s!:outjump (quote JUMP) l1) (s!:set_label l2) (s!:comval (
car x) env context) (s!:set_label l1))) (t (s!:set_label l2)))))

(put (quote if) (quote s!:compfn) (function s!:comif))

(de s!:comwhen (x env context) (prog (l2) (setq l2 (gensym)) (cond ((lessp 
context 2) (progn (s!:comval (cadr x) env 1) (s!:outjump (quote JUMPNIL) l2))
) (t (s!:jumpif nil (cadr x) env l2))) (s!:comval (cons (quote progn) (cddr x
)) env context) (s!:set_label l2)))

(put (quote when) (quote s!:compfn) (function s!:comwhen))

(de s!:comunless (x env context) (s!:comwhen (list!* (quote when) (list (
quote not) (cadr x)) (cddr x)) env context))

(put (quote unless) (quote s!:compfn) (function s!:comunless))

(de s!:comicase (x env context) (prog (l1 labs labassoc w) (setq x (cdr x)) (
prog (var1127) (setq var1127 (cdr x)) lab1126 (cond ((null var1127) (return 
nil))) (prog (v) (setq v (car var1127)) (progn (setq w (assoc!*!* v labassoc)
) (cond (w (setq l1 (cons (cdr w) l1))) (t (progn (setq l1 (gensym)) (setq 
labs (cons l1 labs)) (setq labassoc (cons (cons v l1) labassoc))))))) (setq 
var1127 (cdr var1127)) (go lab1126)) (s!:comval (car x) env 1) (s!:outjump (
quote ICASE) (reversip labs)) (setq l1 (gensym)) (prog (var1129) (setq 
var1129 labassoc) lab1128 (cond ((null var1129) (return nil))) (prog (v) (
setq v (car var1129)) (progn (s!:set_label (cdr v)) (s!:comval (car v) env 
context) (s!:outjump (quote JUMP) l1))) (setq var1129 (cdr var1129)) (go 
lab1128)) (s!:set_label l1)))

(put (quote s!:icase) (quote s!:compfn) (function s!:comicase))

(put (quote JUMPLITEQ!*) (quote s!:opcode) (get (quote JUMPLITEQ) (quote 
s!:opcode)))

(put (quote JUMPLITNE!*) (quote s!:opcode) (get (quote JUMPLITNE) (quote 
s!:opcode)))

(de s!:jumpliteql (val lab env) (prog (w) (cond ((or (idp val) (eq!-safe val)
) (progn (setq w (list (quote JUMPLITEQ!*) val val)) (
s!:record_literal_for_jump w env lab))) (t (progn (s!:outopcode0 (quote PUSH)
(quote (PUSH))) (s!:loadliteral val env) (s!:outopcode1 (quote BUILTIN2) (
get (quote eql) (quote s!:builtin2)) (quote eql)) (s!:outjump (quote JUMPT) 
lab) (flag (list lab) (quote s!:jumpliteql)) (s!:outopcode0 (quote POP) (
quote (POP))))))))

(de s!:casebranch (sw env dflt) (prog (size w w1 r g) (setq size (plus 4 (
truncate (length sw) 2))) (prog nil lab1130 (cond ((null (or (equal (
remainder size 2) 0) (equal (remainder size 3) 0) (equal (remainder size 5) 0
) (equal (remainder size 13) 0))) (return nil))) (setq size (plus size 1)) (
go lab1130)) (prog (var1132) (setq var1132 sw) lab1131 (cond ((null var1132) 
(return nil))) (prog (p) (setq p (car var1132)) (progn (setq w (remainder (
eqlhash (car p)) size)) (setq w1 (assoc!*!* w r)) (cond (w1 (rplacd (cdr w1) 
(cons p (cddr w1)))) (t (setq r (cons (list w (gensym) p) r)))))) (setq 
var1132 (cdr var1132)) (go lab1131)) (s!:outopcode0 (quote PUSH) (quote (PUSH
))) (rplacd env (cons 0 (cdr env))) (s!:outopcode1lit (quote CALL1) (quote 
eqlhash) env) (s!:loadliteral size env) (setq g (gensym)) (s!:outopcode1 (
quote BUILTIN2) (get (quote iremainder) (quote s!:builtin2)) (quote 
iremainder)) (s!:outjump (quote ICASE) (cons g (prog (i var1134) (setq i 0) 
lab1133 (cond ((minusp (times 1 (difference (difference size 1) i))) (return 
(reversip var1134)))) (setq var1134 (cons (progn (setq w (assoc!*!* i r)) (
cond (w (cadr w)) (t g))) var1134)) (setq i (plus i 1)) (go lab1133)))) (prog
 (var1138) (setq var1138 r) lab1137 (cond ((null var1138) (return nil))) (
prog (p) (setq p (car var1138)) (progn (s!:set_label (cadr p)) (s!:outopcode0
(quote POP) (quote (POP))) (prog (var1136) (setq var1136 (cddr p)) lab1135 (
cond ((null var1136) (return nil))) (prog (q) (setq q (car var1136)) (
s!:jumpliteql (car q) (cdr q) env)) (setq var1136 (cdr var1136)) (go lab1135)
) (s!:outjump (quote JUMP) dflt))) (setq var1138 (cdr var1138)) (go lab1137))
(s!:set_label g) (s!:outopcode0 (quote POP) (quote (POP))) (s!:outjump (
quote JUMP) dflt) (rplacd env (cddr env))))

(de s!:comcase (x env context) (prog (keyform blocks v w g dflt sw keys 
nonnum) (setq x (cdr x)) (setq keyform (car x)) (prog (y) (setq y (cdr x)) 
lab1141 (cond ((null y) (return nil))) (progn (setq w (assoc!*!* (cdar y) 
blocks)) (cond (w (setq g (cdr w))) (t (progn (setq g (gensym)) (setq blocks 
(cons (cons (cdar y) g) blocks))))) (setq w (caar y)) (cond ((and (null (cdr 
y)) (or (equal w t) (equal w (quote otherwise)))) (setq dflt g)) (t (progn (
cond ((atom w) (setq w (list w)))) (prog (var1140) (setq var1140 w) lab1139 (
cond ((null var1140) (return nil))) (prog (n) (setq n (car var1140)) (progn (
cond ((or (idp n) (characterp n) (numberp n)) (progn (cond ((not (fixp n)) (
setq nonnum t))) (setq keys (cons n keys)) (setq sw (cons (cons n g) sw)))) (
t (error 0 (list "illegal case label" n)))))) (setq var1140 (cdr var1140)) (
go lab1139)))))) (setq y (cdr y)) (go lab1141)) (cond ((null dflt) (progn (
cond ((setq w (assoc!*!* nil blocks)) (setq dflt (cdr w))) (t (setq blocks (
cons (cons nil (setq dflt (gensym))) blocks))))))) (cond ((not nonnum) (progn
(setq keys (sort keys (function lessp))) (setq nonnum (car keys)) (setq g (
lastcar keys)) (cond ((lessp (difference g nonnum) (times 2 (length keys))) (
progn (cond ((not (equal nonnum 0)) (progn (setq keyform (list (quote 
xdifference) keyform nonnum)) (setq sw (prog (var1143 var1144) (setq var1143 
sw) lab1142 (cond ((null var1143) (return (reversip var1144)))) (prog (y) (
setq y (car var1143)) (setq var1144 (cons (cons (difference (car y) nonnum) (
cdr y)) var1144))) (setq var1143 (cdr var1143)) (go lab1142)))))) (s!:comval 
keyform env 1) (setq w nil) (prog (i) (setq i 0) lab1145 (cond ((minusp (
times 1 (difference g i))) (return nil))) (cond ((setq v (assoc!*!* i sw)) (
setq w (cons (cdr v) w))) (t (setq w (cons dflt w)))) (setq i (plus i 1)) (go
lab1145)) (setq w (cons dflt (reversip w))) (s!:outjump (quote ICASE) w) (
setq nonnum nil))) (t (setq nonnum t)))))) (cond (nonnum (progn (s!:comval 
keyform env 1) (cond ((lessp (length sw) 7) (progn (prog (var1147) (setq 
var1147 sw) lab1146 (cond ((null var1147) (return nil))) (prog (y) (setq y (
car var1147)) (s!:jumpliteql (car y) (cdr y) env)) (setq var1147 (cdr var1147
)) (go lab1146)) (s!:outjump (quote JUMP) dflt))) (t (s!:casebranch sw env 
dflt)))))) (setq g (gensym)) (prog (var1149) (setq var1149 blocks) lab1148 (
cond ((null var1149) (return nil))) (prog (v) (setq v (car var1149)) (progn (
s!:set_label (cdr v)) (cond ((flagp (cdr v) (quote s!:jumpliteql)) (
s!:outlose 1))) (s!:comval (cons (quote progn) (car v)) env context) (
s!:outjump (quote JUMP) g))) (setq var1149 (cdr var1149)) (go lab1148)) (
s!:set_label g)))

(put (quote case) (quote s!:compfn) (function s!:comcase))

(fluid (quote (!*defn dfprint!* s!:dfprintsave s!:faslmod_name)))

(de s!:comeval!-when (x env context) (prog (y) (setq x (cdr x)) (setq y (car 
x)) (princ "COMPILING eval-when: ") (print y) (print x) (setq x (cons (quote 
progn) (cdr x))) (cond ((memq (quote compile) y) (eval x))) (cond ((memq (
quote load) y) (progn (cond (dfprint!* (apply1 dfprint!* x)))))) (cond ((memq
(quote eval) y) (s!:comval x env context)) (t (s!:comval nil env context))))
)

(put (quote eval!-when) (quote s!:compfn) (function s!:comeval!-when))

(de s!:comthe (x env context) (s!:comval (caddr x) env context))

(put (quote the) (quote s!:compfn) (function s!:comthe))

(de s!:comand (x env context) (prog (l) (setq l (gensym)) (setq x (cdr x)) (
s!:comval (car x) env 1) (prog nil lab1150 (cond ((null (setq x (cdr x))) (
return nil))) (progn (s!:outjump (quote JUMPNIL) l) (s!:comval (car x) env 1)
) (go lab1150)) (s!:set_label l)))

(put (quote and) (quote s!:compfn) (function s!:comand))

(de s!:comor (x env context) (prog (l) (setq l (gensym)) (setq x (cdr x)) (
s!:comval (car x) env 1) (prog nil lab1151 (cond ((null (setq x (cdr x))) (
return nil))) (progn (s!:outjump (quote JUMPT) l) (s!:comval (car x) env 1)) 
(go lab1151)) (s!:set_label l)))

(put (quote or) (quote s!:compfn) (function s!:comor))

(de s!:combool (neg x env lab) (prog (fn) (setq fn (eqcar x (quote or))) (
cond ((eq fn neg) (prog nil lab1152 (cond ((null (setq x (cdr x))) (return 
nil))) (s!:jumpif fn (car x) env lab) (go lab1152))) (t (progn (setq neg (
gensym)) (prog nil lab1153 (cond ((null (setq x (cdr x))) (return nil))) (
s!:jumpif fn (car x) env neg) (go lab1153)) (s!:outjump (quote JUMP) lab) (
s!:set_label neg))))))

(put (quote and) (quote s!:testfn) (function s!:combool))

(put (quote or) (quote s!:testfn) (function s!:combool))

(de s!:testeq (neg x env lab) (prog (a b) (setq a (s!:improve (cadr x))) (
setq b (s!:improve (caddr x))) (cond ((or (s!:eval_to_eq_unsafe a) (
s!:eval_to_eq_unsafe b)) (progn (cond ((neq (posn) 0) (terpri))) (princ 
"++++ EQ on number upgraded to EQUAL in ") (prin s!:current_function) (princ 
" : ") (prin a) (princ " ") (print b) (return (s!:testequal neg (cons (quote 
equal) (cdr x)) env lab))))) (cond ((null a) (s!:jumpif (not neg) b env lab))
(t (cond ((null b) (s!:jumpif (not neg) a env lab)) (t (cond ((or (eqcar a (
quote quote)) (and (atom a) (not (symbolp a)))) (progn (s!:comval b env 1) (
cond ((eqcar a (quote quote)) (setq a (cadr a)))) (setq b (list (cond (neg (
quote JUMPLITEQ)) (t (quote JUMPLITNE))) a a)) (s!:record_literal_for_jump b 
env lab))) (t (cond ((or (eqcar b (quote quote)) (and (atom b) (not (symbolp 
b)))) (progn (s!:comval a env 1) (cond ((eqcar b (quote quote)) (setq b (cadr
b)))) (setq a (list (cond (neg (quote JUMPLITEQ)) (t (quote JUMPLITNE))) b b
)) (s!:record_literal_for_jump a env lab))) (t (progn (s!:load2 a b env) (
cond (neg (s!:outjump (quote JUMPEQ) lab)) (t (s!:outjump (quote JUMPNE) lab)
)))))))))))))

(de s!:testeq1 (neg x env lab) (prog (a b) (setq a (s!:improve (cadr x))) (
setq b (s!:improve (caddr x))) (cond ((null a) (s!:jumpif (not neg) b env lab
)) (t (cond ((null b) (s!:jumpif (not neg) a env lab)) (t (cond ((or (eqcar a
(quote quote)) (and (atom a) (not (symbolp a)))) (progn (s!:comval b env 1) 
(cond ((eqcar a (quote quote)) (setq a (cadr a)))) (setq b (list (cond (neg (
quote JUMPLITEQ)) (t (quote JUMPLITNE))) a a)) (s!:record_literal_for_jump b 
env lab))) (t (cond ((or (eqcar b (quote quote)) (and (atom b) (not (symbolp 
b)))) (progn (s!:comval a env 1) (cond ((eqcar b (quote quote)) (setq b (cadr
b)))) (setq a (list (cond (neg (quote JUMPLITEQ)) (t (quote JUMPLITNE))) b b
)) (s!:record_literal_for_jump a env lab))) (t (progn (s!:load2 a b env) (
cond (neg (s!:outjump (quote JUMPEQ) lab)) (t (s!:outjump (quote JUMPNE) lab)
)))))))))))))

(put (quote eq) (quote s!:testfn) (function s!:testeq))

(cond ((eq!-safe 0) (put (quote iequal) (quote s!:testfn) (function 
s!:testeq1))) (t (put (quote iequal) (quote s!:testfn) (function s!:testequal
))))

(de s!:testequal (neg x env lab) (prog (a b) (setq a (cadr x)) (setq b (caddr
x)) (cond ((null a) (s!:jumpif (not neg) b env lab)) (t (cond ((null b) (
s!:jumpif (not neg) a env lab)) (t (cond ((or (and (eqcar a (quote quote)) (
or (symbolp (cadr a)) (eq!-safe (cadr a)))) (and (eqcar b (quote quote)) (or 
(symbolp (cadr b)) (eq!-safe (cadr b)))) (and (not (idp a)) (eq!-safe a)) (
and (not (idp b)) (eq!-safe b))) (s!:testeq1 neg (cons (quote eq) (cdr x)) 
env lab)) (t (progn (s!:load2 a b env) (cond (neg (s!:outjump (quote 
JUMPEQUAL) lab)) (t (s!:outjump (quote JUMPNEQUAL) lab))))))))))))

(put (quote equal) (quote s!:testfn) (function s!:testequal))

(de s!:testneq (neg x env lab) (s!:testequal (not neg) (cons (quote equal) (
cdr x)) env lab))

(put (quote neq) (quote s!:testfn) (function s!:testneq))

(de s!:testeqcar (neg x env lab) (prog (a b sw promote) (setq a (cadr x)) (
setq b (s!:improve (caddr x))) (cond ((s!:eval_to_eq_unsafe b) (progn (cond (
(neq (posn) 0) (terpri))) (princ 
"++++ EQCAR on number upgraded to EQUALCAR in ") (prin s!:current_function) (
princ " : ") (print b) (setq promote t)))) (cond ((and (not promote) (eqcar b
(quote quote))) (progn (s!:comval a env 1) (setq b (cadr b)) (setq a (list (
cond (neg (quote JUMPEQCAR)) (t (quote JUMPNEQCAR))) b b)) (
s!:record_literal_for_jump a env lab))) (t (cond ((or (equal b nil) (equal b 
t) (and (not (symbolp b)) (eq!-safe b))) (progn (s!:comval a env 1) (setq a (
list (cond (neg (quote JUMPEQCAR)) (t (quote JUMPNEQCAR))) b b)) (
s!:record_literal_for_jump a env lab))) (t (progn (setq sw (s!:load2 a b env)
) (cond (sw (s!:outopcode0 (quote SWOP) (quote (SWOP))))) (cond (promote (
s!:outopcode1 (quote BUILTIN2) (get (quote equalcar) (quote s!:builtin2)) (
quote equalcar))) (t (s!:outopcode0 (quote EQCAR) (quote (EQCAR))))) (
s!:outjump (cond (neg (quote JUMPT)) (t (quote JUMPNIL))) lab))))))))

(put (quote eqcar) (quote s!:testfn) (function s!:testeqcar))

(de s!:testflagp (neg x env lab) (prog (a b sw) (setq a (cadr x)) (setq b (
caddr x)) (cond ((eqcar b (quote quote)) (progn (s!:comval a env 1) (setq b (
cadr b)) (setq sw (symbol!-make!-fastget b nil)) (cond (sw (progn (
s!:outopcode1 (quote FASTGET) (logor sw 128) b) (s!:outjump (cond (neg (quote
JUMPT)) (t (quote JUMPNIL))) lab))) (t (progn (setq a (list (cond (neg (
quote JUMPFLAGP)) (t (quote JUMPNFLAGP))) b b)) (s!:record_literal_for_jump a
env lab)))))) (t (progn (setq sw (s!:load2 a b env)) (cond (sw (
s!:outopcode0 (quote SWOP) (quote (SWOP))))) (s!:outopcode0 (quote FLAGP) (
quote (FLAGP))) (s!:outjump (cond (neg (quote JUMPT)) (t (quote JUMPNIL))) 
lab))))))

(put (quote flagp) (quote s!:testfn) (function s!:testflagp))

(global (quote (s!:storelocs)))

(setq s!:storelocs (s!:vecof (quote (STORELOC0 STORELOC1 STORELOC2 STORELOC3 
STORELOC4 STORELOC5 STORELOC6 STORELOC7))))

(de s!:comsetq (x env context) (prog (n w var) (setq x (cdr x)) (cond ((null 
x) (return nil))) (cond ((or (not (symbolp (car x))) (null (cdr x))) (return 
(error 0 (list "bad args for setq" x))))) (s!:comval (cadr x) env 1) (setq 
var (car x)) (setq n 0) (setq w (cdr env)) (prog nil lab1154 (cond ((null (
and w (not (eqcar w var)))) (return nil))) (progn (setq n (add1 n)) (setq w (
cdr w))) (go lab1154)) (cond (w (progn (cond ((not (member!*!* (cons (quote 
loc) w) s!:a_reg_values)) (setq s!:a_reg_values (cons (cons (quote loc) w) 
s!:a_reg_values)))) (cond ((lessp n 8) (s!:outopcode0 (getv s!:storelocs n) (
list (quote storeloc) var))) (t (cond ((greaterp n 4095) (error 0 
"stack frame > 4095")) (t (cond ((greaterp n 255) (s!:outopcode2 (quote 
BIGSTACK) (plus 64 (truncate n 256)) (logand n 255) (list (quote STORELOC) 
var))) (t (s!:outopcode1 (quote STORELOC) n var))))))))) (t (cond ((setq w (
s!:find_lexical var s!:lexical_env 0)) (progn (cond ((not (member!*!* (cons (
quote lex) w) s!:a_reg_values)) (setq s!:a_reg_values (cons (cons (quote lex)
w) s!:a_reg_values)))) (s!:outlexref (quote STORELEX) (length (cdr env)) (
car w) (cadr w) var))) (t (progn (cond ((or (null var) (eq var t)) (error 0 (
list "bad variable in setq" var))) (t (s!:should_be_fluid var))) (setq w (
cons (quote free) var)) (cond ((not (member!*!* w s!:a_reg_values)) (setq 
s!:a_reg_values (cons w s!:a_reg_values)))) (s!:outopcode1lit (quote 
STOREFREE) var env)))))) (cond ((cddr x) (return (s!:comsetq (cdr x) env 
context))))))

(put (quote setq) (quote s!:compfn) (function s!:comsetq))

(put (quote noisy!-setq) (quote s!:compfn) (function s!:comsetq))

(de s!:comlist (x env context) (prog (w) (cond ((null (setq x (cdr x))) (
return (s!:comval nil env context)))) (setq s!:a_reg_values nil) (cond ((null
(setq w (cdr x))) (s!:comval (list (quote ncons) (car x)) env context)) (t (
cond ((null (setq w (cdr w))) (s!:comval (list (quote list2) (car x) (cadr x)
) env context)) (t (cond ((null (cdr w)) (s!:comval (list (quote list3) (car 
x) (cadr x) (car w)) env context)) (t (s!:comlonglist x env context)))))))))

(de s!:comlonglist (x env context) (prog nil (s!:comval (list (quote list3rev
) (car x) (cadr x) (caddr x)) env 1) (setq x (cdddr x)) (rplacd env (cons 0 (
cdr env))) (prog nil lab1155 (cond ((null (and (cdr x) (cddr x))) (return nil
))) (progn (setq s!:a_reg_values nil) (s!:outopcode0 (quote PUSH) (quote (
PUSHA3))) (cond ((s!:load2 (car x) (cadr x) env) (s!:outopcode0 (quote SWOP) 
(quote (SWOP))))) (s!:outopcode1lit (quote CALL3) (quote list2!*rev) env) (
setq x (cddr x))) (go lab1155)) (s!:outopcode0 (quote PUSH) (quote (PUSH))) (
cond ((null (cdr x)) (progn (s!:comval (car x) env 1) (s!:outopcode0 (quote 
POP) (quote (POP))) (s!:outopcode1lit (quote CALL2) (quote nrevlist) env))) (
t (progn (cond ((s!:load2 (car x) (cadr x) env) (s!:outopcode0 (quote SWOP) (
quote (SWOP))))) (s!:outopcode1lit (quote CALL3) (quote nrevlist) env)))) (
rplacd env (cddr env))))

(put (quote list) (quote s!:compfn) (function s!:comlist))

(de s!:comlist!* (x env context) (prog (w) (cond ((null (setq x (cdr x))) (
return (s!:comval nil env context)))) (setq s!:a_reg_values nil) (cond ((null
(setq w (cdr x))) (s!:comval (car x) env context)) (t (cond ((null (setq w (
cdr w))) (s!:comval (list (quote cons) (car x) (cadr x)) env context)) (t (
cond ((null (cdr w)) (s!:comval (list (quote list2!*) (car x) (cadr x) (car w
)) env context)) (t (s!:comval (list (quote list2!*) (car x) (cadr x) (cons (
quote list!*) w)) env context)))))))))

(put (quote list!*) (quote s!:compfn) (function s!:comlist!*))

(de s!:comcons (x env context) (prog (a b) (setq a (cadr x)) (setq b (caddr x
)) (cond ((or (equal b nil) (equal b (quote (quote nil)))) (s!:comval (list (
quote ncons) a) env context)) (t (cond ((eqcar a (quote cons)) (s!:comval (
list (quote acons) (cadr a) (caddr a) b) env context)) (t (cond ((eqcar b (
quote cons)) (cond ((null (caddr b)) (s!:comval (list (quote list2) a (cadr b
)) env context)) (t (s!:comval (list (quote list2!*) a (cadr b) (caddr b)) 
env context)))) (t (cond ((and (not !*ord) (s!:iseasy a) (not (s!:iseasy b)))
(s!:comval (list (quote xcons) b a) env context)) (t (s!:comcall x env 
context)))))))))))

(put (quote cons) (quote s!:compfn) (function s!:comcons))

(de s!:commv!-call (x env context) (prog (fn args) (setq fn (cadr x)) (setq 
args (prog (var1157 var1158) (setq var1157 (cddr x)) lab1156 (cond ((null 
var1157) (return (reversip var1158)))) (prog (v) (setq v (car var1157)) (setq
var1158 (cons (list (quote mv!-list!*) v) var1158))) (setq var1157 (cdr 
var1157)) (go lab1156))) (setq args (expand args (quote append))) (cond ((not
(equal fn (quote (function list)))) (setq args (list (quote apply) fn args))
)) (s!:comval args env context)))

(put (quote multiple!-value!-call) (quote s!:compfn) (function s!:commv!-call
))

(de s!:commv!-prog1 (x env context) (prog nil (setq x (cdr x)) (cond ((null x
) (return (s!:comval nil env context))) (t (cond ((null (cdr x)) (return (
s!:comval (car x) env context)))))) (s!:comval (list (quote mv!-list!*) (car 
x)) env context) (s!:outopcode0 (quote PUSH) (quote (PUSH))) (rplacd env (
cons 0 (cdr env))) (prog (var1160) (setq var1160 x) lab1159 (cond ((null 
var1160) (return nil))) (prog (a) (setq a (car var1160)) (s!:comval a env (
cond ((geq context 4) context) (t 2)))) (setq var1160 (cdr var1160)) (go 
lab1159)) (s!:outopcode0 (quote POP) (quote (POP))) (rplacd env (cddr env)) (
s!:loadliteral (quote values) env) (s!:outopcode1 (quote BUILTIN2) (get (
quote apply1) (quote s!:builtin2)) (quote apply1))))

(put (quote multiple!-value!-prog1) (quote s!:compfn) (function 
s!:commv!-prog1))

(de s!:comapply (x env context) (prog (a b n) (setq a (cadr x)) (setq b (
caddr x)) (cond ((and (null (cdddr x)) (eqcar b (quote list))) (progn (cond (
(eqcar a (quote quote)) (return (progn (setq n s!:current_function) (prog (
s!:current_function) (setq s!:current_function (compress (append (explode n) 
(cons (quote !!) (cons (quote !.) (explodec (setq s!:current_count (plus 
s!:current_count 1)))))))) (return (s!:comval (cons (cadr a) (cdr b)) env 
context))))))) (setq n (length (setq b (cdr b)))) (return (s!:comval (cons (
quote funcall) (cons a b)) env context)))) (t (cond ((and (null b) (null (
cdddr x))) (return (s!:comval (list (quote funcall) a) env context))) (t (
return (s!:comcall x env context))))))))

(put (quote apply) (quote s!:compfn) (function s!:comapply))

(de s!:imp_funcall (u) (prog (n) (setq u (cdr u)) (cond ((eqcar (car u) (
quote function)) (return (s!:improve (cons (cadar u) (cdr u)))))) (setq n (
length (cdr u))) (setq u (cond ((equal n 0) (cons (quote apply0) u)) (t (cond
((equal n 1) (cons (quote apply1) u)) (t (cond ((equal n 2) (cons (quote 
apply2) u)) (t (cond ((equal n 3) (cons (quote apply3) u)) (t (cons (quote 
funcall) u)))))))))) (return u)))

(put (quote funcall) (quote s!:tidy_fn) (quote s!:imp_funcall))

(de s!:eval_to_eq_safe (x) (or (equal x nil) (equal x t) (and (not (symbolp x
)) (eq!-safe x)) (and (not (atom x)) (flagp (car x) (quote eq!-safe))) (and (
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

(de s!:list_some_eq_unsafe (u) (and (not (atom u)) (or (s!:eval_to_eq_unsafe 
(car u)) (s!:list_some_eq_unsafe (cdr u)))))

(de s!:eval_to_list_some_eq_unsafe (x) (cond ((atom x) nil) (t (cond ((eqcar 
x (quote quote)) (s!:list_some_eq_unsafe (cadr x))) (t (cond ((and (eqcar x (
quote list)) (cdr x)) (or (s!:eval_to_eq_unsafe (cadr x)) (
s!:eval_to_list_some_eq_unsafe (cons (quote list) (cddr x))))) (t (cond ((
eqcar x (quote cons)) (or (s!:eval_to_eq_unsafe (cadr x)) (
s!:eval_to_list_some_eq_unsafe (caddr x)))) (t nil)))))))))

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

(de s!:eval_to_alist_eq_unsafe (x) (cond ((null x) nil) (t (cond ((eqcar x (
quote quote)) (s!:alist_eq_unsafe (cadr x))) (t (cond ((eqcar x (quote list))
(and (cdr x) (or (s!:eval_to_car_eq_unsafe (cadr x)) (
s!:eval_to_alist_eq_unsafe (cons (quote list) (cddr x)))))) (t (cond ((eqcar 
x (quote cons)) (or (s!:eval_to_car_eq_unsafe (cadr x)) (
s!:eval_to_alist_eq_safe (caddr x)))) (t nil)))))))))

(flag (quote (eq eqcar null not greaterp lessp geq leq minusp atom numberp 
consp)) (quote eq!-safe))

(cond ((not (eq!-safe 1)) (flag (quote (length plus minus difference times 
quotient plus2 times2 expt fix float)) (quote eq!-unsafe))))

(de s!:comequal (x env context) (cond ((or (s!:eval_to_eq_safe (cadr x)) (
s!:eval_to_eq_safe (caddr x))) (s!:comcall (cons (quote eq) (cdr x)) env 
context)) (t (s!:comcall x env context))))

(put (quote equal) (quote s!:compfn) (function s!:comequal))

(de s!:comeq (x env context) (cond ((or (s!:eval_to_eq_unsafe (cadr x)) (
s!:eval_to_eq_unsafe (caddr x))) (progn (cond ((neq (posn) 0) (terpri))) (
princ "++++ EQ on number upgraded to EQUAL in ") (prin s!:current_function) (
princ " : ") (prin (cadr x)) (princ " ") (print (caddr x)) (s!:comcall (cons 
(quote equal) (cdr x)) env context))) (t (s!:comcall x env context))))

(put (quote eq) (quote s!:compfn) (function s!:comeq))

(de s!:comeqcar (x env context) (cond ((s!:eval_to_eq_unsafe (caddr x)) (
progn (cond ((neq (posn) 0) (terpri))) (princ 
"++++ EQCAR on number upgraded to EQUALCAR in ") (prin s!:current_function) (
princ " : ") (prin (caddr x)) (s!:comcall (cons (quote equalcar) (cdr x)) env
context))) (t (s!:comcall x env context))))

(put (quote eqcar) (quote s!:compfn) (function s!:comeqcar))

(de s!:comsublis (x env context) (cond ((s!:eval_to_alist_eq_safe (cadr x)) (
s!:comval (cons (quote subla) (cdr x)) env context)) (t (s!:comcall x env 
context))))

(put (quote sublis) (quote s!:compfn) (function s!:comsublis))

(de s!:comsubla (x env context) (cond ((s!:eval_to_alist_eq_unsafe (cadr x)) 
(progn (cond ((neq (posn) 0) (terpri))) (princ 
"++++ SUBLA on number upgraded to SUBLIS in ") (prin s!:current_function) (
princ " : ") (print (cadr x)) (s!:comval (cons (quote sublis) (cdr x)) env 
context))) (t (s!:comcall x env context))))

(put (quote subla) (quote s!:compfn) (function s!:comsubla))

(de s!:comassoc (x env context) (cond ((and (or (s!:eval_to_eq_safe (cadr x))
(s!:eval_to_alist_eq_safe (caddr x))) (equal (length x) 3)) (s!:comval (cons
(quote atsoc) (cdr x)) env context)) (t (cond ((equal (length x) 3) (
s!:comcall (cons (quote assoc!*!*) (cdr x)) env context)) (t (s!:comcall x 
env context))))))

(put (quote assoc) (quote s!:compfn) (function s!:comassoc))

(put (quote assoc!*!*) (quote s!:compfn) (function s!:comassoc))

(de s!:comatsoc (x env context) (cond ((or (s!:eval_to_eq_unsafe (cadr x)) (
s!:eval_to_alist_eq_unsafe (caddr x))) (progn (cond ((neq (posn) 0) (terpri))
) (princ "++++ ATSOC on number upgraded to ASSOC in ") (prin 
s!:current_function) (princ " : ") (prin (cadr x)) (princ " ") (print (caddr 
x)) (s!:comval (cons (quote assoc) (cdr x)) env context))) (t (s!:comcall x 
env context))))

(put (quote atsoc) (quote s!:compfn) (function s!:comatsoc))

(de s!:commember (x env context) (cond ((and (or (s!:eval_to_eq_safe (cadr x)
) (s!:eval_to_list_all_eq_safe (caddr x))) (equal (length x) 3)) (s!:comval (
cons (quote memq) (cdr x)) env context)) (t (s!:comcall x env context))))

(put (quote member) (quote s!:compfn) (function s!:commember))

(put (quote member!*!*) (quote s!:compfn) (function s!:commember))

(de s!:commemq (x env context) (cond ((or (s!:eval_to_eq_unsafe (cadr x)) (
s!:eval_to_list_some_eq_unsafe (caddr x))) (progn (cond ((neq (posn) 0) (
terpri))) (princ "++++ MEMQ on number upgraded to MEMBER in ") (prin 
s!:current_function) (princ " : ") (prin (cadr x)) (princ " ") (print (caddr 
x)) (s!:comval (cons (quote member) (cdr x)) env context))) (t (s!:comcall x 
env context))))

(put (quote memq) (quote s!:compfn) (function s!:commemq))

(de s!:comdelete (x env context) (cond ((and (or (s!:eval_to_eq_safe (cadr x)
) (s!:eval_to_list_all_eq_safe (caddr x))) (equal (length x) 3)) (s!:comval (
cons (quote deleq) (cdr x)) env context)) (t (s!:comcall x env context))))

(put (quote delete) (quote s!:compfn) (function s!:comdelete))

(de s!:comdeleq (x env context) (cond ((or (s!:eval_to_eq_unsafe (cadr x)) (
s!:eval_to_list_some_eq_unsafe (caddr x))) (progn (cond ((neq (posn) 0) (
terpri))) (princ "++++ DELEQ on number upgraded to DELETE in ") (prin 
s!:current_function) (princ " : ") (prin (cadr x)) (princ " ") (print (caddr 
x)) (s!:comval (cons (quote delete) (cdr x)) env context))) (t (s!:comcall x 
env context))))

(put (quote deleq) (quote s!:compfn) (function s!:comdeleq))

(de s!:commap (fnargs env context) (prog (carp fn fn1 args var avar moveon l1
 r s closed) (setq fn (car fnargs)) (cond ((greaterp context 1) (progn (cond 
((equal fn (quote mapcar)) (setq fn (quote mapc))) (t (cond ((equal fn (quote
maplist)) (setq fn (quote map))))))))) (cond ((or (equal fn (quote mapc)) (
equal fn (quote mapcar)) (equal fn (quote mapcan))) (setq carp t))) (setq 
fnargs (cdr fnargs)) (cond ((atom fnargs) (error 0 
"bad arguments to map function"))) (setq fn1 (cadr fnargs)) (prog nil lab1161
(cond ((null (or (eqcar fn1 (quote function)) (and (eqcar fn1 (quote quote))
(eqcar (cadr fn1) (quote lambda))))) (return nil))) (progn (setq fn1 (cadr 
fn1)) (setq closed t)) (go lab1161)) (setq args (car fnargs)) (setq l1 (
gensym)) (setq r (gensym)) (setq s (gensym)) (setq var (gensym)) (setq avar 
var) (cond (carp (setq avar (list (quote car) avar)))) (cond (closed (setq 
fn1 (list fn1 avar))) (t (setq fn1 (list (quote funcall) fn1 avar)))) (setq 
moveon (list (quote setq) var (list (quote cdr) var))) (cond ((or (equal fn (
quote map)) (equal fn (quote mapc))) (setq fn (sublis (list (cons (quote l1) 
l1) (cons (quote var) var) (cons (quote fn) fn1) (cons (quote args) args) (
cons (quote moveon) moveon)) (quote (prog (var) (setq var args) l1 (cond ((
not var) (return nil))) fn moveon (go l1)))))) (t (cond ((or (equal fn (quote
maplist)) (equal fn (quote mapcar))) (setq fn (sublis (list (cons (quote l1)
l1) (cons (quote var) var) (cons (quote fn) fn1) (cons (quote args) args) (
cons (quote moveon) moveon) (cons (quote r) r)) (quote (prog (var r) (setq 
var args) l1 (cond ((not var) (return (reversip r)))) (setq r (cons fn r)) 
moveon (go l1)))))) (t (setq fn (sublis (list (cons (quote l1) l1) (cons (
quote l2) (gensym)) (cons (quote var) var) (cons (quote fn) fn1) (cons (quote
args) args) (cons (quote moveon) moveon) (cons (quote r) (gensym)) (cons (
quote s) (gensym))) (quote (prog (var r s) (setq var args) (setq r (setq s (
list nil))) l1 (cond ((not var) (return (cdr r)))) (rplacd s fn) l2 (cond ((
not (atom (cdr s))) (setq s (cdr s)) (go l2))) moveon (go l1))))))))) (
s!:comval fn env context)))

(put (quote map) (quote s!:compfn) (function s!:commap))

(put (quote maplist) (quote s!:compfn) (function s!:commap))

(put (quote mapc) (quote s!:compfn) (function s!:commap))

(put (quote mapcar) (quote s!:compfn) (function s!:commap))

(put (quote mapcon) (quote s!:compfn) (function s!:commap))

(put (quote mapcan) (quote s!:compfn) (function s!:commap))

(de s!:nilargs (use) (cond ((null use) t) (t (cond ((or (equal (car use) (
quote nil)) (equal (car use) (quote (quote nil)))) (s!:nilargs (cdr use))) (t
nil)))))

(de s!:subargs (args use) (cond ((null use) t) (t (cond ((null args) (
s!:nilargs use)) (t (cond ((not (equal (car args) (car use))) nil) (t (
s!:subargs (cdr args) (cdr use)))))))))

(fluid (quote (!*where_defined!*)))

(de clear_source_database nil (progn (setq !*where_defined!* (mkhash (quote 
equal))) nil))

(de load_source_database (filename) (prog (a b) (clear_source_database) (setq
a (open filename (quote input))) (cond ((null a) (return nil))) (setq a (rds
a)) (prog nil lab1162 (cond ((null (setq b (read))) (return nil))) (puthash 
(car b) !*where_defined!* (cdr b)) (go lab1162)) (close (rds a)) (return nil)
))

(de save_source_database (filename) (prog (a) (setq a (open filename (quote 
output))) (cond ((null a) (return nil))) (setq a (wrs a)) (prog (var1164) (
setq var1164 (sort (hashcontents !*where_defined!*) (function orderp))) 
lab1163 (cond ((null var1164) (return nil))) (prog (z) (setq z (car var1164))
(progn (prin z) (terpri))) (setq var1164 (cdr var1164)) (go lab1163)) (princ
nil) (terpri) (wrs a) (setq !*where_defined!* nil) (return nil)))

(de display_source_database nil (prog (w) (cond ((null !*where_defined!*) (
return nil))) (setq w (hashcontents !*where_defined!*)) (setq w (sort w (
function orderp))) (terpri) (prog (var1166) (setq var1166 w) lab1165 (cond ((
null var1166) (return nil))) (prog (x) (setq x (car var1166)) (progn (princ (
car x)) (ttab 40) (prin (cdr x)) (terpri))) (setq var1166 (cdr var1166)) (go 
lab1165))))

(fluid (quote (s!:r2i_simple_recurse s!:r2i_cons_recurse)))

(de s!:r2i (name args body) (prog (lab v b1 s!:r2i_simple_recurse 
s!:r2i_cons_recurse) (setq lab (gensym)) (setq v (list (gensym))) (setq b1 (
s!:r2i1 name args body lab v)) (cond (s!:r2i_cons_recurse (progn (setq b1 (
list (quote prog) v lab b1)) (return b1))) (t (cond (s!:r2i_simple_recurse (
progn (setq v (list (gensym))) (setq b1 (s!:r2i2 name args body lab v)) (setq
b1 (list (quote prog) (cdr v) lab b1)) (return b1))) (t (return (s!:r2i3 
name args body lab v))))))))

(de s!:r2i1 (name args body lab v) (cond ((or (null body) (equal body (quote 
(progn)))) (list (quote return) (list (quote nreverse) (car v)))) (t (cond ((
and (eqcar body name) (equal (length (cdr body)) (length args))) (progn (setq
s!:r2i_simple_recurse t) (cons (quote progn) (append (s!:r2isteps args (cdr 
body) v) (list (list (quote go) lab)))))) (t (cond ((eqcar body (quote cond))
(cons (quote cond) (s!:r2icond name args (cdr body) lab v))) (t (cond ((
eqcar body (quote if)) (cons (quote if) (s!:r2iif name args (cdr body) lab v)
)) (t (cond ((eqcar body (quote when)) (cons (quote when) (s!:r2iwhen name 
args (cdr body) lab v))) (t (cond ((eqcar body (quote cons)) (s!:r2icons name
args (cadr body) (caddr body) lab v)) (t (cond ((or (eqcar body (quote progn
)) (eqcar body (quote prog2))) (cons (quote progn) (s!:r2iprogn name args (
cdr body) lab v))) (t (cond ((eqcar body (quote and)) (s!:r2i1 name args (
s!:r2iand (cdr body)) lab v)) (t (cond ((eqcar body (quote or)) (s!:r2i1 name
args (s!:r2ior (cdr body)) lab v)) (t (list (quote return) (list (quote 
nreverse) (car v) body)))))))))))))))))))))

(de s!:r2iand (l) (cond ((null l) t) (t (cond ((null (cdr l)) (car l)) (t (
list (quote cond) (list (car l) (s!:r2iand (cdr l)))))))))

(de s!:r2ior (l) (cond ((null l) nil) (t (prog (r) (prog nil lab1167 (cond ((
null (cdr l)) (return nil))) (progn (setq r (cons (list (car l)) r)) (setq l 
(cdr l))) (go lab1167)) (setq r (cons (list t (car l)) r)) (return (cons (
quote cond) (reverse r)))))))

(de s!:r2icond (name args b lab v) (cond ((null b) (list (list t (list (quote
return) (list (quote nreverse) (car v)))))) (t (cond ((null (cdar b)) (progn
(cond ((null (cdr v)) (rplacd v (list (gensym))))) (cons (list (list (quote 
setq) (cadr v) (caar b)) (list (quote return) (list (quote nreverse) (car v) 
(cadr v)))) (s!:r2icond name args (cdr b) lab v)))) (t (cond ((eqcar (car b) 
t) (list (cons t (s!:r2iprogn name args (cdar b) lab v)))) (t (cons (cons (
caar b) (s!:r2iprogn name args (cdar b) lab v)) (s!:r2icond name args (cdr b)
lab v)))))))))

(de s!:r2iif (name args b lab v) (cond ((null (cddr b)) (list (car b) (
s!:r2i1 name args (cadr b) lab v))) (t (list (car b) (s!:r2i1 name args (cadr
b) lab v) (s!:r2i1 name args (caddr b) lab v)))))

(de s!:r2iwhen (name args b lab v) (cons (car b) (s!:r2iprogn name args (cdr 
b) lab v)))

(de s!:r2iprogn (name args b lab v) (cond ((null (cdr b)) (list (s!:r2i1 name
args (car b) lab v))) (t (cons (car b) (s!:r2iprogn name args (cdr b) lab v)
))))

(de s!:r2icons (name args a d lab v) (cond ((eqcar d (quote cons)) (
s!:r2icons2 name args a (cadr d) (caddr d) lab v)) (t (cond ((and (eqcar d 
name) (equal (length (cdr d)) (length args))) (progn (setq 
s!:r2i_cons_recurse t) (cons (quote progn) (cons (list (quote setq) (car v) (
list (quote cons) a (car v))) (append (s!:r2isteps args (cdr d) v) (list (
list (quote go) lab))))))) (t (list (quote return) (list (quote nreverse) (
car v) (list (quote cons) a d))))))))

(de s!:r2icons2 (name args a ad dd lab v) (cond ((and (eqcar dd name) (equal 
(length (cdr dd)) (length args))) (progn (setq s!:r2i_cons_recurse t) (cons (
quote progn) (cons (list (quote setq) (car v) (list (quote cons) a (car v))) 
(cons (list (quote setq) (car v) (list (quote cons) ad (car v))) (append (
s!:r2isteps args (cdr dd) v) (list (list (quote go) lab)))))))) (t (list (
quote return) (list (quote nreverse) (car v) (list (quote cons) a (list (
quote cons) ad dd)))))))

(de s!:r2isteps (vars vals v) (cond ((null vars) (cond ((null vals) nil) (t (
error 0 "too many args in recursive call to self")))) (t (cond ((null vals) (
error 0 "not enough args in recursive call to self")) (t (cond ((equal (car 
vars) (car vals)) (s!:r2isteps (cdr vars) (cdr vals) v)) (t (cond ((
s!:r2i_safestep (car vars) (cdr vars) (cdr vals)) (cons (list (quote setq) (
car vars) (car vals)) (s!:r2isteps (cdr vars) (cdr vals) v))) (t (prog (w) (
cond ((null (cdr v)) (rplacd v (list (gensym))))) (setq v (cdr v)) (setq w (
s!:r2isteps (cdr vars) (cdr vals) v)) (return (cons (list (quote setq) (car v
) (car vals)) (append w (list (list (quote setq) (car vars) (car v)))))))))))
)))))

(de s!:r2i_safestep (x vars vals) (cond ((and (null vars) (null vals)) t) (t 
(cond ((s!:r2i_dependson (car vals) x) nil) (t (s!:r2i_safestep x (cdr vars) 
(cdr vals)))))))

(de s!:r2i_dependson (e x) (cond ((equal e x) t) (t (cond ((or (atom e) (
eqcar e (quote quote))) nil) (t (cond ((not (atom (car e))) t) (t (cond ((
flagp (car e) (quote s!:r2i_safe)) (s!:r2i_list_dependson (cdr e) x)) (t (
cond ((or (fluidp x) (globalp x)) t) (t (cond ((or (flagp (car e) (quote 
s!:r2i_unsafe)) (macro!-function (car e))) t) (t (s!:r2i_list_dependson (cdr 
e) x))))))))))))))

(flag (quote (car cdr caar cadr cdar cddr caaar caadr cadar caddr cdaar cdadr
cddar cdddr cons ncons rcons acons list list2 list3 list!* add1 sub1 plus 
plus2 times times2 difference minus quotient append reverse nreverse null not
assoc atsoc member memq subst sublis subla pair prog1 prog2 progn)) (quote 
s!:r2i_safe))

(flag (quote (cond if when case de defun dm defmacro prog let let!* flet and 
or)) (quote s!:r2i_unsafe))

(de s!:r2i_list_dependson (l x) (cond ((null l) nil) (t (cond ((
s!:r2i_dependson (car l) x) t) (t (s!:r2i_list_dependson (cdr l) x))))))

(de s!:r2i2 (name args body lab v) (cond ((or (null body) (equal body (quote 
(progn)))) (list (quote return) nil)) (t (cond ((and (eqcar body name) (equal
(length (cdr body)) (length args))) (progn (cons (quote progn) (append (
s!:r2isteps args (cdr body) v) (list (list (quote go) lab)))))) (t (cond ((
eqcar body (quote cond)) (cons (quote cond) (s!:r2i2cond name args (cdr body)
lab v))) (t (cond ((eqcar body (quote if)) (cons (quote if) (s!:r2i2if name 
args (cdr body) lab v))) (t (cond ((eqcar body (quote when)) (cons (quote 
when) (s!:r2i2when name args (cdr body) lab v))) (t (cond ((or (eqcar body (
quote progn)) (eqcar body (quote prog2))) (cons (quote progn) (s!:r2i2progn 
name args (cdr body) lab v))) (t (cond ((eqcar body (quote and)) (s!:r2i2 
name args (s!:r2iand (cdr body)) lab v)) (t (cond ((eqcar body (quote or)) (
s!:r2i2 name args (s!:r2ior (cdr body)) lab v)) (t (list (quote return) body)
)))))))))))))))))

(de s!:r2i2cond (name args b lab v) (cond ((null b) (list (list t (list (
quote return) nil)))) (t (cond ((null (cdar b)) (progn (cond ((null (cdr v)) 
(rplacd v (list (gensym))))) (cons (list (list (quote setq) (cadr v) (caar b)
) (list (quote return) (cadr v))) (s!:r2i2cond name args (cdr b) lab v)))) (t
(cond ((eqcar (car b) t) (list (cons t (s!:r2i2progn name args (cdar b) lab 
v)))) (t (cons (cons (caar b) (s!:r2i2progn name args (cdar b) lab v)) (
s!:r2i2cond name args (cdr b) lab v)))))))))

(de s!:r2i2if (name args b lab v) (cond ((null (cddr b)) (list (car b) (
s!:r2i2 name args (cadr b) lab v))) (t (list (car b) (s!:r2i2 name args (cadr
b) lab v) (s!:r2i2 name args (caddr b) lab v)))))

(de s!:r2i2when (name args b lab v) (cons (car b) (s!:r2i2progn name args (
cdr b) lab v)))

(de s!:r2i2progn (name args b lab v) (cond ((null (cdr b)) (list (s!:r2i2 
name args (car b) lab v))) (t (cons (car b) (s!:r2i2progn name args (cdr b) 
lab v)))))

(de s!:r2i3 (name args body lab v) (prog (v v1 v2 lab1 lab2 lab3 w P Q g R) (
cond ((s!:any_fluid args) (return body))) (cond ((eqcar body (quote cond)) (
progn (cond ((not (setq w (cdr body))) (return body))) (setq P (car w)) (setq
w (cdr w)) (cond ((null P) (return body))) (setq Q (cdr P)) (setq P (car P))
(cond ((or (null Q) (cdr Q)) (return body))) (setq Q (car Q)) (cond ((or (
null w) (cdr w)) (return body))) (setq w (car w)) (cond ((not (eqcar w t)) (
return body))) (setq w (cdr w)) (cond ((or (not w) (cdr w)) (return body))) (
setq w (car w)))) (t (cond ((eqcar body (quote if)) (progn (setq w (cdr body)
) (setq P (car w)) (setq w (cdr w)) (setq Q (car w)) (setq w (cdr w)) (cond (
(null w) (return body))) (setq w (car w)))) (t (return body))))) (cond ((or (
atom w) (atom (cdr w)) (atom (cddr w)) (cdddr w)) (return body))) (setq g (
car w)) (setq R (cadr w)) (setq w (caddr w)) (cond ((not (atom g)) (return 
body))) (cond ((member g (quote (and or progn prog1 prog2 cond if when))) (
return body))) (cond ((not (eqcar w name)) (return body))) (setq w (cdr w)) (
cond ((not (equal (length w) (length args))) (return body))) (setq v1 (gensym
)) (setq v2 (gensym)) (setq v (list v2)) (setq lab1 (gensym)) (setq lab2 (
gensym)) (setq lab3 (gensym)) (setq w (s!:r2isteps args w v)) (setq w (list (
quote prog) (cons v1 v) lab1 (list (quote cond) (list P (list (quote go) lab2
))) (list (quote setq) v1 (list (quote cons) R v1)) (cons (quote progn) w) (
list (quote go) lab1) lab2 (list (quote setq) v2 Q) lab3 (list (quote cond) (
list (list (quote null) v1) (list (quote return) v2))) (list (quote setq) v2 
(list g (list (quote qcar) v1) v2)) (list (quote setq) v1 (list (quote qcdr) 
v1)) (list (quote go) lab3))) (return w)))

(de s!:any_fluid (l) (cond ((null l) nil) (t (cond ((fluidp (car l)) t) (t (
s!:any_fluid (cdr l)))))))

(de s!:compile1 (name args body s!:lexical_env) (prog (w aargs oargs oinit 
restarg svars nargs nopts env fluids s!:current_function s!:current_label 
s!:current_block s!:current_size s!:current_procedure s!:current_exitlab 
s!:current_proglabels local_decs s!:has_closure s!:local_macros 
s!:recent_literals s!:a_reg_values w1 w2 s!:current_count s!:env_alist 
s!:maybe_values checksum) (setq checksum (md60 (cons args body))) (cond ((
member checksum (get name (quote c!-version))) (progn (
s!:scan_for_embedded_lambdas body) (setq w2 (compress (append (explode name) 
(cons (quote !!) (cons (quote !~) (cons (quote !!) (cons (quote !~) (
explodehex checksum)))))))) (setq s!:other_defs (cons (cons name w2) 
s!:other_defs)) (return nil)))) (cond (s!:lexical_env (setq checksum 0)) (t (
setq checksum (md60 (cons name (cons args body)))))) (setq 
s!:current_function name) (setq s!:current_count 0) (cond (!*where_defined!* 
(progn (setq w name) (puthash w !*where_defined!* (where!-was!-that))))) (
setq body (s!:find_local_decs body nil)) (setq local_decs (car body)) (setq 
body (cdr body)) (cond ((atom body) (setq body nil)) (t (cond ((null (cdr 
body)) (setq body (car body))) (t (setq body (cons (quote progn) body)))))) (
setq nargs (setq nopts 0)) (prog nil lab1168 (cond ((null (and args (not (
eqcar args (quote !&optional))) (not (eqcar args (quote !&rest))))) (return 
nil))) (progn (cond ((or (equal (car args) (quote !&key)) (equal (car args) (
quote !&aux))) (error 0 "&key/&aux"))) (setq aargs (cons (car args) aargs)) (
setq nargs (plus nargs 1)) (setq args (cdr args))) (go lab1168)) (cond ((
eqcar args (quote !&optional)) (progn (setq args (cdr args)) (prog nil 
lab1170 (cond ((null (and args (not (eqcar args (quote !&rest))))) (return 
nil))) (progn (cond ((or (equal (car args) (quote !&key)) (equal (car args) (
quote !&aux))) (error 0 "&key/&aux"))) (setq w (car args)) (prog nil lab1169 
(cond ((null (and (not (atom w)) (or (atom (cdr w)) (equal (cdr w) (quote (
nil)))))) (return nil))) (setq w (car w)) (go lab1169)) (setq args (cdr args)
) (setq oargs (cons w oargs)) (setq nopts (plus nopts 1)) (cond ((atom w) (
setq aargs (cons w aargs))) (t (progn (setq oinit t) (setq aargs (cons (car w
) aargs)) (cond ((not (atom (cddr w))) (setq svars (cons (caddr w) svars)))))
))) (go lab1170))))) (cond ((eqcar args (quote !&rest)) (progn (setq w (cadr 
args)) (setq aargs (cons w aargs)) (setq restarg w) (setq args (cddr args)) (
cond (args (error 0 "&rest arg not at end")))))) (setq args (reverse aargs)) 
(setq oargs (reverse oargs)) (prog (var1172) (setq var1172 (append svars args
)) lab1171 (cond ((null var1172) (return nil))) (prog (v) (setq v (car 
var1172)) (cond ((or (globalp v) (keywordp v)) (error 0 (list 
"attempt to bind global or keyword" v))))) (setq var1172 (cdr var1172)) (go 
lab1171)) (cond (oinit (progn (s!:compile2 name nargs nopts args oargs 
restarg body local_decs checksum) (return nil)))) (setq w nil) (prog (var1174
) (setq var1174 args) lab1173 (cond ((null var1174) (return nil))) (prog (v) 
(setq v (car var1174)) (setq w (s!:instate_local_decs v local_decs w))) (setq
var1174 (cdr var1174)) (go lab1173)) (cond ((and !*r2i (null oargs) (null 
restarg)) (setq body (s!:r2i name args body)))) (prog (v) (setq v args) 
lab1175 (cond ((null v) (return nil))) (progn (cond ((fluidp (car v)) (prog (
g) (setq g (gensym)) (setq fluids (cons (cons (car v) g) fluids)) (rplaca v g
))))) (setq v (cdr v)) (go lab1175)) (cond (fluids (progn (setq body (list (
list (quote return) body))) (prog (var1177) (setq var1177 fluids) lab1176 (
cond ((null var1177) (return nil))) (prog (v) (setq v (car var1177)) (setq 
body (cons (list (quote setq) (car v) (cdr v)) body))) (setq var1177 (cdr 
var1177)) (go lab1176)) (setq body (cons (quote prog) (cons (prog (var1179 
var1180) (setq var1179 fluids) lab1178 (cond ((null var1179) (return (
reversip var1180)))) (prog (v) (setq v (car var1179)) (setq var1180 (cons (
car v) var1180))) (setq var1179 (cdr var1179)) (go lab1178)) body)))))) (setq
env (cons (mkhash (quote equal)) (reverse args))) (puthash name (car env) (
cons 10000000 nil)) (setq w (s!:residual_local_decs local_decs w)) (
s!:start_procedure nargs nopts restarg) (setq w1 body) more (cond ((atom w1) 
nil) (t (cond ((and (equal (car w1) (quote block)) (equal (length w1) 3)) (
progn (setq w1 (caddr w1)) (go more))) (t (cond ((and (equal (car w1) (quote 
progn)) (equal (length w1) 2)) (progn (setq w1 (cadr w1)) (go more))) (t (
cond ((and (atom (setq w2 (car w1))) (setq w2 (get w2 (quote s!:newname)))) (
progn (setq w1 (cons w2 (cdr w1))) (go more))) (t (cond ((and (atom (setq w2 
(car w1))) (setq w2 (macro!-function w2))) (progn (setq w1 (funcall w2 w1)) (
go more)))))))))))) (cond ((not (equal (setq w2 (s!:improve w1)) w1)) (progn 
(setq w1 w2) (go more)))) (cond ((and (not (atom w1)) (atom (car w1)) (not (
special!-form!-p (car w1))) (s!:subargs args (cdr w1)) (leq nargs 3) (equal 
nopts 0) (not restarg) (leq (length (cdr w1)) nargs)) (progn (
s!:cancel_local_decs w) (cond (restarg (setq nopts (plus nopts 512)))) (setq 
nopts (plus nopts (times 1024 (length w1)))) (setq nargs (plus nargs (times 
256 nopts))) (cond (!*pwrds (progn (cond ((neq (posn) 0) (terpri))) (princ 
"+++ ") (prin name) (princ " compiled as link to ") (princ (car w1)) (terpri)
))) (setq s!:other_defs (cons (cons name (cons nargs (cons nil (car w1)))) 
s!:other_defs)) (return nil)))) (s!:comval body env 0) (s!:cancel_local_decs 
w) (cond (restarg (setq nopts (plus nopts 512)))) (setq nargs (plus nargs (
times 256 nopts))) (setq s!:other_defs (cons (cons name (cons nargs (
s!:endprocedure name env checksum))) s!:other_defs))))

(de s!:looks_like_lambda (u) (prog (v) (cond ((and (or (eqcar u (quote quote)
) (eqcar u (quote function))) (not (atom (cdr u))) (null (cddr u))) (setq u (
cadr u)))) (cond ((not (eqcar u (quote lambda))) (return nil))) (cond ((atom 
(setq u (cdr u))) (return nil))) (setq v (car u)) top (cond ((null v) (go 
vars_ok))) (cond ((atom v) (return nil))) (cond ((not (symbolp (car v))) (
return nil))) (setq v (cdr v)) (go top) vars_ok (setq u (cdr u)) (cond ((or (
atom u) (not (null (cdr u)))) (return nil))) (return t)))

(de s!:scan_for_embedded_lambdas (u) (cond ((atom u) nil) (t (cond ((not (
eqcar u (quote lambda))) (progn (s!:scan_for_embedded_lambdas (car u)) (
s!:scan_for_embedded_lambdas (cdr u)))) (t (prog (name checksum bvl body) (
cond ((not (zerop (posn))) (terpri))) (princ "Start LAMBDA: ") (print u) (
s!:scan_for_embedded_lambdas (car u)) (s!:scan_for_embedded_lambdas (cdr u)) 
(setq name (hashtagged!-name (quote lambda) u)) (cond ((atom (setq u (cdr u))
) (return nil))) (setq checksum (md60 u)) (princ "hashtagged name = ") (prin 
name) (princ " checksum = ") (prinhex checksum) (terpri) (setq bvl (car u)) (
setq u (cdr u)) (cond ((atom u) (return nil))) (setq u (cons name (compress (
append (explode name) (cons (quote !!) (cons (quote !~) (cons (quote !!) (
cons (quote !~) (explodehex checksum))))))))) (cond ((not (zerop (posn))) (
terpri))) (princ "Within LAMBDA: ") (print u) (setq s!:other_defs (cons u 
s!:other_defs))))))))

(de s!:scan_for_embedded_lambdas_fasl (u) (cond ((atom u) nil) (t (cond ((not
(eqcar u (quote lambda))) (progn (s!:scan_for_embedded_lambdas_fasl (car u))
(s!:scan_for_embedded_lambdas_fasl (cdr u)))) (t (prog (name checksum bvl 
body) (cond ((not (zerop (posn))) (terpri))) (princ "Start LAMBDA: ") (print 
u) (s!:scan_for_embedded_lambdas_fasl (car u)) (
s!:scan_for_embedded_lambdas_fasl (cdr u)) (setq name (hashtagged!-name (
quote lambda) u)) (cond ((atom (setq u (cdr u))) (return nil))) (setq 
checksum (md60 u)) (princ "hashtagged name = ") (prin name) (princ 
" checksum = ") (prinhex checksum) (terpri) (setq bvl (car u)) (setq u (cdr u
)) (cond ((atom u) (return nil))) (setq u (cons name (compress (append (
explode name) (cons (quote !!) (cons (quote !~) (cons (quote !!) (cons (quote
!~) (explodehex checksum))))))))) (cond ((not (zerop (posn))) (terpri))) (
princ "Within LAMBDA: ") (print u) (setq s!:other_defs (cons u s!:other_defs)
) (setq s!:fasl_code (cons (list (quote symbol!-set!-definition) (mkquote (
car u)) (mkquote (cdr u))) s!:fasl_code))))))))

(de s!:compile2 (name nargs nopts args oargs restarg body local_decs checksum
) (prog (fluids env penv g v init atend w) (prog (var1182) (setq var1182 args
) lab1181 (cond ((null var1182) (return nil))) (prog (v) (setq v (car var1182
)) (progn (setq env (cons 0 env)) (setq penv (cons env penv)))) (setq var1182
(cdr var1182)) (go lab1181)) (setq env (cons (mkhash (quote equal)) env)) (
puthash name (car env) (cons 10000000 nil)) (setq penv (reversip penv)) (cond
(restarg (setq oargs (append oargs (quote (0)))))) (prog (i) (setq i 1) 
lab1183 (cond ((minusp (times 1 (difference nargs i))) (return nil))) (setq 
oargs (cons 0 oargs)) (setq i (plus i 1)) (go lab1183)) (s!:start_procedure 
nargs nopts restarg) (prog nil lab1184 (cond ((null args) (return nil))) (
progn (setq v (car args)) (setq init (car oargs)) (cond ((equal init 0) (
progn (setq w (s!:instate_local_decs v local_decs w)) (cond ((fluidp v) (
progn (setq g (gensym)) (rplaca (car penv) g) (s!:outopcode1lit (quote 
FREEBIND) (s!:vecof (list v)) env) (rplacd env (cons 3 (cons 0 (cons 0 (cdr 
env))))) (setq atend (cons (quote FREERSTR) atend)) (s!:comval (list (quote 
setq) v g) env 2))) (t (rplaca (car penv) v))))) (t (prog (ival sp l1 l2) (
cond ((not (atom init)) (progn (setq init (cdr init)) (setq ival (car init)) 
(cond ((not (atom (cdr init))) (setq sp (cadr init))))))) (setq l1 (gensym)) 
(setq g (gensym)) (rplaca (car penv) g) (cond ((and (null ival) (null sp)) (
s!:comval (list (quote setq) g (list (quote spid!-to!-nil) g)) env 1)) (t (
progn (s!:jumpif nil (list (quote is!-spid) g) env l1) (s!:comval (list (
quote setq) g ival) env 1) (cond (sp (progn (cond ((fluidp sp) (progn (
s!:outopcode1lit (quote FREEBIND) (s!:vecof (list sp)) env) (s!:outjump (
quote JUMP) (setq l2 (gensym))) (s!:set_label l1) (s!:outopcode1lit (quote 
FREEBIND) (s!:vecof (list sp)) env) (rplacd env (cons 3 (cons 0 (cons 0 (cdr 
env))))) (s!:comval (list (quote setq) sp t) env 1) (s!:set_label l2) (setq 
atend (cons (quote FREERSTR) atend)))) (t (progn (s!:outopcode0 (quote 
PUSHNIL) (quote (PUSHNIL))) (s!:outjump (quote JUMP) (setq l2 (gensym))) (
s!:set_label l1) (s!:loadliteral t env) (s!:outopcode0 (quote PUSH) (quote (
PUSH))) (s!:set_label l2) (rplacd env (cons sp (cdr env))) (setq atend (cons 
(quote LOSE) atend))))))) (t (s!:set_label l1)))))) (setq w (
s!:instate_local_decs v local_decs w)) (cond ((fluidp v) (progn (
s!:outopcode1lit (quote FREEBIND) (s!:vecof (list v)) env) (rplacd env (cons 
3 (cons 0 (cons 0 (cdr env))))) (s!:comval (list (quote setq) v g) env 1) (
setq atend (cons (quote FREERSTR) atend)))) (t (rplaca (car penv) v)))))) (
setq args (cdr args)) (setq oargs (cdr oargs)) (setq penv (cdr penv))) (go 
lab1184)) (setq w (s!:residual_local_decs local_decs w)) (s!:comval body env 
0) (prog nil lab1185 (cond ((null atend) (return nil))) (progn (s!:outopcode0
(car atend) (list (car atend))) (setq atend (cdr atend))) (go lab1185)) (
s!:cancel_local_decs w) (setq nopts (plus nopts 256)) (cond (restarg (setq 
nopts (plus nopts 512)))) (setq nargs (plus nargs (times 256 nopts))) (setq 
s!:other_defs (cons (cons name (cons nargs (s!:endprocedure name env checksum
))) s!:other_defs))))

(de compile!-all nil (prog (var1187) (setq var1187 (reverse (oblist))) 
lab1186 (cond ((null var1187) (return nil))) (prog (x) (setq x (car var1187))
(prog (w) (setq w (getd x)) (cond ((and (or (eqcar w (quote expr)) (eqcar w 
(quote macro))) (eqcar (cdr w) (quote lambda))) (progn (princ "Compile: ") (
prin x) (terpri) (errorset (list (quote compile) (mkquote (list x))) t t)))))
) (setq var1187 (cdr var1187)) (go lab1186)))

(flag (quote (rds deflist flag fluid global keyword remprop remflag unfluid 
unkeyword unglobal dm defmacro carcheck faslend c_end)) (quote eval))

(flag (quote (rds)) (quote ignore))

(fluid (quote (!*backtrace)))

(de s!:fasl_supervisor nil (prog (u w !*echo) top (setq u (errorset (quote (
read)) t !*backtrace)) (cond ((atom u) (return nil))) (setq u (car u)) (cond 
((equal u !$eof!$) (return nil))) (cond ((not (atom u)) (setq u (macroexpand 
u)))) (cond ((atom u) (go top)) (t (cond ((eqcar u (quote faslend)) (return (
apply (quote faslend) nil))) (t (cond ((eqcar u (quote rdf)) (progn (setq w (
open (setq u (eval (cadr u))) (quote input))) (cond (w (progn (terpri) (princ
"Reading file ") (prin u) (terpri) (setq w (rds w)) (s!:fasl_supervisor) (
princ "End of file ") (prin u) (terpri) (close (rds w)))) (t (progn (princ 
"Failed to open file ") (prin u) (terpri)))))) (t (s!:fslout0 u))))))) (go 
top)))

(fluid (quote (s!:fasl_code s!:fasl_savedef)))

(de s!:fslout0 (u) (s!:fslout1 u nil))

(de s!:fslout1 (u loadonly) (prog (w) (cond ((not (atom u)) (setq u (
macroexpand u)))) (cond ((atom u) (return nil)) (t (cond ((eqcar u (quote 
progn)) (progn (prog (var1189) (setq var1189 (cdr u)) lab1188 (cond ((null 
var1189) (return nil))) (prog (v) (setq v (car var1189)) (s!:fslout1 v 
loadonly)) (setq var1189 (cdr var1189)) (go lab1188)) (return nil))) (t (cond
((eqcar u (quote eval!-when)) (return (prog nil (setq w (cadr u)) (setq u (
cons (quote progn) (cddr u))) (cond ((and (memq (quote compile) w) (not 
loadonly)) (eval u))) (cond ((memq (quote load) w) (s!:fslout1 u t))) (return
nil)))) (t (cond ((or (flagp (car u) (quote eval)) (and (equal (car u) (
quote setq)) (not (atom (caddr u))) (flagp (caaddr u) (quote eval)))) (cond (
(not loadonly) (errorset u t !*backtrace))))))))))) (cond ((eqcar u (quote 
rdf)) (prog nil (setq w (open (setq u (eval (cadr u))) (quote input))) (cond 
(w (progn (princ "Reading file ") (prin u) (terpri) (setq w (rds w)) (
s!:fasl_supervisor) (princ "End of file ") (prin u) (terpri) (close (rds w)))
) (t (progn (princ "Failed to open file ") (prin u) (terpri)))))) (t (cond (
!*nocompile (progn (cond ((and (not (eqcar u (quote faslend))) (not (eqcar u 
(quote carcheck)))) (setq s!:fasl_code (cons u s!:fasl_code)))))) (t (cond ((
or (eqcar u (quote de)) (eqcar u (quote defun))) (progn (setq u (cdr u)) (
cond ((and (setq w (get (car u) (quote c!-version))) (setq w (member (md60 (
cons (cadr u) (s!:fully_macroexpand_list (cddr u)))) w))) (progn (cond ((not 
(zerop (posn))) (terpri))) (princ "+++ ") (prin (car u)) (printc 
" has a C++ version available.") (s!:scan_for_embedded_lambdas_fasl (cddr u))
(setq s!:fasl_code (cons (list (quote symbol!-set!-definition) (mkquote (car
u)) (mkquote (compress (append (explode (car u)) (cons (quote !!) (cons (
quote !~) (cons (quote !!) (cons (quote !~) (explodehex (car w)))))))))) 
s!:fasl_code)))) (t (cond ((flagp (car u) (quote lose)) (progn (princ "+++ ")
(prin (car u)) (printc " not compiled (LOSE flag)"))) (t (prog (
s!:other_defs) (s!:compile1 (car u) (cadr u) (cddr u) nil) (prog (var1191) (
setq var1191 s!:other_defs) lab1190 (cond ((null var1191) (return nil))) (
prog (p) (setq p (car var1191)) (s!:fslout2 p u)) (setq var1191 (cdr var1191)
) (go lab1190))))))))) (t (cond ((or (eqcar u (quote dm)) (eqcar u (quote 
defmacro))) (prog (g) (setq g (hashtagged!-name (cadr u) (cddr u))) (setq u (
cdr u)) (cond ((flagp (car u) (quote lose)) (progn (princ "+++ ") (prin (car 
u)) (printc " not compiled (LOSE flag)") (return nil)))) (setq w (cadr u)) (
cond ((and w (null (cdr w))) (setq w (cons (car w) (cons (quote !&optional) (
cons (gensym) nil)))))) (prog (s!:other_defs) (s!:compile1 g w (cddr u) nil) 
(prog (var1193) (setq var1193 s!:other_defs) lab1192 (cond ((null var1193) (
return nil))) (prog (p) (setq p (car var1193)) (s!:fslout2 p u)) (setq 
var1193 (cdr var1193)) (go lab1192))) (setq s!:fasl_code (cons (list (quote 
dm) (car u) (quote (u !&optional e)) (list g (quote u) (quote e))) 
s!:fasl_code)))) (t (cond ((eqcar u (quote putd)) (prog (a1 a2 a3) (setq a1 (
cadr u)) (setq a2 (caddr u)) (setq a3 (cadddr u)) (cond ((and (eqcar a1 (
quote quote)) (or (equal a2 (quote (quote expr))) (equal a2 (quote (quote 
macro)))) (or (eqcar a3 (quote quote)) (eqcar a3 (quote function))) (eqcar (
cadr a3) (quote lambda))) (progn (setq a1 (cadr a1)) (setq a2 (cadr a2)) (
setq a3 (cadr a3)) (setq u (cons (cond ((equal a2 (quote expr)) (quote de)) (
t (quote dm))) (cons a1 (cdr a3)))) (s!:fslout1 u loadonly))) (t (setq 
s!:fasl_code (cons u s!:fasl_code)))))) (t (cond ((and (not (eqcar u (quote 
faslend))) (not (eqcar u (quote carcheck)))) (progn (setq s!:fasl_code (cons 
u s!:fasl_code)) (cond ((and !*savedef (eqcar u (quote put)) (not (atom (setq
w (cdr u)))) (eqcar (car w) (quote quote)) (not (atom (setq w (cdr w)))) (
eqcar (car w) (quote quote)) (memq (cadar w) (quote (procedure_type 
defined!-in!-file defined!-on!-line))) (or (numberp (setq w (cadr w))) (eqcar
w (quote quote)))) (setq s!:fasl_savedef (cons (list nil (cadar (setq u (cdr
u))) (cadar (setq u (cdr u))) (cond ((numberp w) w) (t (cadr w)))) 
s!:fasl_savedef)))))))))))))))))))

(de s!:fslout2 (p u) (prog (name nargs code env w) (setq name (car p)) (cond 
((atom (cdr p)) (progn (cond (!*savedef (setq s!:fasl_savedef (cons (list 
name (quote copied) (quote from) (cdr p)) s!:fasl_savedef)))) (setq 
s!:fasl_code (cons (list (quote symbol!-set!-definition) (mkquote name) (
mkquote (cdr p))) s!:fasl_code)) (return nil)))) (setq nargs (cadr p)) (setq 
code (caddr p)) (setq env (cdddr p)) (cond ((and !*savedef (equal name (car u
))) (progn (setq s!:fasl_savedef (cons (list name (cons (quote lambda) (cons 
(cadr u) (s!:fully_macroexpand_list (cddr u))))) s!:fasl_savedef))))) (setq 
s!:fasl_code (cons (list (quote symbol!-set!-definition) (mkquote name) (
mkquote (cons nargs (cons code env)))) s!:fasl_code))))

(remprop (quote faslend) (quote stat))

(de faslend nil (prog nil (cond ((null s!:faslmod_name) (return nil))) (cond 
((not (start!-module (car s!:faslmod_name))) (progn (cond ((neq (posn) 0) (
terpri))) (princ "+++ Failed to open FASL output file for ") (printc 
s!:faslmod_name) (return nil)))) (write!-module (cons (quote progn) (nreverse
s!:fasl_code)) (nreverse s!:fasl_savedef)) (start!-module nil) (princ 
"Completed FASL files for ") (print (car s!:faslmod_name)) (setq dfprint!* 
s!:dfprintsave) (setq !*defn nil) (setq !*comp (cdr s!:faslmod_name)) (setq 
s!:faslmod_name nil) (setq s!:fasl_code (setq s!:fasl_savedef nil)) (return 
nil)))

(put (quote faslend) (quote stat) (quote endstat))

(de s!:file (s) (prog (r) (setq s (reverse (explodec s))) (prog nil lab1194 (
cond ((null (and s (not (or (eqcar s (quote !/)) (eqcar s (quote !\)))))) (
return nil))) (progn (setq r (cons (car s) r)) (setq s (cdr s))) (go lab1194)
) (return (list2string r))))

(de s!:trim!.c (s) (prog (r) (setq s (reverse (explodec s))) (cond ((eqcar s 
(quote c)) (progn (setq s (cdr s)) (cond ((eqcar s (quote !.)) (setq s (cdr s
))))))) (return (list2string (reverse s)))))

(de s!:dir (s) (prog nil (setq s (reverse (explodec s))) (prog nil lab1195 (
cond ((null (and s (not (or (eqcar s (quote !/)) (eqcar s (quote !\)))))) (
return nil))) (setq s (cdr s)) (go lab1195)) (cond (s (setq s (cdr s)))) (
cond ((null s) (return ".")) (t (return (list2string (reverse s)))))))

(de faslout (u) (prog nil (terpri) (princ "FASLOUT ") (prin u) (princ 
": IN files;  or type in expressions") (terpri) (princ 
"When all done, execute FASLEND;") (terpri) (cond ((not (atom u)) (setq u (
car u)))) (setq s!:faslmod_name (cons u !*comp)) (setq s!:fasl_code (setq 
s!:fasl_savedef nil)) (setq s!:dfprintsave dfprint!*) (setq dfprint!* (quote 
s!:fslout0)) (setq !*defn t) (setq !*comp nil) (cond ((getd (quote begin)) (
return nil))) (s!:fasl_supervisor)))

(put (quote faslout) (quote stat) (quote rlis))

(de s!:compile!-file!* (fromfile !&optional tofile verbose !*pwrds) (prog (
!*comp w save) (cond ((null tofile) (setq tofile fromfile))) (cond (verbose (
progn (cond ((neq (posn) 0) (terpri))) (princ "+++ Compiling file ") (prin 
fromfile) (terpri) (setq save (verbos nil)) (verbos (ilogand save 4))))) (
cond ((not (start!-module tofile)) (progn (cond ((neq (posn) 0) (terpri))) (
princ "+++ Failed to open FASL output file") (terpri) (cond (save (verbos 
save))) (return nil)))) (setq w (open fromfile (quote input))) (cond (w (
progn (setq w (rds w)) (s!:fasl_supervisor) (close (rds w)))) (t (progn (
princ "Failed to open file ") (prin fromfile) (terpri)))) (cond (save (verbos
save))) (start!-module nil) (cond (verbose (progn (cond ((neq (posn) 0) (
terpri))) (princ "+++ Compilation complete") (terpri)))) (return t)))

(de compile!-file!* (fromfile !&optional tofile) (s!:compile!-file!* fromfile
tofile t t))

(de compd (name type defn) (prog (g !*comp) (setq !*comp t) (cond ((eqcar 
defn (quote lambda)) (progn (setq g (hashtagged!-name type defn)) (
symbol!-set!-definition g defn) (compile (list g)) (setq defn g)))) (put name
type defn) (return name)))

(de s!:compile0 (name) (prog (w args defn) (setq defn (getd name)) (cond ((
and (eqcar defn (quote macro)) (eqcar (cdr defn) (quote lambda))) (prog (
!*comp lx vx bx) (setq lx (cdr defn)) (cond ((not (or (and (equal (length lx)
3) (not (atom (setq bx (caddr lx)))) (equal (cadr lx) (cdr bx))) (and (equal
(length lx) 3) (not (atom (setq bx (caddr lx)))) (not (atom (cadr lx))) (
eqcar (cdadr lx) (quote !&optional)) (not (atom (setq bx (cdr bx)))) (equal (
caadr lx) (car bx)) (equal (cddadr lx) (cdr bx))))) (progn (setq w (
hashtagged!-name name defn)) (symbol!-set!-definition w (cdr defn)) (
s!:compile0 w) (cond ((equal 1 (length (cadr lx))) (symbol!-set!-env name (
list (quote (u !&optional env)) (list w (quote u))))) (t (symbol!-set!-env 
name (list (quote (u !&optional env)) (list w (quote u) (quote env)))))))))))
(t (cond ((or (not (eqcar defn (quote expr))) (not (eqcar (cdr defn) (quote 
lambda)))) (progn (cond (!*pwrds (progn (cond ((neq (posn) 0) (terpri))) (
princ "+++ ") (prin name) (princ " not compilable") (terpri)))))) (t (progn (
setq args (cddr defn)) (setq defn (cdr args)) (setq args (car args)) (cond ((
stringp args) (progn (cond (!*pwrds (progn (cond ((neq (posn) 0) (terpri))) (
princ "+++ ") (prin name) (princ " was already compiled") (terpri)))))) (t (
prog (s!:other_defs) (cond (!*savedef (put name (quote !*savedef) (cons (
quote lambda) (cons args (s!:fully_macroexpand_list defn)))))) (s!:compile1 
name args defn nil) (prog (var1197) (setq var1197 s!:other_defs) lab1196 (
cond ((null var1197) (return nil))) (prog (p) (setq p (car var1197)) (
symbol!-set!-definition (car p) (cdr p))) (setq var1197 (cdr var1197)) (go 
lab1196))))))))))))

(de s!:fully_macroexpand_list (l) (cond ((atom l) l) (t (prog (var1199 
var1200) (setq var1199 l) lab1198 (cond ((null var1199) (return (reversip 
var1200)))) (prog (u) (setq u (car var1199)) (setq var1200 (cons (
s!:fully_macroexpand u) var1200))) (setq var1199 (cdr var1199)) (go lab1198))
)))

(de s!:fully_macroexpand (x) (prog (helper) (cond ((or (atom x) (eqcar x (
quote quote))) (return x)) (t (cond ((eqcar (car x) (quote lambda)) (return (
cons (cons (quote lambda) (cons (cadar x) (s!:fully_macroexpand_list (cddar x
)))) (s!:fully_macroexpand_list (cdr x))))) (t (cond ((setq helper (get (car 
x) (quote s!:newname))) (return (s!:fully_macroexpand (cons helper (cdr x))))
) (t (cond ((setq helper (get (car x) (quote s!:expandfn))) (return (funcall 
helper x))) (t (cond ((setq helper (macro!-function (car x))) (return (
s!:fully_macroexpand (funcall helper x)))) (t (return (cons (car x) (
s!:fully_macroexpand_list (cdr x))))))))))))))))

(de s!:expandfunction (u) u)

(de s!:expandflet (u) (cons (car u) (cons (prog (var1202 var1203) (setq 
var1202 (cadr u)) lab1201 (cond ((null var1202) (return (reversip var1203))))
(prog (b) (setq b (car var1202)) (setq var1203 (cons (s!:expandfletvars b) 
var1203))) (setq var1202 (cdr var1202)) (go lab1201)) (
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

(de s!:expandlet (u) (cons (car u) (cons (prog (var1205 var1206) (setq 
var1205 (cadr u)) lab1204 (cond ((null var1205) (return (reversip var1206))))
(prog (x) (setq x (car var1205)) (setq var1206 (cons (
s!:fully_macroexpand_list x) var1206))) (setq var1205 (cdr var1205)) (go 
lab1204)) (s!:fully_macroexpand_list (cddr u)))))

(de s!:expandlet!* (u) (s!:expandlet u))

(de s!:expandgo (u) u)

(de s!:expandreturn!-from (u) (cons (car u) (cons (cadr u) (
s!:fully_macroexpand_list (cddr u)))))

(de s!:expandcond (u) (cons (car u) (prog (var1208 var1209) (setq var1208 (
cdr u)) lab1207 (cond ((null var1208) (return (reversip var1209)))) (prog (x)
(setq x (car var1208)) (setq var1209 (cons (s!:fully_macroexpand_list x) 
var1209))) (setq var1208 (cdr var1208)) (go lab1207))))

(de s!:expandcase (u) (cons (car u) (cons (s!:fully_macroexpand (cadr u)) (
prog (var1211 var1212) (setq var1211 (cddr u)) lab1210 (cond ((null var1211) 
(return (reversip var1212)))) (prog (x) (setq x (car var1211)) (setq var1212 
(cons (cons (car x) (s!:fully_macroexpand_list (cdr x))) var1212))) (setq 
var1211 (cdr var1211)) (go lab1210)))))

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

(de compile (l) (prog nil (cond ((and (atom l) (not (null l))) (setq l (list 
l)))) (prog (var1214) (setq var1214 l) lab1213 (cond ((null var1214) (return 
nil))) (prog (name) (setq name (car var1214)) (errorset (list (quote 
s!:compile0) (mkquote name)) t t)) (setq var1214 (cdr var1214)) (go lab1213))
(return l)))



(fluid (quote (!*fastvector !*unsafecar)))

(flag (quote (fastvector unsafecar)) (quote switch))

(global (quote (!*noisy)))

(setq !*noisy nil)

(fluid (quote (C_file L_file O_file L_contents Setup_name File_name)))

(dm c!:printf (u !&optional env) (list (quote c!:printf1) (cadr u) (cons (
quote list) (cddr u))))

(flag (quote (c!:printf)) (quote variadic))

(de c!:printf1 (fmt args) (prog (a c) (setq fmt (explode2 fmt)) (prog nil 
lab1215 (cond ((null fmt) (return nil))) (progn (setq c (car fmt)) (setq fmt 
(cdr fmt)) (cond ((and (equal c (quote !\)) (or (equal (car fmt) (quote !n)) 
(equal (car fmt) (quote !N)))) (progn (terpri) (setq fmt (cdr fmt)))) (t (
cond ((and (equal c (quote !\)) (or (equal (car fmt) (quote !q)) (equal (car 
fmt) (quote !Q)))) (progn (princ (quote !")) (setq fmt (cdr fmt)))) (t (cond 
((equal c (quote !%)) (progn (setq c (car fmt)) (cond ((null args) (setq a (
quote missing_arg))) (t (setq a (car args)))) (cond ((or (equal c (quote !v))
(equal c (quote !V))) (cond ((flagp a (quote c!:live_across_call)) (progn (
princ "stack[") (princ (minus (get a (quote c!:location)))) (princ "]"))) (t 
(princ a)))) (t (cond ((or (equal c (quote !c)) (equal c (quote !C))) (
c!:safeprin a)) (t (cond ((or (equal c (quote !a)) (equal c (quote !A))) (
prin a)) (t (cond ((or (equal c (quote !t)) (equal c (quote !T))) (ttab a)) (
t (cond ((equal c (quote !<)) (progn (setq args (cons nil args)) (cond ((
greaterp (posn) 70) (terpri))))) (t (princ a))))))))))) (cond (args (setq 
args (cdr args)))) (setq fmt (cdr fmt)))) (t (princ c)))))))) (go lab1215))))

(de c!:safeprin (x) (prog (n lastc) (setq n 0) (prog (var1217) (setq var1217 
(explode x)) lab1216 (cond ((null var1217) (return nil))) (prog (c) (setq c (
car var1217)) (progn (cond ((and (greaterp n 120) (equal c (quote ! ))) (
progn (terpri) (prin2 "//") (setq n 2))) (t (cond ((and (greaterp n 150) (neq
c !$eol!$)) (progn (terpri) (prin2 "// ") (setq n 3))) (t (setq n (plus n 1)
))))) (cond ((and (equal lastc (quote !\)) (equal c !$eol!$)) (princ 
" (backslash)"))) (setq lastc c) (princ c) (cond ((equal c !$eol!$) (progn (
princ "//") (setq n 2)))))) (setq var1217 (cdr var1217)) (go lab1216)) (cond 
((equal lastc (quote !\)) (princ " (backslash)")))))

(de c!:valid_fndef (args body) (cond ((or (memq (quote !&optional) args) (
memq (quote !&rest) args)) nil) (t (c!:valid_list body))))

(de c!:valid_list (x) (cond ((null x) t) (t (cond ((atom x) nil) (t (cond ((
not (c!:valid_expr (car x))) nil) (t (c!:valid_list (cdr x)))))))))

(de c!:valid_expr (x) (cond ((atom x) t) (t (cond ((not (atom (car x))) (
progn (cond ((not (c!:valid_list (cdr x))) nil) (t (cond ((not (eqcar (car x)
(quote lambda))) nil) (t (cond ((atom (cdar x)) nil) (t (c!:valid_fndef (
cadar x) (cddar x)))))))))) (t (cond ((not (idp (car x))) nil) (t (cond ((
eqcar x (quote quote)) t) (t (prog (h) (setq h (get (car x) (quote c!:valid))
) (cond ((null h) (return (c!:valid_list (cdr x))))) (return (funcall h (cdr 
x)))))))))))))

(de c!:cspecform (x env) (error 0 (list "special form" x)))

(de c!:valid_specform (x) nil)

(progn (put (quote and) (quote c!:code) (function c!:cspecform)) (put (quote 
catch) (quote c!:code) (function c!:cspecform)) (put (quote compiler!-let) (
quote c!:code) (function c!:cspecform)) (put (quote cond) (quote c!:code) (
function c!:cspecform)) (put (quote declare) (quote c!:code) (function 
c!:cspecform)) (put (quote de) (quote c!:code) (function c!:cspecform)) (put 
(quote eval!-when) (quote c!:code) (function c!:cspecform)) (put (quote flet)
(quote c!:code) (function c!:cspecform)) (put (quote function) (quote 
c!:code) (function c!:cspecform)) (put (quote go) (quote c!:code) (function 
c!:cspecform)) (put (quote if) (quote c!:code) (function c!:cspecform)) (put 
(quote labels) (quote c!:code) (function c!:cspecform)) (put (quote !~let) (
quote c!:code) (function c!:cspecform)) (put (quote let!*) (quote c!:code) (
function c!:cspecform)) (put (quote list) (quote c!:code) (function 
c!:cspecform)) (put (quote list!*) (quote c!:code) (function c!:cspecform)) (
put (quote macrolet) (quote c!:code) (function c!:cspecform)) (put (quote 
multiple!-value!-call) (quote c!:code) (function c!:cspecform)) (put (quote 
multiple!-value!-prog1) (quote c!:code) (function c!:cspecform)) (put (quote 
or) (quote c!:code) (function c!:cspecform)) (put (quote prog) (quote c!:code
) (function c!:cspecform)) (put (quote !~prog) (quote c!:code) (function 
c!:cspecform)) (put (quote prog!*) (quote c!:code) (function c!:cspecform)) (
put (quote prog1) (quote c!:code) (function c!:cspecform)) (put (quote prog2)
(quote c!:code) (function c!:cspecform)) (put (quote progn) (quote c!:code) 
(function c!:cspecform)) (put (quote progv) (quote c!:code) (function 
c!:cspecform)) (put (quote quote) (quote c!:code) (function c!:cspecform)) (
put (quote return) (quote c!:code) (function c!:cspecform)) (put (quote 
return!-from) (quote c!:code) (function c!:cspecform)) (put (quote setq) (
quote c!:code) (function c!:cspecform)) (put (quote tagbody) (quote c!:code) 
(function c!:cspecform)) (put (quote the) (quote c!:code) (function 
c!:cspecform)) (put (quote unless) (quote c!:code) (function c!:cspecform)) (
put (quote unwind!-protect) (quote c!:code) (function c!:cspecform)) (put (
quote when) (quote c!:code) (function c!:cspecform)) (put (quote catch) (
quote c!:valid) (function c!:valid_specform)) (put (quote compiler!-let) (
quote c!:valid) (function c!:valid_specform)) (put (quote cond) (quote 
c!:valid) (function c!:valid_specform)) (put (quote declare) (quote c!:valid)
(function c!:valid_specform)) (put (quote de) (quote c!:valid) (function 
c!:valid_specform)) (put (quote eval!-when) (quote c!:valid) (function 
c!:valid_specform)) (put (quote flet) (quote c!:valid) (function 
c!:valid_specform)) (put (quote function) (quote c!:valid) (function 
c!:valid_specform)) (put (quote labels) (quote c!:valid) (function 
c!:valid_specform)) (put (quote !~let) (quote c!:valid) (function 
c!:valid_specform)) (put (quote let!*) (quote c!:valid) (function 
c!:valid_specform)) (put (quote macrolet) (quote c!:valid) (function 
c!:valid_specform)) (put (quote multiple!-value!-call) (quote c!:valid) (
function c!:valid_specform)) (put (quote multiple!-value!-prog1) (quote 
c!:valid) (function c!:valid_specform)) (put (quote prog) (quote c!:valid) (
function c!:valid_specform)) (put (quote prog!*) (quote c!:valid) (function 
c!:valid_specform)) (put (quote progv) (quote c!:valid) (function 
c!:valid_specform)) (put (quote quote) (quote c!:valid) (function 
c!:valid_specform)) (put (quote the) (quote c!:valid) (function 
c!:valid_specform)) (put (quote unwind!-protect) (quote c!:valid) (function 
c!:valid_specform)))

(fluid (quote (c!:current_procedure c!:current_args c!:current_block 
c!:current_contents c!:all_blocks c!:registers c!:stacklocs)))

(fluid (quote (c!:used)))

(setq c!:used nil)

(de c!:alphanumeric (a b) (prog nil (setq a (compress (cddr (explodec a)))) (
setq b (compress (cddr (explodec b)))) (return (lessp a b))))

(fluid (quote (my_gensym_counter)))

(setq my_gensym_counter 0)

(de c!:reset_gensyms nil (progn (remflag c!:used (quote c!:live_across_call))
(remflag c!:used (quote c!:visited)) (prog nil lab1218 (cond ((null c!:used)
(return nil))) (progn (remprop (car c!:used) (quote c!:contents)) (remprop (
car c!:used) (quote c!:why)) (remprop (car c!:used) (quote c!:where_to)) (
remprop (car c!:used) (quote c!:count)) (remprop (car c!:used) (quote c!:live
)) (remprop (car c!:used) (quote c!:clash)) (remprop (car c!:used) (quote 
c!:chosen)) (remprop (car c!:used) (quote c!:location)) (cond ((plist (car 
c!:used)) (prog (o) (setq o (wrs nil)) (princ "+++++ ") (prin (car c!:used)) 
(princ " ") (prin (plist (car c!:used))) (terpri) (wrs o)))) (setq c!:used (
cdr c!:used))) (go lab1218)) (setq my_gensym_counter 0)))

(de c!:my_gensym nil (prog (w) (setq w (compress1 (cons (quote !v) (cons (
quote !_) (explodec (setq my_gensym_counter (plus my_gensym_counter 1))))))) 
(setq c!:used (cons w c!:used)) (cond ((plist w) (progn (princ "????? ") (
prin w) (princ " => ") (prin (plist w)) (terpri)))) (return w)))

(de c!:newreg nil (prog (r) (setq r (c!:my_gensym)) (setq c!:registers (cons 
r c!:registers)) (return r)))

(de c!:startblock (s) (progn (setq c!:current_block s) (setq 
c!:current_contents nil)))

(de c!:outop (a b c d) (cond (c!:current_block (setq c!:current_contents (
cons (list a b c d) c!:current_contents)))))

(de c!:endblock (why where_to) (cond (c!:current_block (progn (put 
c!:current_block (quote c!:contents) c!:current_contents) (put 
c!:current_block (quote c!:why) why) (put c!:current_block (quote c!:where_to
) where_to) (setq c!:all_blocks (cons c!:current_block c!:all_blocks)) (setq 
c!:current_contents nil) (setq c!:current_block nil)))))

(de c!:cval_inner (x env) (prog (helper) (setq x (s!:improve x)) (cond ((atom
x) (return (c!:catom x env))) (t (cond ((eqcar (car x) (quote lambda)) (
return (c!:clambda (cadar x) (cddar x) (cdr x) env))) (t (cond ((setq helper 
(get (car x) (quote c!:code))) (return (funcall helper x env))) (t (cond ((
and (setq helper (get (car x) (quote c!:compile_macro))) (setq helper (
funcall helper x))) (return (c!:cval helper env))) (t (cond ((and (idp (car x
)) (setq helper (macro!-function (car x)))) (return (c!:cval (funcall helper 
x) env))) (t (return (c!:ccall (car x) (cdr x) env))))))))))))))

(de c!:cval (x env) (prog (r) (setq r (c!:cval_inner x env)) (cond ((and r (
not (member!*!* r c!:registers))) (error 0 (list r "not a register" x)))) (
return r)))

(fluid (quote (c!:stack)))

(de c!:start_nested_context nil (prog nil (setq c!:stack (cons (list 
c!:current_block c!:current_contents c!:all_blocks) c!:stack)) (setq 
c!:all_blocks nil) (c!:startblock (c!:my_gensym))))

(de c!:end_nested_context nil (prog (l b w) (setq l (c!:my_gensym)) (
c!:endblock (quote goto) (list l)) (setq b (reverse c!:all_blocks)) (setq w (
car c!:stack)) (setq c!:stack (cdr c!:stack)) (setq c!:current_block (car w))
(setq c!:current_contents (cadr w)) (setq c!:all_blocks (caddr w)) (
c!:endblock (quote inner_block) b) (c!:startblock l)))

(de c!:clambda (bvl body args env) (prog (w w1 fluids env1 decs) (setq env1 (
car env)) (setq w (prog (var1220 var1221) (setq var1220 args) lab1219 (cond (
(null var1220) (return (reversip var1221)))) (prog (a) (setq a (car var1220))
(setq var1221 (cons (c!:cval a env) var1221))) (setq var1220 (cdr var1220)) 
(go lab1219))) (setq w1 (s!:find_local_decs body nil)) (setq localdecs (cons 
(car w1) localdecs)) (setq w1 (cdr w1)) (cond ((null w1) (setq body nil)) (t 
(cond ((null (cdr w1)) (setq body (car w1))) (t (setq body (cons (quote progn
) w1)))))) (prog (var1223) (setq var1223 bvl) lab1222 (cond ((null var1223) (
return nil))) (prog (x) (setq x (car var1223)) (cond ((and (not (fluidp x)) (
not (globalp x)) (c!:local_fluidp x localdecs)) (progn (make!-special x) (
setq decs (cons x decs)))))) (setq var1223 (cdr var1223)) (go lab1222)) (prog
 (var1225) (setq var1225 bvl) lab1224 (cond ((null var1225) (return nil))) (
prog (v) (setq v (car var1225)) (progn (cond ((globalp v) (prog (oo) (setq oo
(wrs nil)) (princ "+++++ ") (prin v) (princ 
" converted from GLOBAL to FLUID") (terpri) (wrs oo) (unglobal (list v)) (
fluid (list v))))) (cond ((fluidp v) (progn (setq fluids (cons (cons v (
c!:newreg)) fluids)) (flag (list (cdar fluids)) (quote c!:live_across_call)) 
(setq env1 (cons (cons (quote c!:dummy!:name) (cdar fluids)) env1)) (
c!:start_nested_context) (c!:outop (quote fluidbind) (cdar fluids) v (
c!:find_literal v)) (c!:outop (quote strglob) (car w) v (c!:find_literal v)))
) (t (progn (setq env1 (cons (cons v (c!:newreg)) env1)) (c!:outop (quote 
movr) (cdar env1) nil (car w))))) (setq w (cdr w)))) (setq var1225 (cdr 
var1225)) (go lab1224)) (setq env (cons env1 (append fluids (cdr env)))) (
setq w (c!:cval body env)) (prog (var1227) (setq var1227 fluids) lab1226 (
cond ((null var1227) (return nil))) (prog (v) (setq v (car var1227)) (progn (
c!:end_nested_context) (c!:outop (quote fluidunbind) (cdr v) (car v) (
c!:find_literal (car v))))) (setq var1227 (cdr var1227)) (go lab1226)) (
unfluid decs) (setq localdecs (cdr localdecs)) (return w)))

(de c!:locally_bound (x env) (atsoc x (car env)))

(flag (quote (nil t)) (quote c!:constant))

(fluid (quote (literal_vector)))

(de c!:find_literal (x) (prog (n w) (setq w literal_vector) (setq n 0) (prog 
nil lab1228 (cond ((null (and w (not (equal (car w) x)))) (return nil))) (
progn (setq n (plus n 1)) (setq w (cdr w))) (go lab1228)) (cond ((null w) (
setq literal_vector (append literal_vector (list x))))) (return n)))

(de c!:catom (x env) (prog (v w) (setq v (c!:newreg)) (cond ((or (null x) (
equal x (quote t)) (c!:small_number x)) (c!:outop (quote movk1) v nil x)) (t 
(cond ((and (idp x) (or (fluidp x) (globalp x))) (c!:outop (quote ldrglob) v 
x (c!:find_literal x))) (t (cond ((and (idp x) (setq w (c!:locally_bound x 
env))) (c!:outop (quote movr) v nil (cdr w))) (t (cond ((or (not (idp x)) (
flagp x (quote c!:constant))) (c!:outop (quote movk) v x (c!:find_literal x))
) (t (c!:outop (quote ldrglob) v x (c!:find_literal x)))))))))) (return v)))

(de c!:cjumpif (x env d1 d2) (prog (helper r) (setq x (s!:improve x)) (cond (
(and (atom x) (or (not (idp x)) (and (flagp x (quote c!:constant)) (not (
c!:locally_bound x env))))) (c!:endblock (quote goto) (list (cond (x d1) (t 
d2))))) (t (cond ((and (not (atom x)) (setq helper (get (car x) (quote 
c!:ctest)))) (return (funcall helper x env d1 d2))) (t (progn (setq r (
c!:cval x env)) (c!:endblock (list (quote ifnull) r) (list d2 d1)))))))))

(fluid (quote (c!:current c!:visited)))

(de c!:has_calls (a b) (prog (c!:visited) (return (c!:has_calls_1 a b))))

(de c!:has_calls_1 (a b) (cond ((or (equal a b) (not (atom a)) (memq a 
c!:visited)) nil) (t (prog (has_call) (setq c!:visited (cons a c!:visited)) (
prog (var1230) (setq var1230 (get a (quote c!:contents))) lab1229 (cond ((
null var1230) (return nil))) (prog (z) (setq z (car var1230)) (cond ((eqcar z
(quote call)) (setq has_call t)))) (setq var1230 (cdr var1230)) (go lab1229)
) (cond (has_call (return (prog (c!:visited) (return (c!:can_reach a b)))))) 
(prog (var1232) (setq var1232 (get a (quote c!:where_to))) lab1231 (cond ((
null var1232) (return nil))) (prog (d) (setq d (car var1232)) (cond ((
c!:has_calls_1 d b) (setq has_call t)))) (setq var1232 (cdr var1232)) (go 
lab1231)) (return has_call)))))

(de c!:can_reach (a b) (cond ((equal a b) t) (t (cond ((or (not (atom a)) (
memq a c!:visited)) nil) (t (progn (setq c!:visited (cons a c!:visited)) (
c!:any_can_reach (get a (quote c!:where_to)) b)))))))

(de c!:any_can_reach (l b) (cond ((null l) nil) (t (cond ((c!:can_reach (car 
l) b) t) (t (c!:any_can_reach (cdr l) b))))))

(de c!:evalargs (args env) (prog (r) (prog (var1234) (setq var1234 args) 
lab1233 (cond ((null var1234) (return nil))) (prog (a) (setq a (car var1234))
(setq r (cons (c!:cval a env) r))) (setq var1234 (cdr var1234)) (go lab1233)
) (return (reversip r))))

(de c!:ccall (fn args env) (cond ((equal fn (quote caar)) (c!:ccall (quote 
car) (list (list (quote car) (car args))) env)) (t (cond ((equal fn (quote 
cadr)) (c!:ccall (quote car) (list (list (quote cdr) (car args))) env)) (t (
cond ((equal fn (quote cdar)) (c!:ccall (quote cdr) (list (list (quote car) (
car args))) env)) (t (cond ((equal fn (quote cddr)) (c!:ccall (quote cdr) (
list (list (quote cdr) (car args))) env)) (t (prog (tasks merge r val) (setq 
fn (list fn (cdr env))) (setq val (c!:newreg)) (cond ((null args) (c!:outop (
quote call) val nil fn)) (t (cond ((null (cdr args)) (c!:outop (quote call) 
val (list (c!:cval (car args) env)) fn)) (t (progn (cond ((and (not (get (car
fn) (quote c!:direct_entrypoint))) (cddr args) (cdddr args)) (setq args (
list (car args) (cadr args) (caddr args) (cons (quote list) (cdddr args))))))
(setq r (c!:evalargs args env)) (c!:outop (quote call) val r fn)))))) (
c!:outop (quote reloadenv) (quote env) nil nil) (setq reloadenv t) (return 
val)))))))))))

(fluid (quote (restart_label reloadenv does_call c!:current_c_name)))

(de c!:local_fluidp1 (v decs) (and decs (or (and (eqcar (car decs) (quote 
special)) (memq v (cdar decs))) (c!:local_fluidp1 v (cdr decs)))))

(de c!:local_fluidp (v decs) (and decs (or (c!:local_fluidp1 v (car decs)) (
c!:local_fluidp v (cdr decs)))))

(fluid (quote (proglabs blockstack localdecs)))

(de c!:cfndef (c!:current_procedure c!:current_c_name lispname checksum 
argsbody) (prog (env n w c!:current_args c!:current_block restart_label 
c!:current_contents c!:all_blocks entrypoint exitpoint args1 c!:registers 
c!:stacklocs literal_vector reloadenv does_call blockstack proglabs args body
 localdecs varargs) (setq args (car argsbody)) (setq body (cdr argsbody)) (
setq w (s!:find_local_decs body nil)) (setq body (cdr w)) (cond ((atom body) 
(setq body nil)) (t (cond ((atom (cdr body)) (setq body (car body))) (t (setq
body (cons (quote progn) body)))))) (setq localdecs (list (car w))) (
c!:reset_gensyms) (wrs C_file) (linelength 200) (c!:printf 
"\n\n// Code for %a\n\n" c!:current_procedure) (c!:find_literal 
c!:current_procedure) (setq c!:current_args args) (setq varargs (geq (length 
args) 4)) (prog (var1236) (setq var1236 args) lab1235 (cond ((null var1236) (
return nil))) (prog (v) (setq v (car var1236)) (cond ((or (equal v (quote 
!&optional)) (equal v (quote !&rest))) (error 0 
"&optional and &rest not supported by this compiler (yet)")) (t (cond ((
globalp v) (prog (oo) (setq oo (wrs nil)) (princ "+++++ ") (prin v) (princ 
" converted from GLOBAL to FLUID") (terpri) (wrs oo) (unglobal (list v)) (
fluid (list v)) (setq n (cons (cons v (c!:my_gensym)) n)))) (t (cond ((or (
fluidp v) (c!:local_fluidp v localdecs)) (setq n (cons (cons v (c!:my_gensym)
) n))))))))) (setq var1236 (cdr var1236)) (go lab1235)) (cond (!*r2i (setq 
body (s!:r2i c!:current_procedure args body)))) (setq restart_label (
c!:my_gensym)) (setq body (list (quote c!:private_tagbody) restart_label body
)) (cond (n (progn (setq body (list (list (quote return) body))) (setq args (
subla n args)) (prog (var1238) (setq var1238 n) lab1237 (cond ((null var1238)
(return nil))) (prog (v) (setq v (car var1238)) (setq body (cons (list (
quote setq) (car v) (cdr v)) body))) (setq var1238 (cdr var1238)) (go lab1237
)) (setq body (cons (quote !~prog) (cons (prog (var1240 var1241) (setq 
var1240 (reverse n)) lab1239 (cond ((null var1240) (return (reversip var1241)
))) (prog (v) (setq v (car var1240)) (setq var1241 (cons (car v) var1241))) (
setq var1240 (cdr var1240)) (go lab1239)) body)))))) (c!:printf 
"static LispObject %s(LispObject env" c!:current_c_name) (setq env nil) (cond
(varargs (progn (prog (var1243) (setq var1243 (list (car args) (cadr args) (
caddr args))) lab1242 (cond ((null var1243) (return nil))) (prog (x) (setq x 
(car var1243)) (prog (aa) (c!:printf ",") (cond (n (progn (c!:printf 
"\n                        ") (setq n nil))) (t (setq n t))) (setq aa (
c!:my_gensym)) (setq env (cons (cons x aa) env)) (setq c!:registers (cons aa 
c!:registers)) (setq args1 (cons aa args1)) (c!:printf " LispObject %s" aa)))
(setq var1243 (cdr var1243)) (go lab1242)) (c!:printf ", LispObject _a4up_")
)) (t (progn (setq n t) (prog (var1245) (setq var1245 args) lab1244 (cond ((
null var1245) (return nil))) (prog (x) (setq x (car var1245)) (prog (aa) (
c!:printf ",") (cond (n (progn (c!:printf "\n                        ") (setq
n nil))) (t (setq n t))) (setq aa (c!:my_gensym)) (setq env (cons (cons x aa
) env)) (setq c!:registers (cons aa c!:registers)) (setq args1 (cons aa args1
)) (c!:printf " LispObject %s" aa))) (setq var1245 (cdr var1245)) (go lab1244
))))) (c!:printf ")\n{\n") (c!:printf "    env = qenv(env);\n") (cond (
varargs (prog (var1247) (setq var1247 (cdddr args)) lab1246 (cond ((null 
var1247) (return nil))) (prog (x) (setq x (car var1247)) (prog (aa) (setq aa 
(c!:my_gensym)) (setq env (cons (cons x aa) env)) (setq c!:registers (cons aa
c!:registers)) (setq args1 (cons aa args1)))) (setq var1247 (cdr var1247)) (
go lab1246)))) (c!:startblock (setq entrypoint (c!:my_gensym))) (setq 
exitpoint c!:current_block) (c!:endblock (quote goto) (list (list (c!:cval 
body (cons env nil))))) (c!:optimise_flowgraph entrypoint c!:all_blocks env (
cons (length args) c!:current_procedure) (reverse args1) varargs) (c!:printf 
"}\n\n") (wrs O_file) (setq L_contents (cons (cons lispname (cons 
literal_vector checksum)) L_contents)) (return nil)))

(flag (quote (rds deflist flag fluid global remprop remflag unfluid unglobal 
dm carcheck C!-end)) (quote eval))

(flag (quote (rds)) (quote ignore))

(fluid (quote (!*backtrace)))

(de c!:ccompilesupervisor nil (prog (u w) top (setq u (errorset (quote (read)
) t !*backtrace)) (cond ((atom u) (return nil))) (setq u (car u)) (cond ((
equal u !$eof!$) (return nil))) (cond ((atom u) (go top)) (t (cond ((eqcar u 
(quote C!-end)) (return (apply (quote C!-end) nil))) (t (cond ((eqcar u (
quote rdf)) (progn (setq w (open (setq u (eval (cadr u))) (quote input))) (
cond (w (progn (terpri) (princ "Reading file ") (print u) (setq w (rds w)) (
c!:ccompilesupervisor) (princ "End of file ") (print u) (close (rds w)))) (t 
(progn (princ "Failed to open file ") (print u)))))) (t (c!:ccmpout1 u)))))))
(go top)))

(global (quote (c!:char_mappings)))

(setq c!:char_mappings (quote ((!  . !A) (!! . !B) (!# . !C) (!$ . !D) (!% . 
!E) (!^ . !F) (!& . !G) (!* . !H) (!( . !I) (!) . !J) (!- . !K) (!+ . !L) (!=
 . !M) (!\ . !N) (!| . !O) (!, . !P) (!. . !Q) (!< . !R) (!> . !S) (!: . !T) 
(!; . !U) (!/ . !V) (!? . !W) (!~ . !X) (!` . !Y))))

(fluid (quote (c!:names_so_far)))

(de c!:inv_name (n checksum) (prog (r w) (cond ((setq w (assoc n 
c!:names_so_far)) (setq w (plus (cdr w) 1))) (t (setq w 0))) (setq 
c!:names_so_far (cons (cons n w) c!:names_so_far)) (setq r (quote (!C !C !"))
) (cond ((not (zerop w)) (setq r (append (reverse (explodec w)) r)))) (setq r
(cons (quote !_) r)) (prog (var1249) (setq var1249 (explode2 n)) lab1248 (
cond ((null var1249) (return nil))) (prog (c) (setq c (car var1249)) (progn (
cond ((equal c (quote _)) (setq r (cons (quote _) r))) (t (cond ((or (liter c
) (digit c)) (setq r (cons c r))) (t (cond ((setq w (atsoc c c!:char_mappings
)) (setq r (cons (cdr w) r))) (t (setq r (cons (quote !Z) r)))))))))) (setq 
var1249 (cdr var1249)) (go lab1248)) (setq r (append (reverse (explodehex 
checksum)) r)) (setq r (cons (quote !") r)) (return (compress (reverse r)))))

(fluid (quote (c!:defnames pending_functions)))

(de c!:ccmpout1 (u) (prog (pending_functions) (setq pending_functions (list u
)) (prog nil lab1250 (cond ((null pending_functions) (return nil))) (progn (
setq u (car pending_functions)) (setq pending_functions (cdr 
pending_functions)) (c!:ccmpout1a u)) (go lab1250))))

(de c!:ccmpout1a (u) (prog (file checksum cname lispname) (cond ((atom u) (
return nil)) (t (cond ((eqcar u (quote progn)) (progn (prog (var1252) (setq 
var1252 (cdr u)) lab1251 (cond ((null var1252) (return nil))) (prog (v) (setq
v (car var1252)) (c!:ccmpout1a v)) (setq var1252 (cdr var1252)) (go lab1251)
) (return nil))) (t (cond ((eqcar u (quote C!-end)) nil) (t (cond ((or (flagp
(car u) (quote eval)) (and (equal (car u) (quote setq)) (not (atom (caddr u)
)) (flagp (caaddr u) (quote eval)))) (errorset u t !*backtrace))))))))) (cond
((eqcar u (quote rdf)) (prog nil (setq file (open (setq u (eval (cadr u))) (
quote input))) (cond (file (progn (princ "Reading file ") (print u) (setq 
file (rds file)) (c!:ccompilesupervisor) (princ "End of file ") (print u) (
close (rds file)))) (t (progn (princ "Failed to open file ") (print u)))))) (
t (cond ((eqcar u (quote de)) (progn (setq u (cdr u)) (setq checksum (md60 (
cdr u))) (setq lispname (compress (append (explode (car u)) (cons (quote !!) 
(cons (quote !~) (cons (quote !!) (cons (quote !~) (explodehex checksum))))))
)) (setq cname (c!:inv_name (car u) checksum)) (setq c!:defnames (cons (list 
lispname cname (length (cadr u)) checksum) c!:defnames)) (cond ((greaterp (
posn) 10) (terpri))) (princ "Compiling ") (prin (caar c!:defnames)) (princ 
" ... ") (c!:cfndef (car u) cname lispname checksum (cdr u)) (terpri))))))))

(fluid (quote (!*defn dfprint!* dfprintsave)))

(de c!:concat (a b) (compress (cons (quote !") (append (explode2 a) (append (
explode2 b) (quote (!")))))))

(de c!:ccompilestart (name setupname dir) (prog (o d w) (setq c!:registers (
setq c!:used nil)) (setq File_name (list2string (explodec name))) (setq 
Setup_name (explodec setupname)) (setq Setup_name (subst (quote !_) (quote !-
) Setup_name)) (setq Setup_name (list2string Setup_name)) (cond (dir (progn (
cond ((memq (quote win32) lispsystem!*) (setq name (c!:concat dir (c!:concat 
"\" name)))) (t (setq name (c!:concat dir (c!:concat "/" name)))))))) (princ 
"C file = ") (print name) (setq C_file (open (c!:concat name ".cpp") (quote 
output))) (setq L_file (c!:concat name ".lsp")) (setq L_contents nil) (setq 
c!:names_so_far nil) (setq o (reverse (explode (date!-and!-time)))) (prog (i)
(setq i 1) lab1253 (cond ((minusp (times 1 (difference 5 i))) (return nil)))
(progn (setq d (cons (car o) d)) (setq o (cdr o))) (setq i (plus i 1)) (go 
lab1253)) (setq d (cons (quote !-) d)) (setq o (cdddr (cdddr (cddddr o)))) (
setq w o) (setq o (cdddr o)) (setq d (cons (caddr o) (cons (cadr o) (cons (
car o) d)))) (setq d (compress (cons (quote !") (cons (cadr w) (cons (car w) 
(cons (quote !-) d)))))) (setq O_file (wrs C_file)) (setq c!:defnames nil) (
c!:printf "\n// %s.c %tMachine generated C code\n\n" name 25) (c!:printf 
"// $I") (c!:printf "d: $\n\n") (c!:printf "#include \qconfig.h\q\n") (
c!:printf "#include \qheaders.h\q\n\n") (wrs O_file) (return nil)))

(de C!-end nil (prog (checksum c1 c2 c3 stubs) (wrs C_file) (cond ((equal (
explodec Setup_name) (explodec (quote stubs))) (progn (setq stubs t) (setq 
Setup_name "u01")))) (c!:printf "\n\nsetup_type const %s_setup[] =\n{\n" 
Setup_name) (setq c!:defnames (reverse c!:defnames)) (prog nil lab1254 (cond 
((null c!:defnames) (return nil))) (prog (w name nargs f0 f1 f2 f3 f4up) (
setq w (car c!:defnames)) (setq name (car w)) (setq f0 (car (setq w (cdr w)))
) (setq nargs (car (setq w (cdr w)))) (setq checksum (car (setq w (cdr w)))) 
(cond ((equal nargs 0) (progn (setq f1 "G1W0") (setq f2 "G2W0") (setq f3 
"G3W0") (setq f4up "G4W0"))) (t (cond ((equal nargs 1) (progn (setq f1 f0) (
setq f0 "G0W1") (setq f2 "G2W1") (setq f3 "G3W1") (setq f4up "G4W1"))) (t (
cond ((equal nargs 2) (progn (setq f2 f0) (setq f0 "G0W2") (setq f1 "G1W2") (
setq f3 "G3W2") (setq f4up "G4W2"))) (t (cond ((equal nargs 3) (progn (setq 
f3 f0) (setq f0 "G0W3") (setq f1 "G1W3") (setq f2 "G2W3") (setq f4up "G4W3"))
) (t (progn (setq f4up f0) (setq f0 "G0W4up") (setq f1 "G1W4up") (setq f2 
"G2W4up") (setq f3 "G3W4up")))))))))) (c!:printf 
"    {\q%s\q,%t%s,%t%s,%t%s,%t%s,%t%s},\n" name 32 f0 42 f1 52 f2 62 f3 72 
f4up) (setq c!:defnames (cdr c!:defnames))) (go lab1254)) (setq c3 (setq 
checksum (md60 L_contents))) (setq c1 (remainder c3 10000000)) (setq c3 (
quotient c3 10000000)) (setq c2 (remainder c3 10000000)) (setq c3 (quotient 
c3 10000000)) (setq checksum (list2string (append (explodec c3) (cons (quote 
! ) (append (explodec c2) (cons (quote ! ) (explodec c1))))))) (c!:printf 
"    {nullptr, \n") (c!:printf "        reinterpret_cast<no_args *>(\n") (
c!:printf "            reinterpret_cast<uintptr_t>(%a)),\n" Setup_name) (
c!:printf "        reinterpret_cast<one_arg *>(\n") (c!:printf 
"            reinterpret_cast<uintptr_t>(%a)),\n" checksum) (c!:printf 
"        nullptr, nullptr, nullptr}\n};\n\n") (cond (stubs (progn (prog (i) (
setq i 2) lab1255 (cond ((minusp (times 1 (difference 60 i))) (return nil))) 
(progn (c!:printf "setup_type const u") (cond ((lessp i 10) (c!:printf "0")))
(c!:printf "%s_setup[] = {\n" i) (c!:printf "    {nullptr, \n") (c!:printf 
"        reinterpret_cast<no_args *>(\n") (c!:printf 
"            reinterpret_cast<uintptr_t>(%a)),\n" Setup_name) (c!:printf 
"        reinterpret_cast<one_arg *>(\n") (c!:printf 
"            reinterpret_cast<uintptr_t>(%a)),\n" checksum) (c!:printf 
"        nullptr, nullptr, nullptr}\n};\n\n")) (setq i (plus i 1)) (go 
lab1255)) (c!:printf "\n\n")))) (c!:printf "%<// end of generated code\n") (
close C_file) (setq L_file (open L_file (quote output))) (wrs L_file) (
linelength 72) (terpri) (princ "% ") (princ Setup_name) (princ ".lsp") (ttab 
20) (princ "Machine generated Lisp") (terpri) (terpri) (princ 
"(check!-c!-code ") (princ (quote !")) (princ Setup_name) (princ (quote !")) 
(princ " ") (princ checksum) (printc ")") (terpri) (prog (var1257) (setq 
var1257 (reverse L_contents)) lab1256 (cond ((null var1257) (return nil))) (
prog (x) (setq x (car var1257)) (progn (princ "(c!:install '") (prin (car x))
(princ " '") (prin (cadr x)) (princ " ") (prin (cddr x)) (princ ")") (terpri
) (terpri))) (setq var1257 (cdr var1257)) (go lab1256)) (terpri) (princ 
"% End of generated Lisp code") (c!:reset_gensyms) (terpri) (terpri) (setq 
L_contents nil) (wrs O_file) (close L_file) (setq !*defn nil) (setq dfprint!*
dfprintsave)))

(put (quote C!-end) (quote stat) (quote endstat))

(de C!-compile (u) (prog nil (terpri) (princ "C!-COMPILE ") (prin u) (princ 
": IN files;  or type in expressions") (terpri) (princ 
"When all done, execute C!-END;") (terpri) (verbos nil) (c!:ccompilestart (
car u) (car u) nil) (setq dfprintsave dfprint!*) (setq dfprint!* (quote 
c!:ccmpout1)) (setq !*defn t) (cond ((getd (quote begin)) (return nil))) (
c!:ccompilesupervisor)))

(put (quote C!-compile) (quote stat) (quote rlis))

(de c!:print_opcode (s) (prog (op r1 r2 r3 helper) (setq op (car s)) (setq r1
(cadr s)) (setq r2 (caddr s)) (setq r3 (cadddr s)) (setq helper (get op (
quote c!:opcode_printer))) (cond (helper (funcall helper op r1 r2 r3)) (t (
progn (prin s) (terpri))))))

(de c!:print_exit_condition (why where_to next) (prog (helper) (cond ((equal 
why (quote goto)) (progn (setq where_to (car where_to)) (cond ((equal 
where_to next) nil) (t (cond ((atom where_to) (c!:printf "    goto %s;\n" 
where_to)) (t (progn (c!:printf "    ") (c!:pgoto where_to)))))) (return nil)
)) (t (cond ((eqcar (car why) (quote call)) (return (prog (args locs g w) (
cond ((setq w (get (cadar why) (quote c!:direct_entrypoint))) (progn (prog (
var1259) (setq var1259 (cdr why)) lab1258 (cond ((null var1259) (return nil))
) (prog (a) (setq a (car var1259)) (cond ((flagp a (quote c!:live_across_call
)) (progn (cond ((null g) (c!:printf "    {\n"))) (setq g (c!:my_gensym)) (
c!:printf "        LispObject %s = %v;\n" g a) (setq args (cons g args)))) (t
(setq args (cons a args))))) (setq var1259 (cdr var1259)) (go lab1258)) (
cond (g (c!:printf "    "))) (c!:printf "    return %s(" (cdr w)) (setq args 
(reversip args)) (cond (args (progn (c!:printf "%v" (car args)) (prog (
var1261) (setq var1261 (cdr args)) lab1260 (cond ((null var1261) (return nil)
)) (prog (a) (setq a (car var1261)) (c!:printf ", %v" a)) (setq var1261 (cdr 
var1261)) (go lab1260))))) (c!:printf ");\n") (cond (g (c!:printf "    }\n"))
))) (t (cond ((setq w (get (cadar why) (quote c!:c_entrypoint))) (progn (prog
 (var1263) (setq var1263 (cdr why)) lab1262 (cond ((null var1263) (return nil
))) (prog (a) (setq a (car var1263)) (cond ((flagp a (quote 
c!:live_across_call)) (progn (cond ((null g) (c!:printf "    {\n"))) (setq g 
(c!:my_gensym)) (c!:printf "        LispObject %s = %v;\n" g a) (setq args (
cons g args)))) (t (setq args (cons a args))))) (setq var1263 (cdr var1263)) 
(go lab1262)) (c!:printf "        return %s(nil" w) (prog (var1265) (setq 
var1265 (reversip args)) lab1264 (cond ((null var1265) (return nil))) (prog (
a) (setq a (car var1265)) (c!:printf ", %v" a)) (setq var1265 (cdr var1265)) 
(go lab1264)) (c!:printf ");\n") (cond (g (c!:printf "    }\n"))))) (t (prog 
(nargs) (setq nargs (length (cdr why))) (c!:printf "    {") (c!:printf 
"   LispObject fn = basic_elt(env, %s); %<// %c\n" (c!:find_literal (cadar 
why)) (cadar why)) (cond ((equal nargs 0) (c!:printf 
"        return (*qfn0(fn))(fn")) (t (cond ((equal nargs 1) (c!:printf 
"        return (*qfn1(fn))(fn")) (t (cond ((equal nargs 2) (c!:printf 
"        return (*qfn2(fn))(fn")) (t (cond ((equal nargs 3) (c!:printf 
"        return (*qfn3(fn))(fn")) (t (c!:printf 
"        return (*qfn4up(fn))(fn"))))))))) (prog (var1267) (setq var1267 (cdr
why)) lab1266 (cond ((null var1267) (return nil))) (prog (a) (setq a (car 
var1267)) (c!:printf ", %v" a)) (setq var1267 (cdr var1267)) (go lab1266)) (
c!:printf ");\n    }\n")))))) (return nil))))))) (setq helper (get (car why) 
(quote c!:exit_helper))) (cond ((null helper) (error 0 (list 
"Bad exit condition" why)))) (c!:printf "    if (") (funcall helper (cdr why)
) (c!:printf ") ") (c!:pgoto (car where_to)) (cond ((neq (cadr where_to) next
) (progn (c!:printf "    else ") (c!:pgoto (cadr where_to)))))))

(de c!:pmovr (op r1 r2 r3) (c!:printf "    %v = %v;\n" r1 r3))

(put (quote movr) (quote c!:opcode_printer) (function c!:pmovr))

(de c!:pmovk (op r1 r2 r3) (c!:printf 
"    %v = basic_elt(env, %s); %<// %c\n" r1 r3 r2))

(put (quote movk) (quote c!:opcode_printer) (function c!:pmovk))

(de c!:pmovk1 (op r1 r2 r3) (cond ((null r3) (c!:printf "    %v = nil;\n" r1)
) (t (cond ((equal r3 (quote t)) (c!:printf "    %v = lisp_true;\n" r1)) (t (
c!:printf "    %v = static_cast<LispObject>(%s)+TAG_FIXNUM; %<// %c\n" r1 (
times 16 r3) r3))))))

(put (quote movk1) (quote c!:opcode_printer) (function c!:pmovk1))

(flag (quote (movk1)) (quote c!:uses_nil))

(de c!:preloadenv (op r1 r2 r3) (c!:printf "    env = stack[%s];\n" (minus 
reloadenv)))

(put (quote reloadenv) (quote c!:opcode_printer) (function c!:preloadenv))

(de c!:pldrglob (op r1 r2 r3) (c!:printf 
"    %v = qvalue(basic_elt(env, %s)); %<// %c\n" r1 r3 r2))

(put (quote ldrglob) (quote c!:opcode_printer) (function c!:pldrglob))

(de c!:pstrglob (op r1 r2 r3) (c!:printf 
"    setvalue(basic_elt(env, %s), %v); %<// %c\n" r3 r1 r2))

(put (quote strglob) (quote c!:opcode_printer) (function c!:pstrglob))

(de c!:pnilglob (op r1 r2 r3) (c!:printf 
"    setvalue(basic_elt(env, %s), nil); %<// %c\n" r3 r2))

(put (quote nilglob) (quote c!:opcode_printer) (function c!:pnilglob))

(flag (quote (nilglob)) (quote c!:uses_nil))

(de c!:pnull (op r1 r2 r3) (c!:printf 
"    %v = (%v == nil ? lisp_true : nil);\n" r1 r3))

(put (quote null) (quote c!:opcode_printer) (function c!:pnull))

(put (quote not) (quote c!:opcode_printer) (function c!:pnull))

(flag (quote (null not)) (quote c!:uses_nil))

(de c!:pfastget (op r1 r2 r3) (progn (c!:printf 
"    if (!symbolp(%v)) %v = nil;\n" r2 r1) (c!:printf 
"    else { %v = qfastgets(%v);\n" r1 r2) (c!:printf 
"           if (%v != nil) { %v = elt(%v, %s); %<// %c\n" r1 r1 r1 (car r3) (
cdr r3)) (c!:printf "             if (%v == SPID_NOPROP) %v = nil; }}\n" r1 
r1)))

(put (quote fastget) (quote c!:opcode_printer) (function c!:pfastget))

(flag (quote (fastget)) (quote c!:uses_nil))

(de c!:pfastflag (op r1 r2 r3) (progn (c!:printf 
"    if (!symbolp(%v)) %v = nil;\n" r2 r1) (c!:printf 
"    else { %v = qfastgets(%v);\n" r1 r2) (c!:printf 
"           if (%v != nil) { %v = elt(%v, %s); %<// %c\n" r1 r1 r1 (car r3) (
cdr r3)) (c!:printf 
"             if (%v == SPID_NOPROP) %v = nil; else %v = lisp_true; }}\n" r1 
r1 r1)))

(put (quote fastflag) (quote c!:opcode_printer) (function c!:pfastflag))

(flag (quote (fastflag)) (quote c!:uses_nil))

(de c!:pcar (op r1 r2 r3) (prog nil (cond ((not !*unsafecar) (progn (
c!:printf "#ifndef UNSAFE_CAR\n") (c!:printf 
"    if (!car_legal(%v)) UNLIKELY return carerror(%v);\n" r3 r3) (c!:printf 
"#endif\n")))) (c!:printf "    %v = car(%v);\n" r1 r3)))

(put (quote car) (quote c!:opcode_printer) (function c!:pcar))

(de c!:pcdr (op r1 r2 r3) (prog nil (cond ((not !*unsafecar) (progn (
c!:printf "#ifndef UNSAFE_CAR\n") (c!:printf 
"    if (!car_legal(%v)) UNLIKELY return cdrerror(%v);\n" r3 r3) (c!:printf 
"#endif\n")))) (c!:printf "    %v = cdr(%v);\n" r1 r3)))

(put (quote cdr) (quote c!:opcode_printer) (function c!:pcdr))

(de c!:pqcar (op r1 r2 r3) (c!:printf "    %v = car(%v);\n" r1 r3))

(put (quote qcar) (quote c!:opcode_printer) (function c!:pqcar))

(de c!:pqcdr (op r1 r2 r3) (c!:printf "    %v = cdr(%v);\n" r1 r3))

(put (quote qcdr) (quote c!:opcode_printer) (function c!:pqcdr))

(de c!:patom (op r1 r2 r3) (c!:printf 
"    %v = (consp(%v) ? nil : lisp_true);\n" r1 r3))

(put (quote atom) (quote c!:opcode_printer) (function c!:patom))

(flag (quote (atom)) (quote c!:uses_nil))

(de c!:pnumberp (op r1 r2 r3) (c!:printf 
"    %v = (is_number(%v) ? lisp_true : nil);\n" r1 r3))

(put (quote numberp) (quote c!:opcode_printer) (function c!:pnumberp))

(flag (quote (numberp)) (quote c!:uses_nil))

(de c!:pfixp (op r1 r2 r3) (c!:printf "    %v = integerp(%v);\n" r1 r3))

(put (quote fixp) (quote c!:opcode_printer) (function c!:pfixp))

(flag (quote (fixp)) (quote c!:uses_nil))

(de c!:piminusp (op r1 r2 r3) (c!:printf 
"    %v = (static_cast<std::intptr_t>(%v) < 0 ? lisp_true : nil);\n" r1 r3))

(put (quote iminusp) (quote c!:opcode_printer) (function c!:piminusp))

(flag (quote (iminusp)) (quote c!:uses_nil))

(de c!:pilessp (op r1 r2 r3) (c!:printf 
"    %v = (static_cast<std::intptr_t>(%v) < static_cast<std::intptr_t>(%v)) ? lisp_true : nil;\n"
r1 r2 r3))

(put (quote ilessp) (quote c!:opcode_printer) (function c!:pilessp))

(flag (quote (ilessp)) (quote c!:uses_nil))

(de c!:pigreaterp (op r1 r2 r3) (c!:printf 
"    %v = (static_cast<std::intptr_t>(%v) > static_cast<std::intptr_t>(%v)) ? lisp_true : nil;\n"
r1 r2 r3))

(put (quote igreaterp) (quote c!:opcode_printer) (function c!:pigreaterp))

(flag (quote (igreaterp)) (quote c!:uses_nil))

(de c!:piminus (op r1 r2 r3) (c!:printf 
"    %v = static_cast<LispObject>(2*TAG_FIXNUM-(static_cast<std::intptr_t>(%v)));\n"
r1 r3))

(put (quote iminus) (quote c!:opcode_printer) (function c!:piminus))

(de c!:piadd1 (op r1 r2 r3) (c!:printf 
"    %v = static_cast<LispObject>(static_cast<std::intptr_t>(%v) + 0x10);\n" 
r1 r3))

(put (quote iadd1) (quote c!:opcode_printer) (function c!:piadd1))

(de c!:pisub1 (op r1 r2 r3) (c!:printf 
"    %v = static_cast<LispObject>(static_cast<std::intptr_t>(%v) - 0x10);\n" 
r1 r3))

(put (quote isub1) (quote c!:opcode_printer) (function c!:pisub1))

(de c!:piplus2 (op r1 r2 r3) (progn (c!:printf 
"    %v = static_cast<LispObject>(static_cast<std::uintptr_t>(%v) +" r1 r2) (
c!:printf " static_cast<std::uintptr_t>(%v) - TAG_FIXNUM);\n" r3)))

(put (quote iplus2) (quote c!:opcode_printer) (function c!:piplus2))

(de c!:pidifference (op r1 r2 r3) (progn (c!:printf 
"    %v = static_cast<LispObject>(static_cast<std::uintptr_t>(%v) - static_cast<std::uintptr_t>(%v)"
r1 r2 r3) (c!:printf " + TAG_FIXNUM);\n")))

(put (quote idifference) (quote c!:opcode_printer) (function c!:pidifference)
)

(de c!:pitimes2 (op r1 r2 r3) (progn (c!:printf 
"    %v = fixnum_of_int(static_cast<std::intptr_t>(int_of_fixnum(%v) *" r1 r2
) (c!:printf " int_of_fixnum(%v)));\n" r3)))

(put (quote itimes2) (quote c!:opcode_printer) (function c!:pitimes2))

(de c!:pmodular_plus (op r1 r2 r3) (progn (c!:printf 
"    {   std::intptr_t w = int_of_fixnum(%v) + int_of_fixnum(%v);\n" r2 r3) (
c!:printf "        if (w >= current_modulus) w -= current_modulus;\n") (
c!:printf "        %v = fixnum_of_int(w);\n" r1) (c!:printf "    }\n")))

(put (quote modular!-plus) (quote c!:opcode_printer) (function 
c!:pmodular_plus))

(de c!:pmodular_difference (op r1 r2 r3) (progn (c!:printf 
"    {   std::intptr_t w = int_of_fixnum(%v) - int_of_fixnum(%v);\n" r2 r3) (
c!:printf "        if (w < 0) w += current_modulus;\n") (c!:printf 
"        %v = fixnum_of_int(w);\n" r1) (c!:printf "    }\n")))

(put (quote modular!-difference) (quote c!:opcode_printer) (function 
c!:pmodular_difference))

(de c!:pmodular_minus (op r1 r2 r3) (progn (c!:printf 
"    {   std::intptr_t w = int_of_fixnum(%v);\n" r3) (c!:printf 
"        if (w != 0) w = current_modulus - w;\n") (c!:printf 
"        %v = fixnum_of_int(w);\n" r1) (c!:printf "    }\n")))

(put (quote modular!-minus) (quote c!:opcode_printer) (function 
c!:pmodular_minus))

(de c!:passoc (op r1 r2 r3) (c!:printf "    %v = Lassoc(nil, %v, %v);\n" r1 
r2 r3))

(put (quote assoc) (quote c!:opcode_printer) (function c!:passoc))

(flag (quote (assoc)) (quote c!:uses_nil))

(de c!:patsoc (op r1 r2 r3) (c!:printf "    %v = Latsoc(nil, %v, %v);\n" r1 
r2 r3))

(put (quote atsoc) (quote c!:opcode_printer) (function c!:patsoc))

(flag (quote (atsoc)) (quote c!:uses_nil))

(de c!:pmember (op r1 r2 r3) (c!:printf "    %v = Lmember(nil, %v, %v);\n" r1
r2 r3))

(put (quote member) (quote c!:opcode_printer) (function c!:pmember))

(flag (quote (member)) (quote c!:uses_nil))

(de c!:pmemq (op r1 r2 r3) (c!:printf "    %v = Lmemq(nil, %v, %v);\n" r1 r2 
r3))

(put (quote memq) (quote c!:opcode_printer) (function c!:pmemq))

(flag (quote (memq)) (quote c!:uses_nil))

(de c!:pget (op r1 r2 r3) (c!:printf "    %v = get(%v, %v);\n" r1 r2 r3))

(put (quote get) (quote c!:opcode_printer) (function c!:pget))

(de c!:pqgetv (op r1 r2 r3) (progn (c!:printf 
"    %v = *reinterpret_cast<LispObject *>(reinterpret_cast<char *>(%v) + (CELL-TAG_VECTOR) +"
r1 r2) (c!:printf 
" (((static_cast<std::intptr_t<(%v)-TAG_FIXNUM)/(16/CELL)));\n" r3)))

(put (quote qgetv) (quote c!:opcode_printer) (function c!:pqgetv))

(de c!:pqputv (op r1 r2 r3) (progn (c!:printf 
"    *(LispObject *)((char *)%v + (CELL-TAG_VECTOR) +" r2) (c!:printf 
" ((static_cast<std::intptr_t>(%v)-TAG_FIXNUM)/(16/CELL))) = %v;\n" r3 r1)))

(put (quote qputv) (quote c!:opcode_printer) (function c!:pqputv))

(de c!:prplaca (op r1 r2 r3) (progn (c!:printf "#ifndef UNSAFE_CAR\n") (
c!:printf "    if (!car_legal(%v)) UNLIKELY return rplaca_fails(%v);\n" r2 r2
) (c!:printf "#endif\n") (c!:printf "    write_barrier(caraddr(%v), %v);\n" 
r2 r3)))

(put (quote rplaca) (quote c!:opcode_printer) (function c!:prplaca))

(de c!:prplacd (op r1 r2 r3) (progn (c!:printf "#ifndef UNSAFE_CAR\n") (
c!:printf "    if (!car_legal(%v)) UNLIKELY return rplacd_fails(%v);\n" r2 r2
) (c!:printf "#endif\n") (c!:printf "    write_barrier(cdraddr(%v), %v);\n" 
r2 r3)))

(put (quote rplacd) (quote c!:opcode_printer) (function c!:prplacd))

(de c!:peq (op r1 r2 r3) (c!:printf 
"    %v = (%v == %v ? lisp_true : nil);\n" r1 r2 r3))

(put (quote eq) (quote c!:opcode_printer) (function c!:peq))

(flag (quote (eq)) (quote c!:uses_nil))

(de c!:pequal (op r1 r2 r3) (c!:printf 
"    %v = (equal(%v, %v) ? lisp_true : nil);\n" r1 r2 r3 r2 r3))

(put (quote equal) (quote c!:opcode_printer) (function c!:pequal))

(flag (quote (equal)) (quote c!:uses_nil))

(de c!:pfluidbind (op r1 r2 r3) (prog nil (c!:printf "// Binding %a\n" r2) (
c!:printf "// FLUIDBIND: reloadenv=%a litvec-offset=%a saveloc=%a\n" 
reloadenv r3 (get r1 (quote c!:location))) (c!:printf 
"{   bind_fluid_stack bind_fluid_var(THREADARG %a, %a, %a);\n" (minus 
reloadenv) r3 (minus (get r1 (quote c!:location))))))

(put (quote fluidbind) (quote c!:opcode_printer) (function c!:pfluidbind))

(de c!:pfluidunbind (op r1 r2 r3) (prog nil (c!:printf 
"    ;}  // end of a binding scope\n")))

(put (quote fluidunbind) (quote c!:opcode_printer) (function c!:pfluidunbind)
)

(de c!:pcall (op r1 r2 r3) (prog (w boolfn) (cond ((setq w (get (car r3) (
quote c!:direct_entrypoint))) (progn (cond ((flagp (intern (cdr w)) (quote 
c!:noreturn)) (c!:printf "    %s(" (cdr w))) (t (c!:printf "    %v = %s(" r1 
(cdr w)))) (cond (r2 (progn (c!:printf "%v" (car r2)) (prog (var1269) (setq 
var1269 (cdr r2)) lab1268 (cond ((null var1269) (return nil))) (prog (a) (
setq a (car var1269)) (c!:printf ", %v" a)) (setq var1269 (cdr var1269)) (go 
lab1268))))) (c!:printf ");\n"))) (t (cond ((setq w (get (car r3) (quote 
c!:direct_predicate))) (progn (setq boolfn t) (c!:printf 
"    %v = static_cast<LispObject>(%s(" r1 (cdr w)) (cond (r2 (progn (
c!:printf "%v" (car r2)) (prog (var1271) (setq var1271 (cdr r2)) lab1270 (
cond ((null var1271) (return nil))) (prog (a) (setq a (car var1271)) (
c!:printf ", %v" a)) (setq var1271 (cdr var1271)) (go lab1270))))) (c!:printf
"));\n"))) (t (cond ((setq w (get (car r3) (quote c!:c_entrypoint))) (progn 
(cond ((flagp (intern w) (quote c!:noreturn)) (c!:printf "    %s(nil" w)) (t 
(c!:printf "    %v = %s(nil" r1 w))) (prog (var1273) (setq var1273 r2) 
lab1272 (cond ((null var1273) (return nil))) (prog (a) (setq a (car var1273))
(c!:printf ", %v" a)) (setq var1273 (cdr var1273)) (go lab1272)) (c!:printf 
");\n"))) (t (prog (nargs) (setq nargs (length r2)) (c!:printf 
"    {   LispObject fn = basic_elt(env, %s); %<// %c\n" (c!:find_literal (car
r3)) (car r3)) (cond ((equal nargs 0) (c!:printf 
"        %v = (*qfn0(fn))(fn" r1)) (t (cond ((equal nargs 1) (c!:printf 
"        %v = (*qfn1(fn))(fn" r1)) (t (cond ((equal nargs 2) (c!:printf 
"        %v = (*qfn2(fn))(fn" r1)) (t (cond ((equal nargs 3) (c!:printf 
"        %v = (*qfn3(fn))(fn" r1)) (t (c!:printf 
"        %v = (*qfn4up(fn))(fn" r1))))))))) (prog (var1275) (setq var1275 r2)
lab1274 (cond ((null var1275) (return nil))) (prog (a) (setq a (car var1275)
) (c!:printf ", %v" a)) (setq var1275 (cdr var1275)) (go lab1274)) (c!:printf
");\n    }\n")))))))) (cond ((not (flagp (car r3) (quote c!:no_errors))) (
c!:printf "    errexit();\n"))) (cond (boolfn (c!:printf 
"    %v = %v ? lisp_true : nil;\n" r1 r1)))))

(put (quote call) (quote c!:opcode_printer) (function c!:pcall))

(de c!:pgoto (lab) (prog nil (cond ((atom lab) (return (c!:printf 
"goto %s;\n" lab)))) (setq lab (get (car lab) (quote c!:chosen))) (c!:printf 
"return onevalue(%v);\n" lab)))

(de c!:pifnull (s) (c!:printf "%v == nil" (car s)))

(put (quote ifnull) (quote c!:exit_helper) (function c!:pifnull))

(de c!:pifatom (s) (c!:printf "!consp(%v)" (car s)))

(put (quote ifatom) (quote c!:exit_helper) (function c!:pifatom))

(de c!:pifsymbol (s) (c!:printf "symbolp(%v)" (car s)))

(put (quote ifsymbol) (quote c!:exit_helper) (function c!:pifsymbol))

(de c!:pifnumber (s) (c!:printf "is_number(%v)" (car s)))

(put (quote ifnumber) (quote c!:exit_helper) (function c!:pifnumber))

(de c!:pifizerop (s) (c!:printf "(%v) == 1" (car s)))

(put (quote ifizerop) (quote c!:exit_helper) (function c!:pifizerop))

(de c!:pifeq (s) (c!:printf "%v == %v" (car s) (cadr s)))

(put (quote ifeq) (quote c!:exit_helper) (function c!:pifeq))

(de c!:pifequal (s) (c!:printf "equal(%v, %v)" (car s) (cadr s) (car s) (cadr
s)))

(put (quote ifequal) (quote c!:exit_helper) (function c!:pifequal))

(de c!:pifilessp (s) (c!:printf 
"(static_cast<std::intptr_t>(%v) < static_cast<std::intptr_t>(%v))" (car s) (
cadr s)))

(put (quote ifilessp) (quote c!:exit_helper) (function c!:pifilessp))

(de c!:pifigreaterp (s) (c!:printf 
"(static_cast<std::intptr_t>(%v) > static_cast<std::intptr_t>(%v))" (car s) (
cadr s)))

(put (quote ifigreaterp) (quote c!:exit_helper) (function c!:pifigreaterp))

(de c!:flag_exit_label (why where_to next) (prog (helper) (cond ((equal why (
quote goto)) (progn (setq where_to (car where_to)) (cond ((equal where_to 
next) nil) (t (cond ((atom where_to) (flag (list where_to) (quote c!:visited)
))))) (return nil)))) (cond ((atom where_to) (return nil))) (cond ((atom (car
where_to)) (flag (list (car where_to)) (quote c!:visited)))) (cond ((null (
cdr where_to)) (return nil))) (cond ((and (neq (cadr where_to) next) (atom (
cadr where_to))) (flag (list (cadr where_to)) (quote c!:visited))))))

(de c!:display_flowgraph (s) (prog (why where_to s s1) (prog (b) (setq b (
reverse c!:all_blocks)) lab1276 (cond ((null b) (return nil))) (progn (setq s
(car b)) (cond ((cdr b) (setq s1 (cadr b))) (t (setq s1 nil))) (setq why (
get s (quote c!:why))) (setq where_to (get s (quote c!:where_to))) (
c!:flag_exit_label why where_to s1)) (setq b (cdr b)) (go lab1276)) (prog (b)
(setq b (reverse c!:all_blocks)) lab1279 (cond ((null b) (return nil))) (
progn (setq s (car b)) (cond ((cdr b) (setq s1 (cadr b))) (t (setq s1 nil))) 
(cond ((flagp s (quote c!:visited)) (c!:printf "%s:\n" s))) (prog (var1278) (
setq var1278 (reverse (get s (quote c!:contents)))) lab1277 (cond ((null 
var1278) (return nil))) (prog (k) (setq k (car var1278)) (c!:print_opcode k))
(setq var1278 (cdr var1278)) (go lab1277)) (setq why (get s (quote c!:why)))
(setq where_to (get s (quote c!:where_to))) (c!:print_exit_condition why 
where_to s1)) (setq b (cdr b)) (go lab1279))))

(fluid (quote (c!:startpoint)))

(de c!:branch_chain (s count) (prog (contents why where_to n) (cond ((not (
atom s)) (return s)) (t (cond ((flagp s (quote c!:visited)) (progn (setq n (
get s (quote c!:count))) (cond ((null n) (setq n 1)) (t (setq n (plus n 1))))
(put s (quote c!:count) n) (return s)))))) (flag (list s) (quote c!:visited)
) (setq contents (get s (quote c!:contents))) (setq why (get s (quote c!:why)
)) (setq where_to (prog (var1281 var1282) (setq var1281 (get s (quote 
c!:where_to))) lab1280 (cond ((null var1281) (return (reversip var1282)))) (
prog (z) (setq z (car var1281)) (setq var1282 (cons (c!:branch_chain z count)
var1282))) (setq var1281 (cdr var1281)) (go lab1280))) (prog nil lab1283 (
cond ((null (and contents (eqcar (car contents) (quote movr)) (equal why (
quote goto)) (not (atom (car where_to))) (equal (caar where_to) (cadr (car 
contents))))) (return nil))) (progn (setq where_to (list (list (cadddr (car 
contents))))) (setq contents (cdr contents))) (go lab1283)) (put s (quote 
c!:contents) contents) (put s (quote c!:where_to) where_to) (cond ((and (null
contents) (equal why (quote goto))) (progn (remflag (list s) (quote 
c!:visited)) (return (car where_to))))) (cond (count (progn (setq n (get s (
quote c!:count))) (cond ((null n) (setq n 1)) (t (setq n (plus n 1)))) (put s
(quote c!:count) n)))) (return s)))

(de c!:one_operand (op) (progn (flag (list op) (quote c!:set_r1)) (flag (list
op) (quote c!:read_r3)) (put op (quote c!:code) (function c!:builtin_one))))

(de c!:two_operands (op) (progn (flag (list op) (quote c!:set_r1)) (flag (
list op) (quote c!:read_r2)) (flag (list op) (quote c!:read_r3)) (put op (
quote c!:code) (function c!:builtin_two))))

(prog (var1285) (setq var1285 (quote (car cdr qcar qcdr null not atom numberp
fixp iminusp iminus iadd1 isub1 modular!-minus))) lab1284 (cond ((null 
var1285) (return nil))) (prog (n) (setq n (car var1285)) (c!:one_operand n)) 
(setq var1285 (cdr var1285)) (go lab1284))

(prog (var1287) (setq var1287 (quote (eq equal atsoc memq iplus2 idifference 
assoc member itimes2 ilessp igreaterp qgetv get modular!-plus 
modular!-difference))) lab1286 (cond ((null var1287) (return nil))) (prog (n)
(setq n (car var1287)) (c!:two_operands n)) (setq var1287 (cdr var1287)) (go
lab1286))

(flag (quote (movr movk movk1 ldrglob call reloadenv fluidbind fastget 
fastflag)) (quote c!:set_r1))

(flag (quote (strglob qputv fluidunbind)) (quote c!:read_r1))

(flag (quote (qputv fastget fastflag rplaca rplacd)) (quote c!:read_r2))

(flag (quote (movr qputv rplaca rplacd)) (quote c!:read_r3))

(flag (quote (ldrglob strglob nilglob movk call)) (quote c!:read_env))

(flag (quote (call qputv rplaca rplacd fluidbind fluidunbind)) (quote 
c!:side_effect))

(de c!:live_variable_analysis (c!:all_blocks) (prog (changed z) (prog nil 
lab1294 (progn (setq changed nil) (prog (var1293) (setq var1293 c!:all_blocks
) lab1292 (cond ((null var1293) (return nil))) (prog (b) (setq b (car var1293
)) (prog (w live) (prog (var1289) (setq var1289 (get b (quote c!:where_to))) 
lab1288 (cond ((null var1289) (return nil))) (prog (x) (setq x (car var1289))
(cond ((atom x) (setq live (union live (get x (quote c!:live))))) (t (setq 
live (union live x))))) (setq var1289 (cdr var1289)) (go lab1288)) (setq w (
get b (quote c!:why))) (cond ((not (atom w)) (progn (setq live (union live (
cdr w))) (cond ((and (eqcar (car w) (quote call)) (not (get (cadar w) (quote 
c!:direct_entrypoint))) (not (get (cadar w) (quote c!:c_entrypoint)))) (progn
(setq live (union (quote (env)) live)))))))) (prog (var1291) (setq var1291 (
get b (quote c!:contents))) lab1290 (cond ((null var1291) (return nil))) (
prog (s) (setq s (car var1291)) (prog (op r1 r2 r3) (setq op (car s)) (setq 
r1 (cadr s)) (setq r2 (caddr s)) (setq r3 (cadddr s)) (cond ((flagp op (quote
c!:set_r1)) (cond ((memq r1 live) (setq live (delete r1 live))) (t (cond ((
flagp op (quote c!:side_effect)) nil) (t (setq op (quote nop)))))))) (cond ((
flagp op (quote c!:read_r1)) (setq live (union live (list r1))))) (cond ((
flagp op (quote c!:read_r2)) (setq live (union live (list r2))))) (cond ((
flagp op (quote c!:read_r3)) (setq live (union live (list r3))))) (cond ((
equal op (quote call)) (progn (setq does_call t) (cond ((not (flagp (car r3) 
(quote c!:no_errors))) (flag live (quote c!:live_across_call)))) (setq live (
union live r2))))) (cond ((flagp op (quote c!:read_env)) (setq live (union 
live (quote (env)))))))) (setq var1291 (cdr var1291)) (go lab1290)) (setq 
live (sort live (function orderp))) (cond ((not (equal live (get b (quote 
c!:live)))) (progn (put b (quote c!:live) live) (setq changed t)))))) (setq 
var1293 (cdr var1293)) (go lab1292))) (cond ((null (not changed)) (go lab1294
)))) (setq z c!:registers) (setq c!:registers (setq c!:stacklocs nil)) (prog 
(var1296) (setq var1296 z) lab1295 (cond ((null var1296) (return nil))) (prog
 (r) (setq r (car var1296)) (cond ((flagp r (quote c!:live_across_call)) (
setq c!:stacklocs (cons r c!:stacklocs))) (t (setq c!:registers (cons r 
c!:registers))))) (setq var1296 (cdr var1296)) (go lab1295))))

(de c!:insert1 (a b) (cond ((memq a b) b) (t (cons a b))))

(de c!:clash (a b) (cond ((equal (flagp a (quote c!:live_across_call)) (flagp
b (quote c!:live_across_call))) (progn (put a (quote c!:clash) (c!:insert1 b
(get a (quote c!:clash)))) (put b (quote c!:clash) (c!:insert1 a (get b (
quote c!:clash))))))))

(de c!:build_clash_matrix (c!:all_blocks) (prog nil (prog (var1304) (setq 
var1304 c!:all_blocks) lab1303 (cond ((null var1304) (return nil))) (prog (b)
(setq b (car var1304)) (prog (live w) (prog (var1298) (setq var1298 (get b (
quote c!:where_to))) lab1297 (cond ((null var1298) (return nil))) (prog (x) (
setq x (car var1298)) (cond ((atom x) (setq live (union live (get x (quote 
c!:live))))) (t (setq live (union live x))))) (setq var1298 (cdr var1298)) (
go lab1297)) (setq w (get b (quote c!:why))) (cond ((not (atom w)) (progn (
setq live (union live (cdr w))) (cond ((and (eqcar (car w) (quote call)) (not
(get (cadar w) (quote c!:direct_entrypoint))) (not (get (cadar w) (quote 
c!:c_entrypoint)))) (setq live (union (quote (env)) live))))))) (prog (
var1302) (setq var1302 (get b (quote c!:contents))) lab1301 (cond ((null 
var1302) (return nil))) (prog (s) (setq s (car var1302)) (prog (op r1 r2 r3) 
(setq op (car s)) (setq r1 (cadr s)) (setq r2 (caddr s)) (setq r3 (cadddr s))
(cond ((or (equal op (quote reloadenv)) (equal op (quote fluidbind))) (setq 
reloadenv t))) (cond ((flagp op (quote c!:set_r1)) (cond ((memq r1 live) (
progn (setq live (delete r1 live)) (prog (var1300) (setq var1300 live) 
lab1299 (cond ((null var1300) (return nil))) (prog (v) (setq v (car var1300))
(c!:clash r1 v)) (setq var1300 (cdr var1300)) (go lab1299)))) (t (cond ((
flagp op (quote c!:side_effect)) nil) (t (progn (setq op (quote nop)) (rplacd
s (cons (car s) (cdr s))) (rplaca s op)))))))) (cond ((flagp op (quote 
c!:read_r1)) (setq live (union live (list r1))))) (cond ((flagp op (quote 
c!:read_r2)) (setq live (union live (list r2))))) (cond ((flagp op (quote 
c!:read_r3)) (setq live (union live (list r3))))) (cond ((equal op (quote 
call)) (setq live (union live r2)))) (cond ((flagp op (quote c!:read_env)) (
setq live (union live (quote (env)))))))) (setq var1302 (cdr var1302)) (go 
lab1301)))) (setq var1304 (cdr var1304)) (go lab1303)) (return nil)))

(de c!:allocate_registers (rl) (prog (schedule neighbours allocation) (setq 
neighbours 0) (prog nil lab1308 (cond ((null rl) (return nil))) (prog (w x) (
setq w rl) (prog nil lab1305 (cond ((null (and w (greaterp (length (setq x (
get (car w) (quote c!:clash)))) neighbours))) (return nil))) (setq w (cdr w))
(go lab1305)) (cond (w (progn (setq schedule (cons (car w) schedule)) (setq 
rl (deleq (car w) rl)) (prog (var1307) (setq var1307 x) lab1306 (cond ((null 
var1307) (return nil))) (prog (r) (setq r (car var1307)) (put r (quote 
c!:clash) (deleq (car w) (get r (quote c!:clash))))) (setq var1307 (cdr 
var1307)) (go lab1306)))) (t (setq neighbours (plus neighbours 1))))) (go 
lab1308)) (prog (var1312) (setq var1312 schedule) lab1311 (cond ((null 
var1312) (return nil))) (prog (r) (setq r (car var1312)) (prog (poss) (setq 
poss allocation) (prog (var1310) (setq var1310 (get r (quote c!:clash))) 
lab1309 (cond ((null var1310) (return nil))) (prog (x) (setq x (car var1310))
(setq poss (deleq (get x (quote c!:chosen)) poss))) (setq var1310 (cdr 
var1310)) (go lab1309)) (cond ((null poss) (progn (setq poss (c!:my_gensym)) 
(setq allocation (append allocation (list poss))))) (t (setq poss (car poss))
)) (put r (quote c!:chosen) poss))) (setq var1312 (cdr var1312)) (go lab1311)
) (return allocation)))

(de c!:remove_nops (c!:all_blocks) (prog (var1322) (setq var1322 
c!:all_blocks) lab1321 (cond ((null var1322) (return nil))) (prog (b) (setq b
(car var1322)) (prog (r) (prog (var1317) (setq var1317 (get b (quote 
c!:contents))) lab1316 (cond ((null var1317) (return nil))) (prog (s) (setq s
(car var1317)) (cond ((not (eqcar s (quote nop))) (prog (op r1 r2 r3) (setq 
op (car s)) (setq r1 (cadr s)) (setq r2 (caddr s)) (setq r3 (cadddr s)) (cond
((or (flagp op (quote c!:set_r1)) (flagp op (quote c!:read_r1))) (setq r1 (
get r1 (quote c!:chosen))))) (cond ((flagp op (quote c!:read_r2)) (setq r2 (
get r2 (quote c!:chosen))))) (cond ((flagp op (quote c!:read_r3)) (setq r3 (
get r3 (quote c!:chosen))))) (cond ((equal op (quote call)) (setq r2 (prog (
var1314 var1315) (setq var1314 r2) lab1313 (cond ((null var1314) (return (
reversip var1315)))) (prog (v) (setq v (car var1314)) (setq var1315 (cons (
get v (quote c!:chosen)) var1315))) (setq var1314 (cdr var1314)) (go lab1313)
)))) (cond ((not (and (equal op (quote movr)) (equal r1 r3))) (setq r (cons (
list op r1 r2 r3) r)))))))) (setq var1317 (cdr var1317)) (go lab1316)) (put b
(quote c!:contents) (reverse r)) (setq r (get b (quote c!:why))) (cond ((not
(atom r)) (put b (quote c!:why) (cons (car r) (prog (var1319 var1320) (setq 
var1319 (cdr r)) lab1318 (cond ((null var1319) (return (reversip var1320)))) 
(prog (v) (setq v (car var1319)) (setq var1320 (cons (get v (quote c!:chosen)
) var1320))) (setq var1319 (cdr var1319)) (go lab1318)))))))) (setq var1322 (
cdr var1322)) (go lab1321)))

(de c!:assign (u v c) (cond ((flagp u (quote fluid)) (cons (list (quote 
strglob) v u (c!:find_literal u)) c)) (t (cons (list (quote movr) u nil v) c)
)))

(de c!:insert_tailcall (b) (prog (why dest contents fcall res w) (setq why (
get b (quote c!:why))) (setq dest (get b (quote c!:where_to))) (setq contents
(get b (quote c!:contents))) (prog nil lab1323 (cond ((null (and contents (
not (eqcar (car contents) (quote call))))) (return nil))) (progn (setq w (
cons (car contents) w)) (setq contents (cdr contents))) (go lab1323)) (cond (
(null contents) (return nil))) (setq fcall (car contents)) (setq contents (
cdr contents)) (setq res (cadr fcall)) (prog nil lab1324 (cond ((null w) (
return nil))) (progn (cond ((eqcar (car w) (quote reloadenv)) (setq w (cdr w)
)) (t (cond ((and (eqcar (car w) (quote movr)) (equal (cadddr (car w)) res)) 
(progn (setq res (cadr (car w))) (setq w (cdr w)))) (t (setq res (setq w nil)
)))))) (go lab1324)) (cond ((null res) (return nil))) (cond ((c!:does_return 
res why dest) (cond ((and (equal (car (cadddr fcall)) c!:current_procedure) (
lessp (length c!:current_args) 4)) (progn (prog (var1326) (setq var1326 (pair
c!:current_args (caddr fcall))) lab1325 (cond ((null var1326) (return nil)))
(prog (p) (setq p (car var1326)) (setq contents (c!:assign (car p) (cdr p) 
contents))) (setq var1326 (cdr var1326)) (go lab1325)) (put b (quote 
c!:contents) contents) (put b (quote c!:why) (quote goto)) (put b (quote 
c!:where_to) (list restart_label)))) (t (progn (put b (quote c!:contents) 
contents) (put b (quote c!:why) (cons (list (quote call) (car (cadddr fcall))
) (caddr fcall))) (put b (quote c!:where_to) nil))))))))

(de c!:does_return (res why where_to) (cond ((not (equal why (quote goto))) 
nil) (t (cond ((not (atom (car where_to))) (equal res (caar where_to))) (t (
prog (contents) (setq where_to (car where_to)) (setq contents (reverse (get 
where_to (quote c!:contents)))) (setq why (get where_to (quote c!:why))) (
setq where_to (get where_to (quote c!:where_to))) (prog nil lab1327 (cond ((
null contents) (return nil))) (cond ((eqcar (car contents) (quote reloadenv))
(setq contents (cdr contents))) (t (cond ((and (eqcar (car contents) (quote 
movr)) (equal (cadddr (car contents)) res)) (progn (setq res (cadr (car 
contents))) (setq contents (cdr contents)))) (t (setq res (setq contents nil)
))))) (go lab1327)) (cond ((null res) (return nil)) (t (return (
c!:does_return res why where_to))))))))))

(de showblock (l) (prog nil (cond (!*noisy (progn (prin l) (printc ":") (prog
 (var1329) (setq var1329 (get l (quote c!:contents))) lab1328 (cond ((null 
var1329) (return nil))) (prog (i) (setq i (car var1329)) (progn (princ "  ") 
(print i))) (setq var1329 (cdr var1329)) (go lab1328)) (princ "  ") (prin (
get l (quote c!:why))) (princ " ") (print (get l (quote c!:where_to))))))))

(de showblocklist (l) (prog (var1331) (setq var1331 l) lab1330 (cond ((null 
var1331) (return nil))) (prog (q) (setq q (car var1331)) (showblock q)) (setq
var1331 (cdr var1331)) (go lab1330)))

(de c!:flatten (b) (prog (w r inner) (showblocklist b) (prog nil lab1334 (
cond ((null b) (return nil))) (progn (cond ((equal (get (car b) (quote c!:why
)) (quote inner_block)) (progn (setq inner (get (car b) (quote c!:where_to)))
(cond (!*noisy (progn (printc "This is an inner block") (showblocklist inner
)))) (setq w (c!:flatten inner)) (cond (!*noisy (progn (printc 
"Inner block flattened") (showblocklist w)))) (put (car b) (quote c!:why) (
quote goto)) (put (car b) (quote c!:where_to) (list (car inner))) (setq r (
cons (car b) r)) (prog (var1333) (setq var1333 (reverse w)) lab1332 (cond ((
null var1333) (return nil))) (prog (x) (setq x (car var1333)) (setq r (cons x
r))) (setq var1333 (cdr var1333)) (go lab1332)))) (t (setq r (cons (car b) r
)))) (setq b (cdr b))) (go lab1334)) (cond (!*noisy (progn (printc 
"Whole block flattened") (showblocklist (reverse r))))) (return r)))

(de c!:optimise_flowgraph (c!:startpoint c!:all_blocks env argch args varargs
) (prog (w n locs stacks) (printc "#if 0 // Start of trace output") (setq 
c!:all_blocks (c!:flatten (reverse c!:all_blocks))) (prog (var1336) (setq 
var1336 c!:all_blocks) lab1335 (cond ((null var1336) (return nil))) (prog (b)
(setq b (car var1336)) (c!:insert_tailcall b)) (setq var1336 (cdr var1336)) 
(go lab1335)) (cond (!*noisy (progn (printc "now do live variable stuff") (
showblocklist c!:all_blocks)))) (c!:live_variable_analysis c!:all_blocks) (
cond (!*noisy (progn (printc "now build clash list") (princ "reloadenv = ") (
print reloadenv) (showblocklist c!:all_blocks)))) (c!:build_clash_matrix 
c!:all_blocks) (cond (!*noisy (progn (princ "reloadenv = ") (print reloadenv)
))) (prog (var1340) (setq var1340 env) lab1339 (cond ((null var1340) (return 
nil))) (prog (u) (setq u (car var1340)) (prog (var1338) (setq var1338 env) 
lab1337 (cond ((null var1338) (return nil))) (prog (v) (setq v (car var1338))
(c!:clash (cdr u) (cdr v))) (setq var1338 (cdr var1338)) (go lab1337))) (
setq var1340 (cdr var1340)) (go lab1339)) (setq locs (c!:allocate_registers 
c!:registers)) (setq stacks (c!:allocate_registers c!:stacklocs)) (flag 
stacks (quote c!:live_across_call)) (cond (!*noisy (progn (printc 
"before remove nops") (showblocklist c!:all_blocks)))) (c!:remove_nops 
c!:all_blocks) (cond (!*noisy (progn (printc "after remove nops") (
showblocklist c!:all_blocks)))) (printc "#endif // End of trace output") (
cond (locs (progn (c!:printf "    UNUSED_NAME LispObject %s" (car locs)) (
prog (var1342) (setq var1342 (cdr locs)) lab1341 (cond ((null var1342) (
return nil))) (prog (v) (setq v (car var1342)) (c!:printf ", %s" v)) (setq 
var1342 (cdr var1342)) (go lab1341)) (c!:printf ";\n")))) (c!:printf 
"    THREADID;\n") (cond ((or stacks reloadenv) (c!:printf 
"    stack_restorer stack_restorer_var OPTTHREAD;\n"))) (cond ((and varargs 
args) (progn (setq w " ") (c!:printf "    LispObject") (prog (var1344) (setq 
var1344 (cdddr args)) lab1343 (cond ((null var1344) (return nil))) (prog (v) 
(setq v (car var1344)) (progn (c!:printf "%s%s" w v) (setq w ", "))) (setq 
var1344 (cdr var1344)) (go lab1343)) (c!:printf ";\n") (prog (var1346) (setq 
var1346 (cdddr args)) lab1345 (cond ((null var1346) (return nil))) (prog (v) 
(setq v (car var1346)) (progn (c!:printf 
"    if (_a4up_ == nil)\n        aerror1(\qnot enough arguments provided\q, basic_elt(env, 0));\n"
) (c!:printf "    %s = car(_a4up_); _a4up_ = cdr(_a4up_);\n" v))) (setq 
var1346 (cdr var1346)) (go lab1345)) (c!:printf 
"    if (_a4up_ != nil)\n        aerror1(\qtoo many arguments provided\q, basic_elt(env, 0));\n"
)))) (c!:printf "#ifdef CHECK_STACK\n") (c!:printf "    if_check_stack;\n") (
c!:printf "#endif\n") (cond (does_call (progn (c!:printf 
"#ifdef CONSERVATIVE\n") (c!:printf "    poll();\n") (c!:printf 
"#else // CONSERVATIVE\n") (c!:printf 
"    if (++reclaim_trigger_count == reclaim_trigger_target ||\n") (c!:printf 
"        reinterpret_cast<uintptr_t>(stack) >= stackLimit)\n") (c!:printf 
"    {   Save saveArgs(THREADARG env") (cond ((not (null args)) (progn (
c!:printf ", %s" (car args)) (setq w (cdr args)) (cond ((not (null w)) (progn
(c!:printf ", %s" (car w)) (setq w (cdr w)) (cond ((not (null w)) (progn (
c!:printf ", %s" (car w)) (setq w (cdr w)) (cond ((not (null w)) (c!:printf 
", _a4up_")))))))))))) (c!:printf ");\n") (c!:printf 
"        env = reclaim(env, \qstack\q, GC_STACK, 0);\n") (c!:printf 
"        errexit();\n") (c!:printf "        saveArgs.restore(env") (cond ((
not (null args)) (progn (c!:printf ", %s" (car args)) (setq w (cdr args)) (
cond ((not (null w)) (progn (c!:printf ", %s" (car w)) (setq w (cdr w)) (cond
((not (null w)) (progn (c!:printf ", %s" (car w)) (setq w (cdr w)) (cond ((
not (null w)) (c!:printf ", _a4up_")))))))))))) (c!:printf ");\n    }\n") (
c!:printf "#endif // CONSERVATIVE\n")))) (setq n 0) (cond (stacks (progn (
c!:printf "%<// space for vars preserved across procedure calls\n") (prog (
var1348) (setq var1348 stacks) lab1347 (cond ((null var1348) (return nil))) (
prog (v) (setq v (car var1348)) (progn (put v (quote c!:location) n) (setq n 
(plus n 1)))) (setq var1348 (cdr var1348)) (go lab1347))))) (cond (reloadenv 
(progn (setq reloadenv n) (cond ((equal n 0) (c!:printf 
"    RealSave saveEnv(THREADARG env);\n")) (t (c!:printf 
"    RealSave saveEnv(THREADARG env, PushCount(%a));\n" n))))) (t (cond ((neq
n 0) (c!:printf "    RealSave Workspace(THREADARG PushCount(%a));\n" n))))) 
(cond (env (c!:printf "%<// copy arguments values to proper place\n"))) (prog
 (var1350) (setq var1350 env) lab1349 (cond ((null var1350) (return nil))) (
prog (v) (setq v (car var1350)) (cond ((flagp (cdr v) (quote 
c!:live_across_call)) (c!:printf "    stack[%s] = %s;\n" (minus (get (get (
cdr v) (quote c!:chosen)) (quote c!:location))) (cdr v))) (t (c!:printf 
"    %s = %s;\n" (get (cdr v) (quote c!:chosen)) (cdr v))))) (setq var1350 (
cdr var1350)) (go lab1349)) (c!:printf "%<// end of prologue\n") (
c!:display_flowgraph c!:startpoint) (remflag c!:all_blocks (quote c!:visited)
)))

(de c!:cand (u env) (prog (w r) (setq w (reverse (cdr u))) (cond ((null w) (
return (c!:cval nil env)))) (setq r (list (list (quote t) (car w)))) (setq w 
(cdr w)) (prog (var1352) (setq var1352 w) lab1351 (cond ((null var1352) (
return nil))) (prog (z) (setq z (car var1352)) (setq r (cons (list (list (
quote null) z) nil) r))) (setq var1352 (cdr var1352)) (go lab1351)) (setq r (
cons (quote cond) r)) (return (c!:cval r env))))

(put (quote and) (quote c!:code) (function c!:cand))

(de c!:ccatch (u env) (error 0 "catch"))

(put (quote catch) (quote c!:code) (function c!:ccatch))

(de c!:ccompile_let (u env) (error 0 "compiler-let"))

(put (quote compiler!-let) (quote c!:code) (function c!:ccompiler_let))

(de c!:ccond (u env) (prog (v join) (setq v (c!:newreg)) (setq join (
c!:my_gensym)) (prog (var1354) (setq var1354 (cdr u)) lab1353 (cond ((null 
var1354) (return nil))) (prog (c) (setq c (car var1354)) (prog (l1 l2) (setq 
l1 (c!:my_gensym)) (setq l2 (c!:my_gensym)) (cond ((atom (cdr c)) (progn (
c!:outop (quote movr) v nil (c!:cval (car c) env)) (c!:endblock (list (quote 
ifnull) v) (list l2 join)))) (t (progn (c!:cjumpif (car c) env l1 l2) (
c!:startblock l1) (c!:outop (quote movr) v nil (c!:cval (cons (quote progn) (
cdr c)) env)) (c!:endblock (quote goto) (list join))))) (c!:startblock l2))) 
(setq var1354 (cdr var1354)) (go lab1353)) (c!:outop (quote movk1) v nil nil)
(c!:endblock (quote goto) (list join)) (c!:startblock join) (return v)))

(put (quote cond) (quote c!:code) (function c!:ccond))

(de c!:valid_cond (x) (cond ((null x) t) (t (cond ((not (c!:valid_list (car x
))) nil) (t (c!:valid_cond (cdr x)))))))

(put (quote cond) (quote c!:valid) (function c!:valid_cond))

(de c!:cdeclare (u env) (error 0 "declare"))

(put (quote declare) (quote c!:code) (function c!:cdeclare))

(de c!:cde (u env) (error 0 "de"))

(put (quote de) (quote c!:code) (function c!:cde))

(de c!:cdefun (u env) (error 0 "defun"))

(put (quote !~defun) (quote c!:code) (function c!:cdefun))

(de c!:ceval_when (u env) (error 0 "eval-when"))

(put (quote eval!-when) (quote c!:code) (function c!:ceval_when))

(de c!:cflet (u env) (error 0 "flet"))

(put (quote flet) (quote c!:code) (function c!:cflet))

(de c!:cfunction (u env) (prog (v) (setq u (cadr u)) (cond ((not (atom u)) (
progn (cond ((not (eqcar u (quote lambda))) (error 0 (list 
"lambda expression needed" u)))) (setq v (hashtagged!-name (quote lambda) u))
(setq pending_functions (cons (cons (quote de) (cons v (cdr u))) 
pending_functions)) (setq u v)))) (setq v (c!:newreg)) (c!:outop (quote movk)
v u (c!:find_literal u)) (return v)))

(de c!:valid_function (x) (cond ((atom x) nil) (t (cond ((not (null (cdr x)))
nil) (t (cond ((idp (car x)) t) (t (cond ((atom (car x)) nil) (t (cond ((not
(eqcar (car x) (quote lambda))) nil) (t (cond ((atom (cdar x)) nil) (t (
c!:valid_fndef (cadar x) (cddar x)))))))))))))))

(put (quote function) (quote c!:code) (function c!:cfunction))

(put (quote function) (quote c!:valid) (function c!:valid_function))

(de c!:cgo (u env) (prog (w w1) (setq w1 proglabs) (prog nil lab1355 (cond ((
null (and (null w) w1)) (return nil))) (progn (setq w (assoc!*!* (cadr u) (
car w1))) (setq w1 (cdr w1))) (go lab1355)) (cond ((null w) (error 0 (list u 
"label not set")))) (c!:endblock (quote goto) (list (cadr w))) (return nil)))

(put (quote go) (quote c!:code) (function c!:cgo))

(put (quote go) (quote c!:valid) (function c!:valid_quote))

(de c!:cif (u env) (prog (v join l1 l2 w) (setq v (c!:newreg)) (setq join (
c!:my_gensym)) (setq l1 (c!:my_gensym)) (setq l2 (c!:my_gensym)) (c!:cjumpif 
(car (setq u (cdr u))) env l1 l2) (c!:startblock l1) (c!:outop (quote movr) v
nil (c!:cval (car (setq u (cdr u))) env)) (c!:endblock (quote goto) (list 
join)) (c!:startblock l2) (setq u (cdr u)) (cond (u (setq u (car u)))) (
c!:outop (quote movr) v nil (c!:cval u env)) (c!:endblock (quote goto) (list 
join)) (c!:startblock join) (return v)))

(put (quote if) (quote c!:code) (function c!:cif))

(de c!:clabels (u env) (error 0 "labels"))

(put (quote labels) (quote c!:code) (function c!:clabels))

(de c!:expand!-let (vl b) (cond ((null vl) (cons (quote progn) b)) (t (cond (
(null (cdr vl)) (c!:expand!-let!* vl b)) (t (prog (vars vals) (prog (var1357)
(setq var1357 vl) lab1356 (cond ((null var1357) (return nil))) (prog (v) (
setq v (car var1357)) (cond ((atom v) (progn (setq vars (cons v vars)) (setq 
vals (cons nil vals)))) (t (cond ((atom (cdr v)) (progn (setq vars (cons (car
v) vars)) (setq vals (cons nil vals)))) (t (progn (setq vars (cons (car v) 
vars)) (setq vals (cons (cadr v) vals)))))))) (setq var1357 (cdr var1357)) (
go lab1356)) (return (cons (cons (quote lambda) (cons vars b)) vals))))))))

(de c!:clet (x env) (c!:cval (c!:expand!-let (cadr x) (cddr x)) env))

(de c!:valid_let (x) (cond ((null x) t) (t (cond ((not (c!:valid_cond (car x)
)) nil) (t (c!:valid_list (cdr x)))))))

(put (quote !~let) (quote c!:code) (function c!:clet))

(put (quote !~let) (quote c!:valid) (function c!:valid_let))

(de c!:expand!-let!* (vl b) (cond ((null vl) (cons (quote progn) b)) (t (prog
 (var val) (setq var (car vl)) (cond ((not (atom var)) (progn (setq val (cdr 
var)) (setq var (car var)) (cond ((not (atom val)) (setq val (car val))))))) 
(setq b (list (list (quote return) (c!:expand!-let!* (cdr vl) b)))) (cond (
val (setq b (cons (list (quote setq) var val) b)))) (return (cons (quote prog
) (cons (list var) b)))))))

(de c!:clet!* (x env) (c!:cval (c!:expand!-let!* (cadr x) (cddr x)) env))

(put (quote let!*) (quote c!:code) (function c!:clet!*))

(put (quote let!*) (quote c!:valid) (function c!:valid_let))

(de c!:clist (u env) (cond ((null (cdr u)) (c!:cval nil env)) (t (cond ((null
(cddr u)) (c!:cval (cons (quote ncons) (cdr u)) env)) (t (cond ((eqcar (cadr
u) (quote cons)) (c!:cval (list (quote acons) (cadr (cadr u)) (caddr (cadr u
)) (cons (quote list) (cddr u))) env)) (t (cond ((null (cdddr u)) (c!:cval (
cons (quote list2) (cdr u)) env)) (t (cond ((null (cddddr u)) (c!:cval (cons 
(quote list3) (cdr u)) env)) (t (cond ((null (cdr (cddddr u))) (c!:cval (cons
(quote list4) (cdr u)) env)) (t (c!:cval (list (quote list3!*) (cadr u) (
caddr u) (cadddr u) (cons (quote list) (cddddr u))) env))))))))))))))

(put (quote list) (quote c!:code) (function c!:clist))

(de c!:clist!* (u env) (prog (v) (setq u (reverse (cdr u))) (setq v (car u)) 
(prog (var1359) (setq var1359 (cdr u)) lab1358 (cond ((null var1359) (return 
nil))) (prog (a) (setq a (car var1359)) (setq v (list (quote cons) a v))) (
setq var1359 (cdr var1359)) (go lab1358)) (return (c!:cval v env))))

(put (quote list!*) (quote c!:code) (function c!:clist!*))

(de c!:ccons (u env) (prog (a1 a2) (setq a1 (s!:improve (cadr u))) (setq a2 (
s!:improve (caddr u))) (cond ((or (equal a2 nil) (equal a2 (quote (quote nil)
)) (equal a2 (quote (list)))) (return (c!:cval (list (quote ncons) a1) env)))
) (cond ((eqcar a1 (quote cons)) (return (c!:cval (list (quote acons) (cadr 
a1) (caddr a1) a2) env)))) (cond ((eqcar a2 (quote cons)) (return (c!:cval (
list (quote list2!*) a1 (cadr a2) (caddr a2)) env)))) (cond ((eqcar a2 (quote
list)) (return (c!:cval (list (quote cons) a1 (list (quote cons) (cadr a2) (
cons (quote list) (cddr a2)))) env)))) (return (c!:ccall (car u) (cdr u) env)
)))

(put (quote cons) (quote c!:code) (function c!:ccons))

(de c!:cget (u env) (prog (a1 a2 w r r1) (setq a1 (s!:improve (cadr u))) (
setq a2 (s!:improve (caddr u))) (cond ((and (eqcar a2 (quote quote)) (idp (
setq w (cadr a2))) (setq w (symbol!-make!-fastget w nil))) (progn (setq r (
c!:newreg)) (c!:outop (quote fastget) r (c!:cval a1 env) (cons w (cadr a2))) 
(return r))) (t (return (c!:ccall (car u) (cdr u) env))))))

(put (quote get) (quote c!:code) (function c!:cget))

(de c!:cflag (u env) (prog (a1 a2 w r r1) (setq a1 (s!:improve (cadr u))) (
setq a2 (s!:improve (caddr u))) (cond ((and (eqcar a2 (quote quote)) (idp (
setq w (cadr a2))) (setq w (symbol!-make!-fastget w nil))) (progn (setq r (
c!:newreg)) (c!:outop (quote fastflag) r (c!:cval a1 env) (cons w (cadr a2)))
(return r))) (t (return (c!:ccall (car u) (cdr u) env))))))

(put (quote flagp) (quote c!:code) (function c!:cflag))

(de c!:cgetv (u env) (cond ((not !*fastvector) (c!:ccall (car u) (cdr u) env)
) (t (c!:cval (cons (quote qgetv) (cdr u)) env))))

(put (quote getv) (quote c!:code) (function c!:cgetv))

(de c!:cputv (u env) (cond ((not !*fastvector) (c!:ccall (car u) (cdr u) env)
) (t (c!:cval (cons (quote qputv) (cdr u)) env))))

(put (quote putv) (quote c!:code) (function c!:cputv))

(de c!:cqputv (x env) (prog (rr) (setq rr (c!:evalargs (cdr x) env)) (
c!:outop (quote qputv) (caddr rr) (car rr) (cadr rr)) (return (caddr rr))))

(put (quote qputv) (quote c!:code) (function c!:cqputv))

(de c!:cmacrolet (u env) (error 0 "macrolet"))

(put (quote macrolet) (quote c!:code) (function c!:cmacrolet))

(de c!:cmultiple_value_call (u env) (error 0 "multiple_value_call"))

(put (quote multiple!-value!-call) (quote c!:code) (function 
c!:cmultiple_value_call))

(de c!:cmultiple_value_prog1 (u env) (error 0 "multiple_value_prog1"))

(put (quote multiple!-value!-prog1) (quote c!:code) (function 
c!:cmultiple_value_prog1))

(de c!:cor (u env) (prog (next done v r) (setq v (c!:newreg)) (setq done (
c!:my_gensym)) (setq u (cdr u)) (prog nil lab1360 (cond ((null (cdr u)) (
return nil))) (progn (setq next (c!:my_gensym)) (c!:outop (quote movr) v nil 
(c!:cval (car u) env)) (setq u (cdr u)) (c!:endblock (list (quote ifnull) v) 
(list next done)) (c!:startblock next)) (go lab1360)) (c!:outop (quote movr) 
v nil (c!:cval (car u) env)) (c!:endblock (quote goto) (list done)) (
c!:startblock done) (return v)))

(put (quote or) (quote c!:code) (function c!:cor))

(de c!:cprog (u env) (prog (w w1 bvl local_proglabs progret progexit fluids 
env1 body decs) (setq env1 (car env)) (setq bvl (cadr u)) (setq w (
s!:find_local_decs (cddr u) t)) (setq body (cdr w)) (setq localdecs (cons (
car w) localdecs)) (prog (var1362) (setq var1362 bvl) lab1361 (cond ((null 
var1362) (return nil))) (prog (v) (setq v (car var1362)) (progn (cond ((and (
not (globalp v)) (not (fluidp v)) (c!:local_fluidp v localdecs)) (progn (
make!-special v) (setq decs (cons v decs))))))) (setq var1362 (cdr var1362)) 
(go lab1361)) (prog (var1364) (setq var1364 bvl) lab1363 (cond ((null var1364
) (return nil))) (prog (v) (setq v (car var1364)) (progn (cond ((globalp v) (
prog (oo) (setq oo (wrs nil)) (princ "+++++ ") (prin v) (princ 
" converted from GLOBAL to FLUID") (terpri) (wrs oo) (unglobal (list v)) (
fluid (list v))))) (cond ((fluidp v) (progn (setq fluids (cons (cons v (
c!:newreg)) fluids)) (flag (list (cdar fluids)) (quote c!:live_across_call)) 
(setq env1 (cons (cons (quote c!:dummy!:name) (cdar fluids)) env1)) (
c!:start_nested_context) (c!:outop (quote fluidbind) (cdar fluids) v (
c!:find_literal v)) (cond ((eqcar u (quote prog)) (c!:outop (quote nilglob) 
nil v (c!:find_literal v)))))) (t (progn (setq env1 (cons (cons v (c!:newreg)
) env1)) (c!:outop (quote movk1) (cdar env1) nil nil)))))) (setq var1364 (cdr
var1364)) (go lab1363)) (setq env (cons env1 (append fluids (cdr env)))) (
setq u body) (setq progret (c!:newreg)) (setq progexit (c!:my_gensym)) (setq 
blockstack (cons (cons nil (cons progret progexit)) blockstack)) (prog (
var1366) (setq var1366 u) lab1365 (cond ((null var1366) (return nil))) (prog 
(a) (setq a (car var1366)) (cond ((atom a) (cond ((atsoc a local_proglabs) (
progn (cond ((not (null a)) (progn (setq w (wrs nil)) (princ 
"+++++ multiply defined label: ") (prin a) (terpri) (wrs w)))))) (t (setq 
local_proglabs (cons (list a (c!:my_gensym)) local_proglabs))))))) (setq 
var1366 (cdr var1366)) (go lab1365)) (setq proglabs (cons local_proglabs 
proglabs)) (prog (var1368) (setq var1368 u) lab1367 (cond ((null var1368) (
return nil))) (prog (a) (setq a (car var1368)) (cond ((atom a) (progn (setq w
(cdr (assoc!*!* a local_proglabs))) (cond ((null (cdr w)) (progn (rplacd w t
) (c!:endblock (quote goto) (list (car w))) (c!:startblock (car w))))))) (t (
c!:cval a env)))) (setq var1368 (cdr var1368)) (go lab1367)) (c!:outop (quote
movk1) progret nil nil) (c!:endblock (quote goto) (list progexit)) (
c!:startblock progexit) (prog (var1370) (setq var1370 fluids) lab1369 (cond (
(null var1370) (return nil))) (prog (v) (setq v (car var1370)) (progn (
c!:end_nested_context) (c!:outop (quote fluidunbind) (cdr v) (car v) (
c!:find_literal (car v))))) (setq var1370 (cdr var1370)) (go lab1369)) (setq 
blockstack (cdr blockstack)) (setq proglabs (cdr proglabs)) (unfluid decs) (
setq localdecs (cdr localdecs)) (return progret)))

(put (quote prog) (quote c!:code) (function c!:cprog))

(put (quote !~prog) (quote c!:code) (function c!:cprog))

(de c!:valid_prog (x) (c!:valid_list (cdr x)))

(put (quote prog) (quote c!:valid) (function c!:valid_prog))

(put (quote !~prog) (quote c!:valid) (function c!:valid_prog))

(de c!:cprog!* (u env) (error 0 "prog*"))

(put (quote prog!*) (quote c!:code) (function c!:cprog!*))

(de c!:cprog1 (u env) (prog (g) (setq g (c!:my_gensym)) (setq g (list (quote 
prog) (list g) (list (quote setq) g (cadr u)) (cons (quote progn) (cddr u)) (
list (quote return) g))) (return (c!:cval g env))))

(put (quote prog1) (quote c!:code) (function c!:cprog1))

(de c!:cprog2 (u env) (prog (g) (setq u (cdr u)) (setq g (c!:my_gensym)) (
setq g (list (quote prog) (list g) (list (quote setq) g (cadr u)) (cons (
quote progn) (cddr u)) (list (quote return) g))) (setq g (list (quote progn) 
(car u) g)) (return (c!:cval g env))))

(put (quote prog2) (quote c!:code) (function c!:cprog2))

(de c!:cprogn (u env) (prog (r) (setq u (cdr u)) (cond ((equal u nil) (setq u
(quote (nil))))) (prog (var1372) (setq var1372 u) lab1371 (cond ((null 
var1372) (return nil))) (prog (s) (setq s (car var1372)) (setq r (c!:cval s 
env))) (setq var1372 (cdr var1372)) (go lab1371)) (return r)))

(put (quote progn) (quote c!:code) (function c!:cprogn))

(de c!:cprogv (u env) (error 0 "progv"))

(put (quote progv) (quote c!:code) (function c!:cprogv))

(de c!:cquote (u env) (prog (v) (setq u (cadr u)) (setq v (c!:newreg)) (cond 
((or (null u) (equal u (quote t)) (c!:small_number u)) (c!:outop (quote movk1
) v nil u)) (t (c!:outop (quote movk) v u (c!:find_literal u)))) (return v)))

(de c!:valid_quote (x) t)

(put (quote quote) (quote c!:code) (function c!:cquote))

(put (quote quote) (quote c!:valid) (function c!:valid_quote))

(de c!:creturn (u env) (prog (w) (setq w (assoc!*!* nil blockstack)) (cond ((
null w) (error 0 "RETURN out of context"))) (c!:outop (quote movr) (cadr w) 
nil (c!:cval (cadr u) env)) (c!:endblock (quote goto) (list (cddr w))) (
return nil)))

(put (quote return) (quote c!:code) (function c!:creturn))

(put (quote return!-from) (quote c!:code) (function c!:creturn_from))

(de c!:csetq (u env) (prog (v w) (setq v (c!:cval (caddr u) env)) (setq u (
cadr u)) (cond ((not (idp u)) (error 0 (list u "bad variable in setq"))) (t (
cond ((setq w (c!:locally_bound u env)) (c!:outop (quote movr) (cdr w) nil v)
) (t (cond ((flagp u (quote c!:constant)) (error 0 (list u 
"attempt to use setq on a constant"))) (t (c!:outop (quote strglob) v u (
c!:find_literal u)))))))) (return v)))

(put (quote setq) (quote c!:code) (function c!:csetq))

(put (quote noisy!-setq) (quote c!:code) (function c!:csetq))

(de c!:cprivate_tagbody (u env) (prog nil (setq u (cdr u)) (c!:endblock (
quote goto) (list (car u))) (c!:startblock (car u)) (setq c!:current_args (
prog (var1374 var1375) (setq var1374 c!:current_args) lab1373 (cond ((null 
var1374) (return (reversip var1375)))) (prog (v) (setq v (car var1374)) (setq
var1375 (cons (prog (z) (setq z (assoc!*!* v (car env))) (return (cond (z (
cdr z)) (t v)))) var1375))) (setq var1374 (cdr var1374)) (go lab1373))) (
return (c!:cval (cadr u) env))))

(put (quote c!:private_tagbody) (quote c!:code) (function c!:cprivate_tagbody
))

(de c!:cthe (u env) (c!:cval (caddr u) env))

(put (quote the) (quote c!:code) (function c!:cthe))

(de c!:cunless (u env) (prog (v join l1 l2) (setq v (c!:newreg)) (setq join (
c!:my_gensym)) (setq l1 (c!:my_gensym)) (setq l2 (c!:my_gensym)) (c!:cjumpif 
(cadr u) env l2 l1) (c!:startblock l1) (c!:outop (quote movr) v nil (c!:cval 
(cons (quote progn) (cddr u)) env)) (c!:endblock (quote goto) (list join)) (
c!:startblock l2) (c!:outop (quote movk1) v nil nil) (c!:endblock (quote goto
) (list join)) (c!:startblock join) (return v)))

(put (quote unless) (quote c!:code) (function c!:cunless))

(de c!:cunwind_protect (u env) (error 0 "unwind_protect"))

(put (quote unwind!-protect) (quote c!:code) (function c!:cunwind_protect))

(de c!:cwhen (u env) (prog (v join l1 l2) (setq v (c!:newreg)) (setq join (
c!:my_gensym)) (setq l1 (c!:my_gensym)) (setq l2 (c!:my_gensym)) (c!:cjumpif 
(cadr u) env l1 l2) (c!:startblock l1) (c!:outop (quote movr) v nil (c!:cval 
(cons (quote progn) (cddr u)) env)) (c!:endblock (quote goto) (list join)) (
c!:startblock l2) (c!:outop (quote movk1) v nil nil) (c!:endblock (quote goto
) (list join)) (c!:startblock join) (return v)))

(put (quote when) (quote c!:code) (function c!:cwhen))

(de c!:expand_map (fnargs) (prog (carp fn fn1 args var avar moveon l1 r s 
closed) (setq fn (car fnargs)) (cond ((or (equal fn (quote mapc)) (equal fn (
quote mapcar)) (equal fn (quote mapcan))) (setq carp t))) (setq fnargs (cdr 
fnargs)) (cond ((atom fnargs) (error 0 "bad arguments to map function"))) (
setq fn1 (cadr fnargs)) (prog nil lab1376 (cond ((null (or (eqcar fn1 (quote 
function)) (and (eqcar fn1 (quote quote)) (eqcar (cadr fn1) (quote lambda))))
) (return nil))) (progn (setq fn1 (cadr fn1)) (setq closed t)) (go lab1376)) 
(setq args (car fnargs)) (setq l1 (c!:my_gensym)) (setq r (c!:my_gensym)) (
setq s (c!:my_gensym)) (setq var (c!:my_gensym)) (setq avar var) (cond (carp 
(setq avar (list (quote car) avar)))) (cond (closed (setq fn1 (list fn1 avar)
)) (t (setq fn1 (list (quote apply1) fn1 avar)))) (setq moveon (list (quote 
setq) var (list (quote cdr) var))) (cond ((or (equal fn (quote map)) (equal 
fn (quote mapc))) (setq fn (sublis (list (cons (quote l1) l1) (cons (quote 
var) var) (cons (quote fn) fn1) (cons (quote args) args) (cons (quote moveon)
moveon)) (quote (prog (var) (setq var args) l1 (cond ((not var) (return nil)
)) fn moveon (go l1)))))) (t (cond ((or (equal fn (quote maplist)) (equal fn 
(quote mapcar))) (setq fn (sublis (list (cons (quote l1) l1) (cons (quote var
) var) (cons (quote fn) fn1) (cons (quote args) args) (cons (quote moveon) 
moveon) (cons (quote r) r)) (quote (prog (var r) (setq var args) l1 (cond ((
not var) (return (reversip r)))) (setq r (cons fn r)) moveon (go l1)))))) (t 
(setq fn (sublis (list (cons (quote l1) l1) (cons (quote l2) (c!:my_gensym)) 
(cons (quote var) var) (cons (quote fn) fn1) (cons (quote args) args) (cons (
quote moveon) moveon) (cons (quote r) (c!:my_gensym)) (cons (quote s) (
c!:my_gensym))) (quote (prog (var r s) (setq var args) (setq r (setq s (list 
nil))) l1 (cond ((not var) (return (cdr r)))) (rplacd s fn) l2 (cond ((not (
atom (cdr s))) (setq s (cdr s)) (go l2))) moveon (go l1))))))))) (return fn))
)

(put (quote map) (quote c!:compile_macro) (function c!:expand_map))

(put (quote maplist) (quote c!:compile_macro) (function c!:expand_map))

(put (quote mapc) (quote c!:compile_macro) (function c!:expand_map))

(put (quote mapcar) (quote c!:compile_macro) (function c!:expand_map))

(put (quote mapcon) (quote c!:compile_macro) (function c!:expand_map))

(put (quote mapcan) (quote c!:compile_macro) (function c!:expand_map))

(de c!:expand_carcdr (x) (prog (name) (setq name (cdr (reverse (cdr (explode2
(car x)))))) (setq x (cadr x)) (prog (var1378) (setq var1378 name) lab1377 (
cond ((null var1378) (return nil))) (prog (v) (setq v (car var1378)) (setq x 
(list (cond ((equal v (quote a)) (quote car)) (t (quote cdr))) x))) (setq 
var1378 (cdr var1378)) (go lab1377)) (return x)))

(progn (put (quote caaar) (quote c!:compile_macro) (function c!:expand_carcdr
)) (put (quote caadr) (quote c!:compile_macro) (function c!:expand_carcdr)) (
put (quote cadar) (quote c!:compile_macro) (function c!:expand_carcdr)) (put 
(quote caddr) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (
quote cdaar) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (
quote cdadr) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (
quote cddar) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (
quote cdddr) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (
quote caaaar) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (
quote caaadr) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (
quote caadar) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (
quote caaddr) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (
quote cadaar) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (
quote cadadr) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (
quote caddar) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (
quote cadddr) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (
quote cdaaar) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (
quote cdaadr) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (
quote cdadar) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (
quote cdaddr) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (
quote cddaar) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (
quote cddadr) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (
quote cdddar) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (
quote cddddr) (quote c!:compile_macro) (function c!:expand_carcdr)))

(de c!:builtin_one (x env) (prog (r1 r2) (setq r1 (c!:cval (cadr x) env)) (
c!:outop (car x) (setq r2 (c!:newreg)) (cdr env) r1) (return r2)))

(de c!:builtin_two (x env) (prog (a1 a2 r rr) (setq a1 (cadr x)) (setq a2 (
caddr x)) (setq rr (c!:evalargs (list a1 a2) env)) (c!:outop (car x) (setq r 
(c!:newreg)) (car rr) (cadr rr)) (return r)))

(de c!:rplac (x env) (prog (a1 a2 r rr) (setq a1 (cadr x)) (setq a2 (caddr x)
) (setq rr (c!:evalargs (list a1 a2) env)) (c!:outop (car x) nil (car rr) (
cadr rr)) (c!:outop (quote movr) (setq r (c!:newreg)) nil (car rr)) (return r
)))

(put (quote rplaca) (quote c!:code) (function c!:rplac))

(put (quote rplacd) (quote c!:code) (function c!:rplac))

(de c!:narg (x env) (c!:cval (expand (cdr x) (get (car x) (quote 
c!:binary_version))) env))

(prog (var1380) (setq var1380 (quote ((plus plus2) (times times2) (iplus 
iplus2) (itimes itimes2)))) lab1379 (cond ((null var1380) (return nil))) (
prog (n) (setq n (car var1380)) (progn (put (car n) (quote c!:binary_version)
(cadr n)) (put (car n) (quote c!:code) (function c!:narg)))) (setq var1380 (
cdr var1380)) (go lab1379))

(de c!:cplus2 (u env) (prog (a b) (setq a (s!:improve (cadr u))) (setq b (
s!:improve (caddr u))) (return (cond ((and (numberp a) (numberp b)) (c!:cval 
(plus a b) env)) (t (cond ((equal a 0) (c!:cval b env)) (t (cond ((equal a 1)
(c!:cval (list (quote add1) b) env)) (t (cond ((equal b 0) (c!:cval a env)) 
(t (cond ((equal b 1) (c!:cval (list (quote add1) a) env)) (t (cond ((equal b
(minus 1)) (c!:cval (list (quote sub1) a) env)) (t (c!:ccall (car u) (cdr u)
env))))))))))))))))

(put (quote plus2) (quote c!:code) (function c!:cplus2))

(de c!:ciplus2 (u env) (prog (a b) (setq a (s!:improve (cadr u))) (setq b (
s!:improve (caddr u))) (return (cond ((and (numberp a) (numberp b)) (c!:cval 
(plus a b) env)) (t (cond ((equal a 0) (c!:cval b env)) (t (cond ((equal a 1)
(c!:cval (list (quote iadd1) b) env)) (t (cond ((equal b 0) (c!:cval a env))
(t (cond ((equal b 1) (c!:cval (list (quote iadd1) a) env)) (t (cond ((equal
b (minus 1)) (c!:cval (list (quote isub1) a) env)) (t (c!:builtin_two u env)
)))))))))))))))

(put (quote iplus2) (quote c!:code) (function c!:ciplus2))

(de c!:cdifference (u env) (prog (a b) (setq a (s!:improve (cadr u))) (setq b
(s!:improve (caddr u))) (return (cond ((and (numberp a) (numberp b)) (
c!:cval (difference a b) env)) (t (cond ((equal a 0) (c!:cval (list (quote 
minus) b) env)) (t (cond ((equal b 0) (c!:cval a env)) (t (cond ((equal b 1) 
(c!:cval (list (quote sub1) a) env)) (t (cond ((equal b (minus 1)) (c!:cval (
list (quote add1) a) env)) (t (c!:ccall (car u) (cdr u) env))))))))))))))

(put (quote difference) (quote c!:code) (function c!:cdifference))

(de c!:cidifference (u env) (prog (a b) (setq a (s!:improve (cadr u))) (setq 
b (s!:improve (caddr u))) (return (cond ((and (numberp a) (numberp b)) (
c!:cval (difference a b) env)) (t (cond ((equal a 0) (c!:cval (list (quote 
iminus) b) env)) (t (cond ((equal b 0) (c!:cval a env)) (t (cond ((equal b 1)
(c!:cval (list (quote isub1) a) env)) (t (cond ((equal b (minus 1)) (c!:cval
(list (quote iadd1) a) env)) (t (c!:builtin_two u env))))))))))))))

(put (quote idifference) (quote c!:code) (function c!:cidifference))

(de c!:ctimes2 (u env) (prog (a b) (setq a (s!:improve (cadr u))) (setq b (
s!:improve (caddr u))) (return (cond ((and (numberp a) (numberp b)) (c!:cval 
(times a b) env)) (t (cond ((or (equal a 0) (equal b 0)) (c!:cval 0 env)) (t 
(cond ((equal a 1) (c!:cval b env)) (t (cond ((equal b 1) (c!:cval a env)) (t
(cond ((equal a (minus 1)) (c!:cval (list (quote minus) b) env)) (t (cond ((
equal b (minus 1)) (c!:cval (list (quote minus) a) env)) (t (c!:ccall (car u)
(cdr u) env))))))))))))))))

(put (quote times2) (quote c!:code) (function c!:ctimes2))

(de c!:citimes2 (u env) (prog (a b) (setq a (s!:improve (cadr u))) (setq b (
s!:improve (caddr u))) (return (cond ((and (numberp a) (numberp b)) (c!:cval 
(times a b) env)) (t (cond ((or (equal a 0) (equal b 0)) (c!:cval 0 env)) (t 
(cond ((equal a 1) (c!:cval b env)) (t (cond ((equal b 1) (c!:cval a env)) (t
(cond ((equal a (minus 1)) (c!:cval (list (quote iminus) b) env)) (t (cond (
(equal b (minus 1)) (c!:cval (list (quote iminus) a) env)) (t (c!:builtin_two
u env))))))))))))))))

(put (quote itimes2) (quote c!:code) (function c!:citimes2))

(de c!:cminus (u env) (prog (a b) (setq a (s!:improve (cadr u))) (return (
cond ((numberp a) (c!:cval (minus a) env)) (t (cond ((eqcar a (quote minus)) 
(c!:cval (cadr a) env)) (t (c!:ccall (car u) (cdr u) env))))))))

(put (quote minus) (quote c!:code) (function c!:cminus))

(de c!:ceq (x env) (prog (a1 a2 r rr) (setq a1 (s!:improve (cadr x))) (setq 
a2 (s!:improve (caddr x))) (cond ((equal a1 nil) (return (c!:cval (list (
quote null) a2) env))) (t (cond ((equal a2 nil) (return (c!:cval (list (quote
null) a1) env)))))) (setq rr (c!:evalargs (list a1 a2) env)) (c!:outop (
quote eq) (setq r (c!:newreg)) (car rr) (cadr rr)) (return r)))

(put (quote eq) (quote c!:code) (function c!:ceq))

(de c!:cequal (x env) (prog (a1 a2 r rr) (setq a1 (s!:improve (cadr x))) (
setq a2 (s!:improve (caddr x))) (cond ((equal a1 nil) (return (c!:cval (list 
(quote null) a2) env))) (t (cond ((equal a2 nil) (return (c!:cval (list (
quote null) a1) env)))))) (setq rr (c!:evalargs (list a1 a2) env)) (c!:outop 
(cond ((or (c!:eqvalid a1) (c!:eqvalid a2)) (quote eq)) (t (quote equal))) (
setq r (c!:newreg)) (car rr) (cadr rr)) (return r)))

(put (quote equal) (quote c!:code) (function c!:cequal))

(de c!:is_fixnum (x) (and (fixp x) (geq x (minus 134217728)) (leq x 134217727
)))

(de c!:certainlyatom (x) (or (null x) (equal x t) (c!:is_fixnum x) (and (
eqcar x (quote quote)) (or (symbolp (cadr x)) (c!:is_fixnum (cadr x))))))

(de c!:atomlist1 (u) (or (atom u) (and (or (symbolp (car u)) (c!:is_fixnum (
car u))) (c!:atomlist1 (cdr u)))))

(de c!:atomlist (x) (or (null x) (and (eqcar x (quote quote)) (c!:atomlist1 (
cadr x))) (and (eqcar x (quote list)) (or (null (cdr x)) (and (
c!:certainlyatom (cadr x)) (c!:atomlist (cons (quote list) (cddr x)))))) (and
(eqcar x (quote cons)) (c!:certainlyatom (cadr x)) (c!:atomlist (caddr x))))
)

(de c!:atomcar (x) (and (or (eqcar x (quote cons)) (eqcar x (quote list))) (
not (null (cdr x))) (c!:certainlyatom (cadr x))))

(de c!:atomkeys1 (u) (or (atom u) (and (not (atom (car u))) (or (symbolp (
caar u)) (c!:is_fixnum (caar u))) (c!:atomlist1 (cdr u)))))

(de c!:atomkeys (x) (or (null x) (and (eqcar x (quote quote)) (c!:atomkeys1 (
cadr x))) (and (eqcar x (quote list)) (or (null (cdr x)) (and (c!:atomcar (
cadr x)) (c!:atomkeys (cons (quote list) (cddr x)))))) (and (eqcar x (quote 
cons)) (c!:atomcar (cadr x)) (c!:atomkeys (caddr x)))))

(de c!:comsublis (x) (cond ((c!:atomkeys (cadr x)) (cons (quote subla) (cdr x
))) (t nil)))

(put (quote sublis) (quote c!:compile_macro) (function c!:comsublis))

(de c!:comassoc (x) (cond ((or (c!:certainlyatom (cadr x)) (c!:atomkeys (
caddr x))) (cons (quote atsoc) (cdr x))) (t nil)))

(put (quote assoc) (quote c!:compile_macro) (function c!:comassoc))

(put (quote assoc!*!*) (quote c!:compile_macro) (function c!:comassoc))

(de c!:commember (x) (cond ((or (c!:certainlyatom (cadr x)) (c!:atomlist (
caddr x))) (cons (quote memq) (cdr x))) (t nil)))

(put (quote member) (quote c!:compile_macro) (function c!:commember))

(de c!:comdelete (x) (cond ((or (c!:certainlyatom (cadr x)) (c!:atomlist (
caddr x))) (cons (quote deleq) (cdr x))) (t nil)))

(put (quote delete) (quote c!:compile_macro) (function c!:comdelete))

(de c!:ctestif (x env d1 d2) (prog (l1 l2) (setq l1 (c!:my_gensym)) (setq l2 
(c!:my_gensym)) (c!:jumpif (cadr x) l1 l2) (setq x (cddr x)) (c!:startblock 
l1) (c!:jumpif (car x) d1 d2) (c!:startblock l2) (c!:jumpif (cadr x) d1 d2)))

(put (quote if) (quote c!:ctest) (function c!:ctestif))

(de c!:ctestnull (x env d1 d2) (c!:cjumpif (cadr x) env d2 d1))

(put (quote null) (quote c!:ctest) (function c!:ctestnull))

(put (quote not) (quote c!:ctest) (function c!:ctestnull))

(de c!:ctestatom (x env d1 d2) (prog nil (setq x (c!:cval (cadr x) env)) (
c!:endblock (list (quote ifatom) x) (list d1 d2))))

(put (quote atom) (quote c!:ctest) (function c!:ctestatom))

(de c!:ctestconsp (x env d1 d2) (prog nil (setq x (c!:cval (cadr x) env)) (
c!:endblock (list (quote ifatom) x) (list d2 d1))))

(put (quote consp) (quote c!:ctest) (function c!:ctestconsp))

(de c!:ctestsymbol (x env d1 d2) (prog nil (setq x (c!:cval (cadr x) env)) (
c!:endblock (list (quote ifsymbol) x) (list d1 d2))))

(put (quote idp) (quote c!:ctest) (function c!:ctestsymbol))

(de c!:ctestnumberp (x env d1 d2) (prog nil (setq x (c!:cval (cadr x) env)) (
c!:endblock (list (quote ifnumber) x) (list d1 d2))))

(put (quote numberp) (quote c!:ctest) (function c!:ctestnumberp))

(de c!:ctestizerop (x env d1 d2) (prog nil (setq x (c!:cval (cadr x) env)) (
c!:endblock (list (quote ifizerop) x) (list d1 d2))))

(put (quote izerop) (quote c!:ctest) (function c!:ctestizerop))

(de c!:ctesteq (x env d1 d2) (prog (a1 a2 r) (setq a1 (cadr x)) (setq a2 (
caddr x)) (cond ((equal a1 nil) (return (c!:cjumpif a2 env d2 d1))) (t (cond 
((equal a2 nil) (return (c!:cjumpif a1 env d2 d1)))))) (setq r (c!:evalargs (
list a1 a2) env)) (c!:endblock (cons (quote ifeq) r) (list d1 d2))))

(put (quote eq) (quote c!:ctest) (function c!:ctesteq))

(de c!:ctesteqcar (x env d1 d2) (prog (a1 a2 r d3) (setq a1 (cadr x)) (setq 
a2 (caddr x)) (setq d3 (c!:my_gensym)) (setq r (c!:evalargs (list a1 a2) env)
) (c!:endblock (list (quote ifatom) (car r)) (list d2 d3)) (c!:startblock d3)
(c!:outop (quote qcar) (car r) nil (car r)) (c!:endblock (cons (quote ifeq) 
r) (list d1 d2))))

(put (quote eqcar) (quote c!:ctest) (function c!:ctesteqcar))

(global (quote (least_fixnum greatest_fixnum)))

(setq least_fixnum (minus (expt 2 27)))

(setq greatest_fixnum (difference (expt 2 27) 1))

(de c!:small_number (x) (and (fixp x) (geq x least_fixnum) (leq x 
greatest_fixnum)))

(de c!:eqvalid (x) (cond ((atom x) (c!:small_number x)) (t (cond ((flagp (car
x) (quote c!:fixnum_fn)) t) (t (and (equal (car x) (quote quote)) (or (idp (
cadr x)) (c!:small_number (cadr x)))))))))

(flag (quote (iplus iplus2 idifference iminus itimes itimes2)) (quote 
c!:fixnum_fn))

(de c!:ctestequal (x env d1 d2) (prog (a1 a2 r) (setq a1 (s!:improve (cadr x)
)) (setq a2 (s!:improve (caddr x))) (cond ((equal a1 nil) (return (c!:cjumpif
a2 env d2 d1))) (t (cond ((equal a2 nil) (return (c!:cjumpif a1 env d2 d1)))
))) (setq r (c!:evalargs (list a1 a2) env)) (c!:endblock (cons (cond ((or (
c!:eqvalid a1) (c!:eqvalid a2)) (quote ifeq)) (t (quote ifequal))) r) (list 
d1 d2))))

(put (quote equal) (quote c!:ctest) (function c!:ctestequal))

(de c!:ctestneq (x env d1 d2) (prog (a1 a2 r) (setq a1 (s!:improve (cadr x)))
(setq a2 (s!:improve (caddr x))) (cond ((equal a1 nil) (return (c!:cjumpif 
a2 env d1 d2))) (t (cond ((equal a2 nil) (return (c!:cjumpif a1 env d1 d2))))
)) (setq r (c!:evalargs (list a1 a2) env)) (c!:endblock (cons (cond ((or (
c!:eqvalid a1) (c!:eqvalid a2)) (quote ifeq)) (t (quote ifequal))) r) (list 
d2 d1))))

(put (quote neq) (quote c!:ctest) (function c!:ctestneq))

(de c!:ctestilessp (x env d1 d2) (prog (r) (setq r (c!:evalargs (list (cadr x
) (caddr x)) env)) (c!:endblock (cons (quote ifilessp) r) (list d1 d2))))

(put (quote ilessp) (quote c!:ctest) (function c!:ctestilessp))

(de c!:ctestigreaterp (x env d1 d2) (prog (r) (setq r (c!:evalargs (list (
cadr x) (caddr x)) env)) (c!:endblock (cons (quote ifigreaterp) r) (list d1 
d2))))

(put (quote igreaterp) (quote c!:ctest) (function c!:ctestigreaterp))

(de c!:ctestand (x env d1 d2) (prog (next) (prog (var1382) (setq var1382 (cdr
x)) lab1381 (cond ((null var1382) (return nil))) (prog (a) (setq a (car 
var1382)) (progn (setq next (c!:my_gensym)) (c!:cjumpif a env next d2) (
c!:startblock next))) (setq var1382 (cdr var1382)) (go lab1381)) (c!:endblock
(quote goto) (list d1))))

(put (quote and) (quote c!:ctest) (function c!:ctestand))

(de c!:ctestor (x env d1 d2) (prog (next) (prog (var1384) (setq var1384 (cdr 
x)) lab1383 (cond ((null var1384) (return nil))) (prog (a) (setq a (car 
var1384)) (progn (setq next (c!:my_gensym)) (c!:cjumpif a env d1 next) (
c!:startblock next))) (setq var1384 (cdr var1384)) (go lab1383)) (c!:endblock
(quote goto) (list d2))))

(put (quote or) (quote c!:ctest) (function c!:ctestor))

(fluid (quote (c!:c_entrypoint_list)))

(null (setq c!:c_entrypoint_list (quote ((apply0 c!:c_entrypoint "Lapply0") (
apply1 c!:c_entrypoint "Lapply1") (apply2 c!:c_entrypoint "Lapply2") (apply3 
c!:c_entrypoint "Lapply3") (atom c!:c_entrypoint "Latom") (atsoc 
c!:c_entrypoint "Latsoc") (batchp c!:c_entrypoint "Lbatchp") (boundp 
c!:c_entrypoint "Lboundp") (bps!-putv c!:c_entrypoint "Lbpsputv") (caaaar 
c!:c_entrypoint "Lcaaaar") (caaadr c!:c_entrypoint "Lcaaadr") (caaar 
c!:c_entrypoint "Lcaaar") (caadar c!:c_entrypoint "Lcaadar") (caaddr 
c!:c_entrypoint "Lcaaddr") (caadr c!:c_entrypoint "Lcaadr") (caar 
c!:c_entrypoint "Lcaar") (cadaar c!:c_entrypoint "Lcadaar") (cadadr 
c!:c_entrypoint "Lcadadr") (cadar c!:c_entrypoint "Lcadar") (caddar 
c!:c_entrypoint "Lcaddar") (cadddr c!:c_entrypoint "Lcadddr") (caddr 
c!:c_entrypoint "Lcaddr") (cadr c!:c_entrypoint "Lcadr") (car c!:c_entrypoint
"Lcar") (cdaaar c!:c_entrypoint "Lcdaaar") (cdaadr c!:c_entrypoint "Lcdaadr"
) (cdaar c!:c_entrypoint "Lcdaar") (cdadar c!:c_entrypoint "Lcdadar") (cdaddr
c!:c_entrypoint "Lcdaddr") (cdadr c!:c_entrypoint "Lcdadr") (cdar 
c!:c_entrypoint "Lcdar") (cddaar c!:c_entrypoint "Lcddaar") (cddadr 
c!:c_entrypoint "Lcddadr") (cddar c!:c_entrypoint "Lcddar") (cdddar 
c!:c_entrypoint "Lcdddar") (cddddr c!:c_entrypoint "Lcddddr") (cdddr 
c!:c_entrypoint "Lcdddr") (cddr c!:c_entrypoint "Lcddr") (cdr c!:c_entrypoint
"Lcdr") (char!-code c!:c_entrypoint "Lchar_code") (close c!:c_entrypoint 
"Lclose") (codep c!:c_entrypoint "Lcodep") (constantp c!:c_entrypoint 
"Lconstantp") (date c!:c_entrypoint "Ldate") (deleq c!:c_entrypoint "Ldeleq")
(digit c!:c_entrypoint "Ldigitp") (eject c!:c_entrypoint "Leject") (endp 
c!:c_entrypoint "Lendp") (eq c!:c_entrypoint "Leq") (eqcar c!:c_entrypoint 
"Leqcar") (eql c!:c_entrypoint "Leql") (error1 c!:c_entrypoint "Lerror_0") (
evlis c!:c_entrypoint "Levlis") (explode c!:c_entrypoint "Lexplode") (
explode2 c!:c_entrypoint "Lexplodec") (explodec c!:c_entrypoint "Lexplodec") 
(fixp c!:c_entrypoint "Lfixp") (flag c!:c_entrypoint "Lflag") (flagp!*!* 
c!:c_entrypoint "Lflagp") (flagp c!:c_entrypoint "Lflagp") (flagpcar 
c!:c_entrypoint "Lflagpcar") (floatp c!:c_entrypoint "Lfloatp") (fluidp 
c!:c_entrypoint "Lsymbol_specialp") (gctime c!:c_entrypoint "Lgctime") (
gensym c!:c_entrypoint "Lgensym") (gensym1 c!:c_entrypoint "Lgensym") (get!* 
c!:c_entrypoint "Lget") (getenv c!:c_entrypoint "Lgetenv") (getv 
c!:c_entrypoint "Lgetv") (svref c!:c_entrypoint "Lgetv") (globalp 
c!:c_entrypoint "Lsymbol_globalp") (idp c!:c_entrypoint "Lsymbolp") (indirect
c!:c_entrypoint "Lindirect") (integerp c!:c_entrypoint "Lintegerp") (length 
c!:c_entrypoint "Llength") (lengthc c!:c_entrypoint "Llengthc") (linelength 
c!:c_entrypoint "Llinelength") (load!-module c!:c_entrypoint "Lload_module") 
(lposn c!:c_entrypoint "Llposn") (macro!-function c!:c_entrypoint 
"Lmacro_function") (macroexpand!-1 c!:c_entrypoint "Lmacroexpand_1") (
macroexpand c!:c_entrypoint "Lmacroexpand") (make!-bps c!:c_entrypoint 
"Lget_bps") (make!-global c!:c_entrypoint "Lmake_global") (
make!-simple!-string c!:c_entrypoint "Lsmkvect") (make!-special 
c!:c_entrypoint "Lmake_special") (mapstore c!:c_entrypoint "Lmapstore") (memq
c!:c_entrypoint "Lmemq") (mkquote c!:c_entrypoint "Lmkquote") (mkvect 
c!:c_entrypoint "Lmkvect") (nconc c!:c_entrypoint "Lnconc") (neq 
c!:c_entrypoint "Lneq_2") (not c!:c_entrypoint "Lnull") (null c!:c_entrypoint
"Lnull") (numberp c!:c_entrypoint "Lnumberp") (orderp c!:c_entrypoint 
"Lorderp") (pagelength c!:c_entrypoint "Lpagelength") (pairp c!:c_entrypoint 
"Lconsp") (plist c!:c_entrypoint "Lplist") (posn c!:c_entrypoint "Lposn") (
put c!:c_entrypoint "Lputprop") (putv!-char c!:c_entrypoint "Lsputv") (putv 
c!:c_entrypoint "Lputv") (qcaar c!:c_entrypoint "Lcaar") (qcadr 
c!:c_entrypoint "Lcadr") (qcar c!:c_entrypoint "Lcar") (qcdar c!:c_entrypoint
"Lcdar") (qcddr c!:c_entrypoint "Lcddr") (qcdr c!:c_entrypoint "Lcdr") (
qgetv c!:c_entrypoint "Lgetv") (rds c!:c_entrypoint "Lrds") (reclaim 
c!:c_entrypoint "Lgc") (remd c!:c_entrypoint "Lremd") (remflag 
c!:c_entrypoint "Lremflag") (remob c!:c_entrypoint "Lunintern") (remprop 
c!:c_entrypoint "Lremprop") (reverse c!:c_entrypoint "Lreverse") (reversip 
c!:c_entrypoint "Lnreverse") (rplaca c!:c_entrypoint "Lrplaca") (rplacd 
c!:c_entrypoint "Lrplacd") (schar c!:c_entrypoint "Lsgetv") (seprp 
c!:c_entrypoint "Lwhitespace_char_p") (set c!:c_entrypoint "Lset") (smemq 
c!:c_entrypoint "Lsmemq") (spaces c!:c_entrypoint "Lxtab") (special!-char 
c!:c_entrypoint "Lspecial_char") (special!-form!-p c!:c_entrypoint 
"Lspecial_form_p") (spool c!:c_entrypoint "Lspool") (stop c!:c_entrypoint 
"Lstop") (stringp c!:c_entrypoint "Lstringp") (subla c!:c_entrypoint "Lsubla"
) (subst c!:c_entrypoint "Lsubst") (symbol!-env c!:c_entrypoint "Lsymbol_env"
) (symbol!-function c!:c_entrypoint "Lsymbol_function") (symbol!-name 
c!:c_entrypoint "Lsymbol_name") (symbol!-set!-definition c!:c_entrypoint 
"Lsymbol_set_definition") (symbol!-set!-env c!:c_entrypoint "Lsymbol_set_env"
) (symbol!-value c!:c_entrypoint "Lsymbol_value") (system c!:c_entrypoint 
"Lsystem") (terpri c!:c_entrypoint "Lterpri") (threevectorp c!:c_entrypoint 
"Lthreevectorp") (time c!:c_entrypoint "Ltime") (ttab c!:c_entrypoint "Lttab"
) (tyo c!:c_entrypoint "Ltyo") (unmake!-global c!:c_entrypoint 
"Lunmake_global") (unmake!-special c!:c_entrypoint "Lunmake_special") (upbv 
c!:c_entrypoint "Lupbv") (verbos c!:c_entrypoint "Lverbos") (wrs 
c!:c_entrypoint "Lwrs") (xcons c!:c_entrypoint "Lxcons") (xtab 
c!:c_entrypoint "Lxtab") (cons c!:direct_entrypoint (2 . "cons")) (ncons 
c!:direct_entrypoint (1 . "ncons")) (list2 c!:direct_entrypoint (2 . "list2")
) (list2!* c!:direct_entrypoint (3 . "list2star")) (acons 
c!:direct_entrypoint (3 . "acons")) (list3 c!:direct_entrypoint (3 . "list3")
) (list3!* c!:direct_entrypoint (4 . "list3star")) (list4 
c!:direct_entrypoint (4 . "list4"))))))

(null (setq c!:c_entrypoint_list (append c!:c_entrypoint_list (quote ((abs 
c!:c_entrypoint "GABSVAL") (add1 c!:c_entrypoint "GADD1") (!1!+ 
c!:c_entrypoint "GADD1") (ash1 c!:c_entrypoint "GASH1") (atan c!:c_entrypoint
"GATAN") (divide c!:c_entrypoint "GDIVIDE") (eqn c!:c_entrypoint "GEQN") (
evenp c!:c_entrypoint "GEVENP") (expt c!:c_entrypoint "GEXPT") (fix 
c!:c_entrypoint "GTRUNCATE") (float c!:c_entrypoint "GFLOAT") (gcdn 
c!:c_entrypoint "GGCD") (geq c!:c_entrypoint "GGEQ") (greaterp 
c!:c_entrypoint "GGREATERP") (iadd1 c!:c_entrypoint "GIADD1") (idifference 
c!:c_entrypoint "GIDIFFERENCE") (igreaterp c!:c_entrypoint "GIGREATERP") (
ilessp c!:c_entrypoint "GILESSP") (iminus c!:c_entrypoint "GIMINUS") (iminusp
c!:c_entrypoint "GIMINUSP") (iplus2 c!:c_entrypoint "GIPLUS") (iquotient 
c!:c_entrypoint "GIQUOTIENT") (iremainder c!:c_entrypoint "GIREMAINDER") (
irightshift c!:c_entrypoint "GIRIGHTSHIFT") (isub1 c!:c_entrypoint "GISUB1") 
(itimes2 c!:c_entrypoint "GITIMES") (leq c!:c_entrypoint "GLEQ") (lessp 
c!:c_entrypoint "GLESSP") (max2 c!:c_entrypoint "GMAX") (min2 c!:c_entrypoint
"GMIN") (minus c!:c_entrypoint "GMINUS") (minusp c!:c_entrypoint "GMINUSP") 
(mod c!:c_entrypoint "GMOD") (set!-small!-modulus c!:c_entrypoint 
"GSET_SMALL_MODULUS") (modular!-difference c!:c_entrypoint 
"GMODULAR_DIFFERENCE") (modular!-expt c!:c_entrypoint "GMODULAR_EXPT") (
modular!-minus c!:c_entrypoint "GMODULAR_MINUS") (modular!-number 
c!:c_entrypoint "GMODULAR_NUMBER") (modular!-plus c!:c_entrypoint 
"GMODULAR_PLUS") (modular!-quotient c!:c_entrypoint "GMODULAR_QUOTIENT") (
modular!-reciprocal c!:c_entrypoint "GMODULAR_RECIPROCAL") (modular!-times 
c!:c_entrypoint "GMODULAR_TIMES") (oddp c!:c_entrypoint "GODDP") (onep 
c!:c_entrypoint "GONEP") (plusp c!:c_entrypoint "GPLUSP") (!1!- 
c!:c_entrypoint "GSUB1") (zerop c!:c_entrypoint "GZEROP") (plus2 
c!:direct_entrypoint (2 . "DPLUS2")) (difference c!:direct_entrypoint (2 . 
"DDIFFERENCE2")) (add1 c!:direct_entrypoint (1 . "DADD1")) (sub1 
c!:direct_entrypoint (1 . "DSUB1")) (lognot c!:direct_entrypoint (1 . 
"DLOGNOT")) (ash c!:direct_entrypoint (2 . "DASH")) (quotient 
c!:direct_entrypoint (2 . "DQUOT")) (remainder c!:direct_entrypoint (2 . 
"DCREMAINDER")) (times2 c!:direct_entrypoint (2 . "DTIMES2")) (minus 
c!:direct_entrypoint (1 . "DNEGATE")) (lessp c!:direct_predicate (2 . 
"DLESSP2")) (leq c!:direct_predicate (2 . "DLESSEQ2")) (greaterp 
c!:direct_predicate (2 . "DGREATERP2")) (geq c!:direct_predicate (2 . "DGEQ2"
)) (zerop c!:direct_predicate (1 . "DZEROP")))))))

(null (setq c!:c_entrypoint_list (append c!:c_entrypoint_list (quote ((append
c!:c_entrypoint "Lappend_2") (assoc c!:c_entrypoint "Lassoc") (compress 
c!:c_entrypoint "Lcompress") (delete c!:c_entrypoint "Ldelete") (equal 
c!:c_entrypoint "Lequal") (intern c!:c_entrypoint "Lintern") (liter 
c!:c_entrypoint "Lalpha_char_p") (member c!:c_entrypoint "Lmember") (prin 
c!:c_entrypoint "Lprin") (prin1 c!:c_entrypoint "Lprin") (prin2 
c!:c_entrypoint "Lprinc") (princ c!:c_entrypoint "Lprinc") (print 
c!:c_entrypoint "Lprint") (printc c!:c_entrypoint "Lprintc") (read 
c!:c_entrypoint "Lread") (readch c!:c_entrypoint "Lreadch") (sublis 
c!:c_entrypoint "Lsublis") (vectorp c!:c_entrypoint "Lsimple_vectorp") (get 
c!:direct_entrypoint (2 . "get")))))))

(prog (var1386) (setq var1386 c!:c_entrypoint_list) lab1385 (cond ((null 
var1386) (return nil))) (prog (x) (setq x (car var1386)) (put (car x) (cadr x
) (caddr x))) (setq var1386 (cdr var1386)) (go lab1385))

(flag (quote (atom atsoc codep constantp deleq digit endp eq eqcar evenp eql 
fixp flagp flagpcar floatp get globalp iadd1 idifference idp igreaterp ilessp
iminus iminusp indirect integerp iplus2 irightshift isub1 itimes2 liter memq
minusp not null numberp onep pairp plusp qcaar qcadr qcar qcdar qcddr qcdr 
remflag remprop reversip seprp special!-form!-p stringp symbol!-env 
symbol!-name symbol!-value threevectorp vectorp zerop)) (quote c!:no_errors))


% end of file
