%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:STRINGS.LSP 
% Description:  Common Lisp string operations 
% Author:       Eric Benson 
% Created:      7 April 1982 
% Modified:     
% Mode:         Lisp 
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
% 22 Oct 1984 2032-PDT (Brian Beach)
%  Fixed STRING-NOT-LESSP.  It used to call the non-existant function
%  STRING-LESSP=.
% 23-Aug-84 09:26:22 (Brian Beach)
%  Removed local functions.
% 26 Jan 1984 1603-PST (Brian Beach)
%  Corrected file name in header.
% 11 Jan 1984 2007-PST (Nancy Kendzierski)
%  Added header and contents of .BUILD file
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load useful clcomp))  ;; Removed syslisp.

(eval-when (load)
  (imports '(chars)))	; Uses the CHARS module

;;;; CHAR - fetch a character in a string
;(defun char (s i)	; not defined because CHAR means something else in PSL
;  (elt (stringify s) i))

;;;; RPLACHAR - store a character in a string
(defun rplachar (s i x)
  (setelt s i x))

;;;; STRING= - compare two strings (substring options not implemented)
(fset 'string= (fsymeval 'eqstr))	; Same function in PSL

;;;; STRING-EQUAL - compare two strings, ignoring case, bits and font
(defun string-equal (s1 s2)
  (setq s1 (stringify s1))
  (setq s2 (stringify s2))
  (or (eq s1 s2)
      (let ((len1 (string-length s1)) (len2 (string-length s2)))
	   (and (eql len1 len2) (string-equal-aux s1 s2 len1 0)))))

(defun string-equal-aux (s1 s2 len i)
  (or (eql len i)
      (and (char-equal (char s1 i) (char s2 i))
	   (string-equal-aux s1 s2 len (add1 i)))))

;;;; STRING< - lexicographic comparison of strings
(defun string< (s1 s2)
  (setq s1 (stringify s1))
  (setq s2 (stringify s2))
  (string<-aux s1
	       s2
	       (string-length s1)
	       (string-length s2)
	       0))

(defun string<-aux (s1 s2 len1 len2 i)
  (cond ((eql i len1) (if (eql i len2) () i))
        ((eql i len2) ())
	((char= (char s1 i) (char s2 i))
	 (string<-aux s1 s2 len1 len2 (add1 i)))
	((char< (char s1 i) (char s2 i)) i)
	(t ())))

;;;; STRING> - lexicographic comparison of strings
(defun string> (s1 s2)
  (string< s2 s1))

;;;; STRING<= - lexicographic comparison of strings
(defun string<= (s1 s2)
  (setq s1 (stringify s1))
  (setq s2 (stringify s2))
  (string<=-aux s1 s2 (string-length s1) (string-length s2) 0))

(defun string<=-aux (s1 s2 len1 len2 i)
  (cond ((eql i len1) i)
	((eql i len2) ())
	((char= (char s1 i) (char s2 i))
	 (string<=-aux s1 s2 len1 len2 (add1 i)))
	((char< (char s1 i) (char s2 i)) i)
	(t ())))

;;;; STRING>= - lexicographic comparison of strings
(defun string>= (s1 s2)
  (string<= s2 s1))

;;;; STRING<> - lexicographic comparison of strings
(defun string<> (s1 s2)
  (setq s1 (stringify s1))
  (setq s2 (stringify s2))
  (let ((len1 (string-length s1)) (len2 (string-length s2)))
       (if (<= len1 len2)
	   (string<>-aux s1 s2 len1 len2 0)
	   (string<>-aux s2 s1 len2 len1 0))))

(defun string<>-aux (s1 s2 len1 len2 i)
  (cond ((eql i len1)
	 (if (eql i len2) () i))
	((char= (char s1 i) (char s2 i))
	 (string<>-aux s1 s2 len1 len2 (add1 i)))
	(t i)))

;;;; STRING-LESSP - lexicographic comparison of strings
(defun string-lessp (s1 s2)
  (setq s1 (stringify s1))
  (setq s2 (stringify s2))
  (string-lessp-aux s1 s2 (string-length s1) (string-length s2) 0))

(defun string-lessp-aux (s1 s2 len1 len2 i)
  (cond ((eql i len1) (if (eql i len2) () i))
	((eql i len2) ())
	((char-equal (char s1 i) (char s2 i))
	 (string-lessp-aux s1 s2 len1 len2 (add1 i)))
	((char-lessp (char s1 i) (char s2 i)) i)
	(t ())))

;;;; STRING-GREATERP - lexicographic comparison of strings
(defun string-greaterp (s1 s2)
  (string-lessp s2 s1))

;;;; STRING-NOT-GREATERP - lexicographic comparison of strings
(defun string-not-greaterp (s1 s2)
  (setq s1 (stringify s1))
  (setq s2 (stringify s2))
  (string-not-greaterp-aux s1 s2 (string-length s1) (string-length s2) 0))

(defun string-not-greaterp-aux (s1 s2 len1 len2 i)
  (cond ((eql i len1) i)
        ((eql i len2) ())
	((char-equal (char s1 i) (char s2 i))
	 (string-not-greaterp-aux s1 s2 len1 len2 (add1 i)))
	((char-lessp (char s1 i) (char s2 i))
	 i)
	(t ())))

;;;; STRING-NOT-LESSP - lexicographic comparison of strings
(defun string-not-lessp (s1 s2)
  (string-not-greaterp s2 s1))

;;;; STRING-NOT-EQUAL - lexicographic comparison of strings
(defun string-not-equal (s1 s2)
  (setq s1 (stringify s1))
  (setq s2 (stringify s2))
  (let ((len1 (string-length s1)) (len2 (string-length s2)))
       (if (<= len1 len2)
	   (string-not-equal-aux s1 s2 len1 len2 0)
	   (string-not-equal-aux s2 s1 len2 len1 0))))

(defun string-not-equal-aux (s1 s2 len1 len2 i)
  (cond ((eql i len1)
	 (if (eql i len2) () i))
	((char-equal (char s1 i) (char s2 i))
	 (string-not-equal-aux s1 s2 len1 len2 (add1 i)))
	(t i)))

;;;; MAKE-STRING - construct a string
(defun make-string (count fill-character)
  (mkstring (sub1 count) fill-character))

;;;; STRING-REPEAT - concat together copies of a string
(defun string-repeat (s i)
  (setq s (stringify s))
  (cond ((eql i 0) "")
	((eql i 1) (copystring s))
	(t (let ((len (string-length s)))
		(let ((s1 (make-string (* i len) #\Space)))
		     (do ((j 1 (+ j 1)) (i1 -1))
			 ((> j i))
			 (do ((k 0 (+ k 1)))
			     ((eql k len))
			     (setq i1 (add1 i1))
			     (rplachar s1 i1 (char s k))))
		     s1)))))

;;;; STRING-TRIM - remove leading and trailing characters from a string
(defun string-trim (c-bag s)
  (setq s (stringify s))
  (let ((len (string-length s)))
       (let ((i1 (string-trim-left-index c-bag s 0 len))
	     (i2 (string-trim-right-index c-bag s len)))
	    (if (<= i2 i1) "" (substring s i1 i2)))))

(defun string-trim-left-index (c-bag s i uplim)
  (if (or (eql i uplim) (not (bag-element (char s i) c-bag)))
      i
      (string-trim-left-index c-bag s (add1 i) uplim)))

(defun string-trim-right-index (c-bag s i)
  (if (or (eql i 0) (not (bag-element (char s (sub1 i)) c-bag)))
      i
      (string-trim-right-index c-bag s (sub1 i))))

(defun bag-element (elem c-bag)
  (cond ((consp c-bag) (memq elem c-bag))
	((stringp c-bag)
	 (bag-element-aux elem c-bag 0 (string-length c-bag)))
	(t ())))

(defun bag-element-aux (elem c-bag i uplim)
  (and (< i uplim)
       (or (char= elem (char c-bag i))
	   (bag-element-aux elem c-bag (add1 i) uplim))))

;;;; STRING-LEFT-TRIM - remove leading characters from string
(defun string-left-trim (c-bag s)
  (setq s (stringify s))
  (let ((len (string-length s)))
       (let ((i1 (string-trim-left-index c-bag s 0 len)))
	    (if (<= len i1) "" (substring s i1 len)))))

;;;; STRING-RIGHT-TRIM - remove trailing characters from string
(defun string-right-trim (c-bag s)
  (setq s (stringify s))
  (let ((i2 (string-trim-right-index c-bag s (string-length s))))
       (if (<= i2 0) "" (substring s 0 i2))))

;;;; STRING-UPCASE - copy and raise all alphabetic characters in string
(defun string-upcase (s)
  (setq s (stringify s))
  (nstring-upcase (copystring s)))

;;;; NSTRING-UPCASE - destructively raise all alphabetic characters in string
(defun nstring-upcase (s)
  (let ((len (string-length s)))
       (do ((i 0 (+ i 1)))
	   ((eql i len))
	 (let ((c (char s i)))
	   (when (lowercasep c) (rplachar s i (char-upcase c)))))
       s))

;;;; STRING-DOWNCASE - copy and lower all alphabetic characters in string
(defun string-downcase (s)
  (setq s (stringify s))
  (nstring-downcase (copystring s)))

;;;; NSTRING-DOWNCASE - destructively raise all alphabetic characters in string
(defun nstring-downcase (s)
  (let ((len (string-length s)))
       (do ((i 0 (+ i 1)))
	   ((eql i len))
	 (let ((c (char s i)))
	   (when (uppercasep c) (rplachar s i (char-downcase c)))))
       s))

;;;; STRING-CAPITALIZE - copy and raise first letter of all words in string
(defun string-capitalize (s)
  (setq s (stringify s))
  (nstring-capitalize (copystring s)))

;;;; NSTRING-CAPITALIZE - destructively raise first letter of all words
(defun nstring-capitalize (s)
  (let ((len (string-length s)) (in-word-flag ()))
       (do ((i 0 (+ i 1)))
	   ((eql i len))
	   (let ((c (char s i)))
		(cond ((uppercasep c)
		       (if in-word-flag
			   (rplachar s i (char-downcase c))
			   (setq in-word-flag t)))
		      ((lowercasep c)
		       (when (not in-word-flag)
			     (rplachar s i (char-upcase c))
			     (setq in-word-flag t)))
		      (t (setq in-word-flag ())))))
       s))

;;;; STRING - coercion to a string, named STRINGIFY in PSL
(defun stringify (x)
  (cond ((stringp x) x)
        ((symbolp x) (get-pname x))
	(t (stderror (bldmsg "%r cannot be coerced to a string" x)))))

;;;; STRING-TO-LIST - unpack string characters into a list
(defun string-to-list (s)
  (string2list s))			; PSL function

;;;; STRING-TO-VECTOR - unpack string characters into a vector
(defun string-to-vector (s)
  (string2vector s))			; PSL function

;;;; SUBSTRING - subsequence restricted to strings
(defun substring (string start end)
  (subseq (stringify string) start end))

;;;; STRING-LENGTH - last index of a string, plus one
(defun string-length (s)
  (add1 (size s)))

;;;; STRING-CONCAT - concatenate strings
(defmacro string-concat args
  (let ((len (length args)))
    (cond ((eql len 0) "")
          ((eql len 1) `(copystring (stringify ,(first args))))
	  (t (string-concat-aux args len)))))

(defun string-concat-aux (args len)
  (if (eql len 2)
      `(concat (stringify ,(first args))
	       (stringify ,(second args)))
      `(concat (stringify ,(first args))
	       ,(string-concat-aux (rest args) (sub1 len)))))
