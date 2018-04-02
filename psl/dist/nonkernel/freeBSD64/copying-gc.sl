%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:COPYING-GC.SL
% Description:  Copying 2-space garbage collector for PSL
% Author:       Eric Benson
% Created:      30 November 1981
% Modified:     29-Aug-84 10:09:08 (Brian Beach)
% Package:
% Status:	Open Source: BSD License
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
%  20-July-89 (Winfried Neun)
%  Made heapsize enlargeable for 2 space collector. Will be enlarged auto-
%  matically by heapenlarge* items if not more than heap-warn-level is free
%  Added function (set-heap-size items)
%  20-June-89 (Winfried Neun)
%  Added handling of symget vector, modification in copyitem1
%  2-June-89 (Winfried Neun)
%  Changed message format again, copyfromstack now allows a bignum to point to
%  a hwords tag item (formerly a hvect item) for nbig30.
%  10-March-89 (Winfried Neun)
%  Fixed bug with timing(oldtime), new message formats in gcstats and cfserror.
%  1-Sep-88 (Julian Padget)
%  Changed system fluid variables to global.
% 16-Jun-87 (Leigh Stoller)
%  Added Mark Swanson's hack to the GC that ignores bogus stack items.
% 10-Dec-1986 (Tim Mueller)
%  Fixed bug in reclaim2() where oldHeapLowerBound
%   might be equal to heapUpperBound (changed > to >=).
% 9 Oct 1986 - Fix by Russ Fish and Tim Mueller to eliminate device dependent
% code in reclaim2 where null objects are detected.  Also can now repeat
% reclaim2's.
% 6-Feb-86 08:10:09 (Mark Swanson)
%  put in some NIL checks (strictly) for speed;  took out a gratuitous
%  putmem in the non-pointertag case of copyitem
% 6-Feb-86 07:15:59 (Mark Swanson)
%  changed calls on copyfrombase to copyitem, since that's all former
%  did was to call the latter anyway
% 5-Feb-86 21:54:00 (Mark Swanson)
%  Added RECLAIM2 for static heap from 3.2 implementation.
% 24-Jul-84 08:29:01 (Brian Beach)
%  Changed names of tags for micro-kernel.
%  Removed uses of CONST.
% 3 Jul 1984 (Vicki O'Day)
%  Changed references to the constant forward to forward-tag, to match
%  the declaration in tags
% 26 Jan 1984 0958-PST (Brian Beach)
%  Corrected file name in header.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
%
% Old Revision history:
%
% 14 Dec 83 (Cris Perdue)
%  Added handling of BYTES and HALFWORDS to this version.
% Edit by Mark Swanson, 3 April 1983 0949-MST
% Made COPYITEM1 tail-recursive so that long lists can be copied without
% stack overflow -- both COPYITEM and COPYITEM1 are now called exclusively
% for their side effects--return values should be ignored.
% Edit by Cris Perdue, 25 Mar 1983 1711-PST
% Occurrence of heap-warn-level in initialization no longer flagged
% with "LispVar".  Didn't work.
%  <PSL.KERNEL>COPYING-GC.RED.2, 23-Mar-83 11:35:37, Edit by KESSLER
%  Add HeadTrapBound Guys, so we can update the heap trap bound upon switch
% Edit by Cris Perdue, 15 Mar 1983 0937-PST
% Added missing comma as noted by Kessler.
% Edit by Cris Perdue, 16 Feb 1983 1409-PST
% Removed external declaration of HeapPreviousLast (the only occurrence)
% Now using "known-free-space" function and heap-warn-level
% Sets HeapTrapped to NIL now.
% Added check of Heap!-Warn!-Level after %Reclaim.
%  <PSL.KERNEL>COPYING-GC.RED.6,  4-Oct-82 17:56:49, Edit by BENSON
%  Added GCTime!*
 
(on fast-integers)
 
(compiletime (load hash-decls if-system))
 
(fluid '(*gc gcknt* gctime* heap-warn-level symget))
 
(loadtime
  (progn (setq gcknt* 0)
         (setq gctime* 0)
     (setq StaticHeapBase 0)
     (setq StaticHeapUpperBound 0)
         (setq *gc t)
         (setq heap-warn-level 30000)))
 
(compiletime
 (progn
  (ds !%chipmunk-kludge (x) x)   %%% TEMPORARY
 
  (ds pointertagp (x)
    (and (> x posint-tag) (< x code-tag)))
 
  (ds itemtagp (x)
    (or (eq x id-tag)
        (eq x negint-tag)
    (eq x code-tag)
    (<= x evector-tag)))
 
  (ds withinoldheappointer (x)
    (and (wgeq x (!%chipmunk-kludge oldheaplowerbound))
     (wleq x (!%chipmunk-kludge oldheaplast))))
 
  (ds mark (x)
    (mkitem forward-tag x))
 
  (ds marked (x)
    (weq (tag x) forward-tag))
 
  (ds markid (x)
    (setf (field (symnam x) tagstartingbit tagbitlength)
      forward-tag))
 
  (ds markedid (x)
    (weq (tag (symnam x)) forward-tag))
 
  (ds clearidmark (x)
    (setf (field (symnam x) tagstartingbit tagbitlength) string-tag)
    )
 
  (ds exchange (a b)
    (let ((*temp* a))
      (setf a b)
      (setf b *temp*)
      ))
 
  (flag '(copyfromallbases
      copyfromrange
      copyfrombase
      copyitem
      copyitem1
      copypairitem
      markandcopyfromid
      makeidfreelist
      moreheap
      gcstats)
    'iinternalfunction)
  ))
 
(global '(heaptrapped
     oldheaptrapbound
     heaptrapbound
     oldheapupperbound
     oldheaplowerbound
     oldheaplast
     heapupperbound
     heaplowerbound
     heaplast
     bndstkptr
     bndstklowerbound
     stacklowerbound
%        st
         nextsymbol
     StaticHeapBase
     StaticHeapUpperBound
     ))
 
(fluid '(oldsize
     oldtime
     stacklast
     heapenlarge*
     ))

