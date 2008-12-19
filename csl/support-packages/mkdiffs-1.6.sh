#! /bin/sh
# See setup-patching-1.6.sh for explanation.

. ./fox-1.6-version.sh

# I feel that I HAVE to include the output files from autoconf etc
# here so that those who do not have the autoxxx tools installed can
# still build. This is rather nasty since the single file "configure" is
# around 860 Kbytes (and 26000 lines long) and a very great deal of that
# changes (maybe in frivolous ways) when built using a different release
# of autoconf. So I can end up with a 1.6 Mbyte patch file!

# Ah well, if that is what happens then that is what happens...

diff -Naur --strip-trailing-cr -x autom\* fox-1.6.${FOXVER} fox-1.6.${FOXVER}-new > fox-1.6.patches
