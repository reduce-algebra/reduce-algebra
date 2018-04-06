%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PK:FOREIGN.SL
% Package:      
% Status:       Open Source: BSD License
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


(DE  !*ForeignLink (FunctionName  FunctionType NumberOfArguments)
   (let (u)  
     (codedeclareexternal FunctionName)
     (setq u
	(cond ((eq NumberOfArguments 0) nil)
	      ((leq NumberOfArguments 1) 
	       '(
		 (push (reg eax))
		)
	      )   
	      ((eq NumberOfArguments 2)
	       '(
		 (push (reg ebx))
		 (push (reg eax))
		)
	      ) 
	      ((eq NumberOfArguments 3)
	       '(
		 (push (reg ecx))
		 (push (reg ebx))
		 (push (reg eax))
		)
	      ) 
	      ((eq NumberOfArguments 4)
	       '(
		 (push (reg edx))
		 (push (reg ecx))
		 (push (reg ebx))
		 (push (reg eax))
		)
	      ) 

	      (t (stderror "more than 4 parameters for external function")) 
	      ))
	(append u 
	    (list 
	       (list 'call (list 'ForeignEntry FunctionName))
	       (list 'add (times NumberOfArguments 4) '(reg esp))
	       ))
)) 


(de operandprintforeignentry(x)
  (let*((x (cadr x))
	(*lower t)
	(y (get x 'symbol)))
     (printf "%w" (if y y x))))

(setq ExternalDeclarationFormat* "EXTRN %w:NEAR%n")

(de datadeclareexternal (x)
 (let ((*lower t)) 
  (unless (or (member x dataexternals*) (member x dataexporteds*))
    (setq dataexternals* (cons x dataexternals*))
    (when (get x 'symbol)(setq x (get x 'symbol)))
    (dataprintf externaldeclarationformat* x x))))

(de codedeclareexternal (x)
 (let ((*lower t))
  (unless (or (member x codeexternals*) (member x codeexporteds*))
    (setq codeexternals* (cons x codeexternals*))
    (when (get x 'symbol)(setq x (get x 'symbol)))
    (codeprintf externaldeclarationformat* x x))))
