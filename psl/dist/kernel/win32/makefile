# Intel PC
ENV=WIN32

PROJ = bpsl
SRC = bps.c bpsheap.c echo.c file-sta.c float.c misc.c os-hooks.c pslextra.c \
        pwd-fn.c sigs.c unix-io.c pslsocke.c pipe-s.c pslave.c

!include <ntwin32.mak>

all: $(PROJ).exe

# Inference Rules:

.c.obj:
    $(cc) $(cdebug) $(cflags) /W2 $(cvars) $(cf) -DSLAVE $<

datetag.obj: main.obj mkdttag.exe $(SRC:.c=.obj)
     mkdttag
     $(cc) $(cdebug) $(cflags) /W2 $(cvars) $(cf) datetag.c

mkdttag.obj: mkdttag.c
     $(cc) $(cflags) mkdttag.c

mkdttag.exe: mkdttag.obj
      $(link)  -SUBSYSTEM:console  -out:mkdttag.exe mkdttag.obj  $(guilibs)
 
main.obj: main.asm
     masm /Ml main main main main


#
#                   -MAP:bpsl.map 
#
$(PROJ).exe: $(SRC:.c=.OBJ) main.obj $(SRC2:.c=.OBJ) datetag.obj
    $(link) $(ldebug) -SUBSYSTEM:console  -entry:mainCRTStartup\
          -MAP:bpsl.map \
	  -stack:0x1000000,0x1000000 \
          -out:$(PROJ).exe main.obj  $(SRC:.c=.OBJ) $(SRC2:.c=.OBJ) datetag.obj \
     kernel32.lib $(guilibs) advapi32.lib

#    copy bpsl.exe d:\psl\bin\winnt

#    mkbare
#    psl2redu

