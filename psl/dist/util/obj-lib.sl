%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:OBJ-LIB.SL 
% Description:  Library of Miscellaneous Object Functions 
% Author:       Mike Creech, HP/CRC 
% Created:      21-Feb-84 
% Modified:     05-Sep-84 09:12:14 (Brian Beach)
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
% 14-Aug-84 13:23:24 (Mike Creech)
%  Changed date of (objects-version) to Aug 13, 1984 because of bug fix to
%  obj-dflavor.sl.
% 25-Jul-84 15:11:54 (Mike Creech)
%  Added correct check for fasling to &which-method-fetcher.
%  Changed date of (objects-version) to July 25, 1984
% 12-Jul-84 16:56:48 (Mike Creech)
%  Added function extended-object-type to deal with primitive object types.
%  Added check if compiler is running and made to &which-method-fetcher
%  returns hash-method-fetcher if it is.
% 12-Jul-84 13:10:24 (Mike Creech)
%  Changed objects-version function to July 13, 1984.
% 20-May-84 09:09:22 (Mike Creech)
%  Added user function FLAVOR-DEFINED?. Changed objects-version to May 20.
% 11-May-84 11:31:50 (Mike Creech)
%  Changed the objects-version function to May 11.
% 02-May-84 13:25:27 (Mike Creech)
%  Changed the objects-version function to May 2.
% 01-May-84 14:11:48 (Mike Creech)
%  Changed the objects-version function to May 1.
% 27-Apr-84 13:56:50 (Mike Creech)
%  Added &build-method, &decide-on-method-searching-algorithm from obj-dmethod.sl
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
(fluid
      '(*compiler-running
	*writingfaslfile)
      )
% Allow for fast integer operations.
(compiletime   (load numeric-ops))
% Allow for use of fast vector-fetch and vector-store.
(compiletime   (load f-vectors))
% Allow for evector operations.
(compiletime   (load f-evectors))
% Load strings to get the string-concat macro.
(compiletime   (load strings))

(compiletime (on fast-evectors fast-integers fast-vectors))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Calling Tree
%         &build-method (obj-lib.sl)
%             &decide-on-method-searching-algorithm
%                 &which-method-fetcher (obj-lib.sl)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% Summary of Public Functions:
%   
% (objects-version)
%
% (flavor-defined? x) --- returns T if x is a defined flavor, NIL otherwise.
%
% (object-type x)  --- returns the type of an object, or NIL if not an object
%
% (extended-object-type x)  --- returns the type of the object, even if a primitive
%                               type, or NIL.
%
% (object-copy x)  --- returns a direct copy of an object (see below)
%
% (declare-flavor flavor var1 var2 ...)   NOTE: see warnings below!
% (undeclare-flavor var1 var2 ...)
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


% Make the constants available at compile time only.
% For the ability to interpret object routines that refer to these constants,
% dskin these in when interpreting.

(compiletime (load obj-const))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Objects-version
%
% This function returns a date used version control purposes.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de objects-version ()
    (prin2 "August 13, 1984")
    (terpri)
    nil)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Flavor-defined?
%
% This function returns whether its argument is a defined flavor.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de flavor-defined? (flavor)
  
    % Return T if 'flavor' is indeed a defined flavor.
    % Return NIL otherwise.
    % Note that this routine is smart enough to NOT return T if the flavor
    % is partially defined.  In other words, if a flavor is FASLed, some
    % properties may exist, but it has not been loaded and cannot be used

    (when
         (idp flavor)
	 % THEN Check if it is a flavor.
	 (when
	      (get flavor '*FAST-OBJECT-INFO*)
	      % THEN The flavor really exists.
	      T)
	 )
    )

    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Extended-Object-Type
