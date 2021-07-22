%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% File:         PC:DUMPFASL.SL 
% Title:        Code for showing some contents of a FASL file: symbols, relocation
% Author:       Rainer Schöpf
% Created:      08 February 2019
% Modified:     08 June 2021
% Status:       Open Source: BSD License
% Mode:         Lisp 
%
% (c) Copyright 2019 Reduce Developers
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

(compiletime (load fasl-decls))

(on fast-integers)

(fluid '(tokenbuffer argumentblock))

(de dumpfasl (file)
  (prog (fid                  % file pointer 
	 local-id-count       % number of ids in the file
	 local-id-table       % table for mapping local ID numbers to global ID numbers.
	 readcount            % number of words in local-id-table
	 current-offset	      % current offset into input file
	 code-size            % number of words of code
	 code-base            % location of the start of the code
	 init-function-address% Offset into the code of the init function
	 bit-table-size       % number of words in the bit table
	 bit-table            % the bit table
	 mode                 % magic number
	 Btop
	 )

    (printf "Dumpfasl of file %s%n" file)
    % Open the file
    (setf fid (binaryopenread file))

    % Check that the first word is the correct magic number.
    (setq mode (binaryread fid))
    (unless (weq (wand 16#ffff mode) faslin-magic)
	(binaryclose fid)
	(faslin-bad-file file)
	(return nil)
	)
    (setq mode (wshift mode -16))
    (setq current-offset 1)

    % Read in the ID table.
    (setf (cons readcount local-id-table) (dumpfasl-read-id-table fid))
    (printf "ID table has size %d (%x) words%n" readcount readcount)
    (setq current-offset (plus2 current-offset readcount))

    % Read the code.
    (setf code-size (binaryread fid)) % Size of code segment in words
    (setf code-base (gtbps code-size)) % Allocate space in BPS
    (setq Btop (GtBPS 0))              % pointer to top of alloc. BPS
    (setf init-function-address (binaryread fid))
    (setq current-offset (plus2 current-offset 2))
    (printf "Code has size %d (%x) words at offset %d (%x) words,%n init function at relative address %d (%x)%n"
	    code-size code-size
	    current-offset current-offset
	    init-function-address init-function-address)
    (binaryreadblock fid (loc (wgetv code-base 0)) code-size)
    (setq current-offset (plus current-offset code-size 2))

    % Read the bit table
    (setf bit-table-size (binaryread fid))
    (printf "Fasl bittable has size %d (%x) wirds%n" bit-table-size bit-table-size)
    (setq current-offset (plus2 current-offset bit-table-size))
    (setq bit-table (mkwrds (gtwrds bit-table-size)))
    (binaryreadblock fid (loc (words-fetch bit-table 0)) bit-table-size)

    % Close the file
    (binaryclose fid)

    % Twiddle the bits.

    (if (weq (wand mode 1) 1) 
	(dumpfasl-do-relocation-new code-base code-size bit-table local-id-table)
	(dumpfasl-do-relocation code-base code-size bit-table local-id-table))

    (DelBPS code-base btop)

    ))

(de dumpfasl-do-relocation (code-base code-size bit-table id-table)
  % CODE-AU-SIZE is the size of the code measured in addressing
  % units, rather than words.

  (let ((code-au-size  (wtimes2 code-size 
				addressingunitsperitem)))
    (for (from i 0 (wdifference code-au-size 1)) 
	 (do 
	  (let ((bit-table-entry (bittable (loc (words-fetch bit-table 0)) i))   %%% HACK!
		(code-location    (wplus2 code-base i)))
	    (case bit-table-entry
	      ((reloc-word)
	       (dumpfasl-relocate-word code-location code-base id-table))
	      ((reloc-inf) 
	       (dumpfasl-relocate-inf code-location code-base id-table))
	      ((reloc-right-half)
	       (dumpfasl-relocate-right-half code-location code-base id-table))
	      ))))))
		    
(de dumpfasl-do-relocation-new (code-base code-size bit-table id-table)
  (let ((ptr 0)
	(code-location code-base) 
	 entry)
     (setq bit-table (strbase (strinf bit-table)))
     (while (not (izerop (setq entry (wand 16#ff (byte bit-table ptr)))))     
	  (setq ptr (iadd1 ptr))
	  (setq code-location (iplus2 code-location (wand entry 16#3f)))
	  (setq entry (wshift entry -6))
	  (case entry
	      ((reloc-word)
	       (dumpfasl-relocate-word code-location code-base id-table))
	      ((reloc-inf) 
	       (dumpfasl-relocate-inf code-location code-base id-table))
	      ((reloc-right-half)
	       (dumpfasl-relocate-right-half code-location code-base id-table))
	      ))))
		    
		     

(compiletime (ds reloc-word-inf (x) (wshift (wshift x 34) -34)))
(compiletime (ds reloc-word-tag (x) (wshift (wshift x 32) -62)))
(compiletime (put 'get_a_halfword 'opencode '(
   (!*move (displacement (reg 1) 0) (reg eax)))))

(de dumpfasl-relocate-word (code-location code-base id-table)
  (let ((reloc-tag (reloc-word-tag (get_a_halfword code-location)))
	(reloc-inf (reloc-word-inf (get_a_halfword code-location)))
	(hw (wand 16#ffffffff (get_a_halfword code-location)))
	(result))

    (printf "Relocate word at %d (%x): %d (%x) " code-location code-location hw hw)
    (setq result (dumpfasl-compute-relocation reloc-tag reloc-inf code-base id-table))
    (printf " --> %d (%x)%n" result result)
    ))

(de dumpfasl-relocate-inf  (code-location code-base id-table)
  (let ((reloc-tag  (wand (wshift (getmem code-location) -54) 3))
	(reloc-inf (reloc-inf-inf (getmem code-location)))
	(w (getmem code-location))
	(result))

    (printf "Relocate inf at %d (%x): %d (%x) " code-location code-location w w)
    (setf result
     (wor  (wshift (tag (getmem code-location)) 56)
      (dumpfasl-compute-relocation reloc-tag reloc-inf code-base id-table)
      ))
    (printf " --> %d (%x)%n" result result)
    )
)


(de dumpfasl-compute-relocation (reloc-tag reloc-inf code-base id-table)
    (printf "tag=%d(%w), inf=%d (%x) " reloc-tag
	    (case reloc-tag
		  ((reloc-code-offset) 'code-offset)
		  ((reloc-id-number) 'id-number)
		  ((reloc-value-cell) 'value-cell)
		  ((reloc-function-cell) 'function-cell))
	    reloc-inf reloc-inf)
  (cond
    ((eq reloc-tag reloc-code-offset) 
      (wplus2 code-base reloc-inf))
    ((eq reloc-tag reloc-value-cell) 
     (cond ((extraargumentp reloc-inf) 
	    (printf "extraargument %d (%x)" reloc-inf reloc-inf)
	    (loc (wgetv argumentblock
			(makeextraargument reloc-inf))))
	   ((local-id-number? reloc-inf)
	      (setq reloc-inf (local-to-global-id reloc-inf id-table))
	      (printf "ID #%d(%x): %w" reloc-inf reloc-inf (int2id reloc-inf))
              (wplus2 symval (wtimes2 addressingunitsperitem reloc-inf)) )
	   (t
	    (printf "ID #%d(%x): %w" reloc-inf reloc-inf (int2id reloc-inf))
	    (wplus2 symval (wtimes2 addressingunitsperitem reloc-inf)))))
    ((eq reloc-tag reloc-function-cell)
     (progn
      (when (local-id-number? reloc-inf)
	(setq reloc-inf (local-to-global-id reloc-inf id-table)))
      (printf "ID #%d(%x): %w" reloc-inf reloc-inf (int2id reloc-inf))
      (wplus2 symfnc                        %%% Should be (LOC (SYMFNC xxx)) ???
	      (wtimes2 addressingunitsperfunctioncell
		       reloc-inf)))) 
    ((eq reloc-tag reloc-id-number)
     (setq reloc-inf (if (local-id-number? reloc-inf)
			 (local-to-global-id reloc-inf id-table)
		       reloc-inf
		       ))
     (printf "ID #%d(%x): %w" reloc-inf reloc-inf (int2id reloc-inf))
     reloc-inf
     )
    ))

(de dumpfasl-read-id-table (fid)
  % Read in the table of local IDs at the front of the FASL file.
  % Each ID is stored as one word which holds the length, followed 
  % by the appropriate number of words holding the string.

  (let* ((local-id-count  (binaryread fid))
	 (id-table        (mkwrds (gtwrds (wplus2 local-id-count 1))))
         (readcount 1)
	 x
	 n)

    (printf "ID table has %d entries:%n" local-id-count)
    (for 
     (from i 0 local-id-count)
     (do (setf (wgetv tokenbuffer 0) (binaryread fid)) % word is length of ID name
         (setq readcount (add1 readcount))
     	 (setq n (strpack (wgetv tokenbuffer 0)))
	 (binaryreadblock fid
			  (loc (wgetv tokenbuffer 1)) 
			  n)
	 (setq readcount (plus2 readcount n))
	 (setq x (faslin-intern (mkstr (loc (wgetv tokenbuffer 0)))))
	 (printf "%d: %w - %d%n" i x (idinf x))
	 (setf (words-fetch id-table i) (idinf x))
	 ))
    (cons readcount id-table)
    ))

