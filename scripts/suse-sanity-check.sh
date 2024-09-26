#! /usr/bin/env bash

# Install all packages needed for REDUCE development
# on ioenSuSe.

# When I started with a minimal install of SuSe 15.5 I installed
# vim, openssh and subversion manually - I could then fetch first
# fetchreduce.sh from another of my machines and then use that to
# invoke subversion to grab all of Reduce - including this script.
# Running this script seemed to get enough installed that I could
# configure and build Reduce. But PLEASE NOTE that SuSe packaging
# could change without me being aware, or changes to Reduce might
# add extra needs that I fail to include here, so if you get a build
# failure because of some missing header file or library first try
# to identify a package to install to satisfy the dependancy. Then report
# to the Reduce mailing lists so tha thos script can catch up.

# The setup here is based on the one I created for use with Fedora.

# sudo dnf -y group install C\ Development\ Tools\ and\ Libraries

# The above command on Fedora installs
#   valgrind        astyle       automake
#   pkgconfig       gcc-c++      binutils
#   indent          make         elfutils
#   gdb             ltrace       flex    
#   gcc             autoconf     bison   
#   cscope          strace       byacc   
#   oprofile        ccache       ctags   
#   glibc-devel     libtool              

sudo zypper -n install \
    valgrind        astyle       automake \
    pkgconfig       gcc-c++      binutils \
    indent          make         elfutils \
    gdb             ltrace       flex     \
    gcc             autoconf     bison    \
    cscope          strace       byacc    \
    oprofile        ccache       ctags    \
    glibc-devel     libtool              

# Now install 
#   patchutils           systemtap           diffstat
#   doxygen              git                 gettext 
#   subversion           highlight           patch   

sudo ztpper -n install \
    patchutils           systemtap           diffstat \
    doxygen              git                 gettext-tools  \
    subversion           highlight           patch   

sudo zypper -n install openssh
sudo zypper -n install vim

sudo zypper -n install gnuplot
sudo zypper -n install ImageMagick

sudo zypper -n install libXft-devel
sudo zypper -n install libXext-devel

sudo zypper -n install ncurses-devel
#sudo zypper -n install ncurses-compat-libs

sudo zypper -n install polyml

#sudo zypper -n install redhat-lsb-core

sudo zypper -n install bc
#sudo zypper -n install dc

# The following pull in a lot of subpackages. Maybe we should be more selective.

sudo zypper -n install texlive-collection-fontsextra
sudo zypper -n install texlive-collection-fontsrecommended
sudo zypper -n install texlive-collection-latex
sudo zypper -n install texlive-collection-latexextra

sudo zypper -n install libatomic

exit 0
