/* filename.c                 Copyright (C) 1995-2002 Codemist Ltd */

/*
 * Map file-names to expand references to shell variables etc.
 * and to provide portability of names across operating systems.
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


/* Signature: 1705ecf5 10-Oct-2002 */

static char *look_in_lisp_variable(char *o, int prefix)
{
    Lisp_Object nil, var;
/*
 * I will start by tagging a '$' (or whatever) on in front of the
 * parameter name.
 */
    o[0] = (char)prefix;
    var = make_undefined_symbol(o);
    nil = C_nil;
/*
 * make_undefined_symbol() could fail either if we had utterly run out
 * of memory or if somebody generated an interrupt (eg ^C) around now. Ugh.
 */
    if (exception_pending())
    {   flip_exception();
        return NULL;
    }
/*
 * If the variable $name was undefined then I use an empty replacement
 * text for it. Otherwise I need to look harder at its value.
 */
    if (qvalue(var) == unset_var) return o;
    else
    {   Header h;
        intxx len;
        var = qvalue(var);
/*
 * Mostly I expect that the value will be a string or symbol.
 */
#ifdef COMMON
        if (complex_stringp(var))
        {   var = simplify_string(var);
            nil = C_nil;
            if (exception_pending())
            {   flip_exception();
                return NULL;
            }
        }
#endif /* COMMON */
        if (symbolp(var))
        {   var = get_pname(var);
            nil = C_nil;
            if (exception_pending())
            {   flip_exception();
                return NULL;
            }
            h = vechdr(var);
        }
        else if (!is_vector(var) ||
                 type_of_header(h = vechdr(var)) != TYPE_STRING)
            return NULL;
        len = length_of_header(h) - CELL;
/*
 * Copy the characters from the string or from the name of the variable
 * into the file-name buffer. There could at present be a crash here
 * if the expansion was very very long and overflowed my buffer. Tough
 * luck for now - people doing that (maybe) get what they (maybe) deserve.
 */
        memcpy(o, (char *)var + (CELL - TAG_VECTOR), (size_t)len);
        o = o + len;
        return o;
    }
}

static void process_file_name(char *filename, char *old, size_t n)
/*
 * This procedure maps filenames by expanding some environment
 * variables.  It is very thoroughly system specific, which is why it
 * is in this file.  See also LONGEST_LEGAL_FILENAME in "tags.h" for a
 * limit on the permitted size of an expanded filename.
 * The input (old) is not necessarily properly terminated as a C string,
 * so n says how many characters to inspect.  Build a converted name
 * in filename.
 * At present the expansions I allow are:
 *
 *    $xxx   (terminated by '.', '/' or '\' with at least one char x)
 *    ${xxx} (self-terminating)
 *           First check for a Lisp variable $xxx. If this is set (and is
 *           a string or a symbol) then its value is used. If not then
 *           next inspect the environment variable xxx and dump its
 *           value into the output.  If the variable is unset then a check
 *           is made for the value of a global lisp variable called @xxx,
 *           and if that exists and is a string or symbol it is used.
 *           If @xxx is undefined a null string is inserted.
 *           If one of the variables is defined but has an improper value
 *           then the whole file-translation fails.
 *           The use of two Lisp variables makes it possible to control
 *           precedence between these and shell variables.
 *
 *    ~      ) followed by '.', '/' or '\'
 *    ~xxx   )
 *           On Unix these try to find home directories using
 *           getpwuid(getuid()) for '~' and getpwnam() for ~xxx.
 *           If that fails ~ expands into nothing at all.
 *           This syntax is only recognised at the very start of a file-name.
 *           For systems other than Unix this syntax will not be useful and
 *           should be avoided, however as an experimental place-holder I
 *           may do things with environment variables called HOME etc.
 * 
 * 
 * I convert file-names of the form aaa/bbb/ccc.ddd into something
 * acceptable to the system being used, even though this may result in
 * some native file titles that include '/' characters becoming unavailable.
 * The reasoning here is that scripts and programs can then use Unix-like
 * names and non-Unix hosts will treat them forgivingly.
 *
 *
 */
