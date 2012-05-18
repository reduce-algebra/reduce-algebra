
all:	reduce-packages

reduce-packages:
	cd reduce ; debuild -b -us -uc 
	fakeroot alien -k -r reduce-*.deb
