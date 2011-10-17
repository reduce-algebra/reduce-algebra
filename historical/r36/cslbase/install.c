/*
 * Installation code for REDUCE in the Codemist CSL version.  This
 * code is intended for use with MSDOS, and is compiled with
 * Zortech C release 3.0
 *
 * Compile with:
 *    ztc -mc -DMS_DOS=1 install.c
 */

/*
 * Copyright (C) 1992, Codemist Ltd.
 * This code has been modelled after suggestions from Jed Marti
 */

/* Signature: 351e7887 29-Mar-1994 */

/*
 * Here, right at the top of this program, I give a list of the
 * files that are to be unpacked.
 */
 
typedef struct arch
{
    char *name;
    int loaded;
} arch;

static arch archives[] =
{
    {"EXE286.CAR",   0},   /* 0 */
    {"EXE386.CAR",   0},   /* 1 */
    {"OBJS286.CAR",  0},   /* 2 */
    {"SMAL286.CAR",  0},   /* 3 */
    {"OBJS386.CAR",  0},   /* 4 */
    {"SMAL386.CAR",  0},   /* 5 */
    {"SOURCE1.CAR",  0},   /* 6 */
    {"SOURCE2.CAR",  0},   /* 7 */
    {"SOURCE3.CAR",  0},   /* 8 */
    {"SOURCE4.CAR",  0},   /* 9 */
    {"GNUPLOT1.CAR", 0},   /* 10 */
    {"GNUPLOT2.CAR", 0},   /* 11 */
    {"IMG1.CAR",     0},   /* 12 */
    {"IMG2.CAR",     0},   /* 13 */
    {"DOCS1.CAR",    0},   /* 14 */
    {"DOCS2.CAR",    0},   /* 15 */
    {"XLOG1.CAR",    0},   /* 16 */
    {"XLOG2.CAR",    0},   /* 17 */
    {"XMPL1.CAR",    0},   /* 18 */
    {"XMPL2.CAR",    0},   /* 19 */
    {"README.CAR",   0}    /* 20 */
};

#define NARCHIVES (sizeof(archives)/sizeof(archives[0]))

#define O_EXE286   0
#define O_EXE386   1
#define O_OBJS286  2
#define O_SMAL286  3
#define O_OBJS386  4
#define O_SMAL386  5
#define O_SOURCE1  6
#define O_SOURCE2  7
#define O_SOURCE3  8
#define O_SOURCE4  9
#define O_GNUPLOT1 10
#define O_GNUPLOT2 11
#define O_IMG1     12
#define O_IMG2     13
#define O_DOCS1    14
#define O_DOCS2    15

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <signal.h>
#include <setjmp.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include <disp.h>   /* The Zortech C fast screen-output package */
#include <conio.h>  /* unbuffered keyboard input etc */
#include <direct.h> /* for mkdir() to create directories */
#include <dos.h>    /* so that I can select which drive is current */

#define EXTRACT 1
#define INSTALL 1

static jmp_buf escape_buffer;

static void ctrl_c_handler(int n)
{
    longjmp(escape_buffer, 1);
}

static void show_txt(int row, int col, char *msg);

#include "car.c"    /* File decompression technology */

#define white_on_blue  0x17
#define white_on_black 0x07
#define black_on_white 0x70

/*
 * filep(dr, fn) - returns nonzero if drive dr and file name exists, 0 if not.
 */

static FILE *filep(char *dr, char *fn)
{
    char fname[256];
    FILE *fh;
    sprintf(fname, "%s%s\0", dr, fn);
    return fopen(fname, "rb");
}

/*
 * There is a smallish area in the middle of the screen that I
 * actually use here - clear it to the background colour (blue) that
 * I am using.
 */

static void clear_work_area()
{
    disp_fillbox(256*white_on_blue + ' ', 7, 11, 18, 68);
}

static void show_txt(int row, int col, char *msg)
{
    int c, l = col;
    disp_move(row, col);
    while ((c = *msg++) != 0)
    {   if (c == '\n')
        {   while (l <= 68)
            {   disp_putc(' ');
                l++;
            }
            disp_move(++row, col);
            l = col;
        }
        else
        {   disp_putc(c);
            l++;
        }
    }
}

