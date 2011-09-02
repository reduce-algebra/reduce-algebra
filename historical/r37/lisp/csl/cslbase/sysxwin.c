/*  sysxwin.c                       Copyright (C) 1993-2003 Codemist Ltd */

/*
 * General Unix/X/StdWin system-specific code. Not currently
 * tested or working, but possibly valuable as a skeleton or
 * framework.
 */

/*
 * This code may be used and modified, and redistributed in binary
 * or source form, subject to the "CCL Public License", which should
 * accompany it. This license is a variant on the BSD license, and thus
 * permits use of code derived from this in either open and commercial
 * projects: but it does require that updates to this code be made
 * available back to the originators of the package.
 * Before merging other code in with this or linking this code
 * with other packages or libraries please check that the license terms
 * of the other material are compatible with those of this.
 */


/* Signature: 061156c6 13-Jul-2003 */

#include "machine.h"

#ifndef NO_UNISTD_AVAILABLE
/*
 * Posix mandates a header <unistd.h>, which is why I feel entitled to
 * include it here. But for systems that do not I can assert
 * NO_UNISTD_AVAILABLE in machine.h and worry about other ways to
 * reference the relevant facilities...
 */
#include <unistd.h>
#endif
     
#ifdef __hpux
/*
 * Get the regular headers to define a few more things...
 */
#define _SYSCALL_INCLUDED
#endif
      
       
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

#include "tags.h"
#include "externs.h"
#include "sys.h"

#ifdef TIMEOUT
#include "timeout.h"
#endif

#include "filename.c"


int change_directory(char *filename, char *old, size_t n)
{
    process_file_name(filename, old, n);
    if (*filename == 0) return 1;
    if (chdir(filename))
    {   char err_buf[LONGEST_LEGAL_FILENAME+100];
        char *msg;
        switch (errno)
        {
    case ENOTDIR:
            msg = "A component of %s is not a directory.";
            break;
    case ENOENT:  
            msg = "The directory %s does not exist.";
            break;
    case EACCES:
            msg = "Insufficient permission for %s.";
            break;
    case ELOOP:
            msg = "Pathname %s has too many symbolic links.";
            break;
    case ENAMETOOLONG:
            msg = "The pathname %s is too long.";
            break;
    default:
            msg = "Cannot change directory to %s.";
            break;
       }
       sprintf(err_buf, msg, filename);
       aerror0(err_buf);
       return 1;
    }
    else return 0;
}

int create_directory(char *filename, char *old, size_t n)
{
    process_file_name(filename, old, n);
    if (*filename == 0) return 1;
    return mkdir(filename, 0x1f8);
}

static void remove_files(char *name, int dirp, long int size)
/* Remove a file, or a directory and all its contents */
{
    if (dirp)
      rmdir(name);
    else
      remove(name);
}

int delete_file(char *filename, char *old, size_t n)
{
    process_file_name(filename, old, n);
    if (*filename == 0) return 0;
    /*
     * We cannot simply use remove here, since this will not
     * work with directories and their contents.  Hence the
     * use of scan_directory.
     */
    scan_directory(filename, remove_files);
    return 0;
}

/*#include <direct.h> */

int get_current_directory(char *s, int n)
{
    if (getcwd(s, n) == 0)
    {   switch(errno)
        {
    case ERANGE:
            aerror0("the pathname of the current directory is too long.");
            break;
    case EACCES:
            aerror0("insufficient permission to get pathname.");
            break;
    default:
            aerror0("cannot get current directory name.");
            break;
        }
        *s = 0;
        return 0;
    }
    else return strlen(s);
}

int directoryp(char *filename, char *old, size_t n)
{
    struct stat buf;
    process_file_name(filename, old, n);
    if (*filename == 0) return 0;
    if (stat(filename,&buf) == -1) return 0;
    return ((buf.st_mode & S_IFMT) == S_IFDIR);
}

char *get_truename(char *filename, char *old, size_t n)
{
    struct stat buf;
    char *temp, *fn, *dir, *pwd;

    process_file_name(filename, old, n);
    if (*filename == 0) aerror("truename");

    /* Find out whether we have a file or a directory */
    if (stat(filename,&buf) == -1) aerror0("truename: cannot stat file");

    /* Store current directory */
/* /*
 * The next line is UNSATISFACTORY because Posix explicitly says (at least in
 * in the copy of 1003.1 that I have) that getcwd has undefined behaviour
 * if its first argument is NULL.
 */
    if ((pwd = (char *)getcwd((char *)NULL, LONGEST_LEGAL_FILENAME)) == NULL)
        aerror0("truename: cannot get current working directory");

    if ((buf.st_mode & S_IFMT) == S_IFDIR)
    {   /* We have a directory */
        char *dir = (char*) (*malloc_hook)(LONGEST_LEGAL_FILENAME);
        if (chdir(filename) != 0) 
            aerror0("truename: cannot change directory");
        if (getcwd(dir,LONGEST_LEGAL_FILENAME) == NULL)
            aerror0("truename: cannot get current working directory");
        if (chdir(pwd) != 0)
            aerror0("truename: cannot change directory");
        (*free_hool)(pwd);
/*
 * Axiom-specific hack: truename preserves '/' at the end of 
 * a path
 */
        if (old[n-1] == '/' && dir[strlen(dir)-1] != '/')
        {   n = strlen(dir);
            dir[n]   = '/';
            dir[n+1] = '\0';
        }
        return dir;
    }
    else
    {   /* Assume we have some kind of file */
        temp = strrchr(filename,'/');
        if (temp) 
        {   /* Found a directory component */
            fn   = strdup(temp);
            *temp = '\0';
            /* fn is now "/file" and filename is the directory */

            if (chdir(filename) != 0)
                aerror0("truename: cannot change directory");
/* /* getcwd(NULL,...) invalid */
            if ((temp = (char *)getcwd((char *)NULL,LONGEST_LEGAL_FILENAME)) == NULL) 
                aerror0("truename: cannot get current working directory");
            if (chdir(pwd) != 0)
                aerror0("truename: cannot change directory");
            dir = (char *)(*malloc_hook)((strlen(temp) + strlen(fn) + 1)*sizeof(char));
/* /*
 * No check for malloc failure...
 */
            strcpy(dir, temp);
            (*free_hool)(temp);
            (*free_hool)(pwd);
            strcat(dir, fn);
            (*free_hool)(fn);
            return dir;
        }
        else
        {   dir = (char *)(*malloc_hook)((strlen(pwd) + strlen(filename) + 2)*sizeof(char));
/* /* No check for malloc failure */
            strcpy(dir,pwd);
            strcat(dir, "/");
            strcat(dir, filename);
            (*free_hool)(pwd);
            return dir;
        }
    }
}


#ifndef DO_NOT_USE_STAT

int file_readable(char *filename, char *old, size_t n)
{
    struct stat buf;
    process_file_name(filename, old, n);
    if (*filename == 0) return 0;
    if (stat(filename,&buf) == -1) 
      return 0; /* File probably does not exist */
    else if (geteuid() == buf.st_uid)
        return (buf.st_mode & S_IRUSR);
    else if (getegid() == buf.st_gid) 
        return (buf.st_mode & S_IRGRP);
    else 
        return (buf.st_mode & S_IROTH);
}


int file_writeable(char *filename, char *old, size_t n)
{ 
    struct stat buf;
    process_file_name(filename, old, n);
    if (*filename == 0) return 0;
    if (stat(filename,&buf) == -1) 
      return 0; /* Should we check to see if the directory is writeable? */
    else if (geteuid() == buf.st_uid)
        return (buf.st_mode & S_IWUSR);
    else if (getegid() == buf.st_gid) 
        return (buf.st_mode & S_IWGRP);
    else 
        return (buf.st_mode & S_IWOTH);
}

#else

int file_readable(char *filename, char *old, size_t n)
{
    FILE *fp;
    process_file_name(filename, old, n);
    if (*filename == 0) return 0;
    /* The "correct" way to do this is via stat, but this is much simpler! */
    fp = fopen(filename,"r");
    if (fp == NULL) return 0;
    else 
    {   fclose(fp);
        return 1;
    }
}

