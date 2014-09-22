#! /bin/bash -v

# Configure and build CSL version from scratch

reduce=`pwd`/..

# (1) a cygwin32 version

./cslcyg32.sh

# (2) a native-style win32 version

./cslwin32.sh

# (3) a native-style win64 version

./cslwin64.sh


# (4) a cygwin64 version

./cslcyg64.sh

# Now all versions should be built. Check sizes again

ls -lh csl*/csl/csl.exe csl*/csl/csl.com csl*/csl/csl.img
ls -lh csl*/csl/reduce.exe csl*/csl/reduce.com csl*/csl/reduce.img

# Assemble all the files I will want here

cp cslcyg32/csl/reduce.exe cyg32-reduce.exe
cp cslcyg64/csl/reduce.exe cyg32-reduce.exe
cp cslwin32/csl/reduce.exe win32-reduce.exe
cp cslwin64/csl/reduce.exe win64-reduce.exe
cp cslwin32/csl/reduce.com win32-reduce.com
cp cslwin64/csl/reduce.com win64-reduce.com
cp cslwin64/csl/reduce.img reduce.img
cp -r cslwin64/csl/reduce.fonts reduce.fonts
cp -r cslwin64/csl/reduce.resources reduce.resources


# end of build script




