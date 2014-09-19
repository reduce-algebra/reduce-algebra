%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:SYS-SUPPORT.SL
% Description:  System specific kernel support functions.
% Author:       Brian Beach, Hewlett-Packard`CRC
% Created:      22-Feb-84
% Modified:     29-Jun-84 13:56:27 (RAM)
% Mode:         Lisp
% Status:       Experimental (Do Not Distribute)
%
% (c) Copyright 1984, Hewlett-Packard Company, all rights reserved.
% (c) Copyright 1989, Konrad-Zuse-Zentrum Berlin, all rights reserved.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 28-Nov-90 (Winfried Neun)
%  Version for IBM RS 6000
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(on fast-integers)

(lap '((*entry PlantUnbound expr 1)
       
        (*alloc 0)
	(*move (reg 1) (reg t2))
	(*wshift (reg t2) 2)
	(*WPLUS2 (reg t2) (fluid SYMFNC))       
	(*move (times2 4 (idloc UndefinedFunction)) (reg t3))
	(*wplus2 (reg t3) (fluid symfnc))
	(l (reg t1) (displacement (reg  t3) 0))
	(*move (reg t1) (displacement (reg t2) 0))
	(*EXIT 0)))

(compiletime (flag '(PlantCodePointer-normal PlantCodePointer-kernel) 
			'internalfunction))

(de PlantCodePointer (idnum codinf)
     (if (wlessp codinf (inf bpslowerbound))
			 % then it points to kernel most probably
         (PlantCodePointer-kernel idnum codinf)
        (PlantCodePointer-normal idnum codinf)))

(lap '( (*entry PlantCodePointer-normal expr 2)
         (*alloc 0)
	(*move (reg 1) (reg t2))
	(*wshift (reg t2) 2)
	(*WPLUS2 (reg t2) (fluid SYMFNC))       
	(*mkitem (reg 2) string-tag)
	(*move (reg 2) (displacement (reg t2) 0)) % and plant it
        (*EXIT 0)))

(lap '( (*entry PlantCodePointer-kernel  expr 2) % this one is for copyd of
         (*alloc 0)                              % kernel functions
        (*move (reg 1) (reg t2))
        (*wshift (reg t2) 2)
        (*WPLUS2 (reg t2) (fluid SYMFNC))
        (*mkitem (reg 2) 2)
        (*move (reg 2) (displacement (reg t2) 0)) % and plant it
        (*EXIT 0)))

(lap '( (*entry PlantLambdaLink expr 1)
        (*alloc 0)
        (*move (reg 1) (reg t2))
        (*wshift (reg t2) 2)
        (*WPLUS2 (reg t2) (fluid SYMFNC))
        (*move (times2 4 (idloc COMPILEDCALLINGINTERPRETED)) (reg t3))
        (*wplus2 (reg t3) (fluid symfnc))
        (l (reg t1) (displacement (reg  t3) 0))
        (*move (reg t1) (displacement (reg t2) 0))
        (*EXIT 0)))


(lap '((*entry COMPILEDCALLINGINTERPRETED expr 0)
      (l (reg t4) "T.SYMFNC(2)")
      (l (reg t4) (displacement (reg t4)
			 (times2 4 (idloc compiledcallinginterpretedaux))))
      (mtspr (reg ctr) (reg t4))
      (bcc always 0)))

(de bittable (baseaddress bitoffset)
  (field (ilsh (byte baseaddress (ilsh bitoffset -2))
               (idifference (itimes2 (field bitoffset 30 2) 2) 6))
         30 2))

   % to be redefined in nonkernel

(lap '((*entry undefinedfunction expr 1)
      (l (reg t4) "T.SYMFNC(2)")
      (l (reg t4) (displacement (reg t4)
                         (times2 4 (idloc undefinedfunctionaux))))
      (mtspr (reg ctr) (reg t4))
      (bccl always 0)))

(lap '((*entry undefinedfunctionaux expr 1)
       (*alloc 1)
       (*move (reg t3) (frame 1))
       (*move (quote "Undefined function called: ") (reg 1))
       (*call console-print-string)
       (*move (frame 1) (reg t1))
       (*wshift (reg t1) 2)
       (*wplus2 (reg t1) (fluid symnam))
       (*move (displacement (reg t1) 0) (reg 1))
       (*call console-print-string)
       (*call console-newline)
       (*move 0 (reg 1))
       (*call Exit-with-status)
       (*exit 1)))

(de kernel-fatal-error (string)
  (console-print-string (kernelstring2string "FATAL ERROR: "))
  (console-print-string string)
  (console-newline)
  (exit-with-status -1))

(off fast-integers)

% signalhandler must reside in kernel

(lap '((*entry signalhaendler expr 0)
%       We save the information which is in 'scratch' registers.
%
       (*move (reg 1) (fluid ibmrs-signumber))
       (*move (reg 3) (fluid ibmrs-sigcp))
       (*move (indexed (reg 3) 40) (reg 5))
       (*move (reg st) (fluid ibmrs-sigaddr))
       (*move (reg 5) (fluid ibmrs-sigpc))
  
%  Check whether LISP trap handling is appropriate now

       (*movex ($fluid *kernelmode) (reg 5))
       (*move 16#80 (reg nil))
       (*mkitem (reg nil) id-tag)
       (*jumpnoteq (label goon) (reg 5) 'nil)
       (*jumpnoteq (label templab) (reg 1) (quote 2)) % interrupt
       (*movex ($fluid *bruch*) (reg 5))
       (*jumpeq    (label templab) (reg 5) 0)
%
% Now we have a 'weaponed' interrupt. This is used e.g. by gc to remain
% operable. Return Immediately and mark with a negative value in *bruch* !!
%
    goon
       (*move -17 (reg 5))
       (*movex (reg 5) ($fluid *bruch*))
       (*move 0 (reg 5))
       (*movex (reg 5) (fluid ibmrs-sigcp))
       (*exit 0)
     
    templab
       (*move 0 (reg 4))
       (*move (reg 3) (reg t2))
       (*wplus2 (reg t2) 224)
       (*move ($fluid ibmrs-dumparray*) (reg 5)) 
      loop
       (*wplus3 (reg t3) (reg t2) (reg 4))
       (*wplus3 (reg t4) (reg 5) (reg 4))
       (*move (displacement (reg t3) 0) (reg t1))
       (*move (reg t1) (displacement (reg t4) 0))
       (*wplus2 (reg 4) 4)
       (*jumpwlessp (label loop) (reg 4) 129)

       (*jcall signal-done)
))

(compiletime (flag '(profil) 'foreignfunction))

(lap '((*entry unix-profile expr 4)
       (*alloc 1)
       (*link profil expr 4)

       (*move 0 (reg 1))
       (*exit 1)))

