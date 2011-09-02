/*  syswxwin.c                     Copyright (C) 1989-2003 Codemist Ltd */


/*
 * Windows 95, 98, NT and 2000, XP support, using the "wxWindows" package.
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


/* Signature: 2be745d6 17-Feb-2003 */

#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>


#include "machine.h"
#include "tags.h"
#include "externs.h"
#include "read.h"
#include "cslerror.h"
#include "sys.h"
#include "cwin.h"
#ifdef TIMEOUT
#include "timeout.h"
#endif

#ifdef __WATCOMC__
#include <float.h>
#endif

#include <errno.h>

#ifdef _MSC_VER
#define strdup(x) _strdup(x)
#endif


#ifndef __linux__
static CSLbool ticker_active = NO;

void add_ticker(void)
{
    if (ticker_active) return;
    countdown = SOFTWARE_TICKS;
    ticker_active = YES;
}

void MS_CDECL remove_ticker(void)
{
    if (!ticker_active) return;
    ticker_active = NO;
}
#endif

/*
 * void poll_for_attn()
 * {
 *    kbhit();   // causes ^C to be noticed!
 * }
 */

static clock_t prev_clock = 0;

#ifdef UNIX
void accept_tick()
{
}
#else

#ifdef INITIAL_SOFTWARE_TICKS
int32 software_ticks = INITIAL_SOFTWARE_TICKS;
int32 software_tick_count = 0, prev_software_tick_count = 0;
#endif

void accept_tick(void)
{
/*
 * This is where I can put things that need to be done regularly. At
 * In particular I can poll the window manager here.
 */
/*
 * Around once per 2 seconds I update the clock display on the menu bar -
 * the intent of this is to give a bit of feedback to the user that
 * things are happening. NOTE WELL: I tune all this in terms of CPU time
 * (measured with clock()) rather than wall-clock time (time()). On
 * a multi-tasking system this means that a Lisp task running at low
 * priority in the background will hardly poll at all, and one that is
 * suspended (if such a possibility can arise) will not do a lot. But
 * I HOPE that CPU time is not consumed while one is suspended awaiting
 * keyboard input, and so that sort of delay should not cause messups
 * in my "learning" of the correct poll rate.
 */
    clock_t t0 = clock();
#ifdef SOFTWARE_TICKS_PER_SECOND
    software_tick_count++;
#endif
    if (prev_clock == 0 || t0 > prev_clock + 2*CLOCKS_PER_SEC)
    {   long int t, gct;
        Lisp_Object nil;
        ensure_screen(); nil = C_nil;
        if (exception_pending()) return;
#ifdef SOFTWARE_TICKS_PER_SECOND
        if (prev_clock != 0)
        {   double t1 = (double)(t0-prev_clock)/(double)CLOCKS_PER_SEC;
            double ratio = 
               (double)(software_tick_count - prev_software_tick_count)/t1;
            int32 w;
/*
 * t1 is how long since I was last here, ratio is the number of
 * ticks per second over that time-span.
 */
            ratio = ratio / (double)SOFTWARE_TICKS_PER_SECOND;
            prev_software_tick_count = software_tick_count;
/*
 * Now ratio is the extent by which I was taking ticks too fast.
 * To dampen out my correction I will scale software_ticks by the
 * square root of this.
 */
            ratio = sqrt(ratio);
            w = (int)(1000.0 * ratio);
/*
 * I clamp the correction factor so I never adjust my clock rate by
 * a factor of more than (about) 3.
 */
            if (w > 3000) w = 3000;
            else if (w < 300) w = 300;
/*
 * Furthermore I attempt to keep software_ticks within integer range.
 */
            if (software_ticks < (0x7fffffff/3000) &&
                software_ticks > 50)
                software_ticks = (w*software_ticks)/1000;
        }
#endif
        t0 = clock();
        if (clock_stack == &consolidated_time[0])
        {   consolidated_time[0] +=
                (double)(t0 - base_time)/(double)CLOCKS_PER_SEC;
            base_time = t0;
        }
        t = (long int)(100.0 * consolidated_time[0]);
        gct = (long int)(100.0 * gc_time);
        report_time(t, gct);
        prev_clock = t0;
    }
    cwin_poll_window_manager(0);
    if (cwin_interrupt_pending != 0)
    {   Lisp_Object nil = C_nil;
        interrupt_pending = YES;
        if (exception_pending()) nil = (Lisp_Object)((int32)nil ^ 1);
        miscflags |= HEADLINE_FLAG | MESSAGES_FLAG;
        cwin_interrupt_pending = 0;
    }
}
#endif

