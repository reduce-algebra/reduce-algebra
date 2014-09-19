%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXU:MULS.SL
% Description:  support for BIGNUM package with double INUM operations
%               lap source for MIPS processor
% Author:       H. Melenk, W. Neun
% Created:      25 January 1989
% Modified:
% Mode:         Lisp
% Package:      Utilities
% Status:       Experimental
%
% (c) Copyright 1989, Konrad-Zuse-Zentrum, all rights reserved.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% IBM RS 6000 version by W. Neun, ZIB Berlin
%
%  this file is needed compiletime only
%
% Double length multiply and divide for the 68020 processor.
% These are the open codes which embed the extended arithmetic 
% operations such that they are accessible from compiled LISP top level.
% They map the 2*30 bit operations needed by BIG to the 2*32 bit operations
% of the processor by shifting etc.
(fluid '(*second-value*))
 
(bothtimes
(put 'wdivide 'opencode
		'((divs (reg 1) (reg 1) (reg 2))
                  (mfspr (reg 3) (reg mq))
		  (*move (reg 3) ($fluid *second-value*))))
)

(put 'wtimesdouble 'opencode
     % Called with two parameters of maximum bbase size
     % the return value are the low order bits of the product.
     % The high order bits are placed in fluid variable.
     '(% double length unsigned mutiply;
       (MUL (reg 3) (reg 1) (reg 2))
       (Mfspr (reg 1) (reg mq))
       (*WSHIFT (reg 3) 2)
       (*MOVE (reg 1) (reg 2))
       (*WSHIFT (reg 2) -30)
       (*WOR (reg 3)(reg 2))
       (*MOVE (reg 3)($FLUID *second-value*))
       (*WSHIFT (reg 1) 2)
       (*WSHIFT (reg 1) -2) ))
 

(put 'wxtimes2 'opencode % different version for $pxu/mbarith
     '((MUL (reg 4) (reg 1) (reg 2))
      (Mfspr (reg 1) (reg mq))
      (*move (reg 4) ($FLUID *second-value*))))


(put 'wquotientdouble 'opencode
      % called with a double length number in params 1 and 2
      % and a single length number in par 3.
      % Result is the single length quotient.
      % the remainder is placed in a fluid variable.
      '(  % adjusting the words first
        (*MOVE (reg 1) (reg 4))
        (*WSHIFT (reg 1) -2)
        (*WSHIFT (reg 4) 30)
        (*WOR (reg 2) (reg 4))
        (mtspr (reg mq) (reg 2))
          % now we can divide and spread the results
        (DIV (reg 1) (reg 1) (reg 3))
        (mfspr (reg 2) (reg mq))
        (*MOVE (reg 2) ($FLUID *second-value*))))

(fluid '(*second-value*))

(put 'addcarry 'opencode
       '((*MOVE ($FLUID carry*) (reg 2))
         (*WPLUS2 (reg 1)(reg 2))
         (sriq (reg 3) (reg 1) 30)
         (*MOVE (reg 3) ($FLUID carry*))
         (*WSHIFT (reg 1) 2)
         (*WSHIFT (reg 1) -2)))

(put 'subcarry 'opencode
       '((*MOVE ($FLUID carry*) (reg 2))
         (*WDIFFERENCE (reg 1)(reg 2))
         %(*MOVE (reg 1) (reg 2))
         %(*WSHIFT (reg 2) -31)
         (sriq (reg 2) (reg 1) 31)
         (*MOVE (reg 2) ($FLUID carry*))
         (*WSHIFT (reg 2) 30)
         (*WPLUS2 (reg 1) (reg 2))
       ))
         

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%   functions supporting word arithmetic with bbase*
%   bbase* is too large to be stored in a fluid cell;
%   so we perform operations with bbase* by shift and mask
%   instructions.
 
%   get the value for bbase* into a register
(put 'bbase** 'opencode
%     '((*MOVE 1 (reg 1))
%       (*WSHIFT (reg 1) 30)))
      '((cau (reg 1) (reg 0) 16#4000 )))
 
%   get the value for logicalbits* into a register     
(put 'logicalbits** 'opencode
      '((*MOVE -1 (reg 1))
        (*WSHIFT (reg 1) -2)))

%   calculate (remainder x bbase*)
(put 'remainder-bbase 'opencode
      '((*WSHIFT (reg 1) 2)
        (*WSHIFT (reg 1) -2)))

%   calculate (quotient x bbase*)
(put 'quotient-bbase 'opencode
      '((*WSHIFT (reg 1) -30)))

(put 'bbase** 'destroys '((reg 1))) 
(put 'logicalbits** 'destroys '((reg 1)))  
(put 'remainder-bbase 'destroys '((reg 1)))  
(put 'quotient-bbase 'destroys '((reg 1)))  


