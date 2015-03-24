#! /bin/sh

# I want this script to be one I can launch from anywhere, but at least
# some of its sub-scripts will not be so generous. So find out where it
# lives so that other locations can be found relative to that.
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`cd \`dirname "$here"\` ; pwd -P`
here=`dirname "$here"`

if test "x$1" = "x"
then
  rm -f $here/scripts/caseclash.files
  find $here/packages \( -name \*.red -o -name \*.tst \) -print \
     >> $here/scripts/caseclash.files
fi

$O/bin/redcsl -w -Dfiles="$here/scripts/caseclash.files" -K800m \
   "$here/scripts/caseclash.red" -l "$here/scripts/caseclash.log"

# End of script
