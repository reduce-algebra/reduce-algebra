// cwinres.h
//           Header file for resources ONLY. The files cwin.h & cwin.hpp
//           contains declarations needed for compiling code.
//
//     Copyright (C)/©/¸ Codemist Ltd, 1995-99


#ifndef header_cwinres_h
#define header_cwinres_h 1

/* Signature: 43767a10 19-Feb-1999 */

#define  IDM_READ          101
#define  IDM_SAVEAS        102
#define  IDM_SAVESEL       103
#define  IDM_TOFILE        104
#define  IDM_PRINT         105
#define  IDM_PRINTSEL      106
#define  IDM_EXIT          107
#define  IDM_CLOSE         108

#define  IDM_CUT           110
#define  IDM_COPY          111
#define  IDM_PASTE         112
#define  IDM_REINPUT       113
#define  IDM_SELECTALL     114
#define  IDM_CLEAR         115
#define  IDM_UNDO          116
#define  IDM_REDRAW        117
#define  IDM_HOME          118
#define  IDM_END           119

#define  IDM_FONT          120
#define  IDM_RESET_FONT    121
#define  IDM_RESET_WINDOW  122

#define  IDM_INTERRUPT     130
#define  IDM_BACKTRACE     131
#define  IDM_PAGEMODE      132

#ifdef GRAPHICS_WINDOW

#define  IDM_GRAPHICS      140
#define  IDM_HISTORY       141

#define  IDM_SMALLER       150

#define  IDM_LARGER        160

#define  IDM_PORTRAIT      170
#define  IDM_DISPLAY       171
#define  IDM_LANDSCAPE     172

#define  IDM_VIEWPOINT     180

#endif

#define  IDM_HELPCONTENTS  190
#define  IDM_HELPSEARCH    191
#define  IDM_HELP_ON_HELP  192
#define  IDM_ABOUT         193
#define  IDM_EUPRICES      194
#define  IDM_WORDPRICES    195
#define  IDM_ORDERFORM     196

#define  IDM_DYNAMIC_ITEMS 200
#define  IDM_LAST_DYNAMIC  249

#ifdef GRAPHICS_WINDOW

#define  IDM_WIREFRAME     250
#define  IDM_NOSURFACE     251
#define  IDM_SURFACE       252
#define  IDM_SQUARES       253
#define  IDM_TRIANGLES     254
#define  IDM_SMOOTH        255
#define  IDM_HISMOOTH      256
#define  IDM_WIREPREVIEW   257

#define  IDM_ROTLEFT       260
#define  IDM_ROTRIGHT      261
#define  IDM_ROTUP         262
#define  IDM_ROTDOWN       263
#define  IDM_CLOCKWISE     264
#define  IDM_ANTICLOCK     265
#define  IDM_ENLARGE       266
#define  IDM_SHRINK        267

#endif

#ifndef COMMON

#define  IDM_FIRSTLOAD      300

/*
 * The individual numeric codes listed here (and the matching menu items
 * in cwin.rc) are being retired in favour of a scheme that sets up menus
 * more dynamically.
 */

#define  IDM_ALGINT         300
#define  IDM_APPLYSYM       301
#define  IDM_ARNUM          302
#define  IDM_ASSIST         303
#define  IDM_AVECTOR        304
#define  IDM_BOOLEAN        305
#define  IDM_CALI           306
#define  IDM_CAMAL          307
#define  IDM_CHANGEVR       308
#define  IDM_COMPACT        309
#define  IDM_COMPLEX        310
#define  IDM_CRACK          311
#define  IDM_CVIT           312
#define  IDM_DECOMPOS       313
#define  IDM_DEFINT         314
#define  IDM_DESIR          315
#define  IDM_DFPART         316
#define  IDM_DUMMY          317
#define  IDM_ELEM           318
#define  IDM_EXCALC         319
#define  IDM_FIDE           320
#define  IDM_FPS            321
#define  IDM_GENTRAN        322
#define  IDM_GNUPLOT        323
#define  IDM_GROEBNER       324
#define  IDM_IDEALS         325
#define  IDM_INEQ           326
#define  IDM_INVBASE        327
#define  IDM_LAPLACE        328
#define  IDM_LIE            329
#define  IDM_LINALG         330
#define  IDM_MODSR          331
#define  IDM_NCPOLY         332
#define  IDM_NORMFORM       333
#define  IDM_NUMERIC        334
#define  IDM_ODESOLVE       335
#define  IDM_ORTHOVEC       336
#define  IDM_PHYSOP         337
#define  IDM_PMRULES        338
#define  IDM_RANDPOLY       339
#define  IDM_REACTEQN       340
#define  IDM_RESIDUE        341
#define  IDM_RLFI           342
#define  IDM_RSOLVE         343
#define  IDM_SCOPE          344
#define  IDM_SETS           345
#define  IDM_SPDE           346
#define  IDM_SPECFN         347
#define  IDM_SYMMETRY       348
#define  IDM_TAYLOR         349
#define  IDM_TPS            350
#define  IDM_TRI            351
#define  IDM_TRIGSIMP       352
#define  IDM_WU             353
#define  IDM_XCOLOR         354
#define  IDM_XIDEAL         355
#define  IDM_ZEILBERG       356
#define  IDM_ZTRANS         357

