%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PVNK:SCAN-TABLE.SL
% Title:          Lisp character table for UNIX (Vax and HPUX200)
% Author:         Eric Benson
% Created:        27 November 1981
% Modified:       27-Feb-84 16:47:38 (RAM)
% Status:         Open Source: BSD License
% Mode:           Lisp
% Package:        Kernel
%
% (c) Copyright 1983,  Hewlett-Packard Company, all rights reserved.
% Copyright (c) 1981 Eric Benson
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
% 17-Jul-84 8:00 (Brian Beach)
%  EOF character no longer set at startuptime, set at load time.
% 27-Feb-84 16:47:08 (RAM)
%  Changed File and Title entries in header.
% 2-Dec-83  16:00:00 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  $Id$
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(lispscantable* currentscantable*))

(setq lispscantable*
      '[17 10 10 10 11 10 10 10 10 17 17 10 17 17 10 10 10 10 10 10 10 10
        10 10 10 10 10 10 10 10 10 10 17 14 15 10 10 12 10 11 11 11 10 19
        10 18 20 10 0 1 2 3 4 5 6 7 8 9 10 10 10 10 10 10 10 10 10 10 10
        10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10
        11 16 11 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10
        10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10
        10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10
        10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10
        10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10
        10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10
        10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10
        10 10 10 10 10 10 10 10 10 10 10 lispdiphthong])

(setq currentscantable* lispscantable*)

(put 'eof 'charconst (char (cntrl d)))