(setq heapenlarge* 250000)
 
(de Reclaim2 nil
  (prog (oldhsize newsize staticsize)
    (cond ((geq OldHeapLowerBound HeapUpperBound)
    (!%Reclaim)))                   % make sure we're in upper heap
    (!%Reclaim)                         % to get into lower heap
    (setq oldhsize (difference HeapUpperBound HeapLowerBound))
    % Only set this once (may be called more than once)
    (when (eq StaticHeapBase 0)
      (setq StaticHeapBase HeapLowerBound))
    (cond ((equal (land HeapLast 7) 8)
        (setq HeapLast (plus HeapLast 8))))
    (setq HeapLowerBound HeapLast)
    (setq StaticHeapUpperBound HeapLast)
    (setq staticsize (difference StaticHeapUpperBound StaticHeapBase))
    (setq HeapUpperBound (plus HeapLowerBound
        (quotient (difference OldHeapUpperBound HeapLowerBound) 2)))
    (setq OldHeapLowerBound (plus HeapUpperBound 8))
    (setq newsize (difference HeapUpperBound HeapLowerBound))
    (setq HeapTrapBound HeapUpperBound)
    (setq OldHeapTrapBound OldHeapUpperBound)
    (printf "Old Heap Size: %d, New Heap Size: %d, Static Heap Size: %d"
    oldhsize newsize staticsize)))
 
(de reclaim ()
  (!%reclaim))
 