/*
 * This routine asks the use a question.  The question is passed as
 * MSG and it will ask the user to type in a value.  The default
 * will be provided in VAL, and that will be what is used if the user
 * just hits ENTER.  maxlen indicates the size of the VAL buffer, so
 * that (with luck) I can avoid overwriting things.  The message HELP
 * is displayed so that the user understands what the question is
 * supposed to be about.  Returns non-zero if user wants to give up.
 */

static int request_string(int maxlen, char *msg, char *help,
                          char *val, char *dflt)
{
    int i, j, hwm;

    clear_work_area();
    disp_setattr(white_on_black);
    show_txt(8, 11, msg);
    show_txt(12, 11, help);
    disp_setattr(black_on_white);

    strcpy(val, dflt);
    show_txt(10, 16, val);
    hwm = i = strlen(val);
    disp_move(10, 16+i);
    disp_flush();
    for (;;)
    {   int c = getch();
        if (c == 0) c = 0x100 + getch(); /* Extended character */
        switch (c)
        {
    case 0x03:
    case 0x1b:         /* ^C and ESC */
            return 1;
    case 0x08:         /* backspace deletes char before the cursor */
            if (i == 0) continue;
            i--;
    case 0xff:
    case 0x100+'S':    /* DELete deletes char at cursor */
            if (i == hwm) continue;
            disp_move(10, 16+i);
            hwm--;
            for (j=i; j<hwm; j++)
            {   int c = val[j+1];
                disp_putc(c);
                val[j] = c;
            }
            disp_setattr(white_on_blue);
            disp_putc(' ');
            disp_setattr(black_on_white);
            disp_move(10, 16+i);
            disp_flush();
            continue;
    case '\r':
    case '\n':         /* ENTER */
            hwm--;     /* I truncate off any trailing blanks here */
            while (hwm!=0 && val[hwm]==' ') hwm--;
            val[hwm+1] = 0;
            return 0;
    case 0x100+'R':    /* Insert */
            if (hwm >= maxlen) continue;
            hwm++;
            for (j=hwm; j>i; j--) val[j] = val[j-1];
            val[i] = ' ';
            disp_move(10, 16+i);
            for (j=i; j<hwm; j++) disp_putc(val[j]);
            disp_move(10, 16+i);
            continue;
    case 0x100+'K':    /* Left arrow */
            if (i == 0) continue;
            i--;
            disp_move(10, 16+i);
            disp_flush();
            continue;
    case 0x100+'M':    /* Right arrow */
            if (i == hwm) continue;
            i++;
            disp_move(10, 16+i);
            disp_flush();
            continue;
    case 0x100+'G':    /* Home - reinstate default text */
            disp_move(10, 16);
            disp_setattr(white_on_blue);
            for (j=0; j<hwm; j++) disp_putc(' ');
            disp_setattr(black_on_white);
            strcpy(val, dflt);
            show_txt(10, 16, val);
            hwm = i = strlen(val);
            disp_move(10, 16+i);
            disp_flush();
            continue;
    default:
            if (c >= 0x100) continue; /* Ignore extended chars */
            if (i < maxlen)
            {   val[i++] = c;
                disp_putc(c);
                disp_flush();
                if (i > hwm) hwm = i;
            }
            continue;
        }
    }
}

/*
 * request_char is like request_string, except that the input needed from
 * the user will be just one character long.  The result is dumped into the
 * first character of VAL.
 */

static int request_char(char *msg, char *help, char *val)
{
    clear_work_area();

    disp_setattr(white_on_black);
    show_txt(8, 11, msg);
    show_txt(12, 11, help);
    disp_setattr(black_on_white);
    show_txt(10, 16, val);
    disp_move(10, 16);
    disp_flush();
    for (;;)
    {   int c = getch();
        switch (c & 0x7f)
        {
    case 0x03:
    case 0x1b:         /* ^C and ESC */
            return 1;
    case '\r':
    case '\n':         /* ENTER */
            return 0;
    case 0x08:
    case 0x7f:         /* backspace and DELete - mapped to blank */
            c = ' ';
    default:
            c = toupper(c);
            val[0] = c;
            disp_move(10, 16);
            disp_putc(c);
            disp_move(10, 16);
            disp_flush();
            continue;
        }
        break;
    }
    return 0;
}

