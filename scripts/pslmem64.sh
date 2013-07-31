#!/bin/sh

# Print the desired memory for 64 bit psl-based reduce in (decimal) MB.
# The default is 1000, which is 1 GB. Note that on many architectures, psl
# used a stop-and-copy model for gc so that the memory is split into two
# heaps of which only one is available at any time.
#
# For getting information on the memory at runtime, go:
#
# meminfo();
#

echo 1000
