#! /bin/bash

# Scan the disc to find cygwin installations and create files cyg32.exe
# and/or cyg64.exe to change between them. The executables are just not
# created if the relevant cygwin is not found.
#
# After this script has completed you can try
#
# uname -a
# ./cyg32 uname -a
# ./cyg64 uname -a
# and observe the environments in which the "uname -a" command is executed.
#

# Delete the binaries so that any left over ones do not persist and
# cause confusion.

rm -f cyg32.exe cyg64.exe


# I will try to create both cyg32.exe and cyg64.exe

for w in 64 32
do

# Identify a version of objdump that I can use. This is slightly messy
# because the platform I am searching for may (or may not!) be the same as
# the one I am running on. So if I have an explicit cross version of objdump
# I will use it.

case $w in
32)
  if which i686-pc-cygwin-objdump 1>/dev/null 2>/dev/null
  then
    objdump=i686-pc-cygwin-objdump
  else
    objdump=objdump
  fi
  ;;
64)
  if which x86_64-pc-cygwin-objdump 1>/dev/null 2>/dev/null
  then
    objdump=x86_64-pc-cygwin-objdump
  else
    objdump=objdump
  fi
esac

printf "\nBuild cyg$w.exe, a utility to launch cygwin$w tasks from any shell\n"

# As an optimisation I first search for cygwin in a directory
#     /cygdrive/*/*/bin
# where often it will be in /cygdrive/*/cygwin/bin or /cygdrive/*/cygwin64/bin.

where=""
for x in `find /cygdrive/*/*/bin -name cygwin1.dll -printf "%h\\n" 2>/dev/null`
do
  printf "... testing $x/cygwin1.dll\n"
  if test -x $x/bash.exe
  then
# I will accept a cygwin1.dll if objdump tells me it is the correct
# architecture for the version I am seeking.
    case `$objdump -a $x/cygwin1.dll 2>/dev/null`
    in
    *pei-i386*)
       if test "x$w" = "x32"
       then
         printf "Found $x\n"
         where="$x"
       fi
       ;;
    *pei-x86-64*)
       if test "x$w" = "x64"
       then
         printf "Found $x\n"
         where="$x"
       fi
       ;;
    esac
  fi
done

# If the search in /cygdrive/*/*/bin did not turn up anything I will
# scan all directores on all disc drives. This could be somewhat slow, but
# is there for the benefit of anybody who has installed cygwin somewhere
# other than in the root of a drive.

if test "x$where" = "x"
then
  printf "First pass failed to find cygwin: will now scan whole file-system\n"
  for x in `find /cygdrive/* -name cygwin1.dll -printf "%h\\n" 2>/dev/null`
  do
    printf "... testing $x/cygwin1.dll\n"
    if test -x $x/bash.exe
    then
      case `$objdump -a $x/cygwin1.dll 2>/dev/null`
      in
      *pei-i386*)
         if test "x$w" = "x32"
         then
           printf "Found $x\n"
           where="$x"
         fi
         ;;
      *pei-x86-64*)
         if test "x$w" = "x64"
         then
           printf "Found $x\n"
           where="$x"
         fi
         ;;
      esac
    fi
  done
fi
if test "x$where" = "x"
then
  printf "Unable to find a suitable $w bit version of cygwin1.dll"
else
  where=`cygpath -m ${where%/bin}`
# Whether I am running on cygwin32 or cygwin64 I should be able to use
# i686-w64-mingw32-gcc to create a native 32-bit windows binary that will
# be runnable. The code in other-cygwin.c uses CreateProcess to get the
# alternate version of cygwin launched...
  i686-w64-mingw32-gcc other-cygwin.c -Dcygwin=$where -o cyg$w
  printf "cyg$w.exe created to run $w bit cygwin tasks\n"
fi
done

# end of script
