#! /bin/bash

# This is what "make" invokes. It gets passed as arguments
#      make-targets

# The purpose of this script is to re-invoke "make" in any and all
# sub-directories suitable for the architecture of the current machine.
# This means it will not be very good if you try to set up
# cross-compilation! In that case you must select the relevant directory
# to run the cross build for yourself.

# Note that this tries to identify all potentially relevent build
# directories that contain a "Makefile", that being used as a signature
# that they have been configured. It allows for suffixes such as
# "-debug" as in scripts/findhost.sh.

# Things turn out to be fairly horrid!
# (1) The file-space may be a Reduce tree stored on a NAS and
#     accessed from several computers which have different architectures
#     and can not compile or run code meant for each other. That means
#     I would like to build in just directories associated with builds
#     that can succeed on the current machine.
# (2) Cross compilation (and use of "binfmt") can mean that a single
#     computer may in fact support multiple architectures.
# (3) On Macintosh I may want to build one or more of arm64. x86_64 or
#     univeral versions, but that is not quite cross compilation in the
#     normal style.
# (4) A modern raspberry pi that has a 32-bit operating system installed
#     is liable to use a 64-bit kernel, and autoconf etc (specifically
#     via config.guess) detects the machine as an aarch64 one which is
#     not appropriate.
# (5) When an operating system is upgraded the triple that describes the
#     setup can change. People may or may not want to rebuild or use
#     versions from a previous OS.

# When I first set all this up I viewed scenario (1) as most important,
# but now I think I need to change gear and take a view that if several
# incompatible architectures are to be used then a Reduce source tree
# for each should be used (disc is now a lot cheaper than it was in the
# old days). But then (2), (3) and (4) mean that it makes sense to
# rebuild in all configured directories. Regarding (5) I will now take
# the view that the user should delete directories corresponding to
# older OS releases as part of the release upgrade procedure and that
# maybe when Reduce is launched until they do that they may get a
# version originally configured for the older version of their OS.

printf "MFLAGS=<%s> MKFLAGS=<%s> MAKECMDGOALS=<%s> args=<%s>\n" \
       "$MFLAGS"    "$MKFLAGS"   "$MAKECMDGOALS"   "$*"

# If I pass "--debug=w" to GNU make it reports why each action it takes
# has been triggered. Often that will be along the lines of "update target
# 'foo.o' due to: target does not exist" when you build things for the
# first time. However "make" on the macintosh does not support this
# scheme (only a much more verbose "--debug" options that reports on
# fine-grained activity and is dauntingly bulky). So I apply this everywhere
# except on the Mac.

case `uname` in
*Darwin*)
  MFLAGS=""
  ;;
*)
  if test "`uname -ms`" = "Linux i686"
  then
    MFLAGS=""
  else
    MFLAGS="--debug=w"
  fi
  ;;
esac

args=""
flags=""
buildcsl="no"
buildpsl="no"
buildsbcl="no"
buildclisp="no"
buildccl="no"

for a in $*
do
  if test   "$a" = "csl"
  then buildcsl="yes"
  elif test "$a" = "psl"
  then buildpsl="yes"
  elif test "$a" = "sbcl"
  then buildsbcl="yes";
  elif test "$a" = "clisp"
  then buildclisp="yes";
  elif test "$a" = "ccl"
  then buildccl="yes";
  else args="$args $a"
  fi  
done

# If no lisp at all is selected I will try to build everything that is
# configured.

if test "$buildcsl"  = "no" -a "$buildpsl"   = "no" -a \
        "$buildsbcl" = "no" -a "$buildclisp" = "no" -a \
        "$buildccl"  = "no"
then
  buildcsl="yes"
  buildpsl="yes"
  buildsbcl="yes"
  buildclisp="yes"
  buildccl="yes"
fi

if ! test -d cslbuild
then
  buildcsl="no"
fi
if ! test -d pslbuild
then
  buildpsl="no"
fi
if ! test -d sbclbuild
then
  buildsbcl="no"
fi
if ! test -d clispbuild
then
  buildclisp="no"
fi
if ! test -d cclbuild
then
  buildccl="no"
fi
if test "$buildpsl$buildcsl$buildsbcl$buildclisp$buildccl" = "nonononono"
then
  printf "No lisps seem configured and selected here.\n"
  printf "Nothing to do. Stopping.\n"
  exit 1
fi

# The following arranges that if you go "make csl.exe" or
# "make bootstrapreduce.img" (etc) that the system does not try (in vain)
# to build a PSL version etc.

case $args in
*csl* | *bootstrap* | *reduce.img* | *c-code* | *.com | *.exe)
  buildpsl="no"
  buildsbcl="no"
  buildclisp="no"
  buildccl="no"
  ;;
esac

# config.guess fails on Solaris if SHELL is /usr/bin/env bash.
if test -x /bin/sh
then
  SHELL=/bin/sh
  export SHELL
fi

# This was to do with an experiment that was never followed through...
if test "${REDUCE_SHARED_BUILD_DIRECTORY}" != ""
then
  host=`./config.guess`
  host=`scripts/findhost.sh $host`
  os=`scripts/findos.sh`
  printf "Current machine tag is %s\n" "$host"
fi

