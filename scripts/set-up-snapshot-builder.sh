#! /bin/sh

# This script does some of the work of setting up a Macintosh to be
# ready to create regulat snapshots of Reduce. It ararnges that a
# copy of Reduce is checked out in $HOME/reduce-distribution (that is
# not where I normally put it because I want this to be a copy that
# is checked out without a password and I want it to be one that I will
# never build or edit other than via the scripts managed here).

if ! test -d $HOME/reduce-distribution
then
  svn co svn://svn.code.sf.net/p/reduce-algebra/code/trunk reduce-distribution
fi

# I will REQUIRE three vmware virtual machines, "windows", "linux" and
# "linux32".
# They must be set up using NAT networking with the Windows one forwarding
# local port 2201 to its port 22, linux one forwarding port 2202 and linux32
# port 2203.

# Each virtual machine must have a proper set of development tools suitable
# for building Reduce, plus Latex for building the manual and "inno setup" on
# windows and a collection of package maintenance tools on Linux (eg
# debianscripts, alien, rpm). For the Linux systems the commands in
# scripts/ubuntu-sanity-check.sh may help. For Windows you can start with
# scripts/cygwin-sanity-check.sh but to build documentation you need
# latex and some other packages.
#
# The Mac host must have client SSH keys, while the virtual machines must
# each run an SSH server and must have .ssh/authorized_keys including the
# client public keys from the Macintosh host. These client keys must not
# use a pass-phrase, so that ssh from the macintosh to the VM should happen
# without need for any extra authentication or interaction.
#
# If all that is in place then the Macintosh host should be able to use
#    vboxmanage startvm windows -type headless
#    sleep 60
#    ssh -p 2201 localhost uname -a
# and get confirmation that the machine works (once it has had time to start
# up)

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`pwd -P`

crontab $here/crontab.entry

rm -f $HOME/croncheck.sh
rm -f $HOME/croncheck1.sh
rm -f $HOME/croncheck.dat
rm -f $HOME/make-now.sh

ln -s $here/croncheck.sh $HOME
ln -s $here/croncheck1.sh $HOME
ln -s $here/croncheck.dat $HOME
ln -s $here/make-now.sh $HOME

# end of script

