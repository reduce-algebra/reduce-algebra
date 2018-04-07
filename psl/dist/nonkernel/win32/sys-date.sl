%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:SYSTEM-DATE.SL
% Description:  Date and time routines.
%               (Partly taken from VAX version of date.)
% Author:       RAM, HP/FSD
% Created:      27-Feb-84
% Modified:     17-Jul-84 22:56:41 (RAM)
% Mode:         Lisp
% Status:       Open Source: BSD License
% Package:      
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
% 17-Jul-84 22:52:31 (RAM)
%  Changed allocation of datebuffer from warray declaration to a call on
%  gtwarray (the compiler was emitting bad code for declare-warray on
%  non-kernel modules).
%  Changed call of function time to a call of function external_time.
%  Time is defined in top-loop.sl, and was conflicting, now that this time
%  is not flagged as a foreignfunction.
%  Removed many prog nil constructs and reformatted comments.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(datebuffer))
(setq datebuffer (gtwarray 2))

(de date ()                             % current date, as "12-Sep-1955"
  (external_time datebuffer)            % get the current time
  (sub (datebuffer-to-string) 0 10))

(de date-and-time ()                    % current date, as "12-Sep-1955 13:35:22"
  (external_time datebuffer)            % get the current time
  (datebuffer-to-string))

(de date-int-to-string (dateint)        % convert date, as "12-Sep-1955 13:35:22"
  (setf (wgetv datebuffer 0) dateint)   % put time in datebuffer
  (datebuffer-to-string))

(de datebuffer-to-string ()             % convert date, as "12-Sep-1955 13:35:22"
  (prog (s tm)
        (setq s (gtstr 19))             % allocate 18 characters
        (setq tm (ctime datebuffer))    % get Unix' strange date string
        (setf (strbyt s 0) (byte tm 8)) % suck out the day of the month
        (setf (strbyt s 1) (byte tm 9))
        (setf (strbyt s 2) (char '!-))  % throw in a dash
        (setf (strbyt s 3) (byte tm 4)) % suck out the month
        (setf (strbyt s 4) (byte tm 5))
        (setf (strbyt s 5) (byte tm 6))
        (setf (strbyt s 6) (char '!-))  % another dash
        (setf (strbyt s 7) (byte tm 20))% and the year
        (setf (strbyt s 8) (byte tm 21))
        (setf (strbyt s 9) (byte tm 22))% and the year
        (setf (strbyt s 10) (byte tm 23))
        (setf (strbyt s 11) (byte tm 10))% copy the entire time portion, as is
        (setf (strbyt s 12) (byte tm 11))
        (setf (strbyt s 13) (byte tm 12))
        (setf (strbyt s 14) (byte tm 13))
        (setf (strbyt s 15) (byte tm 14))
        (setf (strbyt s 16) (byte tm 15))
        (setf (strbyt s 17) (byte tm 16))
        (setf (strbyt s 18) (byte tm 17))
        (setf (strbyt s 19) (byte tm 18))
        (return (mkstr s))))



