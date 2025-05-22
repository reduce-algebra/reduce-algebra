
% RLISP to LISP converter. A C Norman 2025


%%
%% Copyright (C) 2025, following the master REDUCE source files.          *
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

(dm df (u !&optional env) (prog (g w) (setq g (gensym)) (setq w (list (quote 
list) (quote (quote let!*)) (list (quote list) (list (quote list) (mkquote (
caaddr u)) (list (quote mkquote) (list (quote cdr) g)))) (list (quote cons) (
quote (quote progn)) (mkquote (cdddr u))))) (return (list (quote dm) (cadr u)
(list g (quote !&optional) (gensym)) w))))

(flag (quote (copyd)) (quote lose))

(de oem!-supervisor nil (print (eval (read))))

(de break!-loop (a) (prog (prompt ifile ofile u v) (setq ifile (rds 
!*debug!-io!*)) (setq ofile (wrs !*debug!-io!*)) (setq prompt (setpchar 
"Break loop (:X exits)> ")) top (setq u (read)) (cond ((equal u (quote !:x)) 
(go exit)) (t (cond ((equal u (quote !:q)) (progn (enable!-backtrace nil) (
princ "Backtrace now disabled") (terpri))) (t (cond ((equal u (quote !:v)) (
progn (enable!-backtrace t) (princ "Backtrace now enabled") (terpri))) (t (
progn (cond ((null u) (setq v nil)) (t (setq v (errorset u nil nil)))) (cond 
((atom v) (progn (princ ":Q   quietens backtrace") (terpri) (princ 
":V   enables backtrace") (terpri) (princ ":X   exits from break loop") (
terpri) (princ "else form for evaluation") (terpri))) (t (progn (prin "=> ") 
(prinl (car v)) (terpri))))))))))) (go top) exit (rds ifile) (wrs ofile) (
setpchar prompt) (return nil)))

(de hashtagged!-name (base value) (intern (list2string (append (explodec base
) (cons (quote !_) (explodehex (md60 value)))))))

(remflag (quote (sort sortip)) (quote lose))

(de sort (l pred) (stable!-sortip (append l nil) pred))

(de stable!-sort (l pred) (stable!-sortip (append l nil) pred))

(de sortip (l pred) (stable!-sortip l pred))

(de stable!-sortip (l pred) (prog (l1 l2 w) (cond ((null l) (return l))) (
setq l1 l) (setq l2 (cdr l)) (cond ((null l2) (return l))) (setq l (cdr l2)) 
(cond ((null l) (progn (cond ((apply2 pred (car l2) (car l1)) (progn (setq l 
(car l1)) (rplaca l1 (car l2)) (rplaca l2 l)))) (return l1)))) (setq l l1) (
prog nil lab1000 (cond ((null (and l2 (not (apply2 pred (car l2) (car l))))) 
(return nil))) (progn (setq l l2) (setq l2 (cdr l2))) (go lab1000)) (cond ((
null l2) (return l1))) (setq l2 l1) (setq l (cddr l2)) (prog nil lab1001 (
cond ((null (and l (cdr l))) (return nil))) (progn (setq l2 (cdr l2)) (setq l
(cddr l))) (go lab1001)) (setq l l2) (setq l2 (cdr l2)) (rplacd l nil) (setq
l1 (stable!-sortip l1 pred)) (setq l2 (stable!-sortip l2 pred)) (setq l (
setq w (list nil))) (prog nil lab1002 (cond ((null (and l1 l2)) (return nil))
) (progn (cond ((apply2 pred (car l2) (car l1)) (progn (rplacd w l2) (setq w 
l2) (setq l2 (cdr l2)))) (t (progn (rplacd w l1) (setq w l1) (setq l1 (cdr l1
)))))) (go lab1002)) (cond (l1 (setq l2 l1))) (rplacd w l2) (return (cdr l)))
)

