FUNCTION_UNDER_TEST := hypotq

include ../support/Makefile.bivariate

CFLAGS += -DMPFR_WANT_FLOAT128
LDFLAGS += -lquadmath

all:: check_special

check_special: check_special.o $(FUNCTION_UNDER_TEST).o $(FUNCTION_UNDER_TEST)_mpfr.o
	$(CC) $(OPENMP) -o $@ $^ -lmpfr -lgmp -lm $(LDFLAGS)

check_special.o: check_special.c
	$(CC) $(CFLAGS) $(OPENMP) -o $@ $^ -c

clean::
	rm -f check_special