(de !%reclaim ()
 (prog (b oldtimehi oldtimelo enlargement-tried)
  (when *gc
    (errorprintf "*** Garbage collection starting")
    )
 another-one
  (internal_beforegcsystemhook)
  (beforegcsystemhook)
  (setq stacklast
    (makeaddressfromstackpointer
     (adjuststackpointer (current-stack-pointer) (wminus (framesize)))))
  (setq oldtimehi (timc)) % a strange problem after 5 hours
  (setq oldtimelo (wand oldtimehi 16#ffff))
  (setq oldtimehi (wshift oldtimehi -16))
  (setq oldsize (wdifference heaplast heaplowerbound))
  (setf gcknt* (+ gcknt* 1))
 
  (setq oldheaplast heaplast)
  (setq heaplast oldheaplowerbound)
 
  (exchange heaplowerbound  oldheaplowerbound)    % Swap heaps
  (exchange heapupperbound  oldheapupperbound)
  (exchange heaptrapbound   oldheaptrapbound)
 
  (copyfromallbases)
  (makeidfreelist)
  (internal_aftergcsystemhook)
  (aftergcsystemhook)
 
  (setq oldtime (wor (wshift oldtimehi 16) oldtimelo))
  (setq oldtime (wdifference (timc) oldtime))
  (setf gctime* (wplus2 gctime* oldtime))
  (when (not (posintp gctime*)) (setq gctime* (inf -1)))
                 % another 5 hours problem
 
  (when *gc
    (gcstats))
  (setq heaptrapped nil)
 
  (when enlargement-tried 
    (if (wleq (moreheap heapenlarge*) 0) 
        (progn (continuableerror 99 "Heap space low" nil)
               (return NIL))
        (when *gc
            (Errorprintf "*** Heap space has been enlarged by %w items"
                                heapenlarge* ) )
        (when *gc (gcstats))
        (return NIL)
    ))

  (when (or (wlessp (intinf (known-free-space)) (intinf heap-warn-level))
            (force-heap-enlargement))
    % try to enlarge heap space via call to alterheapsize
    % make sure that stuff is in lower part
    (when (wgreaterp heapupperbound oldheapupperbound)
          (setq enlargement-tried t)
          (go another-one))
    (if (wleq (moreheap heapenlarge*) 0)
        (continuableerror 99 "Heap space low" nil)
        (when *gc
            (Errorprintf "*** Heap space has been enlarged by %w items"
                                heapenlarge* ) )
        (when *gc (gcstats))
    ))
 
  nil
  ))
 
(de moreheap (incr) (alterheapsize (times2 incr addressingunitsperitem)))
 
(de force-heap-enlargement() NIL) 

(if_system sel
(lap '((*entry current-stack-pointer expr 0)
       (*move (reg 0) (reg t1))
       (*move (fluid nil) (reg nil))% Save return address and set stack pointer
                    % as it will be after the return.
       (*move (reg st) (reg 1))
       (*jump (indexed(reg t1) 0))
       ))
 
(lap '((*entry current-stack-pointer expr 0)
       (*pop (reg 2))             % Save return address and set stack pointer
                  % as it will be after the return.
       (*move (reg st) (reg 1))
       (*push (reg 2))
       (*exit 0)
       ))
)
 
(de markandcopyfromid (x)
  % SymNam has to be copied before marking, since the mark destroys the tag
  % No problem since it's only a string, can't reference itself.
  (progn (copyitem (loc (symnam x)))
         (markid x)
         (copyitem (loc (symprp x)))
         (copyitem (loc (symget x)))
         (copyitem (loc (symval x)))))
 
(de copyfromallbases ()
 
  % Mark fixed ID's;  NIL first.
  (markandcopyfromid 128)
  (for (from i 0 127 1) (do (unless (markedid i) (markandcopyfromid i))))
  (for (from i 129 255 1) (do (unless (markedid i) (markandcopyfromid i))))
 
  % Mark other IDs.
  (for (from i 0 hash-table-size 1)
       (do
    (let ((id-number  (hash-table-entry i)))
      (when (and (> id-number 0)     % Slot is occupied
	         (not (= id-number deleted-slot-value)) % skip symbols removed from oblist
                 (not (markedid id-number)))
        (markandcopyfromid id-number)
        ))))
 
  % Mark from binding stack.
  (for (for b (adjustbndstkptr bndstklowerbound 1) (adjustbndstkptr b 1))
       (while (wleq b bndstkptr))
       (do (copyitem b))
       )
 
  (CopyFromStack)
  (CopyFromStaticHeap))
 
