% for kernel: halfword and byte instructions generated in MIT syntax


(deflist '(
         (Byte    ((movb (indexed (reg 2) (displacement (reg 1) 0)) (reg AL))
                   (cbw)
                   (cwde)))
        (PutByte  ((movb (reg CL) (indexed (reg 1) (displacement (reg 2) 0)))))
        (HalfWord ((shl 1 (reg 2))
                    (movw (indexed (reg 2) (displacement (reg 1) 0))(reg AX))
                    (cwde)))
        (PutHalfWord ((shl 1 (reg 2))
                    (movw (reg CX) (indexed (reg 1)(displacement (reg 2) 0))))))
  'OpenCode)

% foreign link for UNIX kernel

(DE  !*ForeignLink (FunctionName  FunctionType NumberOfArguments)
%%%%%(codedeclareexternal FunctionName)
     (append (PNTH '((!*PUSH (REG 14)) (!*PUSH (REG 13))
             (!*PUSH (REG 12)) (!*PUSH (REG 11))
             (!*PUSH (REG 10)) (!*PUSH (REG  9))
             (!*PUSH (REG  8)) (!*PUSH (REG  7))
             (!*PUSH (REG  6)) (!*PUSH (REG  5))
             (!*PUSH (REG  4)) (!*PUSH (REG  3))
             (!*PUSH (REG  2)) (!*PUSH (REG  1)))
           (difference 15  NumberOfArguments))
          (append
           (list (list '!*move '(fluid ebxsave!*) '(reg 2))
                 (list 'call (list 'ForeignEntry FunctionName))
                 (list '!*move '(reg 2) '(fluid ebxsave!*)))
           (cond
        ((eq NumberOfArguments 0) nil)
        ((lessp NumberOfArguments 3)
         (list (list 'add (times 4 NumberOfArguments) '(reg st))))
        (t
         (list (list 'add (times 4 NumberOfArguments) '(reg st))))
        ))
           ))


(de OperandPrintForeignEntry (x)        % (ForeignEntry FcnName)
       (printf "_%w" (cadr x)))
