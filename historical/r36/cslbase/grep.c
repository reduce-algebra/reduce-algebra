/* regex.f -- translated by f2c (version of 17 January 1992  0:17:58).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

/* Signature: 6d962abc 27-Jan-1997 */

/* #include "f2c.h" */
typedef long int integer;
typedef long int logical;
typedef long ftnlen;
#define TRUE_ (1)
#define FALSE_ (0)
#define max(a,b) ((a) >= (b) ? (a) : (b))

#ifdef BSD
#include <strings.h>
#else
#include <string.h>
#endif

/* Added by Mike Dewar to provide Lisp Interface */

#include <stdio.h>

void remark_(char *s,int length)
{
  fprintf(stderr,"error: %s\n",s);
}

void zlowc_(char *retval, int retlen,char *ch, int chlen)
{
  if (retlen!=1 || chlen!=1) remark_("zlowc: Calling sequence error",0);
  *retval = isupper(*ch) ? tolower(*ch) : *ch;
}

void error_(char *s,int length)
{
  fprintf(stderr,"error: %s\n",s);
  my_exit(42);
}

/* Common Block Declarations */

struct {
    integer smode, mode2;
} xcsmod_;

#define xcsmod_1 xcsmod_

struct {
    logical isanum[256];
} xcscas_;

#define xcscas_1 xcscas_

/* opyright 1991 Numerical Algorithms Group */
/* Match any single character */
/* $pp$ANYCHR='.' */
/* $pp$ANYAPO='?' */
/* Begin character class */
/* $pp$BCLCHR='[' */
/* Beginning of line (string) */
/* $pp$BOLAPO='%' */
/* $pp$BOLCHR='^' */
/* Closure */
/* $pp$CL0CHR='*' */
/* Positive Closure */
/* $pp$CL1CHR='+' */
/* Close tag field (group) */
/* $pp$CTGAPO='}' */
/* $pp$CTGTP1='>' */
/* End character class */
/* $pp$ECLCHR=']' */
/* End of line (string) */
/* $pp$EOLCHR='$' */
/* APOLLO and TPACK1: Escape a character anywhere, @n & @t are special */
/* $pp$ESCAPO='@' */
/* EMACS and EGREP: Escape a character inside a character class, plus */
/*                  various special functions outside. */
/* $pp$ESCCHR='\\' */
/* Invert character class */
/* $pp$NOTAPO='~' */
/* $pp$NOTCHR='^' */
/* EMACS and EGREP: Optional item (i.e. 0 or 1 repeats) */
/* $pp$OPTCHR='?' */
/* Open tag field (group) */
/* $pp$OTGAPO='{' */
/* $pp$OTGTP1='<' */
/* Recall tag field (group) */
/* $pp$TAGAPO='@' */
/* $pp$TAGTP1='&' */
/* $pp$TAGCHR='\\' */
/* Transition between alphanumerics and non-alphanumerics */
/* $pp$TRNTP1=':' */
/* Modes of operation */
/* $pp$EMACS=0 */
/* $pp$APOLLO=1 */
/* $pp$EGREP=2 */
/* $pp$TPACK1=3 */

/* Internal Pattern Symbols */

/* $pp$TAGSYM=-101 */
/* $pp$CL1SYM=-102 */
/* $pp$TRNSYM=-103 */
/* $pp$EOLSYM=-104 */
/* $pp$CTGSYM=-105 */
/* $pp$CCESYM=-106 */
/* $pp$CL0SYM=-107 */
/* $pp$ANYSYM=-108 */
/* $pp$BOLSYM=-109 */
/* $pp$OTGSYM=-110 */
/* $pp$CCLSYM=-111 */
/* -112 now unused */
/* $pp$EOSSYM=-113 */
/* $pp$DASSYM=-114 */
/* $pp$ERRSYM=-115 */
/* $pp$OPTSYM=-116 */

/*  PATTERN MATCHING AND REPLACEMENT ROUTINES */

/*        CHARACTER STRING BASED */

