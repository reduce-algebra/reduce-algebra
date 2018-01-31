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
# (3) In casde others choose to look at it, review it and suggest corrections
#     or improvements.
#                                                       ACN January 2018




#! /bin/sh
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`
here=`dirname "$here"`

# If you have a file called .snapshots in your home directory then that
# will be read here to establish machines to be used in the build. See later
# for details...

if test -f $(HOME)/.snapshots
then
  source $(HOME)/.snapshots
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

# If no arguments are given I will default by building a snapshot for
# just the current machine.
  if test "$#" = "0"
  then
    targets="$local"
  else
# If there are arguments I check that each is a recognized system name and
# I collect them in a list - taking care that if the current platform is
# mentioned it will be placed at the end of the list.
    targets=""
    for a in $@
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
  fi

# Now for all the systems that are to be built call the platform-specific
# function that will do the work.
  for t in $targets
  do
    eval "build_$t"
  done

}

build_windows() {
  machine_windows
  printf "\n### windows build script not provided yet.\n"
  exit 1
}

build_linux32() {
  machine_linux32
  printf "\n### linux32 build script not provided yet.\n"
  exit 1
}

build_linux64() {
  machine_linux64
  printf "\n### linux64 build script not provided yet.\n"
  exit 1
}

build_rpi() {
  machine_rpi
  printf "\n### rpi build script not provided yet.\n"
  exit 1
}

build_macintosh() {

machine_macintosh
start_remote_host
copy_files 'reduce-distribution/macbuild/' 'reduce-build/'
copy_files 'reduce-distribution/'          'reduce-build/C/'
execute_in_dir 'reduce-build/C'            './autogen.sh'
execute_in_dir 'reduce-build/C'            'tar cfj ../Reduce-source.tar.bz2 -X ../exclude.from.source.archive *'
execute_in_dir 'reduce-build'              'touch C.stamp'
execute_in_dir 'reduce_build'              'make'
fetch_from_dir 'reduce-build' '*.dmg *.bz2' "snapshots/"
stop_remote_host

return 0

# Here are the commands to be executed to build stuff
COMMANDS=" \
  ./autogen.sh; \
  ./configure --with-csl; \
  ./configure --with-psl; \
  time make"

HOST=192.168.1.8
PORT=22

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
#   --progress report during the transfer
# OR --info=...
#

# NOTE HORRIBLY WELL. On the Macintosh there is a version of rsync in
# /usr/bin, but it is an old one. The settings of PATH that put the newer
# version (from macports) ahead of it for normal use does not apply when
# executing a remote command here. So the "--rsync-path" directive to
# direct use of the macports version is needed if the "--info" option is
# to be accepted to control the amount of displayed trace information.

rsync -rlHpEPtzC -e "ssh -p $PORT" --delete --force \
  --info=backup0,copy0,del0,flist0,misc0,mount0,name0,progress0,remove0,skip0,symsafe2,stats2 \
  --rsync-path=/opt/local/bin/rsync \
  ./reduce-distribution/ \
  $USER@$HOST:reduce-remote-distribution/

ssh -p $PORT $USER@$HOST "cd reduce-remote-distribution; export PATH=/opt/local/bin:\$PATH; $COMMANDS"

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




  


start_remote_host() {
}

copy_files() {
# Usage example : copy_files 'reduce-distribution/macbuild/' 'reduce-build/'
}

execute_in_dir() {
# Usage examople: execute_in_dir 'reduce-build/C' './autogen.sh'
}

fetch_from_dir() {
# Usage example: fetch_from_dir 'reduce-build' '*.dmg *.bz2' "snapshots/"
}

stop_remote_host() {
}


# Now do the work.
prepare
build "$@"


exit 77

###############################################################################
###############################################################################
###############################################################################
###############################################################################
###############################################################################
###############################################################################
###############################################################################
###############################################################################


# Next I will fire up a local virtualbox machine and use that. Note that
# this does just about the same steps apart from configuring the VM at the
# start so it does some port forwarding and then starting it up.

# If there is no existing port-forwarding rule called "ssh" then this
# command to delete it will fail and complain, but that is not a problem!
vboxmanage modifyvm REDUCE-pkg-factory-Ubuntu32 --natpf1 delete ssh 2> /dev/null
vboxmanage modifyvm REDUCE-pkg-factory-Ubuntu32 --natpf1 "ssh,tcp,,1001,,22"
vboxmanage startvm REDUCE-pkg-factory-Ubuntu32 --type headless

HOST=127.0.0.1
PORT=1001

sleep 5
for x in `seq 1 20`
do
  hello=`ssh -p $PORT $USER@$HOST printf "hello"`
  if test "x$hello" = "xhello"
  then
    break
  fi
  printf "Sleeping to allow Linux VM to start up...\n"
  sleep 30
done

rsync -vrlHpEPtzC -e "ssh -p $PORT" --delete --force \
  ./reduce-distribution/ \
  $USER@$HOST:reduce-remote-distribution/

ssh -p $PORT $USER@$HOST "cd reduce-remote-distribution; $COMMANDS"

# The power button causes the virtual machine to close down gracefully, but
# to keep things graceful it gives users 60 seconds notice...
vboxmanage controlvm REDUCE-pkg-factory-Ubuntu32 acpipowerbutton
sleep 65
# If I was confident that the user on the virtual machine has superuser
# authority without needing to quote a password I could save time by
# triggeting an instant shut-down.
# ssh -p $PORT $USER@$HOST "sudo /sbin/shutdown -h now"


# Another case is performing the build on a VM where the VM is hosted
# on a remote machine. Again this is a small modification of what I do
# in the other cases

ssh $USER@$HOST vboxmanage modifyvm REDUCE-pkg-factory-Ubuntu --natpf1 delete ssh 2> /dev/null
ssh $USER@$HOST vboxmanage modifyvm REDUCE-pkg-factory-Ubuntu --natpf1 "ssh,tcp,,1001,,22"
ssh $USER@$HOST vboxmanage startvm REDUCE-pkg-factory-Ubuntu --type headless

HOST=192.168.1.8
PORT=1001

sleep 5
for x in `seq 1 20`
do
  hello=`ssh -p 1001 $USER@$HOST printf "hello"`
  if test "x$hello" = "xhello"
  then
    break
  fi
  printf "Sleeping to allow Linux VM to start up...\n"
  sleep 30
done

rsync -vrlHpEPtzC -e "ssh -p $PORT" --delete --force \
  ./reduce-distribution/ \
  $USER@$HOST:reduce-remote-distribution/

ssh -p $PORT $USER@$HOST "cd reduce-remote-distribution; $COMMANDS"

ssh $USER@$HOST vboxmanage controlvm REDUCE-pkg-factory-Ubuntu acpipowerbutton
sleep 65
# ssh -p $PORT $USER@$HOST "sudo /sbin/shutdown -h now"


# Finally I will do a build locally

pushd reduce-distribution >/dev/null
eval $COMMANDS
popd >/dev/null

########################################


