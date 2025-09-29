#! /usr/bin/env bash

# Install all packages needed for REDUCE development
# on a Fedora Workstation spin.

# I used to use some package groups here, but they are not quite stable as
# across Fedora releases so I am moving to a clumsy detailed list.


sudo dbf -y install valgrind
sudo dbf -y install astyle
sudo dbf -y install automake
sudo dbf -y install pkgconfig
sudo dbf -y install gcc-c++
sudo dbf -y install binutils
sudo dbf -y install indent
sudo dbf -y install make
sudo dbf -y install elfutils
sudo dbf -y install gdb
sudo dbf -y install ltrace
sudo dbf -y install flex
sudo dbf -y install gcc
sudo dbf -y install autoconf
sudo dbf -y install libtool
sudo dbf -y install bison
sudo dbf -y install cscope
sudo dbf -y install strace
sudo dbf -y install byacc
sudo dbf -y install oprofile
sudo dbf -y install ccache
sudo dbf -y install ctags
sudo dbf -y install glibc-devel
sudo dbf -y install libtool
sudo dbf -y install patchutils
sudo dbf -y install systemtap
sudo dbf -y install diffstat
sudo dbf -y install doxygen
sudo dbf -y install git
sudo dbf -y install gettext
sudo dbf -y install subversion
sudo dbf -y install highlight
sudo dbf -y install patch
sudo dnf -y install clang
sudo dnf -y install openssh
sudo dnf -y install vim
sudo dnf -y install cmake
sudo dnf -y install ccache
sudo dnf -y install gnuplot
sudo dnf -y install ImageMagick
sudo dnf -y install libXft-devel
sudo dnf -y install libXext-devel
sudo dnf -y install ncurses-devel
sudo dnf -y install ncurses-compat-libs
sudo dnf -y install polyml
sudo dnf -y install redhat-lsb-core
sudo dnf -y install bc
sudo dnf -y install dc
sudo dnf -y install texlive-collection-fontsextra
sudo dnf -y install texlive-collection-fontsrecommended
sudo dnf -y install texlive-collection-latex
sudo dnf -y install texlive-collection-latexextra
sudo dnf -y install libatomic

exit 0
