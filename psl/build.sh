#! /bin/sh

# Do a complete rebuild of PSL
#
# Usage:
#         .../psl/build.sh

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
cfasl=$chere/red

if test -x /usr/bin/cygpath
then
  psldir=`cygpath -m "$cpsldir"`
  reduce=`cygpath -m "$creduce"`
  here=`cygpath -m "$chere"`
  fasl=`cygpath -m "$cfasl"`
else
  psldir="$cpsldir"
  reduce="$creduce"
  here="$chere"
  fasl="$cfasl"
fi

if test -f psl/64
then
STORE=600
else
STORE=64000000
fi

export here fasl psldir reduce

if test -d red
then
  rm -rf red
fi
mkdir red

if test -d log
then
  rm -rf log
fi
mkdir log

cd psl

echo ++++++ Build initial bootstrap system ++++++

./bpsl -td $STORE <<XXX > $chere/log/bootstrap.blg
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

(setq prolog_file 'pslprolo)

(setq rend_file 'pslrend)

(copyd 'rdf 'dskin)                   % CSL has a nicer name for this.

(global '(oldchan!* datchan!*))       % datchan!* needed for MS-DOS.

(setq !*argnochk t)
(setq !*int nil)                    % Prevents input buffer being saved.
(setq !*msg nil)
(setq !*comp t)               % It's faster if we compile the boot file.

(rdf "$reduce/psl/boot.sl")

(begin2)

rds(xxx := open("$reduce/packages/support/build.red",'input));

(close xxx)

(load!-package!-sources prolog_file 'support)
(load!-package!-sources 'rlisp 'rlisp)
(load!-package!-sources rend_file 'support)
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
package!-remake2(prolog_file,'support);
package!-remake2(rend_file,'support);
package!-remake2('entry,'support);
package!-remake2('remake,'support);
package!-remake2('patches,'support);

% Create the .dat files that indicate which modules will need building

begin
  scalar w, i, s, core, noncore;
  i := open("$reduce/packages/package.map", 'input);
  s := rds i;
  w := read();
  rds s;
  close i;
  for each x in w do
     if member('psl, x) then <<
        if member('core, x) then core := x . core
        else noncore := x . noncore >>;
  i := open("$fasl/core-packages.dat", 'output);
  s := wrs i;
  for each x in reverse core do print car x;
  close i;
  i := open("$fasl/noncore-packages.dat", 'output);
  s := wrs i;
  for each x in reverse noncore do print car x;
  close i;
  wrs s
end;

savesystem("BOOTSTRAP REDUCE", "$here/bootstrap");

bye;

XXX

cd $chere

# On some systems (yes I am talking about Windows!) the core-packages.dat
# file that gets created above will have CR-LF line separation. The shell
# loop below would tend to get muddled by this! Now I could try to reset]
# the shell variable IFS to be a string with space, tab, carriage return
# and line-feed in it. But setting that up is not that comfortable to do,
# so instead I pipe things through "dos2unix" if that exists and expect that
# in the situations where this is important that it will exist and do the
# trick.

if test -x /usr/bin/dos2unix
then
  catcmd=dos2unix
else
  catcmd=cat
fi

# Now I need to compile the main bunch of "core" modules... These are each
# built in a freshly-loaded system since otherwise there can be bad effects
# from left-over declarations and the like.

for p in `$catcmd < $cfasl/core-packages.dat`
do
echo ++++++ About to make $p ++++++

psl/bpsl -td $STORE -f bootstrap.img <<XXX > log/$p.blg

symbolic;

load compiler;
errorset('(load compat),nil,nil); % PSL compiler support.
on verboseload;

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

bye;
XXX

done

echo ++++++ Now create the reduce image file ++++++

cd psl

./bpsl -td $STORE <<XXX > $chere/log/reduce.blg
% This re-starts a bare reduce and loads in the modules compiled
% by the very first step. It then checkpoints a system that can be
% used to rebuild all other modules.

(setq symbolfilename!* "$here/psl/bpsl")
(setq loaddirectories!* (quote ("" "$here/red/" "$here/psl/")))

(reclaim)
(setq !*init!-stats!* (list (time) (gtheap nil) (free-bps) nextsymbol))

(setq !*usermode nil)
(setq !*verboseload t)
(setq !*argnochk t)                % Check argument count.
(setq prolog_file 'pslprolo)
(setq rend_file 'pslrend)

(cond ((filep "symget.b")
       (dskin "$reduce/psl/symget.dat")))

(cond ((filep "addr2id.b")
       (load addr2id)))            % For debugging purposes.

(cond ((filep "pipes.b")
       (load pipes)))              % Unix pipes.

(load zbig)                        % PSL bignums.
(errorset '(load compat) nil nil)  % Load PSL-based functions if there.
(load module)                      % Contains definition of load-package.
(load pslprolo)                    % PSL specific code.

(load!-package 'rlisp)
(load!-package rend_file)
(load!-package 'poly)
(load!-package 'arith)
(load!-package 'alg)
(load!-package 'mathpr)
(load!-package 'entry)
(setq version!* "REDUCE Experimental Version") (setq date!* (date))
(initreduce)

(setq !*loadversion t)             % Load entry module during BEGIN.
(setq !*verboseload nil)           % Inhibit loading messages.

(cond ((and (memq (quote sparc) lispsystem!*)
            (getd (quote supersparc)))
       (supersparc)))

(prog nil
   (reclaim)
   (terpri)
   (prin2 "Time for build: ")
   (prin2 (quotient (difference (time) (car !*init!-stats!*)) 1000.0))
   (prin2t " secs")
   (prin2 "Symbols used:   ")
   (prin2t (difference nextsymbol (cadddr !*init!-stats!*)))
   (prin2 "Heap used:      ")
   (prin2t (difference (cadr !*init!-stats!*) (gtheap nil)))
   (prin2 "BPS used:       ")
   (prin2t (difference (caddr !*init!-stats!*) (free-bps)))
   (prin2 "Heap left:      ")
   (prin2t (gtheap nil))
   (prin2 "BPS left:       ")
   (prin2t (free-bps))
  (setq !*init!-stats!* nil))

(savesystem "REDUCE" "$fasl/reduce" (quote ((read-init-file "reduce"))))
(bye)

XXX

cd $chere

# Now I can re-build the remaining packages using the genuine
# final reduce.img rather than just the bootstrap one

for p in `$catcmd < $cfasl/noncore-packages.dat`
do
echo ++++++ About to make noncore $p ++++++

psl/bpsl -td $STORE -f red/reduce.img <<XXX > log/$p.blg

symbolic;

load compiler;
errorset('(load compat),nil,nil); % PSL compiler support.
on verboseload;

% Specific package loads to avoid BPS problems.
if '$p eq 'susy2 then flag('(susy2),'lap)
else if '$p eq 'fps then load_package limits,factor,specfn,sfgamma
else if '$p eq 'mrvlimit then load_package taylor;

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

bye;
XXX

done
