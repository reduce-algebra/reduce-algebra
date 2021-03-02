#! /bin/sh -v

# This script builds two copies of macports, one for Intel and one for
# ARM. Both are built in the user's home directory (in $ARMDEST and
# $INTELDEST). It sets up trivial scripts in $DEST (ie $HOME/ports/bin)
# such that
#     arm CCCC
# obeys the command CCCC using an arm processor with the ARM version
# of macports available, and intel equivalently. It also sets up a command
# there so that
#     uinstall port1 port2 ...
# should build both ARM and Intel versions of the names ports an merge them
# into universal material also in $DEST.

# Even if you had MacPorts or other specialities installed already this
# script wants to run as if on a clean setup, so I reset PATH. If other
# key environment variable are defined that could hurt it, so beware!

# In general you are only expected to run this script once. To maintain
# ports you can use "uupgrade", which runs "port selfupdate" in both ARM and
# Intel worlds, then "port upgrade outdated" in each and finally merges
# packages that were upgraded in the ARM world to universal versions.

export PATH="/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin"
export PATH="$PATH:/Library/Apple/usr/bin"

# Important directory locations

HERE=`dirname "$0"`
HERE=`cd "$HERE"; pwd`
# Source file for MacPorts itself
SRC=$HERE/MacPorts-src
# Places to stage ARM and Intel material from ports that are fetched
ARMDEST=$HERE/ports/arm
INTELDEST=$HERE/ports/intel
# Location for universal versions of installed ports
DEST=$HOME/ports

# Start by fetching MacPorts source and unpacking it
curl -O https://distfiles.macports.org/MacPorts/MacPorts-2.6.4.tar.bz2
tar xf MacPorts-2.6.4.tar.bz2

# Get directories set up nicely
ln -s MacPorts-2.6.4 MacPorts-src
mkdir -p $ARMDEST
mkdir -p $INTELDEST
mkdir -p $DEST/bin
# Patch your .zprofile to put $DEST on your PATH and activate that now.
if ! grep $DEST/bin $HOME/.zprofile 2> /dev/null
then
   printf "PATH=$DEST/bin:$DEST/sbin:\$PATH\n" >> $HOME/.zprofile
fi
PATH=$DEST/bin:$PATH


compile_macports () {
# The argument will explain whether an ARM or Intel build is being
# performed here.
  case $1 in
  arm)
    name=arm
    type=arm64
    rm -rf $ARMDEST
    DEST1=$ARMDEST
    ;;
  intel)
    name=intel
    type=x86_64
    rm -rf $INTELDEST
    DEST1=$INTELDEST
    ;;
  *)
    printf "Bad type $1"
    exit 1
    ;;
  esac

# I might have liked to build other than in the source directory, but
# that appears not to be supported by the MacPorts build scripts. Any
# comments like this relate to one particulat snapshot of MacPorts and
# some may reflect mistakes I have made, so the way I do things here could
# in fact be just over-cautious.

  cd $SRC

  arch -arch $type sh <<-EOF

        CFLAGS="-pipe -Os" ./configure \
            --enable-readline \
            --with-no-root-privileges \
            --with-install-user=$USER \
            --with-install-group=staff \
            --with-shared-directory \
            --without-startupitems \
            --prefix=$DEST1 \
            --with-applications-dir=$DEST1/Applications \
            --with-frameworks-dir=$DEST1/Frameworks
            --without-startupitems

# Now I have a Makefile I can do a cautious tidy up so I ensure that
# everything gets built this time (and hence for the current target
# architecture).
      make clean
# Have also had trouble if I try "make install" without having done
# a simple "make" first, hence doing things in two steps.
        make
        make install
# Tidy up the distribution directory after all I have done
        make distclean
# Note that there is a TAB not a bunch of spaced ahead of the "EOF" here
# since that is what "<<-EOF" requires.
	EOF

  if test "$name" = "intel"
  then
     printf "macosx_deployment_target 10.13\n" \
        >> $DEST/etc/macports/macports.conf
  fi
  if test "$name" = "arm"
  then
     printf "macosx_deployment_target 11.0\n" \
        >> $DEST/etc/macports/macports.conf
  fi
}


compile_macports arm
compile_macports intel

# I now create several commands in $DEST/bin (ie $HOME/ports/bin), the
# directory you will have on your path:
#
#    arm CCCC                Obey CCCC in ARM mode (ie naturally!).
#    intel CCCC              Obey CCCC using Rosetta-2 in Intel mode.
#    uinstall portnames      Run macports twice, once in ARM mode and
#                            once in x86_64 mode for each port mentioned
#                            and then use lipo to merge the generated
#                            material into what should be universal versions
#                            within $DEST.
#    uupgrade                Update macports itself and its catalogue of
#                            ports and then refresh any current ports that
#                            are out of date.
# see also
#    clean.sh                discard everything ready for a fresh start
#    umerge.sh               consolidate ARm and Intel builds to form
#                            universal versions. This is used at the end of
#                            uinstall and uupgrade. If run manually after one
#                            of those it re-merges recently updated things,
#                            If give the argument "-force" it merges every
#                            file that it can find related to ports.

printf "#!/bin/sh\n" > $DEST/bin/arm
printf "export PATH=$ARMDEST/bin:\$PATH\n" >> $DEST/bin/arm
printf "arch -arch arm64 \$*\n" >> $DEST/bin/arm
chmod +x $DEST/bin/arm

printf "#!/bin/sh\n" > $DEST/bin/intel
printf "export PATH=$INTELDEST/bin:\$PATH\n" >> $DEST/bin/intel
printf "arch -arch x86_64 \$*\n" >> $DEST/bin/intel
chmod +x $DEST/bin/intel

printf "#!/bin/sh\n" > $DEST/bin/uport
printf "$HERE/uinstall.sh \$*\n" >> $DEST/bin/uinstall
chmod +x $DEST/bin/uinstall

printf "#!/bin/sh\n" > $DEST/bin/uupgrade
printf "$HERE/uupgrade.sh \$*\n" >> $DEST/bin/uupgrade
chmod +x $DEST/bin/uupgrade

uupgrade

# end of script
