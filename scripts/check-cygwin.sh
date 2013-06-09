#! /bin/bash

missing=""

for p in \
  automake \
  bash \
  bc \
  binutils \
  bison \
  bzip2 \
  coreutils \
  cygwin64 \
  cygwin64-binutils \
  cygwin64-bzip2 \
  cygwin64-fontconfig \
  cygwin64-freetype2 \
  cygwin64-gcc-core \
  cygwin64-gcc-g++ \
  cygwin64-gmp \
  cygwin64-gnutls \
  cygwin64-isl \
  cygwin64-libffi \
  cygwin64-libtool \
  cygwin64-libX11 \
  cygwin64-libXext \
  cygwin64-libXft \
  cygwin64-libXrandr \
  cygwin64-libXrender \
  cygwin64-ncurses \
  cygwin64-w32api-headers \
  cygwin64-w32api-runtime \
  cygwin64-zlib \
  ed \
  findutils \
  flex \
  fontconfig \
  gcc \
  gcc-core \
  gcc-g++ \
  gcc4-core \
  gcc4-g++ \
  gdb \
  grep \
  gzip \
  initscripts \
  less \
  libffi-devel \
  libfontconfig-devel \
  libfontenc-devel \
  libfreetype-devel \
  libgtk2.0-devel \
  libncurses-devel \
  libstdc++6 \
  libstdc++6-devel \
  libX11-devel \
  libX11-xcb-devel \
  libXaw-devel \
  libXcomposite-devel \
  libXcursor-devel \
  libXdamage-devel \
  libXext-devel \
  libXfixes-devel \
  libXfont-devel \
  libXft-devel \
  libXm-devel \
  libXrandr-devel \
  libXrender-devel \
  libXRes-devel \
  libXt-devel \
  make \
  mingw64-i686-binutils \
  mingw64-i686-gcc-core \
  mingw64-i686-gcc-fortran \
  mingw64-i686-gcc-g++ \
  mingw64-i686-headers \
  mingw64-i686-pthreads \
  mingw64-i686-runtime \
  mingw64-x86_64-binutils \
  mingw64-x86_64-gcc-core \
  mingw64-x86_64-gcc-fortran \
  mingw64-x86_64-gcc-g++ \
  mingw64-x86_64-headers \
  mingw64-x86_64-pthreads \
  mingw64-x86_64-runtime \
  patch \
  sed \
  subversion \
  time \
  unzip \
  w32api \
  w32api-headers \
  w32api-runtime \
  wget \
  which \
  zlib-devel \
  bash
do
  r=`cygcheck -c $p`
  if ( echo $r | grep OK  > /dev/null)
  then
    echo $p is OK
  else
    echo $p is missing or not properly installed
    missing="$missing $p"
  fi
done

if test "x$missing" != "x"
then
  echo "Please (re)install $missing"
fi

exit 0
