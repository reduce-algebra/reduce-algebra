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

(fi 16#e8 call ((A v)))

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

(dm make-the-instructions(u)
  `(progn
     (setq instrs1 ',instrs1)
     (setq instrs2 ',instrs2)
     (setq instrs3 ',instrs3)
     ))

))

(make-the-instructions)



(setq eregs  '("eax" "ecx" "edx" "ebx" "esp" "ebp" "esi" "edi"))

(fluid '( the-instruction* addr*))

(de decode(p1 pl addr*)
  (prog(i lth name)
      (setq lth 1)
      (setq i (assoc p1 instrs1))
      (when (eq p1 16#0f)
            (setq p1 (pop pl))
            (setq lth 2)
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
    (when (eqcar pat nil) (go done))
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
              (bldmsg "[%w+%w]" (reg-m rm)(pop bytes*)))
        ((eq mod 2) 
              (setq  lth* (plus 4 lth*))
	      (setq w (bytes2word))
	      (cond ((equal w 16#B8000000) (setq *comment " -> car"))
		    ((equal w 16#B8000004) (setq *comment " -> cdr")))	      
              (bldmsg "[%w+%x]" (reg-m rm) (int2sys w)))
        ((eq mod 3)  (bldmsg "%w" (reg-m rm)))) )))
              
(de decode-sib(p mod)
   (prog(ss index base offset seg b w)
     (setq b (pop bytes*))
     (setq  lth* (add1 lth*))
     (setq ss (wshift b -6))
     (setq index (wand 7 (wshift b -3)))
     (setq index "")  % erstmal
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
             ((or (eq base 2#100)(eq base 2#101)) "")
             (t "ss")))
     (setq segment* nil)
     (return (bldmsg "%w[%w%w%w]" seg (reg-m base) index offset))))


(de reg-m(n)
  (cond ((eq n 0) 'eax)
        ((eq n 1) 'ecx)
        ((eq n 2) 'edx)
        ((eq n 3) 'ebx)
        ((eq n 4) 'esp)
        ((eq n 5) 'ebp)
        ((eq n 6) 'esi)
        ((eq n 7) 'edi)))

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
         (prinblx (subla instr pat))
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


