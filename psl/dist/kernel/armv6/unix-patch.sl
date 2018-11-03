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

% for kernel: halfword and byte instructions generated in MIT syntax


(deflist '(
         (Byte    ((*wor  (reg 1) 16#8000000)
		(movb (indexed (reg 2) (displacement (reg 1) 0)) (reg AL))
                   (cbw)
                   (cwde)))
        (PutByte  ((*wor  (reg 1) 16#8000000)
		   (movb (reg CL) (indexed (reg 1) (displacement (reg 2) 0)))))
        (HalfWord ((shl 1 (reg 2))
		    (*wor  (reg 1) 16#8000000)
                    (movw (indexed (reg 2) (displacement (reg 1) 0))(reg AX))
                    (cwde)))
        (PutHalfWord ((shl 1 (reg 2))
		    (*wor  (reg 1) 16#8000000)
                    (movw (reg CX) (indexed (reg 1)(displacement (reg 2) 0))))))
  'OpenCode)

% foreign link for UNIX kernel

(DE  !*ForeigxxxxnLink (FunctionName  FunctionType NumberOfArguments)
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
       (printf "%w" (cadr x)))
