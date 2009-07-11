## Process this file with automake to produce Makefile.in

# For non-gcc compilers, change the options to "no-dependencies"
AUTOMAKE_OPTIONS = foreign dist-zip
#AUTOMAKE_OPTIONS = foreign dist-zip no-dependencies

SUBDIRS    = utils include src doc
EXTRA_DIST = ADDITIONS AUTHORS INSTALL LICENSE LICENSE_ADDENDUM TRACING README fox.lsm index.html aclocal.m4

bin_SCRIPTS = fox-config

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = fox.pc

CLEANFILES = fox.tar.gz

snapshot: dist-all
	cp $(distdir).tar.gz /net/linky/mnt/ftp/pub/fox-snapshot.tar.gz
	cp $(distdir).zip /net/linky/mnt/ftp/pub/fox-snapshot.zip



web: distdir
	cd $(distdir)/doc && doxygen doxygen.cfg
	cp -r $(distdir)/doc/* /net/linky/mnt/html

drop: dist-all
	cp $(distdir).tar.gz /net/linky/mnt/ftp/pub
	cp $(distdir).zip /net/linky/mnt/ftp/pub


#diff: distdir
#	-diff -P -c -r fox-1.1.8 $(distdir) > fox-patch-1.1.8-$(distdir)

# Suggestion for the above
# cvs rdiff -u -kk -r fox-1.0.8 -r fox-1.0.9 FOX > fox-path-1.0.8-1.0.9


#ref: distdir
#	(cd $(distdir)/include && doc++ -W -i -j --dir ../doc --footer ../doc/classFooter.inc --header ../doc/classHeader.inc *.h)
#	cp -r $(distdir)/doc/ref/* /home/html/ref


#dist-hook:
#	cp fox.spec $(distdir)
#	cp -dpR windows $(distdir)/windows
#	-find $(distdir)/windows -name CVS -exec rm -rf {} \;


# The following is a dummy target that helps a higher level build-system
fox:
	echo "building fox"
