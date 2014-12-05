# The following line is for Linux. Adapt this for your system to the directory
# containing Z3's lib and include directories.
Z3 = /Users/sturm/Documents/src/z3

CC = gcc

all: libredz3.so

version:
	$(CC) --version

redz3.o: redz3.c
	$(CC) -O2 -fPIC -I $(Z3)/include -c redz3.c

libredz3.so: redz3.o
	$(CC) -O2 -shared -o libredz3.so redz3.o -Wl,-rpath,$(Z3)/lib -L $(Z3)/lib -lz3

clean:
	rm -f redz3.o

distclean: clean
	rm -f libredz3.so
