#!/bin/bash

# Build REDUCE on Common Lisp.
# Based on "psl/bootstrap.sh" and "psl/build.sh".

# Author: Francis J. Wright <https://sourceforge.net/u/fjwright>
# Preliminary support for Armed Bear Common Lisp by Rainer Schöpf.
# Support for Clozure Common Lisp by Marco Ferraris.

# 1. Compile sl-on-cl, which implements Standard Lisp on Common Lisp.
# 2. Build an initial bootstrap REDUCE image without REDUCE fasl files,
#    which does not form part of the final REDUCE system and should not
#    need to be rebuilt very often.  It is used to compile REDUCE.
# 3. Compile all required fasl files and save a final REDUCE image.

# This script must be run in the top-level CL REDUCE directory.
# Always do a clean build after updating your version of Common Lisp!

function help {
    echo 'Build REDUCE on Common Lisp.'
    echo 'Usage: ./build.sh [-h] -l sbcl/clisp/abcl/ccl [-c/f] [-b]'
    echo 'Option -h displays this help message and exits.'
    echo 'Option -c ensures a clean build by deleting any previous build.'
    echo 'Option -f forces recompilation of all packages.'
    echo 'Option -b builds only the bootstrap REDUCE image.'
    exit 1
}

while getopts l:cfbh option
do
    case $option in
        l) lisp=$OPTARG;;
        c) clean=true;;
        f) force='!*forcecompile := t;';;
        b) bootstraponly=true;;
        h) help;;
    esac
done

case $lisp in
    'sbcl')
        runlisp='sbcl'
        runlispfile='sbcl --load'
        runbootstrap='sbcl --noinform --core fasl.sbcl/bootstrap.img'
        runreduce='sbcl --noinform --core fasl.sbcl/reduce.img'
        saveext='img'
        faslext='fasl';;
    'clisp')
        runlisp='clisp -ansi -norc'
        runlispfile='clisp -ansi'
        runlispfile='clisp -ansi'
        runbootstrap='clisp -q -norc -M fasl.clisp/bootstrap.mem'
        runreduce='clisp -q -norc -M fasl.clisp/reduce.mem'
        saveext='mem'
        faslext='fas';;
    'abcl')
        runlisp='java -jar abcl-bin-1.8.0/abcl.jar --noinit'
        runlispfile='java -jar abcl-bin-1.8.0/abcl.jar --noinit --load'
        runbootstrap='java -jar abcl-bin-1.8.0/abcl.jar --noinit --noinform -M fasl.abcl/bootstrap.mem'
        runreduce='java -jar abcl-bin-1.8.0/abcl.jar --noinit --noinform -M fasl.abcl/reduce.mem'
        saveext='jar'
        faslext='abcl';;
    'ccl')
        runlisp='ccl'
        runlispfile='ccl -l'
		runbootstrap='ccl -I fasl.ccl/bootstrap.image'
        runreduce='ccl -I fasl.ccl/reduce.image'
        saveext='image'
        case $(uname -s) in
            Darwin)             # macOS
                faslext='dx64fsl';;
            Linux)
                faslext='lx64fsl';;
            CYGWIN*)            # MS Windows
                faslext='wx64fsl';;
        esac;;
    *)
        echo 'Error: option "-l sbcl/clisp/abcl/ccl" is required'; help;;
esac

if [ $clean ]; then
    echo '+++++ Clean build'
    rm -rf sl-on-cl.$faslext trace.$faslext fasl.$lisp log.$lisp
fi

if [ -z "$reduce" ]; then
    if [ -e './packages' ]; then export reduce=.
    elif [ -e '../packages' ]; then export reduce=..
    else echo 'Error: cannot find packages directory.  Please set $reduce.'; exit 1
    fi
fi

mkdir -p log.$lisp           # -p avoids complaint if directory exists
mkdir -p fasl.$lisp

#################################
# Compile sl-on-cl if necessary #
#################################

if [ "sl-on-cl.lisp" -nt "sl-on-cl.$faslext" ]
then
    echo '+++++ Compiling sl-on-cl'
    $runlisp << XXX &> log.$lisp/sl-on-cl.blg
