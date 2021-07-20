<?php
$header_title = 'Switch Summary';
include './include/begin-head.php';
include './include/begin-body.php';
?>

<p>
    These are switches available within REDUCE via the commands
    <code>ON</code> and <code>OFF</code>, not switches in the sense of
    command-line start-up options.  The switches are sorted
    alphabetically by name.  A <a href="#undocumented">summary
    of some undocumented switches</a> follows the summary of
    documented switches.
</p>
<h2>Documented switch summary</h2>
<p>
    This is a summary of the switches documented in the
    <strong>REDUCE User&apos;s Manual</strong> <small>[
        <a href="/manual/manual.html">HTML</a>
        | <a href="manual/manual.pdf">PDF</a> ]</small>; more
        information and context can be found by searching the
    <a href="/manual/manual.pdf">PDF version of the manual</a>.
</p>

<?php
$switchesA = array(

    array('ADJPREC', 'OFF', 'Input', 'When on, REDUCE increases PRECISION to keep the full accuracy of all numbers input.'),
    array('ALGINT', 'OFF', 'INT', 'When on, INT uses the ALGINT package.'),
    array('ALLBRANCH', 'ON', 'SOLVE', 'When off, SOLVE only selects the principal branches of functions.'),
    array('ALLFAC', 'ON', 'Output', 'When on, REDUCE searches a whole expression, or any sub-expression enclosed in parentheses, for simple multiplicative factors and displays them outside the parentheses.'),
    array('ALLOWDFINT', 'OFF', 'DF', 'When on, DF applies “differentiation under the integral sign”, i.e. <code>DF(INT(Y, X), V)</code> &rarr; <code>INT(DF(Y, V), X)</code> <em>if this results in a simplification</em>.'),
    array('ANTICOM', 'OFF', '*', 'When on, REDUCE uses only anti-commutators to commute non-commuting variables.'),
    array('ARBVARS', 'ON', 'SOLVE', 'When off, SOLVE does not introduce new indeterminate kernels (i.e. <code>ARBCOMPLEX(<em>j</em>)</code>) into the solution of an under-determined multivariate system.'),
    array('ASSERT', 'OFF', 'ASSERT', 'When on, REDUCE checks assertions at translation time.'),
    array('ASSERTBREAK', 'OFF', 'ASSERT', 'When on, not only are warnings issued for assertion violations but the computation is interrupted with a corresponding error.'),
    array('ASSERTSTATISTICS', 'ON', 'ASSERT', 'When on, enables the statistical counting of procedure calls and assertion violations.'),
    array('BALANCED_MOD', 'OFF', 'Arithmetic', 'When on with ON MODULAR, REDUCE uses the symmetric modular representation in the interval [-floor((<em>p</em>-1)/2), ceiling((<em>p</em>-1)/2)], where <em>p</em> is the current modulus.'),
    array('BEZOUT', 'OFF', 'RESULTANT', 'When on, RESULTANT uses the Bezout Matrix.'),
    array('BFSPACE', 'ON', 'Output', 'When on, REDUCE outputs numbers that are stored internally as bigfloats with a space between every five digits to improve readability.'),
    array('CHECKORD', 'ON', 'CDE', 'When on, the function <code>check_letop</code> checks an expression for the presence of <code>letop</code>.'),
    array('COMBINEEXPT', 'OFF', 'Algebra', 'When on, REDUCE combines exponentiated terms such as <code>x^(1/3)*x^(1/6)</code> (which are always output as if combined).'),
    array('COMBINELOGS', 'OFF', 'Algebra', 'When on, REDUCE combines a sum of logarithms into a logarithm of a product (but see also the PRECISE switch).'),
    array('COMMUTEDF', 'OFF', 'DF', 'When on, DF commutes the order of differentiation in <code>df(u,x,...,u,y,...)</code> &ndash; assuming <code>u</code> depends on <code>x,...,y,...</code> in some way &ndash; and hence simplifies it to 0.'),
    array('COMP', 'OFF', 'Input', 'When on, REDUCE compiles procedures when they are input and replaces their definitions with compiled versions.'),
    array('COMPLEX', 'OFF', 'Arithmetic', 'When on, REDUCE uses complex arithmetic; it rationalizes denominators of complex rational numbers, and computes polynomial GCDs and factorizations over the complex rational numbers.'),
    array('CONTRACT', 'OFF', 'PHYSOP', 'When on, REDUCE contracts over dummy indices, reinserting the DOT operator and reassembling the expanded powers.'),
    array('CRAMER', 'OFF', 'SOLVE', 'When on, SOLVE uses Cramer’s method to solve linear equations instead of the multi-step elimination method due to Bareiss.'),
    array('CREF', 'OFF', 'Input', 'When on, REDUCE runs the Standard Lisp Cross Reference Program on the input (but does not otherwise process it).'),
    array('DEFN', 'OFF', 'Input', 'When on, REDUCE outputs the Standard Lisp equivalent of the input (but does not otherwise process it).'),
    array('DEMO', 'OFF', 'Input', 'When on, REDUCE pauses after each command input from a file (with the exception of comments) until a <em>Return</em> is typed on the terminal.'),
    array('DFINT', 'OFF', 'DF', 'When on with ON ALLOWDFINT, DF applies “differentiation under the integral sign”, i.e. <code>DF(INT(Y, X), V)</code> &rarr; <code>INT(DF(Y, V), X)</code> <em>whether or not this results in a simplification</em>.'),
    array('DISPJACOBIAN', 'OFF', 'CHANGEVAR', 'When on, CHANGEVAR displays the entries of the inverse Jacobian.'),
    array('DISTRIBUTE', 'OFF', 'ASSIST', 'When on, ASSIST puts polynomials in distributed form.'),
    array('DIV', 'OFF', 'Output', 'When on, REDUCE searches the denominator of an expression for simple factors that it divides into the numerator, so that rational fractions and negative powers appear in the output.'),
    array('ECHO', 'ON', 'Input', 'Echoing of all or part of an input file can be prevented, even if a semicolon was used, by placing an OFF ECHO command in the input file.'),
    array('ERRCONT', 'OFF', 'Input', 'When on, REDUCE will continue evaluating input from a file after an error occurs; otherwise, it stops.'),
    array('EVALLHSEQP', 'OFF', 'Equations', 'When on, REDUCE evaluates the LHS of equations (as well as the RHS).'),
    array('EXP', 'ON', 'Algebra', 'When on, REDUCE expands powers and products of expressions.'),
    array('EXPANDDF', 'OFF', 'DF', 'When on, REDUCE uses the chain rule to expand symbolic derivatives of indirectly dependent variables (provided the result is unambiguous).'),
    array('EXPANDLOGS', 'OFF', 'Algebra', 'When on, REDUCE expands a logarithm of a product into a sum of logarithms (but see also the PRECISE switch).'),
    array('EZGCD', 'OFF', 'Algebra', 'When on, REDUCE computes GCDs using an alternative algorithm, called the EZGCD Algorithm, which uses modular arithmetic. ON is recommended!'),
    array('FACTOR', 'OFF', 'Algebra', 'When on, REDUCE represents expressions in factored form.'),
    array('FAILHARD', 'OFF', 'INT', 'When on, INT will terminate with an error if an integral cannot be evaluated in closed terms, rather than returning unevaluated.'),
    array('FASTSIMPLEX', 'ON', 'LINALG', 'When on, SIMPLEX uses the bounds argument; otherwise, the algorithm assumes that all the variables have non-negative values.'),
    array('FAST_LA', 'OFF', 'LINALG, SPARSE', 'When on, LINALG and SPARSE use faster but less safe versions of some functions with less error checking.'),
    array('FORT', 'OFF', 'Output', 'When on, REDUCE outputs expressions using FORTRAN syntax.'),
    array('FORTUPPER', 'OFF', 'Output', 'When on, REDUCE outputs FORTRAN in upper case; otherwise, it is in lower case.'),
    array('FULLROOTS', 'OFF', 'SOLVE', 'When on, SOLVE outputs roots of cubics and quartics in closed form (which can often be very messy).'),
    array('GCD', 'OFF', 'Algebra', 'When on, REDUCE cancels common algebraic factors in the numerators and denominators of expressions.'),
    array('GLTBASIS', 'OFF', 'GROEBNER', 'When on, GROEBNER collects the leading terms of the result basis, which is available as the value of the global variable <code>gltb</code>.'),
    array('GROEBFULLREDUCTION', 'ON', 'GROEBNER', 'When off, GROEBNER limits its reduction steps to pure head-term reduction; otherwise, subsequent terms are also reduced.'),
    array('GROEBOPT', 'OFF', 'GROEBNER', 'When on, GROEBNER selects the variable ordering to optimize execution speed; the optimized variable list is available in <code>gvarslast</code>.'),
    array('GROEBPROT', 'OFF', 'GROEBNER', 'When on, GROEBNER, GREDUCE and PREDUCE produce as a side effect a trace of their work as a REDUCE list of equations in the shared variable <code>groebprotfile</code>.'),
    array('GROEBSTAT', 'OFF', 'GROEBNER', 'When on, GROEBNER outputs a summary of the computation including the computing time, the number of intermediate <em>h</em>–polynomials and the counters for the hits of the criteria.'),
    array('HEUGCD', 'OFF', 'Algebra', 'When on with ON GCD, REDUCE uses a heuristic GCD algorithm, available experimentally. EZGCD takes precedence over HEUGCD.'),
    array('HORNER', 'OFF', 'Output', 'When on, REDUCE outputs polynomials according to Horner’s rule.'),
    array('IFACTOR', 'OFF', 'FACTORIZE', 'When on, FACTORIZE finds the prime factors of the overall integer factor (content) of a polynomial, using a probabilistic algorithm.'),
    array('IMAGINARY', 'OFF', 'LINALG', 'When on, RANDOM_MATRIX generates matrix entries that are complex numbers.'),
    array('INT', '&rarr;', 'Input', 'When on, REDUCE treats input as interactive; the default is ON for terminal input and OFF for file input.'),
    array('INTSTR', 'OFF', 'Output', 'When on, REDUCE outputs operator arguments in the same form they would have as top-level expressions; otherwise, they are normally fully expanded.'),
    array('LCM', 'ON', 'Algebra', 'When on, REDUCE uses the true least common multiple of the denominators as the common denominator of a rational expression at each computational step.'),
    array('LHYP', 'OFF', 'LAPLACE', 'When on, INVLAP converts exponentials into the hyperbolic functions sinh and cosh.'),
    array('LIST', 'OFF', 'Output', 'When on, REDUCE outputs each term in any sum on a separate line. [This may not be reliable for typeset-style output.]'),
    array('LISTARGS', 'OFF', 'Algebra', 'When on, REDUCE does not distribute unary operators over list arguments.'),
    array('LMON', 'OFF', 'LAPLACE', 'When on, LAPLACE converts trigonometric and hyperbolic functions into exponentials.'),
    array('LOOKING_GOOD', 'OFF', 'NORMFORM', 'When on and using xr, the X interface for REDUCE, NORMFORM improves the appearance of output by converting all lambda to &xi; and improves the indexing, e.g., lambda12 &rarr; &xi;<sub>12</sub>.'),
    array('LOWER_MATRIX', 'OFF', 'LINALG', 'When on, RANDOM_MATRIX creates lower-triangular matrices.'),
    array('LTRIG', 'OFF', 'LAPLACE', 'When on, INVLAP converts exponentials into the trigonometric functions sin and cos.'),
    array('MCD', 'ON', 'Algebra', 'When on, REDUCE produces an expression over a common denominator when rational functions are added. (ON MCD is necessary for reliable simplification!)'),
    array('MODULAR', 'OFF', 'Arithmetic', 'When on, REDUCE uses modular arithmetic with modulus <em>p</em> (which must be set using the SETMOD command).'),
    array('MSG', 'ON', 'Output', 'When off, REDUCE suppresses warning messages.'),
    array('MULTIPLICITIES', 'OFF', 'SOLVE', 'When on, SOLVE outputs multiple solutions explicitly as repeated solutions.'),
    array('MULTIROOT', 'ON', 'ROOTS', 'When on, ROOTS indicates the multiplicity of a root by outputting it repeatedly, according to its multiplicity.'),
    array('NAT', 'ON', 'Output', 'When on, REDUCE outputs expressions in linear input-compatible form with each expression terminated by a dollar sign.'),
    array('NERO', 'OFF', 'Output', 'When on, REDUCE does not output the results of zero assignments (i.e. assignments of the form <code>&lt;expression&gt; := 0</code>).'),
    array('NOCOMMUTEDF', 'OFF', 'DF', 'When on, DF does not commute the order of differentiation.'),
    array('NOCONVERT', 'OFF', 'Arithmetic', 'When on with ON ROUNDED, REDUCE does not convert the floating-point number 1.0 to the integer 1.'),
    array('NOINTSUBST ', 'OFF', 'INT', 'When on, INT does not use heuristic attempts to solve an integral by substitution.'),
    array('NOLNR', 'OFF', 'INT', 'When on, INT does not use the linear properties of integration in cases where the integral cannot be found in closed form.'),
    array('NOSPLIT', 'ON', 'Output', 'When on, REDUCE does not attempt to break output expressions across lines at natural points.'),
    array('NOSUM', 'OFF', 'EXCALC', 'When on, EXCALC does not perform any summation.'),
    array('NOT_NEGATIVE', 'OFF', 'LINALG', 'When on, RANDOM_MATRIX generates matrix entries that are strictly positive numbers.'),
    array('ONESPACE', 'ON', 'CANTENS', 'When on, CANTENS works in a single space environment, which is Euclidean and has a symbolic dimension equal to <code>dim</code>.'),
    array('ONLY_INTEGER', 'OFF', 'LINALG', 'When on, RANDOM_MATRIX generates matrix entries that are integers (complex integers with ON IMAGINARY).'),
    array('OUTPUT', 'ON', 'Output', 'When off, REDUCE suppresses the output entirely from any top-level evaluation.'),
    array('PERIOD', 'ON', 'Output', 'When on with ON FORT, REDUCE automatically inserts a decimal point after each isolated integer coefficient (so that, for example, <code>4</code> becomes <code>4.</code>).'),
    array('PGWD', 'OFF', 'Compiling', 'When on, the REDUCE compiler displays the actual code generated.'),
    array('PLAP', 'OFF', 'Compiling', 'When on, the REDUCE compiler displays the portable intermediate code generated.'),
    array('PLOTKEEP', 'OFF', 'PLOT', 'When on, REDUCE does not erase GNUPLOT data files.'),
    array('PRECISE', 'ON', 'Algebra', 'When on, REDUCE preserves the positive property of the square root and higher even roots by using the absolute value of any non-numerical factors taken out of surds.'),
    array('PRECISE_COMPLEX', 'OFF', 'Algebra', 'When on, REDUCE does not simplify &radic;<span style="border-top:solid thin"><em>x</em><sup>2</sup></span> to |<em>x</em>|.'),
    array('PRET', 'OFF', 'Output', 'When on, REDUCE &quot;prettyprints&quot; its input in a standard format.'),
    array('PRI', 'ON', 'Output', 'When on, REDUCE respects the switches that control output; otherwise, it uses a fixed format, which basically reflects the internal form of expressions.'),
    array('PSPRINTORDER', 'ON', 'TPS', 'When on, TPS outputs the remainder of the power series in big-O notation; otherwise, three dots are used.'),
    array('PWRDS', 'ON', 'Compiling', 'When on, the REDUCE compiler displays statistics for functions as they are compiled.'),
    array('QGOSPER_DOWN', 'ON', 'QSUM', 'When on, QGOSPER returns a downward anti-difference; otherwise, it returns an upward anti-difference.'),
    array('QGOSPER_SPECIALSOL', 'ON', 'QSUM', 'When on, QGOSPER returns just one special solution; otherwise, it returns all solutions.'),
    array('QSUMRECURSION_CERTIFICATE', 'OFF', 'QSUM', 'When on, QSUMRECURSION provides all necessary information for proving the recurrence equation.'),
    array('QSUMRECURSION_DOWN', 'ON', 'QSUM', 'When on, QSUMRECURSION returns a downward recurrence equation; otherwise it returns an upward recurrence equation.'),
    array('QSUMRECURSION_EXP', 'OFF', 'QSUM', 'When on, QSUMRECURSION factors the coefficients of the recurrence equation.'),
    array('QSUM_NULLSPACE', 'OFF', 'QSUM', 'When on, QSUM uses a modified nullspace-algorithm for solving the set of linear equations, which is generally slower.'),
    array('QSUM_TRACE', 'OFF', 'QSUM', '&nbsp;When on, QSUM outputs some intermediate results.'),
    array('RAT', 'OFF', 'Output', 'When on with a FACTOR declaration in effect, REDUCE output has the overall denominator of an expression divided into each factored sub-expression.'),
    array('RATARG', 'OFF', 'COEFF(N)', 'When on, COEFF and COEFFN do not check denominators for dependence and always treat them as part of the coefficients.'),
    array('RATIONAL', 'OFF', 'Algebra', 'When on, REDUCE treats a rational number as a polynomial coefficient rather than as the numerator and denominator of a rational expression.'),
    array('RATIONALIZE', 'OFF', 'Algebra', 'When on, REDUCE uses complex conjugation to remove complex numbers from denominators (much as with ON COMPLEX).'),
    array('RATPRI', 'ON', 'Output', 'When on, REDUCE attempts to output rational expressions in two-dimensional form.'),
    array('RATROOT', 'OFF', 'ROOTS', 'When on, ROOTS outputs all root equations in rational form.'),
    array('REVPRI', 'OFF', 'Output', 'When on, REDUCE outputs polynomial terms ordered from lowest to highest power (as is normal for a power series).'),
    array('RLISP88', 'OFF', 'Input', 'When on, REDUCE is in symbolic mode with RLISP ’88 syntax and extensions.'),
    array('ROOTMSG', 'OFF', 'ROOTS', 'When on with ON TRROOT, ROOTS outputs additional messages to aid in following the progress of Laguerre and Newton complex iteration.'),
    array('ROUNDALL', 'ON', 'Arithmetic', 'When on with ON ROUNDED, REDUCE converts rational numbers to rounded representation; otherwise, they are kept in rational form until used in an operation that returns a real number.'),
    array('ROUNDBF', 'OFF', 'Arithmetic', 'When on, REDUCE uses bigfloat representation for floating-point numbers at all precisions; otherwise, it uses bigfloat only when necessary.'),
    array('ROUNDED', 'OFF', 'Arithmetic', 'When on, REDUCE uses numerical approximation to compute non-integer numerical values (to the accuracy is specified using the operator PRECISION).'),
    array('RTRACE', 'ON', 'RTRACE', 'When on, traced values are output in algebraic style whenever possible; otherwise, they are output in conventional Lisp style.'),
    array('SAVESTRUCTR', 'OFF', 'Algebra', 'When on, STRUCTR returns a list representing the expression structure; otherwise, it only displays the structure.'),
    array('SIMPNONCOMDF', 'OFF', 'DF', 'When on with OFF COMMUTEDF, <code>DF(U,X,U)</code> simplifies to <code>DF(U,X,2)/DF(U,X)</code> etc., provided <code>U</code> depends only on the one variable <code>X</code>.'),
    array('SOLVESINGULAR', 'ON', 'SOLVE', 'When on, SOLVE introduces arbitrary constants as appropriate to solve consistent singular equations.'),
    array('SYMMETRIC', 'OFF', 'LINALG', 'When on, RANDOM_MATRIX generates symmetric matrices.'),
    array('TAYLORAUTOCOMBINE', 'ON', 'TAYLOR', 'When on, Taylor expressions automatically combine during the simplification process (equivalent to applying TAYLORCOMBINE to every expression that contains Taylor kernels).'),
    array('TAYLORAUTOEXPAND', 'OFF', 'TAYLOR', 'When on, Taylor expressions are “contagious” in the sense that TAYLORCOMBINE tries to Taylor expand all non-Taylor sub-expressions and to combine the result with the rest.'),
    array('TAYLORKEEPORIGINAL', 'OFF', 'TAYLOR', 'When on, TAYLOR keeps the original expression, i.e. the expression that was Taylor expanded. All operations performed on the Taylor kernels are also applied to this expression which can be recovered using the operator TAYLORORIGINAL.'),
    array('TAYLORPRINTORDER', 'ON', 'TAYLOR', 'When on, TAYLOR outputs remainders using big-O notation; otherwise, three dots are used.'),
    array('TIME', 'OFF', 'Output', 'When on, REDUCE outputs a message after each command giving the elapsed CPU time since the last command, since TIME was last turned off, or since the session began.'),
    array('TRA', 'OFF', 'ALGINT', 'When on, ALGINT outputs tracing information about the specific functioning of the algebraic integrator.'),
    array('TRCOMPACT', 'OFF', 'COMPACT', 'When on, COMPACT outputs tracing information.'),
    array('TRDEFINT', 'OFF', 'DEFINT', 'When on, DEFINT outputs information about intermediate steps of the calculation.'),
    array('TRFAC', 'OFF', 'Algebra', 'When on, all calls to the factorizer will generate informative messages reporting on such things as the reduction of multivariate to univariate cases, the choice of a prime and the reconstruction of full factors from their images.'),
    array('TRGROEB', 'OFF', 'GROEBNER', 'When on, GROEBNER tracing includes GROEBSTAT and intermediate <em>h</em>-polynomials.'),
    array('TRGROEB1', 'OFF', 'GROEBNER', 'When on, GROEBNER tracing includes the internal pairlist when modified.'),
    array('TRGROEBR', 'OFF', 'GROEBNER', 'When on, GROEBNER tracing includes all intermediate partial bases when detected.'),
    array('TRGROEBS', 'OFF', 'GROEBNER', 'When on, GROEBNER tracing includes TRGROEB and the printing of intermediate <em>s</em>–polynomials.'),
    array('TRIGFORM', 'ON', 'SOLVE', 'When on, SOLVE uses trigonometrical forms for the solutions of cubics and quartics where appropriate.'),
    array('TRINT', 'OFF', 'INT', 'When on, INT traces the operation of the algorithm. It produces a great deal of output in a somewhat illegible form, and is not of much interest to the general user.'),
    array('TRINTSUBST', 'OFF', 'INT', 'When on, INT traces heuristic attempts to evaluate an integral by substitution.'),
    array('TRNUMERIC', 'OFF', 'NUMERIC', 'When on, NUMERIC outputs tracing information.'),
    array('TRPLOT', 'OFF', 'PLOT', 'When on, all GNUPLOT commands are written additionally to the actual REDUCE output.'),
    array('TRROOT', 'OFF', 'ROOTS', 'When on, ROOTS outputs tracing messages during the course of root determination, to show the progress of solution.'),
    array('TRSOLVE', 'OFF', 'RSOLVE', 'When on, RSOLVE outputs tracing information.'),
    array('TRSUM', 'OFF', 'SUM', 'When on, SUM outputs tracing information.'),
    array('TRWU', 'OFF', 'WU', 'When on, WU outputs tracing information.'),
    array('TR_LIE', 'OFF', 'LIE', 'When on, LIENDIMCOM1 outputs tracing information.'),
    array('UPPER_MATRIX', 'OFF', 'LINALG', 'When on, RANDOM_MATRIX generates upper-triangular matrices.'),
    array('VAROPT', 'ON', 'SOLVE', 'When on, SOLVE rearranges the variable sequence to reduce the (expected) computing time; otherwise, the supplied variable sequence is used or the system kernel ordering is used if the variable list is omitted.'),
    array('VERBOSELOAD', 'OFF', 'TAYLOR', 'When on, REDUCE prints some information when the Taylor package is loaded.'),
    array('ZB_FACTOR', 'ON', 'ZEILBERG', 'When on, ZEILBERG factorizes its output usually producing nicer results.'),
    array('ZB_PROOF', 'OFF', 'ZEILBERG', 'When on, ZEILBERG stores several intermediate results in global variables.'),
    array('ZB_TRACE', 'OFF', 'ZEILBERG', 'When on, ZEILBERG outputs tracing information.')

); // array('', '', '', ''),
?>

