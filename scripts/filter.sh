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
# Some of the options listed here are no longer in use! Many are so
# specialised that no sane person would use them.
  case $x in
  *--*able-silent* | \
  *--enable-conservative* | \
  *--enable-debug* | \
  *--enable-experiment* | \
  *--enable-jit* | \
  *--enable-static* | \
  *--enable-test* | \
  *--with*-autogen* | \
  *--with*-boehm* | \
  *--with*-ccache* | \
  *--with*-crlibm* | \
  *--with*-fox* | \
  *--with*-gui* | \
  *--with*-redfront* | \
  *--with*-sequential* | \
  *--with*-throw* | \
  *--with*-threads* | \
  *--with*-win32bit* | \
  *--with*-wx* | \
  *--with*-xft* | \
  *--with*-xim* | \
  *--with-arithlib* | \
  *--with-build* | \
  *--with-cyg* | \
  *--with-force* | \
  *--with-lto* | \
  *--with-m32* | \
  *--with-m64* | \
  *--with-mingw* | \
  *--with-csl* | \
  *--with-psl* | \
  *--with-both* | \
  *--with-pslbuild* | \
  *--with-smallpage*)
    ;;
  *)
    filter="$filter $x"
    ;;
  esac
done

echo $filter
