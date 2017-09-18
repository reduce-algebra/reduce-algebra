#! /bin/bash

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`
here=`dirname "$here"`

find $here/cslbuild -name .deps | xargs rm -rf
find $here/cslbuild -name \*.dep | xargs rm

for d in `find $here/cslbuild -name config.status`
do
  pushd ${d%/*}
  printf "Tidying up `pwd`\n"
  ./config.status
done

exit 0