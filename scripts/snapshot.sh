#! /bin/bash
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`
here=`dirname "$here"`

main() {
  mc=`uname -s`
  case $mc in
  *Linux*)
    linux_snapshot
    ;;
  *CYGWIN*)
    windows_snapshot
    ;;
  *Darwin*)
    macintosh_snapshot
   ;;
  *)
   printf "Snapshot for $mc not implemented yet\n"
   exit 1
   ;;
  esac
}

linux_snapshot() {
  printf "Start to create Linux snapshot\n"
  exit
Here are the steps from "debianbuild"
(1) record the data to be part of the name of the snapshot
(2) Add a few lines to reduce/debian/changelog
(3) Sort out the host-triple relevant for the current system.
(4) Get a clean source in $BUILDTOPDIR (used to be "C")
(5) run autogen.sh on it
(6) delete reduce-source-$DATE
(7) cd reduce; debuild ...
    This does a LOT. IN particular it is where all the building of
    Reduce gets triggered.
(8) for each *.deb convert to .rpm format
(9) delete TARDEST directory, and copy a load of files into it
    and then tar it up.
}

windows_snapshot() {
  printf "Start to create Windows snapshot\n"
}

macintosh_snapshot() {
  printf "Start to create Macintosh snapshot\n"
}


main "$@"

exit

