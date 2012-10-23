
% u25.lsp           Machine generated Lisp

(c!:install "u25" 12938 8668113 2615058)

(c!:install 'simp!-prop1 '(simp!-prop1 !'and nil !'or not implies or t
equiv and true false (or !*true (not !*true)) (and !*true (not !*true))
boolean prop!* not_prop!* propvars!* reval simp addf multf) 
1044207012247574868)

(c!:install 'skp_ordp '(skp_ordp atom_compare cons_ordp) 
1955200832874693131)

(c!:install 'texstrlen '(texstrlen nil !! t) 794390135283403354)

(c!:install 'offexpchk '(offexpchk !*really_off_exp frlis!*
freevarinexptchk mkprod canprod) 1358505097838405137)

(c!:install 'get!*inverse '(get!*inverse inverse give!*position pnth) 
2078823590028941445)

(c!:install 'qqe_eta!-in!-term1 '(qqe_eta!-in!-term1 qepsilon t nil
qqe_simplterm qqe_op) 913073649869870035)

(c!:install 'opfneval '(opfneval remember noval nil kvalue eval
put!-kvalue revlis) 684401613657772344)

(c!:install 'close_forall '(close_forall flagg "</apply>" printout) 
1043551819731447101)

(c!:install 'ps!:evaluate!-next '(ps!:evaluate!-next ps ps!:erule
ps!:getv ps!:expression apply prepsqxx simp!* ps!:set!-term) 
1451468694344642539)

(c!:install 'derad '(derad ordp nreverse) 1360178742516480715)

(c!:install 'insoccs '(insoccs nil subscriptedvarp constp insertocc) 
2144727946593282948)

(c!:install 'vdpequal '(vdpequal t number nil vdpgetprop dipequal) 
862489867885819791)

(c!:install 'dip2vdp '(dip2vdp !*groebsubs vdp nil dipsubs2 a2bc) 
1395952947560364680)

(c!:install '!*xadd '(!*xadd nil) 1891280429130297442)

(c!:install 'ratlessp '(ratlessp ratdif) 885470824671184428)

(c!:install 'horner!-rule!-for!-one!-var '(horner!-rule!-for!-one!-var t
nil multf addf) 52957983471049377)

(c!:install 'formproc '(formproc fname!* ftype!* !*lose !*defn nil !*msg
"***" "not defined (LOSE flag)" (quote nil) !*redeflg!* "redefined" t
"is a reserved identifier" errmsg!* !*protfg rblock (expr fexpr macro)
progn declare special !*nosmacros smacro expr "SMACRO" de fexpr df macro
dm procfn putc lambda symbolic flag opfn !*argnochk (expr smacro)
number!-of!-args variadic !*strict_argcount "Definition of"
"different count from args previously called with" "defined with"
"but previously called with" "arguments" put (fexpr macro smacro)
!*micro!-version lpriw getd lprie pairxvars form1 symbvarlst mkprogn
eval) 1028359286094348724)

(c!:install 'ofsf_negateat '(ofsf_negateat ofsf_lnegrel) 
1853243829346918467)

(c!:install 'plusdf '(plusdf orddf !*addsq nreverse) 931113904879075087)

(c!:install 'ombindir '(ombindir (!/ o m b i n d) lex omobj variablesir
tobvarir checktag) 1324113408450774951)

(c!:install 'alg_plus '(alg_plus plus aeval) 54209013442699845)

(c!:install 'redcodmat '(redcodmat rowmin rowmax nil testred) 
324873024368088783)

(c!:install 'critical_element '(critical_element) 2159678942939411618)

(c!:install 'getrlist '(getrlist list !*sq prepf "list" sqform typerr) 
567044806723996742)

(c!:install 'indordl2 '(indordl2 indordlp) 1117277181951425814)

(c!:install 'ezgcdf1 '(ezgcdf1 factor!-level gcdlist poly!-abs) 
1090411191736042162)

(c!:install 'l!-subst '(l!-subst nreverse) 1627928267960162687)

(c!:install 'gvar1 '(gvar1 t i !*complex nil dname (plus times expt
difference minus) quotient gvarlis1) 1255243885764260245)

(c!:install 'clean_numid '(clean_numid !*id2num nreverse) 
1717281175596201174)

(c!:install 'ofsf_smordtable '(ofsf_smordtable ((equal (equal . false) (
neq equal . t) (geq equal . t) (leq . false) (greaterp equal . t) (lessp
 . false)) (neq (equal equal) (neq) (geq) (leq leq) (greaterp) (lessp
lessp)) (geq (equal . false) (neq geq . t) (geq geq . t) (leq . false) (
greaterp geq . t) (lessp . false)) (leq (equal equal) (neq) (geq) (leq
leq) (greaterp) (lessp lessp)) (greaterp (equal . false) (neq greaterp
 . t) (geq greaterp . t) (leq . false) (greaterp greaterp . t) (lessp . 
false)) (lessp (equal equal) (neq) (geq) (leq leq) (greaterp) (lessp
lessp)))) 725259192934443599)

(c!:install 'rl_bnfsimpl '(rl_bnfsimpl rl_bnfsimpl!* apply) 
573674249001978529)

(c!:install 'crn!:zerop '(crn!:zerop nil) 636778042702425602)

(c!:install 'statep '(statep nil phystype state) 457609737288902307)

(c!:install 'groeb!=newpair '(groeb!=newpair bas_dpoly dp_lmon mo_lcm
groeb!=weight) 1534917572385384796)

(c!:install 'inprint '(inprint times !*nat nil !*asterisk times2 infix
prtch " " plus !*revpri alt not setq tag setprifn prifn pprifn
inbrackets "(" ")" !*nosplit testing!-width!* t (setq !*comma!*) minus
prin2!* maprint oprin prinfit getrtype) 2126947002721244886)

(c!:install '!*multf '(!*multf t nil !*noncomp (expt sqrt) sqrt expt
squashsqrt multd multf ordop addf makeupsf !*multfsqrt
prefix!-rational!-numberp !*multfexpt mkspm) 1504219198463107614)

(c!:install 'modp '(modp) 67078480321714825)

(c!:install 'formbool '(formbool symbolic t boolvalue!* boolfn boolean
boolargs !*protfg "Too many formbools" where bool!-eval intexprlisp
formclis formboollis formc!* lprie formc) 810773239021001069)

(c!:install 'cquotegex '(cquotegex !*guardian gex) 2193093524515590493)

(c!:install 'vdp_setsugar '(vdp_setsugar !*cgbsugar sugar vdp_putprop) 
197103964400692607)

(c!:install 'lambdaom '(lambdaom "<OMBIND>" t
"<OMS cd=""fns1"" name=""lambda""/>" "<OMBVAR>" nil "</OMBVAR>"
"</OMBIND>" printout indent!* objectom) 847063321728976000)


% End of generated Lisp code

