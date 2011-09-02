
/*  A Bison parser, made from omparser.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	OM_YYERROR	257
#define	OM_INT	258
#define	OM_FLOAT	259
#define	OM_BYTEARRAY	260
#define	OM_VAR	261
#define	OM_STRING	262
#define	OM_SYMBOL	263
#define	OM_APP	264
#define	OM_ENDAPP	265
#define	OM_ATP	266
#define	OM_ENDATP	267
#define	OM_ATTR	268
#define	OM_ENDATTR	269
#define	OM_BIND	270
#define	OM_ENDBIND	271
#define	OM_BVAR	272
#define	OM_ENDBVAR	273
#define	OM_ERROR	274
#define	OM_ENDERROR	275
#define	OM_OBJECT	276
#define	OM_ENDOBJECT	277
#define	OM_SYM_alg1_zero	278
#define	OM_SYM_alg1_one	279
#define	OM_SYM_arith1_abs	280
#define	OM_SYM_arith1_divide	281
#define	OM_SYM_arith1_gcd	282
#define	OM_SYM_arith1_lcm	283
#define	OM_SYM_arith1_minus	284
#define	OM_SYM_arith1_plus	285
#define	OM_SYM_arith1_power	286
#define	OM_SYM_arith1_product	287
#define	OM_SYM_arith1_root	288
#define	OM_SYM_arith1_sum	289
#define	OM_SYM_arith1_times	290
#define	OM_SYM_arith1_unary_minus	291
#define	OM_SYM_arith2_arg	292
#define	OM_SYM_arith2_inverse	293
#define	OM_SYM_arith2_times	294
#define	OM_SYM_bigfloat1_bigfloat	295
#define	OM_SYM_calculus1_defint	296
#define	OM_SYM_calculus1_diff	297
#define	OM_SYM_calculus1_int	298
#define	OM_SYM_calculus1_partialdiff	299
#define	OM_SYM_complex1_argument	300
#define	OM_SYM_complex1_complex_cartesian	301
#define	OM_SYM_complex1_complex_polar	302
#define	OM_SYM_complex1_conjugate	303
#define	OM_SYM_complex1_imaginary	304
#define	OM_SYM_complex1_real	305
#define	OM_SYM_fns1_domain	306
#define	OM_SYM_fns1_range	307
#define	OM_SYM_fns1_image	308
#define	OM_SYM_fns1_identity	309
#define	OM_SYM_fns1_inverse	310
#define	OM_SYM_fns1_lambda	311
#define	OM_SYM_fns1_left_compose	312
#define	OM_SYM_fns2_apply_to_list	313
#define	OM_SYM_fns2_kernel	314
#define	OM_SYM_fns2_right_compose	315
#define	OM_SYM_integer1_factorial	316
#define	OM_SYM_integer1_factorof	317
#define	OM_SYM_integer1_quotient	318
#define	OM_SYM_integer1_remainder	319
#define	OM_SYM_interval1_integer_interval	320
#define	OM_SYM_interval1_interval	321
#define	OM_SYM_interval1_interval_cc	322
#define	OM_SYM_interval1_interval_co	323
#define	OM_SYM_interval1_interval_oc	324
#define	OM_SYM_interval1_interval_oo	325
#define	OM_SYM_limit1_above	326
#define	OM_SYM_limit1_below	327
#define	OM_SYM_limit1_both_sides	328
#define	OM_SYM_limit1_limit	329
#define	OM_SYM_limit1_null	330
#define	OM_SYM_linalg1_determinant	331
#define	OM_SYM_linalg1_matrix_selector	332
#define	OM_SYM_linalg1_vector_selector	333
#define	OM_SYM_linalg1_transpose	334
#define	OM_SYM_linalg1_outerproduct	335
#define	OM_SYM_linalg1_scalarproduct	336
#define	OM_SYM_linalg1_vectorproduct	337
#define	OM_SYM_linalg2_matrix	338
#define	OM_SYM_linalg2_matrixrow	339
#define	OM_SYM_linalg2_vector	340
#define	OM_SYM_linalg3_matrix	341
#define	OM_SYM_linalg3_matrixcolumn	342
#define	OM_SYM_linalg3_vector	343
#define	OM_SYM_list1_list	344
#define	OM_SYM_list1_map	345
#define	OM_SYM_list1_suchthat	346
#define	OM_SYM_list2_cons	347
#define	OM_SYM_list2_first	348
#define	OM_SYM_list2_rest	349
#define	OM_SYM_logic1_and	350
#define	OM_SYM_logic1_false	351
#define	OM_SYM_logic1_implies	352
#define	OM_SYM_logic1_not	353
#define	OM_SYM_logic1_or	354
#define	OM_SYM_logic1_true	355
#define	OM_SYM_logic1_xor	356
#define	OM_SYM_logic1_equivalent	357
#define	OM_SYM_minmax1_max	358
#define	OM_SYM_minmax1_min	359
#define	OM_SYM_nums1_based_integer	360
#define	OM_SYM_nums1_e	361
#define	OM_SYM_nums1_gamma	362
#define	OM_SYM_nums1_i	363
#define	OM_SYM_nums1_infinity	364
#define	OM_SYM_nums1_NaN	365
#define	OM_SYM_nums1_pi	366
#define	OM_SYM_nums1_rational	367
#define	OM_SYM_relation1_eq	368
#define	OM_SYM_relation1_geq	369
#define	OM_SYM_relation1_gt	370
#define	OM_SYM_relation1_leq	371
#define	OM_SYM_relation1_lt	372
#define	OM_SYM_relation1_neq	373
#define	OM_SYM_relation1_approx	374
#define	OM_SYM_rounding1_ceiling	375
#define	OM_SYM_rounding1_floor	376
#define	OM_SYM_rounding1_trunc	377
#define	OM_SYM_rounding1_round	378
#define	OM_SYM_setname1_C	379
#define	OM_SYM_setname1_N	380
#define	OM_SYM_setname1_P	381
#define	OM_SYM_setname1_Q	382
#define	OM_SYM_setname1_R	383
#define	OM_SYM_setname1_Z	384
#define	OM_SYM_set1_cartesian_product	385
#define	OM_SYM_set1_emptyset	386
#define	OM_SYM_set1_in	387
#define	OM_SYM_set1_intersect	388
#define	OM_SYM_set1_map	389
#define	OM_SYM_set1_notin	390
#define	OM_SYM_set1_notprsubset	391
#define	OM_SYM_set1_notsubset	392
#define	OM_SYM_set1_prsubset	393
#define	OM_SYM_set1_set	394
#define	OM_SYM_set1_setdiff	395
#define	OM_SYM_set1_size	396
#define	OM_SYM_set1_subset	397
#define	OM_SYM_set1_suchthat	398
#define	OM_SYM_set1_union	399
#define	OM_SYM_transc1_arccos	400
#define	OM_SYM_transc1_arcsin	401
#define	OM_SYM_transc1_arctan	402
#define	OM_SYM_transc1_cos	403
#define	OM_SYM_transc1_cosh	404
#define	OM_SYM_transc1_cot	405
#define	OM_SYM_transc1_coth	406
#define	OM_SYM_transc1_csc	407
#define	OM_SYM_transc1_csch	408
#define	OM_SYM_transc1_exp	409
#define	OM_SYM_transc1_ln	410
#define	OM_SYM_transc1_log	411
#define	OM_SYM_transc1_sec	412
#define	OM_SYM_transc1_sech	413
#define	OM_SYM_transc1_sin	414
#define	OM_SYM_transc1_sinh	415
#define	OM_SYM_transc1_tan	416
#define	OM_SYM_transc1_tanh	417
#define	OM_SYM_transc1_arccosh	418
#define	OM_SYM_transc1_arccot	419
#define	OM_SYM_transc1_arccoth	420
#define	OM_SYM_transc1_arccsc	421
#define	OM_SYM_transc1_arccsch	422
#define	OM_SYM_transc1_arcsec	423
#define	OM_SYM_transc1_arcsech	424
#define	OM_SYM_transc1_arcsinh	425
#define	OM_SYM_transc1_arctanh	426

#line 1 "omparser.y"

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
#include "read.h"

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
extern char *get_string_data(Lisp_Object name, char *why, int32 *l);

/* Some global variables (yuk!). */
static Lisp_Object ldev;
static Lisp_Object inObj;

/* End of preamble. */
#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		649
#define	YYFLAG		-32768
#define	YYNTBASE	173

#define YYTRANSLATE(x) ((unsigned)(x) <= 426 ? yytranslate[x] : 251)

