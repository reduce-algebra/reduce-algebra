                           here.sh and friends


Most of the scripts here start with a few lines of obscure-looking shell
scripting using "dirname" and "sed". This note is to explain what is going
on and to try to explain the intent, working and limitations of those
lines.

There are typically comments:
  # I want this script to be one I can launch from anywhere, but at least
  # some of its sub-scripts will not be so generous. So find out where it
  # lives so that other locations can be found relative to that.
that provide a basic explanation.

If there is a file in ..../trunk/scripts such as testall.sh or one in
..../trunk/bin such as redcsl or redpsl then people may wish to launch
that when they have an arbitrary directory set as current. There are at
least three use-cases:
 (1) They have put ..../trunk/bin in their PATH so they just go "redcsl"
     or whatever and the script is found in the standard way.
 (2) They have set up a symbolic link (eg by going
         ln -s ..../trunk/bin/redpsl /usr/local/bin/redpsl
     such that a symbolic link to the script is available in somewhere
     that is in their PATH.
 (3) They have a shell variable or know a path to the directory. Suppose that
     $RED refers top the Reduce trunk, they might say "$RED/bin/redpsl". Or
     they may have that $RED/bin as their current directory and go "./redcsl".
     Anyway they refer to the script either by an absolute or a relative
     explicit path. This may or may not have symbolic links in it.
In each case ..../trunk/bin/xxx will need to access some file in
..../trunk/scripts and probably ones in ..../trunk/cslbuild or
..../trunk/pslbuild. To achieve that the script needs to be able to
find the directory that it is in (bin) and the true parent of that
directory (trunk). The last issue could arise if there was a symbolic link
from somewhere to the directory "bin" such that the original directory has
one parent but the link has a different one.

I have tried to make the scripts work on (at least) (Free)BSD, Solaris,
Linux, OSX and in a Cygwin terminal on Windows. I hope that by covering
those cases all will be well on other platforms that can respond to a
script that begins with "#! /bin/sh". I will expand the script here
and explain line by line what it does and why it does it that way.

#! /bin/sh
   This header line indicates that the file contains a shell script
   to be processed by the Bourne Shell /bin/sh. Even if the user invokes
   it from some other shell (say the C shell) this will be a Bourne Shell
   script. It should avoid non-portable shell features.
here="$0"
   The zeroth argument is the name of the script being run. In the case
   that the script was launched using an explicit path this will be the
   text specified by the user. The double quotes should allow for paths that
   contain whitespace. If the command was found on the user's PATH the
   value will be a fully rooted path to the script. This behaviour seems to
   be OK on the platforms listed at the top of this file if the script is
   invoked bt merely quoting its name or a path to it. I will not work if
   the fact that it is a script not a command is exploited by trying something
   like "bash -v < bin/redpsl" where the shell merely uses its standard input
   and has no idea where that comes from. It will also not work if the
   script is invoked via "source" or ".", as in ". bin/redcsl". The last
   case there could be supported if we knew that the shell being used was
   bash by replacing "$0" with "${BASH_SOURCE[0]}" but that would then fail
   in a messy way with other shells. So I think that this is ONLY expected
   to support cases where the user tries invoking the command in an obvious
   way not trying to make special provision for the fact that it is a script
   not an executable binary. I also see some suggestions that if the script
   were made "suid" that the value arriving in "$0" might change. So I do
   not support that situation!
while test -L "$here"
   If the name of the script itself is a symbolic link it is necessary to
   follow it, since the directory that the link is in may not be at all
   related to the location that Reduce itself is sitting. There could be
   a chain on links, hence the loop. A cycle of symbolic links will lead to
   the code here failing to terminate. It would be possible to put in a
   counter to give up after some number of link traversals, but my choice
   at present is to let people who set up that situation get what they
   perhaps deserve! Note that "test -L" works on Sunos 5.10 but I see
   reports that on some older versions of Solaris one used to need to go
   "test -h" instead. I am not going to push historical compatibility back
   quite that far. 
do here=`ls -ld "$here" | sed 's/.*-> //'`
   If I was certain that I had a "readlink" command I could use it here to
   traverse the symbolic link that I just detected, but on some platforms
   I might not and across various platforms where there is some form of
   readlink command (or options for "stat") behaviour and options vary.
   So this uses "ls -ld" to inspect the file (or directory) concerned, and
   the output will contain "->" because the file is a link. The editing
   command passed to sed then remove everything up to and including this
   arrow. A pretty classic case where remaining portable forces one to do
   things a slow and messy way!
done
   End of the loop. At the end "$here" will be a path whose final element is
   not a symbolic link.
here=`cd \`dirname "$here"\` ; pwd -P`
   Note the nested evaluation with back-ticks here. "dirname" does appear
   to be sufficient commonly available that I will use it here rather than
   use a shell script to discard from the final "/" in the name onwards. Note
   That when a command is enclosed in backticks it gets executed in a fresh
   environment so using "cd" in there will not have an effect on the working
   directory overall. "pwd" then prints a fully rooted path. The option "-P"
   to it arranges that there will not be any symbolic links in the path as
   returned, so this is an honest absolute path!
here=`dirname "$here"`
   Finally use dirname again to move up a level, so if the command issued
   resolved (via PATH, symbolic links and anything else) to trunk/bin/redcsl
   then we now get an absolute path to trunk, as required.



                                                       A C Norman January 2015