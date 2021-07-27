#! /bin/bash

# macports-setup.sh                                    A C Norman July 2021

# $Id: macports-setup.sh 5713 2021-03-11 08:35:17Z arthurcnorman $

# This script can be used on a Macintosh (once macports has
# been installed, and that in turn required Xcode tools including its
# command-line option). It installs a collection of "ports" sufficient for
# building, testing and distributing Reduce.
#
# When a new release of the main Macintosh operating system is installed
# or an updated version of Xcode tools gets released it will be proper
# to refresh all ports. For a new operating system in general a fresh
# and updated version of macports itself may be required. But in both cases
# doing "sudo port uninstall all" will discard all current material
# and then this script can be used to reinstate it.

# This version is for use on an ARM-based Mac and it should install
# universal versions of enough ports to make it possible to build a
# "universal" Reduce, ie x86_64+aarch64.
# On an Intel Mac it starts the same process, but at the time of its release
# deveral ports will not install in univeral mode, and hance building
# bi-architecture Reduce on Intel hardware is not (yet) possible this way.
# By doing some manual building of the problematic ports and by tricking the
# macports system into thinking that they have been installed I suspect that
# progress would be possible!


# Ensure that the latest version of macports will be in use.
port selfupdate

port -N install subversion
port -N install gsed
port -N install autoconf autoconf-archive
port -N install autoconf213 perl5 m4 bzip2
port -N install automake libtool xz
port -N install python39 python_select
port -N install perl5.28
port -N install ccache gtime
port -N install astyle dvipng findutils fontforge
port -N install gdb git gnuplot gnutar gzip
port -N install md5sha1sum netpbm psutils rsync texinfo
port -N install texlive-fonts-extra texlive-formats-extra
port -N install texlive-latex-extra texlive-plain-generic
port -N install texlive-bin-extra texlive-fonts-recommended
port -N install wget gmake bc timeout bison


port -N install ncurses gperf libiconv +universal
port -N install gettext zlib libedit +universal
port -N install expat +universal
port -N install brotli +universal
port -N install gmp +universal
# The next line fails when run on an Intel Mac in late July 2021. libffi
# is needed for python39 and somewhere around here m4 gets needed. So this
# is about as far as I get on an Intel mac when trying for universal
# installs. Please keep trying every few weeks because the macports
# team continue to improve things!
port -N install libffi +universal
port -N install xorg-libxcb +universal
port -N install xorg-libX11 +universal
port -N install xorg-libXext +universal
port -N install xorg-libXrandr +universal
port -N install xorg-libXcursor +universal
port -N install fontconfig +universal
port -N install Xft2 +universal

#port -N install m4 +universal fails?? But I think that does not matter
# by now since all the things that depend on it have managed to build.
# There is a reported issue about it on the macports bug list, and I am
# thus expecting that the patches proposed there will filter through in due
# course...

exit 0
