#! /bin/sh -v

# autogen.sh

# This re-creates all the "configure" scripts and the like. It is needed
# because I am not using autoconf's own mechanisms for sub-directories
# and so doing an autoreconf once at the top-level is not enough.

aclocal
autoreconf

cd csl/cslbase
aclocal
autoreconf -f

cd ../fox
aclocal
autoreconf -f

if test -d ../foxtests
then
  cd ../foxtests
  aclocal
  autoreconf -f
fi

cd ../../psl
aclocal
autoreconf -f

cd ..

scripts/resetall.sh

# end of autogen.sh
