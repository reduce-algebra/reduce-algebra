ENV=WIN32

PROJ = bpslw
SRC =  npipe.c pmaster.c
SRC2 = winloop.c winsysdp.c windlg.c winio.c fancy.c psllcall.c
# DOSWIN = c:\psl\kernel\alphant

!include <ntwin32.mak>

all: $(PROJ).exe

# Inference Rules:

.c.obj:
#    claxp $(cdebug) -O2 -c -Zi -Zh -DALPHA -DWINPSL $<
     $(cc) $(cdebug) $(cflags) /W2 $(cvars) $(cf) -DWINPSL $<

psllw.rbj: psllw.rc psllw.h psllwr.ico psllwp.ico page.cur bee1.ico
    $(RC) $(RC_FLAGS) $(cvars) -fo $*.tmp -r psllw.rc
    cvtres -$(CPU) $*.tmp -o psllw.rbj
    del $*.tmp

winloop.obj: winloop.c winstruc.c psllw.h pcommon.h
    $(cc) $(cdebug) $(cflags) /W2 -DWINPSL winloop.c

winsysdp.obj: winsysdp.c winext.h psllw.h pcommon.h
    $(cc) $(cdebug) $(cflags) -DWIN32 /W2 -DWINPSL winsysdp.c

winio.obj: winio.c winext.h psllw.h
    $(cc) $(cdebug) $(cflags) /W2 -DWINPSL winio.c


fancy.obj: fancy.c
     $(cc) $(cdebug) $(cflags) /W2 -DWINPSL fancy.c

windlg.obj: windlg.c
    $(cc) $(cdebug) $(cflags) /W2 -DWINPSL windlg.c

psllcall.obj: psllcall.c winpipes.c psllcall.h
    $(cc) $(cdebug) $(cflags) /W2 -DWINPSL psllcall.c
#
#                   -MAP:bpsl.map 
#
$(PROJ).exe: $(SRC:.c=.obj) $(SRC2:.c=.obj) \
              datetag.obj psllw.rbj
    $(link) $(ldebug) -SUBSYSTEM:windows  -MAP:bpsl.map $(guiflags) -out:$(PROJ).exe \
              $(SRC:.c=.obj) $(SRC2:.c=.obj)  \
              psllw.rbj  $(guilibs) shell32.lib
#   copy bpslw.exe d:\psl\bin\alphant
#    mkbare
#    psl2redu

