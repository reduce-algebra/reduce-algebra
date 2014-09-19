%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PXK:MAIN-START.SL
% Title:          First routine called on startup
% Author:         Brian Beach, Hewlett-Packard CRC
% Created:        16-Feb-84
% Modified:       May 16 1985
% Status:         Experimental
% Mode:           Lisp
% Package:        Kernel
%
% (c) Copyright 1990, Konrad-Zuse-Zentrum Berlin, all rights reserved.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 2-Nov-90 (Winfried Neun)
%  Initial version for IBM RS 6000
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (ds kernelstring2string (s) s))
(compiletime (flag '($fluid fluid global $global) 'terminaloperand))
(compiletime    %% Move this hack somewhere else later.
 (defmacro exported-global (list)
   (for (in id (second list))   % list is quoted
        (do 
         (flag1 id 'exportedsymbol)
         (put id 'symbol id)
         (put id 'vartype 'global)
         ))
   ))

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

(compiletime (dskin "$pxc/sys-consts.sl"))

(declare-kernel-structure 
 (stack             2) % #.(compiler-constant 'stacksize))
 (tokenbuffer       #.(compiler-constant 'maxtokensize))
 (bndstk            #.(compiler-constant 'bndstksize))
 (catchstack        #.(times2 (compiler-constant 'catchstacksize) 4))
 (hashtable         #.(quotient (compiler-constant 'hash-table-size) 2))
 (onewordbuffer     1)
 (saveargc          1)
 (saveargv          1)
 (datebuffer        1)
 (sparcjumpbuf      6)
 (isasavesystem     2)
 (argumentblock     #.(compiler-constant 'maxargs))
 )

(exported-global
 '(bndstkptr   bndstkupperbound   bndstklowerbound 
   gcarraylowerbound   gcarrayupperbound
   heaplast   oldheaplast
   heaplowerbound  heaptrapbound   oldheaptrapbound   heapupperbound
   _infbitlength_   lastbps   bpslowerbound   mainstartinitialize
   nextbps   oldheapupperbound   oldheaplowerbound
   stacklowerbound   stackupperbound   saveda7
   unixstdin   unixstdout   unixstderr   unixnull   unixeof   unixtty
   ))

(internal-global  '(   symnam  symval  symget symfnc  symprp   ))

(system-global  '(symnam symval symprp  symfnc symget
                  %  stack
                  catchstackptr   catchstack
                  bndstklowerbound   bndstkupperbound
                  bndstkptr   bndstk
                  heap
                  nextsymbol    %% Had SYMBOL as its assembler symbol.  why????
                    % Add these so they are always availbale to compiled code.
                  ***MUST-BE-NIL***   ***MUST-BE-NIL-TOO***
                  *fastcar
                 sparcjumpbuf
   ))

(compiletime (off immediatequote))

(de init-pointers()

  (setq catchstackptr catchstack )
  (setq bndstklowerbound bndstk )
  (setq bndstkupperbound (loc (wgetv bndstk (wdifference bndstksize 1))))
  (setq bndstkptr bndstk)
  (setq heap heaplowerbound)
  (init-viv)
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
  (setq *fastcar nil))

(compiletime % copying the actual known viv variable to viv area
(progn
 (fluid '(collected-viv*)) 
 
 (dm collect-viv (u) 
   (prog (hhh) 
      (mapobl (function collect-viv-1)) 
      (setq hhh (append `((*entry init-viv expr 0) (*alloc 0)) 
                           (append collected-viv* '((*exit 0)))))
      (return (setq hhh (list 'lap (list 'quote hhh)))))) 
 
 (de collect-viv-1(x) 
    (prog (g) 
      (when (and (or (setq g (get x 'registername))
		     (setq g (get x '*other-name)))
                 (or (get x 'symbol) (get x 'idnumber)))
          (findidnumber x) 
          (return
           (setq collected-viv*
            (append `((*movex ($fluid ,x) (reg ,g))) collected-viv*))))
)) 
))

(collect-viv) %do it now

(compiletime (on mainfound))

(lap '((*entry !_!p!s!l_!m!a!i!n expr 0)
       (*alloc 1) 

       (*move  (reg argone) (fluid argc))  % system dependent for sun-4. We move
                                       % the argc value (reg i0) into the
                                       %fluid argc. 
	("   .globl _copy_argv")
       (bl (foreignentry copy_argv))     % call c function to store argv 
       (cror 15 15 15)                   % into static space.
       (*move (reg 1) (fluid argv))
       (addis  (reg r17) "0,ha16(_SYMFNC)")
       (la (reg r17) "lo16(_SYMFNC)(r17)")
       (*move (reg symfnccenter) ($fluid symfnc))
       (*wplus2 (reg symfnccenter) 32000) 

       (addis (reg r18) "0,ha16(_SYMVAL)")
       (la (reg r18) "lo16(_SYMVAL)(r18)")
       (*move (reg symvalcenter) ($fluid symval))
       (*wplus2 (reg symvalcenter) 32000)
       (*movex ($fluid t) (reg r3))
%
% Next step: initializing special registers such that symval and symfnc can be
% accessed by one instruction
%

       (*move (fluid argc) (reg 1))
       (*move (fluid argv) (reg 2))
       (*move infbitlength (fluid _infbitlength_))
       (*link os_startup_hook expr 2)
       (*jumpnoteq (label notasavesystem) (reg 1) 4711)
        
       (*move (reg st) (reg t1) )
       (*wshift (reg t1) -5)
       (*move (Reg t1) ($fluid stacklowerbound)) % is a sys int that way!

       (*call init-viv)
       (*move ($fluid heaplastsave) (reg r20)) % ($fluid heaplast))

       (*move 128 (reg NIL))
       (*mkitem (reg NIL) id-tag)                 % initialize NIL reg
       (*call pre-main)                                 % call PSL
        
       (*move (wconst 0) (reg 1))
       (*linke 1 exit-with-status expr 1)
       (*exit 1)

   notasavesystem

%*****************************************************************************

       %  Do OS specific initializations (uses argc and argv)
       (*call init-pointers)
       
       (*call init-viv)

       (*move (reg st) (reg t1) )
       (*wshift (reg t1) -5)
       (*move (Reg t1) ($fluid stacklowerbound)) % is a sys int that way!

       (*move 128 (reg NIL))
       (*mkitem (reg NIL) id-tag)                   % initialize NIL reg
       (*call pre-main)                                 % call PSL

panic-exit                      % need to do UNIX cleanup after
                                % a fatal error, so jump here
       (*move (wconst 0) (reg 1))
       (*linke 1 exit-with-status expr 1)
       (*exit 1)

       (*entry exit-with-status expr 1)
         (*alloc 1)
         (*move (reg 1) (frame 1))
         (*link os_cleanup_hook expr 0)
         (*move (frame 1) (reg 1))
         (*link external_exit expr 1)
         (*exit 1)))

(de pre-main ()
  (unixcleario)
  (initialize-symbol-table)
  (initcode)
  (console-print-string "About to load LOAD-PSL")
  (console-newline)
  (faslin "load-psl.b")
  (loader-main))


(compiletime (remflag '($fluid fluid global $global) 'terminaloperand))
(off fast-integers)
