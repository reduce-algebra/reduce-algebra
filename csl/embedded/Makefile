# Makefile for this SIMPLE setup for Reduce building

CC=gcc
CFLAGS=-m32 -O2 -DHAVE_CONFIG_H=1 -DEMBEDDED=1

all:	reduce

reduce:		arith01.o arith02.o arith03.o arith04.o arith05.o \
		arith06.o arith07.o arith08.o arith09.o arith10.o \
		arith11.o arith12.o bytes.o char.o \
		csl.o cslmpi.o cslread.o eval1.o eval2.o eval3.o \
		eval4.o fasl.o fns1.o fns2.o fns3.o fwin.o gc.o \
		preserve.o print.o restart.o sysfwin.o termed.o \
		u01.o u02.o u03.o u04.o u05.o u06.o u07.o u08.o u09.o u10.o \
		u11.o u12.o u13.o u14.o u15.o u16.o u17.o u18.o u19.o u20.o \
		u21.o u22.o u23.o u24.o u25.o u26.o u27.o u28.o u29.o u30.o \
		u31.o u32.o u33.o u34.o u35.o u36.o u37.o u38.o u39.o u40.o \
		u41.o u42.o u43.o u44.o u45.o u46.o u47.o u48.o u49.o u50.o \
		u51.o u52.o u53.o u54.o u55.o u56.o u57.o u58.o u59.o u60.o
	$(CC) $(CFLAGS) arith01.o arith02.o arith03.o arith04.o arith05.o \
	arith06.o arith07.o arith08.o arith09.o arith10.o \
	arith11.o arith12.o bytes.o char.o \
	csl.o cslmpi.o cslread.o eval1.o eval2.o eval3.o \
	eval4.o fasl.o fns1.o fns2.o fns3.o fwin.o gc.o \
	preserve.o print.o restart.o sysfwin.o termed.o \
	u01.o u02.o u03.o u04.o u05.o u06.o u07.o u08.o u09.o u10.o \
	u11.o u12.o u13.o u14.o u15.o u16.o u17.o u18.o u19.o u20.o \
	u21.o u22.o u23.o u24.o u25.o u26.o u27.o u28.o u29.o u30.o \
	u31.o u32.o u33.o u34.o u35.o u36.o u37.o u38.o u39.o u40.o \
	u41.o u42.o u43.o u44.o u45.o u46.o u47.o u48.o u49.o u50.o \
	u51.o u52.o u53.o u54.o u55.o u56.o u57.o u58.o u59.o u60.o \
	-lm -o reduce

# Create the reduce.img file

reduce.img:	reduce
	-mv reduce.img reduce.img.old
	-rm -f reduce.img
	./reduce -w -z -Dno_init_file ../cslbase/buildreduce.lsp \
		-D@srcdir=../cslbase \
		-o reduce.img \
		-l image.log

clean:
	rm -f *.o reduce

HEADERS = arith.h bytes.h clsyms.h config.h cslerror.h cslread.h \
	entries.h externs.h fwin.h headers.h machine.h proc.h \
	sockhdr.h stream.h syscsl.h tags.h termed.h version.h


