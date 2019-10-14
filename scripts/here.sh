# I want this script to be one I can launch from anywhere, but at least
# some of its sub-scripts will not be so generous. So find out where it
# lives so that other locations can be found relative to that.
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`
here=`dirname "$here"`
# As a special hack that makes things nicer on the Cygwin environment I set
# up for myself, if the path is of the form "/cygdrive/x/.." but I have gone
# "ln -s /cygdrive/x /x" (which I often have!) I return just "/x/.."
case "$here" in
/cygdrive*)
  short=`echo $here | sed 's+^/cygdrive++'`
  long=`readlink -f "$short"`
  if test "$long" = "$here"
  then
    echo $short
  else
    echo $here
  fi
  ;;
*)
  echo $here
  ;;
esac
