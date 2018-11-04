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

