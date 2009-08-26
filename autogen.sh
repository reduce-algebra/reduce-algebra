#! /bin/sh

# autogen.sh

# This re-creates all the "configure" scripts and the like. It is needed
# because I am not using autoconf's own mechanisms for sub-directories
# and so doing an autoreconf once at the top-level is not enough.

# The flags to autoreconf indicate
#   -i    install fresh copies of all relevant script-files etc
#   -f    force all updates regardless of date-stamps
#   -v    display some information about what is being done.

# On a Macintosh (in particular) I have had pain because of the
# presence of a command called "libtool" that is not the GNU tool of
# that name. So here I check and I will refuse to recreate the
# various files if I can not see a "libtool" that suits me.

LIBTOOLIZE="libtoolize"
ltv=`libtoolize --version 2>&1`
gltv=`glibtoolize --version 2>&1`
ltavail="no"
case $ltv in
*GNU*libtool*)
  ltavail="yes"
  ;;
*)
  case $gltv in
  *GNU*libtool*)
    ltavail="yes"
    LIBTOOLIZE="glibtoolize"
    ;;
  esac
  ;;
esac

if test "$ltavail" != "yes"
then
  echo "Can not find GNU libtool installed. Will not do anything"
  exit 1
fi

echo "Updating autoconf scripts"

autoreconf -i -f -v || { echo "autoreconf failed in source root"; exit 1; }

echo "updating in csl"
(cd csl && rm -f ltmain.sh && touch ltmain.sh
    && ${LIBTOOLIZE} --force && ./autogen.sh) \
 || { echo "reconfiguring failed in csl"; exit 1; }

echo "updating in csl/cslbase"
(cd csl/cslbase && autoreconf -i -f -v && autoheader --force) \
 || { echo "autoreconf failed in csl/cslbase"; exit 1; }

echo "updating in csl/fox"
(cd csl/fox &&
# The following lines may be necessary on some systems?
rm -f ltmain.sh &&
touch ltmain.sh &&
${LIBTOOLIZE} --force && autoreconf -i -f -v) \
 || { echo "autoreconf failed in csl/fox"; exit 1; }

if test -d csl/foxtests
then
  echo "updating in csl/foxtests"
  (cd csl/foxtests && autoreconf -i -f -v) || { echo "autoreconf failed in csl/foxtests"; exit $1; }
fi

echo "updating in psl"
(cd psl && autoreconf -i -f -v) || { echo "autoreconf failed in psl"; exit 1; }

echo "updating in psl/support-packages/xport-2.05"
(cd psl/support-packages/xport-2.05 && autoreconf -i -f -v) \
 || { echo "autoreconf failed in psl/support-packages/xport-2.05"; exit 1; }

# XXX: What does it do exactly?
scripts/resetall.sh

exit $?

# end of autogen.sh
