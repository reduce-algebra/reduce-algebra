#! /bin/sh

# This is rather like going "port selfupdate; port upgrade outdated"
# but for maintaining in a universal setup.

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

arm port selfupdate
arm port upgrade outdated
intel port selfupdate
intel port upgrade outdated

${HERE}/umerge.sh

exit 0
