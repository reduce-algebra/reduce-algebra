#! /bin/bash -v

# This should build Windows, Linux64. Linux32 and Macintosh packages for
# Reduce. If it is given an argument "--noupdate" it will not update the
# local tree. This option will be very useful during development and testing!

noupdate="no"
if test "x$1" = "x--noupdate"
then
  noupdate="yes"
  printf "\n+++ --noupdate option set\n"
fi

# My intent now is that this script can be launched from anywhere, but it
# lives within the scripts directory of a checkout of Reduce and it will
# end up placing snapshots in a snapshots directory of that copy of Reduce.

current=`pwd -P`
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`cd \`dirname "$here"\` ; pwd -P`

printf "current directory=$current\n"
printf "script=$here/croncheck1.sh\n"

# I will have the reduce working copy as my current directory for the
# bulk of the time I run this script.

pushd $here/..

export today=`date +"%Y%m%d"`

# Now I set up some (potentially) setup-specific configuration data - the
# names and ports used by the virtual machines I will activate.

# WINDOWS_VM is the name of a virtual box VM that will run Windows.
WINDOWS_VM=REDUCE-pkg-factory-Windows
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
#           $TIMEOUT vboxmanage startvm linux -type headless
#           ssh -p 2202 username@localhost <some command>
# (c) the user of the vm should have an entry in /etc/sudoers that reads
#           %sudo ALL=(ALL) NOPASSWD: ALL
#     (and the user a member of the sudo group).
#     The intent of this is so that it is possible to go
#           sudo apt-get ...
#           sudo /sbin/shutdown -h now
#     within the VM without needing to quote a password.
# Points (b) and (c) significantly compromise the security of the VM, but
# it is only a VIRTUAL machine and the host computer has extreme access to
# it already, so extra security within it is not that amazingly important.
# Furthermore it is expected that the only use of it will be for running
# the tasks that generate Reduce snapshots. It will not be used for web access
# or email or other potentially risky things, and it will have a fairly
# minimal number of packages installed.

LINUX_VM=REDUCE-pkg-factory-Ubuntu
LINUX_USER=
LINUX_PORT=2202

# LINUX32 is much like LINUX but is a 32-bit version on port 2203.

LINUX32_VM=REDUCE-pkg-factory-Ubuntu32
LINUX32_USER=
LINUX32_PORT=2203

# I *HOPE* that while the above entries may need customising or adjusting that
# the rest of this script can work unchanged.




# If the script above had not indicated what account to use on the
# virtual machines assume it is the same as the one in use on the host
# machine.

CURRENT_USER=`whoami`

if test "x$WINDOWS_USER" = "x"
then
  WINDOWS_USER=$CURRENT_USER
fi

if test "x$LINUX_USER" = "x"
then
  LINUX_USER=$CURRENT_USER
fi

if test "x$LINUX32_USER" = "x"
then
  LINUX32_USER=$CURRENT_USER
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

mkdir snapshots
mkdir snapshots/linux-rpm
mkdir snapshots/linux-deb
mkdir snapshots/linux-tar

# I need the following so I grab the correct version of svn, as installed via
# macports! And in general to be certain that I can use macports things. The
# small number of commands I have obeyed so far do not depend on this.

export PATH="/opt/local/bin:/opt/local/sbin:$PATH"

# If the command "timeout" has been installed (and i hope it has!) then
# I will limit the time spent in any use of ssh or scp to 10 minutes. That
# time limit should be hugely longer than can be really needed, but is there
# because otherwise there are circumstances when the script can get stalled
# on an indefinite basis. Indeed just to be cautios I will apply timeouts to
# a range of other command used here... for instance for the remote builds
# on virtual machines I will allow 8 hours!

if which timeout > /dev/null 2>/dev/null
then
# Some documentation for "Timeout" suggests can use time specifications
# such as 10m and 8h here, but my experience seems to be that I need to quote
# a time period in seconds.
  TIMEOUT="timeout 600"
  LONGTIMEOUT="timeout 28800"
else
  TIMEOUT=""
  LONGTIMEOUT=""
fi

# Ensure that my copy of Reduce is fully up to date. I will mention here
# that at one stage we have the Reduce files on a drive that had been
# formatted as a variant on FAT32, and in that case "svn revert" always
# reverted (almost?) everything. Things behaved a lot better when we placed
# the Reduce tree on a modern native file-system for the host.

# The --noupdate option is useful if you have a new experimental version of
# this script and wish to try it. Otherwise it will be put back to its
# canonical state when you try to use it!

if test "$noupdate" = "no"
then
  $TIMEOUT svn -R revert .
  $TIMEOUT svn update
fi

# Unpack as for a local build. This will create the macbuild/C directory
# as a tidy copy of the current revision. I try to do this operation
# just once. It will do "svn export" to create a directory macbuild/C.

pushd macbuild
make clean
$TIMEOUT make C.stamp
popd

