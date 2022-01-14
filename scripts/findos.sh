#! /bin/sh

# "findos.sh"
#
# Attempt to find the operating system varient in play. This is mainly
# for use on Linux where the tests that autoconf does do not detect
# which distribution I am using.
#
# If $1 is "short" then this will omit version information.
#
# This code is not properly general. It mostly looks at the file
# /etc/issue (which an administrator could have altered!) and pattern
# matches against the cases I happen to have tested. It can thus need
# checking and extending as new cases become relevant. If the utility
# lsb_release then information from that will be used, and it may be
# more reliable.

os="unknown"

case `uname -a` in
*CYGWIN* | *Cygwin* | *cygwin* | *MINGW* | *MinGW* | *Mingw* | *mingw*)
  echo "windows"
  exit
  ;;
FreeBSD*)
  version=`uname -r | sed -e 's/-.*$//'`
  echo "freebsd$version"
  exit
  ;;
esac

vendor=`if { lsb_release -d ; } 2>/dev/null; then : ; else echo unknown; fi`
version=`if { lsb_release -r ; } 2>/dev/null; then : ; else echo unknown; fi` 

# I think it is probable that if lsb_release is available  the result it
# provides will be more reliable than looking in /etc/issue

if test "x$vendor" != "xunknown"
then
# I normalise the names of distributions I know about...
  case $vendor in
  *Debian*)
    vendor="debian"
    ;;
  *Fedora*)
    vendor="fedora"
    ;;
  *SUSE*)
    vendor="suse"
    ;;
  *Ubuntu*)
    vendor="ubuntu"
    ;;
  *Linux*Mint*)
    vendor="mint"
    ;;
  *CentOS*)
    vendor="centos"
    ;;
  *Scientific*)
    vendor="scientificlinux"
    ;;
  *Gentoo*)
    vendor="gentoo"
    ;;
  *Raspbian*)
    vendor="raspbian"
    ;;
# Add more distributions here please!
  *)
    vendor="unknown"
    ;;
  esac
fi



if test "x$vendor" != "xunknown"
then
  if test "x$version" != "xunknown" && test "x$1" != "xshort"
  then
    version=`echo $version | sed '-e s/[^:]*:[ \t]*//'`
    os="$vendor$version"
  else
    os="$vendor"
  fi
else
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
      if test "x$1" = "xshort"
      then
        os="rh"
      else
        os=`echo $hissue | sed 's/^[^0-9]*\\([0-9][0-9]*\\.*[0-9]*\\).*$/rh\\1/'`
      fi
      ;;
    *SUSE*)
      if test "x$1" = "xshort"
      then
        os="suse"
      else
        os=`echo $hissue | sed 's/^[^0-9]*\\([0-9][0-9]*\\.*[0-9]*\\).*$/suse\\1/'`
      fi
      ;;
    *Fedora*)
      if test "x$1" = "xshort"
      then
        os="fedora"
      else
        os=`echo $hissue | sed 's/^[^0-9]*\\([0-9][0-9]*\\.*[0-9]*\\).*$/fedora\\1/'`
      fi
      ;;
    *Scientific*Linux*)
      if test "x$1" = "xshort"
      then
        os="scientificlinux"
      else
        os=`echo $hissue | sed 's/^[^0-9]*\\([0-9][0-9]*\\.*[0-9]*\\).*$/scientificlinux\\1/'`
      fi
      ;;
    *Debian*)
      if test "x$1" = "xshort"
      then
        os="debian"
      else
        os=`echo $hissue | sed 's/^[^0-9]*\\([0-9][0-9]*\\.*[0-9]*\\).*$/debian\\1/'`
      fi
      ;;
    *Ubuntu*)
      if test "x$1" = "xshort"
      then
        os="ubuntu"
      else
        os=`echo $hissue | sed 's/^[^0-9]*\\([0-9][0-9]*\\.*[0-9]*\\).*$/ubuntu\\1/'`
      fi
      ;;
    *Linux*Mint*)
      if test "x$1" = "xshort"
      then
        os="mint"
      else
        os=`echo $hissue | sed 's/^[^0-9]*\\([0-9][0-9]*\\.*[0-9]*\\).*$/mint\\1/'`
      fi
      ;;
    *Mandriva*)
      if test "x$1" = "xshort"
      then
        os="mandriva"
      else
        os=`echo $hissue | sed 's/^[^0-9]*\\([0-9][0-9]*\\.*[0-9]*\\).*$/mandriva\\1/'`
      fi
      ;;
    *Mandrake*)
      if test "x$1" = "xshort"
      then
        os="mandrake"
      else
        os=`echo $hissue | sed 's/^[^0-9]*\\([0-9][0-9]*\\.*[0-9]*\\).*$/mandrake\\1/'`
      fi
      ;;
    esac
  else
    if test -f /System/Library/CoreServices/SystemVersion.plist
    then
# For MacOS I will detect the version number and report a code-name for it.
# Actually the succession of changes that Apple make here is starting to
# get tedious to track!
      if test "x$1" = "xshort"
      then
        os="mac"
      else
        case `cat /System/Library/CoreServices/SystemVersion.plist` in
#       *Mac*OS*X*ProductVersion*\<string\>10.2*)
#         os="mac_10.2_jaguar"
#         ;;
#       *Mac*OS*X*ProductVersion*\<string\>10.3*)
#         os="mac_10.3_panther"
#         ;;
#       *Mac*OS*X*ProductVersion*\<string\>10.4*)
#         os="mac_10.4_tiger"
#         ;;
#       *Mac*OS*X*ProductVersion*\<string\>10.5*)
#         os="mac_10.5_leopard"
#         ;;
#       *Mac*OS*X*ProductVersion*\<string\>10.6*)
#         os="mac_10.6_snowleopard"
#         ;;
#       *Mac*OS*X*ProductVersion*\<string\>10.7*)
#         os="mac_10.7_lion"
#         ;;
#       *Mac*OS*X*ProductVersion*\<string\>10.8*)
#         os="mac_10.8_mountainlion"
#         ;;
#       *Mac*OS*X*ProductVersion*\<string\>10.9*)
#         os="mac_10.9_mavericks"
#         ;;
#       *Mac*OS*X*ProductVersion*\<string\>10.10*)
#         os="mac_10.10_yosemite"
#         ;;
#       *Mac*OS*X*ProductVersion*\<string\>10.11*)
#         os="mac_10.11_elcapitan"
#         ;;
#       *Mac*OS*X*ProductVersion*\<string\>10.12*)
#         os="mac_10.12_sierra"
#         ;;
        *Mac*OS*X*ProductVersion*\<string\>10.13*)
          os="mac_10.13_highsierra"
          ;;
        *Mac*OS*X*ProductVersion*\<string\>10.14*)
          os="mac_10.14_mojave"
          ;;
        *Mac*OS*X*ProductVersion*\<string\>10.15*)
          os="mac_10.15_catalina"
          ;;
        *Mac*OS*X*ProductVersion*\<string\>11.*)
          os="mac_11_big_sur"
          ;;
        *mac*OS*ProductVersion*\<string\>12.*)
          os="mac_12_monterey"
          ;;
        *)
          os="mac_unknown_version"
          ;;
        esac
      fi
    else
      os="unknown"
    fi
  fi
fi

# I want to ensure that there are no blanks, tabs or slashes in the name
os=`echo $os | sed -e 's/[ 	/]//g'`

echo $os

exit
