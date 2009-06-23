#! /bin/sh

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
STORE=600
else
STORE=64000000
fi

export fasl psldir reduce

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

bye;
XXX

