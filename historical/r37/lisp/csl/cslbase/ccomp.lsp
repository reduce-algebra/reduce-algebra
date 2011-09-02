
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


(global (quote (!*fastvector !*unsafecar)))

(flag (quote (fastvector unsafecar)) (quote switch))

(fluid (quote (C_file L_file O_file L_contents File_name)))

(dm c!:printf (u !&optional env) (list (quote c!:printf1) (cadr u) (cons (
quote list) (cddr u))))

(de c!:printf1 (fmt args) (prog (a c) (setq fmt (explode2 fmt)) (prog nil 
lab1000 (if (null fmt) (return nil)) (progn (setq c (car fmt)) (setq fmt (cdr
fmt)) (if (and (equal c (quote !\)) (or (equal (car fmt) (quote !n)) (equal 
(car fmt) (quote !N)))) (progn (terpri) (setq fmt (cdr fmt))) (if (and (equal
c (quote !\)) (or (equal (car fmt) (quote !q)) (equal (car fmt) (quote !Q)))
) (progn (princ (quote !")) (setq fmt (cdr fmt))) (if (equal c (quote !%)) (
progn (setq c (car fmt)) (if (null args) (setq a (quote missing_arg)) (setq a
(car args))) (if (or (equal c (quote !v)) (equal c (quote !V))) (if (flagp a
(quote c!:live_across_call)) (progn (princ "stack[") (princ (minus (get a (
quote c!:location)))) (princ "]")) (princ a)) (if (or (equal c (quote !a)) (
equal c (quote !A))) (prin a) (if (or (equal c (quote !t)) (equal c (quote !T
))) (ttab a) (princ a)))) (if args (setq args (cdr args))) (setq fmt (cdr fmt
))) (princ c))))) (go lab1000))))

(de c!:cspecform (x env) (error 0 (list "special form" x)))

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
) (function c!:cspecform)) (put (quote prog!*) (quote c!:code) (function 
c!:cspecform)) (put (quote prog1) (quote c!:code) (function c!:cspecform)) (
put (quote prog2) (quote c!:code) (function c!:cspecform)) (put (quote progn)
(quote c!:code) (function c!:cspecform)) (put (quote progv) (quote c!:code) 
(function c!:cspecform)) (put (quote quote) (quote c!:code) (function 
c!:cspecform)) (put (quote return) (quote c!:code) (function c!:cspecform)) (
put (quote return!-from) (quote c!:code) (function c!:cspecform)) (put (quote
setq) (quote c!:code) (function c!:cspecform)) (put (quote tagbody) (quote 
c!:code) (function c!:cspecform)) (put (quote the) (quote c!:code) (function 
c!:cspecform)) (put (quote throw) (quote c!:code) (function c!:cspecform)) (
put (quote unless) (quote c!:code) (function c!:cspecform)) (put (quote 
unwind!-protect) (quote c!:code) (function c!:cspecform)) (put (quote when) (
quote c!:code) (function c!:cspecform)))

(fluid (quote (current_procedure current_args current_block current_contents 
all_blocks registers stacklocs)))

(fluid (quote (available used)))

(setq available (setq used nil))

(de c!:reset_gensyms nil (progn (remflag used (quote c!:live_across_call)) (
remflag used (quote c!:visited)) (prog nil lab1001 (if (null used) (return 
nil)) (progn (remprop (car used) (quote c!:contents)) (remprop (car used) (
quote c!:why)) (remprop (car used) (quote c!:where_to)) (remprop (car used) (
quote c!:count)) (remprop (car used) (quote c!:live)) (remprop (car used) (
quote c!:clash)) (remprop (car used) (quote c!:chosen)) (remprop (car used) (
quote c!:location)) (if (plist (car used)) (prog (o) (setq o (wrs nil)) (
princ "+++++ ") (prin (car used)) (princ " ") (prin (plist (car used))) (
terpri) (wrs o))) (setq available (cons (car used) available)) (setq used (
cdr used))) (go lab1001))))

(de c!:my_gensym nil (prog (w) (if available (progn (setq w (car available)) 
(setq available (cdr available))) (setq w (gensym1 "v"))) (setq used (cons w 
used)) (if (plist w) (progn (princ "????? ") (prin w) (princ " => ") (prin (
plist w)) (terpri))) (return w)))

(de c!:newreg nil (prog (r) (setq r (c!:my_gensym)) (setq registers (cons r 
registers)) (return r)))

(de c!:startblock (s) (progn (setq current_block s) (setq current_contents 
nil)))

(de c!:outop (a b c d) (if current_block (setq current_contents (cons (list a
b c d) current_contents))))

(de c!:endblock (why where_to) (if current_block (progn (put current_block (
quote c!:contents) current_contents) (put current_block (quote c!:why) why) (
put current_block (quote c!:where_to) where_to) (setq all_blocks (cons 
current_block all_blocks)) (setq current_contents nil) (setq current_block 
nil))))

(de c!:cval_inner (x env) (prog (helper) (setq x (s!:improve x)) (if (atom x)
(return (c!:catom x env)) (if (eqcar (car x) (quote lambda)) (return (
c!:clambda (cadar x) (cons (quote progn) (cddar x)) (cdr x) env)) (if (setq 
helper (get (car x) (quote c!:code))) (return (funcall helper x env)) (if (
and (setq helper (get (car x) (quote c!:compile_macro))) (setq helper (
funcall helper x))) (return (c!:cval helper env)) (if (and (idp (car x)) (
setq helper (macro!-function (car x)))) (return (c!:cval (funcall helper x) 
env)) (return (c!:ccall (car x) (cdr x) env)))))))))

(de c!:cval (x env) (prog (r) (setq r (c!:cval_inner x env)) (if (and r (not 
(member!*!* r registers))) (error 0 (list r "not a register" x))) (return r))
)

(de c!:clambda (bvl body args env) (prog (w fluids env1) (setq env1 (car env)
) (setq w (prog (var1003 var1004) (setq var1003 args) lab1002 (if (null 
var1003) (return (reversip var1004))) (prog (a) (setq a (car var1003)) (setq 
var1004 (cons (c!:cval a env) var1004))) (setq var1003 (cdr var1003)) (go 
lab1002))) (prog (var1006) (setq var1006 bvl) lab1005 (if (null var1006) (
return nil)) (prog (v) (setq v (car var1006)) (progn (if (globalp v) (prog (
oo) (setq oo (wrs nil)) (princ "+++++ ") (prin v) (princ 
" converted from GLOBAL to FLUID") (terpri) (wrs oo) (unglobal (list v)) (
fluid (list v)))) (if (fluidp v) (progn (setq fluids (cons (cons v (c!:newreg
)) fluids)) (flag (list (cdar fluids)) (quote c!:live_across_call)) (setq 
env1 (cons (cons (quote c!:dummy!:name) (cdar fluids)) env1)) (c!:outop (
quote ldrglob) (cdar fluids) v (c!:find_literal v)) (c!:outop (quote strglob)
(car w) v (c!:find_literal v))) (progn (setq env1 (cons (cons v (c!:newreg))
env1)) (c!:outop (quote movr) (cdar env1) nil (car w)))) (setq w (cdr w)))) 
(setq var1006 (cdr var1006)) (go lab1005)) (if fluids (c!:outop (quote 
fluidbind) nil nil fluids)) (setq env (cons env1 (append fluids (cdr env)))) 
(setq w (c!:cval body env)) (prog (var1008) (setq var1008 fluids) lab1007 (if
(null var1008) (return nil)) (prog (v) (setq v (car var1008)) (c!:outop (
quote strglob) (cdr v) (car v) (c!:find_literal (car v)))) (setq var1008 (cdr
var1008)) (go lab1007)) (return w)))

(de c!:locally_bound (x env) (atsoc x (car env)))

(flag (quote (nil t)) (quote c!:constant))

(fluid (quote (literal_vector)))

(de c!:find_literal (x) (prog (n w) (setq w literal_vector) (setq n 0) (prog 
nil lab1009 (if (null (and w (not (equal (car w) x)))) (return nil)) (progn (
setq n (plus n 1)) (setq w (cdr w))) (go lab1009)) (if (null w) (setq 
literal_vector (append literal_vector (list x)))) (return n)))

(de c!:catom (x env) (prog (v w) (setq v (c!:newreg)) (if (and (idp x) (setq 
w (c!:locally_bound x env))) (c!:outop (quote movr) v nil (cdr w)) (if (or (
null x) (equal x (quote t)) (c!:small_number x)) (c!:outop (quote movk1) v 
nil x) (if (or (not (idp x)) (flagp x (quote c!:constant))) (c!:outop (quote 
movk) v x (c!:find_literal x)) (c!:outop (quote ldrglob) v x (c!:find_literal
x))))) (return v)))

(de c!:cjumpif (x env d1 d2) (prog (helper r) (setq x (s!:improve x)) (if (
and (atom x) (or (not (idp x)) (and (flagp x (quote c!:constant)) (not (
c!:locally_bound x env))))) (c!:endblock (quote goto) (list (if x d1 d2))) (
if (and (not (atom x)) (setq helper (get (car x) (quote c!:ctest)))) (return 
(funcall helper x env d1 d2)) (progn (setq r (c!:cval x env)) (c!:endblock (
list (quote ifnull) r) (list d2 d1)))))))

(fluid (quote (current)))

(de c!:ccall (fn args env) (c!:ccall1 fn args env))

(fluid (quote (visited)))

(de c!:has_calls (a b) (prog (visited) (return (c!:has_calls_1 a b))))

(de c!:has_calls_1 (a b) (if (or (equal a b) (not (atom a)) (memq a visited))
nil (prog (has_call) (setq visited (cons a visited)) (prog (var1011) (setq 
var1011 (get a (quote c!:contents))) lab1010 (if (null var1011) (return nil))
(prog (z) (setq z (car var1011)) (if (eqcar z (quote call)) (setq has_call t
))) (setq var1011 (cdr var1011)) (go lab1010)) (if has_call (return (prog (
visited) (return (c!:can_reach a b))))) (prog (var1013) (setq var1013 (get a 
(quote c!:where_to))) lab1012 (if (null var1013) (return nil)) (prog (d) (
setq d (car var1013)) (if (c!:has_calls_1 d b) (setq has_call t))) (setq 
var1013 (cdr var1013)) (go lab1012)) (return has_call))))

(de c!:can_reach (a b) (if (equal a b) t (if (or (not (atom a)) (memq a 
visited)) nil (progn (setq visited (cons a visited)) (c!:any_can_reach (get a
(quote c!:where_to)) b)))))

(de c!:any_can_reach (l b) (if (null l) nil (if (c!:can_reach (car l) b) t (
c!:any_can_reach (cdr l) b))))

(de c!:pareval (args env) (prog (tasks tasks1 merge split r) (setq tasks (
prog (var1015 var1016) (setq var1015 args) lab1014 (if (null var1015) (return
(reversip var1016))) (prog (a) (setq a (car var1015)) (setq var1016 (cons (
cons (c!:my_gensym) (c!:my_gensym)) var1016))) (setq var1015 (cdr var1015)) (
go lab1014))) (setq split (c!:my_gensym)) (c!:endblock (quote goto) (list 
split)) (prog (var1018) (setq var1018 args) lab1017 (if (null var1018) (
return nil)) (prog (a) (setq a (car var1018)) (prog (s) (setq s (car tasks)) 
(setq tasks (cdr tasks)) (c!:startblock (car s)) (setq r (cons (c!:cval a env
) r)) (c!:endblock (quote goto) (list (cdr s))) (if (c!:has_calls (car s) (
cdr s)) (setq tasks1 (cons s tasks1)) (setq merge (cons s merge))))) (setq 
var1018 (cdr var1018)) (go lab1017)) (prog (var1020) (setq var1020 tasks1) 
lab1019 (if (null var1020) (return nil)) (prog (z) (setq z (car var1020)) (
setq merge (cons z merge))) (setq var1020 (cdr var1020)) (go lab1019)) (prog 
(var1022) (setq var1022 merge) lab1021 (if (null var1022) (return nil)) (prog
(v) (setq v (car var1022)) (progn (c!:startblock split) (c!:endblock (quote 
goto) (list (car v))) (setq split (cdr v)))) (setq var1022 (cdr var1022)) (go
lab1021)) (c!:startblock split) (return (reversip r))))

(de c!:ccall1 (fn args env) (prog (tasks merge r val) (setq fn (list fn (cdr 
env))) (setq val (c!:newreg)) (if (null args) (c!:outop (quote call) val nil 
fn) (if (null (cdr args)) (c!:outop (quote call) val (list (c!:cval (car args
) env)) fn) (progn (setq r (c!:pareval args env)) (c!:outop (quote call) val 
r fn)))) (c!:outop (quote reloadenv) (quote env) nil nil) (return val)))

(fluid (quote (restart_label reloadenv does_call current_c_name)))

(fluid (quote (proglabs blockstack)))

(de c!:cfndef (current_procedure current_c_name argsbody) (prog (env n w 
current_args current_block restart_label current_contents all_blocks 
entrypoint exitpoint args1 registers stacklocs literal_vector reloadenv 
does_call blockstack proglabs checksum args body) (setq checksum (md60 
argsbody)) (setq args (car argsbody)) (setq body (cdr argsbody)) (if (atom 
body) (setq body nil) (if (atom (cdr body)) (setq body (car body)) (setq body
(cons (quote progn) body)))) (print (list current_procedure current_c_name 
args body)) (c!:reset_gensyms) (wrs C_file) (linelength 200) (c!:printf 
"\n\n/* Code for %a */\n\n" current_procedure) (c!:find_literal 
current_procedure) (setq current_args args) (prog (var1024) (setq var1024 
args) lab1023 (if (null var1024) (return nil)) (prog (v) (setq v (car var1024
)) (if (or (equal v (quote !&optional)) (equal v (quote !&rest))) (error 0 
"&optional and &rest not supported by this compiler (yet)") (if (globalp v) (
prog (oo) (setq oo (wrs nil)) (princ "+++++ ") (prin v) (princ 
" converted from GLOBAL to FLUID") (terpri) (wrs oo) (unglobal (list v)) (
fluid (list v)) (setq n (cons (cons v (c!:my_gensym)) n))) (if (fluidp v) (
setq n (cons (cons v (c!:my_gensym)) n)))))) (setq var1024 (cdr var1024)) (go
lab1023)) (if !*r2i (setq body (s!:r2i current_procedure args body))) (setq 
restart_label (c!:my_gensym)) (setq body (list (quote c!:private_tagbody) 
restart_label body)) (if n (progn (setq body (list (list (quote return) body)
)) (setq args (subla n args)) (prog (var1026) (setq var1026 n) lab1025 (if (
null var1026) (return nil)) (prog (v) (setq v (car var1026)) (setq body (cons
(list (quote setq) (car v) (cdr v)) body))) (setq var1026 (cdr var1026)) (go
lab1025)) (setq body (cons (quote prog) (cons (prog (var1028 var1029) (setq 
var1028 (reverse n)) lab1027 (if (null var1028) (return (reversip var1029))) 
(prog (v) (setq v (car var1028)) (setq var1029 (cons (car v) var1029))) (setq
var1028 (cdr var1028)) (go lab1027)) body))))) (c!:printf 
"static Lisp_Object ") (if (or (null args) (geq (length args) 3)) (c!:printf 
"MS_CDECL ")) (c!:printf "%s(Lisp_Object env" current_c_name) (if (or (null 
args) (geq (length args) 3)) (c!:printf ", int nargs")) (setq n t) (setq env 
nil) (prog (var1031) (setq var1031 args) lab1030 (if (null var1031) (return 
nil)) (prog (x) (setq x (car var1031)) (prog (aa) (c!:printf ",") (if n (
progn (c!:printf "\n                        ") (setq n nil)) (setq n t)) (
setq aa (c!:my_gensym)) (setq env (cons (cons x aa) env)) (setq registers (
cons aa registers)) (setq args1 (cons aa args1)) (c!:printf " Lisp_Object %s"
aa))) (setq var1031 (cdr var1031)) (go lab1030)) (if (or (null args) (geq (
length args) 3)) (c!:printf ", ...")) (c!:printf ")\n{\n") (c!:startblock (
setq entrypoint (c!:my_gensym))) (setq exitpoint current_block) (c!:endblock 
(quote goto) (list (list (c!:cval body (cons env nil))))) (
c!:optimise_flowgraph entrypoint all_blocks env (cons (length args) 
current_procedure) args1) (c!:printf "}\n\n") (wrs O_file) (setq L_contents (
cons (cons current_procedure (cons literal_vector checksum)) L_contents)) (
return nil)))

