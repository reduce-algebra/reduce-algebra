# Makefile.am

# I want to be able to see what gets built and why, so here is a GNU
# make trace facility.

TRACE = $(warning TRACE: $@ :: $?)

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
	test -d red || mkdir red; \
	if ! test -f red/bootstrap.img; \
	then $(MAKE) red/bootstrap.img; \
	     if test -f red/bootstrap.img; then $(MAKE) reduce; fi; \
	else touch red/bootstrap.img; touch red/hugo; $(MAKE) reduce; fi


force:
# Force rebuild of bootstrap.img
	$(MAKE) red/bootstrap.img
	test -f red/bootstrap.img && $(MAKE) reduce

# The dependencies here use wild-card specifications and are set up by hand
# because at the stage of bootstrapping I do not have any automatic
# scheme for dependency tracking in place

red/bootstrap.img:	psl/* \
		$(srcdir)/symget.dat $(srcdir)/bootstrap.sh \
		$(srcdir)/pslcompat.sl \
		$(srcdir)/boot.sl $(reducec)/packages/package.map \
		$(reducec)/packages/support/*.red \
		$(reducec)/packages/rlisp/*.red \
		$(reducec)/packages/alg/*.red  \
		$(reducec)/packages/poly/* \
		$(reducec)/packages/arith/*.red \
		red/mma.awk red/qepcad.awk
	$(srcdir)/bootstrap.sh $(BUILD)

# These files are needed by redlog, and putting copies of them in
# the "red" directory will mean that Reduce can find them even if the
# full set of source files are not available.

red/mma.awk:	$(reducec)/packages/redlog/ofsf/mma.awk
	cp $(reducec)/packages/redlog/ofsf/mma.awk red/mma.awk

red/qepcad.awk:	$(reducec)/packages/redlog/ofsf/qepcad.awk
	cp $(reducec)/packages/redlog/ofsf/qepcad.awk red/qepcad.awk

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

red/reduce.img:  red/hugo
	if  test -f "../../psl/mkreduce" -o ! -f red/reduce.img; then rm -f ../../psl/mkreduce; \
	"$(srcdir)/reduce.img.sh" $(BUILD); \
	fi


# Now I am going to put some customized and rather odd install stuff. When I
# have this working I will want to put in matching uninstall code, but for
# now that will wait. The idea I have is that the files that get set up by the
# stuff here should match the ones created by the system-specific installers,
# i.e. reduce.deb and .rpm and the Windows installer. I am really not sure
# what I should do on a Macintosh! So I think I will put things so that
# reduce can be launched from the command-line an dnot worry (at least the
# start with) about applications bundles etc.

if windows

install-exec-local:	red/reduce.img
	echo install for windows not implemented
	exit 1

else !windows
if macintosh

install-exec-local:	red/reduce.img
	echo install for macintosh not implemented
	exit 1

else !macintosh
if linux

install-exec-local:	red/reduce.img
# This version is mainly for Linux... It follows the directory layout used
# in the "debianbuild" directory.
	echo install for Linux, Unix etc into destdir=$(DESTDIR) prefix=$(prefix)
	rm -rf $(DESTDIR)$(prefix)/lib/reduce/pslbuild ; \
	mkdir -p $(DESTDIR)$(prefix)/lib/reduce/pslbuild/psl ; \
	mkdir -p $(DESTDIR)$(prefix)/lib/reduce/pslbuild/red ; \
	cp -r psl/* $(DESTDIR)$(prefix)/lib/reduce/pslbuild/psl ; \
	cp -r red/* $(DESTDIR)$(prefix)/lib/reduce/pslbuild/red ; \
	cp $(reducec)/psl/redpsl $(DESTDIR)$(prefix)/bin/redpsl ; \
	echo Installed for PSL in $(DESTDIR)$(prefix)

else !linux

install-exec-local:
	echo install for this unknown system not implemented
	exit 1

endif !linux
endif !macintosh
endif !windows

if windows

uninstall-local:
	echo uninstall for windows not implemented
	exit 1

else !windows
if macintosh

uninstall-local:
	echo uninstall for macintosh not implemented
	exit 1

else !macintosh
if linux

uninstall-local:
# This version is mainly for Linux... It follows the directory layout used
# in the "debianbuild" directory.
	echo install for Linux, Unix etc into destdir=$(DESTDIR) prefix=$(prefix)
	rm -rf $(DESTDIR)$(prefix)/lib/reduce/pslbuild ; \
	rf -f $(DESTDIR)$(prefix)/bin/redpsl ; \
	echo Uninstalled for PSL in $(DESTDIR)$(prefix)

else !linux

uninstall-local:
	echo uninstall for this unknown system not implemented
	exit 1

endif !linux
endif !macintosh
endif !windows

# end of Makefile.am

