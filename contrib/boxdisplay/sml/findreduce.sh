#! /bin/sh

# Some people will have a shell variable O or reduce that indicates the
# top of the Reduce tree. I will use bootstrapreduce in preference to
# redcsl because it gives a bit more information if I need to debug. I
# will use redcsl in preference to redpsl

for x in $O/bin/bootstrapreduce \
         $reduce/bin/bootstrapreduce \
         $O/bin/redcsl \
	 $reduce/bin/redcsl \
         $O/bin/redpsl \
	 $reduce/bin/redpsl
do
  case $x in
  *redpsl*)
    echo "$x"
    ;;
  *)
    echo "$x -w"
    ;;
  esac
  exit 0
done
# fall back to hoping that just "redcsl" will bo on your PATH
echo "redcsl -w"
exit 0
