#! /bin/bash

# ******* E X P E R I M E N T A L *******

# This starts from pre-configured cygwin and windows directories in
# windows-config-cache and copies from those into cslbuild so that
# Reduce can be built using them. I provide this in part because
# running "./configure" on Windows under cygwin is amazingly time
# consuming, to a large extent because Windows does not support "fork()"
# while autoconf-generated scripts rely on the simulation of if.

# This first version just sets up the default style of CSL-Reduce - at
# a later stage I will want to extend this to cover selected options
# such as ones for debugging.

# It would defeat purposes if a first use of the material installed here
# triggered a re-run of the configure scripts, so I touch everything
# in the reference copy that is called "Makefile". 

find windows-config-cache -name Makefile | xargs touch

# When I use "make" in the main tree it detects which sub-directories it
# may make sense to process by checking for an executable file "canary[.exe]"
# and here I regenerate that in each directory I am about to copy. Doing that
# means that the subversion repository does not need to hold copies of those
# silly executables.

for x in windows-config-cache
do
  gcc canary.c -o $x/canary
done

# When I copy I take care to preserve timestamps.
cp -p -r windows-config-cache/* cslbuild

# The file "profile.dat" is not Windows-specific but is also needed.
mkdir -p cslbuild/generated-c
cp csl/generated-c/profile.dat cslbuild/generated-c

# It should now be the case that "make" in the main directory will
# build the Windows versions.


################
# Issue - the simple-build reference directories will have the location on
# the computer that they were built on embedded. My next task is to set up
# scripts that avoid that by converting for use of relative paths.
