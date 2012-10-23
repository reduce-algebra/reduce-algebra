
% u38.lsp           Machine generated Lisp

(c!:install "u38" 3313 9714466 1371268)

(c!:install 'splitcomplex '(splitcomplex kord!* t !*exp i idvalfn
expand!-imrepart repartf impartf setkorder reorder subs2) 
764889137118991384)

(c!:install 'nestzerop!: '(nestzerop!: simp) 1274628154170026995)

(c!:install 'evequal '(evequal nil t (0)) 162531075110848313)

(c!:install 'row_dim '(row_dim !*fast_la nil !*protfg
"Error in row_dim: input should be a matrix." lprie size_of_matrix
matrixp) 1417416162410303378)

(c!:install 'rationalizef '(rationalizef nil expt quotient i t (quotient
1 2) sqrt (quotient 1 3) (quotient 1 4) kernels1 lowertowerp mkmain
conjquadratic conjcubic conjquartic) 2090445109797394738)

(c!:install 'red!=subst1 '(red!=subst1 !*bcsimp "---> " "." " uses "
bas_dpoly dp_lc bas_rep bc_inv bc_prod bc_fi dp_lmon mo_diff dp_times_bc
dp_times_bcmo dp_diff cali_trace dp_print bas_nr bas_make1 bc_gcd
bc_divmod) 361221532838411975)

(c!:install 'mkindxlist '(mkindxlist nil minus !*num2id) 
1856295516987800448)

(c!:install 'ofsf_smeqtable '(ofsf_smeqtable ((equal (equal . equal) (
neq . false) (geq . equal) (leq . equal) (greaterp . false) (lessp . 
false)) (neq (neq . neq) (geq . greaterp) (leq . lessp) (greaterp . 
greaterp) (lessp . lessp)) (geq (geq . geq) (leq . equal) (greaterp . 
greaterp) (lessp . false)) (leq (leq . leq) (greaterp . false) (lessp . 
lessp)) (greaterp (greaterp . greaterp) (lessp . false)) (lessp (lessp
 . lessp)))) 1215348524260009273)

(c!:install 'get!*order '(get!*order get!*elements) 1961358405182470548)

(c!:install 'pasf_pnf '(pasf_pnf rl_nnf pasf_pnf1) 519862379900335075)

(c!:install 'bc_2a '(bc_2a prepf) 644824148841606953)

(c!:install 'ofsf_sacrel!-and '(ofsf_sacrel!-and ((lessp (lessp . keep)
(leq . keep2) (equal . drop) (neq . keep2) (geq . drop) (greaterp . drop
)) (leq (lessp . keep1) (leq . keep) (equal . keep1) (neq . lessp) (geq
 . equal) (greaterp . drop)) (equal (lessp . drop) (leq . keep2) (equal
 . keep) (neq . drop) (geq . keep2) (greaterp . drop)) (neq (lessp . 
keep1) (leq . lessp) (equal . drop) (neq . keep) (geq . greaterp) (
greaterp . keep1)) (geq (lessp . drop) (leq . equal) (equal . keep1) (
neq . greaterp) (geq . keep) (greaterp . keep1)) (greaterp (lessp . drop
) (leq . drop) (equal . drop) (neq . keep2) (geq . keep2) (greaterp . 
keep)))) 1788034428219295700)

(c!:install 'matrixrd '(matrixrd nil char (m a t r i x r o w) (!/ m a t
r i x r o w) "</matrixrow>" mat aeval lex matrixrowrd errorml) 
1737984440574777874)

(c!:install 'search_att '(search_att nil (stop) !  != !" t !$ find
errorml) 1982126949879098658)

(c!:install 'listeq '(listeq nil) 2063551688827354275)

(c!:install 'mkprec '(mkprec fixedpreclis!* preclis!* nil infix op unary
nary) 799177604596311052)

(c!:install 'preproc '(preproc preproc1) 93797400033213538)

(c!:install 'color!-strand '(color!-strand color!-roads nreverse) 
1519305087284542905)

(c!:install 'quotofd '(quotofd t nil mkrn int!-equiv!-chk nreverse
lowest!-terms) 2102623346851057237)

(c!:install 'simpsqrt3 '(simpsqrt3 listofallsqrts listofnewsqrts
knowntobeindep actualsimpsqrt) 198460194971198955)

