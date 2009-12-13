%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PK:INTERN.SL 
% Description:  Interning of symbols for the kernel. 
% Author:       Brian Beach, Hewlett-Packard CRC 
% Created:      16-Feb-84 
% Modified:     13-Nov-84 14:35:11 (Brian Beach) 
% Package:      
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 31-Aug-88 (Julian Padget)
%  Changed first "fluid" call to "global" since there was no need of former.
% 12-Dec-84 20:30 (Brian Beach)
%  Added missing STRINF in UNCHECKED-STRING-INTERN.
% 13-Nov-84 14:03:50 (Brian Beach)
%  Added changes to include the PKG-FASL hack.  Added function FASLIN-INTERN
%  which searches for a null in the name of an ID, and only looks at the part
%  of the name after the null.
% 11-Jul-84 08:04:48 (Brian Beach)
%  Minor cleanup.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


(compiletime (load hash-decls f-strings))

(on fast-integers fast-strings)

(global '(nextsymbol show-new-ids))

(de initialize-symbol-table ()
  % Initialize the symbol table. SYMNAM, SYMFNC, SYMVAL, and SYMPRP 
  % have been filled in for all defined symbols by the cross compiler.
  % We need to create the linked list for the unused symbols in SYMNAM,
  % and set up the hash table.  

  (for (from i nextsymbol maxsymbols)
       (do (setf (symnam i) (+ i 1))))
  (setf (symnam maxsymbols) 0)

  (for (from i 0 hash-table-size)
       (do (setf (hash-table-entry i) empty-slot-value)))
  (for (from i 128 (- nextsymbol 1))  % Don't intern single character IDs
       (do (setf (hash-table-entry (hash-into-table (symnam i))) i)))
  (setf show-new-ids nil)
  )

(de faslin-intern (string)

  % A simple routine to remove package information from the name being
  % interned by FASLIN.  This function will be redefined when the package
  % system is loaded.

  (let ((pos (search-string-for-character (char null) string)))
    (if (not pos)
      (intern string)
      % else
      (let ((bound (string-upper-bound string)))
	(when (and (> bound pos)
		   (= (string-fetch string (+ pos 1)) (char null)))
	  % It's an internal symbol (two nulls in a row)
	  (setf pos (+ pos 1))
	  )
	% Do something with case of nulls at end of string
	% including the ID that has only null in its name.
	(intern
	 (if (>= pos bound)
	   string
	   (subseq string (+ pos 1) (string-length string))
	   ))))))

(de intern (x)                 % To be redefined
  (unchecked-string-intern x)
  )

(de unchecked-string-intern (name)
  %
  % NAME is a String, which IS copied if it is not found on the hash table
  % The interned ID with NAME as print name is returned.
  %
  (let ((string-inf (strinf name))
	(string-len (strlen (strinf name)))
	hash-table-index
	bps-string
	new-id)
    (if (= string-len 0)
      (mkid (strbyt string-inf 0))
      (if (occupied-slot? (setq hash-table-index (hash-into-table name)))
	(mkid (hash-table-entry hash-table-index))
	(progn 
	 (when show-new-ids
	   (console-print-string "New id: ")
	   (console-print-string name)
	   (console-newline)
	   )
	 (setq new-id (gtid)) % allocate a new ID
	 (setf (hash-table-entry hash-table-index) new-id) % plant it in the hash table
	 (setq bps-string (gtconststr string-len)) % allocate a string from uncollected space
	 (copystringtofrom bps-string string-inf)
	 (initialize-new-id new-id (mkstr bps-string))
	 )))))

(de hash-into-table (name)
  % NAME is a string.  Returns a hash table index.
  (prog (hash-value walk-table del-slot)
    (setf hash-value (hash-function name))
    (setf walk-table hash-value)
    (setf del-slot -1)
    loop
    (cond ((empty-slot? walk-table) 
	   (return (if (wneq del-slot -1)
		     del-slot
		     walk-table)))
	  ((deleted-slot? walk-table)
	   (when (weq del-slot -1) (setq del-slot walk-table)))
	  ((equal-hash-entry walk-table name)
	   (return walk-table)))
    (setq walk-table (next-slot walk-table))
    (when (weq walk-table hash-value)
      (kernel-fatal-error "Hash table overflow"))
    (go loop)))

(de initialize-new-id (id-number print-name)
  % Initialize cells of an ID to defaults                                  
  (let ((id (mkid id-number)))
    (setf (symnam id-number) print-name)
    (setf (symprp id-number) nil)
    (setf (symval id-number) (mkitem unbound-tag id-number))
    (plantunbound id-number)
    id
    ))

(de hash-function (s)
  % Compute hash function of string.  The value is computed by folding together
  % a bunch of bits from the first BITSPERWORD - 8 characters of the string.

  (let* ((inf     (strinf s))
	 (len     (strlen inf))
	 (result  0))
    (when (> len (- bitsperword 8))
      (setq len (- bitsperword 8)))
    (for (from i 0 len) 
	 (do (setf result 
	       (^ result (<< (strbyt inf i) 
			     (- (- bitsperword 8) i))))))
    (wremainder result hash-table-size)
    ))

(off fast-integers)

% End of file.
