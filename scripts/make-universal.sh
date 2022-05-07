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

# Having any partially-built ports in a confused state could hurt, so
# tidy up first.
port clean installed

all=`port installed installed | grep active | tail -n +2 | sed -e 's/@.*$//g'`
failures=""
for P in $all
do
  if port installed $P | grep "universal.*active" >/dev/null
  then
    continue
  fi
  if port variants $P | grep "universal:" > /dev/null
  then
    printf "$P is not universal yet but could be\n"
  else
    continue
  fi
  if test "$what" != "yes"
  then
    port -N clean --all $P rdepof:$P
    if ! port -N install $P +universal
    then
      failures="$failures $P"
    fi
  fi
done

if test "$failures" != ""
then
  printf "\n\nFailed: $failures\n"
fi

