#! /bin/sh
#
# This is a script for rebuilding a CSL-based Reduce system in either
# a release or development world. You should select the directory that
# you want Reduce buily in as current and tben run this.
#
# The INTENT is that this should run under a fairly vanilla version of
# the "sh" Bourne shell, but it will be developed and mostly tested
# on systems where the real shell in place is "bash"...
#
# Hmm - a consequence of that is that I can not rely on having shell
# procedures, and at some stage I will need to review the other bits of
# coding style to avoid things that may not work fully cross-platform.

# Record the directory I am in at the start so that I can restore it at the
# end

build_directory=`pwd`

# Find the directory that this script was called from.
# I expect that $0 to this script will give me the name of the current script.
# This will be interpreted in the way bash (and perhaps other shells) find
# commands:
# If the name does not contain a "/" it is expected that $PATH contains
#     a directory with an executable file of that name in it;
# If the name starts with a "/" it is an absolute path;
# In remaining cases it is relative to the current working directory.
#
# Given the above rules I can convert the name to give me an absolute
# path... I do a minor tidy-up involving commands called "./something"
# in that I remove the "./" when it is unnecessary.

# I will use single-letter shall variable names for temporary work-space and
# longer clearer names when I end up with something worth keeping.

a=$0
c=unknown
case $a in
/* )
  c=$a
  ;;
*/* )
  case $a in
  ./* )
    a=`echo $a | sed -e 's/\.\///'`
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
  ;;
esac

# The error case here ought never to arise...

case $c in
unknown )
  echo "Unable to find full path for script. Please re-try"
  echo "launching it using a fully rooted path."
  exit 1
  ;;
esac

echo Full path of script is $c

# Now I want the directory that this script is in. So I remove the
# tail of its full name, from the final "/" to the end of the string.

# Now if I do that and the path has an internal part of the form
#           path1/../path2
# then the ".." really messes things up for me. I could deal with that
# one way by getting the parent directories bt sticking "/.." on the end
# of what I have, but I think I will try to tidy things up another
# way first. Specifically I will try to find any sub-strings in the
# path that are of the form "/xxx/../ and remove them. Well as I think of
# that I ought to remove any instances of "/./" as well!

c=`echo $c | sed -e 's/\/\.\//\//'`
c=`echo $c | sed -e 's/\/\.\//\//'`
c=`echo $c | sed -e 's/\/[^/.][^/]*\/\.\.\//\//'`
c=`echo $c | sed -e 's/\/[^/.][^/]*\/\.\.\//\//'`
c=`echo $c | sed -e 's/\/[^/.][^/]*\/\.\.\//\//'`

util_directory=`echo $c | sed -e 's/\/[^/]*$//'`
csl_directory=`echo $util_directory | sed -e 's/\/[^/]*$//'`
lisp_directory=`echo $csl_directory | sed -e 's/\/[^/]*$//'`
reduce_directory=`echo $lisp_directory | sed -e 's/\/[^/]*$//'`
cslbase_directory=$csl_directory/cslbase

echo util_directory = $util_directory
echo csl_directory = $csl_directory
echo lisp_directory = $lisp_directory
echo reduce_directory = $reduce_directory
echo cslbase_directory = $cslbase_directory

# I test for just a few files that I expect to be in the "cslbase"
# place. If any are missing then I am in a mess. At present I do not
# check that the rest of what should be there is in a good state - I hope
# that "make" and the C/C++ compilers will reject anything that is
# messed up.

if test ! -f $cslbase_directory/configure.ac || \
   test ! -f $cslbase_directory/Makefile.am || \
   test ! -f $cslbase_directory/Makefile.in || \
   test ! -f $cslbase_directory/aclocal.m4 || \
   test ! -f $cslbase_directory/config.h.in || \
   test ! -f $cslbase_directory/configure || \
   test ! -f $cslbase_directory/csl.c
then
  echo "Some autoconfig-related files are not present in the CSL"
  echo "source directory. Please update it and try again."
  exit 1
fi

echo reduce_directory = $reduce_directory

# In the release system the support packages directory lives in $csl_directory
# while the development tree keeps it in $reduce_directory. Sort
# out which to use. Complain if both versions seem to exist since that
# represents a confusing situation

if test -d $reduce_directory/support-packages
then
  if test -d $csl_directory/support-packages
  then
    echo "Two copies of the support-packages directory found."
    echo "Please remove one of them to avoid confusion."
    exit 1
  else
    support_directory="$reduce_directory/support-packages"
  fi
elif test -d $csl_directory/support-packages
then
  support_directory="$csl_directory/support-packages"
else
# If the support directory is not available then FOX and the GUI parts
# of the system can not be built, but the rest can.
  echo "support-directory not found in $csl_directory or"
  echo "$reduce_directory. GUI will not be built."
  support_directory=""
fi

# The "config.guess" script finds a GNU-style triple to identify the
# machine being used. Eg "i686-pc-cygwin". The script us inder the GNU
# license but with a special excepotion that if it is distributed along 
# with a program that contains a configuration script generated by
# Autoconf it can be distributed under the terms that apply to that
# program. In this instance the program concerned is CSL.

# It may be that I could just use a built-in shell variable $MACHTYPE
# here. But if that was generally possible why whould autoconf supply
# config.guess?

machine=`/bin/sh $csl_directory/cslbase/config.guess`

echo machine=$machine

# There will be a number of arguments that I can pass to this script that
# fine-tune the build that it done. They are
#
#    --enable-debug            build for debugging
#    --with-xp64               experimental cross-build for 64-bit windows
#    --with-cygwin             use Cygwin X11 build and rely on cygwin1.dll
#    --with-m32                if compiling with gcc force 32-bit usage
#    --with-m64                if compiling with gcc force 64-bit usage
#
#    --without-fox             disable building the GUI
#
# These particular flags are also detected and interpeted in the same way
# by the various other scripts that I have.

xmachine="$machine"

for x in $*
do
  case $x in
  --enable-debug)
    enable_debug="--enable-debug"
    ;;
  --with-xp64)
    with_xp64="--with-xp64"
    ;;
  --with-cygwin)
    with_cygwin="--with-cygwin"
    ;;
  --with-m32)
    with_m32="--with-m32"
    ;;
  --with-m64)
    with_m64="--with-m64"
    ;;
  --without-fox)
    without_fox="yes"
    ;;
  esac
done

# As well as setting simple flags for each option I create an adjusted
# "machine type" that reflects the options selected. This is used as a
# directory name to hold a compiled version of FOX suitable for the
# configuration  concerned.

if test "x$with_xp64" != "x"
then
  xmachine="x64-pc-windows64"
fi

if test "x$with_cygwin" = "x"
then
  xmachine=`echo $xmachine | sed -e 's/cygwin/mingw/'`
fi

if test "x$with_m32" != "x"
then
  xmachine="$xmachine-m32"
elif test "x$with_m64" != "x"
then
  xmachine="$xmachine-m64"
fi

if test "x$with_debug" != "x"
then
  xmachine="$xmachine-debug"
fi

echo "xmachine = $xmachine"

# This script decides what to compile based on a collection of
# signatures generated using "md5". It keeps its set of signatures
# in a file "signature.sh" in the build directory. When first used
# this file will not exist, and that will cause a complete rebuild
# to be performed. Subsequently things will only be re-build if
# relevant base files have changed.

unset fox_signature
unset fox_md5

if test -x $build_directory/signature.sh
then
  . $build_directory/signature.sh
fi

# At least while developing this I will display the values that I might
# extract from the signature file.

echo fox_signature=$fox_signature
echo fox_md5=$fox_md5

# If the file $support_directory/build-all.sh does not exist then
# it is clear that the FOX sources and build scripts have not been
# downloaded, so there is not point in trying to fuss about
# whether it needs building or rebuilding

if test "x$without_fox" != "xyes" &&
   test "x$support_directory" != "x" &&
   test -f $support_directory/build-all.sh
then

  if test -d $reduce_directory/fox
  then
    fox_directory="$reduce_directory/fox/$xmachine"
  elif test -d $csl_directory
  then
    fox_directory="$csl_directory/fox/$xmachine"
  else
    fox_directory="$csl_directory/fox/$xmachine"
    echo "Need to create FOX directory: using $fox_directory"
  fi
  if ! test -d $fox_directory
  then
    mkdir -p $fox_directory
  fi
  with_fox="--with-fox=$fox_directory"

# I want to get signatures for the FOX source and binary files. If either
# have changed since I last ran this script I will rebuild FOX.
#
# I do the check in two stages to try to reduce cost. First I check
# the output from "ls -l" on the relevant files. If that has not changed at
# all I will assume that the files have not been altered. Note that this is
# not a 100% secure judgement in either direction! If the "ls -l" information
# has changed (note eg that it will on the day that a file becomes over 6
# months old, even though the file has not changed: "ls" changes its display
# format about then!) I will re-compute MD5 checksums.

  fox_files="$support_directory/fox*.gz $support_directory/*.patches"
  fox_files="$fox_files $support_directory/build-all.sh"
  fox_files="$fox_files $support_directory/build-fox*.sh"
  fox_files="$fox_files $fox_directory/include/fox-1.6/*.h"
  fox_files="$fox_files $fox_directory/lib/*.*"

  if test -f fox_files.log
  then
    mv fox_files.log fox_files.log.old
  fi
  ls -l $fox_files > fox_files.log
  current_fox_signature=`ls -l $fox_files | md5sum | sed -e 's/ .*$//'`

  echo "current fox_signature = $current_fox_signature"

# If the checksum on "ls" output agrees with the value (if any) that I had
# stored than I will assume that the files have not changed, and I reflect
# that by assuming that their MD5 sum is as it was last time. If the
# "ls" checksum disagrees I will re-compute the MD5 checksum. This may
# in fact still match and reveal that there has not been a change. There
# are two particularly notable cases when this could arise:
# (a) a file has been "touched" and its date-stamp has altered, but the
#     contents have not changed;
# (b) the output from "ls -l" has changed, because of a file's age, from
#     the layout that gives the hour and minute of update to the version
#     that gives just date and year.  Eg observe the two forms in this
#     2-line extract created in mid-August 2006:
#       -rwxr-xr-x+ 1 acn1 None  159744 Feb 18  2002 unzip.exe
#       -rwxr-xr-x+ 1 acn1 None    4876 Aug  9 21:46 xport.chk

  if test "x$fox_signature" = "x$current_fox_signature" &&
     test "x$fox_md5" != "x"
  then
    current_fox_md5="$fox_md5"
  else
    current_fox_md5=`md5sum $fox_files | md5sum | sed -e 's/ .*$//'`
  fi

  echo "current fox_md5 = $current_fox_md5"



# I need to build FOX if EITHER the sources for FOX have been updated or
# if this is the first time and it is not in place.
  if test "x$current_fox_md5" = "x$fox_md5"
  then
    echo FOX appears to be up-to-date.
    echo The header and libraries are in $fox_directory
  else
# In case any of the script files are not marked as executable I will
# force things. File transfer might have lost permissions.
    chmod +x $support_directory/*.sh
    echo "+++ about to recompile FOX"
    echo "    Please be aware that this can take a while"
    echo "    A log will be in $reduce_directory/log/fox.log"
    if test ! -d $reduce_directory/log
    then
      mkdir $reduce_directory/log
    fi
# Here I attempt to re-compile all of FOX. If that process returns with
# a clean return-code I will record checksums that identify the
# state of both the FOX source directory and the one into which a
# built version has been installed. But if the build fails I will not
# update those recorded checksums, and so I expect that future uses of
# this script will re-do the compilation. Eventually with luck it will
# succeed!  After I have updated the FOX directory I will OF COURSE
# have changed dates and md5 checksums on all the files, and so I
# will need to re-compute signatures on the updated files so that what
# I store for next time reflects the state after the compilation.
    /bin/sh $support_directory/build-all.sh \
        $with_xp64 $with_cygwin $with_m32 $with_m64 $enable_debug \
        > $reduce_directory/log/fox.log 2>&1 &&
    echo "#! /bin/sh" > $build_directory/signature.sh &&
    current_fox_signature=`ls -l $fox_files | md5sum | sed -e 's/ .*$//'` &&
    current_fox_md5=`md5sum $fox_files | md5sum | sed -e 's/ .*$//'` &&
    echo updated fox_signature = $current_fox_signature" &&
    echo updated fox_md5 = $current_fox_md5" &&
    ls -l $fox_files > updated_fox_files.log &&
    echo "fox_signature=\"$current_fox_signature\"" >> $build_directory/signature.sh &&
    echo "fox_md5=\"$current_fox_md5\"" >> $build_directory/signature.sh &&
    echo "export fox_signature fox_md5" >> $build_directory/signature.sh &&
    chmod +x $build_directory/signature.sh
  fi
#
#
# End of section that ensures that an up-to-date FOX build in in place
#
fi

exit 1
# stop for now


# FINISHED!!!

echo r38 built in $build_directory/$machine

exit 0

# end of build-all.sh
