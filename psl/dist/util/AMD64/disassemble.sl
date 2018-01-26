%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:  pxu/disassemble.sl -  disassembler for i486 
%
% Author: H. Melenk , ZIB Berlin
%
% Date :  4-May-1994
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Revisions:
%
(compiletime (load common))

(fluid '(*gassyntax))

(fluid '(bytes* lth* reg* xreg* regnr* segment*  symvalhigh symfnchigh *curradr* *currinst*))

          (de getwrd(a)(getmem a))

          (de getfunctionaddress(fkt) 
             (wshift(wshift (cdr (getd fkt)) 8) -8))

          (de idnumberp(x)
           (cond ((not (posintp x)) nil)
                 ((greaterp x (lshift maxsymbols 1)) nil)
                 ((stringp (symnam x)) x)
                 (t nil)))

          (de safe!-int2id(x) (if (idnumberp x) (mkid x) (mkid 32)))
          (copyd 'ttab 'tab)


(de word2addr (n) (times n 4))
(de addr2word (n) (quotient n 4))
(de jump2word (n) (quotient n 6))


(fluid '(eregs rregs !*comment fktend !*hardjump instrs1 instrs2 instrs3 instrs*))

% establish instruction list at compile time

(compiletime (progn

(fluid '(instrs*))

(setq  instrs1 nil)
(setq  instrs2 nil)
(setq  instrs3 nil)

(dm fi(u)
  (prog (name adr)
    (pop u)
    (setq adr (pop u))
    (setq name (pop u))
    (while u
      (set  instrs* (cons `(,adr ,name .,(pop u)) (eval  instrs*)))
      (setq adr (add1 adr)))))

% fillin standard instructions

(setq instrs* 'instrs1)

(fi 16#00 add ((E b)(G b))
              ((E v)(G v))
              ((G b)(E b))
              ((G v)(E v))
              (AL   (I b))
              (eAX  (I v)))

(fi 16#08 or  ((E b)(G b))
              ((E v)(G v))
              ((G b)(E b))
              ((G v)(E v))
              (AL   (I b))
              (eAX  (I v)))

(fi 16#10 adc ((E b)(G b))
              ((E v)(G v))
              ((G b)(E b))
              ((G v)(E v))
              (AL   (I b))
              (eAX  (I v)))


(fi 16#18 sbb ((E b)(G b))
              ((E v)(G v))
              ((G b)(E b))
              ((G v)(E v))
              (AL   (I b))
              (eAX  (I v)))

(fi 16#20 and ((E b)(G b))
              ((E v)(G v))
              ((G b)(E b))
              ((G v)(E v))
              (AL   (I b))
              (eAX  (I v)))

(fi 16#28 sub ((E b)(G b))
              ((E v)(G v))
              ((G b)(E b))
              ((G v)(E v))
              (AL   (I b))
              (eAX  (I v)))

(fi 16#30 xor ((E b)(G b))
              ((E v)(G v))
              ((G b)(E b))
              ((G v)(E v))
              (AL   (I b))
              (eAX  (I v)))

(fi 16#36 ss: (nil))

(fi 16#38 cmp ((E b)(G b))
              ((E v)(G v))
              ((G b)(E b))
              ((G v)(E v))
              (AL   (I b))
              (eAX  (I v)))

%% not present in 64bit mode
%(fi 16#40 inc (rax) (rcx) (rdx) (rbx) (rsp) (rbp) (rsi) (rdi))

(fi 16#40 rex   (" ") (b) (x) (xb) (r) (rb) (rx) (rxb)
                (" ") (b) (x) (xb) (r) (rb) (rx) (rxb))

(fi 16#50 push (rax) (rcx) (rdx) (rbx) (rsp) (rbp) (rsi) (rdi))

(fi 16#58 pop  (rax) (rcx) (rdx) (rbx) (rsp) (rbp) (rsi) (rdi))

(fi 16#60 pusha nil)

(fi 16#61 popa  nil)

(fi 16#70 jo ((j b)))
(fi 16#71 jno ((j b)))
(fi 16#72 jb ((j b)))
(fi 16#73 jnb ((j b)))
(fi 16#74 jz ((j b)))
(fi 16#75 jnz ((j b)))
(fi 16#76 jbe ((j b)))
(fi 16#77 jbne ((j b)))
(fi 16#78 js ((j b)))
(fi 16#79 jns ((j b)))
(fi 16#7a jp ((j b)))
(fi 16#7b jnp ((j b)))
(fi 16#7c jl ((j b)))
(fi 16#7d jnl ((j b)))
(fi 16#7e jle ((j b)))
(fi 16#7f jnle ((j b)))

(fi 16#80 Grp1 ((E b)(I b)) ((E v)(I v)) nil ((E v)(I b))) % grp1

(fi 16#84 test ((G b) (E b)) ((G v) (E v)))

(fi 16#86 xchg ((E b) (G b)) ((E v) (G v)))

(fi 16#88 movb ((E b)(G b)))
(fi 16#89 mov  ((E v) (G v)))
(fi 16#8a movb ((G b)(E b)))
(fi 16#8b mov  ((G v) (E v)))

(fi 16#8d lea  ((G v) (M)))

(fi 16#90 nop (nil))

(fi 16#91 xchg (ecx eax)(edx eax)(ebx eax)(esp eax)(ebp eax)(esi eax)(edi eax))

(fi 16#98 convert (nil))

(fi 16#9a call (A p))

(fi 16#9b fwait (nil))

(fi 16#a0 mov (AL (O b)) (eax (O v)) ((O b) AL) ((O v) EAX))

(fi 16#b0 mov (AL (I b))(CL (I b))(DL (I b))(BL (I b))
              (AH (I b))(CH (I b))(DH (I b))(BH (I b)))

(fi 16#b8 mov (EAX (I v))(ECX (I v))(EDX (I v))(EBX (I v))
              (ESP (I v))(EBP (I v))(ESI (I v))(EDI (I v)))

(fi 16#c0 shift ((E b)(I b)) ((E v)(I b)))

(fi 16#c3 ret (nil))

(fi 16#c6 mov ((E b)(I b)) ((E v)(I v)))

(fi 16#d0 shift ((E b) 1) ((E v) 1) ((E b) CL) ((E v) CL))

(fi 16#d8 x87fpu ((ST fl)) ((ST fl)) ((ST fl)) ((ST fl)) ((ST fl)) ((ST fl)) ((ST fl)) ((ST fl)))

(fi 16#e8 call ((A v)))

(fi 16#e9 jmp ((J v)) ((A p)) ((J b)))

(fi 16#f6  Grp3 ((E b)) ((E v)))

(fi 16#ff  Grp5 ((E v)))   % grp5

% second group

(setq instrs* 'instrs2)

(fi 16#10 (sse mov) ((V s) (W s)) ((W s) (V s)))
(fi 16#12 (sse movl) ((V q) (UMW q)) ((M q) (V q)))
(fi 16#14 (sse unpckl) ((V s) (W s)) ((W s) (V s)))
(fi 16#16 (sse movh) ((V q) (UM q)) ((M q) (V q)))

(fi 16#28 (sse movap) ((V) (W)) ((W) (V)))
(fi 16#2a (sse cvti) ((V) (W)))

(fi 16#2c (sse cvtt) ((G) (W)))
(fi 16#2d (sse cvt2i) ((G) (W)))
(fi 16#2e (sse ucomis) ((V) (W)))
(fi 16#2f (sse comis) ((V) (W)))

(fi 16#51 (sse sqrt) ((V) (W)))
(fi 16#52 (sse rsqrt) ((V) (W)))
(fi 16#53 (sse rcp) ((V) (W)))
(fi 16#54 (sse and) ((V) (W)))
(fi 16#55 (sse andn) ((V) (W)))
(fi 16#56 (sse or) ((V) (W)))
(fi 16#57 (sse xor) ((V) (W)))
(fi 16#58 (sse add) ((V) (W)))
(fi 16#59 (sse mul) ((V) (W)))
(fi 16#5a (sse cvts) ((V) (W)))
(fi 16#5b (sse cvtd) ((V) (W)))
(fi 16#5c (sse sub) ((V) (W)))
(fi 16#5d (sse min) ((V) (W)))
(fi 16#5e (sse div) ((V) (W)))
(fi 16#5f (sse max) ((V) (W)))

(fi 16#6e (sse movq) ((V q) (E q)))
(fi 16#6f (sse movwa) ((W q) (V q)))
(fi 16#7e (sse movq) ((E q) (V q)))
(fi 16#7f (sse movwa) ((V q) (W q)))

(fi 16#80 JO  ((j v)))
(fi 16#81 JNO ((j v)))
(fi 16#82 Jb  ((j v)))
(fi 16#83 Jnb ((j v)))
(fi 16#84 Jz  ((j v)))
(fi 16#85 Jnz ((j v)))
(fi 16#86 Jbe ((j v)))
(fi 16#87 Jnbe((j v)))
(fi 16#88 Js  ((j v)))
(fi 16#89 Jns ((j v)))
(fi 16#8a Jp  ((j v)))
(fi 16#8b Jnp ((j v)))
(fi 16#8c Jl  ((j v)))
(fi 16#8d Jnl ((j v)))
(fi 16#8e Jle ((j v)))
(fi 16#8f Jnle((j v)))

(fi 16#ae Grp15 ((M)))

(fi 16#af imul ((G v)(E v)))

(fi 16#d6 (sse movq) ((W) (V)))
(fi 16#db (sse pand) ((V) (W)))
(fi 16#df (sse pandn) ((V) (W)))
(fi 16#eb (sse por) ((V) (W)))
(fi 16#ef (sse pxor) ((V) (W)))

(dm make-the-instructions(u)
  `(progn
     (setq instrs1 ',instrs1)
     (setq instrs2 ',instrs2)
     (setq instrs3 ',instrs3)
     ))

))

(make-the-instructions)



(setq eregs  '("eax" "ecx" "edx" "ebx" "esp" "ebp" "esi" "edi"))
(setq rregs  '("rax" "rcx" "rdx" "rbx" "rsp" "rbp" "rsi" "rdi"
               "r8" "r9" "r10" "r11" "r12" "r13" "r14" "r15"))

(fluid '( the-instruction* addr* rex_w rex_r rex_x rex_b size-override* sse-prefix* !0f-prefix* mod-is-3*
			   byte-operand*))

(de decode(p1 pl addr*)
  (prog(i lth name with-rex)
      (setq rex_w nil rex_r nil rex_x nil rex_b nil size-override* nil sse-prefix* nil !0f-prefix* nil
	    mod-is-3* nil)
      (setq lth 1)
      (when (or (weq p1 16#66) (weq p1 16#67))
	 (when (weq p1 16#66) (setq sse-prefix* p1))
         (setq size-override* p1)
	 (setq p1 (pop pl))
         (setq lth 2))
      (when (or (weq p1 16#f2) (weq p1 16#f3))
         (setq sse-prefix* p1)
	 (setq p1 (pop pl))
         (setq lth (add1 lth)))
      (when (and (wlessp p1 16#50) (wgeq p1 16#40))
         (decode-rex-prefix p1)
	 %% 66 prefix is ignored when REX.W bit is set
	 (when (and rex_w (eq size-override* 16#66)) (setq size-override* nil))
         (setq p1 (pop pl))
         (setq lth (add1 lth)))
      (setq i (assoc p1 instrs1))
      (when (and i (eq (cadr i) 'x87fpu))
	(return (decode-x87fpu p1 pl addr* lth)))
      (when (eq p1 16#0f)
            (setq !0f-prefix* t)
            (setq p1 (pop pl))
            (setq lth (add1 lth))
            (setq i (assoc p1 instrs2)))
      (when (not i)(return (cons lth nil)))
      (setq the-instruction* i)
      (setq name (cadr i))
      (when (eq name 'ss:) (setq segment* "ss"))
      (setq i (decode-operands pl lth (cddr i)))
      (return `(,(car i)  % lth
                ,name
                .,(cdr i)))))

(de decode-rex-prefix (p1)
   (when (eq 8 (wand p1 8)) (setq rex_w t))
   (when (eq 4 (wand p1 4)) (setq rex_r t))
   (when (eq 2 (wand p1 2)) (setq rex_x t))
   (when (eq 1 (wand p1 1)) (setq rex_b t))
)


(de decode-operands-special-pattern-cases (bytes lth pat)
  %
  % handle a number of special cases where the operands are interpreted
  %  differently if some prefix is present
  %				%
  (cond ((and (pairp the-instruction*)
	      (pairp (cdr the-instruction*))
	      (equal (cadr the-instruction*) '(sse movq)) 
	      (eq sse-prefix* 16#f3))
	 '((V) (W)))
	(t nil)))

(de decode-operands (bytes* lth* pat)
  (prog (r reg* xreg* byte-operand* x)
    (setq x (decode-operands-special-pattern-cases bytes* lth* pat))
    (when (and x (pairp x)) (setq pat x))
    (when (eqcar pat nil) (go done))
    (push (cons 'op1 (decode-operand1 (pop pat) t)) r)
    (when pat
        (push (cons 'op2 (decode-operand1 (pop pat) nil)) r))
 done
    (when *gassyntax
      (setq reg* (bldmsg "%%%w" reg*) xreg* (bldmsg "%%%w" xreg*)))
    (setq r (subst reg* 'reg r))
    (setq r (subst xreg* 'xreg r))
    (return (cons lth* r))))

(deflist '((eax rax) (ebx rbx) (ecx rcx) (edx rdx) (ebp rbp) (esp rsp) (esi rsi) (edi rsi)) 'reg64)

(de decode-operand1(p firstop)
 (let(w)
  (cond ((and rex_w (setq w (get p 'reg64)))
	 (if *gassyntax (bldmsg "%%%w" w) w))
	((atom p) 
	 (if (and *gassyntax (idp p)) (bldmsg "%%%w" p) p))
        ((eq (car p) 'G) 
	 (if (eqcar (cdr p) 'b) (setq byte-operand* t))
	 'reg)
        ((eq (car p) 'V) 'xreg)
           % immediate byte
        ((equal p '(I b)) 
         (setq  lth* (add1 lth*))
         (pop bytes*))
           % immediate word
        ((equal p '(I v)) 
         (setq  lth* (plus 4 lth*))
         (bytes2word))
           % absolute address
        ((equal p '(A b)) 
         (setq  lth* (add1 lth*))
         (pop bytes*))
        ((equal p '(A v)) 
         (setq  lth* (plus 4 lth*))
         (bytes2word))
           % displacement (relative jump)
        ((equal p '(J b))
         (setq  lth* (add1 lth*))
	 (setq w (pop bytes*))
	 (when (greaterp w 127)(setq w (difference w 256)))
         (plus addr* w 2))
        ((equal p '(J v))
         (setq  lth* (plus 4 lth*))
         (plus addr* (bytes2word) lth*))
           % mod R/M
        ((eqcar p 'E) (decode-modrm p))
        ((eqcar p 'R) (decode-modrm p))
        ((eqcar p 'M) (decode-modrm p))
	((eqcar p 'W) (decode-modrm p))
	((eqcar p 'UMW) (decode-modrm p))
	((eqcar p 'UM) (decode-modrm p))
             % offset
        ((equal p '(o b))
         (setq lth!* (plus lth!* 1))
         (pop bytes!*))

        ((equal p '(o v))
         (setq lth!* (plus lth!* 4))
         (bytes2word))
         
	((eqcar p 'ST) % x87fpu instruction
	 (if (eq (wand (car bytes*) 2#11000000) 2#11000000)
	     (decode-x87fpu p bytes* addr* 0)
	   (decode-modrm p)))
        (t (terpri)
           (prin2t (list "dont know operand declaration:" p))
           (stderror "disassemble")))))

(de decode-modrm(p)
   (prog(mod rm b w usexmm)
     (setq b (pop bytes*)) (setq  lth* (add1 lth*))
     (setq mod (wshift b -6))
     (setq regnr* (wand 7 (wshift b -3)))
     (when rex_r (setq regnr* (wplus2 regnr* 8)))
     (setq reg* (reg-m regnr*))
     (setq xreg* (reg-xmm regnr*))
     (setq rm (wand 7 b))
     (setq usexmm (and !0f-prefix* (not (eqcar p 'E))))
     (when rex_b (setq rm (wplus2 rm 8)))
%       (terpri)(prin2t(list "modrm" b mod regnr* rm)) (print bytes*)
     (return
  (cond ((and (lessp mod 3)(or (eq rm 2#100) (eq rm 12)))
         (decode-sib p mod))
        ((and (eq mod 0)(eq rm 5))
                  % probably a sym*** reference
              (setq  lth* (plus 4 lth*))
              (setq w (bytes2word))
              (cond ((and (xgreaterp w symfnc)
                          (xgreaterp symfnchigh w))
                     (setq *comment
                      (bldmsg " -> %w" 
                       (safe-int2id (wshift (wdifference w symfnc) -3)))))
                    ((and (xgreaterp w symval)
                          (xgreaterp symvalhigh w))
                     (setq *comment
                      (bldmsg " -> %w" 
                       (safe-int2id (wshift (wdifference w symval) -3))))))
              (if *gassyntax 
                  (bldmsg "%w(%%rip)" w)
                (bldmsg "[rip%w0x%x]" (if (wlessp w 0) "-" "+") (if (wlessp w 0) (wminus w) w))))
        ((eq mod 0) (if *gassyntax
			(bldmsg "(%%%w)" (reg-m rm))
		      (bldmsg "[%w]" (reg-m rm) )))
        ((eq mod 1) 
              (setq  lth* (add1 lth*))
	      (if *gassyntax 
		  (bldmsg "%w(%%%w)" (pop bytes*)(reg-m rm))
		(bldmsg "[%w+%w]" (reg-m rm)(pop bytes*))))
        ((eq mod 2) 
              (setq  lth* (plus 4 lth*))
	      (if *gassyntax
		  (bldmsg "%w(%%%w)" (bytes2word) (reg-m rm))
		(bldmsg "[%w+%w]" (reg-m rm) (bytes2word))))
        ((eq mod 3)
	 (setq mod-is-3* t)
	 (bldmsg (if *gassyntax "%%%w" "%w") (if usexmm (reg-xmm rm) (reg-m rm)))
	 )) )))
              
(de decode-sib(p mod)
   (prog(scale index base offset seg b w)
     (setq b (pop bytes*))
     (setq  lth* (add1 lth*))
     (setq scale (lsh 1 (wshift b -6)))     
     (setq index (wand 7 (wshift b -3)))
     (when rex_x (setq index (wplus2 index 8)))
     (when (eq index 4) (setq index ""))  % erstmal
     (setq base (wand 7 b))
     (when rex_b (setq base (wplus2 base 8)))
     (setq offset "")
     (cond ((and (not rex_w) (eq size-override* 16#66)) (setq reg* (reg-m16 regnr*)))
	   ((or byte-operand* (and (not rex_w) (eq scale 1))) (setq reg* (reg-m8 regnr*))))
     (when (eq mod 1)
           (setq offset (pop bytes*))
	   (setq offset
		 (if (greaterp offset 127) 
		     (bldmsg "%w" (difference offset 256))
		   (bldmsg "+%w" offset)))
            (setq  lth* (add1 lth*)))
     (when (eq mod 2)
           (setq w (bytes2word))
           (setq offset (bldmsg "+%w" w))
            (setq  lth* (plus lth* 4)))
     (when (and (eq mod 0)(eq base 2#101))
           (setq  lth* (plus lth* 4))
           (setq w (bytes2word))
           (cond ((and (xgreaterp w symfnc)
                          (xgreaterp symfnchigh w))
                     (setq *comment
                      (bldmsg " -> %w"
                       (safe-int2id (wshift (wdifference w symfnc) -3)))))
                    ((and (xgreaterp w symval)
                          (xgreaterp symvalhigh w))
                     (setq *comment
                      (bldmsg " -> %w"
                       (safe-int2id (wshift (wdifference w symval) -3))))))
           (if *gassyntax 
	       (return (bldmsg "*0x%x%w" w index))
	     (return (bldmsg "[%x%w]" w index))))
     (setq seg
       (cond (segment* segment*)
             (t "")))
     (setq segment* nil)
     (if *gassyntax 
	 (return (bldmsg "%w(%%%w%w)" offset (reg-m base)
			 (if (equal index "") "" (bldmsg ",%%%w,%d" (reg-m index) scale))))
       (return (bldmsg "[%%%w%w%w]" (reg-m base) 
		       (if (equal index "") ""
			 (bldmsg "+%%%w*%w" (reg-m index) scale))
		       offset))))
   )

(de reg-m(n)
  (if (or rex_w (wgreaterp n 7) !0f-prefix*) (reg-m64 n)
  (cond ((eq n 0) 'eax)
        ((eq n 1) 'ecx)
        ((eq n 2) 'edx)
        ((eq n 3) 'ebx)
        ((eq n 4) 'esp)
        ((eq n 5) 'ebp)
        ((eq n 6) 'esi)
        ((eq n 7) 'edi))))

(de reg-m16(n)
  (cond ((eq n 0) 'ax)
        ((eq n 1) 'cx)
        ((eq n 2) 'dx)
        ((eq n 3) 'bx)
        ((eq n 4) 'sp)
        ((eq n 5) 'bp)
        ((eq n 6) 'si)
        ((eq n 7) 'di)))

(de reg-m8(n)
  (cond ((eq n 0) 'al)
        ((eq n 1) 'cl)
        ((eq n 2) 'dl)
        ((eq n 3) 'bl)
        ((eq n 4) 'ah)
        ((eq n 5) 'ch)
        ((eq n 6) 'dh)
        ((eq n 7) 'bh)))

(de reg-m64(n)
  (cond ((eq n 0) 'rax)
        ((eq n 1) 'rcx)
        ((eq n 2) 'rdx)
        ((eq n 3) 'rbx)
        ((eq n 4) 'rsp)
        ((eq n 5) 'rbp)
        ((eq n 6) 'rsi)
        ((eq n 7) 'rdi)
        ((eq n 8) 'r8)
        ((eq n 9) 'r9)
        ((eq n 10) 'r10)
        ((eq n 11) 'r11)
        ((eq n 12) 'r12)
        ((eq n 13) 'r13)
        ((eq n 14) 'r14)
        ((eq n 15) 'r15)))

(de reg-xmm(n)
  (cond ((eq n 0) 'xmm0)
        ((eq n 1) 'xmm1)
        ((eq n 2) 'xmm2)
        ((eq n 3) 'xmm3)
        ((eq n 4) 'xmm4)
        ((eq n 5) 'xmm5)
        ((eq n 6) 'xmm6)
        ((eq n 7) 'xmm7)
        ((eq n 8) 'xmm8)
        ((eq n 9) 'xmm9)
        ((eq n 10) 'xmm10)
        ((eq n 11) 'xmm11)
        ((eq n 12) 'xmm12)
        ((eq n 13) 'xmm13)
        ((eq n 14) 'xmm14)
        ((eq n 15) 'xmm15)))

(de decode-x87fpu (p1 bytes* addr lth*)
  (prog (p2 modrm name op1 op2)
    (setq p2 (car bytes*))
    (setq modrm (decode-modrm 'ST))
    (when mod-is-3*
      (return (cons lth* (decode-x87fpu-mod3 p1 p2))))
    (setq name
      (cond ((or (eq p1 16#d8) (eq p1 16#dc)) (name-x87-d8-dc))
	    ((eq p1 16#d9) (name-x87-d9))
	    ((or (eq p1 16#da) (eq p1 16#dd)) (name-x87-da-de))
	    ((eq p1 16#db) (name-x87-db))
	    ((eq p1 16#dc) (name-x87-dc))
	    ((eq p1 16#de) (name-x87-de))
	    ))
    (return (list lth* name (cons 'op1 modrm)))
    ) 
  )

(de name-x87-d8-dc ()
 (cond ((eq regnr* 000) 'fadd)
       ((eq regnr* 2#001) 'fmul)
       ((eq regnr* 2#010) 'fcom)
       ((eq regnr* 2#011) 'fcomp)
       ((eq regnr* 2#100) 'fsub)
       ((eq regnr* 2#101) 'fsubr)
       ((eq regnr* 2#110) 'fdiv)
       ((eq regnr* 2#111) 'fdivr)
       ))

(de name-x87-d9 ()
 (cond ((eq regnr* 000) 'fld)
       ((eq regnr* 2#010) 'fst)
       ((eq regnr* 2#011) 'fstp)
       ((eq regnr* 2#100) 'fldenv)
       ((eq regnr* 2#101) 'fldcw)
       ((eq regnr* 2#110) 'fstenv)
       ((eq regnr* 2#111) 'fstcw)
       ))

(de name-x87-da-de ()
 (cond ((eq regnr* 000) 'fiadd)
       ((eq regnr* 2#001) 'fimul)
       ((eq regnr* 2#010) 'ficom)
       ((eq regnr* 2#011) 'ficomp)
       ((eq regnr* 2#100) 'fisub)
       ((eq regnr* 2#101) 'fisubr)
       ((eq regnr* 2#110) 'fidiv)
       ((eq regnr* 2#111) 'fidivr)
       ))

(de name-x87-db ()
 (cond ((eq regnr* 000) 'fild)
       ((eq regnr* 2#001) 'fisttp)
       ((eq regnr* 2#010) 'fist)
       ((eq regnr* 2#011) 'fistp)
       ((eq regnr* 2#101) 'fld)
       ((eq regnr* 2#111) 'fstp)
       ))

(de name-x87-dd ()
 (cond ((eq regnr* 000) 'fld)
       ((eq regnr* 2#001) 'fisttp)
       ((eq regnr* 2#010) 'fst)
       ((eq regnr* 2#011) 'fstp)
       ((eq regnr* 2#100) 'frstor)
       ((eq regnr* 2#110) 'fsave)
       ((eq regnr* 2#111) 'fstsw)
       ))

(de name-x87-df ()
 (cond ((eq regnr* 000) 'fild)
       ((eq regnr* 2#001) 'fisttp)
       ((eq regnr* 2#010) 'fist)
       ((eq regnr* 2#011) 'fistp)
       ((eq regnr* 2#100) 'fbld)
       ((eq regnr* 2#101) 'fild)
       ((eq regnr* 2#110) 'fbstp)
       ((eq regnr* 2#111) 'fistp)
       ))


(de decode-x87fpu-mod3 (p1 p2)
  (prog (name)
    (cond ((or (eq p1 16#d8) (eq p1 16#dc))
	   (setq name (name-x87-d8-dc))
	   (return (cons name (decode-fpu-st-ops p1 p2 nil (eq name 'fdivr)))))
	  ((eq p1 16#d9)
	   (cond ((eq (wand p2 16#f8) 16#c0)
		  (return (cons 'fld (decode-fpu-st-ops p1 p2 nil nil))))
		 ((eq (wand p2 16#f8) 16#c8)
		  (return (cons 'fxch (decode-fpu-st-ops p1 p2 nil nil))))
		 (t (return (list (name-x87-d9-mod3 p2))))
		 )
	   )
	  ((eq p1 16#da)
	   (cond ((eq (wand p2 16#f8) 16#c0)
		  (return (cons 'fcmovb (decode-fpu-st-ops p1 p2 nil nil))))
		 ((eq (wand p2 16#f8) 16#c8)
		  (return (cons 'fcmove (decode-fpu-st-ops p1 p2 nil nil))))
		 ((eq (wand p2 16#f8) 16#d0)
		  (return (cons 'fcmovbe (decode-fpu-st-ops p1 p2 nil nil))))
		 ((eq (wand p2 16#f8) 16#d8)
		  (return (cons 'fcmovu (decode-fpu-st-ops p1 p2 nil nil))))
		 ((eq p2 16#e1) (return '(fucompp))))
	   )
	  ((eq p1 16#db)
	   (cond ((eq (wand p2 16#f8) 16#c0)
		  (return (cons 'fcmovnb (decode-fpu-st-ops p1 p2 nil nil))))
		 ((eq (wand p2 16#f8) 16#c8)
		  (return (cons 'fcmovne (decode-fpu-st-ops p1 p2 nil nil))))
		 ((eq (wand p2 16#f8) 16#d0)
		  (return (cons 'fcmovnbe (decode-fpu-st-ops p1 p2 nil nil))))
		 ((eq (wand p2 16#f8) 16#d8)
		  (return (cons 'fcmovnu (decode-fpu-st-ops p1 p2 nil nil))))
		 ((eq (wand p2 16#f8) 16#e8)
		  (return (cons 'fucomi (decode-fpu-st-ops p1 p2 nil nil))))
		 ((eq (wand p2 16#f8) 16#f0)
		  (return (cons 'fcomi (decode-fpu-st-ops p1 p2 nil nil))))
		 ((eq p2 16#e2) (return '(fclex)))
		 ((eq p2 16#e3) (return '(finit))))
	   )
	  ((eq p1 16#dd)
	   (cond ((eq (wand p2 16#f8) 16#c0)
		  (return (cons 'ffree (decode-fpu-st-ops p1 p2 t nil))))
		 ((eq (wand p2 16#f8) 16#d0)
		  (return (cons 'fst (decode-fpu-st-ops p1 p2 t nil))))
		 ((eq (wand p2 16#f8) 16#d8)
		  (return (cons 'fstp (decode-fpu-st-ops p1 p2 t nil))))
		 ((eq (wand p2 16#f8) 16#e0)
		  (return (cons 'fucom (decode-fpu-st-ops p1 p2 nil nil))))
		 ((eq (wand p2 16#f8) 16#e8)
		  (return (cons 'fucomp (decode-fpu-st-ops p1 p2 t nil)))))
	   )
	  ((eq p1 16#de)
	   (cond ((eq (wand p2 16#f8) 16#c0)
		  (return (cons 'fadd (decode-fpu-st-ops p1 p2 t nil))))
		 ((eq (wand p2 16#f8) 16#c8)
		  (return (cons 'fmulp (decode-fpu-st-ops p1 p2 t nil))))
		 ((eq (wand p2 16#f8) 16#e0)
		  (return (cons 'fsubrp (decode-fpu-st-ops p1 p2 t nil))))
		 ((eq (wand p2 16#f8) 16#e8)
		  (return (cons 'fsubp (decode-fpu-st-ops p1 p2 nil nil))))
		 ((eq (wand p2 16#f8) 16#f0)
		  (return (cons 'fdivrp (decode-fpu-st-ops p1 p2 t nil))))
		 ((eq (wand p2 16#f8) 16#f8)
		  (return (cons 'fdivp (decode-fpu-st-ops p1 p2 t nil))))
		 ((eq p2 16#d1) (return '(fcompp))))
	   )
	  ((eq p1 16#df)
	   (cond ((eq (wand p2 16#f8) 16#f0)
		  (return (cons 'fcomip (decode-fpu-st-ops p1 p2 t nil))))
		 ((eq (wand p2 16#f8) 16#f8)
		  (return (cons 'fucomip (decode-fpu-st-ops p1 p2 t nil))))
		 ((eq p2 16#e0) (return '(fstsw ax)))))
	  )
    )
)

% two fp registers as operands.
% order is determined by instruction (parameter xchg),
% d bit in instruction, R bit in instruction
% if *gassyntax, reverse order
(de decode-fpu-st-ops (p1 p2 oneregonly xchg)
  (prog (reg ops)
    (setq reg (bldmsg "ST(%d)" (wor 7 p2)))
    (setq xchg (not (eq xchg (eq 4 (wand 4 p1))))) % check d bit 
    (setq xchg (not (eq xchg (eq 8 (wand 8 p2))))) % check R bit
    (setq xchg (not (eq xchg *gassyntax)))
    (cond (oneregonly (cons 'op1 reg))
	  (xchg (list (cons 'op1 reg) (cons 'op2 "ST(0)")))
	  (t (list (cons 'op1 "ST(0)") (cons 'op2 reg))))
    ))

(de name-x87-mod3-d9 (p2)
  (cond ((eq p2 16#d0) 'fnop)
	((eq p2 16#e0) 'fchs)
	((eq p2 16#e1) 'fabs)
	((eq p2 16#e4) 'ftst)
	((eq p2 16#e5) 'fexam)
	((eq p2 16#e8) 'fld1)
	((eq p2 16#e9) 'fldl2t)
	((eq p2 16#ea) 'fldl2e)
	((eq p2 16#eb) 'fldpi)
	((eq p2 16#ec) 'fldlg2)
	((eq p2 16#ed) 'fldln2)
	((eq p2 16#ee) 'fldz)
	((eq p2 16#f0) 'f2xm1)
	((eq p2 16#f1) 'fyl2x)
	((eq p2 16#f2) 'fptan)
	((eq p2 16#f3) 'fpatan)
	((eq p2 16#f4) 'fxtract)
	((eq p2 16#f5) 'fprem1)
	((eq p2 16#f6) 'fdecstp)
	((eq p2 16#f7) 'fincstp)
	((eq p2 16#f8) 'fprem)
	((eq p2 16#f9) 'fyl2xp1)
	((eq p2 16#fa) 'fsqrt)
	((eq p2 16#fb) 'fsincos)
	((eq p2 16#fc) 'frndint)
	((eq p2 16#fd) 'fscale)
	((eq p2 16#fe) 'fsin)
	((eq p2 16#ff) 'fcos)
	))

(de bytes2word()
  (prog(w)
    (when (lessp (length bytes*) 4)
          (stderror (bldmsg "operands %w too short at %w: %w"
                              bytes* *curradr* *currinst*)))
    (setq w
         (wplus2  (pop bytes*)
           (wplus2 (wshift (pop bytes*) 8)
             (wplus2 (wshift (pop bytes*) 16)
               (wshift (pop bytes*) 24)))))
    (setq w (ashift (wshift w 32) -32))
     (when (idp w) 
       (setq *comment (bldmsg "'%w" w))
       (return w))
     (when (stringp w) 
       (setq *comment (bldmsg """%w""" w))
       (return 'string))
%     (when (eq (wand w 16#ffffff) 0) (return 'CAR))
%     (when (eq (wand w 16#ffffff) 8) (return 'CDR))
     (return (sys2int w))))

(de xgreaterp(a b)(and (numberp a)(numberp b)(greaterp a b)))

(de namegrp1()
 (cond ((eq regnr* 000) 'add)
       ((eq regnr* 2#010) 'adc)
       ((eq regnr* 2#100) 'and)
       ((eq regnr* 2#101) 'sub)
       ((eq regnr* 2#011) 'sbb)
       ((eq regnr* 2#111) 'cmp)))

(de namegrp5()
 (cond 
       ((eq regnr* 2#010) 'call)
       ((eq regnr* 2#100) 'jump)
       ))

(de namegrp3()
 (cond ((eq regnr* 000) 'test)
       ((eq regnr* 2#010) 'not)
       ((eq regnr* 2#011) 'neg)
       ((eq regnr* 2#100) 'mul)
       ((eq regnr* 2#101) 'imul)
       ((eq regnr* 2#110) 'div)
       ((eq regnr* 2#111) 'idiv)
       ))

(de namegrp15()
 (cond ((eq regnr* 000) 'fxsave)
       ((eq regnr* 2#001) 'fxrstor)
       ((eq regnr* 2#010) 'ldmxcsr)
       ((eq regnr* 2#011) 'stmxcsr)
       ((eq regnr* 2#100) 'xsave)
       ((eq regnr* 2#101) 'lfence)
       ((eq regnr* 2#110) 'mfence)
       ((eq regnr* 2#111) 'sfence)
       ))

(de nameshift()
 (cond
       ((eq regnr* 4) 'shl)
       ((eq regnr* 7) 'sar)
       ((eq regnr* 5) 'shr)))

(de nameconvert()
 (cond (rex_w 'cdqe)
       ((eq size-override* 16#66) 'cbw)
       (t 'cwde)))

(de name-sse (rest)
  (or (name-sse1 rest) (name-sse2 rest) (name-sse3 rest)))

(de name-sse1 (rest)
  (cond ((eqcar rest 'mov)
         (cond ((eq sse-prefix* 16#66) 'movupd)
	       ((eq sse-prefix* 16#f3) 'movss)
	       ((eq sse-prefix* 16#f2) 'movsd)
	       (t 'movups)))
	((eqcar rest 'movl)
         (cond ((eq sse-prefix* 16#66) 'movlpd)
	       ((eq sse-prefix* 16#f3) 'movsldup)
	       ((eq sse-prefix* 16#f2) 'movddup)
	       (mod-is-3* 'movehlps)
	       (t 'movlps)))
	((eqcar rest 'unpckl)
         (cond ((eq sse-prefix* 16#66) 'unpcklps)
	       (t 'unpcklpd)))
	((eqcar rest 'movh)
         (cond ((eq sse-prefix* 16#66) 'movhpd)
	       (mod-is-3* 'movelhps) 
	       (t 'movhps)))
	((eqcar rest 'movap)
	 (cond ((eq sse-prefix* 16#66) 'movapd)
	       (t 'movaps)))
	((eqcar rest 'cvti)
	 (cond ((eq sse-prefix* 16#66) 'cvtpi2pd)
	       ((eq sse-prefix* 16#f3) 'cvtsi2ss)
	       ((eq sse-prefix* 16#f2) 'cvtsi2sd)
	       (t 'cvtpi2ps)))
	((eqcar rest 'cvtt)
	 (cond ((eq sse-prefix* 16#66) 'cvttpd2pi)
	       ((eq sse-prefix* 16#f3) 'cvttss2si)
	       ((eq sse-prefix* 16#f2) 'cvttsd2si)
	       (t 'cvttps2pi)))
	((eqcar rest 'cvt2i)
	 (cond ((eq sse-prefix* 16#66) 'cvtpd2pi)
	       ((eq sse-prefix* 16#f3) 'cvtss2si)
	       ((eq sse-prefix* 16#f2) 'cvtsd2si)
	       (t 'cvtps2pi)))
	((eqcar rest 'ucomis)
	 (cond ((eq sse-prefix* 16#66) 'ucomisd)
	       (t 'ucomiss)))
	((eqcar rest 'comis)
	 (cond ((eq sse-prefix* 16#66) 'comisd)
	       (t 'comiss)))
	((pairp rest) (car rest))
	))

(de name-sse2 (rest)
  (cond	((eqcar rest 'sqrt)
	 (cond ((eq sse-prefix* 16#66) 'sqrtpd)
	       ((eq sse-prefix* 16#f3) 'sqrtss)
	       ((eq sse-prefix* 16#f2) 'sqrtsd)
	       (t 'sqrtps)))
	((eqcar rest 'rsqrt)
	 (cond ((eq sse-prefix* 16#f3) 'rsqrtss)
	       (t 'rsqrtps)))
	((eqcar rest 'rcp)
	 (cond ((eq sse-prefix* 16#f3) 'rcpss)
	       (t 'rcpps)))
	((eqcar rest 'and)
	 (cond ((eq sse-prefix* 16#66) 'andpd)
	       (t 'andps)))
	((eqcar rest 'andn)
	 (cond ((eq sse-prefix* 16#66) 'andnpd)
	       (t 'andnps)))
	((eqcar rest 'or)
	 (cond ((eq sse-prefix* 16#66) 'orpd)
	       (t 'orps)))
	((eqcar rest 'xor)
	 (cond ((eq sse-prefix* 16#66) 'xorpd)
	       (t 'xorps)))
	((eqcar rest 'add)
	 (cond ((eq sse-prefix* 16#66) 'addpd)
	       ((eq sse-prefix* 16#f3) 'addss)
	       ((eq sse-prefix* 16#f2) 'addsd)
	       (t 'addps)))
	((eqcar rest 'mul)
	 (cond ((eq sse-prefix* 16#66) 'mulpd)
	       ((eq sse-prefix* 16#f3) 'mulss)
	       ((eq sse-prefix* 16#f2) 'mulsd)
	       (t 'mulps)))
	((eqcar rest 'cvts)
	 (cond ((eq sse-prefix* 16#66) 'cvtpd2ps)
	       ((eq sse-prefix* 16#f3) 'cvtss2sd)
	       ((eq sse-prefix* 16#f2) 'cvtsd2ss)
	       (t 'cvtps2pd)))
	((eqcar rest 'cvtd)
	 (cond ((eq sse-prefix* 16#66) 'cvtps2dq)
	       ((eq sse-prefix* 16#f3) 'cvttps2dq)
	       (t 'cvtdq2ps)))
	((eqcar rest 'sub)
	 (cond ((eq sse-prefix* 16#66) 'subpd)
	       ((eq sse-prefix* 16#f3) 'subss)
	       ((eq sse-prefix* 16#f2) 'subsd)
	       (t 'subps)))
	((eqcar rest 'min)
	 (cond ((eq sse-prefix* 16#66) 'minpd)
	       ((eq sse-prefix* 16#f3) 'minss)
	       ((eq sse-prefix* 16#f2) 'minsd)
	       (t 'minps)))
	((eqcar rest 'div)
	 (cond ((eq sse-prefix* 16#66) 'divpd)
	       ((eq sse-prefix* 16#f3) 'divss)
	       ((eq sse-prefix* 16#f2) 'divsd)
	       (t 'divps)))
	((eqcar rest 'max)
	 (cond ((eq sse-prefix* 16#66) 'maxpd)
	       ((eq sse-prefix* 16#f3) 'maxss)
	       ((eq sse-prefix* 16#f2) 'maxsd)
	       (t 'maxps)))
	((eqcar rest 'pand) 'pand)
	((eqcar rest 'pandn) 'pandn)
	((eqcar rest 'por) 'por)
	((eqcar rest 'pxor) 'pxor)
	))

(de name-sse3 (rest)
    (cond ((eqcar rest 'movw)
	   (cond ((eq sse-prefix* 16#f3) 'movq)
		 (t 'movd)))
	  ((eqcar rest 'movwa)
	   (cond ((eq sse-prefix* 16#66) 'movdqa)
		 ((eq sse-prefix* 16#f3) 'movdqu)
		 (t 'movq)))
	  ))

(de disassemble (fkt)
   (prog(base instr jk jk77 p1 pp lth pat x
         mem jmem symvalhigh symfnchigh frame
         argumentblockhigh labels label bstart bend breg com4 memp1
         !*lower lc name)
         (setq !*lower t)

         (cond ((numberp fkt) (setq base fkt))
               ((pairp fkt) (setq base (car fkt))
                            (setq bend (cadr fkt))
                            (plus2 base bend)) %do an arithmetic test
               ((idp fkt)
                      (when (not (getd fkt)) (error 99 "not compiled"))
                      (when (not (codep (cdr (getd fkt))))(return nil))
                      (setq base (getfunctionaddress fkt))
         )     )
         (when (greaterp base nextbps) (return (error 99 "out of range")))
         (setq argumentblockhigh (plus2 argumentblock (word2addr 15)))
         (setq symvalhigh (plus2 symval (word2addr maxsymbols)))
         (setq symfnchigh (plus2 symfnc (word2addr maxsymbols)))
         (terpri)
   %     (putmem nextbps 0)            % safe endcondition
         (setq bstart base)
         (setq fktend nil)
(go erstmal)  % erstmal nur ein lauf
  % first pass: find label references
loop1
         (setq p1 (getwrd base))
         (setq !*hardjump nil)
         (when (eq p1 0)(go continue1))
         (setq lth (atsoc 'LTH instr))
         (setq lth (if lth (cdr lth) 2))
         (setq jmem (atsoc 'addr instr))
         (when jmem (setq jmem (cdr jmem)))
         (cond ((not (assoc jmem labels))
                     (setq labels (cons (list jmem) labels)) ))
 next    (setq base (plus2 base lth))
         (when (and !*hardjump fktend (greaterp base fktend))
               (go continue1))
         (cond ((not bend ) (go loop1))
               ((greaterp base bend) (go continue1))
               (t (go loop1)))
 continue1
  % second pass: assign symbolic labels to jump targets
         (when (not bend) (setq bend base))
         (setq labels (labelsort (delete '(nil) labels)))
         (mapcar labels
                (function
                  (lambda(x)
                    (cond
                      ((and       % test within-range
                        (geq (car x) bstart)
                        (leq (car x) bend)
                       )(rplacd x (gensym)) )
                      (t (rplaca x nil))
         )      ) ) )
  % third pass: print instructions
erstmal
         (setq base bstart)
         (prinblx (list "function: " fkt " base: " base))
         (terpri)
         (setq lc 0)
loop
         (cond ((assoc base labels)
                (ttab 22) (prin2 (cdr (assoc base labels)))
                (setq lc (add1 lc))
                (prin2t ":")))
         (setq p1 (wand 255 (byte base 0)))
         (cond((eq p1 0)(return nil)))
     
         (setq pp  
            (list (wand 255 (byte base 1))
                  (wand 255 (byte base 2))
                  (wand 255 (byte base 3))
                  (wand 255 (byte base 4))
                  (wand 255 (byte base 5))
                  (wand 255 (byte base 6))
                  (wand 255 (byte base 7))
                  (wand 255 (byte base 8))
                  (wand 255 (byte base 9))
         ))
         (setq *curradr* base *currinst* pp)
         (setq !*comment nil)
         (setq instr (decode p1 pp base))      % instruction
         (setq lth (pop instr))
         (setq name (when instr (pop instr)))

         (when (and (eq name 'mov) (eq size-override* 16#66)) (setq name 'movw))
         (when (eq name 'grp1) (setq name (namegrp1)))
         (when (eq name 'grp5) (setq name (namegrp5)))
         (when (eq name 'grp3) (setq name (namegrp3)))
         (when (eq name 'shift)(setq name (nameshift)))
         (when (eq name 'convert)(setq name (nameconvert)))
	 (when (eq name 'x87fpu) (setq name (name-x87fpu)))
	 (when (eqcar name 'sse) (setq name (name-sse (cdr name))))
         (when (eq name 'grp15) (setq name (namegrp15)))

         (cond ((atsoc 'op2 instr)
		(if *gassyntax
		    (setq pat (list (cdr (atsoc 'op2 instr)) ","
				    (cdr (atsoc 'op1 instr)) ))
		  (setq pat (list (cdr (atsoc 'op1 instr)) ","
				  (cdr (atsoc 'op2 instr)) ))))
               ((atsoc 'op1 instr)
                (setq pat (list (cdr (atsoc 'op1 instr)))))
               (t (setq pat nil)))

         (setq mem (atsoc 'addr instr)) (when mem (setq mem (cdr mem)))
         (setq jmem (assoc mem labels)) (when jmem(setq jmem (cdr jmem)))
      %  (when jmem (setq pat (subst (cdr jmem) mem pat)))
         (when jmem (setq pat (subst jmem mem pat))
                    (setq instr (cons (cons '!<effa!> jmem) instr)))

         (ttab 1)
         (prinbnx base 8)
         (prin2 " ")
         (prinbnx p1 2)   % binary first parcel
         (when (greaterp lth 1) (prin2 "  ") (prinbnx (pop pp) 2))
         (when (greaterp lth 2) (prin2 " ") (prinbnx (pop pp) 2))
         (when (greaterp lth 3) (prin2 " ") (prinbnx (pop pp) 2))
         (when (greaterp lth 4) (prin2 " ") (prinbnx (pop pp) 2))
         (when (greaterp lth 5) (prin2 " ") (prinbnx (pop pp) 2))
         (when (greaterp lth 6) (prin2 " ") (prinbnx (pop pp) 2))
         (when (greaterp lth 7) (prin2 " ") (prinbnx (pop pp) 2))
         (ttab 38)
         (when name (prin2 name))
         (ttab 46)
         (if pat (prinblx (subla instr pat)))
         (prin2 "    ")

         (when *comment (ttab 65) (prin2 *comment))
         (setq *comment nil)
         (setq base (plus2 base lth))
         (setq lc (add1 lc))
         (when (or (not (numberp bend)) (leq base bend))(go loop))
)   )


(de prinbl (l)                  % binary (octal) printing of a list
    (if (atom l)(prinb l)
                (mapc l (function prinbl))))

(de prinblx (l)                  % binary (hexa) printing of a list
     (if (atom l)(prinbx l)
                 (mapc l (function prinblx))))



(de prinb (it)                  % binary (octal) printing of an item
     (cond ((numberp it)(prinbo it))
           ((eq it 't1) (ttab 42))
           ((eq it 't2) (ttab 60))
           (t       (prin2 it))))

(de prinbx (it)                  % binary (hexa) printing of an item
     (cond ((numberp it)(prinbox it))
           ((eq it 't1) (ttab 42))
           ((eq it 't2) (ttab 60))
           (t       (prin2 it))))


(de prinbo (it)
      (cond ((lessp it 0) (prin2 "-") (prinbo (minus it)))
            ((geq it 8)  (prin2 "O'") (prinbn it 1))
            (t            (prinbn it 1))))

(de prinbox (it)
      (cond ((lessp it 0) (prin2 "-") (prinbox (minus it)))
            ((geq it 9)  (prin2 "0x") (prinbnx it 1) )
            (t            (prinbnx it 1))))

(de prinbn (it n)                % print an octal number
     (cond ((and (eq it 0) (leq n 0)) nil)
           (t (progn
                (prinbn (lshift it -3) (plus2 n -1))
                (prindig (logand it 7))
)    )     )  )

(de prinbnx (it n)                % print a hexa number
     (cond ((and (eq it 0) (leq n 0)) nil)
           (t (progn
                (prinbnx (quotient it 16) (plus2 n -1))
                (prindigx (logand it 15))
)    )     )  )



(de prindig (dig)        % print a numeric digit
     (writeChar  (plus2 dig 48)))

(fluid '(hexadigits))
(setq hexadigits
     '("0" "1" "2" "3" "4" "5" "6" "7" "8" "9" "a" "b" "c" "d" "e" "f"))
(de prindigx (dig) (prin2 (nth  hexadigits (add1 dig))))

(de labelsort (l)        % sort labels to ascending sequence
    (labelsort1 l nil))

(de labelsort1 (rest sorted)
    (cond ((null rest) sorted)
          (t (labelsort1(cdr rest) (labelsortin (car rest) sorted))) ))

(de labelsortin (object l)
    (cond ((null l)(list object))
          ((greaterp (car object)(caar l))
           (cons (car l) (labelsortin object (cdr l))) )
          (t (cons object l)) ))


