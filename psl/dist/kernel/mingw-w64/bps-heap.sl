%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PXK:BPS-HEAP.SL  
% Title:          Low level memory management     
% Author:         Herbert Melenk, Konrad-Zuse_zentrum Berlin
% Created:        07-Nov-89
% Modified:                                 
% Status:         Experimental
% Mode:           Lisp
% Package:        Kernel
%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% this version provides for a two heap model (copying GC)

(de init-pointers()
 
    % stack is initialized already by _main

    % catch stack                           
  (setq catchstackptr catchstack)

    % bndstack                    
  %  is a constant for now: (setq bndstksize (segmentlength bndstk))
  (setq bndstklowerbound bndstk)
  (setq bndstkupperbound (loc (wgetv bndstk (wdifference bndstksize 1))))
  (setq bndstkptr bndstk)
 
    % bps
    % nextbps is inherited, but must be relocated
  (setq bpssize (segmentlength bps))
  (setq nextbps (wplus2 addressingunitsperitem
                (relocfromload (wdifference nextbps
                                        addressingunitsperitem))))
  (setq lastbps (wplus2 bps bpssize))
    
    % heap
  (setq heapsize (segmentlength heap))
  (setq heapsize (wquotient heapsize 2))
    % the heap pointers for first heap
  (setq heaplowerbound heap)
  (setq heapupperbound (wplus2 heap heapsize))
  (setq heaplast heaplowerbound)
  (setq heaptrapbound (wdifference heapupperbound 120))
 
    % the heap pointers for second heap
  (setq oldheaplowerbound heapupperbound)
  (setq oldheapupperbound (wplus2 oldheaplowerbound heapsize))
  (setq oldheaplast oldheaplowerbound)
  (setq oldheaptrapbound oldheapupperbound)
)

(de alterheapsize(d)
    (setq d (wplus2 d d))
    (let ((u (enlarge_memory d))
	  (d2 (wquotient d 2)))
	(if (wlessp u 0) -1
	 (progn
		(setq heapsize (plus heapsize d2))
		(setq heapupperbound (plus heapupperbound d2))
		(setq heaptrapbound (wdifference heapupperbound 120))
		
		(setq oldheaplowerbound heapupperbound)
		(setq oldheaplast oldheaplowerbound)
		(setq oldheaptrapbound oldheapupperbound)))))

