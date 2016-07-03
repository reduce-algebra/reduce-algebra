SML ?= poly

.PHONY: all
all: test1 test2

.PHONY: test%
test%:
	echo 'use "all.sml"; $@();' | $(SML)


sml:
	$O/cslbuild/i686-pc-cygwin/csl/bootstrapreduce -w sml.red -l sml.log

sml1:
	$O/cslbuild/i686-pc-cygwin/csl/bootstrapreduce -w test.red -l test.log

lispfile:
	./lispfile.sh

