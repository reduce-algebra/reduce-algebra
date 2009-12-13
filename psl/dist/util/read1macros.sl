%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:READ1MACROS.SL 
% Description:  First part of some specilized reader macros 
% Author:       Don Morrison, Hewlett-Packard CRC 
% Created:      Wednesday, 12 May 1982 
% Modified:     6 May 1984 1558-PDT 
% Package:      Utilities 
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
% 6 May 1984 1538-PDT (Nancy Kendzierski)
%  Split read-macros.sl into two parts to allow them to be separately
%  compilable without requiring itself.  This part defines the
%  ` (backquote) read-macro necessary to compile the second part.
%  Since char-macro is being moved out of the kernel into useful, and
%  char-macro.sl needs this backquote stuff, modified this file to
%  not use CHAR.
% 19 Jan 1984 1449-PST (Brian Beach)
%   Added standard header.
% 1 Feb 1983 1400-PST  (Cris Perdue)
%   Dochar moved into "nonkernel", "C" for "CONTROL", etc. commented out.
%   Many miscellaneous symbolic names for characters removed.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load backquote))

((lambda (o-table)
   (setq LispScanTable* (TotalCopy o-table)) % in case it's in pure space
   (cond ((eq CurrentScanTable* o-table)
	   (setq CurrentScanTable* LispScanTable*))))
  LispScanTable*)

% plug backquote and friends into the lisp reader via read macros
% ` for backquote, , for unquote, ,@ for unquotel, and ,. for unquoted

(de backquote-read-macro (channel qt)
  (list 'backquote (ChannelReadTokenWithHooks channel)))

(de unquote-read-macro (channel qt)
  (list 'unquote (ChannelReadTokenWithHooks channel)))

(de unquotel-read-macro (channel qt)
  (list 'unquotel (ChannelReadTokenWithHooks channel)))

(de unquoted-read-macro (channel qt)
  (list 'unquoted (ChannelReadTokenWithHooks channel)))

(putv LispScanTable* 96 11)   % CHAR not yet defined;  96 = (char !`)

(putv LispScanTable* 44 13)   % CHAR not yet defined;  44 = (char !,)

(put '!, (getv LispScanTable* 128) '((!@ . !,!@)(!. . !,!.)))

(deflist
  '((!` backquote-read-macro)
    (!, unquote-read-macro)
    (!,!@ unquotel-read-macro)
    (!,!. unquoted-read-macro))
  'LispReadMacro)

% End of file.

