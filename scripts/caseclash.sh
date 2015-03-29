#! /bin/sh

# I want this script to be one I can launch from anywhere, but at least
# some of its sub-scripts will not be so generous. So find out where it
# lives so that other locations can be found relative to that.
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`cd \`dirname "$here"\` ; pwd -P`
here=`dirname "$here"`

dir=""
if test "x$1" = "xredlog"
then
  shift
  dir="/redlog"
fi

if test "x$1" = "x"
then
  rm -f $here/scripts/caseclash.files
# Here I filter out less1.red to less7.red because they use case
# for emphasis. They are old enough now that they really need an overall
# review I suspect!
  find $here/packages$dir -name \*.red -and -not -name less\*.red \
     >> $here/scripts/caseclash.files
  find $here/packages$dir -name \*.tst \
     >> $here/scripts/caseclash.files
fi

$O/bin/redcsl -w -Dfiles="$here/scripts/caseclash.files" \
   "$here/scripts/caseclash.red" -l "$here/scripts/caseclash.log"

# End of script
