#! /bin/bash

# This is the set of msys2 packages that I have in a mingw64/clang
# setup for ARM running on Windows 11 on ARM. The CSL configure
# scripts do not behave at the time I am checking this in, and the
# list here (created using "pacman -Q") is going to be redundant and
# have packages that are not actually needed... But it provides a
# starting position.

# To use. install msys2 on your WoA system (and to my amazement
# botspotVM on an 8Gb RPI5 does remarkably well, though a faster laptop
# is nicer). In the directory that is by defauly c:\msys64 run
# ./clangarm64.exe (explicitly giving the ".exe" part) and that
# gives you a shell where "clang" is a compiler targetting WoA.
# "pacman" is then your package manager and before doing anything else
# try "pacman -Su" which attempts a "full system upgrade". I hope that
# then running this file installs a fairly complete set of usefulness.

pacman -S apr apr-util autoconf-wrapper autoconf2.13 autoconf2.69
pacman -S autoconf2.71 autoconf2.72 automake-wrapper automake1.11
pacman -S automake1.12 automake1.13 automake1.14 automake1.15
pacman -S automake1.16 automake1.17 automake1.18 base bash
pacman -S bash-completion bc binutils bison brotli bsdtar bzip2
pacman -S ca-certificates ccache clang cmake coreutils cppdap
pacman -S curl cygrunsrv dash db diffutils doctest expat file
pacman -S filesystem findutils flex fmt gawk gcc gcc-libs gdb
pacman -S gdb-multiarch gdbm getent gettext git gmp gmp-devel
pacman -S gnupg grep groff gzip heimdal heimdal-libs inetutils
pacman -S info isl jsoncpp less libarchive libargp libasprintf
pacman -S libassuan libblake3 libbz2 libcbor libcurl libdb
pacman -S libedit libexpat libffi libffi-devel libfido2 libgc
pacman -S libgcrypt libgdbm libgettextpo libgnutls libgpg-error
pacman -S libguile libhogweed libiconv libidn2 libintl libksba
pacman -S libltdl liblz4 liblzma libnettle libnghttp2 libnghttp3
pacman -S libngtcp2 libnpth libopenssl libp11-kit libpcre libpcre2_8
pacman -S libpipeline libpsl libreadline librhash libsasl libserf
pacman -S libsqlite libssh2 libtasn1 libtool libunistring libutil-linux
pacman -S libuv libxcrypt libxxhash libzstd llvm m4
pacman -S make man-db mingw-w64-clang-aarch64-ansifilter
pacman -S mingw-w64-clang-aarch64-clang mingw-w64-clang-aarch64-clang-libs
pacman -S mingw-w64-clang-aarch64-compiler-rt mingw-w64-clang-aarch64-crt-git
pacman -S mingw-w64-clang-aarch64-gettext-runtime mingw-w64-clang-aarch64-gmp
pacman -S mingw-w64-clang-aarch64-headers-git mingw-w64-clang-aarch64-libc++
pacman -S mingw-w64-clang-aarch64-libffi mingw-w64-clang-aarch64-libiconv
pacman -S mingw-w64-clang-aarch64-libunwind
pacman -S mingw-w64-clang-aarch64-libwinpthread
pacman -S mingw-w64-clang-aarch64-libxml2 mingw-w64-clang-aarch64-lld
pacman -S mingw-w64-clang-aarch64-llvm-libs mingw-w64-clang-aarch64-llvm-tools
pacman -S mingw-w64-clang-aarch64-mpfr mingw-w64-clang-aarch64-termcap
pacman -S mingw-w64-clang-aarch64-texinfo mingw-w64-clang-aarch64-winpthreads
pacman -S mingw-w64-clang-aarch64-xz mingw-w64-clang-aarch64-zlib
pacman -S mingw-w64-clang-aarch64-zstd mingw-w64-clang-x86_64-bzip2
pacman -S mingw-w64-clang-x86_64-expat mingw-w64-clang-x86_64-gettext-runtime
pacman -S mingw-w64-clang-x86_64-libc++ mingw-w64-clang-x86_64-libffi
pacman -S mingw-w64-clang-x86_64-libiconv mingw-w64-clang-x86_64-libsystre
pacman -S mingw-w64-clang-x86_64-libtre mingw-w64-clang-x86_64-libunwind
pacman -S mingw-w64-clang-x86_64-mpdecimal mingw-w64-clang-x86_64-ncurses
pacman -S mingw-w64-clang-x86_64-openssl mingw-w64-clang-x86_64-python
pacman -S mingw-w64-clang-x86_64-python-ifaddr mingw-w64-clang-x86_64-readline
pacman -S mingw-w64-clang-x86_64-sqlite3 mingw-w64-clang-x86_64-tcl
pacman -S mingw-w64-clang-x86_64-termcap mingw-w64-clang-x86_64-tk
pacman -S mingw-w64-clang-x86_64-tzdata mingw-w64-clang-x86_64-xz
pacman -S mingw-w64-clang-x86_64-zlib mingw-w64-cross-common-binutils
pacman -S mingw-w64-cross-mingwarm64-binutils
pacman -S mingw-w64-cross-mingwarm64-crt mingw-w64-cross-mingwarm64-gcc
pacman -S mingw-w64-cross-mingwarm64-headers mingw-w64-cross-mingwarm64-tools
pacman -S mingw-w64-cross-mingwarm64-windows-default-manifest
pacman -S mingw-w64-cross-mingwarm64-winpthread
pacman -S mingw-w64-cross-mingwarm64-zlib mingw-w64-ucrt-x86_64-binutils
pacman -S mingw-w64-ucrt-x86_64-crt-git mingw-w64-ucrt-x86_64-gcc
pacman -S mingw-w64-ucrt-x86_64-gcc-libs mingw-w64-ucrt-x86_64-gettext-runtime
pacman -S mingw-w64-ucrt-x86_64-gmp mingw-w64-ucrt-x86_64-headers-git
pacman -S mingw-w64-ucrt-x86_64-isl mingw-w64-ucrt-x86_64-libiconv
pacman -S mingw-w64-ucrt-x86_64-libwinpthread mingw-w64-ucrt-x86_64-mpc
pacman -S mingw-w64-ucrt-x86_64-mpfr
pacman -S mingw-w64-ucrt-x86_64-windows-default-manifest
pacman -S mingw-w64-ucrt-x86_64-winpthreads mingw-w64-ucrt-x86_64-zlib
pacman -S mingw-w64-ucrt-x86_64-zstd mingw-w64-x86_64-editrights
pacman -S mintty mpc mpdecimal mpfr mpfr-devel msys2-keyring
pacman -S msys2-launcher msys2-runtime msys2-runtime-devel msys2-w32api-headers
pacman -S msys2-w32api-runtime nano ncurses ncurses-devel nettle
pacman -S openssh openssl p11-kit pacman pacman-contrib pacman-mirrors
pacman -S perl perl-Authen-SASL perl-Clone perl-Convert-BinHex
pacman -S perl-Encode-Locale perl-Error perl-File-Listing perl-HTML-Parser
pacman -S perl-HTML-Tagset perl-HTTP-Cookies perl-HTTP-Daemon perl-HTTP-Date
pacman -S perl-HTTP-Message perl-HTTP-Negotiate perl-IO-HTML
pacman -S perl-IO-Socket-SSL perl-IO-Stringy perl-LWP-MediaTypes
pacman -S perl-MIME-tools perl-MailTools perl-Net-HTTP
pacman -S perl-Net-SMTP-SSL perl-Net-SSLeay perl-TermReadKey perl-TimeDate
pacman -S perl-Try-Tiny perl-URI perl-WWW-RobotRules perl-http-cookiejar
pacman -S perl-libwww pinentry pkgconf python rebase rsync sed
pacman -S subversion tar time tzcode util-linux vim wget which
pacman -S windows-default-manifest xxhash xz zlib zstd