void putc_stdout(int c)
{
    if (alternative_stdout != NULL) putc(c, alternative_stdout);
    else cwin_putchar(c);
}

void pause_for_user(void)
{
}

int pipes_today = 0;
int win32s = 0;

void flush_screen(void)
{
    cwin_ensure_screen();
}

void start_up_window_manager(int use_wimp)
{
    CSL_IGNORE(use_wimp); /* on this platform ALWAYS use the window system */
    win32s = 0;           /* NT, 2000, XP, Linux!!! */
    pipes_today = 1;
}

int wimpget(char *buf)
{
    int c, n=0;
    Lisp_Object nil;
    ensure_screen(); nil = C_nil;
    if (exception_pending()) return 0;
    while (n < 255)
    {   c = cwin_getchar();
        nil = C_nil;
        if (exception_pending() || c == EOF) return 0;
        c = c & 0xff;
        buf[n++] = (char)c;
        if (c == '\n') break;
    };
    return n;
}


/*
 * Slightly optional jollies re GC statistics...
 */
 
static char time_string[32], space_string[32];

void report_time(int32 t, int32 gct)
{
    sprintf(time_string, "%ld.%.2ld+%ld.%.2ld secs  ",
        t/100L, t%100L, gct/100L, gct%100L);
    if ((window_heading & 1) == 0) cwin_report_left(time_string);
}

void report_space(int n, double percent)
{
    sprintf(space_string, "[GC %d]:%.2f%%", n, percent);
    if ((window_heading & 4) == 0) cwin_report_right(space_string);
}

/*
 * End of the worst of the window-manager aware code
 */

#undef exit
#define exit(a) my_exit(a)

#ifdef UNIX

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


#else

#ifdef __cplusplus
#include <afxwin.h>
#else
#include <windows.h>
#endif
#include <io.h>
#include <dos.h>
#include <direct.h>
#include <sys\stat.h>

#endif

#include "fileops.c"
#include "scandir.c"
#include "filename.c"


int change_directory(char *filename, char *old, size_t n)
{
    process_file_name(filename, old, n);
    if (*filename == 0) return 1;
#ifdef _MSC_VER
    if (_chdir(filename))
#else
    if (chdir(filename))
#endif
    {   char err_buf[LONGEST_LEGAL_FILENAME+100];
        switch (errno)
        {
    case ENOENT:  
            sprintf(err_buf,"The directory %s does not exist.",filename);
            break;
    default:
            sprintf(err_buf,"Cannot change directory to %s.",filename);
            break;
        }
        aerror0(err_buf);
        return 1;
    }
    else return 0;
}

int create_directory(char *filename, char *old, size_t n)
{
    process_file_name(filename, old, n);
    if (*filename == 0) return 1;
#ifdef UNIX
    return mkdir(filename, 0770);
#else
#ifdef _MSC_VER
    return _mkdir(filename);
#else
    return mkdir(filename);
#endif
#endif
}

CSLbool file_exists(char *filename, char *old, size_t n, char *tt)
{
#ifdef _MSC_VER
    struct _stat statbuff;
#else
    struct stat statbuff;
#endif
    process_file_name(filename, old, n);
    if (*filename == 0) return NO;
#ifdef _MSC_VER
    if (_stat(filename, &statbuff) != 0) return NO;
#else
    if (stat(filename, &statbuff) != 0) return NO;
#endif
    strcpy(tt, ctime(&(statbuff.st_mtime)));
    return YES;
}

