/*
 *  "makemake"                         Copyright (C) 1994-9, Codemist Ltd
 *
 * Used to build system-specific makefiles from a common base file
 *
 *
 * Usage:
 *    makemake key* [-f prototype] [-o newmakefile]
 *                  [-ddata1] [-ddata2] ...
 *
 * The default prototype file is called "makebase" and the default
 * file created is called just "makenew" (note that both those are
 * spelt in lower case letters).  The "keys" passed as arguments
 * should match the options declared at the head of the makebase file.
 * Data given after "-d" is used where otherwise interactive input would be
 * requested.
 */

/* Signature: 55907f19 10-Feb-1999 */

/*
 * The base file is a prototype "makefile", but with extra decorations so
 * that it can contain information relating to several systems.  Lines
 * starting "@ " are comment and are ignored.  Apart from such comments
 * the file should start with a section:
 *      @menu
 *      @item(key1) description
 *      @item(key2) description
 *      @endmenu
 * (the "@" signs should be in column 1, ie no whitespace before them)
 * This declares the valid keys.  A key can be written as
 *      @item(key>extra1>extra2) description
 * and then if the key is specified the given extra symbols will be defined
 * while processing the makebase file.  An example use for this might be
 *      @item(dos386>msdos) Intel 386/486 running DOS
 *      @item(dos286>msdos>sixteenbit) Intel 286 running DOS
 * where subsequent items in the file may test msdos or sixteenbit.
 *
 * After the menu the makebase file is processed subject to directives
 *      @if(key)
 *      @ifnot(key)
 *      @else
 *      @elif(key)
 *      @elifnot(key)
 *      @endif
 * (again no whitespace is permitted, and the "@" must be in column 1)
 * which provide for conditional inclusion of text. A condition is TRUE if
 * it was either the key specified to mmake, or was set up by a ">"
 * in a menu item that matched the key.
 *      @error (while not skipping)
 * terminates processing.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef SEEK_SET
#define SEEK_SET 0
#endif

#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif

static int flags;

static char *special_words[] =
{
    "backslash",
#define FLAG_BACKSLASH   (flags &    0x001)
    "watcom",
#define FLAG_WATCOM      (flags &    0x002)
    "obj",
#define FLAG_OBJ         (flags &    0x004)
    "acorn",
#define FLAG_ACORN       (flags &    0x008)
    "escapequote",
#define FLAG_ESCAPEQUOTE (flags &    0x010)
    "blank",
#define FLAG_BLANK       (flags &    0x020)
    "unix",
#define FLAG_UNIX        (flags &    0x040)
    "blank1",
#define FLAG_BLANK1      (flags &    0x080)
    0
};

#define N_SPECIAL_WORDS 7

#define LINE_LENGTH 1024

static char line[LINE_LENGTH];
static int EOF_seen = 0;
int line_number, last_live_line;

#define MAX_WORDS 100

static char *defined_words[MAX_WORDS];
static int in_makebase[MAX_WORDS];
static int n_user_words = 0, n_defined_words = 0;

static FILE *fmakebase, *fmakefile;

static int get_line()
/* Read one line from makebase into line buffer, return 1 if OK */
{
    int i = 0, c;
    if (EOF_seen) return 0;
    line_number++;
    while ((c = getc(fmakebase)) != '\n' && c != EOF)
        if (i < LINE_LENGTH-2) line[i++] = c;
/* I lose trailing blanks from all input lines */
    while (i > 0 &&
           (line[i-1] == ' ' || line[i-1] == '\t')) i--;
/*
 * If the file ended with a line that was not terminated by '\n' I
 * insert a '\n' here.
 */
    if (c == EOF)
    {   EOF_seen = 1;
        if (i != 0)
        {   line[i++] = '\n';
            line[i] = 0;
            return 1;
        }
        else return 0;
    }
    line[i++] = '\n';
    line[i] = 0;
    return 1;
}

