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

AC_C_BIGENDIAN(
  [],
  AC_DEFINE(LITTLEENDIAN, [1], [Indicate byte order]),
  AC_MSG_ERROR([Unable to determine byte-order for this system]))

# I will suppose that if I am on a machine where pointers are 64-bits then
# 64-bit arithmetic will be fast, and that otherwise it may not be. This
# may not be quite fair on some 32-bit platforms, but since this is mainly
# just a performance issue I will not worry too much.

AC_CHECK_SIZEOF([void *])
AC_COMPUTE_INT(machine_size, SIZEOF_VOID_P)
AC_MSG_NOTICE([machine_size computed as $machine_size])

#if test $machine_size = 8
#then
# You can see that I was minded to set these two only if I was on a
# 64-bit machine. WHat I find is that if I do NOT set SOFTFLOAT_FAST_INT64
# and I then do not provide machine specific definitions of a bunch of
# things (for example softfloat_shortShiftLeft128) then the source code
# tries to define a functions whose return type is uint128 and
# include/primitiveTypes.h has not defined that - leading to a compilation
# failure. I might suggest that primitiveTypes.h should always define
# the type (even if it is not FAST) so as to avoid this sadness. Of course
# it is plausible that the functions that fail to compile will then in fact
# never be used, so an alternative fix would be to wrap tests on FAST_INT64
# around their definitions.
  AC_DEFINE(SOFTFLOAT_FAST_INT64,[1],[Assume a modern machine])
  AC_DEFINE(SOFTFLOAT_FAST_DIV64TO32,[1],[Assume a modern machine])
#fi

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
# but I probably could after use of AC_C_INLINE. But I then need
# to check whether that has gone "#define inline" to map the keyword onto
# an empty string because if it has I ought not to try setting INLINE_DEPTH.

AC_C_INLINE()
# AC_DEFINE(INLINE, inline, [])
# AC_DEFINE(INLINE_LEVEL, 5, [depth of inlining to be used])

AC_CONFIG_HEADERS([platform.h])

AC_OUTPUT

# end of "configure.ac"

