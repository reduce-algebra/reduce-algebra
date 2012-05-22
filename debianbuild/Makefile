
SNAPSHOT=$(shell LANG=C date "+%Y%m%d")
NOW=$(shell LANG=C date "+%a, %d %b %Y %T %z")
CHANGELOG=reduce/debian/changelog

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
 

reduce-packages:
	cd reduce ; debuild -b -us -uc 
	fakeroot alien -k -r reduce-$(SNAPSHOT)_*.deb
