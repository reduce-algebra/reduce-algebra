%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXC:aarch64-cross.sl
% Description:  Aarch64 patches for 64bit cross compiler
% Author:       R. Schöpf
% Created:      January 2021
% Modified:
% Mode:         Lisp
% Package:      
% Status:       Open Source: BSD License
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% This file contains redefinitions of compiler internals for 64/32 bit cross
% compilation.
%
% The PSL compiler running on a 64 bit architecture operates on 64 bit words
% internally. In order to generate code for a 32bit architecture, some
% operations on memory words must be modified. 
%
% In particular:
%  * shift/mask operations
%  * storing memory words 
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(bittable-entries-per-word))

(setq addressingunitsperitem 8)
(setq bittable-entries-per-word 32)

(compiletime
 (load fasl-decls fast-vector)
)

(fluid '(*writingfaslfile
         *lower
         *quiet_faslout
         dfprint*
         uncompiledexpressions*
         modulename*
         codeout*
         initoffset*
         CurrentOffset*
         faslblockend*
         maxfasloffset*
         bittableoffset*
         faslfilenameformat*
         fasl-idnumber-property*
         CodeBase*
         ForwardInternalReferences*
         ))

(de codefiletrailer ()
  (prog (s)
        (systemfaslfixup)
        (binarywrite codeout* (idifference (isub1 nextidnumber*) 
                                           first-local-id-number))
        % Number of local IDs
        (foreach x in (car orderedidlist*) do
                 (progn (remprop x fasl-idnumber-property*)
                        (setq x (strinf (faslid2string x)))
                        (setq s (strlen x))
                        (binarywrite codeout* s)
                        (binarywriteblock codeout* (strbase x)
                                          (strpack s))))
        (binarywrite codeout* % S is size in words
                     (setq s
                      (iquotient
                       (iplus2 CurrentOffset*
                        (isub1 addressingunitsperitem))
                       addressingunitsperitem)))
        (printf "code size is %d/%x%n" s s)
        (printf "initoffset is %d/%x%n" initoffset* initoffset*)
        (binarywrite codeout* initoffset*)
        (binarywriteblock codeout* CodeBase* s)
	(if *compact-bittable
         (let((b (compact-bittable bittablebase* bittableoffset*))
              (bpw (quotient bitsperword 8)))
           (binarywrite codeout*
            (setq s (iquotient
                       (iplus2 (car b)
                        (isub1 bpw))
                       bpw)))
           (binarywriteblock codeout* (strbase (strinf (cdr b))) s)
         )
         (progn
          (binarywrite codeout*
                     (setq s
                      (iquotient
                       (iplus2 bittableoffset*
                        (isub1 bittable-entries-per-word))
                       bittable-entries-per-word)))
          (binarywriteblock codeout* bittablebase* s)
        ))
        (printf "bittable size is %d/%x%n" s s)
        (binarywriteblock codeout* bittablebase* s)
        (deallocatefaslspaces)))

(compiletime
 (put 'put_a_halfword 'opencode
      '(
        (movl (reg ebx) (displacement (reg rax) 0)))))

(de deposit32bitword (x) %% cross
  (put_a_halfword (wplus2 codebase* currentoffset*) x)
  (updatebittable 4 0)
  (setq currentoffset* (plus currentoffset* 4)))

(de deposit-relocated-word (offset)
  % Given an OFFSET from CODEBASE*, deposit a word containing the
  % absolute address of that offset.
  (put_a_halfword (wplus2 CodeBase* CurrentOffset*)
	   (iplus2 offset (if *writingfaslfile 0 CodeBase*)))
  (updatebittable 4 (const reloc_word))
  (setq CurrentOffset* (plus CurrentOffset* 4)))

(de depositwordidnumber (x) 
  (cond
    ((or (not *writingfaslfile) (leq (idinf x) 256)) 
     (deposit32bitword (idinf X)))
    (t
      (put_a_halfword (wplus2 CodeBase* CurrentOffset*)
	       (makerelocword (const reloc_id_number) (findidnumber x))) 
      (setq CurrentOffset* (plus CurrentOffset* 4)) 
      (updatebittable 4 (const reloc_word)))))



