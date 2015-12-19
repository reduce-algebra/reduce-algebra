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

# The ip address or name of the machine where the generated archive is to go
DESTMC=192.168.1.119
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
# OUTFILES is a list of the files in OUTDIR that are wanted.

case `uname -a`
in
CYG*)
  SYS=windows
# Here I illustrate a way of coping with having this script on two machines
# where the Reduce sources are kept in different locations...
  RED=/home/acn1/reduce-algebra
  if ! test -d $RED
  then
    RED=/y/projects/reduce-algebra/trunk
    if ! test -d $RED
    then
      printf "Unable to find Reduce files!\n"
      exit 1
    fi
  fi
  printf "Found Reduce at %s\n" $RED
  BUILD=winbuild
  OUTDIR=Output
  OUTFILES="Reduce.Setup.sh"
  ;;
Darwin*)
  SYS=mac
# This is at present work in progress!
  RED=/Users/acn1/reduce-algebra
  BUILD=macbuild
  OUTDIR=.
  ;;
*)
  SYS=linux
  RED=/home/acn1/reduce-algebra
  BUILD=debianbuild
  OUTDIR=.
  ;;
esac

# From here down the code ought to be stable.

# The date of a snapshot is recorded as yyyymmdd - ie 4 digits of year, two
# of month and two for the day within the month.

today=`date +%Y%m%d`
if test -f $SYS-$today.tgz
then
# If this script has already run today then I will not use it a second time.
# I leave (short form) logs in /tmp.
  printf "Snapshot $SYS-$today.tgz already exists\n" > /tmp/$SYS-already.log
  exit 0
fi

# If I touch the output file here at the start then any accidental attempt to
# restart the build will detect the presence of the file and give up.
touch $SYS-$today.tgz

# Ensure that the version to be used is up to date
cd $RED
svn update

# Move to where the building happens and create files for distribution
cd $BUILD
make > /tmp/$SYS.log

# Copy generated files into the directory that the script was originally called from.
cd $OUTDIR
SAVE="tar cvfz $HERE/$SYS-$today.tgz $OUTFILES"
eval "$SAVE" >> /tmp/$SYS.log

cd $HERE
# Remove previous snapshots.
for x in $SYS-*.tgz
do
  if test $x != $SYS-$today.tgz
  then
    rm $x
  fi
done

# use scp to copy the archive to a central machine. 
ls -l $SYS-$today.tgz >> /tmp/$SYS.log
scp $SYS-$today.tgz $DESTUSER@$DESTMC:$DESTDIR
printf "$SYS-$today.tgz copied to snapshots directory\n" >> /tmp/$SYS.log

# I will run the Widnows and Linux builds within virtual machines hosted
# on a Macintosh. It licensing permitted me to use OSX in a virtual machine
# on a non-Mac host I would have used something else as my main host, but
# as things are I need to build the Mac version on a real Macintosh. For
# the builds in a virtual environment I shut down the VM after a build.
# Note that because I only build once per day if I were to start the VM up
# again lare on the same day it would not shut itself down and that gives
# me scope to develop and debug. For the shutdown command to work my user
# needs to have "sudo" priviledge without needing a password. In my case
# this is a line in /etc/sudoers
#   acn1 ALL=(ALL) NOPASSWD:ALL
#
# The om Linux I make the machine auto-logon to myself and then have an
# entry in "startup programs" that launches this script. For Windows I
# again set up autologin. I use windown-key+R/shell:startup and create
# a shortcut to c:\cywgin\Cygwin.bat as a startup item. amd then I can
# use .bashrc to start this script.
#
# On the Mac I can use a command like "vboxmanage startvm autobuilder" 

# The FIRST time on any day that this machine is booted it will spend
# between 5 and 45 minutes building a Reduce snapshot and it will then
# power down. On subsequent boots on the same day it will start up normally
# so that maintenance is possible. Well on a Macintosh I do not shut down.

case $SYS in
mac)
  ;;
windows)
  shutdown /p
  ;;
*)
  sudo /sbin/shutdown -h now
  ;;
esac

# end of make-snapshot.sh
