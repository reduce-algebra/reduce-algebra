#! /usr/bin/env bash

# Please have MACOSX_DEPLOYMENT_TARGET say to 10.10 before invoking this.

# To build an executable copy of CSL or Reduce that does not rely on
# locally-provided (macports) libraries I need a copy of libfontconfig.a
# in the place that macports will link things from. This script makes
# one, and must be used before building the rest of the code.

# This is only needed because at the time of writing this macports only
# craetes a libfontconfig.dylib not a libfontconfig.a, and if you link
# against that the resulting application can not be distributed to others
# without risking not finding all the libraries that it needs. I apologise,
# and if I was working ONLY on the Macintosh and I was using the Xcode IDE
# and I was a proper Macintosh enthusiast and expert I might work around
# this using a private framework. But somebody keener on the OSX target can
# set that up if they want - I am not about to.

rm -rf fontconfig-2.11.1
tar xvfj ../support-packages/fontconfig-2.11.1.tar.bz2
cd fontconfig-2.11.1
export MACOSX_DEPLOYMENT_TARGET=10.10
./configure --enable-static
make
sudo cp src/.libs/libfontconfig.a /opt/local/lib
rm -rf fontconfig-2.11.1
