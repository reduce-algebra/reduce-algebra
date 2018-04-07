%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:DEFOBJECT.SL
% Description:  Portable interface to HP PSL 3.4 objects package.
% Author:       Russell D. Fish
% Created:      Fri Jan  3 1986
% Modified:     
% Package:      
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
% Revisions:
%
% 27-May-87 (Harold Carr & Leigh Stoller)
%  Added fluid declaration of rlispscantable*.
% Wed Nov 12 1986 (mueller)
%  Added comiletime fexpr definition of definebop so definebop compiles
%   correctly in a non-rlisp evironment (i.e. pslcomp)
% Wed Oct 22 1986 (mueller)
%  Converted to lisp syntax.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(bothtimes (load objects))
% Make sure codeTemplate gets loaded, even in a non-Rlisp environment.
(bothtimes (load c-template))

% copyInstance - Instead of a never-to-be redifined method for each type,
% just make copyInstance a function. See Alan Snyder's proposal:
% "Object-oriented programming for Common Lisp", section 2.11 for further
% discussion.
(de copyinstance (self) 
    (copyevector self))

% handlesP - Predicate for determining if an object handles a method.
(de handlesp (object methodid) 
    (object-get-handler-quietly object methodid))

% copyObjectL - Copy each object in a list of objects.
(de copyobjectl (objlist) 
    (foreach obj in objlist collect 
	(copyobject obj)))

% remMethod - Given a type id and method id, do a remD on the method procedure.
(de remmethod (type method) 
    (remd (&defflavor-function-name type method)))

% Also use the HP object!-type function as is.

