# Makefile for getting ready to make Macintosh installer package

BUILDTOPDIR=C
REVISION=HEAD

# At present this merely make a .tar.bz2 file... not a proper Macintosh
# installer.

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
	(cd $(BUILDTOPDIR) ; \
		./autogen.sh -f )
	touch $(BUILDTOPDIR).stamp

csl.stamp:	$(BUILDTOPDIR).stamp
	(cd $(BUILDTOPDIR) ; \
		./configure --with-csl ; \
		script ../csl.log time make csl )
	touch csl.stamp

psl.stamp:	$(BUILDTOPDIR).stamp
	(cd $(BUILDTOPDIR) ; \
		./configure --with-psl ; \
		script ../psl.log time make psl )
	touch psl.stamp

# Documentation is also re-generated in the clean tree so that regardless
# of history it should end up fresh and tidy.

docs.stamp:	$(BUILDTOPDIR).stamp
	(cd $(BUILDTOPDIR)/doc/misc ; script ../../../docmisc.log time make )
	(cd $(BUILDTOPDIR)/doc/manual ; script ../../../docmanual.log time make )
	touch docs.stamp

package-mac:	$(BUILDTOPDIR).stamp csl.stamp psl.stamp docs.stamp
#	$(BUILDTOPDIR)/psl/saveimage.sh $(BUILDTOPDIR)/pslbuild/x86_64-pc-windows \
#		$(abspath .) '$$reduce/lib/psl' && mv reduce.img reduce64.img
#	$(BUILDTOPDIR)/psl/saveimage.sh $(BUILDTOPDIR)/pslbuild/i686-pc-windows \
#		$(abspath .) '$$reduce/lib/psl'
	rm -rf distrib
	mkdir -p distrib
# The CSL components will be in the form of application bundles. To run from
# the command line you "just" need to put reduce.app/Contents/MacOS on
# your PATH.
	./copyfiles.sh "$(BUILDTOPDIR)"
# At present the PSL material is a mere dump from the pslbuild directory.
# I guess that transcribing the redpsl script into there and arranging
# that it detected its own path when run and then set up the various
# environment variables that the PSL system needs would be feasible, but
# for now I will content myself with putting the directory in place.
	hdiutil create -volname Reduce-snapshot \
		-srcfolder distrib \
		-ov -format UDZO Reduce-snapshot.dmg
	echo Reduce-snapshot.dmg made, I hope!!

# It will be a really good idea to go "make clean" before any wholesale
# "make" here - this removes all the working files that get created
# during the build. It will leave any final installer that is in the
# directory "Output"

clean:
	rm -rf *.img *.dmg distrib $(BUILDTOPDIR) log *.stamp

# end of Makefile