if test "$MAKE" = ""
then
  if test -x /usr/sfw/bin/gmake
  then MAKE=/usr/sfw/bin/gmake
  elif test -x /usr/pkg/bin/gmake
  then MAKE=/usr/pkg/bin/gmake
  elif test -x /opt/local/bin/gmake
  then MAKE=/opt/local/bin/gmake
  elif test -x /usr/local/bin/gmake
  then MAKE=/usr/local/bin/gmake
  elif test -x /usr/bin/gmake
  then MAKE=/usr/bin/gmake
  else MAKE=make
  fi
  export MAKE
fi

# I expect directories with two "-" characters in their names in the
# cslbuild or pslbuild directories to be named as host triples. But
# even then I will only try to build in them if there is a "Makefile"
# present. And when that is there I check for a file that should be
# executable on the current platform - if that file is not present or
# it has been built for a different architecture I will ignore the
# directory. This check is what the file called "canary" is about.

procids=""
list=""

viable() {
  if echo "(quit)" | ./$1 >/dev/null 2>/dev/null
  then
    echo "yes"
  else
    echo "no"
  fi 
}

if test "$buildcsl" = "yes"
then
  if test "${REDUCE_SHARED_BUILD_DIRECTORY}" != ""
  then
    case "$os" in
    *cygwin* | *windows*)
      list="cslbuild/*-cygwin*/csl cslbuild/*-windows*/csl"
      ;;
    mac_*)
      list="cslbuild/*${host}*/csl"
      host1=${host/aarch64/universal}
      host1=${host1/x86_64/universal}
      case "$list cslbuild/*${host1}*" in
      \*)
# If there is a "*" still present that indicated that the "universal"
# option did not match any directory so it is not useful.
        ;;
      *)
        list="$list cslbuild/*${host1}*/csl"
        ;;
      esac
      ;;
    *)
      list="cslbuild/*${host}*/csl"
      ;;
    esac
  else
    for d in cslbuild/*-*-*/csl/Makefile
    do
      if test `viable ${d%Makefile}../canary` = "yes"
      then
        w=`dirname $d`
        w=`dirname $w`
        echo Will build for $w
        list="$list $w"
      fi
    done
  fi
fi

firstcsl=${list%% *}
if ! test -f "$firstcsl/Makefile"
then
  firstcsl=""
fi

if test "$buildpsl" = "yes"
then
  if test "${REDUCE_SHARED_BUILD_DIRECTORY}" != ""
  then
    case "$os" in
    *cygwin* | *windows*)
      list="$list pslbuild/*-cygwin* pslbuild/*-windows*"
      ;;
    *)
      list="$list pslbuild/*${host}*"
      ;;
    esac
  else
    for d in pslbuild/*-*-*/Makefile
    do
#     if test `viable ${d%Makefile}psl/bpsl` = "yes"
#     then    
        w=`dirname $d`
        echo Will build for $w
        list="$list $w"
#     fi
    done
  fi
fi

if test "$buildsbcl"  = "yes" || \
   test "$buildclisp" = "yes" || \
   test "$buildccl"   = "yes"
then
  for d in sbclbuild/*-*-*/Makefile \
           clispbuild/*-*-*/Makefile \
           cclbuild/*-*-*/Makefile
  do
    if test `viable ${d%Makefile}canary` = "yes"
    then
      w=`dirname $d`
      echo Will build for $w
      list="$list $w"
    fi
  done
fi

case $args in
# If I am making bootstrapreduce or bootstrapreduce.img or csl or csl.img or
# one of the demo programs I do not need the generated C code...
*bootstrap* | *csl* | *demo* | *psl*)
  firstcsl=""
  ;;
esac

# The complications here are to do with the fact that a CSL build involves
# building a "bootstrapreduce" and using that to map a selection of Reduce
# functions into C++. This mapping is generic across all CSL variants and
# so I *need* it to happen before I complete any one CSL build but I really
# *want* it to happen only once even if I am rebuilding multiple CSL
# variants.
# The scheme I appply is:
# (1) Bring bootstrapreduce and bootstrapreduce.img up to date
#     for all the cases that are to be rebuilt.
# (2) Identify ONE of them ane use it to create the C++ code. This
#     makes files u01.cpp to u60.cpp (and corresponding *.lsp files)
# (3) Continue to build csl and reduce based on what has now been done.

rc=0

if test "$firstcsl" != ""
then
  for dd in $list
  do
    if test -f $dd/Makefile
    then
      printf "++ Build bootstrapreduce.img in directory $dd\n"
      $MAKE $MFLAGS -C $dd $flags $args MYFLAGS="$flags" bootstrapreduce.img
      rc1=$?
      rc=$(($rc1 > $rc ? $rc1 : $rc))
    fi
  done
# Now I use ONE of the perhaps many versions of bootstrapreduce to
# create the generated C++ code.
  $MAKE $MFLAGS -C "$firstcsl" c-code MYFLAGS="$flags"
  rc1=$?
  rc=$(($rc1 > $rc ? $rc1 : $rc))
fi

# Now complete all the builds.

for dd in $list
do
  if test -f $dd/Makefile
  then
    printf "++ Build in directory $dd\n"
    $MAKE $MFLAGS -C $dd $flags $args MYFLAGS="$flags"
    rc1=$?
    rc=$(($rc1 > $rc ? $rc1 : $rc)) 
  fi
done

if test "$rc" = "0"
then
  printf "\nReduce build tasks finished.\n"
else
  printf "\nReduce build tasks finished: Highest return code $rc\n"
fi

exit $rc
