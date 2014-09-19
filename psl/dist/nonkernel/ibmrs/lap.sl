%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PXNK:APPLY-LAP.SL
% Title:          LAP support for EVAL and APPLY  (Hacked version for testing)
% Author:         Eric Benson
% Created:        20 August 1981
% Modified:       26 Jan 1984 1040-PST (Brian Beach)
% Status:         Experimental
% Mode:           Lisp
% Package:        Kernel
%
% (c) Copyright 1983, Hewlett-Packard Company, all rights reserved.
% (c) Copyright 1981, University of Utah
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 01-Sep-88 (Julian Padget)
%  Bnd... declarations changed from fluid to global.
% 26 Jan 1984 1036-PST (Brian Beach)
%  Corrected file name in header.
% 2-Dec-83  16:00:00 (Brian Beach)
%   Translated from Rlisp to Lisp.
% Griss and Perdue, 10 January 1983
%	Modified Undefined function to make compiled calls
%	continuable
%
% may 23-1988 chris burdorf and T. Yamamoto
%   modified for sparc, got rid of vax specific code in casel, extv, 
%   autoincrement, and divl
%
% July 20,1988 T. Yamamoto: inline coding of argument distribution.
% November15 1988 W. Neun, removed move and *move (frame  ) cmacros
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(global '(bndstkptr bndstkupperbound))

(compiletime (load sys-macros))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% if this could be written in Syslisp, it would look something like this:
%
% syslsp procedure CodeApply(CodePtr, ArgList);
% begin scalar N;
%     N := 0;
%     while PairP ArgList do
%     <<  N := N + 1;
%	  ArgumentRegister[N] := car ArgList;
%	  ArgList := cdr ArgList >>;
%     (jump to address of code pointer)
% end;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de codeapply (CodePtr ArgList)
   (if (codep CodePtr) (ccodeapply (mkstr CodePtr) ArgList)
		(ccodeapply CodePtr ArgList)))

(lap '((*entry ccodeapply expr 2)
       %
       % CodeApply(CodePointer, ArgList)
       %
       % (reg 1) is code pointer
       % (reg 2) is arg list
       %
       (*alloc 0)
       (*move  (reg argone) (reg t6))           % reg t6) <- entry point.
     %*mkitem (reg t6) string-tag)
       (*move (reg argtwo) (reg t2))		% (reg t2) <- arglist

       (*jumpeq (label CONTINUE) (reg t2) (reg nil))	% 0 argument

       (*move (car (reg t2)) (reg 1))
       (*move (cdr (reg t2)) (reg t2))
       (*jumpeq (label CONTINUE) (reg t2) (reg nil))

       (*move (car (reg t2)) (reg 2))
       (*move (cdr (reg t2)) (reg t2))
       (*jumpeq (label CONTINUE) (reg t2) (reg nil))

       (*move (car (reg t2)) (reg 3))
       (*move (cdr (reg t2)) (reg t2))
       (*jumpeq (label CONTINUE) (reg t2) (reg nil))

       (*move (car (reg t2)) (reg 4))
       (*move (cdr (reg t2)) (reg t2))
       (*jumpeq (label CONTINUE) (reg t2) (reg nil))

       (*move (car (reg t2)) (reg 5))
       (*move (cdr (reg t2)) (reg t2))
       (*jumpeq (label CONTINUE) (reg t2) (reg nil))

       (*move (car (reg t2)) (reg 6))
       (*move (cdr (reg t2)) (reg t2))
       (*jumpeq (label CONTINUE) (reg t2) (reg nil))

       (*move (car (reg t2)) (reg 7))
       (*move (cdr (reg t2)) (reg t2))
       (*jumpeq (label CONTINUE) (reg t2) (reg nil))

       (*move (car (reg t2)) (reg 8))
       (*move (cdr (reg t2)) (reg t2))
       (*jumpeq (label CONTINUE) (reg t2) (reg nil))

       (*move (car (reg t2)) (reg 9))
       (*move (cdr (reg t2)) (reg t2))
       (*jumpeq (label CONTINUE) (reg t2) (reg nil))

       (*move (car (reg t2)) (reg 10))
       (*move (cdr (reg t2)) (reg t2))
       (*jumpeq (label CONTINUE) (reg t2) (reg nil))

       (*move (car (reg t2)) (reg 11))
       (*move (cdr (reg t2)) (reg t2))
       (*jumpeq (label CONTINUE) (reg t2) (reg nil))

       (*move (car (reg t2)) (reg 12))
       (*move (cdr (reg t2)) (reg t2))
       (*jumpeq (label CONTINUE) (reg t2) (reg nil))

       (*move (car (reg t2)) (reg 13))
       (*move (cdr (reg t2)) (reg t2))
       (*jumpeq (label CONTINUE) (reg t2) (reg nil))

       (*move (car (reg t2)) (reg 14))
       (*move (cdr (reg t2)) (reg t2))
       (*jumpeq (label CONTINUE) (reg t2) (reg nil))

       (*move (car (reg t2)) (reg 15))
       (*move (cdr (reg t2)) (reg t2))
       (*jumpeq (label CONTINUE) (reg t2) (reg nil))

       (*move (car (reg t2)) (reg 16))
       (*move (cdr (reg t2)) (reg t2))
       (*jumpeq (label CONTINUE) (reg t2) (reg nil))

       (*move (quote "Too many arguments to function") (reg 1))
       (*dealloc 0)
       (*jcall stderror)
       
