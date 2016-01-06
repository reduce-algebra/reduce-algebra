#! /bin/bash
# Used as a helper for packing the distribution
rm -rf distrib
mkdir distrib
mkdir distrib/psl
cp -r $1/cslbuild/*/csl/*.app distrib
cp -r $1/pslbuild/*/psl distrib/psl
cp -r $1/pslbuild/*/red distrib/psl
cp runpsl.sh distrib/psl/runpsl
exit