/*     RMJI - FRIDAY 13 JANUARY 1989 */

/*     Substantially revised and enhanced by Malcolm Cohen, October 1989. */

/* ---------------------------------------------------------------------- */

/*     Z S I N I T   -   Initialise String module (regular expressions) */

/* Subroutine */ int zsinit_(mode)
integer *mode;
{
    /* Initialized data */

    static char digits[10+1] = "0123456789";
    static char lolett[26+1] = "abcdefghijklmnopqrstuvwxyz";
    static char uplett[26+1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    static integer i;

    if (*mode == 3) {
	xcsmod_1.smode = 1;
	xcsmod_1.mode2 = 3;
    } else {
	xcsmod_1.smode = *mode;
	xcsmod_1.mode2 = *mode;
    }
    for (i = 0; i <= 255; ++i) {
	xcscas_1.isanum[i] = FALSE_;
/* L100: */
    }
    for (i = 1; i <= 26; ++i) {
	xcscas_1.isanum[uplett[i - 1]] = TRUE_;
	xcscas_1.isanum[lolett[i - 1]] = TRUE_;
/* L200: */
    }
    for (i = 1; i <= 10; ++i) {
	xcscas_1.isanum[digits[i - 1]] = TRUE_;
/* L300: */
    }
} /* zsinit_ */

/* ---------------------------------------------------------------------- */

/*     Z S C P A T   -   Compile pattern specification from STRING to */
/*                       PATSTR, FLAG indicates case sensitivity (.TRUE. */
/*                       means case sensitive)... */

/* Subroutine */ int zscpat_(string, flag_, patstr, maxpsz, ifail, string_len)

char *string;
logical *flag_;
integer *patstr, *maxpsz, *ifail;
ftnlen string_len;
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer i_len();

    /* Local variables */
    static integer i, j, lastj, limit, itemp, lj, lastcl;
    extern logical xlssgc_();
    extern integer xissex_(), xisspr_(), xissnx_();

    /* Parameter adjustments */
    --patstr;

    /* Function Body */
    limit = (integer) string_len;
    if (*maxpsz <= max(limit,13)) {
	*ifail = 1;
	return 0;
    }
    *ifail = 2;

/* Save case flag */

    if (*flag_) {
	patstr[1] = 0;
    } else {
	patstr[1] = 1;
    }

/* Clear the tag fields and set the pointer to miss it */

    for (i = 2; i <= 11; ++i) {
	patstr[i] = 0;
/* L10: */
    }
    patstr[12] = 1;
    j = 13;
    lastj = j;
    lastcl = 0;
    i = 1;
L20:
    lj = j;
    if (j + 1 > *maxpsz) {
	goto L666;
    }
    if (string[i - 1] == '.' && xcsmod_1.smode != 1 || string[i - 1] == '?' &&
	     xcsmod_1.smode == 1) {
	patstr[j] = -108;
	++j;
    } else if (string[i - 1] == ':' && xcsmod_1.mode2 == 3) {
	patstr[j] = -103;
	++j;
    } else if (xcsmod_1.smode != 1 && string[i - 1] == '^' && i == 1 || 
	    xcsmod_1.smode == 1 && string[i - 1] == '%' && i == 1) {
	patstr[j] = -109;
	++j;
    } else if (string[i - 1] == '$' && i == limit) {
	patstr[j] = -104;
	++j;
    } else if (string[i - 1] == '[') {
	if (! xlssgc_(string, &i, &patstr[1], &j, maxpsz, string_len)) {
	    return 0;
	}
    } else if ((string[i - 1] == '*' || string[i - 1] == '+' || string[i - 1] 
	    == '?' && xcsmod_1.smode != 1) && i > 1) {
	lj = lastj;
	if (patstr[lj] == -109 || patstr[lj] == -107 || patstr[lj] == -102) {
	    goto L50;
	}
	if (string[i - 1] == '+') {
	    lastj = j;
L30:
	    if (lj < lastj) {
		if (j + 1 > *maxpsz) {
		    goto L666;
		}
		patstr[j] = patstr[lj];
		++j;
		++lj;
		goto L30;
	    }
	}
	if (j + 4 > *maxpsz) {
	    goto L666;
	}
	i__1 = lastj;
	for (itemp = j - 1; itemp >= i__1; --itemp) {
	    patstr[itemp + 4] = patstr[itemp];
/* L31: */
	}
	j += 4;
	if (string[i - 1] == '?') {
	    patstr[lastj] = -116;
	} else {
	    patstr[lastj] = -107;
	}
	patstr[lastj + 1] = 0;
	patstr[lastj + 2] = lastcl;
	patstr[lastj + 3] = 0;
	lastcl = lastj;
	lastj += 4;
    } else if (string[i - 1] == '{' && xcsmod_1.mode2 == 1 || string[i - 1] ==
	     '<' && xcsmod_1.mode2 == 3) {
	itemp = xissnx_(&patstr[1]);
	if (itemp <= 0) {
	    *ifail = 4;
	    goto L666;
	}
	if (j + 2 > *maxpsz) {
	    goto L666;
	}
	patstr[j] = -110;
	patstr[j + 1] = itemp;
	j += 2;
    } else if (string[i - 1] == '}' && xcsmod_1.mode2 == 1 || string[i - 1] ==
	     '>' && xcsmod_1.mode2 == 3) {
	if (j + 2 > *maxpsz) {
	    goto L666;
	}
	patstr[j] = -105;
	patstr[j + 1] = xisspr_(&patstr[1]);
	if (patstr[j + 1] <= 0) {
	    *ifail = 4;
	    return 0;
	}
	j += 2;
    } else if (string[i - 1] == '\\' && xcsmod_1.smode != 1 && i < limit) {
	++i;
	if (j + 2 > *maxpsz) {
	    goto L666;
	}
	if (string[i - 1] == '(') {
	    if (string[i] == '+' || string[i] == '*' ||
		string[i] == '?')
	      {
		/* Report error if open tag field followed by +*? */
		*ifail = 4;
		goto L666;
	      }
	    patstr[j] = -110;
	    patstr[j + 1] = xissnx_(&patstr[1]);
	} else if (string[i - 1] == ')') {
	    patstr[j] = -105;
	    patstr[j + 1] = xisspr_(&patstr[1]);
	} else if (string[i - 1] == 'b') {
	    patstr[j] = -103;
	    --j;
	} else {
	    integer tmp=i-1;
	    patstr[j] = xissex_(string, &tmp, string_len);
	    --j;
	}
	if (patstr[j + 1] <= 0 && patstr[j + 1] != -103) {
	    *ifail = 4;
	    goto L666;
	}
	j += 2;
    } else {
	patstr[j] = xissex_(string, &i, string_len);
	++j;
    }
    lastj = lj;
    ++i;
    if (i <= limit) {
	goto L20;
    }
L50:
    if (j <= *maxpsz) {
	patstr[j] = -113;
	for (i = 2; i <= 11; ++i) {
	    patstr[i] = 0;
/* L60: */
	}
	patstr[12] = 1;
	j = 13;
	*ifail = 0;
	return 0;
    }
/* Some sort of error found - mark the pattern as invalid */
L666:
    remark_("Invalid pattern",15L);
    patstr[13] = -115;
} /* zscpat_ */

