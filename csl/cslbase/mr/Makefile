# Sample Makefile that shows how programs here can be built. But NOTE that
# this can need adjustment for different platforms, and the code here is
# in general for hackers rather than mortals...


# isprime.cpp is expected to have the output from running "hash" edited
# into it. Running testisprime verifies that it will give reliable reports
# as to the prime/composite nature of every 32-bit value.

testhash:	testhash.cpp isprime.cpp
	g++ -O3 testhash.coo -o testhash
	time ./testhash

# "hash" takes mr2a.log, a log showing pseudoprimes, and searches for a hash
# function that can be used to fill in isprime.cpp so it is a reliable
# test for primality. Its first argument is a target table size, and the
# second is the number of different hash functions it is prepared to try.
# It can easily find talbles with 256 entries, and with increasing difficulty
# (ie using more tries and hence much longer runs) I have got it to find
# a table of size 220.

# PTHR = -lpthread                needed on Linux etc

hash:	hash.cpp
	gcc -O3 hash.cpp $(PTHR) -o hash

# To find seek a table of size 220, allowing up to a million round of
# searching and putting the log in hash.log ...

hash.log:	hash mr2a.log
	time ./hash 220 1000000 | tee hash.log

# mr2a creates the table of pseudoprimes.

mr2a:	mr2a.cpp
	g++ -O3 mr2a.cpp $(PTHR) -o mr2a

# Running mr2a takes a significant amount of time (months!) and so needs to
# be done on a machine that will not suffer forced reboots etc over that sort
# of timescale. I show how to launch it here but do not automate that since
# it is not something to do exactly casually!

mr2a.log:	mr2
	echo "Let this run for an elapsed time of say 3 months to collect"
	echo "a list of 32-bit pseudoprimes for every potential witness up"
	echo "to 2^16, creating a log file that is around 1.2GB."
	echo "         ./mr2a | tee mr2a.log"

# end of Makefile
