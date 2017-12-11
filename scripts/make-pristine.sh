#! /bin/sh

printf "This script is a DRASTIC one that is not expected to be useful in\n"
printf "ordinary circumstances, and should NOT be used casually. Its job is to\n"
printf "bring the local copy as closely into step with the files on subversion\n"
printf "as possible. In doing this it will DELETE any locally-built files and\n"
printf "DISCARD any local changes. So if you are a developer then use of this\n"
printf "script really risks leading to loss of your work.\n"
printf "\n"
printf "Are you certain that you wish to continue. Type YES in capitals if\n"
printf "you are\n"

read answer

if test "x$answer" != "xYES"
then
  printf "OK, not files will have been damaged.\n"
  exit 1
fi

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here/.."; pwd -P`

save=`pwd`
cd $here

# This looks for files that you have in your directory that subversion does
# not know of as copies of things from the main repository. I set up ready to
# delete all such. This may include local log files, work in progress or
# ANYTHING that you have put anywhere in this tree, and the idea of this
# script is that it is DELETED. Please note that you have been warned!

svn status | grep "^?" | sed -e "s/^[?]/rm -rf/g" | /bin/sh

# Some files or directories will be flagged as sv:ignore. They will
# not have been in the original archive, so I want to delete them too.

for x in `svn -R pl | \
  sed 's/^P/%P/g' | \
  tr '\n%' ' \n' | \
  grep svn:ignore | \
  sed "s/Properties on '//g" | \
  sed "s/':.*//g"`
do
  cd "$x"
  for y in `svn pg svn:ignore`
  do
    rm -rf $y
  done
  cd $here
done

# Unwind any local changes to files. Note that this LOSES any changes that
# you might have made intentionally, and so is not something to do casually.

svn -R revert .

# Bring in any files that have either been updated centrally or that are
# needed to replace things that you have deleted locally.

svn update

# At the end I HOPE that if you go
#     svn status
# if will not generate any reports at all. You should check that now.

printf "svn status report:\n"
svn status

printf "Distribution directory cleaned up\n"

cd $save
