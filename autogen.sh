#! /bin/sh -v

# autogen.sh

# This re-creates all the "configure" scripts and the like. It is needed
# because I am not using autoconf's own mechanisms for sub-directories
# and so doing an autoreconf once at the top-level is not enough.

# The flags to autoreconf indicate
#   -i    install fresh copies of all relevant script-files etc
#   -f    force all updates regardless of date-stamps
#   -v    display some information about what is being done.

autoreconf -i -f -v

cd csl/cslbase
autoreconf -i -f -v

cd ../fox
# The following two lines may be necessary on some systems?
rm -f ltmain.sh
touch ltmain.sh
autoreconf -i -f -v

if test -d ../foxtests
then
  cd ../foxtests
  autoreconf -i -f -v
fi

cd ../../psl
autoreconf -i -f -v

cd support-packages/xport-2.05
autoreconf -i -f -v

cd ../../..

scripts/resetall.sh

# end of autogen.sh
