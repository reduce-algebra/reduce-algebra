#! /bin/sh

# autogen.sh

# This re-creates all the "configure" scripts and the like. It is needed
# because I am not using autoconf's own mechanisms for sub-directories
# and so doing an autoreconf once at the top-level is not enough.

# The flags to autoreconf indicate
#   -i    install fresh copies of all relevant script-files etc
#   -f    force all updates regardless of date-stamps
#   -v    display some information about what is being done.

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


for x in `find $here \( -name configure.ac -o -name configure.in \) -print`
do
#  echo $x
  x1=${x%/configure.ac}
  cd ${x1%/configure.in}
  echo "============================================================"
  echo Updating in `pwd`
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
  autoreconf -f -i
done

cd $here
scripts/resetall.sh

cd $save
exit 0

# end of autogen.sh
