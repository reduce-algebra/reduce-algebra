%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PXC:armv6-instrs.sl
% Title:          Instructions for ARM v6
% Author:         Winfried Neun
% Created:        April 21 2014
% Status:         Experimental
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
     
(compiletime (load fasl-decls common))

(global '(*writingasmfile))

(fluid '(labeloffsets!* currentoffset* codesize* codebase* entries*
	 forwardinternalreferences* lapreturnvalue*  *writingfaslfile
	 initoffset* *pgwd *pwrds label-alist*))

%%|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
%k
%%      Assembler code generator
%%
%%|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

(compiletime 
(dm def-inst (u)
 (prog (name length result)
  (setq u (cdr u)) 
%  (setq name (intern (bldmsg "IBMRS-%w" (first u))))
  (setq name (first u))
  (setq length (second u))
  (push (list 'put (mkquote name) (mkquote '*op-length*) length) result)
  (setq u (cddr u))    
  (setq result
     (append (mapcar u (function 
	 (lambda (x) (list 'put (mkquote name)
		                (mkquote (car x)) (mkquote (cdr x))))))
	result))
  (return(cons 'progn result))))
)

%%      Pseudo-Instructions

(def-inst  *ENTRY 0 (*apply* entry-gen))
%
%       (*ENTRY name type argn)
%
(de entry-gen (instruction name type argn)
  (saveentry (list instruction name type argn)))

%
%       (WORD value ......)
%
(def-inst WORD      4 (*apply* expand-word))
(def-inst FullWORD  4 (*apply* expand-word))
(def-inst STRING    0 (*apply* expand-string))
		            %will be treated by onelaplength
(def-inst Float     8 (*apply* expand-float))

(de expand-word (in x)        (store-word-expression x))

(de expand-string (in x)
	(for (from i 0 (size x))
	     (do (setf (byte (wplus2 codebase* currentoffset*) i) (indx x i))))
	(setf (byte (wplus2 codebase* currentoffset*) (wplus2 (size x) 1)) 0)
	(setq currentoffset* 
		(wplus2 (wtimes2 (strpack (size x))
				 addressingunitsperitem)
		 currentoffset*)))

(de expand-float (in x)         (store-double x ))

%%    The Instruction processor

(de depositinstruction (in)
   (prog (name format spec oldcurrent lng oldbto last)
 
      (setq oldcurrent currentoffset*)
      (when *writingfaslfile (setq oldbto bittableoffset*))
      (when (atom in) (return nil)) % skip labels
      (setq name (first in))
      (setq last (lastcar in))
      (setq lng (cond ((eq name 'string) (wtimes2 addressingunitsperitem
						(strpack (size (second in))) ))
		      (t (get name '*op-length*))))

      (when *writingfaslfile (updatebittable lng 0) % clear bittable 
		             (setq bittableoffset* oldbto))
      
      (cond ((get name '*apply*) (apply (car (get name '*apply*)) in))
		          % escape for opcode pseudo instructions
	    ((setq format (get name 'd-p-i-s))
			 (format-matcher in format nil '*i-format*))
	    ((setq format (get name 'd-p-i-s-2))
			 (format-matcher in format nil '*i-format*))
	    ((setq format (get name 'd-p-r-s-2))
			 (format-matcher in format nil '*i-format*))
	    ((setq format (get name 'd-p-i))
			 (format-matcher in format nil '*i-format*))
	    ((setq format (get name 'l-s-i-o))
			 (format-matcher in format nil '*b-format*))
	    ((setq format (get name 'l-s-r-o))
			 (format-matcher in format nil '*b-format*))
	    ((setq format (get name 'l-s-m))
			 (format-matcher in format nil '*b-format*))
	    ((setq format (get name 'b-b-l))
			 (format-matcher in format nil '*b-format*))
   (t (error 4711 (list "Wrong ARM v6 instr :" in))))
  % 
  % update currentoffset*
  %
    (setq currentoffset* (plus2 oldcurrent lng)) 
    (when *writingfaslfile (setq bittableoffset* (plus2 oldbto lng )))
) )

(de format-matcher (ins format initlist formfkt) 
   (prog (in name item fmtitem alist appl)
       (setq alist 
	     (append initlist
		`((cond . 0) (Rn . 0) (Rd . 0) (shifter . 0) (Rs . 0)
		  (I . 0) (opcode . 0) (registerlist . 0) (S . 0) (L . 0)
		  (P . 0) (U . 0) (W . 0) (bi . 0) (bo . 0) (bd . 0)
		  (mb . 0) (bf . 0) (funct . 0) (d16 . 0) )))
       (setq name (car ins))
       (setq in (cdr ins)) 
	(while (pairp in)
	 (setq item (car in))
	 (setq fmtitem (car format))
	 (cond  ((numberp fmtitem)  nil)
		((and (idp fmtitem)
		      (setq appl (get fmtitem 'matchfn)))
		      (setq alist (apply appl (list (car in) alist))))
		(t (error 4711 (list "wrong RS 6000 instruction " ins))))
	 (setq in (cdr in))
	 (setq format (cdr format))
	 (when (and (not (pairp format)) in)
		(error 4711 (list "RS 6000 wrong instruction :" ins))))

	(while format
	   (when (idp (car format))
	       (error 4711 (list "RS 6000 instruction too short :" ins)))
	   (setq format (cdr format)))

   (apply formfkt (list name alist))
)  )
   
(put 'rt 'matchfn 'rt-match)

(de rt-match (r alist)
    (if (regp r) (cons (cons 'rt r) alist)
     (matcherror "Register" r)))

(put 'rs 'matchfn 'rs-match)

(de rs-match (x alist)
    (if (regp x) (cons (cons 'rs x) alist)
     (matcherror "Register" x)))

(put 'ra 'matchfn 'ra-match)

(de ra-match (x alist)
    (if (regp x) (cons (cons 'ra x) alist)
     (matcherror "Register" x)))

(put 'rb 'matchfn 'rb-match)

(de rb-match (x alist)
    (if (regp x) (cons (cons 'rb x) alist)
     (matcherror "Register" x)))

(put 'sh 'matchfn 'sh-match)

(de sh-match (x alist)
    (if (and (posintp x) (wlessp x 33))  (cons (cons 'sh x) alist)
     (matcherror "Shift amount"x)))

(put 'mb 'matchfn 'mb-match)

(de mb-match (x alist)
    (if (and (posintp x) (wlessp x 33))  (cons (cons 'mb x) alist)
     (matcherror "Mask begin" x)))

(put 'me 'matchfn 'me-match)

(de me-match (x alist)
    (if (and (posintp x) (wlessp x 33))  (cons (cons 'me x) alist)
     (matcherror "Mask end" x)))

(put 'bitn 'matchfn 'bitnumber-match)

(de bitnumber-match(x alist)
    (if (and (posintp x) (wlessp x 33)) (cons (cons 'bitn x) alist)
	(matcherror "Bit number" x)))

(put 'spr 'matchfn 'spr-match)

(de spr-match(x alist)
   (prog (regi)
     (cond ((equal x '(reg mq))  (setq regi 2#00000))
	   ((equal x '(reg XER)) (setq regi 2#00001))
	   ((equal x '(reg RCTU))(setq regi 2#00100))
	   ((equal x '(reg RCTL))(setq regi 2#00101))
	   ((equal x '(reg DEC)) (setq regi 2#00110))
	   ((equal x '(reg lr))  (setq regi 2#01000))
	   ((equal x '(reg CTr)) (setq regi 2#01001)) 
	   (t (return (matcherror "Special Purpose Register" x))))
     (return (cons (cons 'spr regi) alist))))

(put 'bo 'matchfn 'bo-match)

(de bo-match(x alist)
   (prog (regi)
     (cond ((numberp x) (setq regi (wand x 31)))
	   ((equal x 'always)  (setq regi 2#10100))
           ((equal x 'True)    (setq regi 2#01100))
	   ((equal x 'false)   (setq regi 2#00100))
           (t (return (matcherror "Branch Option" x))))
     (return (cons (cons 'bo regi)(cons (cons 'bt regi) alist)))))

(put 'bi 'matchfn 'bi-match)

(de bi-match(x alist)
   (prog (regi)
     (cond ((numberp x) (setq regi (wand x 31)))
           ((equal x 'LT)(setq regi 0))
           ((equal x 'GT)(setq regi 1))
	   ((equal x 'eq)(setq regi 2))
	   ((equal x 'so)(setq regi 3))
           (t (return (matcherror "Branch Bit" x))))
     (return (cons (cons 'bi regi) alist))))

(put 'bt 'matchfn 'bt-match)

(de bt-match (x alist)
   (if (and (posintp x) (wlessp x 16))
	(cons (cons 'bt x) alist)
    (matcherror "Conditionregister bit bt" x)))

(put 'ba 'matchfn 'ba-match)

(de ba-match (x alist)
   (if (and (posintp x) (wlessp x 16))
        (cons (cons 'ba x) (cons (cons 'bi x) alist))
    (matcherror "Conditionregister bit ba" x)))

(put 'bb 'matchfn 'bb-match)

(de bb-match (x alist)
   (if (and (posintp x) (wlessp x 16))
        (cons (cons 'bb x) alist)
    (matcherror "Conditionregister bit bb" x)))

(put 'bf 'matchfn 'bf-match)

(de bf-match (x alist)
   (if (and (posintp x) (wlessp x 8))
        (cons (cons 'bf (lshift x 2)) alist)
    (matcherror "Conditionregister field bf" x)))

(put 'tworegs 'matchfn 'tworegs-match)

(de tworegs-match (x alist)
      (cond ((atom x) (matcherror "tworegs" x))
            ((or (eq (car x) 'indexed) (eq (car x) 'displacement))
                     (cons (cons 'rs2 (caddr x))
                           (cons (cons 'rs1 (cadr x)) alist)))
            (t (matcherror "tworegs" x))))

(put 'scaled 'matchfn 'scaled-match)

(de scaled-match (x alist)
      (cond ((and (eqcar x 'scaled) (regp (cadr x)) (regp (caddr x)))
                     (cons (cons 'rs1 (cadr x))
                           (cons (cons 'rs2 (caddr x)) alist)))
            (t (matcherror "scaled" x))))

(put 'based 'matchfn 'based-match)

(de based-match (x alist)
   (if (atom x)   (cons (cons 'immediate (addressvalue x))
		         (cons (cons 'ra '(reg null)) alist))
      (cond ((eq (car x) 'deferred)
		 (cons (cons 'immediate 0) (cons (cons 'ra (cadr x)) alist)))
	    ((or (eq (car x) 'indexed) (eq (car x) 'displacement))
		     (cons (cons 'immediate (addressvalue (caddr x)))
		           (cons (cons 'ra (cadr x)) alist)))
	    ((eq (car x) 'entryaddress)
		(cons (cons 'immediate 
		        (wand (addressvalue (list 'xidloc (cadr x))) 16#ffff))
		        (cons (cons 'ra '(reg symfnccenter)) alist)))
	    ((eq (car x) 'valueaddress)
		(cons (cons 'immediate 
		        (wand (addressvalue (list 'xidloc (cadr(cadr x))))
		                 16#ffff))
		        (cons (cons 'ra '(reg symvalcenter)) alist)))
	    (t (matcherror "based" x)))))

(put 'si 'matchfn 'si-match)

(de si-match (x alist)
  (prog (add)
     (return  
	(if (setq add (addressvalue x))  
		(cons (cons 'immediate (wand add 16#ffff)) alist)
	     (matcherror "signed immediate" x)))))

(put 'ui 'matchfn 'ui-match)

(de ui-match (x alist)
  (prog (add)
     (return
        (if (setq add (addressvalue x))
                (cons (cons 'immediate  (wand add 16#ffff)) alist)
             (matcherror "unsigned immediate" x)))))


(put 'd16 'matchfn 'd16-match)

(de d16-match (x alist) % branch address
  (prog (add)
     (return  
      (if (setq add (jumpaddressvalue x))  
	(cons (cons 'immediate
		(wand (wshift add -2) 16#ffff)) 
		alist) % word addresses
     (matcherror "d16" x)))))

(put 'target 'matchfn 'target-match)

(de target-match (x alist) % jump address
  (prog (add)
     (return  
	(if (setq add (jumpaddressvalue x)) 
		(cons (cons 'target (wshift (wshift add 6) -8)) alist) 
                          % throw out hightest bits (see B instruction!
		(matcherror "target" x))))) 

(put 'target-14 'matchfn 'target-14-match)

(de target-14-match (x alist) % jump address
  (prog (add)
     (return
        (if (setq add (jumpaddressvalue x))
                (cons (cons 'bd (wshift (wshift add 16) -18)) alist)
		(matcherror "target-14" x)))))

(de matcherror (expected got)
    (error 4711 (list "Mismatch of Arguments (" expected "expected) :" got))) 

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% The formats : r, i, j and fr for floating r format 

%%      i-type instructions

(compiletime (ds valueofreg (x)
		(if (pairp (setq cdrass (cdr (atsoc x alist))))
		     (get-register-code cdrass) cdrass)))
  
(de *d-format* (name alist)
   (prog (cdrass)
     (return
	(make-d-type (get name '*opcode*)
                     (wor (valueofreg 'rt) (valueofreg 'rs))
		     (valueofreg 'ra)
		     (if (pairp (setq cdrass (cdr (atsoc 'immediate alist))))
		        (car cdrass) cdrass)
		     )) ))
 
(de *x-format* (name alist)
   (prog (cdrass a3163)
     (return
        (make-x-type (cond ((setq a3163 (get name '*special31*)) 31)
			   ((setq a3163 (get name '*special63*)) 63)
			   (t (error "mistvieh")))
                     (wor (valueofreg 'rt) (valueofreg 'rs))
                     (wplus2 (valueofreg 'ra)(valueofreg 'spr))
		     (wor (valueofreg 'rb) (cdr (atsoc 'sh alist)))
		     (car a3163)
		     (if (memq 'rc a3163) 1 0)))))

(de *xl-format* (name alist)
   (prog (cdrass a3163)
     (setq a3163 (get name '*special19*))
     (return
        (make-xl-type 19
		     (if (pairp (setq cdrass (cdr (atsoc 'bt alist))))
                        (car cdrass) cdrass)
                     (if (pairp (setq cdrass (cdr (atsoc 'ba alist))))
                        (car cdrass) cdrass)
                     (if (pairp (setq cdrass (cdr (atsoc 'bb alist))))
                        (car cdrass) cdrass)
                     (car a3163)
                     (if (memq 'lk a3163) 1 0)))))

(de *b-format* (name alist)
   (prog (cdrass a3163)
     (setq a3163 (get name '*opcode*))
     (return
        (make-b-type (car a3163)
                     (if (pairp (setq cdrass (cdr (atsoc 'bo alist))))
                        (car cdrass) cdrass)
                     (if (pairp (setq cdrass (cdr (atsoc 'bi alist))))
                        (car cdrass) cdrass)
                     (if (pairp (setq cdrass (cdr (atsoc 'bd alist))))
                        (car cdrass) cdrass)
                     (if (memq 'aa a3163) 1 0)
                     (if (memq 'lk a3163) 1 0)))))

(de *xo-format* (name alist)
   (prog (cdrass a3163)
     (setq a3163 (get name '*special31*))
     (return
        (make-xo-type 31
			(wor (valueofreg 'rt) (valueofreg 'rs))
			(valueofreg 'ra)
			(valueofreg 'rb)
			(car a3163)
                     (if (memq 'oe a3163) 1 0)
                     (if (memq 'rc a3163) 1 0)))))

(de *i-format* (name alist)
   (prog (cdrass a3163)
     (setq a3163 (get name '*opcode*))
     (return
        (make-i-type (car a3163)
                     (if (pairp (setq cdrass (cdr (atsoc 'target alist))))
                        (car cdrass) cdrass)
                     (if (memq 'aa a3163) 1 0)
                     (if (memq 'lk a3163) 1 0)))))

%%      j-type instructions
 
(de *j-format* (name alist) 
	(make-j-type (get name '*opcode*) 
		     (cdr (atsoc 'target alist))))
 
%%      r-type instructions
 
(de *m-format* (name alist)
   (prog (cdrass)
     (return
        (make-m-type (car (get name '*opcode*))
                     (valueofreg 'rs)
                     (valueofreg 'ra)
		     (plus2 (valueofreg 'rb) 
                      (if (pairp (setq cdrass (cdr (atsoc 'sh alist))))
                        (car cdrass) cdrass))
                     (if (pairp (setq cdrass (cdr (atsoc 'MB alist))))
                        (car cdrass) cdrass)
		     (if (pairp (setq cdrass (cdr (atsoc 'ME alist))))
                        (car cdrass) cdrass)
		     (if (memq 'rc (get name '*opcode*)) 1 0)))))

(de *r-format* (name alist)
   (prog (cdrass)
     (return
        (make-r-type 2#111101
                     (valueofreg 'rd)
                     (valueofreg 'rs1)
                     (car  (get name '*opcode*))
                     (cadr (get name '*opcode*))
                     (valueofreg 'rs2)
                     ))
 ))

(de *sr-format* (name alist)
   (prog (cdrass)
     (return
        (make-r-type 2#111101
                     (valueofreg 'rd)
                     (valueofreg 'rs1)
                     (car  (get name '*scaled*))
                     (cadr (get name '*scaled*))
                     (valueofreg 'rs2)
                     ))
 ))

(de *float-format* (name alist)
   (prog (cdrass)
     (return
	(make-r-type 2#100001
		     (valueofreg 'rd)
		     (valueofreg 'rs1)
		     (car  (get name '*float*))
                     (cadr (get name '*float*))
                     (valueofreg 'rs2)
		     ))))
% The make functions
 
(de make-d-type (op rt ra imm)
     (let ((code (wor (wshift (car op) 26)
		      (wor (wshift rt 21)
		           (wor (wshift ra 16)
		                (wand imm 16#ffff))))))
       (store-word code)))
 
(de make-m-type (op rs ra op1 mb me rc)
     (let ((code (wor (wshift op 26)
		      (wor (wshift rs 21)
		           (wor (wshift ra 16)
		                (wor (wshift op1 11)
		                     (wor (wshift mb 6)
					  (wor (wshift me 1) rc))))))))
      (store-word code)))

(de make-x-type (op rt ra rb sec rc)
     (let ((code (wor (wshift op 26)
                      (wor (wshift rt 21)
                           (wor (wshift ra 16)
                                (wor (wshift rb 11)
                                     (wor (wshift sec 1) rc)))))))
      (store-word code)))

(de make-xl-type (op bt ba bb sec lk)
     (let ((code (wor (wshift op 26)
                      (wor (wshift bt 21)
                           (wor (wshift ba 16)
                                (wor (wshift bb 11)
                                     (wor (wshift sec 1) lk)))))))
      (store-word code)))

(de make-xo-type (op rt ra rb ext oe rc)
     (let ((code (wor (wshift op 26)
                      (wor (wshift rt 21)
                           (wor (wshift ra 16)
                                (wor (wshift rb 11)
                                     (wor (wshift oe 10)
					(wor (wshift ext 1) rc))))))))
      (store-word code)))

(de make-b-type (op bt ba bd aa lk)
     (let ((code (wor (wshift op 26)
                      (wor (wshift bt 21)
                           (wor (wshift ba 16)
                                (wor (wshift bd 2)
				     (wor (wshift aa 1) lk)))))))
      (store-word code)))

(de make-i-type (op li aa lk)
     (let ((code (wor (wshift op 26)
			(wor (wshift li 2)
				(wor (wshift aa 1) lk)))))
      (store-word code)))

%%    The Instruction definitions

(def-inst a    4   (*special31* 10)       (*xo-format* rt ra rb))
(def-inst a!.  4   (*special31* 10 Rc)    (*xo-format* rt ra rb))
(def-inst ao   4   (*special31* 10 Oe)    (*xo-format* rt ra rb))
(def-inst ao!. 4   (*special31* 10 Rc Oe) (*xo-format* rt ra rb))

(def-inst abs    4   (*special31* 360)       (*xo-format* rt ra ))
(def-inst abs!.  4   (*special31* 360 Rc)    (*xo-format* rt ra ))
(def-inst abso   4   (*special31* 360 Oe)    (*xo-format* rt ra ))
(def-inst abso!. 4   (*special31* 360 Rc Oe) (*xo-format* rt ra ))

(def-inst ae    4   (*special31* 138)       (*xo-format* rt ra rb))
(def-inst ae!.  4   (*special31* 138 Rc)    (*xo-format* rt ra rb))
(def-inst aeo   4   (*special31* 138 Oe)    (*xo-format* rt ra rb))
(def-inst aeo!. 4   (*special31* 138 Rc Oe) (*xo-format* rt ra rb))

(def-inst ai   4   (*opcode* 12) (*d-format* rt ra si))
(def-inst ai!. 4   (*opcode* 13) (*d-format* rt ra si))

(def-inst ame    4   (*special31* 234)       (*xo-format* rt ra ))
(def-inst ame!.  4   (*special31* 234 Rc)    (*xo-format* rt ra ))
(def-inst ameo   4   (*special31* 234 Oe)    (*xo-format* rt ra ))
(def-inst ameo!. 4   (*special31* 234 Rc Oe) (*xo-format* rt ra ))

(def-inst and    4   (*special31* 28)    (*x-format* ra rs rb ))
(def-inst and!.  4   (*special31* 28 Rc) (*x-format* ra rs rb ))

(def-inst andc   4   (*special31* 60)    (*x-format* ra rs rb ))
(def-inst andc!. 4   (*special31* 60 Rc) (*x-format* ra rs rb ))

(def-inst andil!. 4   (*opcode* 28) (*d-format* ra rs ui))
(def-inst andiu!. 4   (*opcode* 29) (*d-format* ra rs ui))

(def-inst aze    4   (*special31* 202)       (*xo-format* rt ra ))
(def-inst aze!.  4   (*special31* 202 Rc)    (*xo-format* rt ra ))
(def-inst azeo   4   (*special31* 202 Oe)    (*xo-format* rt ra ))
(def-inst azeo!. 4   (*special31* 202 Rc Oe) (*xo-format* rt ra ))


(def-inst b      4   (*opcode* 18)       (*i-format* target))
(def-inst ba     4   (*opcode* 18 AA)    (*i-format* target))
(def-inst bl     4   (*opcode* 18 Lk)    (*i-format* target))
(def-inst bla    4   (*opcode* 18 AA LK) (*i-format* target))

(def-inst bbt    4   (*opcode* 16)       (*b-format* i1 a2))

(def-inst bc     4   (*opcode* 16)       (*b-format* BO BI target-14))
(def-inst bca    4   (*opcode* 16 AA)    (*b-format* BO BI target-14))
(def-inst bcl    4   (*opcode* 16 LK)    (*b-format* BO BI target-14))
(def-inst bcla   4   (*opcode* 16 AA LK) (*b-format* BO BI target-14))

(def-inst bcc    4   (*special19* 528)    (*xl-format* BO BI))
(def-inst bccl   4   (*special19* 528 LK) (*xl-format* BO BI))

(def-inst bcr    4   (*special19* 16)    (*xl-format* BO BI))
(def-inst bcrl   4   (*special19* 16 LK) (*xl-format* BO BI))

(def-inst cal    4   (*opcode* 14) (*d-format* rt based))
(def-inst cau    4   (*opcode* 15) (*d-format* rt RA UI))

(def-inst cax    4   (*special31* 266)       (*xo-format* rt ra rb))
(def-inst cax!.  4   (*special31* 266 Rc)    (*xo-format* rt ra rb))
(def-inst caxo   4   (*special31* 266 Oe)    (*xo-format* rt ra rb))
(def-inst caxo!. 4   (*special31* 266 Rc Oe) (*xo-format* rt ra rb))

(def-inst cmp    4   (*special31* 0) (*x-format* bf ra rb))
(def-inst cmpi   4   (*opcode* 11) (*d-format* bf RA SI))
(def-inst cmpl   4   (*special31* 32) (*x-format* bf ra rb))
(def-inst cmpli  4   (*opcode* 10) (*d-format* bf RA UI))

(def-inst cntlz  4   (*special31* 26) (*x-format* rs ra))
(def-inst cntlz!. 4  (*special31* 26 RC) (*x-format* rs ra))

(def-inst crand  4   (*special19* 257) (*xl-format* bt ba bb))
(def-inst crandc 4   (*special19* 129) (*xl-format* bt ba bb))
(def-inst creqv  4   (*special19* 289) (*xl-format* bt ba bb))
(def-inst crnand 4   (*special19* 225) (*xl-format* bt ba bb))
(def-inst crnor  4   (*special19*  33) (*xl-format* bt ba bb))
(def-inst cror   4   (*special19* 449) (*xl-format* bt ba bb))
(def-inst crorc  4   (*special19* 417) (*xl-format* bt ba bb))
(def-inst crxor  4   (*special19* 193) (*xl-format* bt ba bb))

(def-inst div    4   (*special31* 331) (*xo-format* rt ra rb))
(def-inst div!.  4   (*special31* 331 RC) (*xo-format* rt ra rb))
(def-inst divo   4   (*special31* 331 oe) (*xo-format* rt ra rb))
(def-inst divo!. 4   (*special31* 331 rc oe) (*xo-format* rt ra rb))

(def-inst divs   4   (*special31* 363) (*xo-format* rt ra rb))
(def-inst divs!. 4   (*special31* 363 RC) (*xo-format* rt ra rb))
(def-inst divso  4   (*special31* 363 oe) (*xo-format* rt ra rb))
(def-inst divso!. 4  (*special31* 363 rc oe) (*xo-format* rt ra rb))

(def-inst doz    4   (*special31* 264) (*xo-format* rt ra rb))
(def-inst doz!.  4   (*special31* 264 RC) (*xo-format* rt ra rb))
(def-inst dozo   4   (*special31* 264 oe) (*xo-format* rt ra rb))
(def-inst dozo!. 4   (*special31* 264 rc oe) (*xo-format* rt ra rb))
(def-inst dozi   4   (*opcode* 9) (*d-format* rt RA SI))

(def-inst eqv    4   (*special31* 284) (*x-format* rs ra rb))
(def-inst eqv!.  4   (*special31* 284 rc) (*x-format* rs ra rb))

(def-inst exts   4   (*special31* 922) (*x-format* ra rs))
(def-inst exts!. 4   (*special31* 922 rc) (*x-format* ra rs))

(def-inst fa     4   (*special63* 21) (*a-format* frt fra frb))
(def-inst fa!.   4   (*special63* 21 rc) (*a-format* frt fra frb))

(def-inst fabs   4   (*special63* 264) (*x-format* frt frb))
(def-inst fabs!. 4   (*special63* 264 rc) (*x-format* frt frb))

(def-inst fcmpo  4   (*special63* 32) (*x-format* bf fra frb))
(def-inst fcmpu  4   (*special63*  0) (*x-format* bf fra frb))

(def-inst fd     4   (*special63* 18) (*a-format* frt fra frb))
(def-inst fd!.   4   (*special63* 18 rc) (*a-format* frt fra frb))

(def-inst fm     4   (*special63* 25) (*a-format* frt fra frc))
(def-inst fm!.   4   (*special63* 25 rc) (*a-format* frt fra frc))

(def-inst fma    4   (*special63* 29) (*a-format* frt fra frb frc))
(def-inst fma!.  4   (*special63* 29 rc) (*a-format* frt fra frb frc))

(def-inst fmr    4   (*special63* 72) (*x-format* frt frb))
(def-inst fmr!.  4   (*special63* 72 rc) (*x-format* frt frb))

(def-inst fms    4   (*special63* 28) (*a-format* frt fra frb frc))
(def-inst fms!.  4   (*special63* 28 rc) (*a-format* frt fra frb frc))

(def-inst fnabs  4   (*special63* 136) (*x-format* frt frb))
(def-inst fnabs!. 4  (*special63* 136 rc) (*x-format* frt frb))

(def-inst fneg   4   (*special63* 40) (*x-format* frt frb))
(def-inst fneg!. 4   (*special63* 40 rc) (*x-format* frt frb))

(def-inst fnma   4   (*special63* 31) (*a-format* frt fra frb frc))
(def-inst fnma!. 4   (*special63* 31 rc) (*a-format* frt fra frb frc))

(def-inst fnms   4   (*special63* 30) (*a-format* frt fra frb frc))
(def-inst fnms!. 4   (*special63* 30 rc) (*a-format* frt fra frb frc))

(def-inst frsp   4  (*special63* 12) (*x-format* frt frb))
(def-inst frsp!. 4  (*special63* 12 rc) (*x-format* frt frb))

(def-inst fs     4   (*special63* 20) (*a-format* frt fra frb))
(def-inst fs!.   4   (*special63* 20 rc) (*a-format* frt fra frb))

(def-inst l      4   (*opcode* 32) (*d-format* rt based))
(def-inst lbrx   4   (*special31* 534) (*x-format* rt ra rb))
(def-inst lbz    4   (*opcode* 34) (*d-format* rt based))
(def-inst lbzu   4   (*opcode* 35) (*d-format* rt based))
(def-inst lbzux  4   (*special31* 119) (*x-format* rt ra rb))
(def-inst lbzx   4   (*special31* 87) (*x-format* rt ra rb))

(def-inst lfd    4   (*opcode* 50) (*d-format* frt based))
(def-inst lfdu   4   (*opcode* 51) (*d-format* frt based))
(def-inst lfdux  4   (*special31* 631) (*x-format* frt ra rb))
(def-inst lfdx   4   (*special31* 599) (*x-format* frt ra rb))
(def-inst lfs    4   (*opcode* 48) (*d-format* frt based))
(def-inst lfsu   4   (*opcode* 49) (*d-format* frt based))
(def-inst lfsux  4   (*special31* 567) (*x-format* frt ra rb))
(def-inst lfsx   4   (*special31* 535) (*x-format* frt ra rb))

(def-inst lha    4   (*opcode* 42) (*d-format* rt based))
(def-inst lhau   4   (*opcode* 43) (*d-format* rt based))
(def-inst lhaux  4   (*special31* 375) (*x-format* rt ra rb))
(def-inst lhax   4   (*special31* 343) (*x-format* rt ra rb))
(def-inst lhbrx  4   (*special31* 790) (*x-format* rt ra rb))
(def-inst lhz    4   (*opcode* 40) (*d-format* rt based))
(def-inst lhzux  4   (*special31* 311) (*x-format* rt ra rb))
(def-inst lhzx   4   (*special31* 279) (*x-format* rt ra rb))

(def-inst lil    4   (*opcode* 14) (*d-format* rt SI))
(def-inst liu    4   (*opcode* 15) (*d-format* rt UI))

(def-inst lm     4   (*opcode* 46) (*d-format* rt based))

(def-inst lscbx  4   (*special31* 277) (*x-format* rt ra rb))
(def-inst lscbx!. 4  (*special31* 277 rc) (*x-format* rt ra rb))

(def-inst lsi    4   (*special31* 579) (*x-format* rt ra nb))
(def-inst lsx    4   (*special31* 533) (*x-format* rt ra rb))

(def-inst lu     4   (*opcode* 33) (*d-format* rt based))
(def-inst lux    4   (*special31* 55) (*x-format* rt ra rb))
(def-inst lx     4   (*special31* 23) (*x-format* rt ra rb))

(def-inst maskg  4   (*special31* 29) (*x-format* ra rs rb))
(def-inst maskg!. 4  (*special31* 29 rc) (*x-format* ra rs rb))
(def-inst maskir 4   (*special31* 541) (*x-format* ra rs rb))
(def-inst maskir!. 4 (*special31* 541 rc) (*x-format* ra rs rb))

(def-inst mcrf   4   (*special19* 0) (*xl-format* bf bfa))
(def-inst mcrfs  4   (*opcode* 63) (*xl-format* bf bfa))
(def-inst mcrxr  4   (*special31* 512) (*x-format* bf))
(def-inst mfcr   4   (*special31* 19) (*x-format* rt))
(def-inst mffs   4   (*special63* 583) (*x-format* frt))
(def-inst mfmsr  4   (*special31* 83) (*x-format* rt))
(def-inst mfspr  4   (*special31* 339) (*x-format* rt spr))

% mtcrf
% mtfsf
% mtfsfi

(def-inst mtfsb1 4   (*special63* 38) (*x-format* bt))
(def-inst mtfsb0 4   (*special63* 70) (*x-format* bt))
(def-inst mtspr  4   (*special31* 467) (*x-format* spr rs))

(def-inst mul    4   (*special31* 107) (*xo-format* rt ra rb))
(def-inst mul!.  4   (*special31* 107 RC) (*xo-format* rt ra rb))
(def-inst mulo   4   (*special31* 107 oe) (*xo-format* rt ra rb))
(def-inst mulo!. 4   (*special31* 107 rc oe) (*xo-format* rt ra rb))

(def-inst muli   4   (*opcode* 07) (*d-format* rt ra si))

(def-inst muls   4   (*special31* 235) (*xo-format* rt ra rb))
(def-inst muls!. 4   (*special31* 235 RC) (*xo-format* rt ra rb))
(def-inst mulso  4   (*special31* 235 oe) (*xo-format* rt ra rb))
(def-inst mulso!. 4  (*special31* 235 rc oe) (*xo-format* rt ra rb))

(def-inst nabs   4   (*special31* 488) (*xo-format* rt ra))
(def-inst nabs!. 4   (*special31* 488 RC) (*xo-format* rt ra))
(def-inst nabso  4   (*special31* 488 oe) (*xo-format* rt ra))
(def-inst nabso!. 4  (*special31* 488 rc oe) (*xo-format* rt ra))

(def-inst nand   4   (*special31* 476) (*x-format* ra rs rb))
(def-inst nand!. 4   (*special31* 476 RC) (*x-format* ra rs rb))

(def-inst neg    4   (*special31* 104) (*xo-format* rt ra))
(def-inst neg!.  4   (*special31* 104 RC) (*xo-format* rt ra))
(def-inst nego   4   (*special31* 104 oe) (*xo-format* rt ra))
(def-inst nego!. 4   (*special31* 104 rc oe) (*xo-format* rt ra))

(def-inst nor    4   (*special31* 124) (*x-format* ra rs rb))
(def-inst nor!.  4   (*special31* 124 RC) (*x-format* ra rs rb))

(def-inst or     4   (*special31* 444) (*x-format* ra rs rb))
(def-inst or!.   4   (*special31* 444 RC) (*x-format* ra rs rb))

(def-inst orc    4   (*special31* 412) (*x-format* ra rs rb))
(def-inst orc!.  4   (*special31* 412 RC) (*x-format* ra rs rb))

(def-inst oril   4   (*opcode* 24) (*d-format* ra rs ui))
(def-inst oriu   4   (*opcode* 25) (*d-format* ra rs ui))

(def-inst rlimi  4   (*opcode* 20) (*m-format* ra rs sh mb me))
(def-inst rlimi!. 4  (*opcode* 20 rc) (*m-format* ra rs sh mb me))
(def-inst rlinm  4   (*opcode* 21) (*m-format* ra rs sh mb me))
(def-inst rlinm!. 4  (*opcode* 21 rc) (*m-format* ra rs sh mb me))
(def-inst rlmi   4   (*opcode* 22) (*m-format* ra rs rb mb me))
(def-inst rlmi!. 4   (*opcode* 22 rc) (*m-format* ra rs rb mb me))
(def-inst rlnm   4   (*opcode* 23) (*m-format* ra rs rb mb me))
(def-inst rlnm!. 4   (*opcode* 23 rc) (*m-format* ra rs rb mb me))

(def-inst rrib   4   (*special31* 537) (*x-format* ra rs rb))
(def-inst rrib!. 4   (*special31* 537) (*x-format* ra rs rb))

(def-inst sf     4   (*special31* 8) (*xo-format* rt ra rb))
(def-inst sf!.   4   (*special31* 8 RC) (*xo-format* rt ra rb))
(def-inst sfo    4   (*special31* 8 oe) (*xo-format* rt ra rb))
(def-inst sfo!.  4   (*special31* 8 rc oe) (*xo-format* rt ra rb))

(def-inst sfe    4   (*special31* 136) (*xo-format* rt ra rb))
(def-inst sfe!.  4   (*special31* 136 RC) (*xo-format* rt ra rb))
(def-inst sfeo   4   (*special31* 136 oe) (*xo-format* rt ra rb))
(def-inst sfeo!. 4   (*special31* 136 rc oe) (*xo-format* rt ra rb))

(def-inst sfi    4   (*opcode* 8) (*d-format* rt ra si))

(def-inst sfme   4   (*special31* 232) (*xo-format* rt ra))
(def-inst sfme!. 4   (*special31* 232 RC) (*xo-format* rt ra))
(def-inst sfmeo  4   (*special31* 232 oe) (*xo-format* rt ra))
(def-inst sfmeo!. 4  (*special31* 232 rc oe) (*xo-format* rt ra))

(def-inst sfze   4   (*special31* 200) (*xo-format* rt ra))
(def-inst sfze!. 4   (*special31* 200 RC) (*xo-format* rt ra))
(def-inst sfzeo  4   (*special31* 200 oe) (*xo-format* rt ra))
(def-inst sfzeo!. 4  (*special31* 200 rc oe) (*xo-format* rt ra))

(def-inst sl     4   (*special31* 24) (*x-format* ra rs rb))
(def-inst sl!.   4   (*special31* 24 rc) (*x-format* ra rs rb))
(def-inst sle    4   (*special31* 153) (*x-format* ra rs rb))
(def-inst sle!.  4   (*special31* 153 rc) (*x-format* ra rs rb))
(def-inst sleq   4   (*special31* 217) (*x-format* ra rs rb))
(def-inst sleq!. 4   (*special31* 217 rc) (*x-format* ra rs rb))
(def-inst sliq   4   (*special31* 184) (*x-format* ra rs sh))
(def-inst sliq!. 4   (*special31* 184 rc) (*x-format* ra rs sh))
(def-inst slliq  4   (*special31* 248) (*x-format* ra rs sh))
(def-inst slliq!. 4  (*special31* 248 rc) (*x-format* ra rs sh))
(def-inst sllq   4   (*special31* 216) (*x-format* ra rs rb))
(def-inst sllq!. 4   (*special31* 216 rc) (*x-format* ra rs rb))
(def-inst slq    4   (*special31* 152) (*x-format* ra rs rb))
(def-inst slq!.  4   (*special31* 152 rc) (*x-format* ra rs rb))

(def-inst sr     4   (*special31* 536) (*x-format* ra rs rb))
(def-inst sr!.   4   (*special31* 536 rc) (*x-format* ra rs rb))
(def-inst sra    4   (*special31* 792) (*x-format* ra rs rb))
(def-inst sra!.  4   (*special31* 792 rc) (*x-format* ra rs rb))
(def-inst srai   4   (*special31* 824) (*x-format* ra rs sh))
(def-inst srai!. 4   (*special31* 824 rc) (*x-format* ra rs sh))
(def-inst sraiq  4   (*special31* 592) (*x-format* ra rs sh))
(def-inst sraiq!. 4  (*special31* 592 rc) (*x-format* ra rs sh))
(def-inst sraq   4   (*special31* 920) (*x-format* ra rs rb))
(def-inst sraq!. 4   (*special31* 920 rc) (*x-format* ra rs rb))
(def-inst sre    4   (*special31* 665) (*x-format* ra rs rb))
(def-inst sre!.  4   (*special31* 665 rc) (*x-format* ra rs rb))
(def-inst srea   4   (*special31* 921) (*x-format* ra rs rb))
(def-inst srea!. 4   (*special31* 921 rc) (*x-format* ra rs rb))
(def-inst sreq   4   (*special31* 729) (*x-format* ra rs rb))
(def-inst sreq!. 4   (*special31* 729 rc) (*x-format* ra rs rb))
(def-inst sriq   4   (*special31* 696) (*x-format* ra rs sh))
(def-inst sriq!. 4   (*special31* 696 rc) (*x-format* ra rs sh))
(def-inst srliq  4   (*special31* 760) (*x-format* ra rs sh))
(def-inst srliq!. 4  (*special31* 760 rc) (*x-format* ra rs sh))
(def-inst srlq   4   (*special31* 728) (*x-format* ra rs rb))
(def-inst srlq!. 4   (*special31* 728 rc) (*x-format* ra rs rb))
(def-inst srq    4   (*special31* 664) (*x-format* ra rs rb))
(def-inst srq!.  4   (*special31* 664 rc) (*x-format* ra rs rb))

(def-inst st     4   (*opcode* 36) (*d-format* rs based))
(def-inst stb    4   (*opcode* 38) (*d-format* rs based))
(def-inst stbrx  4   (*special31* 662) (*x-format* rs ra rb))
(def-inst stbu   4   (*opcode* 39) (*d-format* rs based))
(def-inst stbux  4   (*special31* 247) (*x-format* rs ra rb))
(def-inst stbx   4   (*special31* 215) (*x-format* rs ra rb))

(def-inst stfd   4   (*opcode* 54) (*d-format* frs based))
(def-inst stfdu  4   (*opcode* 55) (*d-format* frs based))
(def-inst stfdux 4   (*special31* 759) (*x-format* frs ra rb))
(def-inst stfdx  4   (*special31* 727) (*x-format* frs ra rb))
(def-inst stfs   4   (*opcode* 52) (*d-format* frs based))
(def-inst stfsu  4   (*opcode* 53) (*d-format* frs based))
(def-inst stfsux 4   (*special31* 695) (*x-format* frs ra rb))
(def-inst stfsx  4   (*special31* 663) (*x-format* frs ra rb))

(def-inst sth    4   (*opcode* 44) (*d-format* rs based))
(def-inst sthbrx 4   (*special31* 918) (*x-format* rs ra rb))
(def-inst sthu   4   (*opcode* 45) (*d-format* rs based))
(def-inst sthux  4   (*special31* 439) (*x-format* rs ra rb))
(def-inst sthx   4   (*special31* 407) (*x-format* rs ra rb))

(def-inst stm    4   (*opcode* 47) (*d-format* rs based))

(def-inst stsi   4   (*special31* 725) (*x-format* rs ra nb))
(def-inst stsx   4   (*special31* 661) (*x-format* rs ra rb))

(def-inst stu    4   (*opcode* 37) (*d-format* rs based))
(def-inst stux   4   (*special31* 183) (*x-format* rs ra rb))
(def-inst stx    4   (*special31* 151) (*x-format* rs ra rb))

 %svc
 % trap
 % ti

(def-inst xor    4   (*special31* 316) (*x-format* ra rs rb))
(def-inst xor!.  4   (*special31* 316 RC) (*x-format* ra rs rb))

(def-inst xoril  4   (*opcode* 26) (*d-format* ra rs ui))
(def-inst xoriu  4   (*opcode* 27) (*d-format* ra rs ui))

%%      move-relocatable-object pseudo instructions

(def-inst move-relocatable-object 8 (*apply* movex-gen))

(de movex-gen (name src reg)
	(if *writingfaslfile
	   (progn
	    (store-word-expression src)  %% when writing to faslfile, generate
	    (relocatable-movex-gen reg)) %% opcode code for relocation.
	 (depositinstruction `(cau ,reg (reg 0) (hi16 ,src))) 
		                         %% otherwise normal code.
	 (depositinstruction `(oril ,reg ,reg (lo16 ,src) ))))

(def-inst  move-relocatable-object-and-load 8 (*apply* movex-load))

(de movex-load (name reg src )
   (if *writingfaslfile
	  (progn
	   (store-word-expression  src)  %% when writing to faslfile, generate
	   (relocatable-movex-load  reg))   %% opcode code for relocation.
	 (depositinstruction `(cau ,reg (reg 0) (adjhi16 ,src)))
		                 %% otherwise normal code.
	 (depositinstruction `(l ,reg (indexed ,reg (lo16 ,src))))))

(def-inst move-relocatable-object-and-store 8 (*apply* movex-store))

(de movex-store (name reg src cont)
  (if *writingfaslfile
	  (progn
	   (store-word-expression src) %% when writing to faslfile, generate
	   (relocatable-movex-store reg cont)) %% code for relocation.
	(depositinstruction `(cau ,reg (reg 0) (adjhi16 ,src)))
		                          %% otherwise normal code.
	(depositinstruction `(st ,cont (indexed ,reg (lo16 ,src))))))

(de relocatable-movex-gen (reg)
  (let ((regcode (get-register-code reg)) (mov-instr 24))
       (store-relocatable-movex            % oril instr
	    (wplus2 (wshift mov-instr 26)
		    (wplus2  (wshift regcode 21) (wshift regcode 16))))))

(de relocatable-movex-store (reg cont)
  (let ((regcode (get-register-code reg))
	(regcode1 (get-register-code cont))
	(mov-instr 36))  %st
       (store-relocatable-movex 
	    (wplus2 (wshift mov-instr 26)
		    (wplus2  (wshift regcode 21) (wshift regcode1 16))))))

(de relocatable-movex-load (reg)
  (let ((regcode (get-register-code reg)) (mov-instr 32))
       (store-relocatable-movex 		% l
	    (wplus2 (wshift mov-instr 26)
		    (wplus2  (wshift regcode 21) (wshift regcode 16))))))
 %
 %Basic Predicates
 %

(de ibmrs-immediate-p(r)
  (cond ((fixp r) t)
	((stringp r) t)
	((idp r)  (cond ((get r '*register-code) nil)
	                ((get r '*f-register-code) nil)
	                ((get r '*g-register-code) nil)
	                 (t     t)))  %% label
	(t nil)))

(de ibmrs-relocatable-immediate-p (r)  (eqcar r 'IMMEDIATE))

(de ibmrs-short-immediate-p (r)
	  (and (fixp r) (greaterp r 65535) (lessp r -65536)))

(de ibmrs-huge-displacement-p (r)
	   (and (eqcar r 'displacement)
                (numberp (caddr r))
		(or (greaterp (caddr r) 65535) (lessp (caddr r) -65536))))

(de ibmrs-deferred-p (r)    (eqcar r 'deferred))

(de ibmrs-indirect-p (r)
  (and (pairp r)
       (or (ibmrs-register-p (car r))
	   (eq (car r) 'deferred)
	   (eq (car r) 'displacement))))

(de ibmrs-double-indirect-p (r)
   (and (eqcar r 'deferred) (ibmrs-indirect-p (cadr r))))

(de ibmrs-fluid-p (r)
	  (and (pairp r) (member (car r)  '(!$fluid !$global fluid global))))

(de ibmrs-absolute-p (r)
	  (or (eqcar r 'quote) (stringp r)))

(de ibmrs-foreignentry-p (r)
	  (eqcar r 'foreignentry))
