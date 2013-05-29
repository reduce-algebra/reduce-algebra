# The following line is for Mac OS. Adapt this for your system to the directory
# containing libgurobi51.so.
GUROBI=/Library/gurobi510/mac64

all: libredgurobi.so

redgurobi.o: redgurobi.c
	gcc -O2 -I $(GUROBI)/include -c redgurobi.c

libredgurobi.so: redgurobi.o
	gcc -O2 -L $(GUROBI)/lib -lgurobi51 -bundle -o libredgurobi.so redgurobi.o
