#! /bin/bash -v

# This is a prototype of a scheme to make snapshot building more
# flexible such that it can run either on one machine with several
# virtual machines to support other operating systems, or on a network
# of machines with at least some building happening in native mode.
# AT present this is INCOMPLETE WORK.
# I am checking it in now for at least three reasons:
# (1) So there is a safe copy somewhere.
# (2) Because this way I can get copies of it on a number of machines and
#     that will help me test its portability,
# (3) In case others choose to look at it, review it and suggest corrections
#     or improvements.
#                                                       ACN February 2018




#! /bin/sh
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`
here=`dirname "$here"`

# If you have a file called .snapshots in your home directory then that
# will be read here to establish machines to be used in the build. See later
# for details...

if test -f $HOME/.snapshots
then
  source $HOME/.snapshots
fi

printf ">>>>>>>>>>>>>>>>>>>> here=$here\n"

# There are a collection of issues that one needs to be aware of here...
# The various remote machines must provide the current user with ssh access
# without needing a password - ie they must have been set up with public key
# authentication. The ssh link must have been used already so that the
# system from which the link is initiated is already in the known_hosts file
# of the remote system. Both those constraints are there so that execution
# of a remote command doe snot requite any intervention.
# When the remote system is a Virtual machine then after it has been used
# to build stuff I want to switch it off. About the most safest way I can
# see to do that is to issue the command "sudo /sbin/shutdown -h now" on it.
# for this to work as required the user on that virtual machine needs
# passwordless superuser authority. One might reasonably have some level of
# concern about the security implications of that - I am going to take the
# view for now that this is a VIRTUAL machine and while it trusts its host
# nobody else needs to trust it (much). A possible alternative is to power off
# by using the virtualbox "controlvm acpipowerbutton" and ensure that the
# VM respond to that by closing down gracefully.

pushd $here >/dev/null

prepare() {
# Ensure that there is a clean check-out of Reduce. If there is a directory
# called "reduce-distribution" expect it to be a subversion checkout. Use
# revert to discard any local changes. Get rid of any files in it that have
# been added locally. Then use "avn update" to bring it into step with the
# repository. If this directory does not exist create it by checking out
# a copy from the central site.

  if test -d ./reduce-distribution
  then
    printf "Will update and use existing reduce-distribution file-set.\n"
    pushd ./reduce-distribution >/dev/null
    svn -R revert .
    svn st | grep '^?' | awk '{$1=""; print $0}' | xargs -I{} rm -rf '{}'
    svn update
    popd >/dev/null
  else
    printf "Will check out a new reduce-distribution to use.\n"
    svn co svn://svn.code.sf.net/p/reduce-algebra/code/trunk ./reduce-distribution
  fi
}



build() {
# I will allow command-line options to indicate the collection
# of targets to be built for. This part of the script checks and decodes
# the options and dispatches to platform-specific scripts.

# First identify the current host machine. One could imagine adding more
# options here at some stage, but these are the ones I will initially
# consider building snapshots for or on.
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
    *i686*)
      local="linux32"
      ;;
    *arm*)
      local="rpi"
      ;;
    *)
      printf "Unsupported linux variant (`uname -m`)\n"
      exit 1
      ;;
    esac
    ;;
  *)
    printf "Unknown system (`uname -s`)\n"
    exit 1
    ;;
  esac

# If no arguments are given I will default by building a  full set of
# snapshots.
  if test "$#" = "0"
  then
    ARGS="macintosh windows linux32 linux64 rpi"
  else
# Here (and in general through thsi script) I am going to assume that
# file-paths, machine-name and script arguments do not contain embedded
# whitespace, and so I do not need to be especially careful about quotation
# when expaning shell parameters.
    ARGS="$@"
  fi

# If there are arguments I check that each is a recognized system name and
# I collect them in a list - taking care that if the current platform is
# mentioned it will be placed at the end of the list.
  targets=""
  for a in $ARGS
  do
    case "$a" in
    windows | \
    linux32 | \
    linux64 | \
    rpi     | \
    macintosh)
      if test "$a" = "$local"
      then
        targets="$targets $a"
      else
        targets="$a $targets"
      fi
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
    eval "build_$TARGET"
  done

}

build_windows() {
  machine_windows
  printf "\n### windows build script not provided yet.\n"
  exit 1
}

build_linux32() {
  machine_linux32
  build_debian linux32
}

build_linux64() {
  machine_linux64
  build_debian linux64
}

build_rpi() {
  machine_rpi
  build_debian rpi
}

build_debian() {
# Common code for building on a Linux variant
start_remote_host
copy_files 'reduce-distribution/debianbuild/' 'reduce-build/'
copy_files 'reduce-distribution/'             'reduce-build/C/'
execute_in_dir 'reduce-build/C'               './autogen.sh'
execute_in_dir 'reduce-build'                 'touch C.stamp'
execute_in_dir 'reduce-build'                 'make'
fetch_files    'reduce-build/*.{deb,rpm,tgz,bz2}'  "snapshots/$1/"
stop_remote_host
}

build_macintosh() {

machine_macintosh
start_remote_host
copy_files 'reduce-distribution/macbuild/' 'reduce-build/'
copy_files 'reduce-distribution/'          'reduce-build/C/'
execute_in_dir 'reduce-build/C'            './autogen.sh'
execute_in_dir 'reduce-build/C'            'tar cfj ../Reduce-source.tar.bz2 -X ../exclude.from.source.archive *'
execute_in_dir 'reduce-build'              'touch C.stamp'
execute_in_dir 'reduce-build'              'make'
fetch_files    'reduce-build/*.{dmg,bz2}'  'snapshots/macintosh'
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

# The host used and the mode of access to it will be passed in a selection
# of global variables which will need to be set ahead of calls to these
# functions. For now I will put in fixed settings, but in not too long
# I will arrange for distinct settings for each target architecture and for
# when the build runs on each possible host.

# The code here only deals with the "official Reduce snapshot machine",
# but by putting a file ".snapshots" in your home directory (and the
# file dot-snapshots here provides a model) you can get your own systems
# used instead.

machine_macintosh() {
  MODE="none"
  hosts_macintosh 2> /dev/null
  if test "$MODE" = "none"
  then
    case `uname -n` in
    math-smreduce)
      MODE=local
      ;;
    *)
      printf "Do not know how to access a macintosh from `uname -n`\n"
      exit 1
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
      ;;
    *)
      printf "Do not know how to access a windows machine from `uname -n`\n"
      exit 1
      ;;
    esac
  fi
}

machine_linux32() {
  MODE="none"
  hosts_linux32 2> /dev/null
  if test "$MODE" = "none"
  then
    case `uname -n` in
    math-smreduce)
      MODE=virtual
      VM="REDUCE-pkg-factory-Ubuntu32"
      ;;
    *)
      printf "Do not know how to access an i686 Linux machine from `uname -n`\n"
      exit 1
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
      ;;
    *)
      printf "Do not know how to access an x86_64 Linux machine from `uname -n`\n"
      exit 1
      ;;
    esac
  fi
}

machine_rpi() {
  MODE="none"
  hosts_rpi 2> /dev/null
  if test "$MODE" = "none"
  then
    case `uname -n` in
    math-smreduce)
      MODE=ssh+ssh
      HOST1=codemist.dynu.com
      HOST2=192.168.1.179
      ;;
    *)
      printf "Do not know how to access a raspberry pi from `uname -n`\n"
      exit 1
      ;;
    esac
  fi
}


# Now I have the recipes that can be used to transfer files or execute
# commands. Each tests MODE to see what to do.
  


start_remote_host() {
# This is only required if a virtual machine is involved. There are two
# cases - one when the machine is hosted on the current system and the
# other when it is remote.
  case $MODE in
  virtual)
# If there is a VM on the local machine I start by re-configuring it so that
# local port 1001 is redirected to its port 22 (ie ssh).
    vboxmanage modifyvm $VM --natpf1 delete ssh 2> /dev/null
    vboxmanage modifyvm $VM --natpf1 "ssh,tcp,,1001,,22"
# Start up the machine.
    vboxmanage startvm $VM --type headless
# Now here I would like to use "vboxmanage guestproperty wait $VM" on a
# suitable key to wait until the VM is started. However on at least one of my
# VMs I find that that information required does not manage to filter back
# to the host. So I drop back to polling via ssh every 10 seconds.
    while :
    do
      sleep 10
      hello=`timeout 20 ssh -p 1001 $USER@localhost printf "hello"`
      if test "x$hello" = "xhello"
      then
        break
      fi
    done
    ;;
  ssh+virtual)
# Now I express a similar sequence of steps, but with the Virtual Machine
# being created on a remote host.
    ssh $HOST vboxmanage modifyvm $VM --natpf1 delete ssh 2> /dev/null
    ssh $HOST vboxmanage modifyvm $VM --natpf1 "ssh,tcp,,1001,,22"
    ssh $HOST vboxmanage startvm $VM --type headless
    while :
    do
      sleep 10
      hello=`timeout 20 ssh -p 1001 $USER@$HOST printf "hello"`
      if test "x$hello" = "xhello"
      then
        break
      fi
    done
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
#   C do not send .svn directory and many built files
#   e use ssh with a specified port number
#   --delete get rid of files not in the local file-set
#   --force as you might expect
# OR --info=...
#

RSYNC_OPTIONS="-rlHpEPtzC --delete --force \
--info=backup0,copy0,del0,flist0,misc0,mount0,\
name0,progress0,remove0,skip0,symsafe2,stats2"

# NOTE HORRIBLY WELL. On the Macintosh there is a version of rsync in
# /usr/bin, but it is an old one. The settings of PATH that put the newer
# version (from macports) ahead of it for normal use does not apply when
# executing a remote command here. So the "--rsync-path" directive to
# direct use of the macports version is needed if the "--info" option is
# to be accepted to control the amount of displayed trace information.

MAC_RSYNC_EXTRA="--rsync-path=/opt/local/bin/rsync"

copy_files() {
# Usage example : copy_files 'reduce-distribution/macbuild/' 'reduce-build/'
  if test "$1" = "" || test "$2" = ""
  then
    printf "Internal error\n"
    exit 1
  fi
  src="$1"
  dest="$2"
  if test "$TARGET" = "macintosh"
  then
    RSO="$RSYNC_OPTIONS --delete $MAC_RSYNC_EXTRA"
  else
    RSO="$RSYNC_OPTIONS --delete"
  fi
  printf "Mode = $MODE: copy from $src to $dest\n"
  case $MODE in
  local)
    rsync $RSO $src $dest
    ;;
  ssh)
    rsync $RSO $src $USER@$HOST:$dest
    ;;
  virtual)
    rsync $RSO -e "ssh -p 1001" $src $USER@localhost:$dest
    ;;
  ssh+ssh)
    rsync $RSO -e "ssh $USER@$HOST1" $src $USER@$HOST2:$dest
    ;;
  ssh+virtual)
    rsync $RSO -e "ssh -p 1001" $src $USER@$HOST:$dest
    ;;
  *)
    printf "Unknown mode: $MODE\n"
    exit 1
  esac
}

execute_in_dir() {
# Usage example: execute_in_dir 'reduce-build/C' './autogen.sh'
  if test "$1" = "" || test "$2" = ""
  then
    printf "Internal error\n"
    exit 1
  fi
  dir="$1"
  cmd="$2"
  if test "$TARGET" = "macintosh"
  then
# For execution on the Macintosh I need to ensure that I have macports stuff
# on my PATH.
    cmd="export PATH=/opt/local/bin:\$PATH; $cmd"
  fi
  printf "Mode = $MODE: execute $cmd in directory $dir\n"
  case $MODE in
  local)
    eval "cd $dir; $cmd"
    ;;
  ssh)
    ssh $USER@$HOST "cd $dir; $cmd"
    ;;
  virtual)
    ssh -p 1001 $USER@localhost "cd $dir; $cmd"
    ;;
  ssh+ssh)
    ssh  $USER@$HOST1 "ssh $HOST2 \"cd $dir; $cmd\""
    ;;
  ssh+virtual)
    ssh -p 1001 $USER@HOST "cd $dir; $cmd"
    ;;
  *)
    printf "Unknown mode: $MODE\n"
    exit 1
  esac
}

fetch_files() {
# Usage example: fetch_files 'reduce-build/*.{dmg,bz2}' 'snapshots/'
  if test "$1" = "" || test "$2" = ""
  then
    printf "Internal error\n"
    exit 1
  fi
  src="$1"
  dest="$2"
  mkdir -p $dest
# This function is perhaps more delicate than others, because the source
# argumentmay be a list of files using wildcards. The wildcards must be
# expanded on the remote machine not locally. Also observe that in this
# case I will not be purging other files from the target directory.
  if test "$TARGET" = "macintosh"
  then
    RSO="$RSYNC_OPTIONS $MAC_RSYNC_EXTRA"
  else
    RSO="$RSYNC_OPTIONS"
  fi
  printf "Mode = $MODE: copy $src to $dest\n"
  case $MODE in
  local)
    eval "rsync $RSO $src $dest"
    ;;
  ssh)
    rsync $RSO "$USER@$HOST:$src" $dest
    ;;
  virtual)
    rsync $RSO -e "ssh -p 1001" "$USER@localhost:$src" $dest
    ;;
  ssh+ssh)
# Hah - will I need the extra layer of quoting here. Check carefully!
    rsync $RSO -e "ssh $USER@$HOST1" "\"$USER@$HOST2:$src\"" $dest
    ;;
  ssh+virtual)
    rsync $RSO -e "ssh -p 1001" "$USER@$HOST:$src" $dest
    ;;
  *)
    printf "Unknown mode: $MODE\n"
    exit 1
  esac
}

stop_remote_host() {
# If I am using a virtual machine I will close it by using its (virtual)
# ACPI power button.
  case $MODE in
  virtual)
    vboxmanage controlvm $VM acpipowerbutton
    ;;
  ssh+virtual)
    ssh $HOST vboxmanage controlvm $VM acpipowerbutton
    ;;
  *)
# In cases where a virtual machine is not involved I will not need to
# do anything, and in particular I do not want to drop through and hence
# find myself if the wait loop.
    return 0
    ;;
  esac
# In general a virtual machine will not shut down promptly when its power
# button is pressed. It may delay to give users a chance to tidy up and it
# may install updates or do other system administrative tasks. So I will
# wait until vboxmanage confirms to me that the system is actually powered
# off.
  while :
  do
    sleep 10
    if vboxmanage showvminfo --machinereadable $VM | grep 'VMState="poweroff"'
    then
      break
    fi
  done
}

#########################################################################
# Now do the work.
prepare
build "$@"

exit 0

# end of testsnaps.sh
