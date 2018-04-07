%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PNK:COMPACT-GC.SL
% Title:          Compacting garbage collector for PSL                     
% Author:         Martin Griss and Eric Benson                             
% Created:        28 August 1981                                           
% Modified:       26-Dec-84 13:30:52 (Vicki O'Day)
% Status:         Open Source: BSD License
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:                                                               
%
%  1-Sep-88 (Julian Padget)
%  Changed system fluid variables to global.
% 3-Jul-1984 (Vicki O'Day)
%  Changed references to the constant forward to forward-tag, to match
%  the declaration in tags
% 01-Dec-83 14:24:38 (Brian Beach)                                         
%   Translated from Rlisp to Lisp.                                         
%                                                                          
% WARNING!  This file has not been parameterized using                     
% AddressingUnitsPerItem.  It will not work on machines that               
% address bytes. /csp 3-1-83                                               
% All data types have either explicit header tag in first item,            
% or are assumed to be 1st element of pair.                                
% Revision History:                                                        
% Edit by Cris Perdue, 16 Feb 1983 1407-PST                                
% Fixed GtHeap and collector(s) to use only HeapLast, not HeapPreviousLast 
% Sets HeapTrapped to NIL now.                                             
% Using known-free-space function                                          
%  Added check of Heap-Warn-Level after %Reclaim                           
%  Defined and used known-free-space function                              
%  <PSL.KERNEL>COMPACTING-GC.RED.9,  4-Oct-82 17:59:55, Edit by BENSON     
%  Added GCTime!*                                                          
%  <PSL.KERNEL>COMPACTING-GC.RED.3, 21-Sep-82 10:43:21, Edit by BENSON     
%  Flagged most functions internal                                         
% (M.L. Griss, March, 1977).                                               
% (Update to speed up, July 1978)                                          
% Converted to Syslisp July 1980                                           
% En-STRUCT-ed, Eric Benson April 1981                                     
% Added EVECT tag, M. Griss, 3 July 1982                                   
%                                                                          
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                                                                           
(fluid '(*gc % Controls printing of statistics                              
                                                                           
             gctime* % Total amount of time spent in GC                     
                                                                           
             gcknt* % count of # of GC's since system build                 
                                                                           
             heap-warn-level))

% Continuable error if this much not                                       
% free after %Reclaim.                                                     
(loadtime
  (progn (setq *gc t)
         % Do print GC messages (SL Rep says no)                           
         (setq gctime* 0)
         (setq gcknt* 0)
         % Initialize to zero                                              
         (setq heap-warn-level 1000)
         nil))

% Predicates for whether to follow pointers                                
(global '(heaptrapped heaplast heapupperbound heaplowerbound))

(setq heaptrapped nil)

(setq heaplast nil)

(setq heapupperbound nil)

(setq heaplowerbound nil)

% Boolean: has trap occurred since GC?                                     
(compiletime
  (progn (flag '(markfromallbases buildrelocationfields updateallbases 
                 compactheap markfromonesymbol makeidfreelist gcmessage 
                 markfromsymbols markfromrange markfrombase markfromvector 
                 gcerror updatesymbols updateregion updateitem updateheap)
               'internalfunction)
         (ds pointertagp (x) 
             (and (wgreaterp x (const posint)) (wlessp x (const code))))
         (ds withinheappointer (x) 
             (and (wgeq x heaplowerbound) (wleq x heaplast)))
         nil))

(define-constant gcmarkvalue 511)

(define-constant hskip (const forward-tag))

(compiletime
  (progn (ds mark (x) % Get GC mark bits in item X points to                
                                                                           
             (gcfield (getmem x)))
         (ds setmark (x) % Set GC mark bits in item X points to             
                                                                           
             (setf (gcfield (getmem x)) (const gcmarkvalue)))
         (ds clearmark (x) % Clear GC mark bits in item X points to         
                                                                            
             (setf (gcfield (getmem x)) (if (negintp (getmem x))
                     -1
                     0)))
         (ds marked (x) 
             (weq % Is item pointed to by X marked?                         
                                                                           
                  (mark x) (const gcmarkvalue)))
         (ds markid (x) 
             (setf (field (symnam x) (const tagstartingbit) 
                    (const tagbitlength))
                   (const forward-tag)))
         (ds markedid (x) (weq (tag (symnam x)) (const forward-tag)))
         (ds clearidmark (x) 
             (setf (field (symnam x) (const tagstartingbit) 
                    (const tagbitlength))
                   (const str)))
         % Relocation primitives                                           
         (ds skiplength (x) % Stored in heap header                         
                                                                            
             (inf (getmem x)))
         (ds putskiplength (x l) % Store in heap header                     
                                                                            
             (setf (inf (getmem x)) l))
         (put 'skiplength 'assign-op 'putskiplength)
         nil))

(define-constant bitsinsegment 13)

(define-constant segmentlength (wshift 1 (const bitsinsegment)))

(define-constant segmentmask (wdifference (const segmentlength) 1))

(define-constant gcarraysize 
                 (wplus2 (wshift (const heapsize) 
                          (wminus (const bitsinsegment)))
                         1))

(fluid '(gcarray))

(compiletime
  (progn (ds segmentnumber (x) 
             (wshift (wdifference % Get segment part of pointer             
                                                                           
                      x heaplowerbound)
                     (wminus (const bitsinsegment))))
         (ds offsetinsegment (x) 
             (wand (wdifference % Get offset part of pointer                
                                                                           
                    x heaplowerbound)
                   (const segmentmask)))
         (ds movementwithinsegment (x) % Reloc field in item                
                                                                            
             (gcfield (getmem x)))
         (ds putmovementwithinsegment (x m) % Store reloc field             
                                                                            
             (setf (gcfield (getmem x)) m))
         (ds clearmovementwithinsegment (x) % Clear reloc field             
                                                                            
             (setf (gcfield (getmem x)) (if (negintp (getmem x))
                     -1
                     0)))
         (put 'movementwithinsegment 'assign-op 'putmovementwithinsegment)
         (ds segmentmovement (x) 
             (wgetv (warray % Segment table                                 
                                                                           
                     gcarray)
                    x))
         (ds putsegmentmovement (x m) % Store in seg table                  
                                                                            
             (setf (wgetv gcarray x) m))
         (put 'segmentmovement 'assign-op 'putsegmentmovement)
         (ds reloc (x) 
             (wdifference % Compute pointer adjustment                      
                                                                           
              x 
              (wplus2 (segmentmovement (segmentnumber x)) 
                      (movementwithinsegment x))))
         nil))

(global '(stacklowerbound st))

(setq stacklowerbound nil)

% (setq st nil)

% bottom of stack                                                          
% Base registers marked from by collector                                  
% SymNam, SymPrp and SymVal are declared for all                           
(global '(nextsymbol))

(setq nextsymbol nil)

% next ID number to be allocated                                           
(global '(bndstkptr bndstklowerbound))

(setq bndstkptr nil)

(setq bndstklowerbound nil)

% Binding stack pointer                                                    
(fluid '(startingrealtime heapshrink hole marktag stackstart stackend))

(setq startingrealtime nil)

(setq heapshrink nil)

(setq hole nil)

(setq marktag nil)

(setq stackstart nil)

(setq stackend nil)

(de reclaim ()
  %. User call to garbage collector                                        
  (progn (!%reclaim)
         nil))

(de !%reclaim ()
  % Garbage collector                                                      
  (progn (setq stackend 
               (wdifference (makeaddressfromstackpointer st) (framesize)))
         (setq stackstart stacklowerbound)
         (when *gc
           (errorprintf "*** Garbage collection starting"))
         (setq startingrealtime (timc))
         (setf gcknt* (wplus2 gcknt* 1))
         % must be INUM > 0, so needn't chk                                
         (markfromallbases)
         (makeidfreelist)
         (buildrelocationfields)
         (updateallbases)
         (compactheap)
         (setq heaplast (wdifference heaplast heapshrink))
         (setq startingrealtime (wdifference (timc) startingrealtime))
         (setf gctime* (wplus2 gctime* startingrealtime))
         (when *gc
           (gcmessage))
         (setq heaptrapped nil)
         (when (wlessp (intinf (known-free-space)) 
                       (intinf heap-warn-level))
           (continuableerror 99 "Heap space low" nil))
         nil))

(de markfromallbases ()
  (prog (b)
        (markfromsymbols)
        (markfromrange stackstart stackend)
        (setq b bndstklowerbound)
        (while (progn (setq b (adjustbndstkptr b 1))
                      (wleq b bndstkptr))
          (markfrombase (getmem b)))))

(de markfromsymbols ()
  (prog (b)
        (markfromonesymbol 128)
        (wfor % mark NIL first                                              
                                                                           
              (from i 0 127 1) 
              (do (unless (markedid i)
                    (markfromonesymbol i))))
        (wfor (from i 0 (const maxobarray) 1) 
              (do (progn (setq b (obarray i))
                         (when (and (wgreaterp b 0) (not (markedid b)))
                           (markfromonesymbol b)))))))

(de markfromonesymbol (x)
  % SymNam has to be marked from before marking ID, since the mark uses its tag
                                                                           
  % No problem since it's only a string, can't reference itself.           
  (progn (markfrombase (symnam x))
         (markid x)
         (markfrombase (symprp x))
         (markfrombase (symval x))))

(de markfromrange (low high)
  (wfor (from ptr low high 1) (do (markfrombase (getmem ptr)))))

(de markfrombase (base)
  (prog (markinfo)
        (setq marktag (tag base))
        (unless (pointertagp marktag)
          (return (progn (when (and (weq marktag (const id)) 
                                (not (null base)))
                           (setq markinfo (idinf base))
                           (unless (markedid markinfo)
                             (markfromonesymbol markinfo))))))
        (setq markinfo (inf base))
        (when (or (not (withinheappointer markinfo)) (marked markinfo))
          (return nil))
        (setmark markinfo)
        (commentoutcode (checkandsetmark markinfo))
        (return (cond ((or (weq marktag (const vect)) 
                        (weq marktag (const evect)))
                       (markfromvector markinfo))
                      ((weq marktag (const pair)) 
                       (markfrombase (car base)) (markfrombase (cdr base)))))))

(commentoutcode (progn (de checkandsetmark (p)
                         (prog (headatp)
                               (setq headatp (tag (getmem p)))
                               (case marktag 
                                (((const str)) (when (weq headatp 
                                                      (const hbytes))
                                   (setmark p)))
                                (((const fixn) (const fltn) (const bign) 
                                  (const wrds))
                                 (when (weq headatp (const hwrds))
                                   (setmark p)))
                                (((const vect) (const evect)) (when (weq 
                                                                     headatp
                                                                     (const 
                                                                      hvect))
                                   (setmark p)))
                                (((const pair)) (setmark p)) 
                                (nil 
                                 (gcerror 
                                  "Internal error in marking phase, at %o" 
                                  p)))))
                       nil))

(de markfromvector (info)
  (prog (uplim)
        (commentoutcode (when (wneq (tag (getmem info)) (const hvect))
                          (return nil)))
        (setq uplim (loc (vecitm info (veclen info))))
        (wfor (from ptr (loc (vecitm info 0)) uplim 1) 
              (do (markfrombase (getmem ptr))))))

(de makeidfreelist ()
  (prog (previous)
        (wfor (from i 0 128 1) (do (clearidmark i)))
        (setq previous 129)
        (while (and (markedid previous) (wleq previous (const maxsymbols)))
          (clearidmark previous)
          (setq previous (wplus2 previous 1)))
        (if (wgeq previous (const maxsymbols))
          (setq nextsymbol 0)
          (setq nextsymbol previous))
        (wfor % free list starts here                                       
                                                                           
              (from i (wplus2 previous 1) (const maxsymbols) 1) 
              (do (if (markedid i)
                    (clearidmark i)
                    (progn (setf (symnam previous) i)
                           (setq previous i)))))
        (setf (symnam previous) 0)))

% end of free list                                                         
(de buildrelocationfields ()
  %                                                                        
  %        Pass 2 - Turn off GC marks and Build SEGKNTs                    
  %                                                                        
  (prog (currentitem sgcurrent igcurrent tmpig dcount seglen)
        (setq sgcurrent (setq igcurrent 0))
        (setf (segmentmovement sgcurrent) 0)
        % Dummy                                                            
        (setq hole (wdifference heaplowerbound 1))
        % will be first hole                                               
        (setq dcount (setq heapshrink 0))
        % holes in current segment, total holes                            
        (setq currentitem heaplowerbound)
        (while (wlessp currentitem heaplast)
          (prog (incr)
                (setq seglen 
                      (case (tag (getmem currentitem)) 
                       (((const btrtag) (const code) (const negint) 
                         (const posint) (const id) (const unbound) 
                         (const str) (const bytes) (const fixn) 
                         (const fltn) (const bign) (const wrds) 
                         (const halfwords) (const pair) (const vect) 
                         (const evect))
                        2)
                       (((wconst % must be first of pair                    
                                                                           
                          hbytes))
                        (wplus2 1 (strpack (strlen currentitem))))
                       (((const hhalfwords)) 
                        (wplus2 1 (halfwordpack (strlen currentitem))))
                       (((const hwrds)) 
                        (wplus2 1 (wrdpack (wrdlen currentitem))))
                       (((const hvect)) 
                        (wplus2 1 (vectpack (veclen currentitem))))
                       (((const hskip)) (skiplength currentitem)) 
                       (nil 
                        (gcerror "Illegal item in heap at %o" currentitem))))
                % case                                                     
                (cond ((marked currentitem) % a hole                        
                                                                            
                       (cond ((weq heapshrink 0) (clearmark currentitem))
                             (t % segment also clears mark                  
                                                                           
                              (progn (setf 
                                      (movementwithinsegment currentitem) 
                                      dcount)
                                     % incremental shift                   
                                     (setq incr 0)))))
                      (t % no shift                                         
                                                                           
                         (progn (setf (getmem currentitem) 
                                 (mkitem (const hskip) seglen))
                                % a skip mark                              
                                (setq incr 1)
                                % more shift                               
                                (when (wlessp hole heaplowerbound)
                                  (setq hole currentitem)))))
                (setq tmpig (wplus2 igcurrent seglen))
                % set SEG size                                             
                (setq currentitem (wplus2 currentitem seglen))
                (while (wgeq tmpig (const segmentlength))
                  (prog (tmp)
                        (setq tmp 
                         (wdifference (const segmentlength) igcurrent))
                        % Expand to next SEGMENT                           
                        (setq seglen (wdifference seglen tmp))
                        (when (weq incr 1)
                          (setq heapshrink (wplus2 heapshrink tmp)))
                        (setq dcount (setq igcurrent 0))
                        (setq sgcurrent (wplus2 sgcurrent 1))
                        (setf (segmentmovement sgcurrent) heapshrink)
                        % Store Next Base                                  
                        (setq tmpig 
                         (wdifference tmpig (const segmentlength)))))
                (setq igcurrent tmpig)
                (when (weq incr 1)
                  (setq heapshrink (wplus2 heapshrink seglen))
                  (setq dcount (wplus2 dcount seglen)))))
        % Add in Hole Size                                                 
        (setf (segmentmovement (wplus2 sgcurrent 1)) heapshrink)))

(de updateallbases ()
  (prog (b)
        (updatesymbols)
        (updateregion stackstart stackend)
        (setq b bndstklowerbound)
        (while (progn (setq b (adjustbndstkptr b 1))
                      (wleq b bndstkptr))
          (updateitem b))
        (updateheap)))

(de updatesymbols ()
  (wfor (from i 0 (const maxsymbols) 1) 
        (do (prog (nameloc)
                  (setq nameloc (loc (symnam i)))
                  (when (stringp (getmem nameloc))
                    (updateitem nameloc)
                    (updateitem (loc (symval i)))
                    (updateitem (loc (symprp i))))))))

(de updateregion (low high)
  (wfor (from ptr low high 1) (do (updateitem ptr))))

(de updateheap ()
  (prog (currentitem)
        (setq currentitem heaplowerbound)
        (while (wlessp currentitem heaplast)
          (prog nil
                (case (tag (getmem currentitem)) 
                      (((const btrtag) (const code) (const negint) 
                        (const posint) (const id) (const unbound))
                       (setq currentitem (wplus2 currentitem 1)))
                      (((const str) (const bytes) (const fixn) 
                        (const fltn) (const bign) (const wrds) 
                        (const halfwords) (const pair) (const vect) 
                        (const evect))
                       (progn (when (and 
                                     (wgeq (inf (getmem currentitem)) hole) 
                                     (wleq (inf (getmem currentitem)) 
                                      heaplast))
                                (setf (inf (getmem currentitem)) 
                                 (reloc (inf (getmem currentitem)))))
                              (setq currentitem (wplus2 currentitem 1))))
                      (((const hbytes)) 
                       (setq currentitem 
                        (wplus2 currentitem 1 
                         (strpack (strlen currentitem)))))
                      (((const hhalfwords)) 
                       (setq currentitem 
                        (wplus2 currentitem 1 
                         (halfwordpack (strlen currentitem)))))
                      (((const hwrds)) 
                       (setq currentitem 
                        (wplus2 currentitem 1 
                         (wrdpack (wrdlen currentitem)))))
                      (((const hvect)) 
                       (prog (tmp)
                             (setq tmp (veclen currentitem))
                             (setq currentitem (wplus2 currentitem 1))
                             (wfor % Move over header                       
                                                                           
                              (from i 0 tmp 1) 
                              (do % VecLen + 1 items                        
                                                                           
                               (prog (tmp2 tmp3)
                                     (setq tmp2 (getmem currentitem))
                                     (setq tmp3 (tag tmp2))
                                     (when (and (pointertagp tmp3) 
                                            (wgeq (inf tmp2) hole) 
                                            (wleq (inf tmp2) heaplast))
                                       (setf (inf (getmem currentitem)) 
                                        (reloc (inf tmp2))))
                                     (setq currentitem 
                                      (wplus2 currentitem 1)))))))
                      (((const hskip)) 
                       (setq currentitem 
                        (wplus2 currentitem (skiplength currentitem))))
                      (nil 
                       (gcerror "Internal error in updating phase at %o" 
                        currentitem)))))))

% case                                                                     
(de updateitem (ptr)
  (prog (tg info)
        (setq tg (tag (getmem ptr)))
        (unless (pointertagp tg)
          (return nil))
        (setq info (inf (getmem ptr)))
        (when (or (wlessp info hole) (wgreaterp info heaplast))
          (return nil))
        (setf (inf (getmem ptr)) (reloc info))))

(de compactheap ()
  (prog (olditemptr newitemptr seglen)
        (when (wlessp hole heaplowerbound)
          (return nil))
        (setq newitemptr (setq olditemptr hole))
        (while (wlessp olditemptr heaplast)
          (prog nil
                (case (tag (getmem olditemptr)) 
                      (((const btrtag) (const code) (const negint) 
                        (const posint) (const id) (const unbound) 
                        (const str) (const bytes) (const fixn) 
                        (const fltn) (const bign) (const wrds) 
                        (const halfwords) (const pair) (const vect) 
                        (const evect))
                       (setq seglen (pairpack olditemptr)))
                      (((const hbytes)) 
                       (setq seglen 
                        (wplus2 1 (strpack (strlen olditemptr)))))
                      (((const hhalfwords)) 
                       (setq seglen 
                        (wplus2 1 (halfwordpack (halfwordlen olditemptr)))))
                      (((const hwrds)) 
                       (setq seglen 
                        (wplus2 1 (wrdpack (wrdlen olditemptr)))))
                      (((const hvect)) 
                       (setq seglen 
                        (wplus2 1 (vectpack (veclen olditemptr)))))
                      (((const hskip)) 
                       (progn (setq olditemptr 
                               (wplus2 olditemptr (skiplength olditemptr)))
                              (go whilenext)))
                      (nil 
                       (gcerror "Internal error in compaction at %o" 
                        olditemptr)))
                % case                                                     
                (clearmovementwithinsegment olditemptr)
                (wfor (from i 1 seglen 1) 
                      (do 
                       (progn (setf (getmem newitemptr) 
                               (getmem olditemptr))
                              (setq newitemptr (wplus2 newitemptr 1))
                              (setq olditemptr (wplus2 olditemptr 1)))))
           whilenext
           nil))))

(de gcerror (message p)
  (errorprintf "***** Fatal error during garbage collection")
  (errorprintf message p)
  (while t
    (quit))
  nil)

(de gcmessage ()
  (errorprintf "*** GC %w: time %d ms" gcknt* startingrealtime)
  (errorprintf "*** %d recovered, %d stable, %d active, %d free" 
               heapshrink (wdifference hole heaplowerbound) 
               (wdifference heaplast hole) (intinf (known-free-space))))

