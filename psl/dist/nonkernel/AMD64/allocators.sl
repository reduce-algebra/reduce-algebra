%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:ALLOCATORS.SL 
% Title:        Low level storage management 
% Author:       Eric Benson 
% Created:      27 August 1981 
% Modified:     03-Jul-84 10:14:03 
% Status:       Experimental 
% Mode:         Lisp 
% Package:      Kernel 
% Compiletime:  
% Runtime:      
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
% 06-APR-88 (Julian Padget)
%  Reinstated allocators mentioned below.
% 21-Dec-86 (Leigh Stoller)
%  Added try-other-bps-spaces function and support for it in delbps.
% 03 Sep 1986 (Julian Padget)
%  Added allocators for bvectors and contexts (funargs are done with
%  CONS and bstructs are not allocated.
% 03-Jul-84 10:09:24 (Jim Ambras/CRC)
%  Modified get-heap-try-reclaim to use stderror instead of kernel-fatal-error
%   so the kernel won't terminate when heap space is exhausted.
% 23-Feb-84 15:40:14 (Brian Beach)
%  Removed everything that is in the kernel.  (This file will now be FASLed in)
% 21-Feb-84 09:52:00 (Steve Lowder)
%  Removed all useage of wvar, wconst, warray, wstring.
% 03-Jan-84 18:25:44 (Cris Perdue)
%  Fixed some comments, made gtbps grab no space if the block
%  requested is too big to give.
% 02-Dec-83 09:32:39 (Brian Beach)
%   Translated from Rlisp to Lisp.
%                                                                          
% 5 Nov 83, Swanson and Perdue                                             
%  Changed mention of PDP10 to mention the new system attribute            
%  OneSpaceGC.  Added special code for Extended 20.                        
%  <PSL.KERNEL>ALLOCATORS.RED.7, 23-Mar-83 11:35:37, Edit by KESSLER       
%  Added OldHeapTrapBound to exported WVars, so we can update the heap trap
%  bound upon switch.                                                      
% Edit by Cris Perdue, 16 Feb 1983 1834-PST                                
% Pre-GC trap, known-free-space fns                                        
%  <PSL.KERNEL>ALLOCATORS.RED.4, 10-Jan-83 15:50:50, Edit by PERDUE        
%  Added GtEVect                                                           
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load if-system))

(de eval(x) x)
(de equal (x y) (eq x y))
(de errorprintf(x) (console-print-string x) (console-newline))

(global '(heapupperbound heaplowerbound heaplast heaptrapbound heaplast
          heaptrapped nextbps lastbps))

