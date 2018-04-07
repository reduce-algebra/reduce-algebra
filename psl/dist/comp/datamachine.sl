%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PC:DATA-MACHINE.SL 
% Title:        Macros for fast access to data structures 
% Author:       Eric Benson, University of Utah 
% Created:      5-Apr-82 
% Modified:     29-Oct-84 (Brian Beach) 
% Status:       Open Source: BSD License
% Mode:         Lisp 
% Package:      Compiler 
% Compile to:   PL:DATA-MACHINE.B 
% Compiletime:  PL:SYS-DM.B PL:IF-SYSTEM.B 
% Runtime:      PL:SYS-CONSTS.B PL:SYS-DM.B 
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
% 4 Dec 1984 1040-PST (Brian Beach)
%  Removed SETF-SAFE flag on FIELD.  On the DEC-20 and Vax it is not.
% 29-Oct-84 (Brian Beach)
%  Added VECBASE and WRDBASE.
% 04-Jun-84 12:50:06 (Brian Beach)
%  Removed IF_SYSTEM.  Added module SYS-DM for system-specific stuff.
% 25-Apr-84 08:53:18 (Brian Beach)
%  Added Cris's changes: removed tags, added load of sys-consts.
% 1-Mar-84 10:00:00 (Brian Beach)
%  Replaces WARRAYS, WVARS by fluids.
% 22-Nov-83 (Brian Beach)
%  Translated from RLISP to LISP.  Removed definitions for open-coded
%  functions that were commented out.  Changed symbal table macros
%  (SYMVAL, PUTSYMVAL, etc), to use WARRAY prefix.  Changed OBARRAY
%  macro to use WCONST prefix.  Made macros more readable by using
%  substitution macros.  Added appropriate SETF-SAFE flags so that 
%  the SETF in useful can be used.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(symnam symval symprp symfnc hashtable))

(imports '(sys-consts sys-dm))

(compiletime (load sys-dm if-system))

%
% SysLisp array accessing primitives
%

(ds wgetv (address index) 
  (getmem (wplus2 address
		  (wtimes2 index AddressingUnitsPerItem)
		  )))

(ds wputv (address index value) 
  (putmem (wplus2 address
		  (wtimes2 index AddressingUnitsPerItem)
		  )
	  value
	  ))

%
% Item constructor macros
%

(ds MkBTR (inf-field) 
  (MkItem btr-tag inf-field))

(ds MkID (inf-field) 
  (MkItem ID-tag inf-field))

(ds MkFIXN (inf-field) 
  (MkItem FixNum-tag inf-field))

(ds MkFLTN (inf-field) 
  (MkItem FloatNum-tag inf-field))

(ds MkBIGN (inf-field) 
  (MkItem BigNum-tag inf-field))

(ds MkPAIR (inf-field) 
  (MkItem Pair-tag inf-field))

(ds MkVEC (inf-field) 
  (MkItem Vector-tag inf-field))

(ds MkEVECT (inf-field) 
  (MkItem Evector-tag inf-field))

(ds MkWRDS (inf-field) 
  (MkItem Words-tag inf-field))

(ds MkSTR (inf-field) 
  (MkItem String-tag inf-field))

(ds MkBYTES (inf-field) 
  (MkItem Bytes-tag inf-field))

(ds MkHalfWords (inf-field) 
  (MkItem HalfWords-tag inf-field))

(ds MkCODE (inf-field) 
  (MkItem Code-tag inf-field))

%
% Access to tag (type indicator) of Lisp item in ordinary code
%

(ds Tag (item) 
  (Field item TagStartingBit TagBitLength)
  )


%
% Access to info field of item (pointer or immediate operand)
%

(ds Inf (item) 
  (Field item  InfStartingBit InfBitLength))


(ds PutInf (item value) 
  (PutField item InfStartingBit InfBitLength value)
  )

(foreach x in '(IDInf StrInf VecInf EVecInf PairInf WrdInf HalfWordInf CodeInf 
		FixInf FltInf BigInf) do 
    (PutD x 'macro (cdr (GetD 'Inf))))

(foreach x in '(PutIDInf PutStrInf PutVecInf PutPairInf PutWrdInf 
		PutHalfWordInf PutEVecInf 
		PutFixInf PutFltInf PutBigInf) do 
    (PutD x 'macro (cdr (GetD 'PutInf))))

% IntInf is no longer needed, will be a macro no-op
% for the time being

(RemProp 'IntInf 'OpenFn)

(ds IntInf (x) 
    x)

% Similarly for MkINT

(ds MkINT (x) 
    x)

% Sizes of some simple types:

(ds pairpack  () 2)
(ds fixpack   () 1)
(ds floatpack () 2)

% length (in characters, words, etc.) of a string, vector, or whatever,
% stored in the first word pointed to

(ds GetLen (vector-address) 
  (signedfield (getmem vector-address)
	       infstartingbit
	       infbitlength
	       ))

(ds StrBase (string-address)                         % point to chars of string
  (wplus2 string-address addressingunitsperitem)
  )