(fluid (quote (!*prinl!-visited!-nodes!* !*prinl!-index!* !*prinl!-fn!* 
!*print!-array!* !*print!-length!* !*print!-level!*)))

(fluid (quote (!*show!-shared)))

(setq !*show!-shared nil)

(setq !*print!-length!* (setq !*print!-level!* nil))

(setq !*prinl!-visited!-nodes!* (mkhash 10 0 1.5))

(de s!:prinl0 (x !*prinl!-fn!*) (prog (!*prinl!-index!*) (setq 
!*prinl!-index!* 0) (clrhash !*prinl!-visited!-nodes!*) (cond (!*show!-shared
(s!:prinl1a x 0)) (t (s!:prinl1b x 0 nil))) (s!:prinl2 x 0) (clrhash 
!*prinl!-visited!-nodes!*) (return x)))

(de s!:prinl1a (x depth) (prog (w length) (cond ((and (fixp !*print!-level!*)
(greaterp depth !*print!-level!*)) (return nil))) (setq length 0) top (cond 
((and (atom x) (not (simple!-vector!-p x)) (not (gensymp x)) (not (
hash!-table!-p x))) (return nil)) (t (cond ((setq w (gethash x 
!*prinl!-visited!-nodes!*)) (progn (cond ((equal w 0) (progn (setq 
!*prinl!-index!* (plus !*prinl!-index!* 1)) (puthash x 
!*prinl!-visited!-nodes!* !*prinl!-index!*)))) (return nil))) (t (progn (
puthash x !*prinl!-visited!-nodes!* 0) (cond ((simple!-vector!-p x) (progn (
cond (!*print!-array!* (progn (setq length (upbv x)) (cond ((and (fixp 
!*print!-length!*) (lessp !*print!-length!* length)) (setq length 
!*print!-length!*))) (prog (i) (setq i 0) lab1003 (cond ((minusp (times 1 (
difference length i))) (return nil))) (s!:prinl1a (getv x i) (plus depth 1)) 
(setq i (plus i 1)) (go lab1003))))))) (t (cond ((hash!-table!-p x) (
s!:prinl1a (hashcontents x) (plus depth 1))) (t (cond ((not (atom x)) (progn 
(s!:prinl1a (car x) (plus depth 1)) (cond ((and (fixp !*print!-length!*) (
greaterp (setq length (plus length 1)) !*print!-length!*)) (return nil))) (
setq x (cdr x)) (go top)))))))))))))))

(de s!:prinl1b (x depth trail) (prog (w length) (cond ((and (fixp 
!*print!-level!*) (greaterp depth !*print!-level!*)) (return nil))) (setq 
length 0) top (cond ((and (atom x) (not (simple!-vector!-p x)) (not (gensymp 
x)) (not (hash!-table!-p x))) (return nil)) (t (cond ((setq w (gethash x 
!*prinl!-visited!-nodes!*)) (progn (cond ((and (equal w 0) (memq x trail)) (
progn (setq !*prinl!-index!* (plus !*prinl!-index!* 1)) (puthash x 
!*prinl!-visited!-nodes!* !*prinl!-index!*)))) (return nil))) (t (progn (
puthash x !*prinl!-visited!-nodes!* 0) (cond ((simple!-vector!-p x) (progn (
cond (!*print!-array!* (progn (setq length (upbv x)) (cond ((and (fixp 
!*print!-length!*) (lessp !*print!-length!* length)) (setq length 
!*print!-length!*))) (prog (i) (setq i 0) lab1004 (cond ((minusp (times 1 (
difference length i))) (return nil))) (s!:prinl1b (getv x i) (plus depth 1) (
cons x trail)) (setq i (plus i 1)) (go lab1004))))))) (t (cond ((
hash!-table!-p x) (s!:prinl1b (hashcontents x) (plus depth 1) (cons x trail))
) (t (cond ((not (atom x)) (progn (s!:prinl1b (car x) (plus depth 1) (cons x 
trail)) (cond ((and (fixp !*print!-length!*) (greaterp (setq length (plus 
length 1)) !*print!-length!*)) (return nil))) (setq trail (cons x trail)) (
setq x (cdr x)) (go top)))))))))))))))

