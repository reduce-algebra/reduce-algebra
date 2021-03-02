#! /bin/sh

# This attempts to install universal versions of all the software that
# Reduce needs to build it.

uupgrade

uinstall ncurses gperf libiconv gettext xz zlib libedit bzip2 expat
uinstall gsed pkgconfig subversion autoconf autoconf-archive m4
uinstall perl5 autoconf213 automake libtool bzip2 libffi python_select
uinstall python2_select python27 python39 xorg-libxcb xorg-libX11
uinstall perl5.28 Xft2 xorg-libXext ccache gtime gmake bc timeout
uinstall xorg-libXrandr xorg-libXcursor brotli fontconfig libffi gmp
uinstall astyle dvipng findutils fontforge gdb git gnuplot gnutar
uinstall gzip md5sha1sum netpbm psutils rsync texinfo

# Some things need "sudo" even though I think they ought not to! I try
# installing all the dependencies first without elevated priviledge.
uinstall `arm port echo rdepof:texlive-bin`
sudo uinstall texlive-bin

uinstall texlive-fonts-extra texlive-formats-extra texlive-latex-extra
uinstall texlive-plain-generic texlive-bin-extra
uinstall texlive-fonts-recommended wget

exit 0

