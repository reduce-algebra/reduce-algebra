#! /usr/bin/env bash

# This is a a script to arrange that all the packages needed for
# Reduce are installed in non-GUI mode under termux on Android.
#

apt-get -y install build-essential binutils clang
apt-get -y install autoconf ccache git gnuplot imagemagick ncurses
apt-get -y install automake libtool libandroid-glob
apt-get -y install openssh time polyml bc
apt-get -y install subversion rsync
apt-get -y install bison flex which vim

exit

# Not supported directly on termux (?) so building documentation will
# not be possible.

apt-get -y install texinfo
apt-get -y install texlive-latex-base texlive-fonts-extra \
    texlive-fonts-recommended texlive-latex-recommended texlive-latex-extra \
    texlive-plain-generic
apt-get -y install tex4ht
apt-get -y install xorg-dev

exit 0
# end of script
