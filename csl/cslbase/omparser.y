/*
 Copyright (c) 1991-2002, The Numerical Algorithms Group Ltd.
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are
 met:
 
     - Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
 
     - Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in
       the documentation and/or other materials provided with the
       distribution.
 
     - Neither the name of The Numerical ALgorithms Group Ltd. nor the
       names of its contributors may be used to endorse or promote products
       derived from this software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES-- LOSS OF USE, DATA, OR
 PROFITS-- OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

%{
/* Note that BISON, from version 1.24 onwards, permits arbitrary use
 * of its output file despite the parser skeleton being under GPL not
 * LGPL. See the comments in the BISON output, and be careful to avoid
 * earlier releases of BISON.
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <malloc.h>

#include "machine.h"
#include "tags.h"
#include "cslerror.h"
#include "externs.h"
#include "entries.h"
#include "arith.h"
#include "cslread.h"

#include <OM.h>
#include <OMconn.h>
#include "openmath.h"

#define YYSTYPE Lisp_Object

#define StrToLspM(S) qcar(Lmv_list(C_nil, Lintern(C_nil, make_string(S))))
#define MkUndefSymM(x) make_undefined_symbol(x)

/* Enable parser debugging. */
#define YYDEBUG 0

/* Prototypes for required parser interface functions. */
int yyerror(char *);
YYSTYPE yylex();

/*
 * External CCL functions.
 */
extern char *get_string_data(Lisp_Object name, char *why, int32_t *l);

/* Some global variables (yuk!). */
static Lisp_Object ldev;
static Lisp_Object inObj;

/* End of preamble. */
%}

/*----------------------------------------------------------------------------
 * Adding support for a new CD:
 *
 * 1. Add a new token declaration for each symbol in the CD.
 * 2. Add a new rule which matches any of the symbols from that CD; add that
 *    rule as one of the alternate forms for the om_symbol rule. This rule
 *    should be called om_newcd_symbol, where newcd is the name of the CD.
 * 3. Add a new rule for matching an application of any symbol from that CD,
 *    with the appropriate arguments; this should be called something like
 *    om_apply_newcd_inner, where newcd is as before. This rule should be
 *    added as one of the alternate forms matched by the om_apply_inner rule.
 *    Note that (obviously) this rule should omit symbols which are only valid
 *    as binders.
 * 4. Add a new rule for matching a bind with any symbol from that CD as a
 *    binder; this should be called something like om_bind_newcd_inner, where
 *    newcd is as before. This rule should be added as one of the alternate
 *    forms matched by the om_bind_inner rule. Note that (obviously) this rule
 *    should omit symbols which are not valid as binders.
 * 5. Add the symbols from the new CD to the symTable list in the C code
 *    section.
 * 6. Test it!
 */

/*
 * TOKEN DECLARATIONS
 */

/* Token for signalling a parsing error. */
%token OM_YYERROR

/* Tokens for OpenMath primitives. */
%token OM_INT OM_FLOAT OM_BYTEARRAY OM_VAR OM_STRING OM_SYMBOL
%token OM_APP OM_ENDAPP
%token OM_ATP OM_ENDATP OM_ATTR OM_ENDATTR
%token OM_BIND OM_ENDBIND OM_BVAR OM_ENDBVAR
%token OM_ERROR OM_ENDERROR
%token OM_OBJECT OM_ENDOBJECT

/* Tokens for symbols from the alg1 CD. */
%token OM_SYM_alg1_zero
%token OM_SYM_alg1_one

/* Tokens for symbols from the arith1 CD. */
%token OM_SYM_arith1_abs
%token OM_SYM_arith1_divide
%token OM_SYM_arith1_gcd
%token OM_SYM_arith1_lcm
%token OM_SYM_arith1_minus
%token OM_SYM_arith1_plus
%token OM_SYM_arith1_power
%token OM_SYM_arith1_product
%token OM_SYM_arith1_root
%token OM_SYM_arith1_sum
%token OM_SYM_arith1_times
%token OM_SYM_arith1_unary_minus

/* Tokens for symbols from the arith2 CD. */
%token OM_SYM_arith2_arg
%token OM_SYM_arith2_inverse
%token OM_SYM_arith2_times

/* Tokens for symbols from the bigfloat CD. */
%token OM_SYM_bigfloat1_bigfloat

/* Tokens for symbols from the calculus1 CD. */
%token OM_SYM_calculus1_defint
%token OM_SYM_calculus1_diff
%token OM_SYM_calculus1_int
%token OM_SYM_calculus1_partialdiff

/* Tokens for symbols from the complex1 CD. */
%token OM_SYM_complex1_argument
%token OM_SYM_complex1_complex_cartesian
%token OM_SYM_complex1_complex_polar
%token OM_SYM_complex1_conjugate
%token OM_SYM_complex1_imaginary
%token OM_SYM_complex1_real

/* Tokens for symbols from the fns1 CD. */
%token OM_SYM_fns1_domain
%token OM_SYM_fns1_range
%token OM_SYM_fns1_image
%token OM_SYM_fns1_identity
%token OM_SYM_fns1_inverse
%token OM_SYM_fns1_lambda
%token OM_SYM_fns1_left_compose

/* Tokens for symbols from the fns2 CD. */
%token OM_SYM_fns2_apply_to_list
%token OM_SYM_fns2_kernel
%token OM_SYM_fns2_right_compose

/* Tokens for symbols from the integer1 CD. */
%token OM_SYM_integer1_factorial
%token OM_SYM_integer1_factorof
%token OM_SYM_integer1_quotient
%token OM_SYM_integer1_remainder

/* Tokens for symbols from the interval1 CD. */
%token OM_SYM_interval1_integer_interval
%token OM_SYM_interval1_interval
%token OM_SYM_interval1_interval_cc
%token OM_SYM_interval1_interval_co
%token OM_SYM_interval1_interval_oc
%token OM_SYM_interval1_interval_oo

/* Tokens for symbols from the limit1 CD. */
%token OM_SYM_limit1_above
%token OM_SYM_limit1_below
%token OM_SYM_limit1_both_sides
%token OM_SYM_limit1_limit
%token OM_SYM_limit1_null

/* Tokens for symbols from the linalg1 CD. */
%token OM_SYM_linalg1_determinant
%token OM_SYM_linalg1_matrix_selector
%token OM_SYM_linalg1_vector_selector
%token OM_SYM_linalg1_transpose
%token OM_SYM_linalg1_outerproduct
%token OM_SYM_linalg1_scalarproduct
%token OM_SYM_linalg1_vectorproduct

/* Tokens for symbols from the linalg2 CD. */
%token OM_SYM_linalg2_matrix
%token OM_SYM_linalg2_matrixrow
%token OM_SYM_linalg2_vector

/* Tokens for symbols from the linalg3 CD. */
%token OM_SYM_linalg3_matrix
%token OM_SYM_linalg3_matrixcolumn
%token OM_SYM_linalg3_vector

/* Tokens for symbols from the list1 CD. */
%token OM_SYM_list1_list
%token OM_SYM_list1_map
%token OM_SYM_list1_suchthat

/* Tokens for symbols from the list2 CD. */
%token OM_SYM_list2_cons
%token OM_SYM_list2_first
%token OM_SYM_list2_rest

/* Tokens for symbols from the logic1 CD. */
%token OM_SYM_logic1_and
%token OM_SYM_logic1_false
%token OM_SYM_logic1_implies
%token OM_SYM_logic1_not
%token OM_SYM_logic1_or
%token OM_SYM_logic1_true
%token OM_SYM_logic1_xor
%token OM_SYM_logic1_equivalent

/* Tokens for symbols from the minmax1 CD. */
%token OM_SYM_minmax1_max
%token OM_SYM_minmax1_min

/* The CD multiset1 is not supported. */

/* Tokens for symbols from the nums1 CD. */
%token OM_SYM_nums1_based_integer
%token OM_SYM_nums1_e
%token OM_SYM_nums1_gamma
%token OM_SYM_nums1_i
%token OM_SYM_nums1_infinity
%token OM_SYM_nums1_NaN
%token OM_SYM_nums1_pi
%token OM_SYM_nums1_rational

/* The quant1 CD is not supported. */

/* Tokens for symbols from the relation1 CD. */
%token OM_SYM_relation1_eq
%token OM_SYM_relation1_geq
%token OM_SYM_relation1_gt
%token OM_SYM_relation1_leq
%token OM_SYM_relation1_lt
%token OM_SYM_relation1_neq
%token OM_SYM_relation1_approx

/* Tokens for symbols from the rounding1 CD. */
%token OM_SYM_rounding1_ceiling
%token OM_SYM_rounding1_floor
%token OM_SYM_rounding1_trunc
%token OM_SYM_rounding1_round

/* Tokens for symbols from the setname1 CD. */
%token OM_SYM_setname1_C
%token OM_SYM_setname1_N
%token OM_SYM_setname1_P
%token OM_SYM_setname1_Q
%token OM_SYM_setname1_R
%token OM_SYM_setname1_Z

/* Tokens for symbols from the set1 CD. */
%token OM_SYM_set1_cartesian_product
%token OM_SYM_set1_emptyset
%token OM_SYM_set1_in
%token OM_SYM_set1_intersect
%token OM_SYM_set1_map
%token OM_SYM_set1_notin
%token OM_SYM_set1_notprsubset
%token OM_SYM_set1_notsubset
%token OM_SYM_set1_prsubset
%token OM_SYM_set1_set
%token OM_SYM_set1_setdiff
%token OM_SYM_set1_size
%token OM_SYM_set1_subset
%token OM_SYM_set1_suchthat
%token OM_SYM_set1_union

/* The stats1 CD is not supported. */

