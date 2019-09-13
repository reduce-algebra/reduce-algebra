#! /bin/sh
svn log -q -rHEAD:4454 |sed -n -e 's/^r\([0-9]*\) | .* | \([0-9]\{4\}-[0-9]\{2\}-[0-9]\{2\}\) .*$/Revision \1 : date \2/p' >revision_history.txt
