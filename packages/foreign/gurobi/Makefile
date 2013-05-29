# The following line is for Mac OS. Adapt this for your system to the directory
# containing Gurobi's lib and include directories.
GUROBI=/Library/gurobi510/mac64
# GUROBI=/usr/local/gurobi/linux64

all: libredgurobi.so

redgurobi.o: redgurobi.c
	gcc -O2 -fPIC -I $(GUROBI)/include -c redgurobi.c

libredgurobi.so: redgurobi.o
	gcc -O2 -shared -L $(GUROBI)/lib -lgurobi51 -o libredgurobi.so redgurobi.o

clean:
	rm -f redgurobi.o
