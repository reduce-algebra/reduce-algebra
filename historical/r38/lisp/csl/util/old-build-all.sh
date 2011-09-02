#! /bin/sh -v
#
# This is a script for rebuilding a CSL-based Reduce system in either
# a release or development world.
#.
# The INTENT is that this should run under a fairly vanilla version of
# the "sh" Bourne shell, but it will be developed and mostly tested
# on systems where the real shell in place is "bash"...


#*****************************************************************************
# A first major part of this file will be used to define shell functions
# that do the work. Skip to a line make almost all of stars to find the
# logic of this script...


#=============================================================================
find_directory() {
# Find the directory that this script was called from.
# I expect that $0 to this script will give me the name of the current script.
# This will be interpreted in the way bash (and perhaps other shells) find
# commands:
# If the name does not contain a "/" it is expected that $PATH contains
#     a directory with an executable file of that name in it;
# If the name starts with a "/" it is an absolute path;
# In remaining cases it is relative to the current working directory.
#
# Given the above rules I can convert the name to give me an absolute
# path... I do a minor tidy-up involving commands called "./something"
# in that I remove the "./" when it is unnecessary.

# I will use single-letter shall variable names for temporary work-space and
# longer clearer names when I end up with something worth keeping.

  a=$1
  c=unknown
  case $a in
  /* )
    c=$a
    ;;
  */* )
    case $a in
    ./* )
      a=`echo $a | sed -e 's/\.\///'`
      ;;
    esac
    c=`pwd`/$a
    ;;
  * ) 
    for d in $PATH
    do
      if test -x $d/$a
      then
        c=$d/$a
      fi
    done
    ;;
  esac

# The error case here ought never to arise...

  case $c in
  unknown )
    echo "Unable to find full path for script. Please re-try"
    echo "launching it using a fully rooted path."
    exit 1
    ;;
  esac

  echo Full path of script is $c

# Now I want the directory that this script is in. So I remove the
# tail of its full name, from the final "/" to the end of the string.

  csl_directory=`echo $c | sed -e 's/\/[^/]*$//'`
  lisp_directory=`echo $csl_directory | sed -e 's/\/[^/]*$//'`
  reduce_directory=`echo $lisp_directory | sed -e 's/\/[^/]*$//'`
  echo reduce_directory = $reduce_directory
  return
}


#=============================================================================
get_fox_checksum() {
# This finds a checksum for the FOX sources.
  r=$reduce_directory
# The files passed through md5sum here are an attempt to identify all the
# ones in the support-packages directory that could have a big effect on
# FOX. So there is the source archive for the whole of FOX, the set of local
# patches that I apply to it and the shell scripts used to compile it.
# By checking all of these it will be the case that if (say) the script to
# compile FOX on windows-64 is altered then FOX will get flagged as in need
# or re-compilation on all platforms.

# This function will only ever be called if the build-all.sh file exists and
# so it is guaranteed that md5sum gets at least one argument here.
  new_fox_signature=`md5sum $r/support-packages/fox*.gz \
    $r/support-packages/*.patches \
    $r/support-packages/build-all.sh \
    $r/support-packages/build-fox*.sh | md5sum | sed -e 's/ .*$//'`

# A previous version of the signature for FOX may be present in a shell
# scrip in this directory. Pick it up...
  old_fox_signature="no_old_signature_of_FOX_source_found"
  if test -x $csl_directory/fox_signature.sh
  then
    . $csl_directory/fox_signature.sh
  fi

  echo "FOX signatures: " $old_fox_signature " and " $new_fox_signature
  return
}


#=============================================================================
save_fox_checksum() {
# Create a shell script that locally saves the signature for FOX sources.
  echo "#!/bin/sh" > $csl_directory/fox_signature.sh
  echo "old_fox_signature=\"$new_fox_signature\"" >> $csl_directory/fox_signature.sh
  echo "export old_fox_signature" >> $csl_directory/fox_signature.sh
  chmod +x $csl_directory/fox_signature.sh
  return
}

#=============================================================================
get_fox_binary_checksum() {
# This finds a checksum for the FOX binaries.
  r=$reduce_directory

  if test X"`cat fox/include/*/fxver.h 2>/dev/null`" = "X"  
  then
    new_fox_binary_signature="no_installed_fox_found"
  else
    new_fox_binary_signature=`md5sum $r/fox/lib/* \
      $r/fox/include/*/*.h | md5sum | sed -e 's/ .*$//'`
  fi

  old_fox_binary_signature="no_old_signature_of_an_installed_FOX_found"
  if test -x $csl_directory/fox_binary_signature.sh
  then
    . $csl_directory/fox_binary_signature.sh
  fi

  echo "FOX binary signatures: " $old_fox_binary_signature " and " $new_fox_binary_signature

  return
}


#=============================================================================
save_fox_binary_checksum() {
# Create a shell script that locally saves the signature for FOX sources.
  echo "#!/bin/sh" > $csl_directory/fox_binary_signature.sh
  echo "old_fox_binary_signature=\"$new_fox_binary_signature\"" >> $csl_directory/fox_binary_signature.sh
  echo "export old_fox_binary_signature" >> $csl_directory/fox_binary_signature.sh
  chmod +x $csl_directory/fox_binary_signature.sh
  return
}

#=============================================================================
get_autoconf_checksum() {
# This finds a checksum for autoconf-related files
  c=$csl_directory/cslbase
  m=$csl_directory/$machine

# I do not include the ".deps" directory in the checksum here, nor
# all other files like config.log etc. But the files that
# I do check here should be a pretty convincing way of telling that
# the system is "configured".
  if test -f $m/config.h && \
     test -f $m/Makefile
  then
    new_autoconf_signature=`md5sum $c/configure.ac \
      $c/Makefile.am \
      $c/Makefile.in \
      $c/aclocal.m4 \
      $c/config.h.in \
      $c/configure \
      $m/config.h \
      $m/Makefile | md5sum | sed -e 's/ .*$//'`
  else
    new_autoconf_signature="some_autoconf_files_are_missing"
  fi

  old_autoconf_signature="no_old_autoconf_signature_found"
  if test -x $csl_directory/autoconf_signature.sh
  then
    . $csl_directory/autoconf_signature.sh
  fi

  echo "Autoconf signatures: " $old_autoconf_signature " and " $new_autoconf_signature

  return
}


#=============================================================================
save_autoconf_checksum() {
# Create a shell script that locally saves the signature for FOX sources.
  echo "#!/bin/sh" > $csl_directory/autoconf_signature.sh
  echo "old_autoconf_signature=\"$new_autoconf_signature\"" >> $csl_directory/autoconf_signature.sh
  echo "export old_autoconf_signature" >> $csl_directory/autoconf_signature.sh
  chmod +x $csl_directory/autoconf_signature.sh
  return
}

#*****************************************************************************

# STEP 0: record my current working directory wherever that is.
initial_directory=`pwd`

# STEP 1: identify file directory and system architecture.

find_directory $0

# The "config.guess" script finds a GNU-style triple to identify the
# machine being used. Eg "i686-pc-cygwin". The script us inder the GNU
# license but with a special excepotion that if it is distributed along 
# with a program that contains a configuration script generated by
# Autoconf it can be distributed under the terms that apply to that
# program. In this instance the program concerned is CSL.

# It may be that I could just use a built-in shell variable $MACHTYPE
# here. But if that was generally possible why whould autoconf supply
# config.guess?

machine=`/bin/sh $csl_directory/cslbase/config.guess`

echo machine=$machine

# STEP 2: see if FOX has changed

# If the file build-all.sh does not exist then it is clear
# that the FOX sources and build scripts have not been
# downloaded, so there is not point in trying to fuss about
# wjhether it needs building or rebuilding

if test -f $reduce_directory/support-packages/build-all.sh
then
  get_fox_checksum
  get_fox_binary_checksum

# I need to build FOX if EITHER the sources for FOX have been updated or
# if this is the first time and it is not in place.
  if test $old_fox_signature != $new_fox_signature || \
     test $old_fox_binary_signature != $new_fox_binary_signature
  then
# A situation that is probably BAD is that at present to rebuild FOX I
# need to set my support-packages directory as current. So here I go.
# That is something that I should perhaps review in my FOX build
# scripts. A further issue (to be addressed in the same place) is that
# at present FOX is built in the same place whatever architecture you build
# on, so a cluster of different architectures with a shared file-system
# would not be supported well.

    cd $reduce_directory/support-packages
# In case any of the script files are not marked as executable I will
# force things. File transfer might have lost permissions.
    chmod +x *.sh
    echo "+++ about to recompile FOX"
    echo "    Please be aware that this can take a while"
    echo "    A log will be in $reduce_directory/log/fox.log"
    if test ! -d $reduce_directory/log
    then
      mkdir $reduce_directory/log
    fi
# Here I attempt to re-compile all of FOX. If that process returns with
# a clean return-code I will record checksums that identify the
# state of both the FOX source directory and the one into which a
# built version has been installed. But if the build fails I will not
# update those recorded checksums, and so I expect that future uses of
# this script will re-do the compilation. Eventually with luck it will
# succeed!
    . ./build-all.sh $machine > $reduce_directory/log/fox.log 2>&1 && \
      save_fox_checksum && \
      save_fox_binary_checksum
  fi
# The above is only done if there is some reason to believe that FOX
# sources are present...
fi

cd $csl_directory

# STEP 3: ensure that a directory exists to build the system in. Make it
#         the current directory and get a Makefile in there.

if test -f $machine
then
  if test ! -d $machine
  then
    rm $machine
  fi
fi

if test ! -d $machine
then
  mkdir $machine 
fi

cd $machine

c=$csl_directory/cslbase

if test ! -f $c/configure.ac || \
   test ! -f $c/Makefile.am || \
   test ! -f $c/Makefile.in || \
   test ! -f $c/aclocal.m4 || \
   test ! -f $c/config.h.in || \
   test ! -f $c/configure
then
  echo "Some autoconfig-related files are not present in the CSL"
  echo "source directory. Please update it and try again."
  exit 1
fi

get_autoconf_checksum

if test $old_autoconf_signature != $new_autoconf_signature
then
# I had tried $csl_directory/cslbase/configure here, but that binds in
# an absolute path for the CSL source directory. That will be just fine
# on Linux/Unix/MacOS, but on Windows I build under Cygwin and then I can
# find that Cygwin and Native (absolute) paths are not compatible with one
# another. And the result can be horrid. Specifically during the build
# process I run a program called "objtype" that I build, and it needs 
# to interpret the paths. A relative one is easier for it...
#
# I also want to detect $1=--with-xp64 and then configure for xp64!
  ../cslbase/configure $1 --with-fox=$reduce_directory/fox/$machine &&
  save_autoconf_checksum
fi

# STEP 3:
#
# Well what I will do now is to do a full cold expensive rebuild of
# utterly everything from scratch, just to be on the safe side.

if test -f $csl_directory/util/config.lsp
then
  rm $csl_directory/util/config.lsp
fi

if test -f $csl_directory/util/devconfig.lsp
then
  rm $csl_directory/util/devconfig.lsp
fi

case $1 in
--with-xp64 )
  echo "No attempt to re-create C code here..."
  make r38
  ;;
* )
# Well pragmatically right now I will NOT run the profile job
# every time. It takes too long. But re-creating the C code from Lisp
# is fairly cheap and should be safe.

  make slowr38.img
  #make profile
  #make prof-inst
  make c-code

  make r38.img
  ;;
esac

# FINALLY: restore the initial working directory and display a message
#          of triumph.

echo r38 built in $csl_directory/$machine

cd $initial_directory
exit 0

# end of arthurs-script.sh