static int process_item(int show)
{
    char menuitem[LINE_LENGTH], *extra_defines[16];
    int i, p, n_extra_defines = 0;
    for (i=0, p=6; line[p] != ')' && line[p] != '\n'; )
    {   if (line[p] == '>')
        {   menuitem[i++] = 0;
            extra_defines[n_extra_defines++] = &menuitem[i];
            p++;
        }
        else menuitem[i++] = line[p++];
    }
    menuitem[i] = 0;
    if (line[p] != ')') return 0;
    else p++;
    while (line[p] == ' ' || line[p] == '\t') p++;
    if (show)
    {   int len = (256 - strlen(menuitem)) % 8;
        printf("  %s:%*s %s", menuitem, len, "", &line[p]);
        return 1;
    }
    for (i=0; i<n_defined_words; i++)
        if (strcmp(menuitem, defined_words[i]) == 0)
        {   in_makebase[i] = 1;
            break;
        }
    if (i >= n_defined_words) return 0;
    for (i=0; i<n_extra_defines; i++)
    {   char *s = (char *)malloc(1+strlen(extra_defines[i]));
        if (s == NULL) return 0;
        strcpy(s, extra_defines[i]);
        defined_words[n_defined_words++] = s;
    }
    return 1;
}

static int process_menu(int show, char *makebase)
{
    int success = 0, i;
    if (show) printf("The valid keys from \"%s\" are:\n", makebase);
    while (get_line())
        if (memcmp(line, "@menu", 5) == 0) break;
    while (get_line())
    {   if (memcmp(line, "@endmenu", 8) == 0) break;
        if (memcmp(line, "@item(", 6) == 0 &&
            process_item(show)) success = 1;
    }
    if (!show && success)
      for (i=0; i<n_user_words; i++)
        if (!in_makebase[i])
        {   printf("\"%s\" not present in base file\n", defined_words[i]);
            success = 0;
        }
    return !success;
}

static int blank_lines = 0;

#ifdef SUPPORT_ACORN

/*
 * Support for Acorn's RiscOS is not automatically included - if you need to
 * re-instate that you will have to review the following code and make it
 * work again.
 */

static char *implicit_dirs[] =
/*
 * If I find a filename in the makebase which has one of these names as a
 * suffix (eg xyz.abcdef.c) then for Acorn purposes I will convert it to
 * use a directory instead of a suffix (xyz.c.abcdef).  I will make the
 * check for things in this list case insensitive.  Note that GREAT care is
 * needed with files whose real name looks too much like one of these
 * special strings - eg "doc.c" or "s.txt" could cause muddle. I view it
 * as the business of people creating makecore files to take care of such
 * things (typically be avoiding such file names).
 */
{
    "!",        /* Used by ACN as a place for scratch files */
    "c",        /* C source code                            */
    "f",        /* Fortran source code                      */
    "h",        /* C header files                           */
    "l",        /* Listings generated by the C compiler     */
    "o",        /* Object code                              */
    "p",        /* Pascal?                                  */
    "s",        /* Assembly code                            */
    "lsp",      /* Used with CSL                            */
    "sl",       /* Used with CSL/REDUCE                     */
    "red",      /* REDUCE sources                           */
    "fsl",      /* CSL fast-load files (well, not really!)  */
    "log",      /* I guess this is the hardest case         */
    "tst",      /* REDUCE test files                        */
    "doc",      /* Another hard case                        */
    "cpp",      /* C++ files                                */
    "hpp",      /* C++ header files                         */
    "txt",      /* to help me with some MSDOS transfers     */
    "bak",      /* Ditto.                                   */
    NULL
};