# Next launch a VM to regenerate a 64-bit Linux distribution

$TIMEOUT vboxmanage startvm $LINUX_VM -type headless

# Wait until virtualbox is running. I do this by sending ssh requests
# repeatedly until ons is responded to. I will try up to 20 at 30-second
# intervals, so I am requiring the VM to have stablised within 10 minutes.
# But note that this timeout is not very reliably enforced. For instance
# if you have not used ssh to contact the VM before then ssh will pause
# and ask you to confirm that you believe the machine you are contacting
# is the one you intend, and that does not seem to time-out ever, so that
# (at least) can cause this script to hang without limit.

sleep 5
for x in `seq 1 20`
do
  hello=`$TIMEOUT ssh -p $LINUX_PORT $LINUX_USER@localhost printf "hello"`
  if test "x$hello" = "xhello"
  then
    break
  fi
  printf "Sleeping to allow Linux VM to start up...\n"
  sleep 30
done

# First I will clear away any previous files on the VM and copy across
# files from the host.

$TIMEOUT ssh -p $LINUX_PORT $LINUX_USER@localhost rm -rf debianbuild
$TIMEOUT scp -r -P $LINUX_PORT debianbuild $LINUX_USER@localhost:.

# This next line copies all the files across using tar to pack and unpack so
# that there is only a single ssh transaction. Whether this is really better
# or worse than using "scp -r" is not clear to me. I use only basic facilities
# of "tar" in part because the default Mac one is a BSD tar not a GNU version.

pushd macbuild
tar cfz - C | \
  $TIMEOUT ssh -p $LINUX_PORT $LINUX_USER@localhost \
    \( cd debianbuild \; tar xfz - --warning=no-unknown-keyword \)
popd

# Create the file that marks the source files as present and up to date

$TIMEOUT ssh -p $LINUX_PORT $LINUX_USER@localhost touch debianbuild/C.stamp

# Now do the main build of all the Linux binaries and packages.

$LONGTIMEOUT ssh -p $LINUX_PORT $LINUX_USER@localhost \( \
  cd debianbuild \; \
  pushd C \; ./autogen.sh \; popd \; \
  time make \)

# Recover the built files.
$TIMEOUT scp -P $LINUX_PORT $LINUX_USER@localhost:debianbuild/\*.deb $here/../snapshots/linux-deb
$TIMEOUT scp -P $LINUX_PORT $LINUX_USER@localhost:debianbuild/\*.rpm $here/../snapshots/linux-rpm
$TIMEOUT scp -P $LINUX_PORT $LINUX_USER@localhost:debianbuild/\*.tgz $here/../snapshots/linux-tar
$TIMEOUT scp -P $LINUX_PORT $LINUX_USER@localhost:debianbuild/\*.tar.bz2 $here/../snapshots/linux-tar

# Shut down the guest. I do this by issing a command within the VM rather
# than by an externally forced power-down since I hope that will count
# as kinder. But done this way means that the account used on the VM has
# to have "sudo" rights without neeting to quote a password. I take the
# opportunity to install any updates that there might be to the Linux
# system. By doing that at the end of my job I will power down after
# installing the updates so that the next boot will have a chance to see
# them fully in place.

$TIMEOUT ssh -p $LINUX_PORT $LINUX_USER@localhost \
  \( sudo apt-get -y update \; \
     sudo apt-get -y upgrade \; \
     sudo apt-get -y dist-upgrade \; \
     sudo /sbin/shutdown -h now \)

# Launch a VM to regenerate a 32-bit Linux distribution. This recipe
# is the same as that use for a 64-bit Linux.

$TIMEOUT vboxmanage startvm $LINUX32_VM -type headless

sleep 5
for x in `seq 1 20`
do
  hello=`$TIMEOUT ssh -p $LINUX32_PORT $LINUX32_USER@localhost printf "hello"`
  if test "x$hello" = "xhello"
  then
    break
  fi
  printf "Sleeping to allow Linux VM to start up...\n"
  sleep 30
done

$TIMEOUT ssh -p $LINUX32_PORT $LINUX32_USER@localhost rm -rf debianbuild
$TIMEOUT scp -r -P $LINUX32_PORT debianbuild $LINUX32_USER@localhost:.

pushd macbuild
tar cfz - C | \
  $TIMEOUT ssh -p $LINUX32_PORT $LINUX32_USER@localhost \
    \( cd debianbuild \; tar xfz - --warning=no-unknown-keyword \)
popd

$TIMEOUT ssh -p $LINUX32_PORT $LINUX32_USER@localhost touch debianbuild/C.stamp

$LONGTIMEOUT ssh -p $LINUX32_PORT $LINUX32_USER@localhost \( \
  cd debianbuild \; \
  pushd C \; ./autogen.sh \; popd \; \
  time make \)

