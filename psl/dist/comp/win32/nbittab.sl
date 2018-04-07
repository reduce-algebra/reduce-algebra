%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXC:NBITTAB.SL
% Description:  New bit table format.
% Author:
% Created:
% Package:
% Status:       Open Source: BSD License
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

(compiletime (load inum fasl-dec))

(fluid '(code-vect*))

(de compact-bittable(base max)
 (let ((i 0) (d 0) bl b l s sb)
    (ifor (from i 0 max 1) 
     (do
      (progn
       (setq b (bittable base i))
       (if (or (not (eq b 0))  % nonzero entry
	       (eq d 16#3f)    % maximum offset
	   )
	   (progn
	       (push (wor (wshift b 6) d) bl)
	       (setq d 1)
	   )
	   (setq d (iadd1 d))
       )
    )))
    (setq bl (cons 0 bl))
    (setq bl (reversip bl))
    (setq l (length bl))
    (setq s (mkstring l 0))
    (setq sb (strbase(strinf s))) 
    (setq b (isub1 l))
    (ifor (from i 0 b 1) (do (setf (byte sb i) (pop bl))))
    (return (cons l s))))

(fluid '(*compact-bittable))

(setq *compact-bittable t)

(de codefiletrailer ()
  (prog (s)
	(systemfaslfixup)
	(binarywrite codeout* (idifference (isub1 nextidnumber*) 
					   first-local-id-number))
	% Number of local IDs
	(foreach x in (car orderedidlist*) do
		 (progn (remprop x fasl-idnumber-property*)
			(setq x (strinf (faslid2string x)))
			(setq s (strlen x))
			(binarywrite codeout* s)
			(binarywriteblock codeout* (strbase x)
					  (strpack s))))
	(binarywrite codeout* % S is size in words
		     (setq s
		      (iquotient
		       (iplus2 currentoffset*
			(isub1 addressingunitsperitem))
		       addressingunitsperitem)))
	(binarywrite codeout* initoffset*)
	(fasl-write-codeblock codeout* codebase* s)
	(if *compact-bittable
	 (let((b (compact-bittable (strbase (strinf bittablebase*)) (isub1 bittableoffset*)))
	      (bpw (quotient bitsperword 8)))
	   (binarywrite codeout*
	    (setq s (iquotient
		       (iplus2 (car b)
			(isub1 bpw))
		       bpw)))
	   (binarywriteblock codeout* (strbase(strinf (cdr b))) s)
	 )
	 (progn
	  (binarywrite codeout*
		     (setq s
		      (iquotient
		       (iplus2 bittableoffset*
			(isub1 bittable-entries-per-word))
		       bittable-entries-per-word)))
	  (binarywriteblock codeout* (strbase (strinf bittablebase*)) s)
	))
	(deallocatefaslspaces)))

%-------------------- fasl spaces ---------------------------------------------

(de updatebittable (numberofentries firstentry)
  (when *writingfaslfile
   (let ((b (strbase(strinf bittablebase*))))
    (putbittable b  bittableoffset* firstentry)
    (setq bittableoffset* (iadd1 bittableoffset*))
    (for (from i 2 numberofentries 1)
	 (do (progn (putbittable b bittableoffset* 0)
		    (setq bittableoffset* (iadd1 bittableoffset*)))))
    (when (igreaterp bittableoffset* maxfasloffset*)
      (fatalerror "BPS exhausted during FaslOut; output file too large")))))

(de allocatefaslspaces ()
  (prog (b m)
    (setq m 400000)                     % default bytes of bit table
    (setq code-vect!* (fasl-mkxvect))
    (setq bittablebase* (mkstring m 0))
    (setq faslblockend* 16#3ffffff)     % no limit
    (setq currentoffset* 0)
    (setq bittableoffset* 0)
    (setq codebase* 0)
    (setq maxfasloffset* (wtimes2 m 4))
    (setq orderedidlist* (cons nil nil))
    (setq nextidnumber* first-local-id-number)))

(de deallocatefaslspaces ()
 % (delwarray bittablebase* faslblockend*)
   (setq code-vect* nil)
   (setq bittablebase* nil)
  )

%----------------------------- from pxnk --------------------------------------

(when (null (getd 'pnk-depositvaluecelllocation))
     (copyd 'pnk-depositvaluecelllocation 'depositvaluecelllocation)
     (copyd 'pnk-depositextrareglocation 'depositextrareglocation)
     (copyd 'pnk-depositfunctioncelllocation 'depositfunctioncelllocation)
     (remd 'depositvaluecelllocation)
     (remd 'depositextrareglocation)
     (remd 'depositfunctioncelllocation))


(de depositvaluecelllocation (x)
  (if (not *writingfaslfile)(pnk-depositvaluecelllocation x)
    (progn (lap-putword (iplus2 codebase* currentoffset*) 0 
		 (makerelocword reloc-value-cell (findidnumber x)))
	   (setf currentoffset* (iplus2 currentoffset* 4))
	   (updatebittable 4 reloc-word))))

(de depositextrareglocation (x)
  (if (not *writingfaslfile)(pnk-depositextrareglocation x)
    (progn (lap-putword (iplus2 codebase* currentoffset*) 0 
		 (makerelocword reloc-value-cell (wplus2 x 8150)))
	   (setf currentoffset* (iplus2 currentoffset* 4))
	   (updatebittable 4 reloc-word))))

(de depositfunctioncelllocation (x)
  (if (not *writingfaslfile)(pnk-depositfunctioncelllocation x)
    (progn (lap-putword (iplus2 codebase* currentoffset*) 0 
		 (makerelocword reloc-function-cell 
		  (findidnumber x)))
	   (setf currentoffset* (iplus2 currentoffset* 4))
	   (updatebittable 4 reloc-word))))


%------------------------------------------------------------------------------
%  storing faslout data in heap
%------------------------------------------------------------------------------

(de lap-putword(a o w)
    (when (not (eq o 0)) (stderror "unexpected putword argument"))
    (if (or (not *writingfaslfile) (null code-vect!*))
	(putword a 0 w)
	(fasl-xputw code-vect* a w)))

(de lap-puthalfword(a o w)
    (when (not (eq o 0)) (stderror "unexpected puthalfword argument"))
    (if (or (not *writingfaslfile) (null code-vect!*))
	(puthalfword a 0 w)
	(fasl-xputh code-vect* a w)))

(de lap-putbyte(a o w)
    (when (not (eq o 0)) (stderror "unexpected putbyte argument"))
    (if (or (not *writingfaslfile) (null code-vect!*))
	(putbyte a 0 w)
	(fasl-xputb code-vect* a w)))

(de lap-updatebittable(n m)
    (updatebittable n m))

%-------------------------------------------------------------------

(de fasl-write-codeblock(codeout codebase s)
   (if (null code-vect!*)
       (binarywriteblock codeout codebase s)
       (fasl-xvect-writeblock codeout code-vect!* s)))

%-------------------------------------------------------------------
% xvect: vector of memory blocks, byte-addressable
%-------------------------------------------------------------------

(compiletime (define-constant fasl-vlth 256))

(de fasl-mkxvect() (make-vector 1024 nil))

(de lap-check-mem()
 % ensure that there is enough free space for depositing an
 % instruction without garbage collector.
 (when (and *writingfaslfile code-vect!*)
  (prog(i n)
    (setq n (wplus2 codebase* 32))
    (setq i (wquotient n (times fasl-vlth addressingunitsperitem))) 
    (fasl-findblock code-vect!* i))))
     
(de fasl-findblock(v i)
 (let (w)
  (setq w (igetv v i))
  (when (null w) (iputv v i (setq w (make-words fasl-vlth 0))))
  w))
       
(de fasl-xputw(v n w)
  % put word w into vector v at byteaddress n.
  % LITTLE ENDIAN ONLY!!!
  (let((i 0))
    (while (wlessp i addressingunitsperitem)
	 (fasl-xputb v n (wand w 255))
	 (setq w (wshift w -8))
	 (setq i (iadd1 i))
	 (setq n (iadd1 n)))
   w))

(de fasl-xputh(v n w)
  % put halfword w into vector v at byteaddress n.
  % LITTLE ENDIAN ONLY!!!
  (let((i 0))
    (while (wlessp i (quotient addressingunitsperitem 2))
	 (fasl-xputb v n (wand w 255))
	 (setq w (wshift w -8))
	 (setq i (iadd1 i))
	 (setq n (iadd1 n)))
   w))
 
(de fasl-xputb(v n w)
  % put one bytge into vector v.
  (prog(i j)
    (setq i (iquotient n (times fasl-vlth addressingunitsperitem))) 
    (setq j (iremainder n (times fasl-vlth addressingunitsperitem)))
    (setq v (fasl-findblock v i))
    (putbyte (wplus2 (vecinf v) addressingunitsperitem) j w)
    (return w)))

(de fasl-xvect-writeblock(file v l)
  (let ((i 0))  
    (while (wgreaterp l 0)
	(binarywriteblock file
			  (wplus2 (vecinf (igetv v i)) addressingunitsperitem) 
			  (if (wgreaterp l fasl-vlth) fasl-vlth l)
	)
	(setq l (wdifference l fasl-vlth))
	(setq i (iadd1 i))
	)))
