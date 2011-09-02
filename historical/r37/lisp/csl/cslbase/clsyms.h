/* clsyms.h                          Copyright (C) Codemist Ltd, 1994-2002 */


/*
 * Header defining the vector of literals just used in Common Lisp mode.
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

/* Signature: 5bf74b6b 08-Apr-2002 */

#ifndef header_clsyms_h
#define header_clsyms_h 1

#define nicknames_symbol  elt(qvalue(cl_symbols), 0)  /* :nicknames       */
#define use_symbol        elt(qvalue(cl_symbols), 1)  /* :use             */
#define and_symbol        elt(qvalue(cl_symbols), 2)  /* and              */
#define or_symbol         elt(qvalue(cl_symbols), 3)  /* or               */
#define not_symbol        elt(qvalue(cl_symbols), 4)  /* not              */
#define reader_workspace  elt(qvalue(cl_symbols), 5)  /* Used for #:x     */
#define named_character   elt(qvalue(cl_symbols), 6)  /* :named-character */
#define read_float_format elt(qvalue(cl_symbols), 7)  /* *read-default-float-format* */
#define short_float       elt(qvalue(cl_symbols), 8)  /* short-float */
#define single_float      elt(qvalue(cl_symbols), 9)  /* single-float */
#define double_float      elt(qvalue(cl_symbols), 10) /* double-float */
#define long_float        elt(qvalue(cl_symbols), 11) /* long-float */
#define bit_symbol        elt(qvalue(cl_symbols), 12) /* bit */
#define pathname_symbol   elt(qvalue(cl_symbols), 13) /* pathname */
#define print_array_sym   elt(qvalue(cl_symbols), 14) /* *print-array* */
#define read_base         elt(qvalue(cl_symbols), 15) /* *read-base* */
#define initial_element   elt(qvalue(cl_symbols), 16) /* :initial-element */

#endif /* header_clsyms_h */

/* end of clsyms.h */