(de copyfromstack nil
   (prog (tg x info tg2 tg3 NullSize Size)
     (setq NullSize (Inf -1 ))    % The size of a null vector.
     (for (from i (wshift stacklowerbound 5) stacklast
        (times stackdirection addressingunitsperitem))
       (do
        (setq x (getmem i))
        (setq tg (tag x))
        (setq info (inf x))
    (if (weq tg id-tag)
        (when (and (wlessp info maxsymbols)
               (not (markedid info)))
          (markandcopyfromid info))
      (if (and (withinoldheappointer info) (pointertagp tg))
        (progn
        (setq tg2 (tag (getmem info)))
        (if (weq tg2 forward-tag)
          (setf (getmem i) (mkitem tg (inf (getmem info))))
          (setq Size (Inf (getmem info)))
          (case tg
            ((fixnum-tag floatnum-tag words-tag)
             (if (and (eq tg2 hwords-tag)
                  (or (eq Size NullSize)
                      (wleq (+ info (* Size
                           addressingunitsperitem))
                        oldheaplast)))
               (copyitem i)
               (cfserror "words/fixnum/float" x)
               ))
            ((string-tag bytes-tag)
             (if (and (eq tg2 hbytes-tag)
                  (or (eq Size NullSize)
                      (wleq (+ info Size) oldheaplast)))
               (copyitem i)
               (cfserror "string" x)
               ))
            ((halfwords-tag)
             (if (and (eq tg2 hhalfwords-tag)
                  (or (eq Size NullSize)
                      (wleq (+ info (* Size 2))
                        oldheaplast)))
               (copyitem i)
               (cfserror "halfword" x)
               ))
            ((bignum-tag)
                (if (and (or (eq tg2 hwords-tag) (eq tg2 hvect-tag))
                  (or (eq Size NullSize)
                      (wleq (+ info (* Size addressingunitsperitem))
                        oldheaplast)))
               (copyitem i)
               (cfserror "bignum" x)
               ))
            (( vector-tag evector-tag)
             (if (and (eq tg2 hvect-tag)
                  (or (eq Size NullSize)
                      (wleq (+ info (* Size
                               addressingunitsperitem))
                        oldheaplast)))
               (copyitem i)
               (cfserror "(e)vector" x)
               ))
            ((pair-tag)
             (if (itemtagp tg2)
               (progn
                   (setq tg3 (tag
                      (getmem
                       (wplus2 info
                           addressingunitsperitem))))
                   (when (itemtagp tg3)
                     (copyitem i)))
               (cfserror "pair" x)))
            (nil (cfserror "nil" x)))
          ))))))))
 
(de cfserror (where stackitem)
   (prog (info hinfo htag outputbase*)
     (setq outputbase* 16)
     (setq info (inf stackitem))
     (setq hinfo (getmem info))
     (setq htag (tag hinfo))
     (setq hinfo (inf hinfo))
     (printf
          "CopyFromStack error in %w, stackitem %w heaptag %w heapinf %w%n"
                 where (inf stackitem) htag hinfo)))
 
(de CopyFromStaticHeap nil
(prog (B Size NullSize)
    (setq NullSize (Inf -1 ))    % The size of a null vector.
    (setq B StaticHeapBase)
    (while (wlessp B StaticHeapUpperBound)
    (progn (setq Size (Inf (getmem B)))
    (case (Tag (getmem B))
    ((hwords-tag)
    (progn (cond ((equal Size NullSize)
          (setq Size -1)))
        (setq B (wplus2 B (<< Size 2) 8))))
    ((hbytes-tag)
    (progn (cond ((equal Size NullSize)
          (setq Size -1)))
        (setq B (wplus2 B (<< (>> (wplus2 Size 5) 2) 2) 4))))
    ((hhalfwords-tag)
    (progn (cond ((equal Size NullSize)
          (setq Size -1)))
        (setq B (wplus2 B (<< (>> (wplus2 Size 2) 1) 2) 4))))
    ((hvect-tag)
    (progn (cond ((equal Size NullSize)
          (setq Size -1)))
        (setq B (wplus2 B 4))
        (for (from N 0 Size 1) (do
        (progn (CopyItem B)
         (setq B (wplus2 B 4)))))))
    (nil
    (progn (CopyItem B)
        (setq B (wplus2 B 4))
        (cond ((getmem B) (CopyItem B)))
        (setq B (wplus2 B 4)))))))))
 
