#! /bin/sh

# Build an initial bootstrap REDUCE core that can be used to
# compile the rest of the system
#
# Usage:
#         .../psl/bootstrap.sh  architecture

# This script must live in the PSL directory, but it builds things in the
# current directory.

a=$0
c=unknown
case $a in
/* )
  c=$a  
  ;;
*/* )
  case $a in
  ./* )
    a=`echo $a | sed -e s+./++`
    ;;
  esac
  c=`pwd`/$a
  ;;
* ) 
  for d in $PATH
  do
    if test -x $d/$a
    then
      c=$d/$a
    fi
  done
  if test $c = "unknown" ;then
    echo "Unable to find full path for script. Please re-try"
    echo "launching it using a fully rooted path."
    exit 1
  fi
  ;;
esac

cpsldir=`echo $c | sed -e 's+/[^/]*$++'`
creduce=$cpsldir/..
chere=`pwd`

# If I am running under a cygwin shell at build time (and I expect to be
# on Windows) then in som eplaces I need cygwin-style paths and in others
# native windows-style ones. Well for the latter I can get away with
# "mixed" style. So eg /cygdrive/c/somewhere/file.ext  vs c:/somewere/file.ext

if test -x /usr/bin/cygpath
then
  psldir=`cygpath -m "$cpsldir"`
  reduce=`cygpath -m "$creduce"`
  here=`cygpath -m "$chere"`
else
  psldir="$cpsldir"
  reduce="$creduce"
  here="$chere"
fi

fasl=../red

export fasl here psldir reduce

# The next bit is both a bit of a kludge and is something I do not fully
# understand. Some variants of 64-bit PSL interpret their "-td" paramater
# differently. When this is to be the case a small file called "64" is placed
# in the directory where the binaries live. So on the plain versions I
# recompile in 64 Megabytes and on "64-bit" systems I use "2000".

if test -f psl/64
then
STORE=600
else
STORE=64000000
fi

if test -d red
then :
else
  mkdir red
fi

if test -d deps
then :
else
  mkdir deps
fi

# I keep logs in a directory as named here.
mkdir -p buildlogs

# The initial build MUST be performed in the directory where the
# core PSL binaries had been placed. This is a feature of PSL and is
# because when a bare PSL is first loaded it only knows to load
# fasl files from the current directory. One of the first things that
# is done here is to specify the absolute path for future loading.

cd psl

echo ++++++ Build initial bootstrap system ++++++

./bpsl -td $STORE <<XXX > ../buildlogs/bootstrap.blg

% This starts with a bare version of PSL. It loads various compatibility
% and optimisation modules, then creates a bootstrap version of the
% REDUCE parser. It uses the resulting very initial version of a REDUCE
% core to compile key REDUCE modules that are needed when re-compiling the
% rest of the system. It does not checkpoint itself at the end of this
% because the general Lisp environment will be in a somewhat untidy state,
% so a separate stage will load up the modules compiled here and checkpoint
% them to make the REDUCE bootstrap build system.


(setq symbolfilename!* "$here/psl/bpsl")
(setq loaddirectories!* '("" "$here/red/" "$here/psl/"))

(load addr2id)   % In case an error occurs.

(setq !*fastcar t)
(setq !*usermode nil)
(setq !*verboseload t)

(remprop 'cursym!* 'vartype)          % PSL declares this fluid.

% Compiler modifications.

(load compiler)
(remprop 'wplus2 'one)                % PSL compiler bug.
(remprop 'log 'no!-side!-effects!?)   % So that math can be fasled.
(remprop 'atan 'no!-side!-effects!?)  % So that math can be fasled.
(remprop '!*msg 'vartype)             % Compiler declares this global.
(load fast!-vector)                   % To use IGETV, etc.

(cond ((filep "symget.b")
       (dskin "$reduce/psl/symget.dat")))

(load zbig)                           % PSL bignums.

(errorset '(load compat) nil nil)     % Load PSL accelerators if there.

(flag '(eqcar) 'lose)                 % Already in PSL.

(setq !*init!-time!* (time))

(copyd 'rdf 'dskin)                   % CSL has a nicer name for this.

(global '(oldchan!* datchan!*))       % datchan!* needed for MS-DOS.

(setq !*argnochk t)
(setq !*int nil)                      % Prevents input buffer being saved.
(setq !*msg nil)
(setq !*comp t)                       % It's faster if we compile the boot file.

(rdf "$reduce/psl/boot.sl")

(begin2)

rds(xxx := open("$reduce/packages/support/build.red",'input));

(close xxx)

(load!-package!-sources 'pslprolo 'support)
(load!-package!-sources 'rlisp 'rlisp)
(load!-package!-sources 'pslrend 'support)
(load!-package!-sources 'poly 'poly)
(load!-package!-sources 'alg 'alg)
(load!-package!-sources 'arith 'arith)  %  Needed by roots, specfn*, (psl).
(load!-package!-sources 'entry 'support)
(load!-package!-sources 'remake 'support)

(setq !*comp nil)
(setq !*verboseload nil)

(prog nil
   (reclaim)
   (prin2 "Time for build: ")
   (prin2 (quotient (difference (time) !*init!-time!*) 1000.0))
   (prin2t " secs")
   (prin2 "Heap left:      ")
   (prin2t (gtheap nil))
   (prin2 "BPS left:       ")
   (prin2t (free-bps)))

(initreduce)

(setq date!* (date))

(setq version!* "Bootstrapping REDUCE")

(cond (datchan!* (rds datchan!*)))    % Needed for MS-DOS systems.

(begin)
symbolic;
!*argnochk := t;
load compiler;
errorset('(load compat),nil,nil);
on verboseload;
if not getd 'package!-remake2 then load remake;
package!-remake2('pslprolo,'support);
package!-remake2('pslrend,'support);
package!-remake2('entry,'support);
package!-remake2('remake,'support);
% package!-remake2('patches,'support);

% I create various Makefile dependencies and lists here.

begin
  scalar w, i1, i2, i3, i4, f1, f2, s, core;
  i1 := open("$reduce/packages/package.map", 'input);
  s := rds i1;
  w := read();
  rds s;
  close i1;
  prin2 "map = "; print w;
  i1 := open("../deps/core-packages.psl-make", 'output);
  i2 := open("../deps/core-packages.psl-depend", 'output);
  i3 := open("../deps/noncore-packages.psl-make", 'output);
  i4 := open("../deps/noncore-packages.psl-depend", 'output);
  s := wrs i2;
  prin2 "red/reduce.img:";
  wrs i4;
  prin2 "reduce:";
  for each x in w do
     if member('psl, x) then <<
        if member('core, x) then << core := t; f1 := i1; f2 := i2 >>
        else << core := nil; f1 := i3; f2 := i4 >>;
        wrs f1;
        prin2 "red/";
        prin2 car x;
        prin2 ".b:";
        if core then prin2 "	red/bootstrap.img"
        else prin2 "	red/reduce.img";
        terpri();
        prin2 "	\$(srcdir)/";
        if not core then prin2 "non";
        prin2 "coremodule.sh ";
        prin2 car x;
        prin2 " \$(BUILD)";
        terpri();
        terpri();
        prin2 "deps/";
        prin2 car x;
        prin2 ".psl-depend:";
        terpri();
        prin2 "	touch deps/";
        prin2 car x;
        prin2 ".psl-depend";
        terpri();
        terpri();
        prin2 "-include deps/";
        prin2 car x;
        prin2 ".psl-depend";
        terpri();
        terpri();
        wrs f2;
        prin2 " \";
        terpri();
        prin2 "	red/";
        prin2 car x;
        prin2 ".b" >>;
  wrs i2;
  terpri();
  wrs i4;
  terpri();
  close i1;
  close i2;
  close i3;
  close i4;
  wrs s
end;

initreduce();

savesystem("BOOTSTRAP REDUCE", "../red/bootstrap");

bye;

XXX

cd $chere

# On Windows (and I will be building from a cygwin environment but
# typically creating a native Windows copy of the package) PSL will
# create the dependency files with DOS-style line-termination. This
# would really confuse "make", so here I concert to Unix form. In a
# cygwin world I expect dos2unix to be available in the location tested
# for here, and on most other systems this is irrelevant or harmless.

if test -x /usr/bin/dos2unix
then
  dos2unix deps/core-packages.psl-make
  dos2unix deps/core-packages.psl-depend
  dos2unix deps/noncore-packages.psl-make
  dos2unix deps/noncore-packages.psl-depend
fi

echo Bootstrap reduce built