/*
 * request_ok() displays the given message and just waits for the user
 * to press any (printing) key.  It is used for diagnostic messages and
 * similar reports.
 */

static void request_ok(char *help)
{
    clear_work_area();

    disp_setattr(white_on_black);
    show_txt(8, 11, "Press a key (e.g. ENTER) to continue\n");
    show_txt(12, 11, help);
    disp_move(10, 16);
    disp_flush();
    (void)getch();     /* All characters behave the same here */
}

/*
 * This is an interface to code found in the #included file "car.c"
 * that contains the Codemist file compression code and archive
 * utility.  It sets up various workspace and invokes file decompression.
 */
 
static void decompress_files()
{
    int32 i;
    for (i=0; i<PREDICTION_SIZE; i++)
    {   prediction1[i] = ' ';
        prediction2[i] = '\n';
    }
    memcpy(current_frequencies, default_frequencies,
           sizeof(default_frequencies));

    CRC = 1;
    while (extract_files()) continue;

    {   unsigned32 calculated_CRC = CRC;
        unsigned32  stored_CRC = get4(); /* WARNING: get4() changes CRC! */
        if (calculated_CRC != stored_CRC)
            fprintf(stderr, "Warning: CRC failure - archive may be corrupt\n");
    }
    fclose(archive_file);
}

