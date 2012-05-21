
SNAPSHOT=$(shell LANG=C date "+%Y%m%d")
NOW=$(shell LANG=C date "+%a, %d %b %Y %T %z")
CHANGELOG=reduce/debian/changelog

all:	update-changelog reduce-packages

update-changelog:
	head -1 $(CHANGELOG) | grep $(SNAPSHOT) || \
        cp $(CHANGELOG) $(CHANGELOG).old && \
	( echo "reduce ("$(SNAPSHOT)") unstable; urgency=low" ; \
          echo ; \
          echo "  * New Snapshot." ; echo ; \
	  echo " -- REDUCE Developers <reduce-algebra-developers@lists.sourceforge.net> " $(NOW) ;\
	  echo ) > $(CHANGELOG) && \
        cat $(CHANGELOG).old >> $(CHANGELOG)
 

reduce-packages:
	cd reduce ; debuild -b -us -uc 
	fakeroot alien -k -r reduce-*.deb
