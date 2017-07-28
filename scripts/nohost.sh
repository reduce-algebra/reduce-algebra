#! /bin/sh
# Usage: scripts/nohost "$ac_configure_args"
# displays the arguments that are NOT ones that are specific to
# Reduce! It also removes any "--host=XXX" entry.

filter=""
for x in $1
do
# The processing here is so that I do not pass CSL or REDUCE-specific
# configuration flags down when configuring sub-packaged. This then has
# to have a catalogue of all the options I need to ignore. Messy!
  case $x in
  \'--host=*\' | \
  \'host_alias=*\' | \
  \'--with-force*\' | \
  \'--with*-autogen*\' | \
  \'--with-mingw*\' | \
  \'--with-lto*\' | \
  \'--with-m32*\' | \
  \'--with-m64*\' | \
  \'--with*-gui*\' | \
  \'--with*-xft*\' | \
  \'--with*-xim*\' | \
  \'--with-smallpage*\' | \
  \'--with*-fox*\' | \
  \'--with*-wx*\' | \
  \'--with-cyg*\' | \
  \'--with-csl*\' | \
  \'--with-psl*\' | \
  \'--with-build*\' | \
  \'--with-pslbuild*\' | \
  \'--with*-crlibm*\' | \
  \'--with*-boehm*\' | \
  \'--with*-redfront*\' | \
  \'--enable-debug*\' | \
  \'--enable-conservative*\' | \
  \'--enable-test*\' | \
  \'--enable-jit*\' | \
  \'--enable-static*\' | \
  \'--enable-silent*\' | \
  \'--disable-silent*\' )
    ;;
  *)
    filter="$filter $x"
    ;;
  esac
done

echo $filter
