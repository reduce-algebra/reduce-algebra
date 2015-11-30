%  Description: This file contains the tables guiding the program
%
%  Version 26 March 2000
%
%  Author: Luis Alvarez Sobreviela
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
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



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Declaration of a series of table lists which contain the function to be executed  %
% when a certain token is encountered.                                                    %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

constants!*:=
'(!&true!; !&false!; !&imaginaryi!; !&ii!; !&exponentiale!; !&ee!; !&pi!; !&infin!; !&gamma!; !&differentiald!;
!&dd!;);

% The relations!* list contains the correspondance between
% tokens to be found between <reln></reln> tags and the
% reduce function to be executed as well as the argument
% the reduce function should take.
% The <reln> tag is deprecated in MathML2.0 but we have
% kept it for backwards compatibilty.

relations!*:=
'((tendsto . (binaryrd tendsto))
(tendsto!/ . (binaryrd tendsto))
(eq!/ . (naryrd eq))
(neq!/ . (binaryrd neq))
(lt!/ . (naryrd lt))
(gt!/ . (naryrd gt))
(geq!/ . (naryrd geq))
(leq!/ . (naryrd leq))
(in!/ . (binaryrd in))
(notin!/ . (binaryrd notin))
(subset!/ . (subsetrd subset))
(prsubset!/ . (prsubsetrd prsubset))
(notprsubset!/ . (binaryrd notprsubset))
(notsubset!/ . (binaryrd notsubset)));


% The functions!* list contains the correspondance between
% tokens to be found between <apply></apply> tags and the
% reduce function to be executed as well as the argument
% the reduce function should take.

functions!*:=
'((divide!/ . (binaryrd divide))
(scalarproduct!/ . (binaryrd scalarproduct))
(vectorproduct!/ . (binaryrd vectorproduct))
(outerproduct!/ . (binaryrd outerproduct))
(divergence!/ . (unaryrd divergence))
(curl!/ . (unaryrd curl))
(laplacian!/ . (unaryrd laplacian))
(grad!/ . (unaryrd grad))
(size!/ . (unaryrd size))
(setdiff!/ . (setfuncsbinrd setdiff))
(select!/ . (selectrd selector))
(selector!/ . (selectrd selector))
(transpose!/ . (transposerd transpose))
(determinant!/ . (determinantrd determinant))
(fn . (applyfnrd fn))
(union!/ . (setfuncsnaryrd union))
(intersect!/ . (setfuncsnaryrd intersect))
(implies!/ . (binaryrd implies))
(not!/ . (unaryrd not))
(xor!/ . (naryrd xor))
(or!/ . (naryrd or))
(and!/ . (naryrd and))
(mean!/ . (naryrd mean))
(mode!/ . (naryrd mode))
(var!/ . (naryrd variance))
(variance!/ . (naryrd var))
(sdev!/ . (naryrd sdev))
(moment!/ . (momentrd moment))
(median!/ . (naryrd median))
(sin!/ . (unaryrd sin))
(sec!/ . (unaryrd sec))
(sinh!/ . (unaryrd sinh))
(sech!/ . (unaryrd sech))
(arcsin!/ . (unaryrd arcsin))
(cos!/ . (unaryrd cos))
(csc!/ . (unaryrd csc))
(cosh!/ . (unaryrd cosh))
(csch!/ . (unaryrd csch))
(arccos!/ . (unaryrd arccos))
(tan!/ . (unaryrd tan))
(cot!/ . (unaryrd cot))
(tanh!/ . (unaryrd tanh))
(coth!/ . (unaryrd coth))
(arctan!/ . (unaryrd arctan))
(abs!/ . (unaryrd abs))
(ln!/ . (unaryrd ln))
(plus!/ . (naryrd plus))
(times!/ . (naryrd times))
(power!/ . (binaryrd power))
(exp!/ . (unaryrd exp))
(factorial!/ . (unaryrd factorial))
(quotient!/ . (binaryrd quotient))
(max!/ . (minmaxrd max))
(min!/ . (minmaxrd min))
(minus!/ . (minusrd minus))
(rem!/ . (binaryrd rem))
(conjugate!/ . (unaryrd conjugate))
(root!/ . (rootrd root))
(gcd!/ . (naryrd gcd))
(log!/ . (logrd log))
(int!/ . (symbolsrd int))
(sum!/ . (symbolsrd sum))
(limit!/ . (limitrd limit))
(condition . (conditionrd condition))
(product!/ . (symbolsrd product))
(diff!/ . (diffrd diff))
(partialdiff!/ . (partialdiffrd partialdiff))
(inverse!/ . (unaryrd inverse))
(tendsto . (binaryrd tendsto))
(tendsto!/ . (binaryrd tendsto))
(eq!/ . (naryrd eq))
(neq!/ . (binaryrd neq))
(lt!/ . (naryrd lt))
(gt!/ . (naryrd gt))
(geq!/ . (naryrd geq))
(leq!/ . (naryrd leq))
(in!/ . (setfuncsbinrd in))
(notin!/ . (setfuncsbinrd notin))
(subset!/ . (subsetrd subset))
(prsubset!/ . (prsubsetrd prsubset))
(notprsubset!/ . (setfuncabinrd notprsubset))
(notsubset!/ . (setfuncsbinrd notsubset))
(forall!/ . (quantifierrd forall))
(exists!/ . (quantifierrd exists))
(equivalent!/ . (binaryrd equivalent))
(approx!/ . (binaryrd approx))
(imaginary!/ . (unaryrd imaginary))
(real!/ . (unaryrd real))
(arg!/ . (unaryrd arg))
(compose!/ . (naryrd compose))
(csymbol . (csymbolrd csymbol)));

