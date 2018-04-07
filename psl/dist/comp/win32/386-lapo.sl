%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXC:386-LAPO.SL
% Description:  Lap Code optimizers
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

(compiletime (load if-system))
(compiletime (progn (load useful) (on fast-integers)))

(fluid '(!*lapopt !*trlapopt))
 
%---------------------------------------------------------------------
%  cmacro optimizer
%---------------------------------------------------------------------

(de lapopt1 (u)
    (prog()
	(when (not *lapopt) (return u))
	(setq u (lapopt-move-special-cases u))
	(return u)))

%  Move bodies of if-then-elseif ... sequences  such that at runtime as few
%  jumps as possible are taken.

(fluid '(&cond-cm&))

(setq &cond-cm& 
 '((*jumpeq      . *jumpnoteq)       (*jumpnoteq      . *jumpeq)
   (*jumpwgeq    . *jumpwlessp)      (*jumpwlessp     . *jumpwgeq)
   (*jumpwleq    . *jumpwgreaterp)   (*jumpwgreaterp  . *jumpwleq)
   (*jumptype    . *jumpnottype)     (*jumpnottype    . *jumptype)
   (*jumpintype  . *jumpnotintype)   (*jumpnotintypte . *jumpintype)
   (*jumpeqtag   . *jumpnoteqtag)    (*jumpnoteqtag   . *jumpeqtag)
   (*jumpwgeqtag . *jumpwlessptag)   (*jumpwlessptag  . *jumpwgeqtag)
  % no inverse jumps for
   (*jumpwgreaterptag)
   (*jumpon)
   
))

(de lapopt-move-special-cases(code)
  (let (rcode bcode inst u w lbl lab)
   (while (not (lapopt-bottom code))
    (setq inst (pop code))
     (when 
      (and
       (pairp inst)
       (setq u (atsoc (car inst) &cond-cm&))
       (setq u (cdr u))
       (setq lbl (cadr inst))
       (or (memq lbl code)(member (setq lbl (list '*lbl lbl)) code))
       (setq w (lapopt-move-special-cases1 code lbl))
      )
      (setq lab (list 'label (gensym)))
      (setq bcode (nconc bcode (cons (list '*lbl lab) (car w))))
      (push (cons u (cons lab (cddr inst))) rcode)
      (setq inst nil)
      (setq code (cdr w))
     )
     (when inst (push inst rcode))
    )
  (setq code (nconc (reversip rcode) (nconc bcode code)))
  (when *trlapopt 
	 (prin2t "=== move special cases:")
	 (MAPCAR code 'PRINT))
  code    
)) 

(de lapopt-bottom(u)
 (or (null u) 
     (eqcar (car u) 'fullword)))

(de lapopt-move-special-cases1 (code lbl)
  % Find basic block until lbl which ends by an unconditional jump.
  % Return nil or pair of bblock and rest of code.
  (let (rcode fcode inst op)
   (while code
     (setq inst (pop code))
     (push inst rcode)
     (cond ((or (atom inst) (equal inst lbl)) (setq code nil))
	   ((and (memq (setq op (car inst)) 
		      '(*jump *linke *exit))
		 (cdr code)
		 (equal (car code) lbl)
	    )
	    (setq fcode code) (setq code nil))
	   ((or (eq op '*lbl) (atsoc op &cond-cm&))
	    (setq code nil)
	   )
   ))
   (when fcode (cons (reversip rcode) fcode))
))

%---------------------------------------------------------------------
%  instruction optimizer
%---------------------------------------------------------------------

(de lapopt2 (u)
    (prog()
	(when (not *lapopt) (return u))
     (when (or (eq *lapopt t)
		  (and (numberp *lapopt)
		       (not (izerop (wand *lapopt 4)))))
	      (setq u (lapoptreformloads u)))
	(return u)))
     
(setq !*lapopt t)

(when (null (getd 'myLapoptFrame))
      (copyd 'myLapoptFrame 'LapoptFrame))

(de LapoptFrame(u)(lapopt2 (myLapoptFrame u)))

%%----------------------------------------------------------------- 
 
%----------------------------------------------------------------------
 
(fluid '(jumps*))
 
(setq jumps* '(ja jae jael jb jbe jbel jcxz je jecxz jel
	       jg jge jgel jgl jl jle jlel jll jmp jmpl 
	       jna jnae jnael jnal jnb jnbe jnbel jnbl
	       jne jnel jng jnge jngel jngl jnl
	       jnle jnlel jnll jno jnol jnp jnpl jnps
	       jns jnsl jnsz jnzl jo jol jp jpe
	       jpel jpl jpo jpol js jsl jz jzl
	       call *entry ret))

(ds target(x)(and (pairp x) (pairp (cdr x)) (pairp (cddr x)) (caddr x)))

(de LapOptReformLoads (code)
  (let (rcode rrcode inst0 inst2 x y z inst1)
    (while code
      (setq inst0 (pop code))
      (when *trlapopt (print inst0))
      (when (and (pairp inst0) 
	       rcode 
	       (isaload? (setq inst1 (car rcode)))
	       (member (target inst1) (operands inst0)))
	    (cond((and % previous instruction available?
		    (cdr rcode) 
		    (pairp (setq inst2 (cadr rcode)))
		    (not (isaload? inst2))
		    (not (isastore? inst2))
		    (not (isajump? inst2))
			% independent?
		    (not (member (target inst1) (operands inst2)))
		    (not (member (target inst2) (operands inst1)))
		  )
		  (prin2 "`")
		  (melde (list inst2 inst1 inst0) (list inst1 inst2 inst0))
		  (setq x (pop rcode)) (setq y (pop rcode))
		  (push x rcode) (push y rcode))
		 ((and % next instruction available?
		     code
		    (pairp (setq inst2 (car code)))
		    (not (isaload? inst2))
		    (not (isastore? inst2))
		    (not (isajump? inst2))
			% independent?
		    (not (member (target inst0) (operands inst2)))
		    (not (member (target inst2) (operands inst0)))
		  )
		  (prin2 "'")
		  (melde (list inst1 inst0 inst2)(list inst1 inst2 inst0))
		  (setq x (pop code))
		  (push inst0 code)
		  (setq inst0 x))))

	(push inst0 rcode))

      (setq rcode (reversip rcode)) 
      (when *trlapopt
	    (terpri)(prin2t "   lapopt ====> ")
	    (foreach x in rcode do (print x)))
      rcode
  ))

(de melde(a b)
   (prin2t "ersetzen:")
   (foreach p in (pair a b) do
      (progn (prin2t (car p)) (tab 20)(prin2t (cdr p)) )))
 

(de isaload?(inst1)
	 (and (eqcar inst1 'MOV)
	      (pairp (cadr inst1))
	      (memq (caadr inst1)  
		    '(displacement indirect $fluid fluid global $global))))

(de isastore?(inst1)
       (or
	 (eqcar inst1 'PUSH)
	 (and (eqcar inst1 'MOV)
	      (pairp (caddr inst1))
	      (memq (caaddr inst1)
		    '(displacement indirect $fluid fluid global $global)))))

(de isajump?(inst1) (memq (car inst1) jumps*))

(de operands (x)         %simplified form , only looking for regs
   % extract the operands from x
   (cond ((atom x) nil)
	 ((or (memq (car x) '(reg))) (list x))
	 ((memq (car x) '(displacement indexed indirect))
	  (operands (cdr x)))
	 (t (nconc (operands (car x)) (operands (cdr x))))))


