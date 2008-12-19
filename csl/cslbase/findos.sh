#!/bin/sh

# "findos.sh"
#
# Attempt to find the operating system varient in play. This is mainly
# for use on Linux where the tests that autoconf does do not detect
# which distribution I am using.
#
# This code is not properly general. It mostly looks at the file
# /etc/issue (which an administrator could have altered!) and pattern
# matches against the cases I happen to have tested.

# This file is also a historical relic and while it is referenced in the
# current configuration and build scripts it is not used in ways that are
# relevant to the world of today. So it is kept here as a relic.
#
# A better version implementing the same idea is elsewhere in this source
# tree.

os="unknown"

case `uname -a` in
*CYGWIN*)
  os="windows"
# If a command "cl" exists and seems to be a Microsoft 64-bit
# compiler then I am building for 64-bit windows.
  if which cl 1>/dev/null 2>/dev/null
  then  
    w=`cl 2>&1`
    case $w in
    *Microsoft*Compiler*AMD64*)
      os="windows64"
      ;;
    esac
  fi
  echo $os
  exit
  ;;
FreeBSD*)
  echo "freebsd"
  exit
  ;;
esac

if test -f /etc/issue
then
  case `cat /etc/issue` in
  *Red*Hat*Linux*6.1*)
    os="redhat_6.1"
    ;;
  *Red*Hat*Linux*6.2*)
    os="redhat_6.2"
    ;;
  *Red*Hat*Linux*7.2*)
    os="redhat_7.2"
    ;;
  *Red*Hat*Linux*8.0*)
    os="redhat_8.0"
    ;;
  *Red*Hat*Linux*9.3*)
    os="redhat_9.3"
    ;;
  *Red*Hat*Linux*9*)
    os="redhat_9"
    ;;
  *SUSE*LINUX*10.0*)
    os="suse_10.0"
    ;;
  *SUSE*10.1*)
    os="suse_10.1"
    ;;
  *SUSE*10.2*)
    os="suse_10.2"
    ;;
  *SUSE*10.3*)
    os="suse_10.3"
    ;;
  *SUSE*LINUX*9.2*)
    os="suse_9.2"
    ;;
  *SUSE*LINUX*9.3*)
    os="suse_9.3"
    ;;
  *Fedora*Core*release*1*)
    os="fedora_1"
    ;;
  *Fedora*Core*release*2*)
    os="fedora_2"
    ;;
  *Fedora*Core*release*3*)
    os="fedora_3"
    ;;
  *Fedora*Core*release*4*)
    os="fedora_4"
    ;;
  *Fedora*Core*release*5*)
    os="fedora_5"
    ;;
  *Fedora*Core*release*6*)
    os="fedora_6"
    ;;
  *Fedora*release*7*)
    os="fedora_7"
    ;;
  *Fedora*release*8*)
    os="fedora_8"
    ;;
  *Debian*GNU*3.0*)
    os="debian_3.0"
    ;;
  *Debian*GNU*3.1*)
    os="debian_3.1"
    ;;
  *Debian*GNU*4.0*)
    os="debian_4.0"
    ;;
  *Ubuntu*6.*)
    os="ubuntu_6"
    ;;
  *Ubuntu*7.*)
    os="ubuntu_7"
    ;;
  *Ubuntu*8.*)
    os="ubuntu_8"
    ;;
  *Mandriva*)
# I am not distinguishing versions at all carefully here...
    os="mandrake_2007.0"
    ;;
  esac
else
  if test -f /System/Library/CoreServices/SystemVersion.plist
  then
    case `cat /System/Library/CoreServices/SystemVersion.plist` in
    *Mac*OS*X*ProductVersion*\<string\>10.2*)
      os="macos_10.2_jaguar"
      ;;
    *Mac*OS*X*ProductVersion*\<string\>10.3*)
      os="macos_10.3_panther"
      ;;
    *Mac*OS*X*ProductVersion*\<string\>10.4*)
      os="macos_10.4_tiger"
      ;;
    *Mac*OS*X*ProductVersion*\<string\>10.5*)
      os="macos_10.5_leopard"
      ;;
    esac
  else
    os="unknown"
  fi
fi

echo $os

exit
