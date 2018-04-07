%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:OBJ-DMETHOD.SL 
% Description:  Code for Defining an Object Method 
% Author:       Mike Creech, HP/CRC 
% Created:      21-Feb-84 
% Modified:     05-Sep-84 09:16:01 (Brian Beach)
% Package:      Utilities 
% Status:       Open Source: BSD License
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
%  2-Sep-88 (Russ Fish)
%   Function needed rather than ' in bottom level definer so things are
%   compiled.
% 19-May-87 (Russ Fish)
%   Another fix to &substitute-for-symbols: Needs to know about the variables
%   that are bound by prog and lambda special forms. 
% 16-Dec-85 10:04:20 (Russ Fish)
%   Fix &substitute-for-symbols.  Due to possible collisions between slot
%   names and functions with the same names, it needs to know more about
%   special forms a la macroexpand to avoid wiping out function names with
%   (egetv self nnn) substitutions.
% 27-Apr-84 13:52:38 (Mike Creech)
%   Comment changes and removed &build-method, &decide-on-method-searching-algorithm,
%   and &which-method-fetcher to obj-lib.sl.
% 26-Apr-84 09:41:07 (Mike Creech)
%   Changed and added some comments. Removed &flavor-define-method and moved
%   code into &build-method.  Fixed &substitute-myself to check that 'myself' is
%   not quoted before substituting.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Other Files of Interest:
%
% The object package consists of the files:
%     objects.sl      - Top level file that loads everything necessary to use objects.
%     obj-const.lap   - List of constants used by all object modules.
%     obj-dflavor.sl  - Code for defining a new type of object.
%     obj-dmethod.sl  - Code for defining a new method.
%     obj-hash.sl     - Code for hashing scheme used for method - function association 
%                       and instance variable - evector position.
%     objinstance.sl  - Code for making instances of objects.
%     obj-lib.sl      - Library of miscellaneous functions. Some are
%                       used by two or more object package files.
%     obj-send.sl     - Code for sending messages, tracing messages, and 
%                       creating the correct method fetching scheme (at runtime
%                       in the users program).
%     
% Because this file is only part of the object package, it only needs to load what
% is necessary to compile it.  objects.sl takes care of stuff needed at loadtime.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% Summary of Public Functions:
%   
% (defmethod (flavor-name message-name) (arg1 arg2 ...) form1 form2 ...)
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Calling Tree
%     defmethod
%         &defflavor-function-name (obj-lib.sl)
%         &create-method-source-code
%             &substitute-for-symbols
%                 &object-lookup-variable-in-list (obj-lib.sl)
%             &substitute-myself
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Allow for fast integer operations.
(compiletime   (load numeric-ops))
% Allow for use of fast vector-fetch and vector-store.
(compiletime   (load f-vectors))
% Allow for evector operations.
(compiletime   (load f-evectors))
% Allow use of mutable association list functions -- association-create
% and association-bind.
(compiletime (load association))

(compiletime (on fast-evectors fast-integers fast-vectors))

(fluid '($defflavor-expansion-context
	 ))

(setf $defflavor-expansion-context NIL)

% Make the constants available at compile time only.
% For the ability to interpret object routines that refer to these constants,
% dskin these in when interpreting.

