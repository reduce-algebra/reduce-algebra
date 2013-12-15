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

echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
echo "Updating autoconf scripts in $here"
echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
echo

#
# I need a short essay to explain what is going on here. I really want to
# be doubleplus certain that when I run this script it installs versions of
# all autoconf and automake-related files everywhere. So to be extra careful
# I will remove old copies first, even if I might hope that "autoreconf -f -i"
# might overwrite existing copies with new ones.
# The when the tools search for files such as config.guess they can look
# in the current directory or its parent or grandparent. To ensure I get
# unambiguously simple-to-find versions everywhere I run autoreconf on the
# deepest nested directories first, so that it will install all files.
# This is perhaps redundant but it reduces (in my opinion) confusion when
# looking at the trees, even though it leads to the need for complexity and
# mess here.
#

rm -f compile config.guess config.sub depcomp install-sh missing
cd scripts
rm -f compile config.guess config.sub depcomp install-sh missing
cd ../csl
rm -f compile config.guess config.sub depcomp install-sh missing
cd cslbase
rm -f compile config.guess config.sub depcomp install-sh missing
cd crlibm
rm -f compile config.guess config.sub depcomp install-sh missing
cd ../../fox
rm -f compile config.guess config.sub depcomp install-sh missing
cd ../../psl
rm -f compile config.guess config.sub depcomp install-sh missing
cd support-packages/xport-2.05
rm -f compile config.guess config.sub depcomp install-sh missing
cd ../../..

cd scripts
echo " "
echo "updating in `pwd`"
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

cd ../csl/cslbase/crlibm
echo " "
echo "updating in `pwd`"
if autoreconf -i -f -v && autoheader --force
then :
else
  echo "autoreconf failed in $here/csl/cslbase/crlibm"
  cd $save
  exit 1
fi

cd ..
echo " "
echo "updating in `pwd`"
if autoreconf -i -f -v && autoheader --force
then :
else
  echo "autoreconf failed in $here/csl/cslbase"
  cd $save
  exit 1
fi

cd ../fox
echo " "
echo "updating in `pwd`"
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
  echo "updating in `pwd`"
  rm -f compile config.guess config.sub depcomp install-sh missing
  if autoreconf -i -f -v
  then :
  else
    echo "autoreconf failed in $here/csl/foxtests"
    cd $save
    exit 1
  fi
fi

cd ..
echo " "
echo "updating in `pwd`"
if ./autogen.sh
then :
else
  echo "reconfiguring failed in $here/csl"
  cd $save
  exit 1
fi

cd ../psl/support-packages/xport-2.05
echo " "
echo "updating in `pwd`"
if autoreconf -i -f -v
then :
else
  echo "autoreconf failed in $here/psl/support-packages/xport-2.05"
  cd $save
  exit 1
fi

cd ../..
echo " "
echo "updating in `pwd`"
if autoreconf -i -f -v
then :
else
  echo "autoreconf failed in $here/psl"
  cd $save
  exit 1
fi

cd ..

echo " "
echo "opdating in `pwd`"
if autoreconf -i -f -v
then :
else
  echo "autoreconf failed in $here"
  cd $save
  exit 1
fi

scripts/resetall.sh

cd $save
exit 0

# end of autogen.sh
