#! /bin/sh

# This script does some of the work of setting up a Macintosh to be
# ready to create regular snapshots of Reduce.
# It assumes that the checkout of Reduce that it is within is either one
# checked out using "svn:" or if it is "ssh+svn:" style that the relevant
# password is saved so that "svn update" will not ask for a password or
# any other information.

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`

# I will REQUIRE three vmware virtual machines, "REDUCE-pkg-factory-Windows",
# "REDUCE-pkg-factory-Ubuntu" and "REDUCE-pkg-factory-Ubuntu32".
# They must be set up using NAT networking with the Windows one forwarding
# local port 2201 to its port 22, 64-bit linux one forwarding port 2202 and
# 32-bit linux on port 2203. That gets set up using the "advanced" option
# within the virtualbox network setup when you select NAT networking, and
# you just add an entry that specifies host port (eg) 2201 and guest port 22.

# Each virtual machine must have a proper set of development tools suitable
# for building Reduce, plus Latex for building the manual and "inno setup" on
# windows and a collection of package maintenance tools on Linux (eg
# debianscripts, alien, rpm). For the Linux systems the commands in
# scripts/ubuntu-sanity-check.sh may help. For Windows you can start with
# scripts/cygwin-sanity-check.sh but to build documentation you need
# latex and some other packages: the easiest way to get the Windows setup
# complete would be to install; all the "publishing" modules that cygwin
# offers.
#
# The Mac host must have client SSH keys, while the virtual machines must
# each run an SSH server and must have .ssh/authorized_keys including the
# client public keys from the Macintosh host. These client keys must not
# use a pass-phrase, so that ssh from the macintosh to the VM should happen
# without need for any extra authentication or interaction.
# Eg on the host
#    ssh-keygen -t ecdsa
# and give an empty passphrase and save the key in the regular place. Then
# something like
#    scp -p 2201 .ssh/id_ecdsa.pub localhost:.ssh/authorized_keys
#
# If all that is in place then the Macintosh host should be able to use
#    vboxmanage startvm windows -type headless
#    sleep 60
#    ssh -p 2201 localhost uname -a
# and get confirmation that the machine works (once it has had time to start
# up)

# The file scripts/crontab.entry is a template and "@@@" has to be replaced
# by the name of the directory that the script will be in. This should do the
# trick.

sed -e "s+@@@+$here+" < $here/crontab.entry | crontab


# end of script

