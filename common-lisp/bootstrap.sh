#!/usr/bin/bash

# Build a bootstrap version of REDUCE on Common Lisp.
# Based on "psl/bootstrap.sh".

# Author: Francis J. Wright <https://sourceforge.net/u/fjwright>

# Build an initial bootstrap REDUCE image but no fasl files, which
# does not form part of the final REDUCE system and should not need to
# be rebuilt very often.  It is used (by build.sh) to compile REDUCE.

# Usage: ./bootstrap.sh

if [ ! "$reduce" ]; then export reduce=.; fi

mkdir -p log				 # -p avoids complaint if directory exists
mkdir -p fasl

if [ "sl-on-cl.lisp" -nt "sl-on-cl.fasl" ]
then
echo +++++ Compiling sl-on-cl
sbcl << XXX &> log/sl-on-cl.blg
(compile-file "sl-on-cl")
XXX
fi

echo +++++ Building bootstrap REDUCE

sbcl << XXX &> log/bootstrap.blg
;(declaim (optimize debug)				; same as (debug 3)
;		 (sb-ext:muffle-conditions sb-ext:compiler-note style-warning))

(load "sl-on-cl")
(standard-lisp)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% STANDARD LISP SYNTAX FROM NOW ON! %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(setq !*verboseload t)
(setq !*redefmsg nil)			% Just duplicates CL warnings!

(cl:defparameter !*init!-time!* (time))

(cl:defvar !*argnochk t)
(cl:defvar !*int nil)  % Prevents input buffer being saved.
(cl:defvar !*msg nil)
% (setq !*comp t)  % It's faster in some lisps if we compile.

% Do not use fasl version of "boot.sl": the CL compiler may optimize
% away (i.e. discard) uses of fluid variables that are needed later in
% the build process!

(load "boot.sl")

(cl:defvar xxx)
(begin2)
rds(xxx := open("build.red",'input));
(close xxx)

(load!-package!-sources 'clprolo nil)
(load!-package!-sources 'rlisp 'rlisp)
(load!-package!-sources 'clrend nil)
(load!-package!-sources 'poly 'poly)
(load!-package!-sources 'alg 'alg)
(load!-package!-sources 'arith 'arith)
(load!-package!-sources 'entry 'support)
(load!-package!-sources 'remake nil)

(setq !*comp nil)

% (load "compiler")

(prog nil
   (terpri)
   (prin2 "Time to build bootstrap REDUCE: ")
   (prin2 (quotient (difference (time) !*init!-time!*) 1000.0))
   (prin2t " secs")
   (prin2 "Heap left: ")
   (prin2 (gtheap))
   (prin2t " bytes"))

(initreduce)
(setq date!* (date))
(setq version!* "Bootstrap REDUCE")

% SBCL (see SBCL User Manual / Stopping SBCL / Saving a Core Image):
% save!-lisp!-and!-die("fasl/bootstrap", !:executable, t, !:toplevel, (lambda () (standard-lisp) (begin)))
(save!-lisp!-and!-die "fasl/bootstrap.img")  % better for debugging

XXX

echo +++++ Bootstrap REDUCE built

echo 'Errors:'
grep --ignore-case '\*\*\*\*\*\|\<error\>' log/bootstrap.blg

echo $'\a'