int file_writeable(char *filename, char *old, size_t n)
{
    FILE *fp;
    process_file_name(filename, old, n);
    if (*filename == 0) return 0;
    fp = fopen(filename,"a");
    if (fp == NULL) return 0;
    else 
    {   fclose(fp);
        return 1;
    }
}

#endif

int rename_file(char *from_name, char *from_old, size_t from_size,
                char *to_name, char *to_old, size_t to_size)
{
    process_file_name(from_name, from_old, from_size);
    process_file_name(to_name, to_old, to_size);
    if (*from_name == 0 || *to_name == 0) return 0;
    return rename(from_name,to_name);
}

#ifdef NAG_VERSION

int list_directory_members(char *filename, char *old, char **filelist[],
                           size_t n)
{   struct dirent **namelist;
    int number_of_entries, i;
    char **files;

    process_file_name(filename, old, n);

    /* scandir expects "." for the current directory */
    if (*filename == 0) number_of_entries = scandir(".",&namelist,NULL,NULL);
    else number_of_entries = scandir(filename,&namelist,NULL,NULL);

    /*
     * If the scandir failed then return now, since we make an assumption later
     * that we found at least two entries: "." and "..".
     */
    if (number_of_entries == -1) return -1;

    files=(char **)(*malloc_hook)(number_of_entries*sizeof(char *));

    for (i=0;i<number_of_entries;++i) 
    {   files[i] = strdup(namelist[i]->d_name);
        (*free_hool)(namelist[i]);
    }

    (*free_hool)(namelist);

    *filelist = files;

    /*
     * When we return we will prepend the directory name to the files, so we
     * must make sure it is suitable for that.  This is done here since it is
     * platform dependent (i.e. in DOS we would need to ensure the last
     * character was "\").
     */
    /*
    i=strlen(filename);
    if (i > 0 && filename[i-1] != '/')
    {   filename[i]='/';
        filename[i+1]='\0';
    }
    */

    return number_of_entries;
}

#else

void list_directory_members(char *filename, char *old,
                            size_t n, directory_callback *fn)
{
    process_file_name(filename, old, n);
    scan_files(filename, fn);
}

#endif


CSLbool file_exists(char *filename, char *old, size_t n, char *tt)
/*
 * This returns YES if the file exists, and as a side-effect copies a
 * textual form of the last-changed-time of the file into the buffer tt.
 */
{
    struct stat statbuff;
    process_file_name(filename, old, n);
    if (*filename == 0) return NO;
    if (stat(filename, &statbuff) != 0) return NO;
    strcpy(tt, ctime(&(statbuff.st_mtime)));
    return YES;
}

/*
 * getenv() is a mild pain in two respects - firstly Ultrix uses
 * a non-ANSI definition (using 2 args not 1), and the MSDOS seems
 * to have a strong preference for upper case names.  To allow for
 * all this I do not call getenv() directly but go via the following
 * code that can patch things up.
 */

#ifdef TWO_ARG_GETENV
char *my_getenv(char *s)
{
    static char value[LONGEST_LEGAL_FILENAME];
    getenv(s, value);
    return value;
}
#else
char *my_getenv(char *s)
{
    return getenv(s);
}
#endif

int my_system(char *s)
{
    return system(s);
}

FILE *my_popen(char *a, char *b)
{
#ifdef NCC_LIB
    return NULL;
#else
    return (FILE *)popen(a, b);
#endif
}

void my_pclose(FILE *a)
{
#ifndef NCC_LIB
    pclose(a);
#endif
}

/*
 * I do not expect that the following will work exactly unchanged
 * on all possible versions of Unix - e.g. header file names may need
 * altering and suchlike mess.  But the idea should be reasonable and
 * changes when needed ought to be small.
 */

#ifdef USE_GETUID
/*
 * "machine.h" should set USE_GETUID if that is a good way of doing things.
 * This is NOT made the default, since it seems that getuid and getpwuid
 * are distinctly not comfortably available on all systems.  The alternative
 * of using getenv("HOME") when expanding "~/xxx" is reasonably good, but
 * for "~user/xxx" I give up and just look in the current directory.
 */

#include <pwd.h>
extern int getuid(void);

int void get_home_directory(char *b, int len)
{
    int i;
    struct passwd *pw = getpwuid(getuid());
    strcpy(b, pw->pw_dir);
    i = strlen(b);
/* Here the directory handed back has "/" forced in as its final character */
    if ( b[i-1] != '/')
    {   b[i++] = '/';
        b[i] = 0;
    }
    return i;
}

int get_users_home_directory(char *b, int len)
{
    struct passwd *pw = getpwnam(b);
    if (pw != NULL) strcpy(b, pw->pw_dir);
    else strcpy(b, ".");    /* use current directory if getpwnam() fails */
    return strlen(b);
}

#else /* USE_GETUID */

int get_home_directory(char *b, int len)
{
    int i;
    strcpy(b, getenv("HOME"));  /* Probably works with most shells */
    i = strlen(b);
    if ( b[i-1] != '/')
    {   b[i++] = '/';
        b[i] = 0;
    }
    return i;
}

int get_users_home_directory(char *b, int len)
{
    strcpy(b, ".");    /* use current directory if getpwnam() no available */
    return 1;
}

#endif /* USE_GETUID */

#ifdef UNIX_TIMES
/*
 * This is a BSD-style clock facility, possibly giving a resolution of
 * only 1/100 second.  I believe that Portable Standard Lisp typically
 * reports user time, which is why I do this.  A further nasty here
 * is that I am probably compiling this file in ANSI mode, and on
 * at least some computers this makes #include <sys/times.h> fairly
 * ineffective (ugh), so I declare all the structures and functions I
 * want directly (ugh ugh) and hope they are as needed.  Consider this
 * when you port to a new machine.
 */

clock_t read_clock(void)
{
    struct my_tms {
        clock_t tms_utime;
        clock_t tms_stime;
        clock_t tms_cutime;
        clock_t tms_cstime;
        } tmsbuf;
    clock_t w1, w2, w3;
    extern void times(/*struct my_tms * */);
    times(&tmsbuf);
    w1 = tmsbuf.tms_utime;   /* User time in UNIX_TIMES ticks */
    w2 = CLOCKS_PER_SEC;
    w3 = UNIX_TIMES;
    return (clock_t)((double)w1 * ((double)w2/(double)w3));
}

#endif

#ifdef __kcm
extern int _ttyhandle;

int batchp(void)
{
    return (_ttyhandle != 0);
}

#else
#ifdef NCC_LIB
int batchp(void)
{
    extern int _fisatty(FILE*);
    return !_fisatty(stdin);
}

#else
#if BSD_LIB
int batchp(void)
{
    return !isatty(fileno(stdin));
}
#else
#error "Unknown Library type"

#endif /* BSD_LIB */
#endif /* NCC_LIB */
#endif /* __kcm */

/*
 * The next procedure is responsible for establishing information about
 * where the main checkpoint image should be recovered from, and where
 * and fasl files should come from.
 */
char *find_image_directory(int argc, char *argv[])
{
    char image[LONGEST_LEGAL_FILENAME];
    char pgmname[LONGEST_LEGAL_FILENAME];
    char *w;
/*
 * Here I assume Unix, or something sufficiently like it, and
 * if the current program is called xxx, then I want an environment
 * variable called xxx.img to tell me where to find the image file
 * and the fasl directory.
 */
#ifdef PUBLIC
    strcpy(pgmname, "/usr/local/lib/reduce");  /* fixed name */
    w = my_getenv("reduceimg");
    if (w != NULL) strcpy(image, w);
    else strcpy(image, pgmname);
#else
    if (argc > 0 && argv[0] != NULL)
    {   int i;
        w = argv[0];
        i = strlen(w);
        while (i > 0 && w[i-1] != '/') i--;
        sprintf(pgmname, "%s.img", &w[i]);  /* final component of argv[0] */
        strncpy(program_name, &w[i], 63);
        program_name[63] = 0;
    }
    else strcpy(pgmname, "csl.img");       /* even argv[0] is not available! */
    w = my_getenv(pgmname);
#endif
    if (w != NULL) strcpy(image, w);
    else strcpy(image, pgmname);

/*
 * I copy from local vectors into malloc'd space to hand my
 * answer back.
 */
    w = (char *)(*malloc_hook)(1+strlen(image));
/*
 * The error exit here seem unsatisfactory...
 */
    if (w == NULL)
    {   fprintf(stderr, "\n+++ Panic - run out of space\n");
        exit(EXIT_FAILURE);
    }
    strcpy(w, image);
    return w;
}

