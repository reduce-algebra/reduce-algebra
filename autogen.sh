#! /bin/sh

# autogen.sh

# This re-creates all the "configure" scripts and the like. It is needed
# because I am not using autoconf's own mechanisms for sub-directories
# and so doing an autoreconf once at the top-level is not enough.

#
# Usage:
#     autogen.sh [-f | --force]
#


# The following seem to be the dependencies that can trigger a need for
# autoconf, aclocal, autoheader, automake, libtoolize (and any others?)
# to be us3ed. I use them all via autoreconf. I believe that if I have
# at least automake 1.13 this understands even about libtool...
#
#	aclocal.m4:	configure.ac
#		aclocal
#	config.h.in:	configure.ac aclocal.m4
#		autoheader
#	Makefile.in:	configure.ac Makefile.am
#	# This command also generates COPYING, INSTALL, install-sh, missing
#	# mkinstalldirs, stamp-h.in, config.guess, config.sub, ltmain.sh and
#	# ltconfig as needed.
#		automake
#	configure:	configure.ac aclocal.m4
#

f=""
if test "x$1" = "x-f" || test "x$1" = "x--force"
then
  printf "Will force full re-make of all autoconf-related files\n"
  f=" -f"
fi

# Well I used to make "force" optional, but it now appears to me that the
# only difference it makes is (re-)installation of support scripts and it
# has at most minor cost implications, so I will do it always...

f=" -f"


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
#  ./csl/foxtests \
#  ./generic/libreduce/src \
#  ./generic/redfront/libedit-20140620-3.1 \
#  ./generic/redfront/src \
# taking a view that peopel who wish to build those already have to take
# special steps...

L=". \
  ./csl \
  ./csl/cslbase \
  ./csl/fox \
  ./psl \
  ./scripts"

# On any particular machine I will regenerate the autoconf stuff from
# outside packages just once. The packages that I do some of my own
# maintenence on get reconfigured every time.
# Having seen some pain about all this I am backing off efficiency in the
# direction of caution!

#if ! test -f ./csl/cslbase/gc-7/reconf.stamp
#then
  L="$L ./csl/cslbase/gc-7"
#  touch ./csl/cslbase/gc-7/reconf.stamp
#fi

#if ! test -f ./csl/cslbase/crlibm/reconf.stamp
#then
  L="$L ./csl/cslbase/crlibm"
#  touch ./csl/cslbase/crlibm/reconf.stamp
#fi

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
   
scripts/resetall.sh

cd $save
exit 0

# end of autogen.sh
