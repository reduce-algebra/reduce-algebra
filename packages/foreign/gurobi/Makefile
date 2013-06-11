# The following line is for Mac OS. Adapt this for your system to the directory
# containing Gurobi's lib and include directories.
GUROBI = /Library/gurobi550/mac64

CC = gcc

all: libredgurobi.so

version:
	$(CC) --version

redgurobi.o: redgurobi.c
	$(CC) -O2 -fPIC -I $(GUROBI)/include -c redgurobi.c

libredgurobi.so: redgurobi.o
	$(CC) -O2 -shared -o libredgurobi.so redgurobi.o -Wl,-rpath,$(GUROBI)/lib -L $(GUROBI)/lib -lgurobi55

clean:
	rm -f redgurobi.o

distclean: clean
	rm -f libredgurobi.so
