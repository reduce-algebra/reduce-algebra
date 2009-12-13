%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:OBJ-DFLAVOR.SL 
% Description:  Code to Define an Object Flavor 
% Author:       Mike Creech, HP/CRC 
% Created:      21-Feb-84 
% Modified:     05-Sep-84 09:27:05 (Brian Beach)
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
% 14-Aug-84 13:16:22 (Mike Creech)
%   Fixed bug with saving the inherited flavors under *father-flavors* in
%   the function &build-flavor.
% 12-Jul-84 10:59:04 (Mike Creech)
%   Changed the storage of *father-flavors* to be a list instead of an id (in
%   preparation for multiple inheritance.
% 30-Jun-84 22:08:12 (Mike Creech)
%   Added  storage of father-flavor under the property *father-flavors* under flavor name.
% 11-May-84 11:29:52 (Mike Creech)
%   Changed 'return-inherited-method-builder' to 'inherited-method-builder'
%   Changed 'build-inherited-methods' to 'register-inherited-methods'
%   These changes include defining methods as compile-time instead of at load-time.
% 05-May-84 10:09:42 (Mike Creech)
%   Fixed some comments related to the changes below.
% 02-May-84 13:19:20 (Mike Creech)
%   Added &build-flavor call for each method inherited at compile time.
%   Also moved (association-create) in defflavor up above inheritance code.
% 27-Apr-84 13:39:54 (Mike Creech)
%   Added new inheritance method definer. This includes changes to defflavor
%   the removal of &make-inherited-methods, &carful-car, &number-of-arguments,
%   and &make-variable-name.
% 25-Apr-84 20:46:53 (Mike Creech)
%   Changed some comments. Kludged up &number-of-arguments to return 0
%   if the function is not defined.  This will go away when the changed
%   inheritance is added.
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

% Allow for fast integer operations.
(compiletime   (load numeric-ops))
% Allow for use of fast vector-fetch and vector-store.
(compiletime   (load f-vectors))
% Allow for use of evector operations.
(compiletime   (load f-evectors))
% Get string-concat macro.
(compiletime   (load strings))
% Allow use of mutable association list functions -- association-create
% and association-bind.
(compiletime (load association))

(compiletime (on fast-evectors fast-integers fast-vectors))


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% Summary of Public Functions:
%   
% (defflavor flavor-name (var1 var2 ...) (flav1 flav2 ...) option1 option2 ...)
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Calling Tree
%     defflavor
%         &defflavor-process-varlist
%         &defflavor-error
%         &defflavor-process-options-list
%             &defflavor-process-option
%                 &defflavor-error
%         &defflavor-create-methods
%             &defflavor-define-access-function
%                 defmethod                        (obj-dmethod.sl)
%         &defflavor-define-update-function
%             defmethod                            (obj-dmethod.sl)
%         &defflavor-initable-vars    
%         &defining-flavor?                         (obj-lib.sl)
%         &merge-variable-list
%             &defflavor-error
%         &inherited-method-builder
%         &defflavor-function-name                 (obj-lib.sl)
%         &inherit-flavor-fetch-method
%         &defflavor-build-describe
%         &defflavor-create-prin-method
%             &defflavor-gettable-vars
%             defmethod                           (obj-dmethod.sl)
%         &build-flavor
%             &defflavor-function-name            (obj-lib.sl)
%             &hash-initable-vars
%                 &make-instance-hash-table       (obj-hash.sl)
%                 &instance-hash-put              (obj-hash.sl)
%                 &object-lookup-variable-in-list (obj-lib.sl)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Private Constants, Fluids, and Macros (mere mortals should ignore these)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '($defflavor-option-table
	 ))

% Make the constants available at compile time only.
% For the ability to interpret object routines that refer to these constants,
% dskin these in when interpreting.

(compiletime (load obj-const))

