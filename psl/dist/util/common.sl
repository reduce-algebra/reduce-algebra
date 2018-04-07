%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:COMMON.SL 
% Description:  Compile- and read-time support for Common Lisp compatibility. 
% Author:       Eric Benson, Hewlett-Packard CRC 
% Created:      31 March 1982 
% Modified:     05-Sep-84 10:53:22 (Brian Beach)
% Package:      Utilities 
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
% 26-Sep-86 (Leigh Stoller)
%  Added compiletime load of fast-vector for igets function.
% 16 Apr 1984 1341-PST (Cris Perdue)
%  Made Galway's changes, see immediately below:
% 13-Sep-83 17:07:38, Edit by GALWAY
%   Deleted duplicate definition of nthcdr (there were two identical
%   definitions).
% 12-Sep-83 13:32:22, Edit by GALWAY
%   Added some "minimal" Common Lisp I/O utilities:  WRITE-CHAR,
%   READ-FROM-STRING, READ-CHAR, UNREAD-CHAR, PEEK-CHAR, READ-LINE.
%   Deleted  old (obsolete) definitions for OUCH, INCH, UNINCH.  See code
%   for details on what exactly is (and isn't) implemented.
% 6 Mar 1984 (Cris Perdue)
%  Removed definitions related to string=, string-length, substring.
% 14 Feb 1984 1305-PST (Cris Perdue)
%  Removed +, -, >, etc., and left-expand moved to
%  numeric-operators.  Some of these quite dangerous: defined as
%  macros in conflict with numeric-operators defns..  Now loads
%  numeric-operators as a substitute (not always an exact substitute).
% 19 Jan 1984 1429-PST (Brian Beach)
%   Added standard header.
% 22-Sep-83 11:21:34, Cris Perdue
%   Removed use of "then" keyword in "if" in with-open-file.
% 08-Aug-83 17:27:32, Cris Perdue
%   Added with-open-file.
% 5 Jul 1983 1700-PDT, Cris Perdue
%   + and * expand into PLUS and TIMES, not fast versions now.
% 17-Jun-83 14:59:10, Cris Perdue
%   Defined /= as not eqn rather than neq (more precise).
%   Extended + and * to take any number of arguments.
% 7 Mar 1983 1335-PST, Cris Perdue
%  Left-expand is now available outside this module.  (No longer flagged
%  as internalfunction.)
% Edit by Cris Perdue,  4 Feb 1983 1047-PST
% Removed ERRSET (redundant and not COMMON Lisp) and MOD (incorrect).
% <PSL.UTIL.NEWVERSIONS>COMMON.SL.2, 13-Dec-82 21:30:58, Edit by GALWAY
%    Fixed bugs in copylist and copyalist that copied the first element
%    twice.  Also fixed bug in copyalist where it failed to copy first pair
%    in the list.
%    Also started commenting the functions defined here.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% These are only the Common Lisp definitions that do not conflict with
% Standard Lisp or other PSL functions.  Currently growing on a daily basis

(compiletime (load useful fast-vector) (off usermode))
(imports '(useful fast-vector numeric-ops))

(compiletime
(defmacro cl-alias (sl-name cl-name)
  `(defmacro ,cl-name form
     `(,',sl-name . ,form)))

(flag '(expand-funcall* butlast-aux nbutlast-aux
	 left-expand-aux) 'internalfunction)

)

(cl-alias de defun)

(defmacro defvar (name . other)
  (if *defn (fluid (list name)))
  (if (atom other)
      `(fluid `(,',name))
      `(progn (fluid `(,',name))
	      (setq ,name ,(car other)))))

(cl-alias idp symbolp)

(cl-alias pairp consp)

(defun listp (x) (or (null x) (consp x)))

%%% (put 'listp 'cmacro '(lambda (x) ((lambda (y) (or (null y) (consp y))) x)))

(cl-alias fixp integerp)

(cl-alias fixp characterp)

%%% (put 'characterp 'cmacro '(lambda (x) (posintp x)))

(cl-alias vectorp arrayp)

(cl-alias codep subrp)

(defun functionp (x)
  (or (symbolp x) (codep x) (and (consp x) (eq (car x) 'lambda))))

(cl-alias eqn eql)

(cl-alias equal equalp)

(cl-alias valuecell symeval)

(defmacro fsymeval (symbol)
  `((lambda (***fsymeval***)
	    (or (cdr (getd ***fsymeval***))
		(stderror (bldmsg "%r has no function definition"
				  ***fsymeval***))))
    ,symbol))

(defmacro boundp (name)
  `(not (unboundp ,name)))

(defmacro fboundp (name)
  `(not (funboundp ,name)))

(defmacro macro-p (x)
  `(let ((y (getd ,x)))
        (if (and (consp y) (equal (car y) 'macro)) (cdr y) nil)))

(defmacro special-form-p (x)
  `(let ((y (getd ,x)))
        (if (and (consp y) (equal (car y) 'fexpr)) (cdr y) nil)))

(defmacro fset (symbol value)
  `(putd ,symbol 'expr ,value))

(defmacro makunbound (x)
  `(let ((y ,x) (makunbound y) y)))

(defmacro fmakunbound (x)
  `(let ((y ,x) (remd y) y)))

(defmacro funcall* (fn . args)
  `(apply ,fn ,(expand-funcall* args)))

(defun expand-funcall* (args)
  (if (null (cdr args))
      (car args)
      `(cons ,(car args) ,(expand-funcall* (cdr args)))))

(cl-alias funcall* lexpr-funcall)

% only works when calls are compiled right now
% need to make a separate special form and compiler macro prop.
(defmacro progv (symbols values . body)
  `(let ((***bindmark*** (captureenvironment)))
	(do ((symbols ,symbols (cdr symbols))
	     (values ,values (cdr values)))
	    ((null symbols) nil)
	  (lbind1 (car symbols) (car values)))
	(prog1 (progn ,@body)
	       (restoreenvironment ***bindmark***))))
       
(defmacro dolist (bindspec . progbody)
  `(prog (***do-list*** ,(first bindspec))
     (setq ***do-list*** ,(second bindspec))
$loop$
     (if (null ***do-list***)
         (return ,(if (not (null (cddr bindspec)))
		      (third bindspec)
		      ())))
     (setq ,(first bindspec) (car ***do-list***))
     ,@progbody
     (setq ***do-list*** (cdr ***do-list***))
     (go $loop$)))

(defmacro dotimes (bindspec . progbody)
  `(prog (***do-times*** ,(first bindspec))
     (setq ,(first bindspec) 0)
     (setq ***do-times*** ,(second bindspec))
$loop$
     (if (= ,(first bindspec) ***do-times***)
         (return ,(if (not (null (cddr bindspec)))
		      (third bindspec)
		      ())))
     (setq ,(first bindspec) (+ ,(first bindspec) 1))
     ,@progbody
     (go $loop$)))

(cl-alias map mapl)

% neither PROG or PROG* supports initialization yet
(cl-alias prog prog*)

(cl-alias dm macro)

% DECLARE, LOCALLY ignored now
(defmacro declare forms
  ())

(defmacro locally forms
  `(let () ,forms))

% version of THE which does nothing
(defmacro the (type form)
  form)

(cl-alias get getpr)

(cl-alias put putpr)

(cl-alias remprop rempr)

(cl-alias prop plist)

(cl-alias id2string get-pname)

(defun samepnamep (x y)
  (equal (get-pname x) (get-pname y)))

(cl-alias newid make-symbol)

(cl-alias internp internedp)

(defun plusp (x)
  (and (not (minusp x)) (not (zerop x))))

(defun oddp (x)
  (and (integerp x) (equal (remainder x 2) 1)))

(defun evenp (x)
  (and (integerp x) (equal (remainder x 2) 0)))

(cl-alias add1 !1+)

(cl-alias sub1 !1-)

(cl-alias incr incf)

(cl-alias decr decf)

(defmacro logior args
  (robustexpand args 'lor 0))

(defmacro logxor args
  (robustexpand args 'lxor 0))

(defmacro logand args
  (robustexpand args 'land -1))

(cl-alias lnot lognot)

(cl-alias lshift ash)

(put 'ldb 'assign-op 'dpb)		% Not defined, but used in NSTRUCT

%%% (put 'rplachar 'cmacro '(lambda (s i x) (iputs s i x)))

%%% (put 'char-int 'cmacro '(lambda (x) x))

%%% (put 'int-char 'cmacro '(lambda (x) x))

%%% (put 'char= 'cmacro '(lambda (x y) (eq x y)))

%%% (put 'char< 'cmacro '(lambda (x y) (ilessp x y)))

%%% (put 'char> 'cmacro '(lambda (x y) (igreaterp x y)))

(cl-alias indx elt)

(cl-alias setindx setelt)

(defun copyseq (seq)
  (subseq seq 0 (+ (size seq) 1)))

(defun endp (x)
  (cond ((consp x) ())
        ((null x) t)
	(t (stderror (bldmsg "%r is not null at end of list" x)))))

(cl-alias length list-length)

(cl-alias reversip nreverse)

(cl-alias getv vref)

(cl-alias putv vset)

%%% (put 'string-to-list 'cmacro '(lambda (x) (string2list x)))

%%% (put 'list-to-string 'cmacro '(lambda (x) (list2string x)))

%%% (put 'string-to-vector 'cmacro '(lambda (x) (string2vector x)))

%%% (put 'vector-to-string 'cmacro '(lambda (x) (vector2string x)))

(defun nthcdr (n l)
  (do ((n n (isub1 n))
       (l l (cdr l)))
      ((izerop n) l)))

(cl-alias copy copytree)

(cl-alias pair pairlis)

%%% (put 'make-string 'cmacro '(lambda (i c) (mkstring (isub1 i) c)))

(defmacro putprop (symbol value indicator)
  `(put ,symbol ,indicator ,value))

(defmacro defprop (symbol value indicator)
  `(putprop `,',symbol `,',value `,',indicator))

(defmacro eval-when (time . forms)
  (if *defn
      (progn (when (memq 'compile time) (evprogn forms))
	     (when (memq 'load time) `(progn ,@forms)))
      (when (memq 'eval time) `(progn ,@forms))))

% This name is already used by PSL /csp
% (defmacro case tail
%   (cons 'selectq tail)

% Selectq is actually a LISP Machine LISP name /csp
(defmacro selectq (on . s-forms)
  (if (atom on)
      `(cond ,@(expand-select s-forms on))
      `((lambda (***selectq-arg***)
		(cond ,@(expand-select s-forms '***selectq-arg***)))
	 ,on)))

(defun expand-select (s-forms formal)
  (cond ((null s-forms) ())
        (t `((,(let ((selector (first (first s-forms))))
		(cond ((consp selector)
		       `(memq ,formal `,',selector))
		      ((memq selector '(otherwise t))
			t)
		      (t `(eq ,formal `,',selector))))
	       ,@(rest (first s-forms)))
	      ,@(expand-select (rest s-forms) formal)))))

(defmacro comment form
  ())

(defmacro special args
  `(fluid `,',args))

(defmacro unspecial args
  `(unfluid `,',args))

(cl-alias atsoc assq)

(cl-alias lastpair last)

(cl-alias flatsize2 flatc)

(cl-alias explode2 explodec)

% swapf, exchf ...?

(defun tree-equal (x y)
  (if (atom x)
      (eql x y)
      (and (tree-equal (car x) (car y))
	   (tree-equal (cdr x) (cdr y)))))

% Return a "top level copy" of a list.
(defun copylist (x)
  (if (atom x)
      x
      (let* ((x1 (cons (car x) ()))
              (x (cdr x)))
	   (do ((x2 x1 (cdr x2)))
	       ((atom x) (rplacd x2 x) x1)
             (rplacd x2 (cons (car x) ()))
             (setq x (cdr x))))))

% Return a copy of an a-list (copy down to the pairs but no deeper).
(defun copyalist (x)
  (if (atom x)
      x
      (let* ((x1 (cons (cons (caar x) (cdar x)) ()))
              (x (cdr x)))
           (do ((x2 x1 (cdr x2)))
	       ((atom x) (rplacd x2 x) x1)
             (rplacd x2 (cons (cons (caar x) (cdar x)) ()))
             (setq x (cdr x))))))

(defun revappend (x y)
  (if (atom x) y
      (revappend (cdr x) (cons (car x) y))))

(defun nreconc (x y)
  (if (atom x) y
      (let ((z (cdr x)))
	(rplacd x y)
	(nreconc z x))))

(defun butlast (x)
  (if (or (atom x) (atom (cdr x))) x
      (butlast-aux x ())))

(defun butlast-aux (x y)
  (let ((z (cons (car x) y)))
    (if (atom (cddr x)) z
      (butlast-aux (cdr x) z))))

(defun nbutlast (x)
  (if (or (atom x) (atom (cdr x)))
      x
      (do ((y x (cdr y)))
	((atom (cddr y)) (rplacd y ())))
      x))

(defun buttail (list sublist)
  (if (atom list)
      list
      (let ((list1 (cons (car list) ())))
	   (setq list (cdr list))
	   (do ((list2 list1 (cdr list2)))
	       ((or (atom list) (eq list sublist)) list1)
	       (rplacd list2 (cons (car list) ()))
	       (setq list (cdr list))))))

(cl-alias substip nsubst)

(defmacro with-open-file (header . body)
  (if (not (= (length header) 3))
    (stderror "Bad form of invocation of with-open-file"))
  (let ((var (first header))
	(filename (second header))
	(inout (third header)))
    `(let ((,var (open ,filename ,inout)))
       (unwind-protect
	(progn ,.body)
	(close ,var)))))

%(defmacro ouch (char . maybe-channel)
%  (if maybe-channel
%      `(channelwritechar ,(car maybe-channel) ,char)
%      `(writechar ,char)))
%
%(defmacro inch maybe-channel
%  (if maybe-channel
%      `(channelreadchar ,(car maybe-channel))
%      `(readchar)))
%
%(defmacro uninch (char . maybe-channel)
%  (if maybe-channel
%      `(channelunreadchar ,(car maybe-channel) ,char)
%      `(unreadchar ,char)))

(defmacro write-char (char . maybe-channel)
  (if maybe-channel
      `(channelwritechar ,(car maybe-channel) ,char)
      `(writechar ,char)))

(defmacro read-from-string (str)
  % Use equivalent "PSL" function for reading from a string.
  `(string-read ,str))

(defmacro read-char maybe-channel
  (if maybe-channel
      `(channelreadchar ,(car maybe-channel))
      `(readchar)))

(defmacro unread-char (char . maybe-channel)
  (if maybe-channel
      `(channelunreadchar ,(car maybe-channel) ,char)
      `(unreadchar ,char))
  NIL)

(de peek-char (peek-type input-stream)
  % Return, but don't "suck up" the next character in the input-stream.
  % Ignore peek-type for now (treat it if it were NIL).  See Common Lisp
  % manual for intended values of peek-type.
  (let ((character (read-char input-stream)))
    (unread-char character input-stream)
    character))

(de read-line (input-stream)
  % Read a line from input-stream, return it as a text string (without a
  % trailing EOL).  If the string is longer than 256 characters it is
  % truncated to 256 characters but no "complaint" is made.
  % NOTE that this will only work as compiled code, due to use of
  % IgreaterP, etc..
  (let
    (
     (longest-possible-string (MkString 255 0))
     (string-length 0)
     (char-read 0))
    
    (while
      (not
        (or
          (eq
            (setf char-read (read-char input-stream))
            (char EOL))
          (eq char-read (char EOF))
          (IGreaterP string-length 255)))

      % Store the newly read character
      (setf (IGetS longest-possible-string string-length) char-read)
      (setf string-length (Iadd1 string-length)))

    % Return a nicely trimmed copy of the string.
    (substring longest-possible-string 0 string-length)))

% End of file.
