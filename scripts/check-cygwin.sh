#! /bin/bash

missing=""

case `uname -a` in
*x86_64*)
  other="cygwin32"
  ;;
*)
  other="cygwin64"
  ;;
esac

for p in \
  automake \
  bash \
  bc \
  binutils \
  bison \
  bzip2 \
  coreutils \
  ${other} \
  ${other}-binutils \
  ${other}-bzip2 \
  ${other}-fontconfig \
  ${other}-freetype2 \
  ${other}-gcc-core \
  ${other}-gcc-g++ \
  ${other}-gmp \
  ${other}-gnutls \
  ${other}-isl \
  ${other}-libffi \
  ${other}-libtool \
  ${other}-libX11 \
  ${other}-libXext \
  ${other}-libXft \
  ${other}-libXrandr \
  ${other}-libXrender \
  ${other}-ncurses \
  ${other}-w32api-headers \
  ${other}-w32api-runtime \
  ${other}-zlib \
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