#define  IDM_LASTLOAD       357

#define  IDS_FIRSTSWITCH    500

#define  IDS_algint         500
#define  IDS_adjprec        501
#define  IDS_allbranch      502
#define  IDS_allfac         503
#define  IDS_arbvars        504
#define  IDS_asterisk       505
#define  IDS_backtrace      506
#define  IDS_balanced_mod   507
#define  IDS_bfspace        508
#define  IDS_combineexpt    509
#define  IDS_combinelogs    510
#define  IDS_comp           511
#define  IDS_complex        512
#define  IDS_compxroots     513
#define  IDS_cramer         514
#define  IDS_cref           515
#define  IDS_defn           516
#define  IDS_demo           517
#define  IDS_dfprint        518
#define  IDS_div            519
#define  IDS_echo           520
#define  IDS_errcont        521
#define  IDS_evallhseqp     522
#define  IDS_exp            523
#define  IDS_expandexpt     524
#define  IDS_expandlogs     525
#define  IDS_ezgcd          526
#define  IDS_factor         527
#define  IDS_fastfor        528
#define  IDS_force          529
#define  IDS_fort           530
#define  IDS_fortupper      531
#define  IDS_fullprec       532
#define  IDS_fullprecision  533
#define  IDS_fullroots      534
#define  IDS_gc             535
#define  IDS_gcd            536
#define  IDS_heugcd         537
#define  IDS_horner         538
#define  IDS_ifactor        539
#define  IDS_int            540
#define  IDS_intstr         541
#define  IDS_lcm            542
#define  IDS_lessspace      543
#define  IDS_limitedfactors 544
#define  IDS_list           545
#define  IDS_listargs       546
#define  IDS_lower          547
#define  IDS_mcd            548
#define  IDS_modular        549
#define  IDS_msg            550
#define  IDS_multiplicities 551
#define  IDS_nat            552
#define  IDS_nero           553
#define  IDS_noarg          554
#define  IDS_noconvert      555
#define  IDS_nonlnr         556
#define  IDS_nosplit        557
#define  IDS_numval         558
#define  IDS_output         559
#define  IDS_period         560
#define  IDS_pgwd           561
#define  IDS_plap           562
#define  IDS_precise        563
#define  IDS_pret           564
#define  IDS_pri            565
#define  IDS_pwrds          566
#define  IDS_quotenewnam    567
#define  IDS_raise          568
#define  IDS_rat            569
#define  IDS_ratarg         570
#define  IDS_rational       571
#define  IDS_rationalize    572
#define  IDS_ratpri         573
#define  IDS_reduced        574
#define  IDS_revpri         575
#define  IDS_rlisp88        576
#define  IDS_rootmsg        577
#define  IDS_roundall       578
#define  IDS_roundbf        579
#define  IDS_rounded        580
#define  IDS_savestructr    581
#define  IDS_solvesingular  582
#define  IDS_time           583
#define  IDS_trallfac       584
#define  IDS_trfac          585
#define  IDS_trint          586
#define  IDS_trroot         587
                            
#define  IDS_LASTSWITCH     587

#endif

#endif /* header_cwinres_h */

// end of cwinres.h

