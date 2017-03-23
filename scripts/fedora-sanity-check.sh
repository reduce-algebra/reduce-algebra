# /bin/bash

# An attempt to install all packages needed for REDUCE development
# on a Fedora Workstation spin.   *** Not really tested yet ***

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

sudo dnf -y install gnuplot
sudo dnf -y install ImageMagick

sudo dnf -y install libXft-devel
sudo dnf -y install libXext-devel

sudo dnf -y install ncurses-devel
sudo dnf -y install ncurses-compat-libs

sudo dnf -y install polyml

sudo dnf -y install redhat-lsb-core

# The following pull in a lot of subpackages. Maybe we should be more selective.

sudo dnf -y install texlive-collection-fontsextra
sudo dnf -y install texlive-collection-fontsrecommended
sudo dnf -y install texlive-collection-latex
sudo dnf -y install texlive-collection-latexextra

exit 0
