%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:SYS-MACROS.SL
% Description:  Macros for doing system type things.
% Author:       Brian Beach, Hewlett-Packard CRC
% Created:      22-Mar-84
% Modified:     26-Jun-84 14:45:24
% Mode:         Lisp
% Package:      
% Status:       Open Source: BSD License
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
% 26-Jun-82 14:45:24 (Vicki O'Day)
%  Added support for `external words'.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


(defmacro declare-warray (name init-type init)
  (cond 
   ((eq init-type 'size)      (warray-size name init))
   ((eq init-type 'initially) (warray-init name init))
   (t  (stderror (bldmsg "Bad warray declaration: %w" (list name init-type init))))
   ))

(de warray-size (name init)
  `(progn
    (fluid '(,name))
    (setf ,name (gtwarray ,init))
    (clear-warray ,name ,init)
    ))

(de warray-init (name init)
  `(progn
    (fluid '(,name))
    (setf ,name (gtwarray ,(length init)))
    (initialize-warray ,name (list ,@init))
    ))

(defmacro declare-wstring (name init-type init)
  (cond 
   ((eq init-type 'size)      (wstring-size name init))
   ((eq init-type 'initially) (wstring-init name init))
   (t  (stderror (bldmsg "Bad wstring declaration: %w" (list name init-type init))))
   ))

(ds wstring-word-size (n)
  (plus (quotient n charactersperword) 2)
  )

(de wstring-size (name init)
  `(progn
    (fluid '(,name))
    (setf ,name (gtwarray (wstring-word-size ,init)))
    (clear-wstring ,name ,init (wstring-word-size ,init))
    ))

(de wstring-init (name init)
  `(progn
    (fluid '(,name))
    (setf ,name (gtwarray (wstring-word-size ,(string-length init))))
    (initialize-wstring ,name ,init (wstring-word-size ,(string-length init)))
    ))

(defmacro external-word (name)
  `(getmem ,name)
  )

(defmacro declare-external-word (name)
  (flag1 name 'externalsymbol)
  (put name 'symbol name)
  `(fluid '(,name))
  )

