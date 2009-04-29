##                                               -*- Autoconf -*-
## Process this file with autoconf to produce a configure script.

# Specify the name of this "application" and a version number
AC_INIT([xport], [2.05])
AM_INIT_AUTOMAKE([1.9.0 foreign])

# Explain that a file "config.h" should be generated
# AM_CONFIG_HEADER(config.h)

AC_COPYRIGHT([A C Norman])

# This would quite like autoconf version 2.57 or later. I am not quite
# certain how strict this is, but this line was suggested by another of
# the GNU build tools.
AC_PREREQ(2.57)

# My source file is expected to have "xport.c" in it. This is just a small
# sanity check in case somebody tries to configure with directories
# messed up.
AC_CONFIG_SRCDIR(xport.c)
AC_CONFIG_FILES(Makefile)

# What host am I on?
AC_CANONICAL_HOST()

AC_DEFINE_UNQUOTED(HOST_CPU,"$host_cpu",[Name of CPU])
AC_DEFINE_UNQUOTED(HOST_VENDOR,"$host_vendor",[Name of vendor])
AC_DEFINE_UNQUOTED(HOST_OS,"$host_os",[Name of Operating System])

case $host in
 *-*-cygwin*)
    AC_MSG_NOTICE([Building under cygwin])
# Here is the normal situation where cygwin is the BUILD environment.
    if test "x$prefix" = "xNONE"; then
       prefix="/cygdrive/c"
       AC_MSG_NOTICE([For windows I install in c:\bin by default])
    fi
#
# This comments has to go SOMEWHERE so here is maybe good enough. Some
# versions of gcc (in March 2004) come with a BROKEN set of include
# files for bits of <stdio.h> so that getc() can return negative values
# if a (binary) file contains characters with codes >= 128. Specifically
# a byte 0xff in a file can be returned as "-1" rather than as 0xff, and this
# then looks like EOF.  This glitch is to do with defaulting to use of
# signed characters. Because the bad behaviour seems to be within getch
# I can not work around it in my C code! But by forcing use of unsigned
# characters the world moves back towards sanity...
#
    CPPFLAGS="$CPPFLAGS -funsigned-char"
    windows_build=yes
    exeext=yes
    ;;
 *-*-msdos* | *-*-go32* | *-*-windows* | *-*-mingw*)
    AC_MSG_ERROR([For Windows you are expected to use cygwin])
    ;;
 *-*solaris*)
    AC_MSG_NOTICE([Building for Solaris])
# I USED to make a Solaris build default to using cc, because that was what
# worked on the system I had access to. I am changing that to use the
# default autoconf way of selecting a C compiler, which will more often find
# and use gcc. I will test this case under Solaris 10 x86 with gcc and
# assocated tools installed.
#   AC_MSG_NOTICE([Uses a Sun compiler by default])
# If the user has defined CC in advance then that version of the C compiler
# will be used and a default search will find a C++ compiler. But without
# any action I will use "cc" and "CC", which on the machine I have tested
# on gives me a Sun compiler.
#   if test "x$CC" = "x" ; then
#     CC=cc
#   fi
    ;;
 *darwin*)
    AC_MSG_NOTICE([Building for Macintosh/Darwin with X])
    darwin_build=yes
    LDFLAGS="$LDFLAGS -framework Carbon -framework CoreServices -framework ApplicationServices"
    macintosh_build=yes
# I need to make a provisional judgement about whether I will be supporting
# fat binaries here so that if I am I can disable dependency tracking. The
# mode of dependency tracking gets decided during the elaboration of
# AC_PROG_CC, and the "proper" test for fat binary support can only happen
# after I have found myself a C compiler. 
    echo "#include <stdio.h>" > conftest.c
    echo "int main()" >> conftest.c
# Until recently I had "\\n" after Hello here, but then some versions of echo
# as built-ins in "sh" truned that into a newline in a way that hury me. Since
# the C code here is never going to be used I will just avoid that delicacy!
    echo "{   printf(\"Hello\");" >> conftest.c
    echo "    return 0;" >> conftest.c
    echo "}" >> conftest.c
# First check a path that is best for Leopard (10.5) in December 2007.
    if gcc -isysroot /Developer/SDKs/MacOSX10.5.sdk -arch ppc -arch i386 $CFLAGS $LDFLAGS conftest.c -o conftest
    then
      AC_MSG_NOTICE([fat binary creation will probably be possible using 10.5])
      enable_dependency_tracking="no"
    else
# This is path works if I am on Tiger (10.4) in Spring 2007!
      if gcc -isysroot /Developer/SDKs/MacOSX10.4u.sdk -arch ppc -arch i386 $CFLAGS $LDFLAGS conftest.c -o conftest
      then
        AC_MSG_NOTICE([fat binary creation will probably be possible using 10.4])
        enable_dependency_tracking="no"
      else
        AC_MSG_NOTICE([fat binary creation will probably NOT be possible])
      fi
    fi
    ;;
 *-freebsd*)
    AC_MSG_NOTICE([Building on FreeBSD])
    ;;
 *)
    AC_MSG_NOTICE([Assuming a Unix-like environment, including Linux])
    ;;
esac

save="$CFLAGS"

# find C compiler
AC_PROG_CC

# Find the C preprocessor. 

AC_PROG_CPP

CFLAGS="$save"