$TIMEOUT scp -P $LINUX32_PORT $LINUX32_USER@localhost:debianbuild/\*.deb $here/../snapshots/linux-deb
$TIMEOUT scp -P $LINUX32_PORT $LINUX32_USER@localhost:debianbuild/\*.rpm $here/../snapshots/linux-rpm
$TIMEOUT scp -P $LINUX32_PORT $LINUX32_USER@localhost:debianbuild/\*.tgz $here/../snapshots/linux-tar
$TIMEOUT scp -P $LINUX32_PORT $LINUX32_USER@localhost:debianbuild/\*.tar.bz2 $here/../snapshots/linux-tar

$TIMEOUT ssh -p $LINUX32_PORT $LINUX32_USER@localhost \
  \( sudo apt-get -y update \; \
     sudo apt-get -y upgrade \; \
     sudo apt-get -y dist-upgrade \; \
     sudo /sbin/shutdown -h now \)



# Start a Windows build. This can take some time if Windows has
# concluded that it needs to complete the installation of a large number
# of updates, but since it the VM will be being updated reasonably regularly
# I hope that will never be the case.

$TIMEOUT vboxmanage startvm $WINDOWS_VM -type headless

# Wait until virtualbox is running. I do this by sending ssh requests
# repeatedly until one is responded to. I will try up to 40 at 30-second
# intervals, so I am requiring the VM to have stablised within 20 minutes.
# The long delay I allow is to cope with the possibility that Windows might
# take several ages doing an automatic installation of updates.

sleep 20
for x in `seq 1 40`
do
  hello=`$TIMEOUT ssh -p $WINDOWS_PORT $WINDOWS_USER@localhost printf "hello"`
  if test "x$hello" = "xhello"
  then
    break
  fi
  printf "Sleeping to allow Windows VM to start up...\n"
  sleep 30
done

# Now in a way that is just as was done for Linux I will put the
# necessary files on the Windows guest VM

$TIMEOUT ssh -p $WINDOWS_PORT $WINDOWS_USER@localhost rm -rf winbuild
$TIMEOUT scp -r -P $WINDOWS_PORT winbuild $WINDOWS_USER@localhost:.
pushd macbuild
tar cfz - C | \
  $TIMEOUT ssh -p $WINDOWS_PORT $WINDOWS_USER@localhost \
    \( cd winbuild \; tar xfz - --warning=no-unknown-keyword \)
popd
$TIMEOUT ssh -p $WINDOWS_PORT $WINDOWS_USER@localhost touch winbuild/C.stamp

# That has now established the winbuild directory...

# Now do the main build of all the Windows binaries and packages.

# Note that the following step builds 6 copies of Reduce and takes
# several hours to complete. The versions built are
#   csl-win32, csl-win64, csl-cygwin32, csl-cygwin64, psl-win32 and psl-win64

# I do not fully understand why the setting of PATH here is vital, but it
# seems to be. Without it x86_64-w64-mingw32-gcc fails in a way that seems to
# indicate that it compiles the code in 64-bit mode then tries to assemble
# it using a 32-bit assembler (which then obviously chokes on the 64-bit
# assembly syntax passed to it).

$LONGTIMEOUT ssh -p $WINDOWS_PORT $WINDOWS_USER@localhost \( \
  cd winbuild \; \
  export PATH=/usr/local/bin:/usr/bin:\$PATH \; \
  pushd C \; ./autogen.sh \; popd \; \
  time make \)

# Recover the built files.
$TIMEOUT scp -P $WINDOWS_PORT $WINDOWS_USER@localhost:winbuild/Output/Reduce-Setup.exe \
    $here/../snapshots/Reduce-Setup_$today.exe

# Shut down the guest. I do this by issing a command within the VM rather
# than by an externally forced power-down since I hope that will count
# as kinder. 
#
# Note that under cygwin sometimes a cygwin program called "shutdown" can
# be installed, masking the native Windows one. I will try to call the
# native Windows version here. Further I am expecting that I have a 64-bit
# version of Windows but that I am running 32-bit cygwin for sshd, and so
# the SysWOW64 directory is liable to be the correct place to work from.

$TIMEOUT ssh -p $WINDOWS_PORT $WINDOWS_USER@localhost \$WINDIR/SysWOW64/shutdown /s /t 1

# Now make the Mac version. I wanted the archive unpacked early since that
# is what I copy for use on the other platforms, and doing things that way
# means I know that all systems build from exactly the same version of
# the sources.

pushd macbuild
# Now I very much hope that C and C.stamp are both present here!
pushd C ; ./autogen.sh ; popd
# I rather expect that C.stamp ought to be present still, and so the
# "make" here should not need to do anything by way of re-generating the
# C directory...
touch C.stamp
$LONGTIMEOUT make
cp Reduce*.dmg $here/../snapshots/Reduce-snapshot_$today.dmg
popd

printf "Can now copy these files to sourceforge:\n"

ls -l $here/../snapshots

# I believe everything should be complete now.
popd

exit 0
