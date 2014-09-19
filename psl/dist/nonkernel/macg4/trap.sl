%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:TRAP.SL
% Description:  Signal handling for 88k
% Author:       Vicki O'Day, HP Labs/CRC
% Created:      27-Feb-84
% Modified:     2-Jan-85 13:13:16 (Vicki O'Day)
% Mode:         Lisp
% Package:
% Status:       Experimental (Do Not Distribute)
%
% (c) Copyright 1984, Hewlett-Packard Company, all rights reserved.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 5-Mar-90  (Winfried Neun)
%  added and refined (x-)code-address-to-symbol
% 10-Mar-89 (Winfried Neun)
%  Handling for 88k (SUN4). Complete redesign.
%  Also installed fluid *bruch* to allow gc (etc) to turn off
%  cntrl-c interrupt detection, which destroy system.
% 18-Aug-86 (Leigh Stoller)
%  Reworked so that signals can be added more easily. Also added calls to
%  external functions which set up the trap, and reinit the trap after a
%  signal is received.
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

(compiletime (flag '(build-trap-message) 'internalfunction))

(fluid '(*bruch* ibmrs-sigcp ibmrs-sigaddr ibmrs-sigcode ibmrs-signumber
         *dump ibmrs-sigpc ibmrs-dumparray*))

% this is the interface for toploop

