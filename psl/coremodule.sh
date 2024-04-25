#! /bin/sh

# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
#    * Redistributions of source code must retain the relevant copyright
#      notice, this list of conditions and the following disclaimer.
#    * Redistributions in binary form must reproduce the above copyright
#      notice, this list of conditions and the following disclaimer in the
#      documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
# THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
# CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
# $Id$
#

echo build core module $1 for architecture $2

a=$0
c=unknown
case $a in
/* )
  c=$a  
  ;;
*/* )
  case $a in
  ./* )
    a=`echo $a | sed -e s+./++`
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
  if test $c = "unknown" ;then
    echo "Unable to find full path for script. Please re-try"
    echo "launching it using a fully rooted path."
    exit 1
  fi
  ;;
esac

cpsldir=`echo $c | sed -e 's+/[^/]*$++'`
creduce=$cpsldir/..

if test -x /usr/bin/cygpath
then
  psldir=`cygpath -m "$cpsldir"`
  reduce=`cygpath -m "$creduce"`
else
  psldir="$cpsldir"
  reduce="$creduce"
fi

fasl=red

if test -f psl/64
then
STORE=500
else
STORE=64000000
fi

reduce=${reduce%/}  # get rid of any trailing slash.

export fasl psldir reduce
echo "fasl=$fasl psldir=$psldir reduce=$reduce"

psl/bpsl -td $STORE -f red/bootstrap.img <<XXX > buildlogs/$1.blg

symbolic;

load compiler;
errorset('(load compat),nil,nil); % PSL compiler support.
on verboseload;

load remake;

!*argnochk := t;

begin
  scalar w, i, s;
  i := open("$reduce/packages/package.map", 'input);
  s := rds i;
  w := read();
  rds s;
  close i;
  for each x in w do put(car x, 'folder, cadr x)
end;
  
package!-remake '$1;

if !*faslp 
  then system "touch $reduce/psl/mkreduce";

bye;
XXX

grep -q '^\*\*\*\*\* ' buildlogs/$1.blg && \
   echo Possible error building core module $1 - check buildlogs/$1.blg && \
   exit 1
exit 0
