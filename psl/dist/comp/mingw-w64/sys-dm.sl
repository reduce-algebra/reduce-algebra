%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXC:SYS-DM.SL
% Title:        Lisp item constructors & selectors for 68000 Syslisp
% Author:       Eric Benson, University of Utah
% Created:	10-Jul-1981
% Modified:     21-Jun-84 (Vicki O'Day)
% Status:       Open Source: BSD License
% Mode:         Lisp
% Package:      Compiler
% Compile to:   PL:SYS-DM.B
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
% 20-Jun-89 (Winfried Neun)
% added symget access
% 21-Jun-84 (Vicki O'Day)
%  Made HP-UX corrections to system-list.  Took out constant declarations
%  that were duplicates of some in sys-consts.
% 04-Jun-84 12:52:35 (Brian Beach)
%  This file is now a separately compilable module which is loaded by data-machine.
% 17-Nov-83 (Brian Beach)
%   Translated to LISP from RLISP.  Cleaned up the macros some.
%
% 22-Jul-83  Nancy Kendzierski
%   Changed use of "autodecrement" (in a comment) to "predecrement".
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(load tags)

(define-constant *system-list* '(mc68000 chipmunk hpux200 unix))

(fluid '(symfnc))

% Retrieve the address stored in the function cell
(ds symfnc (function-cell)
  (getmem (wplus2 symfnc (wtimes2 function-cell 
				   addressingunitsperfunctioncell)
			  )))

% Can't really do PutSymFnc
(dm putsymfnc (u)
  '(stderror '"PutSymFnc does not exist on the i386"))

% access to SYMget vector
 
(dm Symget (U)
       (List 'wgetv 'Symget (cadr U)))
 
% Macros for building stack pointers
(ds makestackpointerfromaddress (u)
  u
  )

(ds makeaddressfromstackpointer (u)
  u
  )

(ds adjuststackpointer (pointer amount)
  (wdifference pointer amount)
  )

(loadtime 
 (put 'eof 'charconst (char (cntrl d)))
 (remprop 'adjuststackpointer 'openfn)
 )


(ds FloatHighOrder (address)
  (wgetv address 1))

(ds FloatLowOrder (address)
  (wgetv address 1))
