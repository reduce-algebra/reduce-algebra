
% u41.lsp           Machine generated Lisp

(c!:install "u41" 430 7283672 4196329)

(c!:install 'fs!:zerop!: '(fs!:zerop!: t nil) 350664043061632421)

(c!:install '!*g2lex '(!*g2lex nil psum) 620354904668138515)

(c!:install 'ratpoly_univarp '(ratpoly_univarp sfto_univarp) 
2163562893467236634)

(c!:install 'operator_fn '(operator_fn ((arcsinh . sinh) (arcsech . sech
) (arccosh . cosh) (arccsch csch) (arctanh . tanh) (arccoth . coth))
"<apply><inverse/>" nil "<apply><fn><ci>" "</ci></fn>" indent "</apply>"
printout multi_args) 887140034774169036)

(c!:install 'evalmember '(evalmember getrlist) 674673312422097180)

(c!:install 'mkdmoderr '(mkdmoderr lambda (!*x!*) dmoderr) 
560371362299189013)

(c!:install 'find_triangles1 '(find_triangles1 nil select_triangles) 
921683840285998016)

(c!:install 'negex '(negex negf nreverse) 201606356876881323)

(c!:install 'mo_from_ei '(mo_from_ei mo!=deglist mo_zero) 
602087789336090225)

(c!:install 'simp0 '(simp0 !*factor !*sq nil subfg!* !*sub2 alglist!* t
simp0fn prepsq!* frvarsof setkorder simp delete_from_alglist simpiden) 
2220637349986936266)

(c!:install 'pasf_dnf '(pasf_dnf and dnf pasf_puregconp pasf_pnf
pasf_pbnf) 1373428122110867313)

(c!:install 'reprod '(reprod nil multf) 1680435243969883784)

(c!:install 'ps!:arg!-values '(ps!:arg!-values nil t !:ps!: ps!:value) 
1777542839821814982)

(c!:install 'spmatlength '(spmatlength sparsemat matrix "Matrix"
"not set" list rerror) 1102465676049906727)

(c!:install 'den '(den simp!* mk!*sq) 2266476348450318270)

(c!:install 'dipcontenti '(dipcontenti !*groebrm nil dipcontenti1) 
1720690646852099713)

(c!:install 'dim!<!=deg '(dim!<!=deg dimex!* t nil deg!*form negf addf) 
1597085064993042672)

(c!:install 'natnump '(natnump nil) 837708986667196379)

(c!:install 'rdzchk '(rdzchk 0.0 t nil !!fleps1 rd!-tolerance!* bfz!*
abs!: times!: lessp!:) 1075211769949984069)

(c!:install 'adjp '(adjp unit adjoint comm anticomm) 507533349238098650)

(c!:install 's_noparents '(s_noparents has_parents nreverse) 
1736511321414976285)

(c!:install 'mo_deletecomp '(mo_deletecomp nil mo!=deglist) 
488984179924039477)

(c!:install 'balance_mod '(balance_mod) 688586339938142847)

(c!:install 'remainder!-mod!-p '(remainder!-mod!-p
"B=0 IN REMAINDER-MOD-P" t nil xremainder!-mod!-p errorf) 
1617505365660957407)

(c!:install '!*q2f '(!*q2f polynomial prepsq typerr) 1992770000421239697
)

(c!:install 'ofsf_smwrmknowl '(ofsf_smwrmknowl !*rlsusi ofsf_susirmknowl
ofsf_smrmknowl) 81208063966011404)

(c!:install 'mktag '(mktag nil texprec !\!( !\!) makefunc texexplode) 
2171572979981061329)

(c!:install 'ps!:times!-erule '(ps!:times!-erule nil ps ps!:order
ps!:evaluate multsq addsq) 408827580316550273)

(c!:install 'crprep1 '(crprep1 nil minus plus rd!:zerop rd!:minusp
rd!:minus crprimp) 1717234639998606711)

(c!:install 'solvealgtrig01 '(solvealgtrig01 (sin cos tan cot sinh cosh
tanh coth) constant_exprp union) 1996054250338805224)

