# /bin/bash

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
# to the Reduce mailing lists so tha thos script can catch up.

sudo dnf -y group install C\ Development\ Tools\ and\ Libraries

# The above command installs

#   valgrind        astyle       automake
#   pkgconfig       gcc-c++      binutils
#   indent          make         elfutils
#   gdb             ltrace       flex    
#   gcc             autoconf     bison   
#   cscope          strace       byacc   
#   oprofile        ccache       ctags   
#   glibc-devel     libtool              

sudo dnf -y group install Development\ Tools

# This installs 

#   patchutils           systemtap           diffstat
#   doxygen              git                 gettext 
#   subversion           highlight           patch   

sudo dnf -y install openssh
sudo dnf -y install vim

sudo dnf -y install gnuplot
sudo dnf -y install ImageMagick

sudo dnf -y install libXft-devel
sudo dnf -y install libXext-devel

sudo dnf -y install ncurses-devel
sudo dnf -y install ncurses-compat-libs

sudo dnf -y install libffi-devel

sudo dnf -y install polyml

sudo dnf -y install redhat-lsb-core

# The following pull in a lot of subpackages. Maybe we should be more selective.

sudo dnf -y install texlive-collection-fontsextra
sudo dnf -y install texlive-collection-fontsrecommended
sudo dnf -y install texlive-collection-latex
sudo dnf -y install texlive-collection-latexextra

exit 0