(de s!:prinl2 (x depth) (cond ((and (fixp !*print!-level!*) (greaterp depth 
!*print!-level!*)) (princ "#")) (t (cond ((and (atom x) (not (
simple!-vector!-p x)) (not (gensymp x))) (progn (funcall !*prinl!-fn!* x))) (
t (prog (w length) (setq w (gethash x !*prinl!-visited!-nodes!*)) (cond ((not
(zerop w)) (progn (cond ((lessp w 0) (progn (princ "#") (princ (minus w)) (
princ "#") (return nil))) (t (progn (puthash x !*prinl!-visited!-nodes!* (
minus w)) (princ "#") (princ w) (princ "="))))))) (cond ((simple!-vector!-p x
) (progn (princ "%(") (cond (!*print!-array!* (progn (setq length (upbv x)) (
cond ((and (fixp !*print!-length!*) (lessp !*print!-length!* length)) (setq 
length !*print!-length!*))) (prog (i) (setq i 0) lab1005 (cond ((minusp (
times 1 (difference length i))) (return nil))) (progn (s!:prinl2 (getv x i) (
plus depth 1)) (cond ((not (equal i (upbv x))) (princ " ")))) (setq i (plus i
1)) (go lab1005)))) (t (princ "..."))) (princ ")") (return nil))) (t (cond (
(hash!-table!-p x) (progn (setq x (hashcontents x)) (cond ((null x) (princ 
"#H()")) (t (progn (setq w "#H(") (prog (var1007) (setq var1007 x) lab1006 (
cond ((null var1007) (return nil))) (prog (y) (setq y (car var1007)) (progn (
princ w) (setq w " ") (s!:prinl2 (car y) (plus depth 1)) (princ ":") (
s!:prinl2 (cdr y) (plus depth 1)))) (setq var1007 (cdr var1007)) (go lab1006)
) (princ ")")))))) (t (cond ((atom x) (return (funcall !*prinl!-fn!* x)))))))
) (princ "(") (setq length 0) loop (s!:prinl2 (car x) (plus depth 1)) (setq x
(cdr x)) (cond ((atom x) (progn (cond ((simple!-vector!-p x) (progn (princ 
" . %(") (cond (!*print!-array!* (progn (setq length (upbv x)) (cond ((and (
fixp !*print!-length!*) (lessp !*print!-length!* length)) (setq length 
!*print!-length!*))) (prog (i) (setq i 0) lab1008 (cond ((minusp (times 1 (
difference length i))) (return nil))) (progn (s!:prinl2 (getv x i) (plus 
depth 1)) (cond ((not (equal i (upbv x))) (princ " ")))) (setq i (plus i 1)) 
(go lab1008)))) (t (princ "..."))) (princ ")"))) (t (cond (x (progn (princ 
" . ") (funcall !*prinl!-fn!* x)))))) (return (princ ")"))))) (cond ((and (
fixp !*print!-length!*) (greaterp (setq length (plus length 1)) 
!*print!-length!*)) (return (princ " ...)")))) (setq w (gethash x 
!*prinl!-visited!-nodes!*)) (cond ((not (equal w 0)) (cond ((lessp w 0) (
progn (princ " . #") (princ (minus w)) (return (princ "#)")))) (t (progn (
princ " . ") (s!:prinl2 x (plus depth 1)) (return (princ ")")))))) (t (princ 
" "))) (go loop)))))))

(de printl (x) (progn (prinl x) (terpri) x))

(de printcl (x) (progn (princl x) (terpri) x))

(de princl (x) (s!:prinl0 x (function princ)))

(de prinl (x) (s!:prinl0 x (function prin)))

