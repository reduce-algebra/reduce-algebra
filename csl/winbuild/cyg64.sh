#! /bin/bash
#
# Usage:
#   ./cyg64.sh COMMAND
# obeys the command but using 64-bit cygwin rather than 63-bit cygwin.
# Please edit CYG64ROOT below if you need to. You should have disks
# mounted in cygwin64 in the same pattern as with cygwin32...
#

# I am going to guess that cygwin64 has been installed in one of
# C;\cygwin64, d:\cygwin64 or e:\cygwin64. If none of these apply you
# will need to edit this file to put in your path.

if test -x /cygdrive/c/cygwin64/bin/bash
then
  CYG64ROOT=/cygdrive/c/cygwin64
elif test -x /cygdrive/d/cygwin64/bin/bash
then
  CYG64ROOT=/cygdrive/d/cygwin64
else
  CYG64ROOT=/cygdrive/e/cygwin64
fi

$CYG64ROOT/bin/bash --login -c "cd `cygpath -a .`; $*"

# done
