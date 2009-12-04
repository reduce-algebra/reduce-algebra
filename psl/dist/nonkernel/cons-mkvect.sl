%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:CONS-MKVECT.SL 
% Title:        Standard Lisp constructor functions 
% Author:       Eric Benson 
% Created:      20 August 1981 
% Modified:     07-May-84 07:30:17 
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
% 2-July-91 (Winfried Neun)
%  Added lap versions of cons, xcons and ncons.
% 07-May-84 07:27:46 (Brian Beach)
%  Added Mike's MAKE-MANUAL-EVECTOR
% 24-Feb-84 08:24:09 (Brian Beach)
%  Make into a loadable file.  Removed definition of CONS, since CONS is now
%  in the kernel.  DePROGged.
% 01-Dec-83 14:25:23 (Brian Beach)
%   Translated from Rlisp to Lisp.
% 19-Jul-83  Nancy Kendzierski                                             
%   Fixed Allocate!-String to refer to Len instead of L in call to         
%   NonPositiveIntegerError.                                               
% 22 Jun 1983 1433-PDT, Cris Perdue                                        
%   Added Allocate-String, uninitialized strings for speed, also           
%   Allocate-Words.                                                        
% <PSL.KERNEL>CONS-MKVECT.RED.4, 28-Feb-83 11:41:46, Edit by PERDUE        
%  Moved Make-Words, Make-Halfwords, etc. here from SEQUENCE.RED           
%  Also moved STRING and VECTOR here from there.                           
% Edit by Cris Perdue, 23 Feb 1983 1045-PST                                
% Changed occurrences of HeapUpperbound to HeapTrapBound in optimized      
% allocators to supported pre-GC traps.                                    
%  <PSL.KERNEL>CONS-MKVECT.RED.2, 10-Jan-83 15:50:08, Edit by PERDUE       
%  Added MkEVect                                                           
% Edit by GRISS: (?)                                                       
% Optimized CONS, XCONS and NCONS                                          
%  <PSL.INTERP>CONS-MKVECT.RED.5,  9-Feb-82 06:25:51, Edit by GRISS        
%  Added HardCons                                                          
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(on fast-integers)

% CONS is defined in the kernel.  It will probably need to be changed if
% XCONS and NCONS need changing.

(compiletime (flag '(!_slowcons !_slowncons !_slowxcons) 'internalfunction))

(de !_slowcons (a b)
  (let ((ptr (gtheap (pairpack))))
    (setf (wgetv ptr 0) a)
    (setf (wgetv ptr 1) b)
    (mkpair ptr)
    ))

(de !_slowxcons (b a)
  (let ((ptr (gtheap (pairpack))))
    (setf (wgetv ptr 0) a)
    (setf (wgetv ptr 1) b)
    (mkpair ptr)
    ))

(de !_slowncons (a)
  % Same as (CONS A NIL)
  (let ((ptr (gtheap (pairpack))))
    (setf (wgetv ptr 0) a)
    (setf (wgetv ptr 1) nil)
    (mkpair ptr)
    ))

(lap '((*entry cons expr 2)
          (*alloc 0)
          (*move (global heaplast) (reg 3))
          (*move (global heaptrapbound) (reg 4))
          (*move (reg 3) (reg 5))
          (*wplus2 (reg 5) (times addressingunitsperitem 2))
          (*jumpwgeq (label callslow) (reg 5) (reg 4))
          (*move (reg 1) (memory (reg 3) 0))
          (*move (reg 2) (memory (reg 3) addressingunitsperitem))
          (*move (reg 5) (global heaplast))
          (*move (reg 3) (reg 1))
          (*mkitem (reg 1) pair-tag)
          (*exit 0)
      callslow
          (*linke 0 !_slowcons expr 2)))

(lap '((*entry ncons expr 2)
          (*alloc 0)
          (*move (global heaplast) (reg 3))
          (*move (global heaptrapbound) (reg 4))
          (*move (reg 3) (reg 5))
          (*wplus2 (reg 5) (times addressingunitsperitem 2))
          (*jumpwgeq (label callslow) (reg 5) (reg 4))
          (*move (reg 1) (memory (reg 3) 0))
          (*move (quote nil) (memory (reg 3) addressingunitsperitem))
          (*move (reg 5) (global heaplast))
          (*move (reg 3) (reg 1))
          (*mkitem (reg 1) pair-tag)
          (*exit 0)
      callslow
          (*linke 0 !_slowncons expr 1)))

(lap '((*entry xcons expr 2)
          (*alloc 0)
          (*move (global heaplast) (reg 3))
          (*move (global heaptrapbound) (reg 4))
          (*move (reg 3) (reg 5))
          (*wplus2 (reg 5) (times addressingunitsperitem 2))
          (*jumpwgeq (label callslow) (reg 5) (reg 4))
          (*move (reg 1) (memory (reg 3) addressingunitsperitem))
          (*move (reg 2) (memory (reg 3) 0))
          (*move (reg 5) (global heaplast))
          (*move (reg 3) (reg 1))
          (*mkitem (reg 1) pair-tag)
          (*exit 0)
      callslow
          (*linke 0 !_slowxcons expr 2)))

