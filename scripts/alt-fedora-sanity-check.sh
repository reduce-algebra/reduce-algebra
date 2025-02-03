#! /usr/bin/env bash

# Install all packages needed for REDUCE development
# on a Fedora Workstation spin.

# When I started with a minimal install of Fedora 26 I installed
# vim, openssh and subversion manually - I could then fetch first
# fetchreduce.sh from another of my machines and then use that to
# invoke subversion to grab all of Reduce - including this script.
# Running this script seemed to get enough installed that I could
# configure and build Reduce. But PLEASE NOTE that Fedora packaging
# could change without me being aware, or changes to Reduce might
# add extra needs that I fail to include here, so if you get a build
# failure because of some missing header file or library first try
# to identify a package to install to satisfy the dependancy. Then report
# to the Reduce mailing lists so that those scripts can catch up.

### sudo dnf -y group install C\ Development\ Tools\ and\ Libraries

sudo dnf -y install \
   valgrind        astyle       automake \
   pkgconfig       gcc-c++      binutils \
   indent          make         elfutils \
   gdb             ltrace       flex     \
   gcc             autoconf     bison    \
   cscope          strace       byacc    \
   ccache          ctags        glibc-devel \
   libtool         ccache       autoconf-archive \
   oprofile

###sudo dnf -y group install Development\ Tools

sudo dnf -y install \
   patchutils           systemtap           diffstat \
   doxygen              git                 gettext  \
   subversion           highlight           patch   

sudo dnf -y install clang openssh vim gnuplot ImageMagick

sudo dnf -y install libXft-devel libXext-devel libatomic \
 ncurses-devel ncurses-compat-libs polyml redhat-lsb-core bc dc

# The following pull in a lot of subpackages. Maybe be more selective?

sudo dnf -y install texlive-collection-fontsextra \
 texlive-collection-fontsrecommended \
 texlive-collection-latex \
 texlive-collection-latexextra

exit 0
