%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:CHARS.SL
% Description:  Common Lisp operations on characters 
% Author:       Eric Benson 
% Created:      7 April 1982 
% Modified:     11-Dec-84 13:55:10 (Cris Perdue)
% Mode:         Lisp 
% Package:      
% Status:       Open Source: BSD License
% Compiletime:  PL:USEFUL.B PL:CLCOMP.B 
% Runtime:      
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
% 06-Aug-89 (Tony Hearn)
%  Replaced > and < by greaterp and lessp resp.
% 26-Sep-86 (Leigh Stoller)
%  Moved two macros char-int and int-char to the top of the file since macros
%  should generally be defined before they are used.
% 11-Dec-84 13:54:42 (Cris Perdue)
%  Fixed upper bound test in digit-char: 10 --> 9.
% 02-Feb-84 17:00:17 (Cris Perdue)
%  Changed standard-charp to use char< rather than the not yet
%  existent char>=
% 18 Jan 1984 (Cris Perdue)
%  Changed a comment using "%" to use ";" as required.
% 11 Jan 1984 1917-PST (Nancy Kendzierski)
%  Added standard file header.  Added contents of .BUILD file.
% 13 May 1983 1734-PDT (Cris Perdue)
%  Changed standard-charp to match new Common LISP, fixed
%  char-equal, lessp, greaterp to be correct.
% 2-Sep-82 14:22:45, Edit by BENSON
%  Fixed bug in CHAR-UPCASE and CHAR-DOWNCASE
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load useful clcomp))
(compiletime (put 'Space 'CharConst 32))	; temporary patch

(defvar char-code-limit 128 "Upper bound of character code values")

(defvar char-font-limit 1 "Upper bound on supported fonts")

(defvar char-bits-limit 1 "Upper bound on values produces by char-bits")

;;;; CHAR-INT - convert character to integer
(defmacro char-int (c)
  ;; Identity operation in PSL
  c)

;;;; INT-CHAR - convert integer to character
(defmacro int-char (c)
  ;; Identity operation in PSL
  c)

;;;; STANDARD-CHARP - ASCII definition
(defun standard-charp (c)
  (and (characterp c)
       (or (and (not (char< c #\Space))
		(char< c #\Rubout))
	   (eq c #\Eol))))

;;;; GRAPHICP - printable character
(defun graphicp (c)
  (and (characterp c)
    (not (char< c #\Space))
    (char< c #\Rubout)))

;;;; STRING-CHARP - a character that can be an element of a string
(defun string-charp (c)
  (and (characterp c)
       (>= (char-int c) 0)
       (<= (char-int c) #\Rubout)))

;;;; ALPHAP - an alphabetic character
(defun alphap (c)
  (or (uppercasep c)
      (lowercasep c)))

;;;; UPPERCASEP - an uppercase letter
(defun uppercasep (c)
  (and (characterp c)
       (not (char< c #\A))
       (not (char> c #\Z))))

;;;; LOWERCASEP - a lowercase letter
(defun lowercasep (c)
  (and (characterp c)
       (not (char< c #\\a))
       (not (char> c #\\z))))

;;;; BOTHCASEP - same as ALPHAP
(fset 'bothcasep (fsymeval 'alphap))

;;;; DIGITP - a digit character (optional radix not supported)
(defun digitp (c)
  (when (and (characterp c)
	     (not (char< c #\0))
	     (not (char> c #\9)))
        (- (char-int c) (char-int #\0))))

;;;; ALPHANUMERICP - a digit or an alphabetic
(defun alphanumericp (c)
  (or (alphap c) (digitp c)))

;;;; CHAR= - strict character comparison
(defun char= (c1 c2)
  (eql (char-int c1) (char-int c2)))

;;;; CHAR-EQUAL - similar character objects
(defun char-equal (c1 c2)
  (eq (char-upcase c1) (char-upcase c2)))

;;;; CHAR< - strict character comparison
(defun char< (c1 c2)
  (lessp (char-int c1) (char-int c2)))

;;;; CHAR> - strict character comparison
(defun char> (c1 c2)
  (greaterp (char-int c1) (char-int c2)))

;;;; CHAR-LESSP - ignore case and bits for CHAR<
(defun char-lessp (c1 c2)
  (char< (char-upcase c1) (char-upcase c2)))

;;;; CHAR-GREATERP - ignore case and bits for CHAR>
(defun char-greaterp (c1 c2)
  (char> (char-upcase c1) (char-upcase c2)))

;;;; CHAR-CODE - character to integer conversion
(defmacro char-code (c)
  c)

;;;; CHAR-BITS - bits attribute of a character
(defmacro char-bits (c)
  0)

;;;; CHAR-FONT - font attribute of a character
(defmacro char-font (c)
  0)

;;;; CODE-CHAR - integer to character conversion, optional bits, font ignored
(defmacro code-char (c)
  c)

;;;; CHARACTER - character plus bits and font, which are ignored
(defun character (c)
  (cond ((characterp c) c)
        ((stringp c) (char c 0))
        ((symbolp c) (char (get-pname c) 0))
	(t (stderror (bldmsg "%r cannot be coerced to a character" c)))))

;;;; CHAR-UPCASE - raise a character
(defun char-upcase (c)
  (if (not (or (char< c #\\a)
	       (char> c #\\z)))
      (int-char (+ (char-int #\A)
		   (- (char-int c)
		      (char-int #\\a))))
      c))

;;;; CHAR-DOWNCASE - lower a character
(defun char-downcase (c)
  (if (not (or (char< c #\A)
	       (char> c #\Z)))
      (int-char (+ (char-int #\\a)
		   (- (char-int c)
		      (char-int #\A))))
      c))

;;;; DIGIT-CHAR - convert character to digit (optional radix, bits, font NYI)
(defun digit-char (i)
  (when (and (>= i 0) (<= i 9))
        (int-char (+ (char-int #\0) i))))
