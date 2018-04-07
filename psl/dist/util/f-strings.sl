%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PU:F-STRINGS.SL
% Description:    Fast (unchecked) version of String Functions
% Author:         Alan Snyder, Hewlett-Packard CRC
% Created:        17 September 1982
% Modified:       29-Mar-84 14:29:46 (Brian Beach)
% Package:        Utilities
% Status:         Open Source: BSD License
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
% 10-Sep-88 (Tony Hearn)
%  Corrected misspelling of fast-string-empty?.
% 29-Mar-84 14:29:14 (Brian Beach)
%  Changed for new fast function model in compiler using FAST-FUNCTION property.
% 19 Jan 1984 1431-PST (Brian Beach)
%   Added standard header.
% 23 June 1983, Cris Perdue
%   Added fast-strings switch with enable and disable functions.
%   Now imports rather than loading slow-strings.
%   Makes fast-vector available at runtime, as really required.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Load this at compile-time to make compiled invocations of the following
% functions fast (and unchecked):
%
% (string-fetch s i)
% (string-store s i ch)
% (string-length s)
% (string-upper-bound s)
% (string-empty? s)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(imports '(s-strings fast-vector))

(put 'string-fetch       'fast-function  'igets)
(put 'string-store       'fast-function  'iputs)
(put 'string-length      'fast-function  'fast-string-length)
(put 'string-upper-bound 'fast-function  'isizes)
(put 'string-empty       'fast-function  'fast-string-empty?)

(put 'string-fetch       'fast-flag  '*fast-strings)
(put 'string-store       'fast-flag  '*fast-strings)
(put 'string-length      'fast-flag  '*fast-strings)
(put 'string-upper-bound 'fast-flag  '*fast-strings)
(put 'string-empty       'fast-flag  '*fast-strings)

(ds fast-string-length (string)
  (wplus2 1 (isizes string))
  )

(ds fast-string-empty? (string)
  (wlessp (isizes string) 0)
  )

(loadtime (on fast-strings))

% End of file.
