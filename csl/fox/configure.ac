# configure.ac

# Version of the code
m4_define([fox_major], [1])
m4_define([fox_minor], [6])
m4_define([fox_level], [49])
m4_define([fox_version],[fox_major.fox_minor.fox_level])

# Init
AC_INIT(fox,[fox_version],jeroen@fox-toolkit.com)
AC_CONFIG_SRCDIR([include/fx.h])
AM_INIT_AUTOMAKE([foreign])

# Set version
FOX_MAJOR_VERSION=fox_major
FOX_MINOR_VERSION=fox_minor
FOX_PATCH_LEVEL=fox_level

# Binaries compiled with this patchlevel of FOX will need at least
# version MAJOR.MINOR.INTERFACE_VERSION to run. The assertion
# FOX_INTERFACE_VERSION >= FOX_BINARY_VERSION must hold.
#
# Increment this when an API is added
FOX_INTERFACE_VERSION=0

# Binaries compiled with at least MAJOR.MINOR.BINARY_VERSION are
# compatible with this release of FOX.
#
# Set this to FOX_INTERFACE_VERSION's value if API changed or removed
FOX_BINARY_VERSION=0

# Report what was found
AC_MSG_CHECKING(major version)
AC_MSG_RESULT($FOX_MAJOR_VERSION)
AC_MSG_CHECKING(minor version)
AC_MSG_RESULT($FOX_MINOR_VERSION)
AC_MSG_CHECKING(patch level)
AC_MSG_RESULT($FOX_PATCH_LEVEL)

# Substitute variables in output files
AC_SUBST(FOX_MAJOR_VERSION)
AC_SUBST(FOX_MINOR_VERSION)
AC_SUBST(FOX_PATCH_LEVEL)

# CURRENT:  Most recent interface library implements
# REVISION: The implementation number of the CURRENT interface
# AGE:      The difference between the newest and oldest interfaces that this
#           library implements.  The library implements all the interface numbers
#           in the range from number CURRENT - AGE to CURRENT.
LT_RELEASE=$FOX_MAJOR_VERSION.$FOX_MINOR_VERSION
LT_CURRENT=$FOX_INTERFACE_VERSION
LT_REVISION=`expr $FOX_PATCH_LEVEL - $FOX_INTERFACE_VERSION`
LT_AGE=`expr $FOX_INTERFACE_VERSION - $FOX_BINARY_VERSION`

# Substitute variables in output files
AC_SUBST(LT_RELEASE)
AC_SUBST(LT_CURRENT)
AC_SUBST(LT_REVISION)
AC_SUBST(LT_AGE)

# Prevents setting flags.
CXXFLAGS=""

# More secret source
AC_GNU_SOURCE

# Check using C++
AC_LANG(C++)

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB

AC_CANONICAL_HOST

case $host_os in
  *darwin*)
# Ugh! With macports the autoconf recipe that establishes X11 paths
# fails to include this one but it is needed!
    CXXFLAGS="$CXXFLAGS -I/opt/local/include/freetype2"
  ;;
  *mingw32*)
    AC_MSG_NOTICE([host_os=$host_os so building for native Windows])
    win32="yes"
  ;;
esac

if test "x$win32" = "xyes"
then
  X_BASE_LIBS="-lcomctl32 -lwsock32 -lwinspool -lmpr -lgdi32 -limm32"
  LIBGLU="-lglu32"
  LIBGL="-lopengl32"
else
  X_BASE_LIBS="-lX11 -lXext"
  LIBGLU="-lGLU"
  LIBGL="-lGL"
  AC_PATH_X
  AC_PATH_XTRA
fi

AC_HEADER_TIME
AC_HEADER_SYS_WAIT
AC_HEADER_DIRENT
AC_FUNC_MMAP

# Byte order
AC_C_BIGENDIAN([FOX_BYTEORDER=1], [FOX_BYTEORDER=0])
AC_SUBST(FOX_BYTEORDER)

# Threads
AC_CHECK_LIB(rt,clock_gettime)
AC_CHECK_LIB(pthread, pthread_exit)

# Check for dynamic loader
AC_CHECK_LIB(dl, dlopen)
AC_CHECK_LIB(dld, shl_load)

# Check vsscanf
AC_CHECK_FUNCS(vsscanf vsnprintf strtoll strtoull)

