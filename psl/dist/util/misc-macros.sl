%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PU:MISC-MACROS.SL 
% Description:  assorted useful macros 
% Author:       Don Morrison 
% Created:      Wednesday, 12 May 1982 
% Modified:     9 May 1984 2058-PDT (Nancy Kendzierski) 
% Status:       Open Source: BSD License
% Mode:         Lisp 
% Package:      Utilities 
% Compiletime:  PL:BACKQUOTE.B PL:READ-MACROS.B PL:DEFMACRO.B PL:COND-MACROS.B 
%               PL:BIND-MACROS.B PL:SET-MACROS.B PL:ITER-MACROS.B 
%               PL:FOR-MACRO.B 
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
% 6 May 1984 1755-PDT (Nancy Kendzierski)
%  Added compiletime loads to allow separate compilation.  Moved definition
%  of funcall and call to for-macro.sl, since that file needs them.
% 19 Jan 1984 1443-PST (Brian Beach)
%   Added standard header.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load backquote read-macros defmacro cond-macros
		   bind-macros set-macros iter-macros for-macro))

(defmacro eqfirst (u v) `(eqcar ,u ,v))

(defmacro bldid (s . args) `(intern (bldmsg ,s ,@args)))

(defmacro nary-concat u (expand u 'concat))

(defmacro-no-displace defstub (name . rst)
% quick, kludgy hack -- should be much better
  (let ((args (if (pairp rst) (pop rst))))
    `(de ,name ,args
       (stub-print ',name ',args (list ,@args))
       ,@rst
       (let ((*ContinuableError t)) (break)))))

(de stub-print (name arg-names actual-args)
  (errorprintf "Stub %w called with arguments:" name)
  (for (in u arg-names) (in v actual-args)
    (do (errorprintf "   %w: %p%n" u v)))
  (terpri))

(defmacro circular-list L
  `(let ((***CIRCULAR-LIST-ARG*** (list ,@L)))
     (nconc ***CIRCULAR-LIST-ARG*** ***CIRCULAR-LIST-ARG***)))

(defmacro nothing U nil) % Nary no-op returning nil; args not evaluated.

(defmacro make-list (N . rst)
  `(make-list-1 ,N ,(if (pairp rst) (car rst) nil)))

(de make-list-1 (N init)
  (for (from i 1 N) (collect init)))