arith01.o:	arith01.c $(HEADERS)
arith02.o:	arith02.c $(HEADERS)
arith03.o:	arith03.c $(HEADERS)
arith04.o:	arith04.c $(HEADERS)
arith05.o:	arith05.c $(HEADERS)
arith06.o:	arith06.c $(HEADERS)
arith07.o:	arith07.c $(HEADERS)
arith08.o:	arith08.c $(HEADERS)
arith09.o:	arith09.c $(HEADERS)
arith10.o:	arith10.c $(HEADERS)
arith11.o:	arith11.c $(HEADERS)
arith12.o:	arith12.c $(HEADERS)
bytes.o:	bytes.c $(HEADERS)
bytes1.o:	bytes1.c opnames.c $(HEADERS)
char.o:	char.c $(HEADERS)
csl.o:	csl.c $(HEADERS)
cslmpi.o:	cslmpi.c mpipack.c $(HEADERS)
cslread.o:	cslread.c $(HEADERS)
driver.o:	driver.c $(HEADERS)
embedcsl.o:	embedcsl.c csl.c $(HEADERS)
eval1.o:	eval1.c $(HEADERS)
eval2.o:	eval2.c $(HEADERS)
eval3.o:	eval3.c $(HEADERS)
eval4.o:	eval4.c $(HEADERS)
fasl.o:	fasl.c $(HEADERS)
fns1.o:	fns1.c $(HEADERS)
fns2.o:	fns2.c $(HEADERS)
fns3.o:	fns3.c $(HEADERS)
fwin.o:	fwin.c $(HEADERS)
gc.o:	gc.c $(HEADERS)
preserve.o:	preserve.c $(HEADERS)
print.o:	print.c $(HEADERS)
restart.o:	restart.c machineid.c $(HEADERS)
sysfwin.o:	sysfwin.c $(HEADERS)
termed.o:	termed.c $(HEADERS)
u01.o:	u01.c $(HEADERS)
u02.o:	u02.c $(HEADERS)
u03.o:	u03.c $(HEADERS)
u04.o:	u04.c $(HEADERS)
u05.o:	u05.c $(HEADERS)
u06.o:	u06.c $(HEADERS)
u07.o:	u07.c $(HEADERS)
u08.o:	u08.c $(HEADERS)
u09.o:	u09.c $(HEADERS)
u10.o:	u10.c $(HEADERS)
u11.o:	u11.c $(HEADERS)
u12.o:	u12.c $(HEADERS)
u13.o:	u13.c $(HEADERS)
u14.o:	u14.c $(HEADERS)
u15.o:	u15.c $(HEADERS)
u16.o:	u16.c $(HEADERS)
u17.o:	u17.c $(HEADERS)
u18.o:	u18.c $(HEADERS)
u19.o:	u19.c $(HEADERS)
u20.o:	u20.c $(HEADERS)
u21.o:	u21.c $(HEADERS)
u22.o:	u22.c $(HEADERS)
u23.o:	u23.c $(HEADERS)
u24.o:	u24.c $(HEADERS)
u25.o:	u25.c $(HEADERS)
u26.o:	u26.c $(HEADERS)
u27.o:	u27.c $(HEADERS)
u28.o:	u28.c $(HEADERS)
u29.o:	u29.c $(HEADERS)
u30.o:	u30.c $(HEADERS)
u31.o:	u31.c $(HEADERS)
u32.o:	u32.c $(HEADERS)
u33.o:	u33.c $(HEADERS)
u34.o:	u34.c $(HEADERS)
u35.o:	u35.c $(HEADERS)
u36.o:	u36.c $(HEADERS)
u37.o:	u37.c $(HEADERS)
u38.o:	u38.c $(HEADERS)
u39.o:	u39.c $(HEADERS)
u40.o:	u40.c $(HEADERS)
u41.o:	u41.c $(HEADERS)
u42.o:	u42.c $(HEADERS)
u43.o:	u43.c $(HEADERS)
u44.o:	u44.c $(HEADERS)
u45.o:	u45.c $(HEADERS)
u46.o:	u46.c $(HEADERS)
u47.o:	u47.c $(HEADERS)
u48.o:	u48.c $(HEADERS)
u49.o:	u49.c $(HEADERS)
u50.o:	u50.c $(HEADERS)
u51.o:	u51.c $(HEADERS)
u52.o:	u52.c $(HEADERS)
u53.o:	u53.c $(HEADERS)
u54.o:	u54.c $(HEADERS)
u55.o:	u55.c $(HEADERS)
u56.o:	u56.c $(HEADERS)
u57.o:	u57.c $(HEADERS)
u58.o:	u58.c $(HEADERS)
u59.o:	u59.c $(HEADERS)
u60.o:	u60.c $(HEADERS)


# end of Makefile
