#! /bin/sh

output=revision_history.txt
test -z "$1" || output="$1"

# This script updates the revisions_history.txt file in the Reduce toplevel directory.
# Without a parameter it writes directly to revisions_history.txt.
# To write to another file, pass its path as parameter.
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here/.."; pwd -P`
cd $here

svn log -q -rHEAD:4454 |sed -n -e 's/^r\([0-9]*\) | .* | \([0-9]\{4\}-[0-9]\{2\}-[0-9]\{2\}\) .*$/Revision \1 : date \2/p' >"$output"
