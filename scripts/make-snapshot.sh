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

# If I touch the output file here at the start then any accidental attempt to
# restart the build will detect the presence of the file and give up.
touch $SYS-${today}.stamp

# Remove previous stamp files.
for x in $SYS-*.stamp
do
  if test $x != $SYS-${today}.stamp
  then
    rm $x
  fi
done

# Ensure that the version to be used is up to date. Revert first so no
# possibility of conflicts.
cd $RED
svn -R revert .
svn update

# Move to where the building happens and create files for distribution
cd $BUILD
export TODAY="${today}"
make clean
make

if test "$SYS" = "windows"
then
# I want to badge the setup file with today's date.
  mv $OUTDIR/Reduce-Setup.exe $OUTDIR/$OUTFILES
fi

if test "$SYS" = "mac"
then
# I want to badge the setup file with today's date.
  mv $OUTDIR/Reduce-snapshot.dmg $OUTDIR/$OUTFILES
fi

# Copy generated files to the remote machine where they are wanted
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

cd $HERE
# I will run the Windows and Linux builds within virtual machines hosted
# on a Macintosh. It licensing permitted me to use OSX in a virtual machine
# on a non-Mac host I would have used something else as my main host, but
# as things are I need to build the Mac version on a real Macintosh. For
# the builds in a virtual environment I shut down the VM after a build.
# Note that because I only build once per day if I were to start the VM up
# again later on the same day it would not shut itself down and that gives
# me scope to develop and debug. For the shutdown command to work my user
# needs to have "sudo" priviledge without needing a password. In my case
# this is all set up in /etc/sudoers with a line that reads:
#   acn1 ALL=(ALL) NOPASSWD:ALL
#
# The on Linux I make the machine auto-logon to myself and then have an
# entry in "startup programs" that launches this script. For Windows I
# again set up autologin. I use windown-key+R/shell:startup and create
# a shortcut to c:\cywgin\Cygwin.bat as a startup item. amd then I can
# use .bashrc to start this script.
#
# On the Mac I can use a command like "vboxmanage startvm autobuilder" 
# to start the virtual machines.

# The FIRST time on any day that this machine is booted it will spend
# between 5 and 45 minutes building a Reduce snapshot and it will then
# power down. On subsequent boots on the same day it will start up normally
# so that maintenance is possible. Well on a Macintosh I do not shut down.

case $SYS in
mac)
  ;;
windows)
  sleep 60
  shutdown /p
  ;;
*)
# pause before shutting down in the hope that doing so gives "script"
# time to record even the tail of the transcript
  sleep 60
  sudo /sbin/shutdown -h now
  ;;
esac

# end of make-snapshot.sh
