#!/bin/csh -f
# Script to load lispvar redfront. Do not move this script.
#
# $Id$
#
if ( -e /usr/bin/which) then
   set me=`/usr/bin/which $0`
   set mydir=`dirname $me`
   setenv reduce $mydir
else
   setenv reduce reducevar
endif
set UNAME=`uname`
set ARCH=`arch`
if (("$UNAME" == Linux) && ("$ARCH" == i686)) then
   setenv MACHINE linux
else if (("$UNAME" == Linux) && ("$ARCH" == x86_64)) then
   setenv MACHINE amd64
else if (("$UNAME" == SunOS) && ("$ARCH" == sun4)) then
   setenv MACHINE solaris
else if (("$UNAME" == Darwin) && ("$ARCH" == ppc)) then
   setenv MACHINE macg4
else if (("$UNAME" == Darwin) && ("$ARCH" == i386)) then
   setenv MACHINE macintel
else
   setenv MACHINE MACHINEvar
endif
setenv lisp lispvar
setenv gnuplot $reduce/wutil/$MACHINE
if (($MACHINE == macg4) || ($MACHINE == macintel)) then
   setenv DYLD_FALLBACK_LIBRARY_PATH ${reduce}/packages/redfront/${lisp}/${MACHINE}
endif
exec $reduce/packages/redfront/$lisp/$MACHINE/redfront $*
