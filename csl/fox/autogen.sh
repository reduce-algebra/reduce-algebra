#!/bin/sh
#
# Rebuild all the things that automake and friends can do for me

# A C Norman, 2008-14

echo Rebuild autoconfigure things...

autoreconf -f -i -v

echo Configuration files now up to date.