/* ---------------------------------------------------------------------- */

/*     Z S F I N D   -   Match the string against the compiled pattern */

logical zsfind_(string, start, finish, patstr, string_len)
char *string;
integer *start, *finish, *patstr;
ftnlen string_len;
{
    /* System generated locals */
    integer i__1;
    logical ret_val;

    /* Builtin functions */
    integer i_len();

    /* Local variables */
    static integer i, n;
    extern integer xissam_();

    /* Parameter adjustments */
    --patstr;

    /* Function Body */
    if (patstr[13] == -115) {
	remark_("Pattern is in error", 19L);
    } else {
/* Loop along the line until a match is found */
	i__1 = (integer) string_len;
	for (i = 1; i <= i__1; ++i) {
	    n = xissam_(string, &i, &patstr[1], string_len);
	    if (n > 0) {
		ret_val = TRUE_;
		*start = i;
		*finish = n - 1;
		return ret_val;
	    }
/* L10: */
	}
    }
    ret_val = FALSE_;
    return ret_val;
} /* zsfind_ */

/* ---------------------------------------------------------------------- */

/*     X I S S A M   -   Function to look for a pattern match */

integer xissam_(lin, from, patstr, lin_len)
char *lin;
integer *from, *patstr;
ftnlen lin_len;
{
    /* System generated locals */
    integer ret_val;

    /* Builtin functions */
    integer i_len();

    /* Local variables */
    static integer i, j, stack, offset;
    extern logical xlssom_();
    extern integer xissps_();

    /* Parameter adjustments */
    --patstr;

    /* Function Body */
    stack = 0;
    offset = *from;
    j = 13;
L10:
    if (patstr[j] != -113) {
	if (patstr[j] == -107 || patstr[j] == -116) {
	    stack = j;
	    j += 4;
	    i = offset;
L20:
	    if (i <= (integer) lin_len) {
		if (xlssom_(lin, &i, &j, &patstr[1], lin_len)) {
		    if (patstr[stack] != -116) {
			goto L20;
		    }
		}
	    }
	    patstr[stack + 1] = i - offset;
	    patstr[stack + 3] = offset;
	    offset = i;
	} else if (! xlssom_(lin, &offset, &j, &patstr[1], lin_len)) {
L40:
	    if (stack > 0) {
		if (patstr[stack + 1] <= 0) {
		    stack = patstr[stack + 2];
		    goto L40;
		}
	    }
	    if (stack <= 0) {
		ret_val = 0;
		return ret_val;
	    }
	    --patstr[stack + 1];
	    j = stack + 4;
	    offset = patstr[stack + 3] + patstr[stack + 1];
	}
	j += xissps_(&j, &patstr[1]);
	goto L10;
    }
/* Match found, return pointer to end of match */
    ret_val = offset;
    return ret_val;
} /* xissam_ */

