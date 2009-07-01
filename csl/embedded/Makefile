# Makefile for this SIMPLE setup for Reduce building

CC=gcc
CFLAGS=-m32 -g -DHAVE_CONFIG_H=1 -DEMBEDDED=1

reduce:		arith01.o arith02.o arith03.o arith04.o arith05.o \
		arith06.o arith07.o arith08.o arith09.o arith10.o \
		arith11.o arith12.o bytes.o char.o \
		csl.o cslmpi.o cslread.o eval1.o eval2.o eval3.o \
		eval4.o fasl.o fns1.o fns2.o fns3.o fwin.o gc.o \
		opnames.o preserve.o print.o restart.o sysfwin.o \
		termed.o \
		u01.o u02.o u03.o u04.o u05.o u06.o \
		u07.o u08.o u09.o u10.o u11.o u12.o
	$(CC) $(CFLAGS) arith01.o arith02.o arith03.o arith04.o arith05.o \
	arith06.o arith07.o arith08.o arith09.o arith10.o \
	arith11.o arith12.o bytes.o char.o \
	csl.o cslmpi.o cslread.o eval1.o eval2.o eval3.o \
	eval4.o fasl.o fns1.o fns2.o fns3.o fwin.o gc.o \
	opnames.o preserve.o print.o restart.o sysfwin.o \
	termed.o \
	u01.o u02.o u03.o u04.o u05.o u06.o \
	u07.o u08.o u09.o u10.o u11.o u12.o \
	-lm -o reduce

# end of Makefile
