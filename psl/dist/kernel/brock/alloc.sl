%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PK:ALLOC.SL
% Description:  Kernel allocators for BPS, HEAP, IDs.
% Author:       Brian Beach, Hewlett-Packard CRC
% Created:      22-Feb-84
% Modified:     04-Jun-84 09:13:20 (Brian Beach)
% Mode:         Lisp
% Package:      
% Status:       Experimental (Do Not Distribute)
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 26 Oct 1984 2043-PDT (Mark R. Swanson)
%  Added call on TRY-OTHER-BPS-SPACES in GTBPS to provide "automatic" use
%  of alternate bps sections on the DEC20
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid
 '(lastbps
   nextbps
   heaplast
   heaptrapbound
   heapupperbound
   heaptrapped
   nextsymbol
   using-other-bps-spaces*
   ))

(on fast-integers)

% Allocate N words for binary code, ID names, etc.
% Returns the number of items left in BPS if N is NIL.

(de gtbps (number-of-items)
  (when (null number-of-items)(gtbps-nil-error))

      % adjust to multiple of 16 for faslin objects 
  (when (and (wgreaterp number-of-items 10)
	     (not (eq 0 (wand nextbps 15))))
	(setq nextbps (wplus2 16 (wshift (wshift nextbps -4) 4))))

  (let ((result nextbps))
      (setf nextbps (wplus2 nextbps (* number-of-items
				       addressingunitsperitem)))
      (if (wleq nextbps lastbps)
	result
	(progn
	  (setf nextbps result)
	  (if (and (getd 'try-other-bps-spaces)
		   (try-other-bps-spaces number-of-items))
	    (gtbps number-of-items)
	    (stderror "Ran out of binary program space"))))))



(de gtbps-nil-error ()
  (stderror "GTBPS called with NIL.")
  )


(de gtheap (number-of-items)
  
  % Allocates heap space.  As soon as all uses of (GTHEAP NIL) are
  % removed from code, this function can be removed, and REAL-GTHEAP
  % can become GTHEAP.

  (if (null number-of-items)
    (known-free-space)
    (real-gtheap number-of-items)
    )
  )


(de real-gtheap (number-of-items)

  % This function handles the normal case where there is no trap handling
  % to be done.  It is written so that no stack frame is allocated, which
  % vastly improves performance (at least on the 68000).

  (let ((result heaplast))
    (setf heaplast (wplus2 heaplast (wtimes2 number-of-items
					     addressingunitsperitem)))
    (if (wlessp heaplast heaptrapbound)
      result
      (prog1
       (get-heap-trap result number-of-items)
       )
      )))


(de get-heap-trap (number-of-items) % To be redefined
  (kernel-fatal-error "Garbage collection required.")
  )


(de gtid ()
  % Allocate a new ID                                                     
  %                                                                        
  % IDs are allocated as a linked free list through the SymNam cell,       
  % with a 0 to indicate the end of the list.                              
  %                                                                        
  (when (eq nextsymbol 0)
    (reclaim)
    (when (eq nextsymbol 0)
      (kernel-fatal-error "Ran out of ID space")
      ))
  (let ((result nextsymbol))
    (setq nextsymbol (symnam result))
    result
    ))

(de gtwrds (upper-bound)
  % Allocate space for a words vector of UPPER-BOUND+1 elements. 
  (let ((ptr (gtheap (wplus2 (wrdpack upper-bound) 1))))
    (setf (getmem ptr) (mkitem hwords-tag upper-bound))
    ptr
    ))

(de gtconststr (upper-bound)
  % Allocate un-collected string for print name
  (let* ((n-words  (strpack upper-bound))
	 (str      (gtbps (+ 1 n-words))))
    (setf (getmem str) upper-bound)
    (setf (wgetv str n-words) 0)  % clear last word, including last byte
    str
    ))

(off fast-integers)
