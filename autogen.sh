#! /bin/sh

# autogen.sh

# This re-creates all the "configure" scripts and the like. It is needed
# when the machine being used does not have the same versions of autoconf
# and automake as the machine used by the developer.

#
# Usage:
#     autogen.sh [--sequential] [options as for the configure script]
#
# If no arguments are passed the script will rebuild everything. If
# --with-csl or --with-psl is specified only that section of the tree
# will be processed. In the CSL case "--with-wx", "--withoug-gui",
# and perhaps other sub-options will be checked to try to save reworking
# directories that would not be used.
#

sequential="no"
if test "x$1" = "x--sequential"
then
  sequential="yes"
  shift
fi

# I want this script to be one I can launch from anywhere.

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`cd \`dirname "$here"\` ; pwd -P`

save=`pwd`
cd $here

# On the Mac with macports the command needed here is glibtoolize rather than
# libtoolize.

if which libtoolize > /dev/null
then
  LIBTOOLIZE=libtoolize
else
  LIBTOOLIZE=glibtoolize
fi

if ! which autoconf > /dev/null || \
   ! which automake > /dev/null || \
   ! which $LIBTOOLIZE > /dev/null
then
  printf "You need to have autoconf, automake and $LIBTOOLIZE installed.\n"
  printf "I seem not to be able to find them.\n"
  printf "Note that on some Linux systems it is in a package called libtool-bin\n"
  printf "Stopping...\n"
  exit 1
fi

# Here I list all the directories that might be relevant. Note that in
# some circumstances some may not be present!

# There are some directories that I have chosen not to process here:
#  ./csl/foxtests
#  ./generic/libreduce/src
# taking a view that people who wish to build those already have to take
# special steps... and so they can run autoconf etc for themselves if it
# is needed. If I did so here it would slow things down for everybody in
# a way I would view as unhelpful. And this is already slow enough!

printf "autogen.sh arguments: $*\n"

if test $# -eq 0
then
  a="--with-psl --with-csl --with-fox"
else
  a="$*"
fi

# I will get rid of all config.cache files just to feel safe. If (say) the
# set of libraries on your computer have changed since last time they
# could contain misleading information.

find . -name config.cache | xargs rm -f

# I will re-process the top level first sequentially.
mkdir -p m4
$LIBTOOLIZE --force --copy
aclocal --force
autoreconf -f -i -v

# Here are the directories that I will always process...

L="./scripts ./libraries/crlibm ./libraries/libedit-20140620-3.1 \
   ./generic/newfront"

case $a in
*--without-psl* | *with-psl=no*)
  ;;
*--with-psl*)
  L="$L ./psl"
  ;;
*)
  ;;
esac

# I want "--with-wx" to imply "--without-fox". At present I do not
# feel the need for the converse because this script does not try to
# autoreconf wxWidgets anyway.
case $a in
*--with-wx=no* | "--without-wx*")
  ;;
*--with-wx*)
  a="$a --without-fox"
  ;;
*)
  ;;
esac

case $a in
*--without-csl* | *with-csl=no*)
  ;;
*--with-csl*)
  L="$L ./csl ./csl/cslbase ./libraries/SoftFloat-3a/source ./libraries/libffi"
  case $a in
  *--without-fox* | *with-fox=no* | \
  *--without-gui* | *with-gui=no*)
    ;;
  *)
    L="$L ./csl/fox"
    ;;
  esac
  ;;
*)
  ;;
esac

printf "About to process $L\n"

procids=""

for d in $L
do
  printf "\nautoreconf in directory '%s'\n" $d
  if test -d $d
  then
    cd $d
    printf "autoreconf -f -i -v\n"
# I will spawn all the calls to autoconf to run concurrently...
    mkdir -p m4
    if test "$sequential" = "yes"
    then
      ( aclocal --force; $LIBTOOLIZE --force --copy )
    else
      ( aclocal --force; $LIBTOOLIZE --force --copy ) &
      procids="$procids $!"
    fi
    cd $here
  fi
done

if test "$sequential" != "yes"
then
  wait $procids
fi

procids=""

for d in $L
do
  printf "\nautoreconf in directory '%s'\n" $d
  if test -d $d
  then
    cd $d
    printf "autoreconf -f -i -v\n"
# I will spawn all the calls to autoconf to run concurrently...
    if test "$sequential" = "yes"
    then
      autoreconf -f -i -v
    else
      autoreconf -f -i -v &
      procids="$procids $!"
    fi
    cd $here
  fi
done

# ...then wait until they have all finished.

if test "$sequential" != "yes"
then
  wait $procids
fi

scripts/resetall.sh

cd $save
printf "\nAll autoconf files now up to date\n"

exit 0

# end of autogen.sh
