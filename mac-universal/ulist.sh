#! /bin/zsh

# This script scans the ARM and Intel specific files in their separate
# directories and merges and copies them into ${HOME}/ports in universal
# form. If given an argument "-force" it merges every known file

# It works on the basis that if a file has a later datestamp than that
# of the file "portstamp" it should be processed. This gets its time reset
# to the start of the century if "-force" is specified. It makes more
# noise if the "-verbose" flag is given. The two flags can be given in
# either order.

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

verbose="no"

if test "$1" = "-verbose"
then
  verbose="yes"
  shift
fi
if test "$1" = "-force"
then
  touch -t 0001010000 $HERE/portstamp
  shift
fi
if test "$1" = "-verbose"
then
  verbose="yes"
  shift
fi


# I will use an associative table to keep track of which files I have
# installed.

typeset -A H

find $ARMDEST/bin \
    $ARMDEST/etc \
    $ARMDEST/include \
    $ARMDEST/lib \
    $ARMDEST/libexec \
    $ARMDEST/man \
    $ARMDEST/sbin \
    $ARMDEST/share \
    $ARMDEST/www \
    $INTELDEST/bin \
    $INTELDEST/etc \
    $INTELDEST/include \
    $INTELDEST/lib \
    $INTELDEST/libexec \
    $INTELDEST/man \
    $INTELDEST/sbin \
    $INTELDEST/share \
    $INTELDEST/www -newer $HERE/portstamp 2>/dev/null > files.dat

exit 0
