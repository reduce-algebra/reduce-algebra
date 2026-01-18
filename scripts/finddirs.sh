# finddirs.sh


# Guessed will be a GNU-style host triple, osname a more human
# readable and often more detailed characterisation of the identity of
# the operating system. Eg for Linux it will distinguish between Debian,
# Ubuntu, Fedora and a number of other possibilities and attempt to give
# the release number. For the Macintosh it names the system (Panther up
# to Sequoia, except that these dats I only cover from High Sierra onwards).

getguess() {
  guessed=`$here/config.guess`
}

# findos()
#
# Attempt to find the operating system varient in play. This is mainly
# for use on Linux where the tests that autoconf does do not detect
# which distribution I am using.
#
# This code is not fully general: it is here to cope with many commonly
# encountered cases but will deserve extension as new releases of systems
# are issue or new platforms emerge.
# It mostly looks at the file /etc/issue (which an administrator could
# have altered so could be spoofed!) and pattern matches against the
# cases I happen to have tested. It can thus need checking and extending
# as new cases become relevant. If the utility lsb_release is available
# then information from that will be used, and it may be more reliable.

findos() {
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
    if test "x$version" != "xunknown"
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
        os=`echo $hissue | sed 's/^[^0-9]*\\([0-9][0-9]*\\.*[0-9]*\\).*$/rh\\1/'`
        ;;
      *SUSE*)
        os=`echo $hissue | sed 's/^[^0-9]*\\([0-9][0-9]*\\.*[0-9]*\\).*$/suse\\1/'`
        ;;
      *Fedora*)
        os=`echo $hissue | sed 's/^[^0-9]*\\([0-9][0-9]*\\.*[0-9]*\\).*$/fedora\\1/'`
        ;;
      *Scientific*Linux*)
        os=`echo $hissue | sed 's/^[^0-9]*\\([0-9][0-9]*\\.*[0-9]*\\).*$/scientificlinux\\1/'`
        ;;
      *Debian*)
        os=`echo $hissue | sed 's/^[^0-9]*\\([0-9][0-9]*\\.*[0-9]*\\).*$/debian\\1/'`
        ;;
      *Ubuntu*)
        os=`echo $hissue | sed 's/^[^0-9]*\\([0-9][0-9]*\\.*[0-9]*\\).*$/ubuntu\\1/'`
        ;;
      *Linux*Mint*)
        os=`echo $hissue | sed 's/^[^0-9]*\\([0-9][0-9]*\\.*[0-9]*\\).*$/mint\\1/'`
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
# Actually the succession of changes that Apple make here is starting to
# get tedious to track!
# I will leave in comments about a range of historical Macintosh releases,
# but not detect them.
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
        *ProductVersion*\<string\>10.15*)
          os="mac_10.15_catalina"
          ;;
        *ProductVersion*\<string\>11.*)
          os="mac_11_big_sur"
          ;;
        *ProductVersion*\<string\>12.*)
          os="mac_12_monterey"
          ;;
        *ProductVersion*\<string\>13.*)
          os="mac_13_ventura"
          ;;
        *ProductVersion*\<string\>14.*)
          os="mac_14_sonoma"
          ;;
        *ProductVersion*\<string\>15.*)
          os="mac_15_sequoia"
          ;;
        *)
          os="mac_unknown_version"
          ;;
        esac
      fi
    fi
  fi

# I want to ensure that there are no blanks, tabs or slashes in the name
  os=`echo $os | sed -e 's/[[:space:]/]//g'`
  osname="$os"
}

# gettarget() is given a specification somewhat in the style of
# arguments to configure, save that the first item will be one of
#   --psl, --csl, --bootstrapreduce, --jlisp or --jlispboot but subsequent
# ones should be "--with-XXX", "--enable-XXX", "--without-XXX",
# "--disable-XXX" or "--host=XXX".

gettarget() {
  packagefile="package.map"
  logdir=""
  case $1 in
  --psl)
    root="pslbuild/"
    ;;
  --csl | --bootstrapreduce)
    root="cslbuild/"
    ;;
