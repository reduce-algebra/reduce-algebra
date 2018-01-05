(fluid '(*heap-compacting*))

(compiletime
(put 'nonassocpat 'pattern
     '(nil ('!*destroy '(reg 3)) 
	   ('!*set dest (fn a1 a2)) ((dest any) (mac a1 a2))
	   ((any usesdest) ('!*load t1 a2) ('!*load dest a1) (mac dest t1))
	   (any ('!*load dest a1) (mac dest a2))))
 
)



(compiletime (load inum hash-decls if-system))

(on fast-integers)

(global '(heaptrapped))

(de get-heap-trap (pointer number-of-items)

  % An attempt has been made to allocate NUMBER-OF-ITEMS from the heap, and
  % the HEAPTRAPBOUND was exceeded.  POINTER is the value that would have been
  % returned if the trap bound had not been passed.  The HEAPTRAPPED flag is used
  % to control the 2 levels of GC calls. 

     (setf heaplast (wdifference heaplast (wtimes2 number-of-items
						   addressingunitsperitem)))
     (if heaptrapped (!%compactheap) (!%reclaim number-of-items))
     (setf pointer heaplast)
     (setf heaplast (wplus2 heaplast (wtimes2 number-of-items
						   addressingunitsperitem)))
     (cond ((wlessp heaplast heaptrapbound)
	      (setf heaptrapped nil) 
	      pointer)
	   (*heap-compacting* nil)
	   (heaptrapped 
	      (when *dump (prin2 "**** request:")(prin2t number-of-items)
			  (stderror "heap trap hit"))
	      (stderror "heap space low"))
	   (t (setf heaptrapped t)
	      (get-heap-trap pointer number-of-items))))

	       
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PNK:STATIC-GC.SL
% Title:          Non moving garbage collector for PSL
% Author:         Herbert Melenk               
% Created:        11 March 1990
% Status:         Experimental
% Mode:           Lisp
% Package:        Kernel
%
% (c) Copyright 1990, Konrad-Zuse-Zentrum Berlin
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
(fluid '(*gc % Controls printing of statistics
	 gctime* % Total amount of time spent in GC
	 gcknt* % count of # of GC's since system build
	 gctrace* % diagnosis for GC
	 heap-warn-level
	 *heap-compacting*    % flag, that compaction is ongoing
	 *page                % flag for page mode output (is
			      % heap consuming and therefore turned off)
	 kernel-maxsymbols old_symval
	 gcfunction* olditem*  
	 gcfree* gcoccupied* *moving-heap*
	 onewordbuffer symget))
 
% Continuable - if this much not
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
(global '(heaptrapped heaplast heapupperbound heaplowerbound heaptrapbound))
 
% Boolean: has trap occurred since GC?
(compiletime
  (progn 
   
     (flag '(close-slot skip-slot look-for-slot  cleargcarray
		 !%reclaim1 !%reclaim2  
		 markfromallbases markfromsymbols markfromonesymbol
		 markfromstack markfrombase markfromvector makeidfreelist
		 TSmark buildsegments fehler
		 gcerror gcmessage illegal-item centerdump
		 !%compactheap object-size move-items 
		 update-bases update-stack update-vector update-pair
		 % do not enter update-item (needs to be redfined sometimes)
		 update-symbols update-onesymbol update-heap  
		 length-of-free-segment trailingzeros trailingzeros-16 
		 trailingzeros-8
		 trailingzeros-4)
		'internalfunction)

     (ds pointertagp (x)
	 (wgeq (wor (- x (wplus2 posint-tag 1)) (- (wplus2 code-tag -1) x)) 0))

     (ds withinheappointer (x)
	 (and (wgeq (inf x) (inf heaplowerbound))
		(wleq (inf x) (inf heapupperbound))))

     (ds mark (x)
	(let* ((y (wquotient (wdifference (inf x) (inf heaplowerbound))
			     addressingunitsperitem))
	       (z (wrshift y 5)))
	    (wand 1
	      (wrshift 
		   (wgetv wgcarray* z)   
		   (wand y 31)))))
   
     (ds setmark (x) 
	(let* ((y (wquotient (wdifference x (inf heaplowerbound) )
			     addressingunitsperitem))
	       (z (wrshift y 5)))
	    (setf (wgetv wgcarray* z) 
		  (wor (wgetv wgcarray* z) 
		       (wlshift 1 (wand y 31)))))) 
   
     (ds marked (x) (weq (mark x) 1))
 
     (ds testAndSetMark (x) (weq (TSmark x) 0))

     (ds markid (x)
	  (setf (field (symnam x) tagstartingbit tagbitlength) forward-tag))

     (ds markedid (x) (weq (tag (symnam x)) forward-tag))

     (ds clearidmark (x)
	  (setf (field (symnam x) tagstartingbit tagbitlength) string-tag))

    nil))
 
(commentoutcode
      % some tools for debugging
   (de xmark (x) (mark x))
   (de ymark (x) 
       (let* ((y (wquotient (wdifference x heaplowerbound)
			     addressingunitsperitem))
	       (z (wplus2 wgcarray* (wlshift (wrshift y 5) 2))))
	(console-print-string "in gcarray: ") (unixputn z)
	(console-print-string " -> ")(unixputn (getmem z))
	(console-print-string " bit ")(unixputn (wand y 31))
	(console-newline)
	    (wand 1
	      (wrshift
		   (getmem  z)
		   (wand y 31)))))
   (de xsetmark (x) (setmark x))
   (de xmarkedid (x) (markedid x))
)

(fluid '(gcarray* wgcarray* gcarraysize* gcchainanchor*))
 
(de init-gcarray()
   % the gcarray is placed in the heap such that its size can be
   % modified
    (setq gcarraysize*
	   (wplus2
		 (wquotient
		      (wquotient (wdifference heapupperbound heaplowerbound)
				addressingunitsperitem)
		      bitsperword)
		      2))
    (setq gcarray* (make-words gcarraysize*))
    (setq wgcarray* (wplus2 (inf gcarray*) addressingunitsperitem))
    )

(de TSmark (x)
    % test-and-set mark
    % returns 0 if the mark was set before
    (let* ((y (wrshift (wdifference x (inf heaplowerbound)) 2)) % (x-low)/4
	   (z (wplus2 wgcarray* (wlshift (wrshift y 5)2))) % (y/32)*4
	   (w (getmem z)))
	(setq y (wor w (wlshift 1 (wand y 31))))
	(putmem z y)
	(wxor w y)))

(loadtime
  (when (or (unboundp 'gcchainanchor*)
	    (null gcchainanchor*))
   (progn
    (init-gcarray)
    (setq gcchainanchor* (gtwarray 3)) 
    (wputv gcchainanchor* 0 0)
    (wputv gcchainanchor* 1 0)
    (wputv gcchainanchor* 2 0)
)))

(global '(stacklowerbound ))
 
(de cleargcarray()
    (ifor (from i 0 gcarraysize* 1)
	  (do (wputv wgcarray* i 0))))

(global '(nextsymbol))
 
% next ID number to be allocated
(global '(bndstkptr bndstklowerbound))
 
 
(fluid '(heapshrink hole marktag stackstart stackend))
 
% management of slot pointers
 
(compiletime 

  (ds next-slot (slot)
       % the number of the word after the end of the slot
       (getmem (wplus2 slot addressingunitsperitem)))
 
  (ds slot-length (slot)
       (wtimes2 (wplus2 2 (inf (getmem slot))) addressingunitsperitem))
 
  (ds slot-header (x) (getmem x))
)
 
(de close-slot (start end)
	%close the slot, where start and end are the addresses
	% of first and last word
   (when (and (wgreaterp start 0)(wleq start end)) 
    (putmem start (mkitem hwords-tag
		   (wdifference (wquotient (wdifference end start)
					    addressingunitsperitem)
				1)))))

(de skip-slot ()
  % proceed to next slot (if exists)
    (let ((x (wgetv gcchainanchor* 1)))
	 (close-slot heaplast (wdifference heaptrapbound 
					    addressingunitsperitem))
	 (cond((eq x 0) (setq heaplast heapupperbound)
			nil)
	       (t (setq heaplast x)
		  (setq heaptrapbound(wplus2 x (slot-length x)))
		  (setf (wgetv gcchainanchor* 1) (next-slot x))
			x))))
	 
(de look-for-slot (n)
  % look for a slot of size >=n
    (cond ((wlessp (wplus2 heaplast (wtimes2 n addressingunitsperitem))
		   heaptrapbound) t)
	   ((skip-slot) (look-for-slot n))
	   (t nil)))
 
(de reclaim ()
  %. User call to garbage collector
   (close-slot heaplast (wdifference heaptrapbound addressingunitsperitem)) 
   (!%reclaim2 nil) 
    nil)

(de !%reclaim (n) 
  %. internal  from heap management
   % standard entry: get next segment of free storage
   (or (look-for-slot n) (!%reclaim1 n)))
 
(de !%reclaim1(n)
  % internal call, when no more heap space avaliable
  (when (not *heap-compacting*)
    (!%reclaim2 n)
	% compact heap every 16th call
    (when (or (weq 0 (wand gcknt* 15)) 
	      (and n (null (look-for-slot n)))) 
	  (!%compactheap))
    (when (and n (null (look-for-slot n)))
	 (when *dump (prin2 "**** requested size:") (prin2t n))
	 (stderror "heap space low")) 
    ))

(de !%reclaim2(n)
  % Garbage collector main driver
  (prog(startingrealtime startingrealtime2 *page)
	 %%% (! yield)   % handle terminal interrupts now!
	 (setq wgcarray* (wplus2 (inf gcarray*) addressingunitsperitem))
	 (setq stackend
	   (makeaddressfromstackpointer
	    (adjuststackpointer (current-stack-pointer) (wminus (framesize)))))
	 (setq stackstart (wshift stacklowerbound 5))

	 (beforegcsystemhook)
	 (when *gc
	   (errorprintf "*** Garbage collection starting "))
	 (setq startingrealtime (timc))
	 (setq startingrealtime2 (wshift startingrealtime -16))
	 (setq startingrealtime (wshift (wshift startingrealtime 16) -16))
	 (setf gcknt* (wplus2 gcknt* 1))
	 (cleargcarray)
	 % must be INUM > 0, so needn't chk
	 (markfromallbases)
	 (makeidfreelist)
	 (buildsegments)
	 (setq heaplast (wgetv gcchainanchor* 1))
	 (when gctrace*
	       (printgcchain)
	       (console-print-string " new heaplast: ")
	       (unixputn heaplast) (console-newline)
	 )
	 (setq heaptrapbound
	      (if (not (= heaplast 0)) 
		  (wplus2 heaplast 
			  (wtimes2 (wplus2 2(inf (getmem heaplast)))
				   addressingunitsperitem))
		  0))
	 (wputv gcchainanchor* 1 (getmem (wplus2 heaplast 
						 addressingunitsperitem)))
	 
	 % reconstruct
	 (setq startingrealtime 
	   (wor (wshift startingrealtime2 16)
		startingrealtime))
	 
	 (setq startingrealtime 
	     (wdifference (timc) startingrealtime))
	 %%% (setq startingrealtime (times 10 startingrealtime))
	 (setf gctime* (wplus2 gctime* startingrealtime))

	 (when *gc (gcmessage startingrealtime))
	 (setq heaptrapped nil)
	 (when (wlessp (intinf gcfree*) (intinf heap-warn-level))
	   (when *dump (stderror "below heapwarnlevel"))
	   (stderror "heap space low"))
         (aftergcsystemhook)
	 nil))

(de printgcchain()
    (prog (x y)
       (setq x (wgetv gcchainanchor* 1))
       (console-print-string "free memory block chain : ")
       (console-newline)
loop
       (unixputn x)
       (when (eq x 0)
	      (console-newline)
	       (return nil))
       (console-print-string " :")
       (unixputn (getmem x))
       (console-print-string " :")
       (unixputn (getmem (wplus2 x 4)))
       (console-print-string " ? ")
       (setq y (inf (getmem x)))
       (setq y (wplus2 (wtimes2 y 4) x))
       (unixputn (getmem y))
	(console-print-string " :")
       (unixputn (getmem (wplus2 y 4)))
       (console-print-string " :")
       (unixputn (getmem (wplus2 y 8)))
       (console-newline)
       (setq x (getmem (wplus2 x 4)))
       (go loop) ))
   
(de markfromallbases ()
  (prog (b)
	(markfromonesymbol 128)    % NIL first
	(markfromstack)
	(setq b bndstklowerbound)
	(while (progn (setq b (adjustbndstkptr b 1))
		      (wleq b bndstkptr))
	  (markfrombase (getmem b)))
	(markfromsymbols)
))
 

(de markfromsymbols ()
  (prog (b)
	(ifor (from i 0 127 1)
	      (do (unless (markedid i)
		    (markfromonesymbol i))))
	
	(ifor (from i 129 255 1)
	      (do (unless (markedid i)
		    (markfromonesymbol i))))

	(ifor (from i 0  hash-table-size 1)
	      (do 
		 (let ((id  (hash-table-entry i)))
		    (when (and (> id 0)     % Slot is occupied
			       (not (markedid id)))
			  (markfromonesymbol  id)
	    ))))))

(de markfromonesymbol (x)
  % SymNam has to be marked from before marking ID, since the mark uses its tag
	 (setq gcfunction* 1)
	 (markfrombase (symnam x))
	 (setq gcfunction* 2)
	 (markid x)
	 (setq gcfunction* 3)
	 (markfrombase (symprp x))
	 (when symget (markfrombase (symget x)))
	 (setq gcfunction* 4)
	 (when (not (memq (int2id x)
			'(heaplowerbound heaplast
			olditem*
			heaptrapbound heapupperbound)))
	       (if (wgreaterp x kernel-maxsymbols)
		 (markfrombase (symval x))
		 (markfrombase (wgetv old_symval x))))
	 (setq gcfunction* 0)    
      )
 
(de markfromstack ()
  (setq gcfunction* 5)
  (ifor (from ptr stackstart stackend 
		  (wtimes2 addressingunitsperitem stackdirection)) 
	(do 
	  (progn  %% (unixputn (*get-stack ptr))(console-newline)
		  (markfrombase (*get-stack ptr))))))
 
(de markfrombase (base)
  (prog (markinfo 
	 %%%  olditem*
	)
	 %%% (SETQ OLDITEM* (INF BASE))
	(setq marktag (tag base))
	(unless (pointertagp marktag)
	  (return (progn (when (and (weq marktag id-tag) (not (null base)))
			   (setq markinfo (idinf base))
			   (unless (markedid markinfo) 
				   (markfromonesymbol markinfo)))
	)))
	
	(setq markinfo (inf base))
	
	(when (not (withinheappointer markinfo)) (return nil)) 
	
	(when (not (eq 0 (wand markinfo 3)))
	      (console-print-string "##### odd pointer found ") 
	      (unixputn base)(console-newline)
	      (prin2 " function ")(prin2t gcfunction*)   
	     )
	
	(when (testAndSetMark markinfo) (return nil))
 
%       (when (wlessp (current-stack-pointer) stackupperbound)
%             (errorprintf "****** stack overflow during GC; cannot recover")
%             (exitlisp))
	(cond ((or (weq marktag  vector-tag) (weq marktag evector-tag))
		   (return (markfromvector markinfo)))
	      ((weq marktag pair-tag)
		   (setq gcfunction* 8)    
		   (markfrombase (car base)) 
		   (return (markfrombase (cdr base))))
      %%        ((and (weq marktag bignum-tag)
      %%             (not (weq (tag(getmem (inf base))) hwords-tag)) )
      %%         (console-print-string "#### illegal pointer ")
      %%         (unixputn base)
      %%         (console-newline)
      %%         (illegal-item (inf base) 255)
      %%         (exitlisp) )
	)))
 
(de markfromvector (info)
  (prog (uplim)
	(setq gcfunction* 7)    
	(setq uplim (loc (vecitm info (veclen info))))
	(ifor (from ptr (loc (vecitm info 0)) uplim addressingunitsperitem)
	      (do (markfrombase (getmem ptr))))))
 
(de makeidfreelist ()
  (prog (previous)
	(ifor (from i 0 128 1) (do (clearidmark i)))
	(setq previous 129)
	(while (and (markedid previous) (wleq previous maxsymbols))
	  (clearidmark previous)
	  (setq previous (wplus2 previous 1)))
	(if (wgeq previous  maxsymbols)
	  (setq nextsymbol 0)
	  (setq nextsymbol previous))
	(ifor % free list starts here
 
	      (from i (wplus2 previous 1)  maxsymbols 1)
	      (do (if (markedid i)
		    (clearidmark i)
		    (progn
			   (setf (symnam previous) i)
			   (setq previous i)))))
	(setf (symnam previous) 0)))
 

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
       (*move (reg st) (reg 1))
%      (*wplus2 (reg 1) 20) % a "magic" offset
       (*exit 0)
       ))
)
 
  %
  %        Pass 2 - Build SEGMENTS
  %


(de trailingzeros (w)
   % count the number of trailing zeros in the 32-bit-word w
   (cond ((weq w 0) 32)
	 ((weq w (wand w 16#ffff0000)) (trailingzeros-16 (wrshift w 16) 16))
	 (t (trailingzeros-16 w 0))))

(de trailingzeros-16(w n)
   (cond ((weq w (wand w 16#ffffff00)) (trailingzeros-8 (wrshift w 8) (wplus2 n 8)))
	 (t (trailingzeros-8 w n))))

(de trailingzeros-8(w n)
   (cond ((weq w (wand w 16#fffffff0)) (trailingzeros-4(wrshift w 4) (wplus2 n 4)))
	 (t (trailingzeros-4 w n))))

(de trailingzeros-4(w n)
   (wplus2 n
      (cond ((weq w (wor 16#1 w)) 0)
	    ((weq w (wor 16#2 w)) 1)
	    ((weq w (wor 16#4 w)) 2)
	    (t                    3))))

(de length-of-free-segment(x)
   % calculate the length of the free segment beginning at x
   % by inspecting the mark bit table
    (let* ((y (wrshift (wdifference x heaplowerbound) 2)) % (x-low)/4
	   (z (wplus2 wgcarray* (wlshift (wrshift y 5)2))) % (y/32)*4
	   (o (wplus2 wgcarray* (wlshift gcarraysize* 2)))
	   (w (getmem z))
	   (b (wand y 31))                                % bit number
	   n                                              % aux
	   )
	    % mask out the part below x
      (setq w (wlshift (wrshift w b) b))
	    % and initialize counter
      (setq b (wminus b))
      (setq n 32)
      (while (and (weq n 32) (wlessp z o))
	    (setq n (trailingzeros w))
	    (setq b (wplus2 b n))
	    (setq z (wplus2 z addressingunitsperitem))
	    (setq w (getmem z)))
       b))



(de buildsegments ()
  (prog (currentitem hole-start hole-length old-hole seglen last 
	  %% olditem*
	)
	(setq currentitem heaplowerbound)
	(setq old-hole gcchainanchor*)
	(setq gcfree* 0 gcoccupied* 0)
	(wputv gcchainanchor* 0 0)
	(wputv gcchainanchor* 1 0) 
	(wputv gcchainanchor* 2 heapupperbound)
	(setq gcfunction* 6)
   loop
	(when (wgeq currentitem heapupperbound) (go finis))
	(when (marked currentitem)
	    (setq seglen
		(case (tag (getmem currentitem))
		  ((code-tag negint-tag posint-tag id-tag unbound-tag
		    string-tag  bytes-tag fixnum-tag
		    floatnum-tag bignum-tag words-tag
		    halfwords-tag pair-tag vector-tag evector-tag) 2)
		  ((hbytes-tag)
			(wplus2 1 (strpack (strlen currentitem))))
		  ((hhalfwords-tag)
			(wplus2 1 (halfwordpack (strlen currentitem))))
		  ((hwords-tag)
			(wplus2 1 (wrdpack (wrdlen currentitem))))
		  ((hvect-tag)
			(wplus2 1 (vectpack (veclen currentitem))))
		  (nil (illegal-item currentitem 1))  ))

	    (setq gcoccupied* (wplus2 gcoccupied* seglen))
	    (setq olditem* currentitem)
	    (setq currentitem
		(wplus2 currentitem
			   (wtimes2 seglen addressingunitsperitem)))
	     (go loop)
	 )
	  % free segment
	 (setq hole-start currentitem)
	 (setq seglen (length-of-free-segment currentitem))
	 (setq olditem* currentitem) 
	 (setq currentitem (wplus2 currentitem 
			   (wtimes2 seglen addressingunitsperitem)))
	 (when (wgreaterp currentitem heapupperbound)  % overshot??
	       (wputv gcchainanchor* 2 hole-start)    % last hole
	       (setq seglen 
		     (wquotient 
			(wdifference heapupperbound hole-start) 
			 addressingunitsperitem))
	       )
	 (setq hole-length seglen)
	 (setf(slot-header hole-start) 
	      (mkitem hwords-tag (wdifference hole-length 2)))
	 (when(wgreaterp hole-length 1)
				% link to free block chain
	      (setq gcfree* (wplus2 gcfree* hole-length))
	      (setf (next-slot old-hole) hole-start)
	      (when gctrace*
		    (ifor (from i 1 (isub1 hole-length) 1)
		        (do
			 (when (marked(plus hole-start 
				       (wtimes2 4 i)))
			     (fehler hole-start hole-length 
				     (plus hole-start  (wtimes2 4 i)))
		    )))
		    (ifor
		      (from i 1 (isub1 hole-length) 1)
		      (do
			 (putmem (plus hole-start (wtimes2 4 i)) -1)
		    ))
	       )
	  (setq old-hole hole-start))
	  (go loop)
 finis
		    % finish free memory chain
	  (setf (next-slot old-hole) 0)
    ))

(de fehler (a l pos)
    (console-print-string "************** GC Catastrophy at ")
    (unixputn pos) (console-newline)
    (setq a (inf a))
     (ifor 
	  (from i 0 l 4)
	  (do (progn
	       (unixputn (wplus2 a (wtimes2 i 4)))
	      (console-print-string ": ")
	      (unixputn (getmem (wplus2 a (wtimes2 i 4))))
	      (console-print-string " ")
	      (unixputn (getmem (wplus2 a (wtimes2 (wplus2 i 1) 4))))
	      (console-print-string " ")
	      (unixputn (getmem (wplus2 a (wtimes2 (wplus2 i 2) 4))))
	      (console-print-string " ")
	      (unixputn (getmem (wplus2 a (wtimes2 (wplus2 i 3) 4))))
	      (console-print-string " ")
	      (console-newline)
	      (when (wgreaterp (wplus2 a (wtimes2 i 4)) pos)
		    (exitlisp))
	   ))) 
    (gcerror "unexpected mark found at " pos)
  )


(de gcerror (message p)
  (errorprintf "***** Fatal error during garbage collection")
  (errorprintf message p)
  (while t
    (quit))
  nil)
 
(de gcmessage (startingrealtime)
  (let ((tim (time)) 
        (da (date-and-time) ))
   (setq tim (if (wgreaterp tim 100) (wquotient gctime* (wquotient tim 100)) 0))
  (errorprintf "*** GC %d %w, %d ms (%d%%), %d occupied, %d free" 
		gcknt* da startingrealtime tim 
		(intinf gcoccupied*) (intinf gcfree*) )))
 
(de illegal-item (x c)
  (prog(f file)
   (prin2t "**** Illegal item in heap **** ")
   (centerdump (inf x) 30)
   (setq outputbase* 16)
   (prin2 "**** Illegal item in heap case ")
   (prin2 c) (prin2 " function ")(prin2 gcfunction*) (prin2 " at ")
   (prin2 x)
   (prin2 " tag: ") (prin2 (tag (getmem x)))
   (prin2 " inf: ") (prin2 (inf (getmem x)))
   (when olditem*
      (prin2 "from ")(prin2t olditem*)
      (centerdump (inf olditem!*)))
   (terpri)
   (backtrace)
  ))

(de centerdump (loc howmuch)
  (console-newline)
  (console-print-string "heaplowerbound/heapupperbound/heaplast: ")
    (unixputn heaplowerbound) (console-print-string " ") 
    (unixputn heapupperbound) (console-print-string " ")
    (unixputn heaplast)
  (console-newline)
  (console-print-string "**** Center dump at 16#")
  (unixputn loc)
  (console-newline)
  (console-newline)
  (for (from  i (minus howmuch) howmuch 8)
    (do (unixputn (wplus2 loc (wtimes2 4 i)))
	(console-print-string ":")
	(for (from j 0 7)
	  (do (unixputn (getmem (wplus2 loc (wtimes2 4 (wplus2 i j)))))
	      (console-print-string " ")))
	(console-newline))))
%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  PASS 3:
%
%  heap compaction (optinal/explicit call after garbage collection)
%

(de compactheap()
     (reclaim)
     (!%compactheap))

(de !%compactheap ()
  (let ((*moving-heap* nil)(tim (time)))
    (setq gcfunction* 16)
    (when *gc (errorprintf "*** Heap compaction starting%n"))
    %%(console-print-string "move-items")(console-newline)
    (setq stackend
	   (makeaddressfromstackpointer
	    (adjuststackpointer (current-stack-pointer) (wminus (framesize)))))

    (move-items)
    (setq gcfunction* 17)
    (update-bases)
    (setq gcfunction* 18)
    (setq heaptrapbound (wdifference heapupperbound addressingunitsperitem))
	 % now giving up the structures in the upper part
    (setf (wgetv gcchainanchor* 0) 0)
    (setf (wgetv gcchainanchor* 1) 0)
    (setf (wgetv gcchainanchor* 2) 0)
    (setq tim (wdifference (time) tim))
   (when *gc
    (errorprintf "*** Heap compacted to %d items (=%d%%) in %d ms%n" 
	   (wquotient (wdifference heaplast heaplowerbound)
		      addressingunitsperitem)
	   (wquotient (wtimes2 100 (wdifference heaplast heaplowerbound)) 
			   (wdifference heapupperbound heaplowerbound))
	   tim))
    (setq gctime* (wplus2 tim gctime*))
    heaplast))
 
(de object-size (x)
	 (when (not (withinheappointer x))
	       (illegal-item x 13))
	 (case (tag (getmem x))
	       ((code-tag negint-tag
		 posint-tag id-tag unbound-tag
		 string-tag  bytes-tag fixnum-tag
		 floatnum-tag bignum-tag words-tag
		 halfwords-tag pair-tag vector-tag
		 evector-tag)
		 2)
	       ((hbytes-tag) (wplus2 1 (strpack (strlen x))))
	       ((hhalfwords-tag) (wplus2 1 (halfwordpack (strlen x))))
	       ((hwords-tag) (wplus2 1 (wrdpack (wrdlen x))))
	       ((hvect-tag)     (wplus2 1 (vectpack (veclen x))))
	   %    ((forward-tag) -500)
	       (nil (illegal-item x 14)) ))

(de move-items()
   % from the end of heap downwards: copy marked structures to
   % lower part until heaplast passes the actual pointer
  (let*((act (wplus2 heapupperbound 100))
	(base gcarraysize*)
	(*heap-compacting* t)
	(bit -1)
	(continue t)
	(x heaplast)
	(y (wgetv gcchainanchor* 2))
	(lowest (if(wgreaterp y x) y x))
	 word l new)
   (while continue
	  % look for the next bit 
	(when (wlessp bit 0)
	     (setq word 0)
	     (while (weq word 0)
		    (setq base (isub1 base))
		    (setq word (wgetv wgcarray* base)))
	     (setq bit (isub1 bitsperword)))
	(when (weq 1 (wand 1 (wrshift word bit)))
		% bit 1 found; compute the word number and the heap address
	      (setq x (wplus2 (wlshift base 5) bit)) 
	      (setq act (wplus2 heaplowerbound 
				(wtimes2 x addressingunitsperitem)))
		% copy the object to the lower heap

	      (when (not (wgreaterp act heapupperbound))
	       (if (and
		    (setq l (object-size act))
		    (null (when (wlessp l 0) (illegal-item act 15)))
		    (setq x (wplus2 act (wtimes2 (isub1 l)
				    addressingunitsperitem)))
		    (setq new (gtheap l))
		    (wlessp new act))
		    % if the new slot is still below the current one
		 (progn 
                   (setq y new)
		   (ifor (from z act x addressingunitsperitem)
		     (do
		       (progn 
			      (setf (getmem y) (getmem z))
			      (setq y (wplus2 y addressingunitsperitem)))))
			   % mark the source for later update pass
		   (setq lowest act)
		   (setf (getmem act) (mkitem forward-tag new)))
		     % else stop the loop and give up the new slot
		 (progn
		    (skip-slot)
		    (setq continue nil)  
		    (setq heaplast 
		       (cond ((null new) (wplus2 x addressingunitsperitem))
			     ((wlessp new lowest) new) 
			     (t lowest)))
		 ))))
	(setq bit (isub1 bit)) )))
 
(de update-bases()
  (prog (b)
	 %%(console-print-string "update bases")(console-newline) 
	(update-symbols)
	%%(console-print-string "update stack")(console-newline) 
	(update-stack)
	%%(console-print-string "update bnd")(console-newline) 
	(setq b bndstklowerbound)
	(while (progn (setq b (adjustbndstkptr b 1))
		      (wleq b bndstkptr))
	  (update-item b))
	%%(console-print-string "update heap")(console-newline) 
	(update-heap)))

(de update-stack()
  (ifor (from ptr stackstart stackend
		  (wtimes2 addressingunitsperitem stackdirection))
	(do (progn         % temporary copy to data segment
		   (setf (wgetv onewordbuffer 0) (*get-stack ptr))
		   (update-item onewordbuffer)
		   (*put-stack ptr (wgetv onewordbuffer 0))
		   ))))
 
(de update-vector(base l) 
   (ifor (from i 1 (isub1 l) 1) 
	 (do (update-item (wplus2 base (wtimes2 i addressingunitsperitem))))))
 
(de update-pair(base)
       (update-item base) (update-item (wplus2 base addressingunitsperitem)))

(de update-item(a)
  (if *moving-heap*
      (update-item-move a)
      (update-item-compact a) ))

(de update-item-move(a)
    (let* ((m (getmem a))
	   (tag (tag m))
	   (ptr (inf m)) )
      (when (and (pointertagp tag) (wgeq ptr (inf heap))
				   (wleq ptr (inf heaplast)))
	    (setf (getmem a) (mkitem tag (wplus2 ptr *moving-heap*))) )))

(de update-item-compact(a)
    (let* ((m (getmem a))
	   (tag (tag m))
	   (ptr (inf m))
	   (x 0))
      (when (and (pointertagp tag)
		 (wgeq ptr (inf heaplast))
		 (wleq ptr (inf heapupperbound))
		 (weq forward-tag (tag (setq x (getmem ptr)))))
	    (setf (getmem a)
		  (mkitem tag (inf x)) ))))
 
(de update-symbols ()
  (prog (b)
	(ifor (from i 0  maxsymbols 1)
	      (do
		    (when (stringp (symnam i))     % Slot is occupied
			  (update-onesymbol  i))
	    ))))
 
(de update-onesymbol (x)
	 (update-item (loc (symnam x)))
	 (update-item (loc (symprp x)))
	 (when symget (update-item (loc (symget x))))
	 (when (not (memq (int2id x)
			'(heaplowerbound heaplast
			olditem*
			heaptrapbound heapupperbound)))
	  (if (wgreaterp x kernel-maxsymbols)
		 (update-item (loc (symval x)))
		 (update-item (loc (wgetv old_symval x))))))

(de update-heap ()
  (prog (currentitem seglen)
	(setq currentitem heaplowerbound)
	(while (wlessp currentitem heaplast)
	       (setq seglen (object-size currentitem))
	       (case (tag (getmem currentitem))
		     ((code-tag negint-tag
		       posint-tag id-tag unbound-tag
		       string-tag  bytes-tag fixnum-tag
		       floatnum-tag bignum-tag words-tag
		       halfwords-tag pair-tag vector-tag
		       evector-tag)
			(update-pair currentitem))
		       ((hvect-tag)
			(update-vector currentitem seglen))
		       (nil nil))
	       (setq currentitem(wplus2 currentitem 
					(wtimes2 seglen addressingunitsperitem))) )))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  dynamic bps management
%
 
% special case: if the upper part of bps is free (no warrays there), the
% remaining part of bps can be unified with the fresh part

(de set-bps-size (n) (try-other-bps-spaces n))

(de try-other-bps-spaces (number-of-items)
    (let*((*moving-heap* nil)
	  (bpsrest (wquotient (wdifference lastbps nextbps) 
		   addressingunitsperitem))
	  (amount (wtimes2 25000 
			   (iadd1 (wquotient number-of-items 25000)))))
	 (if (wgreaterp bpsrest amount)
	     bpsrest
	   (errorprintf "*** enlarging fasl space by %d items" amount)
	   (compactheap)
	     % now we have a simplified memory layout
	   (when (wgreaterp amount
			  (wquotient (wdifference heapupperbound
						  heaplast)
				      addressingunitsperitem))
		 (stderror "*** fasl space cannot be enlarged"))

  	   (setq amount (wtimes2 amount addressingunitsperitem))   
           (setq *moving-heap* amount)
	   (update-bases)
	   (move-heap amount)
	   % update bps pointers
           (setq nextbps heap)
           (setq lastbps (wplus2 nextbps (wdifference amount addressingunitsperitem)))
	   % update heap pointers
	   (setq heaplowerbound (wplus2 heaplowerbound amount))
	   (setq heap heaplowerbound)
	   (setq heaplast (wplus2 heaplast amount))
	   (init-gcarray)
	   (wquotient amount addressingunitsperitem)
	)
       ))

(de move-heap(amount)
    (ifor (from i heaplast heap -1)
	  (do (putmem (wplus2 i amount) (getmem i)))  ))

(de set_heap_size(u)
  (cond (u (stderror "no dynamic heap support"))
        (t (quotient (wdifference heapupperbound heaplowerbound)
                      addressingunitsperitem))))

(commentoutcode   % for emergency testing

(fluid '(bufff))
(setq bufff (gtwarray 1000))

(de notmeldung(txt n) 
    (console-print-string txt)
    (unixputn n)
    (console-newline)
    (sync))

(de sync()(null (psll-main bufff )))

)
