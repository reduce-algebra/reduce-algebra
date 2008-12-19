# Makefile.am

srcdir = @srcdir@
VPATH = @srcdir@

reducec=$(srcdir)/..
herec=$(shell pwd)

if cygpath
reduce=$(shell cygpath -m $(reducec))
here=$(shell cygpath -m $(herec))
else
reduce=$(reducec)
here=$(herec)
endif

all:
# The arrangement here is somewhat odd to try to cope with the way that this
# Makefile gets extended via created include files when it runs.
	if ! test -f red/bootstrap.img; \
	then $(MAKE) red/bootstrap.img; \
	     if test -f red/bootstrap.img; then $(MAKE) reduce; fi; \
	else $(MAKE) reduce; fi

# The dependencies here use wild-card specifications and are set up by hand
# because at the stage of bootstrapping I do not have any automatic
# scheme for dependency tracking in place

red/bootstrap.img:	psl/* \
		$(srcdir)/symget.dat $(srcdir)/bootstrap.sh \
		$(srcdir)/boot.sl $(reducec)/packages/package.map \
		$(reducec)/packages/support/*.red \
		$(reducec)/packages/rlisp/*.red \
		$(reducec)/packages/alg/*.red  \
		$(reducec)/packages/poly/* \
		$(reducec)/packages/arith/*.red
	$(srcdir)/bootstrap.sh $(BUILD)

tryboot:
	psl/bpsl -td $(STORE2) -f red/bootstrap.img

# The process of building the bootstrap version of the reduce image
# create a set of subsidiary Makefile includes that document how to
# go further. Of course this means that make has no idea how to cope with
# these extra bits until the bootstrap step has been performed!


# Making these include files sort-of optional and merely touching them
# to bring them up to date when necessary appears to avoid some makefile
# mess that I do not really understand, like a tendancy for the bootstrap
# image to get remade multiple times.

deps/core-packages.psl-make:
	if ! test -d deps; then mkdir deps; fi
	touch deps/core-packages.psl-make

deps/core-packages.psl-depend:
	if ! test -d deps; then mkdir deps; fi
	touch deps/core-packages.psl-depend

deps/noncore-packages.psl-make:
	if ! test -d deps; then mkdir deps; fi
	touch deps/noncore-packages.psl-make

deps/noncore-packages.psl-depend:
	if ! test -d deps; then mkdir deps; fi
	touch deps/noncore-packages.psl-depend

-include deps/core-packages.psl-make
-include deps/core-packages.psl-depend
-include deps/noncore-packages.psl-make
-include deps/noncore-packages.psl-depend

red/reduce.img:
	$(srcdir)/reduce.img.sh $(BUILD)
	

# end of Makefile.am