% //////////////  Rlisp method syntax.  //////////////////////////
% 	method procedure FLAVOR METHOD( ARGS );
%			     BODY;
% parses into:
%	(defmethod (FLAVOR METHOD) (ARGS) BODY )
% 
% A send macro is defined to give uniform reference to operations, so
% 	METHOD( Obj, ARGS )
% is equivalent to 
% 	send( Obj, 'METHOD, ARGS )
% Note that send macros need to be declared at compile time for proper
% calling sequences to be compiled.  Thus, the definition of at least one
% method procedure has to lexically precede a call on the method.
% Alternatively, a
% 	declareMethods( METHOD );
% should be in a definitions file.  Multiple methods may be declared in
% a single declareMethods call.

(when (getd 'definebop)       % Don't bother if loaded into a non-RLisp PSL.
	 (flag '(method) 'ftype)             % RLisp parser magic.
         (bothtimes       % "put" does not normally get done at compile time.
	   (put 'method 'functiondefiningfunction 'rlispdefmethod)) 
	 nil)

(defmacro declaremethods methodids
  (prog (retcode) 
    % Collect entries for all of the method IDs.
    (setq retcode 
	(foreach methodid in methodids collect 
	    (codetemplate methodid 
		% Wrap macros in CONDs to avoid redefinition each time.
		(unless (flagp 'methodid 'methodmacro)
		  % The send macro handles varying arglist lengths.
		  (defmacro methodid (obj . args) 
		    (codetemplate obj args (send obj 'methodid @args)))
		  (flag '(methodid) 'methodmacro)))))

    % Wrap in a block if there is more than one entry.
    (setq retcode (cond ((greaterp (length retcode) 1) 
                         (cons 'progn retcode)) 
			(t % Otherwise discard the enclosing list.
			 (first retcode))))
	
    % This code should really be returned wrapped in a "bothTimes", but
    % bothTimes doesn't work below the toplevel in PSL 3.2 .  It is fixed in
    % PSL 3.4 .
    (eval retcode)                      % Gets the compile time side-effect.
    (return retcode)))

% All object types have "describe" and "init" method handlers.
(declaremethods describe init)          % Define "send macros".

(defmacro rlispdefmethod (flavorid ((methodid . arglist)) body)
    (codetemplate methodid (name (list flavorid methodid)) arglist body 
	(progn 
	    (declaremethods methodid) 
	    (defmethod name arglist body))))

% ////////////////  Rlisp "->" (slot reference) syntax.  ////////////////////
% -> is just a little syntactic sugar for those who like C.  Its semantics
% are just to call the RHS procedure on the LHS argument, so
% 	foo->bar
% is the same as either
% 	bar( foo )
% or
% 	bar foo
% -> is intended to be used for object slot references or other
% single-argument method calls that resemble virtual slot references.
% 
% The difference between -> and function calling is that -> groups left to
% right and so works well as a postfix reference qualifier along with [],
% which is also postfix.  This is cleaner for vector-valued slots than
% function calling, which groups right to left and is hard to combine
% properly with [] since the high precedence of "[" plays a part. -> is left
% associative like [] and at the same high precedence level.
% 
% "foo->bar[5]" would otherwise have to be written "(bar foo)[5]".  (Note
% that "bar(foo)[5]" which seems to be reasonable, does NOT do the desired
% thing in this case, producing the same effect as "foo[5]->bar".)

% Make sure definebop compiles correctly under pslcomp.
(compiletime (unless (getd 'definebop) (df definebop (u) (definebopx u))))

% Infix syntax for the -> operator, adapted from := in $pu/rlispparser.sl .
(when (getd 'definebop)       % Don't bomb if loaded into a non-RLisp PSL.
  (definebop 'slotaccess 121 122 parseslotaccess)
  (mynewtok '-> 'slotaccess '! ->! ) 
  (makediphthong rlispscantable* 'rlispdiphthong '- '> '-> )) 

(de parseslotaccess (lhs rhs) 
    (list rhs lhs))                     % Note the reversed order.

% //////////////  Global declarations  //////////////////////////

(fluid '(rlispscantable*))

(bothtimes 
(progn 
    % Lists of fluids used for binding options.
    (fluid '(&defobjectoptions &slotoptions)) 

    (fluid (setq &defobjectoptions 
	'(:constructor :predicate :creator 

	% Objects package options:
	:inheritfrom :allsettable :allgettable :allinitable :allprivate)))

    (fluid (setq &slotoptions 
	% Contains the type expression for the contents of the slot.
	'(:type 

	% Objects package slot options:
	:gettable :settable :initable :private 

	% Alpha_1 modelling options:
	:notcopied))) % Denotes slots that are not copied by copying methods.

    % Accumulator for slot access control options.
    (fluid '(&slotaccess)) 

    % Accumulator for initable variables to be used as "create" macro args.
    (fluid '(&initableslots)) 

    % Slot names which will not be positional arguments to "create" macros.
    (fluid '(&noncreateargs))))

% //////////////  DefObject  /////////////////////////////////////

(defmacro defobject spec
  (prog (structname defaultaccess retcode retcodeptr 
         flavorslots createargs instanceargs flavoroptions 
         &slotaccess &initableslots accesstype sametype nexttype 
				% Bind option fluids, they all get NIL values.
         :constructor :predicate :creator :inheritfrom 
         :allsettable :allgettable :allinitable :allprivate)

    (when (atom spec)                  % Spec must be a list.
       (typeerror spec 'defobject "a spec list"))

    (setq structname (if (atom (first Spec))
			 (first spec)
			 (first (first spec))))    % Grab the struct Id.

    (cond ((not (idp structname))       % Struct id better be one.
	(usagetypeerror structname 'defobject "an id" "a StructName"))) 

    % Non-NIL defaults for options.
    (setq :constructor (setq :predicate t)) 

    % Process option list if present.
    (cond ((pairp (first spec)) 
	(processoptions (rest (first spec)) &defobjectoptions))) 

    % Figure out the default slot access to provide.
    % Default is !:AllSettable, which implies Gettable and Initable.
    (setq defaultaccess nil) 
    (unless (not :allsettable) 
      (when :allgettable
	(setq defaultaccess (cons ':gettable defaultaccess))) % Gettable.
      (when :allinitable
	(setq defaultaccess (cons ':initable defaultaccess))) % Initable.
      (when (and (not defaultaccess) :allprivate)
	(setq defaultaccess (list ':private))))  % No slot access provided.
    
    % Default is !:AllSettable, which implies Gettable and Initable.
    (cond ((not defaultaccess) 
	(setq defaultaccess (list ':settable)))) 

    % Construct macro names in default pattern if necessary.
    (cond ((eq :constructor t)
	   (setq :constructor (idconcat 'make structname)))) 
    (cond ((eq :predicate t) (setq :predicate (idconcat structname 'p))))
    (cond ((eq :creator t) (setq :creator (idconcat 'create structname)))) 

    % Define the constructor and predicate.
    (setq retcode (list 'progn 
	(mkstructmac :constructor 'make structname) 
	(mkstructpred :predicate structname)))

    % For lConc/tConc.
    (setq retcodeptr (list (cons retcode (lastpair retcode))))

    % Define the Selector methods, collect defFlavor slot args.
    (setq flavorslots 
	(foreach slotspec in (rest spec) collect 
	    (processslot slotspec defaultaccess retcodeptr))) 	% Destructive.

    % Construct a create macro if one is desired.  Positional args correspond
    % to the initable slots of the object structure.
    (when :creator
      (setq &initableslots (reverse &initableslots)) 	% Built backwards.
      (setq createargs (foreach slot in &initableslots collect 
        (idconcat slot "&&")))      % Distinguish defmacro args from slot ids.
      (setq instanceargs (foreach slotnameval in 
	    (pair &initableslots createargs) conc 
		(list (mkquote (car slotnameval)) (cdr slotnameval)))) 
      (setf (first retcodeptr) (tconc (first retcodeptr) 
	    (codetemplate structname :creator createargs instanceargs 
		(progn 
		    (defmacro :creator createargs
			(codetemplate @createargs 
			    (make-instance 'structname @instanceargs)))
		     nil)))))

    % Collect the slot access list.
    (cond ((null &slotaccess) 
	   (setq flavoroptions nil))
	  (t 
	    (progn 
	    % Compress slots with similar access to a single option specifier. 
	      (setq accesstype (cdr (first &slotaccess))) 
	      (setq sametype nil) 
	      (foreach sublist on &slotaccess do 
		(progn 
		% Accumulate slot name.
		  (setq sametype (cons (car (first sublist)) sametype)) 

		  % Is this the last one with the same access?
		  (setq nexttype (cond ((null (rest sublist)) nil) 
				       (t (cdr (second sublist))))) 
				       
		  (cond ((neq nexttype accesstype) 
			 (progn 
		 % Yes, accumulate an option specifier and set up for more.
			   (setq flavoroptions 
			     (cons (cons accesstype sametype) flavoroptions)) 
			   (setq accesstype nexttype) 
			   (setq sametype nil)))))))))

    % Define the flavor that is being front-ended.
    (setf (first retcodeptr) (tconc (first retcodeptr) 
	(codetemplate structname flavorslots flavoroptions 
	    (inheritance (cond ((null :inheritfrom) nil) 
			       (t (list :inheritfrom))))
	    (defflavor structname flavorslots inheritance @flavoroptions)))) 

    % Return value of a defObject call is the object type name.
    (setf (first retcodeptr) (tconc (first retcodeptr) (mkquote structname)))

    (return retcode)))

(declaremethods copyobject copystate)   % Methods defined by defObject.

% Process slot specifications, returning slot names with optional init forms.
(de processslot (slotspec defaultaccess retcodeptr) 
  (prog (initform optlist slotname it lhsslotname 
			   % Bind slot option fluids, they all get NIL values.
         :type :settable :gettable :initable :private)

    % Got a few possibilities to unravel.
    (setq initform '*unbound*)          % Need to distinguish NIL initializer.
    (setq optlist nil)                  % Only slot-name required.
    (cond ((atom slotspec) 
	   (setq slotname slotspec))
	  (t    % Bare slot-name, no default-init or options.
	    (progn 
	      (setq slotname (first slotspec)) 
	      % Default-init and/or options provided.
	      (cond ((setq it (rest slotspec))
		     (progn 
		     % See if option immediately after name.
		     % Down to first atom.
		       (while (pairp it) (setq it (first it)))
		       % Option keyword?
		       (cond ((and (idp it) (memq it &slotoptions)) 	
			      (setq optlist (rest slotspec)))
			     (t 	% Yes, no init-form.
			      (progn 
			      % Init-form after keyword.
			        (setq initform (second slotspec)) 
				% Options or NIL.
				(setq optlist (rest (rest

							 slotspec))))))))))))

    (unless (idp slotname)         % Slot id better be one.
	    (usagetypeerror slotname 'defobject "an id" "a SlotName"))

    (when optlist                      % Process option list
	(processoptions optlist &slotoptions))

    % Provide a default access option if none specified as a slot option.
    (unless (or :settable :gettable :initable :private)
	(foreach permission in defaultaccess do 
	    (set permission t))) 

    % Figure out slot access from option flags, remember in terms of the
    % ridiculous keywords used by defFlavor.
    (cond (:settable 
	    (setq &slotaccess (cons 
	         (cons slotname 'settable-instance-variables) &slotaccess))
	    % Settable implies gettable and initable.
	    (setq :gettable (setq :initable t)))
    
	  (:gettable 
	    (setq &slotaccess (cons 
	      (cons slotname 'gettable-instance-variables) &slotaccess))))

    (when :initable 
	  (setq &slotaccess (cons 
	    (cons slotname 'initable-instance-variables) &slotaccess)))

    % Remember initable slots to be used as create macro arguments.
    % Kluge alert: !&NonCreateArgs contains a list of slot names to ignore.
    (when (and :initable (not (memq slotname &noncreateargs)))
	    (setq &initableslots (cons (print slotname) &initableslots)))

    % Declare selector and depositor method macros.
    (when :gettable 
	(setf (first retcodeptr) (tconc (first retcodeptr) 
	    (codetemplate slotname 
		(declaremethods slotname)))))
	
    (when :settable 
	(setq lhsslotname (idconcat "SET-" slotname)) 
	(setf (first retcodeptr) (lconc (first retcodeptr) 
	    (rest (codetemplate slotname lhsslotname 
		(progn 
		    (declaremethods lhsslotname) 

		    % Tell setF it's ok on the left hand side of an assignment.
		    (put 'slotname 'assign-op 'lhsslotname) 
		    (flag1 'slotname 'setf-safe))))))
	
	% The code should really have a "bothTimes put", but bothTimes
	% doesn't work below the toplevel in PSL 3.2. It is fixed in PSL 3.4 .
	(put slotname 'assign-op lhsslotname) 	% Compiletime.
	(flag1 slotname 'setf-safe))  % Compiletime.
    
    % Return a SlotName or ( SlotName InitForm ) list.
    (return (cond ((eq initform '*unbound*) slotname) 
		  (t (list slotname initform))))))

% //////////////  Internal fns  //////////////////////////////////

% Process defObject and slot options, binding values of valid options. 
(de processoptions (optlist optvarlist) 
  (prog (option optarg) 
    (foreach optspec in optlist do 
      (progn 
	(cond ((atom optspec)           % Bare option id.
	         (setq option optspec) 
		 (setq optarg t))
	      (t 
	         (setq option (first optspec)) 
		 (setq optarg (rest optspec)) 	% List of args to option.
		 (unless (rest optarg)		% Single arg, unlist it.
		    (setq optarg (first optarg)))))

	(cond ((memq option optvarlist) 
		 (set option optarg))
	      (t 
		 (usagetypeerror option 'processoptions 
		    (cons "one of" (cons optvarlist "is needed")) 
			"an option id")))))))

% //////////////  Fn building fns  ///////////////////////////////

% Fn to build specific Structure Fns as macros which use generic macros.
% The generic macro is called with the StructName and the original
% list of arguments.
%     MacName( arg1, arg2, ... )
%      => GenericMac( StructName, arg1, arg2, ... )
(de mkstructmac (macname genericmac structname) 
    (cond ((null macname) nil)        % No macro if unless name given.
	  (t
	    (second (codetemplate macname genericmac structname 
	      (progn 
		(dm macname (args) 
		    (append '(genericmac structname) (rest args)))))))))

% Fn to build specific Structure Predicates.
(de mkstructpred (fnname structname) 
    (second (codetemplate fnname structname 
	(progn 
	    (de fnname (predarg) 
		(eq (object-type predarg) 'structname)) nil))))

% //////////////  Fns used by macros.  ///////////////////////////

% Generic macro for constructors, called with structure name and list
% of "slot-name(value-form)" lists to override the default-inits.
% Returns an object make-instance constructor.
(defmacro make (structname . slotspecs)
  (prog (initseq)
    % Convert SlotSpecs to an initialization list.
    (setq initseq (foreach nameexpr in slotspecs conc 
 	% Quote slot names.
	(list (mkquote (first nameexpr)) (second nameexpr))))

    (return (codetemplate structname initseq 
	(make-instance 'structname @initseq)))))

% End of file.
