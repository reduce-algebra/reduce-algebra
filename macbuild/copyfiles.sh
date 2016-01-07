#! /bin/bash
# Used as a helper for packing the distribution
rm -rf distrib
mkdir distrib
mkdir distrib/psl
cp Reduce_source.tar.bz2 distrib/Reduce_source-$TODAY.tar.bz2
cp -r $1/cslbuild/*/csl/*.app distrib
cp -r $1/pslbuild/*/psl distrib/psl
cp -r $1/pslbuild/*/red distrib/psl
cp runpsl.sh distrib/psl/runpsl
exit
