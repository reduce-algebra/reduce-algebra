#!/bin/bash

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
    if_abcl='%'
elif [ "$lisp" = 'clisp' ]; then
    runlisp='clisp -ansi'
    faslext='fas'
    if_sbcl='%'
    if_clisp=''
    if_abcl='%'
elif [ "$lisp" = 'abcl' ]; then
    runlisp='/usr/lib/jvm/java-8-openjdk-amd64/jre/bin/java -jar abcl-bin-1.8.0/abcl.jar --noinit'
    runbootstrap='/usr/lib/jvm/java-8-openjdk-amd64/jre/bin/java -jar abcl-bin-1.8.0/abcl.jar --noinit --noinform -M fasl/bootstrap.mem'
    runreduce='/usr/lib/jvm/java-8-openjdk-amd64/jre/bin/java -jar abcl-bin-1.8.0/abcl.jar --noinit --noinform -M fasl/reduce.mem'
    saveext='jar'
    faslext='abcl'
    if_sbcl='%'
    if_clisp='%'
    if_abcl=''
else
    echo 'Error: option -l sbcl/clisp/abcl is required'
    exit
fi

if [ ! -v reduce ]; then
    if [ -e './packages' ]; then export reduce=.
    elif [ -e '../packages' ]; then export reduce=..
    else echo 'Error: cannot find packages directory.  Please set $reduce.'; exit
    fi
fi

mkdir -p log.$lisp           # -p avoids complaint if directory exists
mkdir -p fasl.$lisp

if [ "sl-on-cl.lisp" -nt "sl-on-cl.$faslext" ]
then
echo +++++ Compiling sl-on-cl
$runlisp << XXX &> log.$lisp/sl-on-cl.blg
(or (compile-file "sl-on-cl") (exit #+SBCL :code 1))
XXX
fi || { echo '***** Compilation failed'; exit; }

echo +++++ Building bootstrap REDUCE

time $runlisp << XXX &> log.$lisp/bootstrap.blg
(load "sl-on-cl")
#-DEBUG (declaim (optimize speed))
#+DEBUG (declaim (optimize debug safety))
#+SBCL (declaim (sb-ext:muffle-conditions sb-ext:compiler-note style-warning))
#+CLISP (setq custom:*suppress-check-redefinition* t
              custom:*compile-warnings* nil)

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

(cond ((filep "boot.sl") (load "boot.sl"))
      ((filep "../psl/boot.sl") (load "../psl/boot.sl"))
      (t (error 0 "Cannot find boot file.") (exit 1)))

$if_clisp (setq !*comp t)  % It's faster in some lisps if we compile.
$if_abcl (setq !*comp t)  % It's faster in some lisps if we compile.

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
(save!-reduce!-image "bootstrap")

XXX

echo +++++ Bootstrap REDUCE built

echo 'Possible errors:'
grep --ignore-case '\*\*\*\*\*\|\<error\>' log.$lisp/bootstrap.blg

echo $'\a'
