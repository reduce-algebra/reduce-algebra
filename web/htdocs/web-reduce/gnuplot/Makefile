# This makefile downloads and builds a WebAssembly version of Gnuplot
# for use by Web REDUCE using Emscripten.  It is based on code from
# https://github.com/CD3/gnuplot-in-the-browser by C.D. Clark III.

# It works only on Linux, not on Cygwin!  But it works on Ubuntu 22.04
# in Windows Subsystem for Linux once make and a few libraries are
# installed.

# It assumes that the Emscripten directory emsdk is installed in your
# home directory.

version = 5.4.10

# This is the previous stable Gnuplot release as of March 2024; see
# http://www.gnuplot.info/.

gnuplot = gnuplot-$(version)

# Emscripten needs bash (more precisely, it doesn't seem to work with
# dash).
SHELL = /bin/bash

# Note that | before a prerequisite means it just has to exist but its
# timestamp is ignored; it is an order-only prerequisite.

# For Gnuplot configuration options, see ./configure --help

build/$(gnuplot)/src/gnuplot : ~/emsdk/emsdk_env.sh | build/$(gnuplot)
	if [ ! $$EMSDK ]; then . ~/emsdk/emsdk_env.sh; fi && \
	cd build/$(gnuplot) && \
	emconfigure ./configure \
	  --disable-largefile \
	  --disable-plugins \
	  --disable-history-file \
	  --disable-x11-mbfonts \
	  --disable-x11-external \
	  --disable-raise-console \
	  --disable-wxwidgets \
	  --disable-stats \
	  --without-libcerf \
	  --without-latex \
	  --without-x \
	  --without-x-dcop \
	  --without-aquaterm \
	  --without-readline \
	  --without-gd \
	  --without-lua \
	  --without-cwdrc \
	  --without-row-help \
	  --without-wx \
	  --without-wx-multithreaded \
	  --without-bitmap-terminals \
	  --without-tektronix \
	  --without-gpic \
	  --without-tgif \
	  --without-mif \
	  --without-regis \
	  --without-cairo \
	  --without-qt \
	  CFLAGS="-sUSE_ZLIB -Oz" \
	  LDLAGS="-sUSE_ZLIB -Oz" && \
	emmake make gnuplot

build/$(gnuplot) : build/$(gnuplot).tar.gz
	cd build && \
	tar xzf $(gnuplot).tar.gz

build/$(gnuplot).tar.gz : | build
	cd build && \
	wget https://sourceforge.net/projects/gnuplot/files/gnuplot/$(version)/$(gnuplot).tar.gz/download && \
	mv download $(gnuplot).tar.gz

build :
	mkdir build

~/emsdk/emsdk_env.sh :
	echo 'Please install or link Emscripten to your home directory.' && \
	exit 1


install : build/$(gnuplot)/src/gnuplot | termjs
	cp build/$(gnuplot)/src/gnuplot gnuplot.js
	cp build/$(gnuplot)/src/gnuplot.wasm .
	cp -r build/$(gnuplot)/term/js/{canvastext,gnuplot_common,gnuplot_dashedlines}.js termjs

termjs :
	mkdir termjs


clean :
	-rm -r build