(de copyfromrange (lo hi)
  (prog (x i)
        (setq x lo)
        (setq i 0)
        (while (wleq x hi)
          (copyfrombase x)
          (setq i (wplus2 i 1))
          (setq x (loc (wgetv lo i))))))
 
(de copyfrombase (p)
  % P is an "address"
  (copyitem p))
 
(de copyitem (p)
  % COPYITEM is executed for SIDE-EFFECT--its return value is not likely to
  % be meaningful and should be ignored!
  (prog (typ info hdr x)
    (cond ((null (setq x (getmem p))) (return nil)))
        (setq typ (tag x))
        (unless (pointertagp typ)
          (return
         (progn (cond ((weq typ id-tag)
                   (progn (setq info (idinf x))
                      (unless (markedid info)
                          (markandcopyfromid info))))))
    ))
        % else it is a PointerType
        (setq info (inf x))
        (unless (withinoldheappointer info)
          (return x))
        (setq hdr (getmem info))
        (when (marked hdr)
          (return (setf (getmem p) (mkitem typ (inf hdr)))))
        (return (copyitem1 p x hdr))))
 
(de copypairitem (p x)
  % COPYITEM is executed for SIDE-EFFECT--its return value is not likely to
  % be meaningful and should be ignored!
%(unixputn p) (console-print-string " ") (unixputn x) (console-newline)
  (prog (typ info hdr )
    (cond ((null x) (return nil)))
        (setq typ (tag x))
        (unless (pointertagp typ)
          (return
         (progn (cond ((weq typ id-tag)
                   (progn (setq info (idinf x))
                      (unless (markedid info) (markandcopyfromid info))))))
    ))
        % else it is a PointerType
        (setq info (inf x))
        (unless (withinoldheappointer info) (return x))
        (setq hdr (getmem info))
        (when (marked hdr) (return (setf (getmem p) (mkitem typ (inf hdr)))))
        (return (copyitem1 p x hdr))))

(de copyitem1 (p s memos)
  % Copier for GC
  % COPYITEM1 is executed for SIDE-EFFECT--its return value is not likely to
  % be meaningful and should be ignored!
  (prog (news len ptr strips tg cdrs)
        (return (case (setq tg (tag s))
                      ((pair-tag)
                       (progn (setq ptr memos)
                              % Save car which is about to be
                              % replaced by MARK and new address
                              (rplaca s
%                              (mark (setq news (gtheap (pairpack)))))
			       (mark (prog1 (setq news heaplast)
                                      (setq heaplast 
                                       (wplus2 heaplast
                                        (wtimes2 2 addressingunitsperitem))))))
                              (setf (getmem p) (mkpair news))
                              (setf (wgetv news 0) ptr)
                              (setf (wgetv news 1) (setq cdrs (cdr s)))
                              (copypairitem (loc (wgetv news 0)) ptr)
                              (return 
                                  (copypairitem (loc (wgetv news 1)) cdrs))))
                      ((bytes-tag)
                       (progn (setf (getmem (strinf s))
                               (mark (setq news (copybytes s))))
                              (return (setf (getmem p) news))))
                      ((string-tag)
                       (progn (setf (getmem (strinf s))
                               (mark (setq news (copystring s))))
                              (return (setf (getmem p) news))))
              ((floatnum-tag)
               (progn (setf ptr (inf s))
                  (setf (getmem ptr)
                    (mark (setq news (gtfltn))))
                              (setf (wgetv news 1) (wgetv ptr 1))
                  (setf (wgetv news 2) (wgetv ptr 2))
                  (return
                   (setf (getmem p) (mkitem floatnum-tag news)))))
                      ((vector-tag evector-tag)
                       (progn (setq strips (vecinf s))
                              (setq len (veclen strips))
                              (setf (getmem strips)
                               (mark (setq ptr (gtvect len))))
                              (for (from i 0 len 1)
                               (do
                                (progn (setf (vecitm ptr i)
                                        (vecitm strips i))
                                       (copyitem (loc (vecitm ptr i))))))
                              (return (setf (getmem p)  (mkitem tg ptr)))))
                      ((words-tag fixnum-tag bignum-tag)
                       (progn (setf (getmem (inf s))
                               (mark (setq news (copywrds s))))
                              (return (setf (getmem p) (mkitem tg news)))))
%                      ((bignum-tag)
%                       (progn (setf (getmem (inf s))
%                               (mark (setq news (copyvector s))))
%                              (return (setf (getmem p) (mkitem tg news)))))
                      ((halfwords-tag)
                       (progn (setf (getmem (inf s))
        		           (mark (setq news (copyhalfwords s))))
                              (return (setf (getmem p)
                        (mkitem halfwords-tag news)))))
                      (nil
                       (fatalerror
                        (bldmsg
                       "Unexpected tag %w found at %w during garbage collection"
                         (mkint (tag s)) (mkint (inf s)))))))))
 
