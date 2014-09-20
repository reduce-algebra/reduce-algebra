#! /bin/sh

# autogen.sh

# This re-creates all the "configure" scripts and the like. It is needed
# because I am not using autoconf's own mechanisms for sub-directories
# and so doing an autoreconf once at the top-level is not enough.

#
# Usage:
#     autogen.sh [path]
# Without any arguments this regenerates ALL the autoconf-related files.
# If it is given one then that can restrict the set of files that are
# rebuild, so eg
#     autogen.sh csl/cslbase
# will update the files in csl/cslbase (and in csl/cslbase/crlibm).
#

target=${1:-.}

a=$0
c=unknown
case $a in
/* )
  c=$a  
  ;;
*/* )
  case $a in
  ./* )
    a=`echo $a | sed -e 's+./++'`
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

here=`echo $c | sed -e 's+/[^/]*$++'`

save=`pwd`
cd $here

# If "autoreconf" is available then that will be what I use to
# cause aclocal, autoconf and automake to be run. I will assume that
# all the components that are needed will be available if the top
# level command is in place. If at some stage I find reports of cases where
# more elaborate tests are called for I may need to upgrade this!

if which autoreconf > /dev/null
then

  echo autoreconf command available for use.

  for x in `find $target \( -name configure.ac -o -name configure.in \) -print`
  do
    echo "============================================================"
    case $x in
# I will not try reconfiguring in the wxWidgets directory. I will
# want the files there to be exactly as unpacked from the wxWidgets
# archive, and will believe that use of tar to unpack the archive will
# have left files with datestamps correctly ordered.
    *wxWidgets* | *crlibm*)
      echo Leaving directory ${x%/configure.ac} untouched.
      ;;
    *)
      x1=`echo $x | sed -e 's+/configure.ac$++'`
      cd $x1
      echo Updating autoconf files in `pwd`:
      rm -rf aclocal.m4 autom4te.cache
# The files configure and Makefile.in might sometimes have been
# hand written... if so I had better not remove them!
      if test -f configure.ac || test -f configure.in
      then
        rm -f configure
      fi
      if test -f Makefile.am
      then
        rm -f Makefile.in
      fi
      if test -f config.h.in
      then
        rm -f config.h.in
      fi
      autoreconf -f -i
    esac
    cd $here
  done
fi

# Now just to be double plus certain that all is well I will
# reset date-stamps. If the command autoreconf is not available then
# this is the only thing that I will do, and in that case it is probably
# the best that I can do.

cd $here

echo Now reset all date-stamps...

echo Step 1 of 5: configure.ac, configure.in and Makefile.am:
files=`find $target \( -name configure.ac -o -name configure.in \
          -o -name Makefile.am \) -print`
if test "x$files" != "x"
then
  echo $files | xargs touch
fi
sleep 1

echo Step 2 of 5: aclocal.m4:
files=`find $target -name aclocal.m4 -print`
if test "x$files" != "x"
then
  echo $files | xargs touch
fi
sleep 1

echo Step 3 of 5: configure:
files=`find $target -name configure -print`
if test "x$files" != "x"
then
  echo $files | xargs touch
  echo $files | xargs chmod +x
fi
sleep 1

echo Step 4 of 5: config.h.in:
files=`find $target -name config.h.in -print`
if test "x$files" != "x"
then
  echo $files | xargs touch
fi
sleep 1

echo Step 5 of 5: Makefile.in:
files=`find $target -name Makefile.in -print`
if test "x$files" != "x"
then
  echo $files | xargs touch
fi

echo Date-stamps should now be in the proper sequence.

scripts/resetall.sh

cd $save
exit 0

# end of autogen.sh