<table class="table">
  <thead>
    <tr>
      <th scope="col">Switch</th>
      <th scope="col">Default</th>
      <th scope="col">Controls</th>
      <th scope="col">Effect</th>
    </tr>
  </thead>
  <tbody>
    <?php foreach ($switchesA as $switchrow): ?>
    <tr>
      <th scope="row"><?=$switchrow[0]?></th>
      <td><?=$switchrow[1]?></td>
      <td><?=$switchrow[2]?></td>
      <td><?=$switchrow[3]?></td>
    </tr>
    <?php endforeach; ?>
  </tbody>
</table>

<h2 id="undocumented">Undocumented switch summary</h2>
<p>
    This is an attempt to summarize some of the switches that are not
    documented in the <strong>REDUCE User's Manual</strong>, either
    because they are not intended for direct user access or because
    they are specific to the underlying Lisp system (PSL or CSL).
    Beware that details are more likely to be wrong than for the
    documented switches!
</p>

<?php
$switchesB = array(

	array('BACKTRACE', 'OFF', 'Errors', 'When on, REDUCE outputs an unwind backtrace when errors occur in the top-level read-eval-print loop outside the scope of any user-specified error handler.'),
	array('BREAK', 'OFF', 'PSL', 'When on, PSL REDUCE suppresses all break loops and just displays an error message when it detects an error.'),
	array('FANCY', '&rarr;', 'Output', 'When on, REDUCE uses typeset-style output; the default is ON for CSL REDUCE in GUI mode and OFF otherwise (but probably ON when using TeXmacs).'),
	array('GC', 'ON', 'Output', 'When on, REDUCE outputs information about garbage collection.'),
	array('PCMAC', 'OFF', 'PSL', 'When on, the PSL REDUCE compiler displays both the portable intermediate code generated and the assembly language mnemonics.'),
	array('RAISE', 'ON', 'PSL', 'When on, PSL REDUCE converts upper-case alphabetic characters to lower case.'),
	array('USERMODE', 'OFF', 'PSL', 'When on, PSL REDUCE queries an attempt to redefine a system function unless it is flagged LOSE.'),
	array('VERBOSELOAD', 'OFF', 'PSL', 'When on, PSL REDUCE outputs information when a package is loaded.')

); // array('', '', '', ''),
?>

<table class="table">
  <thead>
    <tr>
      <th scope="col">Switch</th>
      <th scope="col">Default</th>
      <th scope="col">Controls</th>
      <th scope="col">Effect</th>
    </tr>
  </thead>
  <tbody>
    <?php foreach ($switchesB as $switchrow): ?>
    <tr>
      <th scope="row"><?=$switchrow[0]?></th>
      <td><?=$switchrow[1]?></td>
      <td><?=$switchrow[2]?></td>
      <td><?=$switchrow[3]?></td>
    </tr>
    <?php endforeach; ?>
  </tbody>
</table>

</div><!-- opened in begin-body.php -->

<?php
include './include/footer.php';
?>

</body>
</html>
