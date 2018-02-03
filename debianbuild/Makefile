# Makefile for debianbuild

SNAPSHOT=$(shell LANG=C date "+%Y-%m-%d")
MACHINE=$(shell uname -m)
NOW=$(shell LANG=C date "+%a, %d %b %Y %T %z")
CHANGELOG=reduce/debian/changelog
BUILDTOPDIR=C
REVISION=HEAD
BUILD=$(shell $(BUILDTOPDIR)/scripts/findhost.sh $(shell $(BUILDTOPDIR)/config.guess))

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
	( time svn export -r $(REVISION) .. $(BUILDTOPDIR) ) > $(BUILDTOPDIR).log
	( cd $(BUILDTOPDIR) ; ./autogen.sh -f )
	-rm -rf reduce-source-$(SNAPSHOT)
	touch $(BUILDTOPDIR).stamp

reduce-packages:	$(BUILDTOPDIR).stamp debpackages rpmpackages tarpackages

debpackages:
	cd reduce ; debuild --set-envvar BUILDTOPDIR=$(realpath $(BUILDTOPDIR)) --preserve-envvar=DH_OPTIONS -b -us -uc

rpmpackages:
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

tarpackages:
# This assumes that both the CSL and PSL versions have already been built in
# the $(BUILDTOPDIR) directory. (PSL not on ARM...)
	rm -rf $(TARDEST)
	mkdir $(TARDEST)
	mkdir $(TARDEST)/csl
ifeq (,$(findstring arm,$(MACHINE)))
	mkdir $(TARDEST)/psl
endif
	mkdir $(TARDEST)/reduce.doc
	cp $(BUILDTOPDIR)/doc/manual/manual.pdf $(TARDEST)/manual.pdf
	cp $(BUILDTOPDIR)/scripts/cslhere.sh $(TARDEST)/redcsl
ifeq (,$(findstring arm,$(MACHINE)))
	cp $(BUILDTOPDIR)/scripts/pslhere.sh $(TARDEST)/redpsl
endif
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
ifeq (,$(findstring arm,$(MACHINE)))
	cp -r $(BUILDTOPDIR)/pslbuild/$(BUILD)/psl $(TARDEST)/psl
	cp -r $(BUILDTOPDIR)/pslbuild/$(BUILD)/red $(TARDEST)/psl
	cp $(BUILDTOPDIR)/generic/newfront/build/rfpsl $(TARDEST)
endif
	chmod +x $(TARDEST)/redcsl $(TARDEST)/rfcsl
ifeq (,$(findstring arm,$(MACHINE)))
	chmod +x $(TARDEST)/redpsl $(TARDEST)/rfpsl 
endif
	tar cfj reduce-freestanding_$(SNAPSHOT)_$(MACHINE).tar.bz2 -C /tmp reduce-snapshot_$(SNAPSHOT)_$(MACHINE)

source-archive:
	-rm -rf reduce-source-$(SNAPSHOT) *.tar.bz2
	cp -r $(BUILDTOPDIR) reduce-source-$(SNAPSHOT)
	$(MAKE) reduce-source-core-$(SNAPSHOT).tar.bz2
	$(MAKE) reduce-source-csl-$(SNAPSHOT).tar.bz2
	$(MAKE) reduce-source-csl-embedded-$(SNAPSHOT).tar.bz2
	$(MAKE) reduce-source-csl-support-$(SNAPSHOT).tar.bz2
ifeq (,$(findstring arm,$(MACHINE)))
	$(MAKE) reduce-source-psl-$(SNAPSHOT).tar.bz2
endif
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

ifeq (,$(findstring arm,$(MACHINE)))
reduce-source-psl-$(SNAPSHOT).tar.bz2:
	tar cfj reduce-source-psl-$(SNAPSHOT).tar.bz2 \
		--owner=root --group=root \
		reduce-source-$(SNAPSHOT)/psl
endif

clean:
	rm -rf $(BUILDTOPDIR) $(BUILDTOPDIR).log
	rm -f *.deb *.rpm *.tgz *.tar.bz2 *.stamp

# end of Makefile
