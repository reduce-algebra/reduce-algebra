%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:HASH-DECLS-NEW.SL
% Description:  Declarations for access to the hash table for AMD64.
% Author:       Brian Beach, Hewlett-Packard CRC
% Created:      22-Feb-84
% Modified:     04-Apr-2006
% Mode:         Lisp
% Package:      
%
% (c) Copyright 2006, Hewlett-Packard Company, all rights reserved.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%
% Special values for labelling unoccupied slots:
%
(define-constant hash-table-size     1001003)
(define-constant maxsymbols          1000000)


(define-constant deleted-slot-value  16#fffffff)
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
       (and (wlessp hte 16#fffffff) (> hte 0))
  ))

%
% Assorted macros:
%
(deflist 
      '(
        (Hashtab-HalfWord ((shl 2 (reg 2))
                (mov (indexed (reg 2) (displacement (reg 1) 0))(reg EAX))
                    (cdqe)))
        (PutHashtab-HalfWord ((shl 2 (reg 2))
                (*move (reg 3) (reg 4))
                (mov (reg EDX)
		    (indexed (reg eax)(displacement (reg 2) 0)))))) 
 'OpenCode)

(put 'Hashtab-HalfWord 'assign-op 'PutHashtab-HalfWord)

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
  (wshift (wshift (Hashtab-halfword hashtable i) 32) -32) )

 % (signedfield (halfword hashtable i) 
%	       bitsperword2
%	       bitsperword2))
				         
(ds set-hash-table-entry (i x) 
  (setf (Hashtab-halfword hashtable i) x))

(put 'hash-table-entry 'assign-op 'set-hash-table-entry)