/* ---------------------------------------------------------------------- */

/*     X S S S C T   -   Function to close a tag field and save the */
/*                       current pointer value. */

/* Subroutine */ int xsssct_(point, n, string)
integer *point, *n, *string;
{
    static integer temp;

    /* Parameter adjustments */
    --string;

    /* Function Body */
    if (*n >= 1 && *n <= 9) {
	temp = string[*n + 2] / 256;
	string[*n + 2] = *point + (temp << 8);
    }
} /* xsssct_ */

/* ---------------------------------------------------------------------- */

/*     X I S S N X   -   Function to return an index to the next free tag */
/*                       field identifier. */

integer xissnx_(string)
integer *string;
{
    /* System generated locals */
    integer ret_val;

    /* Parameter adjustments */
    --string;

    /* Function Body */
    if (string[12] > 9) {
	ret_val = -1;
    } else {
	ret_val = string[12];
	++string[12];
    }
    return ret_val;
} /* xissnx_ */

/* ---------------------------------------------------------------------- */

/*     X S S S O P   -   Function to open a tag field and save the start */
/*                       position. */

/* Subroutine */ int xsssop_(point, n, string)
integer *point, *n, *string;
{
    /* Parameter adjustments */
    --string;

    /* Function Body */
    if (*n >= 1 && *n <= 9) {
/* Save current pointer in tag field array */
	string[*n + 2] = *point << 8;
    }
} /* xsssop_ */

/* ---------------------------------------------------------------------- */

/*     X I S S P R   -   Function to return the value of the current tag */
/*                       field to be closed.  The storage location in */
/*                       PATSTR is used to hold markers to indicate which */
/*                       tag fields have been closed already, these */
/*                       markers are cleared on exit from ZCOMPP. */

