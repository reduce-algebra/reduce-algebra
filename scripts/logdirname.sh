#! /bin/bash

# The input is something like --csl or --csl=x86_64-pc-windows-debug

# Get rid of the initial "--" and any initial "--csl="
p="${1#--}"
p="${p#csl=}"
# Now the name may be like one of these
#   csl    csl-debug
#   x86-pc-windows{-options...}
#   aarch64-mac_12_monterey-darwinN.N.N{-options}
# and in many case I want to abbreviate it
case $p
in
x86_64-pc-windows*)
  p=${p#x86_64-pc-}
  ;;
x86_64-pc-cygwin*)
  p=${p#x86_64-pc-}
  ;;
aarch64-mac*-*-*)
  p=arm-mac-${p#aarch64-mac*-*-}
  ;;
aarch64-mac*-*)
  p=arm-mac
  ;;
x86_64-mac*-*-*)
  p=intel-mac-${p#x86_64-mac*-*-}
  ;;
x86_64-mac*-*)
  p=intel-mac
  ;;
universal-mac*-*-*)
  p=universal-mac-${p#universal-mac*-*-}
  ;;
universal-mac*-*)
  p=universal-mac
  ;;
*)
  ;;
esac
printf -- "$p"

