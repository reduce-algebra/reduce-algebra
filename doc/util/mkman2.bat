REM  Create r38.tex

REM execure this script when in doc\util, please

set man=..\manual
set man2=..\manual2

type %man2%\prolog1.tex > r38.tmp
type %man2%\title.tex >> r38.tmp

REM Original manual sections

type %man%\abstract.tex >> r38.tmp
type %man%\acknowl.tex >> r38.tmp
type %man%\intro.tex >> r38.tmp
type %man%\progstr.tex >> r38.tmp
type %man%\exprn.tex >> r38.tmp
type %man%\list.tex >> r38.tmp
type %man%\statemnt.tex >> r38.tmp
type %man%\command.tex >> r38.tmp
type %man%\oper.tex >> r38.tmp
type %man%\solve.tex >> r38.tmp
type %man%\oper2.tex >> r38.tmp
type %man%\structr.tex >> r38.tmp
type %man%\polyrat.tex >> r38.tmp
type %man%\subst.tex >> r38.tmp
type %man%\io.tex >> r38.tmp
type %man%\inter.tex >> r38.tmp
type %man%\matrix.tex >> r38.tmp
type %man%\proc.tex >> r38.tmp
type %man%\rememb.tex >> r38.tmp
type %man2%\user2.tex >> r38.tmp
REM type %man%\user.tex >> r38.tmp
type %man%\symbolic.tex >> r38.tmp
type %man%\rlisp88.tex >> r38.tmp
type %man%\rlispref.tex >> r38.tmp
type %man%\hephys.tex >> r38.tmp
type %man%\util.tex >> r38.tmp
type %man%\maintain.tex >> r38.tmp

REM Now part 2.

type %man2%\prolog2.tex >> r38.tmp
type %man2%\algint.tex >> r38.tmp
type %man2%\applysym.tex >> r38.tmp
type %man2%\arnum.tex >> r38.tmp
type %man2%\assist.tex >> r38.tmp
type %man2%\atensor.tex >> r38.tmp
type %man2%\avector.tex >> r38.tmp
type %man2%\boolean.tex >> r38.tmp
type %man2%\cali.tex >> r38.tmp
type %man2%\camal.tex >> r38.tmp
type %man2%\cgb.tex >> r38.tmp
type %man2%\changevr.tex >> r38.tmp
type %man2%\compact.tex >> r38.tmp
rem type %man2%\contfr.tex >> r38.tmp   superceded by rataprx.
type %man2%\crack.tex >> r38.tmp
type %man2%\cvit.tex >> r38.tmp
type %man2%\defint.tex >> r38.tmp
type %man2%\desir.tex >> r38.tmp
type %man2%\dfpart.tex >> r38.tmp
type %man2%\dummy.tex >> r38.tmp
type %man2%\eds.tex >> r38.tmp
type %man2%\excalc.tex >> r38.tmp
type %man2%\fide.tex >> r38.tmp
type %man2%\fps.tex >> r38.tmp
REM type %man2%\fps.tex >> r38.tmp
REM type %man2%\fide.tex >> r38.tmp
type %man2%\gentran.tex >> r38.tmp
type %man2%\geometry.tex >> r38.tmp
type %man2%\gnuplot.tex >> r38.tmp
type %man2%\groebner.tex >> r38.tmp
type %man2%\ideals.tex >> r38.tmp
type %man2%\ineq.tex >> r38.tmp
type %man2%\invbase.tex >> r38.tmp
type %man2%\laplace.tex >> r38.tmp
type %man2%\lie.tex >> r38.tmp
type %man2%\limits.tex >> r38.tmp
type %man2%\linalg.tex >> r38.tmp
type %man2%\mathml.tex >> r38.tmp
type %man2%\modsr.tex >> r38.tmp
type %man2%\mrvlimit.tex >> r38.tmp
type %man2%\ncpoly.tex >> r38.tmp
type %man2%\normform.tex >> r38.tmp
type %man2%\numeric.tex >> r38.tmp
type %man2%\odesolve.tex >> r38.tmp
REM type %man2%\odesolv1.tex >> r38.tmp
type %man2%\orthovec.tex >> r38.tmp
type %man2%\physop.tex >> r38.tmp
type %man2%\pm.tex >> r38.tmp
type %man2%\qsum.tex >> r38.tmp
type %man2%\randpoly.tex >> r38.tmp
type %man2%\rataprx.tex >> r38.tmp
type %man2%\reacteqn.tex >> r38.tmp
type %man2%\redlog.tex >> r38.tmp
type %man2%\reset.tex >> r38.tmp
type %man2%\residue.tex >> r38.tmp
type %man2%\rlfi.tex >> r38.tmp
type %man2%\roots.tex >> r38.tmp
type %man2%\rsolve.tex >> r38.tmp
REM type %man2%\rsolve.tex >> r38.tmp
REM type %man2%\roots.tex >> r38.tmp
type %man2%\scope.tex >> r38.tmp
type %man2%\sets.tex >> r38.tmp
type %man2%\sparse.tex >> r38.tmp
type %man2%\spde.tex >> r38.tmp
type %man2%\specfn.tex >> r38.tmp
type %man2%\specfn2.tex >> r38.tmp
type %man2%\sum.tex >> r38.tmp
type %man2%\susy2.tex >> r38.tmp
type %man2%\symmetry.tex >> r38.tmp
type %man2%\taylor.tex >> r38.tmp
type %man2%\tps.tex >> r38.tmp
type %man2%\tri.tex >> r38.tmp
type %man2%\trigsimp.tex >> r38.tmp
type %man2%\wu.tex >> r38.tmp
type %man2%\xcolor.tex >> r38.tmp
type %man2%\xideal.tex >> r38.tmp
REM type %man2%\xcolor.tex >> r38.tmp
REM type %man2%\xideal.tex >> r38.tmp
REM type %man2%\wu.tex >> r38.tmp
type %man2%\zeilberg.tex >> r38.tmp
type %man2%\ztrans.tex >> r38.tmp

type %man2%\sl.tex >> r38.tmp

type %man2%\tail1.tex >> r38.tmp

type %man%\appenda.tex >> r38.tmp

type %man2%\tail2.tex >> r38.tmp

perl conv.pl

del r38.tmp
