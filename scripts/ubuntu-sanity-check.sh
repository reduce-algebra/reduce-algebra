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

sudo apt-get -y install alien
sudo apt-get -y install astyle
sudo apt-get -y install autoconf
sudo apt-get -y install ccache
sudo apt-get -y install devscripts
sudo apt-get -y install git
sudo apt-get -y install gnuplot
sudo apt-get -y install imagemagick
sudo apt-get -y install libedit-dev
sudo apt-get -y install libffi-dev
sudo apt-get -y install libgtk2.0-dev
sudo apt-get -y install libncurses5-dev
# I believe I have seen some systems where I need "libtool" and some
# where it has to be "libtool-bin". By making the install requests each
# individual when one of the following two fails it should not wreck
# the whole attempt to get stuff installed!
sudo apt-get -y install libtool
sudo apt-get -y install libtool-bin
sudo apt-get -y install linux-generic
sudo apt-get -y install polyml
sudo apt-get -y install rpm
sudo apt-get -y install ssh
sudo apt-get -y install subversion
sudo apt-get -y install tex4ht
sudo apt-get -y install texinfo
sudo apt-get -y install texlive-fonts-extra
sudo apt-get -y install texlive-fonts-recommended
sudo apt-get -y install texlive-latex-recommended
sudo apt-get -y install texlive-latex-extra
sudo apt-get -y install ubuntu-desktop
sudo apt-get -y install ubuntu-minimal
sudo apt-get -y install ubuntu-restricted-addons
sudo apt-get -y install ubuntu-standard
sudo apt-get -y install xorg-dev

exit 0
# end of script
