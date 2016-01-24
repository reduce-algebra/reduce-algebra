#! /bin/bash

# I now NEED cygwin to be in c:\cygwin and the 64-bit version to be
# in c:\cygwin64.

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
i686-w64-mingw32-g++ other-cygwin.cpp -o cygalt

# end of script
