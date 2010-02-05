%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:SYSTEM-DATE.SL
% Description:  Date and time routines.
%               (Partly taken from VAX version of date.)
% Author:       RAM, HP/FSD
% Created:      27-Feb-84
% Modified:     17-Jul-84 22:56:41 (RAM)
% Mode:         Lisp
% Package:      
% Status:       Experimental (Do Not Distribute)
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
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
(setq datebuffer (gtwarray 1))

(de date ()                             % current date, as "12-Sep-55"
  (external_time datebuffer)            % get the current time
  (sub (datebuffer-to-string) 0 10))

(de date-and-time ()                    % current date, as "12-Sep-55 13:35:22"
  (external_time datebuffer)            % get the current time
  (datebuffer-to-string))

(de date-int-to-string (dateint)        % convert date, as "12-Sep-55 13:35:22"
  (setf (wgetv datebuffer 0) dateint)   % put time in datebuffer
  (datebuffer-to-string))

(de datebuffer-to-string ()             % convert date, as "12-Sep-55 13:35:22"
  (prog (s tm)
        (setq s (gtstr 19))             % allocate 20 characters
        (setq tm (ctime datebuffer))    % get Unix' strange date string
        (setf (strbyt s 0) (r_byte tm 8)) % suck out the day of the month
        (setf (strbyt s 1) (r_byte tm 9))
        (setf (strbyt s 2) (char '!-))  % throw in a dash
        (setf (strbyt s 3) (r_byte tm 4)) % suck out the month
        (setf (strbyt s 4) (r_byte tm 5))
        (setf (strbyt s 5) (r_byte tm 6))
        (setf (strbyt s 6) (char '!-))  % another dash
        (setf (strbyt s 7) (r_byte tm 20))% and the year
        (setf (strbyt s 8) (r_byte tm 21))
        (setf (strbyt s 9) (r_byte tm 22))
        (setf (strbyt s 10) (r_byte tm 23))
        (setf (strbyt s 11) (r_byte tm 10))% copy the entire time portion, as is
        (setf (strbyt s 12) (r_byte tm 11))
        (setf (strbyt s 13) (r_byte tm 12))
        (setf (strbyt s 14) (r_byte tm 13))
        (setf (strbyt s 15) (r_byte tm 14))
        (setf (strbyt s 16) (r_byte tm 15))
        (setf (strbyt s 17) (r_byte tm 16))
        (setf (strbyt s 18) (r_byte tm 17))
        (setf (strbyt s 19) (r_byte tm 18))
        (return (mkstr s))))



