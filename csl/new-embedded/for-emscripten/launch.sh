#! /bin/sh -v   

if test "$1"=""
then
  case $OS in
  Windows_NT)
    browser="c:/Program Files/Mozilla Firefox/firefox.exe"
    ;;
  *)
    browser="firefox"
    ;;
  esac
else
  browser="$1"
fi

python3 -m http.server &
PY=$!
"$browser" localhost:8000/toplevel.html 
echo PY=$PY

exit 0
