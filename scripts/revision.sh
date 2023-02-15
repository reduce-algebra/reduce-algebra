#! /bin/sh
# I want this script to be one I can launch from anywhere, but at least
# some of its sub-scripts will not be so generous. So find out where it
# lives so that other locations can be found relative to that.
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`

# If called from an unversioned directory svnversion prints a message
# that depends on the current language. Set LANG=C to always print the
# english message.
LANG=C

# If a file called svnversion.txt exists in the toplevel directory, use
# its contents instead of svnversion's output. 
svnversiontxt=$here/../svnversion.txt
if test -s $svnversiontxt
then
  a=$(cat $svnversiontxt)
else
  a=$(svnversion -c $here/..)
fi

# Remove message and trailing modifiers from svnversion output.
a=`echo $a | grep -v 'Unversioned\|Uncommitted' | sed -e 's/[A-Z]*$//'` 
a=${a#*:}
echo $a

