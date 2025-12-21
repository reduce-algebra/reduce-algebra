#! /usr/bin/env bash

# Install all packages needed for REDUCE development
# on a Fedora Workstation spin.

# I used to use some package groups here, but they are not quite stable as
# across Fedora releases so I am moving to a clumsy detailed list.


sudo dnf -y install valgrind
sudo dnf -y install astyle
sudo dnf -y install automake
sudo dnf -y install pkgconfig
sudo dnf -y install gcc-c++
sudo dnf -y install binutils
sudo dnf -y install indent
sudo dnf -y install make
sudo dnf -y install elfutils
sudo dnf -y install gdb
sudo dnf -y install ltrace
sudo dnf -y install flex
sudo dnf -y install gcc
sudo dnf -y install autoconf
sudo dnf -y install libtool
sudo dnf -y install bison
sudo dnf -y install cscope
sudo dnf -y install strace
sudo dnf -y install byacc
sudo dnf -y install oprofile
sudo dnf -y install ccache
sudo dnf -y install ctags
sudo dnf -y install glibc-devel
sudo dnf -y install libtool
sudo dnf -y install patchutils
sudo dnf -y install systemtap
sudo dnf -y install diffstat
sudo dnf -y install doxygen
sudo dnf -y install git
sudo dnf -y install gettext
sudo dnf -y install subversion
sudo dnf -y install highlight
sudo dnf -y install patch
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
