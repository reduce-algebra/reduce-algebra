#! /bin/sh

echo build noncore module $1 for architecture $2

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

psl/bpsl -td $STORE -f red/reduce.img <<XXX > buildlogs/$1.blg

symbolic;

loaded!-modules!* := nil;

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
  
lisp print loaded!-modules!*;

% Specific package loads to avoid BPS problems. I do not know if these
% bits of special treatment are still necessary and so hope that somebody
% who understands better will check and review them and remove this
% bit of special-casing when they can.

if '$1 eq 'susy2 then flag('(susy2),'lap)
else if '$1 eq 'fps then load_package limits,factor,specfn,sfgamma
else if '$1 eq 'mrvlimit then load_package taylor;


package!-remake '$1;

lisp print loaded!-modules!*;

bye;
XXX