static int acorn_filename(int i)
{
    char raw_filename[LINE_LENGTH], extension[20], lc_extension[20];
    int j = 0, c;
    while ((c = line[i++]) != 0 && c != ' ' && c != '\n' &&
           c != '\t')
    {   if (c == '@')
        {   c = line[i++];
            switch (c)
            {
        case '^':
        case '@': raw_filename[j++] = c; break;
        case '/': raw_filename[j++] = '.'; break;
        case '~': if (FLAG_BLANK) raw_filename[j++] = ' ';
                  break;
        case '=': if (FLAG_BLANK1) raw_filename[j++] = ' ';
                  break;
        case '"': if (escapequote) raw_filename[j++] = '\\';
                  raw_filename[j++] = c;
                  break;
        case '!': break;
        case 'o': raw_filename[j++] = 'o';
                  if (FLAG_OBJ)
                  {   raw_filename[j++] = 'b';
                      raw_filename[j++] = 'j';
                  }
                  break;
        default:  raw_filename[j++] = '@';
                  raw_filename[j++] = c;
                  break;
            }
        }
        else raw_filename[j++] = c;
    }
    if (raw_filename[j-1] == ':') i--, j--;
    raw_filename[j] = 0;
    while (j >= 0 && raw_filename[j] != '.') j--;
    extension[0] = 0;
    if (j > 0 & raw_filename[j] == '.' && strlen(&raw_filename[j]) < 16)
    {   strcpy(extension, &raw_filename[j+1]);
        raw_filename[j] = 0;
    }
    for (j=0; extension[j]!=0; j++)
    {   c = extension[j];
        if (isupper(c)) c = tolower(c);
        lc_extension[j] = c;
    }
    lc_extension[j] = 0;
    for (j=0; implicit_dirs[j]!=NULL; j++)
        if (strcmp(implicit_dirs[j], extension) == 0) break;
    if (implicit_dirs[j] != NULL)   /* Match found - flip around */
    {   j = strlen(raw_filename)-1;
        while (j >= 0 && raw_filename[j] != '.') j--;
        if (j > 0)
        {   raw_filename[j] = 0;
            fprintf(fmakefile, "%s.%s.%s",
                raw_filename, extension, &raw_filename[j+1]);
        }
        else fprintf(fmakefile, "%s.%s", extension, raw_filename);
    }
    else if (extension[0] == 0) fprintf(fmakefile, "%s", raw_filename);
    else fprintf(fmakefile, "%s.%s", raw_filename, extension);
    return i-1;
}

#endif /* SUPPORT_ACORN */

static void put_filename(char *filename)
{
    int i, c;
    if (FLAG_OBJ)
    {   i = strlen(filename) - 2;
        if (i > 0 && strcmp(&filename[i], ".o") == 0)
            strcpy(&filename[i], ".obj");
    }
    if (FLAG_UNIX)
    {   i = strlen(filename) - 4;
        if (i > 0 && strcmp(&filename[i], ".exe") == 0)
            filename[i] = 0;
    }
    if (FLAG_BACKSLASH)
    {   for (i=0; (c=filename[i])!=0; i++)
            if (c == '/') filename[i] = '\\';
    }
    for (i=0; (c=filename[i])!=0; i++)
        putc(c, fmakefile);
}

static char userinput[256];
static char **data;
static int data_available;

static void put_line()
{
    int i = 0, c;
    char filename[256], *p;
/*
 * A typical problem with expanded files is that blank lines accumulate
 * beyond reason. Here I will lose any excessive blank blocks.
 */
    if (line[0] == '\n')
    {   if (blank_lines++ > 3) return;
    }
    else blank_lines = 0;
    while ((c = line[i++]) != 0)
    {
/*
 * The line buffer here has a newline character at its end, but no (other)
 * trailing whitespace. For the Watcom "make" utility I need to convert
 * any trailing "\" into a "&".
 */
        if (c == '\\' && FLAG_WATCOM && line[i] == '\n')
        {   putc('&', fmakefile);
            putc('\n', fmakefile);
            break;
        }
        if (c == '@')
        {   c = line[i++];
            switch (c)
            {
        case '@': putc(c, fmakefile);
                  continue;
        case '~': if (FLAG_BLANK) putc(' ', fmakefile);
                  continue;
        case '=': if (FLAG_BLANK1) putc(' ', fmakefile);
                  continue;
        case '"': if (FLAG_ESCAPEQUOTE) putc('\\', fmakefile);
                  putc(c, fmakefile);
                  continue;
        case '?': c = line[i++];
                  if (c != '(') i--;
                  p = userinput;
                  while ((c = line[i++]) != ')' && c != 0 && c != '\n')
                      putchar(c);
                  if (data_available != 0)
                  {   char *q = *data++;
                      data_available--;
                      while ((c = *q++) != 0)
                          *p++ = c, putc(c, fmakefile);
                      *p = 0;
                      printf("\n%s\n", userinput);
                  }
                  else
                  {   printf("\nPlease enter value as described above,\n");
                      printf("file-names to use \"/\" as directory separator: ");
                      while ((c = getchar()) != '\n' && c != EOF)
                          *p++ = c, putc(c, fmakefile);
                      *p = 0;
                  }
                  continue;
        case '!': put_filename(userinput);
                  continue;
        default:  p = filename;
                  i--;
                  while ((c = line[i++]) != ' ' && c != 0 &&
                         c != '\n' && c != '\\' && c != ',' &&
                         !(c == ':' && isspace(line[i])))
                      *p++ = c;
                  *p = 0;
                  i--;      /* unread the character that ended the filename */
                  put_filename(filename);
                  continue;
            }
        }
        else putc(c, fmakefile);
    }
}

