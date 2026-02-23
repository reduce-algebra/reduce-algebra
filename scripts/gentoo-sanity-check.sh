#! /bin/bash

# I suspect that by the nature of gentoo that different setups will
# start with various collections of read-installed packages and
# the flexibility of everything means that almost no script here can
# be universally applicable. This one documents the things I installed
# atop a prebuilt image called di-arm64-console-20260208T234616Z.qcow2
# that gave me a fairly modest starting point. Well that came with 1 16G
# virtual disk, so I used qemu-img etc to enlarge that. I have used that
# under qemu both emulated in an Intel/Linux system (where it is painfully
# slow but neverthless works) and on an ARM-based macbook where it is much
# more comfortable. I will then expect it to behave on a Raspberry Pi 5 in
# a way that is a bit slower but still fully realistic for use.
# With luck the same sort of sequence will apply for a system running
# natively rather than under qemu and at least plausibly most of this will
# be architecture-neutral.
#

sudo emerge --sync

for p in vim ntp openssh subversion autoconf autoconf-archive \
         automake libtook sys-libs/ncurses ncurses-compat ccache \
         gdb gentoo-sources genkernel sys-devel/bc gmp \
         libX11 libXcursor libXrender libXext libXft
do
  sudo emerge $p
done

# I then went "cd /usr/src; rm linux; ln -s *gentoo linux"
# followed by genkernel --menuconfig all where I instantly exited the
# menu not altering anything (but looking at what was set) and after that
# I can try
# sudo emerge dev-debug/rr
# but on the image I had I first needed to unmask it...
#
# What follows is a sketch of extras that may be needed for some
# experiments or for building documentation etc. I needed to make
# some adjustments to config files to get some of these to install.

for p in  harfbuzz texlive-fontsextra texlive-formatsextra texlive-latexextra \
          texlive-plaingeneric texlive-binextra texlive-fontsrecommended \
          fontconfig libffi gmp astyle dvipng sys-apps/findutils \
          fontforge gdb git gnuplot app-arch/gzip md5deep netpbm \
          psutils rsync sys-apps/texinfo wget
do
  sudo emerge $p
done
