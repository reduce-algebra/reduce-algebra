%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:OBJ-HASH.SL 
% Description:  Specific Set of Hashing Functions for the Objects Package 
% Author:       Mike Creech, HP/CRC 
% Created:      11-Dec-83 
% Modified:     12-Jul-84 11:16:43 (Mike Creech) 
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
% 12-Jul-84 10:39:12 (Mike Creech)
%    Changed parameters to &method-hash-get from message-name object to
%    object-info message-name.  Removed the code that got the object information
%    vector.
% 25-Apr-84 19:13:49 (Mike Creech)
%    Added hash table initialization crock (see below).
%    Changed igetv and iputv to vector-fetch and vector-store.
% 02-Mar-84 16:02:17 (Mike Creech)
%    Fixed header.
% 26-Jan-84 15:42:07 (Mike Creech)
%    Made it so object package constants are dskin'd.
% 17-Jan-84 13:32:42 (Mike Creech)
%    Hipo'ed up hasher (&get-method-hash-address).
% 11-Dec-83 11:21:52 (Mike Creech)
%  
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% NOTE: 1) This is an implementation dependent module!
%          It will only run compiled and must be updated when id's are
%          stored differently in the language.  See the comments for 
%          the macro &get-method-hash-address.
%          This will go away when HPSL gives an efficient hashing function.
%       2) This module also initializes the hash tables to the value:
%               (@$&*funkysymbol*&$@)
%          This is a crock to allow use to not check for NIL when
%          doing &method-hash-get or &instance-hash-get.
%          This crock should be removed and the hash tables set to NIL
%          values when an extremely fast safecar is written (as an anyreg).
%       3) Remove compatibility code from &no-hash-element? after
%          everything has been compiled using new hash scheme.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
% Hash functions are as follows:
%
% (&method-hash-put hash-table key element) :
%      using 1 key, insert the element into the method hash table.
%      replaces any previous hash on the same key.
%
% (&instance-hash-put hash-table key element) :
%      using 1 key, insert the element into the instance variable hash table.
%      replaces any previous hash on the same key.
%
% (&method-hash-get object-info message-name) :
%      using message-name as a key, get the element associated with this key 
%      in the method hash table.  If none, return NIL.
%
% (&instance-hash-get hash-table key) :
%      using 1 key, get the element associated with this key 
%      in the instance hash table.  If none, returns NIL.
%
% (&make-method-hash-table) : returns a method hash table.
%
% (&make-instance-hash-table) : returns an instance hash table.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Allow for fast integer operations.
(compiletime   (load numeric-ops))
% Allow for use of fast vector-fetch and vector-store.
(compiletime   (load f-vectors))
% Allow for use of evector operations.
(compiletime   (load f-evectors))

(compiletime (on fast-vectors fast-integers fast-evectors))

% Load in constants defined for the object package.
(compiletime (load obj-const))

(compiletime (defconst METHOD-HASH-TABLE-SIZE   128
                       INSTANCE-HASH-TABLE-SIZE 32))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Internal Functions (to the object package)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(defmacro &get-id-number (id)

   % This is an incredible hack.  

   id)

(de &fast-atsoc (indicator a-list)
  
    % A fast version of EQ association that does no argument checking.
    % a-list must be a proper a-list or NIL.

    (cond ((null a-list) nil)
	  ((eq indicator (caar a-list)) (car a-list))
	  (t (&fast-atsoc indicator (cdr a-list)))))

