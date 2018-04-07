%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:S-STRINGS.SL 
% Description:  Useful String Functions (with lots of error checking) 
% Author:       Alan Snyder 
% Created:      17 September 1982 
% Modified:     26 Jan 1984 1603-PST (Brian Beach) 
% Package:      NMODE Utilities 
% Status:       Open Source: BSD License
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 26 Jan 1984 1603-PST (Brian Beach)
%  Corrected file name in header.
% 30 Nov 83 (Cris Perdue)
%   Added assign-op for string-fetch.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Defines the following functions:
%
% (string-fetch s i)
% (string-store s i ch)
% (string-length s)
% (string-upper-bound s)
% (string-empty? s)
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de string-fetch (s i)
  (cond ((not (StringP s)) (NonStringError s 'String-Fetch))
	((not (FixP i)) (NonIntegerError i 'String-Fetch))
	(t (indx s i))
	))

(put 'string-fetch 'assign-op 'string-store)
% Apparently not setf-safe, at least not in the fast case. /csp

(de string-store (s i c)
  (cond ((not (StringP s)) (NonStringError s 'String-Store))
	((not (FixP i)) (NonIntegerError i 'String-Store))
	((not (FixP c)) (NonCharacterError c 'String-Store))
	(t (setindx s i c))
	))

(de string-length (s)
  (cond ((not (StringP s)) (NonStringError s 'String-Length))
	(t (Plus2 (size s) 1))
	))

(de string-upper-bound (s)
  (cond ((not (StringP s)) (NonStringError s 'String-Upper-Bound))
	(t (size s))
	))

(de string-empty? (s)
  (cond ((not (StringP s)) (NonStringError s 'String-Empty?))
	(t (EqN (size s) -1))
	))

% End of file.

