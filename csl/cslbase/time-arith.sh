#! /bin/bash

# The object of this scripts is to give me some idea of the relative speeds
# of existing CSL arithmetic and the version using arithlib.hpp that is
# in prospect.

# On my Windows/Cygwin64 system the huge multiplications done here show up
# with the new arithlib.hpp code being distinctly faster than the older
# code in CSL, and with both taking much less elapsed time than CPU time
# because they use threads to cope with the top-level of Karatsuba
# multiplication. One might worry that the speed difference was because
# the Reduce version had more overheads getting to where arithmetic started,
# but I can validate the comparison as between C++ code and Lisp code by
# running the Reduce-based test under VSL (which uses arithlib.hpp).
# That confirms my results.
#
# The test here ONLY looks at the relative speed of huge multiplications, and
# even within that case only the situation where a big number is multiplied
# by itself.

case `uname -a` in
*Cygwin*) LIBS=
          ;;
*)        LIBS=-lpthread
          ;;
esac

g++ -xc++ -O3 - $LIBS -o time-arith <<XXX
#include <iostream>
#include <ctime>

#include "arithlib.hpp"

using namespace arithlib;

int main(int argc, char *argv[])
{   Bignum a = pow(13_Z, 100000);
    clock_t c0 = std::clock();
    time_t t0 = std::time(NULL);
    for (int i=0; i<5000; i++)
        (void)(a*a);
    std::cout << ((std::clock()-c0)/(double)CLOCKS_PER_SEC)
              << " CPU seconds " << std::endl;
    std::cout << (std::time(NULL)-t0) << " elapsed seconds" << std::endl;
    return 0;
}
XXX

echo Time using arithlib directly from C++

time ./time-arith

echo Now try using Reduce

time redcsl -w - <<XXX
lisp;
on comp, time;
symbolic procedure time!-arith();
  begin
    scalar a := 13^100000, c0 := time(), t0 := datestamp();
    for i := 1:5000 do a*a;
    print list('cpu, (time()-c0)/1000.0, 'elapsed, datestamp()-t0)
  end;
time!-arith();
quit;
XXX