CONTINUE
       (*dealloc 0)
       (mtspr (reg ctr) (reg t6))
       (bcc always 0)))
       

(de codeevalapply (codeptr arglist)
  (codeapply codeptr (evlis arglist)))

(de bindeval (formals args)
  (bindevalaux formals args 0))

(de bindevalaux (formals args n)
  (let (f
        a)
       (cond ((pairp formals) (if (pairp args)
                (progn (setq f (first formals))
                       (setq a (eval (first args)))
                       (setq n
                        (bindevalaux (rest formals) (rest args) (iadd1 n)))
                       (if (weq n -1)
                         -1
                         (progn (lbind1 f a)
                                n)))
                -1))
             ((pairp args) -1)
             (t n))))

(lap '((*entry undefinedfunctionaux expr 0)
       %
       % Error handler for non-code.
       %
       %	call SYMFNC+X		;; This function is undefined.
       %	.............
       % SYMFNC+X:
       %	call UNDEFINEDFUNCTION
       %	sethi o0,number         id number is shifted 10 bits
       %
       %
       % (reg t1) <- offset of symfnc table
       %
       (*alloc 17)
       (*move (reg t3) (frame 1))   % Set continueable address
                                   % o0 is i0 now!
       (*move (reg 1)(frame 2))
                                % Save all the regs (including fakes) (args)
       (*move (reg 2)(frame 3))
       (*move (reg 3)(frame 4))
       (*move (reg 4)(frame 5))
       (*move (reg 5)(frame 6))
       (*move (reg 6)(frame 7))
       (*move (reg 7)(frame 8))
       (*move (reg 8)(frame 9))
       (*move (reg 9)(frame 10))
       (*move (reg 10)(frame 11))
       (*move (reg 11)(frame 12))
       (*move (reg 12)(frame 13))
       (*move (reg 13)(frame 14))
       (*move (reg 14)(frame 15))
       (*move (reg 15)(frame 16))
       (*move (reg 16)(frame 17))

       (*move (frame 1) (reg 2))
       (*mkitem (reg 2) (wconst id-tag))
       (*move (reg 2) (frame 1))
       (*move '"Undefined function %r called from compiled code" (reg 1))
       (*call bldmsg)
       (*move (reg 1) (reg 2))
       (*move (wconst 0) (reg 1))
       (*move (reg nil) (reg 3))
       (*call continuableerror)

       (*move (frame 17 ) (reg 16))  
                          % Restore all those possible arguments
       (*move (frame 16 ) (reg 15))
       (*move (frame 15 ) (reg 14))
       (*move (frame 14 ) (reg 13))
       (*move (frame 13 ) (reg 12))
       (*move (frame 12 ) (reg 11))
       (*move (frame 11 ) (reg 10))
       (*move (frame 10 ) (reg 9))
       (*move (frame 9 ) (reg 8))
       (*move (frame 8 ) (reg 7))
       (*move (frame 7 ) (reg 6))
       (*move (frame 6 ) (reg 5))
       (*move (frame 5 ) (reg 4))
       (*move (frame 4 ) (reg 3))
       (*move (frame 3 ) (reg 2))
       (*move (frame 2 ) (reg 1))
       (*move (frame 1) (reg t1))
       (*move (frame 1) ($fluid *second-value*))
       (*linke 17 fastapply)))

