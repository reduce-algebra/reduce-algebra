%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:LAP.SL
% Description:  Miscellaneous LAP routines for the D-register model
% Author:       Sam Sands, Tim Tillson
% Created:      12-Dec-83
% Modified:     23-Apr-84 10:21:43
% Mode:         Lisp
% Package:      Kernel
% Status:       Open Source: BSD License
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(global '(bndstkptr bndstkupperbound))

(lap '(              % This file contains miscellaneous LAP routines    scs


% syslsp procedure CodeApply(CodePtr, ArgList);
%
% if this could be written in Syslisp, it would look something like this:
% The arguments, up to 14, are loaded into the registers and execution jumps
% to the code pointer.
%
% begin scalar N;
%     N := 0;
%     while PairP ArgList do
%     <<  N := N + 1;
%	  ArgumentRegister[N] := car ArgList;
%	  ArgList := cdr ArgList >>;
%     (jump to address of code pointer)
% end;

% Note that this code assumes that (reg t2) is an A register            scs
%    and that an (EXIT 0) will do an RTS
%    and that the tagged code pointer is a valid address

  (!*entry CodeApply expr 2)           %  CodeApply(CodePointer, ArgList)
     %  code pointer, ready for RTS, but first it is tag stripped, then pushed
  (*field (reg 1) (reg 1) (wconst InfStartingBit) (wconst InfBitLength))
  (!*push (reg 1))
  (!*jumpeq (Label L0) (reg  2)  (quote nil))    %  done if no arguments

  (!*move (reg 2) (reg t2))            %  move argument list to safe place

  (!*move (car (reg t2)) (reg  1))     %  get actual argument from list
  (!*move (cdr (reg t2)) (reg t2))     %  advance pointer
  (!*jumpeq (Label L0) (reg t2)  (quote nil))    %  test for end of list  

  (!*move (car (reg t2)) (reg  2))     %  repeat for each argument
  (!*move (cdr (reg t2)) (reg t2))  
  (!*jumpeq (Label L0) (reg t2)  (quote nil)) 

  (!*move (car (reg t2)) (reg  3))  
  (!*move (cdr (reg t2)) (reg t2))  
  (!*jumpeq (Label L0) (reg t2)  (quote nil)) 

  (!*move (car (reg t2)) (reg  4))  
  (!*move (cdr (reg t2)) (reg t2))  
  (!*jumpeq (Label L0) (reg t2)  (quote nil)) 

  (!*move (car (reg t2)) (reg  5))  
  (!*move (cdr (reg t2)) (reg t2))  
  (!*jumpeq (Label L0) (reg t2)  (quote nil)) 

  (!*move (car (reg t2)) (reg  6))  
  (!*move (cdr (reg t2)) (reg t2))  
  (!*jumpeq (Label L0) (reg t2)  (quote nil)) 

  (!*move (car (reg t2)) (reg  7))  
  (!*move (cdr (reg t2)) (reg t2))  
  (!*jumpeq (Label L0) (reg t2)  (quote nil)) 

  (!*move (car (reg t2)) (reg  8))  
  (!*move (cdr (reg t2)) (reg t2))  
  (!*jumpeq (Label L0) (reg t2)  (quote nil)) 

  (!*move (car (reg t2)) (reg  9))  
  (!*move (cdr (reg t2)) (reg t2))  
  (!*jumpeq (Label L0) (reg t2)  (quote nil)) 

  (!*move (car (reg t2)) (reg 10))  
  (!*move (cdr (reg t2)) (reg t2))  
  (!*jumpeq (Label L0) (reg t2)  (quote nil)) 

  (!*move (car (reg t2)) (reg 11))  
  (!*move (cdr (reg t2)) (reg t2))  
  (!*jumpeq (Label L0) (reg t2)  (quote nil)) 

  (!*move (car (reg t2)) (reg 12))  
  (!*move (cdr (reg t2)) (reg t2))  
  (!*jumpeq (Label L0) (reg t2)  (quote nil)) 

  (!*move (car (reg t2)) (reg 13))  
  (!*move (cdr (reg t2)) (reg t2))
  (!*jumpeq (Label L0) (reg t2)  (quote nil)) 

  (!*jumpnoteq (Label TooMany) (cdr (reg t2)) (quote nil))  
                                       %  check for more than 14

  (!*move (car (reg t2)) (reg 14))     % the 14th and last argument 

L0
  (LDMIA (reg sp) ((reg pc)) writeback)	% JUMP to code pointer by RTS    scs

TooMany
	(!*MOVE (QUOTE "Too many arguments to function") (reg 1))
	(!*JCALL StdError)


% procedure IDApply0
% procedure IDApply1
% procedure IDApply2
% procedure IDApply3
% procedure IDApply4
%
%  The following assume that (reg t2) is an A register
%    and that the tag bit portions of addresses are don't cares

  (!*entry XIDApply0 expr 1)              %  IDApply0(CodePointer)
  (*field (reg 1) (reg 1)
	  (wconst InfStartingBit) (wconst InfBitLength))
  (!*move   (reg  1) (reg t3))           %  copy ID
  (LDR (reg t2) (displacement (reg symfnc) (regshifted t3 LSL 2))) % load function pointer
  (BX (reg t2))				% jump to function

  (!*entry XIDApply1 expr 2)              %  IDApply1(Arg1, CodePointer)
  (*field (reg 2) (reg 2) 
	  (wconst InfStartingBit) (wconst InfBitLength))
  (!*move   (reg 2) (reg t3))           %  copy ID
  (LDR (reg t2) (displacement (reg symfnc) (regshifted t3 LSL 2))) % load function pointer
  (BX (reg t2))			% jump to function

  (!*entry XIDApply2 expr 3)              %  IDApply2(Arg1, Arg2, CodePointer)
  (*field (reg 3) (reg 3) (wconst InfStartingBit) (wconst InfBitLength))
  (!*move   (reg  3) (reg t3))           %  copy ID
  (LDR (reg t2) (displacement (reg symfnc) (regshifted t3 LSL 2))) % load function pointer
  (BX (reg t2))			% jump to function

  (!*entry XIDApply3 expr 4)    %  IDApply3(Arg1, Arg2, Arg3, CodePointer)
  (*field (reg 4) (reg 4) (wconst InfStartingBit) (wconst InfBitLength))
  (!*move   (reg  4) (reg t2))        
  (LDR (reg t2) (displacement (reg symfnc) (regshifted t3 LSL 2))) % load function pointer
  (BX (reg t2))			% jump to function

  (!*entry XIDApply4 expr 5)    %  IDApply4(Arg1, Arg2, Arg3, Arg4, CodePointer)
  (*field (reg 5) (reg 5)
	  (wconst InfStartingBit) (wconst InfBitLength))
  (!*move   (reg  5) (reg t3))   
  (LDR (reg t2) (displacement (reg symfnc) (regshifted t3 LSL 2))) % load function pointer
  (BX (reg t2))			% jump to function
      ))


