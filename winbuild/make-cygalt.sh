#! /bin/bash

# Scan the disc to find cygwin installations and create files cygalt.exe
# to change between them.
#
# After this script has completed you can try
#
# uname -a
# ./cygalt uname -a
# and observe the environments in which the "uname -a" command is executed.
#

rm -f cygalt.exe
i686-w64-mingw32-g++ -O3 other-cygwin.cpp -static -o cygalt
i686-w64-mingw32-strip cygalt

# end of script
