#! /bin/bash -v

# Build a toolchain that can cross compile from the posix world here
# to create binaries for Windows on ARM. Eg the C++ compiler will
# be called aarch64-w64-mingw32-clang++ (but aarch64-w64-mingw32-g++
# will be the same thing, also using clang/llvm not actually gcc).
# The things that are built here are put in /usr/local/bin etc so you
# can expect to use them without needing to adjust your PATH, since
# you probably have that scanned already.


# I found that the default level of parallel build in som eof these
# scripts led to use of enough memory to crash my (WSL) Linux envirinment,
# so here I tone things down somewhat.
export CORES=$((`nproc` / 2))


build_toolchain() {

rm -rf llvm-mingw

git clone https://github.com/mstorsjo/llvm-mingw.git
cd llvm-mingw
  sudo time ./build-all.sh /usr/local
popd

}

build_zlib() {

rm -rf zlib.tar.gz zlib-*.*.* zlib-build
wget https://zlib.net/current/zlib.tar.gz
tar xvfz zlib.tar.gz
mkdir zlib-build
pushd zlib-build

# With the shell variables as set here zlib can be cross-built.

CHOST=aarch64-w64-mingw32 \
CC=aarch64-w64-mingw32-clang \
AR=aarch64-w64-mingw32-ar \
RANLIB=aarch64-w64-mingw32-ranlib \
../zlib-*.*.*/configure \
--prefix=/usr/local

make
sudo make install

popd

}

case "$1" in
toolchain)
  build_toolchain
  ;;

zlib)
  build_zlib
  ;;

all)
  build_toolchain
  build_zlib
  ;;

*)
  printf "Give an argument toolchain, zlib or all\n";
  ;;

esac
