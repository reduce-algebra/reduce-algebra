#! /bin/bash

# This makes some release (or at least snapshot) archives
# It attempts to ensure that everything is in a fully tidy state
# first. When run on Linux it will expect to be on a 64-bit Linux
# that has both 32 and 64-bit mingw cross compilers installed.

# On other platforms it merely builds the current local version

# I force recompilation of the GUI library, re-profile the system,
# re-generates C code etc. Thus everything takes a while.

mkdir -p releases


# First the Java version
pushd jlisp
  make clean
  make
  da=`date +%Y%m%d`
  cp reduce.jar ../releases/reduce-$da.jar
  cp minireduce.jar ../releases/minireduce-$da.jar
popd

h=`./config.guess`
h=`scripts/findhost.sh $h`

echo "Current host = $d"

rm -rf cslbuild/$h/lib cslbuild/$h/include cslbuild/$h/bin
./configure --with-csl
pushd cslbuild/$h
  make clean
  rm -rf lib include bin
# Note that I will only need to profile and regenerate c-code
# once since the relevant files will be shared across all versions
# build on this machine.
  make profile
  make c-code
  cp ../generated-c/* ../../csl/generated-c
  make
  cd csl
# Get rid of any previous archive
  rm -f reduce*zip reduce*bz2
  make save
  if test -f reduce*zip
  then
    mv reduce*zip ../../../releases
  else
    mv reduce*bz2 ../../../releases
  fi
popd

# Create a source archive. I do this now that the profile and generated-c
# is up to date

scripts/newdist.sh
mv reduce-algebra*bz2 releases
# I do not want the non-date-stamped symbolic link
rm releases/reduce-algebra.tar.bz2

# How about PSL...
#
# N.B. this is a SKETCH and the PSL experts may wish to review it.
# At present it imagines that the pslbuild directory will only have one
# sub-directory and that the sequence "make; make clean" in that will
# do a fully tidy build. It also just pops what results in a .tar.bz2 file
# as the result...

./configure --with-psl
pushd pslbuild/*
  make clean
  make
  tar cfj ../releases/pslreduce-$da.tar.bz2 *
popd

# At present I only try to cross-build Windows binaries if I am on
# a 64-bit Ubuntu system. There is probably no reason why one should
# not use Fedora, SuSE etc but I am listing the version I have tested!

case $h in
x86_64*ubuntu*)
  echo Will also build various other versions...
  ;;
i686-pc-windows)
# If I had configured on a Windows machine and if x86_64 compilers were
# available then that system should also have been configured - so here I
# build it.
  if test -d cslbuild/x86_64-pc-windows
  then
    pushd cslbuild/x86_64-pc-windows
      make clean
      rm -rf lib include bin
      make
      cd csl
# Get rid of any previous archive
      rm -f reduce*zip reduce*bz2
      make save
      if test -f reduce*zip
      then
        mv reduce*zip ../../../releases
      else
        mv reduce*bz2 ../../../releases
      fi
    popd
  fi
  ;;
*)
  echo Merely building a local release
  exit 0
  ;;
esac

echo Build 32-bit Linux variant

./configure --with-csl --with-m32
pushd cslbuild/$h-m32
  make clean
  rm -rf lib include bin
  make
  cd csl
# Get rid of any previous archive
  rm -f reduce-x86_64*-m32*bz2
  make save
# Now I rename the archive to make it appear to have been built on
# a regular 32-bit Linux not on a 64-bit one using multilib facilities
  n=reduce-x86_64*-m32*bz2
  nn=`echo $n | sed -e 's/x86_64/i686/; s/-m32//'`
  mv $n $nn
  mv reduce-i686*bz2 ../../../releases
popd

if which i686-w64-mingw32-gcc
then
  echo build 32-bit windows variant

  ./configure --with-csl --host=i686-w64-mingw32
  pushd cslbuild/i686-pc-windows
    make clean
    rm -rf lib include bin
    make
    cd csl
# Get rid of any previous archive
    rm -f reduce*zip
    make save
    mv reduce*zip ../../../releases
  popd
fi

if which x86_64-w64-mingw32-gcc
then
  echo build 64-bit windows variant

  ./configure --with-csl --host=x86_64-w64-mingw32
  pushd cslbuild/x86_64-w64-windows
    make clean
    rm -rf lib include bin
    make
    cd csl
# Get rid of any previous archive
    rm -f reduce*zip
    make save
    mv reduce*zip ../../../releases
  popd
fi

echo All done