(ds StrPack (upperbound) 
  % Returns the number of items required to store a string, including
  % the one-item header.  Note that indexing starts at zero, and all
  % strings have a trailing zero byte.  Thus, a string with an upper
  % bound of 3 will require 5 bytes of storage past the header.
  (wquotient (wplus2 upperbound
		     (wplus2 CharactersPerWord 1)
		     )
	     CharactersPerWord
	     ))

%
% access to bytes of string; skip first word
%

(ds StrByt (address index) 
  (byte (wplus2 address AddressingUnitsPerItem)
	index
	))

(ds PutStrByt (address index value) 
  (putbyte (wplus2 address AddressingUnitsPerItem)
	   index
	   value
	   ))

%
% access to halfword entries; skip first word
%

(ds HalfWordItm (address index) 
  (halfword (wplus2 address AddressingUnitsPerItem)
	    index
	    ))

(ds PutHalfWordItm (address index value) 
  (puthalfword (wplus2 address AddressingUnitsPerItem)
	       index
	       value
	       ))

%
% halfword length --> words  length
%

(ds HalfWordPack (upperbound) 
  (wplus2 (wshift upperbound -1) 1)
  )

%
% length (in Item size quantities) of Lisp vectors
%
% size of Lisp vector in words

(ds VectPack (upperbound) 
  (wplus2 upperbound 1)
  )

% size of Lisp Evector in words

(ds EVectPack (upperbound) 
    (wplus2 upperbound 1)
    )

% access to elements of Lisp vector

(ds VecItm (address index) 
  (wgetv address (wplus2 index 1))
  )

(ds PutVecItm (address index value) 
  (wputv address (wplus2 index 1) value)
  )

(ds VecBase (address)
  (wplus2 address addressingunitsperitem)
  )

% access to elements of Lisp Evector

(ds EVecItm (address index) 
  (wgetv address (wplus2 index 1))
  )

(ds PutEVecItm (address index value) 
  (wputv address (wplus2 index 1) value)
  )

% Wrd is like Vect, but not traced by the garbage collector

(ds WrdPack (upperbound)
  (wplus2 upperbound 1)
  )

(foreach x in '(StrLen ByteLen VecLen EVecLen WrdLen HalfWordLen) do 
    (PutD x 'macro (cdr (GetD 'GetLen))))

(PutD 'WrdItm    'macro (cdr (GetD 'VecItm)))

(PutD 'PutWrdItm 'macro (cdr (GetD 'PutVecItm)))

(PutD 'WrdBase   'macro (cdr (GetD 'VecBase)))

(ds words-fetch (words index)
  (wgetv (wrdinf words) (wplus2 index 1))
  )

(ds words-length (words)
  (inf (wgetv (wrdinf words) 0))
  )

(ds righthalf (x)
  (field x 0 16)
  )


(ds FixVal (address) 
  (wgetv address 1)
  )

(ds PutFixVal (address value) 
  (wgetv address 1 value)
  )

(ds FloatBase (address) 
  (wplus2 address AddressingUnitsPerItem)
  )

(ds FloatHighOrder (address) 
  (wgetv address 1)
  )

(ds FloatLowOrder (address) 
  (wgetv address 2)
  )

% New addition: A code pointer can have the number of arguments it expects
% stored in the word just before the entry 

(ds !%code-number-of-arguments (address)
  (wgetv address -1)
  )

% The four basic cells for each symbol: Val, Nam, Fnc, Prp, corresponding to
% variable value, symbol name (as string), function cell (jump to compiled
% code or lambda linker) and property list (pairs for PUT, GET, atoms for FLAG,
% FLAGP).  These are currently 4 separate arrays, but this representation may
% be changed to a contiguous 4 element record for each symbol or something else
% and therefore should not be accessed as arrays.

(ds symval (index)
  (wgetv symval index)
  )

(ds putsymval (index value)
  (wputv symval index value)
  )

(ds symnam (index)
  (wgetv symnam index)
  )

(ds putsymnam (index value)
  (wputv symnam index value)
  )

% SymFnc and PutSymFnc are not defined portably

(ds symprp (index)
  (wgetv symprp index)
  )

(ds putsymprp (index value)
  (wputv symprp index value)
  )

% Binding stack primitives

(ds BndStkID (bind-pointer) 
  (wgetv bind-pointer -1)
  )

(ds PutBndStkID (bind-pointer value) 
  (wputv bind-pointer -1 value))

(ds BndStkVal (bind-pointer) 
  (GetMem bind-pointer)
  )

(ds PutBndStkVal (bind-pointer value) 
  (PutMem bind-pointer value)
  )

(ds AdjustBndStkPtr (bind-pointer offset) 
  (wplus2 bind-pointer
	  (wtimes2 offset
		   (wtimes2 AddressingUnitsPerItem 2)
		   )))
(DefList '((GetMem   PutMem) 
	   (Field    PutField) 
	   (Byte     PutByte) 
	   (HalfWord PutHalfWord))      'Assign-Op)

(flag '(GetMem)  'setf-safe)

(if_system MC68000 (flag '(field) 'setf-safe))
