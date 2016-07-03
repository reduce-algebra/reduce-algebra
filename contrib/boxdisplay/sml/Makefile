SML ?= poly

.PHONY: all
all: test1 test2

.PHONY: test%
test%:
	echo 'use "all.sml"; $@();' | $(SML)


sml:
	$O/bin/bootstrapreduce -w sml.red -l sml.log