static void remove_files(char *name, int dirp, long int size)
/*
 * Remove a file, or a directory and all its contents. This function
 * can still misbehave if you do not have write access to all the files
 * involved.
 */
{
    size = size;
    switch (dirp)
    {
case SCAN_ENDDIR:
#ifdef _MSC_VER
        _rmdir(name);  return;
#else
        rmdir(name);   return;
#endif
case SCAN_FILE:
        remove(name);  return;
    }
}

int delete_file(char *filename, char *old, size_t n)
{
    process_file_name(filename, old, n);
    if (*filename == 0) return 1;
    scan_directory(filename, remove_files);
    return 0;
}

long file_length(char *filename, char *old, size_t n)
{
#ifdef _MSC_VER
    struct _stat buf;
#else
    struct stat buf;
#endif
    process_file_name(filename, old, n); 
    if (*filename == 0) return 0;
#ifdef _MSC_VER
    if (_stat(filename,&buf) == -1) return -1;
#else
    if (stat(filename,&buf) == -1) return -1;
#endif
    return (long)(buf.st_size);
}
#ifdef UNIX

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

#else

int directoryp(char *filename, char *old, size_t n)
{
    process_file_name(filename, old, n);
    if (*filename == 0) return 0;
    return (GetFileAttributes(filename) == FILE_ATTRIBUTE_DIRECTORY);
}

#endif

#ifdef UNIX
extern char *strdup(char *s);
#endif

extern char *get_truename(char *filename, char *old, size_t n)
{
#ifdef _MSC_VER
    struct _stat buf;
#else
    struct stat buf;
#endif
    char *temp, *fn, *dir, *pwd;

    process_file_name(filename, old, n);
    if (*filename == 0) aerror("truename");

/* Find out whether we have a file or a directory.  Be careful in case
 *  the first two characters define a drive.
 */

    if (0 /* strlen(filename) > 2 && *(filename+1) == ':' */)
    {
/*
 * Again beware the fact that aerror0 does not change the flow of control.
 */
#ifdef _MSC_VER
        if (_stat(filename+2,&buf) == -1) aerror0("truename: cannot stat file");
#else
        if (stat(filename+2,&buf) == -1) aerror0("truename: cannot stat file");
#endif
    }
    else
    {
#ifdef _MSC_VER
        if (_stat(filename,&buf) == -1) aerror0("truename: cannot stat file");
#else
        if (stat(filename,&buf) == -1) aerror0("truename: cannot stat file");
#endif
    }

  /* Store current directory */
#ifdef _MSC_VER
    if ((pwd = (char *)_getcwd((char *)NULL, LONGEST_LEGAL_FILENAME)) == NULL)
#else
    if ((pwd = (char *)getcwd((char *)NULL, LONGEST_LEGAL_FILENAME)) == NULL)
#endif
        aerror0("truename: cannot get current working directory");

    if ((buf.st_mode & S_IFMT) == S_IFDIR)
    {   /* We have a directory */
        char *dir = (char*)(*malloc_hook)(LONGEST_LEGAL_FILENAME);

#ifdef _MSC_VER
        if (_chdir(filename) != 0) 
            aerror0("truename: cannot change directory");
        if (_getcwd(dir ,LONGEST_LEGAL_FILENAME) == NULL)
            aerror0("truename: cannot get current working directory");
        if (_chdir(pwd) != 0)
            aerror0("truename: cannot change directory");
#else
        if (chdir(filename) != 0) 
            aerror0("truename: cannot change directory");
        if (getcwd(dir ,LONGEST_LEGAL_FILENAME) == NULL)
            aerror0("truename: cannot get current working directory");
        if (chdir(pwd) != 0)
            aerror0("truename: cannot change directory");
#endif
        (*free_hook)(pwd);
    /* 
     * This is an axiom-specific hack --- it expects that truname
     * preserves trailing directory characters.
     */
        if (old[n-1] == '\\' || old[n-1] == '/' &&
            dir[strlen(dir)-1] != '\\')
        {   n = strlen(dir);
            dir[n] = '\\';
            dir[n+1] = '\0';
        }
        return dir;
    }
    else
    {   /* Assume we have some kind of file */
        temp = strrchr(filename,'\\');
        if (temp) 
        {   /* Found a directory component */
            fn = strdup(temp);
            *temp = '\0';
            /* fn is now "\file" and filename is the directory */

#ifdef _MSC_VER
            if (_chdir(filename) != 0)
                aerror0("truename: cannot change directory");
            if ((temp = (char *)_getcwd((char *)NULL,LONGEST_LEGAL_FILENAME)) == NULL)
                aerror0("truename: cannot get current working directory");
            if (_chdir(pwd) != 0)
                aerror0("truename: cannot change directory");
#else
            if (chdir(filename) != 0)
                aerror0("truename: cannot change directory");
            if ((temp = (char *)getcwd((char *)NULL,LONGEST_LEGAL_FILENAME)) == NULL)
                aerror0("truename: cannot get current working directory");
            if (chdir(pwd) != 0)
                aerror0("truename: cannot change directory");
#endif
            dir = (char *)(*malloc_hook)((strlen(temp) + strlen(fn) + 1)*sizeof(char));
            strcpy(dir,temp);
            (*free_hook)(temp);
            strcat(dir, fn);
            (*free_hook)(pwd);
            (*free_hook)(fn);
            return dir;
        }
        else
        {   dir = (char *)(*malloc_hook)((strlen(pwd) +
                        strlen(filename) + 2)*sizeof(char));
            strcpy(dir, pwd);
            strcat(dir, "\\");
            strcat(dir,filename);
            (*free_hook)(pwd);
            return dir;
        }
    }
}