%
% This is pretty gross, but it is essentially the same as LambdaApply, taking
% values from the argument registers instead of a list.
% if this could be written in Syslisp, it would look something like this:
%
% syslsp procedure CompiledCallingInterpreted IDOfFunction;
% begin scalar LForm, LArgs, N, Result;
%     LForm := get(IDOfFunction, '!*LambdaLink);
%     LArgs := cadr LForm;
%     LForm := cddr LForm;
%     N := 1;
%     while PairP LArgs do
%     <<  LBind1(car LArgs, ArgumentRegister[N];
%         LArgs := cdr LArgs;
%         N := N + 1 >>;
%     Result := EvProgN LForm;
%     UnBindN(N - 1);
%     return Result;
% end;

(lap '((*entry compiledcallinginterpretedaux expr 0) 
       % link for lambda
       %
       %
       (*move (reg t3) (reg t2))
	(rlinm (reg t1) (reg t3) 2 5 29) % inf and << 2
       (*mkitem (reg t2) (wconst btr-tag))        % make stack mark for btrace

       (*wplus2 (reg t1) ($fluid symprp))         % Prop list address
       (*move (memory (reg t1) (wconst 0))        % Property list
              (reg t1))
LOOPFINDPROP
       (*jumpnottype (label propnotfound) (reg t1) pair-tag)
                                           % make sure prop list is a pair
       (*move (car (reg t1)) (reg t2))     % get car of prop list
       (*move (cdr (reg t1)) (reg t1))     % cdr down
       (*jumpnottype (label LOOPFINDPROP) (reg t2)  pair-tag)
       (*move (car (reg t2)) (reg t3))     % yes, look at car
       (*move (quote *lambdalink) (reg t4))
       (*jumpnoteq (label loopfindprop) (reg t3) (reg t4))
       (*move (cdr (reg t2)) (reg t1))     % yes, get lambda form
       (*jcall fastlambdaapply)
%
%	At this point, (reg t1) <- lambda function to be called.
%
(*entry fastapply expr 0)
 
       % Apply with arguments loaded
       %
       % Cadded with arguments in the registers and functional form in t1.
 
       (*move (reg t1) (reg t3))
       (*field (reg t2)                    % Tag of function into T2
               (reg t1)
               (wconst tagstartingbit)
               (wconst tagbitlength))
       (*field (reg t1)                    % Inf of function into T1
               (reg t1) 
               (wconst infstartingbit)
               (wconst infbitlength))
 
       (*move (reg t1) (reg t6))
       (*jumpnoteq (label notanid) (reg t2) (wconst id-tag))
 
       % ID: Link through function cell
       (*move (reg t6) (reg t3))
       (*wshift (reg t6) 2) % multiply by addressingunitsperfunctioncell
       (*wplus2  (reg t6) (fluid symfnc))
       (l (reg t1) (displacement (reg t6) 0))
       (mtspr  (reg ctr) (reg t1))
       (bcc always 0)
 
NOTANID(*jumpnoteq (label notacodepointer) (reg t2) (wconst code-tag))
 
       % Code pointer: jump direct
	(*mkitem (reg t3) string-tag)
        (mtspr (reg ctr) (reg t3))
        (bcc always 0)

NOTACODEPOINTER
       (*jumpnoteq (label illegalfunctionalform) (reg t2) (wconst pair-tag))
 
       % Pair: make sure it's a lambda, then call FASTLAMBDAPPLY.
 
       (*move (memory (reg t6) (wconst 0)) (reg t2)) % CAR of the inf field.
       (*jumpnoteq (label illegalfunctionalform) (reg t2) 'lambda)
 
       (*move (reg t6) (reg t1))
       (*jcall fastlambdaapply)         % (reg t1) <- lambda function
 
ILLEGALFUNCTIONALFORM
       (*move '"Illegal functional form in Apply" (reg 1))
       (*move (reg t6) (reg 2))
       (*call list2)
       (*jcall stderror)

(*entry fastlambdaapply expr 0)            % called from FastApply
	(*alloc 6)
	(*move  (reg t1) (frame 2))

	(*move (cdr (frame 2)) (frame 2))     % get (cdr of lambda form
	(*move (cdr (frame 2)) (frame 1))     % save cddr in (reg t1)
	(*move (car (frame 2)) (frame 2))     % cadr of lambda form == arg list

	(*move (reg bndstkptr) (frame 6))    % a copy for restoring
	(*move (frame 2) (frame 5)) 
%
%       The first argument
%
	(*jumpnottype (label DONEBINDINGFORMALS) (frame 5) pair-tag)
	(*wplus2 (reg bndstkptr) (wconst 8))
	(*jumpwgeq (label BINDINGOVERFLOW) (reg bndstkptr)
				 (reg bndstkupperbound))
	(*move (car (frame 5)) (reg t1))
	(*move (cdr (frame 5)) (frame 5))
	(*field (reg t1) (reg t1) 5 27)       % (reg t5) <- id number
	(*move (reg t1) (memory (reg bndstkptr) (wconst -4)))
	(*wshift (reg t1) 2)
	(*wplus2 (reg t1) ($fluid symval))
	(*move (memory (reg t1) (wconst 0)) (memory (reg bndstkptr) (wconst 0)))
	(*move (reg 1) (memory (reg t1) (wconst 0)))
%
%       The second argument
%
	(*jumpnottype (label DONEBINDINGFORMALS) (frame 5) pair-tag)
	(*wplus2 (reg bndstkptr) (wconst 8))
	(*jumpwgeq (label BINDINGOVERFLOW) (reg bndstkptr) (reg bndstkupperbound))
	(*move (car (frame 5)) (reg t1))
	(*move (cdr (frame 5)) (frame 5))
	(*field (reg t1) (reg t1) 5 27)       % (reg t5) <- id number
	(*move (reg t1) (memory (reg bndstkptr) (wconst -4)))
	(*wshift (reg t1) 2)
	(*wplus2 (reg t1) ($fluid symval))
	(*move (memory (reg t1) (wconst 0)) (memory (reg bndstkptr) (wconst 0)))
	(*move (reg 2) (memory (reg t1) (wconst 0)))
%
%       The third argument
%
	(*jumpnottype (label DONEBINDINGFORMALS) (frame 5) pair-tag)
	(*wplus2 (reg bndstkptr) (wconst 8))
	(*jumpwgeq (label BINDINGOVERFLOW) (reg bndstkptr) (reg bndstkupperbound))
	(*move (car (frame 5)) (reg t1))
	(*move (cdr (frame 5)) (frame 5))
	(*field (reg t1) (reg t1) 5 27)       % (reg t5) <- id number
	(*move (reg t1) (memory (reg bndstkptr) (wconst -4)))
	(*wshift (reg t1) 2)
	(*wplus2 (reg t1) ($fluid symval))
	(*move (memory (reg t1) (wconst 0)) (memory (reg bndstkptr) (wconst 0)))
	(*move (reg 3) (memory (reg t1) (wconst 0)))
%
%       The fourth argument
%
	(*jumpnottype (label DONEBINDINGFORMALS) (frame 5) pair-tag)
	(*wplus2 (reg bndstkptr) (wconst 8))
	(*jumpwgeq (label BINDINGOVERFLOW) (reg bndstkptr) (reg bndstkupperbound))
	(*move (car (frame 5)) (reg t1))
	(*move (cdr (frame 5)) (frame 5))
	(*field (reg t1) (reg t1) 5 27)       % (reg t5) <- id number
	(*move (reg t1) (memory (reg bndstkptr) (wconst -4)))
	(*wshift (reg t1) 2)
	(*wplus2 (reg t1) ($fluid symval))
	(*move (memory (reg t1) (wconst 0)) (memory (reg bndstkptr) (wconst 0)))
	(*move (reg 4) (memory (reg t1) (wconst 0)))
%
%       The fifth argument
%
	(*jumpnottype (label DONEBINDINGFORMALS) (frame 5) pair-tag)
	(*wplus2 (reg bndstkptr) (wconst 8))
	(*jumpwgeq (label BINDINGOVERFLOW) (reg bndstkptr) (reg bndstkupperbound))
	(*move (car (frame 5)) (reg t1))
	(*move (cdr (frame 5)) (frame 5))
	(*field (reg t1) (reg t1) 5 27)       % (reg t5) <- id number
	(*move (reg t1) (memory (reg bndstkptr) (wconst -4)))
	(*wshift (reg t1) 2)
	(*wplus2 (reg t1) ($fluid symval))
	(*move (memory (reg t1) (wconst 0)) (memory (reg bndstkptr) (wconst 0)))
	(*move (reg 5) (memory (reg t1) (wconst 0)))
%
%       The sixth argument
%
	(*jumpnottype (label DONEBINDINGFORMALS) (frame 5) pair-tag)
	(*wplus2 (reg bndstkptr) (wconst 8))
	(*jumpwgeq (label BINDINGOVERFLOW) (reg bndstkptr) (reg bndstkupperbound))
	(*move (car (frame 5)) (reg t1))
	(*move (cdr (frame 5)) (frame 5))
	(*field (reg t1) (reg t1) 5 27)       % (reg t5) <- id number
	(*move (reg t1) (memory (reg bndstkptr) (wconst -4)))
	(*wshift (reg t1) 2)
	(*wplus2 (reg t1) ($fluid symval))
	(*move (memory (reg t1) (wconst 0)) (memory (reg bndstkptr) (wconst 0)))
	(*move (reg 6) (memory (reg t1) (wconst 0)))
%
%       The seventh argument
%
	(*jumpnottype (label DONEBINDINGFORMALS) (frame 5) pair-tag)
	(*wplus2 (reg bndstkptr) (wconst 8))
	(*jumpwgeq (label BINDINGOVERFLOW) (reg bndstkptr) (reg bndstkupperbound))
	(*move (car (frame 5)) (reg t1))
	(*move (cdr (frame 5)) (frame 5))
	(*field (reg t1) (reg t1) 5 27)       % (reg t5) <- id number
	(*move (reg t1) (memory (reg bndstkptr) (wconst -4)))
	(*wshift (reg t1) 2)
	(*wplus2 (reg t1) ($fluid symval))
	(*move (memory (reg t1) (wconst 0)) (memory (reg bndstkptr) (wconst 0)))
	(*move (reg 7) (memory (reg t1) (wconst 0)))
%
%       The eighth argument
%
	(*jumpnottype (label DONEBINDINGFORMALS) (frame 5) pair-tag)
	(*wplus2 (reg bndstkptr) (wconst 8))
	(*jumpwgeq (label BINDINGOVERFLOW) (reg bndstkptr) (reg bndstkupperbound))
	(*move (car (frame 5)) (reg t1))
	(*move (cdr (frame 5)) (frame 5))
	(*field (reg t1) (reg t1) 5 27)       % (reg t5) <- id number
	(*move (reg t1) (memory (reg bndstkptr) (wconst -4)))
	(*wshift (reg t1) 2)
	(*wplus2 (reg t1) ($fluid symval))
	(*move (memory (reg t1) (wconst 0)) (memory (reg bndstkptr) (wconst 0)))
	(*move (reg 8) (memory (reg t1) (wconst 0)))
%
%       The nineth argument
%
	(*jumpnottype (label DONEBINDINGFORMALS) (frame 5) pair-tag)
	(*wplus2 (reg bndstkptr) (wconst 8))
	(*jumpwgeq (label BINDINGOVERFLOW) (reg bndstkptr) (reg bndstkupperbound))
	(*move (car (frame 5)) (reg t1))
	(*move (cdr (frame 5)) (frame 5))
	(*field (reg t1) (reg t1) 5 27)       % (reg t5) <- id number
	(*move (reg t1) (memory (reg bndstkptr) (wconst -4)))
	(*wshift (reg t1) 2)
	(*wplus2 (reg t1) ($fluid symval))
	(*move (memory (reg t1) (wconst 0)) (memory (reg bndstkptr) (wconst 0)))
	(*move (reg 9) (memory (reg t1) (wconst 0)))
%
%       The tenth argument
%
	(*jumpnottype (label DONEBINDINGFORMALS) (frame 5) pair-tag)
	(*wplus2 (reg bndstkptr) (wconst 8))
	(*jumpwgeq (label BINDINGOVERFLOW) (reg bndstkptr) (reg bndstkupperbound))
	(*move (car (frame 5)) (reg t1))
	(*move (cdr (frame 5)) (frame 5))
	(*field (reg t1) (reg t1) 5 27)       % (reg t5) <- id number
	(*move (reg t1) (memory (reg bndstkptr) (wconst -4)))
	(*wshift (reg t1) 2)
	(*wplus2 (reg t1) ($fluid symval))
	(*move (memory (reg t1) (wconst 0)) (memory (reg bndstkptr) (wconst 0)))
	(*move (reg 10) (memory (reg t1) (wconst 0)))
%
%       The eleventh argument
%
	(*jumpnottype (label DONEBINDINGFORMALS) (frame 5) pair-tag)
	(*wplus2 (reg bndstkptr) (wconst 8))
	(*jumpwgeq (label BINDINGOVERFLOW) (reg bndstkptr) (reg bndstkupperbound))
	(*move (car (frame 5)) (reg t1))
	(*move (cdr (frame 5)) (frame 5))
	(*field (reg t1) (reg t1) 5 27)       % (reg t5) <- id number
	(*move (reg t1) (memory (reg bndstkptr) (wconst -4)))
	(*wshift (reg t1) 2)
	(*wplus2 (reg t1) ($fluid symval))
	(*move (memory (reg t1) (wconst 0)) (memory (reg bndstkptr) (wconst 0)))
	(*move (reg 11) (memory (reg t1) (wconst 0)))
%
%       The twelveth argument
%
	(*jumpnottype (label DONEBINDINGFORMALS) (frame 5) pair-tag)
	(*wplus2 (reg bndstkptr) (wconst 8))
	(*jumpwgeq (label BINDINGOVERFLOW) (reg bndstkptr) (reg bndstkupperbound))
	(*move (car (frame 5)) (reg t1))
	(*move (cdr (frame 5)) (frame 5))
	(*field (reg t1) (reg t1) 5 27)       % (reg t5) <- id number
	(*move (reg t1) (memory (reg bndstkptr) (wconst -4)))
	(*wshift (reg t1) 2)
	(*wplus2 (reg t1) ($fluid symval))
	(*move (memory (reg t1) (wconst 0)) (memory (reg bndstkptr) (wconst 0)))
	(*move (reg 12) (memory (reg t1) (wconst 0)))
%
%       The thirteenth argument
%
	(*jumpnottype (label DONEBINDINGFORMALS) (frame 5) pair-tag)
	(*wplus2 (reg bndstkptr) (wconst 8))
	(*jumpwgeq (label BINDINGOVERFLOW) (reg bndstkptr) (reg bndstkupperbound))
	(*move (car (frame 5)) (reg t1))
	(*move (cdr (frame 5)) (frame 5))
	(*field (reg t1) (reg t1) 5 27)       % (reg t5) <- id number
	(*move (reg t1) (memory (reg bndstkptr) (wconst -4)))
	(*wshift (reg t1) 2)
	(*wplus2 (reg t1) ($fluid symval))
	(*move (memory (reg t1) (wconst 0)) (memory (reg bndstkptr) (wconst 0)))
	(*move (reg 13) (memory (reg t1) (wconst 0)))
%
%       The fourteenth argument
%
	(*jumpnottype (label DONEBINDINGFORMALS) (frame 5) pair-tag)
	(*wplus2 (reg bndstkptr) (wconst 8))
	(*jumpwgeq (label BINDINGOVERFLOW) (reg bndstkptr) (reg bndstkupperbound))
	(*move (car (frame 5)) (reg t1))
	(*move (cdr (frame 5)) (frame 5))
	(*field (reg t1) (reg t1) 5 27)       % (reg t5) <- id number
	(*move (reg t1) (memory (reg bndstkptr) (wconst -4)))
	(*wshift (reg t1) 2)
	(*wplus2 (reg t1) ($fluid symval))
	(*move (memory (reg t1) (wconst 0)) (memory (reg bndstkptr) (wconst 0)))
	(*move (reg 14) (memory (reg t1) (wconst 0)))
%
%
%       The fifteenth argument
%
	(*jumpnottype (label DONEBINDINGFORMALS) (frame 5) pair-tag)
	(*wplus2 (reg bndstkptr) (wconst 8))
	(*jumpwgeq (label BINDINGOVERFLOW) (reg bndstkptr) (reg bndstkupperbound))
	(*move (car (frame 5)) (reg t1))
	(*move (cdr (frame 5)) (frame 5))
	(*field (reg t1) (reg t1) 5 27)       % (reg t5) <- id number
	(*move (reg t1) (memory (reg bndstkptr) (wconst -4)))
	(*wshift (reg t1) 2)
	(*wplus2 (reg t1) ($fluid symval))
	(*move (memory (reg t1) (wconst 0)) (memory (reg bndstkptr) (wconst 0)))
	(*move (reg 15) (memory (reg t1) (wconst 0)))
%
%       The sixteenth argument
%
	(*jumpnottype (label DONEBINDINGFORMALS) (frame 5) pair-tag)
	(*wplus2 (reg bndstkptr) (wconst 8))
	(*jumpwgeq (label BINDINGOVERFLOW) (reg bndstkptr) (reg bndstkupperbound))
	(*move (car (frame 5)) (reg t1))
	(*move (cdr (frame 5)) (frame 5))
	(*field (reg t1) (reg t1) 5 27)       % (reg t5) <- id number
	(*move (reg t1) (memory (reg bndstkptr) (wconst -4)))
	(*wshift (reg t1) 2)
	(*wplus2 (reg t1) ($fluid symval))
	(*move (memory (reg t1) (wconst 0)) (memory (reg bndstkptr) (wconst 0)))
	(*move (reg 16) (memory (reg t1) (wconst 0)))

	(*move '"Too many arguments to function" (reg 1))
	(*dealloc 6)
	(*jcall stderror)

BINDINGOVERFLOW
	(*dealloc 6)
	(*jcall bstackoverflow)             % then error

DONEBINDINGFORMALS
	(*move (frame 1) (reg 1))          % get cddr of lambda form to eval
	(*call evprogn)                    % implicit progn
	(*move (reg 1) (frame 1))          % save result, get old bind stk ptr
	(*move (frame 6) (reg 1))
	(*call restoreenvironment)
	(*move (frame 1) (reg 1))
	(*exit 6)                            % and return

PROPNOTFOUND
        (*move '"*LAMBDALINK property not found for interpreted function"
               (reg 1))
        (*dealloc 1)
        (*jcall stderror)

))
            
