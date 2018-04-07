%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:BREAK-TRACE.SL 
% Description:  Wrappers implementation of a simple break and trace module. 
% Author:       Lucy Berlin, HP/CRC 
% Created:      05-Oct-84 
% Modified:     20-Dec-84 16:46:12 (Lucy Berlin) 
% Mode:         Lisp 
% Package:      
% Status:       Open Source: BSD License
% Compiletime:  PL:OBJECTS.B PL:WRAPPERS.B PL:IF.B 
% Runtime:      PL:OBJECTS.B PL:WRAPPERS.B PL:IF.B 
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
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
% 20-Dec-84 16:43:00 (Lucy Berlin)
%  Modified unwrap-wrapper, do-untrace, do-unbreak to do more errorchecking,
%  and to return functions successfuly unwrapped.  Modified do-restore
%  to use do-unbreak, do-untrace, and to return T.
% 19-Dec-84 17:20:42 (Lucy Berlin)
%  Fixed  bug in unwrap-wrapper, so that it uses new method-function accessor.
% 14-Dec-84 16:39:55 (Lucy Berlin)
%  Redefined breakpoint to take optional parameters of a format string and
% any number of arguments.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%------------------------------ TO DO: ---------------------------------------
%  FUTURE ENHANCEMENTS:
%. do not return the method-fn name, or print self when tracing a method.
%  -- do when new objects come out.
%. extend to handle Commmon LISP constructs: &optional, &rest, &key parameters,
%     multiple values returned by functions, etc.
%  POSSIBLE ENHANCEMENTS:
%. prettyprinting structured arguments & return values, overflow lines.
%  - use Alan Foster's pp?
%. trace output redirection to history file - rebind *trace-output*?
%------------------------------------------------------------------------------

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   KNOWN BUGS  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%. wrapping some fns used within NMODE may cause nmode to crash.
%. debug output doesn't do %f properly when buffer is both input & output channel.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(bothtimes (load objects
		 wrappers
		 if
		 ))

%----------------
% Globals and external variables used

(fluid 
 '(debug-properties                 % global object defined here
   traced-fns-list                  % global list of traced functions
   broken-fns-list                  % global list of broken functions
   debug-depth                      % fluid -- trace indentation level
   within-debug?                    % used to avoid infinite recursion 
   old-prinlevel                    % saves global value before rebinding by debug
   old-prinlength                   % saves global value before rebinding by debug 
   ))

%---------------- Defining Debug Flavor and Customization Fns  -----------------

