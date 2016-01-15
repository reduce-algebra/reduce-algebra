#! /bin/sh

# autogen.sh

# This re-creates all the "configure" scripts and the like. It is needed
# because I am not using autoconf's own mechanisms for sub-directories
# and so doing an autoreconf once at the top-level is not enough.

#
# Usage:
#     autogen.sh [-f | --force]
#

f=""
if test "x$1" = "x-f" || test "x$1" = "x--force"
then
  printf "Will force full re-make of all autoconf-related files\n"
  f=" -f"
fi

# I want this script to be one I can launch from anywhere.

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`cd \`dirname "$here"\` ; pwd -P`

save=`pwd`
cd $here

if ! which autoreconf > /dev/null
then
  printf "You need to have autoconf and automake installed\n"
  printf "I seem not to be able to find the autoreconf command\n"
  printf "Stopping...\n"
  exit 1
fi

# Here I list all the directories that might be relevant. Note that in
# some circumstances some may not be present!

# There are some directories that I have chosen not to process here:
#  ./foxtests
# taking a view that people who wish to build those are in a minority
# and so can sort things out more or less for themselves.

L=". \
  ./cslbase \
  ./fox"

# On any particular machine I will regenerate the autoconf stuff from
# outside packages just once. The packages that I do some of my own
# maintenence on get reconfigured every time.

if ! test -f ./cslbase/gc-7/reconf.stamp
then
  L="$L ./cslbase/gc-7"
  touch ./cslbase/gc-7/reconf.stamp
fi

if ! test -f ./cslbase/crlibm/reconf.stamp
then
  L="$L ./cslbase/crlibm"
  touch ./cslbase/crlibm/reconf.stamp
fi

for d in $L
do
  printf "\nautoreconf in directory '%s'\n" $d
  if test -d $d
  then
    cd $d
    printf "autoreconf -i -v$f\n"
    autoreconf -i -v$f
    cd $here
  fi
done
   
cd $save
exit 0

# end of autogen.sh