% The constructors!* list sets a correspondance between MathML
% constructor tags, the reduce function to be executed and the
% closing tag which must be looked for in order to make sure
% syntax is correct

constructors!* :=
'((reln . (relnrd !/reln "</reln>"))
(set . ( setrd !/set "</set>"))
(fn . ( fnrd !/fn "</fn>"))
(declare . ( declarerd !/declare "</declare>"))
(interval . ( intervalrd !/interval "</interval>"))
(list . ( listrd !/list "</list>"))
(matrix . ( matrixrd !/matrix "</matrix>"))
(apply . ( applyrd !/apply "</apply>"))
(cn . ( cnrd !/cn "</cn>"))
(ci . ( cird !/ci "</ci>"))
(lambda . ( lambdard !/lambda "</lambda>")));

% The mml!* list determines the correspondance between elements
% in the intermediate representation and the reduce functions to be
% executed.

% The ir2mml!* table determines what function to execute for each
% element of the intermediate representation.
% Its syntax is the following:
%
% (ir_element . (reduce_function function_argument))
%
% The function argument is the equvalent MathML tag usually

ir2mml!* :=
'((determinant . (nary determinant naryom))
(semantic . (semanticml nil semanticom))
(string . (nil nil strom))
(based_integer . (numml based_integer naryom))
(complex_cartesian . (numml complex_cartesian naryom))
(complex_polar . (numml complex_polar naryom))
(ci . (ciml nil ciom))
(cn . (cnml nil cnom))
(vectorml . (vectorml nil containerom))
(scalarproduct . (nary scalarproduct naryom))
(vectorproduct . (nary vectorproduct naryom))
(outerproduct . (nary outerproduct naryom))
(lambda . (containerml lambda lambdaom))
(declare . (declareml nil))
(divergence . (nary divergence naryom))
(laplacian . (nary laplacian naryom))
(curl . (nary curl naryom))
(grad . (nary grad naryom))
(size . (nary size naryom))
(moment . (degreetoksml moment naryom))
(transpose . (nary transpose naryom))
(sum . (nary sum symbolsom))
(product . (nary product symbolsom))
(limit . (nary limit limitom))
(tendsto . (tendstoml nil))
(df . (dfml nil))
(diff . (nary diff symbolsom))
(partialdiff . (nary partialdiff partialdiffom))
(conjugate . (nary conjugate naryom))
(inverse . (nary inverse naryom))
(abs . (nary abs naryom))
(gcd . (nary gcd naryom))
(set . (containerml set containerom))
(factorial . (nary factorial naryom))
(max . (nary max naryom))
(min . (nary min naryom))
(and . (nary and naryom))
(or . (nary or naryom))
(xor . (nary xor naryom))
(selector . (nary selector selectom))
(cos . (nary cos naryom))
(sin . (nary sin naryom))
(sec . (nary sec naryom))
(cosh . (nary cosh naryom))
(cot . (nary cot naryom))
(coth . (nary coth naryom))
(csch . (nary csch naryom))
(arccos . (nary arccos naryom))
(arcsin . (nary arcsin naryom))
(arctan . (nary arctan naryom))
(sech . (nary sech naryom))
(sinh . (nary sinh naryom))
(tan . (nary tan naryom))
(tanh . (nary tanh naryom))
(csc . (nary csc naryom))
(arg . (nary arg naryom))
(real . (nary real naryom))
(exp . (nary exp naryom))
(not . (nary not naryom))
(rem . (nary rem naryom))
(imaginary . (nary imaginary naryom))
(quotient . (quotientml quotient naryom))
(divide . (quotientml divide naryom))
(equivalent . (nary equivalent naryom))
(approx . (nary approx naryom))
(implies . (nary implies naryom))
(plus . (nary plus naryom))
(times . (nary times naryom))
(power . (nary power naryom))
(median . (nary median naryom))
(mean . (nary mean naryom))
(sdev . (nary sdev naryom))
(variance . (nary variance naryom))
(mode . (nary mode naryom))
(compose . (nary compose naryom))
(root . (degreetoksml root naryom))
(log . (log_baseml log naryom))
(logb . (log_baseml logb))
(log10 . (log_baseml log10))
(ln . (nary ln naryom))
(eq . (reln eq naryom))
(neq . (reln neq naryom))
(gt . (reln gt naryom))
(lt . (reln lt naryom))
(geq . (reln geq naryom))
(leq . (reln leq naryom))
(union . (sets union naryom))
(intersect . (sets intersect naryom))
(in . (reln in naryom))
(notin . (reln notin naryom))
(subset . (reln subset naryom))
(prsubset . (reln prsubset naryom))
(notsubset . (reln notsubset naryom))
(notprsubset . (reln notprsubset naryom))
(setdiff . (sets setdiff naryom))
(rational . (rationalml nil naryom))
(matrix . (matrixml nil matrixom))
(minus . (minusml nil naryom))
(int . (nary int symbolsom))
(equal . (equalml nil naryom))
(bvar . (bvarml nil))
(degree . (degreeml nil))
(interval . (containerml interval intervalom))
(integer_interval . (containerml interval intervalom))
(condition . (conditionml nil))
(lowupperlimit . (lowupperlimitml nil intervalom))
(lowlimit . (lowlimitml nil))
(fn . (csymbol_fn nil))
%Ident has no OpenMath equivalent
(ident . (identml nil))
(forall . (nary forall quantom))
(exists . (nary exists quantom))
(list . (containerml list containerom)));


