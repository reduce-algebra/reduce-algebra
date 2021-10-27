%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:  pxu/disassemble.sl -  disassembler for i486 
%
% Author: H. Melenk , ZIB Berlin
%
% Date :  4-May-1994
% Status: Open Source: BSD License
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%

(fluid '(bytes* lth* reg* regnr* segment*  symvalhigh symfnchigh *curradr* *currinst*))

          (de getwrd(a)(getmem a))

          (de getfunctionaddress(fkt) 
             (wshift(wshift (cdr (getd fkt)) 5) -5))

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


(fluid '(eregs !*comment fktend !*hardjump instrs1 instrs2 instrs3 instrs*))

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


(fi 16#40 inc (eax) (ecx) (edx) (ebx) (esp) (ebp) (esi) (edi))

(fi 16#48 dec (eax) (ecx) (edx) (ebx) (esp) (ebp) (esi) (edi))

(fi 16#50 push (eax) (ecx) (edx) (ebx) (esp) (ebp) (esi) (edi))

(fi 16#58 pop  (eax) (ecx) (edx) (ebx) (esp) (ebp) (esi) (edi))

(fi 16#60 pusha nil)

(fi 16#61 popa  nil)

(fi 16#68 push ((I v)))

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

(fi 16#86 xchg ((E b) (G b)) ((E v) (G v)))

(fi 16#88 mov  ((E b)(G b)) ((E v) (G v))  ((G b)(E b)) ((G v) (E v)))

(fi 16#8d lea  ((G v) (M)))

(fi 16#90 nop (nil))

(fi 16#91 xchg (ecx eax)(edx eax)(ebx eax)(esp eax)(ebp eax)(esi eax)(edi eax))

(fi 16#98 convert (nil))

(fi 16#9a call (A p))

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

(fi 16#9b fwait (nil))

(fi 16#e9 jmp ((J v)) ((A p)) ((J b)))

(fi 16#f6  Grp3 ((E b)) ((E v)))

(fi 16#ff  Grp5 ((E v)))   % grp5

% second group

(setq instrs* 'instrs2)

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

(fi 16#af imul ((G v)(E v)))

(fi 16#a3 bt   ((E v)(G v)))
(fi 16#ba bt   ((E v)(I b)))
(fi 16#bc bsf  ((G v)(E v)))
(fi 16#bd bsr  ((G v)(E v)))


(dm make-the-instructions(u)
  `(progn
     (setq instrs1 ',instrs1)
     (setq instrs2 ',instrs2)
     (setq instrs3 ',instrs3)
     ))

))

(make-the-instructions)



(setq eregs  '("eax" "ecx" "edx" "ebx" "esp" "ebp" "esi" "edi"))

(fluid '(the-instruction* addr* size-override* sse-prefix* mod-is-3*))

(de decode(p1 pl addr*)
  (prog(i lth name)
      (setq size-override* nil mod-is-3* nil)
      (setq lth 1)
      (when (or (weq p1 16#66) (weq p1 16#67))
	 (when (weq p1 16#66) (setq sse-prefix* p1))
         (setq size-override* p1)
	 (setq p1 (pop pl))
         (setq lth 2))
      (setq i (assoc p1 instrs1))
      (when (eq p1 16#0f)
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

(de decode-operands(bytes* lth* pat)
  (prog (r reg*)
    (when (or (null pat) (eqcar pat nil)) (go done))
    (push (cons 'op1 (decode-operand1 (pop pat))) r)
    (when pat
        (push (cons 'op2 (decode-operand1 (pop pat))) r))
 done
    (setq r (subst reg* 'reg r))
    (return (cons lth* r))))

(de decode-operand1(p)
 (let(w)
  (cond ((atom p) p)
        ((eq (car p) 'G) 'reg)
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
         (plus addr* (bytes2word) 5))
           % mod R/M
        ((eqcar p 'E) (decode-modrm p))
        ((eqcar p 'R) (decode-modrm p))
        ((eqcar p 'M) (decode-modrm p))
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
   (prog(mod rm b w)
     (setq b (pop bytes*)) (setq  lth* (add1 lth*))
     (setq mod (wshift b -6))
     (setq regnr* (wand 7 (wshift b -3))) (setq reg* (reg-m regnr*))
     (setq rm (wand 7 b))
       %(terpri)(prin2t(list "modrm" b mod regnr* rm)) (print bytes*)
     (return
  (cond ((and (lessp mod 3)(eq rm 2#100))
         (decode-sib p mod))
        ((and (eq mod 0)(eq rm 5))
                  % probably a sym*** reference
              (setq  lth* (plus 4 lth*))
              (setq w (bytes2word))
              (cond ((and (xgreaterp w symfnc)
                          (xgreaterp symfnchigh w))
                     (setq *comment
                      (bldmsg " -> %w" 
                       (safe-int2id (wshift (wdifference (int2sys w) symfnc) -2)))))
                    ((and (xgreaterp w symval)
                          (xgreaterp symvalhigh w))
                     (setq *comment
                      (bldmsg " -> %w" 
                       (safe-int2id (wshift (wdifference (int2sys w) symval) -2))))))
              (bldmsg "*%w" w))
        ((eq mod 0) (bldmsg "[%w]" (reg-m rm)))
        ((eq mod 1) 
              (setq  lth* (add1 lth*))
	      (let ((b (pop bytes*)))
		% b is unsigned, convert to signed byte
		(if (greaterp b 127)
		    (setq b (wdifference b 256)))
		(bldmsg "[%w%w%w]" (reg-m rm) (if (wlessp b 0) "" "+") b)))
        ((eq mod 2) 
              (setq  lth* (plus 4 lth*))
	      (setq w (bytes2word))
	      (cond ((equal w 16#B8000000) (setq *comment " -> car"))
		    ((equal w 16#B8000004) (setq *comment " -> cdr")))	      
              (bldmsg "[%w+%x]" (reg-m rm) (int2sys w)))
        ((eq mod 3)
         (setq mod-is-3* t)
         (bldmsg "%w" (reg-m rm)))) )))
              
(de decode-sib(p mod)
   (prog(scale index base offset seg b w)
     (setq b (pop bytes*))
     (setq  lth* (add1 lth*))
     (setq scale (lsh 1 (wshift b -6)))
     (setq index (wand 7 (wshift b -3)))
     (when (eq index 4) (setq index ""))  % erstmal
     (setq base (wand 7 b))
     (setq offset "")
     (when (eq mod 1)
           (setq offset (bldmsg "+%w" (pop bytes*)))
            (setq  lth* (add1 lth*)))
     (when (eq mod 2)
           (setq w (bytes2word))
           (setq offset (bldmsg "+%w" w))
            (setq  lth* (plus lth* 4)))
     (when (and (eq mod 0)(eq base 2#101))
           (setq  lth* (plus lth* 4))
           (return (bldmsg "[%w%w]" (bytes2word) index)))
     (setq seg
       (cond (segment* segment*)
             (t "")))
     (setq segment* nil)
     (return (bldmsg "[%w%w%w]" (reg-m base)
		     (if (equal index "") ""
		       (bldmsg "+%w*%w" (reg-m index) scale))
		     offset))))


(de reg-m(n)
  (cond ((eq n 0) 'eax)
        ((eq n 1) 'ecx)
        ((eq n 2) 'edx)
        ((eq n 3) 'ebx)
        ((eq n 4) 'esp)
        ((eq n 5) 'ebp)
        ((eq n 6) 'esi)
        ((eq n 7) 'edi)))

(de decode-x87fpu (p1 bytes* addr lth*)
  (prog (p2 modrm name op1 op2)
    (setq p2 (car bytes*))
    (setq modrm (decode-modrm 'ST))
    (when mod-is-3*
      (return (cons lth* (decode-x87fpu-mod3 p1 p2))))
    (setq name
      (cond ((or (eq p1 16#d8) (eq p1 16#dc)) (name-x87-d8-dc))
	    ((eq p1 16#d9) (name-x87-d9))
	    ((or (eq p1 16#da) (eq p1 16#de)) (name-x87-da-de))
	    ((eq p1 16#db) (name-x87-db))
	    ((eq p1 16#dc) (name-x87-dc))
	    ((eq p1 16#dd) (name-x87-dd))
	    ))
    (return (list lth* name (cons 'op1 modrm)))
    ) 
  )

(de name-x87fpu (p1)
    (cond ((or (eq p1 16#d8) (eq p1 16#dc)) (name-x87-d8-dc))
          ((eq p1 16#d9) (name-x87-d9))
          ((or (eq p1 16#da) (eq p1 16#de)) (name-x87-da-de))
          ((eq p1 16#db) (name-x87-db))
          ((eq p1 16#dc) (name-x87-dc))
          ((eq p1 16#dd) (name-x87-dd))
    ))

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
%    (setq xchg (not (eq xchg *gassyntax)))
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
     (when (idp w) 
       (setq *comment (bldmsg "'%w" w))
       (return (sys2int w)))
     (when (stringp w) 
       (setq *comment (bldmsg """%w""" w))
       (return 'string))
%     (when (eq (wand w 16#ffffff) 0) (return 'CAR))
%     (when (eq (wand w 16#ffffff) 4) (return 'CDR))
     (return (sys2int w))))

(de xgreaterp(a b)(and (numberp a)(numberp b)(greaterp a b)))

(de namegrp1()
 (cond ((eq regnr* 000) 'add)
       ((eq regnr* 2#001) 'or)
       ((eq regnr* 2#010) 'adc)
       ((eq regnr* 2#011) 'sbb)
       ((eq regnr* 2#100) 'and)
       ((eq regnr* 2#101) 'sub)
       ((eq regnr* 2#110) 'xor)
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

(de nameshift()
 (cond
       ((eq regnr* 4) 'shl)
       ((eq regnr* 7) 'sar)
       ((eq regnr* 5) 'shr)))

(de nameconvert()
 (cond ((eq size-override* 16#66) 'cbw)
       (t 'cwde)))


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
                      (setq base (sys2int (getfunctionaddress fkt)))
         )     )
         (when (greaterp base (sys2int nextbps)) (return (error 99 "out of range")))
         (setq argumentblockhigh (plus2 argumentblock (word2addr 15)))
         (setq symvalhigh (plus2 (sys2int symval) (word2addr maxsymbols)))
         (setq symfnchigh (plus2 (sys2int symfnc) (word2addr maxsymbols)))
         (terpri)
   %     (putmem nextbps 0)            % safe endcondition
         (setq bstart base)
         (setq fktend nil)
(go erstmal)  % erstmal nur ein lauf
  % first pass: find label references
loop1
         (setq p1 (getwrd (int2sys base)))
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
         (setq p1 (wand 255 (byte (int2sys base) 0)))
         (cond((eq p1 0)(return nil)))
     
         (setq pp  
            (list (wand 255 (byte (int2sys base) 1))
                  (wand 255 (byte (int2sys base) 2))
                  (wand 255 (byte (int2sys base) 3))
                  (wand 255 (byte (int2sys base) 4))
                  (wand 255 (byte (int2sys base) 5))
                  (wand 255 (byte (int2sys base) 6))
                  (wand 255 (byte (int2sys base) 7))
                  (wand 255 (byte (int2sys base) 8))
                  (wand 255 (byte (int2sys base) 9))
         ))
         (setq *curradr* base *currinst* pp)
         (setq !*comment nil)
         (setq instr (decode p1 pp base))      % instruction
         (setq lth (pop instr))
         (setq name (when instr (pop instr)))

         (when (eq name 'grp1) (setq name (namegrp1)))
         (when (eq name 'grp5) (setq name (namegrp5)))
	 (when (eq name 'grp3) (setq name (namegrp3)))
         (when (eq name 'shift)(setq name (nameshift)))
         (when (eq name 'convert)(setq name (nameconvert)))
	 (when (eq name 'x87fpu) (setq name (name-x87fpu p1)))

         (cond ((atsoc 'op2 instr)
                (setq pat (list (cdr (atsoc 'op1 instr)) ","
                                (cdr (atsoc 'op2 instr)) )))
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
         (ttab 30)
         (when name (prin2 name))
         (ttab 38)
         (if pat (prinblx (subla instr pat)))
         (prin2 "    ")

         (when *comment (ttab 60) (prin2 *comment))
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


