#! /bin/sh
# Usage: scripts/filter "$ac_configure_args"
# displays the arguments that are NOT ones that are specific to
# Reduce!

filter=""
for x in $1
do
# The processing here is so that I do not pass CSL or REDUCE-specific
# configuration flags down when configuring sub-packages. This then has
# to have a catalogue of all the options I need to ignore. Messy!
# And what is more, sometimes they appear as '--with-xxx' and sometimes
# as just --with-xxx (sans the quote marks)....
  case $x in
  *--with-force* | \
  *--with*-autogen* | \
  *--with*-ccache* | \
  *--with-mingw* | \
  *--with-lto* | \
  *--with-m32* | \
  *--with-m64* | \
  *--with*-gui* | \
  *--with*-xft* | \
  *--with*-xim* | \
  *--with-smallpage* | \
  *--with*-fox* | \
  *--with*-wx* | \
  *--with-cyg* | \
  *--with-csl* | \
  *--with-psl* | \
  *--with-build* | \
  *--with-pslbuild* | \
  *--with*-crlibm* | \
  *--with*-boehm* | \
  *--with*-redfront* | \
  *--with*-sequential* | \
  *--enable-debug* | \
  *--enable-conservative* | \
  *--enable-test* | \
  *--enable-jit* | \
  *--enable-static* | \
  *--*able-silent* )
    ;;
  *)
    filter="$filter $x"
    ;;
  esac
done

echo $filter