static int eval_condition(char *s)
{
    char word[LINE_LENGTH];
    int i = 0;
    while (s[i] != ')' && s[i] != 0)
    {   int c = s[i];
        if (c == '\n') return 0;  /* bad syntax - treat as condition false */
        word[i++] = c;
    }
    word[i] = 0;
    for (i=0; i<n_defined_words; i++)
        if (strcmp(word, defined_words[i]) == 0) break;
    return (i < n_defined_words);
}

void get_flags()
{
    int i, j;
    flags = 0;
    for (i=0; i<n_defined_words; i++)
       for (j=0; j<N_SPECIAL_WORDS; j++)
           if (strcmp(defined_words[i], special_words[j]) == 0)
               flags |= (1 << j);
}

static void create_makefile(char *makebase, char *makefile)
{
/*
 * skipping is 0 if text is being included. If is 1 if test is being
 *          skipped following @if(false). If is 2 following an
 *          @else clause after an @if(true)
 * nesting is a count of the number of @if constructions nested within
 *          skipped text. It is incremented when @if is seen in skipping
 *          context, and decremented when @endif is encountered.
 */
    int skipping = 0, nesting = 0, i;
    char *p;
    line_number = last_live_line = 0;
    if (process_menu(0, makebase))
    {   printf("\nBad keyword or ill-formed base file\n");
        fseek(fmakebase, SEEK_SET, 0L);
        line_number = 0;
        process_menu(1, makebase);
        fprintf(fmakefile, "\nError in creating makefile, re-run mmake\n");
        return;
    }
    get_flags();
    userinput[0] = 0;
/*
 * By now the makebase file will have had all the menu items at its
 * head scanned, so now I mainly have to copy its body to create the
 * output makefile.
 */
    while (get_line())
    {
        if (skipping == 0) last_live_line = line_number;
        if (memcmp(line, "@ ", 2) == 0) continue;   /* Comment line */
        if (memcmp(line, "@\n", 2) == 0) continue;  /* Comment line */
        else if (memcmp(line, "@set(", 5) == 0)
        {   if (skipping == 0)
            {   i = 5;
                while (line[i] != ')' && line[i] != '\n' && line[i] != 0) i++;
                line[i] = 0;
                p = (char *)malloc(i-4);
                strcpy(p, &line[5]);
                defined_words[n_defined_words++] = p;
                get_flags();
            }
        }
        else if (memcmp(line, "@if(", 4) == 0)
        {   if (skipping) nesting++;
            else if (!eval_condition(&line[4])) skipping = 1;
        }
        else if (memcmp(line, "@ifnot(", 7) == 0)
        {   if (skipping) nesting++;
            else if (eval_condition(&line[7])) skipping = 1;
        }
        else if (memcmp(line, "@elif(", 6) == 0)
        {   if (nesting == 0)
            {   if (skipping==1)
                {   if (eval_condition(&line[6])) skipping = 0;
                }
                else skipping = 2;
            }
        }
        else if (memcmp(line, "@elifnot(", 9) == 0)
        {   if (nesting == 0)
            {   if (skipping==1)
                {   if (!eval_condition(&line[6])) skipping = 0;
                }
                else skipping = 2;
            }
        }
        else if (memcmp(line, "@else", 5) == 0) /* Like @elif(true) */
        {   if (nesting == 0)
            {   if (skipping==1) skipping = 0;
                else skipping = 2;
            }
        }
        else if (memcmp(line, "@endif", 6) == 0)
        {   if (nesting > 0) nesting--;
            else skipping = 0;
        }
        else if (memcmp(line, "@error", 6) == 0)
        {   if (skipping == 0)
            {   printf("\nError line detected...\n");
                printf("%s", line);
                exit(EXIT_FAILURE);
            }
        }
        else if (skipping == 0) put_line();
    }
    if (skipping != 0)
    {   printf("Still skipping at end of file after line %d\n",
               last_live_line);
    }
    printf("\"%s\" created as makefile for", makefile);
    for (i=0; i<n_user_words; i++)
        printf(" \"%s\"", defined_words[i]);
    printf("\n");
}

