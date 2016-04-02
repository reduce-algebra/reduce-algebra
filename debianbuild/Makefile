
SNAPSHOT=$(shell LANG=C date "+%Y%m%d")
NOW=$(shell LANG=C date "+%a, %d %b %Y %T %z")
CHANGELOG=reduce/debian/changelog
BUILDTOPDIR=C
REVISION=HEAD

all:	update-changelog reduce-packages

update-changelog:
	if head -1 $(CHANGELOG) | grep $(SNAPSHOT) >/dev/null ; then : ; \
        else  \
	  ( echo "reduce ("$(SNAPSHOT)") unstable; urgency=low" ; \
            echo ; \
            echo "  * New Snapshot." ; echo ; \
	    echo " -- REDUCE Developers <reduce-algebra-developers@lists.sourceforge.net> " $(NOW) ;\
	    echo ) > $(CHANGELOG).tmp ; \
          cat $(CHANGELOG) >> $(CHANGELOG).tmp ; \
          mv $(CHANGELOG).tmp $(CHANGELOG); \
        fi
 

$(BUILDTOPDIR).stamp:
	rm -rf $(BUILDTOPDIR)
	( time svn export -r $(REVISION) .. $(BUILDTOPDIR) ) | tee $(BUILDTOPDIR).log
	( cd $(BUILDTOPDIR) ; ./autogen.sh -f )
	-rm -rf reduce-source-$(SNAPSHOT)
	touch $(BUILDTOPDIR).stamp

reduce-packages:	$(BUILDTOPDIR).stamp debpackages rpmpackages

debpackages:
	cd reduce ; debuild --set-envvar BUILDTOPDIR=$(realpath $(BUILDTOPDIR)) -b -us -uc

rpmpackages:
	fakeroot alien -k -r reduce-*_$(SNAPSHOT)_*.deb


source-archive:
	-rm -rf reduce-source-$(SNAPSHOT) *.tar.bz2
	cp -r $(BUILDTOPDIR) reduce-source-$(SNAPSHOT)
	$(MAKE) reduce-source-core-$(SNAPSHOT).tar.bz2
	$(MAKE) reduce-source-csl-$(SNAPSHOT).tar.bz2
	$(MAKE) reduce-source-csl-embedded-$(SNAPSHOT).tar.bz2
	$(MAKE) reduce-source-csl-support-$(SNAPSHOT).tar.bz2
	$(MAKE) reduce-source-psl-$(SNAPSHOT).tar.bz2
	ls -lh *.tar.bz2
#	-rm -rf reduce-source-$(SNAPSHOT)

reduce-source-core-$(SNAPSHOT).tar.bz2:
	tar cfj reduce-source-core-$(SNAPSHOT).tar.bz2 \
		--owner=root --group=root \
		--exclude=reduce-source-$(SNAPSHOT)/csl \
		--exclude=reduce-source-$(SNAPSHOT)/psl \
		reduce-source-$(SNAPSHOT)

reduce-source-csl-$(SNAPSHOT).tar.bz2:
	tar cfj reduce-source-csl-$(SNAPSHOT).tar.bz2 \
		--owner=root --group=root \
		--exclude=reduce-source-$(SNAPSHOT)/csl/support-packages \
		--exclude=reduce-source-$(SNAPSHOT)/csl/embedded \
		--exclude=reduce-source-$(SNAPSHOT)/csl/new-embedded \
		--exclude=reduce-source-$(SNAPSHOT)/csl/generated-c \
		reduce-source-$(SNAPSHOT)/csl

reduce-source-csl-embedded-$(SNAPSHOT).tar.bz2:
	tar cfj reduce-source-csl-embedded-$(SNAPSHOT).tar.bz2 \
		--owner=root --group=root \
		reduce-source-$(SNAPSHOT)/csl/embedded \
		reduce-source-$(SNAPSHOT)/csl/new-embedded \
		reduce-source-$(SNAPSHOT)/csl/generated-c

reduce-source-csl-support-$(SNAPSHOT).tar.bz2:
	tar cfj reduce-source-csl-support-$(SNAPSHOT).tar.bz2 \
		--owner=root --group=root \
		reduce-source-$(SNAPSHOT)/csl/support-packages

reduce-source-psl-$(SNAPSHOT).tar.bz2:
	tar cfj reduce-source-psl-$(SNAPSHOT).tar.bz2 \
		--owner=root --group=root \
		reduce-source-$(SNAPSHOT)/psl

clean:
	rm -f *.deb *.rpm *.stamp

# end of Makefile
