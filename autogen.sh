#! /bin/sh -v

# autogen.sh

# This re-creates all the "configure" scripts and the like. It is needed
# because I am not using autoconf's own mechanisms for sub-directories
# and so doing an autoreconf once at the top-level is not enough.

aclocal
autoreconf -i -f -v

cd csl/cslbase
aclocal
autoreconf -i -f -v

cd ../fox
rm -f ltmain.sh
touch ltmain.sh
aclocal
autoreconf -i -f -v

if test -d ../foxtests
then
  cd ../foxtests
  aclocal
  autoreconf -i -f -v
fi

cd ../../psl
aclocal
autoreconf -i -f -v

cd ..

scripts/resetall.sh

# end of autogen.sh
