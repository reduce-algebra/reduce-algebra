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
    alien \
    autoconf \
    devscripts \
    imagemagick \
    libedit-dev \
    libgtk2.0-dev \
    libncurses5-dev \
    libtool-bin \
    linux-generic \
    rpm \
    ssh \
    subversion \
    tex4ht \
    texlive-fonts-extra \
    texlive-fonts-recommended \
    texlive-latex-recommended \
    ubuntu-desktop \
    ubuntu-minimal \
    ubuntu-restricted-addons \
    ubuntu-standard \
    xorg-dev

# end of script
