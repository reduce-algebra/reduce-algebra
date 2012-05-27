/*
 *  "xport.c"               Copyright (C) Codemist Ltd 1994-2009
 *
 *              Fetch files from a remote web site with checksums,
 *              line-end conversion and other capabilities.
 *
 *              This version is just in a single file.
 */

/*
 * This program is intended to make it easier to keep several sites
 * in lock-step with regard to some file-tree.
 * This is supported by keeping a collection of (smallish) files in
 * the root of the tree, selecting that place as current directory and
 * running this "xport" program.  The options available are:
 *
 *     xport -version      give some version info!
 *     xport -sign         create local signature file
 *     xport -increment    create differential signature file xport.inc
 *     xport -inc          [short form for above]
 *     xport -diff         create differential signature file xport.dif
 *     xport -check        check current state against local signatures
 *     xport -check=dir    go to that directory and check it...
 *
 *     xport -fetch        update from a remote master version, renaming
 *                         an updated file xxx.yyy as xxx.yyy.old so you still
 *                         have the previous version to check
 *     xport -fetch=site   ditto, selecting alternate master site
 *     xport -fetch -stamp As "-fetch" but give fetched files today's date
 *     xport -fetch=site -stamp
 *     xport -report       indicate what "xport -fetch" would fetch
 *     xport -report=site  ditto, but alternate site
 *     xport -force        as -fetch but update local files even if
 *                         checksum validation fails. Useful if the
 *                         master site has not kept its signatures
 *                         fully up to date
 *     xport -force -stamp
 *     xport -send=loc     (eg loc could be user@host:path) Use ssh to
 *                         send from current directory to given place,
 *                         supposing that the command "xport" is available
 *                         at the other end.
 *     xport -get URL      fetch a single file to standard output
 *     xport -get URL dest fetch a single file to named destination
 *     xport -bget ...     BINARY mode "get"
 *     xport -tidy         delete all files named *.old in the whole tree.
 *
 *     xport -quiet ...    make less noise!
 *     xport -noisy ...    make more noise!
 *     xport -nodelete ... do not delete old files
 *     xport -hostcase ... act as if "hostcase" flag was set in xport.pat
 *     xport -nohostcase ... opposite action to above
 *
 *     xport ... -to=dest ...         redirect stdout to given file
 *
 *     xport ... -auth=user:pw ...    force HTTP of FTP identity
 *     xport ... -user=name           specify username for "ssh://?@"
 *     xport ... -sshdir=dir ...      location of ssh and scp locally
 *                                    in case private versions are needed.
 *     xport ... -remote-xport=filename ... 
 *                                    location of xport on the REMOTE machine
 *                                    when "send" is being used.
 *
 *
 * NOTE: that this utility treats some files with name "xport.*" and
 * "*.old" specially so if you happen to have user-files with such names
 * you need to read carefully...
 *
 *
 * The "site" given can either be a tag, as declared in xport.pat and
 * explained below, or it can be an URL for the directory on the remote
 * machine.
 * Tags and much more information are declared in a file "xport.pat". The
 * important lines that can be in such a file are:
 *
 *   master=tag URL
 *         eg master=main   http://www.xyz.com/product/current
 *            master=secure scp://my.username@my.host:directory
 *            master=by_ftp ftp://user:password@host:directory
 *                     where writing "?" for password gets xport to prompt
 *
 * There can be several master sites specified. By default the first one
 * listed will be used.
 *
 *   Include p1 p2 ...
 *   Omit p1 p2 ...
 *           cause files as specified by the patterns to be included or not.
 *           A double wild-card "**" matches an arbitrary length string of
 *           junk including directory separators, while "*" matches arbitrary
 *           characters but not across directory marks. It is as if there is
 *           an "Omit **.old" at teh start of xport.pat. Some xport related
 *           files are automatically omitted and can not be included whatever
 *           you say in xport.pat
 *
 *   Binary p1 p2 ...
 *   Text p1 p2 ...
 *           xport normally tries to guess whether files should be sent as
 *           binary or text. This tells it what to do. Eg "Binary **.o" might
 *           make sense.
 *
 *   Executable p1 p2 ...
 *   NonExecutable p1 p2 ...
 *           On Unix-like systems these files should have the executable
 *           attribute forced, as in "chmod +x p1 p2". Other files should
 *           NOT be executable. Well I will install some default patterns
 *           for things I will mark as executable...
 *
 *   Encrypted p1 p1
 *           Indicates that the files concerned may be stored in an encrypted
 *           form. A file "xport.key" should then be present and will give
 *           more information. See later for its use.
 *
 *   nohostcase
 *   mixedcase p1 p1 ...
 *           These are a hang-over from support of Windows 3.x and case
 *           insensitive file systems. They should hardly ever be need.
 *
 *   # comment
 *           "xport.pat" files can contain comments!
 *
 *
 * "xport -sign" creates or updates a file "xport.chk" that lists all files
 * present in the directory and notes a checksum for each one. This file
 * also contains information about date-stamps and whether the file involved
 * is a directory or if it seems to contain binary information.
 *
 * Files can be omitted from processing by putting a note in the file
 * "xport.pat". A line here that says
 *     Omit <pattern>
 * causes the system to ignore those files when creating xport.chk.
 * In patterns "*" matches zero or more characters BUT NOT "/", while "**"
 * matches any string of characters at all.  Thus
 *     Omit *.bak **.tmp
 * will omit ".bak" files in the root of the tree but ".tmp" files
 * anywhere within it.
 * In addition the "xport.pat" file can say "Include" to force inclusion
 * of some file (eg over-riding a previous omit, as in
 *      Omit *.tmp
 *      Include important.tmp
 * and arbitrary sequences of Omit and Include can be given.
 * Files can be  explicitly marked as text/binary in a similar way.
 *
 *
 * "xport -check" expects "xport.chk" to be present (either generated locally
 * some while ago or FTP'd in from some other (master?) site. It checks
 * the current state of the local tree against this and reports on
 * discrepancies. The format of its output is under review.
 *
 * Sites for fetching from are given in xport.pat with lines such as
 *      Master http://www.companyname.co.uk/distrib/package
 * where the first or only such line is used if just "-fetch" or
 * "-report" is used. The line can specify a site nickname as in
 *      Master=alt http://backup.site.name/codemist/archive/distrib/package
 * and if such a line is present the user can say "xport -fetch=alt" to
 * use it. An URL (specifically an HTTP one) can contain a user-name and
 * password as in "http://user:pw@site/path" to use basic authentocation,
 * and if user or pw is given as "?" this code should prompt for the
 * secret value needed.
 *
 *
 * "-auth=user:pw" sets default for user-name and password in transfers
 * that need authentication: ie it may be useful for FTP and HTTP transfers
 * where the URL in "xport.pat" does not contain the authentication data
 * that is needed. If "-auth=" is not used the system checks for a shell
 * variable XPORT_AUTH (in upper case) and expects the value there to be
 * a user:password pair.
 *
 * In order that transfers should work properly between Unix and Windows
 * systems there are two fairly significant delicacies:
 *   (a) Any file that must be transferred between systems in binary mode
 *       and where this fact will not be manifestly obvious from the
 *       file contents must be listed in xport.pat. A special and important
 *       case will be files where the end-of-line markers do not follow the
 *       native conventions on the computer they reside on, or ones where
 *       fseek() will be used to locate data. So please use "Binary p1..."
 *       and "Text p1 ..." where there is any chance of ambiguity.
 *   (b) The windows version uses Cygwin ans so all file-name characteristics
 *       and other portability issues flow from that.
 *
 * Here is a list of the files used by this utility:
 *
 *   xport.pat       Information about what files and sub-directories should
 *                   be processed, and about text/binary files and
 *                   files whose names are anything other than all lower case.
 *                   This file also contains the name of any master sites that
 *                   can be used to refresh the local copy.
 *   xport.chk       Baseline list of files and checksums. Created by
 *                   master site using "xport -sign" and copied verbatim
 *                   to slave sites.
 *   xport.inc       Incremental changes to xport.chk, created at master
 *                   site by "xport -inc" and copied verbatim to slave
 *                   sites.
 *   xport.dif       Incremental changes at a slave site from the xport.chk
 *                   stored there. Created by "xport -diff" and intended
 *                   for comparison with xport.inc (which comes from the
 *                   master site) when deciding what needs updating.
 *   xport.tmp       When xport fetches a file from a remote site it always
 *                   puts the fetched material in xport.tmp and when it
 *                   has been able to verify that the whole file has been
 *                   retrieved properly it renames from xport.tmp to
 *                   whatever the proper file name is. The reasoning
 *                   behind this is to arrange that if a transfer fails
 *                   part way through or if data is corrupted in transit the
 *                   user is not left with a half-complete or mangled file.
 *   xport.tm1       Copy of xport.chk from master site, held at slave site
 *                   if this file had changed. After the slave site has been
 *                   completely updated this is moved to xport.chk.
 *   xport.tm2       Copy of xport.inc fetched from the master site. When an
 *                   update operation completes this is moved to become the
 *                   new local xport.inc.
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <stdarg.h>

#include <sys/types.h>

#ifdef HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif

#ifdef HAVE_DIRENT_H
#include <dirent.h>
#else
#include <sys/types.h>
#include <sys/dir.h>
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <errno.h>

#include <utime.h>
#include <termios.h>        /* So I can do non-echo terminal input */

typedef int                 int32;
typedef unsigned int        unsigned32;

typedef int                 bool;
#define TRUE                1
#define FALSE               0

#define DIRECTORY_CHAR    '/'

#define seems_binary(c)                                 \
               ((c<32 &&                                \
                 c!='\n' && c!='\t' && c!='\r' &&       \
                 c!='\a' && c!='\b' && c!='\f') ||      \
                (c == 0x7f) ||                          \
                ((c & 0x80)!=0 &&                       \
                 c!=0xa9 && c!=0xb8 && c!=0xa3))


#define LONGEST_LEGAL_FILENAME  256

extern int Cmkdir(char *s);

extern int truncate_file(FILE *f, long int where);

extern void make_unix_style_filename(char *filename, const char *old);

extern void make_local_style_filename(char *filename, const char *old);

/*
 * datestamps that I put in archives have given me significant
 * trouble with regard to portability - so now I deal with times by
 * talking to the system in terms of broken down local time (struct tm).
 * I then pack things up for myself to get 32-bit timestamps. The
 * encoding I use aims at simplicity - it treats all months as 31 days
 * and thus does not have to worry about leap years etc.  NOTE this means
 * that timestamps in previously created CAR archives will be decoded
 * in a wrong-minded way by the new version.  Tough luck.
 */

extern void unpack_date(unsigned32 r,
                        int *year, int *mon, int *day,
                        int *hour, int *min, int *sec);

extern unsigned32  pack_date(int year, int mon, int day,
                             int hour, int min, int sec);

typedef struct date_and_type
{
    unsigned32 date;
    int type;
} date_and_type;

/* Reinstate date and filetype... */

extern void set_filedate(char *name, unsigned32 datestamp,
                                     int ftype);

extern void get_fileinfo(date_and_type *p, char *name);

/*
 * If I am to process directories I need a set of routines that will
 * scan sub-directories for me. The specification I want is:
 *       int scan_directory(char *dir,
 *                    void (*proc)(char *name, int why, int32 size));
 *
 * This is called with a file- or directory-name as its first argument
 * and a function as its second.
 * It calls the function for every directory and every file that can be found
 * rooted from the given place.  If the file to scan is specified as NULL
 * the current directory is processed.
 * When a simple file is found the procedure is called with the name of the
 * file, why=0, and the length (in bytes) of the file.  For a directory
 * the function is called with why=1, then the contents of the directory are
 * processed. For directories the size information will be 0.  There is no
 * guarantee of useful behaviour if some of the files to be scanned are
 * flagged as  "invisible" or "not readable" or if they are otherwise special.
 * The value returned is the number of characters that should be removed
 * the start of file-names returned to get rid of any initial directory
 * specified.  If dir is passed as NULL this will be zero and names will
 * come back plain, otherwise it will be 1+strlen(dir)
 */

#define SCAN_FILE       0
#define SCAN_STARTDIR   1
#define SCAN_ENDDIR     2

extern void scan_directory(char *dir,
                           void (*proc)(char *name, int why, long int size));

/*
 * When scan_directory calls the procedure it has been passed, it will have
 * set scan_leafstart to the offset in the passed filename where the
 * original directory ended and the new information starts. Thus if the
 * original string was (say) "/usr/users/acn/xxx" then files in that directory
 * will have names like "/usr/users/acn/xxx/subdir/subfile.ext" and
 * (name+scan_leafstart) will be the string "subdir/subfile.ext" being
 * relative the to name of the directory originally specified.
 */

extern int scan_leafstart;

/*
 * scan_files() is just like scan_directory() except that it does not
 * recurse into sub-directories.
 */

extern void scan_files(char *dir,
                       void (*proc)(char *name, int why, long int size));

/*
 * set_hostcase(flag) tells scan_directory & scan_files whether to
 * fold file-names into monocase or leave them as whatever the host
 * said they were.
 */

extern void set_hostcase(int fg);


extern int wildmatch(char *pattern, char *filename);

extern int casefold_match(char *outname, char *pattern, char *filename);

#define SOCKET_BUFFER_SIZE 20480

typedef struct socket_file socket_file;

extern int ensure_sockets_ready();
extern int ssh_ensure_sockets_ready(char *directory_to_find_ssh_in);
extern void finished_with_sockets();

extern char *set_forced_proxy(char *proxy);

extern socket_file *open_url(char *w, int binary_mode);
extern socket_file *open_auth_url(char *w, int binary_mode,
                                  char *user, char *password);
extern int char_from_data(socket_file *p);
extern void close_socket(socket_file *p);

extern void set_suser(char *s);

/*
 *      cross-platform support for filenames etc
 *
 */


/*
 * datestamps that I store away have given me significant
 * trouble with regard to portability - so now I deal with times by
 * talking to the system in terms of broken down local time (struct tm).
 * I then pack things up for myself to get 32-bit timestamps. The
 * encoding I use aims at simplicity - it treats all months as 31 days
 * and thus does not have to worry about leap years etc.  The effect will be
 * rather as if dates were stored as strings. And MAYBE I thereby avoid
 * some of the oddities that arise when data files containing packed dates
 * are transported across time-zones.
 *
 * NOTE: dates here are based from 1970, and this will lead to overflow
 * beyond 32-bit offsets in around 2099. At the time of writing that is
 * almost 100 years ahead, and I intend not to worry.
 *
 * ANOTHER NOTE: I only allow the "seconds" field to run from 0 to 59.
 * In consequence I am quite possibly going to mess up when there are
 * leap seconds, and this confusion could make times processed here
 * disagree across systems by up to the number of leap seconds that
 * have been used to date. Well I have quite severe doubts about time
 * agreement closer than a few seconds anyway and so again I am going to
 * ignore this oddity!
 */

void unpack_date(unsigned32 r,
                 int *year, int *mon, int *day,
                 int *hour, int *min, int *sec)
{
    *sec  = r%60; r = r/60;
    *min  = r%60; r = r/60;
    *hour = r%24; r = r/24;
    *day  = r%32; r = r/32;
    *mon  = r%12; r = r/12;
/*
 * Please note that the Standard C "struct tm" structure specifies dates
 * in terms of years since 1900. Thus from the year 2000 on the year will
 * be a value of at least 100, but that is not supposed to be any special
 * cause of disaster. In particular the calculation involving "+70"
 * rather than "+1970" is NOT a bug here!
 */
    *year = 70+r;
}

unsigned32 pack_date(int year, int mon, int day,
                     int hour, int min, int sec)
{
    unsigned32 r = (year-70)*12 + mon;
    r = r*32 + day;
    r = r*24 + hour;
    r = r*60 + min;
    return r*60 + sec;
}

int truncate_file(FILE *f, long int where)
{
    if (fflush(f) != 0) return 1;
    return ftruncate(fileno(f), where);  /* Returns zero if success */
}

/* extern void mkdir(const char *, unsigned short int); */

int Cmkdir(char *s)
{
#ifdef HAVE_MINGW
    mkdir(s);
#else
    mkdir(s, 0775);
#endif
    return 1;
}

void make_local_style_filename(char *filename, const char *old)
{
    strcpy(filename, old);
    return;
}

void make_unix_style_filename(char *filename, const char *old)
{
    strcpy(filename, old);
    return;
}

void set_filedate(char *name, unsigned32 datestamp, int filetype)
{
#ifdef UTIME_TIME_T
    time_t tt[2];
#else
    struct utimbuf tt;
#endif
    time_t t0;
    struct tm st;
    unpack_date(datestamp, &st.tm_year, &st.tm_mon, &st.tm_mday,
                           &st.tm_hour, &st.tm_min, &st.tm_sec);
    st.tm_isdst = -1;
    t0 = mktime(&st);
#ifdef UTIME_TIME_T
    tt[0] = tt[1] = t0;
#else
    tt.actime = tt.modtime = t0;
#endif
#ifdef HAVE_SYS_STAT_H
    chmod(name, filetype);
#endif
    utime(name, &tt);
}

void get_fileinfo(date_and_type *p, char *name)
{
    struct stat file_info;
    struct tm *st;
    stat(name, &file_info);
    st = localtime(&(file_info.st_mtime));
    p->date = pack_date(st->tm_year, st->tm_mon, st->tm_mday,
                        st->tm_hour, st->tm_min, st->tm_sec);
    p->type = file_info.st_mode;
}


/*
 *
 * Directory scanning code for use in CSL-related utilities.
 *
 */



/*
 * If I am to process directories I need a set of routines that will
 * scan sub-directories for me.  This is (necessarily?) dependent on
 * the operating system I am running under, hence the conditional compilation
 * here.  The specification I want is:
 *       void scan_directory(char *dir,
 *                    void (*proc)(char *name, int why, long int size));
 *
 * This is called with a file- or directory-name as its first argument
 * and a function as its second.
 * It calls the function for every directory and every file that can be found
 * rooted from the given place.  If the file to scan is specified as NULL
 * the current directory is processed. I also arrange that an input string
 * "." is treated as a request to scan the whole of the current directory.
 * When a simple file is found the procedure is called with the name of the
 * file, why=0, and the length (in bytes) of the file.  For a directory
 * the function is called with why=1, then the contents of the directory are
 * processed. For directories the size information will be 0.  There is no
 * guarantee of useful behaviour if some of the files to be scanned are
 * flagged as  "invisible" or "not readable" or if they are otherwise special.
 *
 * I also provide a similar function scan_files() with the same arguments that
 * does just the same except that it does not recurse into sub-directories,
 * but if the name originally passed is that of a directory then all the
 * files in it will be scanned.
 */

/*
 * When scan_directory calls the procedure it has been passed, it will have
 * set scan_leafstart to the offset in the passed filename where the
 * original directory ended and the new information starts.
 */

int scan_leafstart = 0;

/* #define SCAN_FILE       0      defined earlier - listed here for emphasis */
/* #define SCAN_STARTDIR   1 */
/* #define SCAN_ENDDIR     2 */

/*
 * I use a (static) flag to indicate how sub-directories should be
 * handled, and what to do about case. By default I fold to lower case
 * on windows. Setting hostcase non-zero causes case to be preserved.
 * Possibly these days I should expect that even on Windows all files will
 * have a definitive case?
 */

static int recursive_scan, preserve_hostcase = 0;

/*
 * The following is an expression of despair! ANSI C (all the way back from
 * 1989, and based on good practise from before then, mandates that
 * realloc should behave as malloc if its first arg is NULL. But STILL there
 * are C libraries out there which do not honour this and which crash
 * in such cases. Thus this veneer ought to be unnecessary but in reality
 * is a useful safety net!
 */
static void *my_realloc(void *p, int len)
{
   if (p == NULL) return malloc(len);
   else return realloc(p, len);
}

void set_hostcase(int fg)
{
    preserve_hostcase = fg;
}

static char filename[LONGEST_LEGAL_FILENAME];

/*
 * The code here uses opendir, readdir and closedir and as such ought to
 * be Posix compatible. The macro USE_DIRECT_H can cause an older variant
 * on this idea to be used. BUt it may need adjustment for different
 * systems.
 */

static char **found_files = NULL;

int n_found_files = 0, max_found_files = 0;

#define TABLE_INCREMENT 50

static int more_files()
{
    if (n_found_files > max_found_files - 5)
    {   char **fnew = (char **)
            my_realloc((void *)found_files,
                       sizeof(char *) *
                          (max_found_files + TABLE_INCREMENT));
        if (fnew == NULL) return 1;  /* failure flag */
        found_files = fnew;
        max_found_files += TABLE_INCREMENT;
    }
    return 0;
}

int alphasort_files(const void *a, const void *b)
{
    const char *fa = *(const char **)a,
               *fb = *(const char **)b;
    return strcmp(fb, fa);
}

extern int stat(const char *, struct stat*);

static void scan_file(int namelength,
                      void (*proc)(char *name, int why, long int size));

