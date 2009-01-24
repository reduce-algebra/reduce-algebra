#! /bin/sh

# "findos.sh"
#
# Attempt to find the operating system varient in play. This is mainly
# for use on Linux where the tests that autoconf does do not detect
# which distribution I am using.
#
# This code is not properly general. It mostly looks at the file
# /etc/issue (which an administrator could have altered!) and pattern
# matches against the cases I happen to have tested. It can thus need
# checking and extending as new cases become relevant.

os="unknown"

case `uname -a` in
*CYGWIN* | *Cygwin* | *cygwin* | *MINGW* | *MinGW* | *Mingw* | *mingw*)
  echo "windows"
  exit
  ;;
FreeBSD*)
  echo "freebsd"
  exit
  ;;
esac

if test -f /etc/issue
then
# I will detect a bunch of the bigger distributions. The
# first thing to do is to spot the main family, after that
# I will try to decode the release number.
#
# Usually the information I want is on the first line of /etc/issue, but at
# least on SUSE that is blank. On Ubuntu /etc/issue is several lines long
# and if I process all of them I get in a mess. Hence the following
# messing about with "head" etc. Actuall some of the pain is that on Ubuntu
# the file /etc/issue contains a string "\n" that sometimes gets mapped
# onto a newline.
  issue=`cat /etc/issue`
  hissue=`echo "$issue" | head -1`
  if test "x$hissue" = "x"
  then
    hissue="$issue"
  fi
  case $issue in
  *Red*Hat*)
    os=`echo $hissue | sed 's/^[^0-9]*\\([0-9][0-9]*\\.*[0-9]*\\).*$/rh\\1/'`
    ;;
  *SUSE*)
    os=`echo $hissue | sed 's/^[^0-9]*\\([0-9][0-9]*\\.*[0-9]*\\).*$/suse\\1/'`
    ;;
  *Fedora*)
    os=`echo $hissue | sed 's/^[^0-9]*\\([0-9][0-9]*\\.*[0-9]*\\).*$/fedora\\1/'`
    ;;
  *Scientific Linux*)
    os=`echo $hissue | sed 's/^[^0-9]*\\([0-9][0-9]*\\.*[0-9]*\\).*$/scientificlinux\\1/'`
    ;;
  *Debian*)
    os=`echo $hissue | sed 's/^[^0-9]*\\([0-9][0-9]*\\.*[0-9]*\\).*$/debian\\1/'`
    ;;
  *Ubuntu*)
    os=`echo $hissue | sed 's/^[^0-9]*\\([0-9][0-9]*\\.*[0-9]*\\).*$/ubuntu\\1/'`
    ;;
  *Mandriva*)
    os=`echo $hissue | sed 's/^[^0-9]*\\([0-9][0-9]*\\.*[0-9]*\\).*$/mandriva\\1/'`
    ;;
  *Mandrake*)
    os=`echo $hissue | sed 's/^[^0-9]*\\([0-9][0-9]*\\.*[0-9]*\\).*$/mandrake\\1/'`
    ;;
  esac
else
  if test -f /System/Library/CoreServices/SystemVersion.plist
  then
# For MacOS I will detect the version number and report a code-name for it.
    case `cat /System/Library/CoreServices/SystemVersion.plist` in
    *Mac*OS*X*ProductVersion*\<string\>10.2*)
      os="mac_10.2_jaguar"
      ;;
    *Mac*OS*X*ProductVersion*\<string\>10.3*)
      os="mac_10.3_panther"
      ;;
    *Mac*OS*X*ProductVersion*\<string\>10.4*)
      os="mac_10.4_tiger"
      ;;
    *Mac*OS*X*ProductVersion*\<string\>10.5*)
      os="mac_10.5_leopard"
      ;;
    esac
  else
    os="unknown"
  fi
fi

echo $os

exit
