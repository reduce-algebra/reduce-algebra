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
# Here I filter out less1.red to less7.red because they use case
# for emphasis. I filter our rlisp88.tst mainly because the
# /* ... */ style comments in it lead to comment text getting scanned
# in a manner that is unhelpful here.
  find $here/packages -name \*.red -and -not -name less\*.red \
     >> $here/scripts/caseclash.files
  find $here/packages -name \*.tst -and -not -name rlisp88.tst \
     >> $here/scripts/caseclash.files
fi

$O/bin/redcsl -w -Dfiles="$here/scripts/caseclash.files" -K800m \
   "$here/scripts/caseclash.red" -l "$here/scripts/caseclash.log"

# End of script
