#! /bin/bash -v

./vsl -i Macfasl.img <<XXX | tee try-fasl.log

(setq *echo t)

% This seems to be called at cross-compile time with NIL as the
% second argument. That seems a bit weird to me.

(de mkitem (tag x)
  (cond
    ((null (fixp tag)) (mkitem 0 x))
    ((null (fixp x)) (mkitem tag 0))
    (t (land 16#ffffffffffffffff (lor
         (lsh tag 56)
         (land x 16#00ffffffffffffff))))))

'(trace '(mkitem lap))
% (trace '(putbyte))
'(trace '(puthalfword putword wputv labeloffset depositlabel))
'(trace '(modR/M sibbyte-for-indexed depositextension lthmodR/M
         lth-sibbyte-for-indexed reg2int bytep halfwordp unimmediate
         lth-reg-5-prefix OP-mem-eax OP-reg-effa LTH-reg-effa
         OP-im-effa lth-imm8-effa OP-reg-effa-2 OP_xmmreg-effa
         OP2-EFFA OP-imm-EAX OP-INT OP-imm-reg OP-imm8-reg
         OP-byte OP_HUMP_SHORT OP-JUMP-EFFA saniere-Sprungziel
         OP-RET-n OP-enter OP-imm op-shift op-shiftimm op-dshift
         op-dshiftimm OP-MUL OP-IMUL DepositFluid
         DepositExtraReg DepositEntry depositforeignentry
         MakeExpressionRelative reformBranches BuildInitCodeOffsetTable
         BuildOffsetTable InstructionLength
         ))

'(trace '(Pass1Lap LapoptFrame LapoptPeep ReformBranches OptimizeBranches
         DepositLabel SaveEntry DepositInstruction DefineEntries MkCODE))

'(trace '(jmp!.!L!T!H jmp!.!I!N!S!T!R jmpl apply2safe
         shortlabelp op-jump-short indirectadrp op-jump-effa adrp)) 

(setq *plap t)
(setq *pgwd t)
(setq *testlap t)

(faslout 'foo)
(de bar (x) "hello")
(faslend)

XXX

