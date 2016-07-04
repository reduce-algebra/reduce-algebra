SML ?= poly

.PHONY: all
all: test1 test2

.PHONY: test%
test%:
	echo 'use "all.sml"; $@();' | $(SML)



sml:
	R=`./findreduce.sh` && \
	$$R < sml.red | tee sml.log


