#! /bin/bash

# Attempt to get all ports upgraded to +universal
# If the "-what" option is provided it just reports which might
# be possible.

case ${1:-nothing} in
*what*)
  what="yes"
  ;;
*)
  what="no"
  ;;
esac

all=`port installed installed | grep active | tail -n +2 | sed -e 's/@.*$//g'`
failures=""
for p in $all
do
  if port installed $p | grep "universal.*active" >/dev/null
  then
    continue
  fi
  if port variants $p | grep "universal:" > /dev/null
  then
    printf "$p is not universal yet but could be\n"
  else
    continue
  fi
  if test "$what" != "yes"
  then
    if ! port -N install $p +universal
    then
      failures="$failures $p"
    fi
  fi
done

if test "$failures" != ""
then
  printf "\n\nFailed: $failures\n"
fi


