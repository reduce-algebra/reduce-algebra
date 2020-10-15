#! /bin/bash

# This is a horrid script that I use to help me merge versions of CSL
# when I may have made changes on several platforms. If this needs a
# license it will be subject to the BSD one used elsewhere with CSL.
#
#                       Arthur Norman, October 2020

# REDUCE_MASTER must be set to something like
#    user@host:/path/to/reduce/top-level

if test "$1" != ""
then
  src="$1"
elif test "$REDUCE_MASTER" != ""
then
  src="$MASTER_CSLBASE"
else
  printf "Either provide a master location or set REDUCE_MASTER to one\n"
  exit 1
fi

# Fetch a copy of the files on the master site.
echo Master site $REDUCE_MASTER/csl/cslbase
mkdir -p master-cslbase
rsync $src/csl/cslbase/\*.{cpp,h,lsp,red,ac,am} master-cslbase

# Make a copy of what I have in the current directory
rm -rf local-cslbase
mkdir local-cslbase
cp *.h *.cpp *.lsp *.red Makefile.am configure.ac local-cslbase

# The two sets of files may have differences that are just in the $Id:$
# information that subversion updates, so I remove all the datestamps there!

pushd master-cslbase > /dev/null
for x in *.h *.cpp *.lsp *.red
do
  sed -i 's+$Id:.*+$Id $+g' $x
done
popd > /dev/null

pushd local-cslbase > /dev/null
for x in *.h *.cpp *.lsp *.red
do
  sed -i 's+$Id:.*+$Id $+g' $x
done
popd > /dev/null

# Now I am going to compare the two sets of files. I check the two versions
# and if they differ I run "diff -D" to create a record of the differences
# in changed-cslbase. So that directory should just collect a set of
# the files that have changed. It is possible that it might be good to use
# "diff3" rather than "diff -D" but what I do here at least leaves information
# to guide a subsequence manual merge.

rm -rf changed-cslbase
mkdir changed-cslbase
for x in *.h *.cpp *.lsp *.red Makefile.am configure.ac
do
# Only try comparisons if both files exist.
  if test -f local-cslbase/$x &&
     test -f master-cslbase/$x
  then
    if ! diff local-cslbase/$x master-cslbase > /dev/null
    then
      diff -DXXXYYYZZZ local-cslbase/$x master-cslbase > changed-cslbase/$x
    fi
  fi
done

# Tell the user what files have changed.

ls changed-cslbase

exit 0