%
% TAG( FastApply )
%

(lap '((!*entry FastApply expr 0)	%. Apply with arguments loaded
%
% Called with arguments in the registers and functional form in reg t1 (r5)
% Note: this routine is called from the compiler
%       

        (*ALLOC 0)
	(*MOVE (reg t1) (reg t2))
	% note: reg t3 is clobbered by loading or storing a fluid
        (*MOVE (reg t2) (Fluid Codeform*))     %put lambda in codeform!*
        (!*FIELD (reg t1) (reg t2)
		 (wconst TagStartingBit) (wconst TagBitLength)) %tag in t1
	
        (!*FIELD (reg t2) (reg t2)
		 (wconst InfStartingBit) (wconst InfBitLength)) %inf in t2
	
        (!*JUMPNOTEQ (Label NotAnID) (reg t1) (wconst id-tag))

	% t2 contains id number, load function pointer into t2
	(LDR (reg t2) (displacement (reg symfnc) (regshifted t2 LSL 2)))
        (*move (Fluid Codeform*) (reg t3))
	(!*DeAlloc 0)
        (BX (reg t2))
NotAnID
	(!*JUMPNOTEQ (Label NotACodePointer) (reg t1) (wconst code-tag))
        (*move (Fluid Codeform*) (reg t1))
	(!*DeAlloc 0)
        (BX (reg t2))

NotACodePointer
	(*JUMPNOTEQ (Label IllegalFunctionalForm) (reg t1) (wconst pair-tag))
        (*MOVE (MEMORY (reg t2) 0) (reg t2))  % CAR with pair already untagged
        
	(*JUMPNOTEQ (Label IllegalFunctionalForm) (reg t2) (QUOTE LAMBDA))

	(*DeAlloc 0)
	(*JCALL FastLambdaApply)
IllegalFunctionalForm
	(*MOVE (QUOTE "Illegal functional form in Apply") (reg 1))
	(*MOVE (reg t2) (reg 2))
	(*CALL List5)
	(*DeAlloc 0)
	(*JCALL StdError)
))

%
% TAG( UndefinedFunctionaux )
%

(lap '((!*entry UndefinedFunction-aux expr 0)	%. Error Handler for non code
       %
       % also called by JMP in the Function Cell
       %
       (*ALLOC 0)			% Make sure that (reg lr) is saved on stack
       (*move (reg t1) (reg 2))
       (*MKITEM (reg 2) (wconst id-tag))
       (*MOVE (QUOTE "Undefined function %r called from compiled code")
	       (reg 1))
       (*CALL BldMsg)
       (!*DeAlloc 0)
       (*JCALL StdError)
       ))

