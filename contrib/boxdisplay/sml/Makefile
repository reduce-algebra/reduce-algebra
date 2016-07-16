SML ?= poly

.PHONY: all
all: test1 test2

.PHONY: test%
test%:
	echo 'use "all.sml"; $@();' | $(SML)


# Note that on Arthur's computers there is a shell variable O that
# identifies the top of the REDUCE tree. The "if" clauses here look for a
# copy of Reduce that I will use in the testing.
sml:
	if test -x $$O/cslbuild/i686-pc-cygwin/csl/bootstrapreduce.exe;\
	then R=$$O/cslbuild/i686-pc-cygwin/csl/bootstrapreduce.exe; \
	elif test -x $$O/bin/bootstrapreduce;\
	then R=$$O/bin/bootstrapreduce; \
	else R=bootstrapreduce;fi && \
	$$R -w sml.red -l sml.log


# end of Makefile
