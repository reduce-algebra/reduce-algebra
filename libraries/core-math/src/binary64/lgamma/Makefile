FUNCTION_UNDER_TEST := lgamma

include ../support/Makefile.univariate

all:: check_special

check_special: check_special.o $(CORE_MATH_OBJS) $(FUNCTION_UNDER_TEST)_mpfr.o
	$(CC) $(LDFLAGS) $(OPENMP) -o $@ $^ -lmpfr -lm

check_special.o: check_special.c
	$(CC) $(CFLAGS) $(OPENMP) $(CORE_MATH_DEFINES) -o $@ $^ -c

clean::
	rm -f check_special