%
% The EXTENDED-OBJECT-TYPE function returns the type (an ID) of the specified object, or
% a symbol representing its type if a primitive type or NIL, if the argument is not
% a user defined type or primitive type.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de extended-object-type (object)

    % Return the name of 'object', or if it isn't an object, but a primitive
    % type, return it type, otherwise return NIL.

    (cond
         ((evectorp object)
	  (vector-fetch (egetv object (CONST $FAST-OBJECT-INFO-SLOT))
			(CONST $FLAVOR-NAME-SLOT)))
         ((null object) 'NULL)
	 ((pairp object) 'PAIR)
	 ((vectorp object) 'VECTOR)
	 ((idp     object) 'SYMBOL)
	 ((stringp object) 'STRING)
	 ((fixp    object) 'INTEGER)
	 ((floatp  object) 'FLOAT)
	 (t                NIL)
	 )
    )

    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Object-Type
%
% The OBJECT-TYPE function returns the type (an ID) of the specified object, or
% NIL, if the argument is not an object.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de object-type (object)

    % Return the name of 'object', or if it isn't an object, but a primitive
    % type, return it type, otherwise return NIL.

    (when
         (evectorp object)
         % THEN It is a user defined type.
	 (vector-fetch (egetv object (CONST $FAST-OBJECT-INFO-SLOT))
		       (CONST $FLAVOR-NAME-SLOT))
	 )
    )

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Object-Copy
%
% The OBJECT-COPY function returns a direct copy of the specified object.  The
% instance variables of the new object share their values with the instance
% variables of the original object.  This is a low-level function which is
% probably best used within a COPY method.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de object-copy (object)
  (copyevector object)
  )

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% DECLARE-FLAVOR
%
% *** Read these warnings carefully! ***
%
% The DECLARE-FLAVOR macro allows you to declare that a specific symbol is
% bound to an object of a specific flavor.  This allows the flavors
% implementation to eliminate the run-time method lookup normally associated
% with sending a message to that variable, which can result in an appreciable
% improvement in execution speed.  This feature is motivated solely by
% efficiency considerations and should be used ONLY where the performance
% improvement is critical.
% 
% Details: if you declare the variable X to be bound to an object of flavor
% FOO, then WITHIN THE CONTEXT OF THE DECLARATION (see below), expressions of
% the form (=> X GORP ...)  or (SEND X 'GORP ...)  will be replaced by function
% invocations of the form (FOO$GORP X ...).  Note that there is no check made
% that the flavor FOO actually contains a method GORP.  If it does not, then a
% run-time error "Invocation of undefined function FOO$GORP" will be reported.
% 
% WARNING: The DECLARE-FLAVOR feature is not presently well integrated with
% the compiler.  Currently, the DECLARE-FLAVOR macro may be used only as a
% top-level form, like the PSL FLUID declaration.  It takes effect for all
% code evaluated or compiled henceforth.  Thus, if you should later compile a
% different file in the same compiler, the declaration will still be in
% effect!  THIS IS A DANGEROUS CROCK, SO BE CAREFUL!  To avoid problems, I
% recommend that DECLARE-FLAVOR be used only for uniquely-named variables.
% The effect of a DECLARE-FLAVOR can be undone by an UNDECLARE-FLAVOR, which
% also may be used only as a top-level form.  Therefore, it is good practice
% to bracket your code in the source file with a DECLARE-FLAVOR and a
% corresponding UNDECLARE-FLAVOR.
%
% Here are the syntactic details:
%
% (DECLARE-FLAVOR FLAVOR-NAME VAR1 VAR2 ...)
% (UNDECLARE-FLAVOR VAR1 VAR2 ...)
%
% *** Did you read the above warnings??? ***
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(defmacro declare-flavor (flavor-name . variable-names)
  (prog () % This macro returns NIL!
    (if (not (IdP flavor-name))
      (StdError
       (BldMsg "Flavor name in DECLARE-FLAVOR is not an ID: %p" flavor-name))
      % else
      (for (in var-name variable-names)
	   (do (if (not (IdP var-name))
	         (StdError (BldMsg
			    "Variable name in DECLARE-FLAVOR is not an ID: %p"
			    var-name))
		 % else
		 (put var-name 'declared-type flavor-name)
		 )))
      )))

(dm undeclare-flavor (form)
  (prog () % This macro returns NIL!
    (for (in var-name (cdr form))
	 (do (if (not (IdP var-name))
	       (StdError (BldMsg
			  "Variable name in UNDECLARE-FLAVOR is not an ID: %p"
			  var-name))
	       % else
	       (remprop var-name 'declared-type)
	       )))
    ))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Internal Functions
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de &object-lookup-variable-in-list (variable-names name)

    % Return the index of name in variable-names, or NIL if
    % not in variable-names.
    % Example:
    % variable-names = (real-part imaginary-part funny-part)
    % name           = real-part

    (for
        (in v-name variable-names)
	(for i (CONST $OBJECT-NUMBER-OF-RESERVED-SLOTS) (+ i 1))
	(do (if (eq v-name name) (exit i)))
	(returns nil)
	))


(de &which-method-fetcher (flavor-name)

    % We return 'cond-method-fetcher' if the user specified he wanted
    % fast-access-for-methods in the flavor definition or the number of methods
    % defined is less then or equal to $MAX-COND-CLAUSES.  For both cases,
    % the compiler must be loaded.  Also, in both cases, the compiler must not
    % be running (either in memory or fasling or we would have recursive
    % compilation). In all other cases, 'hash-method-fetcher'
    % is returned.
    %

    (if
       (and (or (leq  (length (get flavor-name '*a-list-method-table*))
		      (CONST $MAX-COND-CLAUSES))
		(get flavor-name '*fast-method-access*))
	    (memq 'compiler options*)
	    (not *compiler-running)
	    (not *writingfaslfile))
       % THEN Should use fast COND.
       'cond-method-fetcher
       % ELSE Should use hash table.
       'hash-method-fetcher
       )
    )

(de &defining-flavor? (flavor-name)

    % Return T if flavor-name is a currently defined flavor or is in the process
    % of being defined.  Being defined means some of the properties are
    % there but not all because:
    %    1) We are in the middle of the defflavor.
    %    2) We finished a defflavor during FASLing (not all stuff is there)
    %       This is for inheritance checking if a flavor was defined
    %       prior to a flavor that inherits it.
    %  Return NIL if the flavor is not defined or being defined.

    (when
         (get flavor-name '*a-list-method-table*)
	 % THEN Return T.
         T)
    )

(de &defflavor-function-name (flavor-name method-name)

    % Return an id of the form:  flavor-name$method-name
    % For example, if flavor-name = nose
    %                 method-name = ma
    % would return 'nose$ma'.

    (intern (string-concat (id2string flavor-name) "$" (id2string method-name))))


(de &build-method (flavor-name method-name function-name)
  
    % Change the code pointer to the method searching algorithm, if necessary.
    % NOTE: This function is called both at compile (or interpret) time and
    %       at loadtime (the load of the code compiled which has a defmethod
    %       in it).
    %       This function must self contain all side effects that "define" a method.
    %       It is used when a flavor inherits a methods and in standard method definition.

    (&decide-on-method-searching-algorithm flavor-name
					   method-name
					   function-name)

    % Add a method to the a-list method table or signal an error.
    % The check for undefined flavor is needed in case the user compiled
    % the flavor definition seperate from the methods.
    % As a result, must check that the flavor definition is there at LOAD
    % time even though a check was made at compile time.

    (let
        ((method-table (get flavor-name '*a-list-method-table*)))
	(if
	   method-table
	   % THEN
	   (association-bind method-table method-name function-name)
	   % ELSE
	   (StdError (BldMsg "DEFMETHOD: undefined flavor %w" flavor-name))
	   ))
    )

(de &decide-on-method-searching-algorithm (flavor-name
					   method-name
					   function-name)

    % Change the code pointer that represents the method searching algorithm to
    % the control function (&control-of-method-fetch) only if:
    %      The flavor exists and we are adding a new method
    %                           or
    %      The flavor exists and the state of our environment has changed
    %      (like the compiler is loaded when it wasn't before).
    %
    % The first time through (before any message or instances
    % have been made), *last-method-fetcher* property is not there
    % and NIL is returned.
    % If the flavor has not been defined yet, also return NIL.
    % This case occurs when FASLing into a file and this is called at compile
    % time.

    (unless
           (and
	       (eq (&which-method-fetcher flavor-name)
		   (get flavor-name '*last-method-fetcher*))
	       (atsoc method-name 
		      (get flavor-name '*a-list-method-table*)))
	   (when
	        (get flavor-name '*fast-object-info*)
		% THEN We know defflavor exists at THIS time
		%      (we are NOT FASLing right now).
		(vector-store (get flavor-name '*fast-object-info*)
			      (CONST $CODE-POINTER-SLOT)
			      (cdr (getd '&control-of-method-fetch)))
		)
	   )
    )


(compiletime (off fast-evectors fast-integers fast-vectors))

% End of file.