static void exall(int namelength,
                  void (*proc)(char *name, int why, long int size))
{
    DIR *d;
#ifdef HAVE_DIRENT_H
    struct dirent *dd;
#else
    struct direct *dd;
#endif
    int i, j;
    int rootlen = namelength, first = n_found_files;
    proc(filename, SCAN_STARTDIR, 0);
    d = opendir(filename);
    if (d != NULL)
    {   while ((dd = readdir(d)) != NULL)
        {   char *leafname = dd->d_name; 
            char *copyname;
/*
 * readdir hands back both "." and ".." but I had better not recurse
 * into either!
 */
            if (strcmp(leafname, ".") == 0 ||
                strcmp(leafname, "..") == 0) continue;
            if (more_files()) break;
            copyname = (char *)malloc(1+strlen(leafname));
            if (copyname == NULL) break;
            strcpy(copyname, leafname);
            found_files[n_found_files++] = copyname;
        }
        closedir(d);
    }

    qsort((void *)&found_files[first],
          n_found_files-first,
          sizeof(char *),
          alphasort_files);

    filename[rootlen] = '/';
    while (n_found_files != first)
    {   char *p = found_files[--n_found_files];
        int c;
        namelength = rootlen+1;
        while ((c = *p++) != 0) filename[namelength++] = c;
        free((void *)found_files[n_found_files]);
        filename[namelength] = 0;
        scan_file(namelength, proc);
    }

    filename[rootlen] = 0;
    proc(filename, SCAN_ENDDIR, 0);
}

#ifndef S_IFMT
# ifdef __S_IFMT
#  define S_IFMT __S_IFMT
# endif
#endif

#ifndef S_IFDIR
# ifdef __S_IFDIR
#  define S_IFDIR __S_IFDIR
# endif
#endif

#ifndef S_IFREG
# ifdef __S_IFREG
#  define S_IFREG __S_IFREG
# endif
#endif

static void scan_file(int namelength,
                      void (*proc)(char *name, int why, long int size))
{
    struct stat buf;
    stat(filename, &buf);
    if ((buf.st_mode & S_IFMT) == S_IFDIR)
    {   if (!recursive_scan) proc(filename, SCAN_STARTDIR, 0);
        else exall(namelength, proc);
    }
    else if ((buf.st_mode & S_IFMT) == S_IFREG)
        proc(filename, SCAN_FILE, buf.st_size);
/*  else fprintf(stderr, "Mode of %s is %o\n", filename, buf.st_mode); */
}

void scan_directory(char *dir,
                    void (*proc)(char *name, int why, long int size))
{
    recursive_scan = 1;
    if (dir==NULL || strcmp(dir, ".")==0) dir = ".";
    scan_leafstart = strlen(dir)+1;
    strcpy(filename, dir);
    scan_file(scan_leafstart-1, proc);
}

void scan_files(char *dir,
                void (*proc)(char *name, int why, long int size))
{
    recursive_scan = 0;
    if (dir==NULL || strcmp(dir, ".")==0) dir = ".";
    scan_leafstart = strlen(dir)+1;
    strcpy(filename, dir);
    exall(scan_leafstart-1, proc);
}



/*
 *      Matching of file-names against wild-card patterns
 *
 */


/*
 * wildmatch(pattern, string) allows the pattern to contain '*' characters
 * which will match an arbitrary string of characters from the target
 * string, but NOT a directory separator character. Note that when this
 * is used filenames may be in Unix format so I can use "/" as a directory
 * separator, or they may be in DOS format with '\'. But sometimes people
 * will want arbitrary strings including "/" chars - so at least as a
 * temporary provision I allow "**" to match an arbitrary unrestricted
 * bunch of characters.
 */

int wildmatch(char *pattern, char *filename)
{
    while (*pattern == *filename)
    {   pattern++;
        if (*filename++ == 0) return 1;
    }
/*
 * I allow a pattern that is the name of a directory to match all
 * files in that directory.
 */
    if (*pattern == 0)
        return (*filename == 0 || *filename == '/' || *filename == '\\');
/*
 * In a pattern "*" matches zero or more characters but NOT including
 * a directory separator, while "**" matches characters and can match
 * "/" or "\". Thus the pattern "*.old" matches just files at top
 * level, while "**.old" will be ones at any level.
 */
    if (*pattern == '*' && *(pattern+1)=='*')
    {   while (*filename != 0)
        {   if (wildmatch(pattern+2, filename)) return 1;
            filename++;
        }
        return wildmatch(pattern+2, filename);
    }
    else if (*pattern == '*')
    {   while (*filename != 0 && *filename != '/' && *filename != '\\')
        {   if (wildmatch(pattern+1, filename)) return 1;
            filename++;
        }
        return wildmatch(pattern+1, filename);
    }
    return 0;
}

/*
 * casefold_match copies a name into the string (outname), and reports
 * if the pattern and the filename match in a case-insensitive manner.
 * If they do then then outname will end up with case filled in from
 * the pattern where possible, and 1 will be returned.
 */

int casefold_match(char *outname, char *pattern, char *filename)
{
    while (tolower(*pattern) == tolower(*filename))
    {   *outname++ = *pattern++;
        if (*filename++ == 0)
        {   *outname = 0;
            return 1;
        }
    }
/*
 * I allow a pattern that is the name of a directory to match all
 * files in that directory.
 */
    if (*pattern == 0)
    {   if (*filename == 0 || *filename == '/' || *filename == '\\')
        {   strcpy(outname, filename);
            return 1;
        }
        else return 0;
    }
    if (*pattern == '*' && *(pattern+1) == '*')
    {   while (*filename != 0)
        {   if (casefold_match(outname, pattern+2, filename)) return 1;
            *outname++ = *filename++;
        }
        return casefold_match(outname, pattern+1, filename);
    }
    else if (*pattern == '*')
    {   while (*filename != 0 && *filename != '/' && *filename != '\\')
        {   if (casefold_match(outname, pattern+1, filename)) return 1;
            *outname++ = *filename++;
        }
        return casefold_match(outname, pattern+1, filename);
    }
    return 0;
}


/*
 *     Code to access things over the internet, arranged as a stand-alone
 *     chunk of routines.  Roughly patterned after a perl-coded package
 *     called "webget.pl" that was written by Jeffrey Friedl
 *     (jfrield@omron.co.jp), but re-written in C from scratch.
 *
 *  Usage:
 *       ensure_sockets_ready()
 *       struct socket_file *a = open_url("http://www.xxx.yyy/file/name.zz", 0);
 * OR     .. = open_auth_url("http...", 0, "user", "password");
 * abd the final 0 is for a text fetch, and could be 1 for a binary fetch.
 *       while ((c = char_from_data(a)) != EOF) ...
 *       close_socket(a);
 *       finished_with_sockets();
 *
 *  The url is either like
 *         http://machine.address:port/path-name/for/object
 *  or     http://username:password@machine.address:port/path-name/for/object
 *         (this uses basic authentication WHICH IS NOT VERY SECURE AT ALL)
 *  or     ftp://username:password@machine.address:port/path-name/for/file
 *  or     local/file/name, c:\local\file\name etc
 *         NOTE: an intial single letter followed by a ":" will be taken
 *         as a local file-name, since maybe the letter is a DOS-style
 *         drive letter. In (local) names any "/" or "\" characters will
 *         be flipped to the style expected by the host machine. To
 *         force local access the protocol "local:" can be specified
 *         explicitly if you really want.
 *  User or password information as part of the URL takes precedence over
 *  any passed done into open_auth_url.
 *
 *  It will usually not be necessary to specify an explicit port for
 *  a host machine: the usual service-related default will apply. If the
 *  protocol is not used but the host's name starts with "www." or
 *  "wwwcgi." then http will be used, otherwise ftp.
 *
 *  If in an ftp link no explicit username is provided then "anonymous"
 *  is used. In this case if no password is given then an attempt may be
 *  made to identify the logged-on user and the current host, and a password
 *  of the form user@host is synthesised. Failing this one is created
 *  from the values of the shell variables "user" and "host". If these
 *  are not set then something fairly random is done.
 *  If the user name is given as "?" then the system prompts for both
 *  a user name and a password.
 *  If the password is given as "?" then the user will be prompted
 *  to give one. If this code is called as a subroutine from some other
 *  piece of code then a password entered this way will be re-used for
 *  the second and subsequent calls. Note that the usage "?:secret@host"
 *  will spot the "?" in the user name position and ignore the specified
 *  password and prompt for one.
 *  Thus a generic FTP URL can be like "ftp://?@host/path"
 *
 *  Note: a saved password should only really be re-used if the
 *        host machine is unchanged. Also I probably need a way to
 *        save or pass in passwords using shell variables rather than
 *        a static variable, so that people who use wegbet repeatedly
 *        from a shell or perl script are reasonavly well looked after.
 *
 *  To use a proxy server do something like
 *        set http_proxy=http://local.firewall.machine:8080
 *  with a similar setting for ftp_proxy.
 *
 *  Redistribution etc.
 *     NO guarantees are provided about the fitness of this code for
 *     any purpose whatsoever. Users accept full responsibility for
 *     checking that it will suit their purposes and not damage their
 *     systems.
 *     I would be interested in seeing and corrections, extensions or
 *     other improvements that anybody can suggest for this code,
 *     provided that any code I receive can be freely incorporated
 *     herein without confusing the rights of people (including myself)
 *     to exploit the code. I can not even guarantee to respond to
 *     bug reports, far less to fix things. But after all you have the
 *     source code so you can fix it for yourself if need-be. All the
 *     same, tell me what goes wrong and I will think about it.
 *
 *                       Arthur Norman (acn1@cam.ac.uk) 1996-2004
 */





#define WSAGetLastError()   errno
#define closesocket(a)      close(a)
#define SOCKET              int
#define SOCKET_ERROR        (-1)

#ifndef INADDR_NONE
#  define INADDR_NONE       0xffffffff
#endif


/*
 * In this file I can give the detailed shape of a socket_file structure.
 */

struct socket_file
{
    int type;                  /* socket_http etc. */
    SOCKET data_socket, control_socket;
    int data_start, data_end;
    int control_start, control_end;
    struct socket_x
    {   char b[SOCKET_BUFFER_SIZE];    /* partitioned in FTP case */
        FILE *f;                       /* Used just in LOCAL case */
    } x;
};

#define standard_ftp_port      21
#define standard_scp_port      22      /* but chain down to an external scp */
#define standard_http_port     80
#define standard_local_port    (-1)

/*
 * At least while development remains active I will leave in an option
 * that can be selected at compile-time: TRACE. With "-DTRACE=1" on the
 * command line for the compiler or "#define TRACE 1" temporarily added
 * to the start of this file a load of extra messages are generated so
 * that one can see how the address decoding etc. progresses. When this
 * is enabled all output that would normally go to stderr is redirected to
 * stdout. The reasoning behind that is that stdout is much easier to
 * redirect or pipe than stderr (across shells and operating systems).
 * The stuff printed under the control of TRACE is not intended for the
 * casual user and will change between versions. Nobody should rely on it!
 */

#ifdef TRACE
#  undef stderr
#  define stderr stdout
#endif

/*
 * set_forced_proxy(NULL)        [default state] look in proxy shell variable
 * set_forced_proxy("")          do not proxy
 * set_forced_proxy("http://url:port") use that
 */

static char *forced_proxy = NULL;

char *set_forced_proxy(char *p)
{
    char *r = forced_proxy;
    forced_proxy = p;
    return r;
}

/*
 * If a socket function fails it leaves an error code that
 * WSAGetLastError() can retrieve. This function converts the numeric
 * codes to some printable text. Still cryptic, but maybe better than
 * the raw numbers! A nice (?) thing is that Microsoft and the BSD sockets
 * code use the same error numbers but provide different macros to
 * name them. Hence the following mess. For almost all people even the
 * decoded message generated here will not be much use - they will just know
 * that something failed. But those concerned with developing the code
 * may be helped by textual reports.
 */

static char error_name[32];

static char *WSAErrName(int i)
{
    switch (i)
    {
default:                 sprintf(error_name, "Socket error %d", i);
                         return error_name;

/*
 * I display both the Unix and Windows form of the error code.
 */
case EINTR:              return "WSAEINTR/EINTR";
case EBADF:              return "WSAEBADF/EBADF";
case EACCES:             return "WSAEACCES/EACCES";
case EFAULT:             return "WSAEFAULT/EFAULT";
case EINVAL:             return "WSAEINVAL/EINVAL";
case EMFILE:             return "WSAEMFILE/EMFILE";
case EWOULDBLOCK:        return "WSAEWOULDBLOCK/EWOULDBLOCK";
case EINPROGRESS:        return "WSAEINPROGRESS/EINPROGRESS";
case EALREADY:           return "WSAEALREADY/EALREADY";
case ENOTSOCK:           return "WSAENOTSOCK/ENOTSOCK";
case EDESTADDRREQ:       return "WSAEDESTADDRREQ/EDESTADDRREQ";
case EMSGSIZE:           return "WSAEMSGSIZE/EMSGSIZE";
case EPROTOTYPE:         return "WSAEPROTOTYPE/EPROTOTYPE";
case ENOPROTOOPT:        return "WSAENOPROTOOPT/ENOPROTOOPT";
case EPROTONOSUPPORT:    return "WSAEPROTONOSUPPORT/EPROTONOSUPPORT";
case ESOCKTNOSUPPORT:    return "WSAESOCKTNOSUPPORT/ESOCKTNOSUPPORT";
case EOPNOTSUPP:         return "WSAEOPNOTSUPP/EOPNOTSUPP";
case EPFNOSUPPORT:       return "WSAEPFNOSUPPORT/EPFNOSUPPORT";
case EAFNOSUPPORT:       return "WSAEAFNOSUPPORT/EAFNOSUPPORT";
case EADDRINUSE:         return "WSAEADDRINUSE/EADDRINUSE";
case EADDRNOTAVAIL:      return "WSAEADDRNOTAVAIL/EADDRNOTAVAIL";
case ENETDOWN:           return "WSAENETDOWN/ENETDOWN";
case ENETUNREACH:        return "WSAENETUNREACH/ENETUNREACH";
case ENETRESET:          return "WSAENETRESET/ENETRESET";
case ECONNABORTED:       return "WSAECONNABORTED/ECONNABORTED";
case ECONNRESET:         return "WSAECONNRESET/ECONNRESET";
case ENOBUFS:            return "WSAENOBUFS/ENOBUFS";
case EISCONN:            return "WSAEISCONN/EISCONN";
case ENOTCONN:           return "WSAENOTCONN/ENOTCONN";
case ESHUTDOWN:          return "WSAESHUTDOWN/ESHUTDOWN";
case ETOOMANYREFS:       return "WSAETOOMANYREFS/ETOOMANYREFS";
case ETIMEDOUT:          return "WSAETIMEDOUT/ETIMEDOUT";
case ECONNREFUSED:       return "WSAECONNREFUSED/ECONNREFUSED";
case ELOOP:              return "WSAELOOP/ELOOP";
case ENAMETOOLONG:       return "WSAENAMETOOLONG/ENAMETOOLONG";
case EHOSTDOWN:          return "WSAEHOSTDOWN/EHOSTDOWN";
case EHOSTUNREACH:       return "WSAEHOSTUNREACH/EHOSTUNREACH";
case HOST_NOT_FOUND:     return "WSAHOST_NOT_FOUND/HOST_NOT_FOUND";
case TRY_AGAIN:          return "WSATRY_AGAIN/TRY_AGAIN";
case NO_RECOVERY:        return "WSANO_RECOVERY/NO_RECOVERY";

    }
}

/*
 * When I retrieve a file there are three possible sorts of source
 *     (a) a file on the local machine
 *     (b) something via an HTTP link, using just one socket
 * and (c) something via an FTP link, using one socket for control
 *         and one for data.
 * I define a union structure capable of capturing the entire state
 * of any of these, including the buffers that are used. I arrange
 * that the remote access cases both take (about) the same amount of
 * space.
 */

#define socket_inactive 0        /* Not in use. Access is an error   */
#define socket_local    1        /* Uses a FILE to access local data */
#define socket_http     2        /* Linked via HTTP                  */
#define socket_ftp      3        /* Linked via FTP                   */
#define socket_ftp1     4        /* FTP with data transfer active    */
#define socket_scp      5        /* had used scp to fetch the data   */
#define socket_binary   256      /* OR into the type field           */

#define FTP_CONTROL_SIZE   1024

static int sockets_ready = 0;

static char *sshdir;

int ssh_ensure_sockets_ready(char *ssh)
{
    if (!sockets_ready)
    {
#ifdef WIN32
/*
 * Under Windows the socket stuff is not automatically active, so some
 * system calls have to be made at the start of a run. I demand a
 * Winsock 1.1, and fail if that is not available.
 */
        WSADATA wsa_data;
        int i = WSAStartup(MAKEWORD(1,1), &wsa_data);
        if (i) return i;   /* Failed to start winsock for some reason */;
        if (LOBYTE(wsa_data.wVersion) != 1 ||
            HIBYTE(wsa_data.wVersion) != 1)
        {   WSACleanup();
            return 1;      /* Version 1.1 of winsock needed */
        }
#endif
        sshdir = ssh;
        sockets_ready = 1;
    }
    return 0;
}

int ensure_sockets_ready()
{
    return ssh_ensure_sockets_ready(NULL);
}

/*
 * The client interface gets characters one at a time from the remote
 * source. If the source is to be treated as "ASCII" I will discard
 * carriage returns, treat line-feed as end-of-line and (for the sake
 * of truly old DOS files) interpret control-Z as end of file. The
 * function char_from_data() is valid for ANY sort of link.
 *
 * Note about an oddity - my socket buffer is an array of type "char" and
 * on machines where this is a signed type and where EOF has the value -1
 * a character 0xff in the data stream might tend to masquerade as an
 * end of file. To prevent that I mask back values returned from here
 * so that they are in the range 0x00 to 0xff.
 */

int char_from_data(socket_file *p)
{
    int ch, datasize = SOCKET_BUFFER_SIZE-FTP_CONTROL_SIZE;
    for (;;)
    {   switch (p->type & 0xff)
        {
    default:
            return EOF;
    case socket_local:
    case socket_scp:
            ch = getc(p->x.f);
            if (ch == EOF) return ch;
            break;
    case socket_http:
            datasize = SOCKET_BUFFER_SIZE;
            /* Drop through */
    case socket_ftp1:
            if (p->data_start != p->data_end)
                ch = p->x.b[p->data_start++];
            else
            {   int nch = recv(p->data_socket, p->x.b, datasize, 0);
                if (nch == 0) return EOF;
                if (nch == SOCKET_ERROR)
                {   printf("socket read error (%s)\n",
                           WSAErrName(WSAGetLastError()));
                    return EOF;
                }
                p->data_start = 1;
                p->data_end = nch;
                ch = p->x.b[0];
            }
        }
        if (p->type & socket_binary) return ch & 0xff;
        else if (ch == (0x1f & 'M')) continue;
        else if (ch == (0x1f & 'J')) return '\n';
        else if (ch == (0x1f & 'Z')) return EOF;
        else return ch & 0xff;
    }
}

/*
 * char_from_control() is ONLY valid for an FTP link, in which case it
 * grabs characters in ASCII mode from the control port. I do NOT check for
 * invalid calls, since it should only be used within the FTP protocol
 * management code, and never by users.
 */

int char_from_control(socket_file *p)
{
    int ch;
    for (;;)
    {   if (p->control_start != p->control_end)
            ch = p->x.b[p->control_start++];
        else
        {   int nch = recv(p->control_socket,
                           p->x.b+SOCKET_BUFFER_SIZE-FTP_CONTROL_SIZE,
                           FTP_CONTROL_SIZE,
                           0);
            if (nch == 0) return EOF;
            if (nch == SOCKET_ERROR)
            {   printf("FTP control socket read error (%s)\n",
                       WSAErrName(WSAGetLastError()));
                return EOF;
            }
            p->control_start = SOCKET_BUFFER_SIZE-FTP_CONTROL_SIZE+1;
            p->control_end = SOCKET_BUFFER_SIZE-FTP_CONTROL_SIZE+nch;
            ch = p->x.b[SOCKET_BUFFER_SIZE-FTP_CONTROL_SIZE];
        }
        if (ch == (0x1f & 'M')) continue;
        else if (ch == (0x1f & 'J')) return '\n';
        else if (ch == (0x1f & 'Z')) return EOF;
        else return ch;
    }
}

/*
 * Sending to a socket does not use my abstract-ish socket record
 * but goes straight down to the system-level functions and handles.
 */

int send_to_socket(SOCKET s, char *buffer, int nhostaddr, char *hostaddr)
{
#ifdef TRACE
/*
 * It will usually be the case that the packet being sent has carriage return
 * and line-feed characters on the end. I strip those from the trace
 * output in the name of a little conciseness.
 */
    int n = strlen(buffer)-1;
    while (buffer[n]== 0x0a || buffer[n] == 0x0d) n--;
    fprintf(stderr, "Request: <%.*s>\n", n+1, buffer);
#endif
    if (send(s, buffer, strlen(buffer), 0) == SOCKET_ERROR)
    {   fprintf(stderr, "Send error (%s) to host %.*s\n",
                        WSAErrName(WSAGetLastError()),
                        nhostaddr, hostaddr);
        return 1;
    }
    return 0;
}