/* Tokens for symbols from the transc1 CD. */
%token OM_SYM_transc1_arccos
%token OM_SYM_transc1_arcsin
%token OM_SYM_transc1_arctan
%token OM_SYM_transc1_cos
%token OM_SYM_transc1_cosh
%token OM_SYM_transc1_cot
%token OM_SYM_transc1_coth
%token OM_SYM_transc1_csc
%token OM_SYM_transc1_csch
%token OM_SYM_transc1_exp
%token OM_SYM_transc1_ln
%token OM_SYM_transc1_log
%token OM_SYM_transc1_sec
%token OM_SYM_transc1_sech
%token OM_SYM_transc1_sin
%token OM_SYM_transc1_sinh
%token OM_SYM_transc1_tan
%token OM_SYM_transc1_tanh
%token OM_SYM_transc1_arccosh
%token OM_SYM_transc1_arccot
%token OM_SYM_transc1_arccoth
%token OM_SYM_transc1_arccsc
%token OM_SYM_transc1_arccsch
%token OM_SYM_transc1_arcsec
%token OM_SYM_transc1_arcsech
%token OM_SYM_transc1_arcsinh
%token OM_SYM_transc1_arctanh

/* The CD veccalc1 is not supported. */

%%

/*
 * PARSING RULES
 */

om_whole_object:
		OM_OBJECT om_object OM_ENDOBJECT
			{ $$ = $2; inObj = $2; YYACCEPT; }
;

om_attributes:
		/* empty */
	|	om_symbol_inner om_object om_attributes
			{ /* TODO */ }
;

om_variables:
		/* empty */
			{ $$ = C_nil; }
	|	om_variable om_variables
			{ $$ = cons($1, $2); }
;

om_object:
		om_integer
	|	om_float
	|	om_bytearray
	|	om_variable
	|	om_string
	|	om_symbol
	|	om_apply
	|	om_bind
/*	|	om_error	*/
;

om_integer:
		OM_INT
			{ $$ = $1; }
	|	OM_ATTR OM_ATP om_attributes OM_ENDATP OM_INT OM_ENDATTR
			{ $$ = $5; }
;

om_float:
		OM_FLOAT
			{ $$ = $1; }
	|	OM_ATTR OM_ATP om_attributes OM_ENDATP OM_FLOAT OM_ENDATTR
			{ $$ = $5; }
;

om_bytearray:
		OM_BYTEARRAY
			{ $$ = $1; }
	|	OM_ATTR OM_ATP om_attributes OM_ENDATP OM_BYTEARRAY OM_ENDATTR
			{ $$ = $5; }
;

om_variable:
		OM_VAR
			{ $$ = $1; }
	|	OM_ATTR OM_ATP om_attributes OM_ENDATP OM_VAR OM_ENDATTR
			{ $$ = $5; }
;

om_string:
		OM_STRING
			{ $$ = $1; }
	|	OM_ATTR OM_ATP om_attributes OM_ENDATP OM_STRING OM_ENDATTR
			{ $$ = $5; }
;

om_symbol:
		om_symbol_inner
			{ $$ = $1; }
	|	OM_ATTR OM_ATP om_attributes OM_ENDATP om_symbol_inner OM_ENDATTR
			{ $$ = $5; }
;

om_symbol_inner:
		OM_SYMBOL
	|	om_alg1_symbol
	|	om_arith1_symbol
	|	om_arith2_symbol
	|	om_bigfloat1_symbol
	|	om_calculus1_symbol
	|	om_complex1_symbol
	|	om_fns1_symbol
	|	om_fns2_symbol
	|	om_integer1_symbol
	|	om_interval1_symbol
	|	om_limit1_symbol
	|	om_linalg1_symbol
	|	om_linalg2_symbol
	|	om_linalg3_symbol
	|	om_list1_symbol
	|	om_list2_symbol
	|	om_logic1_symbol
	|	om_minmax1_symbol
	|	om_nums1_symbol
	|	om_relation1_symbol
	|	om_rounding1_symbol
	|	om_setname1_symbol
	|	om_set1_symbol
	|	om_transc1_symbol
;

om_alg1_symbol:
		OM_SYM_alg1_zero
	|	OM_SYM_alg1_one
;

om_arith1_symbol:
		OM_SYM_arith1_abs
	|	OM_SYM_arith1_divide
	|	OM_SYM_arith1_gcd
	|	OM_SYM_arith1_lcm
	|	OM_SYM_arith1_minus
	|	OM_SYM_arith1_plus
	|	OM_SYM_arith1_power
	|	OM_SYM_arith1_product
	|	OM_SYM_arith1_root
	|	OM_SYM_arith1_sum
	|	OM_SYM_arith1_times
	|	OM_SYM_arith1_unary_minus
;

om_arith2_symbol:
		OM_SYM_arith2_arg
	|	OM_SYM_arith2_inverse
	|	OM_SYM_arith2_times
;

om_bigfloat1_symbol:
		OM_SYM_bigfloat1_bigfloat
;

om_calculus1_symbol:
		OM_SYM_calculus1_defint
	|	OM_SYM_calculus1_diff
	|	OM_SYM_calculus1_int
	|	OM_SYM_calculus1_partialdiff
;

om_complex1_symbol:
		OM_SYM_complex1_argument
	|	OM_SYM_complex1_complex_cartesian
	|	OM_SYM_complex1_complex_polar
	|	OM_SYM_complex1_conjugate
	|	OM_SYM_complex1_imaginary
	|	OM_SYM_complex1_real
;

om_fns1_symbol:
		OM_SYM_fns1_identity
	|	OM_SYM_fns1_inverse
	|	OM_SYM_fns1_lambda
	|	OM_SYM_fns1_left_compose
	|	OM_SYM_fns1_domain
	|	OM_SYM_fns1_range
	|	OM_SYM_fns1_image
;

om_fns2_symbol:
		 OM_SYM_fns2_apply_to_list
	|	 OM_SYM_fns2_kernel
	|	 OM_SYM_fns2_right_compose
;

om_integer1_symbol:
		OM_SYM_integer1_factorial
	|	OM_SYM_integer1_factorof
	|	OM_SYM_integer1_quotient
	|	OM_SYM_integer1_remainder
;

om_interval1_symbol:
		OM_SYM_interval1_integer_interval
	|	OM_SYM_interval1_interval
	|	OM_SYM_interval1_interval_cc
	|	OM_SYM_interval1_interval_co
	|	OM_SYM_interval1_interval_oc
	|	OM_SYM_interval1_interval_oo
;

om_limit1_symbol:
		OM_SYM_limit1_above
	|	OM_SYM_limit1_below
	|	OM_SYM_limit1_both_sides
	|	OM_SYM_limit1_limit
	|	OM_SYM_limit1_null
;

om_linalg2_symbol:
		OM_SYM_linalg2_matrix
	|	OM_SYM_linalg2_matrixrow
	|	OM_SYM_linalg2_vector
;

om_linalg3_symbol:
		OM_SYM_linalg3_matrix
	|	OM_SYM_linalg3_matrixcolumn
	|	OM_SYM_linalg3_vector
;

om_linalg1_symbol:
		OM_SYM_linalg1_determinant
	|	OM_SYM_linalg1_matrix_selector
	|	OM_SYM_linalg1_vector_selector
	|	OM_SYM_linalg1_transpose
	|	OM_SYM_linalg1_outerproduct
	|	OM_SYM_linalg1_scalarproduct
	|	OM_SYM_linalg1_vectorproduct
;

om_list1_symbol:
		OM_SYM_list1_list
	|	OM_SYM_list1_map
	|	OM_SYM_list1_suchthat
;

om_list2_symbol:
		OM_SYM_list2_cons
	|	OM_SYM_list2_first
	|	OM_SYM_list2_rest
;

om_logic1_symbol:
		OM_SYM_logic1_and
	|	OM_SYM_logic1_false
	|	OM_SYM_logic1_implies
	|	OM_SYM_logic1_not
	|	OM_SYM_logic1_or
	|	OM_SYM_logic1_true
	|	OM_SYM_logic1_xor
	|	OM_SYM_logic1_equivalent
;

om_minmax1_symbol:
		OM_SYM_minmax1_max
	|	OM_SYM_minmax1_min
;

om_nums1_symbol:
		OM_SYM_nums1_based_integer
	|	OM_SYM_nums1_e
	|	OM_SYM_nums1_gamma
	|	OM_SYM_nums1_i
	|	OM_SYM_nums1_infinity
	|	OM_SYM_nums1_NaN
	|	OM_SYM_nums1_pi
	|	OM_SYM_nums1_rational
;

om_relation1_symbol:
		OM_SYM_relation1_eq
	|	OM_SYM_relation1_geq
	|	OM_SYM_relation1_gt
	|	OM_SYM_relation1_leq
	|	OM_SYM_relation1_lt
	|	OM_SYM_relation1_neq
	|	OM_SYM_relation1_approx
;

om_rounding1_symbol:
		OM_SYM_rounding1_ceiling
	|	OM_SYM_rounding1_floor
	|	OM_SYM_rounding1_trunc
	|	OM_SYM_rounding1_round
;

om_setname1_symbol:
		OM_SYM_setname1_C
	|	OM_SYM_setname1_N
	|	OM_SYM_setname1_P
	|	OM_SYM_setname1_Q
	|	OM_SYM_setname1_R
	|	OM_SYM_setname1_Z
;

om_set1_symbol:
		OM_SYM_set1_cartesian_product
	|	OM_SYM_set1_emptyset
	|	OM_SYM_set1_map
	|	OM_SYM_set1_size
	|	OM_SYM_set1_suchthat
	|	OM_SYM_set1_in
	|	OM_SYM_set1_intersect
	|	OM_SYM_set1_notin
	|	OM_SYM_set1_notprsubset
	|	OM_SYM_set1_notsubset
	|	OM_SYM_set1_prsubset
	|	OM_SYM_set1_set
	|	OM_SYM_set1_setdiff
	|	OM_SYM_set1_subset
	|	OM_SYM_set1_union
;