(de s!:format (dest fmt args) (prog (len c a res o) (cond ((not (null dest)) 
(progn (cond ((equal dest (quote t)) (setq o (wrs nil))) (t (setq o (wrs dest
))))))) (setq len (upbv fmt)) (prog (i) (setq i 0) lab1015 (cond ((minusp (
times 1 (difference len i))) (return nil))) (progn (setq c (schar fmt i)) (
cond ((equal c (quote !~)) (progn (setq i (plus i 1)) (setq c (char!-downcase
(schar fmt i))) (cond ((equal c (quote !%)) (cond ((null dest) (setq res (
cons !$eol!$ res))) (t (terpri)))) (t (cond ((equal c (quote !~)) (cond ((
null dest) (setq res (cons (quote !~) res))) (t (princ (quote !~))))) (t (
progn (cond ((null args) (setq a nil)) (t (progn (setq a (car args)) (setq 
args (cdr args))))) (cond ((equal c (quote !a)) (cond ((null dest) (prog (
var1010) (setq var1010 (explode2 a)) lab1009 (cond ((null var1010) (return 
nil))) (prog (k) (setq k (car var1010)) (setq res (cons k res))) (setq 
var1010 (cdr var1010)) (go lab1009))) (t (princ a)))) (t (cond ((equal c (
quote !s)) (cond ((null dest) (prog (var1012) (setq var1012 (explode a)) 
lab1011 (cond ((null var1012) (return nil))) (prog (k) (setq k (car var1012))
(setq res (cons k res))) (setq var1012 (cdr var1012)) (go lab1011))) (t (
prin a)))) (t (cond ((null dest) (prog (var1014) (setq var1014 (explode a)) 
lab1013 (cond ((null var1014) (return nil))) (prog (k) (setq k (car var1014))
(setq res (cons k res))) (setq var1014 (cdr var1014)) (go lab1013))) (t (
prin (list (quote !?!?!?) c a))))))))))))))) (t (progn (cond ((null dest) (
setq res (cons c res))) (t (princ c))))))) (setq i (plus i 1)) (go lab1015)) 
(cond ((null dest) (return (list2string (reversip res)))) (t (progn (wrs o) (
return nil))))))

(dm format (u !&optional env) (list (quote s!:format) (cadr u) (caddr u) (
cons (quote list) (cdddr u))))

(fluid (quote (s!:bn s!:bufferi s!:buffero s!:indblanks s!:indentlevel 
s!:initialblanks s!:lmar s!:pendingrpars s!:rmar s!:rparcount s!:stack)))

(global (quote (!*quotes !*pretty!-symmetric thin!*)))

(setq !*pretty!-symmetric t)

(setq !*quotes t)

(setq thin!* 5)

(remflag (quote (superprinm superprintm prettyprint tprettyprint)) (quote 
lose))

(de prettyprint (x) (progn (superprinm x (posn)) (terpri) nil))

(de tprettyprint (x) (progn (cond ((greaterp (posn) 6) (terpri))) (
prettyprint x)))

(de superprintm (x s!:lmar) (progn (superprinm x s!:lmar) (terpri) x))

(de superprinm (x s!:lmar) (prog (s!:stack s!:bufferi s!:buffero s!:bn 
s!:initialblanks s!:rmar s!:pendingrpars s!:indentlevel s!:indblanks 
s!:rparcount w) (setq s!:bufferi (setq s!:buffero (list nil))) (setq 
s!:initialblanks 0) (setq s!:rparcount 0) (setq s!:indblanks 0) (setq s!:rmar
(linelength nil)) (linelength 500) (cond ((lessp s!:rmar 25) (error 0 (list 
s!:rmar "Linelength too short for superprinting")))) (setq s!:bn 0) (setq 
s!:indentlevel 0) (cond ((geq (plus s!:lmar 20) s!:rmar) (setq s!:lmar (
difference s!:rmar 21)))) (setq w (posn)) (cond ((greaterp w s!:lmar) (progn 
(terpri) (setq w 0)))) (cond ((lessp w s!:lmar) (setq s!:initialblanks (
difference s!:lmar w)))) (s!:prindent x (plus s!:lmar 2)) (s!:overflow (quote
none)) (linelength s!:rmar) (return x)))

