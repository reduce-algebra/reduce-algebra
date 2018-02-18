#! /bin/bash

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


sudo apt-get -y install alien astyle autoconf ccache devscripts \
 git gnuplot imagemagick libedit-dev libffi-dev libgtk2.0-dev libncurses5-dev
# I believe I have seen some systems where I need "libtool" and some
# where it has to be "libtool-bin". By making the install requests each
# individual when one of the following two fails it should not wreck
# the whole attempt to get stuff installed! Ditto libltdl-dev.
sudo apt-get -y install libtool libtool-bin libltdl-dev linux-generic \
 polyml rpm ssh subversion tex4ht texinfo texlive-latex-base \
 texlive-fonts-extra texlive-fonts-recommended texlive-latex-recommended \
 texlive-latex-extra xorg-dev devscripts fakeroot alien rsync
# These last few will not be useful on non-Ubuntu platforms I suspect!
sudo apt-get -y install ubuntu-desktop ubuntu-minimal \
 ubuntu-restricted-addons ubuntu-standard 
exit 0
# end of script
