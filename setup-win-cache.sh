##! /bin/bash

# This is a script to set up windows-config-cache.

if test "$OS" != "Windows_NT"
then
  printf "\n+++ This script must be run on Windows +++\n"
  exit 1
fi

# I save the existing cslbuild in cslbuild-save while I process this script.
rm -rf cslbuild-save
mv cslbuild cslbuild-save

# Configure the versions of CSL for Windows. If any command line parameters
# are provided for this script they are passed to the configure step, and
# e.g. "--enable-debug" can make sense. This script can be run multiple
# times and will build up reference material for each option within
# the windows-config-cache directory.

./configure --with-csl $*

mkdir -p windows-config-cache
# Because I had started with a fresh cslbuild directory this will only
# find the material that has just been created to move across.
mv -f cslbuild/*cygwin* windows-config-cache
mv -f cslbuild/*windows* windows-config-cache

# Restore the user's previous state of cslbuild.
rm -rf cslbuild
mv cslbuild-save cslbuild

# Now there are some files that I do not need... If there are existing
# cached setups present the scripting from here down must be such that
# it will not damage them.

find windows-config-cache -name profile.dat | xargs rm -rf
find windows-config-cache -name canary.exe | xargs rm -rf
find windows-config-cache -name config.cache | xargs rm -rf
find windows-config-cache -name config.log | xargs rm -rf

R=`pwd`
sed -i "s+$R+../..+" windows-config-cache/*/Makefile
sed -i "s+$R+../../..+" windows-config-cache/*/*/Makefile
sed -i "s+$R+../../../..+" windows-config-cache/*/*/*/Makefile


for x in \
  `find windows-config-cache -type f | xargs grep -c cygdrive | grep -v :0`
do
  echo worry about $x
done
