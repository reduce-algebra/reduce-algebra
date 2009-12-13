%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:STRING-INPUT.SL 
% Description:  
% Author:       Cris Perdue, Hewlett-Packard CRC 
% Created:      1-Dec-82 
% Modified:     31 Jan 1984 1730-PST (Cris Perdue) 
% Status:       Experimental (Do Not Distribute) 
% Mode:         Lisp 
% Package:      Utilities 
% Compiletime:  PL:IF.B PL:NUMERIC-OPERATORS.B PL:FAST-VECTORS.B 
%               PL:FAST-STRINGS.B 
% Runtime:      
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 31 Jan 1984 (Cris Perdue)
%   Corrected macros to expand via (close ,var) rather than (close chan).
% 19 Jan 1984 1450-PST (Brian Beach)
%   Added standard header.
% 16 Nov 83, Cris Perdue
%   Changed use of $eof$ to (char eof) -- bug fix.
% 02-Sep-83 14:55:26, Cris Perdue
%   Changed with-input-from-string and with-input-from-terminated-string
%   to be macros with a "body" to be executed.  Unwind-protected them.
%   Removed string-readtoken.
%   Removed limitations about channel switching with string input
%   channels.
%   "Terminated" versions of these facilities are apparently unneeded.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load if numeric-ops f-vectors f-strings))

(on fast-integers)

%% Below note the constant 32.  This should be at least as large as
%% the number of i/o channels that exist.  This module will fail
%% if it is not, but will fail somewhat gracefully.
(fluid '(channel-strings channel-string-posns))
(if (null channel-strings) then
  (setf channel-strings (make-vector 32 "")))
(if (null channel-string-posns) then
  (setf channel-string-posns (make-vector 32 0)))

(defmacro with-input-from-string (header . body)
%%% Form of invocation is, e.g.
%%% (with-input-from-string (chan "this is it")
%%%   (list (channelread chan) (channelread chan))).
%%% The form or forms of the body are executed with the variable
%%% specified bound to a channel from which the characters of the string
%%% may be read.  The forms in the body are expected to read from the
%%% string.  The body is unwind-protected.
%%% The value of the form is the value of the last form of the body
%%% if it returns at all.
  (if (not (= (length header) 2)) then
    (stderror "Bad form of invocation of with-input-from-string"))
  (let ((var (first header))
	(str-expr (second header)))
    `(let ((specialreadfunction* 'string-readchar)
	   (specialwritefunction* 'readonlychannel)
	   (specialclosefunction* 'close-string-channel))
       (let ((,var (open "" 'special)))
	 (setf (indx channel-strings ,var) ,str-expr)
	 (setf (indx channel-string-posns ,var) 0)
	 (unwind-protect
	  (progn ,.body)
	  (close ,var))))))

%(defmacro with-input-from-terminated-string (header . body)
%%% This is similar to with-input-from-string, but the string
%%% passed in is effectively padded on the right with a single
%%% blank.  No storage allocation is performed to give this
%%% effect.
%  (if (not (= (length header) 2)) then
%    (stderror "Bad form of invocation of with-input-from-terminated-string"))
%  (let ((var (first header))
%	(str-expr (second header)))
%    `(let ((specialreadfunction* 'string-readchar-terminated)
%	   (specialwritefunction* 'readonlychannel)
%	   (specialclosefunction* 'null))
%       (let ((,var (open "" 'special)))
%	 (setf (indx channel-strings ,var) ,str-expr)
%	 (setf (indx channel-string-posns ,var) 0)
%	 (unwind-protect
%	  (progn ,.body)
%	  (close ,var))))))

(defun string-read (str)
%%% Reads from the string.
  (with-input-from-string (chan str) (channelread chan)))

%(defun string-readtoken (str)
%%% Reads a single token from the string using channelreadtoken.
%%% The string need contain no terminator character; a blank is
%%% provided if necessary by string-readtoken.
%  (with-input-from-terminated-string (chan str) (channelreadtoken chan))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% Internal routines.

(on fast-vectors)
(on fast-strings)

(defun string-readchar (chan)
  (let ((channel-string (vector-fetch channel-strings chan))
	(channel-string-pos (vector-fetch channel-string-posns chan)))
    (if (> channel-string-pos (size channel-string)) then
      (char eof)
      else
      (prog1
       (string-fetch channel-string channel-string-pos)
       (vector-store channel-string-posns chan
		     (+ channel-string-pos 1))))))

%(defun string-readchar-terminated (chan)
%%% Includes hack that tacks on a blank for termination of READ
%%% and friends.
%%% Apparently not needed.
%  (let ((channel-string (vector-fetch channel-strings chan))
%	(channel-string-pos (vector-fetch channel-string-posns chan)))
%    (if (<= channel-string-pos (size channel-string)) then
%      (prog1
%       (string-fetch channel-string channel-string-pos)
%       (vector-store channel-string-posns chan
%		     (+ channel-string-pos 1)))
%      elseif (= channel-string-pos (+ 1 (size channel-string))) then
%      (prog1
%       (char space)		% Blank
%       (vector-store channel-string-posns chan
%		     (+ channel-string-pos 1)))
%      else
%      (char eof))))

(off fast-strings)
(off fast-vectors)
(off fast-integers)

(defun close-string-channel (chan)
  (setf (indx channel-strings chan) ""))