(flag (quote (rds deflist flag fluid global remprop remflag unfluid unglobal 
dm carcheck C!-end)) (quote eval))

(flag (quote (rds)) (quote ignore))

(fluid (quote (!*backtrace)))

(de c!:ccompilesupervisor nil (prog (u w) top (setq u (errorset (quote (read)
) t !*backtrace)) (if (atom u) (return nil)) (setq u (car u)) (if (equal u 
!$eof!$) (return nil)) (if (atom u) (go top) (if (eqcar u (quote C!-end)) (
return (apply (quote C!-end) nil)) (if (eqcar u (quote rdf)) (progn (setq w (
open (setq u (eval (cadr u))) (quote input))) (if w (progn (terpri) (princ 
"Reading file ") (print u) (setq w (rds w)) (c!:ccompilesupervisor) (princ 
"End of file ") (print u) (close (rds w))) (progn (princ 
"Failed to open file ") (print u)))) (c!:ccmpout1 u)))) (go top)))

(global (quote (c!:char_mappings)))

(setq c!:char_mappings (quote ((!  . !A) (!! . !B) (!# . !C) (!$ . !D) (!% . 
!E) (!^ . !F) (!& . !G) (!* . !H) (!( . !I) (!) . !J) (!- . !K) (!+ . !L) (!=
 . !M) (!\ . !N) (!| . !O) (!, . !P) (!. . !Q) (!< . !R) (!> . !S) (!: . !T) 
(!; . !U) (!/ . !V) (!? . !W) (!~ . !X) (!` . !Y))))

(de c!:inv_name (n) (prog (r w) (setq r (quote (_ !C !C !"))) (prog (var1033)
(setq var1033 (explode2 n)) lab1032 (if (null var1033) (return nil)) (prog (
c) (setq c (car var1033)) (progn (if (equal c (quote _)) (setq r (cons (quote
_) r)) (if (or (liter c) (digit c)) (setq r (cons c r)) (if (setq w (atsoc c
c!:char_mappings)) (setq r (cons (cdr w) r)) (setq r (cons (quote !Z) r)))))
)) (setq var1033 (cdr var1033)) (go lab1032)) (setq r (cons (quote !") r)) (
return (compress (reverse r)))))

(fluid (quote (defnames pending_functions)))

(de c!:ccmpout1 (u) (prog (pending_functions) (setq pending_functions (list u
)) (prog nil lab1034 (if (null pending_functions) (return nil)) (progn (setq 
u (car pending_functions)) (setq pending_functions (cdr pending_functions)) (
c!:ccmpout1a u)) (go lab1034))))

(de c!:ccmpout1a (u) (prog (w) (if (atom u) (return nil) (if (eqcar u (quote 
progn)) (progn (prog (var1036) (setq var1036 (cdr u)) lab1035 (if (null 
var1036) (return nil)) (prog (v) (setq v (car var1036)) (c!:ccmpout1a v)) (
setq var1036 (cdr var1036)) (go lab1035)) (return nil)) (if (eqcar u (quote 
C!-end)) nil (if (or (flagp (car u) (quote eval)) (and (equal (car u) (quote 
setq)) (not (atom (caddr u))) (flagp (caaddr u) (quote eval)))) (errorset u t
!*backtrace))))) (if (eqcar u (quote rdf)) (prog nil (setq w (open (setq u (
eval (cadr u))) (quote input))) (if w (progn (princ "Reading file ") (print u
) (setq w (rds w)) (c!:ccompilesupervisor) (princ "End of file ") (print u) (
close (rds w))) (progn (princ "Failed to open file ") (print u)))) (if (eqcar
u (quote de)) (progn (setq u (cdr u)) (setq defnames (cons (list (car u) (
c!:inv_name (car u)) (length (cadr u))) defnames)) (if (neq (posn) 0) (terpri
)) (princ "Compiling ") (prin (caar defnames)) (princ " ... ") (c!:cfndef (
caar defnames) (cadar defnames) (cdr u)) (terpri))))))

(fluid (quote (!*defn dfprint!* dfprintsave)))

(de c!:concat (a b) (compress (cons (quote !") (append (explode2 a) (append (
explode2 b) (quote (!")))))))

(de c!:ccompilestart (name !&optional dir) (prog (o d w) (setq File_name name
) (if dir (setq name (c!:concat dir (c!:concat "/" name)))) (setq C_file (
open (c!:concat name ".c") (quote output))) (setq L_file (c!:concat name 
".lsp")) (setq L_contents nil) (setq o (reverse (explode (date)))) (prog (i) 
(setq i 1) lab1037 (if (minusp (times 1 (difference 5 i))) (return nil)) (
progn (setq d (cons (car o) d)) (setq o (cdr o))) (setq i (plus i 1)) (go 
lab1037)) (setq d (cons (quote !-) d)) (setq o (cdddr (cdddr (cddddr o)))) (
setq w o) (setq o (cdddr o)) (setq d (cons (caddr o) (cons (cadr o) (cons (
car o) d)))) (setq d (compress (cons (quote !") (cons (cadr w) (cons (car w) 
(cons (quote !-) d)))))) (setq O_file (wrs C_file)) (setq defnames nil) (
c!:printf "\n/* %s.c%tMachine generated C code */\n\n" name 25) (c!:printf 
"/* Signature: 00000000 %s */\n\n" d) (c!:printf "#include <stdarg.h>\n") (
c!:printf "#include <string.h>\n") (c!:printf "#include <ctype.h>\n\n") (
c!:printf "#include \qmachine.h\q\n") (c!:printf "#include \qtags.h\q\n") (
c!:printf "#include \qcslerror.h\q\n") (c!:printf "#include \qexterns.h\q\n")
(c!:printf "#include \qarith.h\q\n") (c!:printf 
"#include \qentries.h\q\n\n\n") (wrs O_file) (return nil)))

(de C!-end nil (prog (checksum c1 c2 c3) (wrs C_file) (c!:printf 
"\n\nsetup_type const %s_setup[] =\n{\n" File_name) (setq defnames (reverse 
defnames)) (prog nil lab1038 (if (null defnames) (return nil)) (prog (name 
nargs f1 f2 cast fn) (setq name (caar defnames)) (setq f1 (cadar defnames)) (
setq nargs (caddar defnames)) (setq cast "(n_args *)") (if (equal nargs 1) (
progn (setq f2 (quote !t!o!o_!m!a!n!y_1)) (setq cast "") (setq fn (quote 
!w!r!o!n!g_!n!o_1))) (if (equal nargs 2) (progn (setq f2 f1) (setq f1 (quote 
!t!o!o_!f!e!w_2)) (setq cast "") (setq fn (quote !w!r!o!n!g_!n!o_2))) (progn 
(setq fn f1) (setq f1 (quote !w!r!o!n!g_!n!o_!n!a)) (setq f2 (quote 
!w!r!o!n!g_!n!o_!n!b))))) (c!:printf "    {\q%s\q,%t%s,%t%s,%t%s%s},\n" name 
32 f1 48 f2 63 cast fn) (setq defnames (cdr defnames))) (go lab1038)) (setq 
c3 (setq checksum (md60 L_contents))) (setq c1 (remainder c3 10000000)) (setq
c3 (quotient c3 10000000)) (setq c2 (remainder c3 10000000)) (setq c3 (
quotient c3 10000000)) (setq checksum (list!-to!-string (append (explodec c3)
(cons (quote ! ) (append (explodec c2) (cons (quote ! ) (explodec c1))))))) 
(c!:printf "    {NULL, (one_args *)%a, (two_args *)%a, 0}\n};\n\n" (
list!-to!-string (explodec File_name)) checksum) (c!:printf 
"/* end of generated code */\n") (close C_file) (setq L_file (open L_file (
quote output))) (wrs L_file) (linelength 72) (terpri) (princ "% ") (princ 
File_name) (princ ".lsp") (ttab 20) (princ "Machine generated Lisp") (terpri)
(terpri) (princ "(c!:install ") (princ (quote !")) (princ File_name) (princ 
(quote !")) (princ " ") (princ checksum) (printc ")") (terpri) (prog (var1040
) (setq var1040 (reverse L_contents)) lab1039 (if (null var1040) (return nil)
) (prog (x) (setq x (car var1040)) (progn (princ "(c!:install '") (prin (car 
x)) (princ " '") (prin (cadr x)) (princ " ") (prin (cddr x)) (princ ")") (
terpri) (terpri))) (setq var1040 (cdr var1040)) (go lab1039)) (terpri) (princ
"% End of generated Lisp code") (terpri) (terpri) (setq L_contents nil) (wrs
O_file) (close L_file) (setq !*defn nil) (setq dfprint!* dfprintsave)))

(put (quote C!-end) (quote stat) (quote endstat))

(de C!-compile (u) (prog nil (terpri) (princ "C!-COMPILE ") (prin u) (princ 
": IN files;  or type in expressions") (terpri) (princ 
"When all done, execute C!-END;") (terpri) (verbos nil) (c!:ccompilestart (
car u)) (setq dfprintsave dfprint!*) (setq dfprint!* (quote c!:ccmpout1)) (
setq !*defn t) (if (getd (quote begin)) (return nil)) (c!:ccompilesupervisor)
))

(put (quote C!-compile) (quote stat) (quote rlis))

(de c!:print_opcode (s depth) (prog (op r1 r2 r3 helper) (setq op (car s)) (
setq r1 (cadr s)) (setq r2 (caddr s)) (setq r3 (cadddr s)) (setq helper (get 
op (quote c!:opcode_printer))) (if helper (funcall helper op r1 r2 r3 depth) 
(progn (prin s) (terpri)))))

(de c!:print_exit_condition (why where_to depth) (prog (helper lab1 drop1 
lab2 drop2 negate) (if (equal why (quote goto)) (progn (setq where_to (car 
where_to)) (if (atom where_to) (progn (c!:printf "    goto %s;\n" where_to) (
c!:display_flowgraph where_to depth t)) (progn (c!:printf "    ") (c!:pgoto 
where_to depth))) (return nil)) (if (eqcar (car why) (quote call)) (return (
prog (args locs g w) (if (setq w (get (cadar why) (quote c!:direct_entrypoint
))) (progn (prog (var1042) (setq var1042 (cdr why)) lab1041 (if (null var1042
) (return nil)) (prog (a) (setq a (car var1042)) (if (flagp a (quote 
c!:live_across_call)) (progn (if (null g) (c!:printf "    {\n")) (setq g (
c!:my_gensym)) (c!:printf "        Lisp_Object %s = %v;\n" g a) (setq args (
cons g args))) (setq args (cons a args)))) (setq var1042 (cdr var1042)) (go 
lab1041)) (if (neq depth 0) (progn (if g (c!:printf "    ")) (c!:printf 
"    popv(%s);\n" depth))) (if g (c!:printf "    ")) (c!:printf 
"    return %s(" (cdr w)) (setq args (reversip args)) (if args (progn (
c!:printf "%v" (car args)) (prog (var1044) (setq var1044 (cdr args)) lab1043 
(if (null var1044) (return nil)) (prog (a) (setq a (car var1044)) (c!:printf 
", %v" a)) (setq var1044 (cdr var1044)) (go lab1043)))) (c!:printf ");\n") (
if g (c!:printf "    }\n"))) (if (setq w (get (cadar why) (quote 
c!:c_entrypoint))) (progn (prog (var1046) (setq var1046 (cdr why)) lab1045 (
if (null var1046) (return nil)) (prog (a) (setq a (car var1046)) (if (flagp a
(quote c!:live_across_call)) (progn (if (null g) (c!:printf "    {\n")) (
setq g (c!:my_gensym)) (c!:printf "        Lisp_Object %s = %v;\n" g a) (setq
args (cons g args))) (setq args (cons a args)))) (setq var1046 (cdr var1046)
) (go lab1045)) (if (neq depth 0) (c!:printf "        popv(%s);\n" depth)) (
c!:printf "        return %s(nil" w) (if (or (null args) (geq (length args) 3
)) (c!:printf ", %s" (length args))) (prog (var1048) (setq var1048 (reversip 
args)) lab1047 (if (null var1048) (return nil)) (prog (a) (setq a (car 
var1048)) (c!:printf ", %v" a)) (setq var1048 (cdr var1048)) (go lab1047)) (
c!:printf ");\n") (if g (c!:printf "    }\n"))) (prog (nargs) (setq nargs (
length (cdr why))) (c!:printf "    {\n") (prog (var1050) (setq var1050 (cdr 
why)) lab1049 (if (null var1050) (return nil)) (prog (a) (setq a (car var1050
)) (if (flagp a (quote c!:live_across_call)) (progn (setq g (c!:my_gensym)) (
c!:printf "        Lisp_Object %s = %v;\n" g a) (setq args (cons g args))) (
setq args (cons a args)))) (setq var1050 (cdr var1050)) (go lab1049)) (if (
neq depth 0) (c!:printf "        popv(%s);\n" depth)) (c!:printf 
"        fn = elt(env, %s); /* %a */\n" (c!:find_literal (cadar why)) (cadar 
why)) (if (equal nargs 1) (c!:printf "        return (*qfn1(fn))(qenv(fn)") (
if (equal nargs 2) (c!:printf "        return (*qfn2(fn))(qenv(fn)") (
c!:printf "        return (*qfnn(fn))(qenv(fn), %s" nargs))) (prog (var1052) 
(setq var1052 (reversip args)) lab1051 (if (null var1052) (return nil)) (prog
(a) (setq a (car var1052)) (c!:printf ", %s" a)) (setq var1052 (cdr var1052)
) (go lab1051)) (c!:printf ");\n    }\n")))) (return nil))))) (setq lab1 (car
where_to)) (setq drop1 (and (atom lab1) (not (flagp lab1 (quote c!:visited))
))) (setq lab2 (cadr where_to)) (setq drop2 (and (atom lab2) (not (flagp 
drop2 (quote c!:visited))))) (if (and drop2 (equal (get lab2 (quote c!:count)
) 1)) (progn (setq where_to (list lab2 lab1)) (setq drop1 t)) (if drop1 (setq
negate t))) (setq helper (get (car why) (quote c!:exit_helper))) (if (null 
helper) (error 0 (list "Bad exit condition" why))) (c!:printf "    if (") (if
negate (progn (c!:printf "!(") (funcall helper (cdr why) depth) (c!:printf 
")")) (funcall helper (cdr why) depth)) (c!:printf ") ") (if (not drop1) (
progn (c!:pgoto (car where_to) depth) (c!:printf "    else "))) (c!:pgoto (
cadr where_to) depth) (if (atom (car where_to)) (c!:display_flowgraph (car 
where_to) depth drop1)) (if (atom (cadr where_to)) (c!:display_flowgraph (
cadr where_to) depth nil))))

(de c!:pmovr (op r1 r2 r3 depth) (c!:printf "    %v = %v;\n" r1 r3))

(put (quote movr) (quote c!:opcode_printer) (function c!:pmovr))

(de c!:pmovk (op r1 r2 r3 depth) (c!:printf 
"    %v = elt(env, %s); /* %a */\n" r1 r3 r2))

(put (quote movk) (quote c!:opcode_printer) (function c!:pmovk))

(de c!:pmovk1 (op r1 r2 r3 depth) (if (null r3) (c!:printf "    %v = nil;\n" 
r1) (if (equal r3 (quote t)) (c!:printf "    %v = lisp_true;\n" r1) (
c!:printf "    %v = (Lisp_Object)%s; /* %a */\n" r1 (plus (times 16 r3) 1) r3
))))

(put (quote movk1) (quote c!:opcode_printer) (function c!:pmovk1))

(de c!:preloadenv (op r1 r2 r3 depth) (c!:printf "    env = stack[%s];\n" (
minus reloadenv)))

(put (quote reloadenv) (quote c!:opcode_printer) (function c!:preloadenv))

(de c!:pldrglob (op r1 r2 r3 depth) (c!:printf 
"    %v = qvalue(elt(env, %s)); /* %a */\n" r1 r3 r2))

(put (quote ldrglob) (quote c!:opcode_printer) (function c!:pldrglob))

(de c!:pstrglob (op r1 r2 r3 depth) (c!:printf 
"    qvalue(elt(env, %s)) = %v; /* %a */\n" r3 r1 r2))

(put (quote strglob) (quote c!:opcode_printer) (function c!:pstrglob))

(de c!:pnilglob (op r1 r2 r3 depth) (c!:printf 
"    qvalue(elt(env, %s)) = nil; /* %a */\n" r3 r2))

(put (quote nilglob) (quote c!:opcode_printer) (function c!:pnilglob))

(de c!:pnull (op r1 r2 r3 depth) (c!:printf 
"    %v = (%v == nil ? lisp_true : nil);\n" r1 r3))

(put (quote null) (quote c!:opcode_printer) (function c!:pnull))

(put (quote not) (quote c!:opcode_printer) (function c!:pnull))

(flag (quote (null not)) (quote c!:uses_nil))

(de c!:pfastget (op r1 r2 r3 depth) (progn (c!:printf 
"    if (!symbolp(%v)) %v = nil;\n" r2 r1) (c!:printf 
"    else { %v = qfastgets(%v);\n" r1 r2) (c!:printf 
"           if (%v != nil) { %v = elt(%v, %s); /* %s */\n" r1 r1 r1 (car r3) 
(cdr r3)) (c!:printf "#ifdef RECORD_GET\n") (c!:printf 
"             if (%v != SPID_NOPROP)\n" r1) (c!:printf 
"                record_get(elt(fastget_names, %s), 1);\n" (car r3)) (
c!:printf "             else record_get(elt(fastget_names, %s), 0),\n" (car 
r3)) (c!:printf "                %v = nil; }\n" r1) (c!:printf 
"           else record_get(elt(fastget_names, %s), 0); }\n" (car r3)) (
c!:printf "#else\n") (c!:printf 
"             if (%v == SPID_NOPROP) %v = nil; }}\n" r1 r1) (c!:printf 
"#endif\n")))

(put (quote fastget) (quote c!:opcode_printer) (function c!:pfastget))

(flag (quote (fastget)) (quote c!:uses_nil))

(de c!:pfastflag (op r1 r2 r3 depth) (progn (c!:printf 
"    if (!symbolp(%v)) %v = nil;\n" r2 r1) (c!:printf 
"    else { %v = qfastgets(%v);\n" r1 r2) (c!:printf 
"           if (%v != nil) { %v = elt(%v, %s); /* %s */\n" r1 r1 r1 (car r3) 
(cdr r3)) (c!:printf "#ifdef RECORD_GET\n") (c!:printf 
"             if (%v == SPID_NOPROP)\n" r1) (c!:printf 
"                record_get(elt(fastget_names, %s), 0),\n" (car r3)) (
c!:printf "                %v = nil;\n" r1) (c!:printf 
"             else record_get(elt(fastget_names, %s), 1),\n" (car r3)) (
c!:printf "                %v = lisp_true; }\n" r1) (c!:printf 
"           else record_get(elt(fastget_names, %s), 0); }\n" (car r3)) (
c!:printf "#else\n") (c!:printf 
"             if (%v == SPID_NOPROP) %v = nil; else %v = lisp_true; }}\n" r1 
r1 r1) (c!:printf "#endif\n")))

(put (quote fastflag) (quote c!:opcode_printer) (function c!:pfastflag))

(flag (quote (fastflag)) (quote c!:uses_nil))

(de c!:pcar (op r1 r2 r3 depth) (prog nil (if (not !*unsafecar) (progn (
c!:printf "    if (!car_legal(%v)) " r3) (c!:pgoto (c!:find_error_label (list
(quote car) r3) r2 depth) depth))) (c!:printf "    %v = qcar(%v);\n" r1 r3))
)

(put (quote car) (quote c!:opcode_printer) (function c!:pcar))

(de c!:pcdr (op r1 r2 r3 depth) (prog nil (if (not !*unsafecar) (progn (
c!:printf "    if (!car_legal(%v)) " r3) (c!:pgoto (c!:find_error_label (list
(quote cdr) r3) r2 depth) depth))) (c!:printf "    %v = qcdr(%v);\n" r1 r3))
)

(put (quote cdr) (quote c!:opcode_printer) (function c!:pcdr))

(de c!:pqcar (op r1 r2 r3 depth) (c!:printf "    %v = qcar(%v);\n" r1 r3))

(put (quote qcar) (quote c!:opcode_printer) (function c!:pqcar))

(de c!:pqcdr (op r1 r2 r3 depth) (c!:printf "    %v = qcdr(%v);\n" r1 r3))

(put (quote qcdr) (quote c!:opcode_printer) (function c!:pqcdr))

(de c!:patom (op r1 r2 r3 depth) (c!:printf 
"    %v = (!consp(%v) ? lisp_true : nil);\n" r1 r3))

(put (quote atom) (quote c!:opcode_printer) (function c!:patom))

(de c!:pnumberp (op r1 r2 r3 depth) (c!:printf 
"    %v = (is_number(%v) ? lisp_true : nil);\n" r1 r3))

(put (quote numberp) (quote c!:opcode_printer) (function c!:pnumberp))

(de c!:pfixp (op r1 r2 r3 depth) (c!:printf "    %v = integerp(%v);\n" r1 r3)
)

(put (quote fixp) (quote c!:opcode_printer) (function c!:pfixp))

(de c!:piminusp (op r1 r2 r3 depth) (c!:printf 
"    %v = ((int32)(%v) < 0 ? lisp_true : nil);\n" r1 r3))

(put (quote iminusp) (quote c!:opcode_printer) (function c!:piminusp))

(de c!:pilessp (op r1 r2 r3 depth) (c!:printf 
"    %v = ((int32)%v < (int32)%v) ? lisp_true : nil;\n" r1 r2 r3))

(put (quote ilessp) (quote c!:opcode_printer) (function c!:pilessp))

(de c!:pigreaterp (op r1 r2 r3 depth) (c!:printf 
"    %v = ((int32)%v > (int32)%v) ? lisp_true : nil;\n" r1 r2 r3))

(put (quote igreaterp) (quote c!:opcode_printer) (function c!:pigreaterp))

(de c!:piminus (op r1 r2 r3 depth) (c!:printf 
"    %v = (Lisp_Object)(2-((int32)(%v)));\n" r1 r3))

(put (quote iminus) (quote c!:opcode_printer) (function c!:piminus))

(de c!:piadd1 (op r1 r2 r3 depth) (c!:printf 
"    %v = (Lisp_Object)((int32)(%v) + 0x10);\n" r1 r3))

(put (quote iadd1) (quote c!:opcode_printer) (function c!:piadd1))

(de c!:pisub1 (op r1 r2 r3 depth) (c!:printf 
"    %v = (Lisp_Object)((int32)(%v) - 0x10);\n" r1 r3))

(put (quote isub1) (quote c!:opcode_printer) (function c!:pisub1))

(de c!:piplus2 (op r1 r2 r3 depth) (c!:printf 
"    %v = (Lisp_Object)((int32)%v + (int32)%v - TAG_FIXNUM);\n" r1 r2 r3))

(put (quote iplus2) (quote c!:opcode_printer) (function c!:piplus2))

(de c!:pidifference (op r1 r2 r3 depth) (c!:printf 
"    %v = (Lisp_Object)((int32)%v - (int32)%v + TAG_FIXNUM);\n" r1 r2 r3))

(put (quote idifference) (quote c!:opcode_printer) (function c!:pidifference)
)

(de c!:pitimes2 (op r1 r2 r3 depth) (c!:printf 
"    %v = fixnum_of_int(int_of_fixnum(%v) * int_of_fixnum(%v));\n" r1 r2 r3))

(put (quote itimes2) (quote c!:opcode_printer) (function c!:pitimes2))

(de c!:pmodular_plus (op r1 r2 r3 depth) (progn (c!:printf 
"    {   int32 w = int_of_fixnum(%v) + int_of_fixnum(%v);\n" r2 r3) (
c!:printf "        if (w >= current_modulus) w -= current_modulus;\n") (
c!:printf "        %v = fixnum_of_int(w);\n" r1) (c!:printf "    }\n")))

(put (quote modular!-plus) (quote c!:opcode_printer) (function 
c!:pmodular_plus))

(de c!:pmodular_difference (op r1 r2 r3 depth) (progn (c!:printf 
"    {   int32 w = int_of_fixnum(%v) - int_of_fixnum(%v);\n" r2 r3) (
c!:printf "        if (w < 0) w += current_modulus;\n") (c!:printf 
"        %v = fixnum_of_int(w);\n" r1) (c!:printf "    }\n")))

(put (quote modular!-difference) (quote c!:opcode_printer) (function 
c!:pmodular_difference))

(de c!:pmodular_minus (op r1 r2 r3 depth) (progn (c!:printf 
"    {   int32 w = int_of_fixnum(%v);\n" r3) (c!:printf 
"        if (w != 0) w = current_modulus - w;\n") (c!:printf 
"        %v = fixnum_of_int(w);\n" r1) (c!:printf "    }\n")))

(put (quote modular!-minus) (quote c!:opcode_printer) (function 
c!:pmodular_minus))

(de c!:passoc (op r1 r2 r3 depth) (c!:printf 
"    %v = Lassoc(nil, %v, %v);\n" r1 r2 r3))

(put (quote assoc) (quote c!:opcode_printer) (function c!:passoc))

(flag (quote (assoc)) (quote c!:uses_nil))

(de c!:patsoc (op r1 r2 r3 depth) (c!:printf 
"    %v = Latsoc(nil, %v, %v);\n" r1 r2 r3))

(put (quote atsoc) (quote c!:opcode_printer) (function c!:patsoc))

(flag (quote (atsoc)) (quote c!:uses_nil))

(de c!:pmember (op r1 r2 r3 depth) (c!:printf 
"    %v = Lmember(nil, %v, %v);\n" r1 r2 r3))

(put (quote member) (quote c!:opcode_printer) (function c!:pmember))

(flag (quote (member)) (quote c!:uses_nil))

(de c!:pmemq (op r1 r2 r3 depth) (c!:printf "    %v = Lmemq(nil, %v, %v);\n" 
r1 r2 r3))

(put (quote memq) (quote c!:opcode_printer) (function c!:pmemq))

(flag (quote (memq)) (quote c!:uses_nil))

(de c!:pget (op r1 r2 r3 depth) (c!:printf "    %v = get(%v, %v);\n" r1 r2 r3
))

(put (quote get) (quote c!:opcode_printer) (function c!:pget))

(de c!:pqgetv (op r1 r2 r3 depth) (progn (c!:printf 
"    %v = *(Lisp_Object *)((char *)%v + (CELL-TAG_VECTOR) +" r1 r2) (
c!:printf " ((int32)%v/(16/CELL)));\n" r3)))

(put (quote qgetv) (quote c!:opcode_printer) (function c!:pqgetv))

(de c!:pqputv (op r1 r2 r3 depth) (progn (c!:printf 
"    *(Lisp_Object *)((char *)%v + (CELL-TAG_VECTOR) +" r2) (c!:printf 
" ((int32)%v/(16/CELL))) = %v;\n" r3 r1)))

(put (quote qputv) (quote c!:opcode_printer) (function c!:pqputv))

(de c!:peq (op r1 r2 r3 depth) (c!:printf 
"    %v = (%v == %v ? lisp_true : nil);\n" r1 r2 r3))

(put (quote eq) (quote c!:opcode_printer) (function c!:peq))

(flag (quote (eq)) (quote c!:uses_nil))

(de c!:pequal (op r1 r2 r3 depth) (c!:printf 
"    %v = (equal(%v, %v) ? lisp_true : nil);\n" r1 r2 r3 r2 r3))

(put (quote equal) (quote c!:opcode_printer) (function c!:pequal))

(flag (quote (equal)) (quote c!:uses_nil))

(de c!:pfluidbind (op r1 r2 r3 depth) nil)

(put (quote fluidbind) (quote c!:opcode_printer) (function c!:pfluidbind))

(de c!:pcall (op r1 r2 r3 depth) (prog (w boolfn) (if (setq w (get (car r3) (
quote c!:direct_entrypoint))) (progn (c!:printf "    %v = %s(" r1 (cdr w)) (
if r2 (progn (c!:printf "%v" (car r2)) (prog (var1054) (setq var1054 (cdr r2)
) lab1053 (if (null var1054) (return nil)) (prog (a) (setq a (car var1054)) (
c!:printf ", %v" a)) (setq var1054 (cdr var1054)) (go lab1053)))) (c!:printf 
");\n")) (if (setq w (get (car r3) (quote c!:direct_predicate))) (progn (setq
boolfn t) (c!:printf "    %v = (Lisp_Object)%s(" r1 (cdr w)) (if r2 (progn (
c!:printf "%v" (car r2)) (prog (var1056) (setq var1056 (cdr r2)) lab1055 (if 
(null var1056) (return nil)) (prog (a) (setq a (car var1056)) (c!:printf 
", %v" a)) (setq var1056 (cdr var1056)) (go lab1055)))) (c!:printf ");\n")) (
if (equal (car r3) current_procedure) (progn (c!:printf "    %v = %s(env" r1 
current_c_name) (if (or (null r2) (geq (length r2) 3)) (c!:printf ", %s" (
length r2))) (prog (var1058) (setq var1058 r2) lab1057 (if (null var1058) (
return nil)) (prog (a) (setq a (car var1058)) (c!:printf ", %v" a)) (setq 
var1058 (cdr var1058)) (go lab1057)) (c!:printf ");\n")) (if (setq w (get (
car r3) (quote c!:c_entrypoint))) (progn (c!:printf "    %v = %s(nil" r1 w) (
if (or (null r2) (geq (length r2) 3)) (c!:printf ", %s" (length r2))) (prog (
var1060) (setq var1060 r2) lab1059 (if (null var1060) (return nil)) (prog (a)
(setq a (car var1060)) (c!:printf ", %v" a)) (setq var1060 (cdr var1060)) (
go lab1059)) (c!:printf ");\n")) (prog (nargs) (setq nargs (length r2)) (
c!:printf "    fn = elt(env, %s); /* %a */\n" (c!:find_literal (car r3)) (car
r3)) (if (equal nargs 1) (c!:printf "    %v = (*qfn1(fn))(qenv(fn)" r1) (if 
(equal nargs 2) (c!:printf "    %v = (*qfn2(fn))(qenv(fn)" r1) (c!:printf 
"    %v = (*qfnn(fn))(qenv(fn), %s" r1 nargs))) (prog (var1062) (setq var1062
r2) lab1061 (if (null var1062) (return nil)) (prog (a) (setq a (car var1062)
) (c!:printf ", %v" a)) (setq var1062 (cdr var1062)) (go lab1061)) (c!:printf
");\n")))))) (if (not (flagp (car r3) (quote c!:no_errors))) (progn (if (and
(null (cadr r3)) (equal depth 0)) (c!:printf "    errexit();\n") (progn (
c!:printf "    nil = C_nil;\n") (c!:printf "    if (exception_pending()) ") (
c!:pgoto (c!:find_error_label nil (cadr r3) depth) depth))))) (if boolfn (
c!:printf "    %v = %v ? lisp_true : nil;\n" r1 r1))))

(put (quote call) (quote c!:opcode_printer) (function c!:pcall))

(de c!:pgoto (lab depth) (prog nil (if (atom lab) (return (c!:printf 
"goto %s;\n" lab))) (setq lab (get (car lab) (quote c!:chosen))) (if (zerop 
depth) (c!:printf "return onevalue(%v);\n" lab) (if (flagp lab (quote 
c!:live_across_call)) (c!:printf 
"{ Lisp_Object res = %v; popv(%s); return onevalue(res); }\n" lab depth) (
c!:printf "{ popv(%s); return onevalue(%v); }\n" depth lab)))))

(de c!:pifnull (s depth) (c!:printf "%v == nil" (car s)))

(put (quote ifnull) (quote c!:exit_helper) (function c!:pifnull))

(de c!:pifatom (s depth) (c!:printf "!consp(%v)" (car s)))

(put (quote ifatom) (quote c!:exit_helper) (function c!:pifatom))

(de c!:pifsymbol (s depth) (c!:printf "symbolp(%v)" (car s)))

(put (quote ifsymbol) (quote c!:exit_helper) (function c!:pifsymbol))

(de c!:pifnumber (s depth) (c!:printf "is_number(%v)" (car s)))

(put (quote ifnumber) (quote c!:exit_helper) (function c!:pifnumber))

(de c!:pifizerop (s depth) (c!:printf "(%v) == 1" (car s)))

(put (quote ifizerop) (quote c!:exit_helper) (function c!:pifizerop))

(de c!:pifeq (s depth) (c!:printf "%v == %v" (car s) (cadr s)))

(put (quote ifeq) (quote c!:exit_helper) (function c!:pifeq))

(de c!:pifequal (s depth) (c!:printf "equal(%v, %v)" (car s) (cadr s) (car s)
(cadr s)))

(put (quote ifequal) (quote c!:exit_helper) (function c!:pifequal))

(de c!:pifilessp (s depth) (c!:printf "((int32)(%v)) < ((int32)(%v))" (car s)
(cadr s)))

(put (quote ifilessp) (quote c!:exit_helper) (function c!:pifilessp))

(de c!:pifigreaterp (s depth) (c!:printf "((int32)(%v)) > ((int32)(%v))" (car
s) (cadr s)))

(put (quote ifigreaterp) (quote c!:exit_helper) (function c!:pifigreaterp))

(de c!:display_flowgraph (s depth dropping_through) (if (not (atom s)) (progn
(c!:printf "    ") (c!:pgoto s depth)) (if (not (flagp s (quote c!:visited))
) (prog (why where_to) (flag (list s) (quote c!:visited)) (if (or (not 
dropping_through) (not (equal (get s (quote c!:count)) 1))) (c!:printf 
"\n%s:\n" s)) (prog (var1064) (setq var1064 (reverse (get s (quote 
c!:contents)))) lab1063 (if (null var1064) (return nil)) (prog (k) (setq k (
car var1064)) (c!:print_opcode k depth)) (setq var1064 (cdr var1064)) (go 
lab1063)) (setq why (get s (quote c!:why))) (setq where_to (get s (quote 
c!:where_to))) (if (and (equal why (quote goto)) (or (not (atom (car where_to
))) (and (not (flagp (car where_to) (quote c!:visited))) (equal (get (car 
where_to) (quote c!:count)) 1)))) (c!:display_flowgraph (car where_to) depth 
t) (c!:print_exit_condition why where_to depth))))))

(fluid (quote (startpoint)))

(de c!:branch_chain (s count) (prog (contents why where_to n) (if (not (atom 
s)) (return s) (if (flagp s (quote c!:visited)) (progn (setq n (get s (quote 
c!:count))) (if (null n) (setq n 1) (setq n (plus n 1))) (put s (quote 
c!:count) n) (return s)))) (flag (list s) (quote c!:visited)) (setq contents 
(get s (quote c!:contents))) (setq why (get s (quote c!:why))) (setq where_to
(prog (var1066 var1067) (setq var1066 (get s (quote c!:where_to))) lab1065 (
if (null var1066) (return (reversip var1067))) (prog (z) (setq z (car var1066
)) (setq var1067 (cons (c!:branch_chain z count) var1067))) (setq var1066 (
cdr var1066)) (go lab1065))) (prog nil lab1068 (if (null (and contents (eqcar
(car contents) (quote movr)) (equal why (quote goto)) (not (atom (car 
where_to))) (equal (caar where_to) (cadr (car contents))))) (return nil)) (
progn (setq where_to (list (list (cadddr (car contents))))) (setq contents (
cdr contents))) (go lab1068)) (put s (quote c!:contents) contents) (put s (
quote c!:where_to) where_to) (if (and (null contents) (equal why (quote goto)
)) (progn (remflag (list s) (quote c!:visited)) (return (car where_to)))) (if
count (progn (setq n (get s (quote c!:count))) (if (null n) (setq n 1) (setq
n (plus n 1))) (put s (quote c!:count) n))) (return s)))

(de c!:one_operand (op) (progn (flag (list op) (quote c!:set_r1)) (flag (list
op) (quote c!:read_r3)) (put op (quote c!:code) (function c!:builtin_one))))

(de c!:two_operands (op) (progn (flag (list op) (quote c!:set_r1)) (flag (
list op) (quote c!:read_r2)) (flag (list op) (quote c!:read_r3)) (put op (
quote c!:code) (function c!:builtin_two))))

(prog (var1070) (setq var1070 (quote (car cdr qcar qcdr null not atom numberp
fixp iminusp iminus iadd1 isub1 modular!-minus))) lab1069 (if (null var1070)
(return nil)) (prog (n) (setq n (car var1070)) (c!:one_operand n)) (setq 
var1070 (cdr var1070)) (go lab1069))

(prog (var1072) (setq var1072 (quote (eq equal atsoc memq iplus2 idifference 
assoc member itimes2 ilessp igreaterp qgetv get modular!-plus 
modular!-difference))) lab1071 (if (null var1072) (return nil)) (prog (n) (
setq n (car var1072)) (c!:two_operands n)) (setq var1072 (cdr var1072)) (go 
lab1071))

(flag (quote (movr movk movk1 ldrglob call reloadenv fastget fastflag)) (
quote c!:set_r1))

(flag (quote (strglob qputv)) (quote c!:read_r1))

(flag (quote (qputv fastget fastflag)) (quote c!:read_r2))

(flag (quote (movr qputv)) (quote c!:read_r3))

(flag (quote (ldrglob strglob nilglob movk call)) (quote c!:read_env))

(fluid (quote (fn_used nil_used nilbase_used)))

(de c!:live_variable_analysis (all_blocks) (prog (changed z) (prog nil 
lab1079 (progn (setq changed nil) (prog (var1078) (setq var1078 all_blocks) 
lab1077 (if (null var1078) (return nil)) (prog (b) (setq b (car var1078)) (
prog (w live) (prog (var1074) (setq var1074 (get b (quote c!:where_to))) 
lab1073 (if (null var1074) (return nil)) (prog (x) (setq x (car var1074)) (if
(atom x) (setq live (union live (get x (quote c!:live)))) (setq live (union 
live x)))) (setq var1074 (cdr var1074)) (go lab1073)) (setq w (get b (quote 
c!:why))) (if (not (atom w)) (progn (if (or (eqcar w (quote ifnull)) (eqcar w
(quote ifequal))) (setq nil_used t)) (setq live (union live (cdr w))) (if (
and (eqcar (car w) (quote call)) (or (flagp (cadar w) (quote 
c!:direct_predicate)) (and (flagp (cadar w) (quote c!:c_entrypoint)) (not (
flagp (cadar w) (quote c!:direct_entrypoint)))))) (setq nil_used t)) (if (and
(eqcar (car w) (quote call)) (not (equal (cadar w) current_procedure)) (not 
(get (cadar w) (quote c!:direct_entrypoint))) (not (get (cadar w) (quote 
c!:c_entrypoint)))) (progn (setq fn_used t) (setq live (union (quote (env)) 
live)))))) (prog (var1076) (setq var1076 (get b (quote c!:contents))) lab1075
(if (null var1076) (return nil)) (prog (s) (setq s (car var1076)) (prog (op 
r1 r2 r3) (setq op (car s)) (setq r1 (cadr s)) (setq r2 (caddr s)) (setq r3 (
cadddr s)) (if (equal op (quote movk1)) (progn (if (equal r3 nil) (setq 
nil_used t) (if (equal r3 (quote t)) (setq nilbase_used t)))) (if (and (atom 
op) (flagp op (quote c!:uses_nil))) (setq nil_used t))) (if (flagp op (quote 
c!:set_r1)) (if (memq r1 live) (setq live (delete r1 live)) (if (equal op (
quote call)) nil (setq op (quote nop))))) (if (flagp op (quote c!:read_r1)) (
setq live (union live (list r1)))) (if (flagp op (quote c!:read_r2)) (setq 
live (union live (list r2)))) (if (flagp op (quote c!:read_r3)) (setq live (
union live (list r3)))) (if (equal op (quote call)) (progn (if (or (not (
flagp (car r3) (quote c!:no_errors))) (flagp (car r3) (quote c!:c_entrypoint)
) (get (car r3) (quote c!:direct_predicate))) (setq nil_used t)) (setq 
does_call t) (if (and (not (eqcar r3 current_procedure)) (not (get (car r3) (
quote c!:direct_entrypoint))) (not (get (car r3) (quote c!:c_entrypoint)))) (
setq fn_used t)) (if (not (flagp (car r3) (quote c!:no_errors))) (flag live (
quote c!:live_across_call))) (setq live (union live r2)))) (if (flagp op (
quote c!:read_env)) (setq live (union live (quote (env))))))) (setq var1076 (
cdr var1076)) (go lab1075)) (setq live (sort live (function orderp))) (if (
not (equal live (get b (quote c!:live)))) (progn (put b (quote c!:live) live)
(setq changed t))))) (setq var1078 (cdr var1078)) (go lab1077))) (if (null (
not changed)) (go lab1079))) (setq z registers) (setq registers (setq 
stacklocs nil)) (prog (var1081) (setq var1081 z) lab1080 (if (null var1081) (
return nil)) (prog (r) (setq r (car var1081)) (if (flagp r (quote 
c!:live_across_call)) (setq stacklocs (cons r stacklocs)) (setq registers (
cons r registers)))) (setq var1081 (cdr var1081)) (go lab1080))))

(de c!:insert1 (a b) (if (memq a b) b (cons a b)))

(de c!:clash (a b) (if (equal (flagp a (quote c!:live_across_call)) (flagp b 
(quote c!:live_across_call))) (progn (put a (quote c!:clash) (c!:insert1 b (
get a (quote c!:clash)))) (put b (quote c!:clash) (c!:insert1 a (get b (quote
c!:clash)))))))

(de c!:build_clash_matrix (all_blocks) (prog nil (prog (var1089) (setq 
var1089 all_blocks) lab1088 (if (null var1089) (return nil)) (prog (b) (setq 
b (car var1089)) (prog (live w) (prog (var1083) (setq var1083 (get b (quote 
c!:where_to))) lab1082 (if (null var1083) (return nil)) (prog (x) (setq x (
car var1083)) (if (atom x) (setq live (union live (get x (quote c!:live)))) (
setq live (union live x)))) (setq var1083 (cdr var1083)) (go lab1082)) (setq 
w (get b (quote c!:why))) (if (not (atom w)) (progn (setq live (union live (
cdr w))) (if (and (eqcar (car w) (quote call)) (not (get (cadar w) (quote 
c!:direct_entrypoint))) (not (get (cadar w) (quote c!:c_entrypoint)))) (setq 
live (union (quote (env)) live))))) (prog (var1087) (setq var1087 (get b (
quote c!:contents))) lab1086 (if (null var1087) (return nil)) (prog (s) (setq
s (car var1087)) (prog (op r1 r2 r3) (setq op (car s)) (setq r1 (cadr s)) (
setq r2 (caddr s)) (setq r3 (cadddr s)) (if (flagp op (quote c!:set_r1)) (if 
(memq r1 live) (progn (setq live (delete r1 live)) (if (equal op (quote 
reloadenv)) (setq reloadenv t)) (prog (var1085) (setq var1085 live) lab1084 (
if (null var1085) (return nil)) (prog (v) (setq v (car var1085)) (c!:clash r1
v)) (setq var1085 (cdr var1085)) (go lab1084))) (if (equal op (quote call)) 
nil (progn (setq op (quote nop)) (rplacd s (cons (car s) (cdr s))) (rplaca s 
op))))) (if (flagp op (quote c!:read_r1)) (setq live (union live (list r1))))
(if (flagp op (quote c!:read_r2)) (setq live (union live (list r2)))) (if (
flagp op (quote c!:read_r3)) (setq live (union live (list r3)))) (if (equal 
op (quote call)) (setq live (union live r2))) (if (flagp op (quote 
c!:read_env)) (setq live (union live (quote (env))))))) (setq var1087 (cdr 
var1087)) (go lab1086)))) (setq var1089 (cdr var1089)) (go lab1088)) (return 
nil)))

(de c!:allocate_registers (rl) (prog (schedule neighbours allocation) (setq 
neighbours 0) (prog nil lab1093 (if (null rl) (return nil)) (prog (w x) (setq
w rl) (prog nil lab1090 (if (null (and w (greaterp (length (setq x (get (car
w) (quote c!:clash)))) neighbours))) (return nil)) (setq w (cdr w)) (go 
lab1090)) (if w (progn (setq schedule (cons (car w) schedule)) (setq rl (
deleq (car w) rl)) (prog (var1092) (setq var1092 x) lab1091 (if (null var1092
) (return nil)) (prog (r) (setq r (car var1092)) (put r (quote c!:clash) (
deleq (car w) (get r (quote c!:clash))))) (setq var1092 (cdr var1092)) (go 
lab1091))) (setq neighbours (plus neighbours 1)))) (go lab1093)) (prog (
var1097) (setq var1097 schedule) lab1096 (if (null var1097) (return nil)) (
prog (r) (setq r (car var1097)) (prog (poss) (setq poss allocation) (prog (
var1095) (setq var1095 (get r (quote c!:clash))) lab1094 (if (null var1095) (
return nil)) (prog (x) (setq x (car var1095)) (setq poss (deleq (get x (quote
c!:chosen)) poss))) (setq var1095 (cdr var1095)) (go lab1094)) (if (null 
poss) (progn (setq poss (c!:my_gensym)) (setq allocation (append allocation (
list poss)))) (setq poss (car poss))) (put r (quote c!:chosen) poss))) (setq 
var1097 (cdr var1097)) (go lab1096)) (return allocation)))

(de c!:remove_nops (all_blocks) (prog (var1107) (setq var1107 all_blocks) 
lab1106 (if (null var1107) (return nil)) (prog (b) (setq b (car var1107)) (
prog (r) (prog (var1102) (setq var1102 (get b (quote c!:contents))) lab1101 (
if (null var1102) (return nil)) (prog (s) (setq s (car var1102)) (if (not (
eqcar s (quote nop))) (prog (op r1 r2 r3) (setq op (car s)) (setq r1 (cadr s)
) (setq r2 (caddr s)) (setq r3 (cadddr s)) (if (or (flagp op (quote c!:set_r1
)) (flagp op (quote c!:read_r1))) (setq r1 (get r1 (quote c!:chosen)))) (if (
flagp op (quote c!:read_r2)) (setq r2 (get r2 (quote c!:chosen)))) (if (flagp
op (quote c!:read_r3)) (setq r3 (get r3 (quote c!:chosen)))) (if (equal op (
quote call)) (setq r2 (prog (var1099 var1100) (setq var1099 r2) lab1098 (if (
null var1099) (return (reversip var1100))) (prog (v) (setq v (car var1099)) (
setq var1100 (cons (get v (quote c!:chosen)) var1100))) (setq var1099 (cdr 
var1099)) (go lab1098)))) (if (not (and (equal op (quote movr)) (equal r1 r3)
)) (setq r (cons (list op r1 r2 r3) r)))))) (setq var1102 (cdr var1102)) (go 
lab1101)) (put b (quote c!:contents) (reversip r)) (setq r (get b (quote 
c!:why))) (if (not (atom r)) (put b (quote c!:why) (cons (car r) (prog (
var1104 var1105) (setq var1104 (cdr r)) lab1103 (if (null var1104) (return (
reversip var1105))) (prog (v) (setq v (car var1104)) (setq var1105 (cons (get
v (quote c!:chosen)) var1105))) (setq var1104 (cdr var1104)) (go lab1103))))
))) (setq var1107 (cdr var1107)) (go lab1106)))

(fluid (quote (error_labels)))

(de c!:find_error_label (why env depth) (prog (w z) (setq z (list why env 
depth)) (setq w (assoc!*!* z error_labels)) (if (null w) (progn (setq w (cons
z (c!:my_gensym))) (setq error_labels (cons w error_labels)))) (return (cdr 
w))))

(de c!:assign (u v c) (if (flagp u (quote fluid)) (cons (list (quote strglob)
v u (c!:find_literal u)) c) (cons (list (quote movr) u nil v) c)))

(de c!:insert_tailcall (b) (prog (why dest contents fcall res w) (setq why (
get b (quote c!:why))) (setq dest (get b (quote c!:where_to))) (setq contents
(get b (quote c!:contents))) (prog nil lab1108 (if (null (and contents (not 
(eqcar (car contents) (quote call))))) (return nil)) (progn (setq w (cons (
car contents) w)) (setq contents (cdr contents))) (go lab1108)) (if (null 
contents) (return nil)) (setq fcall (car contents)) (setq contents (cdr 
contents)) (setq res (cadr fcall)) (prog nil lab1109 (if (null w) (return nil
)) (progn (if (eqcar (car w) (quote reloadenv)) (setq w (cdr w)) (if (and (
eqcar (car w) (quote movr)) (equal (cadddr (car w)) res)) (progn (setq res (
cadr (car w))) (setq w (cdr w))) (setq res (setq w nil))))) (go lab1109)) (if
(null res) (return nil)) (if (c!:does_return res why dest) (if (equal (car (
cadddr fcall)) current_procedure) (progn (prog (var1111) (setq var1111 (pair 
current_args (caddr fcall))) lab1110 (if (null var1111) (return nil)) (prog (
p) (setq p (car var1111)) (setq contents (c!:assign (car p) (cdr p) contents)
)) (setq var1111 (cdr var1111)) (go lab1110)) (put b (quote c!:contents) 
contents) (put b (quote c!:why) (quote goto)) (put b (quote c!:where_to) (
list restart_label))) (progn (setq nil_used t) (put b (quote c!:contents) 
contents) (put b (quote c!:why) (cons (list (quote call) (car (cadddr fcall))
) (caddr fcall))) (put b (quote c!:where_to) nil))))))

(de c!:does_return (res why where_to) (if (not (equal why (quote goto))) nil 
(if (not (atom (car where_to))) (equal res (caar where_to)) (prog (contents) 
(setq where_to (car where_to)) (setq contents (reverse (get where_to (quote 
c!:contents)))) (setq why (get where_to (quote c!:why))) (setq where_to (get 
where_to (quote c!:where_to))) (prog nil lab1112 (if (null contents) (return 
nil)) (if (eqcar (car contents) (quote reloadenv)) (setq contents (cdr 
contents)) (if (and (eqcar (car contents) (quote movr)) (equal (cadddr (car 
contents)) res)) (progn (setq res (cadr (car contents))) (setq contents (cdr 
contents))) (setq res (setq contents nil)))) (go lab1112)) (if (null res) (
return nil) (return (c!:does_return res why where_to)))))))

(de c!:pushpop (op v) (prog (n w) (if (null v) (return nil)) (setq n (length 
v)) (if (equal n 1) (return (c!:printf "        %s(%s);\n" op (car v)))) (
prog nil lab1114 (if (null (greaterp n 0)) (return nil)) (progn (setq w n) (
if (greaterp w 6) (setq w 6)) (setq n (difference n w)) (c!:printf 
"        %s%d(%s" op w (car v)) (setq v (cdr v)) (prog (i) (setq i 2) lab1113
(if (minusp (times 1 (difference w i))) (return nil)) (progn (c!:printf 
",%s" (car v)) (setq v (cdr v))) (setq i (plus i 1)) (go lab1113)) (c!:printf
");\n")) (go lab1114))))

(de c!:optimise_flowgraph (startpoint all_blocks env argch args) (prog (w n 
locs stacks error_labels fn_used nil_used nilbase_used) (prog (var1116) (setq
var1116 all_blocks) lab1115 (if (null var1116) (return nil)) (prog (b) (setq
b (car var1116)) (c!:insert_tailcall b)) (setq var1116 (cdr var1116)) (go 
lab1115)) (setq startpoint (c!:branch_chain startpoint nil)) (remflag 
all_blocks (quote c!:visited)) (c!:live_variable_analysis all_blocks) (
c!:build_clash_matrix all_blocks) (if (and error_labels env) (setq reloadenv 
t)) (prog (var1120) (setq var1120 env) lab1119 (if (null var1120) (return nil
)) (prog (u) (setq u (car var1120)) (prog (var1118) (setq var1118 env) 
lab1117 (if (null var1118) (return nil)) (prog (v) (setq v (car var1118)) (
c!:clash (cdr u) (cdr v))) (setq var1118 (cdr var1118)) (go lab1117))) (setq 
var1120 (cdr var1120)) (go lab1119)) (setq locs (c!:allocate_registers 
registers)) (setq stacks (c!:allocate_registers stacklocs)) (flag stacks (
quote c!:live_across_call)) (c!:remove_nops all_blocks) (setq startpoint (
c!:branch_chain startpoint nil)) (remflag all_blocks (quote c!:visited)) (
setq startpoint (c!:branch_chain startpoint t)) (remflag all_blocks (quote 
c!:visited)) (if does_call (setq nil_used t)) (if nil_used (c!:printf 
"    Lisp_Object nil = C_nil;\n") (if nilbase_used (c!:printf 
"    nil_as_base\n"))) (if locs (progn (c!:printf "    Lisp_Object %s" (car 
locs)) (prog (var1122) (setq var1122 (cdr locs)) lab1121 (if (null var1122) (
return nil)) (prog (v) (setq v (car var1122)) (c!:printf ", %s" v)) (setq 
var1122 (cdr var1122)) (go lab1121)) (c!:printf ";\n"))) (if fn_used (
c!:printf "    Lisp_Object fn;\n")) (if (or (equal (car argch) 0) (geq (car 
argch) 3)) (c!:printf "    argcheck(nargs, %s, \q%s\q);\n" (car argch) (cdr 
argch))) (if does_call (progn (c!:printf "    if (stack >= stacklimit)\n") (
c!:printf "    {\n") (c!:pushpop (quote push) args) (c!:printf 
"        env = reclaim(env, \qstack\q, GC_STACK, 0);\n") (c!:pushpop (quote 
pop) (reverse args)) (c!:printf "        nil = C_nil;\n") (c!:printf 
"        if (exception_pending()) return nil;\n") (c!:printf "    }\n"))) (if
reloadenv (c!:printf "    push(env);\n") (c!:printf "    CSL_IGNORE(env);\n"
)) (setq n 0) (if stacks (progn (c!:printf 
"/* space for vars preserved across procedure calls */\n") (prog (var1124) (
setq var1124 stacks) lab1123 (if (null var1124) (return nil)) (prog (v) (setq
v (car var1124)) (progn (put v (quote c!:location) n) (setq n (plus n 1)))) 
(setq var1124 (cdr var1124)) (go lab1123)) (setq w n) (prog nil lab1125 (if (
null (geq w 5)) (return nil)) (progn (c!:printf 
"    push5(nil, nil, nil, nil, nil);\n") (setq w (difference w 5))) (go 
lab1125)) (if (neq w 0) (progn (if (equal w 1) (c!:printf "    push(nil);\n")
(progn (c!:printf "    push%s(nil" w) (prog (i) (setq i 2) lab1126 (if (
minusp (times 1 (difference w i))) (return nil)) (c!:printf ", nil") (setq i 
(plus i 1)) (go lab1126)) (c!:printf ");\n"))))))) (if reloadenv (progn (setq
reloadenv n) (setq n (plus n 1)))) (if env (c!:printf 
"/* copy arguments values to proper place */\n")) (prog (var1128) (setq 
var1128 env) lab1127 (if (null var1128) (return nil)) (prog (v) (setq v (car 
var1128)) (if (flagp (cdr v) (quote c!:live_across_call)) (c!:printf 
"    stack[%s] = %s;\n" (minus (get (get (cdr v) (quote c!:chosen)) (quote 
c!:location))) (cdr v)) (c!:printf "    %s = %s;\n" (get (cdr v) (quote 
c!:chosen)) (cdr v)))) (setq var1128 (cdr var1128)) (go lab1127)) (c!:printf 
"/* end of prologue */\n") (c!:display_flowgraph startpoint n t) (if 
error_labels (progn (c!:printf "/* error exit handlers */\n") (prog (var1130)
(setq var1130 error_labels) lab1129 (if (null var1130) (return nil)) (prog (
x) (setq x (car var1130)) (progn (c!:printf "%s:\n" (cdr x)) (
c!:print_error_return (caar x) (cadar x) (caddar x)))) (setq var1130 (cdr 
var1130)) (go lab1129)))) (remflag all_blocks (quote c!:visited))))

(de c!:print_error_return (why env depth) (prog nil (if (and reloadenv env) (
c!:printf "    env = stack[%s];\n" (minus reloadenv))) (if (null why) (progn 
(prog (var1132) (setq var1132 env) lab1131 (if (null var1132) (return nil)) (
prog (v) (setq v (car var1132)) (c!:printf 
"    qvalue(elt(env, %s)) = %v; /* %a */\n" (c!:find_literal (car v)) (get (
cdr v) (quote c!:chosen)) (car v))) (setq var1132 (cdr var1132)) (go lab1131)
) (if (neq depth 0) (c!:printf "    popv(%s);\n" depth)) (c!:printf 
"    return nil;\n")) (if (flagp (cadr why) (quote c!:live_across_call)) (
progn (c!:printf "    {   Lisp_Object res = %v;\n" (cadr why)) (prog (var1134
) (setq var1134 env) lab1133 (if (null var1134) (return nil)) (prog (v) (setq
v (car var1134)) (c!:printf "        qvalue(elt(env, %s)) = %v;\n" (
c!:find_literal (car v)) (get (cdr v) (quote c!:chosen)))) (setq var1134 (cdr
var1134)) (go lab1133)) (if (neq depth 0) (c!:printf "        popv(%s);\n" 
depth)) (c!:printf "        return error(1, %s, res); }\n" (if (eqcar why (
quote car)) "err_bad_car" (if (eqcar why (quote cdr)) "err_bad_cdr" (error 0 
(list why "unknown_error")))))) (progn (prog (var1136) (setq var1136 env) 
lab1135 (if (null var1136) (return nil)) (prog (v) (setq v (car var1136)) (
c!:printf "    qvalue(elt(env, %s)) = %v;\n" (c!:find_literal (car v)) (get (
cdr v) (quote c!:chosen)))) (setq var1136 (cdr var1136)) (go lab1135)) (if (
neq depth 0) (c!:printf "    popv(%s);\n" depth)) (c!:printf 
"    return error(1, %s, %v);\n" (if (eqcar why (quote car)) "err_bad_car" (
if (eqcar why (quote cdr)) "err_bad_cdr" (error 0 (list why "unknown_error"))
)) (cadr why)))))))

(de c!:cand (u env) (prog (w r) (setq w (reverse (cdr u))) (if (null w) (
return (c!:cval nil env))) (setq r (list (list (quote t) (car w)))) (setq w (
cdr w)) (prog (var1138) (setq var1138 w) lab1137 (if (null var1138) (return 
nil)) (prog (z) (setq z (car var1138)) (setq r (cons (list (list (quote null)
z) nil) r))) (setq var1138 (cdr var1138)) (go lab1137)) (setq r (cons (quote
cond) r)) (return (c!:cval r env))))

(put (quote and) (quote c!:code) (function c!:cand))

(de c!:ccatch (u env) (error 0 "catch"))

(put (quote catch) (quote c!:code) (function c!:ccatch))

(de c!:ccompile_let (u env) (error 0 "compiler-let"))

(put (quote compiler!-let) (quote c!:code) (function c!:ccompiler_let))

(de c!:ccond (u env) (prog (v join) (setq v (c!:newreg)) (setq join (
c!:my_gensym)) (prog (var1140) (setq var1140 (cdr u)) lab1139 (if (null 
var1140) (return nil)) (prog (c) (setq c (car var1140)) (prog (l1 l2) (setq 
l1 (c!:my_gensym)) (setq l2 (c!:my_gensym)) (if (atom (cdr c)) (progn (
c!:outop (quote movr) v nil (c!:cval (car c) env)) (c!:endblock (list (quote 
ifnull) v) (list l2 join))) (progn (c!:cjumpif (car c) env l1 l2) (
c!:startblock l1) (c!:outop (quote movr) v nil (c!:cval (cons (quote progn) (
cdr c)) env)) (c!:endblock (quote goto) (list join)))) (c!:startblock l2))) (
setq var1140 (cdr var1140)) (go lab1139)) (c!:outop (quote movk1) v nil nil) 
(c!:endblock (quote goto) (list join)) (c!:startblock join) (return v)))

(put (quote cond) (quote c!:code) (function c!:ccond))

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

(de c!:cfunction (u env) (prog (v) (setq u (cadr u)) (if (not (atom u)) (
progn (if (not (eqcar u (quote lambda))) (error 0 (list 
"lambda expression needed" u))) (setq v (dated!-name (quote lambda))) (setq 
pending_functions (cons (cons (quote de) (cons v (cdr u))) pending_functions)
) (setq u v))) (setq v (c!:newreg)) (c!:outop (quote movk) v u (
c!:find_literal u)) (return v)))

(put (quote function) (quote c!:code) (function c!:cfunction))

(de c!:cgo (u env) (prog (w w1) (setq w1 proglabs) (prog nil lab1141 (if (
null (and (null w) w1)) (return nil)) (progn (setq w (assoc!*!* (cadr u) (car
w1))) (setq w1 (cdr w1))) (go lab1141)) (if (null w) (error 0 (list u 
"label not set"))) (c!:endblock (quote goto) (list (cadr w))) (return nil)))

(put (quote go) (quote c!:code) (function c!:cgo))

(de c!:cif (u env) (prog (v join l1 l2 w) (setq v (c!:newreg)) (setq join (
c!:my_gensym)) (setq l1 (c!:my_gensym)) (setq l2 (c!:my_gensym)) (c!:cjumpif 
(car (setq u (cdr u))) env l1 l2) (c!:startblock l1) (c!:outop (quote movr) v
nil (c!:cval (car (setq u (cdr u))) env)) (c!:endblock (quote goto) (list 
join)) (c!:startblock l2) (setq u (cdr u)) (if u (setq u (car u))) (c!:outop 
(quote movr) v nil (c!:cval u env)) (c!:endblock (quote goto) (list join)) (
c!:startblock join) (return v)))

(put (quote if) (quote c!:code) (function c!:cif))

(de c!:clabels (u env) (error 0 "labels"))

(put (quote labels) (quote c!:code) (function c!:clabels))

(de c!:expand!-let (vl b) (if (null vl) (cons (quote progn) b) (if (null (cdr
vl)) (c!:expand!-let!* vl b) (prog (vars vals) (prog (var1143) (setq var1143
vl) lab1142 (if (null var1143) (return nil)) (prog (v) (setq v (car var1143)
) (if (atom v) (progn (setq vars (cons v vars)) (setq vals (cons nil vals))) 
(if (atom (cdr v)) (progn (setq vars (cons (car v) vars)) (setq vals (cons 
nil vals))) (progn (setq vars (cons (car v) vars)) (setq vals (cons (cadr v) 
vals)))))) (setq var1143 (cdr var1143)) (go lab1142)) (return (cons (cons (
quote lambda) (cons vars b)) vals))))))

(de c!:clet (x env) (c!:cval (c!:expand!-let (cadr x) (cddr x)) env))

(put (quote !~let) (quote c!:code) (function c!:clet))

(de c!:expand!-let!* (vl b) (if (null vl) (cons (quote progn) b) (prog (var 
val) (setq var (car vl)) (if (not (atom var)) (progn (setq val (cdr var)) (
setq var (car var)) (if (not (atom val)) (setq val (car val))))) (setq b (
list (list (quote return) (c!:expand!-let!* (cdr vl) b)))) (if val (setq b (
cons (list (quote setq) var val) b))) (return (cons (quote prog) (cons (list 
var) b))))))

(de c!:clet!* (x env) (c!:cval (c!:expand!-let!* (cadr x) (cddr x)) env))

(put (quote let!*) (quote c!:code) (function c!:clet!*))

(de c!:clist (u env) (if (null (cdr u)) (c!:cval nil env) (if (null (cddr u))
(c!:cval (cons (quote ncons) (cdr u)) env) (if (eqcar (cadr u) (quote cons))
(c!:cval (list (quote acons) (cadr (cadr u)) (caddr (cadr u)) (cons (quote 
list) (cddr u))) env) (if (null (cdddr u)) (c!:cval (cons (quote list2) (cdr 
u)) env) (c!:cval (list (quote list2!*) (cadr u) (caddr u) (cons (quote list)
(cdddr u))) env))))))

(put (quote list) (quote c!:code) (function c!:clist))

(de c!:clist!* (u env) (prog (v) (setq u (reverse (cdr u))) (setq v (car u)) 
(prog (var1145) (setq var1145 (cdr u)) lab1144 (if (null var1145) (return nil
)) (prog (a) (setq a (car var1145)) (setq v (list (quote cons) a v))) (setq 
var1145 (cdr var1145)) (go lab1144)) (return (c!:cval v env))))

(put (quote list!*) (quote c!:code) (function c!:clist!*))

(de c!:ccons (u env) (prog (a1 a2) (setq a1 (s!:improve (cadr u))) (setq a2 (
s!:improve (caddr u))) (if (or (equal a2 nil) (equal a2 (quote (quote nil))) 
(equal a2 (quote (list)))) (return (c!:cval (list (quote ncons) a1) env))) (
if (eqcar a1 (quote cons)) (return (c!:cval (list (quote acons) (cadr a1) (
caddr a1) a2) env))) (if (eqcar a2 (quote cons)) (return (c!:cval (list (
quote list2!*) a1 (cadr a2) (caddr a2)) env))) (if (eqcar a2 (quote list)) (
return (c!:cval (list (quote cons) a1 (list (quote cons) (cadr a2) (cons (
quote list) (cddr a2)))) env))) (return (c!:ccall (car u) (cdr u) env))))

(put (quote cons) (quote c!:code) (function c!:ccons))

(de c!:cget (u env) (prog (a1 a2 w r r1) (setq a1 (s!:improve (cadr u))) (
setq a2 (s!:improve (caddr u))) (if (and (eqcar a2 (quote quote)) (idp (setq 
w (cadr a2))) (setq w (symbol!-make!-fastget w nil))) (progn (setq r (
c!:newreg)) (c!:outop (quote fastget) r (c!:cval a1 env) (cons w (cadr a2))) 
(return r)) (return (c!:ccall (car u) (cdr u) env)))))

(put (quote get) (quote c!:code) (function c!:cget))

(de c!:cflag (u env) (prog (a1 a2 w r r1) (setq a1 (s!:improve (cadr u))) (
setq a2 (s!:improve (caddr u))) (if (and (eqcar a2 (quote quote)) (idp (setq 
w (cadr a2))) (setq w (symbol!-make!-fastget w nil))) (progn (setq r (
c!:newreg)) (c!:outop (quote fastflag) r (c!:cval a1 env) (cons w (cadr a2)))
(return r)) (return (c!:ccall (car u) (cdr u) env)))))

(put (quote flagp) (quote c!:code) (function c!:cflag))

(de c!:cgetv (u env) (if (not !*fastvector) (c!:ccall (car u) (cdr u) env) (
c!:cval (cons (quote qgetv) (cdr u)) env)))

(put (quote getv) (quote c!:code) (function c!:cgetv))

(de c!:cputv (u env) (if (not !*fastvector) (c!:ccall (car u) (cdr u) env) (
c!:cval (cons (quote qputv) (cdr u)) env)))

(put (quote putv) (quote c!:code) (function c!:cputv))

(de c!:cqputv (x env) (prog (rr) (setq rr (c!:pareval (cdr x) env)) (c!:outop
(quote qputv) (caddr rr) (car rr) (cadr rr)) (return (caddr rr))))

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
c!:my_gensym)) (setq u (cdr u)) (prog nil lab1146 (if (null (cdr u)) (return 
nil)) (progn (setq next (c!:my_gensym)) (c!:outop (quote movr) v nil (c!:cval
(car u) env)) (setq u (cdr u)) (c!:endblock (list (quote ifnull) v) (list 
next done)) (c!:startblock next)) (go lab1146)) (c!:outop (quote movr) v nil 
(c!:cval (car u) env)) (c!:endblock (quote goto) (list done)) (c!:startblock 
done) (return v)))

(put (quote or) (quote c!:code) (function c!:cor))

(de c!:cprog (u env) (prog (w w1 bvl local_proglabs progret progexit fluids 
env1) (setq env1 (car env)) (setq bvl (cadr u)) (prog (var1148) (setq var1148
bvl) lab1147 (if (null var1148) (return nil)) (prog (v) (setq v (car var1148
)) (if (globalp v) (error 0 (list v "attempt to bind a global")) (if (fluidp 
v) (progn (setq fluids (cons (cons v (c!:newreg)) fluids)) (flag (list (cdar 
fluids)) (quote c!:live_across_call)) (setq env1 (cons (cons (quote 
c!:dummy!:name) (cdar fluids)) env1)) (c!:outop (quote ldrglob) (cdar fluids)
v (c!:find_literal v)) (c!:outop (quote nilglob) nil v (c!:find_literal v)))
(progn (setq env1 (cons (cons v (c!:newreg)) env1)) (c!:outop (quote movk1) 
(cdar env1) nil nil))))) (setq var1148 (cdr var1148)) (go lab1147)) (if 
fluids (c!:outop (quote fluidbind) nil nil fluids)) (setq env (cons env1 (
append fluids (cdr env)))) (setq u (cddr u)) (setq progret (c!:newreg)) (setq
progexit (c!:my_gensym)) (setq blockstack (cons (cons nil (cons progret 
progexit)) blockstack)) (prog (var1150) (setq var1150 u) lab1149 (if (null 
var1150) (return nil)) (prog (a) (setq a (car var1150)) (if (atom a) (if (
atsoc a local_proglabs) (progn (if (not (null a)) (progn (setq w (wrs nil)) (
princ "+++++ multiply defined label: ") (prin a) (terpri) (wrs w)))) (setq 
local_proglabs (cons (list a (c!:my_gensym)) local_proglabs))))) (setq 
var1150 (cdr var1150)) (go lab1149)) (setq proglabs (cons local_proglabs 
proglabs)) (prog (var1152) (setq var1152 u) lab1151 (if (null var1152) (
return nil)) (prog (a) (setq a (car var1152)) (if (atom a) (progn (setq w (
cdr (assoc!*!* a local_proglabs))) (if (null (cdr w)) (progn (rplacd w t) (
c!:endblock (quote goto) (list (car w))) (c!:startblock (car w))))) (c!:cval 
a env))) (setq var1152 (cdr var1152)) (go lab1151)) (c!:outop (quote movk1) 
progret nil nil) (c!:endblock (quote goto) (list progexit)) (c!:startblock 
progexit) (prog (var1154) (setq var1154 fluids) lab1153 (if (null var1154) (
return nil)) (prog (v) (setq v (car var1154)) (c!:outop (quote strglob) (cdr 
v) (car v) (c!:find_literal (car v)))) (setq var1154 (cdr var1154)) (go 
lab1153)) (setq blockstack (cdr blockstack)) (setq proglabs (cdr proglabs)) (
return progret)))

(put (quote prog) (quote c!:code) (function c!:cprog))

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

(de c!:cprogn (u env) (prog (r) (setq u (cdr u)) (if (equal u nil) (setq u (
quote (nil)))) (prog (var1156) (setq var1156 u) lab1155 (if (null var1156) (
return nil)) (prog (s) (setq s (car var1156)) (setq r (c!:cval s env))) (setq
var1156 (cdr var1156)) (go lab1155)) (return r)))

(put (quote progn) (quote c!:code) (function c!:cprogn))

(de c!:cprogv (u env) (error 0 "progv"))

(put (quote progv) (quote c!:code) (function c!:cprogv))

(de c!:cquote (u env) (prog (v) (setq u (cadr u)) (setq v (c!:newreg)) (if (
or (null u) (equal u (quote t)) (c!:small_number u)) (c!:outop (quote movk1) 
v nil u) (c!:outop (quote movk) v u (c!:find_literal u))) (return v)))

(put (quote quote) (quote c!:code) (function c!:cquote))

(de c!:creturn (u env) (prog (w) (setq w (assoc!*!* nil blockstack)) (if (
null w) (error "RETURN out of context")) (c!:outop (quote movr) (cadr w) nil 
(c!:cval (cadr u) env)) (c!:endblock (quote goto) (list (cddr w))) (return 
nil)))

(put (quote return) (quote c!:code) (function c!:creturn))

(put (quote return!-from) (quote c!:code) (function c!:creturn_from))

(de c!:csetq (u env) (prog (v w) (setq v (c!:cval (caddr u) env)) (setq u (
cadr u)) (if (not (idp u)) (error 0 (list u "bad variable in setq")) (if (
setq w (c!:locally_bound u env)) (c!:outop (quote movr) (cdr w) nil v) (if (
flagp u (quote c!:constant)) (error 0 (list u 
"attempt to use setq on a constant")) (c!:outop (quote strglob) v u (
c!:find_literal u))))) (return v)))

(put (quote setq) (quote c!:code) (function c!:csetq))

(put (quote noisy!-setq) (quote c!:code) (function c!:csetq))

(de c!:cprivate_tagbody (u env) (prog nil (setq u (cdr u)) (c!:endblock (
quote goto) (list (car u))) (c!:startblock (car u)) (setq current_args (prog 
(var1158 var1159) (setq var1158 current_args) lab1157 (if (null var1158) (
return (reversip var1159))) (prog (v) (setq v (car var1158)) (setq var1159 (
cons (prog (z) (setq z (assoc!*!* v (car env))) (return (if z (cdr z) v))) 
var1159))) (setq var1158 (cdr var1158)) (go lab1157))) (return (c!:cval (cadr
u) env))))

(put (quote c!:private_tagbody) (quote c!:code) (function c!:cprivate_tagbody
))

(de c!:cthe (u env) (c!:cval (caddr u) env))

(put (quote the) (quote c!:code) (function c!:cthe))

(de c!:cthrow (u env) (error 0 "throw"))

(put (quote throw) (quote c!:code) (function c!:cthrow))

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
closed) (setq fn (car fnargs)) (if (or (equal fn (quote mapc)) (equal fn (
quote mapcar)) (equal fn (quote mapcan))) (setq carp t)) (setq fnargs (cdr 
fnargs)) (if (atom fnargs) (error 0 "bad arguments to map function")) (setq 
fn1 (cadr fnargs)) (prog nil lab1160 (if (null (or (eqcar fn1 (quote function
)) (and (eqcar fn1 (quote quote)) (eqcar (cadr fn1) (quote lambda))))) (
return nil)) (progn (setq fn1 (cadr fn1)) (setq closed t)) (go lab1160)) (
setq args (car fnargs)) (setq l1 (c!:my_gensym)) (setq r (c!:my_gensym)) (
setq s (c!:my_gensym)) (setq var (c!:my_gensym)) (setq avar var) (if carp (
setq avar (list (quote car) avar))) (if closed (setq fn1 (list fn1 avar)) (
setq fn1 (list (quote apply1) fn1 avar))) (setq moveon (list (quote setq) var
(list (quote cdr) var))) (if (or (equal fn (quote map)) (equal fn (quote 
mapc))) (setq fn (sublis (list (cons (quote l1) l1) (cons (quote var) var) (
cons (quote fn) fn1) (cons (quote args) args) (cons (quote moveon) moveon)) (
quote (prog (var) (setq var args) l1 (cond ((not var) (return nil))) fn 
moveon (go l1))))) (if (or (equal fn (quote maplist)) (equal fn (quote mapcar
))) (setq fn (sublis (list (cons (quote l1) l1) (cons (quote var) var) (cons 
(quote fn) fn1) (cons (quote args) args) (cons (quote moveon) moveon) (cons (
quote r) r)) (quote (prog (var r) (setq var args) l1 (cond ((not var) (return
(reversip r)))) (setq r (cons fn r)) moveon (go l1))))) (setq fn (sublis (
list (cons (quote l1) l1) (cons (quote l2) (c!:my_gensym)) (cons (quote var) 
var) (cons (quote fn) fn1) (cons (quote args) args) (cons (quote moveon) 
moveon) (cons (quote r) (c!:my_gensym)) (cons (quote s) (c!:my_gensym))) (
quote (prog (var r s) (setq var args) (setq r (setq s (list nil))) l1 (cond (
(not var) (return (cdr r)))) (rplacd s fn) l2 (cond ((not (atom (cdr s))) (
setq s (cdr s)) (go l2))) moveon (go l1))))))) (return fn)))

(put (quote map) (quote c!:compile_macro) (function c!:expand_map))

(put (quote maplist) (quote c!:compile_macro) (function c!:expand_map))

(put (quote mapc) (quote c!:compile_macro) (function c!:expand_map))

(put (quote mapcar) (quote c!:compile_macro) (function c!:expand_map))

(put (quote mapcon) (quote c!:compile_macro) (function c!:expand_map))

(put (quote mapcan) (quote c!:compile_macro) (function c!:expand_map))

(de c!:expand_carcdr (x) (prog (name) (setq name (cdr (reverse (cdr (explode2
(car x)))))) (setq x (cadr x)) (prog (var1162) (setq var1162 name) lab1161 (
if (null var1162) (return nil)) (prog (v) (setq v (car var1162)) (setq x (
list (if (equal v (quote a)) (quote car) (quote cdr)) x))) (setq var1162 (cdr
var1162)) (go lab1161)) (return x)))

(progn (put (quote caar) (quote c!:compile_macro) (function c!:expand_carcdr)
) (put (quote cadr) (quote c!:compile_macro) (function c!:expand_carcdr)) (
put (quote cdar) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (
quote cddr) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (quote
caaar) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (quote 
caadr) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (quote 
cadar) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (quote 
caddr) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (quote 
cdaar) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (quote 
cdadr) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (quote 
cddar) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (quote 
cdddr) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (quote 
caaaar) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (quote 
caaadr) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (quote 
caadar) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (quote 
caaddr) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (quote 
cadaar) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (quote 
cadadr) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (quote 
caddar) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (quote 
cadddr) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (quote 
cdaaar) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (quote 
cdaadr) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (quote 
cdadar) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (quote 
cdaddr) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (quote 
cddaar) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (quote 
cddadr) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (quote 
cdddar) (quote c!:compile_macro) (function c!:expand_carcdr)) (put (quote 
cddddr) (quote c!:compile_macro) (function c!:expand_carcdr)))

(de c!:builtin_one (x env) (prog (r1 r2) (setq r1 (c!:cval (cadr x) env)) (
c!:outop (car x) (setq r2 (c!:newreg)) (cdr env) r1) (return r2)))

(de c!:builtin_two (x env) (prog (a1 a2 r rr) (setq a1 (cadr x)) (setq a2 (
caddr x)) (setq rr (c!:pareval (list a1 a2) env)) (c!:outop (car x) (setq r (
c!:newreg)) (car rr) (cadr rr)) (return r)))

(de c!:narg (x env) (c!:cval (expand (cdr x) (get (car x) (quote 
c!:binary_version))) env))

(prog (var1164) (setq var1164 (quote ((plus plus2) (times times2) (iplus 
iplus2) (itimes itimes2)))) lab1163 (if (null var1164) (return nil)) (prog (n
) (setq n (car var1164)) (progn (put (car n) (quote c!:binary_version) (cadr 
n)) (put (car n) (quote c!:code) (function c!:narg)))) (setq var1164 (cdr 
var1164)) (go lab1163))

(de c!:cplus2 (u env) (prog (a b) (setq a (s!:improve (cadr u))) (setq b (
s!:improve (caddr u))) (return (if (and (numberp a) (numberp b)) (c!:cval (
plus a b) env) (if (equal a 0) (c!:cval b env) (if (equal a 1) (c!:cval (list
(quote add1) b) env) (if (equal b 0) (c!:cval a env) (if (equal b 1) (
c!:cval (list (quote add1) a) env) (if (equal b (minus 1)) (c!:cval (list (
quote sub1) a) env) (c!:ccall (car u) (cdr u) env))))))))))

(put (quote plus2) (quote c!:code) (function c!:cplus2))

(de c!:ciplus2 (u env) (prog (a b) (setq a (s!:improve (cadr u))) (setq b (
s!:improve (caddr u))) (return (if (and (numberp a) (numberp b)) (c!:cval (
plus a b) env) (if (equal a 0) (c!:cval b env) (if (equal a 1) (c!:cval (list
(quote iadd1) b) env) (if (equal b 0) (c!:cval a env) (if (equal b 1) (
c!:cval (list (quote iadd1) a) env) (if (equal b (minus 1)) (c!:cval (list (
quote isub1) a) env) (c!:builtin_two u env))))))))))

(put (quote iplus2) (quote c!:code) (function c!:ciplus2))

(de c!:cdifference (u env) (prog (a b) (setq a (s!:improve (cadr u))) (setq b
(s!:improve (caddr u))) (return (if (and (numberp a) (numberp b)) (c!:cval (
difference a b) env) (if (equal a 0) (c!:cval (list (quote minus) b) env) (if
(equal b 0) (c!:cval a env) (if (equal b 1) (c!:cval (list (quote sub1) a) 
env) (if (equal b (minus 1)) (c!:cval (list (quote add1) a) env) (c!:ccall (
car u) (cdr u) env)))))))))

(put (quote difference) (quote c!:code) (function c!:cdifference))

(de c!:cidifference (u env) (prog (a b) (setq a (s!:improve (cadr u))) (setq 
b (s!:improve (caddr u))) (return (if (and (numberp a) (numberp b)) (c!:cval 
(difference a b) env) (if (equal a 0) (c!:cval (list (quote iminus) b) env) (
if (equal b 0) (c!:cval a env) (if (equal b 1) (c!:cval (list (quote isub1) a
) env) (if (equal b (minus 1)) (c!:cval (list (quote iadd1) a) env) (
c!:builtin_two u env)))))))))

(put (quote idifference) (quote c!:code) (function c!:cidifference))

(de c!:ctimes2 (u env) (prog (a b) (setq a (s!:improve (cadr u))) (setq b (
s!:improve (caddr u))) (return (if (and (numberp a) (numberp b)) (c!:cval (
times a b) env) (if (or (equal a 0) (equal b 0)) (c!:cval 0 env) (if (equal a
1) (c!:cval b env) (if (equal b 1) (c!:cval a env) (if (equal a (minus 1)) (
c!:cval (list (quote minus) b) env) (if (equal b (minus 1)) (c!:cval (list (
quote minus) a) env) (c!:ccall (car u) (cdr u) env))))))))))

(put (quote times2) (quote c!:code) (function c!:ctimes2))

(de c!:citimes2 (u env) (prog (a b) (setq a (s!:improve (cadr u))) (setq b (
s!:improve (caddr u))) (return (if (and (numberp a) (numberp b)) (c!:cval (
times a b) env) (if (or (equal a 0) (equal b 0)) (c!:cval 0 env) (if (equal a
1) (c!:cval b env) (if (equal b 1) (c!:cval a env) (if (equal a (minus 1)) (
c!:cval (list (quote iminus) b) env) (if (equal b (minus 1)) (c!:cval (list (
quote iminus) a) env) (c!:builtin_two u env))))))))))

(put (quote itimes2) (quote c!:code) (function c!:citimes2))

(de c!:cminus (u env) (prog (a b) (setq a (s!:improve (cadr u))) (return (if 
(numberp a) (c!:cval (minus a) env) (if (eqcar a (quote minus)) (c!:cval (
cadr a) env) (c!:ccall (car u) (cdr u) env))))))

(put (quote minus) (quote c!:code) (function c!:cminus))

(de c!:ceq (x env) (prog (a1 a2 r rr) (setq a1 (s!:improve (cadr x))) (setq 
a2 (s!:improve (caddr x))) (if (equal a1 nil) (return (c!:cval (list (quote 
null) a2) env)) (if (equal a2 nil) (return (c!:cval (list (quote null) a1) 
env)))) (setq rr (c!:pareval (list a1 a2) env)) (c!:outop (quote eq) (setq r 
(c!:newreg)) (car rr) (cadr rr)) (return r)))

(put (quote eq) (quote c!:code) (function c!:ceq))

(de c!:cequal (x env) (prog (a1 a2 r rr) (setq a1 (s!:improve (cadr x))) (
setq a2 (s!:improve (caddr x))) (if (equal a1 nil) (return (c!:cval (list (
quote null) a2) env)) (if (equal a2 nil) (return (c!:cval (list (quote null) 
a1) env)))) (setq rr (c!:pareval (list a1 a2) env)) (c!:outop (if (or (
c!:eqvalid a1) (c!:eqvalid a2)) (quote eq) (quote equal)) (setq r (c!:newreg)
) (car rr) (cadr rr)) (return r)))

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

(de c!:comsublis (x) (if (c!:atomkeys (cadr x)) (cons (quote subla) (cdr x)) 
nil))

(put (quote sublis) (quote c!:compile_macro) (function c!:comsublis))

(de c!:comassoc (x) (if (or (c!:certainlyatom (cadr x)) (c!:atomkeys (caddr x
))) (cons (quote atsoc) (cdr x)) nil))

(put (quote assoc) (quote c!:compile_macro) (function c!:comassoc))

(put (quote assoc!*!*) (quote c!:compile_macro) (function c!:comassoc))

(de c!:commember (x) (if (or (c!:certainlyatom (cadr x)) (c!:atomlist (caddr 
x))) (cons (quote memq) (cdr x)) nil))

(put (quote member) (quote c!:compile_macro) (function c!:commember))

(de c!:comdelete (x) (if (or (c!:certainlyatom (cadr x)) (c!:atomlist (caddr 
x))) (cons (quote deleq) (cdr x)) nil))

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
caddr x)) (if (equal a1 nil) (return (c!:cjumpif a2 env d2 d1)) (if (equal a2
nil) (return (c!:cjumpif a1 env d2 d1)))) (setq r (c!:pareval (list a1 a2) 
env)) (c!:endblock (cons (quote ifeq) r) (list d1 d2))))

(put (quote eq) (quote c!:ctest) (function c!:ctesteq))

(de c!:ctesteqcar (x env d1 d2) (prog (a1 a2 r d3) (setq a1 (cadr x)) (setq 
a2 (caddr x)) (setq d3 (c!:my_gensym)) (setq r (c!:pareval (list a1 a2) env))
(c!:endblock (list (quote ifatom) (car r)) (list d2 d3)) (c!:startblock d3) 
(c!:outop (quote qcar) (car r) nil (car r)) (c!:endblock (cons (quote ifeq) r
) (list d1 d2))))

(put (quote eqcar) (quote c!:ctest) (function c!:ctesteqcar))

(global (quote (least_fixnum greatest_fixnum)))

(setq least_fixnum (minus (expt 2 27)))

(setq greatest_fixnum (difference (expt 2 27) 1))

(de c!:small_number (x) (and (fixp x) (geq x least_fixnum) (leq x 
greatest_fixnum)))

(de c!:eqvalid (x) (if (atom x) (c!:small_number x) (if (flagp (car x) (quote
c!:fixnum_fn)) t (and (equal (car x) (quote quote)) (or (idp (cadr x)) (
c!:small_number (cadr x)))))))

(flag (quote (iplus iplus2 idifference iminus itimes itimes2)) (quote 
c!:fixnum_fn))

(de c!:ctestequal (x env d1 d2) (prog (a1 a2 r) (setq a1 (s!:improve (cadr x)
)) (setq a2 (s!:improve (caddr x))) (if (equal a1 nil) (return (c!:cjumpif a2
env d2 d1)) (if (equal a2 nil) (return (c!:cjumpif a1 env d2 d1)))) (setq r 
(c!:pareval (list a1 a2) env)) (c!:endblock (cons (if (or (c!:eqvalid a1) (
c!:eqvalid a2)) (quote ifeq) (quote ifequal)) r) (list d1 d2))))

(put (quote equal) (quote c!:ctest) (function c!:ctestequal))

(de c!:ctestilessp (x env d1 d2) (prog (r) (setq r (c!:pareval (list (cadr x)
(caddr x)) env)) (c!:endblock (cons (quote ifilessp) r) (list d1 d2))))

(put (quote ilessp) (quote c!:ctest) (function c!:ctestilessp))

(de c!:ctestigreaterp (x env d1 d2) (prog (r) (setq r (c!:pareval (list (cadr
x) (caddr x)) env)) (c!:endblock (cons (quote ifigreaterp) r) (list d1 d2)))
)

(put (quote igreaterp) (quote c!:ctest) (function c!:ctestigreaterp))

(de c!:ctestand (x env d1 d2) (prog (next) (prog (var1166) (setq var1166 (cdr
x)) lab1165 (if (null var1166) (return nil)) (prog (a) (setq a (car var1166)
) (progn (setq next (c!:my_gensym)) (c!:cjumpif a env next d2) (c!:startblock
next))) (setq var1166 (cdr var1166)) (go lab1165)) (c!:endblock (quote goto)
(list d1))))

(put (quote and) (quote c!:ctest) (function c!:ctestand))

(de c!:ctestor (x env d1 d2) (prog (next) (prog (var1168) (setq var1168 (cdr 
x)) lab1167 (if (null var1168) (return nil)) (prog (a) (setq a (car var1168))
(progn (setq next (c!:my_gensym)) (c!:cjumpif a env d1 next) (c!:startblock 
next))) (setq var1168 (cdr var1168)) (go lab1167)) (c!:endblock (quote goto) 
(list d2))))

(put (quote or) (quote c!:ctest) (function c!:ctestor))

(progn (put (quote abs) (quote c!:c_entrypoint) "Labsval") (put (quote append
) (quote c!:c_entrypoint) "Lappend") (put (quote apply0) (quote 
c!:c_entrypoint) "Lapply0") (put (quote apply1) (quote c!:c_entrypoint) 
"Lapply1") (put (quote apply2) (quote c!:c_entrypoint) "Lapply2") (put (quote
apply3) (quote c!:c_entrypoint) "Lapply3") (put (quote ash1) (quote 
c!:c_entrypoint) "Lash1") (put (quote assoc) (quote c!:c_entrypoint) "Lassoc"
) (put (quote atan) (quote c!:c_entrypoint) "Latan") (put (quote atom) (quote
c!:c_entrypoint) "Latom") (put (quote atsoc) (quote c!:c_entrypoint) 
"Latsoc") (put (quote batchp) (quote c!:c_entrypoint) "Lbatchp") (put (quote 
boundp) (quote c!:c_entrypoint) "Lboundp") (put (quote bps!-putv) (quote 
c!:c_entrypoint) "Lbpsputv") (put (quote caaaar) (quote c!:c_entrypoint) 
"Lcaaaar") (put (quote caaadr) (quote c!:c_entrypoint) "Lcaaadr") (put (quote
caaar) (quote c!:c_entrypoint) "Lcaaar") (put (quote caadar) (quote 
c!:c_entrypoint) "Lcaadar") (put (quote caaddr) (quote c!:c_entrypoint) 
"Lcaaddr") (put (quote caadr) (quote c!:c_entrypoint) "Lcaadr") (put (quote 
caar) (quote c!:c_entrypoint) "Lcaar") (put (quote cadaar) (quote 
c!:c_entrypoint) "Lcadaar") (put (quote cadadr) (quote c!:c_entrypoint) 
"Lcadadr") (put (quote cadar) (quote c!:c_entrypoint) "Lcadar") (put (quote 
caddar) (quote c!:c_entrypoint) "Lcaddar") (put (quote cadddr) (quote 
c!:c_entrypoint) "Lcadddr") (put (quote caddr) (quote c!:c_entrypoint) 
"Lcaddr") (put (quote cadr) (quote c!:c_entrypoint) "Lcadr") (put (quote car)
(quote c!:c_entrypoint) "Lcar") (put (quote cdaaar) (quote c!:c_entrypoint) 
"Lcdaaar") (put (quote cdaadr) (quote c!:c_entrypoint) "Lcdaadr") (put (quote
cdaar) (quote c!:c_entrypoint) "Lcdaar") (put (quote cdadar) (quote 
c!:c_entrypoint) "Lcdadar") (put (quote cdaddr) (quote c!:c_entrypoint) 
"Lcdaddr") (put (quote cdadr) (quote c!:c_entrypoint) "Lcdadr") (put (quote 
cdar) (quote c!:c_entrypoint) "Lcdar") (put (quote cddaar) (quote 
c!:c_entrypoint) "Lcddaar") (put (quote cddadr) (quote c!:c_entrypoint) 
"Lcddadr") (put (quote cddar) (quote c!:c_entrypoint) "Lcddar") (put (quote 
cdddar) (quote c!:c_entrypoint) "Lcdddar") (put (quote cddddr) (quote 
c!:c_entrypoint) "Lcddddr") (put (quote cdddr) (quote c!:c_entrypoint) 
"Lcdddr") (put (quote cddr) (quote c!:c_entrypoint) "Lcddr") (put (quote cdr)
(quote c!:c_entrypoint) "Lcdr") (put (quote char!-code) (quote 
c!:c_entrypoint) "Lchar_code") (put (quote close) (quote c!:c_entrypoint) 
"Lclose") (put (quote code!-char) (quote c!:c_entrypoint) "Lcode_char") (put 
(quote codep) (quote c!:c_entrypoint) "Lcodep") (put (quote compress) (quote 
c!:c_entrypoint) "Lcompress") (put (quote constantp) (quote c!:c_entrypoint) 
"Lconstantp") (put (quote date) (quote c!:c_entrypoint) "Ldate") (put (quote 
deleq) (quote c!:c_entrypoint) "Ldeleq") (put (quote delete) (quote 
c!:c_entrypoint) "Ldelete") (put (quote digit) (quote c!:c_entrypoint) 
"Ldigitp") (put (quote divide) (quote c!:c_entrypoint) "Ldivide") (put (quote
eject) (quote c!:c_entrypoint) "Leject") (put (quote endp) (quote 
c!:c_entrypoint) "Lendp") (put (quote eq) (quote c!:c_entrypoint) "Leq") (put
(quote eqcar) (quote c!:c_entrypoint) "Leqcar") (put (quote eql) (quote 
c!:c_entrypoint) "Leql") (put (quote eqn) (quote c!:c_entrypoint) "Leqn") (
put (quote equal) (quote c!:c_entrypoint) "Lequal") (put (quote error) (quote
c!:c_entrypoint) "Lerror") (put (quote error1) (quote c!:c_entrypoint) 
"Lerror1") (put (quote evenp) (quote c!:c_entrypoint) "Levenp") (put (quote 
evlis) (quote c!:c_entrypoint) "Levlis") (put (quote explode) (quote 
c!:c_entrypoint) "Lexplode") (put (quote explode2) (quote c!:c_entrypoint) 
"Lexplodec") (put (quote explodec) (quote c!:c_entrypoint) "Lexplodec") (put 
(quote expt) (quote c!:c_entrypoint) "Lexpt") (put (quote fasldef) (quote 
c!:c_entrypoint) "Lfasldef") (put (quote faslstart) (quote c!:c_entrypoint) 
"Lfaslstart") (put (quote faslwrite) (quote c!:c_entrypoint) "Lfaslwrite") (
put (quote fix) (quote c!:c_entrypoint) "Ltruncate") (put (quote fixp) (quote
c!:c_entrypoint) "Lfixp") (put (quote flag) (quote c!:c_entrypoint) "Lflag")
(put (quote flagp!*!*) (quote c!:c_entrypoint) "Lflagp") (put (quote flagp) 
(quote c!:c_entrypoint) "Lflagp") (put (quote flagpcar) (quote 
c!:c_entrypoint) "Lflagpcar") (put (quote float) (quote c!:c_entrypoint) 
"Lfloat") (put (quote floatp) (quote c!:c_entrypoint) "Lfloatp") (put (quote 
fluidp) (quote c!:c_entrypoint) "Lsymbol_specialp") (put (quote gcdn) (quote 
c!:c_entrypoint) "Lgcd") (put (quote gctime) (quote c!:c_entrypoint) 
"Lgctime") (put (quote gensym) (quote c!:c_entrypoint) "Lgensym") (put (quote
gensym1) (quote c!:c_entrypoint) "Lgensym1") (put (quote geq) (quote 
c!:c_entrypoint) "Lgeq") (put (quote get!*) (quote c!:c_entrypoint) "Lget") (
put (quote getenv) (quote c!:c_entrypoint) "Lgetenv") (put (quote getv) (
quote c!:c_entrypoint) "Lgetv") (put (quote globalp) (quote c!:c_entrypoint) 
"Lsymbol_globalp") (put (quote greaterp) (quote c!:c_entrypoint) "Lgreaterp")
(put (quote iadd1) (quote c!:c_entrypoint) "Liadd1") (put (quote idifference
) (quote c!:c_entrypoint) "Lidifference") (put (quote idp) (quote 
c!:c_entrypoint) "Lsymbolp") (put (quote igreaterp) (quote c!:c_entrypoint) 
"Ligreaterp") (put (quote ilessp) (quote c!:c_entrypoint) "Lilessp") (put (
quote iminus) (quote c!:c_entrypoint) "Liminus") (put (quote iminusp) (quote 
c!:c_entrypoint) "Liminusp") (put (quote indirect) (quote c!:c_entrypoint) 
"Lindirect") (put (quote integerp) (quote c!:c_entrypoint) "Lintegerp") (put 
(quote intern) (quote c!:c_entrypoint) "Lintern") (put (quote iplus2) (quote 
c!:c_entrypoint) "Liplus2") (put (quote iquotient) (quote c!:c_entrypoint) 
"Liquotient") (put (quote iremainder) (quote c!:c_entrypoint) "Liremainder") 
(put (quote irightshift) (quote c!:c_entrypoint) "Lirightshift") (put (quote 
isub1) (quote c!:c_entrypoint) "Lisub1") (put (quote itimes2) (quote 
c!:c_entrypoint) "Litimes2") (put (quote length) (quote c!:c_entrypoint) 
"Llength") (put (quote lengthc) (quote c!:c_entrypoint) "Llengthc") (put (
quote leq) (quote c!:c_entrypoint) "Lleq") (put (quote lessp) (quote 
c!:c_entrypoint) "Llessp") (put (quote linelength) (quote c!:c_entrypoint) 
"Llinelength") (put (quote liter) (quote c!:c_entrypoint) "Lalpha_char_p") (
put (quote load!-module) (quote c!:c_entrypoint) "Lload_module") (put (quote 
lposn) (quote c!:c_entrypoint) "Llposn") (put (quote macro!-function) (quote 
c!:c_entrypoint) "Lmacro_function") (put (quote macroexpand!-1) (quote 
c!:c_entrypoint) "Lmacroexpand_1") (put (quote macroexpand) (quote 
c!:c_entrypoint) "Lmacroexpand") (put (quote make!-bps) (quote 
c!:c_entrypoint) "Lget_bps") (put (quote make!-global) (quote c!:c_entrypoint
) "Lmake_global") (put (quote make!-simple!-string) (quote c!:c_entrypoint) 
"Lsmkvect") (put (quote make!-special) (quote c!:c_entrypoint) 
"Lmake_special") (put (quote mapstore) (quote c!:c_entrypoint) "Lmapstore") (
put (quote max2) (quote c!:c_entrypoint) "Lmax2") (put (quote member) (quote 
c!:c_entrypoint) "Lmember") (put (quote memq) (quote c!:c_entrypoint) "Lmemq"
) (put (quote min2) (quote c!:c_entrypoint) "Lmin2") (put (quote minus) (
quote c!:c_entrypoint) "Lminus") (put (quote minusp) (quote c!:c_entrypoint) 
"Lminusp") (put (quote mkquote) (quote c!:c_entrypoint) "Lmkquote") (put (
quote mkvect) (quote c!:c_entrypoint) "Lmkvect") (put (quote mod) (quote 
c!:c_entrypoint) "Lmod") (put (quote modular!-difference) (quote 
c!:c_entrypoint) "Lmodular_difference") (put (quote modular!-expt) (quote 
c!:c_entrypoint) "Lmodular_expt") (put (quote modular!-minus) (quote 
c!:c_entrypoint) "Lmodular_minus") (put (quote modular!-number) (quote 
c!:c_entrypoint) "Lmodular_number") (put (quote modular!-plus) (quote 
c!:c_entrypoint) "Lmodular_plus") (put (quote modular!-quotient) (quote 
c!:c_entrypoint) "Lmodular_quotient") (put (quote modular!-reciprocal) (quote
c!:c_entrypoint) "Lmodular_reciprocal") (put (quote modular!-times) (quote 
c!:c_entrypoint) "Lmodular_times") (put (quote nconc) (quote c!:c_entrypoint)
"Lnconc") (put (quote neq) (quote c!:c_entrypoint) "Lneq") (put (quote not) 
(quote c!:c_entrypoint) "Lnull") (put (quote null) (quote c!:c_entrypoint) 
"Lnull") (put (quote numberp) (quote c!:c_entrypoint) "Lnumberp") (put (quote
oddp) (quote c!:c_entrypoint) "Loddp") (put (quote onep) (quote 
c!:c_entrypoint) "Lonep") (put (quote orderp) (quote c!:c_entrypoint) 
"Lorderp") (put (quote pagelength) (quote c!:c_entrypoint) "Lpagelength") (
put (quote pairp) (quote c!:c_entrypoint) "Lconsp") (put (quote plist) (quote
c!:c_entrypoint) "Lplist") (put (quote plusp) (quote c!:c_entrypoint) 
"Lplusp") (put (quote posn) (quote c!:c_entrypoint) "Lposn") (put (quote prin
) (quote c!:c_entrypoint) "Lprin") (put (quote prin1) (quote c!:c_entrypoint)
"Lprin") (put (quote prin2) (quote c!:c_entrypoint) "Lprinc") (put (quote 
princ) (quote c!:c_entrypoint) "Lprinc") (put (quote print) (quote 
c!:c_entrypoint) "Lprint") (put (quote printc) (quote c!:c_entrypoint) 
"Lprintc") (put (quote put) (quote c!:c_entrypoint) "Lputprop") (put (quote 
putv!-char) (quote c!:c_entrypoint) "Lsputv") (put (quote putv) (quote 
c!:c_entrypoint) "Lputv") (put (quote qcaar) (quote c!:c_entrypoint) "Lcaar")
(put (quote qcadr) (quote c!:c_entrypoint) "Lcadr") (put (quote qcar) (quote
c!:c_entrypoint) "Lcar") (put (quote qcdar) (quote c!:c_entrypoint) "Lcdar")
(put (quote qcddr) (quote c!:c_entrypoint) "Lcddr") (put (quote qcdr) (quote
c!:c_entrypoint) "Lcdr") (put (quote qgetv) (quote c!:c_entrypoint) "Lgetv")
(put (quote rdf) (quote c!:c_entrypoint) "Lrdf") (put (quote rds) (quote 
c!:c_entrypoint) "Lrds") (put (quote read) (quote c!:c_entrypoint) "Lread") (
put (quote readch) (quote c!:c_entrypoint) "Lreadch") (put (quote reclaim) (
quote c!:c_entrypoint) "Lgc") (put (quote remd) (quote c!:c_entrypoint) 
"Lremd") (put (quote remflag) (quote c!:c_entrypoint) "Lremflag") (put (quote
remob) (quote c!:c_entrypoint) "Lunintern") (put (quote remprop) (quote 
c!:c_entrypoint) "Lremprop") (put (quote representation) (quote 
c!:c_entrypoint) "Lrepresentation") (put (quote reverse) (quote 
c!:c_entrypoint) "Lreverse") (put (quote reversip) (quote c!:c_entrypoint) 
"Lnreverse") (put (quote rplaca) (quote c!:c_entrypoint) "Lrplaca") (put (
quote rplacd) (quote c!:c_entrypoint) "Lrplacd") (put (quote schar) (quote 
c!:c_entrypoint) "Lsgetv") (put (quote seprp) (quote c!:c_entrypoint) 
"Lwhitespace_char_p") (put (quote set!-small!-modulus) (quote c!:c_entrypoint
) "Lset_small_modulus") (put (quote set) (quote c!:c_entrypoint) "Lset") (put
(quote smemq) (quote c!:c_entrypoint) "Lsmemq") (put (quote spaces) (quote 
c!:c_entrypoint) "Lxtab") (put (quote special!-char) (quote c!:c_entrypoint) 
"Lspecial_char") (put (quote special!-form!-p) (quote c!:c_entrypoint) 
"Lspecial_form_p") (put (quote spool) (quote c!:c_entrypoint) "Lspool") (put 
(quote stop) (quote c!:c_entrypoint) "Lstop") (put (quote stringp) (quote 
c!:c_entrypoint) "Lstringp") (put (quote subla) (quote c!:c_entrypoint) 
"Lsubla") (put (quote sublis) (quote c!:c_entrypoint) "Lsublis") (put (quote 
subst) (quote c!:c_entrypoint) "Lsubst") (put (quote symbol!-env) (quote 
c!:c_entrypoint) "Lsymbol_env") (put (quote symbol!-function) (quote 
c!:c_entrypoint) "Lsymbol_function") (put (quote symbol!-name) (quote 
c!:c_entrypoint) "Lsymbol_name") (put (quote symbol!-set!-definition) (quote 
c!:c_entrypoint) "Lsymbol_set_definition") (put (quote symbol!-set!-env) (
quote c!:c_entrypoint) "Lsymbol_set_env") (put (quote symbol!-value) (quote 
c!:c_entrypoint) "Lsymbol_value") (put (quote system) (quote c!:c_entrypoint)
"Lsystem") (put (quote terpri) (quote c!:c_entrypoint) "Lterpri") (put (
quote threevectorp) (quote c!:c_entrypoint) "Lthreevectorp") (put (quote time
) (quote c!:c_entrypoint) "Ltime") (put (quote ttab) (quote c!:c_entrypoint) 
"Lttab") (put (quote tyo) (quote c!:c_entrypoint) "Ltyo") (put (quote 
unmake!-global) (quote c!:c_entrypoint) "Lunmake_global") (put (quote 
unmake!-special) (quote c!:c_entrypoint) "Lunmake_special") (put (quote upbv)
(quote c!:c_entrypoint) "Lupbv") (put (quote vectorp) (quote c!:c_entrypoint
) "Lsimple_vectorp") (put (quote verbos) (quote c!:c_entrypoint) "Lverbos") (
put (quote wrs) (quote c!:c_entrypoint) "Lwrs") (put (quote xcons) (quote 
c!:c_entrypoint) "Lxcons") (put (quote xtab) (quote c!:c_entrypoint) "Lxtab")
(put (quote zerop) (quote c!:c_entrypoint) "Lzerop") (put (quote cons) (
quote c!:direct_entrypoint) (cons 2 "cons")) (put (quote ncons) (quote 
c!:direct_entrypoint) (cons 1 "ncons")) (put (quote list2) (quote 
c!:direct_entrypoint) (cons 2 "list2")) (put (quote list2!*) (quote 
c!:direct_entrypoint) (cons 3 "list2star")) (put (quote acons) (quote 
c!:direct_entrypoint) (cons 3 "acons")) (put (quote list3) (quote 
c!:direct_entrypoint) (cons 3 "list3")) (put (quote plus2) (quote 
c!:direct_entrypoint) (cons 2 "plus2")) (put (quote difference) (quote 
c!:direct_entrypoint) (cons 2 "difference2")) (put (quote add1) (quote 
c!:direct_entrypoint) (cons 1 "add1")) (put (quote sub1) (quote 
c!:direct_entrypoint) (cons 1 "sub1")) (put (quote get) (quote 
c!:direct_entrypoint) (cons 2 "get")) (put (quote lognot) (quote 
c!:direct_entrypoint) (cons 1 "lognot")) (put (quote ash) (quote 
c!:direct_entrypoint) (cons 2 "ash")) (put (quote quotient) (quote 
c!:direct_entrypoint) (cons 2 "quot2")) (put (quote remainder) (quote 
c!:direct_entrypoint) (cons 2 "Cremainder")) (put (quote times2) (quote 
c!:direct_entrypoint) (cons 2 "times2")) (put (quote minus) (quote 
c!:direct_entrypoint) (cons 1 "negate")) (put (quote rational) (quote 
c!:direct_entrypoint) (cons 1 "rational")) (put (quote lessp) (quote 
c!:direct_predicate) (cons 2 "lessp2")) (put (quote leq) (quote 
c!:direct_predicate) (cons 2 "lesseq2")) (put (quote greaterp) (quote 
c!:direct_predicate) (cons 2 "greaterp2")) (put (quote geq) (quote 
c!:direct_predicate) (cons 2 "geq2")) (put (quote zerop) (quote 
c!:direct_predicate) (cons 1 "zerop")) "C entrypoints established")

(flag (quote (atom atsoc codep constantp deleq digit endp eq eqcar evenp eql 
fixp flagp flagpcar floatp get globalp iadd1 idifference idp igreaterp ilessp
iminus iminusp indirect integerp iplus2 irightshift isub1 itimes2 liter memq
minusp modular!-difference modular!-expt modular!-minus modular!-number 
modular!-plus modular!-times not null numberp onep pairp plusp qcaar qcadr 
qcar qcdar qcddr qcdr remflag remprop reversip seprp special!-form!-p stringp
symbol!-env symbol!-name symbol!-value threevectorp vectorp zerop)) (quote 
c!:no_errors))


% end of file
