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

# At an earlier stage I ran autoreconf on several directories even when they
# are not actually used by this simple test. To speed this up and leave it a
# more basic check I now concentrate on what I need immediately.

autoreconf -f -i -v
   
cd $save
exit 0

# end of autogen.sh