integer xisspr_(patstr)
integer *patstr;
{
    /* System generated locals */
    integer ret_val;

    /* Parameter adjustments */
    --patstr;

    /* Function Body */
    ret_val = patstr[12] - 1;
L10:
    if (ret_val > 0) {
	if (patstr[ret_val + 2] != 0) {
	    --ret_val;
	    goto L10;
	} else {
	    patstr[ret_val + 2] = 1;
	}
    }
    return ret_val;
} /* xisspr_ */

/* ---------------------------------------------------------------------- */

/*     X S S S D O   -   Expand pattern class range */

logical xsssdo_(valid, array, i, set, j, maxset, valid_len, array_len)
char *valid, *array;
integer *i, *set, *j, *maxset;
ftnlen valid_len;
ftnlen array_len;
{
    /* System generated locals */
    integer i__1;
    logical ret_val;
    char ch__1[1];

    /* Builtin functions */
    integer i_indx();

    /* Local variables */
    static integer k, limit;
    extern integer xissex_();

    /* Added by ICH */
    char *valid_null_term;

    /* Parameter adjustments */
    --set;

    /* Function Body */
    ++(*i);
    --(*j);
    ch__1[0] = xissex_(array, i, array_len);
    /* limit = i_indx(valid, ch__1, valid_len, 1L); */
    valid_null_term = (char *) malloc(valid_len+1);
    strncpy(valid_null_term,valid,(int) valid_len);
    valid_null_term[valid_len]='\0';
    limit = (integer) ((strchr(valid_null_term,ch__1[0]) - valid_null_term) + 1);
    if (limit<0)
      limit=0;
    ch__1[0] = set[*j];
/*  if (*j + limit - i_indx(valid, ch__1, valid_len, 1L) + 1 <= *maxset) { */
    if (*j + limit - (integer) (strchr(valid_null_term,ch__1[0])
				- valid_null_term + 1) + 1 <= *maxset) {
	ch__1[0] = set[*j];
	i__1 = limit;
	for (k = (integer) (strchr(valid_null_term,ch__1[0])
			    - valid_null_term + 1); k <= i__1; ++k) {
	    set[*j] = valid[k - 1];
	    ++(*j);
/* L10: */
	}
	ret_val = TRUE_;
    } else {
	ret_val = FALSE_;
    }
    free((void *)valid_null_term);
    return ret_val;
} /* xsssdo_ */

/* ---------------------------------------------------------------------- */

/*     X I S S E X   -   Un-escape a single character */

integer xissex_(array, i, array_len)
char *array;
integer *i;
ftnlen array_len;
{
    /* System generated locals */
    integer ret_val;

    if (array[*i - 1] == '@' && xcsmod_1.smode == 1 || array[*i - 1] == '\\' 
	    && xcsmod_1.smode != 1) {
	++(*i);
	if (array[*i - 1] == 'n') {
	    ret_val = 10;
	} else if (array[*i - 1] == 't') {
	    ret_val = 9;
	} else {
	    ret_val = array[*i - 1];
	}
    } else {
	ret_val = array[*i - 1];
    }
    return ret_val;
} /* xissex_ */

/* ---------------------------------------------------------------------- */

/*     X S S S F I   -   Fill a character class set for pattern matching */

