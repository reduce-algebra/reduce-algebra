# Makefile for getting ready to make Windows installer package
# This version only builds a 64-bit package.

ifeq ($(REVISION),)
SNAPSHOT=$(shell LANG=C date "+%Y-%m-%d")
#
# Try to find the global svn revision number
#
SVNREVISION := $(shell svnversion .. | sed -e 's/[^0-9].*$$//')
else
SNAPSHOT=$(REVISION)
SVNREVISION := $(REVISION)
endif
BUILDTOPDIR := $(shell pwd)/C
REVISION=HEAD

# If the following path to Inno Setup is correct then running "make" will
# be able to run Inno Setup automatically. If it is not then there will
# be no terrible harm, but when you run "make" it will end by displaying
# a message asking you to run Inno Setup manually.

ifeq ($(INNOVERSION),6)
inno=/cygdrive/c/Program Files (x86)/Inno Setup 6
else
inno=/cygdrive/c/Program Files (x86)/Inno Setup 5
endif

all:	package-win

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
	( time svn export -r $(REVISION) .. $(BUILDTOPDIR); \
	  LANG=C svnversion .. $(REVISION) > $(BUILDTOPDIR)/svnversion.txt ; \
	  cd $(BUILDTOPDIR); ./autogen.sh ) > $(BUILDTOPDIR).log
	touch $(BUILDTOPDIR).stamp

# The CSL version of Reduce gets build using an elaborate scheme that
# creates a sort of Windows "fat binary" such that a single binary can be
# run as a Windowed version or under a Windows console - or under cygwin
# mintty or using an X server! But here it will always be 64-bit.

csl.stamp:	$(BUILDTOPDIR).stamp
	script -c "time ./cslbuild.sh" csl.log
	touch csl.stamp

# The PSL version gets built just for 64-bit architectures. Because
# it is built in the clean tree it will be a fully fresh version
# fully re-build here.

psl.stamp:	$(BUILDTOPDIR).stamp
	(cd $(BUILDTOPDIR) ; \
		./configure --with-psl ; \
		script -c "time make psl" ../psl.log )
	touch psl.stamp

# Documentation is also re-generated in the clean tree so that regardless
# of history it should end up fresh and tidy.

docs.stamp:	$(BUILDTOPDIR).stamp
	(cd $(BUILDTOPDIR)/doc/misc ; script -c "time make"  ../../../docmisc.log )
	(cd $(BUILDTOPDIR)/doc/manual ; script -c "time make" ../../../docmanual.log )
	touch docs.stamp

# The final step in the creation of an installer involved saving PSL
# images for 64-bit versions and then invoking Inno Setup
# to pack up everything.

package-win:	$(BUILDTOPDIR).stamp csl.stamp psl.stamp docs.stamp reduce.iss
	$(BUILDTOPDIR)/psl/saveimage.sh $(BUILDTOPDIR)/pslbuild/x86_64-pc-windows \
		$(abspath .) '$$reduce/lib/psl' && mv reduce.img reduce64.img
	if test -x "$(inno)/ISCC.exe"; then \
		"$(inno)/ISCC" \
		  /Dmydir="$(subst /,\\,$(shell cygpath -m $(abspath .)))" \
		  /Dmyver="$(shell date +%Y-%m-%d) (Rev. $(SVNREVISION))" \
		  reduce.iss;\
		else echo Please run Innosetup on winbuild/reduce.iss; fi
	mv Output/Reduce-Setup.exe Output/Reduce-Setup_$(SNAPSHOT).exe
# At present I do not know if the .cab files created here will be any
# use, but I will at least create SOMETHING so that they can be tested and
# negotiation as to just what is needed can begin.
	cd cslbuild && gcab -c -z ../Output/wincsl_$(SNAPSHOT).cab \
		reduce.exe reduce.fonts reduce.img reduce.resources winreduce.exe
		d=`pwd` && cd $(BUILDTOPDIR)/pslbuild/x86_64* && \
		gcab -c -z $$d/Output/winpsl64_$(SNAPSHOT).cab psl red


# It will be a really good idea to go "make clean" before any wholesale
# "make" here - this removes all the working files that get created
# during the build. It will leave any final installer that is in the
# directory "Output"

clean:
	rm -rf cyg*.exe add*.exe *red*.exe *.img $(BUILDTOPDIR) \
		cslwin64 cslcyg64 \
		cslbuild log dll*.c *.stamp

# end of Makefile
