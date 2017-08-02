
% u38.lsp           Machine generated Lisp

(c!:install "u38" 5909 8674530 6840317)

(c!:install 'talp_specsub '(talp_specsub ((res . scalar) (op . scalar))
true false talp_atfp talp_specsubat talp_op talp_argl) 
18163975277556999350)

(c!:install 'ithlistelem '(ithlistelem nth) 7719509158233613037)

(c!:install 'sparpri '(sparpri ((val . scalar) (row . scalar)) quote
setq first (quote !$) last writepri) 8746266212575710468)

(c!:install 'evalb '(evalb algebraic true false formbool eval) 
5861203536084675183)

(c!:install 'min0 '(min0 min max) 12393225392512410134)

(c!:install 'physoptimes '(physoptimes ((lht . scalar) (rht . scalar) (
lhtype . scalar) (rhtype . scalar) (x . scalar) (mul . scalar)) tstack!*
mul!* scalar physopsim!* getphystype physop2sq multsq mk!*sq physopaeval
physopordchk multopop!*) 11207824659159958274)

(c!:install 'deletez1 '(deletez1 nreverse) 14734844965284007186)

(c!:install 'assert_procstat!-argl '(assert_procstat!-argl ((var .
scalar) (type . scalar) (w . scalar) (argtypel . scalar)) cursym!*
!*rpar!* "Expecting identifier but found" !*colon!*
"Expecting type but found" (!*comma!* !*rpar!*)
"Expecting ',' or ')' but found" !*comma!* nxtsym!* !: returnvalue
eolcheck assert_rederr scan assert_typesyntaxp) 18312426068016557181)

(c!:install 'remchkf1 '(remchkf1 ((n . integer)) !*trcompact
"*** Remainder smaller" termsf xremf prin2t) 10403794558917301417)

(c!:install 'gvar1 '(gvar1 i !*complex (plus times expt difference minus
) quotient gvarlis1) 10478615922619036053)

(c!:install 'lalr_print_first_information '(lalr_print_first_information
"=== FIRST sets for each nonterminal ===" nonterminals ":" lalr_first
" " lalr_prin_symbol) 4398663868268776971)

(c!:install 'give!*position '(give!*position ((j . scalar) (found .
scalar)) "error in give position" nth rederr) 1984191744137210425)

(c!:install 'cl_pnf2 '(cl_pnf2 ((op . scalar) (w . scalar)) ex all or
and true false not impl repl equiv bex ball "cl_pnf2():"
"invalid as operator" cl_pnf2!-quantifier cl_pnf2!-junctor rl_external
apply rederr) 4983668437086268948)

(c!:install 'getargsrd '(getargsrd ((a . scalar)) char (b v a r) bvarrd
lex) 5917374291337736216)

(c!:install 'close_forall '(close_forall flagg "</apply>" printout) 
5670340073436456286)

(c!:install 'degreef '(degreef max) 9999072322222969174)

(c!:install 'matrixp '(matrixp mat sparsemat reval) 6909277299753611861)

(c!:install 'sc_mkmatrix '(sc_mkmatrix ((matr . scalar) (new!-row .
scalar)) sc_simp sc_iputv) 9176297432975028056)

(c!:install 'string2bytelist '(string2bytelist ((r . scalar) (w . scalar
)) string2list) 14489576029392763140)

(c!:install 'gftimes '(gftimes gfftimes gbftimes) 5154146903667630288)

(c!:install 'sublap '(sublap ((x . scalar)) app sublap1) 
9507188692187567971)

(c!:install '!*!*a2i '(!*!*a2i ieval intexprnp) 17857848832979299686)

(c!:install 'drnconv '(drnconv dmd!*) 12269271242945414679)

(c!:install 'rl_fvarl '(rl_fvarl rl_fvarl!* apply) 4349438644931979515)

(c!:install 'taydegree!< '(taydegree!< ((u1 . scalar) (v1 . scalar))
tayexp!-greaterp tayexp!-lessp) 6383126720214479471)

(c!:install 'internal!-factorf '(internal!-factorf current!-modulus
m!-image!-variable ((m!-image!-variable . scalar) (new!-korder . scalar)
(old!-korder . scalar) (sign . scalar) (v . scalar) (w . scalar) (d .
scalar)) !*kernreverse kernord setkorder reorder minusf negf comfac
comfac!-to!-poly quotf1 factorize!-primitive!-polynomial
distribute!.multiplicity fctrf1 to fac!-merge) 15979377140088209822)