%--------------------------------------------------------------------------
%
% lap codes for some frequently used functions
%

(de !_slowgtfltn ()
  % Allocate space for a floating point number.
  (let ((ptr  (gtheap (+ (floatpack) 1))))
    (setf (getmem ptr) (mkitem hwords-tag (- (floatpack) 1)))
    ptr
    ))

(lap '((*entry gtfltn expr 0)
          (*alloc 0)
          (*move (global heaplast) (reg 3))
          (*move (global heaptrapbound) (reg 4))
          (*move (reg 3) (reg 5))
          (*wplus2 (reg 5) (times addressingunitsperitem 3))
          (*jumpwgeq (label callslow) (reg 5) (reg 4))
          (*move (wconst (- (floatpack) 1)) (reg 1))
          (*mkitem (reg 1) hwords-tag)
          (*move (reg 1)(memory (reg 3) 0))
          (*move (reg 5) (global heaplast))
          (*move (reg 3) (reg 1))
          (*exit 0)
      callslow
          (*linke 0 !_slowgtfltn expr 0)))


(compiletime (flag '(slow_list2 slow_list3) 'internalfunction))


   % The repetition of _slowcons here is intentional! (here it is not 
   % internal)

(de !_slowcons (a b)
  (let ((ptr (gtheap (pairpack))))
    (setf (wgetv ptr 0) a)
    (setf (wgetv ptr 1) b)
    (mkpair ptr)
    ))

(lap '((*entry list2 expr 2)
          (*alloc 0)
          (*move (reg heaplast) (reg 3))
          (*move (reg heaplast) (reg 5))
          (*wplus2 (reg 5) (times addressingunitsperitem 4))
          (*jumpwgeq (label callslow) (reg 5) (reg heaptrapbound))
          (*move (reg 1) (memory (reg 3) 0))
          (*move (reg 2) (memory (reg 3) (times addressingunitsperitem 2)))
          (*move (quote nil) (memory (reg 3) (times addressingunitsperitem 3)))
          (*move (reg 5) (reg heaplast))
          (*move (reg 3) (reg 2))
          (*wplus2 (reg 2) (times addressingunitsperitem 2))
          (*move pair-tag (reg 5))
          (*wshift (reg 5) (wconst infbitlength))
          (*wor (reg 2) (reg 5))
          (*move (reg 2) (memory (reg 3) addressingunitsperitem))
          (*move (reg 3) (reg 1))
          (*wor (reg 1) (reg 5))
          (*exit 0)
      callslow
          (*linke 0 slow_list2 expr 2)))

(de slow_list2 (u v) (cons u (ncons v)))
 
(lap '((*entry list3 expr 3)
          (*alloc 0)
          (*move (reg heaplast) (reg 4))
          (*move (reg heaplast) (reg 5))
          (*wplus2 (reg 5) (times addressingunitsperitem 6))
          (*jumpwgeq (label callslow) (reg 5) (reg heaptrapbound))
          (*move (reg 1) (memory (reg heaplast) 0))
          (*move (reg 2) (memory (reg heaplast) (times addressingunitsperitem 2)))
          (*move (reg 3) (memory (reg heaplast) (times addressingunitsperitem 4)))
          (*move (quote nil) (memory (reg heaplast) (times addressingunitsperitem 5)))
          (*move (reg 5) (global heaplast))
          (*move pair-tag (reg 5))
          (*wshift (reg 5) (wconst infbitlength))
          (*move (reg 4) (reg 2))
          (*wplus2 (reg 2) (times addressingunitsperitem 2))
          (*wor (reg 2) (reg 5))
          (*move (reg 2) (memory (reg 4) addressingunitsperitem))
          (*move (reg 4) (reg 2))
          (*wplus2 (reg 2) (times addressingunitsperitem 4))
          (*wor (reg 2) (reg 5))
          (*move (reg 2) (memory (reg 4) (times addressingunitsperitem 3)))
          (*move (reg 4) (reg 1))
          (*wor (reg 1) (reg 5))
          (*exit 0)
      callslow
          (*linke 0 slow_list3 expr 3)))

(de slow_list3 (u v w) (cons u (list2 v w)))

