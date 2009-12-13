%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:OBJ-SEND.SL 
% Description:  Message Sending Object Code 
% Author:       Mike Creech, HP/CRC 
% Created:      21-Feb-84 
% Modified:     5 Mar 1985 1507-PST (Brian Beach)
% Package:      Utilities 
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
% 27-Feb-85 17:43:23 (Mike Creech)
%  Changed &primitive-type-call to take an extra argument that specifies
%  whether an error message should be issued. This is to fix a bug with
%  SEND-IF-HANDLES not returning NIL is an object is NOT given.
%  Changed &check-for-primitive-types to use this new &primitive-type-call.  
% 13-Jul-84 10:08:43 (Mike Creech)
%  Changed object-get-handler and object-get-handler-quietly to deal with primitive
%  types.  This includes the addition of &check-for-primitive-types and
%  &primitive-type-call.
% 11-Jul-84 16:07:43 (Mike Creech)
%  Added correct setting of flags *plap, *pgwd, and *pcmac in
%  &build-and-attach-method-hash-table. Made all routines that object-get-handler
%  calls be consistent with it as far as passing parameters.  All such routines
%  are passed the object information vector followed by the message name.
%  This involves changes to object-get-handler, object-get-handler-quietly,
%  &control-of-method-fetch, &build-hash-method-fetcher,
%  &make-and-attach-method-hash-table, &build-cond-method-fetcher, and
%  &return-fast-cond-body.
%  These changes will make message sending somewhat more efficient and conisistent
%  and allow for sending messages to other data types.
% 10-Jul-84 16:10:01 (Mike Creech)
%  Added to &klude-cont-error to print more intelligent error messages.
% 25-Apr-84 20:35:24 (Mike Creech)
%  Added deactivation of *usermode to &build-cond-method-fetcher.
%  Changed 'apply' in send-if-handles to 'idapply'
% 13 Apr 1984 1546-PST (Nancy Kendzierski)
%  Removed load of fast-c-apply.
% 29-Mar-84 13:38:25 (Mike Creech)
%  Removed FAST-CODEAPPLY and references to IDAPPLY2.  Replaced with
%  references to smart CODEAPPLY and IDAPPLY.
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Declare the global instances used to send primitve types messages efficiently.
(fluid 
      '(*$&null-moosefish-object&$*
	*$&pair-moosefish-object&$*
	*$&int-moosefish-object&$* 
	*$&float-moosefish-object&$* 
	*$&vector-moosefish-object&$*
	*$&string-moosefish-object&$*
	*$&symbol-moosefish-object&$*)
      )
% Allow for fast integer operations.
(compiletime   (load numeric-ops))
% Allow for use of fast vector-fetch and vector-store.
(compiletime   (load f-vectors))
% Allow for use of evector operations.
(compiletime   (load f-evectors))
% Allow use of mutable association list functions -- association-create
% and association-bind.
(compiletime   (load association))

