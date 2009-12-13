%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PC:ANYREG-CMACRO.SL
% Title:          Table-driven Anyreg and C-macro expander
% Author:         Eric Benson
% Created:        17 December 1981
% Modified:       14-Sep-84 07:58:13 (Brian Beach)
% Package:        Compiler
%
% (c) Copyright 1987, University of Utah, all rights reserved.
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 15-Aug-87 (Leigh Stoller)
%  Removed all internal functions. No longer considered proper.
% 23-Mar-84 07:28:36 (Brian Beach)
%  Removed wconstevaluable-for-compiler.  Now handled by CONSTANT? and others.
% 02-Mar-84 09:02:54 (Jim Ambras/CRC)
%  Corrected file header.
% 17-Jan-84 12:00:50 (Tim Tillson)
%  Added wconstevaluable-for-compiler, which evaluates expressions only if the
%  functions have the DOFN property (was a bug in ASSOCPV in compiler.sl).
% 06-Dec-83 10:00 (Brian Beach)
%   New header.
% 20-NOV-83 Mark R. Swanson
%  Added Expand3OperandCMacro to support !specifically! !*MkBPtr cmacro
% November 10, 1983  Brian Beach
%   Changed WCONSTEVALUABLE so that it handles expressions with
%   explicit WCONSTs.
% June 29, 1983  Michael Creech
%   Minor code changes for efficiency and commented the code.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% General questions and comments:
%    - I believe the DOFN property is NOT needed as far as this module
%      is concerned.  This is because it maps to real lisp functions
%      that can be used anyway.  For example, (WCONSTEVALUABLE
%      '(WPLUS2 3 5) maps to (PLUS2 3 5) when DOFN is used.  However,
%      (PLUS2 3 5) is itself legal and will generate the value 8.
%
%    - Why does ResolveWConst return IMMEDIATE when the expression
%      is not a number?
%    
%    - Method of generating labels within CMACRO's should be cleaned up.
%      Currently, TempLabel!* and TempLabel2!* are used in a funny way.
%      They are defined as prog variables in CMacroSubstitute and
%      are set in TempLabelGen which is only used by PatternSublA.
%
%    - Find out if ok to change name of AnyRegPatternMatch to PatternMatch.
%      It is used for pattern matching for both anyreg's and cmacro's.
%      Need to find where else in the compiler it is used.
%    
%    - Functions order of definition should change.  All high-level ANYREG
%      and CMACRO expand functions should be at the top.
% 
%    - The current use of ResultingCode!* should change.  It is currently
%      very dangerous.  If AnyRegPatternExpand is ever called from a function
%      that doesn't have a fluid ResultingCode!*, it will fail.  This
%      currently works because a CMACRO expanding function is always
%      called at the highest level (these all define a prog variable
%      ResultingCode!*) even though many nested calls to ANYREG 
%      pattern exanders may be called (these don't define ResultingCode!*).
%
%    - Can ExpandThreeArgumentAnyreg go away? Where is it called?
%
% The calling structure of code in this module follows.  An indented
% function is called by a less indented function.  '*' means routine
% calls itself.  Comments may follow functions in parenthesis.
%
%    OneOperandAnyreg  (similar for TwoOperandAnyreg)
%       ExpandOneArgumentAnyreg
%          AnyregPatternExpand
%             AnyregSubstitute
%                Safepair*
%                AnyregSubstitute1*
%             AnyregPatternMatch*
%                AnyregPatternMatch1
%                   Matchall*
%       ResolveOperand
%          (calls applied resolution functions)
%          ResolveWconst
%             ResolveWconstExpression*
%                WConstEvaluable*
%                   WConstEvaluabLis* (calls WConstEvaluable)
% 
% Similiarly, for CMACRO's we have:
% 
%    Expand1OperandCMacro , Expand2OperandCMacro , Expand4OperandCMacro
%       CMacroPatternExpand
%          CMacroSubstitute
%             SafePair
%             CMacroSubstitute1*
%                PatternSub1A*
%                   TempLabelGen
%          AnyregPatternMatch
%             ... (same as above)
%       ResolveOperand
%          ... (same as above)
% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(ResultingCode!* TempLabel!* TempLabel2!*))

% Generated code is collected in reverse order in ResultingCode*

(dm DefAnyreg (Form)

% This macro is called with the form:
%    (defanyreg <name> <func> (a) (b) ... (n))
% It returns the form:
%    (progn
%       (put '<name> 'anyregresolutionfunction '<func>)
%       (put '<name> 'anyregpatterntable '((a) (b) ...(n)))
%    )
% which is itself evaluated.
% NOTE: Possibly change in the future to use "quasi-quote" read-macro
%       to build structure.

  (let
       ((AnyregName   (second form))
	(FunctionName (third form))
	(Pattern      (cdddr form)))

       (list 'progn
	      (list 'put
		    (MkQuote AnyregName)
		    '(quote AnyregResolutionFunction)
		    (MkQuote FunctionName))
	      (list 'put
		    (MkQuote AnyregName)
		    '(quote AnyregPatternTable)
		    (MkQuote Pattern)))))

(dm DefCMacro (Form)

% This macro is called with the form:
%    (defcmacro <name> <func> (a) (b) ... (n))
% It returns the form:
%    (progn
%       (flag '(<name>) 'mc)
%       (put '<name> 'cmacropatterntable '((a) (b) ...(n)))
%    )
% which is itself evaluated.
% NOTE: Possibly change in the future to use "quasi-quote" read-macro
%       to build structure.

  (let 
       ((CMacroName (second form))
	(Pattern    (cddr form)))

       (list 'progn
	      (list 'flag
		    (MkQuote (list CMacroName))
		    '(quote MC))
	      (list 'put
		    (MkQuote CMacroName)
		    '(quote CMacroPatternTable)
		    (MkQuote Pattern)))))

(de ResolveOperand (Register Source)

  % 'Register' is a register used to hold temporary calculations
  % Only the resolution functions called use it (not this routine).
  % This function performs the following operations on 'source':
  % If source is an atom (not a pair), return it.
  % If source is an identifier it is "resolved" (see ResolveWconst below).
  % If source is a pair:
  %    - If flagged TERMINALOPERAND, return the pair.
  %    - If the car of the pair has an ANYREGRESOLUTIONFUNCTION
  %      on its property list, apply it to the rest of the pair.
  %    - Otherwise "resolve" the pair.
  %  NOTE: Remove prog with resolveanyregfunction in the future.
  %        PROG and RETURN slower then extra GET time (probably).

  (prog (ResolveAnyregFunction)
    (return (cond
	     ((IDP Source) (ResolveWConst Source))
	     ((atom Source) Source)               
	     ((FlagP (car Source) 'TerminalOperand) Source) 
	     ((setq ResolveAnyregFunction
		(get (car Source) 'AnyregResolutionFunction))
	      (Apply ResolveAnyregFunction
      	       (cons Register (cdr Source))))
	     (t (ResolveWConst Source))))))

(de ResolveWConst (Expression)

% "Resolve" Expression (See ResolveWConstexpression below).
% If it resolves to a number, return it.
% Otherwise return: (IMMEDIATE <expression>).

  (let ((ResolvedExpression (ResolveWConstExpression Expression)))
    (cond ((NumberP ResolvedExpression) ResolvedExpression)
	  (t (list 'Immediate Expression)))))

(de ResolveWConstExpression (Expression)

  % NOTE: Expression must be a string, number, identifier, or pair.
  %       Anything else will lead to an error.
  %
  % Return the "resolved" expression, where "resolved" is recursively
  % defined as follows:
  %    If expression is of the form: (WCONST <expr>), return the
  %    resolved <expr>.
  %    If the expression is a number or a string, return it.
  %    If expression is an identifier, return the value associated with
  %    the WCONST property under that identifier.  If no such property
  %    exists, return the identifier.
  %    If expression is a pair in which the first element is a macro
  %    name, expand the expression as a macro and resolve it.
  %    If expression is a pair, build a list with the first element of
  %    it and all the rest of the elements after they have been resolved,
  %    then WCONSTEVALUABLE the list.
  %    If this list is not WCONSTEVALUABLE (returns nil) then simply
%    return the list.  Some examples follow:
%       1                             =>   1
%       "joe"                         =>   "joe"
%       (WCONST 3)                    => 3
%       joe                           => 8 (assume has (WCONST . 8) on
%                                           property list)
%       joe                           => joe (Has no WCONST property)
%       (PLUS 3 5)                    => 8
%       (PLUS (PLUS 3 5) (TIMES 6 1)) => 14
%       ((PLUS 3 5) (TIMES 6 1))      => ((PLUS 3 5) 6)

  (cond 
   ((EqCar Expression 'WConst)
    (ResolveWConstExpression (cadr Expression)))
   ((or (NumberP Expression) (StringP Expression))
    Expression)
   ((IDP Expression)
    (or (Wconstevaluable expression) Expression))
   ((MacroP (car Expression))
    (ResolveWConstExpression (Apply (car Expression)
				    (list Expression))))
   (t
    (setq Expression
      (cons (car Expression)
	    (MapCar (cdr Expression)
		    (Function ResolveWConstExpression))))
    (or (WConstEvaluable Expression) Expression))))


(de WConstEvaluable (Expression)

  % If expression is a number, return it.  If it is an identifier,
  % return the constant value associated with it (if none
  % exists then return nil).  If expression is of the form: (ID ...),
  % then if the identifier is a macro, expand it and WCONSTEVALUABLE the
  % result.  If the identifier has DOFN as a property on its property
  % list, take the value associated with the property and use it as a
  % function (see below).  If the identifier has no DOFN property but it
  % is a function, use it.  If the rest of the list (ID ...) is not
  % WCONSTEVALUABLE, then return nil, otherwise return the function
  % applied to the WCONSTEVALUABLE'd arguments.  All other cases return
  % NIL.  Some examples follow:

  %      NIL           => NIL
  %      1             => 1
  %      (WCONST 3)    => 3
  %      ((joe arg) 3) => NIL  (car of the pair is not an ID)
  %      (WPLUS2 3 5)  => (PLUS2 3 5) => 8 
  %      "Joe"         => NIL
  %      JOE           => 8    (If JOE is defined to be a constant)
  %      (WCONST JOE)  => 8    (If JOE is defined to be a constant)
  %      JOE           => NIL  (If JOE is not defined to be a constant)
  %      (PLUS 3 5)    => 8
  %      (STRING-LENGTH "JOE") => NIL ("JOE" will be WCONSTEVALUABLE'd
  %                                     and return NIL)

  (cond
   ((null expression)          nil)
   ((numberp expression)       expression)
   ((idp expression)           (when (constant? expression) (constant-value expression)))
   ((not (pairp expression))   nil)
   ((eqcar expression 'wconst) (wconstevaluable (second expression)))
   ((macrop (car expression))  (wconstevaluable (apply (car expression)
						       (list expression))))
   (t  
    (let ((function (or (get (car expression) 'DOFN)
			(car expression)))
	  (parms    (wconstevaluablis (rest expression))))
      (when (and (idp function) (not (funboundp function)) (neq parms 'not))
	(eval (cons function parms))
	)))))

(de WConstEvaluabLis (ExpressionTail)

  % This function is called to evaluate the tail of a pair of the form:
  % (ID arg1 arg2 ... argn) Check that each element in the tail
  % (ExpressionTail) is WCONSTEVALUABLE and return the list of all the
  % WCONSTEVALUABLE'd elements.  If any element of the tail fails to be
  % WCONSTEVALUABLE, return 'NOT'.

  (prog (WC WCLis)
    (return
     (cond ((null ExpressionTail) NIL)
           ((atom ExpressionTail) 'not)
	   ((not (setq WC (WConstEvaluable (car ExpressionTail)))) 'not)
	   ((eq (setq WCLis (WConstEvaluabLis (cdr ExpressionTail)))
		'not)
	    'not)
	   (T (cons WC WCLis))))))
        

% OneOperandAnyreg and TwoOperandAnyreg return a TLM-like operand (it
% may undergo some further processing before it is a true TLM
% instruction) by returning the right patterns from the pattern table
% from the property list of 'AnyregName'.  Also, these functions may
% generate TLMI (TLM Instructions) on the fluid variable
% ResultingCode!*. 'Register' is the expression to generate in TLM
% operands that require a temporary for some reason (like *MOVE source
% dest, where source and dest use the same register).  For example,
% (REG T1).  'Source' and 'SecondArg' are the ALM or TLM operands to
% generate other TLM instructions from.  These arguments are first
% 'resolved' (see ResolveOperand for details) and then used to replace
% the variables within the correct patterns (TLMI) returned.

(de OneOperandAnyreg (Register Source AnyregName)
  (ExpandOneArgumentAnyreg Register
			   (ResolveOperand Register Source)
			   AnyregName))

% ExpandOneArgumentAnyreg, ExpandTwoArgumentAnyreg, and
% ExpandThreeArgumentAnyreg work as described above OneOperandAnyreg.
% Only difference is that 'Source', 'SecondArg', and 'ThirdArg' are
% NOT resolved.

% SecondArg must not require a register for evaluation.
% It is currently used only for (MEMORY reg const).

(de TwoOperandAnyreg (Register Source SecondArg AnyregName)
  (ExpandTwoArgumentAnyreg Register
			   (ResolveOperand Register Source)
			   (ResolveOperand '(REG Error) SecondArg)
			   AnyregName))

(de ExpandOneArgumentAnyreg (Register Source AnyregName)
  (AnyregPatternExpand (list Register Source)
		       (get AnyregName 'AnyregPatternTable)))

(de ExpandTwoArgumentAnyreg (Register Source SecondArg AnyregName)
  (AnyregPatternExpand (list Register Source SecondArg)
		       (get AnyregName 'AnyregPatternTable)))

(de ExpandThreeArgumentAnyreg (Register Source SecondArg ThirdArg AnyregName)
  (AnyregPatternExpand (list Register Source SecondArg ThirdArg)
		       (get AnyregName 'AnyregPatternTable)))

(de AnyregPatternExpand (ArgumentList PatternTable)

% Return the replacement part of PatternTable (PatternTable is
% described in AnyregPatternMatch below) with variables within it
% substituted for actual values from the ArgumentList.  This
% replacement part usually corresponds to TLM (or almost TLM)
% instructions.  Only the last replacement part is returned.  The rest
% are added to the value of ResultingCode!*.

% NOTE: This function must always be called indirectly from a function
% that has a fluid ResultingCode!* (like the CMACRO expanders) or it
% will barf!

% ArgumentList is of the form: (<register> . <source>) where
% <register> is 'Register', described above OneOperandAnyreg.
% <source> is the list of arguments to the operand.  They may or may
% not have been resolved depending on where this function was called
% from.

  (AnyregSubstitute ArgumentList
		    (AnyregPatternMatch (cdr ArgumentList) PatternTable)))

        
% The functions Expand(1,2,3,4)OperandCMacro return a list of TLM or
% almost TLM instructions (TLMI) (they may undergo some further
% processing before they are true TLMI) by returning the right
% patterns from the pattern table from the property list of
% 'CMacroName'.  TLMI are also potentially generated by the resolution
% of the other arguments ( 'Arg1', 'Arg2', 'Arg3', and 'Arg4') given.
% These arguments are first 'resolved' (see ResolveOperand for
% details) and then used to replace the variables within the list of
% correct patterns (TLMI) returned.

(de Expand3OperandCMacro (Arg1 Arg2 Arg3 CMacroName)
  (prog (ResultingCode!*)
    (return (CMacroPatternExpand (list (ResolveOperand '(REG t1) Arg1)
				       (ResolveOperand '(REG t2) Arg2)
				       (ResolveOperand '(REG Error) Arg3))
				 (get CMacroName 'CMacroPatternTable)))))


% The label operand must not require a register to resolve.

(de Expand2OperandAndLabelCMacro (Arg1 Arg2 Label CMacroName)
  (prog (ResultingCode!*)
    (return (CMacroPatternExpand (list (ResolveOperand '(REG t1) Arg1)
				       (ResolveOperand '(REG t2) Arg2)
				       (ResolveOperand '(REG Error) Label))
				 (get CMacroName 'CMacroPatternTable)))))

(de Expand4OperandCMacro (Arg1 Arg2 Arg3 Arg4 CMacroName)
  (prog (ResultingCode!*)
    (return (CMacroPatternExpand (list (ResolveOperand '(REG t1) Arg1)
				       (ResolveOperand '(REG t2) Arg2)
				       (ResolveOperand '(REG Error) Arg3)
				       (ResolveOperand '(REG Error) Arg4))
				 (get CMacroName 'CMacroPatternTable)))))

(de Expand2OperandCMacro (Arg1 Arg2 CMacroName)
  (prog (ResultingCode!*)
    (return (CMacroPatternExpand (list (ResolveOperand '(REG t1) Arg1)
				       (ResolveOperand '(REG t2) Arg2))
				 (get CMacroName 'CMacroPatternTable)))))

(de Expand1OperandCMacro (Arg1 CMacroName)
  (prog (ResultingCode!*)
    (return (CMacroPatternExpand (list (ResolveOperand '(REG t1) Arg1))
				 (get CMacroName 'CMacroPatternTable)))))

(de CMacroPatternExpand (ArgumentList PatternTable)

% Return the replacement part of PatternTable (PatternTable is
% described in AnyregPatternMatch below) with variables within it
% substituted for actual values from the ArgumentList (also see
% AnyregPatternMatch for details).  These patterns usually correspond
% to TLM, or almost TLM, instructions.  This function returns the list
% of ALL such patterns from PatternTable (the value of
% ResultingCode!*).

  (CMacroSubstitute ArgumentList
		    (AnyregPatternMatch ArgumentList PatternTable)))

(de AnyregPatternMatch (ArgumentList PatternTable)

% ArgumentList is the list of the arguments to the ALM/TLM instruction
% or operand.  These arguments may or maynot have been resolved
% depending on where this routine was called from.  As an example,
% consider the CMACRO (*HIPPO (CAR (CDR (REG T1))) (REG T3)).  If
% this CMACRO called this function without resolving its arguments,
% ((CAR (CDR (REG T1))) (REG T3)) would be the value of ArgumentList.
%
% PatternTable is of the form: (((p11 p12 ... p1n) r11 r12 ... r1n)
%                               ((p21 p22 ... p2n) r21 r22 ... r2n)
%				.
%                               .
%				.
%			       )
% This function uses the predicates (pij) to decide which part of the
% pattern table to use for replacement (e.g., (ri1 ... rin) above).
% The replacement part of the pattern table is returned.

  (cond
        % If we are at the end of the patterntable, return the last
        % element (no predicate was given).
        ((null (cdr PatternTable)) (car PatternTable))
	((AnyregPatternMatch1 ArgumentList (caar PatternTable))
	 (cdar PatternTable))
	(t (AnyregPatternMatch ArgumentList (cdr PatternTable)))))

(de AnyregPatternMatch1 (ArgumentList PredicateOrPredicateList)

% ArgumentList is the same as in AnyRegPatternMatch above.
% PredicateOrPredicateList is the predicate or list of predicates from
% the CMACRO or ANYREG pattern table.  Return T or NIL depending on
% whether each predicate returns non-NIL or NIL for each argument in
% ArgumentList.

  (cond ((atom PredicateOrPredicateList)
	 (Apply PredicateOrPredicateList ArgumentList))
	(t (MatchAll ArgumentList PredicateOrPredicateList))))

(de MatchAll (ArgumentList PredicateList)

% Return T if each predicate from PredicateList returns non-NIL for
% each argument in ArgumentList. Return NIL otherwise.  ArgumentList
% is the list of arguments of the ALM/TLM instruction or ALM/TLM
% operand.

  (or (atom ArgumentList)
      (atom PredicateList)
      (and (Apply (car PredicateList) (list (car ArgumentList)))
	   (MatchAll (cdr ArgumentList) (cdr PredicateList)))))

(de AnyregSubstitute (ArgumentList CodeAndAddressExpressionList)

% Take the values specified in ArgumentList and bind them with the
% correct variables (by forming an a-list).  Then wherever these
% variables occur within the replacement part of the pattern table
% specified (CodeAndAddressExpressionList), replace them with their
% values.  See AnyregSubstitute1, below, for details.

  (AnyregSubstitute1 (SafePair '(Register Source ArgTwo ArgThree)
			       ArgumentList)
		     CodeAndAddressExpressionList))

(de AnyregSubstitute1 (NameExpressionAList CodeAndAddressExpressionList)

% This function goes through the replacement part of the pattern table
% and substitutes actual bindings for variables (like SOURCE,
% REGISTER, ARGONE, etc.) in it.  This modified replacement part of
% the pattern table is returned (e.g., (REG T1) instead of (REG
% SOURCE)).  If more than one replacement pattern piece is given,
% perform this process to all of them -- placing the results of all
% but the last on the variable 'ResultingCode!*' and returning the
% last one as the value of the function.  'ResultingCode!*' is a fluid
% defined by one of the CMACRO expansion functions that MUST be called
% before this routine.

% NameExpressionAList is an a-list of variables with their values (for
% example, ((REGISTER . T3) (SOURCE . T1))).
% CodeAndAddressExpressionList is the replacement part of the pattern
% table (for example, in (((foop) (REG SOURCE)) ...) it may be (REG
% SOURCE)).

  (cond ((null (cdr CodeAndAddressExpressionList))
	 (SublA NameExpressionAList (car CodeAndAddressExpressionList)))
	(t  (setq ResultingCode!*
		  (cons (SublA NameExpressionAList
			       (car CodeAndAddressExpressionList))
			       ResultingCode!*))
 	    (AnyregSubstitute1 NameExpressionAList
		  	       (cdr CodeAndAddressExpressionList)))))

(de CMacroSubstitute (ArgumentList CodeTemplateList)

% Same as AnyregSubstitue above, except that CMACRO patterns can have
% labels in them.  See comments for CMacroSubstitute1 and
% AnyregSubstitute.  Value returned is the list of all instructions
% generated (ResultingCode!*).

  % See comment at top of module about these prog variables.
  (prog (TempLabel!* TempLabel2!*)
	(return (CMacroSubstitute1 (SafePair '(ArgOne ArgTwo
						      ArgThree
						      ArgFour
						      ArgFive)
					     ArgumentList)
				   CodeTemplateList))))

(de CMacroSubstitute1 (NameExpressionAList CodeTemplateList)

% Works just like AnyregSubstitute above (see comments).  Only
% difference is if 'TempLabel' or 'TempLabel2' are found in the
% pattern, they are replaced with real, unique string symbols
% generated.  Also, the function returns ALL instructions created, not
% just the last one.  This is done by returning the value of
% ResultingCode!*.

  (cond ((null CodeTemplateList) (ReversIP ResultingCode!*))
	(t (setq ResultingCode!*
		 (cons (PatternSublA NameExpressionAList
				     (car CodeTemplateList))
		       ResultingCode!*))
	   (CMacroSubstitute1 NameExpressionAList
			      (cdr CodeTemplateList)))))

(de SafePair (Vars Values)

% Return an A-list of variables with values (e.g., ((var1 . value1)
% (var2 . value2) ... (varn . valuen))

  (cond ((and (PairP Vars) (PairP Values))
	 (cons (cons (car Vars) (car Values))
	       (SafePair (cdr Vars) (cdr Values))))
	(t NIL)))

(de PatternSublA (AList Expression)

% This function replaces all identifiers in Expression that match
% variables in Alist with the corresponding value part of AList.  If
% 'TempLabel' or 'TempLabel2' are found within  Expression, replace
% them with a generated label (however, only generate the label once,
% even if there are multiple occurances of TempLabel and TempLabel2.

  (prog (X)
	(return (cond ((null Expression) NIL)
		      ((atom Expression)
		       (cond ((eq Expression 'TempLabel)
			      (TempLabelGen 'TempLabel!*))
			     ((eq Expression 'TempLabel2)
			      (TempLabelGen 'TempLabel2!*))
			     ((setq X (atsoc Expression AList))
			      (cdr X))
			     (t Expression)))
		      (t (cons (PatternSublA AList (car Expression))
			       (PatternSublA AList (cdr Expression))))))))

(de TempLabelGen (X)

% X is one of TempLabel!* and TempLabel2!*. If its value already has a
% label associated with it (value is a string), then return the label.
% Otherwise generate a new string label and assign X's value the new
% label.

  ((lambda (Y)
     (cond ((StringP Y) Y)
	   (T (set X (StringGensym)))))
   (Eval X)))
