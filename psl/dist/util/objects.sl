%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:OBJECTS.SL 
% Description:  A simple facility for object oriented programming. 
% Author:       Alan Snyder, Hewlett-Packard CRC 
% Created:      22 July 1982 
% Modified:     05-Sep-84 09:12:56 (Brian Beach)
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
% 26-Sep-86 (Leigh Stoller)
%  Changed all loadtime statements to Bothtimes since the there are object
%  definitions at the end of the file.
% 13-Jul-84 10:20:44 (Mike Creech)
%   Added primitive type definitions and making of global instances of these types.
% 01-May-84 13:16:32 (Mike Creech)
%   Added (loadtime (load fc-indirect)).
% 25-Apr-84 09:55:30 (Mike Creech)
%   Added (loadtime (load common)). Changed some comments.
% 03-Apr-84 16:14:58 (Mike Creech)
%   Added (loadtime (load useful)) to pull in macro expansion capability.
% 02-Mar-84 15:56:02 (Mike Creech)
%   Completely revised.  Split up into seperate modules.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
(BothTimes   (load numeric-ops))
% Allow for use of fast vector-fetch and vector-store.
(BothTimes   (load f-vectors))
% Allow for use of evector operations.
(BothTimes   (load f-evectors))
% Need stringify.
(BothTimes   (load strings))
% Need macro expansion when objects are used.
(BothTimes   (load useful))
% Objects (or something objects uses) uses 'listp'.
(BothTimes   (load common))
% Allow use of mutable association list functions -- association-create
% and association-bind.
(BothTimes (load association))
% Defflavor uses the indirect function creation facility.
(BothTimes (load fc-indirect))

(compiletime (on fast-evectors fast-integers fast-vectors))


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% NOTE: THIS FILE DEFINES MACROS.  IT MUST BE LOADED BEFORE ANY OF THESE
% MACROS ARE USED.  The recommended way to do this is to put the statement
% (BothTimes (load objects)) at the beginning of your source file.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% Summary of Public Functions:
%   
% (objects-version)
% (defflavor flavor-name (var1 var2 ...) (flav1 flav2 ...) option1 option2 ...)
% (defmethod (flavor-name message-name) (arg1 arg2 ...) form1 form2 ...)
%
% (make-instance 'flavor-name 'var1 value1 ...)
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
%
% (instantiate-flavor 'flavor-name init-list)
%
% (object-type x)  --- returns the type of an object, or NIL if not an object
%
% (object-copy x)  --- returns a direct copy of an object (see below)
%
% (object-get-handler x message-name) -- lookup method function (see below)
% (object-get-handler-quietly x message-name)
%
% (trace-method-lookups) - start recording stats about method lookup
% (untrace-method-lookups) - stop recording stats about method lookup
% (print-method-lookup-info) - untrace and print accumulated stats
%
% (declare-flavor flavor var1 var2 ...)   NOTE: see warnings below!
% (undeclare-flavor var1 var2 ...)
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Private Constants, Fluids, and Macros (mere mortals should ignore these)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% For information on how the objects package works, see the file:
%    PIG:OBJ-SPEC.IBM
%  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(BothTimes (load obj-hash))
(BothTimes (load obj-lib))
(BothTimes (load obj-dmethod))
(BothTimes (load obj-send))
(BothTimes (load obj-dflavor))
(BothTimes (load objinstance))


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Define new types for the primitive types, to hold method definitions.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(defflavor null () ())

(defflavor pair
    ()
    ()
    (fast-access-for-methods car cdr)
    )

(defmethod (pair car) () (car self))
(defmethod (pair cdr) () (cdr self))

(defflavor integer () ())
(defflavor float () ())
(defflavor vector () ())
(defflavor string () ())
(defflavor symbol () ())

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Make global instances of the primitive types to use for fast message sending
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(setf *$&null-moosefish-object&$*   (make-instance 'null))
(setf *$&pair-moosefish-object&$*   (make-instance 'pair))
(setf *$&int-moosefish-object&$*    (make-instance 'integer))
(setf *$&float-moosefish-object&$*  (make-instance 'float))
(setf *$&vector-moosefish-object&$* (make-instance 'vector))
(setf *$&string-moosefish-object&$* (make-instance 'string))
(setf *$&symbol-moosefish-object&$* (make-instance 'symbol))

% End of file.
