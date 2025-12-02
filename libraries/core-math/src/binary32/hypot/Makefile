FUNCTION_UNDER_TEST := hypotf

include ../support/Makefile.bivariate

CFLAGS += -ffinite-math-only

all:: check_special

check_special: check_special.o triples.o worst_p1.o $(CORE_MATH_OBJS) $(FUNCTION_UNDER_TEST)_mpfr.o
	$(CC) $(LDFLAGS) $(OPENMP) -o $@ $^ -lmpfr -lgmp -lm

check_special.o: check_special.c
	$(CC) $(CFLAGS) $(CORE_MATH_DEFINES) -c $(OPENMP) -o $@ $<

triples.o: triples.c
	$(CC) $(CFLAGS) $(CORE_MATH_DEFINES) -c $(OPENMP) -o $@ $<

worst_p1.o: worst_p1.c
	$(CC) $(CFLAGS) $(CORE_MATH_DEFINES) -c $(OPENMP) -o $@ $<

clean::
	rm -f check_special
