FUNCTION_UNDER_TEST := atan2

include ../support/Makefile.bivariate

CFLAGS += -ffinite-math-only

check_special: check_special.o $(CORE_MATH_OBJS) $(FUNCTION_UNDER_TEST)_mpfr.o
	$(CC) $(LDFLAGS) $(OPENMP) -o $@ $^ -lmpfr -lm

check_special.o: check_special.c
	$(CC) $(CFLAGS) $(CORE_MATH_DEFINES) -I../support -c $(OPENMP) -o $@ $<

clean_all: clean
	rm -f *.out