(de mkvect (upper-bound)
  % Allocate a vector, initialize all elements to NIL                                      
  (if (intp upper-bound)
    (if (wlessp upper-bound -1)
      (nonpositiveintegererror upper-bound 'mkvect)
      (let ((v (gtvect upper-bound)))
	(for (from i 0 upper-bound)
	     (do (setf (vecitm v i) nil))
	     )
	(mkvec v)
	))
    (nonintegererror upper-bound 'mkvect)
    ))

(de make-vector (upper-bound fill-value)
  % Allocate a vector, initialize all elements to FILL-VALUE.
  (if (intp upper-bound)
    (if (wlessp upper-bound -1)
      (nonpositiveintegererror upper-bound 'make-vector)
      (let ((v (gtvect upper-bound)))
	(for (from i 0 upper-bound)
	     (do (setf (vecitm v i) fill-value))
	     )
	(mkvec v)
	))
    (nonintegererror upper-bound 'make-vector)
    ))

(de mkevector (upper-bound first-element-value)
  % Allocate an evector, initialize the first element, and set the rest to NIL.
  (if (intp upper-bound)
    (if (wlessp upper-bound 0)
      (nonpositiveintegererror upper-bound 'mkevector)
      (let ((v (gtevect upper-bound)))
	(setf (evecitm v 0) first-element-value)
	(for (from i 1 upper-bound)
	     (do (setf (evecitm v i) nil))
	     )
	(mkevect v)
	))
    (nonintegererror upper-bound 'mkevector)
    ))
		 
(de make-manual-evector (n etag value)

  %  Allocate Evect, init all to 'value'.
  %  Fill in the 0th element with 'etag'.

  (if (not (intp n))
    % THEN We have an error.
    (nonintegererror n 'mkevect)
    % ELSE allocate.
    (if (< n 0)
      % THEN We have an error.
      (stderror '"An  Evect with fewer than one element cannot be allocated")
      % ELSE
      (let ((v (gtevect n)))
	(setf (evecitm v 0) etag)
	(for (from i 1 n 1)
	     (do (setf (evecitm v i) value)))
	(mkevect v))))
  )

(de allocate-string (len)
  % Make str with Len chars, uninitialized                                  
  (if (intp len)
    (if (wlessp len 0)
      (nonpositiveintegererror len 'allocate-string)
      (mkstr (gtstr (- len 1)))
      )
    (nonintegererror len 'allocate-string)
    ))

(de mkstring (upper-bound fill-char)
  % Make string of UPPER-BOUND+1 characters, with all characters set to FILL-CHAR.
  (if (intp upper-bound)
    (if (wlessp upper-bound -1)
      (nonpositiveintegererror upper-bound 'mkstring)
      (let ((ptr (gtstr upper-bound)))
	(for (from i 0 upper-bound) (do (setf (strbyt ptr i) fill-char)))
	(mkstr ptr)
	))
    (nonintegererror upper-bound 'mkstring)
    ))
  
(de make-bytes (upper-bound fill-value)
  % Make a byte vector of UPPER-BOUND+1 elements, will all elements set to FILL-VALUE.
  (if (intp upper-bound)
    (if (wlessp upper-bound -1)
      (nonpositiveintegererror upper-bound 'make-bytes)
      (let ((ptr (gtstr upper-bound)))
	(for (from i 0 upper-bound) (do (setf (strbyt ptr i) fill-value)))
	(mkbytes ptr)
	))
    (nonintegererror upper-bound 'make-bytes)
    ))

(de make-halfwords (upper-bound fill-value)
  % Make a halfword vector of UPPER-BOUND+1 elements, will all elements set to FILL-VALUE.
  (if (intp upper-bound)
    (if (wlessp upper-bound -1)
      (nonpositiveintegererror upper-bound 'make-halfwords)
      (let ((ptr (gthalfwords upper-bound)))
	(for (from i 0 upper-bound) (do (setf (halfworditm ptr i) fill-value)))
	(mkhalfwords ptr)
	))
    (nonintegererror upper-bound 'make-halfwords)
    ))

(de make-words (upper-bound fill-value)
  % Make a word vector of UPPER-BOUND+1 elements, will all elements set to FILL-VALUE.
  (if (intp upper-bound)
    (if (wlessp upper-bound -1)
      (nonpositiveintegererror upper-bound 'make-words)
      (let ((ptr (gtwrds upper-bound)))
	(for (from i 0 upper-bound) (do (setf (wrditm ptr i) fill-value)))
	(mkwrds ptr)
	))
    (nonintegererror upper-bound 'make-words)
    ))

(de allocate-words (len)
  % Make a word vector of UPPER-BOUND+1 elements, unititialized.
  (if (intp len)
    (if (wlessp len 0)
      (nonpositiveintegererror len 'allocate-words)
      (mkwrds (gtwrds (- len 1)))
      )
    (nonintegererror len 'allocate-words)
    ))

% Maybe we want to support efficient compilation of these, as with LIST,   
% by functions String2, String3, Vector2, Vector3, etc.                    

(dn string (u)
  %. Analogous to LIST, string constructor                                 
  (list2string u))

(dn vector (u)
  %. Analogous to LIST, vector constructor                                 
  (list2vector u))

(off fast-integers)
