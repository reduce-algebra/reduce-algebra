#! /bin/sh

# Extract from build.sh to only save a new image.
# Takes build dir and toplevel pslbuild dir pathname as arguments
# Optional third argument is topdir to be used for load-path in saved image
#
# Usage:
#         .../psl/saveimage.sh .../builddir /usr/lib/reduce/pslbuild [topdir]

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

if test -n "$2"
then
  builddir="$1"
  imagedir="$2"
  logdir="$builddir/log"
  mkdir -p "$imagedir"

  if test -z "$3"
  then
    topdir="$here"
  else
    topdir="$3"
  fi

  cfasl="$builddir/red"

  bhere="$builddir"

  logfile=saveimage.blg

else

  builddir=.
  imagedir=../red
  logdir=../buildlogs
  cfasl=red

  bhere=`pwd`

  logfile=reduce.img.blg

  echo Create red/reduce.img for architecture $1
fi

cpsldir=`echo $c | sed -e 's+/[^/]*$++'`
creduce=$cpsldir/..
chere=`pwd`

if test -x /usr/bin/cygpath
then
  psldir=`cygpath -m "$cpsldir"`
  reduce=`cygpath -m "$creduce"`
  here=`cygpath -m "$chere"`
  bhere=`cygpath -m "$bhere"`
  fasl=`cygpath -m "$cfasl"`
  imagedir=`cygpath -m "$imagedir"`
  logdir=`cygpath -m "$logdir"`
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

mkdir -p "$logdir"

cd "$builddir"

cd psl

./bpsl -td $STORE <<XXX > "$logdir/$logfile"

% This re-starts a bare reduce and loads in the modules compiled
% by the very first step. It then checkpoints a system that can be
% used to rebuild all other modules.

(setq symbolfilename!* "$bhere/psl/bpsl")
(setq loaddirectories!* (quote ("" "$bhere/red/" "$bhere/psl/")))

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
(errorset '(load pslcompat) nil nil)  % Load PSL-based functions if there.
(load module)                      % Contains definition of load-package.
(load pslprolo)                    % PSL specific code.

(load!-package 'revision)
(load!-package 'rlisp)
(load!-package rend_file)
(load!-package 'poly)
(load!-package 'arith)
(load!-package 'alg)
(load!-package 'mathpr)
(load!-package 'entry)
(setq version!* (compress (append
   (explode2 """Reduce (Free PSL version, revision ")
   (append (explode2 revision!*) '(!) !")))))
(setq date!* (date))
(initreduce)

(setq !*loadversion t)             % Load entry module during BEGIN.
(setq !*verboseload nil)           % Inhibit loading messages.

(cond ((and (memq (quote sparc) lispsystem!*)
            (getd (quote supersparc)))
       (supersparc)))

(flag '(fancy) 'switch)

(put 'fancy 'simpfg
  '((t (load fmprint) (fmp!-switch t))
    (nil (load fmprint) (fmp!-switch nil)) ))

% implant graphics mode switch

(setq *fancy nil)

(cond ((not (unboundp 'win-messages))
      (putv win-messages 3 '(~on '(fancy)))
      (putv win-messages 4 '(and *fancy (~off '(fancy))))))

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

(de alterheapsize (d) (rederr "Sorry, but at present the Heap cannot be extended. Please start Reduce again with a larger heap (-td parameter) and rerun."))

(setq symbolfilename!* "$topdir/psl/bpsl")
(setq loaddirectories!* (quote ("" "$topdir/red/" "$topdir/psl/")))

(savesystem "REDUCE" "$imagedir/reduce" (quote ((commandline_setq)
                                                (set-load-directories)
                                                (read-init-file "reduce")
			(cond ((member "--texmacs" (vector2list unixargs!*))
						(load tmprint))))))
(bye)

XXX

cd $chere

