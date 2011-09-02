#include <stdarg.h>
#include "machine.h"
#include "tags.h"
#include "externs.h"
#include "cslerror.h"


/* Signature: 2edc7539 08-Apr-2002 */


extern Lisp_Object om_read(Lisp_Object, Lisp_Object);
extern Lisp_Object om_supportsCD(Lisp_Object, Lisp_Object);
extern Lisp_Object om_supportsSymbol(Lisp_Object, Lisp_Object, Lisp_Object);
extern Lisp_Object MS_CDECL om_listCDs(Lisp_Object, int, ...);
extern Lisp_Object om_listSymbols(Lisp_Object, Lisp_Object);
extern Lisp_Object om_whichCDs(Lisp_Object, Lisp_Object);


setup_type const om_parse_setup[] = {
	/* LISP Name */			/* Unary */		/* Binary */		/* Nary */
	{"om-read",				om_read,		too_many_1,			wrong_no_1},
	{"om-supportsCD",		om_supportsCD,	too_many_1,			wrong_no_1},
	{"om-supportsSymbol",	too_few_2,		om_supportsSymbol,	wrong_no_2},
	{"om-listCDs",			wrong_no_0a,	wrong_no_0b,		om_listCDs},
	{"om-listSymbols",		om_listSymbols,	too_many_1,			wrong_no_1},
	{"om-whichCDs",			om_whichCDs,	too_many_1,			wrong_no_1},

	{NULL,	0,	0,	0}
};
