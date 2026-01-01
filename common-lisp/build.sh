#!/bin/bash

# Author: Francis J. Wright <https://sourceforge.net/u/fjwright>
# Time-stamp: <2025-12-30 15:13:21 franc>

# Build REDUCE on supported implementations of Common Lisp (CL),
# namely SBCL, CLISP and CCL.

# Based on "psl/bootstrap.sh" and "psl/build.sh".

# This script assumes that the version of Common Lisp to be used has
# already been built if necessary and installed in a directory on your
# command search path.  It then does the following, where the details
# depend on the Lisp in use:

# 1. Compile "sl-on-cl.lisp", which implements Standard Lisp on Common
#    Lisp.

# 2. Build an initial bootstrap REDUCE system by using only REDUCE
#    source files.  This does not form part of the final REDUCE system
#    and should not need to be rebuilt very often.  It is used to
#    compile a full REDUCE system.

# 3. Compile "trace.lisp", which provides rudimentary function
#    tracing.

# 4. Compile all required fasl files and save a build REDUCE system.

# This script must be run with the top-level CL REDUCE directory
# called "common-lisp" as the current directory.

# Always do a clean build after updating your version of Common Lisp!

function help {
    echo 'Build REDUCE on Common Lisp'
    echo 'Usage: ./build.sh [-h] -l <lisp> [-r revision] [-c/f] [-b]'
    echo '<lisp> = sbcl/clisp/ccl'
    echo 'Option -r sets the REDUCE revision number (overriding the default).'
    echo 'Option -c ensures a clean build by deleting any previous build.'
    echo 'Option -f forces recompilation of all packages.'
    echo 'Option -b builds only the bootstrap REDUCE image.'
    echo 'Option -o builds only the core REDUCE packages.'
    echo 'Option -h displays this help message and exits.'
    exit 1
}

while getopts l:r:cfboh option
do
    case $option in
        l) lisp=$OPTARG;;
        r) revision=$OPTARG;;
        c) clean=true;;
        f) force='!*forcecompile := t;';;
        b) bootstraponly=true;;
        o) coreonly=true;;
        h) help;;
        ?) exit 1;;
    esac
done

# The following commands to run Lisp all suppress the user
# initialisation file.

case $lisp in
    'sbcl')
        runlisp='sbcl --no-userinit --disable-debugger'
        runlispfile='sbcl --no-userinit --disable-debugger --load'
        runbootstrap='sbcl --core fasl.sbcl/bootstrap.img --noinform --no-userinit --disable-debugger'
        runreduce='sbcl --core fasl.sbcl/reduce.img --noinform --no-userinit --disable-debugger'
        saveext='img'
        faslext='fasl'
        ;;
    'clisp')
        runlisp='clisp -ansi -norc -E utf-8'
        runlispfile='clisp -ansi -norc'
        runbootstrap='clisp -q -ansi -norc -M fasl.clisp/bootstrap.mem'
        runreduce='clisp -q -ansi -norc -M fasl.clisp/reduce.mem'
        saveext='mem'
        faslext='fas'
        ;;
    'ccl')
        if [ "$(type -ft ccl64)" ]; then CCL='ccl64'; else CCL='ccl'; fi
        runlisp="$CCL -n"
        runlispfile="$CCL -n -l"
	runbootstrap="$CCL -n -I fasl.ccl/bootstrap.image"
        runreduce="$CCL -n -I fasl.ccl/reduce.image"
        saveext='image'
        case $(uname -s) in     # see CCL64 shell script in Clozure distribution
            Darwin)             # macOS
                faslext='dx64fsl';;
            Linux)
                faslext='lx64fsl';;
            CYGWIN*)            # MS Windows
                faslext='wx64fsl';;
        esac
        ;;
    *)
        echo 'Error: option "-l <lisp>" is required'
        help
        ;;
esac

if [ $clean ]; then
    echo '+++++ Clean build'
    rm -rf fasl.$lisp log.$lisp
fi

if [ -z "$reduce" ]; then
    if [ -e './packages' ]; then export reduce=.
    elif [ -e '../packages' ]; then export reduce=..
    else echo 'Error: cannot find packages directory.  Please set $reduce.'; exit 1
    fi
fi

