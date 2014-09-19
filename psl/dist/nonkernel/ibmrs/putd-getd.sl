%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:PUTD-GETD.SL 
% Title:        Standard Lisp function defining functions 
% Author:       Eric Benson 
% Created:      18 August 1981 
% Modified:     31-May-84 10:51:14 (Brian Beach) 
% Status:       Experimental 
% Mode:         Lisp 
% Package:      Kernel 
% Compiletime:  
% Runtime:      
%
% (c) Copyright 1983, Hewlett-Packard Company, all rights reserved.
% (c) Copyright 1981, University of Utah
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 22-August-1990 (Winfried Neun)
%  TYPE information is put into SYMGET vector (slot 0) to spped up
%  (get fn 'type) in eval
% 01-Oct-88 (Tony Hearn)
%  Replaced single use of flag1/remflag1 by flag/remflag to make module
%  less dependent on non-SL functions.
% 23-May-84 16:16:15 (Mike Creech)
%  Rewrote code-number-of-arguments to deal with functions that were
%  defined to have any number of arguments (-1 in *entry definition).
%  Reformatted PUTD to make more readable.
%  Rewrote remd to be more readable.
%  Reformatted getd to be more readable (and changed u => func).
% 01-Dec-83 14:59:44 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(symget &symgetsize&))

(setq &symgetsize& 32)                  % default

(de getd (func)

    % Lookup function definition of func.

    (and
        (idp func)
	(not (funboundp func))
	(cons (or (get func 'type)
		  'expr)
	      (if
		 (flambdalinkp func)
		 % THEN
		 (get func '*lambdalink)
		 % ELSE
		 (mkcode (getfcodepointer func))))))

(de remd (func)

    % Remove function definition of func.

    (let
        ((oldgetd (getd func)))
	(when
	     oldgetd
	     % THEN There was an old definition.
	     (makefunbound func)
	     (remprop func 'type)
	     (when (wgetv SYMGET (idinf func))
		(wputv (inf (wgetv SYMGET (idinf func))) 1 NIL))
			 % Anull slot 0 in SYMGET entry
	     (remprop func '*lambdalink))
	% Return the old definition.
        oldgetd)
    )

(fluid '(*redefmsg % controls printing of redefined
	 *usermode % controls query for redefinition
	 ))

(loadtime
  (progn (setq *usermode nil)  % start in system mode
         (setq *redefmsg t)    % message in PutD
	 ))

(fluid '(*comp % controls automatic compilation
	 promptstring*))

(de code-number-of-arguments (code-pointer)

    % Return the number of arguments within the range 0-maxargs, or
    % "any" if function is setup to have any number of arguments, or
    % NIL if not a code-pointer or too many arguments.

    (when
         (codep code-pointer)
	 % THEN We have a real codepointer.
	 (let
	     ((num-args (!%code-number-of-arguments (codeinf code-pointer))))
	     (cond
	          ((weq num-args -1) "any")
		  ((and (wgeq num-args 0)
			(wleq num-args maxargs)) num-args)
		  (t NIL)
		  )
	     )
	 )
    )


(de putd (fnname fntype fnexp)

  % Install function definition
  %
  % this differs from the SL Report in 2 ways:
  % - function names flagged LOSE are not defined.
  % - 	"      "   which are already fluid or global are defined anyway,
  % with a warning.
  %

  (cond ((not (idp fnname)) (noniderror fnname 'putd))
        ((not (memq fntype '(expr fexpr macro nexpr)))
         (conterror 1305 "%r is not a legal function type" fntype
                    (putd fnname fntype fnexp)))
        ((flagp fnname 'lose)
         (errorprintf "*** %r has not been defined, because it is flagged LOSE"
                      fnname)
         nil)
        (t (prog (vartype
		  printredefinedmessage
		  oldin
		  promptstring*
                  queryresponse)
                 (unless
		       (funboundp fnname)
		       % THEN
		       (when
			    *redefmsg
			    % THEN
			    (setq printredefinedmessage t))
		       (when
			    (and *usermode
				 (not (flagp fnname 'user)))
			    % THEN
			    (if
			       (not (yesp (bldmsg
                        "Do you really want to redefine the system function %r?"
                                                  fnname)))
			       % THEN
			       (return nil)
			       % ELSE
			       (flag1 fnname 'user))))
                 (cond
		      ((codep fnexp) 
				     (makefcode fnname fnexp)
		                     (remprop fnname '*lambdalink))
		      ((and (idp fnexp)
			    (not (funboundp fnexp)))
		       (return (putd fnname fntype (cdr (getd fnexp)))))
		      (*comp
		            (return (compd fnname fntype fnexp)))
		      ((eqcar fnexp 'lambda)
                                            (put fnname '*lambdalink fnexp)
					    (makeflambdalink fnname))
		      (t
                        (return
                               (conterror 1105
				  "Ill-formed function expression in PutD"
					  (putd fnname fntype fnexp)
					  )
			       )
			)
		      )

                 (if
		    (neq fntype 'expr)
		    % THEN
		    (progn (put fnname 'type fntype)
			   (if (wgetv SYMGET (idinf fnname))
				(wputv (inf (wgetv SYMGET (idinf fnname)))
					 1 fntype)
				(wputv SYMGET (idinf fnname)
					(mkvect &symgetsize&))
				(wputv (inf (wgetv SYMGET (idinf fnname)))
					 1 fntype)))
		    % ELSE
		    (remprop fnname 'type)
                    (when (wgetv SYMGET (idinf fnname)) 
                           (wputv (inf (wgetv SYMGET (idinf fnname))) 1 NIL)))

                 (if
		    *usermode
		    (flag (list fnname) 'user)
		    (remflag (list fnname) 'user))

		 (when
		      printredefinedmessage
		      % THEN
		      (errorprintf "*** Function %r has been redefined"
				   fnname))
                 (return fnname)
		 )
	   )
	)
  )

