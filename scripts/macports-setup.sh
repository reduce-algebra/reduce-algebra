#! /bin/bash

# macports-setup.sh                                    A C Norman June 2019

# $Id$

if test "$1" = "--help"
then
  printf "macports-setup.sh [--help] [--minimal] [[force]\n"
  printf "  help:    displays this message\n"
  printf "  minimal: only the bare minimum for local Reduce use\n"
  printf "  force:   overwrite any existing $HOME/.macports/macports.conf\n\n"
  exit 0
fi


# This script can be used on either a new Macintosh (once macports has
# been installed, and that in turn required Xcode tools icnluding its
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
# the Macintosh back as far as 10.11, and so where there are ports that
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

if grep macosx_deployment_target /opt/local/etc/macports/macports.conf 2>/dev/null
then
  printf "/opt/local/etc/macports/macports.conf already sets macosx_deployment_target\n"

else

  cp /opt/local/etc/macports/macports.conf /tmp/macports.conf
  printf "macosx_deployment_target 10.11\n" >> /tmp/macports.conf

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

port -N -s install ncurses gperf libiconv
port -N -s install gettext xz zlib libedit
port -N -s install bzip2 expat
port -N    install pkgconfig subversion
port -N    install autoconf autoconf-archive
port -N    install m4 perl5 autoconf213
port -N    install automake libtool
port -N    install bzip2 libffi python_select
port -N    install python2_select python27
port -N -s install xorg-libX11
port -N    install perl5.28
port -N -s install Xft2
port -N -s install xorg-libXext
port -N    install ccache gtime
port -N    install gmake bc timeout
port -N -s install xorg-libXrandr
port -N -s install xorg-libXcursor
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
# will be set up. As an exammple of ports that may not matter as much to
# others, "gmp" is the GNU multiprocesion library and I have some test
# code that benchmarks CSL arithmetic against it.
# "fontforge" is obviously relevant when considering details of fonts that
# may be used in a future Reduce GUI. "astyle" helps to keep C++ source
# code laid out consistently. All the texlive components are used when
# building the Reduce manual.

port -N install             \
  astyle                    \
  dvipng                    \
  findutils                 \
  fontconfig                \
  fontforge                 \
  gdb                       \
  git                       \
  gmp                       \
  gnuplot                   \
  gnutar                    \
  gzip                      \
  libffi                    \
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
