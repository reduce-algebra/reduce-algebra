#! /bin/sh

# autogen.sh

# This re-creates all the "configure" scripts and the like. It is needed
# because I am not using autoconf's own mechanisms for sub-directories
# and so doing an autoreconf once at the top-level is not enough.

# I arrange that this script can be invoked from anywhere because it will
# possibly be called when the current directory is the BUILD directory
# not the SOURCE one. But this updates files in the SOURCE directory.

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

here=`echo $c | sed -e 's+/[^/]*$++'`

save=`pwd`
cd $here

echo "Updating autoconf scripts in $here"

rm -rf autom4te.cache

canconfigure="yes"

if autoconf --version </dev/null >/dev/null 2>&1
then :
else
  canconfigure="no"
  echo "autoconf not seem to be available"
fi

if automake --version </dev/null >/dev/null 2>&1
then :
else
  canconfigure="no"
  echo "automake not seem to be available"
fi

if autoheader --version </dev/null >/dev/null 2>&1
then :
else
  canconfigure="no"
  echo "autoheader not seem to be available"
fi

if test "$canconfigure" = "no"
then
  echo "I will merely reset some date-stamps"
# I only need to touch the files that the Makefile is going to have
# dependencies for.
  touch aclocal.m4
# The "sleep 1" is to ensure that there is a positive difference in the
# time stamps even if my computer does not record times to high resolution!
  sleep 1
  touch Makefile.in config.h.in configure
  sleep 1
  touch autogen.stamp
  cd $save
  exit 0
fi

echo "About to run aclocal --force"
if aclocal --force
then :
else
  echo "aclocal failed in $here"
  cd $save
  exit 1
fi

echo "About to run autoreconf -i -f -v"
if autoreconf -i -f -v
then :
else
  echo "autoreconf failed in $here"
  cd $save
  exit 1
fi

if autoheader
then :
else
  echo "autoheader failed in $here"
  cd $save
  exit 1
fi

# I maintain my own timestamp on when this procedure was performed.
touch autogen.stamp

cd $save

# end of autogen.sh
