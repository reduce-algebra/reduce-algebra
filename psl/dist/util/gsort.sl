%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:GSORT.SL 
% Description:  Sorting routines. 
% Author:       Cris Perdue, Hewlett-Packard CRC 
% Created:      28-Jul-83 
% Modified:     19 Jan 1984 1440-PST (Brian Beach) 
% Status:        Open Source: BSD License
% Mode:         Lisp 
% Package:      Utilities 
% Compiletime:  PL:IF.B 
% Runtime:      PL:MERGE-SORT.B PL:STRINGS.B 
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
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 19 Jan 1984 1440-PST (Brian Beach)
%   Added standard header.
% 01-Aug-83 17:19:10, Cris Perdue
%   Added stringsortfn, numbersortfn, and atomsortfn for stronger
%   backward compatibility.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  $Id$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


(compiletime (load if))

(imports '(merge-sort strings))

(de gsort (l fn)
  (natural-merge-sort (append l nil) fn))

(de gmergesort (l fn)
  (natural-merge-sort l fn))

(de idsort (l)
  (gsort l 'idsortfn))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% Please don't consider these as public: they are obsolete.  /csp
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de idsortfn (id1 id2)
  (string<= (id2string id1) (id2string id2)))

(de stringsortfn (s1 s2)
  (string<= s1 s2))

(de numbersortfn (x y)
  (leq x y))

(de atomsortfn (x y)
  %% Strings, then numbers, then IDs.
  %% Compatibility ho!
  (if (idp x) then
    (if (idp y) then (idsortfn x y)
      else nil)
    elseif (numberp x) then
    (if (idp y) then t
	elseif (numberp y) then (numbersortfn x y)
	else nil)
    elseif (stringp x) then
    (if (idp y) then t
      elseif (numberp y) then t
      else (stringsortfn x y))
    else nil))
