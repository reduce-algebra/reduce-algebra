SML ?= poly

.PHONY: all
all: test1 test2

.PHONY: test%
test%:
	echo 'use "edit.m"; U "all"; $@();' | $(SML)