% This table contains all the OpenMath elements which are understood by the
% translator and which have a MathML equivalent. The symbol and originating CDs
% are contained in this table.

valid_om!*:=
'((divide . (arith1))
(integer (omtypes))
(float (omtypes))
(selector .(linalg3))
(complex_cartesian . (nums1))
(complex_polar . (nums1))
(based_integer . (nums1))
(equivalent . (logic2))
(approx . (relation2))
(determinant . (linalg3))
(transpose . (linalg3))
(inverse . (fns1 arith2))
(in . (set1 multiset1))
(subset . (set1 multiset1))
(prsubset . (set1 multiset1))
(notsubset . (set1 multiset1))
(notprsubset . (set1 multiset1))
(set . (set1 multiset1))
(setdiff . (set1 multiset1))
(union . (set1 multiset1))
(notin . (set1 multiset1))
(intersect . (set1 multiset1))
(implies . (logic1))
(not . (logic1))
(xor . (logic1))
(vectorproduct . (linalg1))
(vector . (linalg1 linalg2))
(or . (logic1))
(forall . (quant1))
(and . (logic1))
(mean . (stats1))
(mode . (stats1))
(variance . (stats1))
(sdev . (stats1))
(moment . (stats1))
(median . (stats1))
(sin . (transc1))
(sinh . (transc1))
(arcsin . (transc1))
(arcsinh . (transc1 transc2))
(sec . (transc1))
(sech . (transc1))
(arcsec . (transc1 transc2))
(arcsech . (transc1 transc2))
(cos . (transc1))
(arccos . (transc1))
(cosh . (transc1))
(arccosh . (transc1 arctrans2))
(csc . (transc1))
(csch . (transc1))
(arccsc . (transc1 transc2))
(arccsch . (transc1 transc2))
(tan . (transc1))
(tanh . (transc1))
(arctan . (transc1))
(arctanh . (transc1 transc2))
(cot . (transc1))
(coth . (transc1))
(arccot . (transc1 transc2))
(arccoth . (transc1 transc2))
(ln . (transc1))
(exp . (transc1))
(abs . (arith1))
(plus . (arith1))
(times . (arith1 arith2))
(power . (arith1))
(factorial . (integer1))
(minus . (arith1))
(rem . (integer1))
(conjugate . (arith1))
(root . (arith1))
(log . (transc1))
(int . (calculus1))
(gcd . (integer1))
(quotient . (integer1))
(sum . (arith1))
(product . (arith1))
(scalarproduct . (linalg1))
(outerproduct . (linalg1))
(diff . (calculus1))
(partialdiff . (calculus1))
(eq . (relation1))
(neq . (relation1))
(leq . (relation1))
(geq . (relation1))
(lt . (relation1))
(gt . (relation1))
(quotient . (integer1))
(interval . (interval1))
(integer_interval . (interval1))
(min . (minmax1))
(max . (minmax1))
(imaginary . (nums1))
(real . (nums1))
(forall . (quant1))
(exists . (quant1))
(lambda . (fns1))
(list . (list1))
(arg . (arith2))
(type . (typmml))
(rational . (nums1))
(curl . (veccalc1))
(divergence . (veccalc1))
(grad . (veccalc1))
(size . (linalg3))
(laplacian . (veccalc1)));