/*
 * When a transaction is over I close the associated socket. In due
 * course I may change this so that after an FTP fetch the link is left
 * connected until it has been checked whether the next file to be fetched
 * is at the same site and to be accessed using the same account.
 */

static int ftp_reply(socket_file *p);

void close_socket(socket_file *p)
{
    if (p == NULL) return;
    switch (p->type & 0xff)
    {
default:break;
case socket_local:
        fclose(p->x.f);
        break;
case socket_scp:
        fclose(p->x.f);
        remove(p->x.b);
        break;
case socket_ftp1:
/*
 * If I close the socket when it was labelled as in active use for
 * data transfer I will try to get the "200" reply that signals the
 * proper end of the transfer, and I will then send a "QUIT".
 */
        if (p->data_socket)
        {   int i = ftp_reply(p);
            if ((i/100) == 1) i = ftp_reply(p);
            if ((i/100) == 2) send_to_socket(p->control_socket, "quit", 0, "");
            else fprintf(stderr, "FTP fetch seems to have failed\n");
/*
 * I will not bother to check for a return-code from the QUIT command,
 * but will instead promptly close the socket that I had been talking on.
 */
        }
        /* Drop through */
case socket_ftp:
        if (p->control_socket) closesocket(p->control_socket);
        /* Drop through */
case socket_http:
        if (p->data_socket) closesocket(p->data_socket);
        break;
    }
    free((void *)p);
}

/*
 * The symbol defined here probably counts as a bit delicate, in that
 * perhaps some clown will have URLs that are amazingly long. Just at present
 * I will not worry about that, even if this code can thereby be crashed
 * (but I hope it can NOT be crashed...).
 */

#define LONGEST_LEGAL_FILENAME 256

/*
 * The two arrays here are used for general storage and re-packing of
 * bits of addresses, paths and file-names. Thus calling them "filename"
 * is a little simplistic.
 */

char filename0[LONGEST_LEGAL_FILENAME],
     filename1[LONGEST_LEGAL_FILENAME];

char httpauth[64], httpauth64[64];

/*
 * Here I am reading the initial line of response data from
 * a GET request and if my server is only HPPT/0.9 it may have started
 * right away with the contents of the document, which may be nothing
 * like the format I require. In this case I must return in some
 * manner that does not cause too abrupt an exit.
 */

static void fetch_status(char *buffer, socket_file *p)
{
    int i;
    for (i=0; i<LONGEST_LEGAL_FILENAME; i++)
    {   int ch = char_from_data(p);
        if (ch == EOF) break;
        if (ch == 0x0a)
        {   buffer[i] = 0;
            return;      /* Successful return with (CR)LF found */
        }
        buffer[i] = ch;
/*
 * In case I was using HTTP/0.9 I will need to be able to re-read a
 * line of stuff that does not seem to be a proper HTTP/1.x status line.
 * To do this I want to reset my own buffer pointers back - but note that
 * this could cause trouble if some silly server returned the status line
 * split across two packets. The bad case seems very unlikely to arise so
 * I will ignore it (for now). But if I try to read beyond the packet size
 * I will chuck the data away and suppose I do have HTTP/0.9
 */
        if (p->data_start == p->data_end) break;
    }
    buffer[0] = 0;
    return;
}

/*
 * This reads one of the response lines at the start of an HTTP reply.
 * It returns non-zero if something went wrong, and in that case it also
 * closes the socket. Two things can go wrong: (a) the socket can return
 * and EOF and (b) a response line can be ridiculously long.
 */

static int fetch_response(char *buffer, socket_file *p)
{
    int i;
    for (i=0; i<LONGEST_LEGAL_FILENAME; i++)
    {   int ch = char_from_data(p);
        if (ch == EOF) break;
        if (ch == 0x0a)
        {   buffer[i] = 0;
/*
 * The keys returned at the start of a response line are supposed to be
 * case insensitive, so I fold things to lower case right here.
 */
            for (i=0; buffer[i]!=0 && buffer[i]!=' '; i++)
                buffer[i] = tolower(buffer[i]);
            return 0;
        }
        buffer[i] = ch;
    }
    fprintf(stderr, "Unexpected response from server\n");
    close_socket(p);
    return 1;
}

/*
 * FTP transactions generate responses of the following two forms:
 *     nnn text CRLF
 * and
 *     nnn-text CRLF
 *     ...
 *     nnn text (same numeric value nnn)
 * so this code reads one of these and returns the number that is read.
 * It returns -1 if the text seems to be corrupted.
 */

/*
 * read3_control reads 3 digits and the next character, and returns
 * a packed value:
 *     ppqqrrrr
 * pp = number of characters placed in the buffer "filename1"
 * qq = 0 if the character at the end was " ", 1 for "-" and 0xff otherwise
 * rrrr is the value of the 3-digit number.
 * If a proper number is not found the return value will be ppff0000.
 * If an EOF is found anywhere the value 0 is returned.
 */

static int read3_control(socket_file *p, int i)
{
    int n1, ch = char_from_control(p);
    if (ch == EOF) return 0;
    if (i < LONGEST_LEGAL_FILENAME) filename1[i++] = ch;
    if (!isdigit(ch)) return 0x01ff0000;
    n1 = ch - '0';
    ch = char_from_control(p);
    if (ch == EOF) return 0;
    if (i < LONGEST_LEGAL_FILENAME) filename1[i++] = ch;
    if (!isdigit(ch)) return 0x02ff0000;
    n1 = 10*n1 + ch - '0';
    ch = char_from_control(p);
    if (ch == EOF) return 0;
    if (i < LONGEST_LEGAL_FILENAME) filename1[i++] = ch;
    if (!isdigit(ch)) return 0x03ff0000;
    n1 = 10*n1 + ch - '0';
    ch = char_from_control(p);
    if (ch == EOF) return 0;
    if (i < LONGEST_LEGAL_FILENAME) filename1[i++] = ch;
    if (ch == ' ') return 0x04000000 | n1;
    else if (ch == '-') return 0x04010000 | n1;
    else return 0x04ff0000;
}

static int ftp_reply(socket_file *p)
{
    int ch, n1, n2, i;
/* First I read a 3-digit number and the following character */
    if ((n1 = read3_control(p, 0)) != 0)
    {   i = n1 >> 24;
        if ((n1 & 0x00ff0000) == 0) n1 &= 0x0000ffff;
        else if ((n1 & 0x00ff0000) == 0x00010000)  /* "-" case found */
        {   n1 = n1 & 0x0000ffff;
            for (;;)
            {   for (;;)                      /* skip to end of line */
                {   ch = char_from_control(p);
                    if (i < LONGEST_LEGAL_FILENAME) filename1[i++] = ch;
                    if (ch == EOF)
                    {   n1 = -1;
                        break;
                    }
                    if (ch == 0x0a)
                    {   filename1[i-1] = '\n';
                        break;
                    }
                }
                if (n1 < 0) break;
                n2 = read3_control(p, i);     /* Next line starts "nnn "? */
                if (n2 == 0)
                {   n1 = -1;
                    break;
                }
                i += n2 >> 24;
/*
 * If the second number matches the first & ends in " " this is the end
 * of the response.
 */
                if (n2 == (0x04000000 | n1)) break;
            }
        }
        else n1 = -1;
/* Finally I have to skip over the text following the "nnn " */
        if (n1 >= 0)
        {   for (;;)
            {   ch = char_from_control(p);
                if (i < LONGEST_LEGAL_FILENAME) filename1[i++] = ch;
                if (ch == EOF) break;
                if (ch == 0x0a)
                {   filename1[i-1] = 0;
#ifdef TRACE
                    fprintf(stderr, "FTP response: %s\n", filename1); fflush(stderr);
#endif
                    return n1;
                }
            }
        }
    }
    fprintf(stderr, "FTP protocol failed\n");
    return -1;
}

static socket_file *create_socket()
{
    socket_file *new_sock = (socket_file *)malloc(sizeof(socket_file));
    if (new_sock == NULL) return NULL;
    new_sock->type = socket_inactive;
    new_sock->x.f = NULL;
    new_sock->data_socket = 0;
    new_sock->control_socket = 0;
    return new_sock;
}

void encode64(char *a, char *b)
{
    char *code = 
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+-";
    for (;;)
    {   int c1 = *a++, c2, c3, w;
        if (c1 == 0) break;
        if ((c2 = *a++) == 0)
        {   *b++ = code[(c1 >> 2) & 0x3f];
            *b++ = code[(c1 << 4) & 0x3f];
            *b++ = '=';
            *b++ = '=';
            break;
        }
        if ((c3 = *a++) == 0)
        {   w = (c1 << 16) | (c2 << 8);
            *b++ = code[(w >> 18) & 0x3f];
            *b++ = code[(w >> 12) & 0x3f];
            *b++ = code[(w >> 6) & 0x3f];
            *b++ = '=';
            break;
        }
        w = (c1 << 16) | (c2 << 8) | c3;
        *b++ = code[(w >> 18) & 0x3f];
        *b++ = code[(w >> 12) & 0x3f];
        *b++ = code[(w >> 6) & 0x3f];
        *b++ = code[w & 0x3f];
    }
    *b = 0;
}

static int suser_valid=0, spass_valid = 0;
static char suser[64], spass[64]; /* For constructed FTP identification */

void set_suser(char *s)
{
    strncpy(suser, s, 63);
    suser[63] = 0;
    suser_valid = 1;
}


socket_file *open_url(char *w, int binary_mode)
{
    return open_auth_url(w, binary_mode, NULL, NULL);
}

