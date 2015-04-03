#! /bin/sh

# This file tried to list instances of symbols where there could be conflict
# as between incmsistent capitalization. So if tere is a symbol "camelCase"
# and another "CamelCase", or is "x" is ysed in one place and "X" in another
# this will be reported.
# Names using in strings or comments (or within the "#Word;" notation for
# named unicode characters) are not considered. Special (but approximate)
# parsing is used to separate names used as types in the syntax as introduced
# by the "assert" package.

# This script can be run from anywhere. It creates three files in whatever
# directory is currenty when it is launched:
#    caseclash.files        list of Reduce source file it will scan
#    caseclash.log          log file probably only relevant on failure
#    caseclash.list         main output file reporting clashes.

# If the script is given an argument "redlog" is just scans files in the
# packages/redlog part of the Reduce tree. Special provision is made for
# redlog both because it is a large and important sub-part of Reduce and
# because it makes significant use of assert-style annotations.
#
# If any other argument is given than the script assumes that caseclash.files
# already exists and scans the files listed in it. An anticipated use case
# is
#     scripts/caseclash.sh
# (observe clashes, scan files to understand)
# (identify some files where work on them is to be deferred, and edit the
#  file caseclash.files to remove reference to them)
#     scripts/caseclash.sh some_argument
# This looks for clashes in the files you did not decide to defer so it is
# possible to tidy up the feasible parts of the system first and just come
# back to the hard bits later on.

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
# Here I filter out less1.red to less7.red because they use case
# for emphasis. They are old enough now that they really need an overall
# review I suspect!
  find $here/packages$dir -name \*.red -and -not -name less\*.red \
     > caseclash.files
# I avoid mathmlom.tst because it contains a load of markup notation
# rather than "straightforward" Reduce input.
  find $here/packages$dir -name \*.tst -and -not -name mathmlom.tst \
     >> caseclash.files
fi

$here/bin/redcsl -w \
   -Dfiles="caseclash.files" \
   -Doutputfile="caseclash.list" \
   "$here/generic/casefold/caseclash.red" \
   -l caseclash.log

# End of script