/*
 * The following function controls memory allocation policy
 */

int32 ok_to_grab_memory(int32 current)
{
#ifdef COMMON
    return current;
#else
    return 3*current + 2;
#endif
}

#include "fileops.c"
#include "scandir.c"

/* **************** THIS TICKER STUFF IS NOT WORKING CORRECTLY ******* */
#ifndef SOFTWARE_TICKS
#include <sys/time.h>
struct itimerval value, ovalue;
#endif

static CSLbool ticker_active = NO;

void add_ticker(void)
{
    void wimp_tick(int);
    /*putc('+', stderr); */
    if (ticker_active) return;
#ifdef SOFTWARE_TICKS
    if (countdown<0) countdown = SOFTWARE_TICKS; /* Reset if expired */
#else
    value.it_interval.tv_sec = 1;
    value.it_interval.tv_usec = 0;
    value.it_value.tv_sec = 1;
    value.it_value.tv_usec = 0;
    setitimer(ITIMER_VIRTUAL, &value, NULL); /* Set up a 1 sec interrupt */
    signal(SIGVTALRM, wimp_tick);
#endif
    ticker_active = YES;
}

void remove_ticker(void)
{
    /*putc('-', stderr); */
    if (!ticker_active) return;
#ifndef SOFTWARE_TICKS
    value.it_interval.tv_sec = 0;
    value.it_interval.tv_usec = 0;
    value.it_value.tv_sec = 0;
    value.it_value.tv_usec = 0;
    setitimer(ITIMER_VIRTUAL, &value, NULL); /* Remove all interrupt */
    signal(SIGVTALRM, SIG_IGN);	/* Ignore the clock ticks */
#endif
    ticker_active = NO;
}

#ifndef SOFTWARE_TICKS
void wimp_tick(int sig)
{
    /* putc('.', stderr);*/
    if (!ticker_active) return;
    signal(SIGVTALRM, wimp_tick);
    if (tick_pending) return;
    else if (already_in_gc) tick_on_gc_exit = YES;
    else {
      Lisp_Object nil = C_nil;
      tick_pending = YES;
      saveheaplimit = heaplimit;
      heaplimit = fringe;
      savevheaplimit = vheaplimit;
      vheaplimit = vfringe;
      savecodelimit = codelimit;
      codelimit = codefringe;
      savestacklimit = stacklimit;
      stacklimit = stackbase;
    }
    return;
}
#endif

/* ************************************************************ */
/* ********** StdWin Interface ******************************** */
/* ************************************************************ */
/* ************************************************************ */

#include "stdwin.h"
#include "tools.h"
#include "editwin.h"
#include "text.h"               /* Rather a cheat as I need to look
                                 * low down in here */

static WINDOW *CSL_window;
static EDITWIN *CSL_ew;
static EDITWIN *help_ew;
int max_nlines = 250;

#ifndef HELP_DATA
#define HELP_DATA "help.data"
#endif
#ifndef HELP_INDEX
#define HELP_INDEX "help.index"
#endif

static MENU *adminmenu;
static MENU *editmenu;
static MENU *loadmenu;
static MENU *libmenu;
static MENU *switchmenu;
static MENU *helpmenu;
/* static MENU *fontmenu; */
/* static MENU *sizemenu; */

#define ADMIN_MENU (1)
#define MMFile    0
#define MMSaveas  1
#define MMHelp    2 /* main window menu items */
#define MMHelpSel 3
#define MMHelpAsk 4
#define MMInt     5
#define MMAbort   6
#define MMPause   7
#define MMDummy   8
#define MMTime    9
#define MMSpace   10
#define MMOTime   11

#define EDIT_MENU (2)
#define MMCut     0
#define MMCopy    1
#define MMPaste   2
#define MMClear   3
#define MMSelAll  4

#define HELP_LEN (36)
#define HELP_MENU (3)
static struct hlp {
  char name[HELP_LEN];
  long offset;
  int  length;
} *hlp;
int help_length;
int helpstamp;

#define LOAD_MENU (4)

static char *loads[] = {
  "arnum", "assist", "boolean", "changevr", "compact", "complex",
  "decompos", "defint", "dfpart", "elem", "excalc", "gentran", "groebner",
  "gnuplot",
  "laplace", "linalg", "normform", "numeric", "odesolve", "residue",
  "rlfi", "rsolve", "scope", "sets", "specfn", "taylor", "tps", "tri",
  "trigsimp", "zeilberg",
  (char*)NULL};

#define LIB_MENU (5)

static char *libraries[] = {
  "algint", "applysym", "avector", "cali", "camal", "crack", "cvit",
  "desir", "dummy", "fide", "fps", "ideals", "ineq", "invbase", "lie",
  "modsr", "ncpoly", "orthovec", "physop", "pmrules", "randpoly",
  "reacteqn", "spde", "symmetry", "wu", "xcolor", "xideal", "ztrans",
  (char*)NULL};


#define SWITCH_MENU (6)
static struct sw {
  char *name;
  int state;
} switches[] = {
  {"algint", NO},      {"adjprec", NO}, {"allbranch", NO},  {"allfac", YES},
  {"arbvars", NO},     {"asterisk", YES},	{"backtrace", NO},
  {"balanced_mod", NO},{"bfspace", NO}, {"combineexpt", NO},
  {"combinelogs", NO}, {"comp", NO},    {"complex", NO},
  {"compxroots", NO},  {"cramer", NO},  {"cref", NO},       {"defn", NO},
  {"demo", NO},        {"dfprint", NO}, {"div", NO},        {"echo", NO},
  {"errcont", NO},     {"evallhseqp", NO},                  {"exp", YES},
  {"expandexpt", YES}, {"expandlogs", NO},                  {"ezgcd", NO},
  {"factor", NO},      {"fastfor", NO}, {"force", NO},      {"fort", NO},
  {"fortupper", NO},   {"fullprec", NO},{"fullprecision", NO},
  {"fullroots", NO},   {"gcd", NO},     {"heugcd", NO},     {"horner", NO},
  {"ifactor", NO},     {"int", NO},     {"intstr", NO},     {"lcm", YES},
  {"lessspace", NO},   {"limitedfactors", NO},              {"list", NO},
  {"listargs", NO},    {"lower", YES},  {"mcd", YES},       {"modular", NO},
  {"msg", YES},        {"multiplicities", NO},              {"nat", YES},
  {"nero", NO},        {"noarg", YES},  {"noconvert", NO},  {"nonlnr", NO},
  {"nosplit", YES},    {"numval", YES}, {"output", YES},    {"period", YES},
  {"pgwd", NO},        {"plap", NO},    {"precise", YES},
  {"pret", NO},        {"pri", YES},    {"pwrds", YES},
  {"quotenewnam", YES},{"raise", NO},   {"rat", NO},        {"ratarg", NO},
  {"rational", NO},    {"rationalize", NO},                 {"ratpri", YES},
  {"reduced", NO},     {"revpri", NO},  {"rlisp88", NO},    {"rootmsg", NO},
  {"roundall", YES},   {"roundbf", NO}, {"rounded", NO},
  {"savestructr", NO}, {"solvesingular", NO},               {"time", NO},
  {"trallfac", NO},    {"trfac", NO},   {"trint", NO},      {"trroot", NO},
  {(char*)NULL, 0}};