(or (compile-file "sl-on-cl") (exit #+SBCL :code 1))
XXX
fi || { echo '***** Compilation failed'; exit 1; }

########################################################
# Build an initial bootstrap REDUCE image if necessary #
########################################################

function grep_errors {
    grep --ignore-case '\*\{5\} \| error \|COMMON-LISP:ERROR' log.$lisp/$1.blg | uniq
}

if [ ! -e fasl.$lisp/bootstrap.$saveext ]
then
    echo '+++++ Building bootstrap REDUCE...'
    time $runlispfile bootstrap &> log.$lisp/bootstrap.blg
    if [ ! -e fasl.$lisp/bootstrap.$saveext ]
    then
        echo $'\n***** Building bootstrap REDUCE failed'; exit 1
    else
        echo $'\n+++++ Built bootstrap REDUCE.  Possible errors:'
        grep_errors bootstrap
    fi
    echo $'\a'
fi

if [ $bootstraponly ]; then exit; fi

################
# Build REDUCE #
################

echo '+++++ Building REDUCE...'

# First, compile fasl files for non-package source files:
$runbootstrap << XXX &> log.$lisp/build.blg
symbolic; $force

off redefmsg;

package!-remake2('clprolo, nil);
package!-remake2('revision, 'support);
package!-remake2('clrend, nil);
package!-remake2('entry, 'support);
package!-remake2('smacros,'support);
package!-remake2('remake, nil); % for building noncore packages

% Create .dat files that list core and non-core modules to build:

begin
  scalar w, i, s, core, noncore;
  i := open("$reduce/packages/package.map", 'input);
  s := rds i;
  w := read();
  rds s;
  close i;
  for each x in w do
     if member('csl, x) and member('psl, x) then <<
        if member('core, x) then core := x . core
        else noncore := x . noncore >>;
  i := open("fasl.$lisp/core-packages.dat", 'output);
  s := wrs i;
  for each x in reverse core do print car x;
  wrs s;
  close i;
  i := open("fasl.$lisp/noncore-packages.dat", 'output);
  s := wrs i;
  for each x in reverse noncore do print car x;
  wrs s;
  close i;
end;

bye;
XXX

if [ ! -e fasl.$lisp/core-packages.dat -o ! -e fasl.$lisp/noncore-packages.dat ]
then echo '***** Running bootstrap REDUCE failed'; exit 1
fi

# Compile the "core" packages, each in a separate invocation of
# bootstrap REDUCE to avoid adverse interactions:

time for p in $(< fasl.$lisp/core-packages.dat)
do
    echo "+++++ Remaking core package $p"
    $runbootstrap << XXX &> log.$lisp/$p.blg
symbolic; $force

off redefmsg;

begin
  scalar w, i, s;
  i := open("$reduce/packages/package.map", 'input);
  s := rds i;
  w := read();
  rds s;
  close i;
  for each x in w do put(car x, 'folder, cadr x)
end;

package!-remake '$p;

bye;
XXX

grep_errors $p

done

###############################
# Build the REDUCE image file #
###############################

if [ "trace.lisp" -nt "trace.$faslext" ]
then
    echo '+++++ Compiling trace'
    $runlisp << XXX &> log.$lisp/trace.blg
(load "sl-on-cl")
(or (compile-file "trace") (exit 1))
XXX
fi || { echo '***** Compiling trace failed'; exit 1; }

echo $'\n+++++ Building the REDUCE image file...'

# Start a new invocation of Lisp and load the key modules compiled
# above.  Then save a final REDUCE image that will be used below to
# compile the non-core modules.

time $runlisp << XXX &> log.$lisp/reduce.blg
(load "sl-on-cl") (load "trace") ; temporary -- until I can arrange autoloading!
(standard-lisp)

(cl:defparameter !*init!-stats!* (list (time) (gtheap)))

(setq !*verboseload t)
(setq !*redefmsg nil)
(cl:defvar !*argnochk t)        % check argument count

(load "module")                 % for definition of load-package
(load "clprolo")                % initial CL specific code

(load!-package 'revision)
(load!-package 'rlisp)
(load!-package 'clrend)
(load!-package 'smacros)
(load!-package 'poly)
(load!-package 'arith)
(load!-package 'alg)
(load!-package 'rtools)
(load!-package 'mathpr)
(load!-package 'entry)

(cl:fmakunbound 'prettyprint)   % otherwise defautoload has no effect!
(defautoload prettyprint pretty)  % since only in entry file for PSL!

(setq date!* (date))
(setq version!* (cl:format nil "REDUCE (Free ~a version, revision ~a)"
      (cond ((memq 'sbcl lispsystem!*) "SBCL")
            ((memq 'clisp lispsystem!*) "CLISP")
            ((memq 'ccl lispsystem!*) "CCL"))
      revision!*))

(initreduce)

(setq !*verboseload nil)        % inhibit loading messages
(setq !*redefmsg t)             % display redefinition messages

(cond ((memq 'sbcl lispsystem!*)
       (setq !*muffled-warnings!* 'warning))) % exported from sb-ext

(prog nil
   (terpri)
   (prin2 "Time to build REDUCE: ")
   (prin2 (quotient (difference (time) (car !*init!-stats!*)) 1000.0))
   (prin2t " secs")
   (prin2 "Heap used: ")
   (prin2 (difference (cadr !*init!-stats!*) (gtheap)))
   (prin2t " bytes")
   (prin2 "Heap left: ")
   (prin2 (gtheap))
   (prin2t " bytes")
   (cl:makunbound '!*init!-stats!*))

(save!-reduce!-image "reduce")

XXX

if [ ! -e fasl.$lisp/reduce.$saveext ]
then
    echo $'\n***** Building the REDUCE image failed'; exit 1
else
    echo $'\n+++++ Built the REDUCE image file\n'
fi

# Finally, compile the "noncore" packages using reduce.img rather than
# bootstrap.img.

time for p in $(< fasl.$lisp/noncore-packages.dat)
do
    echo "+++++ Remaking noncore package $p"
    $runreduce << XXX &> log.$lisp/$p.blg
symbolic; $force

%load compiler;
on verboseload;

if '$p eq 'fps then load_package limits,factor,specfn,sfgamma
else if '$p eq 'mrvlimit then load_package taylor
% Temporary hacks to avoid build errors:
else if '$p eq 'rubi_red then flag('(flush),'rlisp)
else if '$p eq 'tmprint then <<
   lispsystem!* := 'psl . lispsystem!*;
   switch usermode >>;

load remake;

!*argnochk := t;

begin
  scalar w, i, s;
  i := open("$reduce/packages/package.map", 'input);
  s := rds i;
  w := read();
  rds s;
  close i;
  for each x in w do put(car x, 'folder, cadr x)
end;

package!-remake '$p;

% Temporary hack to make gnuplot package work on Common Lisp:
if '$p eq 'gnuplot then
   begin scalar !*int, !*forcecompile; !*forcecompile := t;
      update!-fasl2('gnuintfc, nil);
   end;

bye;
XXX

grep_errors $p

done

echo $'\n+++++ Built REDUCE.\a'
