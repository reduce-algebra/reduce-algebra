#! /bin/bash -v
pushd C
tar cfj ../Reduce-source_$1.tar.bz2 -X ../exclude.from.source.archive *
popd