(dm s!:top (u !&optional v) (quote (car s!:stack)))

(dm s!:depth (u !&optional v) (list (quote car) (cadr u)))

(dm s!:indenting (u !&optional v) (list (quote cadr) (cadr u)))

(dm s!:blankcount (u !&optional v) (list (quote caddr) (cadr u)))

(dm s!:blanklist (u !&optional v) (list (quote cdddr) (cadr u)))

(dm s!:setindenting (u !&optional v) (list (quote rplaca) (list (quote cdr) (
cadr u)) (caddr u)))

(dm s!:setblankcount (u !&optional v) (list (quote rplaca) (list (quote cddr)
(cadr u)) (caddr u)))

(dm s!:setblanklist (u !&optional v) (list (quote rplacd) (list (quote cddr) 
(cadr u)) (caddr u)))

(dm s!:newframe (u !&optional v) (list (quote list) (cadr u) nil 0))

(dm s!:blankp (u !&optional v) (list (quote numberp) (list (quote car) (cadr 
u))))

(fluid (quote (s!:ppcontext!*)))

(de s!:prid (x n) (prog (s!:ppcontext!*) (setq s!:ppcontext!* (quote symbol))
(setq s!:rmar (difference s!:rmar 1)) (prog (var1017) (setq var1017 (explode
x)) lab1016 (cond ((null var1017) (return nil))) (prog (c) (setq c (car 
var1017)) (s!:putch c)) (setq var1017 (cdr var1017)) (go lab1016)) (setq 
s!:rmar (plus s!:rmar 1))))

(de s!:pridc (x n) (prog (var1019) (setq var1019 (explode2 x)) lab1018 (cond 
((null var1019) (return nil))) (prog (c) (setq c (car var1019)) (s!:putch c))
(setq var1019 (cdr var1019)) (go lab1018)))

(de s!:prstring (x n) (prog (s!:ppcontext!*) (setq s!:ppcontext!* (quote 
string)) (setq s!:rmar (difference s!:rmar 1)) (prog (var1021) (setq var1021 
(explode x)) lab1020 (cond ((null var1021) (return nil))) (prog (c) (setq c (
car var1021)) (s!:putch c)) (setq var1021 (cdr var1021)) (go lab1020)) (setq 
s!:rmar (plus s!:rmar 1))))

(de s!:prstringc (x n) (prog (var1023) (setq var1023 (explode2 x)) lab1022 (
cond ((null var1023) (return nil))) (prog (c) (setq c (car var1023)) (
s!:putch c)) (setq var1023 (cdr var1023)) (go lab1022)))

