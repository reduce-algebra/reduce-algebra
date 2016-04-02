#! /bin/bash -v

# WINDOWS_VM is the name of a virtual box VM that will run Windows.
WINDOWS_VM=windows
# WINDOWS_USER can be an empty string if the user-name that will be
# used on the VM matches that used on the host. Otherwise it can be set
# as in WINDOWS_USER="acn1" with a name that will be used with ssh to
# access the virtual machine. If none is given then the current user
# (as obtained by the "whoami" command) will be used, and in many cases
# I hope that this default will be good enough!
WINDOWS_USER=
# WINDOWS_PORT is the port number that has been forwarded to the VM.
# This needs to be set up when networking is set up for the virtualbox
# VM. It should use NAT networking and there is an "advanced" option for
# port forwarding that should forward this host port to port 22 on the
# guest.
WINDOWS_PORT=2201

# "Linux" is a 64-bit Linux machine and the only special things it should
# need to have set up are
# (a) virualbox should forward port 2202 to its port 22 to allow ssh access
#     from the host.
# (b) .ssh/authorized_keys of the user involved should contain the public
#     keys of the user on the host (which should not require any extra
#     pass-phrase). With (a) and (b) in place it should be possible to go
#           vboxmanage startvm linux -type headless
#           ssh -p 2202 username@localhost <some command>
# (c) the user of the vm should have an entry in /etc/sudoers that reads
#           username ALL=(ALL) NOPASSWD: ALL
#     and the intent of this is so that it is possible to go
#           /sbin/shutdown -h now
#     within the VM without needing to quote a password.
# Points (b) and (c) significantly compromise the security of the VM, but
# it is only a VIRTUAL machine and the host computer has extreme access to
# it already, so extra security within it is not that amazingly important.
# Furthermore it is expected that the only use of it will be for running
# the tasks that generate Reduce snapshots. It will not be used for web access
# or email or other potentially risky things, and it will have a fairly
# minimal number of packages installed.

LINUX_VM=linux
LINUX_USER=
LINUX_PORT=2202

LINUX32_VM=linux32
LINUX32_USER=
LINUX32_PORT=2203

# I *HOPE* that while the above entries may need customising or


if test "x$WINDOWS_USER" = "x"
then
  WINDOWS_USER=`whoami`
fi

if test "x$LINUX_USER" = "x"
then
  LINUX_USER=`whoami`
fi

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
pushd reduce-distribution
svn -R revert .
svn update

# Unpack as for a local build
pushd macbuild
rm -rf C
make clean
make C.stamp
popd

# Next launch a VM to regenerate a 64-bit Linux distribution

vboxmanage startvm $LINUX_VM -type headless

# Wait until virtualbox is running. I do this by sending ssh requests
# repeatedly until ons is responded to. I will try up to 20 at 30-second
# intervals, so I am requiring the VM to have stablised within 10 minutes.

for x in `seq 1 20`
do
  hello=`ssh -p $LINUX_PORT $LINUX_USER@localhost printf "hello"`
  if test "x$hello" = "xhello"
  then
    break
  fi
  printf "Sleeping to allow Linux VM to start up...\n"
  sleep 30
done

# First I will clear away any previous files on the VM and copy across
# files from the host.

ssh -p $LINUX_PORT $LINUX_USER@localhost rm -rf debianbuild
scp -r -P $LINUX_PORT debianbuild $LINUX_USER@localhost:.

# This next line copies all the files across using tar to pack and unpack so
# that there is only a single ssh transaction. Whether this is really better
# or worse than using "scp -r" is not clear to me. I use only basic facilities
# of "tar" in part because the default Mac one is a BSD tar not a GNU version.

pushd macbuild
tar cfz - C | \
  ssh -p $LINUX_PORT $LINUX_USER@localhost \
    \( cd debianbuild \; tar xfz - \)
popd

# Create the file that marks the source files as present and up to date

ssh -p $LINUX_PORT $LINUX_USER@localhost touch debianbuild/C.stamp

# Now do the main build of all the Linux binaries and packages.

ssh -p $LINUX_PORT $LINUX_USER@localhost \( \
  cd debianbuild \; \
  pushd C \; ./autogen.sh \; popd \; \
  time make \)

# Recover the built files.
scp -P $LINUX_PORT $LINUX_USER@localhost:debianbuild/\*.deb $HOME/snapshots
scp -P $LINUX_PORT $LINUX_USER@localhost:debianbuild/\*.rpm $HOME/snapshots

# Shut down the guest. I do this by issing a command within the VM rather
# than by an externally forced power-down since I hope that will count
# as kinder. But done this way means that the account used on the VM has
# to have "sudo" rights without neeting to quote a password. I take the
# opportunity to install any updates that there might be to the Linux
# system. By doing that at the end of my job I will power down after
# installing the updates so that the next boot will have a chance to see
# them fully in place.