(de initializeinterrupts ()

	  % all signals are initiated expect for those in the following list
          % they are ignored
    (!*!*hu!*!*)
    (for (from i 1 31) (do
       (when (not (memq i '(1 15 18 19 20 21 22 28))) (sigsetup i)))))

% this installs the handler

(compiletime (put 'givereg2 'opencode '((*move (reg r2) (reg 1)))))

(de sigsetup (signumber)
%%    (wputv isasavesystem 0 (wgetv symfnc (id2int 'signalhaendler)))
%%    (wputv isasavesystem 1 (givereg2)) % place of the TOK
%%    (wputv isasavesystem 2 0)
    %% old(psl_sigset signumber isasavesystem))
	(psl_sigset signumber (wgetv symfnc (id2int 'lisprpv)))
)

% this is the 'handler'

(setq ibmrs-dumparray* (gtwarray 60))

(setq *bruch* 0)

(compiletime (put 'putto 'opencode '((stw (reg 2) (displacement (reg 1) 0)))))

(compiletime (put 'getstack 'opencode '((addi (reg 1) (reg st) 0))))

(compiletime (de ZIBAnyregMemory (reg source offset)
  (prog (aReg cadrsource)
   (setq source (resolveoperand reg source))
   (setq offset (resolveoperand reg offset))
   (setq aReg (if (and (displacementp source)
                    (member (setq cadrsource (cadr source))
                                 *nextreglist*))
               cadrsource      (nexttempreg)))
   (push `(*move ,source ,aReg) Resultingcode*)
   (unless (eq 0 offset) (push `(*wplus2 ,aReg ,offset) Resultingcode*))
%%%%   (push `(*mkitem ,areg (quote 4)) Resultingcode*)
%%%%    (push `(*field ,areg ,areg 5 27) Resultingcode*)
   (return `(displacement ,areg 0)))))


(de signal-done ()
  (lisprpv1))
                                                                                
(fluid '(save-heaplast save-bndstkptr))

(de lisprpv(num val) % this one is called from the system in case of a trap
		     % we have to make a longjump (in sigset) because the
		     % signal context could not be found
   (prog (mess sta)
    (setq *bruch* 0)
   (setq save-bndstkptr bndstkptr) % have to save the registers across longjump
   (setq save-heaplast heaplast)
   (setq ibmrs-signumber num)
   (setq ibmrs-sigpc (getmem (wplus2 val 24)))
%(console-print-string "******************* Signal ")
%(unixputn ibmrs-signumber) (console-newline)
%(console-print-string " bei ")
%(unixputn ibmrs-sigpc) (console-newline)
   (return (psl_sigset (wgetv symfnc (id2int 'signalhaendler))  (getstack)))
)) 

(de lisprpv1()

    (setq  sta (getstack))
    (setq bndstkptr save-bndstkptr) % have to restore the registers after longjump
    (setq heaplast save-heaplast)

    (smalldump)
    (initializeinterrupts)
    (setq mess (atsoc ibmrs-signumber '((1 . "Hangup")
                          (2 . "Interrupt")
                          (3 . "Quit")
                          (4 . "Illegal Instruction")
                          (5 . "Trace Trap")
                          (6 . "IOT Instruction")
                          (7 . "EMT Instruction")
                          (8 . "Floating Point Exception")
                          (10 . "Bus Error")
			  (11 . "Memory Fault")
                          (12 . "Bad Args to System Call")
                          (13 . "Write on Pipe With None to Read")
                          (14 . "Alarm Clock")
                          (15 . "Software termination signal")  )))
%    (when (eq ibmrs-signumber 8)
%         (cond ((eq ibmrs-sigcode 16#c8)
%                        (setq mess '( 0 . "Floating Point divide by zero")))
%               ((eq ibmrs-sigcode 16#d4)
%                        (setq mess '( 0 . "Floating Point overflow")))
%               ((eq ibmrs-sigcode 16#cc)
%                        (setq mess '( 0 . "Floating Point underflow")))))
    (setq mess (if mess (cdr mess)
                  (bldmsg " Unknown signal type %d"  ibmrs-signumber)))
    (build-trap-message mess ibmrs-sigpc)
    (setq ibmrs-sigaddr 0 ibmrs-sigcp 0 ibmrs-sigpc 0) % for gc
    (return (stderror))))

(de smalldump()
  (when *dump
    (console-print-string "*** UNEXPECTED INTERRUPT ***")
    (console-newline)
    (console-print-string "*** System signal number: 16#")
    (unixputn ibmrs-signumber)
    (console-print-string " , signal code: 16#")
    (unixputn ibmrs-sigcode)
    (console-newline)
    (console-print-string "*** signal pc: 16#")
    (unixputn ibmrs-sigpc)
    (console-print-string " , signal stack: 16#")
    (unixputn ibmrs-sigaddr)
    (console-print-string " , context: 16#")
    (unixputn ibmrs-sigcp)
    (console-newline)
    (setq ibmrs-sigaddr 0 ibmrs-sigcp 0) % for gc
    (console-print-string "*** Registers  0-7 : ")
    (unixputn (wgetv ibmrs-dumparray* 0)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 1)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 2)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 3)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 4)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 5)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 6)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 7)) (console-print-string " ")
     (console-newline)
    (console-print-string "*** Registers  8-15: ")
    (unixputn (wgetv ibmrs-dumparray* 8)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 9)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 10)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 11)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 12)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 13)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 14)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 15)) (console-print-string " ")
     (console-newline)
    (console-print-string "*** Registers 16-23: ")
    (unixputn (wgetv ibmrs-dumparray* 16)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 17)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 18)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 19)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 20)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 21)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 22)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 23)) (console-print-string " ")
     (console-newline)
    (console-print-string "*** Registers 24-31: ")
    (unixputn (wgetv ibmrs-dumparray* 24)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 25)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 26)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 27)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 28)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 29)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 30)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 31)) (console-print-string " ")
     (console-newline)
    (console-print-string "*** Sigcontext     : ")
    (unixputn (wgetv ibmrs-dumparray* 50)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 51)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 52)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 53)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 54)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 55)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 56)) (console-print-string " ")
    (unixputn (wgetv ibmrs-dumparray* 57)) (console-print-string " ")
     (console-newline)
     (console-newline)
))

(compiletime (flag '(x-code-address-to-symbol) 'internalfunction))

(de build-trap-message (trap-type trap-addr)
    (let (extra-info)
      (setf extra-info (bldmsg "%w%w" " in "
                                 (x-code-address-to-symbol (inf trap-addr))))
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

(de code-address-to-symbol (ad) (x-code-address-to-symbol ad))