static void menusetup(void)
{
    MENU *mp;
    int i;

    adminmenu= mp= wmenucreate(ADMIN_MENU, "Admin");

    wmenuadditem(mp, "Input file...", 'F');
    wmenuadditem(mp, "Saveas...", -1);
    wmenuadditem(mp, "Help Window", 'H');
    wmenuadditem(mp, "Help Selection", 'S');
    wmenuadditem(mp, "Help Topic...", -1);
    wmenuadditem(mp, "Interrupt", 'I');
    wmenuadditem(mp, "Quit", 'Q');
    wmenuadditem(mp, "Pause", 'P');
    wmenuadditem(mp, "---------", -1);
    wmenuadditem(mp, "0.00", -1);
    wmenuadditem(mp, "[GC 0]", -1);
    wmenuadditem(mp, "", -1);
    wmenuadditem(mp, "", -1);

    wmenuenable(mp, MMDummy, NO);
    wmenuenable(mp, MMTime, NO);
    wmenuenable(mp, MMSpace, NO);
    wmenuenable(mp, MMOTime, NO);

    editmenu= mp= wmenucreate(EDIT_MENU, "Edit");
    wmenuadditem(mp, "Cut", 'X');
    wmenuadditem(mp, "Copy", 'C');
    wmenuadditem(mp, "Paste", 'V');
    wmenuadditem(mp, "Clear", 'B');
    wmenuadditem(mp, "Select All", 'A');

    helpmenu= mp= wmenucreate(HELP_MENU, "Help");
    {
      FILE* hlpindx = fopen(HELP_INDEX, "r");
      if (hlpindx != NULL) {
	fscanf(hlpindx, "%d\n", &helpstamp);
	fscanf(hlpindx, "%d", &help_length);
	hlp = (struct hlp*) calloc(1+help_length, sizeof(struct hlp));
	if (hlp == NULL) {
	  help_length = 0;
          goto loader;          /* Insufficient memory */
	}
	for (i=0; i<help_length; i++) {
	  int ch, p=0;
	  fscanf(hlpindx, "%d %d ", &(hlp[i].offset), &(hlp[i].length));
	  while (p<HELP_LEN-1) {
	    ch = getc(hlpindx);
	    if (ch == '\n') break;
	    hlp[i].name[p++] = ch; /* Was toupper here */
	  }
	  while (ch != '\n') ch = getc(hlpindx);
	  hlp[i].name[p] = '\0';
	  wmenuadditem(mp, hlp[i].name, -1);
	}
	fclose(hlpindx);
      }
      else {
	help_length = 0;
	strcpy(hlp[0].name, "No help");
	hlp[0].offset = -1;
	hlp[0].length = 0;
      }
    }

loader:
    loadmenu= mp= wmenucreate(LOAD_MENU, "Load");
    for (i=0; loads[i]!= NULL; i++)
      wmenuadditem(mp, loads[i], -1);

    libmenu= mp= wmenucreate(LIB_MENU, "Library");
    for (i=0; libraries[i]!= NULL; i++)
      wmenuadditem(mp, libraries[i], -1);

    switchmenu= mp= wmenucreate(SWITCH_MENU, "Switch");
    for (i=0; switches[i].name!= NULL; i++) {
      wmenuadditem(mp, switches[i].name, -1);
      wmenucheck(mp, i, switches[i].state);
    }
}

static fixmenus(void)
{
    CSLbool focus;

    focus= (CSL_ew->tp->foclen != 0);
    wmenuenable(editmenu, MMCut, focus);
    wmenuenable(editmenu, MMCopy, focus);
    wmenuenable(editmenu, MMClear, focus);
    wmenuenable(adminmenu, MMHelpSel, focus);
/*  wmenuenable(editmenu, MMPaste, YES); */

    if (help_ew != NULL) {
      focus= (help_ew->tp->foclen != 0);
      if (focus) {
	wmenuenable(editmenu, MMCut, focus);
	wmenuenable(editmenu, MMCopy, focus);
	wmenuenable(editmenu, MMClear, focus);
	wmenuenable(adminmenu, MMHelpSel, focus);
      }
    }
}

#define TTYBUF_SIZE 256
static char tty_buff[TTYBUF_SIZE];
static int tty_index = 0;
static CSLbool tty_ready = NO;
static int tty_nnl = 0;
static int tty_offset;

#define STDOUT_BUFSIZE 1024
#define LONGEST_PRINTF 120

static char stdout_buffer[STDOUT_BUFSIZE];
static char *stdout_p;
static int stdout_n;

void start_up_window_manager(int use_wimp)
{
    static char* def_args[]= {"X-Reduce 3.6", (char*)NULL};
    int argc= 1;
    char **argv= def_args;
    int CSL_width, CSL_height;
    signal(SIGVTALRM, SIG_IGN);	/* Ensure it is off */
    wargs(&argc, &argv);	/* Fiddle the argument decode for now */
    winit();
    wsetfont("6x13");		/* For now */
    menusetup();
    wsetdefwinsize(82*wcharwidth('0'), 25*wlineheight());
    CSL_ew = ewcreate(NULL);
    CSL_window = CSL_ew->win;
    wsettitle(CSL_window, "Reduce 3.6");
    fixmenus();
/*  wmenudetach(CSL_window, helpmenu); */
    wmenuenable(editmenu, MMTime, NO); /* These are not selectable */
    wmenuenable(editmenu, MMOTime, NO); /* These are not selectable */
    wmenuenable(editmenu, MMSpace, NO);
    wmenudetach(CSL_window, loadmenu); /* These are only valid when reading */
    wmenudetach(CSL_window, libmenu);
    wmenudetach(CSL_window, switchmenu);
/*  wmessage("Welcome to X-Reduce\n\n"); */
    wflush();
    stdout_n = 0;
    stdout_p = stdout_buffer;
#ifndef SOFTWARE_TICKS
    value.it_interval.tv_sec = 1;
    value.it_interval.tv_usec = 0;
    value.it_value.tv_sec = 1;	/* ?? 10 seconds */
    value.it_value.tv_usec = 0;
    signal(SIGVTALRM, wimp_tick);
    setitimer(ITIMER_VIRTUAL, &value, NULL); /* Set up a 1 sec interrupt */
#endif
    help_ew = NULL;		/* Help window */
}

static char *help_buff;
CSLbool
helpwindow(int index)
{
    FILE* help = fopen(HELP_DATA, "r");
    int ch;
    int width, height;
    int size = hlp[index].length;

    if (help == NULL) return;
/*  fprintf(stderr, "Help on index %d offset=%d size=%d\n",
	  index, hlp[index].offset, hlp[index].length); */
    fscanf(help, "%d\n", &ch);
    if (ch != helpstamp) return; /* Check help data in in line with index */
    fseek(help, hlp[index].offset, SEEK_SET);
    if (help_ew) {
      (*free_hool)(help_buff);
      tesetfocus(help_ew->tp, 0, tegetlen(help_ew->tp));
      ewreplace(help_ew, "");
    }
    else {
      help_ew = ewcreate(NULL);
      wsettitle(help_ew->win, "Help for Reduce 3.6");
    }
    help_buff = (*malloc_hook)(size+1);
    if (help_buff == NULL) {
      dprintf("Insufficient memory");
      wfleep();
      return FALSE;
    }
/*  fprintf(stderr, "reading %d bytes to buffer\n", size); */
    fread(help_buff, size, 1, help);
/*  fprintf(stderr, "help starts as %.100s\n", help_buff); */
    help_buff[size] = '\0';
    wmenudetach(help_ew->win, loadmenu);
    wmenudetach(help_ew->win, libmenu);
    wmenudetach(help_ew->win, switchmenu);
/*  wmenudetach(help_ew->win, adminmenu); */
    ewreplace(help_ew, help_buff);
    tesetfocus(help_ew->tp, 0, 0);
    fclose(help);
    return TRUE;
}

void help_buffer(char *buf, int len)
{
    int i;
    for (i=0; i<help_length; i++) {
      /* fprintf(stderr, "Check against %s\n", hlp[i].name); */
      if (strncmp(hlp[i].name, buf, len) == 0) {
	helpwindow(i);
	break;
      }
    }
    if (i == help_length) wfleep();
}

void help_selection(EDITWIN *ew)
{
    int i;
    char *text;
    TEXTEDIT *tp = ew->tp;
    if (tp->foclen == 0) {
      wfleep();
      return;
    }
    text= tegettext(tp);
    help_buffer(text+tp->foc, tp->foclen);
}

