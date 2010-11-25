#! /bin/sh
#
# This resets time-stamps in a sensible order in case they have
# got mangled. Ditto file permissions on "configure" scripts.

echo Resetting date-stamps on configuration files ...

find . \( -name configure.ac -o -name configure.in \
          -o -name Makefile.am \) -print | xargs touch
sleep 1

find . -name aclocal.m4 -print | xargs touch
sleep 1

find . -name config.h.in -print | xargs touch
sleep 1

find . -name Makefile.in -print | xargs touch
sleep 1

find . -name configure -print | xargs touch
find . -name configure -print | xargs chmod +x

echo datestamps should now be in the proper sequence.


