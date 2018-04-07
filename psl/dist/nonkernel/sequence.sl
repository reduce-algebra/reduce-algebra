%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PNK:SEQUENCE.SL 
% Title:        Useful functions on strings, vectors and lists 
% Author:       Martin Griss and Eric Benson 
% Created:      10 September 1981 
% Modified:     22-Mar-84 14:43:18 (Brian Beach) 
% Status:       Experimental 
% Mode:         Lisp 
% Package:      Kernel 
% Compiletime:  
% Runtime:      
% Status:       Open Source: BSD License
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
% 01-Dec-83 15:01:30 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(on fast-integers)

(de indx (r1 r2)
  % Element of sequence
  (prog (tmp1 tmp2)
    (unless (posintp r2)
      (return (indexerror r2 'indx)))
    % Subscript
    (setq tmp1 (inf r1))
    (setq tmp2 (tag r1))
    (return (case tmp2
	      ((string-tag bytes-tag)
	       (if (wgreaterp r2 (strlen tmp1))
		 (rangeerror r1 r2 'indx)
		 (strbyt tmp1 r2)))
	      ((vector-tag)
	       (if (wgreaterp r2 (veclen tmp1))
		 (rangeerror r1 r2 'indx)
		 (vecitm tmp1 r2)))
	      ((words-tag)
	       (if (wgreaterp r2 (wrdlen tmp1))
		 (rangeerror r1 r2 'indx)
		 (wrditm tmp1 r2)))
	      ((halfwords-tag)
	       (if (wgreaterp r2 (halfwordlen tmp1))
		 (rangeerror r1 r2 'indx)
		 (halfworditm tmp1 r2)))
	      ((pair-tag)
	       (progn (setq tmp2 r2)
		      (while (wgreaterp tmp2 0)
			(setq r1 (cdr r1))
			(when (atom r1)
			  (rangeerror r1 r2 'indx))
			(setq tmp2 (wdifference tmp2 1)))
		      (car r1)))
	      (nil (nonsequenceerror r1 'indx))))))

(de setindx (r1 r2 r3)
  % Store at index of sequence
  (prog (tmp1 tmp2)
    (unless (posintp r2)
      (return (indexerror r2 'setindx)))
    % Subscript
    (setq tmp1 (inf r1))
    (setq tmp2 (tag r1))
    (return (case tmp2
	      ((string-tag bytes-tag)
	       (if (wgreaterp r2 (strlen tmp1))
		 (rangeerror r1 r2 'setindx)
		 (progn (setf (strbyt tmp1 r2) r3)
			r3)))
	      ((vector-tag)
	       (if (wgreaterp r2 (veclen tmp1))
		 (rangeerror r1 r2 'setindx)
		 (progn (setf (vecitm tmp1 r2) r3)
			r3)))
	      ((words-tag)
	       (if (wgreaterp r2 (wrdlen tmp1))
		 (rangeerror r1 r2 'setindx)
		 (progn (setf (wrditm tmp1 r2) r3)
			r3)))
	      ((halfwords-tag)
	       (if (wgreaterp r2 (halfwordlen tmp1))
		 (rangeerror r1 r2 'setindx)
		 (progn (setf (halfworditm tmp1 r2) r3)
			r3)))
	      ((pair-tag)
	       (progn (setq tmp2 r2)
		      (while (wgreaterp tmp2 0)
			(setq r1 (cdr r1))
			(when (atom r1)
			  (rangeerror r1 r2 'setindx))
			(setq tmp2 (wdifference tmp2 1)))
		      (rplaca r1 r3)
		      r3))
	      (nil (nonsequenceerror r1 'setindx))))))

% String and vector sub-part operations.
(de sub (r1 r2 r3)
  % Obsolete subsequence function
  (subseq r1 r2 (wplus2 r2 r3 1)))

(de subseq (r1 r2 r3)
  % R2 is lower bound, R3 upper
  (prog (newsize oldsize newitem)
    (unless (posintp r2)
      (return (indexerror r2 'subseq)))
    (unless (posintp r3)
      (return (indexerror r3 'subseq)))
    (setq newsize (wdifference (wdifference r3 r2) 1))
    (when (wlessp newsize -1)
      (return (rangeerror r1 r3 'subseq)))
    (return (case (tag r1)
	      ((string-tag bytes-tag)
	       (progn (setq oldsize (strlen (strinf r1)))
		      (if (wgreaterp (wdifference r3 1) oldsize)
			(rangeerror r1 r3 'subseq)
			(progn (setq newitem (gtstr newsize))
			       (setq r3 (strinf r1))
			       (for (from i 0 newsize 1)
				    (do
				     (setf (strbyt newitem i)
				       (strbyt r3 (wplus2 r2 i)))))
			       (case (tag r1)
				 ((string-tag) (mkstr newitem))
				 ((bytes-tag) (mkbytes newitem)))))))
	      ((vector-tag)
	       (progn (setq oldsize (veclen (vecinf r1)))
		      (if (wgreaterp (wdifference r3 1) oldsize)
			(rangeerror r1 r3 'subseq)
			(progn (setq newitem (gtvect newsize))
			       (setq r3 (vecinf r1))
			       (for (from i 0 newsize 1)
				    (do
				     (setf (vecitm newitem i)
				       (vecitm r3 (wplus2 r2 i)))))
			       (mkvec newitem)))))
	      ((words-tag)
	       (progn (setq oldsize (wrdlen (wrdinf r1)))
		      (if (wgreaterp (wdifference r3 1) oldsize)
			(rangeerror r1 r3 'subseq)
			(progn (setq newitem (gtwrds newsize))
			       (setq r3 (wrdinf r1))
			       (for (from i 0 newsize 1)
				    (do
				     (setf (wrditm newitem i)
				       (wrditm r3 (wplus2 r2 i)))))
			       (mkwrds newitem)))))
	      ((halfwords-tag)
	       (progn (setq oldsize (halfwordlen (halfwordinf r1)))
		      (if (wgreaterp (wdifference r3 1) oldsize)
			(rangeerror r1 r3 'subseq)
			(progn (setq newitem (gthalfwords newsize))
			       (setq r3 (halfwordinf r1))
			       (for (from i 0 newsize 1)
				    (do
				     (setf (halfworditm newitem i)
				       (halfworditm r3 (wplus2 r2 i)))))
			       (mkhalfwords newitem)))))
	      ((pair-tag)
	       (progn (for (from i 1 r2 1)
			   (do (if (pairp r1)
				 (setq r1 (rest r1))
				 (rangeerror r1 r2 'subseq))))
		      (setq newitem (cons nil nil))
		      (for (from i 0 newsize 1)
			   (do (if (pairp r1)
				 (progn (tconc newitem (first r1))
					(setq r1 (rest r1)))
				 (rangeerror r1 r3 'subseq))))
		      (car newitem)))
	      (nil (nonsequenceerror r1 'subseq))))))

(de setsub (r1 r2 r3 r4)
  % Obsolete subsequence function
  (setsubseq r1 r2 (wplus2 r2 r3 1) r4))

(de setsubseq (r1 r2 r3 r4)
  % R2 is lower bound, R3 upper
  (prog (newsize oldsize subsize newitem)
    (unless (posintp r2)
      (return (indexerror r2 'setsubseq)))
    (unless (posintp r3)
      (return (indexerror r3 'setsubseq)))
    (setq newsize (wdifference (wdifference r3 r2) 1))
    (when (wlessp newsize -1)
      (return (rangeerror r1 r3 'setsubseq)))
    (case (tag r1)
      ((string-tag bytes-tag)
       (progn (when (and (not (stringp r4)) (not (bytesp r4)))
		(return (nonstringerror r4 'setsubseq)))
	      (setq oldsize (strlen (strinf r1)))
	      (setq newitem (strinf r4))
	      (setq subsize (strlen newitem))
	      (cond ((wgreaterp (wdifference r3 1) oldsize)
		     (rangeerror r1 r3 'setsubseq))
		    ((not (weq newsize subsize))
		     (rangeerror r4 newsize 'setsubseq))
		    (t (setq r3 (strinf r1))
		       (for (from i 0 newsize 1)
			    (do
			     (setf (strbyt r3 (wplus2 r2 i))
			       (strbyt newitem i))))))))
      ((vector-tag)
       (progn (unless (vectorp r4)
		(return (nonvectorerror r4 'setsubseq)))
	      (setq oldsize (veclen (vecinf r1)))
	      (setq newitem (vecinf r4))
	      (setq subsize (veclen newitem))
	      (cond ((wgreaterp (wdifference r3 1) oldsize)
		     (rangeerror r1 r3 'setsubseq))
		    ((not (weq newsize subsize))
		     (rangeerror r4 newsize 'setsubseq))
		    (t (setq r3 (vecinf r1))
		       (for (from i 0 newsize 1)
			    (do
			     (setf (vecitm r3 (wplus2 r2 i))
			       (vecitm newitem i))))))))
      ((words-tag)
       (progn (unless (wrdsp r4)
		(return (nonvectorerror r4 'setsubseq)))
	      (setq oldsize (wrdlen (wrdinf r1)))
	      (setq newitem (wrdinf r4))
	      (setq subsize (wrdlen newitem))
	      (cond ((wgreaterp (wdifference r3 1) oldsize)
		     (rangeerror r1 r3 'setsubseq))
		    ((not (weq newsize subsize))
		     (rangeerror r4 newsize 'setsubseq))
		    (t (setq r3 (wrdinf r1))
		       (for (from i 0 newsize 1)
			    (do
			     (setf (wrditm r3 (wplus2 r2 i))
			       (wrditm newitem i))))))))
      ((halfwords-tag)
       (progn (unless (halfwordsp r4)
		(return (nonvectorerror r4 'setsubseq)))
	      (setq oldsize (halfwordlen (halfwordinf r1)))
	      (setq newitem (halfwordinf r4))
	      (setq subsize (halfwordlen newitem))
	      (cond ((wgreaterp (wdifference r3 1) oldsize)
		     (rangeerror r1 r3 'setsubseq))
		    ((not (weq newsize subsize))
		     (rangeerror r4 newsize 'setsubseq))
		    (t (setq r3 (halfwordinf r1))
		       (for (from i 0 newsize 1)
			    (do
			     (setf (halfworditm r3 (wplus2 r2 i))
			       (halfworditm newitem i))))))))
      ((pair-tag)
       (progn (when (and (not (pairp r4)) (not (null r4)))
		(return (nonpairerror r4 'setsubseq)))
	      (for (from i 1 r2 1)
		   (do (if (pairp r1)
			 (setq r1 (rest r1))
			 (rangeerror r1 r2 'setsubseq))))
	      (setq newitem r4)
	      (for (from i 0 newsize 1)
		   (do (if (and (pairp r1) (pairp newitem))
			 (progn (rplaca r1 (first newitem))
				(setq r1 (rest r1))
				(setq newitem (rest newitem)))
			 (rangeerror r1 r3 'setsubseq))))))
      (nil (nonsequenceerror r1 'setsubseq)))
    (return r4)))

(de concat (r1 r2)
  % Concatenate 2 sequences
  (let (i1
        i2
        tmp1
        tmp2
        tmp3)
    (case (tag r1)
      ((string-tag bytes-tag)
       (if (not (or (stringp r2) (bytesp r2)))
         (nonstringerror r2 'concat)
         (progn
	   (setq tmp1 (strinf r1))
	   (setq tmp2 (strinf r2))
	   (setq i1 (strlen tmp1))
	   (setq i2 (strlen tmp2))
	   (setq tmp3 (gtstr (wplus2 i1 i2 1)))
	   % R1 and R2 can move
	   (setq tmp1 (strinf r1))
	   (setq tmp2 (strinf r2))
	   (for (from i 0 i1 1)
		(do (setf (strbyt tmp3 i) (strbyt tmp1 i))))
	   (for (from i 0 i2 1)
		(do
		 (setf (strbyt tmp3 (wplus2 i1 i 1)) (strbyt tmp2 i))))
	   (if (stringp r1)
	       (mkstr tmp3)
	     (mkbytes tmp3)))))
      ((vector-tag)
       (if (not (vectorp r2))
	 (nonvectorerror r2 'concat)
         (progn
	   (setq tmp1 (vecinf r1))
	   (setq tmp2 (vecinf r2))
	   (setq i1 (veclen tmp1))
	   (setq i2 (veclen tmp2))
	   (setq tmp3 (gtvect (wplus2 i1 i2 1)))
	   % R1 and R2 can move
	   (setq tmp1 (vecinf r1))
	   (setq tmp2 (vecinf r2))
	   (for (from i 0 i1 1)
		(do (setf (vecitm tmp3 i) (vecitm tmp1 i))))
	   (for (from i 0 i2 1)
		(do
		 (setf (vecitm tmp3 (wplus2 i1 i 1)) (vecitm tmp2 i))))
	   (mkvec tmp3))))
      ((words-tag)
       (if (not (wrdsp r2))
	 (nonvectorerror r2 'concat)
         (progn
	   (setq tmp1 (wrdinf r1))
	   (setq tmp2 (wrdinf r2))
	   (setq i1 (wrdlen tmp1))
	   (setq i2 (wrdlen tmp2))
	   (setq tmp3 (gtwrds (wplus2 i1 i2 1)))
	   % R1 and R2 can move
	   (setq tmp1 (wrdinf r1))
	   (setq tmp2 (wrdinf r2))
	   (for (from i 0 i1 1)
		(do (setf (wrditm tmp3 i) (wrditm tmp1 i))))
	   (for (from i 0 i2 1)
		(do
		 (setf (wrditm tmp3 (wplus2 i1 i 1)) (wrditm tmp2 i))))
	   (mkwrds tmp3))))
      ((halfwords-tag)
       (if (not (halfwordsp r2))
	 (nonvectorerror r2 'concat)
         (progn	
	   (setq tmp1 (halfwordinf r1))
	   (setq tmp2 (halfwordinf r2))
	   (setq i1 (halfwordlen tmp1))
	   (setq i2 (halfwordlen tmp2))
	   (setq tmp3 (gthalfwords (wplus2 i1 i2 1)))
	   % R1 and R2 can move
	   (setq tmp1 (halfwordinf r1))
	   (setq tmp2 (halfwordinf r2))
	   (for (from i 0 i1 1)
		(do (setf (halfworditm tmp3 i) (halfworditm tmp1 i))))
	   (for (from i 0 i2 1)
		(do
		 (setf (halfworditm tmp3 (wplus2 i1 i 1))
		       (halfworditm tmp2 i))))
	   (mkhalfwords tmp3))))
      ((pair-tag id-tag) (when (or (null r1) (pairp r1))
			   (append r1 r2)))
      (nil (nonsequenceerror r1 'concat)))))

(de size (s)
  % Upper bound of sequence
  (case (tag s)
    ((string-tag bytes-tag words-tag vector-tag halfwords-tag)
     (getlen (inf s)))
    ((id-tag) -1)
    ((pair-tag)
     (prog (i)
       (setq i -1)
       (while (pairp s)
	 (setq i (wplus2 i 1))
	 (setq s (cdr s)))
       (return i)))
    (nil (nonsequenceerror s 'size))))

(on fast-integers)
