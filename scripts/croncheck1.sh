#! /bin/bash -v

# WINDOWS_VM is the name of a virtual box VM that will run Windows
WINDOWS_VM=windows
# WINDOWS_USER can be an empty string if the user-name that will be
# used on the VM matches that used on the host. Otherwise it can be set
# as in WINDOWS_USER="acn1@" with a name and a "@" sign and that will be used
# with ssh to access the virtual machine
WINDOWS_USER=
# WINDOWS_PORT is the port number that has been forwarded to the VM.
WINDOWS_PORT=2201

LINUX_VM=linux
LINUX_USER=
LINUX_PORT=2202

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

# I need the following so I grab the correct version of svn, as installed via
# macports! An in general to be certain that I can use macports things.
export PATH="/opt/local/bin:/opt/local/sbin:$PATH"

mkdir snapshots

# Ensure that my copy of Reduce is fully up to date.
cd reduce-distribution
svn -R revert .
svn update

# Build a snapshot for this machine - a Macintosh
pushd macbuild
make
cp Redu*.dmg $HOME/snapshots
popd

# Next launch a VM to regenerate a Linux distribution
vboxmanage startvm $LINUX_VM -type headless

# I will unpack the Reduce files while waiting for the machine to start,
# and unpacking on the Mac will be faster and safer than doing so in theVM.

pushd debianbuild
make clean
make C.stamp
popd

# Wait until virtualbox is running. I do this by sending ssh requests
# repeatedly until ons is responded to. I will try up to 20 at 30-second
# intervals, so I am requiring the VM to have stablised within 10 minutes.

for x in `seq 1 20`
do
  hello=`ssh -p $LINUX_PORT ${LINUX_USER}localhost printf "hello"`
  if test "x$hello" = "xhello"
  then
    break
  fi
  sleep 30
done

# Note that for the shared folder to be mountable, even when labelled as
# automount by virtualbox, the account that you log in to on the Linux
# client must be a member of the vboxsf group. For the "sudo /sbin/shutdown"
# command to work that user also has to be marked as one where they can
# use "sudo" without a need to quote a password. That will involve a line
# like
#   <username> ALL=(ALL) NOPASSWD:ALL
# in /etc/sudoers
ssh -p $LINUX_PORT ${LINUX_USER}localhost \( \
  cd /media/sf_reduce-distribution/debianbuild \; \
  time make \; \
  sudo /sbin/shutdown -h now \)

cp debianbuild/*.deb debianbuild/*.rpm $HOME/snapshots


# I will fill this in in a while...

# Start a Windows build. This will take a long time!
vboxmanage startvm $WINDOWS_MC -type headless

# Unpack files on the host not in the VM for speed and to avoid trouble
# with symbolic links.

pushd winbuild
make clean
make C.stamp
popd

# Wait until virtualbox is running. I do this by sending ssh requests
# repeatedly until ons is responded to. I will try up to 40 at 30-second
# intervals, so I am requiring the VM to have stablised within 20 minutes.
# The long delay I allow is to cope with the possibility that Widdows might
# take several ages doing an automatic installation of updates.

for x in `seq 1 40`
do
  hello=`ssh -p $LINUX_PORT ${LINUX_USER}localhost printf "hello"`
  if test "x$hello" = "xhello"
  then
    break
  fi
  sleep 30
done

ssh -p $WINDOWS_PORT ${WINDOWS_USER}localhost \( \
  cd /cygdrive/e/winbuild \; \
  time make \; \
  sleep 60 \; \
  shutdown /p \)

cp winbuild/Output/Reduce*.exe $HOME/snapshots

popd
printf "Can now copy these files to sourceforge:\n"

ls -l snapshots

exit 0
