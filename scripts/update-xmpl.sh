#! /bin/bash

# I want this script to be one I can launch from anywhere, but at least
# some of its sub-scripts will not be so generous. So find out where it
# lives so that other locations can be found relative to that.

here=`dirname "$0"`
here=`cd "$here" ; pwd`
here=`dirname "$here"`

find $here/packages \( -name \*.tst -o -name \*.rlg \) -print | \
  xargs $here/scripts/copy-to-xmpl.sh



