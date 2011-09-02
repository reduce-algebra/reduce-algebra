/* file grep2.c */

/* Signature: 180f8783 08-Apr-2002 */


#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include "machine.h"
#include "tags.h"
#include "cslerror.h"
#include "externs.h"
#include "entries.h"
#include "arith.h"

/* Defined in grep.c */
extern void zsfinit_(int32 *mode);
extern void zscpat_(char *pat, int32 *cse, int32 *cpat, int32 *maxpat,
                    int32 *ifail, int32 len);
extern int32 zsfind_(char *line, int32 *start, int32 *finish, int32 *cpat,
                     int32 len);

/* 
 * I really do need to be able to read arbitrary sized lines because the
 * AXIOM databases contain some quite long ones!
 *
 */

/* The number of characters we will malloc at a time */
#define LINE_CHUNK_LENGTH 127

typedef struct LineChunk
{
  char s[LINE_CHUNK_LENGTH+1];
  struct LineChunk *next;
} LineChunk;

LineChunk *newChunk()
{
  LineChunk *new;
  new = (LineChunk *)malloc(sizeof(LineChunk));
  new->next = NULL;
  return(new);
}

int getChunk(char *buffer, FILE *fp)
{
  int32 i=0;
  char  c;

  c = getc(fp);
  /* In theory could compare c to EOF but this probably isn't very safe */
  while (c != '\n' && !feof(fp) && i < LINE_CHUNK_LENGTH) {
    buffer[i] = c;
    ++i;
    c = getc(fp);
  }

  buffer[i] = '\0';

  if (i == LINE_CHUNK_LENGTH) {
    ungetc(c,fp);
    return (0);
  }
  else
    return (1);

} 

char *concatenateChunks(LineChunk *l, int32 len)
{
  char *s;
  LineChunk *prev;

  if (len <= LINE_CHUNK_LENGTH)
    return(l->s);
  else {
    s = (char *)malloc((size_t) len);
    s[0] = '\0'; /* Otherwise strcat might get confused! */

    while (l != NULL) {
      strcat(s,l->s);
      prev = l;
      l = l->next;
      free(prev);
    }

    return(s);
  }
}

char *read_a_line(FILE *fp)
{
  LineChunk *start, *place;
  int32 chunk_count=1;
  char *str;

  start = newChunk();
  place = start;

  while (!getChunk(place->s, fp) ) {
    place->next = newChunk();
    place = place->next;
    ++chunk_count;
  }

  /* The +1 in the size is for the terminator */
  str = concatenateChunks(start,
                          (chunk_count-1)*LINE_CHUNK_LENGTH+strlen(place->s)+1);
  return(str);
}

#define MAXIMUM_PATTERN_SIZE 512

/*
 * This function takes a filename or a list of strings and returns
 * lines which match pattern
 * which uses egrep syntax.  The flag casep says whether to be
 * case sensitive in matching, and the flag matchp says whether to return
 * a line or not if the pattern matches (i.e. it behaves like the "-v"
 * option to grep et al).
 */

Lisp_Object MS_CDECL Lgrep(Lisp_Object nil, int nargs, ...)
{
  va_list args;
  Lisp_Object name, pattern, casep, matchp, result;
  FILE *fp;
  char filename[LONGEST_LEGAL_FILENAME], *pat, *line;
  int32 len, case_sensitive, match, mode, ifail=0, max_patternsize,
        compiled_pattern[MAXIMUM_PATTERN_SIZE], result_is_null=1;
  Header h;
  extern char *get_string_data(Lisp_Object name, char *why, int32 *l);
  extern void zsinit_(int32 *mode); /* used to have return type int32 */

  /* Set up arguments as Lisp Objects */
  argcheck(nargs,4,"Lgrep");
  va_start(args,nargs);
  name = va_arg(args, Lisp_Object);
  pattern = va_arg(args, Lisp_Object);
  casep = va_arg(args, Lisp_Object);
  matchp = va_arg(args, Lisp_Object);
  va_end(args);


  /* Translate arguments into C objects */

  if (!is_vector(pattern) || !(type_of_header(vechdr(pattern)) == TYPE_STRING) )
    return aerror("grep");

  pat = get_string_data(pattern,"grep",&len);

  if (casep == lisp_true)
    case_sensitive = 1;
  else
    case_sensitive = 0;

  if (matchp == lisp_true)
    match = 1;
  else
    match = 0;

  /* Initialise the matcher to egrep mode */
  mode = 2;
  zsinit_(&mode);

  /* Compile the pattern */
  max_patternsize=MAXIMUM_PATTERN_SIZE;
  zscpat_(pat,&case_sensitive,compiled_pattern,&max_patternsize,
          &ifail,len);
  if (ifail != 0) return aerror1("Invalid regular expression", pattern);

  /* Test to see whether we are dealing with a list of strings or a file */
  if (is_cons(name))
    return grepList(nil, name, case_sensitive, match, compiled_pattern);

  /* Sort out the filename */
#ifdef COMMON
  if (complex_stringp(name))
  {   name = simplify_string(name);
      errexit();
      h = vechdr(name);
  }
  else
#endif
      if (symbolp(name))
      {   name = get_pname(name);
          errexit();
          h = vechdr(name);
      }
  else if (!(is_vector(name))) return aerror("grep");
  else if (type_of_header(h = vechdr(name)) != TYPE_STRING)
      return aerror("grep");
  len = length_of_header(h) - 4;
  if (len >= sizeof(filename)) len = sizeof(filename);

  /* Check whether file is readable using method desfined in SYS.c */
  if (!file_readable(filename,
                     (char *)name + (4 - TAG_VECTOR),
                     (size_t)len) ) return aerror1("Cannot read",name);
  /* Open file */
  fp = fopen(filename,"r");
  if (!fp) return aerror("Error opening file in grep - should not happen!");

  while (!feof(fp)) {
    line = read_a_line(fp);

    if (match == zsfind_(line,&ifail,&ifail,compiled_pattern,strlen(line))){
      if (result_is_null) {
        result = Lncons(nil,make_string(line));
        result_is_null = 0;
      }
      else
        result = Lcons(nil,make_string(line),result);
    }
    else
      free((void *)line);
  }

  fclose(fp);
  if (result_is_null)
    return(nil);
  else
    return(Lnreverse(nil,result));
}

Lisp_Object grepList(Lisp_Object nil, Lisp_Object string_list, 
                     int32 case_sensitive, int32 match,
                     int32 *compiled_pattern)
{
  Lisp_Object lstring, result;
  char *str;
  int32 ifail=0, result_is_null=1;

  while (string_list != nil) {

    lstring = Lcar(nil,string_list);
    if (!is_vector(lstring) || type_of_header(vechdr(lstring)) != TYPE_STRING)
      aerror1("error in grep, non-string in list",lstring);
    str=&celt(lstring,0);

    if (match == zsfind_(str,&ifail,&ifail,compiled_pattern,strlen(str)))
      if (result_is_null) {
        result = Lncons(nil,lstring);
        result_is_null = 0;
      }
      else
        result = Lcons(nil,lstring,result);

    string_list = Lcdr(nil,string_list);
  }

  if (result_is_null)
    return(nil);
  else
    return(Lnreverse(nil,result));
}

setup_type const grep_setup[] =
{
    {"grep",  wrong_no_na,    wrong_no_nb,    Lgrep},
    {NULL,      0,              0,              0}
};

/* end of grep2.c */
