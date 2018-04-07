%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:FAST-CHARS.SL 
% Description:  Some fast operations on characters 
% Author:       Cris Perdue 
% Created:      3-Aug-83 
% Modified:     12-Sep-84 08:29:15 (Brian Beach)
% Package:      
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
% 02-Dec-83 08:50:25, Cris Perdue
%   Tidied up and looked over for local release.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Functions present here are the same as functions present in
% chars.lsp except that these check less, run faster, some of
% these are defined as macros, and all of these have names
% with the prefix "fast-".
% 
% Functions provided by this module are simple, but not
% necessarily tested.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load numeric-ops chars if))

(on fast-integers)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% MACROS
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(ds fast-char= (c1 c2)
%%% FAST-CHAR= - strict character comparison
  (= (char-int c1) (char-int c2)))

(ds fast-char< (c1 c2)
%%% FAST-CHAR< - strict character comparison
  (< (char-int c1) (char-int c2)))

(ds fast-char> (c1 c2)
%%% FAST-CHAR> - strict character comparison
  (> (char-int c1) (char-int c2)))

(ds fast-char<= (c1 c2)
%%% FAST-CHAR<= - strict character comparison
  (<= (char-int c1) (char-int c2)))

(ds fast-char>= (c1 c2)
%%% FAST-CHAR>= - strict character comparison
  (>= (char-int c1) (char-int c2)))

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% MACRO DEFINITIONS FOR INTERNAL USE ONLY

(defmacro char-upcase-macro (x)
%%% ASCII-specific.  May evaluate its argument multiple times.  Not to
%%% be exported.
  `(if (and (<= #\!a ,x) (<= ,x #\!z)) then
     (- ,x 32)
    else ,x))

(defmacro char-downcase-macro (x)
%%% ASCII-specific.  May evaluate its argument multiple times.  Not to
%%% be exported.
  `(if (and (<= #\A ,x) (<= ,x #\Z)) then
     (+ ,x 32)
    else ,x))

%%% END OF MACROS

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% Public functions
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(defun fast-char-upcase (c)
  (char-upcase-macro c))

(defun fast-char-downcase (c)
  (char-downcase-macro c))

(defun fast-standard-charp (c)
%%% FAST-STANDARD-CHARP - ASCII definition
  (and (or (not (or (fast-char< c #\Space) (fast-char>= c #\Rubout)))
	   (eq c #\Eol))))

(defun fast-graphicp (c)
%%% FAST-GRAPHICP - printable character
%%% ASCII definition
  (and
   (not (fast-char< c #\Space))
   (fast-char< c #\Rubout)))

(defun fast-string-charp (c)
%%% FAST-STRING-CHARP - a character that can be an element of a string
%%% ASCII definition
  (and
   (>= (char-int c) 0)
   (<= (char-int c) #\Rubout)))

(defun fast-alphap (c)
%%% FAST-ALPHAP - an alphabetic character
  (or (fast-uppercasep c)
      (fast-lowercasep c)))

(defun fast-uppercasep (c)
%%% FAST-UPPERCASEP - an uppercase letter
%%% ASCII definition
  (and
       (not (fast-char< c #\A))
       (not (fast-char> c #\Z))))

(defun fast-lowercasep (c)
%%% FAST-LOWERCASEP - a lowercase letter
%%% ASCII definition
  (and
       (not (fast-char< c #\!a))
       (not (fast-char> c #\!z))))

(defun fast-digitp (c)
%%% FAST-DIGITP - a digit character (optional radix not supported)
%%% ASCII definition
  (when (and
	 (not (fast-char< c #\0))
	 (not (fast-char> c #\9)))
    (- (char-int c) (char-int #\0))))

(defun fast-alphanumericp (c)
%%% FAST-ALPHANUMERICP - a digit or an alphabetic
  (or (fast-alphap c) (fast-digitp c)))

(defun fast-char-equal (c1 c2)
%%% FAST-CHAR-EQUAL - similar character objects
  (= (char-upcase-macro c1) (char-upcase-macro c2)))

(defun fast-char-lessp (c1 c2)
%%% FAST-CHAR-LESSP - ignore case and bits for fast-char<
  (fast-char< (char-upcase-macro c1) (char-upcase-macro c2)))

(defun fast-char-greaterp (c1 c2)
%%% FAST-CHAR-GREATERP - ignore case and bits for fast-char>
  (fast-char> (char-upcase-macro c1) (char-upcase-macro c2)))

(off fast-integers)

% End of file.
