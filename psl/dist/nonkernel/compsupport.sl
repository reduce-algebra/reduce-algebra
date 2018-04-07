%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PNK:COMP-SUPPORT.SL
% Title:          Run-time support for assorted things
% Author:         Eric Benson
% Created:        20 September 1981
% Modified:       29-Aug-84 11:01:48 (Brian Beach)
% Status:         Open Source: BSD License
% Mode:           Lisp
% Package:        Kernel
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
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 01-Dec-83 14:23:53 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% NCONS, XCONS are defined in CONS-MKVECT.


(de list5 (u v w x y)
  % 5-argument EXPR for LIST
  (cons u (list4 v w x y)))

(de list4 (u v w x)
  % 4-argument EXPR for LIST
  (cons u (list3 v w x)))

(de list3 (u v w)
  % 3-argument EXPR for LIST
  (cons u (list2 v w)))

(de list2 (u v)
  % 2-argument EXPR for LIST
  (cons u (ncons v)))



%
% Support for WARRAYS:
%

(on fast-integers)

(de clear-warray (address size)
  (for (from index 0 (- size 1))
       (do (wputv address index 0))
       ))

(de initialize-warray (address initial-values)
  (for (in value initial-values)
       (from index 0)
       (do (wputv address index value))
       ))

(de clear-wstring (address char-count word-count)
  (clear-warray address word-count)
  (wputv address 0 (- char-count 1))
  )

(de initialize-wstring (address initial-string word-count)
  (let ((inf (strinf initial-string)))
    (for (from i 0 (- word-count 1))
	 (do (wputv address i (wgetv inf i)))
	 )))

(off fast-integers)
