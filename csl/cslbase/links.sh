#! /bin/bash

# Under msys2 there is rather uncertin support for symbolic links,
# and so I provide myself with this script which sets the ones I use up.
# It could be that either subversion or editing thinge will have messed
# their status up! Running this in the cslbase directory puts them back...
# but it needs "extern MSYS=winsymlinks:nativestrict" to select the
# msys option that supports symlinks at all rather than making "ln -s"
# make a deep copy.

makelink() {
# echo $1  =>  $2
  pushd $2 > /dev/null
  rm -f $1
  ln -s ../../cslbase/$1 $1
  ls -l $1
  popd > /dev/null
}

makelink termed.h   ../fox/include
makelink fwin.h     ../fox/include
makelink log.h      ../fox/include
makelink fwin.cpp   ../fox/src
makelink termed.cpp ../fox/src
