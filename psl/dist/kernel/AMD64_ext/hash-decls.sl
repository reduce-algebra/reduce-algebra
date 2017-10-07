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

%%(define-constant hash-table-size     786433)
%%(define-constant maxsymbols          650000)

(define-constant hash-table-size     393241)
(define-constant maxsymbols          300000)

%%(define-constant hash-table-size     1572869)
%%(define-constant maxsymbols          1000000)

%
% Special values for labelling unoccupied slots:
%

(define-constant deleted-slot-value  16#ffffffff)
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
       (and (wlessp hte 16#ffffffff) (> hte 0))
  ))

%
% Compiler macros for reading and writing 32bit words:
%

(deflist 
      '(
        (Hashtab-HalfWord ((shl 2 (reg 2))
                (mov (indexed (reg 2) (displacement (reg 1) 0))(reg EAX))
                    (cdqe)))
        (PutHashtab-HalfWord ((shl 2 (reg 2))
                (*move (reg 3) (reg 4))
                (mov (reg EDX)
                    (indexed (reg 1)(displacement (reg 2) 0)))))) 
 'OpenCode)

(put 'Hashtab-HalfWord 'assign-op 'PutHashtab-HalfWord)

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
  (wshift (wshift (Hashtab-halfword hashtable i) 32) -32) )

 % (signedfield (halfword hashtable i) 
%	       bitsperword2
%	       bitsperword2))
				         
(ds set-hash-table-entry (i x) 
  (setf (Hashtab-halfword hashtable i) x))

(put 'hash-table-entry 'assign-op 'set-hash-table-entry)