#ifdef __vmsvax__
/*
 * This is maybe going to be a mess under VAX/VMS, but I will try
 * pretending that is still Unix for now since the VMS C runtime system
 * seems prepared to help a little in that case.
 */
#endif /* __vmsvax__ */
{
    int32 i, j;
    int c;
    char *o, *tail;
    if (n == 0)
    {   *filename = 0;
        return;    /* deem zero-length name to be illegal */
    }
    o = filename;
    c = *old;
/*
 * First I deal with a leading "~"
 */
    if (c == '~')
    {   old++;
        n--;
        while (n != 0)
        {   c = *old;
            if (c == '.' || c == '/' || c == '\\') break;
            old++;
            n--;
            *o++ = (char)c;
        }
        *o = 0;
/*
 * actually deciding what the home directory is is passed down to a
 * system-specific call, but it is not to be relied upon especially
 * on personal computers.
 */
        if (o == filename)  /* '~' on its own */
        {   get_home_directory(filename, LONGEST_LEGAL_FILENAME);
            o = filename + strlen(filename);
        }
        else
        {   get_users_home_directory(filename, LONGEST_LEGAL_FILENAME);
            o = filename + strlen(filename);
        }
    }
/*
 * Having copies a user-name across (if there was one) I now copy the
 * rest of the file-name, expanding $xxx and ${xxx} as necessary.
 */
    while (n != 0)
    {   c = *old++;
        n--;
/*
 * If I find a "$" that is either at the end of the file-name or that is
 * immediately followed by ".", "/" or "\" then I will not use it for
 * parameter expansion. This at least gives me some help with the RISCOS
 * file-name $.abc.def where the "$" is used to indicate the root of the
 * current disc.
 */
        if (c == '$' && n != 0 &&
            (c = *old) != '.' && c != '/' && c != '\\')
        {   char *p = o, *w;
/*
 * I collect the name of the parameter at the end of my file-name buffer,
 * but will over-write it later on when I actually do the expansion.
 */
            if (c == '{')
            {   old++;
                n--;
                while (n != 0)
                {   c = *old++;
                    n--;
                    if (c == '}') break;
                    *p++ = (char)c;
                }
            }
            else
            {   while (n != 0)
                {   c = *old;
                    if (c == '.' || c == '/' || c == '\\') break;
                    old++;
                    n--;
                    *p++ = (char)c;
                }
            }
            *p = 0;
            i = strlen(o) + 2;
            while (i-- != 0) o[i] = o[i-1];
            if ((p = look_in_lisp_variable(o, '$')) != NULL &&
                p != o) o = p;
            else if ((w = my_getenv(o+1)) != NULL)    /* Shell variable? */
            {   strcpy(o, w);
                o = o + strlen(o);
            }
            else if ((p = look_in_lisp_variable(o, '@')) != NULL)
                o = p;
            else
            {   *filename = 0;  /* return reporting failure */
                return;
            }
        }
        else *o++ = (char)c;
    }
    *o = 0;

#ifdef NOT_TOTALLY_DEBUGGED
    term_printf("[temp trace] File-name expands to \"%s\"\n", filename);
#endif

#ifdef MS_DOS
/*
 * Now the filename has had $ and ~ prefix things expanded - I "just"
 * need to deal with sub-directory representation issues. Specifically I need
 * to map "/" separators into "\" so that if a user presents a file
 * name such as aaa/bbb/ccc.d it gets passed to the operating system
 * as aaa\bbb\ccc.d
 * NOte that I enable this code under the heading MS_DOS but really it
 * means any file-system (eg Windows too) that uses "\" as its main
 * directory separator character.
 */
 
/*
 * I map / characters in MSDOS filenames into \s, so that users
 * can give file names with Unix-like slashes as separators if they want.
 * People who WANT to use filenames with '/' in them will be hurt.
 */
    tail = filename;
    while ((j = *tail) != 0)
    {   if (j == '/') *tail = '\\';
        tail++;
    }

/*
 * stat and friends do not like directories referred to as "\foo\", so check
 * for a trailing slash, being careful to respect directories with names
 * like "\" and "a:\".
 */
   j = strlen(filename);
   if (j > 0 && j != 1 && !(j == 3 && *(filename+1) == ':'))
   {
       if ( (*(tail - 1) == '\\')) *(tail - 1) = 0;
   }
#ifdef __WATCOMC__
/*
 * There is a bug in the stat function under some releases of Watcom C, where:
 *  stat("\\foo\\..", ...);
 * fails with errno=-1.  So we delete trailing ".." segments.
 */
   if (filename[0] == '\\' || filename[1] == ':')
   {   j = strlen(filename);
       while (filename[j-1] == '.' && filename[j-2] == '.')
       {   tail = strrchr(filename, '\\');
/*
 * Warning - the aerror0() function sets an internal flag to indicate
 * that something went wrong, and then returns. Thus if further processing
 * is not valid in one of these cases some explicit control flow (maybe a
 * "return") is called for,
 */
           if (tail == NULL)
               aerror0("Unexpected pathname - this error should never happen");
           else *tail = '\0';
           tail = strrchr(filename, '\\');
           if (tail == NULL)
               aerror0("Unexpected pathname - this error should never happen");
           else *tail = '\0';
           j = strlen(filename);
       }

       /* Make sure we don't have an empty string or just a drive */
       if (j == 0) strcpy(filename,"\\");
       else if (j==2 && filename[1] == ':') strcat(filename,"\\");
   }
#endif /* __WATCOMC__ */

#ifdef EIGHT_PLUS_THREE
/*
 * A *NASTY* hack here. I will explicitly truncate the name down to
 * and 8+3 format to keep as much DOS compatibility as I (in)conveniently can.
 * This is done here because if a user attempts to open a file with a long
 * name Windows 95 will try to honour the request and will then get confused
 * if old-style W3.x or DOS utilities made the file with a truncated name.
 * I rather think that this ought not to be wanted any more, especially if
 * it is possible to accept that raw DOS and Windows before 95 need not
 * be supported, but I will leave this in the code just in case!
 */
    tail = filename;
    eight_plus_three(tail);
    while ((j=*tail++)!=0) if (j=='\\' || j==':') eight_plus_three(tail);
#endif /* EIGHT_PLUS_THREE */
#endif /* MS_DOS */

#ifdef MACINTOSH
/*
 * Now the filename has had $ and ~ prefix things expanded - I "just"
 * need to deal with sub-directory representation issues. Specifically I need
 * to map "/" separators into "\" so that if a user presents a file
 * name such as aaa/bbb/ccc.d it gets passed to the operating system
 * as aaa\bbb\ccc.d
 * NOte that I enable this code under the heading MS_DOS but really it
 * means any file-system (eg Windows too) that uses "\" as its main
 * directory separator character.
 */
 
/*
 * I map '/'characters in Macintosh filenames into ':'s, so that users
 * can give file names with Unix-like slashes as separators if they want.
 * People who WANT to use filenames with '/' in them will be hurt.
 * Furthermore if the name originally had no colons in it a leading colon is
 * added, and if it originally started with a '/' (for a Unix fully rooted name)
 * then the leading ':' or '/' is removed.
 */
    tail = filename;
    while ((j = *tail) != 0 && j != ':') tail++;
    if (j == 0)
    {   memmove(&filename[1], filename, 1+strlen(filename));
        filename[0] = ':';
    }
    if (filename[0] == '/') memmove(filename, &filename[1], strlen(filename));
    tail = filename;
    while ((j = *tail) != 0)
    {   if (j == '/') *tail = ':';
        tail++;
    }
/*
 * I map the string :..: onto just :: to cope with Unix-format references to
 * the parent directory
 */
    i = 0;
    while ((c = filename[i]) != 0)
    {   if (c == ':' &&
            filename[i+1] == '.' &&
            filename[i+2] == '.' &&
            filename[i+3] == ':')
        {   j = i+1;
            do
            {   c = filename[j+2];
                filename[j++] = c;
            } while (c != 0);
        }
        i++;
    }
#endif /* MACINTOSH */

#ifdef RISCOS
/*
 * Now the filename has had $ and ~ prefix things expanded - I "just"
 * need to deal with sub-directory representation issues.
 */

/*
 * The Archimedes is best coped with by re-mapping file names
 * so that xxxx.y sometimes becomes y.xxxx
 */
 
    i = strlen(filename);
    for (j=i-1; j>=0; j--) if (filename[j] == '.') break;
    if (j >= 0)   /* No '.' => no possible conversion */
    {   tail = &filename[j+1];
        if (j == i - 2 ||               /* one character suffix */
/*
 * At present my policy is that any file with a one-character final
 * component gets mangled, and that as a special case files of
 * the form xxx.lsp, xxx.red, xxx.fsl and xxx.log are also flipped.
 */
          strcmp(tail, "lsp") == 0 ||
            strcmp(tail, "red") == 0 ||
            strcmp(tail, "fsl") == 0 ||
            strcmp(tail, "tst") == 0 ||
            strcmp(tail, "sl")  == 0 ||
            strcmp(tail, "log") == 0)
        {   int32 k;
            char suffix[8];
            for (k=j-1; k>=0; k--)
                if (filename[k] == '.' || filename[k] == '/') break;
            strcpy(suffix, tail);
            strcat(suffix, ".");
            do filename[--i] = filename[--j]; while (j > k);
            memcpy(&filename[k+1], suffix, (size_t)(i - j));
        }
    }
/*
 * Now if in the Unix world I had a component '..' in the file it will
 * appear something like //.aaa.bbb or aaa.//.bbb
 * Similarly I map an isolated '.' (now an isolated '/') into '@'.
 */
    {   int32 k = 0;
        j = -1;
        c = '/';
        for (;;)
        {   if (c == '/' || c == 0)
            {   if (j == k+1 && filename[k] == '.') filename[k] = '@';
                else if (j == k + 2 && filename[k] == '.' && filename[k+1] == '.')
                {   int c1;
                    filename[k++] = '^';
                    do
                    {   c1 = filename[k+1];
                        filename[k++] = c1;
                    } while (c1 != 0);
                }
                k = j+1;
            }
            if (c == 0) break;
            j++;
            c = filename[j];
        }
    }
/*
 * I map / characters in RISCOS filenames into dots, so that users
 * can give file names with Unix-like slashes as separators if they want.
 * People who WANT to use filenames with '/' in them will be hurt.
 * Note also that when files are created for output an attempt to open
 * (e.g.) "arthur.red" will fail unless the directory "red" already
 * exists.
 */
    tail = filename;
    while ((j = *tail) != 0)
    {   if (j == '/') *tail = '.';
        tail++;
    }
    if (*filename == '.')   /* Deal with fully-rooted Unix filenames */
    {   tail[1] = 0;
        while (tail != filename)
        {   tail--;
            tail[1] = tail[0];
        }
        tail[0] = '$';
    }
#endif /* RISCOS */
}


FILE *open_file(char *filename, char *old, size_t n,
                char *mode, FILE *old_file)
{
/*
 * mode is something like "r" or "w" or "rb", as needed by fopen(),
 * and old_file is NULL normally, but can be a (FILE *) to indicate
 * the use of freopen rather than fopen.
 */
    process_file_name(filename, old, n);
    if (*filename == 0) return NULL;
#ifdef NO_BINARY_FOPEN
/*
 * On some Unix implementations (I mean DECs version on its MIPS workstations
 * and on the microvax I tried) the library does not support "rb" and "wb"
 * modes, so I work around that here.  Explicit selection of binary file
 * access will be needed on some non-Unix operating systems, but should
 * never be relevant under Unix, hence my choice of a flag for the conditional
 * compilation here.
 */
    if (mode[0] == 'w')
    {   if (mode[1] == '+') mode = "w+";
        else mode = "w";
    }
    else if (mode[1] == '+') mode = "r+";
    else mode = "r";    /* That ought to patch it up */
#endif

    if (old_file == NULL) return fopen(filename, mode);
    else return freopen(filename, mode, old_file);
}

/* end of filename.c */

