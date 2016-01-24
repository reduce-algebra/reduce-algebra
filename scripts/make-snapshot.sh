#! /bin/bash

# This script is intended to be used to create a Reduce snapshot and copy
# it to a know location. It can be run under Windows, Linux or on a Mac
# and tries to do the "right" thing in each case.

# When you look at this you will find that there are a number of
# configuration variables set up at the top that related to where the
# generated smapshots should end and and where on your disc you have
# places the Reduce files. These will obviously need customising for you
# individual circumstances!

# I put this in my home directory and arrange that it gets invoked from time
# to time. See comments lower down about its use in virtual machines.

HERE=`pwd`
today=`date +%Y%m%d`

# The ip address or name of the machine where the generated archive is to go
DESTMC=192.168.1.110
# The user to use when copying
DESTUSER=acn1
# The directory to place snapshots in
DESTDIR=snapshots
# NOTE that .ssh authorized-keys need to have been set up so that the use
# of "scp" here can happen without any need to quote a password.

# SYS identifies the platform.
# RED is the full source tree, fetched using subversion so that "svn update"
#  will bring it up to date. Note that it should be a read-only copy so that
#  when you go "svn update" you do not need to quote a password - or perhaps
#  public key ssh certificates could cover that issue... Note that running
#  this will perform an "svn update" here.
# BUILD is the location within a full Reduce source tree where scripts
#  to make a release for $SYS live.
# OUTDIR is the directory within $BUILD where release packages are made.
# OUTFILES is a file or list of the files in OUTDIR that are wanted.

RED=""
for x in $HOME/reduce-distribution \
         $HOME/reduce-algebra \
         /y/projects/reduce-distribution
do
  if test -d $x
  then
    RED="$x"
    break
  fi
done
if test "x$RED" = "x"
then
  printf "Reduce sources not found\n"
  exit 1
fi
printf "Found Reduce at %s\n" $RED

case `uname -a`
in
CYG*)
  SYS=windows
  BUILD=winbuild
  OUTDIR=Output
  OUTFILES="Reduce-Setup-${today}.exe"
  ;;
Darwin*)
  SYS=mac
  BUILD=macbuild
  OUTDIR=.
  OUTFILES="Reduce-${today}.dmg"
  ;;
*)
  SYS=linux
  BUILD=debianbuild
  OUTDIR=.
  OUTFILES="reduce-common_${today}_all.deb \
            reduce-csl_${today}_amd64.deb \
            reduce-psl_${today}_amd64.deb \
            reduce-addons_${today}_amd64.deb \
            reduce-common-${today}-1.noarch.rpm \
            reduce-csl-${today}-1.x86_64.rpm \
            reduce-psl-${today}-1.x86_64.rpm \
            reduce-addons-${today}-1.x86_64.rpm"
  ;;
esac

# From here down the code ought to be stable.

# The date of a snapshot is recorded as yyyymmdd - ie 4 digits of year, two
# of month and two for the day within the month.

if test -f $SYS-${today}.stamp
then
# If this script has already run today then I will not use it a second time.
  printf "Snapshot $SYS-${today}.stamp already exists\n"
# Copy generated files to the remote machine where they are wanted even if
# this is redundant.
  cd $RED
  cd $BUILD
  cd $OUTDIR
  case `uname -a`
  in
  Darwin*)
    cp $OUTFILES $HOME/$DESTDIR
    ;;
  *)
    scp $OUTFILES $DESTUSER@$DESTMC:$DESTDIR
    ;;
  esac
  printf "Snapshot copied to snapshots directory\n"
  exit 0
fi

# The log file I accumulate here is only collected when the build actually
# needs to do serious amounts of work. Note that the "script" commands on
# Macintosh/BSD and Linux/Cygwin differ. Also that some notes suggest that
# the use of "script" in a non-interactive context could potentially cause
# trouble... in ways I do not fully understand!

if test "$SYS" = "mac"
then
  script $HOME/make-snapshot.log $HERE/make-snapshot1.sh
else
  script -c $HERE/make-snapshot1.sh $HOME/make-snapshot.log
fi

exit 0

# end of make-snapshot.sh
