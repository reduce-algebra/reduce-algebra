#! /bin/bash

# I intend that this just installs aarch64 versions of all the packages,
# not "universal" ones.

# macports-aarch64.sh                          C Norman June 2019-June 2026

# $Id: macports-aarch64.sh 7260 2026-01-18 14:33:19Z arthurcnorman $

if test "$1" = "--help"
then
  printf "sudo macports-setup.sh [--help] [--minimal]\n"
  printf "  help:      displays this message\n"
  printf "  minimal:   only the bare minimum for local Reduce use\n"
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

# This version avoids all the cost and complication of setting up
# universal installs. In the future only aarch64 Macs are to be supported.
#

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

# If this computer can no create universal binaries I should not play with
# that at all.


# Packages that are just programs that I will run rather than libraried
# that I will link to do not need to be installed in universal mode...
# however a pain is that when they are seen as dependencies of something
# I do want in bi-architecture form an attempt is made to build them
# that way. Sometimes over and over again during the process here!
# At present I do not have a good way to avoid that. I could certainly
# arrange that an explicit request for them only asked for a plain version
# but that does not mend the issue where they get triggered as a
# dependency. Ugh.

install ()
{
  printf "\n@@@ Install $1 @@@\n\n"
  case $1 in
  *:s)
    P=${1%:s}
    S="-s"
    ;;
  *)
    P=$1
    S=""
    ;;
  esac
  port -N clean --all $P rdepof:$P
  port -f -N $S install $P
}

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
  gsed                        \
  pkgconfig                   \
  subversion                  \
  autoconf                    \
  autoconf-archive            \
  m4                          \
  perl5                       \
  autoconf213                 \
  automake                    \
  libtool                     \
  bzip2                       \
  libffi                      \
  python_select               \
  python2_select              \
  python27                    \
  python39                    \
  xorg-libxcb:s               \
  xorg-libX11:s               \
  perl5.28                    \
  Xft2:s                      \
  xorg-libXext:s              \
  ccache                      \
  gtime                       \
  gmake                       \
  bc                          \
  timeout                     \
  xorg-libXrandr:s            \
  xorg-libXcursor:s           \
  brotli                      \
  brotli-static               \
  ccache                      \
  xorg-server                 \
  xorg

do
  install $p
done

case "$*" in
*--minimal*)
  printf "You probably have enough installed for a minimal local\n"
  printf "build of Reduce. But if you want to build documentation and\n"
  printf "try all [sometimes experimental] options please install the\n"
  printf "rest of the ports here.\n"
  exit 0
  MINIMAL=yes
  ;;
*)
  MINIMAL="no"
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

if test "$MINIMAL" != "yes"
then
  for p in                    \
    fontconfig:s              \
    libffi:s                  \
    gmp:s                     \
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
  do
    install $p
  done
fi

date

exit 0

# end of script
