
% u52.lsp           Machine generated Lisp

(c!:install "u52" 20654 9000083 9900603)

(c!:install 'mod!* '(mod!* cali!=degrees dpmat_coldegs dp_neworder
dpmat_list bas_make red_redpol bas_dpoly) 1926040955582660415)

(c!:install 'monicmember '(monicmember gg!* nil t monic) 
1773917593966844174)

(c!:install 'sep_tens_from_other '(sep_tens_from_other translate1 t
!*n2f fullcopy setcar tensorp no_dum_varp multf) 2158871522937798739)

(c!:install 'reduce!-mod!-eig '(reduce!-mod!-eig nil reduce!-mod!-eigf
lcm quotf multf) 455080532723605792)

(c!:install 'make!-univariate!-mod!-p '(make!-univariate!-mod!-p t
evaluate!-in!-order!-mod!-p !*n2f adjoin!-term) 1684543301683153546)

(c!:install 'my_freeof '(my_freeof depl!* nil smember freeofdepl) 
921718580149925090)

(c!:install 'taysimpsq!* '(taysimpsq!* nil !*taylorautoexpand taysimpsq)
 2248755144385674747)

(c!:install 'addcoeffs '(addcoeffs nil smallest!-increment
common!-increment makecoeffpairs multsq addsq) 1424128364073273772)

(c!:install 'ofsf_posvarpat '(ofsf_posvarpat (greaterp geq) nil
sfto_varp) 1809424616931723861)

(c!:install 'iv_congp '(iv_congp) 1582047794851047910)

(c!:install 'numlistp '(numlistp t nil) 2012200505616564845)

(c!:install 'dipsimpconti '(dipsimpconti nil !*groebdivide !*groebrm
groebmonfac bcfd dipcontenti bcplus!? bcneg bcone!? dipcontlowerev evdif
evzero!? dipreduceconti dipmonfac) 1385325641894561808)

(c!:install 'xvarlistp '(xvarlistp t nil xvarp) 76980965298637073)

(c!:install 'gfrlmult '(gfrlmult !:rd!: fl2bf gbfmult normbf read!:num
gffmult) 411448169738710356)

(c!:install 'partitinnerprod '(partitinnerprod partitop innerprodpf) 
8883592435385114)

(c!:install 'replace_edge2 '(replace_edge2) 581054168860553246)

(c!:install 'mv!-reduced!-coeffs '(mv!-reduced!-coeffs nil mv!-!/) 
985520175458915883)

(c!:install 'mo_support '(mo_support cali!=basering nil ring_names
mo_from_a mo_divides!?) 1897918634685938880)

(c!:install 'getsetvarlis '(getsetvarlis "getsetvarlis" (setel setk)
setq errach nreverse) 2021691902255954252)

(c!:install 'pseudo!-divide '(pseudo!-divide nil t poly!-divide!*) 
1954959286671937729)

(c!:install 'no_of_tm_sf_limited '(no_of_tm_sf_limited t) 
584841158207714251)

(c!:install 'lrootchk '(lrootchk nil krootchk) 596209748052321557)

(c!:install 'pasf_smwrmknowl '(pasf_smwrmknowl !*rlsusi pasf_susirmknowl
cl_smrmknowl) 47500139863204398)

(c!:install 'gb_buchcrit4t '(gb_buchcrit4t ev_disjointp) 
256866813429161736)

(c!:install 'cgp_shift '(cgp_shift !*cgbgen cgp_shift!-gen cgp_shift1) 
97128806111523292)

(c!:install 'crn!:onep '(crn!:onep (1 . 1) nil) 686182006267925929)

(c!:install 'rewrite2 '(rewrite2 nil) 2176527659367536494)

(c!:install 'mx '(mx reval pm_m1) 2033905859357259444)

(c!:install 'grpbf '(grpbf t nil order!:) 935330567905507030)

(c!:install 'redexpp '(redexpp t !*redarithexpops!* !*redlogexpops!*
!*redreswds!*) 365146733599614018)

(c!:install 'mo_dlexcomp '(mo_dlexcomp mo!=lexcomp) 1176551237110189972)

(c!:install 'dv_skelsplit1 '(dv_skelsplit1 nil !* copy lastpair) 
1525414552319530384)

(c!:install 'cr2rderr '(cr2rderr
"complex to real type conversion requires zero imaginary part" error) 
1936012077293626543)

(c!:install 'cd_surep '(cd_surep !*rlgsvb !*cgbgs t !*rlspgs !*rlsithok
rl_surep) 8305617494507145)

(c!:install 'simppsexplim '(simppsexplim ps!:exp!-lim psexplim nil carx
ieval) 76995428546463393)

(c!:install 'simp!:ps!: '(simp!:ps!: simp!:ps1) 2025566615156754466)

(c!:install 'tchscheme '(tchscheme rowmax nil codmat maxvar t chscheme
transferrow) 1933429846154179)

(c!:install 'fast!-stack!-rows '(fast!-stack!-rows) 1858118498792371307)

(c!:install 'groerevlist '(groerevlist nil reval getrlist) 
1037191964888192230)

(c!:install 'xnp '(xnp nil) 1364558411567724926)

(c!:install 'fortexp1 '(fortexp1 !+ nil t minus !*!* literal range !:
!:rd!: !:lower!-sci!: !:upper!-sci!: !. !*double !D !E (!D 0) !:crn!:
!:gi!: !:cr!: !*f90 cmplx!( !, kind!(1!.0!D0!) !) !*fortranname!* (real
dble) real listp fortranname optype fortranprecedence fortranop
insertparens lastpair isfloat !*gi2cr !*crn2cr rd!:explode fortliteral
fortexp) 627273730332312513)

(c!:install 'algint!-subsublis '(algint!-subsublis !*sq subfunc nil
algint!-subsq) 2210589709704843313)

(c!:install 'general!-quotient!-mod!-p '(general!-quotient!-mod!-p
"B=0 IN GENERAL-QUOTIENT-MOD-P" t nil exact!-quotient!-flag
general!-modular!-reciprocal general!-multiply!-by!-constant!-mod!-p
ordop adjoin!-term general!-xquotient!-mod!-p errorf) 
1731427575502545076)

(c!:install 'get!-alpha '(get!-alpha alphalist "Alpha not found for "
" in " assoc!-alpha errorf) 425178542861694733)

(c!:install 'pasf_exprng!-gball '(pasf_exprng!-gball t
"pasf_exprng: bad bound " " with free variables " !*rlexprngnatural nil
and true false cl_fvarl rederr pasf_exprng pasf_qff2ivl pasf_sisub) 
86946155298281280)

(c!:install 'cpr_buchcrit4t '(cpr_buchcrit4t ev_disjointp) 
1875249702315620495)


% End of generated Lisp code