#define DATA_SIZE 20

static char *command_line_data[DATA_SIZE];

/*
 * This is the only place where I seem to really need an #ifdef in this
 * simple code. It is here because under Microsoft C some user may use
 * a register-based calling convention by default, but in such cases
 * "main" needs to be made __cdecl. I put the test here in-line rather
 * than using the "sys.h" header that other code here does because I expect
 * people to need to compile makemake.c before they start to look at the
 * rest of my utilities, and so I want makemake.c to be as simple and
 * stand-alone as possible.
 */

int
#ifdef _MSC_VER
    __cdecl
#endif
    main(int argc, char *argv[])
{
    char *makebase = NULL, *makefile = NULL;
    int i, usage = 0;
    for (i=0; i<MAX_WORDS; i++) in_makebase[i] = 0;
    n_defined_words = 0;
    data = command_line_data;
    data_available = 0;
    for (i=1; i<argc; i++)
    {   char *arg = argv[i];
        if (arg == NULL) continue;
        if (arg[0] == '-') switch(arg[1])
        {
    case 'f': case 'F':
            if (++i < argc) makebase = argv[i];
            continue;
    case 'o': case 'O':
            if (++i < argc) makefile = argv[i];
            continue;
    case 'h': case 'H': case '?':
            usage = 1;
            printf("Usage:\n");
            printf("  mmake key* [-f basefile] [-o outfile]\n");
            printf("basefile defaults to \"makebase\"\n");
            printf("outfile defaults to \"makenew\"\n");
            printf("If no key is given a list of options from basefile ");
            printf("is listed\n");
            continue;
   case 'd': case 'D':
            {   char *q = (char *)malloc(1+strlen(arg+2));
                if (q == NULL)
                {   printf("malloc failure\n");
                    continue;
                }
                strcpy(q, arg+2);
                if (data_available >= DATA_SIZE)
                    printf("Too many \"-d\" options. Ignore this one\n");
                else data[data_available++] = q;
            }
            continue;
    default:
            printf("Unknown option \"%s\" ignored\n", arg);
            continue;
        }
        else defined_words[n_defined_words++] = arg;
    }
    if (usage) return 0;
    if (makebase == NULL) makebase = "makebase";
    if (makefile == NULL) makefile = "makenew";
    if ((fmakebase = fopen(makebase, "r")) == NULL)
    {   printf("Unable to read \"%s\"\n", makebase);
        return 0;
    }
    if (n_defined_words == 0) process_menu(1, makebase);
    else
    {   if ((fmakefile = fopen(makefile, "w")) == NULL)
        {   printf("Unable to write to file \"%s\"\n", makefile);
            fclose(fmakebase);
            return 0;
        }
        n_user_words = n_defined_words;
        create_makefile(makebase, makefile);
        fclose(fmakefile);
    }
    fclose(fmakebase);
    return 0;
}

/* end of makemake.c */
