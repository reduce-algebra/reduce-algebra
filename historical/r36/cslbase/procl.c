I have just manufactured a version of CSL that is (perhaps) easy to call
from other C code.  What follows is the main chunk of code that shows
what the interface is.  What this means wrt REDUCE is that I will want to
manufacture an alternative to (BEGIN) that reads-simplifies-prints just
one REDUCE expression/command at a time rather than the current single
function that gobbles things for ever....

/* Signature: 38b248eb 26-Apr-1996 */

/*
 * The next fragment of code is to help with the use of CSL (and hence
 * packages written in Lisp and supported under CSL) as OEM products
 * embedded within larger C-coded packages.  There is (of course) a
 * significant issue about clashes between the names of external symbols
 * if CSL is to be linked with anything else, but I will not worry about that
 * just yet.
 * The protocol for calling Lisp code from C is as follows:
 *
 *     cslstart(argc, argv, writer);allocate memory and Lisp heap etc. Args
 *                                  should be "as if" CSL was being called
 *                                  directly and this was the main entrypoint.
 *                                  The extra arg accepts output from this
 *                                  stage.  Use NULL to get standard I/O.
 *     execute_lisp_function(fname, reader, writer);
 *                                  fname is a (C) string that names a Lisp
 *                                  function of 0 args.  This is called with
 *                                  stdin/stdout access redirected to use the
 *                                  two character-at-a-time functions passed
 *                                  down.  [Value returned indicates if
 *                                  the evaluation succeeded?]
 *     cslfinish(writer);           Tidies up ready to stop.
 */
 
int execute_lisp_function(char *fname,
    character_reader *r, character_writer *w)
{
    Lisp_Object nil;
    Lisp_Object ff = make_undefined_symbol(fname);
    nil = C_nil;
    if (exception_pending()) return 1;  /* Failed to make the symbol */
    procedural_input = r;
    procedural_output = w;
    Lapply0(nil, ff);
    procedural_input = NULL;
    procedural_output = NULL;
    nil = C_nil;
    if (exception_pending()) return 2;  /* Failure during evaluation */
    return 0;
}

#ifdef SAMPLE_OF_PROCEDURAL_INTERFACE

static char ibuff[100], obuff[100];
static int ibufp = 0, obufp = 0;
static int iget()
{
    int c = ibuff[ibufp++];
    if (c == 0) return EOF;
    else return c;
}

static void iput(int c)
{
    if (obufp < sizeof(obuff)-1)
    {   obuff[obufp++] = c;
        obuff[obufp] = 0;
    }
}

#endif

int MS_CDECL main(int argc, char *argv[])
{
    cslstart(argc, argv, NULL);
#ifdef SAMPLE_OF_PROCEDURAL_INTERFACE
    strcpy(ibuff, "(print '(a b c d))");
    execute_lisp_function("oem-supervisor", iget, iput);
    printf("Buffered output is <%s>\n", obuff);
#else
    cslaction();
#endif
    my_exit(cslfinish(NULL));
    return 0;
}

...............................end
