(load helferlein)
(load armv6-disassemble)
(off usermode)
(on comp)
         (de getfunctionaddress(fkt)
             (wshift(wshift (cdr (getd fkt)) 8) -8))
(off comp)


(load "armv6-lap")
(on echo)
(on backtrace)
(off usermode)
(on testlap)


(de DepositInstructionBytes (byte1 byte2 byte3 byte4)
    (printf "%x %x %x %x%n"
	    (land byte4 16#ff)
	    (land byte3 16#ff)
	    (land byte2 16#ff)
	    (land byte1 16#ff))
        (if *big-endian*
	(progn
	  (depositbyte byte1)
	  (depositbyte byte2)
	  (depositbyte byte3)
	  (depositbyte byte4))
      (progn
	(depositbyte byte4)
	(depositbyte byte3)
	(depositbyte byte2)
	(depositbyte byte1))))
	  
    )

(load addr2id debug)

%(tr  pass1lap  pass1Code onelappass1 addinstruction addcode)
%(tr lapoptframe lapoptpeep ReformBranches OptimizeBranches OptimizeBranches0)
%(tr aligncode buildoffsettable findlongbranches aligncode1)
%(tr instructionlength depositinstruction)
%(tr add!.!L!T!H pm-reg-shifter-p reg-offset12-p imm8-rotatedp reg-shifterp regp)
%(tr ldr!.!I!N!S!T!R)
%(tr OP-ld-st)
%(tr reg2int)

	

(lap '(
       (!*entry testarmv6 expr 0)
      start
       (ldr (reg r0) (displacement (reg r1) 12))
       (ldr (reg r0) (displacement (reg r1) (reg r2)))
       (ldr (reg r0) (displacement (reg r1) (plus (reg r2))))
       (ldr (reg r0) (displacement (reg r1) (minus (reg r2))))
       (ldr (reg r0) (displacement (reg r1) (regshifted r2 LSL 2)))
       (ldr (reg r0) (displacement (reg r1) (plus (regshifted r2 LSL 2))))
       (ldr (reg r0) (displacement (reg r1) (minus (regshifted r2 LSL 2))))
       (ldr (reg r0) (displacement (reg r1) 12 preindexed))
       (ldr (reg r0) (displacement (reg r1) (reg r2) preindexed))
       (ldr (reg r0) (displacement (reg r1) (plus (reg r2)) preindexed))
       (ldr (reg r0) (displacement (reg r1) (minus (reg r2)) preindexed))
       (ldr (reg r0) (displacement (reg r1) (regshifted r2 LSL 2) preindexed))
       (ldr (reg r0) (displacement (reg r1) (plus (regshifted r2 LSL 2)) preindexed))
       (ldr (reg r0) (displacement (reg r1) (minus (regshifted r2 LSL 2)) preindexed))
       (ldr (reg r0) (displacement (reg r1) 12 postindexed))
       (ldr (reg r0) (displacement (reg r1) (reg r2) postindexed))
       (ldr (reg r0) (displacement (reg r1) (plus (reg r2)) postindexed))
       (ldr (reg r0) (displacement (reg r1) (minus (reg r2)) postindexed))
       (ldr (reg r0) (displacement (reg r1) (regshifted r2 LSL 2) postindexed))
       (ldr (reg r0) (displacement (reg r1) (plus (regshifted r2 LSL 2)) postindexed))
       (ldr (reg r0) (displacement (reg r1) (minus (regshifted r2 LSL 2)) postindexed))
       (str (reg t1) (displacement (reg SYMFNC) (regshifted 1 LSL 2)))
       (strd (reg r0) (indirect (reg sp)))
       (strd (reg r0) (displacement (reg r1) 12)) 
       (ldrd (reg r0) (displacement (reg r1) (reg r2)))
       (ldrd (reg r0) (displacement (reg r1) (plus (reg r2))))
       (ldrd (reg r0) (displacement (reg r1) (minus (reg r2))))
       (ldrd (reg r0) (displacement (reg r1) 12 preindexed))
       (ldrd (reg r0) (displacement (reg r1) (reg r2) preindexed))
       (ldrd (reg r0) (displacement (reg r1) (plus (reg r2)) preindexed))
       (ldrd (reg r0) (displacement (reg r1) (minus (reg r2)) preindexed))
       (ldrd (reg r0) (displacement (reg r1) 12 postindexed))
       (ldrd (reg r0) (displacement (reg r1) (reg r2) postindexed))
       (ldrd (reg r0) (displacement (reg r1) (plus (reg r2)) postindexed))
       (ldrd (reg r0) (displacement (reg r1) (minus (reg r2)) postindexed))

       (ldrh (reg r0) (displacement (reg r1) (reg r2)))
       (ldrsb (reg r0) (displacement (reg r1) (reg r2)))
       (ldrsh (reg r0) (displacement (reg r1) (reg r2)))


       (ldm (reg sp) ((reg 1) (reg 2) (reg pc)) writeback)
       (ldmfd (reg sp) ((reg 1) (reg 2) (reg pc)) writeback)
       (ldmfa (reg sp) ((reg 1) (reg 2) (reg pc)) writeback)
       (ldmed (reg sp) ((reg 1) (reg 2) (reg pc)) writeback)
       (ldmea (reg sp) ((reg 1) (reg 2) (reg pc)) writeback)

       (stm (reg sp) ((reg 1) (reg 2) (reg pc)) writeback)
       (stmfd (reg sp) ((reg 1) (reg 2) (reg pc)) writeback)
       (stmfa (reg sp) ((reg 1) (reg 2) (reg pc)) writeback)
       (stmed (reg sp) ((reg 1) (reg 2) (reg pc)) writeback)
       (stmea (reg sp) ((reg 1) (reg 2) (reg pc)) writeback)

%       (B 132)
%       (B -144)

       (str (reg fp) (displacement (reg sp) -4 preindexed))
       (add (reg fp) (reg sp) 0)
       (sub (reg sp) (reg sp) 12)
       (str (reg r0) (displacement (reg fp) -8))
       (ldr (reg r3) (displacement (reg fp) -8))

       (sdiv (reg r0) (reg r1) (reg r2))
       (sdiv (reg r2) (reg r3) (reg r2))
       (udiv (reg r0) (reg r1) (reg r2))
       (mul (reg r0) (reg r1) (reg r2))
       (mul (reg r2) (reg r1) (reg r2))

       (mov (reg r0) (reg r3))
       (add (reg sp) (reg fp) 0)
       (ldr (reg fp) (displacement (reg sp) 4 postindexed))
       ende
       (bx (reg lr))
))

(dumpo 16#14164C4 5)
%(tr decode decode-shifter-operand)
(disassemble 'testarmv6)
t
(rds nil)
