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

echo "Updating autoconf scripts in $here"

if autoreconf -i -f -v
then :
else
  echo "autoreconf failed in $here"
  cd $save
  exit 1
fi

cd scripts
echo " "
echo "updating in scripts"
if aclocal
then :
else
  echo "reconfiguring failed in $here/scripts"
  cd $save
  exit 1
fi
if autoconf
then :
else
  echo "reconfiguring failed in $here/scripts"
  cd $save
  exit 1
fi

cd ../csl
echo " "
echo "updating in csl"
if ./autogen.sh
then :
else
  echo "reconfiguring failed in $here/csl"
  cd $save
  exit 1
fi

cd cslbase
echo " "
echo "updating in csl/cslbase"
if autoreconf -i -f -v && autoheader --force
then :
else
  echo "autoreconf failed in $here/csl/cslbase"
  cd $save
  exit 1
fi

cd ../fox
echo " "
echo "updating in csl/fox"
if autoreconf -i -f -v
then :
else
  echo "autoreconf failed in $here/csl/fox"
  cd $save
  exit 1
fi

if test -d ../foxtests
then
  cd ../foxtests
  echo " "
  echo "updating in csl/foxtests"
  if autoreconf -i -f -v
  then :
  else
    echo "autoreconf failed in $here/csl/foxtests"
    cd $save
    exit 1
  fi
fi

cd ../../psl
echo " "
echo "updating in psl"
if autoreconf -i -f -v
then :
else
  echo "autoreconf failed in $here/psl"
  cd $save
  exit 1
fi

cd support-packages/xport-2.05
echo " "
echo "updating in psl/support-packages/xport-2.05"
if autoreconf -i -f -v
then :
else
  echo "autoreconf failed in $here/psl/support-packages/xport-2.05"
  cd $save
  exit 1
fi

cd ../../..

scripts/resetall.sh

cd $save
exit 0

# end of autogen.sh
