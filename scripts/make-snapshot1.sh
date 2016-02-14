#! /bin/sh

# make-snapshot1.sh - the second part of the snapshot-builder

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
  cp $OUTFILES $HOME/$DESTINATIONDIR
  ;;
*)
  scp $OUTFILES $DESTINATIONUSER@$DESTINATIONMC:$DESTINATIONDIR
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

# end of make-snapshot1.sh
