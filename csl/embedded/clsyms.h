/* clsyms.h                          Copyright (C) Codemist Ltd, 1994-2008 */


/*
 * Header defining the vector of literals just used in Common Lisp mode.
 */


/**************************************************************************
 * Copyright (C) 2008, Codemist Ltd.                     A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

/* Signature: 66d3b906 24-May-2008 */

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
