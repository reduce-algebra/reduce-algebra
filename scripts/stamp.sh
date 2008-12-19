#! /bin/sh
#
# This resets time-stamps in a sensible order in case they have
# got mangled. Ditto file permissions

echo Resetting date-stamps on configuration files ...

# First deal with the top-level directory

touch configure.ac
touch Makefile.am
sleep 1

touch aclocal.m4
sleep 1

touch Makefile.in
sleep 1

touch configure
chmod +x configure

cd csl/cslbase

echo CSLBASE: configure.ac Makefile.am
touch configure.ac
touch Makefile.am
sleep 1

echo CSLBASE: aclocal
touch aclocal.m4
sleep 1

echo CSLBASE: autoheader
touch config.h.in
sleep 1

echo CSLBASE: automake
touch Makefile.in
sleep 1

echo CSLBASE: autoconf
touch configure
chmod +x configure

cd ../fox

echo FOX: configure.in Makefile.am
touch configure.in
touch Makefile.am
sleep 1

echo FOX: aclocal
touch aclocal.m4
sleep 1

echo FOX: automake
touch Makefile.in
touch include/Makefile.in
touch src/Makefile.in
touch utils/Makefile.in
sleep 1

echo FOX: autoconf
touch configure
chmod +x configure

cd ../foxtests

echo foxtests: configure.ac Makefile.am
touch configure.ac
touch Makefile.am
sleep 1

echo foxtests: aclocal
touch aclocal.m4
sleep 1

echo foxtests: automake
touch Makefile.in
sleep 1

echo foxtests: autoconf
touch configure
chmod +x configure

cd ../../psl

echo PSL: configure.ac Makefile.am
touch configure.ac
touch Makefile.am
sleep 1

echo PSL: aclocal
touch aclocal.m4
sleep 1

#echo PSL: autoheader
#touch config.h.in
#sleep 1

echo PSL: automake
touch Makefile.in
sleep 1

echo PSL: autoconf
touch configure
chmod +x configure

cd ..

echo datestamps should now be in the proper sequence.