static int install(int default_source)
{
    int cpu = cputype();              /* Used to select version to install */
    char *xdir, sdrive[4], dest[48], yes_no[4];
    char msg[1000], fname[256];
    int i, l, c, something_found;
    int disable_exe = 0, want_exe = 1, want_doc = 1,
        want_src = 1, want_gnuplot = 1;

    if (cpu < 2)
    {   request_ok("Unsuitable computer - can not install REDUCE\n"
"REDUCE needs at least an 80286 computer (and if you\n"
"have an 80386 or 80486 a faster version will be\n"
"installed for you). This machine seems to be an 8086\n"
"or 80186. You will not be allowed to install\n"
"executable binaries, but can load sources or docs\n");
        disable_exe = 1;
    }
    if (cpu < 3) archives[O_EXE386].loaded = 1,
                 archives[O_OBJS386].loaded = 1,
                 archives[O_SMAL386].loaded = 1,
                 xdir = "csl286";
    else archives[O_EXE286].loaded = 1,
         archives[O_OBJS286].loaded = 1,
         archives[O_SMAL286].loaded = 1,
         xdir = "csl386";
    
    for (;;)
    {   if (disable_exe) want_exe = 0;
        else
        {   for (;;)
            {   sprintf(yes_no, "Y");
                if (request_char(
"Do you want to install executable binaries?\n",
"If you select Y and type ENTER then executable binaries\n"
"for REDUCE will be installed onto your hard disc. If you\n"
"type N and then ENTER binaries will not be installed.\n"
"The binary files involved will be called r35.exe and\n"
"r35.img\n", yes_no)) goto abandon;
                c = toupper(yes_no[0]);
                if (c == 'Y' || c == 'N') break;
            }
            want_exe = (c == 'Y');
        }
        for (;;)
        {   sprintf(yes_no, "Y");
            if (request_char("Do you want to install documentation?\n",
"If you select Y and type ENTER then machine-readable\n"
"documentation for REDUCE will be installed onto your hard\n"
"disc. If you type N and then ENTER it will not be\n"
"installed.  The files involved will be placed in a\n"
"subdirectory called \"DOC\" and most of them are formatted\n"
"using the TeX text layout system\n", yes_no)) goto abandon;
            c = toupper(yes_no[0]);
            if (c == 'Y' || c == 'N') break;
        }
        want_doc = (c == 'Y');
        for (;;)
        {   sprintf(yes_no, "Y");
            if (request_char("Do you want to install the GNUPLOT package?\n",
"If you select Y and type ENTER then the GNUPLOT package\n"
"will be installed onto your hard disc.  GNUPLOT is not\n"
"strictly part of REDUCE, but can be driven by one of the\n"
"REDUCE packages. If you type N and then ENTER it will not\n"
"be installed.\n", yes_no)) goto abandon;
            c = toupper(yes_no[0]);
            if (c == 'Y' || c == 'N') break;
        }
        want_gnuplot = (c == 'Y');
#ifdef PERSONAL
        want_src = 0;
#else
        for (;;)
        {   sprintf(yes_no, "Y");
            if (request_char("Do you want to install source files?\n",
"If you select Y and type ENTER then all source files for\n"
"REDUCE will be installed onto your hard disc.  If you type\n"
"N and then ENTER binaries will not be installed.  The\n"
"REDUCE source files will be put in a directory \"SRC\", and\n"
"many further files relating to the underlying Lisp (CSL)\n"
"will also appear\n", yes_no)) goto abandon;
            c = toupper(yes_no[0]);
            if (c == 'Y' || c == 'N') break;
        }
        want_src = (c == 'Y');
#endif

        for (;;)
        {   sprintf(yes_no, "Y");
            if (want_exe || want_doc || want_src || want_gnuplot)
                sprintf(msg, "You have chosen to install%s%s%s%s\n",
                             (want_exe ? "\n  Executable binaries" : ""),
                             (want_doc ? "\n  Documentation" : ""),
                             (want_src ? "\n  Source code" : ""),
                             (want_gnuplot ? "\n  Gnuplot" : ""));
            else sprintf(msg, "You seem not to want to install anything!\n");
            if (request_char("Proceed with installation?\n",
                             msg, yes_no)) goto abandon;
            c = toupper(yes_no[0]);
            if (c == 'Y' || c == 'N') break;
            else if (c == 'Q') goto abandon;
        }
        if (c == 'N') continue; /* Give user a chance to try again */
        break;
    }

    if (!want_exe)
        archives[O_EXE286].loaded =
        archives[O_EXE386].loaded =
        archives[O_IMG1].loaded =
        archives[O_IMG2].loaded = 1;
    if (!want_doc)
        archives[O_DOCS1].loaded =
        archives[O_DOCS2].loaded = 1;
    if (!want_src)
        archives[O_SOURCE1].loaded =
        archives[O_SOURCE2].loaded =
        archives[O_SOURCE3].loaded =
        archives[O_SOURCE4].loaded =
        archives[O_OBJS286].loaded =
        archives[O_SMAL286].loaded =
        archives[O_OBJS386].loaded =
        archives[O_SMAL386].loaded = 1;
    if (!want_gnuplot)
        archives[O_GNUPLOT1].loaded =
        archives[O_GNUPLOT2].loaded = 1;

    for (;;)
    {   sdrive[0] = default_source;
        sdrive[1] = ':';
        sdrive[2] = 0;

        if (request_char("Floppy Drive Name\n",
"This is the drive identifier where the Codemist Floppy\n"
"disks will be mounted. Common values are A or B. If you\n"
"want the default, just type the ENTER key. To change the\n"
"value, enter a new letter, any of A-Z will be accepted.\n"
"Any other key will cause the installation procedure to\n"
"be aborted.", sdrive)) goto abandon;

        sdrive[0] = toupper(sdrive[0]);
        if (!('A' <= sdrive[0] && sdrive[0] <= 'Z')) goto abandon;

select_destination:
        if (request_string(44, "Hard Disk Drive and Directory\n",
"This is the drive and directory you wish to install\n"
"Codemist REDUCE 3.5 on. If you want the default, just\n"
"type the ENTER key. To change the value, enter a new\n"
"letter. If the directory does not exist, it will be\n"
"created for you.", dest, "C:\\REDUCE")) goto abandon;

        for (;;)
        {   sprintf(yes_no, "Y");
            sprintf(msg, "Source Disk Drive %s\n"
                  "Where to install %s\n"
                  "Are these values correct (Y or N)\n"
                  "Type Q or ^C to abandon installation\n", sdrive, dest);
            if (request_char("Proceed with installation?\n",
                             msg, yes_no)) goto abandon;
            c = toupper(yes_no[0]);
            if (c == 'Y' || c == 'N') break;
            else if (c == 'Q') goto abandon;
        }
        if (c == 'N') continue; /* Give user a chance to try again */
/*
 * Now I try to ensure that the directory indicated exists... First
 * I select the relevant drive as current, that is always supposing that
 * the user's response started off as "X:" for some X.
 */
        if (dest[0] != 0 && dest[1] == ':')
        {   unsigned int want, ndrives, found;
            want = toupper(dest[0]) - 'A' + 1;
            dos_setdrive(want, &ndrives);
/*
 * I check that the desired drive was indeed selected by checking which
 * drive is current after I (attempt to) make the selection.
 */
            dos_getdrive(&found);
            if (found != want) goto select_failed;
        }
        l = strlen(dest);
        for (i=1; i<=l; i++)
        {   c = dest[i];
            if ((c == '\\' || c == 0) &&
                dest[i-1] != ':' && dest[i-1] != '\\')
            {   int w;
                dest[i] = 0;
                w = mkdir(dest);
                if (w == 0 ||                  /* created OK      */
                    errno == EACCES)           /* already present */
                {   dest[i] = c;
                    continue;
                }
                yes_no[0] = 'Y'; yes_no[1] = 0;
                sprintf(msg, "The directory\n"
                "%s\n"
                "could not be created for you. Type Y/ENTER\n"
                "to select another destination, anything else to\n"
                "quit.\n", dest);
                if (request_char("Try again?\n", msg, yes_no)) goto abandon;
                if (toupper(yes_no[0]) != 'Y') goto abandon;
                else goto select_destination;
            }
        }
/*
 * Now the destination directory ought to exist - select it as
 * current.
 * I will leave this drive and directory selected when I exit from
 * the installation process (even if installation fails)
 */
        if (chdir(dest) == 0) break;
/*
 * If I fail to select the desired drive I give the user a chance to
 * select another.
 */
    select_failed:
        yes_no[0] = 'Y'; yes_no[1] = 0;
        sprintf(msg, "The directory\n"
        "%s\n"
        "could not be selected. Type Y/ENTER\n"
        "to select another destination, anything else to\n"
        "quit.\n", dest);
        if (request_char("Try again?\n", msg, yes_no)) goto abandon;
        if (toupper(yes_no[0]) != 'Y') goto abandon;
        else goto select_destination;
    }
/*
 * I want two sub-directories created here - SLOW is used to hold
 * log files from the slow version of the system, while COUNTS holds
 * statistics that can indicate which (bytecoded) functions are being used
 * most heavily.
 */

    if (mkdir(xdir) != 0 && errno != EACCES) goto installation_failed;
    if (chdir(xdir) != 0) goto installation_failed;
    if (mkdir("slow") != 0 && errno != EACCES) goto installation_failed;
    if (mkdir("counts") != 0 && errno != EACCES) goto installation_failed;


/*
 * Now I have the guts of the installation process - I have a list of
 * archives that I would like to find and will accept discs in any order
 * until I have found them all.
 */

    for (;;)
    {
        something_found = 0;
look_for_another:
        for (i=0; i<NARCHIVES; i++)
        {   if (archives[i].loaded) continue;
            goto another_to_load;
        }
        break;    /* Installation complete */

another_to_load:
        for (i=0; i<NARCHIVES; i++)
        {   if (!archives[i].loaded)
            {   archive_file = filep(sdrive, archives[i].name);
                if (archive_file == NULL) continue;
                something_found = 1;
                clear_work_area();
                sprintf(msg, "File %s to be uncompressed\n", archives[i].name);
                show_txt(9, 16, msg);
                decompress_files();
                archives[i].loaded = 1;
                goto look_for_another;
            }
        }
        if (something_found)
            request_ok(
"Please load the next disc of the REDUCE distribution\n"
"set in your floppy disc drive and type a character\n"
"(e.g. ENTER).  Type ^C to abort installation.\n");
        else request_ok(
"*** No relevant files were found on that disc ***\n"
"This may be because you are not loading the whole of\n"
"REDUCE. Please load the next disc of the distribution\n"
"set in your floppy disc drive and type a character\n"
"(e.g. ENTER).  Type ^C to abort installation.\n");
    }


    request_ok(
"Installation complete.  The directory with the REDUCE\n"
"files will now be selected as current.  Please check\n"
"the file \"READ.ME\" for last-minute notes.\n");
    return EXIT_SUCCESS;

installation_failed:
    request_ok(
"The installation script was unable to create\n"
"one of the files or directories needed for REDUCE.\n");
    return EXIT_FAILURE;

abandon:
    request_ok("Installation of REDUCE incomplete.\n");
    return EXIT_FAILURE;
}

