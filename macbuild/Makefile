# Makefile for getting ready to make Macintosh installer package

ifeq ($(REVISION),)
SNAPSHOT=$(shell LANG=C date "+%Y-%m-%d")
else
SNAPSHOT=$(REVISION)
endif
BUILDTOPDIR=C
REVISION=HEAD

all:	package-mac

# The sub-parts of this build process are controlled by a collection
# of datestamp files *.stamp. "make clean" will remove all of these and so
# force you to remake everything from scratch. Otherwise once one of these
# has been created it just sits there and prevents re-building of its
# component

# "$(BUILDTOPDIR)" is a copy of the main Reduce source tree. It will include
# everything that is checked in to the subversion repository but it will
# not include locally created files. If you have updated a file locally
# (even if you have not yet committed your changes) then that update will
# find its way into the clean tree. The purpose of all this is so that the
# setup process can dump large sections of the Reduce tree into the
# installation set without needing to enumerate files individually. A previous
# version of the script used the local copy of the main tree and could end
# up getting ready to distribute large amounts of temporary or experimental
# material.

$(BUILDTOPDIR).stamp:
	rm -rf $(BUILDTOPDIR)
	( time svn export -r $(REVISION) .. $(BUILDTOPDIR) ) > $(BUILDTOPDIR).log
	( pushd $(BUILDTOPDIR) ; ./autogen.sh -f ; popd )
	./make-source.sh $(SNAPSHOT) 
	touch $(BUILDTOPDIR).stamp

source-archive:
	./make-source.sh $(SNAPSHOT) 

csl.stamp:	$(BUILDTOPDIR).stamp
	( pushd $(BUILDTOPDIR) ; ./configure --with-csl --without-autogen ; \
		script ../csl.log time make csl ; popd )
	touch csl.stamp

psl.stamp:	$(BUILDTOPDIR).stamp
	( pushd $(BUILDTOPDIR) ; ./configure --with-psl --without-autogen ; \
		script ../psl.log time make psl ; popd )
	touch psl.stamp

# Documentation is also re-generated in the clean tree so that regardless
# of history it should end up fresh and tidy.

docs.stamp:	$(BUILDTOPDIR).stamp
	( pushd $(BUILDTOPDIR)/doc/misc ; script ../../../docmisc.log time make ; popd )
	( pushd $(BUILDTOPDIR)/doc/manual ; script ../../../docmanual.log time make ; popd )
	touch docs.stamp

package-mac:	$(BUILDTOPDIR).stamp csl.stamp psl.stamp docs.stamp
#
# Something like the following lines that do a "saveimage" will be needed
# so that the runpsl.sh script that I provide should (at least ideally)
# work even when the directory in which all the PSL files are kept gets
# moved. Note that the runpsl.sh script can establish an environment variable
# that gives its own location: I use that to initialize the "fasl" variable.
# I HOPE that PSL can be saved so that it takes the rest of its key
# components from somewhere indicated by an environment variable... but
# I do not quite understand that.
#
##	$(BUILDTOPDIR)/psl/saveimage.sh $(BUILDTOPDIR)/pslbuild/x86_64-pc-windows \
##		$(abspath .) '$$reduce/lib/psl' && mv reduce.img reduce64.img
##	$(BUILDTOPDIR)/psl/saveimage.sh $(BUILDTOPDIR)/pslbuild/i686-pc-windows \
##		$(abspath .) '$$reduce/lib/psl'
	rm -rf distrib
	mkdir -p distrib
# The CSL components will be in the form of application bundles. To run from
# the command line you "just" need to put reduce.app/Contents/MacOS on
# your PATH.
	./copyfiles.sh "$(BUILDTOPDIR)" "$(SNAPSHOT)"
# At present the PSL material is a mere dump from the pslbuild directory.
# I guess that transcribing the redpsl script into there and arranging
# that it detected its own path when run and then set up the various
# environment variables that the PSL system needs would be feasible, but
# for now I will content myself with putting the directory in place.
	hdiutil create -volname Reduce-snapshot \
		-srcfolder distrib \
		-ov -format UDZO Reduce-snapshot_$(SNAPSHOT).dmg
	echo Reduce-snapshot_$(SNAPSHOT).dmg made, I hope!!

# It will be a really good idea to go "make clean" before any wholesale
# "make" here - this removes all the working files that get created
# during the build. It will leave any final installer that is in the
# directory "Output"

clean:
	rm -rf *.img *.dmg distrib $(BUILDTOPDIR) *.log *.stamp

# end of Makefile
