#! /bin/bash

# This is a private script used by ACN, but is put here so that it can be
# copied to other directories and adapted. It fetches files from a
# remote computer to the current one, omitting backups and version control
# administrative stuff. It may be useful while testing stuff before it is
# checked in to a central repository. The messy ad hoc test on its
# parameter is so that I can invoke it without giving any arguments at all
# on the two machines I use most and in each case it will then fetch
# from the other! When used manually remember to put a "/" after the
# name of the directory that you are fetching from.

src="$1"

if test "$src" = ""
then
  if test `uname -n` = "panamint"
  then
    src="acn1@gauguin.trin.cam.ac.uk:\$O/vsl/"
  fi
  if test `uname -n` = "gauguin"
  then
    src="acn1@codemist.dynu.com:\$O/vsl/"
  fi
fi

rsync -rC --info=stats2 $src ./

# end of script
