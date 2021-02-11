#! /bin/sh -v   

# This starts up a web-server that serves from the current directory
# and records its process identifier in the file "http.pid". If that file
# exists and contains a valid process number (even if the number is not
# of our web-server!) it assumes that is already running, so in dire case
# one should remove that file.

# It then launches a web-browser pointing at port 8000 (which is the one that
# the python web server uses). By default it uses firefox but if it is
# given an argument that specifies what to use.

# For the moment you then need to type "ctrl-shift-i" in the browser window
# to access developer tools there, and possibly select the tab that shows
# the javascript console.

# As of early February 2021 I have seen this start to work on Linux but on
# Windows there is still some issue....


HTTP_ACTIVE="no"
PID=`cat http.pid 2> /dev/null`
if test "$PID" != ""
then
  if ps -p $PID 1>/dev/null 2>/dev/null
  then
    HTTP_ACTIVE="yes"
  fi
fi
if test "$HTTP_ACTIVE" != "yes"
  then
  python3 -m http.server &
  echo $! > http.pid
fi

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

"$browser" localhost:8000/MathLiveTests.html

exit 0
