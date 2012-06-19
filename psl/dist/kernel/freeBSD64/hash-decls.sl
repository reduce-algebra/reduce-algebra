%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PK:HASH-DECLS.SL
% Description:  Declarations for access to the hash table.
% Author:       Brian Beach, Hewlett-Packard CRC
% Created:      22-Feb-84
% Modified:     04-Jun-84 09:13:06 (Brian Beach)
% Mode:         Lisp
% Package:      
% Status:       Experimental (Do Not Distribute)
% Compile to:   PL:HASH-DECLS.B
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%
% Special values for labelling unoccupied slots:
%

(define-constant deleted-slot-value  16#ffff)
(define-constant empty-slot-value    0)

%
% Predicates for unoccupied slots:
%

(ds deleted-slot? (u)
  (weq (hash-table-entry u) deleted-slot-value))

(ds empty-slot? (u)
  (weq (hash-table-entry u) empty-slot-value))

(ds occupied-slot? (u) 
  (let ((hte (hash-table-entry u)))
       (and (wlessp hte 16#ffff) (> hte 0))
  ))

%
% Assorted macros:
%

(ds next-slot (h)
  % Increment to the next slot in the hash table, wrapping around at the end.
  (if (eq h hash-table-size)
    0
    (wplus2 h 1)))

(ds equal-hash-entry (hash-index s) 
  % Compare the name of the ID at HASH-INDEX with S.
  (unchecked-string-equal (symnam (hash-table-entry hash-index)) s))

(ds hash-table-entry (i) 
  % Access to an element of the hash table.
  (wshift (wshift (halfword hashtable i) 48) -48) )

 % (signedfield (halfword hashtable i) 
%	       bitsperword2
%	       bitsperword2))
				         
(ds set-hash-table-entry (i x) 
  (setf (halfword hashtable i) x))

(put 'hash-table-entry 'assign-op 'set-hash-table-entry)