(compiletime (load obj-const))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% DEFMETHOD - Define a method on an existing flavor.
%   
% Examples:
%
% (defmethod (complex-number real-part) ()
%   real-part)
%
% (defmethod (complex-number set-real-part) (new-real-part)
%   (setf real-part new-real-part))
%
% The body of a method can freely refer to the instance variables of the flavor
% and can set them using SETF.  Each method defines a function FLAVOR$METHOD
% whose first argument is SELF, the object that is performing the method.  All
% references to instance variables (except within vectors or quoted lists) are
% translated to an invocation of the form (EGETV SELF n).
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(defmacro defmethod ((flavor-name method-name) argument-list . body)

  % When a method is redefined and no changes have occurred to the state
  % of the world that would change which algorithm is used for method
  % fetch, the code-pointer slot is left alone.  If an algorithmic
  % change is necessary or a new method is defined, the code-pointer
  % is set to the method fetch controller (&control-of-method-fetch).
  %     For details on method definition, see PIG:OBJ-SPEC.IBM.

  (unless
         (idp flavor-name)
	 % THEN Invalid flavor.
	 (StdError "DEFMETHOD: invalid flavor name"))
  (unless
         (idp method-name)
	 % THEN Invalid method.
	 (StdError "DEFMETHOD: invalid method name"))
  % Check that arguments to the methods are a list of ids.
  (unless
         (and (listp argument-list)
	      (for (in x argument-list)
		   (always (idp x))))
	 % THEN
	 (StdError "DEFMETHOD: invalid argument list"))

  % Now check that no instances variables overlap arguments for the method.

  (if
     (&defining-flavor? flavor-name)
     % THEN We know we are at least in the middle of defining this object .
     (unless
            (for
	        (with (variable-names (get flavor-name '*variable-names*)))
		(in argument argument-list)
		(never (memq argument variable-names))
		)
	    % THEN
	    (StdError "DEFMETHOD: An argument was found that matches an instance variable.")
	    )
     % ELSE We don't have an object.
     (StdError (BldMsg "DEFMETHOD: Undefined flavor %w." flavor-name))
     )

  (setf argument-list (cons 'self argument-list))
  (let
      ((function-name (&defflavor-function-name flavor-name method-name))
       (source-code `(lambda ,argument-list . ,body)))

      % 'source-code' as a property may be used in the future, but not now.
      % (put function-name 'source-code `(lambda ,argument-list . ,body))

      % For inheritance to work at compile time the method table must exist at
      % load time and compile time! The following line adds the method at 
      % compile time.  During non FASL time (interpreted or compile in memory)
      % the PROGN below ends up duplicating the work done here.
      % This is unavoidable without a flag to tell if we are FASLing or not.

      (&build-method flavor-name method-name function-name)
      
      (let 
          ((new-code (&create-method-source-code function-name
						 flavor-name
						 source-code)))

	  % The previous actions happen at compile or dskin time.
	  % The following actions happen at dskin or load time.
          % All the progn contents below can not be placed into the
	  % &build-method routine because we want the functions that
	  % define the methods to be defined at compile time for 
	  % when we compile into a binary -- progn's are
	  % treated specially.
	  `(progn
		 (&build-method ',flavor-name 
				',method-name
				',function-name)
		 (putd ',function-name 'expr (function ,new-code))
		 % Return value for documentation only.
		 '(method ,flavor-name ,method-name)		 
		)
	  )
      )
  )

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Internal Functions (to the object package)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de &substitute-for-symbols (U var-names)

  % Substitute in U for all unquoted instances of the symbols defined in
  % Var-Names.  Also, change SETQ to SETF in forms, since only SETF can handle
  % the substituted forms.

  (cond
   ((IdP U)
    (let ((address (&object-lookup-variable-in-list var-names U)))
      (if address (list 'egetv 'self address) U)
      ))
   ((PairP U)
    (cond
     ((eq (car U) 'quote) U)
     ((eq (car U) 'setq)   % Convert setq to setf so instance vars can be set.
      (&substitute-for-symbols (cons 'setf (cdr U)) var-names))
     ((or (eq (car U) 'lambda) (eq (car U) 'prog))
      (let ((var-names       % Remove the locals from the substitution list.
	     (for (in X var-names)
		  (conc (cond ((memq X (cadr U)) NIL)
			      (T (list X)))))))
	(cons (car U)   % Don't substitute in first two of lambda and progn.
	      (cons (cadr U)
		    (for (in V (cddr U))
			 (collect (&substitute-for-symbols V var-names)))))))
     ((eq (car U) 'cond)
      (cons 'cond		    % Cond is special, has list of form lists.
	    (for (in V (cdr U))
		 (collect
		     (for (in W V) 
			  (collect (&substitute-for-symbols W var-names)))))))
     ((eqcar (car U) 'lambda)
      (for (in V U)		     % Lambda being applied, examine its body.
	   (collect (&substitute-for-symbols V var-names))))
     (t (cons (car U)		% Don't substitute in the car of normal forms.
	      (for (in V (cdr U))
		   (collect (&substitute-for-symbols V var-names)))))
     )
    )
   (t U)
   ))


(de &substitute-myself (u)

    % Traverse entire form u subsitituting self for myself (when not quoted).
    % Do this after send macro expanded and before varable names are substituted.

    (cond
         ((idp u) (if
		     (eq u 'myself)
		     % THEN substitute to self.
		     'self
		     % ELSE return u.
		     u))
	 ((pairp u) (if
		       (eq (car u) 'quote)
		       % THEN return u
		       u
		       % ELSE check to substitute all pieces of this structure.
		       (cons (&substitute-myself (car u))
			     (&substitute-myself (cdr u)))
		       ))
	 (t u))
    )

(de &create-method-source-code (function-name flavor-name source-code)

    % The setting of the local version of $defflavor-expansion-context
    % is critical.  It sets the value of 'self' and is used when
    % send messages are expanded in the 'macroexpand'.
    % NOTE: Is fuction-name used for anything anymore?

    (let
        ((var-names (get flavor-name '*variable-names*))
	 ($defflavor-expansion-context flavor-name)) % FLUID variable!

	(&substitute-for-symbols  
	            (&substitute-myself (MacroExpand source-code))
		    var-names)
	))

(compiletime (off fast-evectors fast-integers fast-vectors))

% End of file.
