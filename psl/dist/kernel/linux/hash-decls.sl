%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PK:HASH-DECLS.SL
% Description:  Declarations for access to the hash table.
% Author:       Brian Beach, Hewlett-Packard CRC
% Created:      22-Feb-84
% Modified:     04-Jun-84 09:13:06 (Brian Beach)
% Mode:         Lisp
% Package:      
% Status:       Open Source: BSD License
% Compile to:   PL:HASH-DECLS.B
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
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
	(and (< hte 16#ffff) (> hte 0)))
  )

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
  (field (halfword hashtable i) 
	       bitsperword2
	       bitsperword2))
				         
(ds set-hash-table-entry (i x) 
  (setf (halfword hashtable i) x))

(put 'hash-table-entry 'assign-op 'set-hash-table-entry)
