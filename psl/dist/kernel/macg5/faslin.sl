%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PK:FASLIN.SL 
% Title:        Loading of binary format files. 
% Author:       E. Benson 
% Created:      ??? 
% Status:       Experimental 
% Mode:         Lisp 
% Package:      Kernel 
% Compiletime:  PL:FASL-DECLS.B 
% Runtime:      
%
% (c) Copyright 1983, Hewlett-Packard Company, all rights reserved.
% 
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 1-Nov-90  (Winfried Neun)
%  Initial version for IBM RS 6000
% 14-Jun-88 (Tsuyoshi Yamamoto)
%  Added new relocation types (relocate-movex,relocate-call) and long word
%  alignment for halfword access.
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

(compiletime (load fasl-decls)
(ds reloc-inf-tag (x) (field x 8 2))
(ds reloc-inf-inf (x) (field x 42 22))
)


(on fast-integers)

(fluid '(code-base-hack
	 symfnc
	 symval
	 tokenbuffer
	 argumentblock))

(compiletime (flag '(relocate-movex relocate-inf relocate-word read-id-table/de 
		     do-relocation relocate-right-half compute-relocation
		     local-to-global-id) 'internalfunction))


(de faslin (file)
  (prog (fid                  % file pointer 
	 local-id-count       % number of ids in the file
	 local-id-table       % table for mapping local ID numbers to global ID numbers.
	 code-size            % number of words of code
	 code-base            % location of the start of the code
	 init-function-address% Offset into the code of the init function
	 bit-table-size       % number of words in the bit table
	 bit-table            % the bit table
	 Btop
	 )

    % Open the file
    (setf fid (binaryopenread file))

    % Check that the first word is the correct magic number.
    (let ((first-word (binaryread fid)))
      (unless (weq first-word faslin-magic)
	(binaryclose fid)
	(faslin-bad-file file)
	(return nil)
	))

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
    (setq bit-table (gtwrds bit-table-size))
    (setq bit-table (mkwrds bit-table))
    (binaryreadblock fid (loc (words-fetch bit-table 0)) bit-table-size)

    % Close the file
    (binaryclose fid)

    % Twiddle the bits.
    (do-relocation code-base code-size bit-table local-id-table)

    % Call the init code
    (let ((temp code-base-hack))  % avoid use of fluid binding
      (setf code-base-hack code-base)
      (flushcache code-base (wdifference btop code-base) 0)
      (external_system (strbase (strinf "sync")))
      (addressapply0 init-function-address)
      (setf code-base-hack temp)
      (DelBPS (wplus2 init-function-address 4) Btop)
      )
    ))


(define-constant reloc-movex 1)
(define-constant reloc-call  2)
(define-constant reloc-xidloc 3)

(compiletime (put 'halfword_getmem 'opencode
                '((lwz (reg 1) (displacement (reg 1) 0)) ))
             (put 'halfword_putmem 'opencode
                '((stw (reg 2) (displacement (reg 1) 0)))))

(de do-relocation (code-base code-size bit-table id-table)
  % CODE-AU-SIZE is the size of the code measured in addressing
  % units, rather than words.

  (let ((code-au-size code-size )) %addressingunitsperitem)))
    (for (from i 0 (wshift (wdifference code-au-size 1) 3) 4)
     (do 
      (let ((bit-table-entry  (bittable (loc (words-fetch bit-table 0)) i))
	    (code-location    (wplus2 code-base i  ))	memo )
	(case bit-table-entry
	 ((reloc-word) 
	  (case (bittable (loc (words-fetch bit-table 0))
					 (wplus2 i 1))
	 	((0) (relocate-word code-location code-base id-table))
		((reloc-movex)
		    (relocate-movex code-location code-base id-table))
		((reloc-call)
		    (progn (setq memo (halfword_getmem code-location))
		            (setq memo 
		                (wplus2 memo (wshift (wshift code-base 6) -6)))
		                        %clear out first bits (see J instr!)
		                (halfword_putmem code-location memo)))
		((reloc-xidloc) 
		    (progn (setq memo (wand (halfword_getmem code-location)
					16#ffff))
		           (when (local-id-number? memo)
		               (setq memo (local-to-global-id memo id-table)))
		           (halfword_putmem code-location 
		             (wor (wand (halfword_getmem code-location)
					(wnot 16#ffff))
		             (wand (wtimes2 8  (wplus2 memo -4000)) 16#ffff)))
		      ))))
		     %
	((reloc-inf) (relocate-inf code-location code-base id-table))
	((reloc-right-half)
	       (relocate-right-half code-location code-base id-table))
))))))
		    
		     
(de relocate-word (code-location code-base id-table)
  (let ((reloc-tag (reloc-word-tag (halfword_getmem code-location)))
	(reloc-inf (reloc-word-inf (halfword_getmem code-location))))
    (cond ((posintp (halfword_getmem code-location))
			% a naked pointer from movex
	     (halfword_putmem  code-location
		 (wplus2 code-base (halfword_getmem code-location)) ))
	  (t (halfword_putmem code-location % an item
		(compute-relocation reloc-tag reloc-inf code-base id-table))))
      ))

(de relocate-inf  (code-location code-base id-table)
  (let ((reloc-tag (reloc-inf-tag (getmem code-location)))
	(reloc-inf (reloc-inf-inf (getmem code-location))))
    (putmem code-location
     (mkitem (tag (getmem code-location))
      (compute-relocation reloc-tag reloc-inf code-base id-table))
      )))
%
%
(de relocate-right-half (code-location code-base id-table)
  (let ((temp1 (halfword_getmem code-location))
	(temp2 nil))
       (setq temp2 (wand temp1 16#ffff))
       (cond ((local-id-number? temp2) 
		(setq temp2 (local-to-global-id temp2 id-table))
		(halfword_putmem code-location (wor (wand temp1 (wnot 16#ffff))
		                           temp2))))))
  

(de compute-relocation (reloc-tag reloc-inf code-base id-table)
  (case reloc-tag
    ((reloc-code-offset)  (wplus2 code-base reloc-inf ))
    ((reloc-value-cell) 
     (cond ((local-id-number? reloc-inf) 
	      (loc (symval (local-to-global-id reloc-inf id-table))))
	   (t (loc (symval reloc-inf)))))
    ((reloc-function-cell)
     (progn
      (when (local-id-number? reloc-inf)
	(setq reloc-inf (local-to-global-id reloc-inf id-table)))
      (wplus2 symfnc                      %%% Should be (LOC (SYMFNC xxx)) ???
	      (wtimes2 addressingunitsperfunctioncell reloc-inf))))
    ((reloc-id-number)
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
     (do (setf (wgetv tokenbuffer 0) (binaryread fid)) 
			% word is length of ID name
	 (binaryreadblock fid  (loc (wgetv tokenbuffer 1)) 
		               (strpack (wgetv tokenbuffer 0)))
	 (setf (words-fetch id-table i) 
	   (idinf (faslin-intern (mkstr (loc (wgetv tokenbuffer 0))))))
	 ))
    id-table
    ))

(de putentry (name type offset)
  % Called by the initcode.
  % CODE-BASE-HACK is set by FASLIN before the initcode is called.
  (putd name type (mkcode (wplus2 code-base-hack offset) )))

(de faslin-bad-file (name)    % To be redefined
  (console-print-string "File is not FASL format")
  (console-newline) )

(de relocate-movex (code-location code-base id-table)
    (let ((val (halfword_getmem (wplus2 code-location -4)))
	  (add (halfword_getmem code-location))
          (twentysix 26)
	  (lui nil))
	 (setq lui (wor (wshift 15 twentysix) % LIS instruction
		        (wor (wand (wshift val -16) 16#ffff)
		                  % pull the register out of next instr
		             (wshift (wand (wshift add -21) 16#1f) 21))))
	 (setq add (wor add (wand val 16#ffff)))
	 % adjust in case of not oril instruction
	 (when (and (eq 1 (wshift (wand val 16#ffff) -15))
		    (not (eq 24 (wshift add -26)))) % 24 is ORIL opcode
		        (setq lui (wplus2 1 lui)))
	 (halfword_putmem (wplus2 code-location -4) lui)
	 (halfword_putmem code-location add)))

(de delbps (bottom top)      % returns space to Bps

       (when (weq nextbps top)
            (flushcache bottom (wdifference nextbps bottom) 1)
            (setq nextbps bottom)))


(lap '((*entry flushcache expr 3)
       (icbi (reg 1) (reg r0)) % see instruction manual
       (*exit 0)))

(off fast-integers)
