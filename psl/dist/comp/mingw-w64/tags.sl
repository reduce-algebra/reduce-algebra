%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXC:TAGS.SL
% Description:
% Author:
% Created:
% Modified:     25-Apr-84 08:49:24 (Brian Beach)
% Mode:         Lisp
% Package:
% Status:       Open Source: BSD License
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 19 Mar 1988 (Julian Padget)
%  Added tag declaration for stack group descriptors.
% 17 Aug 1986 (Julian Padget)
%  Added tag declarations for bvectors, bstructs, contexts and funargs.
% 25 Jun 1986 (Leigh Stoller)
%  This file needs to be recompiled on the host machine when porting with the
%   tagbitlength set to target machine's value. It then must be loaded into
%   the cross compiler as the last module.
% 28 Mar 1984 1536-PST (Nancy Kendzierski)
%  Fixed file name in header.
% 19 Dec 1983 1759-PST (Nancy Kendzierski)
%  Added header.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
(CompileTime
 
 (setq TagBitLength 8)

 (de DeclareTagRange (NameList StartingValue Increment)
   (let ((result '(PROGN)))
     (while NameList
       (setq Result (cons `(define-constant ,(first namelist) ,startingvalue)
              Result))
       (setq StartingValue (plus StartingValue Increment))
       (setq NameList (rest NameList)))
     (reverse result)
     ))
 
 (dm LowTags (U)
   (DeclareTagRange (cdr U) 0 1))
 
 (dm HighTags (U)
   (DeclareTagRange (cdr U)
            (difference (LSH 1 (compiler-constant 'TagBitLength)) 1)
            -1))
 )
 
 
%
% JumpInType and friends depend on the ordering and contiguity of
% the numeric type tags.  Fast arithmetic depends on PosInt = 0,
% NegInt = -1.  Garbage collectors depend on pointer tags being
% between PosInt and Code, non-inclusive. /csp
%
 
(lowtags posint-tag
     fixnum-tag
     bignum-tag
     floatnum-tag
     string-tag
     bytes-tag
     halfwords-tag
     words-tag
     vector-tag
     pair-tag
     evector-tag
%JAP: some new types for the new scheme
     bvector-tag
     context-tag
     funarg-tag
%JAP: and one for stack groups
         sgd-tag
%NB: we need to change code-tag if we add any more.
)
 
(define-constant code-tag 20)
 
(hightags negint-tag
      id-tag
      unbound-tag
      btr-tag
      forward-tag
      hvect-tag
      hwords-tag
      hhalfwords-tag
      hbytes-tag
%JAP: put the bstruct-tag here so GC won't follow it
      bstruct-tag
      )
 
