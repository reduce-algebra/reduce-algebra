%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         pslcomp.sl
% Description:  Interpret program command string for source files to compile
% Author:       Leigh Stoller & Stan Shebs
% Created:      22-Nov-86
% Package:      
%
% (c) Copyright 1987, University of Utah
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Revisions
%
% 01-Jun-87 (Harold Carr & Leigh Stoller)
%  Added .l suffix to allowable source file extensions.
% 02-Dec-86 (Leigh Stoller)
%  Removed load of useful since it is now a kernel module named macros.sl.
%   Corrected spelling of compiler.
% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


% Redefines PSLCOMP start-up routine to read and interpret program command
%  string as a list of source files to be compiled.

(imports '(get-options compiler str-search))
%% get-options defines get-command-args.

(fluid '(*usermode *redefmsg *WritingFASLFile))

(cond ((funboundp 'original-main)
       (copyd 'original-main 'main)))

(de main ()
  (let ((c-list (get-command-args))
	(*usermode nil)
	(*redefmsg nil))
    (compile-files c-list)
    (copyd 'main 'original-main))
  (original-main)
  )

(de compile-files (c-list)
  (cond ((null c-list)
	 (PrintF "Portable Standard Lisp Compiler%n")
	 (PrintF "Usage: PSLCOMP source-file ...%n"))
	(t
	 (for (in fn c-list)
	      (do (attempt-to-compile-file fn)))
         (exitlisp))))

(de attempt-to-compile-file (fn)
  (let* ((*break NIL)
	 (result (ErrSet (compile-file fn) T)))
    (cond ((FixP result)
	   (if *WritingFASLFile (faslend))
	   (printf "%n ***** Error during compilation of %w.%n" fn)))))


% Returns either T (successful), ABORT (aborted by user after error is
% signalled), or NIL (source file not found).

(de compile-file (fn)
  (let ((result (compile-file-aux1 fn)))
    (cond ((eq result 'ABORT) (exit 'ABORT))
	  ((eq result T) (exit T))
	  ((null result) (printf "Source file %w not found%n" fn)))))

% This function attempts to compile the specified source file.
% Returns T if successful, ABORT if aborted by the
% user after an error is signalled, NIL if the source file is not found.
% The compilation is terminated even upon an abnormal exit.

(de compile-file-aux1 (source-fn)
  (when (filep source-fn)
    (let ((result 'ABORT))
      (unwind-protect
       (setq result (unprotected-compile-file source-fn NIL))
       % Here is the cleanup action:
       (when (eq result 'ABORT)
	 (faslabort)
	 (printf "%f----- Compilation of %w aborted.%n%n" source-fn)
	 ))
      result
      )))

(de compile-file-aux (source-fn binary-fn)

    (when (filep source-fn)
    (let ((result 'ABORT))
      (unwind-protect
       (setq result (unprotected-compile-file source-fn binary-fn))
       % Here is the cleanup action:
       (when (eq result 'ABORT)
         (faslabort)
         (printf "%f----- Compilation of %w aborted.%n%n" source-fn)
         ))
      result
      )))

(de unprotected-compile-file (source-fn name)
  (let* ((*quiet_faslout T)
	 (file-type (get-file-extension source-fn))
	 (binary-fn (if name name (get-binary-name source-fn file-type))))
    (printf "%n----- Compiling %w to %w.b -----%n"
	    source-fn binary-fn)
    (faslout binary-fn)
    (if (eq 'ABORT (dskin-file 'COMPILE-FILE source-fn NIL #'faslend))
      'ABORT
      (progn
	(printf "%f----- Compilation of %w completed.%n%n" source-fn)
	T))))

(de get-binary-name (filename type)
  (cond ((equal type 'SL)
         (subseq filename 0 (difference (size filename) 2)))
        ((equal type 'L)
         (subseq filename 0 (difference (size filename) 1)))
        (t
         filename)))

(de get-file-extension (filename)
  (cond ((string-search-equal ".sl" filename)
         'SL)
        ((string-search-equal ".l" filename)
         'L)))

% End of file.