(c!:install 'symbolsom '(symbolsom ((cd . scalar) (var . scalar) (fun .
scalar) (int . scalar) (name . scalar)) valid_om!* diff condition
"<condition> tag not supported in MathML" "<OMA>" int defint
"<OMS cd=""" """ name=""" """/>" lambda "</OMA>" errorml printout
indent!* objectom lambdaom) 668712312742349020)

(c!:install 'contposp '(contposp) 8182456738789676309)

(c!:install 'exdff0 '(exdff0 multsqpf exdfp0 multpfsq addpf) 
13966361513958058173)

(c!:install '!:!:quotient '(!:!:quotient i2rd!* !:quotient) 
15132540149930532904)

(c!:install 'getphystypeall '(getphystypeall ((x . scalar))
"PHYSOP type mismatch in" deleteall collectphystype rederr2) 
1367731310037140724)

(c!:install 'evalgreaterp '(evalgreaterp difference "number" simp!*
minusf negsq mk!*sq typerr !:minusp) 12669567216885518850)

(c!:install 'bas_make '(bas_make dp_ecart) 11969008909803901740)

(c!:install 'split!-further '(split!-further ((a . scalar) (b . scalar)
(gg . scalar) (q . scalar)) number!-needed work!-vector1 dwork1
work!-vector2 dwork2 copy!-vector gcd!-in!-vector quotfail!-in!-vector) 
6808160647903321014)

(c!:install 'ext_mult '(ext_mult ext merge_lists !*a2k to) 
9547799705883413000)

(c!:install 'multivariatep '(multivariatep) 6455206724317581613)

(c!:install 'lex_init '(lex_init last64 last64p which_line if_depth
!*tracelex "yylex initialized" lex_peeked yyreadch) 2545617430861042629)

(c!:install 'rl_qefsolset '(rl_qefsolset rl_qefsolset!* apply) 
18185265947675789221)

(c!:install 'even_action_sf '(even_action_sf ((action . scalar))
even_action_term addsq) 14710738266246556114)

(c!:install 'talp_maxd '(talp_maxd ((tmp . scalar) (md . integer) (mdtmp
. integer)) rl_atl talp_arg2l talp_td talp_arg2r) 10668731309087620029)

(c!:install 'rl_bnfsimpl '(rl_bnfsimpl rl_bnfsimpl!* apply) 
12102889295070448289)

(c!:install 'sfto_b!:extadd '(sfto_b!:extadd nreverse addf
sfto_b!:ordexp) 14555970045207833266)

(c!:install 'ciml '(ciml "<ci" "" "</ci>" printout attributesml) 
10619037057796267404)

(c!:install 'groebinvokecritm '(groebinvokecritm mcount!*
buchvevdivides!? groedeletip) 590440005261952739)

(c!:install 'collectphysops_reversed '(collectphysops_reversed physopp
collectindices removeindices) 5162854092352589005)

(c!:install 'subcare '(subcare subfunc nreverse) 16246309351900561860)

(c!:install 'fs!:make!-nullangle '(fs!:make!-nullangle ((ans . scalar)))
 16096756319203989620)

(c!:install 'dp_from_ei '(dp_from_ei cali_bc_fi mo_from_ei dp_term) 
1551402700809790358)

(c!:install 'giplus!: '(giplus!: mkgi) 12497355129620666169)

(c!:install 'ofsf_sippsubst1 '(ofsf_sippsubst1 ofsf_siatsubf) 
8204819944402773185)

(c!:install 'rl_convertarg '(rl_convertarg rl_conversionfunction apply) 
16762408709431988432)

(c!:install 'repr_n '(repr_n "repr_n : invalid REPR structure" rederr) 
9234101115622280862)

(c!:install 'setrd '(setrd ((setvars . scalar) (ats . scalar)) atts (
type) set retattributes stats_getargs) 3747456156439647758)

(c!:install 'valuecoefft '(valuecoefft "Valuecoefft - no value" interr) 
11085630856475024248)

(c!:install 'gbfplus '(gbfplus plubf) 12825317034124909812)

(c!:install 'r2findindex1 '(r2findindex1 "index not found" rederr) 
89207632565066563)

(c!:install 'intrdsortin '(intrdsortin nreverse !:difference !:minusp) 
12946241828873678541)

(c!:install 'contr2 '(contr2 contr nreverse split!-road) 
18339366017502773054)


% End of generated Lisp code

