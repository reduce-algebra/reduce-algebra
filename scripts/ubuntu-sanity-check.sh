#! /bin/bash

# This is a (first attempt at) a script to arrange that all the
# packages needed for Reduce are installed on an Ubuntu Linux. Note
# that this installs ubuntu-minimal, ubuntu-regular and ubuntu-desktop
# so if you were otherwise minded to use a different spin on Ubuntu it
# may not be what you want. It is possible that I do not need the package
# ubuntu-restricted-addons.
#
# I will test this soon! Until it has been tested please view it as
# a starting point not a guaranteed solution. (ACN: April 2016)

sudo apt-get install \
    libtool-bin \
    ubuntu-restricted-addons \
    xorg-dev \
    texlive-fonts-extra \
    libgtk2.0-dev \
    devscripts \
    deborphan \
    libncurses5-dev \
    linux-generic \
    ubuntu-desktop \
    subversion \
    libedit-dev \
    ubuntu-minimal \
    ubuntu-standard

# end of script