(de DepositQuadWordExpression (x)
  % Only limited expressions now handled
  (let (y)
%    (printf "Deposit %w at %x -> %x%n" x CurrentOffset* (wplus2 CodeBase* CurrentOffset*))
    (cond
      ((fixp x) (depositword (int2sys x)))
      ((labelp x) (deposit-relocated-word (LabelOffset x)))
      ((equal (first x) 'internalentry) 
       (let ((offset (get (second x) 'internalentryoffset)))
	 (if offset
	     (deposit-relocated-word offset)
	     (progn
	       (setq ForwardInternalReferences*
		     (cons (cons CurrentOffset* (second x))
			   ForwardInternalReferences*))
	       (deposit-relocated-word 0)))))
      ((and (eq (car x) 'mkitem)
	    (eq (cadr x) id-tag)
	    (eqcar (setq y (caddr x)) 'idloc)
	    (wlessp (id2int (cadr y)) 257))
	(depositword (cadr y)))
      ((equal (first x) 'idloc) (depositquadwordidnumber (second x)))
      ((equal (first x) 'mkitem) (DepositItem (second x) (third x)))
      ((equal (first x) 'entry) (DepositEntry x))
      ((memq (first x) '(fluid global $fluid $global)) (DepositValueCellLocation (second x)))
      ((setq y (wconstevaluable x)) (DepositWord (int2sys y)))
      (t (stderror (bldmsg "Expression too complicated %r" x))))
%    (printf "Deposited at %x: %x >%x< %x%n"
%	    (wplus2 (wplus2 CodeBase* CurrentOffset*) -4)
%	    (getword32 (wplus2 (wplus2 CodeBase* CurrentOffset*) -8) 0)
%	    (getword32 (wplus2 (wplus2 CodeBase* CurrentOffset*) -4) 0)
%	    (getword32 (wplus2 CodeBase* CurrentOffset*) 0)
%	    )
    ))

(de depositwordidnumber (x) 
  (cond
    ((or (not *writingfaslfile) (leq (idinf x) 256)) 
     (deposit32bitword (idinf X)))
    (t
      (put_a_halfword (wplus2 CodeBase* CurrentOffset*)
	       (makerelocword (const reloc_id_number) (findidnumber x))) 
      (setq CurrentOffset* (plus CurrentOffset* 4)) 
      (updatebittable 4 (const reloc_word)))))


(compiletime (load addr2id))


(de systemfaslfixup ()
  (prog (x wrd)
%     (printf "%nForwardInternalReferences: %w%n" ForwardInternalReferences*)
     % THIS VERSION ASSUMES 32 bit RELATIVE ADDESSES, HM.
     (setq x (remainder CurrentOffset* 16))
     (while (greaterp x 0) (DepositByte 0) (setq x (sub1 x)))
     (while ForwardInternalReferences*
       (setq x (get (cdr (first ForwardInternalReferences*)) 
		    'internalentryoffset))
       (when (null x) 
	      (errorprintf "***** %r not defined in this module, call incorrect" 
			   (cdr (first ForwardInternalReferences*))))
       % calculate the offset
       % offset is actual offset -8
       (setq x (plus -8             % offset of PC in branch instruction
		     (difference x (car (first ForwardInternalReferences*)))))
%       (printf "Offset is %d%n" x)
       (setq x (wshift x -2))		% offset is in words, not bytes
       % insert the fixup into the lower 24 bits, upper 8 bits are condition bits and opcode
       (setq wrd (wgetv (iplus2 CodeBase* (car (first ForwardInternalReferences*))) 0))
%       (printf "instruction is %x --> %x%n"
%	       (wand wrd 16#ffffffff)
%	       (wor (wand wrd 16#ff000000) (wand x 16#00ffffff)))
       (put_a_halfword (iplus2 CodeBase* (car (first ForwardInternalReferences*))) x)
%       (printf "New instruction is %x%n" (wand (wgetv (iplus2 CodeBase* (car (first ForwardInternalReferences*))) 0) 16#ffffffff))
       (setq ForwardInternalReferences* (cdr ForwardInternalReferences*)))
	      % Now remove the InternalEntry offsets from everyone
   (mapobl 'remove-ieo-property)))

(de findidnumber (u)
  (prog (i)
        (return (cond ((null u) 256)
		      ((ileq (setq i (idinf u)) 256) i)
                      ((setq i (get u fasl-idnumber-property*)) i)
                      (t
		       (if (extraargumentp nextidnumber*)
			   (stderror "Too many identifiers is fasl file")
			 (progn
			   (put u fasl-idnumber-property* (setq i nextidnumber*))
			   (setq orderedidlist* (tconc orderedidlist* u))
			   (setq nextidnumber* (iadd1 nextidnumber*)) i)))))))


(setq nil-t-diff* 140)

%(remprop '*get-stack 'opencode)
%(remprop '*put-stack 'opencode)

%(remprop 'wconst 'anyregresolutionfunction)
%(remprop 'wconst 'anyregpatterntable)

%(remprop 'cons 'opencode)
