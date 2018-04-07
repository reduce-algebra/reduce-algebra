%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PC: COMMON-PREDICATES.SL
% Title:          Predicates used for Anyreg and C-macro expansion
% Author:         Eric Benson
% Created:        21 December 1981
% Modified:       11-Sep-84 08:24:54 (Brian Beach)
% Status:         Open Source: BSD License
% Mode:           Lisp
% Package:        
% Compile to:     none
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 06-Dec-83 10:00 (Brian Beach)
%   New header.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%

(fluid '(EntryPoints!*
	 !*FastLinks))

(global '(!*R2I))

(de RegisterP (Expression)
  (EqCar Expression 'REG))

(de AnyP (Expression)
  T)

(de TaggedLabel (X)
  (EqCar X 'Label))

(de EqTP (Expression)
  (equal Expression T))

(de MinusOneP (Expression)
  (equal Expression -1))

(de InternallyCallableP (X)		% only when writing a file
  (and (or !*WritingFaslFile (not (FUnBoundP 'AsmOut)))
       (or !*FastLinks
	   (and !*R2I (memq X EntryPoints!*))
	   (FlagP X 'InternalFunction)
	   (FlagP X 'FastLink))))

(de AddressConstantP (Expression)
  (or (atom Expression) (equal (car Expression) 'Immediate)))
