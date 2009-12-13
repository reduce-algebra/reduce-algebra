%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PC: P-LAMBIND.SL
% Title:          Portable cmacro definitions *LAMBIND, *PROGBIND and *FREERSTR
% Author:         Eric Benson
% Created:        6 August 1982
% Modified:       06-Dec-83 10:00 (Brian Beach)
% Status:         Experimental
% Mode:           Lisp
% Package:        Compiler
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
% (c) Copyright 1982, University of Utah
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 06-Dec-83 10:00 (Brian Beach)
%   New header.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%

(compiletime (load useful))

(imports '(syslisp))			% requires SYSLISP for AddrUnitsPerItem

(de *lambind (regs fluids)
  (prog (n firstreg)
    (setq n 0)
    (setq regs (rest regs))		% remove REGISTERS at the front
    (setq fluids (rest fluids))		% remove NONLOCALVARS at the front
    (setq fluids			% convert fluids list into vector
          (list2vector (foreach x in fluids collect (second x))))
    (setq firstreg (first regs))
    (setq regs (rest regs))
    (return (if (null regs)			% only one to bind
        `((*move ,firstreg (reg 2))
	  (*move `,',(getv fluids 0) (reg 1))
	  (*call lbind1))
	`((*move ,firstreg (memory (fluid LambindArgs*) (wconst 0)))
	  (*move (fluid LambindArgs*) ,firstreg)
	  ,@(foreach x in regs collect
	    (progn (setq n (add1 n))
	           `(*move ,x
		     (memory ,firstreg
			     (wconst (wtimes2 (wconst AddressingUnitsPerItem)
					      (wconst ,n)))))))
	  (*move `,',fluids (reg 1))
	  (*call lambind))))))

(defcmacro *lambind)

(de *progbind (fluids)
  (if (null (rest (rest fluids)))
      `((*move `,',(second (first (rest fluids))) (reg 1))
	(*call pbind1))
      `((*move `,',(list2vector (foreach x in (rest fluids) collect
				         (second x)))
	       (reg 1))
	(*call progbind))))

(defcmacro *progbind)

(de *freerstr (fluids)
  `((*move `,',(length (rest fluids)) (reg 1))
    (*call UnBindN)))

(defcmacro *freerstr)

(setq *unsafebinder t)			% has to save registers across calls
