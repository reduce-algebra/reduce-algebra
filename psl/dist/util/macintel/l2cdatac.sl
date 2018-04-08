%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% File:         l2cDataCon.sl
% Description:  Macros to Convert data types between Lisp and C.
% Author:       Harold Carr (borrowing from Russ Fish)
% Created:      Summer 1985
% Package:
% Status:       Open Source: BSD License
% RCS $Header: $
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
% Usage: These are macros because we do not want to incur a function
%        call overhead to convert argument types.  To use these functions
%        you must load this file at compile time to compile files with
%        calls to these macros, or load time, if you run interpreted code
%        using these functions.  If you use the functions which acces
%        C global variables then this file must be loaded at load time.
%
%        If you have a C function name _foo which takes a character
%        and a string and returns a string, you would write the Lisp
%        function which calls it as:
%
%        (flag '(_foo) 'foreignfunction)
%
%        (de foo (c s)
%          (string-from-c (_foo (char-to-c c) (string-to-c s))))
 
% From psl to c.
 
% Used to send a word of bits to C without conversion.
(defmacro bits-to-c (b>)
  b>)
 
(defmacro boolean-to-c (flag>)
  `(if ,flag> 1 0))
 
(defmacro char-to-c (c>)
  `(character ,c>))
 
(defmacro c-ptr-to-c (p>)
  `(int2sys ,p>))
 
% If the C routine expects a float (double), not a pointer to a double
% then the two words of the double must be placed on the stack.  The
% following two routines accomplish this.
% VAX-dependency: (float1-to-c f) must be followed with (float2-to-c f):
%
%        (de foo (f)
%          (float-from-c (_foo (float1-to-c f) (float2-to-c f))))
%
% Depending on stack direction this may need to be reversed on some machines.
 
(defmacro float1-to-c (f1>)
  `(floathighorder (fltinf (float ,f1>))))
 
(defmacro float2-to-c (f2>)
  `(floatloworder  (fltinf (float ,f2>))))
 
(defmacro float-to-c (fp>)          % This one passes pointers to doubles.
  `(floatbase (fltinf (float ,fp>))))
 
(defmacro id-to-c (id>)
  id>)
 
(defmacro id-to-string-to-c (is>)
  `(unixstring (id2string ,is>)))
 
(defmacro int-to-c (int>)
  `(int2sys ,int>))
 
(defmacro string-to-c (s>)
  `(unixstring ,s>))
 
(defmacro string-to-id-to-c (si>)
  `(intern ,si>))
 
 
% From c to psl.
 
% Used to receive a word of bits from C without conversion.
(defmacro bits-from-c (<b)
  <b)
 
(defmacro boolean-from-c (<flag)
  `(not (zerop ,<flag)))
 
(defmacro char-from-c (<c)
  `(int-char ,<c))
 
(defmacro c-ptr-from-c (<p)
  `(sys2int ,<p))
 
(defmacro float-from-c (caddress)    % Takes a pointer to a double.
  `(let ((<caddress> ,caddress)
     (f (gtfltn)))
     (setf (floathighorder f) (getmem <caddress>))
     (setf (floatloworder  f) (wgetv  <caddress> 1))
     (mkfltn f)))
 
(defmacro id-from-c (<id)
  <id)
 
(defmacro int-from-c (<int)
  `(sys2int ,<int))
 
(defmacro string-from-c (<s)
  `(importforeignstring ,<s))
 
(defmacro string-to-id-from-c (<si)
  `(intern (importforeignstring ,<si)))
 
(defmacro void-from-c (<v)
  <v)
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
% Access to C global variables: ForeignData.
 
% FOREIGN-DATA-ADDRESS -
% Given a C global variable's name as an ID.
% Return the address of the variable.
% Note that the IDs will have underscore prefixes added by the C compiler.
 
(defun foreign-data-address (varname)
  (let ((dataprop (get varname 'foreigndata)))
    (if dataprop
      (car dataprop)
      (stderror (bldmsg "%p is not loaded as foreign data." varname)))))
 
(defun foreign-data-word (varname)
  (getmem (foreign-data-address varname)))
 
(defun set-foreign-data-word (varname value)
  (setf (getmem (foreign-data-address varname)) value))
 
% You can refine the type of the foreign word with macros like:
 
(defmacro foreign-data-flag (varname)
  `(boolean-from-c (foreign-data-word ,varname)))
 
(defmacro set-foreign-data-flag (varname value)
  `(set-foreign-data-word ,varname (boolean-to-c ,value)))
 
% Slightly higher level interface to C globals
 
(de cconst1 (x)
  (set x
       (foreign-data-word (intern (compress (append '(!! !_) (explode x)))))))
 
(de cconst (l) (global l) (for (in x l) (do (CCONST1 x))))
 
% Floats need special treatment:
 
(defun foreign-data-float (varname)
  (float-from-c (foreign-data-address varname)))
 
(defun set-foreign-data-float (varname number)
  (let ((caddress) (tmp))
    (setq caddress (foreign-data-address varname))
    % Make sure it's a float, may garbage collect.
    (setq tmp (fltinf (float number)))
    (setf (getmem caddress) (floathighorder tmp))
    (setf (wgetv caddress 1) (floatloworder tmp))
    number))
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
% Pointer access to some bottom-level PSL datastructures.
% WARNING: The pointers returned by these functions will be invalidated when a
% garbage collection relocates a items stored in the heap.  It is only safe
% if you do NOTHING that allocates heap space between the time the pointer
% is computed and when it is used (typically by passing it to C code.)
% Exceptions are print names of symbols (id2String), which
% are statically allocated in BPS space and not garbage collected;
% static word vectors in WArray space, like that returned by the static-Words
% function below.  However, the system may change, so relying on GC
% protection is dangerous.
 
% STRING-PTR
% Given a string. Returns a pointer to the body of the string.
 
(defun string-ptr (string)
  (if (not (stringp string))
    (stderror (bldmsg "STRING-PTR: %p is not a string." string))
    (strbase (strinf string))))
 
 
% WORDS-PTR
% Given a word vector. Returns a pointer to the body of a word vector.
 
(defun words-ptr (words)
  (if (not (eq (tag words) words-tag))
    (stderror (bldmsg "WORDS-PTR: %p is not a word vector." words))
    (wrdbase (wrdinf words))))
 
 
% STATIC-WORDS
% Given the number of words to allocate (one more than the indexing bound).
% Allocate a chunk of WArray space, which is not garbage collected.
% Returns a word-vector object, which can be accessed by indexing.
 
(defun static-words (nwords)
  (let ((words (gtwarray (wplus2 nwords 1))))
    (setf (getmem words) (mkitem hwords-tag (wdifference nwords 1)))
    (mkwrds words)))
 
% End of file.
