%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:  pxu/disassemble.sl -  disassembler for armv6
%
% Author: Rainer Sch�pf
%
% Date :  10-Aug-2018
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
		*largest-target-addr*))

          (de getwrd(a)(getmem a))

          (de getfunctionaddress(fkt) 
             (wshift(wshift (cdr (getd fkt)) 5) -5))

          (de idnumberp(x)
           (cond ((not (posintp x)) nil)
                 ((greaterp x (lshift maxsymbols 1)) nil)
                 ((stringp (symnam x)) x)
                 (t nil)))

          (de safe!-int2id(x)
            (setq x (wand 16#f7ffffff x))
            (if (idnumberp x) (mkid x) (mkid 32)))

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


(dm make-the-instructions(u)
  `(progn
     (setq instrs1 ',instrs1)
     (setq instrs2 ',instrs2)
     (setq instrs3 ',instrs3)
     ))

))

(make-the-instructions)




(fluid '( the-instruction* addr* cclist* reglist* dataproc* shiftoplist* multiply*))

(setq cclist*
      '((2#0000 EQ) (2#0001 NE) (2#0010 CS) (2#0011 CC)
	(2#0100 MI) (2#0101 PL) (2#0110 VS) (2#0111 VC)
	(2#1000 HI) (2#1001 LS) (2#1010 GE) (2#1011 LT)
	(2#1100 GT) (2#1101 LE) (2#1110 "")))

(setq dataproc*
      '((2#00000000 AND) (2#00100000 AND)
	(2#00000010 EOR)	(2#00100010 EOR)
	(2#00000100 SUB) (2#00100100 SUB)
	(2#00000110 RSB) (2#00100110 RSB)
	(2#00001000 ADD) (2#00101000 ADD)
	(2#00001010 ADC) (2#00101010 ADC)
	(2#00001100 SBC) (2#00101100 SBC)
	(2#00001110 RSC) (2#00101110 RSC)
	(2#00010000 TST) (2#00110000 TST)
	(2#00010010 TEQ) (2#00110010 TEQ)
	(2#00010100 CMP) (2#00110100 CMP)
	(2#00010110 CMN) (2#00110110 CMN)
	(2#00011000 ORR) (2#00111000 ORR)
	(2#00011010 MOV) (2#00111010 MOV)
	(2#00011100 BIC) (2#00111100 BIC)
	(2#00011110 MVN) (2#00111110 MVN)
	))

      
(de decode-cc (cc)
    (let ((cctext (assoc cc cclist*)))
      (and cctext (cadr cctext))))

(de regnum-to-regname (n)
    (cond ((equal n 11) "fp")
	  ((equal n 13) "sp")
	  ((equal n 14) "lr")
	  ((equal n 15) "pc")
	  (t (intern (bldmsg "r%d" n)))))

(de decode (p1 pp addr*)
  (prog(i lth cc opcode1 opcode2 name)
      (setq lth 4)
      (setq cc (wand 16#0f (wshift pp -28)))
      (if (weq cc 16#0f)
	  (return (decode-special p1 pp addr*)))
      (setq opcode1 (wand 16#ff (wshift pp -20)))
      (setq opcode2 (wand 16#0f (wshift pp -4)))
      %% big branch for various instruction types
      (cond ((and (weq opcode1 2#00010010) (weq (wand opcode2 2#1101) 2#0001)
		  (weq (wand 16#fff (wshift pp -8)) 16#fff))
	     (return (decode-branchx p1 pp cc opcode1 opcode2)))
	    ((and (weq (wand 2#11000000 opcode1) 2#00000000)
		  %% check for instruction from extension space: bit[25] == 0 and bit[4] == 1 and bit[7] == 1
		  (not (weq (wand 16#02000090 pp) 16#90)))
	     (return (decode-dataproc p1 pp cc opcode1 opcode2)))
	    ((and (weq (wand 2#11110000 opcode1) 0) (weq opcode2 2#1001))
	     (return (decode-multiply p1 pp cc opcode1 opcode2)))
	    ((and (weq (wand 2#11100000 opcode1) 0) (weq (wand opcode2 9) 2#1001))
	     (return (decode-load-store-extension p1 pp cc opcode1 opcode2)))
	    ((weq (wand 2#11111011 opcode1) 2#00010000)
	     (return (decode-data-swap p1 pp cc opcode1 opcode2)))
	    ((weq (wand opcode1 2#11100000) 0)
	     (return (decode-halfwordtrans p1 pp cc opcode1 opcode2)))
	    ((weq (wand opcode1 2#11000000) 2#01000000)
	     (return (decode-singledatatrans p1 pp cc opcode1 opcode2)))
	    ((weq (wand opcode1 2#11100000) 2#10000000)
	     (return (decode-blockdatatrans p1 pp cc opcode1 opcode2)))
	    ((weq (wand opcode1 2#11100000) 2#10100000)
	     (return (decode-branch p1 pp cc opcode1 opcode2)))
	    ((weq (wand opcode1 2#11100000) 2#11000000)
	     (return (decode-other p1 pp cc opcode1 opcode2)))
	    (t
	     (stderror (bldmsg "Unknown armv6 instruction %x" pp)))
	    )))

(de decode-branch (p1 pp cc opcode1 opcode2)
    (prog (instr offset targetaddr)
	  (setq instr (if (weq 0 (wand p1 1)) 'b 'bl))
	  (setq instr (intern (bldmsg "%w%w" instr (decode-cc cc))))
	  (setq offset (wand 16#00ffffff pp))
	  %% sign-extend the 24-bit value to 30 bit
	  (if (wgreaterp offset 16#007fffff)
	      (setq offset (wor 16#3f000000 offset)))
	  (setq offset (wshift offset 2))
	  (setq targetaddr (wplus2 8 (wplus2 *curradr* offset)))
	  (if (wgreaterp targetaddr *largest-target-addr*)
	      (setq *largest-target-addr* targetaddr))
	  (return (list 4 instr (bldmsg "0x%x" targetaddr)))))
	  
(de decode-branchx (p1 pp cc opcode1 opcode2)
    % first check that the bit pattern is <cc nibble> 0x12fff <three bits> 2#10000
    % be careful to not use constants with more than 27 bits!
    (if (not (and (weq (wand 16#fffff (wshift pp -8)) 16#012fff)
		  (wand 16#d0 pp) 16#10))
	(stderror (bldmsg "Unknown armv6 instruction %x" pp)))
    (list 4
	  (if (weq opcode2 3) 'blx 'bx)
	  (regnum-to-regname (wand pp 16#0f))))

(de decode-dataproc (p1 pp cc opcode1 opcode2)
    (prog (instr regn regd operand2 set-bit immediate?)
	  (setq immediate? (weq 2#00100000 (wand 2#00100000 opcode1)))
	  (setq set-bit (weq (wand opcode1 1) 1))
	  (setq cc (decode-cc cc))
	  (setq instr (cadr (assoc (wand opcode1 16#fe) dataproc*)))
	  (if immediate?
	      (setq operand2 (decode-imm8 (wand 16#ffffff pp)))
	    (setq operand2 (decode-shifter-operand (wand 16#ffffff pp))))
	  (setq regn (regnum-to-regname (wand (wshift pp -16) 16#0f)))
	  (setq regd (regnum-to-regname (wand (wshift pp -12) 16#0f)))
	  (cond ((memq instr '(MOV MVN))
		 (setq operand2 (bldmsg "%w, %w" regd operand2)))
		((memq instr '(CMP CMN TST TEQ))
		 (setq operand2 (bldmsg "%w, %w" regn operand2)))
		(t
		 (setq operand2 (bldmsg "%w, %w, %w" regd regn operand2))))
	  (setq instr (intern (bldmsg "%w%w%s" instr cc (if (and set-bit (not (memq instr '(CMP CMN TST TEQ)))) "s" ""))))
	  (return (list 4 instr operand2))))

(ds disassemble-rotate-right (n m)
    (lor
     (wshift n (wminus m))
     (wand 16#ffffffff (wshift n (wdifference 32 m)))))

(de decode-imm8 (bits)
    (prog (rotate_imm immed_8)
	  (setq rotate_imm (wshift (wand 16#0f (wshift bits -8)) 1))
	  (setq immed_8 (wand bits 16#ff))
	  %% rotate right immed_8 by rotate_imm bits
	  (return (bldmsg "#%d" (if (weq rotate_imm 0) immed_8 (disassemble-rotate-right immed_8 rotate_imm))))))

(setq shiftoplist*
      '((2#00 . lsl) (2#01 . lsr) (2#10 . asr) (2#11 . ror)))

(de decode-shifter-operand (bits)
    (prog (regm shift shift_imm regs instr)
	  (setq regm (regnum-to-regname (wand bits 16#0f)))
	  (setq shift (wand (wshift bits -5) 2#11))
	  (cond ((weq 0 (wand bits 2#10000)) % immediate shift
		 (setq shift_imm (wand (wshift bits -7) 2#11111))
		 (if (and (weq shift_imm 0) (or (weq shift 1) (weq shift 2)))
		     (setq shift_imm 32))
		 (cond ((weq shift_imm 0)
			(if (weq shift 3)
			    (return (bldmsg "%w, rrx" regm))
			  (return regm)))
		       (t
			(return (bldmsg "%w, %w #%d" regm (cdr (assoc shift shiftoplist*)) shift_imm))))
		 )
		(t
		 (setq regs (regnum-to-regname (wand (wshift bits -8) 16#0f)))
		 (return (bldmsg "%w, %w %w" regm (cdr (assoc shift shiftoplist*)) regs))))
	  )
    )

(setq multiply*
      '((2#000000001001 mul     3)
	(2#000000101001 mla     3)
	(2#000001001001 umaal   4)
	(2#000010001001 umull   4)
	(2#000010101001 umlal   4)
	(2#000011001001 smull   4)
	(2#000011101001 smlal   4)
	(2#000101101000 smulbb  3)
	(2#000101101100 smulbt  3)
	(2#000101101010 smultb  3)
	(2#000101101110 smultt  3)
	))

	 
(de decode-multiply (p1 pp cc opcode1 opcode2)
    (prog (regd regs regm regn set-bit operands instr)
	  (setq set-bit (wand opcode1 1))
	  (setq cc (decode-cc cc))
	  (setq instr (cdr (assoc (wand (wor (wshift (wand opcode1 2#11111110) 4) opcode2) 16#1e) multiply*)))
	  (setq regd (regnum-to-regname (wand (wshift pp -16) 16#0f)))
	  (setq regn (regnum-to-regname (wand (wshift pp -12) 16#0f)))
	  (setq regs (regnum-to-regname (wand (wshift pp -8) 16#0f)))
	  (setq regm (regnum-to-regname (wand 16#0f)))
	  (if (weq 4 (cadr instr))
	      (setq operands (list regd regn regm regs))
	    (setq operands (list regd regm regs)))
	  (setq instr (intern (bldmsg "%w%w%s" (car instr) cc (if set-bit "S" ""))))
	  (return (cons 4 (cons instr operands)))
	  )
    )

(de decode-halfwordtrans (p1 pp cc opcode1 opcode2)
    )

(de decode-singledatatrans (p1 pp cc opcode1 opcode2)
    (prog (instr regn regd regm i-bit p-bit u-bit b-bit w-bit shift shift_imm offset12)
	  (setq i-bit (weq 2#00100000 (wand 2#00100000 opcode1)))
	  (setq p-bit (wshift (wand 2#00010000 opcode1) -4))
	  (setq u-bit (weq 2#00001000 (wand 2#00001000 opcode1)))
	  (setq b-bit (weq 2#00000100 (wand 2#00000100 opcode1)))
	  (setq w-bit (wshift (wand 2#00000010 opcode1) -1))
	  (setq cc (decode-cc cc))
	  (setq regn (regnum-to-regname (wand (wshift pp -16) 16#0f)))
	  (setq regd (regnum-to-regname (wand (wshift pp -12) 16#0f)))
	  (setq regm (regnum-to-regname (wand pp 16#0f)))
	  (setq instr (intern (bldmsg "%w%w%w" (if (weq (wand opcode1 1) 1) 'ldr 'str) cc (if b-bit "b" ""))))
	  (setq shift (wand (wshift pp -5) 3))
	  (setq shift_imm (wand 16#1f (wshift pp -7)))

	  (cond ((null i-bit)
		 (setq offset12 (wand 16#fff pp))
		 (if (null u-bit) (setq offset12 (wminus offset12)))
		 (case (wor (wshift p-bit 1) w-bit)
		       ((0)		% normal memory access, postindexed
			(return (list 4 instr regd (bldmsg "[%w], #%d" regn offset12)))
			)
		       ((1)		% unprivileged LDRT/STRT -- not handled
			(stderror "Unprivileged LDRT/STRT not handled")
			)
		       ((2)		% offset adressing immediate
			(return (list 4 instr regd
				      (if (weq offset12 0) (bldmsg "[%w]" regn)
					(bldmsg "[%w, #%d]" regn offset12))))
			)
		       ((3)		% offset addressing, preindexed
			(return (list 4 instr regd (bldmsg "[%w, #%d]!" regn offset12)))
			)
		      )
		 )

		%% ((and (weq 0 shift) (weq shift_imm 0)) % Register offset
		%%  (case (wor (wshift p-bit 1) w-bit)
		%%        ((0)		% normal memory access, postindexed
		%% 	(return (list 4 instr regd (bldmsg "[%w], %s%w" regn (if (null u-bit) "-" "") regm)))
		%% 	)
		%%        ((1)		% unprivileged LDRT/STRT -- not handled
		%% 	(stderror "Unprivileged LDRT/STRT not handled")
		%% 	)
		%%        ((2)		% offset adressing immediate
		%% 	(return (list 4 instr regd (bldmsg "[%w, %s%w]" regn (if (null u-bit) "-" "") regm)))
		%% 	)
		%%        ((3)		% offset addressing, preindexed
		%% 	(return (list 4 instr regd (bldmsg "[%w, %s%w]!" regn (if (null u-bit) "-" "") regm)))
		%% 	)
		%%       )
		%%  )

	        (t			% register offset/indexed
		 (if (and (weq shift_imm 0) (or (weq shift 1) (weq shift 2)))
		     (setq shift_imm 32))
                 (if (and (weq shift_imm 0) (weq shift 3))
		     (setq shift ", rrx")
                   (setq shift (bldmsg ", %w #%d" (cdr (assoc shift shiftoplist*)) shift_imm)))
		 (case (wor (wshift p-bit 1) w-bit)
		       ((0)		% register offset adressing, postindexed
			(return (list 4 instr regd (bldmsg "[%w], %s%w%s" regn (if (null u-bit) "-" "") regm shift)))
			)
		       ((1)		% unprivileged LDRT/STRT -- not handled
			(stderror "Unprivileged LDRT/STRT not handled")
			)
		       ((2)		% register offset adressing
			(return (list 4 instr regd (bldmsg "[%w, %s%w%s]" regn (if (null u-bit) "-" "") regm shift)))
			)
		       ((3)		% register offset addressing, preindexed
			(return (list 4 instr regd (bldmsg "[%w, %s%w%s]!" regn (if (null u-bit) "-" "") regm shift)))
			)
		      )
		 )
	       )
	  )
    )

(de decode-blockdatatrans (p1 pp cc opcode1 opcode2)
    (prog (instr regn reglist l-bit p-bit u-bit s-bit w-bit reglist-bits op)
	  (setq p-bit (wshift (wand 2#00010000 opcode1) -4))
	  (setq u-bit (weq 2#00001000 (wand 2#00001000 opcode1)))
	  (setq s-bit (weq 2#00000100 (wand 2#00000100 opcode1)))
	  (setq w-bit (wshift (wand 2#00000010 opcode1) -1))
	  (setq l-bit (wand 1 opcode1))
	  (setq cc (decode-cc cc))
	  (setq regn (regnum-to-regname (wand (wshift pp -16) 16#0f)))
	  (if (weq w-bit 1) (setq regn (bldmsg "%w!" regn)))
	  (setq op
		(case (wand 3 (wshift pp -23))
		      ((0) 'da)
		      ((1) 'ia)
		      ((2) 'db)
		      ((3) 'ib)
		      ))
	  (setq instr (intern (bldmsg "%w%w%w" (if (weq l-bit 1) 'ldm 'stm) cc op)))
	  (setq reglist-bits (wand pp 16#ffff))
	  (setq reglist "")
	  (for (from i 0 15 1)
	       (do
		(if (weq 1 (wand reglist-bits 1))
		    (setq reglist (bldmsg "%w%s%w" reglist (if (equal reglist "") "{" ",") (regnum-to-regname i))))
		(setq reglist-bits (wshift reglist-bits -1))))
	  (setq reglist (concat reglist "}"))
	  (return (list 4 instr regn reglist))
	  
	  )
    )

(de decode-load-store-extension (p1 pp cc opcode1 opcode2)
        (prog (instr regn regd regm i-bit p-bit u-bit w-bit l-bit specialop op offset)
	  (setq p-bit (wshift (wand 2#00010000 opcode1) -4))
	  (setq u-bit (weq 2#00001000 (wand 2#00001000 opcode1)))
	  (setq i-bit (weq 2#00000100 (wand 2#00000100 opcode1)))
	  (setq w-bit (wshift (wand 2#00000010 opcode1) -1))
	  (setq l-bit (wand opcode1 1))
	  (setq cc (decode-cc cc))
	  (setq regn (regnum-to-regname (wand (wshift pp -16) 16#0f)))
	  (setq regd (regnum-to-regname (wand (wshift pp -12) 16#0f)))
	  (setq regm (regnum-to-regname (wand pp 16#0f)))
	  (setq offset (wor (wand 2#11110000 (wshift pp -4)) (wand 2#00001111 pp)))
	  (setq offset (if i-bit (bldmsg "#%w%w" (if (null u-bit) "-" "") offset)
			 (bldmsg "%w%w" (if (null u-bit) "-" "") regm)))
	  (setq op (wand 2#11 (wshift pp -5)))
	  (case (wor (wshift l-bit 2) op)
		((0) (setq instr (bldmsg "%w%w" (if u-bit 'strex 'swp) cc))
		     (setq specialop (bldsmg "%w, [%w]" regm regn)))
		((1) (setq instr (bldmsg "%w%w%w" 'str cc 'h)))
		((2) (setq instr (bldmsg "%w%w%w" 'ldr cc 'd)))
		((3) (setq instr (bldmsg "%w%w%w" 'str cc 'd)))
		((4) (setq instr (if u-bit (bldmsg "%w%w" 'ldrex cc) (bldmsg "%w%w%w" 'swp cc 'b)))
		     (setq specialop (bldsmg "%w, [%w]" regm regn)))
		((5) (setq instr (bldmsg "%w%w%w" 'ldr cc 'h)))
		((6) (setq instr (bldmsg "%w%w%w" 'ldr cc 'sb)))
		((7) (setq instr (bldmsg "%w%w%w" 'ldr cc 'sh)))
		)
	  (case (wor (wshift p-bit 1) w-bit)
		((0)		% normal memory access, postindexed
		 (return (list 4 instr regd (bldmsg "[%w], %w" regn offset)))
		 )
		((1)		% Unpredictable instruction
		 (stderror "Unpredictable misc. load/store")
		 )
		((2)		% offset adressing immediate
		 (return (list 4 instr regd (or specialop
						(if (weq offset 0) (bldmsg "[%w]" regn)
						  (bldmsg "[%w, %w]" regn offset)))))
		 )
		((3)		% offset addressing, preindexed
		 (return (list 4 instr regd (bldmsg "[%w, %w]!" regn offset)))
		 )
		)
	  ))

(de decode-other (p1 pp cc opcode1 opcode2)
    )


(de decode-special (p1 pp adr)
    (printf "decode-special not yet implemented: %x %x %x%n" p1 pp adr))

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

(de xgreaterp(a b)(and (numberp a)(numberp b)(greaterp a b)))

(de return-instr-p (instr)
    (or (and (memq (car instr) '(bx blx)) (eq (cadr instr) 'lr))
	(and (eq (car instr) 'ldmia) (string-search "pc" (caddr instr)))))
    
(de disassemble (fkt)
    (prog(base instr jk jk77 p1 pp lth x
	       symvalhigh symfnchigh frame
	       argumentblockhigh labels label bstart bend breg com4 memp1
	       !*lower lc name)
         (setq !*lower t)
	 (setq *largest-target-addr* 0)

         (cond ((numberp fkt) (setq base fkt))
               ((pairp fkt) (setq base (car fkt))
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
         (setq lth (atsoc 'LTH instr))
         (setq lth (if lth (cdr lth) 2))
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
	 (when (and (return-instr-p (cdr instr)) (not (wgreaterp *largest-target-addr* base)))
	   (setq bend base))
         (setq lth (pop instr))
         (setq name (when instr (pop instr)))

         (ttab 1)
         (prinbnx base 8)
         (prin2 " ")
         (prinbnx (sys2int pp) 8)
         (ttab 20)
         (when name (prin2 name))
         (ttab 28)
         (while (cdr instr)
	   (prin2 (car instr)) (prin2 ", ")
	   (pop instr))
         (if (pairp instr) (prin2 (car instr)))
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