extern int pause_set = 0;
void event_loop(void)
{
    for (;;) {                    /* Loop while there are events */
      EVENT e;
      EDITWIN *ew;
      CSLbool closed;

/*       putc('%', stderr); */
      wgetevent(&e);
/*       printf("Event: type=%d win=%p data=%d\n", e.type, e.window, e.u.command);  */
      ew = ewfind(e.window);
      if (ew == CSL_ew) {
	switch (e.type) {
	case WE_CHAR:
	  switch(e.u.character) {
          case 'A'-'@':         /* ^A == beginning of line */
	    {
	      TEXTEDIT* tp = CSL_ew->tp;
	      tesetfocus(tp,
			 zsubgap(tp->start[tewhichline(tp,
						       zaddgap(tp->foc),
						       tp->focprev)]),
			 -1);
	      break;
	    }
          case 'B'-'@':         /* ^B back a character */
	    tearrow(CSL_ew->tp, WC_LEFT);
	    break;
          case 127:             /* Delete character */
          case 'D'-'@':         /* ^D delete at cursor */
	    {
	      TEXTEDIT* tp = CSL_ew->tp;
	      tearrow(tp, WC_RIGHT);
	      {
		int f1 = tp->foc;
		int i;
		int ss = tp->start[tp->nlines-tty_nnl];
		int ee = ss + tty_offset;
		if (ss <= f1 && f1 < ee) {
		  if (tty_offset>0) tty_offset--;

		}
		e.type = WE_COMMAND;
		e.u.command = WC_BACKSPACE;
		ewevent(ew,&e, NULL);
		break;
	      }
	    }
          case 'E'-'@':         /* ^E end of line */
	    {
	      TEXTEDIT* tp = CSL_ew->tp;
	      int line = tewhichline(tp, zaddgap(tp->foc), tp->focprev);
	      int xxx = zsubgap(tetextround(tp, line, tp->right));
	      tesetfocus(tp, xxx, -1);
	      break;
	    }
          case 'F'-'@':         /* ^F forward a character */
	    tearrow(CSL_ew->tp, WC_RIGHT);
	    break;
          case 'K'-'@':         /* ^K kill to end of line */
	    {			/* This does not take notice of offset */
	      TEXTEDIT* tp = CSL_ew->tp;
	      int f1;
	      int i;
	      int ss;
	      int ee;
	      tesetfocus(tp,
			 tp->foc,
			 zsubgap(tetextround(tp,
					     tewhichline(tp, zaddgap(tp->foc),
							     tp->focprev),
					     tp->right)));
	      f1 = tp->foc;
	      ss = tp->start[tp->nlines-tty_nnl];
	      ee = ss + tty_offset;
	      for (i=0; i<tp->foclen; i++)
		if (ss <= f1+i && f1+i < ee) {
		  if (tty_offset>0) tty_offset--;
		}
	      ewreplace(ew, "");
	      break;
	    }
          case 'N'-'@':         /* ^N next line */
	    tearrow(CSL_ew->tp, WC_DOWN);
	    break;
          case 'P'-'@':         /* ^P previous line */
	    tearrow(CSL_ew->tp, WC_UP);
	    break;
          case 'Z'-'@':         /* ^Z move to end of buffer */
	    {
	      TEXTEDIT* tp = CSL_ew->tp;
	      tesetfocus(tp, tp->buflen - tp->gaplen, -1);
	      break;
	    }
	  default:
	    ewevent(ew, &e, &closed);
	    if (tty_ready == YES && !pause_set) return;
	  }
	  break;
	case WE_COMMAND:
	  switch (e.u.command) {
          case WC_CANCEL:
            interrupt_pending = YES;
            break;
	  case WC_CLOSE:
	    pause_for_user();
	    exit(1);
	  case WC_RETURN:
	    {
	      TEXTEDIT* tp = CSL_ew->tp;
	      int f1 = zaddgap(tp->foc);
	      int ee = tp->start[tp->nlines-tty_nnl] + tty_offset;
/* printf("f1=%d ee=%d offset=%d\n", f1, ee, tty_offset); */
	      if (f1 >= ee) {
		tty_nnl++;
		if (f1 == tp->buflen) {
		  ewevent(ew, &e, &closed);
		  tty_ready = YES;
		  if (!pause_set) return;
		}
	      }
	    }
	    break;
	  case WC_DEL:
	  case WC_BACKSPACE:
	    /* Need to check to see if we are deleting
	     * in the offset area */
            {
              TEXTEDIT* tp = CSL_ew->tp;
              int f1 = tp->foc;
              int i;
              int ss = tp->start[tp->nlines-tty_nnl];
              int ee = ss + tty_offset;
	      if (tp->foclen == 0) {
		if (ss < f1 && f1 <= ee && tty_offset>0) tty_offset--;
	      }
	      else {
                for (i=0; i<tp->foclen; i++) {
		  if (ss <= f1+i && f1+i < ee && tty_offset>0) tty_offset--;
		}
	      }
            }
	    break;
	  case WC_LEFT:
	  case WC_RIGHT:
	  default:
	    break;
	  }
        ewevent(ew, &e, &closed);
        break;
      case WE_MENU:
        switch (e.u.m.id) {
        case ADMIN_MENU:
          switch (e.u.m.item) {
            case MMFile:
              {
                short wd;
                TEXTEDIT *tp = CSL_ew->tp;
		char name[42];
		if (waskstr("Input file name", name, 40)) {
		  tesetfocus(tp, tp->buflen - tp->gaplen, -1);
		  ewreplace(CSL_ew, "in \"");
		  ewreplace(CSL_ew, name);
		  ewreplace(CSL_ew, "\"");
		  /*tetoend(tp); */
		}
		break;
              }
            case MMSaveas:
              ewsaveas(CSL_ew);
              break;
          case MMHelp:
            helpwindow(0);
            break;
          case MMHelpSel:
            help_selection(ew);
            break;
	  case MMHelpAsk:
	    {
	      char buf[40];
	      int len;
	      if (waskstr("Help on topic", buf, 40)) {
		len = strlen(buf);
		help_buffer(buf, len);
	      }
	    }
	    break;
          case MMAbort:
            pause_for_user();
            exit(1);
          case MMInt:
            interrupt_pending = YES;
            return;
          case MMPause:
            pause_set = !pause_set;
            wmenucheck(adminmenu, MMPause, pause_set);
            if (pause_set) wsettitle(CSL_window, "<Paused> Reduce 3.6");
            else           wsettitle(CSL_window, "Reduce 3.6");
            break;
          }
          break;
        case EDIT_MENU:
          switch (e.u.m.item) {
          case MMCopy:
            ewcopy(ew);
            break;
          case MMPaste:
            {
              char* text = wgetclip();
              char* tt = text;
              int valid = YES;

              if (text == NULL) wfleep();
              else {
                TEXTEDIT *tp = CSL_ew->tp;
                tesetfocus(tp, tp->buflen - tp->gaplen, -1);
                while (*tt != '\0')
                  if (*tt++=='\n') valid = NO;
                if (valid) ewreplace(ew, text);
                else wmessage("Cannot Paste text including new line");
              }
            }
            break;
          case MMCut:
            ewcopy(ew);
          case MMClear:
                                /* Need to check to see if we are deleting
                                 * in the offset area */
            {
              TEXTEDIT* tp = CSL_ew->tp;
              int f1 = tp->foc;
              int i;
              int ss = tp->start[tp->nlines-tty_nnl];
              int ee = ss + tty_offset;
              for (i=0; i<tp->foclen; i++)
                if (ss <= f1+i && f1+i < ee) {
                  if (tty_offset>0) tty_offset--;
                }
            }
            ewreplace(ew, "");
            break;
          case MMSelAll:
            tesetfocus(ew->tp, 0, tegetlen(ew->tp));
            break;
          }
          break;
        case LOAD_MENU:
          {
            char *load = "load_package ";
            char *tt = loads[e.u.m.item];
            TEXTEDIT *tp = CSL_ew->tp;
            tesetfocus(tp, tp->buflen - tp->gaplen, -1);
            tp->aim= UNDEF;
            tp->focprev= FALSE;
            ewreplace(CSL_ew, load);
            ewreplace(CSL_ew, tt);
            tty_ready = YES;
            ewreplace(CSL_ew, ";\n");
            tty_nnl++;
            wmenuenable(loadmenu, e.u.m.item, NO);
            return;
          }
        case LIB_MENU:
          {
            char *load = "load_package ";
            char *tt = libraries[e.u.m.item];
            TEXTEDIT *tp = CSL_ew->tp;
            tesetfocus(tp, tp->buflen - tp->gaplen, -1);
	    tp->aim= UNDEF;
	    tp->focprev= FALSE;
            ewreplace(CSL_ew, load);
            ewreplace(CSL_ew, tt);
            tty_ready = YES;
            ewreplace(CSL_ew, ";\n");
            tty_nnl++;
            wmenuenable(loadmenu, e.u.m.item, NO);
            return;
          }
        case SWITCH_MENU:
          {
            char *load = (switches[e.u.m.item].state ? "off " : "on ");
            char *tt = switches[e.u.m.item].name;
            TEXTEDIT *tp = CSL_ew->tp;
            tesetfocus(tp, tp->buflen - tp->gaplen, -1);
            ewreplace(CSL_ew, load);
            ewreplace(CSL_ew, tt);
            tty_ready = YES;
            ewreplace(CSL_ew, ";\n");
            tty_nnl++;
            switches[e.u.m.item].state = ~ switches[e.u.m.item].state;
            wmenucheck(switchmenu, e.u.m.item, switches[e.u.m.item].state);
            return;
          }
        case HELP_MENU:
	  helpwindow(e.u.m.item);
	  break;
        }
        break;
      case WE_CLOSE:
        pause_for_user();
        exit(1);
      default:
        ewevent(ew, &e, &closed);
        break;
	}
      }
      else if (ew == help_ew) {
	switch (e.type) {
	case WE_MOUSE_UP:	/* Extend to a word on single click */
	  if (!ew->tp->mdown) break;
	  ew->tp->mdown= FALSE;
	  if (e.u.where.clicks > 1) {
	    teclicknew(ew->tp, e.u.where.h, e.u.where.v, FALSE, TRUE);
	    help_selection(ew);
	  }
	  break;
	case WE_CHAR:
	  switch(e.u.character) {
	  case 'A'-'@':		/* ^A == beginning of line */
	    {
	      TEXTEDIT* tp = help_ew->tp;
	      tesetfocus(tp,
			 zsubgap(tp->start[tewhichline(tp,
						       zaddgap(tp->foc),
						       tp->focprev)]),
			 -1);
	      break;
	    }
	  case 'B'-'@':		/* ^B back a character */
	    tearrow(help_ew->tp, WC_LEFT);
	    break;
	  case 'E'-'@':		/* ^E end of line */
	    {
	      TEXTEDIT* tp = help_ew->tp;
	      int line = tewhichline(tp, zaddgap(tp->foc), tp->focprev);
	      int xxx = zsubgap(tetextround(tp, line, tp->right));
	      tesetfocus(tp, xxx, -1);
	      break;
	    }
	  case 'F'-'@':		/* ^F forward a character */
	    tearrow(help_ew->tp, WC_RIGHT);
	    break;
          case 'K'-'@':         /* ^K is Page up */
            {
              int i;
              int j;
              wgetdefwinsize(&i, &j);
              j = j/wlineheight() -1;
              for (i=0; i<j; i++) tearrow(help_ew->tp, WC_UP);
              break;
          }
	  case 'N'-'@':		/* ^N next line */
	    tearrow(help_ew->tp, WC_DOWN);
	    break;
	  case 'P'-'@':		/* ^P previous line */
	    tearrow(help_ew->tp, WC_UP);
	    break;
	  case 'Z'-'@':		/* ^Z move to end of buffer */
	    {
	      TEXTEDIT* tp = help_ew->tp;
	      tesetfocus(tp, tp->buflen - tp->gaplen, -1);
	      break;
	    }
	  case 'V'-'@':		/* ^V page down */
	  case ' ':
          case 'L'-'@':         /* ^L is Page down */
	    {
	      int i;
	      int j;
	      wgetdefwinsize(&i, &j);
	      j = j/wlineheight() -1;
	      for (i=0; i<j; i++) tearrow(help_ew->tp, WC_DOWN);
	      break;
	    }
	  case 'i':
	  case 'I':
	    {
	      char buf[40];
	      int len;
	      if (waskstr("Help on topic", buf, 40)) {
		len = strlen(buf);
		help_buffer(buf, len);
	      }
	      break;
	    }
	  case 'n':
	  case 'N':
	    {
	      extern char *strstr(const char*, const char*);
	      char *p = strstr((const char*)help_buff, (const char*)"Next: ");
	      int i = 0;
	      if (p == NULL) {
		wfleep(); break;
	      }
	      p += 6;
	      while (p[i]!= ',') i++;
	      help_buffer(p,i);
	      break;
	    }
	  case 'p':
	  case 'P':
	    {
	      extern char *strstr(const char*, const char*);
	      char *p = strstr((const char*)help_buff, "Prev: ");
	      int i = 0;
	      if (p == NULL) {
		wfleep(); break;
	      }
	      p += 6;
	      while (p[i]!= ',') i++;
	      help_buffer(p,i);
	      break;
	    }
	  case 'q':
	  case 'Q':
	    help_ew->saved = TRUE; /* Fake it */
	    (*free_hool)(help_buff);
	    ewclose(help_ew);
	    help_ew = 0;
	    break;
	  case 'u':
	  case 'U':
	    {
	      extern char *strstr(const char*, const char*);
	      char *p = strstr((const char*)help_buff, "Up: ");
	      int i = 0;
	      if (p == NULL) {
		wfleep(); break;
	      }
	      p += 4;
	      while (p[i]!= '\n') i++;
	      help_buffer(p,i);
	      break;
	    }
	  }
	  break;
	case WE_MENU:
	  switch (e.u.m.id) {
	  case ADMIN_MENU:
	    switch (e.u.m.item) {
            case MMSaveas:
              ewsaveas(help_ew);
              break;
	    case MMHelp:
	      if (help_length) helpwindow(0);
	      break;
	    case MMHelpSel:
	      help_selection(ew);
	      break;
	    case MMHelpAsk:
	      {
		char buf[40];
		int len;
		if (waskstr("Help on topic", buf, 40)) {
		  len = strlen(buf);
		  help_buffer(buf, len);
		}
		break;
	      }
	    case MMAbort:
	      help_ew->saved = TRUE; /* Fake it */
	      (*free_hool)(help_buff);
	      ewclose(help_ew);
	      help_ew = 0;
	      break;
	    }
	    break;
	  case EDIT_MENU:
	    switch (e.u.m.item) {
	    case MMCopy:
	      ewcopy(ew);
	      break;
	    case MMSelAll:
              tesetfocus(ew->tp, 0, tegetlen(ew->tp));
	      break;
	    }
	    break;
	  case HELP_MENU:
	    helpwindow(e.u.m.item);
	    break;
	  }
	  break;
	case WE_COMMAND:
	  switch (e.u.command) {
          case WC_CANCEL:
            interrupt_pending=YES;
            break;
	  case WC_RETURN:
	    help_selection(ew);
	    break;
	  case WC_DEL:
	  case WC_BACKSPACE:
	    helpwindow(0);
	    break;
	  default:
	    ewevent(ew, &e, &closed);
	    break;
	  }
	  if (e.u.command != WC_CLOSE) {
	    break;
	  }
	case WE_CLOSE:
	  help_ew->saved = TRUE; /* Fake it */
	  (*free_hool)(help_buff);
	  ewclose(help_ew);
	  help_ew = 0;
	  break;
	default:
	  ewevent(ew, &e, &closed);
	  if (closed) {
	    help_ew->saved = TRUE; /* Fake it */
	    (*free_hool)(help_buff);
	    ewclose(help_ew);
	    help_ew = 0;
	  }
	  break;
	}
      }
    else if (ew != NULL) ewevent(ew, &e, &closed);
    else wfleep();
    fixmenus();
  }
}

