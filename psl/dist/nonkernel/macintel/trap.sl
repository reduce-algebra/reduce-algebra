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
 
(fluid '(errornumber* errorcall* sigaddr))


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
     (*move (displacement (reg st) 12 ) (reg 1))
     (*move (displacement (reg 1) 76) (reg 2))
     (*move (reg 2) (fluid sigaddr))
     (*move (wconst ,signumber) (reg 2))
     (*move (reg 2)(fluid errornumber*))
     (*move ,handler (reg 2))
     (*move  ($fluid errorcall*) (reg 2))
     (*move (reg 2) (displacement (reg 1) 76))
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
       (*sigsetup 2  Inthandler  IntHandlerInstruction  "Interrupt")
       (*sigsetup 3  QuitHandler QuitHandlerInstruction "Quit")
       (*sigsetup 4  IllHandler  IllHandlerInstruction  "Illegal Instruction")
       (*sigsetup 5  Traphandler TrapHandlerInstruction "Trace Trap")
       (*sigsetup 6  IotHandler  IotHandlerInstruction  "IOT Instruction")
       (*sigsetup 7  Emthandler  EmtHandlerInstruction  "EMT Instruction")
       (*sigsetup 8  FpeHandler  FpeHandlerInstruction "Floating Pt Exception")
       (*sigsetup 10 Bushandler  BusHandlerInstruction  "Bus Error")
       (*sigsetup 11 SegHandler  SegHandlerInstruction
                                    "Segmentation Violation")
       (*sigsetup 12 SysHandler  SysHandlerInstruction
                                    "Bad Args to System Call")
       (*sigsetup 13 PipeHandler PipeHandlerinstruction
                                    "Write on Pipe With Noone to Read")
       (*sigsetup 14 AlrmHandler AlrmHandlerInstruction "Alarm Clock")
       (*entry initializeinterrupts-1 expr 0)
       (*sigcall)
       (*exit 0)))
 
(de initializeinterrupts (nn)
       (ieee_flags (strbase (strinf "set")) (strbase (strinf "direction"))
				(strbase (strinf "tozero")) 0)
       (ieee_handler (strbase (strinf "set"))
                  (strbase (strinf "common"))
                  (symfnc (id2int 'fpehandler)))
       (*freset)
       (initializeinterrupts-1)
       (unless (eq 17 nn) (sun3_sigset 500)) % Hack! If stated from top-loop, save
%					       the fp environment.
)
 
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
     (*link *freset expr 0)
     (*move 17 (reg 1))
     (*link initializeinterrupts expr 1) % MK
     (pop (reg 1))
     (*move (fluid sigaddr ) (reg 2))
     (*call build-trap-message)
     (*move (reg 1) (reg 2))
     (*move (reg 1) (fluid sigaddr ))
     (*move (fluid errornumber*) (reg 1))
     (*wplus2 (reg 1)(wconst 10000))
     (ret) %%%(*jcall error) 
     ))

(de errortrap () (sun3_sigset 501) (error (wplus2 errornumber* 10000) sigaddr))

% (sun3_sigset 501)  restauriert das FP Environment

(setq errorcall* (wgetv symfnc (id2int 'errortrap)))

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

(de build-trap-message (trap-type trap-addr)
    (let (extra-info)
      (if (funboundp 'code-address-to-symbol)
        (setf extra-info
          (bldmsg "%w%n%w%n%w"
              " : the name of the routine that trapped can't be"
              " reported unless the function CODE-ADDRESS-TO-SYMBOL"
              " has been defined, by loading ADDR2ID."))
    % else, get the name of the offending function
    (setf extra-info (bldmsg "%w%w"
                 " in "
                 (code-address-to-symbol (inf trap-addr))))
      )
      (bldmsg "%w%w" trap-type extra-info)))
 
(fluid '(code-address* closest-address* closest-symbol*))

(de x-code-address-to-symbol (code-address*)
  (let ((closest-symbol* ()) (closest-address* 0))
        (mapobl #'(lambda (symbol)
                 (when (fcodep symbol)
                       (let ((address (inf (getfcodepointer symbol))))
                            (when (and (ileq address code-address*)
                                       (igreaterp address closest-address*))
                                  (setq closest-address* address)
                                  (setq closest-symbol* symbol))))))
       closest-symbol*))

(de code-address-to-symbol (ad) (x-code-address-to-symbol (inf ad)))

% End of file.
 
