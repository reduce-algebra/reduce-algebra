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
    a=${a#./}
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

here=${c%/*}

cd $here
echo "Updating autoconf scripts in $here"

if ! autoreconf -i -f -v
then
  echo "autoreconf failed in $here"
  exit 1
fi

cd csl
echo " "
echo "updating in csl"
if ! autoreconf -i -f -v && autoheader --force
then
  echo "autoreconf failed in $here/csl"
  exit 1
fi

cd cslbase
echo " "
echo "updating in csl/cslbase"
if ! autoreconf -i -f -v && autoheader --force
then
  echo "autoreconf failed in $here/csl/cslbase"
  exit 1
fi

cd ../fox
echo " "
echo "updating in csl/fox"
# The following two lines may be necessary on some systems?
rm -f ltmain.sh
touch ltmain.sh
if ! autoreconf -i -f -v
then
  echo "autoreconf failed in $here/csl/fox"
  exit 1
fi

if test -d ../foxtests
then
  cd ../foxtests
  echo " "
  echo "updating in csl/foxtests"
  if ! autoreconf -i -f -v
  then
    echo "autoreconf failed in $here/csl/foxtests"
    exit 1
  fi
fi

cd ../../psl
echo " "
echo "updating in psl"
if ! autoreconf -i -f -v
then
  echo "autoreconf failed in $here/psl"
  exit 1
fi

cd support-packages/xport-2.05
echo " "
echo "updating in psl/support-packages/xport-2.05"
if ! autoreconf -i -f -v
then
  echo "autoreconf failed in $here/psl/support-packages/xport-2.05"
  exit 1
fi

cd ../../..

scripts/resetall.sh

# end of autogen.sh
