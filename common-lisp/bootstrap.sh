#!/usr/bin/bash

# Build a bootstrap version of REDUCE on Common Lisp.
# Based on "psl/bootstrap.sh".

# Author: Francis J. Wright <https://sourceforge.net/u/fjwright>

# Build an initial bootstrap REDUCE image but no fasl files, which
# does not form part of the final REDUCE system and should not need to
# be rebuilt very often.  It is used (by build.sh) to compile REDUCE.

# Usage: ./bootstrap.sh -l sbcl/clisp

if getopts l: option; then lisp=$OPTARG; fi

if [ "$lisp" = 'sbcl' ]; then
    runlisp='sbcl'
    faslext='fasl'
    if_sbcl=''
    if_clisp='%'
elif [ "$lisp" = 'clisp' ]; then
    runlisp='clisp -ansi'
    faslext='fas'
    if_sbcl='%'
    if_clisp=''
else
    echo 'Error: option -l sbcl/clisp is required'
    exit
fi

if [ ! "$reduce" ]; then export reduce=.; fi

mkdir -p log                 # -p avoids complaint if directory exists
mkdir -p fasl

if [ "sl-on-cl.lisp" -nt "sl-on-cl.$faslext" ]
then
echo +++++ Compiling sl-on-cl
$runlisp << XXX &> log/sl-on-cl.blg
(or (compile-file "sl-on-cl") (exit #+SBCL :code 1))
XXX
fi || { echo '***** Compilation failed'; exit; }

echo +++++ Building bootstrap REDUCE

time $runlisp << XXX &> log/bootstrap.blg
(declaim (optimize speed))

(load "sl-on-cl")
(standard-lisp)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% STANDARD LISP SYNTAX FROM NOW ON! %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(setq !*verboseload t)
(setq !*redefmsg nil)           % Just duplicates CL warnings!

(cl:defparameter !*init!-time!* (time))

(cl:defvar !*argnochk t)
(cl:defvar !*int nil)  % Prevents input buffer being saved.
(cl:defvar !*msg nil)

% Do not use fasl version of "boot.sl": the CL compiler may optimize
% away (i.e. discard) uses of fluid variables that are needed later in
% the build process!

(load "boot.sl")

$if_clisp (setq !*comp t)  % It's faster in some lisps if we compile.

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
   (prin2t " bytes")
)

(initreduce)
(setq date!* (date))
(setq version!* "Bootstrap REDUCE")

% SBCL (see SBCL User Manual / Stopping SBCL / Saving a Core Image):
% save!-lisp!-and!-die("fasl/bootstrap", !:executable, t, !:toplevel, (lambda () (standard-lisp) (begin)))
% For better debugging...
$if_sbcl (save!-lisp!-and!-die "fasl/bootstrap.img")
$if_clisp (saveinitmem "fasl/bootstrap.mem")

XXX

echo +++++ Bootstrap REDUCE built

echo 'Possible errors:'
grep --ignore-case '\*\*\*\*\*\|\<error\>' log/bootstrap.blg

echo $'\a'