(defmacro &get-method-hash-address (hash-number)

   % This macro only works if hash-number is positive, and fits into
   % a psl single word (with tag).  Also, the hash table size must be
   % a power of two.
   % Hash address is a number mod size of hash table.
   % In order for this routine to work (since we are doing a & on
   % a number and an id, ALL places where this macro is used
   % MUST be compiled with fast integers.

  `(& ,hash-number ,(- (CONST METHOD-HASH-TABLE-SIZE) 1)))

(defmacro &get-instance-hash-address (hash-number)

   % See comments above.

  `(& ,hash-number ,(- (CONST INSTANCE-HASH-TABLE-SIZE) 1)))

(defmacro &get-method-hash-number (id)

    % Currently, &get-id-number returns the id itself!  This is an
    % incredible hack.  Hashing is simplified to being a logical
    % and to get the right piece of the tag as an index into the hash
    % table.  It will only work compiled (will get an error interpreted)
    % with FAST-INTEGERS.

    `(&get-method-hash-address (&get-id-number ,id)))

(defmacro &get-instance-hash-number (id)

    % See the comments from &get-method-hash-number above.

    `(&get-instance-hash-address (&get-id-number ,id)))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                   Hash Element Manipulation Functions
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(defmacro &create-hash-element (var value)
    `(cons ,var ,value))

(defmacro &get-hash-element-value (element) 
    `(cdr ,element))

(defmacro &put-hash-element-value (element new-value)
    `(rplacd ,element ,new-value))

(defmacro &get-hash-element-name (element) 
    `(car ,element))

(defmacro &no-hash-element? (hash-elements)

    % Return NIL only if nothing has been stored in this bucked.
    % For acompatibility, two forms are handled: NIL and the funky symbol.

    `(or (eq (car ,hash-elements) '@$&*funkysymbol*&$@)
	 (null ,hash-elements)
	 )
    )

(defmacro &single-or-no-hash-element? (hash-elements)

    % Return NIL only if the hash bucket has two or more elements.

    `(idp (car ,hash-elements)))

(defmacro &find-hash-element (var hash-elements)
    `(&fast-atsoc ,var ,hash-elements))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                Callable Functions
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de &make-method-hash-table ()

    % Good sizes to pick based on size wanted is:
    % 2 for 2.
    % 3 for 4.
    % 7 for 8.
    % 13 for 16.
    % 31 for 32.
    % 61 for 64
    % 127 for 128.
    % 253 for 256.
    % 511 for 512.
    % 1021 for 1024.
    % 2047 for 2048.

  (let*
       ((last-elem-index (- (CONST METHOD-HASH-TABLE-SIZE) 1))
	(hash-table  (mkvect last-elem-index)))
       (&initialize-hash-table hash-table last-elem-index)
       hash-table
      )
  )

(de &make-instance-hash-table ()

  (let*
       ((last-elem-index (- (CONST INSTANCE-HASH-TABLE-SIZE) 1))
	(hash-table  (mkvect last-elem-index)))
       (&initialize-hash-table hash-table last-elem-index)
       hash-table
      )
  )

(de &initialize-hash-table (hash-table last-elem-index)

    % This is part of the initialization crock.
    % This routine should be removed when a fast anyreg safecar is written.
    % For space efficiency only one crock value is created and copied into all
    % elements of the vector.

    (let
        ((funky-value '(@$&*funkysymbol*&$@)))
	(for
	   (from index 0 last-elem-index)
	   (do
	      (vector-store hash-table index funky-value)
	      )
	   )
	)
    )
	 
(de &method-hash-put (hash-table var value)

    % This function adds 'var' and 'value' to the hash table.
    % If 'var' was in the hash table, its value is replaced with
    % 'value'.  If 'var' didn't exist, a new hash element is created.
    % If a hash-table has no elements in a slot, place the element
    % there.  If the table has one or more elements, make sure a 
    % list of elements is created.  This technique is used for speed
    % assuming that table size is tuned so that in the majority of
    % cases only one element will be in a hash table slot.
    % var-there? will be NIL or the hash-element to modify if it
    % already exists in the hash table.

    (let
        ((hash-element (&create-hash-element var value))
	 (table-number (&get-method-hash-number var)))
	(let*
	    ((hash-elements (vector-fetch hash-table table-number))
	     (var-there?    (if
			       (&single-or-no-hash-element? hash-elements)
			       % THEN Check directly if equal.
			       %      Will never be eq to the funky symbol (we hope).
			       (and (eq (&get-hash-element-name hash-elements) var)
				    hash-elements)
			       % ELSE Use more general method.
			       (&find-hash-element var hash-elements))))
	    (if
	       var-there?

	       % THEN The variable already existed in the table.
	       (&put-hash-element-value var-there? value)

	       % ELSE Make a new hash table entry for the item.
	       (cond
	            ((&no-hash-element? hash-elements) (vector-store hash-table table-number hash-element))
		    ((&single-or-no-hash-element? hash-elements)
		            (vector-store hash-table
				   table-number
				   (list hash-elements hash-element)))
		    (t (nconc hash-elements (list hash-element)))
		    )
	       )
	       value)))

(de &instance-hash-put (hash-table var value)

    % This function adds 'var' and 'value' to the hash table.
    % If 'var' was in the hash table, its value is replaced with
    % 'value'.  If 'var' didn't exist, a new hash element is created.
    % If a hash-table has no elements in a slot, place the element
    % there.  If the table has one or more elements, make sure a 
    % list of elements is created.  This technique is used for speed
    % assuming that table size is tuned so that in the majority of
    % cases only one element will be in a hash table slot.
    % var-there? will be NIL or the hash-element to modify if it
    % already exists in the hash table.

    (let
        ((hash-element (&create-hash-element var value))
	 (table-number (&get-instance-hash-number var)))
	(let*
	    ((hash-elements (vector-fetch hash-table table-number))
	     (var-there?    (if
			       (&single-or-no-hash-element? hash-elements)
			       % THEN Check directly if equal.
			       %      Will never be eq to the funky symbol (we hope).
			       (and (eq (&get-hash-element-name hash-elements) var)
				    hash-elements)
			       % ELSE Use more general method.
			       (&find-hash-element var hash-elements))))
	    (if
	       var-there?

	       % THEN The variable already existed in the table.
	       (&put-hash-element-value var-there? value)

	       % ELSE Make a new hash table entry for the item.
	       (cond
	            ((&no-hash-element? hash-elements) (vector-store hash-table table-number hash-element))
		    ((&single-or-no-hash-element? hash-elements)
		            (vector-store hash-table
				   table-number
				   (list hash-elements hash-element)))
		    (t (nconc hash-elements (list hash-element)))
		    )
	       )
	       value)))

(de &method-hash-get (object-info method-name)

    % Retrieve the hash-table from 'object-info' and then hash using 'method-name'.
    
    (let
	 ((hash-elements (vector-fetch  (vector-fetch object-info
						      (CONST $METHOD-TABLE-SLOT))
					(&get-method-hash-number method-name))))
	 
	 (if
	    (&single-or-no-hash-element? hash-elements)
	    % THEN We only have one or no elements in this table spot.
	    (when
	         (eq method-name (&get-hash-element-name hash-elements))
		 % THEN Return the value.
		 %      The method-name should never be equal to the funky symbol (we hope).
		 (&get-hash-element-value hash-elements)
		 )
	    % ELSE We have no elements or 2 or more elements in this
	    %      table spot.
	    (let
	        ((element (&find-hash-element method-name hash-elements)))
		(when
		     element
 	            % THEN
		     (&get-hash-element-value element))
		)
	    )
	 )
    )
 
(de &instance-hash-get (hash-table var)

    (let
        ((hash-elements (vector-fetch hash-table
			       (&get-instance-hash-number var))))
	(if
	   (&single-or-no-hash-element? hash-elements)

	   % THEN We only have one or no elements in this table spot.
	   (when
	        (eq var (&get-hash-element-name hash-elements))
		% THEN Return the value.
		 %     The var should never be equal to the funky symbol (we hope).
		(&get-hash-element-value hash-elements)
		)
	   % ELSE We have no elements or 2 or more elements in this
	   %      table spot.
	   (let
	       ((element (&find-hash-element var hash-elements)))
	       (when
		    element
 	            % THEN
		    (&get-hash-element-value element))
	       )
	   )
	))

(compiletime (off fast-vectors fast-integers fast-evectors))

% End of file.

