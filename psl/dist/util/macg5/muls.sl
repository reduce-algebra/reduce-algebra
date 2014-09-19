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
% Mac G4 version by W. Neun, ZIB Berlin
%
%  this file is needed compiletime only
%
% Double length multiply and divide for the 68020 processor.
% These are the open codes which embed the extended arithmetic 
% operations such that they are accessible from compiled LISP top level.
% They map the 2*30 bit operations needed by BIG to the 2*32 bit operations
% of the processor by shifting etc.

(compiletime (load inum))

(fluid '(*second-value*))
 
(bothtimes
(put 'wdivide 'opencode
		'((divd (reg 3) (reg 1) (reg 2))
                  (mulld (reg 4) (reg 3) (reg 2))
                  (subf  (reg 4) (reg 4) (reg 1))
		  (*move (reg 3) (reg 1))
		  (*move (reg 4) ($fluid *second-value*))))
)

(put 'wtimesdouble 'opencode
     % Called with two parameters of maximum bbase size
     % the return value are the low order bits of the product.
     % The high order bits are placed in fluid variable.
     '(% double length unsigned mutiply;
       (mulhd (reg 3) (reg 1) (reg 2))
       (mulld (reg 1) (reg 1) (reg 2))
       (*WSHIFT (reg 3) 2)
       (*MOVE (reg 1) (reg 2))
       (*WSHIFT (reg 2) -62)
       (*WOR (reg 3)(reg 2))
       (*MOVE (reg 3)($FLUID *second-value*))
       (*WSHIFT (reg 1) 2)
       (*WSHIFT (reg 1) -2) ))
 

(put 'wxtimes2 'opencode % different version for $pxu/mbarith
     '((MULhd (reg 4) (reg 1) (reg 2))
       (mulld (reg 1) (reg 1) (reg 2))
      (*move (reg 4) ($FLUID *second-value*))))


(de wquotientdouble (arg1 arg2 arg3)
                                                                                
   (prog (quot rem carrybit i)
                                                                                
             % first divide the uper 30 bits by divisor and put the
             % quotient into the result and continue with the remainder
                                                                                
     (setq quot (wdivide arg1 arg3))
     (setq rem *second-value*)
                                                                                
     (setq arg2 (wshift arg2 2))  %initial shift
                                                                                
     (ifor (from i 0 61 1) (do
                                                                                
            % now shift the remainder left by 1 and add the most significant
            % bit of arg2. shift arg2 left one bit
            % if sum is greater or equal divisor, add a bit '1' to remainder
            % else add a '0'.
            % do it until arg2 is eaten up. quot is the result (quotient),
            %          rem is the remainder (in *second-value*)
                                                                                
            (progn
             (setq quot (wshift quot 1))
             (setq carrybit (wshift arg2 -63))
             (setq arg2 (wshift arg2 1))
             (setq rem (wplus2 (wshift rem 1) carrybit))
             (when (wgeq rem arg3) (setq rem (wdifference rem arg3))
                                   (setq quot (wplus2 quot 1)))
      )     )              )
     (setq *second-value* rem)
     (return quot)))
)

(commentoutcode
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
       %% (DIV (reg 1) (reg 1) (reg 3))
        (mfspr (reg 2) (reg mq))
        (*MOVE (reg 2) ($FLUID *second-value*)))))

(fluid '(*second-value*))

(put 'addcarry 'opencode
       '((*MOVE ($FLUID carry*) (reg 2))
         (*WPLUS2 (reg 1)(reg 2))
         (rldicl (reg 3) (reg 1) 2 62)
         (*MOVE (reg 3) ($FLUID carry*))
         (*WSHIFT (reg 1) 2)
         (*WSHIFT (reg 1) -2)))

(put 'subcarry 'opencode
       '((*MOVE ($FLUID carry*) (reg 2))
         (*WDIFFERENCE (reg 1)(reg 2))
         %(*MOVE (reg 1) (reg 2))
         %(*WSHIFT (reg 2) -31)
         (rldicl (reg 2) (reg 1) 1 63)
         (*MOVE (reg 2) ($FLUID carry*))
         (*WSHIFT (reg 2) 62)
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
     '((*MOVE 1 (reg 1))
       (*WSHIFT (reg 1) 62)))
 
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
      '((*WSHIFT (reg 1) -62)))

(put 'bbase** 'destroys '((reg 1))) 
(put 'logicalbits** 'destroys '((reg 1)))  
(put 'remainder-bbase 'destroys '((reg 1)))  
(put 'quotient-bbase 'destroys '((reg 1)))  


