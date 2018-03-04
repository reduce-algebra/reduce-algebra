#! /bin/bash -v

case `uname -s` in
*cygwin* | *CYGWIN*)
  d="fasl-win"
  ;;
*)
  d="fasl"
  ;;
esac

if test "$1" != ""
then
  d="$1"
fi

pushd $d

../bpsl --args -td 1000 <<EOF
(setq loaddirectories* '("" "fasl"))
(on verboseload)
(load init-file)
(load debug useful common)
(load numeric-ops)
(savesystem "New PSL" "psl" nil)
(exitlisp)
EOF

popd