(c!:install 'sc_rowscalarproduct '(sc_rowscalarproduct nil sc_simp
fast!-column!-dim sc_getmat sc_multsq sc_addsq) 980670286350788801)

(c!:install 'simpwedge '(simpwedge partitwedge !*pf2sq) 
1857253920508819625)

(c!:install 'mkforttab '(mkforttab forttab fortcurrind!*) 
194199250556763354)

(c!:install 'physoppri '(physoppri nil "x= " " y= " "nat= " !*nat
" contract= " !*contract !" "(" obrkp!* !*comma!* t ")" !- !1 !+ " z= "
" x1= " expt trwrite exptpri prin2!* inprint pnth) 1294828544294185811)

(c!:install 'strand!-alg!-top '(strand!-alg!-top nil deletez1
color!-strand contract!-strand dstr!-to!-alg) 1066361833696827269)

(c!:install 'pst_mkpst '(pst_mkpst nil pst_mkpst1 pst_equitable) 
1119549800287236044)

(c!:install 'add!-factor '(add!-factor nil) 1135026712130103929)

(c!:install 'ofsf_decdeg2 '(ofsf_decdeg2 !*gcd t !*rlbrkcxk nil odd
ofsf_cxkdgcd cl_atl1 ofsf_ignshift quotf sfto_reorder gcdf) 
246217381498551241)

(c!:install 'ofsf_irl2atl '(ofsf_irl2atl nil ofsf_ir2atl lastpair) 
1999193066804717430)

(c!:install 'simp_all_ineq_with_equ_sq '(simp_all_ineq_with_equ_sq
alg_poly terms max_term_to_pred kern expt starde derivs nil torder list
ftem_ lex ineq_ t contradiction_ ineq_or print_
"Contradiction: The equation:" equal !*sq sqval
"transformed all expressions, each given as a list of factors:"
"within one OR-inequality modulo all other equations to zero."
"Due to vanishing expressions an OR-inequality is now"
"converted to a normal inequality where each of the"
"following factors must not vanish: " freeof aeval simp_ineq_with_equ_sq
addsqineq union mathprint eqprint) 2219363989582746772)

(c!:install 'pasf_premf '(pasf_premf remf pasf_premf1) 
1302106345876169980)

(c!:install 'cl_bnfsimpl '(cl_bnfsimpl !*rlbnfsac cl_sac) 
1992113928242124091)

(c!:install 'dvfsf_ppolyp '(dvfsf_ppolyp t p nil kernels) 
1126301945952123569)

(c!:install 'gcdld '(gcdld t gcd!-with!-number) 1316750812650340790)

(c!:install 'simpsqrtsq '(simpsqrtsq simpsqrt2) 716761607846718595)

(c!:install 'ldf!-dep!-var '(ldf!-dep!-var nil depl!* ldt!-tvar makeset)
 799932098294362677)

(c!:install 'nestzerop!: '(nestzerop!: simp) 1274628154170026995)

(c!:install 'vdpcleanup '(vdpcleanup nil dipevlist!*) 502938669518610163
)

(c!:install 'remove_least_item '(remove_least_item
"How did we get here?" remove_root_item rederr) 367934720557431123)

(c!:install 'applysetop '(applysetop nil list setvalued "set" setdiff
reval delete!-dups make!-set typerr aeval) 445657864416251660)

(c!:install 'mkassign '(mkassign setq) 1784845354946001370)

(c!:install 'coeff_calc '(coeff_calc plus coeff1_calc reval) 
545285013038681672)

(c!:install 'rfirst '(rfirst list nil "list" listeval0 typerr reval
parterr aeval) 1768895054251206701)

(c!:install 'set!-weights '(set!-weights nil) 942807277933079476)

(c!:install 'fs!:minusp '(fs!:minusp nil minusf) 739057131223260109)

(c!:install 'lesspcar '(lesspcar) 486420850439597881)


% End of generated Lisp code

