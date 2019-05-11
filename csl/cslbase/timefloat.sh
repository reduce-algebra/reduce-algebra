#! /bin/bash -v

# The object of this scripts is to give me some idea of the relative speeds
# of existing CSL arithmetic and the version using arithlib.hpp that is
# in prospect.

# On my Windows/Cygwin64 system the huge multiplications done here show up
# with the new arithlib.hpp code taking 24 seconds in both CPU cycles and
# elapsed time, while the older CSL-based code takes around 20 seconds elapsed
# and 60 seconds CPU (or maybe 24/72).
# I can validate the comparison as between C++ code and Lisp code by running
# the Reduce-based test under VSL (which uses arithlib.hpp). That confirms
# my results.
#
# The take away result so far (and on just one platform) is that the raw
# performance using arithlib for multiplication is around 3 times faster than
# the old CSL code (wheeeee!!) by the way the CSL code uses 3 threads for
# a top level of Karatsuba lets it about claw that back for huge
# multiplication cases.
#
# That probably signals to me that I want to code up the parallel Karatsuba
# for arithlib, but it also gives me great encouragement that migrating
# CSL to use the new code is something worth putting effort into.
#
# Of course there will not be HUGE speedups in code that is not arithmetic-
# intensive.


g++ -xc++ -O3 - -o timefloat <<XXX
#include <iostream>
#include <ctime>

#include "arithlib.hpp"

using namespace arithlib;

int main(int argc, char *argv[])
{   Bignum a = pow(13_Z, 100000);
    clock_t c0 = std::clock();
    for (int i=0; i<5000; i++)
        (void)(a*a);
    std::cout << ((std::clock()-c0)/(double)CLOCKS_PER_SEC) << std::endl;
    return 0;
}
XXX
time ./timefloat
time redcsl -w - <<XXX
lisp;
on echo, comp, time;
symbolic procedure timefloat();
  begin
    scalar a := 13^100000, c0 := time(), t0 := datestamp();
    for i := 1:5000 do a*a;
    print list((time()-c0)/1000.0, datestamp()-t0)
  end;
timefloat();
end;
XXX
