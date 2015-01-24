#! /bin/sh

# Install a single log file with the ".new" suffix

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`cd \`dirname "$here"\` ; pwd -P`

echo Installing log $1 into $2

if test -f $here/../logs/$1.rlg
then
  cp $here/../logs/$1.rlg $here/../packages/$2/$1.rlg.new
else
  echo "File $here/../logs/$1.rlg does not exist"
  exit 1
fi

