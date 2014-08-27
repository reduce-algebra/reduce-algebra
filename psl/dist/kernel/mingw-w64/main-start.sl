%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PXK:MAIN-START.SL
% Title:          First routine called on startup
% Author:         Brian Beach, Hewlett-Packard CRC
% Created:        16-Feb-84
% Modified:       19-Feb-85 09:36:17
% Status:         Experimental
% Mode:           Lisp
% Package:        Kernel
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
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
%
% Revisions:
%
% 20-Jun-89 (Winfried Neun)
%  added reference to symget vector as internal structure
% 31-Aug-88 (Julian Padget)
%  Changed fluids to globals, since latter needed in CPSL.
% 28-Oct-87 (Harold Carr)
%  Made panic exit call exit-with-status, rather than redundantely doing
%  what panic exit already did then calling external_exit.
% 13-Apr-87 (Harold Carr & Leigh Stoller)
%  Added external fluid _infbitlength_ to be used in bpsheap.c.
% 26-Sep-86 (Leigh Stoller)
%  Changed exit to unix to be a call to exit library function. The Sun does
%  accept the exit status in (reg 1) like the Bobcat. Called it external_exit
%  so it does not interfere with the cmacro of the same name.
% 22-Sep-86 (Leigh Stoller)
%  Commented out calls 68020_advise which is not defined on the sun.
% 18-Jul-86 (Leigh Stoller)
%  Changed the allocation of argumentblock to be the number of maxregs since
%   it is indexed by base + reg number.
% 15-Feb-85 13:27:53 ()
%  Made it so that PSL allocates the stack it will use.
%  Removed TST.B for stack expansion.
%  Included declaration of STACKSIZE (should go in SYS-CONSTS eventually).
% 9-Jul-84 09:11:55 (RAM)
%  Added fluids (and initialization) unixstdin, unixstdout, unixstderr,
%  unixnull, unixeof, unixtty.
% 3-Jul-84 10:51:27 (RAM)
%  Changed name of initial faslin file to $pnkl/load-psl.b since
%  binaryopenread can now expand shell variable references.
% 29-Jun-84 12:33:38 (RAM)
%  Chagged exit_to_unix to exit-to-unix to match call in kernel-fatal-error.
%  Removed save and restore of A6.
% 31-May-84 08:15:32 (Brian Beach)
%  Changed SYSCLEARIO call to HP_CLEARIO.  SYSCLEARIO is now called by the 
%  loader as part of its startup.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(commentoutcode
(compiletime    %% Move this hack somewhere else later.
 (defmacro exported-fluid (list)
   (for (in id (second list))   % list is quoted
        (do 
         (flag1 id 'exportedsymbol)
         (put id 'symbol id)
         ))
   `(fluid ,list)
   ))
)

(compiletime    %% Move this hack somewhere else later.
 (defmacro exported-global (list)
   (for (in id (second list))   % list is quoted
        (do 
         (flag1 id 'exportedsymbol)
         (put id 'symbol id)
         (put id 'vartype 'global)
         ))
   ))

(commentoutcode
(compiletime    %% Move this hack somewhere else later.
 (defmacro internal-fluid (list)
   (for (in id (second list))   % list is quoted
        (do 
         (flag1 id 'internalsymbol)
         (put id 'symbol id)
         ))
   `(fluid ,list)
   ))
)

(compiletime    %% Move this hack somewhere else later.
 (defmacro internal-global (list)
   (for (in id (second list))   % list is quoted
        (do 
         (flag1 id 'internalsymbol)
         (put id 'symbol id)
         (put id 'vartype 'global)
         ))
   ))

(compiletime    %% Move this hack somewhere else later.
 (defmacro system-global (list)
   (for (in id (second list))   % list is quoted
        (do 
         (put id 'vartype 'global)
         ))
   ))

(on fast-integers)

(compiletime (load sys-consts))

%%(dskin "my-consts.sl")

(declare-kernel-structure 
 (stack           2)%     #.(compiler-constant 'stacksize))
 (argumentblock     #.(compiler-constant 'maxargs))
%(theirregs         #.(compiler-constant 'savesize))
%(temptheirregs     #.(compiler-constant 'savesize))
 (tokenbuffer       #.(compiler-constant 'maxtokensize))
 (bndstk            #.(compiler-constant 'bndstksize))
 (catchstack        #.(times2 (compiler-constant 'catchstacksize) 4))
 (hashtable         #.(quotient (compiler-constant 'hash-table-size) 2))
 (onewordbuffer     1)
 (saveargc          1)
 (saveargv          1)
 (datebuffer        1)
 )

(exported-global
 '(bndstkptr
   bndstkupperbound
   gcarraylowerbound
   gcarrayupperbound
   heaplast
   oldheaplast
   heaplowerbound
   heaptrapbound
   oldheaptrapbound
   heapupperbound
   _infbitlength_
   lastbps
   bpslowerbound
   mainstartinitialize
   nextbps
   oldheapupperbound
   oldheaplowerbound
   stacklowerbound
   stackupperbound
   saveda7
   unixstdin
   unixstdout
   unixstderr
   unixnull
   unixeof
   unixtty
   ))

(internal-global
 '(symget
   symnam
   symval
   symfnc
   symprp
   ))

(system-global
 '(symget
   symnam
   symval
   symprp
   symfnc
%  stack
   catchstackptr
   catchstack
   bndstklowerbound
   bndstkupperbound
   bndstkptr
   bndstk
   heap
   nextsymbol    %% Had SYMBOL as its assembler symbol.  why????
   % Add these so they are always available to compiled code.
   ***MUST-BE-NIL***
   ***MUST-BE-NIL-TOO***
   *fastcar
   ))

(de init-pointers()
% (setq stacklowerbound (wplus2 stack stacksize))
% (setq stackupperbound (wplus2 stack 100))
  (setq catchstackptr catchstack)
  (setq bndstklowerbound bndstk)
  (setq bndstkupperbound (loc (wgetv bndstk (wdifference bndstksize 1))))
  (setq bndstkptr bndstk)
  % most of the heap pointers are set up in the pascal world..
  % i.e. heaplowerbound, heaptrapbound, heaplast, heapupperbound, heaptrapbound.
  (setq heap heaplowerbound)
)

(de init-fluids ()
        % Until problem of labels not appearing is fixed...
  (setq gcarraylowerbound nil)
  (setq gcarrayupperbound nil)
  (setq heaplast nil)
  (setq oldheaplast nil)
  (setq heaptrapbound nil)
  (setq oldheaptrapbound nil)
  (setq heapupperbound nil)
  (setq _infbitlength_ nil)
  (setq lastbps nil)
  (setq bpslowerbound nil)
  (setq mainstartinitialize nil)
  (setq nextbps nil)
  (setq oldheapupperbound nil)
  (setq oldheaplowerbound nil)
  (setq stackupperbound nil)
  (setq unixstdin nil)
  (setq unixstdout nil)
  (setq unixstderr nil)
  (setq unixnull nil)
  (setq unixeof nil)
  (setq unixtty nil)
  (setq ***MUST-BE-NIL*** NIL)
  (setq ***MUST-BE-NIL-TOO*** NIL)
  (setq *fastcar nil)
)

(lap '((*entry !m!a!i!n expr 0)

       %(*move (reg rcx) (reg 1))
       %(*move (reg rdx) (reg 2))

       (*alloc 3) % changes Stack pointer

       (*move (reg rcx) (frame 1))
       (*move (reg rdx) (frame 2))
       (*move (reg 5) (frame 3)) % have to save %rbp

    %  (*move (fluid argc) (frame 1))
    %   (*move (fluid argv) (frame 2))
    %   (*move (reg 2) (frame 3)) % have to save %ebx


  %    (*move   (fluid stack) (reg st))
  %    (*move   (reg st)      (fluid stackupperbound))
  %    (*wplus2 (reg st)      (wconst (times (sub1 stacksize) 
  % 				     addressingunitsperitem)))

       %  Do OS specific initializations (uses argc and argv)
    %   (*move (fluid argc) (reg 1))
    %   (*move (fluid argv) (reg 2))
    %   (*move infbitlength (fluid _infbitlength_))
       (*move (frame 1) (reg 1))
       (*move (frame 2) (reg 2))
       (*link os_startup_hook expr 2)

       (*move (frame 1) (fluid argc))
       (*move (frame 2) (fluid argv))
       (*move (frame 3) (fluid ebxsave!*))

       (*call init-pointers)

       (*move   (reg st)  (reg 4))
       (*wshift (reg 4) -5)
       (*move (reg 4)  (fluid stacklowerbound))

       (*link init-gcarray expr 0)

       (*call pre-main)                                 % call PSL

panic-exit                      % need to do UNIX cleanup after
                                % a fatal error, so jump here
       (*move (wconst 0) (reg 1))
       (*linke 3 exit-with-status expr 1)
       (*exit 3)

       (*entry exit-with-status expr 1)
       (*push (reg 1))
       (*link os_cleanup_hook expr 0)
       (*pop (reg 1))
       (*link external_exit expr 1)
       (*exit 3)
       ))

(de init-gcarray() nil) % hook for garbage collector initialization 

(de pre-main ()
  (unixcleario)
  (initialize-symbol-table)
  (initcode)
  (console-print-string "About to load LOAD-PSL")
  (console-newline)
  (faslin "load-psl.b")
  (loader-main)
  )

(off fast-integers)
