#! /usr/bin/env bash

# This script makes snapshots of Reduce. It should be capable of
# building ones for Windows (64-bit), Macintosh, Linux-x86_64
# and the Raspberry Pi. For the latter both 32 and 64-bit can be built,
# but we will probably not be keeping published Raspberry Pi snapshots
# up to date.
#
# The default as of June 2020 is
#     win64 linux64 macintosh
# so Raspberry Pi variants are not included by default.
#
# Each snapshot needs to be built on a computer of the relevant type.
# This can either be the current local host, a remote host that is
# accessible using ssh (possibly via a gateway machine) or a virtual
# machine using virtualbox that is either local or remote.
# The exact set of machine to be used are set in a file "./snapshots"
# in the user's home directory, and a file called dot-snapshots here
# gives a prototype for that.
#
# The "altlocal" option provides for running commands
#     altlocal C
# to run the command C in an alternative context but on the current
# machine with file-space, network address, user-identity and the like
# all unchanged. The command or script "altlocal" must be set up to make
# this happen, and (for instance) "altlocal uname -a" must report the
# identity of the changed context.
#
# Each host used during the build must have been set up with a comprehensive
# set of build tools and development libraries, and where it is to be
# accessed over ssh it must use public key authentication so that the current
# user on the system that this script runs on can access it without needing
# any extra interaction.
#
#                                                       ACN February 2018
#                                                           July 2019
#                                                           September 2019
#                                                           December 2019
#                                                           June 2020

# [some of the access schemes that chain ssh and virtual machines etc do not
# get path quoting right yet, but the simple cases are OK!]


