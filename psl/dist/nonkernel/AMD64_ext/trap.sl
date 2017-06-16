%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:TRAP.SL
% Description:  Signal handling for Sun Unix 4.2.
% Author:       Vicki O'Day, HP Labs/CRC
% Created:      27-Feb-84
% Modified:     2-Jan-85 13:13:16 (Vicki O'Day)
% Mode:         Lisp
% Package:
% Status:       Experimental (Do Not Distribute)
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 17-Feb-89 (Chris Burdorf)
%  Use sun3_sigset for os/4.
% 09-Oct-87 (Leigh Stoller)
%  Do not call build-trap-message anymore. It is too flakey to be relied
%   on to tell the truth.
% 31-Apr-87 (Leigh Stoller)
%  After consult with Julian Padget, altered sigunwind to decrease the
%   stack frame by 320 bytes instead of 98. The interrupted address is
%   found 312 bytes into this frame.
% 18-Aug-86 (Leigh Stoller)
%  Reworked so that signals can be added more easily. Also added calls to
%  external functions which set up the trap, and reinit the trap after a
%  signal is recieved.
% 2-Jan-85 10:21:47 (Vicki O'Day)
%  Instead of just calling stderror with a message about the kind of trap,
%  we now find the name of the routine that caused the trap and report
%  that as well.  CODE-ADDRESS-TO-SYMBOL is used to figure out the name.
% 27-Dec-84 10:55:56 (Vicki O'Day)
%  Added sigunwind, to pop the signal handler's stack frame before calling
%  stderror.  (Many thanks to Jim Davis for deciphering the contents of this
%  frame.)
% 17-Dec-84 10:24:41 (Vicki O'Day)
%  Added lots more signals to catch, to try to prevent those occasional
%  dumps out of Nmode.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
(fluid '(errornumber* sigaddr* arith-exception-type*))

(compiletime
 (progn
   (setf *sigcalls* nil)
   %
   % Create a list of initialization code needed to set up the traps. The
   % return value is the entry points for each signal handler.
   % This is later flaged as a
   %  cmacro so the returned code can be inserted directly into the lap coded
   %  procedure 'initializeinterrupts each time it is called. The list
   %  *sigentries is then inserted to define the entry points.
   (de *sigsetup (signumber function handler errorstring)
       (setf *sigcalls* (append
             % Sigset takes a function pointer.
             `((*move (wconst ,signumber) (reg 1))
               (*move ,handler (reg 2))
               (*link sun3_sigset expr 2))
             *sigcalls*))
       % Return the the function definition for the signal handler.
       `((*entry ,function expr 0)
     ,handler
     (*move (wconst ,signumber) (reg 1))
     (*move (reg 1)(fluid errornumber*))
     % for arithmetic expressions, get exception subtype:
     % Reg RSI contains a pointer to a siginto_t structure, and at offset 8
     % there is si_code (4 byte integer) which is the FPE subtype
     (*field (reg 2) (displacement (reg rsi) 8) 32 32)
     (*move (reg 2) (fluid arith-exception-type*))
     (*move ,handler (reg 2))
     (*move (memory (reg rdx) 168) (fluid sigaddr*))   % instruction pointer at fault
     (*link sigrelse expr 2)
     (*move (quote ,errorstring) (reg 1))
     (*jcall sigunwind))
       )
 
   % Return the entry point list. Defined as a cmacro.
   (de *sigcall ()
       *sigcalls*)
 
   (defcmacro *sigcall)
   (defcmacro *sigsetup)
 
   )
) % End of compiletime.
 
 
(lap '(
   % (*sigsetup 1  Huphandler  Huphandlerinstruction  "Hup")
   (*sigsetup 2  Inthandler   IntHandlerInstruction   "Interrupt")
   (*sigsetup 3  QuitHandler  QuitHandlerInstruction  "Quit")
   (*sigsetup 4  IllHandler   IllHandlerInstruction   "Illegal Instruction")
   (*sigsetup 5  Traphandler  TrapHandlerInstruction  "Trace Trap")
   (*sigsetup 6  AbortHandler AbortHandlerInstruction "Program aborted")
   (*sigsetup 7  Bushandler   BusHandlerInstruction   "Bus error")
   (*sigsetup 8  FpeHandler   FpeHandlerInstruction   "Arithmetic Exception")
%   (*sigsetup 10 Usr1handler  Usr1HandlerInstruction  "User defined signal 1")
   (*sigsetup 11 SegHandler   SegHandlerInstruction   "Segmentation Violation")
%   (*sigsetup 12 Usr2handler  Usr2HandlerInstruction  "User defined signal 2")
   (*sigsetup 13 PipeHandler  PipeHandlerinstruction  "Write on Pipe With Noone to Read")
   (*sigsetup 14 AlrmHandler  AlrmHandlerInstruction  "Alarm Clock")
   (*sigsetup 15 TermHandler  TermHandlerInstruction  "Termination signal")
%   (*sigsetup 16 STKXhandler STKXHandlerInstruction   "Stack fault")
%   (*sigsetup 17 Childhandler ChildHandlerInstruction "Child waiting")
%   (*sigsetup 18 Conthandler  ContHandlerInstruction  "SIGCONT received")
%   (*sigsetup 20 Stophandler  StopHandlerInstruction  "SIGTSTP received")
%   (*sigsetup 21 Ttinhandler  TtinHandlerInstruction  "Bg process waiting for input")
%   (*sigsetup 22 Ttouhandler  TtouHandlerInstruction  "Bg process waiting for output")
%   (*sigsetup 23 Urghandler   UrgHandlerInstruction   "Urgent out-of-band data")
   (*sigsetup 24 CPUXhandler  CPUXHandlerInstruction  "CPU time limit exceeded")
   (*sigsetup 25 FileXhandler FileXHandlerInstruction "File size limit exceeded")
%   (*sigsetup 26 VAlrmHandler VAlrmHandlerInstruction "CPU Timer")
%   (*sigsetup 27 ProfHandler ProfHandlerInstruction  "Profiling timer")
%   (*sigsetup 28 WinchHandler WinchHandlerInstruction "Window size change")
%   (*sigsetup 29 IOHandler    IOHandlerInstruction    "IO ready")
   (*sigsetup 30 Pwrhandler   PwrHandlerInstruction   "Power failure")
   (*sigsetup 31 Syshandler   SysHandlerInstruction   "Bad system call")
   (*entry initializeinterrupts-1 expr 0)
   (*sigcall)
   (*exit 0)))
 
(de initializeinterrupts ()
     %  (ieee_flags (strbase (strinf "set")) (strbase (strinf "direction"))
	%			(strbase (strinf "tozero")) 0)
     %  (ieee_handler (strbase (strinf "set"))
     %             (strbase (strinf "common"))
     %             (symfnc (id2int 'fpehandler)))
       (initializeinterrupts-1))
 
(lap
 '((!*entry sigunwind expr 0)
     % At this point, an arg is already set up in register 1 with a message
     % describing the kind of trap.  First, though, we want to find the
     % name of the routine that caused the trap by using the "interrupted
     % address" in the signal handler stack frame.  Then we want to
     % pop this frame off the stack.  On the SUN, this adds up to 320 bytes.
     % Who know why.
 
     % (*move (memory (reg st) 312) (reg 2)) % Addr. at which signal occurred
     %(*wplus2 (reg st) 320)                % Pop signal-handling frame
     % (*link build-trap-message expr 2)     % This leaves its result in reg
                                           % 1, so the new message is
     (push (reg 1))
     (*move 128 (reg NIL))
     (*mkitem (reg NIL) id-tag)            % make sure (reg nil) contains nil
     % if this is a terminal interrupt (errornumber* = 2) we check
     % whether it occured within lisp code. If not, just return.
     (*jumpnoteq (label in-lisp) (fluid errornumber*) 2)
     (*move (fluid sigaddr*) (reg 1))
     (*link codeaddressp expr 1)
     (!*jumpnoteq (label in-lisp) (reg 1) (quote nil))
     (pop (reg 1))
     (ret)
    in-lisp
     (*link *freset expr 0)
     (*link initializeinterrupts expr 0) % MK
     (pop (reg 2))
     (*move (fluid errornumber*) (reg 1))
     (*wplus2 (reg 1)(wconst 10000))
     % if the error number = 8 (arithmetic exception), pass the subtype in register 3
     (*move (wconst 0) (reg 3))
     (*jumpnoteq (label done) (fluid errornumber*) 8)
     (*move (fluid arith-exception-type*) (reg 3))
    done
     (*jcall error-trap) 
     ))

(lap '((*entry *freset expr 0)
       (*move 100000 (reg 5))
     lab
       (*move ($fluid onewordbuffer) (reg 4))
       (*wplus2 (reg 5) -1)
       (*jumpwgreaterp (label lab) (reg 5) 0)

       (fclex)
       (wait)
       (*move ($fluid onewordbuffer) (reg 3))
       (*move 0 (reg 2))
       (*move (reg 2) (displacement (reg 3) 0))
       (fstcw (displacement (reg 3) 0))
       (wait)
       (*move (displacement (reg 3) 0) (reg 2))
       (*wor (reg 2)  2#110000000000)
       (*wand (reg 2) 2#11111111110010)
       (*move (reg 2) (displacement (reg 3) 0))
       (fldcw (displacement (reg 3) 0))
       (wait)
       (*exit 0)))

%% Error subtypes for arithmetic exception
(define-constant FPE_INTDIV 1)
(define-constant FPE_INTOVF 2)
(define-constant FPE_FLTDIV 3)
(define-constant FPE_FLTOVF 4)
(define-constant FPE_FLTUND 5)
(define-constant FPE_FLTRES 6)
(define-constant FPE_FLTINV 7)
(define-constant FPE_FLTSUB 8)

%% convert arithmetic error subtype to error message
(de get-fpe-errmsg (n)
  (cond
    ((eq n FPE_INTDIV) "Integer divide by zero")
    ((eq n FPE_INTOVF) "Integer overflow")
    ((eq n FPE_FLTDIV) "Floating point divide by zero")
    ((eq n FPE_FLTOVF) "Floating point overflow")
    ((eq n FPE_FLTUND) "Floating point underflow")
    ((eq n FPE_FLTRES) "Floating point inexact result")
    ((eq n FPE_FLTINV) "Floating point invalid operation")
    ((eq n FPE_FLTSUB) "Subscript out of range")
    (t "Arithmetic exception")))

(de error-trap (errornumber errorstring arithsubtype)
  (error errornumber
   (build-trap-message
    (if (eq errornumber* 8) (get-fpe-errmsg arithsubtype)
	errorstring)
    sigaddr*)))

(de build-trap-message (trap-type trap-addr)
    (let (extra-info)
      (cond ((funboundp 'code-address-to-symbol)
	     (setf extra-info
		   (bldmsg "%w%x%w%n%w%n%w%n%w"
			   " at address 0x"
			   (inf trap-addr)
			   " :"
			   " the name of the routine that trapped can't be"
			   " reported unless the function CODE-ADDRESS-TO-SYMBOL"
			   " has been defined, by loading ADDR2ID.")))
	    % else, get the name of the offending function
	    ((setf extra-info (code-address-to-symbol (inf trap-addr)))
	     (setf extra-info (bldmsg "%w%w" " in " extra-info)))
	    (t (setf extra-info (bldmsg "%w%x" " at address 0x" (inf trap-addr))))
      )
      (bldmsg "%w%w" trap-type extra-info)))
 
% End of file.
 
