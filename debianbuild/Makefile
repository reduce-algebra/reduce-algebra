# Makefile for debianbuild

SNAPSHOTDATE=$(shell LANG=C date "+%Y-%m-%d")
ifeq ($(REVISION),)
SNAPSHOT=$(SNAPSHOTDATE)
else
SNAPSHOT=$(REVISION)
endif
MACHINE=$(shell PATH=/usr/local/bin:$$PATH && uname -m)
NOW=$(shell LANG=C date "+%a, %d %b %Y %T %z")
CHANGELOG=reduce/debian/changelog
BUILDTOPDIR=C
REVISION=HEAD
BUILD=$(shell $(BUILDTOPDIR)/scripts/findhost.sh $(shell $(BUILDTOPDIR)/config.guess))

export DEB_BUILD_OPTIONS=noautodbgsym

all:	update-changelog reduce-packages

update-changelog:
	if head -1 $(CHANGELOG) | grep $(SNAPSHOT) >/dev/null ; then : ; \
	else  \
	  ( echo "reduce ("$(SNAPSHOT)") stable; urgency=low" ; \
	    echo ; \
	    echo "  * New Snapshot. Date $(SNAPSHOTDATE)." ; \
	    echo ; \
	    echo " -- REDUCE Developers <reduce-algebra-developers@lists.sourceforge.net> " $(NOW) ;\
	    echo ) > $(CHANGELOG).tmp ; \
	  cat $(CHANGELOG) >> $(CHANGELOG).tmp ; \
	  mv $(CHANGELOG).tmp $(CHANGELOG); \
	fi


$(BUILDTOPDIR).stamp:
	rm -rf $(BUILDTOPDIR)
	( time svn export -r $(REVISION) .. $(BUILDTOPDIR) ) > $(BUILDTOPDIR).log
	( LANG=C svnversion .. $(REVISION) > $(BUILDTOPDIR)/svnversion.txt )
	( cd $(BUILDTOPDIR) ; ./autogen.sh )
	-rm -rf reduce-source_$(SNAPSHOT)
	touch $(BUILDTOPDIR).stamp

reduce-packages:	tarpackages

# suppress complaint about distribution "unstable" in Ubuntu
# by specifying the debian lintian profile
debpackages:	$(BUILDTOPDIR).stamp
	cd reduce ; \
	echo DEBUILD_LINTIAN_OPTS= $${DEBUILD_LINTIAN_OPTS} ; \
	debuild \
            --set-envvar BUILDTOPDIR=$(realpath $(BUILDTOPDIR)) \
	    --preserve-envvar=DH_OPTIONS \
            --prepend-path=/usr/local/bin \
            -b -us -uc \
	    --lintian-opts --profile debian

