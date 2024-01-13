#! /bin/sh

# alias.sh

# Used by test1.sh and testall.sh
#    scripts/alias.sh reduce-directory test-option
# reduce-directory is the main reduce directory
# test-option is one of the arguments to test1.sh or testall.sh
#  This detects various abreviations that I want to support for
# the testing script and displays the full form argument wanted. The
# precise range of cases may be altered over time by updating this
# script. Initial exampled include
#    --csl=windown              --csl=x86_64-pc-windows
#    --csl=cygwin               --csl=x86_64-pc-cygwin
#    --csl=mac-arm              )
#    --csl=mac-intel            ) relevant full versions
#    --csl=mac-universal        )
#    --csl=oldgc                --csl=$HOST-oldgc

here="$1"
# The version specified here can have its initial "--" either present or
# not. But what comes out will start with "--".
arg="${2#--}"

case "$arg"
in
"csl=windows")
  printf -- "--csl=x86_64-pc-windows"
  ;;
"csl=cygwin")
  printf -- "--csl=x86_64-pc-cygwin"
  ;;
"csl=mac-arm" | "csl=mac-aarch64")
# On the Mac I need to allow for changing releases of the operating
# system, so I search the cslbuild directory to see what makes sense.
# This picks up the alphabetically first case, but that is OK since it
# will be any "plain" build, so eg one with a suffix (say) "-debug" comes
# after it and is not the one picked up.
  p=`echo $here/cslbuild/aarch64-mac*`
  p=${p%% *}
  p=${p#*cslbuild/}
  printf -- "--csl=$p"
  ;;
"csl=mac-intel" | "csl=mac-x86_64")
  p=`echo $here/cslbuild/x86_64-mac*`
  p=${p%% *}
  p=${p#*cslbuild/}
  printf -- "--csl=$p"
  ;;
"csl=mac-universal")
  p=`echo $here/cslbuild/universal*`
  p=${p%% *}
  p=${p#*cslbuild/}
  printf -- "--csl=$p"
  ;;
# Now that the conservative GC is standard it may be useful to be
# able to revert to the old one in case of concerns.
"csl=oldgc")
  if test "$OS" = "Windows_NT"
  then
    p="x86_64-pc-cygwin-oldgc"
  else
    mc=`$here/config.guess`
    mc=`$here/scripts/findhost.sh $mc`
    p="$mc-oldgc"
  fi
  printf -- "--csl=$p"
  ;;
*)
  printf -- "--$arg"
  ;;
esac

# end of script
