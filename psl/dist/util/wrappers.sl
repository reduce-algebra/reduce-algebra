%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:WRAPPERS.SL 
% Description:  A wrapper facility for PSL 
% Author:       Cris Perdue, Hewlett-Packard Laboratories 
% Created:      13-Mar-84 
% Modified:     21-Dec-84 10:28:24 (Lucy Berlin) 
% Mode:         Lisp 
% Package:      
% Status:       Open Source: BSD License
% Compiletime:  PL:IF.B PL:SYS-CONSTS.B 
% Runtime:      PL:SYS-CONSTS.B 
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
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
% 11-Dec-84 16:35:15 (Lucy Berlin)
%  Loaded sys-consts & removed setq of maxargs.
% 14-Nov-84 10:24:44 (Lucy Berlin)
%  Changed wrap to refer to switch *pwrds rather than *pwds.
% 13-Nov-84 17:36:09 (Lucy Berlin)
%  Redefined the switch *pwds locally within a part of fn wrap. (To suppress
%  the message *** fn-name: base 16#FF...., length 10#.... bytes
%  when compiling a wrapper.)
% 12-Nov-84 17:27:57 (Lucy Berlin)
%  Fixed bug in search-for-wrapper, & in setting 'wrapper-type property.
%  Now 'wrapped-definition contains just the pointer to the next layer,
%  and 'wrapper-type holds the name of the wrapper type.
% 12-Nov-84 16:13:06 (Lucy Berlin)
%  Added the public function (compiled-wrapper-only-fns), and made
%  unwind-protect a member of non-interp-wrappable-fns.
%  set maxargs = 20 for lack of a better thing to do.
% 07-Nov-84 09:00:17 (Cris Perdue)
%  (newid fn) ==> (newid (id2string fn)).
% 02-Nov-84 17:11:48 (Cris Perdue)
%  Now wrapping of functions with "any" number of arguments is
%  prohibited.  (These are inherited method functions).  Fixed a bug
%  in wrapping of undefined functions.  Wrappers now take the name
%  of the basic function, but are uninterned.
% 30-Oct-84 18:13:25 (Cris Perdue)
%  Added the concept of functions that are not wrappable.
% 25-Oct-84 11:09:48 (Cris Perdue)
%  Changed wrap and remove-wrapper to rebind *usermode and
%  *redefmsg to nil.
% 09-Oct-84 15:57:33 (Cris Perdue)
%  Extended WRAP to handle a lambda expression in place of the
%  previous BODY argument.  If a lambda expression is supplied,
%  only the symbol WRAPPED-FUNCTION is substituted for rather
%  than occurrences of the expression (wrapped-invocation).  A
%  function may now have more than one wrapper of each type.
%  New wrappers are for now always added as the outermost of
%  their type.
% 10-May-84 17:17:42 (Bob Shaw)
%  Changed occurrence of < to lessp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load if))
(bothtimes (load sys-consts))     % for maxargs;  may not need to be bothtimes

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Overview:
% 
% A wrapper conceptually is a redefinition of a function.
% Usually a wrapper calls the previous definition, doing
% some additional work before and/or after calling the previous
% definition.  Typically a wrapper may be added to a
% function and later removed.  A function potentially may be
% wrapped up inside more than one wrapper at the same
% time.  The user may decide to redefine a function that is
% wrapped or to access its definition.  This facility does
% bookkeeping to support these operations on functions that may
% or may not already be wrapped.
% 
% The wrapper-standard-order supports keeping "advice"
% inside breaking inside tracing, etc..
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Issue: can we arrange better names for wrappers?  A problem is
% that each wrapper knows the identity of the function it calls,
% so wrappers "must" work by putting a new definition on an
% existing symbol, or it will never get called.  Problem is
% that a symbol may be associated with different wrappers at
% different times.  Possible approach: give the FUNDEFs of
% wrappers names appropriate to the type of wrapper.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% wrapper-standard-order is a list of recognized
% wrapper types in order.  The outermost type of
% wrapper appears first on the list.
(fluid '(wrapper-standard-order))
(if (null wrapper-standard-order) then
  (setq wrapper-standard-order
    '(trace break meter)))

% Functions internal to the "normal" operation of the
% interpreter, functions liable to be called in the case where
% the fluid variable is non-NIL, and functions liable to be
% called from the wrapper without the fluid variable rebound to
% a non-NIL value must not be wrapped.
%
(fluid '(non-interp-wrappable-fns))
(if (null non-interp-wrappable-fns) then
  (setq non-interp-wrappable-fns
    '(eval bindeval bindevalaux evprogn valuecell unbindn lbind1 
	   funboundp fcodep getfcodepointer lambdaapply saveregisters
	   codeevalapply lambdaevalapply evlis cons get mapcar
	   compiledcallinginterpreted compiledcallinginterpretedaux
	   compiledcallinginterpretedauxaux restoreenvironment pbind1
	   flambdalinkp cond prog progn setq return unwind-protect)))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Exported wrapper fns
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Public operations and predicates:
% 
% (wrap FN:id  TYPE:id  BODY:any COMPILE?:boolean): id                   expr
% (remove-wrapper FN:id TYPE:id): boolean                                expr
% (wrapper-of-type? FN:id TYPE:id): {fn,nil}                             expr
% (function-lambda-list FN:{id,code-ptr,lambda-expression}): list        expr
% (function-basic-definition FN:id): fn                                  expr   
% (interpretive-wrapper-ok? FN:id): boolean                              expr
% (compiled-wrapper-only-fns): list                                      expr
% (wrapper-types FN:id): list                                            expr
% (wrapped? FN:id): boolean                                              expr
% wrapper-standard-order: list                                          fluid
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Puts a wrapper of type TYPE on FN.  Signals an error if
% one  of that type  already exists for  FN.  The  body arg will
% have an appropriate invocation substituted for all occurrences
% of the form (wrapped-invocation).
(de wrap (fn type body compile?)
  (if (and (not compile?) (not (interpretive-wrapper-ok? fn))) then
    (stderror (bldmsg "Can't put interpretive wrapper on %p." fn)))
  (let ((prev (search-for-wrapper fn type)))
    %    (if (eq (wrapper-type prev) type) then
    %      (continuableerror
    %       99
    %       (bldmsg "Function %r already has a wrapper of type %r."
    %	       fn type)
    %       nil))
    (let* ((sym (newid (id2string fn)))
	   (defn (getd prev))
	   (fntype (if defn then (car defn)))
	   % Compute lambda list now so error case for functions
	   % with unknown number of arguments happens before
	   % redefinitions are done.
	   (lambda-list (function-lambda-list prev)))
      % Give the new ID the old definition and wrapper
      % type if any.
      (basic-copyd sym prev)
      (if (get prev 'wrapper-type) then
	(set-wrapper sym prev (get prev 'wrapper-type)))
      % Now redefine prev
      (let ((lambda-form
	     (if (eqcar body 'lambda) then
	       (subst sym 'wrapped-function body)
	       else
	       `(lambda ,lambda-list
		  ,(subst
		    (if (memq fntype '(macro fexpr nexpr))
		      then
		      `(funcall ',sym ,.lambda-list)
		      elseif (eq fntype 'expr) then
		      (cons sym lambda-list)
		      else (stderror
			    (bldmsg "Unknown function type %r in WRAP."
				    fntype)))
		    '(wrapped-invocation)
		    body))))
	    (*usermode nil)
	    (*redefmsg nil))
	(basic-putd
	 prev fntype
	 (if compile? then
	   (let ((*pwrds nil))
	     % Compile into a code pointer if to be compiled.
	     (compd '***code**pointer*** 'expr lambda-form))
	   else lambda-form)))
      % Note that PREV is now a wrapper containing SYM
      (set-wrapper prev sym type)
      fn)))

(de interpretive-wrapper-ok? (id)
  (not (memq id non-interp-wrappable-fns)))

(de compiled-wrapper-only-fns ()
  % Lists the fns which need their wrappers to be compiled.
  non-interp-wrappable-fns)

% Removes the wrapper of type TYPE from FN if there is any
% such.  Returns T if anything removed, else NIL.
(de remove-wrapper (fn type)
  (let ((nominee (search-for-wrapper fn type)))
    (if (eq (wrapper-type nominee) type) then
      (let ((inner-fn (wrapped-function nominee))
	    (*usermode nil)
	    (*redefmsg nil))
	(basic-copyd nominee inner-fn)
	(if (wrapper-type inner-fn) then
	  (set-wrapper nominee (wrapped-function inner-fn)
			     (wrapper-type inner-fn))
	  else
	  (mark-not-wrapper nominee)))
      t
      else nil)))

% Returns wrapper of TYPE if exists, else NIL.
(de wrapper-of-type? (fn type)
  (let ((inner (search-for-wrapper fn type)))
    (if (eq (wrapper-type inner) type) then
      inner
      else nil)))

% Gets the function's lambda list or invents one if the function
% is compiled.  Arg may be ID, code pointer, or lambda expression.
(de function-lambda-list (fn)
  (if (idp fn) then
    (let ((defn (getd fn)))
      (if (null defn) then
	(stderror (bldmsg "%r is not defined as a function." fn)))
      (setf fn (cdr defn))))
  (if (codep fn) then
    (let ((n (code-number-of-arguments fn)))
      (if (not (numberp n)) then
	(stderror (bldmsg "Unknown number of args to %p" fn)))
      (make-n-var-names n))
    elseif (eqcar fn 'lambda)
    then (second fn)
    else (stderror (bldmsg "%r is not a function." fn))))
  
(de wrapped? (fn)
  (if (wrapper-type fn) then t else nil))

% Returns descriptive information: a list of each of the types
% of each of the wrappers of the function (id) given, in order
% from outside in.
(de wrapper-types (fn)
  (for (for f fn (wrapped-function f))
       (while (wrapped-function f))
       (collect (wrapper-type f))))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Candidate public function
%
% I'll make it public and document if it is shown to be needed.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Predicate that tells whether the argument names for its
% function argument should be considered "invented" as opposed
% to being the names specified by the author.  Potentially
% useful for function traceing utilities.
(de invent-arg-names? (fn)
  (if (idp fn) then
    (let ((defn (getd fn)))
      (if (null defn) then
	(stderror (bldmsg "%r is not defined as a function." fn)))
      (setf fn (cdr defn))))
  (if (codep fn) then t
    elseif (eqcar fn 'lambda)
    then nil
    else (stderror (bldmsg "%r is not a function." fn))))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Internal functions
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Given a symbol, which may be a wrapper, searches
% through wrappers until a function is found that is
% either not wrapped or has a wrapper type that is
% the same as TYPE or one that should be nested within
% wrappers of type TYPE.  The function found is returned,
% and one is always found.  TYPE of NIL means find the basic
% definition (the one that is not a wrapper).
(de search-for-wrapper (fn type)
  (let ((types-to-find (memq type wrapper-standard-order)))
    (if (and type (null types-to-find)) then
      (stderror (bldmsg "%r is not a registered wrapper type."
			type)))
    (while t
      (let ((found-type (wrapper-type fn)))
	(cond ((or (null found-type) (memq found-type types-to-find))
	       (return fn))
	      (T 
	       (setf fn (wrapped-function fn))))))))

(de function-basic-definition (fn)
  (search-for-wrapper fn nil))

(fluid '(wrapper-var-names))

(setq wrapper-var-names
  (for (from i 1 maxargs)
       (collect (newid (bldmsg "ARG%p" i)))))

% Makes a list of N ID's for a wrapper to use in a
% created lambda list.  Error if it can't make enough names.
(de make-n-var-names (n)
  (let ((var-list
	 (for (in var wrapper-var-names)
	      (from i 1 n)
	      (collect var))))
    (if (lessp (length var-list) n) then
      (stderror
       (bldmsg "Failed to make an argument list of length %p -- MAKE-N-VAR-NAMES."
	       n)))
    var-list))

% Returns the number of arguments of "something applicable" as
% determined from the function's own perspective, i.e. the number
% of arguments it RECEIVES.  Handles as many cases as possible.
% Signals an error if the number cannot be determined.
(de fn-number-of-arguments (fn)
  (if (idp fn) then
    (let ((defn (getd fn)))
      (if (null defn) then
	(stderror (bldmsg "%r is not defined as a function." fn)))
      (setf fn (cdr defn))))
  (if (codep fn) then
    (code-number-of-arguments fn)
    elseif (eqcar fn 'lambda)
    then (length (second fn))
    else (stderror (bldmsg "%r is not a function." fn))))
  
% Copydh that does NOT hack wrappers
(de basic-copyd (to from)
  (let ((defn (basic-getd from)))
    (if (null defn) then
      (continuableerror
       99 (bldmsg "%r has no definition in BASIC-COPYD." from)
       nil))
    (basic-putd to (car defn) (cdr defn))))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Operations on "function specs" (currently IDs):
%
% An inner layer of modularity within the wrapper module.
% 
% (wrapper-type fun-spec)
% Obtains the wrapper type of the function, NIL if not a
% wrapper.
% 
% (wrapped-function fun-spec)
% Returns the function spec "immediately enclosed" by the given
% function spec, or NIL if the given function is not a
% wrapper.
% 
% (set-wrapper fn inner-fn type)
% Records fn as a wrapper of the given type on the
% inner-fn.
% 
% (mark-not-wrapper fn)
% Perhaps delete-wrapper would be a better operation to
% supply than this, which just un-records what set-wrapper
% records.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Returns the type of the wrapper that fun-spec is or NIL
% if it is not a wrapper.  Fun-spec is assumed to be an
% ID at present.
(de wrapper-type (fun-spec)
  (get fun-spec 'wrapper-type))

% Returns the function wrapped by fun-spec or NIL, similar
% to the function wrapper-type.
(de wrapped-function (fun-spec)
  (get fun-spec 'wrapped-definition))

% Establishes FN as a wrapper on INNER-FN, of type TYPE.
(de set-wrapper (fn inner-fn type)
  (put fn 'wrapped-definition inner-fn)
  (put fn 'wrapper-type type))

% Marks as not a wrapper
(de mark-not-wrapper (fn)
  (remprop fn 'wrapped-definition)
  (remprop fn 'wrapper-type))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Initializations and redefinitions
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(if (funboundp 'basic-putd) then
  (copyd 'basic-putd 'putd))

(if (funboundp 'basic-getd) then
  (copyd 'basic-getd 'getd))

(de putd (fn type defn)
  (basic-putd (function-basic-definition fn) type defn))

(de getd (fn)
  (basic-getd (function-basic-definition fn)))

