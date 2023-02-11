
mc=`$here/config.guess`
mc=`$here/scripts/findhost.sh $mc`

getplatform() {
  case $1 in
# Plain --csl --bootstrapreduce --psl
  --csl)
    printf "csl=$mc"
    ;;
  --bootstrapreduce)
    printf "bootstrapreduce=$mc"
    ;;
  --psl)
    printf "psl=$mc"
    ;;

  --csl=installed)
    printf "csl=installed"
    ;;

  --csl=debug | --csl-debug)
    printf "csl=debug"
    ;;
  --bootstrapreduce=debug | --bootstrapreduce-debug)
    printf "bootstrapreduce=debug"
    ;;

# -csl=[windows/cygwin/native/universal] -bootstrapreduce=[cygwin etc]
  --csl=windows)
    printf "csl=x86_64-pc-windows"
    ;;
  --csl=cygwin)
    printf "csl=x86_64-pc-cygwin"
    ;;
  --csl=native)
    printf "csl=$mc"
    ;;
  --csl=universal)
    w=`echo $mc | sed s/aarch64/universal/ | sed s/x86_64/universal/`
    printf "csl=$w"
    ;;

  --bootstrapreduce=windows)
    printf "bootstrapreduce=x86_64-pc-windows"
    ;;
  --bootstrapreduce=cygwin)
    printf "bootstrapreduce=x86_64-pc-cygwin"
    ;;
  --bootstrapreduce=native)
    printf "bootstrapreduce=$mc"
    ;;
  --bootstrapreduce=universal)
    w=`echo $mc | sed s/aarch64/universal/ | sed s/x86_64/universal/`
    printf "bootstrapreduce=$w"
    ;;

# Ditto but with "-debug"

  --csl=windows-debug)
    printf "csl=x86_64-pc-windows-debug"
    ;;
  --csl=cygwin-debug)
    printf "csl=x86_64-pc-cygwin-debug"
    ;;
  --csl=native-debug)
    printf "csl=$mc-debug"
    ;;
  --csl=universal-debug)
    w=`echo $mc | sed s/aarch64/universal/ | sed s/x86_64/universal/`
    printf "csl=$w-debug"
    ;;

  --bootstrapreduce=windows-debug)
    printf "bootstrapreduce=x86_64-pc-windows-debug"
    ;;
  --bootstrapreduce=cygwin-debug)
    printf "bootstrapreduce=x86_64-pc-cygwin-debug"
    ;;
  --bootstrapreduce=native-debug)
    printf "bootstrapreduce=$mc-debug"
    ;;
  --bootstrapreduce=universal-debug)
    w=`echo $mc | sed s/aarch64/universal/ | sed s/x86_64/universal/`
    printf "bootstrapreduce=$w-debug"
    ;;

# Now the generic variants
  --csl=*)
    printf "${1#--}"
    ;;
  --bootstrapreduce=*)
    printf "${1#--}"
    ;;
  --psl=*)
    printf "${1#--}"
    ;;

# Now the rest.
  --jlisp)
    printf "jlisp"
    ;;
  --jlispboot)
    printf "jlispboot"
    ;;
  esac
}

getlogdir() {
  pp="$1"
  case "$pp" in
  csl=*)
    var=${pp#csl=}
    if test "$var" = "$mc"
    then
      logdir="csl"
    elif test "$var" = "installed"
    then
      logdir="csl:installed"
    elif test "$var" = "${mc}-debug"
    then
      logdir="csl-debug"
    else
      logdir="csl:${var#${mc}}"
    fi
    ;; 
  psl=*)
    var=${pp#psl=}
    if test "$var" = "$mc"
    then
      logdir="psl"
    elif test "$var" = "installed"
    then
      logdir="psl:installed"
    else
      logdir="psl:${var#${mc}}"
    fi
    ;;
  *)
    logdir="$pp"
    ;;
  esac
  printf "%s" "$logdir-times"
}
