#! /bin/sh -v

# autogen.sh

# This re-creates all the "configure" scripts and the like. It is needed
# because I am not using autoconf's own mechanisms for sub-directories
# and so doing an autoreconf once at the top-level is not enough.

aclocal
autoreconf

cd csl/cslbase
aclocal
autoreconf

cd ../fox
aclocal
autoreconf

if test -d ../foxtests
then
  cd ../foxtests
  aclocal
  autoreconf
fi

cd ../../psl
aclocal
autoreconf

cd ..

scripts/resetall.sh

# end of autogen.sh