(c!:install 'rtrnda '(rtrnda rlval!# round!:dec1 decimal2internal) 
777991326442741264)

(c!:install '!*s2i '(!*s2i "integer" typerr) 968289169307440120)

(c!:install 'co_hfn '(co_hfn cl_fvarl1 rl_atnum) 1124030370406417194)

(c!:install 'even_action_pow '(even_action_pow nil component_action
multsq find_active_components diffp addsq) 39966624644770320)

(c!:install 'cnml '(cnml nil atts (t y p e) char (c o n s t a n t)
rdci!* ((r e a l) (i n t e g e r)) ((r a t i o n a l) (c o m p l e x !-
c a r t e s i a n) (c o m p l e x !- p o l a r)) (r a t i o n a l) (c o
m p l e x !- c a r t e s i a n) (c o m p l e x !- p o l a r) search_att
lex apply errorml seprd po2ca comp2 alg_quotient) 1276681560043763149)

(c!:install 'ldf!-sep!-var '(ldf!-sep!-var ldf!-pow!-var ldf!-dep!-var
compl ldf!-spf!-var) 244071086637132373)

(c!:install 'transferrow1 '(transferrow1 codmat maxvar nil) 
1243056662242331832)

(c!:install 'xexptpf '(xexptpf wedgepf) 2002618631577602484)

(c!:install 'mk_parents_prim '(mk_parents_prim s_noparents
mk_edge_parents) 162538637311508163)

(c!:install 'njets '(njets combin) 1430456143211559356)

(c!:install 'mkrootsq '(mkrootsq t (minus 1) nil i expt
!*precise_complex factorbound!* !*ifactor quotient simp exptsq mkrootsql
opmtch mksq mksqrt zfactor1 !*d2q) 447351031222923455)

(c!:install 'update_components '(update_components nil) 
1023550167711174905)

(c!:install 'mri_opn '(mri_opn mri_op) 2036384330803727972)

(c!:install 'cl_sacat '(cl_sacat keep nil) 1987925681016809754)

(c!:install 'pasf_smordtable2 '(pasf_smordtable2 ((lessp (lessp 2) (leq
2) (equal 2) (neq nil) (geq nil) (greaterp nil) (cong nil) (ncong nil))
(leq (lessp 2) (leq 2) (equal 2) (neq nil) (geq nil) (greaterp nil) (
cong nil) (ncong nil)) (equal (lessp false) (leq false) (equal false) (
neq 1) (geq 1) (greaterp 1) (cong nil) (ncong nil)) (neq (lessp 2) (leq
2) (equal 2) (neq nil) (geq nil) (greaterp nil) (cong nil) (ncong nil))
(geq (lessp false) (leq false) (equal false) (neq 1) (geq 1) (greaterp 1
) (cong nil) (ncong nil)) (greaterp (lessp false) (leq false) (equal
false) (neq 1) (geq 1) (greaterp 1) (cong nil) (ncong nil)))) 
239562974591753651)

(c!:install 'ratpoly_minus '(ratpoly_minus negf addsq) 
642501371650992921)

(c!:install 'ev_mtest!? '(ev_mtest!? t nil) 724144092715302348)

(c!:install 'dvfsf_0mk2 '(dvfsf_0mk2 nil) 417119454214080077)

(c!:install 'pdiffvars '(pdiffvars ind pnth) 667144658730022747)

(c!:install 'ps!:set!-term '(ps!:set!-term "less than the order of "
errmsg!* !*protfg "less than power of last term of " t !:ps!: dname nil
ps!:order lprie ps!:putv ps!:getv ps!:last!-term) 1690448097859041326)

(c!:install 'addns '(addns ordp nreverse addsq) 564154211775859928)

(c!:install 'dipreplus '(dipreplus plus) 2231842920475923467)

(c!:install 'vevzero!?1 '(vevzero!?1 t nil) 934012342982908038)

(c!:install 'gfdiffer '(gfdiffer difbf) 1690434788135435379)

(c!:install 'equiv!-coeffs '(equiv!-coeffs mv!-pow!-!> nreverse nzeros) 
1331851324197063902)

(c!:install 'simp!-prop '(simp!-prop propvars!* nil and or !'and !'or
!'true !'false t times not full boolean reval simp!-prop1 prepf
simp!-prop!-dist simp!-prop2 simp!-prop!-form simp) 164776302537465396)

(c!:install 'mod!/ '(mod!/ current!-modulus general!-reciprocal!-by!-gcd
) 1070135859137580275)

(c!:install 'xquotient!-mod!-p '(xquotient!-mod!-p nil t
exact!-quotient!-flag fkern getpower quotient!-mod!-p negate!-term
times!-term!-mod!-p plus!-mod!-p times!-mod!-p difference!-mod!-p) 
1894032331427177642)

(c!:install 'bc_minus!? '(bc_minus!? minusf) 1952517193192629692)

(c!:install 'lowupperlimitml '(lowupperlimitml "<lowlimit>" t nil
"</lowlimit>" "<uplimit>" "</uplimit>" printout indent!* expression) 
1492536106977873344)

(c!:install 'i2ps '(i2ps) 1228974304425396579)

(c!:install 'sprow_dim '(sprow_dim !*fast_la nil !*protfg
"Error in sprow_dim: input should be a matrix." lprie spmatlength
matrixp) 1002833468951326463)

(c!:install 'vdpsimpcont '(vdpsimpcont nil monfac dipsimpcont dip2vdp
evzero!? vdpputprop evtdeg) 1561328366091331221)

(c!:install 'mkupf '(mkupf nil t mksq partitsq!*) 1327335907876771635)

(c!:install 'rfirst '(rfirst list nil "list" "Expression"
"does not have part" t listeval0 typerr reval msgpri aeval) 
129254477270972603)


% End of generated Lisp code

