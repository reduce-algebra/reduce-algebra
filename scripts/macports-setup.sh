#! /bin/bash

# macports-setup.sh                                    A C Norman June 2019

# $Id$

if test "$1" = "--help"
then
  printf "macports-setup.sh [--help] [--minimal] [--universal] [[force]\n"
  printf "  help:      displays this message\n"
  printf "  minimal:   only the bare minimum for local Reduce use\n"
  printf "  universal: try to install x86_64+arm64 on Macintosh"
  printf "  force: overwrite any existing $HOME/.macports/macports.conf\n\n"
  exit 0
fi


# This script can be used on either a Macintosh (once macports has
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



# I want binaries of Reduce that I build to be able to support version of
# the Macintosh back as far as 10.13, and so where there are ports that
# lead to linkable libraries I will forcibly build from source with
# macosx_deployment_target set via macports.conf. To achieve that I set up
# a copy of that file in $HOME/.macports if necessary.
#
# For tools that are merely used locally while building Reduce I will let
# the port system fetch pre-built binaries when it has any, and dong so
# saves a major amount of time here.
# On a 2014 Macbook Pro a "minimal" installation takes around 25 minutes
# and a full one somewhat over an hour. It is OK to run this script without
# the "--minimal" flag at any stage after you have done a --minimal install,
# and it will check the alread-installed components but then just go on to
# fetch and install the rest.
#
# The --universal flag is for use on Big Sur and beyond to ttry to install
# ports so that that support both x86_64 and arm64, and hence Reduce can be
# built in that way. At the time of writing (February 2021) this still fails
# on an M1 Macintosh because a few ports will not build in universal mode.
# On an x86_64 Macintosh it fails much more thoroughly. There are strong
# indications that the Macports support team are aware of and are addressing
# these issues and the problem is just a natural one due to to the need for
# universal builds being fairly new. In many reszpects that extent to which
# things do work is amazing!

if grep macosx_deployment_target /opt/local/etc/macports/macports.conf 2>/dev/null
then
  printf "/opt/local/etc/macports/macports.conf already sets macosx_deployment_target\n"

else

  cp /opt/local/etc/macports/macports.conf /tmp/macports.conf
  printf "macosx_deployment_target 10.13\n" >> /tmp/macports.conf

  if ! test -f $HOME/.macports/macports.conf
  then
    mkdir $HOME/.macports
    mv /tmp/macports.conf $HOME/.macports
    printf "I have just created $HOME/.macports/macports.conf\n"
    printf "to set macosx_deployment_target for you\n"
  else

    if diff $HOME/.macports/macports.conf /tmp/macports.conf
    then
      printf "You already have $HOME/.macports/macports.conf set up\n"
    else

      printf "Your $HOME/.macports/macports.conf clashes with mine\n"
      printf "Please review it against /tmp/macports.conf\n"
      printf "This script will not continue unless you specify '--force'\n"
      printf "or delete your own macports.conf or bring it into step.\n"
      case "$*" in
      *--force*)
        ;;
      *)
        exit 1
        ;;
      esac
    fi
  fi
fi


# Report that date at start and end of this just for interest.
date

# Ensure that the latest version of macports will be in use.
port       selfupdate

# The ordering of the installations here is not arbitrary - I have made at
# least some attempt to set it up so that dependencies do not lead to
# ports being built from source (or not) against my intention. So for
# instance if I had listed ncurses lower down I could have found a binary
# install of it triggered by some package that depended on it, while
# if I moved xorg-libX11 up then various of its dependencies would end up
# compiled from source in an unnecessary way.

extraopt=""
case "$*" in
*--universal*)
  extraopt="+universal"
  ;;
esac

port -N -s install ncurses gperf libiconv $extraopt
port -N -s install gettext xz zlib libedit $extraopt
port -N -s install bzip2 expat $extraopt
port -N    install gsed $extraopt
port -N    install pkgconfig subversion $extraopt
port -N    install autoconf autoconf-archive $extraopt
port -N    install m4 $extraopt
port -N    install perl5 autoconf213 $extraopt
port -N    install automake libtool $extraopt
port -N    install bzip2 libffi python_select $extraopt
port -N    install python2_select python27 $extraopt
port -N    install python39 $extraopt
# As of February 2021 xorg-libxcb depends on libxml2 which in turn
# depends on icu, and an attempt to build on an x86_64 Mac stalls with
# a message
#   --->  Computing dependencies for libxml2
#   Error: Cannot install libxml2 for the archs 'arm64 x86_64' because
#   Error: its dependency icu cannot build for the required archs.
# this despite the fact that "port install icu +universal" succeeds. I
# expect this to be a transient issue and will remove this comment when
# I observe things behave better.
port -N -s install xorg-libxcb +python39 $extraopt
# xorg-libX11 is stalled by xorg-libxcb.
port -N -s install xorg-libX11 $extraopt
# perl5.28 depends on gdbm which in turn depends on readline, which
# can not (yet) be built in universal mode if you are on an x86_64 mac.
port -N    install perl5.28
# Xft2 also depends on libxml2.
port -N -s install Xft2 $extraopt
port -N -s install xorg-libXext $extraopt
port -N    install ccache gtime $extraopt
port -N    install gmake bc timeout $extraopt
port -N -s install xorg-libXrandr $extraopt
port -N -s install xorg-libXcursor $extraopt
port -N    install brotli $extraopt
date

case "$*" in
*--minimal*)
  printf "You probably have enough installed for a minimal local\n"
  printf "build of Reduce. But if you want to build documentation and\n"
  printf "try all [sometimes experimental] options please install the\n"
  printf "rest of the ports here. They are in general fetched in binary\n"
  printf "and it should not take TOO long...\n"
  exit 0
  ;;
*)
  ;;
esac

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

port -N -s install          \
  fontconfig                \
  libffi                    \
  gmp             $extraopt

port -N install             \
  astyle                    \
  dvipng                    \
  findutils                 \
  fontforge                 \
  gdb                       \
  git                       \
  gnuplot                   \
  gnutar                    \
  gzip                      \
  md5sha1sum                \
  netpbm                    \
  psutils                   \
  rsync                     \
  texinfo                   \
  texlive-fonts-extra       \
  texlive-formats-extra     \
  texlive-latex-extra       \
  texlive-plain-generic     \
  texlive-bin-extra         \
  texlive-fonts-recommended \
  wget

exit 0

# end of script