/*
 * The following procedure displays one line of text, centred in the
 * box I have drawn on the screen.
 */

static void disp(int row, char *s)
{
    int len = strlen(s);
    disp_move(row, 40-len/2);
    disp_puts(s);
}

int main(int argc, char *argv[])
{
    int rc, vm = disp_getmode();
    int nrows, ncols, crow, ccol;
    unsigned short *ssave;
/*
 * Firstly I grab the initial contents of the screen so that I can
 * restore it at the end.
 */
    disp_open();
    nrows = disp_numrows;   ncols = disp_numcols;
    crow = disp_cursorrow;  ccol = disp_cursorcol;
    ssave = (unsigned short *)malloc(nrows*ncols*sizeof(short));
    if (ssave == NULL)
    {   disp_close();
        fprintf(stderr, "Insufficient memory for installation of REDUCE\n");
        exit(EXIT_FAILURE);
    }
    disp_peekbox(ssave, 0, 0, nrows-1, ncols-1);
    disp_close();

/*
 * Now I grab the memory that will be needed for file decompression, so
 * that use of malloc() is all done early and thus out-of-memory
 * messages can be dealt with before anything else is messed up.
 */
    prediction1 = (unsigned char *)malloc((size_t)PREDICTION_SIZE);
    prediction2 = (unsigned char *)malloc((size_t)PREDICTION_SIZE);
    fast_decode_table =
        (int32 *)malloc((size_t)(FAST_DECODE_TABLESIZE*sizeof(int32)));
    char_being_coded = (int *)malloc((size_t)(2*CODE_SIZE*sizeof(int)));
    number_of_occurences = (int32 *)malloc((size_t)(2*CODE_SIZE*sizeof(int32)));
    character_index = (int *)malloc((size_t)(2*CODE_SIZE*sizeof(int)));
    corresponding_character = (int *)malloc((size_t)(CODE_SIZE*sizeof(int)));
    huffman_coded_bits =
        (unsigned32 *)malloc((size_t)(CODE_SIZE*sizeof(unsigned32)));
    length_of_code = (char *)malloc((size_t)CODE_SIZE);
/*
 * I re-use the double-length array character_index[] as one of the
 * arrays needed for decoding...
 */
    sorted_huffman_codes = (unsigned32 *)&character_index[0];
    if (prediction1 == NULL ||
        prediction2 == NULL ||
        fast_decode_table == NULL ||
        char_being_coded == NULL ||
        number_of_occurences == NULL ||
        character_index == NULL ||
        corresponding_character == NULL ||
        huffman_coded_bits == NULL ||
        length_of_code == NULL)
    {   fprintf(stderr, "Insufficient memory for installation of REDUCE\n");
        exit(EXIT_FAILURE);
    }

/*
 * Now force myself into an 80*25 alphanumeric screen mode
 */
    if (vm != 3) disp_setmode(3);
    disp_open();
/*
 * Clear the screen
 */
     disp_move(0, 0); disp_eeop();
/*
 * Draw a box, with a border, for installation messages to live within
 */
    disp_fillbox(256*white_on_blue + ' ', 4, 9, 21, 70);
    disp_box(0, white_on_blue, 4, 9, 21, 70);

    disp_setattr(white_on_blue);
#ifdef PERSONAL
    disp(6, "Personal R E D U C E  3.5");
#else
    disp(6, "R E D U C E  3.5");
#endif
    disp(19, "Codemist Ltd, Alta, Horsecombe Vale, Combe Down,");
    disp(20, "Bath BA2 5QR, England.  Telephone/Fax: +44 225 837430");

    switch (setjmp(escape_buffer))
    {
case 0:
        signal(SIGTERM, ctrl_c_handler);
        rc = install(argc > 0 ? toupper(argv[0][0]) : 'A');
        break;
default:
        signal(SIGTERM, SIG_IGN);
        rc = EXIT_FAILURE;
        break;
    }

/*
 * Re-instate the screen-mode that was active when I started
 */
    disp_close();
    if (vm != 3) disp_setmode(vm);
/*
 * Restore previous screen contents and cursor position
 */
    disp_open();
    disp_pokebox(ssave, 0, 0, nrows-1, ncols-1);
    disp_move(crow, ccol);
    disp_flush();
    disp_close();

    exit(rc);
    return 0;
}

/* end of install.c */