void poll_for_attn(void)
{
    EVENT e;
    EDITWIN *ew;
/*     putc('#', stderr); */
    if (!pause_set) {
      if (!wpollevent(&e)) {
/* 	putc('<', stderr);  */
	return;
      }
    }
    else wgetevent(&e);
/*     fprintf(stderr, "PollEvent: type=%d win=%p data=%d\n", e.type,e.window,e.u.command); */
    for (;;) {			/* Loop while there are events */
      CSLbool closed;

      ew = ewfind(e.window);
      if (ew == CSL_ew) {
	switch (e.type) {
	case WE_CHAR:
	  switch(e.u.character) {
	  case 'A'-'@':		/* ^A == beginning of line */
	    {
	      TEXTEDIT* tp = CSL_ew->tp;
	      tesetfocus(tp,
			 zsubgap(tp->start[tewhichline(tp,
						       zaddgap(tp->foc),
						       tp->focprev)]),
			 -1);
	      break;
	    }
	  case 'B'-'@':		/* ^B back a character */
	    tearrow(CSL_ew->tp, WC_LEFT);
	    break;
	  case 'D'-'@':		/* ^D delete at cursor */
	    {
	      TEXTEDIT* tp = CSL_ew->tp;
	      tearrow(tp, WC_RIGHT);
	      e.type = WE_COMMAND;
	      e.u.command = WC_BACKSPACE;
	      ewevent(ew,&e, NULL);
	      break;
	    }
	  case 'E'-'@':		/* ^E end of line */
	    {
	      TEXTEDIT* tp = CSL_ew->tp;
	      int line = tewhichline(tp, zaddgap(tp->foc), tp->focprev);
	      int xxx = zsubgap(tetextround(tp, line, tp->right));
	      tesetfocus(tp, xxx, -1);
	      break;
	    }
	  case 'F'-'@':		/* ^F forward a character */
	    tearrow(CSL_ew->tp, WC_RIGHT);
	    break;
	  case 'K'-'@':		/* ^K kill all type ahead */
	    tty_index = 0;
	    break;
	  case 'N'-'@':		/* ^N next line */
	    tearrow(CSL_ew->tp, WC_DOWN);
	    break;
	  case 'P'-'@':		/* ^P previous line */
	    tearrow(CSL_ew->tp, WC_UP);
	    break;
	  case 'Z'-'@':		/* ^Z move to end of buffer */
	    {
	      TEXTEDIT* tp = CSL_ew->tp;
	      tesetfocus(tp, tp->buflen - tp->gaplen, -1);
	      break;
	    }
	  case 'V'-'@':		/* ^V page down */
	  case ' ':
	    {
	      int i;
	      int j;
	      wgetdefwinsize(&i, &j);
	      j = j/wlineheight() -1;
	      for (i=0; i<j; i++) tearrow(help_ew->tp, WC_DOWN);
	      break;
	    }
	  default:
	    if (tty_index > TTYBUF_SIZE-2) wfleep();
	    else tty_buff[tty_index++] = e.u.character;
	    break;
	  }
	  break;
	case WE_COMMAND:
	  switch (e.u.command) {
        case WC_CANCEL:
          interrupt_pending = YES;
          break;
	  case WC_CLOSE:
	    pause_for_user();
	    exit(1);
	  case WC_RETURN:
	    if (tty_index > TTYBUF_SIZE-2) wfleep();
	    else tty_buff[tty_index++] = '\n';
	    break;
	  case WC_TAB:
	    if (tty_index > TTYBUF_SIZE-2) wfleep();
	    else tty_buff[tty_index++] = '\t';
	    break;
	  case WC_DEL:
	  case WC_BACKSPACE:
	    if (tty_index>0) tty_index--;
	    break;
	  }
	  break;
	case WE_MENU:
	  switch (e.u.m.id) {
	  case ADMIN_MENU:
	    switch (e.u.m.item) {
	    case MMHelp:
	      helpwindow(0);
	      break;
	    case MMHelpSel:
	      help_selection(ew);
	      break;
	    case MMAbort:
	      pause_for_user();
	      exit(1);
	    case MMInt:
	      interrupt_pending = YES;
	      return;
	    case MMPause:
	      pause_set = !pause_set;
	      wmenucheck(adminmenu, MMPause, pause_set);
	      if (pause_set) wsettitle(CSL_window, "<Paused> Reduce 3.6");
	      else           wsettitle(CSL_window, "Reduce 3.6");
	      break;
	    }
	    break;
	  case EDIT_MENU:
	    switch (e.u.m.item) {
	    case MMCopy:
	      ewcopy(ew);
	      break;
	    case MMPaste:
	      break;
	    case MMCut:
	      ewcopy(ew);
	    case MMClear:
	      ewreplace(ew, "");
	      break;
	    case MMSelAll:
	      tesetfocus(ew->tp, 0, tegetlen(ew->tp));
	      break;
	    }
	    break;
	  case HELP_MENU:
	    helpwindow(e.u.m.item);
	    break;
	  }
	  break;
	case WE_CLOSE:
	  pause_for_user();
	  exit(1);
	default:
	  ewevent(ew, &e, &closed);
	  break;
	}
      }
      else if (ew == help_ew) {
	switch (e.type) {
	case WE_MOUSE_UP:         /* Extend to a word on single click */
	  if (!ew->tp->mdown)
	    break;
	  ew->tp->mdown= FALSE;
	  if (e.u.where.clicks > 1) {
	    teclicknew(ew->tp, e.u.where.h, e.u.where.v, FALSE, TRUE);
	    help_selection(ew);
	  }
	  break;
	case WE_CHAR:
/* 	  fprintf(stderr, "WE_CHAR %d(%c)\n", e.u.character,e.u.character); */
	  switch(e.u.character) {
	  case 'A'-'@':		/* ^A == beginning of line */
	    {
	      TEXTEDIT* tp = help_ew->tp;
	      tesetfocus(tp,
			 zsubgap(tp->start[tewhichline(tp,
						       zaddgap(tp->foc),
						       tp->focprev)]),
			 -1);
	      break;
	    }
	  case 'B'-'@':		/* ^B back a character */
	    tearrow(help_ew->tp, WC_LEFT);
	    break;
	  case 'E'-'@':		/* ^E end of line */
	    {
	      TEXTEDIT* tp = help_ew->tp;
	      int line = tewhichline(tp, zaddgap(tp->foc), tp->focprev);
	      int xxx = zsubgap(tetextround(tp, line, tp->right));
	      tesetfocus(tp, xxx, -1);
	      break;
	    }
	  case 'F'-'@':		/* ^F forward a character */
	    tearrow(help_ew->tp, WC_RIGHT);
	    break;
	  case 'N'-'@':		/* ^N next line */
	    tearrow(help_ew->tp, WC_DOWN);
	    break;
	  case 'P'-'@':		/* ^P previous line */
	    tearrow(help_ew->tp, WC_UP);
	    break;
	  case 'Z'-'@':		/* ^Z move to end of buffer */
	    {
	      TEXTEDIT* tp = help_ew->tp;
	      tesetfocus(tp, tp->buflen - tp->gaplen, -1);
	      break;
	    }
          case 'L'-'@':         /* ^L is PgDn */
          case 'V'-'@':         /* ^V page down */
          case ' ':
            {
              int i;
              int j;
              wgetdefwinsize(&i, &j);
              j = j/wlineheight() -1;
              for (i=0; i<j; i++) tearrow(help_ew->tp, WC_DOWN);
              break;
	  }
          case 'K'-'@':         /* ^K is PgUp */
            {
              int i;
              int j;
              wgetdefwinsize(&i, &j);
              j = j/wlineheight() -1;
              for (i=0; i<j; i++) tearrow(help_ew->tp, WC_UP);
	  break;
            }
        }
        break;
	case WE_MENU:
	  switch (e.u.m.id) {
	  case ADMIN_MENU:
	    switch (e.u.m.item) {
	    case MMHelp:
	      if (help_length) helpwindow(0);
	      break;
	    case MMHelpSel:
	      help_selection(ew);
	      break;
	    }
	    break;
	  case EDIT_MENU:
	    switch (e.u.m.item) {
	    case MMCopy:
	      ewcopy(ew);
	      break;
	    case MMSelAll:
	      tesetfocus(ew->tp, 0,
			 tegetlen(ew->tp));
	      break;
	    }
	    break;
	  case HELP_MENU:
	    helpwindow(e.u.m.item);
	    break;
	  }
	  break;
	case WE_COMMAND:
	  switch (e.u.command) {
        case WC_CANCEL:
          interrupt_pending = YES;
          break;
	  case WC_RETURN:
	    help_selection(ew);
	    break;
	  case WC_DEL:
	  case WC_BACKSPACE:
	    helpwindow(0);
	    break;
	  default:
	    ewevent(ew, &e, &closed);
	    break;
	  }
	  if (e.u.command != WC_CLOSE) {
	    break;
	  }
	case WE_CLOSE:
	  help_ew->saved = TRUE;  /* Fake it */
	  (*free_hool)(help_buff);
	  ewclose(help_ew);
	  help_ew = 0;
	  break;
	default:
	  ewevent(ew, &e, &closed);
	  if (closed) {
	    help_ew->saved = TRUE; /* Fake it */
	    (*free_hool)(help_buff);
	    ewclose(help_ew);
	    help_ew = 0;
	  }
	  break;
	}
      }
      else if (ew != NULL) ewevent(ew, &e, &closed);
      else wfleep();
      fixmenus();
      /* putc('#', stderr); */
      if (!pause_set) {
	if (!wpollevent(&e)) {
/* 	  putc('<', stderr); */
	  return;
	}
      }
      else wgetevent(&e);
/*       fprintf(stderr, "PollEvent: type=%d win=%p data=%d\n", e.type,e.window,e.u.command); */
    }
}