static const short yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
    77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
    87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
    97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
   107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
   117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
   127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
   137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
   147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
   157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
   167,   168,   169,   170,   171,   172
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     4,     5,     9,    10,    13,    15,    17,    19,    21,
    23,    25,    27,    29,    31,    38,    40,    47,    49,    56,
    58,    65,    67,    74,    76,    83,    85,    87,    89,    91,
    93,    95,    97,    99,   101,   103,   105,   107,   109,   111,
   113,   115,   117,   119,   121,   123,   125,   127,   129,   131,
   133,   135,   137,   139,   141,   143,   145,   147,   149,   151,
   153,   155,   157,   159,   161,   163,   165,   167,   169,   171,
   173,   175,   177,   179,   181,   183,   185,   187,   189,   191,
   193,   195,   197,   199,   201,   203,   205,   207,   209,   211,
   213,   215,   217,   219,   221,   223,   225,   227,   229,   231,
   233,   235,   237,   239,   241,   243,   245,   247,   249,   251,
   253,   255,   257,   259,   261,   263,   265,   267,   269,   271,
   273,   275,   277,   279,   281,   283,   285,   287,   289,   291,
   293,   295,   297,   299,   301,   303,   305,   307,   309,   311,
   313,   315,   317,   319,   321,   323,   325,   327,   329,   331,
   333,   335,   337,   339,   341,   343,   345,   347,   349,   351,
   353,   355,   357,   359,   361,   363,   365,   367,   369,   371,
   373,   375,   377,   379,   381,   383,   385,   387,   389,   391,
   393,   395,   397,   399,   401,   403,   405,   407,   409,   411,
   413,   415,   417,   419,   421,   423,   425,   427,   429,   431,
   432,   435,   437,   439,   441,   449,   453,   462,   464,   466,
   468,   470,   472,   474,   476,   478,   480,   482,   484,   486,
   488,   490,   492,   494,   496,   498,   500,   502,   504,   506,
   508,   510,   512,   514,   517,   521,   524,   527,   531,   533,
   536,   540,   544,   548,   552,   554,   557,   560,   562,   565,
   567,   570,   573,   576,   578,   581,   586,   590,   593,   596,
   600,   606,   612,   614,   616,   618,   620,   622,   630,   633,
   637,   641,   644,   647,   650,   653,   656,   659,   662,   665,
   669,   673,   676,   680,   683,   687,   691,   695,   699,   703,
   707,   711,   715,   719,   724,   729,   734,   739,   742,   745,
   748,   749,   755,   758,   761,   764,   765,   771,   774,   779,
   783,   786,   790,   794,   798,   801,   805,   809,   811,   813,
   815,   817,   824,   832,   836,   839,   842,   844,   847,   849,
   853,   856,   858,   861,   863,   865,   868,   872,   874,   877,
   879,   882,   884,   887,   889,   892,   894,   897,   899,   902,
   904,   907,   911,   915,   919,   923,   927,   931,   935,   939,
   943,   946,   949,   952,   955,   959,   963,   967,   971,   975,
   979,   982,   986,   990,   994,   997,  1000,  1002,  1006,  1010,
  1013,  1016,  1019,  1022,  1025,  1028,  1031,  1034,  1037,  1040,
  1043,  1047,  1050,  1053,  1056,  1059,  1062,  1065,  1068,  1071,
  1074,  1077,  1080,  1083,  1086,  1089,  1092,  1095,  1099,  1108,
  1110
};

