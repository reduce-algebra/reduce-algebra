#! /bin/bash

for w in 64 32
do

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

where=""
for x in `find /cygdrive/*/*/bin -name cygwin1.dll -printf "%h\\n" 2>/dev/null`
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
  i686-w64-mingw32-gcc other-cygwin.c -Dcygwin=$where -o cyg$w
  printf "cyg$w.exe created to run $w bit cygwin tasks\n"
fi
done