(setf $defflavor-option-table
      '((gettable-instance-variables . &defflavor-do-gettable-option)
        (settable-instance-variables . &defflavor-do-settable-option)
	(initable-instance-variables . &defflavor-do-initable-option)
	(fast-access-for-methods     . &defflavor-do-access-option))
      )

% Note the free variable FLAVOR-NAME in this macro:
(defmacro &defflavor-error (format . arguments)
  `(ContinuableError 1000 (BldMsg ,(string-concat "DEFFLAVOR %w: " format)
			          flavor-name . ,arguments) NIL))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Public Functions
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% DEFFLAVOR - Define a new flavor of Object
%   
% Examples:
%
% (defflavor complex-number (real-part imaginary-part) ())
%
% (defflavor complex-number (real-part imaginary-part) ()
%    gettable-instance-variables
%    initable-instance-variables
%    )
%
% (defflavor funny-number ((real-part 0.0)
%			   (imaginary-part 0.0)
%                          funny-part
%			   )
%    ()
%    gettable-instance-variables
%    (settable-instance-variables real-part)
%    )
%
% An object is represented by an evector; instance variables are allocated
% specific slots in the evector.  Do not use names like "IF" or "WHILE" for
% instance varibles: they are translated freely within method bodies (see
% DEFMETHOD).  Initial values for instance variables may be specified as
% arguments to MAKE-INSTANCE, or as initializing expressions in the variable
% list, or may be supplied by an INIT method (see MAKE-INSTANCE).
% Uninitializied instance variables are bound to *UNBOUND*.
% The funny-number example above is used throughout the defflavor code
% as an example.
% For a detailed example of defflavor, see PIG:OBJ-SPEC.IBM.
% Recognized options are:
%
%  (GETTABLE-INSTANCE-VARIABLES var1 var2 ...)
%  (SETTABLE-INSTANCE-VARIABLES var1 var2 ...) 
%  (INITABLE-INSTANCE-VARIABLES var1 var2 ...)
%  (FAST-ACCESS-FOR-METHODS     method1 method2 ...)
%  GETTABLE-INSTANCE-VARIABLES  [make all instance variables GETTABLE]
%  SETTABLE-INSTANCE-VARIABLES  [make all instance variables SETTABLE]
%  INITABLE-INSTANCE-VARIABLES  [make all instance variables INITABLE]
%  FAST-ACCESS-FOR-METHODS      [access all methods fast]
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(defmacro defflavor (flavor-name variable-list flavor-list . options-list)

  % EXAMPLE:
  % flavor-name   = funny-number
  % variable-list = ((real-part 0.0)
  %                  (imaginary-part 0.0)
  %		     funny-part)
  % flavor-list   = NIL
  % options-list  = (gettable-instance-variables
  %                  (settable-instance-variables real-part))

  (prog (var-names		% List of valid instance variable names
	 init-code		% body of DEFAULT-INIT method
	 describe-code		% body of DESCRIBE method
	 defmethod-list		% list of created DEFMETHODs
	 var-options		% AList mapping var names to option list
	 initable-vars		% list of INITABLE instance variables
	 father-flavor		% Flavor of father to inherit from
	 )

    % Return a list the the variables and init code.  Also check that 
    % flavor-name and variable-list are of the right form.
    (desetq (var-names init-code)
	    (&defflavor-process-varlist flavor-name variable-list)
	    )

    % var-names = (real-part imaginary-part funny-part)
    % init-code = ((if (eq real-part '*UNBOUND*)
    %                  (setf real-part 0.0))
    %              (if (eq imaginary-part '*UNBOUND*)
    %   	       (setf imaginary-part 0.0)))

    % Remove information about fast access for methods from previous
    % definitions.
    (remprop flavor-name '*fast-method-access*)

    (setf var-options
      (&defflavor-process-options-list flavor-name var-names options-list)
      )

    % The 'fast-access-for-methods' option is handled differently.
    % If this option was specified, the list of methods to access fast is
    % placed on the property list of '*fast-method-access* or T is placed on this
    % property list if no
    % specific methods were specified.  This information is passed to &build-flavor
    % to handle the FASLing case (interpeting and compiling into memory will still
    % have the *fast-method-access* property to use).

    % var-options = ((*dummy* . *dummy*)
    %                (real-part settable gettable)
    %                (imaginary-part gettable)
    %                (funny-part gettable))

    % Generate get and set methods for new variables.
    (setf defmethod-list (&defflavor-create-methods flavor-name var-options))

    % defmethod-list = see &defflavor-create-methods.

    (setf initable-vars (&defflavor-initable-vars flavor-name var-options))
    
    % initable-vars = (real-part)

    % Want this stuff done at compile time and at load time.
    % Specify that the flavor exists at this point, before inheritance code
    % below is executed.
    % Don't want existing methods to be removed when the flavor is redefined.
    % HPSL NOTE: This will go away.
    (unless
           (&defining-flavor? flavor-name)
	   (put flavor-name '*a-list-method-table* (association-create)))

    % Add inherited instance variables to this subflavor when present.
    (when
         flavor-list
	 % THEN Check that the user didn't use multiple inheritance and has a 
	 %      legal flavor-list.
	 (unless
	        (pairp flavor-list)
		% THEN We have in incorrect flavor-list.
		(&defflavor-error "The flavors to inherit must be a list or NIL.")
		)
	 (unless
	        (eq (length flavor-list) 1)
		% THEN Error, no multiple inheritance yet.
		(&defflavor-error "Multiple Component Flavors not implemented.")
		)
	 (setf father-flavor (car flavor-list))
	 % Check that father-flavor is a defined flavor.
	 (unless
	        (&defining-flavor? father-flavor)
		(&defflavor-error "Component Flavor: %w not a flavor" father-flavor))

	 (setf var-names (&merge-variable-list 
			     (get father-flavor '*variable-names*)
			     var-names
			     flavor-name))	%order must be preserved.
	 (setf initable-vars (unionq (get father-flavor '*initable-variables*)
				     initable-vars))

         % Add a call to the method definer to define the inherited methods.
         (setf defmethod-list (cons (&inherited-method-builder
				       father-flavor 
				       flavor-name)
				    defmethod-list))

	  % Add code to do invocation of father's init method if necessary.
	  % HPSL Note: This must be fixed so that a new defflavor or undefine
	  %            method undefined the function, since we are using FUNBOUNDP.

	  (setf init-code
	        (cons `(unless
			    (funboundp ',(&defflavor-function-name father-flavor
								   'init))
			    % THEN Call the father's init method.
			    (,(&defflavor-function-name father-flavor
							'init)
			          self init-plist)
			    )
		      init-code))

	  % Add code to 'init-code' list to do invocation of fathers default
	  % init code before local default init.
	  (setf init-code 
	        (cons `(,(&inherit-flavor-fetch-method father-flavor 
						       'default-init)
			self init-plist)
		      init-code))

	  )

    (setf describe-code (&defflavor-build-describe flavor-name var-names))

    % Print method only prints subflavor gettable variables by default.
    (setf defmethod-list
          (cons (&defflavor-create-prin-method flavor-name var-options)
		defmethod-list))
    (setf defmethod-list
          (cons `(defmethod (,flavor-name default-init) (init-plist) . ,init-code)
		defmethod-list))
    (setf defmethod-list
          (cons `(defmethod (,flavor-name describe) () . ,describe-code)
		defmethod-list))

    (put flavor-name '*variable-names* var-names)		%want bothtimes.
    (put flavor-name '*initable-variables* initable-vars)	%want bothtimes.

    % The previous actions happen at compile or dskin time.
    % The following actions happen at dskin or load time.
    % All the progn contents below can not be placed into the
    % &build-method routine because we want the functions that
    % define the methods to be defined at compile time for 
    % when we compile into a binary -- progn's are
    % treated specially.
    %    To see a full example of this progn, see objects.sl.
    (return `(progn
	           (&build-flavor ',flavor-name 
				  ',var-names
				  ',initable-vars
				  ',(get flavor-name '*fast-method-access*)
				  ',father-flavor)
		   % Take the list of methods to define and splice them in here.
		   ,@defmethod-list
		   '(flavor ,flavor-name) % for documentation only
		   )
	    )
    ))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Internal Functions (to the object package)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de &build-flavor (flavor-name
		   var-names
		   initable-vars
		   fast-methods-accessed
		   father-flavor)

    % Perform the required tasks to properly define a flavor.

    % 'fast-methods-accessed' is NIL if no 'fast-access-for-methods' option
    % existed in the defflavor.  It is T, if the names of the methods
    % are not specified.  It is a list of the methods otherwise.

    % HPSL Note: The a-list-method-table will always be rebuilt.

    (unless
           (&defining-flavor? flavor-name)
	   % THEN Build a new method-table and prepare for
	   %      reversing it at run time (to move speed independent methods
	   %      to the back).
	   (put flavor-name '*a-list-method-table* (association-create)))

    % Setup the structure pointed to by all instances of this
    % object to make the method-table and flavor-name lookup
    % FAST as well as making instances of objects fast.
    % Similarly, allow old object code to run by only defining
    % property if it hasn't all ready been defined, but changing
    % its code-pointer to control function again.

    % HPSL Note: Will not have IF but replace all fast-object-info for
    %            HPSL.
    (if
       (get flavor-name '*fast-object-info*)
       % THEN Old versions of this object potentially exist and
       %      the only thing we want to change is the code-pointer field.
       (vector-store (get flavor-name '*fast-object-info*)
		     (CONST $CODE-POINTER-SLOT)
		     (cdr (getd '&control-of-method-fetch)))

       % ELSE Set up a new vector.
       % The first NIL means there is no method table initially.
       % The second NIL means there is currently no 'init'
       % method for this object.  See objects.sl for a detialed description of
       % *fast-object-info*.
       (let
	   ((fast-object-info (mkvect (- (CONST $INFO-NUMBER-OF-SLOTS)
					 1))))
	   (vector-store fast-object-info
			 (CONST $CODE-POINTER-SLOT)
			 (cdr (getd '&control-of-method-fetch)))
	   (vector-store fast-object-info
			 (CONST $METHOD-TABLE-SLOT)
			 NIL)
	   (vector-store fast-object-info
			 (CONST $INIT-METHOD-NAME-SLOT)
			 (&defflavor-function-name flavor-name
						   'init))
	   (vector-store fast-object-info
			 (CONST $FLAVOR-NAME-SLOT)
			 flavor-name)
	   (put flavor-name '*fast-object-info* fast-object-info)
	   )
       )
    
    (put flavor-name '*instance-vector-size*
	 (+ (CONST $OBJECT-NUMBER-OF-RESERVED-SLOTS)
	    (length var-names)))
    (put flavor-name '*variable-names* var-names)
    (put flavor-name '*initable-variables* initable-vars)
    (put flavor-name '*father-flavors* (when father-flavor
					     % We have a real inherited flavor.
					     (list father-flavor)))
    (when
         fast-methods-accessed
	 % THEN set up for which methods will be accessed fast.
	 (put flavor-name '*fast-method-access* fast-methods-accessed)
	 )
      
    % Make a fast access list of initable variables for
    % use by make-instance.
    (put flavor-name '*hashed-initable-variables* 
	 (&hash-initable-vars initable-vars var-names))
    )

(de &merge-variable-list (father son flavor-name)

    % 'flavor-name' is used by &defflavor-error.
    % Return the union of father and son variable lists.
    % Issue an error if there is any intersection.
    
    (when
         (intersectionq father son)
	 % THEN
          (&defflavor-error "Inherited variables %w overlap subflavor variables"
			    (intersectionq father son))
	  % do not return the son variables.
	  (for
	      (in i (intersectionq father son))
	      (do (setf son (delq i son))))
	  )
    (append father son)
    )

(de &inherited-method-builder (father-flavor son-flavor)

    % Define the inherited methods now (at compile-time).
    % Also add the methods to the son's *a-list-method-table* (now at compile-time).
    % This is necessary  so other flavors can inherit
    % from this one when we are fasling.
    % Return a call to '&register-inherited-methods' that has as arguments
    % the father flavor, the son flavor and the list of the methods to
    % inherit from the father.


  (let
      ((father-methods (get father-flavor '*a-list-method-table*)))

      % First remove the fathers automatically defined methods because
      % we're going to make our own.
      (setf father-methods (delatq 'describe father-methods))
      (setf father-methods (delatq 'default-init father-methods))
      (setf father-methods (delatq 'channelprin father-methods))
      (setf father-methods (delatq 'init father-methods))

      % The soul purpose of the following loop is to make sure the inherited
      % methods are addes to the sons method table so, at compile time when fasling,
      % the son's flavor can also be correctly inherited from.
      
      (for
          (in method-function-pair father-methods)
	  (do
	     (let
	         ((son-func-name (&defflavor-function-name son-flavor
							   (car method-function-pair))))
		 % Actually define the function.
		 (define-indirect-function son-func-name (cdr method-function-pair))
		 % Now add the method to the son's *a-list-method-table*.
		 (&build-method son-flavor
				(car method-function-pair)
				son-func-name)
		 )
	     )
	  
	  )
      `(&register-inherited-methods ',son-flavor ',father-flavor ',father-methods)
      )
  )

(de &register-inherited-methods (son-flavor father-flavor fathers-a-list-method-table)
  
    % When executed, this function will add all the inherited methods specified
    % to the son flavor's *a-list-method-table*.

    (for
        (in method-function-pair fathers-a-list-method-table)
	(do
	   (let
	       ((son-function-name (&defflavor-function-name son-flavor
							     (car method-function-pair))))
	       % Add appropriate information to say the method is "defined."
	       (&build-method son-flavor (car method-function-pair) son-function-name)
	       )
	   )
	)
    )


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Internal Functions
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de &hash-initable-vars (initable-vars all-vars)

    % Return a hash table of all initable variables and their
    % index in the evector.  For example:
    %      initable-vars = (c e)
    %      all-vars      = (a b c d e)
    % would return an instance hash table with : ((c . 4) (e . 6))
    % in it.  c = 4 and e = 6 because the first two slots are reserved.
    % If there are no initable-vars, NIL is returned.
  
    (when
         initable-vars
	 % THEN hash the variables.
	 (for
	     (with (hashed-initable-vars (&make-instance-hash-table)))
	     (finally hashed-initable-vars)
	     (in variable initable-vars)
	     (do
	        (&instance-hash-put hashed-initable-vars
				    variable 
				    (&object-lookup-variable-in-list all-vars
								     variable))))
	 )
    )

(de &inherit-flavor-fetch-method (flavor-name method-name)
  
    % This is used by the inheritance facility.
    % No object exists at the time
    % it is called, so getting the information from the object is impossible.

    (let
        ((assoc-pair (atsoc method-name
			    (get flavor-name '*a-list-method-table*))))
	(when
	     assoc-pair
	     % THEN Return the name.
	     (cdr assoc-pair)
	     )))

(de &defflavor-process-varlist (flavor-name variable-list)

  % Process the instance variable list of a DEFFLAVOR.  Create a list of valid
  % instance variable names and a list of forms to perform default
  % initialization of instance variables.
  % Also check that flavor-name and variable-list are of the right form.
  %
  % Example: flavor-name = funny-number
  %          variable-list = ((real-part      0.0)
  %                           (imaginary-part 0.0)
  %                           funny-part)
  % Returns:
  %    ((real-part imaginary-part funny-part)
  %     ((if
  %         (eq real-part '*UNBOUND*)
  %         (setf real-part 0.0)
  %         )
  %      (if
  %         (eq imaginary-part '*UNBOUND*)
  %         (setf imaginary-part 0.0)
  %         )
  %     ))

  (unless
         (and (idp flavor-name) flavor-name)
	 % THEN We have an invalid flavor-name.
	 (&defflavor-error "Flavor name must be an identifier and NOT the symbol NIL.")
	 )

  (unless
         (or (pairp variable-list) (null variable-list))
	 % THEN We have an illegal variable list.
	 (&defflavor-error "The variable list given must be NIL or a list.")
	 )

  (prog (var-names default-init-code init-form v)
    (for (in v-entry variable-list)
	 (do
	  (cond
	       % Is the variable entry an assignment (i.e., of the form
	       % (real-part 0.0)).
	       ((and (PairP v-entry) (IdP (car v-entry)))
		(setf v (car v-entry))
		% v = real-part
		(setf init-form (cdr v-entry))
		% init-form = (0.0)
		(if init-form (setf init-form (car init-form)))
		(setf init-form `(if (eq ,v '*UNBOUND*) (setf ,v ,init-form)))
		% init-form = (if 
		%                (eq real-part '*UNBOUND*)
		%                (setf real-part 0.0))
		(setf default-init-code (aconc default-init-code init-form))
		)
		((IdP v-entry) (setf v v-entry))
		(t (&defflavor-error "Bad item in variable list: %p" v-entry)
		   (setf v NIL)
		   )
		)
	  (if
	     v
	     % THEN
	     (setf var-names (aconc var-names v))
	     % var-names = (real-part imaginary-part funny-part)
	     )
	  ))
    (return (list var-names default-init-code))))

(de &defflavor-build-describe (flavor-name var-names)

  % Return a list of forms that print a description of an instance.

  % Example:
  %    flavor-name = funny-number
  %    var-names   = (real-part imaginary-part funny-part)
  % Returns:
  %    ((PRINTF "An object of flavor FUNNY-NUMBER, has instance variable values:%n")
  %     (PRINTF "  %w: %p%n" (QUOTE REAL-PART) REAL-PART) 
  %     (PRINTF "  %w: %p%n" (QUOTE IMAGINARY-PART) IMAGINARY-PART)
  %     (PRINTF "  %w: %p%n" (QUOTE FUNNY-PART) FUNNY-PART)
  %     NIL)

  (let ((describe-code
	 `((printf ,(string-concat "An object of flavor "
				   (id2string flavor-name)
				   ", has instance variable values:%n")))))
    (for (in v var-names)
	 (do
	  (setf describe-code
	    (aconc describe-code `(printf "  %w: %p%n" ',v ,v)))
	  ))
    (aconc describe-code NIL)
    ))

(de &defflavor-process-options-list (flavor-name var-names options-list)

  % Return an a-list mapping var-names to a list of options.
  
  % Example:
  %    flavor-name  = funny-number
  %    var-names    = (real-part imaginary-part funny-part)
  %    options-list = (gettable-instance-variables (settable-instance-variables real-part))
  % Returns:
  %    ((*DUMMY* . *DUMMY*)
  %     (REAL-PART SETTABLE GETTABLE)
  %     (IMAGINARY-PART GETTABLE)
  %     (FUNNY-PART GETTABLE))

  (let
      ((var-options (association-create)))
      (for
          (in option options-list)
	  (do (&defflavor-process-option flavor-name var-names
					 var-options option)
	      ))
      var-options
      ))

(de &defflavor-process-option (flavor-name var-names var-options option)

  % Process the option by modifying the a-list VAR-OPTIONS.

  (let (option-keyword option-arguments)
    (cond ((PairP option)
	   (setf option-keyword (car option))
	   (setf option-arguments (cdr option))
	   )
	  ((IdP option)
	   (setf option-keyword option)
	   )
	  (t (&defflavor-error "Bad item in options list: %p" option)
	     (setf option-keyword '*NONE*)
	     )
	  )
    (when
         (neq option-keyword '*NONE*)
	 % THEN
	 (let
	     ((pair (atsoc option-keyword $defflavor-option-table)))
	     (if
	        (null pair)
		% THEN
		(&defflavor-error "Bad option in options list: %w" option)
		% ELSE
		(apply (cdr pair)
		       (list flavor-name var-names var-options option-arguments))
		)))))

(de &defflavor-do-gettable-option (flavor-name var-names var-options args)
  (&defflavor-insert-keyword flavor-name var-names var-options args 'GETTABLE)
  )

(de &defflavor-do-settable-option (flavor-name var-names var-options args)
  (&defflavor-insert-keyword flavor-name var-names var-options args 'SETTABLE)
  )

(de &defflavor-do-initable-option (flavor-name var-names var-options args)
  (&defflavor-insert-keyword flavor-name var-names var-options args 'INITABLE)
  )

(de &defflavor-do-access-option (flavor-name var-names var-options args)
    (if
       args
       % THEN Place the args on the *fast-method-access* property.
       (put flavor-name '*fast-method-access* args)
       % ELSE Place T on the property.
       (put flavor-name '*fast-method-access* T)
       )
    )

(de &defflavor-insert-keyword (flavor-name var-names var-options args key)

  (if (null args) (setf args var-names)) % default: applies to all variables
  (for (in var args) % for each specified instance variable
       (do
	(if (not (memq var var-names))
	  (&defflavor-error "%p (in keyword option) not a variable." var)
	  % else
	  (let ((pair (atsoc var var-options)))
	    (when (null pair)
	      (setf pair (cons var nil))
	      (aconc var-options pair)
	      )
	    (setf (cdr pair) (adjoinq key (cdr pair)))
	    )))))

(de &defflavor-define-access-function (flavor-name var-name)

    % Example, returns: (defmethod (funny-number real-part) () real-part).

   `(defmethod (,flavor-name ,var-name) () ,var-name))

(de &defflavor-define-update-function (flavor-name var-name)
 
    % Example, returns:
    % (defmethod (funny-number set-real-part) (new-value)
    %            (setf real-part new-value))

    (let
        ((method-name (intern (string-concat "SET-" (id2string var-name)))))
	`(defmethod (,flavor-name ,method-name) (new-value)
	   (setf ,var-name new-value))))

(de &defflavor-create-methods (flavor-name var-options)

  % Return a list of DEFMETHODs for GETTABLE and SETTABLE instance variables.
  % Example: flavor-name = funny-number
  %          var-options = ((*dummy* . *dummy*)
  %                         (real-part settable gettable)
  %                         (imaginary-part gettable)
  %                         (funny-part gettable))
  % Returns:
  %    ((DEFMETHOD (FUNNY-NUMBER FUNNY-PART) NIL FUNNY-PART)
  %     (DEFMETHOD (FUNNY-NUMBER IMAGINARY-PART) NIL IMAGINARY-PART)
  %     (DEFMETHOD (FUNNY-NUMBER SET-REAL-PART) (NEW-VALUE) (SETF REAL-PART NEW-VALUE))
  %     (DEFMETHOD (FUNNY-NUMBER REAL-PART) NIL REAL-PART)
  %     )
  
  (let ((defmethod-list))
    (for (in pair var-options)
	 (do
	  (let ((var-name (car pair))
		(keywords (cdr pair))
		)
	    (if (or (memq 'GETTABLE keywords) (memq 'SETTABLE keywords))
	      (setf defmethod-list
		(cons (&defflavor-define-access-function flavor-name var-name)
		      defmethod-list
		      )))
	    (if (memq 'SETTABLE keywords)
	      (setf defmethod-list
		(cons (&defflavor-define-update-function flavor-name var-name)
		      defmethod-list
		      )))
	    )))
    defmethod-list
    ))

(de &defflavor-create-prin-method (flavor-name var-options)

  % Returns an s-expression to define a printer for objects of a flavor.
  % Example: flavor-name = funny-number
  %          var-options = ((*dummy* . *dummy*)
  %                         (real-part settable gettable)
  %                         (imaginary-part gettable)
  %                         (funny-part gettable))
  % Returns:
  %   (DEFMETHOD (FUNNY-NUMBER CHANNELPRIN) (CHANNEL LEVEL PRIN1?)
  %       (CHANNELPRIN2 CHANNEL "#<")
  %       (CHANNELPRIN1 CHANNEL (QUOTE FUNNY-NUMBER))
  %       (LET ((PRINLEVEL (IF PRINLEVEL (!- PRINLEVEL LEVEL 1))))
  %	       (CHANNELSPACES CHANNEL 1)
  %	       (CHANNELPRIN1 CHANNEL (QUOTE REAL-PART))
  %	       (CHANNELPRIN2 CHANNEL "=")
  %	       (CHANNELPRIN1 CHANNEL REAL-PART)
  %	       (CHANNELSPACES CHANNEL 1)
  %	       (CHANNELPRIN1 CHANNEL (QUOTE IMAGINARY-PART))
  %	       (CHANNELPRIN2 CHANNEL "=")
  %	       (CHANNELPRIN1 CHANNEL IMAGINARY-PART)
  %	       (CHANNELSPACES CHANNEL 1)
  %	       (CHANNELPRIN1 CHANNEL (QUOTE FUNNY-PART))
  %	       (CHANNELPRIN2 CHANNEL "=")
  % 	       (CHANNELPRIN1 CHANNEL FUNNY-PART)
  %	       )
  %	  (CHANNELPRIN2 CHANNEL ">")
  %	  T)

  (let ((gettable-vars (&defflavor-gettable-vars flavor-name var-options)))
    `(defmethod (,flavor-name channelprin) (channel level prin1?)
       (channelprin2 channel "#<")
       (channelprin1 channel ',flavor-name)
       ,(if (pairp gettable-vars)
	    `(let ((prinlevel (if prinlevel (- prinlevel level 1))))
	       ,@(for (in v gettable-vars)
		      (join
		       `((channelspaces channel 1)
			 (channelprin1 channel ',v)
			 (channelprin2 channel "=")
			 (channelprin1 channel ,v))))))
       (channelprin2 channel ">")
       t)))

(de &defflavor-gettable-vars (flavor-name var-options)

  % Returns a list of names of instance variables declared to
  % be GETtable.

  (for (in pair var-options)
       (when (and (pairp pair)
		  (or (memq 'GETTABLE (cdr pair))
		      (memq 'SETTABLE (cdr pair)))))
       (collect (car pair))))

(de &defflavor-initable-vars (flavor-name var-options)

  % Return a list containing the names of instance variables that have been
  % declared to be INITable.
  % Example: flavor-name   = funny-number
  %          var-options = ((*dummy* . *dummy*)
  %                         (real-part settable gettable)
  %                         (imaginary-part gettable)
  %                         (funny-part gettable))
  % Returns: (real-part)

  (for (in pair var-options)
       (when (and (PairP pair)
		  (or (memq 'INITABLE (cdr pair))
		      (memq 'SETTABLE (cdr pair))
		      )))
       (collect (car pair))
       )
  )

%(de &method-info-sortfn (m1 m2)
%  (numbersortfn (cdr m2) (cdr m1))
%  )

(compiletime (off fast-integers fast-evectors fast-vectors))

% End of file.

