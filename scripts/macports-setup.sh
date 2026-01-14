#! /bin/bash

# macports-setup.sh                           A C Norman June 2019-Nov 2021

# $Id$


help="no"
minimal="no"
check="no"
univ="no"
extra=""

for p in $*
do
  case $p in
  --help)
    help="yes"   
    ;;
  --minimal)
    minimal="yes"
    ;;
  --check)
    check="yes"
    ;;
  --univ)
    univ="yes"
    ;;
  --extra=*)
    extra="${p%extra=}"    
     ;;
  *)
    printf "+++ Unrecognised option $p\n"
    exit 1
    ;;
  esac
done

# As of early 2026 and running under Big Sur (which is of course no
# longer supported!) on a mid 2014 macbook I find that python314 fails
# to build, and unless I take action many other ports depends on it and
# hence fail. Falling back to python313 for ports that are willing to
# do so helps rather a lot! This might need reviewing some day! But
# it is probably valid for the remaining time that universal builds will
# make sense!

extra="$extra +python313"

if test "$help" = "yes"
then
  printf "sudo macports-setup.sh [--help] [--minimal]\n"
  printf "                       [--check] [--univ]]\n"
  printf "                       [--extra=XXX]\n"
  printf "  help:      displays this message\n"
  printf "  minimal:   only (about) the minimum for local Reduce use\n"
  printf "  check:     report what is NOT universal\n"
  printf "  univ:      try to upgrade eveything to universal\n"
  printf "  extra=XXX  pass XXX to all uses of \"port install\"\n"
  exit 0
fi

# This script can be used on a Macintosh (once macports has
# been installed, and that in turn required Xcode tools including its
# command-line option). It installs a collection of "ports" sufficient for
# building, testing and distributing Reduce.
#
# When a new release of the main Macintosh operating system is installed
# or an updated version of Xcode tools gets released it will be proper
# to refresh all ports. For a new operating system in general a fresh
# and updated version of macports itself may be required. But in both cases
# doing "sudo port uninstall all" will discard all current material
# and then this script can be used to reinstate it.

# Based on an expectation that I will be running on a Big Sur or later
# I will try to install universal (ie combined x86_64 and arm64) versions
# of everything. As of January 2022 some ports fail to install in universal
# form and you are liable to see messages to that effect, but on Bug Sur
# using an Intel CPU and on an m1-based macbook with Monterey I find ENOUGH
# universal ports get installed that it is possible to build Reduce with
# "--enable-universal" specified when you go "./configure". 
#
# The ports that did not install in full universal form for me on a
# February 2022 attempt running on an Intel Mac were:
#   at-spi2-atk at-spi2-core atk dav1d findutils fontforge
#   gdk-pixbuf2 ghostscript gmake graphite2 grep groff gtime
#   gtk3 harfbuzz harfbuzz-icu libde265 libepoxy m4 openldap
#   pango subversion texlive-bin
# Note that those are mostly not libraries that I need to link in
# to create the Reduce executables - thay are tools used during a
# build and some libraries used by those tools.
#
# For instance ghostscript is used by Reduce for displaying graphs, so
# Intel and ARM installations will require different versions (or an
# universal binary built some other way). Most of the rest are utilities
# and the libraries that they depend on that are used locally while
# building Reduce (especially its documentation), debugging it or running
# tests: they do not provide components that go into distribution files. 


# Report that date at start and end of this just for interest.
date

if test "$check" != "yes"
then
# Ensure that the latest version of macports will be in use.
  port selfupdate
fi

# The ordering of the installations here is not arbitrary - I have made at
# least some attempt to set it up so that dependencies do not lead to
# ports being built from source (or not) against my intention. So for
# instance if I had listed ncurses lower down I could have found a binary
# install of it triggered by some package that depended on it, while
# if I moved xorg-libX11 up then various of its dependencies would end up
# compiled from source in an unnecessary way.

# If this computer can no create universal binaries I should not play with
# that at all.

base=`mktemp SXXXXXXX`
echo "int main() { return 0; }" > /tmp/$base.c
rm -f /tmp/$base
gcc -arch x86_64 -arch arm64 /tmp/$base.c -o /tmp/$base >/dev/null 2>/dev/null
if test -f /tmp/$base
then
  universal="yes"
else
  universal="no"
fi
rm -f /tmp/$base.c /tmp/$base

# For each port I first try installing in +universal mode than if that
# fails I try again in plain single-architecture mode. I use "port clean"
# frequently because without it incomplete installs in one mode can clash
# with subsequent attempts in another.

install ()
{
  printf "\n@@@ Install $1 @@@\n\n"
# For each port I am keen on I will first try installing in +universal
# mode and if that fails I will repeat the attempt in single architecture
# style. I use a suffix ":s" on the port name when I want to build from
# source and hence force in all the prerequisites for that. Hmm if one of
# the prerequisites for the installs fails to build as +universal then in
# the fallback the rest may be build plain. However at the end of this
# script I perform a sweep that will clean up after any such problems.
# Also I allow a suffix ":x" that should never be used alongside ":s" that
# indicated that the port just provides executable utilities rather than
# libraries, so there is no merit in trying to make it universal.
  case $1 in
  *:x)
    P=${1%:x}
    S=""
    xtag="yes"
    ;;
  *:s)
    P=${1%:s}
    S="-s"
    xtag="no"
    ;;
  *)
    P=$1
    S=""
    xtag="no"
    ;;
  esac
