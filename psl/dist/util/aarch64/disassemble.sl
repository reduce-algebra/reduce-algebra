%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:  pxu/disassemble.sl -  disassembler for aarch64
%
% Author: Rainer Schöpf
%
% Date :  20-Dec-2024
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  $Id$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load common))


(fluid '(bytes* lth* reg* regnr* segment*  symvalhigh symfnchigh *curradr* *currinst* *big-endian*
	 labels* *largest-target-addr* targetaddr* targetaddr-is-load*
	 return-seen* genlbl-pname* gensympname))

          (de getwrd(a)(getmem a))

          (de getfunctionaddress(fkt) 
             (wshift(wshift (cdr (getd fkt)) 8) -8))

          (de idnumberp(x)
           (cond ((not (posintp x)) nil)
                 ((greaterp x (lshift maxsymbols 1)) nil)
                 ((stringp (symnam x)) x)
                 (t nil)))

          (de safe!-int2id(x)
            (setq x (wand 16#f7ffffff x))
            (if (idnumberp x) (mkid x) (mkid 32)))

          (copyd 'ttab 'tab)

(setq genlbl-pname* "L0001")

(de gen-target-label ()
    (let ((gensympname genlbl-pname*))
      (interngensym)))
      

(de unknown-instr-error (pp)
    (stderror (bldmsg "Unknown aarch64 instruction %x" pp)))

(de word2addr (n) (times n 4))
%(de addr2word (n) (quotient n 4))
%(de jump2word (n) (quotient n 6))


(fluid '(!*comment fktend !*hardjump instrs1 instrs2 instrs3 instrs*))

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


(dm make-the-instructions(u)
  `(progn
     (setq instrs1 ',instrs1)
     (setq instrs2 ',instrs2)
     (setq instrs3 ',instrs3)
     ))

))

(make-the-instructions)




(fluid '( the-instruction* addr* cclist* extendlist* reglist* dataproc* shiftoplist* multiply*))

(setq cclist*
      '((2#0000 EQ) (2#0001 NE) (2#0010 CS) (2#0011 CC)
	(2#0100 MI) (2#0101 PL) (2#0110 VS) (2#0111 VC)
	(2#1000 HI) (2#1001 LS) (2#1010 GE) (2#1011 LT)
	(2#1100 GT) (2#1101 LE) (2#1110 "")))

(setq extendlist*
      '((2#000 . "UXTB")
	(2#001 . "UXTH")
	(2#010 . "UXTW")
	(2#011 . "LSL")
	(2#100 . "SXTB")
	(2#101 . "SXTH")
	(2#110 . "SXTW")
	(2#111 . "SXTX")))

(de decode-cc (cc)
    (let ((cctext (assoc cc cclist*)))
      (and cctext (cadr cctext))))

(de decode-extend (option)
    (let ((ext (assoc option extendlist*)))
      (and ext (cdr ext))))

(de bx-preferred (sf uns imms immr)
    (cond ((wlessp imms immr)
	   nil)
	  ((or (and (weq sf 0) (weq imms 2#011111)) (and (weq sf 1) (weq imms 2#111111)))
	   nil)
	  ((and (weq immr 0) (weq sf 0) (or (weq imms 2#000111) (weq imms 2#001111)))
	   nil)
	  ((and (weq immr 0) (weq sf 1) (weq uns 0) (or (weq imms 2#000111) (weq imms 2#001111) (weq imms 2#011111)))
	   nil)
	  (t t))
    )

(de highest-set-bit (x)
    (let ((n 0) (result -1))
       (while (wlessp n 64)
 	(if (weq (wand 1 x) 1) (setq result n))
 	(setq x (wshift x -1))
 	(setq n (iadd1 n)))
       result))

(de Ones (n)
    (wdifference (wshift 1 n) 1))

(de ROR (x N shift)
    (when (weq shift 0) (stderror "Error in instruction encoding"))
    (while (wgeq shift N) (setq shift (wdifference shift N))) % compute: shift mod N
    (wor (wshift x shift) (wshift x (wdifference N shift))))

(de replicate (x xsize ntimes)
    (let ((result 0) (n 0))
      (while (wgreaterp ntimes n)
	(setq result (wor (wshift result xsize) x))
	(setq n (iadd1 n)))))

(de decode-bitmasks (N imms immr immediate?)
    (let* ((len (highest-set-bit (wor (wshift N 6) (wnot imms))))
	   (levels (wshift 2#111111 (wdifference len 6)))
	   (S (wand imms levels))
	   (R (wand immr levels))
	   (d (wdifference S R))
	   (esize (wshift 1 len))
	   (welem (Ones (iadd1 S)))
	   (telem (Ones (iadd1 d)))
	   (rtimes (wquotient 64 esize))
	   (wmask (replicate (ROR welem esize R) esize rtimes))
	   (tmask (replicate telem esize rtimes)))
      (cons wmask tmask))
    )

(de prefix!# (imm)
    (bldmsg "#%d" imm))

(de regnum-to-regname (n is64bit isSP)
    (cond ((equal n 31)
	   (if (weq 0 is64bit)
	       (if isSP '!W!S!P '!W!Z!R)
	     (if isSP '!S!P '!X!Z!R)))
	  (t (intern (bldmsg "%s%d" (if (weq 0 is64bit) "W" "X") n)))))

(de regnum-to-simd-regname (n size opc)
    (let ((prefix
	   (if (weq opc 2#10) (assoc size '((0 . "Q")))
	     (assoc size '((0 . "S") (1 . "D") (2 . "Q"))))))
      (when prefix (intern (bldmsg "%s%d" (cdr prefix) n)))))

(de regnum-to-simd-regname1 (n size opc)
    (let ((prefix
	   (if (weq opc 2#11) (assoc size '((0 . "Q")))
	     (assoc size '((0 . "B") (1 . "H") (2 . "S") (3 . "D"))))))
      (when prefix (intern (bldmsg "%s%d" (cdr prefix) n)))))

(de regnum-to-simd-regname2 (n bitsize)
    (intern (bldmsg "%s%d" (cdr (assoc bitsize '((0 . "S") (1 . "D") (2 . "Q") (3 . "H")))) n)))

(de regnum-to-simd-regname3 (n)
    (intern (bldmsg "V%d.D[1]" n)))

(de decode (p1 pp addr*)
  (prog (i lth name instr)
      (setq targetaddr* nil targetaddr-is-load* nil)
      (setq lth 4)
      (if return-seen* (return (list ".word" pp)))
%      (setq cc (wand 16#0f (wshift pp -28)))
      %% big branch for various instruction types
      (setq instr
	    (cond ((weq (wand 2#00011100 p1) 2#00010000)
		   (decode-dataproc-imm p1 pp))
		  ((weq (wand 2#00011100 p1) 2#00010100)
		   (decode-branch p1 pp))
		  ((weq (wand 2#00001010 p1) 2#00001000)
		   (decode-load-store p1 pp))
		  ((weq (wand 2#00001110 p1) 2#00001010)
		   (decode-dataproc-reg p1 pp))
		  ((weq (wand 2#01011111 p1) 2#00011110)
		   (decode-dataproc-fp p1 pp))
		  ((weq (wand 2#00001110 p1) 2#00001110)
		   (decode-dataproc-simd p1 pp))
		  (t
		   (unknown-instr-error pp))
		  ))
      (when (and targetaddr* (not (assoc targetaddr* labels*)))
	(setq labels* (cons (cons targetaddr* (gen-target-label)) labels*))
	(setq *comment (cond ((not targetaddr-is-load*) (cdar labels*))
			     ((weq (tag (getmem targetaddr*)) id-tag) (bldmsg "%w -> %w" (cdar labels*) (getmem targetaddr*)))
			     (t (bldmsg "%w = %d -> %w" (cdar labels*) (getmem targetaddr*) (safe-int2id (getmem targetaddr*)))))))
      (return instr)
      ))

(de decode-branch (p1 pp)
    (prog (instr offset sf op1 bitnumber)
	  (setq sf (wand 1 (wshift p1 -7)))
	  (cond ((weq (wand p1 2#01111100) 2#00010100) % immediate branch
		 (setq instr (if (weq 0 sf) 'b 'bl))
		 (setq offset (wshift (wand 16#3ffffff pp) 2))
		 (when (wgreaterp offset (isub1 (wshift 1 27)))
		   (setq offset (wdifference offset (wshift 1 28))))
		 (setq targetaddr* (wplus2 *curradr* offset))
		 (if (wgreaterp targetaddr* *largest-target-addr*)
		     (setq *largest-target-addr* targetaddr*))
		 (return (list instr (bldmsg "0x%x" targetaddr*))))
		((weq (wand p1 2#01111110) 2#00110100) % compare & branch imm.
		 (setq op1 (wand 1 p1))
		 (setq instr (if (weq 0 op1) 'cbz 'cbnz))
		 (setq offset (wshift (wand 16#ffffe0 pp) -3))
		 (when (wgreaterp offset (isub1 (wshift 1 20)))
		   (setq offset (wdifference offset (wshift 1 21))))
		 (setq targetaddr* (wplus2 *curradr* offset))
		 (if (wgreaterp targetaddr* *largest-target-addr*)
                     (setq *largest-target-addr* targetaddr*))
                 (return (list instr (regnum-to-regname (wand pp 16#1f) sf) (bldmsg "0x%x" targetaddr*))))
		((weq (wand p1 2#01111110) 2#00110110) % test & branch imm.
		 (setq op1 (wand 1 p1))
		 (setq instr (if (weq 0 op1) 'tbz 'tbnz))
		 (setq bitnumber (wshift (wand pp 16#ffffff) -19))
		 (setq offset (wshift (wand pp 16#7ffe0) -3))
		 (when (wgreaterp offset (isub1 (wshift 1 25)))
		   (setq offset (wdifference offset (wshift 1 16))))
		 (setq targetaddr* (wplus2 *curradr* offset))
		 (if (wgreaterp targetaddr* *largest-target-addr*)
                     (setq *largest-target-addr* targetaddr*))
                 (return (list instr (regnum-to-regname (wand pp 16#1f) sf) (prefix!# bitnumber) (bldmsg "0x%x" targetaddr*))))
		((and (weq (wand p1 2#11111110) 2#01010100) (weq (wand pp 16#10) 0)) % cond. branch imm.
		 (setq instr (bldmsg "b.%w" (decode-cc (wand 16#f pp))))
		 (setq offset (wshift (wand 16#ffffe0 pp) -3))
		 (when (wgreaterp offset (isub1 (wshift 1 20)))
		   (setq offset (wdifference offset (wshift 1 21))))
		 (setq targetaddr* (wplus2 *curradr* offset))
		 (if (wgreaterp targetaddr* *largest-target-addr*)
                     (setq *largest-target-addr* targetaddr*))
                 (return (list instr (bldmsg "0x%x" targetaddr*))))
		((weq p1 2#11010100)	% Exception generation
		 
		 )
		((and (weq p1 2#11010101) (wand 2#11 (wshift pp -22) 0)) % System
		 (decode-system p1 pp sf))
		((weq (wand p1 2#11111110) 2#11010110) % Uncond. branch register
		 (setq op1 (wand 2#1111 (wshift pp -21)))
		 (let ((op2 (wand 2#11111 (wshift pp -16)))
		       (op3 (wand 2#111111 (wshift pp -10)))
		       (op4 (wand 2#11111 pp))
		       (reg (wand 2#11111 (wshift pp -5)) 1))
		   (cond ((not (and (weq op2 2#11111) (weq op3 0) (weq op4 0)))
			  (unknown-instr-error pp))
			 ((weq op1 2#0000) (return (list 'br (regnum-to-regname reg 1))))
			 ((weq op1 2#0001) (return (list 'blr (regnum-to-regname reg 1))))
			 ((weq op1 2#0010) (return (if (weq reg 30) (list 'ret) (list 'ret reg))))
			 ((and (weq op1 2#0100) (eq reg 2#11111) (return (list 'eret))))
			 ((and (weq op1 2#0101) (eq reg 2#11111) (return (list 'drps))))
			 (t (unknown-instr-error pp))
			 ))
		 )
		(t (unknown-instr-error pp))
		)
	  )
    )

(de num-to-cregname (n)
    (bldmsg "C%d" n))

(de decode-systemreg (op0 op1 crn crm op2)

    (cond
     
    %% 2#11 2#000 2#0001 2#0000 2#901 ACTLR_EL1
    %% 2#11 2#100 2#0001 2#0000 2#001 ACTLR_EL2
    %% 2#11 2#110 2#0001 2#0000 2#001 ACTLR_EL3
    %% 2#11 2#000 2#0101 2#0001 2#000 AFSR0_EL1
    %% 2#11 2#100 2#0101 2#0001 2#000 AFSR0_EL2
    %% 2#11 2#110 2#0101 2#0001 2#000 AFSR0_EL3
    %% 2#11 2#000 2#0101 2#0001 2#001 AFSR0_EL1
    %% 2#11 2#100 2#0101 2#0001 2#001 AFSR0_EL2
    %% 2#11 2#110 2#0101 2#0001 2#001 AFSR0_EL3
    %% 2#11 2#001 2#0000 2#0000 2#111 AIDR_EL1
    %% 2#11 2#000 2#1010 2#0011 2#000 AMAIR_EL1
    %% 2#11 2#100 2#1010 2#0011 2#000 AMAIR_EL2
    %% 2#11 2#110 2#1010 2#0011 2#000 AMAIR_EL3
    %% 2#11 2#001 2#0000 2#0000 2#000 CCSIDR_EL1
    %% 2#11 2#001 2#0000 2#0000 2#001 CLIDR_EL1
    %% 2#11 2#000 2#1101 2#0000 2#001 CONTEXTIDR_EL1
    %% 2#11 2#000 2#0001 2#0000 2#010 CPACR_EL1
    %% 2#11 2#100 2#0001 2#0001 2#010 CPTR_EL2
    %% 2#11 2#110 2#0001 2#0001 2#010 CPTR_EL3

    %% 2#11 2#100 2#0101 2#0011 2#000 FPEXC32_EL2

     ((and (weq op0 2#11) (weq op1 2#011) (weq crn 2#0100) (weq crm 2#0100) (weq op2 2#000)) 'FPCR)
     ((and (weq op0 2#11) (weq op1 2#011) (weq crn 2#0100) (weq crm 2#0100) (weq op2 2#001)) 'FPSR)
     ((and (weq op0 2#11) (weq op1 2#011) (weq crn 2#0100) (weq crm 2#0010) (weq op2 2#000)) 'NZCV)
     (t 'not-yet-implemented)
    ))

(de decode-system (p1 pp sf)
    (let ((!L (wand 1 (wshift pp -21)))
	  (op0 (wand 2#11 (wshift pp -19)))
	  (op1 (wand 2#111 (wshift pp -16)))
	  (crn (wand 2#1111 (wshift pp -12)))
	  (crm (wand 2#1111 (wshift pp -8)))
	  (op2 (wand 2#111 (wshift pp -5)))
	  (regt (wand 2#11111 pp))
	  (systemreg))
      (cond ((weq op0 2#01)
	     (if (weq !L 1)
		 (list 'sysl (regnum-to-regname regt 1 nil) (prefix!' op1) (num-to-cregname crn) (num-to-cregname crm) (prefix!' op2))
	       (list 'sys (prefix!# op1) (num-to-cregname crn) (num-to-cregname crm) (prefix!# op2)
		     (when (wneq regt 2#11111) (regnum-to-rename regt sf nil)))))
	    ((wgeq op0 2#10)
	     (setq systemreg (decode-systemreg op0 op1 crn crm op2))
	     (if (weq !L 1)
		 (list 'mrs (regnum-to-regname regt 1 nil) systemreg)
	       (list 'msr systemreg (regnum-to-regname regt 1 nil))))
	    ((wneq regt 2#11111) (unknown-instr-error pp))
	    ((and (weq !L 0) (weq crn 2#0100)) % MSR immediate
	     (let ((pstatefield
		    (cond ((and (weq op1 2#000) (weq op2 2#101)) "SPSel")
			  ((and (weq op1 2#011) (weq op2 2#110)) "DAIFSet")
			  ((and (weq op1 2#011) (weq op2 2#11)) "DAIFClr")
			  (t (unknown-instr-error pp)))))
	       (list 'msr pstatefield (prefix!# crm))))
	    ((and (weq !L 0) (weq op1 2#011))
	     (list
	      (cond ((or (wneq crm 2#0000) (weq op2 2#000)) 'nop)
		    ((weq op2 2#101) 'sevl)
		    ((weq op2 2#100) 'sev)
		    ((weq op2 2#011) 'wfi)
		    ((weq op2 2#010) 'wfe)
		    ((weq op2 2#001) 'yield)
		    (t (unknown-instr-error pp)))))
	    (t (unknown-instr-error pp)))
      ))	       


(de decode-dataproc-pcrel (p1 pp sf opc)
    (let ((instr (if (weq sf 0) 'adr 'adrp))
	  (immediate (wshift (wand pp 16#ffffff) -5))
	  )
      (setq immediate (wor (wshift immediate 2) opc))                                                                                                                                
      (if (weq sf 1) (setq immediate (wshift immediate 12)))
      (setq targetaddr* (wplus2 8 (wplus2 *curradr* immediate)))
      (if (wgreaterp targetaddr* *largest-target-addr*) (setq *largest-target-addr* targetaddr*))
      (list instr (bldmsg "0x%x" targetaddr*))
      ))

(de decode-dataproc-arith-imm (p1 pp sf opc)
    (let ((instr (cdr (assoc opc '((0 . add) (1 . adds) (2 . sub) (3 . subs)))))
	  (shift (wand 2#11 (wshift pp -21)))
	  (immediate (wand 16#fff (wshift pp -10)))
	  (regd (wand pp 2#11111))
	  (regn (wand (wshift pp -5) 2#11111)))
      (when (wgreaterp shift 1) (unknown-instr-error pp))
      %% aliases
      (cond ((and (eq instr 'add) (or (weq regd 31) (weq regn 31)) (eq immediate 0) (eq shift 0))
	     (list 'mov (regnum-to-regname regd sf t) (regnum-to-regname regn sf t)))
	    ((and (eq instr 'adds) (weq regd 31))
	     (list 'cmn (regnum-to-regname regn sf t) (prefix!# immediate) (if (wneq shift 0) "LSL #12")))
	    ((and (eq instr 'subs) (weq regd 31))
	     (list 'cmp (regnum-to-regname regn sf t) (prefix!# immediate) (if (wneq shift 0) "LSL #12")))
	    (t (list instr (regnum-to-regname regd sf) (regnum-to-regname regn sf)
		     (prefix!# immediate) (if (wneq shift 0) "LSL #12")))
      )))

(de decode-dataproc-log-imm (p1 pp sf opc)
    (let* ((!N (wand 1 (wshift pp -22)))
	   (instr (cdr (assoc opc '((0 . and) (1 . orr) (2 . eor) (3 . ands)))))
	   (immediate (car (decode-bitmasks !N (wand 2#111111 (wshift pp -16)) (wand 2#111111 (wshift pp -10)) t)))
	   (regd (wand pp 2#11111))
	   (regn (wand (wshift pp -5) 2#11111)) )
      (when (and (weq sf 0) (weq !N 1)) (unknown-instr-error pp))
      (list instr (regnum-to-regname regd sf t) (regnum-to-regname regn sf nil) (prefix!# immediate))
      ))

(de decode-dataproc-movew-imm (p1 pp sf opc)
    (let ((hw (wand 2#11 (wshift pp -21)))
	  (instr)
	  (shift)
	  (imm16 (wand 16#ffff (wshift pp -5)))
	  (regd (wand pp 2#11111)))
      (when (or (weq opc 1) (and (weq sf 0) (wgreaterp hw 1))) (unknown-instr-error pp))
      (setq instr (cdr (assoc opc '((0 . movn) (2 . movz) (3 . movk)))))
      (setq shift (wshift hw 4))
      %% aliases
      (when (and (not (eq instr 'movk)) (not (and (weq imm16 0) (wgreaterp hw 0))))
	(when (or (eq instr 'movz)
		  (weq sf 1)
		  (and (weq sf 0) (not (weq imm16 16#ffff))))
	  (setq imm16 (wshift imm16 shift))
	  (setq shift 0)
	  (if (eq instr 'movn) (setq imm16 (wnot imm16)))
	  (setq instr 'mov)
))
      (setq instr (list instr (regnum-to-regname regd sf nil) (prefix!# imm16)))
      (if (weq shift 0) instr
	(nconc instr (list (bldmsg "LSL #%d" shift))))
      ))

(de decode-dataproc-bitfield (p1 pp sf opc)
    (let* ((!N (wand 1 (wshift pp -22)))
	   (instr (assoc opc '((0 . sbfm) (1 . bfm) (2 . ubfm))))
	   (immr (wand 2#111111 (wshift pp -16)))
	   (imms (wand 2#111111 (wshift pp -10)))
	   (regd (wand pp 2#11111))
	   (regn (wand (wshift pp -5) 2#11111)) )
      (if (null instr) (unknown-instr-error pp)
	(setq instr (cdr instr)))
      (when (and (weq sf 0) (weq !N 1)) (unknown-instr-error pp))
      %% aliases
      (cond ((eq instr 'bfm)
	     (list (if (wlessp imms immr) 'bfi 'bfxil)
		   (regnum-to-regname regd sf nil)
		   (regnum-to-regname regn sf nil)
		   (prefix!# (if (weq sf 1) (wand 2#111111 (wdifference 64 immr)) (wand 2#11111 (wdifference 32 immr))))
		   (prefix!# (iadd1 imms))))
	    ((and (eq instr 'sbfm) (or (and (weq sf 0) (weq imms 2#011111)) (and (weq sf 1) (weq imms 2#111111))))
	     (list 'asr (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil) (prefix!# immr)))
	    ((and (eq instr 'sbfm) (wlessp imms immr))
	     (list 'sbfiz (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil) 0 0))
            ((and (eq instr 'sbfm) (bx-preferred sf (wshift opc -1) imms immr))
             (list 'sbfx (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil) (prefix!# immr) (prefix!# (iadd1 (wdifference imms immr)))))
	    ((and (eq instr 'sbfm) (weq immr 0) (weq imms 2#000111))
	     (list 'sxtb (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil)))
	    ((and (eq instr 'sbfm) (weq immr 0) (weq imms 2#001111))
	     (list 'sxth (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil)))
	    ((and (eq instr 'sbfm) (weq immr 0) (weq imms 2#011111))
	     (list 'sxtw (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil)))
	    ((and (eq instr 'ubfm) (or (and (weq sf 0) (wneq imms 2#011111)) (and (weq sf 1) (wneq imms 2#111111))) (weq (iadd1 imms) immr))
	     (list 'lsl (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil)
		   (prefix!# (if (weq sf 1) (wand 2#111111 (wdifference 64 immr)) (wand 2#11111 (wdifference 32 immr))))))
	    ((and (eq instr 'ubfm) (or (and (weq sf 0) (weq imms 2#011111)) (and (weq sf 1) (weq imms 2#111111))))
	     (list 'lsr (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil) (prefix!# immr)))
	    ((and (eq instr 'ubfm) (wlessp imms immr))
	     (list 'ubfiz (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil) "#0" "#0"))
            ((and (eq instr 'ubfm) (bx-preferred sf opc imms immr))
             (list 'ubfx (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil) (prefix!# immr) (prefix!# (iadd1 (wdifference imms immr)))))
	    ((and (eq instr 'ubfm) (weq immr 0) (weq imms 2#000111))
	     (list 'uxtb (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil)))
	    ((and (eq instr 'ubfm) (weq immr 0) (weq imms 2#001111))
	     (list 'uxth (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil)))
	    (t (list instr (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil) (prefix!# immr) (prefix!# imms))))
      ))


(de decode-dataproc-extract (p1 pp sf opc)
    (let ((!N (wand 1 (wshift pp -22)))
	  (bit21 (wand 1 (wshift pp -21)))
	  (imms (wand 2#111111 (wshift pp -10)))
	  (regd (wand pp 2#11111))
	  (regn (wand (wshift pp -5) 2#11111))
	  (regm (wand (wshift pp -16) 2#11111)))
      (when (or (not (weq sf !N)) (and (weq sf 0) (wgreaterp imms 2#11111)))
	(unknown-instr-error pp))
      (if (weq regn regm)
	  (list 'ror (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil) (prefix!# imms))
	(list 'extr (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil) (regnum-to-regname regm sf nil) (prefix!# imms)))
      ))
    
(de decode-dataproc-imm (p1 pp cc)
    (let ((sf (wand 1 (wshift p1 -7)))
	  (opc (wand 2#11 (wshift p1 -5))))
      (cond ((weq (wand 2#11111 p1) 2#10000) % PC-rel addressing
	     (decode-dataproc-pcrel p1 pp sf opc))

	    ((weq (wand p1 2#11111) 2#10001) % add/subtract immediate
	     (decode-dataproc-arith-imm p1 pp sf opc))

	    ((weq (wand (wshift pp -23) 2#000111111) 2#000100100) % logical immediate
	     (decode-dataproc-log-imm p1 pp sf opc))

	    ((weq (wand (wshift pp -23) 2#000111111) 2#000100101) % move wide immediate
	     (decode-dataproc-movew-imm p1 pp sf opc))

	    ((weq (wand (wshift pp -23) 2#000111111) 2#000100110) % bitfield
	     (decode-dataproc-bitfield p1 pp sf opc))

	    ((weq (wand (wshift pp -23) 2#000111111) 2#000100111) % extract
	     (decode-dataproc-extract p1 pp sf opc))
	    (t (unknown-instr-error pp))
	    )))


(de decode-load-store (p1 pp)
    (cond ((weq (wand 2#00111111 p1) 2#00001000)
	   (decode-load-store-exclusive p1 pp))
	  ((weq (wand 2#00111011 p1) 2#00011000)
	   (decode-load-reg-literal p1 pp))
	  ((weq (wand 2#00111010 p1) 2#00101000)
	   (decode-load-store-pair p1 pp))
	  ((weq (wand 2#00111011 p1) 2#00111000)
	   (cond ((and (weq 0 (wand 1 (wshift pp -21))) (weq 2#00 (wand 2#11 (wshift pp -10))))
		  (decode-load-store-reg-unscaled-imm p1 pp))
		 ((and (weq 1 (wand 1 (wshift pp -21))) (weq 2#10 (wand 2#11 (wshift pp -10))))
		  (decode-load-store-reg-offset p1 pp))
		 (t (decode-load-store-reg p1 pp nil))))
	  ((weq (wand 2#00111011 p1) 2#00111001)
           (decode-load-store-reg p1 pp t))
	  ((weq (wand 2#10111111 p1) 2#00001100)
           (decode-load-store-simd-multiple p1 pp))
	  ((weq (wand 2#00111011 p1) 2#00001101)
           (decode-load-store-simd-single p1 pp))
	  (t (unknown-instr-error pp))
	  ))

(de decode-load-store-exclusive (p1 pp)
    (list 'not-yet-implemented)
    )

(de decode-load-reg-literal (p1 pp)
    (let* ((opc (wand 2#11 (wshift p1 -6)))
	   (!V (wand 1 (wshift p1 -2)))
	   (offset (wshift (wshift (wand 16#ffffff pp) -5) 2))
	   (targetaddr (bldmsg "0x%x" (setq targetaddr* (wplus2 *curradr* offset))))
	   (regt (wand pp 2#11111))
	   (instr))
      (setq targetaddr-is-load* t)
      (cond ((and (weq !V 0) (wlessp opc 2)) % LDR literal
	     (list 'ldr (regnum-to-regname regt opc nil) targetaddr))
	    ((and (weq !V 1) (wlessp opc 3)) % LDR literal simd/fp
	     (list 'ldr (regnum-to-simd-regname2 regt opc) targetaddr))
	    ((and (weq !V 0) (weq opc 2))
	     (list 'ldrsw (regnum-to-regname regt 1 nil) targetaddr))
	    (t (list 'prfm regt) targetaddr))
      ))


(de decode-load-store-pair (p1 pp)
    (let ((opc (wand 2#11 (wshift p1 -6)))
	  (sf)
	  (!V (wand 1 (wshift p1 -2)))
	  (!L (wand 1 (wshift pp -22)))
	  (imm7 (wand 2#1111111 (wshift pp -15)))
	  (regt (wand 2#11111 pp))
	  (regd (wand 2#11111 (wshift pp -5)))
	  (regt2 (wand 2#11111 (wshift pp -10)))
	  (instr))
      (setq sf (wshift opc -1))
      (setq instr (if (weq !L 0) 'stp 'ldp))
      (when (wgreaterp imm7 63) (setq imm7 (wdifference imm7 128))) % convert to signed 7 bit
      (setq imm7 (wshift imm7 (if (weq sf 0) 2 3)))
      (cond ((and (weq (wand p1 1) 0) (weq (wand 1 (wshift pp -23)) 0))
	     (decode-load-store-noalloc-pair p1 pp opc !V))
	    (t
	     (list instr
		   (regnum-to-regname regt sf nil)
		   (regnum-to-regname regt2 sf nil)
		   (bldmsg "[%w%s" (regnum-to-regname regd 1 t) (if (and (weq (wand p1 1) 0) (weq (wand 1 (wshift pp -23)) 1)) "]" ""))
		   (if (not (and (weq (wand p1 1) 1) (weq (wand 1 (wshift pp -23)) 0) (weq imm7 0)))
		       (bldmsg "#%d%s%s" imm7
			       (if (weq (wand p1 1) 1) "]" "")
			       (if (and (weq (wand p1 1) 1) (weq (wand 1 (wshift pp -23)) 1)) "!" ""))))))))

(de decode-load-store-noalloc-pair (p1 pp opc !V)
    (list 'not-yet-implemented 'load-store-noalloc-pair)
    )

(de decode-load-store-reg (p1 pp unsigned)
    (let ((size (wand 2#11 (wshift p1 -6)))
	  (!V (wand 1 (wshift p1 -2)))
	  (opc (wand 2#11 (wshift pp -22)))
	  (imm (if unsigned (wand 16#fff (wshift pp -10))
		 (wand 2#111111111 (wshift pp -12))))
	  (type (wand 2#11 (wshift pp -10)))
	  (regn (wand 2#11111 (wshift pp -5)))
	  (regt (wand 2#11111 pp))
	  (instr)
	  )
      % check for invalid opcodes
      (when (and (wgreaterp opc 1)
		 (or (and (weq size 2#01) (weq !V 1))
		     (and (weq size 2#10) (weq !V 0) (weq opc 2#11))
		     (weq size 2#11)))
	(unknown-instr-error pp))
      (cond ((weq !V 1)
	     (setq instr (if (weq (wand 1 opc) 0) 'str 'ldr)))
	    ((weq size 2#00)
	     (setq instr (cdr (assoc opc '((0 . strb) (1 . ldrb) (2 . ldrsb) (3 . ldrsb))))))
	    ((weq size 2#01)
	     (setq instr (cdr (assoc opc '((0 . strh) (1 . ldrh) (2 . ldrsh) (3 . ldrsh))))))
	    ((weq size 2#10)
	     (setq instr (cdr (assoc opc '((0 . str) (1 . ldr) (2 . strsw))))))
	    (t
	     (setq instr (cdr (assoc opc '((0 . str) (1 . ldr)))))))
      (cond (unsigned (setq imm (wshift imm size)))
	    ((wgreaterp imm 255) (setq imm (wdifference imm 512))))
      (list instr
	    (if (weq !V 1) (regnum-to-simd-regname1 regt size opc) (regnum-to-regname regt (wand size 1) nil))
	    (bldmsg "[%w%s"
		    (if (weq !V 1) (regnum-to-simd-regname1 regn size opc) (regnum-to-regname regn 1 t))
		    (if (or (and (not unsigned) (weq type 2#01)) (and unsigned (weq imm 0))) "]" ""))
	    (if (and unsigned (weq imm 0)) nil
	      (bldmsg "#%d%s" imm
		      (cond (unsigned "]")
			    ((weq type 2#11) "]!")
			    (t "")))))
      )
    )

(de decode-load-store-reg-unscaled-imm (p1 pp)
    (list 'not-yet-implemented 'load-store-reg-unscaled-imm)
    )

(de decode-load-store-reg-offset (p1 pp)
    (let ((size (wand 2#11 (wshift p1 -6)))
	  (!V (wand 1 (wshift p1 -2)))
	  (opc (wand 2#11 (wshift pp -22)))
	  (type (wand 2#11 (wshift pp -10)))
	  (option (wand 2#111 (wshift pp -13)))
	  (!S (wand 1 (wshift pp -12)))
	  (regm (wand 2#11111 (wshift pp -16)))
	  (regn (wand 2#11111 (wshift pp -5)))
	  (regt (wand 2#11111 pp))
	  (instr)
	  (extend)
	  (is64bit)
	  )
      % check for invalid opcodes
      (when (and (wgreaterp opc 1)
		 (or (and (weq size 2#01) (weq !V 1))
		     (and (weq size 2#10) (weq !V 0) (weq opc 2#11))
		     (and (weq size 2#11) (or (and (weq !V 0) (weq opc 2#11)) (weq !V 1)))))
	(unknown-instr-error pp))
      (setq is64bit (if (weq opc 2#10) 1 0))
      (cond ((weq !V 1)
	     (setq instr (if (weq (wand 1 opc) 0) 'str 'ldr))
	     (setq is64bit (wand opc 1)))	    
	    ((weq size 2#00)
	     (setq instr (cdr (assoc opc '((0 . strb) (1 . ldrb) (2 . ldrsb) (3 . ldrsb))))))
	    ((weq size 2#01)
	     (setq instr (cdr (assoc opc '((0 . strh) (1 . ldrh) (2 . ldrsh) (3 . ldrsh))))))
	    ((weq size 2#10)
	     (setq instr (cdr (assoc opc '((0 . str) (1 . ldr) (2 . ldrsw))))))
	    (t
	     (setq instr (cdr (assoc opc '((0 . str) (1 . ldr) (2 . prfm)))))
             (setq is64bit 1)))

      (setq extend (decode-extend option))

      (list instr
	    (regnum-to-regname regt is64bit nil)
	    (bldmsg "[%w" (regnum-to-regname regn 1 t))
	    (bldmsg "%w%s" (regnum-to-regname regm (wand option 1) nil) (if (and (weq size 0) (weq !S 0) (equal extend "LSL")) "]" ""))
	    (if (and (weq size 0) (weq !S 0))
		(when (not (equal extend "LSL")) (bldmsg "%s]" "" extend))
	      (bldmsg "%s #%d]" extend size)))
      )
    )

(de decode-load-store-reg-unsigned-imm (p1 pp)
    (list 'not-yet-implemented 'load-store-reg-unsigned-imm)
    )

(de decode-load-store-simd-multiple (p1 pp)
    (list 'not-yet-implemented 'load-store-simd-multiple)
    )

(de decode-load-store-simd-single (p1 pp)
    (list 'not-yet-implemented 'load-store-simd-single)
    )

(de decode-dataproc-reg (p1 pp)
    (let ((sf (wand 1 (wshift p1 -7)))
	  (opc (wand 2#11 (wshift p1 -5))))
      (cond ((weq (wand 2#11111 p1) 2#01010)
	     (decode-dataproc-logical p1 pp sf opc))
	    ((weq (wand 2#11111 p1) 2#01011)
	     (decode-dataproc-add-sub p1 pp sf opc))
	    ((weq (wand 2#11111 p1) 2#11011)
	     (decode-dataproc-3source p1 pp sf opc))
	    ((weq (wand 2#11111 p1) 2#11010)
	     (decode-dataproc-rest p1 pp sf opc))
	    )
      ))

(de decode-dataproc-logical (p1 pp sf opc)
    (let ((shift (wand 2#11 (wshift pp -22)))
	  (!N (wand 1 (wshift pp -21)))
	  (imm6 (wand 2#111111 (wshift pp -10)))
	  (regd (wand pp 2#11111))
	  (regn (wand (wshift pp -5) 2#11111))
	  (regm (wand (wshift pp -16) 2#11111))
	  (instr)
	  (shiftop))
      (if (weq !N 0)
	  (setq instr (cdr (assoc opc '((0 . and) (1 . orr) (2 . eor) (3 . ands)))))
	(setq instr (cdr (assoc opc '((0 . bic) (1 . orn) (2 . eon) (3 . bics))))))
      (when (and (weq sf 0) (weq 1 (wand 2#100000 imm6)))
	(unknown-instr-error pp))
      (setq shiftop (cdr (assoc shift '((0 . "LSL") (1 . "LSR") (2 . "ASR") ( 3 . "ROR")))))
      %% aliases
      (cond ((and (eq instr 'orr) (weq regn 2#11111) (weq 0 shift) (weq 0 imm6))
	     (list 'mov (regnum-to-regname regd sf nil) (regnum-to-regname regm sf nil)))
	    ((and (eq instr 'orn) (weq regn 2#11111))
	     (list 'mvn (regnum-to-regname regd sf nil) (regnum-to-regname regm sf nil)))
	    ((and (eq instr 'ands) (weq regd 2#11111))
	     (list 'tst (regnum-to-regname regn sf nil) (regnum-to-regname regm sf nil)) (if (wneq imm6 0) (bldmsg "%s #%d" shiftop imm6)))
	    (t (list instr (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil) (regnum-to-regname regm sf nil)
		     (if (wneq imm6 0) (bldmsg "%s #%d" shiftop imm6)))))
      )
    )
    
(de decode-dataproc-add-sub (p1 pp sf opc)
    (let ((shift (wand 2#11 (wshift pp -22)))
	  (type (wand 1 (wshift pp -21)))
	  (imm6 (wand 2#111111 (wshift pp -10)))
	  (regd (wand pp 2#11111))
	  (regn (wand (wshift pp -5) 2#11111))
	  (regm (wand (wshift pp -16) 2#11111))
	  (instr (cdr (assoc opc '((0 . add) (1 . adds) (2 . sub) (3 . subs))))))
      (when (or (weq shift 2#11) (and (weq sf 0) (weq 1 (wand 2#100000 imm6))))
	(unknown-instr-error pp))
      (setq shift (cdr (assoc shift '((0 . "LSL") (1 . "LSR") (2 . "ASR")))))
      (if (weq type 0)			% shifted register
	  (cond ((and (eq instr 'ands) (weq regd 2#11111))
		 (list 'cmn (regnum-to-regname regn sf nil) (regnum-to-regname regm sf nil) (if (wneq imm6 0) (bldmsg "%s #%d" shift imm6))))
		((and (eq instr 'subs) (weq regd 2#11111))
		 (list 'cmp (regnum-to-regname regn sf nil) (regnum-to-regname regm sf nil) (if (wneq imm6 0) (bldmsg "%s #%d" shift imm6))))
		((and (eq instr 'subs) (weq regn 2#11111))
		 (list 'negs (regnum-to-regname regd sf nil) (regnum-to-regname regm sf nil) (if (wneq imm6 0) (bldmsg "%s #%d" shift imm6))))
		((and (eq instr 'sub) (weq regn 2#11111))
		 (list 'neg (regnum-to-regname regd sf nil) (regnum-to-regname regm sf nil) (if (wneq imm6 0) (bldmsg "%s #%d" shift imm6))))
		(t (list instr (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil) (regnum-to-regname regm sf nil) (if (wneq imm6 0) (bldmsg "%s #%d" shift imm6)))))
	(let* ((option (wshift imm6 -3)) % extended register
	       (imm3 (wand 2#111 imm6))
	       (regm-name (regnum-to-regname regm (if (weq (wand option 2#11) 2#11) 1 0) nil))
	       (extend (cdr (assoc option '((0 . "UXTB") (1 . "UXTH") (2 . "UXTW") (3 . "UXTX") (4 . "SXTB") (5 . "SXTH") (6 . "SXTW") (7 . "SXTX"))))))
	  (when (wgreaterp imm3 4) (unknown-instr-error pp))
	  (when (and (or (weq regd 31) (weq regn 31)) (weq option 2#011))
	    (setq extend "LSL"))
	  (cond ((and (eq instr 'ands) (weq regd 2#11111))
		 (list 'cmn (regnum-to-regname regn sf t) regm-name (if (wneq imm3 0) (bldmsg "%s #%d" extend imm3))))
		((and (eq instr 'subs) (weq regd 2#11111))
		 (list 'cmp (regnum-to-regname regn sf nil) regm-name (if (wneq imm3 0) (bldmsg "%s #%d" extend imm3))))
		(t (list instr (regnum-to-regname regd sf t) (regnum-to-regname regn t) regm-name (if (wneq imm3 0) (bldmsg "%s #%d" extend imm3)))))
	  ))
	))
    
(de decode-dataproc-3source (p1 pp sf op54)
    (let ((op31 (wand 2#111 (wshift pp -21)))
	  (o0 (wand 1 (wshift pp -15)))
	  (regd (wand pp 2#11111))
	  (regn (wand (wshift pp -5) 2#11111))
	  (regm (wand (wshift pp -16) 2#11111))
	  (rega (wand (wshift pp -10) 2#11111))
	  (instr))
      (if (weq o0 0)
	  (setq instr (assoc op31 '((0 . madd) (1 . smaddl) (2 . smulh) (5 . umaddl) (6 . umulh))))
	(setq instr (assoc op31 '((0 . msub) (1 . smsubl) (5 . umsubl)))))
      (if (or (null instr) (and (weq sf 0) (wneq op31 0)))
	  (unknown-instr-error pp)
	(setq instr (cdr instr)))
      (cond ((and (eq instr 'madd) (weq rega 2#11111))
	     (list 'mul (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil) (regnum-to-regname regm sf nil)))
	    ((and (eq instr 'msub) (weq rega 2#11111))
	     (list 'mneg (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil) (regnum-to-regname regm sf nil)))
	    ((and (eq instr 'smaddl) (weq rega 2#11111))
	     (list 'smull (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil) (regnum-to-regname regm sf nil)))
	    ((and (eq instr 'smsubl) (weq rega 2#11111))
	     (list 'smnegl (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil) (regnum-to-regname regm sf nil)))
	    ((and (eq instr 'umaddl) (weq rega 2#11111))
	     (list 'umull (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil) (regnum-to-regname regm sf nil)))
	    ((and (eq instr 'umsubl) (weq rega 2#11111))
	     (list 'umnegl (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil) (regnum-to-regname regm sf nil)))
	    (t (list instr (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil) (regnum-to-regname regm sf nil) (regnum-to-regname rega sf nil))))
      ))


(de decode-dataproc-rest (p1 pp sf opc)
    (case (wand 2#111 (wshift pp -21))
	  ((2#000) (decode-add-sub-carry p1 pp sf opc))
	  ((2#010) (decode-cond-compare p1 pp sf opc))
	  ((2#100) (decode-cond-select p1 pp sf opc))
	  ((2#110) (if (weq 2#00011010 (wand 2#01011010 p1))
		       (decode-dataproc-2source p1 pp sf opc)
		     (decode-dataproc-1source p1 pp sf opc)))
	  (nil (unknown-instr-error pp))))

(de decode-add-sub-carry (p1 pp sf opc)
    (list 'not-yet-implemented 'decode-add-sub-carry)
    )
    
(de decode-cond-compare (p1 pp sf opc)
    (list 'not-yet-implemented 'decode-cond-compare)
    )
    
(de decode-cond-select (p1 pp sf opc)
    (list 'not-yet-implemented 'decode-cond-select)
    )
    
(de decode-dataproc-2source (p1 pp sf opc)
    (let ((!S (wand 1 (wshift p1 -5)))
	  (opcode (wand 2#111111 (wshift pp -10)))
	  (regd (wand pp 2#11111))
	  (regn (wand (wshift pp -5) 2#11111))
	  (regm (wand (wshift pp -16) 2#11111))
	  (instr))
      (setq instr (assoc opcode '((2#000010 udiv) (2#000011 sdiv)
				  (2#001000 lsl) (2#001001 lsr)
				  (2#001010 asr) (2#001011 ror)
				  (2#010000 crc32b) (2#010100 crc32cb)
				  (2#010001 crc32h) (2#010101 crc32ch)
				  (2#010010 crc32w) (2#010110 crc32cw)
				  (2#010011 crc32x) (2#010111 crc32cx))))
      (when (or (weq !S 1) (null instr)) (unknown-instr-error pp))
      (setq instr (cadr instr))
      (list instr  (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil) (regnum-to-regname regm sf nil))
      ))

    
(de decode-dataproc-1source (p1 pp sf opc)
    (let ((!S (wand 1 (wshift p1 -5)))
	  (opcode (wand 2#111111 (wshift pp -10)))
	  (opcode2 (wand (wshift pp -16) 2#11111))
	  (regd (wand pp 2#11111))
	  (regn (wand (wshift pp -5) 2#11111))
	  (instr))
      (if (weq sf 0)
	  (setq instr (assoc opcode '((2#000000 rbit) (2#000001 rev16) (2#000010 rev) (2#000100 clz) (2#000101 cls))))
	(setq instr (assoc opcode '((2#000000 rbit) (2#000001 rev16) (2#000010 rev32) (2#000011 rev) (2#000100 clz) (2#000101 cls)))))
      (when (or (weq !S 1) (wneq opcode2 0) (null instr)) (unknown-instr-error pp))
      (setq instr (cadr instr))
      (list instr (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil))
      ))

    
(de decode-dataproc-fp (p1 pp)
    (let ((sf (wand 1 (wshift p1 -7)))
	  (!S (wand 1 (wshift p1 -5)))
	  (type (wand 2#11 (wshift pp -22))))
      (cond ((weq 2#11111 (wand p1 2#11111))
	     (decode-dataproc-fp-3source p1 pp sf !S type))
	    ((weq 0 (wand 1 (wshift pp -21)))
	     (decode-dataproc-fp-conv-fixed p1 pp sf !S type))
	    ((weq 0 (wand 2#111111 (wshift pp -10)))
	     (decode-dataproc-fp-conv-int p1 pp sf !S type))
	    ((weq 2#10000 (wand 2#11111 (wshift pp -10)))
	     (decode-dataproc-fp-1source p1 pp sf !S type))
	    ((weq 2#1000 (wand 2#1111 (wshift pp -10)))
	     (decode-dataproc-fp-cmp p1 pp sf !S type))
	    ((weq 2#100 (wand 2#111 (wshift pp -10)))
	     (decode-dataproc-fp-imm p1 pp sf !S type))
	    ((weq 2#01 (wand 2#11 (wshift pp -10)))
	     (decode-dataproc-fp-cond-cmp p1 pp sf !S type))
	    ((weq 2#10 (wand 2#11 (wshift pp -10)))
	     (decode-dataproc-fp-2source p1 pp sf !S type))
	    ((weq 2#11 (wand 2#11 (wshift pp -10)))
	     (decode-dataproc-fp-cond-select p1 pp sf !S type))
	    (t (unknown-instr-error pp)))
      ))

(de decode-dataproc-fp-conv-fixed (p1 pp sf !S type)
    (list 'not-yet-implemented 'decode-dataproc-fp-conv-fixed))

(de decode-dataproc-fp-conv-int (p1 pp sf !S type) 
    (let ((rmode (wand 2#11 (wshift pp -19)))
	  (opcode (wand 2#111 (wshift pp -16)))
	  (regd (wand 2#11111 pp))
	  (regn (wand 2#11111 (wshift pp -5)))
	  (instr)
	  )
      (cond ((and (weq !S 0) (wleq type 1) (weq rmode 0))
	     (cond ((weq opcode 2#010)
		    (list 'scvtf (regnum-to-simd-regname2 regd type) (regnum-to-regname regn sf nil)))
		   ((weq opcode 2#011)
		    (list 'ucvtf (regnum-to-simd-regname2 regd type) (regnum-to-regname regn sf nil)))
		   ((weq opcode 2#110)
		    (list 'fmov (regnum-to-regname regd sf nil) (regnum-to-simd-regname2 regn type)))
		   ((weq opcode 2#111)
		    (list 'fmov (regnum-to-simd-regname2 regd type) (regnum-to-regname regn sf nil)))
		   (t
		    (setq instr (cdr (assoc opcode '((2#000 . fcvtns) (2#001 . fcvtnu) (2#100 . fcvtas) (2#101 . fcvtau)))))
		    (list instr (regnum-to-regname regd sf nil) (regnum-to-simd-regname2 regn type)))))
	    ((and (weq !S 0) (wleq type 1) (wleq opcode 2#001))
	     (case rmode
		   ((2#01) (setq instr (if (weq opcode 0) 'fcvtps 'fcvtpu)))
		   ((2#10) (setq instr (if (weq opcode 0) 'fcvtms 'fcvtmu)))
		   ((2#11) (setq instr (if (weq opcode 0) 'fcvtZs 'fcvtzu))))
	     (list instr (regnum-to-regname regd sf nil) (regnum-to-simd-regname2 regn type)))
	    ((and (weq !S 0) (weq type 2#10) (weq rmode 2#01) (wgeq opcode 2#110))
	     (cond((weq opcode 2#110)
		   (list 'fmov (regnum-to-regname regd sf nil) (regnum-to-simd-regname3 regn type)))
		  ((weq opcode 2#111)
		   (list 'fmov (regnum-to-simd-regname3 regd type) (regnum-to-regname regn sf nil)))))
	    (t (unknown-instr-error pp)))
      ))

(de decode-dataproc-fp-3source (p1 pp sf !S type)
    (let ((o1 (wand 1 (wshift pp -21)))
	  (o0 (wand 1 (wshift pp -15)))
	  (regd (wand pp 2#11111))
	  (regn (wand (wshift pp -5) 2#11111))
	  (regm (wand (wshift pp -16) 2#11111))
	  (rega (wand (wshift pp -10) 2#11111))
	  (instr))
      (when (or (wneq sf 0) (wneq !S 0)) (unkown-instr-error pp))
      (if (weq o1 0)
	  (setq instr (if (weq o0 0) 'fmadd 'fmsub))
	(setq instr (if (weq o0 0) 'fnmadd 'fnmsub)))
      (list instr (regnum-to-simd-regname2 regd type) (regnum-to-simd-regname2 regn type) (regnum-to-simd-regname2 regm type) (regnum-to-simd-regname2 rega type))
      ))

(de decode-dataproc-fp-2source (p1 pp sf !S type)
    (let ((opcode (wand 2#1111 (wshift pp -12)))
	  (regd (wand pp 2#11111))
	  (regn (wand (wshift pp -5) 2#11111))
	  (regm (wand (wshift pp -16) 2#11111))
	  (instr))
      (setq instr (assoc opcode '((2#0000 fmul) (2#0001 fdiv)
				  (2#0010 fadd) (2#0011 fsub)
				  (2#0010 fmax) (2#0101 fmin)
				  (2#0110 fmaxnm) (2#0111 fminnm)
				  (2#1000 fnmul))))
      (when (or (wneq sf 0) (wneq !S 0) (null instr)) (unkown-instr-error pp))
      (setq instr (cadr instr))
      (list instr (regnum-to-simd-regname2 regd type) (regnum-to-simd-regname2 regn type))
      ))

(de decode-dataproc-fp-1source (p1 pp sf !S type)
    (let ((opcode (wand 2#111111 (wshift pp -15)))
	  (regd (wand pp 2#11111))
	  (regn (wand (wshift pp -5) 2#11111))
	  (instr))
      (case type
	    ((2#00)
	     (setq instr (assoc opcode '((2#000000 fmov)   (2#000001 fabs) (2#000010 rev) (2#000011 fneg) (2#000100 fsqrt)
					 (2#000101 fcvt)   (2#000111 fcvt)
					 (2#001000 frintn) (2#001001 frintp) (2#001010 frintm) (2#001011 frintz)
					 (2#001100 frinta) (2#001110 frintx) (2#001111 frinti)))))
	    ((2#01)
	     (setq instr (assoc opcode '((2#000000 fmov)   (2#000001 fabs) (2#000010 rev) (2#000011 fneg) (2#000100 fsqrt)
					 (2#000100 fcvt)   (2#000111 fcvt)
					 (2#001000 frintn) (2#001001 frintp) (2#001010 frintm) (2#001011 frintz)
					 (2#001100 frinta) (2#001110 frintx) (2#001111 frinti)))))
	    ((2#11)
	     (setq instr (assoc opcode '((2#000100 fcvt)   (2#000101 fcvt))))))
	     

      (when (or (weq sf 1) (weq !S 1) (null instr)) (unknown-instr-error pp))
      (setq instr (cadr instr))
      (if (eq instr 'fcvt)
	  (list instr (regnum-to-simd-regname2 regd (wand opcode 2#11)) (regnum-to-simd-regname2 regn type))
	(list instr  (regnum-to-regname regd sf nil) (regnum-to-regname regn sf nil)))
      ))

(de decode-dataproc-fp-cmp (p1 pp sf !S type)
    (let* ((opcode2 (wand 2#11111 pp))
	   (regm (wand 2#11111) (wshift pp -16))
	   (regn (wand 2#11111) (wshift pp -5))
	   (instr (if (weq 0 (wshift opcode2 -4)) 'fcmp 'fcmpe))
	   (zerotest (wand 1 (wshift opcode2 -3))))
      (when (or (weq sf 1) (weq !S 1)) (unknown-instr-error pp))
      (list instr (regnum-to-simd-regname2 regn type)
	    (if (weq zerotest 1) "#0.0"	(regnum-to-simd-regname2 regm type)))
      ))

(de imm8-to-fp (imm8 type)
    (let ((sign (wand 1 (wshift imm8 -7)))
	  (expo (wand 2#111 (wshift imm8 -4)))
	  (frac (wand 2#1111 )))
      (setq expo (difference expo (wshift 1 (if (weq 2#01 type) 10 7))))
      (if (weq sign 1) (setq frac (wminus frac)))
      (bldmsg "#%w" (times (expt 2.0 (difference expo 16)) frac))
      ))
		 
(de decode-dataproc-fp-imm (p1 pp sf !S type)
    (let ((imm8 (wand 16#ff (wshift pp -13)))
	  (imm5 (wand 2#11111 (wshift pp -5)))
	  (regd (wand 2#11111 pp)))
      (when (or (weq sf 1) (weq !S 1) (wneq 0 imm5)) (unknown-instr-error pp))
      (list 'fmov (regnum-to-simd-regname2 regd type) (imm8-to-fp imm8))
    ))

(de decode-dataproc-fp-cond-cmp (p1 pp sf !S type)
    (let ((cnd (wand 2#1111 (wshift pp -12)))
	  (nzcv (wand 2#1111 pp))
	  (regm (wand 2#11111) (wshift pp -16))
	  (regn (wand 2#11111) (wshift pp -5))
	  (instr (if (weq 0 (wand 1 (wshift pp -4))) 'fccmp 'fccmpe)))
      (when (or (weq sf 1) (weq !S 1) (wgreaterp type 2#01)) (unknown-instr-error pp))
      (list instr (regnum-to-simd-regname2 regn type) (regnum-to-simd-regname2 regm type) (prefix!# nzcv) (decode-cc cnd))
      ))


(de decode-dataproc-fp-cond-select (p1 pp sf !S type)
    (let ((cnd (wand 2#1111 (wshift pp -12)))
	  (regd (wand 2#11111 pp))
	  (regm (wand 2#11111) (wshift pp -16))
	  (regn (wand 2#11111) (wshift pp -5)))
      (when (or (weq sf 1) (weq !S 1) (wgreaterp type 2#01)) (unknown-instr-error pp))
      (list 'fcsel (regnum-to-simd-regname2 regd type) (regnum-to-simd-regname2 regn type) (regnum-to-simd-regname2 regm type) (decode-cc cnd))
      ))

(de decode-dataproc-simd (p1 pp)
    (list 'not-yet-implemented 'decode-dataproc-simd)
    )

%% (ds disassemble-rotate-right (n m)
%%     (lor
%%      (wshift n (wminus m))
%%      (wand 16#ffffffff (wshift n (wdifference 32 m)))))

%% (de decode-imm8 (bits)
%%     (prog (rotate_imm immed_8)
%% 	  (setq rotate_imm (wshift (wand 16#0f (wshift bits -8)) 1))
%% 	  (setq immed_8 (wand bits 16#ff))
%% 	  %% rotate right immed_8 by rotate_imm bits
%% 	  (return (prefix!# (if (weq rotate_imm 0) immed_8 (disassemble-rotate-right immed_8 rotate_imm))))))

%% (setq shiftoplist*
%%       '((2#00 . lsl) (2#01 . lsr) (2#10 . asr) (2#11 . ror)))

%% (de decode-shifter-operand (bits)
%%     (prog (regm shift shift_imm regs instr)
%% 	  (setq regm (regnum-to-regname (wand bits 16#0f)))
%% 	  (setq shift (wand (wshift bits -5) 2#11))
%% 	  (cond ((weq 0 (wand bits 2#10000)) % immediate shift
%% 		 (setq shift_imm (wand (wshift bits -7) 2#11111))
%% 		 (if (and (weq shift_imm 0) (or (weq shift 1) (weq shift 2)))
%% 		     (setq shift_imm 32))
%% 		 (cond ((weq shift_imm 0)
%% 			(if (weq shift 3)
%% 			    (return (bldmsg "%w, rrx" regm))
%% 			  (return regm)))
%% 		       (t
%% 			(return (bldmsg "%w, %w #%d" regm (cdr (assoc shift shiftoplist*)) shift_imm))))
%% 		 )
%% 		(t
%% 		 (setq regs (regnum-to-regname (wand (wshift bits -8) 16#0f)))
%% 		 (return (bldmsg "%w, %w %w" regm (cdr (assoc shift shiftoplist*)) regs))))
%% 	  )
%%     )

%% (setq multiply*
%%       '((2#000000001001 mul     3)
%% 	(2#000000101001 mla     3)
%% 	(2#000001001001 umaal   4)
%% 	(2#000010001001 umull   4)
%% 	(2#000010101001 umlal   4)
%% 	(2#000011001001 smull   4)
%% 	(2#000011101001 smlal   4)
%% 	(2#000101101000 smulbb  3)
%% 	(2#000101101100 smulbt  3)
%% 	(2#000101101010 smultb  3)
%% 	(2#000101101110 smultt  3)
%% 	))

	 
%% (de decode-multiply (p1 pp cc opcode1 opcode2)
%%     (prog (regd regs regm regn set-bit operands instr)
%% 	  (setq set-bit (wand opcode1 1))
%% 	  (setq cc (decode-cc cc))
%% 	  (setq instr (cdr (assoc (wand (wor (wshift (wand opcode1 2#11111110) 4) opcode2) 16#1e) multiply*)))
%% 	  (setq regd (regnum-to-regname (wand (wshift pp -16) 16#0f)))
%% 	  (setq regn (regnum-to-regname (wand (wshift pp -12) 16#0f)))
%% 	  (setq regs (regnum-to-regname (wand (wshift pp -8) 16#0f)))
%% 	  (setq regm (regnum-to-regname (wand 16#0f)))
%% 	  (if (weq 4 (cadr instr))
%% 	      (setq operands (list regd regn regm regs))
%% 	    (setq operands (list regd regm regs)))
%% 	  (setq instr (intern (bldmsg "%w%w%s" (car instr) cc (if set-bit "S" ""))))
%% 	  (return (cons 4 (cons instr operands)))
%% 	  )
%%     )

%% (de decode-halfwordtrans (p1 pp cc opcode1 opcode2)
%%     )

%% (de decode-singledatatrans (p1 pp cc opcode1 opcode2)
%%     (prog (instr regn regd regm i-bit p-bit u-bit b-bit w-bit shift shift_imm offset12)
%% 	  (setq i-bit (weq 2#00100000 (wand 2#00100000 opcode1)))
%% 	  (setq p-bit (wshift (wand 2#00010000 opcode1) -4))
%% 	  (setq u-bit (weq 2#00001000 (wand 2#00001000 opcode1)))
%% 	  (setq b-bit (weq 2#00000100 (wand 2#00000100 opcode1)))
%% 	  (setq w-bit (wshift (wand 2#00000010 opcode1) -1))
%% 	  (setq cc (decode-cc cc))
%% 	  (setq regn (regnum-to-regname (wand (wshift pp -16) 16#0f)))
%% 	  (setq regd (regnum-to-regname (wand (wshift pp -12) 16#0f)))
%% 	  (setq regm (regnum-to-regname (wand pp 16#0f)))
%% 	  (setq instr (intern (bldmsg "%w%w%w" (if (weq (wand opcode1 1) 1) 'ldr 'str) cc (if b-bit "b" ""))))
%% 	  (setq shift (wand (wshift pp -5) 3))
%% 	  (setq shift_imm (wand 16#1f (wshift pp -7)))

%% 	  (cond ((null i-bit)
%% 		 (setq offset12 (wand 16#fff pp))
%% 		 (if (null u-bit) (setq offset12 (wminus offset12)))
%% 		 (case (wor (wshift p-bit 1) w-bit)
%% 		       ((0)		% normal memory access, postindexed
%% 			(return (list 4 instr regd (bldmsg "[%w], #%d" regn offset12)))
%% 			)
%% 		       ((1)		% unprivileged LDRT/STRT -- not handled
%% 			(stderror "Unprivileged LDRT/STRT not handled")
%% 			)
%% 		       ((2)		% offset adressing immediate
%% 			(return (list 4 instr regd
%% 				      (if (weq offset12 0) (bldmsg "[%w]" regn)
%% 					(bldmsg "[%w, #%d]" regn offset12))))
%% 			)
%% 		       ((3)		% offset addressing, preindexed
%% 			(return (list 4 instr regd (bldmsg "[%w, #%d]!" regn offset12)))
%% 			)
%% 		      )
%% 		 )

%% 		%% ((and (weq 0 shift) (weq shift_imm 0)) % Register offset
%% 		%%  (case (wor (wshift p-bit 1) w-bit)
%% 		%%        ((0)		% normal memory access, postindexed
%% 		%% 	(return (list 4 instr regd (bldmsg "[%w], %s%w" regn (if (null u-bit) "-" "") regm)))
%% 		%% 	)
%% 		%%        ((1)		% unprivileged LDRT/STRT -- not handled
%% 		%% 	(stderror "Unprivileged LDRT/STRT not handled")
%% 		%% 	)
%% 		%%        ((2)		% offset adressing immediate
%% 		%% 	(return (list 4 instr regd (bldmsg "[%w, %s%w]" regn (if (null u-bit) "-" "") regm)))
%% 		%% 	)
%% 		%%        ((3)		% offset addressing, preindexed
%% 		%% 	(return (list 4 instr regd (bldmsg "[%w, %s%w]!" regn (if (null u-bit) "-" "") regm)))
%% 		%% 	)
%% 		%%       )
%% 		%%  )

%% 	        (t			% register offset/indexed
%% 		 (if (and (weq shift_imm 0) (or (weq shift 1) (weq shift 2)))
%% 		     (setq shift_imm 32))
%%                  (if (and (weq shift_imm 0) (weq shift 3))
%% 		     (setq shift ", rrx")
%%                    (setq shift (bldmsg ", %w #%d" (cdr (assoc shift shiftoplist*)) shift_imm)))
%% 		 (case (wor (wshift p-bit 1) w-bit)
%% 		       ((0)		% register offset adressing, postindexed
%% 			(return (list 4 instr regd (bldmsg "[%w], %s%w%s" regn (if (null u-bit) "-" "") regm shift)))
%% 			)
%% 		       ((1)		% unprivileged LDRT/STRT -- not handled
%% 			(stderror "Unprivileged LDRT/STRT not handled")
%% 			)
%% 		       ((2)		% register offset adressing
%% 			(return (list 4 instr regd (bldmsg "[%w, %s%w%s]" regn (if (null u-bit) "-" "") regm shift)))
%% 			)
%% 		       ((3)		% register offset addressing, preindexed
%% 			(return (list 4 instr regd (bldmsg "[%w, %s%w%s]!" regn (if (null u-bit) "-" "") regm shift)))
%% 			)
%% 		      )
%% 		 )
%% 	       )
%% 	  )
%%     )

%% (de decode-blockdatatrans (p1 pp cc opcode1 opcode2)
%%     (prog (instr regn reglist l-bit p-bit u-bit s-bit w-bit reglist-bits op)
%% 	  (setq p-bit (wshift (wand 2#00010000 opcode1) -4))
%% 	  (setq u-bit (weq 2#00001000 (wand 2#00001000 opcode1)))
%% 	  (setq s-bit (weq 2#00000100 (wand 2#00000100 opcode1)))
%% 	  (setq w-bit (wshift (wand 2#00000010 opcode1) -1))
%% 	  (setq l-bit (wand 1 opcode1))
%% 	  (setq cc (decode-cc cc))
%% 	  (setq regn (regnum-to-regname (wand (wshift pp -16) 16#0f)))
%% 	  (if (weq w-bit 1) (setq regn (bldmsg "%w!" regn)))
%% 	  (setq op
%% 		(case (wand 3 (wshift pp -23))
%% 		      ((0) 'da)
%% 		      ((1) 'ia)
%% 		      ((2) 'db)
%% 		      ((3) 'ib)
%% 		      ))
%% 	  (setq instr (intern (bldmsg "%w%w%w" (if (weq l-bit 1) 'ldm 'stm) cc op)))
%% 	  (setq reglist-bits (wand pp 16#ffff))
%% 	  (setq reglist "")
%% 	  (for (from i 0 15 1)
%% 	       (do
%% 		(if (weq 1 (wand reglist-bits 1))
%% 		    (setq reglist (bldmsg "%w%s%w" reglist (if (equal reglist "") "{" ",") (regnum-to-regname i))))
%% 		(setq reglist-bits (wshift reglist-bits -1))))
%% 	  (setq reglist (concat reglist "}"))
%% 	  (return (list 4 instr regn reglist))
	  
%% 	  )
%%     )

%% (de decode-load-store-extension (p1 pp cc opcode1 opcode2)
%%         (prog (instr regn regd regm i-bit p-bit u-bit w-bit l-bit specialop op offset)
%% 	  (setq p-bit (wshift (wand 2#00010000 opcode1) -4))
%% 	  (setq u-bit (weq 2#00001000 (wand 2#00001000 opcode1)))
%% 	  (setq i-bit (weq 2#00000100 (wand 2#00000100 opcode1)))
%% 	  (setq w-bit (wshift (wand 2#00000010 opcode1) -1))
%% 	  (setq l-bit (wand opcode1 1))
%% 	  (setq cc (decode-cc cc))
%% 	  (setq regn (regnum-to-regname (wand (wshift pp -16) 16#0f)))
%% 	  (setq regd (regnum-to-regname (wand (wshift pp -12) 16#0f)))
%% 	  (setq regm (regnum-to-regname (wand pp 16#0f)))
%% 	  (setq offset (wor (wand 2#11110000 (wshift pp -4)) (wand 2#00001111 pp)))
%% 	  (setq offset (if i-bit (bldmsg "#%w%w" (if (null u-bit) "-" "") offset)
%% 			 (bldmsg "%w%w" (if (null u-bit) "-" "") regm)))
%% 	  (setq op (wand 2#11 (wshift pp -5)))
%% 	  (case (wor (wshift l-bit 2) op)
%% 		((0) (setq instr (bldmsg "%w%w" (if u-bit 'strex 'swp) cc))
%% 		     (setq specialop (bldsmg "%w, [%w]" regm regn)))
%% 		((1) (setq instr (bldmsg "%w%w%w" 'str cc 'h)))
%% 		((2) (setq instr (bldmsg "%w%w%w" 'ldr cc 'd)))
%% 		((3) (setq instr (bldmsg "%w%w%w" 'str cc 'd)))
%% 		((4) (setq instr (if u-bit (bldmsg "%w%w" 'ldrex cc) (bldmsg "%w%w%w" 'swp cc 'b)))
%% 		     (setq specialop (bldsmg "%w, [%w]" regm regn)))
%% 		((5) (setq instr (bldmsg "%w%w%w" 'ldr cc 'h)))
%% 		((6) (setq instr (bldmsg "%w%w%w" 'ldr cc 'sb)))
%% 		((7) (setq instr (bldmsg "%w%w%w" 'ldr cc 'sh)))
%% 		)
%% 	  (case (wor (wshift p-bit 1) w-bit)
%% 		((0)		% normal memory access, postindexed
%% 		 (return (list 4 instr regd (bldmsg "[%w], %w" regn offset)))
%% 		 )
%% 		((1)		% Unpredictable instruction
%% 		 (stderror "Unpredictable misc. load/store")
%% 		 )
%% 		((2)		% offset adressing immediate
%% 		 (return (list 4 instr regd (or specialop
%% 						(if (weq offset 0) (bldmsg "[%w]" regn)
%% 						  (bldmsg "[%w, %w]" regn offset)))))
%% 		 )
%% 		((3)		% offset addressing, preindexed
%% 		 (return (list 4 instr regd (bldmsg "[%w, %w]!" regn offset)))
%% 		 )
%% 		)
%% 	  ))

%% (de decode-other (p1 pp cc opcode1 opcode2)
%%     )


%% (de decode-special (p1 pp adr)
%%     (printf "decode-special not yet implemented: %x %x %x%n" p1 pp adr))

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
       (return w))
     (when (stringp w) 
       (setq *comment (bldmsg """%w""" w))
       (return 'string))
%     (when (eq (wand w 16#ffffff) 0) (return 'CAR))
%     (when (eq (wand w 16#ffffff) 4) (return 'CDR))
     (return (sys2int w))))

%% (de xgreaterp(a b)(and (numberp a)(numberp b)(greaterp a b)))

(de return-instr-p (instr)
    (eq (car instr) 'ret)
)
    
(de disassemble (fkt)
    (prog(base instr jk jk77 p1 pp lth x return-seen*
	       jmem symvalhigh symfnchigh frame
	       argumentblockhigh labels* label bstart bend breg com4 memp1
	       !*lower lc name)
         (setq !*lower t)
	 (setq *largest-target-addr* 0)

         (cond ((numberp fkt) (setq base fkt))
               ((pairp fkt)
		(setq base (car fkt))
		(setq bend (cadr fkt))
		(plus2 base bend)) %do an arithmetic test
               ((idp fkt)
		(when (not (getd fkt)) (error 99 "not compiled"))
		(when (not (codep (cdr (getd fkt))))(return nil))
		(setq base (sys2int (getfunctionaddress fkt)))
		)     )
         (when (greaterp base (sys2int nextbps)) (return (error 99 "disassemble: start address out of range")))
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
         (setq lth 4)
 next    (setq base (plus2 base lth))
         (when (and !*hardjump fktend (greaterp base fktend))
               (go continue1))
         (cond ((not bend ) (go loop1))
               ((greaterp base bend) (go continue1))
               (t (go loop1)))
 continue1
  % second pass: assign symbolic labels to jump targets
         (when (not bend) (setq bend base))
         (setq labels* (labelsort labels*))
         (mapcar labels*
                (function
                  (lambda(x)
                    (cond
                      ((and       % test within-range
                        (geq (car x) bstart)
                        (leq (car x) bend)
			)
		       (rplacd x (gensym)) )
                      (t (rplaca x nil))
         )      ) ) )
  % third pass: print instructions
erstmal
         (setq base bstart)
         (prinblx (list "function: " fkt " base: " base))
         (terpri)
         (setq lc 0)
loop
         (cond ((assoc base labels*)
                (ttab 19) (prin2 (cdr (assoc base labels*)))
                (setq lc (add1 lc))
                (prin2t ":")))
         (setq p1 (wand 255 (byte(int2sys base) 0)))
%         (print p1)
%         (cond((eq p1 0)(return nil)))

         (setq pp p1)
         (if *big-endian*
	     (for (from i 1 3 1)
		  (do (setq pp (wor (wshift pp 8) (wand 255 (byte (int2sys base) i))))))
	   (progn 
	     (for (from i 1 3 1)
		  (do
		   (setq pp (wor pp (wshift (wand 255 (byte (int2sys base) i)) (times2 i 8))))
		      ))
	     (setq p1 (wand 16#ff (wshift pp -24)))
	     )
	   
	   )
         (cond((eq pp 0)(return nil)))

         (setq *curradr* base *currinst* pp)
         (setq !*comment nil)
         (setq instr (decode p1 pp base))      % instruction
         (if (null instr) (return nil))
         (when (return-instr-p instr)
	   %% The following doesn't work for functions that end with a BR instruction,
	   %% need a more complex logic.
	   (setq return-seen* t)
	   (unless (wgreaterp *largest-target-addr* base)
	     (setq bend base)))
         (setq lth 4)
         (setq name (when instr (pop instr)))

         (ttab 1)
         (prinbnx base 8)
         (prin2 " ")
         (prinbnx (sys2int pp) 8)
         (ttab 20)
         (when name (prin2 name))
         (ttab 28)
	 (when instr
           (while (and (cdr instr) (cadr instr))
	     (prin2 (car instr)) (prin2 ", ")
	     (pop instr))
           (if (pairp instr) (prin2 (car instr)))
           (prin2 "    "))

         (when *comment (ttab 50) (prin2 *comment))
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


