# /usr/bin/env bash

# This is at least an approximation to a script that will ensure that
# an installation of Scientific Linux has evough development tools and
# libraries installed to make the rebuilding of Reduce possible.

# It was created by taking the corresponding Fedora script and expanding
# the group installs and expanding each to install all the packages that
# Fedora would have, initially assuming that package names would be the
# same.

yum -y install valgrind
yum -y install automake
yum -y install pkgconfig
yum -y install gcc-c++
yum -y install binutils
yum -y install indent
yum -y install make
yum -y install elfutils
yum -y install gdb
yum -y install ltrace
yum -y install flex
yum -y install gcc
yum -y install autoconf
yum -y install bison
yum -y install cscope
yum -y install strace
yum -y install byacc
yum -y install oprofile
yum -y install ctags
yum -y install glibc-devel
yum -y install libtool
yum -y install patchutils
yum -y install systemtap
yum -y install diffstat
yum -y install doxygen
yum -y install git
yum -y install gettext
yum -y install subversion
yum -y install highlight
yum -y install patch

sudo yum -y install openssh
sudo yum -y install vim

sudo yum -y install gnuplot
sudo yum -y install ImageMagick

sudo yum -y install libXft-devel
sudo yum -y install libXext-devel

sudo yum -y install ncurses-devel

sudo yum -y install redhat-lsb-core

sudo yum -y install texlive-collection-fontsrecommended
sudo yum -y install texlive-collection-latex

sudo yum -y install tex4ht
sudo yum -y install dvipng
sudo yum -y install texlive

# These are things I installed under Fedora but are not directly available
# in the copy of Scientific Linux that I tried. They are not centrally
# essential for Reduce, but if you find yourself needing them you may need
# to find an .rpm file or build from source yourself.

#yum -y install astyle
#                        Used to re-layout C++ source code
#yum -y install ccache
#                        I do not know!
#sudo yum -y install ncurses-compat-libs
#                        I am not certain why this is wanted!
#sudo yum -y install polyml
#                        Use for the SML-TeX contributed package
#sudo yum -y install texlive-collection-fontsextra
#                        Possibly provided otherwise
#sudo yum -y install texlive-collection-latexextra
#                        Possibly provided otherwise


exit 0
