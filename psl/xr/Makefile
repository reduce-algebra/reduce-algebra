
# Simple Makefile for XR, C Cannam 1993.  Sorry no imake.

# Defines:
#
#     + Define SOLARIS for work around dodgy bit in Solaris gcc
#    where the size of jmp_buf is apparently wrong.
#
#     + Define LINUX for linux; at present all this does is take
#    out references to SIGBUS.
#
#     + Define WAIT_PID for systems lacking wait4 but having
#    waitpid; if your system has neither but has instead wait3,
#    define WAIT_THREE.  If you have wait4, define neither.
#
#     + Define HAVE_VIEWPORT_SET_FUNCTIONS if your Xaw supports
#    the function XawViewportSetCoordinates.  Many versions do,
#    and it works much better than XReduce's hacked alternatives.
#    If you're unsure but patient, define it and see if it links.
#
#     + Define HAVE_GETHOSTNAME if you have the gethostname(3)
#    call and want the host name displayed in XR's title bar.
#
#     + Define EXPLICIT_EDITRES for explicit inclusion of the
#    Editres Protocol files and error handler (shouldn't be
#    necessary, and isn't particularly recommended).

# If you define WAIT_THREE or WAIT_PID and leave undefined
# HAVE_GETHOSTNAME, there should be no remaining BSDisms (and
# the code is mostly POSIX compliant).  The X code used is only
# X11 (R4 or R5), Xt and Athena; there's no OL or Motif or
# anything.  All C code is K & R; using an ANSI-only compiler
# will fail utterly.


CC 		= cc

CFLAGS		= -g -DHAVE_VIEWPORT_SET_FUNCTIONS -DHAVE_GETHOSTNAME #-DEXPLICIT_EDITRES
LDFLAGS		= -L/usr/lib/X11

# # Solaris
#
# CFLAGS	= -g -DHAVE_VIEWPORT_SET_FUNCTIONS -DSOLARIS -DWAIT_PID
# LDFLAGS	= -L/usr/lib -L/usr/ccs/lib

HFLILES		= fallback.h  font.h      manager.h   printer.h   xredres.h\
		fancy.h     help.h      message.h   verbal.h    xredrres.h\
		fchoose.h   input.h     option.h    widgets.h   xredtech.h\
		file.h      main.h      output.h    xredplus.h  xreduce.h

OBJECTS		= main.o verbal.o xredtech.o input.o widgets.o output.o fancy.o message.o option.o font.o help.o manager.o printer.o file.o fchoose.o newhelp.o
SOURCES		= main.c verbal.c xredtech.c input.c widgets.c output.c fancy.c message.c option.c font.c help.c manager.c printer.c file.c fchoose.c newhelp.c

xr:		${OBJECTS} ${HFILES}
		rm -f xr
		${CC} -o xr ${OBJECTS} ${LDFLAGS} -lX11 -lXt -lXaw -lXmu -lXext -lm

# # For dynamic loading on Solaris perhaps put this into the preceding line:
# -YP,:/opt/SUNWspro/SC2.0.1:/usr/ccs/lib:/usr/lib

all:		${SOURCES} ${HFILES}
		rm -f xr *.o
		make xr

lint:		${SOURCES}
		${LINT} ${SOURCES}

clean:		
		rm -f *.o

