#! /bin/sh -v
# This fetches up-to-date copy of libedit from the NetBSD site and
# saves it in a directory tagged with today's date.
wget -r ftp://ftp.netbsd.org/pub/NetBSD/NetBSD-current/src/lib/libedit
mv ftp.netbsd.org/pub/NetBSD/NetBSD-Current/src/lib/libedit \
  libedit-`date +%Y%m%d`
rm -rf ftp.netbsd.org
