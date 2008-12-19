#!/bin/sh
#
# Rebuild all the things that automake and friends can do for me

# A C Norman, 2008

echo Rebuild autoconfigure things...

rm -r aclocal.m4 autom4te.cache Makefile.in configure

echo
echo aclocal
aclocal

echo automake
automake

echo autoconf
autoconf

echo Configuration files now up to date.

