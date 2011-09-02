#! /bin/sh
#
# Rebuild all the things that automake and friends can do for me

autoreconf -v


#echo Rebuild autoconfigure things...
#echo
#echo aclocal
#aclocal
#
#echo autoheader
#rm -f config.h.in
#autoheader
#
#echo automake
#rm -f Makefile.in
#automake
#
#echo autoconf
#rm -f configure
#autoconf

echo Configuration files now up to date.

