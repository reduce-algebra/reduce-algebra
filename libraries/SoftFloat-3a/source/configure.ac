## Process this file with autoconf to produce a configure script.

# A C Norman.                                               2016

# Specify the name of this "application" and a version number
AC_INIT([SoftFP],[3a])

AM_INIT_AUTOMAKE([1.13 -Wno-portability -Wno-override foreign dist-bzip2])

AC_PROG_RANLIB

AC_COPYRIGHT([Codemist])

AC_PREREQ(2.61)

AC_CONFIG_SRCDIR(softfloat_state.c)
AC_CONFIG_FILES(Makefile)

AC_CANONICAL_HOST()

AC_C_BIGENDIAN(
  [],
  AC_DEFINE(LITTLEENDIAN, [1], [Indicate byte order]),
  AC_MSG_ERROR([Unable to determine byte-order for this system]))

AC_CHECK_SIZEOF([void *])

# I will suppose that if I am on a machine where pointers are 64-bits then
# 64-bit arithmetic will be fast, and that otherwise it may not be. This
# may not be quite fair on some 32-bit platforms, but since this is mainly
# just a performance issue I will not worry too much.

AC_COMPUTE_INT(machine_size, SIZEOF_VOID_P)
AC_MSG_NOTICE([machine_size computed as $machine_size])

if test $machine_size = 8
then
  AC_DEFINE(SOFTFLOAT_FAST_INT64,[1],[Assume a modern machine])
  AC_DEFINE(SOFTFLOAT_FAST_DIV64TO32,[1],[Assume a modern machine])
fi

CPPFLAGS="$CPPFLAGS -I$srcdir -I$srcdir/8086-SSE -I$srcdir/include"

AC_ARG_ENABLE(debug,
  AC_HELP_STRING([--enable-debug],
                 [Select debugging build options]),
  [],
  [enable_debug="no"])


if test "$enable_debug" = "yes"
then
  CFLAGS="$CFLAGS -O1 -g"
else
  CFLAGS="$CFLAGS -O2"
fi

# At present I am not defining either INLINE or INLINE_LEVEL
# but I probably could after use of AC_C_INLINE

AC_C_INLINE()
# AC_DEFINE(INLINE, inline, [])
# AC_DEFINE(INLINE_LEVEL, 5, [depth of inlining to be used])

AC_CONFIG_HEADERS([platform.h])

AC_OUTPUT

# end of "configure.ac"

