%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%##
%
% File:         PK:FASLIN.SL 
% Title:        Loading of binary format files. 
% Author:       E. Benson 
% Created:      ??? 
% Modified:     10-Jan-84 13:30 (Brian Beach)
% Status:       Experimental 
% Mode:         Lisp 
% Package:      Kernel 
% Compiletime:  PL:FASL-DECLS.B 
% Runtime:      
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 10-Jan-84 (Brian Beach)
%  Commented-in checking of fasl-magic-number.
% 13-Nov-84 14:13:11 (Brian Beach)
%  Moved FASLIN-INTERN to INTERN.SL.
% 10-May-84 14:35:05 (Brian Beach)
%  Changed fasl-magic-number to faslin-magic (which is defined now in SYS-CONSTS.)
% 01-Dec-83 14:44:33 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load fasl-decls))

(on fast-integers)

(fluid '(code-base-hack
	 symfnc
	 symval
	 kernel-maxsymbols
	 tokenbuffer
	 argumentblock))

(de faslin (file)
  (prog (fid                  % file pointer 
	 local-id-count       % number of ids in the file
	 local-id-table       % table for mapping local ID numbers to global ID numbers.
	 code-size            % number of words of code
	 code-base            % location of the start of the code
	 init-function-address% Offset into the code of the init function
	 bit-table-size       % number of words in the bit table
	 bit-table            % the bit table
	 mode                 % magic number
	 Btop
	 )

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

    % Read in the ID table.
    (setf local-id-table (read-id-table fid))

    % Read the code.
    (setf code-size (binaryread fid)) % Size of code segment in words
    (setf code-base (gtbps code-size)) % Allocate space in BPS
    (setq Btop (GtBPS 0))              % pointer to top of alloc. BPS
    (setf init-function-address (wplus2 code-base (binaryread fid)))
    (binaryreadblock fid (loc (wgetv code-base 0)) code-size)

    % Read the bit table
    (setf bit-table-size (binaryread fid))
    (setq bit-table (mkwrds (gtwrds bit-table-size)))
    (binaryreadblock fid (loc (words-fetch bit-table 0)) bit-table-size)

    % Close the fil
    (binaryclose fid)

    % Twiddle the bits

    (if (weq (wand mode 1) 1)
	(do-relocation-new code-base code-size bit-table local-id-table)
	(do-relocation code-base code-size bit-table local-id-table))

    % Call the init code
    (let ((temp code-base-hack))  % avoid use of fluid binding
      (setf code-base-hack code-base)

      (addressapply0 init-function-address)
      (setf code-base-hack temp)
      (DelBPS init-function-address btop)
      )
    ))

(de delbps (x y) nil) %to be redefined

(de do-relocation (code-base code-size bit-table id-table)
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
	       (relocate-word code-location code-base id-table))
	      ((reloc-inf) 
	       (relocate-inf code-location code-base id-table))
	      ((reloc-right-half)
	       (relocate-right-half code-location code-base id-table))
	      ))))))
		    
(de do-relocation-new (code-base code-size bit-table id-table)
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
	       (relocate-word code-location code-base id-table))
	      ((reloc-inf) 
	       (relocate-inf code-location code-base id-table))
	      ((reloc-right-half)
	       (relocate-right-half code-location code-base id-table))
	      ))))
		    
		     

(compiletime (ds reloc-word-inf (x) (wshift (wshift x 34) -34)))
(compiletime (ds reloc-word-tag (x) (wshift (wshift x 32) -62)))
(compiletime (put 'put_a_halfword 'opencode '
   ((mov  "%ebx" "0(%rax)")))) %% (reg 2) (displacement (reg rax) 0))))
(compiletime (put 'get_a_halfword 'opencode '
   ((!*move (displacement (reg 1) 0) (reg eax)))))