# When I clean things I will clean all the other ports that this one
# depends on (in a recursive sense, so that dependencies of dependencies
# are followed). This is because trying to install this may trigger attempts
# to build some or even all of those, and if any are in an untidy state
# that could disrupt the entire build.
  port -N clean --all $P rdepof:$P
  if test "$xtag" = "yes"
  then
    port -f -N install $P $extra
  elif test "$universal" = "no" || ! port -f -N $S install $P +universal $extra
  then
    if test "$universal" = "no"
    then
      printf "### Using single-architecture install of $P\n"
    else
      printf "### Fallback to simple install of $P\n"
      port -N clean --all $P rdepof:$P
    fi
    port -f -N $S install $P $extra
  fi
}

if test "$check" != "yes" && test "$univ" != "yes"
then
  for p in                      \
    ncurses:s                   \
    gperf:s                     \
    libiconv:s                  \
    gettext:s                   \
    xz:s                        \
    zlib:s                      \
    libedit:s                   \
    bzip2:s                     \
    expat:s                     \
    gsed:x                      \
    pkgconfig:x                 \
    subversion:x                \
    autoconf:x                  \
    autoconf-archive:x          \
    m4:x                        \
    perl5:x                     \
    autoconf213:x               \
    automake:x                  \
    libtool                     \
    bzip2:x                     \
    libffi                      \
    python_select:x             \
    python2_select:x            \
    python27:x                  \
    python39:x                  \
    xorg-libxcb:s               \
    xorg-libX11:s               \
    perl5.28:x                  \
    Xft2:s                      \
    xorg-libXext:s              \
    ccache:x                    \
    gtime:x                     \
    gmake:x                     \
    bc:x                        \
    timeout:x                   \
    xorg-libXrandr:s            \
    xorg-libXcursor:s           \
    brotli                      \
    brotli-static               \
    ccache:x                    \
    xorg-server                 \
    xorg

  do
    install $p
  done
fi

# Once again several of the ports that follow are really not essential
# for Reduce use, but by installing them I find that the full set of tools
# that I (ACN) have made use of in Reduce development and experiment
# will be set up. As an example of ports that may not matter as much to
# others, "gmp" is the GNU multiprecision library and I have some test
# code that benchmarks CSL arithmetic against it.
# "fontforge" is obviously relevant when considering details of fonts that
# may be used in a future Reduce GUI. "astyle" helps to keep C++ source
# code laid out consistently. All the texlive components are used when
# building the Reduce manual.

if test "$check" != "yes" && test "$univ" != "yes" && test "$minimal" != "yes"
then
  for p in                      \
    fontconfig:s                \
    libffi:s                    \
    gmp:s                       \
    astyle:x                    \
    dvipng:x                    \
    findutils:x                 \
    fontforge:x                 \
    gdb:x                       \
    git:x                       \
    gnuplot                     \
    gnutar:x                    \
    gzip:x                      \
    md5sha1sum:x                \
    netpbm:x                    \
    psutils:x                   \
    rsync:x                     \
    texinfo:x                   \
    texlive-fonts-extra:x       \
    texlive-formats-extra:x     \
    texlive-latex-extra:x       \
    texlive-plain-generic:x     \
    texlive-bin-extra:x         \
    texlive-fonts-recommended:x \
    wget:x
  do
    install $p
  done
fi

# Now I should have everything I want, and if I am lucky almost everything
# will be in univeral mode. But it may be that for various reasons some
# ports that could have been universal have ended up installed in a plain
# form, so I scan, identify those and try for +universal again. I report
# at the end on any that still fail. In January 2022 there are some but none
# that cause serious problems for me. Reviewed in January 2026. I now reverse
# the order because that gets a lot of X11 packages upgraded early in the
# process and that works well for me in cases that the full upgrade is
# interrupted part way through.

all=`port installed installed | \
     grep active | \
     tail -n +2 | \
     sed -e 's/@.*$//g' | \
     sort -r`
failures=""

# The above sets all to a list of all the ports that are at present active.
# I will then check each to see if a universal version is already installed,
# and if not whether one may be available.

for P in $all
do
  if port installed $P | grep "universal.*active" >/dev/null
  then
# If the current version is already universal I do not have to do more for
# this package.
    continue
  fi
  if port variants $P | grep "universal:" > /dev/null
  then
# Here the currently active port is not universal but the option +universal
# will be understood.
    case $P in
    clang* | llvm* | python* | texlive* | ImageMagick | ccache |\
    subversion | rsync)
# These things do not need th be universal - they are packages I will
# run on this machine but I will not move their binaries elsewhere.
# Furthermore building or rebuilding them can be seriously tedious.
      printf "$P does not need to be universal\n";
      continue
      ;;
    *)
      printf "$P is not universal yet but potentially could be\n"
      ;;
    esac
  else
    continue
  fi
  if test "$check" != "yes"
  then
    port -N clean --all $P rdepof:$P
    if ! port -f -N install $P +universal $extra
    then
# Collect a list of cases where the universal build fails.
      failures="$P $failures"
    fi
  fi
done

if test "$failures" != ""
then
  printf "\n\nFailed: $failures\n"
fi

date

exit 0

# end of script
