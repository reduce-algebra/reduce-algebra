#! /bin/sh

# This is used to re-run autoconf, automake etc and then restart
# a call to "configure". It had been used in an attempt to arrange that
# when one went "configure;make" the make step would not instantly
# invoke automake etc and then run the configure step all over again. But
# the test I had to do that were too bash-specific so I have backed off
# from that. The result will sometimes be configures that take a lot
# longer than is really necessary!

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

saved=`pwd`
cd $here

if autoconf -o /dev/null >/dev/null 2>&1
then
# If looks as if we have autoconf installed and it is at least version
# 2.61, which is what I seem to need at the moment.
# The configure.ac file here arranges to check the automake
# version too.
  if $here/../autogen.sh
  then :
  else
    echo "The autoconf/automake process seems to have failed"
    echo "Please check you have up to date versions of all those installed"
    exit 1
  fi
else
# Here I do NOT have an up to date version of autoconf available. So as
# a fall-back and with some trepidation I will merely re-set date-stamps
# on the files that are involved.
  echo "About to touch aclocal.m4"
  find $here/.. -name aclocal.m4 -print | xargs touch
  sleep 1
  echo "About to touch Makefile.in, config.h.in and configure"
  find $here/.. \( -name Makefile.in -o -name config.h.in -o -name configure \) -print | xargs touch
  echo "datestamps should now be in the right order"
  echo " "
fi

cd $saved

exec $here/../configure $*