(defflavor debug-object
  ((output-stream   '"OUTPUT")       % currently not used
   (history-stream    NIL)           % currently not used
   (print-depth       3)             % depth of printing a nested data object
   (print-length      5)             % # elem to print at any level 
                                     % (nil <= no limit)
   (indent-step     3)
   max-indent-col  
   (use-history?    NIL)
   (compile?        NIL)
   )
  ()
  settable-instance-variables 
  initable-instance-variables
  )

(de SET-DEBUG-INDENT-STEP   (integer)
  (=> debug-properties set-indent-step integer))  

(de SET-DEBUG-MAXIMUM-INDENT (integer)
  (=> debug-properties set-max-indent-col integer))

(de SET-DEBUG-PRINT-DEPTH (value)
  (=> debug-properties set-print-depth value))

(de SET-DEBUG-PRINT-LENGTH (value)
  (=> debug-properties set-print-length value))

(de COMPILE-DEBUG-WRAPPERS? (boolean)
  (=> debug-properties set-compile? boolean))

%------------------------ Initializations & redefinitions ----------------

(setf debug-properties 
  (make-instance 
   'debug-object
   'max-indent-col  36
   'compile?        NIL))

(setf traced-fns-list    NIL)
(setf broken-fns-list    NIL)
(setf debug-depth        0)
(setf within-debug?      NIL)

% this allows 'get & 'unwind-protect to be wrapped  even though they are used 
% in break & trace wrapper code.

(if (funboundp '&debug-get) then
  (copyd '&debug-get 'get))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                         Exported Functions
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(defmacro TRACE args
  % Adds a trace wrapper to each legal element of args.
  % A macro is used for do-trace needs a single argument, but the user interface
  % specifies an arbitrary number of arguments.
  `(do-trace ',args))

(defmacro UNTRACE x
  % The macro converts arg*, an arbitrary # of args to a single argument.
  `(do-untrace ',x))

(defmacro TR args
  % same as 'trace; provided for backward compatibility with PSL.
  `(do-trace ',args))

(defmacro UNTR x
  % synonym for 'untrace; provided for backward compatibility with PSL.
  % The macro converts arg*, an arbitrary # of args to a single argument.
  `(do-untrace ',x))

(defmacro RESTR x
  % Turns off both tracing and breaking for all arguments.
  % provided for compatibility with PSL's old debugging package.
  `(do-restore ',x))


(defmacro BR x
  % The macro converts an arbitrary # of args to a single argument.
  `(do-break ',x))

(defmacro UNBR x
  `(do-unbreak ',x))

% BREAKPOINT inserts a continuable break point in code.
% Arguments are optional.  If present, should be [format-string] [arguments].
% Upward compatible with CL, although the format-string will of course change.
(defmacro breakpoint args
  (cond ((null args)
	 `(prog ()
	   (return
	    (setq *continuableerror T)
	    (break)
	    )))
	(T 	 
	`(prog ()
	   (return
	    (printf "User Breakpoint: ")
	    ,(cond ((stringp (eval (car args)))
		    `(printf ,@args))
		    (T `(for (in item ',args)
			     (do (prin1 (eval item)) (spaces 1)))))
	    (terpri)
	    (setq *continuableerror T)
	    (break)
	    )))
	))

(commentoutcode
(de BREAKPOINT ()
  % is there currently a working function 'break' which does this?
  (setf *continuableerror T)
  (break))
)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de DO-TRACE (args)
  % adds trace wrapper to each of fns in args-list, if list is not empty,
  % and returns sublist of fns successfuly traced.  
  % If  args list is empty, returns the names of all traced functions.
  (cond (args
	 (for (IN fn args) 
	      (WITH return-list)
	      % collect names of fns successfuly wrapped into return-list,
              % using adjoin to remove multiple values of NIL.
	      (adjoin (add-trace-wrapper fn) return-list)
	      % delete NIL to return a subset of the list in ARGS.
	      (returns (delete nil return-list))))
        (T traced-fns-list)
	))

(de DO-UNTRACE (args)
  % if there are 0 args, turns off tracing of all functions, else
  % if args exist, turns off tracing of the named functions.
  (cond ((null args)
	 (setf args traced-fns-list)))
  (for (in fn args)
       (with return-list)
       (adjoin (unwrap-wrapper fn 'trace) return-list)
       (returns (delete nil return-list))
       ))

(de DO-BREAK (args)
  % adds break wrapper to each of fns in args-list, if list is not empty,
  % and returns a list containing the fns which were successfuly added to
  % the broken-fns-list.  If ARGS list is empty, returns the names of all 
  % broken fns.
  (cond (args
	 (print-break-help-message)
	 (for (IN fn args) (with return-list)
	      (adjoin (add-break-wrapper fn) return-list)
	      (returns (delete nil return-list))))
        (T broken-fns-list)
	))

(de DO-UNBREAK (args)
  % if there are 0 args, turns off breaking of all functions, else
  % if args exist, turns off breaking of the named functions.
  (cond ((null args)
	 (setf args broken-fns-list)))
  (for (in fn args)
       (with return-list)
       (adjoin (unwrap-wrapper fn 'break) return-list)
       (returns (delete nil return-list))
       ))

(de DO-RESTORE (args)
    % returns T
    (do-untrace args)
    (do-unbreak args)
    T
    )
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de ADD-TRACE-WRAPPER (fn)
  % Wraps fn in trace wrapper, and does initializations:
  %   puts 'fdepth property on fn, adds fn to traced-fns-list, and locally
  %   changes 'debug-depth.
  % The fluid 'debug-depth starts out at 0, and is locally rebound 
  %   within this function, but only after 'indent-col is calculated.
  
  (let* ((fn                  (get-fn-or-method-fn fn))
	 (valid-request?      (ok-to-wrap? fn 'trace)))  % errorchecking

    (cond (valid-request?   % fn is a defined and may be wrapped 
	   (setf traced-fns-list (adjoin fn traced-fns-list))
	   % adjoin adds an element to a set if not already at top level.
	   (put fn 'fdepth 0)
	   (let ((llist         (function-lambda-list fn))
		 (must-compile? (compile-wrapper? fn)))
	     (wrap fn 
		   'trace 
		   `(prog (old-depth)
		      (return
		       (cond 
			(within-debug? (wrapped-invocation))
			(T
			 (setq old-depth debug-depth)
			 (prog (fdepth fn-value)
			   (setq fdepth (add1 (&debug-get ',fn 'fdepth)))
			   (unwind-protect
			    (prog (indent-col debug-depth offset)
			      (setq indent-col  (debug-indent-column old-depth))
			      (setq debug-depth (add1 old-depth))
			      (setq offset 
				(plus2 2 (=> debug-properties indent-step)))
			      (prog (within-debug?)
				(setq within-debug? T)
				(put ',fn 'fdepth fdepth)
				(print-entry-message  
				 indent-col ',fn fdepth)
				(set-debug-print-properties)
				(unwind-protect
				 ,(print-args-expand llist ))
				(restore-print-properties))
			      (setq fn-value (wrapped-invocation))
			      (prog (within-debug?)
				(setq within-debug? T)
				(print-return-message 
				  indent-col ',fn fdepth fn-value))
			      (return  fn-value))           
			    % execute unwind form -- restore fdepth
			    (put ',fn 'fdepth (sub1 fdepth)))
			   %return wrapped-invocation's value.
			   (return  fn-value)
			   )))))   % end of wrapper body
		   must-compile?))
	   fn)
	  )))

(de ADD-BREAK-WRAPPER (fn)
  % Wraps fn in break wrapper, and does initializations:
  % Adds fn to broken-fns-list, and locally changes 'debug-depth.
  % The fluid 'debug-depth starts out at 0, and is locally rebound 
  %   within this function, but only after 'indent-col is calculated.
  
  % If fn is a list, it may be a request to break a method.  If it is, then
  % evaluate the list to get the name of the fn associated with the method.

  (let* ((fn               (get-fn-or-method-fn fn))
	 (valid-request?   (ok-to-wrap? fn 'break)))
    
    (cond (valid-request?
	   (setf broken-fns-list (adjoin fn broken-fns-list))
	   (let ((llist (function-lambda-list fn))
		 (must-compile?    (compile-wrapper? fn))
		 )
	     (wrap fn 
		   'break 
		   `(prog (old-depth)
		      (return
		       (cond 
			(within-debug? (wrapped-invocation))
			(T
			 (setq old-depth debug-depth)
			 (prog (indent-col debug-depth fn-value)
			   (setq indent-col        (debug-indent-column old-depth))
			   (setq debug-depth       (add1 old-depth))  % fluid

			   (prog (within-debug?)
			     (setq within-debug? T)
			     (print-break-message indent-col ',fn 'entry NIL)
			     (breakpoint))
			   (setq fn-value (wrapped-invocation))
			   (prog (within-debug?)
			     (setq within-debug? T)
			     (print-break-message indent-col ',fn 'exit fn-value)
			     (breakpoint))
			   %  return wrapped-invocation's value.
			   (return fn-value )
			   )))))
		   must-compile?))
	   fn)      
	  )))


(de UNWRAP-WRAPPER (fn type)
  % removes BREAK or 'trace  wrapper from fn, if it exists, and
  % removes fn from the global variable TRACED-FNS-LIST or BROKEN-FNS-LIST.
    
  % If fn is a list, it may be a request to break a method.  If it is, then
  % evaluate the list to get the name of the fn associated with the method.
  (let ((typestring (if (eq type 'break) then "broken" else "traced")))
    (setf fn (get-fn-or-method-fn fn))
    (cond ((null fn))
	  ((not (idp fn))
	   (printf "%f***** %p is not an id.%n" fn) nil)
    	  ((funboundp fn)
	   (printf "%f***** %p is not a defined function.%n" fn) NIL)
	  ((wrapper-of-type? fn type)
	   (remove-wrapper fn type)
	   (put fn 'fdepth 0)
	   (cond ((eq type 'trace)
		  (setf traced-fns-list (delete fn traced-fns-list)))
		 (T
		  (setf broken-fns-list (delete fn broken-fns-list)))
		 )
	   fn)
	  (T 
	   (printf "%f*** Function %p was not %w.%n" fn typestring)
	     nil)
	  )))

%------------------- Debugging package internal functions ----------------  

(de GET-FN-OR-METHOD-FN (arg)
  % If fn is actually a list (METHOD flavor-name method-name) then an internal
  % fn is evaluated to return the id of the fn assoc with that flavor's method.
  % Otherwise, just returns the argument.
  (cond ((and (listp arg) 
	      (eq (length arg) 3)
	      (eq (first arg) 'method))
	 (&defflavor-function-name (second arg) (third arg)))
	((listp arg)
	 (printf "%f***** %p is not a valid method-specification.%n" arg))
	(T arg)
	))

(de OK-TO-WRAP? (fn type)
  % Primary error-checking / handling function for adding wrappers of
  %   type 'trace or 'break.
  % Returns id which is a defined function name IFF the function may be
  %   wrapped in a wrapper of type 'type, else returns NIL.
  (let ((typestring (if (eq type 'break) then "broken" else "traced"))
	(compiler-loaded? (member 'compiler options*))
	)
    (cond ((null fn) NIL)
	  ((not (idp fn))
	   (printf "%f***** %p is not an id; cannot be %w.%n" fn typestring) NIL)
	  ((funboundp fn)
	   (printf "%f***** %p is not a defined function.%n" fn) NIL)
	  ((wrapper-of-type? fn type) 	 % don't add wrapper
	   (printf "%f*** Function %p is already %w.%n" fn typestring) NIL)
	  ((and (compile-wrapper? fn)
		(not compiler-loaded?))
	   (printf
	    "%f***** The compiler must be loaded in order to trace or break %p.%n" fn)
	   NIL)
	  (T 
	   fn))
    ))

(de COMPILE-WRAPPER? (fn)
  % returns T iff fn is a defined function which should be wrapped in a
  % compiled wrapper.
  % NOTE: AND evaluates only until it finds a false argument.
  (and (not (funboundp fn))
       (or (not (interpretive-wrapper-ok? fn))
	   (=> debug-properties compile?))
       ))

(de DEBUG-INDENT-COLUMN (debug-depth)
  % calculates the starting column for trace printout, from the values 
  % of the fluid 'debug-depth, and the user's customized trace properties.
  (remainder (times (=> debug-properties indent-step) 
		    debug-depth)
	     (=> debug-properties max-indent-col)))

(de INDENT-FOR-DEBUG (start-col)
  % indents to start-col, printing a vertical bar every indent-step spaces,
  % thus giving a visual guide to for ligning up function entrance & exit.
  % start-col gives the starting column for trace printout.
  (let ((step-size (=> debug-properties indent-step)))
    (printf "%f")
    (cond ((zerop step-size) NIL)
	  ((zerop start-col) NIL)
	  (T 
	   (for (from i 1 start-col step-size)
		(do (printf "|%b" (sub1 step-size)))
		)))
    ))

(de SET-DEBUG-PRINT-PROPERTIES () 
  (setf old-prinlevel prinlevel)
  (setf old-prinlength prinlength)
  (setf prinlevel (=> debug-properties print-depth))
  (setf prinlength (=> debug-properties print-length))
  )

(de RESTORE-PRINT-PROPERTIES () 
  (setf prinlevel old-prinlevel)
  (setf prinlength old-prinlength))

(de PRINT-ENTRY-MESSAGE (start-col fn-name fdepth)
  % prints function name and level, starting at column start-col.
  (cond ((eq fdepth 1)
	 (indent-for-debug start-col)
	 (printf "%p entry:"  fn-name))
	(T
	 (indent-for-debug start-col)
	 (printf "%p reentry (# %p):"  fn-name fdepth))
	)
  )

(de PRINT-ARGS-EXPAND (args-list)
  % executed at macroexpansion time.  Produces code which, when 
  % compiled and executed prints out names and values of the arguments in
  % args-list.
  (cons 'prog 
      (cons '()
	    (for (in arg args-list)
		 (join (print-arg-and-value arg))))))

(de PRINT-ARG-AND-VALUE (arg)
  (list `(indent-for-debug indent-col)
	`(printf "|%b%p :%p%n" offset ',arg ,arg)))


(de PRINT-RETURN-MESSAGE (start-col fn-name fdepth return-value)
  % prints function name (and level) and function return value, starting at
  % column start-col.
  (cond ((eq fdepth 1)
	 (indent-for-debug start-col)
	 (printf "%p value = %p %n"  fn-name  return-value))
	(T
	 (indent-for-debug start-col)
	 (set-debug-print-properties)
	 (unwind-protect 
	  (printf "%p value (# %p) = %p %n" 
		  fn-name fdepth return-value)
	  (restore-print-properties))
	))
  return-value
  )



(de PRINT-BREAK-MESSAGE (start-col fn-name type fn-value)
  % starting at column start-col, 
  % prints function name, and whether at entry or exit (given by type)
  (indent-for-debug start-col)
  (let ((prinlevel (=> debug-properties print-depth))
	(prinlength (=> debug-properties print-Length)))
    (cond ((eq type 'entry)
	   (printf "%p entry BREAK:%n"  fn-name)
	   (indent-for-debug start-col))
	  ((eq type 'exit)
	   (printf "%p exit BREAK, value = %p:%n"  fn-name fn-value)
	   (indent-for-debug start-col))
	  )))


(de PRINT-BREAK-HELP-MESSAGE ()
  % printed when user selects breaking a function or a set of functions.
  (printf "%fIn a break, t prints backTrace; c Continues; q Quits a level;")
  (printf " a Aborts to top.%n"))
