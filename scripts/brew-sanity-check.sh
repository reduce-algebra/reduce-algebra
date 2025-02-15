#! /bin/bash

failed=""

for x in \
   aom                   apr                   apr-util              \
   assimp                astyle                at-spi2-core          \
   autoconf              automake              bc bison              \
   blake3                brotli                ca-certificates       \
   cairo                 ccache        cmake   dbus                  \
   docbook               docbook-xsl           docutils              \
   double-conversion     fmt                   fontconfig            \
   freetype              fribidi       gawk    gd                    \
   gdk-pixbuf            gettext               giflib                \
   git                   glib                  gmp                   \
   gnu-getopt            gnu-sed               gnu-time              \
   gnuplot               gobject-introspection graphite2             \
   harfbuzz              highway               hiredis               \
   hunspell              icu4c                 icu4c@76              \
   imath                 isl                   jasper                \
   jpeg-turbo            jpeg-xl               ldns                  \
   libavif               libb2                 libcbor               \
   libcerf               libdeflate            libedit               \
   libffi                libfido2              libgccjit             \
   libmng                libmpc                libpng                \
   libtiff               libtool               libunistring          \
   libvmaf               libx11                libxau                \
   libxcb                libxdmcp              libxext               \
   libxfixes             libxi                 libxtst               \
   little-cms2           lua                   lz4                   \
   lzo                   m4                    md4c                  \
   meson                 mpdecimal             mpfr                  \
   ncurses               ninja                 openexr               \
   openssh               openssl@3             pango                 \
   pcre2                 pixman                pkgconf               \
   popt                  python-packaging      python-setuptools     \
   python@3.12           python@3.13           qt                    \
   readline              rsync                 scons                 \
   sqlite                subversion            swig                  \
   texinfo               timelimit             utf8proc              \
   util-macros           webp                  xmlto                 \
   xorgproto             xquartz               xtrans                \
   xxhash                xz                    zstd                  \
   zlib                  libxft                libxcursor            \
   libxrender            bzip2                 expat                 \
   libxrandr
do
  echo "About to install $x"
  if ! brew install $x
  then
    failed = "$failed $x"
  fi
done

if test "$failed" = ""
then
  echo "All done - looks OK"
else
  echo "Fails to install $failed"
fi

# end of script

