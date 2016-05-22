#! /bin/sh

# "pslver.sh"
#
# Attempt to find which (known) version of PSL should be used on the
# current machine.
#

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`

host=`"$here/../config.guess"`

#
# The decoding here is very probably inadequate, however I hope that
# even as it is it will cope with some of the most important
# cases. The list of PSL binaries I know of to consider is
#   alpha        AMD64        AMD64_ext    eeepc
#   hpux         linux        linux64
#   linux_a.out  macg4        macg5        macintel
#   macintel64   sgi          sgi64        solaris
#   solaris64    solarisx86   sunox        win32
#   mingw-w64
#
# I do not understand the difference between some of these, but I
# hope that use of the host information as here plus inspection
# of /etc/issue (as in findos.sh) and as an utter fall-back compilation
# and execution of some small program will resolve matters.

case $host in
*WOW*)
  echo winx64
  exit 0
  ;;
*CYGWIN* | *Cygwin* | *cygwin* | *MINGW* | *MinGW* | *Mingw* | *mingw*)
  case `uname` in
  *CYGWIN*WOW*)
    echo "mingw-w64"
    ;;
  *)
    if test "`uname -m`" = "x86_64"
    then
      echo "mingw-w64"
    else
      echo "win32"
    fi
    ;;
  esac
  exit 0
  ;;
*eeepc*)
  echo "eeepc"
  ;;
*hpux*)
  echo "hpux"
  ;;
*x86_64*linux*)
  echo "AMD64_ext"
#  echo "AMD64"
  ;;
*arm*)
  echo "arm"
  ;;
*linux*)
# linux32 or linux_a.out
  gcc -x c - -o /tmp/pslver <<EOF
#include <stdio.h>
// At present this always says linux and never linux_a.out!!!!
int main()
{  printf(1 ? "linux\n" : "linux_a.out\n");
   return 0;
}
EOF
  /tmp/pslver
  rm -f /tmp/pslver

  ;;
*solaris*)
# or solaris64?
# or solarisx86
  echo "solaris"
  ;;
*sunos*)
  echo "sunos"
  ;;
*powerpc*darwin*)
# How can I distingush macg4 from macg5?
  echo "macg4"
  ;;
  *darwin*)
  gcc -x c - -o /tmp/pslver <<EOF
#include <stdio.h>
int main()
{  printf(sizeof(void *)==8 ? "macintel64\n" : "macintel\n");
   return 0;
}
EOF
  /tmp/pslver
  rm -f /tmp/pslver
  ;;
# *i386*darwin* | *i686*darwin*)
#   echo "macintel"
#   ;;
# *x86_64*darwin*)
#   echo "macintel64"
#   ;;
*sgi*)
# I have a sample here of the sort of thing I might do to
# discriminate between variants... 
  gcc -x c - -o /tmp/pslver <<EOF
#include <stdio.h>
int main()
{  printf(sizeof(void *)==8 ? "sgi64\n" : "sgi\n");
   return 0;
}
EOF
  /tmp/pslver
  rm -f /tmp/pslver
  ;;
*alpha*)
  echo "alpha"
  ;;
x86_64*freebsd*|amd64*freebsd*)
  echo "freeBSD64"
  ;;
i386*freebsd*)
  echo "freeBSD"
  ;;
*)
  echo "unknown"
  ;;
esac

exit