(de s!:prindent (x n) (cond ((atom x) (cond ((vectorp x) (prvector x n)) (t (
cond ((stringp x) (cond (!*pretty!-symmetric (s!:prstring x n)) (t (
s!:prstringc x n)))) (t (cond (!*pretty!-symmetric (s!:prid x n)) (t (
s!:pridc x n)))))))) (t (cond ((s!:quotep x) (progn (s!:putch (quote !')) (
s!:prindent (cadr x) (plus n 1)))) (t (prog (cx) (cond ((greaterp (times 4 n)
(times 3 s!:rmar)) (progn (s!:overflow (quote all)) (setq n (truncate n 8)) 
(cond ((greaterp s!:initialblanks n) (progn (setq s!:lmar (plus (difference 
s!:lmar s!:initialblanks) n)) (setq s!:initialblanks n))))))) (setq s!:stack 
(cons (s!:newframe n) s!:stack)) (s!:putch (cons (quote lpar) (s!:top))) (
setq cx (car x)) (s!:prindent cx (plus n 1)) (cond ((and (idp cx) (not (atom 
(cdr x)))) (setq cx (get cx (quote s!:ppformat)))) (t (setq cx nil))) (cond (
(and (equal cx 2) (atom (cddr x))) (setq cx nil))) (cond ((equal cx (quote 
prog)) (progn (s!:putch (quote ! )) (s!:prindent (car (setq x (cdr x))) (plus
n 2))))) (setq x (cdr x)) scan (cond ((atom x) (go outt))) (s!:finishpending
) (cond ((equal cx (quote prog)) (progn (s!:putblank) (s!:overflow s!:bufferi
) (cond ((atom (car x)) (progn (setq s!:lmar (setq s!:initialblanks (max (
difference s!:lmar 6) 0))) (s!:prindent (car x) (difference n 2)) (setq x (
cdr x)) (cond ((and (not (atom x)) (atom (car x))) (go scan))) (cond ((
greaterp (plus s!:lmar s!:bn) n) (s!:putblank)) (t (prog (i) (setq i (plus 
s!:lmar s!:bn)) lab1024 (cond ((minusp (times 1 (difference (difference n 1) 
i))) (return nil))) (s!:putch (quote ! )) (setq i (plus i 1)) (go lab1024))))
(cond ((atom x) (go outt)))))))) (t (cond ((numberp cx) (progn (setq cx (
difference cx 1)) (cond ((equal cx 0) (setq cx nil))) (s!:putch (quote ! ))))
(t (s!:putblank))))) (s!:prindent (car x) (plus n 2)) (setq x (cdr x)) (go 
scan) outt (cond ((not (null x)) (progn (s!:finishpending) (s!:putblank) (
s!:putch (quote !.)) (s!:putch (quote ! )) (s!:prindent x (plus n 5))))) (
s!:putch (cons (quote rpar) (difference n 2))) (cond ((and (equal (
s!:indenting (s!:top)) (quote indent)) (not (null (s!:blanklist (s!:top))))) 
(s!:overflow (car (s!:blanklist (s!:top))))) (t (s!:endlist (s!:top)))) (setq
s!:stack (cdr s!:stack))))))))

(de s!:explodes (x) (explode x))

(de s!:prvector (x n) (prog (bound) (setq bound (upbv x)) (setq s!:stack (
cons (s!:newframe n) s!:stack)) (s!:putch (cons (quote lsquare) (s!:top))) (
s!:prindent (getv x 0) (plus n 2)) (prog (i) (setq i 1) lab1025 (cond ((
minusp (times 1 (difference bound i))) (return nil))) (progn (s!:putch (quote
!,)) (s!:putblank) (s!:prindent (getv x i) (plus n 2))) (setq i (plus i 1)) 
(go lab1025)) (s!:putch (cons (quote rsquare) (difference n 2))) (s!:endlist 
(s!:top)) (setq s!:stack (cdr s!:stack))))

(de s!:putblank nil (prog nil (s!:putch (s!:top)) (s!:setblankcount (s!:top) 
(plus (s!:blankcount (s!:top)) 1)) (s!:setblanklist (s!:top) (cons s!:bufferi
(s!:blanklist (s!:top)))) (setq s!:indblanks (plus s!:indblanks 1))))

(de s!:endlist (l) (setq s!:pendingrpars (cons l s!:pendingrpars)))

(de s!:finishpending nil (progn (prog (var1029) (setq var1029 s!:pendingrpars
) lab1028 (cond ((null var1029) (return nil))) (prog (stackframe) (setq 
stackframe (car var1029)) (progn (cond ((neq (s!:indenting stackframe) (quote
indent)) (prog (var1027) (setq var1027 (s!:blanklist stackframe)) lab1026 (
cond ((null var1027) (return nil))) (prog (b) (setq b (car var1027)) (progn (
rplaca b (quote ! )) (setq s!:indblanks (difference s!:indblanks 1)))) (setq 
var1027 (cdr var1027)) (go lab1026)))) (s!:setblanklist stackframe t))) (setq
var1029 (cdr var1029)) (go lab1028)) (setq s!:pendingrpars nil)))

(de s!:quotep (x) (and !*quotes (not (atom x)) (equal (car x) (quote quote)) 
(not (atom (cdr x))) (null (cddr x))))

(put (quote prog) (quote s!:ppformat) (quote prog))

(put (quote lambda) (quote s!:ppformat) 1)

(put (quote lambdaq) (quote s!:ppformat) 1)

(put (quote setq) (quote s!:ppformat) 1)

(put (quote set) (quote s!:ppformat) 1)

(put (quote while) (quote s!:ppformat) 1)

(put (quote t) (quote s!:ppformat) 1)

(put (quote de) (quote s!:ppformat) 2)

(put (quote df) (quote s!:ppformat) 2)

(put (quote dm) (quote s!:ppformat) 2)

(put (quote defun) (quote s!:ppformat) 2)

(put (quote defmacro) (quote s!:ppformat) 2)

(put (quote foreach) (quote s!:ppformat) 4)

(de s!:putch (c) (prog nil (cond ((atom c) (setq s!:rparcount 0)) (t (cond ((
s!:blankp c) (progn (setq s!:rparcount 0) (go nocheck))) (t (cond ((equal (
car c) (quote rpar)) (progn (setq s!:rparcount (plus s!:rparcount 1)) (cond (
(greaterp s!:rparcount 4) (progn (s!:putch (quote ! )) (setq s!:rparcount 2))
)))) (t (setq s!:rparcount 0))))))) (prog nil lab1030 (cond ((null (geq (plus
s!:lmar s!:bn) s!:rmar)) (return nil))) (s!:overflow (quote more)) (go 
lab1030)) nocheck (setq s!:bufferi (cdr (rplacd s!:bufferi (list c)))) (setq 
s!:bn (plus s!:bn 1))))

(de s!:overflow (flg) (prog (c blankstoskip) (cond ((and (equal s!:indblanks 
0) (greaterp s!:initialblanks 2) (equal flg (quote more))) (progn (setq 
s!:initialblanks (difference s!:initialblanks 2)) (setq s!:lmar (difference 
s!:lmar 2)) (return (quote moved!-left))))) fblank (cond ((equal s!:bn 0) (
progn (cond ((not (equal flg (quote more))) (return (quote empty)))) (cond ((
atom (car s!:buffero)) (progn (cond ((equal s!:ppcontext!* (quote string)) (
progn (prin2 """_") (terpri) (prin2 "   """) (setq s!:lmar 0) (return (quote 
continued)))) (t (cond ((equal s!:ppcontext!* (quote symbol)) (progn (prin2 
"__") (terpri) (prin2 "   ") (setq s!:lmar 0) (return (quote continued)))) (t
(prin2 "\")))))))) (terpri) (setq s!:lmar 0) (return (quote continued)))) (t
(progn (spaces s!:initialblanks) (setq s!:initialblanks 0)))) (setq 
s!:buffero (cdr s!:buffero)) (setq s!:bn (difference s!:bn 1)) (setq s!:lmar 
(plus s!:lmar 1)) (setq c (car s!:buffero)) (cond ((atom c) (progn (prin2 c) 
(go fblank))) (t (cond ((s!:blankp c) (cond ((not (atom blankstoskip)) (progn
(prin2 (quote ! )) (setq s!:indblanks (difference s!:indblanks 1)) (cond ((
eq c (car blankstoskip)) (progn (rplacd blankstoskip (difference (cdr 
blankstoskip) 1)) (cond ((equal (cdr blankstoskip) 0) (setq blankstoskip t)))
))) (go fblank))) (t (go blankfound)))) (t (cond ((or (equal (car c) (quote 
lpar)) (equal (car c) (quote lsquare))) (progn (prin2 (get (car c) (quote 
s!:ppchar))) (cond ((equal flg (quote none)) (go fblank))) (setq c (cdr c)) (
cond ((not (null (s!:blanklist c))) (go fblank))) (cond ((greaterp (s!:depth 
c) s!:indentlevel) (progn (setq s!:indentlevel (s!:depth c)) (s!:setindenting
c (quote indent))))) (go fblank))) (t (cond ((or (equal (car c) (quote rpar)
) (equal (car c) (quote rsquare))) (progn (cond ((lessp (cdr c) 
s!:indentlevel) (setq s!:indentlevel (cdr c)))) (prin2 (get (car c) (quote 
s!:ppchar))) (go fblank))) (t (error 0 (list c "UNKNOWN TAG IN OVERFLOW")))))
))))) blankfound (cond ((eqcar (s!:blanklist c) s!:buffero) (s!:setblanklist 
c nil))) (setq s!:indblanks (difference s!:indblanks 1)) (cond ((greaterp (
s!:depth c) s!:indentlevel) (progn (cond ((equal flg (quote none)) (progn (
prin2 (quote ! )) (go fblank)))) (cond (blankstoskip (setq blankstoskip nil))
(t (progn (setq s!:indentlevel (s!:depth c)) (s!:setindenting c (quote 
indent)))))))) (cond ((greaterp (s!:blankcount c) (difference thin!* 1)) (
progn (setq blankstoskip (cons c (difference (s!:blankcount c) 2))) (
s!:setindenting c (quote thin)) (s!:setblankcount c 1) (setq s!:indentlevel (
difference (s!:depth c) 1)) (prin2 (quote ! )) (go fblank)))) (
s!:setblankcount c (difference (s!:blankcount c) 1)) (terpri) (setq s!:lmar (
setq s!:initialblanks (s!:depth c))) (cond ((eq s!:buffero flg) (return (
quote to!-flg)))) (cond ((or blankstoskip (not (equal flg (quote more)))) (go
fblank))) (return (quote more))))

(put (quote lpar) (quote s!:ppchar) (quote !())

(put (quote lsquare) (quote s!:ppchar) (quote ![))

(put (quote rpar) (quote s!:ppchar) (quote !)))

(put (quote rsquare) (quote s!:ppchar) (quote !]))

(de fetch!-url (url !&optional dest) (prog (a b c d e w) (setq a (open!-url 
url)) (cond ((null a) (return nil))) (cond (dest (progn (setq d (open dest (
quote output))) (cond ((null d) (progn (close a) (return (error 0 
"unable to open destination file"))))) (setq d (wrs d))))) (setq b (rds a)) (
setq w (linelength 500)) (prog nil lab1031 (cond ((null (not (equal (setq c (
readch)) !$eof!$))) (return nil))) (princ c) (go lab1031)) (linelength e) (
rds b) (close a) (cond (dest (close (wrs d))))))

(de bldmsg_temp_internal (fmt args) (prog (r a) (setq fmt (explodec fmt)) (
prog nil lab1034 (cond ((null fmt) (return nil))) (progn (cond ((eqcar fmt (
quote !%)) (progn (setq fmt (cdr fmt)) (setq a (car args)) (setq args (cdr 
args)) (cond ((or (eqcar fmt (quote !p)) (eqcar fmt (quote !P))) (setq a (
explode a))) (t (setq a (explodec a)))) (prog (var1033) (setq var1033 a) 
lab1032 (cond ((null var1033) (return nil))) (prog (c) (setq c (car var1033))
(setq r (cons c r))) (setq var1033 (cdr var1033)) (go lab1032)))) (t (setq r
(cons (car fmt) r)))) (setq fmt (cdr fmt))) (go lab1034)) (return (
list2string (reversip r)))))

(dm bldmsg (u) (list (quote bldmsg_temp_internal) (cadr u) (cons (quote list)
(cddr u))))

(flag (quote (bldmsg)) (quote variadic))


% end of file
