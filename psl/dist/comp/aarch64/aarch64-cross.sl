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

(compiletime (load if-system))

(fluid '(bittable-entries-per-word))

(setq addressingunitsperitem 8)
(setq bittable-entries-per-word 32)
(setq LASTACTUALREG&   8)

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

%% (de codefiletrailer ()
%%   (prog (s)
%%         (systemfaslfixup)
%%         (binarywrite codeout* (idifference (isub1 nextidnumber*) 
%%                                            first-local-id-number))
%%         % Number of local IDs
%%         (foreach x in (car orderedidlist*) do
%%                  (progn (remprop x fasl-idnumber-property*)
%%                         (setq x (strinf (faslid2string x)))
%%                         (setq s (strlen x))
%%                         (binarywrite codeout* s)
%%                         (binarywriteblock codeout* (strbase x)
%%                                           (strpack s))))
%%         (binarywrite codeout* % S is size in words
%%                      (setq s
%%                       (iquotient
%%                        (iplus2 CurrentOffset*
%%                         (isub1 addressingunitsperitem))
%%                        addressingunitsperitem)))
%%         (binarywrite codeout* initoffset*)
%%         (binarywriteblock codeout* CodeBase* s)
%% 	(if *compact-bittable
%%          (let((b (compact-bittable bittablebase* bittableoffset*))
%%               (bpw (quotient bitsperword 8)))
%%            (binarywrite codeout*
%%             (setq s (iquotient
%%                        (iplus2 (car b)
%%                         (isub1 bpw))
%%                        bpw)))
%%            (binarywriteblock codeout* (strbase (strinf (cdr b))) s)
%%          )
%%          (progn
%%           (binarywrite codeout*
%%                      (setq s
%%                       (iquotient
%%                        (iplus2 bittableoffset*
%%                         (isub1 bittable-entries-per-word))
%%                        bittable-entries-per-word)))
%%           (binarywriteblock codeout* bittablebase* s)
%%         ))
%%         (deallocatefaslspaces)))

(compiletime
 (if_system x86_64
   (progn
     (put 'put_a_halfword 'opencode '((movl (reg ebx) (displacement (reg rax) 0))))
     (put 'getword32 'opencode '((movl (indexed (reg 1) (displacement (reg 2) 0)) (reg EAX)))))
   (progn
     (put 'put_a_halfword 'opencode '((STR (reg w1) (displacement (reg x0) 0))))
     (put 'getword32 'opencode '((LDR (reg w0) (indexed (reg 1) (reg 2)) ))))
   ))

%% (de deposit32bitword (x) %% cross
%%   (put_a_halfword (wplus2 codebase* currentoffset*) x)
%%   (updatebittable 4 0)
%%   (setq currentoffset* (plus currentoffset* 4)))

%% (de deposit-relocated-word (offset)
%%   % Given an OFFSET from CODEBASE*, deposit a word containing the
%%   % absolute address of that offset.
%%   (put_a_halfword (wplus2 CodeBase* CurrentOffset*)
%% 	   (iplus2 offset (if *writingfaslfile 0 CodeBase*)))
%%   (updatebittable 4 (const reloc_word))
%%   (setq CurrentOffset* (plus CurrentOffset* 4)))

%% (de depositwordidnumber (x) 
%%   (cond
%%     ((or (not *writingfaslfile) (leq (idinf x) 256)) 
%%      (deposit32bitword (idinf X)))
%%     (t
%%       (put_a_halfword (wplus2 CodeBase* CurrentOffset*)
%% 	       (makerelocword (const reloc_id_number) (findidnumber x))) 
%%       (setq CurrentOffset* (plus CurrentOffset* 4)) 
%%       (updatebittable 4 (const reloc_word)))))

(de DepositQuadWordExpression (x)
  % Only limited expressions now handled
  (let (y)
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
	(depositword (if (null (cadr y)) (int2id 256) (cadr y))))
      ((equal (first x) 'idloc) (depositquadwordidnumber (second x)))
      ((equal (first x) 'mkitem) (DepositItem (second x) (third x)))
      ((equal (first x) 'entry) (DepositEntry x))
      ((memq (first x) '(fluid global $fluid $global)) (DepositValueCellLocation (second x)))
      ((setq y (wconstevaluable x)) (DepositWord (int2sys y)))
      (t (stderror (bldmsg "Expression too complicated %r" x))))
    ))

%% (de depositwordidnumber (x) 
%%   (cond
%%     ((or (not *writingfaslfile) (leq (idinf x) 256)) 
%%      (deposit32bitword (idinf X)))
%%     (t
%%       (put_a_halfword (wplus2 CodeBase* CurrentOffset*)
%% 	       (makerelocword (const reloc_id_number) (findidnumber x))) 
%%       (setq CurrentOffset* (plus CurrentOffset* 4)) 
%%       (updatebittable 4 (const reloc_word)))))

(compiletime (load addr2id))

%% (de findidnumber (u)
%%   (prog (i)
%%         (return (cond ((null u) 256)
%% 		      ((ileq (setq i (idinf u)) 256) i)
%%                       ((setq i (get u fasl-idnumber-property*)) i)
%% 		      ((extraargumentp nextidnumber*)
%% 		       (stderror "Too many identifiers in fasl file"))
%%                       (t (put u 'idnumber (setq i nextidnumber*))
%% 			 (setq orderedidlist* (tconc orderedidlist* u))
%% 			 (setq nextidnumber* (iadd1 nextidnumber*)) i)))))


(de initsymval1 (x)
  (prog (val)
% now decide what to plant in value cell at compiletime.
        (return (dataprintfullword 
                 (cond 
                       ((eq x 'nextsymbol) nextidnumber*)
% print the corresponding symbol for the valuecell with label, and external declaration.
                       ((flagp x 'externalsymbol)
                          (setq val (get x 'symbol))
                          (datadeclareexternal val)
                          val)
% print the corresponding symbol for the valuecell with label, and exported declaration.
                       ((flagp x 'exportedsymbol)
                          (setq val (get x 'symbol))
                          (datadeclareexported val)
                          (dataprintlabel val)
                          (list 'mkitem (compiler-constant 'unbound-tag) 
                            (findidnumber x)))
% print internal references for symnam, symfnc, symval, symprp.
                       ((flagp x 'internalsymbol)
                          (setq val (get x 'symbol))
                          val)
% print the initial value.
                       ((setq val (get x 'initialvalue)) 
                        (compileconstant val))
% print the value of nil.
		       ((eq (id2int x) 256)
			(list 'mkitem (compiler-constant 'id-tag) 256))
% print the value of cross compiler nil
                       ((eq (id2int x) 128)
			(list 'mkitem (compiler-constant 'unbound-tag) 128))
                       ((flagp x 'nilinitialvalue) nilnumber*)
% print the unbound variable value.
                       (t 
                        (list 'mkitem (compiler-constant 'unbound-tag) 
                         (findidnumber x))))))))
(setq nil-t-diff* 140)

