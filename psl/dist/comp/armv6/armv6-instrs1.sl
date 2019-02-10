%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PXC:armv6-instrs1.sl
% Title:          Instructions for ARM v6
% Author:         Winfried Neun
% Created:        April 21 2014
% Status:         Open Source: BSD License
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
     
(compiletime (load backquote))

%(fluid '(*OpNameList*))

(CompileTime
 (progn 

%(setq *OpNameList* nil)
   
(dm DefOpcode (U) 
%
% (DefOpcode name (parameters) pattern)
%
(prog (OpName variants vars pattern fname condbits set!? opname-string) 
    (setq U (rest U)) 
    (setq OpName (pop U))
    (setq opname-string (string OpName))
    (setq fname (intern (bldmsg "%w.INSTR" OpName)))
    (setq OpName (MkQuote OpName))
%    (setq variants (pop u))
    (setq vars (pop u))
    (setq pattern
      (append u
	`((t (laperr ',OpName  (list .,vars))))))
    (setq pattern (cons 'cond pattern))
    %% (setq pattern
    %% 	  `((lambda (*condbits* *set* *ldm-addr*) ,pattern)
    %% 	    (get (or ,(car variants) 'AL) 'condition-bits)
    %% 	    ,(if (cdr variants)
    %% 		 `(if ,(cadr variants) 1 0)
    %% 	       )
    %% 	    ,(if (and (cdr variants) (cddr variants))
    %% 		 `(get (or ,(caddr variants) 'IA) 'ldm-addressing-modes))
    %% 	    ))
    % (setq u `(lambda ,vars ,pattern)) 
    % (return `(put ,OpName 'InstructionDepositMacro ',u))
%    (push opname-string *OpNameList*)
    (return
      `(progn
	 (de ,fname ,vars ,pattern)
%	 (put ,OpName 'variants ',variants)
	 (put ,OpName 'InstructionDepositMacro ',fname)))
    ))



(dm DefOpLength (U)
%
% (DefOpLength name (parameters) pattern)
%
(prog (OpName variants vars pattern fname)
    (setq U (rest U))
    (setq OpName (pop U))   % (quote name)
    (setq fname (intern (bldmsg "%w.LTH" OpName)))
    (setq OpName (MkQuote OpName))   % (quote name)
%    (setq variants (pop u)) 
    (setq vars (pop u)) 
    (setq pattern
      (append u 
	`((t (laperr ',OpName  (list .,vars))))))  
    (setq pattern (cons 'cond pattern)) 
    % (setq u `(lambda ,vars ,pattern))
    % (return `(put ,OpName 'InstructionLengthFunction ',u))
    (return 
      `(progn
	 (de ,fname ,vars ,pattern) 
	 (put ,OpName 'InstructionLengthFunction ',fname))) 
)) 
))
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
%
%    getting the instructions in 
  
( dskin "armv6-inst1.dat")
