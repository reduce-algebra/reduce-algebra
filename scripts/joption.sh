#! /bin/sh
if test -f /proc/cpuinfo
then
  case `grep -i ^processor /proc/cpuinfo | wc -l`
  in
  1 | 2)
    ;;
  3 | 4)
    echo "-j2"
    ;;
  5 | 6)
    echo "-j4"
    ;;
  7 | 8 | 9 | 1* | 2* | 3* | 4* | 5* | 6*)
    echo "-j6"
    ;;
  *)
    ;;
  esac
fi
