% charname.tst

% Author: Arthur Norman.

% Copyright (c) 2014 Arthur Norman.  All rights reserved.

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ;AS IS;
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%

lisp;
on echo;

%
% The strings here should each have 32 "special" characters with blanks
% between them - ie they should be of length 63. When printed using "printc"
% and when the output goes to a Unicode-capable output device the characters
% ought to appear in neat columns.
%
% This tries to display roughly all the named characters that I know about. In very many cases
% the fonts installed on your computer will not support all of them and so
% the display you will get as output from this will not be complete! The file
% is provided here mainly as a record of the range of character entity names
% that might exist.

symbolic procedure print_extra_chars();
 <<
    printc "#Aacute; #aacute; #Abreve; #abreve; #ac; #acd; #Acirc; #acirc; #acute; #Acy; #acy; #AElig; #aelig; #af; #Afr; #afr; #Agrave; #agrave; #alefsym; #aleph; #Alpha; #alpha; #Amacr; #amacr; #amalg; #amp; #AMP; #andand; #And; #and; #andd; #andslope;";
    printc "#andv; #ang; #ange; #angle; #angmsdaa; #angmsdab; #angmsdac; #angmsdad; #angmsdae; #angmsdaf; #angmsdag; #angmsdah; #angmsd; #angrt; #angrtvb; #angrtvbd; #angsph; #angst; #angzarr; #Aogon; #aogon; #Aopf; #aopf; #apacir; #ap; #apE; #ape; #apid; #apos; #ApplyFunction; #approx; #approxeq;";
    printc "#Aring; #aring; #Ascr; #ascr; #Assign; #ast; #asymp; #asympeq; #Atilde; #atilde; #Auml; #auml; #awconint; #awint; #backcong; #backepsilon; #backprime; #backsim; #backsimeq; #Backslash; #Barv; #barvee; #barwed; #Barwed; #barwedge; #bbrk; #bbrktbrk; #bcong; #Bcy; #bcy; #bdquo; #becaus;";
    printc "#because; #Because; #bemptyv; #bepsi; #bernou; #Bernoullis; #Beta; #beta; #beth; #between; #Bfr; #bfr; #bigcap; #bigcirc; #bigcup; #bigodot; #bigoplus; #bigotimes; #bigsqcup; #bigstar; #bigtriangledown; #bigtriangleup; #biguplus; #bigvee; #bigwedge; #bkarow; #blacklozenge; #blacksquare; #blacktriangle; #blacktriangledown; #blacktriangleleft; #blacktriangleright;";
    printc "#blank; #blk12; #blk14; #blk34; #block; #bNot; #bnot; #Bopf; #bopf; #bot; #bottom; #bowtie; #boxbox; #boxdl; #boxdL; #boxDl; #boxDL; #boxdr; #boxdR; #boxDr; #boxDR; #boxh; #boxH; #boxhd; #boxHd; #boxhD; #boxHD; #boxhu; #boxHu; #boxhU; #boxHU; #boxminus;";
    printc "#boxplus; #boxtimes; #boxul; #boxuL; #boxUl; #boxUL; #boxur; #boxuR; #boxUr; #boxUR; #boxv; #boxV; #boxvh; #boxvH; #boxVh; #boxVH; #boxvl; #boxvL; #boxVl; #boxVL; #boxvr; #boxvR; #boxVr; #boxVR; #bprime; #breve; #Breve; #brvbar; #bscr; #Bscr; #bsemi; #bsim;";
    printc "#bsime; #bsolb; #bsol; #bsolhsub; #bull; #bullet; #bump; #bumpE; #bumpe; #Bumpeq; #bumpeq; #Cacute; #cacute; #capand; #capbrcup; #capcap; #cap; #Cap; #capcup; #capdot; #CapitalDifferentialD; #caret; #caron; #Cayleys; #ccaps; #Ccaron; #ccaron; #Ccedil; #ccedil; #Ccirc; #ccirc; #Cconint;";
    printc "#ccups; #ccupssm; #Cdot; #cdot; #cedil; #Cedilla; #cemptyv; #cent; #centerdot; #CenterDot; #cfr; #Cfr; #CHcy; #chcy; #check; #checkmark; #Chi; #chi; #circ; #circeq; #circlearrowleft; #circlearrowright; #circledast; #circledcirc; #circleddash; #CircleDot; #circledR; #circledS; #CircleMinus; #CirclePlus; #CircleTimes; #cir; #cirE;";
    printc "#cire; #cirfnint; #cirmid; #cirscir; #ClockwiseContourIntegral; #CloseCurlyDoubleQuote; #CloseCurlyQuote; #clubs; #clubsuit; #colon; #Colon; #Colone; #colone; #coloneq; #comma; #commat; #comp; #compfn; #complement; #complexes; #cong; #congdot; #Congruent; #conint; #Conint; #ContourIntegral; #copf; #Copf; #coprod; #Coproduct; #copy; #COPY; #copysr;";
    printc "#CounterClockwiseContourIntegral; #crarr; #cross; #Cross; #Cscr; #cscr; #csub; #csube; #csup; #csupe; #ctdot; #cudarrl; #cudarrr; #cuepr; #cuesc; #cularr; #cularrp; #cupbrcap; #cupcap; #CupCap; #cup; #Cup; #cupcup; #cupdot; #cupor; #curarr; #curarrm; #curlyeqprec; #curlyeqsucc; #curlyvee; #curlywedge; #curren;";
    printc "#curvearrowleft; #curvearrowright; #cuvee; #cuwed; #cwconint; #cwint; #cylcty; #dagger; #Dagger; #daleth; #darr; #Darr; #dArr; #dash; #Dashv; #dashv; #dbkarow; #dblac; #Dcaron; #dcaron; #Dcy; #dcy; #ddagger; #ddarr; #DD; #dd; #DDotrahd; #ddotseq; #deg; #Del; #Delta; #delta;";
    printc "#demptyv; #dfisht; #Dfr; #dfr; #dHar; #dharl; #dharr; #DiacriticalAcute; #DiacriticalDot; #DiacriticalDoubleAcute; #DiacriticalGrave; #DiacriticalTilde; #diam; #diamond; #Diamond; #diamondsuit; #diams; #die; #DifferentialD; #digamma; #disin; #div; #divide; #divideontimes; #divonx; #DJcy; #djcy; #dlcorn; #dlcrop; #dollar; #Dopf; #dopf;";
    printc "#Dot; #dot; #DotDot; #doteq; #doteqdot; #DotEqual; #dotminus; #dotplus; #dotsquare; #doublebarwedge; #DoubleContourIntegral; #DoubleDot; #DoubleDownArrow; #DoubleLeftArrow; #DoubleLeftRightArrow; #DoubleLeftTee; #DoubleLongLeftArrow; #DoubleLongLeftRightArrow; #DoubleLongRightArrow; #DoubleRightArrow; #DoubleRightTee; #DoubleUpArrow; #DoubleUpDownArrow; #DoubleVerticalBar; #DownArrowBar; #downarrow; #DownArrow; #Downarrow; #DownArrowUpArrow; #DownBreve; #downdownarrows; #downharpoonleft;";
    printc "#downharpoonright; #DownLeftRightVector; #DownLeftTeeVector; #DownLeftVectorBar; #DownLeftVector; #DownRightTeeVector; #DownRightVectorBar; #DownRightVector; #DownTeeArrow; #DownTee; #drbkarow; #drcorn; #drcrop; #Dscr; #dscr; #DScy; #dscy; #dsol; #Dstrok; #dstrok; #dtdot; #dtri; #dtrif; #duarr; #duhar; #dwangle; #DZcy; #dzcy; #dzigrarr; #Eacute; #eacute; #easter; #Ecaron;";
    printc "#ecaron; #Ecirc; #ecirc; #ecir; #ecolon; #Ecy; #ecy; #eDDot; #Edot; #edot; #eDot; #ee; #efDot; #Efr; #efr; #eg; #Egrave; #egrave; #egs; #egsdot; #el; #Element; #elinters; #ell; #els; #elsdot; #Emacr; #emacr; #empty; #emptyset; #EmptySmallSquare; #emptyv;";
    printc "#EmptyVerySmallSquare; #emsp13; #emsp14; #emsp; #ENG; #eng; #ensp; #Eogon; #eogon; #Eopf; #eopf; #epar; #eparsl; #eplus; #epsi; #Epsilon; #epsilon; #epsiv; #eqcirc; #eqcolon; #eqsim; #eqslantgtr; #eqslantless; #Equal; #equals; #EqualTilde; #equest; #Equilibrium; #equiv; #equivDD; #eqvparsl; #erarr; #erDot; #escr;";
    printc "#Escr; #esdot; #Esim; #esim; #Eta; #eta; #ETH; #eth; #Euml; #euml; #euro; #excl; #exist; #Exists; #expectation; #exponentiale; #ExponentialE; #fallingdotseq; #Fcy; #fcy; #female; #ffilig; #fflig; #ffllig; #Ffr; #ffr; #filig; #FilledSmallSquare; #FilledVerySmallSquare; #flat; #fllig; #fltns;";
    printc "#fnof; #Fopf; #fopf; #forall; #ForAll; #fork; #forkv; #Fouriertrf; #fpartint; #frac12; #frac13; #frac14; #frac15; #frac16; #frac18; #frac23; #frac25; #frac34; #frac35; #frac38; #frac45; #frac56; #frac58; #frac78; #frasl; #frown; #fscr; #Fscr; #gacute; #Gamma; #gamma; #Gammad; #gammad;";
    printc "#gap; #Gbreve; #gbreve; #Gcedil; #Gcirc; #gcirc; #Gcy; #gcy; #Gdot; #gdot; #ge; #gE; #gEl; #gel; #geq; #geqq; #geqslant; #gescc; #ges; #gesdot; #gesdoto; #gesdotol; #gesles; #Gfr; #gfr; #gg; #Gg; #ggg; #gimel; #GJcy; #gjcy; #gla;";
    printc "#gl; #glE; #glj; #gnap; #gnapprox; #gne; #gnE; #gneq; #gneqq; #gnsim; #Gopf; #gopf; #grave; #GreaterEqual; #GreaterEqualLess; #GreaterFullEqual; #GreaterGreater; #GreaterLess; #GreaterSlantEqual; #GreaterTilde; #Gscr; #gscr; #gsim; #gsime; #gsiml; #gtcc; #gtcir; #gt; #GT; #Gt; #gtdot; #gtlPar; #gtquest;";
    printc "#gtrapprox; #gtrarr; #gtrdot; #gtreqless; #gtreqqless; #gtrless; #gtrsim; #Hacek; #hairsp; #half; #hamilt; #HARDcy; #hardcy; #harrcir; #harr; #hArr; #harrw; #hash; #Hat; #hbar; #Hcirc; #hcirc; #hearts; #heartsuit; #hellip; #hercon; #hfr; #Hfr; #HilbertSpace; #hksearow; #hkswarow; #hoarr;";
    printc "#homtht; #hookleftarrow; #hookrightarrow; #hopf; #Hopf; #horbar; #HorizontalLine; #hscr; #Hscr; #hslash; #Hstrok; #hstrok; #HumpDownHump; #HumpEqual; #hybull; #hyphen; #Iacute; #iacute; #ic; #Icirc; #icirc; #Icy; #icy; #Idot; #IEcy; #iecy; #iexcl; #iff; #ifr; #Ifr; #Igrave; #igrave;";
    printc "#ii; #iiiint; #iiint; #iinfin; #iiota; #IJlig; #ijlig; #Imacr; #imacr; #image; #ImaginaryI; #imagline; #imagpart; #imath; #Im; #imof; #imped; #Implies; #incare; #in; #infin; #infintie; #inodot; #intcal; #int; #Int; #integers; #Integral; #intercal; #Intersection; #intlarhk; #intprod;";
    printc "#InvisibleComma; #InvisibleTimes; #IOcy; #iocy; #Iogon; #iogon; #Iopf; #iopf; #Iota; #iota; #iprod; #iquest; #iscr; #Iscr; #isin; #isindot; #isinE; #isins; #isinsv; #isinv; #it; #Itilde; #itilde; #Iukcy; #iukcy; #Iuml; #iuml; #Jcirc; #jcirc; #Jcy; #jcy; #Jfr;";
    printc "#jfr; #jmath; #Jopf; #jopf; #Jscr; #jscr; #Jsercy; #jsercy; #Jukcy; #jukcy; #Kappa; #kappa; #kappav; #Kcedil; #kcedil; #Kcy; #kcy; #Kfr; #kfr; #kgreen; #KHcy; #khcy; #KJcy; #kjcy; #Kopf; #kopf; #Kscr; #kscr; #lAarr; #Lacute; #lacute; #laemptyv;";
    printc "#lagran; #Lambda; #lambda; #lang; #Lang; #langd; #langle; #lap; #Laplacetrf; #laquo; #larrb; #larrbfs; #larr; #Larr; #lArr; #larrfs; #larrhk; #larrlp; #larrpl; #larrsim; #larrtl; #latail; #lAtail; #lat; #late; #lbarr; #lBarr; #lbbrk; #lbrace; #lbrack; #lbrke; #lbrksld;";
    printc "#lbrkslu; #Lcaron; #lcaron; #Lcedil; #lcedil; #lceil; #lcub; #Lcy; #lcy; #ldca; #ldquo; #ldquor; #ldrdhar; #ldrushar; #ldsh; #le; #lE; #LeftAngleBracket; #LeftArrowBar; #leftarrow; #LeftArrow; #Leftarrow; #LeftArrowRightArrow; #leftarrowtail; #LeftCeiling; #LeftDoubleBracket; #LeftDownTeeVector; #LeftDownVectorBar; #LeftDownVector; #LeftFloor; #leftharpoondown; #leftharpoonup;";
    printc "#leftleftarrows; #leftrightarrow; #LeftRightArrow; #Leftrightarrow; #leftrightarrows; #leftrightharpoons; #leftrightsquigarrow; #LeftRightVector; #LeftTeeArrow; #LeftTee; #LeftTeeVector; #leftthreetimes; #LeftTriangleBar; #LeftTriangle; #LeftTriangleEqual; #LeftUpDownVector; #LeftUpTeeVector; #LeftUpVectorBar; #LeftUpVector; #LeftVectorBar; #LeftVector; #lEg; #leg; #leq; #leqq; #leqslant; #lescc; #les; #lesdot; #lesdoto; #lesdotor; #lesges;";
    printc "#lessapprox; #lessdot; #lesseqgtr; #lesseqqgtr; #LessEqualGreater; #LessFullEqual; #LessGreater; #lessgtr; #LessLess; #lesssim; #LessSlantEqual; #LessTilde; #lfisht; #lfloor; #Lfr; #lfr; #lg; #lgE; #lHar; #lhard; #lharu; #lharul; #lhblk; #LJcy; #ljcy; #llarr; #ll; #Ll; #llcorner; #Lleftarrow; #llhard; #lltri; #Lmidot;";
    printc "#lmidot; #lmoustache; #lmoust; #lnap; #lnapprox; #lne; #lnE; #lneq; #lneqq; #lnsim; #loang; #loarr; #lobrk; #longleftarrow; #LongLeftArrow; #Longleftarrow; #longleftrightarrow; #LongLeftRightArrow; #Longleftrightarrow; #longmapsto; #longrightarrow; #LongRightArrow; #Longrightarrow; #looparrowleft; #looparrowright; #lopar; #Lopf; #lopf; #loplus; #lotimes; #lowast; #lowbar;";
    printc "#LowerLeftArrow; #LowerRightArrow; #loz; #lozenge; #lozf; #lpar; #lparlt; #lrarr; #lrcorner; #lrhar; #lrhard; #lrm; #lrtri; #lsaquo; #lscr; #Lscr; #lsh; #Lsh; #lsim; #lsime; #lsimg; #lsqb; #lsquo; #lsquor; #Lstrok; #lstrok; #ltcc; #ltcir; #lt; #LT; #Lt; #ltdot;";
    printc "#lthree; #ltimes; #ltlarr; #ltquest; #ltri; #ltrie; #ltrif; #ltrPar; #lurdshar; #luruhar; #macr; #male; #malt; #maltese; #Map; #map; #mapsto; #mapstodown; #mapstoleft; #mapstoup; #marker; #mcomma; #Mcy; #mcy; #mdash; #mDDot; #measuredangle; #MediumSpace; #Mellintrf; #Mfr; #mfr; #mho; #micro;";
    printc "#midast; #midcir; #mid; #middot; #minusb; #minus; #minusd; #minusdu; #MinusPlus; #mlcp; #mldr; #mnplus; #models; #Mopf; #mopf; #mp; #mscr; #Mscr; #mstpos; #Mu; #mu; #multimap; #mumap; #nabla; #Nacute; #nacute; #nap; #napos; #napprox; #natural; #naturals; #natur; #nbsp;";
    printc "#ncap; #Ncaron; #ncaron; #Ncedil; #ncedil; #ncong; #ncup; #Ncy; #ncy; #ndash; #nearhk; #nearr; #neArr; #nearrow; #ne; #NegativeMediumSpace; #NegativeThickSpace; #NegativeThinSpace; #NegativeVeryThinSpace; #nequiv; #nesim; #NestedGreaterGreater; #NestedLessLess; #NewLine; #nexist; #nexists; #Nfr; #ngE; #nge; #ngeq; #ngsim; #ngt; #ngtr;";
    printc "#nharr; #nhArr; #nhpar; #ni; #nis; #nisd; #niv; #NJcy; #njcy; #nlarr; #nlArr; #nlE; #nle; #nleftarrow; #nLeftarrow; #nleftrightarrow; #nLeftrightarrow; #nleq; #nless; #nlsim; #nlt; #nltri; #nltrie; #nmid; #NoBreak; #NonBreakingSpace; #nopf; #Nopf; #Not; #not; #NotCongruent; #NotCupCap;";
    printc "#NotDoubleVerticalBar; #NotElement; #NotEqual; #NotExists; #NotGreater; #NotGreaterEqual; #NotGreaterLess; #NotGreaterTilde; #notin; #notinva; #notinvb; #notinvc; #NotLeftTriangle; #NotLeftTriangleEqual; #NotLess; #NotLessEqual; #NotLessGreater; #NotLessTilde; #notni; #notniva; #notnivb; #notnivc; #NotPrecedes; #NotPrecedesSlantEqual; #NotReverseElement; #NotRightTriangle; #NotRightTriangleEqual; #NotSquareSubsetEqual; #NotSquareSupersetEqual; #NotSubsetEqual; #NotSucceeds; #NotSucceedsSlantEqual; #NotSupersetEqual;";
    printc "#NotTilde; #NotTildeEqual; #NotTildeFullEqual; #NotTildeTilde; #NotVerticalBar; #nparallel; #npar; #npolint; #npr; #nprcue; #nprec; #nrarr; #nrArr; #nrightarrow; #nRightarrow; #nrtri; #nrtrie; #nsc; #nsccue; #Nscr; #nscr; #nshortmid; #nshortparallel; #nsim; #nsime; #nsimeq; #nsmid; #nspar; #nsqsube; #nsqsupe; #nsub; #nsube;";
    printc "#nsubseteq; #nsucc; #nsup; #nsupe; #nsupseteq; #ntgl; #Ntilde; #ntilde; #ntlg; #ntriangleleft; #ntrianglelefteq; #ntriangleright; #ntrianglerighteq; #Nu; #nu; #num; #numero; #numsp; #nvdash; #nvDash; #nVdash; #nVDash; #nvHarr; #nvinfin; #nvlArr; #nvrArr; #nwarhk; #nwarr; #nwArr; #nwarrow; #nwnear; #Oacute;";
    printc "#oacute; #oast; #Ocirc; #ocirc; #ocir; #Ocy; #ocy; #odash; #Odblac; #odblac; #odiv; #odot; #odsold; #OElig; #oelig; #ofcir; #Ofr; #ofr; #ogon; #Ograve; #ograve; #ogt; #ohbar; #ohm; #oint; #olarr; #olcir; #olcross; #oline; #olt; #Omacr; #omacr;";
    printc "#Omega; #omega; #Omicron; #omicron; #omid; #ominus; #Oopf; #oopf; #opar; #OpenCurlyDoubleQuote; #OpenCurlyQuote; #operp; #oplus; #orarr; #Or; #or; #ord; #order; #orderof; #ordf; #ordm; #origof; #oror; #orslope; #orv; #oS; #Oscr; #oscr; #Oslash; #oslash; #osol; #Otilde; #otilde;";
    printc "#otimesas; #Otimes; #otimes; #Ouml; #ouml; #ovbar; #OverBar; #OverBrace; #OverBracket; #OverParenthesis; #para; #parallel; #par; #parsim; #parsl; #part; #PartialD; #Pcy; #pcy; #percnt; #period; #permil; #perp; #pertenk; #Pfr; #pfr; #Phi; #phi; #phiv; #phmmat; #phone; #Pi;";
    printc "#pi; #pitchfork; #piv; #planck; #planckh; #plankv; #plusacir; #plusb; #pluscir; #plus; #plusdo; #plusdu; #pluse; #PlusMinus; #plusmn; #plussim; #plustwo; #pm; #Poincareplane; #pointint; #popf; #Popf; #pound; #prap; #Pr; #pr; #prcue; #precapprox; #prec; #preccurlyeq; #Precedes; #PrecedesEqual;";
    printc "#PrecedesSlantEqual; #PrecedesTilde; #preceq; #precnapprox; #precneqq; #precnsim; #pre; #prE; #precsim; #prime; #Prime; #primes; #prnap; #prnE; #prnsim; #prod; #Product; #profalar; #profline; #profsurf; #prop; #Proportional; #Proportion; #propto; #prsim; #prurel; #Pscr; #pscr; #Psi; #psi; #puncsp; #Qfr;";
    printc "#qfr; #qint; #qopf; #Qopf; #qprime; #Qscr; #qscr; #quaternions; #quatint; #quest; #questeq; #quot; #QUOT; #rAarr; #Racute; #racute; #radic; #raemptyv; #rang; #Rang; #rangd; #range; #rangle; #raquo; #rarrap; #rarrb; #rarrbfs; #rarrc; #rarr; #Rarr; #rArr; #rarrfs;";
    printc "#rarrhk; #rarrlp; #rarrpl; #rarrsim; #Rarrtl; #rarrtl; #rarrw; #ratail; #rAtail; #ratio; #rationals; #rbarr; #rBarr; #RBarr; #rbbrk; #rbrace; #rbrack; #rbrke; #rbrksld; #rbrkslu; #Rcaron; #rcaron; #Rcedil; #rcedil; #rceil; #rcub; #Rcy; #rcy; #rdca; #rdldhar; #rdquo; #rdquor;";
    printc "#rdsh; #real; #realine; #realpart; #reals; #Re; #rect; #reg; #REG; #ReverseElement; #ReverseEquilibrium; #ReverseUpEquilibrium; #rfisht; #rfloor; #rfr; #Rfr; #rHar; #rhard; #rharu; #rharul; #Rho; #rho; #rhov; #RightAngleBracket; #RightArrowBar; #rightarrow; #RightArrow; #Rightarrow; #RightArrowLeftArrow; #rightarrowtail; #RightCeiling; #RightDoubleBracket;";
    printc "#RightDownTeeVector; #RightDownVectorBar; #RightDownVector; #RightFloor; #rightharpoondown; #rightharpoonup; #rightleftarrows; #rightleftharpoons; #rightrightarrows; #rightsquigarrow; #RightTeeArrow; #RightTee; #RightTeeVector; #rightthreetimes; #RightTriangleBar; #RightTriangle; #RightTriangleEqual; #RightUpDownVector; #RightUpTeeVector; #RightUpVectorBar; #RightUpVector; #RightVectorBar; #RightVector; #ring; #risingdotseq; #rlarr; #rlhar; #rlm; #rmoustache; #rmoust; #rnmid; #roang;";
    printc "#roarr; #robrk; #ropar; #ropf; #Ropf; #roplus; #rotimes; #RoundImplies; #rpar; #rpargt; #rppolint; #rrarr; #Rrightarrow; #rsaquo; #rscr; #Rscr; #rsh; #Rsh; #rsqb; #rsquo; #rsquor; #rthree; #rtimes; #rtri; #rtrie; #rtrif; #rtriltri; #RuleDelayed; #ruluhar; #rx; #Sacute; #sacute;";
    printc "#sbquo; #scap; #Scaron; #scaron; #Sc; #sc; #sccue; #sce; #scE; #Scedil; #scedil; #Scirc; #scirc; #scnap; #scnE; #scnsim; #scpolint; #scsim; #Scy; #scy; #sdotb; #sdot; #sdote; #searhk; #searr; #seArr; #searrow; #sect; #semi; #seswar; #setminus; #setmn; #sext;";
    printc "#Sfr; #sfr; #sfrown; #sharp; #SHCHcy; #shchcy; #SHcy; #shcy; #ShortDownArrow; #ShortLeftArrow; #shortmid; #shortparallel; #ShortRightArrow; #ShortUpArrow; #shy; #Sigma; #sigma; #sigmaf; #sigmav; #sim; #simdot; #sime; #simeq; #simg; #simgE; #siml; #simlE; #simne; #simplus; #simrarr; #slarr; #SmallCircle;";
    printc "#smallsetminus; #smashp; #smeparsl; #smid; #smile; #smt; #smte; #SOFTcy; #softcy; #solbar; #solb; #sol; #Sopf; #sopf; #spades; #spadesuit; #spar; #sqcap; #sqcup; #Sqrt; #sqsub; #sqsube; #sqsubset; #sqsubseteq; #sqsup; #sqsupe; #sqsupset; #sqsupseteq; #square; #Square; #SquareIntersection; #SquareSubset;";
    printc "#SquareSubsetEqual; #SquareSuperset; #SquareSupersetEqual; #SquareUnion; #squarf; #squ; #squf; #srarr; #Sscr; #sscr; #ssetmn; #ssmile; #sstarf; #Star; #star; #starf; #straightepsilon; #straightphi; #strns; #sub; #Sub; #subdot; #subE; #sube; #subedot; #submult; #subnE; #subne; #subplus; #subrarr; #subset; #Subset;";
    printc "#subseteq; #subseteqq; #SubsetEqual; #subsetneq; #subsetneqq; #subsim; #subsub; #subsup; #succapprox; #succ; #succcurlyeq; #Succeeds; #SucceedsEqual; #SucceedsSlantEqual; #SucceedsTilde; #succeq; #succnapprox; #succneqq; #succnsim; #succsim; #SuchThat; #sum; #Sum; #sung; #sup1; #sup2; #sup3; #sup; #Sup; #supdot; #supdsub; #supE;";
    printc "#supe; #supedot; #Superset; #SupersetEqual; #suphsol; #suphsub; #suplarr; #supmult; #supnE; #supne; #supplus; #supset; #Supset; #supseteq; #supseteqq; #supsetneq; #supsetneqq; #supsim; #supsub; #supsup; #swarhk; #swarr; #swArr; #swarrow; #swnwar; #szlig; #Tab; #target; #Tau; #tau; #tbrk; #Tcaron;";
    printc "#tcaron; #Tcedil; #tcedil; #Tcy; #tcy; #tdot; #telrec; #Tfr; #tfr; #there4; #therefore; #Therefore; #Theta; #theta; #thetasym; #thetav; #thickapprox; #thicksim; #ThinSpace; #thinsp; #thkap; #thksim; #THORN; #thorn; #tilde; #Tilde; #TildeEqual; #TildeFullEqual; #TildeTilde; #timesbar; #timesb; #times;";
    printc "#timesd; #tint; #toea; #topbot; #topcir; #top; #Topf; #topf; #topfork; #tosa; #tprime; #trade; #TRADE; #triangle; #triangledown; #triangleleft; #trianglelefteq; #triangleq; #triangleright; #trianglerighteq; #tridot; #trie; #triminus; #TripleDot; #triplus; #trisb; #tritime; #trpezium; #Tscr; #tscr; #TScy; #tscy;";
    printc "#TSHcy; #tshcy; #Tstrok; #tstrok; #twixt; #twoheadleftarrow; #twoheadrightarrow; #Uacute; #uacute; #uarr; #Uarr; #uArr; #Uarrocir; #Ubrcy; #ubrcy; #Ubreve; #ubreve; #Ucirc; #ucirc; #Ucy; #ucy; #udarr; #Udblac; #udblac; #udhar; #ufisht; #Ufr; #ufr; #Ugrave; #ugrave; #uHar; #uharl;";
    printc "#uharr; #uhblk; #ulcorn; #ulcorner; #ulcrop; #ultri; #Umacr; #umacr; #uml; #UnderBar; #UnderBrace; #UnderBracket; #UnderParenthesis; #Union; #UnionPlus; #Uogon; #uogon; #Uopf; #uopf; #UpArrowBar; #uparrow; #UpArrow; #Uparrow; #UpArrowDownArrow; #updownarrow; #UpDownArrow; #Updownarrow; #UpEquilibrium; #upharpoonleft; #upharpoonright; #uplus; #UpperLeftArrow;";
    printc "#UpperRightArrow; #upsi; #Upsi; #upsih; #Upsilon; #upsilon; #UpTeeArrow; #UpTee; #upuparrows; #urcorn; #urcorner; #urcrop; #Uring; #uring; #urtri; #Uscr; #uscr; #utdot; #Utilde; #utilde; #utri; #utrif; #uuarr; #Uuml; #uuml; #uwangle; #vangrt; #varepsilon; #varkappa; #varnothing; #varphi; #varpi;";
    printc "#varpropto; #varr; #vArr; #varrho; #varsigma; #vartheta; #vartriangleleft; #vartriangleright; #vBar; #Vbar; #vBarv; #Vcy; #vcy; #vdash; #vDash; #Vdash; #VDash; #Vdashl; #veebar; #vee; #Vee; #veeeq; #vellip; #verbar; #Verbar; #vert; #Vert; #VerticalBar; #VerticalLine; #VerticalSeparator; #VerticalTilde; #VeryThinSpace;";
    printc "#Vfr; #vfr; #vltri; #Vopf; #vopf; #vprop; #vrtri; #Vscr; #vscr; #Vvdash; #vzigzag; #Wcirc; #wcirc; #wedbar; #wedge; #Wedge; #wedgeq; #weierp; #Wfr; #wfr; #Wopf; #wopf; #wp; #wr; #wreath; #Wscr; #wscr; #xcap; #xcirc; #xcup; #xdtri; #Xfr;";
    printc "#xfr; #xharr; #xhArr; #Xi; #xi; #xlarr; #xlArr; #xmap; #xnis; #xodot; #Xopf; #xopf; #xoplus; #xotime; #xrarr; #xrArr; #Xscr; #xscr; #xsqcup; #xuplus; #xutri; #xvee; #xwedge; #Yacute; #yacute; #YAcy; #yacy; #Ycirc; #ycirc; #Ycy; #ycy; #yen;";
    printc "#Yfr; #yfr; #YIcy; #yicy; #Yopf; #yopf; #Yscr; #yscr; #YUcy; #yucy; #yuml; #Yuml; #Zacute; #zacute; #Zcaron; #zcaron; #Zcy; #zcy; #Zdot; #zdot; #zeetrf; #ZeroWidthSpace; #Zeta; #zeta; #zfr; #Zfr; #ZHcy; #zhcy; #zigrarr; #zopf; #Zopf; #Zscr;";
    printc "#zscr; #zwj; #zwnj;";
    nil >>;

print_extra_chars();

end;
