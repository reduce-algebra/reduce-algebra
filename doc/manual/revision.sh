#!/bin/sh

# Get the latest svn revision number of the current working directory
# and write it to "revision.tex".

rev=$(svnversion)
# Delete beginning of range if present:
rev=${rev##*:}
# Delete any trailing annotations:
rev=${rev%%[^0-9]*}
echo $rev > revision.tex
