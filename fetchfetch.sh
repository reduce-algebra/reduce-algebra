#! /usr/bin/env bash
# Fetch some files needed for starting to fetch and install Reduce.

r=https://sourceforge.net/p/reduce-algebra/code/HEAD/tree
wget $r/trunk/fetchreduce.sh\?format=raw -O fetchreduce.sh

# Edit this file so that the platform relevant to you is the one that is
# not commented out.

m=scientific-linux-sanity-check.sh
#m=fedora-sanity-check.sh
#m=ubuntu-sanity-check.sh
#m=cygwin-sanity-check.sh
#m=macports-setup.sh

wget $r/trunk/scripts/$m\?format=raw -O $m

ls -l fetchreduce.sh $m

# end of script

 
