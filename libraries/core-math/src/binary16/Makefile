FUNCTIONS := $(patsubst %/,%,$(dir $(wildcard */Makefile)))

all: $(addprefix all-,$(FUNCTIONS))

clean: $(addprefix clean-,$(FUNCTIONS))

all-%:
	$(MAKE) -C $* all

clean-%:
	$(MAKE) -C $* clean