(de relocate-word (code-location code-base id-table)
  (let ((reloc-tag (reloc-word-tag (get_a_halfword code-location)))
	(reloc-inf (reloc-word-inf (get_a_halfword code-location))
        tempo))

    (put_a_halfword code-location
     (progn
      (setq tempo
      (compute-relocation reloc-tag reloc-inf code-base id-table))
      (if (or (eq reloc-tag reloc-value-cell)
          (eq reloc-tag reloc-code-offset)
          (eq reloc-tag reloc-function-cell))
         (wdifference tempo (wplus2 4 code-location)) tempo)))
      ))

(de relocate-inf  (code-location code-base id-table)
  (let ((reloc-tag  (wand (wshift (getmem code-location) -54) 3))
	(reloc-inf (reloc-inf-inf (getmem code-location))
        tempo))

    (setf (getmem code-location)
     (wor  (wshift (tag (getmem code-location)) 56)
      (progn (setq tempo
		(compute-relocation reloc-tag reloc-inf code-base id-table))
       %  (if (or (eq reloc-tag reloc-value-cell)
       %   			(eq reloc-tag reloc-function-cell))
       %  (wdifference tempo code-location) tempo)
        tempo)

      ))))



(commentoutcode de relocate-right-half (code-location code-base id-table)
  (let ((reloc-tag (reloc-right-half-tag (getmem code-location)))
	(reloc-inf (reloc-right-half-inf (getmem code-location))))
    (setf (righthalf (getmem code-location))
      (compute-relocation reloc-tag reloc-inf code-base id-table)
      )))

(de compute-relocation (reloc-tag reloc-inf code-base id-table)
  (cond
    ((eq reloc-tag reloc-code-offset) 
      (wplus2 code-base reloc-inf))
    ((eq reloc-tag reloc-value-cell) 
     (cond ((extraargumentp reloc-inf) 
	    (loc (wgetv argumentblock
			(makeextraargument reloc-inf))))
	   ((local-id-number? reloc-inf)
	      (setq reloc-inf (local-to-global-id reloc-inf id-table))
              (wplus2 symval (wtimes2 addressingunitsperitem reloc-inf))) 
	   (t (wplus2 symval (wtimes2 addressingunitsperitem reloc-inf)))))
    ((eq reloc-tag reloc-function-cell)
     (progn
      (when (local-id-number? reloc-inf)
	(setq reloc-inf (local-to-global-id reloc-inf id-table)))
      (wplus2 symfnc                        %%% Should be (LOC (SYMFNC xxx)) ???
	      (wtimes2 addressingunitsperfunctioncell
		       reloc-inf)))) 
    ((eq reloc-tag reloc-id-number)
     (if (local-id-number? reloc-inf)
       (local-to-global-id reloc-inf id-table)
       reloc-inf
       ))
    ))

(de local-to-global-id (local-id-number id-table)
  (words-fetch id-table (wdifference local-id-number 2048))
  )

(de read-id-table (fid)
  % Read in the table of local IDs at the front of the FASL file.
  % Each ID is stored as one word which holds the length, followed 
  % by the appropriate number of words holding the string.

  (let* ((local-id-count  (binaryread fid))
	 (id-table        (mkwrds (gtwrds (wplus2 local-id-count 1)))))

    (for 
     (from i 0 local-id-count)
     (do (setf (wgetv tokenbuffer 0) (binaryread fid)) % word is length of ID name
	 (binaryreadblock fid
			  (loc (wgetv tokenbuffer 1)) 
			  (strpack (wgetv tokenbuffer 0)))
	 (setf (words-fetch id-table i) 
	   (idinf (faslin-intern (mkstr (loc (wgetv tokenbuffer 0))))))
	 ))
    id-table
    ))

(de putentry (name type offset)
  % Called by the initcode.
  % CODE-BASE-HACK is set by FASLIN before the initcode is called.
  (putd name type (mkcode (wplus2 code-base-hack offset))))

(de faslin-bad-file (name)    % To be redefined
  (console-print-string "File is not FASL format")
  (console-newline)
  )

(off fast-integers)

)
