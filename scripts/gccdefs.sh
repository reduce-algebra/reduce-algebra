#! /bin/sh

# This script displays the collection of macros that gcc predefines. Knowing
# them can be a real help when needing to customise code to cope with
# system-specific behaviour. Eg on Windows I might set CFLAGS to -mno-cygwin
# before using this.

# This is NOT used when doing any routine builds of Reduce - but may be a
# helpful reminder to anybody who sets out to port it to a new platform.

# This hack was noted on stackoverflow.org and answers a question I have
# had for AGES. Thank you stackoverflow.

echo | gcc $CFLAGS -E -dM -