#ifdef UNIX

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


#else

int get_current_directory(char *s, int n)
{
    int n1 = GetCurrentDirectory(n, s);
    if (n1 == 0)
    {   aerror0("cannot get current directory name");
        return 0;
    }
    else if (n1 >= n)
    {   aerror("the pathname of the current directory is too long");
        return 0;
    }
    else return n1;
}

#endif

#ifdef NAG_VERSION

#define MAX_NUMBER_OF_FILES 2048

int list_directory_members(char *filename, char *old, char **filelist[],
                           size_t n)
{   WIN32_FIND_DATA fileData;
    HANDLE fileHandle;
    int32 number_of_entries = 1;
    char **files;

    process_file_name(filename, old, n);

    if (*filename == 0) strcpy(filename,"*.*");
    else if (filename[strlen(filename)-1] != '\\')
        filename=strcat(filename,"\\*.*");
    else filename=strcat(filename,"*.*");
    
    fileHandle = FindFirstFile(filename,&fileData);
    
    if (fileHandle == INVALID_HANDLE_VALUE) return 0;

/*
 * The fixed allocation size here seems unsatisfactory, but I will leave it
 * like that for the moment because altering things to behave better would
 * probably involve redesigning the interface to this function.
 */
    files=(char **)(*malloc_hook)(MAX_NUMBER_OF_FILES*sizeof(char *));
    files[0]=strdup(fileData.cFileName);

    while(FindNextFile(fileHandle,&fileData))
    {   files[number_of_entries] = strdup(fileData.cFileName);
        number_of_entries++;
    }

    FindClose(fileHandle);

    *filelist = files;

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

/*
 * The following few lines are an attempt to provide compatibility
 * between Watcom C 11.0 and Microsoft Visual C++ version 5... Both provide
 * a stat() function but they use different names for the bits that
 * can be used to test if files are readable or writable.
 */

#ifndef S_IRUSR
#define S_IRUSR _S_IREAD
#endif
#ifndef S_IWUSR
#define S_IWUSR _S_IWRITE
#endif

int file_readable(char *filename, char *old, size_t n)
{
#ifdef _MSC_VER
    struct _stat buf;
#else
    struct stat buf;
#endif
    process_file_name(filename, old, n);
    if (*filename == 0) return 0;
#ifdef _MSC_VER
    if (_stat(filename,&buf) == -1)
#else
    if (stat(filename,&buf) == -1)
#endif
      return 0; /* File probably does not exist */
    else
        return (buf.st_mode & S_IRUSR);
}

int file_writeable(char *filename, char *old, size_t n)
{
#ifdef _MSC_VER
    struct _stat buf;
#else
    struct stat buf;
#endif
    process_file_name(filename, old, n);
    if (*filename == 0) return 0;
#ifdef _MSC_VER
    if (_stat(filename,&buf) == -1)
#else
    if (stat(filename,&buf) == -1)
#endif
      return 0; /* Should we check to see if the directory is writeable? */
    else
        return (buf.st_mode & S_IWUSR);
}

int rename_file(char *from_name, char *from_old, size_t from_size,
                char *to_name, char *to_old, size_t to_size)
{
    process_file_name(from_name, from_old, from_size);
    process_file_name(to_name, to_old, to_size);
    if (*from_name == 0 || *to_name == 0) return 0;
    return rename(from_name,to_name);
}

#ifdef UNIX

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

#else
/*
 * It appears to me that "system" as provided by the Windows NT SDK
 * libraries is a real mess.  This is perhaps because executing a
 * command might want to generate terminal output, so when one invokes
 * "system" it first pops up a console window running the command
 * interpreter, then loads the thing you wanted executed, and then
 * closes everything down - probably before you have had any real
 * chance to observe any output that was generated.  I might therefore
 * want to invent a version of my own... as in here using CreateProcess.
 * The issues about Win32 vs Win32s incompatibilities here are HORRID.
 */
 

static HANDLE osRunRedirect(char *cmd, BOOL wait, HANDLE hin,
                            HANDLE hout, HANDLE herr);
static HANDLE osMakeReadPipe(char *cmd, HANDLE *);
static char *osMangleCommand(char *s);

int my_system(char *s)
{
    HANDLE h, hproc;
    DWORD  retCode;
    char buf[256];
    char *os;
    DWORD nread;
    BOOL done = FALSE;
        
    os = s;
    s = osMangleCommand(s);
    h = osMakeReadPipe(s, &hproc);
    if (s != os) free(s);
    if (h==NULL)
    {   term_printf("Failed: %d\n", GetLastError());
        CloseHandle(hproc);
        return 0;
    }

    while (!done)
    {   DWORD i;
        BOOL res;
        res = ReadFile(h, (void*) buf, 256, &nread, NULL);
        if (res == TRUE && nread == 0 && 
            GetExitCodeProcess(hproc, &retCode) != STILL_ACTIVE) 
        {   done = TRUE;
        }
        else if (!res)
        {   int err = GetLastError();
            if (GetExitCodeProcess(hproc, &retCode) == STILL_ACTIVE) 
            {   term_printf("Error: %d\n", err);
                CloseHandle(hproc);                                
                CloseHandle(h);
                return -1;
            }
            return retCode;
        }
        else
        {   for (i=0; i<nread; i++)
            {   if (buf[i] != '\r')
                {   stdout_printf("%c", buf[i]);
                }
            }
        }
    }
    GetExitCodeProcess(hproc, &retCode);
    return retCode;
}

static HANDLE osMakeReadPipe(char *cmd, HANDLE *proc)
{
    HANDLE hwr, hwr2, hrd, hproc;
    SECURITY_ATTRIBUTES attribs;
    BOOL ret;

    attribs.nLength = sizeof(attribs);
    attribs.lpSecurityDescriptor = NULL;
    attribs.bInheritHandle = TRUE;
    if (!CreatePipe(&hrd,       /* address of variable for read handle */
                    &hwr,       /* address of variable for write handle */
                    &attribs,   /* Security sillyness */
                    0)) return NULL;
    hproc = GetCurrentProcess();
    ret = DuplicateHandle(hproc, hwr,          /* Source */
                          hproc, &hwr2,        /* Target */
                          0,                   /* Desired access */
                          TRUE,                /* Inherit */
                          DUPLICATE_SAME_ACCESS);
    if (!ret)
    {   CloseHandle(hrd);
        CloseHandle(hwr);
        return NULL;
    }
        
    hproc = osRunRedirect(cmd, FALSE, NULL, hwr, hwr2);
    CloseHandle(hwr);
    CloseHandle(hwr2);
    if (hproc == NULL) return NULL;
    *proc = hproc;
    return hrd;
}

static HANDLE osRunRedirect(char *cmd, BOOL wait, HANDLE hin, 
                            HANDLE hout, HANDLE herr)
{
    static STARTUPINFO si;
    static PROCESS_INFORMATION pi;
    BOOL rc;

    rc = TRUE;

    if (!rc) term_printf("Ooops!");
    /* Create process. */
    memset(&si, 0, sizeof(si));
    si.cb                = sizeof(si);
    si.lpReserved        = NULL;
    si.lpDesktop         = NULL;
    si.lpTitle           = "!";
    si.cbReserved2       = 0;
    si.lpReserved2       = NULL;
    si.dwFlags           = STARTF_USESTDHANDLES;
    si.hStdInput         = hin;
    si.hStdOutput        = hout;
    si.hStdError         = herr;

    rc = CreateProcess(NULL, cmd, NULL, NULL, 
                       TRUE,
                       DETACHED_PROCESS/*|NORMAL_PRIORITY_CLASS*/,
                       NULL, NULL, 
                       &si, &pi);
    if (rc == FALSE) return NULL;

    if (wait == TRUE)
    {   rc = WaitForSingleObject(pi.hProcess, INFINITE);
        if (rc == WAIT_FAILED) return NULL;
    }

    return pi.hProcess;
}

/* Expand any environment variables inside s */
static char *osFindEnvVar(char *s, int idx, int *new_idx)
{
    char *var, c;
    int j=idx;
    while (isalnum(s[j])) j++;
    if (j==idx) return NULL;
    c = s[j];
    s[j] = '\0';

    *new_idx = j;
    var = getenv(s+idx);
    s[j] = c;
    return var;
}

static char *osMangleCommand(char *s)
{
    char *var, *res;
    int  i, j, o, len;

    len = strlen(s);

    o = i = 0; res = s; 
    while (s[i] != '\0') 
    {   int new_i;
        if (s[i] == '$' && (var = osFindEnvVar(s, i+1, &new_i)) != NULL)
        {   /* Get new space */
            int lv = strlen(var);
            char *nres = (char *) malloc(o + lv + len - i + 1);
            for (j=0; j<o; j++) nres[j] = res[j];
            if (res != s) free(res);
            res = nres;
            for (j=0; j<lv; j++) res[o++] = var[j];
            i = new_i;
        } 
        else if (res != s) res[o++] = s[i++];
        else
        {   i++;
            o++;
        }
    }
    if (res != s) res[o] = s[i];

    return res;
}

HWND gnuplot_handle = 0;

BOOL CALLBACK find_text(HWND h, LPARAM x)
{
    char buffer[24];
    CSL_IGNORE(x);
    GetClassName(h, buffer, 20);
    if (strcmp(buffer, "wgnuplot_text") != 0) return TRUE;
    gnuplot_handle = h;
    return FALSE;
}

FILE *my_popen(char *command, char *direction)
{
/*
 * Here I take a pretty shameless direction and spot the special case of
 * opening an output pipe to gnuplot... and hook in a behind-the-scenes
 * way.
 */
    int i = 0, j;
    for (;;)
    {   char *name = "gnuplot";
        j = i;
        while (*name && tolower(command[j++]) == *name) name++;
        if (*name == 0)
        {   HWND parent = 0;
#ifdef OLD_API
            if (WinExec(command, SW_SHOWMINIMIZED) <= 32) return 0;
#else
/*
 * Win32 would rather I used the following long-winded version, which provides
 * a pile of generality that is irrelevant here!
 */
            STARTUPINFO startup;
            PROCESS_INFORMATION process;
            clock_t t0, t1;
            memset(&startup, 0, sizeof(STARTUPINFO));
            startup.cb = sizeof(startup);
            startup.lpReserved = NULL;
            startup.lpDesktop = NULL;
            startup.lpTitle = NULL;
            startup.dwFlags = STARTF_USESHOWWINDOW;
            startup.wShowWindow = SW_SHOWMINIMIZED;
            startup.cbReserved2 = 0;
            startup.lpReserved2 = NULL;
            if (!CreateProcess(NULL, command, NULL, NULL, FALSE,
                               0, NULL, NULL, &startup, &process)) return 0;
#endif
            gnuplot_handle = 0;
            t0 = clock();
            for (i=0; i<25; i++)  /* Give it 5 seconds to appear */
            {   parent = FindWindow((LPSTR)"wgnuplot_parent",
                                    (LPSTR)"gnuplot");
                if (parent != 0) break;
                t0 += CLOCKS_PER_SEC/5;
                while ((t1 = clock()) < t0) cwin_poll_window_manager(0);
                t0 = t1;
            }
            if (parent != 0)
            {   for (i=0; i<10; i++)   /* 2 more seconds for the child */
                {   EnumChildWindows(parent, find_text, 0);
                    if (gnuplot_handle != 0) break;
                    t0 += CLOCKS_PER_SEC/5;
                    while ((t1 = clock()) < t0) cwin_poll_window_manager(0);
                    t0 = t1;
                }
            }
            return (FILE *)-1;  // special handle for the gnuplot pipe
        }
        i++;
        if (command[i] == 0) break;
    }
#ifdef __WATCOMC__
    CSL_IGNORE(command); CSL_IGNORE(direction);
    return 0;
#else
    return _popen(command, direction);    
#endif
}

int my_pipe_putc(int c, FILE *f)
{
    if (f == (FILE *)(-1))
    {   if (gnuplot_handle == 0) return EOF;
        if (c == '\n') c = '\r';
        SendMessage(gnuplot_handle, WM_CHAR, c, 1L);
        return c;
    }
    else return putc(c, f);
}

int my_pipe_flush(FILE *f)
{
    if (f != (FILE *)(-1)) return fflush(f);
    return 0;
}

void my_pclose(FILE *stream)
{
    if (stream == (FILE *)(-1))
    {   SendMessage(gnuplot_handle, WM_CHAR, 'q', 1L);
        SendMessage(gnuplot_handle, WM_CHAR, 'u', 1L);
        SendMessage(gnuplot_handle, WM_CHAR, 'i', 1L);
        SendMessage(gnuplot_handle, WM_CHAR, 't', 1L);
        SendMessage(gnuplot_handle, WM_CHAR, '\r', 1L);
        return;
    }
#ifdef __WATCOMC__
    CSL_IGNORE(stream);
#else
    _pclose(stream);
#endif
}

#endif /* UNIX */

char *my_getenv(char *s)
{
/*
 * Case fold for MSDOS
 */
    char uppercase[LONGEST_LEGAL_FILENAME];
    int c;
    char *p = uppercase;
    while ((c = *s++) != 0) *p++ = (char)toupper(c);
    *p = 0;
    s = uppercase;
    return getenv(s);
}

/*
 * MSDOS does not support the idea of home directories for
 * users, so in case anybody still wants to use the notation "~" that
 * would indicate a home directory under Unix I implement something
 * in terms of environment variables.
 */

int get_home_directory(char *b, int len)
{
/*
 * Worry about "len" here...
 */
    char *w = my_getenv("home");
    if (w != NULL) strcpy(b, w);
    else strcpy(b, ".");
    return strlen(b);
}

int get_users_home_directory(char *b, int len)
{
/*
 * Worry about "len" here...
 */
    char *w, h[LONGEST_LEGAL_FILENAME];
    sprintf(h, "home$%s", b);
    w = my_getenv(h);
    if (w != NULL) strcpy(b, w);
    else strcpy(b, ".");
    return strlen(b);
}

/*
 * The next bit of mess is jolly - I just want to see if stdin has been
 * redirected to come from a file, i.e. whether I am interactive in some
 * sense.  This may be used to decide what to do about error reports etc.
 * The IDEA seems generic across most systems, but the details vary in
 * frustrating ways.
 */


int batchp(void)
{
    return 0;   /* !isatty(stdin->_file); */
}

/*
 * The next procedure is responsible for establishing information about
 * where the main checkpoint image should be recovered from, and where
 * and fasl files should come from.
 */
char *find_image_directory(int argc, char *argv[])
{
    char *w;
    int i = strlen(cwin_full_program_name), j;
    strcpy(program_name, programName);
    CSL_IGNORE(argc); CSL_IGNORE(argv);
/*
 * If the current program is called c:\aaa\xxx.exe, then I look
 * for a file c:\aaa\xxx.img
 */
    w = (char *)(*malloc_hook)(i+1);
    if (w == NULL)
    {   fprintf(stderr, "\n+++ Panic - run out of space\n");
        my_exit(EXIT_FAILURE);
    }
    strcpy(w, cwin_full_program_name);
/*
 * Windows file-names are not case-sensitive when you search, but
 * I think names look neater in lower case so I force things here.
 */
    for (j=i-4; j>=0; j--)
    {   if (w[j] == '\\' || w[j] == '/') break;
        w[j] = (char)tolower(w[j]);
    }
    w[i-3] = 'i';
    w[i-2] = 'm';
    w[i-1] = 'g';
    return w;
}

CSLbool sigint_must_longjmp = NO;
jmp_buf sigint_buf;

void MS_CDECL sigint_handler(int code)
{
    CSL_IGNORE(code);
    interrupt_pending = 1;
    if (sigint_must_longjmp)
    {   sigint_must_longjmp = 0;
        longjmp(sigint_buf, 1);
    }
    return;
}

/*
 * The following function controls memory allocation policy
 */

#ifdef UNIX

int32 ok_to_grab_memory(int32 current)
{
#ifdef COMMON
    return current;
#else
    return 3*current + 2;
#endif
}

#else
int32 ok_to_grab_memory(int32 current)
{
    MEMORYSTATUS w;
    memset(&w, 0, sizeof(w));
    w.dwLength = sizeof(w);
    GlobalMemoryStatus(&w);
#ifdef NOT_CONFIDENT_ENOUGH_HIDE_THIS_TRASH
    term_printf("memStats %d %d %d %d %d %d %d %d\n",
       w.dwLength, 
       w.dwMemoryLoad, 
       w.dwTotalPhys,     w.dwAvailPhys,
       w.dwTotalPageFile, w.dwAvailPageFile, 
       w.dwTotalVirtual,  w.dwAvailVirtual);
#endif
    if (w.dwTotalPhys == 0)
    {
#ifdef COMMON
        return current;
#else
        return 3*current + 2;
#endif
    }
    else
/*
 * Here we seem to be running under win32 (not win32s) and can measure how
 * much memory is currently available for this process. I will grab space
 * until win32 is using all the physical memory there is. After that I will
 * tend to grow much more cautiously.
 */
    {   int32 freemem = w.dwAvailPhys / CSL_PAGE_SIZE;
        if (freemem == 0) return current / 2 + 1;
        if (freemem > 3*current + 2) freemem = 3*current + 2;
        return freemem;
    }
}

#endif

/* end of syswxwin.c */

