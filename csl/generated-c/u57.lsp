
% u57.lsp           Machine generated Lisp

(c!:install "u57" 180158 5268792 3413595)

(c!:install 'unshift '(unshift !*xo (0.0 . 0.0) gfplus gfadjust) 
18342691400931012398)

(c!:install 'physopplus '(physopplus ((lht . scalar) (rht . scalar) (
lhtype . scalar) (rhtype . scalar)) "type mismatch in plus " physopsim!*
getphystype rederr2 physop2sq addsq mk!*sq) 9445603566272518531)

(c!:install 'bassoc '(bassoc th_match) 16440937476530816831)

(c!:install '!*sq2fourier '(!*sq2fourier ((fourier . scalar)) cos
fourier tag fs!:make!-nullangle) 2238193269687759710)

(c!:install 'all_index_lst '(all_index_lst list listp) 
3654155541323541217)

(c!:install 'sc_create '(sc_create ((base . scalar) (count . integer))
symbolic list2vect!*) 17877286572345807905)

(c!:install 'change!+sq!+to!+int '(change!+sq!+to!+int ((nr . scalar))
"no integer in change!+sq!+to!+int" prepsq simp!* rederr) 
14894946801738484437)

(c!:install 'qqe_simpat '(qqe_simpat) 9761063186935570134)

(c!:install 'operator '(operator mkop) 1409021900333175665)

(c!:install 'cr!:minusp '(cr!:minusp) 1518570810801810726)

(c!:install 'expttermp '(expttermp expt expttermp1) 18192048704841883576
)

(c!:install 'xpndwedge '(xpndwedge partitop mkunarywedge wedgepf2) 
3250510587247370634)

(c!:install 'acmemb '(acmemb aceq) 13271867179498849625)

(c!:install 'noncom1 '(noncom1 !*ncmp noncom) 11419460836052736216)

(c!:install 'rationalizef '(rationalizef ((x . scalar) (y . scalar) (z .
scalar)) expt quotient i (quotient 1 2) sqrt (quotient 1 3) (quotient 1
4) kernels lowertowerp mkmain conjquadratic conjcubic conjquartic) 
15032183740477105480)

(c!:install 'red_extract '(red_extract bas_rep dp_comp bas_nr bas_dpoly
dp_diff bas_make1) 18351211877572852818)

(c!:install 'lowestdeg '(lowestdeg ((x . scalar) (y . scalar) (uu .
scalar) (vv . scalar)) expt "exponents must be integers" simp!* !*q2f
erase_pol_cst !*a2k setkorder reorder rederr) 1291910831618222574)

(c!:install 'radd '(radd ((bool . scalar) (ipart . scalar) (x . scalar))
!*reduced i prepf nrootnn to multd) 12610784647974374150)

(c!:install 'no_of_tm_sf '(no_of_tm_sf) 14650371380341364919)

(c!:install 'add!-to!-sorted!-tree '(add!-to!-sorted!-tree nreverse) 
16019473893027424821)

(c!:install 'giminusp!: '(giminusp!:) 7111611823332749510)

(c!:install 'uterm '(uterm rhs!* ((coef . scalar) (power . scalar))
addinds evaluatecoeffts plusdf) 12099463544731537631)

(c!:install 'get!*nr!*real!*irred!*reps '(get!*nr!*real!*irred!*reps
realrepnumber) 17446448125246442107)

(c!:install 'dip_comp1 '(dip_comp1 dip_evlmon ev_comp) 
15677524538554573974)

(c!:install 'search4facf '(search4facf ((q . scalar) (w . scalar))
tryfactorf) 3716348035737370885)

(c!:install 'subsubf '(subsubf ((x . scalar) (y . scalar)) equal sub
subsublis reversip!* aeval aconc!* subeval mksp mk!*sq) 
6285782985781381473)

(c!:install 'row_dim '(row_dim !*fast_la
"Error in row_dim: input should be a matrix." matrixp rederr
size_of_matrix) 2138413619587443822)

(c!:install 'r2speclist '(r2speclist plus r2speclist1) 
5879233124307570045)

(c!:install 'all_defined '(all_defined map__edges defined_append
all_defined_map_) 6100698165411242067)

(c!:install 'simprd '(simprd !:rd!: dmode!* simplist) 
15671832098548929442)

(c!:install 'gak '(gak aconc) 12594716863303144844)

(c!:install 'anu_mk '(anu_mk anu) 3254050022557752615)

(c!:install 'opfchk!! '(opfchk!! ((fn . scalar) (fn1 . scalar) (sf .
scalar) (sc . scalar) (int . scalar) (ce . scalar)) integer !:rn!:
!*numval dmode!* (!:rd!: !:cr!:) !:rd!: simprn simparg simprd !*complex
list expt !:cr!: alg "is not defined as complex function" apply revlis
simpcr rd!:minusp rerror errorset2 errorp complexp intconv) 
10278056562235779948)

(c!:install 'constant_expr_listp '(constant_expr_listp constant i
constant_exprp) 11204786086360299674)

(c!:install 'talp_nextt '(talp_nextt ((cl . scalar) (cvv . scalar) (vv .
scalar) (fv . scalar) (ifv . scalar)) talp_getl talp_mk!-invs lastpair
talp_list2vec talp_invp talp_nextt1) 7318936077014995885)

(c!:install 'dip_reduceconti '(dip_reduceconti dip_lbc bc_quot
dip_evlmon dip_mred dip_moncomp) 12536364206078477054)

(c!:install 'poly!-remainder '(poly!-remainder remainder poly!-divide!*)
 6768570781226289743)

(c!:install 'xriterion_2 '(xriterion_2 wedge_pair !*trxideal
"criterion 2 hit" last xdiv make_wedge_pair find_item writepri) 
5623418408247858791)

(c!:install 'evalsubset '(evalsubset subset evalsetbool evalsymsubset) 
18227868268543170902)

(c!:install 'preproc '(preproc ((r . scalar)) preproc1) 
14740742247801117819)

(c!:install 'partitindexvar '(partitindexvar ((freel . scalar) (x .
scalar) (y . scalar) (z . scalar) (v . scalar) (sgn . scalar) (w .
scalar)) minus metricu!* covariant indxsymmetries revalind !*num2id
deg!*form getlower simp multpfsq addpf getupper coposp mkupf mksq
indexsymmetrize negsq) 13316095765127046282)

(c!:install 'dvertex!-to!-projector '(dvertex!-to!-projector ((l1 .
scalar) (l2 . scalar) (coeff . scalar) (w . scalar)) mktails repeatsp
prop!-simp mk!-contract!-coeff dpropagator) 9550656546503130542)


% End of generated Lisp code

