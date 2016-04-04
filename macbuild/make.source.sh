#! /bin/bash -v
pushd C
tar cfj ../Reduce-source.tar.bz2 -X ../exclude.from.source.archive *
popd
