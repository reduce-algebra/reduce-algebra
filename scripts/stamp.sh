#! /bin/sh
#
# This resets time-stamps in a sensible order in case they have
# got mangled. Ditto file permissions on "configure" scripts.
#
# If stamps are in the order as set here then "make" should never try
# to run autoconf or automake to rebuild them, and hence it should not
# matter what version (if any) of those tools you have installed on
# your computer.
#

echo Resetting date-stamps on configuration files ...

echo Step 1 of 5: configure.ac and configure.in
find . \( -name configure.ac -o -name configure.in \
          -o -name Makefile.am \) -print | xargs touch
sleep 1

echo Step 2 of 5: aclocal.m4
find . -name aclocal.m4 -print | xargs touch
sleep 1

echo Step 3 of 5: configure
find . -name configure -print | xargs touch
find . -name configure -print | xargs chmod +x
sleep 1

echo Step 4 of 5: config.h.in
find . -name config.h.in -print | xargs touch
sleep 1

echo Step 5 of 5: Makefile.in
find . -name Makefile.in -print | xargs touch

echo Date-stamps should now be in the proper sequence.


