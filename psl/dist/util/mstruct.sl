%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% MSTRUCT.SL -- A tiny structure package for PSL.
%
% Author: Bruce A. Florman
% Status: Open Source: BSD License
%
% DESCRIPTION
%
%	(defstruct <structspec> [ <slotspec>... ] )
%
%	The <structspec> may be either the name of the structure, or a 
%	list containing the name followed by zero or more options.
%	Each <slotspec> may be either a list containing the slot name 
%	and its default value, or simply the slot name, in which case 
%	the default value is NIL.
%
%	Each option in the <structspec> may be either an option name, 
%	or a list containing the option name and a specified value.
%	If only the option name is given, then the default value for 
%	the given option is used.  If NIL is the specified value in 
%	an option, then the option is not used at all (in general a NIL
%	value is the same as not having that option in the list at all).
%	If the same option appears more than once with different values, 
%	the last one in the <structspec> takes precedence.
%
%	These are the valid options:
%
%	SLOT-PREFIX or PREFIX or CONC-NAME
%		Append a prefix to each slot accessor macro.  The 
%		default prefix is the structure name and a hyphen.  
%		The symbol CONC-NAME is accepted for backwards 
%		compatability, dispite the fact that it isn't a 
%		particularly descriptive term.
%
%	PREDICATE
%		Makes the zeroth element of the structure contain 
%		the structure name, and creates a predicate macro 
%		to test if a given item is an instance of this 
%		structure.  The specified value is the name of 
%		the predicate macro.  The default value is the 
%		structure name followed by a `P'.
%
%	CONSTRUCTOR
%		By default the name of the constructor macro is 
%		`MAKE-' followed by the structure name.  You may 
%		provide a different constructor name with this 
%		option.  If there is no constructor option in the 
%		<structspec> the default constructor will still 
%		be generated.  The only way to completely sup-
%		press the generation of a constructor macro is to 
%		have a (CONSTRUCTOR NIL) option.
%
%	The flag !*FAST-STRUCTS controls how the accessor macros expand.  
%	If it is NIL, they expand as GETVs, otherwise they expand as 
%	IGETVs.
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
% REVISION HISTORY
%	07/19/85 BAF -- File created.
%	01/26/89 BAF -- Added predicate and constructor macros so that 
%			this code can replace the RLISP record code. 
%			Changed  GetR to StructFetch, and !*FAST-RECORDS 
%			to !*FAST-STRUCTS.  Added code to check the 
%			validity of the options.  Also added this file 
%			header.
%	01/30/89 BAF -- Added CONC-NAME as a synonym for SLOT-PREFIX and 
%			the ExplodeId function for compatability with 
%			existing programs (eg. ernie).
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(flag1 'defstruct 'eval)


(bothtimes (fluid '(!*fast-structs)))


(dm defstruct (u)
    (let* ( (options (get_defstruct_options (cadr u)))
	    (slot_forms (for (in slot (safecdr (cdr u)))
			     (collect (if (idp slot)
					  (list slot nil)
					  slot)
			     )))
	    (name (car options))
	    (slot_prefix (safecdr (atsoc 'slot-prefix (cdr options)) ))
	    (predicate (safecdr (atsoc 'predicate (cdr options)) ))
	    (constructor (safecdr (atsoc 'constructor (cdr options)) ))
	    (functions (list nil)) )
	(if constructor
	    (tconc functions
		   (build_defstruct_constructor_macro name
						      constructor
						      slot_forms
						      (not (null predicate))
							    )))
	(if predicate
	    (tconc functions (build_defstruct_predicate_function name
				 predicate)) )
	(for (in slot slot_forms)
	     (from index (if predicate 1 0) 8000)
	     (do (tconc functions
			(build_defstruct_accessor_macro slot_prefix
							(car slot)
							index))
	     ))
	(tconc functions (mkquote name))
	(cons 'progn (car functions))
    ))


(de get_defstruct_options (u)
    (prog (name options slot_prefix predicate constructor)
	(cond ((pairp u)
		 (setq name (car u))
		 (setq options (cdr u)) )
	      (t (setq name u)
		 (setq options nil) ))
	(if (not (idp name))
	    (error 0 (list "bad defstruct name:" name)) )
	(for (in entry options)
	     (do (cond ((memq entry '(slot-prefix prefix conc-name))
			  (setq slot_prefix (compress (append (explode name)
							 '(!! !-) )) ) )
		       ((and (pairp entry)
			     (memq (car entry) '(slot-prefix prefix
						    conc-name)))
			  (setq slot_prefix (compress (explodeid
							 (cadr entry)))))
		       ((eq entry 'predicate)
			  (setq predicate
			    (intern (compress (append (explode name)
							      '(p) ))) ) )
		       ((eqcar entry 'predicate)
			  (setq predicate (cadr entry)) )
		       ((eq entry 'constructor)
			  (setq constructor
				(intern (compress (append '(m a k e !! !-)
						      (explode name) ))) ) )
		       ((eqcar entry 'constructor)
			  (setq constructor (cadr entry)) )
		       (t (error 0 (list "bad defstruct option:" entry)) )
		 )))
	(if (null constructor)
	    (setq constructor (intern (compress (append '(m a k e !! !-)
						      (explode name) ))) ))
	(return (list name (cons 'slot-prefix slot_prefix)
			   (cons 'predicate predicate)
			   (cons 'constructor constructor)) )
    ))


(de explodeid (x)
    (cond ((idp x)
	     (explode x) )
	  (t (foreach elt in (explode2 x) join (list '!! elt)) )) )


(de build_defstruct_constructor_macro (name macro_name slot_forms
					    has_predicate)
    (let ( (body `(for (in slot (quote ,slot_forms))
		       (with entry)
		       (collect
			    (if (setq entry (memq (car slot) (cdr u)))
				(cadr entry)
				(cadr slot) )
		       )) ) )
	(if has_predicate
	    (setq body `(cons (quote (quote ,name)) ,body)) )
	`(dm ,macro_name (u)
	     (cons 'vector ,body))
    ))


(de build_defstruct_predicate_function (name fnname)
    `(de ,fnname (x)
	(and (vectorp x)
	     (eq (quote ,name) (igetv x 0)) )) )


(de build_defstruct_accessor_macro (slot_prefix slot_name index)
    (let ( (macro_name (if slot_prefix
			   (intern (compress (append (explode slot_prefix)
						     (explode slot_name) )))
			   slot_name)) )
	`(dm ,macro_name (u)
	     (list (quote structfetch) (cadr u) ,index) )
    ))


(dm structfetch (u)
    (if !*fast-structs
	(cons 'igetv (cdr u))
	(cons 'getv (cdr u))
    ))
