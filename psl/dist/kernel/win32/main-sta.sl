%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PXK:MAIN-START.SL
% Title:          First routine called on startup
% Author:         Brian Beach, Hewlett-Packard CRC
% Created:        16-Feb-84
% Modified:       19-Feb-85 09:36:17
% Status:         Open Source: BSD License
% Mode:           Lisp
% Package:        Kernel
%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
%
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
% 
%
% Revisions:
%
% 20-Jun-89 (Winfried Neun)
%  added reference to symget vector as internal structure
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime
(defmacro exported-global (list)
  (let ((*lower t)) 
   (for (in id (second list))   % list is quoted
        (do 
         (flag1 id 'exportedsymbol)
         (put id 'symbol (intern (bldmsg "_%w" id)))
         (put id 'vartype 'global)
         ))
   )))

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

%%(compiletime (load sys-consts))

%%(dskin "my-consts.sl")

(declare-kernel-structure 
% (stack             #.(compiler-constant 'stacksize))
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
   heaplowerbound
   heaptrapbound
   heapupperbound
   oldheaplast
   oldheaplowerbound
   oldheaptrapbound
   oldheapupperbound
   
   old_symval
   old_symfnc
   old_symprp
   old_symget

   _infbitlength_
   lastbps
   bpslowerbound
   mainstartinitialize
   nextbps
   stacklowerbound
   stackupperbound
   unixstdin
   unixstdout
   unixstderr
   unixnull
   unixeof
   unixtty
   bruch_bruch
   psl_callback1 psl_callback2 psl_callback3 psl_callback4
   ))

(internal-global
 '(
   symget
   symnam
   symval
   symfnc
   symprp
   ))

(system-global
 '(
   symget
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
   **windows
   ))

(de init-pointers()
  (setq psl_callback1 0)
  (setq psl_callback2 0)
  (setq psl_callback3 0)
  (setq psl_callback4 0)
  (setq stackupperbound (wdifference stack stacksize))
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
  (setq heaptrapbound nil)
  (setq heapupperbound nil)
  (setq _infbitlength_ nil)
  (setq lastbps nil)
  (setq bpslowerbound nil)
  
  (setq oldheaplast nil)
  (setq oldheaplowerbound nil)
  (setq oldheaptrapbound nil)
  (setq oldheapupperbound nil)

  (setq mainstartinitialize nil)
  (setq nextbps nil)
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
  (setq **windows nil)
)

(de &&init-tables1()
    % establish final id tables - excuted BEFORE image loading
  (setq bruch_bruch 0)
  (setq kernel-maxsymbols nextsymbol)
  (setq old_symval symval old_symfnc symfnc old_symprp symprp old_symget symget)
  (setq symval symms)
  (setq symfnc (wplus2 symval (times2 maxsymbols addressingunitsperitem)))
  (setq symprp (wplus2 symfnc (times2 maxsymbols addressingunitsperitem)))
  %(setq symget (wplus2 symprp (times2 maxsymbols addressingunitsperitem)))
)

(de &&init-tables2()
    % synchronize lower id's - executed AFTER image loading
  (if mainstartinitialize
      (prog(hu ht)    % image has been read
         (setq hu heapupperbound ht heaptrapbound)    
         (&&symcopy symfnc old_symfnc)
         (&&symcopy symval old_symval)
         (setq heaptrapbound ht heapupperbound hu)
         (init-gcarray)
         )
      (progn    % start from scratch
         (&&symcopy old_symfnc symfnc)
         (&&symcopy old_symval symval)
         (&&symcopy old_symprp symprp)
         %(&&symcopy old_symget symget)
          )))

(de &&symcopy(from to)  
  (for (from i 0 kernel-maxsymbols) (do (wputv to i (wgetv from i)) )))

(lap '(
       (*entry _!p!s!l_!m!a!i!n expr 0)
       (push "ebp")
         % frame 1: (ebp)
         % frame 2: (ret addr)
         % frame 3: argc
         % frame 4: argv
	 % frame 5: ptr to SYMNAM on heap
       (*move (frame 5) (fluid symms))
       (*move (frame 3) (reg 1))
       (*move (frame 4) (reg 2))

       (*move (reg st) (fluid stacklowerbound))
       (*move (reg 1) (fluid argc))
       (*move (reg 2) (fluid argv))
       (*push (reg 1))
       (*push (reg 2))

       (*move infbitlength (fluid _infbitlength_))
       (*move (quote nil) (fluid mainstartinitialize))
       (*call &&init-tables1)
       
       (*pop (reg 2))
       (*pop (reg 1))
       (*link os_startup_hook expr 2)
       
       (*call &&init-tables2)

       (*call init-pointers)
       (*move (wconst -1)(reg 1))
       (*link &time-control expr 1)                     % reset timer

       (*move (frame 3) (reg 1)) % preserve argv & argc around image load
       (*move (frame 4) (reg 2))
       (*move (reg 1) (fluid argc))
       (*move (reg 2) (fluid argv))

       (*call pre-main)                                 % call PSL

panic-exit                      % need to do UNIX cleanup after
                                % a fatal error, so jump here
       (*move (wconst 0) (reg 1))
       (*linke 0 exit-with-status expr 1)
       (pop "ebp")
       (*exit 0)

  (*entry exit-with-status expr 1)
       (*link external_exit expr 1)
       (*exit 0)
       ))

(lap '(
       (*entry _!p!s!l!_!c!a!l!l expr 4)
       (push "ebp")
       (*move (frame 3) (reg 1))
       (*move (frame 4) (reg 2))
       (*move (frame 5) (reg 3))
       (*move (frame 6) (reg 4))
       (*call psl_call1)
       (pop "ebp")
       (*exit 0)
))

(de psl_call1(a b c d) nil)  % hook

(de &time-control(u) nil)    % hook

(de pre-main ()
  (unixcleario)
 (console-print-string "BPS:   ")(unixputn nextbps)
 (console-print-string "-")(unixputn lastbps)(console-newline)
 (console-print-string "HEAP:  ")(unixputn heaplast)
 (console-print-string "-")(unixputn heapupperbound)(console-newline)
 (console-print-string "STACK: ")(unixputn stacklowerbound)
 (console-print-string "-")(unixputn stackupperbound)(console-newline)
 (console-print-string "SYMVAL: ")(unixputn symval)
 (console-print-string " SYMFNC: ")(unixputn symfnc)
 (console-print-string " SYMPRP: ")(unixputn symprp)
 (console-print-string " SYMNAM: ")(unixputn symnam)
 (console-print-string " SYMGET: ")(unixputn symget)
 (console-newline)

  (initialize-symbol-table)
  (initcode)
  (console-print-string "About to load LOAD-PSL")
  (console-newline)
  (faslin "load-psl.b")
  (loader-main)
  )

(de external_strlen (str)
    (prog (zae)
       (setq zae 0)
     aa
       (when (eq 0 (byte str zae)) (return zae))
       (setq zae (wplus2 zae 1))
       (go aa)))

(de ! yield() )  % hook for synchronizing with garbage collector

(off fast-integers)

