%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PU:F-VECTORS.SL
% Description:    Fast (unchecked) version of Vector Functions
% Author:         Alan Snyder, Hewlett-Packard CRC
% Created:        17 September 1982
% Modified:       15-Sep-84 14:06:22 (Brian Beach)
% Package:        Utilities
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
% 14-Sep-84 12:23:39 (Vicki O'Day)
%  Changed vector-upper-bound so it doesn't add 1 to size of vector,
%  and vector-size so it does.
% 29-Mar-84 14:11:09 (Brian Beach)
%  Changed for new fast function model in compiler using FAST-FUNCTION
%  property.
% 19 Jan 1984 1432-PST (Brian Beach)
%   Added standard header.
% 21-Jun-83 14:41:52, Cris Perdue
%   Added the fast-vectors switch with enable and disable functions.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Load this at compile-time to make compiled invocations of the following
% functions fast (and unchecked):
%
% (vector-fetch v i)
% (vector-store v i x)
% (vector-size v)
% (vector-upper-bound v)
% (vector-empty? v)
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(imports '(s-vectors		% For the interpreted versions
	   fast-vector))	% For machine-dependent primitives

(fluid '*fast-vectors)

(put 'vector-fetch        'fast-function   'igetv)
(put 'vector-store        'fast-function   'iputv)
(put 'vector-size         'fast-function   'fast-vector-size)
(put 'vector-upper-bound  'fast-function   'isizev)
(put 'vector-empty?       'fast-function   'fast-vector-empty?)

(put 'vector-fetch        'fast-flag   '*fast-vectors)
(put 'vector-store        'fast-flag   '*fast-vectors)
(put 'vector-size         'fast-flag   '*fast-vectors)
(put 'vector-upper-bound  'fast-flag   '*fast-vectors)
(put 'vector-empty?       'fast-flag   '*fast-vectors)

(ds fast-vector-size (vector) (wplus2 1 (isizev vector)))

(ds fast-vector-empty? (vector) (wlessp (isizev vector) 0))

(loadtime (on fast-vectors))

% End of file.