(compiletime (on fast-evectors fast-integers fast-vectors))


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% Summary of Public Functions:
%   
% (=> foo message-name arg1 arg2 ...)
%
% (send foo 'message-name arg1 arg2 ...)
% (lexpr-send foo 'message-name arg1 arg2 ... rest-arg-list)
% (lexpr-send-1 foo 'message-name arg-list)
% (ev-send foo 'message-name arg-list) {EXPR form}
%
% (send-if-handles foo 'message-name arg1 arg2 ...)
% (lexpr-send-if-handles foo 'message-name arg1 arg2 ... rest-arg-list)
% (lexpr-send-1-if-handles foo 'message-name arg-list)
% (object-get-handler x message-name) -- lookup method function (see below)
% (object-get-handler-quietly x message-name)
%
% (trace-method-lookups) - start recording stats about method lookup
% (untrace-method-lookups) - stop recording stats about method lookup
% (print-method-lookup-info) - untrace and print accumulated stats
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Calling Tree 
%    =>
%        send
%            &self-send-expansion
%                &defflavor-function-name        (obj-lib.sl)
%            &direct-send-expansion
%                &defflavor-function-name        (obj-lib.sl)
%            &normal-send-expansion
%                &return-apply-part
%                    object-get-handler
%                        &check-for-primitive-types
%                            &primitive-type-call
%                            &kludge-cont-error
%                                 extended-object-type  (obj-lib.sl)
%                        &kludge-cont-error
%
%    &control-of-method-fetch
%        &which-method-fetcher                   (obj-lib.sl)
%        &build-cond-method-fetcher
%            &return-fast-cond-body
%                &check-fast-access-method-list
%                &make-and-attach-method-hash-table
%                    &make-method-hash-table     (obj-hash.sl)
%                    &method-hash-put            (obj-hash.sl)
%                &method-hash-get                (obj-hash.sl)
%            &compute-size-of-cond
%        &build-hash-method-fetcher
%            &make-and-attach-method-hash-table
%                &make-method-hash-table     (obj-hash.sl)
%                &method-hash-put            (obj-hash.sl)
%            &method-hash-get                (obj-hash.sl)
%                

(fluid '($defflavor-expansion-context
	 $method-lookup-stats
	 ))

(setf $defflavor-expansion-context NIL)

% Make the constants available at compile time only.
% For the ability to interpret object routines that refer to these constants,
% dskin these in when interpreting.

(compiletime (load obj-const))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% => - Convenient form for sending a message
%   
% Examples:
%
% (=> r real-part)
%
% (=> r set-real-part 1.0)
%
% The message name is not quoted.  Arguments to the method are supplied as
% arguments to =>.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(defmacro => (object message-name . arguments)
  `(send ,object ',message-name . ,arguments))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% SEND - Send a Message (Evaluated Message Name)
%   
% Examples:
%
% (send r 'real-part)
%
% (send r 'set-real-part 1.0)
%
% Note that the message name is quoted.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(defmacro send (target-form method-form . argument-forms)

  % If the method name is known at compile time (i.e., the method-form is of
  % the form (QUOTE <id>)) and the target is either SELF (within the body of a
  % DEFMETHOD) or a variable which has been declared (using DECLARE-FLAVOR),
  % then optimize the form to a direct invocation of the method function.
  % Argument example:
  %     (send foo 'buggy 3)
  %         target-form = foo
  %         method-form = buggy
  %         argument-forms = (3).
  % The send is expanded into a direct function call like (nose$buggy 3) or
  % into a call to object-get-handler (see example in &normal-send-expansion).

  (if
     % First check if the method-form is of the form (QUOTE BUGGY).
     (and (PairP method-form)
	  (eq (car method-form) 'quote)
	  (cdr method-form)
	  (IdP (cadr method-form)))
     % THEN
     (let
	 % method-name will be BUGGY.
	 ((method-name (cadr method-form)))
	 (cond
	      % $defflavor-expansion-context is a fluid variable that is non-NIL
	      % (the name of the falvor we are in) when we are in a defmethod.

	      % We have a SELF optomization.
 	      ((and (eq target-form 'self) $defflavor-expansion-context)
	       (&self-send-expansion method-name argument-forms))

	      % DECLARE optomization.
	      ((and (IdP target-form) (get target-form 'declared-type))
	       (&direct-send-expansion target-form method-name argument-forms))

	      % No optomization.
	      (t (&normal-send-expansion target-form method-form argument-forms))
	      ))
     % ELSE We have a normal expression.
     (&normal-send-expansion target-form method-form argument-forms)
     ))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% SEND-IF-HANDLES - Conditionally Send a Message (Evaluated Message Name)
%   
% Examples:
%
% (send-if-handles r 'real-part)
%
% (send-if-handles r 'set-real-part 1.0)
%
% SEND-IF-HANDLES is like SEND, except that if the object defines no method
% to handle the message, no error is reported and NIL is returned.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(defmacro send-if-handles (object message-name . arguments)

    % If 'object' is an ID, generate a simpler form that doesn't have
    % the setting of a variable to object.

    (if
       (idp object)
       % THEN Generate the simple form.
       `(let
	    ((***HANDLER*** (object-get-handler-quietly ,object ,message-name)))
	    (when
	         ***HANDLER*** 
		 (idapply ***HANDLER*** (list ,object ,@arguments))))
       % ELSE Generate the general form.
       `(let*
	     ((***SELF*** ,object)
	      (***HANDLER*** (object-get-handler-quietly ***SELF*** ,message-name)))
	     (when ***HANDLER*** (idapply ***HANDLER*** (list ***SELF*** ,@arguments))))
       )
    )

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% LEXPR-SEND - Send a Message (Explicit "Rest" Argument List)
%   
% Examples:
%
% (lexpr-send foo 'bar a b c list)
%
% The last argument to LEXPR-SEND is a list of the remaining arguments.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(defmacro lexpr-send (object message-name . arguments)
  (if arguments
    (let ((explicit-args (reverse (cdr (reverse arguments))))
	  (last-arg (LastCar arguments))
	  )
      (if explicit-args
        `(lexpr-send-1 ,object ,message-name
		       (append (list ,@explicit-args) ,last-arg))
	`(lexpr-send-1 ,object ,message-name ,last-arg)
	)
      )
    `(let ((***SELF*** ,object))
       (apply (object-get-handler ***SELF*** ,message-name)
	      (list ***SELF***)))
    ))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% LEXPR-SEND-IF-HANDLES 
%   
% This is the same as LEXPR-SEND, except that no error is reported
% if the object fails to handle the message.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(defmacro lexpr-send-if-handles (object message-name . arguments)
  (if arguments
    (let ((explicit-args (reverse (cdr (reverse arguments))))
	  (last-arg (LastCar arguments))
	  )
      (if explicit-args
        `(lexpr-send-1-if-handles ,object ,message-name
				  (append (list ,@explicit-args) ,last-arg))
	`(lexpr-send-1-if-handles ,object ,message-name ,last-arg)
	)
      )
    `(let* ((***SELF*** ,object)
	    (***HANDLER***
	     (object-get-handler-quietly ***SELF*** ,message-name))
	    )
       (and ***HANDLER*** (apply ***HANDLER*** (list ***SELF***))))
    ))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% LEXPR-SEND-1 - Send a Message (Explicit Argument List)
%   
% Examples:
%
% (lexpr-send-1 r 'real-part nil)
%
% (lexpr-send-1 r 'set-real-part (list 1.0))
%
% Note that the message name is quoted and that the argument list is passed as a
% single argument to LEXPR-SEND-1.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(defmacro lexpr-send-1 (object message-name argument-list)
  `(let ((***SELF*** ,object))
     (apply (object-get-handler ***SELF*** ,message-name)
	    (cons ***SELF*** ,argument-list))))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% EV-SEND - EXPR form of LEXPR-SEND-1
%   
% EV-SEND is just like LEXPR-SEND-1, except that it is an EXPR instead of
% a MACRO.  Its sole purpose is to be used as a run-time function object,
% for example, as a function argument to a function.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de ev-send (obj msg arg-list)
  (lexpr-send-1 obj msg arg-list)
  )

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% LEXPR-SEND-1-IF-HANDLES
%   
% This is the same as LEXPR-SEND-1, except that no error is reported if the
% object fails to handle the message.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(defmacro lexpr-send-1-if-handles (object message-name argument-list)
  `(let* ((***SELF*** ,object)
	  (***HANDLER*** (object-get-handler-quietly ***SELF*** ,message-name))
	  )
     (and ***HANDLER*** (apply ***HANDLER*** (cons ***SELF*** ,argument-list)))
     ))


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Method Lookup
%
% The following functions return method functions given an object and a message
% name.  The returned function can be invoked, passing the object as the first
% argument and the message arguments as the remaining arguments.  For example,
% the expression (=> foo gorp a b c) is equivalent to:
%
%   (apply (object-get-handler foo 'gorp) (list foo a b c))
%
% It can be useful for efficiency reasons to lookup a method function once and
% then apply it many times to the same object.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de object-get-handler (object message-name)

    % Returns the name of the function that implements the specified
    % message (message-name) for the specified object (object).
    % If no such method exists, generate a continuable error.
    % NOTE: This function is critical for the speed of message passing.
    %       As a result, many things have been put "in-line" at the expense
    %       of readability.
    %       The reference to codeapply below optimizes to fast opencode.
    %       The compiler optimizes the duplicate egetv's and places them into
    %       a register.  DON'T replace with a let or anything like it.
    %       Or you will slow the code down.

    (if
       (evectorp object)
       % THEN We have a legitimate object.
       (or
	  (codeapply (vector-fetch (egetv object
					  (CONST $FAST-OBJECT-INFO-SLOT))
				   (CONST $CODE-POINTER-SLOT))
		     (list  (egetv object
				   (CONST $FAST-OBJECT-INFO-SLOT))
			    message-name))
	  (&kludge-cont-error object message-name)
	  )
       % ELSE Check if we are sending a message to other lisp data types.
       %      If there aren't any, print an error message.
       (&check-for-primitive-types object message-name T)
       )
    )

(de object-get-handler-quietly (object message-name)

    % Returns the method function that implements the specified message when sent
    % to the specified object, if it exists, otherwise returns NIL.
    % NOTE: The reference to codeapply below optimizes to fast opencode.

    (if
       (evectorp object)
       % THEN We have a legitimate object.
       (codeapply (vector-fetch (egetv object
				       (CONST $FAST-OBJECT-INFO-SLOT))
				(CONST $CODE-POINTER-SLOT))
		  (list  (egetv object
				(CONST $FAST-OBJECT-INFO-SLOT))
			 message-name))
       % ELSE Check for primitive types.  If there aren't any return NIL.
       (&check-for-primitive-types object message-name NIL)
       )
    )

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Method Lookup Tracing
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de trace-method-lookups ()

    % Begin accumulating information about method lookups (invocations of
    % object-get-handler).  The statistics are reset.

    (setf $method-lookup-stats (association-create))
    (copyd 'object-get-handler '&traced-object-get-handler)
    )

(de untrace-method-lookups ()

    % Stop accumulating information about method lookups.

    (copyd 'object-get-handler '&untraced-object-get-handler)
    )

(de print-method-lookup-info ()

    % Stop accumulating information about method lookups and print a summary of
    % the accumulated information about method lookups.  This summary shows which
    % methods were looked up and how many times each method was looked up.

    (untrace-method-lookups)
    (load gsort stringx)
    (setf $method-lookup-stats (gsort $method-lookup-stats '&method-info-sortfn))
    (for (in pair $method-lookup-stats)
	 (do (printf "%w  %w%n"
		     (string-pad-left (bldmsg "%w" (cdr pair)) 6)
		     (car pair))))
    )


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Internal Functions (to the object package)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de &kludge-cont-error (object message-name)
  
    % This functions sole purpose is to speed up 'object-get-handler' by
    % cutting the number of parameters that are stored if 'conterror'
    % were found in 'object-get-handler' directly.  This is about a 10%
    % savings in speed for sending messages!

    (if
       (or (evectorp object)
	   (null object)
	   (pairp object)
	   (vectorp object)
	   (idp     object)
	   (stringp object)
	   (fixp    object)
	   (floatp  object))
       % THEN we really have user defined or primitive type.
       (ContError 1000
	          "Flavor %w has no method %w."
		  (extended-object-type object)
		  message-name
		  (object-get-handler object message-name)
		  )
       % ELSE We don't have an object.
       (conterror 1001
		  "Trying to send a message to %w which is not an object."
		  object
		  (object-get-handler object message-name)
		  )
       )
    )

(de &primitive-type-call (object-info message-name object error-message?)

    % Invoke the appropriate method for primitive types.
    % Only print an error message if error-message? is non-nil.

    (or
       (codeapply (vector-fetch object-info (CONST $CODE-POINTER-SLOT))
		  (list object-info message-name))
       (when
	    error-message?
	    % THEN Issue an error.
	    (&kludge-cont-error object message-name))
       )
    )

(de &check-for-primitive-types (object message-name error-message?)

    % Hook for HPSL non-user defined types.
    % If error-message? is non-nil, print an error message if the given object
    % is not a primitive type.
    % NOTE: The check of fixp also catches bignums when they are loaded.

    (cond
	 ((null object) (&primitive-type-call
			     (egetv *$&NULL-MOOSEFISH-OBJECT&$*
				    (CONST $FAST-OBJECT-INFO-SLOT))
			     message-name object error-message?))
	 ((pairp object) (&primitive-type-call
			     (egetv *$&PAIR-MOOSEFISH-OBJECT&$*
				    (CONST $FAST-OBJECT-INFO-SLOT))
			     message-name object error-message?))
	 ((vectorp object) (&primitive-type-call
			     (egetv *$&VECTOR-MOOSEFISH-OBJECT&$*
				    (CONST $FAST-OBJECT-INFO-SLOT))
			     message-name object error-message?))
	 ((idp     object) (&primitive-type-call
			     (egetv *$&SYMBOL-MOOSEFISH-OBJECT&$*
				    (CONST $FAST-OBJECT-INFO-SLOT))
			     message-name object error-message?))
	 ((stringp object) (&primitive-type-call
			     (egetv *$&STRING-MOOSEFISH-OBJECT&$*
				    (CONST $FAST-OBJECT-INFO-SLOT))
			     message-name object error-message?))
	 ((fixp    object) (&primitive-type-call
			     (egetv *$&INT-MOOSEFISH-OBJECT&$*
				    (CONST $FAST-OBJECT-INFO-SLOT))
			     message-name object error-message?))
	 ((floatp  object) (&primitive-type-call
			     (egetv *$&FLOAT-MOOSEFISH-OBJECT&$*
				    (CONST $FAST-OBJECT-INFO-SLOT))
			     message-name object error-message?))
	 (t (when
	         error-message?
		 % THEN Print an error message.
		 (&kludge-cont-error object message-name)
		 )
	    )
	 )
    )

(de &normal-send-expansion (target-form method-form argument-forms)

    % This is the expansion of a normal call to a method (e.g.,
    % (=> FOO BUGGY 3)).  A check is made to see if the target form
    % is an ID.  If it is (as is FOO in (=> FOO BUGGY 3)), don't
    % generate a LET to save the evaluated object because it is
    % extra overhead.
    % For an example of send expansion, consider:
    %      (=> FOO BUGGY 3)
    % This would expand to:
    %      (IDAPPLY (OBJECT-GET-HANDLER FOO (QUOTE BUGGY)) (LIST FOO 3))
    % If the flavor name is not an ID, as in:
    %      (=> (MEMQ LIST 'FOO) BUGGY 3)
    % The expansion would be:
    %      ((LAMBDA (***SELF***)
    %       (IDAPPLY (OBJECT-GET-HANDLER ***SELF*** (QUOTE BUGGY))
    %                (LIST ***SELF*** 3)))
    %	    (MEMQ LIST (QUOTE FOO)))

    (if
       (idp target-form)
       % THEN Return without LET.
       (&return-apply-part target-form method-form argument-forms)
       % ELSE Return with LET.
       `(let
	    ((***SELF*** ,target-form))
	    ,(&return-apply-part '***SELF*** method-form argument-forms)
       )))

(de &return-apply-part (object method arguments)

    % Return a fast opencoded IDAPPLY form if 13 or fewer arguments.  Otherwise
    % return a regular APPLY form.

    (if 
       (< (length arguments) 14)
       % THEN optimize to a fast opencoded idapply.
       `(idapply (object-get-handler ,object ,method)
		 (list ,object ,@arguments))
       % ELSE We can't optomize.  Use regular apply.
       `(apply (object-get-handler ,object ,method)
	       (list ,object ,@arguments))
       )
    )

(de &self-send-expansion (method-name argument-forms)

    % This is the expansion of a call to a method within an object from
    % within this same object (e.g., (=> SELF FOO)).
    % $defflavor-expansion-context is a fluid that holds the name of the flavor.
    % This function returns something of the form:
    %    (flavor$method-name argument-forms)

    (cons (&defflavor-function-name $defflavor-expansion-context method-name)
	  (cons 'self argument-forms)))

(de &direct-send-expansion (target-id method-name argument-forms)

    % This is the expansion of a call to a method that has been DECLARE'd.
    % This function returns something of the form:
    %    (target-id$method-name argument-forms)

    (let
        ((target-type (get target-id 'declared-type)))
	(cons (&defflavor-function-name target-type method-name)
	      (cons target-id argument-forms))))


(copyd '&untraced-object-get-handler 'object-get-handler)

(de &traced-object-get-handler (obj method-name)
  (let* ((result (&untraced-object-get-handler obj method-name))
	 (count (association-lookup $method-lookup-stats result))
	 )
    (association-bind $method-lookup-stats result (if count (+ count 1) 1))
    result
    ))


(de &control-of-method-fetch (object-info method-name)
  
    % Build the hash-table and replace the lookup function with
    % the hash lookup function or build a fast COND and replace
    % with the COND.  Currently, this routine is the lookup function.
    % A COND is used only if:
    %     The compiler is available (the COND MUST be compiled for
    %     the code pointer to be used) AND this object has been
    %     instructed to use a COND.
    %                    OR
    %     The compiler is available AND this object has <= 
    %     $MAX-COND-CLAUSES.
    % Object-info is the object information vector from the flavor name.
    % For all other cases, a hash table is created.
    % NOTE: This code will only work if we are guarenteed that
    %       the flavor has at least one method.  Mutable association
    %       list function (association-create) removes the 
    %       ((*DUMMY* . *DUMMY*)) when the first "real"
    %       item is put on the list.  
    % For a more global description of method sending, see obj-spec.ibm

    (let
        ((flavor-name (vector-fetch object-info
				    (CONST $FLAVOR-NAME-SLOT))))
	(if
	   (eq (&which-method-fetcher flavor-name) 'cond-method-fetcher)
	   % THEN Make a COND method fetch function.
	   (&build-cond-method-fetcher object-info  method-name)
	   % ELSE Make a hash-table method fetch function.
	   (&build-hash-method-fetcher object-info method-name)
	   )))

(de &build-hash-method-fetcher (object-info method-name)

    % Build the hash table for flavor-name and attach it to the right
    % part of '*fast-object-info* on the property list of flavor-name.
    % The table is built from the a-list *a-list-method-table* stored
    % on the property list of flavor-name.
    % When done, change the code pointer field of *fast-object-info*
    % so that &method-hash-get is called directly the next time a message is
    % sent.  After changing the code pointer, call &method-hash-get
    % directly to return the actual function (that represents the method).
    % object-info is the object information vector from the flavor name.
    % NOTE: This code will only work if we are guarenteed that
    %       the flavor has at least one method.  Mutable association
    %       list function (association-create) removes the 
    %       ((*DUMMY* . *DUMMY*)) when the first "real"
    %       item is put on the list.

    (let
        ((flavor-name (vector-fetch object-info
				    (CONST $FLAVOR-NAME-SLOT))))
	% Register which algorithm we are using.
	(put flavor-name '*last-method-fetcher* 'hash-method-fetcher)
	(&make-and-attach-method-hash-table object-info
					    (get flavor-name '*a-list-method-table*))

	)
    % Now change the code-pointer to point to &method-hash-get
    % so future messages sent will invoke it directly.
    (vector-store object-info
		  (CONST $CODE-POINTER-SLOT)
		  (cdr (getd '&method-hash-get)))
    
    % Now invoke &method-hash-get to return the function associated with the 
    % method.
    (&method-hash-get object-info method-name)
    )

(de &make-and-attach-method-hash-table (object-info method-table)

    % Build a method hash table filled with items from 'method-table'
    % and attach it to the *fast-object-info* vector stored under 
    % 'flavor-name'.

    (let
        ((hash-table (&make-method-hash-table)))
	(for
	    (in method-pair method-table)
	    (do
	       (&method-hash-put hash-table
				 (car method-pair)
				 (cdr method-pair))
	       )
	    )
	% Now attach the hash table to *fast-object-info*.
	(vector-store object-info
		      (CONST $METHOD-TABLE-SLOT)
		      hash-table)
	)
    )

(de &build-cond-method-fetcher (object-info method-name)

    % Build the cond function for flavor-name and attach its code pointer
    % to the right part of '*fast-object-info*' on the property list of
    % flavor-name. The cond is built from the a-list *a-list-method-table*
    % stored on the property list of flavor-name.
    % When done, the next time a message is sent, the cond will be called
    % directly.  Finally, call the fast COND directly to return the function
    % associated with the method.
    % NOTE: This code will only work if we are guarenteed that
    %       the flavor has at least one method.  Mutable association
    %       list function (association-bind) removes the 
    %       ((*DUMMY* . *DUMMY*)) when the first "real"
    %       item is put on the list.

    % Now get ready to define the COND.
    (let
        ((flavor-name (vector-fetch object-info (CONST $FLAVOR-NAME-SLOT)))
	 (is-compiling? *comp)
	 (old-*redefmsg *redefmsg)
	 (old-*usermode *usermode)
	 (old-*pwrds    *pwrds)
	 (old-*pcmac    *pcmac)
	 (old-*plap     *plap)
	 (old-*pgwd    *pgwd))

	% Register which algorithm we are using.
	(put flavor-name '*last-method-fetcher* 'cond-method-fetcher)

	% Remove the hash-table, to stop confusion, if it existed.
	(vector-store object-info 
		      (CONST $METHOD-TABLE-SLOT)
		      NIL)

	% Now define the COND method access function.
	% Since we know the compiler is loaded (checked before this
	% routine was called), compile the access function even
	% if user is interpreting and don't print redefine message or
	% fact that the function was compiled.
        (setf *comp     T)
	(setf *redefmsg NIL)
	(setf *usermode NIL)
	(setf *pwrds    NIL)
	(setf *pcmac    NIL)
	(setf *plap     NIL)
	(setf *pgwd    NIL)

	(putd '*object-cond-access-function*
	      'expr
	      `(lambda (object-info method-name)
		 (cond ,@(&return-fast-cond-body flavor-name 
						 object-info
						 (&compute-size-of-cond flavor-name)))))

        % Reset the state of compiling affairs.
	(setf *comp is-compiling?)
	(setf *redefmsg old-*redefmsg)
	(setf *usermode old-*usermode)
	(setf *pwrds    old-*pwrds)
	(setf *pcmac    old-*pcmac)
	(setf *plap     old-*plap)
	(setf *pgwd    old-*pgwd)

	% Now change the code-pointer to point to the fast COND function
	% so future messages sent will invoke it directly.
	(vector-store object-info
		      (CONST $CODE-POINTER-SLOT)
		      (cdr (getd '*object-cond-access-function*)))

	% Now invoke the fast COND to do an actual method fetch.
	(*object-cond-access-function* object-info method-name)
	)
    )

       
(de &compute-size-of-cond (flavor-name)
  
    % For efficiency, we combine a cond and a hash table based on the number
    % of methods the flavor has.  They are combined as follows:
    %    If the number of methods is <= $MAX-COND-CLAUSES then just
    %    make a cond.
    %    If the number of methods is <= (4 * $MAX-COND-CLAUSES) then
    %    make a cond with (2 * $MAX-COND-CLAUSES) and hash the rest.
    %    If the number of methods is > (4 * $MAX-COND-CLAUSES) then
    %    make a cond with $MAX-COND-CLAUSES and hash the rest.
    %
    % The reason we have the middle case is because it is believed that
    % access to more then half of the methods faster then hashing,
    % and with no collision possibility, is more efficient then
    % accessing all but $MAX-COND-CLAUSES at hashing speed with
    % up to the last half of methods faster.
    % This decision is quite arbitrary though, since the correct choice 
    % depends on the frequency the various methods are called.
  
    (let
        ((number-of-methods (length (get flavor-name '*a-list-method-table*))))
	(if
	   (<= number-of-methods (* 4 (CONST $MAX-COND-CLAUSES)))
	   % THEN
	   (* 2 (CONST  $MAX-COND-CLAUSES))
	   % ELSE
	   (CONST $MAX-COND-CLAUSES)
	   )
	)
    )


(de &return-fast-cond-body (flavor-name object-info max-elem-in-cond)
  
    % Return a list of the cond clauses for the fast method accessor.
    % Check if there are specific methods to place in the cond
    % first and build them (check if '*fast-access-methods* is a pair).
    % Then build the cond clauses for the rest of the items that
    % exist in the a-list form of the method table.
    % Note that the fast access methods build first are removed from
    % the method table (nondestructively) so we don't repeat clauses
    % in the cond.
    %    If illegal fast access variables are found, a warning message
    % is issued and the bad variables are skipped.
    % 'max-elem-in-cond' specifies how many methods should be placed in a cond
    % before a call (as the last cond item) to the hashing function is made.
    % If the number of cond clauses exceeds max-elem-in-cond, the rest
    % of the methods are added to the hash table.

    % Example: flavor 'dogfood' has an '*a-list-method-table*' of
    %          ((a . dogfood$a) (b . dogfood$b) (c . dogfood$c)
    %           (d . dogfood$d) (e . dogfood$e))
    %          Its '*fast-method-access* property has a value of (c e) and
    %          'max-elem-in-cond' = 8.
    %          This function would return:
    %          (((EQ METHOD-NAME 'C) 'DOGFOOD$C)
    %           ((EQ METHOD-NAME 'E) 'DOGFOOD$E) 
    %           ((EQ METHOD-NAME 'A) 'DOGFOOD$A)
    %           ((EQ METHOD-NAME 'B) 'DOGFOOD$B) 
    %           ((EQ METHOD-NAME 'D) 'DOGFOOD$D))


    (let
        ((a-list-method-table (get flavor-name '*a-list-method-table*))
	 cond-body
	 (fast-access-methods (get flavor-name '*fast-method-access*)))

	% Check list of methods to access fast (if any).
	(&check-fast-access-method-list a-list-method-table fast-access-methods)
	(when
	   (pairp fast-access-methods)
	   % THEN we have specific methods to access fast.
	   (setf cond-body 
	         (for
		     (with 
		          (done? NIL))
		     (in fast-method fast-access-methods)
		     % Skip this iteration if unless expression returns non-NIL.
		     % This is when we are making a hash table (enough elements
		     % in the cond) or the fast-method is invalid.
		     (unless
		            (or
			       done?
			       (not (atsoc fast-method a-list-method-table))
			       ))
		     (collect
		             (if
			        (zerop max-elem-in-cond)
				% THEN Add any extra methods to hash table.
				(progn
				      (&make-and-attach-method-hash-table object-info
									  a-list-method-table)
				      % Set up so we leave this function.
				      (setf done? T)
				      (setf a-list-method-table NIL)
				      % Return the end of the cond.
				      `(t (&method-hash-get object-info method-name))
				      )
				% ELSE Add another cond clause.
				(let
				    ((method-pair (atsoc fast-method
							 a-list-method-table)))
				    % Remove the item from the temporary 
				    % method table.
				    (setf a-list-method-table
				          (delatq (car method-pair) a-list-method-table))
				    % Specify that we added another cond clause.
				    (setf max-elem-in-cond (1- max-elem-in-cond))
				    `((eq method-name ',(car method-pair)) ',(cdr method-pair))
				    )
				)
			     )
		     )
		 )
	   )
	% Deal with any non specifically declared methods.
	(setf cond-body
	      (append cond-body
		      (for
		          (with 
			       (done? NIL))
		          (in method-pair a-list-method-table)
			  (on rest-of-table a-list-method-table)
			  (unless 
			         done?)
			  (collect
			          (if
				     (zerop max-elem-in-cond)
				     % THEN The remaining methods must be added to hash table.
				     (progn
				           (&make-and-attach-method-hash-table object-info
									       rest-of-table)
					   % Set up so we leave this routine.
					   (setf done? T)
					   % Return the end of the cond.
					   `(t (&method-hash-get object-info method-name))
					   )
				     % ELSE Add another cond clause.
				     % Specify that we added another cond clause.
				     (setf max-elem-in-cond (1- max-elem-in-cond))
				     `((eq method-name ',(car method-pair)) ',(cdr method-pair))
				     )
				  )
			  )
		      )
	      )
	)
    )

(de &check-fast-access-method-list (a-list-method-table fast-access-methods)
  
    % Run through list of methods to access fast and check that each is a method
    % that really exists.  If any don't flag warning messages.

    (for
        (in method-name fast-access-methods)
	(do
	   (unless
	          (atsoc method-name a-list-method-table)
		  % THEN Print warning.
		  (prin2 (bldmsg "Ignoring attempt at fast access to method %w, which doesn't exist."
				 method-name))
		  )
	   )
	)
    )

(compiletime (off fast-evectors fast-integers fast-vectors))

% End of file.