if test "x$macintosh_build" = "xyes"
then
  sysroot=""
  AC_MSG_NOTICE([Checking for OSX10.5 framework])
  OLDCFLAGS="$CFLAGS"
  CFLAGS="$CFLAGS -isysroot /Developer/SDKs/MacOSX10.5.sdk"
  AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                                  [[printf("Hello\n");]])],
    [CXXFLAGS="$CXXFLAGS -isysroot /Developer/SDKs/MacOSX10.5.sdk"
     AC_MSG_NOTICE([MacOS10.5 SDK found])
     sysroot="/Developer/SDKs/MacOSX10.5.sdk"],
    [CFLAGS="$OLDCFLAGS"
     AC_MSG_NOTICE([MacOS10.5 SKD NOT found])])
  if test "x$sysroot" = "x"
  then
    AC_MSG_NOTICE([Checking for OSX10.4u framework])
    CFLAGS="$CFLAGS -isysroot /Developer/SDKs/MacOSX10.4u.sdk"
    AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                                    [[printf("Hello\n");]])],
      [CXXFLAGS="$CXXFLAGS -isysroot /Developer/SDKs/MacOSX10.4u.sdk"
       AC_MSG_NOTICE([MacOS10.4u SDK found])
       sysroot="/Developer/SDKs/MacOSX10.4u"],
      [CFLAGS="$OLDCFLAGS"
       AC_MSG_NOTICE([MacOS10.4u SKD NOT found])])
  fi
  OLDCFLAGS="$CFLAGS"
  CFLAGS="$CFLAGS -arch ppc -arch i386"
  AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                                  [[printf("Hello\n");]])],
    [CXXFLAGS="$CXXFLAGS -arch ppc -arch i386"
     LDFLAGS="$LDFLAGS -arch ppc -arch i386"
     fat_support_available="yes"],
    [CFLAGS="$OLDCFLAGS"
     fat_support_available="no"])
  AC_MSG_NOTICE([fat_support=$fat_support_available])
fi


# If I am using gcc I will try to build a 32-bit executable even if on
# a 64-bit system. This is to increase the changes that I can move
# executables around. Note that I explicitly verify that the version of
# gcc that I am using will build exeutables if given an "-m32" flag, so I
# hope that on platforms that are not able to cope with both widths I will
# not get caught out. This is mainly for Linux/x86_64 where 32-bit binaries
# are still good. And where a 32-bit binary can then be passed into any
# 32-bit sub-world or to another machine while 64-bit binaries would be
# less portable.

if test "x$darwin_build" != "xyes"; then
if test "x$GCC" = "xyes"; then
   OLDCPPFLAGS="$CPPFLAGS"
   OLDLDFLAGS="$LDFLAGS"
   CPPFLAGS="$CPPFLAGS -m32"
   LDFLAGS="$LDFLAGS -m32"
   AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <stdio.h>]],
                                   [[printf("Hello\n");]])],
   [AC_MSG_NOTICE([Using -m32 to force 32-bit compilation])],
   [CPPFLAGS="$OLDCPPFLAGS"
    LDFLAGS="$OLDLDFLAGS"
    AC_MSG_NOTICE([This version of gcc does not accept -m32])])
fi
fi

# Debugging turned on?
AC_MSG_CHECKING(for debugging)
AC_ARG_ENABLE(debug,[  --enable-debug           compile for debugging])
AC_MSG_RESULT([$enable_debug])

# In lots of cases I will be using gcc. In that case I will use -O2 for
# release code, but -O1 when debugging. I also stick in -Wall so I get
# loads of comments about code style etc. For other C compilers I do
# not set any optimisation flags but I do expect "-g" to be available
# to enable debugging.


if test "x$GCC" = "xyes" ; then
   if test "x$enable_debug" = "xyes" ; then
      CFLAGS="${CFLAGS} -fno-strict-aliasing -O1 -g -DDEBUG=1 -Wall"
      LDFLAGS="${LDFLAGS} -g"
   else
      CFLAGS="$CFLAGS -fno-strict-aliasing -O2 -Wall"
   fi
else
   if test "x$enable_debug" = "xyes" ; then
      CFLAGS="${CFLAGS} -g -DDEBUG=1"
      LDFLAGS="${LDFLAGS} -g"
   fi
fi

# Checks for header files.
AC_HEADER_DIRENT

AC_CHECK_HEADERS([sys/time.h unistd.h utime.h sys/stat.h])
AC_CHECK_HEADERS([arpa/inet.h netdb.h netinet/in.h sys/socket.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STAT
AC_STRUCT_TM
AC_CHECK_SIZEOF(int)
AC_CHECK_SIZEOF(long)

# Certainly Solaris needs extra libraries scanned for socket stuff

AC_CHECK_LIB(socket,socket)
AC_CHECK_LIB(nsl,gethostbyname)


# Checks for library functions.
AC_FUNC_STAT
AC_CHECK_FUNCS([ftruncate gethostbyaddr gethostbyname inet_ntoa])
AC_CHECK_FUNCS([mkdir rmdir socket])

AM_PROG_CC_C_O

#
# Make some things available for conditional segments of a Makefile
#

AM_CONDITIONAL(windows,test "x$windows_build" = "xyes")
AM_CONDITIONAL(cygwin,test "x$cygwin_build" = "xyes")
AM_CONDITIONAL(darwin,test "x$darwin_build" = "xyes")
AM_CONDITIONAL(debug,test "x$enable_debug" = "xyes")
AM_CONDITIONAL(exeext,test "x$exeext" = "xyes")

AC_OUTPUT

# end of "configure.ac"

