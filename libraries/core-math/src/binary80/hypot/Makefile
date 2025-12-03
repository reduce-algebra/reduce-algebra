FUNCTION_UNDER_TEST := hypotl

include ../support/Makefile.bivariate

all:: check_special check_exact

check_special: check_special.o $(CORE_MATH_OBJS) $(FUNCTION_UNDER_TEST)_mpfr.o
	$(CC) $(LDFLAGS) $(OPENMP) -o $@ $^ -lmpfr -lgmp -lm

check_special.o: check_special.c
	$(CC) $(CFLAGS) $(CORE_MATH_DEFINES) $(OPENMP) -o $@ $^ -c

clean::
	rm -f check_special check_exact

check_exact: check_exact.o $(CORE_MATH_OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ -lm

check_exact.o: check_exact.c
	$(CC) $(CFLAGS) $(CORE_MATH_DEFINES) -o $@ $^ -c
