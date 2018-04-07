%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:OBJ-INSTANCE.SL 
% Description:  Code for Making Instances of Objects 
% Author:       Mike Creech, HP/CRC 
% Created:      21-Feb-84 
% Modified:     05-Sep-84 09:12:31 (Brian Beach)
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
% 10-Jul-84 16:27:41 (Mike Creech)
%  Changed &object-perform-initialization to check that the flavor has initable
%  instance variables before it calls the hash functions.
%  This catches the error of setting an instance variable when the flavor has none.
% 28-Mar-84 15:39:37 (Mike Creech)
%  Changed both references to IDAPPLY2 to new compiler IDAPPLY.
%  This IDAPPLY mimics APPLY.
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
%                       used by two or more  object package files.
%     obj-send.sl     - Code for sending messages, tracing messages, and 
%                       creating the correct method fetching scheme (at runtime
%                       in the users program).
%     
% Because this file is only part of the object package, it only needs to load what
% is necessary to compile it.  objects.sl takes care of stuff needed at loadtime.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


% Allow for fast integer operations.
(compiletime   (load numeric-ops))
% Allow for use of fast vector-fetch and vector-store.
(compiletime   (load f-vectors))
% Allow for evector operations.
(compiletime   (load f-evectors))

(compiletime (on fast-evectors fast-integers fast-vectors))


% Make the constants available at compile time only.
% For the ability to interpret object routines that refer to these constants,
% dskin these in when interpreting.

(compiletime (load obj-const))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% Summary of Public Functions:
%   
% (make-instance 'flavor-name 'var1 value1 ...)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Calling Tree 
%    make-instance
%        instantiate-flavor
%            &object-perform-initialization
%                &instance-hash-get              (obj-hash.sl)
%                &object-lookup-variable-in-list (obj-lib.sl)
%                &object-get-handler             (obj-send.sl)
%                &object-get-handler-quietly     (obj-send.sl)
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% MAKE-INSTANCE - Create a new instance of a flavor.
%   
% Examples:
%
% (make-instance 'funny-number)
% (make-instance 'funny-number 'real-part 0.0)
%
% The last example is used throughout make-instance code.
%
% MAKE-INSTANCE accepts an optional initialization list, consisting of
% alternating pairs of instance variable names and corresponding initial values.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(defmacro make-instance (flavor-name . init-plist)

    % Example:
    %    returns: (instantiate-flavor 'funny-number
    %                                 (list 'real-part 0.0))

    (if
       init-plist
       % THEN make a list of the arguments.
       `(instantiate-flavor ,flavor-name
			    (list . ,init-plist))
       % ELSE don't make a list.
       `(instantiate-flavor ,flavor-name NIL)
       )
    )

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% INSTANTIATE-FLAVOR
%   
% This is the same as MAKE-INSTANCE, except that the initialization list is
% provided as a single (required) argument.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de instantiate-flavor (flavor-name init-plist)
 
    % Example:
    %    flavor-name = funny-number
    %    init-plist  = (real-part 0.0)

    (let
        ((vector-size (get flavor-name '*instance-vector-size*))
	 object)
	(if
	   vector-size

	   % THEN the flavor exists.
           %      Make the vector that represents the object.
	   (let
	       ((object-info (get flavor-name '*fast-object-info*)))

	       (setf object (make-manual-evector (- vector-size 1)
						 object-info
						 '*UNBOUND*))

	       (eputv object (CONST $OBJECT-INHERITANCE-SLOT) NIL)
	       (&object-perform-initialization object init-plist flavor-name)
		 
	       % Call default-init method quickly.
	       (idapply  (object-get-handler object 'default-init)
			 (list object init-plist))
	       % Only call init method if needed.  We don't use
	       % send-if-handles because it is too slow.
	       
	       (unless
		      (funboundp (vector-fetch object-info
					       (CONST $INIT-METHOD-NAME-SLOT)))
		      % THEN An init method has been defined.
		      (idapply	(vector-fetch object-info
					      (CONST $INIT-METHOD-NAME-SLOT))
				(list object init-plist))
		      )
	       object
	       )
	   % ELSE We have an error.
	   (ContError 0 "Attempt to instantiate undefined flavor: %w"
		      flavor-name (Instantiate-Flavor flavor-name init-plist))
	   )
	)
    )

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Internal Functions (to the object package)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de &object-perform-initialization (object init-plist flavor-name)

    % Perform the initialization of instance variables in OBJECT as specified by
    % the INIT-PLIST, which contains alternating instance variable names and
    % initializing values.  If a variable is found without a value or the
    % remainder of the INIT-PLIST is not a list or nil, that variable is set
    % to NIL.  
    % Example:
    %    object      = a new evector.
    %    flavor-name = funny-number
    %    init-plist  = (real-part 0.0)

    (when
         init-plist
	 % THEN Only bother setting up to assign variables.
	 (let
	     ((hashed-initable-vars (get flavor-name
					 '*hashed-initable-variables*))
	      name
	      value
	      index)
	     % hashed-initable-vars  = ((real-part . 2))

	     (if
	        hashed-initable-vars
		% THEN We know the flavor really has some initable instance variables.
		(repeat
	               (setf name (car init-plist))
		       % name       = real-part
		       (setf init-plist (cdr init-plist))
		       % init-plist = (0.0)
		       (if
			  (pairp init-plist)
			  % THEN We are assigning it a specific value.
			  (progn (setf value (car init-plist))
				 (setf init-plist (cdr init-plist)))
			  % ELSE We are defaulting the value.
			  (setf value NIL)
			  )
		       (setq index
			     (&instance-hash-get hashed-initable-vars
						 name))
		       (if
			  index
			  % THEN 'name' exists as a variable.
			  (eputv object index value)
			  % ELSE We have an error.
			  (ContinuableError 1000
					    (BldMsg "%p not an initable instance variable of flavor %w"
						    name
						    flavor-name)
					    NIL)
			  )
		       % UNTIL
		       (not (pairp init-plist))
		       )
		% ELSE We have an error.
		(continuableerror 1003
				  (bldmsg "Flavor %w has no initable instance variables."
					  flavor-name)
				  NIL)
		)
	     )
	 )
    )

(compiletime (off fast-evectors fast-integers fast-vectors))

% End of file.
