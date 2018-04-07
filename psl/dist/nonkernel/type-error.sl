%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:           PNK:TYPE-ERRORS.SL
% Title:          Error handlers for common type mismatches
% Author:         Eric Benson
% Created:        15 September 1981
% Modified:       29-Aug-84 11:01:14 (Brian Beach)
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 01-Dec-83 15:04:40 (Brian Beach)
%   Translated from Rlisp to Lisp.
%
% Edit by Cris Perdue, 21 Apr 1983 1339-PST
% Added NonListError, NonWords --> NonWordsError
% Edit by Cris Perdue, 27 Jan 1983 1621-PST
% Added NonIOChannelError
%  <PSL.INTERP>TYPE-ERRORS.RED.6, 20-Jan-82 03:10:00, Edit by GRISS
%  Added NonWords Error
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(de typeerror (offender fn typ)
  (stderror (bldmsg "An attempt was made to do %p on %r, which is not %w"
                    fn offender typ)))

(de usagetypeerror (offender fn typ usage)
  (stderror (bldmsg "An attempt was made to use %r as %w in %p, where %w is needed"
                    offender usage fn typ)))

(de indexerror (offender fn)
  (usagetypeerror offender fn "an integer" "an index"))

(de nonpairerror (offender fn)
  (typeerror offender fn "a pair"))

(de nonlisterror (offender fn)
  (typeerror offender fn "a list or NIL"))

(de noniderror (offender fn)
  (typeerror offender fn "an identifier"))

(de nonnumbererror (offender fn)
  (typeerror offender fn "a number"))

(de nonintegererror (offender fn)
  (typeerror offender fn "an integer"))

(de nonpositiveintegererror (offender fn)
  (typeerror offender fn "a non-negative integer"))

(de noncharactererror (offender fn)
  (typeerror offender fn "a character"))

(de nonstringerror (offender fn)
  (typeerror offender fn "a string"))

(de nonvectorerror (offender fn)
  (typeerror offender fn "a vector"))

(de nonwordserror (offender fn)
  (typeerror offender fn "a words vector"))

(de nonsequenceerror (offender fn)
  (typeerror offender fn "a sequence"))

(de noniochannelerror (offender fn)
  (typeerror offender fn "a legal I/O channel"))