# At present all support for jlisp is "pending" here...
  --jlisp | --jlispboot)
    root="jlisp/"
    ;;
  *)
    printf "Unknown target system \"$1\"\n"
    exit 1
    ;;
  esac
  shift

# Now find the directory within cslbuild or psbuild
# that will be used if no tags are to be stuck on the end. In
# a simple case that is just the output from config.guess. However
# on various systems it either normalises the name or adds extra
# information. In addition to returning the directory (by printing it)
# it sets $root, $dirbase and $tags to parts of the name.

  host="$guessed"
echo host=$guessed in finddirs.sh > /tmp/debug.log
  case $host in
# On a macintosh specifying --enable-x86_84, --enable-aarch64 or
# --enable-universal must map onto the host triple.
  *darwin*)
echo host=darwin, args=$* in finddirs.sh >> /tmp/debug.log
    case $* in
    *--enable-universal*)
      host=${host/x86_64/universal}
      host=${host/aarch64/universal}
      ;;
    *--enable-x86_64*)
      host=${host/universal/x86_64}
      host=${host/aarch64/x86_64}
      ;;
    *--enable-aarch64*)
      host=${host/x86_64/aarch64}
      host=${host/universal/aarch64}
      ;;
    esac
    ;;
# If I am on cygwin I will call myself x86_64-pc-windows or possible
# aarch64-pc-windows.
  *cygwin* | *CYGWIN* | *Cygwin*)
    host=${host/cygwin/windows}
    ;;
  esac
# The following line may help on FreeBSD where AC_CANONICAL_HOST
# and config.guess apppear to have differing ideas. And in that case
# please remember to use GNU make not the vanilla one.
  host=${host/amd64/x86_64}
  if test "x$osname" != "xunknown"
  then
    host=${host/-suse-linux/-unknown-linux}
    host=${host/-pc-linux/-unknown-linux}
    host=${host/linux-gnu/$osname}
    host=${host/apple/$osname}
  fi
  dirbase="$host"

  declare -a tags
  while test $# != 0
  do
    opt="$1"
    shift
    case $opt in
    --with-buildver=*)
      dirbase="${opt#--with-buildver=}"
      tags=""
      logdir="${dirbase}-times"
      opt=""
      ;;
    --with-logs=*)
      logdir="${opt#--with-logs=}"
      opt=""
      ;;
    --pkgmap=*)
      packagefile="${opt#--pkgmap=}.map"
      if ! test -f "$here/packages/$packagefile"
      then
        printf "package file '$packagefile' not found\n"
        exit 1
      fi
      opt="${opt#--pkgmap=}"
# If the file that lists packages has suffix "map" I will not include that
# suffix in the tag.
      opt="${opt%.map}"
      tags+=("-$opt")
      ;;
    --with-x86_64 | --with-aarch64 | --with-universal | --with-cygwin)
      opt=""
      ;;
    --with-*)
      opt="${opt#--with-}"
      tags+=("-$opt")
      ;;
    --without-*)
      opt=${opt#--without-}  
      tags+=("-no$opt")
      ;;
    --enable-*)
      opt=${opt#--enable-}  
      tags+=("-$opt")
      ;;
    --disable-*)
      opt=${opt#--disable-}  
      tags+=("-no$opt")
      ;;
    --host=*)
      opt=${opt#--host=}  
      tags+=("-$opt")
      ;;
# I should not get any other form of option passed here.
    esac
    case $opt in
    *=*)
      printf "unrecognised input near $opt\n"
      exit 1
      ;;
    esac
  done
  IFS=$'\n' sortedTags=($(sort <<<"${tags[*]}"))
  unset IFS
  tags=""
# I do not want any spaces between the concatenated tag-names.
  for tt in ${sortedTags[@]}
  do
    tags="$tags$tt"
  done
  if test "$logdir" = ""
  then
    logdir=${root/build\//}${tags}-times
  fi
  target="$root$dirbase$tags"
  optprintf "packagefile=$packagefile\n"
}

# end of finddirs.sh
