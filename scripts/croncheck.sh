#! /bin/bash

# This is a script I keep in my home directory on my Mac and get called every
# half hour or so. It  is thus not self-standning and not for use by everybody
# but by putting it here I keep a safe copy for me and make it possible for
# others to comment, enhance and improve things - or replace this totally.
#
# This does not use proper locks to protect against concurrent use, nor does
# it do proper error checking on the sub-process it uses!


req=`cat croncheck.dat 2>/dev/null`
now=`date +%s`
if test "x$req" = "x"
then
  req=0
fi
printf "Time %s run croncheck task\n" "`date`" >> croncheck.log

# If either the last set of snapshots are less than (about) a week old
# or if it is 10pm or later I will not do anything just now. The limitation
# on late-night processing is so that the creation of snapshots will
# tend not to happen over the time when the clock moves from one day to
# the next. And perhaps because there seems more of a risk that I will switch
# my computer off as the evening wears on.
if test $now -lt $req || \
   test `date %H` -gt 21
then
  printf "Nothing needs doing right now\n";
  exit 0
fi

# Arrange that the next attempt to build will not happen for another week.
next=$(($now + 600000))
printf "$next" > croncheck.dat

# Keep a backup of the previous snapshots and start with an empty
# directory for the new ones I am about to create.

if test -d old-snapshots
then
  rm -rf old-snapshots
fi

if test -d snapshots
then
  mv snapshots old-snapshots
fi

mkdir snapshots

# First build a snapshot for this machine - a Macintosh
script make-mac-snapshot ./make-snapshot.sh

# Next launch a VM to regenerate a Linux distribution
vboxmanage startvm autobuilder

# Give the Linux build 10 minute to complete before moving on
sleep 600

# Start a Windows build. This will take a long time!
vboxmanage startvm w-10

# in due course everything should end up in the snapshots directory.

# I wait for the Windows version to become present. Note that when the
# test here first succeeds it will purely mean that the "scp" to here
# has started, so I will wait a while after thet before believing that
# the file is really present.
# Note that if any aspect of building fails or is badly delayed that this
# script may behave badly.

while ! test -f snapshots/Reduce-Setup-*.exe
do
  sleep 120
done
sleep 60

printf "Can now copy these files to sourceforge:\n"
ls -l snapshots

exit 0
