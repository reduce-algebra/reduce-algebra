#! /bin/sh

# ensure script files in this directory have correct permissions

#
# Note
#  most scripts here are intended to be executed from a target architecture
#  directory, via a command such as
#       ../util/boot38.sh
#  but this one (setexec.sh) and "makes.bat" should be executed with
# this util directory current.

# chmod +x setexec.sh       but hard to do while being executed?

# full38.sh is the build script to use supposing that all the C code
# (in directory csl-c) has already been built. It is the only rebuild
# job needed in normal circumstances

chmod +x full38.sh

# testall.sh called on its own runs all known test scripts.
# If followed by a package name it just runs the test for that package.
# testrest is similar, except that it only updates logs that seem out of
# date.

chmod +x testall.sh
chmod +x testrest.sh

# checkall.sh produces a log (in log/checkall.log) of differences between
# the logs creates by testall.sh and reference ones. "checkall.sh XXX" produces
# a log that relates to just that one package.

chmod +x checkall.sh

#
# If (for any reason) you want to recompile just one package that forms
# part of REDUCE you can go
#   ../util/package.sh  <packagename>
# This will recompile such modules that are parts of the given package
# and whose source files are newer than the compiled versions stored
# within the REDUCE image file.  This may be useful if you have updated
# some of the source code. Note that if you add extra packages to REDUCE
# you will need to update the "package.red" file in the REDUCE root
# directory and follow the rukes about having a file for each package
# that identifies all of the other relevant source files.
#

chmod +x package.sh

#
# The next scripts are only needed if you want to rebuild everything
# from scratch. "boot38.sh" uses a "slowr38" executable and builds a
# bootstrap version of REDUCE. "testslow.sh" is like "testall.sh" but
# tests this version. "profile.sh" collects profile data, and then
# "c-code38.sh" compiles the hot-spot functions into C. "clash.sh" looks
# for places in the REDUCE source where two packages each define a
# function with the same name.
#

chmod +x boot38.sh
chmod +x testslow.sh
chmod +x profile.sh
chmod +x c-code38.sh

chmod +x clash.sh

# the "makeall.sh" script does all the above and provides a hands-free
# utterly complete reconstruction and test.

chmod +x makeall.sh

# end of setexec.sh script