static const short yyrhs[] = {    22,
   176,    23,     0,     0,   183,   176,   174,     0,     0,   180,
   175,     0,   177,     0,   178,     0,   179,     0,   180,     0,
   181,     0,   182,     0,   210,     0,   248,     0,     4,     0,
    14,    12,   174,    13,     4,    15,     0,     5,     0,    14,
    12,   174,    13,     5,    15,     0,     6,     0,    14,    12,
   174,    13,     6,    15,     0,     7,     0,    14,    12,   174,
    13,     7,    15,     0,     8,     0,    14,    12,   174,    13,
     8,    15,     0,   183,     0,    14,    12,   174,    13,   183,
    15,     0,     9,     0,   184,     0,   185,     0,   186,     0,
   187,     0,   188,     0,   189,     0,   190,     0,   191,     0,
   192,     0,   193,     0,   194,     0,   197,     0,   195,     0,
   196,     0,   198,     0,   199,     0,   200,     0,   201,     0,
   202,     0,   203,     0,   204,     0,   205,     0,   206,     0,
   207,     0,    24,     0,    25,     0,    26,     0,    27,     0,
    28,     0,    29,     0,    30,     0,    31,     0,    32,     0,
    33,     0,    34,     0,    35,     0,    36,     0,    37,     0,
    38,     0,    39,     0,    40,     0,    41,     0,    42,     0,
    43,     0,    44,     0,    45,     0,    46,     0,    47,     0,
    48,     0,    49,     0,    50,     0,    51,     0,    55,     0,
    56,     0,    57,     0,    58,     0,    52,     0,    53,     0,
    54,     0,    59,     0,    60,     0,    61,     0,    62,     0,
    63,     0,    64,     0,    65,     0,    66,     0,    67,     0,
    68,     0,    69,     0,    70,     0,    71,     0,    72,     0,
    73,     0,    74,     0,    75,     0,    76,     0,    84,     0,
    85,     0,    86,     0,    87,     0,    88,     0,    89,     0,
    77,     0,    78,     0,    79,     0,    80,     0,    81,     0,
    82,     0,    83,     0,    90,     0,    91,     0,    92,     0,
    93,     0,    94,     0,    95,     0,    96,     0,    97,     0,
    98,     0,    99,     0,   100,     0,   101,     0,   102,     0,
   103,     0,   104,     0,   105,     0,   106,     0,   107,     0,
   108,     0,   109,     0,   110,     0,   111,     0,   112,     0,
   113,     0,   114,     0,   115,     0,   116,     0,   117,     0,
   118,     0,   119,     0,   120,     0,   121,     0,   122,     0,
   123,     0,   124,     0,   125,     0,   126,     0,   127,     0,
   128,     0,   129,     0,   130,     0,   131,     0,   132,     0,
   135,     0,   142,     0,   144,     0,   133,     0,   134,     0,
   136,     0,   137,     0,   138,     0,   139,     0,   140,     0,
   141,     0,   143,     0,   145,     0,   146,     0,   147,     0,
   148,     0,   149,     0,   150,     0,   151,     0,   152,     0,
   153,     0,   154,     0,   155,     0,   156,     0,   157,     0,
   158,     0,   159,     0,   160,     0,   161,     0,   162,     0,
   163,     0,   164,     0,   165,     0,   166,     0,   167,     0,
   168,     0,   169,     0,   170,     0,   171,     0,   172,     0,
     0,   176,   208,     0,   180,     0,   182,     0,   210,     0,
    16,    57,    18,   180,    19,   176,    17,     0,    10,   211,
    11,     0,    14,    12,   174,    13,    10,   211,    11,    15,
     0,   212,     0,   213,     0,   216,     0,   217,     0,   218,
     0,   222,     0,   223,     0,   224,     0,   225,     0,   226,
     0,   227,     0,   232,     0,   228,     0,   230,     0,   233,
     0,   234,     0,   235,     0,   239,     0,   242,     0,   243,
     0,   244,     0,   245,     0,   246,     0,   247,     0,    24,
     0,    25,     0,    26,   176,     0,    27,   176,   176,     0,
    28,   208,     0,    29,   208,     0,    30,   176,   176,     0,
    31,     0,    31,   214,     0,    32,   176,   176,     0,    33,
   176,   176,     0,    34,   176,   176,     0,    35,   176,   176,
     0,    36,     0,    36,   215,     0,    37,   176,     0,   176,
     0,   176,   214,     0,   176,     0,   176,   215,     0,    38,
   176,     0,    39,   176,     0,    40,     0,    40,   215,     0,
    41,   176,   176,   176,     0,    42,   219,   209,     0,    43,
   209,     0,    44,   209,     0,    45,   176,   221,     0,    10,
    66,   176,   176,    11,     0,    10,   220,   176,   176,    11,
     0,    67,     0,    67,     0,    67,     0,    67,     0,    67,
     0,    16,    57,    18,   175,    19,   176,    17,     0,    46,
   176,     0,    47,   176,   176,     0,    48,   176,   176,     0,
    49,   176,     0,    50,   176,     0,    51,   176,     0,    55,
   176,     0,    56,   176,     0,    54,   176,     0,    53,   176,
     0,    52,   176,     0,    58,   209,   209,     0,    59,   209,
   176,     0,    60,   209,     0,    61,   209,   209,     0,    62,
   176,     0,    63,   176,   176,     0,    64,   176,   176,     0,
    65,   176,   176,     0,    66,   176,   176,     0,    67,   176,
   176,     0,    68,   176,   176,     0,    69,   176,   176,     0,
    70,   176,   176,     0,    71,   176,   176,     0,    75,   176,
    72,   209,     0,    75,   176,    73,   209,     0,    75,   176,
    74,   209,     0,    75,   176,    76,   209,     0,    84,   229,
     0,    85,   208,     0,    86,   208,     0,     0,    10,    85,
   208,    11,   229,     0,    87,   231,     0,    88,   208,     0,
    89,   208,     0,     0,    10,    88,   208,    11,   231,     0,
    77,   176,     0,    78,   176,   176,   176,     0,    79,   176,
   176,     0,    80,   176,     0,    81,   176,   176,     0,    82,
   176,   176,     0,    83,   176,   176,     0,    90,   208,     0,
    91,   176,   176,     0,    92,   176,   176,     0,   180,     0,
   182,     0,   210,     0,     0,     0,    14,    12,   174,    13,
     0,    15,     0,    16,    57,    18,   180,    19,   176,    17,
     0,    93,   176,   176,     0,    94,   176,     0,    95,   176,
     0,    96,     0,    96,   236,     0,    97,     0,    98,   176,
   176,     0,    99,   176,     0,   100,     0,   100,   237,     0,
   101,     0,   102,     0,   102,   238,     0,   103,   176,   176,
     0,   176,     0,   176,   236,     0,   176,     0,   176,   237,
     0,   176,     0,   176,   238,     0,   104,     0,   104,   240,
     0,   105,     0,   105,   241,     0,   176,     0,   176,   240,
     0,   176,     0,   176,   241,     0,   106,   176,   176,     0,
   113,   176,   176,     0,   114,   176,   176,     0,   115,   176,
   176,     0,   116,   176,   176,     0,   117,   176,   176,     0,
   118,   176,   176,     0,   119,   176,   176,     0,   120,   176,
   176,     0,   121,   176,     0,   122,   176,     0,   123,   176,
     0,   124,   176,     0,   133,   176,   176,     0,   134,   176,
   176,     0,   136,   176,   176,     0,   137,   176,   176,     0,
   138,   176,   176,     0,   139,   176,   176,     0,   140,   208,
     0,   141,   176,   176,     0,   143,   176,   176,     0,   145,
   176,   176,     0,   142,   176,     0,   131,   208,     0,   132,
     0,   135,   176,   176,     0,   144,   176,   176,     0,   146,
   176,     0,   147,   176,     0,   148,   176,     0,   149,   176,
     0,   150,   176,     0,   151,   176,     0,   152,   176,     0,
   153,   176,     0,   154,   176,     0,   155,   176,     0,   156,
   176,     0,   157,   176,   176,     0,   158,   176,     0,   159,
   176,     0,   160,   176,     0,   161,   176,     0,   162,   176,
     0,   163,   176,     0,   164,   176,     0,   165,   176,     0,
   166,   176,     0,   167,   176,     0,   168,   176,     0,   169,
   176,     0,   170,   176,     0,   171,   176,     0,   172,   176,
     0,   248,   208,     0,    16,   249,    17,     0,    14,    12,
   174,    13,    16,   249,    17,    15,     0,   250,     0,    57,
    18,   175,    19,   176,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   296,   301,   303,   307,   310,   314,   316,   317,   318,   319,
   320,   321,   322,   326,   329,   333,   336,   340,   343,   347,
   350,   354,   357,   361,   364,   368,   370,   371,   372,   373,
   374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
   384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
   396,   398,   401,   403,   404,   405,   406,   407,   408,   409,
   410,   411,   412,   413,   416,   418,   419,   422,   426,   428,
   429,   430,   433,   435,   436,   437,   438,   439,   442,   444,
   445,   446,   447,   448,   449,   452,   454,   455,   458,   460,
   461,   462,   465,   467,   468,   469,   470,   471,   474,   476,
   477,   478,   479,   482,   484,   485,   488,   490,   491,   494,
   496,   497,   498,   499,   500,   501,   504,   506,   507,   510,
   512,   513,   516,   518,   519,   520,   521,   522,   523,   524,
   527,   529,   532,   534,   535,   536,   537,   538,   539,   540,
   543,   545,   546,   547,   548,   549,   550,   553,   555,   556,
   557,   560,   562,   563,   564,   565,   566,   569,   571,   572,
   573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
   583,   584,   587,   589,   590,   591,   592,   593,   594,   595,
   596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
   606,   607,   608,   609,   610,   611,   612,   613,   614,   618,
   621,   626,   635,   643,   651,   659,   662,   666,   668,   669,
   670,   671,   672,   673,   674,   675,   676,   677,   678,   679,
   680,   681,   682,   683,   684,   685,   686,   687,   688,   689,
   690,   693,   696,   700,   706,   711,   716,   721,   726,   728,
   730,   735,   740,   745,   750,   752,   754,   761,   764,   772,
   775,   783,   789,   794,   796,   802,   810,   826,   828,   834,
   882,   889,   903,   905,   906,   907,   908,   913,   921,   927,
   932,   938,   943,   948,   957,   960,   962,   967,   972,   977,
  1006,  1012,  1014,  1043,  1049,  1054,  1059,  1066,  1072,  1082,
  1092,  1113,  1134,  1158,  1180,  1201,  1222,  1245,  1252,  1254,
  1258,  1261,  1265,  1273,  1275,  1279,  1282,  1286,  1292,  1294,
  1299,  1304,  1309,  1314,  1321,  1324,  1329,  1340,  1349,  1357,
  1365,  1367,  1371,  1380,  1386,  1391,  1398,  1401,  1403,  1405,
  1410,  1415,  1417,  1419,  1421,  1423,  1425,  1429,  1432,  1440,
  1443,  1451,  1454,  1462,  1465,  1467,  1469,  1473,  1476,  1484,
  1487,  1497,  1500,  1515,  1526,  1531,  1536,  1541,  1546,  1551,
  1558,  1564,  1569,  1574,  1581,  1587,  1592,  1598,  1604,  1610,
  1615,  1619,  1624,  1629,  1634,  1639,  1644,  1649,  1654,  1662,
  1668,  1673,  1678,  1683,  1688,  1693,  1698,  1703,  1708,  1713,
  1718,  1724,  1729,  1734,  1739,  1744,  1749,  1754,  1759,  1764,
  1769,  1774,  1779,  1784,  1789,  1794,  1801,  1806,  1809,  1813,
  1817
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","OM_YYERROR",
"OM_INT","OM_FLOAT","OM_BYTEARRAY","OM_VAR","OM_STRING","OM_SYMBOL","OM_APP",
"OM_ENDAPP","OM_ATP","OM_ENDATP","OM_ATTR","OM_ENDATTR","OM_BIND","OM_ENDBIND",
"OM_BVAR","OM_ENDBVAR","OM_ERROR","OM_ENDERROR","OM_OBJECT","OM_ENDOBJECT","OM_SYM_alg1_zero",
"OM_SYM_alg1_one","OM_SYM_arith1_abs","OM_SYM_arith1_divide","OM_SYM_arith1_gcd",
"OM_SYM_arith1_lcm","OM_SYM_arith1_minus","OM_SYM_arith1_plus","OM_SYM_arith1_power",
"OM_SYM_arith1_product","OM_SYM_arith1_root","OM_SYM_arith1_sum","OM_SYM_arith1_times",
"OM_SYM_arith1_unary_minus","OM_SYM_arith2_arg","OM_SYM_arith2_inverse","OM_SYM_arith2_times",
"OM_SYM_bigfloat1_bigfloat","OM_SYM_calculus1_defint","OM_SYM_calculus1_diff",
"OM_SYM_calculus1_int","OM_SYM_calculus1_partialdiff","OM_SYM_complex1_argument",
"OM_SYM_complex1_complex_cartesian","OM_SYM_complex1_complex_polar","OM_SYM_complex1_conjugate",
"OM_SYM_complex1_imaginary","OM_SYM_complex1_real","OM_SYM_fns1_domain","OM_SYM_fns1_range",
"OM_SYM_fns1_image","OM_SYM_fns1_identity","OM_SYM_fns1_inverse","OM_SYM_fns1_lambda",
"OM_SYM_fns1_left_compose","OM_SYM_fns2_apply_to_list","OM_SYM_fns2_kernel",
"OM_SYM_fns2_right_compose","OM_SYM_integer1_factorial","OM_SYM_integer1_factorof",
"OM_SYM_integer1_quotient","OM_SYM_integer1_remainder","OM_SYM_interval1_integer_interval",
"OM_SYM_interval1_interval","OM_SYM_interval1_interval_cc","OM_SYM_interval1_interval_co",
"OM_SYM_interval1_interval_oc","OM_SYM_interval1_interval_oo","OM_SYM_limit1_above",
"OM_SYM_limit1_below","OM_SYM_limit1_both_sides","OM_SYM_limit1_limit","OM_SYM_limit1_null",
"OM_SYM_linalg1_determinant","OM_SYM_linalg1_matrix_selector","OM_SYM_linalg1_vector_selector",
"OM_SYM_linalg1_transpose","OM_SYM_linalg1_outerproduct","OM_SYM_linalg1_scalarproduct",
"OM_SYM_linalg1_vectorproduct","OM_SYM_linalg2_matrix","OM_SYM_linalg2_matrixrow",
"OM_SYM_linalg2_vector","OM_SYM_linalg3_matrix","OM_SYM_linalg3_matrixcolumn",
"OM_SYM_linalg3_vector","OM_SYM_list1_list","OM_SYM_list1_map","OM_SYM_list1_suchthat",
"OM_SYM_list2_cons","OM_SYM_list2_first","OM_SYM_list2_rest","OM_SYM_logic1_and",
"OM_SYM_logic1_false","OM_SYM_logic1_implies","OM_SYM_logic1_not","OM_SYM_logic1_or",
"OM_SYM_logic1_true","OM_SYM_logic1_xor","OM_SYM_logic1_equivalent","OM_SYM_minmax1_max",
"OM_SYM_minmax1_min","OM_SYM_nums1_based_integer","OM_SYM_nums1_e","OM_SYM_nums1_gamma",
"OM_SYM_nums1_i","OM_SYM_nums1_infinity","OM_SYM_nums1_NaN","OM_SYM_nums1_pi",
"OM_SYM_nums1_rational","OM_SYM_relation1_eq","OM_SYM_relation1_geq","OM_SYM_relation1_gt",
"OM_SYM_relation1_leq","OM_SYM_relation1_lt","OM_SYM_relation1_neq","OM_SYM_relation1_approx",
"OM_SYM_rounding1_ceiling","OM_SYM_rounding1_floor","OM_SYM_rounding1_trunc",
"OM_SYM_rounding1_round","OM_SYM_setname1_C","OM_SYM_setname1_N","OM_SYM_setname1_P",
"OM_SYM_setname1_Q","OM_SYM_setname1_R","OM_SYM_setname1_Z","OM_SYM_set1_cartesian_product",
"OM_SYM_set1_emptyset","OM_SYM_set1_in","OM_SYM_set1_intersect","OM_SYM_set1_map",
"OM_SYM_set1_notin","OM_SYM_set1_notprsubset","OM_SYM_set1_notsubset","OM_SYM_set1_prsubset",
"OM_SYM_set1_set","OM_SYM_set1_setdiff","OM_SYM_set1_size","OM_SYM_set1_subset",
"OM_SYM_set1_suchthat","OM_SYM_set1_union","OM_SYM_transc1_arccos","OM_SYM_transc1_arcsin",
"OM_SYM_transc1_arctan","OM_SYM_transc1_cos","OM_SYM_transc1_cosh","OM_SYM_transc1_cot",
"OM_SYM_transc1_coth","OM_SYM_transc1_csc","OM_SYM_transc1_csch","OM_SYM_transc1_exp",
"OM_SYM_transc1_ln","OM_SYM_transc1_log","OM_SYM_transc1_sec","OM_SYM_transc1_sech",
"OM_SYM_transc1_sin","OM_SYM_transc1_sinh","OM_SYM_transc1_tan","OM_SYM_transc1_tanh",
"OM_SYM_transc1_arccosh","OM_SYM_transc1_arccot","OM_SYM_transc1_arccoth","OM_SYM_transc1_arccsc",
"OM_SYM_transc1_arccsch","OM_SYM_transc1_arcsec","OM_SYM_transc1_arcsech","OM_SYM_transc1_arcsinh",
"OM_SYM_transc1_arctanh","om_whole_object","om_attributes","om_variables","om_object",
"om_integer","om_float","om_bytearray","om_variable","om_string","om_symbol",
"om_symbol_inner","om_alg1_symbol","om_arith1_symbol","om_arith2_symbol","om_bigfloat1_symbol",
"om_calculus1_symbol","om_complex1_symbol","om_fns1_symbol","om_fns2_symbol",
"om_integer1_symbol","om_interval1_symbol","om_limit1_symbol","om_linalg2_symbol",
"om_linalg3_symbol","om_linalg1_symbol","om_list1_symbol","om_list2_symbol",
"om_logic1_symbol","om_minmax1_symbol","om_nums1_symbol","om_relation1_symbol",
"om_rounding1_symbol","om_setname1_symbol","om_set1_symbol","om_transc1_symbol",
"om_nary_args","om_unary_func","om_apply","om_apply_inner","om_apply_alg1_inner",
"om_apply_arith1_inner","om_arith1_plus_args","om_arith1_times_args","om_apply_arith2_inner",
"om_apply_bigfloat1_inner","om_apply_calculus1_inner","om_calculus1_interval",
"om_calculus1_interval_symbol","om_calculus1_partialdiff_funcarg","om_apply_complex1_inner",
"om_apply_fns1_inner","om_apply_fns2_inner","om_apply_integer1_inner","om_apply_interval1_inner",
"om_apply_limit1_inner","om_apply_linalg2_inner","om_linalg2_matrix_args","om_apply_linalg3_inner",
"om_linalg3_matrix_args","om_apply_linalg1_inner","om_apply_list1_inner","om_apply_list2_inner",
"om_apply_logic1_inner","om_logic1_and_args","om_logic1_or_args","om_logic1_xor_args",
"om_apply_minmax1_inner","om_minmax1_max_args","om_minmax1_min_args","om_apply_nums1_inner",
"om_apply_relation1_inner","om_apply_rounding1_inner","om_apply_set1_inner",
"om_apply_transc1_inner","om_apply_boundexpr_inner","om_bind","om_bind_inner",
"om_bind_fns1_inner", NULL
};
#endif

