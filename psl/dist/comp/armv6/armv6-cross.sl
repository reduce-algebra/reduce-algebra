<%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXC:armv6-cross.sl
% Description:  Armv6 patches for 64bit cross compiler
% Author:       R. Schöpf
% Created:      December 2018
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

(setq addressingunitsperitem 4)
(setq bittable-entries-per-word 16)

(de binarywrite (channel n)
  (putw n channel))
 
(de binarywriteblock (channel blockbase blocksize)
  (fwrite blockbase 4 blocksize channel))

(compiletime
 (load fasl-decls fast-vector)
)

(ds MyStrPack (upperbound) 
  % Returns the number of items required to store a string, including
  % the one-item header.  Note that indexing starts at zero, and all
  % strings have a trailing zero byte.  Thus, a string with an upper
  % bound of 3 will require 5 bytes of storage past the header.
  (wquotient (wplus2 upperbound
                     (wplus2 4 1)
                     )
             4
             ))

(fluid '(*writingfaslfile
         *lower
         *quiet_faslout
         dfprint*
         uncompiledexpressions*
         modulename*
         codeout*
         initoffset*
         currentoffset*
         faslblockend*
         maxfasloffset*
         bittableoffset*
         faslfilenameformat*
         fasl-idnumber-property*
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
                                          (mystrpack s))))
        (binarywrite codeout* % S is size in words
                     (setq s
                      (iquotient
                       (iplus2 currentoffset*
                        (isub1 4))
                       4)))
        (printf "code size is %d/%x%n" s s)
        (printf "initoffset is %d/%x%n" initoffset* initoffset*)
        (binarywrite codeout* initoffset*)
        (binarywriteblock codeout* codebase* s)
	(if *compact-bittable
         (let((b (compact-bittable bittablebase* bittableoffset*))
              (bpw (quotient 32 8)))
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
                        (isub1 16))
                       16)))
          (binarywriteblock codeout* bittablebase* s)
        ))
        (printf "bittable size is %d/%x%n" s s)
        (binarywriteblock codeout* bittablebase* s)
        (deallocatefaslspaces)))

(compiletime
 (put 'putword32 'opencode
      '(
	(movl (reg ebx) (displacement (reg rax) 0)))))

(de DepositWord (x)
  (putword32 (wplus2 codebase* CurrentOffset*) x)
  (updatebittable 4 0)
  (setq CurrentOffset* (plus CurrentOffset* 4)))

(de deposit-relocated-word (offset)
  % Given an OFFSET from CODEBASE*, deposit a word containing the
  % absolute address of that offset.
  (putword32 (wplus2 codebase* CurrentOffset*)
	   (iplus2 offset (if *writingfaslfile 0 codebase*)))
  (updatebittable 4 (const reloc_word))
  (setq CurrentOffset* (plus CurrentOffset* 4)))
  
(de depositwordidnumber (x) 
  (cond
    ((or (not *writingfaslfile) (leq (idinf x) 256)) 
     (depositword (idinf X)))
    (t
      (putword32 (wplus2 codebase* CurrentOffset*)
	       (makerelocword (const reloc_id_number) (findidnumber x))) 
      (setq CurrentOffset* (plus CurrentOffset* 4)) 
      (updatebittable 4 (const reloc_word)))))

(compiletime
(DefCMacro *MyMkItem
     ((fixp regp)   (shl 37 ArgTwo)
                    (shr 37 ArgTwo)
                    (*move ArgOne (reg 1))
                    (shl 59 (reg 1))
		    (shr 32 (reg 1))
                    (*wor (Reg 1) ArgTwo))
     ((regp regp)   (shl 37 ArgTwo)
                    (shr 37 ArgTwo)
                    (shl 59 ArgOne)
		    (shr 32 ArgOne)
                    (*wor Argone Argtwo))
     ((anyp regp)   (*move ArgOne (reg t1))             
                    (*MyMkItem (reg t1) ArgTwo))
     (              (*move argTwo (reg t1))
                    (*mymkitem ArgOne (reg t1))
                    (*move (reg t1) argtwo)))
)

(compiletime (load addr2id))

(compiletime
(de *MyMkItem (Arg1 Arg2)
  (Expand2OperandCMacro Arg1 Arg2 '*MyMkItem))
)

(de makerelocword (reloctag relocinf)
  (iplus2 (ilsh reloctag 30) (ilsh (ilsh relocinf 2) -2)))

(de makerelocinf (reloctag relocinf)
  (iplus2 (ilsh reloctag 22) (field relocinf 42 22)))

(de makerelochalfword (reloctag relocinf)
  (iplus2 (ilsh reloctag 14) (field relocinf 18 14)))


(compiletime
 (put 'MyMkItem 'openfn '(nonassocpat *MyMkItem))
 )

(de xMyMkItem (x y) (MyMkItem x y))

(de DepositItem (TagPart InfPart) 
    (cond ((not *WritingFaslFile) 
	   (DepositWord 
	       (MyMkItem TagPart 
		       (cond ((LabelP InfPart) 
			      (wPlus2 CodeBase* (LabelOffset InfPart))) 
			     ((equal (first InfPart) 'IDLoc) 
			      (IDInf (second InfPart))) 
			     (t 
				(StdError 
				    (BldMsg "Unknown inf in MkItem %r"
					    InfPart)))))))
	  (t 
	     (progn (cond 
		     ((LabelP InfPart)      % RELOC_CODE_OFFSET = 0
		      (putword32 (wPlus2 CodeBase* CurrentOffset*)
		       (xMyMkItem TagPart (LabelOffset InfPart)))) 
		     ((equal (first InfPart) 'IDLoc) 
		      (putword32 (wPlus2 CodeBase* CurrentOffset*)
		       (xMyMkItem TagPart 
			(MakeRelocInf (const RELOC_ID_NUMBER) 
			  (FindIDNumber (second InfPart))))))
		     (t 
		      (StdError (BldMsg "Unknown inf in MkItem %r"
				 InfPart))))
	      (setq CurrentOffset* (plus CurrentOffset* 4))
	      (UpdateBitTable 4 (const RELOC_INF))))))

(de systemfaslfixup ()
  (prog (x)
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
       (setq x (plus -4             % offset to next word
	     (difference x (car (first ForwardInternalReferences*)))))
			 % insert the fixup
       (putword32 (iplus2 codebase* (car (first ForwardInternalReferences*))) x)
       (setq ForwardInternalReferences* (cdr ForwardInternalReferences*)))
	      % Now remove the InternalEntry offsets from everyone
   (mapobl 'remove-ieo-property)))

(setq nil-t-diff* 140)