/* Subroutine */ int xsssfi_(array, i, set, j, maxset, array_len)
char *array;
integer *i, *set, *j, *maxset;
ftnlen array_len;
{
    /* System generated locals */
    char ch__1[1];

    /* Builtin functions */
    integer i_len(), i_indx();

    /* Local variables */
    static logical ok;
    extern integer xissex_();
    extern logical xsssdo_();

    /* Parameter adjustments */
    --set;

    /* Function Body */
L10:
    ok = *j + 1 < *maxset;
    if (ok && array[*i - 1] != ']') {
	if (array[*i - 1] == '\\' && xcsmod_1.smode != 1 || array[*i - 1] == 
		'@' && xcsmod_1.smode == 1) {
/* Character has been escaped */
	    set[*j] = xissex_(array, i, array_len);
	    ++(*j);
	} else if (array[*i - 1] != '-') {
	    set[*j] = array[*i - 1];
	    ++(*j);
	} else if (*j <= 1 || *i == (integer) array_len) {
	    set[*j] = -114;
	    ++(*j);
	} else /* if(complicated condition) */ {
	    ch__1[0] = set[*j - 1];
/*	    if (i_indx("0123456789", ch__1, 10L, 1L) > 0) { */
	    if (*ch__1>='0' && *ch__1<='9') {
		ok = xsssdo_("0123456789", array, i, &set[1], j, maxset, 10L, 
			array_len);
	    } else /* if(complicated condition) */ {
		ch__1[0] = set[*j - 1];
/*	if (i_indx("abcdefghijklmnopqrstuvwxyz", ch__1, 26L, 1L) > 0) */
		if (*ch__1>='a' && *ch__1<='z' ) 
			{
		    ok = xsssdo_("abcdefghijklmnopqrstuvwxyz", array, i, &set[
			    1], j, maxset, 26L, array_len);
		} else /* if(complicated condition) */ {
		    ch__1[0] = set[*j - 1];
/*	       if (i_indx("ABCDEFGHIJKLMNOPQRSTUVWXYZ", ch__1, 26L, 1L) */
	       if ( *ch__1>='A' && *ch__1<='Z') {
			ok = xsssdo_("ABCDEFGHIJKLMNOPQRSTUVWXYZ", array, i, &
				set[1], j, maxset, 26L, array_len);
		    } else {
			set[*j] = -114;
			++(*j);
		    }
		}
	    }
	}
	++(*i);
	if (*i <= (integer) array_len) {
	    goto L10;
	}
    }
} /* xsssfi_ */

/* ---------------------------------------------------------------------- */

/*     X L S S G C   -   Get character class */

logical xlssgc_(arg, i, pat, j, maxpsz, arg_len)
char *arg;
integer *i, *pat, *j, *maxpsz;
ftnlen arg_len;
{
    /* System generated locals */
    logical ret_val;

    /* Local variables */
    static integer jstart;
    extern /* Subroutine */ int xsssfi_();
    static integer sym;

    /* Parameter adjustments */
    --pat;

    /* Function Body */
    ++(*i);
/* Check if an inclusive or exclusive set is being requested */
    if (arg[*i - 1] == '^' && xcsmod_1.smode != 1 || arg[*i - 1] == '~' && 
	    xcsmod_1.smode == 1) {
	++(*i);
	sym = -106;
    } else {
	sym = -111;
    }
    if (*j + 2 <= *maxpsz) {
	pat[*j] = sym;
	pat[*j + 1] = 0;
	jstart = *j + 1;
	*j += 2;
	xsssfi_(arg, i, &pat[1], j, maxpsz, arg_len);
	pat[jstart] = *j - jstart - 1;
/* Check to see if pattern filled in ok */
	ret_val = arg[*i - 1] == ']';
    } else {
	ret_val = FALSE_;
    }
    return ret_val;
} /* xlssgc_ */

/* ---------------------------------------------------------------------- */

/*     X L S S L O   -   Match a single character against a char set */

logical xlsslo_(c, pat, offset, c_len)
char *c;
integer *pat, *offset;
ftnlen c_len;
{
    /* System generated locals */
    logical ret_val;

    /* Local variables */
    static integer i;

    /* Parameter adjustments */
    --pat;

    /* Function Body */
    i = *offset + pat[*offset];
L10:
    if (i > *offset) {
	if (*c == pat[i]) {
	    ret_val = TRUE_;
	    return ret_val;
	}
	--i;
	goto L10;
    }
    ret_val = FALSE_;
    return ret_val;
} /* xlsslo_ */

/* ---------------------------------------------------------------------- */

/*     X L S S O M   -   Match a single pattern */

