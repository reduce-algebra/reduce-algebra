#! /usr/bin/env bash

# This is a a script to arrange that all the packages needed for
# Reduce are installed on an Debian-derived Linux.
#
# It has mostly be developed and tested on Ubuntu, and there are (at least)
# three reasons it may not be fully satisfactory on other releases of
# Linux:
# (1) Package names and exact contents may vary between distributions, and
#     perhaps between releases of the same distribution.
# (2) I rely on the apt-get dependancy mechanism to expand the list of
#     packages that I list explicitly here. The dependency information may
#     also not be universal or long-term stable.
# (3) I include some obviously Ubuntu-specific packages here, and I do
#     not document just what they are needed for or what to replace them
#     with elsewhere!
# Despite the above limitations I believe that this will provide a very good
# start on most "apt-get" systems.
#
# I install some things that are not needed at all when merely building a
# simple version of Reduce for local use, but which are needed or useful
# while building a distributable snapshot (ie one packages as a .deb or
# .rpm file).

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`
here=`dirname "$here"`

sudo apt-get -y install alien astyle autoconf ccache devscripts \
 git gnuplot imagemagick libedit-dev libffi-dev libgtk2.0-dev libncurses5-dev
# I believe I have seen some systems where I need "libtool" and some
# where it has to be "libtool-bin". By making the install requests each
# individual when one of the following two fails it should not wreck
# the whole attempt to get stuff installed! Ditto libltdl-dev.
sudo apt-get -y install libtool
sudo apt-get -y install libtool-bin
sudo apt-get -y install libltdl-dev
# Sort of similarly ssh may be either ssh or openssh...
sudo apt-get -y install openssh
sudo apt-get -y install ssh
sudo apt-get -y install linux-generic \
 polyml rpm ssh subversion tex4ht texinfo texlive-latex-base \
 texlive-fonts-extra texlive-fonts-recommended texlive-latex-recommended \
 texlive-latex-extra xorg-dev devscripts fakeroot alien rsync
# These last few will not be useful on non-Ubuntu platforms I suspect!
sudo apt-get -y install ubuntu-desktop ubuntu-minimal \
 ubuntu-restricted-addons ubuntu-standard 

# CSL now depends on C++-11, and versions of g++ prior to 4.9 (at least)
# have enough support to seen plausible but enough missing deatures to cause
# me pain. So I intend to take a view that gcc 5.X shhould be seen as the
# earliest version to be used without worrying too much. For Ubuntu LTS
# releases 12.04 and 14.04 the initially shipped gcc is earlier than that, but
# the following script can be used to fetch a newer toolchain and make it the
# default.

case `gcc -v 2>&1` in
*gcc\ version\ 4*)
  sudo apt-get -y install python-software-properties
  sudo add-apt-repository ppa:ubuntu-toolchain-r/test
  sudo apt-get update
  sudo apt-get -y install gcc-5 g++-5
  sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-5 \
       60 --slave /usr/bin/g++ g++ /usr/bin/g++-5
  ;;
*)
  printf "gcc is already probably recent enough\n"
  ;;
esac

# In some cases "make", "autoconf", "automake" "libtool" or "rsync" might be
# too old a version. So if I have a command line option "necessary" I will
# install better versions

case $* in
*necessary*)
  tar xvfj $here/csl/support-packages/necessary-updates.tar.bz2
  pushd necessary-updates
  ./build-them.sh
  popd
  ;;
*)
  ;;
esac

exit 0
# end of script