static const short yyr1[] = {     0,
   173,   174,   174,   175,   175,   176,   176,   176,   176,   176,
   176,   176,   176,   177,   177,   178,   178,   179,   179,   180,
   180,   181,   181,   182,   182,   183,   183,   183,   183,   183,
   183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
   183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
   184,   184,   185,   185,   185,   185,   185,   185,   185,   185,
   185,   185,   185,   185,   186,   186,   186,   187,   188,   188,
   188,   188,   189,   189,   189,   189,   189,   189,   190,   190,
   190,   190,   190,   190,   190,   191,   191,   191,   192,   192,
   192,   192,   193,   193,   193,   193,   193,   193,   194,   194,
   194,   194,   194,   195,   195,   195,   196,   196,   196,   197,
   197,   197,   197,   197,   197,   197,   198,   198,   198,   199,
   199,   199,   200,   200,   200,   200,   200,   200,   200,   200,
   201,   201,   202,   202,   202,   202,   202,   202,   202,   202,
   203,   203,   203,   203,   203,   203,   203,   204,   204,   204,
   204,   205,   205,   205,   205,   205,   205,   206,   206,   206,
   206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
   206,   206,   207,   207,   207,   207,   207,   207,   207,   207,
   207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
   207,   207,   207,   207,   207,   207,   207,   207,   207,   208,
   208,   209,   209,   209,   209,   210,   210,   211,   211,   211,
   211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
   211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
   211,   212,   212,   213,   213,   213,   213,   213,   213,   213,
   213,   213,   213,   213,   213,   213,   213,   214,   214,   215,
   215,   216,   216,   216,   216,   217,   218,   218,   218,   218,
   219,   219,   220,   220,   220,   220,   220,   221,   222,   222,
   222,   222,   222,   222,   223,   223,   223,   223,   223,   223,
   224,   224,   224,   225,   225,   225,   225,   226,   226,   226,
   226,   226,   226,   227,   227,   227,   227,   228,   228,   228,
   229,   229,   230,   230,   230,   231,   231,   232,   232,   232,
   232,   232,   232,   232,   233,   233,   233,    -1,    -1,    -1,
    -1,    -1,    -1,   234,   234,   234,   235,   235,   235,   235,
   235,   235,   235,   235,   235,   235,   235,   236,   236,   237,
   237,   238,   238,   239,   239,   239,   239,   240,   240,   241,
   241,   242,   242,   243,   243,   243,   243,   243,   243,   243,
   244,   244,   244,   244,   245,   245,   245,   245,   245,   245,
   245,   245,   245,   245,   245,   245,   245,   245,   245,   246,
   246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
   246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
   246,   246,   246,   246,   246,   246,   247,   248,   248,   249,
   250
};

static const short yyr2[] = {     0,
     3,     0,     3,     0,     2,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     6,     1,     6,     1,     6,     1,
     6,     1,     6,     1,     6,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
     2,     1,     1,     1,     7,     3,     8,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     2,     3,     2,     2,     3,     1,     2,
     3,     3,     3,     3,     1,     2,     2,     1,     2,     1,
     2,     2,     2,     1,     2,     4,     3,     2,     2,     3,
     5,     5,     1,     1,     1,     1,     1,     7,     2,     3,
     3,     2,     2,     2,     2,     2,     2,     2,     2,     3,
     3,     2,     3,     2,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     4,     4,     4,     4,     2,     2,     2,
     0,     5,     2,     2,     2,     0,     5,     2,     4,     3,
     2,     3,     3,     3,     2,     3,     3,     1,     1,     1,
     1,     6,     7,     3,     2,     2,     1,     2,     1,     3,
     2,     1,     2,     1,     1,     2,     3,     1,     2,     1,
     2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
     2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
     2,     3,     3,     3,     2,     2,     1,     3,     3,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     3,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     3,     8,     1,
     5
};

static const short yydefact[] = {     0,
     0,    14,    16,    18,    20,    22,    26,     0,     0,     0,
    51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,    75,    76,    77,    78,    83,    84,
    85,    79,    80,    81,    82,    86,    87,    88,    89,    90,
    91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
   101,   102,   103,   110,   111,   112,   113,   114,   115,   116,
   104,   105,   106,   107,   108,   109,   117,   118,   119,   120,
   121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
   131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
   141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
   151,   152,   153,   154,   155,   156,   157,   158,   159,   163,
   164,   160,   165,   166,   167,   168,   169,   170,   161,   171,
   162,   172,   173,   174,   175,   176,   177,   178,   179,   180,
   181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
   191,   192,   193,   194,   195,   196,   197,   198,   199,     0,
     6,     7,     8,     9,    10,    11,    24,    27,    28,    29,
    30,    31,    32,    33,    34,    35,    36,    37,    39,    40,
    38,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    12,    13,     0,   232,   233,     0,     0,   200,   200,
     0,   239,     0,     0,     0,     0,   245,     0,     0,     0,
   254,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   301,
   200,   200,   306,   200,   200,   200,     0,     0,     0,     0,
     0,   327,   329,     0,     0,   332,   334,   335,     0,   344,
   346,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,   200,   377,     0,     0,     0,     0,
     0,     0,     0,   200,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   208,   209,   210,
   211,   212,   213,   214,   215,   216,   217,   218,   220,   221,
   219,   222,   223,   224,   225,   226,   227,   228,   229,   230,
   231,   200,     2,     0,     0,   410,     1,     2,   234,     0,
   200,   236,   237,     0,   248,   240,     0,     0,     0,     0,
   250,   246,   247,   252,   253,   255,     0,     0,     0,     0,
     0,   202,   203,   258,   204,   259,     0,   269,     0,     0,
   272,   273,   274,   279,   278,   277,   275,   276,     0,     0,
   282,     0,   284,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   308,     0,     0,   311,     0,     0,     0,
     0,   298,   299,   300,     0,   303,   304,   305,   315,     0,
     0,     0,   325,   326,   338,   328,     0,   331,   340,   333,
   342,   336,     0,   348,   345,   350,   347,     0,     0,     0,
     0,     0,     0,     0,     0,     0,   361,   362,   363,   364,
   376,     0,     0,     0,     0,     0,     0,     0,   371,     0,
   375,     0,     0,     0,   380,   381,   382,   383,   384,   385,
   386,   387,   388,   389,   390,     0,   392,   393,   394,   395,
   396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
   406,   206,   407,     0,     0,     4,   408,     0,   235,   201,
   238,   249,   241,   242,   243,   244,   251,     0,     0,   263,
     0,   257,     2,     0,     0,   260,   270,   271,   280,   281,
   283,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     0,     0,     0,     0,     0,   310,   312,   313,   314,   200,
   200,   316,   317,   324,   339,   330,   341,   343,   337,   349,
   351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
   365,   366,   378,   367,   368,   369,   370,   372,   373,   379,
   374,   391,     0,     2,     0,     0,     4,     0,   256,     0,
     0,     0,     0,     0,   294,   295,   296,   297,   309,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     3,
     2,     0,     5,     0,     0,     0,     0,     4,   301,   306,
    15,    17,    19,    21,    23,     0,     0,    25,     0,   411,
   261,   262,     0,     0,   302,   307,     0,     0,     0,     0,
     0,   207,   409,   205,     0,   268,     0,     0,     0
};

static const short yydefgoto[] = {   647,
   504,   586,   361,   161,   162,   163,   164,   165,   166,   167,
   168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
   178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
   188,   189,   190,   191,   362,   384,   192,   327,   328,   329,
   366,   372,   330,   331,   332,   379,   521,   526,   333,   334,
   335,   336,   337,   338,   339,   422,   340,   426,   341,   342,
   343,   344,   436,   440,   442,   345,   445,   447,   346,   347,
   348,   349,   350,   351,   193,   355,   356
};

