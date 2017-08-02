
% u05.lsp           Machine generated Lisp

(c!:install "u05" 180048 8259596 4716218)

(c!:install 'resimp '(resimp varstack!* resimp1) 245030305365798647)

(c!:install 'kernord!-sort '(kernord!-sort ((x . scalar) (y . scalar))
maxdeg delallasc) 3686868347379040344)

(c!:install 'ev_comp '(ev_comp dip_sortevcomp!* apply) 
6308362367969480729)

(c!:install 'revlis '(revlis reval) 12784786891327265868)

(c!:install 'round!:last '(round!:last !:rd!: lshift) 
11771289043284577007)

(c!:install 'rd!:minusp '(rd!:minusp minusp!:) 6192968839908774165)

(c!:install 'fprin2 '(fprin2 !*lower !*fortupper prin2!-upcase
prin2!-downcase) 11224564587785184818)

(c!:install 'tensopp '(tensopp tensor isanindex) 15497026400427711128)

(c!:install 'getroad '(getroad qassoc) 3298571974922732838)

(c!:install 'fs!:plus '(fs!:plus ((coef . scalar)) angles!-equal addsq
fs!:angle!-order) 13372579131402806506)

(c!:install 'mo_sum '(mo_sum mo!=sum mo!=shorten mo!=deglist) 
11690513269509191580)

(c!:install 'insert_pv '(insert_pv sieve_pv pv_renorm insert_pv1) 
3928730491069730406)

(c!:install 'rntimes!: '(rntimes!: mkrn) 16843820830970689749)

(c!:install 'orderactions '(orderactions shift ordp) 9345515028130377688
)

(c!:install 'ofsf_clnegrel '(ofsf_clnegrel ofsf_lnegrel) 
10718404464395059854)

(c!:install 'quotf1 '(quotf1 ((u . scalar) (v . scalar) (w . scalar) (x
. scalar) (xx . scalar) (y . scalar) (z . scalar) (z1 . scalar) (n .
integer)) !*mcd quotfd rank lt!* to negf multf addf aconc!* rnconc ordop
quotk) 5757200980954450380)

(c!:install 'tayexp!-plus2 '(tayexp!-plus2 !*i2rn rnplus!:) 
17543982543919753841)

(c!:install 'subs2 '(subs2 ((xexp . scalar) (v . scalar) (w . scalar) (x
. scalar)) subfg!* !*sub2 powlis1!* slash !*match !*exp subs2q exptchksq
resimp subs3q subs4q) 4959908422197722710)

(c!:install 'talp_negateat '(talp_negateat ((op . scalar)) equal neq
talp_op talp_arg2l talp_arg2r talp_mk2) 4613640234785563129)

(c!:install 'mri_floorp '(mri_floorp floor) 15639793372292956144)

(c!:install 'rl_susibin '(rl_susibin rl_susibin!* apply) 
14790073274071796983)

(c!:install 'ibalp_varlt '(ibalp_varlt ibalp_varlt1) 
11883918343511078755)

(c!:install 'findrow '(findrow ((list . scalar) (rlist . scalar))
sparsemat) 10778174883902106805)

(c!:install 'getrtype1 '(getrtype1 !3vector) 17623002873539832421)

(c!:install 'rmsubs '(rmsubs !*sqvar!* alglist!*) 8232088002439907036)

(c!:install 'scprint '(scprint ((m . scalar)) !*utf8 posn!* utf8_scprint
) 3066823333177549529)

(c!:install 'safe!-fp!-plus '(safe!-fp!-plus ((r . scalar)) 0.0
!!minnorm !!minnegnorm 0.00195312) 3244108188168113361)

(c!:install 'formlis '(formlis ((x . scalar)) form1 reversip!*) 
1261942890744877493)

(c!:install 'getel1 '(getel1 "array index" rlisp "Array out of bounds"
typerr rerror) 14149257150581464448)

(c!:install 'prepsqx '(prepsqx !*intstr prepsq!* prepsq) 
2057516612996716158)

(c!:install 'mo!=shorten '(mo!=shorten ((m1 . scalar))) 
8188436328187202309)

(c!:install 'pv_sort1 '(pv_sort1 pv_sort2) 18324050516951395998)

(c!:install 'noncomdel '(noncomdel noncomp!* noncomdel1) 
9512117499868604191)

