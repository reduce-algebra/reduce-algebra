/*  sysunix.c                       Copyright (C) 1989-2002 Codemist Ltd */

/*
 * General Unix system-specific code
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


/* Signature: 3035e8da 08-Apr-2002 */

#include "machine.h"

#include <sys/stat.h>

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
#ifndef HP_UNIX
/*
 * This symbol seems not to be available under HP versions of Unix.
 * Since I am just producing pretty error messages here the loss of
 * functionality missing it out is pretty minor...
 */
    case ELOOP:
            msg = "Pathname %s has too many symbolic links.";
            break;
#endif
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
    return mkdir(filename, 0770);
}

static void remove_files(char *name, int dirp, long int size)
/* Remove a file, or a directory and all its contents */
{
    switch (dirp)
    {
case 0:               /* SCAN_FILE */
      remove(name);
      return;
case 2:               /* SCAN_ENDDIR */
      rmdir(name);
      return;
default:              /* 1 == SCAN_STARTDIR */
      return;
    }
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

/* extern char *getcwd(char *s, size_t n); in case unistd not used */

int get_current_directory(char *s, int n)
{
#ifdef NO_GETCWD
    aerror0("cannot get current directory name.");
    *s = 0;
    return 0;
#else
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
#endif
}

long file_length(char *filename, char *old, size_t n)
{
    struct stat buf;
    process_file_name(filename, old, n); 
    if (*filename == 0) return 0;
    if (stat(filename,&buf) == -1) return -1;
    return (long)(buf.st_size);
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

#ifndef S_ISLNK
# ifdef S_IFLNK
#  ifdef S_IFMT
#   define S_ISLNK(m) (((m) & S_IFMT) == S_IFLNK)
#  endif
# endif
#endif

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
        char *dir = (char*)(*malloc_hook)(LONGEST_LEGAL_FILENAME);
        if (chdir(filename) != 0) 
            aerror0("truename: cannot change directory");
        if (getcwd(dir,LONGEST_LEGAL_FILENAME) == NULL)
            aerror0("truename: cannot get current working directory");
        if (chdir(pwd) != 0)
            aerror0("truename: cannot change directory");
        (*free_hook)(pwd);
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
            fn   = (char *)(*malloc_hook)(1+strlen(temp));
            strcpy(fn, temp); /* strdup(temp); */
            *temp = '\0';
            /* fn is now "/file" and filename is the directory */

            if (chdir(filename) != 0)
                aerror0("truename: cannot change directory");
/* /* getcwd(NULL,...) invalid */
            if ((temp = (char *)getcwd((char *)NULL,LONGEST_LEGAL_FILENAME)) == NULL) 
                aerror0("truename: cannot get current working directory");
            if (chdir(pwd) != 0)
            dir = (char *)malloc((strlen(temp) + strlen(fn) + 1)*sizeof(char));
            if (dir == NULL)
            {   aerror0("truename: malloc failed");
                (*free_hook)(fn);
                return NULL;
            }
                aerror0("truename: cannot change directory");
            dir = (char *)(*malloc_hook)((strlen(temp) + strlen(fn) + 1)*sizeof(char));
/* /*
 * No check for malloc failure...
 */
            strcpy(dir, temp);
            (*free_hook)(temp);
            (*free_hook)(pwd);
            strcat(dir, fn);
            (*free_hook)(fn);
            return dir;
        }
        else
        {   dir = (char *)(*malloc_hook)((strlen(pwd) + strlen(filename) + 2)*sizeof(char));
/* /* No check for malloc failure */
            strcpy(dir,pwd);
            strcat(dir, "/");
            strcat(dir, filename);
            (*free_hook)(pwd);
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
        (*free_hook)(namelist[i]);
    }

    (*free_hook)(namelist);

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

#ifndef DO_NOT_USE_GETUID
/*
 * "machine.h" should set DO_NOT_USE_GETUID if that function is not
 * properly available. Not having it will make the treatment of
 * (eg) "~xxx/..." in filenames less satisfactory.
 */

#include <pwd.h>

int get_home_directory(char *b, int len)
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


void accept_tick()
{
}

#ifdef __kcm

extern int _ttyhandle;

int batchp()
{
    return (_ttyhandle != 0);
}

#else
#ifdef NCC_LIB

int batchp()
{
    extern int _fisatty(FILE*);
    return !_fisatty(stdin);
}

#else
#if BSD_LIB
int batchp()
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
 * If the main reduce executable is has a full path-name /xxx/yyy/zzz then
 * I will try to make /xxx/yyy/zzz.img the default image file. To do
 * this I need to find the full path for the executable. I ATTEMPT to follow
 * the bahaviour of "sh", "bash" and "csh".  But NOTE WELL that if anybody
 * launches this code in an unusual manner (eg using an "exec" style
 * function) that could confuse it substantially. Thus users are expected
 * EITHER to run this code directly via the shell OR to provide explicit
 * command-line options specifying what image files should be used.
 */
    char *myname = argv[0];
/*
 * If the name of the executable starts with a "/" it is already an
 * absolute path name. I believe that if the user types (to the shell)
 * something like $REDUCE/bin/reduce or ~user/subdir/csl then the environment
 * variable or user-name key gets expanded out by the shell before the command
 * is actually launched.
 */
    if (myname == NULL || myname[0] == 0) pgmname[0] = 0;
    else if (myname[0] == '/')
    {
#ifdef TRACE_NAME
        printf("Absolute path executable %s\n", myname);
#endif
        strcpy(pgmname, myname);
    }
    else
    {   int n;
        for (w=myname; *w!=0; w++)
            if (*w == '/') break;
/*
 * Now if the program name has a "/" anywhere within it it is treated as
 * a path starting from the current directory.
 */
        if (*w == '/')
        {
            if (myname[0] == '.' && myname[1] == '/') myname += 2;
#ifdef TRACE_NAME
            printf("local path with \"/\" in it %s\n", myname);
#endif
            n = get_current_directory(pgmname, sizeof(pgmname));
            if (n + strlen(myname) + 2 >= sizeof(pgmname) ||
                pgmname[0] == 0)
                pgmname[0] = 0;
                /* Current dir unavailable or full name is too long */
            else
            {   pgmname[n] = '/';
                strcpy(&pgmname[n+1], myname);
#ifdef TRACE_NAME
                printf("Full name: %s\n", pgmname);
#endif
            }
        }
        else
        {   char *path = my_getenv("PATH");
/*
 * I omit checks for names of shell built-in functions, since my code is
 * actually being executed by here. So I get my search path and look
 * for an executable file somewhere on it. I note that the shells back this
 * up with hash tables, and so in cases where "rehash" might be needed this
 * code may become confused.
 */
            struct stat buf;
            uid_t myuid = geteuid(), hisuid;
            gid_t mygid = getegid(), hisgid;
            int protection;
            int ok = 0;
            if (path != NULL)
            {   while (*path != 0)
                {   while (*path == ':') path++;
                    n = 0;
                    while (*path != 0 && *path != ':') pgmname[n++] = *path++;
/* Here I have separated off the next segment of my PATH */
                    pgmname[n++] = '/';
                    strcpy(&pgmname[n], myname);
#ifdef TRACE_NAME
                    printf("Try looking for %s\n", pgmname);
#endif
                    if (stat(pgmname, &buf) == -1) continue;
                    hisuid = buf.st_uid;
                    hisgid = buf.st_gid;
                    protection = buf.st_mode;
#ifdef TRACE_NAME
                    printf("uids %d %d  gids %d %d protection %o\n",
                       myuid, hisuid, mygid, hisgid, protection);
#endif
/*
 * I now want to check if there is a file of the right name that is
 * executable by the current (effective) user.
 */
                    if (protection & S_IXOTH ||
                        mygid == hisgid && protection & S_IXGRP ||
                        myuid == hisuid && protection & S_IXUSR)
                    {   ok = 1;
                        break;
                    }
                }
            }
            if (ok)
            {
#ifdef TRACE_NAME
                printf("Success %s\n", pgmname);
#endif
            }
            else pgmname[0] = 0;
        }
    }       
#ifndef DO_NOT_FOLLOW_SYMBOLIC_LINKS
#ifdef S_ISLNK
/*
 * Now if I have a program name I will try to see if it is a symbolic link
 * and if so I will follow it.
 */
    if (pgmname[0] != 0)
    {   struct stat buf;
        int n1;
        if (lstat(pgmname, &buf) != -1 &&
            S_ISLNK(buf.st_mode) &&
            (n1 = readlink(pgmname, image, sizeof(image)-1)) > 0)
        {   image[n1] = 0;
#ifdef TRACE_NAME
            printf("Symbolic link to: %s\n", image);
#endif
            strcpy(pgmname, image);
        }
    }
#endif /* S_ISLNK */
#endif /* DO_NOT_FOLLOW_SYMBOLIC_LINKS */

    if (pgmname[0] == 0)
    {
/*
 * If I could not find the name of the current executable I will
 * look in a shell variable "reduceimg". If that is not set I will
 * really consider that I have failed and use an image "csl.img" in the
 * current dircectory.
 */
        w = my_getenv("reduceimg");
        if (w != NULL) strcpy(image, w);
        else strcpy(image, "csl.img");
    }
    else
    {   strcpy(image, pgmname);
/*
 * If the fully-rooted name of the program was available I just
 * append ".img" to get the default image name.
 */
        w = image + strlen(image);
        strcpy(w, ".img");
    }
#ifdef OLD_CODE_NOW_REPLACED
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

#endif /* OLD_CODE_NOW_REPLACED */

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

/* end of sysunix.c */