void flush_screen(void)
{
    TEXTEDIT* tp = CSL_ew->tp;
    if (stdout_n != 0) {
    /*     fprintf(stderr, stdout_buffer);  */
      ewreplace(CSL_ew, stdout_buffer);
      stdout_n = 0; stdout_p = stdout_buffer;
    }
    if (tp->nlines > max_nlines+5) { /* Allow a five line slop */
      techangefocus(tp, 0, zsubgap(tp->start[tp->nlines-max_nlines]));
      tp->aim= UNDEF;
      tp->focprev= FALSE;
/*    ewreplace(CSL_ew, ""); */
      tereplace(tp, "");
    /*    fprintf(stderr, "-> %d\n", tp->nlines); */
    /* focus to end */
      tesetfocus(tp, tp->buflen - tp->gaplen, -1);
    }
    wupdate(CSL_window);
    wflush();
}

static clock_t prev_clock = 0;

void accept_tick(void)
{
    clock_t c0 = clock();
    remove_ticker();

    if (c0 > prev_clock + CLOCKS_PER_SEC) {
/*
 * Time spent doing all of this is counted as "overhead" or "system time"
 * and not included in the times that I will report to my users...
 */
      if (clock_stack == &consolidated_time[0]) {
	consolidated_time[0] +=
	  ((double)(clock_t)(c0 - base_time))/((double)CLOCKS_PER_SEC);
	base_time = clock();
      }
      report_time((int)(100.0*consolidated_time[0]), (int)(100.0*gc_time));
    }
    push_clock();
    wupdate(CSL_window);
    poll_for_attn();
    polltick_pending = NO;
    ensure_screen();
    add_ticker();
    pop_clock();
    return;
}

