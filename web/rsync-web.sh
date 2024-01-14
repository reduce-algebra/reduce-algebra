#! /bin/bash

# Upload only necessary and changed files to the web server.

# -n means dry run; can specify as first command argument.

rsync -vrutC $* --chmod=D755,F644 --exclude-from=.rsync-exclude '.' \
      'fjwright@web.sourceforge.net:/home/project-web/reduce-algebra/'