om_transc1_symbol:
		OM_SYM_transc1_arccos
	|	OM_SYM_transc1_arcsin
	|	OM_SYM_transc1_arctan
	|	OM_SYM_transc1_cos
	|	OM_SYM_transc1_cosh
	|	OM_SYM_transc1_cot
	|	OM_SYM_transc1_coth
	|	OM_SYM_transc1_csc
	|	OM_SYM_transc1_csch
	|	OM_SYM_transc1_exp
	|	OM_SYM_transc1_ln
	|	OM_SYM_transc1_log
	|	OM_SYM_transc1_sec
	|	OM_SYM_transc1_sech
	|	OM_SYM_transc1_sin
	|	OM_SYM_transc1_sinh
	|	OM_SYM_transc1_tan
	|	OM_SYM_transc1_tanh
	|	OM_SYM_transc1_arccosh
	|	OM_SYM_transc1_arccot
	|	OM_SYM_transc1_arccoth
	|	OM_SYM_transc1_arccsc
	|	OM_SYM_transc1_arccsch
	|	OM_SYM_transc1_arcsec
	|	OM_SYM_transc1_arcsech
	|	OM_SYM_transc1_arcsinh
	|	OM_SYM_transc1_arctanh
;

/* A generic rule that will be used within some of the apply and bind rules. */
om_nary_args:
		/* empty */
			{ $$ = C_nil; }
	|	om_object om_nary_args
			{ $$ = cons($1, $2); }
;

/* A generic rule that will be used within some of the apply and bind rules. */
om_unary_func:
		om_variable
			/* Note: the variable must contain a unary function for
			 * it to be valid here. */
			{ 	Lisp_Object var = MkUndefSymM("x");
				push2($1,var);
				$$ = list2(list2($1, var), var);
				pop2(var,$1);
			}
	|	om_symbol
			/* Note: the symbol must represent a unary function for it to be
			 * valid here. */
			{ 	Lisp_Object var = MkUndefSymM("x");
				push2($1,var);
				$$ = list2(list2($1, var), var);
				pop2(var,$1);
			}
	|	om_apply
			/* Note: the _result_ of the om_apply must be a unary function for
			 * it to be valid here. */
			{ 	Lisp_Object var = MkUndefSymM("x");
				push2($1,var);
				$$ = list2(list2($1, var), var);
				pop2(var,$1);
			}
	|	OM_BIND OM_SYM_fns1_lambda OM_BVAR om_variable OM_ENDBVAR om_object OM_ENDBIND
			/* This is the only kind of OMBIND that we allow here. */
			{	push2($6, $4);
        			$$ = list2($6, $4);
				pop2($4, $6);
			}
;

om_apply:
		OM_APP om_apply_inner OM_ENDAPP
			{ $$ = $2; }
	|	OM_ATTR OM_ATP om_attributes OM_ENDATP OM_APP om_apply_inner OM_ENDAPP OM_ENDATTR
			{ $$ = $6; }
;

om_apply_inner:
		om_apply_alg1_inner
	|	om_apply_arith1_inner
	|	om_apply_arith2_inner
	|	om_apply_bigfloat1_inner
	|	om_apply_calculus1_inner
	|	om_apply_complex1_inner
	|	om_apply_fns1_inner
	|	om_apply_fns2_inner
	|	om_apply_integer1_inner
	|	om_apply_interval1_inner
	|	om_apply_limit1_inner
	|	om_apply_linalg1_inner
	|	om_apply_linalg2_inner
	|	om_apply_linalg3_inner
	|	om_apply_list1_inner
	|	om_apply_list2_inner
	|	om_apply_logic1_inner
	|	om_apply_minmax1_inner
	|	om_apply_nums1_inner
	|	om_apply_relation1_inner
	|	om_apply_rounding1_inner
	|	om_apply_set1_inner
	|	om_apply_transc1_inner
	|	om_apply_boundexpr_inner
;

om_apply_alg1_inner:
		OM_SYM_alg1_zero
			{ $$ = fixnum_of_int(0); }
	|	OM_SYM_alg1_one
			{ $$ = fixnum_of_int(1); }
;