(c!:install 'checkargcount '(checkargcount ((correctn . scalar))
naryargs curfun!* hasarg instdof) 14984585471208680544)

(c!:install 'reordsq '(reordsq reorder) 6551028279869735544)

(c!:install 'tayexp!-minusp '(tayexp!-minusp rnminusp!:) 
11440009276948992143)

(c!:install 'addsq '(addsq ((x . scalar) (y . scalar) (z . scalar))
!*exp !*lcm !*gcd addf mkprod gcdf!* gcdf quotf!-fail canonsq multf) 
2343442705142335313)

(c!:install 'talp_mkinv '(talp_mkinv) 9881918859696743090)

(c!:install 'rl_prepat '(rl_prepat rl_prepat!* apply) 
7678146107771699444)

(c!:install 'fac!-merge '(fac!-merge multf) 9464410801670856120)

(c!:install 'ibalp_getupl '(ibalp_getupl ((upl . scalar))) 
6421423721522787559)

(c!:install 'listsum '(listsum) 4359773221243097064)

(c!:install 'mathml_list2string '(mathml_list2string) 
8144497037046277680)

(c!:install 'sqform '(sqform quotient) 12561050226564334981)

(c!:install 'ps!:getv '(ps!:getv !:ps!: tps "PS:GETV: not a ps" eval
rerror) 16942942242138714985)

(c!:install 'c!:ordexp '(c!:ordexp c!:ordxp) 16045650534029472007)

(c!:install 'dm!-times '(dm!-times zero2nil !:times) 
10142955220570690041)

(c!:install 'vevtdeg '(vevtdeg) 390444595040601212)

(c!:install 'simpminus '(simpminus minus carx simp negsq) 
5896211553045019281)

(c!:install 'find_item '(find_item) 11091868128839770907)

(c!:install 'update!-pline '(update!-pline) 8413433348725287400)

(c!:install 'prin2!-downcase '(prin2!-downcase red!-char!-downcase) 
2999629200536730834)

(c!:install 'widestring2list '(widestring2list ((w . scalar) (r . scalar
) (n . scalar) (c . scalar)) "Improper byte in utf-8 string" string2list
land moan!-if!-truncated lshift error) 16457497357983390651)

(c!:install 'readch1 '(readch1 ((x . scalar) (y . scalar) (w . scalar) (
n . scalar) (save . scalar)) peekchar!* !$eof!$ !*psl !*raise !*lower
!$eol!$ curline!* crbuf1!* crbuf!* !# !; unicode_character
named!-character!* u !U x !X hexdigit red!-char!-downcase char!-downcase
char!-upcase terminalp id2string string!-length list2string int2wideid) 
382284339268676425)

(c!:install 'mo_compare '(mo_compare ((x . scalar)) cali!=basering
revlex mo!=degcomp ring_tag mo!=revlexcomp mo!=lexcomp) 
1752879122192982701)

(c!:install 'prin2!* '(prin2!* !*utf8 outputhandler!* ((m . integer) (n
. integer) (p . integer) (x . scalar)) overflowed!* overflowed !*fort
!*nat pi !.pi infinity !*rounded posn!* spare!* testing!-width!*
utf8_prin2!* fprin2!* symbol widelengthc i2rd!* rd!:prin terpri!*
add_prin_char prin2lint) 2590609923311525863)

(c!:install 'insert_pv1 '(insert_pv1 reduce_pv pv_renorm) 
13461779201674913131)

(c!:install 'noncomp!* '(noncomp!* expt noncomp) 11520600477447941211)

(c!:install 'aconc '(aconc) 4286747449048000529)

(c!:install 'anform '(anform !*globals locls!* glb2rf globs!* anform1) 
2819029936396861794)

(c!:install 'ofsf_vareqnp '(ofsf_vareqnp sfto_varisnump) 
609914299391789314)

(c!:install 'polynomclone '(polynomclone ((tmppolynom . scalar) (
polynomiterator . scalar)) monomclone) 10603688290712247943)

(c!:install 'subs3q '(subs3q ((x . scalar)) mchfg!* subs3f quotsq) 
14240785092821181351)

(c!:install 'ckrn1 '(ckrn1 ((x . scalar)) gck2 noncomp) 
1125439684290953513)


% End of generated Lisp code

