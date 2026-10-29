#! /bin/bash

# Build the REDUCE web site, i.e. convert all PHP files to HTML.

# This requires the CLI version of PHP (see
# https://www.php.net/manual/en/features.commandline.php) to be
# installed locally and the command php to be on your PATH.

# This script must be run in the "web" directory of the REDUCE file tree.

# But it *must* run PHP in each subdirectory, not in this directory,
# hence we must use the find action -execdir, not -exec.

find htdocs -path 'htdocs/include' -prune -o \
     -path 'htdocs/web-reduce' -prune -o \
     -name '*.php' \
     -execdir bash -c 'php -f $0 > ${0%.php}.html' '{}' ';'