(fluid '(using-other-bps-spaces*))

(setf heaptrapped nil)

(on fast-integers)

(de known-free-space ()
  (mkint (wquotient (wdifference heapupperbound heaplast) 
                    addressingunitsperitem)))

(de free-bps ()
  (wquotient (wdifference lastbps nextbps) 
	     addressingunitsperitem)
  )
%
% The function GTHEAP is defined in the kernel.  It calls GET-HEAP-TRAP when
% HEAPLAST (the pointer to the next available item) passes HEAPTRAPBOUND.
%

(de get-heap-trap (pointer number-of-items)

  % An attempt has been made to allocate NUMBER-OF-ITEMS from the heap, and
  % the HEAPTRAPBOUND was exceeded.  POINTER is the value that would have been
  % returned if the trap bound had not been passed.  The HEAPTRAPPED flag is used
  % to indicate when GC-TRAP has already been called.  If it has not, do so.

  (if (null heaptrapped)
    (progn
     (setf heaplast (wdifference heaplast (wtimes2 number-of-items
						   addressingunitsperitem)))
     (setf heaptrapped t)
     (gc-trap)
     (gtheap number-of-items)
     )
    (if (wlessp heaplast heaptrapbound)
      pointer
      (get-heap-try-reclaim number-of-items)
      )
    ))

(de gc-trap ()
  )

(fluid '(heap-warn-level))
 
(de get-heap-try-reclaim (number-of-items)
  (let ((oldheap-warn-level heap-warn-level))
  % Reset HEAPLAST to the way it was before the allocation attempt, do
  % a garbage collection, and then try the allocation again.
 
  (setf heaplast (wdifference heaplast (wtimes2 number-of-items
                                                addressingunitsperitem)))
  (when (wgreaterp number-of-items heap-warn-level)
        (setq heap-warn-level (wplus2 number-of-items 1000)))
  (!%reclaim)
  (setq heap-warn-level oldheap-warn-level)
  (let ((result heaplast))
    (setf heaplast (wplus2 heaplast (wtimes2 number-of-items
                                             addressingunitsperitem)))
    (if (wlessp heaplast heaptrapbound)
      result
      (stderror "Ran out of heap space.")
      ))))

(de gc-trap-level ()
  (wquotient (wdifference heapupperbound heaptrapbound)
	     addressingunitsperitem))

(de set-gc-trap-level (n)
  (unless (intp n)
    (nonintegererror n 'set-gc-trap-level))
  (setq n (intinf n))
  (setq heaptrapbound 
        (wdifference heapupperbound 
                     (wtimes2 n addressingunitsperitem)))
  t)

(de delheap (lowpointer highpointer)
  (when (weq highpointer heaplast)
    (setq heaplast lowpointer)))

(de gtstr (upper-bound)
  % Allocate a string of UPPER-BOUND+1 characters.
  (let* ((n-words  (strpack upper-bound))
	 (str      (gtheap (+ 1 n-words))))
    (setf (getmem str) (mkitem hbytes-tag upper-bound))
    (setf (wgetv str n-words) 0)  % clear last word, including last byte
    str
    ))

% GTCONSTSTR is defined in the kernel

(de gthalfwords (upper-bound)
  % Allocate space for a halfwords vector of UPPER-BOUND+1 elements.
  (let* ((n-words  (halfwordpack upper-bound))
	 (ptr      (gtheap (+ n-words 1))))
    (setf (getmem ptr) (mkitem hhalfwords-tag upper-bound))
    ptr
    ))

(de gtvect (upper-bound)
  % Allocate space for a vector of UPPER-BOUND+1 elements.
  (let ((ptr  (gtheap (+ (vectpack upper-bound) 1))))
    (setf (getmem ptr) (mkitem hvect-tag upper-bound))
    ptr
    ))

(de gtevect (upper-bound)
  % Allocate space for an evector of UPPER-BOUND+1 elements.
  (let ((ptr  (gtheap (+ (evectpack upper-bound) 1))))
    (setf (getmem ptr) (mkitem hvect-tag upper-bound))
    ptr
    ))

(de gtcontext ()
  % allocate space for an environment descriptor (7 entries)
  (let ((ptr (gtheap (+ (contextpack) 1))))
    (setf (getmem ptr) (mkitem hvect-tag (contextpack)))
    ptr))

(de gtbvect (upper-bound)
  % allocate space for a bvector - four words per entry
  (let ((ptr (gtheap (+ (bvectpack upper-bound) 1))))
    (setf (getmem ptr) (mkitem hvect-tag (bvectpack upper-bound)))
    ptr))

% GTWRDS is defined in the kernel

(de gtfixn ()
  % Allocate space for a fixnum.
  (let ((ptr  (gtheap (+ (fixpack) 1))))
    (setf (getmem ptr) (mkitem hwords-tag (- (fixpack) 1)))
    ptr
    ))

(if_system sel
(de gtfltn ()
  % Allocate space for a floating point number on a double-word boundary.
  (let ((x (gtheap 0))
	ptr)
    (if (neq (remainder x 8) 4)
	(gtheap 1))
    (setf ptr  (gtheap (+ (floatpack) 1)))
    (setf (getmem ptr) (mkitem hwords-tag (- (floatpack) 1)))
    ptr
    ))

(de gtfltn ()
  % Allocate space for a floating point number.
  (let ((ptr  (gtheap (+ (floatpack) 1))))
    (setf (getmem ptr) (mkitem hwords-tag (- (floatpack) 1)))
    ptr
    ))
)

% GTID is defined in the kernel.

% GTBPS is defined in the kernel.

%% Attempt to allocate more bps space at the end of the image by calling
%% external-allocatemorebps. Warn user and set fluid so we can head off
%% an unexec.
%%
(de try-other-bps-spaces (number-of-items)
  (let ((morebps (external-allocatemorebps)))
    (when (wgreaterp morebps 0)
      (printf "Warning, allocating additional bps space of %w items.%n"
	      (quotient morebps 4))
      (printf "  Cannot savesystem after allocating additional bps space.%n")
      (setq using-other-bps-spaces* t))))

% Return space to BPS, but make sure that nextbps will not intrude down into
%  the heap, as might be the case after calling try-other-bps-spaces.
(de delbps (bottom top)
  (when (and (weq nextbps top)
	     (wgreaterp bottom bpslowerbound))
    (setq nextbps bottom)))

(de gtwarray (n)
  %. Allocate N words for WVar/WArray/WString                              
  (if (null n)
    (wquotient (wdifference lastbps nextbps) 
	       addressingunitsperitem)
    (let ((b (wdifference lastbps (wtimes2 n addressingunitsperitem))))
      (if (wgreaterp nextbps b)
	(stderror '"Ran out of WArray space")
	(setq lastbps b))
      )))

(de delwarray (bottom top)
  %. Return space for WArray                                               
  (when (weq lastbps bottom)
    (setq lastbps top)))


(off fast-integers)