static char time_string[32], space_string[32];

void report_time(int32 t, int32 gct)
{
    sprintf(time_string, "%d.%.2d secs", t/100, t%100);
    wmenusetitem(adminmenu, MMTime, time_string);
    sprintf(time_string, "+ %d.%.2d secs", gct/100, gct%100);
    wmenusetitem(adminmenu, MMOTime, time_string);
}

void report_space(int gc_count, double percent)
{
    sprintf(space_string, "[GC %d]:%.2f%%", gc_count, percent);
    wmenusetitem(adminmenu, MMSpace, space_string);
}

void pause_for_user(void)
/*
 * This is called at the end of a run so that the user gets a chance to read
 * the final screen-full of output.  It pops up a dialog box that will
 * wait for a button push.  I take the view that if output is going to a
 * file then the delay is not needed, since the user can always check for
 * messages there. This has the effect that non-interactive build sequences
 * will often run without the pause - a good thing!  Note however that this
 * mean that you MUST use the close box to exit from a wimp session. Just
 * "quit;" or "(stop 0)" will not do.
 */
{
    remove_ticker();
    ensure_screen();
    CSL_ew->saved = TRUE;       /* Fake it */
    if (spool_file != NULL) return;
/*
 * Here I just loop handling events until the user hits the CLOSE box
 * on my window.
 */
    wmessage("Leaving Reduce 3.6");
    ewclose(CSL_ew);
    wdone();
}

int wimpget(char *tty_buffer)
/*
 * This is the main call from the body of CSL into the window manager
 * to obtain input from the user.  It is expected to copy some input
 * characters into tty_buffer and return the number of characters
 * provided.  In this implementation I read the text back from the
 * stdwin textedit buffer, looking rather too low.
 *  Any type ahead is handled in here.
 */
{
    TEXTEDIT* tp = CSL_ew->tp;
    int i;
    int n;
    int lineno;
    tty_nnl = 1;                /* Offset from nlines */

    push_clock();
    remove_ticker();
    if (stdout_n != 0) flush_screen();
    wmenuattach(CSL_window, loadmenu);
    wmenuattach(CSL_window, libmenu);
    wmenuattach(CSL_window, switchmenu);
    lineno = tp->nlines-1;      /* Need to do this after the toend */
    tty_offset = tp->foc - tp->start[lineno];
    if (tty_offset<0) tty_offset += tp->gaplen;
    wmenuenable(adminmenu, MMPause, NO);
    if(tty_index>0) {
	int i = 0;
	for (; i<tty_index; i++)
	  if (tty_buff[i] == '\n') tty_nnl++;
	tty_buff[tty_index] = '\0';
	ewreplace(CSL_ew, tty_buff);
	tty_index = 0;
    }	
    event_loop();
    /*    fprintf(stderr, "Event loop ended\n");  */
    lineno = tp->nlines-tty_nnl;
/* printf("Offset=%d Length=%d\n",tty_offset,tp->foc-tp->start[lineno]-tty_offset); */
/* for (i=0; i<tp->foc- tp->start[lineno]-tty_offset; i++) { */
/*   printf("%c",  *(tegettext(tp)+tp->start[lineno]+tty_offset+i)); */
/* }  */
/* printf("\n"); */

    memcpy(tty_buffer, tegettext(tp)+tp->start[lineno]+tty_offset,
           tp->foc- tp->start[lineno]-tty_offset);
    wmenudetach(CSL_window, loadmenu);
    wmenudetach(CSL_window, libmenu);
    wmenudetach(CSL_window, switchmenu);
    wmenuenable(adminmenu, MMPause, YES);
    add_ticker();
    n = tp->foc- tp->start[lineno]-tty_offset;
    if (n<0) {
	n += tp->gaplen;
	fprintf(stderr, "N correction\n");
    }
    tty_ready = NO;
    pop_clock();
    return n;
}

int char_cnt = 0;
void putc_stdout(int c)
{
    *stdout_p++ = c;
    *stdout_p = 0;
    stdout_n++;
    char_cnt++;
    remove_ticker();
    if (c == '\n' || stdout_n > STDOUT_BUFSIZE - LONGEST_PRINTF) {
      push_clock(); flush_screen();
      if (char_cnt>200) {	/* Where 200 is a random number */
	poll_for_attn(); char_cnt = 0;
      }
      pop_clock();
    }
    add_ticker();
}

void vfprintf_stdout(char *fmt, va_list a)
{
    int n;
/*
 * I have given myself LONGEST_PRINTF locations in the array for
 * this vsprintf to fill in.  If it overflows I am in big trouble!
 */
    n = vsprintf(stdout_p, fmt, a);
    stdout_p += n;
    stdout_n += n;
    char_cnt += n;
    remove_ticker();
    if (stdout_n > STDOUT_BUFSIZE - LONGEST_PRINTF) {
      push_clock(); flush_screen();
      if (char_cnt>200) {
	poll_for_attn(); char_cnt = 0;
      }
      pop_clock();
    }
    add_ticker();
}

/* end of sysxwin.c */