# Add copious amounts of debugging with gcc
if test "${GXX}" = "yes" ; then
  # There is an issue about just how much output from g++ actually helps
  # me. A plausible view is that extra warnings should be enabled at a
  # stage that a blitz through the code to remove their cause is to be
  # activated.
  #OVERLOADED_VIRTUAL=-Woverloaded-virtual
  CXXFLAGS="${CXXFLAGS} -Wall -Wformat $OVERLOADED_VIRTUAL -Wshadow"
  #LDFLAGS="-rdynamic ${LDFLAGS}"
fi

# Debugging turned on
AC_MSG_CHECKING(for debugging)
AC_ARG_ENABLE(debug,[  --enable-debug          compile for debugging])
AC_MSG_RESULT([$enable_debug])
if test "x$enable_debug" = "xyes" ; then
  CXXFLAGS="${CXXFLAGS} -O0 -g -DDEBUG"
  if test "${GXX}" = "yes"; then
    CXXFLAGS="${CXXFLAGS} -ffast-math -fstrict-aliasing -fno-inline-functions"
  fi
fi

# Building for release
AC_MSG_CHECKING(for release build)
AC_ARG_ENABLE(release,[  --enable-release        compile for release])
AC_MSG_RESULT([$enable_release])
if test "x$enable_release" = "xyes" && test "x$enable_debug" != "xyes"; then
  CXXFLAGS="${CXXFLAGS} -O2 -DNDEBUG"
  if test "${GXX}" = "yes" ; then
    CXXFLAGS="${CXXFLAGS} -Wuninitialized -ffast-math -fstrict-aliasing -finline-functions -fomit-frame-pointer -fexpensive-optimizations"
    LDFLAGS="-s ${LDFLAGS}"
  fi
fi

# Enable profiling
AC_MSG_CHECKING(for profiling)
AC_ARG_WITH(profiling,[  --with-profiling        choices are yes, no, or gprof])
AC_MSG_RESULT([$with_profiling])
if test "x$with_profiling" = "xyes" ; then
CXXFLAGS="${CXXFLAGS} -p"
elif test "x$with_profiling" = "xgprof" ; then
CXXFLAGS="${CXXFLAGS} -pg"
fi


# Check for JPEG Image support
AC_ARG_ENABLE(jpeg,[  --disable-jpeg          compile without JPEG image support])
AC_MSG_RESULT([$enable_jpeg])
if test "x$enable_jpeg" != "xno"; then
AC_CHECK_HEADER(jpeglib.h,CXXFLAGS="${CXXFLAGS} -DHAVE_JPEG_H=1"; LIBS="${LIBS} ${LIBJPEG:=-ljpeg}")
fi


# Check for PNG Image support; note zlib is needed for PNG
AC_ARG_ENABLE(png,[  --disable-png           compile without PNG image support])
AC_MSG_RESULT([$enable_png])
if test "x$enable_png" != "xno"; then
AC_CHECK_HEADERS(png.h,CXXFLAGS="${CXXFLAGS} -DHAVE_PNG_H=1"; LIBS="${LIBS} ${LIBPNG:=-lpng}")
fi


# Check for TIFF Image support; note zlib is needed for TIFF
AC_ARG_ENABLE(tiff,[  --disable-tiff          compile without TIFF image support])
AC_MSG_RESULT([$enable_tiff])
if test "x$enable_tiff" != "xno"; then
AC_CHECK_HEADERS(tiff.h,CXXFLAGS="${CXXFLAGS} -DHAVE_TIFF_H=1"; LIBS="${LIBS} ${LIBTIFF:=-ltiff}")
fi


# Check for libz compression library
AC_ARG_ENABLE(zlib,[  --disable-zlib          compile without zlib support])
AC_MSG_RESULT([$enable_zlib])
if test "x$enable_zlib" != "xno"; then
AC_CHECK_HEADERS(zlib.h,CXXFLAGS="${CXXFLAGS} -DHAVE_ZLIB_H=1"; LIBS="${LIBS} ${LIBZ:=-lz}")
fi


# Check for bzip2 compression library
AC_ARG_ENABLE(bz2lib,[  --disable-bz2lib        compile without bz2lib support])
AC_MSG_RESULT([$enable_bz2lib])
if test "x$enable_bz2lib" != "xno"; then
AC_CHECK_HEADERS(bzlib.h,CXXFLAGS="${CXXFLAGS} -DHAVE_BZ2LIB_H=1"; LIBS="${LIBS} ${LIBBZ2:=-lbz2}")
fi


