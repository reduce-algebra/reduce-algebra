

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