socket_file *open_auth_url(char *w, int binary_mode, char *xuser, char *xpw)
{
    socket_file *current_socket = NULL;
    char *p;
    char *user, *pass, *proto, *hostaddr, *port, *path;
    int  nuser, npass, nproto, nhostaddr, nport, npath;
    char *proxy;
    char *proxyhostaddr, *proxyport;
    int  nproxyhostaddr, nproxyport;
    int default_port; /* Used to tell me what protocol is in use too */
    int len;
    int retcode;
    struct hostent *host;
    long int hostnum;
    SOCKET s;
    int i;
    int retry_count = 0;
/*
 * The start_again label here is used when an HTTP request gives me
 * a reply that indicates that the object to be fetched has been moved
 * to some other location. I follow such links with retry_count being
 * used to set an upper bound on the work done. I think that it would be
 * less tidy either to wrap a "for (retry_count=0;..)" round the whole code
 * or to make a recursive call (where retry_count would then need to be an
 * additional parameter to open_url). So you structured programming
 * thought police can go and bother somebody else, please.
 */
start_again:
    current_socket = create_socket();
    if (current_socket == NULL) 
    {   fprintf(stderr, "failed to create a socket\n");
        return NULL; /* Failed */
    }
    len = strlen(w);
    if (len >= sizeof(filename0)) len = sizeof(filename0)-1;
    memcpy(filename0, w, len);
    filename0[len] = 0;
/*
 * I want to parse the URL. I leave the result as a collection of
 * pointers (usually to the start of text within the URL itself, but
 * sometimes elsewhere, together with lengths of the substrings as found.
 */
    user = pass = proto = hostaddr = port = path = " ";
    nuser = npass = nproto = nhostaddr = nport = npath = 0;
    p = filename0;
/*
 * If the start of the URL is of the form "xyz:" with xyz alphanumeric
 * then that is a protocol name, and I will force it into lower case.
 * However the special case "<one-letter>:" (eg "c:") will NOT be
 * viewed as a protocol specifier but will force "local" access.
 */
    for (i=0; i<len; i++)
        if (!isalnum(p[i])) break;
    if (p[i] == ':')
    {   if (i == 1 && isalpha(p[0]))
        {   proto = "local";
            nproto = 5;
        }
        else
        {   proto = p;
            nproto = i;   /* Could still be zero! */
            p += i+1;
            len -= i+1;
            for (i=0; i<nproto; i++) proto[i] = tolower(proto[i]);
        }
    }
/*
 * If a protocol was not explicitly given I will try to deduce one from the
 * start of the name of the hostaddr. Failing that I will just use a default.
 */
    if (nproto == 0)
    {   if (strncmp(hostaddr, "www.", 4) == 0 ||
            strncmp(hostaddr, "wwwcgi.", 7) == 0)
        {   proto = "http";
            nproto = 4;
            default_port = standard_http_port;
            proxy = getenv("http_proxy");
        }
        else
        {   proto = "ftp";
            nproto = 3;
            default_port = standard_ftp_port;
            proxy = getenv("ftp_proxy");
        }
    }
    else if (nproto == 3 && memcmp(proto, "ftp", 3) == 0)
        default_port = standard_ftp_port,
        proxy = getenv("ftp_proxy");
    else if ((nproto == 3 && memcmp(proto, "scp", 3) == 0) ||
             (nproto == 3 && memcmp(proto, "ssh", 3) == 0))
        default_port = standard_scp_port,
        proxy = NULL;
    else if (nproto == 4 && memcmp(proto, "http", 4) == 0)
        default_port = standard_http_port,
        proxy = getenv("http_proxy");
    else if (nproto == 5 && memcmp(proto, "local", 5) == 0)
        default_port = standard_local_port,
        proxy = NULL;
    else
    {   if (current_socket != NULL) free ((void *)current_socket);
        current_socket = NULL;
        fprintf(stderr, "Unknown protocol\n");
        return NULL; /* Unknown protocol */
    }
/*
 * Allow programmer to override env-variable proxy specification
 */
    if (forced_proxy != NULL)
    {   if (*forced_proxy == 0) proxy = NULL;
        else proxy = forced_proxy;
    }

/*
 * After any protocol specification I may have a host name, introduced
 * by "//". Note that if there is either an explicit "local:" or a drive
 * letter at the start of the URL then I do not look for a host.
 */
    if (p[0] == '/' && p[1] == '/' && default_port!=standard_local_port)
    {   p += 2;
        len -= 2;
/*
 * If the URL (sans protocol) contains a "@" then I will take it to be
 * in the form
 *      user:password@hostaddr/...
 * and will split the user bit off. This will be particularly used in the
 * case of FTP requests. The password will be allowed to contain ":" and
 * "@" characters. Furthermore I will also allow the password to be
 * enclosed in quote marks ("), although since I scan for the "@" from
 * the right and for the ":" from the left these are not needed at all,
 * so if I notice them here all I have to do is to discard them!
 */
        for (i=len-1; i>=0; i--)
            if (p[i] == '@') break;
        if (i >= 0)
        {   user = p;
            p += i+1;
            len -= i+1;
            while (user[nuser] != ':' && user[nuser] != '@') nuser++;
            if (user[nuser] == ':')
            {   pass = user+nuser+1;
                npass = i - nuser - 1;
                if (pass[0] == '"' && pass[npass-1] == '"')
                    pass++, npass -= 2;
            }
        }
/*
 * Now what is left is a host, port number and path, written as
 *     hostaddr:port/... but note that the "/" should be treated as
 * part of the path-name.
 * Well in the case of FTP and SCP protocols I will not permit
 * and explicit port number to be specified but I will allow (and maybe
 * indeed prefer) ":" to separate the host address from the path. In this
 * case the issue of local vs. fully rooted paths becomes easier to
 * understand.
 */
        hostaddr = p;
        for (;;)
        {   switch (hostaddr[nhostaddr])
            {
        default:
                nhostaddr++;
                continue;
        case '/':
                p += nhostaddr;
                len -= nhostaddr;
                break;
        case 0: len = 0;
                break;
        case ':':        /* port number or ftp/scp end of host */
                if (default_port == standard_ftp_port ||
                    default_port == standard_scp_port)
                {   p += nhostaddr;
                    len -= nhostaddr;
                    break;
                }
        case '=':        /* alternative syntax for marking port number */
                port = hostaddr+nhostaddr+1;
                for (;;)
                {   switch (port[nport])
                    {
                default:
                        nport++;
                        continue;
                case '/':
                case ':':
                        p += nhostaddr + nport + 1;
                        len -= nhostaddr + nport + 1;
                        break;
                case 0: len = 0;
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        }
    }
    path = p;
    npath = len;
    if (npath == 0) path = "/", npath = 1;  /* Default path */
/*
 * If the user gave an explicit port number I will try to use it. If the
 * port was not numeric I ignore it and drop down to trying to use
 * a default port based on the selected protocol.
 */
    if (nport != 0)
    {   int nport_temp;
        memcpy(filename1, port, nport);
        filename1[nport] = 0;
        if (sscanf(filename1, "%d", &nport_temp) == 1) nport = nport_temp;
        else nport = 0;
    }
    if (nport == 0) nport = default_port;
/*
 * If no host-name was given then the object concerned is on the
 * local machine. This is a funny case maybe, but I will just chain
 * through and open it as an ordinary file (without regard to
 * protocol etc). The whole of the data in the file will be returned.
 */
    if (nhostaddr == 0)
    {   FILE *file;
/*
 * Here the path may contain either "/" or "\" characters and I should
 * re-map it suitably for my host.
 */
        for (i=0; i<npath; i++)
           if (path[i] == '\\') path[i] = '/';
        file = fopen(path, "rb");
        if (file == NULL)
        {   if (current_socket != NULL) free((void *)current_socket);
            current_socket = NULL;
            fprintf(stderr, "File %s unavailable\n", path);
            return NULL;
        }
        current_socket->type = socket_local;
        if (binary_mode) current_socket->type |= socket_binary;
        current_socket->x.f = file;
        return current_socket;
    }
    if (nuser == 0 && xuser != NULL)
    {   user = xuser;
        nuser = strlen(user);
    }
    if (npass == 0 && xpw != NULL)
    {   pass = xpw;
        npass = strlen(pass);
    }
    if (nuser == 1 && user[0] == '?')
    {   if (suser_valid)
        {   user = suser;
            nuser = strlen(user);
        }
        else
        {   printf("User for %.*s: ", nhostaddr, hostaddr);
            fflush(stdout);
            for (i=0; i<sizeof(suser)-1; i++)
            {   int ch;
                ch = getchar();
                if (ch == '\n' || ch == '\r' || ch == EOF) break;
                suser[i] = ch;
            }
            suser[i] = 0;
            user = suser;
            nuser = i;
            suser_valid = 1;
        }
        if (spass_valid)
        {   pass = spass;
            npass = strlen(pass);
        }
        else if (default_port == standard_ftp_port)
/*
 * At present if I use scp I do not know how to feed it a password as
 * I go. This is basically because I "exec()" a call to "scp" and there
 * is no obvious command-line way to pass down authentication. So it
 * would be silly to ask for it! One view about all of this is that scp
 * as a matter of POLICY does not want you to give passwords via the command
 * line etc and that authentication via trusted keys is better.
 */
        {
/*
 * This is the Posix way of switching off echo.
 */
            struct termios old_term, new_term;
            tcgetattr(fileno(stdin), &old_term);
            new_term = old_term;
            new_term.c_lflag &= ~(ECHO|ECHOE|ECHOK|ECHONL);
            tcsetattr(fileno(stdin), TCSANOW, &new_term);
            printf("Password: ");
            fflush(stdout);
            for (i=0; i<sizeof(spass)-1; i++)
            {   int ch;
                ch = getchar();
                if (ch == '\n' || ch == '\r' || ch == EOF) break;
                spass[i] = ch;
            }
            spass[i] = 0;
            pass = spass;
            npass = i;
            spass_valid = 1;
            tcsetattr(fileno(stdin), TCSANOW, &old_term);
            printf("\n");    /* Since the user's newline was not echoed */
        }
    }
/*
 * If the password is given as just "?" then I will try to prompt the user to
 * provide one interactively. My first version may not manage to switch off
 * terminal echo, but that can be a later update. Anybody who has a single "?"
 * as their true password will be out of luck here, but then they do not
 * deserve much luck!!!
 */
    if (npass == 1 && pass[0] == '?')
    {   if (spass_valid)
        {   pass = spass;
            npass = strlen(pass);
        }
        else
        {
/*
 * This is the Posix way of switching off echo.
 */
            struct termios old_term, new_term;
            tcgetattr(fileno(stdin), &old_term);
            new_term = old_term;
            new_term.c_lflag &= ~(ECHO|ECHOE|ECHOK|ECHONL);
            tcsetattr(fileno(stdin), TCSANOW, &new_term);
            printf("Password for %.*s@%.*s: ",
                   nuser, user, nhostaddr, hostaddr);
            fflush(stdout);
            for (i=0; i<sizeof(spass)-1; i++)
            {   int ch;
                ch = getchar();
                if (ch == '\n' || ch == '\r' || ch == EOF) break;
                spass[i] = ch;
            }
            spass[i] = 0;
            pass = spass;
            npass = i;
            spass_valid = 1;
            tcsetattr(fileno(stdin), TCSANOW, &old_term);
            printf("\n");    /* Since the user's newline was not echoed */
        }
    }
    if (default_port == standard_ftp_port ||
        default_port == standard_scp_port)
    {   if (nuser == 0)
        {   user = "anonymous";
            nuser = strlen(user);
            if (npass == 0)
            {
                char *localuser = getenv("user");
                char *localhost = getenv("host");
                if (localuser==NULL) localuser = "ftpuser";
                if (localhost==NULL) localhost = "unknown.machine";
                pass = spass;
                sprintf(pass, "%s@%s", localuser, localhost);
                npass = strlen(pass);
            }
        }
    }
    nproxyhostaddr = nproxyport = 0;
/*
 * Now if the user has indicated that a proxy server should be used I must
 * decode the gunk involved, using somewhat similar logic to the used for the
 * main URL. But this time it is really a lot simpler since I will (at
 * present) ignore any protocol specification in the proxy name and just
 * look for a server identification and optional port.
 */
    if (proxy != NULL)
    {   for (i=0; i<strlen(proxy); i++) if (!isalnum(proxy[i])) break;
        if (proxy[i] == ':') proxy += i+1; /* Strip of protocol name */
/*
 * I will attempt a generous treatment of proxy specifications. The user can
 * either give or not give a prefix that indicates protocol, as in
 * for instance "http:". And then there can be up to two "/" characters.
 * What follows will be treated as a host name up as far as the next ":"
 * (if there is one).
 */
        if (proxy[0] == '/') proxy++;
        if (proxy[0] == '/') proxy++;
        proxyhostaddr = proxy;
        while (proxy[nproxyhostaddr] != 0 &&
               proxy[nproxyhostaddr] != ':') nproxyhostaddr++;
        if (proxy[nproxyhostaddr] == ':')
        {   proxyport = proxy+nproxyhostaddr+1;
            while (isdigit(proxyport[nproxyport])) nproxyport++;
        }
        else proxyport = "8080";
        if (nproxyport == 0) nproxyport = default_port;
        else
        {   proxyport[nproxyport] = 0;
            sscanf(proxyport, "%d", &nproxyport);
        }
    }
    else proxyport = proxyhostaddr = NULL;

#ifdef TRACE
/*
 * Dump out all the information decoded so far so that I can admire it.
 */
    if (nproto == 0)         proto = "";
    if (nuser == 0)          user = "";
    if (npass == 0)          pass = "";
    if (nhostaddr == 0)      hostaddr = "";
    if (npath == 0)          path = "";
    if (nproxyhostaddr == 0) proxyhostaddr = "";
    fprintf(stderr, "URL decoded\n"); fflush(stderr);
    fprintf(stderr, "protocol = [%.*s]\n", nproto, proto); fflush(stderr);
    fprintf(stderr, "user = [%.*s]\n", nuser, user); fflush(stderr);
    fprintf(stderr, "password = [%.*s]\n", npass, pass); fflush(stderr);
    fprintf(stderr, "hostaddr = [%.*s]:%d\n", nhostaddr, hostaddr, nport); fflush(stderr);
    fprintf(stderr, "path = [%.*s]\n", npath, path); fflush(stderr);
    fprintf(stderr, "proxy = [%.*s]:%d\n",
                    nproxyhostaddr, proxyhostaddr, nproxyport); fflush(stderr);
#endif
    if (default_port == standard_scp_port)
    {   FILE *file;
        char *tnam = "xport.scp"; /* tmpnam(NULL); */
        char fetch_command[256];
        int rc, ntries = 0;
        for (i=0; i<npath; i++)
           if (path[i] == '\\') path[i] = '/';
/*
 * As with FTP I ignore the initial character in the path, which
 * might be "/" or ":".
 */
/*
 * I might rather like to be able to impose a password on each call to
 * scp here... much as I do so for ftp. Of course I could implement
 * my own scp client.... Ugh! At present I can not see a way to do this.
 * However with ssh/scp if you set up a suitable entry in your
 * authorized_keys file you can avoid the need for re-quoting passwords
 * and maybe that is even better!
 */
        if (sshdir)
            sprintf(fetch_command, "%s%cscp -P %d -S %s%cssh %.*s@%.*s:%.*s %s",
                sshdir, DIRECTORY_CHAR, nport, sshdir, DIRECTORY_CHAR,
                nuser, user, nhostaddr, hostaddr, npath-1, path+1, tnam);
        else sprintf(fetch_command, "scp -P %d %.*s@%.*s:%.*s %s",
             nport, nuser, user, nhostaddr, hostaddr, npath-1, path+1, tnam);
        for (;;)
        {   if ((rc = system(fetch_command)) == 0) break; 
            if (ntries++ >= 2)
            {   if (current_socket != NULL) free((void *)current_socket);
                 current_socket = NULL;
                fprintf(stderr, "File %s unavailable\n", path);
                return NULL;
            }
            remove(tnam);
/*
 * If I fail I will wait 5 secs before re-trying.
 */
            sleep(5);
        }
/*
 * "What..." I hear you ask, "... is the meaning of this gratuitous call to
 * sleep?". Well I observe that fetching from a Windows site (that runs the
 * cygwin-built version of openssh as its sshd) uncomfortably often hangs up.
 * A suggestion I have seen (but not verified) is that this may be because of
 * how long Windows can take to release port 22. So putting a  delay in here
 * may help. At least it is an experiment I want to try.
 */
#ifdef OLD_CAUTION_RE_WINDOWS
        sleep(2); 
#endif
/*
 * This issue of "scp" and binary/text files is horrid it seems. At
 * present I only have ssh daemons on Unix-like machine where the files
 * are stored with one-byte end-of-line, and everything then works OK.
 * However I may need to think some more if I ever want to support
 * scp with data coming FROM a Windows machine. Which of course I would
 * like to! Especially since with "cygwin" it is now easy to set up ssh as
 * a service on a Windows box. What I will do is to discard any '\r' chars
 * in fetched text data.
 */
        file = fopen(tnam, "rb");
        if (file == NULL)
        {   if (current_socket != NULL) free((void *)current_socket);
            current_socket = NULL;
            fprintf(stderr, "File %s unavailable\n", path);
            return NULL;
        }
        current_socket->type = socket_scp;
        if (binary_mode) current_socket->type |= socket_binary;
        current_socket->x.f = file;
        strcpy(current_socket->x.b, tnam);
        return current_socket;
    }
    if (ensure_sockets_ready() != 0)
    {   if (current_socket != NULL) free((void *)current_socket);
        current_socket = NULL;
        fprintf(stderr, "Sockets not available\n");
        return NULL;
    }
/*
 * Now the machine I want to talk to will either be the real target, or
 * the proxy server that I just identified. In the case of a proxy server
 * it could be that I ought to perform some authentication activity
 * somewhere, but at present I do not understand that! Also there is
 * some possibility that a proxy for an FTP request should be sent in HTTP
 * mode (so that the proxy server converts it to FTP). I will think about
 * such things more later on if I can find a proxy server to try things
 * out on!
 */
    if (nproxyhostaddr != 0)
    {   memcpy(filename1, proxyhostaddr, nproxyhostaddr);
        filename1[nproxyhostaddr] = 0;
    }
    else
    {   memcpy(filename1, hostaddr, nhostaddr);
        filename1[nhostaddr] = 0;
    }
/* I accept either "." form or named host specifications */
    hostnum = inet_addr(filename1);
    if (hostnum == INADDR_NONE)
    {   host = gethostbyname(filename1);
        if (host != NULL)
            hostnum = ((struct in_addr *)host->h_addr)->s_addr;
    }
    if (hostnum == INADDR_NONE)
    {   fprintf(stderr, "Host not found (%s)\n", WSAErrName(WSAGetLastError()));
        if (current_socket != NULL) free((void *)current_socket);
        current_socket = NULL;
        fprintf(stderr, "Host not found\n");
        return NULL;
    }
    s = socket(PF_INET, SOCK_STREAM, 0);  /* Make a new socket */
    {   struct sockaddr_in sin;
        memset(&sin, 0, sizeof(sin));
        sin.sin_family = AF_INET;
        if (nproxyhostaddr != 0)
            sin.sin_port = htons((unsigned short)nproxyport);
        else sin.sin_port = htons((unsigned short)nport);
        sin.sin_addr.s_addr = hostnum;
/*
 * I leave this here as a comment since it is a major place where there could
 * be delay, and some people might like to be encouraged that something is
 * still happening.
 *      printf("Contacting %.*s...\n", nhostaddr, hostaddr);
 */
        if (connect(s, (struct sockaddr *)&sin, sizeof(sin)) == SOCKET_ERROR)
        {   fprintf(stderr, "Connection to %.*s could not be made: %s\n",
                            nhostaddr, hostaddr,
                            WSAErrName(WSAGetLastError()));
            closesocket(s);
            if (current_socket != NULL) free((void *)current_socket);
            current_socket = NULL;
            return NULL;
        }
    }
/*
 * Now I have connected to the remote host on the port that I was supposed
 * to. Next I need to run the conversation that deals with whatever
 * protocol was supposed to be used.
 */
    if (default_port == standard_http_port)
    {
        current_socket->type = socket_http;
        current_socket->data_socket = s;
        current_socket->data_start = current_socket->data_end = 0;
/*
 * If I am using a proxy server the request that I send has to include
 * the service type and the name (and port) for the true target system.
 * If I have a direct link I must just send the absolute path part of
 * the URL.
 */

	/*
	** Note: If you are trying to access a virtual host you need to
	** make sure that you are passing the whole URL, not just the
	** component excluding hostname and port.
	*/

        if (nproxyhostaddr != 0)
            sprintf(filename1,
                "GET http://%.*s:%d%.*s HTTP/1.0\x0d\x0a",
                nhostaddr, hostaddr, nport, npath, path);
#if !ARRIFIX
        else
            sprintf(filename1,
                "GET %.*s HTTP/1.0\x0d\x0a", npath, path);
#else
	else {
	    sprintf(filename1,
		    "GET %.*s HTTP/1.0\nHost: %.*s\nUser-Agent: xport\n",
		    npath, path, nhostaddr, hostaddr);
	}
#endif /* !ARRIFIX */

/*
 * HTTP/1.1 will *REQUIRE* a "host:" field to be sent with every
 * request, so I tried the effect of putting one in to an HTTP/1.0
 * transaction. The effect seemed to be that all conversations failed.
 * Oh well. I had thought that unrecognised headers would not matter
 * too much.
 */
        i = strlen(filename1);
        i += sprintf(&filename1[i], "Host: %.*s\x0d\x0a", nhostaddr, hostaddr);
        i += sprintf(&filename1[i], "User-agent: xport\x0d\x0a");

/*
 * Certainly if the Web server I am accessing is the one that comes as
 * standard with Windows NT I need to reassure it that I want the document
 * returned to me WHATEVER its media type is. If I do not add in the
 * line "Accept: *|*" the GET request will only allow me to fetch simple
 * text. (?)
 * Note that above I write "*|*" where I only really mean a "/" in the
 * middle but where C comment conventions intrude!
 */  
        i += sprintf(&filename1[i], "Accept: */*\x0d\x0a");
/*
 * If both a user-name and password had been provided then I will use them
 * as basic authentication.
 */
        if (nuser != 0 && npass != 0)
        {   sprintf(httpauth, "%.*s:%.*s", nuser, user, npass, pass);
#ifdef TRACE
            fprintf(stderr, "<%s>\n", httpauth);
#endif
            encode64(httpauth, httpauth64);
            i += sprintf(&filename1[i], "Authorization: basic %s\x0d\x0a",
                         httpauth64);
        }
        i += sprintf(&filename1[i], "\x0d\x0a");
        if (send_to_socket(s, filename1, nhostaddr, hostaddr))
        {   close_socket(current_socket);
            fprintf(stderr, "Failed to write to socket\n");
            return NULL;
        }
/*
 * The above transfer does not put much additional information along with the
 * GET request. Eventually I probably need to consider supporting the
 * extra information that would make up HTTP (weak) authentication, and
 * possibly other options.
 */
/*
 * I want to read the headers that were returned in ascii mode, or to put
 * it another way, I feel safer doing that. Well the HTTP/1.1 drafts
 * suggest that I should ignore CR and treat LF as the end of a line,
 * which is what my implementation of ascii mode does for me.
 */
        fetch_status(filename1, current_socket);
#ifdef TRACE
        fprintf(stderr, "Status: <%s>\n", filename1);
#endif
/*
 * I check if the first line returned is in the form "HTTP/n.n nnn " and if
 * it is not I assume that I have reached an HTTP/0.9 server and all the
 * text that comes back will be the body.
 */
        {   int major, minor;
/*
 * I will not worry much about just which version of HTTP the system reports
 * that it is using, provided it says something! I expect to see the return
 * code as a three digit number. I verify that it is in the range 0 to 999 but
 * do not check for (and thus reject) illegal responses such as 0000200.
 */
            if (sscanf(filename1,
                       "HTTP/%d.%d %d", &major, &minor, &retcode) != 3 ||
                retcode < 0 || retcode > 999)
            {   current_socket->data_start = 0;
                if (binary_mode) current_socket->type |= socket_binary;
                return current_socket;
            }
        }
/*
 * In this code I treat all unexpected responses as errors and I do not
 * attempt to continue. This is sometimes going to be overly pessimistic
 * and RFC1945 tells me that I should treat unidentified codes as the
 * n00 variant thereupon.
 */
#ifdef TRACE
        printf("return code = %d\n", retcode);
#endif
        switch (retcode)
        {
    default:retcode = 0;
            break;
    case 200:
            break;   /* A success code for GET requests */
    case 301:        /* Redirection request */
    case 302:
            for (;;)
            {   if (fetch_response(filename1, current_socket))
                {   current_socket = NULL;
                    fprintf(stderr, "Failed to fetch response\n");
                    return NULL;
                }
                if (filename1[0] == 0)
                {   fprintf(stderr,
                            "Document has moved, but I can not trace it\n");
                    retcode = 0;
                    break;
                }
#ifdef TRACE
                fprintf(stderr, "Redir: <%s>\n", filename1);
#endif
/*
 * At present I take a somewhat simplistic view of redirection, and just
 * look for the first alternative URL and start my entire unpicking
 * process afresh from there.
 */
                if (memcmp(filename1, "location: ", 10) == 0)
                {   for (i=10; filename1[i]==' '; i++);
                    w = &filename1[i];
                    while (filename1[i]!=' ' &&
                           filename1[i]!=0) i++;
                    filename1[i] = 0;
                    close_socket(current_socket);
                    current_socket = NULL;
                    if (++retry_count > 5)
                    {   fprintf(stderr,
                                "Apparent loop in redirection information\n");
                        return NULL;
                    }
#ifdef TRACE
                    fprintf(stderr, "Redirect to %s\n", w);
#endif
                    goto start_again;
                }
            }
            break;
    case 401:
            fprintf(stderr, "Authorisation required for this access\n");
            retcode = 0;
            break;
    case 404:
            fprintf(stderr, "Object not found\n");
            retcode = 0;
            break;
        }
        if (retcode == 0)
        {   close_socket(current_socket);
            fprintf(stderr, "Unable to continue\n");
            return NULL;
        }
        while (filename1[0] != 0)
        {   if (fetch_response(filename1, current_socket))
            {
                fprintf(stderr, "Failed to fetch response\n");
                return NULL;
            }
#ifdef TRACE
            fprintf(stderr, "Further information <%s>\n", filename1);
#endif
        }
        if (binary_mode) current_socket->type |= socket_binary;
        return current_socket;
    }
    else if (default_port == standard_ftp_port)
    {   current_socket->type = socket_ftp;
        current_socket->data_socket = 0;    /* Not yet present */
        current_socket->control_socket = s;
/*
 * This is a BIT of a fudge. I set the buffer pointers for the control
 * socket to 0. This does not point into the control part of the buffer
 * but since it represents no data things will get corrected as soon
 * as I try to read from the socket!
 */
        current_socket->control_start = current_socket->control_end = 0;
        if (binary_mode) current_socket->type |= socket_binary;
        i = ftp_reply(current_socket);
        if (i == 120) i = ftp_reply(current_socket);
        if (i != 220)
        {   fprintf(stderr, "FTP server not available\n");
            close_socket(current_socket);
            return NULL;
        }
        sprintf(filename1, "USER %.*s\x0d\x0a", nuser, user);
        if (send_to_socket(s, filename1, nhostaddr, hostaddr) ||
            (i = ftp_reply(current_socket)) == -1)
        {   close_socket(current_socket);
            fprintf(stderr, "Failed to write USER to socket\n");
            return NULL;
        }
        if ((i/100) == 3)
        {   sprintf(filename1, "PASS %.*s\x0d\x0a", npass, pass);
            if (send_to_socket(s, filename1, nhostaddr, hostaddr) ||
                (i = ftp_reply(current_socket)) == -1)
            {   close_socket(current_socket);
                fprintf(stderr, "Failed to write PASS to socket\n");
                return NULL;
            }
/*
 * It is not clear that either Unix or Windows systems have a clear
 * concept of "account", and so I do not handle that part of the logging
 * on process very cleverly.
 */
            if ((i/100) == 3)
            {   sprintf(filename1, "ACCT noaccount\x0d\x0a");
                if (send_to_socket(s, filename1, nhostaddr, hostaddr) ||
                    (i = ftp_reply(current_socket)) == -1)
                {   close_socket(current_socket);
                    fprintf(stderr, "Failed to write ACCT to socket\n");
                    return NULL;
                }
            }
        }
        if ((i/100) != 2)
        {   fprintf(stderr, "Failed to log in to FTP server\n");
            close_socket(current_socket);
            return NULL;
        }
#ifdef TRACE
        fprintf(stderr, "Logged on to FTP server\n"); fflush(stderr);
#endif
/*
 * Here I have logged in to the FTP server, so maybe I can attempt a
 * fetch operation.
 */
        if (send_to_socket(s, binary_mode ? "TYPE I\x0d\x0a" :
                                            "TYPE A\x0d\x0a",
                              nhostaddr, hostaddr))
        {   close_socket(current_socket);
            fprintf(stderr, "Failed to write TYPE to socket\n");
            return NULL;
        }
        i = ftp_reply(current_socket);
        if ((i/100) != 2)
        {   fprintf(stderr, "Failed to set FTP transfer mode\n");
            close_socket(current_socket);
            return NULL;
        }
#ifdef TRACE
        fprintf(stderr, "File transfer mode set up\n"); fflush(stderr);
#endif
/*
 * If I send a PASV command to the fileserver it will reply to me with
 * its host identification and port number, so that I can create a
 * new socket and connect to it to get the data link that I need. If I
 * did not do this then the server would try to connect to one of my ports
 * and I would have had to tell it which, and set the relevant port into
 * a "listening" state.
 *
 * It appears that at least SOME ftp servers do not support the PASV
 * request, and hence my code will not interact with them at all well.
 * For now I suggest hunting for a more general server...
 * Well actually it is more complicated than that! The issue of PASV or not
 * relates uncomfortably to firewalls etc and what I ought to do is to
 * implement both modes of fetch and (as necessary) try both and use
 * whichever I can.
 */
        if (send_to_socket(s, "PASV\x0d\x0a",
                              nhostaddr, hostaddr))
        {   close_socket(current_socket);
            fprintf(stderr, "Failed to write PASV to socket\n");
            return NULL;
        }
        i = ftp_reply(current_socket);
        if (i != 227)
        {   fprintf(stderr, 
                "Failed (%d) to set \"passive mode\" on FTP server\n", i);
            close_socket(current_socket);
            return NULL;
        }
/*
 * Parse the information returned by PASV to get the host:port information.
 */
        {   int x1, x2, x3, x4, p1, p2;
            SOCKET s1;
            long int ftphostnum;
            struct sockaddr_in sin1;
            for (i=0; filename1[i]!='(' && filename1[i]!=0; i++);
#ifdef TRACE
            fprintf(stderr, "%s\n", &filename1[i]);
#endif
            if (sscanf(&filename1[i], "(%d,%d,%d,%d,%d,%d)",
                       &x1, &x2, &x3, &x4, &p1, &p2) != 6)
            {   fprintf(stderr, "Failed to locate FTP server data port\n");
                close_socket(current_socket);
                return NULL;
            }
            p1 = 256*p1 + p2;
#ifdef TRACE
            fprintf(stderr, "File transfer will be host %d.%d.%d.%d port %d\n",
                             x1, x2, x3, x4, p1); fflush(stderr);
#endif
            sprintf(filename1, "%d.%d.%d.%d", x1, x2, x3, x4);
            ftphostnum = inet_addr(filename1);
            if (hostnum == INADDR_NONE)
            {   fprintf(stderr, "FTP data host not found (%s)\n",
                                WSAErrName(WSAGetLastError()));
                close_socket(current_socket);
                return NULL;
            }
            s1 = socket(PF_INET, SOCK_STREAM, 0);  /* Make a new socket */
            memset(&sin1, 0, sizeof(sin1));
            sin1.sin_family = AF_INET;
            sin1.sin_port = htons((unsigned short)p1);
            sin1.sin_addr.s_addr = ftphostnum;
            current_socket->data_socket = s1;
            current_socket->data_start = current_socket->data_end = 0;
            if (connect(s1, (struct sockaddr *)&sin1, sizeof(sin1)) ==
                SOCKET_ERROR)
            {   fprintf(stderr, "Connection to %s could not be made: %s\n",
                                filename1,
                                WSAErrName(WSAGetLastError()));
                close_socket(current_socket);
                return NULL;
            }
/*
 * For HTTP fetches (where there is no user information provided)
 * I tend to start the path with "/". For FTP this is less than
 * helpful. So write ftp://anonymous:who@aaa.yyy//pub/...
 * This also works cheerfully with the syntax I think I now prefer, ie
 *    ftp://user:ps@host:filename
 */
            npath--;
            path++;
            sprintf(filename1, "RETR %.*s\x0d\x0a", npath, path);
            if (send_to_socket(s, filename1, nhostaddr, hostaddr))
            {   close_socket(current_socket);
                fprintf(stderr, "Failed to write RETR to socket\n");
                return NULL;
            }
/*
 * After a RETR command I expect (ha ha) to get a "100" class preliminary
 * response that will indicate that the file I asked for is available.
 * There would be trouble if the first thing I saw was a "200" class
 * message telling me that all the data had arrived. At present my
 * reading of RFC959 leaves me suspecting that I really can not be
 * totally certain that I will get the "125" or "150", since I can not
 * find words that force a server to return those preliminary responses
 * at all. However my reading of the INTENT is that they should be present
 * to help code like this that would otherwise have to listen in a
 * simultaneous way to both of its sockets.
 */
            i = ftp_reply(current_socket);
            if ((i/100) != 1)
            {   close_socket(current_socket);
                fprintf(stderr, "Failed to get 100 response after RETR (%d)\n", i);
                return NULL;
            }
        }
        current_socket->type = (current_socket->type & socket_binary) |
                               socket_ftp1;
        return current_socket;
    }
    fprintf(stderr, "At present I do not support the %.*s protocol\n",
                    nproto, proto);
    closesocket(s);
    free((void *)current_socket);
    return NULL;
}

void finished_with_sockets()
{
#ifdef WIN32
    WSACleanup();
#endif
    sockets_ready = 0;
}




/*
 *   Start of the main body of the program
 */

#define VERSION_STRING "2.05: March 2009"

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/



/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

FILE *myout;

void fatal_error(char *fmt, ...)
{
    va_list a;
    char msg[100];
    va_start(a, fmt);
    vsprintf(msg, fmt, a);
    va_end(a);
    fprintf(myout, "\nFatal error: %s\n", msg);
    fflush(myout);
    exit(EXIT_FAILURE);
}

void *Xmalloc(size_t n)
{
    void *p = malloc(n);
    if (p == NULL) fatal_error("no store");
    return p;
}

char today[16];
char timeofday[16];

static void get_todays_date()
{
    time_t t0 = time(NULL);
    char *b = ctime(&t0);
/*
 * I format the date as "31-Mar-1992" and the time as "01:21:59"
 */
    sprintf(today, "%.2s-%.3s-%.4s", b+8, b+4, b+20);
    sprintf(timeofday, "%.8s", b+11);
}

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

static char auth_user[64], auth_password[64];

socket_file *xopen_url(char *name, int mode)
{
    if (auth_user[0] == 0) return open_url(name, mode);
    else return open_auth_url(name, mode, auth_user, auth_password);
}

typedef struct stringlist
{
    char *name;
    struct stringlist *next;
} stringlist;

typedef struct patternlist
{
    int flag;
    stringlist *p;
    struct patternlist *next;
} patternlist;

stringlist *include, *omit, *text, *binary,
           *encrypted, *mixedcase, *executable, *nonexecutable;
patternlist *includeomit, *textbinary, *textencrypted, *execnonexec;
int hostcase = 1;

int should_omit(char *name)
{
    patternlist *p, *plast = NULL;
/*
 * I force a point here, and files with names xport.chk, .inc and .tmp
 * (etc) are always omitted from all file-listings. This is because they are
 * used as part of the workings of this program, and they appear,
 * disappear and change in a way that it would not be useful to mention
 * in the usual way. "xport.key" is not included because it may contain
 * secret information! It is thus hidden even if nested within sub-directories
 * and even if you have a version xport.key.old (made by use of a version
 * of xport that pre-dated special treatment of this file).
 */
    if (wildmatch("xport.chk", name) ||
        wildmatch("xport.inc", name) ||
        wildmatch("xport.dif", name) ||
        wildmatch("xport.ssh", name) ||
        wildmatch("xport.tm1", name) ||
        wildmatch("xport.tm2", name) ||
        wildmatch("xport.tmp", name) ||
        wildmatch("xport.key", name) ||
        wildmatch(".svn",    name)   ||
        wildmatch("**/.svn", name)   ||     /* for subversion survival */
        wildmatch("**/xport.key", name) ||
        wildmatch("xport.key.old", name) ||
        wildmatch("**/xport.key.old", name)) return 1;
    if (wildmatch("xport.pat", name)) return 0; /* always include this! */
    for (p=includeomit; p!=NULL; p=p->next)
    {   stringlist *s;
        for (s=p->p; s!=NULL; s=s->next)
           if (wildmatch(s->name, name)) return (p->flag<0);
        plast = p;
    }
    if (wildmatch("**.old", name)) return 1;
    return 0;
/*  return (plast!=NULL && plast->flag>=0); */
}

int is_binary(char *name)
{
    patternlist *p;
    for (p=textbinary; p!=NULL; p=p->next)
    {   stringlist *s;
        for (s=p->p; s!=NULL; s=s->next)
           if (wildmatch(s->name, name)) return (p->flag<0);
    }
/*
 * I will have some default rules that I use here in case the user has not
 * specified anything...
 */
    if (wildmatch("**.exe", name) ||
        wildmatch("**.com", name) ||
        wildmatch("**.gz", name) ||
        wildmatch("**.zip", name) ||
        wildmatch("**.tar", name)) return 1;
    return 0;
}

int is_executable(char *name)
{
    patternlist *p;
    for (p=execnonexec; p!=NULL; p=p->next)
    {   stringlist *s;
        for (s=p->p; s!=NULL; s=s->next)
           if (wildmatch(s->name, name)) return (p->flag<0);
    }
    if (wildmatch("**.exe", name) ||
        wildmatch("**.com", name) ||
        wildmatch("**.bat", name) ||
/* A bunch of files used by autoconf etc are make executable by default... */
        wildmatch("configure", name) ||
        wildmatch("**/configure", name) ||
        wildmatch("config.sub", name) ||
        wildmatch("**/config.sub", name) ||
        wildmatch("config.guess", name) ||
        wildmatch("**/config.guess", name) ||
        wildmatch("install-sh", name) ||
        wildmatch("**/install-sh", name) ||
        wildmatch("depcomp", name) ||
        wildmatch("**/depcomp", name) ||
        wildmatch("missing", name) ||
        wildmatch("**/missing", name) ||
        wildmatch("mkinstalldirs", name) ||
        wildmatch("**/mkinstalldirs", name) ||
        wildmatch("**.sh", name)) return 1;
    return 0;
}

int is_encrypted(char *name)
{
    patternlist *p;
    for (p=textencrypted; p!=NULL; p=p->next)
    {   stringlist *s;
        for (s=p->p; s!=NULL; s=s->next)
           if (wildmatch(s->name, name)) return (p->flag<0);
    }
    return 0;
}

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

static int quietflag = 0, noisyflag = 0, nodeleteflag = 0;

char *localfilename(char *n)
{
    char name[LONGEST_LEGAL_FILENAME], *w;
    make_local_style_filename(name, n);
    w = (char *)Xmalloc(strlen(name)+1);
    strcpy(w, name);
    return w;
}

char *unixfilename(char *n)
{
    stringlist *s;
    char *changed = NULL;
    char name[LONGEST_LEGAL_FILENAME], casename[LONGEST_LEGAL_FILENAME], *w;
    make_unix_style_filename(name, n);
/*
 * If I have listed some names as belonging in mixed case I apply that
 * transformation here.
 */
    if (!hostcase)
    {   for (s=mixedcase; s!=NULL; s=s->next)
        {   if (casefold_match(casename, s->name, name))
            {   changed = s->name;
                break;
            }
        }
    }
    if (!hostcase)
    {
        if (changed != NULL) strcpy(name, casename);
    }
    w = (char *)Xmalloc(strlen(name)+1);
    strcpy(w, name);
    return w;
}

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

static unsigned32 CRC;

static void update_CRC(int ch)
{
    unsigned32 CRCtemp = ((CRC & 0x01ffffff) << 7);
/*
 * This is my favourite hash function at present - it cycles a 31-bit shift
 * register with maximum period.  As used here the item mixed in (ch) will
 * always have been masked with 0xff.
 */
    CRC = ((CRC >> 25) ^      /* NB logical (not arithmetic) shift here */
           (CRCtemp >> 1) ^
           (CRCtemp >> 4) ^
           (unsigned32)ch) & 0x7fffffff;
}

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

typedef struct list_of_files
{
    char *filename;
    char *unixname;
    int dirp;
    int encryptedp;
    int binaryp;
    int execp;
    int newp;         /* 0 is default state */
    long int size;
    unsigned32 datestamp;
    unsigned32 checksum;
    struct list_of_files *next;
} list_of_files;

list_of_files *previous = NULL, *current = NULL, *oldfiles = NULL;
int how_many = 0;

list_of_files *reverse_list_of_files(list_of_files *p)
{
    list_of_files *r = NULL;
    while (p != NULL)
    {   list_of_files *p1 = p->next;
        p->next = r;
        r = p;
        p = p1;
    }
    return r;
}

/*
 * sortlist is a merge sort that destructively sorts the list of files
 * on the basis of their "unixname" fields. The order used is alphabetic
 * case insensitive, so that warnings can easily be generated for files
 * whose names only differ in case.
 */

int nameorder(char *n1, char *n2)
{
    for (;;)
    {   int c1 = *n1++, c2 = *n2++;
        if (c1 == 0) return 1;
        else if (c2 == 0) return 0;
        c1 = tolower(c1);
        c2 = tolower(c2);
        if (c1 != c2) return (c1 < c2);
    }
}

list_of_files *sortlist(list_of_files *p)
{
    list_of_files *p1 = NULL, *p2 = NULL, *w;
/* A base condition for the recursion */
    if (p == NULL || p->next == NULL) return p;
/* First I split the input list into two (almost) equally sized parts. */
    for (;;)
    {   if (p == NULL) break;
        w = p; p = p->next; w->next = p1; p1 = w;
        if (p == NULL) break;
        w = p; p = p->next; w->next = p2; p2 = w;
    }
/* Sort each of these */
    p1 = sortlist(p1);
    p2 = sortlist(p2);
/* Merge to make one ordered list */
    while (p1 != NULL && p2 != NULL)
    {   if (nameorder(p1->unixname, p2->unixname))
        {   w = p1; p1 = p1->next; w->next = p; p = w;
        }
        else
        {   w = p2; p2 = p2->next; w->next = p; p = w;
        }
    }
/* At the end I have built most of my output in reverse order, so fix it */
    if (p1 == NULL) p1 = p2;
    while (p != NULL)
    {   w = p; p = p->next; w->next = p1; p1 = w;
    }
    return p1;
}

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

int commandp(char *buffer, char *word)
{
    int c1, c2;
    while ((c2 = *word++) != 0)
    {   c1 = *buffer++;
        if (c1 == 0) return 0;
        c1 = tolower(c1);
        if (c1 != c2) return 0;
    }
    c1 = *buffer;
    return (c1 == ' ' || c1 == '\t' || c1 == '=' || c1 == 0);
}

stringlist *readnames(stringlist *l, char *b)
{
    int i, c = *b++;
    char name[LONGEST_LEGAL_FILENAME], *s;
    stringlist *w;
    while (c != 0)
    {   while (c == ' ' || c == '\t') c = *b++;
        i = 0;
        while (c != ' ' && c != '\t' && c != 0)
        {   name[i++] = c;
            c = *b++;
        }
        if (i == 0) continue;
        name[i] = 0;
        s = (char *)Xmalloc(i+1);
        strcpy(s, name);
        w = (stringlist *)Xmalloc(sizeof(stringlist));
        w->name = s;
        w->next = l;
        l = w;
    }
    return l;
}

/*
 * I clearly have a buffer overflow worry with ridiculous pretend
 * file-names here... But this is a user-mode utility and I will not worry!
 */
static char master_url[LONGEST_LEGAL_FILENAME+16];

static FILE *fopen1(char *directory, char *name, char *mode);

int getc_nocr(FILE *f)
{
    int c = getc(f);
    while (c == '\r') c = getc(f);
    return c;
}

void read_patterns_file(char *directory, char *master_site)
{
    char line[LONGEST_LEGAL_FILENAME+16];
    int c;
    FILE *f1;
    include = omit = text = binary =
        encrypted = mixedcase = executable = nonexecutable = NULL;
    hostcase = 1;
    includeomit = textbinary = textencrypted = execnonexec = NULL;
    master_url[0] = 0;
    f1 = fopen1(directory, "xport.pat", "r");
    if (f1 == NULL)
    {   fprintf(myout, "Warning - no file \"xport.pat\" found\n");
        if (master_site != NULL)
        {   fprintf(myout, "Will try <%s> as URL\n", master_site);
            strcpy(master_url, master_site);
        }
        fflush(myout);
        return;
    }
    for (;;)
    {   int i = 0;
        for (;;)
        {   c = getc_nocr(f1);
            if (c == '\r' || c == '\f') continue;
            if (c == EOF || c == '\n')
            {   line[i] = 0;
                break;
            }
            else if (i == 0 && (c == ' ' || c == '\t')) continue;
            else if (i < sizeof(line)-1) line[i++] = c;
        }
        if (commandp(line, "include"))
        {   if (omit != NULL)
            {   patternlist *p = (patternlist *)Xmalloc(sizeof(patternlist));
                p->flag = -1;
                p->p = omit;
                p->next = includeomit;
                includeomit = p;
                omit = NULL;
            }
            include = readnames(include, &line[7]);
        }
        else if (commandp(line, "omit"))
        {   if (include != NULL)
            {   patternlist *p = (patternlist *)Xmalloc(sizeof(patternlist));
                p->flag = 1;
                p->p = include;
                p->next = includeomit;
                includeomit = p;
                include = NULL;
            }
            omit = readnames(omit, &line[4]);
        }
        else if (commandp(line, "executable"))
        {   if (nonexecutable != NULL)
            {   patternlist *p = (patternlist *)Xmalloc(sizeof(patternlist));
                p->flag = 1;
                p->p = nonexecutable;
                p->next = execnonexec;
                execnonexec = p;
                nonexecutable = NULL;
            }
            executable = readnames(executable, &line[10]);
        }
        else if (commandp(line, "nonexecutable"))
        {   if (executable != NULL)
            {   patternlist *p = (patternlist *)Xmalloc(sizeof(patternlist));
                p->flag = -1;
                p->p = executable;
                p->next = execnonexec;
                execnonexec = p;
                executable = NULL;
            }
            nonexecutable = readnames(nonexecutable, &line[13]);
        }
        else if (commandp(line, "text"))
        {   if (binary != NULL)
            {   patternlist *p = (patternlist *)Xmalloc(sizeof(patternlist));
                p->flag = -1;
                p->p = binary;
                p->next = textbinary;
                textbinary = p;
                binary = NULL;
            }
            text = readnames(text, &line[4]);
        }
        else if (commandp(line, "binary"))
        {   if (text != NULL)
            {   patternlist *p = (patternlist *)Xmalloc(sizeof(patternlist));
                p->flag = 1;
                p->p = text;
                p->next = textbinary;
                textbinary = p;
                text = NULL;
            }
            binary = readnames(binary, &line[6]);
        }
        else if (commandp(line, "encrypted"))
            encrypted = readnames(encrypted, &line[9]);
        else if (commandp(line, "hostcase"))
            hostcase = 1;
        else if (commandp(line, "nohostcase"))
            hostcase = 0;
        else if (commandp(line, "mixedcase"))
            mixedcase = readnames(mixedcase, &line[9]);
        else if (commandp(line, "master"))
        {   i = 6;
/*
 * If an explicit site was given on the command line AND I find a
 * record in the file that matches it I will use that URL. If there are
 * multiple matches I will accept the first one found.
 * If no command line tag was given I will use the first record
 * in the file (tagged or not).
 * If a command-line tag is given I will insist that it matches some
 * key in the file.
 */
            if (master_url[0] != 0) continue;
            if (line[i] == '=') /* "master=" record - read & check a tag */
            {   if (master_site == NULL)
                {   while (line[i] != ' ' &&
                           line[i] != '\t' &&
                           line[i] != 0) i++;
                }
                else
                {   /* Do some matching here */
                    char *key = master_site;
                    i++;
                    for (;;)
                    {   int c1 = line[i++], c2 = *key++;
                        if (c2 == 0)
                        {   if (c1 == ' ' || c1 == '\t' || c1 == 0) key = NULL;
                            break;
                        }
                        else if (c1 == ' ' || c1 == '\t' || c1 == 0) break;
                        if (tolower(c1) != tolower(c2)) break;
                    }
                    if (key != NULL) continue;
                }
            }
            else if (master_site != NULL) continue;
            while (line[i] == ' ' || line[i] == '\t') i++;
            strcpy(master_url, &line[i]);
            i = strlen(line) - 1;
            if (i >= 0 && line[i] == '/') line[i] = 0;
        }
        else if (i != 0 && line[0] != '#')
        {   strcpy(&line[32], "...");  /* truncate it for the message */
            i = 0;
            while (line[i] != 0 &&
                   line[i] != '\n' &&
                   line[i] != '\r') i++;
            line[i] = 0;
            fprintf(myout, "Unrecognized pattern line \"%s\"\n", line);
            fflush(myout);
        }
        if (c == EOF) break;
    }
    fclose(f1);
    if (omit != NULL)
    {   patternlist *p = (patternlist *)Xmalloc(sizeof(patternlist));
        p->flag = -1;
        p->p = omit;
        p->next = includeomit;
        includeomit = p;
    }
    if (include != NULL)
    {   patternlist *p = (patternlist *)Xmalloc(sizeof(patternlist));
        p->flag = 1;
        p->p = include;
        p->next = includeomit;
        includeomit = p;
    }
    if (binary != NULL)
    {   patternlist *p = (patternlist *)Xmalloc(sizeof(patternlist));
        p->flag = -1;
        p->p = binary;
        p->next = textbinary;
        textbinary = p;
    }
    if (text != NULL)
    {   patternlist *p = (patternlist *)Xmalloc(sizeof(patternlist));
        p->flag = 1;
        p->p = text;
        p->next = textbinary;
        textbinary = p;
    }
    if (executable != NULL)
    {   patternlist *p = (patternlist *)Xmalloc(sizeof(patternlist));
        p->flag = -1;
        p->p = executable;
        p->next = execnonexec;
        execnonexec = p;
    }
    if (nonexecutable != NULL)
    {   patternlist *p = (patternlist *)Xmalloc(sizeof(patternlist));
        p->flag = 1;
        p->p = nonexecutable;
        p->next = execnonexec;
        execnonexec = p;
    }
    if (master_url[0] == 0 && master_site!=NULL)
    {   fprintf(myout, "Will try <%s> as URL\n", master_site);
        fflush(myout);
        strcpy(master_url, master_site);
    }
}

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

#define FETCH_NEW_OK    0
#define FETCH_NEW_NONE  1
#define FETCH_NEW_FAIL  2

int fetch_list_of_new_files(char *mastername, char *fname)
{
    socket_file *f;
    char url[LONGEST_LEGAL_FILENAME];
    int c;
    FILE *dest;
    if ((dest = fopen("xport.tmp", "w")) == NULL)
    {   fprintf(myout, "Failed to open \"xport.tmp\" for writing\n");
        fflush(myout);
        return FETCH_NEW_FAIL;
    }
    sprintf(url, "%s/%s", master_url, mastername);
    if ((f = xopen_url(url, 0)) == NULL)
    {   fprintf(myout, "Unable to access \"%s\"\n", url);
        fclose(dest);
        fflush(myout);
        return FETCH_NEW_NONE;
    }
    CRC = 1;
    while ((c = char_from_data(f)) != EOF)
    {
/*
 * In the list of new files I will ignore any carriage returns that the
 * remote site tries to send me! This is in case a Windows-style file has
 * been installed (maybe cross-mounted) on a Unix server. In such cases
 * I expect to see a linefeed which should look like '\n' anyway.
 */
        if (c != '\r')
        {   update_CRC(c & 0xff);
            putc(c, dest);
        }
    }
    fclose(dest);
    if (f != NULL) close_socket(f);
/*
 * I arrange that the "xport.chk" files always have a checksum of 0x11111111
 * so that I can fetch and validate one without having to exhibit any
 * sort of serious inspiration.
 */
    if (CRC != 0x11111111)
    {   fprintf(myout, "checksum failure while fetching \"%s\"\n", mastername);
        fflush(myout);
        return FETCH_NEW_FAIL;
    }
    remove(fname);
    if (rename("xport.tmp", fname))
    {   fprintf(myout, "Failed to rename \"xport.tmp\" as \"%s\"\n", fname);
        fflush(myout);
        return FETCH_NEW_FAIL;
    }
    return FETCH_NEW_OK;
}

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

static list_of_files *make_list(char *fname1, unsigned32 dstamp,
    unsigned32 csum, int dirp, int encp, int binp,
    int execp, list_of_files *prev)
{
    list_of_files *list1 =
        (list_of_files *)Xmalloc(sizeof(list_of_files));
    char *name1 = (char *)Xmalloc(strlen(fname1)+1);
    strcpy(name1, fname1);
    list1->unixname = name1;
    list1->filename = localfilename(name1);
    list1->dirp = dirp;
    list1->encryptedp = encp;
    list1->binaryp = binp;
    list1->execp = execp;
    list1->newp = 0;
    list1->size = 0;
    list1->datestamp = dstamp;
    list1->checksum = csum;
    list1->next = prev;
    return list1;
}

static char check_header[64];

void read_increments(char *directory, char *fname)
{
    FILE *f = fopen1(directory, fname, "r");
    char line[LONGEST_LEGAL_FILENAME+28];
    int c;
    int code, dirp, binp;
    char codex[4];
    unsigned32 datestamp;
    unsigned32 checksum;
    list_of_files **pprev = &previous, *prev = previous;
    if (f == NULL)
    {   fprintf(myout, "File \"%s\" could not be read\n", fname);
        fflush(myout);
        return;    /* No action if file not found */
    }
/*
 * Start by skipping the first 2 lines of the increment file
 */
    while ((c = getc_nocr(f)) != EOF && c != '\n');
    if (c != EOF) while ((c = getc_nocr(f)) != EOF && c != '\n');
    if (c == EOF)
    {   fclose(f);
        return;
    }
    for (;;)
    {   int i = 0;
        char *name;
        while ((c = getc_nocr(f)) != EOF && c != '\n')
            if (i < sizeof(line)-2 && c!='\r' && c!='\f') line[i++] = c;
        line[i] = 0;
        if (c == EOF && i == 0) break;
        if (sscanf(line, "%c%8x %8x %d %d",
                   &codex[0], &datestamp, &checksum, &dirp, &binp) != 5)
        {   fprintf(myout, "Malformed line in xport.inc file\n");
            fflush(myout);
            break;
        }
/*
 * Hah: sscanf with a "%c" format must have a pointer to a "char" not an
 * "int" because otherwise on machines with one byte-order (eg Sun) the
 * charecter gets put at the end of the word where nobody looks. What a
 * horrid C pitfall the "%c" format specifier is here.
 */
        code = codex[0];
        name = &line[23];
        code &= 0xff;
        while (prev != NULL &&
               strcmp(prev->unixname, name) != 0 &&
               nameorder(prev->unixname, name))
        {   pprev = &(prev->next);
            prev = *pprev;
        }
        if (prev != NULL && strcmp(prev->unixname, name) == 0)
        {
            switch (code)
            {
        default:
                fprintf(myout,
                "Code in increment file should be A C or D but is '%c'=%x\n",
                    code, code);
                fflush(myout);
                break;
        case 'A':
                fprintf(myout, "Increment code 'A' but file seen in base\n");
                fflush(myout);
                break;
        case 'C':
                prev->datestamp = datestamp;
                prev->checksum = checksum;
                prev->dirp = dirp;
                prev->execp = (binp>>2) & 1;
                prev->encryptedp = (binp>>1) & 1;
                prev->binaryp = (binp & 1);
                break;
        case 'D':
                prev = prev->next;
                *pprev = prev;
                break;
            }
        }
        else if (code != 'A')
        {   fprintf(myout,
                "Increment code is '%c' not 'A' but file not seen in base\n",
                code);
            fflush(myout);
            break;
        }
        else
        {   *pprev = make_list(name, datestamp, checksum, dirp,
                               (binp>>1)&1, binp&1, (binp>>2)&1, prev);
            pprev = &((*pprev)->next);
        }
        if (c == EOF) break;
    }
    fclose(f);
    return;
}

int read_list_of_files(char *directory, char *fname, char *incname)
{
    char line[LONGEST_LEGAL_FILENAME+24];
    char fname1[LONGEST_LEGAL_FILENAME], fname2[LONGEST_LEGAL_FILENAME];
    char *sample = "EXPORT: Signatures 10:45:18.12-Sep-1994 <@@DBBCEHKNBE>\n";
    FILE *f1;
    unsigned32 dstamp, csum;
    int i, dirp, binp, c;
    previous = NULL;
    if (directory == NULL) strcpy(fname1, fname);
    else sprintf(fname1, "%s%c%s", directory, DIRECTORY_CHAR, fname);
    f1 = fopen(fname1, "r");
    if (f1 == NULL)
    {   fprintf(myout, "Warning - no file \"%s\" found\n", fname1);
        fflush(myout);
        return 0;
    }
    CRC = 1;
    for (i=0; i<60;)
    {   c = getc_nocr(f1);
        if (c == EOF) break;
/*
 * In a local xport.chk or xport.inc file I will ignore any '\r'.
 */
        if (c != '\r')
        {   update_CRC(c & 0xff);
            line[i++] = c;
        }
        if (c == '\n') break;
    }
    line[i] = 0;
    if (i != (int)strlen(sample) ||
        strncmp(line, sample, 19) != 0)
    {   fprintf(myout,
                "File \"%s\" does not have correct header line\n", fname1);
        fclose(f1);
        fprintf(myout, "%d vs %d\n", i, (int)strlen(sample));
        fflush(myout);
        return 0;
    }
    strcpy(check_header, line);
    for (;;)
    {   for (i=0; i<sizeof(line)-1; i++)
        {   c = getc_nocr(f1);
            if (c == EOF) break;
            if (c != '\r')
            {   update_CRC(c & 0xff);
                line[i] = c;
            }
            if (c == '\n') break;
        }
        if (c == EOF) break;
        line[i] = 0;
        if ((i = sscanf(line,
                  "%x %x %d %d %s\n", &dstamp, &csum, &dirp, &binp, fname2))
                   != 5)
        {   fprintf(myout, "Failed to parse (%d) the line:\n<%s>\n", i, line);
            fflush(myout);
            break;
        }
        previous = make_list(fname2, dstamp, csum, dirp,
                             (binp>>1)&1, binp&1, (binp>>2)&1, previous);
    }
    fclose(f1);
    if (CRC != 0x11111111)
    {   previous = NULL;
        fprintf(myout, "Checksum failure in \"%s\" (%.8x)\n", fname1, CRC);
        fflush(myout);
        return 0;
    }
    previous = reverse_list_of_files(previous);
    if (incname != NULL) read_increments(directory, incname);
    return 1;
}

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

/*
 * When scanning files I may have an extended path name that contains
 * a route to the directory that is being processed. I do not want to
 * include this part of the name in the lists I create. scan_leafstart
 * indicates how many characters are in this unwanted part -- see "scandir.h"
 */

/*
 * This gets called, with dirp a code to tell me if I have a directory or
 * a regular file to handle.  The size will be an APPROXIMATION to the
 * bulk of the file but will not be portable across systems (eg because
 * of the representation of end-of-line in text files).
 */

void record_one_file(char *name, int dirp, long int size)
{
    char *name1, *name2, *relname = name+scan_leafstart;
    char *unixname;
    list_of_files *list1;
    date_and_type datestamp;
    if ((int)strlen(name) <= scan_leafstart) return;
    unixname = unixfilename(relname);
/*
 * I make a separate list of all files called "*.old" so that if needbe I can
 * delete them.
 */
    if (wildmatch("**.old", unixname))
    {   name1 = (char *)Xmalloc(strlen(relname) + 1);
        name2 = unixname;
        list1 = (list_of_files *)Xmalloc(sizeof(list_of_files));
        strcpy(name1, relname);
        strcpy(name2, unixname);
        list1->filename = name1;
        list1->unixname = name2;
        list1->dirp = dirp;
        list1->encryptedp = is_encrypted(unixname);
        list1->binaryp = is_binary(unixname);
        list1->execp = is_executable(unixname);
        list1->newp = 0;
        list1->size = size;
        list1->datestamp = 0;
        list1->checksum = 0;
        list1->next = oldfiles;
        oldfiles = list1;
    }
    if (should_omit(unixname)) return;
    switch (dirp)
    {
case 0: how_many++;  /* I only count FILES not directories here */
case 1: name1 = (char *)Xmalloc(strlen(relname) + 1);
        name2 = unixname;
        list1 = (list_of_files *)Xmalloc(sizeof(list_of_files));
        strcpy(name1, relname);
        strcpy(name2, unixname);
        list1->filename = name1;
        list1->unixname = name2;
        list1->dirp = dirp;
        list1->encryptedp = is_encrypted(unixname);
        list1->binaryp = is_binary(unixname);
        list1->execp = is_executable(unixname);
        list1->newp = 0;
        list1->size = size;
        get_fileinfo(&datestamp, name1);
/*
 * Note that the information I obtain about the file here includes
 * whether it is executable, but what I propagate is NOT based on what
 * I find on disc but on what is declared in the patterns file.
 */
        list1->datestamp = dirp ? 0 : datestamp.date;
        list1->checksum = 0;
        list1->next = current;
        current = list1;
        break;
default:
        break;
    }
}

void find_existing_files(char *directory_to_scan)
{
    current = oldfiles = NULL;
    scan_directory(directory_to_scan, record_one_file);
    current = sortlist(current);
    oldfiles = sortlist(oldfiles);
}

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

static char file_buffer[1024*1024];

void compute_checksums(char *directory, list_of_files *filep)
{
    list_of_files *fp;
    int crseen = 0, maybeshell = 1;
    for (fp=filep; fp!=NULL;)
    {   char *mode = fp->binaryp ? "rb" : "r";
/* @@@ binary vs encryption here */
        FILE *f;
        char line[50], old_date[16];
        unsigned32 old_checksum, save_CRC;
        int found, n, counter = 0, xline = 1;
        crseen = 0;
        maybeshell = 1;
        if (fp->dirp) fp->checksum = 0;
        else
        {   f = fopen1(directory, fp->filename, mode);
            if (f == NULL) fp->checksum = 0;
            else
            {   int c;
                setvbuf(f, file_buffer, _IOFBF, 1024*1024);
                save_CRC = CRC = 1;
                found = 0;
                n = 0;
/*
 * If I find a character with a dodgy code I mark the file as being "binary".
 * This is not a guaranteed recipe for success, especially since if a
 * binary file was being read in text mode I may not see all the data in
 * it (consider an MSDOS file with first byte matching the code '^Z').
 * But maybe it is better than nothing. Also if in text mode I detect any
 * line consisting of the text that I use to mark file signatures, and I both
 * check at the end that the signature matches, and ignore the signature line
 * itself in the checksum calculation
 */
                while ((counter++, c = getc(f)) != EOF)
                {   c &= 0xff;
/*
 * I do not want shell scripts to have carriage returns in them, since
 * I find that that is a common cause of confusion generated via cygwin. I
 * will GUESS that a file is a script it its first two chars are "#!". This
 * is of course not a 100% guaranteed but it may be good enough to let
 * me issue warnings based on it.
 */
                    if (c == '\r') crseen = 1;
                    else if (counter==1 && c != '#') maybeshell=0;
                    else if (counter==2 && c != '!') maybeshell=0;
                    else if (c == '\n')
                    {
                        xline++;
                    }
/*
 * My characterisation of "dodgy" characters here is pretty clearly
 * a delicate one. It is also painfully tied to a particular character
 * set and encoding. I will express doubts about control characters
 * other than newline, tab and formfeed. Note that this means that a file
 * with a backspace or vertical tab or carriage return in it will be viewed
 * as "binary". I also reject all characters with code 0x7f upwards, except
 * 0xa9 and 0xb8. These last two are copyright marks in two different
 * Windows code-pages, and might plausibly (!) occur in source files.
 * A significant case where this guesswork will fail will be when a Windows
 * host has a file where line separation uses just linefeed (nor CR/LF). I
 * believe that the C library will pass that back to me as '\n' so the file
 * will be treated as text. If it then ever gets back to a Windows machine
 * the LFs will get expanded into CR/LF and nothing in this whole mechanism
 * will know or protect me. It may be that similar issues arise if LF/CR is
 * used instead of CR/LF etc etc. So PLEASE mention any such files in
 * "xport.pat" so that the fact that they must be treated as binary files is
 * clear and unambiguous.
 */
                    if (seems_binary(c) &&
                        !fp->binaryp) break;
/*
 * Because of fun with cross-mounted file-systems I am going to ignore
 * carriage-returns while computing the checksum for a "text" file. But
 * for security I will not ignore them while checksumming a binary file.
 */
                    if (fp->binaryp || c != '\r') update_CRC(c);
                    if (!fp->binaryp && !found)
                    {   if (c == '\n')
                        {   line[n] = 0;
                            if (n == 37 &&
                                sscanf(line, "/* Signature: %x %11s */",
                                       &old_checksum, old_date) == 2)
                                found = 1, CRC = save_CRC;
                            save_CRC = CRC;
                            n = 0;
                        }
                        else if (n < 40 && c != '\r') line[n++] = c;
                    }
                }
                if (c != EOF)
                {   fp->binaryp = 1;
                    fclose(f);
                    if (noisyflag)
                        fprintf(myout,
"\"%s\" will be handled in binary mode (code = %.2x at char %d line %d)\n",
                           fp->filename, c, counter, xline);
                    fflush(myout);
                    continue;  /* try again in binary mode */
                }
                fclose(f);
                if (found && CRC != old_checksum && old_checksum != 0)
                    if (!quietflag)
                    {   fprintf(myout,
                        "File \"%s\" has checksum %.8x but is signed %.8x\n",
                           fp->filename, CRC, (unsigned32)old_checksum);
                        fflush(myout);
                    }
                fp->checksum = CRC;
            }
        }
        if (crseen && maybeshell)
        {   fprintf(myout, "File \"%s\" may be a shell script in DOS mode\n",
                    fp->filename);
            fprintf(myout, "Check, and if necessary remove CR characters\n");
        }
        fp = fp->next;
    }
}

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

/*
 * This prints a 48-bit number using radix 32, with letters @ABC...
 * as digits. The intent of these is that the bit-pattern in the
 * representation mirrors that in the number. This rather assumes
 * ASCII code, but what is really required here is that 16 consecutive
 * character codes starting at ('A'-1) are all printable.
 */

void put_bits(char *bb, unsigned32 bit, unsigned32 bit1)
{
    int i;
    *bb++ = '<';
    for (i=0; i<12; i++)
    {   int n = (bit1 >> 12) & 0xf;
        *bb++ = 'A' + n - 1;
        bit1 = ((bit1 & 0xfff) << 4) | ((bit >> 28) & 0xf);
        bit = (bit & 0x0fffffff) << 4;
    }
    *bb++ = '>';
    *bb = 0;
}

typedef int writeline(char *dest, int seq);

static list_of_files *s_fp;

int write_main_signature_line(char *dest, int seq)
{
    if (seq == 1) s_fp = current;
    if (s_fp == NULL) return 0;  /* report finished */
    sprintf(dest, "%.8x %.8x %d %d %s\n",
                   s_fp->datestamp, s_fp->checksum,
                   s_fp->dirp,
                   (s_fp->binaryp |
                    (s_fp->encryptedp<<1) |
                    (s_fp->execp<<2)),
                   s_fp->unixname);
    s_fp = s_fp->next;
    return 1;
}

static list_of_files *s_p, *s_c;

int write_incremental_signature_line(char *dest, int seq)
{
    if (seq == 1)
    {   s_p = previous;
        s_c = current;
        sprintf(dest, "Base \"xport.chk\":  %s", check_header+19);
        return 1;
    }
    while (s_p && s_c)
    {   char *pn = s_p->unixname, *cn = s_c->unixname;
        if (strcmp(pn, cn) == 0)
        {   int changed = 0;
            if (s_p->binaryp != s_c->binaryp) changed = 1;
            if (s_p->execp != s_c->execp) changed = 1;
            else if (s_p->checksum != s_c->checksum) changed = 1;
            if (changed)
                sprintf(dest, "C%.8x %.8x %d %d %s\n",
                              s_c->datestamp, s_c->checksum,
                              s_c->dirp, 
                              (s_c->binaryp |
                               (s_c->encryptedp<<1) |
                               (s_c->execp<<2)),
                              s_c->unixname);
            s_p = s_p->next;
            s_c = s_c->next;
            if (changed) return 1;
        }
        else if (nameorder(pn, cn))
        {   sprintf(dest, "D%.8x %.8x %d %d %s\n",
                          s_p->datestamp, s_p->checksum,
                          s_p->dirp, 
                          (s_p->binaryp |
                           (s_p->encryptedp<<1) |
                           (s_p->execp<<2)),
                          s_p->unixname);
            s_p = s_p->next;
            return 1;
        }
        else
        {   sprintf(dest, "A%.8x %.8x %d %d %s\n",
                          s_c->datestamp, s_c->checksum,
                          s_c->dirp,
                          (s_c->binaryp |
                           (s_c->encryptedp<<1) |
                           (s_c->execp<<2)),
                          s_c->unixname);
            s_c = s_c->next;
            return 1;
        }
    }
    if (s_p)
    {   sprintf(dest, "D%.8x %.8x %d %d %s\n",
                      s_p->datestamp, s_p->checksum,
                      s_p->dirp,
                      (s_p->binaryp |
                       (s_p->encryptedp<<1) |
                       (s_p->execp<<2)),
                      s_p->unixname);
        s_p = s_p->next;
        return 1;
    }
    if (s_c)
    {   sprintf(dest, "A%.8x %.8x %d %d %s\n",
                      s_c->datestamp, s_c->checksum,
                      s_c->dirp,
                      (s_c->binaryp |
                       (s_c->encryptedp<<1) |
                       (s_c->execp<<2)),
                      s_c->unixname);
        s_c = s_c->next;
        return 1;
    }
    return 0;
}

void write_the_signatures(FILE *sigfile, char *header, writeline *fn)
{
    char line[LONGEST_LEGAL_FILENAME+24], bb[20];
    unsigned32 basecheck, bitsin[49], bitsin1[49], bitsout[49], bit, bit1;
    int i, done[48], seq;
/*
 * Now I want to arrange that the overall checksum of this file is a fixed
 * value. I achieve this by working out the (linear) way that the checksum
 * depends on characters in a 12-place field, and then adjusting those
 * characters to make the overall checksum come out as I want it.
 */
    for (i=0; i<49; i++)
    {   char *p;
        int c;
        CRC = 1;
        bit = bit1 = 0;
        if (i < 32) bit = (1 << i);
        else if (i < 48) bit1 = (1 << (i-32));
        put_bits(bb, bit, bit1);
        bitsin[i] = bit, bitsin1[i] = bit1;
        sprintf(line, "%19.19s%s.%s %s\n", header, today, timeofday, bb);
        p = line;
/* Signature files are text so I can ignore carriage returns */
        while ((c = *p++) != 0)
            if (c != '\r') update_CRC(c & 0xff);
        seq = 1;
        while ((*fn)(line, seq++))
        {   p = line;
            while ((c = *p++) != 0)
                if (c != '\r') update_CRC(c & 0xff);
        }
        bitsout[i] = CRC;
    }
    basecheck = bitsout[48];
    for (i=0; i<48; i++)
    {   bitsout[i] ^= basecheck;
        done[i] = -1;
    }
    for (i=0; i<31; i++)  /* NB bit 31 of checksum == 0 always */
    {   int j, k;
        bit = (1 << i);
        for (j=0; j<48; j++)
            if ((bitsout[j] & bit) && done[j]<0) break;
        if (j == 48)
        {   fprintf(myout, "Bit %d not adjustable\n", i);
            fflush(myout);
            continue;  /* This bit uncontrollable - WORRY */
        }
        done[j] = i;
        for (k=0; k<48; k++)
            if (k!=j && (bitsout[k] & bit))
            {   bitsin[k]  ^= bitsin[j];
                bitsin1[k] ^= bitsin1[j];
                bitsout[k] ^= bitsout[j];
            }
    }
    basecheck ^= 0x11111111;   /* The desired checksum */
    bit = bit1 = 0;
    for (i=0; i<32; i++)
    {   unsigned32 bit2 = (1 << i);
        int j;
        if ((basecheck & bit2) == 0) continue;
        for (j=0; j<48; j++)
            if (done[j] >= 0 && bitsout[j] == bit2) break;
        if (j == 48)
        {   fprintf(myout, "failed to force checksum of zero\n");
            fflush(myout);
            exit(EXIT_FAILURE);
        }
        basecheck ^= bit2;
        bit  ^= bitsin[j];
        bit1 ^= bitsin1[j];
    }
    put_bits(bb, bit, bit1);
    fprintf(sigfile, "%19.19s%s.%s %s\n", header, today, timeofday, bb);
    seq = 1;
    while ((*fn)(line, seq++))
    {   char *p = line;
        int c;
        while ((c = *p++) != 0) putc(c, sigfile);
    }
    sprintf(check_header, "%19.19s%s.%s %s\n", header, today, timeofday, bb);
}

void make_signature_file()
{
    FILE *sigfile;
    sigfile = fopen("xport.chk", "w");
    if (sigfile == NULL)
    {   fprintf(myout, "Unable to write to \"xport.chk\"\n");
        fflush(myout);
        exit(EXIT_FAILURE);
    }
    get_todays_date();
    write_the_signatures(sigfile, "EXPORT: Signatures ",
                         write_main_signature_line);
    fclose(sigfile);
    sigfile = fopen("xport.inc", "w");
    if (sigfile == NULL)
    {   fprintf(myout, "Unable to write to \"xport.inc\"\n");
        fflush(myout);
        exit(EXIT_FAILURE);
    }
    previous = current = NULL;
    write_the_signatures(sigfile, 
        "EXPORT: Increments ", write_incremental_signature_line);
    fclose(sigfile);
}

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

/*
 * previous and current are lists of files to compare.
 */

#define NEW_BINMODE 1
#define NEW_CHANGED 2
#define NEW_NEW     4

void report_differences(int only_local, int listflag)
{
    list_of_files *p = previous, *c = current;
    fflush(myout);
    while (p && c)
    {   char *pn = p->unixname, *cn = c->unixname;
        if (strcmp(pn, cn) == 0)
        {
            if (p->binaryp != c->binaryp)
            {   if (listflag)
                    fprintf(myout, "%c%s\n", p->binaryp?'B':'A', cn);
                else if (!quietflag)
                    fprintf(myout,
                       "Binary/text status changed for %s (now %s)\n", cn,
                       p->binaryp ? "binary" : "text");
                fflush(myout);
            }
            if (p->execp != c->execp)
            {   if (listflag)
                    fprintf(myout, "%c%s\n", p->execp?'B':'A', cn);
                else if (!quietflag)
                    fprintf(myout,
                       "Executable status changed for %s (now %s)\n", cn,
                       p->execp ? "executable" : "non-executable");
                fflush(myout);
            }
            else if (p->checksum != c->checksum)
            {   if (listflag)
                    fprintf(myout, "%c%s\n", p->binaryp?'B':'A', cn);
                else switch (c->newp)
                {
            case 0: if (!quietflag)
                    {   if (only_local) fprintf(myout,
                            "File %s has been changed\n", cn);
                        else fprintf(myout,
                            "File %s can be updated from the master site\n",
                            cn);
                    }
                    break;
            case NEW_BINMODE:
            case NEW_BINMODE+NEW_CHANGED:
                    if (!quietflag)
                    {   fprintf(myout,
                    "File %s changed binary/text mode recently and needs\n",
                            cn);
                        fprintf(myout, "updating from the master site\n");
                    }
                    break;
            case NEW_CHANGED:
                    fprintf(myout, "File %s changed locally. Please check\n",
                                   cn);
                    break;
            case NEW_NEW:
                    fprintf(myout,
                            "File %s created locally recently. Please check\n",
                            cn);
                    break;
            default:
                    if (!quietflag) fprintf(myout, "File %s changed\n", cn);
                    break;
                }
            }
            fflush(myout);
            p = p->next;
            c = c->next;
            continue;
        }
        if (nameorder(pn, cn))
        {   if (listflag)
                fprintf(myout, "%c%s\n", p->binaryp?'B':'A', pn);
            else if (!quietflag) fprintf(myout, "Missing %s\n", pn);
            p = p->next;
        }
        else
        {   if (listflag)
                fprintf(myout, "D%s\n", cn);
            else if (!quietflag) fprintf(myout, "Unwanted %s\n", cn);
            c = c->next;
        }
    }
    fflush(myout);
    while (p)
    {   if (listflag)
                fprintf(myout, "%c%s\n", p->binaryp?'B':'A', p->unixname);
        else if (!quietflag) fprintf(myout, "Missing %s\n", p->unixname);
        p = p->next;
    }
    while (c)
    {   if (listflag) fprintf(myout, "D%s\n", c->unixname);
        else if (!quietflag) fprintf(myout, "Unwanted %s\n", c->unixname);
        c = c->next;
    }
    fflush(myout);
}

void write_increments(char *name)
{
    FILE *sigfile = fopen(name, "w");
    if (sigfile == NULL)
    {   fprintf(myout, "Unable to write to \"%s\"\n", name);
        fflush(myout);
        exit(EXIT_FAILURE);
    }
    get_todays_date();
    write_the_signatures(sigfile, 
        "EXPORT: Increments ", write_incremental_signature_line);
    fclose(sigfile);
    return;
}

/*
 * Here previous is a list of files as read from xport.chk, representing
 * the state of affairs some time ago. current is a list just created
 * and showing exactly what is on disc now. This function scans these
 * two lists and sets the ->newp field in records in current, explaining
 * what (if anything) is different about them. They can have changed
 * binary/text status, altered their contents or be newly created. This
 * code does not record cases where a file used to exist (in previous)
 * but does not now.
 */

void collect_differences()
{
    list_of_files *p = previous, *c = current;
    while (p && c)
    {   char *pn = p->unixname, *cn = c->unixname;
        if (strcmp(pn, cn) == 0)
        {   if (p->binaryp != c->binaryp) c->newp |= NEW_BINMODE;
            else if (p->checksum != c->checksum) c->newp |= NEW_CHANGED;
            p = p->next;
            c = c->next;
            continue;
        }
        if (nameorder(pn, cn)) p = p->next;
        else
        {   c->newp |= NEW_NEW;
            c = c->next;
        }
    }
    while (c)
    {   c->newp |= NEW_NEW;
        c = c->next;
    }
}


static void make_backup(char *name)
{
    char name_old[LONGEST_LEGAL_FILENAME];
    sprintf(name_old, "%s.old", name);
    remove(name_old);  /* Dispose of any previous backup */
    rename(name, name_old);
/*
 * I used to moan if the rename failed. But these days I realise that
 * if a whole directory is discarded than the directory itself will be
 * renames as xxx.old (say) early on, and after that the individual
 * files within it will no longer be findable (ha ha). The effect is that they
 * get left with their existing names because the above rename operation
 * fails to work. However this apparent bug or oddity actually appears to
 * be the overall behaviour that feels nicest!
 *
 *  if (rename(name, name_old))
 *      fprintf(myout, "rename(%s,%s) failed\n", name, name_old);
 */
}

int web_fetch(list_of_files *p, list_of_files *c, int force, int stampflag)
{
/*
 * Here p is information from the downloaded xport.chk, while c
 * was obtained by scanning the local disc. The two records will both
 * refer to the same file-name, but I pass down the two of them here because
 * that way I get access to both date-stamps.
 */
    char url[LONGEST_LEGAL_FILENAME];
    char line[50];
    socket_file *src;
    FILE *dest;
    int i, ch, found;
    unsigned32 old_checksum, save_CRC;
    char old_date[16];
    if (c!=NULL && c->newp != 0 && c->dirp==0)
    {   fprintf(myout, "File \"%s\" seems to have been changed locally\n",
               c->filename);
        fflush(myout);
    }
    if (p->dirp)
    {   Cmkdir(p->filename);
        return 1;
    }
    sprintf(url, "%s/%s", master_url, p->unixname);
    if (!quietflag) 
    {   fprintf(myout, "+++ Fetching %sfrom %s for %s\n",
                p->binaryp ? "(binary) " : "", url, p->filename);
        fflush(myout);
    }
    src = xopen_url(url, p->binaryp);  /* @@@ or encrypted? */
    if (src == NULL)
    {   fprintf(myout, "Unable to access \"%s\"\n", url);
        if (force)
        {   fprintf(myout, "\"%s\" not available but -force flag given\n",
                           url);
            fflush(myout);
            return 1;
        }
        fflush(myout);
        return 0;
    }
    dest = fopen("xport.tmp", p->binaryp ? "wb" : "w"); /* p->filename */
    if (dest == NULL)
    {   fprintf(myout, "failed to access \"xport.tmp\"\n");
        if (src != NULL) close_socket(src);
        if (force)
        {   fprintf(myout, "-force flag given so continuing\n");
            fflush(myout);
            return 1;
        }
        fflush(myout);
        return 0;
    }
    CRC = save_CRC = 1;
    i = found = 0;
    while ((ch = char_from_data(src)) != EOF)
    {   if (p->binaryp ||
            (ch & 0xff) != '\r') update_CRC(ch & 0xff);
/*
 * There is some mildly amazing complication here because the checksums
 * that I compute are not really whole-file checksums. They omit
 * the first instance of a line that agrees with my idea of a file
 * signature. This is so that I can update the date-stamp on a file
 * without having to worry too much about the checksum, and also to make
 * the code in the file-signature-updater easier. What I put here must
 * match the code I have in my "filesign" and "checksum" utilities as
 * well as the corresponding version elsewhere in this file.
 */
        if (!found && !p->binaryp && ch == '\n')
        {   line[i] = 0;
            if (i == 37 &&
                sscanf(line, "/* Signature: %x %11s */",
                       &old_checksum, old_date) == 2)
                found = 1, CRC = save_CRC;
            save_CRC = CRC;
            i = 0;
        }
        else if (i < 40 && ch != '\r') line[i++] = ch;
        putc(ch, dest);
    }
    fclose(dest);
    if (src != NULL) close_socket(src);
    if (CRC != p->checksum)
    {   if (force)
        {   fprintf(myout,
    "Checksum for file as fetched was %.8x while master site said %.8x,\n",
                   CRC, p->checksum);
            fprintf(myout,
    "but \"-force\" option used, so accepting the fetched file anyway.\n");
        }
        else
        {   fprintf(myout,
    "Checksum of file as fetched was %.8x while the master site\n", CRC);
            fprintf(myout,
    "had the value %.8x reported. Either the index file at the\n",
         p->checksum);
            fprintf(myout,
    "master site needs updating or data was corrupted during\n");
            fprintf(myout,
    "the transfer.\n");
            fprintf(myout,
    "Your existing version of the file will be left undisturbed\n");
            fprintf(myout,
    "and the fetched version will be in \"xport.tmp\".\n");
            return 0;
        }
        fflush(myout);
    }
/*
 * I arrange that updating a file can NEVER move its timestamp
 * backwards in time. If I was about to move a timestamp backwards then
 * instead I move it to "now".
 */
    {   unsigned32 tfile = p->datestamp;
        if (stampflag || (c != NULL && c->datestamp > tfile))
        {   time_t tnow = time(NULL);
            struct tm *st = localtime(&tnow);
            tfile = pack_date(st->tm_year, st->tm_mon, st->tm_mday,
                              st->tm_hour, st->tm_min, st->tm_sec);
        }
        set_filedate("xport.tmp", tfile, 
            (p->execp || p->dirp) ? 0755 : 0644);
    }
/*
 * If a file with the given name already exists I will (ALWAYS now)
 * move it across from a name xxx to one xxx.old
 * The view is that the extra disc space consumed by these backup copies
 * is not too important these days and the extra security is a good thing.
 */
    if (c!=NULL && c->dirp==0) make_backup(c->filename);
    remove(p->filename);
    if (rename("xport.tmp", p->filename))
    {   fprintf(myout,
                "Failed to rename \"xport.tmp\" as \"%s\"\n", p->filename);
        if (force)
        {   fprintf(myout, "-force flag given so continuing\n");
            fflush(myout);
            return 1;
        }
        fflush(myout);
        return 0;
    }
    return 1;
}

void remove_local(list_of_files *c)
{
    char oldname[LONGEST_LEGAL_FILENAME];
    if (nodeleteflag) return;
    sprintf(oldname, "%s.old", c->filename);
    if (!quietflag)
    {   fprintf(myout, "Existing version will be saved as \"%s\"\n", oldname);
        fflush(myout);
    }
    remove(oldname);  /* Dispose of any previous backup */
    if (rename(c->filename, oldname))
    {   fprintf(myout, "rename(%s,%s) failed\n", c->filename, oldname);
        fflush(myout);
    }
}

#define XPORT_CHK_FOUND 1       /* Old xport.chk was present */
#define XPORT_TM1_FETCHED 2     /* Had to fetch xport.chk from remote site */
#define XPORT_TM2_FETCHED 4     /* Found xport.inc on remote site */

/*
 * This brings files up to date. If an update to the file "xport.pat" is
 * called for I will JUST fetch than and then return 1. Otherwise I return 0.
 */
int correct_differences(int force, int flags, int stampflag)
{
    int failed = 0, updated_count = 0;
    list_of_files *p = previous, *c = current;
    while (p && strcmp(p->unixname, "xport.pat")!=0) p=p->next;
    while (c && strcmp(c->unixname, "xport.pat")!=0) c=c->next;
    if (p && (c==NULL || p->checksum!=c->checksum))
    {   fprintf(myout, "Fetching new xport.pat\n");
        if (!web_fetch(p, c, force, stampflag)) failed = 1;
        else return 1;
    }
    p = previous;
    c = current;
    while (p && c)
    {   char *pn = p->unixname, *cn = c->unixname;
        if (strcmp(pn, cn) == 0)
        {   if (p->binaryp != c->binaryp)
            {   if (!quietflag)
                    fprintf(myout,
                       "Binary/text status changed for %s (now %s)\n", cn,
                       p->binaryp ? "binary" : "text");
                if (!web_fetch(p, c, force, stampflag))
                {   failed = 1;
                    break;
                }
                fflush(myout);
                updated_count++;
            }
            else if (p->checksum != c->checksum)
            {   fprintf(myout, "Changed %s\n", cn);
                if (!web_fetch(p, c, force, stampflag))
                {   failed = 1;
                    break;
                }
                fflush(myout);
                updated_count++;
            }
            p = p->next;
            c = c->next;
            continue;
        }
        if (nameorder(pn, cn))
        {   fprintf(myout, "Creating %s\n", pn);
            fflush(myout);
            if (!web_fetch(p, NULL, force, stampflag))
            {   failed = 1;
                break;
            }
            updated_count++;
            p = p->next;
        }
        else
        {   fprintf(myout, "Unwanted %s\n", cn);
            fflush(myout);
            remove_local(c);
            c = c->next;
        }
    }
    while (!failed && p)
    {   fprintf(myout, "Creating %s\n", p->unixname);
        fflush(myout);
        if (!web_fetch(p, NULL, force, stampflag))
        {   failed = 1;
            break;
        }
        updated_count++;
        p = p->next;
    }
    while (!failed && c)
    {   fprintf(myout, "Unwanted %s\n", c->unixname);
        fflush(myout);
        remove_local(c);
        c = c->next;
    }
    if (failed) return 0;
    if (flags & XPORT_TM1_FETCHED)
    {   remove("xport.chk");
        if (rename("xport.tm1", "xport.chk"))
        {   fprintf(myout, "rename xport.tm1 as xport.chk please\n");
            fflush(myout);
        }
    }
    if (flags & XPORT_TM2_FETCHED)
    {   remove("xport.inc");
        if (rename("xport.tm2", "xport.inc"))
        {   fprintf(myout, "rename xport.tm2 as xport.inc please\n");
            fflush(myout);
        }
    }
/*
 *  if (!quietflag)
 */
    {
        switch (updated_count)
        {
    case 0: fprintf(myout, "No files needed updating\n");        break;
    case 1: fprintf(myout, "1 file updated\n");                  break;
    default:fprintf(myout, "%d files updated\n", updated_count); break;
        }
        fflush(myout);
    }
    return 0;
}

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

static void remove_old_files()
{
    list_of_files *p=oldfiles, *q = NULL;
/*
 * I reverse the list so that directories will be removed AFTER all the files
 * in them are.
 */
    while (p!=NULL)
    {   list_of_files *r = p->next;
        p->next = q;
        q = p;
        p = r;
    }
    for (p=q; p!=NULL; p=p->next)
    {   fprintf(myout, "Removing \"%s\"\n", p->filename);
        fflush(myout);
/*
 * for most systems (?) I will have an rmdir() function...
 */
        if (p->dirp)
            rmdir(p->filename);
        else remove(p->filename);
    }
}

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

static void usage(void)
{
    fprintf(myout,
"Usage:  xport -key [file [directory]]\n");
    fprintf(myout,
"  keys:    -sign     create signature file\n");
    fprintf(myout,
"           -increment/-inc  differential signature\n");
    fprintf(myout,
"           -diff     differential sig to alternative place\n");
    fprintf(myout,
"           -check    check against signature file\n");
    fprintf(myout,
"           -fetch    update this directory from reference site\n");
    fprintf(myout,
"           -fetch=tag, -report=tag  specify alternate site\n");
    fprintf(myout,
"           -force..  as -fetch but continues after errors\n");
    fprintf(myout,
"           -report   like -fetch, but just gives messages\n");
    fprintf(myout,
"           -tidy     delete all *.old files\n");
    fprintf(myout,
"           -get URL dest   fetch from given URL to a local file\n");
    fprintf(myout,
"           -bget URL dest  fetch from given URL in binary mode\n");
    fprintf(myout,
"           -quiet [other options]    be less noisy\n");
    fprintf(myout,
"           -noisy [other options]    be more noisy\n");
    fprintf(myout,
"           -nodelete [other options] do not remove local junk\n");
    fprintf(myout,
"           -version        display a version number\n");
    fflush(myout);
}


static FILE *fopen1(char *dir, char *name, char *mode)
{
    char filename[LONGEST_LEGAL_FILENAME];
    if (dir == NULL) strcpy(filename, name);
    else sprintf(filename, "%s%c%s", dir, DIRECTORY_CHAR, name);
    return fopen(filename, mode);
}

/*
 * When I use scp to send a file I need to worry about CRLF vs NL issues
 * for text files!
 */

static void scp_send(char *sshdir, char *local, char *site, char *remote_name)
{
    char b[LONGEST_LEGAL_FILENAME];
    if (sshdir == NULL)
        sprintf(b, "scp -q %s %s/%s", local, site, remote_name);
    else sprintf(b, "%s%cscp -q -S %s%cssh %s %s/%s",
        sshdir, DIRECTORY_CHAR, sshdir, DIRECTORY_CHAR,
        local, site, remote_name);
    system(b);
}

static char *remove_CRLF(char *local)
{
    FILE *from = fopen(local, "r");
    char *name = "xport.ssh";
    FILE *to = fopen(name, "wb");
    int c;
    while ((c = getc(from)) != EOF && (c & 0x1f) != 'Z')
        if (c != '\r') putc(c, to);
    fclose(from);
    fclose(to);
    return name;
}

static char *add_CRLF(char *local)
{
    FILE *from = fopen(local, "r");
    char *name = "xport.ssh";
    FILE *to = fopen(name, "w");
    int c;
    while ((c = getc(from)) != EOF && (c & 0x1f) != 'Z')
    {   if (c == '\r') continue;
        if (c == '\n') putc('\r', to);
        putc(c, to);
    }
    fclose(from);
    fclose(to);
    return name;
}

static void scp_send_ascii(char *sshdir, char *local, char *site, 
                           char *remote_name, int remote_is_windows)
{
    char b[LONGEST_LEGAL_FILENAME];
    if (!remote_is_windows) local = remove_CRLF(local);
    else local = add_CRLF(local);
    if (sshdir == NULL)
        sprintf(b, "scp -q %s %s/%s", local, site, remote_name);
    else sprintf(b, "%s%cscp -q -S %s%cssh %s %s/%s",
        sshdir, DIRECTORY_CHAR, sshdir, DIRECTORY_CHAR,
        local, site, remote_name);
    system(b);
}

static void scp_fetch(char *sshdir, char *site, char *remote, char *local)
{
    char b[LONGEST_LEGAL_FILENAME];
    if (sshdir == NULL)
        sprintf(b, "scp -q %s/%s %s", site, remote, local);
    else sprintf(b, "%s%cscp -q -S %s%cssh %s/%s %s",
        sshdir, DIRECTORY_CHAR, sshdir, DIRECTORY_CHAR, site, remote, local);
    system(b);
}

static void ssh_delete(char *sshdir, char *sendto, char *remote)
{
/*
 * Right at the moment this assumes that the remote machine is Unix-like
 */
    char user[LONGEST_LEGAL_FILENAME],
         host[LONGEST_LEGAL_FILENAME],
         directory[LONGEST_LEGAL_FILENAME],
         b[LONGEST_LEGAL_FILENAME];
    int p = 0;
    strcpy(user, sendto);
    while (sendto[p] != 0 && sendto[p] != '@') p++;
    user[p] = 0;
    if (sendto[p] == 0)
    {   fprintf(myout, "Need user@host:dir with \"-send\"\n");
        exit(EXIT_FAILURE);
    }
    sendto += p+1;
    strcpy(host, sendto);
    while (sendto[p] != 0 && sendto[p] != ':') p++;
    host[p] = 0;
    if (sendto[p] == 0)
    {   fprintf(myout, "Need user@host:dir with \"-send\"\n");
        exit(EXIT_FAILURE);
    }
    sendto += p+1;
    strcpy(directory, sendto);
    if (sshdir == NULL)
        sprintf(b, "ssh -l %s %s cp %s/%s %s/%s.old", user, host,
                directory, remote, directory, remote);
    else sprintf(b, "%s%cssh -l %s %s cp %s/%s %s/%s.old",
        sshdir, DIRECTORY_CHAR, user, host,
        directory, remote, directory, remote);
    fprintf(myout, "OBEY %s\n", b);
    fflush(myout);
    system(b);
    if (sshdir == NULL)
        sprintf(b, "ssh -l %s %s rm %s/%s", user, host, directory, remote);
    else sprintf(b, "%s%cssh -l %s %s rm %s/%s",
        sshdir, DIRECTORY_CHAR, user, host, directory, remote);
    fprintf(myout, "OBEY %s\n", b);
    fflush(myout);
    system(b);
}

static void ssh_obey_xport(char *sshdir, char *remote_xport, char *sendto)
/* 
 *  "[?sshdir]ssh host -l user [?remote_xport/xport] -check=dir \
 *                     -list -to dir/xport.tmp"
 * where sendto is of the form
 *     user@host:dir
 */
{
    char user[LONGEST_LEGAL_FILENAME],
         host[LONGEST_LEGAL_FILENAME],
         directory[LONGEST_LEGAL_FILENAME],
         b[LONGEST_LEGAL_FILENAME];
    int p = 0;
    strcpy(user, sendto);
    while (sendto[p] != 0 && sendto[p] != '@') p++;
    user[p] = 0;
    if (sendto[p] == 0)
    {   fprintf(myout, "Need user@host:dir with \"-send\"\n");
        exit(EXIT_FAILURE);
    }
    sendto += p+1;
    strcpy(host, sendto);
    while (sendto[p] != 0 && sendto[p] != ':') p++;
    host[p] = 0;
    if (sendto[p] == 0)
    {   fprintf(myout, "Need user@host:dir with \"-send\"\n");
        exit(EXIT_FAILURE);
    }
    sendto += p+1;
    strcpy(directory, sendto);
    p = 0;
    if (sshdir != NULL) p += sprintf(&b[p], "%s%c", sshdir, DIRECTORY_CHAR);
    p += sprintf(&b[p], "ssh %s -l %s ", host, user);
    if (remote_xport != NULL)
        p += sprintf(&b[p], "%s", remote_xport);
    else p += sprintf(&b[p], "xport");
    p += sprintf(&b[p], " -check %s -list -to %s/xport.tmp",
                 directory, directory);
/*  fprintf(myout, "Command: %s\n", b); */
    system(b);
}

static int read_line(FILE *f, char *b)
{
    int p = 0, c;
    while ((c = getc(f)) != '\n' && c != EOF)
    {   if (c != '\r' && p < LONGEST_LEGAL_FILENAME-1) b[p++] = c;
    }
    b[p] = 0;
    return (c == EOF);
}

#define ACT_AUTH          0
#define ACT_BGET          1
#define ACT_CHECK         2
#define ACT_DIFF          3
#define ACT_FETCH         4
#define ACT_FORCE         5
#define ACT_GET           6
#define ACT_HOSTCASE      7
#define ACT_INC           8
#define ACT_INCREMENT     9
#define ACT_LIST          10
#define ACT_NODELETE      11
#define ACT_NOISY         12
#define ACT_NOHOSTCASE    13
#define ACT_QUIET         14
#define ACT_REPORT        15
#define ACT_SEND          16
#define ACT_SIGN          17
#define ACT_SSHDIR        18
#define ACT_STAMP         19
#define ACT_TIDY          20
#define ACT_TO            21
#define ACT_REMOTE_XPORT  22
#define ACT_USER          23
#define ACT_VERSION       24
#define ACT_count         25

typedef struct keyrecord
{
    char *name;
    int present;
    char *value;
    char *value2;
    int value_needed;
} keyrecord;

static keyrecord keywords[] =
{
    {"auth",         0, NULL, NULL, 1},
    {"bget",         0, NULL, NULL, 1},
    {"check",        0, NULL, NULL, 0},
    {"diff",         0, NULL, NULL, 1},
    {"fetch",        0, NULL, NULL, 0},
    {"force",        0, NULL, NULL, 0},
    {"get",          0, NULL, NULL, 1},
    {"hostcase",     0, NULL, NULL, 0},
    {"inc",          0, NULL, NULL, 0},
    {"increment",    0, NULL, NULL, 0},
    {"list",         0, NULL, NULL, 0},
    {"nodelete",     0, NULL, NULL, 0},
    {"noisy",        0, NULL, NULL, 0},
    {"nohostcase",   0, NULL, NULL, 0},
    {"quiet",        0, NULL, NULL, 0},
    {"report",       0, NULL, NULL, 0},
    {"send",         0, NULL, NULL, 1},
    {"sign",         0, NULL, NULL, 0},
    {"sshdir",       0, NULL, NULL, 1},
    {"stamp",        0, NULL, NULL, 0},
    {"tidy",         0, NULL, NULL, 0},
    {"to",           0, NULL, NULL, 1},
    {"remote-xport", 0, NULL, NULL, 1},
    {"user",         0, NULL, NULL, 1},
    {"version",      0, NULL, NULL, 0},
    {"*dummy*",      0, NULL, NULL, 0}
};


int decode_arguments(int argc, char *argv[])
{
    int i, valuefound;
    for (i=0; i<ACT_count; i++)
    {   keywords[i].present = 0;
        keywords[i].value = NULL;
        keywords[i].value2 = NULL;
    }
    for (i=1; i<argc; i++)
    {   char *arg = argv[i];
        int j, len;
/*
 * I will recognize either xxx or -xxx or --xxx as a keyword!
 */
        if (arg[0] == '-') arg++;
        if (arg[0] == '-') arg++;
        for (j=0; j<ACT_count; j++)
        {   len = strlen(keywords[j].name);
            if (strncmp(arg, keywords[j].name, len) == 0) break;
        }
        if (j>=ACT_count) return 0; /* keyword not recognized */
        keywords[j].present = 1;
        valuefound = 0;
        if (arg[len] == '=') /* "xxx=yyy" form */
        {   keywords[j].value = arg+len+1;
            valuefound = 1;
            if (i<(argc-1) &&
                argv[i+1][0] != '-')
                keywords[j].value2 = argv[++i];
        }
/*
 * "-keyword value" sets a value provided the item in the value position
 * does not start with "-".
 * Furthermore "-keyword value1 value2" sets two values, again provided
 * neither start with "-".
 */
        else if (i<(argc-1) &&
                 argv[i+1][0] != '-')
        {   keywords[j].value = argv[++i];
            valuefound = 1;
            if (i<(argc-1) &&
                argv[i+1][0] != '-')
                keywords[j].value2 = argv[++i];
        }
        if (keywords[j].value_needed && !valuefound)
        {   fprintf(stderr, "-%s needs an argument. Ignoring it here\n",
                            keywords[j].name);
            keywords[j].present = 0;
        }
    }
    return 1;
}


int main(int argc, char *argv[])
{
    char *w, *auth, *checkdir, *sshdir, *remote_xport, *key1, *key2;
    int action, flags = 0, stampflag = 0,
        forcehostcase = 0, forcenohostcase = 0,
        listflag = 0;

    myout = stdout;  /* For really early error messages */
    if (!decode_arguments(argc, argv))
    {   usage();
        exit(EXIT_FAILURE);
    }
    if (keywords[ACT_VERSION].present)
    {   fprintf(myout, "xport version %s\n", VERSION_STRING);
        exit(EXIT_SUCCESS);
    }

    if (!keywords[ACT_TO].present ||
        (w = keywords[ACT_TO].value) == NULL) myout = stdout;
    else
    {   myout = fopen(w, "w");
        if (myout == NULL)
        {   myout = stdout;
            fprintf(myout, "Unable to access %s\n", w);
            fflush(myout);
        }
    }

    if (!keywords[ACT_AUTH].present ||
        (auth = keywords[ACT_AUTH].value) == NULL)
    {   auth = getenv("XPORT_AUTH");
/* Well - permit lower case as well... */
        if (auth == NULL) auth = getenv("xport_auth");
    }

    if (keywords[ACT_USER].present) set_suser(keywords[ACT_USER].value);

    if (keywords[ACT_CHECK].present)
        checkdir = keywords[ACT_CHECK].value;
    else checkdir = NULL;

    if (keywords[ACT_SSHDIR].present)
        sshdir = keywords[ACT_SSHDIR].value;
    else sshdir = NULL;

    if (keywords[ACT_REMOTE_XPORT].present)
        remote_xport = keywords[ACT_REMOTE_XPORT].value;
    else remote_xport = NULL;

    forcehostcase = keywords[ACT_HOSTCASE].present;
    forcenohostcase = keywords[ACT_NOHOSTCASE].present;
    stampflag = keywords[ACT_STAMP].present;
    nodeleteflag = keywords[ACT_NODELETE].present;
    quietflag = keywords[ACT_QUIET].present;
    noisyflag = keywords[ACT_NOISY].present;
    listflag = keywords[ACT_LIST].present;
    if (listflag) quietflag = 1;

/*
 * Now identify keywords that ask for primary action. If the user has
 * been silly enough to use several of these then the first one present
 * in this list will take priority.
 */
         if (keywords[ACT_BGET].present)       action = ACT_BGET;
    else if (keywords[ACT_CHECK].present)      action = ACT_CHECK;
    else if (keywords[ACT_DIFF].present)       action = ACT_DIFF;
    else if (keywords[ACT_FETCH].present)      action = ACT_FETCH;
    else if (keywords[ACT_FORCE].present)      action = ACT_FORCE;
    else if (keywords[ACT_GET].present)        action = ACT_GET;
    else if (keywords[ACT_INC].present)        action = ACT_INC;
    else if (keywords[ACT_INCREMENT].present)  action = ACT_INCREMENT;
    else if (keywords[ACT_REPORT].present)     action = ACT_REPORT;
    else if (keywords[ACT_SEND].present)       action = ACT_SEND;
    else if (keywords[ACT_SIGN].present)       action = ACT_SIGN;
    else if (keywords[ACT_TIDY].present)       action = ACT_TIDY;
    else
    {   usage();
        exit(EXIT_FAILURE);
    }

    key1 = keywords[action].value;
    key2 = keywords[action].value2;

    if (auth == NULL)
    {   auth_user[0] = auth_password[0] = 0;
    }
    else
    {   char *p = auth, *q = auth_user;
        int n = 0;
        while (*p != 0 && *p != ':')
        {   if (n < sizeof(auth_user)-1) *q++ = *p++;
            n++;
        }
        *q = 0;
        if (*p == ':') p++;
        q = auth_password;
        while (*p != 0 && *p != ':')
        {   if (n < sizeof(auth_password)-1) *q++ = *p++;
            n++;
        }
        *q = 0;
        *q = 0;
    }


/*
 * xport -GET url [dest]
 *    does not want directories scanned etc, so I detect that case
 *    up front.
 */
    if (action == ACT_GET || action == ACT_BGET)
    {   socket_file *f;
        int c;
        FILE *dest;
        if (key1 == NULL)
        {   fprintf(myout, "\"xport -get\" needs to be told what to fetch\n");
            fflush(myout);
            finished_with_sockets();
            return EXIT_FAILURE;
        }
        flags = (action == ACT_BGET); /* binary mode fetch */
        if ((f = xopen_url(key1, flags)) == NULL)
        {   fprintf(myout, "Unable to access \"%s\"\n", key1);
            fflush(myout);
            finished_with_sockets();
            return EXIT_FAILURE;
        }
        if (key2 == NULL) dest = NULL;
        else if ((dest = fopen(key2, flags ? "wb" : "w")) == NULL)
        {   fprintf(myout, "Failed to open \"%s\" for writing\n", key2);
            fflush(myout);
            finished_with_sockets();
            return EXIT_FAILURE;
        }
        while ((c = char_from_data(f)) != EOF)
        {   if (flags || (c & 0xff) != '\r') update_CRC(c & 0xff);
            if (dest == NULL) putchar(c);
            else putc(c, dest);
        }
        if (dest != NULL) fclose(dest);
        if (f != NULL) close_socket(f);
        finished_with_sockets();
        return EXIT_SUCCESS;
    }
/*
 * "-send" is very special too...
 */
    if (action == ACT_SEND)
    {   char b[LONGEST_LEGAL_FILENAME];
        FILE *f;
        int remote_is_windows;
        char *sendto = keywords[ACT_SEND].value;
        if (sendto == NULL)
        {   fprintf(myout, "-send needs a destination\n");
            fflush(myout);
            exit(EXIT_FAILURE);
        }
/*
 * I have arranged that this program does not mind if the following 3 files
 * have extra '\r' chars in or not so I will send them in binary mode
 * regardless of Windows/Unix combinations involved.
 */
        scp_send(sshdir, "xport.pat", sendto, "xport.pat");
        scp_send(sshdir, "xport.chk", sendto, "xport.chk");
        scp_send(sshdir, "xport.inc", sendto, "xport.inc");
        ssh_obey_xport(sshdir, remote_xport, sendto);
        scp_fetch(sshdir, sendto, "xport.tmp", "xport.tmp");
        f = fopen("xport.tmp", "r");
/*
 * Here I am going to be idle about checking for error conditions. Ideally
 * I will come back and fix that later. However I can argue that "xport" can
 * provide an overall end-to-end checking protocol so disasters during one
 * run of it are maybe benign!
 */
        if (read_line(f, b))
        {   fprintf(myout, "Empty file recovered from remote machine\n");
            fflush(myout);
            return EXIT_FAILURE;
        }
        remote_is_windows = (b[0] == 'W');
        while (!read_line(f, b))
        {   switch (b[0])
            {
        default:fprintf(myout, "Unexpected line <%s>\n", b);
                fflush(myout);
                return EXIT_FAILURE;
        case 'A':
                fprintf(myout, "Send %s as a text file\n", b+1);
                fflush(myout);
                scp_send_ascii(sshdir, b+1, sendto, b+1, remote_is_windows);
                break;
        case 'B':
                fprintf(myout, "Send %s as a binary file\n", b+1);
                fflush(myout);
                scp_send(sshdir, b+1, sendto, b+1);
                break;
        case 'D':
                fprintf(myout, "Delete file %s\n", b+1);
                fflush(myout);
                ssh_delete(sshdir, sendto, b+1);
                break;
            }
        }
        fclose(f);
        return EXIT_SUCCESS;
    }
/*
 * All other behaviours do a few things right at the start...
 */
    read_patterns_file(checkdir, key1);
    if (forcehostcase) hostcase = 1;
    if (forcenohostcase) hostcase = 0;
    set_hostcase(hostcase);  /* for benefit of scan_directory */
    if (!hostcase) 
    {   fprintf(myout, "NB file-names will be case-folded\n");
        fflush(myout);
    }
    find_existing_files(checkdir);

    switch (action)
    {
case ACT_SIGN:
        compute_checksums(checkdir, current);
        make_signature_file();
        remove("xport.tm1");
        remove("xport.tm2");
        return EXIT_SUCCESS;
case ACT_INC:
case ACT_INCREMENT:
        compute_checksums(checkdir, current);
        if (!read_list_of_files(checkdir, "xport.chk", NULL))
            return EXIT_FAILURE;
        write_increments("xport.inc");
        remove("xport.tm1");
        remove("xport.tm2");
        return EXIT_SUCCESS;
case ACT_DIFF:
        compute_checksums(checkdir, current);
        if (!read_list_of_files(checkdir, "xport.chk", NULL))
            return EXIT_FAILURE;
        write_increments("xport.dif");
        remove("xport.tm1");
        remove("xport.tm2");
        return EXIT_SUCCESS;
default:
case ACT_CHECK:
        compute_checksums(checkdir, current);
        if (!read_list_of_files(checkdir, "xport.chk", "xport.inc"))
            return EXIT_FAILURE;
        if (listflag) report_differences(1, listflag);
        else
        {   FILE *f = fopen1(checkdir, "xport.tm1", "r");
            if (f != NULL)
            {   fclose(f);
                collect_differences();
                if (!read_list_of_files(checkdir, "xport.tm1", "xport.tm2"))
                    return EXIT_FAILURE;
                report_differences(0, listflag);
            }
            else report_differences(1, listflag);
        }
        return EXIT_SUCCESS;
case ACT_REPORT:
case ACT_FETCH:
case ACT_FORCE:
        flags = 0;              /* Used to hold info about fetches */
        if (master_url[0] == 0)
        {   fprintf(myout, "No master HTTP/FTP site given in \"xport.pat\"\n");
            fflush(myout);
            return EXIT_FAILURE;
        }
        compute_checksums(checkdir, current);
        if (read_list_of_files(checkdir, "xport.chk", "xport.inc"))
        {   collect_differences();
            flags |= XPORT_CHK_FOUND;
        }
        ssh_ensure_sockets_ready(sshdir);
        switch (fetch_list_of_new_files("xport.inc", "xport.tm2"))
        {
    case FETCH_NEW_OK:
            {   FILE *f = fopen("xport.tm2", "r");
                char headline[80];
                int i, ch;
                if (f == NULL)
                {   fprintf(myout, "xport.inc not fetched properly\n");
                    fflush(myout);
                    if (action != ACT_REPORT)
                    {   fprintf(myout, "No files updated\n");
                        fflush(myout);
                    }
                    return EXIT_FAILURE;
                }
                while ((ch = getc(f)) != EOF && ch != '\n');
                i = 0;
                headline[0] = 0;
                if (ch != EOF)
                    while (i < 72 && (ch = getc(f)) != EOF &&
                           ch != '\n')
                        if (ch != '\r' && ch != '\f') headline[i++] = ch;
                headline[i++] = '\n';
                headline[i] = 0;
                fclose(f);
                if (memcmp(headline, "Base \"xport.chk\":  ", 19) != 0)
                {   fprintf(myout,
                            "Fetched version of xport.inc is corrupt\n");
                    if (action != ACT_REPORT)
                        fprintf(myout, "No files updated\n");
                    fflush(myout);
                    return EXIT_FAILURE;
                }
                memcpy(headline, "EXPORT: Signatures ", 19);
                if (memcmp(headline, check_header, 55) != 0)
                {   if (!quietflag)
                    {   fprintf(myout,
                                "Need to fetch baseline \"xport.chk\"\n");
                        fflush(myout);
                    }
                    if (fetch_list_of_new_files("xport.chk", "xport.tm1") !=
                        FETCH_NEW_OK)
                    {   finished_with_sockets();
                        if (action != ACT_REPORT)
                            fprintf(myout, "No files updated\n");
                        fflush(myout);
                        return EXIT_FAILURE;
                    }
                    flags |= XPORT_TM1_FETCHED;
                }
                flags |= XPORT_TM2_FETCHED;
                break;
            }
    case FETCH_NEW_NONE:
/*
 * If the remote site does not have an "xport.inc" then I will just fetch the
 * "xport.chk" from there and suppose that it is fully up to date.
 */
            if (fetch_list_of_new_files("xport.chk", "xport.tm1") !=
                FETCH_NEW_OK)
            {   finished_with_sockets();
                if (action != ACT_REPORT) fprintf(myout, "No files updated\n");
                fflush(myout);
                return EXIT_FAILURE;
            }
            flags |= XPORT_TM1_FETCHED;
            break;
    case FETCH_NEW_FAIL:
            finished_with_sockets();
            if (action != ACT_REPORT) fprintf(myout, "No files updated\n");
            fflush(myout);
            return EXIT_FAILURE;
        }
        if (!read_list_of_files(
                 checkdir,
                 flags & XPORT_TM1_FETCHED ? "xport.tm1" : "xport.chk",
                 flags & XPORT_TM2_FETCHED ? "xport.tm2" : NULL))
        {   if (action != ACT_REPORT) fprintf(myout, "No files updated\n");
            fflush(myout);
            return EXIT_FAILURE;
        }
        if (action == ACT_REPORT) report_differences(0, listflag);
        else 
        {
/*
 * There is an astonishing-liiking recursion on main() here. This is so that
 * if currect_differences fetches a new "xport.pat" I can restart.
 */
            if (correct_differences(action==ACT_FORCE, flags, stampflag))
                return main(argc, argv);
        }
        finished_with_sockets();
        return EXIT_SUCCESS;
case ACT_TIDY:
        remove_old_files();
        return EXIT_SUCCESS;
    }
}

/* end of xport.c */