# Check for Xft2 support
AC_MSG_CHECKING(for Xft support)
AC_ARG_WITH(xft,[  --with-xft              enable Xft support])
AC_MSG_RESULT([$with_xft])
if test "x$with_xft" != "xno"; then
XFTCFLAGS="-I/usr/include/freetype2"
XFTLIBS="-lfreetype -lXft"
saved_cppflags="${CXXFLAGS}"
CXXFLAGS="${CXXFLAGS} -DHAVE_XFT_H=1 $XFTCFLAGS"
X_BASE_LIBS="${X_BASE_LIBS} $XFTLIBS"
fi


# Check for XShm support
AC_ARG_WITH(xshm,[  --with-xshm             compile with XShm support])
AC_MSG_RESULT([$with_xshm])
if test "x$with_xshm" != "xno"; then
AC_CHECK_HEADERS(X11/extensions/XShm.h,CXXFLAGS="${CXXFLAGS} -DHAVE_XSHM_H=1",, [#include <X11/Xlib.h>])
fi


# Check for XShape support
AC_ARG_WITH(shape,[  --with-shape            enable XShape support])
AC_MSG_RESULT([$with_shape])
if test "x$with_shape" != "xno"; then
AC_CHECK_HEADERS(X11/extensions/shape.h,CXXFLAGS="${CXXFLAGS} -DHAVE_XSHAPE_H=1",, [#include <X11/Xlib.h>])
fi


# Check for Xcursor support
AC_ARG_WITH(xcursor,[  --with-xcursor          compile with Xcursor support])
AC_MSG_RESULT([$with_xcursor])
if test "x$with_xcursor" != "xno"; then
AC_CHECK_HEADERS(X11/Xcursor/Xcursor.h,CXXFLAGS="${CXXFLAGS} -DHAVE_XCURSOR_H=1"; X_BASE_LIBS="${X_BASE_LIBS} -lXcursor",, [#include <X11/Xlib.h>])
fi


# Check for XRender support
AC_ARG_WITH(xrender,[  --with-xrender          compile with XRender support])
AC_MSG_RESULT([$with_xrender])
if test "x$with_xrender" != "xno"; then
AC_CHECK_HEADERS(X11/extensions/Xrender.h,CXXFLAGS="${CXXFLAGS} -DHAVE_XRENDER_H=1"; X_BASE_LIBS="${X_BASE_LIBS} -lXrender",, [#include <X11/Xlib.h>])
fi


# Check for XRandR support
AC_ARG_WITH(xrandr,[  --with-xrandr           compile with XRandR support])
AC_MSG_RESULT([$with_xrandr])
if test "x$with_xrandr" != "xno"; then
AC_CHECK_HEADERS(X11/extensions/Xrandr.h,CXXFLAGS="${CXXFLAGS} -DHAVE_XRANDR_H=1"; X_BASE_LIBS="${X_BASE_LIBS} -lXrandr",, [#include <X11/Xlib.h>])
fi


# Check for XFixes support
AC_ARG_WITH(xfixes,[  --with-xfixes           compile with XFixes support])
AC_MSG_RESULT([$with_xfixes])
if test "x$with_xfixes" != "xno"; then
AC_CHECK_HEADERS(X11/extensions/Xfixes.h,CXXFLAGS="${CXXFLAGS} -DHAVE_XFIXES_H=1"; X_BASE_LIBS="${X_BASE_LIBS} -lXfixes",, [#include <X11/Xlib.h>])
fi


# Check for XInput support
AC_ARG_WITH(xinput,[  --with-xinput           compile with XInput support])
AC_MSG_RESULT([$with_xinput])
if test "x$with_xinput" != "xno"; then
AC_CHECK_HEADERS(X11/extensions/XInput.h,CXXFLAGS="${CXXFLAGS} -DHAVE_XINPUT_H=1"; X_BASE_LIBS="${X_BASE_LIBS} -lXi",, [#include <X11/Xlib.h>])
fi


# Check for Input Method support
AC_ARG_WITH(xim,[  --with-xim              compile with XIM support])
AC_MSG_RESULT([$with_xim])
##if test "x$with_xim" = "xno"; then
if test "x$with_xim" != "xyes"; then
CXXFLAGS="${CXXFLAGS} -DNO_XIM"
fi

# Substitute variables in output files
AC_SUBST(X_LIBS)
AC_SUBST(X_BASE_LIBS)
AC_SUBST(X_EXTRA_LIBS)
AC_SUBST(X_PRE_LIBS)

# Compile with 3D support
AC_MSG_CHECKING(for OpenGL support)
AC_ARG_WITH(opengl,[  --with-opengl           choices are yes, no])
AC_MSG_RESULT([$with_opengl])
if test "x$with_opengl" != "xno" ; then
AC_CHECK_HEADER(GL/glu.h,CXXFLAGS="${CXXFLAGS} -DHAVE_GLU_H=1"; LIBS="${LIBS} ${LIBGLU}")
AC_CHECK_HEADER(GL/gl.h,CXXFLAGS="${CXXFLAGS} -DHAVE_GL_H=1"; LIBS="${LIBS} ${LIBGL}")
GL_LIBS="${LIBGL} ${LIBGLU}"
fi

# For use with Reduce there are a bunch of "--with-xxx" options that are not
# important here but it seems neatest to prevent their use from leading to
# warning messages...
AC_ARG_WITH(csl,[  --with-csl              stray option from the Reduce build setup])
AC_ARG_WITH(force,[  --with-force            stray option from the Reduce build setup])
AC_ARG_WITH(cygwin,[  --with-cygwin           stray option from the Reduce build setup])
AC_ARG_WITH(cygbuild,[  --with-cygbuild         stray option from the Reduce build setup])
AC_ARG_WITH(cygbuild64,[  --with-cygbuild64       stray option from the Reduce build setup])
AC_ARG_WITH(build,[  --with-build            stray option from the Reduce build setup])
AC_ARG_WITH(pslbuild,[  --with-pslbuild         stray option from the Reduce build setup])

# Substitute variables in output files
AC_SUBST(GL_LIBS)

# Access to terminal control things...

# I want to support some flavour of direct screen addressing. 
# On Windows I use the Console API. 
# Otherwise I need both term.h and [n]curses.h. Sometimes the file
# may be <ncurses/term.h>. If term.h is not available I may survive
# on tgetent.
# For linking I count "tgetent" as an adequate function to test for
# as diagnostic of curses.

# I am giving up on supporting things that only have "termcap" on the
# grounds that that is now supposed to count as ancient.
# At an earlier stage I deeply nested messes of tests here. They became
# confusing! So now I will just check for each header and then work out later
# on if I have enough to support what I need.

if test "x$win32" != "xyes"
then
  AC_CHECK_HEADERS(termios.h sys/ioctl.h)

  AC_CHECK_HEADERS(curses.h ncurses.h)

  AC_MSG_NOTICE([curses=$HAVE_CURSES_H ncurses=$HAVE_NCURSES_H])

  AC_CHECK_LIB(curses, tgetent, [],
    [AC_CHECK_LIB(ncurses, tgetent)])

# There is a misery here! "term.h" (on some machines) needs cuses.h
# included first (typically to define "bool" for it).
  AC_CHECK_HEADERS(term.h,[],[],
     [#if HAVE_CURSES_H
      #include <curses.h>
      #else
      #if HAVE_NCURSES_H
      #include <ncurses.h>
      #endif
      #endif])
  AC_CHECK_HEADERS(ncurses/term.h,[],[],
     [#if HAVE_CURSES_H
      #include <curses.h>
      #else
      #if HAVE_NCURSES_H
      #include <ncurses.h>
      #endif
      #endif])

  AC_CHECK_FUNCS([tgetent tputs])

# Now I have access to some terminfo support. I would like to know if
# the convenience function cfmakeraw is present since if so I will use
# it, but if it is not there I will just simulate what I hope it does.
  AC_CHECK_FUNCS(cfmakeraw)

fi

AC_CHECK_HEADERS([unistd.h])

case $host_os in
  *darwin*)
    CC="MACOSX_DEPLOYMENT_TARGET=10.7 $CC"
    CXX="MACOSX_DEPLOYMENT_TARGET=10.7 $CXX"
  ;;
esac

AM_CONDITIONAL(xp64, test "x$mingw64" = "xyes")
AM_CONDITIONAL(cygwinshell, test "x$win32" = "xyes")
AM_CONDITIONAL(canrun, test "x$cross_compiling" != "xyes")

# Done.
AC_OUTPUT(Makefile
utils/Makefile
include/Makefile
include/fxver.h
src/Makefile
src/version.rc
fox.spec
fox-config
fox.pc)
