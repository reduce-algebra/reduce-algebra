%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:PUTD-GETD.SL 
% Title:        Standard Lisp function defining functions 
% Author:       Eric Benson 
% Created:      18 August 1981 
% Modified:     31-May-84 10:51:14 (Brian Beach) 
% Status:       Open Source: BSD License
% Mode:         Lisp 
% Package:      Kernel 
% Compiletime:  
% Runtime:      
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
% 29-Sep-91 (Herbert Melenk)
%  DOS: compile putd calls for nonkernel and kernel functions
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

(de getd (func)
    % Lookup function definition of func.
    (and
	(idp func)
	(not (funboundp func))
	(cons (or (get func 'type)
		  'expr)
	      (if
		 (or
		    (flambdalinkp func)
		    (and (flagp func 'planttrampoline)
			 (get func '*lambdalink)))
		 (get func '*lambdalink)
		 (getfcodepointer func)))))

(compiletime (flag '(getd0) 'internalfunction))

(de getd0 (func)
    % internal: Lookup function definition of func.
    (and
	(idp func)
	(not (funboundp func))
	(cons (or (get func 'type)
		  'expr)
	      (if
		 (flambdalinkp func)
		 (get func '*lambdalink)
		 (getfcodepointer func)))))


(de remd (func)

    % Remove function definition of func.

    (let
	((oldgetd (getd func)))
	(when (and oldgetd
		   (codep (cdr oldgetd))
		   (wlessp (inf (cdr oldgetd)) nonkernelupperbound*)
			)
		   (flag1 func 'planttrampoline)
		 )
	
	(when
	     oldgetd
	     % THEN There was an old definition.
	     (makefunbound func)
	     (remprop func 'type)
	     (remprop func '*lambdalink))
	% Return the old definition.
	oldgetd)
    )

(fluid '(*redefmsg % controls printing of redefined
	 *usermode % controls query for redefinition
	 nonkernelupperbound*  % high address in bps
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
  % -   "      "   which are already fluid or global are defined anyway,
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
		  u
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
		 (when (and (setq u (getd fnname))
			    (codep (cdr u))
			    (wlessp (inf (cdr u)) 
				    nonkernelupperbound*)
			)
			(flag1 fnname 'planttrampoline)
		 )
		 
		 (cond
		      ((codep fnexp) (makefcode fnname fnexp)
				     (remprop fnname '*lambdalink))
		      ((and (idp fnexp)
			    (not (funboundp fnexp)))
		       (return (putd fnname fntype (cdr (getd fnexp)))))
		      (*comp
			    (return (compd fnname fntype fnexp)))
		      ((and (flagp fnname 'planttrampoline)
			    (eqcar fnexp 'lambda))
			(planttrampoline fnname (length (cadr fnexp)))
			(put fnname '!*lambdalink fnexp)
		       )
			    
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
		    (put fnname 'type fntype)
		    % ELSE
		    (remprop fnname 'type))

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

(de trampoline()(compiledcallinginterpreted))
 
(compiletime (put 'put_a_halfword 'opencode '(
   (mov (reg ebx) (displacement (reg eax) 0))))))

(de planttrampoline(u p)
   % install an indirect call to compiledcallinginterpreted
   (let ((m (gtbps 4))
	 (n (id2int u))
	 %  (p (getmem (wdifference (inf (cdr (getd u))) 4)))
	 (a (inf (cdr (getd 'trampoline)))) )
	(putmem  m p)
	(putmem (wplus2 m 8) (getmem a))
	(putmem (wplus2 m 16) (getmem (wplus2 a 8)))
	(put_a_halfword (wplus2 m 11) n)
	   % now plant it
	(setf (getmem (wplus2 symfnc (wtimes2 n 8))) (wplus2 m 8))
	  ))

(setq nonkernelupperbound!* (inf(cdr(getd 'putd))))
