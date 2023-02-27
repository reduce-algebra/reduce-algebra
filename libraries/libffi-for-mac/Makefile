# This may for a template for creating MacOS "universal" binaries
# and libraries. It creates arm64 and an x86_64 versions and then
# merges them using "lipo". This version is for the fairly extreme
# case where arm64 and x86_64 use different sets of source files
# and may use different configure-detected options, so running a single
# universal compilation with "-arch arm64 -arch x86_64" is not viable.

all:
	$(MAKE) dirs
	$(MAKE) doarm64
	$(MAKE) dox86_64
	$(MAKE) libs

install:	all

dirs:
	rm -rf arm64 build-arm64 x86_64 build-x86_64
	mkdir -p arm64 build-arm64
	mkdir -p x86_64 build-x86_64

doarm64:
	cd build-arm64 && \
	@srcdir@/libraries/libffi-for-mac/libffi-3.3-arm64/configure \
	    --host=arm64-apple-darwin \
	    CFLAGS="-arch arm64" \
	    CXXFLAGS="-arch arm64" \
	    LDFLAGS="-arch arm64" \
	    --disable-multi-os-directory \
	    --prefix=`pwd`/../arm64 && \
	make && make install

dox86_64:
	cd build-x86_64 && \
	@srcdir@/libraries/libffi-for-mac/libffi-3.3-x86_64/configure \
	    --host=x86_64-apple-darwin \
	    CFLAGS="-arch x86_64" \
	    CXXFLAGS="-arch x86_64" \
	    LDFLAGS="-arch x86_64" \
	    --disable-multi-os-directory \
	    --prefix=`pwd`/../x86_64 && \
	make && make install

libs:
	mkdir -p ../lib && \
	mkdir -p ../include && \
	mkdir -p ../share && \
	cp -r arm64/include/* ../include && \
	cp -r arm64/share/* ../share && \
	lipo -create -output ../lib/libffi.a arm64/lib/libffi.a x86_64/lib/libffi.a && \
	lipo -create -output ../lib/libffi.7.dylib arm64/lib/libffi.7.dylib x86_64/lib/libffi.7.dylib && \
	cp -r arm64/lib/pkgconfig ../lib && \
	cd ../lib && \
	rm -f libffi.dylib && \
	ln -s libffi.7.dylib libffi.dylib && \
	for x in *libffi*.a *libffi*.dylib ; \
	do \
	  printf "Architectures for $$x: " ; \
	  lipo -archs $$x ; \
	done
