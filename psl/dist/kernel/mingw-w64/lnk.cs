#! /bin/csh                    #
#  linking the PSL loader program
#
if ($TERM == "sun" || $TERM == "sun-cmd") then  #
   ld -x -e _start -Bstatic -o psll psll.o /lib/crt0.o echo.o float.o pslextras.o pwd-fn.o sigs.o unix-io.o file-status.o misc.o -lm -lc  #
  endif   #
                                                    #
                                                      #
if ($TERM != "sun" && $TERM != "sun-cmd") then #
   ld -x -e _start -o psll psll.o /lib/crt0.o echo.o float.o pslextras.o pwd-fn.o sigs.o unix-io.o file-status.o misc.o -lm -lc  #
  endif   #
