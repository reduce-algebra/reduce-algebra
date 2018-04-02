%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:TRAP.SL
% Description:  Signal handling for Sun Unix 4.2.
% Author:       Vicki O'Day, HP Labs/CRC
% Created:      27-Feb-84
% Modified:     2-Jan-85 13:13:16 (Vicki O'Day)
% Mode:         Lisp
% Package:
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
 
(fluid '(errornumber*))

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
     (*move ,handler (reg 2))
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
 
(de initializeinterrupts ()
       (ieee_flags (strbase (strinf "set")) (strbase (strinf "direction"))
				(strbase (strinf "tozero")) 0)
       (ieee_handler (strbase (strinf "set"))
                  (strbase (strinf "common"))
                  (symfnc (id2int 'fpehandler)))
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
     (*link *freset expr 0)
     (*link initializeinterrupts expr 0) % MK
     (pop (reg 2))
     (*move (fluid errornumber*) (reg 1))
     (*wplus2 (reg 1)(wconst 10000))
     (*jcall error) 
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
 
% End of file.
 
