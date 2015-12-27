#! /bin/bash

# Small script to get me started creating a "dmg" disc image for
# distribution. Call as
#   ./makedmg.sh <snapshot-identity>
# where the identity will often be the date, such as 20100101 for 1 January
# 2016.

hdiutil create -volname Reduce-${1:-snapshot} \
  -srcfolder directory-with-app-in-it \
  -ov -format UDZO Reduce-${1:-snapshot}.dmg
