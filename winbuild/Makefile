# Makefile for getting ready to make Windows installer package

BUILDTOPDIR=C
REVISION=HEAD

# If the following path to Inno Setup is correct then running "make" will
# be able to run Inno Setup automatically. If it is not then there will
# be no terrible harm, but when you run "make" it will end by displaying
# a message asking you to run Inno Setup manually.

inno=/cygdrive/c/Program Files (x86)/Inno Setup 5

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
	  cd $(BUILDTOPDIR); ./autogen.sh ) > $(BUILDTOPDIR).log
	touch $(BUILDTOPDIR).stamp

# The CSL version of Reduce gets build using an elaborate scheme that
# creates a sort of Windows "fat binary" such that a single binary can be
# used on 32 or 64-bit systems and to run as a Windowed version or under
# a Windows console - or under cygwin mintty or using an X server!

csl.stamp:	$(BUILDTOPDIR).stamp
	script -c "time ./cslbuild.sh" csl.log
	touch csl.stamp

# The PSL version gets built for both 32 and 64-bit architectures. Because
# it is built in the clean tree it will be a fully fresh pair of versions
# fully re-build here.

psl.stamp:	$(BUILDTOPDIR).stamp
	(cd $(BUILDTOPDIR) ; \
		./configure --with-psl ; \
		./configure --with-psl --with-m32 ; \
		script -c "time make psl" ../psl.log )
	touch psl.stamp

# Documentation is also re-generated in the clean tree so that regardless
# of history it should end up fresh and tidy.

docs.stamp:	$(BUILDTOPDIR).stamp
	(cd $(BUILDTOPDIR)/doc/misc ; script -c "time make"  ../../../docmisc.log )
	(cd $(BUILDTOPDIR)/doc/manual ; script -c "time make" ../../../docmanual.log )
	touch docs.stamp

# reduce.iss is the script for Inno Setup. It is created here by
# setting the string @here@ in it to the absolute path to this
# directory. That is so that when Inno Setup processes it there is no
# reliance on any "current directory".

reduce.iss:	reduce.iss.in
	sed -e 's#\@here\@#$(subst /,\\,$(shell cygpath -m $(abspath .)))#; s#\@VERSION\@#$(shell date +%Y-%m-%d)#' \
		<reduce.iss.in >reduce.iss

# The final step in the creation of an installer involved saving PSL
# images for both 32 and 64-bit versions and then invoking Inno Setup
# to pack up everything.

package-win:	$(BUILDTOPDIR).stamp csl.stamp psl.stamp docs.stamp reduce.iss
	$(BUILDTOPDIR)/psl/saveimage.sh $(BUILDTOPDIR)/pslbuild/x86_64-pc-windows \
		$(abspath .) '$$reduce/lib/psl' && mv reduce.img reduce64.img
	$(BUILDTOPDIR)/psl/saveimage.sh $(BUILDTOPDIR)/pslbuild/i686-pc-windows \
		$(abspath .) '$$reduce/lib/psl'
	if test -x "$(inno)/ISCC.exe"; then "$(inno)/ISCC" reduce.iss;\
		else echo Please run Innosetup on winbuild/reduce.iss; fi
# At present I do not know if the .cab files created here will be any
# use, but I will at least create SOMETHING so that they can be tested and
# negotiation as to just what is needed can begin.
	cd cslbuild && gcab -c -z ../Output/wincsl.cab \
		reduce.exe reduce.fonts reduce.img reduce.resources winreduce.exe
	d=`pwd` && cd $(BUILDTOPDIR)/pslbuild/i686* && \
		gcab -c -z $$d/Output/winpsl32.cab psl red
	d=`pwd` && cd $(BUILDTOPDIR)/pslbuild/x86_64* && \
		gcab -c -z $$d/Output/winpsl64.cab psl red


# It will be a really good idea to go "make clean" before any wholesale
# "make" here - this removes all the working files that get created
# during the build. It will leave any final installer that is in the
# directory "Output"

clean:
	rm -rf cyg*.exe add*.exe *red*.exe *.img $(BUILDTOPDIR) \
		cslwin32 cslwin64 cslcyg32 cslcyg64 \
		cslbuild log reduce.iss dll*.c *.stamp

# end of Makefile
