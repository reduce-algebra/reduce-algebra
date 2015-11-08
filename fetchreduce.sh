#! /bin/bash

# Fetch Reduce to a folder called "reduce-algebra"
# Give a username as an argument if you have write-authority to the
# sourceforge repository. E.g. I can go
#    fetchreduce.sh arthurcnorman

# The object of having this file is so that JUST THIS single small file
# can first be fetched manually. It can then be run to download all of
# Reduce.

if test "x$1" == "x"
then
  p="svn://"
else
  p="svn+ssh://${1}@"
fi

svn co \
   ${p}svn.code.sf.net/p/reduce-algebra/code/trunk \
   ${2:-reduce-algebra}

# Done!