static const short yypact[] = {    -9,
   617,-32768,-32768,-32768,-32768,-32768,-32768,  1441,    14,   -30,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,     5,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,    17,-32768,-32768,   617,   617,   617,   617,
   617,   617,   617,   617,   617,   617,   617,   617,   617,   617,
   617,   617,    20,   952,   952,   617,   617,   617,   617,   617,
   617,   617,   617,   617,   617,   617,   617,   952,   952,   952,
   952,   617,   617,   617,   617,   617,   617,   617,   617,   617,
   617,   617,   617,   617,   617,   617,   617,   617,   617,    21,
   617,   617,    23,   617,   617,   617,   617,   617,   617,   617,
   617,   617,-32768,   617,   617,   617,-32768,   617,   617,   617,
   617,   617,   617,   617,   617,   617,   617,   617,   617,   617,
   617,   617,   617,   617,   617,-32768,   617,   617,   617,   617,
   617,   617,   617,   617,   617,   617,   617,   617,   617,   617,
   617,   617,   617,   617,   617,   617,   617,   617,   617,   617,
   617,   617,   617,   617,   617,   617,   617,   617,   617,   617,
   617,   617,   617,   617,   617,   617,    24,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   617,  1282,    16,    19,-32768,-32768,  1282,-32768,   617,
   617,-32768,-32768,   617,   617,-32768,   617,   617,   617,   617,
   617,-32768,-32768,-32768,-32768,-32768,   617,   -51,   952,    26,
   -18,-32768,-32768,-32768,-32768,-32768,    25,-32768,   617,   617,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   952,   617,
-32768,   952,-32768,   617,   617,   617,   617,   617,   617,   617,
   617,   617,   -62,-32768,   617,   617,-32768,   617,   617,   617,
   -45,-32768,-32768,-32768,   -46,-32768,-32768,-32768,-32768,   617,
   617,   617,-32768,-32768,   617,-32768,   617,-32768,   617,-32768,
   617,-32768,   617,   617,-32768,   617,-32768,   617,   617,   617,
   617,   617,   617,   617,   617,   617,-32768,-32768,-32768,-32768,
-32768,   617,   617,   617,   617,   617,   617,   617,-32768,   617,
-32768,   617,   617,   617,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   617,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,    30,   617,    18,-32768,    31,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   617,   617,-32768,
   617,-32768,  1282,    27,   -11,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   952,   952,   952,   952,   617,-32768,-32768,-32768,-32768,   617,
   617,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,   786,  1282,    35,    29,    18,    33,-32768,   617,
   617,    37,    18,    34,-32768,-32768,-32768,-32768,-32768,    40,
    42,    39,    43,    47,    48,    49,  1441,   -30,    51,-32768,
  1282,   617,-32768,    44,    56,  1118,    50,    18,    21,    23,
-32768,-32768,-32768,-32768,-32768,    57,    53,-32768,    58,-32768,
-32768,-32768,   617,    54,-32768,-32768,    59,    60,    65,    66,
   617,-32768,-32768,-32768,    67,-32768,    76,    77,-32768
};

static const short yypgoto[] = {-32768,
  -356,  -581,    -1,-32768,-32768,-32768,   -50,-32768,  -211,  -239,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,  -195,  -150,  -207,  -525,-32768,-32768,
  -280,  -202,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,  -533,-32768,  -532,-32768,-32768,
-32768,-32768,  -348,  -350,  -349,-32768,  -353,  -352,-32768,-32768,
-32768,-32768,-32768,-32768,    -7,  -515,-32768
};


#define	YYLAST		1613


static const short yytable[] = {   160,
   352,   508,   383,   383,   363,   613,   385,   385,   376,   541,
   542,   543,     1,   544,   519,   520,   383,   383,   383,   383,
   385,   385,   385,   385,     5,   353,   354,   357,   358,   378,
   421,   585,   425,   506,   502,   507,   634,   523,   524,   550,
   525,   551,   583,   588,   593,   594,   611,   612,   608,   616,
   619,   618,   620,   621,   631,   423,   424,   622,   427,   428,
   429,   623,   624,   625,   386,   628,   632,   637,   633,   638,
   639,   605,   641,   642,   643,   648,   649,   399,   400,   401,
   402,   626,   644,   646,   512,   635,   555,   636,   557,   461,
   560,   558,   627,   561,     0,     0,     0,     0,   469,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   505,     0,     0,     0,     0,   505,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,   503,     0,     0,     0,
     0,     0,     0,   382,   382,   510,   592,   383,   517,     0,
     0,   385,     0,     0,     0,     0,     0,   382,   382,   382,
   382,     0,     0,     0,     0,     0,     0,   383,     0,     0,
   383,   385,     0,     0,   385,   359,   360,     0,     0,   364,
   365,   367,   368,   369,   370,   371,   373,   374,   375,   371,
   377,     0,     0,     0,   387,   388,   389,   390,   391,   392,
   393,   394,   395,   396,   397,   398,     0,   610,   522,     0,
   403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
   413,   414,   415,   416,   417,   418,   419,   420,   529,     0,
     0,   531,     0,     0,   629,   430,   431,   432,   433,   434,
   435,     0,   437,   438,   439,     0,   441,   443,   444,   446,
   448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
   458,   459,   460,   505,     0,   462,   463,   464,   465,   466,
   467,   468,     0,   470,   471,   472,   473,   474,   475,   476,
   477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
   487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
   497,   498,   499,   500,   501,     0,     0,     0,   382,   383,
   383,   383,   383,   385,   385,   385,   385,     0,     0,     0,
     0,     0,     0,   609,   505,     0,     0,     0,   382,     0,
     0,   382,     0,     0,   600,   601,     0,     0,   509,     0,
     0,     0,   511,   365,     0,   513,   514,   515,   516,   371,
     0,   505,     0,     0,     0,   518,   609,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   527,   528,     0,
   595,   596,   597,   598,     0,     0,     0,     0,   530,     0,
     0,     0,   532,   533,   534,   535,   536,   537,   538,   539,
   540,     0,     0,   545,   546,     0,   547,   548,   549,     0,
     0,     0,     0,     0,     0,     0,     0,     0,   552,   553,
   554,     0,     0,   435,     0,   556,     0,   439,     0,   441,
     0,   559,   444,     0,   446,     0,   562,   563,   564,   565,
   566,   567,   568,   569,   570,   587,     0,     0,     0,     0,
   571,   572,   573,   574,   575,   576,   577,     0,   578,     0,
   579,   580,   581,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,   582,     0,     0,     0,     0,     0,
   382,   382,   382,   382,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   584,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,   589,   590,     0,   591,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,   587,     0,     0,     0,
     0,     0,   617,   599,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   587,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,   614,   615,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   352,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   630,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     2,     3,     4,     5,     6,     7,     8,     0,     0,     0,
     9,   640,    10,     0,     0,     0,     0,     0,     0,   645,
    11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
    21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
    31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
    91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
   101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
   111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
   121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
   131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
   141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
   151,   152,   153,   154,   155,   156,   157,   158,   159,   602,
   603,   604,   605,   606,     7,   607,     0,     0,     0,     0,
     0,   608,     0,     0,     0,     0,     0,     0,     0,    11,
    12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
    22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
    52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
    82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
    92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
   102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
   112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
   122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
   132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
   142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
   152,   153,   154,   155,   156,   157,   158,   159,     5,     0,
     7,     8,     0,     0,     0,   380,     0,   381,     0,     0,
     0,     0,     0,     0,     0,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
   116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
   126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
   136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
   146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
   156,   157,   158,   159,   605,     0,     7,   607,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
    20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
    30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
    60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
    70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
    80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
    90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
   100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
   110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
   120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
   130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
   140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
   150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     7,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
   116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
   126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
   136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
   146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
   156,   157,   158,   159,   194,     0,    10,     0,     0,     0,
     0,     0,     0,     0,   195,   196,   197,   198,   199,   200,
   201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
   211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
   221,   222,   223,   224,   225,   226,   227,     0,   228,   229,
   230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
   240,   241,     0,     0,     0,   242,     0,   243,   244,   245,
   246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
   256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
   266,   267,   268,   269,   270,   271,   272,     0,     0,     0,
     0,     0,     0,   273,   274,   275,   276,   277,   278,   279,
   280,   281,   282,   283,   284,     0,     0,     0,     0,     0,
     0,   285,   286,   287,   288,   289,   290,   291,   292,   293,
   294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
   304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
   314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
   324,   325,   326
};

