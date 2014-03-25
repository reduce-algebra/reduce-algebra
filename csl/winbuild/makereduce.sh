#! /bin/bash -v

# This starts off my making fresh binaries of the variations of Reduce
# that are relevant to me here... In each case I should leave a log
# recording the build.

here=`cygpath -a .`
here=${here%/}
echo here = $here

script cyg32.log -c './makebin.sh cyg32 i686-pc-cygwin --with-cygwin'

script cyg64.log -c './cyg64.sh ./makebin.sh cyg64 x86_64-pc-cygwin --with-cygwin"'

script win32.log -c './makebin.sh win32 i686-w64-mingw32 \
   --with-cygbuild=$here/cyg32 --with-cygbuild64=$here/cyg64'

script win64.log -c './makebin.sh win64 x86_64-w64-mingw32 \
   --with-cygbuild=$here/cyg32 --with-cygbuild64=$here/cyg64'

echo All binaries should now be made

