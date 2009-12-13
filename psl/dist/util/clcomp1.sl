%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:CLCOMP1.SL
% Description:  Incompatible Common Lisp compatibility
% Author:       Eric Benson
% Created:      12 April 1982
% Modified:     05-Sep-84 10:45:56 (Brian Beach)
% Mode:         Lisp
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
% 27-May-87 (Leigh Stoller & Harold Carr)
%  Added fluid declaration of PackageCharacter*.
% 05-Sep-84 10:44:27 (Brian Beach)
%  Fixed macro definition for CHAR.
% 21-Mar-84 15:41:26 (Brian Beach)
%  Commented out CMACRO properties.
% 26 Jan 1984 1548-PST (Brian Beach)
%  Corrected file name in header.
% 11 Jan 1984 1942-PST (Nancy Kendzierski)
%  Added header and contents of .BUILD file.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% These are Common Lisp compatiblity definitions that cause Standard Lisp
% to break.  Changes character definitions and redefines functions.

(compiletime (load useful common))
(compiletime (off usermode))

(imports '(useful common fast-vector))

(fluid '(PackageCharacter*))

(defmacro prog2 (first second . others)
  `(progn ,first (prog1 ,second ,@others)))

(remprop 'prog2 'compfn)

(ds char (s i) (igets s i))

%%%(put 'char 'cmacro '(lambda (s i) (igets s i)))

% NTH is a problem, hasn't been dealt with yet
% Also MAP functions...

(comment "make backslash the escape character")

(setf IDEscapeChar* #\!\)
(setf (elt lispscantable* #\!\) 14)

(comment "Make percent a letter")

(setf (elt lispscantable* #\!%) 10)

(comment "Make semicolon start comments")

(setf (elt lispscantable* #\;) 12)

(comment "make bang a letter")

(setf (elt lispscantable* #\!!) 10)

(comment "Make colon the package character")

(setf PackageCharacter* #\:)
(setf (elt lispscantable* #\:) 16)

(comment "Add vertical bars for reading IDs")

(setf (elt lispscantable* #\|) 21)

(comment "#M and #Q mean if_maclisp and if_lispm")

(defun throw-away-next-form (channel qt)
  (ChannelReadTokenWithHooks channel)
  (ChannelReadTokenWithHooks channel))

(put '!#M 'LispReadMacro 'throw-away-next-form)
(put '!#Q 'LispReadMacro 'throw-away-next-form)

(push '(M . !#M) (get '!# (getv LispScanTable* 128)))
(push '(Q . !#Q) (get '!# (getv LispScanTable* 128)))

(comment "So we can add #+psl to maclisp code")

(push 'psl system_list*)