ssh -p $LINUX_PORT $LINUX_USER@localhost \
  \( sudo apt-get update \; \
     sudo apt-get upgrade \; \
     sudo apt-get dist-upgrade \; \
     sudo /sbin/shutdown -h now \)

# Launch a VM to regenerate a 32-bit Linux distribution. This recipe
# is the same as that use for a 64-bit Linux.

vboxmanage startvm $LINUX32_VM -type headless

for x in `seq 1 20`
do
  hello=`ssh -p $LINUX32_PORT $LINUX32_USER@localhost printf "hello"`
  if test "x$hello" = "xhello"
  then
    break
  fi
  printf "Sleeping to allow Linux VM to start up...\n"
  sleep 30
done

ssh -p $LINUX32_PORT $LINUX32_USER@localhost rm -rf debianbuild
scp -r -P $LINUX32_PORT debianbuild $LINUX32_USER@localhost:.

pushd macbuild
tar cfz - C | \
  ssh -p $LINUX32_PORT $LINUX32_USER@localhost \
    \( cd debianbuild \; tar xfz - \)
popd

ssh -p $LINUX32_PORT $LINUX32_USER@localhost touch debianbuild/C.stamp

ssh -p $LINUX32_PORT $LINUX32_USER@localhost \( \
  cd debianbuild \; \
  pushd C \; ./autogen.sh \; popd \; \
  time make \)

scp -P $LINUX32_PORT $LINUX32_USER@localhost:debianbuild/\*.deb $HOME/snapshots
scp -P $LINUX32_PORT $LINUX32_USER@localhost:debianbuild/\*.rpm $HOME/snapshots

ssh -p $LINUX32_PORT $LINUX32_USER@localhost sudo \
  \( sudo apt-get update \; \
     sudo apt-get upgrade \; \
     sudo apt-get dist-upgrade \; \
     sudo /sbin/shutdown -h now \)



# Start a Windows build. This can take a long time if Windows has
# concluded that it needs to install a large number of updates.

vboxmanage startvm $WINDOWS_VM -type headless

# Wait until virtualbox is running. I do this by sending ssh requests
# repeatedly until one is responded to. I will try up to 40 at 30-second
# intervals, so I am requiring the VM to have stablised within 20 minutes.
# The long delay I allow is to cope with the possibility that Widdows might
# take several ages doing an automatic installation of updates.

for x in `seq 1 40`
do
  hello=`ssh -p $WINDOWS_PORT $WINDOWS_USER@localhost printf "hello"`
  if test "x$hello" = "xhello"
  then
    break
  fi
  printf "Sleeping to allow Windows VM to start up...\n"
  sleep 30
done

# Now in a way that is just as was done for Linux I will put the
# necessary files on the Windows guest VM

ssh -p $WINDOWS_PORT $WINDOWS_USER@localhost rm -rf winbuild
scp -r -P $WINDOWS_PORT winbuild $WINDOWS_USER@localhost:.
pushd macbuild
tar cfz - C | \
  ssh -p $WINDOWS_PORT $WINDOWS_USER@localhost \
    \( cd winbuild \; tar xfz - \)
popd
ssh -p $WINDOWS_PORT $WINDOWS_USER@localhost touch winbuild/C.stamp

# That has now established the winbuild directory...

# Now do the main build of all the Windows binaries and packages.

# Note that the following step builds 6 copies of Reduce and takes
# several hours to complete. The versions built are
#   csl-win32, csl-win64, csl-cygwin32, csl-cygwin64, psl-win32 and psl-win64

# I do not fully understand why the setting of PATH here is vital, but it
# seems to be. Without it x86_64-w64-mingw32-gcc fails in a way that seems to
# indicate that it compiles the code in 64-bit mode then tries to assemble
# it using a 32-bit assembler (which then onbiously chokes on the 64-bit
# assembly syntax passed to it).

ssh -p $WINDOWS_PORT $WINDOWS_USER@localhost \( \
  cd winbuild \; \
  export PATH=/usr/local/bin:/usr/bin:\$PATH \; \
  pushd C \; ./autogen.sh \; popd \; \
  time make \)

# Recover the built files.
scp -P $WINDOWS_PORT $WINDOWS_USER@localhost:winbuild/\*.exe $HOME/snapshots

# Shut down the guest. I do this by issing a command within the VM rather
# than by an externally forced power-down since I hope that will count
# as kinder. But done this way means that the account used on the VM has
# to have "sudo" rights without neeting to quote a password.

ssh -p $WINDOWS_PORT $WINDOWS_USER@localhost shutdown /p


# Now make the Mac version. I wanted the archive unpacked early since that
# is what I copy for use on the other platforms, and doing things that way
# means I know that all systems build from exactly the same version of
# the sources.

pushd macbuild
pushd C ; ./autogen.sh ; popd
make
cp Reduce*.dmg $HOME/snapshots/Reduce-snapshot_`date "+%Y%m%d"`.dmg
popd

popd
printf "Can now copy these files to sourceforge:\n"

ls -l snapshots

exit 0
