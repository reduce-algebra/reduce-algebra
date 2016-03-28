#! /bin/sh -v

# scripts/macports.sh
#
# This script assumes that MacPorts has already been installed and that
# relevant changes have been made to your PATH so that it is ready for use.
# I hope you have gone "sudo port selfupdate" recently too.
# Given that it used "port install" to install a bunch of packages. The list
# here is intended to be such that once these have all been built and
# installed the things that they depend on will also have been installed
# and the result will be an environment in which Reduce can be built.
# Despite this list seeming fairly modest I find that in all I end up with
# just over 300 installed ports. Fetching and building them all is an
# overnight task!
#
# Some of the ports listed here are not essential for building Reduce, but
# I want them for one reason or another. Here is a short commentary on some
# of the ones you might most notably question. I note that their presence in
# the list here may also be for the things they depend on, so removing things
# you think you do not need might mean you lose other things you do need!
#
# astyle      Can be used to re-format C++ code, and I use it on the
#             CSL sources.
# autoconf-archive,
# autoconf213 I believe that having lots of versions of autoconf/automake
#             helps with portability of build sequences! 
# bc          used by scripts/testall.sh 
# dvipng      used to re-make documentation
# findutils   I count them as useful
# fontforge   I use this when checking fonts during development
# gdb         Invaluable following a bad crash
# git         Useful to access projects that use git not subversion!
# gnome-system-monitor Apart from the fact that I like this as a tool
#             to review system load etc, installing it causes port to
#             install many X11-related packages that I need.
# gnuplot     Used by Reduce for plotting
# gnutar      Probably not needed?
# gzip        For packing and unpacking things I wish to ship elsewhere
# md5sha1sum  For checking integrity of files I copy
# netpbm      Used for documentation
# polyml      My experiment with an ML implementation of TeX layout
#             algorithms needs this.
# psutils,
# subversion  a newer version than the one that comes with OSX/Xcode
# TeX stuff   For building documentation
# vim         Some of you may want emacs (too?)
# wget        For fetching stuff from elsewhere.

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`cd \`dirname "$here"\` ; pwd -P`

save=`pwd`
cd $here

# First I intend to check if macports.conf is set up the way I want it!
# If it is then it should have the following two lines present:
#   macosx_deployment_target 10.10
#   buildfromsource always

conf=/opt/local/etc/macports/macport.conf
if ! test -f $conf || \
   ! grep macosx_deployment_target $conf > /dev/null || \
   ! grep "buildfromsource always" $conf > /dev/null
then
  printf "macport.conf seems not to exist, or does not contain the lines\n"
  printf "   macosx_deployment_target 10.10\n"
  printf "   buildfromsource always\n"
  printf "Please correct that and try again.\n"
  exit 1
fi

sudo port install          \
  astyle                   \
  autoconf                 \
  autoconf-archive         \
  autoconf213              \
  automake                 \
  bc                       \
  dvipng                   \
  findutils                \
  fontforge                \
  gdb                      \
  git                      \
  gnome-system-monitor     \
  gnuplot                  \
  gnutar                   \
  gzip                     \
  md5sha1sum               \
  netpbm                   \
  pkgconfig                \
  polyml                   \
  psutils                  \
  subversion               \
  texlive-fonts-extra      \
  texlive-htmlxml          \
  texlive-latex-extra      \
  vim                      \
  wget

# MacPorts installs most stuff nicely, but at the time of writing
# (January 2016) it does not generate a libfontconfig.a and I want one.
# This next step fixes up for that! It is ugly but expedient. It is
# required so that the Reduce binary I create does not include dynamic
# links against libraries that it needs to have in /opt/local/lib. If
# it did depend on the dynamic libraries then the binary would not work
# if copied to a different computer that dis not have all the MacPorts
# stuff installed.

cd $here/../csl/cslbase
./make-static-fontconfig-for-macintosh.sh

cd $save

exit 0
# end of script