(de makeidfreelist ()
  (prog (previous)
        (for (from i 0 128 1) (do (clearidmark i)))
        (setq previous 129)
        (while (and (markedid previous) (< previous maxsymbols))
          (clearidmark previous)
          (setq previous (+ previous 1)))
        (if (< previous maxsymbols)
          (setq nextsymbol previous)
          (setq nextsymbol 0))
        (for % free list starts here
              (from i (+ previous 1) maxsymbols 1)
              (do (if (markedid i)
                    (clearidmark i)
                    (progn (setf (symnam previous) i)
                           (setq previous i)))))
        (setf (symnam previous) 0)))
 
% end of free list
(commentoutcode
(de gcstats ()
  (errorprintf "*** GC %w: time %d ms, %d recovered, %d free" gcknt*
               oldtime
               (wquotient
                (wdifference oldsize (wdifference heaplast heaplowerbound))
                addressingunitsperitem)
               (known-free-space)))
)
(de gcstats ()
  (if (wgeq (known-free-space) 100)
      (if (wgeq (sys2int(timc)) 3600000) % 1 hour -> float
             (Errorprintf "*** GC %w: %w (~ %w h cpu time, gc : %w %%)"
                      gcknt* (date-and-time)
			     (quotient (sys2int (timc)) 3600000.0)
                             (wquotient (wtimes2 100 gctime*)
                                 (wplus2 1 (timc))))
             (Errorprintf "*** GC %w: %w (~ %w ms cpu time, gc : %w %%)"
                        gcknt* (date-and-time) (sys2int(timc))
                               (wquotient (wtimes2 100 gctime*)
			       (wplus2 1 (timc)))))
      (Errorprintf "*** GC %w: Heap space exhausted" gcknt*))
  (Errorprintf "*** time %d ms, %d occupied, %d recovered, %d free"
     oldtime
     (wquotient (wdifference heaplast heaplowerbound) addressingunitsperitem)
     (if (wlessp (wdifference oldsize (wdifference heaplast heaplowerbound)) 0)
         0
         (wquotient (wdifference oldsize (wdifference heaplast heaplowerbound))
                    addressingunitsperitem))
     (known-free-space)))


(de set!-heap!-size (items) 
   (prog (actual heap-warn-level heapenlarge*) 
       (setq actual (wdifference heapupperbound heaplowerbound)) 
       (setq actual (wquotient actual 8)) 
       (when (null items) (return actual))
       (when (wgreaterp actual items) 
          (print "Cannot shrink heap") (return nil)) 
       (setq heapenlarge* (difference items actual)) 
       (setq heap-warn-level actual) 
       (when (pairp (errorset '(!%reclaim) NIL NIL)) (return items))
       (return nil))) 

