#! /bin/sh -v
# Convert files from DOS to Unix format
# Usage:
#    dos2unix.sh file1 file2 ...
# converts in-place
#
if test "$#" = "0"
then
echo Usage: dos2unix.sh file1 file2 ...
exit 0
fi
for x in $@ ; do
if test -d $x
then
echo $x is a directory in dos2unix.sh
exit 0
fi
# BEWARE. I believe that not all versions of "tr" are compatible!
tr -d "\r" < $x > /tmp/dos2unix.tmp
mv /tmp/dos2unix.tmp $x
if test "x$verbose" != "x"
then
echo File $x converted to Unix style
fi
done
