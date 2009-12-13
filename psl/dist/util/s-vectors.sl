%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:S-VECTORS.SL 
% Description:  Useful Vector Functions (with lots of error checking) 
% Author:       Alan Snyder 
% Created:      17 September 1982 
% Modified:     26 Jan 1984 1603-PST (Brian Beach) 
% Package:      NMODE Utilities 
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
% 26 Jan 1984 1603-PST (Brian Beach)
%  Corrected file name in header.
% 30 Nov 83 (Cris Perdue)
%   Added assign-op for vector-fetch.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Defines the following functions:
%
% (vector-fetch v i)
% (vector-store v i x)
% (vector-size v)
% (vector-upper-bound v)
% (vector-empty? v)
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de vector-fetch (v i)
  (cond ((not (Vectorp v)) (NonVectorError v 'Vector-Fetch))
	((not (FixP i)) (NonIntegerError i 'Vector-Fetch))
	(t (indx v i))
	))

(put 'vector-fetch 'assign-op 'vector-store)
(flag1 'vector-fetch 'setf-safe)
% Apparently setf-safe, analagous to igetv. /csp

(de vector-store (v i x)
  (cond ((not (Vectorp v)) (NonVectorError v 'Vector-Store))
	((not (FixP i)) (NonIntegerError i 'Vector-Store))
	(t (setindx v i x))
	))

(de vector-size (v)
  (cond ((not (Vectorp v)) (NonVectorError v 'Vector-Size))
	(t (Plus2 (size v) 1))
	))

(de vector-upper-bound (v)
  (cond ((not (Vectorp v)) (NonVectorError v 'Vector-Upper-Bound))
	(t (size v))
	))

(de vector-empty? (v)
  (cond ((not (Vectorp v)) (NonVectorError v 'Vector-Empty?))
	(t (EqN (size v) -1))
	))

% End of file.

