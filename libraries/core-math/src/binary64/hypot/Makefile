FUNCTION_UNDER_TEST := hypot

include ../support/Makefile.bivariate

CFLAGS += -ffinite-math-only -fno-math-errno

all:: check_special

check_special: check_special.o triples.o $(CORE_MATH_OBJS) $(FUNCTION_UNDER_TEST)_mpfr.o
	$(CC) $(LDFLAGS) $(OPENMP) -o $@ $^ -lmpfr -lgmp -lm

check_special.o: check_special.c
	$(CC) $(CFLAGS) $(CORE_MATH_DEFINES) -I../support -c $(OPENMP) -o $@ $<

triples.o: triples.c
	$(CC) $(CFLAGS) $(CORE_MATH_DEFINES) -I../support -c $(OPENMP) -o $@ $<

clean::
	rm -f check_special