static const short yycheck[] = {     1,
     8,   358,   214,   215,   200,   587,   214,   215,   211,    72,
    73,    74,    22,    76,    66,    67,   228,   229,   230,   231,
   228,   229,   230,   231,     7,    12,    57,    23,    12,    10,
    10,    14,    10,    18,    11,    17,   618,    12,    57,    85,
    16,    88,    13,    13,    18,    57,    12,    19,    16,    13,
    11,    18,    11,    15,    11,   251,   252,    15,   254,   255,
   256,    15,    15,    15,   215,    15,    11,    11,    19,    17,
    13,     7,    19,    15,    15,     0,     0,   228,   229,   230,
   231,   607,    17,    17,   365,   619,   435,   620,   439,   285,
   444,   441,   608,   446,    -1,    -1,    -1,    -1,   294,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   353,    -1,    -1,    -1,    -1,   358,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   352,    -1,    -1,    -1,
    -1,    -1,    -1,   214,   215,   361,   523,   379,   371,    -1,
    -1,   379,    -1,    -1,    -1,    -1,    -1,   228,   229,   230,
   231,    -1,    -1,    -1,    -1,    -1,    -1,   399,    -1,    -1,
   402,   399,    -1,    -1,   402,   197,   198,    -1,    -1,   201,
   202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
   212,    -1,    -1,    -1,   216,   217,   218,   219,   220,   221,
   222,   223,   224,   225,   226,   227,    -1,   584,   379,    -1,
   232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
   242,   243,   244,   245,   246,   247,   248,   249,   399,    -1,
    -1,   402,    -1,    -1,   611,   257,   258,   259,   260,   261,
   262,    -1,   264,   265,   266,    -1,   268,   269,   270,   271,
   272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
   282,   283,   284,   523,    -1,   287,   288,   289,   290,   291,
   292,   293,    -1,   295,   296,   297,   298,   299,   300,   301,
   302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
   312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
   322,   323,   324,   325,   326,    -1,    -1,    -1,   379,   541,
   542,   543,   544,   541,   542,   543,   544,    -1,    -1,    -1,
    -1,    -1,    -1,   583,   584,    -1,    -1,    -1,   399,    -1,
    -1,   402,    -1,    -1,   550,   551,    -1,    -1,   360,    -1,
    -1,    -1,   364,   365,    -1,   367,   368,   369,   370,   371,
    -1,   611,    -1,    -1,    -1,   377,   616,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   389,   390,    -1,
   541,   542,   543,   544,    -1,    -1,    -1,    -1,   400,    -1,
    -1,    -1,   404,   405,   406,   407,   408,   409,   410,   411,
   412,    -1,    -1,   415,   416,    -1,   418,   419,   420,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   430,   431,
   432,    -1,    -1,   435,    -1,   437,    -1,   439,    -1,   441,
    -1,   443,   444,    -1,   446,    -1,   448,   449,   450,   451,
   452,   453,   454,   455,   456,   506,    -1,    -1,    -1,    -1,
   462,   463,   464,   465,   466,   467,   468,    -1,   470,    -1,
   472,   473,   474,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,   486,    -1,    -1,    -1,    -1,    -1,
   541,   542,   543,   544,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   505,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   518,   519,    -1,   521,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,   587,    -1,    -1,    -1,
    -1,    -1,   593,   545,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   618,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   590,   591,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   607,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   612,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     4,     5,     6,     7,     8,     9,    10,    -1,    -1,    -1,
    14,   633,    16,    -1,    -1,    -1,    -1,    -1,    -1,   641,
    24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
    34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
    54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
    84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
    94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
   104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
   114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
   124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
   134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
   144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
   154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
   164,   165,   166,   167,   168,   169,   170,   171,   172,     4,
     5,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
    25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
    35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
    55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
    75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
    85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
    95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
   105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
   115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
   125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
   135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
   145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
   155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
   165,   166,   167,   168,   169,   170,   171,   172,     7,    -1,
     9,    10,    -1,    -1,    -1,    14,    -1,    16,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,
    29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
    59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
    79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
    89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
    99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
   109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
   119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
   129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
   139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
   149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
   159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
   169,   170,   171,   172,     7,    -1,     9,    10,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
    53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
    73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
    83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
    93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
   103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
   113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
   123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
   133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
   143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
   153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
   163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,
    29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
    49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
    59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
    69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
    79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
    89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
    99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
   109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
   119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
   129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
   139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
   149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
   159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
   169,   170,   171,   172,    14,    -1,    16,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,    29,
    30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
    50,    51,    52,    53,    54,    55,    56,    -1,    58,    59,
    60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
    70,    71,    -1,    -1,    -1,    75,    -1,    77,    78,    79,
    80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
    90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
   100,   101,   102,   103,   104,   105,   106,    -1,    -1,    -1,
    -1,    -1,    -1,   113,   114,   115,   116,   117,   118,   119,
   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,
    -1,   131,   132,   133,   134,   135,   136,   137,   138,   139,
   140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
   150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
   160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
   170,   171,   172
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/lib/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/usr/lib/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 298 "omparser.y"
{ yyval = yyvsp[-1]; inObj = yyvsp[-1]; YYACCEPT; ;
    break;}
case 3:
#line 304 "omparser.y"
{ /* TODO */ ;
    break;}
case 4:
#line 309 "omparser.y"
{ yyval = C_nil; ;
    break;}
case 5:
#line 311 "omparser.y"
{ yyval = cons(yyvsp[-1], yyvsp[0]); ;
    break;}
case 14:
#line 328 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 15:
#line 330 "omparser.y"
{ yyval = yyvsp[-1]; ;
    break;}
case 16:
#line 335 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 17:
#line 337 "omparser.y"
{ yyval = yyvsp[-1]; ;
    break;}
case 18:
#line 342 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 19:
#line 344 "omparser.y"
{ yyval = yyvsp[-1]; ;
    break;}
case 20:
#line 349 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 21:
#line 351 "omparser.y"
{ yyval = yyvsp[-1]; ;
    break;}
case 22:
#line 356 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 23:
#line 358 "omparser.y"
{ yyval = yyvsp[-1]; ;
    break;}
case 24:
#line 363 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 25:
#line 365 "omparser.y"
{ yyval = yyvsp[-1]; ;
    break;}
case 200:
#line 620 "omparser.y"
{ yyval = C_nil; ;
    break;}
case 201:
#line 622 "omparser.y"
{ yyval = cons(yyvsp[-1], yyvsp[0]); ;
    break;}
case 202:
#line 630 "omparser.y"
{ 	Lisp_Object var = MkUndefSymM("x");
				push2(yyvsp[0],var);
				yyval = list2(list2(yyvsp[0], var), var);
				pop2(var,yyvsp[0]);
			;
    break;}
case 203:
#line 638 "omparser.y"
{ 	Lisp_Object var = MkUndefSymM("x");
				push2(yyvsp[0],var);
				yyval = list2(list2(yyvsp[0], var), var);
				pop2(var,yyvsp[0]);
			;
    break;}
case 204:
#line 646 "omparser.y"
{ 	Lisp_Object var = MkUndefSymM("x");
				push2(yyvsp[0],var);
				yyval = list2(list2(yyvsp[0], var), var);
				pop2(var,yyvsp[0]);
			;
    break;}
case 205:
#line 653 "omparser.y"
{	push2(yyvsp[-1], yyvsp[-3]);
        			yyval = list2(yyvsp[-1], yyvsp[-3]);
				pop2(yyvsp[-3], yyvsp[-1]);
			;
    break;}
case 206:
#line 661 "omparser.y"
{ yyval = yyvsp[-1]; ;
    break;}
case 207:
#line 663 "omparser.y"
{ yyval = yyvsp[-2]; ;
    break;}
case 232:
#line 695 "omparser.y"
{ yyval = fixnum_of_int(0); ;
    break;}
case 233:
#line 697 "omparser.y"
{ yyval = fixnum_of_int(1); ;
    break;}
case 234:
#line 702 "omparser.y"
{	push2(yyvsp[-1],yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 235:
#line 707 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 236:
#line 712 "omparser.y"
{	push2(yyvsp[-1],yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 237:
#line 717 "omparser.y"
{	push2(yyvsp[-1],yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 238:
#line 722 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 239:
#line 727 "omparser.y"
{ yyval = fixnum_of_int(0); ;
    break;}
case 240:
#line 729 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 241:
#line 731 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 242:
#line 736 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 243:
#line 741 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 244:
#line 746 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 245:
#line 751 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 246:
#line 753 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 247:
#line 755 "omparser.y"
{	push2(yyvsp[-1],yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 248:
#line 763 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 249:
#line 765 "omparser.y"
{	Lisp_Object obj = StrToLspM("+");
				push3(obj, yyvsp[-1], yyvsp[0]);
				yyval = list3(obj, yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], obj);
			;
    break;}
case 250:
#line 774 "omparser.y"
{	yyval = yyvsp[0]; ;
    break;}
case 251:
#line 776 "omparser.y"
{	Lisp_Object obj = StrToLspM("*");
				push3(obj, yyvsp[-1], yyvsp[0]);
				yyval = list3(obj, yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], obj);
			;
    break;}
case 252:
#line 785 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 253:
#line 790 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 254:
#line 795 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 255:
#line 799 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 256:
#line 804 "omparser.y"
{	push4(yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = cons(yyvsp[-3], list3(yyvsp[-2], yyvsp[0], yyvsp[-1]));
				pop4(yyvsp[0], yyvsp[-1], yyvsp[-2], yyvsp[-3]);
			;
    break;}
case 257:
#line 812 "omparser.y"
{/*	(|integrate| function range) */
			 /*	FIXME: needs to treat more general cases as well... */
				push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(
					yyvsp[-2],
					qcar(yyvsp[0]),
					list3(
						StrToLspM("="),
						qcar(qcdr(yyvsp[0])),
						yyvsp[-1]
					)
				);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 258:
#line 827 "omparser.y"
{ yyval = cons(yyvsp[-1], yyvsp[0]); ;
    break;}
case 259:
#line 829 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
			        yyval = yyvsp[0];
				yyval = cons(yyvsp[-1], yyvsp[0]); 
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 260:
#line 835 "omparser.y"
{/* (|differentiate| function (|construct| vars...)) */
				Lisp_Object varIndList, varList;
				Lisp_Object funcObj, quoteObj;

				push(yyvsp[-1]);
				varIndList = Ceval(yyvsp[-1], C_nil);
				pop(yyvsp[-1]);
				push(yyvsp[0]);
				varList = qcar(yyvsp[0]);
				funcObj = qcar(qcdr(yyvsp[0]));
				pop(yyvsp[0]);

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

				push3(yyvsp[-2], funcObj, varList);
				yyval = list3(yyvsp[-2], funcObj, varList);
				pop3(varList, funcObj, yyvsp[-2]);
			;
    break;}
case 261:
#line 884 "omparser.y"
{	/* (|segment| lo hi) */
				push3(yyvsp[-3], yyvsp[-2], yyvsp[-1]);
				yyval = list3(yyvsp[-3], yyvsp[-2], yyvsp[-1]);
				pop3(yyvsp[-1], yyvsp[-2], yyvsp[-3]);
			;
    break;}
case 262:
#line 890 "omparser.y"
{	Lisp_Object segObj = StrToLspM("segment");
				Lisp_Object coerceObj = StrToLspM("::");
				Lisp_Object typeObj = list2(StrToLspM("Fraction"), StrToLspM("Integer"));
				push3(segObj, coerceObj, typeObj);
				yyval = list3(
					segObj,
					list3(coerceObj, yyvsp[-2], typeObj),
					list3(coerceObj, yyvsp[-1], typeObj)
				);
				pop3(typeObj, coerceObj, segObj);
			;
    break;}
case 268:
#line 915 "omparser.y"
{	push2(yyvsp[-3], yyvsp[-1]);
				yyval = list2(yyvsp[-3], yyvsp[-1]);
				pop2(yyvsp[-1], yyvsp[-3]);
			;
    break;}
case 269:
#line 923 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 270:
#line 928 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 271:
#line 933 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				/* Unhandled Symbol */
				yyval = list3(yyvsp[-2], make_string("complex_polar"), make_string("complex1"));
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 272:
#line 939 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 273:
#line 944 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 274:
#line 949 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 275:
#line 959 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 276:
#line 961 "omparser.y"
{ yyval = list3(yyvsp[-1], make_string("inverse"), make_string("fns1")); ;
    break;}
case 277:
#line 963 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-1], make_string("image"), make_string("fns1"));
				pop2(yyvsp[-1], yyvsp[0]);
			;
    break;}
case 278:
#line 968 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-1], make_string("range"), make_string("fns1"));
				pop2(yyvsp[-1], yyvsp[0]);
			;
    break;}
case 279:
#line 973 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-1], make_string("domain"), make_string("fns1"));
				pop2(yyvsp[-1], yyvsp[0]);
			;
    break;}
case 280:
#line 978 "omparser.y"
{/*	(ADEF (bv2) (NIL NIL) (NIL NIL) (func1 (func2 bv2))) */
				Lisp_Object types, bv1, bv2, func1, func2;
				types = list2(C_nil, C_nil);
				func1 = qcar(yyvsp[-1]);
				bv1 = qcar(qcdr(yyvsp[-1]));
				func2 = qcar(yyvsp[0]);
				bv2 = qcar(qcdr(yyvsp[0]));

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

				push4(yyvsp[-2], bv2, types, func1);
				yyval = cons(yyvsp[-2], cons(cons(bv2, C_nil), list3(types, types, func1)));
				pop4(func1, types, bv2, yyvsp[-2]);
			;
    break;}
case 281:
#line 1008 "omparser.y"
{	push3(yyvsp[-2],yyvsp[-1],yyvsp[0]);
				yyval = list3(yyvsp[-2],yyvsp[-1],yyvsp[0]);
				pop3(yyvsp[0],yyvsp[-1],yyvsp[-2]);
			;
    break;}
case 282:
#line 1013 "omparser.y"
{yyval = list3(yyvsp[-1], make_string("kernel"), make_string("fns2")); ;
    break;}
case 283:
#line 1015 "omparser.y"
{/*	(ADEF (bv1) (NIL NIL) (NIL NIL) (func2 (func1 bv1))) */
					Lisp_Object types, bv1, bv2, func1, func2;
					types = list2(C_nil, C_nil);
					func1 = qcar(yyvsp[-1]);
					bv1 = qcar(qcdr(yyvsp[-1]));
					func2 = qcar(yyvsp[0]);
					bv2 = qcar(qcdr(yyvsp[0]));

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

					push4(yyvsp[-2], bv2, types, func2);
					yyval = cons(yyvsp[-2], cons(cons(bv1, C_nil), list3(types, types, func2)));
					pop4(func2, types, bv2, yyvsp[-2]);
				;
    break;}
case 284:
#line 1045 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
					yyval = list2(yyvsp[-1], yyvsp[0]);
					pop2(yyvsp[0], yyvsp[-1]);
				;
    break;}
case 285:
#line 1050 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
					yyval = list3(yyvsp[-2], make_string("factorof"), make_string("integer1"));
					pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 286:
#line 1055 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 287:
#line 1060 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 288:
#line 1068 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 289:
#line 1073 "omparser.y"
{	Lisp_Object interpObj = StrToLspM("@");
				Lisp_Object typeObj = list2(
					StrToLspM("Interval"),
					StrToLspM("DoubleFloat")
				);
				push5(yyvsp[-2], yyvsp[-1], yyvsp[0], interpObj, typeObj);
				yyval = list3(interpObj, list3(yyvsp[-2], yyvsp[-1], yyvsp[0]), typeObj);
				pop5(typeObj, interpObj, yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 290:
#line 1083 "omparser.y"
{	Lisp_Object interpObj = StrToLspM("@");
				Lisp_Object typeObj = list2(
					StrToLspM("Interval"),
					StrToLspM("DoubleFloat")
				);
				push5(yyvsp[-2], yyvsp[-1], yyvsp[0], interpObj, typeObj);
				yyval = list3(interpObj, list3(yyvsp[-2], yyvsp[-1], yyvsp[0]), typeObj);
				pop5(typeObj, interpObj, yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 291:
#line 1093 "omparser.y"
{	Lisp_Object interpObj = StrToLspM("@");
				Lisp_Object typeObj = list2(
					StrToLspM("Interval"),
					StrToLspM("DoubleFloat")
				);
				double dLo = float_of_number(yyvsp[-1]);
				double dHi = float_of_number(yyvsp[0]);
				if (dLo > dHi) {
					double dt = dLo;
					dLo = dHi;
					dHi = dt;
				}
				dHi -= DBL_EPSILON;
				push3(yyvsp[-2], interpObj, typeObj);
				yyval = list3(interpObj, list3(yyvsp[-2],
					make_boxfloat(dLo, TYPE_DOUBLE_FLOAT),
					make_boxfloat(dHi, TYPE_DOUBLE_FLOAT)
				), typeObj);
				pop3(typeObj, interpObj, yyvsp[-2]);
			;
    break;}
case 292:
#line 1114 "omparser.y"
{	Lisp_Object interpObj = StrToLspM("@");
				Lisp_Object typeObj = list2(
					StrToLspM("Interval"),
					StrToLspM("DoubleFloat")
				);
				double dLo = float_of_number(yyvsp[-1]);
				double dHi = float_of_number(yyvsp[0]);
				if (dLo > dHi) {
					double dt = dLo;
					dLo = dHi;
					dHi = dt;
				}
				dLo += DBL_EPSILON;
				push3(yyvsp[-2], interpObj, typeObj);
				yyval = list3(interpObj, list3(yyvsp[-2],
					make_boxfloat(dLo, TYPE_DOUBLE_FLOAT),
					make_boxfloat(dHi, TYPE_DOUBLE_FLOAT)
				), typeObj);
				pop3(typeObj, interpObj, yyvsp[-2]);
			;
    break;}
case 293:
#line 1135 "omparser.y"
{	Lisp_Object interpObj = StrToLspM("@");
				Lisp_Object typeObj = list2(
					StrToLspM("Interval"),
					StrToLspM("DoubleFloat")
				);
				double dLo = float_of_number(yyvsp[-1]);
				double dHi = float_of_number(yyvsp[0]);
				if (dLo > dHi) {
					double dt = dLo;
					dLo = dHi;
					dHi = dt;
				}
				dLo += DBL_EPSILON;
				dHi -= DBL_EPSILON;
				push3(yyvsp[-2], interpObj, typeObj);
				yyval = list3(interpObj, list3(yyvsp[-2],
					make_boxfloat(dLo, TYPE_DOUBLE_FLOAT),
					make_boxfloat(dHi, TYPE_DOUBLE_FLOAT)
				), typeObj);
				pop3(typeObj, interpObj, yyvsp[-2]);
			;
    break;}
case 294:
#line 1160 "omparser.y"
{/* (|limit| func (|=| var limiting_val) "right") */
				Lisp_Object limitVal;
				push2(yyvsp[0], yyvsp[-2]);
				limitVal = list3(
					StrToLspM("="),
					qcar(qcdr(yyvsp[0])),
					list3(
						StrToLspM("::"),
						yyvsp[-2],
						list2(
							StrToLspM("Fraction"),
							StrToLspM("Integer")
						)
					)
				);
				pop2(yyvsp[-2], yyvsp[0]);
				push2(yyvsp[-3], yyvsp[0]);
				yyval = cons(yyvsp[-3], list3(qcar(yyvsp[0]), limitVal, make_string("right")));
				pop2(yyvsp[0], yyvsp[-3]);
			;
    break;}
case 295:
#line 1181 "omparser.y"
{/* (|limit| func (|=| var limiting_val) "left") */
				Lisp_Object limitVal;
				push2(yyvsp[0], yyvsp[-2]);
				limitVal = list3(
					StrToLspM("="),
					qcar(qcdr(yyvsp[0])),
					list3(
						StrToLspM("::"),
						yyvsp[-2],
						list2(
							StrToLspM("Fraction"),
							StrToLspM("Integer")
						)
					)
				);
				pop2(yyvsp[-2], yyvsp[0]);
				push2(yyvsp[-3], yyvsp[0]);
				yyval = cons(yyvsp[-3], list3(qcar(yyvsp[0]), limitVal, make_string("left")));
				pop2(yyvsp[0], yyvsp[-3]);
			;
    break;}
case 296:
#line 1202 "omparser.y"
{/* (|limit| func (|=| var limiting_val)) */
				Lisp_Object limitVal;
				push2(yyvsp[0], yyvsp[-2]);
				limitVal = list3(
					StrToLspM("="),
					qcar(qcdr(yyvsp[0])),
					list3(
						StrToLspM("::"),
						yyvsp[-2],
						list2(
							StrToLspM("Fraction"),
							StrToLspM("Integer")
						)
					)
				);
				pop2(yyvsp[-2], yyvsp[0]);
				push2(yyvsp[-3], yyvsp[0]);
				yyval = list3(yyvsp[-3], qcar(yyvsp[0]), limitVal);
				pop2(yyvsp[0], yyvsp[-3]);
			;
    break;}
case 297:
#line 1223 "omparser.y"
{/* (|limit| func (|=| var limiting_val)) */
				Lisp_Object limitVal;
				push2(yyvsp[0], yyvsp[-2]);
				limitVal = list3(
					StrToLspM("="),
					qcar(qcdr(yyvsp[0])),
					list3(
						StrToLspM("::"),
						yyvsp[-2],
						list2(
							StrToLspM("Fraction"),
							StrToLspM("Integer")
						)
					)
				);
				pop2(yyvsp[-2], yyvsp[0]);
				push2(yyvsp[-3], yyvsp[0]);
				yyval = list3(yyvsp[-3], qcar(yyvsp[0]), limitVal);
				pop2(yyvsp[0], yyvsp[-3]);
			;
    break;}
case 298:
#line 1247 "omparser.y"
{	Lisp_Object obj = StrToLspM("construct");
				push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], cons(obj, yyvsp[0]));
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 299:
#line 1253 "omparser.y"
{ yyval = cons(yyvsp[-1], yyvsp[0]); ;
    break;}
case 300:
#line 1255 "omparser.y"
{ yyval = cons(yyvsp[-1], yyvsp[0]); ;
    break;}
case 301:
#line 1260 "omparser.y"
{ yyval = C_nil; ;
    break;}
case 302:
#line 1262 "omparser.y"
{ yyval = cons(cons(yyvsp[-3], yyvsp[-2]), yyvsp[0]); ;
    break;}
case 303:
#line 1267 "omparser.y"
{	Lisp_Object cns = StrToLspM("construct");
				Lisp_Object trn = StrToLspM("transpose");
				push4(trn, yyvsp[-1], cns, yyvsp[0]);
				yyval = list2(trn, list2(yyvsp[-1], cons(cns, yyvsp[0])));
				pop4(yyvsp[0], cns, yyvsp[-1], trn);
			;
    break;}
case 304:
#line 1274 "omparser.y"
{ yyval = cons(yyvsp[-1], yyvsp[0]); ;
    break;}
case 305:
#line 1276 "omparser.y"
{ yyval = cons(yyvsp[-1], yyvsp[0]); ;
    break;}
case 306:
#line 1281 "omparser.y"
{ yyval = C_nil; ;
    break;}
case 307:
#line 1283 "omparser.y"
{ yyval = cons( cons(yyvsp[-3], yyvsp[-2]), yyvsp[0] ); ;
    break;}
case 308:
#line 1288 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 309:
#line 1293 "omparser.y"
{ yyval = cons(yyvsp[-3], list3(yyvsp[-1], yyvsp[0], yyvsp[-2])); ;
    break;}
case 310:
#line 1295 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[0], yyvsp[-1]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 311:
#line 1300 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 312:
#line 1305 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 313:
#line 1310 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 314:
#line 1315 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 315:
#line 1323 "omparser.y"
{ yyval = cons(yyvsp[-1], yyvsp[0]); ;
    break;}
case 316:
#line 1325 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 317:
#line 1330 "omparser.y"
{ /* Deliberately swap arguments for AXIOM */
			 	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[0], yyvsp[-1]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 318:
#line 1344 "omparser.y"
{	Lisp_Object var = MkUndefSymM("x");
				push2(yyvsp[0], var);
				yyval = list2(var, list2(yyvsp[0], var)); 
				pop2(var, yyvsp[0]);
			;
    break;}
case 319:
#line 1352 "omparser.y"
{	Lisp_Object var = MkUndefSymM("x");
				push2(yyvsp[0], var);
				yyval = list2(var, list2(yyvsp[0], var)); 
				pop2(var, yyvsp[0]);
			;
    break;}
case 320:
#line 1360 "omparser.y"
{	Lisp_Object var = MkUndefSymM("x");
				push2(yyvsp[0], var);
				yyval = list2(var, list2(yyvsp[0], var)); 
				pop2(var, yyvsp[0]);
			;
    break;}
case 321:
#line 1366 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 322:
#line 1368 "omparser.y"
{ yyval = yyvsp[-1]; ;
    break;}
case 323:
#line 1374 "omparser.y"
{	push2(yyvsp[-3], yyvsp[-1]);
				yyval = list2(yyvsp[-3], yyvsp[-1]);
				pop2(yyvsp[-1], yyvsp[-3]);
			;
    break;}
case 324:
#line 1382 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 325:
#line 1387 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 326:
#line 1392 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 327:
#line 1400 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 328:
#line 1402 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 329:
#line 1404 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 330:
#line 1406 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 331:
#line 1411 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 332:
#line 1416 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 333:
#line 1418 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 334:
#line 1420 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 335:
#line 1422 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 336:
#line 1424 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 337:
#line 1426 "omparser.y"
{yyval = list3(yyvsp[-2], make_string("equivalent"), make_string("logic1")); ;
    break;}
case 338:
#line 1431 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 339:
#line 1433 "omparser.y"
{	Lisp_Object obj = StrToLspM("and");
				push3(obj, yyvsp[-1], yyvsp[0]);
				yyval = list3(obj, yyvsp[-1], yyvsp[0]); 
				pop3(yyvsp[0], yyvsp[-1], obj);
			;
    break;}
case 340:
#line 1442 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 341:
#line 1444 "omparser.y"
{	Lisp_Object obj = StrToLspM("or");
				push3(obj, yyvsp[-1], yyvsp[0]);
				yyval = list3(obj, yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], obj);
			;
    break;}
case 342:
#line 1453 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 343:
#line 1455 "omparser.y"
{	Lisp_Object obj = StrToLspM("xor");
				push3(obj, yyvsp[-1], yyvsp[0]);
				yyval = list3(obj, yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], obj);
			;
    break;}
case 344:
#line 1464 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 345:
#line 1466 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 346:
#line 1468 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 347:
#line 1470 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 348:
#line 1475 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 349:
#line 1477 "omparser.y"
{	Lisp_Object obj = StrToLspM("max");
				push3(obj, yyvsp[-1], yyvsp[0]);
				yyval = list3(obj, yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], obj);
			;
    break;}
case 350:
#line 1486 "omparser.y"
{ yyval = yyvsp[0]; ;
    break;}
case 351:
#line 1488 "omparser.y"
{	Lisp_Object obj = StrToLspM("min");
				push3(obj, yyvsp[-1], yyvsp[0]);
				yyval = list3(obj, yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], obj);
			;
    break;}
case 352:
#line 1499 "omparser.y"
{yyval = list3(yyvsp[-2], make_string("based_integer"), make_string("nums1")); ;
    break;}
case 353:
#line 1501 "omparser.y"
{/*	(|@| (/ numer denom) (|Fraction| |Integer|)) */
				push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(
					StrToLspM("@"),
					list3(yyvsp[-2], yyvsp[-1], yyvsp[0]),
					list2(
						StrToLspM("Fraction"),
						StrToLspM("Integer")
					)
				);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 354:
#line 1517 "omparser.y"
{	Lisp_Object coerceObj = StrToLspM("::");
				Lisp_Object nameObj = StrToLspM("SExpression");
				push5(yyvsp[-2], yyvsp[-1], yyvsp[0], coerceObj, nameObj);
				yyval = list3(yyvsp[-2],
					list3(coerceObj, yyvsp[-1], nameObj),
					list3(coerceObj, yyvsp[0], nameObj)
				);
				pop5(nameObj, coerceObj, yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 355:
#line 1527 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 356:
#line 1532 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 357:
#line 1537 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 358:
#line 1542 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 359:
#line 1547 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 360:
#line 1552 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], make_string("approx"), make_string("relation1"));
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 361:
#line 1560 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 362:
#line 1565 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 363:
#line 1570 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 364:
#line 1575 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 365:
#line 1583 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 366:
#line 1588 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 367:
#line 1593 "omparser.y"
{	Lisp_Object notObj = StrToLspM("not");
				push4(notObj, yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list2(notObj, list3(yyvsp[-2], yyvsp[-1], yyvsp[0]));
				pop4(yyvsp[0], yyvsp[-1], yyvsp[-2], notObj);
			;
    break;}
case 368:
#line 1599 "omparser.y"
{	Lisp_Object notObj = StrToLspM("not");
				push4(notObj, yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list2(notObj, list3(yyvsp[-2], yyvsp[-1], yyvsp[0]));
				pop4(yyvsp[0], yyvsp[-1], yyvsp[-2], notObj);
			;
    break;}
case 369:
#line 1605 "omparser.y"
{	Lisp_Object notObj = StrToLspM("not");
				push4(notObj, yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list2(notObj, list3(yyvsp[-2], yyvsp[-1], yyvsp[0]));
				pop4(yyvsp[0], yyvsp[-1], yyvsp[-2], notObj);
			;
    break;}
case 370:
#line 1611 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 371:
#line 1616 "omparser.y"
{
				yyval = cons(yyvsp[-1], yyvsp[0]);
			;
    break;}
case 372:
#line 1620 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 373:
#line 1625 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 374:
#line 1630 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 375:
#line 1635 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 376:
#line 1640 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-1], make_string("cartesian_product"), make_string("set1"));
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 377:
#line 1645 "omparser.y"
{	push(yyvsp[0]);
				yyval = Llist(C_nil, yyvsp[0]);
				pop(yyvsp[0]);
			;
    break;}
case 378:
#line 1650 "omparser.y"
{	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 379:
#line 1655 "omparser.y"
{ /* Deliberately swap arguments for AXIOM */
			 	push3(yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(yyvsp[-2], yyvsp[0], yyvsp[-1]);
				pop3(yyvsp[0], yyvsp[-1], yyvsp[-2]);
			;
    break;}
case 380:
#line 1664 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 381:
#line 1669 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 382:
#line 1674 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 383:
#line 1679 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 384:
#line 1684 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 385:
#line 1689 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 386:
#line 1694 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 387:
#line 1699 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 388:
#line 1704 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 389:
#line 1709 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 390:
#line 1714 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 391:
#line 1719 "omparser.y"
{	Lisp_Object obj = StrToLspM("/");
				push4(obj, yyvsp[-2], yyvsp[-1], yyvsp[0]);
				yyval = list3(obj, list2(yyvsp[-2], yyvsp[0]), list2(yyvsp[-2], yyvsp[-1]));
				pop4(yyvsp[0], yyvsp[-1], yyvsp[-2], obj);
			;
    break;}
case 392:
#line 1725 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 393:
#line 1730 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 394:
#line 1735 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 395:
#line 1740 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 396:
#line 1745 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 397:
#line 1750 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 398:
#line 1755 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 399:
#line 1760 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 400:
#line 1765 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 401:
#line 1770 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 402:
#line 1775 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 403:
#line 1780 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 404:
#line 1785 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 405:
#line 1790 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 406:
#line 1795 "omparser.y"
{	push2(yyvsp[-1], yyvsp[0]);
				yyval = list2(yyvsp[-1], yyvsp[0]);
				pop2(yyvsp[0], yyvsp[-1]);
			;
    break;}
case 407:
#line 1803 "omparser.y"
{ yyval = cons(yyvsp[-1], yyvsp[0]); ;
    break;}
case 408:
#line 1808 "omparser.y"
{ yyval = yyvsp[-1]; ;
    break;}
case 409:
#line 1810 "omparser.y"
{ yyval = yyvsp[-2]; ;
    break;}
case 411:
#line 1819 "omparser.y"
{	Lisp_Object types = C_nil;
				Lisp_Object llen = Llength(C_nil, yyvsp[-2]);
				int len = int_of_fixnum(llen);
				int i;

				for (i = 0; i < len; i++)
					types = cons(C_nil, types);
				types = cons(C_nil, types);

				push4(yyvsp[-4], yyvsp[-2], yyvsp[0], types);
				yyval = cons(yyvsp[-4], cons(yyvsp[-2], list3(types, types, yyvsp[0])));
				pop4(types, yyvsp[0], yyvsp[-2], yyvsp[-4]);
			;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/usr/lib/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 1834 "omparser.y"


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

