FUNCTION_UNDER_TEST := expl

include ../support/Makefile.univariate

clean::
	rm -rf *.o check_special

all:: check_special

check_special: check_special.o $(CORE_MATH_OBJS) $(FUNCTION_UNDER_TEST)_mpfr.o
	$(CC) $(LDFLAGS) $(OPENMP) -o $@ $^ -lmpfr -lm

check_special.o: check_special.c
	$(CC) $(CFLAGS) $(CORE_MATH_DEFINES) $(OPENMP) -o $@ $^ -c