here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`
HERE=`dirname "$here"`

case $@ in
*help*)
  printf "$0: This script is for making snapshots of Reduce\n"
  printf "Usage: $0 machine1 machine2 ...\n"
  printf "   or  %0 --test machine1 ...\n"
  printf "where the supported 'machines' are\n"
  printf "    windows (win64), macintosh, linux (linux64),\n"
  printf "and rpi (rpi32), rpi64.\n"
  printf "You can also include '--rev=NNNN' to specify a revision to use\n"
  printf "but note that '--rev=NNNN' must be the first item on the command line\n"
  printf "'rpi' is a Raspberry Pi running raspbian (now called Raspberry Pi OS).\n"
  printf "'pi64' uses 64-bit Raspberry Pi OS.\n"
  printf "If no machines are listed the script will attempt to build a\n"
  printf "default set. The results will end up in a snapshots directory in\n"
  printf "the Reduce tree. The hosts used during the build can be adapted to\n"
  printf "local needs via a $HOME/.snapshots file, and scripts/dot-snapshots\n"
  printf "provides a prototype for such a file and some explanation of what\n"
  printf "needs to be present.\n"
  printf "An option --rc=FILE uses that file in place of $HOME/.snapshots\n"
  printf "The default builds as of June 2020 are\n"
  printf "     win64 linux64 macintosh\n"
  printf "NOTE: There are no options here for creating 32-bit snapshots on\n"
  printf "      either Windows or Linux.\n"
  exit
  ;;
esac

# There are a collection of issues that one needs to be aware of here...
#
# The various remote machines must provide the current user with ssh access
# without needing a password - ie they must have been set up with public key
# authentication. The ssh link must have been used already so that the
# system from which the link is initiated is already in the known_hosts file
# of the remote system. Both those constraints are there so that execution
# of a remote command does not require any intervention.
#
# When the remote system is a Virtual machine then after it has been used
# to build stuff I want to switch it off. About the safest way I can
# see to do that is to issue the command "sudo /sbin/shutdown -h now" on it.
# for this to work as required the user on that virtual machine needs
# passwordless superuser authority. One might reasonably have some level of
# concern about the security implications of that - I am going to take the
# view for now that this is a VIRTUAL machine and while it trusts its host
# nobody else needs to trust it (much). A possible alternative is to power off
# by using the virtualbox "controlvm acpipowerbutton" and ensure that the
# VM respond to that by closing down gracefully. So in fact I will try both
# of these and if neither shuts the system down promptly I will kill it
# crudely.

cd $HERE

# Directory names here can be absolute or relative. If they are specified
# as relative then they are relative to the trunk directory in the Reduce
# tree that the snapshot builder is run from.

# REDUCE-DISTRIBUTION will hold a clean checkout of Reduce, updated from
# the master repository (ie Sourceforge). When I update it I will
# get rid of any files within that directory that are not tracked
# at Sourceforge. At the time of preparing this script all this fills
# 1.4 Gbytes, and of that around half is the ".svn" directory that
# subversion uses to track everything. It is legal to delete this tree
# between building snapshots, but if you do then the next snapshot build
# will need to fetch eveything from Sourceforge again. If you leave it in
# place then when a snapshot is created only updates to this will lead to
# network traffic. This directory only appears on the host machine that
# the snapshot builder runs on directly.

# The directory settings here can be overridden in your $HOME/.snapshots file
# or a file specified via --rc=FILE.

REDUCE_DISTRIBUTION="reduce-distribution"

# REDUCE_BUILD is created on each machine or virtual machine that
# a snapshot is build on and for. Its exact contents will vary depending
# omn whether the machine concerned is running Windows, Mac OSX, Linux
# or whatever. $REDUCE_BUILD/C becomes a copy of REDUCE_DISTRIBUTION
# but without the ".svn" directory. If this is left on the build machine
# then only updates to it get transmitted when a snapshot is needed.
# A local copy of Reduce is configured and built within REDUCE_BUILD,
# and by the end of that its size may be around 2GB. The build files are
# tidied away at the start of the next build cycle.

REDUCE_BUILD="reduce-build"

# SNAPSHOTS is where built snapshots are deposited. They are put in
# separate directories for each platform, eg SNAPSHOTS/windows. When new
# file are uploaded to this directory copies of its previous contents
# are archived in $SNAPSHOTS/old so that they are not lost and to provide
# an historical record. A full set of snapshots for Windows, Macintosh,
# 64-bit pc-Linux and for a Raspberry Pi use of the order
# of 630 Mbytes, and so obviously $SNAPSHOTS/old can grow in units of
# this amount. Discarding unwanted files from $SNAPSHOTS/old is left as
# a manual activity.

SNAPSHOTS="snapshots"

# If you have a file called .snapshots in your home directory then that
# will be read here to establish machines to be used in the build. See later
# for details...
# Well if you have "--rc=FILE" somewhere on the command line that can specify
# and alternative location for a configuration file.

DOT_SNAPSHOTS="$HOME/.snapshots"

# Any command-line item including the text "--rc=" will be noticed here
# and can lead to overriding where .snapshots is read from, so do not
# play too many silly games please!

case "$*" in
*--rc=*)
  snaploc="$*"
  snaploc=${snaploc##*--rc=}
  snaploc=${snaploc%% *}
  if test "$snaploc" != ""
  then
    DOT_SNAPSHOTS="$snaploc"
  fi
  ;;
esac

# Similarly any item containing "--rev=" anywhereon the command line will be
# treated as a revision specifier.

SVNOPT=""
case "$*" in
*--rev=*)
  revision="$*"
  revision=${revision##*--rev=}
  revision=${revision%% *}
  if test "$revision" != ""
  then
    SVNOPT="-r $revision"
  fi
  ;;
esac

printf "Will read profile from $DOT_SNAPSHOTS\n"

if test -f $DOT_SNAPSHOTS
then
  source $DOT_SNAPSHOTS
else
  printf "$DOT_SNAPSHOTS not found\n"
  exit 1
fi

# At the end of this file there is a sequence of calls to the procedures
# set up here. These each carry out one of the major steps in the
# snapshot building process.

prepare() {
# Ensure that there is a clean check-out of Reduce. If there is a directory
# called "$REDUCE_DISTRIBUTION" expect it to be a subversion checkout. Use
# revert to discard any local changes. Get rid of any files in it that have
# been added locally. Then use "svn update" to bring it into step with the
# repository. If this directory does not exist create it by checking out
# a copy from the central site.

  mkdir -p $SNAPSHOTS
  if test -d $REDUCE_DISTRIBUTION
  then
    printf "Will update and use existing $REDUCE_DISTRIBUTION file-set.\n"
    pushd $REDUCE_DISTRIBUTION >/dev/null
    svn -R revert .
# Get rid of any files that are in the local tree but are not present in the
# subversion repository. If "svn update" had a "--delete" option a bit like
# the one that rsync has or a bit like "Git clean" I would not have to
# use odd-looking shell scripting like this!
    svn st | grep '^?' | awk '{$1=""; print $0}' | xargs -I{} rm -rf '{}'
# I want a log of how the update went put in $SNAPSHOTS, however that might
# either be an absolute path or it could be one relative to the Reduce
# trunk directory on the machine coordinating the build. That makes it hard
# to send stuff there directly, so I first put the log within
# $REDUCE_DISTRIBUTION and then when I have done a "popd" back to my top
# level location I can move it to where I want it!
    svn $SVNOPT update | tee reduce-update.log
    REVISION=`svnversion`
    popd >/dev/null
    mv $REDUCE_DISTRIBUTION/reduce-update.log $SNAPSHOTS
  else
    printf "Will check out a new $REDUCE_DISTRIBUTION to use.\n"
    svn co $SVNOPT svn://svn.code.sf.net/p/reduce-algebra/code/trunk \
           $REDUCE_DISTRIBUTION > $SNAPSHOTS/reduce-checkout.log
    pushd $REDUCE_DISTRIBUTION >/dev/null
    REVISION=`svnversion`
    popd >/dev/null
# REVISION will be the subversion revision of the copy that I will make the
# snapshot of, written in the form "svnNNNN".
  fi
}

hostname() {
# I have a number of aliases for platforms, eg "linux" and "linux64". I
# arrange to map onto a canonical choice.
  case $1 in
  windows | win64)
    echo "windows"
    ;;
# altwin64 is a hack so I can have two build hosts for Windows and chose
# which to use on any particular occastion. Eg they could be picked from
# a Virtual machine, a remote Windows host or the current machine.
  altwindows | altwin64)
    echo "altwindows"
    ;;
  linux | linux64)
    echo "linux"
    ;;
  rpi | rpi32)
    echo "rpi"
    ;;
  *)
    echo "$1"
    ;;
  esac
}

add_target() {
# As I decode command line options I build up a list of the targets I am
# being asked to build. I put any the correspond to the current computer
# last.
  if test `hostname "$1"` = `hostname "$local"`
  then
    targets="$targets $1"
  else
    targets="$1 $targets"
  fi
}

remove_target() {
# Sometimes I may want to remove a target from my list.
  ot="$targets"
  targets=""
  for t in $ot
  do
    if test "$t" != "$1"
    then
      targets="$targets $t"
    fi
  done
}

build() {
# I will allow command-line options to indicate the collection
# of targets to be built for. This part of the script checks and decodes
# the options and dispatches to platform-specific scripts.

# First identify the current host machine. One could imagine adding more
# options here at some stage, but these are the ones I will initially
# consider building snapshots for or on. Given either real or virtual
# machines for other platforms they could be added here... subject to
# the creation of scripts that would package up the results in a way that
# suited the platform concerned.
  case `uname -s` in
  *CYGWIN*)
    local="windows"
    ;;
  *Darwin*)
    local="macintosh"
    ;;
  *Linux*)
    case `uname -m` in
    *x86_64*)
      local="linux64"
      ;;
    *arm*)
      local="rpi"
      ;;
    *aarch64*)
      local="rpi64"
      ;;
    *)
      printf "Unsupported Linux variant (`uname -m`)\n"
      exit 1
      ;;
    esac
    ;;
  *)
    printf "Unknown system (`uname -s`)\n"
    exit 1
    ;;
  esac

# If no positive arguments are given I will default by building a full
# set of snapshots.
  full="yes"
  for a in $*
  do
    case "$a" in
    windows     | \
    altwindows  | \
    win64       | \
    altwin64    | \
    linux       | \
    linux64     | \
    rpi         | \
    rpi32       | \
    rpi64       | \
    macintosh)
      full="no"
      ;;
    esac
  done
# The idea behind this is that one can provide no arguments at all and
# a default set of snapshots will be built. You can provide one or more
# platform names and then just those snapshots will be built. Or
# you can use a platform name prefixed with a "-" to disable that one.
# so:
#   no arguments, or just a --rc=FILE one:   linux64 win64 macintosh
#   linux64 rpi:                             just those 2 platforms
#   -macintosh:                              linux64 & win64, not macintosh
#
  if test "$full" = "yes"
  then
    ARGS="macintosh win64 linux64 $*"
  else
# Here (and in general through this script) I am going to assume that
# file-paths, machine-name and script arguments do not contain embedded
# whitespace, and so I do not need to be especially careful about quotation
# when expanding shell parameters.
    ARGS="$*"
  fi

# If there are arguments I check that each is a recognized system name and
# I collect them in a list - taking care that if the current platform is
# mentioned it will be placed at the end of the list.
  targets=""
  for a in $ARGS
  do
    case "$a" in
    windows    | \
    win64      | \
    altwindows | \
    altwin64   | \
    linux      | \
    linux64    | \
    rpi        | \
    rpi32      | \
    rpi64      | \
    macintosh)
      add_target "$a"
      ;;
    -windows    | \
    -win64      | \
    -altwindows | \
    -altwin64   | \
    -linux      | \
    -linux64    | \
    -rpi        | \
    -rpi32      | \
    -rpi64      | \
    -macintosh)
      remove_target "${a#-}"
      ;;
    --rc=* | --rev=*)
      ;;
    *)
      printf "\n### Option '$a' not recognized. Stopping.\n"
      exit 1
      ;;
    esac
  done

  printf "\nTargets: $targets\n"

# Now for all the systems that are to be built call the platform-specific
# function that will do the work.
  for TARGET in $targets
  do
# I will expect that there is a bash function to build for each possible
# target architecture.
    printf "Next build for $TARGET\n"
    eval "build_$TARGET"
    printf "Completed building for $TARGET\n"
  done
}

# Here I start with the per-target build instructions...

build_win64() {
  machine_windows
  if test "$MODE" = "none"
  then
    printf "Unable to build Windows snapshot here\n"
    return 0
  fi
# The general pattern applied here is that I start any virtual machines
# that are to be used, copy my neat distribution files across and position
# them alongside relevant platform-specific build instructions. I then
# update all the autoconf-generated files and can then use "make" to get
# the snapshot built and packages. I fetch the build snapshot back and
# put it where it needs to be.
  start_remote_host
# The files in winbuild64 provide the framework for building the snapshot.
  copy_files "$REDUCE_DISTRIBUTION/winbuild64/"  "$REDUCE_BUILD/"  "--exclude=C"
  copy_files "$REDUCE_DISTRIBUTION/"             "$REDUCE_BUILD/C/"
  execute_in_dir "windows" "$REDUCE_BUILD/C"               "./autogen.sh"
  execute_in_dir "windows" "$REDUCE_BUILD"                 "touch C.stamp"
  execute_in_dir "windows" "$REDUCE_BUILD"                 "make REVISION=$REVISION"
  fetch_files    "$REDUCE_BUILD/Output/*.*"      "$SNAPSHOTS/windows/" "$SNAPSHOTS/old/windows"
  stop_remote_host
}

build_windows() {
  build_win64
}

build_altwin64() {
  machine_altwindows
  if test "$MODE" = "none"
  then
    printf "Unable to build Windows snapshot here\n"
    return 0
  fi
  start_remote_host
  copy_files "$REDUCE_DISTRIBUTION/winbuild64/"  "$REDUCE_BUILD/"  "--exclude=C"
  copy_files "$REDUCE_DISTRIBUTION/"             "$REDUCE_BUILD/C/"
  execute_in_dir "windows" "$REDUCE_BUILD/C"               "./autogen.sh"
  execute_in_dir "windows" "$REDUCE_BUILD"                 "touch C.stamp"
  execute_in_dir "windows" "$REDUCE_BUILD"                 "make REVISION=$REVISION"
  fetch_files    "$REDUCE_BUILD/Output/*.*"      "$SNAPSHOTS/windows/" "$SNAPSHOTS/old/win64"
  stop_remote_host
}

build_altwindows() {
  build_altwin64
}

build_debian() {
####@@@@
  printf "build_debian starting $*\n";
# Common code for building on a Linux variant.
  if test "$MODE" = "none"
  then
    printf "Unable to build $TARGET snapshot here\n"
    return 0
  fi
  start_remote_host
# The files in debianbuild provide the framework for building. I will first
# build ".deb" style distribution archives and then map those onto ".rpm"
# versions: the machine used to do that is required to be a Debian-family
# system.
  copy_files "$REDUCE_DISTRIBUTION/debianbuild/" "$REDUCE_BUILD/"   "--exclude=C"
  copy_files "$REDUCE_DISTRIBUTION/"             "$REDUCE_BUILD/C/"
  execute_in_dir "linux" "$REDUCE_BUILD/C"               "./autogen.sh"
  execute_in_dir "linux" "$REDUCE_BUILD"                 "touch C.stamp"
  execute_in_dir "linux" "$REDUCE_BUILD"                 "make REVISION=$REVISION"
  fetch_files    "$REDUCE_BUILD/*.{deb,rpm,tgz,bz2}"  "$SNAPSHOTS/$1/" "$SNAPSHOTS/old/$1"
  stop_remote_host
}

# All the Linux variants will use build_debian to do the main work once I
# know which machine to run that on.

build_linux64() {
  machine_linux64
  build_debian linux64
}

build_linux() {
  build_linux64
}

build_rpi32() {
  machine_rpi32
  build_debian rpi
}

build_rpi() {
  build_rpi32
}

build_rpi64() {
# Much the same as for 32-bit Raspberry pi but it will need a different
# host.
  machine_rpi64
  build_debian rpi64
}

build_macintosh() {
  machine_macintosh
  if test "$MODE" = "none"
  then
    printf "Unable to build Macintosh snapshot here\n"
    return 0
  fi
  start_remote_host
# As you might imagine, macbuild holds build scripts here.
  copy_files "$REDUCE_DISTRIBUTION/macbuild/" "$REDUCE_BUILD/"   "--exclude=C"
  copy_files "$REDUCE_DISTRIBUTION/"          "$REDUCE_BUILD/C/"
  execute_in_dir "macintosh" "$REDUCE_BUILD/C"            "./autogen.sh"
  execute_in_dir "macintosh" "$REDUCE_BUILD"              "make REVISION=$REVISION source-archive"
  execute_in_dir "macintosh" "$REDUCE_BUILD"              "touch C.stamp"
  execute_in_dir "macintosh" "$REDUCE_BUILD"              "make REVISION=$REVISION"
  fetch_files    "$REDUCE_BUILD/*.{dmg,bz2}"  "$SNAPSHOTS/macintosh/" "$SNAPSHOTS/old/macintosh"
  stop_remote_host
}

# The following functions arrange access to the machine on which building
# will take place. There are several possible configurations:
# (1) The current machine is to be used.
# (2) A machine reachable using ssh (with public key authentication so
#     no explicit password exchange is called for is needed) is to be used,
#     with the remote build performed relative to the current user's home
#     directory there.
# (3) A virtual machine is hosted on the current system and is to be used.
# (4) A virtual machine is hosted on a remote system and is to be used.
# (5) The machine to be used is on a private network accessible via
#     a machine that can be reached using ssh,
# I think that extending case (5) with a virtual machine hosted on a system
# that can only be accessed indirectly would be taking things too far, but if
# needbe I believe it could be supported.
# (6) As (3), (4) or (5) but rather than using a virtual machine using a
#     containerised version of some alternative operating system.

# The host used and the mode of access to it will be passed in a selection
# of global variables which will need to be set ahead of calls to these
# functions. For now I will put in fixed settings, but in not too long
# I will arrange for distinct settings for each target architecture and for
# when the build runs on each possible host.

# The code here sets things up for the "official Reduce snapshot machine",
# but by putting a file ".snapshots" in your home directory (and the
# file dot-snapshots here provides a model) almost everything can be
# overridden to perform builds on machines of your own customised choice
# using the access schemes that you need.

machine_macintosh() {
  MODE="none"
# The function "hosts_macintosh" *MAY* have been defined in a user .snapshots
# file, and if so then I will call it here. But it does not have to be, so if
# the following line fails with a "command not found" error then that is
# entirely reasonable. That is why I redirect stderr to /dev/null.
  hosts_macintosh 2> /dev/null
# If .snapshots did not provide an indication of what to do but we are running
# on "math-smreduce" set things up as for there.
  if test "$MODE" = "none"
  then
    case `uname -n` in
    math-smreduce)
      MODE=local
# On this host the disc space is such that it is useful to specify that
# the work-space and eventual results from a snapshot build run are
# put in a separate volume... Note that the settings here are repeated for
# each target architecture.
      REDUCE_DISTRIBUTION="/Volumes/DATA/reduce-distribution"
      REDUCE_BUILD="/Volumes/DATA/reduce-build"
      SNAPSHOTS="/Volumes/DATA/snapshots"
      ;;
    *)
      printf "Do not know how to access a Macintosh from `uname -n`\n"
      MODE=none
      ;;
    esac
  fi
}

machine_windows() {
  MODE="none"
  hosts_windows 2> /dev/null
  if test "$MODE" = "none"
  then
    case `uname -n` in
    math-smreduce)
      MODE=virtual
      VM="REDUCE-pkg-factory-Windows"
      REDUCE_DISTRIBUTION="/Volumes/DATA/reduce-distribution"
      REDUCE_BUILD="/Volumes/DATA/reduce-build"
      SNAPSHOTS="/Volumes/DATA/snapshots"
      ;;
    *)
      printf "Do not know how to access a Windows machine from `uname -n`\n"
      MODE=none
      ;;
    esac
  fi
}

machine_altwindows() {
  MODE="none"
  hosts_altwindows 2> /dev/null
  if test "$MODE" = "none"
  then
    case `uname -n` in
    math-smreduce)
      MODE=virtual
      VM="REDUCE-pkg-factory-Windows"
      REDUCE_DISTRIBUTION="/Volumes/DATA/reduce-distribution"
      REDUCE_BUILD="/Volumes/DATA/reduce-build"
      SNAPSHOTS="/Volumes/DATA/snapshots"
      ;;
    *)
      printf "Do not know how to access a Windows machine from `uname -n`\n"
      MODE=none
      ;;
    esac
  fi
}

machine_linux64() {
  MODE="none"
  hosts_linux64 2> /dev/null
  if test "$MODE" = "none"
  then
    case `uname -n` in
    math-smreduce)
      MODE=virtual
      VM="REDUCE-pkg-factory-Ubuntu"
      REDUCE_DISTRIBUTION="/Volumes/DATA/reduce-distribution"
      REDUCE_BUILD="/Volumes/DATA/reduce-build"
      SNAPSHOTS="/Volumes/DATA/snapshots"
      ;;
    *)
      printf "Do not know how to access an x86_64 Linux machine from `uname -n`\n"
      MODE=none
      ;;
    esac
  fi
}

machine_linux() {
  machine_linux64
}

machine_rpi32() {
  MODE="none"
  hosts_rpi 2> /dev/null
  if test "$MODE" = "none"
  then
    case `uname -n` in
    *)
      printf "Do not know how to access a Raspberry Pi from `uname -n`\n"
      MODE=none
      ;;
    esac
  fi
}

machine_rpi() {
  machine_rpi32
}

machine_rpi64() {
  MODE="none"
  hosts_rpi64 2> /dev/null
  if test "$MODE" = "none"
  then
    case `uname -n` in
    *)
      printf "Do not know how to access a 64-bit Raspberry Pi from `uname -n`\n"
      MODE=none
      ;;
    esac
  fi
}

# Now I have the recipes that can be used to transfer files or execute
# commands. Each tests MODE to see what to do.
  
# If I am connecting to a Virtual Machine I will disable host key checking
# and recording so that I can connect for the very first time without
# that causing confusion, and so that reconfiguration of the VM does not
# lead to pain.

SSHOPTS="-o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no\
 -o LogLevel=error -o ForwardX11=no"

start_remote_host() {
# This is only required if a virtual machine is involved. There are two
# cases - one when the machine is hosted on the current system and the
# other when it is remote.
  case $MODE in
  virtual)
# If the VM happens to be running already (perhaps left over from an
# interrupted previous attempt) I need to shut it down before I try
# to re-configure it. Note that all this will just stall if the VM
# you are trying to work with does not exist! I check for "running" here
# because a machine might be labelled as "aborted" or "stopped" or various
# other states. If the machine is already in the process of stopping then
# it might have done so before the ACPI event is posted to it and that might
# lead to a message suggesting an error, but all ought to be well.
    printf "vboxmanage showvminfo --machinereadable $VM\n"
    if vboxmanage showvminfo --machinereadable $VM | grep 'VMState="running"'
    then
      stop_remote_host
    fi
# If there is a VM on the local machine I start by re-configuring it so that
# a local port is redirected to its port 22 (ie ssh). I pick a random port
# number in the range 10000 to 42767 such that the ports is not in use.
# Well there could then be a race condition once I have selected a port -
# some other task could seize it before virualbox managed to. I rather hope
# that there will not be too many clashes in the range I use and that
# bad things will be uncommon.
    printf "vboxmanage modifyvm $VM --natpf1 delete ssh\n"
    vboxmanage modifyvm $VM --natpf1 delete ssh 2> /dev/null
    while :
    do
      let PORT=RANDOM+10000
# Note that RANDOM returns a 15-bit integer.
      if ! true &>/dev/null </dev/tcp/127.0.0.1/$PORT
      then
        break
      fi
    done
    printf "vboxmanage modifyvm $VM --natpf1 \"ssh,tcp,,$PORT,,22\"\n"
    vboxmanage modifyvm $VM --natpf1 "ssh,tcp,,$PORT,,22"
# Start up the machine.
    printf "vboxmanage startvm $VM --type headless\n"
    vboxmanage startvm $VM --type headless
# Now here I would like to use "vboxmanage guestproperty wait $VM" on a
# suitable key to wait until the VM is started. However on at least one of my
# VMs I find that that information required does not manage to filter back
# to the host. So I drop back to polling via ssh every 10 seconds.
    printf "Poll at $USER@localhost port $PORT\n"
    while :
    do
      sleep 10
      printf "ssh -p $PORT $SSHOPTS $USER@localhost printf \"hello\"\n"
      hello=`timeout 20 ssh -p $PORT $SSHOPTS $USER@localhost printf "hello"`
      if test "x$hello" = "xhello"
      then
        break
      else
        printf "Response: $hello\n"
      fi
    done
    ;;
  ssh+virtual)
# Now I express a similar sequence of steps, but with the Virtual Machine
# being created on a remote host. Note that this means that the port that
# I select must be available for use on that remote system.
    printf "ssh $USER@$HOST vboxmanage showvminfo --machinereadable $VM\n"
    if ssh $USER@$HOST vboxmanage showvminfo --machinereadable $VM | grep 'VMState="running"'
    then
      stop_remote_host
    fi
    printf "ssh $USER@$HOST vboxmanage modifyvm $VM --natpf1 delete ssh\n"
    ssh $USER@$HOST vboxmanage modifyvm $VM --natpf1 delete ssh 2> /dev/null
    while :
    do
      let PORT=RANDOM+10000
      if ! ssh $USER@$HOST "true &>/dev/null </dev/tcp/127.0.0.1/$PORT"
      then
        break
      fi
    done
    printf "ssh $USER@$HOST vboxmanage modifyvm $VM --natpf1 \"ssh,tcp,,$PORT,,22\"\n"
    ssh $USER@$HOST vboxmanage modifyvm $VM --natpf1 "ssh,tcp,,$PORT,,22"
    printf "ssh $USER@$HOST vboxmanage startvm $VM --type headless\n"
    ssh $USER@$HOST vboxmanage startvm $VM --type headless
    printf "Poll at $USER@$HOST port $PORT\n"
    while :
    do
      sleep 10
      printf "ssh -p $PORT $SSHOPTS $USER@$HOST printf \"hello\"\n"
      hello=`timeout 20 ssh -p $PORT $SSHOPTS $USER@$HOST printf "hello"`
      if test "x$hello" = "xhello"
      then
        break
      else
        printf "Response: $hello\n"
      fi
    done
    ;;
# It is at least imaginable that the "altlocal" schemes might need a startup
# step, and if they do it should go in here,
  altlocal)
    ;;
  ssh+altlocal)
    ;;
  ssh+ssh+altlocal)
    ;;
  esac
}

# All the options to rsync here say
#   r recursive copy
#   l copy symlinks
#   H copy hard links
#   p preserve permissions
#   E preserve executability
#   P keep any partially copied files for smoother re-start after
#     interruption
#   t preserve modification times of files
#   z compress network traffic
#   e use ssh with a specified port number
#   --exclude=... avoid sending certain files & directories
#   --delete get rid of files not in the local file-set
#   --force perform actions without requiring confirmation
#   --info=... control messages that are generated
#

RSYNC_OPTIONS="--old-args -rlHpEPtz --delete --force \
   --info=backup0,copy0,del0,flist0,misc0,mount0 \
   --info=name0,progress0,remove0,skip0,symsafe2,stats2"

# NOTE HORRIBLY WELL. On the Macintosh there is a version of rsync in
# /usr/bin, but it is an old one. The settings of PATH that put the newer
# version (from macports) ahead of it for normal use does not apply when
# executing a remote command here. So the "--rsync-path" directive to
# direct use of the macports version is needed if the "--info" option is
# to be accepted to control the amount of displayed trace information.

MAC_RSYNC_EXTRA="--rsync-path=/opt/local/bin/rsync"

copy_files() {
# Usage example : copy_files "$REDUCE_DISTRIBUTION/macbuild/" "$REDUCE_BUILD/" "--exclude=C"
  if test "$1" = "" || test "$2" = ""
  then
    printf "Internal error\n"
    exit 1
  fi
  src="$1"
  dest="$2"
# The third argument is optional, but passes additional options to rsync.
  xtra="$3"
  if test "$TARGET" = "macintosh"
  then
    RSO="$RSYNC_OPTIONS --exclude=.svn $xtra --delete $MAC_RSYNC_EXTRA"
  else
    RSO="$RSYNC_OPTIONS --exclude=.svn $xtra --delete"
  fi
  printf "Mode = $MODE: copy from $src to $dest\n"
  case $MODE in
  local | altlocal)
    cd $HERE
    printf "rsync $RSO $src $dest\n"
    rsync $RSO $src $dest
    ;;
  ssh | ssh+altlocal)
# For direct ssh access I will expect that the remote machine has been
# accessed before and that host key confirmation etc has been performed.
    printf "rsync $RSO $src $USER@$HOST:$dest\n"
    rsync $RSO $src $USER@$HOST:$dest
    ;;
  virtual)
    printf "rsync $RSO -e \"ssh -p $PORT $SSHOPTS\" $src $USER@localhost:$dest\n"
    rsync $RSO -e "ssh -p $PORT $SSHOPTS" $src $USER@localhost:$dest
    ;;
  ssh+ssh | ssh+ssh+altlocal)
    printf "rsync $RSO -e \"ssh -t -A $SSHOPTS $USER@$HOST1 ssh $SSHOPTS\" $src $USER@$HOST2:$dest\n"
    rsync $RSO -e "ssh -t -A $SSHOPTS $USER@$HOST1 ssh $SSHOPTS" $src $USER@$HOST2:$dest
    ;;
  ssh+virtual)
    printf "rsync $RSO -e \"ssh -p $PORT $SSHOPTS\" $src $USER@$HOST:$dest\n"
    rsync $RSO -e "ssh -p $PORT $SSHOPTS" $src $USER@$HOST:$dest
    ;;
  *)
    printf "Unknown mode: $MODE\n"
    exit 1
  esac
}

execute_in_dir() {
# Usage example: execute_in_dir "$REDUCE_BUILD/C" "./autogen.sh"
  if test "$1" = "" || test "$2" = ""
  then
    printf "Internal error\n"
    exit 1
  fi
  machine="$1"
  dir="$2"
  cmd="$3"
  printf "raw cmd = %s\n" "$cmd"
  mode="$MODE"
  case $MODE in
  altlocal)
    mode=local
    cmd="altlocal $cmd"
    ;;
  ssh+altlocal)
    mode=ssh
    cmd="altlocal $cmd"
    ;;
  ssh+ssh+altlocal)
    mode=ssh+ssh
    cmd="altlocal $cmd"
    ;;
  esac  
  case "$machine" in
  *macintosh*)
    cmd="export PATH=/opt/local/bin:\$PATH; $cmd"
    ;;
  *linux* | *rpi*)
    cmd="export PATH=/usr/local/bin:\$PATH; $cmd"
    ;;
  esac
  printf "Adjusted command = %s\n" "$cmd"
  printf "+++ Mode = %s\n" "$MODE"
  printf "Execute %s\n" "$cmd"
  printf "+++ in directory %s\n" "$dir"
  case $MODE in
  local)
    cd $HERE
    printf "eval \"cd $dir; $cmd\"\n"
    eval "cd $dir; $cmd"
    cd $HERE
    ;;
  ssh)
    cmd=export\ PATH=/usr/local/bin:/usr/bin:/bin:\\\$PATH\;\ cd\ $dir\;\ $cmd
    cmd=`echo \$cmd | sed 's/[^a-zA-Z0-9]/\\\&/g'`
    printf "\nssh $USER@$HOST eval $cmd\n"
    ssh $USER@$HOST "eval $cmd"
    ;;
  virtual)
    printf "ssh -p $PORT $SSHOPTS $USER@localhost \"export PATH=/usr/local/bin:/usr/bin:\$PATH; cd $dir; $cmd\"\n"
    ssh -p $PORT $SSHOPTS $USER@localhost "export PATH=/usr/local/bin:/usr/bin:\$PATH; cd $dir; $cmd"
    ;;
  ssh+ssh)
    printf "ssh $SSHOPTS $USER@$HOST1 \"$cmd\"\n"
    echo SSH+SSH case [$cmd]
    ssh -t -A $SSHOPTS $USER@$HOST1 "echo $USER@$HOST2 \"export PATH=/usr/bin:\\\"\"\\\$PATH\"\\\"; cd $dir; \\\"$cmd\\\"\""
    ssh -t -A $SSHOPTS $USER@$HOST1 "ssh  $USER@$HOST2 \"export PATH=/usr/bin:\\\"\"\\\$PATH\"\\\"; cd $dir; \\\"$cmd\\\"\""
    ;;
  ssh+virtual)
    printf "ssh -p $PORT $SSHOPTS $USER@$HOST \"export PATH=/usr/local/bin:/usr/bin:\$PATH; cd $dir; $cmd\"\n"
    ssh -p $PORT $SSHOPTS $USER@$HOST "export PATH=/usr/local/bin:/usr/bin:\$PATH; cd $dir; $cmd"
    ;;
  *)
    printf "Unknown mode: $MODE\n"
    exit 1
  esac
}

fetch_files() {
# Usage example: fetch_files "$REDUCE_BUILD/*.{dmg,bz2}" "$SNAPSHOTS/linux32" "$SNAPSHOTS/old/linux32"
  if test "$1" = "" || test "$2" = "" || test "$3" = ""
  then
    printf "Internal error\n"
    exit 1
  fi
  src="$1"
  dest="$2"
  backup="$3"
# I will move any previous snapshots for this architecture to somewhere
# else, specifically to a directory "old" in the place where snapshots are
# collected. At one stage I had copied the files here and I expected that
# rsync would delete the old ones for me, but when I copy named files using
# rsync, ones not mentioned are not purged. I had also tried using
# a directory called old$dest (eg oldsnapshots) but that would not be good
# if the user had configured things to put built snapshots in a directory
# with a fully rooted path. So now the invocation of this function specifies
# the backup directory explicitly.
  mkdir -p $dest
  mkdir -p $backup
  printf "mv ${dest}* $backup\n"
# The "mv" here would fail if the directory $dest is empty such that there
# are no old snapshots to preserve. So do not perform it.
  if test "`find ${dest} -type f`" = ""
  then
    echo No existing snapshots in ${dest}
  else
    mv ${dest}* $backup
  fi
# This function is perhaps more delicate than others, because the source
# argument may be a list of files using wildcards. The wildcards must be
# expanded on the remote machine not locally. The --delete option here
# turns out not to do as much as I had hoped by way of tidying up the
# destination directory, but all is well - I just emptied it by moving files
# from there to the backup location.
  if test "$TARGET" = "macintosh"
  then
    RSO="$RSYNC_OPTIONS --delete $MAC_RSYNC_EXTRA"
  else
    RSO="$RSYNC_OPTIONS --delete"
  fi
  printf "Mode = $MODE: copy $src to $dest\n"
  case $MODE in
  local | altlocal)
    cd $HERE
    printf "eval \"rsync $RSO $src $dest\"\n"
    eval "rsync $RSO $src $dest"
    ;;
  ssh | ssh+altlocal)
    printf "rsync $RSO \"$USER@$HOST:$src\" $dest\n"
    rsync $RSO "$USER@$HOST:$src" $dest
    ;;
  virtual)
    printf "rsync $RSO -e \"ssh -p $PORT $SSHOPTS\" \"$USER@localhost:$src\" $dest\n"
    rsync $RSO -e "ssh -p $PORT $SSHOPTS" "$USER@localhost:$src" $dest
    ;;
  ssh+ssh | ssh+ssh+altlocal)
    printf "rsync $RSO -e \"ssh $SSHOPTS $USER@$HOST1 ssh $SSHOPTS\" \"$USER@$HOST2:$src\" $dest\n"
    rsync $RSO -e "ssh -t -A $SSHOPTS $USER@$HOST1 ssh $SSHOPTS" "$USER@$HOST2:$src" $dest
    ;;
  ssh+virtual)
    printf "rsync $RSO -e \"ssh -p $PORT $SSHOPTS\" \"$USER@$HOST:$src\" $dest\n"
    rsync $RSO -e "ssh -p $PORT $SSHOPTS" "$USER@$HOST:$src" $dest
    ;;
  *)
    printf "Unknown mode: $MODE\n"
    exit 1
  esac
}

stop_remote_host() {
# If I am using a virtual machine I will shut it down.
  case $MODE in
  virtual)
# If this is closing things down at the end of a build I should know the
# port number to communicate with it, and I will try sending a command
# to instruct it to power off. On machines other than Windows that would
# only work if the current user has superuser authority without needing
# to quote a password!
    if test "$PORT" != ""
    then
      case $TARGET
      in
      *win*)
        execute_in_dir "windows" "$REDUCE_BUILD" "\$WINDIR/SysWOW64/shutdown /s /t 1"
        ;;
      *macintosh*)
        execute_in_dir "macintosh" "$REDUCE_BUILD" "sudo /sbin/shutdown -h now"
        ;;
      *)
        execute_in_dir "linux" "$REDUCE_BUILD" "sudo /sbin/shutdown -h now"
        ;;
      esac
    fi
# Having tried to ask the machine to power off I will also press its
# virtual ACPI power button.
    printf "vboxmanage controlvm $VM acpipowerbutton\n"
    vboxmanage controlvm $VM acpipowerbutton
# In general a virtual machine will not shut down promptly when its power
# button is pressed. It may delay to give users a chance to tidy up and it
# may install updates or do other system administrative tasks. So I will
# wait until vboxmanage confirms to me that the system is actually powered
# off.
    for n in `seq 1 60`
    do
      sleep 10
      printf "vboxmanage showvminfo --machinereadable $VM\n"
      if vboxmanage showvminfo --machinereadable $VM | grep 'VMState="poweroff"'
      then
        return 0
      fi
    done
# If I get here then the polling to see if the machine has stopped has gone
# on for 10 minutes. If it has taken that long I will just pull the plug.
    printf "vboxmanage controlvm $VM poweroff\n"
    vboxmanage controlvm $VM poweroff
    ;;
  ssh+virtual)
    printf "ssh $USER@$HOST vboxmanage controlvm $VM acpipowerbutton\n"
    ssh $USER@$HOST vboxmanage controlvm $VM acpipowerbutton
    for n in `seq 1 60`
    do
      sleep 10
      printf "ssh $USER@$HOST vboxmanage showvminfo --machinereadable $VM\n"
      if ssh $USER@$HOST vboxmanage showvminfo --machinereadable $VM | grep 'VMState="poweroff"'
      then
        break
      fi
    done
    printf "ssh $USER@HOST vboxmanage controlvm $VM poweroff\n"
    ssh $USER@$HOST vboxmanage controlvm $VM poweroff
    ;;
  altlocal)
    ;;
  ssh+altlocal)
    ;;
  ssh+ssh+altlocal)
    ;;
  esac
}

#########################################################################
# Now do the work.

# I allow either "-test" or "--test". This will run tests rather than build
# the system.

if test "$1" = "-test" ||
   test "$1" = "--test"
then
  printf "\n\n+++ Test machine access +++ \n\n"
  shift
# --test can be followed by a list of machines to test for access.
  if test "$*" = ""
  then
    MCS="linux64 macintosh win64"
  else
    MCS="$*"
  fi
  printf "Test for $MCS\n\n"
#  cd $HERE
#  prepare
  cd $HERE
# This is going to try each of the intended targets
  for m in $MCS
  do
    machine_$m
# If a target is not supported from this host do not try it.
    if test "$MODE" != "none"
    then
      start_remote_host
# I try to display `pwd` which should be /usr/bin, then
# `uname -a` to confirm the type of machine being used,
# `file /bin/ls` will confirm the userland architecture.
      execute_in_dir "$m" "/usr/bin" \
        "printf \"\\n\\n\\nTest on machine type $m\\n\";
         printf \"dir = \`pwd\`\\n\"; \
         printf \"path = \`echo \\\$PATH\`\\n\"; \
         printf \"uname = \`uname -a\`\\n\"; \
         printf \"file type of /bin/ls = \`file /bin/ls\`\\n\\n\\n\""
      stop_remote_host
    fi
  done
else
  cd $HERE
  prepare
  cd $HERE
  build "$@"
  cd $HERE
fi

exit 0

# end of mk-snapshots.sh
