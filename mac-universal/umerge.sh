#! /bin/zsh

# This script scans the ARM and Intel specific files in their separate
# directories and merges and copies them into ${HOME}/ports in universal
# form. If given an argument "-force" it merges every known file

# It works on the basis that if a file has a later datestamp than that
# of the file "portstamp" it should be processed. This gets its time reset
# to the start of the century if "-force" is specified. It makes more
# noise if the "-verbose" flag is given. The two flags can be given in
# either order.

export PATH="/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin"
export PATH="$PATH:/Library/Apple/usr/bin"

# Important directory locations

HERE=`dirname "$0"`
HERE=`cd "$HERE"; pwd`
# Source file for MacPorts itself
SRC=$HERE/MacPorts-src
# Places to stage ARM and Intel material from ports that are fetched
ARMDEST=$HERE/ports/arm
INTELDEST=$HERE/ports/intel
# Location for universal versions of installed ports
DEST=$HOME/ports

export PATH=$DEST/bin:$PATH

verbose="no"

if test "$1" = "-verbose"
then
  verbose="yes"
  shift
fi
if test "$1" = "-force"
then
  touch -t 0001010000 $HERE/portstamp
  shift
fi
if test "$1" = "-verbose"
then
  verbose="yes"
  shift
fi


# I will use an associative table to keep track of which files I have
# installed.

typeset -A H

for f1 in `find $ARMDEST/bin \
    $ARMDEST/etc \
    $ARMDEST/include \
    $ARMDEST/lib \
    $ARMDEST/libexec \
    $ARMDEST/man \
    $ARMDEST/sbin \
    $ARMDEST/share \
    $ARMDEST/www \
    $INTELDEST/bin \
    $INTELDEST/etc \
    $INTELDEST/include \
    $INTELDEST/lib \
    $INTELDEST/libexec \
    $INTELDEST/man \
    $INTELDEST/sbin \
    $INTELDEST/share \
    $INTELDEST/www -newer $HERE/portstamp 2>/dev/null`
do
# Ensure that f1 is an absolute path (but do not mess with symbolic links).
  d1=`dirname "$f1"`
  f1=`cd "$d1"; pwd`/`basename "$f1"`
# The file will be in one of $ARMDEST or $INTELDEST but I do not know
# which so I strip whichever prefix I find.
  f="${f1#${ARMDEST}/}"
  if test "$f" = "$f1"
  then
    f="${f1#${INTELDEST}/}"
  fi
  f1="${ARMDEST}/$f"
  f2="${INTELDEST}/$f"
# I then check whether both ARM and Intel trees have that file.
  missing_arm="no"
  missing_intel="no"
  swapped="no"
  if ! test -e "$f1"
  then
    printf "$f1 missing\n"
    missing_arm="yes"
  fi
  if ! test -e "$f2"
  then
    printf "$f2 missing\n"
    missing_intel="yes"
  fi
# One of the files MAY be missing - I will ensure that $f1 exists.
  if test "$missing_arm" = "yes"
  then
    temp="$f1"
    f1="$f2"
    f2="$temp"
    swapped="yes"
  fi

# A merge will be triggered when either an ARM or an Intel file has been
# updated, but I want to deal with each case just once, so I set a marker
# the first time I find something.
  Hf=${H["$f"]}
  if test "$Hf" = "done"
  then
    continue
  fi
  H["$f"]="done" 
  printf "Will install $f\n"
  f3="${DEST}/$f"

# Now f1 is an absolute path to the source file (within ${ARMDEST}.
# f2 is the corresponding name within $(INTELDEST}, f3 is in ${DEST}
# and f is the leaf or common part of all of those.

  mkdir -p `dirname "$f3"`

# Now I have a bunch of varied behaviours based on the nature of the argument!

  if test -d "$f1"
  then
    if ! test -d "$f2"
    then
      printf "$f2 was expected to be a directory\n"
    fi
# When the item is just a directory I will merely create it.
    if test "$verbose" = "yes"
    then
      printf "$f1 is a directory\n"
    fi
    mkdir -p "$f3"
  elif test -L "$f1"
  then
    if ! test -L "$f2"
    then
      printf "$f2 was expected to be a symbolic link\n"
    fi
# For symbolic links I will copy the link itself, expecting it to to a
# relative reference, so I need to take care to preserve its status as
# a link and let where it refers to follow from the relativeness.
    if test "$verbose" = "yes"
    then
      printf "$f1 is a symbolic link\n"
    fi
    mkdir -p `dirname "$f3"`
    rm -rf "$f3"
    cp -PpR "$f1" "$f3"
  else
# If "lipo -archs" succeeds then the file is liable to be an object file
# or a native executable, and then I expect there to be a version for the
# "other" architecture available and that I can combine then into a single
# universal object file or executable.
    case `lipo -archs "$f1" 2>/dev/null` in
    *x86_64*arm64* | *arm64*x86_64*)
# Sometimes $f1 will already be universal, in which case it can be used as is
# and $f2 is in fact irrelevant.
      rm -rf "$f3"
      cp -PpR "$f1" "$f3"
      ;;
    *arm64* | *x86_64*)
      case `lipo -archs "$f2" 2>/dev/null` in
      *x86_64* | *arm64*)
        if test "$verbose" = "yes"
        then
          printf "$f1 and $f2 are libraries or executable\n"
        fi
        rm -rf "$f3"
        lipo "$f1" "$f2" -create -output "$f3"
        ;;
      *)
        printf "$f2 was expected to be a library or executable\n"
# If one file is executable but the other not I will just copy the
# executable one into place.
        rm -rf "$f3"
        cp -PpR "$f1" "$f3"
        ;;
      esac
      ;;
    *)
# Otherwise the file is probably a text file and it may be a script of
# some sort. In many cases it will have an initial line of the form
#    "#! $ARMDEST/interpreter
# for some interpreter - maybe perl, python, tcl, ...
# I edit any such to refer to the same program but in $DEST.
      if test "$verbose" = "yes"
      then
        printf "$f1 is a data file or script\n"
      fi
      rm -rf "$f3"
      sed -e "s+${ARMDEST}/+${DEST}/+g" < "$f1" > "$f3"
# I must preserve executable status...
      if test -x "$f1"
      then
        chmod +x "$f3"
      fi
      ;;
    esac
  fi
done

exit 0
