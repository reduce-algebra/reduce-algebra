%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:CONSTANTS.SL
% Description:  Functions for definitions of constants.
% Author:       Brian Beach, Hewlett-Packard CRC
% Created:      06-Mar-83
% Modified:     15 Oct 1984 2300-PDT (Brian Beach)
% Mode:         Lisp
% Package:      
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 15 Oct 1984 2300-PDT (Brian Beach)
%  Fixed file name in header.
% 22-Jun-84 11:10:21 (Brian Beach)
%  Changed COMPILER-CONSTANT so that in will accept regular constants too.
%  Added LOAD-FOR-COMPILER to load in compiler constants for cross compilation.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% The value for a constant is stored the the value cell.  A property is placed
% on the property list (CONSTANT?) to tell the compiler that the value can be
% treated as a constant.
%
% Some constants are implementation specific and need to be handled specially
% by the compiler.  The *CONSTANTS-FOR-COMPILER* flag is set when any constants
% being defined are to be defined for the compiler only.  The values for these
% constants are placed on property lists.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(*constants-for-compiler*))

(setf *constants-for-compiler* nil)

(defmacro define-constant (name init)
  (let ((form `(*define-constant ',name ,init)))
    (eval form)
    form))

(de *define-constant (name value)
  (if *constants-for-compiler*
    (progn
     (when (and *redefmsg
		(get name 'compiler-constant?)
		(not (equal value (get name 'compiler-constant-value))))
       (errorprintf "Request to set constant %p to a different value." name)
       )
     (put name 'compiler-constant? t)
     (put name 'compiler-constant-value value)
     )
    (progn
     (when (and (not (unboundp name))
		(not (equal value (eval name))))
       (errorprintf "Request to set constant %p to a different value." name)
       )
     (put name 'constant? t)
     (set name value)
     ))
  name
  )

    
(de compiler-constant (name)
  (cond
   ((get name 'compiler-constant?) (get name 'compiler-constant-value))
   ((get name 'constant?)          (eval name))
   (t (stderror (bldmsg "Unknown compiler constant used: %w" name)))
   ))

(dm load-for-compiler (u)
  `(*load-for-compiler (quote ,(rest u)))
  )

(de *load-for-compiler (module-list)
  (for (in module module-list)
       (do
	(let ((*constants-for-compiler* t)
	      (module-loaded?           (member module options*)))
	  (evreload (list module))
	  (unless module-loaded?
	    (setf options* (delete module options*))
	    )
	  ))
       ))

  
