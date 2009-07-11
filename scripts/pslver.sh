#! /bin/sh

# "pslver.sh"
#
# Attempt to find which (known) version of PSL should be used on the
# current machine.
#

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

host=`$here/../config.guess`

#
# The decoding here is very probably inadequate, however I hope that
# even as it is it will cope with some of the most important
# cases. The list of PSL binaries I know of to consider is
#   alpha        amd64        amd64a       eeepc
#   hpux         linux        linux64
#   linux_a.out  macg4        macg5        macintel
#   macintel64   sgi          sgi64        solaris
#   solaris64    solarisx86   sunox        win32
#
# I do not understand the difference between some of these, but I
# hope that use of the host information as here plus inspection
# of /etc/issue (as in findos.sh) and as an utter fall-back compilation
# and execution of some small program will resolve matters.

case $host in
*CYGWIN* | *Cygwin* | *cygwin* | *MINGW* | *MinGW* | *Mingw* | *mingw*)
  echo "win32"
  exit 0
  ;;
*eeepc*)
  echo "eeepc"
  ;;
*hpux*)
  echo "hpux"
  ;;
*x86_64*linux*)
  echo "amd64"
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
*i386*darwin* | *i686*darwin*)
  echo "macintel"
  ;;
*x86_64*darwin*)
  echo "macintel64"
  ;;
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
*)
  echo "unknown"
  ;;
esac

exit
