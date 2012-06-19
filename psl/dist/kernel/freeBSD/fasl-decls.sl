%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PX:FASL-DECLS.SL
% Description:  Declarations used by FASLIN and FASLOUT
% Author:       Brian Beach, Hewlett-Packard CRC
% Created:      22-Feb-84
% Modified:     05-Sep-84 10:01:27 (Brian Beach)
% Mode:         Lisp
% Package:      
% Status:       Experimental (Do Not Distribute)
% Compile to:   PL:FASL-DECLS.B
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 11-Jul-84 08:05:20 (Brian Beach)
%  Moved to P68 directory, since this file is specific to the 68000 
%  implementations.
% 10-May-84 14:34:00 (Brian Beach)
%  Removed FASL magic number.  It now is in SYS-CONSTS.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%
% These constants are the tags of the relocation fields. They tell
% What the number in the inf field represents.
%

(define-constant reloc-code-offset   0)
(define-constant reloc-id-number     1)
(define-constant reloc-value-cell    2)
(define-constant reloc-function-cell 3)

%
% These constants go in the bit table to tell how long a field the relocator
% is to process:
%

(define-constant reloc-word       1)
(define-constant reloc-right-half 2)
(define-constant reloc-inf        3)

%
% Local ID's are represented in the code to be relocated as numbers over
% 2048, the number being 2048 greater that the index into the table of
% local ID's.

(define-constant first-local-id-number 2048)

(ds local-id-number? (u)
  (wgeq u first-local-id-number)
  )

%
% More weird constant stuff
%

(ds extraargumentp (u)
  (wgeq u 8150)
  )

(ds makeextraargument (u)
  (wdifference u (wplus2 8150 (wplus2 maxrealregs 1)))
  )

(define-constant bittable-entries-per-word 16)

(ds reloc-right-half-tag (x) (field x 0 2))
(ds reloc-right-half-inf (x) (field x 2 14))

(ds reloc-inf-tag (x) (field x 8 2))
(ds reloc-inf-inf (x) (field x 10 22))

(ds reloc-word-tag (x) (field x 0 2))
(ds reloc-word-inf (x) (field x 2 30))

  
