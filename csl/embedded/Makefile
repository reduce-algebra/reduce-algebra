# Makefile for this SIMPLE setup for Reduce building

PROG=	reduce

SRCS=	arith01.c arith02.c arith03.c arith04.c arith05.c \
	arith06.c arith07.c arith08.c arith09.c arith10.c \
	arith11.c arith12.c bytes.c char.c \
	csl.c cslmpi.c cslread.c eval1.c eval2.c eval3.c \
	eval4.c fasl.c fns1.c fns2.c fns3.c fwin.c gc.c \
	opnames.c preserve.c print.c restart.c sysfwin.c \
	termed.c \
	u01.c u02.c u03.c u04.c u05.c u06.c \
	u07.c u08.c u09.c u10.c u11.c u12.c

CFLAGS=		-g
CPPFLAGS=	-DHAVE_CONFIG_H=1 -DEMBEDDED=1 $$($(PKGCONFIG) --cflags x11)
LDLIBS=		-lm

OBJS=		$(SRCS:.c=.o)

PKGCONFIG=	pkg-config

.SUFFIXES:	.c .o

.c.o:
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(PROG):	$(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

# config.h dependent files:
fwin.c:		config.h
termed.c:	config.h
u01.c:		config.h
u02.c:		config.h
u03.c:		config.h
u04.c:		config.h
u05.c:		config.h
u06.c:		config.h
u07.c:		config.h
u08.c:		config.h
u09.c:		config.h
u10.c:		config.h
u11.c:		config.h
u12.c:		config.h

# Maintainance:
clean:
	rm -f $(PROG) $(OBJS)

# end of Makefile
