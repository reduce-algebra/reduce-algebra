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


for x in `find $here -name configure.ac -print`
do
  echo "============================================================"
  case $x in
# I will not try reconfiguring in the wxWidgets directory. I will
# want the files there to be exactly as unpacked from the wxWidgets
# archive.
  */csl/wxWidgets*)
    echo Leaving $x untouched.
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
    autoreconf -f -i
  esac
done

# Now just to be double plus certain that all is well I will
# reset date-stamps.

echo Now reset all date-stamps...
echo Step 1 of 5: configure.ac and configure.in.
find . \( -name configure.ac -o -name configure.in \
          -o -name Makefile.am \) -print | xargs touch
sleep 1

echo Step 2 of 5: aclocal.m4:
find . -name aclocal.m4 -print | xargs touch
sleep 1

echo Step 3 of 5: config.h.in:
find . -name config.h.in -print | xargs touch
sleep 1

echo Step 4 of 5: Makefile.in:
find . -name Makefile.in -print | xargs touch
sleep 1

echo Step 5 of 5: configure:
find . -name configure -print | xargs touch
find . -name configure -print | xargs chmod +x

echo Date-stamps should now be in the proper sequence.

cd $here
scripts/resetall.sh

cd $save
exit 0

# end of autogen.sh