% The following table keeps information about OpenMath elements which have
% a MathML equivalent, but with another name. It also makes sure that
% the MathML translation has the correct attributes when attributes
% are needed to have a correct semantic translation.
%
% The format of the table is:
% (OpenMath_symbol_name . (one_or_more_CDs  MathML_equivalent  MathML_attribute))

special_cases!*:=
'((unary_minus . (arith1 minus nil))
(both_sides . (limit1 nil nil))
(above . (limit1 tendsto above))
(below . (limit1 tendsto below))
(null . (limit1 nil nil))
(multiset . (multiset1 set (type multiset)))
(complex_cartesian_type . (typmml complex_cartesian nil))
(complex_polar_type . (typmml complex_polar nil))
(constant_type . (typmml constant nil))
(fn_type . (typmml csymbol nil))
(integer_type . (typmml integer nil))
(list_type . (typmml list nil))
(matrix_type . (typmml matrix nil))
(rational_type . (typmml rational nil))
(real_type . (typmml real nil))
(set_type . (typmml set nil))
(vector_type . (typmml vectorml nil))
(integer_interval . (interval1 interval nil))
(interval_oo . (interval1 interval (closure open)))
(interval_cc . (interval1 interval (closure close)))
(interval_oc . (interval1 interval (closure open!-closed)))
(interval_co . (interval1 interval (closure closed!-open))));

% The following table specifies when it is
% necessary to call a function to deal in a
% precise way with the translation of the
% symbol.

special_cases2!*:=
'((matrix . (matrixir))
(limit . (limitir))
(vector_selector . (selectir))
(matrix_selector . (selectir))
(complex_cartesian . (numir))
(complex_polar . (numir))
(rational . (numir))
(defint . (integralir))
(int . (integralir))
(diff . (integralir))
(partialdiff . (partialdiffir))
(sum . (sum_prodir))
(product . (sum_prodir))
(one . (unaryir alg1 1))
(zero . (unaryir alg1 0))
(i . (unaryir nums1 !&imaginaryi!;))
(e . (unaryir nums1 !&exponentiale!;))
(pi . (unaryir nums1 !&pi!;))
(nan . (unaryir nums1 !&notanumber!;))
(gamma . (unaryir nums1 !&gamma!;))
(infinity . (unaryir nums1 !&infin!;))
(false . (unaryir logic1 !&false!;))
(true . (unaryir logic1 !&true!;)));


% This table contains the OpenMath elements which map simply to MathML.
% These symbols have direct mapping into MathML.

mmleq!*:= '(divide based_integer
equivalent approx determinant transpose inverse in subset prsubset
notsubset notprsubset set setdiff union notin intersect implies not xor
vectorproduct vector or forall and mean mode variance sdev moment median
sin sinh arcsin arcsinh sec sech arcsec arcsech cos arccos cosh arccosh
csc csch arccsc arccsch tan tanh arctan arctanh cot coth arccot arccoth
ln exp abs plus times power factorial minus rem conjugate root log gcd
quotient scalarproduct outerproduct eq neq leq geq lt gt quotient
interval min max imaginary real forall exists lambda list arg type
laplacian divergence curl grad size integer);

end;
