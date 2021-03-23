#! /bin/sh

# This will first go "port install" on all its arguments but in both
# ARM and Intel environments,
# It will then try to merge files build for ARM with the corresponding
# version built for Intel put the results in ${HOME}/ports

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

export PATH=$DEST/bin:$PATH

rm -f $HERE/portstamp
touch $HERE/portstamp
sleep 1

verbose="no"
if test "$1" = "-v"
then
  verbose="yes"
  shift
fi

for p in $*
do
# I can install the ARM and Intel variants in parallel, and that may
# save a useful amount of time.
  ( arm port clean $p
# If the package or anything that it depends on is already installed then
# the date-stamp procedure I use later on will not re-process the existing
# files. If ARM and Intel builds had different dependencies or created
# different sets of files I would be in difficulty!
#
# I use the "-N" option so that dependencies are installed without asking
# the user whether that is wanted.
#
   arm port -N install $p ) &
  task=$!
  intel port clean $p
  intel port -N install $p
  wait $task
done

${HERE}/umerge.sh

exit 0
