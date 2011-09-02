/* version.h                  Copyright (C) 1990-1997 Codemist Ltd */

/* Signature: 64847d4c 07-Feb-1999 */

#ifndef header_version_h
#define header_version_h 1

/*
 * VERSION is used to control the version number displayed when CSL/CCL
 * is started up in verbose mode (command line option -v). Version numbers
 * are also recorded in image files.
 */

#define VERSION     "5.00"

/*
 * The next two lines are processed by filesign.c on the basis of
 * of a private file register.key and a user name to give 64 bytes
 * of registration information, coded up as two strings of hex digits.
 */
#define REG1 "69d24b1690f1ca585906206121ad286e84ad98306b8273a4509249584fa048e9"
#define REG2 "ec223ed82d9a91419bbeba5df8dc624876b95a05bd1fa2c170a9b252a86383bc"

#endif /* header_version_h */

/* end of version.h */
