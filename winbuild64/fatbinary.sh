#! /bin/sh

# Assemble some of the built files & directories I will want,
# creating "fat binaries" for CSL, Reduce etc. Put results in the
# directory cslbuild.

rm -rf cslbuild
mkdir -p cslbuild/reduce.resources
cp -r cslwin64/csl/reduce.fonts cslbuild/reduce.fonts

cp Makefile.cslbuild cslbuild/Makefile

cd cslbuild && make && cd ..

echo all versions built
