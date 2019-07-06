#!/bin/bash

# Build REDUCE on Common Lisp.
# Based on "psl/bootstrap.sh" and "psl/build.sh".

# Author: Francis J. Wright <https://sourceforge.net/u/fjwright>

# Compile all required fasl files and save a final REDUCE image.
# Assume this script is run in the top-level CL REDUCE directory.

# Usage: ./build.sh -l sbcl/clisp [-c/f]

# Option -c ensures a clean build by deleting any previous build.
# Option -f forces recompilation of all packages.

if getopts l: option; then lisp=$OPTARG; fi

if [ "$lisp" = 'sbcl' ]; then
    runlisp='sbcl'
    runbootstrap='sbcl --noinform --core fasl.sbcl/bootstrap.img'
    runreduce='sbcl --noinform --core fasl.sbcl/reduce.img'
    saveext='img'
    faslext='fasl'
    if_sbcl=''
    if_clisp='%'
elif [ "$lisp" = 'clisp' ]; then
    runlisp='clisp -ansi -norc'
    runbootstrap='clisp -q -norc -M fasl.clisp/bootstrap.mem'
    runreduce='clisp -q -norc -M fasl.clisp/reduce.mem'
    saveext='mem'
    faslext='fas'
    if_sbcl='%'
    if_clisp=''
else
    echo 'Error: option -l sbcl/clisp is required'
    exit
fi

while getopts cf option
do
    if [ $option = c ]; then rm -rf fasl.$lisp log.$lisp;
    elif [ $option = f ]; then force='!*forcecompile := t;';
    fi
done

if [ ! -v reduce ]; then
    if [ -e './packages' ]; then export reduce=.
    elif [ -e '../packages' ]; then export reduce=..
    else echo 'Error: cannot find packages directory.  Please set $reduce.'; exit
    fi
fi

# Build an initial bootstrap REDUCE image if necessary:
if [ ! -e fasl.$lisp/bootstrap.$saveext ]; then ./bootstrap.sh -l $lisp; fi

mkdir -p log.$lisp           # -p avoids complaint if directory exists

shopt -s expand_aliases

alias grep_errors=\
"grep --ignore-case '\*\{5\} \| \<error\>\|COMMON-LISP:ERROR' log.$lisp/\$p.blg | uniq"

# First, compile fasl files for non-package source files:
$runbootstrap << XXX &> log.$lisp/build.blg
symbolic; $force

off redefmsg;

package!-remake2('clprolo, nil);
package!-remake2('revision, 'support);
package!-remake2('clrend, nil);
package!-remake2('entry, 'support);
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

# Compile the "core" packages, each in a separate invocation of
# bootstrap REDUCE to avoid adverse interactions:

time for p in $(< fasl.$lisp/core-packages.dat)
do
echo +++++ Remaking core package $p

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

grep_errors

done

if [ "sl-on-cl.lisp" -nt "sl-on-cl.$faslext" ]
then
echo +++++ Compiling sl-on-cl
$runlisp << XXX &> log.$lisp/sl-on-cl.blg
(or (compile-file "sl-on-cl") (exit #+SBCL :code 1))
XXX
fi || { echo '***** Compilation failed'; exit; }

if [ "trace.lisp" -nt "trace.$faslext" ]
then
echo +++++ Compiling trace
$runlisp << XXX &> log.$lisp/trace.blg
(load "sl-on-cl")
(or (compile-file "trace") (exit 1))
XXX
fi || { echo '***** Compilation failed'; exit; }

echo +++++ Creating the REDUCE image file

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
(load!-package 'poly)
(load!-package 'arith)
(load!-package 'alg)
(load!-package 'mathpr)
(load!-package 'entry)

(cl:fmakunbound 'prettyprint)   % otherwise defautoload has no effect!
(defautoload prettyprint pretty)  % since only in entry file for PSL!

(setq date!* (date))
(setq version!* (cl:format nil "REDUCE (Free ~a version, revision ~a)"
      (cond ((memq 'sbcl lispsystem!*) "SBCL")
            ((memq 'clisp lispsystem!*) "CLISP"))
      revision!*))

(initreduce)

(setq !*verboseload nil)        % inhibit loading messages
(setq !*redefmsg t)             % display redefinition messages

$if_sbcl (setq sb-ext:*muffled-warnings* 'warning)

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

# Finally, compile the "noncore" packages using reduce.img rather than
# bootstrap.img.

time for p in $(< fasl.$lisp/noncore-packages.dat)
do
echo +++++ Remaking noncore package $p

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

grep_errors

done

echo $'\a'