(compiletime 
  (put 'cons 'opencode '(
          (*move (global heaplast) (reg 3))
          (*move (global heaptrapbound) (reg 4))
          (*move (reg 3) (reg 5))
          (*wplus2 (reg 5) (times addressingunitsperitem 2))
          (*jumpwgeq (labelgen callslow) (reg 5) (reg 4))
          (*move (reg 1) (memory (reg 3) 0))
          (*move (reg 2) (memory (reg 3) addressingunitsperitem))
          (*move (reg 5) (global heaplast))
          (*move (reg 3) (reg 1))
          (*move pair-tag (reg 5))
          (*wshift (reg 5) (wconst infbitlength))
          (*wor (reg 1) (reg 5))
          (*jump (labelgen done))
      (labelref callslow)
          (*link !_slowcons expr 2)
      (labelref done)
       )))
 
(compiletime
  (put 'ncons 'opencode '(
          (*move (global heaplast) (reg 3))
          (*move (global heaptrapbound) (reg 4))
          (*move (reg 3) (reg 5))
          (*wplus2 (reg 5) (times addressingunitsperitem 2))
          (*jumpwgeq (labelgen callslow) (reg 5) (reg 4))
          (*move (reg 1) (memory (reg 3) 0))
          (*move (quote nil) (memory (reg 3) addressingunitsperitem))
          (*move (reg 5) (global heaplast))
          (*move (reg 3) (reg 1))
          (*move pair-tag (reg 5))
          (*wshift (reg 5) (wconst infbitlength))
          (*wor (reg 1) (reg 5))
          (*jump (labelgen done))
      (labelref callslow)
          (*move (quote nil)(reg 2))
          (*link !_slowcons expr 2)
      (labelref done)
       )))
  
(de append (u v)
  %. Combine 2 lists
  (if (not (pairp u))
    v
    (prog (u1 u2)
          (setq u1 (setq u2 (cons (car u) nil)))
          (setq u (cdr u))
          (while (pairp u)
            (rplacd u2 (cons (car u) nil))
            (setq u (cdr u))
            (setq u2 (cdr u2)))
          (rplacd u2 v)
          (return u1))))

(de reverse (u)
  %. Top-level reverse of list
  (prog (v)
        (while (pairp u)
          (setq v (cons (car u) v))
          (setq u (cdr u)))
        (return v)))


(lap '((*entry get expr 2)
    (*alloc 0)
    (*move (reg 1)(reg 3))
    (*field (reg 3)(reg 3) (wconst tagstartingbit)(wconst tagbitlength))
    (*jumpnoteq (label no)(reg 3)(wconst id-tag))
    (*field (reg 1)(reg 1) (wconst infstartingbit)(wconst infbitlength))
    (*wshift (reg 1) 2)
    (*wplus2 (reg 1) ($FLUID SYMPRP))
    (*move (indexed (reg 1) 0) (reg 1))
  loop
    (*jumpeq (label ret) (reg 1) (quote nil))
    (*field (reg 1)(reg 1) (wconst infstartingbit)(wconst infbitlength))
    (*move (indexed (reg 1) 0) (reg 4))
    (*move (reg 4) (reg 3))
    (*field (reg 3)(reg 3) (wconst tagstartingbit)(wconst tagbitlength))
    (*jumpnoteq (label next) (reg 3)(wconst pair-tag))
    (*move (reg 4) (reg 3))
    (*field (reg 3)(reg 3) (wconst infstartingbit)(wconst infbitlength))
    (*move (indexed (reg 3) 0) (reg 5))
    (*jumpnoteq (label next) (reg 5)(reg 2))
    (*move (indexed (reg 3) 4) (reg 1))
    (*jump (label ret))
  next
    (*move (indexed (reg 1) 4) (reg 1))
    (*jump (label loop))
  no
    (*move (quote nil)(reg 1))
  ret
    (*exit 0)))
    
(lap '((*entry flagp  expr 2)
    (*alloc 0)
    (*move (reg 1)(reg 3))
    (*field (reg 3)(reg 3) (wconst tagstartingbit)(wconst tagbitlength))
    (*jumpnoteq (label no)(reg 3)(wconst id-tag))
    (*field (reg 1)(reg 1) (wconst infstartingbit)(wconst infbitlength))
    (*wshift (reg 1) 2)
    (*wplus2 (reg 1) ($FLUID SYMPRP))
    (*move (indexed (reg 1) 0) (reg 1))
  loop
    (*jumpeq (label ret) (reg 1) (quote nil))
    (*field (reg 1)(reg 1) (wconst infstartingbit)(wconst infbitlength))
    (*move (indexed (reg 1) 0) (reg 4))
    (*jumpnoteq (label next) (reg 4)(reg 2))
    (*move (quote T) (reg 1))
    (*jump (label ret))
  next
    (*move (indexed (reg 1) 4) (reg 1))
    (*jump (label loop))
  no
    (*move (quote nil)(reg 1))
  ret
    (*exit 0)))