if [ -z "$revision" ] && type svnversion > /dev/null; then
    packages="$reduce/packages"
    # If $packages is a symlink then follow it (if possible):
    if [ -L $packages ] && type readlink > /dev/null; then
        packages=$(readlink -n "$packages")
    fi
    revision=$(svnversion -n "$packages")
    # Value may be (e.g.) 4123:4168MSP so extract the second number:
    revision=${revision/#*:}     # delete first number and ":"
    revision=${revision/%[A-Z]*} # delete trailing letters
fi
if [[ "$revision" =~ ^[[:digit:]]+$ ]]; then
    echo '+++++ REDUCE revision number set to' $revision
else
    unset -v revision
fi

mkdir -p log.$lisp           # -p avoids complaint if directory exists
mkdir -p fasl.$lisp

#################################
# Compile sl-on-cl if necessary #
#################################

if [ "sl-on-cl.lisp" -nt "fasl.$lisp/sl-on-cl.$faslext" ]
then
    echo $'\n+++++ Compiling sl-on-cl'
    time eval $runlisp << EOF &> log.$lisp/sl-on-cl.blg &&
(or (compile-file "sl-on-cl.lisp")
    #+CCL (quit 1)
    #-CCL (exit #+SBCL :code 1))
EOF
    mv sl-on-cl.$faslext fasl.$lisp &&
        if [ $lisp = 'clisp' ]; then rm sl-on-cl.lib; fi
fi || { echo '***** Compilation failed'; exit 1; }

########################################################
# Build an initial bootstrap REDUCE image if necessary #
########################################################

function grep_errors {
    grep -i '^\*\{5\} \| error \|COMMON-LISP:ERROR' log.$lisp/$1.blg | uniq |\
        grep -viw errorset      # except matching lines
}

if [ ! -e fasl.$lisp/bootstrap.$saveext ]
then
    echo $'\n+++++ Building bootstrap REDUCE...'
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

echo $'\n+++++ Building REDUCE...'

eval $runbootstrap << EOF &> log.$lisp/build.blg
symbolic; $force

off redefmsg;

% First, compile fasl files for non-package source files:

package!-remake2('clprolo, nil);
package!-remake2('clrend, nil);
package!-remake2('entry, 'support);
package!-remake2('smacros,'support);
package!-remake2('remake, nil); % for building noncore packages

% Second, create .dat files that list core and non-core modules to build:

begin
   scalar w, i, s, core, noncore;
   i := open("$reduce/packages/package.map", 'input);
   s := rds i;
   w := read();
   rds s;
   close i;
   for each x in w do     % x is a row of package.map
      if member('csl, x) and member('psl, x) then <<
         if member('core, x) then
            << if not (car x eq 'revision) then
               core := car x . core >>
         else noncore := car x . noncore >>;
   i := open("fasl.$lisp/core-packages.dat", 'output);
   s := wrs i;
   for each x in reverse core do print x;
   wrs s;
   close i;
   i := open("fasl.$lisp/noncore-packages.dat", 'output);
   s := wrs i;
   for each x in reverse noncore do print x;
   wrs s;
   close i;
end;

bye;
EOF

if [ ! -e fasl.$lisp/core-packages.dat -o ! -e fasl.$lisp/noncore-packages.dat ]
then echo '***** Running bootstrap REDUCE failed'; exit 1
fi

# Compile the "core" packages, each in a separate invocation of
# bootstrap REDUCE to avoid adverse interactions:

time for p in $(< fasl.$lisp/core-packages.dat)
do
    echo "+++++ Remaking core package $p"
    eval $runbootstrap << EOF &> log.$lisp/$p.blg
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
EOF

grep_errors $p

done

if [ $coreonly ]; then exit; fi

##############################
# Compile trace if necessary #
##############################

if [ "trace.lisp" -nt "fasl.$lisp/trace.$faslext" ]
then
    echo $'\n+++++ Compiling trace'
    time eval $runlisp << EOF &> log.$lisp/trace.blg &&
(load "fasl.$lisp/sl-on-cl")
(or (compile-file "trace.lisp")
    #+CCL (quit 1)
    #-CCL (exit #+SBCL :code 1))
EOF
    mv trace.$faslext fasl.$lisp &&
        if [ $lisp = 'clisp' ]; then rm trace.lib; fi
fi || { echo '***** Compiling trace failed'; exit 1; }

###############################
# Build the REDUCE image file #
###############################

echo $'\n+++++ Building the REDUCE image file...'

# Start a new invocation of Lisp and load the key modules compiled
# above.  Then save a final REDUCE image that will be used below to
# compile the non-core modules.

time eval $runlisp << EOF &> log.$lisp/reduce.blg
(load "fasl.$lisp/sl-on-cl")
(load "fasl.$lisp/trace") ; temporary -- until I can arrange autoloading!
(standard-lisp)

(cl:defparameter !*init!-stats!* (list (time) (gtheap)))

(setq !*verboseload t)
(setq !*redefmsg nil)
(cl:defvar !*argnochk t)        % check argument count

(load "module")                 % for definition of load-package
(load "clprolo")                % initial CL specific code

(cl:defvar revision!* $revision)
(cl:if (not (cl:boundp 'revision!*)) (setq revision!* nil))
(load!-package 'rlisp)
(load!-package 'clrend)
(load!-package 'smacros)
(load!-package 'poly)
(load!-package 'arith)
(load!-package 'alg)
(load!-package 'rtools)
(load!-package 'mathpr)
(load!-package 'entry)

% cf. support/fastmath.red:
(flag '(sin cos tan sind cosd tand cotd secd cscd asin acos atan
   asecd acscd atan2d atan2 sqrt exp log hypot cosh sinh tanh) 'lose)

(cl:fmakunbound 'prettyprint)   % otherwise defautoload has no effect!
(defautoload prettyprint pretty)  % since only in entry file for PSL!

(setq date!* (date))
(setq version!* (cl:format nil "REDUCE (Free ~a version, revision ~a)"
      (cond ((memq 'sbcl lispsystem!*) "SBCL")
            ((memq 'clisp lispsystem!*) "CLISP")
            ((memq 'ccl lispsystem!*) "CCL"))
      (or revision!* "???")))

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

EOF

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
    eval $runreduce << EOF &> log.$lisp/$p.blg
symbolic; $force

on verboseload;
off redefmsg;

if '$p eq 'fps then load_package limits,factor,specfn,sfgamma
else if '$p eq 'mrvlimit then load_package taylor
% Temporary hacks to avoid build errors:
else if '$p eq 'corrundum then flag('(flush),'rlisp)
else if '$p eq 'tmprint then <<
   lispsystem!* := 'psl . lispsystem!*;
   switch usermode >>;

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

package!-remake '$p; % autoloads remake

% Temporary hack to make gnuplot package work on Common Lisp:
if '$p eq 'gnuplot then
   begin scalar !*int, !*forcecompile := t;
      update!-fasl2('gnuintfc, nil);
   end;

bye;
EOF

grep_errors $p

done

echo $'\n+++++ Built REDUCE.\a'
