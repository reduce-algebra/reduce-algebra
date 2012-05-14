
all:	reduce-packages

reduce-packages:
	cd reduce ; debuild -B -us -uc 
	fakeroot alien -k -r reduce_*.deb