rpmpackages:	debpackages
	for f in reduce-*_$(SNAPSHOT)_*.deb ; \
	  do \
	     msg=`fakeroot alien -k -r -g $${f}` ; \
	     msg=$${msg#Directory } ; dir=$${msg% prepared*} ; \
	     arch=$${f##*_} ; arch=$${arch%.deb} ; rpmarch=`echo $${arch} | sed -e 's/all/noarch/' -e 's/amd64/x86_64/'` ; \
	     pkg=$${f%.deb} ; \
	     (cd $${dir} ; \
	      tar -c -z -f ../$${pkg}.tgz --exclude='*.spec' . ; \
	      sed -i -e '/^%dir "\(\/\|\/usr\/\|\/usr\/bin\/\|\/usr\/lib\/\|\/usr\/share\/\|\/usr\/share\/doc\/\|\/etc\/\)"/d' *.spec ; \
	      rpmbuild -bb --buildroot=`pwd` --target=$${rpmarch} *.spec >/tmp/$${dir}.log 2>&1 ; \
	      test -n "$?" && echo Build of $${dir} failed: $?, log file follows: && cat /tmp/$${dir}.log ; \
	      echo rm -f /tmp/$${dir}.log ; \
	     ) ; \
	  done

TARDEST=/tmp/reduce-snapshot_$(SNAPSHOT)_$(MACHINE)

tarpackages:	rpmpackages
# This assumes that both the CSL and PSL versions have already been built in
# the $(BUILDTOPDIR) directory.
	rm -rf $(TARDEST)
	mkdir $(TARDEST)
	mkdir $(TARDEST)/csl
	mkdir $(TARDEST)/psl
	mkdir $(TARDEST)/reduce.doc
	cp $(BUILDTOPDIR)/doc/manual/manual.pdf $(TARDEST)/manual.pdf
	cp $(BUILDTOPDIR)/scripts/cslhere.sh $(TARDEST)/redcsl
	cp $(BUILDTOPDIR)/scripts/pslhere.sh $(TARDEST)/redpsl
	cp -r $(BUILDTOPDIR)/xmpl $(TARDEST)
	cp $(BUILDTOPDIR)/cslbuild/$(BUILD)/csl/csl $(TARDEST)/csl
	cp $(BUILDTOPDIR)/cslbuild/$(BUILD)/csl/csl.img $(TARDEST)/csl
	cp $(BUILDTOPDIR)/cslbuild/$(BUILD)/csl/reduce $(TARDEST)/csl
	cp $(BUILDTOPDIR)/cslbuild/$(BUILD)/csl/reduce.img $(TARDEST)/csl
	cp -r $(BUILDTOPDIR)/cslbuild/$(BUILD)/csl/reduce.fonts $(TARDEST)/csl
	cp -r $(BUILDTOPDIR)/cslbuild/$(BUILD)/csl/reduce.resources $(TARDEST)/csl
	cp $(BUILDTOPDIR)/generic/newfront/build/rfcsl $(TARDEST)
	cp $(BUILDTOPDIR)/cslbuild/$(BUILD)/csl/reduce.doc/BINARY-LICENSE.txt $(TARDEST)/reduce.doc
	cp $(BUILDTOPDIR)/cslbuild/$(BUILD)/csl/reduce.doc/BSD-LICENSE.txt $(TARDEST)/reduce.doc
	cp -r $(BUILDTOPDIR)/pslbuild/$(BUILD)/psl $(TARDEST)/psl
	cp -r $(BUILDTOPDIR)/pslbuild/$(BUILD)/red $(TARDEST)/psl
	cp $(BUILDTOPDIR)/generic/newfront/build/rfpsl $(TARDEST)
	chmod +x $(TARDEST)/redcsl $(TARDEST)/rfcsl
	chmod +x $(TARDEST)/redpsl $(TARDEST)/rfpsl 
	tar cfj reduce-freestanding_$(SNAPSHOT)_$(MACHINE).tar.bz2 -C /tmp reduce-snapshot_$(SNAPSHOT)_$(MACHINE)

source-archive:
	-rm -rf reduce-source_$(SNAPSHOT) *.tar.bz2
	cp -r $(BUILDTOPDIR) reduce-source_$(SNAPSHOT)
	$(MAKE) reduce-source-core_$(SNAPSHOT).tar.bz2
	$(MAKE) reduce-source-csl_$(SNAPSHOT).tar.bz2
	$(MAKE) reduce-source-csl-embedded_$(SNAPSHOT).tar.bz2
	$(MAKE) reduce-source-csl-support_$(SNAPSHOT).tar.bz2
	$(MAKE) reduce-source-psl_$(SNAPSHOT).tar.bz2
	ls -lh *.tar.bz2
#	-rm -rf reduce-source_$(SNAPSHOT)

reduce-source-core_$(SNAPSHOT).tar.bz2:
	tar cfj reduce-source-core_$(SNAPSHOT).tar.bz2 \
		--owner=root --group=root \
		--exclude=reduce-source_$(SNAPSHOT)/csl \
		--exclude=reduce-source_$(SNAPSHOT)/psl \
		reduce-source_$(SNAPSHOT)

reduce-source-csl_$(SNAPSHOT).tar.bz2:
	tar cfj reduce-source-csl_$(SNAPSHOT).tar.bz2 \
		--owner=root --group=root \
		--exclude=reduce-source_$(SNAPSHOT)/csl/support-packages \
		--exclude=reduce-source_$(SNAPSHOT)/csl/embedded \
		--exclude=reduce-source_$(SNAPSHOT)/csl/new-embedded \
		--exclude=reduce-source_$(SNAPSHOT)/csl/generated-c \
		reduce-source_$(SNAPSHOT)/csl

reduce-source-csl-embedded_$(SNAPSHOT).tar.bz2:
	tar cfj reduce-source-csl-embedded_$(SNAPSHOT).tar.bz2 \
		--owner=root --group=root \
		reduce-source_$(SNAPSHOT)/csl/embedded \
		reduce-source_$(SNAPSHOT)/csl/new-embedded \
		reduce-source_$(SNAPSHOT)/csl/generated-c

reduce-source-csl-support_$(SNAPSHOT).tar.bz2:
	tar cfj reduce-source-csl-support_$(SNAPSHOT).tar.bz2 \
		--owner=root --group=root \
		reduce-source_$(SNAPSHOT)/csl/support-packages

reduce-source-psl_$(SNAPSHOT).tar.bz2:
	tar cfj reduce-source-psl_$(SNAPSHOT).tar.bz2 \
		--owner=root --group=root \
		reduce-source_$(SNAPSHOT)/psl

clean:
	rm -rf $(BUILDTOPDIR) $(BUILDTOPDIR).log
	rm -f *.deb *.rpm *.tgz *.tar.bz2 *.stamp

# end of Makefile
