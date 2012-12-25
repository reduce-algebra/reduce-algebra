# Makefile for building reduce.img suitable for embedded use. This
# will always want to run on the current machine!


COMMON=-O2 -I. -DPAGE_BITS=19 -DHAVE_CONFIG_H=1 -DEMBEDDED=1 -DBUILTIN_IMAGE=1

# The idea here is that I want a C compiler and set of flags that will
# generate a 32-bit executable. Rather than use a separate configuration
# step I will use GNU Make trickery to detect a collection of cases
# I expect to be enough to get me going rather often. I will assume I am
# going to use (a version of) gcc...
# If this does not work or you do not like it merely set CC and CFLAGS
# manually for yourself.

ifeq ($(findstring Windows, $(OS)), Windows)

CC=i686-w64-mingw32-gcc
CFLAGS=$(COMMON) -DWIN32=1
CFLAGS1=$(COMMON) -DUNIX=1 -I/usr/include/ncurses
CONFIG=config.h.mingw32

else

CC3:=$(shell gcc hello.c -o hello && ./hello 2>&1)
CC4:=$(shell gcc -m32 hello.c -o hello && ./hello 2>&1)
MC:= $(shell uname -m)

ifeq ($(findstring [[4]], $(CC3)), [[4]])
CC=gcc
CFLAGS=$(COMMON) -DUNIX=1
CFLAGS1=$(COMMON) -DUNIX=1
LIBS=-lcurses
else
ifeq ($(findstring [[4]], $(CC4)), [[4]])
CC=gcc
CFLAGS=-m32 $(COMMON) -DUNIX=1
LIBS=-lcurses
else
CC=echo "Unable to build 32 bit application" && exit 1 &&
CFLAGS=
LIBS=
endif
endif

ifeq ($(MC),armv6l)
CONFIG=config.h.raspberrypi
else
CONFIG=config.h.linux64
endif

endif

S=../../cslbase

VPATH=$(S)

all:	reduce

reduce:		$(S)/arith01.c $(S)/arith02.c $(S)/arith03.c $(S)/arith04.c $(S)/arith05.c \
		$(S)/arith06.c $(S)/arith07.c $(S)/arith08.c $(S)/arith09.c $(S)/arith10.c \
		$(S)/arith11.c $(S)/arith12.c $(S)/bytes.c $(S)/char.c $(S)/babyreduce.c \
		$(S)/embedcsl.c $(S)/cslmpi.c $(S)/cslread.c $(S)/eval1.c $(S)/eval2.c $(S)/eval3.c \
		$(S)/eval4.c $(S)/fasl.c $(S)/fns1.c $(S)/fns2.c $(S)/fns3.c $(S)/fwin.c $(S)/gc.c \
		$(S)/preserve.c $(S)/print.c $(S)/restart.c $(S)/sysfwin.c $(S)/termed.c \
		$(S)/stubs.c image.c
	cp $(CONFIG) config.h
	$(CC) $(CFLAGS) -g $(S)/arith01.c $(S)/arith02.c $(S)/arith03.c $(S)/arith04.c $(S)/arith05.c \
		$(S)/arith06.c $(S)/arith07.c $(S)/arith08.c $(S)/arith09.c $(S)/arith10.c \
		$(S)/arith11.c $(S)/arith12.c $(S)/bytes.c $(S)/char.c $(S)/babyreduce.c \
		$(S)/embedcsl.c $(S)/cslmpi.c $(S)/cslread.c $(S)/eval1.c $(S)/eval2.c $(S)/eval3.c \
		$(S)/eval4.c $(S)/fasl.c $(S)/fns1.c $(S)/fns2.c $(S)/fns3.c $(S)/fwin.c $(S)/gc.c \
		$(S)/preserve.c $(S)/print.c $(S)/restart.c $(S)/sysfwin.c $(S)/termed.c \
		$(S)/stubs.c -lm $(LIBS) -o reduce
ifeq ($(findstring Windows, $(OS)), Windows)
	cp config.h.cygwin config.h
	gcc $(CFLAGS1) -g $(S)/arith01.c $(S)/arith02.c $(S)/arith03.c $(S)/arith04.c $(S)/arith05.c \
		$(S)/arith06.c $(S)/arith07.c $(S)/arith08.c $(S)/arith09.c $(S)/arith10.c \
		$(S)/arith11.c $(S)/arith12.c $(S)/bytes.c $(S)/char.c $(S)/babyreduce.c \
		$(S)/embedcsl.c $(S)/cslmpi.c $(S)/cslread.c $(S)/eval1.c $(S)/eval2.c $(S)/eval3.c \
		$(S)/eval4.c $(S)/fasl.c $(S)/fns1.c $(S)/fns2.c $(S)/fns3.c $(S)/fwin.c $(S)/gc.c \
		$(S)/preserve.c $(S)/print.c $(S)/restart.c $(S)/sysfwin.c $(S)/termed.c \
		$(S)/stubs.c -lm $(LIBS) -lcurses -o cygreduce
endif

image.c:	../minireduce-image.c
	cp ../minireduce-image.c image.c

clean:
	-rm -f *.o reduce hello config.h


# end of Makefile
