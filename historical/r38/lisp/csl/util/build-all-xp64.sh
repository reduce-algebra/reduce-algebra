#! /bin/sh
# This performs a cross-build for Windows XP (64-bit). Note that this
# can NOT manage any of the steps that involve running 64-bit executables
# because it is run in a 32-bit world...

./build-all.sh --with-xp64
