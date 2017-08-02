
% u36.lsp           Machine generated Lisp

(c!:install "u36" 56480 9449843 9350354)

(c!:install 'talp_sumd '(talp_sumd ((tmp . scalar) (sd . integer))
rl_atl talp_arg2l talp_td talp_arg2r) 10892878792290591241)

(c!:install 'matrixom '(matrixom "<OMA>"
"<OMS cd=""linalg1"" name=""matrix""/>" "</OMA>" printout indent!*
matrixrowom) 9644613628154774012)

(c!:install '!*a2k '(!*a2k ((x . scalar)) kernel simp!* kernp typerr) 
8281215974036431212)

(c!:install 'matsm1 '(matsm1 ((x . scalar) (y . scalar) (z . scalar) (
len . scalar) (n . integer)) !*div sparsemat mat matrix
"Matrix mismatch" sparse "Non square matrix" subfg!* inversefn
lnrsolvefn !*sub2 "Zero divisor" "Matrix" "not set" spmultm lispapply
multsm multm lchk rerror xsimp checksp spmatsm matsm subs2 revpr
generateident) 4867210883474349852)

(c!:install 'noncomexpf '(noncomexpf noncomp) 5575421815131349904)

(c!:install 'dipprodin '(dipprodin dipzero dipprodin1 dipsum) 
17397364834695958208)

(c!:install 'color!-roads '(color!-roads ((e1 . scalar) (e2 . scalar) (
e3 . scalar) (lines . scalar))) 12841465118492548952)

(c!:install 'realvaluedp '(realvaluedp realvalued ((caru . scalar))
alwaysrealvalued !:rd!: realvaluedlist) 9023018177008024464)

(c!:install 'log_assignment '(log_assignment quote function setq
"+++ Assignment to parameter of inline: " "+++ Macro was: " inlineinfo
cond log_assignment_list_list log_assignment_list) 8320727009848696406)

(c!:install 'subeval1 '(subeval1 ((y . scalar) (z . scalar)) subfn alg
"No substitution defined for type" !*sub2 getrtype rerror simp subsq
subs2 mk!*sq) 8769543063423835354)

(c!:install 'remchkf '(remchkf remchkf1 kernels intersection) 
7564202488979874806)

(c!:install 'dp_neworder '(dp_neworder dp!=mocompare mo_neworder sort) 
14657201897860316967)

(c!:install 'ad_splitname '(ad_splitname ((uu . scalar) (nn . scalar))
charnump!:) 10782894195199100011)

(c!:install 'ratdif '(ratdif ratminus ratplusm) 8523472214507921043)

(c!:install 'lex_process_directive '(lex_process_directive ((w . scalar)
) yylval !#endif if_depth "+++ #endif not follopwing #if" !$eof!$
"+++ #endif missing at end of file" !#if !#else !#elif read_s_expression
errorset errorp lex_skip_to_else_or_endif) 18031669433059662845)

(c!:install 'polynomwrite '(polynomwrite nreverse monomwrite) 
8019372385341136277)

(c!:install 'ofsf_smcpknowl '(ofsf_smcpknowl) 16842228859866707994)

(c!:install 'plusdf '(plusdf nreverse !*addsq orddf) 
10154485941733850895)

(c!:install 'gen!+can!+bas '(gen!+can!+bas ((eins . scalar) (nullsq .
scalar) (i . scalar) (j . scalar) (ll . scalar))) 11042513933147353437)

(c!:install 'iv_cutcongs1 '(iv_cutcongs1 iv_cutcongs2) 
7532152779373007213)

(c!:install 'vdp_putprop '(vdp_putprop ((c . scalar) (p . scalar))) 
4920085295548576027)

(c!:install 'bc_mkat '(bc_mkat) 11608354390859674424)

(c!:install 'applyfnrd '(applyfnrd ((b1 . scalar) (b2 . scalar) (c1 .
scalar)) fnrd stats_getargs) 10960131211083153396)

(c!:install 'maxl '(maxl max) 15330531340632273549)

(c!:install 'recaliasbacksubst '(recaliasbacksubst constp) 
7026364058141692205)

(c!:install 'amatch '(amatch r p !*semantic equal mval unify suchp
resume) 5585579030456768667)

(c!:install 'dipsimpcont '(dipsimpcont !*vdpinteger !*groebdivide
dipsimpconti dipsimpcontr) 603366294860614937)

(c!:install 'vdpilcomb1 '(vdpilcomb1 ((r . scalar)) !*gsugar dipilcomb1
dip2vdp gsugar vevtdeg max gsetsugar) 2503205053533280197)

(c!:install 'chkint!* '(chkint!* !*!*roundbf !:rd!: !!maxbflexp fl2bf
read!:num normbf msd rndbfon) 15655245400453327677)

(c!:install 'po!:statep '(po!:statep state) 14306850752333635111)

(c!:install 'color!-strand '(color!-strand nreverse color!-roads) 
13048520133353012665)

(c!:install 'greaterpcdr '(greaterpcdr) 8968584287361009996)

(c!:install 'subs2chk '(subs2chk ((x . scalar)) subfg!* subs2f) 
17381995801078977510)

(c!:install 'fs!:prin '(fs!:prin " 0 " " + " prin2!* fs!:prin1) 
6908279454003400687)

(c!:install 'mo!=zero '(mo!=zero) 13998459805112765093)

(c!:install '!*f2di '(!*f2di varlist!* addgt pdmult pcmult psum) 
17461722156329616849)

(c!:install 'dv_ind2var '(dv_ind2var g_dvnames g_dvbase upbve mkid) 
17529332376884670646)

(c!:install 'msolve!-polyn '(msolve!-polyn current!-modulus
msolve!-poly1 subf lastpair) 2360298124392123331)

(c!:install 'reduce!-mod!-eigf '(reduce!-mod!-eigf !*sub2 cancel negsq
reduce!-eival!-powers subs2) 18377647075100431114)

(c!:install 'domainvalchk '(domainvalchk ((x . scalar)) dmode!* valuechk
mk!*sq) 17656628488317632186)

(c!:install 'get!*inverse '(get!*inverse ((invlist . scalar)) inverse
give!*position nth) 14302678929141173667)


% End of generated Lisp code

