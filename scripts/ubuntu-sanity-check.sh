#! /usr/bin/env bash

# This is a a script to arrange that all the packages needed for
# Reduce are installed on an Debian-derived Linux.
#
# It has mostly be developed and tested on Ubuntu, and there are (at least)
# three reasons it may not be fully satisfactory on other releases of
# Linux:
# (1) Package names and exact contents may vary between distributions, and
#     perhaps between releases of the same distribution.
# (2) I rely on the apt dependancy mechanism to expand the list of
#     packages that I list explicitly here. The dependency information may
#     also not be universal or long-term stable.
# (3) I include some obviously Ubuntu-specific packages here, and I do
#     not document just what they are needed for or what to replace them
#     with elsewhere!
# Despite the above limitations I believe that this will provide a very good
# start on most "apt" systems.
#
# I install some things that are not needed at all when merely building a
# simple version of Reduce for local use, but which are needed or useful
# while building a distributable snapshot (ie one packages as a .deb or
# .rpm file).

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`
here=`dirname "$here"`

sudo apt -y install alien astyle autoconf ccache devscripts \
 git gnuplot imagemagick libedit-dev libffi-dev libgtk2.0-dev libncurses5-dev
# I believe I have seen some systems where I need "libtool" and some
# where it has to be "libtool-bin". By making the install requests each
# individual when one of the following two fails it should not wreck
# the whole attempt to get stuff installed! Ditto libltdl-dev.
sudo apt -y install libtool
sudo apt -y install libtool-bin
sudo apt -y install libltdl-dev
# Sort of similarly ssh may be either ssh or openssh... so some of these
# requests are liable to moan.
sudo apt -y install openssh
sudo apt -y install ssh
sudo apt -y install clang
sudo apt -y install time
sudo apt -y install dvipng
sudo apt -y install linux-generic
sudo apt -y install polyml
sudo apt -y install bc
sudo apt -y install dc
sudo apt -y install subversion
sudo apt -y install texinfo
sudo apt -y install texlive-latex-base texlive-fonts-extra \
    texlive-fonts-recommended texlive-latex-recommended texlive-latex-extra \
    texlive-plain-generic
sudo apt -y install tex4ht
sudo apt -y install xorg-dev
sudo apt -y install rpm
sudo apt -y install devscripts fakeroot alien
sudo apt -y install rsync

exit 0
# end of script