logical xlssom_(lin, i, j, patstr, lin_len)
char *lin;
integer *i, *j, *patstr;
ftnlen lin_len;
{
    /* System generated locals */
    integer i__1;
    logical ret_val;
    char ch__1[1], ch__2[1], ch__3[1];

    /* Builtin functions */
    integer i_len();

    /* Local variables */
    static integer bump;
    extern logical xlsslo_();
    extern /* Subroutine */ int xsssct_(), xsssop_();

/* Set initial (invalid) value for pointer update */
    /* Parameter adjustments */
    --patstr;

    /* Function Body */
    bump = -1;
/* Open tag field */
    if (patstr[*j] == -110) {
	bump = 0;
	xsssop_(i, &patstr[*j + 1], &patstr[1]);
/* Close tag field */
    } else if (patstr[*j] == -105) {
	bump = 0;
	xsssct_(i, &patstr[*j + 1], &patstr[1]);
/* Transition (or end or line or beginning of line) */
    } else if (patstr[*j] == -103) {
	if (*i > (integer) lin_len || *i == 1) {
	    bump = 0;
	} else {
	    i__1 = *i - 2;
	    if (xcscas_1.isanum[lin[*i - 1]] != xcscas_1.isanum[lin[i__1]]) {
		bump = 0;
/*              ELSE IF (I.GT.1) THEN */
/*              IF (ICHAR(LIN(I:I)).EQ.10) BUMP = 0 */
	    }
	}
/* End of the line */
    } else if (*i > (integer) lin_len) {
	if (patstr[*j] == -104) {
	    bump = 0;
	}
    } else if (patstr[*j] == -104) {
	if (lin[*i - 1] == 10) {
	    bump = 0;
	}
/* Ordinary character */
    } else if (patstr[*j] > 0) {
	if (patstr[1] == 1) {
	    zlowc_(ch__1, 1L, lin + (*i - 1), 1L);
	    ch__3[0] = patstr[*j];
	    zlowc_(ch__2, 1L, ch__3, 1L);
	    if (ch__1[0] == ch__2[0]) {
		bump = 1;
	    }
	} else {
	    if (lin[*i - 1] == patstr[*j]) {
		bump = 1;
	    }
	}
/* Beginning of the line */
    } else if (patstr[*j] == -109) {
	if (*i == 1) {
	    bump = 0;
	}
/* Free match (any character) */
    } else if (patstr[*j] == -108) {
	if (lin[*i - 1] != 10 && *i <= (integer) lin_len) {
	    bump = 1;
	}
/* Character class */
    } else if (patstr[*j] == -111) {
	i__1 = *j + 1;
	if (xlsslo_(lin + (*i - 1), &patstr[1], &i__1, 1L)) {
	    bump = 1;
	}
/* Negated character class */
    } else if (patstr[*j] == -106) {
	i__1 = *j + 1;
	if (lin[*i - 1] != 10 && *i <= (integer) lin_len && ! xlsslo_(lin + 
		(*i - 1), &patstr[1], &i__1, 1L)) {
	    bump = 1;
	}
/* Otherwise */
    } else {
	error_("Invalid compiled pattern", 24L);
    }
/* If bump is no longer -1 then a match has been found */
    if (bump >= 0) {
	*i += bump;
    }
    ret_val = bump >= 0;
    return ret_val;
} /* xlssom_ */

/* ---------------------------------------------------------------------- */

/*     X I S S P S   -   Return size of pattern entry */

integer xissps_(n, patstr)
integer *n, *patstr;
{
    /* System generated locals */
    integer ret_val;

    /* Parameter adjustments */
    --patstr;

    /* Function Body */
    if (patstr[*n] > 0) {
	ret_val = 1;
    } else if (patstr[*n] == -109 || patstr[*n] == -104 || patstr[*n] == -108 
	    || patstr[*n] == -103) {
	ret_val = 1;
    } else if (patstr[*n] == -111 || patstr[*n] == -106) {
	ret_val = patstr[*n + 1] + 2;
    } else if (patstr[*n] == -107) {
	ret_val = 4;
    } else if (patstr[*n] == -110 || patstr[*n] == -105) {
	ret_val = 2;
    } else {
	error_("XISSPS: Invalid pattern entry found", 35L);
    }
    return ret_val;
} /* xissps_ */