om_apply_arith1_inner:
		OM_SYM_arith1_abs om_object
			{	push2($1,$2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_arith1_divide om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
	|	OM_SYM_arith1_gcd om_nary_args
			{	push2($1,$2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_arith1_lcm om_nary_args
			{	push2($1,$2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_arith1_minus om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
	|	OM_SYM_arith1_plus
			{ $$ = fixnum_of_int(0); }
	|	OM_SYM_arith1_plus om_arith1_plus_args
			{ $$ = $2; }
	|	OM_SYM_arith1_power om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
	|	OM_SYM_arith1_product om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
	|	OM_SYM_arith1_root om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
	|	OM_SYM_arith1_sum om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
	|	OM_SYM_arith1_times
			{ $$ = $1; }
	|	OM_SYM_arith1_times om_arith1_times_args
			{ $$ = $2; }
	|	OM_SYM_arith1_unary_minus om_object
			{	push2($1,$2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
;

om_arith1_plus_args:
		om_object
			{ $$ = $1; }
	|	om_object om_arith1_plus_args
			{	Lisp_Object obj = StrToLspM("+");
				push3(obj, $1, $2);
				$$ = list3(obj, $1, $2);
				pop3($2, $1, obj);
			}
;

om_arith1_times_args:
		om_object
			{	$$ = $1; }
	|	om_object om_arith1_times_args
			{	Lisp_Object obj = StrToLspM("*");
				push3(obj, $1, $2);
				$$ = list3(obj, $1, $2);
				pop3($2, $1, obj);
			}
;

om_apply_arith2_inner:
		OM_SYM_arith2_arg om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_arith2_inverse om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_arith2_times
			{ $$ = $1; }
	|	OM_SYM_arith2_times om_arith1_times_args
		/* Note: we intentionally reuse om_arith1_times_args rule here, 
		 * to save work. */
			{ $$ = $2; }
;

om_apply_bigfloat1_inner:
		OM_SYM_bigfloat1_bigfloat om_object om_object om_object
			{	push4($1, $2, $3, $4);
				$$ = cons($1, list3($2, $4, $3));
				pop4($4, $3, $2, $1);
			}
;

om_apply_calculus1_inner:
		OM_SYM_calculus1_defint om_calculus1_interval om_unary_func
			{/*	(|integrate| function range) */
			 /*	FIXME: needs to treat more general cases as well... */
				push3($1, $2, $3);
				$$ = list3(
					$1,
					qcar($3),
					list3(
						StrToLspM("="),
						qcar(qcdr($3)),
						$2
					)
				);
				pop3($3, $2, $1);
			}
	|	OM_SYM_calculus1_diff om_unary_func
			{ $$ = cons($1, $2); }
	|	OM_SYM_calculus1_int om_unary_func
			{	push2($1, $2);
			        $$ = $2;
				$$ = cons($1, $2); 
				pop2($2, $1);
			}
	|	OM_SYM_calculus1_partialdiff om_object om_calculus1_partialdiff_funcarg
			{/* (|differentiate| function (|construct| vars...)) */
				Lisp_Object varIndList, varList;
				Lisp_Object funcObj, quoteObj;

				push($2);
				varIndList = Ceval($2, C_nil);
				pop($2);
				push($3);
				varList = qcar($3);
				funcObj = qcar(qcdr($3));
				pop($3);

				/* Get names corresponding to variable indices.
				 */
				quoteObj = StrToLspM("QUOTE");

				push3(quoteObj, varList, varIndList); 
				varList = list3(
					StrToLspM("MAPCAR"),
					list2(
						quoteObj,
						list3(
							StrToLspM("LAMBDA"),
							cons(MkUndefSymM("i"), C_nil),
							list3(
								StrToLspM("NTH"),
								list3(
									StrToLspM("-"),
									MkUndefSymM("i"),
									fixnum_of_int(1)),
								list2(quoteObj, varList)))),
					list2(quoteObj, varIndList));
				pop3(varIndList, varList, quoteObj);

				push(varList);
				varList = Ceval(varList, C_nil);
				varList = cons(
					StrToLspM("construct"),
					varList);
				pop(varList);

				push3($1, funcObj, varList);
				$$ = list3($1, funcObj, varList);
				pop3(varList, funcObj, $1);
			}
;

om_calculus1_interval:
		OM_APP OM_SYM_interval1_integer_interval om_object om_object OM_ENDAPP
			{	/* (|segment| lo hi) */
				push3($2, $3, $4);
				$$ = list3($2, $3, $4);
				pop3($4, $3, $2);
			}
	|	OM_APP om_calculus1_interval_symbol om_object om_object OM_ENDAPP
			{	Lisp_Object segObj = StrToLspM("segment");
				Lisp_Object coerceObj = StrToLspM("::");
				Lisp_Object typeObj = list2(StrToLspM("Fraction"), StrToLspM("Integer"));
				push3(segObj, coerceObj, typeObj);
				$$ = list3(
					segObj,
					list3(coerceObj, $3, typeObj),
					list3(coerceObj, $4, typeObj)
				);
				pop3(typeObj, coerceObj, segObj);
			}
;

om_calculus1_interval_symbol:
		OM_SYM_interval1_interval
	|	OM_SYM_interval1_interval
	|	OM_SYM_interval1_interval
	|	OM_SYM_interval1_interval
	|	OM_SYM_interval1_interval
;

/* This will make sure that the semantic value returned is of the form
 * ((vars) func) to make life easier... */
om_calculus1_partialdiff_funcarg:
		OM_BIND OM_SYM_fns1_lambda OM_BVAR om_variables OM_ENDBVAR om_object OM_ENDBIND
			{	push2($4, $6);
				$$ = list2($4, $6);
				pop2($6, $4);
			}
;

om_apply_complex1_inner:
		OM_SYM_complex1_argument om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_complex1_complex_cartesian om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
	|	OM_SYM_complex1_complex_polar om_object om_object
			{	push3($1, $2, $3);
				/* Unhandled Symbol */
				$$ = list3($1, make_string("complex_polar"), make_string("complex1"));
				pop3($3, $2, $1);
			}
	|	OM_SYM_complex1_conjugate om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_complex1_imaginary om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_complex1_real om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
;

/* Note that the lambda symbol does not appear here because it is only valid
 * as a binder. */
om_apply_fns1_inner:
		OM_SYM_fns1_identity om_object
			{ $$ = $2; }
	|	OM_SYM_fns1_inverse om_object
			{ $$ = list3($1, make_string("inverse"), make_string("fns1")); }
	|	OM_SYM_fns1_image om_object
			{	push2($1, $2);
				$$ = list3($1, make_string("image"), make_string("fns1"));
				pop2($1, $2);
			}
	|	OM_SYM_fns1_range om_object
			{	push2($1, $2);
				$$ = list3($1, make_string("range"), make_string("fns1"));
				pop2($1, $2);
			}
	|	OM_SYM_fns1_domain om_object
			{	push2($1, $2);
				$$ = list3($1, make_string("domain"), make_string("fns1"));
				pop2($1, $2);
			}
	|	OM_SYM_fns1_left_compose om_unary_func om_unary_func
			{/*	(ADEF (bv2) (NIL NIL) (NIL NIL) (func1 (func2 bv2))) */
				Lisp_Object types, bv1, bv2, func1, func2;
				types = list2(C_nil, C_nil);
				func1 = qcar($2);
				bv1 = qcar(qcdr($2));
				func2 = qcar($3);
				bv2 = qcar(qcdr($3));

				push3(func1, func2, bv1);
				func1 = Ceval(
					cons(
						StrToLspM("SUBST"),
						list3(
							list2(StrToLspM("QUOTE"), func2),
							list2(StrToLspM("QUOTE"), bv1),
							list2(StrToLspM("QUOTE"), func1)
						)
					),
					C_nil
				);
				pop3(bv1, func2, func1);

				push4($1, bv2, types, func1);
				$$ = cons($1, cons(cons(bv2, C_nil), list3(types, types, func1)));
				pop4(func1, types, bv2, $1);
			}
;

om_apply_fns2_inner:
		 OM_SYM_fns2_apply_to_list om_unary_func om_object
			{	push3($1,$2,$3);
				$$ = list3($1,$2,$3);
				pop3($3,$2,$1);
			}
	|	 OM_SYM_fns2_kernel om_unary_func
				{$$ = list3($1, make_string("kernel"), make_string("fns2")); }
		|	 OM_SYM_fns2_right_compose om_unary_func om_unary_func
				{/*	(ADEF (bv1) (NIL NIL) (NIL NIL) (func2 (func1 bv1))) */
					Lisp_Object types, bv1, bv2, func1, func2;
					types = list2(C_nil, C_nil);
					func1 = qcar($2);
					bv1 = qcar(qcdr($2));
					func2 = qcar($3);
					bv2 = qcar(qcdr($3));

					push3(func1, func2, bv2);
					func1 = Ceval(
						cons(
							StrToLspM("SUBST"),
							list3(
								list2(StrToLspM("QUOTE"), func1),
								list2(StrToLspM("QUOTE"), bv2),
								list2(StrToLspM("QUOTE"), func2)
							)
						),
						C_nil
					);
					pop3(bv2, func2, func1);

					push4($1, bv2, types, func2);
					$$ = cons($1, cons(cons(bv1, C_nil), list3(types, types, func2)));
					pop4(func2, types, bv2, $1);
				}
	;

	om_apply_integer1_inner:
			OM_SYM_integer1_factorial om_object
				{	push2($1, $2);
					$$ = list2($1, $2);
					pop2($2, $1);
				}
		|	OM_SYM_integer1_factorof om_object om_object
				{	push3($1, $2, $3);
					$$ = list3($1, make_string("factorof"), make_string("integer1"));
					pop3($3, $2, $1);
			}
	|	OM_SYM_integer1_quotient om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
	|	OM_SYM_integer1_remainder om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
;

om_apply_interval1_inner:
		OM_SYM_interval1_integer_interval om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
	|	OM_SYM_interval1_interval om_object om_object
			{	Lisp_Object interpObj = StrToLspM("@");
				Lisp_Object typeObj = list2(
					StrToLspM("Interval"),
					StrToLspM("DoubleFloat")
				);
				push5($1, $2, $3, interpObj, typeObj);
				$$ = list3(interpObj, list3($1, $2, $3), typeObj);
				pop5(typeObj, interpObj, $3, $2, $1);
			}
	|	OM_SYM_interval1_interval_cc om_object om_object
			{	Lisp_Object interpObj = StrToLspM("@");
				Lisp_Object typeObj = list2(
					StrToLspM("Interval"),
					StrToLspM("DoubleFloat")
				);
				push5($1, $2, $3, interpObj, typeObj);
				$$ = list3(interpObj, list3($1, $2, $3), typeObj);
				pop5(typeObj, interpObj, $3, $2, $1);
			}
	|	OM_SYM_interval1_interval_co om_object om_object
			{	Lisp_Object interpObj = StrToLspM("@");
				Lisp_Object typeObj = list2(
					StrToLspM("Interval"),
					StrToLspM("DoubleFloat")
				);
				double dLo = float_of_number($2);
				double dHi = float_of_number($3);
				if (dLo > dHi) {
					double dt = dLo;
					dLo = dHi;
					dHi = dt;
				}
				dHi -= DBL_EPSILON;
				push3($1, interpObj, typeObj);
				$$ = list3(interpObj, list3($1,
					make_boxfloat(dLo, TYPE_DOUBLE_FLOAT),
					make_boxfloat(dHi, TYPE_DOUBLE_FLOAT)
				), typeObj);
				pop3(typeObj, interpObj, $1);
			}
	|	OM_SYM_interval1_interval_oc om_object om_object
			{	Lisp_Object interpObj = StrToLspM("@");
				Lisp_Object typeObj = list2(
					StrToLspM("Interval"),
					StrToLspM("DoubleFloat")
				);
				double dLo = float_of_number($2);
				double dHi = float_of_number($3);
				if (dLo > dHi) {
					double dt = dLo;
					dLo = dHi;
					dHi = dt;
				}
				dLo += DBL_EPSILON;
				push3($1, interpObj, typeObj);
				$$ = list3(interpObj, list3($1,
					make_boxfloat(dLo, TYPE_DOUBLE_FLOAT),
					make_boxfloat(dHi, TYPE_DOUBLE_FLOAT)
				), typeObj);
				pop3(typeObj, interpObj, $1);
			}
	|	OM_SYM_interval1_interval_oo om_object om_object
			{	Lisp_Object interpObj = StrToLspM("@");
				Lisp_Object typeObj = list2(
					StrToLspM("Interval"),
					StrToLspM("DoubleFloat")
				);
				double dLo = float_of_number($2);
				double dHi = float_of_number($3);
				if (dLo > dHi) {
					double dt = dLo;
					dLo = dHi;
					dHi = dt;
				}
				dLo += DBL_EPSILON;
				dHi -= DBL_EPSILON;
				push3($1, interpObj, typeObj);
				$$ = list3(interpObj, list3($1,
					make_boxfloat(dLo, TYPE_DOUBLE_FLOAT),
					make_boxfloat(dHi, TYPE_DOUBLE_FLOAT)
				), typeObj);
				pop3(typeObj, interpObj, $1);
			}
;

om_apply_limit1_inner:
		OM_SYM_limit1_limit om_object OM_SYM_limit1_above om_unary_func
			{/* (|limit| func (|=| var limiting_val) "right") */
				Lisp_Object limitVal;
				push2($4, $2);
				limitVal = list3(
					StrToLspM("="),
					qcar(qcdr($4)),
					list3(
						StrToLspM("::"),
						$2,
						list2(
							StrToLspM("Fraction"),
							StrToLspM("Integer")
						)
					)
				);
				pop2($2, $4);
				push2($1, $4);
				$$ = cons($1, list3(qcar($4), limitVal, make_string("right")));
				pop2($4, $1);
			}
	|	OM_SYM_limit1_limit om_object OM_SYM_limit1_below om_unary_func
			{/* (|limit| func (|=| var limiting_val) "left") */
				Lisp_Object limitVal;
				push2($4, $2);
				limitVal = list3(
					StrToLspM("="),
					qcar(qcdr($4)),
					list3(
						StrToLspM("::"),
						$2,
						list2(
							StrToLspM("Fraction"),
							StrToLspM("Integer")
						)
					)
				);
				pop2($2, $4);
				push2($1, $4);
				$$ = cons($1, list3(qcar($4), limitVal, make_string("left")));
				pop2($4, $1);
			}
	|	OM_SYM_limit1_limit om_object OM_SYM_limit1_both_sides om_unary_func
			{/* (|limit| func (|=| var limiting_val)) */
				Lisp_Object limitVal;
				push2($4, $2);
				limitVal = list3(
					StrToLspM("="),
					qcar(qcdr($4)),
					list3(
						StrToLspM("::"),
						$2,
						list2(
							StrToLspM("Fraction"),
							StrToLspM("Integer")
						)
					)
				);
				pop2($2, $4);
				push2($1, $4);
				$$ = list3($1, qcar($4), limitVal);
				pop2($4, $1);
			}
	|	OM_SYM_limit1_limit om_object OM_SYM_limit1_null om_unary_func
			{/* (|limit| func (|=| var limiting_val)) */
				Lisp_Object limitVal;
				push2($4, $2);
				limitVal = list3(
					StrToLspM("="),
					qcar(qcdr($4)),
					list3(
						StrToLspM("::"),
						$2,
						list2(
							StrToLspM("Fraction"),
							StrToLspM("Integer")
						)
					)
				);
				pop2($2, $4);
				push2($1, $4);
				$$ = list3($1, qcar($4), limitVal);
				pop2($4, $1);
			}
;

om_apply_linalg2_inner:
		OM_SYM_linalg2_matrix om_linalg2_matrix_args
			{	Lisp_Object obj = StrToLspM("construct");
				push2($1, $2);
				$$ = list2($1, cons(obj, $2));
				pop2($2, $1);
			}
	|	OM_SYM_linalg2_matrixrow om_nary_args
			{ $$ = cons($1, $2); }
	|	OM_SYM_linalg2_vector om_nary_args
			{ $$ = cons($1, $2); }
;

om_linalg2_matrix_args:
		/* empty */
			{ $$ = C_nil; }
	|	OM_APP OM_SYM_linalg2_matrixrow om_nary_args OM_ENDAPP om_linalg2_matrix_args
			{ $$ = cons(cons($2, $3), $5); }
;

om_apply_linalg3_inner:
		OM_SYM_linalg3_matrix om_linalg3_matrix_args
			{	Lisp_Object cns = StrToLspM("construct");
				Lisp_Object trn = StrToLspM("transpose");
				push4(trn, $1, cns, $2);
				$$ = list2(trn, list2($1, cons(cns, $2)));
				pop4($2, cns, $1, trn);
			}
	|	OM_SYM_linalg3_matrixcolumn om_nary_args
			{ $$ = cons($1, $2); }
	|	OM_SYM_linalg3_vector om_nary_args
			{ $$ = cons($1, $2); }
;

om_linalg3_matrix_args:
		/* empty */
			{ $$ = C_nil; }
	|	OM_APP OM_SYM_linalg3_matrixcolumn om_nary_args OM_ENDAPP om_linalg3_matrix_args
			{ $$ = cons( cons($2, $3), $5 ); }
;

om_apply_linalg1_inner:
		OM_SYM_linalg1_determinant om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_linalg1_matrix_selector om_object om_object om_object
			{ $$ = cons($1, list3($3, $4, $2)); }
	|	OM_SYM_linalg1_vector_selector om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $3, $2);
				pop3($3, $2, $1);
			}
	|	OM_SYM_linalg1_transpose om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_linalg1_outerproduct om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
	|	OM_SYM_linalg1_scalarproduct om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
	|	OM_SYM_linalg1_vectorproduct om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
;

om_apply_list1_inner:
		OM_SYM_list1_list om_nary_args
			{ $$ = cons($1, $2); }
	|	OM_SYM_list1_map om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
	|	OM_SYM_list1_suchthat om_object om_object
			{ /* Deliberately swap arguments for AXIOM */
			 	push3($1, $2, $3);
				$$ = list3($1, $3, $2);
				pop3($3, $2, $1);
			}
;

/* This rule will always return the list (x expr), where x is the name of
 * the bound variable in the expression and expr is some expression involving
 * x. */
om_list1_funcarg:
		om_variable
			/* Note: the variable must contain a unary function
			 * for it to be valid here. */
			{	Lisp_Object var = MkUndefSymM("x");
				push2($1, var);
				$$ = list2(var, list2($1, var)); 
				pop2(var, $1);
			}
	|	om_symbol
			/* Note: the symbol must represent a unary function
			 * for it to be valid here. */
			{	Lisp_Object var = MkUndefSymM("x");
				push2($1, var);
				$$ = list2(var, list2($1, var)); 
				pop2(var, $1);
			}
	|	om_apply
			/* Note: the _result_ of the om_apply must be a unary
			 * function for it to be valid here. */
			{	Lisp_Object var = MkUndefSymM("x");
				push2($1, var);
				$$ = list2(var, list2($1, var)); 
				pop2(var, $1);
			}
	|	om_list1_anonymous_funcarg
			{ $$ = $1; }
	|	OM_ATTR OM_ATP om_attributes OM_ENDATP om_list1_anonymous_funcarg OM_ENDATTR
			{ $$ = $5; }
;

om_list1_anonymous_funcarg:
		OM_BIND OM_SYM_fns1_lambda OM_BVAR om_variable OM_ENDBVAR om_object OM_ENDBIND
			/* This is the only kind of OMBIND that we allow here. */
			{	push2($4, $6);
				$$ = list2($4, $6);
				pop2($6, $4);
			}
;

om_apply_list2_inner:
		OM_SYM_list2_cons om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
	|	OM_SYM_list2_first om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_list2_rest om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
;

om_apply_logic1_inner:
		OM_SYM_logic1_and
			{ $$ = $1; }
	|	OM_SYM_logic1_and om_logic1_and_args
			{ $$ = $2; }
	|	OM_SYM_logic1_false
			{ $$ = $1; }
	|	OM_SYM_logic1_implies om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
	|	OM_SYM_logic1_not om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_logic1_or
			{ $$ = $1; }
	|	OM_SYM_logic1_or om_logic1_or_args
			{ $$ = $2; }
	|	OM_SYM_logic1_true
			{ $$ = $1; }
	|	OM_SYM_logic1_xor
			{ $$ = $1; }
	|	OM_SYM_logic1_xor om_logic1_xor_args
			{ $$ = $2; }
	|	OM_SYM_logic1_equivalent om_object om_object
			{$$ = list3($1, make_string("equivalent"), make_string("logic1")); }
;

om_logic1_and_args:
		om_object
			{ $$ = $1; }
	|	om_object om_logic1_and_args
			{	Lisp_Object obj = StrToLspM("and");
				push3(obj, $1, $2);
				$$ = list3(obj, $1, $2); 
				pop3($2, $1, obj);
			}
;

om_logic1_or_args:
		om_object
			{ $$ = $1; }
	|	om_object om_logic1_or_args
			{	Lisp_Object obj = StrToLspM("or");
				push3(obj, $1, $2);
				$$ = list3(obj, $1, $2);
				pop3($2, $1, obj);
			}
;

om_logic1_xor_args:
		om_object
			{ $$ = $1; }
	|	om_object om_logic1_xor_args
			{	Lisp_Object obj = StrToLspM("xor");
				push3(obj, $1, $2);
				$$ = list3(obj, $1, $2);
				pop3($2, $1, obj);
			}
;

om_apply_minmax1_inner:
		OM_SYM_minmax1_max
			{ $$ = $1; }
	|	OM_SYM_minmax1_max om_minmax1_max_args
			{ $$ = $2; }
	|	OM_SYM_minmax1_min
			{ $$ = $1; }
	|	OM_SYM_minmax1_min om_minmax1_min_args
			{ $$ = $2; }
;

om_minmax1_max_args:
		om_object
			{ $$ = $1; }
	|	om_object om_minmax1_max_args
			{	Lisp_Object obj = StrToLspM("max");
				push3(obj, $1, $2);
				$$ = list3(obj, $1, $2);
				pop3($2, $1, obj);
			}
;

om_minmax1_min_args:
		om_object
			{ $$ = $1; }
	|	om_object om_minmax1_min_args
			{	Lisp_Object obj = StrToLspM("min");
				push3(obj, $1, $2);
				$$ = list3(obj, $1, $2);
				pop3($2, $1, obj);
			}
;

/* Note that some of the symbols from the nums1 CD are not present here as they
 * are constants and hence cannot be applied. */
om_apply_nums1_inner:
		OM_SYM_nums1_based_integer om_object om_object
			{$$ = list3($1, make_string("based_integer"), make_string("nums1")); }
	|	OM_SYM_nums1_rational om_object om_object
			{/*	(|@| (/ numer denom) (|Fraction| |Integer|)) */
				push3($1, $2, $3);
				$$ = list3(
					StrToLspM("@"),
					list3($1, $2, $3),
					list2(
						StrToLspM("Fraction"),
						StrToLspM("Integer")
					)
				);
				pop3($3, $2, $1);
			}
;

om_apply_relation1_inner:
		OM_SYM_relation1_eq om_object om_object
			{	Lisp_Object coerceObj = StrToLspM("::");
				Lisp_Object nameObj = StrToLspM("SExpression");
				push5($1, $2, $3, coerceObj, nameObj);
				$$ = list3($1,
					list3(coerceObj, $2, nameObj),
					list3(coerceObj, $3, nameObj)
				);
				pop5(nameObj, coerceObj, $3, $2, $1);
			}
	|	OM_SYM_relation1_geq om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
	|	OM_SYM_relation1_gt om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
	|	OM_SYM_relation1_leq om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
	|	OM_SYM_relation1_lt om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
	|	OM_SYM_relation1_neq om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
	|	OM_SYM_relation1_approx om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, make_string("approx"), make_string("relation1"));
				pop3($3, $2, $1);
			}
;

om_apply_rounding1_inner:
		OM_SYM_rounding1_ceiling om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_rounding1_floor om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_rounding1_trunc om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_rounding1_round om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
;

om_apply_set1_inner:
		OM_SYM_set1_in om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
	|	OM_SYM_set1_intersect om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
	|	OM_SYM_set1_notin om_object om_object
			{	Lisp_Object notObj = StrToLspM("not");
				push4(notObj, $1, $2, $3);
				$$ = list2(notObj, list3($1, $2, $3));
				pop4($3, $2, $1, notObj);
			}
	|	OM_SYM_set1_notprsubset om_object om_object
			{	Lisp_Object notObj = StrToLspM("not");
				push4(notObj, $1, $2, $3);
				$$ = list2(notObj, list3($1, $2, $3));
				pop4($3, $2, $1, notObj);
			}
	|	OM_SYM_set1_notsubset om_object om_object
			{	Lisp_Object notObj = StrToLspM("not");
				push4(notObj, $1, $2, $3);
				$$ = list2(notObj, list3($1, $2, $3));
				pop4($3, $2, $1, notObj);
			}
	|	OM_SYM_set1_prsubset om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
	|	OM_SYM_set1_set om_nary_args
			{
				$$ = cons($1, $2);
			}
	|	OM_SYM_set1_setdiff om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
	|	OM_SYM_set1_subset om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
	|	OM_SYM_set1_union om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
	|	OM_SYM_set1_size om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_set1_cartesian_product om_nary_args
			{	push2($1, $2);
				$$ = list3($1, make_string("cartesian_product"), make_string("set1"));
				pop2($2, $1);
			}
	|	OM_SYM_set1_emptyset
			{	push($1);
				$$ = Llist(C_nil, $1);
				pop($1);
			}
	|	OM_SYM_set1_map om_object om_object
			{	push3($1, $2, $3);
				$$ = list3($1, $2, $3);
				pop3($3, $2, $1);
			}
	|	OM_SYM_set1_suchthat om_object om_object
			{ /* Deliberately swap arguments for AXIOM */
			 	push3($1, $2, $3);
				$$ = list3($1, $3, $2);
				pop3($3, $2, $1);
			}
;

om_apply_transc1_inner:
		OM_SYM_transc1_arccos om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_transc1_arcsin om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_transc1_arctan om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_transc1_cos om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_transc1_cosh om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_transc1_cot om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_transc1_coth om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_transc1_csc om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_transc1_csch om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_transc1_exp om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_transc1_ln om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_transc1_log om_object om_object
			{	Lisp_Object obj = StrToLspM("/");
				push4(obj, $1, $2, $3);
				$$ = list3(obj, list2($1, $3), list2($1, $2));
				pop4($3, $2, $1, obj);
			}
	|	OM_SYM_transc1_sec om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_transc1_sech om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_transc1_sin om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_transc1_sinh om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_transc1_tan om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_transc1_tanh om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_transc1_arccosh om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_transc1_arccot om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_transc1_arccoth om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_transc1_arccsc om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_transc1_arccsch om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_transc1_arcsec om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_transc1_arcsech om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_transc1_arcsinh om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
	|	OM_SYM_transc1_arctanh om_object
			{	push2($1, $2);
				$$ = list2($1, $2);
				pop2($2, $1);
			}
;

om_apply_boundexpr_inner:
		om_bind om_nary_args
			{ $$ = cons($1, $2); }
;

om_bind:
		OM_BIND om_bind_inner OM_ENDBIND
			{ $$ = $2; }
	|	OM_ATTR OM_ATP om_attributes OM_ENDATP OM_BIND om_bind_inner OM_ENDBIND OM_ENDATTR
			{ $$ = $6; }
;

om_bind_inner:
		om_bind_fns1_inner
;

om_bind_fns1_inner:
		OM_SYM_fns1_lambda OM_BVAR om_variables OM_ENDBVAR om_object
			{	Lisp_Object types = C_nil;
				Lisp_Object llen = Llength(C_nil, $3);
				int len = int_of_fixnum(llen);
				int i;

				for (i = 0; i < len; i++)
					types = cons(C_nil, types);
				types = cons(C_nil, types);

				push4($1, $3, $5, types);
				$$ = cons($1, cons($3, list3(types, types, $5)));
				pop4(types, $5, $3, $1);
			}
;

%%

/* C code. */

typedef struct {
	char *cd;
	char *name;
	char *axname;
	YYSTYPE	token;
} symTableItem;

/* All symbols from the same CD must be in a contiguous group. */
static symTableItem symTable[] = {
	{"alg1",	"one",			"1",			OM_SYM_alg1_one},
	{"alg1",	"zero",			"0",			OM_SYM_alg1_zero},

	{"arith1",	"abs",			"abs",			OM_SYM_arith1_abs},
	{"arith1",	"divide",		"/",			OM_SYM_arith1_divide},
	{"arith1",	"gcd",			"gcd",			OM_SYM_arith1_gcd},
	{"arith1",	"lcm",			"lcm",			OM_SYM_arith1_lcm},
	{"arith1",	"minus",		"-",			OM_SYM_arith1_minus},
	{"arith1",	"plus",			"+",			OM_SYM_arith1_plus},
	{"arith1",	"power",		"**",			OM_SYM_arith1_power},
	{"arith1",	"product",		"product",		OM_SYM_arith1_product},
	{"arith1",	"root",			"nthRoot",		OM_SYM_arith1_root},
	{"arith1",	"sum",			"summation",	        OM_SYM_arith1_sum},
	{"arith1",	"times",		"*",			OM_SYM_arith1_times},
	{"arith1",	"unary_minus",	        "-",			OM_SYM_arith1_unary_minus},

	{"arith2",	"arg",			"argument",		OM_SYM_arith2_arg},
	{"arith2",	"inverse",		"inv",			OM_SYM_arith2_inverse},
	{"arith2",	"times",		"*",			OM_SYM_arith2_times},

	{"bigfloat1",	"bigfloat",		"float",		OM_SYM_bigfloat1_bigfloat},

	{"calculus1",	"defint",		"integrate",	        OM_SYM_calculus1_defint},
	{"calculus1",	"diff",			"differentiate",        OM_SYM_calculus1_diff},
/*MCDT*/
	{"calculus1",	"int",			"integrate",	        OM_SYM_calculus1_int},
	{"calculus1",	"partialdiff",		"differentiate",        OM_SYM_calculus1_partialdiff},

	{"complex1",	"argument",		"argument",	        OM_SYM_complex1_argument},
	{"complex1",	"complex_cartesian",	"complex",	        OM_SYM_complex1_complex_cartesian},
	{"complex1",	"complex_polar",	"OMunhandledSymbol",	OM_SYM_complex1_complex_polar},
	{"complex1",	"conjugate",		"conjugate",	        OM_SYM_complex1_conjugate},
	{"complex1",	"real",			"real",		        OM_SYM_complex1_real},
	{"complex1",	"imaginary",		"imaginary",	        OM_SYM_complex1_imaginary},

	/* dummy name: no equivalent Axiom function. */
	{"fns1",	"identity",		"OMunhandledSymbol",	OM_SYM_fns1_identity},
	{"fns1",	"range",		"OMunhandledSymbol",	OM_SYM_fns1_range},
	{"fns1",	"image",		"OMunhandledSymbol",	OM_SYM_fns1_image},
	{"fns1",	"domain",		"OMunhandledSymbol",	OM_SYM_fns1_domain},
	{"fns1",	"inverse",		"OMunhandledSymbol",	OM_SYM_fns1_inverse},
	{"fns1",	"lambda",		"ADEF",			OM_SYM_fns1_lambda},
	{"fns1",	"left_compose",	        "ADEF",			OM_SYM_fns1_left_compose},

	{"fns2",	"apply_to_list",	"reduce",		OM_SYM_fns2_apply_to_list},
	{"fns2",	"kernel",		"OMunhandledSymbol",	OM_SYM_fns2_kernel},
	/* FIXME: find out the axiom name for this. */
/*	{"fns2",		"right_compose","????",			OM_SYM_fns2_right_compose},*/

	{"integer1",	"factorial",	        "factorial",	        OM_SYM_integer1_factorial},
	{"integer1",	"factorof",	        "OMunhandledSymbol",	OM_SYM_integer1_factorof},
	{"integer1",	"quotient",		"quo",			OM_SYM_integer1_quotient},
	{"integer1",	"rem",			"rem",			OM_SYM_integer1_remainder},

	{"interval1",	"integer_interval",	"segment",	        OM_SYM_interval1_integer_interval},
	{"interval1",	"interval",		"interval",		OM_SYM_interval1_interval},
	{"interval1",	"interval_cc",	        "interval",		OM_SYM_interval1_interval_cc},
	{"interval1",	"interval_co",	        "interval",		OM_SYM_interval1_interval_co},
	{"interval1",	"interval_oc",	        "interval",		OM_SYM_interval1_interval_oc},
	{"interval1",	"interval_oo",	        "interval",		OM_SYM_interval1_interval_oo},

	{"limit1",	"above",		"right",		OM_SYM_limit1_above},
	{"limit1",	"below",		"left",			OM_SYM_limit1_below},
	{"limit1",	"both_sides",	        "neither",		OM_SYM_limit1_both_sides}, /* dummy name */
	{"limit1",	"limit",		"limit",	        OM_SYM_limit1_limit},
	{"limit1",	"null",			"neither",	        OM_SYM_limit1_null},	   /* dummy name */

	{"linalg1",	"determinant",		"determinant",	        OM_SYM_linalg1_determinant},
	{"linalg1",	"matrix_selector",	"elt",		        OM_SYM_linalg1_matrix_selector},
	{"linalg1",	"vector_selector",	"elt",		        OM_SYM_linalg1_vector_selector},
	{"linalg1",	"transpose",		"transpose",	        OM_SYM_linalg1_transpose},
	{"linalg1",	"outerproduct",		"outerproduct",	        OM_SYM_linalg1_outerproduct},
	{"linalg1",	"scalarproduct",	"dot",		        OM_SYM_linalg1_scalarproduct},
	{"linalg1",	"vectorproduct",	"cross",	        OM_SYM_linalg1_vectorproduct},

	{"linalg2",	"matrix",		"matrix",	        OM_SYM_linalg2_matrix},
	{"linalg2",	"matrixrow",		"construct",	        OM_SYM_linalg2_matrixrow},
	{"linalg2",	"vector",		"vector",	        OM_SYM_linalg2_vector},

	{"linalg3",	"matrix",		"matrix",	        OM_SYM_linalg3_matrix},
	{"linalg3",	"matrixcolumn",		"construct",	        OM_SYM_linalg3_matrixcolumn},
	{"linalg3",	"vector",		"vector",	        OM_SYM_linalg3_vector},

	{"list1",	"list",			"construct",	        OM_SYM_list1_list},
	{"list1",	"map",			"map",		        OM_SYM_list1_map},
	{"list1",	"suchthat",		"select",		OM_SYM_list1_suchthat},

	{"list2",	"cons",			"cons",			OM_SYM_list2_cons},
	{"list2",	"first",		"first",		OM_SYM_list2_first},
	{"list2",	"rest",			"rest",			OM_SYM_list2_rest},

	{"logic1",	"and",			"and",			OM_SYM_logic1_and},
	{"logic1",	"false",		"false",		OM_SYM_logic1_false},
	{"logic1",	"implies",		"implies",		OM_SYM_logic1_implies},
	{"logic1",	"not",			"not",			OM_SYM_logic1_not},
	{"logic1",	"or",			"or",			OM_SYM_logic1_or},
	{"logic1",	"true",			"true",			OM_SYM_logic1_true},
	{"logic1",	"xor",			"xor",			OM_SYM_logic1_xor},
	{"logic1",	"equivalent",		"OMunhandledSymbol",	OM_SYM_logic1_equivalent},

	{"minmax1",	"max",			"max",			OM_SYM_minmax1_max},
	{"minmax1",	"min",			"min",			OM_SYM_minmax1_min},

	{"nums1",	"based_integer",	"OMunhandledSymbol",	OM_SYM_nums1_based_integer},
	{"nums1",	"e",			"%e",		        OM_SYM_nums1_e},
/*	{"nums1",	"gamma",		"????",		        OM_SYM_nums1_gamma},*/
	{"nums1",	"i",			"%i",		        OM_SYM_nums1_i},
	{"nums1",	"infinity",		"%infinity",	        OM_SYM_nums1_infinity},
	{"nums1",	"NaN",			"OMunhandledSymbol",	OM_SYM_nums1_NaN},
	{"nums1",	"pi",			"%pi",		        OM_SYM_nums1_pi},
	{"nums1",	"rational",		"/",		        OM_SYM_nums1_rational},

	{"relation1",	"eq",			"eq",			OM_SYM_relation1_eq},
	{"relation1",	"geq",			">=",			OM_SYM_relation1_geq},
	{"relation1",	"gt",			">",			OM_SYM_relation1_gt},
	{"relation1",	"leq",			"<=",			OM_SYM_relation1_leq},
	{"relation1",	"lt",			"<",			OM_SYM_relation1_lt},
	{"relation1",	"neq",			"~=",			OM_SYM_relation1_neq},

	{"relation1",	"approx",		"OMunhandledSymbol",	OM_SYM_relation1_approx},

	{"rounding1",	"ceiling",		"ceiling",		OM_SYM_rounding1_ceiling},
	{"rounding1",	"floor",		"floor",		OM_SYM_rounding1_floor},
	{"rounding1",	"trunc",		"truncate",		OM_SYM_rounding1_trunc},
	{"rounding1",	"round",		"round",		OM_SYM_rounding1_round},

	/* FIXME: how to represent these in Axiom? */
/*	{"setname1",	"C",			"????",			OM_SYM_setname1_C},*/
/*	{"setname1",	"N",			"????",			OM_SYM_setname1_N},*/
/*	{"setname1",	"P",			"????",			OM_SYM_setname1_P},*/
/*	{"setname1",	"Q",			"????",			OM_SYM_setname1_Q},*/
/*	{"setname1",	"R",			"????",			OM_SYM_setname1_R},*/
/*	{"setname1",	"Z",			"????",			OM_SYM_setname1_Z},*/

	{"set1",	"in",			"member?",		OM_SYM_set1_in},
	{"set1",	"intersect",	        "intersect",	        OM_SYM_set1_intersect},
	/* This is the same as for "in" but will be combined with the "not" symbol. */
	{"set1",	"notin",		"member?",		OM_SYM_set1_notin},
	/* This is the same as for "prsubset" but will be combined with the "not" symbol. */
	{"set1",	"notprsubset",	        "<",			OM_SYM_set1_notprsubset},
	/* This is the same as for "subset" but will be combined with the "not" symbol. */
	{"set1",	"notsubset",	        "subset?",		OM_SYM_set1_notsubset},
	{"set1",	"prsubset",		"<",			OM_SYM_set1_prsubset},
	{"set1",	"set",			"set",			OM_SYM_set1_set},
	{"set1",	"setdiff",		"difference",	        OM_SYM_set1_setdiff},
	{"set1",	"subset",		"subset?",		OM_SYM_set1_subset},
	{"set1",	"union",		"union",		OM_SYM_set1_union},
	{"set1",	"size",			"cardinality",	        OM_SYM_set1_size},
	{"set1",	"cartesian_product",	"OMunhandledSymbol",	OM_SYM_set1_cartesian_product},
	{"set1",	"emptyset",		"empty",	        OM_SYM_set1_emptyset},
	{"set1",	"map",			"map",		        OM_SYM_set1_map},
	{"set1",	"suchthat",		"select",	        OM_SYM_set1_suchthat},

	{"transc1",	"arccos",		"acos",			OM_SYM_transc1_arccos},
	{"transc1",	"arcsin",		"asin",			OM_SYM_transc1_arcsin},
	{"transc1",	"arctan",		"atan",			OM_SYM_transc1_arctan},
	{"transc1",	"cos",			"cos",			OM_SYM_transc1_cos},
	{"transc1",	"cosh",			"cosh",			OM_SYM_transc1_cosh},
	{"transc1",	"cot",			"cot",			OM_SYM_transc1_cot},
	{"transc1",	"coth",			"coth",			OM_SYM_transc1_coth},
	{"transc1",	"csc",			"csc",			OM_SYM_transc1_csc},
	{"transc1",	"csch",			"csch",			OM_SYM_transc1_csch},
	{"transc1",	"exp",			"exp",			OM_SYM_transc1_exp},
	{"transc1",	"ln",			"log",			OM_SYM_transc1_ln},
	{"transc1",	"log",			"log",			OM_SYM_transc1_log},
	{"transc1",	"sec",			"sec",			OM_SYM_transc1_sec},
	{"transc1",	"sech",			"sech",			OM_SYM_transc1_sech},
/*MCDT*/
	{"transc1",	"sin",			"sin",			OM_SYM_transc1_sin},
	{"transc1",	"sinh",			"sinh",			OM_SYM_transc1_sinh},
	{"transc1",	"tan",			"tan",			OM_SYM_transc1_tan},
	{"transc1",	"tanh",			"tanh",			OM_SYM_transc1_tanh},
	{"transc1",	"arccosh",		"acosh",		OM_SYM_transc1_arccosh},
	{"transc1",	"arccot",		"acot",			OM_SYM_transc1_arccot},
	{"transc1",	"arccoth",		"acoth",		OM_SYM_transc1_arccoth},
	{"transc1",	"arccsc",		"acsc",			OM_SYM_transc1_arccsc},
	{"transc1",	"arccsch",		"acsch",		OM_SYM_transc1_arccsch},
	{"transc1",	"arcsec",		"asec",			OM_SYM_transc1_arcsec},
	{"transc1",	"arcsech",		"asech",		OM_SYM_transc1_arcsech},
	{"transc1",	"arcsinh",		"asinh",		OM_SYM_transc1_arcsinh},
	{"transc1",	"arctanh",		"atanh",		OM_SYM_transc1_arctanh},

	{NULL,		NULL,			NULL,			OM_YYERROR}
};


int findOMSymbol(char *cd, char *name)
{
	int i, j;

	/* First find the group of symbols from the correct CD. */
	i = 0;
	while (symTable[i].cd != NULL && strcmp(symTable[i].cd, cd) != 0)
		i++;
	if (symTable[i].cd == NULL)
		return -1;

	/* Now find the matching symbol from that group (if present). */
	j = i;
	while (symTable[j].cd != NULL) {
		if (strcmp(symTable[j].cd, symTable[i].cd) != 0)
			return -1;
		else if (strcmp(symTable[j].name, name) == 0)
			return j;
		else
			j++;
	}

	return -1;
}


YYSTYPE classifySymbol(Lisp_Object lsym)
{
	Lisp_Object tmpObj;
	char *cd = NULL;
	char *name = NULL;
	int len;
	int i = 0;

	/*DEBUG*/
	/*Lprint(C_nil, lsym);*/
	/*END DEBUG*/

	/* Note: there is a strange serial dependency in the following code. If
	 * the block which gets the CD of the symbol occurs before the block which
	 * gets the name of the symbol, the symbol name will be corrupted in some
	 * cases. Very odd. (VH) --- This may not be valid any more... */

	/* Get the name of the symbol. */
	/*tmpObj = om_getLispProperty(lsym, MkUndefSymM("name"));*/
	tmpObj = qcar(qcdr(lsym));
	/*DEBUG*/
	/*Lprint(C_nil, tmpObj);*/
	/*END DEBUG*/
	if (!stringp(tmpObj))
		return OM_YYERROR;
	name = get_string_data(tmpObj, "classifySymbol", &len);
	assert(name != NULL);
	name[len] = '\0';

	/* Get the CD of the symbol. */
	/*tmpObj = om_getLispProperty(lsym, MkUndefSymM("cd"));*/
	tmpObj = qcar(lsym);
	/*DEBUG*/
#if defined(YYDEBUG) && YYDEBUG == 1
	Lprint(C_nil, tmpObj);
#endif
	/*END DEBUG*/
	if (!stringp(tmpObj))
		return OM_YYERROR;
	cd = get_string_data(tmpObj, "classifySymbol", &len);
	assert(cd != NULL);
	cd[len] = '\0';

	/* Find the symbol in the symbol table, if it is present. */
	i = findOMSymbol(cd, name);

	/* If the symbol was recognised, return it. */
	if (i != -1) {
		yylval = StrToLspM(symTable[i].axname); 
		return symTable[i].token;
	}
	else return OM_YYERROR;
}


int yyerror(char *msg)
{
	fprintf(stderr, "ERROR: %s\n", msg);
	return 0;
}


YYSTYPE yylex()
{
	OMtokenType ttype;
	OMstatus status;
	OMdev dev;

	dev = om_toDev(ldev);
	status = OMgetType(dev, &ttype);

	/* The following code breaks file handling.  MCD */

	/* If we are listening to a socket (as opposed to reading from a file), we
	 * should block until more tokens become available. */
	/* XXX
	if (OMisSocketDevice(dev)) {
		while (status == OMnoMoreToken)
	*/
			status = OMgetType(dev, &ttype);
	/* XXX
	}
	*/

	if (ttype == OMtokenUnknown || status != OMsuccess)
		return 0;
	else {
		switch (ttype) {
		case OMtokenApp:
			yylval = om_getApp(C_nil, ldev);
			return OM_APP;
		case OMtokenEndApp:
			yylval = om_getEndApp(C_nil, ldev);
			return OM_ENDAPP;
		case OMtokenAtp:
			yylval = om_getAtp(C_nil, ldev);
			return OM_ATP;
		case OMtokenEndAtp:
			yylval = om_getEndAtp(C_nil, ldev);
			return OM_ENDATP;
		case OMtokenAttr:
			yylval = om_getAttr(C_nil, ldev);
			return OM_ATTR;
		case OMtokenEndAttr:
			yylval = om_getEndAttr(C_nil, ldev);
			return OM_ENDATTR;
		case OMtokenBind:
			yylval = om_getBind(C_nil, ldev);
			return OM_BIND;
		case OMtokenEndBind:
			yylval = om_getEndBind(C_nil, ldev);
			return OM_ENDBIND;
		case OMtokenBVar:
			yylval = om_getBVar(C_nil, ldev);
			return OM_BVAR;
		case OMtokenEndBVar:
			yylval = om_getEndBVar(C_nil, ldev);
			return OM_ENDBVAR;
		case OMtokenError:
			yylval = om_getError(C_nil, ldev);
			return OM_ERROR;
		case OMtokenEndError:
			yylval = om_getEndError(C_nil, ldev);
			return OM_ENDERROR;
		case OMtokenObject:
			yylval = om_getObject(C_nil, ldev);
			return OM_OBJECT;
		case OMtokenEndObject:
			yylval = om_getEndObject(C_nil, ldev);
			return OM_ENDOBJECT;
		case OMtokenInt32:
		case OMtokenBigInt:
			yylval = om_getInt(C_nil, ldev);
			return OM_INT;
		case OMtokenFloat64:
			yylval = om_getFloat(C_nil, ldev);
			return OM_FLOAT;
		case OMtokenByteArray:
			yylval = om_getByteArray(C_nil, ldev);
			return OM_BYTEARRAY;
		case OMtokenVar:
			yylval = om_getVar(C_nil, ldev);
			return OM_VAR;
		case OMtokenString:
			yylval = om_getString(C_nil, ldev);
			return OM_STRING;
		case OMtokenSymbol:
			yylval = om_getSymbol(C_nil, ldev);
			return classifySymbol(yylval);
		default:
			return OM_YYERROR;
		}
	}
}


/**
* This function is exposed to the lisp interpreter, to allow it to parse
* OpenMath objects from a given string or device. The OpenMath object will be
* returned in a form suitable for use by the "interpret" function.
*/
Lisp_Object om_read(Lisp_Object nil, Lisp_Object obj)
{
	OMdev dev;
	char *data = NULL;
	int len, val;

	CSL_IGNORE(nil);
	push(obj);

	inObj = nil;
	if (stringp(obj)) {
		data = get_string_data(obj, "om-read", &len);
		errexitn(1);
		if (data != NULL)
			data[len] = '\0';
		dev = OMmakeDevice(OMencodingXML, OMmakeIOString(&data));
		ldev = om_fromDev(dev);
	}
	else if (is_bignum(obj) && ((bignum_length(obj) >> 2) - 1) == 1)
		ldev = obj;
	else
		return aerror("om-read: argument must be a string or an OpenMath device.");
	
	/* Turn parser tracing on. */
#if defined YYDEBUG && YYDEBUG == 1
	yydebug = 1;/*DEBUG*/
#endif
	val = yyparse();
	yylval = C_nil;

	if (stringp(obj))
		OMcloseDevice(dev);
	errexitn(1);
	pop(obj);
#if defined YYDEBUG && YYDEBUG == 1
	Lprint(C_nil, inObj);/*DEBUG*/
#endif

	if (val == 0)
		return onevalue(inObj);
	else
		return aerror("om-read: invalid OpenMath object.");
}


/**
* Will return the Lisp value true or false, depending on whether the named CD
* (the lcd parameter) is supported by this phrasebook.
*/
Lisp_Object om_supportsCD(Lisp_Object nil, Lisp_Object lcd)
{
	char *cd = NULL;
	int len, i;

	CSL_IGNORE(nil);
	push(lcd);

	if (!stringp(lcd))
		return aerror("om-supportsCD: the argument must be a string");
	errexitn(1);
	cd = get_string_data(lcd, "om-supportsCD", &len);
	errexitn(1);
	if (cd == NULL)
		return aerror("om-supportsCD: invalid CD name");
	cd[len] = '\0';

	for (i = 0; symTable[i].cd != NULL; i++) {
		if (strcmp(symTable[i].cd, cd) == 0) {
			pop(lcd);
			return onevalue(StrToLspM("true"));
		}
	}
	pop(lcd);
	return onevalue(StrToLspM("false"));
}


/**
* Will return Lisp true or false, depending on whether the named symbol from
* the named CD is supported by this phrasebook.
*/
Lisp_Object om_supportsSymbol(Lisp_Object nil, Lisp_Object lcd, Lisp_Object lsym)
{
	char *cd = NULL;
	char *sym = NULL;
	int len, i;

	CSL_IGNORE(nil);
	push2(lcd, lsym);

	if (!stringp(lcd))
		return aerror("om-supportsSymbol: the content dictionary name must be a string");
	else if (!stringp(lsym))
		return aerror("om-supportsSymbol: the symbol name must be a string");
	errexitn(2);

	/* Note: there is a strange serial dependency in the following code. If
	 * the block which gets the CD of the symbol occurs before the block which
	 * gets the name of the symbol, the symbol name will be corrupted in some
	 * cases. Very odd. (VH) */

	sym = get_string_data(lsym, "om-supportsSymbol received a corrupt symbol name", &len);
	errexitn(2);
	if (sym == NULL)
		return aerror("om-supportsSymbol: invalid symbol name");
	sym[len] = '\0';

	cd = get_string_data(lcd, "om-supportsSymbol received a corrupt CD name", &len);
	errexitn(2);
	if (cd == NULL)
		return aerror("om-supportsSymbol: invalid content dictionary name");
	cd[len] = '\0';

	pop2(lcd, lsym);

	i = findOMSymbol(cd, sym);
	if (i == -1)
		return onevalue(StrToLspM("false"));
	else
		return onevalue(StrToLspM("true"));
}


/**
* Will return a list of the names of all CDs supported (partially or fully) by
* this phrasebook.
*/
Lisp_Object MS_CDECL om_listCDs(Lisp_Object nil, int nargs, ...)
{
	Lisp_Object lcds = nil;
	Lisp_Object obj;
	int i, j;

	CSL_IGNORE(nil);
	argcheck(nargs, 0, "om-listCDs: this function takes no arguments");

	/* Find the end of the symbol table. */
	for (i = 0; symTable[i].cd != NULL; i++) ;

	/* Work backwards through the symbol table, consing new CD names into the
	 * list as they are encountered. */
	j = i;
	while (i > 0) {
		i--;
		if (symTable[j].cd == NULL && symTable[i].cd != NULL)
			j = i;
		else if (strcmp(symTable[i].cd, symTable[j].cd) != 0)
			j = i;

		if (j == i) {
			lcds = cons(make_string(symTable[i].cd), lcds);
			errexit();
		}
	}

	obj = StrToLspM("construct");
	errexit();
	lcds = cons(obj, lcds);
	errexit();

	return onevalue(lcds);
}


/**
* Will return a list of all of the symbols from the named CD that are
* supported by this phrasebook.
*/
Lisp_Object om_listSymbols(Lisp_Object nil, Lisp_Object lcd)
{
	Lisp_Object lsyms = nil;
	Lisp_Object obj;
	char *cd = NULL;
	int i, j, len;
	
	CSL_IGNORE(nil);
	push(lcd);

	if (!stringp(lcd))
		return aerror("om-listSymbols: the content dictionary name must be a string");
	errexitn(1);

	cd = get_string_data(lcd, "om-listSymbols", &len);
	errexitn(1);
	if (cd == NULL)
		return aerror("om-listSymbols: invalid content dictionary name");
	cd[len] = '\0';

	for (i = 0; symTable[i].cd != NULL; i++) {
		if (strcmp(symTable[i].cd, cd) == 0)
			break;
	}
	if (symTable[i].cd == NULL) {
		pop(lcd);
		return nil;
	}
	
	for (j = i + 1; symTable[j].cd != NULL; j++) {
		if (strcmp(symTable[j].cd, cd) != 0)
			break;
	}

	for (j = j - 1; j >= i; j--) {
		lsyms = cons(make_string(symTable[j].name), lsyms);
		errexitn(1);
	}

	obj = StrToLspM("construct");
	errexitn(1);
	lsyms = cons(obj, lsyms);
	errexitn(1);

	pop(lcd);
	return onevalue(lsyms);
}


/**
* This will return a list of the supported CDs that include the symbol with the
* given name.
*/
Lisp_Object om_whichCDs(Lisp_Object nil, Lisp_Object lsym)
{
	Lisp_Object lcds = nil;
	Lisp_Object obj = nil;
	char *sym = NULL;
	int i, len;

	CSL_IGNORE(nil);
	push(lsym);

	if (!stringp(lsym))
		return aerror("om-whichCDs: symbol name must be a string");
	errexitn(1);

	sym = get_string_data(lsym, "om-whichCDs", &len);
	errexitn(1);
	if (sym == NULL)
		return aerror("om-whichCDs: invalid symbol name");
	sym[len] = '\0';

	/* Find the end of the symbol table. */
	for (i = 0; symTable[i].cd != NULL; i++) ;

	while (i > 0) {
		i--;
		if (strcmp(symTable[i].name, sym) == 0) {
			lcds = cons(make_string(symTable[i].cd), lcds);
			errexitn(1);
		}
	}

	obj = StrToLspM("construct");
	errexitn(1);
	lcds = cons(obj, lcds);
	errexitn(1);

	pop(lsym);
	return onevalue(lcds);
}

