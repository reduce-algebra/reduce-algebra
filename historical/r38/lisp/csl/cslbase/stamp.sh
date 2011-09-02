#! /bin/sh
#
# This resets time-stamps in a sensible order in case they have
# got mangled. Ditto file permissions

echo Resetting date-stamps on configuration files ...

# The following two files are the basis for everything...
echo configure.ac Makefile.am
touch configure.ac
touch Makefile.am
sleep 1

echo aclocal
touch aclocal.m4
sleep 1

echo autoheader
touch config.h.in
sleep 1

echo automake
touch Makefile.in
sleep 1

echo autoconf
touch configure
chmod +x configure

echo datestamps should now be in the proper sequence.


